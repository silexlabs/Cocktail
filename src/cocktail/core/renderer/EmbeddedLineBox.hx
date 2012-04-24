package cocktail.core.renderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class EmbeddedLineBox extends LineBox
{

	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
		
		_bounds.width = elementRenderer.bounds.width;
		_bounds.height = elementRenderer.bounds.height;
	}
	
	override private function get_leadedAscent():Float 
	{
		return _bounds.height;
	}
}