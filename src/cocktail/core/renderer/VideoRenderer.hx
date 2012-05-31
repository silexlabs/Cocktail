 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLVideoElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import flash.display.DisplayObjectContainer;

/**
 * 
 * TODO 1 : should override bounds to include controls
 * size if necessary
 * 
 * @author Yannick DOMINGUEZ
 */
class VideoRenderer extends EmbeddedBoxRenderer
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
//TODO 1 : doc
//TODO 1 : deal with video aspect ratio and letterboxing here ?
	override private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		var htmlVideoElement:HTMLVideoElement = cast(_node);
		trace(htmlVideoElement.embeddedAsset);
		#if (flash9 || nme)
		
		var containerGraphicContext:DisplayObjectContainer = cast(graphicContext);
		
		containerGraphicContext.addChild(htmlVideoElement.embeddedAsset);
		
		htmlVideoElement.embeddedAsset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft + relativeOffset.x;
		htmlVideoElement.embeddedAsset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop + relativeOffset.y;
		htmlVideoElement.embeddedAsset.alpha = computedStyle.opacity;
		htmlVideoElement.embeddedAsset.width = _coreStyle.computedStyle.width;
		htmlVideoElement.embeddedAsset.height = _coreStyle.computedStyle.height;
		#end
	}
	
}