package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.geom.GeomData;
import cocktail.viewport.Viewport;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InitialBlockRenderer extends BlockBoxRenderer
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
		
		var viewport:Viewport = new Viewport();
		var width:Float = viewport.width;
		var height:Float = viewport.height;
		
		_bounds.width = width;
		_bounds.height = height;
	}
	
}