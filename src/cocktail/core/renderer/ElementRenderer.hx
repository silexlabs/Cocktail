/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.DrawingManager;
import cocktail.core.geom.GeomData;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import haxe.Timer;


/**
 * This is the base class for element renderers.
 * An ElementRenderer is responsible for displaying
 * an element of the DOM tree on screen
 * 
 * A tree of ElementRenderers, paralleling the DOM tree
 * is built for rendering, starting at the HTMLBodyElement
 * 
 * Each element of the DOM tree which must be displayed
 * creates a corresponding ElementRenderer. For instance,
 * an HTML 'div' element by default will create a 
 * BlockBoxRenderer to be displayed. A TextNode in 
 * the DOM tree will create a TextRenderer in the 
 * rendering tree.
 * 
 * An ElementRenderer is associated with a CoreStyle object
 * which holds all of the styles used to render the
 * ElementRenderer.
 * 
 * An ElementRenderer knows how to layout itself, meaning
 * that once laid out it knows all its necessary bounds
 * to be rendered
 * 
 * It also knows how to render itself. The rendering will
 * be started by the LayerRenderer associated with the
 * ElementRenderer
 * 
 * Once an ElementRenderer has been laid out, it holds
 * a reference to all the bounds needed to be rendered
 * on the screen
 * 
 * @author Yannick DOMINGUEZ
 */
class ElementRenderer extends Node
{
	/**
	 * The bounds of the ElementRenderer.
	 * 
	 * For ElementRenderers conforming to the box model, such
	 * as block or inline box, the width and height represents
	 * the border box of the element. For instance for width, it
	 * is the width from the left border to the right border, 
	 * including the borders width.
	 * 
	 * For ElementRenderers not conforming to the box model,
	 * for instance a TextRenderer, it is the width and height
	 * of their content. For instance, for a TextRenderer, the width
	 * will be the width of the bounds of its formatted TextLineBoxes
	 * 
	 * The x and y of the bounds are relative to the padding edge of
	 * the containing block of the ElementRenderer, which is the BlockBoxRenderer
	 * which established the formatting context this ElementRenderer 
	 * participates in.
	 */
	private var _bounds:RectangleData;
	public var bounds(get_bounds, set_bounds):RectangleData;
	
	/**
	 * The bounds of the ElementRenderer in the space of the Window.
	 * 
	 * This is a utility read-only property which returns the
	 * relevant global bounds for an ElementRenderer. For instance
	 * if the ElementRenderer uses the normal flow, then its bounds
	 * will be used to determine its global bounds whereas if it
	 * is absolutely positioned, it will use its positioned bounds
	 */
	public var globalBounds(get_globalBounds, never):RectangleData;
	
	/**
	 * This is the position of the top left padding box corner of the 
	 * containing block of this ElementRenderer in the Window space.
	 * This is used to render elements using the normal flow.
	 * 
	 * When added to the x and y bounds of the ElementRenderer, 
	 * it gives the global x and y of the ElementRenderer
	 */
	private var _globalContainingBlockOrigin:PointData;
	public var globalContainingBlockOrigin(get_globalContainingBlockOrigin, set_globalContainingBlockOrigin):PointData;
	
	/**
	 * This is the position of the top left corner of this
	 * ElementRenderer relative to the top left padding box
	 * corner of the first positioned ancestor of this
	 * ElementRenderer.
	 * 
	 * It is used when this ElementRenderer
	 * is absolutely positioned. When added to the global
	 * positioned ancesotr origin, it gives the global
	 * positioned origin of the ElementRenderer
	 */
	private var _positionedOrigin:PointData;
	public var positionedOrigin(get_positionedOrigin, set_positionedOrigin):PointData;
	
	/**
	 * This is the position of the top left padding box corner
	 * of the first positioned ancestor of this ElementRenderer
	 * in the Window space.
	 * 
	 * It is used when this ElementRenderer
	 * is absolutely positioned.
	 */
	private var _globalPositionnedAncestorOrigin:PointData;
	public var globalPositionnedAncestorOrigin(get_globalPositionnedAncestorOrigin, set_globalPositionnedAncestorOrigin):PointData;
	
