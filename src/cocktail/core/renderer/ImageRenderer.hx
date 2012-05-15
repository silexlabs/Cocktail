package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ImageRenderer extends EmbeddedBoxRenderer
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : opacity doesn't work on embedded asset
	//TODO : enable smoothing
	override private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		var htmlImageElement:HTMLImageElement = cast(_node);
		
		graphicContext.addChild(htmlImageElement.embeddedAsset);
	
		htmlImageElement.embeddedAsset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		htmlImageElement.embeddedAsset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;

		htmlImageElement.embeddedAsset.width = _coreStyle.computedStyle.width;
		htmlImageElement.embeddedAsset.height = _coreStyle.computedStyle.height;
		
		
	}
	
}