package src;
import js.Dom;
import js.Lib;
import haxe.Resource;

/**
 * Allow to browse css w3c test and display
 * them in both the native js of the browser
 * and with cocktail compiled in flash
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSTester 
{

	private static inline var COCKTAIL_SWF_URL:String = "cocktail_browser.swf?testUrl=";
	
	private static inline var FLASH_OBJECT_ID:String = "flash-test";
	
	private static inline var JS_FRAME_ID:String = "js-test";
	
	private static inline var TEST_DIV_ID:String = "test-list";
	
	static function main()
	{
		new CSSTester();
	}
	
	public function new() 
	{
		js.Lib.window.onload = function(e) {	
			initTestsBrowser();
		}
	}
	
	/**
	 * parse the list of available test and display
	 * it in html
	 */
	private function initTestsBrowser():Void
	{
		//xml list stored as embedded resource
		var testsList:String = Resource.getString("tests-list");
		
		var xml = Xml.parse(testsList).firstElement();
		var htmlTests = "";
		
		//parse test xml and build html from it
		for (chapter in xml.elements())
		{
			htmlTests += "<h2>" + chapter.get("name") + "</h2>";
			
			for (section in chapter.elements())
			{
				htmlTests += "<h3>" + section.get("name") + "</h3>";
				htmlTests += "<ul>";
				for (test in section.elements())
				{
					htmlTests += "<li><a href='" + test.get("url") + "'>" + test.get("name") + "</a>";
				}
				htmlTests += "</ul>";
			}
			
			htmlTests += "<ul>";
		}
		
		var testsBrowser = js.Lib.document.getElementById(TEST_DIV_ID);
		testsBrowser.innerHTML = htmlTests;
		
		
		//add click listener to all anchor to refresh js frame and flash object
		//when clicked
		var anchors = testsBrowser.getElementsByTagName("a");
		for (i in 0...anchors.length)
		{
			untyped anchors[i].addEventListener("click", onTestClick);
		}
		
	}
	
	/**
	 * When a test description is clicked, display
	 * the test in both an iframe for the js version
	 * and in an object tag for the cocktail flash
	 * version
	 */
	private function onTestClick(e:Event)
	{
		untyped e.preventDefault();
		
		var anchor:Anchor = cast(e.target);
		var jsFrame:Frame = cast(Lib.document.getElementById(JS_FRAME_ID));
		trace(jsFrame);
		jsFrame.src = anchor.href;
		
		
		var flashObject = Lib.document.getElementById(FLASH_OBJECT_ID);
		untyped flashObject.data = COCKTAIL_SWF_URL + StringTools.urlEncode(anchor.href);
		
		trace(jsFrame.src);
		
	}
	
}