	/**
	 * A reference to the Node in the DOM tree
	 * which created this ElementRenderer. It might
	 * be an HTMLElement or a Text node
	 */
	private var _node:Node;
	public var node(get_node, never):Node;
	
	/**
	 * A reference to the coreStyle from which
	 * the styles of this ElementRenderer are retrieved
	 */
	private var _coreStyle:CoreStyle;
	public var coreStyle(get_coreStyle, set_coreStyle):CoreStyle;
	
	/**
	 * A reference to the LayerRenderer in the LayerRenderer tree
	 * responsible for rendering this ElementRenderer
	 */
	private var _layerRenderer:LayerRenderer;
	public var layerRenderer(getLayerRenderer, setLayerRenderer):LayerRenderer;
	
	/**
	 * A reference to the line boxes generated by this ElementRenderer. For
	 * instance for a Text renderer, an array of Text line box will be created.
	 * 
	 * For a block box which doesn't establish an inline formatting context,
	 * no line box will be created
	 */ 
	private var _lineBoxes:Array<LineBox>;
	public var lineBoxes(getLineBoxes, setLineBoxes):Array<LineBox>;
	
	/**
	 * determine wether the HTMLElement is currently being
	 * laid out, in which case it won't take any subsequent
	 * layout request into account
	 */
	private var _isLayingOut:Bool;
	
	/**
	 * Determine wheter this ElementRenderer establishes its own
	 * stacking context (instantiates a new LayerRenderer)
	 * 
	 * TODO : not very clean, should layerRenderer be null instead
	 * for ElementRenderernot starting a layer ?
	 */
	private var _hasOwnLayer:Bool;
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyleData;
	
	/**
	 * get/set the scrolling in the x axis of this ElementRenderer
	 */
	public var scrollLeft(get_scrollLeft, set_scrollLeft):Float;
	
	/**
	 * get/set the scrolling in the y axis of this ElementRenderer
	 */
	public var scrollTop(get_scrollTop, set_scrollTop):Float;
	
