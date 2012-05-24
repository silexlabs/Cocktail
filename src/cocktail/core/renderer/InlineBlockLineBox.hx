package cocktail.core.renderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InlineBlockLineBox extends EmbeddedLineBox
{

	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	override private function get_leadedAscent():Float 
	{
		return bounds.height + _elementRenderer.coreStyle.computedStyle.marginTop + _elementRenderer.coreStyle.computedStyle.marginBottom;
	}
	
}