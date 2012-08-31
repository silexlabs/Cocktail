/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.port.NativeElement;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;

/**
 * 
 * This is a special sub class of block box
 * for the HTMLBodyElement
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyBoxRenderer extends BlockBoxRenderer
{

	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overiden as the body's element renderer computed height is a special
	 * case where the height should be the height of the initial containing block
	 * if it specified as 'auto'
	 */
	override private function layoutSelf():Void
	{
		super.layoutSelf();
		if (_coreStyle.height == Dimension.cssAuto && (isPositioned() == false || isRelativePositioned() == true))
		{
			this.computedStyle.height = _containingBlock.getContainerBlockData().height - computedStyle.marginTop - computedStyle.marginBottom
			- computedStyle.paddingTop - computedStyle.paddingBottom;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The HTMLBodyElement uses the bounds of the viewport
	 * for its background
	 */
	override private function getBackgroundBounds():RectangleData
	{
		var windowData:ContainingBlockData = getWindowData();
		
		var width:Float = windowData.width;
		var height:Float = windowData.height;
		
		var bodyBounds:RectangleData = {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		}
		
		return bodyBounds;
	}
	
	
}