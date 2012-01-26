/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktail.nativeElement.NativeElement;
import haxe.Log;
import js.Dom;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.Matrix;
import cocktail.geom.GeomData;

/**
 * This is the DOMElement implementation for JavaScript. 
 * It manipulates the native HTML DOM
 * @author Yannick DOMINGUEZ
 */
class DOMElement extends AbstractDOMElement
{
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN FOCUS SETTER/GETTER AND METHODS
	// The JavaScript focus implementation relies on the browser
	// instead of Cocktail's FocusManager
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a listener on the nativeElement for focus events
	 */
	override private function setOnFocusIn(value:Void->Void):Void->Void
	{
		if (value == null)
		{
			_nativeElement.onfocus = null;
		}
		else
		{
			_nativeElement.onfocus = onNativeFocusIn;
		}
		
		return _onFocusIn = value;
	}
	
	/**
	 * Set a listener on the nativeElement for blur events
	 */
	override private function setOnFocusOut(value:Void->Void):Void->Void
	{
		if (value == null)
		{
			_nativeElement.onblur = null;
		}
		else
		{
			_nativeElement.onblur = onNativeFocusOut;
		}
		
		return _onFocusOut = value;
	}

	/**
	 * When tab is enabled, set the stored tabIndex on the
	 * native HTML element, as in HTML, non-focusable elements
	 * such as a <div> can still receive focus if a tabIndex
	 * is explicitely set on them
	 */
	override private function setTabEnabled(value:Bool):Bool
	{
		if (value == true)
		{
			untyped _nativeElement.tabIndex = tabIndex;
		}
		else
		{
			untyped _nativeElement.tabIndex = null;
		}
		
		return _tabEnabled = value;
	}
	
	/**
	 * Stores the tabIndex attribute and reset the tabEnabled
	 * setter. This way the HTML attribute will only be set if
	 * tab is enabled
	 */
	override private function setTabIndex(value:Int):Int
	{
		_tabIndex = value;
		tabEnabled = tabEnabled;
		
		return _tabIndex;
	}
	
	/**
	 * set focus on the nativeElement
	 */
	override public function focus():Void
	{
		_nativeElement.focus();
	}
	
	/**
	 * When a native focus event is dispatched,
	 * call the focus callback
	 */
	private function onNativeFocusIn(event:Dynamic):Void
	{
		if (onFocusIn != null)
		{
			onFocusIn();
		}
	}
	
	/**
	 * When a native blur event is dispatched,
	 * call the blur callback
	 */
	private function onNativeFocusOut(event:Dynamic):Void
	{
		if (onFocusOut != null)
		{
			onFocusOut();
		}
	}
}