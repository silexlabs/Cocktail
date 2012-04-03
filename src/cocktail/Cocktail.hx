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
typedef Element = cocktail.core.dom.Element;
typedef Node = cocktail.core.dom.Node;
typedef Text = cocktail.core.dom.Text;
typedef Document = cocktail.core.dom.Document;
typedef Attr = cocktail.core.dom.Attr;
typedef NamedNodeMap = cocktail.core.dom.NamedNodeMap;

/**
 * HTML
 */
typedef HTMLImageElement = cocktail.core.HTMLImageElement;
typedef Image = cocktail.core.HTMLImageElement;
typedef HTMLElement = cocktail.core.HTMLElement;
typedef HTMLDocument = cocktail.core.html.HTMLDocument;

/**
 * EVENT
 */
typedef Event = cocktail.core.event.Event;
typedef IEventTarget = cocktail.core.event.IEventTarget;
typedef MouseEvent = cocktail.core.event.MouseEvent;
typedef UIEvent = cocktail.core.event.UIEvent;
typedef KeyboardEvent = cocktail.core.event.KeyboardEvent;

/**
 * RESOURCE
 */
typedef XMLHTTPRequest = cocktail.core.resource.XMLHTTPRequest;

/**
 * STYLE
 */
typedef Display = cocktail.core.style.StyleData.Display;
typedef Position = cocktail.core.style.StyleData.Position;
typedef CSSFloat = cocktail.core.style.StyleData.CSSFloat;
typedef Clear = cocktail.core.style.StyleData.Clear;

typedef FontSize = cocktail.core.style.StyleData.FontSize;
typedef FontWeight = cocktail.core.style.StyleData.FontWeight;
typedef FontStyle = cocktail.core.style.StyleData.FontStyle;
typedef FontFamily = cocktail.core.style.StyleData.FontFamily;
typedef FontVariant = cocktail.core.style.StyleData.FontVariant;

typedef WhiteSpace = cocktail.core.style.StyleData.WhiteSpace;
typedef LetterSpacing = cocktail.core.style.StyleData.LetterSpacing;
typedef WordSpacing = cocktail.core.style.StyleData.WordSpacing;
typedef TextTransform = cocktail.core.style.StyleData.TextTransform;
typedef TextIndent = cocktail.core.style.StyleData.TextIndent;
typedef TextAlign = cocktail.core.style.StyleData.TextAlign;

typedef Overflow = cocktail.core.style.StyleData.Overflow;
typedef Visibility = cocktail.core.style.StyleData.Visibility;
typedef Opacity = cocktail.core.style.StyleData.Opacity;
typedef Transform = cocktail.core.style.StyleData.Transform;

typedef Margin = cocktail.core.style.StyleData.Margin;
typedef Padding = cocktail.core.style.StyleData.Padding;

typedef BackgroundImage = cocktail.core.style.StyleData.BackgroundImage;
typedef BackgroundColor = cocktail.core.style.StyleData.BackgroundColor;
typedef BackgroundRepeat = cocktail.core.style.StyleData.BackgroundRepeat;
typedef BackgroundSize = cocktail.core.style.StyleData.BackgroundSize;
typedef BackgroundPosition = cocktail.core.style.StyleData.BackgroundPosition;

typedef Dimension = cocktail.core.style.StyleData.Dimension;
typedef PositionOffset = cocktail.core.style.StyleData.PositionOffset;

/**
 * UNIT
 */
typedef Length = cocktail.core.unit.UnitData.Length;
typedef ImageValue = cocktail.core.unit.UnitData.ImageValue;
typedef Color = cocktail.core.unit.UnitData.CSSColor;
typedef ColorKeyword = cocktail.core.unit.UnitData.ColorKeyword;