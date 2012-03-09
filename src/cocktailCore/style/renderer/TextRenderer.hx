package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.textElement.TextElementData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextRenderer extends ElementRenderer
{

	private var _textToken:TextTokenValue;
	
	public function new(domElement:DOMElement, textToken:TextTokenValue) 
	{
		_textToken = textToken;
		
	
		
		super(domElement);
		
		_bounds.width = domElement.offsetWidth;
		_bounds.height = domElement.offsetHeight;

	}
	
	override public function render():Array<NativeElement>
	{
		var ret:Array<NativeElement> = [];
		#if (flash9 ||nme)
		_domElement.nativeElement.x = _bounds.x;
		_domElement.nativeElement.y = _bounds.y;
		#end
		
		ret.push(_domElement.nativeElement);
		
		return ret;
	}
	
	override public function isText():Bool
	{
		return true;
	}
	
	override public function isSpace():Bool
	{
		var isSpace:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.space:
				isSpace = true;
				
			default:
				isSpace = false;
				
		}
		
		return isSpace;
	}
	
}