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
	}
	
	override public function renderBackground():Array<NativeElement>
	{
		var viewport:Viewport = new Viewport();
		
		var width:Float = viewport.width;
		var height:Float = viewport.height;
		
		var viewportBounds:RectangleData = {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		}
		
		return _backgroundManager.render(viewportBounds, _domElement.style);
	}
	
}