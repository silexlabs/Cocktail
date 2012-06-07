/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.geom.GeomData;
import cocktail.core.NativeElement;
import cocktail.core.style.StyleData;

/**
 * 
 * This is the base class for the elements which can be laid out as line, like text.
 * 
 * For instance, an InlineBoxRenderer will generate as many LineBox as the number
 * of lines where one of its children is.
 * For the text, a TextRenderer will generate as many TextLineBox as there is words
 * and space in its text.
 * 
 * The line boxes are owned both by the element renderer which created them and the
 * container block which lay them out in a line.
 * 
 * Block box renderer which establishes an inline formatting context has an array 
 * of root line box, each one being the root of one line in the inline formatting context.
 * 
 * It extends Node as line box are stored in a tree for each line of an inline
 * formatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class LineBox extends Node
{
	/**
	 * A reference to the element renderer which created this
	 * line box
	 */
	private var _elementRenderer:ElementRenderer;
	public var elementRenderer(get_elementRenderer, never):ElementRenderer;
	
	/**
	 * A reference to the LayerRenderer which will render this line box.
	 * It is retrieved from the ElementRenderer
	 */
	public var layerRenderer(get_layerRenderer, never):LayerRenderer;
	
	/**
	 * the bounds of the line box, in the space of its containing
	 * block (the block which started the inline formatting context)
	 */
	private var _bounds:RectangleData;
	public var bounds(get_bounds, set_bounds):RectangleData;
	
	/**
	 * The native element wrapped by this line box, for instance for 
	 * a text line box, it will be a native text element
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	/**
	 * the ascent of the line box with its leading applied
	 */
	private var _leadedAscent:Float;
	public var leadedAscent(get_leadedAscent, set_leadedAscent):Float;
	
	/**
	 * the descent of the line box with its leading applied
	 */
	private var _leadedDescent:Float;
	public var leadedDescent(get_leadedDescent, set_leadedDescent):Float;
	
	/**
	 * the left margin of the line box
	 */
	private var _marginLeft:Int;
	public var marginLeft(get_marginLeft, set_marginLeft):Int;
	
	/**
	 * the right margin of the line box
	 */
	private var _marginRight:Int;
	public var marginRight(get_marginRight, set_marginRight):Int;
	
	/**
	 * the left padding of the line box
	 */
	private var _paddingLeft:Int;
	public var paddingLeft(get_paddingLeft, set_paddingLeft):Int;
	
	/**
	 * the right margin of the line box
	 */
	private var _paddingRight:Int;
	public var paddingRight(get_paddingRight, set_paddingRight):Int;
	
	/**
	 * an instance of a background manager used to draw the backgrounds
	 * of line box generated by inline box renderer
	 */
	private var	_backgroundManager:BackgroundManager;
	
	/**
	 * class constructor. Init class attribute
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super();
			_bounds = {
			x:0.0,
			y:0.0,
			width:0.0,
			height:0.0
		}
		_elementRenderer = elementRenderer;
		
		_leadedAscent = 0;
		_leadedDescent = 0;
		
		_backgroundManager = new BackgroundManager();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render this LineBox using the provided
	 * graphic context as canvas
	 * 
	 * Default is to draw the background of the line box, this
	 * is expected behaviour for line boxes generated by an InlineBoxRenderer
	 */
	public function render(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _elementRenderer.coreStyle);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		for (i in 0...backgrounds.length)
		{
			backgrounds[i].x = _bounds.x  + _elementRenderer.globalBounds.x - _elementRenderer.bounds.x + relativeOffset.x;
			backgrounds[i].y = _bounds.y + _elementRenderer.globalBounds.y - _elementRenderer.bounds.y + relativeOffset.y;
			containerGraphicContext.addChild(backgrounds[i]);
		}
		#end
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Wether this is a TextLineBox
	 */
	public function isText():Bool
	{
		return false;
	}
	
	/**
	 * Helper method to determine if this
	 * line box wraps a space character
	 */
	public function isSpace():Bool
	{
		return false;
	}
	
	/**
	 * Wether the lineboxe's ElementRenderer is
	 * aboslutely positioned
	 * 
	 * TODO 5 : check of still necessary
	 */
	public function isAbsolutelyPositioned():Bool
	{
		return _elementRenderer.coreStyle.computedStyle.position == fixed || _elementRenderer.coreStyle.computedStyle.position == absolute;
	}
	
	/**
	 * Wether the lineBoxe's ElementRenderer
	 * establishes a new formatting context
	 */
	public function establishesNewFormattingContext():Bool
	{
		return _elementRenderer.establishesNewFormattingContext();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC FORMATTING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 4 : doc + missing values for vertical align
	public function getBaselineOffset(parentBaselineOffset:Float, parentXHeight:Float):Float
	{
		
		var baselineOffset:Float = parentBaselineOffset + _elementRenderer.coreStyle.computedStyle.verticalAlign;
		
		switch (_elementRenderer.coreStyle.verticalAlign)
		{
			case VerticalAlign.middle:
				baselineOffset -=  (bounds.height / 2) - (parentXHeight / 2);
				
			default:	
		}
		
		return baselineOffset;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_elementRenderer():ElementRenderer
	{
		return _elementRenderer;
	}
	
	private function get_layerRenderer():LayerRenderer
	{
		return _elementRenderer.layerRenderer;
	}
	
	private function get_paddingRight():Int 
	{
		return _paddingRight;
	}
	
	private function set_paddingRight(value:Int):Int 
	{
		return _paddingRight = value;
	}
	
	private function get_paddingLeft():Int 
	{
		return _paddingLeft;
	}
	
	private function set_paddingLeft(value:Int):Int 
	{
		return _paddingLeft = value;
	}
	
	public function get_marginRight():Int
	{
		return _marginRight;
	}
	
	public function get_marginLeft():Int
	{
		return _marginLeft;
	}
	
	public function set_marginLeft(value:Int):Int
	{
		return _marginLeft = value;
	}
	
	public function set_marginRight(value:Int):Int
	{
		return _marginRight = value;
	}
	
	private function get_nativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function get_bounds():RectangleData
	{
		return _bounds;
	}
	
	private function set_bounds(value:RectangleData):RectangleData
	{
		return _bounds = value;
	}
	
	private function get_leadedAscent():Float 
	{
		return _leadedAscent;
	}
	
	private function set_leadedAscent(value:Float):Float 
	{
		return _leadedAscent = value;
	}
	
	private function get_leadedDescent():Float 
	{
		return _leadedDescent;
	}
	
	private function set_leadedDescent(value:Float):Float 
	{
		return _leadedDescent = value;
	}
}