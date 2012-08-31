/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package viewport;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import haxe.Log;

import cocktail.viewport.Viewport;


/**
 * Test the cross-platform runtime tests loading
 * @author lexa
 * @date	12-2011
 */
class ViewportTests 
{
	private var _viewport : Viewport;
	
	#if flash9
	private var tf:flash.text.TextField;
	#end
	
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new ViewportTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		// create an object to access the application view port
		_viewport = new Viewport();
		
		#if flash9
		tf = new flash.text.TextField();
		tf.autoSize = flash.text.TextFieldAutoSize.LEFT;
		tf.multiline = true;
        flash.Lib.current.addChild(tf);
		#end
	}
	
	/**
	 * Test the viewport events
	 */
	public function testViewport()
	{
		// listen to document events
		_viewport.onResize = Assert.createAsync(onViewportResize, 6000);

		// display a message while waiting for resize
		#if flash9
        tf.htmlText += '<br>Resize your window now !<br>';
		#elseif js
		untyped document.body.innerHTML += 'Resize your window now !<br />';
		#end
		
		// (new haxe.Timer(5000)).run = Assert.createAsync(endTest,6000);
	}
	/**
	 * Called when the viewport has been resized
	 */
	private function onViewportResize():Void
	{
		Assert.isTrue(true);

		#if flash9
		tf.htmlText += '<br>Rotate your device now !<br>';
		#elseif js
		untyped document.body.innerHTML += 'Rotate your device now !<br />';
		#end
		
		// stop litening
		_viewport.onResize = null;

		// rotation test
		_viewport.onOrientationChange = Assert.createAsync(onViewportRotate, 6000);
		
		Log.trace("Resize " + _viewport.width + ", "+_viewport.height);
	}
	/**
	 * Called when the viewport has been rotated
	 */
	private function onViewportRotate():Void
	{
		Assert.isTrue(true);
		
		// stop litening
		_viewport.onOrientationChange = null;
		
		#if flash9
		tf.htmlText += "<br>Rotate " + _viewport.orientation;
		#elseif js
		untyped document.body.innerHTML += "Rotate " + _viewport.orientation;
		#end
	}
}
