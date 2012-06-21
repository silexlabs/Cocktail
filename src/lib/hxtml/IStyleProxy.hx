package lib.hxtml;

//TODO : add mmethod for property who can take a "0" length value, like width or height
interface IStyleProxy<DisplayObjectType>
{
	public function setDisplay(element:DisplayObjectType, value:String):Void;
	public function setPosition (element:DisplayObjectType, value:String):Void;
	public function setCssFloat(element:DisplayObjectType, value:String):Void;
	public function setClear (element:DisplayObjectType, value:String):Void;
/*	public function setTransformOriginNum (element:DisplayObjectType, valueX:Int, unitX:String, valueY:Int, unitY:String, valueZ:Int, unitZ:String):Void;
	public function setTransformOriginKey (element:DisplayObjectType, value:String):Void;
	public function setTransform (element:DisplayObjectType, value:String):Void;
	
	//TODO : rename setMarginLeftLength ? Add setMarginLeftPercent ?
*/	public function setMarginLeftNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMarginLeftKey (element:DisplayObjectType, value:String):Void;
	public function setMarginTopNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMarginTopKey (element:DisplayObjectType, value:String):Void;
	public function setMarginRightNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMarginRightKey (element:DisplayObjectType, value:String):Void;
	public function setMarginBottomNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMarginBottomKey (element:DisplayObjectType, value:String):Void;
	public function setMarginBottomZero (element:DisplayObjectType):Void;
	public function setMarginTopZero (element:DisplayObjectType):Void;
	public function setMarginLeftZero (element:DisplayObjectType):Void;
	public function setMarginRightZero (element:DisplayObjectType):Void;
	public function setPaddingLeft (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setPaddingTop (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setPaddingRight (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setPaddingBottom (element:DisplayObjectType, value:Float, unit:String):Void;

/*	public function setBorderLeft (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderTop (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderRight (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderBottom (element:DisplayObjectType, value:Int, unit:String):Void;

	public function setBorderLeftColor (element:DisplayObjectType, value:String):Void;
	public function setBorderTopColor (element:DisplayObjectType, value:String):Void;
	public function setBorderRightColor (element:DisplayObjectType, value:String):Void;
	public function setBorderBottomColor (element:DisplayObjectType, value:String):Void;
*/
	public function setMinWidth (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMinWidthZero (element:DisplayObjectType):Void;
	public function setMaxWidth (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMaxWidthZero (element:DisplayObjectType):Void;
	public function setMaxWidthKey (element:DisplayObjectType, value:String):Void;
	public function setMinHeight(element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMinHeightZero (element:DisplayObjectType):Void;
	public function setMaxHeight (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setMaxHeightKey (element:DisplayObjectType, value:String):Void;
	public function setMaxHeightZero (element:DisplayObjectType):Void;
	
	public function setWidth (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setWidthZero (element:DisplayObjectType):Void;
	public function setWidthKey(element:DisplayObjectType, value:String):Void;
	public function setHeight (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setHeightZero (element:DisplayObjectType):Void;
	public function setHeightKey(element:DisplayObjectType, value:String):Void;
/*	public function setMinWidth (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMinHeight (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMaxWidth (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMaxHeight (element:DisplayObjectType, value:Int, unit:String):Void;
*/	public function setTop (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setTopZero (element:DisplayObjectType):Void;
	public function setLeft (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setLeftZero (element:DisplayObjectType):Void;
	public function setBottom (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setBottomZero (element:DisplayObjectType):Void;
	public function setRight (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setRightZero (element:DisplayObjectType):Void;
	public function setTopKey (element:DisplayObjectType, value:String):Void;
	public function setLeftKey (element:DisplayObjectType, value:String):Void;
	public function setBottomKey (element:DisplayObjectType, value:String):Void;
	public function setRightKey (element:DisplayObjectType, value:String):Void;
	public function setBgColorHex (element:DisplayObjectType, value:String):Void;
	public function setBgColorRGBA (element:DisplayObjectType, value:String):Void;
	public function setBgColorRGB (element:DisplayObjectType, value:String):Void;
	public function setBgColorKey (element:DisplayObjectType, value:String):Void;
	public function setBgImage (element:DisplayObjectType, value:Array<String>):Void;
	public function setBgAttachment (element:DisplayObjectType, value:String):Void;
	public function setBgRepeat (element:DisplayObjectType, value:Array<String>):Void;
/*	public function setBgOrigin (element:DisplayObjectType, value:Array<String>):Void;
	public function setBgSize (element:DisplayObjectType, value:Array<String>):Void;
*/	public function setBgPos (element:DisplayObjectType, value:String):Void;

/*	public function setBgClip (element:DisplayObjectType, value:Array<String>):Void;
*/
	public function setFontSizeNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setFontSizeKey (element:DisplayObjectType, value:String):Void;
	public function setFontWeightKey (element:DisplayObjectType, value:String):Void;
	public function setFontWeightNum (element:DisplayObjectType, value:Int):Void;
	public function setFontStyle (element:DisplayObjectType, value:String):Void;
	public function setFontFamily (element:DisplayObjectType, value:Array<String>):Void;
	public function setFontVariant (element:DisplayObjectType, value:String):Void;
	public function setTextColorKey (element:DisplayObjectType, value:String):Void;
	public function setTextColorNum (element:DisplayObjectType, value:Int):Void;
	public function setTextColorRGBA (element:DisplayObjectType, value:String):Void;
	public function setTextColorRGB (element:DisplayObjectType, value:String):Void;
	public function setTextDecoration (element:DisplayObjectType, value:String):Void;
	public function setLineHeightNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setLineHeightZero (element:DisplayObjectType):Void;
	public function setLineHeightKey (element:DisplayObjectType, value:String):Void;
	public function setTextTransform (element:DisplayObjectType, value:String):Void;
	public function setTextIndent (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setLetterSpacingNum (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setLetterSpacingKey (element:DisplayObjectType, value:String):Void;
	public function setWordSpacingNum (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setWordSpacingKey (element:DisplayObjectType, value:String):Void;
	public function setTextAlign (element:DisplayObjectType, value:String):Void;
	public function setVerticalAlignNum (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setVerticalAlignKey (element:DisplayObjectType, value:String):Void;
	public function setWhiteSpace (element:DisplayObjectType, value:String):Void;
	public function setOverflowX (element:DisplayObjectType, value:String):Void;
	public function setOverflowY (element:DisplayObjectType, value:String):Void;
	public function setZIndex(element:DisplayObjectType, value:String):Void;
/*	public function setTextIndent (element:DisplayObjectType, value:Int, unit:String):Void;
	
	public function setOpacity (element:DisplayObjectType, value:Int, unit:String):Void;
	}
	public function setVisibility (element:DisplayObjectType, value:Int, unit:String):Void;
	
	public function setCursor (element:DisplayObjectType, value:Int, unit:String):Void;
*/
}
/*
interface IStyleProxy<DisplayObjectType>
{
	public function setMarginLeft (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMarginTop (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMarginRight (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setMarginBottom (element:DisplayObjectType, value:Int, unit:String):Void;

	public function setPaddingLeft (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setPaddingTop (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setPaddingRight (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setPaddingBottom (element:DisplayObjectType, value:Int, unit:String):Void;

	public function setBorderLeft (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderTop (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderRight (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBorderBottom (element:DisplayObjectType, value:Int, unit:String):Void;

	public function setBorderLeftColor (element:DisplayObjectType, value:String):Void;
	public function setBorderTopColor (element:DisplayObjectType, value:String):Void;
	public function setBorderRightColor (element:DisplayObjectType, value:String):Void;
	public function setBorderBottomColor (element:DisplayObjectType, value:String):Void;
	
	// inherited
//	public function font : Context.Font; // family + style
	public function setFontFamily (element:DisplayObjectType, value:Array<String>):Void;
	public function setFontWeightKeyword (element:DisplayObjectType, value:String):Void;
	public function setFontWeightNum (element:DisplayObjectType, value:Int):Void;
	public function setFontVariant (element:DisplayObjectType, value:String):Void;
	public function setFontStyle (element:DisplayObjectType, value:String):Void;
	public function setFontSizeKeyword (element:DisplayObjectType, value:String):Void;
	public function setFontSizeNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setTextColorKeyword (element:DisplayObjectType, value:String):Void;
	public function setTextColorNum (element:DisplayObjectType, value:Int):Void;
	public function setTextDecoration (element:DisplayObjectType, value:String):Void;
	public function setTextTransform (element:DisplayObjectType, value:String):Void;
	public function setLineHeightNum (element:DisplayObjectType, value:Float, unit:String):Void;
	public function setLineHeightKeyword (element:DisplayObjectType, value:String):Void;
	
	public function setBgColorKeyword (element:DisplayObjectType, value:String):Void;
	public function setBgColorNum (element:DisplayObjectType, value:Int):Void;
	public function setBgImage (element:DisplayObjectType, value:String):Void;
	public function setBgAttachment (element:DisplayObjectType, value:String):Void;
	public function setBgRepeat (element:DisplayObjectType, value:String):Void;
	public function setBgPosXKeyword (element:DisplayObjectType, value:String):Void;
	public function setBgPosXNum (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setBgPosYKeyword (element:DisplayObjectType, value:String):Void;
	public function setBgPosYNum (element:DisplayObjectType, value:Int, unit:String):Void;
	
	public function setWidth (element:DisplayObjectType, value:Int, unit:String):Void;
	public function setHeight (element:DisplayObjectType, value:Int, unit:String):Void;
	
	public function setDisplay (element:DisplayObjectType, value:String):Void;
	public function setPosition (element:DisplayObjectType, value:String):Void;
}
*/