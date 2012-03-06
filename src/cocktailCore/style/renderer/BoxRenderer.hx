package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.background.BackgroundManager;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BoxRenderer extends ElementRenderer
{

	private var _backgroundManager:BackgroundManager;
	
	
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_backgroundManager = new BackgroundManager();
	}
	
	override public function render():Array<NativeElement>
	{
		return [];
	}	
	
	override public function renderBackground():Array<NativeElement>
	{
		return _backgroundManager.render(_bounds, _domElement.style);
	}
}