package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import flash.text.TextField;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextInputRenderer extends EmbeddedBoxRenderer
{

	private var _nativeTextField:TextField;
	
	public function new(node:Node) 
	{
		super(node);
		
		_nativeTextField = new TextField();
		
	}
	
	override private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		_nativeTextField.text = "bim";
		graphicContext.addChild(_nativeTextField);
		
	}
	
}