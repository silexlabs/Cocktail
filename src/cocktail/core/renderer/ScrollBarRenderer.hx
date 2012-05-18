package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.ScrollBar;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ScrollBarRenderer extends BlockBoxRenderer
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	override public function isScrollBar():Bool
	{
		return true;
	}
	
	/**
	 * TODO : seems a bit overkill but works to referesh the thumb size
	 */
	override public function layout(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		super.layout(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		
		var scrollBar:ScrollBar = cast(_node);
		scrollBar.updateThumbSize();
		
	}
	
}