/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package ;

import js.Lib;
import js.Dom;

import Constants;

/**
 * Defines the style of the web app
 * 
 * @author Raphael Harmel
 */

class WebAppStyle 
{
	// offset, needed for Panasonic TV
	static inline var _offSet:Int = 40;
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:HtmlDom):Void
	{
		domElement.style.minHeight = "130%";
	}
	
	/**
	 * Defines body Style
	 * 
	 * @param	domElement
	 */
	public static function getBodyStyle(domElement:HtmlDom):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = "static";

		domElement.style.marginBottom = "0";
		domElement.style.marginLeft = "0";
		domElement.style.marginRight = "0";
		domElement.style.marginTop = "0";
	}
	
	/**
	 * Defines main container Style
	 * 
	 * @param	domElement
	 */
	public static function getMainContainerStyle(domElement:HtmlDom):Void
	{
		getDefaultStyle(domElement);
		
		//domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		//domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		//domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		//domElement.style.paddingTop = PaddingStyleValue.length(px(0));

		//domElement.style.position = PositionStyleValue.staticStyle;
		
		// Panasonic TV workaround so that aplication is fully visible
		//domElement.style.marginBottom = MarginStyleValue.length(px(_offSet));
		//domElement.style.marginLeft = MarginStyleValue.length(px(_offSet));
		//domElement.style.marginRight = MarginStyleValue.length(px(_offSet));
		//domElement.style.marginTop = MarginStyleValue.length(px(_offSet));
		
		//domElement.style.top = PositionOffsetStyleValue.length(px(_offSet));
		//domElement.style.bottom = PositionOffsetStyleValue.length(px(_offSet));
		//domElement.style.left = PositionOffsetStyleValue.length(px(_offSet));
		//domElement.style.right = PositionOffsetStyleValue.length(px(_offSet));
	}
	
	/**
	 * Defines page container Style
	 * 
	 * @param	domElement
	 */
	public static function getPageContainerStyle(domElement:HtmlDom):Void
	{
		getDefaultStyle(domElement);
		
		//domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.height = DimensionStyleValue.percent(100);

		domElement.style.left = "auto";
		domElement.style.top = "auto";
	}
	
	/**
	 * Defines home page Style
	 * 
	 * @param	domElement
	 */
	public static function getHomePageStyle(domElement:HtmlDom):Void
	{
		//getDefaultStyle(domElement);
		
		//getPageStyle(domElement);
	}
	
	/**
	 * Defines default page Style
	 * 
	 * @param	domElement
	 */
	public static function getPageStyle(domElement:HtmlDom):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.width = "100%";
		domElement.style.height = "100%";
	}
	
	/**
	 * Defines home background image style Style
	 * 
	 * @param	domElement
	 */
	public static function getBgStyle(domElement:HtmlDom):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = "absolute";
		domElement.style.display = "block";
		
		domElement.style.top = "0";
		domElement.style.left = "0";
		domElement.style.right = "0";
		domElement.style.bottom = "0";
		
		domElement.style.width = "100%";
		domElement.style.height = "100%";
	}
	
	
	/**
	 * Defines header Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderStyle(domElement:HtmlDom):Void
	{
		domElement.style.position = "fixed";
		domElement.style.display = "block";
		
		domElement.style.minWidth = "100%";
		domElement.style.width = "100%";
		domElement.style.left = "0";
		domElement.style.top = "0";
		//domElement.nativeElement.style.zIndex = 2;
	}

	/**
	 * Defines header tile Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderTileStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);
		
		domElement.style.position = "relative";
		domElement.style.display = "block";
		domElement.style.top = "0";
		domElement.style.bottom = "auto";
		domElement.style.minWidth = "100%";
		domElement.style.width = "100%";
		domElement.style.height = Constants.headerHeight + "px";
	}

	/**
	 * Defines header logo Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderLogoStyle(domElement:HtmlDom):Void
	{
		domElement.style.position = "absolute";
		domElement.style.display = "block";
		domElement.style.top = "4px";
		domElement.style.bottom = "auto";
		domElement.style.left = "15px";
		domElement.style.right = "auto";
		domElement.style.width = "44px";
	}

	/**
	 * Defines footer Style
	 * 
	 * @param	domElement
	 */
	public static function getFooterStyle(domElement:HtmlDom):Void
	{
		domElement.style.position = "fixed";
		domElement.style.display = "block";
		
		domElement.style.left = "0";
		domElement.style.top = "auto";
		domElement.style.bottom = "0";
	}

	/**
	 * Defines footer menu image Style
	 * 
	 * @param	domElement
	 */
	public static function getFooterMenuStyle(domElement:HtmlDom):Void
	{
		domElement.style.position = "fixed";
		domElement.style.display = "block";
		domElement.style.top = "auto";
		domElement.style.bottom = "auto";
		domElement.style.width = "auto";
	}

	/**
	 * Defines footer tile Style
	 * 
	 * @param	domElement
	 */
	public static function getFooterTileStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);
		
		domElement.style.position = "fixed";
		domElement.style.display = "block";
		domElement.style.top = "auto";
		domElement.style.bottom = "0";
		domElement.style.minWidth = "100%";
		domElement.style.width = "100%";
		domElement.style.height = Constants.footerHeight + "px";
	}

	/**
	 * Defines header title text Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderTextStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);
		
		domElement.style.position = "absolute";
		domElement.style.color = '#454545';

		domElement.style.fontSize = "20px";
		domElement.style.fontWeight = "bold";
		domElement.style.fontStyle = "normal";
		domElement.style.fontFamily = "HelveticaNeue,Sans-Serif";
		
		domElement.style.textAlign = "center";

		domElement.style.paddingTop = "8px";
		
		domElement.style.minWidth = "100%";
		domElement.style.width = "100%";
		domElement.style.height = Constants.headerHeight + "px";
		domElement.style.verticalAlign = "middle";
	}

	/**
	 * Defines back button Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);
		
		domElement.style.position = "absolute";
		domElement.style.paddingTop = "6px";
		domElement.style.paddingLeft = "10px";
	}

	/**
	 * Defines back button text Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonTextStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);
		
		domElement.style.position = "absolute";
		domElement.style.color = '#EEEEEE';

		domElement.style.fontSize = "14px";
		domElement.style.lineHeight = "normal";
		domElement.style.fontWeight = "bold";
		domElement.style.fontStyle = "normal";
		domElement.style.fontFamily = "HelveticaNeue, Sans-Serif";
	
		domElement.style.textAlign = "center";

		domElement.style.paddingTop = "12px";
		domElement.style.paddingLeft = "30px";
	}

	/**
	 * Defines back button image Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonImageStyle(domElement:HtmlDom):Void
	{
		getHeaderStyle(domElement);

		domElement.style.display = "inline";
		domElement.style.position = "relative";
		domElement.style.top = "0";
		domElement.style.left = "0";
	}

	/**
	 * Defines text content Style
	 * 
	 * @param	domElement
	 */
	public static function getTextContentStyle(domElement:HtmlDom):Void
	{
		domElement.style.paddingBottom = "8px";
		domElement.style.paddingLeft = "8px";
		domElement.style.paddingTop = "8px";
		domElement.style.paddingRight = "8px";
	}
	
}