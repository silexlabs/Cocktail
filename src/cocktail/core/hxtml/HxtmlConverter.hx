package cocktail.core.hxtml;

import cocktail.core.dom.Node;
import hxtml.Browser;
import cocktail.Lib;
import cocktail.Dom;

/**
 * This class shows an implementation of an HTML renderer in Flash
 * It loads the page test.html and display it in Flash 
 */
class HxtmlConverter 
{
	/**
	 * entry point for our test application
	 */
	static public function getNode(htmlString:String):Node 
	{
		// create an instance of our class to manage css styles
		var s = new StyleProxy();

		// the browser is the class used to parse the HTML/CSS with our custom methods
		var browser:Browser<Node>;

		// init the browser with our custom methods
		browser = new Browser<Node>(Lib.document.createElement, Lib.document.createTextNode, appendChild, setAttribute, invalidate, s);
		 
		// parse the html data
		try{
			browser.setHtml(htmlString);
		}catch(e:String){ 
			throw("Error parsing HTML in HXTML");
		}
		return browser.domRoot;
	}
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public static function appendChild(parent:Node, element:Node):Void
	{
		parent.appendChild(element);
	}
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public static function invalidate():Void
	{
	}
	public static function setAttribute(element:Node, a : String, v : String ):Void
	{
		cast(element, HtmlDom).setAttribute(a, v);
	}
}
/**
 * Implementation of a IStyleProxy
 * This is where we apply the CSS Styles to our custom DOM 
 */
class StyleProxy implements hxtml.IStyleProxy<Node>
{
	public function new(){}
	
	public function setDisplay(element:Node, value:String):Void{
		cast(element, HtmlDom).style.display = value;
	}
	public function setPosition (element:Node, value:String):Void{
		cast(element, HtmlDom).style.position = value;
	}
/*	public function setCssFloat(element:Node, value:String):Void{
		trace("cssFloat "+value);
		cast(element, HtmlDom).style.cssFloat = value;
	}
/*	public function setClear (element:Node, value:String):Void{
		trace("Clear "+value);
		cast(element, HtmlDom).style.clear = value;
	}
/*	public function setTransformOriginNum (element:Node, valueX:Int, unitX:String, valueY:Int, unitY:String, valueZ:Int, unitZ:String):Void{
		trace("TransformOrigin "+valueX+unitX);
		cast(element, HtmlDom).style.transformOrigin = valueX+unitX +" "+valueY+unitY +" "+valueZ+unitZ;
	}
	public function setTransformOriginKey (element:Node, value:String):Void{
		trace("TransformOrigin "+value);
		cast(element, HtmlDom).style.transformOrigin = value;
	}
	public function setTransform (element:Node, value:String):Void{
		cast(element, HtmlDom).style.transform = value;
	}
*/	public function setMarginLeft (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
//		cast(element, HtmlDom).style.marginLeft = CocktailCSSConverter.getMarginStyleValue(value);
		cast(element, HtmlDom).style.marginLeft = value + unit;
	}
	public function setMarginLeftIdent (element:Node, value:String):Void{
		// TODO: take unit into account
//		cast(element, HtmlDom).style.marginLeft = CocktailCSSConverter.getMarginStyleValue(value);
		cast(element, HtmlDom).style.marginLeft = value;
	}
	public function setMarginTop (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginTop = value + unit;
	}
	public function setMarginTopIdent (element:Node, value:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginTop = value;
	}
	public function setMarginRight (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginRight = value + unit;
	}
	public function setMarginRightIdent (element:Node, value:String):Void{
		// TODO: take unit into account
//		cast(element, HtmlDom).style.marginLeft = CocktailCSSConverter.getMarginStyleValue(value);
		cast(element, HtmlDom).style.marginRight = value;
	}
	public function setMarginBottom (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginBottom = value + unit;
	}
	public function setMarginBottomIdent (element:Node, value:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginBottom = value;
	}

