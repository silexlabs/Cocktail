package src;

import haxe.Http;
import js.Dom;
import js.Lib;
import haxe.Resource;

/**
 * Allow to display html/css tests in both the native js of the browser
 * and with cocktail compiled in flash. Tests can come from a pre-defined
 * lists loaded at startup or be inputed via a form
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSTester 
{
	private static inline var TESTS_LIST_URL:String = "Tests-list.xml";

	private static inline var COCKTAIL_SWF_URL:String = "cocktail_browser.swf?html=";
	
	private static inline var FLASH_OBJECT_ID:String = "flash-test";
	
	private static inline var JS_FRAME_ID:String = "js-test";
	
	private static inline var TEST_DIV_ID:String = "test-list";
	
	private static inline var HTML_INPUT_ID:String = "htmlInput";
	
	public static inline var HTML_FORM_ID:String = "htmlForm";
	
	static function main()
	{
		new CSSTester();
	}
	
	/**
	 * constructor, when the browser is ready,
	 * load the xml file containing the list of tests
	 */
	public function new() 
	{
		js.Lib.window.onload = function(e) {	
			var http = new Http(TESTS_LIST_URL);
			
			http.onData = function(e) {
				initTestsBrowser(e);
			}
			
			http.request(false);
		}
	}
	
	/**
	 * parse the list of available test and display
	 * it in html
	 */
	function initTestsBrowser(testsList:String):Void
	{
		//listen for html input form submission, display inputed html when happens
		var htmlForm = Lib.document.getElementById(HTML_FORM_ID);
		untyped htmlForm.addEventListener("submit", onHtmlFormSubmit);
		
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
	 * When the html form is submitted, display
	 * the inputed html
	 */
	function onHtmlFormSubmit(e:Event)
	{
		untyped e.preventDefault();
		
		var htmlInput:Textarea = cast(Lib.document.getElementById(HTML_INPUT_ID));
		updateHtml(htmlInput.value);
	}
	
	/**
	 * When a test description is clicked, load the 
	 * corresponding text and display it
	 */
	function onTestClick(e:Event)
	{
		untyped e.preventDefault();
		var anchor:Anchor = cast(e.target);
		
		//always use proxy to prevent cross-domain security error
		var http = new Http("proxy.php?url="+anchor.href);
		http.onData = function(e) {
			updateHtml(e);
		}
		
		http.request(false);
	}
	
	/**
	 * Update the displayed html in the js frame, the
	 * flash object and the html input
	 */
	function updateHtml(html:String)
	{
		var urlEncodedHtml = StringTools.urlEncode(html);
		
		var jsFrame:Frame = cast(Lib.document.getElementById(JS_FRAME_ID));
		
		//use data uri scheme to prevent loading the html multiple times, might 
		//not work in older browser
		jsFrame.src = "data:text/html,"+urlEncodedHtml;
	
		//for flash, html provided as flash vars
		var flashObject = Lib.document.getElementById(FLASH_OBJECT_ID);
		untyped flashObject.data = COCKTAIL_SWF_URL + urlEncodedHtml;
		
		var htmlInput:Textarea = cast(Lib.document.getElementById(HTML_INPUT_ID));
		htmlInput.value = html;
	}
	
}