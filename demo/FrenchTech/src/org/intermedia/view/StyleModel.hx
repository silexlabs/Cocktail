/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia.view;

/**
 * This class is in charge of defining the style models
 * 
 * @author Raphael Harmel
 */

import js.Dom;
 
typedef CellStyleModel =
{
	var cell:HtmlDom->?Int->Void;
	var thumbnailMask:HtmlDom->Void;
	var thumbnail:HtmlDom->Void;
	var textBlock:HtmlDom->Void;
	var title:HtmlDom->Void;
	var author:HtmlDom->Void;
}