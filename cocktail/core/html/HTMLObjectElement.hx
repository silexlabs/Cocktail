/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.dom.Attr;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.core.renderer.ObjectRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.plugin.Plugin;
import cocktail.plugin.swf.SWFPlugin;
import cocktail.core.renderer.ImageRenderer;
import cocktail.core.parser.ParserData;
import cocktail.port.Bindings;

/**
 * The object element can represent an external resource,
 * which, depending on the type of the resource,
 * will either be treated as an image, as a nested browsing
 * context, or as an external resource to be processed by a plugin.
 * 
 * TODO 1 IMPORTANT : for now only support embedding of flash movies, which are hard-code. Should
 * be able to display any plugin as well as regular picture like .jpg.
 * There is currently no easy way to add a third-party plugin
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLObjectElement extends EmbeddedElement
{

	//the intrinsic dimensions of an object tag, they are always the same and do not
	//depend on the displayed content
	
	private static inline var HTML_OBJECT_INTRISIC_WIDTH:Float = 300;
	
	private static inline var HTML_OBJECT_INTRINSIC_HEIGHT:Float = 150;
	
	/**
	 * Extension of a flash movie file
	 */
	private static inline var SWF_FILE_EXTENSION:String = ".swf";
	
	/**
	 * MIME type for flash movie
	 */
	private static inline var SWF_FILE_MIME_TYPE:String = "application/x-shockwave-flash";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The data attribute specifies the address of the resource.
	 */
	public var data(get_data, set_data):String;
	
	/**
	 * Specifies the mime-type of the resource
	 */
	public var type(get_type, set_type):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A reference to the plugin instantiated
	 * by this HTMLElement. It might be null,
	 * if the resource is a native one, like
	 * a picture or if not enough data are
	 * provided to determine which plugin
	 * to instantiate
	 */
	public var plugin(default, null):Plugin;
	
	/**
	 * A flag determining wheter the plugin is
	 * ready to be used. The plugin, after
	 * being instantiate call a callback to
	 * signal that it is ready to be used
	 */
	private var _pluginReady:Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_OBJECT_TAG_NAME);
		
		_pluginReady = false;
		intrinsicHeight = HTML_OBJECT_INTRINSIC_HEIGHT;
		intrinsicWidth = HTML_OBJECT_INTRISIC_WIDTH;
		intrinsicRatio = intrinsicWidth / intrinsicHeight;
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
		else if (name == HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME)
		{
			type = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden, as when attached, the plugin might need to
	 * be instantiated.
	 * 
	 * Plugins instantiated via an object tag are considered
	 * visual and are only instantiated if the object
	 * element is supposed to be rendered
	 */
	override public function attach(recursive:Bool):Void
	{
		super.attach(recursive);
		
		//check that the object tag should be rendered.
		//Don't check if element renderer is not null, as
		//the element renderer for this is only created when
		//the plugin is ready
		if (isRendered() == true)
		{
			createPlugin();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC DOM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * overriden as when aded to the DOM,
	 * if a data attribute is given, the resource
	 * is fetched
	 */
	override private function addedToDOM():Void
	{
		super.addedToDOM();
		
		if (data != null)
		{
			//for now only SWF files are supported
			if (data.indexOf(SWF_FILE_EXTENSION) != -1)
			{
				//start loading the resource, the resource
				//need to be completely loaded before
				//the plugin is instantiated
				_ownerHTMLDocument.resourceManager.getBinaryResource(data);
			}
		}
	}
	
	
	/**
	 * Overriden as when removed from DOM, the plugin
	 * might need to be destroyed.
	 * 
	 * If the plugin is only removed from rendering
	 * tree, for instance by setting its 'display' style
	 * to 'none', it is not deleted as it is assumed
	 * that it might be shown again
	 */
	override private function removedFromDOM():Void
	{
		super.removedFromDOM();
		deletePlugin();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PLUGIN METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate a third-party
	 * plugin if necessary
	 */
	private function createPlugin():Void
	{
		//prevent re-instantiating a plugin
		if (plugin != null)
		{
			return;
		}
		
		//plugin can only be
		//created if the object tag is currently
		//attached to the DOM
		if (attachedToDOM == false)
		{
			return;
		}
		
		//an url for the resource must be provided
		if (data != null)
		{
			//check that the url contain swf file or that data type
			//is swf MIME type, for now
			//this is the only supported type
			if (data.indexOf(SWF_FILE_EXTENSION) != -1 || getAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME) == SWF_FILE_MIME_TYPE)
			{
				//retrieve the resource the plugin will use
				var resource:NativeHttp = _ownerHTMLDocument.resourceManager.getBinaryResource(data);
				
				//if it couldn't be loaded, don't create the plugin
				if (resource.error == true)
				{
					return;
				}
				//if the resource is not yet loaded, 
				//wait for its load end
				if (resource.complete == false)
				{
					resource.addEventListener(EventConstants.LOAD, onPluginResourceLoaded);
					return;
				}
				
				var params:Map<String, String> = new Map<String, String>();
				
				//retrive all the name/value of the child param tags
				var length:Int = childNodes.length;
				for (i in 0...length)
				{
					var child:HTMLElement = cast(childNodes[i]);
					if (child.tagName == HTMLConstants.HTML_PARAM_TAG_NAME)
					{
						var name:String = child.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME);
						var value:String = child.getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
						
						if (name != null && value != null)
						{
							params.set(name, value);
						}
					}
				}
				
				//retrive all the attributes of this HTMLElement
				var elementAttributes:Map<String, String> = new Map<String, String>();
				for (i in 0...attributes.length)
				{
					var attr:Attr = attributes.item(i);
					elementAttributes.set(attr.name, attr.value);
				}
				
				//instantiate the plugin, for now hard-coded SWF plugin
				plugin = new SWFPlugin(this, elementAttributes, params, onLoadComplete, onLoadError);
			}
		}
	}
	
	/**
	 * Dispose of the plugin
	 * 
	 * TODO 2:  for now, only deleted
	 * when node removed from DOM, should
	 * add more conditions, like for instance
	 * change of data attribute value
	 */
	private function deletePlugin():Void
	{	
		if (plugin != null)
		{
			_pluginReady = false;
			plugin.dispose();
			plugin = null;
		}
	}
	
	/**
	 * called when the resource necessary
	 * to instantiate the plugin was loaded
	 */
	private function onPluginResourceLoaded(e:Event):Void
	{
		e.target.removeEventListener(EventConstants.LOAD, onPluginResourceLoaded);
		//try to create the plugin now that the resource is ready
		createPlugin();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate an object specific renderer, if the plugin
	 * is ready to be used
	 * 
	 * TODO 2 : should display fallback content if plugin
	 * not ready
	 */
	override private function createElementRenderer():Void
	{
		if (_pluginReady == true)
		{
			elementRenderer = new ObjectRenderer(this, coreStyle);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called by the plugin when it is ready
	 */
	private function onLoadComplete():Void
	{
		_pluginReady = true;
		
		//set the element renderer to be updated,
		//now that the plugin is ready, it can be created
		invalidateElementRenderer();
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(EventConstants.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	/**
	 * Called by the plugin when there
	 * was an error preventing it
	 * from working
	 */
	private function onLoadError():Void
	{
		_pluginReady = false;
		
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(EventConstants.ERROR, false, false, null, 0.0);
		dispatchEvent(errorEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_data(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME, value);
		
		//when calue of data changes, delete and create/recreate
		//plugin if necessary
		deletePlugin();
		createPlugin();
		
		return value;
	}
	
	private function get_data():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME);
	}
	
	private function set_type(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_type():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME);
	}
}
