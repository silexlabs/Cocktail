
/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

import js.Browser;
import js.html.InputElement;
import js.html.HtmlElement;

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
        var playBtn:InputElement = cast Browser.document.querySelector("input[type=button][value=play]");
        var time:HtmlElement = cast Browser.document.getElementsByClassName("time")[0];
        var track:HtmlElement = cast Browser.document.getElementsByClassName("track")[0];

        //play pause
        playBtn.onclick = function(e) {
            if (playBtn.value == "play") {
                playBtn.value = "pause";
                video.play();
            }
            else {
                playBtn.value = "play";
                video.pause();
            }
        }

        //update play time needle
        video.addEventListener("timeupdate", function(e) {
            time.style.width = Std.string((video.currentTime / video.duration) * 100) + "%";
        });

        //jump to time 
        track.onclick = function(e) {
            video.currentTime = ((e.clientX - track.offsetLeft) / track.clientWidth) * video.duration;
        }
    }
}
