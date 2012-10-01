/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.graphics;

import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.GraphicsContextImpl;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.dom.NodeBase;
import cocktail.core.geom.GeomData;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;
import cocktail.port.NativeLayer;


/**
 * Each LayerRenderer has a reference to a graphics context.
 * Graphics context are stored as a tree of GraphicContext object.
 * 
 * Each GraphicContext has a bitmap surface which can be painted
 * onto. They also have a reference to a native object representing
 * the concept of a layer in the target platform. For instance, for
 * the Flash platform, a layer can be assimilated to a Sprite.
 * 
 * They are the closest abstraction in Cocktail from the native
 * display list of the underlying platform. The tree of GraphicContext
 * builds a tree of native layer from the target platform.
 * 
 * We could have had just one GraphicContext for the whole document and
 * paint onto it, but it seems like a better approach for platform integration
 * to instead leverage the native display list of the platform.
 * 
 * For instance, for a video it allows the underlying platform to take care of the rendering,
 * the video being given its own layer. With just one GraphicContext, the video would have needed
 * to be painted onto the unique GraphicContext each frame.
 * 
 * It also facilitates integration with native platform UI widget which can live on its own native
 * layer, being composited by the platform, instead of being painted onto a single bitmap.
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicsContext extends NodeBase<GraphicsContext>
{
	/**
	 * A reference to a native layer
	 */
	public var nativeLayer(get_nativeLayer, never):NativeLayer;
	
	/**
	 * A reference to the LayerRenderer which created this GraphicsContext
	 */
	public var layerRenderer(default, null):LayerRenderer;
	
	/**
	 * An instance of the class which actually implements the 
	 * platform specific API calls to draw and build the native
	 * display list. 
	 */
	public var graphics(default, null):GraphicsContextImpl;
	
	/**
	 * A flag set when the native layers needs to be re-attached to the native
	 * display list, after a change in the ordered list of child graphics
	 * context
	 */
	private var _needsNativeLayerUpdate:Bool;
	
	/**
	 * class constructor
	 * @param layerRenderer the LayerRenderer which instantiated this 
	 * GraphicsContext
	 */
	public function new(layerRenderer:LayerRenderer)
	{
		super();
		this.layerRenderer = layerRenderer;
		_needsNativeLayerUpdate = true;
		graphics = new GraphicsContextImpl();
	}
	
	/**
	 * clean-up method, free memory used
	 * by graphics context
	 */
	public function dispose():Void
	{
		graphics.dispose();
		graphics = null;
		layerRenderer = null;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Overriden to invalidate the native layer tree
	 */ 
	override public function appendChild(newChild:GraphicsContext):GraphicsContext
	{
		super.appendChild(newChild);
		
		newChild.invalidateNativeLayer();
		
		return newChild;
	}
	
	/**
	 * Overriden to invalidate the native layer tree
	 * and detach the old child
	 */ 
	override public function removeChild(oldChild:GraphicsContext):GraphicsContext
	{
		oldChild.detach();
		oldChild.invalidateNativeLayer();
		
		super.removeChild(oldChild);
		
		return oldChild;
	}
	
	/**
	 * Overriden to invalidate the native layer tree
	 */ 
	override public function insertBefore(newChild:GraphicsContext, refChild:GraphicsContext):GraphicsContext
	{
		super.insertBefore(newChild, refChild);

		newChild.invalidateNativeLayer();
		
		return newChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC GRAPHICS CONTEXT TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Main method building the native layer tree.
	 * Called by the document when the tree needs
	 * to be updated
	 */
	public function updateNativeLayer():Void
	{
		if (_needsNativeLayerUpdate == true)
		{
			_needsNativeLayerUpdate = false;
			detach();
			attach();
			return;
		}
		
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].updateNativeLayer();
		}
	}
	
	/**
	 * called when the native layer is invalid, schedule
	 * a call to update the native layer tree
	 */
	public function invalidateNativeLayer():Void
	{
		_needsNativeLayerUpdate = true;
		var htmlDocument:HTMLDocument = cast(layerRenderer.rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidateNativeLayerTree();
	}
	
	/**
	 * attachement for graphics context
	 * consist in attaching the native layer
	 * to the native display list
	 */
	public function attach():Void
	{
		doAttach();
		
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].attach();
		}
	}
	
	/**
	 * when detached, the graphics context
	 * detach its native layer from
	 * the native layer tree
	 */
	public function detach():Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].detach();
		}
		
		doDetach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE GRAPHICS CONTEXT TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually attach the native layer
	 */
	private function doAttach():Void
	{
		graphics.attach(this);
	}
	
	/**
	 * Actually detach the native layer
	 */
	private function doDetach():Void
	{
		graphics.detach(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeLayer():NativeLayer
	{
		return graphics.nativeLayer;
	}
	
}