package lib.hxtml;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;

import lib.hxtml.Browser;
import cocktail.Lib;
import cocktail.Dom;

/**
 * This class shows an implementation of an HTML renderer in Flash
 * It loads the page test.html and display it in Flash 
 */
class HxtmlConverter 
{
	
}
/**
 * Implementation of a IStyleProxy
 * This is where we apply the CSS Styles to our custom DOM 
 */
class StyleProxy implements lib.hxtml.IStyleProxy<HTMLElement>
{
	public function new(){}
	
	public function setDisplay(element:HTMLElement, value:String):Void{
		element.style.display = value;
	}
	public function setPosition (element:HTMLElement, value:String):Void{
		element.style.position = value;
	}
	public function setCssFloat(element:HTMLElement, value:String):Void{
		element.style.cssFloat = value;
	}
	public function setClear (element:HTMLElement, value:String):Void{
		element.style.clear = value;
	}
/*	public function setTransformOriginNum (element:Node, valueX:Int, unitX:String, valueY:Int, unitY:String, valueZ:Int, unitZ:String):Void{
		trace("TransformOrigin "+valueX+unitX);
		element.style.transformOrigin = valueX+unitX +" "+valueY+unitY +" "+valueZ+unitZ;
	}
	public function setTransformOriginKey (element:Node, value:String):Void{
		trace("TransformOrigin "+value);
		element.style.transformOrigin = value;
	}
*/
	public function setTransform (element:HTMLElement, value:String):Void{
		element.style.transform = value;
	}
	public function setTransformOrigin(element:HTMLElement, value:String):Void{
		element.style.transformOrigin = value;
	}
	public function setMarginLeftNum (element:HTMLElement, value:Float, unit:String):Void{
		element.style.marginLeft = value + unit;
	}
	public function setMarginLeftKey (element:HTMLElement, value:String):Void{
		element.style.marginLeft = value;
	}
	public function setMarginTopNum (element:HTMLElement, value:Float, unit:String):Void{
		element.style.marginTop = value + unit;
	}
	public function setMarginTopKey (element:HTMLElement, value:String):Void{
		element.style.marginTop = value;
	}
	public function setMarginRightNum (element:HTMLElement, value:Float, unit:String):Void{
		element.style.marginRight = value + unit;
	}
	public function setMarginRightKey (element:HTMLElement, value:String):Void{
		element.style.marginRight = value;
	}
	public function setMarginBottomNum (element:HTMLElement, value:Float, unit:String):Void{
		element.style.marginBottom = value + unit;
	}
	public function setMarginBottomKey (element:HTMLElement, value:String):Void{
		element.style.marginBottom = value;
	}
	public function setMarginBottomZero (element:HTMLElement):Void{
		element.style.marginBottom = "0";
	}
	public function setMarginLeftZero (element:HTMLElement):Void{
		element.style.marginLeft = "0";
	}
	public function setMarginTopZero (element:HTMLElement):Void{
		element.style.marginTop = "0";
	}
	public function setMarginRightZero (element:HTMLElement):Void{
		element.style.marginRight = "0";
	}

