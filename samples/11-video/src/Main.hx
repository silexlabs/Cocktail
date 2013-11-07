
/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

import js.Browser;

/**
 * Showcases how to display a video in flash
 */
class Main
{
	static function main()
	{
		#if !js
		//init cocktail, and starts the load of the "index.html" file
		cocktail.api.Cocktail.boot();
		#end

		Browser.window.onload = function(e) new Main();
	}

    public function new()
    {
        var video:js.html.VideoElement = cast Browser.document.getElementsByTagName("video")[0];
        var playBtn = Browser.document.querySelector("input[type=button][value=play]");
        var pauseBtn = Browser.document.querySelector("input[type=button][value=pause]");
        var time = Browser.document.getElementsByClassName("time")[0];

        playBtn.onclick = function(e) {
            video.play();
        }

        pauseBtn.onclick = function(e) {
            video.pause();
        }

        video.ontimeupdate = function(e) {
            time.style.width = Std.string((video.currentTime / video.duration) * 100) + "px";
        }

    }
}
