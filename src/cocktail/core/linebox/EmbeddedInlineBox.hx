package cocktail.core.linebox;
import cocktail.core.renderer.ElementRenderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class EmbeddedInlineBox extends InlineBox
{

	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	override public function isEmbedded():Bool
	{
		return true;
	}
	
}