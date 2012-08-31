import js.Lib;
import js.Dom;

/**
 * Loading and displaying a picture
 */
class Main
{
	private var title:HtmlDom;
	
	public function new()
	{
		var pic:Image = cast(Lib.document.createElement("img"));
		pic.onload = onPicLoaded;
		pic.onerror = onPicError;
		
		Lib.document.body.appendChild(pic);
		
		pic.src = "assets/cocktail.jpg";
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

}
