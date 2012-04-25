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
 */

/**
 * DOM
 */
/**
 * TODO : are those useful ?
 * 
typedef Element = cocktail.core.dom.Element;
typedef Node = cocktail.core.dom.Node;
typedef Text = cocktail.core.dom.Text;
typedef Document = cocktail.core.dom.Document;
typedef Attr = cocktail.core.dom.Attr;
typedef NamedNodeMap = cocktail.core.dom.NamedNodeMap;
*/

/**
 * HTML
 */

//HaxeJs types
typedef Image = cocktail.core.html.HTMLImageElement;
typedef HtmlDom = cocktail.core.html.HTMLElement;
typedef Anchor = cocktail.core.HTMLAnchorElement;
typedef Body = cocktail.core.html.HTMLBodyElement;
typedef Style = cocktail.core.style.adapter.Style;

typedef HTMLAnchorElement = cocktail.core.HTMLAnchorElement;
typedef HTMLImageElement = cocktail.core.html.HTMLImageElement;
typedef HTMLElement = cocktail.core.html.HTMLElement;
typedef HTMLDocument = cocktail.core.HTMLDocument;

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