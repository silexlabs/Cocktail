package src;

import haxe.Http;
import js.Dom;
import js.Lib;
import haxe.Resource;
import js.JQuery;

/**
 * Allow to display html/css tests in both the native js of the browser
 * and with cocktail compiled in flash. Tests can come from a pre-defined
 * lists loaded at startup or be inputed via a code editor
 * 
 * The Ace code editor is used : http://ace.ajax.org/#nav=about
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSTester 
{
	private static inline var DEFAULT_TESTS_LIST_URL:String = "Tests-list.xml";
	
	private static inline var ALTERNATE_TESTS_LIST_URL_PARAMETER:String = "tests";

	private static inline var COCKTAIL_SWF_URL:String = "cocktail_browser.swf?html=";
	
	private static inline var FLASH_OBJECT_ID:String = "flash-test";
	
	private static inline var JS_FRAME_ID:String = "js-test";
	
	private static inline var TEST_DIV_ID:String = "test-list";
	
	private static inline var HTML_EDITOR_ID:String = "editor";
	
	private static inline var UPDATE_BUTTON_ID:String = "updateBtn";
	
	static function main()
	{
		new CSSTester();
	}
	
	public function new() 
	{
		js.Lib.window.onload = function(e) {	
			init();
		}
	}
	
	/**
	 * when the browser is ready,
	 * load the xml file containing the list of tests
	 */
	function init()
	{
		//when this button is clicked, the display is updated with the content
		//of the code editor
		var updateButton = Lib.document.getElementById(UPDATE_BUTTON_ID);
		untyped updateButton.addEventListener("click", onUpdate);
		
		//listen to window scroll to place some elements if needed
		untyped Lib.window.addEventListener("scroll", onWindowScroll);
		
		
		//tests url either use a default, or can use an alternate
		//file provided by query string parameter
		var testUrl = DEFAULT_TESTS_LIST_URL;
		
		var prmstr = Lib.window.location.search.substr(1);
		var prmarr = prmstr.split("&");
		for (i in 0...prmarr.length) {
			var tmparr = prmarr[i].split("=");
			if (tmparr[0] == ALTERNATE_TESTS_LIST_URL_PARAMETER)
			{
				testUrl = tmparr[1];
			}
		}
		
		var http = new Http(testUrl);
		
		http.onData = function(e) {
			initTestsBrowser(e);
		}
		
		http.request(false);
	}
	
	/**
	 * parse the list of available test and display
	 * it in html
	 */
	function initTestsBrowser(testsList:String):Void
	{
		var xml = Xml.parse(testsList).firstElement();
		var htmlTests = "";
		
		//parse test xml and build html from it
		for (chapter in xml.elements())
		{
			if (chapter.get("name") != null)
			{
				htmlTests += "<h3>" + chapter.get("name") + "</h3>";
			}
			
			
			for (section in chapter.elements())
			{
				if (section.get("name") != null)
				{
					htmlTests += "<h4>" + section.get("name") + "</h4>";
				}
				
				htmlTests += "<ul class='nav nav-tabs nav-stacked'>";
				for (test in section.elements())
				{
					if (test.get("description") != null)
					{
						htmlTests += "<li><a data-placement='right' rel='tooltip' href='" + test.get("url") +"' title='"+test.get("description") + "'>" + test.get("name") + "</a>";
					}
					else
					{
						htmlTests += "<li><a href='" + test.get("url") + "'>" + test.get("name") + "</a>";
					}
				}
				htmlTests += "</ul>";
			}
		}
		
		var testsBrowser = js.Lib.document.getElementById(TEST_DIV_ID);
		testsBrowser.innerHTML = htmlTests;
		
		//activate all tooltips
		untyped new JQuery('[rel=tooltip]').tooltip(); 
		
		//add click listener to all anchor to refresh js frame and flash object
		//when clicked
		var anchors = testsBrowser.getElementsByTagName("a");
		for (i in 0...anchors.length)
		{
			untyped anchors[i].addEventListener("click", onTestClick);
		}
		
	}
	
	/**
	 * When the window is scrolled past the header, 
	 * the js and flash frame are fixed sot that they
	 * always remain on screen
	 */
	function onWindowScroll(e:Event)
	{
		if (new JQuery(Lib.window).scrollTop() > new JQuery("header").innerHeight())
		{
			new JQuery("#main-container").addClass('fixed');
		}
		else
		{
			new JQuery("#main-container").removeClass('fixed');
		}
	}
	
	/**
	 * Called when the html must be updated from
	 * the code editor content
	 */
	function onUpdate(e:Event)
	{
		var editor:Dynamic = untyped ace.edit(HTML_EDITOR_ID);
		updateHtml(untyped editor.getValue());
		
		untyped new JQuery("#editorModal").modal("hide");
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
		var swfObject = new js.SWFObject(COCKTAIL_SWF_URL + urlEncodedHtml, FLASH_OBJECT_ID, 400, 400, "11", "#FFFFFF" );
		swfObject.addParam("wmode", "transparent");
		swfObject.write(FLASH_OBJECT_ID);
		
		//var flashObject = Lib.document.getElementById(FLASH_OBJECT_ID);
		//untyped flashObject.data = COCKTAIL_SWF_URL + urlEncodedHtml;
		
		//refresh code editor content
		var editor:Dynamic = untyped ace.edit(HTML_EDITOR_ID);
		editor.setValue(html);
	}
	
}