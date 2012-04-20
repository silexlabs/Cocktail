package cocktail.core.renderer;
import cocktail.core.NativeElement;
import cocktail.core.style.CoreStyle;
import haxe.Log;

/**
 * TODO : disambiguate InlineBoxRenderer and InlineBox generated
 * by the InlineFormatting context
 * 
 * InlineBox should be its type, with sub class for container, text fragment and
 * embedded asset
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{

	public function new(style:CoreStyle) 
	{
		super(style);
	}
	
	//TODO : should call renderBackground from LayerRenderer instead, here create z-index issues
	override public function render():Array<NativeElement>
	{
		return renderBackground();
	}
}