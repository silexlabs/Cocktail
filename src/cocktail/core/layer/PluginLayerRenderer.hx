package cocktail.core.layer;
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.renderer.ElementRenderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class PluginLayerRenderer extends CompositingLayerRenderer
{

	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	/**
	 * When attached, gives an opportunity to the
	 * plugin to attch itself to the display list
	 */
	override public function attach():Void
	{
		super.attach();
		var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
		htmlObjectElement.plugin.attach(graphicsContext);
	}
	
	/**
	 * When detached, gives an opportunity to
	 * the plugin to detach itself
	 */
	override public function detach():Void
	{
		if (hasOwnGraphicsContext == true)
		{
			var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
			htmlObjectElement.plugin.detach(graphicsContext);
		}
		super.detach();
	}
	
}