	public function setPaddingLeft (element:HTMLElement, value:Float, unit:String):Void{
		element.style.paddingLeft = value + unit;
	}
	public function setPaddingTop (element:HTMLElement, value:Float, unit:String):Void{
		element.style.paddingTop = value + unit;
	}
	public function setPaddingRight (element:HTMLElement, value:Float, unit:String):Void{
		element.style.paddingRight = value + unit;
	}
	public function setPaddingBottom (element:HTMLElement, value:Float, unit:String):Void{
		element.style.paddingBottom = value + unit;
	}
/*
	public function setBorderLeft (element:Node, value:Int, unit:String):Void{
		element.style.borderLeft = Std.string(value) + unit;
	}
	public function setBorderTop (element:Node, value:Int, unit:String):Void{
		element.style.borderTop = value + unit;
	}
	public function setBorderRight (element:Node, value:Int, unit:String):Void{
		element.style.borderRight = value + unit;
	}
	public function setBorderBottom (element:Node, value:Int, unit:String):Void{
		element.style.borderBottom = value + unit;
	}

	public function setBorderLeftColor (element:Node, value:String):Void{
	}
	public function setBorderTopColor (element:Node, value:String):Void{
	}
	public function setBorderRightColor (element:Node, value:String):Void{
	}
	public function setBorderBottomColor (element:Node, value:String):Void{
	}
*/	public function setWidth(element:HTMLElement, value:Float, unit:String):Void {

		element.style.width = value+unit; 
	}
	public function setWidthZero(element:HTMLElement):Void {

		element.style.width = "0"; 
	}
	public function setWidthKey(element:HTMLElement, value:String):Void {

		element.style.width = value; 
	}
	public function setHeight (element:HTMLElement, value:Float, unit:String):Void {
		element.style.height = value+unit; 
	}
	public function setHeightZero(element:HTMLElement):Void {

		element.style.height = "0"; 
	}
	public function setHeightKey(element:HTMLElement, value:String):Void {

		element.style.height = value; 
	}
	public function setMinWidth (element:HTMLElement, value:Float, unit:String):Void{
		element.style.minWidth = value+unit; 
	}
	public function setMinHeight (element:HTMLElement, value:Float, unit:String):Void{
		element.style.minHeight = value+unit; 
	}
	public function setMaxWidth (element:HTMLElement, value:Float, unit:String):Void{
		element.style.maxWidth = value+unit; 
	}
	public function setMaxHeight (element:HTMLElement, value:Float, unit:String):Void{
		element.style.maxHeight = value+unit; 
	}
	
	public function setMinWidthZero(element:HTMLElement):Void {
		element.style.minWidth = "0"; 
	}
	public function setMaxWidthZero (element:HTMLElement):Void {
		element.style.maxWidth = "0"; 
	}
	public function setMinHeightZero (element:HTMLElement):Void {
		element.style.minHeight = "0"; 
	}
	public function setMaxHeightZero (element:HTMLElement):Void {
		element.style.maxHeight = "0"; 
	}
	
	public function setMaxWidthKey (element:HTMLElement, value:String):Void {
		element.style.maxWidth = value; 
	}
	
