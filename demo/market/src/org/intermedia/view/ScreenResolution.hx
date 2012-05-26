package org.intermedia.view;

import js.Lib;

/**
 * ...
 * @author Raphael Harmel
 */

enum ScreenResolutionSize
{
	small;
	normal;
	large;
}

class ScreenResolution
{
	public var size:ScreenResolutionSize;
	
	/**
	 * constructor
	 * 
	 */
	public function new()
	{
		// As a reference, here are the typical resolutions defined for Android
		//xlarge screens are at least 960dp x 720dp
		//large screens are at least 640dp x 480dp
		//normal screens are at least 470dp x 320dp
		//small screens are at least 426dp x 320dp
		
		if (Lib.window.innerWidth < 400) size = small;
		else if (Lib.window.innerWidth < 600) size = normal;
		else size = large;
	}
}