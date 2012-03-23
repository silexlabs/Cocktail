package hxtml2;

/*
//import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
*/

import js.Dom;
import js.Lib;


enum ElementTypeValue 
{
	img;
	body;
	div;
	style;
	text;
	link;
	unknown;
	html; head; meta; title;
}

/**
 * This class is used to store an HTML Page data, i.e. the model for a page. 
 * It is based on Cocktail library, it has a htmlDom as a root for the DOM, and a hierarchy of DOMElement and TextElement.
 * There are also attributes to store hxscript, and CSS styles.
 */
class HTMLPageData
{
	/**
	 * The body dom element which is the root of all the dom elements hierarchy
	 */
	public var htmlDom:HtmlDom;
	/**
	 * hash table used to store IDs of the dome lements
	 */
	private var _ids : Hash<HtmlDom>;
	/**
	 * The css parser used to set styles on an element (inline styles)
	 */
	public var _cssParser : CSSParser;
	/**
	 * constructor
	 */
	public function new(cssParser : CSSParser)
	{
		// store the CSS parser
		_cssParser = cssParser;
		// init the ids
		_ids = new Hash();
		// init the body dom element
//		htmlDom = Lib.document.createElement("div");
	}
	/**
	 * register a DOMElement with its ID
	 */
	public function registerId(id:String, element:HtmlDom) 
	{
		_ids.set(id, element);
	}
	/**
	 * get a DOMElement by its ID
	 */
	public function getById(id):HtmlDom
	{
		return _ids.get(id);
	}
	
	public function createTextNode(text:String = "", parent:Null<HtmlDom> = null):HtmlDom
	{
		// create a text node
		var element:HtmlDom = Lib.document.createTextNode(text);
		// add to the dom
		if (parent != null)
			parent.appendChild(element);
		return element;
	}
	/**
	 * Creates an element in the page, specifying its type, ID and parent.
	 * If parent is null, the element will be added as a child of the body. 
	 * @return	the element created or null. The element is a class derived from HtmlDom.
	 * Part of the code is taken from http://code.google.com/p/hxtml/source/browse/trunk/hxtml/Browser.hx
	 */
	public function createElement(elementType:ElementTypeValue, attributes:Null<Hash<String>> = null, parent:Null<HtmlDom> = null, semantic:String = ""):HtmlDom
	{
//		trace("createElement "+elementType+ ", "+parent+", "+attributes);
		// default value for parent is an empty container
//		if (elementType != body && parent == null)
//			parent = containerDOMElement;
		
		// the element to return
		var element:HtmlDom = null;

		// create the element depending on the desired type
		switch(elementType)
		{
//			case a:
//				...
//			case video:
//				...
//			case sound:
//				...
//			case object:
//				...
			case img:
				element = Lib.document.createElement("img");
				if (attributes.exists("src"))
					element.setAttribute("src", attributes.get("src"));
			case body:
				// body element
				// still it may take style data
				element = Lib.document.body;
			default:
				// span, div, p, ...
				if (semantic != "")
					element = Lib.document.createElement(semantic);
				else
					element = Lib.document.createElement("div");
		}
		// add to the dom
		if (parent != null)
			parent.appendChild(element);
		// set attributes
		if (attributes != null)
			setAttributes(element, attributes);
		// return the new element
		return element;
	}
	public function setAttributes(element:HtmlDom, attributes:Hash<String>)
	{
		// get the id
		if (attributes.exists("id"))
			element.id = attributes.get("id");
		
		// register the id if needed
		if (element.id != "")
			registerId(element.id, element);
	
		// set styles
		if (attributes.exists("style"))
		{
			var styles:String = attributes.get("style");
			_cssParser.setStyleFromString(element.style, styles);
		}
	}
}