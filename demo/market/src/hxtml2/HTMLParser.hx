package hxtml2;

import hxtml2.HTMLPageData;
import js.Dom;

/*
import cocktail.textElement.TextElement;
*/

/**
 * This class is in charge of parsing a whole HTML page. It can load CSS and fonts. (And store hxscript/javascript?).
 * It is based on Cocktail library, so the parse() method builds a hole model for the HTML page, with a BodyDOMElement, and a hierarchy of DOMElement and TextElement.
 * Part of the code is taken from http://code.google.com/p/hxtml/source/browse/trunk/hxtml/Browser.hx
 */
class HTMLParser 
{
	/**
	 * The css parser
	 */
	public var _cssParser : CSSParser;
	/**
	 * Constructor
	 */
	public function new()
	{
		// create the css parser
		_cssParser = new CSSParser();
	}
	/**
	 * parse all the DOM nodes and create the DOM elements
	 */
	public function parse(xmlDOM:Xml):HTMLPageData
	{
		// init the page data
		var htmlPageData = new HTMLPageData(_cssParser);
		// create the DOM
		_doParse(xmlDOM, htmlPageData, htmlPageData.htmlDom);
		return htmlPageData;
	}
	/**
	 * recursively parse all the DOM nodes and create the DOM elements
	 */
	private function _doParse(xmlDOM:Xml, htmlPageData:HTMLPageData, parent:HtmlDom = null):Void
	{
		//trace("_doParse " + xmlDOM);

		// variable used to store the return value
		var element:HtmlDom = null;

		// if the element is a node of type Text or CData, create the node and return - no children
		switch( xmlDOM.nodeType ) 
		{
			case Xml.CData:
				throw "assert";
			case Xml.PCData, Xml.Comment:
				//trace("added text :"+xmlDOM.nodeValue);
				// create the node
				element = htmlPageData.createTextNode(xmlDOM.nodeValue, parent);
				// first node
				if (parent == null) htmlPageData.htmlDom = element;
				return ;
		}

		// type of tag (img, body, div...)
		var elementType:ElementTypeValue = unknown;
		try
		{
			elementType = Type.createEnum(ElementTypeValue, xmlDOM.nodeName.toLowerCase());
		}catch(msg : String)
		{
			//trace("Error, unknown tag "+xmlDOM.nodeName.toLowerCase()+"\n"+msg);
			elementType = unknown;
		}

		// create the element depending on its type
		switch(elementType) 
		{
			case head, link, meta, title:
			case html:
			case style:
				// to do : load a style sheet or parse the css styles
			default:
				// convert the attributes iterator in a hash table for ease of use
				var attributesHash:Hash<String> = new Hash();
				for(attr in xmlDOM.attributes())
				{
					attributesHash.set(attr, xmlDOM.get(attr));
				}
				// create the node
				element = htmlPageData.createElement(elementType, attributesHash, parent, xmlDOM.nodeName);
				// first node
				if (parent == null) htmlPageData.htmlDom = element;
		}
		// build children
		var hasText = false;
		for( child in xmlDOM ) 
		{
			// remove empty texts
			if(child.nodeType ==Xml.PCData && ~/^[ \n\r\t]*$/.match(child.nodeValue) ) 
					continue;
			// recusrsive call 
			_doParse(child, htmlPageData, element);
		}
	}
}