package cocktail.core.layer;
import cocktail.core.renderer.ElementRenderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CompositingLayerRenderer extends LayerRenderer
{

	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	override private function establishesNewGraphicsContext():Bool
	{
		return true;
	}
	
}