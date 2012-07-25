package cocktail.core.layer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InitialLayerRenderer extends LayerRenderer
{

	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
		
		attach();
	}
	
	override private function attachGraphicsContext():Void
	{
		#if flash9
		var initialNativeLayer:NativeElement = flash.Lib.current;
		graphicsContext = new GraphicsContext(this, initialNativeLayer); 
		#end
		_hasOwnGraphicsContext = true;
	}
	
	override private function detachGraphicsContext():Void 
	{
		graphicsContext.dispose();
		graphicsContext = null;
		_hasOwnGraphicsContext = false;
	}
	
	override private function establishesNewGraphicsContext():Bool
	{
		return true;
	}
	
	
}