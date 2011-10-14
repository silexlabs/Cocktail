package cocktail.style.formatter;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BlockFormattingContext extends FormattingContext
{

	public function new(domElement:DOMElement, previsouFormatingContext:FormattingContext) 
	{
		super(domElement, previsouFormatingContext);
	}
	
	override private function place(domElement:DOMElement):Void
	{
		super.place(domElement);
		
		startNewLine();
		
		_flowData.x = flowData.firstLineX;
						
		domElement.x = _flowData.x + domElement.style.computedStyle.marginLeft + domElement.style.computedStyle.paddingLeft;
		domElement.y = _flowData.y + _flowData.maxLineHeight + domElement.style.computedStyle.marginTop + domElement.style.computedStyle.paddingTop;
		
		_flowData.y += domElement.style.computedStyle.height + domElement.style.computedStyle.marginTop + 
		domElement.style.computedStyle.paddingTop + domElement.style.computedStyle.paddingBottom + domElement.style.computedStyle.marginBottom;
		
		
		_flowData.totalHeight = _flowData.y + _flowData.maxLineHeight ;
		_flowData.maxLineHeight = 0;
		
	}
	
	
	override public function beginNewFormattingContext(domElement:ContainerDOMElement):Bool
	{
		var ret:Bool = false;
		
		if (FormattingContext.childrenInline(domElement) == true)
		{
			ret = true;
		}
		
		/**switch domElement.style.computedStyle.display
		{
			case inlineBlock:
				ret = true;
			default:
				
		}*/
		
		
		return true;
	}
	
	
	
	override public function clearFloat(clear:ClearStyleValue):Void
	{
		switch (clear)
		{
			case none:
				
			case left:
				clearLeft();
			case right:
				clearRight();
			case both:	
				clearBoth();
		}
	}
	
	private function clearLeft():Void
	{
		
	}
	
	private function clearRight():Void
	{
		
	}
	
	private function clearBoth():Void
	{
		clearLeft();
		clearRight();
	}
	
	
	
	

	
}