/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package components.lists;

import js.Lib;
import js.Dom;

import Constants;

// list
import components.lists.ListBaseModels;

// Utils
import Utils;
import ScreenResolution;

/**
 * This class defines the styles used by a Thumb & text cell,
 * i.e. a list with each cell containing a thumbnail on the left and text informations on the right,
 * and having each cell under the previous one
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1Style
{
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getListStyle(domElement:HtmlDom):Void
	{
		
		domElement.style.display = "block";
		domElement.style.position = "absolute";
		
		domElement.style.marginLeft = "0";
		domElement.style.marginRight = "0";
		domElement.style.marginTop = "0";
		domElement.style.marginBottom = "0";
		//domElement.style.marginBottom = MarginStyleValue.length(px(Constants.footerHeight));
		
		domElement.style.paddingLeft = "0";
		domElement.style.paddingRight = "0";
		domElement.style.paddingTop = "0";
		domElement.style.paddingBottom = Constants.footerHeight +"px";
		
		domElement.style.top = "43px";
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:HtmlDom):Void
	{
		domElement.style.paddingTop = "1%";
		
		// Samsung TV workaround
		//domElement.style.height = "200px";
		
	}
	
	/**
	 * Defines info block Style
	 * 
	 * @param	domElement
	 */
	public static function getCellInfoBlockStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "inline-block";
		domElement.style.width = "10%";
		domElement.style.verticalAlign = "middle";
		// workaround for Samsung TVs
		domElement.style.textAlign = "center";
	}
	
	/**
	 * Defines cell number Style
	 * 
	 * @param	domElement
	 */
	public static function getCellNumberStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
		var fontSize:Int = 12;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 12;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16;
		else  fontSize = 20;
		domElement.style.fontSize = fontSize + "px";

		domElement.style.fontWeight = "bold";
		domElement.style.color = '#989898';
		domElement.style.textAlign = "center";
		domElement.style.paddingBottom = "2%";
	}
	
	/**
	 * Defines comment count Style
	 * 
	 * @param	domElement
	 */
	public static function getCellCommentCountStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
		var fontSize:Int = 11;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 11;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 14;
		else  fontSize = 17;
		domElement.style.fontSize = fontSize + "px";

		domElement.style.fontWeight = "bold";
		domElement.style.color = '#CC3517';
		domElement.style.textAlign = "center";
	}
	
	/**
	 * Defines cell info block image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellInfoBlockLineStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	//public static function getCellInfoBlockLineStyle(domElement:ImageDOMElement):Void
	{
		var imageMaxWidth:Int = 50;
		
		domElement.style.display = "block";
		
		domElement.style.marginLeft = "auto";
		domElement.style.marginRight = "auto";
		domElement.style.marginTop = "auto";
		domElement.style.marginBottom = "auto";
		domElement.style.paddingBottom = "5%";
		domElement.style.verticalAlign = "middle";
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(domElement.intrinsicWidth));

		// Samsung TV bug workaround
		// Samsung use
		//domElement.style.height = DimensionStyleValue.length(px(2));
		//domElement.style.textAlign = TextAlignStyleValue.center;
		// the resolution size is check to avoid having side effets on smaller devices
		// TODO: if no side-effects, could be removed
		if(screenResolutionSize == ScreenResolutionSize.large)
		{
			domElement.style.width = imageMaxWidth + "px";
			domElement.style.height = "2px";
		}
		else
		{
			domElement.style.maxWidth = imageMaxWidth + "px";
			domElement.style.width = "90%";	
		}
		// common use (Samsung TV + all other tagerts), done to emulate verticalAlign = middle, not working on samsung TV
		//domElement.style.paddingLeft = PaddingStyleValue.percent(5);
	}
	
	/**
	 * Defines cell info block image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellInfoBlockImageStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	//public static function getCellInfoBlockImageStyle(domElement:ImageDOMElement):Void
	{
		//domElement.style.display = DisplayStyleValue.block;
		domElement.style.display = "block";
		
		domElement.style.marginLeft = "auto";
		domElement.style.marginRight = "auto";
		domElement.style.marginTop = "auto";
		domElement.style.marginBottom = "auto";
		domElement.style.paddingBottom = "2%";
		domElement.style.verticalAlign = "middle";
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(domElement.intrinsicWidth));
		domElement.style.maxWidth = "20px";
		domElement.style.width = "50%";
		
		// Samsung TV bug workaround
		// Samsung use
		if(screenResolutionSize == ScreenResolutionSize.large)
		{
			domElement.style.width = "20px";
		//domElement.style.textAlign = TextAlignStyleValue.center;
		}
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellThumbnailStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		var imageMaxWidth:Int = 200;
		
		getCellStyle(domElement);
		
		domElement.style.display = "inline";
		
		domElement.style.paddingLeft = "1%";
		domElement.style.paddingRight = "1%";
		domElement.style.paddingBottom = "1%";

		domElement.style.verticalAlign = "middle";
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(imageMaxWidth));
		//domElement.style.maxHeight = ConstrainedDimensionStyleValue.percent(50);
		//domElement.style.width = DimensionStyleValue.percent(30);

		// Samsung TV bug workaround
		if(screenResolutionSize == ScreenResolutionSize.large)
		{
			domElement.style.width = imageMaxWidth + "px";
			domElement.style.height = "auto";
			domElement.style.maxHeight = imageMaxWidth + "px";
			//domElement.style.height = DimensionStyleValue.length(px(50));
		}
		else
		{
			domElement.style.maxWidth = imageMaxWidth + "px";
			domElement.style.maxHeight = imageMaxWidth + "px";
			domElement.style.width = "30%";	
		}
		
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	domElement
	 */
	public static function getCellLineStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "inline";
		domElement.style.width = "100%";
		domElement.style.height = "1px";
	}
	
	/**
	 * Defines cell text block Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextBlockStyle(domElement:HtmlDom):Void
	{
		//getCellStyle(domElement);
		
		domElement.style.display = "inline-block";
		domElement.style.marginLeft = "2%";
		domElement.style.paddingTop = "1%";
		domElement.style.verticalAlign = "middle";
		domElement.style.width = "55%";
	}

	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "block";
		domElement.style.color = '#202020';
		domElement.style.fontFamily = "HelveticaNeue, Sans-Serif";
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTitleStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
		var fontSize:Int = 14;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 14;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16;
		else  fontSize = 18;
		
		domElement.style.fontSize = fontSize + "px";
		domElement.style.fontWeight = "bold";
	}

	/**
	 * Defines cell comment Style
	 * 
	 * @param	domElement
	 */
	public static function getCellCommentStyle(domElement:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);

		var fontSize:Int = 10;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 10;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 11;
		else  fontSize = 12;
		
		domElement.style.fontSize = fontSize + "px";
		domElement.style.fontWeight = "normal";
	}

	/**
	 * Defines cell description Style
	 * 
	 * @param	domElement
	 */
	public static function getCellDescriptionStyle(domElement:HtmlDom):Void
	{
		getCellTextStyle(domElement);

		domElement.style.fontSize = "14px";
		domElement.style.fontWeight = "bold";
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:HtmlDom):Void
	{
	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:HtmlDom):Void
	{
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:HtmlDom):Void
	{
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:HtmlDom):Void
	{
	}
	
}