	public function setMaxHeightKey (element:HTMLElement, value:String):Void {
		element.style.maxHeight = value; 
	}

	
	public function setTop (element:HTMLElement, value:Float, unit:String):Void{
		element.style.top = value+unit; 
	}
	public function setTopZero (element:HTMLElement):Void{
		element.style.top = "0"; 
	}
	public function setLeft (element:HTMLElement, value:Float, unit:String):Void{
		element.style.left = value+unit; 
	}
	public function setLeftZero (element:HTMLElement):Void{
		element.style.left = "0"; 
	}
	public function setBottom (element:HTMLElement, value:Float, unit:String):Void{
		element.style.bottom = value+unit; 
	}
	public function setBottomZero (element:HTMLElement):Void{
		element.style.bottom = "0"; 
	}
	public function setRight (element:HTMLElement, value:Float, unit:String):Void {
		element.style.right = value+unit; 
	}
	public function setRightZero (element:HTMLElement):Void{
		element.style.right = "0"; 
	}
	public function setTopKey (element:HTMLElement, value:String):Void{
		element.style.top = value; 
	}
	public function setLeftKey (element:HTMLElement, value:String):Void{
		element.style.left = value; 
	}
	public function setBottomKey (element:HTMLElement, value:String):Void{
		element.style.bottom = value; 
	}
	public function setRightKey (element:HTMLElement, value:String):Void{
		element.style.right = value; 
	}
	public function setBgColorHex (element:HTMLElement, value:String):Void {
		element.style.backgroundColor = "#" + Std.string(value);
	}
	public function setBgColorRGBA (element:HTMLElement, value:String):Void{
		element.style.backgroundColor = "rgba("+value+")";
	}
	public function setBgColorRGB (element:HTMLElement, value:String):Void {
		element.style.backgroundColor = "rgb("+value+")";
	}
	public function setBgColorKey (element:HTMLElement, value:String):Void{
		element.style.backgroundColor = value;
	}
	public function setBgImage (element:HTMLElement, value:Array<String>):Void{
		// TODO 2 : check for space and do not add "
		if (value.length == 1) 
			//TODO 2 : hack to make it work for at least one background image
			element.style.backgroundImage = "url(" + value[0] + ")";
			//element.style.backgroundImage = "\"" + value.join("\"");
		else
			element.style.backgroundImage = "";
	}
	public function setBgAttachment (element:HTMLElement, value:String):Void{
//		element.style.backgroundAttachment = value;
	}
	public function setBgRepeat (element:HTMLElement, value:Array<String>):Void{
		element.style.backgroundRepeat = value.join(",");
	}
/*	public function setBgOrigin (element:Node, value:Array<String>):Void{
		element.style.backgroundOrigin = value;
	}
	public function setBgSize (element:Node, value:Array<String>):Void{
		element.style.backgroundSize = value;
	}
*/	public function setBgPos (element:HTMLElement, value:String):Void {
		element.style.backgroundPosition = value;
	}
	

/*	public function setBgClip (element:Node, value:Array<String>):Void{
		element.style.backgroundClip = value;
	}
*/
	public function setFontSizeNum (element:HTMLElement, value:Float, unit:String):Void {
		element.style.fontSize = value+unit;
	}
	public function setFontSizeKey (element:HTMLElement, value:String):Void{
		element.style.fontSize = value;
	}
	public function setFontWeightNum (element:HTMLElement, value:Int):Void{
		element.style.fontWeight = Std.string(value);
	}
	public function setFontWeightKey (element:HTMLElement, value:String):Void{
		element.style.fontWeight = value;
	}
	public function setFontStyle (element:HTMLElement, value:String):Void{
		element.style.fontStyle = value;
	}
	public function setFontFamily (element:HTMLElement, value:Array<String>):Void {
		if (value.length > 0) 
			element.style.fontFamily = value.join(",");
		else
			element.style.fontFamily = "";
	}
	public function setFontVariant (element:HTMLElement, value:String):Void{
		element.style.fontVariant = value;
	}
	public function setTextColorKey (element:HTMLElement, value:String):Void{
		element.style.color = value;
	}
	public function setTextColorNum (element:HTMLElement, value:Int):Void{
		element.style.color = "#" + Std.string(value);
	}
	public function setTextColorRGBA (element:HTMLElement, value:String):Void{
		element.style.color = "rgba("+value+")";
	}
	public function setTextColorRGB (element:HTMLElement, value:String):Void {
		element.style.color = "rgb("+value+")";
	}
	public function setTextDecoration (element:HTMLElement, value:String):Void{
//		element.style.textDecoration = value;
	}
	public function setLineHeightKey (element:HTMLElement, value:String):Void{
		element.style.lineHeight = value;
	}
	public function setLineHeightZero (element:HTMLElement):Void{
		element.style.lineHeight = "0";
	}
	public function setLineHeightNum (element:HTMLElement, value:Float, unit:String):Void{
		element.style.lineHeight = value+unit;
	}
	public function setTextTransform (element:HTMLElement, value:String):Void{
		element.style.textTransform = value;
	}
	public function setLetterSpacingNum (element:HTMLElement, value:Int, unit:String):Void{
		element.style.letterSpacing = value+unit;
	}
	public function setLetterSpacingKey (element:HTMLElement, value:String):Void{
		element.style.letterSpacing = value;
	}
	public function setWordSpacingNum (element:HTMLElement, value:Int, unit:String):Void{
		element.style.wordSpacing = value+unit;
	}
	public function setWordSpacingKey (element:HTMLElement, value:String):Void{
		element.style.wordSpacing = value;
	}
	public function setTextIndent (element:HTMLElement, value:Int, unit:String):Void{
		element.style.textIndent = value + unit;
	}
	public function setTextAlign (element:HTMLElement, value:String):Void{
		element.style.textAlign = value;
	}
	public function setVerticalAlignNum (element:HTMLElement, value:Int, unit:String):Void{
		element.style.verticalAlign = value+unit;
	}
	public function setVerticalAlignKey (element:HTMLElement, value:String):Void{
		element.style.verticalAlign = value;
	}
	public function setWhiteSpace (element:HTMLElement, value:String):Void{
		element.style.whiteSpace = value;
	}
	public function setZIndex (element:HTMLElement, value:String):Void{
		element.style.zIndex = value;
	}
	public function setOverflowX (element:HTMLElement, value:String):Void{
		element.style.overflowX = value;
	}
	public function setOverflowY (element:HTMLElement, value:String):Void{
		element.style.overflowY = value;
	}
	public function setTransitionDuration(element:HTMLElement, value:String):Void{
		element.style.transitionDuration = value; 
	}
	public function setTransitionDelay(element:HTMLElement, value:String):Void{
		element.style.transitionDelay = value; 
	}
	public function setTransitionProperty(element:HTMLElement, value:String):Void{
		element.style.transitionProperty = value; 
	}
	public function setTransitionTimingFunction(element:HTMLElement, value:String):Void{
		element.style.transitionTimingFunction = value; 
	}	
/*	
	public function setOpacity (element:Node, value:Int, unit:String):Void{
		element.style.opacity = value+unit;
	}
	public function setVisibility (element:Node, value:Int, unit:String):Void{
		element.style.visibility = value+unit;
	}

	public function setCursor (element:Node, value:Int, unit:String):Void{
		element.style.cursor = value+unit;
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
//		element.style.marginLeft = CocktailCSSConverter.getMarginStyleValue(value);
		element.style.marginLeft = value + unit;
	}
	public function setMarginTop (element:Node, value:Int, unit:String):Void{
		trace("setMarginTop "+value+unit);
		element.style.marginTop = value + unit;
	}
	public function setMarginRight (element:Node, value:Int, unit:String):Void{
		trace("setMarginRight "+value+unit);
		element.style.marginRight = value + unit;
	}
	public function setMarginBottom (element:Node, value:Int, unit:String):Void{
		trace("setMarginBottom "+value+unit);
		element.style.marginBottom = value + unit;
	}

	public function setPaddingLeft (element:Node, value:Int, unit:String):Void{
		trace("setPaddingLeft "+value+unit);
		element.style.paddingLeft = value + unit;
	}
	public function setPaddingTop (element:Node, value:Int, unit:String):Void{
		trace("setPaddingTop "+value+unit);
		element.style.paddingTop = value + unit;
	}
	public function setPaddingRight (element:Node, value:Int, unit:String):Void{
		trace("setPaddingRight "+value+unit);
		element.style.paddingRight = value + unit;
	}
	public function setPaddingBottom (element:Node, value:Int, unit:String):Void{
		trace("setPaddingBottom "+value+unit);
		element.style.paddingBottom = value + unit;
	}

	public function setBorderLeft (element:Node, value:Int, unit:String):Void{
		trace("setBorderLeft "+value+unit);
		//element.style.borderLeft = Std.string(value) + unit;
	}
	public function setBorderTop (element:Node, value:Int, unit:String):Void{
		trace("setBorderTop "+value+unit);
		//element.style.borderTop = value + unit;
	}
	public function setBorderRight (element:Node, value:Int, unit:String):Void{
		trace("setBorderRight "+value+unit);
		//element.style.borderRight = value + unit;
	}
	public function setBorderBottom (element:Node, value:Int, unit:String):Void{
		trace("setBorderBottom "+value+unit);
		//element.style.borderBottom = value + unit;
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
		//element.style.fontFamily = value.concat(", ");
	}
	public function setFontWeightNum (element:Node, value:Int):Void{
		element.style.fontWeight = Std.string(value);
	}
	public function setFontWeightKeyword (element:Node, value:String):Void{
		element.style.fontWeight = value;
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
	}
	public function setBgColorNum (element:Node, value:Int):Void{
		element.style.backgroundColor = Std.string(value); 
	}
	public function setBgImage (element:Node, value:String):Void{
		element.style.backgroundImage = value; 
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
		element.style.display = value;
	}
	public function setPosition (element:Node, value:String):Void{
		element.style.position = value;
	}
}
*/