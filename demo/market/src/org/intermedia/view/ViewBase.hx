package org.intermedia.view;
import cocktail.domElement.ContainerDOMElement;

/**
 * Base class for views
 * 
 * @author Raphael Harmel
 */

//class ViewBase
class ViewBase extends ContainerDOMElement
{

	//get/set the data of the view. Dynamically cast by each inheriting view
	private var _data:Dynamic;
	public var data(getData, setData):Dynamic;
	
	//activate / deactivate the display of the loader.
	public var displayLoading(null, setDisplayLoading):Bool;
	
	private var _loadingView:LoadingView;

	public function new() 
	{
		super();
		
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
			if (_loadingView.parent == null)
				this.addChild(_loadingView);
		}
		// else, hide it
		else
		{
			// if _loadingView view exists
			if (_loadingView != null)
				// if the loading view is attached to this, un-attach it
				if (_loadingView.parent != null)
					this.removeChild(_loadingView);
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