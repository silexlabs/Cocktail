package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AnonymousBlockBoxRenderer extends BlockBoxRenderer
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	override public function isAnonymousBlockBox():Bool
	{
		return true;
	}
	
	override public function establishesNewStackingContext():Bool
	{
		return false;
	}
	
	
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		
		//TODO 4 : check if works
	
		_parentNode.removeChild(this);
		
		return oldChild;
	}
	
	override public function isInlineLevel():Bool
	{
		return false;
	}
	
	
	
}