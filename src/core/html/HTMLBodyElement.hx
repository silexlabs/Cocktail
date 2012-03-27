package core.html;
import core.event.Event;
import core.nativeElement.NativeElementManager;
import cocktailCore.focus.FocusManager;
import core.BodyStyle;
import core.Window;

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
	 * the html tag name for the body
	 */
	private static inline var HTML_BODY_TAG_NAME:String = "body";
	
	/**
	 * A reference to the view port used to listen for
	 * resize events
	 * 
	 * TODO : move to the Document ?
	 */
	private var _window:Window;
	
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
		super(HTML_BODY_TAG_NAME);
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
		_window = new Window();
		_window.onResize = onWindowResize;
	}
	
	/**
	 * When the view port is resized, insvalidate
	 * this BodyDOMElement to lay it out with
	 * the new view port dimensions
	 */
	private function onWindowResize(event:Event):Void
	{
		_style.invalidate();
	}
	
	
}