package cocktailCore.dom;
import cocktail.nativeElement.NativeElementManager;
import cocktail.viewport.Viewport;
import cocktailCore.focus.FocusManager;
import cocktailCore.style.BodyStyle;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class HTMLBodyElement extends HTMLElement
{
	/**
	 * A reference to the view port used to listen for
	 * resize events
	 */
	private var _viewPort:Viewport;
	
	/**
	 * class constructor. Retrieve the root of the
	 * runtime and set it as this DOMElement's
	 * NativeElement
	 */
	public function new() 
	{
		_nativeElement = NativeElementManager.getRoot();
		super();
	}
	
	/**
	 * Instantiate a Style specific to this
	 * DOMElement
	 */
	override private function initStyle():Void
	{
		_style = new BodyStyle(this);
		
		//instantiate the view port and listen
		//for resize on it
		_viewPort = new Viewport();
		_viewPort.onResize = onViewPortResize;
	}
	
	/**
	 * Overriden to set this as the reference
	 * to the BodyDOMElement of the focus manager,
	 * used to build the tab list tree
	 */
	override private function initFocus():Void
	{
		FocusManager.getInstance().bodyDOMElement = cast(this);
		super.initFocus();
	}
	
	/**
	 * When the view port is resized, insvalidate
	 * this BodyDOMElement to lay it out with
	 * the new view port dimensions
	 */
	private function onViewPortResize():Void
	{
		_style.invalidate();
	}
	
	
}