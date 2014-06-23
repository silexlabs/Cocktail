/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.graphics;

import cocktail.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.core.layout.LayoutData;

/**
 * Represents the graphics context at the 
 * root of the graphics context tree
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialGraphicsContext extends GraphicsContext
{
	/**
	 * class constructor
	 */
	public function new(layerRenderer:LayerRenderer)
	{
		super(layerRenderer);
		
		//when the initial graphics context is created
		//or re-created, the whole native layer tree needs
		//an update
		invalidateNativeLayer();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE GRAPHICS CONTEXT TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For the initial graphic context, 
	 * make the graphics context root attach
	 * itself to the root of the native
	 * display list
	 */
	override private function doAttach():Void
	{
		//retrieve platform specific root layer
		nativeLayer.attach(getTopPlatformLayer(), 0);
		
		//when the initial graphics context, is attached,
		//the bitmap size needs to be invalidated so that
		//the bitmap surface gets initialised
		invalidateBitmapSize();
	}
	
	/**
	 * make the graphics context implementation 
	 * detach itself from the root of
	 * the native display list
	 */
	override private function doDetach():Void
	{
		nativeLayer.detach(getTopPlatformLayer());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE FUNCTION
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * retrieve platform specific root layer
	 */
	private function getTopPlatformLayer():PlatformLayer
	{
		var htmlDocument:HTMLDocument = cast(layerRenderer.rootElementRenderer.domNode.ownerDocument);
		return htmlDocument.getTopPlatformLayer();
	}
}
