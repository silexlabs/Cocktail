import js.Lib;
import js.Dom;

/**
 * DOM serialise/deserialize
 */
class Sample
{
	
	public function new()
	{
		Lib.document.body.innerHTML = "<h1 id='title' style='color:blue'>Inner HTML</h1><p>My page is built from HTML</p>";
		
		var title = Lib.document.getElementById("title");
		title.onclick = function(e) {
			title.style.color = "orange";
			
			var output = Lib.document.createElement("p");
			var text = Lib.document.createTextNode("this is the updated HTML : "+Lib.document.body.innerHTML);
			output.appendChild(text);
			Lib.document.body.appendChild(output);
			
		}
	}

	public static function main()
	{
		#if nme
			nme.Lib.create(function() { new Sample(); }, 1024, 768, 60, 0xffffff, (1 * nme.Lib.HARDWARE) | nme.Lib.RESIZABLE);
		#else
		     new Sample();
		#end
	}

}
