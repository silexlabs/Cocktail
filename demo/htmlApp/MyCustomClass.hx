package ;

import js.Lib;

/**
 * 
 * 
 * @author Thomas Fétiveau
 */
class MyCustomClass 
{
	public function new() 
	{
		var t = new haxe.Timer(2000);
		
		t.run = function () { if ( Lib.document.getElementById("blink").style.display == "none" ) Lib.document.getElementById("blink").style.display = "block"; else Lib.document.getElementById("blink").style.display = "none"; };
	}
}