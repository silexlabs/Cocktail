var $_, $hxClasses = $hxClasses || {}, $estr = function() { return js.Boot.__string_rec(this,''); }
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var EReg = $hxClasses["EReg"] = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.__name__ = ["EReg"];
EReg.prototype = {
	r: null
	,match: function(s) {
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,matched: function(n) {
		return this.r.m != null && n >= 0 && n < this.r.m.length?this.r.m[n]:(function($this) {
			var $r;
			throw "EReg::matched";
			return $r;
		}(this));
	}
	,matchedLeft: function() {
		if(this.r.m == null) throw "No string matched";
		return this.r.s.substr(0,this.r.m.index);
	}
	,matchedRight: function() {
		if(this.r.m == null) throw "No string matched";
		var sz = this.r.m.index + this.r.m[0].length;
		return this.r.s.substr(sz,this.r.s.length - sz);
	}
	,matchedPos: function() {
		if(this.r.m == null) throw "No string matched";
		return { pos : this.r.m.index, len : this.r.m[0].length};
	}
	,split: function(s) {
		var d = "#__delim__#";
		return s.replace(this.r,d).split(d);
	}
	,replace: function(s,by) {
		return s.replace(this.r,by);
	}
	,customReplace: function(s,f) {
		var buf = new StringBuf();
		while(true) {
			if(!this.match(s)) break;
			buf.add(this.matchedLeft());
			buf.add(f(this));
			s = this.matchedRight();
		}
		buf.b[buf.b.length] = s == null?"null":s;
		return buf.b.join("");
	}
	,__class__: EReg
}
var Hash = $hxClasses["Hash"] = function() {
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
};
Hash.__name__ = ["Hash"];
Hash.prototype = {
	h: null
	,set: function(key,value) {
		this.h["$" + key] = value;
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,exists: function(key) {
		try {
			key = "$" + key;
			return this.hasOwnProperty.call(this.h,key);
		} catch( e ) {
			for(var i in this.h) if( i == key ) return true;
			return false;
		}
	}
	,remove: function(key) {
		if(!this.exists(key)) return false;
		delete(this.h["$" + key]);
		return true;
	}
	,keys: function() {
		var a = new Array();
		for(var i in this.h) a.push(i.substr(1));
		return a.iterator();
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref["$" + i];
		}};
	}
	,toString: function() {
		var s = new StringBuf();
		s.b[s.b.length] = "{";
		var it = this.keys();
		while( it.hasNext() ) {
			var i = it.next();
			s.b[s.b.length] = i == null?"null":i;
			s.b[s.b.length] = " => ";
			s.add(Std.string(this.get(i)));
			if(it.hasNext()) s.b[s.b.length] = ", ";
		}
		s.b[s.b.length] = "}";
		return s.b.join("");
	}
	,__class__: Hash
}
var IntIter = $hxClasses["IntIter"] = function(min,max) {
	this.min = min;
	this.max = max;
};
IntIter.__name__ = ["IntIter"];
IntIter.prototype = {
	min: null
	,max: null
	,hasNext: function() {
		return this.min < this.max;
	}
	,next: function() {
		return this.min++;
	}
	,__class__: IntIter
}
var List = $hxClasses["List"] = function() {
	this.length = 0;
};
List.__name__ = ["List"];
List.prototype = {
	h: null
	,q: null
	,length: null
	,add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,first: function() {
		return this.h == null?null:this.h[0];
	}
	,last: function() {
		return this.q == null?null:this.q[0];
	}
	,pop: function() {
		if(this.h == null) return null;
		var x = this.h[0];
		this.h = this.h[1];
		if(this.h == null) this.q = null;
		this.length--;
		return x;
	}
	,isEmpty: function() {
		return this.h == null;
	}
	,clear: function() {
		this.h = null;
		this.q = null;
		this.length = 0;
	}
	,remove: function(v) {
		var prev = null;
		var l = this.h;
		while(l != null) {
			if(l[0] == v) {
				if(prev == null) this.h = l[1]; else prev[1] = l[1];
				if(this.q == l) this.q = prev;
				this.length--;
				return true;
			}
			prev = l;
			l = l[1];
		}
		return false;
	}
	,iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,toString: function() {
		var s = new StringBuf();
		var first = true;
		var l = this.h;
		s.b[s.b.length] = "{";
		while(l != null) {
			if(first) first = false; else s.b[s.b.length] = ", ";
			s.add(Std.string(l[0]));
			l = l[1];
		}
		s.b[s.b.length] = "}";
		return s.b.join("");
	}
	,join: function(sep) {
		var s = new StringBuf();
		var first = true;
		var l = this.h;
		while(l != null) {
			if(first) first = false; else s.b[s.b.length] = sep == null?"null":sep;
			s.add(l[0]);
			l = l[1];
		}
		return s.b.join("");
	}
	,filter: function(f) {
		var l2 = new List();
		var l = this.h;
		while(l != null) {
			var v = l[0];
			l = l[1];
			if(f(v)) l2.add(v);
		}
		return l2;
	}
	,map: function(f) {
		var b = new List();
		var l = this.h;
		while(l != null) {
			var v = l[0];
			l = l[1];
			b.add(f(v));
		}
		return b;
	}
	,__class__: List
}
var Reflect = $hxClasses["Reflect"] = function() { }
Reflect.__name__ = ["Reflect"];
Reflect.hasField = function(o,field) {
	if(o.hasOwnProperty != null) return o.hasOwnProperty(field);
	var arr = Reflect.fields(o);
	var $it0 = arr.iterator();
	while( $it0.hasNext() ) {
		var t = $it0.next();
		if(t == field) return true;
	}
	return false;
}
Reflect.field = function(o,field) {
	var v = null;
	try {
		v = o[field];
	} catch( e ) {
	}
	return v;
}
Reflect.setField = function(o,field,value) {
	o[field] = value;
}
Reflect.getProperty = function(o,field) {
	var tmp;
	return o == null?null:o.__properties__ && (tmp = o.__properties__["get_" + field])?o[tmp]():o[field];
}
Reflect.setProperty = function(o,field,value) {
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
}
Reflect.callMethod = function(o,func,args) {
	return func.apply(o,args);
}
Reflect.fields = function(o) {
	if(o == null) return new Array();
	var a = new Array();
	if(o.hasOwnProperty) {
		for(var i in o) if( o.hasOwnProperty(i) ) a.push(i);
	} else {
		var t;
		try {
			t = o.__proto__;
		} catch( e ) {
			t = null;
		}
		if(t != null) o.__proto__ = null;
		for(var i in o) if( i != "__proto__" ) a.push(i);
		if(t != null) o.__proto__ = t;
	}
	return a;
}
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && f.__name__ == null;
}
Reflect.compare = function(a,b) {
	return a == b?0:a > b?1:-1;
}
Reflect.compareMethods = function(f1,f2) {
	if(f1 == f2) return true;
	if(!Reflect.isFunction(f1) || !Reflect.isFunction(f2)) return false;
	return f1.scope == f2.scope && f1.method == f2.method && f1.method != null;
}
Reflect.isObject = function(v) {
	if(v == null) return false;
	var t = typeof(v);
	return t == "string" || t == "object" && !v.__enum__ || t == "function" && v.__name__ != null;
}
Reflect.deleteField = function(o,f) {
	if(!Reflect.hasField(o,f)) return false;
	delete(o[f]);
	return true;
}
Reflect.copy = function(o) {
	var o2 = { };
	var _g = 0, _g1 = Reflect.fields(o);
	while(_g < _g1.length) {
		var f = _g1[_g];
		++_g;
		o2[f] = Reflect.field(o,f);
	}
	return o2;
}
Reflect.makeVarArgs = function(f) {
	return function() {
		var a = new Array();
		var _g1 = 0, _g = arguments.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(arguments[i]);
		}
		return f(a);
	};
}
Reflect.prototype = {
	__class__: Reflect
}
var Std = $hxClasses["Std"] = function() { }
Std.__name__ = ["Std"];
Std["is"] = function(v,t) {
	return js.Boot.__instanceof(v,t);
}
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std["int"] = function(x) {
	return x | 0;
}
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && x.charCodeAt(1) == 120) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
}
Std.parseFloat = function(x) {
	return parseFloat(x);
}
Std.random = function(x) {
	return Math.floor(Math.random() * x);
}
Std.prototype = {
	__class__: Std
}
var StringBuf = $hxClasses["StringBuf"] = function() {
	this.b = new Array();
};
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		this.b[this.b.length] = x == null?"null":x;
	}
	,addSub: function(s,pos,len) {
		this.b[this.b.length] = s.substr(pos,len);
	}
	,addChar: function(c) {
		this.b[this.b.length] = String.fromCharCode(c);
	}
	,toString: function() {
		return this.b.join("");
	}
	,b: null
	,__class__: StringBuf
}
var StringTools = $hxClasses["StringTools"] = function() { }
StringTools.__name__ = ["StringTools"];
StringTools.urlEncode = function(s) {
	return encodeURIComponent(s);
}
StringTools.urlDecode = function(s) {
	return decodeURIComponent(s.split("+").join(" "));
}
StringTools.htmlEscape = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
}
StringTools.htmlUnescape = function(s) {
	return s.split("&gt;").join(">").split("&lt;").join("<").split("&amp;").join("&");
}
StringTools.startsWith = function(s,start) {
	return s.length >= start.length && s.substr(0,start.length) == start;
}
StringTools.endsWith = function(s,end) {
	var elen = end.length;
	var slen = s.length;
	return slen >= elen && s.substr(slen - elen,elen) == end;
}
StringTools.isSpace = function(s,pos) {
	var c = s.charCodeAt(pos);
	return c >= 9 && c <= 13 || c == 32;
}
StringTools.ltrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,r)) r++;
	if(r > 0) return s.substr(r,l - r); else return s;
}
StringTools.rtrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) r++;
	if(r > 0) return s.substr(0,l - r); else return s;
}
StringTools.trim = function(s) {
	return StringTools.ltrim(StringTools.rtrim(s));
}
StringTools.rpad = function(s,c,l) {
	var sl = s.length;
	var cl = c.length;
	while(sl < l) if(l - sl < cl) {
		s += c.substr(0,l - sl);
		sl = l;
	} else {
		s += c;
		sl += cl;
	}
	return s;
}
StringTools.lpad = function(s,c,l) {
	var ns = "";
	var sl = s.length;
	if(sl >= l) return s;
	var cl = c.length;
	while(sl < l) if(l - sl < cl) {
		ns += c.substr(0,l - sl);
		sl = l;
	} else {
		ns += c;
		sl += cl;
	}
	return ns + s;
}
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
}
StringTools.hex = function(n,digits) {
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(n & 15) + s;
		n >>>= 4;
	} while(n > 0);
	if(digits != null) while(s.length < digits) s = "0" + s;
	return s;
}
StringTools.fastCodeAt = function(s,index) {
	return s.cca(index);
}
StringTools.isEOF = function(c) {
	return c != c;
}
StringTools.prototype = {
	__class__: StringTools
}
var Xml = $hxClasses["Xml"] = function() {
};
Xml.__name__ = ["Xml"];
Xml.Element = null;
Xml.PCData = null;
Xml.CData = null;
Xml.Comment = null;
Xml.DocType = null;
Xml.Prolog = null;
Xml.Document = null;
Xml.parse = function(str) {
	var rules = [Xml.enode,Xml.epcdata,Xml.eend,Xml.ecdata,Xml.edoctype,Xml.ecomment,Xml.eprolog];
	var nrules = rules.length;
	var current = Xml.createDocument();
	var stack = new List();
	while(str.length > 0) {
		var i = 0;
		try {
			while(i < nrules) {
				var r = rules[i];
				if(r.match(str)) {
					switch(i) {
					case 0:
						var x = Xml.createElement(r.matched(1));
						current.addChild(x);
						str = r.matchedRight();
						while(Xml.eattribute.match(str)) {
							x.set(Xml.eattribute.matched(1),Xml.eattribute.matched(3));
							str = Xml.eattribute.matchedRight();
						}
						if(!Xml.eclose.match(str)) {
							i = nrules;
							throw "__break__";
						}
						if(Xml.eclose.matched(1) == ">") {
							stack.push(current);
							current = x;
						}
						str = Xml.eclose.matchedRight();
						break;
					case 1:
						var x = Xml.createPCData(r.matched(0));
						current.addChild(x);
						str = r.matchedRight();
						break;
					case 2:
						if(current._children != null && current._children.length == 0) {
							var e = Xml.createPCData("");
							current.addChild(e);
						}
						if(r.matched(1) != current._nodeName || stack.isEmpty()) {
							i = nrules;
							throw "__break__";
						}
						current = stack.pop();
						str = r.matchedRight();
						break;
					case 3:
						str = r.matchedRight();
						if(!Xml.ecdata_end.match(str)) throw "End of CDATA section not found";
						var x = Xml.createCData(Xml.ecdata_end.matchedLeft());
						current.addChild(x);
						str = Xml.ecdata_end.matchedRight();
						break;
					case 4:
						var pos = 0;
						var count = 0;
						var old = str;
						try {
							while(true) {
								if(!Xml.edoctype_elt.match(str)) throw "End of DOCTYPE section not found";
								var p = Xml.edoctype_elt.matchedPos();
								pos += p.pos + p.len;
								str = Xml.edoctype_elt.matchedRight();
								switch(Xml.edoctype_elt.matched(0)) {
								case "[":
									count++;
									break;
								case "]":
									count--;
									if(count < 0) throw "Invalid ] found in DOCTYPE declaration";
									break;
								default:
									if(count == 0) throw "__break__";
								}
							}
						} catch( e ) { if( e != "__break__" ) throw e; }
						var x = Xml.createDocType(old.substr(10,pos - 11));
						current.addChild(x);
						break;
					case 5:
						if(!Xml.ecomment_end.match(str)) throw "Unclosed Comment";
						var p = Xml.ecomment_end.matchedPos();
						var x = Xml.createComment(str.substr(4,p.pos + p.len - 7));
						current.addChild(x);
						str = Xml.ecomment_end.matchedRight();
						break;
					case 6:
						var prolog = r.matched(0);
						var x = Xml.createProlog(prolog.substr(2,prolog.length - 4));
						current.addChild(x);
						str = r.matchedRight();
						break;
					}
					throw "__break__";
				}
				i += 1;
			}
		} catch( e ) { if( e != "__break__" ) throw e; }
		if(i == nrules) {
			if(str.length > 10) throw "Xml parse error : Unexpected " + str.substr(0,10) + "..."; else throw "Xml parse error : Unexpected " + str;
		}
	}
	if(!stack.isEmpty()) throw "Xml parse error : Unclosed " + stack.last().getNodeName();
	return current;
}
Xml.createElement = function(name) {
	var r = new Xml();
	r.nodeType = Xml.Element;
	r._children = new Array();
	r._attributes = new Hash();
	r.setNodeName(name);
	return r;
}
Xml.createPCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.PCData;
	r.setNodeValue(data);
	return r;
}
Xml.createCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.CData;
	r.setNodeValue(data);
	return r;
}
Xml.createComment = function(data) {
	var r = new Xml();
	r.nodeType = Xml.Comment;
	r.setNodeValue(data);
	return r;
}
Xml.createDocType = function(data) {
	var r = new Xml();
	r.nodeType = Xml.DocType;
	r.setNodeValue(data);
	return r;
}
Xml.createProlog = function(data) {
	var r = new Xml();
	r.nodeType = Xml.Prolog;
	r.setNodeValue(data);
	return r;
}
Xml.createDocument = function() {
	var r = new Xml();
	r.nodeType = Xml.Document;
	r._children = new Array();
	return r;
}
Xml.prototype = {
	nodeType: null
	,nodeName: null
	,nodeValue: null
	,parent: null
	,_nodeName: null
	,_nodeValue: null
	,_attributes: null
	,_children: null
	,_parent: null
	,getNodeName: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName;
	}
	,setNodeName: function(n) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName = n;
	}
	,getNodeValue: function() {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue;
	}
	,setNodeValue: function(v) {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue = v;
	}
	,getParent: function() {
		return this._parent;
	}
	,get: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.get(att);
	}
	,set: function(att,value) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.set(att,value);
	}
	,remove: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.remove(att);
	}
	,exists: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.exists(att);
	}
	,attributes: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.keys();
	}
	,iterator: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			return this.cur < this.x.length;
		}, next : function() {
			return this.x[this.cur++];
		}};
	}
	,elements: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				if(this.x[k].nodeType == Xml.Element) break;
				k += 1;
			}
			this.cur = k;
			return k < l;
		}, next : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				var n = this.x[k];
				k += 1;
				if(n.nodeType == Xml.Element) {
					this.cur = k;
					return n;
				}
			}
			return null;
		}};
	}
	,elementsNamed: function(name) {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				var n = this.x[k];
				if(n.nodeType == Xml.Element && n._nodeName == name) break;
				k++;
			}
			this.cur = k;
			return k < l;
		}, next : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				var n = this.x[k];
				k++;
				if(n.nodeType == Xml.Element && n._nodeName == name) {
					this.cur = k;
					return n;
				}
			}
			return null;
		}};
	}
	,firstChild: function() {
		if(this._children == null) throw "bad nodetype";
		return this._children[0];
	}
	,firstElement: function() {
		if(this._children == null) throw "bad nodetype";
		var cur = 0;
		var l = this._children.length;
		while(cur < l) {
			var n = this._children[cur];
			if(n.nodeType == Xml.Element) return n;
			cur++;
		}
		return null;
	}
	,addChild: function(x) {
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) x._parent._children.remove(x);
		x._parent = this;
		this._children.push(x);
	}
	,removeChild: function(x) {
		if(this._children == null) throw "bad nodetype";
		var b = this._children.remove(x);
		if(b) x._parent = null;
		return b;
	}
	,insertChild: function(x,pos) {
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) x._parent._children.remove(x);
		x._parent = this;
		this._children.insert(pos,x);
	}
	,toString: function() {
		if(this.nodeType == Xml.PCData) return this._nodeValue;
		if(this.nodeType == Xml.CData) return "<![CDATA[" + this._nodeValue + "]]>";
		if(this.nodeType == Xml.Comment) return "<!--" + this._nodeValue + "-->";
		if(this.nodeType == Xml.DocType) return "<!DOCTYPE " + this._nodeValue + ">";
		if(this.nodeType == Xml.Prolog) return "<?" + this._nodeValue + "?>";
		var s = new StringBuf();
		if(this.nodeType == Xml.Element) {
			s.b[s.b.length] = "<";
			s.add(this._nodeName);
			var $it0 = this._attributes.keys();
			while( $it0.hasNext() ) {
				var k = $it0.next();
				s.b[s.b.length] = " ";
				s.b[s.b.length] = k == null?"null":k;
				s.b[s.b.length] = "=\"";
				s.add(this._attributes.get(k));
				s.b[s.b.length] = "\"";
			}
			if(this._children.length == 0) {
				s.b[s.b.length] = "/>";
				return s.b.join("");
			}
			s.b[s.b.length] = ">";
		}
		var $it1 = this.iterator();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			s.add(x.toString());
		}
		if(this.nodeType == Xml.Element) {
			s.b[s.b.length] = "</";
			s.add(this._nodeName);
			s.b[s.b.length] = ">";
		}
		return s.b.join("");
	}
	,__class__: Xml
	,__properties__: {get_parent:"getParent",set_nodeValue:"setNodeValue",get_nodeValue:"getNodeValue",set_nodeName:"setNodeName",get_nodeName:"getNodeName"}
}
var haxe = haxe || {}
haxe.FastList = $hxClasses["haxe.FastList"] = function() {
};
haxe.FastList.__name__ = ["haxe","FastList"];
haxe.FastList.prototype = {
	head: null
	,add: function(item) {
		this.head = new haxe.FastCell(item,this.head);
	}
	,first: function() {
		return this.head == null?null:this.head.elt;
	}
	,pop: function() {
		var k = this.head;
		if(k == null) return null; else {
			this.head = k.next;
			return k.elt;
		}
	}
	,isEmpty: function() {
		return this.head == null;
	}
	,remove: function(v) {
		var prev = null;
		var l = this.head;
		while(l != null) {
			if(l.elt == v) {
				if(prev == null) this.head = l.next; else prev.next = l.next;
				break;
			}
			prev = l;
			l = l.next;
		}
		return l != null;
	}
	,iterator: function() {
		var l = this.head;
		return { hasNext : function() {
			return l != null;
		}, next : function() {
			var k = l;
			l = k.next;
			return k.elt;
		}};
	}
	,toString: function() {
		var a = new Array();
		var l = this.head;
		while(l != null) {
			a.push(l.elt);
			l = l.next;
		}
		return "{" + a.join(",") + "}";
	}
	,__class__: haxe.FastList
}
var feffects = feffects || {}
feffects.Tween = $hxClasses["feffects.Tween"] = function(init,end,dur,_obj,_prop,easing) {
	this._initVal = init;
	this._endVal = end;
	this.duration = dur;
	this._offsetTime = 0;
	this._obj = _obj;
	this._prop = _prop;
	if(easing != null) this._easingF = easing; else if(Reflect.isFunction(_obj)) this._easingF = _obj; else this._easingF = this.easingEquation.$bind(this);
	this.isPlaying = false;
};
feffects.Tween.__name__ = ["feffects","Tween"];
feffects.Tween._timer = null;
feffects.Tween.AddTween = function(tween) {
	feffects.Tween._aTweens.add(tween);
	feffects.Tween._timer.run = feffects.Tween.DispatchTweens;
}
feffects.Tween.RemoveTween = function(tween) {
	if(tween == null || feffects.Tween._timer == null) return;
	feffects.Tween._aTweens.remove(tween);
	if(feffects.Tween._aTweens.head == null && feffects.Tween._aPaused.head == null) {
		feffects.Tween._timer.stop();
		feffects.Tween._timer = null;
	}
}
feffects.Tween.getActiveTweens = function() {
	return feffects.Tween._aTweens;
}
feffects.Tween.getPausedTweens = function() {
	return feffects.Tween._aPaused;
}
feffects.Tween.setTweenPaused = function(tween) {
	if(tween == null || feffects.Tween._timer == null) return;
	feffects.Tween._aPaused.add(tween);
	feffects.Tween._aTweens.remove(tween);
}
feffects.Tween.setTweenActive = function(tween) {
	if(tween == null || feffects.Tween._timer == null) return;
	feffects.Tween._aTweens.add(tween);
	feffects.Tween._aPaused.remove(tween);
}
feffects.Tween.DispatchTweens = function() {
	var $it0 = feffects.Tween._aTweens.iterator();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		i.doInterval();
	}
}
feffects.Tween.prototype = {
	duration: null
	,position: null
	,reversed: null
	,isPlaying: null
	,_initVal: null
	,_endVal: null
	,_startTime: null
	,_pauseTime: null
	,_offsetTime: null
	,_reverseTime: null
	,_easingF: null
	,_obj: null
	,_prop: null
	,start: function() {
		if(feffects.Tween._timer != null) feffects.Tween._timer.stop();
		feffects.Tween._timer = new haxe.Timer(10);
		this._startTime = Date.now().getTime();
		if(this.duration == 0) this.endTween(); else feffects.Tween.AddTween(this);
		this.isPlaying = true;
		this.position = 0;
		this._reverseTime = this._startTime;
		this.reversed = false;
	}
	,pause: function() {
		this._pauseTime = Date.now().getTime();
		feffects.Tween.setTweenPaused(this);
		this.isPlaying = false;
	}
	,resume: function() {
		this._startTime += Date.now().getTime() - this._pauseTime;
		this._reverseTime += Date.now().getTime() - this._pauseTime;
		feffects.Tween.setTweenActive(this);
		this.isPlaying = true;
	}
	,seek: function(ms) {
		this._offsetTime = ms;
	}
	,reverse: function() {
		this.reversed = !this.reversed;
		if(!this.reversed) this._startTime += (Date.now().getTime() - this._reverseTime) * 2;
		this._reverseTime = Date.now().getTime();
	}
	,stop: function() {
		feffects.Tween.RemoveTween(this);
		this.isPlaying = false;
	}
	,setTweenHandlers: function(update,end) {
		this.updateFunc = update;
		this.endFunc = end;
	}
	,setEasing: function(easingFunc) {
		if(easingFunc != null) this._easingF = easingFunc;
	}
	,updateFunc: function(e) {
	}
	,endFunc: function(e) {
	}
	,doInterval: function() {
		var stamp = Date.now().getTime();
		var curTime = 0;
		if(this.reversed) curTime = this._reverseTime * 2 - stamp - this._startTime + this._offsetTime; else curTime = stamp - this._startTime + this._offsetTime;
		var curVal = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
		if(curTime >= this.duration || curTime <= 0) this.endTween(); else {
			if(this.updateFunc.$bind(this) != null) this.updateFunc(curVal);
			if(this._prop != null) this._obj[this._prop] = curVal;
		}
		this.position = curTime;
	}
	,getCurVal: function(curTime) {
		return this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
	}
	,getStamp: function() {
		return Date.now().getTime();
	}
	,endTween: function() {
		feffects.Tween.RemoveTween(this);
		var val = 0.0;
		if(this.reversed) val = this._initVal; else val = this._endVal;
		if(this.updateFunc.$bind(this) != null) this.updateFunc(val);
		if(this.endFunc.$bind(this) != null) this.endFunc(val);
		if(this._prop != null) this._obj[this._prop] = val;
	}
	,easingEquation: function(t,b,c,d) {
		return c / 2 * (Math.sin(Math.PI * (t / d - 0.5)) + 1) + b;
	}
	,__class__: feffects.Tween
}
haxe.Public = $hxClasses["haxe.Public"] = function() { }
haxe.Public.__name__ = ["haxe","Public"];
haxe.Public.prototype = {
	__class__: haxe.Public
}
if(!feffects.easing) feffects.easing = {}
feffects.easing.Quart = $hxClasses["feffects.easing.Quart"] = function() { }
feffects.easing.Quart.__name__ = ["feffects","easing","Quart"];
feffects.easing.Quart.__interfaces__ = [haxe.Public];
feffects.easing.Quart.easeIn = function(t,b,c,d) {
	return c * (t /= d) * t * t * t + b;
}
feffects.easing.Quart.easeOut = function(t,b,c,d) {
	return -c * ((t = t / d - 1) * t * t * t - 1) + b;
}
feffects.easing.Quart.easeInOut = function(t,b,c,d) {
	if((t /= d * 0.5) < 1) return c * 0.5 * t * t * t * t + b; else return -c * 0.5 * ((t -= 2) * t * t * t - 2) + b;
}
feffects.easing.Quart.prototype = {
	__class__: feffects.easing.Quart
}
feffects.easing.Quint = $hxClasses["feffects.easing.Quint"] = function() { }
feffects.easing.Quint.__name__ = ["feffects","easing","Quint"];
feffects.easing.Quint.__interfaces__ = [haxe.Public];
feffects.easing.Quint.easeIn = function(t,b,c,d) {
	return c * (t /= d) * t * t * t * t + b;
}
feffects.easing.Quint.easeOut = function(t,b,c,d) {
	return c * ((t = t / d - 1) * t * t * t * t + 1) + b;
}
feffects.easing.Quint.easeInOut = function(t,b,c,d) {
	if((t /= d * 0.5) < 1) return c * 0.5 * t * t * t * t * t + b; else return c * 0.5 * ((t -= 2) * t * t * t * t + 2) + b;
}
feffects.easing.Quint.prototype = {
	__class__: feffects.easing.Quint
}
haxe.FastCell = $hxClasses["haxe.FastCell"] = function(elt,next) {
	this.elt = elt;
	this.next = next;
};
haxe.FastCell.__name__ = ["haxe","FastCell"];
haxe.FastCell.prototype = {
	elt: null
	,next: null
	,__class__: haxe.FastCell
}
haxe.Firebug = $hxClasses["haxe.Firebug"] = function() { }
haxe.Firebug.__name__ = ["haxe","Firebug"];
haxe.Firebug.detect = function() {
	try {
		return console != null && console.error != null;
	} catch( e ) {
		return false;
	}
}
haxe.Firebug.redirectTraces = function() {
	haxe.Log.trace = haxe.Firebug.trace;
	js.Lib.onerror = haxe.Firebug.onError;
}
haxe.Firebug.onError = function(err,stack) {
	var buf = err + "\n";
	var _g = 0;
	while(_g < stack.length) {
		var s = stack[_g];
		++_g;
		buf += "Called from " + s + "\n";
	}
	haxe.Firebug.trace(buf,null);
	return true;
}
haxe.Firebug.trace = function(v,inf) {
	var type = inf != null && inf.customParams != null?inf.customParams[0]:null;
	if(type != "warn" && type != "info" && type != "debug" && type != "error") type = inf == null?"error":"log";
	console[type]((inf == null?"":inf.fileName + ":" + inf.lineNumber + " : ") + Std.string(v));
}
haxe.Firebug.prototype = {
	__class__: haxe.Firebug
}
haxe.Http = $hxClasses["haxe.Http"] = function(url) {
	this.url = url;
	this.headers = new Hash();
	this.params = new Hash();
	this.async = true;
};
haxe.Http.__name__ = ["haxe","Http"];
haxe.Http.requestUrl = function(url) {
	var h = new haxe.Http(url);
	h.async = false;
	var r = null;
	h.onData = function(d) {
		r = d;
	};
	h.onError = function(e) {
		throw e;
	};
	h.request(false);
	return r;
}
haxe.Http.prototype = {
	url: null
	,async: null
	,postData: null
	,headers: null
	,params: null
	,setHeader: function(header,value) {
		this.headers.set(header,value);
	}
	,setParameter: function(param,value) {
		this.params.set(param,value);
	}
	,setPostData: function(data) {
		this.postData = data;
	}
	,request: function(post) {
		var me = this;
		var r = new js.XMLHttpRequest();
		var onreadystatechange = function() {
			if(r.readyState != 4) return;
			var s = (function($this) {
				var $r;
				try {
					$r = r.status;
				} catch( e ) {
					$r = null;
				}
				return $r;
			}(this));
			if(s == undefined) s = null;
			if(s != null) me.onStatus(s);
			if(s != null && s >= 200 && s < 400) me.onData(r.responseText); else switch(s) {
			case null: case undefined:
				me.onError("Failed to connect or resolve host");
				break;
			case 12029:
				me.onError("Failed to connect to host");
				break;
			case 12007:
				me.onError("Unknown host");
				break;
			default:
				me.onError("Http Error #" + r.status);
			}
		};
		if(this.async) r.onreadystatechange = onreadystatechange;
		var uri = this.postData;
		if(uri != null) post = true; else {
			var $it0 = this.params.keys();
			while( $it0.hasNext() ) {
				var p = $it0.next();
				if(uri == null) uri = ""; else uri += "&";
				uri += StringTools.urlEncode(p) + "=" + StringTools.urlEncode(this.params.get(p));
			}
		}
		try {
			if(post) r.open("POST",this.url,this.async); else if(uri != null) {
				var question = this.url.split("?").length <= 1;
				r.open("GET",this.url + (question?"?":"&") + uri,this.async);
				uri = null;
			} else r.open("GET",this.url,this.async);
		} catch( e ) {
			this.onError(e.toString());
			return;
		}
		if(this.headers.get("Content-Type") == null && post && this.postData == null) r.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		var $it1 = this.headers.keys();
		while( $it1.hasNext() ) {
			var h = $it1.next();
			r.setRequestHeader(h,this.headers.get(h));
		}
		r.send(uri);
		if(!this.async) onreadystatechange();
	}
	,onData: function(data) {
	}
	,onError: function(msg) {
	}
	,onStatus: function(status) {
	}
	,__class__: haxe.Http
}
haxe.Log = $hxClasses["haxe.Log"] = function() { }
haxe.Log.__name__ = ["haxe","Log"];
haxe.Log.trace = function(v,infos) {
	js.Boot.__trace(v,infos);
}
haxe.Log.clear = function() {
	js.Boot.__clear_trace();
}
haxe.Log.prototype = {
	__class__: haxe.Log
}
haxe.Timer = $hxClasses["haxe.Timer"] = function(time_ms) {
	var arr = haxe_timers;
	this.id = arr.length;
	arr[this.id] = this;
	this.timerId = window.setInterval("haxe_timers[" + this.id + "].run();",time_ms);
};
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
}
haxe.Timer.measure = function(f,pos) {
	var t0 = haxe.Timer.stamp();
	var r = f();
	haxe.Log.trace(haxe.Timer.stamp() - t0 + "s",pos);
	return r;
}
haxe.Timer.stamp = function() {
	return Date.now().getTime() / 1000;
}
haxe.Timer.prototype = {
	id: null
	,timerId: null
	,stop: function() {
		if(this.id == null) return;
		window.clearInterval(this.timerId);
		var arr = haxe_timers;
		arr[this.id] = null;
		if(this.id > 100 && this.id == arr.length - 1) {
			var p = this.id - 1;
			while(p >= 0 && arr[p] == null) p--;
			arr = arr.slice(0,p + 1);
		}
		this.id = null;
	}
	,run: function() {
	}
	,__class__: haxe.Timer
}
var js = js || {}
js.Boot = $hxClasses["js.Boot"] = function() { }
js.Boot.__name__ = ["js","Boot"];
js.Boot.__unhtml = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
}
js.Boot.__trace = function(v,i) {
	var msg = i != null?i.fileName + ":" + i.lineNumber + ": ":"";
	msg += js.Boot.__string_rec(v,"");
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML += js.Boot.__unhtml(msg) + "<br/>"; else if(typeof(console) != "undefined" && console.log != null) console.log(msg);
}
js.Boot.__clear_trace = function() {
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML = "";
}
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ != null || o.__ename__ != null)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__ != null) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2, _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i;
			var str = "[";
			s += "\t";
			var _g = 0;
			while(_g < l) {
				var i1 = _g++;
				str += (i1 > 0?",":"") + js.Boot.__string_rec(o[i1],s);
			}
			str += "]";
			return str;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) { ;
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
}
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0, _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
}
js.Boot.__instanceof = function(o,cl) {
	try {
		if(o instanceof cl) {
			if(cl == Array) return o.__enum__ == null;
			return true;
		}
		if(js.Boot.__interfLoop(o.__class__,cl)) return true;
	} catch( e ) {
		if(cl == null) return false;
	}
	switch(cl) {
	case Int:
		return Math.ceil(o%2147483648.0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return o === true || o === false;
	case String:
		return typeof(o) == "string";
	case Dynamic:
		return true;
	default:
		if(o == null) return false;
		return o.__enum__ == cl || cl == Class && o.__name__ != null || cl == Enum && o.__ename__ != null;
	}
}
js.Boot.__init = function() {
	js.Lib.isIE = typeof document!='undefined' && document.all != null && typeof window!='undefined' && window.opera == null;
	js.Lib.isOpera = typeof window!='undefined' && window.opera != null;
	Array.prototype.copy = Array.prototype.slice;
	Array.prototype.insert = function(i,x) {
		this.splice(i,0,x);
	};
	Array.prototype.remove = Array.prototype.indexOf?function(obj) {
		var idx = this.indexOf(obj);
		if(idx == -1) return false;
		this.splice(idx,1);
		return true;
	}:function(obj) {
		var i = 0;
		var l = this.length;
		while(i < l) {
			if(this[i] == obj) {
				this.splice(i,1);
				return true;
			}
			i++;
		}
		return false;
	};
	Array.prototype.iterator = function() {
		return { cur : 0, arr : this, hasNext : function() {
			return this.cur < this.arr.length;
		}, next : function() {
			return this.arr[this.cur++];
		}};
	};
	if(String.prototype.cca == null) String.prototype.cca = String.prototype.charCodeAt;
	String.prototype.charCodeAt = function(i) {
		var x = this.cca(i);
		if(x != x) return undefined;
		return x;
	};
	var oldsub = String.prototype.substr;
	String.prototype.substr = function(pos,len) {
		if(pos != null && pos != 0 && len != null && len < 0) return "";
		if(len == null) len = this.length;
		if(pos < 0) {
			pos = this.length + pos;
			if(pos < 0) pos = 0;
		} else if(len < 0) len = this.length + len - pos;
		return oldsub.apply(this,[pos,len]);
	};
	Function.prototype["$bind"] = function(o) {
		var f = function() {
			return f.method.apply(f.scope,arguments);
		};
		f.scope = o;
		f.method = this;
		return f;
	};
}
js.Boot.prototype = {
	__class__: js.Boot
}
js.Lib = $hxClasses["js.Lib"] = function() { }
js.Lib.__name__ = ["js","Lib"];
js.Lib.isIE = null;
js.Lib.isOpera = null;
js.Lib.document = null;
js.Lib.window = null;
js.Lib.alert = function(v) {
	alert(js.Boot.__string_rec(v,""));
}
js.Lib.eval = function(code) {
	return eval(code);
}
js.Lib.setErrorHandler = function(f) {
	js.Lib.onerror = f;
}
js.Lib.prototype = {
	__class__: js.Lib
}
var org = org || {}
if(!org.intermedia) org.intermedia = {}
org.intermedia.Application = $hxClasses["org.intermedia.Application"] = function() {
	var applicationModel = new org.intermedia.model.ApplicationModel();
	var applicationController = new org.intermedia.controller.ApplicationController(applicationModel);
	var view = new org.intermedia.view.ViewManager(applicationModel,applicationController);
};
org.intermedia.Application.__name__ = ["org","intermedia","Application"];
org.intermedia.Application.main = function() {
	new org.intermedia.Application();
}
org.intermedia.Application.prototype = {
	__class__: org.intermedia.Application
}
if(!org.intermedia.controller) org.intermedia.controller = {}
org.intermedia.controller.ApplicationController = $hxClasses["org.intermedia.controller.ApplicationController"] = function(applicationModel) {
	this._applicationModel = applicationModel;
};
org.intermedia.controller.ApplicationController.__name__ = ["org","intermedia","controller","ApplicationController"];
org.intermedia.controller.ApplicationController.prototype = {
	_applicationModel: null
	,loadCellData: function(feed) {
		this._applicationModel.loadCellData(feed);
	}
	,openDetailView: function(cellData) {
		this._applicationModel.loadDetailData(cellData);
	}
	,__class__: org.intermedia.controller.ApplicationController
}
if(!org.intermedia.model) org.intermedia.model = {}
org.intermedia.model.ApplicationModel = $hxClasses["org.intermedia.model.ApplicationModel"] = function() {
	this._online = false;
	this._loadedCellsData = new Array();
	this._loadedDetailData = new Array();
	this._dataLoader = new org.intermedia.model.DataLoader(this._online);
};
org.intermedia.model.ApplicationModel.__name__ = ["org","intermedia","model","ApplicationModel"];
org.intermedia.model.ApplicationModel.prototype = {
	onModelCellDataLoaded: null
	,onModelDetailDataLoaded: null
	,onModelDataLoadError: null
	,onModelStartsLoading: null
	,_dataLoader: null
	,_loadedCellsData: null
	,_loadedDetailData: null
	,_online: null
	,loadCellData: function(feed) {
		if(this._loadedCellsData.length == 0) {
			if(this.onModelStartsLoading != null) this.onModelStartsLoading();
		}
		this._dataLoader.loadCellData(feed,10,this.onCellsDataLoadComplete.$bind(this),this.onModelDataLoadError);
	}
	,loadDetailData: function(cellData) {
		if(this.onModelStartsLoading != null) this.onModelStartsLoading();
		this._dataLoader.loadDetailData(cellData,this.onDetailDataLoadComplete.$bind(this),this.onModelDataLoadError);
	}
	,onCellsDataLoadComplete: function(listData) {
		this._loadedCellsData = new Array();
		var _g = 0, _g1 = listData.cells;
		while(_g < _g1.length) {
			var cellData = _g1[_g];
			++_g;
			this._loadedCellsData.push(cellData);
		}
		if(this.onModelCellDataLoaded != null) this.onModelCellDataLoaded(listData);
	}
	,onDetailDataLoadComplete: function(detailData) {
		this._loadedDetailData.push(detailData);
		if(this.onModelDetailDataLoaded != null) this.onModelDetailDataLoaded(detailData);
	}
	,__class__: org.intermedia.model.ApplicationModel
}
org.intermedia.model.CellDetailsRss = $hxClasses["org.intermedia.model.CellDetailsRss"] = function() { }
org.intermedia.model.CellDetailsRss.__name__ = ["org","intermedia","model","CellDetailsRss"];
org.intermedia.model.CellDetailsRss.rss2CellDetail = function(rss,cellData) {
	var cell = { id : cellData.id, title : cellData.title, author : cellData.author, thumbUrl : cellData.thumbUrl, category : cellData.category, description : ""};
	var channelNode = rss.firstElement().firstElement();
	if(channelNode == null) return cell;
	var $it0 = channelNode.elements();
	while( $it0.hasNext() ) {
		var channelChild = $it0.next();
		if(channelChild.getNodeName() == "item") {
			var $it1 = channelChild.elements();
			while( $it1.hasNext() ) {
				var itemParam = $it1.next();
				if(itemParam.getNodeName() == "post_excerpt") {
					var text = itemParam.firstChild().getNodeValue();
					var toRemove = ["Online Demo","Online demo","Description :"];
					var _g = 0;
					while(_g < toRemove.length) {
						var string = toRemove[_g];
						++_g;
						text = StringTools.replace(text,string,"");
					}
					text = StringTools.ltrim(text);
					cell.description = text;
					break;
				}
			}
			return cell;
		}
	}
	return cell;
}
org.intermedia.model.CellDetailsRss.prototype = {
	__class__: org.intermedia.model.CellDetailsRss
}
org.intermedia.model.DataLoader = $hxClasses["org.intermedia.model.DataLoader"] = function(online) {
	if(online == null) online = true;
	this._pageIndex = 1;
	this._pageIndexHash = new Hash();
	this._online = online;
};
org.intermedia.model.DataLoader.__name__ = ["org","intermedia","model","DataLoader"];
org.intermedia.model.DataLoader.prototype = {
	onCellDataLoaded: null
	,onCellDetailLoaded: null
	,onLoadingError: null
	,_online: null
	,_itemsToLoad: null
	,_pageIndex: null
	,_pageIndexHash: null
	,loadCellData: function(feed,itemsPerPage,successCallback,errorCallback) {
		this.onCellDataLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var fullUrl = "";
		if(this._online) {
			var pageIndex = 1;
			if(this._pageIndexHash.exists(feed)) pageIndex = this._pageIndexHash.get(feed) + 1;
			this._pageIndexHash.set(feed,pageIndex);
			fullUrl = feed + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex;
		} else if(feed == { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url) fullUrl = "data/feed1.rss"; else if(feed == { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url) fullUrl = "data/feed2.rss"; else if(feed == { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url) fullUrl = "data/feed3.rss";
		var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,this.onCellsXmlLoaded.$bind(this),this.onLoadingError,feed);
	}
	,loadDetailData: function(cellData,successCallback,errorCallback) {
		var me = this;
		this.onCellDetailLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var onLoadSuccessDelegate = function(listId,xml) {
			me.onCellDetailXmlLoaded(xml,cellData);
		};
		var fullUrl = "";
		if(this._online) fullUrl = "http://www.silexlabs.org/feed/ep_get_item_info?format=rss2&p=" + cellData.id; else fullUrl = "data/detail.rss";
		var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,onLoadSuccessDelegate,this.onLoadingError);
	}
	,onCellsXmlLoaded: function(listId,xml) {
		this.onCellDataLoaded({ id : listId, cells : org.intermedia.model.ThumbTextListRssStandard.rss2Cells(xml)});
	}
	,onCellDetailXmlLoaded: function(xml,cellData) {
		this.onCellDetailLoaded(org.intermedia.model.CellDetailsRss.rss2CellDetail(xml,cellData));
	}
	,__class__: org.intermedia.model.DataLoader
}
org.intermedia.model.Feeds = $hxClasses["org.intermedia.model.Feeds"] = function() { }
org.intermedia.model.Feeds.__name__ = ["org","intermedia","model","Feeds"];
org.intermedia.model.Feeds.prototype = {
	__class__: org.intermedia.model.Feeds
}
org.intermedia.model.ThumbTextListRssStandard = $hxClasses["org.intermedia.model.ThumbTextListRssStandard"] = function() { }
org.intermedia.model.ThumbTextListRssStandard.__name__ = ["org","intermedia","model","ThumbTextListRssStandard"];
org.intermedia.model.ThumbTextListRssStandard.rss2Cells = function(rss) {
	var cells = new Array();
	var channelNode = rss.firstElement().firstElement();
	if(channelNode == null) return cells;
	var $it0 = channelNode.elements();
	while( $it0.hasNext() ) {
		var channelChild = $it0.next();
		if(channelChild.getNodeName() == "item") {
			var cell = { id : 0, title : "", author : "", thumbUrl : "", category : "", description : "", content : ""};
			var $it1 = channelChild.elements();
			while( $it1.hasNext() ) {
				var itemParam = $it1.next();
				if(itemParam.getNodeName() == "title") {
					var title = org.intermedia.model.ThumbTextListRssStandard.cleanText(itemParam.firstChild().getNodeValue());
					var index = title.indexOf("Name");
					if(index != -1) title = title.substr(0,index);
					title = StringTools.rtrim(title);
					cell.title = title;
				}
				if(itemParam.getNodeName() == "dc:creator") cell.author = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "description") {
					cell.description = org.intermedia.model.ThumbTextListRssStandard.cleanText(itemParam.firstChild().getNodeValue());
					cell.thumbUrl = org.intermedia.model.ThumbTextListRssStandard.getThumb(cell.description);
				}
				if(itemParam.getNodeName() == "content:encoded") {
					cell.content = org.intermedia.model.ThumbTextListRssStandard.cleanText(itemParam.firstChild().getNodeValue());
					if(cell.thumbUrl == "") cell.thumbUrl = org.intermedia.model.ThumbTextListRssStandard.getThumb(cell.content);
				}
			}
			if(cell.title != "" && cell.thumbUrl != "" && (cell.description != "" || cell.content != "")) cells.push(cell);
		}
	}
	return cells;
}
org.intermedia.model.ThumbTextListRssStandard.cleanText = function(text) {
	return StringTools.htmlUnescape(org.intermedia.model.ThumbTextListRssStandard.cleanCharCodes(text));
}
org.intermedia.model.ThumbTextListRssStandard.cleanCharCodes = function(text) {
	var charCodeStart = "&#";
	var charCodeEnd = ";";
	var charCodeStartPosition = 0;
	var charCodeEndPosition = 0;
	var charCode = 0;
	var charCodeString = "";
	var $char = "";
	var textEnd = "";
	charCodeStartPosition = text.indexOf(charCodeStart);
	while(charCodeStartPosition != -1) {
		charCodeString = text.substr(charCodeStartPosition + charCodeStart.length);
		charCodeEndPosition = charCodeString.indexOf(charCodeEnd);
		textEnd = charCodeString.substr(charCodeEndPosition + 1);
		charCodeString = charCodeString.substr(0,charCodeEndPosition);
		charCode = Std.parseInt(charCodeString);
		$char = String.fromCharCode(charCode);
		text = text.substr(0,charCodeStartPosition) + $char + textEnd;
		charCodeStartPosition = text.indexOf(charCodeStart);
	}
	return text;
	return text;
}
org.intermedia.model.ThumbTextListRssStandard.getThumb = function(htmlString) {
	var imgNodeStartIndex = htmlString.indexOf("<img ");
	var imgNode = "";
	var imgUrl = "";
	var imgUrlStartIndex = 0;
	if(imgNodeStartIndex != -1) {
		htmlString = htmlString.substr(imgNodeStartIndex);
		var imgNodeEndIndex = htmlString.indexOf(">") + 1;
		imgNode = htmlString.substr(0,imgNodeEndIndex);
		var srcKeyWord = "src=";
		imgUrlStartIndex = imgNode.indexOf(srcKeyWord);
		if(imgUrlStartIndex != -1) {
			var imgUrlDelimitor = imgNode.substr(imgUrlStartIndex + srcKeyWord.length,1);
			imgUrl = imgNode.substr(imgUrlStartIndex + srcKeyWord.length + 1);
			var imgUrlEndIndex = imgUrl.indexOf(imgUrlDelimitor);
			imgUrl = imgUrl.substr(0,imgUrlEndIndex);
			return imgUrl;
		}
	} else {
		imgUrlStartIndex = htmlString.indexOf("<p>http://");
		if(imgUrlStartIndex != -1) {
			var srcKeyWord = "<p>";
			imgUrl = htmlString.substr(imgUrlStartIndex + srcKeyWord.length);
			var imgUrlEndIndex = imgUrl.indexOf("</p>");
			imgUrl = imgUrl.substr(0,imgUrlEndIndex);
			return imgUrl;
		}
	}
	return "";
}
org.intermedia.model.ThumbTextListRssStandard.prototype = {
	__class__: org.intermedia.model.ThumbTextListRssStandard
}
org.intermedia.model.XmlLoader = $hxClasses["org.intermedia.model.XmlLoader"] = function(xmlUrl,online,successCallback,errorCallback,listId) {
	if(listId == null) listId = "";
	this._online = online;
	this.onLoadSuccess = successCallback;
	this.onLoadError = errorCallback;
	this.loadXmlFeed(listId,xmlUrl);
};
org.intermedia.model.XmlLoader.__name__ = ["org","intermedia","model","XmlLoader"];
org.intermedia.model.XmlLoader.prototype = {
	onLoadSuccess: null
	,onLoadError: null
	,_online: null
	,loadXmlFeed: function(listId,xmlUrl) {
		var me = this;
		var fullUrl = "";
		if(!this._online) fullUrl = xmlUrl; else fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);
		try {
			var httpRequest = new haxe.Http(fullUrl);
			httpRequest.onData = function(xml) {
				me.onXmlLoaded(listId,xml);
			};
			httpRequest.onError = this.onXmlError.$bind(this);
			httpRequest.request(false);
		} catch( error ) {
			this.onXmlError(error);
		}
	}
	,onXmlError: function(error) {
		if(this.onLoadError != null) this.onLoadError(error);
	}
	,onXmlLoaded: function(listId,xmlString) {
		var xml = Xml.parse(xmlString);
		if(this.onLoadSuccess != null) this.onLoadSuccess(listId,xml);
	}
	,__class__: org.intermedia.model.XmlLoader
}
if(!org.intermedia.view) org.intermedia.view = {}
org.intermedia.view.ViewBase = $hxClasses["org.intermedia.view.ViewBase"] = function() {
	this.node = js.Lib.document.createElement("div");
	this.setDisplayLoading(false);
	this.buildView();
};
org.intermedia.view.ViewBase.__name__ = ["org","intermedia","view","ViewBase"];
org.intermedia.view.ViewBase.prototype = {
	node: null
	,_data: null
	,data: null
	,displayLoading: null
	,_loadingView: null
	,getData: function() {
		return this._data;
	}
	,setData: function(v) {
		this._data = v;
		this.updateView();
		return this._data;
	}
	,setDisplayLoading: function(v) {
		if(v) {
			if(this._loadingView == null) this._loadingView = new org.intermedia.view.LoadingView();
			if(this._loadingView.node.parentNode == null) this.node.appendChild(this._loadingView.node);
		} else if(this._loadingView != null) {
			if(this._loadingView.node.parentNode != null) this.node.removeChild(this._loadingView.node);
		}
		return v;
	}
	,buildView: function() {
	}
	,updateView: function() {
	}
	,__class__: org.intermedia.view.ViewBase
	,__properties__: {set_displayLoading:"setDisplayLoading",set_data:"setData",get_data:"getData"}
}
org.intermedia.view.CellBase = $hxClasses["org.intermedia.view.CellBase"] = function(cellPerLine,cellStyle) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ViewBase.call(this);
	this._cellPerLine = cellPerLine;
	if(cellStyle != null) this._cellStyle = cellStyle; else this.initCellStyle();
	this._cellStyle.cell(this.node,cellPerLine);
};
org.intermedia.view.CellBase.__name__ = ["org","intermedia","view","CellBase"];
org.intermedia.view.CellBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CellBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	_cellStyle: null
	,_cellPerLine: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellStyle.setCellStyle, thumbnail : null, textBlock : null, title : null, author : null, line : null};
	}
	,refreshStyles: function() {
	}
	,__class__: org.intermedia.view.CellBase
});
org.intermedia.view.CellStyle = $hxClasses["org.intermedia.view.CellStyle"] = function() { }
org.intermedia.view.CellStyle.__name__ = ["org","intermedia","view","CellStyle"];
org.intermedia.view.CellStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	var cellWidthPercent = org.intermedia.view.CellStyle.computeWidthPercentage(cellPerLine);
	node.style.width = Std.string(cellWidthPercent) + "%";
	node.style.verticalAlign = "top";
	node.style.backgroundColor = "#FFFFFF";
}
org.intermedia.view.CellStyle.computeWidthPercentage = function(cellPerLine) {
	var cellWidthPercent = 100;
	if(cellPerLine != 0) {
		if(cellPerLine != 1) {
			cellWidthPercent = 100 / cellPerLine;
			cellWidthPercent -= 0.95;
		}
	}
	return cellWidthPercent;
}
org.intermedia.view.CellStyle.computeWidthPixels = function(cellPerLine) {
	var cellWidthPixels = js.Lib.window.innerWidth;
	if(cellPerLine != 0) cellWidthPixels = cellWidthPixels / cellPerLine | 0;
	return cellWidthPixels;
}
org.intermedia.view.CellStyle.addBorder = function(node) {
	node.style.margin = Std.string(1) + "px";
}
org.intermedia.view.CellStyle.removeBorder = function(node) {
	node.style.margin = "0px";
}
org.intermedia.view.CellStyle.prototype = {
	__class__: org.intermedia.view.CellStyle
}
org.intermedia.view.CellText = $hxClasses["org.intermedia.view.CellText"] = function() {
	org.intermedia.view.CellBase.call(this);
	org.intermedia.view.CellTextStyle.setCellStyle(this.node);
};
org.intermedia.view.CellText.__name__ = ["org","intermedia","view","CellText"];
org.intermedia.view.CellText.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellText.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	updateView: function() {
		var cellData = this._data;
		var cellTextContainer = js.Lib.document.createElement("div");
		if(cellData.title != "" && cellData.title != null) {
			var textElement = js.Lib.document.createTextNode(cellData.title);
			cellTextContainer.appendChild(textElement);
			org.intermedia.view.CellTextStyle.setCellTextStyle(cellTextContainer);
			this.node.appendChild(cellTextContainer);
		}
	}
	,__class__: org.intermedia.view.CellText
});
org.intermedia.view.CellTextStyle = $hxClasses["org.intermedia.view.CellTextStyle"] = function() { }
org.intermedia.view.CellTextStyle.__name__ = ["org","intermedia","view","CellTextStyle"];
org.intermedia.view.CellTextStyle.setCellStyle = function(node) {
	node.style.display = "block";
	node.style.position = "relative";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = Std.string(2) + "%";
	node.style.paddingRight = Std.string(2) + "%";
	node.style.paddingTop = Std.string(4) + "px";
	node.style.paddingBottom = Std.string(4) + "px";
	node.style.width = Std.string(96) + "%";
	org.intermedia.view.CellStyle.addBorder(node);
}
org.intermedia.view.CellTextStyle.setCellTextStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.fontSize = "15px";
	node.style.lineHeight = "normal";
	node.style.fontWeight = "bold";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.fontVariant = "normal";
	node.style.textTransform = "none";
	node.style.letterSpacing = "normal";
	node.style.wordSpacing = "normal";
	node.style.textIndent = "0px";
	node.style.whiteSpace = "normal";
	node.style.textAlign = "left";
	node.style.verticalAlign = "middle";
	node.style.color = "#666666";
}
org.intermedia.view.CellTextStyle.setCellLineStyle = function(node) {
	node.style.display = "block";
	node.style.position = "relative";
	node.style.width = "100%";
	node.style.height = Std.string(1) + "px";
	node.style.marginTop = Std.string(4) + "px";
}
org.intermedia.view.CellTextStyle.prototype = {
	__class__: org.intermedia.view.CellTextStyle
}
org.intermedia.view.CellThumb = $hxClasses["org.intermedia.view.CellThumb"] = function(cellPerLine,cellStyle,thumbWidthPercent) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine);
	this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine);
};
org.intermedia.view.CellThumb.__name__ = ["org","intermedia","view","CellThumb"];
org.intermedia.view.CellThumb.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumb.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_thumbMask: null
	,_mask: null
	,_croppedImage: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbStyle.setCellStyle};
	}
	,updateView: function() {
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._data.thumbUrl,this._thumbMask);
			this.node.appendChild(this._croppedImage.node);
		}
	}
	,refreshStyles: function() {
		this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(this._cellPerLine);
		this._croppedImage.resetStyle(this._thumbMask);
	}
	,__class__: org.intermedia.view.CellThumb
});
org.intermedia.view.CellThumbStyle = $hxClasses["org.intermedia.view.CellThumbStyle"] = function() { }
org.intermedia.view.CellThumbStyle.__name__ = ["org","intermedia","view","CellThumbStyle"];
org.intermedia.view.CellThumbStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellSize = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine);
	node.style.height = Std.string(cellSize.height) + "px";
	node.style.maxHeight = Std.string(150) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	return cellSize;
}
org.intermedia.view.CellThumbStyle.prototype = {
	__class__: org.intermedia.view.CellThumbStyle
}
org.intermedia.view.CellThumbText1 = $hxClasses["org.intermedia.view.CellThumbText1"] = function(cellPerLine,cellStyle) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine);
	this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine,35);
};
org.intermedia.view.CellThumbText1.__name__ = ["org","intermedia","view","CellThumbText1"];
org.intermedia.view.CellThumbText1.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumbText1.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_thumbMask: null
	,_mask: null
	,_croppedImage: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
	}
	,updateView: function() {
		org.intermedia.view.CellBase.prototype.updateView.call(this);
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._data.thumbUrl,this._thumbMask);
			this.node.appendChild(this._croppedImage.node);
		}
		var cellTextBlockContainer = js.Lib.document.createElement("div");
		this._cellStyle.textBlock(cellTextBlockContainer);
		this.node.appendChild(cellTextBlockContainer);
		if(this._data.title != "" && this._data.title != null) {
			var text = this._data.title;
			if(text.length > 40) text = text.substr(0,40) + "...";
			var textElement = js.Lib.document.createTextNode(text);
			var cellTitleContainer = js.Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
			this._cellStyle.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
	}
	,refreshStyles: function() {
		this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(this._cellPerLine,35);
		this._croppedImage.resetStyle(this._thumbMask);
	}
	,__class__: org.intermedia.view.CellThumbText1
});
org.intermedia.view.CellThumbText1Style = $hxClasses["org.intermedia.view.CellThumbText1Style"] = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = ["org","intermedia","view","CellThumbText1Style"];
org.intermedia.view.CellThumbText1Style.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellSize = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine,35);
	node.style.height = Std.string(cellSize.height) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	return cellSize;
}
org.intermedia.view.CellThumbText1Style.setTextBlockStyle = function(node) {
	node.style.display = "inline-block";
	node.style.marginLeft = "2%";
	node.style.verticalAlign = "top";
	node.style.width = Std.string(60) + "%";
}
org.intermedia.view.CellThumbText1Style.setTextStyle = function(node) {
	node.style.display = "block";
	node.style.color = "#202020";
	node.style.fontFamily = "Arial, sans-serif";
}
org.intermedia.view.CellThumbText1Style.setTitleStyle = function(node,screenResolutionSize) {
	org.intermedia.view.CellThumbText1Style.setTextStyle(node);
	if(screenResolutionSize == null) screenResolutionSize = org.intermedia.view.ScreenResolutionSize.small;
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	node.style.fontSize = Std.string(fontSize) + "px";
}
org.intermedia.view.CellThumbText1Style.setAuthorStyle = function(node,screenResolutionSize) {
	org.intermedia.view.CellThumbText1Style.setTextStyle(node);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "normal";
}
org.intermedia.view.CellThumbText1Style.setLineStyle = function(node) {
	node.style.display = "block";
	node.style.position = "relative";
	node.style.width = "100%";
	node.style.height = "1px";
	node.style.marginTop = Std.string(2) + "px";
}
org.intermedia.view.CellThumbText1Style.prototype = {
	__class__: org.intermedia.view.CellThumbText1Style
}
org.intermedia.view.Constants = $hxClasses["org.intermedia.view.Constants"] = function() { }
org.intermedia.view.Constants.__name__ = ["org","intermedia","view","Constants"];
org.intermedia.view.Constants.prototype = {
	__class__: org.intermedia.view.Constants
}
org.intermedia.view.CroppedImage = $hxClasses["org.intermedia.view.CroppedImage"] = function(imageUrl,maskSize) {
	this.node = js.Lib.document.createElement("div");
	this.node.style.width = Std.string(maskSize.width) + "px";
	this.node.style.height = Std.string(maskSize.height) + "px";
	this.node.style.overflowX = "hidden";
	this.node.style.overflowY = "hidden";
	this.node.style.display = "inline-block";
	this._image = js.Lib.document.createElement("img");
	this._maskSize = maskSize;
	this.loadThumb(imageUrl);
};
org.intermedia.view.CroppedImage.__name__ = ["org","intermedia","view","CroppedImage"];
org.intermedia.view.CroppedImage.prototype = {
	node: null
	,_image: null
	,_maskSize: null
	,loadThumb: function(imageUrl) {
		this._image.onload = this.onImageLoadSuccess.$bind(this);
		this._image.src = imageUrl;
	}
	,onImageLoadSuccess: function(event) {
		this._image.style.opacity = 0;
		this.node.appendChild(org.intermedia.view.ImageUtils.cropImage(this._image,this._maskSize));
		haxe.Timer.delay(this.fadeIn.$bind(this),Std.random(1000));
	}
	,fadeIn: function() {
		var tween = new feffects.Tween(0,1,400);
		tween.setTweenHandlers(this.tweenOpacity.$bind(this),this.tweenEnd.$bind(this));
		tween.start();
	}
	,tweenOpacity: function(e) {
		this._image.style.opacity = e;
	}
	,tweenEnd: function(e) {
	}
	,resetStyle: function(maskSize) {
		this._maskSize = maskSize;
		this.node.style.width = Std.string(maskSize.width) + "px";
		this.node.style.height = Std.string(maskSize.height) + "px";
		org.intermedia.view.ImageUtils.cropImage(this._image,this._maskSize);
	}
	,__class__: org.intermedia.view.CroppedImage
}
org.intermedia.view.DetailStyle = $hxClasses["org.intermedia.view.DetailStyle"] = function() { }
org.intermedia.view.DetailStyle.__name__ = ["org","intermedia","view","DetailStyle"];
org.intermedia.view.DetailStyle.setDetailStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "absolute";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "2%";
	node.style.paddingRight = "2%";
	node.style.paddingTop = "10px";
	node.style.paddingBottom = "10px";
	node.style.width = "96%";
	node.style.height = "auto";
	node.style.top = Std.string(43) + "px";
	node.style.bottom = "0px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "scroll";
}
org.intermedia.view.DetailStyle.setThumbnail = function(node) {
	var imageMaxWidth = 250;
	node.style.display = "block";
	node.style.maxWidth = Std.string(imageMaxWidth) + "px";
	node.style.maxHeight = "50%";
	node.style.width = "80%";
}
org.intermedia.view.DetailStyle.setText = function(node) {
	node.style.display = "block";
	node.style.color = "#202020";
	node.style.fontFamily = "Arial, sans-serif";
}
org.intermedia.view.DetailStyle.setTitle = function(node,screenResolutionSize) {
	org.intermedia.view.DetailStyle.setText(node);
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "bold";
}
org.intermedia.view.DetailStyle.setAuthor = function(node,screenResolutionSize) {
	org.intermedia.view.DetailStyle.setText(node);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "normal";
}
org.intermedia.view.DetailStyle.setDescription = function(node) {
	org.intermedia.view.DetailStyle.setText(node);
	node.style.marginTop = Std.string(10) + "px";
	node.style.marginBottom = Std.string(10) + "px";
	node.style.fontSize = "14px";
}
org.intermedia.view.DetailStyle.prototype = {
	__class__: org.intermedia.view.DetailStyle
}
org.intermedia.view.DetailView = $hxClasses["org.intermedia.view.DetailView"] = function() {
	this._titleElement = js.Lib.document.createTextNode("");
	this._authorElement = js.Lib.document.createTextNode("");
	this._descriptionElement = js.Lib.document.createTextNode("");
	this._contentElement = js.Lib.document.createTextNode("");
	org.intermedia.view.ViewBase.call(this);
	this._moveHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.vertical);
	this._moveHandler.onVerticalScroll = this.onVerticalMove.$bind(this);
};
org.intermedia.view.DetailView.__name__ = ["org","intermedia","view","DetailView"];
org.intermedia.view.DetailView.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.DetailView.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	_titleContainer: null
	,_titleElement: null
	,_authorContainer: null
	,_authorElement: null
	,_thumbnail: null
	,_descriptionContainer: null
	,_descriptionElement: null
	,_contentContainer: null
	,_contentElement: null
	,_moveHandler: null
	,buildView: function() {
		org.intermedia.view.DetailStyle.setDetailStyle(this.node);
		this._titleContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setTitle(this._titleContainer);
		this._titleContainer.appendChild(this._titleElement);
		this.node.appendChild(this._titleContainer);
		this._authorContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setAuthor(this._authorContainer);
		this._authorContainer.appendChild(this._authorElement);
		this.node.appendChild(this._authorContainer);
		this._descriptionContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setDescription(this._descriptionContainer);
		this._descriptionContainer.appendChild(this._descriptionElement);
		this.node.appendChild(this._descriptionContainer);
		this._contentContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setDescription(this._contentContainer);
		this._contentContainer.appendChild(this._contentElement);
		this.node.appendChild(this._contentContainer);
	}
	,updateView: function() {
		this._titleContainer.removeChild(this._titleElement);
		this._titleElement = js.Lib.document.createTextNode(this._data.title);
		this._titleContainer.appendChild(this._titleElement);
		this._authorContainer.removeChild(this._authorElement);
		this._authorElement = js.Lib.document.createTextNode(this._data.author);
		this._authorContainer.appendChild(this._authorElement);
		this.node.innerHTML += this._data.content;
	}
	,touchStart: function(event) {
		this._moveHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this.node.scrollTop};
		this._moveHandler.touchHandler(event);
	}
	,addTouchEvents: function() {
		this.node.addEventListener("touchstart",this.touchStart.$bind(this),false);
		this.node.addEventListener("touchmove",($_=this._moveHandler,$_.touchHandler.$bind($_)),false);
		this.node.addEventListener("touchend",($_=this._moveHandler,$_.touchHandler.$bind($_)),false);
		this.node.addEventListener("touchcancel",($_=this._moveHandler,$_.touchHandler.$bind($_)),false);
	}
	,onVerticalMove: function(y) {
		this.node.scrollTop = y;
	}
	,__class__: org.intermedia.view.DetailView
});
org.intermedia.view.HeaderStyle = $hxClasses["org.intermedia.view.HeaderStyle"] = function() { }
org.intermedia.view.HeaderStyle.__name__ = ["org","intermedia","view","HeaderStyle"];
org.intermedia.view.HeaderStyle.setHeaderStyle = function(node) {
	node.style.position = "fixed";
	node.style.display = "block";
	node.style.top = "0px";
	node.style.bottom = "auto";
	node.style.left = "0px";
	node.style.top = "0px";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = Std.string(43) + "px";
	node.style.backgroundImage = "url(" + "assets/headerGrey.jpg" + ")";
}
org.intermedia.view.HeaderStyle.setHeaderStaticStyle = function(node) {
	node.style.position = "static";
	node.style.display = "block";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = Std.string(43) + "px";
}
org.intermedia.view.HeaderStyle.setHeaderTextStyle = function(node) {
	node.style.position = "absolute";
	node.style.color = "#454545";
	node.style.fontSize = "20px";
	node.style.fontWeight = "bold";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.textAlign = "center";
	node.style.paddingTop = "8px";
	node.style.minWidth = "100%";
	node.style.top = "0px";
	node.style.width = "100%";
	node.style.height = "100%";
	node.style.verticalAlign = "middle";
}
org.intermedia.view.HeaderStyle.setBackButtonStyle = function(node) {
	node.style.position = "absolute";
	node.style.paddingTop = "6px";
	node.style.paddingLeft = "10px";
	node.style.top = "0px";
}
org.intermedia.view.HeaderStyle.setBackButtonTextStyle = function(node) {
	node.style.position = "absolute";
	node.style.color = "#EEEEEE";
	node.style.fontSize = "14px";
	node.style.lineHeight = "normal";
	node.style.fontWeight = "bold";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.textAlign = "center";
	node.style.paddingTop = "12px";
	node.style.paddingLeft = "30px";
	node.style.top = "0px";
	node.style.left = "0px";
}
org.intermedia.view.HeaderStyle.setBackButtonImageStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.top = "0px";
	node.style.left = "0px";
}
org.intermedia.view.HeaderStyle.setThumbImageStyle = function(node) {
	var THUMB_MARGIN = 5;
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.top = Std.string(THUMB_MARGIN) + "px";
	node.style.left = Std.string(2 * THUMB_MARGIN) + "px";
	node.style.width = Std.string(43 - 2 * THUMB_MARGIN) + "px";
	node.style.height = Std.string(43 - 2 * THUMB_MARGIN) + "px";
}
org.intermedia.view.HeaderStyle.prototype = {
	__class__: org.intermedia.view.HeaderStyle
}
org.intermedia.view.HeaderView = $hxClasses["org.intermedia.view.HeaderView"] = function() {
	org.intermedia.view.ViewBase.call(this);
	this._data = "";
	this._backButtonContainer = this.buildBackButtonView();
};
org.intermedia.view.HeaderView.__name__ = ["org","intermedia","view","HeaderView"];
org.intermedia.view.HeaderView.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.HeaderView.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onBackButtonClick: null
	,_displayBackButton: null
	,displayBackButton: null
	,_titleContainer: null
	,_titleTextElement: null
	,_image: null
	,_backButtonContainer: null
	,getDisplayBackButton: function() {
		return this._displayBackButton;
	}
	,setDisplayBackButton: function(v) {
		this._displayBackButton = v;
		if(this._displayBackButton) {
			this.node.removeChild(this._image);
			this.node.appendChild(this._backButtonContainer);
		} else if(this._backButtonContainer.parentNode != null) {
			this.node.removeChild(this._backButtonContainer);
			this.node.appendChild(this._image);
		}
		return this._displayBackButton;
	}
	,buildView: function() {
		org.intermedia.view.HeaderStyle.setHeaderStyle(this.node);
		this._image = js.Lib.document.createElement("img");
		org.intermedia.view.HeaderStyle.setThumbImageStyle(this._image);
		this._image.src = "assets/rss-icon.png";
		this.node.appendChild(this._image);
		this._titleTextElement = js.Lib.document.createTextNode(this._data);
		this._titleContainer = js.Lib.document.createElement("div");
		this._titleContainer.appendChild(this._titleTextElement);
		org.intermedia.view.HeaderStyle.setHeaderTextStyle(this._titleContainer);
		this.node.appendChild(this._titleContainer);
	}
	,updateView: function() {
		this._titleContainer.removeChild(this._titleTextElement);
		this._titleTextElement = js.Lib.document.createTextNode(this._data);
		this._titleContainer.appendChild(this._titleTextElement);
	}
	,buildBackButtonView: function() {
		var me = this;
		var backButtonContainer = js.Lib.document.createElement("div");
		org.intermedia.view.HeaderStyle.setBackButtonStyle(backButtonContainer);
		var backButtonArrowLeft = js.Lib.document.createElement("img");
		org.intermedia.view.HeaderStyle.setBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.src = "assets/blackButtonLeft.png";
		backButtonContainer.appendChild(backButtonArrowLeft);
		var backButtonArrowRight = js.Lib.document.createElement("img");
		org.intermedia.view.HeaderStyle.setBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.src = "assets/blackButtonRight.png";
		backButtonContainer.appendChild(backButtonArrowRight);
		var backButtonTextContainer = js.Lib.document.createElement("div");
		org.intermedia.view.HeaderStyle.setBackButtonTextStyle(backButtonTextContainer);
		var backButtonText = js.Lib.document.createTextNode("Back");
		backButtonTextContainer.appendChild(backButtonText);
		backButtonContainer.appendChild(backButtonTextContainer);
		backButtonContainer.onmouseup = function(event) {
			me.onBackButtonClickCallback();
		};
		return backButtonContainer;
	}
	,onBackButtonClickCallback: function() {
		if(this.onBackButtonClick != null) this.onBackButtonClick();
	}
	,__class__: org.intermedia.view.HeaderView
	,__properties__: $extend(org.intermedia.view.ViewBase.prototype.__properties__,{set_displayBackButton:"setDisplayBackButton",get_displayBackButton:"getDisplayBackButton"})
});
org.intermedia.view.HomePage = $hxClasses["org.intermedia.view.HomePage"] = function(initData) {
	this._data = initData;
	this.cells = new Array();
	org.intermedia.view.ViewBase.call(this);
};
org.intermedia.view.HomePage.__name__ = ["org","intermedia","view","HomePage"];
org.intermedia.view.HomePage.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.HomePage.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onListItemSelected: null
	,cells: null
	,buildView: function() {
		var me = this;
		var cell0Style = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : null, textBlock : null, title : null, author : null, line : null};
		var cell0 = new org.intermedia.view.CellThumb(1,cell0Style);
		cell0.setData(this._data[0]);
		cell0.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell0.getData());
		};
		this.node.appendChild(cell0.node);
		this.cells.push(cell0);
		var cell1 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell1.setData(this._data[1]);
		cell1.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell1.getData());
		};
		this.node.appendChild(cell1.node);
		this.cells.push(cell1);
		var cell2 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell2.setData(this._data[2]);
		cell2.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell2.getData());
		};
		this.node.appendChild(cell2.node);
		this.cells.push(cell2);
		var cell3 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell3.setData(this._data[3]);
		cell3.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell3.getData());
		};
		this.node.appendChild(cell3.node);
		this.cells.push(cell3);
		var cell4 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell4.setData(this._data[4]);
		cell4.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell4.getData());
		};
		this.node.appendChild(cell4.node);
		this.cells.push(cell4);
	}
	,loadThumb: function(url) {
		var image = js.Lib.document.createElement("img");
		image.style.verticalAlign = "middle";
		this.node.appendChild(image);
		image.src = url;
		return image;
	}
	,onListItemSelectedCallback: function(cellData) {
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	}
	,__class__: org.intermedia.view.HomePage
});
org.intermedia.view.ImageUtils = $hxClasses["org.intermedia.view.ImageUtils"] = function() { }
org.intermedia.view.ImageUtils.__name__ = ["org","intermedia","view","ImageUtils"];
org.intermedia.view.ImageUtils.computeMaskSize = function(cellPerLine,thumbWidthPercent) {
	if(thumbWidthPercent == null) thumbWidthPercent = 100;
	var maskPixelSize = { width : 0, height : 0};
	if(cellPerLine != 0) maskPixelSize.width = js.Lib.window.innerWidth * thumbWidthPercent / (cellPerLine * 100) | 0; else maskPixelSize.width = js.Lib.window.innerWidth * thumbWidthPercent / 100 | 0;
	maskPixelSize.height = 90;
	return maskPixelSize;
}
org.intermedia.view.ImageUtils.cropImage = function(image,maskSize) {
	var maskRatio = maskSize.width / maskSize.height;
	var imageRatio = 0;
	if(image.naturalHeight != 0) imageRatio = image.naturalWidth / image.naturalHeight;
	var resizedImageSize = { width : 0, height : 0};
	if(imageRatio > maskRatio) {
		resizedImageSize.height = maskSize.height;
		resizedImageSize.width = resizedImageSize.height * imageRatio | 0;
		image.style.width = Std.string(resizedImageSize.width) + "px";
		image.style.height = Std.string(resizedImageSize.height) + "px";
		image.style.marginTop = "0px";
		image.style.marginLeft = Std.string(-Math.abs(maskSize.width - resizedImageSize.width) / 2) + "px";
	} else {
		resizedImageSize.width = maskSize.width;
		resizedImageSize.height = resizedImageSize.width / imageRatio | 0;
		image.style.width = Std.string(resizedImageSize.width) + "px";
		image.style.height = Std.string(resizedImageSize.height) + "px";
		image.style.marginTop = Std.string(-Math.abs(maskSize.height - resizedImageSize.height) / 2) + "px";
		image.style.marginLeft = "0px";
	}
	return image;
}
org.intermedia.view.ImageUtils.prototype = {
	__class__: org.intermedia.view.ImageUtils
}
org.intermedia.view.ListViewBase = $hxClasses["org.intermedia.view.ListViewBase"] = function() {
	org.intermedia.view.ViewBase.call(this);
	org.intermedia.view.ListViewStyle.setListStyle(this.node);
	this.displayListBottomLoader = true;
	this._cells = new Array();
	this.buildBottomLoader();
	this.node.onscroll = this.onScrollCallback.$bind(this);
};
org.intermedia.view.ListViewBase.__name__ = ["org","intermedia","view","ListViewBase"];
org.intermedia.view.ListViewBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.ListViewBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onListItemSelected: null
	,onDataRequest: null
	,displayListBottomLoader: null
	,_cells: null
	,id: null
	,_listBottomLoader: null
	,buildBottomLoader: function() {
		var bottomLoaderImage = js.Lib.document.createElement("img");
		org.intermedia.view.ListViewStyle.loaderImage(bottomLoaderImage);
		bottomLoaderImage.src = "assets/loading.gif";
		this._listBottomLoader = js.Lib.document.createElement("div");
		this._listBottomLoader.appendChild(bottomLoaderImage);
		org.intermedia.view.CellStyle.setCellStyle(this._listBottomLoader);
	}
	,updateView: function() {
		var me = this;
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var index = _g1[_g];
			++_g;
			var cell = [this.createCell()];
			cell[0].setData(Reflect.field(this._data,index));
			cell[0].node.onmouseup = (function(cell) {
				return function(mouseEventData) {
					me.onListItemSelectedCallback(cell[0].getData());
				};
			})(cell);
			this._cells.push(cell[0]);
			this.node.appendChild(cell[0].node);
		}
		if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
		if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
	}
	,createCell: function() {
		var cell = new org.intermedia.view.CellBase();
		return cell;
	}
	,onListItemSelectedCallback: function(cellData) {
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	}
	,onScrollCallback: function(event) {
		if(this.node.scrollTop >= this.node.scrollHeight - js.Lib.window.innerHeight) this.onDataRequestCallback(this.id);
	}
	,onDataRequestCallback: function(id) {
		if(this.onDataRequest != null) this.onDataRequest(id);
	}
	,refreshStyles: function() {
		var _g = 0, _g1 = this._cells;
		while(_g < _g1.length) {
			var cell = _g1[_g];
			++_g;
			cell.refreshStyles();
		}
	}
	,__class__: org.intermedia.view.ListViewBase
});
org.intermedia.view.ListViewStyle = $hxClasses["org.intermedia.view.ListViewStyle"] = function() { }
org.intermedia.view.ListViewStyle.__name__ = ["org","intermedia","view","ListViewStyle"];
org.intermedia.view.ListViewStyle.setListStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	node.style.width = Std.string(100 / 3) + "%";
	node.style.height = Std.string(js.Lib.window.innerHeight) + "px";
	node.style.top = "0px";
	node.style.bottom = "0px";
	node.style.verticalAlign = "top";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
	node.style.backgroundColor = "#CCCCCC";
}
org.intermedia.view.ListViewStyle.loaderImage = function(node) {
	var VERTICAL_MARGIN = 20;
	node.style.display = "block";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.marginTop = Std.string(VERTICAL_MARGIN) + "px";
	node.style.marginBottom = Std.string(VERTICAL_MARGIN) + "px";
	node.style.top = Std.string(js.Lib.window.innerHeight) + "px";
}
org.intermedia.view.ListViewStyle.prototype = {
	__class__: org.intermedia.view.ListViewStyle
}
org.intermedia.view.ListViewText = $hxClasses["org.intermedia.view.ListViewText"] = function() {
	org.intermedia.view.ListViewBase.call(this);
};
org.intermedia.view.ListViewText.__name__ = ["org","intermedia","view","ListViewText"];
org.intermedia.view.ListViewText.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ListViewText.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	createCell: function() {
		var cell = new org.intermedia.view.CellText();
		return cell;
	}
	,refreshStyles: function() {
	}
	,__class__: org.intermedia.view.ListViewText
});
org.intermedia.view.LoadingView = $hxClasses["org.intermedia.view.LoadingView"] = function() {
	this.node = js.Lib.document.createElement("div");
	org.intermedia.view.LoadingViewStyle.setLoadingStyle(this.node);
	this.loadThumb();
};
org.intermedia.view.LoadingView.__name__ = ["org","intermedia","view","LoadingView"];
org.intermedia.view.LoadingView.prototype = {
	node: null
	,_viewStyle: null
	,loadThumb: function() {
		var image = js.Lib.document.createElement("img");
		org.intermedia.view.LoadingViewStyle.setThumbnailStyle(image);
		this.node.appendChild(image);
		image.src = "assets/loading.gif";
	}
	,__class__: org.intermedia.view.LoadingView
}
org.intermedia.view.LoadingViewStyle = $hxClasses["org.intermedia.view.LoadingViewStyle"] = function() { }
org.intermedia.view.LoadingViewStyle.__name__ = ["org","intermedia","view","LoadingViewStyle"];
org.intermedia.view.LoadingViewStyle.setLoadingStyle = function(node) {
	node.style.display = "block";
	node.style.position = "absolute";
	node.style.width = Std.string(js.Lib.window.innerWidth) + "px";
	node.style.height = Std.string(js.Lib.window.innerHeight) + "px";
	node.style.textAlign = "center";
	node.style.top = "0px";
	node.style.bottom = "0px";
	node.style.color = "#FFFFFF";
}
org.intermedia.view.LoadingViewStyle.setThumbnailStyle = function(node) {
	node.style.position = "relative";
	node.style.marginTop = "auto";
	node.style.marginBottom = "auto";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.top = "45%";
}
org.intermedia.view.LoadingViewStyle.prototype = {
	__class__: org.intermedia.view.LoadingViewStyle
}
org.intermedia.view.MenuCellText = $hxClasses["org.intermedia.view.MenuCellText"] = function() {
	org.intermedia.view.CellBase.call(this);
	org.intermedia.view.MenuCellTextStyle.setCellStyle(this.node);
};
org.intermedia.view.MenuCellText.__name__ = ["org","intermedia","view","MenuCellText"];
org.intermedia.view.MenuCellText.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.MenuCellText.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	updateView: function() {
		var cellData = this._data;
		var cellTextContainer = js.Lib.document.createElement("div");
		if(cellData.title != "" && cellData.title != null) {
			var textElement = js.Lib.document.createTextNode(cellData.title);
			cellTextContainer.appendChild(textElement);
			this.node.appendChild(cellTextContainer);
			org.intermedia.view.MenuCellTextStyle.setCellTextStyle(cellTextContainer);
		}
	}
	,__class__: org.intermedia.view.MenuCellText
});
org.intermedia.view.MenuCellTextStyle = $hxClasses["org.intermedia.view.MenuCellTextStyle"] = function() { }
org.intermedia.view.MenuCellTextStyle.__name__ = ["org","intermedia","view","MenuCellTextStyle"];
org.intermedia.view.MenuCellTextStyle.setCellStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "absolute";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = Std.string(5) + "px";
	node.style.paddingBottom = "0px";
	node.style.width = "auto";
	org.intermedia.view.CellStyle.removeBorder(node);
	node.style.backgroundColor = null;
}
org.intermedia.view.MenuCellTextStyle.setLeftCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.left = "0px";
}
org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.left = ((js.Lib.window.innerWidth - node.offsetWidth) / 2 | 0) + "px";
}
org.intermedia.view.MenuCellTextStyle.setRightCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.right = "0px";
}
org.intermedia.view.MenuCellTextStyle.setCellTextStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.paddingRight = Std.string(5) + "px";
	node.style.paddingLeft = Std.string(5) + "px";
	node.style.fontSize = "16px";
	node.style.lineHeight = "normal";
	node.style.fontWeight = "bold";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.fontVariant = "normal";
	node.style.textTransform = "none";
	node.style.letterSpacing = "normal";
	node.style.wordSpacing = "normal";
	node.style.textIndent = "0px";
	node.style.whiteSpace = "normal";
	node.style.verticalAlign = "middle";
	node.style.color = "#444444";
}
org.intermedia.view.MenuCellTextStyle.prototype = {
	__class__: org.intermedia.view.MenuCellTextStyle
}
org.intermedia.view.MenuListViewStyle = $hxClasses["org.intermedia.view.MenuListViewStyle"] = function() { }
org.intermedia.view.MenuListViewStyle.__name__ = ["org","intermedia","view","MenuListViewStyle"];
org.intermedia.view.MenuListViewStyle.setMenuStyle = function(node) {
	node.style.position = "fixed";
	node.style.display = "block";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = Std.string(35) + "px";
	node.style.top = Std.string(43) + "px";
	node.style.bottom = "auto";
	node.style.backgroundColor = null;
	node.style.backgroundImage = "url(" + "assets/headerBlue.png" + ")";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
}
org.intermedia.view.MenuListViewStyle.setListStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	node.style.width = "100%";
	node.style.height = "100%";
	node.style.backgroundColor = null;
}
org.intermedia.view.MenuListViewStyle.prototype = {
	__class__: org.intermedia.view.MenuListViewStyle
}
org.intermedia.view.MenuListViewText = $hxClasses["org.intermedia.view.MenuListViewText"] = function() {
	this._index = 0;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.MenuListViewStyle.setMenuStyle(this.node);
	this.displayListBottomLoader = false;
};
org.intermedia.view.MenuListViewText.__name__ = ["org","intermedia","view","MenuListViewText"];
org.intermedia.view.MenuListViewText.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.MenuListViewText.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_index: null
	,index: null
	,_menuItem0Width: null
	,_menuItem1Width: null
	,_menuItem2Width: null
	,_menuItem0LeftPos: null
	,_menuItem1LeftPos: null
	,_menuItem2LeftPos: null
	,_menuItem0LeftTarget: null
	,_menuItem1LeftTarget: null
	,_menuItem2LeftTarget: null
	,getIndex: function() {
		return this._index;
	}
	,setIndex: function(v) {
		this._index = v;
		this.computeMenuItemLeftTarget();
		var tween0 = new feffects.Tween(this._cells[0].node.offsetLeft,this._menuItem0LeftTarget,600,feffects.easing.Quint.easeOut);
		tween0.setTweenHandlers(this.menuItem0Move.$bind(this),this.menuItemMoveEnd.$bind(this));
		tween0.start();
		var tween1 = new feffects.Tween(this._cells[1].node.offsetLeft,this._menuItem1LeftTarget,600,feffects.easing.Quint.easeOut);
		tween1.setTweenHandlers(this.menuItem1Move.$bind(this),this.menuItemMoveEnd.$bind(this));
		tween1.start();
		var tween2 = new feffects.Tween(this._cells[2].node.offsetLeft,this._menuItem2LeftTarget,600,feffects.easing.Quint.easeOut);
		tween2.setTweenHandlers(this.menuItem2Move.$bind(this),this.menuItemMoveEnd.$bind(this));
		tween2.start();
		return v;
	}
	,computeMenuItemLeftTarget: function() {
		switch(this._index) {
		case 0:
			this._menuItem0LeftTarget = (js.Lib.window.innerWidth - this._menuItem0Width) / 2 | 0;
			this._menuItem1LeftTarget = js.Lib.window.innerWidth - this._menuItem1Width;
			this._menuItem2LeftTarget = js.Lib.window.innerWidth;
			break;
		case 1:
			this._menuItem0LeftTarget = 0;
			this._menuItem1LeftTarget = (js.Lib.window.innerWidth - this._menuItem1Width) / 2 | 0;
			this._menuItem2LeftTarget = js.Lib.window.innerWidth - this._menuItem2Width;
			break;
		case 2:
			this._menuItem0LeftTarget = -this._menuItem0Width;
			this._menuItem1LeftTarget = 0;
			this._menuItem2LeftTarget = (js.Lib.window.innerWidth - this._menuItem2Width) / 2 | 0;
			break;
		default:
			this._menuItem0LeftTarget = 0;
			this._menuItem1LeftTarget = 0;
			this._menuItem2LeftTarget = 0;
		}
	}
	,menuItem0Move: function(e) {
		this._cells[0].node.style.left = (e | 0) + "px";
	}
	,menuItem1Move: function(e) {
		this._cells[1].node.style.left = (e | 0) + "px";
	}
	,menuItem2Move: function(e) {
		this._cells[2].node.style.left = (e | 0) + "px";
	}
	,menuItemMoveEnd: function(e) {
		this.computeMenuItemsLeftPos();
	}
	,computeMenuItemsWidth: function() {
		this._menuItem0Width = this._cells[0].node.clientWidth;
		this._menuItem1Width = this._cells[1].node.clientWidth;
		this._menuItem2Width = this._cells[2].node.clientWidth;
	}
	,computeMenuItemsLeftPos: function() {
		this._menuItem0LeftPos = this._cells[0].node.offsetLeft;
		this._menuItem1LeftPos = this._cells[1].node.offsetLeft;
		this._menuItem2LeftPos = this._cells[2].node.offsetLeft;
	}
	,updateView: function() {
		var me = this;
		this._index = 0;
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var field = _g1[_g];
			++_g;
			var cell = [this.createCell()];
			cell[0].setData(Reflect.field(this._data,field));
			cell[0].node.onmouseup = (function(cell) {
				return function(mouseEventData) {
					me.onListItemSelectedCallback(cell[0].getData());
				};
			})(cell);
			this._cells.push(cell[0]);
			this.node.appendChild(cell[0].node);
			var style = this.setCellsStyle();
			style(cell[0].node);
			switch(this._index) {
			case 0:
				cell[0].node.id = "menu_item0";
				break;
			case 1:
				cell[0].node.id = "menu_item1";
				break;
			case 2:
				cell[0].node.id = "menu_item2";
				break;
			default:
			}
			this._index++;
		}
		this._index = 1;
		if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
		if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
		this.computeMenuItemsWidth();
		this.computeMenuItemsLeftPos();
	}
	,createCell: function() {
		var cell = new org.intermedia.view.MenuCellText();
		return cell;
	}
	,setCellsStyle: function() {
		var style = org.intermedia.view.MenuCellTextStyle.setCellStyle;
		switch(this._index) {
		case 0:
			style = org.intermedia.view.MenuCellTextStyle.setLeftCellStyle;
			break;
		case 1:
			style = org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle;
			break;
		case 2:
			style = org.intermedia.view.MenuCellTextStyle.setRightCellStyle;
			break;
		default:
		}
		return style;
	}
	,onListItemSelectedCallback: function(cellData) {
		this.setIndex(cellData.id);
		org.intermedia.view.ListViewBase.prototype.onListItemSelectedCallback.call(this,cellData);
	}
	,moveHorizontally: function(ratio) {
		this.menuItem0Move(this._menuItem0LeftPos + (js.Lib.window.innerWidth - this._menuItem0Width) * ratio / 2);
		this.menuItem1Move(this._menuItem1LeftPos + (js.Lib.window.innerWidth - this._menuItem1Width) * ratio / 2);
		this.menuItem2Move(this._menuItem2LeftPos + (js.Lib.window.innerWidth - this._menuItem2Width) * ratio / 2);
	}
	,horizontalUp: function(listIndex) {
		this.setIndex(listIndex);
	}
	,onResizeCallback: function(event) {
		this.computeMenuItemLeftTarget();
		this.menuItem0Move(this._menuItem0LeftTarget);
		this.menuItem1Move(this._menuItem1LeftTarget);
		this.menuItem2Move(this._menuItem2LeftTarget);
	}
	,__class__: org.intermedia.view.MenuListViewText
	,__properties__: $extend(org.intermedia.view.ListViewBase.prototype.__properties__,{set_index:"setIndex",get_index:"getIndex"})
});
org.intermedia.view.ScreenResolutionSize = $hxClasses["org.intermedia.view.ScreenResolutionSize"] = { __ename__ : ["org","intermedia","view","ScreenResolutionSize"], __constructs__ : ["small","normal","large"] }
org.intermedia.view.ScreenResolutionSize.small = ["small",0];
org.intermedia.view.ScreenResolutionSize.small.toString = $estr;
org.intermedia.view.ScreenResolutionSize.small.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolutionSize.normal = ["normal",1];
org.intermedia.view.ScreenResolutionSize.normal.toString = $estr;
org.intermedia.view.ScreenResolutionSize.normal.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolutionSize.large = ["large",2];
org.intermedia.view.ScreenResolutionSize.large.toString = $estr;
org.intermedia.view.ScreenResolutionSize.large.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolution = $hxClasses["org.intermedia.view.ScreenResolution"] = function() {
	if(js.Lib.window.innerWidth < 400) this.size = org.intermedia.view.ScreenResolutionSize.small; else if(js.Lib.window.innerWidth < 600) this.size = org.intermedia.view.ScreenResolutionSize.normal; else this.size = org.intermedia.view.ScreenResolutionSize.large;
};
org.intermedia.view.ScreenResolution.__name__ = ["org","intermedia","view","ScreenResolution"];
org.intermedia.view.ScreenResolution.prototype = {
	size: null
	,__class__: org.intermedia.view.ScreenResolution
}
org.intermedia.view.Scroll2D = $hxClasses["org.intermedia.view.Scroll2D"] = function(scrollType) {
	this._scrollType = scrollType;
	this._initialPosition = { x : 0, y : 0};
	this._offset = { x : 0, y : 0};
	this._scrollPosition = { x : 0, y : 0};
	this.initialScrollPosition = { x : 0, y : 0};
	this._direction = org.intermedia.view.Direction.notYetSet;
};
org.intermedia.view.Scroll2D.__name__ = ["org","intermedia","view","Scroll2D"];
org.intermedia.view.Scroll2D.prototype = {
	_offset: null
	,_initialPosition: null
	,initialScrollPosition: null
	,_scrollPosition: null
	,_scrollType: null
	,_direction: null
	,onHorizontalScroll: null
	,onVerticalScroll: null
	,onHorizontalUp: null
	,onHorizontalTween: null
	,_horizontalTween: null
	,_verticalTween: null
	,touchHandler: function(event) {
		switch(event.type) {
		case "touchstart":
			this.onDownCallback(event);
			break;
		case "touchmove":
			this.onMoveCallback(event);
			break;
		case "touchend":
			this.onUpCallback(event);
			break;
		default:
			return;
		}
	}
	,onDownCallback: function(event) {
		this.stopTweens();
		this._initialPosition.x = event.touches[0].pageX;
		this._initialPosition.y = event.touches[0].pageY;
		if(this._scrollType == org.intermedia.view.ScrollType.horizontal) this._direction = org.intermedia.view.Direction.horizontal; else if(this._scrollType == org.intermedia.view.ScrollType.vertical) this._direction = org.intermedia.view.Direction.vertical; else this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,onMoveCallback: function(event) {
		this._offset.x = event.touches[0].pageX - this._initialPosition.x | 0;
		this._offset.y = event.touches[0].pageY - this._initialPosition.y | 0;
		if(this._direction == org.intermedia.view.Direction.notYetSet) {
			var absX = Math.abs(this._offset.x);
			var absY = Math.abs(this._offset.y);
			if(Math.max(absX,absY) >= 5) {
				if(absX > absY) this._direction = org.intermedia.view.Direction.horizontal; else this._direction = org.intermedia.view.Direction.vertical;
			}
		}
		if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalMoveCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) {
			this.onVerticalMoveCallback(event);
			if(this._horizontalTween != null) this._horizontalTween.resume();
		}
	}
	,onHorizontalMoveCallback: function(event) {
		event.preventDefault();
		this._scrollPosition = { x : this.initialScrollPosition.x - this._offset.x, y : this.initialScrollPosition.x};
		this.onHorizontalScrollCallback(this._scrollPosition.x);
	}
	,onVerticalMoveCallback: function(event) {
		event.preventDefault();
		this._scrollPosition = { x : this.initialScrollPosition.x, y : this.initialScrollPosition.y - this._offset.y};
		this.onVerticalScrollCallback(this._scrollPosition.y);
	}
	,onUpCallback: function(event) {
		if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalUpCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) this.verticalReleaseTween();
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,onHorizontalUpCallback: function(event) {
		if(this.onHorizontalUp != null) this.onHorizontalUp(event,this._offset.x);
	}
	,horizontalReleaseTween: function(xOrigin,xTarget) {
		this._horizontalTween = new feffects.Tween(xOrigin,xTarget,600,feffects.easing.Quint.easeOut);
		this._horizontalTween.setTweenHandlers(this.onHorizontalTweenCallback.$bind(this),this.horizontalTweenEnd.$bind(this));
		this._horizontalTween.start();
	}
	,onHorizontalScrollCallback: function(e) {
		if(this.onHorizontalScroll != null) this.onHorizontalScroll(e | 0,this._offset.x);
	}
	,onHorizontalTweenCallback: function(e) {
		if(this.onHorizontalTween != null) this.onHorizontalTween(e | 0);
	}
	,horizontalTweenEnd: function(e) {
	}
	,verticalReleaseTween: function() {
		var verticalTweenEnd = 0;
		if(this._offset.y > 0) verticalTweenEnd = this._scrollPosition.y - 100; else verticalTweenEnd = this._scrollPosition.y + 100;
		this._verticalTween = new feffects.Tween(this._scrollPosition.y,verticalTweenEnd,600,feffects.easing.Quint.easeOut);
		this._verticalTween.setTweenHandlers(this.onVerticalScrollCallback.$bind(this),this.onVerticalTweenEnd.$bind(this));
		this._verticalTween.start();
	}
	,onVerticalScrollCallback: function(e) {
		if(this.onVerticalScroll != null) this.onVerticalScroll(e | 0);
	}
	,onVerticalTweenEnd: function(e) {
	}
	,stopTweens: function() {
		if(this._horizontalTween != null && this._horizontalTween.isPlaying) this._horizontalTween.pause();
		if(this._verticalTween != null && this._verticalTween.isPlaying) this._verticalTween.stop();
	}
	,__class__: org.intermedia.view.Scroll2D
}
org.intermedia.view.Direction = $hxClasses["org.intermedia.view.Direction"] = { __ename__ : ["org","intermedia","view","Direction"], __constructs__ : ["horizontal","vertical","notYetSet"] }
org.intermedia.view.Direction.horizontal = ["horizontal",0];
org.intermedia.view.Direction.horizontal.toString = $estr;
org.intermedia.view.Direction.horizontal.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.vertical = ["vertical",1];
org.intermedia.view.Direction.vertical.toString = $estr;
org.intermedia.view.Direction.vertical.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.notYetSet = ["notYetSet",2];
org.intermedia.view.Direction.notYetSet.toString = $estr;
org.intermedia.view.Direction.notYetSet.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.ScrollType = $hxClasses["org.intermedia.view.ScrollType"] = { __ename__ : ["org","intermedia","view","ScrollType"], __constructs__ : ["horizontal","vertical","both"] }
org.intermedia.view.ScrollType.horizontal = ["horizontal",0];
org.intermedia.view.ScrollType.horizontal.toString = $estr;
org.intermedia.view.ScrollType.horizontal.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.vertical = ["vertical",1];
org.intermedia.view.ScrollType.vertical.toString = $estr;
org.intermedia.view.ScrollType.vertical.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.both = ["both",2];
org.intermedia.view.ScrollType.both.toString = $estr;
org.intermedia.view.ScrollType.both.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.SwippableListView = $hxClasses["org.intermedia.view.SwippableListView"] = function() {
	org.intermedia.view.ListViewBase.call(this);
	this.setDisplayLoading(true);
	this._offset = { x : 0, y : 0};
	this._offsetStart = { x : 0, y : 0};
	this._initialPosition = { x : 0, y : 0};
	this._direction = org.intermedia.view.Direction.notYetSet;
	this._homePageData = new Array();
	this._homePageDataSet = false;
	this._listsContainer = js.Lib.document.createElement("div");
	org.intermedia.view.SwippableListViewStyle.setListsContainerStyle(this._listsContainer);
	this.node.appendChild(this._listsContainer);
	org.intermedia.view.SwippableListViewStyle.setSwippableListStyle(this.node);
	this._listViews = new Array();
	this.list0 = new org.intermedia.view.ListViewText();
	this.list0.id = { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url;
	this._listViews.push(this.list0);
	this.list1 = new org.intermedia.view.ThumbTextList1Bis(2);
	this.list1.id = { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url;
	this._listViews.push(this.list1);
	this.list2 = new org.intermedia.view.ThumbTextList1(2);
	this.list2.id = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url;
	this._listViews.push(this.list2);
	this.positionLists();
	var _g = 0, _g1 = this._listViews;
	while(_g < _g1.length) {
		var listView = _g1[_g];
		++_g;
		listView.onDataRequest = this.onDataRequestCallback.$bind(this);
		listView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._listsContainer.appendChild(listView.node);
	}
	this._index = 1;
	this._currentListView = this._listViews[this._index];
	this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
	this._moveHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.both);
	this._moveHandler.onVerticalScroll = this.onVerticalMove.$bind(this);
	this._moveHandler.onHorizontalScroll = this.onHorizontalMoveCallback.$bind(this);
	this._moveHandler.onHorizontalUp = this.onHorizontalUpCallback.$bind(this);
	this._moveHandler.onHorizontalTween = this.onHorizontalTweenCallback.$bind(this);
	this.addTouchEvents();
};
org.intermedia.view.SwippableListView.__name__ = ["org","intermedia","view","SwippableListView"];
org.intermedia.view.SwippableListView.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.SwippableListView.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_listsContainer: null
	,_listViews: null
	,list0: null
	,list1: null
	,list2: null
	,_list1Data: null
	,_currentListView: null
	,_index: null
	,index: null
	,_offset: null
	,_offsetStart: null
	,_initialPosition: null
	,_direction: null
	,_homePageData: null
	,_homePageDataSet: null
	,_moveHandler: null
	,onHorizontalMove: null
	,onHorizontalTweenEnd: null
	,onHorizontalUp: null
	,positionLists: function() {
		this.list1.node.style.left = Std.string(js.Lib.window.innerWidth) + "px";
		this.list2.node.style.left = Std.string(2 * js.Lib.window.innerWidth) + "px";
	}
	,setData: function(v) {
		this._data = v;
		var _g = 0, _g1 = this._listViews;
		while(_g < _g1.length) {
			var list = _g1[_g];
			++_g;
			if(v.id == list.id && v.id != this.list1.id) {
				if(this._homePageData.length < 6) {
					var _g2 = 0;
					while(_g2 < 3) {
						var i = _g2++;
						this._homePageData.push(this.getData().cells[i]);
					}
				}
				list.setData(v.cells);
				break;
			}
			if(v.id == this.list1.id) this._list1Data = v.cells;
		}
		if(!this._homePageDataSet && this._homePageData.length == 6) {
			this.list1.buildHomePage(this._homePageData);
			this._homePageDataSet = true;
			this.scrollToCurrentList();
			this.setDisplayLoading(false);
		}
		if(this._homePageDataSet) this.list1.setData(this._list1Data);
		return this._data;
	}
	,getIndex: function() {
		return this._index;
	}
	,setIndex: function(v) {
		this._currentListView.onListItemSelected = null;
		this._index = v;
		this._currentListView = this._listViews[v];
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._moveHandler.horizontalReleaseTween(this.node.scrollLeft,this._currentListView.node.offsetLeft);
		return v;
	}
	,scrollToCurrentList: function() {
		this.node.scrollLeft = Std.parseInt(this._currentListView.node.style.left.substr(0,-2));
	}
	,onResizeCallback: function(event) {
		this.positionLists();
		this.scrollToCurrentList();
		var _g = 0, _g1 = this._listViews;
		while(_g < _g1.length) {
			var list = _g1[_g];
			++_g;
			list.refreshStyles();
		}
	}
	,onHorizontalMoveCallback: function(XScroll,XOffset) {
		var horizontalRatio = this.computeHorizontalRatio(XOffset);
		this.node.scrollLeft = XScroll;
		if(this.onHorizontalMove != null && horizontalRatio != 0) this.onHorizontalMove(horizontalRatio);
	}
	,onHorizontalTweenCallback: function(XScroll) {
		this.node.scrollLeft = XScroll;
	}
	,onVerticalMove: function(y) {
		this._currentListView.node.scrollTop = y;
	}
	,onHorizontalUpCallback: function(event,XOffset) {
		event.preventDefault();
		if(XOffset < -js.Lib.window.innerHeight / 2) {
			if(this.getIndex() < this._listViews.length - 1) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 + 1);
				_g1;
			}
		} else if(XOffset > js.Lib.window.innerHeight / 2) {
			if(this.getIndex() > 0) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 - 1);
				_g1;
			}
		} else this.setIndex(this.getIndex());
		var horizontalRatio = this.computeHorizontalRatio(XOffset);
		if(this.onHorizontalUp != null) this.onHorizontalUp(this._index);
	}
	,onScrollCallback: function(event) {
	}
	,addTouchEvents: function() {
		this.node.addEventListener("touchstart",this.touchStart.$bind(this),false);
		this.node.addEventListener("touchmove",this.touchMove.$bind(this),false);
		this.node.addEventListener("touchend",this.touchEnd.$bind(this),false);
		this.node.addEventListener("touchcancel",($_=this._moveHandler,$_.touchHandler.$bind($_)),false);
	}
	,touchStart: function(event) {
		this._moveHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this._currentListView.node.scrollTop};
		this._moveHandler.touchHandler(event);
	}
	,touchMove: function(event) {
		this._currentListView.onListItemSelected = null;
		this._moveHandler.touchHandler(event);
	}
	,touchEnd: function(event) {
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._moveHandler.touchHandler(event);
	}
	,computeHorizontalRatio: function(XOffset) {
		var ratio = 0;
		if(js.Lib.window.innerHeight != 0) ratio = XOffset / js.Lib.window.innerHeight;
		return ratio;
	}
	,__class__: org.intermedia.view.SwippableListView
	,__properties__: $extend(org.intermedia.view.ListViewBase.prototype.__properties__,{set_index:"setIndex",get_index:"getIndex"})
});
org.intermedia.view.SwippableListViewStyle = $hxClasses["org.intermedia.view.SwippableListViewStyle"] = function() { }
org.intermedia.view.SwippableListViewStyle.__name__ = ["org","intermedia","view","SwippableListViewStyle"];
org.intermedia.view.SwippableListViewStyle.setSwippableListStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "absolute";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = Std.string(78) + "px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.width = "100%";
	node.style.height = "100%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
}
org.intermedia.view.SwippableListViewStyle.setListsContainerStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.width = "300%";
	node.style.height = "100%";
}
org.intermedia.view.SwippableListViewStyle.prototype = {
	__class__: org.intermedia.view.SwippableListViewStyle
}
org.intermedia.view.ThumbTextList1 = $hxClasses["org.intermedia.view.ThumbTextList1"] = function(cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	this._cellsPerLine = cellPerLine;
	org.intermedia.view.ListViewBase.call(this);
};
org.intermedia.view.ThumbTextList1.__name__ = ["org","intermedia","view","ThumbTextList1"];
org.intermedia.view.ThumbTextList1.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ThumbTextList1.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_cellsPerLine: null
	,createCell: function() {
		var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine);
		return cell;
	}
	,__class__: org.intermedia.view.ThumbTextList1
});
org.intermedia.view.ThumbTextList1Bis = $hxClasses["org.intermedia.view.ThumbTextList1Bis"] = function(cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ThumbTextList1.call(this,cellPerLine);
};
org.intermedia.view.ThumbTextList1Bis.__name__ = ["org","intermedia","view","ThumbTextList1Bis"];
org.intermedia.view.ThumbTextList1Bis.__super__ = org.intermedia.view.ThumbTextList1;
org.intermedia.view.ThumbTextList1Bis.prototype = $extend(org.intermedia.view.ThumbTextList1.prototype,{
	_homePage: null
	,buildHomePage: function(homePageData) {
		var homePage = new org.intermedia.view.HomePage(homePageData);
		homePage.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		var _g1 = 0, _g = homePage.cells.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._cells.push(homePage.cells[i]);
			this.node.appendChild(this._cells[i].node);
		}
	}
	,__class__: org.intermedia.view.ThumbTextList1Bis
});
org.intermedia.view.ViewManager = $hxClasses["org.intermedia.view.ViewManager"] = function(applicationModel,applicationController) {
	this._applicationModel = applicationModel;
	this._applicationController = applicationController;
	this._body = js.Lib.document.body;
	org.intermedia.view.ViewManagerStyle.setBodyStyle(this._body);
	this._header = new org.intermedia.view.HeaderView();
	this._header.setData("French Tech");
	this._header.onBackButtonClick = this.onHeaderBackButtonPressed.$bind(this);
	this._body.appendChild(this._header.node);
	this._menu = new org.intermedia.view.MenuListViewText();
	this._menu.displayListBottomLoader = false;
	this._body.appendChild(this._menu.node);
	this._menu.setData([{ id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"},{ id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"},{ id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}]);
	org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle(js.Lib.document.getElementById("menu_item1"));
	this._swippableListView = new org.intermedia.view.SwippableListView();
	this._currentView = this._swippableListView;
	this._body.appendChild(this._swippableListView.node);
	js.Lib.window.onresize = this.onResizeCallback.$bind(this);
	this.init();
};
org.intermedia.view.ViewManager.__name__ = ["org","intermedia","view","ViewManager"];
org.intermedia.view.ViewManager.prototype = {
	_body: null
	,_header: null
	,_menu: null
	,_swippableListView: null
	,_detailView: null
	,_applicationModel: null
	,_applicationController: null
	,_currentView: null
	,init: function() {
		this._applicationModel.onModelStartsLoading = this.onStartLoading.$bind(this);
		this._applicationModel.onModelDataLoadError = this.onLoadingError.$bind(this);
		this._applicationModel.onModelCellDataLoaded = this.onCellDataLoaded.$bind(this);
		this._applicationModel.onModelDetailDataLoaded = this.onDetailDataLoaded.$bind(this);
		this._menu.onListItemSelected = this.onMenuItemSelectedCallback.$bind(this);
		this._swippableListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._swippableListView.onDataRequest = ($_=this._applicationController,$_.loadCellData.$bind($_));
		this._swippableListView.onHorizontalMove = ($_=this._menu,$_.moveHorizontally.$bind($_));
		this._swippableListView.onHorizontalUp = ($_=this._menu,$_.horizontalUp.$bind($_));
		this._applicationController.loadCellData({ id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url);
		this._applicationController.loadCellData({ id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url);
		this._applicationController.loadCellData({ id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url);
	}
	,onMenuItemSelectedCallback: function(cellData) {
		this._swippableListView.setIndex(cellData.id);
	}
	,onListItemSelectedCallback: function(cellData) {
		this._body.removeChild(this._swippableListView.node);
		this._body.removeChild(this._menu.node);
		this._detailView = new org.intermedia.view.DetailView();
		this._body.appendChild(this._detailView.node);
		this._detailView.addTouchEvents();
		this._currentView = this._detailView;
		this.onDetailDataLoaded(cellData);
	}
	,onCellDataLoaded: function(listData) {
		if(listData.cells.length == 0) this._swippableListView.displayListBottomLoader = false;
		this._swippableListView.setData(listData);
		this.updateZIndexes();
	}
	,onDetailDataLoaded: function(detailData) {
		this._detailView.setData(detailData);
		this._header.setData("Infos");
		this._header.setDisplayBackButton(true);
		this.setZIndexToMax(this._header);
		this._detailView.setDisplayLoading(false);
	}
	,onStartLoading: function() {
	}
	,onLoadingError: function(error) {
		haxe.Firebug.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 234, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
	}
	,onHeaderBackButtonPressed: function() {
		this._header.setData("French Tech");
		this._header.setDisplayBackButton(false);
		this._body.removeChild(this._detailView.node);
		this._body.appendChild(this._menu.node);
		this._body.appendChild(this._swippableListView.node);
		this._swippableListView.scrollToCurrentList();
		this.updateZIndexes();
		this._currentView = this._swippableListView;
		this._swippableListView.addTouchEvents();
	}
	,updateZIndexes: function() {
		this.setZIndexToMax(this._menu);
		this.setZIndexToMax(this._header);
	}
	,setZIndexToMax: function(view) {
		this._body.removeChild(view.node);
		this._body.appendChild(view.node);
	}
	,onResizeCallback: function(event) {
		this._menu.onResizeCallback(event);
		this._swippableListView.onResizeCallback(event);
	}
	,__class__: org.intermedia.view.ViewManager
}
org.intermedia.view.ViewManagerStyle = $hxClasses["org.intermedia.view.ViewManagerStyle"] = function() { }
org.intermedia.view.ViewManagerStyle.__name__ = ["org","intermedia","view","ViewManagerStyle"];
org.intermedia.view.ViewManagerStyle.setBodyStyle = function(node) {
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	node.style.width = "100%";
	node.style.height = "130%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
}
org.intermedia.view.ViewManagerStyle.prototype = {
	__class__: org.intermedia.view.ViewManagerStyle
}
js.Boot.__res = {}
js.Boot.__init();
{
	var d = Date;
	d.now = function() {
		return new Date();
	};
	d.fromTime = function(t) {
		var d1 = new Date();
		d1["setTime"](t);
		return d1;
	};
	d.fromString = function(s) {
		switch(s.length) {
		case 8:
			var k = s.split(":");
			var d1 = new Date();
			d1["setTime"](0);
			d1["setUTCHours"](k[0]);
			d1["setUTCMinutes"](k[1]);
			d1["setUTCSeconds"](k[2]);
			return d1;
		case 10:
			var k = s.split("-");
			return new Date(k[0],k[1] - 1,k[2],0,0,0);
		case 19:
			var k = s.split(" ");
			var y = k[0].split("-");
			var t = k[1].split(":");
			return new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
		default:
			throw "Invalid date format : " + s;
		}
	};
	d.prototype["toString"] = function() {
		var date = this;
		var m = date.getMonth() + 1;
		var d1 = date.getDate();
		var h = date.getHours();
		var mi = date.getMinutes();
		var s = date.getSeconds();
		return date.getFullYear() + "-" + (m < 10?"0" + m:"" + m) + "-" + (d1 < 10?"0" + d1:"" + d1) + " " + (h < 10?"0" + h:"" + h) + ":" + (mi < 10?"0" + mi:"" + mi) + ":" + (s < 10?"0" + s:"" + s);
	};
	d.prototype.__class__ = $hxClasses["Date"] = d;
	d.__name__ = ["Date"];
}
{
	Math.__name__ = ["Math"];
	Math.NaN = Number["NaN"];
	Math.NEGATIVE_INFINITY = Number["NEGATIVE_INFINITY"];
	Math.POSITIVE_INFINITY = Number["POSITIVE_INFINITY"];
	$hxClasses["Math"] = Math;
	Math.isFinite = function(i) {
		return isFinite(i);
	};
	Math.isNaN = function(i) {
		return isNaN(i);
	};
}
{
	String.prototype.__class__ = $hxClasses["String"] = String;
	String.__name__ = ["String"];
	Array.prototype.__class__ = $hxClasses["Array"] = Array;
	Array.__name__ = ["Array"];
	var Int = $hxClasses["Int"] = { __name__ : ["Int"]};
	var Dynamic = $hxClasses["Dynamic"] = { __name__ : ["Dynamic"]};
	var Float = $hxClasses["Float"] = Number;
	Float.__name__ = ["Float"];
	var Bool = $hxClasses["Bool"] = Boolean;
	Bool.__ename__ = ["Bool"];
	var Class = $hxClasses["Class"] = { __name__ : ["Class"]};
	var Enum = { };
	var Void = $hxClasses["Void"] = { __ename__ : ["Void"]};
}
{
	Xml.Element = "element";
	Xml.PCData = "pcdata";
	Xml.CData = "cdata";
	Xml.Comment = "comment";
	Xml.DocType = "doctype";
	Xml.Prolog = "prolog";
	Xml.Document = "document";
}
if(typeof(haxe_timers) == "undefined") {
	var haxe_timers = [];
}
{
	if(typeof document != "undefined") js.Lib.document = document;
	if(typeof window != "undefined") {
		js.Lib.window = window;
		js.Lib.window.onerror = function(msg,url,line) {
			var f = js.Lib.onerror;
			if(f == null) return false;
			return f(msg,[url + ":" + line]);
		};
	}
}
js["XMLHttpRequest"] = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
	try {
		return new ActiveXObject("Msxml2.XMLHTTP");
	} catch( e ) {
		try {
			return new ActiveXObject("Microsoft.XMLHTTP");
		} catch( e1 ) {
			throw "Unable to create XMLHttpRequest object.";
		}
	}
}:(function($this) {
	var $r;
	throw "Unable to create XMLHttpRequest object.";
	return $r;
}(this));
Xml.enode = new EReg("^<([a-zA-Z0-9:._-]+)","");
Xml.ecdata = new EReg("^<!\\[CDATA\\[","i");
Xml.edoctype = new EReg("^<!DOCTYPE ","i");
Xml.eend = new EReg("^</([a-zA-Z0-9:._-]+)>","");
Xml.epcdata = new EReg("^[^<]+","");
Xml.ecomment = new EReg("^<!--","");
Xml.eprolog = new EReg("^<\\?[^\\?]+\\?>","");
Xml.eattribute = new EReg("^\\s*([a-zA-Z0-9:_-]+)\\s*=\\s*([\"'])([^\\2]*?)\\2","");
Xml.eclose = new EReg("^[ \r\n\t]*(>|(/>))","");
Xml.ecdata_end = new EReg("\\]\\]>","");
Xml.edoctype_elt = new EReg("[\\[|\\]>]","");
Xml.ecomment_end = new EReg("-->","");
feffects.Tween._aTweens = new haxe.FastList();
feffects.Tween._aPaused = new haxe.FastList();
feffects.Tween.INTERVAL = 10;
js.Lib.onerror = null;
org.intermedia.model.ApplicationModel.CELL_QTY = 10;
org.intermedia.model.Feeds.FEED_1 = { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"};
org.intermedia.model.Feeds.FEED_2 = { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"};
org.intermedia.model.Feeds.FEED_3 = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"};
org.intermedia.view.CellTextStyle.CELL_VERTICAL_SPACE = 4;
org.intermedia.view.CellTextStyle.CELL_HORIZONTAL_SPACE = 2;
org.intermedia.view.CellThumbStyle.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbStyle.CELL_RATIO = 16 / 9;
org.intermedia.view.CellThumbStyle.CELL_MAX_HEIGHT = 150;
org.intermedia.view.CellThumbStyle.CELL_HEIGHT = 100;
org.intermedia.view.CellThumbText1.TITLE_LENGTH = 40;
org.intermedia.view.CellThumbText1Style.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbText1Style.CELL_TEXT_WIDTH_PERCENT = 60;
org.intermedia.view.CellThumbText1Style.CELL_THUMB_WIDTH_PERCENT = 35;
org.intermedia.view.Constants.HEADER_HOME_TITLE = "French Tech";
org.intermedia.view.Constants.HEADER_DETAIL_TITLE = "Infos";
org.intermedia.view.Constants.HEADER_BG_IMAGE_URL = "assets/headerGrey.jpg";
org.intermedia.view.Constants.HEADER_HEIGHT = 43;
org.intermedia.view.Constants.MENU_BG_IMAGE_URL = "assets/headerBlue.png";
org.intermedia.view.Constants.MENU_HEIGHT = 35;
org.intermedia.view.Constants.LIST_TOP = 78;
org.intermedia.view.Constants.LIST_BG_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_BG_COLOR = "#FFFFFF";
org.intermedia.view.Constants.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.Constants.CELL_BORDER_WIDTH = 1;
org.intermedia.view.Constants.CELL_BORDER_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_HEIGHT = 90;
org.intermedia.view.HeaderView.IMAGE_URL = "assets/rss-icon.png";
org.intermedia.view.LoadingViewStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_HORIZONTAL_PADDING = 5;
org.intermedia.view.Scroll2D.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.Scroll2D.VERTICAL_TWEEN_DELTA = 100;
org.intermedia.view.SwippableListView.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEM_PER_LIST = 3;
org.intermedia.view.SwippableListView.LIST_QTY = 2;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEMS = 6;
org.intermedia.Application.main()