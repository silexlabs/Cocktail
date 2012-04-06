package hxtml;
import hxtml.Style;

class Dom {

	var browser : Browser;
	
	public var name(default, null) : String;
	public var childs(default, null) : Array<Dom>;
	public var style : Style;
	public var defStyle(default, null) : Style;
	public var parent : Dom;
	
	var ctx(getContext, null) : Context;
	var e : Context.Element;
	
	public var id : String;
	public var classes : Array<String>;
	
	public var preferredWidth : Int;
	public var preferredHeight : Int;
	public var baseLineHeight : Int;
	
	public var posX : Int;
	public var posY : Int;
	
	public var contentWidth : Int;
	public var contentHeight : Int;

	public var totalWidth : Int;
	public var totalHeight : Int;
	
	var lineIndex : Int;
	var lineHeights : Array<Int>;
	var baseLineHeights : Array<Int>;
	
	public function new(b, name) {
		this.browser = b;
		this.name = name;
	}
	
	inline function getContext() {
		return browser.ctx;
	}
	
	public inline function getText() : DomText {
		return cast this;
	}
	
	public function addChild( c : Dom ) {
		if( c.parent != null ) throw "assert";
		if( childs == null )
			childs = [];
		childs.push(c);
		c.parent = this;
	}
	
	public function setAttribute( a : String, v : String ) {
		switch( a ) {
		case "id":
			id = v;
			browser.register(id, this);
		case "style":
			defStyle = new Style();
			new CssParser().parse(v,defStyle);
		case "class":
			classes = ~/[ \t]+/g.split(StringTools.trim(v));
		default:
			throw "Unsupported attribute " + name + "." + a;
		}
	}
	
	public function getPrev() {
		if( parent == null ) return null;
		var prev = null;
		for( c in parent.childs ) {
			if( c == this ) return prev;
			if( c.style != null && c.style.display != None ) prev = c;
		}
		return null;
	}

	public function getNext() {
		if( parent == null ) return null;
		var found = true;
		for( c in parent.childs ) {
			if( c == this ) found = true;
			if( found && (c.style == null || c.style.display != None) ) return c;
		}
		return null;
	}
	
	public function updateStyle() {
		browser.css.applyClasses(this);
		if( parent != null )
			style.inherit(parent.style);
		if( childs != null )
			for( d in childs )
				d.updateStyle();
		// margin collapse
		if( style.marginTop != null ) {
			var prev = getPrev();
			if( prev == null ) {
				// give our margin to our parent - unless it has padding/border - will recurse
				if( parent != null && (parent.style.paddingTop == null || parent.style.paddingTop == 0) && (parent.style.borderTop == null || parent.style.borderTop == 0) ) {
					if( parent.style.marginTop == null || parent.style.marginTop < style.marginTop )
						parent.style.marginTop = style.marginTop;
					style.marginTop = 0;
				}
			} else if( prev.style.marginBottom != null ) {
				// give our margin to our previous visible element
				if( prev.style.marginBottom < style.marginTop )
					prev.style.marginBottom = style.marginTop;
				style.marginTop = 0;
			}
		}
	}

	function initElement() {
	}
	
	function evalUnits( u : Unit, size : Float ) {
		if( u == null ) return 0;
		switch( u ) {
		case Pix(v):
			return v;
		case EM(v):
			return Math.round(v * style.fontSize);
		case Percent(v):
			return Math.round(v * size);
		}
	}
	
	public function render() {
		e = ctx.createElement((parent == null) ? ctx.root : parent.e);
		e.setPos(posX, posY);
		var plr = style.paddingLeft + style.paddingRight;
		var ptb = style.paddingTop + style.paddingBottom;
		if( style.bgColor != null && !style.bgTransparent )
			ctx.addBackground(e, style.bgColor, contentWidth + plr, contentHeight + ptb);
		if( style.bgImage != null && style.bgImage != "" ) {
			var me = this;
			var img = ctx.loadImage(style.bgImage, function(_) {
				me.browser.invalidate();
			});
			if( img == null )
				browser.notLoaded();
			else {
				var bw = contentWidth + plr;
				var bh = contentHeight + ptb;
				var px = evalUnits(style.bgPosX, bw - img.width);
				var py = evalUnits(style.bgPosY, bh - img.height);
				if( style.bgRepeatX == false ) {
					bw -= px;
					if( bw < 0 ) bw = 0;
					if( bw > img.width ) bw = img.width;
				}
				if( style.bgRepeatY == false ) {
					bh -= py;
					if( bh < 0 ) bh = 0;
					if( bh > img.height ) bh = img.height;
				}
				ctx.addBackgroundImage(e, img, style, px, py, bw, bh, style.bgRepeatX != false, style.bgRepeatY != false);
			}
		}
		initElement();
		if( childs != null )
			for( d in childs )
				if( d.style.display != None )
					d.render();
	}
	
