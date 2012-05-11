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