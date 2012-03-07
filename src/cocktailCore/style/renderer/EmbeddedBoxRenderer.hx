package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class EmbeddedBoxRenderer extends BoxRenderer
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);

	}
	
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		
		var embeddedDOMElement:EmbeddedDOMElement = cast(_domElement);
		ret.push(embeddedDOMElement.embeddedAsset);
		
		#if flash9
		embeddedDOMElement.embeddedAsset.x = _bounds.x;
		embeddedDOMElement.embeddedAsset.y = _bounds.y;
		embeddedDOMElement.embeddedAsset.width = _bounds.width;
		embeddedDOMElement.embeddedAsset.height = _bounds.height;
		
		#end
		
		//apply transformations
		//setNativeMatrix(_computedStyle.transform);
		
		//apply opacity and visibility
		_domElement.style.setNativeOpacity(_domElement.style.computedStyle.opacity);
		_domElement.style.setNativeVisibility(_domElement.style.computedStyle.visibility);
		
		return ret;
	}
	
	
	
}