	public function updateSize( width : Int, height : Null<Int> ) {
		var plr = style.paddingLeft + style.paddingRight;
		var ptb = style.paddingTop + style.paddingBottom;
		var mlr = style.marginLeft + style.marginRight;
		var mtb = style.marginTop + style.marginBottom;
		
		if( style.width != null )
			width = style.width;
		if( style.height != null )
			height = style.height;
		
		contentWidth = 0;
		contentHeight = 0;
	
		// inline childs
		if( childs != null ) {
			var allowedWidth = width - (mlr + plr);
			var lineWidth = 0, lineHeight = 0, baseLine = 0;
			var i = 0, count = childs.length, lineIndex = 0;
			lineHeights = [];
			baseLineHeights = [];
			while( i < count ) {
				var d = childs[i++];
				if( d.style.display == None )
					continue;
				var isBlock = (d.style.display == Block);
				// create new line
				if( isBlock && lineWidth > 0 ) {
					lineHeights.push(lineHeight);
					baseLineHeights.push(baseLine);
					contentHeight += lineHeight;
					if( lineWidth > contentWidth )
						contentWidth = lineWidth;
					lineWidth = 0;
					lineHeight = 0;
					baseLine = 0;
					lineIndex++;
				}
				d.updateSize(allowedWidth - lineWidth, height);
				// check breakable
				if( d.name == null && browser.isLoaded() && lineWidth + d.totalWidth > allowedWidth ) {
					var d2 : Dom = d.getText().breakAt(allowedWidth - lineWidth);
					if( d2 == null && lineWidth > 0 && d.totalWidth > allowedWidth )
						d2 = d.getText().breakAt(allowedWidth);
					if( d2 != null ) {
						d2.parent = this;
						d2.updateStyle();
						d.updateSize(allowedWidth, height);
						childs.insert(i, d2);
						count++;
					}
				}
				// create new line
				if( lineWidth > 0 && (isBlock || lineWidth + d.totalWidth > allowedWidth) ) {
					lineHeights.push(lineHeight);
					baseLineHeights.push(baseLine);
					contentHeight += lineHeight;
					if( lineWidth > contentWidth )
						contentWidth = lineWidth;
					lineWidth = 0;
					lineHeight = 0;
					baseLine = 0;
					lineIndex++;
				}
				// add to current line
				lineWidth += d.totalWidth;
				d.lineIndex = lineIndex;
				if( d.totalHeight > lineHeight ) lineHeight = d.totalHeight;
				if( d.baseLineHeight > baseLine ) baseLine = d.baseLineHeight;
			}
			if( lineWidth > 0 ) {
				lineHeights.push(lineHeight);
				baseLineHeights.push(baseLine);
				if( lineWidth > contentWidth )
					contentWidth = lineWidth;
				contentHeight += lineHeight;
			}
		}
		if( contentWidth < preferredWidth )
			contentWidth = preferredWidth;
		if( contentHeight < preferredHeight )
			contentHeight = preferredHeight;
		if( style.width != null )
			contentWidth = style.width;
		if( style.height != null )
			contentHeight = style.height;
		totalWidth = contentWidth + mlr + plr;
		totalHeight = contentHeight + mtb + ptb;
		baseLineHeight = ( childs == null || baseLineHeights.length > 1 ) ? totalHeight : baseLineHeights[0];
	}
	
	public function updatePos(x, y) {
		x += style.marginLeft;
		y += style.marginTop;
		posX = x;
		posY = y;
		if( childs != null ) {
			var lineIndex = 0;
			var px0 = style.paddingLeft;
			var px = px0, py = style.paddingTop;
			for( d in childs ) {
				if( d.style.display == None )
					continue;
				if( d.lineIndex != lineIndex ) {
					py += lineHeights[lineIndex++];
					px = px0;
				}
				d.updatePos(px, py + baseLineHeights[lineIndex] - d.baseLineHeight);
				px += d.totalWidth;
			}
		}
	}
	
}

class DomText extends Dom {
	
	public var text(default,null) : String;
	var telt : Context.Text;
	var displayText : String;
	
	public function new(b,t) {
		super(b, null);
		text = ~/[ \r\n\t]+/g.split(t).join(" ");
	}
	
