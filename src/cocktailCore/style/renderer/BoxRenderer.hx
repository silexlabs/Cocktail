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
		var bg = _backgroundManager.render(_bounds, _domElement.style);
		
		for (i in 0...bg.length)
		{
			//TODO : don't do that here
			#if (flash9 || nme)
			bg[i].x = _bounds.x;
			bg[i].y = _bounds.y;
			#end
		}
	
		
		return bg;
	}
}