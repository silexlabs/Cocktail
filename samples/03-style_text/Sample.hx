import js.Lib;
import js.Dom;

/**
 * CSS text styling
 */
class Sample
{
	private var title:HtmlDom;
	
	public function new()
	{
		var paragraph = addParagraph("Font family");
		paragraph.style.fontFamily = "arial";
		
		paragraph = addParagraph("Font size");
		paragraph.style.fontSize = "small";
		
		paragraph = addParagraph("Font size 2");
		paragraph.style.fontSize = "25px";
		
		paragraph = addParagraph("Font size 3");
		paragraph.style.fontSize = "3em";
		
		paragraph = addParagraph("Font color");
		paragraph.style.color = "orange";
		
		paragraph = addParagraph("Bold text");
		paragraph.style.fontWeight = "bold";
		
		paragraph = addParagraph("Italic text");
		paragraph.style.fontStyle = "italic";
		
		paragraph = addParagraph("letter spacing");
		paragraph.style.letterSpacing = "10px";
		
		paragraph = addParagraph("word spacing");
		paragraph.style.wordSpacing = "50px";
		
		paragraph = addParagraph("uppercase text");
		paragraph.style.textTransform = "uppercase";
	}
	
	private function addParagraph(text)
	{
		var text = Lib.document.createTextNode(text);
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(text);
		Lib.document.body.appendChild(paragraph);
		
		return paragraph;
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
