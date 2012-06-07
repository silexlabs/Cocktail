package lib.hxtml;
import lib.haxe.xml.Parser;

class Browser<DisplayObjectType> {

	public var html(default, null) : String;
	public var domRoot : DisplayObjectType;
	var ids : Hash<DisplayObjectType>;
	
	var invalid : Bool;
	
	////////////////////////////////////////////////////////
	// callbacks provided by the application 
	// used to manipulate the dom
	////////////////////////////////////////////////////////
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public var createElement:String->DisplayObjectType;
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public var createTextNode:String->DisplayObjectType;
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public var appendChild:DisplayObjectType->DisplayObjectType->Void;
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public var setAttribute:DisplayObjectType->String->String->Void;
	/**
	 * This method is called by the browser class during the parsing of the HTML 
	 */
	public var invalidate:Void->Void;

	var styleProxy:IStyleProxy<DisplayObjectType>;
	
	public function new(createElement:String->DisplayObjectType, 
						createTextNode:String->DisplayObjectType, 
						appendChild:DisplayObjectType->DisplayObjectType->Void, 
						setAttribute:DisplayObjectType->String->String->Void,
						invalidate:Void->Void,
						styleProxy:IStyleProxy<DisplayObjectType>) {
							
		this.createElement = createElement;
		this.createTextNode = createTextNode; 
		this.appendChild = appendChild;
		this.setAttribute = setAttribute;
		this.invalidate = invalidate;
		this.styleProxy = styleProxy;
	}

	public function register(id, d) {
		ids.set(id, d);
	}

	public function setHtml( data : String ) {
		var x = Parser.parse(data).firstElement();
		ids = new Hash();
		domRoot = make(x);
		refresh();
	}
	
	public function refresh() {
		invalid = false;
		if( invalidate != null )
			invalidate();
	}
	
	public function getById(id) {
		return ids.get(id);
	}

	function make( x : Xml ) : DisplayObjectType {
		// create element
		switch( x.nodeType ) {
		case Xml.CData:
			throw "assert";
		case Xml.PCData, Xml.Comment:
			return createTextNode(x.nodeValue);
		case Xml.DocType:
			return null;
		}
		var d : DisplayObjectType;
		var name = x.nodeName.toLowerCase();
		d = createElement(name);

		// build children
		var allowComments = (name == "style");
		

 		var prev : DisplayObjectType = null;
		//var hasText = false;
		for( c in x ) {
			// remove empty texts
			switch( c.nodeType ) {
			case Xml.PCData:
				if( ~/^[ \n\r\t]*$/.match(c.nodeValue) ) {
					
/*					if( prev.name != null )
						hasText = true;
					else
						prev.getText().appendSpace();
					continue;
*/				}
/*				if( hasText ) {
					hasText = false;
					c.nodeValue = " " + c.nodeValue;
				}
*/			case Xml.Comment:
				if( !allowComments )
					continue;
			default:
/*				if( hasText ) {
					hasText = false;
					appendChild(d, createTextNode(" "));
				}
*/			}

			
		if (name == "ul")
				{
					trace(c);
				}
					prev = make(c);
					appendChild(d, prev);
		}
		// init attributes
		for( a in x.attributes() ){
			a = a.toLowerCase();
			var v = x.get(a);
			switch( a ) {
			case "id":
				register(v, d);
				setAttribute (d, a, v);
			case "style":
				new CssParser<DisplayObjectType>().parse(v, d, styleProxy);
			default:
				setAttribute (d, a, v);
			}
		}
		return d;
	}
	
}