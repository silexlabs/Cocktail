package core.html;
import core.nativeElement.NativeElementManager;
import cocktail.viewport.Viewport;
import cocktailCore.focus.FocusManager;
import core.BodyStyle;

#if (flash9 || cpp || nme)
import port.flash_player.HTMLElement;

#elseif js
import port.browser.HTMLElement;

#end

/**
 * The HTML document body. This element is always present
 * in the DOM API, even if the tags are not present in the source document.
 * 
 * TODO : override in JS to listen to keyboard on document. Or use ownerDocument
 * or add keydown, keyup callbacks on HTMLDocument
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLBodyElement extends HTMLElement
{
	/**
	 * A reference to the view port used to listen for
	 * resize events
	 * 
	 * TODO : move to the Document ?
	 */
	private var _viewPort:Viewport;
	
	/**
	 * class constructor. Retrieve the root of the
	 * runtime and set it as this DOMElement's
	 * NativeElement
	 * 
	 * TODO : init keyboard with document in JS ?
	 */
	public function new() 
	{	
		//TODO : should be moved to Document
		FocusManager.getInstance().bodyElement = cast(this);
		super();
	}
	
	override private function initNativeElement():Void
	{
		_nativeElement = NativeElementManager.getRoot();
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
	 * When the view port is resized, insvalidate
	 * this BodyDOMElement to lay it out with
	 * the new view port dimensions
	 */
	private function onViewPortResize():Void
	{
		_style.invalidate();
	}
	
	
}