	public function appendSpace() {
		if( text.charCodeAt(text.length - 1) != " ".code )
			text += " ";
	}

	public function breakAt( width : Int ) {
		if( telt == null )
			return null;
		var index = telt.getCharIndex(width);
		if( index < 0 )
			return null;
		var start = 0;
		while( true ) {
			var pos = displayText.indexOf(" ", start);
			if( pos == -1 || pos > index ) break;
			start = pos + 1;
		}
		if( start == 0 )
			return null;
		var tsub = displayText.substr(start);
		var firstSpace = text.charAt(0) == " ";
		var lastSpace = text.charAt(1) == " ";
		text = displayText = displayText.substr(0, start - 1);
		if( firstSpace ) text = " " + text;
		if( lastSpace ) tsub += " ";
		return new DomText(browser, tsub);
	}
	
	override function updateStyle() {
		super.updateStyle();
		// first update
		if( parent == null || parent.childs.length == 1 ) {
			displayText = StringTools.trim(text);
			if( displayText == "" ) displayText = " ";
		} else {
			displayText = text;
			var prev = getPrev();
			if( prev == null || prev.style.display == Block )
				displayText = StringTools.ltrim(displayText);
			var next = getNext();
			if( next == null || next.style.display == Block )
				displayText = StringTools.rtrim(displayText);
			if( displayText == "" )
				style.display = None;
		}
		if( style.textTransform != null )
			switch( style.textTransform ) {
			case TFNone:
			case TFCapitalize:
				var str = null;
				for( w in displayText.split(" ") ) {
					if( str == null ) str = "" else str += " ";
					if( w.length > 0 )
						str += w.charAt(0).toUpperCase()+w.substr(1);
				}
				displayText = str;
			case TFLowercase: displayText = displayText.toLowerCase();
			case TFUppercase: displayText = displayText.toUpperCase();
			}
	}
	
	override function updateSize(w, h) {
		telt = ctx.createText(displayText, style);
		preferredWidth = telt.width;
		preferredHeight = telt.height;
		super.updateSize(w, h);
		baseLineHeight = telt.getBaseLineHeight();
	}
	
	override function initElement() {
		if( telt != null ) ctx.addText(e, telt);
	}

}

class DomLink extends Dom {
	
	public var href : String;
	
	override function setAttribute( a : String, v : String ) {
		switch( a ) {
		case "href":
			href = v;
		default:
			super.setAttribute(a, v);
		}
	}
		
	override function initElement() {
		var me = this;
		if( href != null ) e.setClick(function() me.browser.browse(me.href));
	}
	
}

class DomHidden extends Dom {
	
	var hrefLink : String;
	
	override function setAttribute( a, v ) {
		switch( name ) {
		case "link":
			switch( a ) {
			case "rel":
				return;
			case "type":
				return;
			case "href":
				hrefLink = v;
				return;
			}
		}
		super.setAttribute(a, v);
	}
	
	override function render() {
	}

	override function updateStyle() {
		super.updateStyle();
		if( hrefLink != null ) {
			var me = this;
			me.browser.notLoaded();
			ctx.loadText(hrefLink, function(data) {
				me.browser.css.addRules(data);
				me.browser.invalidate();
			});
			hrefLink = null;
		}
	}
	
	override function updateSize(w, h) {
	}

	override function updatePos(x,y) {
	}
	
}

class DomStyle extends DomHidden {
	
	var styleInit : Bool;
	
	override function setAttribute( a : String, v : String ) {
		switch( a ) {
		case "type": return;
		default:
		}
		super.setAttribute(a, v);
	}
	
	override function updateStyle() {
		super.updateStyle();
		if( styleInit ) return;
		styleInit = true;
		var c = childs[0];
		if( c.name == null )
			browser.css.addRules(c.getText().text);
	}
	
}

class DomImage extends Dom {
	
	var src : String;
	var image : Context.Image;
	
	function onLoaded(i) {
		image = i;
		browser.invalidate();
	}
	
	override function updateSize(w,h) {
		if( image == null && src != null ) {
			image = ctx.loadImage(src, onLoaded);
			if( image == null ) {
				browser.notLoaded();
				return;
			}
		}
		preferredWidth = image.width;
		preferredHeight = image.height;
		super.updateSize(w,h);
	}
	
	override function initElement() {
		if( image != null )
			ctx.addImage(e, style.paddingLeft, style.paddingTop, image);
	}
	
	override function setAttribute( a : String, v : String ) {
		switch( a ) {
		case "src":
			src = v;
		default:
			super.setAttribute(a, v);
		}
	}
	
}