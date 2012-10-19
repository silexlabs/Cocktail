package cocktail.core.stacking;
import cocktail.core.layer.LayerRenderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StackingContext extends FastNode<StackingContext>
{

	public var layerRenderer(default, null):LayerRenderer;
	
	public function new(layerRenderer:LayerRenderer) 
	{
		this.layerRenderer = layerRenderer;
	}
	
}