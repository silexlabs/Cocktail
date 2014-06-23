/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.plugin;

import cocktail.event.Event;
import cocktail.core.graphics.GraphicsContext;
import cocktail.geom.GeomData;
import cocktail.core.html.HTMLElement;

/**
 * base class for third-party plugin, instantiated through
 * object or embed tag
 * 
 * note : this is a first draft of a plugin system, for now
 * only supports one hard-coded SWF plugin, to display
 * swf movie in flash and OpenFL. Eventually it will be possible
 * to embed custom plugin with cocktail instantiated via the
 * mime type parameter of the object tag.
 * This class is very likely to change and shouldn't be used
 * to yet to build plugins
 * 
 * @author Yannick DOMINGUEZ
 */
class Plugin
{
	/**
	 * The viewport where the content of the plugin
	 * should be displayed, relative to the window.
	 * It is computed by the instantiating object
	 * or mebed node
	 */
	public var viewport(default, null):RectangleVO;
	
	/**
	 * A callback provided by the instantiating class, 
	 * should be called when the plugin is ready
	 */
	private var _loadComplete:Void->Void;
	
	/**
	 * A callback provided by the instantiating class, 
	 * should be called when there was an error while
	 * initialising the plugin
	 */
	private var _loadError:Void->Void;
	
	/**
	 * Contains a reference to the node which instantiated
	 * this plugin
	 */
	private var _node:HTMLElement;
	
	/**
	 * Contain all the attributes of the instantiating
	 * object or embed node, as key/value pair where
	 * key is the name of the attribute
	 */
	private var _elementAttributes:Map<String, String>;
	
	/**
	 * When the instantiating node is an object tag,
	 * contain all the key/value par of the param
	 * tag which are its direct children
	 */
	private var _params:Map<String, String>;
	
	public function new(node:HTMLElement, elementAttributes:Map<String, String>, params:Map<String, String>,loadComplete:Void->Void, loadError:Void->Void) 
	{
		viewport = new RectangleVO();
		_node = node;
		_loadComplete = loadComplete;
		_loadError = loadError;
		_elementAttributes = elementAttributes;
		_params = params;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the viewport where the plugin
	 * should be displayed is updated
	 */
	public function updateViewport(x:Float, y:Float, width:Float, height:Float):Void
	{
		
	}
	
	/**
	 * Called before the plugin is destroyed to perform
	 * necessary clean-up
	 */
	public function dispose():Void
	{
		
	}
	
	/**
	 * The plugin must return wether it is a
	 * composited layer, meaning that it will need
	 * its own bitmap surface to be rendered.
	 * 
	 * Default is false to prevent creating too
	 * many bitmaps
	 */
	public function isCompositedPlugin():Bool
	{
		return false;
	}
	
	/**
	 * Provide an opportunity to the plugin to
	 * either paint on the graphics context associated
	 * with its instantiating node or to attach itself
	 * to the native display list of its target platform
	 * 
	 * @param	graphicsContext contains access to a painting
	 * surface and to a native layer for attachement to the 
	 * native display list
	 */
	public function attach(graphicsContext:GraphicsContext):Void
	{
		
	}
	
	/**
	 * Provde an opportunity for the plugin to detach itself
	 * from the native display or erase content it might have drawn
	 */
	public function detach(graphicsContext:GraphicsContext):Void
	{
		
	}
}
