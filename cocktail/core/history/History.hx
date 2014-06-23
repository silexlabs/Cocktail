/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.history;

import cocktail.core.history.HistoryData;
import cocktail.core.html.HTMLConstants;
import cocktail.event.PopStateEvent;
import cocktail.event.EventConstants;
import cocktail.core.html.HTMLDocument;
/**
 * Implementation of the history API as stated here http://dev.w3.org/html5/spec/single-page.html#history
 * Notes
 * - the intial state is the browser state, it is pushed at start, currentIdx is then 0, not sure if this is right because specs do not say if the browser initial state should be pushed or not
 * - stateDataArray should always have more than 0 elements and currentIdx should always be positive
 * Todo:
 * - methods to resolve urls? (do like the css and xml parsers of COcktail, not with regexp)
 * - update window.location
 */
class History
{	    	
	/**
	 * number of entries in the history
	 */
	public var length(get_length, null):Int;
	/**
	 * current state object
	 * null if initial document state
	 * this is the information that was provided to pushState() or replaceState()
	 */
	public var state(default, null):Null<Dynamic>;
	/**
	 * array of states
	 */
	private var stateDataArray:Array<StateData>;
	/**
	 * store the current index in stateDataArray
	 */
	private var currentIdx:Int;
	/**
	 * store the document owning this instance
	 */
	private var document:HTMLDocument;
	/**
	 * class constructor
	 */
	public function new(document:HTMLDocument) 
	{
		// intial state is the browser state
		stateDataArray = new Array();
		currentIdx = 0;
		
		this.document = document;

		// add the initial browser state to the history
		// todo: use the location to resolve the url
		stateDataArray.push( {
			state:null,
			title:"",
			url:null
		});
	}
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		stateDataArray = null;
		document = null;
		state = null;
	}
	
	/**
	 * getter for the length property
	 */
	public function get_length():Int 
	{
		return stateDataArray.length;
	}
	/**
	 * Goes back or forward the specified number of steps in the joint session history.
	 * A zero delta will reload the current page. If the delta is out of range, does nothing.
	 */
	public function go(delta:Int) 
	{
		// compute new index
		var newIndex = currentIdx + delta;

		// check boudaries
		if(newIndex < 0 || newIndex >= stateDataArray.length)
			return;

		// update current index and state
		currentIdx = newIndex;
		state = cloneData(stateDataArray[currentIdx].state);

		// fire the popstate event
		onPopState({
			state : state,
			title : stateDataArray[currentIdx].title,
			url : stateDataArray[currentIdx].url
		});
	}
	/**
	 * Goes back one step in the joint session history. If there is no previous page, does nothing.
	 */
	public function back()
	{
		go(-1);
	}
	/**
	 * Goes forward one step in the joint session history. If there is no next page, does nothing.
	 */
	public function forward()
	{
		go(1);
	}
	/**
	 * Pushes the given data onto the session history, with the given title, and, if provided, the given URL.
	 */
	public function pushState(data:Dynamic, title:String, url:Null<String>=null)
	{
		// empty the history after the current position
		while (stateDataArray.length > currentIdx + 1)
		{
			stateDataArray.pop();
		}

		// adds the new entry
		var newStateData = computeStateData(data, title, url);
		stateDataArray.push(newStateData);
		currentIdx++;
		// TODO: Set the document's address to new URL, should not dispatch hashchange event

		// update the state object
		state = cloneData(newStateData.state);
	}
	/**
	 * Updates the current entry in the session history to have the given data, title, and, if provided, URL.
	 */
	public function replaceState(data:Dynamic, title:String, url:Null<String>=null)
	{
		var newStateData = computeStateData(data, title, url);
		stateDataArray[currentIdx] = newStateData;
		// TODO: Set the document's address to new URL?

		// update the state object
		state = cloneData(newStateData.state);
	}
	/**
	 * dispatch the "popstate" event on window and call window.onpopstate
	 * event.state contains a copy of the information that was provided to pushState() or replaceState()
	 */
	public function onPopState(stateData:StateData)
	{
		// clone input data 
		var clonedState = cloneData(stateData.state);

		// create the event
		var event:PopStateEvent = new PopStateEvent();
		event.initPopStateEvent(EventConstants.POP_STATE, true, false, null, 0.0, clonedState);
  		// dispatch event on window
		document.defaultView.dispatchEvent(event);

		// call callback
		if(document.defaultView.onpopstate != null)
			document.defaultView.onpopstate(event);
	}

	/**
	 * clone data 
	 * todo: use this to make it 5x faster http://haxe.org/forum/thread/3395#nabble-td2119917
	 */
	private function cloneData<T>(data:T):T
	{
		return haxe.Unserializer.run(haxe.Serializer.run(data));
	}
	/**
	 * algorithm common to replaceState and onPopState
	 * creates a new StateData structure with specified data
	 * clone data and resolve url like explained here: http://dev.w3.org/html5/spec/single-page.html - "When either of these methods is invoked, the user agent must run the following steps"
	 */
	private function computeStateData(data:Dynamic, title:String, url:Null<String>=null):StateData
	{
		// clone input data 
		var clonedData:Dynamic;
		try
		{
			clonedData = cloneData(data);
		}
		catch(e:Dynamic)
		{
			throw("SecurityError - Error duplicating the data passed to History::replaceState or History::pushState. The error is: " + e);
		}
		// handle input url
		if (url != null)
		{
			// resolve url
			url = resolveUrl(url);
			// todo: handle SecurityError and domain restrictions?
		}
		else
		{
			// default url is the current entry
			url = stateDataArray[currentIdx].url;
		}
		return {
			state:clonedData,
			title:title,
			url:url
		};
	}
	/**
	 * convert into absolute URL
	 * handle the .. in relative urls, take the base tag into account
	 * todo: do it right like described here http://dev.w3.org/html5/spec/single-page.html#fallback-base-url
	 */
	private function resolveUrl(url:String, base:Null<String>=null):String{
		// default value for base is the document 
		// todo: do it right like described here (with case of iframe abd about:blank) http://dev.w3.org/html5/spec/single-page.html#fallback-base-url
		if (base == null)
		{
			// retrieve the base meta tag
			var tags = document.getElementsByTagName("base");
			for (idx in 0...tags.length)
			{
				if (tags[idx].hasAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME))
				{
					base = tags[idx].getAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME);
					break;
				}
			}
			// defaults to the document location
			if (base == null)
			{
				// todo: use location
				//base = document.location.href;
				// throw("location is not yet implemented");
				base = "";
			}
		}
		// replace all "\" by "/" in url
		url = StringTools.replace(url, "\\", "/");

		// add base to url if needed
		var idxBase = url.indexOf("http");
		if (idxBase != 0)
		{
			url = base+url;
		}

		// resolve the ".."
		var urlArray = url.split("/");
		var absoluteUrlArray = new Array();
		for (idx in 0...urlArray.length)
		{
			// check if this is a ".."
			if (urlArray[idx]==".."){
				// removes the last element of the final array
				absoluteUrlArray.pop();
			}
			else{
				// add the path element to the final array
				absoluteUrlArray.push(urlArray[idx]);
			}
		}
		url = absoluteUrlArray.join("/");

		// return the absolute url
		return url;
	}
}
