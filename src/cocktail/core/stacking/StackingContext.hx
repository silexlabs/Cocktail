package cocktail.core.stacking;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.utils.FastNode;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StackingContext extends FastNode<StackingContext>
{

	public var layerRenderer(default, null):LayerRenderer;
	
	public function new(layerRenderer:LayerRenderer) 
	{
		super();
		this.layerRenderer = layerRenderer;
	}
	
	public function render():Void
	{
		layerRenderer.render();
		
		var child:StackingContext = firstChild;
		
		while (child != null)
		{
			child.render();
			child = child.nextSibling;
		}
	}
	
}