	public function setPaddingLeft (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingLeft = value + unit;
	}
	public function setPaddingTop (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingTop = value + unit;
	}
	public function setPaddingRight (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingRight = value + unit;
	}
	public function setPaddingBottom (element:Node, value:Int, unit:String):Void{
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingBottom = value + unit;
	}
/*
	public function setBorderLeft (element:Node, value:Int, unit:String):Void{
		trace("setBorderLeft "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.borderLeft = Std.string(value) + unit;
	}
	public function setBorderTop (element:Node, value:Int, unit:String):Void{
		trace("setBorderTop "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.borderTop = value + unit;
	}
	public function setBorderRight (element:Node, value:Int, unit:String):Void{
		trace("setBorderRight "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.borderRight = value + unit;
	}
	public function setBorderBottom (element:Node, value:Int, unit:String):Void{
		trace("setBorderBottom "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.borderBottom = value + unit;
	}

	public function setBorderLeftColor (element:Node, value:String):Void{
	}
	public function setBorderTopColor (element:Node, value:String):Void{
	}
	public function setBorderRightColor (element:Node, value:String):Void{
	}
	public function setBorderBottomColor (element:Node, value:String):Void{
	}
*/	public function setWidth (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.width = value+unit; 
	}
	public function setHeight (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.height = value+unit; 
	}
/*	public function setMinWidth (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.minWidth = value+unit; 
	}
	public function setMinHeight (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.minHeight = value+unit; 
	}
	public function setMaxWidth (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.maxWidth = value+unit; 
	}
	public function setMaxHeight (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.maxHeight = value+unit; 
	}
*/	public function setTop (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.top = value+unit; 
	}
	public function setLeft (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.left = value+unit; 
	}
	public function setBottom (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.bottom = value+unit; 
	}
	public function setRight (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.right = value+unit; 
	}
	public function setTopKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.top = value; 
	}
	public function setLeftKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.left = value; 
	}
	public function setBottomKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.bottom = value; 
	}
	public function setRightKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.right = value; 
	}
	public function setBgColorNum (element:Node, value:Int):Void{
		cast(element, HtmlDom).style.backgroundColor = "#" + Std.string(value);
	}
	public function setBgColorKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.backgroundColor = value;
	}
	public function setBgImage (element:Node, value:Array<String>):Void{
		// TODO : check for space and do not add "
		if (value.length > 0) 
			cast(element, HtmlDom).style.backgroundImage = "\"" + value.join("\"");
		else
			cast(element, HtmlDom).style.backgroundImage = "";
	}
	public function setBgAttachment (element:Node, value:String):Void{
//		cast(element, HtmlDom).style.backgroundAttachment = value;
	}
	public function setBgRepeat (element:Node, value:Array<String>):Void{
		cast(element, HtmlDom).style.backgroundRepeat = value.join(",");
	}
/*	public function setBgOrigin (element:Node, value:Array<String>):Void{
		cast(element, HtmlDom).style.backgroundOrigin = value;
	}
	public function setBgSize (element:Node, value:Array<String>):Void{
		cast(element, HtmlDom).style.backgroundSize = value;
	}
*/	public function setBgPosXKey (element:Node, value:String):Void{
	}
	public function setBgPosYKey (element:Node, value:String):Void{
	}
	public function setBgPosYNum (element:Node, value:Int, unit:String):Void{
	}
	public function setBgPosXNum (element:Node, value:Int, unit:String):Void{
	}

/*	public function setBgClip (element:Node, value:Array<String>):Void{
		cast(element, HtmlDom).style.backgroundClip = value;
	}
*/
	public function setFontSizeNum (element:Node, value:Float, unit:String):Void{
		cast(element, HtmlDom).style.fontSize = value+unit;
	}
	public function setFontSizeKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.fontSize = value;
	}
	public function setFontWeightNum (element:Node, value:Int):Void{
		cast(element, HtmlDom).style.fontWeight = Std.string(value);
	}
	public function setFontWeightKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.fontWeight = value;
	}
	public function setFontStyle (element:Node, value:String):Void{
		cast(element, HtmlDom).style.fontStyle = value;
	}
	public function setFontFamily (element:Node, value:Array<String>):Void {
		if (value.length > 0) 
			cast(element, HtmlDom).style.fontFamily = value.join(",");
		else
			cast(element, HtmlDom).style.fontFamily = "";
	}
	public function setFontVariant (element:Node, value:String):Void{
		cast(element, HtmlDom).style.fontVariant = value;
	}
	public function setTextColorKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.color = value;
	}
	public function setTextColorNum (element:Node, value:Int):Void{
		cast(element, HtmlDom).style.color = "#" + Std.string(value);
	}
	public function setTextDecoration (element:Node, value:String):Void{
//		cast(element, HtmlDom).style.textDecoration = value;
	}
	public function setLineHeightKey (element:Node, value:String):Void{
		cast(element, HtmlDom).style.lineHeight = value;
	}
	public function setLineHeightNum (element:Node, value:Float, unit:String):Void{
		cast(element, HtmlDom).style.lineHeight = value+unit;
	}
	public function setTextTransform (element:Node, value:String):Void{
		cast(element, HtmlDom).style.textTransform = value;
	}
/*	public function setLetterSpacing (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.letterSpacing = value+unit;
	}
	public function setWordSpacing (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.wordSpacing = value+unit;
	}
	public function setWhiteSpace (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.whiteSpace = value+unit;
	}
	public function setTextAlign (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.textAlign = value+unit;
	}
	public function setTextIndent (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.textIndent = value+unit;
	}
	public function setVerticalAlign (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.verticalAlign = value+unit;
	}
	public function setOpacity (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.opacity = value+unit;
	}
	public function setVisibility (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.visibility = value+unit;
	}
	public function setOverflowX (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.overflowX = value+unit;
	}
	public function setOverflowY (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.overflowY = value+unit;
	}
	public function setCursor (element:Node, value:Int, unit:String):Void{
		cast(element, HtmlDom).style.cursor = value+unit;
	}
*/
}
/**
 * Implementation of a IStyleProxy
 * This is where we apply the CSS Styles to our custom DOM 
 */
