package hxtml;
import hxtml.Style;

class CssRule {
	public var c : CssClass;
	public var priority : Int;
	public var s : Style;
	public function new() {
	}
}

class CssEngine {
	
	var rules : Array<CssRule>;
	
	public function new() {
		rules = [];
	}

	function applyDefaultStyle( s : Style, node : String ) {
		s.display = Inline;
		switch( node ) {
		case "body":
			s.margin(8, 8, 8, 8);
			s.fontFamily = ["Times New Roman"];
			s.fontWeight = true;
			s.fontStyle = FSNormal;
			s.fontSize = 16;
		case "html":
			s.bgColor = 0xFFFFFF;
//			s.width = browser.ctx.pageWidth;
		case "a":
			s.textDecoration = TDUnderline;
			s.textColor = 0x0000CC;
		case "div":
			s.display = Block;
		case "br":
			s.display = Block;
		case "style":
			s.display = None;
		}
		return s;
	}
	
	function randColor() {
		while( true ) {
			var r = Std.random(256);
			var g = Std.random(256);
			var b = Std.random(256);
			if( r + g + b < 256 ) continue;
			return (r << 16) | (g << 8) | b;
		}
		return 0;
	}
	
	public function applyClasses( d : Dom ) {
		var s = new Style();
		applyDefaultStyle(s, d.name);
		d.style = s;
		var rules = [];
		for( r in this.rules ) {
			if( !ruleMatch(r.c, d) )
				continue;
			rules.push(r);
		}
		rules.sort(sortByPriority);
		for( r in rules )
			s.apply(r.s);
		if( d.defStyle != null )
			s.apply(d.defStyle);
	}
	
	function sortByPriority(r1:CssRule, r2:CssRule) {
		return r1.priority - r2.priority;
	}
	
	function ruleMatch( c : CssClass, d : Dom ) {
		if( c.className != null ) {
			if( d.classes == null )
				return false;
			var found = false;
			for( cc in d.classes )
				if( cc == c.className ) {
					found = true;
					break;
				}
			if( !found )
				return false;
		}
		if( c.node != null && c.node != d.name )
			return false;
		if( c.id != null && c.id != d.id )
			return false;
		if( c.parent != null && (d.parent == null || !ruleMatch(c.parent, d.parent)) )
			return false;
		return true;
	}
	
	public function addRules( text : String ) {
		for( r in new CssParser().parseRules(text) ) {
			var c = r.c;
			var imp = r.imp ? 1 : 0;
			var nids = 0, nothers = 0, nnodes = 0;
			while( c != null ) {
				if( c.id != null ) nids++;
				if( c.node != null ) nnodes++;
				if( c.pseudoClass != null ) nothers++;
				if( c.className != null ) nothers++;
				c = c.parent;
			}
			var rule = new CssRule();
			rule.c = r.c;
			rule.s = r.s;
			rule.priority = (imp << 24) | (nids << 16) | (nothers << 8) | nnodes;
			rules.push(rule);
		}
	}
	
}
