package org.intermedia.view;

import js.Lib;
import js.Dom;

/**
 * Base class for views
 * 
 * @author Raphael Harmel
 */

class ViewBase
{
	public var node:HtmlDom;
	
	//get/set the data of the view. Dynamically cast by each inheriting view
	private var _data:Dynamic;
	public var data(getData, setData):Dynamic;
	
	// style
	//private var _style:Dynamic;
	
	//activate / deactivate the display of the loader.
	public var displayLoading(null, setDisplayLoading):Bool;
	
	private var _loadingView:LoadingView;

	public function new()
	{
		// initialise node
		node = Lib.document.createElement("div");
		
		// set the display attributes of the loading wheel to true
		displayLoading = false;
		
		// build view
		buildView();
	}
	
	/**
	 * data getter
	 * @return
	 */
	private function getData():Dynamic
	{
		return _data;
	}
	
	/**
	 * data setter
	 * @param	v
	 * @return
	 */
	private function setData(v:Dynamic):Dynamic
	{
		_data = v;
		// update view
		updateView();
		return _data;
	}
	
	/**
	 * Display Loading setter
	 * @param	v
	 * @return
	 */
	private function setDisplayLoading(v:Bool):Bool
	{
		// if display loading is set to true, display it
		if (v)
		{
			// instanciate the loading view if not already done (done here instead of contructor to limit memory usage)
			if (_loadingView == null)
				_loadingView = new LoadingView();
				
			// if the loading view is not attached to this, display it
			if (_loadingView.node.parentNode == null)
				node.appendChild(_loadingView.node);
		}
		// else, hide it
		else
		{
			// if _loadingView view exists
			if (_loadingView != null)
				// if the loading view is attached to this, un-attach it
				if (_loadingView.node.parentNode != null)
					node.removeChild(_loadingView.node);
		}
		return v;
	}
	
	/**
	 * build view
	 * to be overriden in inheriting classes
	 */
	private function buildView():Void
	{
		
	}
	
	/**
	 * update view
	 * to be overriden in inheriting classes
	 */
	private function updateView():Void
	{
		
	}
	
}