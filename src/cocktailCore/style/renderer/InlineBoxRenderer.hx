package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InlineBoxRenderer extends FlowBoxRenderer
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	override public function render():Array<NativeElement>
	{
		return renderBackground();
	}
}