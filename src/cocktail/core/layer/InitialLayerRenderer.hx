package cocktail.core.layer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;

/**
 * This a special LayerRenderer used as the root of the 
 * LayerRenderer tree. It is similar to the InitialBlockRenderer
 * from the ElementRenderer tree
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialLayerRenderer extends LayerRenderer
{
	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
		
		//As this is the root of the LayerRenderer, it attaches
		//itself as it has no parents
		attach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The initial LayerRenderer always creates the GraphicsContext
	 * at the root of the GraphicsContext tree
	 */
	override private function attachGraphicsContext():Void
	{
		//TODO 1 : should use Platform class
		#if macro
		#elseif (flash9 || nme)
		var initialNativeLayer:NativeElement = flash.Lib.current;
		graphicsContext = new GraphicsContext(this, initialNativeLayer);
		#end
		hasOwnGraphicsContext = true;
	}
	
	/**
	 * The initial LayerRenderer always dispose of its GraphicsContext
	 */
	override private function detachGraphicsContext():Void 
	{
		graphicsContext.dispose();
		graphicsContext = null;
		hasOwnGraphicsContext = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Always establishes a new graphic context
	 */
	override private function establishesNewGraphicsContext():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE LAYER TREE METHODS
	////////////////////////////////	
	
	/**
	 * The initial layer renderer always establishes
	 * the roor stacking context
	 */
	override private function establishesNewStackingContext():Bool
	{
		return true;
	}
	
	
}