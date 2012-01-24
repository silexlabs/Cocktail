/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.domElement.DOMElementData;
import cocktail.mouse.MouseData;

/**
 * The link DOMElement is a special kind of
 * ContainerDOMElement, used to link to another
 * document. It emulates the behaviour of a <a>
 * HTML tag
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractLinkDOMElement extends ContainerDOMElement
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
	 * Save a reference to the onMouseDown callback set by the
	 * application developer on this LinkDOMElement. The LinkDOMElement has a
	 * default behaviour of opening the linked document but can
	 * also have an additional behaviour thanks to this callback.
	 * 
	 * When the application user clicks on the LinkDOMElement, the 
	 * application developer's callback is first executed if provided, then
	 * the link is opened if an "href" value was provided.
	 * 
	 * It is not yet possible to prevent opening the link in a
	 * cross-platform way when a mouse down callback is set
	 */
	private var _onMouseDown:MouseEventData->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.link));
		
		_target = LinkTargetValue.self;
	}
	
	override private function initFocus():Void
	{
		super.initFocus();
		_tabEnabled = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting a mouse down callback, the callback is
	 * wrapped in another callback which first execute the mouse down
	 * callback then tries to open the link
	 */
	override private function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		_onMouseDown = value;
		
		_mouse.onMouseDown = onLinkMouseDown;
		
		return _mouse.onMouseDown;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback wrapping the mouse down callback
	 */
	private function onLinkMouseDown(mouseEventData:MouseEventData):Void
	{
		//only execute mouse down callback
		//if defined
		if (_onMouseDown != null)
		{
			_onMouseDown(mouseEventData);
		}
		
		openLink();
	}
	
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