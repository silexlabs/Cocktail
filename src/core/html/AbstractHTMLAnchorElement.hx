package core.html;

import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.event.MouseEvent;
import core.dom.DOMData;

/**
 * The anchor element, used to link to an external document, or
 * to scroll to a position in the current document
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLAnchorElement extends HTMLElement
{
	/**
	 * The absolute URI of the linked resource.
	 * This attribute specifies the location of a Web resource, thus defining
	 * a link between the current element (the source anchor)
	 * and the destination anchor defined by this attribute.
	 */
	private var _href:String;
	public var href(get_href, set_href):String;
	
	/**
	 * Frame to render the resource in.
	 * This attribute specifies the name of a frame where a document is to be opened.
	 */
	private var _target:AnchorTarget;
	public var target(get_target, set_target):AnchorTarget;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		_target = AnchorTarget.self;
	}
	
	/**
	 * create a native anchor element
	 */
	override private function initNativeElement():Void
	{
		_nativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.link);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting a mouse down callback, it is always
	 * set on the mouse for the HTML anchor as even
	 * if the user sets a null callback for the mouse down
	 * event, the callback must be called to follow the
	 * http link if it is provided
	 */
	override private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
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
	override private function onMouseDownCallback(mouseEvent:MouseEvent):Void
	{
		if (_onMouseDown != null)
		{
			_onMouseDown(mouseEvent);
		}
		
		//TODO : implement Event.PreventDefault
		openDocument();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the linked document using
	 * runtime specific API. Overriden
	 * by runtime as needed
	 */
	private function openDocument():Void
	{
		//abstract
	}
	
	/**
	 * Utils method to convert the target enum to an HTML
	 * target attribute value
	 */
	private function getTargetAsString(value:AnchorTarget):String
	{
		var target:String;
		
		switch (value)
		{
			case AnchorTarget.blank:
				target = "_blank";
				
			case AnchorTarget.parent:
				target = "_parent";
				
			case AnchorTarget.self:
				target = "_self";
				
			case AnchorTarget.top:
				target = "_top";
		}
		
		return target;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOCUMENT LINK SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set the href attribute and refresh
	 * the mouse down callback with the new href
	 * value
	 */
	private function set_href(value:String):String
	{
		_href = value;
		set_onMouseDown(_onMouseDown);
		return value;
	}
	
	private function get_href():String
	{
		return _href;
	}
		
	/**
	 * set the target attribute and refresh
	 * the mouse down callback with the new target
	 * value
	 */
	private function set_target(value:AnchorTarget):AnchorTarget
	{
		_target = value;
		set_onMouseDown(_onMouseDown);
		
		return value;
	}
	
	private function get_target():AnchorTarget
	{
		return _target;
	}
	
	
	
}