/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
import cocktail.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.geom.GeomData;
import cocktail.core.layer.InputLayerRenderer;
import cocktail.port.Bindings;

/**
 * This is an base ElementRenderer in charge of
 * rendering a input form controls
 * 
 * @author Yannick DOMINGUEZ
 */
class InputRenderer extends BlockBoxRenderer
{
	/**
	 * get/set the value of the input
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * get/set checkedness of the input
	 */
	public var checked(get_checked, set_checked):Bool;
	
	/**
	 * Get/set the maxLength of the input
	 */
	public var maxLength(default, set_maxLength):Int;
	
	/**
	 * Get/set wether the input is disabled (can't be 
	 * interacted by the user, however value of input
	 * can be changed programmatically)
	 */
	public var disabled(default, set_disabled):Bool;
	
	/**
	 * Get/set wether the input is read-only (similar
	 * to disabled but only applies to text based input)
	 */
	public var readonly(default, set_readonly):Bool;
	
	/**
	 * Return the instrinsic width of the native control
	 */
	public var intrinsicWidth(get_intrinsicWidth, null):Int;
	
	/**
	 * Return the instrinsic height of the native control
	 */
	public var intrinsicHeight(get_intrinsicHeight, null):Int;
	
	/**
	 * a reference to the native input renderedd by
	 * this input renderer
	 */
	public var nativeInput(default, null):NativeInput;
	
	/**
	 * Callback, called when the native input is
	 * "activated" (clicked, touched...)
	 */
	public var onActivate:Void->Void;
	
	/**
	 * Callback, called when text is input
	 * by the user, only applies to text based
	 * input
	 */
	public var onInput:Void->Void;
	
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		
		createNativeInput();
		setNativeInputCallbacks();
	}
	
	/**
	 * Instantiate a specific native input, 
	 * overriden by inheriting element renderer
	 */
	private function createNativeInput():Void
	{
		//abstract
	}
	
	/**
	 * set up callbacks to respond to event of
	 * the native input
	 */
	private function setNativeInputCallbacks():Void
	{
		//forwad native element callbacs
		nativeInput.onActivate = function() { onActivate(); }
		nativeInput.onInput = function() { onInput(); };
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC FOCUS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set native focus on native input
	 */
	public function focus():Void
	{
		nativeInput.focus();
	}
	
	/**
	 * blur native focus on native input
	 */
	public function blur():Void
	{
		nativeInput.blur();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An input always create its own layer,
	 * has it may need to be composited to
	 * leverage the native platform input
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}
	
	/**
	 * An input always create its own compositing
	 * layer
	 */
	override private function doCreateLayer():Void
	{
		layerRenderer = new InputLayerRenderer(this);
	}
	
	/**
	 * Overriden to update the native input display
	 */
	override private function renderSelf(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO)
	{
		super.renderSelf(graphicContext, clipRect, scrollOffset);
		updateNativeInputViewport(scrollOffset, clipRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the bounds of the native input
	 */
	private function updateNativeInputViewport(scrollOffset:PointVO, clipRect:RectangleVO):Void
	{
		var globalBounds:RectangleVO = this.globalBounds;
		
		//set the position and size of the native input, relative
		//to the viewport
		var x:Float = globalBounds.x + coreStyle.usedValues.borderLeftWidth - scrollOffset.x;
		var y:Float =  getViewportY(scrollOffset);
		
		//add the layer's transformations if it has any
		//
		//TODO 3 : only translation for now
		var layerMatrix:Matrix = layerRenderer.matrix;
		x += layerMatrix.e;
		y += layerMatrix.f;
		
		var width:Float =  globalBounds.width - coreStyle.usedValues.borderLeftWidth - coreStyle.usedValues.borderRightWidth;
		var height:Float =  globalBounds.height - coreStyle.usedValues.borderTopWidth - coreStyle.usedValues.borderBottomWidth;
		var viewport:RectangleVO = new RectangleVO();
		viewport.x = x;
		viewport.y = y;
		viewport.width = width;
		viewport.height = height;
		nativeInput.viewport = viewport;
		
		//update clip rect of native text input, so that
		//it doesn't overflow its layer clip rect
		//
		//TODO 3 : use direct reference to layerRenderer clipRect as there
		//seems to be a bug with the provided clip rect which is modified
		nativeInput.clipRect = layerRenderer.clipRect;
	}
	
	/**
	 * special case for viewport's y which might vary based on inputs
	 */
	private function getViewportY(scrollOffset:PointVO):Float
	{
		 return globalBounds.y + coreStyle.usedValues.borderTopWidth + (globalBounds.height - coreStyle.usedValues.borderTopWidth - coreStyle.usedValues.borderBottomWidth) / 2 - coreStyle.fontMetrics.fontSize + coreStyle.fontMetrics.ascent / 2 - scrollOffset.y;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_value():String 
	{
		return nativeInput.value;
	}
	
	private function set_value(value:String):String 
	{
		return nativeInput.value = value;
	}
	
	private function set_maxLength(value:Int):Int
	{
		return nativeInput.maxLength = value;
	}
	
	private function set_disabled(value:Bool):Bool
	{
		return nativeInput.disabled = value;
	}
	
	private function set_readonly(value:Bool):Bool
	{
		return nativeInput.readonly = value;
	}
	
	private function get_checked():Bool 
	{
		return nativeInput.checked;
	}
	
	private function set_checked(value:Bool):Bool 
	{
		return nativeInput.checked = value;
	}
	
	private function get_intrinsicWidth():Int
	{
		return nativeInput.intrinsicWidth;
	}
	
	private function get_intrinsicHeight():Int
	{
		return nativeInput.intrinsicHeight;
	}
}
