package core.renderer;
import core.nativeElement.NativeElement;
import core.Style;
import haxe.Log;

/**
 * TODO : disambiguate InlineBoxRenderer and InlineBox generated
 * by the InlineFormatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{

	public function new(style:Style) 
	{
		super(style);
	}
	
	override public function render():Array<NativeElement>
	{
		return renderBackground();
	}
}