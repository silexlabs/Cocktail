package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextRenderer extends ElementRenderer
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	override public function render():Array<NativeElement>
	{
		var ret:Array<NativeElement> = [];
		#if flash9
		_domElement.nativeElement.x = _bounds.x;
		_domElement.nativeElement.y = _bounds.y;
		#end
		
		ret.push(_domElement.nativeElement);
		
		return ret;
	}
	
}