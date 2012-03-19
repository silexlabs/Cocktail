package cocktailCore.dom;

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
	public var onLoad:ImageDOMElement->Void;
	
	/**
	 * The callback called when there was an error during loading
	 */
	public var onError:String->Void;

	//////////////////////
	// PRIVATE ATTRIBUTES
	/////////////////////
	
	/**
	 * The URL of the loaded picture.
	 * Read-only
	 */
	private var _src:String;
	public var src(getSrc, never):String;
	
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
		_embeddedAsset = _imageLoader.nativeElement;
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.neutral));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 * @param	url the url of the picture to load
	 * @param	allowCache wheter the picture is allowed to be cached by the browser
	 */
	public function load(url:String, allowCache:Bool = true):Void
	{
		this._src = url;
		_imageLoader.load([url], onLoadComplete, onLoadError, allowCache);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
		this._intrinsicRatio = _imageLoader.intrinsicRatio;
		
		this._style.invalidate();
		
		//if provided, call the callback
		//with the ImageDOMElement
		if (onLoad != null)
		{
			onLoad(cast(this));
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
	
	private function getSrc():String
	{
		return this._src;
	}
	
}