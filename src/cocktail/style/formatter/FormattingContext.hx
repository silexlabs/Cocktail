/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.formatter;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.floats.FloatsManager;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
 
class FormattingContext 
{

	private var _rootDOMElement:DOMElement;
	
	private var _formatedElements:Array<DOMElement>;
	
	private var _floatsManager:FloatsManager;
	public var floatsManager(getFloatsManager, never):FloatsManager;
	
	private var _flowData:FlowData;
	public var flowData(getFlowData, never):FlowData;
	
	
	public function new(domElement:DOMElement, previousFormatingContext:FormattingContext = null) 
	{
		
		_rootDOMElement = domElement;
		
		_flowData = initFlowData(domElement);
		
		_floatsManager = new FloatsManager();
		
		
		_formatedElements = new Array<DOMElement>();
		
		if (previousFormatingContext != null)
		{
			if (domElement.style.isFloat() == false)
			{
				_floatsManager.addLeftFloats(previousFormatingContext);
			}
		}
		
		
		startNewLine();
		
	}
	
	private function initFlowData(domElement:DOMElement):FlowData
	{
		return {
			x : domElement.style.computedStyle.paddingLeft,
			y : domElement.style.computedStyle.paddingTop,
			firstLineX : domElement.style.computedStyle.paddingLeft,
			firstLineY : domElement.style.computedStyle.paddingTop,
			maxLineWidth : domElement.style.computedStyle.width,
			containingBlockWidth : domElement.style.computedStyle.width,
			containingBlockHeight : domElement.style.computedStyle.height,
			totalHeight : 0,
			maxLineHeight : 0
		};
	}
	
	public function insert(domElement:DOMElement):Void
	{
		_formatedElements.push(domElement);
		place(domElement);
		removeFloats();
	}
	
	private function place(domElement:DOMElement):Void
	{
		
	}
	
	public function insertFloat(domElement:DOMElement):Void
	{
		var floatData:FloatData = _floatsManager.computeFloatData(domElement, _flowData);
		
		placeFloat(domElement, floatData);
	}
	
	public function clearFloat(clear:ClearStyleValue):Void
	{

	}
	
	private function placeFloat(domElement:DOMElement, floatData:FloatData):Void
	{
		
	}
	
	private function removeFloats():Void
	{
		_floatsManager.removeFloats(_flowData.y);
	}
	
	
	public function retrieveFloats(formattingContext:FormattingContext):Void
	{
		_floatsManager.retrieveFloats(formattingContext);
	}
	
	private function startNewLine():Void
	{
		
	}
	
	public function getFloatsManager():FloatsManager
	{
		return _floatsManager;
	}
	
	public function getFlowData():FlowData
	{
		return _flowData;
	}
	
	public function getRootDOMElement():DOMElement
	{
		return _rootDOMElement;
	}
	
}