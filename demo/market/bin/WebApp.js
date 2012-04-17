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
var ValueType = $hxClasses["ValueType"] = { __ename__ : ["ValueType"], __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] }
ValueType.TNull = ["TNull",0];
ValueType.TNull.toString = $estr;
ValueType.TNull.__enum__ = ValueType;
ValueType.TInt = ["TInt",1];
ValueType.TInt.toString = $estr;
ValueType.TInt.__enum__ = ValueType;
ValueType.TFloat = ["TFloat",2];
ValueType.TFloat.toString = $estr;
ValueType.TFloat.__enum__ = ValueType;
ValueType.TBool = ["TBool",3];
ValueType.TBool.toString = $estr;
ValueType.TBool.__enum__ = ValueType;
ValueType.TObject = ["TObject",4];
ValueType.TObject.toString = $estr;
ValueType.TObject.__enum__ = ValueType;
ValueType.TFunction = ["TFunction",5];
ValueType.TFunction.toString = $estr;
ValueType.TFunction.__enum__ = ValueType;
ValueType.TClass = function(c) { var $x = ["TClass",6,c]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; }
ValueType.TEnum = function(e) { var $x = ["TEnum",7,e]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; }
ValueType.TUnknown = ["TUnknown",8];
ValueType.TUnknown.toString = $estr;
ValueType.TUnknown.__enum__ = ValueType;
var Type = $hxClasses["Type"] = function() { }
Type.__name__ = ["Type"];
Type.getClass = function(o) {
	if(o == null) return null;
	if(o.__enum__ != null) return null;
	return o.__class__;
}
Type.getEnum = function(o) {
	if(o == null) return null;
	return o.__enum__;
}
Type.getSuperClass = function(c) {
	return c.__super__;
}
Type.getClassName = function(c) {
	var a = c.__name__;
	return a.join(".");
}
Type.getEnumName = function(e) {
	var a = e.__ename__;
	return a.join(".");
}
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || cl.__name__ == null) return null;
	return cl;
}
Type.resolveEnum = function(name) {
	var e = $hxClasses[name];
	if(e == null || e.__ename__ == null) return null;
	return e;
}
Type.createInstance = function(cl,args) {
	switch(args.length) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw "Too many arguments";
	}
	return null;
}
Type.createEmptyInstance = function(cl) {
	function empty() {}; empty.prototype = cl.prototype;
	return new empty();
}
Type.createEnum = function(e,constr,params) {
	var f = Reflect.field(e,constr);
	if(f == null) throw "No such constructor " + constr;
	if(Reflect.isFunction(f)) {
		if(params == null) throw "Constructor " + constr + " need parameters";
		return f.apply(e,params);
	}
	if(params != null && params.length != 0) throw "Constructor " + constr + " does not need parameters";
	return f;
}
Type.createEnumIndex = function(e,index,params) {
	var c = e.__constructs__[index];
	if(c == null) throw index + " is not a valid enum constructor index";
	return Type.createEnum(e,c,params);
}
Type.getInstanceFields = function(c) {
	var a = [];
	for(var i in c.prototype) a.push(i);
	a.remove("__class__");
	a.remove("__properties__");
	return a;
}
Type.getClassFields = function(c) {
	var a = Reflect.fields(c);
	a.remove("__name__");
	a.remove("__interfaces__");
	a.remove("__properties__");
	a.remove("__super__");
	a.remove("prototype");
	return a;
}
Type.getEnumConstructs = function(e) {
	var a = e.__constructs__;
	return a.copy();
}
Type["typeof"] = function(v) {
	switch(typeof(v)) {
	case "boolean":
		return ValueType.TBool;
	case "string":
		return ValueType.TClass(String);
	case "number":
		if(Math.ceil(v) == v % 2147483648.0) return ValueType.TInt;
		return ValueType.TFloat;
	case "object":
		if(v == null) return ValueType.TNull;
		var e = v.__enum__;
		if(e != null) return ValueType.TEnum(e);
		var c = v.__class__;
		if(c != null) return ValueType.TClass(c);
		return ValueType.TObject;
	case "function":
		if(v.__name__ != null) return ValueType.TObject;
		return ValueType.TFunction;
	case "undefined":
		return ValueType.TNull;
	default:
		return ValueType.TUnknown;
	}
}
Type.enumEq = function(a,b) {
	if(a == b) return true;
	try {
		if(a[0] != b[0]) return false;
		var _g1 = 2, _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(!Type.enumEq(a[i],b[i])) return false;
		}
		var e = a.__enum__;
		if(e != b.__enum__ || e == null) return false;
	} catch( e ) {
		return false;
	}
	return true;
}
Type.enumConstructor = function(e) {
	return e[0];
}
Type.enumParameters = function(e) {
	return e.slice(2);
}
Type.enumIndex = function(e) {
	return e[1];
}
Type.allEnums = function(e) {
	var all = [];
	var cst = e.__constructs__;
	var _g = 0;
	while(_g < cst.length) {
		var c = cst[_g];
		++_g;
		var v = Reflect.field(e,c);
		if(!Reflect.isFunction(v)) all.push(v);
	}
	return all;
}
Type.prototype = {
	__class__: Type
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
var cocktail = cocktail || {}
cocktail.Lib = $hxClasses["cocktail.Lib"] = function() {
};
cocktail.Lib.__name__ = ["cocktail","Lib"];
cocktail.Lib.__properties__ = {get_window:"get_window",get_document:"get_document"}
cocktail.Lib._document = null;
cocktail.Lib.document = null;
cocktail.Lib._window = null;
cocktail.Lib.window = null;
cocktail.Lib.init = function() {
	cocktail.Lib._document = new cocktail.port.browser.HTMLDocument();
	cocktail.Lib._window = new cocktail.port.browser.Window(cocktail.Lib._document);
}
cocktail.Lib.get_document = function() {
	if(cocktail.Lib._document == null) cocktail.Lib.init();
	return cocktail.Lib._document;
}
cocktail.Lib.get_window = function() {
	if(cocktail.Lib._window == null) cocktail.Lib.init();
	return cocktail.Lib._window;
}
cocktail.Lib.prototype = {
	__class__: cocktail.Lib
}
if(!cocktail.core) cocktail.core = {}
if(!cocktail.core.drawing) cocktail.core.drawing = {}
cocktail.core.drawing.AbstractDrawingManager = $hxClasses["cocktail.core.drawing.AbstractDrawingManager"] = function(nativeElement,width,height) {
	this._nativeElement = nativeElement;
	this._width = width;
	this._height = height;
};
cocktail.core.drawing.AbstractDrawingManager.__name__ = ["cocktail","core","drawing","AbstractDrawingManager"];
cocktail.core.drawing.AbstractDrawingManager.prototype = {
	_nativeElement: null
	,nativeElement: null
	,_width: null
	,width: null
	,_height: null
	,height: null
	,beginFill: function(fillStyle,lineStyle) {
		if(fillStyle == null) fillStyle = cocktail.core.dom.FillStyleValue.none;
		if(lineStyle == null) lineStyle = cocktail.core.dom.LineStyleValue.none;
		this.setFillStyle(fillStyle);
		this.setLineStyle(lineStyle);
	}
	,endFill: function() {
	}
	,clear: function() {
	}
	,setLineStyle: function(lineStyle) {
	}
	,setFillStyle: function(fillStyle) {
	}
	,drawRect: function(x,y,width,height,cornerRadiuses) {
		if(cornerRadiuses == null) cornerRadiuses = { tlCornerRadius : 0, trCornerRadius : 0, blCornerRadius : 0, brCornerRadius : 0};
		this.moveTo(cornerRadiuses.tlCornerRadius + x,y);
		this.lineTo(width - cornerRadiuses.trCornerRadius + x,y);
		this.curveTo(width + x,y,width + x,cornerRadiuses.trCornerRadius + y);
		this.lineTo(width + x,cornerRadiuses.trCornerRadius + y);
		this.lineTo(width + x,height - cornerRadiuses.brCornerRadius + y);
		this.curveTo(width + x,height + y,width - cornerRadiuses.brCornerRadius + x,height + y);
		this.lineTo(width - cornerRadiuses.brCornerRadius + x,height + y);
		this.lineTo(cornerRadiuses.blCornerRadius + x,height + y);
		this.curveTo(x,height + y,x,height - cornerRadiuses.blCornerRadius + y);
		this.lineTo(x,height - cornerRadiuses.blCornerRadius + y);
		this.lineTo(x,cornerRadiuses.tlCornerRadius + y);
		this.curveTo(x,y,cornerRadiuses.tlCornerRadius + x,y);
		this.lineTo(cornerRadiuses.tlCornerRadius + x,y);
	}
	,drawEllipse: function(x,y,width,height) {
		var xRadius = width / 2;
		var yRadius = height / 2;
		var xCenter = width / 2 + x;
		var yCenter = height / 2 + y;
		var angleDelta = Math.PI / 4;
		var xCtrlDist = xRadius / Math.cos(angleDelta / 2);
		var yCtrlDist = yRadius / Math.cos(angleDelta / 2);
		this.moveTo(xCenter + xRadius,yCenter);
		var angle = 0;
		var rx, ry, ax, ay;
		var _g = 0;
		while(_g < 8) {
			var i = _g++;
			angle += angleDelta;
			rx = xCenter + Math.cos(angle - angleDelta / 2) * xCtrlDist;
			ry = yCenter + Math.sin(angle - angleDelta / 2) * yCtrlDist;
			ax = xCenter + Math.cos(angle) * xRadius;
			ay = yCenter + Math.sin(angle) * yRadius;
			this.curveTo(rx,ry,ax,ay);
		}
	}
	,drawImage: function(source,matrix,sourceRect) {
	}
	,lineTo: function(x,y) {
	}
	,moveTo: function(x,y) {
	}
	,curveTo: function(controlX,controlY,x,y) {
	}
	,toNativeAlpha: function(genericAlpa) {
		return null;
	}
	,toNativeColor: function(genericColor) {
		return null;
	}
	,toNativeRatio: function(genericRatio) {
		return null;
	}
	,toNativeCapStyle: function(genericCapStyle) {
		return null;
	}
	,toNativeJointStyle: function(genericJointStyle) {
		return null;
	}
	,getNativeElement: function() {
		return this._nativeElement;
	}
	,setWidth: function(value) {
		return this._width = value;
	}
	,getWidth: function() {
		return this._width;
	}
	,setHeight: function(value) {
		return this._height = value;
	}
	,getHeight: function() {
		return this._height;
	}
	,__class__: cocktail.core.drawing.AbstractDrawingManager
	,__properties__: {set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",get_nativeElement:"getNativeElement"}
}
if(!cocktail.port) cocktail.port = {}
if(!cocktail.port.browser) cocktail.port.browser = {}
cocktail.port.browser.DrawingManager = $hxClasses["cocktail.port.browser.DrawingManager"] = function(nativeElement,width,height) {
	cocktail.core.drawing.AbstractDrawingManager.call(this,nativeElement,width,height);
};
cocktail.port.browser.DrawingManager.__name__ = ["cocktail","port","browser","DrawingManager"];
cocktail.port.browser.DrawingManager.__super__ = cocktail.core.drawing.AbstractDrawingManager;
cocktail.port.browser.DrawingManager.prototype = $extend(cocktail.core.drawing.AbstractDrawingManager.prototype,{
	beginFill: function(fillStyle,lineStyle) {
		cocktail.core.drawing.AbstractDrawingManager.prototype.beginFill.call(this,fillStyle,lineStyle);
		var canvasContext = this.getContext();
		canvasContext.beginPath();
	}
	,endFill: function() {
		var canvasContext = this.getContext();
		canvasContext.closePath();
		canvasContext.fill();
		canvasContext.stroke();
	}
	,clear: function() {
		var canvasContext = this.getContext();
		canvasContext.clearRect(0,0,this.getWidth(),this.getHeight());
	}
	,setFillStyle: function(fillStyle) {
		var canvasContext = this.getContext();
		var $e = (fillStyle);
		switch( $e[1] ) {
		case 0:
			canvasContext.fillStyle = "rgba(0,0,0,0)";
			break;
		case 1:
			var colorStop = $e[2];
			canvasContext.fillStyle = this.colorStopToRGBA(colorStop);
			break;
		case 2:
			var gradientStyle = $e[2];
			canvasContext.fillStyle = this.getGradient(gradientStyle);
			break;
		case 3:
			var repeat = $e[3], imageHTMLElement = $e[2];
			canvasContext.fillStyle = this.getCanvasPattern(imageHTMLElement,repeat);
			break;
		}
	}
	,setLineStyle: function(lineStyle) {
		var canvasContext = this.getContext();
		var $e = (lineStyle);
		switch( $e[1] ) {
		case 0:
			canvasContext.strokeStyle = "rgba(0,0,0,0)";
			break;
		case 1:
			var lineStyleData = $e[3], colorStop = $e[2];
			this.initLineStyle(lineStyleData);
			canvasContext.strokeStyle = this.colorStopToRGBA(colorStop);
			break;
		case 2:
			var lineStyleData = $e[3], gradientStyle = $e[2];
			this.initLineStyle(lineStyleData);
			canvasContext.strokeStyle = this.getGradient(gradientStyle);
			break;
		case 3:
			var repeat = $e[4], lineStyleData = $e[3], imageHTMLElement = $e[2];
			this.initLineStyle(lineStyleData);
			canvasContext.strokeStyle = this.getCanvasPattern(imageHTMLElement,repeat);
			break;
		}
	}
	,drawImage: function(source,matrix,sourceRect) {
		if(matrix == null) matrix = new cocktail.core.geom.Matrix();
		if(sourceRect == null) {
			var width = source.width;
			var height = source.height;
			sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
		}
		var canvasContext = this.getContext();
	}
	,lineTo: function(x,y) {
		var canvasContext = this.getContext();
		canvasContext.lineTo(x,y);
	}
	,moveTo: function(x,y) {
		var canvasContext = this.getContext();
		canvasContext.moveTo(x,y);
	}
	,curveTo: function(controlX,controlY,x,y) {
		var canvasContext = this.getContext();
		canvasContext.quadraticCurveTo(controlX,controlY,x,y);
	}
	,toNativeAlpha: function(genericAlpha) {
		return genericAlpha;
	}
	,toNativeRatio: function(genericRatio) {
		return genericRatio * 0.01;
	}
	,toNativeCapStyle: function(genericCapStyle) {
		var capStyle = "";
		switch( (genericCapStyle)[1] ) {
		case 2:
			capStyle = "round";
			break;
		case 1:
			capStyle = "square";
			break;
		case 0:
			capStyle = "butt";
			break;
		}
		return capStyle;
	}
	,toNativeJointStyle: function(genericJointStyle) {
		var jointStyle = "";
		switch( (genericJointStyle)[1] ) {
		case 0:
			jointStyle = "miter";
			break;
		case 1:
			jointStyle = "round";
			break;
		case 2:
			jointStyle = "bevel";
			break;
		}
		return jointStyle;
	}
	,colorStopToRGBA: function(colorStop) {
		var rgb = this.hexToRGB(this.getHexColor(colorStop.color));
		return "rgba(" + rgb.red + "," + rgb.green + "," + rgb.blue + "," + this.toNativeAlpha(colorStop.alpha) + ")";
	}
	,getHexColor: function(color) {
		var hexColor = StringTools.hex(color);
		while(hexColor.length < 6) hexColor = "0" + hexColor;
		return "#" + hexColor;
	}
	,hexToRGB: function(hex) {
		var hexCopy = hex;
		var hexCopy1 = hexCopy.substr(1);
		var rgb = { red : Std.parseInt("0x" + hexCopy1.substr(0,2)), green : Std.parseInt("0x" + hexCopy1.substr(2,2)), blue : Std.parseInt("0x" + hexCopy1.substr(4,2))};
		return rgb;
	}
	,initLineStyle: function(lineStyleData) {
		var canvasContext = this.getContext();
		canvasContext.lineWidth = lineStyleData.thickness;
		canvasContext.lineCap = this.toNativeCapStyle(lineStyleData.capStyle);
		canvasContext.lineJoin = this.toNativeJointStyle(lineStyleData.jointStyle);
		canvasContext.miterLimit = lineStyleData.miterLimit;
	}
	,getContext: function() {
		return this._nativeElement.getContext("2d");
	}
	,getCanvasPattern: function(htmlImageElement,repeat) {
		var canvasContext = this.getContext();
		var repeatValue = "";
		if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
		return canvasContext.createPattern(htmlImageElement.get_nativeElement(),repeatValue);
	}
	,getGradient: function(gradientStyle) {
		var gradient = { };
		var canvasContext = this.getContext();
		switch( (gradientStyle.gradientType)[1] ) {
		case 0:
			var gradientRadRotation = gradientStyle.rotation / 180 * Math.PI;
			var xStart = 0;
			var yStart = this.getHeight() / 2;
			var xEnd = this.getWidth();
			var yEnd = this.getHeight() / 2;
			xStart -= this.getWidth() / 2;
			yStart -= this.getHeight() / 2;
			var rotatedStartX = xStart * Math.cos(gradientRadRotation) - yStart * Math.sin(gradientRadRotation);
			var rotatedStartY = xStart * Math.sin(gradientRadRotation) + yStart * Math.cos(gradientRadRotation);
			rotatedStartX += this.getWidth() / 2;
			rotatedStartY += this.getHeight() / 2;
			xEnd -= this.getWidth() / 2;
			yEnd -= this.getHeight() / 2;
			var rotatedEndX = xEnd * Math.cos(gradientRadRotation) - yEnd * Math.sin(gradientRadRotation);
			var rotatedEndY = xEnd * Math.sin(gradientRadRotation) + yEnd * Math.cos(gradientRadRotation);
			rotatedEndX += this.getWidth() / 2;
			rotatedEndY += this.getHeight() / 2;
			gradient = canvasContext.createLinearGradient(rotatedStartX,rotatedStartY,rotatedEndX,rotatedEndY);
			break;
		case 1:
			gradient = canvasContext.createRadialGradient(this.getWidth() / 2,this.getHeight() / 2,this.getWidth() / 4,this.getWidth() / 2,this.getHeight() / 2,this.getHeight() / 2);
			break;
		}
		var gradientStops = gradientStyle.gradientStops;
		var _g1 = 0, _g = gradientStops.length;
		while(_g1 < _g) {
			var i = _g1++;
			gradient.addColorStop(this.toNativeRatio(gradientStops[i].ratio),this.colorStopToRGBA(gradientStops[i].colorStop));
		}
		return gradient;
	}
	,setWidth: function(value) {
		this.clear();
		cocktail.core.drawing.AbstractDrawingManager.prototype.setWidth.call(this,value);
		this._nativeElement.width = value;
		return this._width = value;
	}
	,setHeight: function(value) {
		this.clear();
		cocktail.core.drawing.AbstractDrawingManager.prototype.setHeight.call(this,value);
		this._nativeElement.height = value;
		return this._height = value;
	}
	,__class__: cocktail.port.browser.DrawingManager
});
if(!cocktail.core.background) cocktail.core.background = {}
cocktail.core.background.BackgroundDrawingManager = $hxClasses["cocktail.core.background.BackgroundDrawingManager"] = function(nativeElement,backgroundBox) {
	cocktail.port.browser.DrawingManager.call(this,nativeElement,Math.round(backgroundBox.width),Math.round(backgroundBox.height));
};
cocktail.core.background.BackgroundDrawingManager.__name__ = ["cocktail","core","background","BackgroundDrawingManager"];
cocktail.core.background.BackgroundDrawingManager.__super__ = cocktail.port.browser.DrawingManager;
cocktail.core.background.BackgroundDrawingManager.prototype = $extend(cocktail.port.browser.DrawingManager.prototype,{
	drawBackgroundImage: function(nativeImage,backgroundPositioningBox,backgroundPaintingBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
		var totalWidth = Math.round(computedBackgroundPosition.x) + Math.round(backgroundPositioningBox.x);
		var maxWidth = Math.round(backgroundPaintingBox.x + backgroundPaintingBox.width);
		var imageWidth = Math.round(computedBackgroundSize.width);
		switch( (backgroundRepeat.x)[1] ) {
		case 3:
			maxWidth = totalWidth + imageWidth;
			break;
		case 0:
			while(totalWidth > backgroundPaintingBox.x) totalWidth -= imageWidth;
			break;
		case 1:
			imageWidth = Math.round(backgroundPositioningBox.width / computedBackgroundSize.width);
			while(totalWidth > backgroundPaintingBox.x) totalWidth -= imageWidth;
			break;
		case 2:
			while(totalWidth > backgroundPaintingBox.x) totalWidth -= imageWidth;
			break;
		}
		var initialWidth = totalWidth;
		var totalHeight = computedBackgroundPosition.y + Math.round(backgroundPositioningBox.y);
		var maxHeight = backgroundPaintingBox.y + backgroundPaintingBox.height;
		var imageHeight = computedBackgroundSize.height;
		switch( (backgroundRepeat.y)[1] ) {
		case 3:
			maxHeight = totalHeight + imageHeight;
			break;
		case 0:
			while(totalHeight > backgroundPaintingBox.y) totalHeight -= imageHeight;
			break;
		case 1:
			imageHeight = backgroundPositioningBox.height / computedBackgroundSize.height;
			while(totalHeight > backgroundPaintingBox.y) totalHeight -= imageHeight;
			break;
		case 2:
			while(totalHeight > backgroundPaintingBox.y) totalHeight -= imageHeight;
			break;
		}
		var initialHeight = totalHeight;
		while(totalHeight < maxHeight) {
			var matrix = new cocktail.core.geom.Matrix();
			matrix.translate(totalWidth,totalHeight);
			matrix.scale(imageWidth / intrinsicWidth,imageHeight / intrinsicHeight,{ x : 0.0, y : 0.0});
			this.drawImage(nativeImage,matrix,backgroundPaintingBox);
			totalWidth += imageWidth;
			if(totalWidth >= maxWidth) {
				totalWidth = initialWidth;
				totalHeight += imageHeight;
			}
		}
	}
	,drawBackgroundColor: function(color,backgroundPaintingBox) {
		var fillStyle = cocktail.core.dom.FillStyleValue.monochrome(color);
		var lineStyle = cocktail.core.dom.LineStyleValue.none;
		this.beginFill(fillStyle,lineStyle);
		this.drawRect(Math.round(backgroundPaintingBox.x),Math.round(backgroundPaintingBox.y),Math.round(backgroundPaintingBox.width),Math.round(backgroundPaintingBox.height));
		this.endFill();
	}
	,drawBackgroundGradient: function(gradient,backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
		var gradientSurface = new cocktail.port.browser.DrawingManager(cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas),computedBackgroundSize.width,computedBackgroundSize.height);
		var fillStyle;
		var lineStyle = cocktail.core.dom.LineStyleValue.none;
		var $e = (gradient);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			var gradientStyle = { gradientType : cocktail.core.dom.GradientTypeValue.linear, gradientStops : this.getGradientStops(value.colorStops), rotation : this.getRotation(value.angle)};
			fillStyle = cocktail.core.dom.FillStyleValue.gradient(gradientStyle);
			break;
		}
		gradientSurface.beginFill(fillStyle,lineStyle);
		gradientSurface.drawRect(0,0,computedBackgroundSize.width,computedBackgroundSize.height);
		gradientSurface.endFill();
		this.drawBackgroundImage(gradientSurface.getNativeElement(),backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize.width,computedBackgroundSize.height,computedBackgroundSize.width / computedBackgroundSize.height,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat);
	}
	,getGradientStops: function(value) {
		var gradientStopsData = new Array();
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ratio;
			var $e = (value[i].stop);
			switch( $e[1] ) {
			case 0:
				var value1 = $e[2];
				ratio = 0;
				break;
			case 1:
				var value1 = $e[2];
				ratio = value1;
				break;
			}
			var color = cocktail.core.unit.UnitManager.getColorDataFromCSSColor(value[i].color);
			gradientStopsData.push({ colorStop : color, ratio : ratio});
		}
		return gradientStopsData;
	}
	,getRotation: function(value) {
		var rotation;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			rotation = Math.round(cocktail.core.unit.UnitManager.getDegreeFromAngle(value1));
			break;
		case 1:
			var value1 = $e[2];
			switch( (value1)[1] ) {
			case 0:
				rotation = 0;
				break;
			case 3:
				rotation = 90;
				break;
			case 2:
				rotation = 180;
				break;
			case 1:
				rotation = 270;
				break;
			}
			break;
		case 2:
			var value1 = $e[2];
			switch( (value1)[1] ) {
			case 0:
				rotation = 45;
				break;
			case 1:
				rotation = 135;
				break;
			case 2:
				rotation = 225;
				break;
			case 3:
				rotation = 315;
				break;
			}
			break;
		}
		return rotation;
	}
	,__class__: cocktail.core.background.BackgroundDrawingManager
});
cocktail.core.background.BackgroundManager = $hxClasses["cocktail.core.background.BackgroundManager"] = function() {
	this._backgroundDrawingManagers = new Array();
};
cocktail.core.background.BackgroundManager.__name__ = ["cocktail","core","background","BackgroundManager"];
cocktail.core.background.BackgroundManager.prototype = {
	_backgroundDrawingManagers: null
	,dispose: function() {
		this._backgroundDrawingManagers = null;
	}
	,render: function(backgroundBox,style) {
		var nativeElements = new Array();
		if(backgroundBox.width <= 0 || backgroundBox.height <= 0) return nativeElements;
		var _g1 = 0, _g = style.getBackgroundImage().length;
		while(_g1 < _g) {
			var i = _g1++;
			var $e = (style.getBackgroundImage()[i]);
			switch( $e[1] ) {
			case 0:
				break;
			case 1:
				var value = $e[2];
				var $e = (value);
				switch( $e[1] ) {
				case 0:
					var value1 = $e[2];
					var imageDeclaration = { urls : [value1], fallbackColor : cocktail.core.unit.CSSColor.transparent};
					var imageNativeElement = this.drawBackgroundImage(imageDeclaration,style,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
					nativeElements.push(imageNativeElement);
					break;
				case 1:
					var value1 = $e[2];
					var imageNativeElement = this.drawBackgroundImage(value1,style,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
					nativeElements.push(imageNativeElement);
					break;
				case 2:
					var value1 = $e[2];
					var gradientNativeElement = this.drawBackgroundGradient(style,value1,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
					nativeElements.push(gradientNativeElement);
					break;
				}
				break;
			}
			if(i == style.getBackgroundImage().length - 1) {
				var backgroundColorNativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas);
				this.drawBackgroundColor(style,style.getComputedStyle().backgroundColor,backgroundColorNativeElement,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
				nativeElements.reverse();
				nativeElements.unshift(backgroundColorNativeElement);
			}
		}
		return nativeElements;
	}
	,drawBackgroundImage: function(imageDeclaration,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var backgroundImageNativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas);
		var imageLoader = new cocktail.core.resource.AbstractImageLoader();
		var onBackgroundImageLoadedDelegate = this.onBackgroundImageLoaded.$bind(this);
		var onBackgroundImageLoadErrorDelegate = this.onBackgroundImageLoadError.$bind(this);
		imageLoader.load(imageDeclaration.urls,function(loadedImage) {
			onBackgroundImageLoadedDelegate(backgroundImageNativeElement,loadedImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		},function(error) {
			onBackgroundImageLoadErrorDelegate(error,imageDeclaration.fallbackColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		});
		return backgroundImageNativeElement;
	}
	,onBackgroundImageLoaded: function(backgroundImageNativeElement,loadedBackgroundImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var computedGradientStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundImageDrawingManager = new cocktail.core.background.BackgroundDrawingManager(backgroundImageNativeElement,backgroundBox);
		backgroundImageDrawingManager.drawBackgroundImage(loadedBackgroundImage,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		this._backgroundDrawingManagers.push(backgroundImageDrawingManager);
	}
	,onBackgroundImageLoadError: function(error,backgroundColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		this.drawBackgroundColor(style,cocktail.core.unit.UnitManager.getColorDataFromCSSColor(backgroundColor),backgroundImageNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	}
	,drawBackgroundColor: function(style,backgroundColor,backgroundColorNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var computedBackgroundStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundColorDrawingManager = new cocktail.core.background.BackgroundDrawingManager(backgroundColorNativeElement,backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor,this.getBackgroundPaintingBox(computedBackgroundStyles.backgroundClip));
		this._backgroundDrawingManagers.push(backgroundColorDrawingManager);
	}
	,drawBackgroundGradient: function(style,gradientValue,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var computedGradientStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var gradientNativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas);
		var backgroundGradientDrawingManager = new cocktail.core.background.BackgroundDrawingManager(gradientNativeElement,backgroundBox);
		backgroundGradientDrawingManager.drawBackgroundGradient(gradientValue,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		return gradientNativeElement;
	}
	,getBackgroundPaintingBox: function(computedBackgroundBox) {
		return computedBackgroundBox;
	}
	,getBackgroundPositioningBox: function(computedPositioningBox) {
		return computedPositioningBox;
	}
	,__class__: cocktail.core.background.BackgroundManager
}
cocktail.core.background.InitialBlockBackgroundManager = $hxClasses["cocktail.core.background.InitialBlockBackgroundManager"] = function() {
	cocktail.core.background.BackgroundManager.call(this);
};
cocktail.core.background.InitialBlockBackgroundManager.__name__ = ["cocktail","core","background","InitialBlockBackgroundManager"];
cocktail.core.background.InitialBlockBackgroundManager.__super__ = cocktail.core.background.BackgroundManager;
cocktail.core.background.InitialBlockBackgroundManager.prototype = $extend(cocktail.core.background.BackgroundManager.prototype,{
	getBackgroundPaintingBox: function(computedBackgroundBox) {
		return this.getWindowRectangleData();
	}
	,getBackgroundPositioningBox: function(computedPositioningBox) {
		return this.getWindowRectangleData();
	}
	,getWindowRectangleData: function() {
		var windowWidth = cocktail.Lib.get_window().get_innerWidth();
		var windowHeight = cocktail.Lib.get_window().get_innerHeight();
		var window = { x : 0.0, y : 0.0, width : windowWidth, height : windowHeight};
		return window;
	}
	,__class__: cocktail.core.background.InitialBlockBackgroundManager
});
if(!cocktail.core.dom) cocktail.core.dom = {}
cocktail.core.dom.Node = $hxClasses["cocktail.core.dom.Node"] = function() {
	this._childNodes = new Array();
};
cocktail.core.dom.Node.__name__ = ["cocktail","core","dom","Node"];
cocktail.core.dom.Node.prototype = {
	nodeType: null
	,nodeValue: null
	,nodeName: null
	,_parentNode: null
	,parentNode: null
	,_childNodes: null
	,childNodes: null
	,firstChild: null
	,lastChild: null
	,nextSibling: null
	,previousSibling: null
	,_attributes: null
	,attributes: null
	,_ownerDocument: null
	,ownerDocument: null
	,removeChild: function(oldChild) {
		oldChild.set_parentNode(null);
		var newChildNodes = new Array();
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._childNodes[i] != oldChild) newChildNodes.push(this._childNodes[i]);
		}
		this._childNodes = newChildNodes;
		return oldChild;
	}
	,appendChild: function(newChild) {
		this.removeFromParentIfNecessary(newChild);
		newChild.set_parentNode(this);
		this._childNodes.push(newChild);
		return newChild;
	}
	,insertBefore: function(newChild,refChild) {
		if(refChild == null) this.appendChild(newChild); else {
			this.removeFromParentIfNecessary(newChild);
			var newChildNodes = new Array();
			var _g1 = 0, _g = this._childNodes.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._childNodes[i] == refChild) newChildNodes.push(newChild);
				newChildNodes.push(this._childNodes[i]);
			}
			this._childNodes = newChildNodes;
		}
		return newChild;
	}
	,replaceChild: function(newChild,oldChild) {
		var newChildNodes = new Array();
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._childNodes[i] == oldChild) newChildNodes.push(newChild); else newChildNodes.push(this._childNodes[i]);
		}
		this._childNodes = newChildNodes;
		return oldChild;
	}
	,isSameNode: function(other) {
		return other == this;
	}
	,hasChildNodes: function() {
		return this._childNodes.length > 0;
	}
	,hasAttributes: function() {
		return false;
	}
	,removeFromParentIfNecessary: function(newChild) {
		if(newChild.get_parentNode() != null) {
			var parentNode = newChild.get_parentNode();
			parentNode.removeChild(newChild);
		}
	}
	,get_firstChild: function() {
		if(this.hasChildNodes() == true) return this._childNodes[0]; else return null;
	}
	,get_lastChild: function() {
		if(this.hasChildNodes() == true) return this._childNodes[this._childNodes.length - 1]; else return null;
	}
	,get_nextSibling: function() {
		if(this._parentNode == null) return null; else if(this._parentNode.get_lastChild() != this) {
			var _g1 = 0, _g = this._parentNode.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this.isSameNode(this._parentNode.get_childNodes()[i]) == true) return this._parentNode.get_childNodes()[i + 1];
			}
		}
		return null;
	}
	,get_previousSibling: function() {
		if(this._parentNode == null) return null; else if(this._parentNode.get_firstChild() != this) {
			var _g1 = 0, _g = this._parentNode.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this.isSameNode(this._parentNode.get_childNodes()[i]) == true) return this._parentNode.get_childNodes()[i - 1];
			}
		}
		return null;
	}
	,get_nodeType: function() {
		return -1;
	}
	,get_parentNode: function() {
		return this._parentNode;
	}
	,set_parentNode: function(value) {
		return this._parentNode = value;
	}
	,get_childNodes: function() {
		return this._childNodes;
	}
	,get_nodeValue: function() {
		return null;
	}
	,set_nodeValue: function(value) {
		return value;
	}
	,get_nodeName: function() {
		return null;
	}
	,get_attributes: function() {
		return null;
	}
	,get_ownerDocument: function() {
		return this._ownerDocument;
	}
	,set_ownerDocument: function(value) {
		return this._ownerDocument = value;
	}
	,__class__: cocktail.core.dom.Node
	,__properties__: {set_ownerDocument:"set_ownerDocument",get_ownerDocument:"get_ownerDocument",get_attributes:"get_attributes",get_previousSibling:"get_previousSibling",get_nextSibling:"get_nextSibling",get_lastChild:"get_lastChild",get_firstChild:"get_firstChild",get_childNodes:"get_childNodes",set_parentNode:"set_parentNode",get_parentNode:"get_parentNode",get_nodeName:"get_nodeName",set_nodeValue:"set_nodeValue",get_nodeValue:"get_nodeValue",get_nodeType:"get_nodeType"}
}
cocktail.core.dom.Attr = $hxClasses["cocktail.core.dom.Attr"] = function(name) {
	this._name = name;
	this._specified = false;
	cocktail.core.dom.Node.call(this);
};
cocktail.core.dom.Attr.__name__ = ["cocktail","core","dom","Attr"];
cocktail.core.dom.Attr.__super__ = cocktail.core.dom.Node;
cocktail.core.dom.Attr.prototype = $extend(cocktail.core.dom.Node.prototype,{
	_name: null
	,name: null
	,_value: null
	,value: null
	,_specified: null
	,specified: null
	,_isId: null
	,isId: null
	,_ownerElement: null
	,ownerElement: null
	,get_nodeName: function() {
		return this._name;
	}
	,get_nodeType: function() {
		return 2;
	}
	,get_nodeValue: function() {
		return this.get_value();
	}
	,set_nodeValue: function(value) {
		return this.set_value(value);
	}
	,get_ownerElement: function() {
		return this._ownerElement;
	}
	,set_ownerElement: function(value) {
		return this._ownerElement = value;
	}
	,get_isId: function() {
		return this._isId;
	}
	,set_isId: function(value) {
		return this._isId = value;
	}
	,get_name: function() {
		return this._name;
	}
	,get_value: function() {
		if(this._value == null) return "";
		return this._value;
	}
	,set_value: function(value) {
		this._specified = true;
		return this._value = value;
	}
	,get_specified: function() {
		return this._specified;
	}
	,__class__: cocktail.core.dom.Attr
	,__properties__: $extend(cocktail.core.dom.Node.prototype.__properties__,{set_ownerElement:"set_ownerElement",get_ownerElement:"get_ownerElement",set_isId:"set_isId",get_isId:"get_isId",get_specified:"get_specified",set_value:"set_value",get_value:"get_value",get_name:"get_name"})
});
cocktail.core.dom.CharacterData = $hxClasses["cocktail.core.dom.CharacterData"] = function() {
	cocktail.core.dom.Node.call(this);
};
cocktail.core.dom.CharacterData.__name__ = ["cocktail","core","dom","CharacterData"];
cocktail.core.dom.CharacterData.__super__ = cocktail.core.dom.Node;
cocktail.core.dom.CharacterData.prototype = $extend(cocktail.core.dom.Node.prototype,{
	_data: null
	,data: null
	,get_nodeType: function() {
		return 3;
	}
	,get_data: function() {
		return this._data;
	}
	,set_data: function(value) {
		return this._data = value;
	}
	,__class__: cocktail.core.dom.CharacterData
	,__properties__: $extend(cocktail.core.dom.Node.prototype.__properties__,{set_data:"set_data",get_data:"get_data"})
});
cocktail.core.dom.TextTokenValue = $hxClasses["cocktail.core.dom.TextTokenValue"] = { __ename__ : ["cocktail","core","dom","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
cocktail.core.dom.TextTokenValue.word = function(value) { var $x = ["word",0,value]; $x.__enum__ = cocktail.core.dom.TextTokenValue; $x.toString = $estr; return $x; }
cocktail.core.dom.TextTokenValue.space = ["space",1];
cocktail.core.dom.TextTokenValue.space.toString = $estr;
cocktail.core.dom.TextTokenValue.space.__enum__ = cocktail.core.dom.TextTokenValue;
cocktail.core.dom.TextTokenValue.tab = ["tab",2];
cocktail.core.dom.TextTokenValue.tab.toString = $estr;
cocktail.core.dom.TextTokenValue.tab.__enum__ = cocktail.core.dom.TextTokenValue;
cocktail.core.dom.TextTokenValue.lineFeed = ["lineFeed",3];
cocktail.core.dom.TextTokenValue.lineFeed.toString = $estr;
cocktail.core.dom.TextTokenValue.lineFeed.__enum__ = cocktail.core.dom.TextTokenValue;
cocktail.core.dom.FillStyleValue = $hxClasses["cocktail.core.dom.FillStyleValue"] = { __ename__ : ["cocktail","core","dom","FillStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.core.dom.FillStyleValue.none = ["none",0];
cocktail.core.dom.FillStyleValue.none.toString = $estr;
cocktail.core.dom.FillStyleValue.none.__enum__ = cocktail.core.dom.FillStyleValue;
cocktail.core.dom.FillStyleValue.monochrome = function(colorStop) { var $x = ["monochrome",1,colorStop]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.FillStyleValue.gradient = function(gradientStyle) { var $x = ["gradient",2,gradientStyle]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.FillStyleValue.bitmap = function(htmlImageElement,repeat) { var $x = ["bitmap",3,htmlImageElement,repeat]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue = $hxClasses["cocktail.core.dom.LineStyleValue"] = { __ename__ : ["cocktail","core","dom","LineStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.core.dom.LineStyleValue.none = ["none",0];
cocktail.core.dom.LineStyleValue.none.toString = $estr;
cocktail.core.dom.LineStyleValue.none.__enum__ = cocktail.core.dom.LineStyleValue;
cocktail.core.dom.LineStyleValue.monochrome = function(color,lineStyle) { var $x = ["monochrome",1,color,lineStyle]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue.gradient = function(gradientStyle,lineStyle) { var $x = ["gradient",2,gradientStyle,lineStyle]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue.bitmap = function(htmlImageElement,lineStyle,repeat) { var $x = ["bitmap",3,htmlImageElement,lineStyle,repeat]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.GradientTypeValue = $hxClasses["cocktail.core.dom.GradientTypeValue"] = { __ename__ : ["cocktail","core","dom","GradientTypeValue"], __constructs__ : ["linear","radial"] }
cocktail.core.dom.GradientTypeValue.linear = ["linear",0];
cocktail.core.dom.GradientTypeValue.linear.toString = $estr;
cocktail.core.dom.GradientTypeValue.linear.__enum__ = cocktail.core.dom.GradientTypeValue;
cocktail.core.dom.GradientTypeValue.radial = ["radial",1];
cocktail.core.dom.GradientTypeValue.radial.toString = $estr;
cocktail.core.dom.GradientTypeValue.radial.__enum__ = cocktail.core.dom.GradientTypeValue;
cocktail.core.dom.CapsStyleValue = $hxClasses["cocktail.core.dom.CapsStyleValue"] = { __ename__ : ["cocktail","core","dom","CapsStyleValue"], __constructs__ : ["none","square","round"] }
cocktail.core.dom.CapsStyleValue.none = ["none",0];
cocktail.core.dom.CapsStyleValue.none.toString = $estr;
cocktail.core.dom.CapsStyleValue.none.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.CapsStyleValue.square = ["square",1];
cocktail.core.dom.CapsStyleValue.square.toString = $estr;
cocktail.core.dom.CapsStyleValue.square.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.CapsStyleValue.round = ["round",2];
cocktail.core.dom.CapsStyleValue.round.toString = $estr;
cocktail.core.dom.CapsStyleValue.round.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.JointStyleValue = $hxClasses["cocktail.core.dom.JointStyleValue"] = { __ename__ : ["cocktail","core","dom","JointStyleValue"], __constructs__ : ["miter","round","bevel"] }
cocktail.core.dom.JointStyleValue.miter = ["miter",0];
cocktail.core.dom.JointStyleValue.miter.toString = $estr;
cocktail.core.dom.JointStyleValue.miter.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.core.dom.JointStyleValue.round = ["round",1];
cocktail.core.dom.JointStyleValue.round.toString = $estr;
cocktail.core.dom.JointStyleValue.round.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.core.dom.JointStyleValue.bevel = ["bevel",2];
cocktail.core.dom.JointStyleValue.bevel.toString = $estr;
cocktail.core.dom.JointStyleValue.bevel.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.core.dom.Document = $hxClasses["cocktail.core.dom.Document"] = function() {
	cocktail.core.dom.Node.call(this);
};
cocktail.core.dom.Document.__name__ = ["cocktail","core","dom","Document"];
cocktail.core.dom.Document.__super__ = cocktail.core.dom.Node;
cocktail.core.dom.Document.prototype = $extend(cocktail.core.dom.Node.prototype,{
	_documentElement: null
	,documentElement: null
	,createElement: function(tagName) {
		var element = new cocktail.port.browser.HTMLElement(tagName);
		element.set_ownerDocument(this);
		return element;
	}
	,createTextNode: function(data) {
		var text = new cocktail.port.browser.Text();
		text.set_nodeValue(data);
		return text;
	}
	,createAttribute: function(name) {
		var attribute = new cocktail.core.dom.Attr(name);
		return attribute;
	}
	,getElementById: function(elementId) {
		return this.doGetElementById(this._documentElement,elementId);
	}
	,doGetElementById: function(node,elementId) {
		if(node.hasChildNodes() == true && node.get_nodeType() == 1) {
			var _g1 = 0, _g = node.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				var matchingElement = this.doGetElementById(node.get_childNodes()[i],elementId);
				if(matchingElement != null) return matchingElement;
			}
		}
		if(node.hasAttributes() == true) {
			var attributes = node.get_attributes();
			var element = node;
			var _g1 = 0, _g = attributes.get_length();
			while(_g1 < _g) {
				var i = _g1++;
				var attribute = element.getAttributeNode(attributes.item(i).get_nodeName());
				if(attribute.get_isId() == true && attribute.get_specified() == true) {
					if(attribute.get_value() == elementId) return element;
				}
			}
		}
		return null;
	}
	,getElementsByTagName: function(tagName) {
		return this._documentElement.getElementsByTagName(tagName);
	}
	,get_nodeType: function() {
		return 9;
	}
	,get_documentElement: function() {
		return this._documentElement;
	}
	,__class__: cocktail.core.dom.Document
	,__properties__: $extend(cocktail.core.dom.Node.prototype.__properties__,{get_documentElement:"get_documentElement"})
});
cocktail.core.dom.Element = $hxClasses["cocktail.core.dom.Element"] = function(tagName) {
	this._tagName = tagName;
	this._attributes = new cocktail.core.dom.NamedNodeMap();
	cocktail.core.dom.Node.call(this);
};
cocktail.core.dom.Element.__name__ = ["cocktail","core","dom","Element"];
cocktail.core.dom.Element.__super__ = cocktail.core.dom.Node;
cocktail.core.dom.Element.prototype = $extend(cocktail.core.dom.Node.prototype,{
	_tagName: null
	,tagName: null
	,firstElementChild: null
	,lastElementChild: null
	,previousElementSibling: null
	,nextElementSibling: null
	,childElementCount: null
	,getAttribute: function(name) {
		var attribute = this.getAttributeNode(name);
		if(attribute != null) return attribute.get_value(); else return null;
	}
	,setAttribute: function(name,value) {
		var attribute = this._attributes.getNamedItem(name);
		if(attribute == null) {
			attribute = new cocktail.core.dom.Attr(name);
			this._attributes.setNamedItem(attribute);
			attribute.set_ownerElement(this);
		}
		attribute.set_value(value);
	}
	,getAttributeNode: function(name) {
		var attribute = this._attributes.getNamedItem(name);
		if(attribute != null) return attribute;
		return null;
	}
	,setAttributeNode: function(newAttr) {
		newAttr.set_ownerElement(this);
		return this._attributes.setNamedItem(newAttr);
	}
	,removeAttribute: function(name) {
		var removedAttribute = this._attributes.removeNamedItem(name);
		if(removedAttribute != null) removedAttribute.set_ownerElement(null);
	}
	,setIdAttribute: function(name,isId) {
		var idAttribute = this._attributes.getNamedItem(name);
		if(idAttribute == null) {
			idAttribute = new cocktail.core.dom.Attr(name);
			this._attributes.setNamedItem(idAttribute);
			idAttribute.set_ownerElement(this);
		}
		idAttribute.set_isId(isId);
	}
	,setIdAttributeNode: function(idAttr,isId) {
		idAttr.set_isId(isId);
		this._attributes.setNamedItem(idAttr);
	}
	,hasAttribute: function(name) {
		return this._attributes.getNamedItem(name) != null;
	}
	,getElementsByTagName: function(tagName) {
		var elements = new Array();
		this.doGetElementsByTagName(this,tagName,elements);
		return elements;
	}
	,doGetElementsByTagName: function(node,tagName,elements) {
		if(node.hasChildNodes() == true) {
			var _g1 = 0, _g = node.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				var childNode = node.get_childNodes()[i];
				if(childNode.get_nodeName() == tagName) elements.push(childNode); else if(tagName == "*" && childNode.get_nodeType() == 1) elements.push(childNode);
				this.doGetElementsByTagName(childNode,tagName,elements);
			}
		}
	}
	,hasAttributes: function() {
		return this._attributes.get_length() > 0;
	}
	,get_nodeName: function() {
		return this._tagName;
	}
	,get_nodeType: function() {
		return 1;
	}
	,get_attributes: function() {
		return this._attributes;
	}
	,get_firstElementChild: function() {
		if(this.hasChildNodes() == false) return null;
		if(this.get_firstChild().get_nodeType() == 1) return this.get_firstChild(); else {
			var _g1 = 0, _g = this._childNodes.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._childNodes[i].get_nodeType() == 1) return this._childNodes[i];
			}
		}
		return null;
	}
	,get_lastElementChild: function() {
		if(this.hasChildNodes() == false) return null;
		if(this.get_lastChild().get_nodeType() == 1) return this.get_lastChild(); else {
			var _g = this._childNodes.length;
			while(_g < 0) {
				var i = _g++;
				if(this._childNodes[i].get_nodeType() == 1) return this._childNodes[i];
			}
		}
		return null;
	}
	,get_nextElementSibling: function() {
		if(this.get_nextSibling() == null) return null;
		var nextElementSibling = this.get_nextSibling();
		while(nextElementSibling.get_nodeType() != 1) {
			nextElementSibling = nextElementSibling.get_nextSibling();
			if(nextElementSibling == null) return null;
		}
		return nextElementSibling;
	}
	,get_previousElementSibling: function() {
		if(this.get_previousSibling() == null) return null;
		var previousElementSibling = this.get_previousSibling();
		while(previousElementSibling.get_nodeType() != 1) {
			previousElementSibling = previousElementSibling.get_previousSibling();
			if(previousElementSibling == null) return null;
		}
		return previousElementSibling;
	}
	,get_childElementCount: function() {
		var childElementCount = 0;
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._childNodes[i].get_nodeType() == 1) childElementCount++;
		}
		return childElementCount;
	}
	,get_tagName: function() {
		return this._tagName;
	}
	,__class__: cocktail.core.dom.Element
	,__properties__: $extend(cocktail.core.dom.Node.prototype.__properties__,{get_childElementCount:"get_childElementCount",get_nextElementSibling:"get_nextElementSibling",get_previousElementSibling:"get_previousElementSibling",get_lastElementChild:"get_lastElementChild",get_firstElementChild:"get_firstElementChild",get_tagName:"get_tagName"})
});
cocktail.core.dom.NamedNodeMap = $hxClasses["cocktail.core.dom.NamedNodeMap"] = function() {
	this._nodes = new Array();
};
cocktail.core.dom.NamedNodeMap.__name__ = ["cocktail","core","dom","NamedNodeMap"];
cocktail.core.dom.NamedNodeMap.prototype = {
	_nodes: null
	,length: null
	,getNamedItem: function(name) {
		var _g1 = 0, _g = this._nodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._nodes[i].get_nodeName() == name) return this._nodes[i];
		}
		return null;
	}
	,setNamedItem: function(arg) {
		var replacedNode = this.getNamedItem(arg.get_nodeName());
		if(replacedNode != null) {
			var _g1 = 0, _g = this.get_length();
			while(_g1 < _g) {
				var i = _g1++;
				if(this._nodes[i].isSameNode(replacedNode) == true) {
					this._nodes[i] = arg;
					return replacedNode;
				}
			}
		} else this._nodes.push(arg);
		return replacedNode;
	}
	,removeNamedItem: function(name) {
		var removedNode = this.getNamedItem(name);
		if(removedNode == null) return null;
		var newNodes = new Array();
		var _g1 = 0, _g = this.get_length();
		while(_g1 < _g) {
			var i = _g1++;
			if(this._nodes[i].isSameNode(removedNode) == false) newNodes.push(this._nodes[i]);
		}
		this._nodes = newNodes;
		return removedNode;
	}
	,item: function(index) {
		if(index > this.get_length() - 1) return null; else return this._nodes[index];
	}
	,get_length: function() {
		return this._nodes.length;
	}
	,__class__: cocktail.core.dom.NamedNodeMap
	,__properties__: {get_length:"get_length"}
}
cocktail.core.dom.Text = $hxClasses["cocktail.core.dom.Text"] = function() {
	cocktail.core.dom.CharacterData.call(this);
	this._textFragments = new Array();
};
cocktail.core.dom.Text.__name__ = ["cocktail","core","dom","Text"];
cocktail.core.dom.Text.doGetTextFragments = function(text) {
	var textFragments = new Array();
	var textFragment = "";
	var i = 0;
	while(i < text.length) {
		if(text.charAt(i) == "\\") {
			if(i < text.length - 1) {
				if(text.charAt(i + 1) == "n") {
					if(textFragment != null) {
						textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.lineFeed));
					i++;
				} else if(text.charAt(i + 1) == "t") {
					if(textFragment != null) {
						textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.tab));
					i++;
				}
			}
		}
		if(StringTools.isSpace(text,i) == true) {
			if(textFragment != null) {
				textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.word(textFragment)));
				textFragment = null;
			}
			textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.space));
		} else {
			if(textFragment == null) textFragment = "";
			textFragment += text.charAt(i);
		}
		i++;
	}
	if(textFragment != null) textFragments.push(cocktail.core.dom.Text.insertTextToken(cocktail.core.dom.TextTokenValue.word(textFragment)));
	return textFragments;
}
cocktail.core.dom.Text.insertTextToken = function(textToken) {
	return { textToken : textToken, textRenderer : null};
}
cocktail.core.dom.Text.__super__ = cocktail.core.dom.CharacterData;
cocktail.core.dom.Text.prototype = $extend(cocktail.core.dom.CharacterData.prototype,{
	_nativeElement: null
	,nativeElement: null
	,_textFragments: null
	,reset: function() {
		var _g1 = 0, _g = this._textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._textFragments[i].textRenderer = null;
		}
	}
	,getTextFragments: function(text) {
		if(this._textFragments.length == 0) this._textFragments = cocktail.core.dom.Text.doGetTextFragments(text);
		return this._textFragments;
	}
	,get_nativeElement: function() {
		return this._nativeElement;
	}
	,get_nodeValue: function() {
		return this._data;
	}
	,set_nodeValue: function(value) {
		return this.set_data(value);
	}
	,__class__: cocktail.core.dom.Text
	,__properties__: $extend(cocktail.core.dom.CharacterData.prototype.__properties__,{get_nativeElement:"get_nativeElement"})
});
if(!cocktail.core.event) cocktail.core.event = {}
cocktail.core.event.Event = $hxClasses["cocktail.core.event.Event"] = function(type,target) {
	this._type = type;
	this._target = target;
};
cocktail.core.event.Event.__name__ = ["cocktail","core","event","Event"];
cocktail.core.event.Event.prototype = {
	_type: null
	,type: null
	,_target: null
	,target: null
	,_defaultPrevented: null
	,defaultPrevented: null
	,preventDefault: function() {
		this._defaultPrevented = true;
	}
	,get_defaultPrevented: function() {
		return this._defaultPrevented;
	}
	,get_type: function() {
		return this._type;
	}
	,get_target: function() {
		return this._target;
	}
	,__class__: cocktail.core.event.Event
	,__properties__: {get_defaultPrevented:"get_defaultPrevented",get_target:"get_target",get_type:"get_type"}
}
cocktail.core.event.IEventTarget = $hxClasses["cocktail.core.event.IEventTarget"] = function() { }
cocktail.core.event.IEventTarget.__name__ = ["cocktail","core","event","IEventTarget"];
cocktail.core.event.IEventTarget.prototype = {
	__class__: cocktail.core.event.IEventTarget
}
cocktail.core.event.UIEvent = $hxClasses["cocktail.core.event.UIEvent"] = function(type,target,detail) {
	this._detail = detail;
	cocktail.core.event.Event.call(this,type,target);
};
cocktail.core.event.UIEvent.__name__ = ["cocktail","core","event","UIEvent"];
cocktail.core.event.UIEvent.__super__ = cocktail.core.event.Event;
cocktail.core.event.UIEvent.prototype = $extend(cocktail.core.event.Event.prototype,{
	_detail: null
	,detail: null
	,get_detail: function() {
		return this._detail;
	}
	,set_detail: function(value) {
		return this._detail = value;
	}
	,__class__: cocktail.core.event.UIEvent
	,__properties__: $extend(cocktail.core.event.Event.prototype.__properties__,{set_detail:"set_detail",get_detail:"get_detail"})
});
cocktail.core.event.KeyboardEvent = $hxClasses["cocktail.core.event.KeyboardEvent"] = function(type,target,detail,keyChar,key,ctrlKey,shiftKey,altKey) {
	cocktail.core.event.UIEvent.call(this,type,target,detail);
	this._keyChar = keyChar;
	this._key = key;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
};
cocktail.core.event.KeyboardEvent.__name__ = ["cocktail","core","event","KeyboardEvent"];
cocktail.core.event.KeyboardEvent.__super__ = cocktail.core.event.UIEvent;
cocktail.core.event.KeyboardEvent.prototype = $extend(cocktail.core.event.UIEvent.prototype,{
	_keyChar: null
	,keyChar: null
	,_key: null
	,key: null
	,_ctrlKey: null
	,ctrlKey: null
	,_shiftKey: null
	,shiftKey: null
	,_altKey: null
	,altKey: null
	,get_altKey: function() {
		return this._altKey;
	}
	,get_shiftKey: function() {
		return this._shiftKey;
	}
	,get_ctrlKey: function() {
		return this._ctrlKey;
	}
	,get_keyChar: function() {
		return this._keyChar;
	}
	,get_key: function() {
		return this._key;
	}
	,__class__: cocktail.core.event.KeyboardEvent
	,__properties__: $extend(cocktail.core.event.UIEvent.prototype.__properties__,{get_altKey:"get_altKey",get_shiftKey:"get_shiftKey",get_ctrlKey:"get_ctrlKey",get_key:"get_key",get_keyChar:"get_keyChar"})
});
cocktail.core.event.MouseEvent = $hxClasses["cocktail.core.event.MouseEvent"] = function(type,target,detail,screenX,screenY,clientX,clientY,ctrlKey,shiftKey,altKey) {
	cocktail.core.event.UIEvent.call(this,type,target,detail);
	this._screenX = screenX;
	this._screenY = screenY;
	this._clientX = clientX;
	this._clientY = clientY;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
};
cocktail.core.event.MouseEvent.__name__ = ["cocktail","core","event","MouseEvent"];
cocktail.core.event.MouseEvent.__super__ = cocktail.core.event.UIEvent;
cocktail.core.event.MouseEvent.prototype = $extend(cocktail.core.event.UIEvent.prototype,{
	_screenX: null
	,screenX: null
	,_screenY: null
	,screenY: null
	,_clientX: null
	,clientX: null
	,_clientY: null
	,clientY: null
	,_ctrlKey: null
	,ctrlKey: null
	,_shiftKey: null
	,shiftKey: null
	,_altKey: null
	,altKey: null
	,get_altKey: function() {
		return this._altKey;
	}
	,get_shiftKey: function() {
		return this._shiftKey;
	}
	,get_ctrlKey: function() {
		return this._ctrlKey;
	}
	,get_clientY: function() {
		return this._clientY;
	}
	,get_clientX: function() {
		return this._clientX;
	}
	,get_screenX: function() {
		return this._screenX;
	}
	,get_screenY: function() {
		return this._screenY;
	}
	,__class__: cocktail.core.event.MouseEvent
	,__properties__: $extend(cocktail.core.event.UIEvent.prototype.__properties__,{get_altKey:"get_altKey",get_shiftKey:"get_shiftKey",get_ctrlKey:"get_ctrlKey",get_clientY:"get_clientY",get_clientX:"get_clientX",get_screenY:"get_screenY",get_screenX:"get_screenX"})
});
if(!cocktail.core.focus) cocktail.core.focus = {}
cocktail.core.focus.FocusManager = $hxClasses["cocktail.core.focus.FocusManager"] = function() {
};
cocktail.core.focus.FocusManager.__name__ = ["cocktail","core","focus","FocusManager"];
cocktail.core.focus.FocusManager.prototype = {
	_tabList: null
	,invalidate: function() {
		this._tabList = null;
	}
	,getNextFocusedElement: function(reverse,rootElement,activeElement) {
		if(this._tabList == null) this._tabList = this.buildTabList(rootElement);
		var tabListIndex;
		if(activeElement == rootElement) {
			if(reverse == false) tabListIndex = 0; else tabListIndex = this._tabList.length - 1;
		} else {
			tabListIndex = this.getElementTabListIndex(activeElement);
			if(reverse == false) tabListIndex++; else tabListIndex--;
		}
		if(tabListIndex == this._tabList.length) tabListIndex = 0; else if(tabListIndex == -1) tabListIndex = this._tabList.length - 1;
		return this._tabList[tabListIndex];
	}
	,getElementTabListIndex: function(element) {
		var _g1 = 0, _g = this._tabList.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._tabList[i] == element) return i;
		}
		return -1;
	}
	,buildTabList: function(rootElement) {
		var orderedTabList = new Array();
		var indexedTabList = new Array();
		this.doBuildTabList(rootElement,orderedTabList,indexedTabList);
		var _g1 = 0, _g = orderedTabList.length;
		while(_g1 < _g) {
			var i = _g1++;
			indexedTabList.push(orderedTabList[i]);
		}
		return indexedTabList;
	}
	,doBuildTabList: function(htmlElement,orderedTabList,indexedTabList) {
		var _g1 = 0, _g = htmlElement.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(htmlElement.get_childNodes()[i].get_nodeType() == 1) {
				var child = htmlElement.get_childNodes()[i];
				if(child.hasChildNodes() == true) this.doBuildTabList(child,orderedTabList,indexedTabList);
				if(child.isFocusable() == true) {
					if(child.get_tabIndex() == 0 || child.get_tabIndex() == null) orderedTabList.push(child); else if(child.get_tabIndex() > 0) {
						if(indexedTabList.length == 0) indexedTabList.push(child); else {
							var foundSpotFlag = false;
							var _g3 = 0, _g2 = indexedTabList.length;
							while(_g3 < _g2) {
								var j = _g3++;
								if(child.get_tabIndex() < indexedTabList[j].get_tabIndex()) {
									indexedTabList.insert(j,child);
									foundSpotFlag = true;
								}
							}
							if(foundSpotFlag == false) indexedTabList.push(child);
						}
					}
				}
			}
		}
	}
	,__class__: cocktail.core.focus.FocusManager
}
if(!cocktail.core.font) cocktail.core.font = {}
cocktail.core.font.AbstractFontLoader = $hxClasses["cocktail.core.font.AbstractFontLoader"] = function() {
	this._successCallbackArray = new Array();
	this._errorCallbackArray = new Array();
};
cocktail.core.font.AbstractFontLoader.__name__ = ["cocktail","core","font","AbstractFontLoader"];
cocktail.core.font.AbstractFontLoader.prototype = {
	fontData: null
	,_successCallbackArray: null
	,_errorCallbackArray: null
	,load: function(url,name) {
		var extension = url.substr(url.lastIndexOf("."),url.length);
		this.fontData = { url : url, name : name, type : cocktail.core.font.FontType.unknown};
		if(extension == ".ttf") this.fontData.type = cocktail.core.font.FontType.ttf; else if(extension == ".eot") this.fontData.type = cocktail.core.font.FontType.eot; else if(extension == ".otf") this.fontData.type = cocktail.core.font.FontType.otf; else if(extension == ".swf") this.fontData.type = cocktail.core.font.FontType.swf; else this.fontData.type = cocktail.core.font.FontType.unknown;
	}
	,addCallback: function(successCallback,errorCallback) {
		if(successCallback != null) this._successCallbackArray.push(successCallback);
		if(errorCallback != null) this._errorCallbackArray.push(errorCallback);
	}
	,_successCallback: function() {
		var idx;
		var _g1 = 0, _g = this._successCallbackArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			this._successCallbackArray[idx1](this.fontData);
		}
		this.cleanup();
	}
	,_errorCallback: function(errorStr) {
		var idx;
		var _g1 = 0, _g = this._errorCallbackArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			this._errorCallbackArray[idx1](this.fontData,errorStr);
		}
		this.cleanup();
	}
	,cleanup: function() {
		while(this._successCallbackArray.length > 0) this._successCallbackArray.pop();
		while(this._errorCallbackArray.length > 0) this._errorCallbackArray.pop();
	}
	,__class__: cocktail.core.font.AbstractFontLoader
}
cocktail.core.font.AbstractFontManager = $hxClasses["cocktail.core.font.AbstractFontManager"] = function() {
	if(cocktail.core.font.AbstractFontManager._fontLoaderArray == null) cocktail.core.font.AbstractFontManager._fontLoaderArray = new Array();
	if(cocktail.core.font.AbstractFontManager._loadedFonts == null) cocktail.core.font.AbstractFontManager._loadedFonts = new Array();
};
cocktail.core.font.AbstractFontManager.__name__ = ["cocktail","core","font","AbstractFontManager"];
cocktail.core.font.AbstractFontManager._loadedFonts = null;
cocktail.core.font.AbstractFontManager._fontLoaderArray = null;
cocktail.core.font.AbstractFontManager.prototype = {
	getEmbeddedFonts: function() {
		return cocktail.core.font.AbstractFontManager._loadedFonts;
	}
	,getSystemFonts: function() {
		throw "Virtual method should be implemented in sub class";
		return null;
	}
	,hasFont: function(fontName) {
		var fontDataArray;
		var idx;
		fontDataArray = this.getEmbeddedFonts();
		var _g1 = 0, _g = fontDataArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			if(fontDataArray[idx1].name == fontName) return true;
		}
		fontDataArray = this.getSystemFonts();
		var _g1 = 0, _g = fontDataArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			if(fontDataArray[idx1].name == fontName) return true;
		}
		return false;
	}
	,getFontMetrics: function(fontFamily,fontSize) {
		throw "Virtual method should be implemented in sub class";
		return null;
	}
	,createNativeTextElement: function(text,computedStyle) {
		throw "Virtual method should be implemented in sub class";
		return null;
	}
	,applyTextTransform: function(text,textTransform) {
		switch( (textTransform)[1] ) {
		case 1:
			text = text.toUpperCase();
			break;
		case 2:
			text = text.toLowerCase();
			break;
		case 0:
			text = this.capitalizeText(text);
			break;
		case 3:
			break;
		}
		return text;
	}
	,capitalizeText: function(text) {
		var capitalizedText = text.charAt(0);
		var _g1 = 1, _g = text.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
		}
		return capitalizedText;
	}
	,loadFont: function(url,name,successCallback,errorCallback) {
		var fontLoader;
		var idx;
		var _g1 = 0, _g = cocktail.core.font.AbstractFontManager._fontLoaderArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			if(cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1].fontData.url == url && cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1].fontData.name == name) {
				cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1].addCallback(successCallback,errorCallback);
				return;
			}
		}
		fontLoader = new cocktail.port.browser.FontLoader();
		fontLoader.addCallback(this._onFontLoadingSuccess.$bind(this),this._onFontLoadingError.$bind(this));
		fontLoader.addCallback(successCallback,errorCallback);
		fontLoader.load(url,name);
		cocktail.core.font.AbstractFontManager._fontLoaderArray.push(fontLoader);
	}
	,_onFontLoadingSuccess: function(fontData) {
		cocktail.core.font.AbstractFontManager._loadedFonts.push(fontData);
		if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font was successfully loaded",{ fileName : "AbstractFontManager.hx", lineNumber : 223, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingSuccess"});
	}
	,_onFontLoadingError: function(fontData,errorStr) {
		haxe.Log.trace("font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 232, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingError"});
		if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 238, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingError"});
	}
	,_removeFontLoader: function(fontData) {
		var fontLoader;
		var idx;
		var _g1 = 0, _g = cocktail.core.font.AbstractFontManager._fontLoaderArray.length;
		while(_g1 < _g) {
			var idx1 = _g1++;
			if(cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1].fontData.url == fontData.url && cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1].fontData.name == fontData.name) {
				cocktail.core.font.AbstractFontManager._fontLoaderArray.remove(cocktail.core.font.AbstractFontManager._fontLoaderArray[idx1]);
				return true;
			}
		}
		return false;
	}
	,__class__: cocktail.core.font.AbstractFontManager
}
cocktail.core.font.FontType = $hxClasses["cocktail.core.font.FontType"] = { __ename__ : ["cocktail","core","font","FontType"], __constructs__ : ["ttf","otf","eot","swf","system","unknown"] }
cocktail.core.font.FontType.ttf = ["ttf",0];
cocktail.core.font.FontType.ttf.toString = $estr;
cocktail.core.font.FontType.ttf.__enum__ = cocktail.core.font.FontType;
cocktail.core.font.FontType.otf = ["otf",1];
cocktail.core.font.FontType.otf.toString = $estr;
cocktail.core.font.FontType.otf.__enum__ = cocktail.core.font.FontType;
cocktail.core.font.FontType.eot = ["eot",2];
cocktail.core.font.FontType.eot.toString = $estr;
cocktail.core.font.FontType.eot.__enum__ = cocktail.core.font.FontType;
cocktail.core.font.FontType.swf = ["swf",3];
cocktail.core.font.FontType.swf.toString = $estr;
cocktail.core.font.FontType.swf.__enum__ = cocktail.core.font.FontType;
cocktail.core.font.FontType.system = ["system",4];
cocktail.core.font.FontType.system.toString = $estr;
cocktail.core.font.FontType.system.__enum__ = cocktail.core.font.FontType;
cocktail.core.font.FontType.unknown = ["unknown",5];
cocktail.core.font.FontType.unknown.toString = $estr;
cocktail.core.font.FontType.unknown.__enum__ = cocktail.core.font.FontType;
if(!cocktail.core.geom) cocktail.core.geom = {}
cocktail.core.geom.Matrix = $hxClasses["cocktail.core.geom.Matrix"] = function(data) {
	this.setData(data);
};
cocktail.core.geom.Matrix.__name__ = ["cocktail","core","geom","Matrix"];
cocktail.core.geom.Matrix.prototype = {
	_data: null
	,data: null
	,identity: function() {
		this._data = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : 0.0, f : 0.0};
	}
	,setData: function(data) {
		this._data = data;
		if(this._data == null) this.identity();
		return this._data;
	}
	,getData: function() {
		return this._data;
	}
	,concatenate: function(matrix) {
		var currentMatrixData = this._data;
		var targetMatrixData = matrix.getData();
		var a = currentMatrixData.a * targetMatrixData.a + currentMatrixData.c * targetMatrixData.b;
		var b = currentMatrixData.b * targetMatrixData.a + currentMatrixData.d * targetMatrixData.b;
		var c = currentMatrixData.a * targetMatrixData.c + currentMatrixData.c * targetMatrixData.d;
		var d = currentMatrixData.b * targetMatrixData.c + currentMatrixData.d * targetMatrixData.d;
		var e = currentMatrixData.a * targetMatrixData.e + currentMatrixData.c * targetMatrixData.f + currentMatrixData.e;
		var f = currentMatrixData.b * targetMatrixData.e + currentMatrixData.d * targetMatrixData.f + currentMatrixData.f;
		var concatenatedMatrixData = { a : a, b : b, c : c, d : d, e : e, f : f};
		this.setData(concatenatedMatrixData);
	}
	,translate: function(x,y) {
		var translationMatrixData = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : x, f : y};
		var translationMatrix = new cocktail.core.geom.Matrix(translationMatrixData);
		this.concatenate(translationMatrix);
	}
	,rotate: function(angle,registrationPoint) {
		var rotatedMatrix = new cocktail.core.geom.Matrix();
		rotatedMatrix.translate(registrationPoint.x,registrationPoint.y);
		var a = 0.0;
		var b = 0.0;
		var c = 0.0;
		var d = 0.0;
		if(angle == Math.PI / 2) {
			a = d = 0.0;
			c = b = 1.0;
		} else if(angle == Math.PI) {
			a = d = -1.0;
			c = b = 0.0;
		} else if(angle == Math.PI * 3 / 2) {
			a = d = 0.0;
			c = b = -1.0;
		} else {
			a = d = Math.cos(angle);
			c = b = Math.sin(angle);
		}
		var rotationMatrixData = { a : a, b : b, c : c * -1.0, d : d, e : 0.0, f : 0.0};
		var rotationMatrix = new cocktail.core.geom.Matrix(rotationMatrixData);
		rotatedMatrix.concatenate(rotationMatrix);
		rotatedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(rotatedMatrix);
	}
	,scale: function(scaleX,scaleY,registrationPoint) {
		var scaledMatrix = new cocktail.core.geom.Matrix();
		scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
		var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
		var scalingMatrix = new cocktail.core.geom.Matrix(scalingMatrixData);
		scaledMatrix.concatenate(scalingMatrix);
		scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(scaledMatrix);
	}
	,skew: function(skewX,skewY,registrationPoint) {
		var skewedMatrix = new cocktail.core.geom.Matrix();
		skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
		var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
		var skewingMatrix = new cocktail.core.geom.Matrix(skewingMatrixData);
		skewedMatrix.concatenate(skewingMatrix);
		skewedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(skewedMatrix);
	}
	,setRotation: function(angle,registrationPoint) {
		var currentRotation = this.getRotation();
		var resetAngle = Math.PI * 2 - currentRotation;
		this.rotate(resetAngle,registrationPoint);
		this.rotate(angle,registrationPoint);
	}
	,getRotation: function() {
		var flip = this.getFlip();
		var scaleX = this.getScaleX();
		var skewX = this.getSkewX();
		var actualScaleX = Math.sqrt(scaleX * scaleX + skewX * skewX);
		var scaleY = this.getScaleY();
		var skewY = this.getSkewY() * flip;
		var actualScaleY = Math.sqrt(scaleY * scaleY + skewY * skewY);
		var rotationInRad = Math.atan2(skewY / actualScaleY - skewX / actualScaleX,scaleY / actualScaleY + scaleX / actualScaleX);
		if(rotationInRad < 0) rotationInRad = Math.PI + rotationInRad;
		return rotationInRad;
	}
	,getFlip: function() {
		var scaleX = this.getScaleX();
		var scaleXSign = 0;
		if(scaleX >= 0) scaleXSign = 1; else scaleXSign = -1;
		var scaleY = this.getScaleY();
		var scaleYSign = scaleY >= 0?1:-1;
		var skewX = this.getSkewX();
		var skewXSign = skewX >= 0?1:-1;
		var skewY = this.getSkewY();
		var skewYSign = skewY >= 0?1:-1;
		if(scaleXSign == scaleYSign && skewXSign == skewYSign * -1) return 1;
		if(scaleXSign == scaleYSign * -1 && skewXSign == skewYSign) return -1;
		return 1;
	}
	,setScaleX: function(scaleXFactor,registrationPoint) {
		var currentScaleX = this.getScaleX();
		var resetScaleX = 1 / currentScaleX;
		this.scale(resetScaleX,1,registrationPoint);
		this.scale(scaleXFactor,1,registrationPoint);
	}
	,getScaleX: function() {
		return this._data.a;
	}
	,setScaleY: function(scaleYFactor,registrationPoint) {
		var currentScaleY = this.getScaleY();
		var resetScaleY = 1 / currentScaleY;
		this.scale(1,resetScaleY,registrationPoint);
		this.scale(1,scaleYFactor,registrationPoint);
	}
	,getScaleY: function() {
		return this._data.d;
	}
	,setTranslationX: function(translationX) {
		var currentTranslationX = this.getTranslationX();
		var resetTranslationX = currentTranslationX * -1;
		this.translate(resetTranslationX,0);
		this.translate(translationX,0);
	}
	,getTranslationX: function() {
		return this._data.e;
	}
	,setTranslationY: function(translationY) {
		var currentTranslationY = this.getTranslationY();
		var resetTranslationY = currentTranslationY * -1;
		this.translate(0,resetTranslationY);
		this.translate(0,translationY);
	}
	,getTranslationY: function() {
		return this._data.f;
	}
	,getSkewX: function() {
		return this._data.c;
	}
	,getSkewY: function() {
		return this._data.b;
	}
	,__class__: cocktail.core.geom.Matrix
	,__properties__: {set_data:"setData",get_data:"getData"}
}
if(!cocktail.core.html) cocktail.core.html = {}
cocktail.core.html.AbstractHTMLElement = $hxClasses["cocktail.core.html.AbstractHTMLElement"] = function(tagName) {
	cocktail.core.dom.Element.call(this,tagName);
	this.init();
};
cocktail.core.html.AbstractHTMLElement.__name__ = ["cocktail","core","html","AbstractHTMLElement"];
cocktail.core.html.AbstractHTMLElement.__interfaces__ = [cocktail.core.event.IEventTarget];
cocktail.core.html.AbstractHTMLElement.__super__ = cocktail.core.dom.Element;
cocktail.core.html.AbstractHTMLElement.prototype = $extend(cocktail.core.dom.Element.prototype,{
	_mouse: null
	,_onClick: null
	,onclick: null
	,_onMouseDown: null
	,onmousedown: null
	,_onMouseUp: null
	,onmouseup: null
	,_onMouseOver: null
	,onmouseover: null
	,_onMouseOut: null
	,onmouseout: null
	,_onMouseMove: null
	,onmousemove: null
	,_keyboard: null
	,_onKeyDown: null
	,onkeydown: null
	,_onKeyUp: null
	,onkeyup: null
	,_tabIndex: null
	,tabIndex: null
	,_onFocus: null
	,onfocus: null
	,_onBlur: null
	,onblur: null
	,_onScroll: null
	,onscroll: null
	,scrollTop: null
	,scrollLeft: null
	,scrollHeight: null
	,scrollWidth: null
	,_nativeElement: null
	,nativeElement: null
	,id: null
	,innerHTML: null
	,offsetParent: null
	,offsetWidth: null
	,offsetHeight: null
	,offsetLeft: null
	,offsetTop: null
	,clientWidth: null
	,clientHeight: null
	,clientLeft: null
	,clientTop: null
	,_coreStyle: null
	,coreStyle: null
	,_style: null
	,style: null
	,init: function() {
		this.initNativeElement();
		this.initMouse();
		this.initKeyboard();
		this.initCoreStyle();
		this.initStyle();
		this.initId();
	}
	,initNativeElement: function() {
		this._nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.semantic(this._tagName));
	}
	,initMouse: function() {
		this._mouse = new cocktail.port.browser.Mouse(this);
	}
	,initKeyboard: function() {
		this._keyboard = new cocktail.port.browser.Keyboard(this);
	}
	,initCoreStyle: function() {
		this._coreStyle = new cocktail.core.style.ContainerCoreStyle(this);
	}
	,initStyle: function() {
		this._style = new cocktail.port.browser.Style(this._coreStyle);
	}
	,initId: function() {
		var id = new cocktail.core.dom.Attr("id");
		this.setIdAttributeNode(id,true);
	}
	,appendChild: function(newChild) {
		cocktail.core.dom.Element.prototype.appendChild.call(this,newChild);
		this._coreStyle.invalidate();
		return newChild;
	}
	,removeChild: function(oldChild) {
		cocktail.core.dom.Element.prototype.removeChild.call(this,oldChild);
		this._coreStyle.invalidate();
		return oldChild;
	}
	,click: function() {
		if(this._onClick != null) this.onClickCallback(new cocktail.core.event.MouseEvent("click",this,0,0,0,0,0,false,false,false));
	}
	,set_onClick: function(value) {
		this._onClick = value;
		if(this._onClick == null) this._mouse.set_onClick(null); else this._mouse.set_onClick(this.onClickCallback.$bind(this));
		return value;
	}
	,get_onClick: function() {
		return this._onClick;
	}
	,set_onMouseDown: function(value) {
		this._onMouseDown = value;
		if(this._onMouseDown == null) this._mouse.setOnMouseDown(null); else this._mouse.setOnMouseDown(this.onMouseDownCallback.$bind(this));
		return value;
	}
	,get_onMouseDown: function() {
		return this._onMouseDown;
	}
	,set_onMouseUp: function(value) {
		this._onMouseUp = value;
		if(this._onMouseUp == null) this._mouse.setOnMouseUp(null); else this._mouse.setOnMouseUp(this.onMouseUpCallback.$bind(this));
		return value;
	}
	,get_onMouseUp: function() {
		return this._onMouseUp;
	}
	,set_onMouseOver: function(value) {
		this._onMouseOver = value;
		if(this._onMouseOver == null) this._mouse.setOnMouseOver(null); else this._mouse.setOnMouseOver(this.onMouseOverCallback.$bind(this));
		return value;
	}
	,get_onMouseOver: function() {
		return this._onMouseOver;
	}
	,set_onMouseOut: function(value) {
		this._onMouseOut = value;
		if(this._onMouseOut == null) this._mouse.setOnMouseOut(null); else this._mouse.setOnMouseOut(this.onMouseOutCallback.$bind(this));
		return value;
	}
	,get_onMouseOut: function() {
		return this._onMouseOut;
	}
	,set_onMouseMove: function(value) {
		this._onMouseMove = value;
		if(this._onMouseMove == null) this._mouse.setOnMouseMove(null); else this._mouse.setOnMouseMove(this.onMouseMoveCallback.$bind(this));
		return value;
	}
	,get_onMouseMove: function() {
		return this._onMouseMove;
	}
	,onClickCallback: function(mouseEvent) {
		this._onClick(mouseEvent);
	}
	,onMouseDownCallback: function(mouseEvent) {
		this._onMouseDown(mouseEvent);
	}
	,onMouseUpCallback: function(mouseEvent) {
		this._onMouseUp(mouseEvent);
	}
	,onMouseMoveCallback: function(mouseEvent) {
		this._onMouseMove(mouseEvent);
	}
	,onMouseOverCallback: function(mouseEvent) {
		this._onMouseOver(mouseEvent);
	}
	,onMouseOutCallback: function(mouseEvent) {
		this._onMouseOut(mouseEvent);
	}
	,set_onKeyDown: function(value) {
		this._onKeyDown = value;
		if(this._onKeyDown == null) this._keyboard.setOnKeyDown(null); else this._keyboard.setOnKeyDown(this.onKeyDownCallback.$bind(this));
		return value;
	}
	,get_onKeyDown: function() {
		return this._keyboard.getOnKeyDown();
	}
	,set_onKeyUp: function(value) {
		this._onKeyUp = value;
		if(this._onKeyUp == null) this._keyboard.setOnKeyUp(null); else this._keyboard.setOnKeyUp(this.onKeyUpCallback.$bind(this));
		return value;
	}
	,get_onKeyUp: function() {
		return this._keyboard.getOnKeyUp();
	}
	,onKeyDownCallback: function(keyEventData) {
		this._onKeyDown(keyEventData);
	}
	,onKeyUpCallback: function(keyEventData) {
		this._onKeyUp(keyEventData);
	}
	,isFocusable: function() {
		if(this.get_parentNode() == null) return false; else if(this.isDefaultFocusable() == true) return true; else if(this.get_tabIndex() != null) {
			if(this.get_tabIndex() > 0) return true;
		}
		return false;
	}
	,isDefaultFocusable: function() {
		return false;
	}
	,focus: function() {
		if(this.isFocusable() == true) {
			var htmlDocument = this.get_ownerDocument();
			htmlDocument.set_activeElement(this);
		}
	}
	,blur: function() {
		var htmlDocument = this.get_ownerDocument();
		htmlDocument.get_body().focus();
	}
	,set_onFocus: function(value) {
		return this._onFocus = value;
	}
	,get_onFocus: function() {
		return this._onFocus;
	}
	,set_onBlur: function(value) {
		return this._onBlur = value;
	}
	,get_onBlur: function() {
		return this._onBlur;
	}
	,set_tabIndex: function(value) {
		return this._tabIndex = value;
	}
	,get_tabIndex: function() {
		return this._tabIndex;
	}
	,set_onScroll: function(value) {
		return this._onScroll = value;
	}
	,get_onScroll: function() {
		return this._onScroll;
	}
	,onScrollCallback: function(event) {
		if(this._onScroll != null) this._onScroll(event);
	}
	,get_scrollHeight: function() {
		return -1;
	}
	,get_scrollWidth: function() {
		return -1;
	}
	,set_scrollLeft: function(value) {
		return -1;
	}
	,get_scrollLeft: function() {
		return -1;
	}
	,set_scrollTop: function(value) {
		return -1;
	}
	,get_scrollTop: function() {
		return -1;
	}
	,get_nativeElement: function() {
		return this._nativeElement;
	}
	,get_id: function() {
		return this.getAttribute("id");
	}
	,set_id: function(value) {
		this.setAttribute("id",value);
		return value;
	}
	,set_innerHTML: function(value) {
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.removeChild(this._childNodes[i]);
		}
		this.appendChild(cocktail.core.hxtml.HxtmlConverter.getNode(value));
		return value;
	}
	,get_innerHTML: function() {
		return "";
	}
	,get_offsetParent: function() {
		return this._coreStyle.getFirstPositionedAncestor();
	}
	,get_offsetWidth: function() {
		this._coreStyle.invalidate(true);
		var computedStyle = this._coreStyle.getComputedStyle();
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	,get_offsetHeight: function() {
		this._coreStyle.invalidate(true);
		var computedStyle = this._coreStyle.getComputedStyle();
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	,get_offsetLeft: function() {
		this._coreStyle.invalidate(true);
		var firstPositionedAncestor = this.get_offsetParent();
		var offsetLeft = 0;
		if(firstPositionedAncestor != null) {
			var parent = this.get_parentNode();
			offsetLeft = parent.get_coreStyle().getComputedStyle().paddingLeft + parent.get_coreStyle().getComputedStyle().marginLeft;
			while(parent != firstPositionedAncestor) {
				offsetLeft += parent.get_coreStyle().getComputedStyle().paddingLeft + parent.get_coreStyle().getComputedStyle().marginLeft;
				parent = parent.get_parentNode();
			}
		}
		return offsetLeft;
	}
	,get_offsetTop: function() {
		this._coreStyle.invalidate(true);
		var firstPositionedAncestor = this.get_offsetParent();
		var offsetTop = 0;
		if(firstPositionedAncestor != null) {
			var parent = this.get_parentNode();
			offsetTop = parent.get_coreStyle().getComputedStyle().paddingTop + parent.get_coreStyle().getComputedStyle().marginTop;
			while(parent != firstPositionedAncestor) {
				offsetTop += parent.get_coreStyle().getComputedStyle().paddingTop + parent.get_coreStyle().getComputedStyle().marginTop;
				parent = parent.get_parentNode();
			}
		}
		return offsetTop;
	}
	,get_clientWidth: function() {
		this._coreStyle.invalidate(true);
		var computedStyle = this._coreStyle.getComputedStyle();
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	,get_clientHeight: function() {
		this._coreStyle.invalidate(true);
		var computedStyle = this._coreStyle.getComputedStyle();
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	,get_clientTop: function() {
		this._coreStyle.invalidate(true);
		return 0;
	}
	,get_clientLeft: function() {
		this._coreStyle.invalidate(true);
		return 0;
	}
	,get_coreStyle: function() {
		return this._coreStyle;
	}
	,get_style: function() {
		return this._style;
	}
	,__class__: cocktail.core.html.AbstractHTMLElement
	,__properties__: $extend(cocktail.core.dom.Element.prototype.__properties__,{get_style:"get_style",get_coreStyle:"get_coreStyle",get_clientTop:"get_clientTop",get_clientLeft:"get_clientLeft",get_clientHeight:"get_clientHeight",get_clientWidth:"get_clientWidth",get_offsetTop:"get_offsetTop",get_offsetLeft:"get_offsetLeft",get_offsetHeight:"get_offsetHeight",get_offsetWidth:"get_offsetWidth",get_offsetParent:"get_offsetParent",set_innerHTML:"set_innerHTML",get_innerHTML:"get_innerHTML",set_id:"set_id",get_id:"get_id",get_nativeElement:"get_nativeElement",get_scrollWidth:"get_scrollWidth",get_scrollHeight:"get_scrollHeight",set_scrollLeft:"set_scrollLeft",get_scrollLeft:"get_scrollLeft",set_scrollTop:"set_scrollTop",get_scrollTop:"get_scrollTop",set_onscroll:"set_onScroll",get_onscroll:"get_onScroll",set_onblur:"set_onBlur",get_onblur:"get_onBlur",set_onfocus:"set_onFocus",get_onfocus:"get_onFocus",set_tabIndex:"set_tabIndex",get_tabIndex:"get_tabIndex",set_onkeyup:"set_onKeyUp",get_onkeyup:"get_onKeyUp",set_onkeydown:"set_onKeyDown",get_onkeydown:"get_onKeyDown",set_onmousemove:"set_onMouseMove",get_onmousemove:"get_onMouseMove",set_onmouseout:"set_onMouseOut",get_onmouseout:"get_onMouseOut",set_onmouseover:"set_onMouseOver",get_onmouseover:"get_onMouseOver",set_onmouseup:"set_onMouseUp",get_onmouseup:"get_onMouseUp",set_onmousedown:"set_onMouseDown",get_onmousedown:"get_onMouseDown",set_onclick:"set_onClick",get_onclick:"get_onClick"})
});
cocktail.port.browser.HTMLElement = $hxClasses["cocktail.port.browser.HTMLElement"] = function(tagName) {
	cocktail.core.html.AbstractHTMLElement.call(this,tagName);
};
cocktail.port.browser.HTMLElement.__name__ = ["cocktail","port","browser","HTMLElement"];
cocktail.port.browser.HTMLElement.__super__ = cocktail.core.html.AbstractHTMLElement;
cocktail.port.browser.HTMLElement.prototype = $extend(cocktail.core.html.AbstractHTMLElement.prototype,{
	removeChild: function(oldChild) {
		cocktail.core.html.AbstractHTMLElement.prototype.removeChild.call(this,oldChild);
		switch(oldChild.get_nodeType()) {
		case 1:
			var childHTMLElement = oldChild;
			this._nativeElement.removeChild(childHTMLElement.get_nativeElement());
			break;
		case 3:
			var childTextElement = oldChild;
			this._nativeElement.removeChild(childTextElement.get_nativeElement());
			break;
		default:
		}
		return oldChild;
	}
	,appendChild: function(newChild) {
		cocktail.core.html.AbstractHTMLElement.prototype.appendChild.call(this,newChild);
		switch(newChild.get_nodeType()) {
		case 1:
			var childHTMLElement = newChild;
			this._nativeElement.appendChild(childHTMLElement.get_nativeElement());
			break;
		case 3:
			var childTextElement = newChild;
			this._nativeElement.appendChild(childTextElement.get_nativeElement());
			break;
		default:
		}
		return newChild;
	}
	,insertBefore: function(newChild,refChild) {
		cocktail.core.html.AbstractHTMLElement.prototype.insertBefore.call(this,newChild,refChild);
		this._nativeElement.insertBefore(newChild.nativeElement,refChild.nativeElement);
		return newChild;
	}
	,replaceChild: function(newChild,oldChild) {
		cocktail.core.html.AbstractHTMLElement.prototype.replaceChild.call(this,newChild,oldChild);
		this._nativeElement.replaceChild(newChild.nativeElement,refChild.nativeElement);
		return oldChild;
	}
	,setAttribute: function(name,value) {
		cocktail.core.html.AbstractHTMLElement.prototype.setAttribute.call(this,name,value);
		this._nativeElement.setAttribute(name,value);
	}
	,get_offsetWidth: function() {
		return this._nativeElement.offsetWidth;
	}
	,get_offsetHeight: function() {
		return this._nativeElement.offsetHeight;
	}
	,get_offsetLeft: function() {
		return this._nativeElement.offsetLeft;
	}
	,get_offsetTop: function() {
		return this._nativeElement.offsetTop;
	}
	,get_clientWidth: function() {
		return this._nativeElement.clientWidth;
	}
	,get_clientHeight: function() {
		return this._nativeElement.clientHeight;
	}
	,get_clientLeft: function() {
		return this._nativeElement.clientLeft;
	}
	,get_clientTop: function() {
		return this._nativeElement.clientTop;
	}
	,set_scrollTop: function(value) {
		return this._nativeElement.scrollTop = value;
	}
	,get_scrollTop: function() {
		return this._nativeElement.scrollTop;
	}
	,set_scrollLeft: function(value) {
		return this._nativeElement.scrollLeft = value;
	}
	,get_scrollLeft: function() {
		return this._nativeElement.scrollLeft;
	}
	,get_scrollWidth: function() {
		return this._nativeElement.scrollWidth;
	}
	,get_scrollHeight: function() {
		return this._nativeElement.scrollHeight;
	}
	,set_onFocus: function(value) {
		if(value == null) this._nativeElement.removeEventListener("focus",this.onNativeFocus.$bind(this)); else this._nativeElement.addEventListener("focus",this.onNativeFocus.$bind(this));
		return this._onFocus = value;
	}
	,set_onBlur: function(value) {
		if(value == null) this._nativeElement.removeEventListener("blur",this.onNativeBlur.$bind(this)); else this._nativeElement.addEventListener("blur",this.onNativeBlur.$bind(this));
		return this._onBlur = value;
	}
	,set_tabIndex: function(value) {
		cocktail.core.html.AbstractHTMLElement.prototype.set_tabIndex.call(this,value);
		this._nativeElement.tabIndex = value;
		return this._tabIndex;
	}
	,focus: function() {
		cocktail.core.html.AbstractHTMLElement.prototype.focus.call(this);
		this._nativeElement.focus();
	}
	,blur: function() {
		cocktail.core.html.AbstractHTMLElement.prototype.blur.call(this);
		this._nativeElement.blur();
	}
	,onNativeFocus: function(event) {
		if(this._onFocus != null) this._onFocus(new cocktail.core.event.Event("focus",this));
	}
	,onNativeBlur: function(event) {
		if(this._onBlur != null) this._onBlur(new cocktail.core.event.Event("blur",this));
	}
	,set_onScroll: function(value) {
		this._nativeElement.removeEventListener("scroll",this.onNativeScroll.$bind(this));
		this._onScroll = value;
		if(this._onScroll != null) this._nativeElement.addEventListener("scroll",this.onNativeScroll.$bind(this));
		return value;
	}
	,onNativeScroll: function(event) {
		this.onScrollCallback(new cocktail.core.event.Event("scroll",this));
	}
	,__class__: cocktail.port.browser.HTMLElement
});
cocktail.core.html.AbstractHTMLAnchorElement = $hxClasses["cocktail.core.html.AbstractHTMLAnchorElement"] = function() {
	cocktail.port.browser.HTMLElement.call(this,"a");
	this._target = "_self";
};
cocktail.core.html.AbstractHTMLAnchorElement.__name__ = ["cocktail","core","html","AbstractHTMLAnchorElement"];
cocktail.core.html.AbstractHTMLAnchorElement.__super__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.AbstractHTMLAnchorElement.prototype = $extend(cocktail.port.browser.HTMLElement.prototype,{
	_href: null
	,href: null
	,_target: null
	,target: null
	,initNativeElement: function() {
		this._nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.anchor);
	}
	,set_onMouseDown: function(value) {
		this._onMouseDown = value;
		this._mouse.setOnMouseDown(this.onMouseDownCallback.$bind(this));
		return this._onMouseDown;
	}
	,set_onMouseOver: function(value) {
		this._onMouseOver = value;
		this._mouse.setOnMouseOver(this.onMouseOverCallback.$bind(this));
		return this._onMouseOver;
	}
	,set_onMouseOut: function(value) {
		this._onMouseOut = value;
		this._mouse.setOnMouseOut(this.onMouseOutCallback.$bind(this));
		return this._onMouseOut;
	}
	,onMouseDownCallback: function(mouseEvent) {
		if(this._onMouseDown != null) this._onMouseDown(mouseEvent);
		if(mouseEvent.get_defaultPrevented() == false) this.openDocument();
	}
	,onMouseOverCallback: function(mouseEvent) {
		if(this._onMouseOver != null) this._onMouseOver(mouseEvent);
		this.displayPointerCursor();
	}
	,onMouseOutCallback: function(mouseEvent) {
		if(this._onMouseOut != null) this._onMouseOut(mouseEvent);
		this.hidePointerCursor();
	}
	,isDefaultFocusable: function() {
		if(this.get_href() != null) return true; else return false;
	}
	,openDocument: function() {
	}
	,displayPointerCursor: function() {
		cocktail.core.mouse.MouseCursorManager.setMouseCursor(cocktail.core.mouse.MouseCursorValue["native"](cocktail.core.mouse.NativeOSMouseCursorValue.pointer));
	}
	,hidePointerCursor: function() {
		cocktail.core.mouse.MouseCursorManager.setMouseCursor(cocktail.core.mouse.MouseCursorValue.cssAuto);
	}
	,set_href: function(value) {
		this._href = value;
		this.set_onMouseDown(this._onMouseDown);
		this.set_onMouseOver(this._onMouseOver);
		this.set_onMouseOut(this._onMouseOut);
		return value;
	}
	,get_href: function() {
		return this._href;
	}
	,set_target: function(value) {
		this._target = value;
		this.set_onMouseDown(this._onMouseDown);
		this.set_onMouseOver(this._onMouseOver);
		this.set_onMouseOut(this._onMouseOut);
		return value;
	}
	,get_target: function() {
		return this._target;
	}
	,__class__: cocktail.core.html.AbstractHTMLAnchorElement
	,__properties__: $extend(cocktail.port.browser.HTMLElement.prototype.__properties__,{set_target:"set_target",get_target:"get_target",set_href:"set_href",get_href:"get_href"})
});
cocktail.core.html.AbstractHTMLDocument = $hxClasses["cocktail.core.html.AbstractHTMLDocument"] = function() {
	cocktail.core.dom.Document.call(this);
	this._body = this.createElement("body");
	this._documentElement = this.createElement("html");
	this._documentElement.appendChild(this._body);
	this._nativeElements = new Array();
	this._focusManager = new cocktail.core.focus.FocusManager();
	this._activeElement = this._body;
	this._window = new cocktail.port.browser.Window();
	this._window.set_onResize(this.onWindowResize.$bind(this));
	this.initKeyboardListeners();
};
cocktail.core.html.AbstractHTMLDocument.__name__ = ["cocktail","core","html","AbstractHTMLDocument"];
cocktail.core.html.AbstractHTMLDocument.__super__ = cocktail.core.dom.Document;
cocktail.core.html.AbstractHTMLDocument.prototype = $extend(cocktail.core.dom.Document.prototype,{
	_body: null
	,body: null
	,_window: null
	,_nativeElements: null
	,_activeElement: null
	,activeElement: null
	,_focusManager: null
	,_keyboard: null
	,initKeyboardListeners: function() {
		var keyboard = new cocktail.port.browser.Keyboard(this._body);
		keyboard.setOnKeyDown(this.onKeyDown.$bind(this));
		keyboard.setOnKeyUp(this.onKeyUp.$bind(this));
	}
	,createElement: function(tagName) {
		var element;
		switch(tagName.toLowerCase()) {
		case "img":
			element = new cocktail.port.browser.HTMLImageElement();
			break;
		case "canvas":
			element = new cocktail.core.html.HTMLCanvasElement();
			break;
		case "input":
			element = new cocktail.port.browser.HTMLInputElement();
			break;
		case "a":
			element = new cocktail.port.browser.HTMLAnchorElement();
			break;
		case "html":
			element = new cocktail.port.browser.HTMLHtmlElement();
			break;
		case "body":
			element = new cocktail.core.html.HTMLBodyElement();
			break;
		default:
			element = new cocktail.port.browser.HTMLElement(tagName);
		}
		element.set_ownerDocument(this);
		return element;
	}
	,invalidate: function(immediate) {
		if(immediate == null) immediate = false;
		if(immediate == false) this.scheduleLayoutAndRender(); else this.layoutAndRender();
	}
	,onKeyDown: function(keyboardEvent) {
		switch(keyboardEvent.get_key()) {
		case 9:
			this.set_activeElement(this._focusManager.getNextFocusedElement(keyboardEvent.get_shiftKey() == true,this._body,this.get_activeElement()));
			break;
		case 13:case 32:
			this.get_activeElement().click();
			break;
		default:
			if(this.get_activeElement().get_onKeyDown() != null) (this.get_activeElement().get_onKeyDown())(keyboardEvent);
		}
	}
	,onKeyUp: function(keyEventData) {
		if(this.get_activeElement().get_onKeyUp() != null) (this.get_activeElement().get_onKeyUp())(keyEventData);
	}
	,layoutAndRender: function() {
		this.layout();
		this.render();
	}
	,layout: function() {
		var bodyCoreStyle = this._body.get_coreStyle();
		bodyCoreStyle.layout();
	}
	,render: function() {
		this.detachNativeElements(this._nativeElements);
		this._nativeElements = this._body.get_coreStyle().getElementRenderer().getLayerRenderer().render();
		this.attachNativeElements(this._nativeElements);
	}
	,attachNativeElement: function(nativeElement) {
	}
	,detachNativeElement: function(nativeElement) {
	}
	,attachNativeElements: function(nativeElements) {
		var _g1 = 0, _g = nativeElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.attachNativeElement(nativeElements[i]);
		}
	}
	,detachNativeElements: function(nativeElements) {
		var _g1 = 0, _g = nativeElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.detachNativeElement(nativeElements[i]);
		}
	}
	,scheduleLayoutAndRender: function() {
		var layoutAndRenderDelegate = this.layoutAndRender.$bind(this);
		haxe.Timer.delay(function() {
			layoutAndRenderDelegate();
		},1);
	}
	,onWindowResize: function(event) {
		this.scheduleLayoutAndRender();
	}
	,get_body: function() {
		return this._body;
	}
	,set_activeElement: function(value) {
		if(value == null) return this._activeElement;
		if(value != this.get_activeElement()) {
			if(this.get_activeElement().get_onBlur() != null) (this.get_activeElement().get_onBlur())(new cocktail.core.event.Event("blur",this.get_activeElement()));
			this._activeElement = value;
			if(this._activeElement.get_onFocus() != null) (this._activeElement.get_onFocus())(new cocktail.core.event.Event("focus",this._activeElement));
		}
		return this._activeElement;
	}
	,get_activeElement: function() {
		return this._activeElement;
	}
	,__class__: cocktail.core.html.AbstractHTMLDocument
	,__properties__: $extend(cocktail.core.dom.Document.prototype.__properties__,{set_activeElement:"set_activeElement",get_activeElement:"get_activeElement",get_body:"get_body"})
});
cocktail.core.html.AbstractHTMLHtmlElement = $hxClasses["cocktail.core.html.AbstractHTMLHtmlElement"] = function() {
	cocktail.port.browser.HTMLElement.call(this,"html");
};
cocktail.core.html.AbstractHTMLHtmlElement.__name__ = ["cocktail","core","html","AbstractHTMLHtmlElement"];
cocktail.core.html.AbstractHTMLHtmlElement.__super__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.AbstractHTMLHtmlElement.prototype = $extend(cocktail.port.browser.HTMLElement.prototype,{
	__class__: cocktail.core.html.AbstractHTMLHtmlElement
});
cocktail.core.html.EmbeddedElement = $hxClasses["cocktail.core.html.EmbeddedElement"] = function(tagName) {
	cocktail.port.browser.HTMLElement.call(this,tagName);
};
cocktail.core.html.EmbeddedElement.__name__ = ["cocktail","core","html","EmbeddedElement"];
cocktail.core.html.EmbeddedElement.__super__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.EmbeddedElement.prototype = $extend(cocktail.port.browser.HTMLElement.prototype,{
	_intrinsicHeight: null
	,intrinsicHeight: null
	,_intrinsicWidth: null
	,intrinsicWidth: null
	,_intrinsicRatio: null
	,intrinsicRatio: null
	,_height: null
	,height: null
	,_width: null
	,width: null
	,_embeddedAsset: null
	,embeddedAsset: null
	,init: function() {
		this.initEmbeddedAsset();
		cocktail.port.browser.HTMLElement.prototype.init.call(this);
	}
	,initEmbeddedAsset: function() {
	}
	,initCoreStyle: function() {
		this._coreStyle = new cocktail.core.style.CoreStyle(this);
	}
	,appendChild: function(newChild) {
		return newChild;
	}
	,removeChild: function(oldChild) {
		return oldChild;
	}
	,get_embeddedAsset: function() {
		return this._embeddedAsset;
	}
	,get_intrinsicHeight: function() {
		return this._intrinsicHeight;
	}
	,get_intrinsicWidth: function() {
		return this._intrinsicWidth;
	}
	,get_intrinsicRatio: function() {
		return this._intrinsicRatio;
	}
	,set_width: function(value) {
		return this._width = value;
	}
	,get_width: function() {
		return this._width;
	}
	,set_height: function(value) {
		return this._height = value;
	}
	,get_height: function() {
		return this._height;
	}
	,__class__: cocktail.core.html.EmbeddedElement
	,__properties__: $extend(cocktail.port.browser.HTMLElement.prototype.__properties__,{get_embeddedAsset:"get_embeddedAsset",set_width:"set_width",get_width:"get_width",set_height:"set_height",get_height:"get_height",get_intrinsicRatio:"get_intrinsicRatio",get_intrinsicWidth:"get_intrinsicWidth",get_intrinsicHeight:"get_intrinsicHeight"})
});
cocktail.core.html.AbstractHTMLImageElement = $hxClasses["cocktail.core.html.AbstractHTMLImageElement"] = function() {
	this._imageLoader = new cocktail.core.resource.AbstractImageLoader();
	cocktail.core.html.EmbeddedElement.call(this,"img");
};
cocktail.core.html.AbstractHTMLImageElement.__name__ = ["cocktail","core","html","AbstractHTMLImageElement"];
cocktail.core.html.AbstractHTMLImageElement.__super__ = cocktail.core.html.EmbeddedElement;
cocktail.core.html.AbstractHTMLImageElement.prototype = $extend(cocktail.core.html.EmbeddedElement.prototype,{
	onLoad: null
	,onError: null
	,naturalWidth: null
	,naturalHeight: null
	,src: null
	,_imageLoader: null
	,initEmbeddedAsset: function() {
		this._embeddedAsset = this._imageLoader.getNativeElement();
	}
	,setAttribute: function(name,value) {
		if(name == "src") this.set_src(value); else cocktail.core.html.EmbeddedElement.prototype.setAttribute.call(this,name,value);
	}
	,set_src: function(value) {
		var srcAttr = this._attributes.getNamedItem("src");
		if(srcAttr == null) {
			srcAttr = new cocktail.core.dom.Attr("src");
			this._attributes.setNamedItem(srcAttr);
		}
		srcAttr.set_nodeValue(value);
		this._imageLoader.load([value],this.onLoadComplete.$bind(this),this.onLoadError.$bind(this));
		return value;
	}
	,onLoadComplete: function(image) {
		this._intrinsicHeight = this._imageLoader.getIntrinsicHeight();
		this._intrinsicWidth = this._imageLoader.getIntrinsicWidth();
		this._intrinsicRatio = this._intrinsicHeight / this._intrinsicWidth;
		this._coreStyle.invalidate();
		if(this.onLoad != null) {
			var loadEvent = new cocktail.core.event.Event("load",this);
			this.onLoad(loadEvent);
		}
	}
	,onLoadError: function(message) {
		if(this.onError != null) this.onError(new cocktail.core.event.Event("error",this));
	}
	,get_src: function() {
		return this.getAttribute("src");
	}
	,get_naturalHeight: function() {
		if(this._intrinsicHeight == null) return 0;
		return this._intrinsicHeight;
	}
	,get_naturalWidth: function() {
		if(this._intrinsicWidth == null) return 0;
		return this._intrinsicWidth;
	}
	,__class__: cocktail.core.html.AbstractHTMLImageElement
	,__properties__: $extend(cocktail.core.html.EmbeddedElement.prototype.__properties__,{set_src:"set_src",get_src:"get_src",get_naturalHeight:"get_naturalHeight",get_naturalWidth:"get_naturalWidth"})
});
cocktail.core.html.AbstractHTMLInputElement = $hxClasses["cocktail.core.html.AbstractHTMLInputElement"] = function() {
	cocktail.port.browser.HTMLElement.call(this,"input");
};
cocktail.core.html.AbstractHTMLInputElement.__name__ = ["cocktail","core","html","AbstractHTMLInputElement"];
cocktail.core.html.AbstractHTMLInputElement.__super__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.AbstractHTMLInputElement.prototype = $extend(cocktail.port.browser.HTMLElement.prototype,{
	_onChange: null
	,onchange: null
	,_disabled: null
	,disabled: null
	,_maxLength: null
	,maxLength: null
	,_value: null
	,value: null
	,init: function() {
		cocktail.port.browser.HTMLElement.prototype.init.call(this);
		this._disabled = false;
		this._value = "";
	}
	,initCoreStyle: function() {
		this._coreStyle = new cocktail.core.style.CoreStyle(this);
	}
	,set_onChange: function(value) {
		return this._onChange = value;
	}
	,get_onChange: function() {
		return this._onChange;
	}
	,onChangeCallback: function() {
		if(this._onChange != null) this._onChange();
	}
	,set_disabled: function(value) {
		return this._disabled = value;
	}
	,get_disabled: function() {
		return this._disabled;
	}
	,set_maxLength: function(value) {
		return this._maxLength = value;
	}
	,get_maxLength: function() {
		return this._maxLength;
	}
	,set_value: function(value) {
		return this._value = value;
	}
	,get_value: function() {
		return this._value;
	}
	,__class__: cocktail.core.html.AbstractHTMLInputElement
	,__properties__: $extend(cocktail.port.browser.HTMLElement.prototype.__properties__,{set_value:"set_value",get_value:"get_value",set_maxLength:"set_maxLength",get_maxLength:"get_maxLength",set_disabled:"set_disabled",get_disabled:"get_disabled",set_onchange:"set_onChange",get_onchange:"get_onChange"})
});
cocktail.core.html.HTMLBodyElement = $hxClasses["cocktail.core.html.HTMLBodyElement"] = function() {
	cocktail.port.browser.HTMLElement.call(this,"body");
};
cocktail.core.html.HTMLBodyElement.__name__ = ["cocktail","core","html","HTMLBodyElement"];
cocktail.core.html.HTMLBodyElement.__super__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.HTMLBodyElement.prototype = $extend(cocktail.port.browser.HTMLElement.prototype,{
	initNativeElement: function() {
		this._nativeElement = cocktail.core.nativeElement.NativeElementManager.getRoot();
	}
	,initCoreStyle: function() {
		this._coreStyle = new cocktail.core.style.BodyCoreStyle(this);
	}
	,__class__: cocktail.core.html.HTMLBodyElement
});
cocktail.core.html.HTMLCanvasElement = $hxClasses["cocktail.core.html.HTMLCanvasElement"] = function() {
	cocktail.core.html.EmbeddedElement.call(this,"canvas");
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
};
cocktail.core.html.HTMLCanvasElement.__name__ = ["cocktail","core","html","HTMLCanvasElement"];
cocktail.core.html.HTMLCanvasElement.__super__ = cocktail.core.html.EmbeddedElement;
cocktail.core.html.HTMLCanvasElement.prototype = $extend(cocktail.core.html.EmbeddedElement.prototype,{
	_drawingManager: null
	,initEmbeddedAsset: function() {
		this._embeddedAsset = this._nativeElement;
	}
	,getContext: function(contextID) {
		if(contextID == "2d") {
			if(this._drawingManager == null) this._drawingManager = new cocktail.port.browser.DrawingManager(this._nativeElement,this._intrinsicHeight,this._intrinsicWidth);
			return this._drawingManager;
		} else return null;
	}
	,set_width: function(value) {
		this._drawingManager.setWidth(value);
		return this._width = value;
	}
	,set_height: function(value) {
		this._drawingManager.setHeight(value);
		return this._height = value;
	}
	,__class__: cocktail.core.html.HTMLCanvasElement
});
if(!cocktail.core.hxtml) cocktail.core.hxtml = {}
cocktail.core.hxtml.HxtmlConverter = $hxClasses["cocktail.core.hxtml.HxtmlConverter"] = function() { }
cocktail.core.hxtml.HxtmlConverter.__name__ = ["cocktail","core","hxtml","HxtmlConverter"];
cocktail.core.hxtml.HxtmlConverter.getNode = function(htmlString) {
	var s = new cocktail.core.hxtml.StyleProxy();
	var browser;
	browser = new hxtml.Browser(($_=cocktail.Lib.get_document(),$_.createElement.$bind($_)),($_=cocktail.Lib.get_document(),$_.createTextNode.$bind($_)),cocktail.core.hxtml.HxtmlConverter.appendChild,cocktail.core.hxtml.HxtmlConverter.setAttribute,cocktail.core.hxtml.HxtmlConverter.invalidate,s);
	try {
		browser.setHtml(htmlString);
	} catch( e ) {
		if( js.Boot.__instanceof(e,String) ) {
			throw "Error parsing HTML in HXTML";
		} else throw(e);
	}
	return browser.domRoot;
}
cocktail.core.hxtml.HxtmlConverter.appendChild = function(parent,element) {
	parent.appendChild(element);
}
cocktail.core.hxtml.HxtmlConverter.invalidate = function() {
}
cocktail.core.hxtml.HxtmlConverter.setAttribute = function(element,a,v) {
	((function($this) {
		var $r;
		var $t = element;
		if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
		$r = $t;
		return $r;
	}(this))).setAttribute(a,v);
}
cocktail.core.hxtml.HxtmlConverter.prototype = {
	__class__: cocktail.core.hxtml.HxtmlConverter
}
var hxtml = hxtml || {}
hxtml.IStyleProxy = $hxClasses["hxtml.IStyleProxy"] = function() { }
hxtml.IStyleProxy.__name__ = ["hxtml","IStyleProxy"];
hxtml.IStyleProxy.prototype = {
	setDisplay: null
	,setPosition: null
	,setMarginLeftNum: null
	,setMarginLeftKey: null
	,setMarginTopNum: null
	,setMarginTopKey: null
	,setMarginRightNum: null
	,setMarginRightKey: null
	,setMarginBottomNum: null
	,setMarginBottomKey: null
	,setPaddingLeft: null
	,setPaddingTop: null
	,setPaddingRight: null
	,setPaddingBottom: null
	,setWidth: null
	,setHeight: null
	,setTop: null
	,setLeft: null
	,setBottom: null
	,setRight: null
	,setTopKey: null
	,setLeftKey: null
	,setBottomKey: null
	,setRightKey: null
	,setBgColorNum: null
	,setBgColorRGBA: null
	,setBgColorKey: null
	,setBgImage: null
	,setBgAttachment: null
	,setBgRepeat: null
	,setBgPosXKey: null
	,setBgPosXNum: null
	,setBgPosYKey: null
	,setBgPosYNum: null
	,setFontSizeNum: null
	,setFontSizeKey: null
	,setFontWeightKey: null
	,setFontWeightNum: null
	,setFontStyle: null
	,setFontFamily: null
	,setFontVariant: null
	,setTextColorKey: null
	,setTextColorNum: null
	,setTextDecoration: null
	,setLineHeightNum: null
	,setLineHeightKey: null
	,setTextTransform: null
	,setLetterSpacingNum: null
	,setLetterSpacingKey: null
	,setWordSpacingNum: null
	,setWordSpacingKey: null
	,__class__: hxtml.IStyleProxy
}
cocktail.core.hxtml.StyleProxy = $hxClasses["cocktail.core.hxtml.StyleProxy"] = function() {
};
cocktail.core.hxtml.StyleProxy.__name__ = ["cocktail","core","hxtml","StyleProxy"];
cocktail.core.hxtml.StyleProxy.__interfaces__ = [hxtml.IStyleProxy];
cocktail.core.hxtml.StyleProxy.prototype = {
	setDisplay: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_display(value);
	}
	,setPosition: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_position(value);
	}
	,setMarginLeftNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginLeft(value + unit);
	}
	,setMarginLeftKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginLeft(value);
	}
	,setMarginTopNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginTop(value + unit);
	}
	,setMarginTopKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginTop(value);
	}
	,setMarginRightNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginRight(value + unit);
	}
	,setMarginRightKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginRight(value);
	}
	,setMarginBottomNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginBottom(value + unit);
	}
	,setMarginBottomKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_marginBottom(value);
	}
	,setPaddingLeft: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_paddingLeft(value + unit);
	}
	,setPaddingTop: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_paddingTop(value + unit);
	}
	,setPaddingRight: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_paddingRight(value + unit);
	}
	,setPaddingBottom: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_paddingBottom(value + unit);
	}
	,setWidth: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_width(value + unit);
	}
	,setHeight: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_height(value + unit);
	}
	,setTop: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_top(value + unit);
	}
	,setLeft: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_left(value + unit);
	}
	,setBottom: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_bottom(value + unit);
	}
	,setRight: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_right(value + unit);
	}
	,setTopKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_top(value);
	}
	,setLeftKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_left(value);
	}
	,setBottomKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_bottom(value);
	}
	,setRightKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_right(value);
	}
	,setBgColorNum: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundColor("#" + Std.string(value));
	}
	,setBgColorRGBA: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundColor("rgba(" + value + ")");
	}
	,setBgColorKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundColor(value);
	}
	,setBgImage: function(element,value) {
		if(value.length > 0) ((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundImage("\"" + value.join("\"")); else ((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundImage("");
	}
	,setBgAttachment: function(element,value) {
	}
	,setBgRepeat: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_backgroundRepeat(value.join(","));
	}
	,setBgPosXKey: function(element,value) {
	}
	,setBgPosYKey: function(element,value) {
	}
	,setBgPosYNum: function(element,value,unit) {
	}
	,setBgPosXNum: function(element,value,unit) {
	}
	,setFontSizeNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontSize(value + unit);
	}
	,setFontSizeKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontSize(value);
	}
	,setFontWeightNum: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontWeight(Std.string(value));
	}
	,setFontWeightKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontWeight(value);
	}
	,setFontStyle: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontStyle(value);
	}
	,setFontFamily: function(element,value) {
		if(value.length > 0) ((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontFamily(value.join(",")); else ((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontFamily("");
	}
	,setFontVariant: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_fontVariant(value);
	}
	,setTextColorKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_color(value);
	}
	,setTextColorNum: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_color("#" + Std.string(value));
	}
	,setTextDecoration: function(element,value) {
	}
	,setLineHeightKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_lineHeight(value);
	}
	,setLineHeightNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_lineHeight(value + unit);
	}
	,setTextTransform: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_textTransform(value);
	}
	,setLetterSpacingNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_letterSpacing(value + unit);
	}
	,setLetterSpacingKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_letterSpacing(value);
	}
	,setWordSpacingNum: function(element,value,unit) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_wordSpacing(value + unit);
	}
	,setWordSpacingKey: function(element,value) {
		((function($this) {
			var $r;
			var $t = element;
			if(Std["is"]($t,cocktail.port.browser.HTMLElement)) $t; else throw "Class cast error";
			$r = $t;
			return $r;
		}(this))).get_style().set_wordSpacing(value);
	}
	,__class__: cocktail.core.hxtml.StyleProxy
}
if(!cocktail.core.keyboard) cocktail.core.keyboard = {}
cocktail.core.keyboard.AbstractKeyboard = $hxClasses["cocktail.core.keyboard.AbstractKeyboard"] = function(htmlElement) {
	this._htmlElement = htmlElement;
};
cocktail.core.keyboard.AbstractKeyboard.__name__ = ["cocktail","core","keyboard","AbstractKeyboard"];
cocktail.core.keyboard.AbstractKeyboard.prototype = {
	_onKeyDown: null
	,onKeyDown: null
	,_onKeyUp: null
	,onKeyUp: null
	,_htmlElement: null
	,_keyDownEvent: null
	,_keyUpEvent: null
	,onNativeKeyDown: function(event) {
		if(this.getOnKeyDown() != null) (this.getOnKeyDown())(this.getKeyData(event));
	}
	,onNativeKeyUp: function(event) {
		if(this.getOnKeyUp() != null) (this.getOnKeyUp())(this.getKeyData(event));
	}
	,setOnKeyDown: function(value) {
		this.updateListeners(this._keyDownEvent,this.onNativeKeyDown.$bind(this),value);
		return this._onKeyDown = value;
	}
	,getOnKeyDown: function() {
		return this._onKeyDown;
	}
	,setOnKeyUp: function(value) {
		this.updateListeners(this._keyUpEvent,this.onNativeKeyUp.$bind(this),value);
		return this._onKeyUp = value;
	}
	,getOnKeyUp: function() {
		return this._onKeyUp;
	}
	,updateListeners: function(keyboardEvent,nativeCallback,htmlElementCallback) {
	}
	,getKeyData: function(event) {
		return null;
	}
	,__class__: cocktail.core.keyboard.AbstractKeyboard
	,__properties__: {set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown"}
}
if(!cocktail.core.mouse) cocktail.core.mouse = {}
cocktail.core.mouse.AbstractMouse = $hxClasses["cocktail.core.mouse.AbstractMouse"] = function(htmlElement) {
	this._htmlElement = htmlElement;
};
cocktail.core.mouse.AbstractMouse.__name__ = ["cocktail","core","mouse","AbstractMouse"];
cocktail.core.mouse.AbstractMouse.prototype = {
	_onClick: null
	,onClick: null
	,_onMouseDown: null
	,onMouseDown: null
	,_onMouseUp: null
	,onMouseUp: null
	,_onMouseOver: null
	,onMouseOver: null
	,_onMouseOut: null
	,onMouseOut: null
	,_onMouseMove: null
	,onMouseMove: null
	,_clickEvent: null
	,_mouseDownEvent: null
	,_mouseUpEvent: null
	,_mouseOverEvent: null
	,_mouseOutEvent: null
	,_mouseMoveEvent: null
	,_htmlElement: null
	,onNativeClick: function(event) {
		if(this.get_onClick() != null) (this.get_onClick())(this.getMouseEvent(event));
	}
	,onNativeMouseDown: function(event) {
		if(this.getOnMouseDown() != null) (this.getOnMouseDown())(this.getMouseEvent(event));
	}
	,onNativeMouseUp: function(event) {
		if(this.getOnMouseUp() != null) (this.getOnMouseUp())(this.getMouseEvent(event));
	}
	,onNativeMouseOver: function(event) {
		if(this.getOnMouseOver() != null) (this.getOnMouseOver())(this.getMouseEvent(event));
	}
	,onNativeMouseOut: function(event) {
		if(this.getOnMouseOut() != null) (this.getOnMouseOut())(this.getMouseEvent(event));
	}
	,onNativeMouseMove: function(event) {
		if(this.getOnMouseMove() != null) (this.getOnMouseMove())(this.getMouseEvent(event));
	}
	,updateListeners: function(mouseEvent,nativeCallback,htmlElementCallback) {
	}
	,getMouseEvent: function(event) {
		return null;
	}
	,set_onClick: function(value) {
		this.updateListeners(this._clickEvent,this.onNativeClick.$bind(this),value);
		return this._onClick = value;
	}
	,get_onClick: function() {
		return this._onClick;
	}
	,setOnMouseDown: function(value) {
		this.updateListeners(this._mouseDownEvent,this.onNativeMouseDown.$bind(this),value);
		return this._onMouseDown = value;
	}
	,getOnMouseDown: function() {
		return this._onMouseDown;
	}
	,setOnMouseUp: function(value) {
		this.updateListeners(this._mouseUpEvent,this.onNativeMouseUp.$bind(this),value);
		return this._onMouseUp = value;
	}
	,getOnMouseUp: function() {
		return this._onMouseUp;
	}
	,setOnMouseOver: function(value) {
		this.updateListeners(this._mouseOverEvent,this.onNativeMouseOver.$bind(this),value);
		return this._onMouseOver = value;
	}
	,getOnMouseOver: function() {
		return this._onMouseOver;
	}
	,setOnMouseOut: function(value) {
		this.updateListeners(this._mouseOutEvent,this.onNativeMouseOut.$bind(this),value);
		return this._onMouseOut = value;
	}
	,getOnMouseOut: function() {
		return this._onMouseOut;
	}
	,setOnMouseMove: function(value) {
		this.updateListeners(this._mouseMoveEvent,this.onNativeMouseMove.$bind(this),value);
		return this._onMouseMove = value;
	}
	,getOnMouseMove: function() {
		return this._onMouseMove;
	}
	,__class__: cocktail.core.mouse.AbstractMouse
	,__properties__: {set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown",set_onClick:"set_onClick",get_onClick:"get_onClick"}
}
cocktail.core.mouse.AbstractMouseCursor = $hxClasses["cocktail.core.mouse.AbstractMouseCursor"] = function() {
	this._nativeMouseCursor = cocktail.core.mouse.MouseCursorValue.cssAuto;
};
cocktail.core.mouse.AbstractMouseCursor.__name__ = ["cocktail","core","mouse","AbstractMouseCursor"];
cocktail.core.mouse.AbstractMouseCursor.prototype = {
	_nativeMouseCursor: null
	,nativeMouseCursor: null
	,setNativeMouseCursor: function(value) {
		this._nativeMouseCursor = value;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var hotSpot = $e[3], imageHTMLElement = $e[2];
			this.setBitmapCursor(imageHTMLElement,hotSpot);
			break;
		case 1:
			this.setDefaultCursor();
			break;
		case 2:
			this.hideCursor();
			break;
		case 3:
			var nativeOSMouseCursor = $e[2];
			this.setNativeOSCursor(nativeOSMouseCursor);
			break;
		}
		return this._nativeMouseCursor;
	}
	,getNativeMouseCursor: function() {
		return this._nativeMouseCursor;
	}
	,setBitmapCursor: function(imageHTMLElement,hotSpot) {
	}
	,hideCursor: function() {
	}
	,setDefaultCursor: function() {
	}
	,setNativeOSCursor: function(value) {
	}
	,__class__: cocktail.core.mouse.AbstractMouseCursor
	,__properties__: {set_nativeMouseCursor:"setNativeMouseCursor",get_nativeMouseCursor:"getNativeMouseCursor"}
}
cocktail.core.mouse.MouseCursorManager = $hxClasses["cocktail.core.mouse.MouseCursorManager"] = function() {
};
cocktail.core.mouse.MouseCursorManager.__name__ = ["cocktail","core","mouse","MouseCursorManager"];
cocktail.core.mouse.MouseCursorManager._mouseCursor = null;
cocktail.core.mouse.MouseCursorManager.setMouseCursor = function(mouseCursorValue) {
	if(cocktail.core.mouse.MouseCursorManager._mouseCursor == null) cocktail.core.mouse.MouseCursorManager._mouseCursor = new cocktail.port.browser.MouseCursor();
	cocktail.core.mouse.MouseCursorManager._mouseCursor.setNativeMouseCursor(mouseCursorValue);
}
cocktail.core.mouse.MouseCursorManager.getMousecursor = function() {
	if(cocktail.core.mouse.MouseCursorManager._mouseCursor == null) cocktail.core.mouse.MouseCursorManager._mouseCursor = new cocktail.port.browser.MouseCursor();
	return cocktail.core.mouse.MouseCursorManager._mouseCursor.getNativeMouseCursor();
}
cocktail.core.mouse.MouseCursorManager.prototype = {
	__class__: cocktail.core.mouse.MouseCursorManager
}
cocktail.core.mouse.MouseCursorValue = $hxClasses["cocktail.core.mouse.MouseCursorValue"] = { __ename__ : ["cocktail","core","mouse","MouseCursorValue"], __constructs__ : ["custom","cssAuto","none","native"] }
cocktail.core.mouse.MouseCursorValue.custom = function(htmlImageElement,hotSpot) { var $x = ["custom",0,htmlImageElement,hotSpot]; $x.__enum__ = cocktail.core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.core.mouse.MouseCursorValue.cssAuto = ["cssAuto",1];
cocktail.core.mouse.MouseCursorValue.cssAuto.toString = $estr;
cocktail.core.mouse.MouseCursorValue.cssAuto.__enum__ = cocktail.core.mouse.MouseCursorValue;
cocktail.core.mouse.MouseCursorValue.none = ["none",2];
cocktail.core.mouse.MouseCursorValue.none.toString = $estr;
cocktail.core.mouse.MouseCursorValue.none.__enum__ = cocktail.core.mouse.MouseCursorValue;
cocktail.core.mouse.MouseCursorValue["native"] = function(nativeOSMouseCursorValue) { var $x = ["native",3,nativeOSMouseCursorValue]; $x.__enum__ = cocktail.core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.core.mouse.NativeOSMouseCursorValue = $hxClasses["cocktail.core.mouse.NativeOSMouseCursorValue"] = { __ename__ : ["cocktail","core","mouse","NativeOSMouseCursorValue"], __constructs__ : ["pointer","text"] }
cocktail.core.mouse.NativeOSMouseCursorValue.pointer = ["pointer",0];
cocktail.core.mouse.NativeOSMouseCursorValue.pointer.toString = $estr;
cocktail.core.mouse.NativeOSMouseCursorValue.pointer.__enum__ = cocktail.core.mouse.NativeOSMouseCursorValue;
cocktail.core.mouse.NativeOSMouseCursorValue.text = ["text",1];
cocktail.core.mouse.NativeOSMouseCursorValue.text.toString = $estr;
cocktail.core.mouse.NativeOSMouseCursorValue.text.__enum__ = cocktail.core.mouse.NativeOSMouseCursorValue;
if(!cocktail.core.nativeElement) cocktail.core.nativeElement = {}
cocktail.core.nativeElement.AbstractNativeElementManagerImpl = $hxClasses["cocktail.core.nativeElement.AbstractNativeElementManagerImpl"] = function() {
};
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.__name__ = ["cocktail","core","nativeElement","AbstractNativeElementManagerImpl"];
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype = {
	getRoot: function() {
		return null;
	}
	,createNativeElement: function(nativeElementType) {
		return null;
	}
	,__class__: cocktail.core.nativeElement.AbstractNativeElementManagerImpl
}
cocktail.core.nativeElement.NativeElementTypeValue = $hxClasses["cocktail.core.nativeElement.NativeElementTypeValue"] = { __ename__ : ["cocktail","core","nativeElement","NativeElementTypeValue"], __constructs__ : ["canvas","img","script","anchor","input","semantic"] }
cocktail.core.nativeElement.NativeElementTypeValue.canvas = ["canvas",0];
cocktail.core.nativeElement.NativeElementTypeValue.canvas.toString = $estr;
cocktail.core.nativeElement.NativeElementTypeValue.canvas.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue;
cocktail.core.nativeElement.NativeElementTypeValue.img = ["img",1];
cocktail.core.nativeElement.NativeElementTypeValue.img.toString = $estr;
cocktail.core.nativeElement.NativeElementTypeValue.img.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue;
cocktail.core.nativeElement.NativeElementTypeValue.script = ["script",2];
cocktail.core.nativeElement.NativeElementTypeValue.script.toString = $estr;
cocktail.core.nativeElement.NativeElementTypeValue.script.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue;
cocktail.core.nativeElement.NativeElementTypeValue.anchor = ["anchor",3];
cocktail.core.nativeElement.NativeElementTypeValue.anchor.toString = $estr;
cocktail.core.nativeElement.NativeElementTypeValue.anchor.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue;
cocktail.core.nativeElement.NativeElementTypeValue.input = ["input",4];
cocktail.core.nativeElement.NativeElementTypeValue.input.toString = $estr;
cocktail.core.nativeElement.NativeElementTypeValue.input.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue;
cocktail.core.nativeElement.NativeElementTypeValue.semantic = function(name) { var $x = ["semantic",5,name]; $x.__enum__ = cocktail.core.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
cocktail.core.nativeElement.NativeElementManager = $hxClasses["cocktail.core.nativeElement.NativeElementManager"] = function() {
};
cocktail.core.nativeElement.NativeElementManager.__name__ = ["cocktail","core","nativeElement","NativeElementManager"];
cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl = null;
cocktail.core.nativeElement.NativeElementManager.getRoot = function() {
	if(cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl == null) cocktail.core.nativeElement.NativeElementManager.init();
	return cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl.getRoot();
}
cocktail.core.nativeElement.NativeElementManager.createNativeElement = function(nativeElementType) {
	if(cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl == null) cocktail.core.nativeElement.NativeElementManager.init();
	return cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl.createNativeElement(nativeElementType);
}
cocktail.core.nativeElement.NativeElementManager.init = function() {
	cocktail.core.nativeElement.NativeElementManager._nativeElementManagerImpl = new cocktail.port.browser.NativeElementManagerImpl();
}
cocktail.core.nativeElement.NativeElementManager.prototype = {
	__class__: cocktail.core.nativeElement.NativeElementManager
}
if(!cocktail.core.renderer) cocktail.core.renderer = {}
cocktail.core.renderer.ElementRenderer = $hxClasses["cocktail.core.renderer.ElementRenderer"] = function(style) {
	cocktail.core.dom.Node.call(this);
	this._coreStyle = style;
	this._bounds = { x : 0.0, y : 0.0, width : 0.0, height : 0.0};
};
cocktail.core.renderer.ElementRenderer.__name__ = ["cocktail","core","renderer","ElementRenderer"];
cocktail.core.renderer.ElementRenderer.__super__ = cocktail.core.dom.Node;
cocktail.core.renderer.ElementRenderer.prototype = $extend(cocktail.core.dom.Node.prototype,{
	_bounds: null
	,bounds: null
	,_coreStyle: null
	,coreStyle: null
	,_layerRenderer: null
	,layerRenderer: null
	,render: function() {
		return [];
	}
	,renderBackground: function() {
		return [];
	}
	,dispose: function() {
		this._bounds = null;
		this._coreStyle = null;
		this._layerRenderer = null;
	}
	,establishesNewFormattingContext: function() {
		return false;
	}
	,canHaveChildren: function() {
		return false;
	}
	,isFloat: function() {
		return this._coreStyle.isFloat();
	}
	,isPositioned: function() {
		return this._coreStyle.isPositioned();
	}
	,isEmbedded: function() {
		return true;
	}
	,isText: function() {
		return false;
	}
	,isSpace: function() {
		return false;
	}
	,isLineFeed: function() {
		return false;
	}
	,isTab: function() {
		return false;
	}
	,isInitialContainer: function() {
		return false;
	}
	,isDisplayed: function() {
		return this._coreStyle.isDisplayed();
	}
	,setLayerRenderer: function(value) {
		return this._layerRenderer = value;
	}
	,getLayerRenderer: function() {
		return this._layerRenderer;
	}
	,getCoreStyle: function() {
		return this._coreStyle;
	}
	,getBounds: function() {
		return this._bounds;
	}
	,setBounds: function(value) {
		return this._bounds = value;
	}
	,__class__: cocktail.core.renderer.ElementRenderer
	,__properties__: $extend(cocktail.core.dom.Node.prototype.__properties__,{set_layerRenderer:"setLayerRenderer",get_layerRenderer:"getLayerRenderer",get_coreStyle:"getCoreStyle",set_bounds:"setBounds",get_bounds:"getBounds"})
});
cocktail.core.renderer.BoxRenderer = $hxClasses["cocktail.core.renderer.BoxRenderer"] = function(style) {
	cocktail.core.renderer.ElementRenderer.call(this,style);
	this.init();
};
cocktail.core.renderer.BoxRenderer.__name__ = ["cocktail","core","renderer","BoxRenderer"];
cocktail.core.renderer.BoxRenderer.__super__ = cocktail.core.renderer.ElementRenderer;
cocktail.core.renderer.BoxRenderer.prototype = $extend(cocktail.core.renderer.ElementRenderer.prototype,{
	_backgroundManager: null
	,init: function() {
		this._backgroundManager = new cocktail.core.background.BackgroundManager();
	}
	,dispose: function() {
		cocktail.core.renderer.ElementRenderer.prototype.dispose.call(this);
		this._backgroundManager.dispose();
		this._backgroundManager = null;
	}
	,renderBackground: function() {
		var backgrounds = this._backgroundManager.render(this._bounds,this._coreStyle);
		var _g1 = 0, _g = backgrounds.length;
		while(_g1 < _g) {
			var i = _g1++;
		}
		return backgrounds;
	}
	,__class__: cocktail.core.renderer.BoxRenderer
});
cocktail.core.renderer.FlowBoxRenderer = $hxClasses["cocktail.core.renderer.FlowBoxRenderer"] = function(style) {
	cocktail.core.renderer.BoxRenderer.call(this,style);
};
cocktail.core.renderer.FlowBoxRenderer.__name__ = ["cocktail","core","renderer","FlowBoxRenderer"];
cocktail.core.renderer.FlowBoxRenderer.__super__ = cocktail.core.renderer.BoxRenderer;
cocktail.core.renderer.FlowBoxRenderer.prototype = $extend(cocktail.core.renderer.BoxRenderer.prototype,{
	dispose: function() {
		cocktail.core.renderer.BoxRenderer.prototype.dispose.call(this);
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = this._childNodes[i];
			child.dispose();
		}
		this._childNodes = null;
	}
	,establishesNewFormattingContext: function() {
		return this.getCoreStyle().establishesNewFormattingContext();
	}
	,isEmbedded: function() {
		return false;
	}
	,canHaveChildren: function() {
		return true;
	}
	,__class__: cocktail.core.renderer.FlowBoxRenderer
});
cocktail.core.renderer.BlockBoxRenderer = $hxClasses["cocktail.core.renderer.BlockBoxRenderer"] = function(style) {
	cocktail.core.renderer.FlowBoxRenderer.call(this,style);
};
cocktail.core.renderer.BlockBoxRenderer.__name__ = ["cocktail","core","renderer","BlockBoxRenderer"];
cocktail.core.renderer.BlockBoxRenderer.__super__ = cocktail.core.renderer.FlowBoxRenderer;
cocktail.core.renderer.BlockBoxRenderer.prototype = $extend(cocktail.core.renderer.FlowBoxRenderer.prototype,{
	_lineBoxes: null
	,lineBoxes: null
	,dispose: function() {
		cocktail.core.renderer.FlowBoxRenderer.prototype.dispose.call(this);
		var _g1 = 0, _g = this._lineBoxes.length;
		while(_g1 < _g) {
			var i = _g1++;
			var _g3 = 0, _g2 = this._lineBoxes[i].length;
			while(_g3 < _g2) {
				var j = _g3++;
				this._lineBoxes[i][j].dispose();
			}
		}
		this._lineBoxes = null;
	}
	,addLineBox: function(lineBoxElements) {
		this._lineBoxes.push(lineBoxElements);
	}
	,removeLineBoxes: function() {
		this._lineBoxes = new Array();
	}
	,getLineBoxes: function() {
		return this._lineBoxes;
	}
	,__class__: cocktail.core.renderer.BlockBoxRenderer
	,__properties__: $extend(cocktail.core.renderer.FlowBoxRenderer.prototype.__properties__,{get_lineBoxes:"getLineBoxes"})
});
cocktail.core.renderer.EmbeddedBoxRenderer = $hxClasses["cocktail.core.renderer.EmbeddedBoxRenderer"] = function(style) {
	cocktail.core.renderer.BoxRenderer.call(this,style);
	var computedStyle = style.getComputedStyle();
	this._bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	this._bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
};
cocktail.core.renderer.EmbeddedBoxRenderer.__name__ = ["cocktail","core","renderer","EmbeddedBoxRenderer"];
cocktail.core.renderer.EmbeddedBoxRenderer.__super__ = cocktail.core.renderer.BoxRenderer;
cocktail.core.renderer.EmbeddedBoxRenderer.prototype = $extend(cocktail.core.renderer.BoxRenderer.prototype,{
	render: function() {
		var ret = [];
		return ret;
	}
	,renderBackground: function() {
		var backgrounds = this._backgroundManager.render(this._bounds,this._coreStyle);
		var _g1 = 0, _g = backgrounds.length;
		while(_g1 < _g) {
			var i = _g1++;
		}
		return backgrounds;
	}
	,__class__: cocktail.core.renderer.EmbeddedBoxRenderer
});
cocktail.core.renderer.InitialBlockRenderer = $hxClasses["cocktail.core.renderer.InitialBlockRenderer"] = function(style) {
	cocktail.core.renderer.BlockBoxRenderer.call(this,style);
	var width = cocktail.Lib.get_window().get_innerWidth();
	var height = cocktail.Lib.get_window().get_innerHeight();
	this._bounds.width = width;
	this._bounds.height = height;
};
cocktail.core.renderer.InitialBlockRenderer.__name__ = ["cocktail","core","renderer","InitialBlockRenderer"];
cocktail.core.renderer.InitialBlockRenderer.__super__ = cocktail.core.renderer.BlockBoxRenderer;
cocktail.core.renderer.InitialBlockRenderer.prototype = $extend(cocktail.core.renderer.BlockBoxRenderer.prototype,{
	isInitialContainer: function() {
		return true;
	}
	,init: function() {
		this._backgroundManager = new cocktail.core.background.InitialBlockBackgroundManager();
	}
	,__class__: cocktail.core.renderer.InitialBlockRenderer
});
cocktail.core.renderer.InlineBoxRenderer = $hxClasses["cocktail.core.renderer.InlineBoxRenderer"] = function(style) {
	cocktail.core.renderer.FlowBoxRenderer.call(this,style);
};
cocktail.core.renderer.InlineBoxRenderer.__name__ = ["cocktail","core","renderer","InlineBoxRenderer"];
cocktail.core.renderer.InlineBoxRenderer.__super__ = cocktail.core.renderer.FlowBoxRenderer;
cocktail.core.renderer.InlineBoxRenderer.prototype = $extend(cocktail.core.renderer.FlowBoxRenderer.prototype,{
	render: function() {
		return this.renderBackground();
	}
	,__class__: cocktail.core.renderer.InlineBoxRenderer
});
cocktail.core.renderer.LayerRenderer = $hxClasses["cocktail.core.renderer.LayerRenderer"] = function(rootRenderer) {
	this._rootRenderer = rootRenderer;
};
cocktail.core.renderer.LayerRenderer.__name__ = ["cocktail","core","renderer","LayerRenderer"];
cocktail.core.renderer.LayerRenderer.prototype = {
	_rootRenderer: null
	,dispose: function() {
		this._rootRenderer = null;
	}
	,render: function() {
		var nativeElements = new Array();
		if(this._rootRenderer.canHaveChildren() == true && this._rootRenderer.getCoreStyle().isInlineLevel() == false || this._rootRenderer.getCoreStyle().getDisplay() == cocktail.core.style.Display.inlineBlock) {
			var rootRendererBackground = this._rootRenderer.renderBackground();
			var _g1 = 0, _g = rootRendererBackground.length;
			while(_g1 < _g) {
				var i = _g1++;
				nativeElements.push(rootRendererBackground[i]);
			}
			var childrenBlockContainerBackground = this.renderChildrenBlockContainerBackground();
			var _g1 = 0, _g = childrenBlockContainerBackground.length;
			while(_g1 < _g) {
				var i = _g1++;
				nativeElements.push(childrenBlockContainerBackground[i]);
			}
			var inFlowChildren = this.renderInFlowChildren();
			var _g1 = 0, _g = inFlowChildren.length;
			while(_g1 < _g) {
				var i = _g1++;
				nativeElements.push(inFlowChildren[i]);
			}
			var childLayers = this.renderChildLayer();
			var _g1 = 0, _g = childLayers.length;
			while(_g1 < _g) {
				var i = _g1++;
			}
		} else {
			var rootRendererBackground = this._rootRenderer.renderBackground();
			var _g1 = 0, _g = rootRendererBackground.length;
			while(_g1 < _g) {
				var i = _g1++;
				nativeElements.push(rootRendererBackground[i]);
			}
			var rootRendererElements = this._rootRenderer.render();
			var _g1 = 0, _g = rootRendererElements.length;
			while(_g1 < _g) {
				var i = _g1++;
				nativeElements.push(rootRendererElements[i]);
			}
		}
		return nativeElements;
	}
	,renderChildrenBlockContainerBackground: function() {
		var childrenBlockContainer = this.getBlockContainerChildren(this._rootRenderer);
		var ret = new Array();
		var _g1 = 0, _g = childrenBlockContainer.length;
		while(_g1 < _g) {
			var i = _g1++;
			var nativeElements = childrenBlockContainer[i].renderBackground();
			var _g3 = 0, _g2 = nativeElements.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(nativeElements[j]);
			}
		}
		return ret;
	}
	,getBlockContainerChildren: function(rootRenderer) {
		var ret = new Array();
		var _g1 = 0, _g = rootRenderer.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = rootRenderer.get_childNodes()[i];
			if(child.getLayerRenderer() == this) {
				if(child.canHaveChildren() == true) {
					var childElementRenderer = this.getBlockContainerChildren(child);
					var _g3 = 0, _g2 = childElementRenderer.length;
					while(_g3 < _g2) {
						var j = _g3++;
						ret.push(childElementRenderer[j]);
					}
					ret.push(child);
				}
			}
		}
		return ret;
	}
	,renderChildLayer: function() {
		var childLayers = this.getChildLayers(this._rootRenderer,this);
		childLayers.reverse();
		var ret = new Array();
		var _g1 = 0, _g = childLayers.length;
		while(_g1 < _g) {
			var i = _g1++;
			var nativeElements = childLayers[i].render();
			var _g3 = 0, _g2 = nativeElements.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(nativeElements[j]);
			}
		}
		return ret;
	}
	,getChildLayers: function(rootRenderer,referenceLayer) {
		var childLayers = new Array();
		var _g1 = 0, _g = rootRenderer.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = rootRenderer.get_childNodes()[i];
			if(child.getLayerRenderer() == referenceLayer) {
				if(child.canHaveChildren() == true && child.getCoreStyle().getDisplay() != cocktail.core.style.Display.inlineBlock) {
					var childElementRenderer = this.getChildLayers(child,referenceLayer);
					var _g3 = 0, _g2 = childElementRenderer.length;
					while(_g3 < _g2) {
						var j = _g3++;
						childLayers.push(childElementRenderer[j]);
					}
				}
			} else childLayers.push(child.getLayerRenderer());
		}
		return childLayers;
	}
	,renderInFlowChildren: function() {
		var inFlowChildren = this.getInFlowChildren(this._rootRenderer);
		var ret = new Array();
		var _g1 = 0, _g = inFlowChildren.length;
		while(_g1 < _g) {
			var i = _g1++;
			var nativeElements = [];
			if(inFlowChildren[i].getCoreStyle().getDisplay() == cocktail.core.style.Display.inlineBlock) {
				var d = this.getChildLayers(inFlowChildren[i],this);
				var _g3 = 0, _g2 = d.length;
				while(_g3 < _g2) {
					var l = _g3++;
					var ne = d[l].render();
					var _g5 = 0, _g4 = ne.length;
					while(_g5 < _g4) {
						var m = _g5++;
						nativeElements.push(ne[m]);
					}
				}
				var childElementRenderer = this.getInFlowChildren(inFlowChildren[i]);
				var _g3 = 0, _g2 = childElementRenderer.length;
				while(_g3 < _g2) {
					var l = _g3++;
					childElementRenderer[l].getBounds().x += inFlowChildren[i].getBounds().x;
					childElementRenderer[l].getBounds().y += inFlowChildren[i].getBounds().y;
					var el = childElementRenderer[l].render();
					var _g5 = 0, _g4 = el.length;
					while(_g5 < _g4) {
						var k = _g5++;
						nativeElements.push(el[k]);
					}
				}
			} else nativeElements = inFlowChildren[i].render();
			if(inFlowChildren[i].canHaveChildren() == false && inFlowChildren[i].isText() == false) {
				var bg = inFlowChildren[i].renderBackground();
				var _g3 = 0, _g2 = bg.length;
				while(_g3 < _g2) {
					var j = _g3++;
					ret.push(bg[j]);
				}
			}
			var _g3 = 0, _g2 = nativeElements.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(nativeElements[j]);
			}
		}
		return ret;
	}
	,getInFlowChildren: function(rootRenderer) {
		var ret = new Array();
		if(rootRenderer.establishesNewFormattingContext() == true && rootRenderer.getCoreStyle().childrenInline() == true) {
			var blockBoxRenderer = rootRenderer;
			var _g1 = 0, _g = blockBoxRenderer.getLineBoxes().length;
			while(_g1 < _g) {
				var i = _g1++;
				var _g3 = 0, _g2 = blockBoxRenderer.getLineBoxes()[i].length;
				while(_g3 < _g2) {
					var j = _g3++;
					if(blockBoxRenderer.getLineBoxes()[i][j].isPositioned() == false && blockBoxRenderer.getLineBoxes()[i][j].isDisplayed() == true) ret.push(blockBoxRenderer.getLineBoxes()[i][j]);
				}
			}
		} else {
			var _g1 = 0, _g = rootRenderer.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				var child = rootRenderer.get_childNodes()[i];
				if(child.isDisplayed() == true) {
					if(child.getLayerRenderer() == this) {
						if(child.isPositioned() == false) {
							ret.push(child);
							if(child.canHaveChildren() == true) {
								var childElementRenderer = this.getInFlowChildren(child);
								var _g3 = 0, _g2 = childElementRenderer.length;
								while(_g3 < _g2) {
									var j = _g3++;
									if(child.establishesNewFormattingContext() == true) {
										childElementRenderer[j].getBounds().x += child.getBounds().x;
										childElementRenderer[j].getBounds().y += child.getBounds().y;
									}
									ret.push(childElementRenderer[j]);
								}
							}
						}
					}
				}
			}
		}
		return ret;
	}
	,setNativeMatrix: function(matrix) {
	}
	,getConcatenatedMatrix: function(matrix) {
		var currentMatrix = new cocktail.core.geom.Matrix();
		return currentMatrix;
	}
	,getConcatenatedMatrix2: function(matrix) {
		var currentMatrix = new cocktail.core.geom.Matrix();
		return currentMatrix;
	}
	,__class__: cocktail.core.renderer.LayerRenderer
}
cocktail.core.renderer.TextRenderer = $hxClasses["cocktail.core.renderer.TextRenderer"] = function(style,nativeElement,textToken) {
	this._textToken = textToken;
	this._nativeElement = nativeElement;
	cocktail.core.renderer.ElementRenderer.call(this,style);
};
cocktail.core.renderer.TextRenderer.__name__ = ["cocktail","core","renderer","TextRenderer"];
cocktail.core.renderer.TextRenderer.__super__ = cocktail.core.renderer.ElementRenderer;
cocktail.core.renderer.TextRenderer.prototype = $extend(cocktail.core.renderer.ElementRenderer.prototype,{
	_textToken: null
	,_nativeElement: null
	,dispose: function() {
		cocktail.core.renderer.ElementRenderer.prototype.dispose.call(this);
		this._textToken = null;
		this._nativeElement = null;
	}
	,render: function() {
		var ret = [];
		ret.push(this._nativeElement);
		return ret;
	}
	,getOffsetHeight: function() {
		var ascent = this._coreStyle.getFontMetricsData().ascent;
		var descent = this._coreStyle.getFontMetricsData().descent;
		var leading = this._coreStyle.getComputedStyle().lineHeight - (ascent + descent);
		var leadedAscent = ascent + leading / 2;
		var leadedDescent = descent + leading / 2;
		return Math.round(leadedAscent + leadedDescent);
		return 50;
	}
	,isFloat: function() {
		return false;
	}
	,isPositioned: function() {
		return false;
	}
	,isText: function() {
		return true;
	}
	,isSpace: function() {
		var isSpace;
		switch( (this._textToken)[1] ) {
		case 1:
			isSpace = true;
			break;
		default:
			isSpace = false;
		}
		return isSpace;
	}
	,isLineFeed: function() {
		var isLineFeed;
		switch( (this._textToken)[1] ) {
		case 3:
			isLineFeed = true;
			break;
		default:
			isLineFeed = false;
		}
		return isLineFeed;
	}
	,isTab: function() {
		var isTab;
		switch( (this._textToken)[1] ) {
		case 2:
			isTab = true;
			break;
		default:
			isTab = false;
		}
		return isTab;
	}
	,__class__: cocktail.core.renderer.TextRenderer
});
if(!cocktail.core.resource) cocktail.core.resource = {}
cocktail.core.resource.AbstractResourceLoader = $hxClasses["cocktail.core.resource.AbstractResourceLoader"] = function() {
};
cocktail.core.resource.AbstractResourceLoader.__name__ = ["cocktail","core","resource","AbstractResourceLoader"];
cocktail.core.resource.AbstractResourceLoader.prototype = {
	_onLoadCompleteCallback: null
	,_onLoadErrorCallback: null
	,_urlToLoadIdx: null
	,_urls: null
	,load: function(urls,onLoadComplete,onLoadError) {
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		this._urls = urls;
		this._urlToLoadIdx = 0;
		this.doLoad(this._urls[this._urlToLoadIdx]);
	}
	,doLoad: function(url) {
	}
	,onLoadComplete: function(data) {
		this._onLoadCompleteCallback(data);
	}
	,onLoadError: function(msg) {
		this._urlToLoadIdx++;
		if(this._urlToLoadIdx < this._urls.length - 1) this.doLoad(this._urls[this._urlToLoadIdx]); else this._onLoadErrorCallback(msg);
	}
	,__class__: cocktail.core.resource.AbstractResourceLoader
}
cocktail.core.resource.AbstractMediaLoader = $hxClasses["cocktail.core.resource.AbstractMediaLoader"] = function(nativeElement) {
	this._nativeElement = nativeElement;
	cocktail.core.resource.AbstractResourceLoader.call(this);
};
cocktail.core.resource.AbstractMediaLoader.__name__ = ["cocktail","core","resource","AbstractMediaLoader"];
cocktail.core.resource.AbstractMediaLoader.__super__ = cocktail.core.resource.AbstractResourceLoader;
cocktail.core.resource.AbstractMediaLoader.prototype = $extend(cocktail.core.resource.AbstractResourceLoader.prototype,{
	_nativeElement: null
	,nativeElement: null
	,_intrinsicWidth: null
	,intrinsicWidth: null
	,_intrinsicHeight: null
	,intrinsicHeight: null
	,_intrinsicRatio: null
	,intrinsicRatio: null
	,getNativeElement: function() {
		return this._nativeElement;
	}
	,getIntrinsicWidth: function() {
		return this._intrinsicWidth;
	}
	,getIntrinsicHeight: function() {
		return this._intrinsicHeight;
	}
	,getIntrinsicRatio: function() {
		return this._intrinsicRatio;
	}
	,__class__: cocktail.core.resource.AbstractMediaLoader
	,__properties__: {get_intrinsicRatio:"getIntrinsicRatio",get_intrinsicHeight:"getIntrinsicHeight",get_intrinsicWidth:"getIntrinsicWidth",get_nativeElement:"getNativeElement"}
});
cocktail.port.browser.MediaLoader = $hxClasses["cocktail.port.browser.MediaLoader"] = function(nativeElement) {
	cocktail.core.resource.AbstractMediaLoader.call(this,nativeElement);
};
cocktail.port.browser.MediaLoader.__name__ = ["cocktail","port","browser","MediaLoader"];
cocktail.port.browser.MediaLoader.__super__ = cocktail.core.resource.AbstractMediaLoader;
cocktail.port.browser.MediaLoader.prototype = $extend(cocktail.core.resource.AbstractMediaLoader.prototype,{
	doLoad: function(url) {
		var onLoadCompleteDelegate = this.onNativeLoadComplete.$bind(this);
		var onLoadErrorDelegate = this.onNativeLoadError.$bind(this);
		var nativeElementDelegate = this._nativeElement;
		this._nativeElement.onload = function() {
			onLoadCompleteDelegate(nativeElementDelegate);
		};
		this._nativeElement.onerror = function() {
			onLoadErrorDelegate("couldn't load picture");
		};
		this._nativeElement.setAttribute("src",url);
	}
	,onNativeLoadComplete: function(nativeElement) {
		this.setIntrinsicDimensions(nativeElement);
		this.onLoadComplete(nativeElement);
	}
	,onNativeLoadError: function(event) {
		this.onLoadError(event.toString());
	}
	,setIntrinsicDimensions: function(nativeElement) {
		this._intrinsicHeight = nativeElement.naturalHeight;
		this._intrinsicWidth = nativeElement.naturalWidth;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	}
	,__class__: cocktail.port.browser.MediaLoader
});
cocktail.core.resource.AbstractImageLoader = $hxClasses["cocktail.core.resource.AbstractImageLoader"] = function() {
	var nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.img);
	cocktail.port.browser.MediaLoader.call(this,nativeElement);
};
cocktail.core.resource.AbstractImageLoader.__name__ = ["cocktail","core","resource","AbstractImageLoader"];
cocktail.core.resource.AbstractImageLoader.__super__ = cocktail.port.browser.MediaLoader;
cocktail.core.resource.AbstractImageLoader.prototype = $extend(cocktail.port.browser.MediaLoader.prototype,{
	__class__: cocktail.core.resource.AbstractImageLoader
});
cocktail.core.resource.XMLHTTPRequest = $hxClasses["cocktail.core.resource.XMLHTTPRequest"] = function() {
	this._http = new haxe.Http("");
	this._http.onData = this.onHTTPData.$bind(this);
	this._http.onStatus = this.onHTTPStatus.$bind(this);
	this._http.onError = this.onHTTPError.$bind(this);
	this.setReadyState(0);
};
cocktail.core.resource.XMLHTTPRequest.__name__ = ["cocktail","core","resource","XMLHTTPRequest"];
cocktail.core.resource.XMLHTTPRequest.__interfaces__ = [cocktail.core.event.IEventTarget];
cocktail.core.resource.XMLHTTPRequest.prototype = {
	_readyState: null
	,readyState: null
	,_responseText: null
	,responseText: null
	,_status: null
	,status: null
	,onReadyStateChange: null
	,_http: null
	,_method: null
	,open: function(method,url) {
		this._http.url = url;
		this._method = method;
		this.setReadyState(1);
	}
	,send: function(content) {
		var post = false;
		switch(this._method.toUpperCase()) {
		case "POST":
			post = true;
			break;
		}
		this._http.request(post);
		this.setReadyState(3);
	}
	,setRequestHeader: function(name,value) {
		this._http.setHeader(name,value);
	}
	,onHTTPStatus: function(status) {
		this._status = status;
	}
	,onHTTPData: function(data) {
		this._responseText = data;
		this.setReadyState(4);
	}
	,onHTTPError: function(data) {
		this._responseText = data;
		this.setReadyState(4);
	}
	,setReadyState: function(value) {
		this._readyState = value;
		if(this.onReadyStateChange != null) this.onReadyStateChange(new cocktail.core.event.Event("readystatechange",this));
	}
	,get_readyState: function() {
		return this._readyState;
	}
	,get_status: function() {
		return this._status;
	}
	,get_responseText: function() {
		return this._responseText;
	}
	,__class__: cocktail.core.resource.XMLHTTPRequest
	,__properties__: {get_status:"get_status",get_responseText:"get_responseText",get_readyState:"get_readyState"}
}
if(!cocktail.core.style) cocktail.core.style = {}
cocktail.core.style.CoreStyle = $hxClasses["cocktail.core.style.CoreStyle"] = function(htmlElement) {
	this._htmlElement = htmlElement;
	this._isDirty = false;
	this.initDefaultStyleValues();
};
cocktail.core.style.CoreStyle.__name__ = ["cocktail","core","style","CoreStyle"];
cocktail.core.style.CoreStyle.getDefaultStyle = function() {
	return { fontFamily : ["serif"], color : cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.black)};
}
cocktail.core.style.CoreStyle.prototype = {
	_display: null
	,display: null
	,_position: null
	,position: null
	,_cssFloat: null
	,cssFloat: null
	,_clear: null
	,clear: null
	,_transformOrigin: null
	,transformOrigin: null
	,_transform: null
	,transform: null
	,_marginLeft: null
	,marginLeft: null
	,_marginRight: null
	,marginRight: null
	,_marginTop: null
	,marginTop: null
	,_marginBottom: null
	,marginBottom: null
	,_paddingLeft: null
	,paddingLeft: null
	,_paddingRight: null
	,paddingRight: null
	,_paddingTop: null
	,paddingTop: null
	,_paddingBottom: null
	,paddingBottom: null
	,_width: null
	,width: null
	,_height: null
	,height: null
	,_minHeight: null
	,minHeight: null
	,_maxHeight: null
	,maxHeight: null
	,_minWidth: null
	,minWidth: null
	,_maxWidth: null
	,maxWidth: null
	,_top: null
	,top: null
	,_left: null
	,left: null
	,_bottom: null
	,bottom: null
	,_right: null
	,right: null
	,_backgroundColor: null
	,backgroundColor: null
	,_backgroundImage: null
	,backgroundImage: null
	,_backgroundRepeat: null
	,backgroundRepeat: null
	,_backgroundOrigin: null
	,backgroundOrigin: null
	,_backgroundSize: null
	,backgroundSize: null
	,_backgroundPosition: null
	,backgroundPosition: null
	,_backgroundClip: null
	,backgroundClip: null
	,_fontSize: null
	,fontSize: null
	,_fontWeight: null
	,fontWeight: null
	,_fontStyle: null
	,fontStyle: null
	,_fontFamily: null
	,fontFamily: null
	,_fontVariant: null
	,fontVariant: null
	,_color: null
	,color: null
	,_lineHeight: null
	,lineHeight: null
	,_textTransform: null
	,textTransform: null
	,_letterSpacing: null
	,letterSpacing: null
	,_wordSpacing: null
	,wordSpacing: null
	,_whiteSpace: null
	,whiteSpace: null
	,_textAlign: null
	,textAlign: null
	,_textIndent: null
	,textIndent: null
	,_verticalAlign: null
	,verticalAlign: null
	,_opacity: null
	,opacity: null
	,_visibility: null
	,visibility: null
	,_overflowX: null
	,overflowX: null
	,_overflowY: null
	,overflowY: null
	,_cursor: null
	,cursor: null
	,_computedStyle: null
	,computedStyle: null
	,_htmlElement: null
	,htmlElement: null
	,_fontMetrics: null
	,fontMetrics: null
	,_isDirty: null
	,_elementRenderer: null
	,elementRenderer: null
	,initDefaultStyleValues: function() {
		this.initComputedStyles();
		this._width = cocktail.core.style.Dimension.cssAuto;
		this._height = cocktail.core.style.Dimension.cssAuto;
		this._minWidth = cocktail.core.style.ConstrainedDimension.length(cocktail.core.unit.Length.px(0));
		this._maxWidth = cocktail.core.style.ConstrainedDimension.none;
		this._minHeight = cocktail.core.style.ConstrainedDimension.length(cocktail.core.unit.Length.px(0));
		this._maxHeight = cocktail.core.style.ConstrainedDimension.none;
		this._marginTop = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(0));
		this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(0));
		this._marginLeft = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(0));
		this._marginRight = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(0));
		this._paddingTop = cocktail.core.style.Padding.length(cocktail.core.unit.Length.px(0));
		this._paddingBottom = cocktail.core.style.Padding.length(cocktail.core.unit.Length.px(0));
		this._paddingLeft = cocktail.core.style.Padding.length(cocktail.core.unit.Length.px(0));
		this._paddingRight = cocktail.core.style.Padding.length(cocktail.core.unit.Length.px(0));
		this._lineHeight = cocktail.core.style.LineHeight.normal;
		this._verticalAlign = cocktail.core.style.VerticalAlign.baseline;
		this._display = cocktail.core.style.Display.cssInline;
		this._position = cocktail.core.style.Position.cssStatic;
		this._top = cocktail.core.style.PositionOffset.cssAuto;
		this._bottom = cocktail.core.style.PositionOffset.cssAuto;
		this._left = cocktail.core.style.PositionOffset.cssAuto;
		this._right = cocktail.core.style.PositionOffset.cssAuto;
		this._cssFloat = cocktail.core.style.CSSFloat.none;
		this._clear = cocktail.core.style.Clear.none;
		this._backgroundColor = cocktail.core.unit.CSSColor.transparent;
		this._backgroundImage = [cocktail.core.style.BackgroundImage.none];
		this._backgroundRepeat = [{ x : cocktail.core.style.BackgroundRepeatValue.repeat, y : cocktail.core.style.BackgroundRepeatValue.repeat}];
		this._backgroundPosition = [{ x : cocktail.core.style.BackgroundPositionX.percent(0), y : cocktail.core.style.BackgroundPositionY.percent(0)}];
		this._backgroundOrigin = [cocktail.core.style.BackgroundOrigin.paddingBox];
		this._backgroundSize = [cocktail.core.style.BackgroundSize.dimensions({ x : cocktail.core.style.BackgroundSizeDimension.cssAuto, y : cocktail.core.style.BackgroundSizeDimension.cssAuto})];
		this._backgroundClip = [cocktail.core.style.BackgroundClip.borderBox];
		this._fontStyle = cocktail.core.style.FontStyle.normal;
		this._fontVariant = cocktail.core.style.FontVariant.normal;
		this._fontWeight = cocktail.core.style.FontWeight.normal;
		this._fontSize = cocktail.core.style.FontSize.absoluteSize(cocktail.core.unit.FontSizeAbsoluteSize.medium);
		this._textIndent = cocktail.core.style.TextIndent.length(cocktail.core.unit.Length.px(0));
		this._textAlign = cocktail.core.style.TextAlign.left;
		this._letterSpacing = cocktail.core.style.LetterSpacing.normal;
		this._wordSpacing = cocktail.core.style.WordSpacing.normal;
		this._textTransform = cocktail.core.style.TextTransform.none;
		this._whiteSpace = cocktail.core.style.WhiteSpace.normal;
		this._visibility = cocktail.core.style.Visibility.visible;
		this._opacity = 1.0;
		this._overflowX = cocktail.core.style.Overflow.visible;
		this._overflowY = cocktail.core.style.Overflow.visible;
		this._transformOrigin = { x : cocktail.core.style.TransformOriginX.center, y : cocktail.core.style.TransformOriginY.center};
		this._transform = cocktail.core.style.Transform.none;
		this._cursor = cocktail.core.style.Cursor.cssDefault;
		var defaultStyles = cocktail.core.style.CoreStyle.getDefaultStyle();
		this._fontFamily = defaultStyles.fontFamily;
		this._color = defaultStyles.color;
		this.applyDefaultHTMLStyles();
	}
	,initComputedStyles: function() {
		this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.core.style.Clear.none, cssFloat : cocktail.core.style.CSSFloat.none, display : cocktail.core.style.Display.block, position : cocktail.core.style.Position.cssStatic, verticalAlign : 0.0, fontSize : 16.0, lineHeight : 14.0, fontWeight : cocktail.core.style.FontWeight.normal, fontStyle : cocktail.core.style.FontStyle.normal, fontFamily : ["serif"], fontVariant : cocktail.core.style.FontVariant.normal, textTransform : cocktail.core.style.TextTransform.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.core.style.WhiteSpace.normal, textAlign : cocktail.core.style.TextAlign.left, color : { color : 0, alpha : 1.0}, visibility : true, opacity : 1.0, overflowX : cocktail.core.style.Overflow.visible, overflowY : cocktail.core.style.Overflow.visible, transformOrigin : { x : 0.0, y : 0.0}, transform : new cocktail.core.geom.Matrix(), backgroundColor : { color : 0, alpha : 1.0}, backgroundSize : [], backgroundOrigin : [], backgroundImage : [], backgroundClip : [], backgroundPosition : [], backgroundRepeat : [], cursor : cocktail.core.style.Cursor.cssDefault};
	}
	,applyDefaultHTMLStyles: function() {
		switch(this._htmlElement.get_tagName()) {
		case "html":case "adress":case "dd":case "div":case "dl":case "dt":case "fieldset":case "form":case "frame":case "frameset":case "noframes":case "ol":case "ul":case "center":case "dir":case "hr":case "menu":
			this._display = cocktail.core.style.Display.block;
			break;
		case "head":
			this._display = cocktail.core.style.Display.none;
			break;
		case "body":
			this._display = cocktail.core.style.Display.block;
			this._marginLeft = this._marginRight = this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(8));
			break;
		case "h1":
			this._display = cocktail.core.style.Display.block;
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(2));
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(0.67));
			break;
		case "h2":
			this._display = cocktail.core.style.Display.block;
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(1.5));
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(0.75));
			break;
		case "h3":
			this._display = cocktail.core.style.Display.block;
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(1.17));
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(0.83));
			break;
		case "h4":
			this._display = cocktail.core.style.Display.block;
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(1.12));
			break;
		case "h5":
			this._display = cocktail.core.style.Display.block;
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(0.83));
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(1.5));
			break;
		case "h6":
			this._display = cocktail.core.style.Display.block;
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(0.75));
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(1.67));
			break;
		case "p":
			this._display = cocktail.core.style.Display.block;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(1.67));
			break;
		case "pre":
			this._display = cocktail.core.style.Display.block;
			this._whiteSpace = cocktail.core.style.WhiteSpace.pre;
			this._fontFamily = ["monospace"];
			break;
		case "code":
			this._fontFamily = ["monospace"];
			break;
		case "i":case "cite":case "em":case "var":
			this._fontStyle = cocktail.core.style.FontStyle.italic;
			break;
		case "input":
			this._display = cocktail.core.style.Display.inlineBlock;
			break;
		case "blockquote":
			this._display = cocktail.core.style.Display.block;
			this._marginTop = this._marginBottom = cocktail.core.style.Margin.length(cocktail.core.unit.Length.em(1.12));
			this._marginLeft = this._marginRight = cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(40));
			break;
		case "strong":
			this._fontWeight = cocktail.core.style.FontWeight.bolder;
			break;
		case "big":
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(1.17));
			break;
		case "small":
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(0.83));
			break;
		case "sub":
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(0.83));
			this._verticalAlign = cocktail.core.style.VerticalAlign.sub;
			break;
		case "sup":
			this._fontSize = cocktail.core.style.FontSize.length(cocktail.core.unit.Length.em(0.83));
			this._verticalAlign = cocktail.core.style.VerticalAlign.cssSuper;
			break;
		}
	}
	,createElementRenderer: function(parentElementRenderer) {
		var elementRenderer = new cocktail.core.renderer.EmbeddedBoxRenderer(this);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		parentElementRenderer.appendChild(elementRenderer);
		return elementRenderer;
	}
	,getLayerRenderer: function(elementRenderer,parentElementRenderer) {
		var layerRenderer;
		if(this.isPositioned() == true) layerRenderer = new cocktail.core.renderer.LayerRenderer(elementRenderer); else layerRenderer = parentElementRenderer.getLayerRenderer();
		return layerRenderer;
	}
	,flow: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext,parentElementRenderer) {
		if(this._elementRenderer != null && parentElementRenderer != null) parentElementRenderer.removeChild(this._elementRenderer);
		if(this.isDisplayed() == false) return;
		this.initComputedStyles();
		this.computeHTMLElementStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData.data,containingHTMLElementFontMetricsData);
		this._elementRenderer = this.createElementRenderer(parentElementRenderer);
		this.flowChildren(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext);
		this.computeVisualEffectStyles();
		this.computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		this.computeBackgroundStyles();
		this.insertHTMLElement(formattingContext,lastPositionedHTMLElementData,viewportData);
		this._isDirty = false;
	}
	,positionElement: function(lastPositionedHTMLElementData,viewportData,staticPosition) {
		var positioner;
		switch( (this._htmlElement.get_coreStyle().getComputedStyle().position)[1] ) {
		case 1:
			positioner = new cocktail.core.style.positioner.RelativePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedHTMLElementData,staticPosition);
			break;
		case 3:
			positioner = new cocktail.core.style.positioner.FixedPositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,viewportData,staticPosition);
			break;
		case 2:
			positioner = new cocktail.core.style.positioner.AbsolutePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedHTMLElementData,staticPosition);
			break;
		default:
		}
		this._elementRenderer.getBounds().width = this._computedStyle.width + this._computedStyle.paddingLeft + this._computedStyle.paddingRight;
		this._elementRenderer.getBounds().height = this._computedStyle.height + this._computedStyle.paddingTop + this._computedStyle.paddingBottom;
		return this._elementRenderer;
	}
	,flowChildren: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
	}
	,insertHTMLElement: function(formattingContext,lastPositionedHTMLElementData,viewportData) {
		if(this.isPositioned() == false) formattingContext.insertElement(this._elementRenderer); else {
			var staticPosition = formattingContext.getStaticPosition(this._elementRenderer);
			if(this.isRelativePositioned() == true) formattingContext.insertElement(this._elementRenderer);
			var positionedHTMLElementData = { staticPosition : staticPosition, coreStyle : this};
			lastPositionedHTMLElementData.children.push(positionedHTMLElementData);
		}
	}
	,invalidate: function(immediate) {
		if(immediate == null) immediate = false;
		if(this._isDirty == false || immediate == true) {
			this._isDirty = true;
			if(this._htmlElement.get_parentNode() != null) {
				var parent = this._htmlElement.get_parentNode();
				parent.get_coreStyle().invalidate(immediate);
			}
		}
	}
	,computeDisplayStyles: function() {
		cocktail.core.style.computer.DisplayStylesComputer.compute(this);
	}
	,computeBackgroundStyles: function() {
		cocktail.core.style.computer.BackgroundStylesComputer.compute(this);
	}
	,computeHTMLElementStyles: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData) {
		this.computeDisplayStyles();
		this.computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		this.computeBoxModelStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
	}
	,computeVisualEffectStyles: function() {
		cocktail.core.style.computer.VisualEffectStylesComputer.compute(this);
	}
	,computeTextAndFontStyles: function(containingHTMLElementData,containingHTMLElementFontMetricsData) {
		cocktail.core.style.computer.FontAndTextStylesComputer.compute(this,containingHTMLElementData,containingHTMLElementFontMetricsData);
	}
	,computeBoxModelStyles: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
		var boxComputer = this.getBoxStylesComputer();
		var containingBlockDimensions = this.getContainingHTMLElementData(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
		boxComputer.measure(this,containingBlockDimensions);
	}
	,getBoxStylesComputer: function() {
		var boxComputer;
		if(this.isFloat() == true) boxComputer = new cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer(); else {
			switch( (this._computedStyle.display)[1] ) {
			case 0:
				boxComputer = new cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer();
				break;
			case 1:
				boxComputer = new cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer();
				break;
			case 3:
				boxComputer = null;
				break;
			case 2:
				boxComputer = new cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer();
				break;
			}
		}
		return boxComputer;
	}
	,getContainingHTMLElementData: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
		var containingBlockDimensions;
		if(this.isPositioned() == true) {
			if(this._computedStyle.position == cocktail.core.style.Position.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto}; else if(this._computedStyle.position == cocktail.core.style.Position.absolute) containingBlockDimensions = { width : lastPositionedHTMLElementData.width, height : lastPositionedHTMLElementData.height, isHeightAuto : lastPositionedHTMLElementData.isHeightAuto, isWidthAuto : lastPositionedHTMLElementData.isWidthAuto}; else containingBlockDimensions = containingHTMLElementData;
		} else containingBlockDimensions = containingHTMLElementData;
		return containingBlockDimensions;
	}
	,isFloat: function() {
		var ret = false;
		switch( (this._computedStyle.cssFloat)[1] ) {
		case 0:
		case 1:
			ret = true;
			break;
		case 2:
			ret = false;
			break;
		}
		return ret;
	}
	,isPositioned: function() {
		var ret = false;
		switch( (this._computedStyle.position)[1] ) {
		case 1:
		case 2:
		case 3:
			ret = true;
			break;
		case 0:
			ret = false;
			break;
		}
		return ret;
	}
	,isRelativePositioned: function() {
		return this._computedStyle.position == cocktail.core.style.Position.relative;
	}
	,childrenInline: function() {
		return false;
	}
	,isInlineLevel: function() {
		var ret = false;
		switch( (this._computedStyle.display)[1] ) {
		case 2:
		case 1:
			ret = true;
			break;
		default:
			ret = false;
		}
		return ret;
	}
	,establishesNewFormattingContext: function() {
		return false;
	}
	,getFirstPositionedAncestor: function() {
		if(this._htmlElement.get_parentNode() == null) return null;
		var parent = this._htmlElement.get_parentNode();
		var isOffsetParent = parent.get_coreStyle().isOffsetParent();
		while(isOffsetParent == false) if(parent.get_parentNode() != null) {
			parent = parent.get_parentNode();
			isOffsetParent = parent.get_coreStyle().isOffsetParent();
		} else isOffsetParent = true;
		return parent;
	}
	,isOffsetParent: function() {
		return this.isPositioned();
	}
	,isClear: function() {
		var ret = false;
		switch( (this._computedStyle.clear)[1] ) {
		case 1:
		case 2:
		case 3:
			ret = true;
			break;
		case 0:
			ret = false;
			break;
		}
		return ret;
	}
	,isDisplayed: function() {
		return this._computedStyle.display != cocktail.core.style.Display.none;
	}
	,getFirstPositionedAncestorData: function() {
		var firstPositionedAncestorData;
		var firstPositionedAncestor = this.getFirstPositionedAncestor();
		if(firstPositionedAncestor != null) {
			var firstPositionedAncestorStyle = firstPositionedAncestor.get_coreStyle();
			firstPositionedAncestorData = firstPositionedAncestorStyle.getContainerHTMLElementData();
		} else firstPositionedAncestorData = this.getWindowData();
		return firstPositionedAncestorData;
	}
	,getWindowData: function() {
		var windowData = { isHeightAuto : false, isWidthAuto : false, width : cocktail.Lib.get_window().get_innerWidth(), height : cocktail.Lib.get_window().get_innerHeight()};
		return windowData;
	}
	,getElementRenderer: function() {
		return this._elementRenderer;
	}
	,getFontMetricsData: function() {
		var fontManager = new cocktail.port.browser.FontManager();
		this._fontMetrics = fontManager.getFontMetrics(cocktail.core.unit.UnitManager.getCSSFontFamily(this._computedStyle.fontFamily),this._computedStyle.fontSize);
		return this._fontMetrics;
	}
	,getComputedStyle: function() {
		return this._computedStyle;
	}
	,setComputedStyle: function(value) {
		return this._computedStyle = value;
	}
	,get_htmlElement: function() {
		return this._htmlElement;
	}
	,setWidth: function(value) {
		this.invalidate();
		return this._width = value;
	}
	,setMarginLeft: function(value) {
		this.invalidate();
		return this._marginLeft = value;
	}
	,setMarginRight: function(value) {
		this.invalidate();
		return this._marginRight = value;
	}
	,setMarginTop: function(value) {
		this.invalidate();
		return this._marginTop = value;
	}
	,setMarginBottom: function(value) {
		this.invalidate();
		return this._marginBottom = value;
	}
	,setPaddingLeft: function(value) {
		this.invalidate();
		return this._paddingLeft = value;
	}
	,setPaddingRight: function(value) {
		this.invalidate();
		return this._paddingRight = value;
	}
	,setPaddingTop: function(value) {
		this.invalidate();
		return this._paddingTop = value;
	}
	,setPaddingBottom: function(value) {
		this.invalidate();
		return this._paddingBottom = value;
	}
	,setDisplay: function(value) {
		this.invalidate();
		return this._display = value;
	}
	,setPosition: function(value) {
		this.invalidate();
		return this._position = value;
	}
	,setHeight: function(value) {
		this.invalidate();
		return this._height = value;
	}
	,setMinHeight: function(value) {
		this.invalidate();
		return this._minHeight = value;
	}
	,setMaxHeight: function(value) {
		this.invalidate();
		return this._maxHeight = value;
	}
	,setMinWidth: function(value) {
		this.invalidate();
		return this._minWidth = value;
	}
	,setMaxWidth: function(value) {
		this.invalidate();
		return this._maxWidth = value;
	}
	,setTop: function(value) {
		this.invalidate();
		return this._top = value;
	}
	,setLeft: function(value) {
		this.invalidate();
		return this._left = value;
	}
	,setBottom: function(value) {
		this.invalidate();
		return this._bottom = value;
	}
	,setRight: function(value) {
		this.invalidate();
		return this._right = value;
	}
	,setCSSFloat: function(value) {
		this.invalidate();
		return this._cssFloat = value;
	}
	,setClear: function(value) {
		this.invalidate();
		return this._clear = value;
	}
	,setFontSize: function(value) {
		this.invalidate();
		return this._fontSize = value;
	}
	,setFontWeight: function(value) {
		this.invalidate();
		return this._fontWeight = value;
	}
	,setFontStyle: function(value) {
		this.invalidate();
		return this._fontStyle = value;
	}
	,setFontFamily: function(value) {
		this.invalidate();
		return this._fontFamily = value;
	}
	,setFontVariant: function(value) {
		this.invalidate();
		return this._fontVariant = value;
	}
	,setTextTransform: function(value) {
		this.invalidate();
		return this._textTransform = value;
	}
	,setLetterSpacing: function(value) {
		this.invalidate();
		return this._letterSpacing = value;
	}
	,setWordSpacing: function(value) {
		this.invalidate();
		return this._wordSpacing = value;
	}
	,setLineHeight: function(value) {
		this.invalidate();
		return this._lineHeight = value;
	}
	,setColor: function(value) {
		this.invalidate();
		return this._color = value;
	}
	,setVerticalAlign: function(value) {
		this.invalidate();
		return this._verticalAlign = value;
	}
	,setTextIndent: function(value) {
		this.invalidate();
		return this._textIndent = value;
	}
	,setWhiteSpace: function(value) {
		this.invalidate();
		return this._whiteSpace = value;
	}
	,setTextAlign: function(value) {
		this.invalidate();
		return this._textAlign = value;
	}
	,setOpacity: function(value) {
		this._opacity = value;
		this.invalidate();
		return this._opacity;
	}
	,setVisibility: function(value) {
		this._visibility = value;
		this.invalidate();
		return this._visibility;
	}
	,setTransformOrigin: function(value) {
		this.invalidate();
		return this._transformOrigin = value;
	}
	,setTransform: function(value) {
		this.invalidate();
		return this._transform = value;
	}
	,setOverflowX: function(value) {
		this.invalidate();
		return this._overflowX = value;
	}
	,setOverflowY: function(value) {
		this.invalidate();
		return this._overflowY = value;
	}
	,getOpacity: function() {
		return this._opacity;
	}
	,getVisibility: function() {
		return this._visibility;
	}
	,getMarginLeft: function() {
		return this._marginLeft;
	}
	,getMarginRight: function() {
		return this._marginRight;
	}
	,getMarginTop: function() {
		return this._marginTop;
	}
	,getMarginBottom: function() {
		return this._marginBottom;
	}
	,getPaddingLeft: function() {
		return this._paddingLeft;
	}
	,getPaddingRight: function() {
		return this._paddingRight;
	}
	,getPaddingTop: function() {
		return this._paddingTop;
	}
	,getPaddingBottom: function() {
		return this._paddingBottom;
	}
	,getDisplay: function() {
		return this._display;
	}
	,getPosition: function() {
		return this._position;
	}
	,getWidth: function() {
		return this._width;
	}
	,getHeight: function() {
		return this._height;
	}
	,getMinHeight: function() {
		return this._minHeight;
	}
	,getMaxHeight: function() {
		return this._maxHeight;
	}
	,getMinWidth: function() {
		return this._minWidth;
	}
	,getMaxWidth: function() {
		return this._maxWidth;
	}
	,getTop: function() {
		return this._top;
	}
	,getLeft: function() {
		return this._left;
	}
	,getBottom: function() {
		return this._bottom;
	}
	,getRight: function() {
		return this._right;
	}
	,getCSSFloat: function() {
		return this._cssFloat;
	}
	,getClear: function() {
		return this._clear;
	}
	,getFontSize: function() {
		return this._fontSize;
	}
	,getFontWeight: function() {
		return this._fontWeight;
	}
	,getFontStyle: function() {
		return this._fontStyle;
	}
	,getFontFamily: function() {
		return this._fontFamily;
	}
	,getFontVariant: function() {
		return this._fontVariant;
	}
	,getTextTransform: function() {
		return this._textTransform;
	}
	,getLetterSpacing: function() {
		return this._letterSpacing;
	}
	,getColor: function() {
		return this._color;
	}
	,getWordSpacing: function() {
		return this._wordSpacing;
	}
	,getLineHeight: function() {
		return this._lineHeight;
	}
	,getVerticalAlign: function() {
		return this._verticalAlign;
	}
	,getTextIndent: function() {
		return this._textIndent;
	}
	,getWhiteSpace: function() {
		return this._whiteSpace;
	}
	,getTextAlign: function() {
		return this._textAlign;
	}
	,getTransform: function() {
		return this._transform;
	}
	,getTransformOrigin: function() {
		return this._transformOrigin;
	}
	,setBackgroundColor: function(value) {
		this.invalidate();
		return this._backgroundColor = value;
	}
	,getBackgroundColor: function() {
		return this._backgroundColor;
	}
	,setBackgroundImage: function(value) {
		this.invalidate();
		return this._backgroundImage = value;
	}
	,getBackgroundImage: function() {
		return this._backgroundImage;
	}
	,setBackgroundRepeat: function(value) {
		this.invalidate();
		return this._backgroundRepeat = value;
	}
	,getBackgroundRepeat: function() {
		return this._backgroundRepeat;
	}
	,setBackgroundSize: function(value) {
		this.invalidate();
		return this._backgroundSize = value;
	}
	,getBackgroundSize: function() {
		return this._backgroundSize;
	}
	,setBackgroundClip: function(value) {
		this.invalidate();
		return this._backgroundClip = value;
	}
	,getBackgroundClip: function() {
		return this._backgroundClip;
	}
	,setBackgroundPosition: function(value) {
		this.invalidate();
		return this._backgroundPosition = value;
	}
	,getBackgroundPosition: function() {
		return this._backgroundPosition;
	}
	,setBackgroundOrigin: function(value) {
		this.invalidate();
		return this._backgroundOrigin = value;
	}
	,getBackgroundOrigin: function() {
		return this._backgroundOrigin;
	}
	,getOverflowX: function() {
		return this._overflowX;
	}
	,getOverflowY: function() {
		return this._overflowY;
	}
	,setCursor: function(value) {
		return this._cursor = value;
	}
	,getCursor: function() {
		return this._cursor;
	}
	,__class__: cocktail.core.style.CoreStyle
	,__properties__: {get_elementRenderer:"getElementRenderer",get_fontMetrics:"getFontMetricsData",get_htmlElement:"get_htmlElement",set_computedStyle:"setComputedStyle",get_computedStyle:"getComputedStyle",set_cursor:"setCursor",get_cursor:"getCursor",set_overflowY:"setOverflowY",get_overflowY:"getOverflowY",set_overflowX:"setOverflowX",get_overflowX:"getOverflowX",set_visibility:"setVisibility",get_visibility:"getVisibility",set_opacity:"setOpacity",get_opacity:"getOpacity",set_verticalAlign:"setVerticalAlign",get_verticalAlign:"getVerticalAlign",set_textIndent:"setTextIndent",get_textIndent:"getTextIndent",set_textAlign:"setTextAlign",get_textAlign:"getTextAlign",set_whiteSpace:"setWhiteSpace",get_whiteSpace:"getWhiteSpace",set_wordSpacing:"setWordSpacing",get_wordSpacing:"getWordSpacing",set_letterSpacing:"setLetterSpacing",get_letterSpacing:"getLetterSpacing",set_textTransform:"setTextTransform",get_textTransform:"getTextTransform",set_lineHeight:"setLineHeight",get_lineHeight:"getLineHeight",set_color:"setColor",get_color:"getColor",set_fontVariant:"setFontVariant",get_fontVariant:"getFontVariant",set_fontFamily:"setFontFamily",get_fontFamily:"getFontFamily",set_fontStyle:"setFontStyle",get_fontStyle:"getFontStyle",set_fontWeight:"setFontWeight",get_fontWeight:"getFontWeight",set_fontSize:"setFontSize",get_fontSize:"getFontSize",set_backgroundClip:"setBackgroundClip",get_backgroundClip:"getBackgroundClip",set_backgroundPosition:"setBackgroundPosition",get_backgroundPosition:"getBackgroundPosition",set_backgroundSize:"setBackgroundSize",get_backgroundSize:"getBackgroundSize",set_backgroundOrigin:"setBackgroundOrigin",get_backgroundOrigin:"getBackgroundOrigin",set_backgroundRepeat:"setBackgroundRepeat",get_backgroundRepeat:"getBackgroundRepeat",set_backgroundImage:"setBackgroundImage",get_backgroundImage:"getBackgroundImage",set_backgroundColor:"setBackgroundColor",get_backgroundColor:"getBackgroundColor",set_right:"setRight",get_right:"getRight",set_bottom:"setBottom",get_bottom:"getBottom",set_left:"setLeft",get_left:"getLeft",set_top:"setTop",get_top:"getTop",set_maxWidth:"setMaxWidth",get_maxWidth:"getMaxWidth",set_minWidth:"setMinWidth",get_minWidth:"getMinWidth",set_maxHeight:"setMaxHeight",get_maxHeight:"getMaxHeight",set_minHeight:"setMinHeight",get_minHeight:"getMinHeight",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_paddingBottom:"setPaddingBottom",get_paddingBottom:"getPaddingBottom",set_paddingTop:"setPaddingTop",get_paddingTop:"getPaddingTop",set_paddingRight:"setPaddingRight",get_paddingRight:"getPaddingRight",set_paddingLeft:"setPaddingLeft",get_paddingLeft:"getPaddingLeft",set_marginBottom:"setMarginBottom",get_marginBottom:"getMarginBottom",set_marginTop:"setMarginTop",get_marginTop:"getMarginTop",set_marginRight:"setMarginRight",get_marginRight:"getMarginRight",set_marginLeft:"setMarginLeft",get_marginLeft:"getMarginLeft",set_transform:"setTransform",get_transform:"getTransform",set_transformOrigin:"setTransformOrigin",get_transformOrigin:"getTransformOrigin",set_clear:"setClear",get_clear:"getClear",set_cssFloat:"setCSSFloat",get_cssFloat:"getCSSFloat",set_position:"setPosition",get_position:"getPosition",set_display:"setDisplay",get_display:"getDisplay"}
}
cocktail.core.style.ContainerCoreStyle = $hxClasses["cocktail.core.style.ContainerCoreStyle"] = function(htmlElement) {
	cocktail.core.style.CoreStyle.call(this,htmlElement);
};
cocktail.core.style.ContainerCoreStyle.__name__ = ["cocktail","core","style","ContainerCoreStyle"];
cocktail.core.style.ContainerCoreStyle.__super__ = cocktail.core.style.CoreStyle;
cocktail.core.style.ContainerCoreStyle.prototype = $extend(cocktail.core.style.CoreStyle.prototype,{
	createElementRenderer: function(parentElementRenderer) {
		var elementRenderer;
		if(this.isInlineLevel() == true && this.establishesNewFormattingContext() == false) elementRenderer = new cocktail.core.renderer.InlineBoxRenderer(this); else elementRenderer = new cocktail.core.renderer.BlockBoxRenderer(this);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		parentElementRenderer.appendChild(elementRenderer);
		return elementRenderer;
	}
	,flowChildren: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
		var _g1 = 0, _g = this._htmlElement.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._htmlElement.get_childNodes()[i].get_nodeType() == 1) {
				var childHTMLElement = this._htmlElement.get_childNodes()[i];
				childHTMLElement.get_coreStyle().computeDisplayStyles();
			}
		}
		var childrenFormattingContext = this.getformattingContext(formattingContext);
		var childrenContainingHTMLElementData = this.getContainerHTMLElementData();
		var childrenContainingHTMLElementFontMetricsData = this.getFontMetricsData();
		var childLastPositionedHTMLElementData;
		childLastPositionedHTMLElementData = this.getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		childrenFormattingContext = this.doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext);
		if(this._width == cocktail.core.style.Dimension.cssAuto) this.shrinkToFitIfNeeded(containingHTMLElementData,childrenFormattingContext.getMaxWidth(),formattingContext,lastPositionedHTMLElementData,viewportData);
		if(this._height == cocktail.core.style.Dimension.cssAuto) {
			if(this.establishesNewFormattingContext() == false) childrenFormattingContext.format();
			this._computedStyle.height = this.applyContentHeightIfNeeded(containingHTMLElementData,childrenFormattingContext.getChildrenHeight(this._elementRenderer));
		}
		this.positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData,viewportData);
		if(this.establishesNewFormattingContext() == true) childrenFormattingContext.dispose();
	}
	,doFlowChildren: function(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext) {
		var flowBoxRenderer = this._elementRenderer;
		var _g1 = 0, _g = this._htmlElement.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._htmlElement.get_childNodes()[i].get_nodeType() == 1) {
				var childHTMLElement = this._htmlElement.get_childNodes()[i];
				childHTMLElement.get_coreStyle().flow(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext,this._elementRenderer);
			} else {
				var childrenText = this._htmlElement.get_childNodes()[i];
				var insertedText = this.insertTextElement(childrenText,childrenFormattingContext,childrenContainingHTMLElementData);
				var _g3 = 0, _g2 = insertedText.length;
				while(_g3 < _g2) {
					var j = _g3++;
					flowBoxRenderer.appendChild(insertedText[j]);
				}
			}
		}
		if(this.establishesNewFormattingContext() == true) childrenFormattingContext.format();
		return childrenFormattingContext;
	}
	,positionAbsolutelyPositionedHTMLElementsIfNeeded: function(childLastPositionedHTMLElementData,viewportData) {
		if(this.isPositioned() == true) this.doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
	}
	,doPositionAbsolutelyPositionedHTMLElements: function(childLastPositionedHTMLElementData,viewportData) {
		childLastPositionedHTMLElementData.data = this.getPositionedHTMLElementData();
		var _g1 = 0, _g = childLastPositionedHTMLElementData.children.length;
		while(_g1 < _g) {
			var i = _g1++;
			var positionedHTMLElementData = childLastPositionedHTMLElementData.children[i];
			positionedHTMLElementData.coreStyle.positionElement(childLastPositionedHTMLElementData.data,viewportData,positionedHTMLElementData.staticPosition);
		}
	}
	,insertTextElement: function(textElement,formattingContext,containingHTMLElementData) {
		var rendereredText = new Array();
		var text = textElement.get_nodeValue();
		var textFragments = textElement.getTextFragments(text);
		var _g1 = 0, _g = textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			var textRenderer = this.createTextRendererFromTextFragment(textFragments[i]);
			formattingContext.insertElement(textRenderer);
			rendereredText.push(textRenderer);
		}
		return rendereredText;
	}
	,createTextRendererFromTextFragment: function(textFragment) {
		var text;
		var $e = (textFragment.textToken);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			text = value;
			break;
		case 1:
			text = " ";
			break;
		case 2:
			text = "";
			break;
		case 3:
			text = "";
			break;
		}
		var textRenderer = this.getTextRenderer(textFragment,text);
		return textRenderer;
	}
	,shrinkToFitIfNeeded: function(containingHTMLElementData,minimumWidth,formattingContext,lastPositionedHTMLElementData,viewportData) {
		var boxComputer = this.getBoxStylesComputer();
		var shrinkedWidth = boxComputer.shrinkToFit(this,containingHTMLElementData,minimumWidth);
		if(this._computedStyle.width != shrinkedWidth) {
			this._computedStyle.width = shrinkedWidth;
			var childrenFormattingContext = this.getformattingContext(formattingContext);
			var childrenContainingHTMLElementData = this.getContainerHTMLElementData();
			var childLastPositionedHTMLElementData = this.getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			childrenFormattingContext = this.doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,this.getFontMetricsData(),childrenFormattingContext);
		}
	}
	,applyContentHeightIfNeeded: function(containingHTMLElementData,childrenHeight) {
		var boxComputer = this.getBoxStylesComputer();
		return boxComputer.applyContentHeight(this,containingHTMLElementData,childrenHeight);
	}
	,getBoxStylesComputer: function() {
		var boxComputer;
		if(this.isFloat() == true) boxComputer = new cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer(); else {
			switch( (this._computedStyle.display)[1] ) {
			case 0:
				boxComputer = new cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer();
				break;
			case 1:
				boxComputer = new cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer();
				break;
			case 3:
				boxComputer = null;
				break;
			case 2:
				boxComputer = new cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer();
				break;
			}
		}
		return boxComputer;
	}
	,getTextRenderer: function(textFragmentData,text) {
		var fontManager = new cocktail.port.browser.FontManager();
		var nativeTextElement = fontManager.createNativeTextElement(text,this._computedStyle);
		var textRenderer = new cocktail.core.renderer.TextRenderer(this,nativeTextElement,textFragmentData.textToken);
		textRenderer.setLayerRenderer(this._elementRenderer.getLayerRenderer());
		textFragmentData.textRenderer = textRenderer;
		return textRenderer;
	}
	,establishesNewFormattingContext: function() {
		var ret = false;
		if(this.isFloat() == true) ret = true; else if(this.isPositioned() == true && this.isRelativePositioned() == false) ret = true; else {
			switch( (this._computedStyle.display)[1] ) {
			case 1:
				ret = true;
				break;
			case 0:
				if(this.childrenInline() == true) ret = true;
				break;
			default:
			}
		}
		return ret;
	}
	,childrenInline: function() {
		if(this._htmlElement.get_childNodes().length == 0) return false;
		var ret = this.isChildInline(this._htmlElement.get_childNodes()[0]);
		var _g1 = 0, _g = this._htmlElement.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isChildInline(this._htmlElement.get_childNodes()[i]) != ret) {
			}
		}
		return ret;
	}
	,getContainerHTMLElementData: function() {
		var height;
		if(this.isInlineLevel() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.establishesNewFormattingContext() == true && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
		return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.core.style.Dimension.cssAuto, height : height, isHeightAuto : this._height == cocktail.core.style.Dimension.cssAuto};
	}
	,getPositionedHTMLElementData: function() {
		var positionedHTMLElementData = this.getContainerHTMLElementData();
		positionedHTMLElementData.height = this.getComputedHeight();
		return positionedHTMLElementData;
	}
	,getformattingContext: function(previousformattingContext) {
		var formattingContext;
		if(this.establishesNewFormattingContext() == true || previousformattingContext == null) {
			var formattingContextRoot = this._elementRenderer;
			if(this.childrenInline() == true) formattingContext = new cocktail.core.style.formatter.InlineFormattingContext(formattingContextRoot); else formattingContext = new cocktail.core.style.formatter.BlockFormattingContext(formattingContextRoot);
		} else formattingContext = previousformattingContext;
		return formattingContext;
	}
	,isChildInline: function(child) {
		var ret = true;
		if(child.get_nodeType() == 1) {
			var childHTMLElement = child;
			if(childHTMLElement.get_coreStyle().getComputedStyle().display == cocktail.core.style.Display.block) {
				if(childHTMLElement.get_coreStyle().isFloat() == false) ret = false; else if(childHTMLElement.get_coreStyle().isPositioned() == false || childHTMLElement.get_coreStyle().isRelativePositioned() == true) ret = false;
			} else ret = true;
		} else ret = true;
		return ret;
	}
	,getChildLastPositionedHTMLElementData: function(lastPositionedHTMLElementData) {
		var childLastPositionedHTMLElementData;
		if(this.isPositioned() == true) childLastPositionedHTMLElementData = { data : this.getContainerHTMLElementData(), children : new Array()}; else childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
		return childLastPositionedHTMLElementData;
	}
	,isInlineContainer: function() {
		var ret;
		switch( (this._computedStyle.display)[1] ) {
		case 0:
		case 1:
			ret = false;
			break;
		case 2:
			ret = true;
			break;
		default:
			ret = true;
		}
		return ret;
	}
	,getComputedHeight: function() {
		return this._computedStyle.height;
	}
	,__class__: cocktail.core.style.ContainerCoreStyle
});
cocktail.core.style.BodyCoreStyle = $hxClasses["cocktail.core.style.BodyCoreStyle"] = function(htmlElement) {
	cocktail.core.style.ContainerCoreStyle.call(this,htmlElement);
	this._isDirty = false;
};
cocktail.core.style.BodyCoreStyle.__name__ = ["cocktail","core","style","BodyCoreStyle"];
cocktail.core.style.BodyCoreStyle.__super__ = cocktail.core.style.ContainerCoreStyle;
cocktail.core.style.BodyCoreStyle.prototype = $extend(cocktail.core.style.ContainerCoreStyle.prototype,{
	invalidate: function(immediate) {
		if(immediate == null) immediate = false;
		if(this._isDirty == false || immediate == true) {
			this._isDirty = true;
			var htmlDocument = this._htmlElement.get_ownerDocument();
			htmlDocument.invalidate(immediate);
		}
	}
	,createElementRenderer: function(parentElementRenderer) {
		var elementRenderer = new cocktail.core.renderer.InitialBlockRenderer(this);
		elementRenderer.setLayerRenderer(new cocktail.core.renderer.LayerRenderer(elementRenderer));
		return elementRenderer;
	}
	,layout: function() {
		var windowData = this.getWindowData();
		var lastPositionedHTMLElementData = { children : new Array(), data : windowData};
		this.flow(windowData,windowData,lastPositionedHTMLElementData,null,null,null);
	}
	,insertHTMLElement: function(formattingContext,lastPositionedHTMLElementData,viewportData) {
	}
	,positionAbsolutelyPositionedHTMLElementsIfNeeded: function(childLastPositionedHTMLElementData,viewportData) {
		this.doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
	}
	,getPositionedHTMLElementData: function() {
		return this.getWindowData();
	}
	,isInlineLevel: function() {
		return false;
	}
	,isOffsetParent: function() {
		return true;
	}
	,getFirstPositionedAncestor: function() {
		return null;
	}
	,getformattingContext: function(previousformattingContext) {
		return new cocktail.core.style.formatter.BlockFormattingContext(this._elementRenderer);
	}
	,establishesNewFormattingContext: function() {
		return true;
	}
	,__class__: cocktail.core.style.BodyCoreStyle
});
cocktail.core.style.FontSize = $hxClasses["cocktail.core.style.FontSize"] = { __ename__ : ["cocktail","core","style","FontSize"], __constructs__ : ["length","percentage","absoluteSize","relativeSize"] }
cocktail.core.style.FontSize.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.absoluteSize = function(value) { var $x = ["absoluteSize",2,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.relativeSize = function(value) { var $x = ["relativeSize",3,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontWeight = $hxClasses["cocktail.core.style.FontWeight"] = { __ename__ : ["cocktail","core","style","FontWeight"], __constructs__ : ["normal","bold","bolder","lighter","css100","css200","css300","css400","css500","css600","css700","css800","css900"] }
cocktail.core.style.FontWeight.normal = ["normal",0];
cocktail.core.style.FontWeight.normal.toString = $estr;
cocktail.core.style.FontWeight.normal.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.bold = ["bold",1];
cocktail.core.style.FontWeight.bold.toString = $estr;
cocktail.core.style.FontWeight.bold.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.bolder = ["bolder",2];
cocktail.core.style.FontWeight.bolder.toString = $estr;
cocktail.core.style.FontWeight.bolder.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.lighter = ["lighter",3];
cocktail.core.style.FontWeight.lighter.toString = $estr;
cocktail.core.style.FontWeight.lighter.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css100 = ["css100",4];
cocktail.core.style.FontWeight.css100.toString = $estr;
cocktail.core.style.FontWeight.css100.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css200 = ["css200",5];
cocktail.core.style.FontWeight.css200.toString = $estr;
cocktail.core.style.FontWeight.css200.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css300 = ["css300",6];
cocktail.core.style.FontWeight.css300.toString = $estr;
cocktail.core.style.FontWeight.css300.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css400 = ["css400",7];
cocktail.core.style.FontWeight.css400.toString = $estr;
cocktail.core.style.FontWeight.css400.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css500 = ["css500",8];
cocktail.core.style.FontWeight.css500.toString = $estr;
cocktail.core.style.FontWeight.css500.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css600 = ["css600",9];
cocktail.core.style.FontWeight.css600.toString = $estr;
cocktail.core.style.FontWeight.css600.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css700 = ["css700",10];
cocktail.core.style.FontWeight.css700.toString = $estr;
cocktail.core.style.FontWeight.css700.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css800 = ["css800",11];
cocktail.core.style.FontWeight.css800.toString = $estr;
cocktail.core.style.FontWeight.css800.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontWeight.css900 = ["css900",12];
cocktail.core.style.FontWeight.css900.toString = $estr;
cocktail.core.style.FontWeight.css900.__enum__ = cocktail.core.style.FontWeight;
cocktail.core.style.FontStyle = $hxClasses["cocktail.core.style.FontStyle"] = { __ename__ : ["cocktail","core","style","FontStyle"], __constructs__ : ["normal","italic"] }
cocktail.core.style.FontStyle.normal = ["normal",0];
cocktail.core.style.FontStyle.normal.toString = $estr;
cocktail.core.style.FontStyle.normal.__enum__ = cocktail.core.style.FontStyle;
cocktail.core.style.FontStyle.italic = ["italic",1];
cocktail.core.style.FontStyle.italic.toString = $estr;
cocktail.core.style.FontStyle.italic.__enum__ = cocktail.core.style.FontStyle;
cocktail.core.style.FontVariant = $hxClasses["cocktail.core.style.FontVariant"] = { __ename__ : ["cocktail","core","style","FontVariant"], __constructs__ : ["normal","smallCaps"] }
cocktail.core.style.FontVariant.normal = ["normal",0];
cocktail.core.style.FontVariant.normal.toString = $estr;
cocktail.core.style.FontVariant.normal.__enum__ = cocktail.core.style.FontVariant;
cocktail.core.style.FontVariant.smallCaps = ["smallCaps",1];
cocktail.core.style.FontVariant.smallCaps.toString = $estr;
cocktail.core.style.FontVariant.smallCaps.__enum__ = cocktail.core.style.FontVariant;
cocktail.core.style.WhiteSpace = $hxClasses["cocktail.core.style.WhiteSpace"] = { __ename__ : ["cocktail","core","style","WhiteSpace"], __constructs__ : ["normal","pre","nowrap","preWrap","preLine"] }
cocktail.core.style.WhiteSpace.normal = ["normal",0];
cocktail.core.style.WhiteSpace.normal.toString = $estr;
cocktail.core.style.WhiteSpace.normal.__enum__ = cocktail.core.style.WhiteSpace;
cocktail.core.style.WhiteSpace.pre = ["pre",1];
cocktail.core.style.WhiteSpace.pre.toString = $estr;
cocktail.core.style.WhiteSpace.pre.__enum__ = cocktail.core.style.WhiteSpace;
cocktail.core.style.WhiteSpace.nowrap = ["nowrap",2];
cocktail.core.style.WhiteSpace.nowrap.toString = $estr;
cocktail.core.style.WhiteSpace.nowrap.__enum__ = cocktail.core.style.WhiteSpace;
cocktail.core.style.WhiteSpace.preWrap = ["preWrap",3];
cocktail.core.style.WhiteSpace.preWrap.toString = $estr;
cocktail.core.style.WhiteSpace.preWrap.__enum__ = cocktail.core.style.WhiteSpace;
cocktail.core.style.WhiteSpace.preLine = ["preLine",4];
cocktail.core.style.WhiteSpace.preLine.toString = $estr;
cocktail.core.style.WhiteSpace.preLine.__enum__ = cocktail.core.style.WhiteSpace;
cocktail.core.style.LetterSpacing = $hxClasses["cocktail.core.style.LetterSpacing"] = { __ename__ : ["cocktail","core","style","LetterSpacing"], __constructs__ : ["normal","length"] }
cocktail.core.style.LetterSpacing.normal = ["normal",0];
cocktail.core.style.LetterSpacing.normal.toString = $estr;
cocktail.core.style.LetterSpacing.normal.__enum__ = cocktail.core.style.LetterSpacing;
cocktail.core.style.LetterSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.core.style.LetterSpacing; $x.toString = $estr; return $x; }
cocktail.core.style.WordSpacing = $hxClasses["cocktail.core.style.WordSpacing"] = { __ename__ : ["cocktail","core","style","WordSpacing"], __constructs__ : ["normal","length"] }
cocktail.core.style.WordSpacing.normal = ["normal",0];
cocktail.core.style.WordSpacing.normal.toString = $estr;
cocktail.core.style.WordSpacing.normal.__enum__ = cocktail.core.style.WordSpacing;
cocktail.core.style.WordSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.core.style.WordSpacing; $x.toString = $estr; return $x; }
cocktail.core.style.TextIndent = $hxClasses["cocktail.core.style.TextIndent"] = { __ename__ : ["cocktail","core","style","TextIndent"], __constructs__ : ["length","percentage"] }
cocktail.core.style.TextIndent.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.TextIndent; $x.toString = $estr; return $x; }
cocktail.core.style.TextIndent.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.core.style.TextIndent; $x.toString = $estr; return $x; }
cocktail.core.style.TextAlign = $hxClasses["cocktail.core.style.TextAlign"] = { __ename__ : ["cocktail","core","style","TextAlign"], __constructs__ : ["left","right","center","justify"] }
cocktail.core.style.TextAlign.left = ["left",0];
cocktail.core.style.TextAlign.left.toString = $estr;
cocktail.core.style.TextAlign.left.__enum__ = cocktail.core.style.TextAlign;
cocktail.core.style.TextAlign.right = ["right",1];
cocktail.core.style.TextAlign.right.toString = $estr;
cocktail.core.style.TextAlign.right.__enum__ = cocktail.core.style.TextAlign;
cocktail.core.style.TextAlign.center = ["center",2];
cocktail.core.style.TextAlign.center.toString = $estr;
cocktail.core.style.TextAlign.center.__enum__ = cocktail.core.style.TextAlign;
cocktail.core.style.TextAlign.justify = ["justify",3];
cocktail.core.style.TextAlign.justify.toString = $estr;
cocktail.core.style.TextAlign.justify.__enum__ = cocktail.core.style.TextAlign;
cocktail.core.style.TextTransform = $hxClasses["cocktail.core.style.TextTransform"] = { __ename__ : ["cocktail","core","style","TextTransform"], __constructs__ : ["capitalize","uppercase","lowercase","none"] }
cocktail.core.style.TextTransform.capitalize = ["capitalize",0];
cocktail.core.style.TextTransform.capitalize.toString = $estr;
cocktail.core.style.TextTransform.capitalize.__enum__ = cocktail.core.style.TextTransform;
cocktail.core.style.TextTransform.uppercase = ["uppercase",1];
cocktail.core.style.TextTransform.uppercase.toString = $estr;
cocktail.core.style.TextTransform.uppercase.__enum__ = cocktail.core.style.TextTransform;
cocktail.core.style.TextTransform.lowercase = ["lowercase",2];
cocktail.core.style.TextTransform.lowercase.toString = $estr;
cocktail.core.style.TextTransform.lowercase.__enum__ = cocktail.core.style.TextTransform;
cocktail.core.style.TextTransform.none = ["none",3];
cocktail.core.style.TextTransform.none.toString = $estr;
cocktail.core.style.TextTransform.none.__enum__ = cocktail.core.style.TextTransform;
cocktail.core.style.LineHeight = $hxClasses["cocktail.core.style.LineHeight"] = { __ename__ : ["cocktail","core","style","LineHeight"], __constructs__ : ["normal","number","length","percentage"] }
cocktail.core.style.LineHeight.normal = ["normal",0];
cocktail.core.style.LineHeight.normal.toString = $estr;
cocktail.core.style.LineHeight.normal.__enum__ = cocktail.core.style.LineHeight;
cocktail.core.style.LineHeight.number = function(value) { var $x = ["number",1,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.LineHeight.length = function(value) { var $x = ["length",2,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.LineHeight.percentage = function(value) { var $x = ["percentage",3,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.VerticalAlign = $hxClasses["cocktail.core.style.VerticalAlign"] = { __ename__ : ["cocktail","core","style","VerticalAlign"], __constructs__ : ["baseline","sub","cssSuper","top","textTop","middle","bottom","textBottom","percent","length"] }
cocktail.core.style.VerticalAlign.baseline = ["baseline",0];
cocktail.core.style.VerticalAlign.baseline.toString = $estr;
cocktail.core.style.VerticalAlign.baseline.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.sub = ["sub",1];
cocktail.core.style.VerticalAlign.sub.toString = $estr;
cocktail.core.style.VerticalAlign.sub.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.cssSuper = ["cssSuper",2];
cocktail.core.style.VerticalAlign.cssSuper.toString = $estr;
cocktail.core.style.VerticalAlign.cssSuper.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.top = ["top",3];
cocktail.core.style.VerticalAlign.top.toString = $estr;
cocktail.core.style.VerticalAlign.top.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.textTop = ["textTop",4];
cocktail.core.style.VerticalAlign.textTop.toString = $estr;
cocktail.core.style.VerticalAlign.textTop.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.middle = ["middle",5];
cocktail.core.style.VerticalAlign.middle.toString = $estr;
cocktail.core.style.VerticalAlign.middle.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.bottom = ["bottom",6];
cocktail.core.style.VerticalAlign.bottom.toString = $estr;
cocktail.core.style.VerticalAlign.bottom.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.textBottom = ["textBottom",7];
cocktail.core.style.VerticalAlign.textBottom.toString = $estr;
cocktail.core.style.VerticalAlign.textBottom.__enum__ = cocktail.core.style.VerticalAlign;
cocktail.core.style.VerticalAlign.percent = function(value) { var $x = ["percent",8,value]; $x.__enum__ = cocktail.core.style.VerticalAlign; $x.toString = $estr; return $x; }
cocktail.core.style.VerticalAlign.length = function(value) { var $x = ["length",9,value]; $x.__enum__ = cocktail.core.style.VerticalAlign; $x.toString = $estr; return $x; }
cocktail.core.style.Margin = $hxClasses["cocktail.core.style.Margin"] = { __ename__ : ["cocktail","core","style","Margin"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.Margin.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Margin; $x.toString = $estr; return $x; }
cocktail.core.style.Margin.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Margin; $x.toString = $estr; return $x; }
cocktail.core.style.Margin.cssAuto = ["cssAuto",2];
cocktail.core.style.Margin.cssAuto.toString = $estr;
cocktail.core.style.Margin.cssAuto.__enum__ = cocktail.core.style.Margin;
cocktail.core.style.Padding = $hxClasses["cocktail.core.style.Padding"] = { __ename__ : ["cocktail","core","style","Padding"], __constructs__ : ["length","percent"] }
cocktail.core.style.Padding.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Padding; $x.toString = $estr; return $x; }
cocktail.core.style.Padding.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Padding; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension = $hxClasses["cocktail.core.style.Dimension"] = { __ename__ : ["cocktail","core","style","Dimension"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.Dimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Dimension; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Dimension; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension.cssAuto = ["cssAuto",2];
cocktail.core.style.Dimension.cssAuto.toString = $estr;
cocktail.core.style.Dimension.cssAuto.__enum__ = cocktail.core.style.Dimension;
cocktail.core.style.ConstrainedDimension = $hxClasses["cocktail.core.style.ConstrainedDimension"] = { __ename__ : ["cocktail","core","style","ConstrainedDimension"], __constructs__ : ["length","percent","none"] }
cocktail.core.style.ConstrainedDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
cocktail.core.style.ConstrainedDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
cocktail.core.style.ConstrainedDimension.none = ["none",2];
cocktail.core.style.ConstrainedDimension.none.toString = $estr;
cocktail.core.style.ConstrainedDimension.none.__enum__ = cocktail.core.style.ConstrainedDimension;
cocktail.core.style.Display = $hxClasses["cocktail.core.style.Display"] = { __ename__ : ["cocktail","core","style","Display"], __constructs__ : ["block","inlineBlock","cssInline","none"] }
cocktail.core.style.Display.block = ["block",0];
cocktail.core.style.Display.block.toString = $estr;
cocktail.core.style.Display.block.__enum__ = cocktail.core.style.Display;
cocktail.core.style.Display.inlineBlock = ["inlineBlock",1];
cocktail.core.style.Display.inlineBlock.toString = $estr;
cocktail.core.style.Display.inlineBlock.__enum__ = cocktail.core.style.Display;
cocktail.core.style.Display.cssInline = ["cssInline",2];
cocktail.core.style.Display.cssInline.toString = $estr;
cocktail.core.style.Display.cssInline.__enum__ = cocktail.core.style.Display;
cocktail.core.style.Display.none = ["none",3];
cocktail.core.style.Display.none.toString = $estr;
cocktail.core.style.Display.none.__enum__ = cocktail.core.style.Display;
cocktail.core.style.CSSFloat = $hxClasses["cocktail.core.style.CSSFloat"] = { __ename__ : ["cocktail","core","style","CSSFloat"], __constructs__ : ["left","right","none"] }
cocktail.core.style.CSSFloat.left = ["left",0];
cocktail.core.style.CSSFloat.left.toString = $estr;
cocktail.core.style.CSSFloat.left.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.CSSFloat.right = ["right",1];
cocktail.core.style.CSSFloat.right.toString = $estr;
cocktail.core.style.CSSFloat.right.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.CSSFloat.none = ["none",2];
cocktail.core.style.CSSFloat.none.toString = $estr;
cocktail.core.style.CSSFloat.none.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.Clear = $hxClasses["cocktail.core.style.Clear"] = { __ename__ : ["cocktail","core","style","Clear"], __constructs__ : ["none","left","right","both"] }
cocktail.core.style.Clear.none = ["none",0];
cocktail.core.style.Clear.none.toString = $estr;
cocktail.core.style.Clear.none.__enum__ = cocktail.core.style.Clear;
cocktail.core.style.Clear.left = ["left",1];
cocktail.core.style.Clear.left.toString = $estr;
cocktail.core.style.Clear.left.__enum__ = cocktail.core.style.Clear;
cocktail.core.style.Clear.right = ["right",2];
cocktail.core.style.Clear.right.toString = $estr;
cocktail.core.style.Clear.right.__enum__ = cocktail.core.style.Clear;
cocktail.core.style.Clear.both = ["both",3];
cocktail.core.style.Clear.both.toString = $estr;
cocktail.core.style.Clear.both.__enum__ = cocktail.core.style.Clear;
cocktail.core.style.Position = $hxClasses["cocktail.core.style.Position"] = { __ename__ : ["cocktail","core","style","Position"], __constructs__ : ["cssStatic","relative","absolute","fixed"] }
cocktail.core.style.Position.cssStatic = ["cssStatic",0];
cocktail.core.style.Position.cssStatic.toString = $estr;
cocktail.core.style.Position.cssStatic.__enum__ = cocktail.core.style.Position;
cocktail.core.style.Position.relative = ["relative",1];
cocktail.core.style.Position.relative.toString = $estr;
cocktail.core.style.Position.relative.__enum__ = cocktail.core.style.Position;
cocktail.core.style.Position.absolute = ["absolute",2];
cocktail.core.style.Position.absolute.toString = $estr;
cocktail.core.style.Position.absolute.__enum__ = cocktail.core.style.Position;
cocktail.core.style.Position.fixed = ["fixed",3];
cocktail.core.style.Position.fixed.toString = $estr;
cocktail.core.style.Position.fixed.__enum__ = cocktail.core.style.Position;
cocktail.core.style.PositionOffset = $hxClasses["cocktail.core.style.PositionOffset"] = { __ename__ : ["cocktail","core","style","PositionOffset"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.PositionOffset.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.PositionOffset; $x.toString = $estr; return $x; }
cocktail.core.style.PositionOffset.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.PositionOffset; $x.toString = $estr; return $x; }
cocktail.core.style.PositionOffset.cssAuto = ["cssAuto",2];
cocktail.core.style.PositionOffset.cssAuto.toString = $estr;
cocktail.core.style.PositionOffset.cssAuto.__enum__ = cocktail.core.style.PositionOffset;
cocktail.core.style.Overflow = $hxClasses["cocktail.core.style.Overflow"] = { __ename__ : ["cocktail","core","style","Overflow"], __constructs__ : ["visible","hidden","scroll","cssAuto"] }
cocktail.core.style.Overflow.visible = ["visible",0];
cocktail.core.style.Overflow.visible.toString = $estr;
cocktail.core.style.Overflow.visible.__enum__ = cocktail.core.style.Overflow;
cocktail.core.style.Overflow.hidden = ["hidden",1];
cocktail.core.style.Overflow.hidden.toString = $estr;
cocktail.core.style.Overflow.hidden.__enum__ = cocktail.core.style.Overflow;
cocktail.core.style.Overflow.scroll = ["scroll",2];
cocktail.core.style.Overflow.scroll.toString = $estr;
cocktail.core.style.Overflow.scroll.__enum__ = cocktail.core.style.Overflow;
cocktail.core.style.Overflow.cssAuto = ["cssAuto",3];
cocktail.core.style.Overflow.cssAuto.toString = $estr;
cocktail.core.style.Overflow.cssAuto.__enum__ = cocktail.core.style.Overflow;
cocktail.core.style.Visibility = $hxClasses["cocktail.core.style.Visibility"] = { __ename__ : ["cocktail","core","style","Visibility"], __constructs__ : ["visible","hidden"] }
cocktail.core.style.Visibility.visible = ["visible",0];
cocktail.core.style.Visibility.visible.toString = $estr;
cocktail.core.style.Visibility.visible.__enum__ = cocktail.core.style.Visibility;
cocktail.core.style.Visibility.hidden = ["hidden",1];
cocktail.core.style.Visibility.hidden.toString = $estr;
cocktail.core.style.Visibility.hidden.__enum__ = cocktail.core.style.Visibility;
cocktail.core.style.Transform = $hxClasses["cocktail.core.style.Transform"] = { __ename__ : ["cocktail","core","style","Transform"], __constructs__ : ["none","transformFunctions"] }
cocktail.core.style.Transform.none = ["none",0];
cocktail.core.style.Transform.none.toString = $estr;
cocktail.core.style.Transform.none.__enum__ = cocktail.core.style.Transform;
cocktail.core.style.Transform.transformFunctions = function(transformFunctions) { var $x = ["transformFunctions",1,transformFunctions]; $x.__enum__ = cocktail.core.style.Transform; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction = $hxClasses["cocktail.core.style.TransformFunction"] = { __ename__ : ["cocktail","core","style","TransformFunction"], __constructs__ : ["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","skew"] }
cocktail.core.style.TransformFunction.matrix = function(data) { var $x = ["matrix",0,data]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.translate = function(tx,ty) { var $x = ["translate",1,tx,ty]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.translateX = function(tx) { var $x = ["translateX",2,tx]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.translateY = function(ty) { var $x = ["translateY",3,ty]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.scale = function(sx,sy) { var $x = ["scale",4,sx,sy]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.scaleX = function(sx) { var $x = ["scaleX",5,sx]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.scaleY = function(sy) { var $x = ["scaleY",6,sy]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.rotate = function(angle) { var $x = ["rotate",7,angle]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.skewX = function(angle) { var $x = ["skewX",8,angle]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.skewY = function(angle) { var $x = ["skewY",9,angle]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction.skew = function(angleX,angleY) { var $x = ["skew",10,angleX,angleY]; $x.__enum__ = cocktail.core.style.TransformFunction; $x.toString = $estr; return $x; }
cocktail.core.style.Translation = $hxClasses["cocktail.core.style.Translation"] = { __ename__ : ["cocktail","core","style","Translation"], __constructs__ : ["length","percent"] }
cocktail.core.style.Translation.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Translation; $x.toString = $estr; return $x; }
cocktail.core.style.Translation.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Translation; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginX = $hxClasses["cocktail.core.style.TransformOriginX"] = { __ename__ : ["cocktail","core","style","TransformOriginX"], __constructs__ : ["length","percent","left","center","right"] }
cocktail.core.style.TransformOriginX.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.TransformOriginX; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginX.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.TransformOriginX; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginX.left = ["left",2];
cocktail.core.style.TransformOriginX.left.toString = $estr;
cocktail.core.style.TransformOriginX.left.__enum__ = cocktail.core.style.TransformOriginX;
cocktail.core.style.TransformOriginX.center = ["center",3];
cocktail.core.style.TransformOriginX.center.toString = $estr;
cocktail.core.style.TransformOriginX.center.__enum__ = cocktail.core.style.TransformOriginX;
cocktail.core.style.TransformOriginX.right = ["right",4];
cocktail.core.style.TransformOriginX.right.toString = $estr;
cocktail.core.style.TransformOriginX.right.__enum__ = cocktail.core.style.TransformOriginX;
cocktail.core.style.TransformOriginY = $hxClasses["cocktail.core.style.TransformOriginY"] = { __ename__ : ["cocktail","core","style","TransformOriginY"], __constructs__ : ["length","percent","top","center","bottom"] }
cocktail.core.style.TransformOriginY.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.TransformOriginY; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginY.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.TransformOriginY; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginY.top = ["top",2];
cocktail.core.style.TransformOriginY.top.toString = $estr;
cocktail.core.style.TransformOriginY.top.__enum__ = cocktail.core.style.TransformOriginY;
cocktail.core.style.TransformOriginY.center = ["center",3];
cocktail.core.style.TransformOriginY.center.toString = $estr;
cocktail.core.style.TransformOriginY.center.__enum__ = cocktail.core.style.TransformOriginY;
cocktail.core.style.TransformOriginY.bottom = ["bottom",4];
cocktail.core.style.TransformOriginY.bottom.toString = $estr;
cocktail.core.style.TransformOriginY.bottom.__enum__ = cocktail.core.style.TransformOriginY;
cocktail.core.style.BackgroundImage = $hxClasses["cocktail.core.style.BackgroundImage"] = { __ename__ : ["cocktail","core","style","BackgroundImage"], __constructs__ : ["none","image"] }
cocktail.core.style.BackgroundImage.none = ["none",0];
cocktail.core.style.BackgroundImage.none.toString = $estr;
cocktail.core.style.BackgroundImage.none.__enum__ = cocktail.core.style.BackgroundImage;
cocktail.core.style.BackgroundImage.image = function(value) { var $x = ["image",1,value]; $x.__enum__ = cocktail.core.style.BackgroundImage; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundRepeatValue = $hxClasses["cocktail.core.style.BackgroundRepeatValue"] = { __ename__ : ["cocktail","core","style","BackgroundRepeatValue"], __constructs__ : ["repeat","space","round","noRepeat"] }
cocktail.core.style.BackgroundRepeatValue.repeat = ["repeat",0];
cocktail.core.style.BackgroundRepeatValue.repeat.toString = $estr;
cocktail.core.style.BackgroundRepeatValue.repeat.__enum__ = cocktail.core.style.BackgroundRepeatValue;
cocktail.core.style.BackgroundRepeatValue.space = ["space",1];
cocktail.core.style.BackgroundRepeatValue.space.toString = $estr;
cocktail.core.style.BackgroundRepeatValue.space.__enum__ = cocktail.core.style.BackgroundRepeatValue;
cocktail.core.style.BackgroundRepeatValue.round = ["round",2];
cocktail.core.style.BackgroundRepeatValue.round.toString = $estr;
cocktail.core.style.BackgroundRepeatValue.round.__enum__ = cocktail.core.style.BackgroundRepeatValue;
cocktail.core.style.BackgroundRepeatValue.noRepeat = ["noRepeat",3];
cocktail.core.style.BackgroundRepeatValue.noRepeat.toString = $estr;
cocktail.core.style.BackgroundRepeatValue.noRepeat.__enum__ = cocktail.core.style.BackgroundRepeatValue;
cocktail.core.style.BackgroundPositionX = $hxClasses["cocktail.core.style.BackgroundPositionX"] = { __ename__ : ["cocktail","core","style","BackgroundPositionX"], __constructs__ : ["length","percent","left","center","right"] }
cocktail.core.style.BackgroundPositionX.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.BackgroundPositionX; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundPositionX.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.BackgroundPositionX; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundPositionX.left = ["left",2];
cocktail.core.style.BackgroundPositionX.left.toString = $estr;
cocktail.core.style.BackgroundPositionX.left.__enum__ = cocktail.core.style.BackgroundPositionX;
cocktail.core.style.BackgroundPositionX.center = ["center",3];
cocktail.core.style.BackgroundPositionX.center.toString = $estr;
cocktail.core.style.BackgroundPositionX.center.__enum__ = cocktail.core.style.BackgroundPositionX;
cocktail.core.style.BackgroundPositionX.right = ["right",4];
cocktail.core.style.BackgroundPositionX.right.toString = $estr;
cocktail.core.style.BackgroundPositionX.right.__enum__ = cocktail.core.style.BackgroundPositionX;
cocktail.core.style.BackgroundPositionY = $hxClasses["cocktail.core.style.BackgroundPositionY"] = { __ename__ : ["cocktail","core","style","BackgroundPositionY"], __constructs__ : ["length","percent","top","center","bottom"] }
cocktail.core.style.BackgroundPositionY.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.BackgroundPositionY; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundPositionY.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.BackgroundPositionY; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundPositionY.top = ["top",2];
cocktail.core.style.BackgroundPositionY.top.toString = $estr;
cocktail.core.style.BackgroundPositionY.top.__enum__ = cocktail.core.style.BackgroundPositionY;
cocktail.core.style.BackgroundPositionY.center = ["center",3];
cocktail.core.style.BackgroundPositionY.center.toString = $estr;
cocktail.core.style.BackgroundPositionY.center.__enum__ = cocktail.core.style.BackgroundPositionY;
cocktail.core.style.BackgroundPositionY.bottom = ["bottom",4];
cocktail.core.style.BackgroundPositionY.bottom.toString = $estr;
cocktail.core.style.BackgroundPositionY.bottom.__enum__ = cocktail.core.style.BackgroundPositionY;
cocktail.core.style.BackgroundClip = $hxClasses["cocktail.core.style.BackgroundClip"] = { __ename__ : ["cocktail","core","style","BackgroundClip"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.core.style.BackgroundClip.borderBox = ["borderBox",0];
cocktail.core.style.BackgroundClip.borderBox.toString = $estr;
cocktail.core.style.BackgroundClip.borderBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundClip.paddingBox = ["paddingBox",1];
cocktail.core.style.BackgroundClip.paddingBox.toString = $estr;
cocktail.core.style.BackgroundClip.paddingBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundClip.contentBox = ["contentBox",2];
cocktail.core.style.BackgroundClip.contentBox.toString = $estr;
cocktail.core.style.BackgroundClip.contentBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundOrigin = $hxClasses["cocktail.core.style.BackgroundOrigin"] = { __ename__ : ["cocktail","core","style","BackgroundOrigin"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.core.style.BackgroundOrigin.borderBox = ["borderBox",0];
cocktail.core.style.BackgroundOrigin.borderBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.borderBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundOrigin.paddingBox = ["paddingBox",1];
cocktail.core.style.BackgroundOrigin.paddingBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.paddingBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundOrigin.contentBox = ["contentBox",2];
cocktail.core.style.BackgroundOrigin.contentBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.contentBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundSize = $hxClasses["cocktail.core.style.BackgroundSize"] = { __ename__ : ["cocktail","core","style","BackgroundSize"], __constructs__ : ["contain","cover","dimensions"] }
cocktail.core.style.BackgroundSize.contain = ["contain",0];
cocktail.core.style.BackgroundSize.contain.toString = $estr;
cocktail.core.style.BackgroundSize.contain.__enum__ = cocktail.core.style.BackgroundSize;
cocktail.core.style.BackgroundSize.cover = ["cover",1];
cocktail.core.style.BackgroundSize.cover.toString = $estr;
cocktail.core.style.BackgroundSize.cover.__enum__ = cocktail.core.style.BackgroundSize;
cocktail.core.style.BackgroundSize.dimensions = function(value) { var $x = ["dimensions",2,value]; $x.__enum__ = cocktail.core.style.BackgroundSize; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension = $hxClasses["cocktail.core.style.BackgroundSizeDimension"] = { __ename__ : ["cocktail","core","style","BackgroundSizeDimension"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.BackgroundSizeDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension.cssAuto = ["cssAuto",2];
cocktail.core.style.BackgroundSizeDimension.cssAuto.toString = $estr;
cocktail.core.style.BackgroundSizeDimension.cssAuto.__enum__ = cocktail.core.style.BackgroundSizeDimension;
cocktail.core.style.Cursor = $hxClasses["cocktail.core.style.Cursor"] = { __ename__ : ["cocktail","core","style","Cursor"], __constructs__ : ["cssAuto","crosshair","cssDefault","pointer"] }
cocktail.core.style.Cursor.cssAuto = ["cssAuto",0];
cocktail.core.style.Cursor.cssAuto.toString = $estr;
cocktail.core.style.Cursor.cssAuto.__enum__ = cocktail.core.style.Cursor;
cocktail.core.style.Cursor.crosshair = ["crosshair",1];
cocktail.core.style.Cursor.crosshair.toString = $estr;
cocktail.core.style.Cursor.crosshair.__enum__ = cocktail.core.style.Cursor;
cocktail.core.style.Cursor.cssDefault = ["cssDefault",2];
cocktail.core.style.Cursor.cssDefault.toString = $estr;
cocktail.core.style.Cursor.cssDefault.__enum__ = cocktail.core.style.Cursor;
cocktail.core.style.Cursor.pointer = ["pointer",3];
cocktail.core.style.Cursor.pointer.toString = $estr;
cocktail.core.style.Cursor.pointer.__enum__ = cocktail.core.style.Cursor;
if(!cocktail.core.style.adapter) cocktail.core.style.adapter = {}
cocktail.core.style.adapter.AbstractStyle = $hxClasses["cocktail.core.style.adapter.AbstractStyle"] = function(coreStyle) {
	this._coreStyle = coreStyle;
};
cocktail.core.style.adapter.AbstractStyle.__name__ = ["cocktail","core","style","adapter","AbstractStyle"];
cocktail.core.style.adapter.AbstractStyle.prototype = {
	display: null
	,position: null
	,cssFloat: null
	,clear: null
	,marginLeft: null
	,marginRight: null
	,marginTop: null
	,marginBottom: null
	,paddingLeft: null
	,paddingRight: null
	,paddingTop: null
	,paddingBottom: null
	,width: null
	,height: null
	,minHeight: null
	,maxHeight: null
	,minWidth: null
	,maxWidth: null
	,top: null
	,left: null
	,bottom: null
	,right: null
	,backgroundColor: null
	,backgroundImage: null
	,backgroundRepeat: null
	,backgroundOrigin: null
	,backgroundSize: null
	,backgroundPosition: null
	,backgroundClip: null
	,fontSize: null
	,fontWeight: null
	,fontStyle: null
	,fontFamily: null
	,fontVariant: null
	,color: null
	,lineHeight: null
	,textTransform: null
	,letterSpacing: null
	,wordSpacing: null
	,whiteSpace: null
	,textAlign: null
	,textIndent: null
	,verticalAlign: null
	,opacity: null
	,visibility: null
	,overflowX: null
	,overflowY: null
	,cursor: null
	,_coreStyle: null
	,get_opacity: function() {
		return cocktail.core.unit.UnitManager.getCSSOpacity(this._coreStyle.getOpacity());
	}
	,set_opacity: function(value) {
		this._coreStyle.setOpacity(Std.parseFloat(value));
		return value;
	}
	,get_visibility: function() {
		return cocktail.core.unit.UnitManager.getCSSVisibility(this._coreStyle.getVisibility());
	}
	,set_visibility: function(value) {
		this._coreStyle.setVisibility(cocktail.core.unit.UnitManager.visibilityEnum(value));
		return value;
	}
	,get_marginLeft: function() {
		return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginLeft());
	}
	,set_marginLeft: function(value) {
		this._coreStyle.setMarginLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
		return value;
	}
	,get_marginRight: function() {
		return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginRight());
	}
	,set_marginRight: function(value) {
		this._coreStyle.setMarginRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
		return value;
	}
	,get_marginTop: function() {
		return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginTop());
	}
	,set_marginTop: function(value) {
		this._coreStyle.setMarginTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
		return value;
	}
	,get_marginBottom: function() {
		return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginBottom());
	}
	,set_marginBottom: function(value) {
		this._coreStyle.setMarginBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
		return value;
	}
	,get_paddingLeft: function() {
		return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingLeft());
	}
	,set_paddingLeft: function(value) {
		this._coreStyle.setPaddingLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
		return value;
	}
	,get_paddingRight: function() {
		return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingRight());
	}
	,set_paddingRight: function(value) {
		this._coreStyle.setPaddingRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
		return value;
	}
	,get_paddingTop: function() {
		return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingTop());
	}
	,set_paddingTop: function(value) {
		this._coreStyle.setPaddingTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
		return value;
	}
	,get_paddingBottom: function() {
		return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingBottom());
	}
	,set_paddingBottom: function(value) {
		this._coreStyle.setPaddingBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
		return value;
	}
	,get_display: function() {
		return cocktail.core.unit.UnitManager.getCSSDisplay(this._coreStyle.getDisplay());
	}
	,set_display: function(value) {
		this._coreStyle.setDisplay(cocktail.core.unit.UnitManager.displayEnum(value));
		return value;
	}
	,get_position: function() {
		return cocktail.core.unit.UnitManager.getCSSPosition(this._coreStyle.getPosition());
	}
	,set_position: function(value) {
		this._coreStyle.setPosition(cocktail.core.unit.UnitManager.positionEnum(value));
		return value;
	}
	,get_width: function() {
		return cocktail.core.unit.UnitManager.getCSSDimension(this._coreStyle.getWidth());
	}
	,set_width: function(value) {
		this._coreStyle.setWidth(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Dimension,value));
		return value;
	}
	,get_height: function() {
		return cocktail.core.unit.UnitManager.getCSSDimension(this._coreStyle.getHeight());
	}
	,set_height: function(value) {
		this._coreStyle.setHeight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Dimension,value));
		return value;
	}
	,get_minHeight: function() {
		return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMinHeight());
	}
	,set_minHeight: function(value) {
		this._coreStyle.setMinHeight(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
		return value;
	}
	,get_maxHeight: function() {
		return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMaxHeight());
	}
	,set_maxHeight: function(value) {
		this._coreStyle.setMaxHeight(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
		return value;
	}
	,get_minWidth: function() {
		return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMinWidth());
	}
	,set_minWidth: function(value) {
		this._coreStyle.setMinWidth(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
		return value;
	}
	,get_maxWidth: function() {
		return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMaxWidth());
	}
	,set_maxWidth: function(value) {
		this._coreStyle.setMaxWidth(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
		return value;
	}
	,get_top: function() {
		return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getTop());
	}
	,set_top: function(value) {
		this._coreStyle.setTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
		return value;
	}
	,get_left: function() {
		return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getLeft());
	}
	,set_left: function(value) {
		this._coreStyle.setLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
		return value;
	}
	,get_bottom: function() {
		return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getBottom());
	}
	,set_bottom: function(value) {
		this._coreStyle.setBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
		return value;
	}
	,get_right: function() {
		return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getRight());
	}
	,set_right: function(value) {
		this._coreStyle.setRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
		return value;
	}
	,get_CSSFloat: function() {
		return cocktail.core.unit.UnitManager.getCSSFloatAsString(this._coreStyle.getCSSFloat());
	}
	,set_CSSFloat: function(value) {
		this._coreStyle.setCSSFloat(cocktail.core.unit.UnitManager.cssFloatEnum(value));
		return value;
	}
	,get_clear: function() {
		return cocktail.core.unit.UnitManager.getCSSClear(this._coreStyle.getClear());
	}
	,set_clear: function(value) {
		this._coreStyle.setClear(cocktail.core.unit.UnitManager.clearEnum(value));
		return value;
	}
	,get_fontSize: function() {
		return cocktail.core.unit.UnitManager.getCSSFontSize(this._coreStyle.getFontSize());
	}
	,set_fontSize: function(value) {
		return value;
	}
	,get_fontWeight: function() {
		return cocktail.core.unit.UnitManager.getCSSFontWeight(this._coreStyle.getFontWeight());
	}
	,set_fontWeight: function(value) {
		this._coreStyle.setFontWeight(cocktail.core.unit.UnitManager.fontWeightEnum(value));
		return value;
	}
	,get_fontStyle: function() {
		return cocktail.core.unit.UnitManager.getCSSFontStyle(this._coreStyle.getFontStyle());
	}
	,set_fontStyle: function(value) {
		this._coreStyle.setFontStyle(cocktail.core.unit.UnitManager.fontStyleEnum(value));
		return value;
	}
	,get_fontFamily: function() {
		return cocktail.core.unit.UnitManager.getCSSFontFamily(this._coreStyle.getFontFamily());
	}
	,set_fontFamily: function(value) {
		this._coreStyle.setFontFamily(cocktail.core.unit.UnitManager.fontFamilyEnum(value));
		return value;
	}
	,get_fontVariant: function() {
		return cocktail.core.unit.UnitManager.getCSSFontVariant(this._coreStyle.getFontVariant());
	}
	,set_fontVariant: function(value) {
		this._coreStyle.setFontVariant(cocktail.core.unit.UnitManager.fontVariantEnum(value));
		return value;
	}
	,get_textTransform: function() {
		return cocktail.core.unit.UnitManager.getCSSTextTransform(this._coreStyle.getTextTransform());
	}
	,set_textTransform: function(value) {
		this._coreStyle.setTextTransform(cocktail.core.unit.UnitManager.textTransformEnum(value));
		return value;
	}
	,get_letterSpacing: function() {
		return cocktail.core.unit.UnitManager.getCSSLetterSpacing(this._coreStyle.getLetterSpacing());
	}
	,set_letterSpacing: function(value) {
		this._coreStyle.setLetterSpacing(cocktail.core.unit.UnitManager.letterSpacingEnum(value));
		return value;
	}
	,get_color: function() {
		return cocktail.core.unit.UnitManager.getCSSColor(this._coreStyle.getColor());
	}
	,set_color: function(value) {
		this._coreStyle.setColor(cocktail.core.unit.UnitManager.colorEnum(value));
		return value;
	}
	,get_wordSpacing: function() {
		return cocktail.core.unit.UnitManager.getCSSWordSpacing(this._coreStyle.getWordSpacing());
	}
	,set_wordSpacing: function(value) {
		this._coreStyle.setWordSpacing(cocktail.core.unit.UnitManager.wordSpacingEnum(value));
		return value;
	}
	,get_lineHeight: function() {
		return cocktail.core.unit.UnitManager.getCSSLineHeight(this._coreStyle.getLineHeight());
	}
	,set_lineHeight: function(value) {
		this._coreStyle.setLineHeight(cocktail.core.unit.UnitManager.lineHeightEnum(value));
		return value;
	}
	,get_verticalAlign: function() {
		return cocktail.core.unit.UnitManager.getCSSVerticalAlign(this._coreStyle.getVerticalAlign());
	}
	,set_verticalAlign: function(value) {
		this._coreStyle.setVerticalAlign(cocktail.core.unit.UnitManager.verticalAlignEnum(value));
		return value;
	}
	,get_textIndent: function() {
		return cocktail.core.unit.UnitManager.getCSSTextIndent(this._coreStyle.getTextIndent());
	}
	,set_textIndent: function(value) {
		this._coreStyle.setTextIndent(cocktail.core.unit.UnitManager.textIndentEnum(value));
		return value;
	}
	,get_whiteSpace: function() {
		return cocktail.core.unit.UnitManager.getCSSWhiteSpace(this._coreStyle.getWhiteSpace());
	}
	,set_whiteSpace: function(value) {
		this._coreStyle.setWhiteSpace(cocktail.core.unit.UnitManager.whiteSpaceEnum(value));
		return value;
	}
	,get_textAlign: function() {
		return cocktail.core.unit.UnitManager.getCSSTextAlign(this._coreStyle.getTextAlign());
	}
	,set_textAlign: function(value) {
		this._coreStyle.setTextAlign(cocktail.core.unit.UnitManager.textAlignEnum(value));
		return value;
	}
	,set_backgroundColor: function(value) {
		this._coreStyle.setBackgroundColor(cocktail.core.unit.UnitManager.colorEnum(value));
		return value;
	}
	,get_backgroundColor: function() {
		return cocktail.core.unit.UnitManager.getCSSColor(this._coreStyle.getBackgroundColor());
	}
	,set_backgroundImage: function(value) {
		this._coreStyle.setBackgroundImage(cocktail.core.unit.UnitManager.backgroundImageEnum(value));
		return value;
	}
	,get_backgroundImage: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundImage(this._coreStyle.getBackgroundImage());
	}
	,set_backgroundRepeat: function(value) {
		this._coreStyle.setBackgroundRepeat(cocktail.core.unit.UnitManager.backgroundRepeatEnum(value));
		return value;
	}
	,get_backgroundRepeat: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundRepeat(this._coreStyle.getBackgroundRepeat());
	}
	,set_backgroundSize: function(value) {
		this._coreStyle.setBackgroundSize(cocktail.core.unit.UnitManager.backgroundSizeEnum(value));
		return value;
	}
	,get_backgroundSize: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundSize(this._coreStyle.getBackgroundSize());
	}
	,set_backgroundClip: function(value) {
		this._coreStyle.setBackgroundClip(cocktail.core.unit.UnitManager.backgroundClipEnum(value));
		return value;
	}
	,get_backgroundClip: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundClip(this._coreStyle.getBackgroundClip());
	}
	,set_backgroundPosition: function(value) {
		this._coreStyle.setBackgroundPosition(cocktail.core.unit.UnitManager.backgroundPositionEnum(value));
		return value;
	}
	,get_backgroundPosition: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundPosition(this._coreStyle.getBackgroundPosition());
	}
	,set_backgroundOrigin: function(value) {
		this._coreStyle.setBackgroundOrigin(cocktail.core.unit.UnitManager.backgroundOriginEnum(value));
		return value;
	}
	,get_backgroundOrigin: function() {
		return cocktail.core.unit.UnitManager.getCSSBackgroundOrigin(this._coreStyle.getBackgroundOrigin());
	}
	,get_overflowX: function() {
		return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowX());
	}
	,set_overflowX: function(value) {
		this._coreStyle.setOverflowX(cocktail.core.unit.UnitManager.overflowEnum(value));
		return value;
	}
	,get_overflowY: function() {
		return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowY());
	}
	,set_overflowY: function(value) {
		this._coreStyle.setOverflowY(cocktail.core.unit.UnitManager.overflowEnum(value));
		return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowY());
	}
	,set_cursor: function(value) {
		this._coreStyle.setCursor(cocktail.core.unit.UnitManager.cursorEnum(value));
		return value;
	}
	,get_cursor: function() {
		return cocktail.core.unit.UnitManager.getCSSCursor(this._coreStyle.getCursor());
	}
	,__class__: cocktail.core.style.adapter.AbstractStyle
	,__properties__: {set_cursor:"set_cursor",get_cursor:"get_cursor",set_overflowY:"set_overflowY",get_overflowY:"get_overflowY",set_overflowX:"set_overflowX",get_overflowX:"get_overflowX",set_visibility:"set_visibility",get_visibility:"get_visibility",set_opacity:"set_opacity",get_opacity:"get_opacity",set_verticalAlign:"set_verticalAlign",get_verticalAlign:"get_verticalAlign",set_textIndent:"set_textIndent",get_textIndent:"get_textIndent",set_textAlign:"set_textAlign",get_textAlign:"get_textAlign",set_whiteSpace:"set_whiteSpace",get_whiteSpace:"get_whiteSpace",set_wordSpacing:"set_wordSpacing",get_wordSpacing:"get_wordSpacing",set_letterSpacing:"set_letterSpacing",get_letterSpacing:"get_letterSpacing",set_textTransform:"set_textTransform",get_textTransform:"get_textTransform",set_lineHeight:"set_lineHeight",get_lineHeight:"get_lineHeight",set_color:"set_color",get_color:"get_color",set_fontVariant:"set_fontVariant",get_fontVariant:"get_fontVariant",set_fontFamily:"set_fontFamily",get_fontFamily:"get_fontFamily",set_fontStyle:"set_fontStyle",get_fontStyle:"get_fontStyle",set_fontWeight:"set_fontWeight",get_fontWeight:"get_fontWeight",set_fontSize:"set_fontSize",get_fontSize:"get_fontSize",set_backgroundClip:"set_backgroundClip",get_backgroundClip:"get_backgroundClip",set_backgroundPosition:"set_backgroundPosition",get_backgroundPosition:"get_backgroundPosition",set_backgroundSize:"set_backgroundSize",get_backgroundSize:"get_backgroundSize",set_backgroundOrigin:"set_backgroundOrigin",get_backgroundOrigin:"get_backgroundOrigin",set_backgroundRepeat:"set_backgroundRepeat",get_backgroundRepeat:"get_backgroundRepeat",set_backgroundImage:"set_backgroundImage",get_backgroundImage:"get_backgroundImage",set_backgroundColor:"set_backgroundColor",get_backgroundColor:"get_backgroundColor",set_right:"set_right",get_right:"get_right",set_bottom:"set_bottom",get_bottom:"get_bottom",set_left:"set_left",get_left:"get_left",set_top:"set_top",get_top:"get_top",set_maxWidth:"set_maxWidth",get_maxWidth:"get_maxWidth",set_minWidth:"set_minWidth",get_minWidth:"get_minWidth",set_maxHeight:"set_maxHeight",get_maxHeight:"get_maxHeight",set_minHeight:"set_minHeight",get_minHeight:"get_minHeight",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_paddingBottom:"set_paddingBottom",get_paddingBottom:"get_paddingBottom",set_paddingTop:"set_paddingTop",get_paddingTop:"get_paddingTop",set_paddingRight:"set_paddingRight",get_paddingRight:"get_paddingRight",set_paddingLeft:"set_paddingLeft",get_paddingLeft:"get_paddingLeft",set_marginBottom:"set_marginBottom",get_marginBottom:"get_marginBottom",set_marginTop:"set_marginTop",get_marginTop:"get_marginTop",set_marginRight:"set_marginRight",get_marginRight:"get_marginRight",set_marginLeft:"set_marginLeft",get_marginLeft:"get_marginLeft",set_clear:"set_clear",get_clear:"get_clear",set_cssFloat:"set_CSSFloat",get_cssFloat:"get_CSSFloat",set_position:"set_position",get_position:"get_position",set_display:"set_display",get_display:"get_display"}
}
if(!cocktail.core.style.computer) cocktail.core.style.computer = {}
cocktail.core.style.computer.BackgroundStylesComputer = $hxClasses["cocktail.core.style.computer.BackgroundStylesComputer"] = function() {
};
cocktail.core.style.computer.BackgroundStylesComputer.__name__ = ["cocktail","core","style","computer","BackgroundStylesComputer"];
cocktail.core.style.computer.BackgroundStylesComputer.compute = function(style) {
	style.getComputedStyle().backgroundColor = cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundColor(style);
	style.getComputedStyle().backgroundRepeat = style.getBackgroundRepeat();
	style.getComputedStyle().backgroundClip = style.getBackgroundClip();
	style.getComputedStyle().backgroundSize = style.getBackgroundSize();
	style.getComputedStyle().backgroundPosition = style.getBackgroundPosition();
	style.getComputedStyle().backgroundOrigin = style.getBackgroundOrigin();
	style.getComputedStyle().backgroundImage = style.getBackgroundImage();
}
cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground = function(style,backgroundBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var backgroundPositioningArea = cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea(style,backgroundOrigin,backgroundBox);
	var computedBackgroundSize = cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundSize(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundPosition = cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundClip = cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea(style,backgroundClip,backgroundBox);
	var computedBackgroundStyle = { backgroundOrigin : backgroundPositioningArea, backgroundClip : computedBackgroundClip, backgroundRepeat : backgroundRepeat, backgroundImage : backgroundImage, backgroundSize : computedBackgroundSize, backgroundPosition : computedBackgroundPosition};
	return computedBackgroundStyle;
}
cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundColor = function(style) {
	var computedColor;
	computedColor = cocktail.core.unit.UnitManager.getColorDataFromCSSColor(style.getBackgroundColor());
	return computedColor;
}
cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition = function(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,emReference,exReference) {
	var computedBackgroundXPosition = cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition(backgroundPosition.x,Math.round(backgroundPositioningArea.width),computedBackgroundSize.width,emReference,exReference);
	var computedBackgroundYPosition = cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition(backgroundPosition.y,Math.round(backgroundPositioningArea.height),computedBackgroundSize.height,emReference,exReference);
	var computedBackgroundPosition = { x : computedBackgroundXPosition, y : computedBackgroundYPosition};
	return computedBackgroundPosition;
}
cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	var computedBackgroundXPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundXPosition = cocktail.core.unit.UnitManager.getPixelFromLength(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundXPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundXPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundXPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundXPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	return computedBackgroundXPosition;
}
cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	var computedBackgroundYPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundYPosition = cocktail.core.unit.UnitManager.getPixelFromLength(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundYPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundYPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundYPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundYPosition = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	return computedBackgroundYPosition;
}
cocktail.core.style.computer.BackgroundStylesComputer.getComputedBackgroundSize = function(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference) {
	var computedBackgroundSize;
	var $e = (backgroundSize);
	switch( $e[1] ) {
	case 0:
		if(intrinsicRatio != null) {
			var ratio = intrinsicRatio / (backgroundPositioningArea.width / backgroundPositioningArea.height);
			computedBackgroundSize = { width : Math.round(intrinsicWidth * ratio), height : Math.round(intrinsicHeight * ratio)};
		} else computedBackgroundSize = { width : Math.round(backgroundPositioningArea.width), height : Math.round(backgroundPositioningArea.height)};
		break;
	case 1:
		if(intrinsicRatio != null) {
			var ratio = backgroundPositioningArea.width / backgroundPositioningArea.height / intrinsicRatio;
			computedBackgroundSize = { width : Math.round(intrinsicWidth * ratio), height : Math.round(intrinsicHeight * ratio)};
		} else computedBackgroundSize = { width : Math.round(backgroundPositioningArea.width), height : Math.round(backgroundPositioningArea.height)};
		break;
	case 2:
		var value = $e[2];
		computedBackgroundSize = { width : cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.x,value.y,Math.round(backgroundPositioningArea.width),Math.round(backgroundPositioningArea.height),intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference), height : cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.y,value.x,Math.round(backgroundPositioningArea.height),Math.round(backgroundPositioningArea.width),intrinsicHeight,intrinsicWidth,intrinsicRatio,emReference,exReference)};
		break;
	}
	return computedBackgroundSize;
}
cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData = function(value,opositeBackgroundSizeValue,backgroundPositioningAreaDimension,opositeBackgroundAreaDimension,intrinsicDimension,opositeIntrinsicDimension,intrinsicRatio,emReference,exReference) {
	var backgroundSizeStyleDimension;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		backgroundSizeStyleDimension = cocktail.core.unit.UnitManager.getPixelFromLength(value1,emReference,exReference);
		break;
	case 1:
		var value1 = $e[2];
		backgroundSizeStyleDimension = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value1,backgroundPositioningAreaDimension));
		break;
	case 2:
		if(intrinsicDimension != null && opositeBackgroundSizeValue == cocktail.core.style.BackgroundSizeDimension.cssAuto) backgroundSizeStyleDimension = intrinsicDimension; else if(opositeIntrinsicDimension != null && intrinsicRatio != null) {
			var opositeDimension = cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(opositeBackgroundSizeValue,value,opositeBackgroundAreaDimension,backgroundPositioningAreaDimension,opositeIntrinsicDimension,intrinsicDimension,intrinsicRatio,emReference,exReference);
			backgroundSizeStyleDimension = Math.round(opositeDimension * intrinsicRatio);
		} else backgroundSizeStyleDimension = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension));
		break;
	}
	return backgroundSizeStyleDimension;
}
cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea = function(style,backgroundOrigin,backgroundBox) {
	var backgroundPositioningArea;
	var height;
	var width;
	var x;
	var y;
	switch( (backgroundOrigin)[1] ) {
	case 0:
		height = backgroundBox.height;
		width = backgroundBox.width;
		x = 0.0;
		y = 0.0;
		break;
	case 1:
		height = backgroundBox.height;
		width = backgroundBox.width;
		x = style.getComputedStyle().marginLeft;
		y = style.getComputedStyle().marginTop;
		break;
	case 2:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom - style.getComputedStyle().paddingTop - style.getComputedStyle().paddingBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight;
		x = style.getComputedStyle().marginLeft + style.getComputedStyle().paddingLeft;
		y = style.getComputedStyle().marginTop + style.getComputedStyle().paddingTop;
		break;
	}
	backgroundPositioningArea = { height : height, width : width, x : x, y : y};
	return backgroundPositioningArea;
}
cocktail.core.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea = function(style,backgroundClip,backgroundBox) {
	var backgroundPaintingArea;
	var height;
	var width;
	var x;
	var y;
	switch( (backgroundClip)[1] ) {
	case 0:
		height = backgroundBox.height;
		width = backgroundBox.width;
		x = 0.0;
		y = 0.0;
		break;
	case 1:
		height = backgroundBox.height;
		width = backgroundBox.width;
		x = style.getComputedStyle().marginLeft;
		y = style.getComputedStyle().marginTop;
		break;
	case 2:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom - style.getComputedStyle().paddingTop - style.getComputedStyle().paddingBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight;
		x = style.getComputedStyle().marginLeft + style.getComputedStyle().paddingLeft;
		y = style.getComputedStyle().marginTop + style.getComputedStyle().paddingTop;
		break;
	}
	backgroundPaintingArea = { height : height, width : width, x : x, y : y};
	return backgroundPaintingArea;
}
cocktail.core.style.computer.BackgroundStylesComputer.prototype = {
	__class__: cocktail.core.style.computer.BackgroundStylesComputer
}
cocktail.core.style.computer.DisplayStylesComputer = $hxClasses["cocktail.core.style.computer.DisplayStylesComputer"] = function() {
};
cocktail.core.style.computer.DisplayStylesComputer.__name__ = ["cocktail","core","style","computer","DisplayStylesComputer"];
cocktail.core.style.computer.DisplayStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.position = cocktail.core.style.computer.DisplayStylesComputer.getComputedPosition(style);
	computedStyle.cssFloat = cocktail.core.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = cocktail.core.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle.cssFloat);
	computedStyle.clear = cocktail.core.style.computer.DisplayStylesComputer.getComputedClear(style,computedStyle.position,computedStyle.display);
}
cocktail.core.style.computer.DisplayStylesComputer.getComputedPosition = function(style) {
	return style.getPosition();
}
cocktail.core.style.computer.DisplayStylesComputer.getComputedFloat = function(style,computedPosition) {
	var ret;
	if(computedPosition == cocktail.core.style.Position.absolute || computedPosition == cocktail.core.style.Position.fixed) ret = cocktail.core.style.CSSFloat.none; else ret = style.getCSSFloat();
	return ret;
}
cocktail.core.style.computer.DisplayStylesComputer.getComputedDisplay = function(style,computedFloat) {
	var ret;
	if(computedFloat != cocktail.core.style.CSSFloat.none) {
		switch( (style.getDisplay())[1] ) {
		case 2:
		case 1:
			ret = cocktail.core.style.Display.block;
			break;
		default:
			ret = style.getDisplay();
		}
	} else ret = style.getDisplay();
	return ret;
}
cocktail.core.style.computer.DisplayStylesComputer.getComputedClear = function(style,computedPosition,computedDisplay) {
	var ret;
	if(computedDisplay == cocktail.core.style.Display.cssInline || computedDisplay == cocktail.core.style.Display.inlineBlock) ret = cocktail.core.style.Clear.none; else if(computedPosition == cocktail.core.style.Position.absolute || computedPosition == cocktail.core.style.Position.fixed) ret = cocktail.core.style.Clear.none; else ret = style.getClear();
	return ret;
}
cocktail.core.style.computer.DisplayStylesComputer.prototype = {
	__class__: cocktail.core.style.computer.DisplayStylesComputer
}
cocktail.core.style.computer.FontAndTextStylesComputer = $hxClasses["cocktail.core.style.computer.FontAndTextStylesComputer"] = function() {
};
cocktail.core.style.computer.FontAndTextStylesComputer.__name__ = ["cocktail","core","style","computer","FontAndTextStylesComputer"];
cocktail.core.style.computer.FontAndTextStylesComputer.compute = function(style,containingHTMLElementData,containingHTMLElementFontMetricsData) {
	var computedStyle = style.getComputedStyle();
	if(containingHTMLElementFontMetricsData != null) computedStyle.fontSize = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,containingHTMLElementFontMetricsData.fontSize,containingHTMLElementFontMetricsData.xHeight); else computedStyle.fontSize = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,12.0,10.0);
	computedStyle.lineHeight = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedLineHeight(style);
	computedStyle.verticalAlign = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign(style,containingHTMLElementData,containingHTMLElementFontMetricsData);
	computedStyle.fontWeight = style.getFontWeight();
	computedStyle.fontStyle = style.getFontStyle();
	computedStyle.fontFamily = style.getFontFamily();
	computedStyle.fontVariant = style.getFontVariant();
	computedStyle.textTransform = style.getTextTransform();
	computedStyle.letterSpacing = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing(style);
	computedStyle.wordSpacing = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedWordSpacing(style);
	computedStyle.textIndent = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedTextIndent(style,containingHTMLElementData);
	computedStyle.whiteSpace = style.getWhiteSpace();
	computedStyle.textAlign = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedTextAlign(style,computedStyle.whiteSpace);
	computedStyle.color = cocktail.core.style.computer.FontAndTextStylesComputer.getComputedColor(style);
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedTextIndent = function(style,containingHTMLElementData) {
	var textIndent;
	var $e = (style.getTextIndent());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		textIndent = cocktail.core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		textIndent = cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementData.width);
		break;
	}
	return Math.round(textIndent);
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingHTMLElementData,containingHTMLElementFontMetricsData) {
	var verticalAlign;
	var $e = (style.getVerticalAlign());
	switch( $e[1] ) {
	case 0:
		verticalAlign = 0;
		break;
	case 5:
		var offsetHeight = style.getComputedStyle().height + style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom;
		verticalAlign = offsetHeight / 2 + containingHTMLElementFontMetricsData.xHeight / 2;
		break;
	case 1:
		verticalAlign = containingHTMLElementFontMetricsData.subscriptOffset;
		break;
	case 2:
		verticalAlign = containingHTMLElementFontMetricsData.superscriptOffset;
		break;
	case 4:
		verticalAlign = 0;
		break;
	case 7:
		verticalAlign = 0;
		break;
	case 8:
		var value = $e[2];
		verticalAlign = cocktail.core.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().lineHeight));
		break;
	case 9:
		var value = $e[2];
		verticalAlign = cocktail.core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 3:
		verticalAlign = 0;
		break;
	case 6:
		verticalAlign = 0;
		break;
	}
	return verticalAlign;
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedTextAlign = function(style,computedWhiteSpace) {
	var textAlign = style.getTextAlign();
	switch( (computedWhiteSpace)[1] ) {
	case 1:
		if(style.getTextAlign() == cocktail.core.style.TextAlign.justify) textAlign = cocktail.core.style.TextAlign.left;
		break;
	default:
	}
	return textAlign;
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedColor = function(style) {
	return cocktail.core.unit.UnitManager.getColorDataFromCSSColor(style.getColor());
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedWordSpacing = function(style) {
	var wordSpacing;
	var $e = (style.getWordSpacing());
	switch( $e[1] ) {
	case 0:
		wordSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		wordSpacing = Math.round(cocktail.core.unit.UnitManager.getPixelFromLength(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	return wordSpacing;
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedLineHeight = function(style) {
	var lineHeight;
	var $e = (style.getLineHeight());
	switch( $e[1] ) {
	case 2:
		var unit = $e[2];
		lineHeight = cocktail.core.unit.UnitManager.getPixelFromLength(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 0:
		lineHeight = style.getComputedStyle().fontSize * 1.2;
		break;
	case 3:
		var value = $e[2];
		lineHeight = cocktail.core.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().fontSize));
		break;
	case 1:
		var value = $e[2];
		lineHeight = style.getComputedStyle().fontSize * value;
		break;
	}
	return lineHeight;
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing = function(style) {
	var letterSpacing;
	var $e = (style.getLetterSpacing());
	switch( $e[1] ) {
	case 0:
		letterSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		letterSpacing = Math.round(cocktail.core.unit.UnitManager.getPixelFromLength(unit,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	return letterSpacing;
}
cocktail.core.style.computer.FontAndTextStylesComputer.getComputedFontSize = function(style,parentFontSize,parentXHeight) {
	var fontSize;
	var $e = (style.getFontSize());
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		fontSize = cocktail.core.unit.UnitManager.getPixelFromLength(unit,parentFontSize,parentXHeight);
		break;
	case 1:
		var percent = $e[2];
		fontSize = cocktail.core.unit.UnitManager.getPixelFromPercent(percent,Math.round(parentFontSize));
		break;
	case 2:
		var value = $e[2];
		fontSize = cocktail.core.unit.UnitManager.getFontSizeFromAbsoluteSizeValue(value);
		break;
	case 3:
		var value = $e[2];
		fontSize = cocktail.core.unit.UnitManager.getFontSizeFromRelativeSizeValue(value,parentFontSize);
		break;
	}
	return fontSize;
}
cocktail.core.style.computer.FontAndTextStylesComputer.prototype = {
	__class__: cocktail.core.style.computer.FontAndTextStylesComputer
}
cocktail.core.style.computer.VisualEffectStylesComputer = $hxClasses["cocktail.core.style.computer.VisualEffectStylesComputer"] = function() {
};
cocktail.core.style.computer.VisualEffectStylesComputer.__name__ = ["cocktail","core","style","computer","VisualEffectStylesComputer"];
cocktail.core.style.computer.VisualEffectStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.opacity = style.getOpacity();
	computedStyle.visibility = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedVisibility(style);
	computedStyle.overflowX = style.getOverflowX();
	computedStyle.overflowY = style.getOverflowY();
	computedStyle.transformOrigin = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin(style);
	computedStyle.transform = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTransform(style);
}
cocktail.core.style.computer.VisualEffectStylesComputer.getComputedVisibility = function(style) {
	var visibility;
	switch( (style.getVisibility())[1] ) {
	case 0:
		visibility = true;
		break;
	case 1:
		visibility = false;
		break;
	}
	return visibility;
}
cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin = function(style) {
	var x;
	var y;
	var $e = (style.getTransformOrigin().x);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		x = cocktail.core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		x = cocktail.core.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		x = cocktail.core.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		x = cocktail.core.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		x = cocktail.core.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var $e = (style.getTransformOrigin().y);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		y = cocktail.core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		y = cocktail.core.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		y = cocktail.core.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		y = cocktail.core.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		y = cocktail.core.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var transformOriginPoint = { x : x, y : y};
	return transformOriginPoint;
}
cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTransform = function(style) {
	var transformFunctions;
	var transformOrigin = style.getComputedStyle().transformOrigin;
	var matrix = new cocktail.core.geom.Matrix();
	var $e = (style.getTransform());
	switch( $e[1] ) {
	case 1:
		var value = $e[2];
		transformFunctions = value;
		break;
	case 0:
		transformFunctions = new Array();
		break;
	}
	var _g1 = 0, _g = transformFunctions.length;
	while(_g1 < _g) {
		var i = _g1++;
		var transformFunction = transformFunctions[i];
		var $e = (transformFunction);
		switch( $e[1] ) {
		case 0:
			var data = $e[2];
			matrix.concatenate(new cocktail.core.geom.Matrix(data));
			break;
		case 7:
			var value = $e[2];
			var angle = Math.round(cocktail.core.unit.UnitManager.getRadFromAngle(value));
			matrix.rotate(angle,transformOrigin);
			break;
		case 4:
			var sys = $e[3], sx = $e[2];
			matrix.scale(sx,sys,transformOrigin);
			break;
		case 5:
			var sx = $e[2];
			matrix.scale(sx,1,transformOrigin);
			break;
		case 6:
			var sy = $e[2];
			matrix.scale(1,sy,transformOrigin);
			break;
		case 10:
			var angleY = $e[3], angleX = $e[2];
			var skewX = cocktail.core.unit.UnitManager.getRadFromAngle(angleX);
			var skewY = cocktail.core.unit.UnitManager.getRadFromAngle(angleY);
			matrix.skew(skewX,skewY,transformOrigin);
			break;
		case 8:
			var angleX = $e[2];
			var skewX = cocktail.core.unit.UnitManager.getRadFromAngle(angleX);
			matrix.skew(skewX,1,transformOrigin);
			break;
		case 9:
			var angleY = $e[2];
			var skewY = cocktail.core.unit.UnitManager.getRadFromAngle(angleY);
			matrix.skew(1,skewY,transformOrigin);
			break;
		case 1:
			var ty = $e[3], tx = $e[2];
			var translationX = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			var translationY = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(translationX,translationY);
			break;
		case 2:
			var tx = $e[2];
			var translationX = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			matrix.translate(translationX,0.0);
			break;
		case 3:
			var ty = $e[2];
			var translationY = cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(0.0,translationY);
			break;
		}
	}
	return matrix;
}
cocktail.core.style.computer.VisualEffectStylesComputer.getComputedTranslation = function(style,translation,percentReference) {
	var computedTranslation;
	var $e = (translation);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedTranslation = cocktail.core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		computedTranslation = cocktail.core.unit.UnitManager.getPixelFromPercent(value,percentReference);
		break;
	}
	return computedTranslation;
}
cocktail.core.style.computer.VisualEffectStylesComputer.prototype = {
	__class__: cocktail.core.style.computer.VisualEffectStylesComputer
}
if(!cocktail.core.style.computer.boxComputers) cocktail.core.style.computer.boxComputers = {}
cocktail.core.style.computer.boxComputers.BoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.BoxStylesComputer"] = function() {
};
cocktail.core.style.computer.boxComputers.BoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","BoxStylesComputer"];
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype = {
	measure: function(style,containingHTMLElementData) {
		this.measureHorizontalPaddings(style,containingHTMLElementData);
		this.measureVerticalPaddings(style,containingHTMLElementData);
		this.measureDimensionsConstraints(style,containingHTMLElementData);
		this.measureWidthAndHorizontalMargins(style,containingHTMLElementData);
		this.measureHeightAndVerticalMargins(style,containingHTMLElementData);
		this.measurePositionOffsets(style,containingHTMLElementData);
	}
	,shrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		return style.getComputedStyle().width;
	}
	,applyContentHeight: function(style,cotainingHTMLElementData,childrenHeight) {
		return childrenHeight;
	}
	,measureDimensionsConstraints: function(style,containingHTMLElementData) {
		style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,measurePositionOffsets: function(style,containingHTMLElementData) {
		style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureVerticalPaddings: function(style,containingHTMLElementData) {
		style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureHorizontalPaddings: function(style,containingHTMLElementData) {
		style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureWidthAndHorizontalMargins: function(style,containingHTMLElementData) {
		if(style.getWidth() == cocktail.core.style.Dimension.cssAuto) this.measureAutoWidth(style,containingHTMLElementData); else this.measureWidth(style,containingHTMLElementData);
	}
	,measureAutoWidth: function(style,containingHTMLElementData) {
		this.setComputedWidth(style,0);
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingHTMLElementData));
	}
	,measureWidth: function(style,containingHTMLElementData) {
		this.setComputedWidth(style,this.getComputedWidth(style,containingHTMLElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
	}
	,measureHeightAndVerticalMargins: function(style,containingHTMLElementData) {
		if(style.getHeight() == cocktail.core.style.Dimension.cssAuto) this.measureAutoHeight(style,containingHTMLElementData); else this.measureHeight(style,containingHTMLElementData);
	}
	,measureAutoHeight: function(style,containingHTMLElementData) {
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingHTMLElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
	}
	,measureHeight: function(style,containingHTMLElementData) {
		this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
	}
	,constrainWidth: function(style,computedWidth) {
		var computedStyle = style.getComputedStyle();
		if(style.getMaxWidth() != cocktail.core.style.ConstrainedDimension.none) {
			if(computedWidth > computedStyle.maxWidth) computedWidth = computedStyle.maxWidth;
		}
		if(computedWidth < computedStyle.minWidth) computedWidth = computedStyle.minWidth;
		return computedWidth;
	}
	,constrainHeight: function(style,computedHeight) {
		var computedStyle = style.getComputedStyle();
		if(style.getMaxHeight() != cocktail.core.style.ConstrainedDimension.none) {
			if(computedHeight > computedStyle.maxHeight) computedHeight = computedStyle.maxHeight;
		}
		if(computedHeight < computedStyle.minHeight) computedHeight = computedStyle.minHeight;
		return computedHeight;
	}
	,setComputedHeight: function(style,computedHeight) {
		style.getComputedStyle().height = this.constrainHeight(style,computedHeight);
	}
	,setComputedWidth: function(style,computedWidth) {
		style.getComputedStyle().width = this.constrainWidth(style,computedWidth);
	}
	,getComputedWidth: function(style,containingHTMLElementData) {
		return this.getComputedDimension(style.getWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedAutoWidth: function(style,containingHTMLElementData) {
		return containingHTMLElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
	}
	,getComputedHeight: function(style,containingHTMLElementData) {
		return this.getComputedDimension(style.getHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedAutoHeight: function(style,containingHTMLElementData) {
		return 0;
	}
	,getComputedMarginLeft: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginRight: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginTop: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMarginBottom: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		var computedMargin;
		var $e = (marginStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedMargin = cocktail.core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isDimensionAuto == true) computedMargin = 0; else computedMargin = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		case 2:
			computedMargin = this.getComputedAutoMargin(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
			break;
		}
		return computedMargin;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		var computedMargin;
		if(isHorizontalMargin == false || isDimensionAuto == true) computedMargin = 0; else {
			switch( (opositeMargin)[1] ) {
			case 2:
				computedMargin = Math.round((containingHTMLElementDimension - computedDimension - computedPaddingsDimension) / 2);
				break;
			default:
				var opositeComputedMargin = this.getComputedMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
				computedMargin = containingHTMLElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin;
			}
		}
		return computedMargin;
	}
	,getComputedConstrainedDimension: function(constrainedDimension,containingHTMLElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
		if(isMinConstraint == null) isMinConstraint = false;
		var computedConstraintDimension;
		var $e = (constrainedDimension);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedConstraintDimension = cocktail.core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isContainingDimensionAuto == true) {
				if(isMinConstraint == true) computedConstraintDimension = 0; else computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
			} else computedConstraintDimension = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		case 2:
			if(isMinConstraint == true) computedConstraintDimension = 0; else computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
			break;
		}
		return computedConstraintDimension;
	}
	,getComputedPositionOffset: function(positionOffsetStyleValue,containingHTMLElementDimension,fontSize,xHeight) {
		var computedPositionOffset;
		var $e = (positionOffsetStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedPositionOffset = cocktail.core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPositionOffset = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		case 2:
			computedPositionOffset = 0;
			break;
		}
		return computedPositionOffset;
	}
	,getComputedDimension: function(dimensionStyleValue,containingHTMLElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
		var computedDimensions;
		var $e = (dimensionStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedDimensions = cocktail.core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedDimensions = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		case 2:
			computedDimensions = 0;
			break;
		}
		return computedDimensions;
	}
	,getComputedPadding: function(paddingStyleValue,containingHTMLElementDimension,fontSize,xHeight) {
		var computedPaddingValue;
		var $e = (paddingStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedPaddingValue = cocktail.core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPaddingValue = Math.round(cocktail.core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		}
		return computedPaddingValue;
	}
	,__class__: cocktail.core.style.computer.boxComputers.BoxStylesComputer
}
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	__class__: cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	measureAutoWidth: function(style,containingHTMLElementData) {
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingHTMLElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
	}
	,getComputedAutoWidth: function(style,containingHTMLElementData) {
		var ret = 0;
		var embeddedHTMLElement = style.get_htmlElement();
		if(style.getHeight() == cocktail.core.style.Dimension.cssAuto) {
			if(embeddedHTMLElement.get_intrinsicWidth() != null) ret = embeddedHTMLElement.get_intrinsicWidth(); else if(embeddedHTMLElement.get_intrinsicHeight() != null && embeddedHTMLElement.get_intrinsicRatio() != null) ret = Math.round(embeddedHTMLElement.get_intrinsicHeight() * embeddedHTMLElement.get_intrinsicRatio()); else if(embeddedHTMLElement.get_intrinsicRatio() != null) {
				if(containingHTMLElementData.isWidthAuto == false) {
					var computedStyle = style.getComputedStyle();
					ret = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
				} else ret = 0;
			}
		} else {
			var computedHeight = this.getComputedDimension(style.getHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,computedHeight);
			if(embeddedHTMLElement.get_intrinsicRatio() != null) ret = Math.round(computedHeight * embeddedHTMLElement.get_intrinsicRatio()); else if(embeddedHTMLElement.get_intrinsicWidth() != null) ret = embeddedHTMLElement.get_intrinsicWidth(); else ret = 300;
		}
		return ret;
	}
	,getComputedAutoHeight: function(style,containingHTMLElementData) {
		var ret = 0;
		var embeddedHTMLElement = style.get_htmlElement();
		if(style.getWidth() == cocktail.core.style.Dimension.cssAuto) {
			if(embeddedHTMLElement.get_intrinsicHeight() != null) ret = embeddedHTMLElement.get_intrinsicHeight();
		} else {
			var computedWidth = this.getComputedDimension(style.getWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,computedWidth);
			if(embeddedHTMLElement.get_intrinsicRatio() != null) ret = Math.round(style.getComputedStyle().width / embeddedHTMLElement.get_intrinsicRatio()); else ret = 150;
		}
		return ret;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		var computedMargin;
		if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
		return computedMargin;
	}
	,__class__: cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,__class__: cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	measurePositionOffsets: function(style,containingHTMLElementData) {
		this.measureHorizontalPositionOffsets(style,containingHTMLElementData);
		this.measureVerticalPositionOffsets(style,containingHTMLElementData);
	}
	,measureHorizontalPositionOffsets: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto || style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
			if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = 0;
			if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginRight = 0;
			if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto && style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			} else if(style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		} else {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto && style.getMarginRight() == cocktail.core.style.Margin.cssAuto) {
				var margin = Math.round((containingHTMLElementData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight) / 2);
				var computedMargin = Math.round((containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginLeft = computedMargin;
					style.getComputedStyle().marginRight = computedMargin;
				} else {
					style.getComputedStyle().marginLeft = 0;
					style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
				style.getComputedStyle().marginLeft = 0;
			} else if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight; else if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
		}
	}
	,measureVerticalPositionOffsets: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto || style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
			if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0;
			if(style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0;
			if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto && style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingHTMLElementData);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().top = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else if(style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			}
		} else {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto && style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) {
				var margin = Math.round((containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2);
				var computedMargin = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginTop = 0;
					style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			} else if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom; else if(style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
		}
	}
	,getComputedStaticLeft: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginLeft;
	}
	,getComputedStaticTop: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginTop;
	}
	,__class__: cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,shrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < containingHTMLElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingHTMLElementData.width;
		return shrinkedWidth;
	}
	,__class__: cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype,{
	getComputedAutoWidth: function(style,containingHTMLElementData) {
		return 0;
	}
	,__class__: cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	measureVerticalPaddings: function(style,containingHTMLElementData) {
		style.getComputedStyle().paddingTop = 0;
		style.getComputedStyle().paddingBottom = 0;
	}
	,measureAutoHeight: function(style,containingHTMLElementData) {
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingHTMLElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
	}
	,measureHeight: function(style,containingHTMLElementData) {
		this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,getComputedWidth: function(style,containingHTMLElementData) {
		return 0;
	}
	,getComputedHeight: function(style,containingHTMLElementData) {
		return 0;
	}
	,__class__: cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer
});
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer = $hxClasses["cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer"] = function() {
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
};
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype = $extend(cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	shrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		var shrinkedWidth;
		if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto || style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
			var computedStyle = style.getComputedStyle();
			shrinkedWidth = this.doShrinkToFit(style,containingHTMLElementData,minimumWidth);
			if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto && style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
		} else shrinkedWidth = style.getComputedStyle().width;
		shrinkedWidth = this.constrainWidth(style,shrinkedWidth);
		return shrinkedWidth;
	}
	,applyContentHeight: function(style,containingHTMLElementData,childrenHeight) {
		var height;
		if(style.getTop() != cocktail.core.style.PositionOffset.cssAuto && style.getBottom() != cocktail.core.style.PositionOffset.cssAuto) {
			var computedStyle = style.getComputedStyle();
			height = containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		} else height = childrenHeight;
		height = this.constrainHeight(style,height);
		return height;
	}
	,measurePositionOffsets: function(style,containingHTMLElementData) {
	}
	,measureAutoWidth: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) computedStyle.marginLeft = 0; else computedStyle.marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) computedStyle.marginRight = 0; else computedStyle.marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
		if(style.getLeft() != cocktail.core.style.PositionOffset.cssAuto && style.getRight() != cocktail.core.style.PositionOffset.cssAuto) {
			computedStyle.left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			computedStyle.right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight);
		} else this.setComputedWidth(style,1000000);
	}
	,measureWidth: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		this.setComputedWidth(style,this.getComputedWidth(style,containingHTMLElementData));
		if(style.getLeft() != cocktail.core.style.PositionOffset.cssAuto && style.getRight() != cocktail.core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto && style.getMarginRight() == cocktail.core.style.Margin.cssAuto) {
				var computedMargin = Math.round((containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginLeft = computedMargin;
					style.getComputedStyle().marginRight = computedMargin;
				} else {
					style.getComputedStyle().marginLeft = 0;
					style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			} else if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) {
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
				style.getComputedStyle().marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			} else if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
				style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			} else {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
			}
		} else {
			if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = 0; else style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
			if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginRight = 0; else style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
			if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto && style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			} else if(style.getRight() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
	}
	,measureAutoHeight: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
		if(style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
		if(style.getTop() != cocktail.core.style.PositionOffset.cssAuto && style.getBottom() != cocktail.core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,containingHTMLElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom);
		} else if(style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
		} else if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().top = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
		}
	}
	,measureHeight: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
		if(style.getTop() != cocktail.core.style.PositionOffset.cssAuto && style.getBottom() != cocktail.core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto && style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) {
				var computedMargin = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginBottom = 0;
					style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			} else if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto) {
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
				style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			} else if(style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
				style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			} else {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
			}
		} else {
			if(style.getMarginTop() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
			if(style.getMarginBottom() == cocktail.core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
			if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto && style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingHTMLElementData);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getBottom() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == cocktail.core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().top = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
			}
		}
	}
	,getComputedStaticLeft: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginLeft;
	}
	,getComputedStaticTop: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginTop;
	}
	,doShrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		return minimumWidth;
	}
	,__class__: cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer
});
if(!cocktail.core.style.floats) cocktail.core.style.floats = {}
cocktail.core.style.floats.FloatsManager = $hxClasses["cocktail.core.style.floats.FloatsManager"] = function() {
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
};
cocktail.core.style.floats.FloatsManager.__name__ = ["cocktail","core","style","floats","FloatsManager"];
cocktail.core.style.floats.FloatsManager.prototype = {
	_floats: null
	,floats: null
	,dispose: function() {
		this._floats.left = null;
		this._floats.right = null;
		this._floats = null;
	}
	,clearFloat: function(clear,formattingContextData) {
		var ret;
		switch( (clear)[1] ) {
		case 1:
			ret = this.clearLeft(formattingContextData);
			this._floats.left = new Array();
			break;
		case 2:
			ret = this.clearRight(formattingContextData);
			this._floats.right = new Array();
			break;
		case 3:
			ret = this.clearBoth(formattingContextData);
			this._floats.right = new Array();
			this._floats.left = new Array();
			break;
		case 0:
			ret = formattingContextData.y;
			break;
		}
		return ret;
	}
	,clearLeft: function(formattingContextData) {
		return this.doClearFloat(formattingContextData,this._floats.left);
	}
	,clearRight: function(formattingContextData) {
		return this.doClearFloat(formattingContextData,this._floats.right);
	}
	,clearBoth: function(formattingContextData) {
		var leftY = this.doClearFloat(formattingContextData,this._floats.left);
		var rightY = this.doClearFloat(formattingContextData,this._floats.right);
		if(leftY > rightY) return leftY; else return rightY;
	}
	,doClearFloat: function(formattingContextData,floats) {
		if(floats.length > 0) {
			var highestFloat = floats[0];
			var _g1 = 0, _g = floats.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(floats[i].y + floats[i].height > highestFloat.y + highestFloat.height) highestFloat = floats[i];
			}
			return highestFloat.y + highestFloat.height;
		} else return formattingContextData.y;
	}
	,computeFloatData: function(elementRenderer,formattingContextData,containingBlockWidth) {
		var ret;
		switch( (elementRenderer.getCoreStyle().getComputedStyle().cssFloat)[1] ) {
		case 0:
			ret = this.getLeftFloatData(elementRenderer,formattingContextData,containingBlockWidth);
			this._floats.left.push(ret);
			break;
		case 1:
			ret = this.getRightFloatData(elementRenderer,formattingContextData,containingBlockWidth);
			this._floats.right.push(ret);
			break;
		default:
			ret = null;
		}
		return ret;
	}
	,getLeftFloatData: function(elementRenderer,formattingContextData,containingBlockWidth) {
		var floatData = this.getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
		floatData.x = this.getLeftFloatOffset(floatData.y);
		return floatData;
	}
	,getRightFloatData: function(elementRenderer,formattingContextData,containingBlockWidth) {
		var floatData = this.getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
		floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth);
		return floatData;
	}
	,getFloatData: function(elementRenderer,formattingContextData,containingBlockWidth) {
		var computedStyle = elementRenderer.getCoreStyle().getComputedStyle();
		var floatWidth = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		var floatHeight = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
		var floatY = this.getFirstAvailableY(formattingContextData,floatWidth,containingBlockWidth);
		var floatX = 0;
		return { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
	}
	,getFirstAvailableY: function(formattingContextData,elementWidth,containingBlockWidth) {
		var retY = formattingContextData.y;
		while(this.getLeftFloatOffset(retY) + this.getRightFloatOffset(retY,containingBlockWidth) + elementWidth > containingBlockWidth) {
			var afterFloats = new Array();
			var _g1 = 0, _g = this._floats.left.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._floats.left[i].y <= retY && this._floats.left[i].height + this._floats.left[i].y > retY) afterFloats.push(this._floats.left[i]);
			}
			var _g1 = 0, _g = this._floats.right.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._floats.right[i].y <= retY && this._floats.right[i].height + this._floats.right[i].y > retY) afterFloats.push(this._floats.right[i]);
			}
			if(afterFloats.length == 0) break; else {
				var nextY = 1000000;
				var _g1 = 0, _g = afterFloats.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(afterFloats[i].y + afterFloats[i].height - retY < nextY) nextY = afterFloats[i].y + afterFloats[i].height - retY;
				}
				retY += nextY;
			}
		}
		return retY;
	}
	,removeFloats: function(flowY) {
		this._floats.left = this.doRemoveFloat(this._floats.left,flowY);
		this._floats.right = this.doRemoveFloat(this._floats.right,flowY);
	}
	,doRemoveFloat: function(floats,flowY) {
		var newFloats = new Array();
		var _g1 = 0, _g = floats.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(floats[i].y + floats[i].height > flowY) newFloats.push(floats[i]);
		}
		return newFloats;
	}
	,getRightFloatOffset: function(y,containingWidth) {
		var rightFloatOffset = 0;
		var _g1 = 0, _g = this._floats.right.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._floats.right[i].y + this._floats.right[i].height > y && this._floats.right[i].y <= y) {
				if(containingWidth - this._floats.right[i].x > rightFloatOffset) rightFloatOffset = containingWidth - this._floats.right[i].x;
			}
		}
		return rightFloatOffset;
	}
	,getLeftFloatOffset: function(y) {
		var leftFloatOffset = 0;
		var _g1 = 0, _g = this._floats.left.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._floats.left[i].y + this._floats.left[i].height > y && this._floats.left[i].y <= y) {
				if(this._floats.left[i].x + this._floats.left[i].width > leftFloatOffset) leftFloatOffset = this._floats.left[i].x + this._floats.left[i].width;
			}
		}
		return leftFloatOffset;
	}
	,getFloats: function() {
		return this._floats;
	}
	,__class__: cocktail.core.style.floats.FloatsManager
	,__properties__: {get_floats:"getFloats"}
}
if(!cocktail.core.style.formatter) cocktail.core.style.formatter = {}
cocktail.core.style.formatter.FormattingContext = $hxClasses["cocktail.core.style.formatter.FormattingContext"] = function(formattingContextRoot) {
	this._formattingContextRoot = formattingContextRoot;
	this._floatsManager = new cocktail.core.style.floats.FloatsManager();
	this.initFormattingContextData();
	this._elementsInFormattingContext = new Array();
};
cocktail.core.style.formatter.FormattingContext.__name__ = ["cocktail","core","style","formatter","FormattingContext"];
cocktail.core.style.formatter.FormattingContext.prototype = {
	_formattingContextRoot: null
	,_floatsManager: null
	,_formattingContextData: null
	,_elementsInFormattingContext: null
	,_lastInsertedElement: null
	,maxWidth: null
	,_layOutLastLine: null
	,initFormattingContextData: function() {
		this._formattingContextData = { x : 0, y : 0, maxHeight : 0, maxWidth : 0};
	}
	,dispose: function() {
		this._elementsInFormattingContext = null;
		this._formattingContextData = null;
		this._lastInsertedElement = null;
		this._floatsManager.dispose();
		this._floatsManager = null;
		this._formattingContextRoot = null;
	}
	,insertElement: function(element) {
		this._elementsInFormattingContext.push(element);
	}
	,format: function() {
		this._layOutLastLine = true;
		this.doFormat(this._elementsInFormattingContext);
	}
	,getStaticPosition: function(element) {
		this._layOutLastLine = true;
		var elementsToFormat = new Array();
		var _g1 = 0, _g = this._elementsInFormattingContext.length;
		while(_g1 < _g) {
			var i = _g1++;
			elementsToFormat.push(this._elementsInFormattingContext[i]);
		}
		elementsToFormat.push(element);
		this.doFormat(elementsToFormat);
		var x = element.getBounds().x;
		var y = element.getBounds().y;
		return { x : x, y : y};
	}
	,getChildrenHeight: function(elementRenderer) {
		var height = 0;
		var elementRenderers = this.getChildElementRenderers(elementRenderer);
		height = Math.round(this.getBounds(elementRenderers).height);
		return height;
	}
	,getBounds: function(elements) {
		var bounds;
		var left = 50000;
		var top = 50000;
		var right = -50000;
		var bottom = -50000;
		var _g1 = 0, _g = elements.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(elements[i].getBounds().x < left) left = elements[i].getBounds().x;
			if(elements[i].getBounds().y < top) {
				if(elements[i].isText() == false) top = elements[i].getBounds().y; else {
					var htmlElementAscent = elements[i].getCoreStyle().getFontMetricsData().ascent;
					var htmlElementDescent = elements[i].getCoreStyle().getFontMetricsData().descent;
					var leading = elements[i].getCoreStyle().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
					htmlElementAscent = Math.round(htmlElementAscent + leading / 2);
					htmlElementDescent = Math.round(htmlElementDescent + leading / 2);
					top = elements[i].getBounds().y - htmlElementAscent;
				}
			}
			if(elements[i].getBounds().x + elements[i].getBounds().width > right) right = elements[i].getBounds().x + elements[i].getBounds().width;
			if(elements[i].getBounds().y + elements[i].getBounds().height > bottom) {
				if(elements[i].isText() == false) bottom = elements[i].getBounds().y + elements[i].getBounds().height; else {
					var htmlElementAscent = elements[i].getCoreStyle().getFontMetricsData().ascent;
					var htmlElementDescent = elements[i].getCoreStyle().getFontMetricsData().descent;
					var leading = elements[i].getCoreStyle().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
					htmlElementAscent = Math.round(htmlElementAscent + leading / 2);
					htmlElementDescent = Math.round(htmlElementDescent + leading / 2);
					bottom = elements[i].getBounds().y - htmlElementAscent + elements[i].getBounds().height;
				}
			}
		}
		bounds = { x : left, y : top, width : right - left, height : bottom - top};
		if(bounds.width < 0) bounds.width = 0;
		if(bounds.height < 0) bounds.height = 0;
		return bounds;
	}
	,doFormat: function(elementsInFormattingContext) {
		this.initFormattingContextData();
		var _g1 = 0, _g = elementsInFormattingContext.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.doInsertElement(elementsInFormattingContext[i],this.isNextElementALineFeed(elementsInFormattingContext,i));
		}
	}
	,doInsertElement: function(element,isNextElementALineFeed) {
		if(element.isFloat() == true) this.insertFloat(element); else if(element.canHaveChildren() == true) {
			if(element.getCoreStyle().establishesNewFormattingContext() == true) this.insertFormattingContextRootElement(element); else this.insertContainerElement(element);
		} else if(element.isText() == true) {
			if(element.isSpace() == true) this.insertSpace(element,isNextElementALineFeed); else this.insertText(element);
		} else this.insertEmbeddedElement(element);
	}
	,getChildElementRenderers: function(elementRenderer) {
		var elementRenderers = new Array();
		var _g1 = 0, _g = this._elementsInFormattingContext.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._elementsInFormattingContext[i].get_parentNode() == elementRenderer) elementRenderers.push(this._elementsInFormattingContext[i]);
		}
		return elementRenderers;
	}
	,insertEmbeddedElement: function(element) {
	}
	,insertFormattingContextRootElement: function(element) {
	}
	,insertContainerElement: function(element) {
	}
	,insertText: function(element) {
	}
	,insertSpace: function(element,isNextElementALineFeed) {
	}
	,insertHorizontalOffset: function(element) {
	}
	,insertTab: function(element,isNextElementALineFeed) {
	}
	,insertLineFeed: function(element) {
	}
	,insertFloat: function(element) {
	}
	,clearFloat: function(clear) {
		this._floatsManager.clearFloat(clear,this._formattingContextData);
	}
	,removeFloats: function() {
		this._floatsManager.removeFloats(this._formattingContextData.y);
	}
	,isNextElementALineFeed: function(elementsInFormattingContext,currentIndex) {
		var isNextElementALineFeed;
		if(currentIndex + 1 >= elementsInFormattingContext.length) isNextElementALineFeed = false; else isNextElementALineFeed = elementsInFormattingContext[currentIndex + 1].isLineFeed();
		return isNextElementALineFeed;
	}
	,getMaxWidth: function() {
		return this._formattingContextData.maxWidth;
	}
	,__class__: cocktail.core.style.formatter.FormattingContext
	,__properties__: {get_maxWidth:"getMaxWidth"}
}
cocktail.core.style.formatter.BlockFormattingContext = $hxClasses["cocktail.core.style.formatter.BlockFormattingContext"] = function(formattingContextRoot) {
	cocktail.core.style.formatter.FormattingContext.call(this,formattingContextRoot);
};
cocktail.core.style.formatter.BlockFormattingContext.__name__ = ["cocktail","core","style","formatter","BlockFormattingContext"];
cocktail.core.style.formatter.BlockFormattingContext.__super__ = cocktail.core.style.formatter.FormattingContext;
cocktail.core.style.formatter.BlockFormattingContext.prototype = $extend(cocktail.core.style.formatter.FormattingContext.prototype,{
	doFormat: function(elementsInFormattingContext) {
		this.doFormat2(this._formattingContextRoot,0);
	}
	,doFormat2: function(elementRenderer,concatenatedX) {
		var currentAddedSiblingsHeight = 0;
		concatenatedX += elementRenderer.getCoreStyle().getComputedStyle().marginLeft + elementRenderer.getCoreStyle().getComputedStyle().paddingLeft;
		var _g1 = 0, _g = elementRenderer.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = elementRenderer.get_childNodes()[i];
			var marginTop = child.getCoreStyle().getComputedStyle().marginTop;
			if(i == 0) {
				if(child.get_firstChild() != null) {
					var firstChild = child.get_firstChild();
					if(firstChild.getCoreStyle().getComputedStyle().marginTop > marginTop && child.getCoreStyle().getComputedStyle().paddingTop == 0) marginTop = firstChild.getCoreStyle().getComputedStyle().marginTop;
				}
			}
			if(child.hasChildNodes() == true) {
				if(child.establishesNewFormattingContext() == false) this.doFormat2(child,concatenatedX);
			}
			var marginBottom = this.getCollapsedMarginBottom(child);
			var x = concatenatedX + child.getCoreStyle().getComputedStyle().marginLeft;
			var y = this._formattingContextData.y + marginTop + elementRenderer.getCoreStyle().getComputedStyle().paddingTop;
			var computedStyle = child.getCoreStyle().getComputedStyle();
			var width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
			var height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
			child.setBounds({ x : x, y : y, width : width, height : height});
			this._formattingContextData.y += Math.round(child.getBounds().height) + marginTop + marginBottom;
			currentAddedSiblingsHeight += Math.round(child.getBounds().height) + marginTop + marginBottom;
		}
		this._formattingContextData.y -= currentAddedSiblingsHeight;
	}
	,getCollapsedMarginBottom: function(child) {
		var marginBottom = child.getCoreStyle().getComputedStyle().marginBottom;
		if(child.get_nextSibling() != null) {
			var nextSibling = child.get_nextSibling();
			if(nextSibling.getCoreStyle().getComputedStyle().marginTop > marginBottom) marginBottom = 0; else marginBottom -= nextSibling.getCoreStyle().getComputedStyle().marginTop;
		}
		return marginBottom;
	}
	,insertFloat: function(element) {
		var parent = element.get_parentNode();
		var floatData = this._floatsManager.computeFloatData(element,this._formattingContextData,Math.round(parent.getCoreStyle().getComputedStyle().width));
		var x = floatData.x + parent.getCoreStyle().getComputedStyle().paddingLeft;
		var y = floatData.y + parent.getCoreStyle().getComputedStyle().paddingTop;
		var width = floatData.width;
		var height = floatData.height;
		element.setBounds({ x : x, y : y, width : width, height : height});
	}
	,__class__: cocktail.core.style.formatter.BlockFormattingContext
});
cocktail.core.style.formatter.InlineFormattingContext = $hxClasses["cocktail.core.style.formatter.InlineFormattingContext"] = function(formattingContextRoot) {
	this._elementsInLineBox = new Array();
	this._unbreakableLineBoxElements = new Array();
	this._unbreakableWidth = 0;
	this._currentInlineBoxesData = new Array();
	cocktail.core.style.formatter.FormattingContext.call(this,formattingContextRoot);
};
cocktail.core.style.formatter.InlineFormattingContext.__name__ = ["cocktail","core","style","formatter","InlineFormattingContext"];
cocktail.core.style.formatter.InlineFormattingContext.__super__ = cocktail.core.style.formatter.FormattingContext;
cocktail.core.style.formatter.InlineFormattingContext.prototype = $extend(cocktail.core.style.formatter.FormattingContext.prototype,{
	_elementsInLineBox: null
	,_unbreakableLineBoxElements: null
	,_unbreakableWidth: null
	,_currentInlineBoxesData: null
	,dispose: function() {
		cocktail.core.style.formatter.FormattingContext.prototype.dispose.call(this);
		this._unbreakableLineBoxElements = null;
		this._elementsInLineBox = null;
		this._currentInlineBoxesData = null;
	}
	,doFormat: function(elementsInFormattingContext) {
		this._elementsInLineBox = new Array();
		this._unbreakableLineBoxElements = new Array();
		this._unbreakableWidth = 0;
		this._formattingContextRoot.removeLineBoxes();
		this._currentInlineBoxesData = new Array();
		cocktail.core.style.formatter.FormattingContext.prototype.doFormat.call(this,elementsInFormattingContext);
		this.insertBreakOpportunity(true,true);
	}
	,getRemainingLineWidth: function() {
		return this._formattingContextRoot.getCoreStyle().getComputedStyle().width - this._formattingContextData.x - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._formattingContextRoot.getCoreStyle().getComputedStyle().width);
	}
	,insertEmbeddedElement: function(element) {
		this.insertBreakOpportunity(false);
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(Math.round(element.getBounds().width));
		this.insertBreakOpportunity(false);
	}
	,insertFormattingContextRootElement: function(element) {
		var computedStyle = element.getCoreStyle().getComputedStyle();
		element.getBounds().width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		element.getBounds().height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
		this.insertBreakOpportunity(false);
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(Math.round(element.getBounds().width));
		this.insertBreakOpportunity(false);
	}
	,insertContainerElement: function(element) {
		this._unbreakableLineBoxElements.push(element);
	}
	,insertText: function(element) {
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(Math.round(element.getBounds().width));
	}
	,insertSpace: function(element,isNextElementALineFeed) {
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(Math.round(element.getBounds().width));
		this.insertBreakOpportunity(false);
	}
	,insertHorizontalOffset: function(element) {
	}
	,insertTab: function(element,isNextElementALineFeed) {
	}
	,insertLineFeed: function(element) {
	}
	,insertBreakOpportunity: function(forced,isLastLine) {
		if(isLastLine == null) isLastLine = false;
		var remainingLineWidth = this.getRemainingLineWidth();
		if(isLastLine == true) this.insertBreakOpportunity(false,false);
		if(remainingLineWidth - this._unbreakableWidth < 0 || forced == true) this.startNewLine(this._unbreakableWidth,isLastLine);
		var _g1 = 0, _g = this._unbreakableLineBoxElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox.push(this._unbreakableLineBoxElements[i]);
		}
		this._unbreakableLineBoxElements = new Array();
		this._formattingContextData.x += this._unbreakableWidth;
		this._unbreakableWidth = 0;
	}
	,addWidth: function(width) {
		this._unbreakableWidth += width;
	}
	,shouldTabBeConvertedToSpace: function(whiteSpace) {
		var shouldTabBeConvertedToSpace;
		switch( (whiteSpace)[1] ) {
		case 0:
		case 2:
		case 4:
			shouldTabBeConvertedToSpace = true;
			break;
		case 1:
		case 3:
			shouldTabBeConvertedToSpace = false;
			break;
		}
		return shouldTabBeConvertedToSpace;
	}
	,isLineFeedAllowed: function(whiteSpace) {
		var lineFeedAllowed;
		switch( (whiteSpace)[1] ) {
		case 0:
		case 2:
			lineFeedAllowed = false;
			break;
		case 1:
		case 3:
		case 4:
			lineFeedAllowed = true;
			break;
		}
		return lineFeedAllowed;
	}
	,shouldInsertSpace: function(whiteSpace,isNexElementALineFeed) {
		var shouldInsertSpace;
		switch( (whiteSpace)[1] ) {
		case 0:
		case 2:
		case 4:
			shouldInsertSpace = isNexElementALineFeed == false;
			break;
		case 3:
		case 1:
			shouldInsertSpace = true;
			break;
		}
		if(shouldInsertSpace == true) shouldInsertSpace != this.isCollapsed(this._lastInsertedElement,whiteSpace);
		return shouldInsertSpace;
	}
	,isCollapsed: function(lastInsertedElement,whiteSpace) {
		return false;
	}
	,getParentInlineBoxesData: function(parent) {
		var inlineBoxData = { element : parent, children : []};
		var flagFound = false;
		var _g1 = 0, _g = this._currentInlineBoxesData.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._currentInlineBoxesData[i].element == parent) {
				inlineBoxData = this._currentInlineBoxesData[i];
				flagFound = true;
			}
		}
		if(flagFound == false) this._currentInlineBoxesData.push(inlineBoxData);
		return inlineBoxData;
	}
	,startNewLine: function(elementWidth,isLastLine) {
		if(this._elementsInLineBox.length > 0) {
			this.removeSpaces();
			var lineBoxHeight = this.computeLineBoxHeight();
			var lineWidth = this.alignLineBox(isLastLine);
			if(lineWidth > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = lineWidth;
			var lineBoxElements = new Array();
			this._formattingContextRoot.addLineBox(lineBoxElements);
			var _g1 = 0, _g = this._elementsInLineBox.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._elementsInLineBox[i].get_parentNode() != this._formattingContextRoot.getCoreStyle().getElementRenderer()) this.getParentInlineBoxesData(this._elementsInLineBox[i].get_parentNode()).children.push(this._elementsInLineBox[i]); else lineBoxElements.push(this._elementsInLineBox[i]);
			}
			var _g1 = 0, _g = this._currentInlineBoxesData.length;
			while(_g1 < _g) {
				var i = _g1++;
				var _g3 = 0, _g2 = this._currentInlineBoxesData[i].children.length;
				while(_g3 < _g2) {
					var j = _g3++;
					lineBoxElements.push(this._currentInlineBoxesData[i].children[j]);
				}
			}
			var inlineBoxes = new Array();
			var _g1 = 0, _g = this._currentInlineBoxesData.length;
			while(_g1 < _g) {
				var i = _g1++;
				var inlineBoxRenderer = new cocktail.core.renderer.InlineBoxRenderer(this._currentInlineBoxesData[i].element.getCoreStyle());
				inlineBoxRenderer.setLayerRenderer(this._currentInlineBoxesData[i].element.getLayerRenderer());
				inlineBoxRenderer.setBounds(this.getBounds(this._currentInlineBoxesData[i].children));
				inlineBoxes.push(inlineBoxRenderer);
			}
			inlineBoxes.reverse();
			var _g1 = 0, _g = inlineBoxes.length;
			while(_g1 < _g) {
				var i = _g1++;
				lineBoxElements.push(inlineBoxes[i]);
			}
			this._currentInlineBoxesData = new Array();
			this._elementsInLineBox = new Array();
			if(isLastLine == false) {
				this._formattingContextData.y += lineBoxHeight;
				this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,elementWidth,this._formattingContextRoot.getCoreStyle().getComputedStyle().width);
				if(this._formattingContextData.y + lineBoxHeight > this._formattingContextData.maxHeight) this._formattingContextData.maxHeight = this._formattingContextData.y + lineBoxHeight;
				this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
			} else if(this._layOutLastLine == true) {
				this._formattingContextData.y += lineBoxHeight;
				this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,elementWidth,this._formattingContextRoot.getCoreStyle().getComputedStyle().width);
				if(this._formattingContextData.y > this._formattingContextData.maxHeight) this._formattingContextData.maxHeight = this._formattingContextData.y;
				this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
			}
		}
	}
	,removeSpaces: function() {
	}
	,alignLineBox: function(isLastLine) {
		var concatenatedLength = 0;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			concatenatedLength += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
		var remainingSpace;
		var flowX;
		remainingSpace = this._formattingContextRoot.getCoreStyle().getComputedStyle().width - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._formattingContextData.y) - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._formattingContextRoot.getCoreStyle().getComputedStyle().width);
		flowX = this._formattingContextRoot.getCoreStyle().getComputedStyle().paddingLeft;
		flowX += this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
		switch( (this._formattingContextRoot.getCoreStyle().getComputedStyle().textAlign)[1] ) {
		case 0:
			this.alignLeft(flowX);
			break;
		case 1:
			this.alignRight(flowX,remainingSpace);
			break;
		case 2:
			this.alignCenter(flowX,remainingSpace);
			break;
		case 3:
			if(isLastLine == true) this.alignLeft(flowX); else {
				concatenatedLength = this._formattingContextRoot.getCoreStyle().getComputedStyle().width;
				this.alignJustify(flowX,remainingSpace);
			}
			break;
		}
		return concatenatedLength;
	}
	,alignLeft: function(flowX) {
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = flowX;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
	}
	,alignCenter: function(flowX,remainingSpace) {
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = Math.round(remainingSpace / 2) + flowX;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
	}
	,alignRight: function(flowX,remainingSpace) {
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = flowX + remainingSpace;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
	}
	,alignJustify: function(flowX,remainingSpace) {
		var spacesNumber = 0;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._elementsInLineBox[i].isSpace() == true) spacesNumber++;
		}
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._elementsInLineBox[i].isSpace() == true) {
				var spaceWidth = Math.round(remainingSpace / spacesNumber);
				spacesNumber--;
				remainingSpace -= spaceWidth;
				flowX += spaceWidth;
			}
			this._elementsInLineBox[i].getBounds().x = flowX;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
	}
	,computeLineBoxHeight: function() {
		var lineBoxAscent = 0;
		var lineBoxDescent = 0;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var htmlElement = this._elementsInLineBox[i].getCoreStyle().get_htmlElement();
			var htmlElementAscent;
			var htmlElementDescent;
			var htmlElementVerticalAlign = htmlElement.get_coreStyle().getComputedStyle().verticalAlign;
			if(this._elementsInLineBox[i].isEmbedded() == true && this._elementsInLineBox[i].isText() == false || this._elementsInLineBox[i].establishesNewFormattingContext() == true) {
				htmlElementAscent = htmlElement.get_coreStyle().getComputedStyle().height + htmlElement.get_coreStyle().getComputedStyle().paddingTop + htmlElement.get_coreStyle().getComputedStyle().paddingBottom + this._elementsInLineBox[i].getCoreStyle().getComputedStyle().marginTop + this._elementsInLineBox[i].getCoreStyle().getComputedStyle().marginBottom;
				htmlElementDescent = 0;
				switch( (htmlElement.get_coreStyle().getVerticalAlign())[1] ) {
				case 3:
					htmlElementAscent = Math.round(lineBoxAscent);
					htmlElementDescent = Math.round(htmlElement.get_coreStyle().getComputedStyle().height + htmlElement.get_coreStyle().getComputedStyle().paddingTop + htmlElement.get_coreStyle().getComputedStyle().paddingBottom - lineBoxAscent);
					break;
				default:
				}
			} else {
				htmlElementAscent = htmlElement.get_coreStyle().getFontMetricsData().ascent;
				htmlElementDescent = htmlElement.get_coreStyle().getFontMetricsData().descent;
				var leading = htmlElement.get_coreStyle().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
				htmlElementAscent = Math.round(htmlElementAscent + leading / 2);
				htmlElementDescent = Math.round(htmlElementDescent + leading / 2);
			}
			if(htmlElementAscent - htmlElementVerticalAlign > lineBoxAscent) lineBoxAscent = htmlElementAscent - htmlElementVerticalAlign;
			if(htmlElementDescent + htmlElementVerticalAlign > lineBoxDescent) lineBoxDescent = htmlElementDescent + htmlElementVerticalAlign;
		}
		var lineBoxHeight = lineBoxAscent + lineBoxDescent;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var htmlElement = this._elementsInLineBox[i].getCoreStyle().get_htmlElement();
			var verticalAlign;
			switch( (htmlElement.get_coreStyle().getVerticalAlign())[1] ) {
			case 3:
				verticalAlign = 0;
				break;
			case 6:
				verticalAlign = 0;
				break;
			default:
				verticalAlign = htmlElement.get_coreStyle().getComputedStyle().verticalAlign;
			}
			this._elementsInLineBox[i].getBounds().y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + this._formattingContextData.y + this._formattingContextRoot.getCoreStyle().getComputedStyle().paddingTop;
			if(this._elementsInLineBox[i].isEmbedded() == true && this._elementsInLineBox[i].isText() == false || this._elementsInLineBox[i].establishesNewFormattingContext() == true) {
				switch( (htmlElement.get_coreStyle().getVerticalAlign())[1] ) {
				case 3:
					this._elementsInLineBox[i].getBounds().y = this._formattingContextData.y;
					break;
				default:
					this._elementsInLineBox[i].getBounds().y -= htmlElement.get_coreStyle().getComputedStyle().height + htmlElement.get_coreStyle().getComputedStyle().paddingTop + htmlElement.get_coreStyle().getComputedStyle().paddingBottom + this._elementsInLineBox[i].getCoreStyle().getComputedStyle().marginTop + this._elementsInLineBox[i].getCoreStyle().getComputedStyle().marginBottom;
				}
			}
		}
		return Math.round(lineBoxHeight);
	}
	,__class__: cocktail.core.style.formatter.InlineFormattingContext
});
if(!cocktail.core.style.positioner) cocktail.core.style.positioner = {}
cocktail.core.style.positioner.BoxPositioner = $hxClasses["cocktail.core.style.positioner.BoxPositioner"] = function() {
};
cocktail.core.style.positioner.BoxPositioner.__name__ = ["cocktail","core","style","positioner","BoxPositioner"];
cocktail.core.style.positioner.BoxPositioner.prototype = {
	position: function(elementRenderer,containingHTMLElementData,staticPosition) {
		var htmlElement = elementRenderer.getCoreStyle().get_htmlElement();
		if(htmlElement.get_coreStyle().getLeft() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getLeftOffset(htmlElement,Math.round(staticPosition.x)); else if(htmlElement.get_coreStyle().getRight() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getRightOffset(htmlElement,containingHTMLElementData.width,Math.round(staticPosition.x)); else elementRenderer.getBounds().x = Math.round(staticPosition.x);
		if(htmlElement.get_coreStyle().getTop() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getTopOffset(htmlElement,Math.round(staticPosition.y)); else if(htmlElement.get_coreStyle().getBottom() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getBottomOffset(htmlElement,containingHTMLElementData.height,Math.round(staticPosition.y)); else elementRenderer.getBounds().y = Math.round(staticPosition.y);
		return elementRenderer;
	}
	,getLeftOffset: function(htmlElement,staticPosition) {
		return htmlElement.get_coreStyle().getComputedStyle().left;
	}
	,getRightOffset: function(htmlElement,containingHTMLElementWidth,staticPosition) {
		return containingHTMLElementWidth - htmlElement.get_coreStyle().getComputedStyle().width + htmlElement.get_coreStyle().getComputedStyle().paddingLeft + htmlElement.get_coreStyle().getComputedStyle().width - htmlElement.get_coreStyle().getComputedStyle().right;
	}
	,getTopOffset: function(htmlElement,staticPosition) {
		return htmlElement.get_coreStyle().getComputedStyle().top;
	}
	,getBottomOffset: function(htmlElement,containingHTMLElementHeight,staticPosition) {
		return containingHTMLElementHeight - htmlElement.get_coreStyle().getComputedStyle().height + htmlElement.get_coreStyle().getComputedStyle().paddingTop + htmlElement.get_coreStyle().getComputedStyle().paddingBottom - htmlElement.get_coreStyle().getComputedStyle().bottom;
	}
	,__class__: cocktail.core.style.positioner.BoxPositioner
}
cocktail.core.style.positioner.AbsolutePositioner = $hxClasses["cocktail.core.style.positioner.AbsolutePositioner"] = function() {
	cocktail.core.style.positioner.BoxPositioner.call(this);
};
cocktail.core.style.positioner.AbsolutePositioner.__name__ = ["cocktail","core","style","positioner","AbsolutePositioner"];
cocktail.core.style.positioner.AbsolutePositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
cocktail.core.style.positioner.AbsolutePositioner.prototype = $extend(cocktail.core.style.positioner.BoxPositioner.prototype,{
	__class__: cocktail.core.style.positioner.AbsolutePositioner
});
cocktail.core.style.positioner.FixedPositioner = $hxClasses["cocktail.core.style.positioner.FixedPositioner"] = function() {
	cocktail.core.style.positioner.BoxPositioner.call(this);
};
cocktail.core.style.positioner.FixedPositioner.__name__ = ["cocktail","core","style","positioner","FixedPositioner"];
cocktail.core.style.positioner.FixedPositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
cocktail.core.style.positioner.FixedPositioner.prototype = $extend(cocktail.core.style.positioner.BoxPositioner.prototype,{
	__class__: cocktail.core.style.positioner.FixedPositioner
});
cocktail.core.style.positioner.RelativePositioner = $hxClasses["cocktail.core.style.positioner.RelativePositioner"] = function() {
	cocktail.core.style.positioner.BoxPositioner.call(this);
};
cocktail.core.style.positioner.RelativePositioner.__name__ = ["cocktail","core","style","positioner","RelativePositioner"];
cocktail.core.style.positioner.RelativePositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
cocktail.core.style.positioner.RelativePositioner.prototype = $extend(cocktail.core.style.positioner.BoxPositioner.prototype,{
	getLeftOffset: function(htmlElement,staticPosition) {
		return staticPosition + htmlElement.get_coreStyle().getComputedStyle().left;
	}
	,getRightOffset: function(htmlElement,containingHTMLElementWidth,staticPosition) {
		return staticPosition - htmlElement.get_coreStyle().getComputedStyle().right;
	}
	,getTopOffset: function(htmlElement,staticPosition) {
		return staticPosition + htmlElement.get_coreStyle().getComputedStyle().top;
	}
	,getBottomOffset: function(htmlElement,containingHTMLElementHeight,staticPosition) {
		return staticPosition - htmlElement.get_coreStyle().getComputedStyle().bottom;
	}
	,__class__: cocktail.core.style.positioner.RelativePositioner
});
if(!cocktail.core.unit) cocktail.core.unit = {}
cocktail.core.unit.Length = $hxClasses["cocktail.core.unit.Length"] = { __ename__ : ["cocktail","core","unit","Length"], __constructs__ : ["px","cm","mm","pt","pc","cssIn","em","ex"] }
cocktail.core.unit.Length.px = function(value) { var $x = ["px",0,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.cm = function(value) { var $x = ["cm",1,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.mm = function(value) { var $x = ["mm",2,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.pt = function(value) { var $x = ["pt",3,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.pc = function(value) { var $x = ["pc",4,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.cssIn = function(value) { var $x = ["cssIn",5,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.em = function(value) { var $x = ["em",6,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.ex = function(value) { var $x = ["ex",7,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.FontSizeAbsoluteSize = $hxClasses["cocktail.core.unit.FontSizeAbsoluteSize"] = { __ename__ : ["cocktail","core","unit","FontSizeAbsoluteSize"], __constructs__ : ["xxSmall","xSmall","small","medium","large","xLarge","xxLarge"] }
cocktail.core.unit.FontSizeAbsoluteSize.xxSmall = ["xxSmall",0];
cocktail.core.unit.FontSizeAbsoluteSize.xxSmall.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.xxSmall.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.xSmall = ["xSmall",1];
cocktail.core.unit.FontSizeAbsoluteSize.xSmall.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.xSmall.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.small = ["small",2];
cocktail.core.unit.FontSizeAbsoluteSize.small.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.small.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.medium = ["medium",3];
cocktail.core.unit.FontSizeAbsoluteSize.medium.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.medium.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.large = ["large",4];
cocktail.core.unit.FontSizeAbsoluteSize.large.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.large.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.xLarge = ["xLarge",5];
cocktail.core.unit.FontSizeAbsoluteSize.xLarge.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.xLarge.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeAbsoluteSize.xxLarge = ["xxLarge",6];
cocktail.core.unit.FontSizeAbsoluteSize.xxLarge.toString = $estr;
cocktail.core.unit.FontSizeAbsoluteSize.xxLarge.__enum__ = cocktail.core.unit.FontSizeAbsoluteSize;
cocktail.core.unit.FontSizeRelativeSize = $hxClasses["cocktail.core.unit.FontSizeRelativeSize"] = { __ename__ : ["cocktail","core","unit","FontSizeRelativeSize"], __constructs__ : ["larger","smaller"] }
cocktail.core.unit.FontSizeRelativeSize.larger = ["larger",0];
cocktail.core.unit.FontSizeRelativeSize.larger.toString = $estr;
cocktail.core.unit.FontSizeRelativeSize.larger.__enum__ = cocktail.core.unit.FontSizeRelativeSize;
cocktail.core.unit.FontSizeRelativeSize.smaller = ["smaller",1];
cocktail.core.unit.FontSizeRelativeSize.smaller.toString = $estr;
cocktail.core.unit.FontSizeRelativeSize.smaller.__enum__ = cocktail.core.unit.FontSizeRelativeSize;
cocktail.core.unit.CSSColor = $hxClasses["cocktail.core.unit.CSSColor"] = { __ename__ : ["cocktail","core","unit","CSSColor"], __constructs__ : ["rgb","rgba","hex","keyword","transparent"] }
cocktail.core.unit.CSSColor.rgb = function(red,green,blue) { var $x = ["rgb",0,red,green,blue]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.rgba = function(red,green,blue,alpha) { var $x = ["rgba",1,red,green,blue,alpha]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.hex = function(value) { var $x = ["hex",2,value]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.keyword = function(value) { var $x = ["keyword",3,value]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.transparent = ["transparent",4];
cocktail.core.unit.CSSColor.transparent.toString = $estr;
cocktail.core.unit.CSSColor.transparent.__enum__ = cocktail.core.unit.CSSColor;
cocktail.core.unit.ImageValue = $hxClasses["cocktail.core.unit.ImageValue"] = { __ename__ : ["cocktail","core","unit","ImageValue"], __constructs__ : ["url","imageList","gradient"] }
cocktail.core.unit.ImageValue.url = function(value) { var $x = ["url",0,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.ImageValue.imageList = function(value) { var $x = ["imageList",1,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.ImageValue.gradient = function(value) { var $x = ["gradient",2,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientValue = $hxClasses["cocktail.core.unit.GradientValue"] = { __ename__ : ["cocktail","core","unit","GradientValue"], __constructs__ : ["linear"] }
cocktail.core.unit.GradientValue.linear = function(value) { var $x = ["linear",0,value]; $x.__enum__ = cocktail.core.unit.GradientValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientStopValue = $hxClasses["cocktail.core.unit.GradientStopValue"] = { __ename__ : ["cocktail","core","unit","GradientStopValue"], __constructs__ : ["length","percent"] }
cocktail.core.unit.GradientStopValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientStopValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle = $hxClasses["cocktail.core.unit.GradientAngle"] = { __ename__ : ["cocktail","core","unit","GradientAngle"], __constructs__ : ["angle","side","corner"] }
cocktail.core.unit.GradientAngle.angle = function(value) { var $x = ["angle",0,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle.side = function(value) { var $x = ["side",1,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle.corner = function(value) { var $x = ["corner",2,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientSideValue = $hxClasses["cocktail.core.unit.GradientSideValue"] = { __ename__ : ["cocktail","core","unit","GradientSideValue"], __constructs__ : ["top","left","bottom","right"] }
cocktail.core.unit.GradientSideValue.top = ["top",0];
cocktail.core.unit.GradientSideValue.top.toString = $estr;
cocktail.core.unit.GradientSideValue.top.__enum__ = cocktail.core.unit.GradientSideValue;
cocktail.core.unit.GradientSideValue.left = ["left",1];
cocktail.core.unit.GradientSideValue.left.toString = $estr;
cocktail.core.unit.GradientSideValue.left.__enum__ = cocktail.core.unit.GradientSideValue;
cocktail.core.unit.GradientSideValue.bottom = ["bottom",2];
cocktail.core.unit.GradientSideValue.bottom.toString = $estr;
cocktail.core.unit.GradientSideValue.bottom.__enum__ = cocktail.core.unit.GradientSideValue;
cocktail.core.unit.GradientSideValue.right = ["right",3];
cocktail.core.unit.GradientSideValue.right.toString = $estr;
cocktail.core.unit.GradientSideValue.right.__enum__ = cocktail.core.unit.GradientSideValue;
cocktail.core.unit.GradientCornerValue = $hxClasses["cocktail.core.unit.GradientCornerValue"] = { __ename__ : ["cocktail","core","unit","GradientCornerValue"], __constructs__ : ["topRight","bottomRight","bottomLeft","topLeft"] }
cocktail.core.unit.GradientCornerValue.topRight = ["topRight",0];
cocktail.core.unit.GradientCornerValue.topRight.toString = $estr;
cocktail.core.unit.GradientCornerValue.topRight.__enum__ = cocktail.core.unit.GradientCornerValue;
cocktail.core.unit.GradientCornerValue.bottomRight = ["bottomRight",1];
cocktail.core.unit.GradientCornerValue.bottomRight.toString = $estr;
cocktail.core.unit.GradientCornerValue.bottomRight.__enum__ = cocktail.core.unit.GradientCornerValue;
cocktail.core.unit.GradientCornerValue.bottomLeft = ["bottomLeft",2];
cocktail.core.unit.GradientCornerValue.bottomLeft.toString = $estr;
cocktail.core.unit.GradientCornerValue.bottomLeft.__enum__ = cocktail.core.unit.GradientCornerValue;
cocktail.core.unit.GradientCornerValue.topLeft = ["topLeft",3];
cocktail.core.unit.GradientCornerValue.topLeft.toString = $estr;
cocktail.core.unit.GradientCornerValue.topLeft.__enum__ = cocktail.core.unit.GradientCornerValue;
cocktail.core.unit.ColorKeyword = $hxClasses["cocktail.core.unit.ColorKeyword"] = { __ename__ : ["cocktail","core","unit","ColorKeyword"], __constructs__ : ["aqua","black","blue","fuchsia","gray","green","lime","maroon","navy","olive","orange","purple","red","silver","teal","white","yellow"] }
cocktail.core.unit.ColorKeyword.aqua = ["aqua",0];
cocktail.core.unit.ColorKeyword.aqua.toString = $estr;
cocktail.core.unit.ColorKeyword.aqua.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.black = ["black",1];
cocktail.core.unit.ColorKeyword.black.toString = $estr;
cocktail.core.unit.ColorKeyword.black.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.blue = ["blue",2];
cocktail.core.unit.ColorKeyword.blue.toString = $estr;
cocktail.core.unit.ColorKeyword.blue.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.fuchsia = ["fuchsia",3];
cocktail.core.unit.ColorKeyword.fuchsia.toString = $estr;
cocktail.core.unit.ColorKeyword.fuchsia.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.gray = ["gray",4];
cocktail.core.unit.ColorKeyword.gray.toString = $estr;
cocktail.core.unit.ColorKeyword.gray.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.green = ["green",5];
cocktail.core.unit.ColorKeyword.green.toString = $estr;
cocktail.core.unit.ColorKeyword.green.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.lime = ["lime",6];
cocktail.core.unit.ColorKeyword.lime.toString = $estr;
cocktail.core.unit.ColorKeyword.lime.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.maroon = ["maroon",7];
cocktail.core.unit.ColorKeyword.maroon.toString = $estr;
cocktail.core.unit.ColorKeyword.maroon.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.navy = ["navy",8];
cocktail.core.unit.ColorKeyword.navy.toString = $estr;
cocktail.core.unit.ColorKeyword.navy.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.olive = ["olive",9];
cocktail.core.unit.ColorKeyword.olive.toString = $estr;
cocktail.core.unit.ColorKeyword.olive.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.orange = ["orange",10];
cocktail.core.unit.ColorKeyword.orange.toString = $estr;
cocktail.core.unit.ColorKeyword.orange.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.purple = ["purple",11];
cocktail.core.unit.ColorKeyword.purple.toString = $estr;
cocktail.core.unit.ColorKeyword.purple.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.red = ["red",12];
cocktail.core.unit.ColorKeyword.red.toString = $estr;
cocktail.core.unit.ColorKeyword.red.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.silver = ["silver",13];
cocktail.core.unit.ColorKeyword.silver.toString = $estr;
cocktail.core.unit.ColorKeyword.silver.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.teal = ["teal",14];
cocktail.core.unit.ColorKeyword.teal.toString = $estr;
cocktail.core.unit.ColorKeyword.teal.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.white = ["white",15];
cocktail.core.unit.ColorKeyword.white.toString = $estr;
cocktail.core.unit.ColorKeyword.white.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.ColorKeyword.yellow = ["yellow",16];
cocktail.core.unit.ColorKeyword.yellow.toString = $estr;
cocktail.core.unit.ColorKeyword.yellow.__enum__ = cocktail.core.unit.ColorKeyword;
cocktail.core.unit.Angle = $hxClasses["cocktail.core.unit.Angle"] = { __ename__ : ["cocktail","core","unit","Angle"], __constructs__ : ["deg","grad","rad","turn"] }
cocktail.core.unit.Angle.deg = function(value) { var $x = ["deg",0,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.grad = function(value) { var $x = ["grad",1,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.rad = function(value) { var $x = ["rad",2,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.turn = function(value) { var $x = ["turn",3,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.UnitManager = $hxClasses["cocktail.core.unit.UnitManager"] = function() {
};
cocktail.core.unit.UnitManager.__name__ = ["cocktail","core","unit","UnitManager"];
cocktail.core.unit.UnitManager.boxStyleEnum = function(enumType,string) {
	if(string == "auto") return Type.createEnum(enumType,"cssAuto");
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	return (function($this) {
		var $r;
		switch(parsed.unit) {
		case "%":
			$r = Type.createEnum(enumType,"percent",[Std.parseInt(parsed.value)]);
			break;
		default:
			$r = Type.createEnum(enumType,"length",[cocktail.core.unit.UnitManager.string2Length(parsed)]);
		}
		return $r;
	}(this));
}
cocktail.core.unit.UnitManager.constrainedDimensionEnum = function(string) {
	if(string == "none") return cocktail.core.style.ConstrainedDimension.none;
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	var constrainedDimension;
	switch(parsed.unit) {
	case "%":
		constrainedDimension = cocktail.core.style.ConstrainedDimension.percent(Std.parseInt(parsed.value));
		break;
	default:
		constrainedDimension = cocktail.core.style.ConstrainedDimension.length(cocktail.core.unit.UnitManager.string2Length(parsed));
	}
	return constrainedDimension;
}
cocktail.core.unit.UnitManager.displayEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var display;
	switch(parsed) {
	case "inline":
		display = cocktail.core.style.Display.cssInline;
		break;
	case "block":
		display = cocktail.core.style.Display.block;
		break;
	case "inline-block":
		display = cocktail.core.style.Display.inlineBlock;
		break;
	case "none":
		display = cocktail.core.style.Display.none;
		break;
	default:
		display = null;
	}
	return display;
}
cocktail.core.unit.UnitManager.overflowEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var overflow;
	switch(parsed) {
	case "visible":
		overflow = cocktail.core.style.Overflow.visible;
		break;
	case "scroll":
		overflow = cocktail.core.style.Overflow.scroll;
		break;
	case "auto":
		overflow = cocktail.core.style.Overflow.cssAuto;
		break;
	case "hidden":
		overflow = cocktail.core.style.Overflow.hidden;
		break;
	default:
		overflow = null;
	}
	return overflow;
}
cocktail.core.unit.UnitManager.verticalAlignEnum = function(string) {
	string = cocktail.core.unit.UnitManager.trim(string);
	var verticalAlign;
	switch(string) {
	case "baseline":
		verticalAlign = cocktail.core.style.VerticalAlign.baseline;
		break;
	case "bottom":
		verticalAlign = cocktail.core.style.VerticalAlign.bottom;
		break;
	case "super":
		verticalAlign = cocktail.core.style.VerticalAlign.cssSuper;
		break;
	case "middle":
		verticalAlign = cocktail.core.style.VerticalAlign.middle;
		break;
	case "top":
		verticalAlign = cocktail.core.style.VerticalAlign.top;
		break;
	case "textBottom":
		verticalAlign = cocktail.core.style.VerticalAlign.textBottom;
		break;
	case "textTop":
		verticalAlign = cocktail.core.style.VerticalAlign.textTop;
		break;
	case "sub":
		verticalAlign = cocktail.core.style.VerticalAlign.sub;
		break;
	default:
		verticalAlign = null;
	}
	if(verticalAlign == null) {
		var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
		switch(parsed.unit) {
		case "%":
			verticalAlign = cocktail.core.style.VerticalAlign.percent(Std.parseInt(parsed.value));
			break;
		default:
			verticalAlign = cocktail.core.style.VerticalAlign.length(cocktail.core.unit.UnitManager.string2Length(parsed));
		}
	}
	return verticalAlign;
}
cocktail.core.unit.UnitManager.clearEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var clear;
	switch(parsed) {
	case "both":
		clear = cocktail.core.style.Clear.both;
		break;
	case "left":
		clear = cocktail.core.style.Clear.left;
		break;
	case "right":
		clear = cocktail.core.style.Clear.right;
		break;
	case "none":
		clear = cocktail.core.style.Clear.none;
		break;
	default:
		clear = null;
	}
	return clear;
}
cocktail.core.unit.UnitManager.positionEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var position;
	switch(parsed) {
	case "static":
		position = cocktail.core.style.Position.cssStatic;
		break;
	case "absolute":
		position = cocktail.core.style.Position.absolute;
		break;
	case "relative":
		position = cocktail.core.style.Position.relative;
		break;
	case "fixed":
		position = cocktail.core.style.Position.fixed;
		break;
	default:
		position = null;
	}
	return position;
}
cocktail.core.unit.UnitManager.whiteSpaceEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var whiteSpace;
	switch(parsed) {
	case "normal":
		whiteSpace = cocktail.core.style.WhiteSpace.normal;
		break;
	case "nowrap":
		whiteSpace = cocktail.core.style.WhiteSpace.nowrap;
		break;
	case "pre":
		whiteSpace = cocktail.core.style.WhiteSpace.pre;
		break;
	case "preLine":
		whiteSpace = cocktail.core.style.WhiteSpace.preLine;
		break;
	case "preWrap":
		whiteSpace = cocktail.core.style.WhiteSpace.preWrap;
		break;
	default:
		whiteSpace = null;
	}
	return whiteSpace;
}
cocktail.core.unit.UnitManager.textAlignEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var textAlign;
	switch(parsed) {
	case "left":
		textAlign = cocktail.core.style.TextAlign.left;
		break;
	case "right":
		textAlign = cocktail.core.style.TextAlign.right;
		break;
	case "center":
		textAlign = cocktail.core.style.TextAlign.center;
		break;
	case "justify":
		textAlign = cocktail.core.style.TextAlign.justify;
		break;
	default:
		textAlign = null;
	}
	return textAlign;
}
cocktail.core.unit.UnitManager.fontWeightEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var fontWeight;
	switch(parsed) {
	case "bold":
		fontWeight = cocktail.core.style.FontWeight.bold;
		break;
	case "bolder":
		fontWeight = cocktail.core.style.FontWeight.bolder;
		break;
	case "normal":
		fontWeight = cocktail.core.style.FontWeight.normal;
		break;
	case "lighter":
		fontWeight = cocktail.core.style.FontWeight.lighter;
		break;
	case "100":
		fontWeight = cocktail.core.style.FontWeight.css100;
		break;
	case "200":
		fontWeight = cocktail.core.style.FontWeight.css200;
		break;
	case "300":
		fontWeight = cocktail.core.style.FontWeight.css300;
		break;
	case "400":
		fontWeight = cocktail.core.style.FontWeight.css400;
		break;
	case "500":
		fontWeight = cocktail.core.style.FontWeight.css500;
		break;
	case "600":
		fontWeight = cocktail.core.style.FontWeight.css600;
		break;
	case "700":
		fontWeight = cocktail.core.style.FontWeight.css700;
		break;
	case "800":
		fontWeight = cocktail.core.style.FontWeight.css800;
		break;
	case "900":
		fontWeight = cocktail.core.style.FontWeight.css900;
		break;
	default:
		fontWeight = null;
	}
	return fontWeight;
}
cocktail.core.unit.UnitManager.fontStyleEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var fontStyle;
	switch(parsed) {
	case "italic":
		fontStyle = cocktail.core.style.FontStyle.italic;
		break;
	case "normal":
		fontStyle = cocktail.core.style.FontStyle.normal;
		break;
	default:
		fontStyle = null;
	}
	return fontStyle;
}
cocktail.core.unit.UnitManager.fontVariantEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var fontVariant;
	switch(parsed) {
	case "normal":
		fontVariant = cocktail.core.style.FontVariant.normal;
		break;
	case "small-caps":
		fontVariant = cocktail.core.style.FontVariant.smallCaps;
		break;
	default:
		fontVariant = null;
	}
	return fontVariant;
}
cocktail.core.unit.UnitManager.textTransformEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var textTransform;
	switch(parsed) {
	case "capitalize":
		textTransform = cocktail.core.style.TextTransform.capitalize;
		break;
	case "lowercase":
		textTransform = cocktail.core.style.TextTransform.lowercase;
		break;
	case "uppercase":
		textTransform = cocktail.core.style.TextTransform.uppercase;
		break;
	case "none":
		textTransform = cocktail.core.style.TextTransform.none;
		break;
	default:
		textTransform = null;
	}
	return textTransform;
}
cocktail.core.unit.UnitManager.visibilityEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var visibility;
	switch(parsed) {
	case "hidden":
		visibility = cocktail.core.style.Visibility.hidden;
		break;
	case "visible":
		visibility = cocktail.core.style.Visibility.visible;
		break;
	default:
		visibility = null;
	}
	return visibility;
}
cocktail.core.unit.UnitManager.cursorEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var cursor;
	switch(parsed) {
	case "auto":
		cursor = cocktail.core.style.Cursor.cssAuto;
		break;
	case "crosshair":
		cursor = cocktail.core.style.Cursor.crosshair;
		break;
	case "pointer":
		cursor = cocktail.core.style.Cursor.pointer;
		break;
	case "default":
		cursor = cocktail.core.style.Cursor.cssDefault;
		break;
	default:
		cursor = null;
	}
	return cursor;
}
cocktail.core.unit.UnitManager.wordSpacingEnum = function(string) {
	if(string == "normal") return cocktail.core.style.WordSpacing.normal;
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	var wordSpacing;
	switch(parsed.unit) {
	case "%":
		wordSpacing = null;
		break;
	default:
		wordSpacing = cocktail.core.style.WordSpacing.length(cocktail.core.unit.UnitManager.string2Length(parsed));
	}
	return wordSpacing;
}
cocktail.core.unit.UnitManager.backgroundImageEnum = function(string) {
	if(string == "none") return [cocktail.core.style.BackgroundImage.none];
	var array = cocktail.core.unit.UnitManager.string2VList(string,",");
	var arrayBgImg = [];
	var _g = 0;
	while(_g < array.length) {
		var val = array[_g];
		++_g;
		if(val == "none") arrayBgImg.push(cocktail.core.style.BackgroundImage.none); else arrayBgImg.push(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url(cocktail.core.unit.UnitManager.string2URLData(val))));
	}
	return arrayBgImg;
}
cocktail.core.unit.UnitManager.backgroundRepeatEnum = function(string) {
	return [];
}
cocktail.core.unit.UnitManager.backgroundOriginEnum = function(string) {
	return [];
}
cocktail.core.unit.UnitManager.backgroundSizeEnum = function(string) {
	return [];
}
cocktail.core.unit.UnitManager.backgroundPositionEnum = function(string) {
	return [];
}
cocktail.core.unit.UnitManager.backgroundClipEnum = function(string) {
	return [];
}
cocktail.core.unit.UnitManager.fontFamilyEnum = function(string) {
	return cocktail.core.unit.UnitManager.string2Array(string);
}
cocktail.core.unit.UnitManager.letterSpacingEnum = function(string) {
	if(string == "normal") return cocktail.core.style.LetterSpacing.normal;
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	var letterSpacing;
	switch(parsed.unit) {
	case "%":
		letterSpacing = null;
		break;
	default:
		letterSpacing = cocktail.core.style.LetterSpacing.length(cocktail.core.unit.UnitManager.string2Length(parsed));
	}
	return letterSpacing;
}
cocktail.core.unit.UnitManager.lineHeightEnum = function(string) {
	if(string == "normal") return cocktail.core.style.LineHeight.normal;
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	var lineHeight;
	switch(parsed.unit) {
	case "%":
		lineHeight = cocktail.core.style.LineHeight.percentage(Std.parseInt(parsed.value));
		break;
	default:
		lineHeight = cocktail.core.style.LineHeight.length(cocktail.core.unit.UnitManager.string2Length(parsed));
	}
	return lineHeight;
}
cocktail.core.unit.UnitManager.textIndentEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.string2VUnit(string);
	var textIndent;
	switch(parsed.unit) {
	case "%":
		textIndent = cocktail.core.style.TextIndent.percentage(Std.parseInt(parsed.value));
		break;
	default:
		textIndent = cocktail.core.style.TextIndent.length(cocktail.core.unit.UnitManager.string2Length(parsed));
	}
	return textIndent;
}
cocktail.core.unit.UnitManager.cssFloatEnum = function(string) {
	var parsed = cocktail.core.unit.UnitManager.trim(string);
	var cssFloat;
	switch(parsed) {
	case "left":
		cssFloat = cocktail.core.style.CSSFloat.left;
		break;
	case "right":
		cssFloat = cocktail.core.style.CSSFloat.right;
		break;
	case "none":
		cssFloat = cocktail.core.style.CSSFloat.none;
		break;
	default:
		cssFloat = null;
	}
	return cssFloat;
}
cocktail.core.unit.UnitManager.colorEnum = function(string) {
	string = cocktail.core.unit.UnitManager.trim(string);
	if(StringTools.startsWith(string,"#")) return cocktail.core.unit.CSSColor.hex(string.substr(1));
	if(StringTools.startsWith(string,"rgba")) {
		var vcol = cocktail.core.unit.UnitManager.string2RGBA(string);
		return cocktail.core.unit.CSSColor.rgba(vcol.r,vcol.g,vcol.b,vcol.a);
	}
	if(StringTools.startsWith(string,"rgb")) {
		var vcol = cocktail.core.unit.UnitManager.string2RGB(string);
		return cocktail.core.unit.CSSColor.rgb(vcol.r,vcol.g,vcol.b);
	}
	return (function($this) {
		var $r;
		switch(string) {
		case "transparent":
			$r = cocktail.core.unit.CSSColor.transparent;
			break;
		case "aqua":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.aqua);
			break;
		case "black":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.black);
			break;
		case "blue":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.blue);
			break;
		case "fuchsia":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.fuchsia);
			break;
		case "gray":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.gray);
			break;
		case "green":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.green);
			break;
		case "lime":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.lime);
			break;
		case "maroon":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.maroon);
			break;
		case "navy":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.navy);
			break;
		case "olive":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.olive);
			break;
		case "orange":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.orange);
			break;
		case "purple":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.purple);
			break;
		case "red":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.red);
			break;
		case "silver":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.silver);
			break;
		case "teal":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.teal);
			break;
		case "white":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.white);
			break;
		case "yellow":
			$r = cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.yellow);
			break;
		default:
			$r = (function($this) {
				var $r;
				throw "unknown color \"" + string + "\"";
				return $r;
			}($this));
		}
		return $r;
	}(this));
}
cocktail.core.unit.UnitManager.string2RGBA = function(string) {
	string = string.substr(5,string.length - 6);
	var rgba = string.split(",");
	while(rgba.length < 4) rgba.push("0");
	return { r : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[0])), g : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[1])), b : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[2])), a : Std.parseFloat(cocktail.core.unit.UnitManager.trim(rgba[3]))};
}
cocktail.core.unit.UnitManager.string2RGB = function(string) {
	string = string.substr(4,string.length - 5);
	var rgba = string.split(",");
	while(rgba.length < 3) rgba.push("0");
	return { r : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[0])), g : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[1])), b : Std.parseInt(cocktail.core.unit.UnitManager.trim(rgba[2])), a : null};
}
cocktail.core.unit.UnitManager.trim = function(string) {
	return StringTools.ltrim(StringTools.rtrim(string));
}
cocktail.core.unit.UnitManager.string2VUnit = function(string) {
	var r = new EReg("([0-9]*)(.*)","");
	r.match(string);
	return { value : r.matched(1), unit : cocktail.core.unit.UnitManager.trim(r.matched(2))};
}
cocktail.core.unit.UnitManager.string2Length = function(parsed) {
	return (function($this) {
		var $r;
		switch(parsed.unit) {
		case "in":
			$r = cocktail.core.unit.Length.cssIn(Std.parseInt(parsed.value));
			break;
		case "cm":
			$r = cocktail.core.unit.Length.cm(Std.parseInt(parsed.value));
			break;
		case "em":
			$r = cocktail.core.unit.Length.em(Std.parseInt(parsed.value));
			break;
		case "ex":
			$r = cocktail.core.unit.Length.ex(Std.parseInt(parsed.value));
			break;
		case "mm":
			$r = cocktail.core.unit.Length.mm(Std.parseInt(parsed.value));
			break;
		case "pc":
			$r = cocktail.core.unit.Length.pc(Std.parseInt(parsed.value));
			break;
		case "pt":
			$r = cocktail.core.unit.Length.pt(Std.parseInt(parsed.value));
			break;
		case "px":
			$r = cocktail.core.unit.Length.px(Std.parseInt(parsed.value));
			break;
		case "":
			$r = (function($this) {
				var $r;
				var v = Std.parseInt(parsed.value);
				$r = v == 0?cocktail.core.unit.Length.px(v):(function($this) {
					var $r;
					throw "Bad unit \"" + parsed.unit + "\"";
					return $r;
				}($this));
				return $r;
			}($this));
			break;
		default:
			$r = (function($this) {
				var $r;
				throw "Bad unit \"" + parsed.unit + "\"";
				return $r;
			}($this));
		}
		return $r;
	}(this));
}
cocktail.core.unit.UnitManager.string2URLData = function(string) {
	string = cocktail.core.unit.UnitManager.trim(string);
	string = cocktail.core.unit.UnitManager.trim(string.substr(4,string.length - 5));
	if(StringTools.startsWith(string,"\"")) string = string.substr(1);
	if(StringTools.endsWith(string,"\"")) string = string.substr(0,string.length - 1);
	return string;
}
cocktail.core.unit.UnitManager.string2VList = function(string,sep) {
	if(sep == null) sep = " ";
	if(sep == " ") string = new EReg("[ ]{2,}","g").replace(string," "); else string = StringTools.replace(string," ","");
	string = cocktail.core.unit.UnitManager.trim(string);
	var array = string.split(sep);
	return array;
}
cocktail.core.unit.UnitManager.string2Array = function(string) {
	var r = new EReg("[ \"]*[,\"][ \"]*","g");
	var res = r.split(string);
	if(res[0] == "") res.shift();
	return res;
}
cocktail.core.unit.UnitManager.getPixelFromLength = function(length,emReference,exReference) {
	var lengthValue;
	var $e = (length);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		lengthValue = value;
		break;
	case 2:
		var value = $e[2];
		lengthValue = value * (72 * (1 / 0.75) / 2.54) / 10;
		break;
	case 1:
		var value = $e[2];
		lengthValue = value * (72 * (1 / 0.75) / 2.54);
		break;
	case 3:
		var value = $e[2];
		lengthValue = value / 0.75;
		break;
	case 5:
		var value = $e[2];
		lengthValue = value * (72 * (1 / 0.75));
		break;
	case 4:
		var value = $e[2];
		lengthValue = value * (12 * (1 / 0.75));
		break;
	case 6:
		var value = $e[2];
		lengthValue = emReference * value;
		break;
	case 7:
		var value = $e[2];
		lengthValue = exReference * value;
		break;
	}
	return Math.round(lengthValue);
}
cocktail.core.unit.UnitManager.getFontSizeFromAbsoluteSizeValue = function(absoluteSize) {
	var fontSize;
	var mediumFontSize = 16;
	switch( (absoluteSize)[1] ) {
	case 0:
		fontSize = 9;
		break;
	case 1:
		fontSize = 10;
		break;
	case 2:
		fontSize = 13;
		break;
	case 3:
		fontSize = 16;
		break;
	case 4:
		fontSize = 18;
		break;
	case 5:
		fontSize = 24;
		break;
	case 6:
		fontSize = 32;
		break;
	}
	return fontSize;
}
cocktail.core.unit.UnitManager.getFontSizeFromRelativeSizeValue = function(relativeSize,parentFontSize) {
	var fontSize;
	switch( (relativeSize)[1] ) {
	case 0:
		fontSize = cocktail.core.unit.UnitManager.getLargerFontSize(parentFontSize);
		break;
	case 1:
		fontSize = cocktail.core.unit.UnitManager.getSmallerFontSize(parentFontSize);
		break;
	}
	return fontSize;
}
cocktail.core.unit.UnitManager.getPixelFromPercent = function(percent,reference) {
	return reference * (percent * 0.01);
}
cocktail.core.unit.UnitManager.getPercentFromPixel = function(pixel,reference) {
	return reference / pixel * 100;
}
cocktail.core.unit.UnitManager.getColorDataFromCSSColor = function(value) {
	var colorValue;
	var alphaValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var blue = $e[4], green = $e[3], red = $e[2];
		colorValue = red;
		colorValue = (colorValue << 8) + green;
		colorValue = (colorValue << 8) + blue;
		alphaValue = 1.0;
		break;
	case 1:
		var alpha = $e[5], blue = $e[4], green = $e[3], red = $e[2];
		colorValue = red;
		colorValue = (colorValue << 8) + green;
		colorValue = (colorValue << 8) + blue;
		alphaValue = alpha;
		break;
	case 2:
		var value1 = $e[2];
		colorValue = Std.parseInt(StringTools.replace(value1,"#","0x"));
		alphaValue = 1.0;
		break;
	case 3:
		var value1 = $e[2];
		colorValue = cocktail.core.unit.UnitManager.getColorDataFromColorKeyword(value1).color;
		alphaValue = 1.0;
		break;
	case 4:
		colorValue = 16777215;
		alphaValue = 0.0;
		break;
	}
	var colorData = { color : colorValue, alpha : alphaValue};
	return colorData;
}
cocktail.core.unit.UnitManager.getRadFromAngle = function(value) {
	var angle;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		angle = value1 * (Math.PI / 180);
		break;
	case 2:
		var value1 = $e[2];
		angle = value1;
		break;
	case 3:
		var value1 = $e[2];
		angle = value1 * 360 * (Math.PI / 180);
		break;
	case 1:
		var value1 = $e[2];
		angle = value1 * (Math.PI / 200);
		break;
	}
	return angle;
}
cocktail.core.unit.UnitManager.getDegreeFromAngle = function(value) {
	var angle;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		angle = value1;
		break;
	case 2:
		var value1 = $e[2];
		angle = value1 * (180 / Math.PI);
		break;
	case 3:
		var value1 = $e[2];
		angle = value1 * 360;
		break;
	case 1:
		var value1 = $e[2];
		angle = value1 * 0.9;
		break;
	}
	return angle;
}
cocktail.core.unit.UnitManager.getColorDataFromColorKeyword = function(value) {
	var hexColor;
	switch( (value)[1] ) {
	case 0:
		hexColor = "#00FFFF";
		break;
	case 1:
		hexColor = "#000000";
		break;
	case 2:
		hexColor = "#0000FF";
		break;
	case 3:
		hexColor = "#FF00FF";
		break;
	case 4:
		hexColor = "#808080";
		break;
	case 5:
		hexColor = "#008000";
		break;
	case 6:
		hexColor = "#00FF00";
		break;
	case 7:
		hexColor = "#800000";
		break;
	case 8:
		hexColor = "#000080";
		break;
	case 9:
		hexColor = "#808000";
		break;
	case 10:
		hexColor = "#FFA500";
		break;
	case 11:
		hexColor = "#800080";
		break;
	case 12:
		hexColor = "#FF0000";
		break;
	case 13:
		hexColor = "#C0C0C0";
		break;
	case 14:
		hexColor = "#008080";
		break;
	case 15:
		hexColor = "#FFFFFF";
		break;
	case 16:
		hexColor = "#FFFF00";
		break;
	}
	return cocktail.core.unit.UnitManager.getColorDataFromCSSColor(cocktail.core.unit.CSSColor.hex(hexColor));
}
cocktail.core.unit.UnitManager.getLargerFontSize = function(parentFontSize) {
	var fontSizeTable = [9,10,13,16,18,24,32];
	var fontSize = fontSizeTable[fontSizeTable.length - 1];
	var _g1 = 0, _g = fontSizeTable.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(fontSizeTable[i] > parentFontSize) {
			fontSize = fontSizeTable[i];
			break;
		}
	}
	return fontSize;
}
cocktail.core.unit.UnitManager.getSmallerFontSize = function(parentFontSize) {
	var fontSizeTable = [9,10,13,16,18,24,32];
	var fontSize = fontSizeTable[0];
	var i = fontSizeTable.length - 1;
	while(i > 0) {
		if(fontSizeTable[i] < parentFontSize) {
			fontSize = fontSizeTable[i];
			break;
		}
		i--;
	}
	return fontSize;
}
cocktail.core.unit.UnitManager.getCSSDisplay = function(value) {
	var cssDisplayValue;
	switch( (value)[1] ) {
	case 0:
		cssDisplayValue = "block";
		break;
	case 2:
		cssDisplayValue = "inline";
		break;
	case 1:
		cssDisplayValue = "inline-block";
		break;
	case 3:
		cssDisplayValue = "none";
		break;
	}
	return cssDisplayValue;
}
cocktail.core.unit.UnitManager.getCSSFloatAsString = function(value) {
	var cssCSSFloat;
	switch( (value)[1] ) {
	case 0:
		cssCSSFloat = "left";
		break;
	case 1:
		cssCSSFloat = "right";
		break;
	case 2:
		cssCSSFloat = "none";
		break;
	}
	return cssCSSFloat;
}
cocktail.core.unit.UnitManager.getCSSClear = function(value) {
	var cssClearValue;
	switch( (value)[1] ) {
	case 1:
		cssClearValue = "left";
		break;
	case 2:
		cssClearValue = "right";
		break;
	case 3:
		cssClearValue = "both";
		break;
	case 0:
		cssClearValue = "none";
		break;
	}
	return cssClearValue;
}
cocktail.core.unit.UnitManager.getCSSPosition = function(value) {
	var cssPositionValue;
	switch( (value)[1] ) {
	case 0:
		cssPositionValue = "static";
		break;
	case 1:
		cssPositionValue = "relative";
		break;
	case 2:
		cssPositionValue = "absolute";
		break;
	case 3:
		cssPositionValue = "fixed";
		break;
	}
	return cssPositionValue;
}
cocktail.core.unit.UnitManager.getCSSOverflow = function(value) {
	var cssOverflowValue;
	switch( (value)[1] ) {
	case 0:
		cssOverflowValue = "visible";
		break;
	case 1:
		cssOverflowValue = "hidden";
		break;
	case 2:
		cssOverflowValue = "scroll";
		break;
	case 3:
		cssOverflowValue = "auto";
		break;
	}
	return cssOverflowValue;
}
cocktail.core.unit.UnitManager.getCSSOpacity = function(value) {
	var cssOpacityValue;
	cssOpacityValue = Std.string(value);
	return cssOpacityValue;
}
cocktail.core.unit.UnitManager.getCSSVisibility = function(value) {
	var cssVisibilityValue;
	switch( (value)[1] ) {
	case 0:
		cssVisibilityValue = "visible";
		break;
	case 1:
		cssVisibilityValue = "hidden";
		break;
	}
	return cssVisibilityValue;
}
cocktail.core.unit.UnitManager.getCSSTransform = function(value) {
	var cssTransformValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		cssTransformValue = "none";
		break;
	case 1:
		var value1 = $e[2];
		cssTransformValue = "";
		var _g1 = 0, _g = value1.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssTransformValue += cocktail.core.unit.UnitManager.getCSSTransformFunction(value1[i]);
			if(i < value1.length - 1) cssTransformValue += " ";
		}
		break;
	}
	return cssTransformValue;
}
cocktail.core.unit.UnitManager.getCSSTransformFunction = function(transformFunction) {
	var cssTransformFunction;
	var $e = (transformFunction);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		cssTransformFunction = "matrix(" + value.a + "," + value.b + "," + value.c + "," + value.d + "," + value.e + "," + value.f + ")";
		break;
	case 7:
		var angle = $e[2];
		cssTransformFunction = "rotate(" + cocktail.core.unit.UnitManager.getCSSAngle(angle) + ")";
		break;
	case 4:
		var sy = $e[3], sx = $e[2];
		cssTransformFunction = "scale(" + sx + "," + sy + ")";
		break;
	case 5:
		var sx = $e[2];
		cssTransformFunction = "scaleX(" + sx + ")";
		break;
	case 6:
		var sy = $e[2];
		cssTransformFunction = "scaleY(" + sy + ")";
		break;
	case 10:
		var skewY = $e[3], skewX = $e[2];
		cssTransformFunction = "skew(" + cocktail.core.unit.UnitManager.getCSSAngle(skewX) + "," + cocktail.core.unit.UnitManager.getCSSAngle(skewY) + ")";
		break;
	case 8:
		var skewX = $e[2];
		cssTransformFunction = "skewX(" + cocktail.core.unit.UnitManager.getCSSAngle(skewX) + ")";
		break;
	case 9:
		var skewY = $e[2];
		cssTransformFunction = "skewY(" + cocktail.core.unit.UnitManager.getCSSAngle(skewY) + ")";
		break;
	case 1:
		var ty = $e[3], tx = $e[2];
		cssTransformFunction = "translate(" + cocktail.core.unit.UnitManager.getCSSTranslation(tx) + "," + cocktail.core.unit.UnitManager.getCSSTranslation(ty) + ")";
		break;
	case 2:
		var tx = $e[2];
		cssTransformFunction = "translateX(" + cocktail.core.unit.UnitManager.getCSSTranslation(tx) + ")";
		break;
	case 3:
		var ty = $e[2];
		cssTransformFunction = "translateY(" + cocktail.core.unit.UnitManager.getCSSTranslation(ty) + ")";
		break;
	}
	return cssTransformFunction;
}
cocktail.core.unit.UnitManager.getCSSTranslation = function(translation) {
	var cssTranslation;
	var $e = (translation);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		cssTranslation = cocktail.core.unit.UnitManager.getCSSLength(value);
		break;
	case 1:
		var value = $e[2];
		cssTranslation = cocktail.core.unit.UnitManager.getCSSPercentValue(value);
		break;
	}
	return cssTranslation;
}
cocktail.core.unit.UnitManager.getCSSTransformOrigin = function(value) {
	var cssTransformOriginValue;
	var $e = (value.x);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssTransformOriginValue = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssTransformOriginValue = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 2:
		cssTransformOriginValue = "left";
		break;
	case 3:
		cssTransformOriginValue = "center";
		break;
	case 4:
		cssTransformOriginValue = "right";
		break;
	}
	cssTransformOriginValue += " ";
	var $e = (value.y);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssTransformOriginValue += cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssTransformOriginValue += cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 2:
		cssTransformOriginValue += "top";
		break;
	case 3:
		cssTransformOriginValue += "center";
		break;
	case 4:
		cssTransformOriginValue += "bottom";
		break;
	}
	return cssTransformOriginValue;
}
cocktail.core.unit.UnitManager.getCSSMargin = function(value) {
	var cssMarginValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssMarginValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percentValue = $e[2];
		cssMarginValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percentValue);
		break;
	case 2:
		cssMarginValue = "auto";
		break;
	}
	return cssMarginValue;
}
cocktail.core.unit.UnitManager.getCSSPadding = function(value) {
	var cssPaddingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssPaddingValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percentValue = $e[2];
		cssPaddingValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percentValue);
		break;
	}
	return cssPaddingValue;
}
cocktail.core.unit.UnitManager.getCSSDimension = function(value) {
	var cssDimensionValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssDimensionValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percentValue = $e[2];
		cssDimensionValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percentValue);
		break;
	case 2:
		cssDimensionValue = "auto";
		break;
	}
	return cssDimensionValue;
}
cocktail.core.unit.UnitManager.getCSSPositionOffset = function(value) {
	var cssPositionOffsetValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssPositionOffsetValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percentValue = $e[2];
		cssPositionOffsetValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percentValue);
		break;
	case 2:
		cssPositionOffsetValue = "auto";
		break;
	}
	return cssPositionOffsetValue;
}
cocktail.core.unit.UnitManager.getCSSConstrainedDimension = function(value) {
	var cssConstrainedValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssConstrainedValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percentValue = $e[2];
		cssConstrainedValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percentValue);
		break;
	case 2:
		cssConstrainedValue = "none";
		break;
	}
	return cssConstrainedValue;
}
cocktail.core.unit.UnitManager.getCSSVerticalAlign = function(value) {
	var cssVerticalAlignValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		cssVerticalAlignValue = "baseline";
		break;
	case 5:
		cssVerticalAlignValue = "middle";
		break;
	case 1:
		cssVerticalAlignValue = "sub";
		break;
	case 2:
		cssVerticalAlignValue = "super";
		break;
	case 4:
		cssVerticalAlignValue = "text-top";
		break;
	case 7:
		cssVerticalAlignValue = "text-bottom";
		break;
	case 3:
		cssVerticalAlignValue = "top";
		break;
	case 6:
		cssVerticalAlignValue = "bottom";
		break;
	case 8:
		var value1 = $e[2];
		cssVerticalAlignValue = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 9:
		var value1 = $e[2];
		cssVerticalAlignValue = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	}
	return cssVerticalAlignValue;
}
cocktail.core.unit.UnitManager.getCSSLineHeight = function(value) {
	var cssLineHeightValue;
	var $e = (value);
	switch( $e[1] ) {
	case 2:
		var unit = $e[2];
		cssLineHeightValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 0:
		cssLineHeightValue = "normal";
		break;
	case 3:
		var value1 = $e[2];
		cssLineHeightValue = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssLineHeightValue = Std.string(value1);
		break;
	}
	return cssLineHeightValue;
}
cocktail.core.unit.UnitManager.getCSSFontSize = function(value) {
	var cssFontSizeValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		cssFontSizeValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	case 1:
		var percent = $e[2];
		cssFontSizeValue = cocktail.core.unit.UnitManager.getCSSPercentValue(percent);
		break;
	case 2:
		var value1 = $e[2];
		switch( (value1)[1] ) {
		case 0:
			cssFontSizeValue = "xx-small";
			break;
		case 1:
			cssFontSizeValue = "x-small";
			break;
		case 2:
			cssFontSizeValue = "small";
			break;
		case 3:
			cssFontSizeValue = "medium";
			break;
		case 4:
			cssFontSizeValue = "large";
			break;
		case 5:
			cssFontSizeValue = "x-large";
			break;
		case 6:
			cssFontSizeValue = "xx-large";
			break;
		}
		break;
	case 3:
		var value1 = $e[2];
		switch( (value1)[1] ) {
		case 0:
			cssFontSizeValue = "larger";
			break;
		case 1:
			cssFontSizeValue = "smaller";
			break;
		}
		break;
	}
	return cssFontSizeValue;
}
cocktail.core.unit.UnitManager.getCSSFontWeight = function(value) {
	var cssFontWeightValue;
	switch( (value)[1] ) {
	case 0:
		cssFontWeightValue = "normal";
		break;
	case 1:
		cssFontWeightValue = "bold";
		break;
	case 2:
		cssFontWeightValue = "bolder";
		break;
	case 3:
		cssFontWeightValue = "lighter";
		break;
	case 4:
		cssFontWeightValue = "100";
		break;
	case 5:
		cssFontWeightValue = "200";
		break;
	case 6:
		cssFontWeightValue = "300";
		break;
	case 7:
		cssFontWeightValue = "400";
		break;
	case 8:
		cssFontWeightValue = "500";
		break;
	case 9:
		cssFontWeightValue = "600";
		break;
	case 10:
		cssFontWeightValue = "700";
		break;
	case 11:
		cssFontWeightValue = "800";
		break;
	case 12:
		cssFontWeightValue = "900";
		break;
	}
	return cssFontWeightValue;
}
cocktail.core.unit.UnitManager.getCSSFontStyle = function(value) {
	var cssFontStyleValue;
	switch( (value)[1] ) {
	case 0:
		cssFontStyleValue = "normal";
		break;
	case 1:
		cssFontStyleValue = "italic";
		break;
	}
	return cssFontStyleValue;
}
cocktail.core.unit.UnitManager.getCSSFontVariant = function(value) {
	var cssFontVariantValue;
	switch( (value)[1] ) {
	case 0:
		cssFontVariantValue = "normal";
		break;
	case 1:
		cssFontVariantValue = "small-caps";
		break;
	}
	return cssFontVariantValue;
}
cocktail.core.unit.UnitManager.getCSSFontFamily = function(value) {
	var cssFontFamilyValue = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		var fontName = value[i];
		if(fontName.indexOf(" ") != -1) fontName = "'" + fontName + "'";
		cssFontFamilyValue += fontName;
		if(i < value.length - 1) cssFontFamilyValue += ",";
	}
	return cssFontFamilyValue;
}
cocktail.core.unit.UnitManager.getCSSTextAlign = function(value) {
	var cssTextAlignValue;
	switch( (value)[1] ) {
	case 0:
		cssTextAlignValue = "left";
		break;
	case 1:
		cssTextAlignValue = "right";
		break;
	case 2:
		cssTextAlignValue = "center";
		break;
	case 3:
		cssTextAlignValue = "justify";
		break;
	}
	return cssTextAlignValue;
}
cocktail.core.unit.UnitManager.getCSSWhiteSpace = function(value) {
	var cssWhiteSpaceValue;
	switch( (value)[1] ) {
	case 0:
		cssWhiteSpaceValue = "normal";
		break;
	case 1:
		cssWhiteSpaceValue = "pre";
		break;
	case 2:
		cssWhiteSpaceValue = "nowrap";
		break;
	case 3:
		cssWhiteSpaceValue = "pre-wrap";
		break;
	case 4:
		cssWhiteSpaceValue = "pre-line";
		break;
	}
	return cssWhiteSpaceValue;
}
cocktail.core.unit.UnitManager.getCSSTextTransform = function(value) {
	var cssTextTransformValue;
	switch( (value)[1] ) {
	case 3:
		cssTextTransformValue = "none";
		break;
	case 1:
		cssTextTransformValue = "uppercase";
		break;
	case 2:
		cssTextTransformValue = "lowercase";
		break;
	case 0:
		cssTextTransformValue = "capitalize";
		break;
	}
	return cssTextTransformValue;
}
cocktail.core.unit.UnitManager.getCSSTextIndent = function(value) {
	var cssTextIndentValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssTextIndentValue = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssTextIndentValue = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	}
	return cssTextIndentValue;
}
cocktail.core.unit.UnitManager.getCSSLetterSpacing = function(value) {
	var cssLetterSpacingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		cssLetterSpacingValue = "normal";
		break;
	case 1:
		var unit = $e[2];
		cssLetterSpacingValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	}
	return cssLetterSpacingValue;
}
cocktail.core.unit.UnitManager.getCSSWordSpacing = function(value) {
	var cssWordSpacingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		cssWordSpacingValue = "normal";
		break;
	case 1:
		var unit = $e[2];
		cssWordSpacingValue = cocktail.core.unit.UnitManager.getCSSLength(unit);
		break;
	}
	return cssWordSpacingValue;
}
cocktail.core.unit.UnitManager.getCSSBackgroundColor = function(value) {
	var cssBackgroundColor;
	cssBackgroundColor = cocktail.core.unit.UnitManager.getCSSColor(value);
	return cssBackgroundColor;
}
cocktail.core.unit.UnitManager.getCSSBackgroundOrigin = function(value) {
	var cssBackgroundOrigin = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		switch( (value[i])[1] ) {
		case 0:
			cssBackgroundOrigin += "border-box";
			break;
		case 2:
			cssBackgroundOrigin += "content-box";
			break;
		case 1:
			cssBackgroundOrigin += "padding-box";
			break;
		}
		if(i < value.length - 1) cssBackgroundOrigin += ",";
	}
	return cssBackgroundOrigin;
}
cocktail.core.unit.UnitManager.getCSSBackgroundClip = function(value) {
	var cssBackgroundClip = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		switch( (value[i])[1] ) {
		case 0:
			cssBackgroundClip += "border-box";
			break;
		case 2:
			cssBackgroundClip += "content-box";
			break;
		case 1:
			cssBackgroundClip += "padding-box";
			break;
		}
		if(i < value.length - 1) cssBackgroundClip += ",";
	}
	return cssBackgroundClip;
}
cocktail.core.unit.UnitManager.getCSSBackgroundImage = function(value) {
	var cssBackgroundImage = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		var $e = (value[i]);
		switch( $e[1] ) {
		case 0:
			cssBackgroundImage += "none";
			break;
		case 1:
			var value1 = $e[2];
			cssBackgroundImage += cocktail.core.unit.UnitManager.getCSSImageValue(value1);
			break;
		}
		if(i < value.length - 1) cssBackgroundImage += ",";
	}
	return cssBackgroundImage;
}
cocktail.core.unit.UnitManager.getCSSBackgroundSize = function(value) {
	var cssBackgroundSize = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		var $e = (value[i]);
		switch( $e[1] ) {
		case 0:
			cssBackgroundSize += "contain";
			break;
		case 1:
			cssBackgroundSize += "cover";
			break;
		case 2:
			var value1 = $e[2];
			cssBackgroundSize += cocktail.core.unit.UnitManager.getCSSBackgroundSizeDimensions(value1);
			break;
		}
		if(i < value.length - 1) cssBackgroundSize += ",";
	}
	return cssBackgroundSize;
}
cocktail.core.unit.UnitManager.getCSSBackgroundSizeDimensions = function(value) {
	var cssBackgroundSizeDimensions = cocktail.core.unit.UnitManager.getCSSBackgroundSizeDimension(value.x) + " " + cocktail.core.unit.UnitManager.getCSSBackgroundSizeDimension(value.y);
	return cssBackgroundSizeDimensions;
}
cocktail.core.unit.UnitManager.getCSSBackgroundSizeDimension = function(value) {
	var cssBackgroundSizeDimension;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssBackgroundSizeDimension = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssBackgroundSizeDimension = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 2:
		cssBackgroundSizeDimension = "auto";
		break;
	}
	return cssBackgroundSizeDimension;
}
cocktail.core.unit.UnitManager.getCSSBackgroundPosition = function(value) {
	var cssBackgroundPositionData = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		cssBackgroundPositionData += cocktail.core.unit.UnitManager.getCSSBackgroundPositionX(value[i].x) + " " + cocktail.core.unit.UnitManager.getCSSBackgroundPositionY(value[i].y);
		if(i < value.length - 1) cssBackgroundPositionData += ",";
	}
	return cssBackgroundPositionData;
}
cocktail.core.unit.UnitManager.getCSSBackgroundPositionX = function(value) {
	var cssBackgroundPositionX;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssBackgroundPositionX = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssBackgroundPositionX = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 3:
		cssBackgroundPositionX = "center";
		break;
	case 2:
		cssBackgroundPositionX = "left";
		break;
	case 4:
		cssBackgroundPositionX = "right";
		break;
	}
	return cssBackgroundPositionX;
}
cocktail.core.unit.UnitManager.getCSSBackgroundPositionY = function(value) {
	var cssBackgroundPositionY;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssBackgroundPositionY = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssBackgroundPositionY = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 4:
		cssBackgroundPositionY = "bottom";
		break;
	case 2:
		cssBackgroundPositionY = "top";
		break;
	case 3:
		cssBackgroundPositionY = "center";
		break;
	}
	return cssBackgroundPositionY;
}
cocktail.core.unit.UnitManager.getCSSBackgroundRepeat = function(value) {
	var cssBackgroundRepeat = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		cssBackgroundRepeat += cocktail.core.unit.UnitManager.getCSSBackgroundRepeatValue(value[i].x) + " " + cocktail.core.unit.UnitManager.getCSSBackgroundRepeatValue(value[i].y);
		if(i < value.length - 1) cssBackgroundRepeat += ",";
	}
	return cssBackgroundRepeat;
}
cocktail.core.unit.UnitManager.getCSSBackgroundRepeatValue = function(value) {
	var cssBackgroundRepeatValue;
	switch( (value)[1] ) {
	case 3:
		cssBackgroundRepeatValue = "no-repeat";
		break;
	case 0:
		cssBackgroundRepeatValue = "repeat";
		break;
	case 2:
		cssBackgroundRepeatValue = "round";
		break;
	case 1:
		cssBackgroundRepeatValue = "space";
		break;
	}
	return cssBackgroundRepeatValue;
}
cocktail.core.unit.UnitManager.getCSSCursor = function(value) {
	var cssCursorValue;
	switch( (value)[1] ) {
	case 0:
		cssCursorValue = "auto";
		break;
	case 1:
		cssCursorValue = "crosshair";
		break;
	case 2:
		cssCursorValue = "default";
		break;
	case 3:
		cssCursorValue = "pointer";
		break;
	}
	return cssCursorValue;
}
cocktail.core.unit.UnitManager.getCSSImageValue = function(value) {
	var cssImageValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssImageValue = "url(\"" + value1 + "\")";
		break;
	case 1:
		var value1 = $e[2];
		cssImageValue = "image(" + cocktail.core.unit.UnitManager.getCSSImageList(value1) + ")";
		break;
	case 2:
		var value1 = $e[2];
		cssImageValue = cocktail.core.unit.UnitManager.getCSSGradientValue(value1);
		break;
	}
	return cssImageValue;
}
cocktail.core.unit.UnitManager.getCSSImageList = function(value) {
	var cssImageList = "";
	var _g1 = 0, _g = value.urls.length;
	while(_g1 < _g) {
		var i = _g1++;
		cssImageList += "\"" + value.urls[i] + "\"";
		if(i < value.urls.length - 1) cssImageList += ","; else cssImageList += "," + cocktail.core.unit.UnitManager.getCSSColor(value.fallbackColor);
	}
	return cssImageList;
}
cocktail.core.unit.UnitManager.getCSSGradientValue = function(value) {
	var cssGradientValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssGradientValue = "linear-gradient(" + cocktail.core.unit.UnitManager.getCSSLinearGradientValue(value1) + ")";
		break;
	}
	return cssGradientValue;
}
cocktail.core.unit.UnitManager.getCSSLinearGradientValue = function(value) {
	var cssLinearGradientValue = cocktail.core.unit.UnitManager.getCSSGradientAngle(value.angle) + "," + cocktail.core.unit.UnitManager.getCSSColorStopsValue(value.colorStops);
	return cssLinearGradientValue;
}
cocktail.core.unit.UnitManager.getCSSColorStopsValue = function(value) {
	var cssColorStopsData = "";
	var _g1 = 0, _g = value.length;
	while(_g1 < _g) {
		var i = _g1++;
		cssColorStopsData += cocktail.core.unit.UnitManager.getCSSColor(value[i].color) + " " + cocktail.core.unit.UnitManager.getCSSColorStopValue(value[i].stop);
		if(i < value.length - 1) cssColorStopsData += ",";
	}
	return cssColorStopsData;
}
cocktail.core.unit.UnitManager.getCSSColorStopValue = function(value) {
	var cssColorStopValue;
	var $e = (value);
	switch( $e[1] ) {
	case 1:
		var value1 = $e[2];
		cssColorStopValue = cocktail.core.unit.UnitManager.getCSSPercentValue(value1);
		break;
	case 0:
		var value1 = $e[2];
		cssColorStopValue = cocktail.core.unit.UnitManager.getCSSLength(value1);
		break;
	}
	return cssColorStopValue;
}
cocktail.core.unit.UnitManager.getCSSGradientAngle = function(value) {
	var cssGradientAngle;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssGradientAngle = cocktail.core.unit.UnitManager.getCSSAngle(value1);
		break;
	case 2:
		var value1 = $e[2];
		cssGradientAngle = cocktail.core.unit.UnitManager.getCSSCornerValue(value1);
		break;
	case 1:
		var value1 = $e[2];
		cssGradientAngle = cocktail.core.unit.UnitManager.getCSSSideValue(value1);
		break;
	}
	return cssGradientAngle;
}
cocktail.core.unit.UnitManager.getCSSSideValue = function(value) {
	var cssSideValue;
	switch( (value)[1] ) {
	case 2:
		cssSideValue = "bottom";
		break;
	case 1:
		cssSideValue = "left";
		break;
	case 3:
		cssSideValue = "right";
		break;
	case 0:
		cssSideValue = "top";
		break;
	}
	return cssSideValue;
}
cocktail.core.unit.UnitManager.getCSSCornerValue = function(value) {
	var cssCornerValue;
	switch( (value)[1] ) {
	case 2:
		cssCornerValue = "left bottom";
		break;
	case 1:
		cssCornerValue = "right bottom";
		break;
	case 3:
		cssCornerValue = "left top";
		break;
	case 0:
		cssCornerValue = "right top";
		break;
	}
	return cssCornerValue;
}
cocktail.core.unit.UnitManager.getCSSColor = function(value) {
	var cssColor;
	var $e = (value);
	switch( $e[1] ) {
	case 2:
		var value1 = $e[2];
		cssColor = value1;
		break;
	case 0:
		var blue = $e[4], green = $e[3], red = $e[2];
		cssColor = "rgb(" + red + "," + green + "," + blue + ")";
		break;
	case 1:
		var alpha = $e[5], blue = $e[4], green = $e[3], red = $e[2];
		cssColor = "rgba(" + red + "," + green + "," + blue + "," + alpha + ")";
		break;
	case 3:
		var value1 = $e[2];
		cssColor = cocktail.core.unit.UnitManager.getColorFromKeyword(value1);
		break;
	case 4:
		cssColor = "transparent";
		break;
	}
	return cssColor;
}
cocktail.core.unit.UnitManager.getCSSLength = function(lengthValue) {
	var cssLength;
	var $e = (lengthValue);
	switch( $e[1] ) {
	case 0:
		var pixelValue = $e[2];
		cssLength = Std.string(pixelValue) + "px";
		break;
	case 3:
		var pointValue = $e[2];
		cssLength = Std.string(pointValue) + "pt";
		break;
	case 2:
		var milimetersValue = $e[2];
		cssLength = Std.string(milimetersValue) + "mm";
		break;
	case 4:
		var picasValue = $e[2];
		cssLength = Std.string(picasValue) + "pc";
		break;
	case 1:
		var centimetersValue = $e[2];
		cssLength = Std.string(centimetersValue) + "cm";
		break;
	case 5:
		var inchesValue = $e[2];
		cssLength = Std.string(inchesValue) + "in";
		break;
	case 6:
		var emValue = $e[2];
		cssLength = Std.string(emValue) + "em";
		break;
	case 7:
		var exValue = $e[2];
		cssLength = Std.string(exValue) + "ex";
		break;
	}
	return cssLength;
}
cocktail.core.unit.UnitManager.getCSSPercentValue = function(value) {
	return Std.string(value) + "%";
}
cocktail.core.unit.UnitManager.getCSSAngle = function(value) {
	var cssAngle;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		cssAngle = Std.string(value1) + "deg";
		break;
	case 2:
		var value1 = $e[2];
		cssAngle = Std.string(value1) + "rad";
		break;
	case 1:
		var value1 = $e[2];
		cssAngle = Std.string(value1) + "grad";
		break;
	case 3:
		var value1 = $e[2];
		cssAngle = Std.string(value1) + "turn";
		break;
	}
	return cssAngle;
}
cocktail.core.unit.UnitManager.getColorFromKeyword = function(value) {
	var cssColor;
	switch( (value)[1] ) {
	case 0:
		cssColor = "aqua";
		break;
	case 1:
		cssColor = "black";
		break;
	case 2:
		cssColor = "blue";
		break;
	case 3:
		cssColor = "fuchsia";
		break;
	case 4:
		cssColor = "gray";
		break;
	case 5:
		cssColor = "green";
		break;
	case 6:
		cssColor = "lime";
		break;
	case 7:
		cssColor = "maroon";
		break;
	case 8:
		cssColor = "navy";
		break;
	case 9:
		cssColor = "olive";
		break;
	case 10:
		cssColor = "orange";
		break;
	case 11:
		cssColor = "purple";
		break;
	case 12:
		cssColor = "red";
		break;
	case 13:
		cssColor = "silver";
		break;
	case 14:
		cssColor = "teal";
		break;
	case 15:
		cssColor = "white";
		break;
	case 16:
		cssColor = "yellow";
		break;
	}
	return cssColor;
}
cocktail.core.unit.UnitManager.prototype = {
	__class__: cocktail.core.unit.UnitManager
}
if(!cocktail.core.window) cocktail.core.window = {}
cocktail.core.window.AbstractWindow = $hxClasses["cocktail.core.window.AbstractWindow"] = function(document) {
	this._document = document;
};
cocktail.core.window.AbstractWindow.__name__ = ["cocktail","core","window","AbstractWindow"];
cocktail.core.window.AbstractWindow.__interfaces__ = [cocktail.core.event.IEventTarget];
cocktail.core.window.AbstractWindow.prototype = {
	_onResize: null
	,onResize: null
	,_document: null
	,document: null
	,innerHeight: null
	,innerWidth: null
	,set_onResize: function(value) {
		return this._onResize = value;
	}
	,get_onResize: function() {
		return this._onResize;
	}
	,get_innerHeight: function() {
		return -1;
	}
	,get_innerWidth: function() {
		return -1;
	}
	,get_document: function() {
		return this._document;
	}
	,__class__: cocktail.core.window.AbstractWindow
	,__properties__: {get_innerWidth:"get_innerWidth",get_innerHeight:"get_innerHeight",get_document:"get_document",set_onResize:"set_onResize",get_onResize:"get_onResize"}
}
cocktail.port.browser.FontLoader = $hxClasses["cocktail.port.browser.FontLoader"] = function() {
	cocktail.core.font.AbstractFontLoader.call(this);
};
cocktail.port.browser.FontLoader.__name__ = ["cocktail","port","browser","FontLoader"];
cocktail.port.browser.FontLoader.__super__ = cocktail.core.font.AbstractFontLoader;
cocktail.port.browser.FontLoader.prototype = $extend(cocktail.core.font.AbstractFontLoader.prototype,{
	_styleE: null
	,load: function(url,name) {
		cocktail.core.font.AbstractFontLoader.prototype.load.call(this,url,name);
		if(this.fontData.type != cocktail.core.font.FontType.swf) {
			var fontTypeString = "";
			if(this.fontData.type == cocktail.core.font.FontType.ttf) fontTypeString = " format(\"truetype\")"; else fontTypeString = "";
			this._styleE = js.Lib.document.createElement("style");
			this._styleE.innerHTML = "@font-face{font-family: " + name + " ; src: url( \"" + url + "\" )" + fontTypeString + ";}";
			js.Lib.document.getElementsByTagName("head")[0].appendChild(this._styleE);
			this._successCallback();
		} else {
			haxe.Log.trace("Could not load font, the font format is not appropriate for the target: " + url,{ fileName : "FontLoader.hx", lineNumber : 81, className : "cocktail.port.browser.FontLoader", methodName : "load"});
			this._errorCallback("Could not load font, the font format is not appropriate for the target: " + url);
		}
	}
	,cleanup: function() {
		cocktail.core.font.AbstractFontLoader.prototype.cleanup.call(this);
	}
	,__class__: cocktail.port.browser.FontLoader
});
cocktail.port.browser.FontManager = $hxClasses["cocktail.port.browser.FontManager"] = function() {
	cocktail.core.font.AbstractFontManager.call(this);
};
cocktail.port.browser.FontManager.__name__ = ["cocktail","port","browser","FontManager"];
cocktail.port.browser.FontManager.__super__ = cocktail.core.font.AbstractFontManager;
cocktail.port.browser.FontManager.prototype = $extend(cocktail.core.font.AbstractFontManager.prototype,{
	getSystemFonts: function() {
		haxe.Log.trace("It is impossible to list the system fonts in javascript",{ fileName : "FontManager.hx", lineNumber : 38, className : "cocktail.port.browser.FontManager", methodName : "getSystemFonts"});
		return new Array();
	}
	,__class__: cocktail.port.browser.FontManager
});
cocktail.port.browser.HTMLAnchorElement = $hxClasses["cocktail.port.browser.HTMLAnchorElement"] = function() {
	cocktail.core.html.AbstractHTMLAnchorElement.call(this);
};
cocktail.port.browser.HTMLAnchorElement.__name__ = ["cocktail","port","browser","HTMLAnchorElement"];
cocktail.port.browser.HTMLAnchorElement.__super__ = cocktail.core.html.AbstractHTMLAnchorElement;
cocktail.port.browser.HTMLAnchorElement.prototype = $extend(cocktail.core.html.AbstractHTMLAnchorElement.prototype,{
	set_href: function(value) {
		this._nativeElement.href = value;
		cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_href.call(this,value);
		return value;
	}
	,set_target: function(value) {
		this._nativeElement.target = value;
		cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_target.call(this,value);
		return value;
	}
	,__class__: cocktail.port.browser.HTMLAnchorElement
});
cocktail.port.browser.HTMLDocument = $hxClasses["cocktail.port.browser.HTMLDocument"] = function() {
	cocktail.core.html.AbstractHTMLDocument.call(this);
};
cocktail.port.browser.HTMLDocument.__name__ = ["cocktail","port","browser","HTMLDocument"];
cocktail.port.browser.HTMLDocument.__super__ = cocktail.core.html.AbstractHTMLDocument;
cocktail.port.browser.HTMLDocument.prototype = $extend(cocktail.core.html.AbstractHTMLDocument.prototype,{
	layoutAndRender: function() {
	}
	,__class__: cocktail.port.browser.HTMLDocument
});
cocktail.port.browser.HTMLHtmlElement = $hxClasses["cocktail.port.browser.HTMLHtmlElement"] = function() {
	cocktail.core.html.AbstractHTMLHtmlElement.call(this);
};
cocktail.port.browser.HTMLHtmlElement.__name__ = ["cocktail","port","browser","HTMLHtmlElement"];
cocktail.port.browser.HTMLHtmlElement.__super__ = cocktail.core.html.AbstractHTMLHtmlElement;
cocktail.port.browser.HTMLHtmlElement.prototype = $extend(cocktail.core.html.AbstractHTMLHtmlElement.prototype,{
	appendChild: function(newChild) {
		this.removeFromParentIfNecessary(newChild);
		newChild.set_parentNode(this);
		this._childNodes.push(newChild);
		return newChild;
	}
	,__class__: cocktail.port.browser.HTMLHtmlElement
});
cocktail.port.browser.HTMLImageElement = $hxClasses["cocktail.port.browser.HTMLImageElement"] = function() {
	cocktail.core.html.AbstractHTMLImageElement.call(this);
};
cocktail.port.browser.HTMLImageElement.__name__ = ["cocktail","port","browser","HTMLImageElement"];
cocktail.port.browser.HTMLImageElement.__super__ = cocktail.core.html.AbstractHTMLImageElement;
cocktail.port.browser.HTMLImageElement.prototype = $extend(cocktail.core.html.AbstractHTMLImageElement.prototype,{
	initNativeElement: function() {
		this._nativeElement = this._embeddedAsset;
	}
	,__class__: cocktail.port.browser.HTMLImageElement
});
cocktail.port.browser.HTMLInputElement = $hxClasses["cocktail.port.browser.HTMLInputElement"] = function() {
	cocktail.core.html.AbstractHTMLInputElement.call(this);
};
cocktail.port.browser.HTMLInputElement.__name__ = ["cocktail","port","browser","HTMLInputElement"];
cocktail.port.browser.HTMLInputElement.__super__ = cocktail.core.html.AbstractHTMLInputElement;
cocktail.port.browser.HTMLInputElement.prototype = $extend(cocktail.core.html.AbstractHTMLInputElement.prototype,{
	set_onChange: function(value) {
		this._nativeElement.removeEventListener("change",this.onNativeChange.$bind(this));
		this._onChange = value;
		if(this._onChange != null) this._nativeElement.addEventListener("change",this.onNativeChange.$bind(this));
		return value;
	}
	,onNativeChange: function(event) {
		this.onChangeCallback();
	}
	,set_disabled: function(value) {
		this._nativeElement.disabled = value;
		return this._disabled = value;
	}
	,set_maxLength: function(value) {
		this._nativeElement.maxLength = value;
		return this._maxLength = value;
	}
	,set_value: function(value) {
		this._nativeElement.value = value;
		return this._value = value;
	}
	,get_value: function() {
		this._value = this._nativeElement.value;
		return this._value;
	}
	,__class__: cocktail.port.browser.HTMLInputElement
});
cocktail.port.browser.Keyboard = $hxClasses["cocktail.port.browser.Keyboard"] = function(htmlElement) {
	cocktail.core.keyboard.AbstractKeyboard.call(this,htmlElement);
	this._keyDownEvent = "keydown";
	this._keyUpEvent = "keyup";
};
cocktail.port.browser.Keyboard.__name__ = ["cocktail","port","browser","Keyboard"];
cocktail.port.browser.Keyboard.__super__ = cocktail.core.keyboard.AbstractKeyboard;
cocktail.port.browser.Keyboard.prototype = $extend(cocktail.core.keyboard.AbstractKeyboard.prototype,{
	updateListeners: function(keyboardEvent,nativeCallback,htmlElementCallback) {
		this._htmlElement.get_nativeElement().removeEventListener(keyboardEvent,nativeCallback);
		if(htmlElementCallback != null) this._htmlElement.get_nativeElement().addEventListener(keyboardEvent,nativeCallback);
	}
	,getKeyData: function(event) {
		var eventType;
		switch(event.type) {
		case "keydown":
			eventType = "keydown";
			break;
		case "keyup":
			eventType = "keyup";
			break;
		default:
			eventType = event.type;
		}
		var keyboardEvent = new cocktail.core.event.KeyboardEvent(eventType,this._htmlElement,0.0,event.charCode,event.keyCode,event.ctrlKey,event.shiftKey,event.altKey);
		return keyboardEvent;
	}
	,__class__: cocktail.port.browser.Keyboard
});
cocktail.port.browser.Mouse = $hxClasses["cocktail.port.browser.Mouse"] = function(htmlElement) {
	cocktail.core.mouse.AbstractMouse.call(this,htmlElement);
	this._clickEvent = "click";
	this._mouseDownEvent = "mousedown";
	this._mouseUpEvent = "mouseup";
	this._mouseOverEvent = "mouseover";
	this._mouseOutEvent = "mouseout";
	this._mouseMoveEvent = "mousemove";
};
cocktail.port.browser.Mouse.__name__ = ["cocktail","port","browser","Mouse"];
cocktail.port.browser.Mouse.__super__ = cocktail.core.mouse.AbstractMouse;
cocktail.port.browser.Mouse.prototype = $extend(cocktail.core.mouse.AbstractMouse.prototype,{
	updateListeners: function(mouseEvent,nativeCallback,htmlElementCallback) {
		this._htmlElement.get_nativeElement().removeEventListener(mouseEvent,nativeCallback);
		if(htmlElementCallback != null) this._htmlElement.get_nativeElement().addEventListener(mouseEvent,nativeCallback);
	}
	,getMouseEvent: function(event) {
		var eventType;
		switch(event.type) {
		case "click":
			eventType = "click";
			break;
		case "mouseup":
			eventType = "mousedown";
			break;
		case "mousedown":
			eventType = "mouseup";
			break;
		case "mouseover":
			eventType = "mouseover";
			break;
		case "mouseout":
			eventType = "mouseout";
			break;
		case "mousemove":
			eventType = "mousemove";
			break;
		default:
			eventType = event.type;
		}
		var mouseEvent = new cocktail.core.event.MouseEvent(eventType,this._htmlElement,0.0,event.stageX,event.stageY,event.localX,event.localY,event.ctrlKey,event.shiftKey,event.altKey);
		return mouseEvent;
	}
	,__class__: cocktail.port.browser.Mouse
});
cocktail.port.browser.MouseCursor = $hxClasses["cocktail.port.browser.MouseCursor"] = function() {
	cocktail.core.mouse.AbstractMouseCursor.call(this);
};
cocktail.port.browser.MouseCursor.__name__ = ["cocktail","port","browser","MouseCursor"];
cocktail.port.browser.MouseCursor.__super__ = cocktail.core.mouse.AbstractMouseCursor;
cocktail.port.browser.MouseCursor.prototype = $extend(cocktail.core.mouse.AbstractMouseCursor.prototype,{
	setBitmapCursor: function(imageHTMLElement,hotSpot) {
		var cursorURL = imageHTMLElement.get_nativeElement().src;
		if(hotSpot == null) hotSpot = { x : 0.0, y : 0.0};
		this.setCursorStyle("url(" + cursorURL + ") " + hotSpot.x + " " + hotSpot.y + ", auto");
	}
	,hideCursor: function() {
		this.setCursorStyle("none");
	}
	,setDefaultCursor: function() {
		this.setCursorStyle("auto");
	}
	,setNativeOSCursor: function(value) {
		switch( (value)[1] ) {
		case 0:
			this.setCursorStyle("pointer");
			break;
		case 1:
			this.setCursorStyle("text");
			break;
		}
	}
	,setCursorStyle: function(style) {
		js.Lib.document.body.style.cursor = style;
	}
	,__class__: cocktail.port.browser.MouseCursor
});
cocktail.port.browser.NativeElementManagerImpl = $hxClasses["cocktail.port.browser.NativeElementManagerImpl"] = function() {
	cocktail.core.nativeElement.AbstractNativeElementManagerImpl.call(this);
};
cocktail.port.browser.NativeElementManagerImpl.__name__ = ["cocktail","port","browser","NativeElementManagerImpl"];
cocktail.port.browser.NativeElementManagerImpl.__super__ = cocktail.core.nativeElement.AbstractNativeElementManagerImpl;
cocktail.port.browser.NativeElementManagerImpl.prototype = $extend(cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype,{
	getRoot: function() {
		return js.Lib.document.body;
	}
	,createNativeElement: function(nativeElementType) {
		var nativeElement;
		var $e = (nativeElementType);
		switch( $e[1] ) {
		case 1:
			nativeElement = js.Lib.document.createElement("img");
			break;
		case 0:
			nativeElement = js.Lib.document.createElement("canvas");
			break;
		case 5:
			var name = $e[2];
			nativeElement = js.Lib.document.createElement(name);
			break;
		case 2:
			nativeElement = js.Lib.document.createElement("script");
			break;
		case 3:
			nativeElement = js.Lib.document.createElement("a");
			break;
		case 4:
			nativeElement = js.Lib.document.createElement("input");
			break;
		}
		return nativeElement;
	}
	,__class__: cocktail.port.browser.NativeElementManagerImpl
});
cocktail.port.browser.Style = $hxClasses["cocktail.port.browser.Style"] = function(coreStyle) {
	cocktail.core.style.adapter.AbstractStyle.call(this,coreStyle);
};
cocktail.port.browser.Style.__name__ = ["cocktail","port","browser","Style"];
cocktail.port.browser.Style.__super__ = cocktail.core.style.adapter.AbstractStyle;
cocktail.port.browser.Style.prototype = $extend(cocktail.core.style.adapter.AbstractStyle.prototype,{
	getVendorSpecificStyleName: function(nativeStyle,styleName) {
		var vendorSpecificStyleName;
		if(Reflect.hasField(nativeStyle,styleName)) vendorSpecificStyleName = styleName; else {
			var styleNameCap = styleName.charAt(0).toUpperCase();
			var styleNameEnd = styleName.substr(1);
			styleName = styleNameCap + styleNameEnd;
			if(Reflect.field(nativeStyle,"Moz" + styleName) != null) vendorSpecificStyleName = "Moz" + styleName; else if(Reflect.field(nativeStyle,"Webkit" + styleName) != null) vendorSpecificStyleName = "Webkit" + styleName; else if(Reflect.field(nativeStyle,"Ms" + styleName) != null) vendorSpecificStyleName = "Ms" + styleName; else if(Reflect.field(nativeStyle,"O" + styleName) != null) vendorSpecificStyleName = "O" + styleName; else vendorSpecificStyleName = null;
		}
		return vendorSpecificStyleName;
	}
	,set_verticalAlign: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.verticalAlign = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_verticalAlign.call(this,value);
		return value;
	}
	,set_color: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.color = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_color.call(this,value);
		return value;
	}
	,set_wordSpacing: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.wordSpacing = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_wordSpacing.call(this,value);
		return value;
	}
	,set_letterSpacing: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.letterSpacing = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_letterSpacing.call(this,value);
		return value;
	}
	,set_textTransform: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.textTransform = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_textTransform.call(this,value);
		return value;
	}
	,set_fontVariant: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.fontVariant = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_fontVariant.call(this,value);
		return value;
	}
	,set_fontFamily: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.fontFamily = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_fontFamily.call(this,value);
		return value;
	}
	,set_fontWeight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.fontWeight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_fontWeight.call(this,value);
		return value;
	}
	,set_fontStyle: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.fontStyle = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_fontStyle.call(this,value);
		return value;
	}
	,set_fontSize: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.fontSize = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_fontSize.call(this,value);
		return value;
	}
	,set_lineHeight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.lineHeight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_lineHeight.call(this,value);
		return value;
	}
	,set_marginLeft: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.marginLeft = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_marginLeft.call(this,value);
		return value;
	}
	,set_marginRight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.marginRight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_marginRight.call(this,value);
		return value;
	}
	,set_marginTop: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.marginTop = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_marginTop.call(this,value);
		return value;
	}
	,set_marginBottom: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.marginBottom = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_marginBottom.call(this,value);
		return value;
	}
	,set_paddingLeft: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.paddingLeft = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingLeft.call(this,value);
		return value;
	}
	,set_paddingRight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.paddingRight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingRight.call(this,value);
		return value;
	}
	,set_paddingTop: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.paddingTop = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingTop.call(this,value);
		return value;
	}
	,set_paddingBottom: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.paddingBottom = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingBottom.call(this,value);
		return value;
	}
	,set_display: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.display = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_display.call(this,value);
		return value;
	}
	,set_position: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.position = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_position.call(this,value);
		return value;
	}
	,set_width: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.width = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_width.call(this,value);
		return value;
	}
	,set_height: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.height = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_height.call(this,value);
		return value;
	}
	,set_minHeight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.minHeight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_minHeight.call(this,value);
		return value;
	}
	,set_maxHeight: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.maxHeight = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_maxHeight.call(this,value);
		return value;
	}
	,set_minWidth: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.minWidth = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_minWidth.call(this,value);
		return value;
	}
	,set_maxWidth: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.maxWidth = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_maxWidth.call(this,value);
		return value;
	}
	,set_top: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.top = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_top.call(this,value);
		return value;
	}
	,set_left: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.left = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_left.call(this,value);
		return value;
	}
	,set_bottom: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.bottom = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_bottom.call(this,value);
		return value;
	}
	,set_right: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.right = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_right.call(this,value);
		return value;
	}
	,set_textIndent: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.textIndent = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_textIndent.call(this,value);
		return value;
	}
	,set_CSSFloat: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.cssFloat = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_CSSFloat.call(this,value);
		return value;
	}
	,set_clear: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.clear = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_clear.call(this,value);
		return value;
	}
	,set_whiteSpace: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.whiteSpace = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_whiteSpace.call(this,value);
		return value;
	}
	,set_textAlign: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.textAlign = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_textAlign.call(this,value);
		return value;
	}
	,set_opacity: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.opacity = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_opacity.call(this,value);
		return value;
	}
	,set_visibility: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.visibility = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_visibility.call(this,value);
		return value;
	}
	,set_backgroundColor: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundColor = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundColor.call(this,value);
		return value;
	}
	,set_backgroundOrigin: function(value) {
		var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundOrigin.call(this,value);
		return value;
	}
	,set_backgroundClip: function(value) {
		var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundClip");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundClip.call(this,value);
		return value;
	}
	,set_backgroundImage: function(value) {
		var cssBackgroundImage = value;
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = cssBackgroundImage;
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-webkit-linear-gradient");
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-moz-linear-gradient");
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundImage.call(this,value);
		return value;
	}
	,set_backgroundPosition: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundPosition = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundPosition.call(this,value);
		return value;
	}
	,set_backgroundSize: function(value) {
		var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundSize");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundSize.call(this,value);
		return value;
	}
	,set_backgroundRepeat: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundRepeat = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundRepeat.call(this,value);
		return value;
	}
	,set_overflowX: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.overflowX = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowX.call(this,value);
		return value;
	}
	,set_overflowY: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.overflowY = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowY.call(this,value);
		return value;
	}
	,set_cursor: function(value) {
		this._coreStyle.get_htmlElement().get_nativeElement().style.cursor = value;
		cocktail.core.style.adapter.AbstractStyle.prototype.set_cursor.call(this,value);
		return value;
	}
	,__class__: cocktail.port.browser.Style
});
cocktail.port.browser.Text = $hxClasses["cocktail.port.browser.Text"] = function() {
	cocktail.core.dom.Text.call(this);
};
cocktail.port.browser.Text.__name__ = ["cocktail","port","browser","Text"];
cocktail.port.browser.Text.__super__ = cocktail.core.dom.Text;
cocktail.port.browser.Text.prototype = $extend(cocktail.core.dom.Text.prototype,{
	set_data: function(value) {
		if(this._nativeElement == null) this._nativeElement = js.Lib.document.createTextNode(value); else this._nativeElement.nodeValue = value;
		cocktail.core.dom.Text.prototype.set_data.call(this,value);
		return value;
	}
	,__class__: cocktail.port.browser.Text
});
cocktail.port.browser.Window = $hxClasses["cocktail.port.browser.Window"] = function(document) {
	cocktail.core.window.AbstractWindow.call(this,document);
};
cocktail.port.browser.Window.__name__ = ["cocktail","port","browser","Window"];
cocktail.port.browser.Window.__super__ = cocktail.core.window.AbstractWindow;
cocktail.port.browser.Window.prototype = $extend(cocktail.core.window.AbstractWindow.prototype,{
	set_onResize: function(value) {
		if(value == null) js.Lib.window.removeEventListener("resize",this.onNativeResize.$bind(this)); else js.Lib.window.addEventListener("resize",this.onNativeResize.$bind(this));
		return this._onResize = value;
	}
	,get_innerHeight: function() {
		return js.Lib.window.innerHeight;
	}
	,get_innerWidth: function() {
		return js.Lib.window.innerWidth;
	}
	,onNativeResize: function(event) {
		if(this._onResize != null) this._onResize(new cocktail.core.event.Event("resize",this));
	}
	,__class__: cocktail.port.browser.Window
});
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
hxtml.Browser = $hxClasses["hxtml.Browser"] = function(createElement,createTextNode,appendChild,setAttribute,invalidate,styleProxy) {
	this.createElement = createElement;
	this.createTextNode = createTextNode;
	this.appendChild = appendChild;
	this.setAttribute = setAttribute;
	this.invalidate = invalidate;
	this.styleProxy = styleProxy;
};
hxtml.Browser.__name__ = ["hxtml","Browser"];
hxtml.Browser.prototype = {
	html: null
	,domRoot: null
	,ids: null
	,invalid: null
	,createElement: null
	,createTextNode: null
	,appendChild: null
	,setAttribute: null
	,invalidate: null
	,styleProxy: null
	,register: function(id,d) {
		this.ids.set(id,d);
	}
	,setHtml: function(data) {
		var x = Xml.parse(data).firstElement();
		this.ids = new Hash();
		this.domRoot = this.make(x);
		this.refresh();
	}
	,refresh: function() {
		this.invalid = false;
		if(this.invalidate != null) this.invalidate();
	}
	,getById: function(id) {
		return this.ids.get(id);
	}
	,make: function(x) {
		switch(x.nodeType) {
		case Xml.CData:
			throw "assert";
			break;
		case Xml.PCData:case Xml.Comment:
			return this.createTextNode(x.getNodeValue());
		}
		var d;
		var name = x.getNodeName().toLowerCase();
		d = this.createElement(name);
		var allowSpaces = !(name == "head" || name == "link" || name == "meta" || name == "title" || name == "html");
		var allowComments = name == "style";
		var prev = null;
		var $it0 = x.iterator();
		while( $it0.hasNext() ) {
			var c = $it0.next();
			switch(c.nodeType) {
			case Xml.PCData:
				if(new EReg("^[ \n\r\t]*$","").match(c.getNodeValue())) {
					if(!allowSpaces || prev == null) continue;
				}
				break;
			case Xml.Comment:
				if(!allowComments) continue;
				break;
			default:
			}
			prev = this.make(c);
			this.appendChild(d,prev);
		}
		var $it1 = x.attributes();
		while( $it1.hasNext() ) {
			var a = $it1.next();
			a = a.toLowerCase();
			var v = x.get(a);
			switch(a) {
			case "id":
				this.register(v,d);
				this.setAttribute(d,a,v);
				break;
			case "style":
				new hxtml.CssParser().parse(v,d,this.styleProxy);
				break;
			case "class":
				throw "'class' attribute not implemented yet";
				break;
			default:
				this.setAttribute(d,a,v);
			}
		}
		return d;
	}
	,__class__: hxtml.Browser
}
hxtml.Token = $hxClasses["hxtml.Token"] = { __ename__ : ["hxtml","Token"], __constructs__ : ["TIdent","TString","TInt","TFloat","TDblDot","TSharp","TPOpen","TPClose","TExclam","TComma","TEof","TPercent","TSemicolon","TBrOpen","TBrClose","TDot","TSpaces","TSlash"] }
hxtml.Token.TIdent = function(i) { var $x = ["TIdent",0,i]; $x.__enum__ = hxtml.Token; $x.toString = $estr; return $x; }
hxtml.Token.TString = function(s) { var $x = ["TString",1,s]; $x.__enum__ = hxtml.Token; $x.toString = $estr; return $x; }
hxtml.Token.TInt = function(i) { var $x = ["TInt",2,i]; $x.__enum__ = hxtml.Token; $x.toString = $estr; return $x; }
hxtml.Token.TFloat = function(f) { var $x = ["TFloat",3,f]; $x.__enum__ = hxtml.Token; $x.toString = $estr; return $x; }
hxtml.Token.TDblDot = ["TDblDot",4];
hxtml.Token.TDblDot.toString = $estr;
hxtml.Token.TDblDot.__enum__ = hxtml.Token;
hxtml.Token.TSharp = ["TSharp",5];
hxtml.Token.TSharp.toString = $estr;
hxtml.Token.TSharp.__enum__ = hxtml.Token;
hxtml.Token.TPOpen = ["TPOpen",6];
hxtml.Token.TPOpen.toString = $estr;
hxtml.Token.TPOpen.__enum__ = hxtml.Token;
hxtml.Token.TPClose = ["TPClose",7];
hxtml.Token.TPClose.toString = $estr;
hxtml.Token.TPClose.__enum__ = hxtml.Token;
hxtml.Token.TExclam = ["TExclam",8];
hxtml.Token.TExclam.toString = $estr;
hxtml.Token.TExclam.__enum__ = hxtml.Token;
hxtml.Token.TComma = ["TComma",9];
hxtml.Token.TComma.toString = $estr;
hxtml.Token.TComma.__enum__ = hxtml.Token;
hxtml.Token.TEof = ["TEof",10];
hxtml.Token.TEof.toString = $estr;
hxtml.Token.TEof.__enum__ = hxtml.Token;
hxtml.Token.TPercent = ["TPercent",11];
hxtml.Token.TPercent.toString = $estr;
hxtml.Token.TPercent.__enum__ = hxtml.Token;
hxtml.Token.TSemicolon = ["TSemicolon",12];
hxtml.Token.TSemicolon.toString = $estr;
hxtml.Token.TSemicolon.__enum__ = hxtml.Token;
hxtml.Token.TBrOpen = ["TBrOpen",13];
hxtml.Token.TBrOpen.toString = $estr;
hxtml.Token.TBrOpen.__enum__ = hxtml.Token;
hxtml.Token.TBrClose = ["TBrClose",14];
hxtml.Token.TBrClose.toString = $estr;
hxtml.Token.TBrClose.__enum__ = hxtml.Token;
hxtml.Token.TDot = ["TDot",15];
hxtml.Token.TDot.toString = $estr;
hxtml.Token.TDot.__enum__ = hxtml.Token;
hxtml.Token.TSpaces = ["TSpaces",16];
hxtml.Token.TSpaces.toString = $estr;
hxtml.Token.TSpaces.__enum__ = hxtml.Token;
hxtml.Token.TSlash = ["TSlash",17];
hxtml.Token.TSlash.toString = $estr;
hxtml.Token.TSlash.__enum__ = hxtml.Token;
hxtml.Value = $hxClasses["hxtml.Value"] = { __ename__ : ["hxtml","Value"], __constructs__ : ["VIdent","VString","VUnit","VRGBA","VFloat","VInt","VHex","VList","VGroup","VUrl","VLabel","VSlash"] }
hxtml.Value.VIdent = function(i) { var $x = ["VIdent",0,i]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VString = function(s) { var $x = ["VString",1,s]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VUnit = function(v,unit) { var $x = ["VUnit",2,v,unit]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VRGBA = function(v) { var $x = ["VRGBA",3,v]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VFloat = function(v) { var $x = ["VFloat",4,v]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VInt = function(v) { var $x = ["VInt",5,v]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VHex = function(v) { var $x = ["VHex",6,v]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VList = function(l) { var $x = ["VList",7,l]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VGroup = function(l) { var $x = ["VGroup",8,l]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VUrl = function(v) { var $x = ["VUrl",9,v]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VLabel = function(v,val) { var $x = ["VLabel",10,v,val]; $x.__enum__ = hxtml.Value; $x.toString = $estr; return $x; }
hxtml.Value.VSlash = ["VSlash",11];
hxtml.Value.VSlash.toString = $estr;
hxtml.Value.VSlash.__enum__ = hxtml.Value;
hxtml.CssParser = $hxClasses["hxtml.CssParser"] = function() {
};
hxtml.CssParser.__name__ = ["hxtml","CssParser"];
hxtml.CssParser.prototype = {
	css: null
	,s: null
	,d: null
	,pos: null
	,spacesTokens: null
	,tokens: null
	,notImplemented: function() {
	}
	,applyStyle: function(r,v,s) {
		switch(r) {
		case "margin":
			var vl = (function($this) {
				var $r;
				var $e = (v);
				switch( $e[1] ) {
				case 8:
					var l = $e[2];
					$r = l;
					break;
				default:
					$r = [v];
				}
				return $r;
			}(this));
			var vUnits = new Array();
			var _g = 0;
			while(_g < vl.length) {
				var i = vl[_g];
				++_g;
				var vo = this.getValueObject(i);
				if(vo != null) vUnits.push(vo);
			}
			switch(vUnits.length) {
			case 1:
				s.setMarginTopNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginRightNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginBottomNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginLeftNum(this.d,vUnits[0].value,vUnits[0].unit);
				return true;
			case 2:
				s.setMarginTopNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginRightNum(this.d,vUnits[1].value,vUnits[1].unit);
				s.setMarginBottomNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginLeftNum(this.d,vUnits[1].value,vUnits[1].unit);
				return true;
			case 3:
				s.setMarginTopNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginRightNum(this.d,vUnits[1].value,vUnits[1].unit);
				s.setMarginBottomNum(this.d,vUnits[2].value,vUnits[2].unit);
				s.setMarginLeftNum(this.d,vUnits[1].value,vUnits[1].unit);
				return true;
			case 4:
				s.setMarginTopNum(this.d,vUnits[0].value,vUnits[0].unit);
				s.setMarginRightNum(this.d,vUnits[1].value,vUnits[1].unit);
				s.setMarginBottomNum(this.d,vUnits[2].value,vUnits[2].unit);
				s.setMarginLeftNum(this.d,vUnits[3].value,vUnits[3].unit);
				return true;
			}
			break;
		case "margin-left":
			var val = this.getIdent(v);
			if(val != null) {
				s.setMarginLeftKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setMarginLeftNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "margin-right":
			var val = this.getIdent(v);
			if(val != null) {
				s.setMarginRightKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setMarginRightNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "margin-top":
			var val = this.getIdent(v);
			if(val != null) {
				s.setMarginTopKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setMarginTopNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "margin-bottom":
			var val = this.getIdent(v);
			if(val != null) {
				s.setMarginBottomKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setMarginBottomNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "padding":
			var vl = (function($this) {
				var $r;
				var $e = (v);
				switch( $e[1] ) {
				case 8:
					var l = $e[2];
					$r = l;
					break;
				default:
					$r = [v];
				}
				return $r;
			}(this));
			var vUnits = new Array();
			var _g = 0;
			while(_g < vl.length) {
				var i = vl[_g];
				++_g;
				var vo = this.getValueObject(i);
				if(vo != null) vUnits.push(vo);
			}
			switch(vUnits.length) {
			case 1:
				s.setPaddingTop(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingRight(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingBottom(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingLeft(this.d,vUnits[0].value,vUnits[0].unit);
				return true;
			case 2:
				s.setPaddingTop(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingRight(this.d,vUnits[1].value,vUnits[1].unit);
				s.setPaddingBottom(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingLeft(this.d,vUnits[1].value,vUnits[1].unit);
				return true;
			case 3:
				s.setPaddingTop(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingRight(this.d,vUnits[1].value,vUnits[1].unit);
				s.setPaddingBottom(this.d,vUnits[2].value,vUnits[2].unit);
				s.setPaddingLeft(this.d,vUnits[1].value,vUnits[1].unit);
				return true;
			case 4:
				s.setPaddingTop(this.d,vUnits[0].value,vUnits[0].unit);
				s.setPaddingRight(this.d,vUnits[1].value,vUnits[1].unit);
				s.setPaddingBottom(this.d,vUnits[2].value,vUnits[2].unit);
				s.setPaddingLeft(this.d,vUnits[3].value,vUnits[3].unit);
				return true;
			}
			break;
		case "padding-left":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setPaddingLeft(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "padding-right":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setPaddingRight(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "padding-top":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setPaddingTop(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "padding-bottom":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setPaddingBottom(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "width":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setWidth(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "height":
			var i = this.getValueObject(v);
			if(i != null) {
				s.setHeight(this.d,i.value,i.unit);
				return true;
			}
			break;
		case "background-color":
			var $e = (v);
			switch( $e[1] ) {
			case 6:
				var v1 = $e[2];
				var val = v1.length == 6?Std.parseInt("0x" + v1):v1.length == 3?Std.parseInt("0x" + v1.charAt(0) + v1.charAt(0) + v1.charAt(1) + v1.charAt(1) + v1.charAt(2) + v1.charAt(2)):null;
				s.setBgColorNum(this.d,val);
				return true;
			case 3:
				var v1 = $e[2];
				s.setBgColorRGBA(this.d,v1);
				return true;
			case 0:
				var i = $e[2];
				s.setBgColorKey(this.d,i);
				return true;
			default:
			}
			break;
		case "background-repeat":
			s.setBgRepeat(this.d,[this.getIdent(v)]);
			return true;
		case "background-image":
			var $e = (v);
			switch( $e[1] ) {
			case 9:
				var url = $e[2];
				s.setBgImage(this.d,[url]);
				return true;
			case 0:
				var i = $e[2];
				s.setBgImage(this.d,[i]);
				return true;
			default:
			}
			break;
		case "background-attachment":
			s.setBgAttachment(this.d,this.getIdent(v));
			return true;
		case "background-position":
			s.setBgPosXNum(this.d,50,"%");
			s.setBgPosYNum(this.d,50,"%");
			return this.applyComposite(["-inner-bgpos-left","-inner-bgpos-top"],v,s);
		case "-inner-bgpos-top":
			var l = this.getValueObject(v);
			if(l != null) {
				s.setBgPosYNum(this.d,l.value,l.unit);
				return true;
			}
			s.setBgPosYKey(this.d,this.getIdent(v));
			return true;
		case "-inner-bgpos-left":
			var l = this.getValueObject(v);
			if(l != null) {
				s.setBgPosXNum(this.d,l.value,l.unit);
				return true;
			}
			s.setBgPosXKey(this.d,this.getIdent(v));
			return true;
		case "background":
			return this.applyComposite(["background-color","background-image","background-repeat","background-attachment","background-position"],v,s);
		case "font-family":
			var l = this.getList(v,this.getFontName.$bind(this));
			if(l != null) {
				s.setFontFamily(this.d,l);
				return true;
			}
			break;
		case "font-style":
			s.setFontStyle(this.d,this.getIdent(v));
			return true;
		case "font-variant":
			s.setFontVariant(this.d,this.getIdent(v));
			return true;
		case "font-weight":
			var val = this.getIdent(v);
			if(val != null) {
				s.setFontWeightKey(this.d,val);
				return true;
			}
			var $e = (v);
			switch( $e[1] ) {
			case 5:
				var i = $e[2];
				s.setFontWeightNum(this.d,i);
				return true;
			default:
			}
			break;
		case "font-size":
			var val = this.getIdent(v);
			if(val != null) {
				s.setFontSizeKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setFontSizeNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "font":
			var vl = (function($this) {
				var $r;
				var $e = (v);
				switch( $e[1] ) {
				case 8:
					var l = $e[2];
					$r = l;
					break;
				default:
					$r = [v];
				}
				return $r;
			}(this));
			var v1 = hxtml.Value.VGroup(vl);
			this.applyComposite(["font-style","font-variant","font-weight"],v1,s);
			this.applyComposite(["font-size"],v1,s);
			if(vl.length > 0) {
				switch( (vl[0])[1] ) {
				case 11:
					vl.shift();
					break;
				default:
				}
			}
			this.applyComposite(["line-height"],v1,s);
			this.applyComposite(["font-family"],v1,s);
			if(vl.length == 0) return true;
			break;
		case "color":
			var $e = (v);
			switch( $e[1] ) {
			case 6:
				var v1 = $e[2];
				var val = v1.length == 6?Std.parseInt("0x" + v1):v1.length == 3?Std.parseInt("0x" + v1.charAt(0) + v1.charAt(0) + v1.charAt(1) + v1.charAt(1) + v1.charAt(2) + v1.charAt(2)):null;
				s.setTextColorNum(this.d,val);
				return true;
			case 0:
				var i = $e[2];
				s.setTextColorKey(this.d,i);
				return true;
			default:
			}
			break;
		case "text-decoration":
			var idents = this.getGroup(v,this.getIdent.$bind(this));
			var _g = 0;
			while(_g < idents.length) {
				var i = idents[_g];
				++_g;
				s.setTextDecoration(this.d,i);
			}
			return true;
		case "text-transform":
			var val = this.getIdent(v);
			if(val != null) {
				s.setTextTransform(this.d,val);
				return true;
			}
			break;
		case "line-height":
			var val = this.getIdent(v);
			if(val != null) {
				s.setLineHeightKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setLineHeightNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "word-spacing":
			var val = this.getIdent(v);
			if(val != null) {
				s.setWordSpacingKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setWordSpacingNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "letter-spacing":
			var val = this.getIdent(v);
			if(val != null) {
				s.setLetterSpacingKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setLetterSpacingNum(this.d,l.value,l.unit);
				return true;
			}
			break;
		case "top":
			var val = this.getIdent(v);
			if(val != null) {
				s.setTopKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setTop(this.d,l.value,l.unit);
				return true;
			}
			return true;
		case "left":
			var val = this.getIdent(v);
			if(val != null) {
				s.setLeftKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setLeft(this.d,l.value,l.unit);
				return true;
			}
			return true;
		case "right":
			var val = this.getIdent(v);
			if(val != null) {
				s.setRightKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setRight(this.d,l.value,l.unit);
				return true;
			}
			return true;
		case "bottom":
			var val = this.getIdent(v);
			if(val != null) {
				s.setBottomKey(this.d,val);
				return true;
			}
			var l = this.getValueObject(v);
			if(l != null) {
				s.setBottom(this.d,l.value,l.unit);
				return true;
			}
			return true;
		case "display":
			s.setDisplay(this.d,this.getIdent(v));
			return true;
		case "position":
			s.setPosition(this.d,this.getIdent(v));
			return true;
		default:
			throw "Not implemented '" + r + "' = " + Std.string(v);
		}
		return false;
	}
	,applyComposite: function(names,v,s) {
		var vl = (function($this) {
			var $r;
			var $e = (v);
			switch( $e[1] ) {
			case 8:
				var l = $e[2];
				$r = l;
				break;
			default:
				$r = [v];
			}
			return $r;
		}(this));
		while(vl.length > 0) {
			var found = false;
			var _g = 0;
			while(_g < names.length) {
				var n = names[_g];
				++_g;
				var count = (function($this) {
					var $r;
					switch(n) {
					case "background-position":
						$r = 2;
						break;
					default:
						$r = 1;
					}
					return $r;
				}(this));
				if(count > vl.length) count = vl.length;
				while(count > 0) {
					var v1 = count == 1?vl[0]:hxtml.Value.VGroup(vl.slice(0,count));
					if(this.applyStyle(n,v1,s)) {
						found = true;
						names.remove(n);
						var _g1 = 0;
						while(_g1 < count) {
							var i = _g1++;
							vl.shift();
						}
						break;
					}
					count--;
				}
				if(found) break;
			}
			if(!found) return false;
		}
		return true;
	}
	,getValueObject: function(i) {
		return (function($this) {
			var $r;
			var $e = (i);
			switch( $e[1] ) {
			case 2:
				var u = $e[3], v = $e[2];
				$r = { value : v, unit : u};
				break;
			default:
				$r = null;
			}
			return $r;
		}(this));
	}
	,getGroup: function(v,f) {
		var $e = (v);
		switch( $e[1] ) {
		case 8:
			var l = $e[2];
			var a = [];
			var _g = 0;
			while(_g < l.length) {
				var v1 = l[_g];
				++_g;
				var v2 = f(v1);
				if(v2 == null) return null;
				a.push(v2);
			}
			return a;
		default:
			var v1 = f(v);
			return v1 == null?null:[v1];
		}
	}
	,getList: function(v,f) {
		var $e = (v);
		switch( $e[1] ) {
		case 7:
			var l = $e[2];
			var a = [];
			var _g = 0;
			while(_g < l.length) {
				var v1 = l[_g];
				++_g;
				var v2 = f(v1);
				if(v2 == null) return null;
				a.push(v2);
			}
			return a;
		default:
			var v1 = f(v);
			return v1 == null?null:[v1];
		}
	}
	,getPix: function(v) {
		return (function($this) {
			var $r;
			var $e = (v);
			switch( $e[1] ) {
			case 2:
				var u = $e[3], f = $e[2];
				$r = (function($this) {
					var $r;
					switch(u) {
					case "px":
						$r = f | 0;
						break;
					case "pt":
						$r = f * 4 / 3 | 0;
						break;
					default:
						$r = null;
					}
					return $r;
				}($this));
				break;
			case 5:
				var v1 = $e[2];
				$r = v1;
				break;
			default:
				$r = null;
			}
			return $r;
		}(this));
	}
	,getIdent: function(v) {
		return (function($this) {
			var $r;
			var $e = (v);
			switch( $e[1] ) {
			case 0:
				var v1 = $e[2];
				$r = v1;
				break;
			default:
				$r = null;
			}
			return $r;
		}(this));
	}
	,getCol: function(v) {
		return (function($this) {
			var $r;
			var $e = (v);
			switch( $e[1] ) {
			case 6:
				var v1 = $e[2];
				$r = v1.length == 6?Std.parseInt("0x" + v1):v1.length == 3?Std.parseInt("0x" + v1.charAt(0) + v1.charAt(0) + v1.charAt(1) + v1.charAt(1) + v1.charAt(2) + v1.charAt(2)):null;
				break;
			case 0:
				var i = $e[2];
				$r = (function($this) {
					var $r;
					switch(i) {
					case "black":
						$r = 0;
						break;
					case "red":
						$r = 16711680;
						break;
					case "lime":
						$r = 65280;
						break;
					case "blue":
						$r = 255;
						break;
					case "white":
						$r = 16777215;
						break;
					case "aqua":
						$r = 65535;
						break;
					case "fuchsia":
						$r = 16711935;
						break;
					case "yellow":
						$r = 16776960;
						break;
					case "maroon":
						$r = 8388608;
						break;
					case "green":
						$r = 32768;
						break;
					case "navy":
						$r = 128;
						break;
					case "olive":
						$r = 8421376;
						break;
					case "purple":
						$r = 8388736;
						break;
					case "teal":
						$r = 32896;
						break;
					case "silver":
						$r = 12632256;
						break;
					case "gray":case "grey":
						$r = 8421504;
						break;
					default:
						$r = null;
					}
					return $r;
				}($this));
				break;
			default:
				$r = null;
			}
			return $r;
		}(this));
	}
	,getFontName: function(v) {
		return (function($this) {
			var $r;
			var $e = (v);
			switch( $e[1] ) {
			case 1:
				var s = $e[2];
				$r = s;
				break;
			case 8:
				$r = (function($this) {
					var $r;
					var g = $this.getGroup(v,$this.getIdent.$bind($this));
					$r = g == null?null:g.join(" ");
					return $r;
				}($this));
				break;
			case 0:
				var i = $e[2];
				$r = i;
				break;
			default:
				$r = null;
			}
			return $r;
		}(this));
	}
	,unexpected: function(t) {
		throw "Unexpected " + Std.string(t);
		return null;
	}
	,expect: function(t) {
		var tk = this.readToken();
		if(tk != t) this.unexpected(tk);
	}
	,push: function(t) {
		this.tokens.push(t);
	}
	,isToken: function(t) {
		var tk = this.readToken();
		if(tk == t) return true;
		this.tokens.push(tk);
		return false;
	}
	,parse: function(css,d,s) {
		this.css = css;
		this.s = s;
		this.d = d;
		this.pos = 0;
		this.tokens = [];
		this.parseStyle(hxtml.Token.TEof);
	}
	,parseStyle: function(eof) {
		while(true) {
			if(this.isToken(eof)) break;
			var r = this.readIdent();
			this.expect(hxtml.Token.TDblDot);
			var v = this.readValue();
			var s = this.s;
			var $e = (v);
			switch( $e[1] ) {
			case 10:
				var val = $e[3], label = $e[2];
				if(label == "important") v = val;
				break;
			default:
			}
			if(!this.applyStyle(r,v,s)) throw "Invalid value " + Std.string(v) + " for css " + r;
			if(this.isToken(eof)) break;
			this.expect(hxtml.Token.TSemicolon);
		}
	}
	,readIdent: function() {
		var t = this.readToken();
		return (function($this) {
			var $r;
			var $e = (t);
			switch( $e[1] ) {
			case 0:
				var i = $e[2];
				$r = i;
				break;
			default:
				$r = $this.unexpected(t);
			}
			return $r;
		}(this));
	}
	,readValue: function(opt) {
		var t = this.readToken();
		var v = (function($this) {
			var $r;
			var $e = (t);
			switch( $e[1] ) {
			case 5:
				$r = hxtml.Value.VHex($this.readHex());
				break;
			case 0:
				var i = $e[2];
				$r = hxtml.Value.VIdent(i);
				break;
			case 1:
				var s = $e[2];
				$r = hxtml.Value.VString(s);
				break;
			case 2:
				var i = $e[2];
				$r = $this.readValueUnit(i,i);
				break;
			case 3:
				var f = $e[2];
				$r = $this.readValueUnit(f,null);
				break;
			case 17:
				$r = hxtml.Value.VSlash;
				break;
			default:
				$r = (function($this) {
					var $r;
					if(!opt) $this.unexpected(t);
					$this.tokens.push(t);
					$r = null;
					return $r;
				}($this));
			}
			return $r;
		}(this));
		if(v != null) v = this.readValueNext(v);
		return v;
	}
	,readHex: function() {
		var start = this.pos;
		while(true) {
			var c = this.css.cca(this.pos++);
			if(c >= 65 && c <= 70 || c >= 97 && c <= 102 || c >= 48 && c <= 57) continue;
			this.pos--;
			break;
		}
		return this.css.substr(start,this.pos - start);
	}
	,readValueUnit: function(f,i) {
		var t = this.readToken();
		return (function($this) {
			var $r;
			var $e = (t);
			switch( $e[1] ) {
			case 0:
				var i1 = $e[2];
				$r = hxtml.Value.VUnit(f,i1);
				break;
			case 11:
				$r = hxtml.Value.VUnit(f,"%");
				break;
			default:
				$r = (function($this) {
					var $r;
					$this.tokens.push(t);
					$r = i != null?hxtml.Value.VInt(i):hxtml.Value.VFloat(f);
					return $r;
				}($this));
			}
			return $r;
		}(this));
	}
	,readValueNext: function(v) {
		var t = this.readToken();
		return (function($this) {
			var $r;
			switch( (t)[1] ) {
			case 6:
				$r = (function($this) {
					var $r;
					var $e = (v);
					switch( $e[1] ) {
					case 0:
						var i = $e[2];
						$r = (function($this) {
							var $r;
							switch(i) {
							case "url":
								$r = $this.readValueNext(hxtml.Value.VUrl($this.readUrl()));
								break;
							case "rgba":
								$r = $this.readValueNext(hxtml.Value.VRGBA($this.readRGBA()));
								break;
							default:
								$r = (function($this) {
									var $r;
									$this.tokens.push(t);
									$r = v;
									return $r;
								}($this));
							}
							return $r;
						}($this));
						break;
					default:
						$r = (function($this) {
							var $r;
							$this.tokens.push(t);
							$r = v;
							return $r;
						}($this));
					}
					return $r;
				}($this));
				break;
			case 8:
				$r = (function($this) {
					var $r;
					var t1 = $this.readToken();
					$r = (function($this) {
						var $r;
						var $e = (t1);
						switch( $e[1] ) {
						case 0:
							var i = $e[2];
							$r = hxtml.Value.VLabel(i,v);
							break;
						default:
							$r = $this.unexpected(t1);
						}
						return $r;
					}($this));
					return $r;
				}($this));
				break;
			case 9:
				$r = $this.loopComma(v,$this.readValue());
				break;
			default:
				$r = (function($this) {
					var $r;
					$this.tokens.push(t);
					var v2 = $this.readValue(true);
					$r = v2 == null?v:$this.loopNext(v,v2);
					return $r;
				}($this));
			}
			return $r;
		}(this));
	}
	,loopNext: function(v,v2) {
		return (function($this) {
			var $r;
			var $e = (v2);
			switch( $e[1] ) {
			case 8:
				var l = $e[2];
				$r = (function($this) {
					var $r;
					l.unshift(v);
					$r = v2;
					return $r;
				}($this));
				break;
			case 7:
				var l = $e[2];
				$r = (function($this) {
					var $r;
					l[0] = $this.loopNext(v,l[0]);
					$r = v2;
					return $r;
				}($this));
				break;
			case 10:
				var v21 = $e[3], lab = $e[2];
				$r = hxtml.Value.VLabel(lab,$this.loopNext(v,v21));
				break;
			default:
				$r = hxtml.Value.VGroup([v,v2]);
			}
			return $r;
		}(this));
	}
	,loopComma: function(v,v2) {
		return (function($this) {
			var $r;
			var $e = (v2);
			switch( $e[1] ) {
			case 7:
				var l = $e[2];
				$r = (function($this) {
					var $r;
					l.unshift(v);
					$r = v2;
					return $r;
				}($this));
				break;
			case 10:
				var v21 = $e[3], lab = $e[2];
				$r = hxtml.Value.VLabel(lab,$this.loopComma(v,v21));
				break;
			default:
				$r = hxtml.Value.VList([v,v2]);
			}
			return $r;
		}(this));
	}
	,isSpace: function(c) {
		return c == 32 || c == 10 || c == 13 || c == 9;
	}
	,isIdentChar: function(c) {
		return c >= 97 && c <= 122 || c >= 65 && c <= 90 || c == 45;
	}
	,isNum: function(c) {
		return c >= 48 && c <= 57;
	}
	,next: function() {
		return this.css.cca(this.pos++);
	}
	,readUrl: function() {
		var c0 = this.css.cca(this.pos++);
		while(c0 == 32 || c0 == 10 || c0 == 13 || c0 == 9) c0 = this.css.cca(this.pos++);
		var quote = c0;
		if(quote == 39 || quote == 34) {
			this.pos--;
			var $e = (this.readToken());
			switch( $e[1] ) {
			case 1:
				var s = $e[2];
				var c01 = this.css.cca(this.pos++);
				while(c01 == 32 || c01 == 10 || c01 == 13 || c01 == 9) c01 = this.css.cca(this.pos++);
				if(c01 != 41) throw "Invalid char " + String.fromCharCode(c01);
				return s;
			default:
				throw "assert";
			}
		}
		var start = this.pos - 1;
		while(true) {
			if(c0 != c0) break;
			c0 = this.css.cca(this.pos++);
			if(c0 == 41) break;
		}
		return StringTools.trim(this.css.substr(start,this.pos - start - 1));
	}
	,readRGBA: function() {
		var c = this.css.cca(this.pos++);
		while(c == 32 || c == 10 || c == 13 || c == 9) c = this.css.cca(this.pos++);
		var start = this.pos - 1;
		while(true) {
			if(c != c) break;
			c = this.css.cca(this.pos++);
			if(c == 41) break;
		}
		return StringTools.trim(this.css.substr(start,this.pos - start - 1));
	}
	,readToken: function() {
		var t = this.tokens.pop();
		if(t != null) return t;
		while(true) {
			var c = this.css.cca(this.pos++);
			if(c != c) return hxtml.Token.TEof;
			if(c == 32 || c == 10 || c == 13 || c == 9) {
				if(this.spacesTokens) {
					while(this.isSpace(this.css.cca(this.pos++))) {
					}
					this.pos--;
					return hxtml.Token.TSpaces;
				}
				continue;
			}
			if(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c == 45) {
				var pos = this.pos - 1;
				do c = this.css.cca(this.pos++); while(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c == 45);
				this.pos--;
				return hxtml.Token.TIdent(this.css.substr(pos,this.pos - pos).toLowerCase());
			}
			if(c >= 48 && c <= 57) {
				var i = 0;
				do {
					i = i * 10 + (c - 48);
					c = this.css.cca(this.pos++);
				} while(c >= 48 && c <= 57);
				if(c == 46) {
					var f = i;
					var k = 0.1;
					while(this.isNum(c = this.css.cca(this.pos++))) {
						f += (c - 48) * k;
						k *= 0.1;
					}
					this.pos--;
					return hxtml.Token.TFloat(f);
				}
				this.pos--;
				return hxtml.Token.TInt(i);
			}
			switch(c) {
			case 58:
				return hxtml.Token.TDblDot;
			case 35:
				return hxtml.Token.TSharp;
			case 40:
				return hxtml.Token.TPOpen;
			case 41:
				return hxtml.Token.TPClose;
			case 33:
				return hxtml.Token.TExclam;
			case 37:
				return hxtml.Token.TPercent;
			case 59:
				return hxtml.Token.TSemicolon;
			case 46:
				return hxtml.Token.TDot;
			case 123:
				return hxtml.Token.TBrOpen;
			case 125:
				return hxtml.Token.TBrClose;
			case 44:
				return hxtml.Token.TComma;
			case 47:
				if((c = this.css.cca(this.pos++)) != 42) {
					this.pos--;
					return hxtml.Token.TSlash;
				}
				while(true) {
					while((c = this.css.cca(this.pos++)) != 42) if(c != c) throw "Unclosed comment";
					c = this.css.cca(this.pos++);
					if(c == 47) break;
					if(c != c) throw "Unclosed comment";
				}
				return this.readToken();
			case 39:case 34:
				var pos = this.pos;
				var k;
				while((k = this.css.cca(this.pos++)) != c) {
					if(k != k) throw "Unclosed string constant";
					if(k == 92) {
						throw "todo";
						continue;
					}
				}
				return hxtml.Token.TString(this.css.substr(pos,this.pos - pos - 1));
			default:
			}
			this.pos--;
			throw "Invalid char " + this.css.charAt(this.pos);
		}
		return null;
	}
	,__class__: hxtml.CssParser
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
	if(cellStyle != null) this._cellStyle = cellStyle; else this.initCellStyle();
	this._cellStyle.cell(this.node,cellPerLine);
};
org.intermedia.view.CellBase.__name__ = ["org","intermedia","view","CellBase"];
org.intermedia.view.CellBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CellBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	_cellStyle: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellStyle.setCellStyle, thumbnail : null, textBlock : null, title : null, author : null, line : null};
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
		cellWidthPercent = 100 / cellPerLine;
		cellWidthPercent -= 1;
	}
	return cellWidthPercent;
}
org.intermedia.view.CellStyle.computeWidthPixels = function(cellPerLine) {
	var cellWidthPixels = js.Lib.window.innerWidth;
	if(cellPerLine != 0) cellWidthPixels = cellWidthPixels / cellPerLine | 0;
	return cellWidthPixels;
}
org.intermedia.view.CellStyle.addBorder = function(node) {
	node.style.borderWidth = Std.string(1) + "px";
	node.style.borderColor = "#CCCCCC";
	node.style.borderStyle = "solid";
}
org.intermedia.view.CellStyle.removeBorder = function(node) {
	node.style.borderStyle = "none";
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
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = Std.string(5) + "px";
	node.style.paddingBottom = "0px";
	org.intermedia.view.CellStyle.addBorder(node);
	node.style.borderStyle = "none none solid none";
}
org.intermedia.view.CellTextStyle.setCellTextStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.paddingLeft = "8px";
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
	node.style.marginTop = Std.string(5) + "px";
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
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : org.intermedia.view.CellThumbStyle.setThumbnailStyle, textBlock : null, title : null, author : null, line : null};
	}
	,updateView: function() {
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			var croppedImage = new org.intermedia.view.CroppedImage(this._data.thumbUrl,this._thumbMask);
			this.node.appendChild(croppedImage.node);
		}
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
	node.style.overflow = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	return cellSize;
}
org.intermedia.view.CellThumbStyle.setThumbnailStyle = function(image,maskSize) {
	image.style.display = "inline";
	image.style.verticalAlign = "middle";
	image.style.opacity = 0;
	org.intermedia.view.ImageUtils.cropImage(image,maskSize);
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
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, thumbnail : org.intermedia.view.CellThumbText1Style.setThumbnailStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
	}
	,updateView: function() {
		org.intermedia.view.CellBase.prototype.updateView.call(this);
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			var croppedImage = new org.intermedia.view.CroppedImage(this._data.thumbUrl,this._thumbMask);
			this.node.appendChild(croppedImage.node);
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
	,__class__: org.intermedia.view.CellThumbText1
});
org.intermedia.view.CellThumbText1Style = $hxClasses["org.intermedia.view.CellThumbText1Style"] = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = ["org","intermedia","view","CellThumbText1Style"];
org.intermedia.view.CellThumbText1Style.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellSize = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine,35);
	node.style.height = Std.string(cellSize.height) + "px";
	node.style.overflow = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	return cellSize;
}
org.intermedia.view.CellThumbText1Style.setThumbnailStyle = function(image,maskSize) {
	org.intermedia.view.CellThumbStyle.setThumbnailStyle(image,maskSize);
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
	this.node.style.overflow = "hidden";
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
	,__class__: org.intermedia.view.CroppedImage
}
org.intermedia.view.DetailStyle = $hxClasses["org.intermedia.view.DetailStyle"] = function() { }
org.intermedia.view.DetailStyle.__name__ = ["org","intermedia","view","DetailStyle"];
org.intermedia.view.DetailStyle.setDefault = function(node) {
	node.style.display = "block";
	node.style.position = "absolute";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingBottom = "0px";
	node.style.width = "100%";
	node.style.height = "auto";
	node.style.top = Std.string(43) + "px";
	node.style.bottom = "0px";
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
	,buildView: function() {
		org.intermedia.view.DetailStyle.setDefault(this.node);
		this._titleContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setTitle(this._titleContainer);
		this._titleContainer.appendChild(this._titleElement);
		this.node.appendChild(this._titleContainer);
		this._authorContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setAuthor(this._authorContainer);
		this._authorContainer.appendChild(this._authorElement);
		this.node.appendChild(this._authorContainer);
		this._thumbnail = js.Lib.document.createElement("img");
		org.intermedia.view.DetailStyle.setThumbnail(this._thumbnail);
		this.node.appendChild(this._thumbnail);
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
	node.style.zIndex = 1000;
	node.style.backgroundImage = "url(assets/headerGrey.jpg)";
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
	,_backButtonContainer: null
	,getDisplayBackButton: function() {
		return this._displayBackButton;
	}
	,setDisplayBackButton: function(v) {
		this._displayBackButton = v;
		if(this._displayBackButton) this.node.appendChild(this._backButtonContainer); else if(this._backButtonContainer.parentNode != null) this.node.removeChild(this._backButtonContainer);
		return this._displayBackButton;
	}
	,buildView: function() {
		org.intermedia.view.HeaderStyle.setHeaderStyle(this.node);
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
	org.intermedia.view.ViewBase.call(this);
};
org.intermedia.view.HomePage.__name__ = ["org","intermedia","view","HomePage"];
org.intermedia.view.HomePage.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.HomePage.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onListItemSelected: null
	,buildView: function() {
		var me = this;
		var cell0Style = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : org.intermedia.view.CellThumbStyle.setThumbnailStyle, textBlock : null, title : null, author : null, line : null};
		var cell0 = new org.intermedia.view.CellThumb(1,cell0Style);
		cell0.setData(this._data[0]);
		cell0.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell0.getData());
		};
		this.node.appendChild(cell0.node);
		var cell1 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell1.setData(this._data[1]);
		cell1.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell1.getData());
		};
		this.node.appendChild(cell1.node);
		var cell2 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell2.setData(this._data[2]);
		cell2.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell2.getData());
		};
		this.node.appendChild(cell2.node);
		var cell3 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell3.setData(this._data[3]);
		cell3.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell3.getData());
		};
		this.node.appendChild(cell3.node);
		var cell4 = new org.intermedia.view.CellThumb(2,cell0Style);
		cell4.setData(this._data[4]);
		cell4.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell4.getData());
		};
		this.node.appendChild(cell4.node);
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
		image.style.height = Std.string(resizedImageSize.height) + "px";
		image.style.marginLeft = Std.string(-Math.abs(maskSize.width - resizedImageSize.width) / 2) + "px";
	} else {
		resizedImageSize.width = maskSize.width;
		resizedImageSize.height = resizedImageSize.width / imageRatio | 0;
		image.style.width = Std.string(resizedImageSize.width) + "px";
		image.style.marginTop = Std.string(-Math.abs(maskSize.height - resizedImageSize.height) / 2) + "px";
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
	this._listBottomLoader = js.Lib.document.createElement("img");
	org.intermedia.view.ListViewStyle.loader(this._listBottomLoader);
	this._listBottomLoader.src = "assets/loading.gif";
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
org.intermedia.view.ListViewStyle.loader = function(node) {
	var VERTICAL_MARGIN = 20;
	node.style.display = "block";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.marginTop = Std.string(VERTICAL_MARGIN) + "px";
	node.style.marginBottom = Std.string(VERTICAL_MARGIN) + "px";
	node.style.top = Std.string(js.Lib.window.innerHeight) + "px";
	node.style.zIndex = 1000;
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
	node.style.zIndex = 1000;
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
org.intermedia.view.MenuCellText = $hxClasses["org.intermedia.view.MenuCellText"] = function(cellStyle) {
	org.intermedia.view.CellBase.call(this);
	cellStyle(this.node);
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
			org.intermedia.view.MenuCellTextStyle.setCellTextStyle(cellTextContainer);
			this.node.appendChild(cellTextContainer);
		}
	}
	,__class__: org.intermedia.view.MenuCellText
});
org.intermedia.view.MenuCellTextStyle = $hxClasses["org.intermedia.view.MenuCellTextStyle"] = function() { }
org.intermedia.view.MenuCellTextStyle.__name__ = ["org","intermedia","view","MenuCellTextStyle"];
org.intermedia.view.MenuCellTextStyle.setCellStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = "0px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = Std.string(5) + "px";
	node.style.paddingBottom = "0px";
	node.style.width = "33%";
	node.style.minWidth = "33%";
	node.style.borderStyle = "none";
	node.style.backgroundColor = null;
}
org.intermedia.view.MenuCellTextStyle.setLeftCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.textAlign = "left";
	node.style.left = Std.string(5) + "px";
}
org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.textAlign = "center";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
}
org.intermedia.view.MenuCellTextStyle.setRightCellStyle = function(node) {
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.textAlign = "right";
	node.style.right = Std.string(5) + "px";
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
org.intermedia.view.MenuListViewStyle.setListStyle = function(node) {
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
	node.style.zIndex = 1000;
	node.style.backgroundImage = "url(\"assets/headerBlue.png\")";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
}
org.intermedia.view.MenuListViewStyle.prototype = {
	__class__: org.intermedia.view.MenuListViewStyle
}
org.intermedia.view.MenuListViewText = $hxClasses["org.intermedia.view.MenuListViewText"] = function() {
	this._index = 0;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.MenuListViewStyle.setListStyle(this.node);
};
org.intermedia.view.MenuListViewText.__name__ = ["org","intermedia","view","MenuListViewText"];
org.intermedia.view.MenuListViewText.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.MenuListViewText.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_index: null
	,index: null
	,getIndex: function() {
		return this._index;
	}
	,createCell: function() {
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
		this._index++;
		var cell = new org.intermedia.view.MenuCellText(style);
		return cell;
	}
	,onListItemSelectedCallback: function(cellData) {
		this.index = cellData.id;
		org.intermedia.view.ListViewBase.prototype.onListItemSelectedCallback.call(this,cellData);
	}
	,__class__: org.intermedia.view.MenuListViewText
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
org.intermedia.view.SwippableListView = $hxClasses["org.intermedia.view.SwippableListView"] = function() {
	org.intermedia.view.ListViewBase.call(this);
	this.setDisplayLoading(true);
	this._offset = { x : 0, y : 0};
	this._offsetStart = { x : 0, y : 0};
	this._initialPosition = { x : 0, y : 0};
	this._direction = org.intermedia.view.Direction.notYetSet;
	this._viewportWidth = js.Lib.window.innerWidth;
	this._viewportHeight = js.Lib.window.innerHeight;
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
	this.list1.node.style.left = Std.string(this._viewportWidth) + "px";
	this.list2 = new org.intermedia.view.ThumbTextList1(2);
	this.list2.id = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url;
	this._listViews.push(this.list2);
	this.list2.node.style.left = Std.string(2 * this._viewportWidth) + "px";
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
	this.initTouchEvents();
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
	,onHorizontalTweenEnd: null
	,_homePageData: null
	,_homePageDataSet: null
	,_viewportWidth: null
	,_viewportHeight: null
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
		this.horizontalReleaseTween();
		return v;
	}
	,onDownCallback2: function(event) {
		this._initialPosition.x = event.touches[0].pageX;
		this._initialPosition.y = event.touches[0].pageY;
		this._offsetStart.x = this.node.scrollLeft;
		this._offsetStart.y = this._currentListView.node.scrollTop;
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,onMoveCallback2: function(event) {
		this._offset.x = event.touches[0].pageX - this._initialPosition.x | 0;
		this._offset.y = event.touches[0].pageY - this._initialPosition.y | 0;
		if(this._direction == org.intermedia.view.Direction.notYetSet) {
			var absX = Math.abs(this._offset.x);
			var absY = Math.abs(this._offset.y);
			if(Math.max(absX,absY) >= 5) {
				if(absX > absY) this._direction = org.intermedia.view.Direction.horizontal; else this._direction = org.intermedia.view.Direction.vertical;
			}
		}
		if(this._direction == org.intermedia.view.Direction.horizontal) {
			event.preventDefault();
			this.node.scrollLeft = this._offsetStart.x - this._offset.x;
		} else if(this._direction == org.intermedia.view.Direction.vertical) {
			event.preventDefault();
			this._currentListView.node.scrollTop = this._offsetStart.y - this._offset.y;
		}
	}
	,onUpCallback2: function(event) {
		if(this._direction == org.intermedia.view.Direction.horizontal) {
			event.preventDefault();
			if(this._offset.x < -this._viewportWidth / 2) {
				if(this.getIndex() < this._listViews.length - 1) {
					var _g = this, _g1 = _g.getIndex();
					_g.setIndex(_g1 + 1);
					_g1;
				}
			} else if(this._offset.x > this._viewportWidth / 2) {
				if(this.getIndex() > 0) {
					var _g = this, _g1 = _g.getIndex();
					_g.setIndex(_g1 - 1);
					_g1;
				}
			} else this.setIndex(this.getIndex());
		} else if(this._direction == org.intermedia.view.Direction.vertical) this.verticalReleaseTween();
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,scrollToCurrentList: function() {
		this.node.scrollLeft = Std.parseInt(this._currentListView.node.style.left.substr(0,-2));
	}
	,horizontalReleaseTween: function() {
		var tween = new feffects.Tween(this.node.scrollLeft,Std.parseInt(this._currentListView.node.style.left),600,feffects.easing.Quint.easeOut);
		tween.setTweenHandlers(this.horizontalTweenMove.$bind(this),this.horizontalTweenEnd.$bind(this));
		tween.start();
	}
	,horizontalTweenMove: function(e) {
		this.node.scrollLeft = e | 0;
	}
	,horizontalTweenEnd: function(e) {
		if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd();
	}
	,verticalReleaseTween: function() {
		var verticalTweenEnd = 0;
		if(this._offset.y > 0) verticalTweenEnd = this._currentListView.node.scrollTop - 150; else verticalTweenEnd = this._currentListView.node.scrollTop + 150;
		var tween = new feffects.Tween(this._currentListView.node.scrollTop,verticalTweenEnd,600,feffects.easing.Quint.easeOut);
		tween.setTweenHandlers(this.onVerticalTweenMove.$bind(this),this.onVerticalTweenEnd.$bind(this));
		tween.start();
	}
	,onVerticalTweenMove: function(e) {
		this._currentListView.node.scrollTop = e | 0;
	}
	,onVerticalTweenEnd: function(e) {
	}
	,onScrollCallback: function(event) {
	}
	,touchHandler: function(event) {
		switch(event.type) {
		case "touchstart":
			this.onDownCallback2(event);
			break;
		case "touchmove":
			this.onMoveCallback2(event);
			break;
		case "touchend":
			this.onUpCallback2(event);
			break;
		default:
			return;
		}
	}
	,initTouchEvents: function() {
		document.addEventListener("touchstart",this.touchHandler.$bind(this),true);
		document.addEventListener("touchmove",this.touchHandler.$bind(this),true);
		document.addEventListener("touchend",this.touchHandler.$bind(this),true);
		document.addEventListener("touchcancel",this.touchHandler.$bind(this),true);
	}
	,__class__: org.intermedia.view.SwippableListView
	,__properties__: $extend(org.intermedia.view.ListViewBase.prototype.__properties__,{set_index:"setIndex",get_index:"getIndex"})
});
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
	node.style.overflow = "hidden";
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
	_homePageData: null
	,buildHomePage: function(homePageData) {
		var homePage = new org.intermedia.view.HomePage(homePageData);
		homePage.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this.node.appendChild(homePage.node);
	}
	,__class__: org.intermedia.view.ThumbTextList1Bis
});
org.intermedia.view.ViewManager = $hxClasses["org.intermedia.view.ViewManager"] = function(applicationModel,applicationController) {
	this._applicationModel = applicationModel;
	this._applicationController = applicationController;
	this._body = js.Lib.document.body;
	org.intermedia.view.ViewManagerStyle.setBodyStyle(this._body);
	this._header = new org.intermedia.view.HeaderView();
	this._header.setData("Market");
	this._header.onBackButtonClick = this.onHeaderBackButtonPressed.$bind(this);
	this._body.appendChild(this._header.node);
	this._menu = new org.intermedia.view.MenuListViewText();
	this._menu.displayListBottomLoader = false;
	this._menu.setData([{ id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"},{ id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"},{ id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}]);
	this._body.appendChild(this._menu.node);
	this._swippableListView = new org.intermedia.view.SwippableListView();
	this._currentView = this._swippableListView;
	this._body.appendChild(this._swippableListView.node);
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
		this._currentView = this._detailView;
		this.onDetailDataLoaded(cellData);
	}
	,onCellDataLoaded: function(listData) {
		if(listData.cells.length == 0) this._swippableListView.displayListBottomLoader = false;
		this._swippableListView.setData(listData);
	}
	,onDetailDataLoaded: function(detailData) {
		this._detailView.setData(detailData);
		this._header.setData("Infos");
		this._header.setDisplayBackButton(true);
		this._detailView.setDisplayLoading(false);
	}
	,onStartLoading: function() {
	}
	,onLoadingError: function(error) {
		haxe.Firebug.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 231, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
	}
	,onHeaderBackButtonPressed: function() {
		this._header.setData("Market");
		this._header.setDisplayBackButton(false);
		this._body.removeChild(this._detailView.node);
		this._body.appendChild(this._menu.node);
		this._body.appendChild(this._swippableListView.node);
		this._swippableListView.scrollToCurrentList();
		this._currentView = this._swippableListView;
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
	node.style.overflow = "hidden";
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
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_NONE = "butt";
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_ROUND = "round";
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_SQUARE = "square";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_ROUND = "round";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_MITER = "miter";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_BEVEL = "bevel";
cocktail.port.browser.DrawingManager.CANVAS_PATTERN_REPEAT = "repeat";
cocktail.port.browser.DrawingManager.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
cocktail.core.dom.Node.ELEMENT_NODE = 1;
cocktail.core.dom.Node.ATTRIBUTE_NODE = 2;
cocktail.core.dom.Node.TEXT_NODE = 3;
cocktail.core.dom.Node.CDATA_SECTION_NODE = 4;
cocktail.core.dom.Node.ENTITY_REFERENCE_NODE = 5;
cocktail.core.dom.Node.ENTITY_NODE = 6;
cocktail.core.dom.Node.PROCESSING_INSTRUCTION_NODE = 7;
cocktail.core.dom.Node.COMMENT_NODE = 8;
cocktail.core.dom.Node.DOCUMENT_NODE = 9;
cocktail.core.dom.Node.DOCUMENT_TYPE_NODE = 10;
cocktail.core.dom.Node.DOCUMENT_FRAGMENT_NODE = 11;
cocktail.core.dom.Node.NOTATION_NODE = 11;
cocktail.core.dom.Element.MATCH_ALL_TAG_NAME = "*";
cocktail.core.event.Event.SCROLL = "scroll";
cocktail.core.event.Event.LOAD = "load";
cocktail.core.event.Event.FOCUS = "focus";
cocktail.core.event.Event.BLUR = "blur";
cocktail.core.event.Event.ERROR = "error";
cocktail.core.event.Event.READY_STATE_CHANGE = "readystatechange";
cocktail.core.event.Event.RESIZE = "resize";
cocktail.core.event.KeyboardEvent.KEY_DOWN = "keydown";
cocktail.core.event.KeyboardEvent.KEY_UP = "keyup";
cocktail.core.event.MouseEvent.CLICK = "click";
cocktail.core.event.MouseEvent.MOUSE_UP = "mouseup";
cocktail.core.event.MouseEvent.MOUSE_DOWN = "mousedown";
cocktail.core.event.MouseEvent.MOUSE_OVER = "mouseover";
cocktail.core.event.MouseEvent.MOUSE_OUT = "mouseout";
cocktail.core.event.MouseEvent.MOUSE_MOVE = "mousemove";
cocktail.core.html.AbstractHTMLElement.HTML_ID_ATTRIBUTE = "id";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_BLANK = "_blank";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_SELF = "_self";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_PARENT = "_parent";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_TOP = "_top";
cocktail.core.html.AbstractHTMLAnchorElement.HTML_ANCHOR_TAG_NAME = "a";
cocktail.core.html.AbstractHTMLDocument.HTML_IMAGE_ELEMENT_TAG_NAME = "img";
cocktail.core.html.AbstractHTMLDocument.HTML_CANVAS_ELEMENT_TAG_NAME = "canvas";
cocktail.core.html.AbstractHTMLDocument.HTML_INPUT_ELEMENT_TAG_NAME = "input";
cocktail.core.html.AbstractHTMLDocument.HTML_ANCHOR_ELEMENT_TAG_NAME = "a";
cocktail.core.html.AbstractHTMLDocument.HTML_HTML_TAG_NAME = "html";
cocktail.core.html.AbstractHTMLDocument.HTML_BODY_TAG_NAME = "body";
cocktail.core.html.AbstractHTMLDocument.TAB_KEY_CODE = 9;
cocktail.core.html.AbstractHTMLDocument.ENTER_KEY_CODE = 13;
cocktail.core.html.AbstractHTMLDocument.SPACE_KEY_CODE = 32;
cocktail.core.html.AbstractHTMLHtmlElement.HTML_HTML_TAG_NAME = "html";
cocktail.core.html.AbstractHTMLImageElement.HTML_IMAGE_TAG_NAME = "img";
cocktail.core.html.AbstractHTMLImageElement.HTML_IMAGE_SRC_ATTRIBUTE = "src";
cocktail.core.html.AbstractHTMLInputElement.HTML_INPUT_TAG_NAME = "input";
cocktail.core.html.HTMLBodyElement.HTML_BODY_TAG_NAME = "body";
cocktail.core.html.HTMLCanvasElement.CANVAS_INTRINSIC_HEIGHT = 150;
cocktail.core.html.HTMLCanvasElement.CANVAS_INTRINSIC_WIDTH = 300;
cocktail.core.html.HTMLCanvasElement.HTML_CANVAS_TAG_NAME = "canvas";
cocktail.core.html.HTMLCanvasElement.CANVAS_2D_CONTEXT = "2d";
cocktail.core.resource.XMLHTTPRequest.READY_STATE_UNSENT = 0;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_OPENED = 1;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_HEADERS_RECEIVED = 2;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_LOADING = 3;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_DONE = 4;
cocktail.port.browser.Keyboard.KEY_DOWN_EVENT = "keydown";
cocktail.port.browser.Keyboard.KEY_UP_EVENT = "keyup";
cocktail.port.browser.Mouse.MOUSE_CLICK_EVENT = "click";
cocktail.port.browser.Mouse.MOUSE_UP_EVENT = "mouseup";
cocktail.port.browser.Mouse.MOUSE_DOWN_EVENT = "mousedown";
cocktail.port.browser.Mouse.MOUSE_OVER_EVENT = "mouseover";
cocktail.port.browser.Mouse.MOUSE_OUT_EVENT = "mouseout";
cocktail.port.browser.Mouse.MOUSE_MOVE_EVENT = "mousemove";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_NONE = "none";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_POINTER = "pointer";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_TEXT = "text";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_AUTO = "auto";
feffects.Tween._aTweens = new haxe.FastList();
feffects.Tween._aPaused = new haxe.FastList();
feffects.Tween.INTERVAL = 10;
js.Lib.onerror = null;
org.intermedia.model.ApplicationModel.CELL_QTY = 10;
org.intermedia.model.Feeds.FEED_1 = { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"};
org.intermedia.model.Feeds.FEED_2 = { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"};
org.intermedia.model.Feeds.FEED_3 = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"};
org.intermedia.view.CellTextStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.CellThumbStyle.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbStyle.CELL_RATIO = 16 / 9;
org.intermedia.view.CellThumbStyle.CELL_MAX_HEIGHT = 150;
org.intermedia.view.CellThumbStyle.CELL_HEIGHT = 100;
org.intermedia.view.CellThumbText1.TITLE_LENGTH = 40;
org.intermedia.view.CellThumbText1Style.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbText1Style.CELL_TEXT_WIDTH_PERCENT = 60;
org.intermedia.view.CellThumbText1Style.CELL_THUMB_WIDTH_PERCENT = 35;
org.intermedia.view.Constants.HEADER_HEIGHT = 43;
org.intermedia.view.Constants.MENU_HEIGHT = 35;
org.intermedia.view.Constants.LIST_TOP = 78;
org.intermedia.view.Constants.LIST_BG_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_BG_COLOR = "#FFFFFF";
org.intermedia.view.Constants.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.Constants.CELL_BORDER_WIDTH = 1;
org.intermedia.view.Constants.CELL_BORDER_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_HEIGHT = 90;
org.intermedia.view.LoadingViewStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_HORIZONTAL_PADDING = 5;
org.intermedia.view.SwippableListView.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.SwippableListView.VERTICAL_TWEEN_DELTA = 150;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEM_PER_LIST = 3;
org.intermedia.view.SwippableListView.LIST_QTY = 2;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEMS = 6;
org.intermedia.view.ViewManager.HEADER_HOME_TITLE = "Market";
org.intermedia.view.ViewManager.HEADER_DETAIL_TITLE = "Infos";
org.intermedia.Application.main()