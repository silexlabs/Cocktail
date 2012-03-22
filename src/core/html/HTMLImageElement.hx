package core.html;

import core.nativeElement.NativeElement;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.event.Event;
import core.ImageLoader;
import core.EmbeddedStyle;
import haxe.Log;
import core.html.EmbeddedElement;


/**
 * The IMG element embeds an image in the current document at
 * the location of the element's definition. The IMG element 
 * has no content; it is usually replaced inline by the image
 * designated by the src attribute, the exception being for 
 * left or right-aligned images that are "floated" out of line.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLImageElement extends EmbeddedElement
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
	public var naturalWidth(get_naturalWidth, never):Null<Int>;
	
	/**
	 * The instrinsic height of an embedded content. For example, for a video, the height
	 * in pixel of the video
	 */
	public var naturalHeight(get_naturalHeight, never):Null<Int>;
	
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
		//use the provided NativeElement if any
		_imageLoader = new ImageLoader();
		super();
	}
	
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _imageLoader.nativeElement;
	}
	
	//TODO : should only be for JS runtime, in flash, 
	//nativeElement should be used to draw hitRect for now
	override private function initNativeElement():Void
	{
		_nativeElement = _embeddedAsset;
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
		this._intrinsicHeight = _imageLoader.intrinsicHeight;
		this._intrinsicWidth = _imageLoader.intrinsicWidth;
		this._intrinsicRatio = _intrinsicHeight / _intrinsicRatio;
		
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
	
	private function get_src():String
	{
		return _src;
	}
	
	private function get_naturalHeight():Null<Int>
	{
		return _intrinsicHeight;
	}
	
	private function get_naturalWidth():Null<Int>
	{
		return _intrinsicWidth;
	}
	
}