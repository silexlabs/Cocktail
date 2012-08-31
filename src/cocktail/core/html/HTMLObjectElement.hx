/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.event.UIEvent;
import cocktail.core.renderer.ObjectRenderer;
import cocktail.port.NativeElement;
import cocktail.core.renderer.ImageRenderer;
import cocktail.core.resource.ImageLoader;
import cocktail.core.renderer.RendererData;

/**
 * The object element can represent an external resource,
 * which, depending on the type of the resource,
 * will either be treated as an image, as a nested browsing
 * context, or as an external resource to be processed by a plugin.
 * 
 * TODO 1 IMPORTANT : for now only support embedding of flash movies.
 * Eventually, when a ResourceManager is done, this class might be used
 * to display any type of embedded content
 * 
 * TODO 1 : this is pretty much the same code as HTMLImageElement for now, comments
 * have not been updated either
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLObjectElement extends EmbeddedElement
{

	//the intrinsic dimensions of an object tag, they are always the same and do not
	//depend on the displayed content
	
	private static inline var HTML_OBJECT_INTRISIC_WIDTH:Float = 300;
	
	private static inline var HTML_OBJECT_INTRINSIC_HEIGHT:Float = 150;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The data attribute specifies the address of the resource.
	 */
	public var data(get_data, set_data):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reponsible for loading pictures into a NativeElement. 
	 * Its NativeElement is used by this HTMLImageElement as an
	 * embedded asset
	 */
	private var _imageLoader:ImageLoader;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_imageLoader = new ImageLoader();
		super(HTMLConstants.HTML_OBJECT_TAG_NAME);
		intrinsicHeight = HTML_OBJECT_INTRINSIC_HEIGHT;
		intrinsicWidth = HTML_OBJECT_INTRISIC_WIDTH;
		intrinsicRatio = intrinsicWidth / intrinsicHeight;
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		embeddedAsset = _imageLoader.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_DATA_ATTRIBUTE_NAME)
		{
			data = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate an image specific renderer
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new ObjectRenderer(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the picture was successfuly loaded.
	 * Invalidate the Style and call the
	 * onLoad callback if provided.
	 * 
	 * @param	image the loaded picture stored as a nativeElement
	 */
	private function onLoadComplete(image:NativeElement):Void
	{
		invalidate(InvalidationReason.other);
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(UIEvent.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	/**
	 * Called when there was an error during loading.
	 * Call the error callback if provided
	 * 
	 * @param	message the error message
	 */
	private function onLoadError(message:String):Void
	{
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(UIEvent.ERROR, false, false, null, 0.0);
		dispatchEvent(errorEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 */
	private function set_data(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME, value);
		_imageLoader.load([value], onLoadComplete, onLoadError);
		return value;
	}
	
	private function get_data():String
	{
		return getAttribute(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME);
	}
	
}