package cocktail.core.renderer;
import cocktail.core.NativeElement;
import cocktail.core.CoreStyle;
import haxe.Log;

/**
 * TODO : disambiguate InlineBoxRenderer and InlineBox generated
 * by the InlineFormatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{

	public function new(style:CoreStyle) 
	{
		super(style);
	}
	
	override public function render():Array<NativeElement>
	{
		return renderBackground();
	}
}