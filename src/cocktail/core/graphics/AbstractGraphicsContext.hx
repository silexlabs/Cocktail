/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.graphics;

import cocktail.core.geom.Matrix;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.dom.NodeBase;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitData;

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
 * the video being given in its own layer. With just one GraphicContext, the video would have need
 * to be painted onto it for each frame.
 * 
 * It also facilitates integration with native platform UI widget which can live on its own native
 * layer, being composited by the platform, instead of being painted onto a single bitmap.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractGraphicsContext extends NodeBase<AbstractGraphicsContext>
{
	/**
	 * A reference to a native layer
	 */
	public var nativeLayer(get_nativeLayer, null):NativeElement;
	
	/**
	 * A reference to a native bitmap data object of the 
	 * underlying platform
	 */
	public var nativeBitmapData(get_nativeBitmapData, null):NativeBitmapData;
	
	/**
	 * A reference to the LayerRenderer which created this GraphicsContext
	 */
	public var layerRenderer(default, null):LayerRenderer;
	
	/**
	 * Holds a list of all the child GraphicsContext ordered by z-index,
	 * from most negative to most positive. Ultimately, this is this array which
	 * is use to order the native layer of the target platform
	 */
	private var _orderedChildList:Array<AbstractGraphicsContext>;

	/**
	 * class constructor
	 * @param layerRenderer the LayerRenderer which instantiated this 
	 * GraphicsContext
	 * 
	 * @param	nativeLayer the reference to the nativeLayer can be passed
	 * as parameter, else it is instantiated in the constructor
	 */
	public function new(layerRenderer:LayerRenderer = null, nativeLayer:NativeElement = null)
	{
		super();
		this.layerRenderer = layerRenderer;
		
		_orderedChildList = new Array<AbstractGraphicsContext>();
	}
	
	/**
	 * Init the bitmap data with a given size
	 */
	public function initBitmapData(width:Int, height:Int):Void
	{
		//abstract
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Override to also update the ordered child list array
	 */ 
	override public function appendChild(newChild:AbstractGraphicsContext):AbstractGraphicsContext
	{
		super.appendChild(newChild);
	
		instertIntoOrderedChildList(newChild);
		
		return newChild;
	}
	
	override public function removeChild(oldChild:AbstractGraphicsContext):AbstractGraphicsContext
	{
		super.removeChild(oldChild);
		
		_orderedChildList.remove(oldChild);
		
		
		return oldChild;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * clean-up method, free memory used
	 * by graphics context
	 */
	public function dispose():Void
	{
		//abstract
	}
	
	/**
	 * Apply a transformation matrix to the layer
	 */
	public function transform(matrix:Matrix):Void
	{
		//abstract
	}
	
	/**
	 * Clears the bitmap data
	 */
	public function clear():Void
	{
		//abstract
	}
	
	/**
	 * Draw bitmap data onto the bitmap surface. Alpha is preserved 
	 * for transparent bitmap
	 * @param	bitmapData the source  bitmap data
	 * @param	matrix a transformation matrix to apply yo the bitmap data when drawing to 
	 * to the bitmap. Defaults to an identity matrix
	 * @param	sourceRect defines the zone from the source bitmap data that must be copied onto the 
	 * native graphic dom element. Takes the whole bitmap data by default
	 */
	public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix = null, sourceRect:RectangleData = null):Void
	{
		//abstract
	}
	
	/**
	 * fast pixel manipulation method used when no transformation is applied to the image
	 * @param	bitmapData the pixels to copy
	 * @param	sourceRect the area of the source bitmap data to use
	 * @param	destPoint the upper left corner of the rectangular aeaa where the new
	 * pixels are placed
	 */
	public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleData, destPoint:PointData):Void
	{
		//abstract
	}
	
	/**
	 * Fill a rect with the specified color
	 * @param rect the rectangle to fill
	 * @param color the rectangle's color
	 */
	public function fillRect(rect:RectangleData, color:ColorData):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Insert the new GraphicsContext based on its z-index (the z-index of the
	 * ElementRenderer creating the LayerRenderer which created the GraphicsContext)
	 */
	private function instertIntoOrderedChildList(newChild:AbstractGraphicsContext):Void
	{
		//get the index of the new child to insert
		var index:Int = getIndex(newChild.layerRenderer.rootElementRenderer);
		
		//flasg set to true once the child has found its index in the array
		var isInserted:Bool = false;
		
		//a new list will replace the current one
		var newOrderedChildList:Array<AbstractGraphicsContext> = new Array<AbstractGraphicsContext>();
		
		/**
		 * Loop in all the list to find the right
		 * index for the new child
		 */
		for (i in 0..._orderedChildList.length)
		{
			//the index of the current child
			var childIndex:Int = getIndex(_orderedChildList[i].layerRenderer.rootElementRenderer);
			
			//the new child is inserted before the first child with a 
			//z-index superior to its own
			if (index < childIndex && isInserted == false)
			{
				newOrderedChildList.push(newChild);
				isInserted = true;
			}
			
			newOrderedChildList.push(_orderedChildList[i]);
		}
		
		//here, the new child was not inserted yet, it might
		//either be the first element in the array or should be placed last
		if (isInserted == false)
		{
			newOrderedChildList.push(newChild);
		}
		
		_orderedChildList = newOrderedChildList;
	}
	
	/**
	 * Utils mehod returning the z-index of an ElementRenderer.
	 * If the ElementRenderer is not positioned, it always has
	 * a z-index of 0 and is inserted visually following document
	 * order
	 */
	private function getIndex(elementRenderer:ElementRenderer):Int
	{
		var index:Int = 0;
		
		if (elementRenderer.isPositioned() == true)
		{
			//TODO 1 : for some reason CoreStyle is null on InitialBlockRenderer at this point
			if (elementRenderer.coreStyle != null)
			{
				switch (elementRenderer.coreStyle.computedStyle.zIndex)
				{
					case ZIndex.integer(value):
						index = value;
						
					default:	
				}
			}
		}
		
		return index;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeBitmapData():NativeBitmapData
	{
		return null;
	}
	
	private function get_nativeLayer():NativeElement
	{
		return null;
	}
	
}