/*class StyleProxy implements hxtml.IStyleProxy<Node>
{
	public function new(){}
	public function setMarginLeft (element:Node, value:Int, unit:String):Void{
		trace("setMarginLeft "+value+unit);
		// TODO: take unit into account
//		cast(element, HtmlDom).style.marginLeft = CocktailCSSConverter.getMarginStyleValue(value);
		cast(element, HtmlDom).style.marginLeft = value + unit;
	}
	public function setMarginTop (element:Node, value:Int, unit:String):Void{
		trace("setMarginTop "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginTop = value + unit;
	}
	public function setMarginRight (element:Node, value:Int, unit:String):Void{
		trace("setMarginRight "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginRight = value + unit;
	}
	public function setMarginBottom (element:Node, value:Int, unit:String):Void{
		trace("setMarginBottom "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.marginBottom = value + unit;
	}

	public function setPaddingLeft (element:Node, value:Int, unit:String):Void{
		trace("setPaddingLeft "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingLeft = value + unit;
	}
	public function setPaddingTop (element:Node, value:Int, unit:String):Void{
		trace("setPaddingTop "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingTop = value + unit;
	}
	public function setPaddingRight (element:Node, value:Int, unit:String):Void{
		trace("setPaddingRight "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingRight = value + unit;
	}
	public function setPaddingBottom (element:Node, value:Int, unit:String):Void{
		trace("setPaddingBottom "+value+unit);
		// TODO: take unit into account
		cast(element, HtmlDom).style.paddingBottom = value + unit;
	}

	public function setBorderLeft (element:Node, value:Int, unit:String):Void{
		trace("setBorderLeft "+value+unit);
		// TODO: take unit into account
		//cast(element, HtmlDom).style.borderLeft = Std.string(value) + unit;
	}
	public function setBorderTop (element:Node, value:Int, unit:String):Void{
		trace("setBorderTop "+value+unit);
		// TODO: take unit into account
		//cast(element, HtmlDom).style.borderTop = value + unit;
	}
	public function setBorderRight (element:Node, value:Int, unit:String):Void{
		trace("setBorderRight "+value+unit);
		// TODO: take unit into account
		//cast(element, HtmlDom).style.borderRight = value + unit;
	}
	public function setBorderBottom (element:Node, value:Int, unit:String):Void{
		trace("setBorderBottom "+value+unit);
		// TODO: take unit into account
		//cast(element, HtmlDom).style.borderBottom = value + unit;
	}

	public function setBorderLeftColor (element:Node, value:String):Void{
	}
	public function setBorderTopColor (element:Node, value:String):Void{
	}
	public function setBorderRightColor (element:Node, value:String):Void{
	}
	public function setBorderBottomColor (element:Node, value:String):Void{
	}
	
	// inherited
	public function setFontFamily (element:Node, value:Array<String>):Void{
		//cast(element, HtmlDom).style.fontFamily = value.concat(", ");
	}
	public function setFontWeightNum (element:Node, value:Int):Void{
		cast(element, HtmlDom).style.fontWeight = Std.string(value);
	}
	public function setFontWeightKeyword (element:Node, value:String):Void{
		cast(element, HtmlDom).style.fontWeight = value;
	}
	public function setFontStyle (element:Node, value:String):Void{
	}
	public function setFontSizeNum (element:Node, value:Float, unit:String):Void{
	}
	public function setFontSizeKeyword (element:Node, value:String):Void{
	}
	public function setFontVariant (element:Node, value:String):Void{
	}
	public function setTextColorKeyword (element:Node, value:String):Void{
	}
	public function setTextColorNum (element:Node, value:Int):Void{
	}
	public function setTextDecoration (element:Node, value:String):Void{
	}
	public function setTextTransform (element:Node, value:String):Void{
	}
	public function setLineHeightKeyword (element:Node, value:String):Void{
	}
	public function setLineHeightNum (element:Node, value:Float, unit:String):Void{
	}
	
	public function setBgColorKeyword (element:Node, value:String):Void{
		// TODO: handle transparent case
	}
	public function setBgColorNum (element:Node, value:Int):Void{
		cast(element, HtmlDom).style.backgroundColor = Std.string(value); 
	}
	public function setBgImage (element:Node, value:String):Void{
		cast(element, HtmlDom).style.backgroundImage = value; 
	}
	public function setBgAttachment (element:Node, value:String):Void{
	}
	public function setBgRepeat (element:Node, value:String):Void{
	}
	public function setBgPosXKeyword (element:Node, value:String):Void{
	}
	public function setBgPosYKeyword (element:Node, value:String):Void{
	}
	public function setBgPosYNum (element:Node, value:Int, unit:String):Void{
	}
	public function setBgPosXNum (element:Node, value:Int, unit:String):Void{
	}
	
	public function setWidth (element:Node, value:Int, unit:String):Void{
	}
	public function setHeight (element:Node, value:Int, unit:String):Void{
	}
	
	public function setDisplay (element:Node, value:String):Void{
		cast(element, HtmlDom).style.display = value;
	}
	public function setPosition (element:Node, value:String):Void{
		cast(element, HtmlDom).style.position = value;
	}
}
*/