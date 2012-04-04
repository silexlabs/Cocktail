package cocktail.core.renderer;
import cocktail.core.NativeElement;
import cocktail.core.style.AbstractCoreStyle;
import haxe.Log;

/**
 * TODO : disambiguate InlineBoxRenderer and InlineBox generated
 * by the InlineFormatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{

	public function new(style:AbstractCoreStyle) 
	{
		super(style);
	}
	
	override public function render():Array<NativeElement>
	{
		return renderBackground();
	}
}