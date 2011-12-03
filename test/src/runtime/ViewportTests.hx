/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package runtime;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import haxe.Log;

import cocktail.runtime.Viewport;


/**
 * Test the cross-platform runtime tests loading
 * @author lexa
 * @date	12-2011
 */
class ViewportTests 
{
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new ViewportTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	/**
	 * Test the viewport events
	 */
	public function testViewport()
	{
		var onViewportResizeAsync:Void->Void = Assert.createAsync(onViewportResize, 6000);
		var onViewportRotateAsync:Void->Void = Assert.createAsync(onViewportRotate, 6000);
		
		// create an object to access the application view port
		var viewport = new Viewport();
		
		// listen to document events
		viewport.onResize = onViewportResizeAsync;
		viewport.onOrientationChange = onViewportRotateAsync;
		
		// display a message while waiting for resize
		untyped document.body.innerHTML += 'Resize your window now !<br />';
		
		// (new haxe.Timer(5000)).run = Assert.createAsync(endTest,6000);
	}
	/**
	 * Called when the viewport has been resized
	 */
	private function onViewportResize():Void
	{
		Assert.isTrue(true);

		// display a message while waiting for rotation
		untyped document.body.innerHTML += 'Rotate your device now !<br />';
		
		// create an object to access the application view port
		var viewport = new Viewport();
		Log.trace("Resize " + viewport.width + ", "+viewport.height);
	}
	/**
	 * Called when the viewport has been rotated
	 */
	private function onViewportRotate():Void
	{
		Assert.isTrue(true);
		
		// create an object to access the application view port
		var viewport = new Viewport();
		Log.trace("Rotate " + viewport.orientation);
	}
}
