package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
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
		
		_bounds.width = domElement.offsetWidth;
		_bounds.height = domElement.offsetHeight;

	}
	
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		
		var embeddedDOMElement:EmbeddedDOMElement = cast(_domElement);
		ret.push(embeddedDOMElement.embeddedAsset);
		
		if (_domElement.style.position == absolute)
		{
			//Log.trace(_domElement.style.computedStyle.marginLeft);
			//Log.trace(_bounds.x);
			
		}
		
		#if (flash9 ||nme)
		embeddedDOMElement.embeddedAsset.x = _bounds.x + _domElement.style.computedStyle.paddingLeft + _domElement.style.computedStyle.marginLeft;
		embeddedDOMElement.embeddedAsset.y = _bounds.y + _domElement.style.computedStyle.paddingTop + _domElement.style.computedStyle.marginTop;
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