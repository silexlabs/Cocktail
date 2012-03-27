/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail;

/**
 * Define type aliases for all of Cocktail's public API
 * 
 * TODO : missing types
 */

/**
 * DOM
 */
typedef Element = core.dom.Element;
typedef Node = core.dom.Node;

/**
 * HTML
 */
typedef HTMLImageElement = core.HTMLImageElement;
typedef Image = core.HTMLImageElement;
typedef HTMLElement = core.HTMLElement;
typedef HTMLDocument = core.html.HTMLDocument;

/**
 * RESOURCE
 */
typedef XMLHTTPRequest = core.resource.XMLHTTPRequest;

/**
 * STYLE
 */
typedef Display = core.style.StyleData.Display;
typedef Position = core.style.StyleData.Position;
typedef CSSFloat = core.style.StyleData.CSSFloat;
typedef Clear = core.style.StyleData.Clear;

typedef FontSize = core.style.StyleData.FontSize;
typedef FontWeight = core.style.StyleData.FontWeight;
typedef FontStyle = core.style.StyleData.FontStyle;
typedef FontFamily = core.style.StyleData.FontFamily;
typedef FontVariant = core.style.StyleData.FontVariant;

typedef WhiteSpace = core.style.StyleData.WhiteSpace;
typedef LetterSpacing = core.style.StyleData.LetterSpacing;
typedef WordSpacing = core.style.StyleData.WordSpacing;
typedef TextTransform = core.style.StyleData.TextTransform;
typedef TextIndent = core.style.StyleData.TextIndent;
typedef TextAlign = core.style.StyleData.TextAlign;

typedef Overflow = core.style.StyleData.Overflow;
typedef Visibility = core.style.StyleData.Visibility;
typedef Opacity = core.style.StyleData.Opacity;
typedef Transform = core.style.StyleData.Transform;

typedef Margin = core.style.StyleData.Margin;
typedef Padding = core.style.StyleData.Padding;

typedef BackgroundImage = core.style.StyleData.BackgroundImage;
typedef BackgroundColor = core.style.StyleData.BackgroundColor;
typedef BackgroundRepeat = core.style.StyleData.BackgroundRepeat;
typedef BackgroundSize = core.style.StyleData.BackgroundSize;
typedef BackgroundPosition = core.style.StyleData.BackgroundPosition;

typedef Dimension = core.style.StyleData.Dimension;

/**
 * UNIT
 */
typedef Length = core.unit.UnitData.Length;
typedef ImageValue = core.unit.UnitData.ImageValue;
typedef ColorValue = core.unit.UnitData.ColorValue;
typedef ColorKeyword = core.unit.UnitData.ColorKeyword;