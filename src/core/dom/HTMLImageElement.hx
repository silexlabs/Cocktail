package core.dom;
import core.nativeElement.NativeElement;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.event.Event;
import cocktailCore.resource.ImageLoader;
import cocktailCore.style.EmbeddedStyle;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class HTMLImageElement extends HTMLElement
{

	//////////////////////
	// CALLBACKS
	/////////////////////
	
	/**
	 * The callback called once a picture has been successfully
	 * loaded
	 */
	public var onLoad:Event->Void;
	
	/**
	 * The callback called when there was an error during loading
	 */
	public var onError:String->Void;

	//////////////////////
	// PRIVATE ATTRIBUTES
	/////////////////////
	
	/**
	 * The instrinsic width of an embedded content. For example, for a video, the width
	 * in pixel of the video
	 */
	private var _naturalWidth:Null<Int>;
	public var naturalWidth(get_naturalWidth, never):Null<Int>;
	
	/**
	 * The instrinsic height of an embedded content. For example, for a video, the height
	 * in pixel of the video
	 */
	private var _naturalHeight:Null<Int>;
	public var naturalHeight(get_naturalHeight, never):Null<Int>;
	
	private var _embeddedAsset:NativeElement;
	public var embeddedAsset(get_embeddedAsset, never):NativeElement;
	
	/**
	 * Set/get the height of the EmbeddedDOMElement.
	 */
	private var _height:Int;
	public var height(get_height, set_height):Int;
		
	/**
	 * Set/get the width of the EmbeddedDOMElement.
	 */
	private var _width:Int;
	public var width(get_width, set_width):Int;
	
	/**
	 * The URL of the loaded picture.
	 * Read-only
	 */
	private var _src:String;
	public var src(get_src, set_src):String;
	
	/**
	 * Reponsible for loading pictures into a NativeElement. 
	 * Its NativeElement is used by this ImageDOMElement
	 */
	private var _imageLoader:ImageLoader;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor. Instantiate the image loader
	 * and set its NativeElement as this ImageDOMElement's
	 * NativeElement
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//TODO : should be embedded asset ?
		_nativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.neutral);
		
		//use the provided NativeElement if any
		_imageLoader = new ImageLoader();
		_embeddedAsset = _imageLoader.nativeElement;
		super();
	}
	
	/**
	 * Override to instantiate an embedded DOMElement specific 
	 * style manager
	 */
	override private function initStyle():Void
	{
		this._style = new EmbeddedStyle(this);
	}

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 * @param	url the url of the picture to load
	 * @param	allowCache wheter the picture is allowed to be cached by the browser
	 */
	private function set_src(value:String):String
	{
		_src = value;
		_imageLoader.load([value], onLoadComplete, onLoadError, false);
		return _src;
	}
	
	/**
	 * Called when the picture was successfuly loaded.
	 * Invalidate the DOMElement and call the
	 * onLoad callback if provided.
	 * Store the instrinsic dimensions of the loaded asset
	 * 
	 * @param	image the loaded picture stored as a nativeElement
	 */
	private function onLoadComplete(image:NativeElement):Void
	{
		this._naturalHeight = _imageLoader.intrinsicHeight;
		this._naturalWidth = _imageLoader.intrinsicWidth;
		
		this._style.invalidate();
		
		//if provided, call the callback
		//with the ImageDOMElement
		if (onLoad != null)
		{
			var loadEvent:Event = new Event(Event.LOAD);
			onLoad(loadEvent);
		}
	}
	
	/**
	 * Called when there was an error during loading.
	 * Call the error callback if provided
	 * @param	message the error message
	 */
	private function onLoadError(message:String):Void
	{
		if (onError != null)
		{
			onError(message);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_embeddedAsset():NativeElement
	{
		return _embeddedAsset;
	}
	
	private function get_src():String
	{
		return _src;
	}
	
	private function get_naturalHeight():Null<Int>
	{
		return _naturalHeight;
	}
	
	private function get_naturalWidth():Null<Int>
	{
		return _naturalWidth;
	}
	
	private function set_width(value:Int):Int
	{
		return _width = value;
	}
	
	private function get_width():Int
	{
		return _width;
	}
	
	private function set_height(value:Int):Int
	{
		return _height = value;
	}
	
	private function get_height():Int
	{
		return _height;
	}
	
}