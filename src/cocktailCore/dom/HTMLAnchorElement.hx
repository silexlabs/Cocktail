package cocktailCore.dom;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class HTMLAnchorElement extends HTMLElement
{

		/**
	 * set/get the URL to open when clicking on 
	 * the LinkDOMElement
	 */
	private var _href:String;
	public var href(getHref, setHref):String;
	
	/**
	 * set/get the target where to open
	 * the linked documenet (for instance, it can be in a new tab
	 * in a browser environnement or replace the current document)
	 */
	private var _target:LinkTargetValue;
	public var target(getTarget, setTarget):LinkTargetValue;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.link));
		_target = LinkTargetValue.self;
	}
	
	/**
	 * LinkDOMElement are tab enabled by default
	 */
	override private function initFocus():Void
	{
		super.initFocus();
		_tabEnabled = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting a mouse down callback, it is always
	 * set on the mouse for the LinkDOMElement as even
	 * if the user sets a null callback for the mouse down
	 * event, the callback must be called to follow the
	 * http link if it is provided
	 */
	override private function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		_onMouseDown = value;
		_mouse.onMouseDown = onMouseDownCallback;
		
		return _onMouseDown;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE EVENT CALLBACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the link in addition to calling the user callback
	 */
	override private function onMouseDownCallback(mouseEventData:MouseEventData):Void
	{
		if (_onMouseDown != null)
		{
			_onMouseDown(mouseEventData);
		}
		
		openLink();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the href link if provided using
	 * runtime specific API. Overriden
	 * by runtime as needed
	 */
	private function openLink():Void
	{
		//abstract
	}
	
	/**
	 * Utils method to convert the target enum to an HTML
	 * target attribute value
	 */
	private function getTargetAsString(value:LinkTargetValue):String
	{
		var target:String;
		
		switch (value)
		{
			case LinkTargetValue.blank:
				target = "_blank";
				
			case LinkTargetValue.parent:
				target = "_parent";
				
			case LinkTargetValue.self:
				target = "_self";
				
			case LinkTargetValue.top:
				target = "_top";
		}
		
		return target;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// LINK SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set the href attribute and refresh
	 * the mouse down callback with the new href
	 * value
	 */
	private function setHref(value:String):String
	{
		_href = value;
		setOnMouseDown(_onMouseDown);
		
		return value;
	}
	
	private function getHref():String
	{
		return _href;
	}
		
	/**
	 * set the target attribute and refresh
	 * the mouse down callback with the new target
	 * value
	 */
	private function setTarget(value:LinkTargetValue):LinkTargetValue
	{
		_target = value;
		setOnMouseDown(_onMouseDown);
		
		return value;
	}
	
	private function getTarget():LinkTargetValue
	{
		return _target;
	}
	
	
	
}