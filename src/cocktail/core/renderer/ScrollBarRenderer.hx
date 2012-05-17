package cocktail.core.renderer;
import cocktail.core.dom.Node;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ScrollBarRenderer extends BlockBoxRenderer
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	override public function isScrollBar():Bool
	{
		return true;
	}
	
}