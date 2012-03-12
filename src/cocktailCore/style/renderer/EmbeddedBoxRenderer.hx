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
		
		_bounds.width = domElement.style.computedStyle.width;
		_bounds.height = domElement.style.computedStyle.height;

	}
	
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		
		var embeddedDOMElement:EmbeddedDOMElement = cast(_domElement);
		ret.push(embeddedDOMElement.embeddedAsset);
		
		#if (flash9 ||nme)
		embeddedDOMElement.embeddedAsset.x = _bounds.x;
		embeddedDOMElement.embeddedAsset.y = _bounds.y;
		//TODO : should only take asset height
		embeddedDOMElement.embeddedAsset.width = _domElement.style.computedStyle.width;
		embeddedDOMElement.embeddedAsset.height = _domElement.style.computedStyle.height;
		
		#end
		
		//apply transformations
		//setNativeMatrix(_computedStyle.transform);
		
		//apply opacity and visibility
		//TODO : opacity doesn't work and should also be applied to background
		_domElement.style.setNativeOpacity(_domElement.style.computedStyle.opacity);
		_domElement.style.setNativeVisibility(_domElement.style.computedStyle.visibility);
		
		return ret;
	}
	
	
	
}