	/**
	 * class constructor. init class attribute
	 */
	public function new(node:Node) 
	{
		super();

		_node = node;
		
		_isLayingOut = false;
		_hasOwnLayer = false;
		
		_bounds = {
			x:0.0,
			y:0.0,
			width : 0.0,
			height: 0.0
		}
		
		_positionedOrigin = {
			x:0.0,
			y:0.0
		}
		
		_globalPositionnedAncestorOrigin = {
			x:0.0,
			y:0.0
		}
		
		_globalContainingBlockOrigin = {
			x:0.0,
			y:0.0
		}
		
		_lineBoxes = new Array<LineBox>();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as when an ElementRenderer is appended, its LayerRenderer
	 * must be attached so that it can be rendered
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		var elementRendererChild:ElementRenderer = cast(newChild);
		elementRendererChild.attachLayer();
		invalidateLayout();
		return newChild;
	}
	
	
	/**
	 * overriden as when an ElementRenderer is removed, its LayerRenderer
	 * might be removed form the LayerRenderer tree if it created it
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		var elementRendererChild:ElementRenderer = cast(oldChild);
		elementRendererChild.detachLayer();
		invalidateLayout();
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Render this ElementRenderer using the provided
	 * graphic context as canvas
	 */
	public function render(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/*
	 * Layout this ElementRenderer so that it knows its bounds and can be rendered to the screen
	 */ 
	public function layout(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach the LayerRenderer of this ElementRenderer
	 * to the LayerRenderer tree so that it can be rendered
	 */
	public function attachLayer():Void
	{
		//create the LayerRenderer if needed
		if (_layerRenderer == null)
		{
			var parent:ElementRenderer = cast(_parentNode);
			if (parent.layerRenderer != null)
			{
				createLayer(parent.layerRenderer);
			}
		}
		
		//the ElementRenderer is attached to the LayerRenderer
		//tree and must now also attach its children
		for (i in 0..._childNodes.length)
		{
			var child:ElementRenderer = cast(_childNodes[i]);
			child.attachLayer();
		}
	}
	
	/**
	 * Detach the LayerRenderer of this ElementRenderer if necessary
	 */
	public function detachLayer():Void
	{
		//first detach the LayerRenderer of all its children
		for (i in 0..._childNodes.length)
		{
			var child:ElementRenderer = cast(_childNodes[i]);
			child.detachLayer();
		}
		
		//only detach the LayerRenderer if this ElementRenderer
		//created it, else it will be detached by the ElementRenderer
		//which created it when detached
		if (_hasOwnLayer == true)
		{
			var parent:ElementRenderer = cast(_parentNode);
			parent.layerRenderer.removeChild(_layerRenderer);
			_layerRenderer.detach();
			_hasOwnLayer = false;
		}
		
		_layerRenderer = null;
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	////////////////////////////////
	
	public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	public function isFloat():Bool
	{
		return false;
	}
	
	public function isPositioned():Bool
	{
		return false;
	}
	
	public function isInlineLevel():Bool
	{
		return false;
	}
	
	public function isReplaced():Bool
	{
		return false;
	}
	
	public function isText():Bool
	{
		return false;
	}
	
	public function isRelativePositioned():Bool
	{
		return false;
	}
	
	public function childrenInline():Bool
	{
		return false;
	}
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	private function establishesNewStackingContext():Bool
	{
		return false;
	}
	
	/**
	 * Create a new LayerRenderer for this ElementRenderer or
	 * use the one from its parent
	 */
	private function createLayer(parentLayer:LayerRenderer):Void
	{
		if (establishesNewStackingContext() == true)
		{
			_layerRenderer = new LayerRenderer(this);
			parentLayer.appendChild(_layerRenderer);
			_hasOwnLayer = true;
		}
		else
		{
			_layerRenderer = parentLayer;
		}
	}
	
	/**
	 * Determine the bounds of the children of this ElementRenderer
	 * from the array of their bounds
	 */
	private function getChildrenBounds(childrenBounds:Array<RectangleData>):RectangleData
	{
		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		
		for (i in 0...childrenBounds.length)
		{
			if (childrenBounds[i].x < left)
			{
				left = childrenBounds[i].x;
			}
			if (childrenBounds[i].y < top)
			{
				top = childrenBounds[i].y;
			}
			if (childrenBounds[i].x + childrenBounds[i].width > right)
			{
				right = childrenBounds[i].x + childrenBounds[i].width;
			}
			if (childrenBounds[i].y + childrenBounds[i].height  > bottom)
			{
				bottom = childrenBounds[i].y + childrenBounds[i].height;
			}
		}
			
		bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
		
		//TODO : need to implement better fix,
		//sould not be negative
		if (bounds.width < 0)
		{
			bounds.width = 0;
		}
		if (bounds.height < 0)
		{
			bounds.height = 0;
		}
				
		return bounds;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the value of a style that require
	 * a re-layout (such as width, height, display...) is
	 * changed.
	 * 
	 * An invalidated ElementRenderer will in turn invalidate its
	 * parent and so on until the initial ElementRenderer is invalidated.
	 * The initial ElementRenderer will then layout itself, laying out
	 * at the same time all its invalidated children.
	 * 
	 * TODO : shouldn't need to invalidate all of the rendering tree
	 * 
	 * A layout can be immediate or scheduled asynchronously, which
	 * increase preformance when many style value are set in a 
	 * row as the layout only happen once
	 */
	public function invalidateLayout(immediate:Bool = false):Void
	{
		//only invalidate the parent if it isn't
		//already being laid out or if an immediate layout is required
		if (this._isLayingOut == false || immediate == true)
		{
			//set the layout flag to prevent multiple
			//layout of the ElementRenderer in a row
			//The ElementRenderer will be able to be invalidated
			//again once it has been laid out
			this._isLayingOut = true;
			
			//if the ElementRenderer doesn't have a parent, then it
			//is not currently added to the DOM and doesn't require
			//a layout
			//
			//TODO : shouldn't be possible anymore, when an HTMLElement is not
			//attached to the DOM, it doesn't create an ElementRenderer,
			//only the initial ElementRenderer doesn't have a parent
			if (this._parentNode != null)
			{
				var parent:ElementRenderer = cast(_parentNode);
				parent.invalidateLayout(immediate);	
			}
		}
	}
	
	public function invalidateText():Void
	{
		for (i in 0..._childNodes.length)
		{
			var child:ElementRenderer = cast(_childNodes[i]);
			child.invalidateText();
		}
		invalidateLayout();
	}
	
	public function invalidateLayer():Void
	{
		detachLayer();
		attachLayer();
		invalidateLayout();
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_globalBounds():RectangleData
	{
		var globalX:Float;
		var globalY:Float;
		
		if (_coreStyle.position == fixed)
		{
			
			if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = _globalContainingBlockOrigin.x + _bounds.x;
			}
			else
			{
				globalX = _positionedOrigin.x;
			}
			
			if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
			{
				globalY = _globalContainingBlockOrigin.y + _bounds.y;
			}
			else
			{
				globalY = _positionedOrigin.y;
			}
		}
		else if (_coreStyle.position == absolute)
		{
			if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = _globalContainingBlockOrigin.x + _bounds.x;
			}
			else
			{
				globalX = _globalPositionnedAncestorOrigin.x + _positionedOrigin.x;
			}
			
			if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
			{
				globalY = _globalContainingBlockOrigin.y + _bounds.y;
			}
			else
			{
				globalY = _globalPositionnedAncestorOrigin.y + _positionedOrigin.y;
			}
		}
		else
		{
			globalX = _globalContainingBlockOrigin.x + _bounds.x;
			globalY = _globalContainingBlockOrigin.y + _bounds.y;
		}
		
		
		return {
			x:globalX,
			y:globalY,
			width:bounds.width,
			height:bounds.height
		}
	}
	
	private function getComputedStyle():ComputedStyleData
	{
		return _coreStyle.computedStyle;
	}
	
	private function setComputedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _coreStyle.computedStyle = value;
	}
	
	private function getLineBoxes():Array<LineBox>
	{
		return _lineBoxes;
	}
	
	private function setLineBoxes(value:Array<LineBox>):Array<LineBox>
	{
		return _lineBoxes = value;
	}
	
	private function setLayerRenderer(value:LayerRenderer):LayerRenderer
	{
		return _layerRenderer = value;
	}
	
	private function getLayerRenderer():LayerRenderer
	{
		return _layerRenderer;
	}
	
	private function get_coreStyle():CoreStyle
	{
		return _coreStyle;
	}
	 
	private function set_coreStyle(value:CoreStyle):CoreStyle
	{
		_coreStyle = value;
		invalidateLayout();
		return value;
	}
	
	private function get_bounds():RectangleData
	{
		return _bounds;
	}
	
	private function set_bounds(value:RectangleData):RectangleData
	{
		return _bounds = value;
	}
	
	private function get_globalContainingBlockOrigin():PointData
	{
		return _globalContainingBlockOrigin;
	}
	
	private function set_globalContainingBlockOrigin(value:PointData):PointData
	{
		return _globalContainingBlockOrigin = value;
	}
	
	private function get_positionedOrigin():PointData
	{
		return _positionedOrigin;
	}
	
	private function set_positionedOrigin(value:PointData):PointData
	{
		return _positionedOrigin = value;
	}
	
	private function get_globalPositionnedAncestorOrigin():PointData 
	{
		return _globalPositionnedAncestorOrigin;
	}
	
	private function set_globalPositionnedAncestorOrigin(value:PointData):PointData 
	{
		return _globalPositionnedAncestorOrigin = value;
	}
	
	private function get_node():Node
	{
		return _node;
	}
	
	private function get_scrollLeft():Float 
	{
		return 0;
	}
	
	private function set_scrollLeft(value:Float):Float 
	{
		return value;
	}
	
	private function get_scrollTop():Float 
	{
		return 0;
	}
	
	private function set_scrollTop(value:Float):Float 
	{
		return value;
	}
	
	
	
}