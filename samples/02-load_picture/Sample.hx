import js.Lib;
import js.Dom;

/**
 * Loading and displaying a picture
 */
class Sample
{
	private var title:HtmlDom;
	
	public function new()
	{
		title = Lib.document.createElement("h1");
		title.appendChild(Lib.document.createTextNode("My beautiful picture"));
		
		var pic:Image = cast(Lib.document.createElement("img"));
		pic.onload = onPicLoaded;
		pic.onerror = onPicError;
		
		Lib.document.body.appendChild(title);
		Lib.document.body.appendChild(pic);
		
		pic.src = "../assets/cocktail.jpg";
	}
	
	private function onPicLoaded(e:Event):Void
	{
		var picLoadedText = Lib.document.createTextNode("picture successfully loaded");
		
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(picLoadedText);
		
		Lib.document.body.appendChild(paragraph);
	}
	
	private function onPicError(e:Event):Void
	{
		var picErrorText = Lib.document.createTextNode("picture load error");
		
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(picErrorText);
		
		Lib.document.body.appendChild(paragraph);
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
