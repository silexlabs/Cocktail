/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.plugin;

import cocktail.core.event.Event;
import cocktail.core.event.EventCallback;
import cocktail.port.GraphicsContext;
import cocktail.core.geom.GeomData;

/**
 * base class fro third-party plugin, instantiated through
 * object or embed tag
 * 
 * note : this is a first draft of a plugin system, for now
 * only supports one hard-coded SWF plugin, to display
 * swf movie in flash and NME. Eventually it will be possible
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
	public var viewport(get_viewport, set_viewport):RectangleVO;
	
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
	 * Contain all the attributes of the instantiating
	 * object or embed node, as key/value pair where
	 * key is the name of the attribute
	 */
	private var _elementAttributes:Hash<String>;
	
	/**
	 * When the instantiating node is an object tag,
	 * contain all the key/value par of the param
	 * tag which are its direct children
	 */
	private var _params:Hash<String>;
	
	public function new(elementAttributes:Hash<String>, params:Hash<String>,loadComplete:Void->Void, loadError:Void->Void) 
	{
		viewport = new RectangleVO(0.0, 0.0, 0.0, 0.0);
		_loadComplete = loadComplete;
		_loadError = loadError;
		_elementAttributes = elementAttributes;
		_params = params;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called before the plugin is destroyed to perform
	 * necessary clean-up
	 */
	public function dispose():Void
	{
		
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_viewport():RectangleVO
	{
		return viewport;
	}
	
	private function set_viewport(value:RectangleVO):RectangleVO
	{
		return viewport = value;
	}
	
}