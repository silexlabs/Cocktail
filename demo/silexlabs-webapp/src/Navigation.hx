/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

import js.Dom;

import components.lists.ListBaseModels;

/**
 * Handles all applications pages
 * 
 * @author	Raphael Harmel
 * @date	2001-11-30
 */

class Navigation 
{
	// pagesContainer is the container for all pages
	public var pagesContainer:HtmlDom;

	// the current visible page
	public var currentPage:HtmlDom;

	// the previous page
	private var _previousPages:Array<HtmlDom>;
	
	/**
	 * Constructor
	 */
	public function new(container:HtmlDom, startPage:HtmlDom)
	{
		// initializes pagesContainer & current page
		pagesContainer = container;
		currentPage = startPage;

		// initializes _previousPage
		_previousPages = new Array<HtmlDom>();
		_previousPages.push(startPage);
		
		// adds the home page to pagesContainer
		pagesContainer.appendChild(startPage);
	}
	
	/**
	 * Callback called on mouse release of the back header button
	 * 
	 * @param	mouseEvent
	 */
	public function goToPreviousPage():Void
	{
		// show previous page in the history
		showPage(getPreviousPage());
	}

	/**
	 * Gets the previous page, back button callback
	 * 
	 * @return
	 */
	private function getPreviousPage():HtmlDom
	{
		// remove current page from history
		_previousPages.pop();
		
		// get previous page from history
		var previousPage:HtmlDom = _previousPages[_previousPages.length-1];
		
		// in case history is emtpy, go to home page
		if (previousPage == null)
			return _previousPages[0];
		
		// else return previous page
		return previousPage;
	}
	
	/**
	 * Adds a page to history
	 * 
	 */
	private function addToHistory(page:HtmlDom):Void
	{
		// if page to show is _homepage, reset history
		if (page == _previousPages[0])
			_previousPages = [page];
		// if not add the preceding page container to _previousPage 
		else
			_previousPages.push(page);
	}
	
	/**
	 * Hides the current page and shows the wanted page
	 * 
	 * @param	page	the wanted page
	 */
	private function showPage(page:HtmlDom):Void
	{
		// removes the current page from the page container
		pagesContainer.removeChild(currentPage);
		// adds the new page to the page container
		pagesContainer.appendChild(page);
		currentPage = page;
	}
	
	/**
	 * Called when a new cell is selected in a list
	 * Select the action to be done
	 * 
	 * @param	cell
	 */
	public function onChangeListCallback(cell:CellModel)
	{
		//trace("Navigation.onChangeListCallback" + cell.action);
		if (cell.action == "goToPage")
		{
			//trace("Navigation.onChangeListCallback goToPage");
			var page:HtmlDom = cell.actionTarget;
		
			// history handling
			addToHistory(page);
			
			// show needed pages
			showPage(page);
		}
		else if (cell.action == "goToUrl")
		{
			goToUrl(cell.actionTarget);
		}
		else if (cell.action == "openUrl")
		{
			openUrl(cell.actionTarget);
		}
	}
	
	/**
	 * Go the wanted URL - not supported by Cocktail yet so conditionnal compilation is used
	 * 
	 * @param	url		the url to go to
	 */
	private function goToUrl(url:String)
	{
		#if js
		js.Lib.window.open(url);
		
		#elseif flash9
		var request:flash.net.URLRequest = new flash.net.URLRequest(url);
		flash.Lib.getURL(request);

		#end
	}
	
	/**
	 * Opens the wanted URL - not supported by Cocktail yet so conditionnal compilation is used
	 * 
	 * @param	url		the url to open
	 */
	private function openUrl(url:String)
	{
		#if js
		js.Lib.window.open(url,'_self');
		
		#elseif flash9
		var request:flash.net.URLRequest = new flash.net.URLRequest(url);
		flash.Lib.getURL(request,"_self");

		#end
	}
}
