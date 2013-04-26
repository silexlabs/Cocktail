/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.core.config.Config;
import cocktail.core.renderer.ElementRenderer;

/**
 * Compositing layer are used for elements 
 * which can't be rendered by drawing bitmap,
 * for instance an hardware accelerated video
 * rendering is handled by the GPU. It is
 * given a compositing layer so that it can
 * be integrated in the DOM
 * 
 * @author Yannick DOMINGUEZ
 */
class CompositingLayerRenderer extends LayerRenderer
{

	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	/**
	 * A compositing layer in most cases has its own
	 * graphic context for compositing, but it may
	 * depend. For instance a plugin layer renderer might
	 * not always need a graphic context based on its plugin
	 */
	override private function establishesNewGraphicsContext():Bool
	{
		//compositing may be deactivated altogether 
		if (Config.getInstance().enableCompositing == true)
		{
			if (isCompositingLayer() == true)
			{
				return true;
			}
			else
			{
				return super.establishesNewGraphicsContext();
			}
		}
		return false;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	////////////////////////////////
	
	override public function isCompositingLayer():Bool
	{
		return true;
	}
	
	
}