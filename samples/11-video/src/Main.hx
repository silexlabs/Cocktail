
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
        var buffer:HtmlElement = cast Browser.document.getElementsByClassName("buffer")[0];

        var player:HtmlElement = cast Browser.document.getElementsByClassName("player")[0];
        var muteBtn:InputElement = cast Browser.document.getElementsByClassName("mute")[0];
        var fullscreenBtn:InputElement = cast Browser.document.getElementsByClassName("full")[0];

        //play/pause
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

        //mute/unmute
        muteBtn.onclick = function(e) {
            if (muteBtn.value == "mute") {
                muteBtn.value = "unmute";
                video.muted = true;
            }
            else {
                muteBtn.value = "mute";
                video.muted = false;
            }
        }

        //update play time needle
        video.addEventListener("timeupdate", function(e) {
            time.style.width = Std.string((video.currentTime / video.duration) * 100) + "%";
        });

        //set at start in case where video is already in cache
        buffer.style.width = Std.string((video.buffered.end(0) / video.duration) * 100) + "%";

        //update buffering progress
        video.addEventListener("progress", function(e) {
            buffer.style.width = Std.string((video.buffered.end(0) / video.duration) * 100) + "%";
        });

        //jump to time 
        track.onclick = function(e) {
            video.currentTime = ((e.clientX - track.offsetLeft) / track.clientWidth) * video.duration;
        }

        //toggle fullscreen
        //note : for fullscreen to work in flash, the swf need to embedded with the
        //"allowFullScreen" param set to true
        fullscreenBtn.onclick = function(e) {
            if (fullscreenBtn.value == "full") {
                fullscreenBtn.value = "small";
#if js
                    //for Haxe JS API need this extra param, didn't find any
                    //doc about it
                    player.requestFullScreen(0);
#else
                    player.requestFullScreen();
#end
            }
            else {
                fullscreenBtn.value = "full";
                Browser.document.exitFullscreen();
            }
        }
    }
}
