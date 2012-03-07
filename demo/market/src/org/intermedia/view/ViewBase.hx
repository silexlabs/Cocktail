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
	public var displayLoading:Bool;

	public function new() 
	{
		super();
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
		updateView();
		return _data;
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