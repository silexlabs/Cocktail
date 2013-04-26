/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.port.NativeAudio;

/**
 * An audio element represents a sound or audio stream.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLAudioElement extends HTMLMediaElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR & INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function new() 
	{
		super(HTMLConstants.HTML_AUDIO_TAG_NAME);
	}
	
	/**
	 * Instantiate an audio media manager
	 */
	override private function initNativeMedia():Void
	{
		nativeMedia = new NativeAudio();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * the audio element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
}