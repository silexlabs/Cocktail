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
var IntHash = $hxClasses["IntHash"] = function() {
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
};
IntHash.__name__ = ["IntHash"];
IntHash.prototype = {
	h: null
	,set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,exists: function(key) {
		return this.h[key] != null;
	}
	,remove: function(key) {
		if(this.h[key] == null) return false;
		delete(this.h[key]);
		return true;
	}
	,keys: function() {
		var a = new Array();
		for( x in this.h ) a.push(x|0);
		return a.iterator();
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref[i];
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
	,__class__: IntHash
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
haxe.Resource = $hxClasses["haxe.Resource"] = function() { }
haxe.Resource.__name__ = ["haxe","Resource"];
haxe.Resource.content = null;
haxe.Resource.listNames = function() {
	var names = new Array();
	var _g = 0, _g1 = haxe.Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		names.push(x.name);
	}
	return names;
}
haxe.Resource.getString = function(name) {
	var _g = 0, _g1 = haxe.Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		if(x.name == name) {
			if(x.str != null) return x.str;
			var b = haxe.Unserializer.run(x.data);
			return b.toString();
		}
	}
	return null;
}
haxe.Resource.getBytes = function(name) {
	var _g = 0, _g1 = haxe.Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		if(x.name == name) {
			if(x.str != null) return haxe.io.Bytes.ofString(x.str);
			return haxe.Unserializer.run(x.data);
		}
	}
	return null;
}
haxe.Resource.prototype = {
	__class__: haxe.Resource
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
haxe.Unserializer = $hxClasses["haxe.Unserializer"] = function(buf) {
	this.buf = buf;
	this.length = buf.length;
	this.pos = 0;
	this.scache = new Array();
	this.cache = new Array();
	var r = haxe.Unserializer.DEFAULT_RESOLVER;
	if(r == null) {
		r = Type;
		haxe.Unserializer.DEFAULT_RESOLVER = r;
	}
	this.setResolver(r);
};
haxe.Unserializer.__name__ = ["haxe","Unserializer"];
haxe.Unserializer.initCodes = function() {
	var codes = new Array();
	var _g1 = 0, _g = haxe.Unserializer.BASE64.length;
	while(_g1 < _g) {
		var i = _g1++;
		codes[haxe.Unserializer.BASE64.cca(i)] = i;
	}
	return codes;
}
haxe.Unserializer.run = function(v) {
	return new haxe.Unserializer(v).unserialize();
}
haxe.Unserializer.prototype = {
	buf: null
	,pos: null
	,length: null
	,cache: null
	,scache: null
	,resolver: null
	,setResolver: function(r) {
		if(r == null) this.resolver = { resolveClass : function(_) {
			return null;
		}, resolveEnum : function(_) {
			return null;
		}}; else this.resolver = r;
	}
	,getResolver: function() {
		return this.resolver;
	}
	,get: function(p) {
		return this.buf.cca(p);
	}
	,readDigits: function() {
		var k = 0;
		var s = false;
		var fpos = this.pos;
		while(true) {
			var c = this.buf.cca(this.pos);
			if(c != c) break;
			if(c == 45) {
				if(this.pos != fpos) break;
				s = true;
				this.pos++;
				continue;
			}
			if(c < 48 || c > 57) break;
			k = k * 10 + (c - 48);
			this.pos++;
		}
		if(s) k *= -1;
		return k;
	}
	,unserializeObject: function(o) {
		while(true) {
			if(this.pos >= this.length) throw "Invalid object";
			if(this.buf.cca(this.pos) == 103) break;
			var k = this.unserialize();
			if(!Std["is"](k,String)) throw "Invalid object key";
			var v = this.unserialize();
			o[k] = v;
		}
		this.pos++;
	}
	,unserializeEnum: function(edecl,tag) {
		if(this.buf.cca(this.pos++) != 58) throw "Invalid enum format";
		var nargs = this.readDigits();
		if(nargs == 0) return Type.createEnum(edecl,tag);
		var args = new Array();
		while(nargs-- > 0) args.push(this.unserialize());
		return Type.createEnum(edecl,tag,args);
	}
	,unserialize: function() {
		switch(this.buf.cca(this.pos++)) {
		case 110:
			return null;
		case 116:
			return true;
		case 102:
			return false;
		case 122:
			return 0;
		case 105:
			return this.readDigits();
		case 100:
			var p1 = this.pos;
			while(true) {
				var c = this.buf.cca(this.pos);
				if(c >= 43 && c < 58 || c == 101 || c == 69) this.pos++; else break;
			}
			return Std.parseFloat(this.buf.substr(p1,this.pos - p1));
		case 121:
			var len = this.readDigits();
			if(this.buf.cca(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid string length";
			var s = this.buf.substr(this.pos,len);
			this.pos += len;
			s = StringTools.urlDecode(s);
			this.scache.push(s);
			return s;
		case 107:
			return Math.NaN;
		case 109:
			return Math.NEGATIVE_INFINITY;
		case 112:
			return Math.POSITIVE_INFINITY;
		case 97:
			var buf = this.buf;
			var a = new Array();
			this.cache.push(a);
			while(true) {
				var c = this.buf.cca(this.pos);
				if(c == 104) {
					this.pos++;
					break;
				}
				if(c == 117) {
					this.pos++;
					var n = this.readDigits();
					a[a.length + n - 1] = null;
				} else a.push(this.unserialize());
			}
			return a;
		case 111:
			var o = { };
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 114:
			var n = this.readDigits();
			if(n < 0 || n >= this.cache.length) throw "Invalid reference";
			return this.cache[n];
		case 82:
			var n = this.readDigits();
			if(n < 0 || n >= this.scache.length) throw "Invalid string reference";
			return this.scache[n];
		case 120:
			throw this.unserialize();
			break;
		case 99:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 119:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			var e = this.unserializeEnum(edecl,this.unserialize());
			this.cache.push(e);
			return e;
		case 106:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			this.pos++;
			var index = this.readDigits();
			var tag = Type.getEnumConstructs(edecl)[index];
			if(tag == null) throw "Unknown enum index " + name + "@" + index;
			var e = this.unserializeEnum(edecl,tag);
			this.cache.push(e);
			return e;
		case 108:
			var l = new List();
			this.cache.push(l);
			var buf = this.buf;
			while(this.buf.cca(this.pos) != 104) l.add(this.unserialize());
			this.pos++;
			return l;
		case 98:
			var h = new Hash();
			this.cache.push(h);
			var buf = this.buf;
			while(this.buf.cca(this.pos) != 104) {
				var s = this.unserialize();
				h.set(s,this.unserialize());
			}
			this.pos++;
			return h;
		case 113:
			var h = new IntHash();
			this.cache.push(h);
			var buf = this.buf;
			var c = this.buf.cca(this.pos++);
			while(c == 58) {
				var i = this.readDigits();
				h.set(i,this.unserialize());
				c = this.buf.cca(this.pos++);
			}
			if(c != 104) throw "Invalid IntHash format";
			return h;
		case 118:
			var d = Date.fromString(this.buf.substr(this.pos,19));
			this.cache.push(d);
			this.pos += 19;
			return d;
		case 115:
			var len = this.readDigits();
			var buf = this.buf;
			if(this.buf.cca(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid bytes length";
			var codes = haxe.Unserializer.CODES;
			if(codes == null) {
				codes = haxe.Unserializer.initCodes();
				haxe.Unserializer.CODES = codes;
			}
			var i = this.pos;
			var rest = len & 3;
			var size = (len >> 2) * 3 + (rest >= 2?rest - 1:0);
			var max = i + (len - rest);
			var bytes = haxe.io.Bytes.alloc(size);
			var bpos = 0;
			while(i < max) {
				var c1 = codes[buf.cca(i++)];
				var c2 = codes[buf.cca(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				var c3 = codes[buf.cca(i++)];
				bytes.b[bpos++] = (c2 << 4 | c3 >> 2) & 255;
				var c4 = codes[buf.cca(i++)];
				bytes.b[bpos++] = (c3 << 6 | c4) & 255;
			}
			if(rest >= 2) {
				var c1 = codes[buf.cca(i++)];
				var c2 = codes[buf.cca(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				if(rest == 3) {
					var c3 = codes[buf.cca(i++)];
					bytes.b[bpos++] = (c2 << 4 | c3 >> 2) & 255;
				}
			}
			this.pos += len;
			this.cache.push(bytes);
			return bytes;
		case 67:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			o.hxUnserialize(this);
			if(this.buf.cca(this.pos++) != 103) throw "Invalid custom data";
			return o;
		default:
		}
		this.pos--;
		throw "Invalid char " + this.buf.charAt(this.pos) + " at position " + this.pos;
	}
	,__class__: haxe.Unserializer
}
if(!haxe.io) haxe.io = {}
haxe.io.Bytes = $hxClasses["haxe.io.Bytes"] = function(length,b) {
	this.length = length;
	this.b = b;
};
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
}
haxe.io.Bytes.ofString = function(s) {
	var a = new Array();
	var _g1 = 0, _g = s.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = s.cca(i);
		if(c <= 127) a.push(c); else if(c <= 2047) {
			a.push(192 | c >> 6);
			a.push(128 | c & 63);
		} else if(c <= 65535) {
			a.push(224 | c >> 12);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		} else {
			a.push(240 | c >> 18);
			a.push(128 | c >> 12 & 63);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		}
	}
	return new haxe.io.Bytes(a.length,a);
}
haxe.io.Bytes.ofData = function(b) {
	return new haxe.io.Bytes(b.length,b);
}
haxe.io.Bytes.prototype = {
	length: null
	,b: null
	,get: function(pos) {
		return this.b[pos];
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,blit: function(pos,src,srcpos,len) {
		if(pos < 0 || srcpos < 0 || len < 0 || pos + len > this.length || srcpos + len > src.length) throw haxe.io.Error.OutsideBounds;
		var b1 = this.b;
		var b2 = src.b;
		if(b1 == b2 && pos > srcpos) {
			var i = len;
			while(i > 0) {
				i--;
				b1[i + pos] = b2[i + srcpos];
			}
			return;
		}
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			b1[i + pos] = b2[i + srcpos];
		}
	}
	,sub: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
		return new haxe.io.Bytes(len,this.b.slice(pos,pos + len));
	}
	,compare: function(other) {
		var b1 = this.b;
		var b2 = other.b;
		var len = this.length < other.length?this.length:other.length;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			if(b1[i] != b2[i]) return b1[i] - b2[i];
		}
		return this.length - other.length;
	}
	,readString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c2 = b[i++];
				var c3 = b[i++];
				s += fcc((c & 15) << 18 | (c2 & 127) << 12 | c3 << 6 & 127 | b[i++] & 127);
			}
		}
		return s;
	}
	,toString: function() {
		return this.readString(0,this.length);
	}
	,toHex: function() {
		var s = new StringBuf();
		var chars = [];
		var str = "0123456789abcdef";
		var _g1 = 0, _g = str.length;
		while(_g1 < _g) {
			var i = _g1++;
			chars.push(str.charCodeAt(i));
		}
		var _g1 = 0, _g = this.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.b[i];
			s.b[s.b.length] = String.fromCharCode(chars[c >> 4]);
			s.b[s.b.length] = String.fromCharCode(chars[c & 15]);
		}
		return s.b.join("");
	}
	,getData: function() {
		return this.b;
	}
	,__class__: haxe.io.Bytes
}
haxe.io.Error = $hxClasses["haxe.io.Error"] = { __ename__ : ["haxe","io","Error"], __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] }
haxe.io.Error.Blocked = ["Blocked",0];
haxe.io.Error.Blocked.toString = $estr;
haxe.io.Error.Blocked.__enum__ = haxe.io.Error;
haxe.io.Error.Overflow = ["Overflow",1];
haxe.io.Error.Overflow.toString = $estr;
haxe.io.Error.Overflow.__enum__ = haxe.io.Error;
haxe.io.Error.OutsideBounds = ["OutsideBounds",2];
haxe.io.Error.OutsideBounds.toString = $estr;
haxe.io.Error.OutsideBounds.__enum__ = haxe.io.Error;
haxe.io.Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe.io.Error; $x.toString = $estr; return $x; }
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
		this._dataLoader.loadCellData(feed,15,this.onCellsDataLoadComplete.$bind(this),this.onModelDataLoadError);
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
			haxe.Firebug.trace(feed + " => " + pageIndex,{ fileName : "DataLoader.hx", lineNumber : 74, className : "org.intermedia.model.DataLoader", methodName : "loadCellData"});
			fullUrl = feed + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex;
			var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,this.onCellsXmlLoaded.$bind(this),this.onLoadingError,feed);
		} else if(feed == { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed1"))); else if(feed == { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed2"))); else if(feed == { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed3")));
	}
	,loadDetailData: function(cellData,successCallback,errorCallback) {
		var me = this;
		this.onCellDetailLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var onLoadSuccessDelegate = function(listId,xml) {
			me.onCellDetailXmlLoaded(xml,cellData);
		};
		var fullUrl = "";
		if(this._online) {
			fullUrl = "http://www.silexlabs.org/feed/ep_get_item_info?format=rss2&p=" + cellData.id;
			var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,onLoadSuccessDelegate,this.onLoadingError);
		} else this.onCellDetailXmlLoaded(Xml.parse(haxe.Resource.getString("detail")),cellData);
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
		fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);
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
	,_style: null
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
		this._cellStyle = { cell : org.intermedia.view.CellStyle.setCellStyle};
	}
	,refreshStyles: function() {
		this._cellStyle.cell(this.node,this._cellPerLine);
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
	node.style.backgroundColor = "";
}
org.intermedia.view.CellStyle.computeWidthPercentage = function(cellPerLine,borderWidth) {
	if(borderWidth == null) borderWidth = 0;
	var cellWidthPercent = 100;
	if(cellPerLine != 0) cellWidthPercent = 100 / cellPerLine - borderWidth * 100 / js.Lib.window.innerWidth - borderWidth * 100 / (js.Lib.window.innerWidth * cellPerLine);
	return cellWidthPercent;
}
org.intermedia.view.CellStyle.computeWidthPixels = function(cellPerLine) {
	var cellWidthPixels = js.Lib.window.innerWidth;
	if(cellPerLine != 0) cellWidthPixels = cellWidthPixels / cellPerLine | 0;
	return cellWidthPixels;
}
org.intermedia.view.CellStyle.addBorder = function(node,borderWidth) {
	node.style.marginTop = Std.string(borderWidth) + "px";
	node.style.marginLeft = Std.string(borderWidth) + "px";
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
	org.intermedia.view.CellStyle.addBorder(node,1);
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
org.intermedia.view.CellThumb = $hxClasses["org.intermedia.view.CellThumb"] = function(cellPerLine,cellStyle) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine,cellStyle);
};
org.intermedia.view.CellThumb.__name__ = ["org","intermedia","view","CellThumb"];
org.intermedia.view.CellThumb.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumb.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_croppedImage: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbStyle.setThumbnailMaskStyle};
	}
	,updateView: function() {
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._cellStyle);
			this._croppedImage.setData(this._data);
			this.node.appendChild(this._croppedImage.node);
		}
	}
	,refreshStyles: function() {
		org.intermedia.view.CellBase.prototype.refreshStyles.call(this);
		this._croppedImage.refreshStyles();
	}
	,__class__: org.intermedia.view.CellThumb
});
org.intermedia.view.CellThumbStyle = $hxClasses["org.intermedia.view.CellThumbStyle"] = function() { }
org.intermedia.view.CellThumbStyle.__name__ = ["org","intermedia","view","CellThumbStyle"];
org.intermedia.view.CellThumbStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellWidthPercent = org.intermedia.view.CellStyle.computeWidthPercentage(cellPerLine,4);
	node.style.width = Std.string(cellWidthPercent) + "%";
	node.style.height = Std.string(90) + "px";
	node.style.maxHeight = Std.string(160) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node,1);
}
org.intermedia.view.CellThumbStyle.setThumbnailMaskStyle = function(node) {
	node.style.width = Std.string(100) + "%";
	node.style.height = Std.string(100) + "%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	node.style.display = "inline-block";
}
org.intermedia.view.CellThumbStyle.prototype = {
	__class__: org.intermedia.view.CellThumbStyle
}
org.intermedia.view.CellThumbText1 = $hxClasses["org.intermedia.view.CellThumbText1"] = function(cellPerLine,cellStyle) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine,cellStyle);
};
org.intermedia.view.CellThumbText1.__name__ = ["org","intermedia","view","CellThumbText1"];
org.intermedia.view.CellThumbText1.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumbText1.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_croppedImage: null
	,initCellStyle: function() {
		this._cellStyle = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbText1Style.setThumbnailMaskStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
	}
	,updateView: function() {
		org.intermedia.view.CellBase.prototype.updateView.call(this);
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._cellStyle);
			this._croppedImage.setData(this._data);
			this.node.appendChild(this._croppedImage.node);
		}
		var cellTextBlockContainer = js.Lib.document.createElement("div");
		this._cellStyle.textBlock(cellTextBlockContainer);
		this.node.appendChild(cellTextBlockContainer);
		if(this._data.title != "" && this._data.title != null) {
			var text = this._data.title;
			if(text.length > 42) {
				text = text.substr(0,42);
				text = text.substr(0,text.lastIndexOf(" ")) + "...";
			}
			var textElement = js.Lib.document.createTextNode(text);
			var cellTitleContainer = js.Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
			this._cellStyle.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
	}
	,refreshStyles: function() {
		org.intermedia.view.CellBase.prototype.refreshStyles.call(this);
		this._croppedImage.refreshStyles();
	}
	,__class__: org.intermedia.view.CellThumbText1
});
org.intermedia.view.CellThumbText1BisStyle = $hxClasses["org.intermedia.view.CellThumbText1BisStyle"] = function() { }
org.intermedia.view.CellThumbText1BisStyle.__name__ = ["org","intermedia","view","CellThumbText1BisStyle"];
org.intermedia.view.CellThumbText1BisStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellWidthPercent = org.intermedia.view.CellStyle.computeWidthPercentage(cellPerLine,4);
	node.style.width = Std.string(cellWidthPercent) + "%";
	node.style.height = Std.string(90) + "px";
	node.style.maxHeight = Std.string(160) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node,4);
}
org.intermedia.view.CellThumbText1BisStyle.prototype = {
	__class__: org.intermedia.view.CellThumbText1BisStyle
}
org.intermedia.view.CellThumbText1Style = $hxClasses["org.intermedia.view.CellThumbText1Style"] = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = ["org","intermedia","view","CellThumbText1Style"];
org.intermedia.view.CellThumbText1Style.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	node.style.verticalAlign = "middle";
	var cellWidthPercent = org.intermedia.view.CellStyle.computeWidthPercentage(cellPerLine,1);
	node.style.width = Std.string(cellWidthPercent) + "%";
	node.style.height = Std.string(90) + "px";
	node.style.maxHeight = Std.string(160) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node,1);
}
org.intermedia.view.CellThumbText1Style.setThumbnailMaskStyle = function(node) {
	node.style.marginTop = Std.string(8) + "%";
	node.style.marginLeft = "3%";
	node.style.width = Std.string(34) + "%";
	node.style.height = Std.string(70) + "%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	node.style.display = "inline-block";
}
org.intermedia.view.CellThumbText1Style.setTextBlockStyle = function(node) {
	node.style.display = "inline-block";
	node.style.marginTop = Std.string(4. | 0) + "%";
	node.style.marginLeft = "3%";
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
org.intermedia.view.CroppedImage = $hxClasses["org.intermedia.view.CroppedImage"] = function(style) {
	org.intermedia.view.ViewBase.call(this);
	this._style = style;
	this.node = js.Lib.document.createElement("div");
};
org.intermedia.view.CroppedImage.__name__ = ["org","intermedia","view","CroppedImage"];
org.intermedia.view.CroppedImage.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CroppedImage.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	_image: null
	,onImageLoadSuccess: null
	,updateView: function() {
		this._style.thumbnailMask(this.node);
		this.loadThumb(this._data.thumbUrl);
	}
	,loadThumb: function(imageUrl) {
		this._image = js.Lib.document.createElement("img");
		this._image.onload = this.onImageLoadSuccessCallback.$bind(this);
		this._image.src = imageUrl;
	}
	,onImageLoadSuccessCallback: function(event) {
		this.refreshStyles();
		this._image.style.opacity = 0;
		this.node.appendChild(this._image);
		haxe.Timer.delay(this.fadeIn.$bind(this),Std.random(1500));
		if(this.onImageLoadSuccess != null) this.onImageLoadSuccess();
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
	,refreshStyles: function() {
		var maskSize = { width : this.node.clientWidth, height : this.node.clientHeight};
		org.intermedia.view.ImageUtils.cropImage(this._image,maskSize);
	}
	,__class__: org.intermedia.view.CroppedImage
});
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
	this._moveHandler.onVerticalScroll = this.onVerticalScroll.$bind(this);
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
	,onVerticalScroll: function(y) {
		this.node.scrollTop = this._moveHandler.initialScrollPosition.y - y;
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
	node.style.backgroundImage = "url(" + "" + ")";
}
org.intermedia.view.HeaderStyle.setHeaderStaticStyle = function(node) {
	node.style.position = "static";
	node.style.display = "block";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = "58px";
}
org.intermedia.view.HeaderStyle.setHeaderTextStyle = function(node) {
	node.style.position = "absolute";
	node.style.color = "#EEEEEE";
	node.style.fontSize = "20px";
	node.style.fontWeight = "bold";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.textAlign = "center";
	node.style.paddingTop = "10px";
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
		var cellStyle = { cell : org.intermedia.view.CellThumbText1BisStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbStyle.setThumbnailMaskStyle};
		var cell0 = new org.intermedia.view.CellThumb(1,cellStyle);
		cell0.setData(this._data[0]);
		cell0.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell0.getData());
		};
		this.node.appendChild(cell0.node);
		this.cells.push(cell0);
		var cell1 = new org.intermedia.view.CellThumb(2,cellStyle);
		cell1.setData(this._data[1]);
		cell1.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell1.getData());
		};
		this.node.appendChild(cell1.node);
		this.cells.push(cell1);
		var cell2 = new org.intermedia.view.CellThumb(2,cellStyle);
		cell2.setData(this._data[2]);
		cell2.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell2.getData());
		};
		this.node.appendChild(cell2.node);
		this.cells.push(cell2);
		var cell3 = new org.intermedia.view.CellThumb(2,cellStyle);
		cell3.setData(this._data[3]);
		cell3.node.onmouseup = function(mouseEventData) {
			me.onListItemSelectedCallback(cell3.getData());
		};
		this.node.appendChild(cell3.node);
		this.cells.push(cell3);
		var cell4 = new org.intermedia.view.CellThumb(2,cellStyle);
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
	this._waitingData = true;
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
	,_bottomLoaderImage: null
	,_waitingData: null
	,buildBottomLoader: function() {
		this._bottomLoaderImage = js.Lib.document.createElement("img");
		org.intermedia.view.ListViewStyle.loaderImage(this._bottomLoaderImage);
		this._bottomLoaderImage.src = "assets/loading.gif";
		this._listBottomLoader = js.Lib.document.createElement("div");
		this._listBottomLoader.appendChild(this._bottomLoaderImage);
		org.intermedia.view.CellStyle.setCellStyle(this._listBottomLoader);
	}
	,updateView: function() {
		var me = this;
		this._waitingData = false;
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
		if(this.node.parentNode.parentNode != null) {
		}
	}
	,createCell: function() {
		var cell = new org.intermedia.view.CellBase();
		return cell;
	}
	,onListItemSelectedCallback: function(cellData) {
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	}
	,onScrollCallback: function(event) {
		if(this.node.scrollTop >= this.node.scrollHeight - (js.Lib.window.innerHeight - 78) - 10) this.onDataRequestCallback(this.id);
	}
	,onDataRequestCallback: function(id) {
		if(this.onDataRequest != null) {
			haxe.Firebug.trace("List " + id + " data requested",{ fileName : "ListViewBase.hx", lineNumber : 192, className : "org.intermedia.view.ListViewBase", methodName : "onDataRequestCallback"});
			this._waitingData = true;
			this.onDataRequest(id);
		}
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
	node.style.height = "100%";
	node.style.top = "0px";
	node.style.bottom = "0px";
	node.style.verticalAlign = "top";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
	node.style.backgroundColor = "";
}
org.intermedia.view.ListViewStyle.loaderImage = function(node) {
	node.style.display = "block";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.marginTop = "0px";
	node.style.marginBottom = Std.string(10) + "px";
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
	node.style.paddingTop = Std.string(7) + "px";
	node.style.paddingBottom = Std.string(7) + "px";
	node.style.width = "auto";
	org.intermedia.view.CellStyle.removeBorder(node);
	node.style.backgroundColor = null;
}
org.intermedia.view.MenuCellTextStyle.setCellTextStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.paddingRight = Std.string(5) + "px";
	node.style.paddingLeft = Std.string(5) + "px";
	node.style.fontSize = "16px";
	node.style.lineHeight = "normal";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.fontVariant = "normal";
	node.style.textTransform = "none";
	node.style.letterSpacing = "normal";
	node.style.wordSpacing = "normal";
	node.style.textIndent = "0px";
	node.style.whiteSpace = "normal";
	node.style.verticalAlign = "middle";
	node.style.color = "#AAAAAA";
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
	node.style.backgroundImage = "url(" + "" + ")";
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
	this._menuItem0LeftTarget = 0;
	this._menuItem1LeftTarget = 0;
	this._menuItem2LeftTarget = 0;
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
	,updateView: function() {
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var field = _g1[_g];
			++_g;
			var cell = this.createCell();
			cell.setData(Reflect.field(this._data,field));
			this._cells.push(cell);
			this.node.appendChild(cell.node);
		}
		if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
		if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
		this.computeMenuItemsWidth();
		this.setIndex(1);
		this.onResizeCallback();
	}
	,createCell: function() {
		var cell = new org.intermedia.view.MenuCellText();
		return cell;
	}
	,getIndex: function() {
		return this._index;
	}
	,setIndex: function(v) {
		this._cells[this._index].node.style.fontWeight = "normal";
		this._cells[v].node.style.fontWeight = "bold";
		this._index = v;
		return v;
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
	,computeMenuItemsLeftTarget: function(targetIndex) {
		switch(targetIndex) {
		case 0:
			this._menuItem0LeftTarget = (js.Lib.window.innerWidth - this._menuItem0Width) / 2 - 2.5 | 0;
			this._menuItem1LeftTarget = js.Lib.window.innerWidth - 30 | 0;
			this._menuItem2LeftTarget = 3 * js.Lib.window.innerWidth / 2 | 0;
			break;
		case 1:
			this._menuItem0LeftTarget = -(this._menuItem0Width - 30) | 0;
			this._menuItem1LeftTarget = (js.Lib.window.innerWidth - this._menuItem1Width - 5) / 2 | 0;
			this._menuItem2LeftTarget = js.Lib.window.innerWidth - 30 | 0;
			break;
		case 2:
			this._menuItem0LeftTarget = -js.Lib.window.innerWidth / 2 | 0;
			this._menuItem1LeftTarget = -(this._menuItem1Width - 30) | 0;
			this._menuItem2LeftTarget = (js.Lib.window.innerWidth - this._menuItem2Width) / 2 - 2.5 | 0;
			break;
		default:
		}
	}
	,moveHorizontally: function(ratio) {
		haxe.Firebug.trace(ratio,{ fileName : "MenuListViewText.hx", lineNumber : 330, className : "org.intermedia.view.MenuListViewText", methodName : "moveHorizontally"});
		if(ratio > 0) this.computeMenuItemsLeftTarget(Math.max(this._index - 1,0) | 0); else if(ratio < 0) this.computeMenuItemsLeftTarget(Math.min(this._index + 1,2) | 0);
		this.menuItem0Move(this._menuItem0LeftPos + Math.abs(this._menuItem0LeftTarget - this._menuItem0LeftPos) * ratio);
		this.menuItem1Move(this._menuItem1LeftPos + Math.abs(this._menuItem1LeftTarget - this._menuItem1LeftPos) * ratio);
		this.menuItem2Move(this._menuItem2LeftPos + Math.abs(this._menuItem2LeftTarget - this._menuItem2LeftPos) * ratio);
	}
	,horizontalTweenEnd: function(newIndex) {
		haxe.Firebug.trace(this._menuItem0LeftTarget + "," + this._menuItem1LeftTarget + "," + this._menuItem2LeftTarget,{ fileName : "MenuListViewText.hx", lineNumber : 376, className : "org.intermedia.view.MenuListViewText", methodName : "horizontalTweenEnd"});
		this.setIndex(newIndex);
		this.computeMenuItemsLeftPos();
	}
	,onResizeCallback: function() {
		this.computeMenuItemsLeftTarget(this._index);
		this.menuItem0Move(this._menuItem0LeftTarget);
		this.menuItem1Move(this._menuItem1LeftTarget);
		this.menuItem2Move(this._menuItem2LeftTarget);
		this.computeMenuItemsLeftPos();
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
	this.initialScrollPosition = { x : 0, y : 0};
	this.init();
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
	,onHorizontalTweenEnd: null
	,_horizontalTween: null
	,_verticalTween: null
	,_timer: null
	,_verticalVelocity: null
	,_previousY: null
	,init: function() {
		this._initialPosition = { x : 0, y : 0};
		this._offset = { x : 0, y : 0};
		this._scrollPosition = { x : 0, y : 0};
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
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
		this.init();
		if(this._horizontalTween != null && this._horizontalTween.isPlaying) this._horizontalTween.pause();
		if(this._verticalTween != null && this._verticalTween.isPlaying) this._verticalTween.stop();
		this._initialPosition.x = event.touches[0].pageX;
		this._initialPosition.y = event.touches[0].pageY;
		this._timer = new haxe.Timer(100);
		this._verticalVelocity = 0;
		this._previousY = 0;
		this._timer.run = this.computeVelocity.$bind(this);
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
		if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalMoveCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) this.onVerticalMoveCallback(event);
	}
	,onHorizontalMoveCallback: function(event) {
		event.preventDefault();
		this._scrollPosition = { x : this.initialScrollPosition.x - this._offset.x, y : this.initialScrollPosition.y};
		this.onHorizontalScrollCallback(this._offset.x);
	}
	,onVerticalMoveCallback: function(event) {
		event.preventDefault();
		this._scrollPosition = { x : this.initialScrollPosition.x, y : this.initialScrollPosition.y - this._offset.y};
		this.onVerticalScrollCallback(this._offset.y);
	}
	,onUpCallback: function(event) {
		if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalUpCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) this.verticalReleaseTween();
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,onHorizontalUpCallback: function(event) {
		if(this.onHorizontalUp != null) this.onHorizontalUp(event,this._offset.x);
	}
	,horizontalReleaseTween: function(xOrigin,xTarget) {
		this._horizontalTween = new feffects.Tween(-xOrigin,-xTarget,150,feffects.easing.Quint.easeOut);
		this._horizontalTween.setTweenHandlers(this.onHorizontalScrollCallback.$bind(this),this.horizontalTweenEnd.$bind(this));
		this._horizontalTween.start();
	}
	,onHorizontalScrollCallback: function(xOffset) {
		if(this.onHorizontalScroll != null) this.onHorizontalScroll(xOffset | 0);
	}
	,onHorizontalTweenCallback: function(e) {
		if(this.onHorizontalTween != null) this.onHorizontalTween(e | 0);
	}
	,horizontalTweenEnd: function(e) {
		if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd(e | 0);
	}
	,verticalReleaseTween: function() {
		this._timer.stop();
		var verticalTweenEnd = 0;
		verticalTweenEnd = this._offset.y + (this._verticalVelocity * 100 | 0);
		this._verticalTween = new feffects.Tween(this._offset.y,verticalTweenEnd,600,feffects.easing.Quint.easeOut);
		this._verticalTween.setTweenHandlers(this.onVerticalScrollCallback.$bind(this),this.onVerticalTweenEnd.$bind(this));
		this._verticalTween.start();
	}
	,onVerticalScrollCallback: function(e) {
		if(this.onVerticalScroll != null) this.onVerticalScroll(e | 0);
	}
	,onVerticalTweenEnd: function(e) {
	}
	,computeVelocity: function() {
		this._verticalVelocity = this.deriv(this._previousY,this._offset.y);
		this._previousY = Std.parseInt(Std.string(this._offset.y));
	}
	,deriv: function(a,b) {
		return (b - a) / 100;
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
	this._scrollHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.both);
	this._scrollHandler.onVerticalScroll = this.onVerticalScroll.$bind(this);
	this._scrollHandler.onHorizontalScroll = this.onHorizontalScrollCallback.$bind(this);
	this._scrollHandler.onHorizontalUp = this.onHorizontalUpCallback.$bind(this);
	this._scrollHandler.onHorizontalTween = this.onHorizontalScrollCallback.$bind(this);
	this._scrollHandler.onHorizontalTweenEnd = this.onHorizontalTweenEndCallback.$bind(this);
	this.addTouchEvents();
	org.intermedia.view.SwippableListViewStyle.setSwippableListStyle(this.node);
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
	,_scrollHandler: null
	,onHorizontalMove: null
	,onHorizontalTweenEnd: null
	,onHorizontalUp: null
	,positionLists: function() {
		this.list1.node.style.left = Std.string(js.Lib.window.innerWidth) + "px";
		this.list2.node.style.left = Std.string(2 * js.Lib.window.innerWidth) + "px";
	}
	,updateView: function() {
		this._waitingData = false;
		var _g = 0, _g1 = this._listViews;
		while(_g < _g1.length) {
			var list = _g1[_g];
			++_g;
			if(this._data.id == list.id && this._data.id != this.list1.id) {
				if(this._homePageData.length < 6) {
					var _g2 = 0;
					while(_g2 < 3) {
						var i = _g2++;
						this._homePageData.push(this.getData().cells[i]);
					}
				}
				list.setData(this._data.cells);
				break;
			}
			if(this._data.id == this.list1.id) this._list1Data = this._data.cells;
		}
		if(!this._homePageDataSet && this._homePageData.length == 6) {
			this.list1.buildHomePage(this._homePageData);
			this._homePageDataSet = true;
			this.setDisplayLoading(false);
		}
		if(this._homePageDataSet) {
			this.list1.setData(this._list1Data);
			if(this._listsContainer.parentNode == null) this.node.appendChild(this._listsContainer);
			this.scrollToCurrentList();
		}
	}
	,getIndex: function() {
		return this._index;
	}
	,setIndex: function(v) {
		this._currentListView.onListItemSelected = null;
		this._index = v;
		this._currentListView = this._listViews[v];
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._scrollHandler.horizontalReleaseTween(this.node.scrollLeft - this._scrollHandler.initialScrollPosition.x,this._currentListView.node.offsetLeft - this._scrollHandler.initialScrollPosition.x);
		return v;
	}
	,scrollToCurrentList: function() {
		this.node.scrollLeft = Std.parseInt(this._currentListView.node.style.left.substr(0,-2));
		this._scrollHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this._currentListView.node.scrollTop};
	}
	,onResizeCallback: function(event) {
		org.intermedia.view.SwippableListViewStyle.setSwippableListStyle(this.node);
		this.positionLists();
		this.scrollToCurrentList();
		var _g = 0, _g1 = this._listViews;
		while(_g < _g1.length) {
			var list = _g1[_g];
			++_g;
			list.refreshStyles();
		}
	}
	,onHorizontalScrollCallback: function(xOffset) {
		this._currentListView.onListItemSelected = null;
		var horizontalRatio = this.computeHorizontalRatio(xOffset);
		this.node.scrollLeft = this._scrollHandler.initialScrollPosition.x - xOffset;
		if(this.node.scrollLeft > this.list0.node.offsetLeft && this.node.scrollLeft < this.list2.node.offsetLeft) {
			if(this.onHorizontalMove != null && horizontalRatio != 0) this.onHorizontalMove(horizontalRatio);
		}
	}
	,onHorizontalTweenEndCallback: function(xOffset) {
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		var horizontalRatio = this.computeHorizontalRatio(xOffset);
		if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd(this._index);
	}
	,onVerticalScroll: function(yOffset) {
		this._currentListView.node.scrollTop = this._scrollHandler.initialScrollPosition.y - yOffset;
	}
	,onHorizontalUpCallback: function(event,xOffset) {
		event.preventDefault();
		if(xOffset < -js.Lib.window.innerHeight * 0.1) {
			if(this.getIndex() < this._listViews.length - 1) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 + 1);
				_g1;
			}
		} else if(xOffset > js.Lib.window.innerHeight * 0.1) {
			if(this.getIndex() > 0) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 - 1);
				_g1;
			}
		} else this.setIndex(this.getIndex());
	}
	,onScrollCallback: function(event) {
	}
	,addTouchEvents: function() {
		this.node.addEventListener("touchstart",this.touchStart.$bind(this),false);
		this.node.addEventListener("touchmove",this.touchMove.$bind(this),false);
		this.node.addEventListener("touchend",this.touchEnd.$bind(this),false);
		this.node.addEventListener("touchcancel",($_=this._scrollHandler,$_.touchHandler.$bind($_)),false);
	}
	,touchStart: function(event) {
		this._scrollHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this._currentListView.node.scrollTop};
		this._scrollHandler.touchHandler(event);
	}
	,touchMove: function(event) {
		this._currentListView.onListItemSelected = null;
		this._scrollHandler.touchHandler(event);
	}
	,touchEnd: function(event) {
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._scrollHandler.touchHandler(event);
	}
	,computeHorizontalRatio: function(xOffset) {
		var ratio = 0;
		if(js.Lib.window.innerWidth != 0) ratio = xOffset / js.Lib.window.innerWidth;
		return ratio;
	}
	,__class__: org.intermedia.view.SwippableListView
	,__properties__: $extend(org.intermedia.view.ListViewBase.prototype.__properties__,{set_index:"setIndex",get_index:"getIndex"})
});
org.intermedia.view.SwippableListViewStyle = $hxClasses["org.intermedia.view.SwippableListViewStyle"] = function() { }
org.intermedia.view.SwippableListViewStyle.__name__ = ["org","intermedia","view","SwippableListViewStyle"];
org.intermedia.view.SwippableListViewStyle.setSwippableListStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "fixed";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = Std.string(78) + "px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.paddingTop = "0px";
	node.style.width = "100%";
	node.style.height = Std.string(js.Lib.window.innerHeight - 78) + "px";
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
	org.intermedia.view.ThumbTextList1BisStyle.setListStyle(this.node);
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
	,createCell: function() {
		var cellStyle = { cell : org.intermedia.view.CellThumbText1BisStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbText1Style.setThumbnailMaskStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
		var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine,cellStyle);
		return cell;
	}
	,__class__: org.intermedia.view.ThumbTextList1Bis
});
org.intermedia.view.ThumbTextList1BisStyle = $hxClasses["org.intermedia.view.ThumbTextList1BisStyle"] = function() { }
org.intermedia.view.ThumbTextList1BisStyle.__name__ = ["org","intermedia","view","ThumbTextList1BisStyle"];
org.intermedia.view.ThumbTextList1BisStyle.setListStyle = function(node) {
	node.style.backgroundColor = "";
}
org.intermedia.view.ThumbTextList1BisStyle.prototype = {
	__class__: org.intermedia.view.ThumbTextList1BisStyle
}
org.intermedia.view.ViewManager = $hxClasses["org.intermedia.view.ViewManager"] = function(applicationModel,applicationController) {
	this._time = haxe.Timer.stamp();
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
	this._swippableListView = new org.intermedia.view.SwippableListView();
	this._currentView = this._swippableListView;
	this._body.appendChild(this._swippableListView.node);
	js.Lib.window.onresize = this.onResizeCallback.$bind(this);
	js.Lib.window.onscroll = this.onResizeCallback.$bind(this);
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
	,_time: null
	,init: function() {
		this._applicationModel.onModelStartsLoading = this.onStartLoading.$bind(this);
		this._applicationModel.onModelDataLoadError = this.onLoadingError.$bind(this);
		this._applicationModel.onModelCellDataLoaded = this.onCellDataLoaded.$bind(this);
		this._applicationModel.onModelDetailDataLoaded = this.onDetailDataLoaded.$bind(this);
		this._menu.onListItemSelected = this.onMenuItemSelectedCallback.$bind(this);
		this._swippableListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this._swippableListView.onDataRequest = ($_=this._applicationController,$_.loadCellData.$bind($_));
		this._swippableListView.onHorizontalMove = ($_=this._menu,$_.moveHorizontally.$bind($_));
		this._swippableListView.onHorizontalTweenEnd = ($_=this._menu,$_.horizontalTweenEnd.$bind($_));
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
		haxe.Log.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 249, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
		haxe.Firebug.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 250, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
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
		this._menu.onResizeCallback();
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
haxe.Resource.content = [{ name : "feed3", data : "s93414:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPkZyZW5jaFdlYi5mcjwvdGl0bGU%DQoJPGF0b206bGluayBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2ZlZWQvP3Bvc3RzX3Blcl9wYWdlPTEwIiByZWw9InNlbGYiIHR5cGU9ImFwcGxpY2F0aW9uL3Jzcyt4bWwiIC8%DQoJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mcjwvbGluaz4NCgk8ZGVzY3JpcHRpb24%TGUgbWFnYXppbmUgZGVzIHByb2Zlc3Npb25uZWxzIGRlIGwmIzAzOTtpbnRlcm5ldCAtIEJ1c2luZXNzLCBtYXJrZXRpbmcsIHRlY2gsIGRlc2lnbiwgbWFuYWdlbWVudDwvZGVzY3JpcHRpb24%DQoJPGxhc3RCdWlsZERhdGU%RnJpLCAzMCBNYXIgMjAxMiAxNTo1ODo1NiArMDAwMDwvbGFzdEJ1aWxkRGF0ZT4NCg0KCTxsYW5ndWFnZT5lbjwvbGFuZ3VhZ2U%DQoJPHN5OnVwZGF0ZVBlcmlvZD5ob3VybHk8L3N5OnVwZGF0ZVBlcmlvZD4NCgk8c3k6dXBkYXRlRnJlcXVlbmN5PjE8L3N5OnVwZGF0ZUZyZXF1ZW5jeT4NCgk8Z2VuZXJhdG9yPmh0dHA6Ly93b3JkcHJlc3Mub3JnLz92PTMuMy4xPC9nZW5lcmF0b3I%DQoJPGF0b206bGluayByZWw9J2h1YicgaHJlZj0naHR0cDovL2ZyZW5jaHdlYi5mci8:cHVzaHByZXNzPWh1YicvPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkxlcyBvZmZyZXMgZCYjODIxNztlbXBsb2kgZGUgbGEgc2VtYWluZSA6IFJlc3BvbnNhYmxlIFByb2R1aXQgV2ViIEIyQywgQXVkaWVuY2UgTWFuYWdlciYjODIzMDs8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW9mZnJlcy1kZW1wbG9pLWRlLWxhLXNlbWFpbmUtcmVzcG9uc2FibGUtcHJvZHVpdC13ZWItYjJjLWF1ZGllbmNlLW1hbmFnZXItNjExNDMvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtb2ZmcmVzLWRlbXBsb2ktZGUtbGEtc2VtYWluZS1yZXNwb25zYWJsZS1wcm9kdWl0LXdlYi1iMmMtYXVkaWVuY2UtbWFuYWdlci02MTE0My8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE1OjU4OjU2ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5yTWVuPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtNYXJrZXRpbmddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQXVkaWVuY2UgTWFuYWdlcl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtlbXBsb2ldXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtSZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkNdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTYxMTwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0NoYXF1ZSB2ZW5kcmVkaSwgbCYjODIxNztlbXBsb2kgZXN0IGF1IHJlbmRlei12b3VzIHN1ciBGcmVuY2h3ZWIgISBSZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkMsIENoZWYgZGUgcHJvamV0IHNlbmlvciB3ZWJtYXJrZXRpbmcgLyBTRU8sIFJlc3BvbnNhYmxlIENvbW1lcmNpYWwgTW9iaWxlJiM4MjMwOyBSZXRyb3V2ZXogbGVzIGRlcm5pw6hyZXMgb2ZmcmVzIGQmIzgyMTc7ZW1wbG9pIGR1IHNlY3RldXIgSW50ZXJuZXQuDQoNCg0KUmVzcG9uc2FibGUgUHJvZHVpdCBXZWIgQjJDIEAgTGFGb3VyY2hldHRlLmNvbQ0KQXVkaWVuY2UgTWFuYWdlciBAIENBVEFMSU5BDQpDaGVmIGRlIHByb2pldCBzZW5pb3Igd2VibWFya2V0aW5nIC8gU0VPIEAgRS1Nb25kZW9zDQpSZXNwb25zYWJsZSBDb21tZXJjaWFsIE1vYmlsZSAobWVkaWEgZXQgcGVyZm9ybWFuY2UgbWFya2V0aW5nKSBAIFBVUkUgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5DaGFxdWUgdmVuZHJlZGksIGwmIzgyMTc7ZW1wbG9pIGVzdCBhdSByZW5kZXotdm91cyBzdXIgRnJlbmNod2ViICEgUmVzcG9uc2FibGUgUHJvZHVpdCBXZWIgQjJDLCBDaGVmIGRlIHByb2pldCBzZW5pb3Igd2VibWFya2V0aW5nIC8gU0VPLCBSZXNwb25zYWJsZSBDb21tZXJjaWFsIE1vYmlsZSYjODIzMDsgUmV0cm91dmV6IGxlcyBkZXJuacOocmVzIG9mZnJlcyBkJiM4MjE3O2VtcGxvaSBkdSBzZWN0ZXVyIEludGVybmV0LjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciIgdGl0bGU9ImlTdG9ja18wMDAwMTM4MzYxODJTbWFsbDEiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMC9pU3RvY2tfMDAwMDEzODM2MTgyU21hbGwxLmpwZWciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMxNiIgLz48L3A%DQo8dWw%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL3Jlc3BvbnNhYmxlLXByb2R1aXQtd2ViLWIyYy1oZi8iIHRhcmdldD0iX2JsYW5rIj5SZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkMgQCBMYUZvdXJjaGV0dGUuY29tPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL2F1ZGllbmNlLW1hbmFnZXIvIiB0YXJnZXQ9Il9ibGFuayI%QXVkaWVuY2UgTWFuYWdlciBAIENBVEFMSU5BPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL2NoZWYtZGUtcHJvamV0LXNlbmlvci13ZWJtYXJrZXRpbmctc2VvLWhmLyIgdGFyZ2V0PSJfYmxhbmsiPkNoZWYgZGUgcHJvamV0IHNlbmlvciB3ZWJtYXJrZXRpbmcgLyBTRU8gQCBFLU1vbmRlb3M8L2E%PC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vZW1wbG9pLmZyZW5jaHdlYi5mci9vZmZyZS1lbXBsb2kvcmVzcG9uc2FibGUtY29tbWVyY2lhbC1tb2JpbGUtbWVkaWEtZXQtcGVyZm9ybWFuY2UtbWFya2V0aW5nLWhmLyIgdGFyZ2V0PSJfYmxhbmsiPlJlc3BvbnNhYmxlIENvbW1lcmNpYWwgTW9iaWxlIChtZWRpYSBldCBwZXJmb3JtYW5jZSBtYXJrZXRpbmcpIEAgUFVSRSBBR0VOQ1k8L2E%PC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vZW1wbG9pLmZyZW5jaHdlYi5mci9vZmZyZS1lbXBsb2kvcmVzcG9uc2FibGUtcGFydGVuYXJpYXRzLWRpcmVjdHMtZ3JvdXBlLWUtY29tbWVyY2UtaGYvIiB0YXJnZXQ9Il9ibGFuayI%UmVzcG9uc2FibGUgcGFydGVuYXJpYXRzIGRpcmVjdHMgLyBncm91cGUgZS1jb21tZXJjZSBAIE5ldCBOZXcgVGFsZW50PC9hPjwvbGk%DQo8L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW9mZnJlcy1kZW1wbG9pLWRlLWxhLXNlbWFpbmUtcmVzcG9uc2FibGUtcHJvZHVpdC13ZWItYjJjLWF1ZGllbmNlLW1hbmFnZXItNjExNDMvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCg0KCQk8aXRlbT4NCgkJPHRpdGxlPltHYWRnZXQgZGUgbGEgc2VtYWluZV0gRS1wYXBlciwgbCYjODIxNzvDqWNyYW4gZmxleGlibGUgZGUgTEc8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2dhZGdldC1kZS1sYS1zZW1haW5lLWUtcGFwZXItZWNyYW4tZmxleGlibGUtZGUtbGctNjExNDIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9nYWRnZXQtZGUtbGEtc2VtYWluZS1lLXBhcGVyLWVjcmFuLWZsZXhpYmxlLWRlLWxnLTYxMTQyLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTU6NDY6MzUgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1RlY2hdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZSBwYXBlcl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtFUERdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTEddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTczMzwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0xvbmd0ZW1wcyBmYW50YXNtw6lzIHBhciBkZSBub21icmV1eCBnZWVrcywgbGVzIMOpY3JhbnMgZmxleGlibGVzIGRldnJhaWVudCBiaWVudMO0dCDDqnRyZSBjb21tZXJjaWFsaXPDqXMuIEVuIGVmZmV0LCBMRyBhIHLDqWNlbW1lbnQgYW5ub25jw6kgcXVlIGxlcyBwcmVtaWVycyDDqWNyYW5zIGRlIGNlIGdlbnJlLCBkZXN0aW7DqXMgYXV4IGUtcmVhZGVycywgZGV2YWllbnQgZmFpcmUgbGV1ciBhcnJpdsOpZSBlbiBFdXJvcGUsIGQmIzgyMTc7aWNpIGxhIGZpbiBkdSBtb2lzIGQmIzgyMTc7YXZyaWwuDQoNCkJhcHRpc8OpIEVQRCBwb3VyIMKrZWxlY3Ryb25pYyBwYXBlciBkaXNwbGF5wrssIGNlIGdhZGdldCBncmFuZCBkZSBzaXggcG91Y2VzIG5lIGZlcmFpdCBxdWUgMCw3IG1tIGQmIzgyMTc7w6lwYWlzc2V1ci4gU2Vsb24gWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5Mb25ndGVtcHMgZmFudGFzbcOpcyBwYXIgZGUgbm9tYnJldXggZ2Vla3MsIGxlcyDDqWNyYW5zIGZsZXhpYmxlcyBkZXZyYWllbnQgYmllbnTDtHQgw6p0cmUgY29tbWVyY2lhbGlzw6lzLiBFbiBlZmZldCwgPGEgaHJlZj0iaHR0cDovL3d3dy5sZy5jb20vZnIvaW5kZXguanNwIiB0YXJnZXQ9Il9ibGFuayI%TEc8L2E%IGEgcsOpY2VtbWVudCBhbm5vbmPDqSBxdWUgbGVzIHByZW1pZXJzIMOpY3JhbnMgZGUgY2UgZ2VucmUsIGRlc3RpbsOpcyBhdXggZS1yZWFkZXJzLCBkZXZhaWVudCBmYWlyZSBsZXVyIGFycml2w6llIGVuIEV1cm9wZSwgZCYjODIxNztpY2kgbGEgZmluIGR1IG1vaXMgZCYjODIxNzthdnJpbC48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1tZWRpdW0gd3AtaW1hZ2UtNTU3MzciIHRpdGxlPSJFLXBhcGVyIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvRS1wYXBlci01NTB4MjM5LnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjM5IiAvPjwvcD4NCjxwPkJhcHRpc8OpIEVQRCBwb3VyIMKrZWxlY3Ryb25pYyBwYXBlciBkaXNwbGF5wrssIGNlIGdhZGdldCBncmFuZCBkZSBzaXggcG91Y2VzIG5lIGZlcmFpdCBxdWUgMCw3IG1tIGQmIzgyMTc7w6lwYWlzc2V1ci4gU2Vsb24gbGUgc3VkLWNvcsOpZW4sIGwmIzgyMTc7w6ljcmFuIG9mZnJlIHVuZSByw6lzb2x1dGlvbiBkZSAxMDI0JiMyMTU7NzY4IHBpeGVscy4gRVBEIHMmIzgyMTc7YXBwdWllIHN1ciBsYSB0ZWNobm9sb2dpZSBlLWluayBldCBuZSBwcm9wb3NlIGRvbmMgcXVlIGRpZmbDqXJlbnRzIHRvbnMgZGUgZ3Jpcy4gT3V0cmUgc2EgZmxleGliaWxpdMOpICg0MMKwKSwgY2Ugbm91dmVhdSBwcm9kdWl0IHNlcmFpdCDDqWdhbGVtZW50IHRyw6hzIHLDqXNpc3RhbnQgZXQgc3Vydml2cmFpdCBhaW5zaSDDoCB1bmUgY2h1dGUgZGUgcGx1cyBkJiM4MjE3O3VuIG3DqHRyZS48L3A%DQo8cD5BcHLDqHMgTEcsIGxlcyBjb25zdHJ1Y3RldXJzIFNhbXN1bmcgZXQgU2hhcnAgZGV2cmFpZW50IMOpZ2FsZW1lbnQgY29tbWVyY2lhbGlzZXIgdHLDqHMgcHJvY2hhaW5lbWVudCBsZXMgbcOqbWVzIHR5cGVzIGRlIHByb2R1aXRzLjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvcGFwZXItbGktbm91dmVsbGUtbGV2ZWUtMi0xLW0vIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5VbmUgbm91dmVsbGUgbGV2w6llIGRlIDIuMSBNJCBwb3VyIFBhcGVyLmxpICE8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9wYXBlci1saS1sYW5jZS12ZXJzaW9uLWZyYW5jYWlzZS0xNTIzOC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPlBhcGVyLmxpIGxhbmNlIHNhIHZlcnNpb24gZnJhbsOnYWlzZSAmIzgyMTE7IEVudHJldGllbjwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2dhZGdldC1kZS1sYS1zZW1haW5lLWxlLXNhbXN1bmctZ2FsYXh5LXNraW4tZXQtc29uLWVjcmFuLWZsZXhpYmxlLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0dhZGdldCBkZSBsYSBzZW1haW5lXSBMZSBTYW1zdW5nIEdhbGF4eSBTa2luIGV0IHNvbiDDqWNyYW4gZmxleGlibGU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbi1zdWlzc2Utb24tZmFpdC1kdS1ib24tY2hvY29sYXQtbWFpcy1hdXNzaS1kZXMtc3RhcnR1cHMvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5FbiBTdWlzc2UsIG9uIGZhaXQgZHUgYm9uIGNob2NvbGF0IG1haXMgYXVzc2kgZGVzIHN0YXJ0dXBzICE8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sYW5uZWUtMjAxMC12dWUtcGFyLWNlZHJpYy1naW9yZ2ktdGVjaGNydW5jaC1mcmFuY2UvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MJiM4MjE3O2FubsOpZSAyMDEwIHZ1ZSBwYXIgQ8OpZHJpYyBHaW9yZ2ksIFRlY2hDcnVuY2ggRnJhbmNlPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZ2FkZ2V0LWRlLWxhLXNlbWFpbmUtZS1wYXBlci1lY3Jhbi1mbGV4aWJsZS1kZS1sZy02MTE0Mi9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjExNDEvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtbW91dmVtZW50cy1kZS1sYS1zZW1haW5lLTEyLTYxMTQxLyNjb21tZW50czwvY29tbWVudHM%DQoNCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxNToxODoyNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0RpZ2l0YXNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbRHVrZSBSYXpvcmZpc2hdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGFnYXJkZXJlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01pbGt5XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW25vbWluYXRpb25dXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtTRlJdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3ludGhlc2lvXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3RyYW5zZsOocmVzXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1MTM8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtBdWpvdXJkJiM4MjE3O2h1aSBsZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lIHNvbnQgYXUgcmVuZGV6LXZvdXMgc3VyIEZyZW5jaFdlYiAhIFN5bnRoZXNpbywgU0ZSLCBEaWdpdGFzLCBZYWhvbyEgRHVrZSBSYXpvcmZpc2gsIFBlcmZlbyYjODIzMDsgUmV0cm91dmV6IGxlcyBkZXJuaWVycyB0cmFuc2ZlcnRzIG1hcnF1YW50cyBkdSBzZWN0ZXVyLg0KDQoNClN0w6lwaGFuZSBHdWVycnksIERpcmVjdGV1ciBnw6luw6lyYWwgZGUgRHVrZSBSYXpvcmZpc2gsIGFubm9uY2UgbOKAmWFycml2w6llIGRlIGRldXggbm91dmVhdXggRGlyZWN0ZXVycyBjb25zZWlsIDogVGhvbWFzIERlIExhdHRyZSBldCBBZHJpw6FuIFJ1aXogTWVkaWF2aWxsYS4NCk1pbGt5LCBs4oCZYWdlbmNlIGRlIHNvY2lhbCBjb21tZXJjZSBjcsOpw6llIHBhciBQaWVycmUgTWF0dWNoZXQgYW5ub25jZSBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkF1am91cmQmIzgyMTc7aHVpIGxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmUgc29udCBhdSByZW5kZXotdm91cyBzdXIgRnJlbmNoV2ViICEgU3ludGhlc2lvLCBTRlIsIERpZ2l0YXMsIFlhaG9vISBEdWtlIFJhem9yZmlzaCwgUGVyZmVvJiM4MjMwOyBSZXRyb3V2ZXogbGVzIGRlcm5pZXJzIHRyYW5zZmVydHMgbWFycXVhbnRzIGR1IHNlY3RldXIuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTcyNCIgdGl0bGU9ImxlcyBtb3V2ZW1lbnRzIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbGVzLW1vdXZlbWVudHMzLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMTE3IiAvPjwvcD4NCjx1bD4NCjxsaT48c3Ryb25nPlN0w6lwaGFuZSBHdWVycnk8L3N0cm9uZz4sIERpcmVjdGV1ciBnw6luw6lyYWwgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5kdWtlLXJhem9yZmlzaC5jb20vIiB0YXJnZXQ9Il9ibGFuayI%RHVrZSBSYXpvcmZpc2g8L2E%LCBhbm5vbmNlIGzigJlhcnJpdsOpZSBkZSBkZXV4IG5vdXZlYXV4IERpcmVjdGV1cnMgY29uc2VpbCA6IFRob21hcyBEZSBMYXR0cmUgZXQgQWRyacOhbiBSdWl6IE1lZGlhdmlsbGEuPC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vd3d3Lm1pbGt5LmZyLyIgdGFyZ2V0PSJfYmxhbmsiPk1pbGt5LDwvYT4gbOKAmWFnZW5jZSBkZSBzb2NpYWwgY29tbWVyY2UgY3LDqcOpZSBwYXIgUGllcnJlIE1hdHVjaGV0IGFubm9uY2UgdHJvaXMgbm91dmVsbGVzIHJlY3J1ZXMgOiA8c3Ryb25nPkVtaWxpZSBNYXNjbGV0PC9zdHJvbmc%IHJlam9pbnQgbOKAmcOpcXVpcGUgY29tbWUgRGlyZWN0cmljZSBkZXMgT3DDqXJhdGlvbnMsIDxzdHJvbmc%TWFyeWxlbmUgRHVyaWV1PC9zdHJvbmc%IHJlam9pbnQgbOKAmWFnZW5jZSBhdSBwb3N0ZSBkZSBTb2NpYWwgbWVkaWEgY29uc3VsdGFudCBldCA8c3Ryb25nPkplcmVtaWUgRHVwdWlzPC9zdHJvbmc%IGVuIHRhbnQgcXVlIFNlbmlvciBwcm9kdWN0IG1hbmFnZXIuPC9saT4NCjxsaT48c3Ryb25nPllhbm5pY2sgTGFjb21iZTwvc3Ryb25nPiBhIMOpdMOpIG5vbW3DqSBkaXJlY3RldXIgZ8OpbsOpcmFsIGFkam9pbnQgZW4gY2hhcmdlIGR1IG1hcmtldGluZyBldCBkZSBsYSBzdHJhdMOpZ2llIGNoZXogPGEgaHJlZj0iaHR0cDovL3d3dy5sYWdhcmRlcmUtcHViLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5MYWdhcmTDqHJlIHB1YmxpY2l0w6kuPC9hPjwvbGk%DQo8bGk%PHN0cm9uZz5KZWFuLVBoaWxpcHBlIE1hcnR6ZWw8L3N0cm9uZz4gYSDDqXTDqSBub21tw6kgRGlyZWN0ZXVyIEfDqW7DqXJhbCBBZGpvaW50IGVuIGNoYXJnZSBkdSA8c3BhbiBpZD0ibW9yZS01NTUxMyI%PC9zcGFuPlBsYW5uaW5nIFN0cmF0w6lnaXF1ZSBkZSA8YSBocmVmPSJodHRwOi8vd3d3LmRpZ2l0YXMuZnIvIiB0YXJnZXQ9Il9ibGFuayI%RGlnaXRhcyBGcmFuY2UuPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL3d3dy50dXJuLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5UdXJuPC9hPiwgcGxhdGVmb3JtZSBtb25kaWFsZSBkZSBkb25uw6llcyBwb3VyIGxhIHB1YmxpY2l0w6kgZXQgbGUgbWFya2V0aW5nIGRpZ2l0YWwsIGEgcsOpY2VtbWVudCByZW5mb3JjZXIgc29uIMOpcXVpcGUgY29tbWVyY2lhbGUgcGFuLWV1cm9ww6llbm5lIGF2ZWMgbGEgbm9taW5hdGlvbiBkZSA8c3Ryb25nPkplYW4tQ2xhdWRlIE11cmF0b3JlPC9zdHJvbmc%IGF1IHBvc3RlIGRlIGRpcmVjdGV1ciBjb21tZXJjaWFsIHBvdXIgbGEgRnJhbmNlLCBs4oCZSXRhbGllIGV0IGxhIHDDqW5pbnN1bGUgaWLDqXJpcXVlIGRlcHVpcyBsZSBub3V2ZWF1IGJ1cmVhdSBkZSBsYSBzb2Npw6l0w6ksIGJhc8OpIMOgIFBhcmlzLjwvbGk%DQo8bGk%U2Vsb24gZGVzIHNvdXJjZXMgcHJvY2hlcyBkdSBkb3NzaWVyLCA8YSBocmVmPSJodHRwOi8vd3d3LnNmci5mci8iIHRhcmdldD0iX2JsYW5rIj5TRlI8L2E%IGRldnJhaXQgYW5ub25jZXIgbGEgbm9taW5hdGlvbiA8c3Ryb25nPmTigJlPbGl2aWVyIFNpY2hlbDwvc3Ryb25nPiwgcHLDqXNzZW50aSBhdSBwb3N0ZSBkZSBQREcgZGUgU0ZSIHN1aXRlIGF1IGTDqXBhcnQgcHLDqWNpcGl0w6kgZGUgPHN0cm9uZz5GcmFuY2sgRXNzZXI8L3N0cm9uZz4sIHRlbXBvcmFpcmVtZW50IHJlbXBsYWPDqSBwYXIgPHN0cm9uZz5KZWFuLUJlcm5hcmQgTMOpdnk8L3N0cm9uZz4sIHNpbXVsdGFuw6ltZW50IFByw6lzaWRlbnQgZHUgRGlyZWN0b2lyZSBkZSBWaXZlbmRpLjwvbGk%DQo8bGk%PHN0cm9uZz5UaG9tYXMgTGUgR2FjPC9zdHJvbmc%LCBwcsOpY8OpZGVtbWVudCBkaXJlY3RldXIgZGUgbGEgcmVsYXRpb24gY2xpZW50IDIuMCBjaGV6IE9yYW5nZSwgcmVqb2ludCA8YSBocmVmPSJodHRwOi8vc3ludGhlc2lvLmNvbS9jb3Jwb3JhdGUvZnIvIiB0YXJnZXQ9Il9ibGFuayI%U3ludGhlc2lvPC9hPiwgc3DDqWNpYWxpc3RlIGRlIGwmIzgyMTc7ZS1yw6lwdXRhdGlvbiBldCBkdSBzb2NpYWwtQ1JNLCBlbiB0YW50IHF1ZSBkaXJlY3RldXIgZ8OpbsOpcmFsIEZyYW5jZS48L2xpPg0KPGxpPlNlbG9uIGxlcyBpbmZvcm1hdGlvbiBkdSBKb3VybmFsIGR1IG5ldCw8c3Ryb25nPiBBbnRvaW5lIENsw6ltZW50LCA8L3N0cm9uZz5EaXJlY3RldXIgZ8OpbsOpcmFsIFdlYiBkZSAyMCBNaW51dGVzLCBkb2l0IHF1aXR0ZXIgc2VzIGZvbmN0aW9ucyBhdWpvdXJkJiM4MjE3O2h1aSBwb3VyIHJlam9pbmRyZSA8YSBocmVmPSJodHRwOi8vd3d3Lm5leHRyYWRpb3R2LmNvbS8iIHRhcmdldD0iX2JsYW5rIj5OZXh0IEludGVyYWN0aXZlIE1lZGlhPC9hPiwgZmlsaWFsZSBudW3DqXJpcXVlIGR1IGdyb3VwZSBOZXh0IFJhZGlvIFRWLjwvbGk%DQo8bGk%PHN0cm9uZz5NYXRoaWV1IFF1aWxsw6hyZTwvc3Ryb25nPiBhIHLDqWNlbW1lbnQgcmVqb2ludCBsJiM4MjE3O2FnZW5jZSBkZSBjb21tdW5pY2F0aW9uIGRpZ2l0YWxlIG1hcnNlaWxsYWlzZSA8YSBocmVmPSJodHRwOi8vd3d3LnBlcmZlby5jb20vIiB0YXJnZXQ9Il9ibGFuayI%UGVyZmVvIDwvYT5hdSBwb3N0ZSBkZSBjaGFyZ8OpIGRlIGNvbXB0ZXMuPC9saT4NCjxsaT48c3Ryb25nPkRhdmlkIFNvdXJlbmlhbjwvc3Ryb25nPiwgZXgtRGlyZWN0ZXVyIGTigJlFdHVkZXMgYXUgc2VpbiBkdSBkw6lwYXJ0ZW1lbnQgTWVkaWEsIFRlY2hub2xvZ2llICZhbXA7IEVudGVydGFpbm1lbnQgZGUgSGFycmlzIEludGVyYWN0aXZlLCBhIMOpdMOpIG5vbW3DqSBEaXJlY3RldXIgZGVzIEV0dWRlcyBjaGV6IDxhIGhyZWY9Imh0dHA6Ly9mci55YWhvby5jb20vIiB0YXJnZXQ9Il9ibGFuayI%WWFob28hIEZyYW5jZTwvYT48L2xpPg0KPC91bD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW1vdXZlbWVudHMtZGUtbGEtc2VtYWluZS0xMi02MTA3NC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtbW91dmVtZW50cy1kZS1sYS1zZW1haW5lLTEyLTYwNzk1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TGVzIG1vdXZlbWVudHMgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjAxMDkvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW1vdXZlbWVudHMtZGUtbGEtc2VtYWluZS05LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TGVzIG1vdXZlbWVudHMgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjA4NzUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjExNDEvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KDQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2VuLWRpcmVjdC1kZXMtYWdlbmNlcy1sZXMtbmV3cy1kZS1sYS1zZW1haW5lLTYtNjExNDAvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS02LTYxMTQwLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTQ6MzU6MDQgKzAwMDA8L3B1YkRhdGU%DQoNCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtNYXJrZXRpbmddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU29jaWFsIE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2J1enptYW5dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQ3JpZXVyIDIuMF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtMQ1BdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGVnXV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTWV0aG9kZSBCZXJuYXJkXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU2ODI8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtCdWRnZXRzLCBjYW1wYWduZXMgd2ViLCBjaGlmZnJlcywgaGlnaC10ZWNoLCBub3V2ZWF1eCBtw6lkaWFzJiM4MjMwOyBSZXRvdXIgc3VyIGzigJlhY3R1YWxpdMOpIGRlIGxhIGNvbW11bmljYXRpb24sIGR1IG1hcmtldGluZyBldCBkZSBsYSBwdWJsaWNpdMOpIGRlIGNldHRlIHNlbWFpbmUuDQpXZWINClNpbW9uIDogbGUgcHJlbWllciBjcmlldXIgcHVibGljIDIuMC4gRW4gc291dmVuaXIgZHUgdGVtcHMgb8O5IGxlcyBjcmlldXJzIHNvbm5haWVudCBsZXVyIGNsb2NoZXR0ZSBwdWlzIHNjYW5kYWllbnQgbGVzIG1vdHMgZGVzIGhhYml0YW50cyBkZXMgYWxlbnRvdXJzLCBNZXJjaSBBbGZyZWQsIGxhIG5ld3NsZXR0ZXIgZMOpZGnDqWUgYXV4IGhvbW1lcyBkdSBncm91cGUgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5CdWRnZXRzLCBjYW1wYWduZXMgd2ViLCBjaGlmZnJlcywgaGlnaC10ZWNoLCBub3V2ZWF1eCBtw6lkaWFzJiM4MjMwOyBSZXRvdXIgc3VyIGzigJlhY3R1YWxpdMOpIGRlIGxhIGNvbW11bmljYXRpb24sIGR1IG1hcmtldGluZyBldCBkZSBsYSBwdWJsaWNpdMOpIGRlIGNldHRlIHNlbWFpbmUuPC9wPg0KPGgyPldlYjwvaDI%DQo8cD48c3Ryb25nPlNpbW9uIDogbGUgcHJlbWllciBjcmlldXIgcHVibGljIDIuMDwvc3Ryb25nPi4gRW4gc291dmVuaXIgZHUgdGVtcHMgb8O5IGxlcyBjcmlldXJzIHNvbm5haWVudCBsZXVyIGNsb2NoZXR0ZSBwdWlzIHNjYW5kYWllbnQgbGVzIG1vdHMgZGVzIGhhYml0YW50cyBkZXMgYWxlbnRvdXJzLCA8YSBocmVmPSJodHRwOi8vbWVyY2lhbGZyZWQuY29tLyIgdGFyZ2V0PSJfYmxhbmsiPk1lcmNpIEFsZnJlZDwvYT4sIGxhIG5ld3NsZXR0ZXIgZMOpZGnDqWUgYXV4IGhvbW1lcyBkdSBncm91cGUgTXkgTGl0dGxlIFBhcmlzLCBvZmZyZSDDoCBzZXMgYWJvbm7DqXMgdW5lIG9ww6lyYXRpb24gw6Agc29uIGltYWdlLCBkw6ljYWzDqWUgZXQgcGxlaW5lIGTigJlodW1vdXIuIEFpbnNpLCBhdWpvdXJkJiM4MjE3O2h1aSDDoCBwYXJ0aXIgZGUgMTdoLCBzdXIgbGEgcGxhY2UgZGUgbOKAmU9ww6lyYSDDoCBQYXJpcywgU2ltb24gZMOpY2xhbWVyYSBsZXMgZMOpY2xhcmF0aW9ucyBk4oCZYW1vdXIgZGVzIHRpbWlkZXMsIGxlcyBjb3VwcyBkZSBndWV1bGUgZGVzIG3DqWNvbnRlbnRzIG91IGVuY29yZSBkZXMgY291cHMgZGUgcHViIGRlcyBjb21tZXLDp2FudHMsIHR3ZWV0w6lzIHN1ciBsZSBoYXNodGFnICNjcmlldXJwdWJsaWMuIElscyBzZXJvbnQgZW5zdWl0ZSBkaWZmdXPDqXMgc3VyIFlvdVR1YmUgcG91ciBsYSBwb3N0w6lyaXTDqS48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL21lcmNpYWxmcmVkLmNvbS9zaW1vbi1jcmlldXItZGUtdHdlZXRzLmh0bWwiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtbWVkaXVtIHdwLWltYWdlLTU1NzA0IiB0aXRsZT0iQ3JpZXVyLXB1YmxpYyAyLjAiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9DcmlldXItcHVibGljLTIuMC01NTB4MjQ0LnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjQ0IiAvPjwvYT48L3A%DQo8cD5PcmNoZXN0csOpZSBwYXIgbGEgZmFtZXVzZSBhZ2VuY2UgPGEgaHJlZj0iaHR0cDovL3d3dy5idXp6bWFuLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPkJ1enpNYW48L2E%LCBBeGEgYSBsYW5jw6kgY2V0dGUgc2VtYWluZSB1bmUgbm91dmVsbGUgY2FtcGFnbmUgYmFwdGlzw6llIDxzdHJvbmc%PGEgaHJlZj0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9heGFmcmFuY2VjaGFpbmUiIHRhcmdldD0iX2JsYW5rIj5MYSBNw6l0aG9kZSBCZXJuYXJkPC9hPjwvc3Ryb25nPi4gQ29tcG9zw6kgZGUgdHJvaXMgZmlsbXMgdmlyYXV4IGV0IGQmIzgyMTc7dW5lIDxzcGFuIGlkPSJtb3JlLTU1NjgyIj48L3NwYW4%YWN0aXZhdGlvbiBkaWdpdGFsZSwgbGUgZGlzcG9zaXRpZiBhIHBvdXIgb2JqZWN0aWYgZCYjODIxNzthcHB1eWVyIGxlIGxhbmNlbWVudCBkdSBub3V2ZWF1IHNlcnZpY2UgZCYjODIxNztBeGEgY29udHJlIGxlcyBkYW5nZXJzIGQmIzgyMTc7SW50ZXJuZXQuIEJhcHRpc8OpZSBQcm90ZWN0aW9uIGZhbWlsaWFsZSBpbnTDqWdyYWxlLCBjZXR0ZSBvZmZyZSBwcm90w6hnZSBsZXMgY2xpZW50cyBkZXMgYWNjaWRlbnRzIG1haXMgc3VydG91dCBkZXMgcmlzcXVlcyBkZSBs4oCZdXN1cnBhdGlvbiBkZSB2b3RyZSBpZGVudGl0w6ksIGV0IGRlcyBhdHRlaW50ZXMgw6AgbOKAmWUtcsOpcHV0YXRpb27igKYuIEzigJlhZ2VuY2UgYSBub3RhbW1lbnQgbWlzIGVuIHBsYWNlIDxhIGhyZWY9Imh0dHA6Ly93d3cueW91dHViZS5jb20vYXhhZnJhbmNlY2hhaW5lIiB0YXJnZXQ9Il9ibGFuayI%dW4gc2l0ZSBpbnRlcm5ldDwvYT4gcXVpIHBlcm1ldCBhdXggaW50ZXJuYXV0ZXMgZGUgcGnDqWdlciBsZXVycyBhbWlzIGVuIGTDqXRvdXJuYW50IGxldXIgcHJvZmlsIChhdmVjIHBob3Rvcywgbm9tc%KApikgcG91ciBsZXMgaW5jcnVzdGVyIHN1ciBkZXMgc2l0ZXMgcGV1IGZsYXR0ZXVycy48L3A%DQo8cD48Y2VudGVyPjxpZnJhbWUgc3JjPSJodHRwOi8vd3d3LnlvdXR1YmUuY29tL2VtYmVkL2dpYW9HSjJXd2RnIiBmcmFtZWJvcmRlcj0iMCIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIzMDkiPjwvaWZyYW1lPjwvY2VudGVyPjwvcD4NCjxwPjwvYnI%TGEgY2hhw65uZSBwYXJsZW1lbnRhaXJlIGEgcsOpY2VtbWVudCBtaXMgZW4gcGxhY2UgdW4gZGlzcG9zaXRpZiBvcmlnaW5hbCBxdWkgcGVybWV0IDxzdHJvbmc%ZGUgZMOpdG91cm5lciBsZXMgYWZmaWNoZXMgZGUgY2FtcGFnbmUuPC9zdHJvbmc%IExhIGNoYcOubmUgYSBhaW5zaSBmYWl0IGFwcGVsIMOgIGwmIzgyMTc7YWdlbmNlIGRlIGNvbW11bmljYXRpb24gQ29udmVyc2lvbm5lbCBwb3VyIGTDqXZlbG9wcGVyIGwmIzgyMTc7YXBwbGljYXRpb24gTUNQIDogcG91ciA8YSBocmVmPSJodHRwOi8vbWNwLmxjcC5mci8iIHRhcmdldD0iX2JsYW5rIj5tYSBjYW1wYWduZSBwcsOpc2lkZW50aWVsbGU8L2E%LiBMJiM4MjE3O2FwcGxpY2F0aW9uIHBlcm1ldCBhaW5zaSBhdXggaW50ZXJuYXV0ZXMgZGUgcsOpYWxpc2VyIGxldXIgcHJvcHJlIGFmZmljaGUgw6lsZWN0b3JhbGUsIGF2ZWMgbGV1ciBwcm9wcmUgc2xvZ2FuIGRlIGNhbXBhZ25lLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vbWNwLmxjcC5mci8jMTk0Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU3MDAiIHRpdGxlPSJNQ1AiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NQ1AucG5nIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIyNDIiIC8%PC9hPjwvcD4NCjxwPkwmIzgyMTc7YWdlbmNlIFBhc3NhZ2UgUGnDqXRvbiBhIHLDqWNlbW1lbnQgbGFuY8OpIGxhIG5vdXZlbGxlIDxhIGhyZWY9Imh0dHA6Ly93d3cuZmFjZWJvb2suY29tL21ycHJvcHJlIiB0YXJnZXQ9Il9ibGFuayI%cGFnZSBGYWNlYm9vayBkZSBNciBQcm9wcmUgPC9hPnF1aSBhY2N1ZWlsbGVyYSBsZSA5IGF2cmlsIHByb2NoYWluIHVuZSBhcHBsaWNhdGlvbiBiYXB0aXPDqWUgPHN0cm9uZz4mbGFxdW87Jm5ic3A7bcOpbmFnZSBkaWdpdGFsJm5ic3A7JnJhcXVvOy48L3N0cm9uZz4gTCYjODIxNztpZMOpZSA6IGFpZGVyIGxlcyBpbnRlcm5hdXRlcyDDoCBmYWlyZSBsZSB0cmkgZGUgbGV1cnMgYW5jaWVubmVzIHBob3RvcyBldCBwb3N0cyBldCBiaWVuIGNvbXByZW5kcmUgdG91cyBsZXMgbm91dmVhdXggcGFyYW3DqXRyYWdlcyBkZSBsYSBUaW1lbGluZS48L3A%DQo8cD5PcmNoZXN0csOpZSBwYXIgVEJXQVxQQVJJUywgbGEgY2FtcGFnbmUgPHN0cm9uZz4mbGFxdW87Jm5ic3A7Q29udHJlIGxlIGNvbW1lcmNlIGlycmVzcG9uc2FibGUgZGVzIGFybWVzJm5ic3A7JnJhcXVvOzwvc3Ryb25nPiBkJiM4MjE3O0FtbmVzdHkgSW50ZXJuYXRpb25hbCBGcmFuY2UgcHJvcG9zZXJhIHBlbmRhbnQgMTAwIGpvdXJzLCB1bmUgY3LDqWF0aW9uIG9yaWdpbmFsZSBzdXIgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vQW1uZXN0eUFybWVzIiB0YXJnZXQ9Il9ibGFuayI%bGEgcGFnZSBGYWNlYm9vayBkw6lkacOpZTwvYT4uIENlcyAxNCBjcsOpYXRpb25zIG9udCBwb3VyIG9iamVjdGlmIGRlIHBlcm1ldHRyZSBkZSBwcmVuZHJlIGNvbnNjaWVuY2UgZGVzIGF0cm9jaXTDqXMgZW5nZW5kcsOpZXMgcGFyIGxlcyBhcm1lcy48L3A%DQo8cD5Qb3VyIGPDqWzDqWJyZXIgbGUgbGFuY2VtZW50IGR1IGZpbG0gVGl0YW5pYyBlbiAzRCAoc29ydGllIHByw6l2dWUgbGUgNCBhdnJpbCksIExhIDIwdGggQ2VudHVyeSBGb3ggYSBtaXMgZW4gcGxhY2UgbGEgcHJlbWnDqHJlIGFkdmVydGlzZXIgcGFnZSBzcG9uc29yaXPDqWUgZGFucyBTcG90aWZ5LCBxdWkgcGVybWV0IGRlIGNyw6llciBkZXMgYmFuZGVzLWFubm9uY2VzIHBlcnNvbm5hbGlzw6llcy4gTGVzIGludGVybmF1dGVzIHBvdXJyb250IGFpbnNpIGNyw6llciBldCA8c3Ryb25nPmRldmVuaXIgbGEgc3RhciBkZSBsZXVyIHByb3ByZSBiYW5kZS1hbm5vbmNlLjwvc3Ryb25nPjwvcD4NCjxociAvPg0KPGgyPkJ1c2luZXNzPC9oMj4NCjxwPjxhIGhyZWY9Imh0dHBzOi8vd3d3LmZhY2Vib29rLmNvbS9hZ2VuY2UubGVnIiB0YXJnZXQ9Il9ibGFuayI%TCYjODIxNzthZ2VuY2UgTGVnPC9hPiBhIGFubm9uY8OpIHF1ZSBwb3VyIHNlcyAxMCBhbnMgZWxsZSBzJiM4MjE3O29mZnJhaXQgbCYjODIxNzt1biBkZXMgcGx1cyBiZWF1eCBjYWRlYXV4IGQmIzgyMTc7YW5uaXZlcnNhaXJlJiM4MjMwOyA8c3Ryb25nPm5lIHBsdXMgcGFydGljaXBlciBhdXggY29tcMOpdGl0aW9ucy48L3N0cm9uZz48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cHM6Ly93d3cuZmFjZWJvb2suY29tL3Bob3RvLnBocD9mYmlkPTM5MDE4MDY3NDMzOTQ5NiZhbXA7c2V0PWEuMjkxMDU0MTI3NTg1NDg1Ljc4NzM0LjI5MTAzNzQ1MDkyMDQ4NiZhbXA7dHlwZT0xJmFtcDt0aGVhdGVyIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLW1lZGl1bSB3cC1pbWFnZS01NTcwOSIgdGl0bGU9ImxlZy1pbWFnZSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL2xlZy1pbWFnZS01NTB4MTExLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMTExIiAvPjwvYT48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogbGVmdDsiPlByaWNlTWluaXN0ZXIgZXQgU29Db2xpc3NpbW8gIG9udCByZW1wb3J0ZXIgPHN0cm9uZz5sZSBHcmFuZCBQcml4IE9yIGR1IEJyYW5kIENvbnRlbnQ8L3N0cm9uZz4sIGNhdMOpZ29yaWUgQ29tbWVyY2UgZXQgRGlzdHJpYnV0aW9uLCBhdmVjIGwmIzgyMTc7b3DDqXJhdGlvbiDCqyBQZXRpdHMgQ2FkZWF1eCBlbnRyZSBBbWlzIMK7PC9wPg0KPHA%U2Vsb24gbGVzIGluZm9ybWF0aW9ucyBkZSBTdHJhdMOpZ2llcywgbGEgbWFycXVlIGRlIGp1cyBkZSBmcnVpdHMgPGEgaHJlZj0iaHR0cDovL3d3dy50cm9waWNhbmEuZnIvIiB0YXJnZXQ9Il9ibGFuayI%VHJvcGljYW5hPC9hPiBhIGTDqWNpZMOpICYjODIxMTsgc2FucyBjb21ww6l0aXRpb24gJiM4MjExOyBkZSBjb25maWVyIMOgIDxhIGhyZWY9Imh0dHA6Ly93d3cuZGRiLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPnNvbiBhZ2VuY2UgcHVibGljaXRhaXJlIEREQiA8L2E%UGFyaXMgbCYjODIxNztlbnNlbWJsZSBkZSBzYSBzdHJhdMOpZ2llIGRpZ2l0YWxlLCBxdWkgw6l0YWl0IGfDqXLDqWUgcGFyIE51cnVuIEZyYW5jZSBkZXB1aXMgMjAxMC48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy50cm9waWNhbmEuZnIvIy9jYXJyb3VzZWxwcm9kdWl0Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU3MDciIHRpdGxlPSJ0cm9waWNhbmEiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy90cm9waWNhbmEucG5nIiBhbHQ9IiIgd2lkdGg9IjUwNCIgaGVpZ2h0PSIxODAiIC8%PC9hPjwvcD4NCjxwPlRvdWpvdXJzIHNlbG9uIGxlcyBpbmZvcm1hdGlvbnMgZGUgU3RyYXTDqWdpZXMsIGxlIGxhYm9yYXRvaXJlIHBoYXJtYWNldXRpcXVlIE5vdm8gTm9yZGlzayBGcmFuY2UgYSByZXRlbnUgbCYjODIxNzthZ2VuY2UgPGEgaHJlZj0iaHR0cDovL3d3dy5uZXdiYmRvLmZyLyNob21lIiB0YXJnZXQ9Il9ibGFuayI%TmV3IEJCRE88L2E%IHBvdXIgZ8OpcmVyIHNvbiBidWRnZXQgZGUgY29tbXVuaWNhdGlvbiBkaWdpdGFsZS48L3A%DQo8cD48YSBocmVmPSJodHRwOi8vd3d3LnBpY3RpbWUuY29tLzAxMC1BQ0NVRUlMLzAxMC1ob21lLnBocCIgdGFyZ2V0PSJfYmxhbmsiPlBpY3RpbWUsPC9hPiBzcMOpY2lhbGlzdGUgZW4gY29uc2VpbCBldCBzb2x1dGlvbnMgZS1jb21tZXJjZSwgYW5ub25jZSBsZSBnYWluIGRlIGRldXggbm91dmVhdXggYnVkZ2V0czogTm9jaWLDqSwgcXVpIGx1aSBhIGNvbmZpw6kgbGEgcsOpYWxpc2F0aW9uIGRlIHNvbiBzaXRlIG1vYmlsZSwgbS5ub2NpYmUuZnIsIGV0IEJyaWNvbWFuLCBxdWkgbHVpIGEgY29uZmnDqSBsYSByZWZvbnRlIGRlIHNvbiBzaXRlIGQmIzgyMTc7ZS1jb21tZXJjZS48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy5waWN0aW1lLmNvbS8wMTAtQUNDVUVJTC8wMTAtaG9tZS5waHAiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTcwNiIgdGl0bGU9InBpY3RpbWUiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9waWN0aW1lLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMTA4IiAvPjwvYT48L3A%DQo8cD5HcmFuZE9wdGljYWwgYSBjaG9pc2kgbCYjODIxNzthZ2VuY2UgPGEgaHJlZj0iaHR0cDovL3d3dy52YW5rc2VuLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPlZhbmtzZW48L2E%LCBxdWkgc2VyYSBkw6lzb3JtYWlzIGVuIGNoYXJnZSBkdSBzaXRlIDxhIGhyZWY9Imh0dHA6Ly93d3cuZ3JhbmRvcHRpY2FsLmNvbS8iPmdyYW5kb3B0aWNhbC5jb208L2E%LCBkb250IHVuZSByZWZvbnRlIGVzdCBwcsOpdnVlIGVuIGF2cmlsIHByb2NoYWluLiBMJiM4MjE3O2FnZW5jZSBhdXJhIMOpZ2FsZW1lbnQgcG91ciBtaXNzaW9uIGQmIzgyMTc7YW5pbWVyIGxlIHNpdGUgdG91dCBhdSBsb25nIGRlIGwmIzgyMTc7YW5uw6llLCBlbiByZWxheWFudCBsZXMgY2FtcGFnbmVzIGRlIGxhIG1hcnF1ZSBldCBlbiBkaWZmdXNhbnQgZGUgbm9tYnJldXggYXJ0aWNsZXMgYXV0b3VyIGRlIGwmIzgyMTc7b3B0aXF1ZS4gQ2VzIGluZm9ybWF0aW9ucyBzZXJvbnQgcmVsYXnDqWVzIHN1ciBsZXMgcHJpbmNpcGF1eCBtZWRpYSBzb2NpYXV4IGV0IGF1dHJlcyBwbGF0ZWZvcm1lcyBjb2xsYWJvcmF0aXZlcy48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VuLWRpcmVjdC1kZXMtYWdlbmNlcy1sZXMtbmV3cy1kZS1sYS1zZW1haW5lLTYtNjA4NzQvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRW4gZGlyZWN0IGRlcyBhZ2VuY2VzXSBMZXMgbmV3cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZW4tZGlyZWN0LWRlcy1hZ2VuY2VzLWxlcy1uZXdzLWRlLWxhLXNlbWFpbmUtNi02MDkzMi8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS01LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VuIGRpcmVjdCBkZXMgYWdlbmNlc10gTGVzIG5ld3MgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VuLWRpcmVjdC1kZXMtYWdlbmNlcy1sZXMtbmV3cy1kZS1sYS1zZW1haW5lcy8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdICBMZXMgbmV3cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZW4tZGlyZWN0LWRlcy1hZ2VuY2VzLWxlcy1uZXdzLWRlLWxhLXNlbWFpbmUtNy02MDcwOS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZW4tZGlyZWN0LWRlcy1hZ2VuY2VzLWxlcy1uZXdzLWRlLWxhLXNlbWFpbmUtNi02MTE0MC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KDQoJCTxpdGVtPg0KCQk8dGl0bGU%W0V0dWRlXSBNw6lkaWFtw6l0cmllIGRlc3NpbmUgbGUgcG9ydHJhaXQgcm9ib3QgZHUgdGFibG9uYXV0ZTwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXR1ZGUtbWVkaWFtZXRyaWUtZGVzc2luZS1sZS1wb3J0cmFpdC1yb2JvdC1kdS10YWJsb25hdXRlLTYxMTM5LzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXR1ZGUtbWVkaWFtZXRyaWUtZGVzc2luZS1sZS1wb3J0cmFpdC1yb2JvdC1kdS10YWJsb25hdXRlLTYxMTM5LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTM6MTg6MjQgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0ludGVybmV0XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01vYmlsZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtjaGlmZnJlc11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVvDqXR1ZGVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbaVBhZF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtwb3J0cmFpdF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0YWJsZXR0ZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt1c2FnZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NjY0PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbRGFucyBsZSBjYWRyZSBk4oCZdW5lIG1hdGluw6llIGRlIHLDqWZsZXhpb24gb3JnYW5pc8OpZSBwYXIgbGUgR2VzdGUgKEdyb3VwZW1lbnQgZGVzIEVkaXRldXJzIGRlIGNvbnRlbnVzIGV0IGRlIHNlcnZpY2VzIGVuIGxpZ25lKSwgTcOpZGlhbcOpdHJpZSBzJiM4MjE3O2VzdCBwZW5jaMOpIHBvdXIgbGEgcHJlbWnDqHJlIGZvaXMgc3VyIGxlcyB1c2FnZXMgZXQgbGUgcHJvZmlsIGRlcyB0YWJsb25hdXRlcy4gQ29tbWUgc29uIG5vbSBsJiM4MjE3O2luZGlxdWUsIGNlIG7DqW9sb2dpc21lIGTDqXNpZ25lIGxlcyB1dGlsaXNhdGV1cnMgZGUgdGFibGV0dGVzLCBhdSBub21icmUgZCYjODIxNzsxLDcgbWlsbGlvbiBlbiBGcmFuY2UsIGVuIGhhdXNzZSBkZSAyMyUgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL21hdGluZWUtcHJvc3BlY3RpdmUtZHUtZ2VzdGUtcXVlbC1mdXR1ci1wb3VyLWxlcy1tZWRpYXMtZW4tbGlnbmUtNjExMzQvIiB0YXJnZXQ9Il9ibGFuayI%RGFucyBsZSBjYWRyZSBk4oCZdW5lIG1hdGluw6llIGRlIHLDqWZsZXhpb248L2E%IG9yZ2FuaXPDqWUgcGFyIGxlIEdlc3RlIChHcm91cGVtZW50IGRlcyBFZGl0ZXVycyBkZSBjb250ZW51cyBldCBkZSBzZXJ2aWNlcyBlbiBsaWduZSksIDxhIGhyZWY9Imh0dHA6Ly93d3cubWVkaWFtZXRyaWUuZnIvIiB0YXJnZXQ9Il9ibGFuayI%TcOpZGlhbcOpdHJpZTwvYT4gcyYjODIxNztlc3QgcGVuY2jDqSBwb3VyIGxhIHByZW1pw6hyZSBmb2lzIHN1ciBsZXMgdXNhZ2VzIGV0IGxlIHByb2ZpbCBkZXMgdGFibG9uYXV0ZXMuIENvbW1lIHNvbiBub20gbCYjODIxNztpbmRpcXVlLCBjZSBuw6lvbG9naXNtZSBkw6lzaWduZSBsZXMgdXRpbGlzYXRldXJzIGRlIHRhYmxldHRlcywgYXUgbm9tYnJlIGQmIzgyMTc7MSw3IG1pbGxpb24gZW4gRnJhbmNlLCBlbiBoYXVzc2UgZGUgMjMlIGVuIHVuIGFuLiA8YSBocmVmPSJodHRwOi8vd3d3Lm1lZGlhbWV0cmllLmZyL3dlYm1haWwvZG93bmxvYWQvTWVkaWFtZXRyaWVfUGFuZWxUYWJsZXR0ZXNfQ29uZmVyZW5jZUdFU1RFMjkwMzEyLnBkZiIgdGFyZ2V0PSJfYmxhbmsiPkwmIzgyMTc7w6l0dWRlIDwvYT5tZW7DqWUgcGFyIGwmIzgyMTc7aW5zdGl0dXQgcmVwb3NlIHN1ciB1bmUgZW5xdcOqdGUgZWZmZWN0dcOpZSBhdXByw6hzIGQmIzgyMTc7dW4gcGFuZWwgZGUgcHLDqHMgZGUgMTAwMCB1dGlsaXNhdGV1cnMgcHJpbmNpcGF1eCBkJiM4MjE3O2lQYWQuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHA6Ly93d3cubWVkaWFtZXRyaWUuZnIvd2VibWFpbC9kb3dubG9hZC9NZWRpYW1ldHJpZV9QYW5lbFRhYmxldHRlc19Db25mZXJlbmNlR0VTVEUyOTAzMTIucGRmIj48aW1nIGNsYXNzPSJzaXplLWZ1bGwgd3AtaW1hZ2UtNTU2NzEgYWxpZ25jZW50ZXIiIHRpdGxlPSJtZWRpYW1ldHJpZSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL21lZGlhbWV0cmllMi5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjIzNCIgLz48L2E%PC9wPg0KPHA%U2Vsb24gbGVzIHByZW1pZXJzIHLDqXN1bHRhdHMgZGUgbCYjODIxNzvDqXR1ZGUsIGxlIHRhYmxvbmF1dGUgZXN0IGRvbmMgOiB1biBob21tZSAoNjglKSB1cmJhaW4gKDU5JSkgYXBwYXJ0ZW5hbnQgYXV4IENTUCsgKDUzJSkgZXQgPHNwYW4gaWQ9Im1vcmUtNTU2NjQiPjwvc3Bhbj5heWFudCBlbnRyZSAzNSBldCA0OSBhbnMgKDMzJSkuPC9wPg0KPHA%Rm9ydCBkZSBjZXMgZG9ubsOpZXMsIGwmIzgyMTc7w6l0dWRlIGEgZW5zdWl0ZSBwb2ludMOpIGR1IGRvaWd0IGxlcyBwcmluY2lwYWxlcyBkaWZmw6lyZW5jZXMgcXVpIGRpc3Rpbmd1ZW50IGxlIHByb2ZpbCBkJiM4MjE3O3VuIG1vYmluYXV0ZSBldCBjZWx1aSBkJiM4MjE3O3VuIHRhYmxvbmF1dGUuIEwmIzgyMTc7ZW5xdcOqdGUgc291bGlnbmUgYWluc2kgdW5lIGxhcmdlIHN1cnJlcHLDqXNlbnRhdGlvbiBkZXMgaG9tbWVzIHBhcm1pIGxlcyB0YWJsb25hdXRlcyAoNzAlIGNvbnRyZSA1NyUgZGUgbW9iaW5hdXRlcykuIExlcyB1dGlsaXNhdGV1cnMgZGUgdGFibGV0dGUgc29udCDDqWdhbGVtZW50IHBsdXMgw6Jnw6lzIDogMzAlIGQmIzgyMTc7ZW50cmUgZXV4IG9udCBlbnRyZSAzNSBldCA0OSBhbnMsIGNvbnRyZSAyNCUgZGVzIG1vYmluYXV0ZXMuIExlcyB0YWJsb25hdXRlcyBhcHBhcnRpZW5uZW50IMOpZ2FsZW1lbnQgZCYjODIxNzthdmFudGFnZSBhdXggQ1NQKyAgKDQ3JSBjb250cmUgMzQlIHBvdXIgbGVzIG1vYmluYXV0ZXMpLiBFbmZpbiwgbGEgY29uY2VudHJhdGlvbiBkZXMgdGFibG9uYXV0ZXMgKDMwJSkgZW4gcsOpZ2lvbiBwYXJpc2llbm5lIHNlIHLDqXbDqGxlIGJlYXVjb3VwIHBsdXMgbWFycXXDqWUgcXVlIHBvdXIgbGVzIHV0aWxpc2F0ZXVycyBkZSBzbWFydHBob25lcyAoMjUlKS48L3A%DQo8cD5QYXJtaSBsZXMgYXV0cmVzIGVuc2VpZ25lbWVudHMgw6AgcmV0ZW5pciwgbCYjODIxNztlbnF1w6p0ZSBtb250cmUgw6AgcXVlbCBwb2ludCAmbGFxdW87Jm5ic3A7bGEgY29uc29tbWF0aW9uJm5ic3A7JnJhcXVvOyBkZXMgdGFibGV0dGUgZXN0IHPDqWRlbnRhaXJlLiBFbiBlZmZldCwgbCYjODIxNzt1dGlsaXNhdGlvbiBkZSBsJiM4MjE3O2lQYWQgc2UgZmFpdCBlc3NlbnRpZWxsZW1lbnQgw6AgZG9taWNpbGUgKDkyJSkuIExvaW4gZGVycmnDqHJlLCBsJiM4MjE3O3VzYWdlIHN1ciBsZXMgbGlldXggZGUgdHJhdmFpbCBhcnJpdmUgZW4gc2Vjb25kZSBwb3NpdGlvbiAoMjUlKS4gQXV0cmUgY2FyYWN0w6lyaXN0aXF1ZSA6IGwmIzgyMTc7dXNhZ2UgZCYjODIxNzt1biBpUGFkIGVzdCBiZWF1Y291cCBtb2lucyBleGNsdXNpZiBxdSYjODIxNzt1biBzbWFydHBob25lIDogMzMlIGRlcyB1dGlsaXNhdGV1cnMgcHJpbmNpcGF1eCBkw6ljbGFyZW50IHF1JiM4MjE3O2F1IHNlaW4gZCYjODIxNzt1biBtw6ptZSBmb3llciBkZXV4IHBlcnNvbm5lcyB1dGlsaXNlbnQgdW5lIHVuaXF1ZSB0YWJsZXR0ZS4gRGFucyAyNCUgZGVzIGNhcywgbCYjODIxNzt1dGlsaXNhdGlvbiBkZSBsYSB0YWJsZXR0ZSBjb25jZXJuZXJhaXQgYXUgbW9pbnMgMyBwZXJzb25uZXMuIEwmIzgyMTc7w6l0dWRlIHMmIzgyMTc7ZXN0IGVuZmluIGludMOpcmVzc8OpZSDDoCBsYSBqb3VybsOpZSB0eXBlIGRlcyB0YWJsb25hdXRlcyBldCBtb250cmUgYWluc2kgcXVlIGxhIG1ham9yaXTDqSBkZXMgdXRpbGlzYXRldXJzIGQmIzgyMTc7aVBhZCAoNjUlKSBzdXJmZW50IHN1ciBsZXVyIHRhYmxldHRlIGVudHJlIDE3aCBldCAyMWguPC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ldHVkZS1sZXMtdGFibGV0dGVzLW1vaW5zLW11bHRpdGFjaGVzLXF1ZS1sZXMtc21hcnRwaG9uZXMtNTA0MDIvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRXR1ZGVdIExlcyB0YWJsZXR0ZXMgbW9pbnMgbXVsdGl0w6JjaGVzIHF1ZSBsZXMgc21hcnRwaG9uZXM8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9jaGlmZnJlcy1sYS12b2QtYXR0aXJlLXBsdXMtdW4taW50ZXJuYXV0ZS1zdXItNS02MDA2NS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltDaGlmZnJlc10gTGEgVk9EIGF0dGlyZSBkw6lzb3JtYWlzIHBsdXMgZCYjODIxNzt1biBpbnRlcm5hdXRlIGZyYW7Dp2FpcyBzdXIgNTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V0dWRlLWxlcy1mcmFuY2Fpcy1hY2Nyb3MtYXV4LXRhYmxldHRlcy01MDAxNS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFdHVkZV0gTGVzIEZyYW7Dp2FpcyBhY2Nyb3MgYXV4IHRhYmxldHRlcyE8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9jaGlmZnJlcy1hdWRpZW5jZS1kZS1pbnRlcm5ldC1tb2JpbGUtYXUtNGVtZS10cmltZXN0cmUtMjAxMS02MDI1NS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltDaGlmZnJlc10gTCYjODIxNzthdWRpZW5jZSBkZSBsJiM4MjE3O2ludGVybmV0IG1vYmlsZSBhdSA0w6htZSB0cmltZXN0cmUgMjAxMTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V0dWRlLWxlcy1ob21tZXMtZXQtbGVzLWZlbW1lcy1zdXItbGUtd2ViLW1vZGUtZW1wbG9pLTUwMzEyLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0V0dWRlXSBMZXMgaG9tbWVzIGV0IGxlcyBmZW1tZXMgc3VyIGxlIHdlYiA6IGxlIG1vZGUgZCYjODIxNztlbXBsb2k8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXR1ZGUtbWVkaWFtZXRyaWUtZGVzc2luZS1sZS1wb3J0cmFpdC1yb2JvdC1kdS10YWJsb25hdXRlLTYxMTM5L2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjA8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5bRG9zc2llcl0gTGUgY2FzIExpbmtlb2wgLyBMaW5rZWRpbiwgb3UgbGVzIGVuamV1eCBkdSBuYW1pbmc8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2Rvc3NpZXItbGUtY2FzLWxpbmtlb2wtbGlua2VkaW4tb3UtbGVzLWVuamV1eC1kdS1uYW1pbmctNjExMzgvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9kb3NzaWVyLWxlLWNhcy1saW5rZW9sLWxpbmtlZGluLW91LWxlcy1lbmpldXgtZHUtbmFtaW5nLTYxMTM4LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTI6MTg6MDcgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW2J1c2luZXNzXV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU29jaWFsIE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1N0YXJ0dXBdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbVmlkZW9dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZ3JhbnJ1dF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtsaW5rZWRpbl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtMaW5rZW9sXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbWVuXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3VuZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1MjYwPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbTGUgZ8OpYW50IGFtw6lyaWNhaW4gZGVtYW5kZSDDoCBsYSBzdGFydC11cCBmcmFuw6dhaXNlIGRlIHJldGlyZXIgc2EgbWFycXVlIGV0IGxlcyBub21zIGRlIGRvbWFpbmVzIGFzc29jacOpcy4gRnJlbmNoV2ViIG91dnJlIGxlIGRvc3NpZXIgZHUgbmFtaW5nIGF2ZWMgMyBlbnRyZXRpZW5zIHBvdXIgY29tcHJlbmRyZSBsZXMgZW5qZXV4IGV0IGJlc3QgcHJhY3RpY2VzLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkEgbCYjODIxNztvcmlnaW5lIGRlIGNlIGRvc3NpZXIgb3V2ZXJ0IHBhciBGcmVuY2hXZWIsIHVuIGNvdXJyaWVyIGR1IGNhYmluZXQgZCYjODIxNzthdm9jYXRzIHBhcmlzaWVuIDxhIGhyZWY9Imh0dHA6Ly93d3cua29wYWN6LXBhcmlzLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPkxhdyBPZmZpY2VzIEtvcGFjejwvYT4sIHJlcHLDqXNlbnRhbnQgZW4gRnJhbmNlIGR1IHLDqXNlYXUgc29jaWFsIHByb2Zlc3Npb25uZWwgYW3DqXJpY2FpbiBMaW5rZWRJbiwgw6AgZGVzdGluYXRpb24gZGUgR2lsbGVzIER1bHVjcSwgUHLDqXNpZGVudC1Gb25kYXRldXIgZGUgTGlua2VvbCwgcGxhdGVmb3JtZSByZWxhdGlvbm5lbGxlIGVudHJlIHBvcnRldXJzIGRlIHByb2pldHMgZXQgZXhwZXJ0cy4gTGlua2VkSW4gZGVtYW5kZSDDoCBMaW5rZW9sIGRlIHJldGlyZXIgc2EgbWFycXVlIGV0IGxlcyBub21zIGRlIGRvbWFpbmVzIGFzc29jacOpcywgYXUgbW90aWZzIHF1JiM4MjE3O2lsIHkgYXVyYWl0IHNpbWlsaXR1ZGUgZW50cmUgbGVzIGRldXggbWFycXVlcyBldCBxdWUgTGlua2VvbCAmbGFxdW87Jm5ic3A7Y291dnJlIGRlcyBzZXJ2aWNlcyBpZGVudGlxdWVzJm5ic3A7JnJhcXVvOy48L3A%DQo8cD48aW1nIGNsYXNzPSJhbGlnbnJpZ2h0ICB3cC1pbWFnZS01NTY1NiIgdGl0bGU9IkdpbGxlcy1kdWx1Y3EtTGlua2VvbCIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL0dpbGxlcy1kdWx1Y3EtTGlua2VvbC5qcGciIGFsdD0iIiB3aWR0aD0iMTI2IiBoZWlnaHQ9IjEyNiIgLz5Wb2ljaSB0cm9pcyB0cm9pcyBlbnRyZXRpZW5zIHBvdXIgY29tcHJlbmRyZSBsZXMgZW5qZXV4IHByb3ByZXMgw6AgY2UgY2FzIGV0IMOpbGFyZ2lyIGxlIGTDqWJhdCBhdXggYmVzdCBwcmFjdGljZXMgZXQgcHLDqWNhdXRpb25zIMOgIHByZW5kcmUgZW4gbWF0acOocmUgZGUgbmFtaW5nIGRlcyBzdGFydHVwcyA6IDxzdHJvbmc%R2lsbGVzIER1bHVjcSBkZSA8YSBocmVmPSJodHRwOi8vd3d3Lmxpbmtlb2wuZnIvIiB0YXJnZXQ9Il9ibGFuayI%TGlua2VvbDwvYT4sIE1hw650cmUgUmljaGFyZCBNaWxjaGlvciBkdSBjYWJpbmV0IDxhIGhyZWY9Imh0dHA6Ly93d3cuZ3JhbnJ1dC5jb20vLUFjY3VlaWwtLmh0bWwiIHRhcmdldD0iX2JsYW5rIj5HcmFucnV0IEF2b2NhdHMgPC9hPmV0IE1hcmNlbCBCb3R0b24sIGZvbmRhdGV1ciBkZSA8YSBocmVmPSJodHRwOi8vd3d3Lm5vbWVuLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5Ob21lbjwvYT4uPC9zdHJvbmc%PC9wPg0KPHA%PHN0cm9uZz5HaWxsZXMgRHVsdWNxPC9zdHJvbmc%IGTDqXRhaWxsZSBsZSAmbGFxdW87Jm5ic3A7ZG9zc2llciBMaW5rZWRJbiZuYnNwOyZyYXF1bzsgZXQgbGVzIHJhaXNvbnMgcG91ciBsZXNxdWVsbGVzIGlsIGVzdGltZSBxdWUgTGlua2VvbCwgbGFuY8OpIGZpbiAyMDEsIG4mIzgyMTc7ZW50cmUgcGFzIGVuICZsYXF1bzsmbmJzcDtjb25jdXJyZW5jZSZuYnNwOyZyYXF1bzsgYXZlYyBsZSBnw6lhbnQgYW3DqXJpY2Fpbi48L3A%DQo8cD48Y2VudGVyPjxpZnJhbWUgc3JjPSJodHRwOi8vd3d3LmRhaWx5bW90aW9uLmNvbS9lbWJlZC92aWRlby94cHA3N3UiIGZyYW1lYm9yZGVyPSIwIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMwOSI%PC9pZnJhbWU%PC9jZW50ZXI%PGJyIC8%DQo8c3Ryb25nPk1hw650cmUgUmljaGFyZCBNaWxjaGlvcjwvc3Ryb25nPiBkdSBjYWJpbmV0IEdyYW5ydXQgQXZvY2F0LCBjb25zdWx0YW50IHLDqWd1bGllciBkZSBGcmVuY2hXZWIsIMOpdm9xdWUgbGVzIGNvbmRpdGlvbnMgZGUgcmVjZXZhYmlsaXTDqSBkZSBsYSBkZW1hbmRlIGRlIExpbmtlZEluIGV0IGxlcyBwcsOpY2F1dGlvbnMgw6AgcHJlbmRyZSBsb3JzcXUmIzgyMTc7b24gY3LDqcOpIHVuZSBzdGFydC11cC48L3A%DQo8cD48Y2VudGVyPjwhLS0gZGVncmFkYWJsZSBodG1sNSBhdWRpbyBhbmQgdmlkZW8gcGx1Z2luIC0tPjxkaXYgY2xhc3M9ImF1ZGlvX3dyYXAgaHRtbDVhdWRpbyI%PGRpdiBzdHlsZT0iZGlzcGxheTpub25lOyI%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NaWxjaGlvci1MaW5rZWRpbi1saW5rZW9sLm1wMyIgdGl0bGU9IkNsaWNrIHRvIG9wZW4iIGlkPSJmLWh0bWw1YXVkaW8tMCI%QXVkaW8gTVAzPC9hPjxzY3JpcHQgdHlwZT0idGV4dC9qYXZhc2NyaXB0Ij5BdWRpb1BsYXllci5lbWJlZCgiZi1odG1sNWF1ZGlvLTAiLCB7c291bmRGaWxlOiAiaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NaWxjaGlvci1MaW5rZWRpbi1saW5rZW9sLm1wMyJ9KTs8L3NjcmlwdD48L2Rpdj48YXVkaW8gY29udHJvbHMgYXV0b2J1ZmZlciBpZD0iaHRtbDVhdWRpby0wIiBjbGFzcz0iaHRtbDVhdWRpbyI%PHNvdXJjZSBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWlsY2hpb3ItTGlua2VkaW4tbGlua2VvbC5tcDMiIHR5cGU9ImF1ZGlvL21wZWciIC8%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NaWxjaGlvci1MaW5rZWRpbi1saW5rZW9sLm1wMyIgdGl0bGU9IkNsaWNrIHRvIG9wZW4iIGlkPSJmLWh0bWw1YXVkaW8tMCI%QXVkaW8gTVAzPC9hPjxzY3JpcHQgdHlwZT0idGV4dC9qYXZhc2NyaXB0Ij5BdWRpb1BsYXllci5lbWJlZCgiZi1odG1sNWF1ZGlvLTAiLCB7c291bmRGaWxlOiAiaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NaWxjaGlvci1MaW5rZWRpbi1saW5rZW9sLm1wMyJ9KTs8L3NjcmlwdD48L2F1ZGlvPjwvZGl2PjxzY3JpcHQgdHlwZT0idGV4dC9qYXZhc2NyaXB0Ij5pZiAoalF1ZXJ5LmJyb3dzZXIubW96aWxsYSkge3RlbXBhdWQ9ZG9jdW1lbnQuZ2V0RWxlbWVudHNCeVRhZ05hbWUoImF1ZGlvIilbMF07IGpRdWVyeSh0ZW1wYXVkKS5yZW1vdmUoKTsgalF1ZXJ5KCJkaXYuYXVkaW9fd3JhcCBkaXYiKS5zaG93KCl9IGVsc2UgalF1ZXJ5KCJkaXYuYXVkaW9fd3JhcCBkaXYgKiIpLnJlbW92ZSgpOzwvc2NyaXB0PjwvY2VudGVyPiZuYnNwOzwvcD4NCjxwPjxhIGhyZWY9Imh0dHA6Ly93d3cubm9tZW4uY29tL2ZyYW5jYWlzL25vbWVuLW1hcnF1ZXMuaHRtbCIgdGFyZ2V0PSJfYmxhbmsiPk5vbWVuIEludGVybmF0aW9uYWw8L2E%LCBjcsOpw6kgcGFyIDxzdHJvbmc%TWFyY2VsIEJvdHRvbjwvc3Ryb25nPiBlbiAxOTgxIGVzdCBhdWpvdXJkJiM4MjE3O2h1aSB1biBkZXMgbGVhZGVycyBkYW5zIGxhIGNyw6lhdGlvbiBkZSBub21zIGRlIG1hcnF1ZXMgZXQgZGUgcHJvZHVpdHMuIE5vbWVuIGEgYWluc2kgdHJvdXbDqSBwbHVzIGRlIDE1MDAgbm9tcywgY2VydGFpbnMgdHLDqHMgY8OpbMOoYnJlcyA6IFDDtGxlIEVtcGxvaSwgQXJldmEsIFdhbmFkb28sIFByaWNlTWluaXN0ZXImIzgyMzA7IE1hcmNlbCBCb3R0b24sIGV4cGVydCBldCBwYXNzaW9ubsOpIGRlIGxpbmd1aXN0aXF1ZSBldCBkJiM4MjE3O8OpY29ub21pZSwgbGl2cmUgcXVlbHF1ZXMgcGV0aXRzIHNlY3JldHMgcG91ciDDqXZpdGVyIGxlcyBwacOoZ2VzIGV0IHMmIzgyMTc7aW1wb3NlciBzdXIgc29uIG1hcmNow6kuPC9wPg0KPHA%PGNlbnRlcj48aWZyYW1lIHNyYz0iaHR0cDovL3d3dy5kYWlseW1vdGlvbi5jb20vZW1iZWQvdmlkZW8vazRKNmJoVUhqZzVpUTEyVjVabiIgZnJhbWVib3JkZXI9IjAiIHdpZHRoPSI1NTAiIGhlaWdodD0iMzA5Ij48L2lmcmFtZT48L2NlbnRlcj48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL3Jlc2VhdXgtc29jaWF1eC1wcm8tbGFuY2VtZW50LWF1am91cmRodWktZGUtbXV4aS1ldC1saW5rZW9sLTUwNjkwLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W1LDqXNlYXV4IHNvY2lhdXggcHJvXSBMYW5jZW1lbnQgYXVqb3VyZCYjODIxNztodWkgZGUgTXV4aSBldCBMaW5rZW9sPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvaGF1c3NlLXR2YS1tb2JpbGVzLWxvaS1lZmZldHMtYXViYWluZS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkhhdXNzZSBkZSBsYSBUVkEgc3VyIG1vYmlsZXMsIGxhIGxvaSBldCBsZXMgZWZmZXRzIGQmIzgyMTc7YXViYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2lkZWVzLTIwMTItbGUtZGVicmllZi1wYXItZ2lsbGVzLWJhYmluZXQtcHJlc2lkZW50LWR1LWNubnVtLTYwOTQxLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0lkw6llcyAyMDEyXSBMZSBEZWJyaWVmLCBwYXIgR2lsbGVzIEJhYmluZXQsIHByw6lzaWRlbnQgZHUgQ05OdW08L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9pZGVlcy0yMDEyLWxlLWRlYnJpZWYtcGFyLWdpbGxlcy1iYWJpbmV0LXByZXNpZGVudC1kdS1jbm51bS02MDgzNC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltJZMOpZXMgMjAxMl0gTGUgRGVicmllZiwgcGFyIEdpbGxlcyBCYWJpbmV0LCBwcsOpc2lkZW50IGR1IENOTnVtPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvaWRlZXMtMjAxMi1sZS1kZWJyaWVmLWF2ZWMtZ2lsbGVzLWJhYmluZXQtcHJlc2lkZW50LWR1LWNubi02MDI4Mi8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltJZMOpZXMgMjAxMl0gTGUgRGVicmllZiwgYXZlYyBHaWxsZXMgQmFiaW5ldCwgcHLDqXNpZGVudCBkdSBDTk48L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZG9zc2llci1sZS1jYXMtbGlua2VvbC1saW5rZWRpbi1vdS1sZXMtZW5qZXV4LWR1LW5hbWluZy02MTEzOC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4yPC9zbGFzaDpjb21tZW50cz4NCjxlbmNsb3N1cmUgdXJsPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01pbGNoaW9yLUxpbmtlZGluLWxpbmtlb2wubXAzIiBsZW5ndGg9IjYzNTMzMTUiIHR5cGU9ImF1ZGlvL21wZWciIC8%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoNCgkJPHRpdGxlPkRyb3BHaWZ0cyxUb3VzY29wcm9kLCBNYWlzb24gJmFtcDsgRMOpY28sIFNtYXJ0QW5nZWxzJiM4MjMwOyBab29tIHN1ciA2IG5vdXZlYXV0w6lzPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9kcm9wZ2lmdHN0b3VzY29wcm9kLW1haXNvbi1kZWNvLXNtYXJ0YW5nZWxzLXpvb20tc3VyLTYtbm91dmVhdXRlcy02MTEzNy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2Ryb3BnaWZ0c3RvdXNjb3Byb2QtbWFpc29uLWRlY28tc21hcnRhbmdlbHMtem9vbS1zdXItNi1ub3V2ZWF1dGVzLTYxMTM3LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTA6MTM6NTEgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0FsbG9WZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbRHJvcEdpZnRzXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0dvb2dsZSDDqWxlY3Rpb25zXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01haXNvbiAmIETDqWNvXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1NtYXJ0QW5nZWxzXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1RvdXNjb3Byb2RdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTU3OTwvZ3VpZD4NCg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbU21hcnRBbmdlbHMsIERyb3BHaWZ0cywgVG91c2NvcHJvZCwgTWFpc29uICYjMzg7IETDqWNvLCBHb29nbGUgw6lsZWN0aW9ucywgQWxsb1ZldCYjODIzMDsgWm9vbSBzdXIgc2l4IG5vdXZlbGxlcyBwbGF0ZWZvcm1lcy4NCg0KU21hcnRBbmdlbHMgOiBub3V2ZWxsZSBwbGF0ZWZvcm1lIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnRzIGTDqWRpw6llIGF1eCBQTUUNCkNyw6nDqWUgZW4gc2VwdGVtYnJlIDIwMTEgcGFyIEJlbm:DrnQgQmF6emFvY2NoaSwgU21hcnRBbmdlbHMuZnIgZXN0IHVuZSBub3V2ZWxsZSBwbGF0ZWZvcm1lIGVuIGxpZ25lIHN1ciBsYXF1ZWxsZSBsZXMgcGFydGljdWxpZXJzIHBldXZlbnQgaW52ZXN0aXIgZGlyZWN0ZW1lbnQgYXUgY2FwaXRhbCBkZSBQTUUuIE9mZnJhbnQgdW5lIHNvbHV0aW9uIGRlIGdlc3Rpb24gZGUgcGF0cmltb2luZSBhdXggcGFydGljdWxpZXJzLCBTbWFydEFuZ2VscyBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHBzOi8vd3d3LnNtYXJ0YW5nZWxzLmZyL2hvbWVwYWdlIiB0YXJnZXQ9Il9ibGFuayI%U21hcnRBbmdlbHM8L2E%LCA8YSBocmVmPSJodHRwOi8vd3d3LmRyb3BnaWZ0cy5mci8iIHRhcmdldD0iX2JsYW5rIj5Ecm9wR2lmdHM8L2E%LCA8YSBocmVmPSJodHRwOi8vd3d3LnRvdXNjb3Byb2QuY29tLyIgdGFyZ2V0PSJfYmxhbmsiPlRvdXNjb3Byb2Q8L2E%LCA8YSBocmVmPSJodHRwOi8vd3d3Lm1haXNvbi1kZWNvLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5NYWlzb24gJmFtcDsgRMOpY288L2E%LCA8YSBocmVmPSJodHRwOi8vd3d3Lmdvb2dsZS5mci9lbGVjdGlvbnMvZWQvZnIiIHRhcmdldD0iX2JsYW5rIj5Hb29nbGUgw6lsZWN0aW9uczwvYT4sIDxhIGhyZWY9Imh0dHA6Ly9hbGxvdmV0LmNvbS8iIHRhcmdldD0iX2JsYW5rIj5BbGxvVmV0PC9hPiYjODIzMDsgWm9vbSBzdXIgc2l4IG5vdXZlbGxlcyBwbGF0ZWZvcm1lcy48L3A%DQo8cD48aW1nIHRpdGxlPSJub3V2ZWF1eC1zaXRlcyIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL25vdXZlYXV4LXNpdGVzLnBuZyIgYWx0PSIiIHdpZHRoPSIxNDkiIGhlaWdodD0iMzAiIC8%PC9wPg0KPGgyPlNtYXJ0QW5nZWxzIDogbm91dmVsbGUgcGxhdGVmb3JtZSBkJiM4MjE3O2ludmVzdGlzc2VtZW50cyBkw6lkacOpZSBhdXggUE1FPC9oMj4NCjxwPkNyw6nDqWUgZW4gc2VwdGVtYnJlIDIwMTEgcGFyIEJlbm:DrnQgQmF6emFvY2NoaSwgPGEgaHJlZj0iaHR0cHM6Ly93d3cuc21hcnRhbmdlbHMuZnIvaG9tZXBhZ2UiIHRhcmdldD0iX2JsYW5rIj5TbWFydEFuZ2Vscy5mcjwvYT4gZXN0IHVuZSBub3V2ZWxsZSBwbGF0ZWZvcm1lIGVuIGxpZ25lIHN1ciBsYXF1ZWxsZSBsZXMgcGFydGljdWxpZXJzIHBldXZlbnQgaW52ZXN0aXIgZGlyZWN0ZW1lbnQgYXUgY2FwaXRhbCBkZSBQTUUuIE9mZnJhbnQgdW5lIHNvbHV0aW9uIGRlIGdlc3Rpb24gZGUgcGF0cmltb2luZSBhdXggcGFydGljdWxpZXJzLCBTbWFydEFuZ2VscyBwcm9wb3NlIGRvbmMgYXV4IGVudHJlcHJpc2VzIGRlIGxldmVyIGRlcyBmb25kcyB2aWEgZGVzIGludmVzdGlzc2VtZW50cyBwcml2w6lzIHBvdXIgZmluYW5jZXIgbGV1ciBjcm9pc3NhbmNlLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwczovL3d3dy5zbWFydGFuZ2Vscy5mci9ob21lcGFnZSI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1mdWxsIHdwLWltYWdlLTU1NTg5IiB0aXRsZT0ic21hcnRhbmdlbHMiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9zbWFydGFuZ2Vscy5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjE2MSIgLz48L2E%PC9wPg0KPGhyIC8%DQo8aDI%RHJvcGdpZnRzIDogUXVhbmQgbGVzIGNhcnRlcyBjYWRlYXV4IGRldmllbm5lbnQgdmlyYWxlczwvaDI%DQo8cD48YSBocmVmPSJodHRwOi8vd3d3LmRyb3BnaWZ0cy5mci8iIHRhcmdldD0iX2JsYW5rIj5Ecm9wR2lmdHM8L2E%LCBzcMOpY2lhbGlzdGUgZHUgc29jaWFsIGdpZnRpbmcsIHZpZW50IGQmIzgyMTc7YXJyaXZlciBlbiA8c3BhbiBpZD0ibW9yZS01NTU3OSI%PC9zcGFuPkZyYW5jZS4gUHLDqXNlbnRlIGRhbnMgMzAgcGF5cywgbGEgcGxhdGVmb3JtZSBwcm9wb3NlIGF1eCBtYXJxdWVzIGRlIGRpc3RyaWJ1ZXIgbGV1cnMgY2FydGVzIGNhZGVhdXggdmlhIEZhY2Vib29rLCBlbiBpbnZpdGFudCBsZXMgwqsgYW1pcyDCuyDDoCBzZSBsZXMgb2ZmcmlyIGVudHJlIGV1eC4gVW5lIGZvaXMgbGEgY2FydGUgZW52b3nDqWUgc3VyIGxlIG11ciBGYWNlYm9vayBkdSBkZXN0aW5hdGFpcmUsIGV0IGRvbmMgdnVlIHBhciBs4oCZZW5zZW1ibGUgZGUgc2VzIGFtaXMsIGNlcyBkZXJuaWVycyBwZXV2ZW50IHkgY29udHJpYnVlciBldCBhdWdtZW50ZXIgYWluc2kgc2EgdmFsZXVyLiBQYXJtaSBsYSB0cmVudGFpbmUgZGUgcGFydGVuYWlyZXMgYXUgbGFuY2VtZW50LCBvbiByZXRyb3V2ZSA6IEFtYXpvbiwgR2F1bW9udCBQYXRow6ksIEt1c21pIFRlYSwgTWljcm9tYW5pYSwgVG95cyAmbGFxdW87Jm5ic3A7UiZuYnNwOyZyYXF1bzsgVXMsIFVyYmFuIE91dGZpdHRlcnMsIFllbGxvd0tvcm5lciwgWmFsYW5kb%KApiBEcm9wZ2lmdHMgZXN0IGRpc3BvbmlibGUgc3VyIDxhIGhyZWY9Imh0dHA6Ly9pdHVuZXMuYXBwbGUuY29tL2ZyL2FwcC9kcm9wZ2lmdHMvaWQ1MDgxMTM4MTc:bXQ9OCIgdGFyZ2V0PSJfYmxhbmsiPmwmIzgyMTc7QXBwIFN0b3JlPC9hPiBldCBzdXIgPGEgaHJlZj0iaHR0cHM6Ly93d3cuZmFjZWJvb2suY29tL2RpYWxvZy9vYXV0aD9jbGllbnRfaWQ9MjgwNjUzNjU4NjU0NDI0JmFtcDtyZWRpcmVjdF91cmk9aHR0cCUzQSUyRiUyRnd3dy5kcm9wZ2lmdHMuZnIlMkZhdXRoJTJGbG9naW4lMkYmYW1wO3N0YXRlPWQ2MTFhYjllYzFiZGI5MWMwODg0NjlmY2Q5NDk5OGQzJmFtcDtzY29wZT1wdWJsaXNoX3N0cmVhbSUyQ3VzZXJfYmlydGhkYXklMkNmcmllbmRzX2JpcnRoZGF5JTJDdXNlcl9sb2NhdGlvbiUyQ2ZyaWVuZHNfbG9jYXRpb24lMkN1c2VyX3JlbGF0aW9uc2hpcHMlMkNmcmllbmRzX3JlbGF0aW9uc2hpcHMlMkN1c2VyX3JlbGF0aW9uc2hpcF9kZXRhaWxzJTJDZnJpZW5kc19yZWxhdGlvbnNoaXBfZGV0YWlscyUyQ3VzZXJfaG9tZXRvd24lMkNmcmllbmRzX2hvbWV0b3duJTJDb2ZmbGluZV9hY2Nlc3MlMkNlbWFpbCIgdGFyZ2V0PSJfYmxhbmsiPkZhY2Vib29rLiA8L2E%PC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHA6Ly9pdHVuZXMuYXBwbGUuY29tL2ZyL2FwcC9kcm9wZ2lmdHMvaWQ1MDgxMTM4MTc:bXQ9OCI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1tZWRpdW0gd3AtaW1hZ2UtNTU2MjEiIHRpdGxlPSJkcm9wZ2lmdHMtMiIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL2Ryb3BnaWZ0cy0yLTU1MHgyMDUucG5nIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIyMDUiIC8%PC9hPjwvcD4NCjxociAvPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZHJvcGdpZnRzdG91c2NvcHJvZC1tYWlzb24tZGVjby1zbWFydGFuZ2Vscy16b29tLXN1ci02LW5vdXZlYXV0ZXMtNjExMzcvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bQ2hyb25pcXVlXSBEaWdpdGFsIE11c2ljICMyODwvdGl0bGU%DQoNCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9jaHJvbmlxdWUtZGlnaXRhbC1tdXNpYy0yOC02MTEzNi88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2Nocm9uaXF1ZS1kaWdpdGFsLW11c2ljLTI4LTYxMTM2LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDk6Mzc6NTQgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkxhdXJlIERlY2FpbGx5PC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0ludGVybmV0XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01vYmlsZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2thcmFva8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW091cmxhYmVsXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1Nwb3RpZnldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbVHJhY2tzXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1R1cm50YWJsZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0d2l0dGVyXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1OTQ8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtOZXdzIGTDqWNhbMOpZXMsIHZpZMOpb3MgbXVzaWNhbGVzIGV0IGNvbmNlcnRzIGluZMOpc%KApkPigJllc3QgbGEgY2hyb25pcXVlIG11c2lxdWUgRnJlbmNod2ViIGRlIGxhIHNlbWFpbmUgISBBdSBzb21tYWlyZSA6IGxlcyAxMSBub3V2ZWxsZXMgYXBwbGljYXRpb25zIFNwb3RpZnkgw6AgbGEgbG91cGUsIFRyYWNrcy5ieSBlbiBiw6p0YSBwdWJsaXF1ZSwgT3VybGFiZWwgbGFuY2UgbGUgMWVyIGxhYmVsIHBhcnRpY2lwYXRpZiBlbnRpw6hyZW1lbnQgZ8OpcsOpIHBhciBsZXMgZmFucywgVHVybnRhYmxlLmZtIHNpZ25lIGRlcyBhY2NvcmRzIGF2ZWMgbGVzIDQgTWFqb3JzIGR1IGRpc3F1ZSwgVHdpdHRlciBwdWJsaWUgc29uIGd1aWRlIG9mZmljaWVsIHBvdXIgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KDQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPk5ld3MgZMOpY2Fsw6llcywgdmlkw6lvcyBtdXNpY2FsZXMgZXQgY29uY2VydHMgaW5kw6lz4oCmQ%KAmWVzdCBsYSBjaHJvbmlxdWUgbXVzaXF1ZSBGcmVuY2h3ZWIgZGUgbGEgc2VtYWluZSAhIEF1IHNvbW1haXJlIDogbGVzIDExIG5vdXZlbGxlcyBhcHBsaWNhdGlvbnMgU3BvdGlmeSDDoCBsYSBsb3VwZSwgVHJhY2tzLmJ5IGVuIGLDqnRhIHB1YmxpcXVlLCBPdXJsYWJlbCBsYW5jZSBsZSAxZXIgbGFiZWwgcGFydGljaXBhdGlmIGVudGnDqHJlbWVudCBnw6lyw6kgcGFyIGxlcyBmYW5zLCBUdXJudGFibGUuZm0gc2lnbmUgZGVzIGFjY29yZHMgYXZlYyBsZXMgNCBNYWpvcnMgZHUgZGlzcXVlLCBUd2l0dGVyIHB1YmxpZSBzb24gZ3VpZGUgb2ZmaWNpZWwgcG91ciBsZXMgYXJ0aXN0ZXMsIGV0IGxlIHJldG91ciBkZSBoeXBlIGR1IGthcmFva8OpLjwvcD4NCjxwPjxzdHJvbmc%W1NQT1RJRlldIDExIG5vdXZlbGxlcyBhcHBsaWNhdGlvbnMgbXVzaWNhbGVzIGVuIGxpZ25lLjwvc3Ryb25nPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vd3d3LnNwb3RpZnkuY29tL2ZyLyI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1mdWxsIHdwLWltYWdlLTU1NTk4IiB0aXRsZT0ic3BvdGlmeSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3Nwb3RpZnkxLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjQyIiAvPjwvYT48L3A%DQo8cD5FbiBub3ZlbWJyZSBkZXJuaWVyLCA8YSBocmVmPSJodHRwOi8vd3d3LnNwb3RpZnkuY29tL2ZyIj5TcG90aWZ5PC9hPiBvdXZyYWl0IHNhIHBsYXRlZm9ybWUgYXV4IGFwcGxpY2F0aW9ucyBtdXNpY2FsZXMuIFVuZSByw6l2b2x1dGlvbiBkYW5zIGxlIHBldGl0IG1vbmRlIGR1IHN0cmVhbWluZyBxdWksIHBvdXIgbGEgcHJlbWnDqHJlIGZvaXMsIHByb3Bvc2FpdCDDoCBzZXMgdXRpbGlzYXRldXJzIGRlcyBleHDDqXJpZW5jZXMgbXVzaWNhbGVzIGludGVyYWN0aXZlcyBzdXItbWVzdXJlLiBGb3J0IGRlIGNldCBlbmdvdWVtZW50LCA8YSBocmVmPSJodHRwOi8vd3d3LnNwb3RpZnkuY29tL2ZyIj5TcG90aWZ5PC9hPiBhIGTDqXZvaWzDqSBsZSAyMiBtYXJzIG9uemUgbm91dmVsbGVzIGFwcGxpY2F0aW9ucywgZMOpdmVsb3Bww6llcyBub3RhbW1lbnQgcGFyIGxlcyBsYWJlbHMgVW5pdmVyc2FsIE11c2ljLCBTb255IE11c2ljLCBXYXJuZXIgTXVzaWMsIExFR0FDWSwgRGVmIEphbSwgRG9taW5vLCBNYXRhZG9yLCBQSUFTIG91IGVuY29yZSBYNS4gUGV0aXQgdG91ciBk4oCZaG9yaXpvbiBkZXMgbm91dmVhdXTDqXPigKY8c3BhbiBpZD0ibW9yZS01NTU5NCI%PC9zcGFuPjwvcD4NCjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY2hyb25pcXVlLWRpZ2l0YWwtbXVzaWMtMjgtNjExMzYvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bTWF0aW7DqWUgcHJvc3BlY3RpdmUgZHUgR2VzdGVdIFF1ZWwgZnV0dXIgcG91ciBsZXMgbcOpZGlhcyBlbiBsaWduZSA:PC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9tYXRpbmVlLXByb3NwZWN0aXZlLWR1LWdlc3RlLXF1ZWwtZnV0dXItcG91ci1sZXMtbWVkaWFzLWVuLWxpZ25lLTYxMTM0LzwvbGluaz4NCg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9tYXRpbmVlLXByb3NwZWN0aXZlLWR1LWdlc3RlLXF1ZWwtZnV0dXItcG91ci1sZXMtbWVkaWFzLWVuLWxpZ25lLTYxMTM0LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDk6MjQ6MjAgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTWVkaWFdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU29jaWFsIE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2ZyYW5jZSB0ZWxldmlzaW9uc11dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2dlc3RlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3NvY2lhbCBUVl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtUViBjb25uZWN0w6llXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU0NDg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtMZSBHZXN0ZSwgbGUgR3JvdXBlbWVudCBkZXMgRWRpdGV1cnMgZGUgY29udGVudXMgZXQgZGUgc2VydmljZXMgZW4gbGlnbmUsIGEgb3JnYW5pc8OpIGhpZXIgYXUgc2VpbiBkdSBzacOoZ2UgZGUgRnJhbmNlIFTDqWzDqXZpc2lvbnMgdW5lIG1hdGluw6llIHByb3NwZWN0aXZlIGludGl0dWzDqWUgOiAiTcOpZGlhcyBlbiBsaWduZSA6IFdoYXQmIzgyMTc7cyBuZXh0ID8iLiBMJiM4MjE3O29iamVjdGlmIDogaWRlbnRpZmllciBsZXMgbm91dmVhdXggdXNhZ2VzIGxpw6lzIGF1eCB0YWJsZXR0ZXMsIHNtYXJ0cGhvbmVzLCBsYXB0b3BzLCByw6lzZWF1eCBzb2NpYXV4IGV0YyYjODIzMDsgVW5lIGNvbnNvbW1hdGlvbiBxdWkgdHJhbnNmb3JtZSBub3RhbW1lbnQgbGEgcmVsYXRpb24gWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5MZSBHZXN0ZSwgbGUgR3JvdXBlbWVudCBkZXMgRWRpdGV1cnMgZGUgY29udGVudXMgZXQgZGUgc2VydmljZXMgZW4gbGlnbmUsIGEgb3JnYW5pc8OpIGhpZXIgYXUgc2VpbiBkdSBzacOoZ2UgZGUgRnJhbmNlIFTDqWzDqXZpc2lvbnMgdW5lIG1hdGluw6llIHByb3NwZWN0aXZlIGludGl0dWzDqWUgOjxjb2RlPiAiPC9jb2RlPk3DqWRpYXMgZW4gbGlnbmUgOiBXaGF0JiM4MjE3O3MgbmV4dCA:PGNvZGU%IjwvY29kZT4uIEwmIzgyMTc7b2JqZWN0aWYgOiBpZGVudGlmaWVyIGxlcyBub3V2ZWF1eCB1c2FnZXMgbGnDqXMgYXV4IHRhYmxldHRlcywgc21hcnRwaG9uZXMsIGxhcHRvcHMsIHLDqXNlYXV4IHNvY2lhdXggZXRjJiM4MjMwOyBVbmUgY29uc29tbWF0aW9uIHF1aSB0cmFuc2Zvcm1lIG5vdGFtbWVudCBsYSByZWxhdGlvbiBkdSBtZWRpYSBhdmVjIHNvbiBhdWRpZW5jZSAoZXQgcsOpY2lwcm9xdWVtZW50ICEpLjwvcD4NCjxwPkRldXggdGFibGVzIHJvbmRlcyBvbnQgw6l0w6kgbCYjODIxNztvY2Nhc2lvbiBkJiM4MjE3O8OpY2hhbmdlciBzdXIgbGVzIHRlbmRhbmNlcyBkJiM4MjE3O2F1am91cmQmIzgyMTc7aHVpIGV0IGRlIGRlbWFpbiwgYXZlYyBkZXMgcHJvZmVzc2lvbm5lbHMgZGVzIG3DqWRpYXMuIFBhcm1pIGV1eCwgRXJpYyBTY2hlcmVyLCBEaXJlY3RldXIgZGUgbGEgUHJvc3BlY3RpdmUgZGUgbGEgU3RyYXTDqWdpZSBldCBkZXMgUmVsYXRpb25zIEludGVybmF0aW9uYWxlcyBkZSBGcmFuY2UgVMOpbMOpdmlzaW9ucy48L3A%DQo8cD48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU0ODMiIHRpdGxlPSJHZXN0ZSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL0dlc3RlMS5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjEzMiIgLz48L3A%DQo8cD5SZXZlbmFudCBkZXB1aXMgcGV1IGR1ICZsYXF1bzsmbmJzcDtTb3V0aCBCeSBTb3V0aFdlc3QmbmJzcDsmcmFxdW87IMOgIEF1c3RpbiBhdXggRXRhdHMtVW5pcywgaWwgYSBwdSB0w6ltb2lnbmVyIGRlIGwmIzgyMTc7ZXNzb3IgZ3JhbmRpc3NhbnQgZGUgbGEgc29jaWFsIFRWLCBsYSB0w6lsw6l2aXNpb24gcXVpIGludMOoZ3JlIGxlcyByw6lzZWF1eCBzb2NpYXV4IGRhbnMgc29uIGludGVyZmFjZSA6ICZsYXF1bzsmbmJzcDs8ZW0%IElsIHkgYSB1biBlbnJpY2hpc3NlbWVudCBkZSBsJiM4MjE3O2V4cMOpcmllbmNlIHV0aWxpc2F0ZXVyIHF1aSBlc3QgaW50ZXJ2ZW51IGNlcyAxOCBkZXJuaWVycyBtb2lzLCBncsOiY2UgYXV4IHRhYmxldHRlcyBldCBhdXggc21hcnRwaG9uZXM8L2VtPjxjb2RlPiI8L2NvZGU%LCBwcsOpY2lzZS10LWlsLiBBdXggRXRhdHMtVW5pcywgcHLDqHMgZGUgbGEgbW9pdGnDqSBkZXMgdXRpbGlzYXRldXJzIGRlIGNlcyBkZXZpY2VzIHNlIGNvbm5lY3RlbnQgZW4gcmVnYXJkYW50IGxhIHTDqWzDqXZpc2lvbi4gRW4gRnJhbmNlLCBsZSBjaGlmZnJlIHRvdXJuZSBhdXRvdXIgPHNwYW4gaWQ9Im1vcmUtNTU0NDgiPjwvc3Bhbj5kZXMgMzAlLjwvcD4NCjxwPkxlcyBncmFuZGVzIGNoYcOubmVzIGRlIFRWIG9udCBjb21tZW5jw6kgw6AgaW50w6lncmVyIGNldHRlIG5vdXZlbGxlIGNvbnNvbW1hdGlvbiBlbiBtaXNhbnQgc3VyIGxlIGNhbmFsIFR3aXR0ZXIgZXQgRmFjZWJvb2ssIHN1ciBkZXMgw6ltaXNzaW9ucyBwcmltZS10aW1lIGNvbW1lICZsYXF1bzsmbmJzcDtUb3AgQ2hlZiZuYnNwOyZyYXF1bzsgb3UgZGVzIMOpbWlzc2lvbnMgcG9saXRpcXVlcyDDoCBmb3J0ZSBhdWRpZW5jZSwgY29tbWUgJmxhcXVvOyZuYnNwO0RlcyBQYXJvbGVzIGV0IGRlcyBBY3RlcyZuYnNwOyZyYXF1bzsuIExlcyBkZXJuacOocmVzIFZpY3RvaXJlcyBkZSBsYSBNdXNpcXVlIG9udCBnw6luw6lyw6kgcGx1cyBkZSAzMCAwMDAgdHdlZXRzIHBlbmRhbnQgbGEgZGlmZnVzaW9uLjwvcD4NCjxwPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTYwOSIgdGl0bGU9ImJhbmRlYXUgR2VzdGUiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9iYW5kZWF1LUdlc3RlMS5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjE4MyIgLz48L3A%DQo8L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL21hdGluZWUtcHJvc3BlY3RpdmUtZHUtZ2VzdGUtcXVlbC1mdXR1ci1wb3VyLWxlcy1tZWRpYXMtZW4tbGlnbmUtNjExMzQvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KDQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltTaG9wcGluZ10gQm9uaWFsLCBsZSBndWlkZSBwb3VyIHByw6lwYXJlciBzZXMgYWNoYXRzIGVuIG1hZ2FzaW48L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2JvbmlhbC1ndWlkZS1wb3VyLXByZXBhcmVyLXNlcy1hY2hhdHMtZW4tbWFnYXNpbi02MTEzMy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2JvbmlhbC1ndWlkZS1wb3VyLXByZXBhcmVyLXNlcy1hY2hhdHMtZW4tbWFnYXNpbi02MTEzMy8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDA4OjMwOjQxICswMDAwPC9wdWJEYXRlPg0KDQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZUNvbW1lcmNlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01hcmtldGluZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtWaWRlb11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVthY2hhdF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtCb25pYWxdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZ3VpZGVdXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVt1bmVdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTQ5NzwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0ZpbGlhbGUgZGUgS2F1ZkRhIGR1IEdyb3VwZSBBeGVsIFNwcmluZ2VyLCBCb25pYWwgYSBkw6liYXJxdcOpIGVuIEZyYW5jZSBlbiBkw6ljZW1icmUgZGVybmllci4gQ2UgZ3VpZGUgcGVybWV0IGRlIGNvbnN1bHRlciBwbHVzaWV1cnMgbWlsbGllcnMgZGUgcGFnZXMgcHJvZHVpdHMuIEVudHJldGllbiBhdmVjIGxlIENFTyBGcmFuY2UgZGUgQm9uaWFsLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkxhbmPDqSBlbiBkw6ljZW1icmUgMjAxMSwgPGEgaHJlZj0iaHR0cDovL3d3dy5ib25pYWwuZnIvIiB0YXJnZXQ9Il9ibGFuayI%Qm9uaWFsPC9hPiBwZXJtZXQgZGUgcHLDqXBhcmVyIHNlcyBhY2hhdHMgZW4gdW4gY2xpbiBkJiM4MjE3O29laWwgOiBvbiBwZXV0IHJlY2hlcmNoZXIgdW4gcHJvZHVpdCwgY29uc3VsdGVyIHNhIGRpc3BvbmliaWxpdMOpLCBjb25uYcOudHJlIGxlcyBhZHJlc3NlcyBldCBob3JhaXJlcyBk4oCZb3V2ZXJ0dXJlIGRlcyBtYWdhc2lucyBwcm9jaGVzIGRlIHNvaeKApjwvcD4NCjxwPkxlIHNpdGUgZXN0IGTDqWNsaW7DqSBlbiA8YSBocmVmPSJodHRwOi8vaXR1bmVzLmFwcGxlLmNvbS9mci9hcHAvYm9uaWFsL2lkNDY4NjI0NTY3P210PTgiIHRhcmdldD0iX2JsYW5rIj5hcHBsaWNhdGlvbjwvYT4sIGRpc3BvbmlibGUgc3VyIGlQaG9uZSwgaVBhZCBldCBBbmRyb2lkLiBBdSAwOSBtYXJzLCBCb25pYWwgw6l0YWl0IGwmIzgyMTc7YXBwbGljYXRpb24gbGEgcGx1cyB0w6lsw6ljaGFyZ8OpZSBzdXIgQXBwIFN0b3JlIGRhbnMgbGEgY2F0w6lnb3JpZSAmbGFxdW87Jm5ic3A7YXBwbGljYXRpb25zIGdyYXR1aXRlcyZuYnNwOyZyYXF1bzssIGV0IHNlIHBsYcOnYWl0IGRhbnMgbGUgVE9QIDUgZGVzIGFwcGxpY2F0aW9ucyBsZXMgcGx1cyB0w6lsw6ljaGFyZ8OpZXMgc3VyIGlQYWQuIExlIG1vZMOobGUgZGUgQm9uYWwgcmVwb3NlIHN1ciBsYSBwZXJmb3JtYW5jZSA6IEJvbmlhbCBwcm9wb3NlIGRlcyB2b2x1bWVzIGRlIGNvbnN1bHRhdGlvbiBzdXIgbGVzIGNhdGFsb2d1ZXMsIHRyw6hzIGNvbnN1bHTDqXMgcGFyIGxlcyB1dGlsaXNhdGV1cnMuPC9wPg0KPHA%RmlsaWFsZSBkZSBsYSBzb2Npw6l0w6kgYWxsZW1hbmRlIDxhIGhyZWY9Imh0dHA6Ly93d3cua2F1ZmRhLmRlL0JlcmxpbiIgdGFyZ2V0PSJfYmxhbmsiPmthdWZEQTwvYT4gKEdyb3VwZSBBeGVsIFNwcmluZ2VyKSwgQm9uaWFsIHJldmVuZGlxdWUgdW5lIGF1ZGllbmNlIGRlIDRNIGRlIFZVIGVuIEFsbGVtYWduZS4ga2F1ZkRBIGEgZMOpdmVsb3Bww6kgdW5lIHRlY2hub2xvZ2llIGV0IHVuIHNhdm9pci1mYWlyZSBlbiBtYXJrZXRpbmcgZGlnaXRhbCBldCBTRU8uPC9wPg0KPHA%PHN0cm9uZz5FbnRyZXRpZW4gYXZlYyBNYXR0aGlhcyBCZXJhaHlhLUxhemFydXMsIENFTyBkZSBCb25pYWwgRnJhbmNlIDwvc3Ryb25nPjwvcD4NCjxwPjxjZW50ZXI%PGlmcmFtZSBzcmM9Imh0dHA6Ly93d3cuZGFpbHltb3Rpb24uY29tL2VtYmVkL3ZpZGVvL2szQ1BYckJCR01vQmNlMlZxYmMiIGZyYW1lYm9yZGVyPSIwIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMwOSI%PC9pZnJhbWU%PC9jZW50ZXI%PC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9uZXdzLWNlLXF1ZS1pbC1mYXV0LXNhdm9pci1jZS1tYXRpbi01MDQ0MC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltOZXdzXSBDZSBxdSYjODIxNztpbCBmYXV0IHNhdm9pciBjZSBtYXRpbjwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL29obXlkZWFsLWxhbmNlLW9mZmljaWVsbGVtZW50LXNvbi1hcHBsaWNhdGlvbi1pcGFkLTUwMjM2LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%T2hNeURlYWwgbGFuY2Ugc29uIGFwcGxpY2F0aW9uIGlQYWQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9za3lwZS1kZXZyYWl0LWV0cmUtZGlzcG9uaWJsZS1lbi12ZXJzaW9uLWlwYWQtZGVzLWNldHRlLXNlbWFpbmUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5Ta3lwZSBkZXZyYWl0IMOqdHJlIGRpc3BvbmlibGUgZW4gdmVyc2lvbiBpUGFkIGTDqHMgY2V0dGUgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V4Y2x1LWJvbnMtcGxhbnMtb2hteWRlYWwtZGlzcG9uaWJsZXMtc3VyLWlwYWQvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRXhjbHVdIExlcyBib25zIHBsYW5zIGQmIzgyMTc7T2hNeWRlYWwgZGlzcG9uaWJsZXMgc3VyIElwYWQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ub3V2ZWF1LXN0YXItYXBwLWxlLWdvb2dsZS1kZXMtYXBwbGljYXRpb25zLW1vYmlsZXMtNjA3MzEvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bTm91dmVhdV0gU3RhciBhcHAsIGxlIEdvb2dsZSBkZXMgYXBwbGljYXRpb25zIG1vYmlsZXM8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvYm9uaWFsLWd1aWRlLXBvdXItcHJlcGFyZXItc2VzLWFjaGF0cy1lbi1tYWdhc2luLTYxMTMzL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjM8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoNCgkJPGl0ZW0%DQoJCTx0aXRsZT5bQXRlbGllciBudW3DqXJpcXVlIC0gQkZNIEJ1c2luZXNzXSBMYSBjaHJvbmlxdWUgc3RhcnQtdXAgZGUgRnJlbmNod2ViICMyMiA6IE1lbnRpb24ubmV0PC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9hdGVsaWVyLW51bWVyaXF1ZS1iZm0tYnVzaW5lc3MtbGEtY2hyb25pcXVlLXN0YXJ0LXVwLWRlLWZyZW5jaHdlYi0yMi1tZW50aW9uLW5ldC02MTEzMy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2F0ZWxpZXItbnVtZXJpcXVlLWJmbS1idXNpbmVzcy1sYS1jaHJvbmlxdWUtc3RhcnQtdXAtZGUtZnJlbmNod2ViLTIyLW1lbnRpb24tbmV0LTYxMTMzLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDg6MzA6MzggKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkJlcnRyYW5kIExlbm90cmU8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQWN0dV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtTdGFydHVwXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01lbnRpb25dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbdmVpbGxlXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1NjI8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtDcsOpw6kgZW50cmUgUGFyaXMgZXQgQnJ1eGVsbGVzIHBhciA0IGNyw6lhdGV1cnMgZG9udCB1biBmb25kYXRldXIgZGUgRm90b2xpYSwgVGhpYmF1bHQgRWx6aWVyZSBldCBsJiM4MjE3O2V4IENFTyBkZSBQcmVzc2tpbmcsIEVkb3VhcmQgIGRlIGxhIEpvbnF1acOocmUsIE1lbnRpb24gZXN0IHVuIG5vdXZlbCBvdXRpbCBkZSB2ZWlsbGUgcG91ciBtb25pdG9yZXIgZW4gdGVtcHMgcsOpZWwgY2UgcXVpIHNlIGRpdCBzdXIgdm91cywgdm90cmUgbWFycXVlIG91IHZvdHJlIHNvY2nDqXTDqSBzdXIgbCYjODIxNztlbnNlbWJsZSBkZSBsJiM4MjE3O0ludGVybmV0IChXZWIsIFR3aXR0ZXIsIEZsaWNrciwgR29vZ2xlIE5ld3MsIGxlcyBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkNyw6nDqSBlbnRyZSBQYXJpcyBldCBCcnV4ZWxsZXMgcGFyIDQgY3LDqWF0ZXVycyBkb250IHVuIGZvbmRhdGV1ciBkZSBGb3RvbGlhLCBUaGliYXVsdCBFbHppZXJlIGV0IGwmIzgyMTc7ZXggQ0VPIGRlIFByZXNza2luZywgRWRvdWFyZCAgZGUgbGEgSm9ucXVpw6hyZSwgPGEgaHJlZj0iaHR0cHM6Ly9mci5tZW50aW9uLm5ldC8iIHRhcmdldD0iX2JsYW5rIj5NZW50aW9uPC9hPiBlc3QgdW4gbm91dmVsIG91dGlsIGRlIHZlaWxsZSBwb3VyIG1vbml0b3JlciBlbiB0ZW1wcyByw6llbCBjZSBxdWkgc2UgZGl0IHN1ciB2b3VzLCB2b3RyZSBtYXJxdWUgb3Ugdm90cmUgc29jacOpdMOpIHN1ciBsJiM4MjE3O2Vuc2VtYmxlIGRlIGwmIzgyMTc7SW50ZXJuZXQgKFdlYiwgVHdpdHRlciwgRmxpY2tyLCBHb29nbGUgTmV3cywgbGVzIGJsb2dzLCBmb3J1bXMsIHBsYXRlZm9ybWVzIHZpZMOpbyYjODIzMDspLjwvcD4NCjxwPjxhIGhyZWY9Imh0dHBzOi8vZnIubWVudGlvbi5uZXQvIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1NzciIHRpdGxlPSJNZW50aW9uIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5qcGVnIiBhbHQ9IiIgd2lkdGg9IjQ1MiIgaGVpZ2h0PSIyNTkiIC8%PC9hPjwvcD4NCjxwPlVuIG91dGlsIGRlIHZlaWxsZSBleGhhdXN0aWYgcXVpIGVudGVuZCBzZSBwb3NpdGlvbm5lciBjb21tZSB1biBEcm9wYm94IG91IHVuIEV2ZXJub3RlIMOgIGxhIGxpc2nDqHJlIGRlcyB1dGlsaXNhdGlvbnMgcGVyc29ubmVsbGVzIC8gcHJvZmVzc2lvbm5lbGxlcyBkYW5zIHVuZSBnYW1tZSBkZSB0YXJpZnMgcGx1cyBhY2Nlc3NpYmxlIHF1ZSBjZWxsZSBkZXMgc29sdXRpb25zIEIyQiBleGlzdGFudGVzIHN1ciBsZSBtYXJjaMOpLiBNZW50aW9uIGVzdCB1bmUgJmxhcXVvOyZuYnNwO3NpbmdsZS1wYWdlLWFwcCZuYnNwOyZyYXF1bzsgKE1hYyAvIFdpbmRvd3MgLyBMaW51eCksIGJpZW50w7R0IHN1ciBtb2JpbGUsIGV0IGRpc3BvbmlibGUgZW4gMyBsYW5ndWVzIChmcmFuw6dhaXMsIGFuZ2xhaXMsIGFsbGVtYW5kKS4gTGVzIGNvbnRlbnVzIHNvbnQsIGV1eCwgdHJhY2vDqXMgZGFucyA0MiBsYW5ndWVzLiBVbiBjaG9peCBjYXTDqWdvcmllbCBkZXMgYWxlcnRlcyBwZXJtZXQgZGUgY2libGVyIHNlcyBjaGFtcHMgZGUgdmVpbGxlLjwvcD4NCjxwPkxlIGJ1c2luZXNzIG1vZGVsIGRlIE1lbnRpb24gdGllbnQgw6AgdW5lIG9mZnJlIGZyZWVtaXVtIDogZGUgNC45MCDigqwgcG91ciA1MDAgbWVudGlvbnMgcGFyIG1vaXMgw6AgMTk5IOKCrCBwb3VyIDUwIDAwMCBtZW50aW9ucy48L3A%DQo8IS0tIGRlZ3JhZGFibGUgaHRtbDUgYXVkaW8gYW5kIHZpZGVvIHBsdWdpbiAtLT48ZGl2IGNsYXNzPSJhdWRpb193cmFwIGh0bWw1YXVkaW8iPjxkaXYgc3R5bGU9ImRpc3BsYXk6bm9uZTsiPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMiIHRpdGxlPSJDbGljayB0byBvcGVuIiBpZD0iZi1odG1sNWF1ZGlvLTEiPkF1ZGlvIE1QMzwvYT48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%QXVkaW9QbGF5ZXIuZW1iZWQoImYtaHRtbDVhdWRpby0xIiwge3NvdW5kRmlsZTogImh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMifSk7PC9zY3JpcHQ%PC9kaXY%PGF1ZGlvIGNvbnRyb2xzIGF1dG9idWZmZXIgaWQ9Imh0bWw1YXVkaW8tMSIgY2xhc3M9Imh0bWw1YXVkaW8iPjxzb3VyY2Ugc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01lbnRpb24ubXAzIiB0eXBlPSJhdWRpby9tcGVnIiAvPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMiIHRpdGxlPSJDbGljayB0byBvcGVuIiBpZD0iZi1odG1sNWF1ZGlvLTEiPkF1ZGlvIE1QMzwvYT48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%QXVkaW9QbGF5ZXIuZW1iZWQoImYtaHRtbDVhdWRpby0xIiwge3NvdW5kRmlsZTogImh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMifSk7PC9zY3JpcHQ%PC9hdWRpbz48L2Rpdj48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%aWYgKGpRdWVyeS5icm93c2VyLm1vemlsbGEpIHt0ZW1wYXVkPWRvY3VtZW50LmdldEVsZW1lbnRzQnlUYWdOYW1lKCJhdWRpbyIpWzBdOyBqUXVlcnkodGVtcGF1ZCkucmVtb3ZlKCk7IGpRdWVyeSgiZGl2LmF1ZGlvX3dyYXAgZGl2Iikuc2hvdygpfSBlbHNlIGpRdWVyeSgiZGl2LmF1ZGlvX3dyYXAgZGl2ICoiKS5yZW1vdmUoKTs8L3NjcmlwdD4NCjxwPjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbWVudGlvbi1zb3J0aXItY29tLWluZm9uYWlzc2FuY2UtYmRzcGhlcmUtbGVzLTQtZGVybmllcmVzLW5vdXZlYXV0ZXMtNjEwNDIvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5NZW50aW9uLCBTb3J0aXIuY29tLCBJbmZvbmFpc3NhbmNlLCBCRHNwaMOocmUgOiBsZXMgNCBkZXJuacOocmVzIG5vdXZlYXV0w6lzPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvYXVqb3VyZGh1aS1zdXItZnJlbmNod2ViLTIwLTYxMDUxLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%QXVqb3VyZCYjODIxNztodWkgc3VyIEZyZW5jaFdlYiYjODIzMDs8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ncmFuZGVzLW1hcnF1ZXMtZmFjZWJvb2stdHdpdHRlci8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPk1haXMgb8O5IHNvbnQgbGVzIEZhY2Vib29rIGV0IFR3aXR0ZXIgZGVzIGdyYW5kZXMgbWFycXVlcyA:PC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvYnV6enBhcmFkaXNlLWRldmllbnQtbGEtMWVyZS1wbGF0ZWZvcm1lLWV1cm9wZWVubmUtZGUtc29jaWFsLW1lZGlhLWFkdmVydGlzaW5nLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%QnV6elBhcmFkaXNlIGRldmllbnQgbGEgMcOocmUgcGxhdGVmb3JtZSBldXJvcMOpZW5uZSBkZSBzb2NpYWwgbWVkaWEgYWR2ZXJ0aXNpbmc8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9kZXJyaWVyZS1sYS1yZXZvbHV0aW9uLWR1LW1vYmlsZS1zZS1jYWNoZXJhaXQtbnVtZXJpY2FibGUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5EZXJyacOocmUgJmxhcXVvOyZuYnNwO0xhIFLDqXZvbHV0aW9uIGR1IE1vYmlsZSZuYnNwOyZyYXF1bzsgc2UgY2FjaGVyYWl0IE51bWVyaWNhYmxlICE8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KDQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9hdGVsaWVyLW51bWVyaXF1ZS1iZm0tYnVzaW5lc3MtbGEtY2hyb25pcXVlLXN0YXJ0LXVwLWRlLWZyZW5jaHdlYi0yMi1tZW50aW9uLW5ldC02MTEzMy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCjxlbmNsb3N1cmUgdXJsPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01lbnRpb24ubXAzIiBsZW5ndGg9IjM3NjE1NTAiIHR5cGU9ImF1ZGlvL21wZWciIC8%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bSW5mb2dyYXBoaWVdIExlIG1hcmNow6kgZGVzIGFwcGxpY2F0aW9ucyBtb2JpbGVzIG11c2ljYWxlczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvaW5mb2dyYXBoaWUtbGUtbWFyY2hlLWRlcy1hcHBsaWNhdGlvbnMtbW9iaWxlcy1tdXNpY2FsZXMtNjExMzIvPC9saW5rPg0KDQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2luZm9ncmFwaGllLWxlLW1hcmNoZS1kZXMtYXBwbGljYXRpb25zLW1vYmlsZXMtbXVzaWNhbGVzLTYxMTMyLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDg6MDk6MDQgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbSW50ZXJuZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGVzIGNoaWZmcmVzIGR1IG5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtNb2JpbGVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYXBwbGljYXRpb25dXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtjb21wYXJhaXNvbl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtlc3ByaXQgbXVzaXF1ZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtTb3VuZFBsYWNlc11dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NTYwPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbQSBsJiM4MjE3O29jY2FzaW9uIGRlIGxhIHNvcnRpZSBkZSBsYSBub3V2ZWxsZSB2ZXJzaW9uIGRlIGwmIzgyMTc7YXBwbGljYXRpb24gU291bmRwbGFjZXMsIGTDqWRpw6llIMOgIGxhIGTDqWNvdXZlcnRlIGRlIGpldW5lcyB0YWxlbnRzIG11c2ljYXV4LCBFc3ByaXQgTXVzaXF1ZSBhIHLDqWFsaXPDqSB1bmUgaW5mb2dyYXBoaWUgc3VyIGxlcyBhcHBsaWNhdGlvbnMgbW9iaWxlcyBtdXNpY2FsZXMuIEF1IG1lbnUgOiB1c2FnZXMgZXQgY2hpZmZyZXMgZHUgbWFyY2jDqSwgbWFpcyDDqWdhbGVtZW50IGNvbXBhcmFpc29uIGRlcyBkaWZmw6lyZW50ZXMgYXBwbGljYXRpb25zIG1vYmlsZXMgZGlzcG9uaWJsZXMsIHNhbnMgb3VibGllciBxdWVscXVlcyBjaGlmZnJlcyByw6ljYXBpdHVsYXRpZnMgZHUgZGlzcG9zaXRpZiBTb3VuZHBsYWNlcy4NCg0KUGFybWkgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5BIGwmIzgyMTc7b2NjYXNpb24gZGUgbGEgc29ydGllIGRlIGxhIG5vdXZlbGxlIHZlcnNpb24gZGU8YSBocmVmPSJodHRwOi8vaXR1bmVzLmFwcGxlLmNvbS9mci9hcHAvc291bmQtcGxhY2VzLWVzcHJpdC1tdXNpcXVlL2lkNDM3Nzk2OTQ1P210PTgiIHRhcmdldD0iX2JsYW5rIj4gbCYjODIxNzthcHBsaWNhdGlvbiBTb3VuZHBsYWNlczwvYT4sIGTDqWRpw6llIMOgIGxhIGTDqWNvdXZlcnRlIGRlIGpldW5lcyB0YWxlbnRzIG11c2ljYXV4LCBFc3ByaXQgTXVzaXF1ZSBhIHLDqWFsaXPDqSB1bmUgaW5mb2dyYXBoaWUgc3VyIGxlcyBhcHBsaWNhdGlvbnMgbW9iaWxlcyBtdXNpY2FsZXMuIEF1IG1lbnUgOiB1c2FnZXMgZXQgY2hpZmZyZXMgZHUgbWFyY2jDqSwgbWFpcyDDqWdhbGVtZW50IGNvbXBhcmFpc29uIGRlcyBkaWZmw6lyZW50ZXMgYXBwbGljYXRpb25zIG1vYmlsZXMgZGlzcG9uaWJsZXMsIHNhbnMgb3VibGllciBxdWVscXVlcyBjaGlmZnJlcyByw6ljYXBpdHVsYXRpZnMgZHUgZGlzcG9zaXRpZiBTb3VuZHBsYWNlcy48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy5lc3ByaXRtdXNpcXVlLmZyL2luZm9ncmFwaGllIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1NjQiIHRpdGxlPSJhcHBsaWNhdGlvbnMtbW9iaWxlcy1tdXNpcXVlcyIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL2FwcGxpY2F0aW9ucy1tb2JpbGVzLW11c2lxdWVzLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjcxIiAvPjwvYT48L3A%DQo8cD5QYXJtaSBsZXMgY2hpZmZyZXMgY2xlZnMgOjwvcD4NCjx1bD4NCjxsaT4yMCUgZGVzIGdlbnMgdXRpbGlzZW50IGxldXIgbW9iaWxlIHBvdXIgw6ljb3V0ZXIgZGUgbGEgbXVzaXF1ZTwvbGk%DQo8bGk%OU0gZGUgdGl0cmVzIHTDqWzDqWNoYXJnw6lzIHN1ciBtb2JpbGU8L2xpPg0KPGxpPlBsdXMgZGUgPHNwYW4gaWQ9Im1vcmUtNTU1NjAiPjwvc3Bhbj4xNiUgZHUgQ0EgZHUgbWFyY2jDqSBkZSBsYSBtdXNpcXVlIG51bcOpcmlxdWUgZXN0IHLDqWFsaXPDqSBzdXIgbGVzIG1vYmlsZXM8L2xpPg0KPGxpPjIxIDI3NyBhcHBsaWNhdGlvbnMgbXVzaWNhbGVzIGRpc3BvbmlibGVzIHN1ciBsJiM4MjE3O0FwcCBTdG9yZSwgZG9udCA1NSUgZ3JhdHVpdGVzPC9saT4NCjxsaT4xMDAgMDAwIHTDqWzDqWNoYXJnZW1lbnRzIHBvdXIgU291bmRwbGFjZXM8L2xpPg0KPC91bD4NCjxwPjwvY2VudGVyPg0KPGRpdiBjbGFzcz0iZXNwcml0bXVzaXF1ZV9lbWJlZCI%DQo8cD48aW1nIHRpdGxlPSIiIHNyYz0iaHR0cDovL3d3dy5lc3ByaXRtdXNpcXVlLmZyL21lZGlhbGlicmFyeS9jbXMvNjEvY2VfaW5mb2dyYXBoaWVmaW5hbC5qcGciIGFsdD0iIiB3aWR0aD0iNTUwIiBib3JkZXI9IjAiIC8%PC9wPg0KPGRpdiBjbGFzcz0iZ2NfYXJ0aWNsZV9ncmFwaGljX2J1dHRvbl9lbWJlZCI%PC9kaXY%DQo8ZGl2IGNsYXNzPSJnY19hcnRpY2xlX2dyYXBoaWNfY29weSI%PHNwYW4gY2xhc3M9ImVzcHJpdG11c2lxdWVfZW1iZWRfdGl0bGVfY29weSI%SW50w6lncmVyIGwmIzgyMTc7aW5mb2dyYXBoaWUgY2kgZGVzc291cyDDoCB2b3RyZSBzaXRlPC9zcGFuPjxzcGFuIGNsYXNzPSJlc3ByaXRtdXNpcXVlX2VtYmVkX3dpZHRoX2NvcHkiPlRhaWxsZSBkZSBsJiM4MjE3O2ltYWdlIChlbiBwaXhlbCkgOjwvc3Bhbj48YnIgLz4NCjxpbnB1dCB0eXBlPSJ0ZXh0IiBuYW1lPSJlc3ByaXRtdXNpcXVlX2VtYmVkX3dpZHRoIiB2YWx1ZT0iNTUwIiAvPiA8c3BhbiBjbGFzcz0iZXNwcml0bXVzaXF1ZV9lbWJlZF93aWR0aF9jb3B5Ij5Db3BpZXIgbGUgY29udGVudSBkdSBjaGFtcCBjaSBkZXNzb3VzIDo8L3NwYW4%PGJyIC8%DQo8aW5wdXQgaWQ9ImVzcHJpdG11c2lxdWVfZW1iZWRfY29weSIgdHlwZT0idGV4dCIgbmFtZT0iZXNwcml0bXVzaXF1ZV9lbWJlZF9jb3B5IiB2YWx1ZT0iIiAvPjwvZGl2Pg0KPHA%PHNjcmlwdCB0eXBlPSJ0ZXh0L2phdmFzY3JpcHQiPi8vIDwhW0NEQVRBWw0KdmFyIHVybCA9ICdodHRwOi8vd3d3LmVzcHJpdG11c2lxdWUuZnInO3ZhciBpbWFnZV91cmwgPSB1cmwrJ2h0dHA6Ly93d3cuZXNwcml0bXVzaXF1ZS5mci9tZWRpYWxpYnJhcnkvY21zLzYxL2NlX2luZm9ncmFwaGllZmluYWwuanBnJzt2YXIgaW1hZ2VfdGl0bGUgPSAnJzsNCi8vIF1dJmd0Ozwvc2NyaXB0PjxzY3JpcHQgdHlwZT0idGV4dC9qYXZhc2NyaXB0IiBzcmM9Imh0dHA6Ly93d3cuZXNwcml0bXVzaXF1ZS5mci9qcy9mcm9udC9lbWJlZC5qcyI%PC9zY3JpcHQ%PC9wPg0KPC9kaXY%DQo8cD4gPC9jZW50ZXI%PC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sYS1jYWlzc2UtZXBhcmduZS1hZmZpbmUtc2Etc3RyYXRlZ2llLW11c2ljYWxlLWF2ZWMtdW5lLW5vdXZlbGxlLXZlcnNpb24tZGUtc291bmRwbGFjZXMtZXQtZXNwcml0bXVzaXF1ZS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkxhIENhaXNzZSBkJiM4MjE3O0VwYXJnbmUgYWZmaW5lIHNhIHN0cmF0w6lnaWUgbXVzaWNhbGUgYXZlYyB1bmUgbm91dmVsbGUgdmVyc2lvbiBkZSBTb3VuZFBsYWNlcyBldCBFc3ByaXRNdXNpcXVlPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvdXNlcmFkZ2VudHMtcGFzc2UtYXBwLXN0b3JlLWFwcGxlLWF1LWNyaWJsZS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPlVzZXJBRGdlbnRzIHBhc3NlIGwmIzgyMTc7QXBwIFN0b3JlIGQmIzgyMTc7QXBwbGUgYXUgY3JpYmxlPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvcGV0aXQtdGVzdC1kZS1nb29nbGUtZnJpZW5kLWNvbm5lY3QvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5QZXRpdCB0ZXN0IGRlIEdvb2dsZSBGcmllbmQgQ29ubmVjdDwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xvcnMtZHUtcHJvY2hhaW4tcmVtYW5pZW1lbnQtbWluaXN0ZXJpZWwtcXVlbC1wb2xpdGlxdWUtdm91cy1wYXJhaXQtbGUtcGx1cy1hLW1lbWUtZGUtcmVtcGxhY2VyLWRlcmljLWJlc3Nvbi1jb21tZS1zZWNyZXRhaXJlLWQlZTIlODAlOTlldGF0LWEtbCVlMiU4MCU5OWVjb25vbWllLW51bWVyaXF1ZS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkxvcnMgZHUgcHJvY2hhaW4gcmVtYW5pZW1lbnQgbWluaXN0ZXJpZWwsIHF1ZWwgcG9saXRpcXVlIHZvdXMgcGFyYWl0IGxlIHBsdXMgw6AgbcOqbWUgZGUgcmVtcGxhY2VyIEVyaWMgQmVzc29uLCBjb21tZSBzZWNyw6l0YWlyZSBk4oCZw6l0YXQgw6AgbOKAmcOpY29ub21pZSBudW3DqXJpcXVlPzwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2lscy1haW1lbnQtZnJlbmNod2ViLWZyLWV0LXZvdXMvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5JbHMgYWltZW50IEZyZW5jaHdlYi5mciBldCB2b3VzPzwvYT48L2xpPjwvdWw%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9pbmZvZ3JhcGhpZS1sZS1tYXJjaGUtZGVzLWFwcGxpY2F0aW9ucy1tb2JpbGVzLW11c2ljYWxlcy02MTEzMi9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoNCgkJPHNsYXNoOmNvbW1lbnRzPjE8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%W0VsZWN0aW9uIFByw6lzaWRlbnRpZWxsZV0gTW9uIGlkw6llIHBvdXIgMjAxMiAmIzgyMTE7IEVtbWFudWVsIFZpdmllcjwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZWxlY3Rpb24tcHJlc2lkZW50aWVsbGUtbW9uLWlkZWUtcG91ci0yMDEyLWVtbWFudWVsLXZpdmllci02MTEzMS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2VsZWN0aW9uLXByZXNpZGVudGllbGxlLW1vbi1pZGVlLXBvdXItMjAxMi1lbW1hbnVlbC12aXZpZXItNjExMzEvI2NvbW1lbnRzPC9jb21tZW50cz4NCg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDA3OjI1OjU5ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5NYXJpb24gTW9yZWF1PC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0ZyZW5jaFdlYl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtWaWRlb11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtFbW1hbnVlbCBWaXZpZXJdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbaWTDqWUgMjAxMl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt1bmVdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTQ2ODwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0lsIGZhdXQgdW4gU21hbGwgQWN0IGVuIEZyYW5jZSAhIEMnZXN0IGwnaWTDqWUgZMOpZmVuZHVlIHBhciBFbW1hbnVlbCBWaWNpZXIsIGFuY2llbiBjby0gZm9uZGF0ZXVyIGRlIGwnYWdlbmNlIFZhbmtzZW4sIGF1am91cmQnaHVpIGNvbnN1bHRhbnQgZW4gbWFya2V0aW5nIGRpZ2l0YWwuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%Q2hhcXVlIGpvdXIsIHVuIGFjdGV1ciBkdSBuZXQgbm91cyBsaXZyZSBzb24gaWTDqWUgcG91ciAyMDEyLCBwb3VyIGludGVycGVsbGVyIGxlcyBjYW5kaWRhdHMgw6AgbCYjODIxNzvDqWxlY3Rpb24gcHLDqXNpZGVudGllbGxlIHN1ciBsZXMgZW5qZXV4IGR1IG51bcOpcmlxdWUuIEF1am91cmQmIzgyMTc7aHVpLCBFbW1hbnVlbCBWaXZpZXIsIGFuY2llbiBjby0gZm9uZGF0ZXVyIGRlIGwmIzgyMTc7YWdlbmNlIDxhIGhyZWY9Imh0dHA6Ly93d3cudmFua3Nlbi5jb20vIiB0YXJnZXQ9Il9ibGFuayI%VmFua3NlbjwvYT4sIGF1am91cmQmIzgyMTc7aHVpIGNvbnN1bHRhbnQgZW4gbWFya2V0aW5nIGRpZ2l0YWwuPC9wPg0KPHA%PHN0cm9uZz5Sw6lhZ2lzc2V6IHN1ciBUd2l0dGVyIDogI0ZXMjAxMjwvc3Ryb25nPjwvcD4NCjxwPjxjZW50ZXI%PGlmcmFtZSBzcmM9Imh0dHA6Ly93d3cuZGFpbHltb3Rpb24uY29tL2VtYmVkL3ZpZGVvL2t6SUtndkYyaUdCNVN5MlY0djgiIGZyYW1lYm9yZGVyPSIwIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMwOSI%PC9pZnJhbWU%PC9jZW50ZXI%PC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItNjEwOTIvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRWxlY3Rpb24gUHLDqXNpZGVudGllbGxlXSBNb24gaWTDqWUgcG91ciAyMDEyICYjODIxMTsgUmVuYXVkIENoYW1waW9uIC8gUHJpbW5leHQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItYXJuYXVkLXBvaXNzb25uaWVyLWJhYnlsb2FuLTYxMDc5LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VsZWN0aW9uIFByw6lzaWRlbnRpZWxsZV0gTW9uIGlkw6llIHBvdXIgMjAxMiAmIzgyMTE7IEFybmF1ZCBQb2lzc29ubmllciAvIEJhYnlsb2FuPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZWxlY3Rpb24tcHJlc2lkZW50aWVsbGUtbW9uLWlkZWUtcG91ci0yMDEyLW1hcmMtdHJpbGxpbmctbG9naWNhLWJ1c2luZXNzLWNvbnN1bHRpbmctNjExMDgvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRWxlY3Rpb24gUHLDqXNpZGVudGllbGxlXSBNb24gaWTDqWUgcG91ciAyMDEyICYjODIxMTsgTWFyYyBUcmlsbGluZyAvIExvZ2ljYSBCdXNpbmVzcyBDb25zdWx0aW5nPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZWxlY3Rpb24tcHJlc2lkZW50aWVsbGUtbW9uLWlkZWUtcG91ci0yMDEyLW5pY29sYXMtZ2F1bWUtc25qdi02MTExNS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbGVjdGlvbiBQcsOpc2lkZW50aWVsbGVdIE1vbiBpZMOpZSBwb3VyIDIwMTIgJiM4MjExOyBOaWNvbGFzIEdhdW1lIC8gU05KVjwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VsZWN0aW9uLXByZXNpZGVudGllbGxlLW1vbi1pZGVlLXBvdXItMjAxMi1lbWVyeS1kb2xpZ2UtNTAyMDgvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRWxlY3Rpb24gUHLDqXNpZGVudGllbGxlXSBNb24gaWTDqWUgcG91ciAyMDEyICYjODIxMTsgRW1lcnkgRG9saWfDqTwvYT48L2xpPjwvdWw%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItZW1tYW51ZWwtdml2aWVyLTYxMTMxL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjA8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5bQ29mZnJldHMgY2FkZWF1eF0gWW91a2FkbyBib3VjbGUgdW5lIHByZW1pw6hyZSBsZXbDqWUgZGUgZm9uZHMgZGUgcHLDqHMgZGUgMSw1IG1pbGxpb24gZCYjODIxNztldXJvczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY29mZnJldHMtY2FkZWF1eC15b3VrYWRvLWJvdWNsZS11bmUtcHJlbWllcmUtbGV2ZWUtZGUtZm9uZHMtZGUtcHJlcy1kZS0xNS1taWxsaW9uLWV1cm9zLTYxMTMwLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY29mZnJldHMtY2FkZWF1eC15b3VrYWRvLWJvdWNsZS11bmUtcHJlbWllcmUtbGV2ZWUtZGUtZm9uZHMtZGUtcHJlcy1kZS0xNS1taWxsaW9uLWV1cm9zLTYxMTMwLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDc6MjQ6MDUgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQWN0dV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2J1c2luZXNzXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2VDb21tZXJjZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtCdG9CXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2NvZmZyZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbbGV2w6llXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3BlcnNvbm5hbGlzYXRpb25dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbWW91a2Fkb11dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NTA0PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbWW91a2FkbywgcGxhdGVmb3JtZSBkZSBjb2ZmcmV0cyBjYWRlYXV4IGVuIGxpZ25lLCB2aWVudCBkZSBmaW5hbGlzZXIgdW5lIGxldsOpZSBkZSBwcsOocyBkZSAxLDVNIOKCrCBhdXByw6hzIGTigJlpbnZlc3Rpc3NldXJzIHByb2Zlc3Npb25uZWxzLCBkb250IEZpbm9ycGEsIGV0IGTigJlpbnZlc3Rpc3NldXJzIHByaXbDqXMuDQoNCkZvbmTDqWUgZMOpYnV0IDIwMDkgcGFyIFBoaWxpcHBlIERlc3ByZXRzIGV0IFN0w6lwaGFuZSBGcmVteSwgbGEgc29jacOpdMOpIGEgZCYjODIxNzthYm9yZCBkw6l2ZWxvcHDDqSB1bmUgb2ZmcmUgZ3JhbmQgcHVibGljIGRlcHVpcyBzYSBwbGF0ZWZvcm1lIGVuIGxpZ25lLiBMYSBzb2Npw6l0w6kgcyYjODIxNztlc3QgZW5zdWl0ZSBjb25jZW50csOpZSBzdXIgdW4gc2VjdGV1ciBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly93d3cueW91a2Fkby5jb20vIiB0YXJnZXQ9Il9ibGFuayI%WW91a2Fkbyw8L2E%IHBsYXRlZm9ybWUgZGUgY29mZnJldHMgY2FkZWF1eCBlbiBsaWduZSwgdmllbnQgZGUgZmluYWxpc2VyIHVuZSBsZXbDqWUgZGUgcHLDqHMgZGUgMSw1TSDigqwgYXVwcsOocyBk4oCZaW52ZXN0aXNzZXVycyBwcm9mZXNzaW9ubmVscywgZG9udCA8YSBocmVmPSJodHRwOi8vd3d3LmZpbm9ycGEuZnIvIiB0YXJnZXQ9Il9ibGFuayI%Rmlub3JwYTwvYT4sIGV0IGTigJlpbnZlc3Rpc3NldXJzIHByaXbDqXMuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHA6Ly93d3cueW91a2Fkby5jb20vIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLW1lZGl1bSB3cC1pbWFnZS01NTUxMCIgdGl0bGU9InlvdWthZG8iIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy95b3VrYWRvLTU1MHgxNjgucG5nIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIxNjgiIC8%PC9hPjwvcD4NCjxwPkZvbmTDqWUgZMOpYnV0IDIwMDkgcGFyIFBoaWxpcHBlIERlc3ByZXRzIGV0IFN0w6lwaGFuZSBGcmVteSwgbGEgc29jacOpdMOpIGEgZCYjODIxNzthYm9yZCBkw6l2ZWxvcHDDqSB1bmUgb2ZmcmUgZ3JhbmQgcHVibGljIGRlcHVpcyBzYSBwbGF0ZWZvcm1lIGVuIGxpZ25lLiBMYSBzb2Npw6l0w6kgcyYjODIxNztlc3QgZW5zdWl0ZSBjb25jZW50csOpZSBzdXIgdW4gc2VjdGV1ciBCdG9CIGV0IGEgcmFwaWRlbWVudCA8c3BhbiBpZD0ibW9yZS01NTUwNCI%PC9zcGFuPmFmZmljaMOpIHVuZSBmb3J0ZSBww6luw6l0cmF0aW9uIHN1ciBsZSBtYXJjaMOpIGR1IGNhZGVhdSBk4oCZYWZmYWlyZXMuPC9wPg0KPHA%U29uIHN1Y2PDqHMgc3VyIGNlIHNlZ21lbnQgYSBkb25uw6kgbmFpc3NhbmNlIGVuIDIwMTEgw6AgbGEgY3LDqWF0aW9uIGRlIGRldXggcMO0bGVzIG9yZ2FuaXNhdGlvbm5lbHMgOiBZb3VrYWRvIEJ1c2luZXNzIFNvbHV0aW9ucywgY29uY2V2YW50IGRlcyBzb2x1dGlvbnMgY2FkZWF1eCBwb3VyIGxlIGNvbXB0ZSBkZSBtYXJxdWVzIGV0IGRlIGxpY2VuY2VzIGV0IFlvdWthZG8gcHJvLCBzcMOpY2lhbGlzdGUgZGUgbGEgc29sdXRpb24gY2FkZWF1IHBlcnNvbm5hbGlzw6llLCBkw6lkacOpZSDDoCBsYSBmb2lzIGF1eCDDqXbDqW5lbWVudHMgZGVzIGNvbWl0w6lzIGTigJllbnRyZXByaXNlcyBhaW5zaSBxdeKAmWF1eCBvcMOpcmF0aW9ucyBk4oCZaW5jZW50aXZlIGV0IGRlIHBhcnJhaW5hZ2UgcG91ciBsZXMgZW50cmVwcmlzZXMuPC9wPg0KPHA%TGEgbGV2w6llIGRlIGZvbmRzIGRvaXQgcGVybWV0dHJlIMOgIFlvdWthZG8gZCYjODIxNzthY2PDqWzDqXJlciBsZSBkw6l2ZWxvcHBlbWVudCBkZSBzZXMgYWN0aXZpdMOpcyBldCBkZSB0b3VjaGVyIGRlIG5vdXZlbGxlcyBtYXJxdWVzIGV0IGxpY2VuY2VzIGluZHVzdHJpZWxsZXMuPC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ncmFpbmUtZGUtY2FkZWF1eC1sZS1ub3V2ZWwtaW52ZXN0aXNzZW1lbnQtZGUta2ltYS12ZW50dXJlcy8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkdyYWluZSBkZSBDYWRlYXV4LCBsZSBub3V2ZWwgaW52ZXN0aXNzZW1lbnQgZGUgS2ltYSBWZW50dXJlczwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL25vdXZlbGxlLWxldmVlLWRlLWZvbmQtcG91ci1hdHRyYWN0aXZlLXdvcmxkLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%Tm91dmVsbGUgbGV2w6llIGRlIGZvbmQgcG91ciBBdHRyYWN0aXZlIFdvcmxkPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvYmlsbGV0dGVyaWUtZW4tbGlnbmUtd2VlemV2ZW50LWZpbmFsaXNlLXVuZS1wcmVtaWVyZS1sZXZlZS1kLTEtbWlsbGlvbi1ldXJvcy02MDA4OS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltCaWxsZXR0ZXJpZSBlbiBsaWduZV0gV2VlemV2ZW50IGZpbmFsaXNlIHVuZSBwcmVtacOocmUgbGV2w6llIGQmIzgyMTc7MSBtaWxsaW9uIGQmIzgyMTc7ZXVyb3M8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sZXZlZS1kZS1mb25kcy1kZS0xMS1taWxsaW9ucy1kZXVyb3MtcG91ci1sZS1ncm91cGUtZWRpbGl2cmUtaWtpb3NxdWUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MZXbDqWUgZGUgZm9uZHMgZGUgMSwxIG1pbGxpb24gZCYjODIxNztldXJvcyBwb3VyIGxlIGdyb3VwZSBFZGlsaXZyZS1pS2lvc3F1ZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V4Y2x1LWt3YWdhLWVkaXRldXItZGUtd3JpdGV0aGF0LW5hbWUtbGV2ZS0xMi1taWxsaW9uLWV1cm9zLTYwMDg4LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0V4Y2x1XSBLd2FnYSwgw6lkaXRldXIgZGUgV3JpdGVUaGF0Lm5hbWUgbMOodmUgMSwyIG1pbGxpb24gZOKAmWV1cm9zPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2NvZmZyZXRzLWNhZGVhdXgteW91a2Fkby1ib3VjbGUtdW5lLXByZW1pZXJlLWxldmVlLWRlLWZvbmRzLWRlLXByZXMtZGUtMTUtbWlsbGlvbi1ldXJvcy02MTEzMC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCg0KCQk8dGl0bGU%W05ld3NdIENlIHF1JiM4MjE3O2lsIGZhdXQgc2F2b2lyIGNlIG1hdGluPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9uZXdzLWNlLXF1ZWlsLWZhdXQtc2F2b2lyLWNlLW1hdGluLTYxMTI4LzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvbmV3cy1jZS1xdWVpbC1mYXV0LXNhdm9pci1jZS1tYXRpbi02MTEyOC8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDA3OjE1OjMxICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5HaWxsZXMgS2xlaW48L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtidXNpbmVzc11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVs0R11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtkbyBub3QgdHJhY2tdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbbGl2aW5nc29jaWFsXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01pbGxlbmlhbE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1JOVF1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NTE5PC9ndWlkPg0KDQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtTRlIgZMOpdm9pbGUgc2EgNEcsIFJJTS9CbGFja0JlcnJ5IGVuIHBlcnRlLCBsZXMgdGFibGV0dGVzIEdvb2dsZSBzZSBwcsOpY2lzZW50LCBiZWxsZSBlbnRyw6llIGVuIGJvdXJzZSBwb3VyIE1pbGxlbm5pYWwgTWVkaWEsIFdpRmkgZ3JhdHVpdCDDoCBCb3JkZWF1eCwgLCA2MCBoL3NlbWFpbmUgY2hleiBGb3hjb25uIHBvdXIgQXBwbGUsIFlhaG9vISB2YSBzZSBtYXR0cmUgYXUgRG8gTm90IFRyYWNrLCBhcnJpdsOpZSBpbW1pbmVudGUgZGUgbGEgUmFkaW8gTnVtw6lyaXF1ZSBUZXJyZXN0cmUuDQpEw6ltaXNzaW9uIGR1IHBhdHJvbiBkZSBMaXZpbmdTb2NpYWwNCkxlIGNvLWZvbmRhdGV1ciBldCBwYXRyb24gZGUgTGl2aW5nU29jaWFsIChncmFuZCByaXZhbCBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPlNGUiBkw6l2b2lsZSBzYSA0RywgUklNL0JsYWNrQmVycnkgZW4gcGVydGUsIGxlcyB0YWJsZXR0ZXMgR29vZ2xlIHNlIHByw6ljaXNlbnQsIGJlbGxlIGVudHLDqWUgZW4gYm91cnNlIHBvdXIgTWlsbGVubmlhbCBNZWRpYSwgV2lGaSBncmF0dWl0IMOgIEJvcmRlYXV4LCAsIDYwIGgvc2VtYWluZSBjaGV6IEZveGNvbm4gcG91ciBBcHBsZSwgWWFob28hIHZhIHNlIG1hdHRyZSBhdSBEbyBOb3QgVHJhY2ssIGFycml2w6llIGltbWluZW50ZSBkZSBsYSBSYWRpbyBOdW3DqXJpcXVlIFRlcnJlc3RyZS48L3A%DQo8aDI%RMOpbWlzc2lvbiBkdSBwYXRyb24gZGUgTGl2aW5nU29jaWFsPC9oMj4NCjxwPkxlIGNvLWZvbmRhdGV1ciBldCBwYXRyb24gZGUgPGEgaHJlZj0iaHR0cDovL3N1YnNjcmliZS5saXZpbmdzb2NpYWwuY29tL2NpdGllcy8xP3NraXBwYWJsZT0xJmFtcDtyZWY9YnJvYWRlcl9yb2FkYmxvY2siIHRhcmdldD0iX2JsYW5rIj5MaXZpbmdTb2NpYWw8L2E%IChncmFuZCByaXZhbCBkZSBHcm91cG9uLCBkb250IEFtYXpvbiBwb3Nzw6hkZSAzMCUpLCA8YSBocmVmPSJodHRwOi8vdGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOS9saXZpbmdzb2NpYWwtY29mb3VuZGVyLXN0ZXBzLWRvd24vIiB0YXJnZXQ9Il9ibGFuayI%RWRkaWUgRnJlZGVyaWNrLCBkw6ltaXNzaW9ubmUgZGUgc29uIHBvc3RlPC9hPiwgw6AgbGEgdmVpbGxlIGQmIzgyMTc7dW5lIHByb2NoYWluZSBpbnRyb2R1Y3Rpb24gZW4gYm91cnNlLCBub24gY29uZmlybcOpZSBwb3VyIGwmIzgyMTc7aW5zdGFudC48L3A%DQo8aHIgLz4NCjxoMj5TRlIgYW5ub25jZSBzYSA0RzwvaDI%DQo8cD48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1MzciIHRpdGxlPSJTRlItNEciIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9TRlItNEcucG5nIiBhbHQ9IiIgd2lkdGg9IjQ0MiIgaGVpZ2h0PSIxODAiIC8%PC9wPg0KPHA%JmxhcXVvOyZuYnNwO0wmIzgyMTc7b3DDqXJhdGV1ciBTRlIsIHF1aSBtw6huZSBkZXB1aXMgc2VwdGVtYnJlIHVuIHByb2pldCBwaWxvdGUgZGUgdMOpbMOpcGhvbmllIDRHIMOgIE1hcnNlaWxsZSwgYSBhbm5vbmPDqSBqZXVkaSBxdSYjODIxNztpbCBhbGxhaXQgZMOpcGxveWVyIGVuIDIwMTIgbGEgNEcgZGFuczxzcGFuIGlkPSJtb3JlLTU1NTE5Ij48L3NwYW4%IHBsdXNpZXVycyBhdXRyZXMgdmlsbGVzLCBkb250IEx5b24gZXQgTW9udHBlbGxpZXIsIHBvdXIgdW5lIGNvbW1lcmNpYWxpc2F0aW9uIGR1IHNlcnZpY2UgZMOpYnV0IDIwMTMuJm5ic3A7JnJhcXVvOyA8YSBocmVmPSJodHRwOi8vd3d3LmxlcGFyaXNpZW4uZnIvbWFyc2VpbGxlLTEzMDAwL3Nmci1wcmV2b2l0LXVuZS1jb21tZXJjaWFsaXNhdGlvbi1kZS1zb24tb2ZmcmUtNGctZGVidXQtMjAxMy0yOS0wMy0yMDEyLTE5Mjk4OTYucGhwIiB0YXJnZXQ9Il9ibGFuayI%bm90ZSBMZSBQYXJpc2llbjwvYT4gJmxhcXVvOyZuYnNwO0xlcyBvcMOpcmF0ZXVycyBtb2JpbGUgQm91eWd1ZXMgVGVsZWNvbSBldCBPcmFuZ2Ugb250IGV1eCBhdXNzaSBhbm5vbmPDqSBpbCB5IGEgdW5lIHNlbWFpbmUgbGUgbGFuY2VtZW50IGRlIGxhIHByZW1pw6hyZSDDqXRhcGUgZHUgZMOpcGxvaWVtZW50IGRlIGxldXIgcsOpc2VhdSA0RywgcG91ciBsJiM4MjE3O3VuIMOgIEx5b24gZXQgbCYjODIxNzthdXRyZSDDoCBNYXJzZWlsbGUsIGF2ZWMgcG91ciBvYmplY3RpZiB1biBkw6lwbG9pZW1lbnQgY29tbWVyY2lhbCBkw6lidXQgMjAxMy4mbmJzcDsmcmFxdW87PC9wPg0KPGhyIC8%DQo8L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL25ld3MtY2UtcXVlaWwtZmF1dC1zYXZvaXItY2UtbWF0aW4tNjExMjgvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgk8L2NoYW5uZWw%DQo8L3Jzcz4NCg0KPCEtLSBEeW5hbWljIHBhZ2UgZ2VuZXJhdGVkIGluIDEwLjc3MiBzZWNvbmRzLiAtLT4NCg0KPCEtLSBDYWNoZWQgcGFnZSBnZW5lcmF0ZWQgYnkgV1AtU3VwZXItQ2FjaGUgb24gMjAxMi0wMy0zMCAxNzowMjoyNSAtLT4NCg"},{ name : "feed2", data : "s56454:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPlRlY2hDcnVuY2ggRnJhbmNlPC90aXRsZT4NCgk8YXRvbTpsaW5rIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS9mZWVkLyIgcmVsPSJzZWxmIiB0eXBlPSJhcHBsaWNhdGlvbi9yc3MreG1sIiAvPg0KCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbTwvbGluaz4NCgk8ZGVzY3JpcHRpb24%SnVzdCBhbm90aGVyIFdvcmRQcmVzcyBzaXRlPC9kZXNjcmlwdGlvbj4NCgk8bGFzdEJ1aWxkRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE0OjM3OjE3ICswMDAwPC9sYXN0QnVpbGREYXRlPg0KDQoJPGxhbmd1YWdlPmVuPC9sYW5ndWFnZT4NCgk8c3k6dXBkYXRlUGVyaW9kPmhvdXJseTwvc3k6dXBkYXRlUGVyaW9kPg0KCTxzeTp1cGRhdGVGcmVxdWVuY3k%MTwvc3k6dXBkYXRlRnJlcXVlbmN5Pg0KCTxnZW5lcmF0b3I%aHR0cDovL3dvcmRwcmVzcy5vcmcvP3Y9My4wPC9nZW5lcmF0b3I%DQoJCTxpdGVtPg0KCQk8dGl0bGU%UXVhbmQgbGVzIGZyw6hyZXMgU2Ftd2VyIHBhcnRlbnQgZW4gZ3VlcnJlJiM4MjMwOzwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L3F1YW5kLWxlcy1mcmVyZXMtc2Ftd2VyLXBhcnRlbnQtZW4tZ3VlcnJlLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L3F1YW5kLWxlcy1mcmVyZXMtc2Ftd2VyLXBhcnRlbnQtZW4tZ3VlcnJlLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPldlZCwgMjggTWFyIDIwMTIgMTY6MzM6MjQgKzAwMDA8L3B1YkRhdGU%DQoNCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYmxpZXR6a3JpZWddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZ3VlcnJlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3NhbXdlcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4Mzg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQiIHRpdGxlPSJyb2NrZXQgaW50ZXJuZXQiIHNyYz0iaHR0cDovL3d3dy5qb2JzcGlub3kuY29tL3VwbG9hZF9maWxlcy9pbWFnZXMvNy9jLzUvN2M1ZjkzZjcwYzQ4NWExMzgxYmI5YzMxMjIzYjA4ZDkuanBnIiBhbHQ9IiIgd2lkdGg9IjM2MCIgaGVpZ2h0PSI5MCIgLz4NClRyYWR1Y3Rpb24gZXQgYWRhcHRhdGlvbiBkJ3VuIDxhIGhyZWY9Imh0dHA6Ly90ZWNoY3J1bmNoLmNvbS8yMDExLzEyLzIyL2luLWNvbmZpZGVudGlhbC1lbWFpbC1zYW13ZXItZGVzY3JpYmVzLW9ubGluZS1mdXJuaXR1cmUtc3RyYXRlZ3ktYXMtYS1ibGl0emtyaWVnLyAgIj5hcnRpY2xlIDwvYT5kZSBNaWtlIEJ1dGNoZXIuDQoNClJvY2tldCBJbnRlcm5ldCwgbGUgZm9uZHMgZGVzIGZyw6hyZXMgU2Ftd2VyLCB2aWVudCBkZSBzZSBsYW5jZXIgZW4gRnJhbmNlLCBldCBjZXJ0YWlucyB2b250IGNlcnRhaW5lbWVudCBlbiBmYWlyZSBsZXMgZnJhaXMuIFBvdXIgdm91cyBlbiBkb25uZXIgdW4gYXBlcsOndSwgdm9pY2kgbGEgdHJhZHVjdGlvbiBkJ3VuIGUtbWFpbCBjb25maWRlbnRpZWwgZW52b3nDqSBwYXIgT2xpdmVyIFNhbXdlciDDoCBzZXMgw6lxdWlwZXMsIGRhbnMgbGVxdWVsIGlsIHV0aWxpc2UgbGUgbW90IMKrIEJsaXR6a3JpZWcgwrsgcG91ciBkw6ljcmlyZSBzYSBzdHJhdMOpZ2llIGRlIHZlbnRlIGRlIG1ldWJsZXMgZW4gbGlnbmUuDQpdXT48L2Rlc2NyaXB0aW9uPg0KDQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9InJvY2tldCBpbnRlcm5ldCIgc3JjPSJodHRwOi8vd3d3LmpvYnNwaW5veS5jb20vdXBsb2FkX2ZpbGVzL2ltYWdlcy83L2MvNS83YzVmOTNmNzBjNDg1YTEzODFiYjljMzEyMjNiMDhkOS5qcGciIGFsdD0iIiB3aWR0aD0iMzYwIiBoZWlnaHQ9IjkwIiAvPjxiciAvPg0KVHJhZHVjdGlvbiBldCBhZGFwdGF0aW9uIGQmIzgyMTc7dW4gPGEgaHJlZj0iaHR0cDovL3RlY2hjcnVuY2guY29tLzIwMTEvMTIvMjIvaW4tY29uZmlkZW50aWFsLWVtYWlsLXNhbXdlci1kZXNjcmliZXMtb25saW5lLWZ1cm5pdHVyZS1zdHJhdGVneS1hcy1hLWJsaXR6a3JpZWcvICAiPmFydGljbGUgPC9hPmRlIE1pa2UgQnV0Y2hlci48L3A%DQo8cD5Sb2NrZXQgSW50ZXJuZXQsIGxlIGZvbmRzIGRlcyBmcsOocmVzIFNhbXdlciwgdmllbnQgZGUgc2UgbGFuY2VyIGVuIEZyYW5jZSwgZXQgY2VydGFpbnMgdm9udCBjZXJ0YWluZW1lbnQgZW4gZmFpcmUgbGVzIGZyYWlzLiBQb3VyIHZvdXMgZW4gZG9ubmVyIHVuIGFwZXLDp3UsIHZvaWNpIGxhIHRyYWR1Y3Rpb24gZCYjODIxNzt1biBlLW1haWwgY29uZmlkZW50aWVsIGVudm95w6kgcGFyIE9saXZlciBTYW13ZXIgw6Agc2VzIMOpcXVpcGVzLCBkYW5zIGxlcXVlbCBpbCB1dGlsaXNlIGxlIG1vdCDCqyBCbGl0emtyaWVnIMK7IHBvdXIgZMOpY3JpcmUgc2Egc3RyYXTDqWdpZSBkZSB2ZW50ZSBkZSBtZXVibGVzIGVuIGxpZ25lLjwvcD4NCjxwPlJvY2tldCBpbnRlcm5ldCwgbOKAmWluY3ViYXRldXIgYmVybGlub2lzIGNvbm51IHBvdXIgbGVzIHZlcnNpb25zIGFsbGVtYW5kZXMgZGUgc3RhcnR1cHMgYW3DqXJpY2FpbmVzIGNvbW1lIFphcHBvcyBldCBHcm91cG9uLCBhIG1haW50ZW5hbnQgZGUgZ3JhbmRlcyBhbWJpdGlvbnMsIHN1cnRvdXQgZGFucyBsZSBzZWN0ZXVyIGR1IG1ldWJsZSBlbiBsaWduZSwgc2Vsb24gZGVzIGluZm9ybWF0aW9ucyBkb25uw6llcyDDoCBUZWNoQ3J1bmNoIEV1cm9wZS48L3A%DQo8cD5EYW5zIHVuIGUtbWFpbCBjb25maWRlbnRpZWwgZW52b3nDqSBwYXIgT2xpdmVyIFNhbXdlciAocXVpIGRpcmlnZSBsZSBmb25kcyBhdmVjIHNlcyBmcsOocmVzIE1hcmMgZXQgQWxleGFuZGVyKSwgaWwgZMOpY2xhcmUgcXVlIGxldXIgc3RyYXTDqWdpZSBlc3QgZGUgZGV2ZW5pciBsZSDCqyBudW3DqXJvIHVuIMK7IGR1IGUtY29tbWVyY2UgZGUgbWV1YmxlcyBkYW5zIGxlcyBwcm9jaGFpbmVzIGFubsOpZXMuIE1haXMgbGUgbGFuZ2FnZSB1dGlsaXPDqSBjb21tZSBsZSBtb3QgwqtibGl0emtyaWVnwrsgbW9udHJlIHVuIHR5cGUgZGUgbWFuYWdlbWVudCB0csOocyBhZ3Jlc3NpZiwgcXVpIG5lIGxhaXNzZSBhdWN1bmUgcGxhY2UgYXV4IHNlbnRpbWVudHMsIGV0IHF1aSBhcHBhcmHDrnQgY29tbWUgw6l0YW50IHVuIOKAmW1vZHVzIG9wZXJhbmRp4oCZIGRlIGxhIGN1bHR1cmUgZGUgUm9ja2V0IChsZSBub20gbiYjODIxNzthIGQmIzgyMTc7YWlsbGV1cnMgcGFzIMOpdMOpIGNob2lzaSBwYXIgaGFzYXJkKS4gU2Ftd2VyIHPigJllc3QgZGVwdWlzIGV4Y3Vzw6kgZOKAmWF2b2lyIHV0aWxpc8OpIGNlcyB0ZXJtZXMuPC9wPg0KPHA%RGFucyBs4oCZZS1tYWlsLCDDqWNyaXQgZGFucyB1biBhbmdsYWlzIGjDqXNpdGFudCwgT2xpdmVyIFNhbXdlciBkaXQgw6Agc29uIMOpcXVpcGUgY2hleiBSb2NrZXQgcXXigJlpbCB5IGEgc2V1bGVtZW50IDMgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIHBvdXIgY3LDqWVyIHVuZSBlbnRyZXByaXNlIGRlIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzIDo8L3A%DQo8cD4mIzgyMjE7IDxlbT5O4oCZb3VibGlleiBqYW1haXMgcXXigJlpbCBu4oCZeSBhIHF1ZSBkZXV4IGdyb3Mgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIDogQW1hem9uIGV0IFphcHBvcy4gQ%KAmWVzdCBsYSBkZXJuacOocmUgY2hhbmNlIGRlIHZvdHJlIHZpZSA6IGxhIGNoYW5jZSBwb3VyIHVuZSBhdXRyZSBlbnRyZXByaXNlIGRlIGUtY29tbWVyY2UgZGUgdmFsb2lyIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzLCB1bmUgY2hhbmNlIHF1aSBuZSBzZSByZXByw6lzZW50ZXJhIHBsdXMgITxiciAvPg0KQ%KAmWVzdCB0ZXJtaW7DqSwgYXByw6hzIEFtYXpvbiBpbCBuJiM4MjE3O3kgYSBxdWUgWmFwcG9zLCBkb25jIG9uIG5lIHBldXQgcGFzIHJhdGVyIGNldHRlIG9jY2FzaW9uLCBzaW5vbiB2b3MgcGV0aXRzLWVuZmFudHMgdm91cyBkZW1hbmRlcm9udCB0b3V0ZSB2b3RyZSB2aWUgcG91cnF1b2kgdm91cyBuZSBsJiM4MjE3O2F2ZXogcGFzIGZhaXQgPC9lbT7Cuy48L3A%DQo8cD5BaW5zaSwgaWwgZGl0IMOgIHNvbiDDqXF1aXBlIDogwqsgPGVtPlZvdXMgZGV2ZXogdG91dCBhbnRpY2lwZXI8L2VtPjxlbT4gZGFucyB2b3RyZSBwbGFuIHBvdXIgcXXigJlpbCBu4oCZeSBhaXQgcGFzIGRlIHN1cnByaXNlLiBKZSBu4oCZYWNjZXB0ZSBwYXMgbGVzIHN1cnByaXNlcy4gSmUgdmV1eCBxdWUgdG91dCBzb2l0IHZhbGlkw6kgZXQgdsOpcmlmacOpIDwvZW0%PGVtPnBhciB2b3VzIHRyb2lzIGZvaXM6IHZvdXMgZGV2ZXogbGUgc2lnbmVyIGF2ZWMgdm90cmUgc2FuZzwvZW0%LiDCuywgZXQgYWpvdXRlIDogwqs8ZW0%IEplIG5lIGZlcmFpIHF14oCZdW4gcGxhbiBhdXF1ZWwgdm91cyBjcm9pcmV6IMOgIDEwMCUgZXQgcXVpIHNlcmEgc2lnbsOpIGF2ZWMgZHUgc2FuZzwvZW0%wrsuPC9wPg0KPHA%SWwgcHLDqWNpc2Ugw6lnYWxlbWVudCBxdWUgY2VydGFpbnMgbWFuYWdlcnMgcXXigJlpbCBlbXBsb3lhaXQgZXQgcXVpIG7igJlvbnQgcGFzIGZhaXQgdG91dCBjZWxhLCBsdWkgb250IGZhaXJlIHBlcmRyZSDCqyBiZWF1Y291cCBk4oCZYXJnZW50IMK7IGV0IHF1ZSDCqyBjZXMgbWFuYWdlcnMgb250IHBlcmR1IDUwJSBkZSBsZXVyIGNhcGl0YWwgwrsgZXQgbuKAmW9udCDCqyBwYXMgZXUgZGUgc2FsYWlyZSBwZW5kYW50IDYgbW9pcy4gwrs8L3A%DQo8cD5MJiM4MjE3O2UtbWFpbCBwcmVuZCB1biB0b24gcGx1cyBjb250cm92ZXJzw6ksIHN1cnRvdXQgcG91ciB1biBidXNpbmVzc21hbiBjb21tZSBsdWksIGxvcnNxdSYjODIxNztpbCB1dGlsaXNlIGxlIGxhbmdhZ2UgZGUgbGEgc2Vjb25kZSBndWVycmUgbW9uZGlhbGUgOiDCqyA8ZW0%TGEgY2hvc2Ugw6AgbGFxdWVsbGUgbm91cyBkZXZvbnMgZmFpcmUgbGUgcGx1cyBhdHRlbnRpb24sIGMmIzgyMTc7ZXN0IHF1ZSBub3VzIGRldm9ucyBiaWVuIGNob2lzaXIgbGUgbW9tZW50IHBvdXIgbGEgQmxpdHprcmllZywgYWZpbiBxdWUgY2hhcXVlIHBheXMgbWUgZGlzZSBhdmVjIHNvbiBzYW5nIHF1YW5kIGPigJllc3QgbGUgYm9uIG1vbWVudC4gSmUgc2VyYWkgcHLDqnQg4oCTIG7igJlpbXBvcnRlIHF1YW5kICE8L2VtPiDCuzwvcD4NCjxwPsKrIEJsaXR6a3JpZWcgwrsgw6l0YWl0IGJpZW4gw6l2aWRlbW1lbnQgdW4gdGVybWUgdXRpbGlzw6kgcGFyIGxlcyBtaWxpdGFpcmVzIGFsbGVtYW5kcyBwb3VyIGTDqWNyaXJlIGxldXIgdGFjdGlxdWUgZGUgZMOpcGxhY2VtZW50IHJhcGlkZSwgc29pdCB1bmUgwqsgR3VlcnJlIMOpY2xhaXIgwrsuIExhIHNvdXJjZSBiaWVuIHBsYWPDqWUgcXVpIG5vdXMgYSBmYWl0IHN1aXZyZSBjZXQgZS1tYWlsIG5vdXMgZGl0IDogwqsgU2FtdWVsIGVzdCBjb25udSBwb3VyIHV0aWxpc2VyIGRlcyB0ZXJtZXMgbWlsaXRhaXJlcywgYXV0YW50IHF1ZSBkZSBub21icmV1eCB0ZXJtZXMgZGUgbGFuZ2FnZSBvYnNjw6huZXMsIGFsb3JzIGNlIGdlbnJlIGRlIOKAmG1vdGl2YXRpb27igJkgZXN0IGFzc3Vyw6ltZW50IGxlIOKAmHN0eWxlIGTigJlPbGxpIFNhbXdlcuKAmS4gSmUgbmUgY29ubmFpcyBwYXMgdW4gc2V1bCBhdXRyZSBidXNpbmVzc21hbiB1dGlsaXNhbnQgdW4gdGVsIGxhbmdhZ2UgwrsuPC9wPg0KPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0ic2Ftd2VyIiBzcmM9Imh0dHA6Ly93d3cuY3J1bmNoYmFzZS5jb20vYXNzZXRzL2ltYWdlcy9yZXNpemVkLzAwMDYvMjEzNy82MjEzN3YxLW1heC0yNTB4MjUwLmpwZyIgYWx0PSIiIHdpZHRoPSIyNTAiIGhlaWdodD0iMTA1IiAvPjwvcD4NCjxwPjxzdHJvbmc%UsOpc3Vtw6kgZGUgbCYjODIxNztlLW1haWwgPC9zdHJvbmc%OiAmIzgyMjA7PGVtPkplIHZvdXMgZG9ubmUgdG91dCBs4oCZYXJnZW50IGRvbnQgdm91cyBhdXJleiBiZXNvaW4gcG91ciBnYWduZXIsIGplIHZvdXMgZG9ubmUgdG91dGUgbWEgY29uZmlhbmNlLCBtYWlzIHZvdXMgZGV2ZXogcmV2ZW5pciB2ZXJzIG1vaSBhdmVjIHVuIHN1Y2PDqHMgaW7DqWdhbMOpLiBTaSBqZSB2b2lzIHF1ZSB2b3VzIGdhc3BpbGxleiBtb24gYXJnZW50LCBxdWUgdm91cyBu4oCZw6p0ZXMgcGFzIGNvbmNlbnRyw6lzIHN1ciBsZSBkw6l0YWlsIGNvbW1lIHVuIGFsbGVtYW5kLCBxdWUgdm91cyBu4oCZw6p0ZXMgcGFzIHJhcGlkZXMsIHF1ZSB2b3VzIG7igJnDqnRlcyBwYXMgYWdyZXNzaWZzLCBxdWUgdm91cyBuZSBzdWl2ZXogcGFzIGxlcyBpbmZvcm1hdGlvbnMsIHF1ZSB2b3VzIG7igJllZmZlY3R1ZXogcGFzIGxhIGxvZ2lzdGlxdWUgZGUgbGEgYm9ubmUgZmHDp29uLCBxdWUgdm91cyBuZSBtZXR0ZXogcGFzIHJhcGlkZW1lbnQgZW4gbGlnbmUgbGVzIHByb2R1aXRzLCBvdSBxdWUgdm91cyBhY2hldGV6IGRlIG1hdXZhaXNlcyBtYXJjaGFuZGlzZXMsIGFsb3JzIGplIG1lIG1ldHRyYWlzIGVuIGNvbMOocmUgZXQgamUgZmVyYWlzIGNvbW1lIGVuIFJ1c3NpZSwgb8O5IGFjdHVlbGxlbWVudCBhdWN1biBkZXMgbWFuYWdlcnMgbmUgZGlyaWdlIGwmIzgyMTc7ZW50cmVwcmlzZS4gSuKAmWFpIHBlcmR1IGJlYXVjb3VwIGTigJlhcmdlbnQgZXQgbGVzIGZvbmRhdGV1cnMgb250IHBlcmR1IDUwJSBkZSBsZXVyIGNhcGl0YWwuIEF1Y3VuIHNhbGFpcmUgbuKAmWEgcGx1cyDDqXTDqSB2ZXJzw6kgcGVuZGFudCA2IG1vaXMuIE5vdXMgc29tbWVzIGRhbnMgbGUgbcOqbWUgYmF0ZWF1LCB0b3V0IGxlIG1vbmRlIGRvaXQgZWZmZWN0dWVyIHNhIG1pc3Npb24uPC9lbT48L3A%DQo8cD48ZW0%Tm91cyBhcnJpdm9ucyB0YXJkLCBhbG9ycyBub3VzIGF2b25zIGJlc29pbiBk4oCZw6p0cmUgbGVzIHBsdXMgYWdyZXNzaWZzLiBUZWxsZW1lbnQgYWdyZXNzaWZzIHF1ZSBjaGFxdWUgY29uY3VycmVudCBzZXJhIHN1cnByaXMgcGFyY2UgcXXigJlpbCBuZSBwb3V2YWl0ICBpbWFnaW5lciBxdWUgbm91cyBzZXJpb25zIHNpIGFncmVzc2lmcy4gUG91ciB2b3VzIGRvbm5lciB1biBleGVtcGxlIGF1IEJyw6lzaWwgYXZlYyBHcm91cG9uIDogbW9uIGNvbmN1cnJlbnQgcsOpYWxpc2FpdCB0cm9pcyBtaWxsaW9ucyBwYXIgbW9pcyBldCBhdmFpdCA4MCB2ZW5kZXVycy4gIErigJlhaSBzdXBwb3PDqSBxdeKAmWVuIDQgbW9pcyBpbCBpcmFpdCBqdXNxdeKAmcOgIDMwMCB2ZW5kZXVycyBldCA2IG1pbGxpb25zLCBhbG9ycyBq4oCZYWkgZGl0IMOgIGzigJnDqXF1aXBlIGRlIHByZW5kcmUgNTAwIHZlbmRldXJzIGVuIDQgbW9pcywgZXQgMTAgbWlsbGlvbnMgZGUgY2hpZmZyZSBkJiM4MjE3O2FmZmFpcmVzIGVuIG9udCBkw6ljb3Vsw6lzLiBOb3VzIGF2b25zIGdhZ27DqS4gT3VpLCBpbCB5IGEgZXUgZGVzIGRvbW1hZ2VzIGNvbGxhdMOpcmF1eCAoY2VsYSBhdXJhaXQgw6l0w6kgbW9pbnMgY2hlciBhdmVjIHBsdXMgZGUgdGVtcHMpLCBtYWlzIGrigJlhaSBnYWduw6kgZXQgY%KAmWVzdCB0b3V0IGNlIHF1aSBjb21wdGUuIEomIzgyMTc7YWkgYWxvcnMgcHUgcsOpY29sdGVyIGRlIGzigJlhcmdlbnQgZXQgb3B0aW1pc2VyIGxlcyBsYWN1bmVzLjwvZW0%PC9wPg0KPHA%PGVtPkZvdXJuaXNzZXogdW4gcGxhbiBwb3VyIGNlIHdlZWstZW5kIHF1aSBjb21wcmVuZCB0b3V0ZXMgdm9zIHJlY29tbWFuZGF0aW9ucywgcGVuc2V6IHkgcGFyY2UgcXVlIGplIHBldXggdm91cyBkb25uZXIgbOKAmWFyZ2VudCwgbGUgc2F2b2lyLWZhaXJlLCBsYSBzdHJhdMOpZ2llLCBtYWlzIGplIG5lIGZlcmFpIHF14oCZdW4gcGxhbiBhdXF1ZWwgdm91cyBjcm9pcmV6IMOgIDEwMCUgZXQgcXVpIHNlcmEgc2lnbsOpIGF2ZWMgZHUgc2FuZy4gQ2UgbuKAmWVzdCBwYXMgbGUgcGxhbiBkJiM4MjE3O09saSwgw6dhIGRvaXQgw6p0cmUgdm90cmUgcGxhbiwgbm90cmUgcGxhbi48L2VtPjwvcD4NCjxwPjxlbT5O4oCZb3VibGlleiBqYW1haXMgcXXigJlpbCBu4oCZeSBhIHF1ZSBkZXV4IGdyb3Mgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIDogQW1hem9uIGV0IFphcHBvcy4gQ%KAmWVzdCBsYSBkZXJuacOocmUgY2hhbmNlIGRlIHZvdHJlIHZpZSA6IGxhIGNoYW5jZSBwb3VyIHVuZSBhdXRyZSBlbnRyZXByaXNlIGRlIGUtY29tbWVyY2UgZGUgdmFsb2lyIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzLCB1bmUgY2hhbmNlIHF1aSBuZSBzZSByZXByw6lzZW50ZXJhIHBsdXMgISBD4oCZZXN0IHRlcm1pbsOpLCBhcHLDqHMgQW1hem9uIHZpZW50IHNldWxlbWVudCBaYXBwb3MsIGRvbmMgb24gbmUgcGV1dCBwYXMgcmF0ZXIgw6dhLiBQYXJjZSBxdWUgc2lub24gdm9zIHBldGl0cy1lbmZhbnRzIHZvdXMgZGVtYW5kZXJvbnQgdG91dGUgdm90cmUgdmllIHBvdXJxdW9pIHZvdXMgbmUgbCYjODIxNzthdmV6IHBhcyBmYWl0LiA8L2VtPjwvcD4NCjxwPjxlbT5TdXJwcmVuZXotbW9pIGF2ZWMgdm90cmUgYWdyZXNzaXZpdMOpLCBzb3lleiBpbnRlbGxpZ2VudHMgZXQgcGVuc2V6ICBkZSBtYW5pw6hyZSBhZ3Jlc3NpdmUg4oCTIGFwcHJlbmV6IGRlcyBlcnJldXJzIGRlcyBydXNzZXMgZXQgZGVzIGphcG9uYWlzLCBldCBkdSBzdWNjw6hzIGRlcyBhbGxlbWFuZHMgZXQgZGVzIGJyw6lzaWxpZW5zICE8L2VtPjwvcD4NCjxwPjxlbT5D4oCZZXN0IG5vdHJlIGRlcm5pw6hyZSBjaGFuY2UgZGFucyBsZSBlLWNvbW1lcmNlIGRlIGNvbnN0cnVpcmUgdW5lIGVudHJlcHJpc2UgY29tbWUgQW1hem9uLiBBcHLDqHMgbm91cywgdm91cyBwb3VycmV6IG1vbnRlciB1bmUgZW50cmVwcmlzZSBkZSBqZXV4IGVuIGxpZ25lLCBtYWlzIHBsdXMgcmllbiBlbiBlLWNvbW1lcmNlLiBD4oCZZXN0IGxhIERFUk5JRVJFIG9jY2FzaW9uIGRhbnMgdm90cmUgdmllIHBvdXIgdm91cyBsYW5jZXIgZGFucyBsZSBlLWNvbW1lcmNlIGV0IGplIHZldXggcXVlIHZvdXMgbWlzaWV6IHRvdXQgc3VyIGNldHRlIG9wcG9ydHVuaXTDqS4gUGFzIGF2ZWMgMjAlIG91IDMwJSwgbWFpcyBhdmVjIDgwJSBkZSBwYXJ0cyBkZSBtYXJjaMOpLCBjJiM4MjE3O2VzdCBwb3NzaWJsZSBkYW5zIG5vcyBwYXlzITwvZW0%PC9wPg0KPHA%PGVtPkplIHN1aXMgbGUgbWVjIGxlIHBsdXMgYWdyZXNzaWYgZCYjODIxNztpbnRlcm5ldCBzdXIgbGEgcGxhbsOodGUuIEplIG1vdXJyYWkgcG91ciBnYWduZXIgZXQgauKAmWVuIGF0dGVuZHMgZGUgbcOqbWUgZGUgdm90cmUgcGFydCAhJiM4MjIxOzwvZW0%PC9wPg0KPHA%JiM4MjExOzwvcD4NCjxwPklsIGVzdCBjbGFpciBxdWUgZGFucyBsZSBkb21haW5lIGRlcyBlbnRyZXByaXNlcyDDoCBmb3J0ZSBjcm9pc3NhbmNlIHN1ciBpbnRlcm5ldCwgbGVzIGluZGl2aWR1cyBwZXV2ZW50IHBhcmZvaXMgw6p0cmUgc3VyZXhjaXTDqXMgZXQgYWxsZXIgdHJvcCBsb2luLiBJY2ksIGxlIGxhbmdhZ2UgdXRpbGlzw6kgbWFucXVlIGNydWVsbGVtZW50IGRlIHRhY3QsIGPigJllc3QgdW4gZXVwaMOpbWlzbWUuIENvbnRhY3TDqSBwYXIgVGVjaENydW5jaCBFdXJvcGUgw6AgcHJvcG9zIGRlIGzigJllLW1haWwsIE9saXZlciBTYW13ZXIgYSBjb25maXJtw6kgcXXigJlpbCDDqXRhaXQgYmllbiBkZSBsdWksIGV0IGEgcsOpcG9uZHUgcGFyIGNldHRlIGTDqWNsYXJhdGlvbiA6PC9wPg0KPHA%wqsgPGVtPjxlbT5D4oCZw6l0YWl0IHVuIGUtbWFpbCBxdWUgauKAmWFpIGVudm95w6kgYXV4IG1lbWJyZSBk4oCZdW4gcHJvamV0IGTigJnDqXF1aXBlIGVuIG9jdG9icmUuIEF1IG1pbGlldSBkZSBtb24gZW50aG91c2lhc21lIGV0IGRlcyBpZMOpZXMgZGUgZMOpcGxvaWVtZW50IHJhcGlkZSwgauKAmWFpIHV0aWxpc8OpIGxlIHRlcm1lIHRvdGFsZW1lbnQgaW5hcHByb3ByacOpIGRlICYjODIyMDtCbGl0emtyaWVnJiM4MjIxOy4gSmUgc3VpcyBwcm9mb25kw6ltZW50IGTDqXNvbMOpIHBvdXIgY2VsYS4gSmUgbeKAmWV4Y3VzZSBhdXByw6hzIGRlIGNldXggcXVpIG9udCBwdSDDqnRyZSBvZmZlbnPDqXMgcGFyIGNlIG1vdCwgZXQgbGUgdG9uIGfDqW7DqXJhbCBkZSBs4oCZZW1haWwuIENlIG7igJnDqXRhaXQgcGFzIGRhbnMgbW9uIGludGVudGlvbiBkZSBibGVzc2VyIHF1ZWxxdeKAmXVuLiBK4oCZZW52b2llIGxlIG3Dqm1lIGUtbWFpbCBk4oCZZXhjdXNlcyBhdXggZGVzdGluYXRhaXJlcyBk4oCZb3JpZ2luZSBkZSBjZXQgZS1tYWlsLiBKZSBzYWlzIHF1ZSBq4oCZYWkgZXUgdG9ydCBldCBqZSBuZSBtZSBzZXJhaSBqYW1haXMgbW9pLW3Dqm1lIGV4cHJpbcOpIGRlIGNldHRlIGZhw6dvbjwvZW0%PC9lbT4uIMK7PC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvcXVhbmQtbGVzLWZyZXJlcy1zYW13ZXItcGFydGVudC1lbi1ndWVycmUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%Njwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bRXhjbHVdIE15RVJQLmNvbSBsYW5jZSB1bmUgdmVyc2lvbiBkZSBzb24gYXBwbGljYXRpb24gZGUgZ2VzdGlvbiBjbG91ZCBkw6lkacOpZSBhdSBQTUUgYXUgVUs8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay88L2xpbms%DQoNCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2V4Y2x1LW15ZXJwLWNvbS1sYW5jZS11bmUtdmVyc2lvbi1kZS1zb24tYXBwbGljYXRpb24tZGUtZ2VzdGlvbi1jbG91ZC1kZWRpZWUtYXUtcG1lLWF1LXVrLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPldlZCwgMjggTWFyIDIwMTIgMTI6MjQ6MzMgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkF1cmVsaWUgUGVycnVjaGU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW215RVJQXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg5NzwvZ3VpZD4NCg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzkwMCIgdGl0bGU9Im15ZXJwIiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9teWVycC5wbmciIGFsdD0iIiB3aWR0aD0iMjQzIiBoZWlnaHQ9IjExMSIgLz48YSBocmVmPSJodHRwOi8vbXllcnAuY29tLyIgdGFyZ2V0PSJfc2VsZiI%TXlFUlAuY29tPC9hPiBlc3QgbGUgPHN0cm9uZz5wcmVtaWVyIHNlcnZpY2UgY2xvdWQgZGUgZ2VzdGlvbjwvc3Ryb25nPiDDoCBkZXN0aW5hdGlvbiBkZXMgUE1FLCBsYSBzb2Npw6l0w6kgbGFuY2UgYXVqb3VyZCdodWkgdW5lIHZlcnNpb24gZGUgc29uIGFwcGxpY2F0aW9uIHN1ciBsZSBtYXJjaMOpIGJyaXRhbm5pcXVlIGFsb3JzIHF1ZSBzb24gY29uY3VycmVudCBsb2NhbCBTQUdFIG4nYSB0b3Vqb3VycyBwYXMgZGUgc29sdXRpb24gY2xvdWQuIExhbmPDqSBvZmZpY2llbGxlbWVudCBlbiA8c3Ryb25nPm1hcnMgMjAxMDwvc3Ryb25nPiBhdmVjIGxlIGxhbmNlbWVudCBkZSBHb29nbGUgQXBwcyBNYXJrZXRwbGFjZSwgbXlFUlAgY29tcHRlIHByw6hzIGRlIDUwMDAwIFBNRSDDoCB0cmF2ZXJzIHBsdXMgZGUgMTAwIHBheXMgZGlmZsOpcmVudHMgcXVpIHV0aWxpc2VudCByw6lndWxpw6hyZW1lbnQgbGEgcGxhdGVmb3JtZSBwb3VyIGfDqXJlciB0b3V0ZXMgbGVzIGFjdGl2aXTDqXMgZGUgbGV1ciBzb2Npw6l0w6kgZGVwdWlzIGxlIGNsb3VkIDogbGEgY29tcHRhYmlsaXTDqSBlbiBsaWduZSwgbGEgZmFjdHVyYXRpb24sIGxlIENSTSwgbGVzIHN0b2NrcyBldCBiaWVuIHBsdXMsIGxlIHRvdXQgaW50w6lncsOpIGF2ZWMgR29vZ2xlIEFwcHMuIEMnZXN0IHVuZSA8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMC8wNy8xNi9sZXMtZnJhbmNhaXMtZGUtbGEtdmFsbGV5LXRvdXItZGhvcnpvbi1kZXMtc3RhcnR1cHMtb3UtZW50cmVwcmVuZXVycy1mcmFuY2Fpcy8iIHRhcmdldD0iX2JsYW5rIj5zdGFydHVwIGZyYW7Dp2Fpc2UgcGFydGllIGRhbnMgbGEgc2lsaWNvbiBWYWxsZXk8L2E%Ll1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MDAiIHRpdGxlPSJteWVycCIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbXllcnAucG5nIiBhbHQ9IiIgd2lkdGg9IjI0MyIgaGVpZ2h0PSIxMTEiIC8%PGEgaHJlZj0iaHR0cDovL215ZXJwLmNvbS8iIHRhcmdldD0iX3NlbGYiPk15RVJQLmNvbTwvYT4gZXN0IGxlIDxzdHJvbmc%cHJlbWllciBzZXJ2aWNlIGNsb3VkIGRlIGdlc3Rpb248L3N0cm9uZz4gw6AgZGVzdGluYXRpb24gZGVzIFBNRSwgbGEgc29jacOpdMOpIGxhbmNlIGF1am91cmQmIzgyMTc7aHVpIHVuZSB2ZXJzaW9uIGRlIHNvbiBhcHBsaWNhdGlvbiBzdXIgbGUgbWFyY2jDqSBicml0YW5uaXF1ZSBhbG9ycyBxdWUgc29uIGNvbmN1cnJlbnQgbG9jYWwgU0FHRSBuJiM4MjE3O2EgdG91am91cnMgcGFzIGRlIHNvbHV0aW9uIGNsb3VkLiBMYW5jw6kgb2ZmaWNpZWxsZW1lbnQgZW4gPHN0cm9uZz5tYXJzIDIwMTA8L3N0cm9uZz4gYXZlYyBsZSBsYW5jZW1lbnQgZGUgR29vZ2xlIEFwcHMgTWFya2V0cGxhY2UsIG15RVJQIGNvbXB0ZSBwcsOocyBkZSA1MDAwMCBQTUUgw6AgdHJhdmVycyBwbHVzIGRlIDEwMCBwYXlzIGRpZmbDqXJlbnRzIHF1aSB1dGlsaXNlbnQgcsOpZ3VsacOocmVtZW50IGxhIHBsYXRlZm9ybWUgcG91ciBnw6lyZXIgdG91dGVzIGxlcyBhY3Rpdml0w6lzIGRlIGxldXIgc29jacOpdMOpIGRlcHVpcyBsZSBjbG91ZCA6IGxhIGNvbXB0YWJpbGl0w6kgZW4gbGlnbmUsIGxhIGZhY3R1cmF0aW9uLCBsZSBDUk0sIGxlcyBzdG9ja3MgZXQgYmllbiBwbHVzLCBsZSB0b3V0IGludMOpZ3LDqSBhdmVjIEdvb2dsZSBBcHBzLiBDJiM4MjE3O2VzdCB1bmUgPGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTAvMDcvMTYvbGVzLWZyYW5jYWlzLWRlLWxhLXZhbGxleS10b3VyLWRob3J6b24tZGVzLXN0YXJ0dXBzLW91LWVudHJlcHJlbmV1cnMtZnJhbmNhaXMvIiB0YXJnZXQ9Il9ibGFuayI%c3RhcnR1cCBmcmFuw6dhaXNlIHBhcnRpZSBkYW5zIGxhIHNpbGljb24gVmFsbGV5PC9hPi48L3A%DQo8cD5MJiM4MjE3O29mZnJlIGRlIG15RVJQIHBlcm1ldCBhdXggUE1FIGQmIzgyMTc7YWNoZXRlciB1bmUgc2V1bGUgYXBwbGljYXRpb24gc2ltcGxlIGV0IGNvbXBsw6h0ZSBhdSBsaWV1IGRlIG11bHRpcGxlcyBhcHBsaWNhdGlvbnMgY2jDqHJlcyBldCBkaWZmaWNpbGVzIMOgIHV0aWxpc2VyLiBHcsOiY2Ugw6Agc29uIGludGVyZmFjZSBzaW1wbGUgYXZlYyB1bmUgYmFycmUgZGUgbmF2aWdhdGlvbiDDoCBsYSBHb29nbGUgZXQgc29uIGFsZ29yaXRobWUgaW50ZWxsaWdlbnQgZXQgcHLDqWRpY3RpZiBxdWkgYXJyaXZlIMOgIGNvbXByZW5kcmUgZXhhY3RlbWVudCBjZSBxdWUgbCYjODIxNzt1dGlsaXNhdGV1ciBzb3VoYWl0ZSBmYWlyZSwgbCYjODIxNzthcHBsaWNhdGlvbiBteUVSUCBuZSBuw6ljZXNzaXRlIGF1Y3VuZSBmb3JtYXRpb24gYWZpbiBkZSBsJiM4MjE3O3V0aWxpc2VyLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MDQiIHRpdGxlPSJteWVycCIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbXllcnAyLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTYiIGhlaWdodD0iMzAyIiAvPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%PHN0cm9uZz5GcmFuw6dvaXMgTmFkYWw8L3N0cm9uZz4sIFBERyBkZSBteUVSUCwgZXhwbGlxdWUgbGUgbGFuY2VtZW50IGRlIGxhIHZlcnNpb24gYnJpdGFubmlxdWU6ICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBicml0YW5uaXF1ZSByZXByw6lzZW50ZSBzZWxvbiBub3MgZXN0aW1hdGlvbnMgbGUgNMOobWUgbWFyY2jDqSBsZSBwbHVzIGludMOpcmVzc2FudCBwb3VyIGxlcyBhcHBsaWNhdGlvbnMgY2xvdWQ8L2VtPiYjODIyMDsuIElsIHByw6ljaXNlIGVuIHBsdXMgcXVlICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBVSyBlc3QgZG9taW7DqSBwYXIgbCYjODIxNzthY3RldXIgaGlzdG9yaXF1ZSwgU2FnZSwgcXVpIG4mIzgyMTc7YSBwYXMgc3UgcHJvcG9zZXIgw6Agc2VzIGNsaWVudHMgdW5lIHZlcnNpb24gY2xvdWQuIE5vdXMgZXN0aW1vbnMgcXUmIzgyMTc7ZW4gMjAxMSwgMzUlIGRlcyBlbnRyZXByaXNlcyBicml0YW5uaXF1ZXMgc291aGFpdGFpZW50IGTDqWrDoCBtaWdyZXIgbGV1ciBnZXN0aW9uIGRhbnMgbGUgY2xvdWQuIEVuIDIwMTIsIG15RVJQIGFycml2ZSBlbmZpbiBhdmVjIHVuZSBzb2x1dGlvbiBtYXR1cmUsIHJvYnVzdGUgZXQgc8OpY3VyaXPDqWUgcG91ciBhc3N1cmVyIGNldHRlIG1pZ3JhdGlvbi48L2VtPiYjODIyMDs8L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogbGVmdDsiPkwmIzgyMTc7b3V2ZXJ0dXJlIGR1IGNvbXB0ZSBteUVSUCBlc3QgZ3JhdHVpdCBhdmVjIGRlcyBmb25jdGlvbm5hbGl0w6lzIGlsbGltaXTDqWVzIHBvdXIgMSB1dGlsaXNhdGV1ci4gTGVzIG9mZnJlcyBwYXlhbnRlcyAmIzgyMjA7UHJlbWl1bSYjODIyMTsgc29udCBkaXNwb25pYmxlcyBwb3VyIDIgdXRpbGlzYXRldXJzIG91IDUgdXRpbGlzYXRldXJzLCBhdSBkZWzDoCwgbCYjODIxNzt1dGlsaXNhdGV1ciBzdXBwbMOpbWVudGFpcmUgZXN0IGZhY3R1csOpIDEy4oKsIHBhciBtb2lzLiBCb24gbGFuY2VtZW50ICE8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4zPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkNpdGl2ZXJzaXR5LCBsZSBmZXUgZGUgY2FtcCAyLjA8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9jaXRpdmVyc2l0eS1sZS1mZXUtZGUtY2FtcC0yLTAvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%V2VkLCAyOCBNYXIgMjAxMiAxMjowODozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbY2l0eXZlcnNpdHldXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODg4PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi4NCg0KUGVybWV0dHJlIMOgIGRlcyBwYXNzaW9ubsOpcyBkZSBwYXJ0YWdlciBsZXVyIGV4cMOpcmllbmNlIGF2ZWMgdW5lIHF1aW56YWluZSBkZSBwZXJzb25uZXMgZW4gZGV1eCBoZXVyZXMgZXQgZGFucyB1biBsaWV1IGFkYXB0w6ksIHRlbCBlc3QgbOKAmW9iamVjdGlmIHF1ZSBz4oCZZXN0IGZpeMOpIDxhIGhyZWY9Imh0dHA6Ly9jaXRpdmVyc2l0eS5ldmVudGJyaXRlLmNvbSI%IENpdGl2ZXJzaXR5PC9hPi4NCg0KVW4gb2JqZWN0aWYgcXVpIG7igJllc3QgcGFzIHNhbnMgcmFwcGVsZXIgY2VsdWkgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5za2lsbHNoYXJlLmNvbSI%U2tpbGxzaGFyZTwvYT4sIHN0YXJ0LXVwIG5ldy15b3JrYWlzZSBiaWVuIGNvbm51ZSBtYWlzIHF1aSBzb3VmZnJlIGRlIGxhIGxpYmVydMOpIGxhaXNzw6llIMOgIHNlcyB1dGlsaXNhdGV1cnMgOyBu4oCZaW1wb3J0ZSBxdWkgcG91dmFudCBwcm9wb3NlciB1biBjb3VycywgY29tbWVudCBzYXZvaXIgc2kgbGUgcHJvZmVzc2V1ciBzZXJhIGRlIHF1YWxpdMOpPyBDb21tZW50LCBwb3VyIGxlcyBwcm9mZXNzZXVycywgdHJvdXZlciBldCByw6lzZXJ2ZXIgdW5lIHNhbGxlIGFkYXB0w6llIHNhbnMgbWV0dHJlIGdyYXZlbWVudCBlbiBkYW5nZXIgbGEgcmVudGFiaWxpdMOpIGRlIGzigJlvcMOpcmF0aW9uID8gVGVsbGVzIHNvbnQgbGVzIHF1ZXN0aW9ucyBhdXhxdWVsbGVzIHLDqXBvbmQgQ2l0aXZlcnNpdHksIHF1aSBzw6lsZWN0aW9ubmUgbcOpdGljdWxldXNlbWVudCBzZXMgYW5pbWF0ZXVycyBldCBwcmVuZCBlbiBjaGFyZ2UgbOKAmWFzcGVjdCBsb2dpc3RpcXVlIGRlIGzigJlvcmdhbmlzYXRpb24gZGUgbOKAmWF0ZWxpZXIgKHVuIHNlcnZpY2UgcG91ciBsZXF1ZWwgQ2l0aXZlcnNpdHkgcHLDqWzDqHZlIDI1JSBkdSB0b3RhbCwgZnJhaXMgZOKAmW9yZ2FuaXNhdGlvbiBkw6lkdWl0cykuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5QZXJtZXR0cmUgw6AgZGVzIHBhc3Npb25uw6lzIGRlIHBhcnRhZ2VyIGxldXIgZXhww6lyaWVuY2UgYXZlYyB1bmUgcXVpbnphaW5lIGRlIHBlcnNvbm5lcyBlbiBkZXV4IGhldXJlcyBldCBkYW5zIHVuIGxpZXUgYWRhcHTDqSwgdGVsIGVzdCBs4oCZb2JqZWN0aWYgcXVlIHPigJllc3QgZml4w6kgPGEgaHJlZj0iaHR0cDovL2NpdGl2ZXJzaXR5LmV2ZW50YnJpdGUuY29tIj4gQ2l0aXZlcnNpdHk8L2E%LjwvcD4NCjxwPlVuIG9iamVjdGlmIHF1aSBu4oCZZXN0IHBhcyBzYW5zIHJhcHBlbGVyIGNlbHVpIGRlIDxhIGhyZWY9Imh0dHA6Ly93d3cuc2tpbGxzaGFyZS5jb20iPlNraWxsc2hhcmU8L2E%LCBzdGFydC11cCBuZXcteW9ya2Fpc2UgYmllbiBjb25udWUgbWFpcyBxdWkgc291ZmZyZSBkZSBsYSBsaWJlcnTDqSBsYWlzc8OpZSDDoCBzZXMgdXRpbGlzYXRldXJzIDsgbuKAmWltcG9ydGUgcXVpIHBvdXZhbnQgcHJvcG9zZXIgdW4gY291cnMsIGNvbW1lbnQgc2F2b2lyIHNpIGxlIHByb2Zlc3NldXIgc2VyYSBkZSBxdWFsaXTDqT8gQ29tbWVudCwgcG91ciBsZXMgcHJvZmVzc2V1cnMsIHRyb3V2ZXIgZXQgcsOpc2VydmVyIHVuZSBzYWxsZSBhZGFwdMOpZSBzYW5zIG1ldHRyZSBncmF2ZW1lbnQgZW4gZGFuZ2VyIGxhIHJlbnRhYmlsaXTDqSBkZSBs4oCZb3DDqXJhdGlvbiA:IFRlbGxlcyBzb250IGxlcyBxdWVzdGlvbnMgYXV4cXVlbGxlcyByw6lwb25kIENpdGl2ZXJzaXR5LCBxdWkgc8OpbGVjdGlvbm5lIG3DqXRpY3VsZXVzZW1lbnQgc2VzIGFuaW1hdGV1cnMgZXQgcHJlbmQgZW4gY2hhcmdlIGzigJlhc3BlY3QgbG9naXN0aXF1ZSBkZSBs4oCZb3JnYW5pc2F0aW9uIGRlIGzigJlhdGVsaWVyICh1biBzZXJ2aWNlIHBvdXIgbGVxdWVsIENpdGl2ZXJzaXR5IHByw6lsw6h2ZSAyNSUgZHUgdG90YWwsIGZyYWlzIGTigJlvcmdhbmlzYXRpb24gZMOpZHVpdHMpLjwvcD4NCjxwPlRyw6hzIGNlbnRyw6kgc3VyIGxhIHF1YWxpdMOpIGRlIGzigJnDqWNoYW5nZSwgQ2l0aXZlcnNpdHkgcsOqdmUgYWluc2kgZGUgZmFpcmUgw6ljbG9yZSBlbiBjaGFjdW4gbOKAmWVudmllIGRlIHBhcnRhZ2VyIGNlIHF1aSBsZSByZW5kIHVuaXF1ZSA6IHNvbiBleHDDqXJpZW5jZS4gQWluc2kgYS10LW9uIHB1IHBhcnRpY2lwZXIgZW4gTWFycyDDoCB1biBhdGVsaWVyIGRlIGTDqWNvdXZlcnRlIGR1IGJhbGxldCBhbmltw6kgcGFyIHVuZSBkYW5zZXVzZSBjbGFzc2lxdWUgY29uZmlybcOpZSwgb3Ugw6AgdW4gYXV0cmUgdmlzYW50IMOgIGZvcm1lciBsZXMgYXVkaXRldXJzIMOgIGzigJlhcnQgZGUgbOKAmWludGVydmlldyBwcm9wb3PDqSBwYXIgdW4gam91cm5hbGlzdGUgcmVub21tw6kuPC9wPg0KPHA%Rm9uZMOpIHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL2tuaWxmbyI%IEtleXZhbiBOaWxmb3JvdXNoYW4gPC9hPmFwcsOocyB1bmUgcHJlbWnDqHJlIGNhcnJpw6hyZSBkZSBWQyBjaGV6IE5leHRTdGFnZSwgQ2l0aXZlcnNpdHkgaWxsdXN0cmUgcGFyZmFpdGVtZW50IGRldXggY29uY2VwdHMgdHLDqHMgZW4gdm9ndWU6IGxlIDxlbT5sZWFuPC9lbT4gZXQgbGEgPGVtPmN1cmF0aW9uPC9lbT4uIERhbnMgdW4gcHJlbWllciB0ZW1wcywgQ2l0aXZlcnNpdHkgYSBlbiBlZmZldCBjaG9pc2kgZOKAmXV0aWxpc2VyIGxhIHNvbHV0aW9uIEV2ZW50YnJpdGUgKGFpbnNpIHF1ZSBNYWlsY2hpbXAgZXQgTGF1bmNocm9jaykgbGUgdGVtcHMgZGUgcHLDqWNpc2VyIHNvbiBtb2TDqGxlLiBCaWVuIGx1aSBlbiBhIHByaXMgYXV4IHZ1ZXMgZHUgc3VjY8OocyBkZXMgcHJlbWllcnMgYXRlbGllcnMsIHF1aSBvbnQgdmFsaWTDqSBzYSBjb252aWN0aW9uIHF14oCZaWwgeSBhIHVuZSB2w6lyaXRhYmxlIHZhbGV1ciBham91dMOpZSDDoCBuZSBwcm9wb3NlciBxdWUgZGVzIGV4cMOpcmllbmNlcyBxdWFsaXRhdGl2ZXMgKGxlIHRhcmlmIG1veWVuIMOpdGFudCBkZSA1MCBldXJvcyBwYXIgcGVyc29ubmUuKTwvcD4NCjxwPkVuIGF0dGVuZGFudCBsYSB2ZXJzaW9uIDIuMCwgZGUgbm9tYnJldXggYXRlbGllcnMgc29udCBkw6lqw6AgcHJvZ3JhbW3DqXMsIHBhcm1pIGxlc3F1ZWxzIMKrIEZhaXJlIHNlcyBjb3Vyc2VzIMOgIENoaW5hdG93biDCuywgwqsgUHJlbmRyZSBsZXMgbW9udW1lbnRzIHBhcmlzaWVucyBlbiBwaG90byDCuyBldCDCqyBMZSBwaWFubyBlbiA0IGhldXJlcyDCuyAoZW4gZGV1eCBwYXJ0aWVzKS48L3A%DQo8cD5Wb3VzIHLDqnZleiBk4oCZdW4gYXRlbGllciBlbiBwYXJ0aWN1bGllciA:IERlbWFuZGV6LWxlLCA8YSBocmVmPSJodHRwOi8vZmVlZGJhY2suY2l0aXZlcnNpdHkuY29tIj51bmUgcGFnZSBkw6lkacOpZTwvYT4gZXN0IGzDoCBwb3VyIMOnYS4gU2kgbGEgY29tbXVuYXV0w6kgdm90ZSBwb3VyIHZvdHJlIGlkw6llLCA8YSBocmVmPSJodHRwOi8vY2l0aXZlcnNpdHkuZXZlbnRicml0ZS5jb20iPiBDaXRpdmVyc2l0eTwvYT4gc2UgY2hhcmdlcmEgZGUgdHJvdXZlciBs4oCZaW50ZXJ2ZW5hbnQgaWTDqWFsLCBldCBkZSBkb25uZXIgdmllIMOgIGzigJlhdGVsaWVyLiAgRXQgdm91cywgcXXigJlhdmV6LXZvdXMgw6AgcGFydGFnZXIgPzwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCg0KCQk8dGl0bGU%TGUgSmV1ZGkgMTIgQXZyaWwsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHPigJlpbnZpdGVudCBhdSBQYWxhaXMgZGUgbGEgZMOpY291dmVydGU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDIzOjAwOjMyICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5BdXJlbGllIFBlcnJ1Y2hlPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4Njg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9yZXNlYXV4LXNvY2lhdXgucG5nIiBhbHQ9IiIgd2lkdGg9IjI3MSIgaGVpZ2h0PSIxNDgiIC8%TGVzIDEyIGV0IDEzIGF2cmlsIDIwMTIsIGzigJlVbml2ZXJzaXTDqSBkZSBWZXJzYWlsbGVzIFNhaW50LVF1ZW50aW4tZW4tWXZlbGluZXMgb3JnYW5pc2UgYXUgUGFsYWlzIGRlIGxhIGTDqWNvdXZlcnRlIDxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJiMzODtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%dW48L2E%DQo8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCYjMzg7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPmNvbGxvcXVlIGNvbnNhY3LDqSBhdXggbm91dmVhdXggbcOpZGlhczwvYT4uIFVuZSB0YWJsZSByb25kZSBzdXIgbGEgdGjDqW1hdGlxdWUgZGUgPHN0cm9uZz5sYSBjdWx0dXJlIGV0IGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IGVzdA0KcHJvcG9zw6llIGxlIDxzdHJvbmc%amV1ZGkgMTIgYXZyaWwgMjAxMiBkZSA5aDMwIMOgIDEyaDAwPC9zdHJvbmc%Lg0KDQpEZXB1aXMgcGx1c2lldXJzIGFubsOpZXMsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHNvbnQgZGV2ZW51cyBkZSB2w6lyaXRhYmxlcyBvdXRpbHMgZGUgcGFydGFnZS5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9yZXNlYXV4LXNvY2lhdXgucG5nIiBhbHQ9IiIgd2lkdGg9IjI3MSIgaGVpZ2h0PSIxNDgiIC8%TGVzIDEyIGV0IDEzIGF2cmlsIDIwMTIsIGzigJlVbml2ZXJzaXTDqSBkZSBWZXJzYWlsbGVzIFNhaW50LVF1ZW50aW4tZW4tWXZlbGluZXMgb3JnYW5pc2UgYXUgUGFsYWlzIGRlIGxhIGTDqWNvdXZlcnRlIDxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJmFtcDtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%dW48L2E%PGJyIC8%DQo8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCZhbXA7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPmNvbGxvcXVlIGNvbnNhY3LDqSBhdXggbm91dmVhdXggbcOpZGlhczwvYT4uIFVuZSB0YWJsZSByb25kZSBzdXIgbGEgdGjDqW1hdGlxdWUgZGUgPHN0cm9uZz5sYSBjdWx0dXJlIGV0IGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IGVzdDxiciAvPg0KcHJvcG9zw6llIGxlIDxzdHJvbmc%amV1ZGkgMTIgYXZyaWwgMjAxMiBkZSA5aDMwIMOgIDEyaDAwPC9zdHJvbmc%LjwvcD4NCjxwPkRlcHVpcyBwbHVzaWV1cnMgYW5uw6llcywgbGVzIHLDqXNlYXV4IHNvY2lhdXggc29udCBkZXZlbnVzIGRlIHbDqXJpdGFibGVzIG91dGlscyBkZSBwYXJ0YWdlLiBEaWZmdXNhbnQgZGUgbGEgbXVzaXF1ZSwgZGVzIGZpbG1zLCBkZXMgcmVwcsOpc2VudGF0aW9ucyB0aMOpw6J0cmFsZXMgZXQgYmllbiBk4oCZYXV0cmVzIGNyw6lhdGlvbnMgYXJ0aXN0aXF1ZXMsIGlscyBzb250IGTigJlpbmNyb3lhYmxlcyBwbGF0ZWZvcm1lcyBk4oCZw6ljaGFuZ2UsIHVuIHbDqXJpdGFibGUgdHJlbXBsaW4gcG91ciBsZXMgYXJ0aXN0ZXMgZXQgdW4gbm91dmVhdSB2ZWN0ZXVyIGRlIHRyYW5zbWlzc2lvbiBkZSBsYSBjdWx0dXJlLiBEYW5zIHVuZSBzb2Npw6l0w6kgZ291dmVybsOpZSBwYXIgbGEgY29tbXVuaWNhdGlvbiBldCBsYSByYXBpZGl0w6kgZGVzIMOpY2hhbmdlcywgbGVzIHByYXRpcXVlcyBjdWx0dXJlbGxlcyBvbnQgc3ViaSBsYSBtdXRhdGlvbiBkZSBjZXR0ZSBpbnN0YW50YW7DqWl0w6kgYWJzb2x1ZS4gRW4gcXVlbHF1ZXMgY2xpY3MsIGxlcyBpbnRlcm5hdXRlcyBwZXV2ZW50IGF1am91cmTigJlodWkgZMOpY291dnJpciBkZXMgdmlkw6lvcyBldCBkZXMgY29udGVudXMgcHVibGnDqXMgc3VyIHRvdXMgbGVzIGNvbnRpbmVudHMsIHNvdXRlbmlyIHVuIGFydGlzdGUgcXXigJlpbHMgYWZmZWN0aW9ubmVudCBldCBsaXJlIHVuIHJvbWFuIG51bcOpcmlzw6kgZW4gbGlnbmUuPC9wPg0KPHA%TGVzIHLDqXNlYXV4IHNvY2lhdXggYWdpc3NlbnQgY29tbWUgZGVzIHLDqXbDqWxhdGV1cnMgZGUgdGFsZW50cyBwYXIgbGUgYmlhaXMgZGVzIHBsYXRlZm9ybWVzIHBhcnRpY2lwYXRpdmVzIGV0IHBlcm1ldHRlbnQgw6AgZGVzIGFydGlzdGVzIGRlIHNlIGZhaXJlIGNvbm5hw650cmUgZHUgcHVibGljIHNhbnMgYXZvaXIgw6Agc2Ugc291bWV0dHJlIGF1eCBjZXJjbGVzIGRlIGzDqWdpdGltYXRpb248YnIgLz4NCnRyYWRpdGlvbm5lbHMuIENlcGVuZGFudCwgw6l2b3F1ZXIgbOKAmWV4cGxvaXRhdGlvbiBkZXMgcsOpc2VhdXggc29jaWF1eCBwYXIgbGVzIGFydGlzdGVzIG7DqWNlc3NpdGUgZGUgc%KAmWludGVycm9nZXIgc3VyIGxldXIgY29udHLDtGxlIGV0IGzigJlpbXBhY3QgcXXigJlpbHMgc29udCBzdXNjZXB0aWJsZXMgZOKAmWF2b2lyIHN1ciBsZSBkcm9pdCBk4oCZYXV0ZXVyIGV0IHN1ciBsYSBwcm9wcmnDqXTDqSBpbnRlbGxlY3R1ZWxsZS48L3A%DQo8cD5Qb3VyIHLDqXBvbmRyZSDDoCBjZXMgcXVlc3Rpb25zIG5vdXZlbGxlcywgYXV0b3VyIGRlIGNldHRlIHRhYmxlIHJvbmRlIGRpZmbDqXJlbnRzIHNww6ljaWFsaXN0ZXMgc2Vyb250IHByw6lzZW50cyA6IDxzdHJvbmc%SnVsaWVuIFJBU1RFR0FSPC9zdHJvbmc%IChqb3VybmFsaXN0ZSBzY2llbnRpZmlxdWUpLCA8c3Ryb25nPk5pY29sYXMgTE9VQkVUPC9zdHJvbmc%IChlbnRyZXByZW5ldXIgZXQgY29uc3VsdGFudCBVbWFwcyk8YnIgLz4NCjxzdHJvbmc%TWFyaW5lIEpPVUFOPC9zdHJvbmc%IChjaGFyZ8OpIGRlcyBwcm9qZXRzIGRlIEtpc3NLaXNzIEJhbmtCYW5rKSwgPHN0cm9uZz5BbXlsZWU8L3N0cm9uZz4gKGFydGlzdGUgcGxhc3RpY2llbm5lKSBldCA8c3Ryb25nPk5hdGhhbGllIERSRVlGVVM8L3N0cm9uZz4gKGp1cmlzdGUpLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2xlLWpldWRpLTEyLWF2cmlsLWxlcy1yZXNlYXV4LXNvY2lhdXgtcyVlMiU4MCU5OWludml0ZW50LWF1LXBhbGFpcy1kZS1sYS1kZWNvdXZlcnRlL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjE8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5TUEVBUiBwcm9mZXNzaW9ubmFsaXNlIGxlIGNyb3dkbGVuZGluZyDDqXRoaXF1ZTwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvc3BlYXItcHJvZmVzc2lvbm5hbGlzZS1sZS1jcm93ZGxlbmRpbmctZXRoaXF1ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDE2OjA4OjQ5ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5KdWxpZW4gTWVjaGluPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2Nyb3dkbGVuZGluZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtzcGVhcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4ODA8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODgyIiB0aXRsZT0ic3BlYXIiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3NwZWFyLnBuZyIgYWx0PSIiIHdpZHRoPSIyNTAiIGhlaWdodD0iNjkiIC8%DQoNCkFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%Lg0KDQpJbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4ODIiIHRpdGxlPSJzcGVhciIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc3BlYXIucG5nIiBhbHQ9IiIgd2lkdGg9IjI1MCIgaGVpZ2h0PSI2OSIgLz48L3A%DQo8cD5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5JbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLjwvcD4NCjxwPlNQRUFSIHByb3Bvc2UgZGUgZsOpZMOpcmVyIGxlcyDDqXBhcmduYW50cyBhZmluIGRlIGxldXIgcGVybWV0dHJlIGRlIG1ldHRyZSBsZXVyIGFyZ2VudCBhdSBzZXJ2aWNlIGRlIHByb2pldHMgcXXigJlpbHMgY2hvaXNpc3NlbnQsIGV0IHF1aSBvbnQgZHUgc2VucyDDoCBsZXVycyB5ZXV4ICjDqWNvbG9naXF1ZXMsIHNvY2lhdXggb3UgY3VsdHVyZWxzKS4gw4AgbGEgZGlmZsOpcmVuY2UgZGUgc3RydWN0dXJlcyBjb21tZSBLaWNrc3RhcnRlciBvdSBNeW1ham9yY29tcGFueSwgU1BFQVIgcHJvcG9zZSBk4oCZaW52ZXN0aXIgZW4gZGV0dGUsIGV0IHPDqWxlY3Rpb25uZSBsZXMgaW5pdGlhdGl2ZXMgcXXigJlpbCBlc3QgcG9zc2libGUgZOKAmWFpZGVyIGVuIGZvbmN0aW9uIGRlIGNyaXTDqHJlcyDDqXRoaXF1ZXMgZXQgZmluYW5jaWVycy4gIExlIHRvdXQgc2FucyBhdWN1biByaXNxdWUgcG91ciBs4oCZw6lwYXJnbmFudC48L3A%DQo8cD5Qb3VyIHJlbmRyZSBwb3NzaWJsZSBjZXR0ZSDDqXF1YXRpb24sIFNQRUFSIHPigJllc3QgYWxsacOpIMOgIGRlcyBiYW5xdWVzIChsZSBDcsOpZGl0IE11bmljaXBhbCBkZSBQYXJpcyAgcG91ciBsZSBtb21lbnQsIGRlcyBwYXJ0ZW5hcmlhdCBhdmVjIGxlIENyw6lkaXQgQ29vcMOpcmF0aWYgZXQgbGEgQ2Fpc3NlIGTigJkgw4lwYXJnbmUgc29udCBlbiBib25uZSB2b2llKSBxdWkgc8OpY3VyaXNlbnQgbGUgcHLDqnQgbW95ZW5uYW50IHVuZSBjb21taXNzaW9uIGRlc3RpbsOpZSDDoCBjb21wZW5zZXIgbGUgcmlzcXVlIGRlIGTDqWZhdXQuIEzigJllbnRyZXByZW5ldXIgb2J0aWVudCBhaW5zaSBmYWNpbGVtZW50IHVuIGNyw6lkaXQgcG91ciB1biB0YXV4IGluZsOpcmlldXIgYXUgdGF1eCBkdSBtYXJjaMOpIGV0IGzigJnDqXBhcmduYW50LCBtb3llbm5hbnQgdW5lIG1vZGlxdWUgZGltaW51dGlvbiBkZSBzb24gdGF1eCBkZSByZW5kZW1lbnQsIG1ldCBzb24gYXJnZW50IGF1IHNlcnZpY2UgZGUgc2VzIGNvbnZpY3Rpb25zLiBVbiBiw6luw6lmaWNlIGF1cXVlbCBz4oCZYWpvdXRlbnQgbGVzIGNsYXNzaXF1ZXMgZGlzcG9zaXRpZnMgZGUgZMOpZHVjdGlvbiBkZSBs4oCZSVNGIGV0IGRlIGzigJlJUlBQLCBwdWlzcXVlIGzigJnDqXBhcmduZSBzZSByw6lhbGlzZSBwYXIgbGEgc291c2NyaXB0aW9uIGRlIHBhcnRzIHNvY2lhbGVzIGRlIFNQRUFSLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvQ2FwdHVyZS1k4oCZw6ljcmFuLTIwMTItMDMtMjYtw6AtMjMuMzYuNDYucG5nIj48aW1nIGNsYXNzPSJzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4ODEgYWxpZ25jZW50ZXIiIHRpdGxlPSJDYXB0dXJlIGTigJnDqWNyYW4gMjAxMi0wMy0yNiDDoCAyMy4zNi40NiIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvQ2FwdHVyZS1k4oCZw6ljcmFuLTIwMTItMDMtMjYtw6AtMjMuMzYuNDYucG5nIiBhbHQ9IiIgd2lkdGg9IjQ4NyIgaGVpZ2h0PSIzNzQiIC8%PC9hPjwvcD4NCjxwPk1vaW5zIGRlIDE1JSBkZXMgcHJvamV0cyBzb3VtaXMgw6AgU1BFQVIgc29udCByZXRlbnVzIHBhciBzb24gY29taXTDqS4gUG91ciBsZSBtb21lbnQsIDIwMCAwMDAgZXVyb3MgZOKAmSDCqyDDqXBhcmduZSB0cmFuc3BhcmVudGUgwrsgb250IGZpbmFuY8OpcyAzIHByb2pldHMsIGV0IDIgc29udCBlbiBwYXNzZSBkZSBs4oCZw6p0cmUgKDxhIGhyZWY9Imh0dHA6Ly9zcGVhci5mci9wcm9qZXRzLzE2Ij4gQ2xhaXIgJmFtcDsgTmV0IDwvYT4sIGVudHJlcHJpc2UgZOKAmWluc2VydGlvbiBwYXIgbGUgdHJhdmFpbCBkYW5zIGxlIHNlY3RldXIgZGUgbOKAmcOpY29wcm9wcmV0w6kgZXQgPGEgaHJlZj0iaHR0cDovL3NwZWFyLmZyL3Byb2pldHMvMTgiPiBCYXNpbGlhZGUgPC9hPiwgc3RydWN0dXJlIGTigJlhaWRlIGF1eCBtYWxhZGVzIGR1IFNJREEpLiA1IGF1dHJlcyBsZXMgcmVqb2luZHJvbnQgZOKAmWljaSBs4oCZw6l0w6kgKHVuIHByb2pldCB2aXNhbnQgw6AgZm91cm5pciBkZXMgbHVuZXR0ZXMgZGUgcsOpYWxpdMOpIGF1Z21lbnTDqWUgYXV4IG1hbGFkZXMgY2hyb25pcXVlcyBpbW1vYmlsaXPDqXMgc2VyYWl0IG5vdGFtbWVudCBkYW5zIGxlcyB0dXlhdXgpLjwvcD4NCjxwPkF2aXMgYXV4IGdlZWtzIGF1IGdyYW5kIGPFk3VyIDogbGEgcGxhdGVmb3JtZSwgbGF1csOpYXRlIGR1IFByaXggU0ZSIEpldW5lcyBUYWxlbnRzIEVudHJlcHJlbmV1cmlhdCBTb2NpYWwsIGVzdCBjb2TDqWUgZW4gUnVieSBvbiBSYWlscy4gRXQgZGVzIHJlY3J1dGVtZW50cyBzb250IGF1IHByb2dyYW1tZeKApjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPldhbGxpdCBjcsOpZSBkZXMgbXVycyB2aXJ0dWVscyBlbiByw6lhbGl0w6kgYXVnbWVudMOpZSBkYW5zIGxlcyBsaWV1eCBwdWJsaWNzPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvd2FsbGl0LWNyZWUtZGVzLW11cnMtdmlydHVlbHMtZW4tcmVhbGl0ZS1hdWdtZW50ZWUtZGFucy1sZXMtbGlldXgtcHVibGljcy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy93YWxsaXQtY3JlZS1kZXMtbXVycy12aXJ0dWVscy1lbi1yZWFsaXRlLWF1Z21lbnRlZS1kYW5zLWxlcy1saWV1eC1wdWJsaWNzLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPlR1ZSwgMjcgTWFyIDIwMTIgMDk6Mjk6MDYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbd2FsbGl0XV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg1MjwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9IndhbGxpdCIgc3JjPSJodHRwOi8vd2FsbGl0YXBwLmNvbS9pbWcvbG9nb193YWxsaXRfaWNvbi5wbmciIGFsdD0iIiB3aWR0aD0iMjMyIiBoZWlnaHQ9IjkyIiAvPiBBcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9jZWNpbG9nZSIgdGFyZ2V0PSJfYmxhbmsiPkPDqWNpbGUgTG9nw6k8L2E%Lg0KDQpDcsOpw6llIHBhciA8YSBocmVmPSJodHRwOi8vd3d3LmxpbmtlZGluLmNvbS9wdWIvdmV5c2VsLWJlcmsvMTAvMTExLzIxMiI%VmV5c2VsIEJlcms8L2E%LCB1biBhbmNpZW4gZGUgVUMgQmVya2VsZXkgcGxlaW4gZOKAmWlkw6llcyBldCBkw6l0ZW50ZXVyIGTigJl1biBQaEQgZW4gUGh5c2lxdWUsIDxhIGhyZWY9Imh0dHA6Ly93d3cud2FsbGl0YXBwLmNvbS8iPldhbGxpdDwvYT4gZXN0IHVuZSBub3V2ZWxsZSBhcHBsaWNhdGlvbiBpUGhvbmUgZ3JhdHVpdGUgcXVpIGNoZXJjaGUgw6AgY2hhbmdlciBub3RyZSB2aXNpb24gZGVzIGxpZXV4IHB1YmxpY3M6IGxhbmPDqWUgZMOpYnV0IG1hcnMsIGzigJlhcHBsaWNhdGlvbiBwZXJtZXQgZGUgY29tbXVuaXF1ZXIgYXZlYyBsZXMgcGVyc29ubmVzIHF1aSBzb250IGF1IG3Dqm1lIGVuZHJvaXQgYXUgbcOqbWUgbW9tZW50IHBhciBs4oCZaW50ZXJtw6lkaWFpcmUgZGUgbGEgcsOpYWxpdMOpIGF1Z21lbnTDqWUuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0id2FsbGl0IiBzcmM9Imh0dHA6Ly93YWxsaXRhcHAuY29tL2ltZy9sb2dvX3dhbGxpdF9pY29uLnBuZyIgYWx0PSIiIHdpZHRoPSIyMzIiIGhlaWdodD0iOTIiIC8%IEFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL2NlY2lsb2dlIiB0YXJnZXQ9Il9ibGFuayI%Q8OpY2lsZSBMb2fDqTwvYT4uPC9wPg0KPHA%Q3LDqcOpZSBwYXIgPGEgaHJlZj0iaHR0cDovL3d3dy5saW5rZWRpbi5jb20vcHViL3ZleXNlbC1iZXJrLzEwLzExMS8yMTIiPlZleXNlbCBCZXJrPC9hPiwgdW4gYW5jaWVuIGRlIFVDIEJlcmtlbGV5IHBsZWluIGTigJlpZMOpZXMgZXQgZMOpdGVudGV1ciBk4oCZdW4gUGhEIGVuIFBoeXNpcXVlLCA8YSBocmVmPSJodHRwOi8vd3d3LndhbGxpdGFwcC5jb20vIj5XYWxsaXQ8L2E%IGVzdCB1bmUgbm91dmVsbGUgYXBwbGljYXRpb24gaVBob25lIGdyYXR1aXRlIHF1aSBjaGVyY2hlIMOgIGNoYW5nZXIgbm90cmUgdmlzaW9uIGRlcyBsaWV1eCBwdWJsaWNzOiBsYW5jw6llIGTDqWJ1dCBtYXJzLCBs4oCZYXBwbGljYXRpb24gcGVybWV0IGRlIGNvbW11bmlxdWVyIGF2ZWMgbGVzIHBlcnNvbm5lcyBxdWkgc29udCBhdSBtw6ptZSBlbmRyb2l0IGF1IG3Dqm1lIG1vbWVudCBwYXIgbOKAmWludGVybcOpZGlhaXJlIGRlIGxhIHLDqWFsaXTDqSBhdWdtZW50w6llLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvd2FsbGl0LnBuZyI%PGltZyBjbGFzcz0ic2l6ZS1mdWxsIHdwLWltYWdlLTIzODUzIGFsaWduY2VudGVyIiB0aXRsZT0id2FsbGl0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy93YWxsaXQucG5nIiBhbHQ9IiIgd2lkdGg9IjQ0MyIgaGVpZ2h0PSIyOTciIC8%PC9hPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%RT9uIGZhaXQsIFdhbGxpdCBtw6lsYW5nZSBsZXMgdHJhaXRzIGRlcyBwbHVzIGdyYW5kcyByw6lzZWF1eCBzb2NpYXV4OiBsZXMgaW50ZXJhY3Rpb25zIHNvY2lhbGVzIGRlIEZhY2Vib29rLCBsZXMgMTQwIGNhcmFjdMOocmVzIG1heGltdW0gZGUgVHdpdHRlciBldCBsYSBnw6lvbG9jYWxpc2F0aW9uIGRlIEZvdXJzcXVhcmUsIGxlIHRvdXQgYXBwbGlxdcOpIMOgIGRlcyBtdXJzIHZpcnR1ZWxzIGFjY2Vzc2libGVzIGVuIHLDqWFsaXTDqSBhdWdtZW50w6llLiBJbWFnaW5vbnMgdW4gw6l2w6huZW1lbnQgaW1wb3J0YW50IGNvbW1lIHVuIG1hdGNoIGRlIGZvb3QsIG91IHVuIGZlc3RpdmFsOiBsZXMgcGFydGljaXBhbnRzIG7igJlhdXJvbnQgcXXigJnDoCBvdXZyaXIgbOKAmWFwcGxpY2F0aW9uLCBldCBzZSBnw6lvbG9jYWxpc2VyIHBvdXIgdm9pciBhcHBhcmFpdHJlIGxlIG11ciB2aXJ0dWVsIMOgIHRyYXZlcnMgbGEgY2Ftw6lyYSBkZSBsZXVyIGlQaG9uZSBldCBjb21tdW5pcXVlciBlbnRyZSBldXguIFBob3RvcywgY29tbWVudGFpcmVzLCB2aWTDqW9zLCBvdSBtZXNzYWdlcyBhdWRpb3MuLiBUb3V0IGVzdCBwb3NzaWJsZSE8L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3dhbGxpdDIucG5nIj48aW1nIGNsYXNzPSJzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4NTQgYWxpZ25jZW50ZXIiIHRpdGxlPSJ3YWxsaXQyIiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy93YWxsaXQyLnBuZyIgYWx0PSIiIHdpZHRoPSI0NDEiIGhlaWdodD0iMjk3IiAvPjwvYT48L3A%DQo8cD5XYWxsaXQgYSBkw6lqw6AgY3LDqcOpIHBsdXMgZGUgNzAwIG11cnMgdW4gcGV1IHBhcnRvdXQgZGFucyBsZSBtb25kZSAoTG9uZHJlcywgVG9reW8sIE5ldy1Zb3JrLCBQYXJpcy4uKS4gVW5lIGZvaXMgc3VyIHBsYWNlLCBvbiBwZXV0IGFwcG9ydGVyIHNhIGNvbnRyaWJ1dGlvbiBzb2l0IGFub255bWVtZW50LCBzb2l0IGVuIHNlIGxvZ2dhbnQgc3VyIEZhY2Vib29rIG91IFR3aXR0ZXI6IGJpZW50w7R0LCBkZXMgZm9uY3Rpb25zIHNvY2lhbGVzIHBlcm1ldHRhbnQgZGUgZmlsdHJlciBsZXMgcG9zdHMgKGFtaXMgRmFjZWJvb2sgIHNldWxlbWVudCBwYXIgZXhlbXBsZSkgc2Vyb250IMOpZ2FsZW1lbnQgZGlzcG9uaWJsZXMuPC9wPg0KPHA%QWxvcnMgcXVlIGxlcyBhdXRyZXMgYXBwcyBnw6lvbG9jYWxpc8OpZXMgZXQgbGVzIHLDqXNlYXV4IHNvY2lhdXggY29tbWUgRm91cnNxdWFyZSBzZSBmb2NhbGlzZW50IGfDqW7DqXJhbGVtZW50IHN1ciBsZXMgcHJvZmlscyBkZXMgdXRpbGlzYXRldXJzLCBjZWxsZS1jaSBhbWJpdGlvbm5lIGRlIGRvbm5lciB2aWUgYXV4IGxpZXV4IGV1eC1tw6ptZXMgZ3LDomNlIMOgIGxldXJzIHZpc2l0ZXVycy4gQmVyayBpbnNpc3RlIGTigJlhaWxsZXVycyBzdXIgbOKAmWlkw6llIHF1ZSBXYWxsaXQg4oCcPGVtPmNvbnRyaWJ1ZSDDoCBlbnRyZXRlbmlyIGzigJllc3NlbmNlIGRlcyBsaWV1eDwvZW0%4oCdIGV0IMOgIOKAnDxlbT5jdWx0aXZlciBsZXVyIHBlcnNvbm5hbGl0w6k8L2VtPuKAnSBncsOiY2UgYXUgcGFydGFnZSBk4oCZZXhww6lyaWVuY2VzLCBkZSBwaG90b3MsIGRlIGNvbW1lbnRhaXJlcyBkZXMgZ2VucyBxdWkgeSBwYXNzZW50IHBoeXNpcXVlbWVudC48L3A%DQo8cD48aWZyYW1lIHdpZHRoPSI1NjAiIGhlaWdodD0iMzE1IiBzcmM9Imh0dHA6Ly93d3cueW91dHViZS5jb20vZW1iZWQvTXgxQ3kzc21ScjAiIGZyYW1lYm9yZGVyPSIwIiBhbGxvd2Z1bGxzY3JlZW4%PC9pZnJhbWU%PC9wPg0KPHA%V2FsbGl0IGEgcsOpY2VtbWVudCBsZXbDqSAxLjJNJCBkZSBmb25kcyBhdXByw6hzIGRlIGRpZmbDqXJlbnRzIGJ1c2luZXNzIGFuZ2VscyBldCBmb25kcyBk4oCZaW52ZXN0aXNzZW1lbnRzLCBldCBkZXMgdmVyc2lvbnMgaVBhZCBldCBBbmRyb2lkIHNvbnQgZW4gY291cnMgZGUgZMOpdmVsb3BwZW1lbnQuIElsIHPigJlhZ2lyYSBlbnN1aXRlIGRlIG1vbsOpdGlzZXIgbGUgcHJvamV0IGVuIGltcGxpcXVhbnQgZGVzIHBhcnRlbmFpcmVzIGV0IGRlcyBncmFuZGVzIG1hcnF1ZXMsIG5vdGFtbWVudCBlbiBsZXMgYWlkYW50IMOgIGNyw6llciBsZXVycyBwcm9wcmVzIG11cnMvcGFubmVhdXggZGUgcHViIGludGVyYWN0aWZzIGV0IHZpcnR1ZWxzLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3dhbGxpdC1jcmVlLWRlcy1tdXJzLXZpcnR1ZWxzLWVuLXJlYWxpdGUtYXVnbWVudGVlLWRhbnMtbGVzLWxpZXV4LXB1YmxpY3MvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%NDwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPlNjaWVudGlwb2xlIEluaXRpYXRpdmUgZsOqdGUgc2VzIDEwIGFuczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPk1vbiwgMjYgTWFyIDIwMTIgMDk6MTg6MjYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc2NpZW50aXBvbGUgaW5pdGlhdGl2ZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4NDE8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc2NpZW50aXBvbGUucG5nIj48aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODQ1IiB0aXRsZT0ic2NpZW50aXBvbGUiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3NjaWVudGlwb2xlLnBuZyIgYWx0PSIiIHdpZHRoPSIzNzciIGhlaWdodD0iOTEiIC8%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICENCl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9zY2llbnRpcG9sZS5wbmciPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4NDUiIHRpdGxlPSJzY2llbnRpcG9sZSIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc2NpZW50aXBvbGUucG5nIiBhbHQ9IiIgd2lkdGg9IjM3NyIgaGVpZ2h0PSI5MSIgLz48L2E%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICE8L3A%DQo8cD5MZSBwcsOqdCBk4oCZaG9ubmV1ciBlc3QgdW4gcHLDqnQgw6AgdGF1eCAwIHF1ZSBwZXV0IHJlY2V2b2lyIHRvdXQgY3LDqWF0ZXVyIGTigJllbnRyZXByaXNlLCBzYW5zIGdhcmFudGllIHBlcnNvbm5lbGxlIGV0IGRvbnQgbGUgbW9udGFudCBwZXV0IGFsbGVyIGp1c3F14oCZw6AgNjAgMDAwIGV1cm9zIHBhciBlbnRyZXByaXNlLiBM4oCZb2JqZWN0aWYgZHUgcHLDqnQgZOKAmWhvbm5ldXIgZXN0IGTigJlhbW9yY2VyIGxhIGNvbW1lcmNpYWxpc2F0aW9uIGTigJl1biBwcm9kdWl0IG91IGTigJl1bmUgdGVjaG5vbG9naWUgZW4gdnVlIGTigJl1biBlZmZldCBkZSBsZXZpZXIgcG91ciBs4oCZb2J0ZW50aW9uIGRlIHByw6p0cyBiYW5jYWlyZXMuPC9wPg0KPHA%UG91ciBwcsOpdGVuZHJlIMOgIGNlIHR5cGUgZGUgcHLDqnQsIGwmIzgyMTc7ZW50cmVwcmlzZSBkb2l0IGF2b2lyIG1vaW5zIGRlIDMgYW5zLCDDqnRyZSBpbnN0YWxsw6llIGVuIElsZSBkZSBGcmFuY2UsIHByb3Bvc2VyIHVuZSBpbm5vdmF0aW9uLCBldCBwb3Nzw6lkZXIgdW4gcG90ZW50aWVsIGRlIGNyw6lhdGlvbnMgZCYjODIxNztlbXBsb2lzLjwvcD4NCjxwPlBvdXIgZsOqdGVyIHNhIDEww6htZSBhbm7DqWUgZGUgc291dGllbiBhdXggc3RhcnQgdXAsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIG9yZ2FuaXNlIHVuIMOpdsOobmVtZW50IGRlIDE0aCDDoCAxOWggbGUgMjggTWFycyDDoCBs4oCZaMO0dGVsIGRlIHZpbGxlIGRlIFBhcmlzLiBMZSA8YSBocmVmPSJodHRwOi8vd3d3LjEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnL3Byb2dyYW1tZS5odG1sIj5wcm9ncmFtbWU8L2E%IGFubm9uY2UgbGEgdmVudWUgZGUgUmFvdWwgTWFsbGFydCwgRGlyZWN0ZXVyIEJ1c2luZXNzIERldmVsb3BwZW1lbnQgZCYjODIxNztBcmNob3MsIG91IGVuY29yZSBkZSBSYWZpIEhhbGFkamlhbiwgZm9uZGF0ZXVyIGRlIE5hYmF6dGFnLiBMZXMgaW5zY3JpcHRpb25zIHNvbnQgPGEgaHJlZj0iaHR0cDovL3d3dy4xMGFucy1zY2llbnRpcG9sZS1pbml0aWF0aXZlLm9yZy9pbnNjcmlwdGlvbi5odG1sIj5pY2k8L2E%IGV0IGwmIzgyMTc7YWN0dWFsaXTDqSBkdSBTY2llbnRpcG9sZSBlc3QgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9TY2llbnRJbml0aWF0aXYiPmzDoC4gPC9hPjwvcD4NCjxwPjxpZnJhbWUgd2lkdGg9IjU2MCIgaGVpZ2h0PSIzMTUiIHNyYz0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9lbWJlZC9DcVYwVW82SDFiVSIgZnJhbWVib3JkZXI9IjAiIGFsbG93ZnVsbHNjcmVlbj48L2lmcmFtZT48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNi9zY2llbnRpcG9sZS1pbml0aWF0aXZlLWZldGUtc2VzLTEwLWFucy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%VENGUiDigJMgTGUgemFwcGluZyBkZSBsYSBzZW1haW5lPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAyMyBNYXIgMjAxMiAxODoyNDozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%Q2VkcmljIE8nTmVpbGw8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3RhcnR1cF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0Y2ZyXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3phcHBpbmddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODMyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMS9icmVmLmpwZyIgYWx0PSIiIHdpZHRoPSIyNDUiIGhlaWdodD0iMTgzIiAvPi0gTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQnYXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuDQoNCi0gQW50b2luZSBWaWFsbGUsIHNlcmlhbCBlbnRyZXByZW5ldXIgdmllbnQgZGUgY2FydG9ncmFwaGllciBsZXMgYWlkZXMgZXQgc3VidmVudGlvbnMgZGlzcG9uaWJsZXMgZW4gRnJhbmNlIHBvdXIgbGVzIGNyw6lhdGV1cnMgZCdlbnRyZXByaXNlLiBDaGFxdWUgbGlnbmUgY29ycmVzcG9uZCBhdSBuaXZlYXUgZGUgbWF0dXJpdMOpIGQndW5lIHNvY2nDqXTDqS4gVm91cyBwb3VycmV6IGxhIHJldHJvdXZlciDDoCA8YSBocmVmPSJodHRwOi8vd3d3LmFpZGVzLWNyZWF0aW9uLmZyL29mZnJlLXNwZWFjdXRlY2lhbGUtaW50ZXJuZXQuaHRtbCI%Y2V0dGUgYWRyZXNzZTwvYT4uXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMS9icmVmLmpwZyIgYWx0PSIiIHdpZHRoPSIyNDUiIGhlaWdodD0iMTgzIiAvPi0gTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQmIzgyMTc7YXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuPC9wPg0KPHA%LSBBbnRvaW5lIFZpYWxsZSwgc2VyaWFsIGVudHJlcHJlbmV1ciB2aWVudCBkZSBjYXJ0b2dyYXBoaWVyIGxlcyBhaWRlcyBldCBzdWJ2ZW50aW9ucyBkaXNwb25pYmxlcyBlbiBGcmFuY2UgcG91ciBsZXMgY3LDqWF0ZXVycyBkJiM4MjE3O2VudHJlcHJpc2UuIENoYXF1ZSBsaWduZSBjb3JyZXNwb25kIGF1IG5pdmVhdSBkZSBtYXR1cml0w6kgZCYjODIxNzt1bmUgc29jacOpdMOpLiBWb3VzIHBvdXJyZXogbGEgcmV0cm91dmVyIMOgIDxhIGhyZWY9Imh0dHA6Ly93d3cuYWlkZXMtY3JlYXRpb24uZnIvb2ZmcmUtc3BlYWN1dGVjaWFsZS1pbnRlcm5ldC5odG1sIj5jZXR0ZSBhZHJlc3NlPC9hPi48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cueW91c2VlbWlpLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPllvdXNlZW1paSA8L2E%cHLDqXNlbnRlIHNhIG5vdXZlbGxlIHZlcnNpb24sIGF2ZWMgdW4gbm91dmVhdSBkZXNpZ24sIGV0IHN1cnRvdXQgdW5lIG5vdXZlbGxlIGV4cMOpcmllbmNlIHV0aWxpc2F0ZXVyLiBEw6lzb3JtYWlzLCBsZSBsb2dpY2llbCBwZXJtZXQgYXVzc2kgZCYjODIxNzthbmFseXNlciBzYSBwcsOpc2VuY2Ugd2ViIHN1ciBGb3Vyc3F1YXJlLCBHb29nbGUgKywgRGFpbHltb3Rpb24sIFZpbWVvLCBldCBtw6ptZSBhdXByw6hzIGRlcyBraW9zcXVlcyBSZWxheS48L3A%DQo8cD4tTGUgcsOpc2VhdSBzb2NpYWwgbW9iaWxlIDxhIGhyZWY9Imh0dHBzOi8vcGF0aC5jb20vIj5QYXRoPC9hPiBsw6h2ZSAyMCBtaWxsaW9ucyBkZSBkb2xsYXJzLiBMZSByw6lzZWF1IHNvY2lhbCBkZSBwYXJ0YWdlIGRlIHBob3RvcyBsaW1pdMOpIMOgIDUwIGNvbnRhY3RzIGV0IGRpc3BvbmlibGUgZXhjbHVzaXZlbWVudCBzdXIgbOKAmWFwcGxpIGlQaG9uZSBkdSBtw6ptZSBub20gc2VyYWl0IGFpbnNpIHZhbG9yaXPDqSAyNTBNJC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmVkeWNhc2EuY29tLyI%QmVkeUNhc2E8L2E%IGdhZ25lIGxlcyBUcmF2ZWwgZOKAmU9yIGRhbnMgbGEgY2F0w6lnb3JpZSBzdGFydC11cCwgcXVpIHLDqWNvbXBlbnNlIGxlcyBtZWlsbGV1cnMgc2l0ZXMgZOKAmWUtdG91cmlzbWUuIEJlZHljYXNhLCBwZXJtZXQgbGEgbG9jYXRpb24gZGUgY2hhbWJyZXMgY2hleiBs4oCZaGFiaXRhbnQuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHBzOi8vc2Vlc21pYy5jb20vIj5TZWVzbWljPC9hPiBhbm5vbmNlIHVuZSB2YWd1ZSBkZSBsaWNlbmNpZW1lbnRzLiBMYSBzdGFydC11cCBmb25kw6llIHBhciA8c3Ryb25nPkxvw69jIExlIE1ldXI8L3N0cm9uZz4sIG9yZ2FuaXNhdGV1ciBkZSBsYSBjb25mw6lyZW5jZSA8c3Ryb25nPkxlV2ViPC9zdHJvbmc%IGRldnJhaXQgbGljZW5jaWVyIDE4IHBlcnNvbm5lcyBmYXV0ZSBkZSBidXNpbmVzcyBtb2RlbCB2aWFibGUuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHA6Ly93d3cuZWFzeS12ZXJyZXMuY29tLyI%RWFzeS12ZXJyZXM8L2E%LCBs4oCZb3B0aWNpZW4gbG93IGNvc3QgcXVpIGNvbXB0ZXJhaXQgcHLDqHMgZGUgNzUwIG9wdGljaWVucyBwYXJ0ZW5haXJlcyB2aWVudCBkZSBsZXZlciAxTeKCrC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuaWxsaWNvdHJhdmVsLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5pbGxpY290cmF2ZWw8L2E%LCBsZSBjb21wYXJhdGV1ciBkZSB2b2xzIGV0IGRlIHZveWFnZXMgb25saW5lIHZpZW50IGRlIGxhbmNlciB1bmUgbm91dmVsbGUgdmVyc2lvbiBkZSBzb24gaW50ZXJmYWNlLjwvcD4NCjxwPi08c3Ryb25nPiA8YSBocmVmPSJodHRwOi8vd3d3LnJveWFsY2FjdHVzLmNvbS8iPlJveWFsIENhY3R1czwvYT48L3N0cm9uZz4sIHNww6ljaWFsaXN0ZSBkdSBqZXUgZW4gbGlnbmUgY29tbXVuYXV0YWlyZSwgdmllbnQgZGUgbGV2ZXIgNTAwIDAwMCBldXJvcyBhdXByw6hzIGR1IGZvbmRzIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnQgPHN0cm9uZz5YQW5nZSBQcml2YXRlIEVxdWl0eTwvc3Ryb25nPi4gT2JqZWN0aWYgYWZmaWNow6kgOiBkZXZlbmlyIHVuIGRlcyBsZWFkZXJzIGZyYW7Dp2FpcyBkdSBTb2NpYWwgR2FtaW5nIGVuIG1lbmFudCB1bmUgc3RyYXTDqWdpZSBjcm9zcy1jaGFubmVsLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzIzL3RjZnItJWUyJTgwJTkzLWxlLXphcHBpbmctZGUtbGEtc2VtYWluZS0yL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgk8L2NoYW5uZWw%DQo8L3Jzcz4NCg"},{ name : "feed1", data : "s69026:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPlRlY2hDcnVuY2ggRnJhbmNlPC90aXRsZT4NCgk8YXRvbTpsaW5rIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS9mZWVkLyIgcmVsPSJzZWxmIiB0eXBlPSJhcHBsaWNhdGlvbi9yc3MreG1sIiAvPg0KCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbTwvbGluaz4NCgk8ZGVzY3JpcHRpb24%SnVzdCBhbm90aGVyIFdvcmRQcmVzcyBzaXRlPC9kZXNjcmlwdGlvbj4NCgk8bGFzdEJ1aWxkRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE0OjM3OjE3ICswMDAwPC9sYXN0QnVpbGREYXRlPg0KDQoJPGxhbmd1YWdlPmVuPC9sYW5ndWFnZT4NCgk8c3k6dXBkYXRlUGVyaW9kPmhvdXJseTwvc3k6dXBkYXRlUGVyaW9kPg0KCTxzeTp1cGRhdGVGcmVxdWVuY3k%MTwvc3k6dXBkYXRlRnJlcXVlbmN5Pg0KCTxnZW5lcmF0b3I%aHR0cDovL3dvcmRwcmVzcy5vcmcvP3Y9My4wPC9nZW5lcmF0b3I%DQoJCTxpdGVtPg0KCQk8dGl0bGU%UXVhbmQgbGVzIGZyw6hyZXMgU2Ftd2VyIHBhcnRlbnQgZW4gZ3VlcnJlJiM4MjMwOzwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L3F1YW5kLWxlcy1mcmVyZXMtc2Ftd2VyLXBhcnRlbnQtZW4tZ3VlcnJlLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L3F1YW5kLWxlcy1mcmVyZXMtc2Ftd2VyLXBhcnRlbnQtZW4tZ3VlcnJlLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPldlZCwgMjggTWFyIDIwMTIgMTY6MzM6MjQgKzAwMDA8L3B1YkRhdGU%DQoNCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYmxpZXR6a3JpZWddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZ3VlcnJlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3NhbXdlcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4Mzg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQiIHRpdGxlPSJyb2NrZXQgaW50ZXJuZXQiIHNyYz0iaHR0cDovL3d3dy5qb2JzcGlub3kuY29tL3VwbG9hZF9maWxlcy9pbWFnZXMvNy9jLzUvN2M1ZjkzZjcwYzQ4NWExMzgxYmI5YzMxMjIzYjA4ZDkuanBnIiBhbHQ9IiIgd2lkdGg9IjM2MCIgaGVpZ2h0PSI5MCIgLz4NClRyYWR1Y3Rpb24gZXQgYWRhcHRhdGlvbiBkJ3VuIDxhIGhyZWY9Imh0dHA6Ly90ZWNoY3J1bmNoLmNvbS8yMDExLzEyLzIyL2luLWNvbmZpZGVudGlhbC1lbWFpbC1zYW13ZXItZGVzY3JpYmVzLW9ubGluZS1mdXJuaXR1cmUtc3RyYXRlZ3ktYXMtYS1ibGl0emtyaWVnLyAgIj5hcnRpY2xlIDwvYT5kZSBNaWtlIEJ1dGNoZXIuDQoNClJvY2tldCBJbnRlcm5ldCwgbGUgZm9uZHMgZGVzIGZyw6hyZXMgU2Ftd2VyLCB2aWVudCBkZSBzZSBsYW5jZXIgZW4gRnJhbmNlLCBldCBjZXJ0YWlucyB2b250IGNlcnRhaW5lbWVudCBlbiBmYWlyZSBsZXMgZnJhaXMuIFBvdXIgdm91cyBlbiBkb25uZXIgdW4gYXBlcsOndSwgdm9pY2kgbGEgdHJhZHVjdGlvbiBkJ3VuIGUtbWFpbCBjb25maWRlbnRpZWwgZW52b3nDqSBwYXIgT2xpdmVyIFNhbXdlciDDoCBzZXMgw6lxdWlwZXMsIGRhbnMgbGVxdWVsIGlsIHV0aWxpc2UgbGUgbW90IMKrIEJsaXR6a3JpZWcgwrsgcG91ciBkw6ljcmlyZSBzYSBzdHJhdMOpZ2llIGRlIHZlbnRlIGRlIG1ldWJsZXMgZW4gbGlnbmUuDQpdXT48L2Rlc2NyaXB0aW9uPg0KDQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9InJvY2tldCBpbnRlcm5ldCIgc3JjPSJodHRwOi8vd3d3LmpvYnNwaW5veS5jb20vdXBsb2FkX2ZpbGVzL2ltYWdlcy83L2MvNS83YzVmOTNmNzBjNDg1YTEzODFiYjljMzEyMjNiMDhkOS5qcGciIGFsdD0iIiB3aWR0aD0iMzYwIiBoZWlnaHQ9IjkwIiAvPjxiciAvPg0KVHJhZHVjdGlvbiBldCBhZGFwdGF0aW9uIGQmIzgyMTc7dW4gPGEgaHJlZj0iaHR0cDovL3RlY2hjcnVuY2guY29tLzIwMTEvMTIvMjIvaW4tY29uZmlkZW50aWFsLWVtYWlsLXNhbXdlci1kZXNjcmliZXMtb25saW5lLWZ1cm5pdHVyZS1zdHJhdGVneS1hcy1hLWJsaXR6a3JpZWcvICAiPmFydGljbGUgPC9hPmRlIE1pa2UgQnV0Y2hlci48L3A%DQo8cD5Sb2NrZXQgSW50ZXJuZXQsIGxlIGZvbmRzIGRlcyBmcsOocmVzIFNhbXdlciwgdmllbnQgZGUgc2UgbGFuY2VyIGVuIEZyYW5jZSwgZXQgY2VydGFpbnMgdm9udCBjZXJ0YWluZW1lbnQgZW4gZmFpcmUgbGVzIGZyYWlzLiBQb3VyIHZvdXMgZW4gZG9ubmVyIHVuIGFwZXLDp3UsIHZvaWNpIGxhIHRyYWR1Y3Rpb24gZCYjODIxNzt1biBlLW1haWwgY29uZmlkZW50aWVsIGVudm95w6kgcGFyIE9saXZlciBTYW13ZXIgw6Agc2VzIMOpcXVpcGVzLCBkYW5zIGxlcXVlbCBpbCB1dGlsaXNlIGxlIG1vdCDCqyBCbGl0emtyaWVnIMK7IHBvdXIgZMOpY3JpcmUgc2Egc3RyYXTDqWdpZSBkZSB2ZW50ZSBkZSBtZXVibGVzIGVuIGxpZ25lLjwvcD4NCjxwPlJvY2tldCBpbnRlcm5ldCwgbOKAmWluY3ViYXRldXIgYmVybGlub2lzIGNvbm51IHBvdXIgbGVzIHZlcnNpb25zIGFsbGVtYW5kZXMgZGUgc3RhcnR1cHMgYW3DqXJpY2FpbmVzIGNvbW1lIFphcHBvcyBldCBHcm91cG9uLCBhIG1haW50ZW5hbnQgZGUgZ3JhbmRlcyBhbWJpdGlvbnMsIHN1cnRvdXQgZGFucyBsZSBzZWN0ZXVyIGR1IG1ldWJsZSBlbiBsaWduZSwgc2Vsb24gZGVzIGluZm9ybWF0aW9ucyBkb25uw6llcyDDoCBUZWNoQ3J1bmNoIEV1cm9wZS48L3A%DQo8cD5EYW5zIHVuIGUtbWFpbCBjb25maWRlbnRpZWwgZW52b3nDqSBwYXIgT2xpdmVyIFNhbXdlciAocXVpIGRpcmlnZSBsZSBmb25kcyBhdmVjIHNlcyBmcsOocmVzIE1hcmMgZXQgQWxleGFuZGVyKSwgaWwgZMOpY2xhcmUgcXVlIGxldXIgc3RyYXTDqWdpZSBlc3QgZGUgZGV2ZW5pciBsZSDCqyBudW3DqXJvIHVuIMK7IGR1IGUtY29tbWVyY2UgZGUgbWV1YmxlcyBkYW5zIGxlcyBwcm9jaGFpbmVzIGFubsOpZXMuIE1haXMgbGUgbGFuZ2FnZSB1dGlsaXPDqSBjb21tZSBsZSBtb3QgwqtibGl0emtyaWVnwrsgbW9udHJlIHVuIHR5cGUgZGUgbWFuYWdlbWVudCB0csOocyBhZ3Jlc3NpZiwgcXVpIG5lIGxhaXNzZSBhdWN1bmUgcGxhY2UgYXV4IHNlbnRpbWVudHMsIGV0IHF1aSBhcHBhcmHDrnQgY29tbWUgw6l0YW50IHVuIOKAmW1vZHVzIG9wZXJhbmRp4oCZIGRlIGxhIGN1bHR1cmUgZGUgUm9ja2V0IChsZSBub20gbiYjODIxNzthIGQmIzgyMTc7YWlsbGV1cnMgcGFzIMOpdMOpIGNob2lzaSBwYXIgaGFzYXJkKS4gU2Ftd2VyIHPigJllc3QgZGVwdWlzIGV4Y3Vzw6kgZOKAmWF2b2lyIHV0aWxpc8OpIGNlcyB0ZXJtZXMuPC9wPg0KPHA%RGFucyBs4oCZZS1tYWlsLCDDqWNyaXQgZGFucyB1biBhbmdsYWlzIGjDqXNpdGFudCwgT2xpdmVyIFNhbXdlciBkaXQgw6Agc29uIMOpcXVpcGUgY2hleiBSb2NrZXQgcXXigJlpbCB5IGEgc2V1bGVtZW50IDMgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIHBvdXIgY3LDqWVyIHVuZSBlbnRyZXByaXNlIGRlIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzIDo8L3A%DQo8cD4mIzgyMjE7IDxlbT5O4oCZb3VibGlleiBqYW1haXMgcXXigJlpbCBu4oCZeSBhIHF1ZSBkZXV4IGdyb3Mgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIDogQW1hem9uIGV0IFphcHBvcy4gQ%KAmWVzdCBsYSBkZXJuacOocmUgY2hhbmNlIGRlIHZvdHJlIHZpZSA6IGxhIGNoYW5jZSBwb3VyIHVuZSBhdXRyZSBlbnRyZXByaXNlIGRlIGUtY29tbWVyY2UgZGUgdmFsb2lyIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzLCB1bmUgY2hhbmNlIHF1aSBuZSBzZSByZXByw6lzZW50ZXJhIHBsdXMgITxiciAvPg0KQ%KAmWVzdCB0ZXJtaW7DqSwgYXByw6hzIEFtYXpvbiBpbCBuJiM4MjE3O3kgYSBxdWUgWmFwcG9zLCBkb25jIG9uIG5lIHBldXQgcGFzIHJhdGVyIGNldHRlIG9jY2FzaW9uLCBzaW5vbiB2b3MgcGV0aXRzLWVuZmFudHMgdm91cyBkZW1hbmRlcm9udCB0b3V0ZSB2b3RyZSB2aWUgcG91cnF1b2kgdm91cyBuZSBsJiM4MjE3O2F2ZXogcGFzIGZhaXQgPC9lbT7Cuy48L3A%DQo8cD5BaW5zaSwgaWwgZGl0IMOgIHNvbiDDqXF1aXBlIDogwqsgPGVtPlZvdXMgZGV2ZXogdG91dCBhbnRpY2lwZXI8L2VtPjxlbT4gZGFucyB2b3RyZSBwbGFuIHBvdXIgcXXigJlpbCBu4oCZeSBhaXQgcGFzIGRlIHN1cnByaXNlLiBKZSBu4oCZYWNjZXB0ZSBwYXMgbGVzIHN1cnByaXNlcy4gSmUgdmV1eCBxdWUgdG91dCBzb2l0IHZhbGlkw6kgZXQgdsOpcmlmacOpIDwvZW0%PGVtPnBhciB2b3VzIHRyb2lzIGZvaXM6IHZvdXMgZGV2ZXogbGUgc2lnbmVyIGF2ZWMgdm90cmUgc2FuZzwvZW0%LiDCuywgZXQgYWpvdXRlIDogwqs8ZW0%IEplIG5lIGZlcmFpIHF14oCZdW4gcGxhbiBhdXF1ZWwgdm91cyBjcm9pcmV6IMOgIDEwMCUgZXQgcXVpIHNlcmEgc2lnbsOpIGF2ZWMgZHUgc2FuZzwvZW0%wrsuPC9wPg0KPHA%SWwgcHLDqWNpc2Ugw6lnYWxlbWVudCBxdWUgY2VydGFpbnMgbWFuYWdlcnMgcXXigJlpbCBlbXBsb3lhaXQgZXQgcXVpIG7igJlvbnQgcGFzIGZhaXQgdG91dCBjZWxhLCBsdWkgb250IGZhaXJlIHBlcmRyZSDCqyBiZWF1Y291cCBk4oCZYXJnZW50IMK7IGV0IHF1ZSDCqyBjZXMgbWFuYWdlcnMgb250IHBlcmR1IDUwJSBkZSBsZXVyIGNhcGl0YWwgwrsgZXQgbuKAmW9udCDCqyBwYXMgZXUgZGUgc2FsYWlyZSBwZW5kYW50IDYgbW9pcy4gwrs8L3A%DQo8cD5MJiM4MjE3O2UtbWFpbCBwcmVuZCB1biB0b24gcGx1cyBjb250cm92ZXJzw6ksIHN1cnRvdXQgcG91ciB1biBidXNpbmVzc21hbiBjb21tZSBsdWksIGxvcnNxdSYjODIxNztpbCB1dGlsaXNlIGxlIGxhbmdhZ2UgZGUgbGEgc2Vjb25kZSBndWVycmUgbW9uZGlhbGUgOiDCqyA8ZW0%TGEgY2hvc2Ugw6AgbGFxdWVsbGUgbm91cyBkZXZvbnMgZmFpcmUgbGUgcGx1cyBhdHRlbnRpb24sIGMmIzgyMTc7ZXN0IHF1ZSBub3VzIGRldm9ucyBiaWVuIGNob2lzaXIgbGUgbW9tZW50IHBvdXIgbGEgQmxpdHprcmllZywgYWZpbiBxdWUgY2hhcXVlIHBheXMgbWUgZGlzZSBhdmVjIHNvbiBzYW5nIHF1YW5kIGPigJllc3QgbGUgYm9uIG1vbWVudC4gSmUgc2VyYWkgcHLDqnQg4oCTIG7igJlpbXBvcnRlIHF1YW5kICE8L2VtPiDCuzwvcD4NCjxwPsKrIEJsaXR6a3JpZWcgwrsgw6l0YWl0IGJpZW4gw6l2aWRlbW1lbnQgdW4gdGVybWUgdXRpbGlzw6kgcGFyIGxlcyBtaWxpdGFpcmVzIGFsbGVtYW5kcyBwb3VyIGTDqWNyaXJlIGxldXIgdGFjdGlxdWUgZGUgZMOpcGxhY2VtZW50IHJhcGlkZSwgc29pdCB1bmUgwqsgR3VlcnJlIMOpY2xhaXIgwrsuIExhIHNvdXJjZSBiaWVuIHBsYWPDqWUgcXVpIG5vdXMgYSBmYWl0IHN1aXZyZSBjZXQgZS1tYWlsIG5vdXMgZGl0IDogwqsgU2FtdWVsIGVzdCBjb25udSBwb3VyIHV0aWxpc2VyIGRlcyB0ZXJtZXMgbWlsaXRhaXJlcywgYXV0YW50IHF1ZSBkZSBub21icmV1eCB0ZXJtZXMgZGUgbGFuZ2FnZSBvYnNjw6huZXMsIGFsb3JzIGNlIGdlbnJlIGRlIOKAmG1vdGl2YXRpb27igJkgZXN0IGFzc3Vyw6ltZW50IGxlIOKAmHN0eWxlIGTigJlPbGxpIFNhbXdlcuKAmS4gSmUgbmUgY29ubmFpcyBwYXMgdW4gc2V1bCBhdXRyZSBidXNpbmVzc21hbiB1dGlsaXNhbnQgdW4gdGVsIGxhbmdhZ2UgwrsuPC9wPg0KPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0ic2Ftd2VyIiBzcmM9Imh0dHA6Ly93d3cuY3J1bmNoYmFzZS5jb20vYXNzZXRzL2ltYWdlcy9yZXNpemVkLzAwMDYvMjEzNy82MjEzN3YxLW1heC0yNTB4MjUwLmpwZyIgYWx0PSIiIHdpZHRoPSIyNTAiIGhlaWdodD0iMTA1IiAvPjwvcD4NCjxwPjxzdHJvbmc%UsOpc3Vtw6kgZGUgbCYjODIxNztlLW1haWwgPC9zdHJvbmc%OiAmIzgyMjA7PGVtPkplIHZvdXMgZG9ubmUgdG91dCBs4oCZYXJnZW50IGRvbnQgdm91cyBhdXJleiBiZXNvaW4gcG91ciBnYWduZXIsIGplIHZvdXMgZG9ubmUgdG91dGUgbWEgY29uZmlhbmNlLCBtYWlzIHZvdXMgZGV2ZXogcmV2ZW5pciB2ZXJzIG1vaSBhdmVjIHVuIHN1Y2PDqHMgaW7DqWdhbMOpLiBTaSBqZSB2b2lzIHF1ZSB2b3VzIGdhc3BpbGxleiBtb24gYXJnZW50LCBxdWUgdm91cyBu4oCZw6p0ZXMgcGFzIGNvbmNlbnRyw6lzIHN1ciBsZSBkw6l0YWlsIGNvbW1lIHVuIGFsbGVtYW5kLCBxdWUgdm91cyBu4oCZw6p0ZXMgcGFzIHJhcGlkZXMsIHF1ZSB2b3VzIG7igJnDqnRlcyBwYXMgYWdyZXNzaWZzLCBxdWUgdm91cyBuZSBzdWl2ZXogcGFzIGxlcyBpbmZvcm1hdGlvbnMsIHF1ZSB2b3VzIG7igJllZmZlY3R1ZXogcGFzIGxhIGxvZ2lzdGlxdWUgZGUgbGEgYm9ubmUgZmHDp29uLCBxdWUgdm91cyBuZSBtZXR0ZXogcGFzIHJhcGlkZW1lbnQgZW4gbGlnbmUgbGVzIHByb2R1aXRzLCBvdSBxdWUgdm91cyBhY2hldGV6IGRlIG1hdXZhaXNlcyBtYXJjaGFuZGlzZXMsIGFsb3JzIGplIG1lIG1ldHRyYWlzIGVuIGNvbMOocmUgZXQgamUgZmVyYWlzIGNvbW1lIGVuIFJ1c3NpZSwgb8O5IGFjdHVlbGxlbWVudCBhdWN1biBkZXMgbWFuYWdlcnMgbmUgZGlyaWdlIGwmIzgyMTc7ZW50cmVwcmlzZS4gSuKAmWFpIHBlcmR1IGJlYXVjb3VwIGTigJlhcmdlbnQgZXQgbGVzIGZvbmRhdGV1cnMgb250IHBlcmR1IDUwJSBkZSBsZXVyIGNhcGl0YWwuIEF1Y3VuIHNhbGFpcmUgbuKAmWEgcGx1cyDDqXTDqSB2ZXJzw6kgcGVuZGFudCA2IG1vaXMuIE5vdXMgc29tbWVzIGRhbnMgbGUgbcOqbWUgYmF0ZWF1LCB0b3V0IGxlIG1vbmRlIGRvaXQgZWZmZWN0dWVyIHNhIG1pc3Npb24uPC9lbT48L3A%DQo8cD48ZW0%Tm91cyBhcnJpdm9ucyB0YXJkLCBhbG9ycyBub3VzIGF2b25zIGJlc29pbiBk4oCZw6p0cmUgbGVzIHBsdXMgYWdyZXNzaWZzLiBUZWxsZW1lbnQgYWdyZXNzaWZzIHF1ZSBjaGFxdWUgY29uY3VycmVudCBzZXJhIHN1cnByaXMgcGFyY2UgcXXigJlpbCBuZSBwb3V2YWl0ICBpbWFnaW5lciBxdWUgbm91cyBzZXJpb25zIHNpIGFncmVzc2lmcy4gUG91ciB2b3VzIGRvbm5lciB1biBleGVtcGxlIGF1IEJyw6lzaWwgYXZlYyBHcm91cG9uIDogbW9uIGNvbmN1cnJlbnQgcsOpYWxpc2FpdCB0cm9pcyBtaWxsaW9ucyBwYXIgbW9pcyBldCBhdmFpdCA4MCB2ZW5kZXVycy4gIErigJlhaSBzdXBwb3PDqSBxdeKAmWVuIDQgbW9pcyBpbCBpcmFpdCBqdXNxdeKAmcOgIDMwMCB2ZW5kZXVycyBldCA2IG1pbGxpb25zLCBhbG9ycyBq4oCZYWkgZGl0IMOgIGzigJnDqXF1aXBlIGRlIHByZW5kcmUgNTAwIHZlbmRldXJzIGVuIDQgbW9pcywgZXQgMTAgbWlsbGlvbnMgZGUgY2hpZmZyZSBkJiM4MjE3O2FmZmFpcmVzIGVuIG9udCBkw6ljb3Vsw6lzLiBOb3VzIGF2b25zIGdhZ27DqS4gT3VpLCBpbCB5IGEgZXUgZGVzIGRvbW1hZ2VzIGNvbGxhdMOpcmF1eCAoY2VsYSBhdXJhaXQgw6l0w6kgbW9pbnMgY2hlciBhdmVjIHBsdXMgZGUgdGVtcHMpLCBtYWlzIGrigJlhaSBnYWduw6kgZXQgY%KAmWVzdCB0b3V0IGNlIHF1aSBjb21wdGUuIEomIzgyMTc7YWkgYWxvcnMgcHUgcsOpY29sdGVyIGRlIGzigJlhcmdlbnQgZXQgb3B0aW1pc2VyIGxlcyBsYWN1bmVzLjwvZW0%PC9wPg0KPHA%PGVtPkZvdXJuaXNzZXogdW4gcGxhbiBwb3VyIGNlIHdlZWstZW5kIHF1aSBjb21wcmVuZCB0b3V0ZXMgdm9zIHJlY29tbWFuZGF0aW9ucywgcGVuc2V6IHkgcGFyY2UgcXVlIGplIHBldXggdm91cyBkb25uZXIgbOKAmWFyZ2VudCwgbGUgc2F2b2lyLWZhaXJlLCBsYSBzdHJhdMOpZ2llLCBtYWlzIGplIG5lIGZlcmFpIHF14oCZdW4gcGxhbiBhdXF1ZWwgdm91cyBjcm9pcmV6IMOgIDEwMCUgZXQgcXVpIHNlcmEgc2lnbsOpIGF2ZWMgZHUgc2FuZy4gQ2UgbuKAmWVzdCBwYXMgbGUgcGxhbiBkJiM4MjE3O09saSwgw6dhIGRvaXQgw6p0cmUgdm90cmUgcGxhbiwgbm90cmUgcGxhbi48L2VtPjwvcD4NCjxwPjxlbT5O4oCZb3VibGlleiBqYW1haXMgcXXigJlpbCBu4oCZeSBhIHF1ZSBkZXV4IGdyb3Mgc2VjdGV1cnMgZGFucyBsZSBlLWNvbW1lcmNlIDogQW1hem9uIGV0IFphcHBvcy4gQ%KAmWVzdCBsYSBkZXJuacOocmUgY2hhbmNlIGRlIHZvdHJlIHZpZSA6IGxhIGNoYW5jZSBwb3VyIHVuZSBhdXRyZSBlbnRyZXByaXNlIGRlIGUtY29tbWVyY2UgZGUgdmFsb2lyIHBsdXNpZXVycyBtaWxsaWFyZCBkZSBkb2xsYXJzLCB1bmUgY2hhbmNlIHF1aSBuZSBzZSByZXByw6lzZW50ZXJhIHBsdXMgISBD4oCZZXN0IHRlcm1pbsOpLCBhcHLDqHMgQW1hem9uIHZpZW50IHNldWxlbWVudCBaYXBwb3MsIGRvbmMgb24gbmUgcGV1dCBwYXMgcmF0ZXIgw6dhLiBQYXJjZSBxdWUgc2lub24gdm9zIHBldGl0cy1lbmZhbnRzIHZvdXMgZGVtYW5kZXJvbnQgdG91dGUgdm90cmUgdmllIHBvdXJxdW9pIHZvdXMgbmUgbCYjODIxNzthdmV6IHBhcyBmYWl0LiA8L2VtPjwvcD4NCjxwPjxlbT5TdXJwcmVuZXotbW9pIGF2ZWMgdm90cmUgYWdyZXNzaXZpdMOpLCBzb3lleiBpbnRlbGxpZ2VudHMgZXQgcGVuc2V6ICBkZSBtYW5pw6hyZSBhZ3Jlc3NpdmUg4oCTIGFwcHJlbmV6IGRlcyBlcnJldXJzIGRlcyBydXNzZXMgZXQgZGVzIGphcG9uYWlzLCBldCBkdSBzdWNjw6hzIGRlcyBhbGxlbWFuZHMgZXQgZGVzIGJyw6lzaWxpZW5zICE8L2VtPjwvcD4NCjxwPjxlbT5D4oCZZXN0IG5vdHJlIGRlcm5pw6hyZSBjaGFuY2UgZGFucyBsZSBlLWNvbW1lcmNlIGRlIGNvbnN0cnVpcmUgdW5lIGVudHJlcHJpc2UgY29tbWUgQW1hem9uLiBBcHLDqHMgbm91cywgdm91cyBwb3VycmV6IG1vbnRlciB1bmUgZW50cmVwcmlzZSBkZSBqZXV4IGVuIGxpZ25lLCBtYWlzIHBsdXMgcmllbiBlbiBlLWNvbW1lcmNlLiBD4oCZZXN0IGxhIERFUk5JRVJFIG9jY2FzaW9uIGRhbnMgdm90cmUgdmllIHBvdXIgdm91cyBsYW5jZXIgZGFucyBsZSBlLWNvbW1lcmNlIGV0IGplIHZldXggcXVlIHZvdXMgbWlzaWV6IHRvdXQgc3VyIGNldHRlIG9wcG9ydHVuaXTDqS4gUGFzIGF2ZWMgMjAlIG91IDMwJSwgbWFpcyBhdmVjIDgwJSBkZSBwYXJ0cyBkZSBtYXJjaMOpLCBjJiM4MjE3O2VzdCBwb3NzaWJsZSBkYW5zIG5vcyBwYXlzITwvZW0%PC9wPg0KPHA%PGVtPkplIHN1aXMgbGUgbWVjIGxlIHBsdXMgYWdyZXNzaWYgZCYjODIxNztpbnRlcm5ldCBzdXIgbGEgcGxhbsOodGUuIEplIG1vdXJyYWkgcG91ciBnYWduZXIgZXQgauKAmWVuIGF0dGVuZHMgZGUgbcOqbWUgZGUgdm90cmUgcGFydCAhJiM4MjIxOzwvZW0%PC9wPg0KPHA%JiM4MjExOzwvcD4NCjxwPklsIGVzdCBjbGFpciBxdWUgZGFucyBsZSBkb21haW5lIGRlcyBlbnRyZXByaXNlcyDDoCBmb3J0ZSBjcm9pc3NhbmNlIHN1ciBpbnRlcm5ldCwgbGVzIGluZGl2aWR1cyBwZXV2ZW50IHBhcmZvaXMgw6p0cmUgc3VyZXhjaXTDqXMgZXQgYWxsZXIgdHJvcCBsb2luLiBJY2ksIGxlIGxhbmdhZ2UgdXRpbGlzw6kgbWFucXVlIGNydWVsbGVtZW50IGRlIHRhY3QsIGPigJllc3QgdW4gZXVwaMOpbWlzbWUuIENvbnRhY3TDqSBwYXIgVGVjaENydW5jaCBFdXJvcGUgw6AgcHJvcG9zIGRlIGzigJllLW1haWwsIE9saXZlciBTYW13ZXIgYSBjb25maXJtw6kgcXXigJlpbCDDqXRhaXQgYmllbiBkZSBsdWksIGV0IGEgcsOpcG9uZHUgcGFyIGNldHRlIGTDqWNsYXJhdGlvbiA6PC9wPg0KPHA%wqsgPGVtPjxlbT5D4oCZw6l0YWl0IHVuIGUtbWFpbCBxdWUgauKAmWFpIGVudm95w6kgYXV4IG1lbWJyZSBk4oCZdW4gcHJvamV0IGTigJnDqXF1aXBlIGVuIG9jdG9icmUuIEF1IG1pbGlldSBkZSBtb24gZW50aG91c2lhc21lIGV0IGRlcyBpZMOpZXMgZGUgZMOpcGxvaWVtZW50IHJhcGlkZSwgauKAmWFpIHV0aWxpc8OpIGxlIHRlcm1lIHRvdGFsZW1lbnQgaW5hcHByb3ByacOpIGRlICYjODIyMDtCbGl0emtyaWVnJiM4MjIxOy4gSmUgc3VpcyBwcm9mb25kw6ltZW50IGTDqXNvbMOpIHBvdXIgY2VsYS4gSmUgbeKAmWV4Y3VzZSBhdXByw6hzIGRlIGNldXggcXVpIG9udCBwdSDDqnRyZSBvZmZlbnPDqXMgcGFyIGNlIG1vdCwgZXQgbGUgdG9uIGfDqW7DqXJhbCBkZSBs4oCZZW1haWwuIENlIG7igJnDqXRhaXQgcGFzIGRhbnMgbW9uIGludGVudGlvbiBkZSBibGVzc2VyIHF1ZWxxdeKAmXVuLiBK4oCZZW52b2llIGxlIG3Dqm1lIGUtbWFpbCBk4oCZZXhjdXNlcyBhdXggZGVzdGluYXRhaXJlcyBk4oCZb3JpZ2luZSBkZSBjZXQgZS1tYWlsLiBKZSBzYWlzIHF1ZSBq4oCZYWkgZXUgdG9ydCBldCBqZSBuZSBtZSBzZXJhaSBqYW1haXMgbW9pLW3Dqm1lIGV4cHJpbcOpIGRlIGNldHRlIGZhw6dvbjwvZW0%PC9lbT4uIMK7PC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvcXVhbmQtbGVzLWZyZXJlcy1zYW13ZXItcGFydGVudC1lbi1ndWVycmUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%Njwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5BdmRpY2UsIGxhIG5vdXZlbGxlIHBsYWNlIGRlIG1hcmNow6kgMi4wIHNww6ljaWFsaXPDqWUgZGFucyBsYSBwcmVzdGF0aW9uIGludGVsbGVjdHVlbGxlPC90aXRsZT4NCg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8zMC9hdmRpY2UtbGEtbm91dmVsbGUtcGxhY2UtZGUtbWFyY2hlLTItMC1zcGVjaWFsaXNlZS1kYW5zLWxhLXByZXN0YXRpb24taW50ZWxsZWN0dWVsbGUvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMzAvYXZkaWNlLWxhLW5vdXZlbGxlLXBsYWNlLWRlLW1hcmNoZS0yLTAtc3BlY2lhbGlzZWUtZGFucy1sYS1wcmVzdGF0aW9uLWludGVsbGVjdHVlbGxlLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTQ6Mjc6MDUgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkNlZHJpYyBPJ05laWxsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVthdmRpY2VdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGlua2VkaW5dXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVttYXJrZXRwbGFjZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtwcmVzdGF0aW9uIGludGVsZWN0dWVsbGVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbVHdpdHRlcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM5MzA8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvYXZkaWNlMS5wbmciPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MzIiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL2F2ZGljZTEucG5nIiBhbHQ9IiIgd2lkdGg9IjE1MiIgaGVpZ2h0PSI2MiIgLz48YSBocmVmPSJodHRwOi8vd3d3LmF2ZGljZS5jb20vIj5BdmRpY2U8L2E%IHZpZW50IGRlIGxhbmNlciBzYSBiw6p0YSBwdWJsaXF1ZS4gQ2V0dGUgPHN0cm9uZz5wbGFjZSBkZSBtYXJjaMOpPC9zdHJvbmc%IHZvdXMgcGVybWV0IGRlIHRyb3V2ZXIgZGVzIGNvbXDDqXRlbmNlcyBwbHVzIGZhY2lsZW1lbnQgZ3LDomNlIMOgIDxzdHJvbmc%bOKAmXV0aWxpc2F0aW9uIGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IDogdW5lIG5vdXZlbGxlIGZhw6dvbiBkZSBtZXR0cmUgZW4gcmVsYXRpb24gZG9ubmV1cnMgZOKAmW9yZHJlcyBldCBwcmVzdGF0YWlyZXMuDQoNCkVuIGQnYXV0cmVzIHRlcm1lcywgaWwgcydhZ2l0IGQndW5lIGFwcGxpY2F0aW9uIHdlYiBxdWkgcGVybWV0IGF1eCBwcmVzdGF0YWlyZXMgZGUgc2VydmljZXMgaW5kw6lwZW5kYW50cyBvdSBhc3NvY2nDqXMgZCdvcmdhbmlzZXIgbGV1ciBwcm9zcGVjdGlvbiwgZGUgbGlzc2VyIGxldXIgYWN0aXZpdMOpIGV0IGRlIGdhZ25lciBlbiB2aXNpYmlsaXTDqS4gUG91ciBsZXMgZG9ubmV1cnMgZCdvcmRyZXMsIGzigJlvYmplY3RpZiBlc3QgZGUgZMOpbmljaGVyIGxlcyBtZWlsbGV1cnMgcHJlc3RhdGFpcmVzIGRlIGxldXIgcsOpc2VhdSBncsOiY2Ugbm90YW1tZW50IMOgIDxzdHJvbmc%VHdpdHRlcjwvc3Ryb25nPiBldCA8c3Ryb25nPkxpbmtlZGluPC9zdHJvbmc%Ll1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9hdmRpY2UxLnBuZyI%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzkzMiIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvYXZkaWNlMS5wbmciIGFsdD0iIiB3aWR0aD0iMTUyIiBoZWlnaHQ9IjYyIiAvPjwvYT48YSBocmVmPSJodHRwOi8vd3d3LmF2ZGljZS5jb20vIj5BdmRpY2U8L2E%IHZpZW50IGRlIGxhbmNlciBzYSBiw6p0YSBwdWJsaXF1ZS4gQ2V0dGUgPHN0cm9uZz5wbGFjZSBkZSBtYXJjaMOpPC9zdHJvbmc%IHZvdXMgcGVybWV0IGRlIHRyb3V2ZXIgZGVzIGNvbXDDqXRlbmNlcyBwbHVzIGZhY2lsZW1lbnQgZ3LDomNlIMOgIDxzdHJvbmc%bOKAmXV0aWxpc2F0aW9uIGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IDogdW5lIG5vdXZlbGxlIGZhw6dvbiBkZSBtZXR0cmUgZW4gcmVsYXRpb24gZG9ubmV1cnMgZOKAmW9yZHJlcyBldCBwcmVzdGF0YWlyZXMuPC9wPg0KPHA%RW4gZCYjODIxNzthdXRyZXMgdGVybWVzLCBpbCBzJiM4MjE3O2FnaXQgZCYjODIxNzt1bmUgYXBwbGljYXRpb24gd2ViIHF1aSBwZXJtZXQgYXV4IHByZXN0YXRhaXJlcyBkZSBzZXJ2aWNlcyBpbmTDqXBlbmRhbnRzIG91IGFzc29jacOpcyBkJiM4MjE3O29yZ2FuaXNlciBsZXVyIHByb3NwZWN0aW9uLCBkZSBsaXNzZXIgbGV1ciBhY3Rpdml0w6kgZXQgZGUgZ2FnbmVyIGVuIHZpc2liaWxpdMOpLiBQb3VyIGxlcyBkb25uZXVycyBkJiM4MjE3O29yZHJlcywgbOKAmW9iamVjdGlmIGVzdCBkZSBkw6luaWNoZXIgbGVzIG1laWxsZXVycyBwcmVzdGF0YWlyZXMgZGUgbGV1ciByw6lzZWF1IGdyw6JjZSBub3RhbW1lbnQgw6AgPHN0cm9uZz5Ud2l0dGVyPC9zdHJvbmc%IGV0IDxzdHJvbmc%TGlua2VkaW48L3N0cm9uZz4uPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlciI%PGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3ZpZXdlcjEucG5nIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MzUiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3ZpZXdlcjEucG5nIiBhbHQ9IiIgd2lkdGg9IjUzMCIgaGVpZ2h0PSI1NzAiIC8%PC9hPjwvcD4NCjxwPkVuIHN1cHByaW1hbnQgbGVzIGludGVybcOpZGlhaXJlcywgPHN0cm9uZz5BdmRpY2U8L3N0cm9uZz4gcGVybWV0IGF1eCBkb25uZXVycyBk4oCZb3JkcmVzIGRlIHRyb3V2ZXIgZGVzIGluZMOpcGVuZGFudHMgw6AgbGV1ciBqdXN0ZSB2YWxldXIuIFBvdXIgY2VsYSwgQXZkaWNlIHByb3Bvc2UgYXV4IGRvbm5ldXJzIGTigJlvcmRyZXMgZGUgZGlmZnVzZXIgbGV1cnMgb2ZmcmVzIGF1cHLDqHMgZGUgbGV1ciByw6lzZWF1IGFpbnNpIHF14oCZYXV4IHByZXN0YXRhaXJlcyBob3JzIHLDqXNlYXUgcXVpIGNvcnJlc3BvbmRlbnQgYXV4IGNhcmFjdMOpcmlzdGlxdWVzIGRlIGxhIG1pc3Npb24uIENlcyBwcmVzdGF0YWlyZXMgc29udCBhdmVydGlzIGV0IHBldXZlbnQgZGlyZWN0ZW1lbnQgZXQgZ3JhdHVpdGVtZW50IGNvbnRhY3RlciBsZSBkb25uZXVyIGTigJlvcmRyZXMuPC9wPg0KPHA%TOKAmXV0aWxpc2F0aW9uIGRlIGxhIHBsYXRlZm9ybWUgZXN0IDxzdHJvbmc%ZW50acOocmVtZW50IGdyYXR1aXRlPC9zdHJvbmc%IHBvdXIgbGUgbW9tZW50LiBBdmRpY2Ugc2UgcGxhY2UgZW4gY29uY3VycmVuY2UgZGlyZWN0IGZhY2Ugw6AgZGUgbm9tYnJldXggYXV0cmVzIGFjdGV1cnMgZHUgbWFyY2jDqSBkZSBsYSBwcmVzdGF0aW9uIGludGVsbGVjdHVlbGxlIG9ubGluZSwgbWFpcyDDoCBsYSBkaWZmw6lyZW5jZSBkZSBjZXMgYWN0ZXVycywgQXZkaWNlIG7igJllc3QgcGFzIHNww6ljaWFsaXPDqSBldCBwcm9wb3NlIGRlcyBwcmVzdGF0aW9ucyBhbGxhbnQgZGUgPHN0cm9uZz5s4oCZYW5hbHlzZSBmaW5hbmNpw6hyZSDDoCBsYSBjcsOpYXRpb24gZGUgdm90cmUgbm91dmVsbGUgY2hhcnRlIGdyYXBoaXF1ZTwvc3Ryb25nPi4gTGEgZGlmZmljdWx0w6ksIMOgIG1vbiBzZW5zLCBzZXJhIHN1cmVtZW50IGRhbnMgbGEgY29udmVyc2lvbiBpbiBmaW5lIGRlcyB1dGlsaXNhdGV1cnMuIE1haXMgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jJTIxL1lpb2t0dSI%SsOpcsOpbXkgQmxvY2ssPC9hPiBzb24gQ0VPIGFubm9uY2UgbGFuY2VyIHRyw6hzIHByb2NoYWluZW1lbnQgZOKAmWF1dHJlcyBmb25jdGlvbm5hbGl0w6lzIHZlbmFudCBjb21wbMOpdGVyIGV0IMOpbGFyZ2lyIGxlIHNlcnZpY2UuPC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMzAvYXZkaWNlLWxhLW5vdXZlbGxlLXBsYWNlLWRlLW1hcmNoZS0yLTAtc3BlY2lhbGlzZWUtZGFucy1sYS1wcmVzdGF0aW9uLWludGVsbGVjdHVlbGxlL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5GYWd1byBTaG9lcyBvcmdhbmlzZSBzYW1lZGkgw6AgMTJoIGxhIEZBR1VPIFRyw6lzb3IsIHVuZSBjaGFzc2UgYXUgdHLDqXNvciAzLjA8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8zMC9mYWd1by1zaG9lcy1vcmdhbmlzZS1zYW1lZGktYS0xMmgtbGEtZmFndW8tdHJlc29yLXVuZS1jaGFzc2UtYXUtdHJlc29yLTMtMC88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8zMC9mYWd1by1zaG9lcy1vcmdhbmlzZS1zYW1lZGktYS0xMmgtbGEtZmFndW8tdHJlc29yLXVuZS1jaGFzc2UtYXUtdHJlc29yLTMtMC8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDEwOjI0OjEyICswMDAwPC9wdWJEYXRlPg0KDQoJCTxkYzpjcmVhdG9yPkF1cmVsaWUgUGVycnVjaGU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2ZhZ3VvIHRyw6lzb3JdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzOTIyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzkyNSIgdGl0bGU9IlFSLUNvZGUtRkFHVU8iIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL1FSLUNvZGUtRkFHVU8ucG5nIiBhbHQ9IiIgd2lkdGg9IjE1OSIgaGVpZ2h0PSIxNTMiIC8%QSBsJ29jY2FzaW9uIGRlIFDDonF1ZXMsIGxhIG1hcnF1ZSBkZSBjaGF1c3N1cmVzIDxzdHJvbmc%PGEgaHJlZj0iaHR0cHM6Ly93d3cuZmFjZWJvb2suY29tL0ZBR1VPU2hvZXMvYXBwXzM2Mzc2Njk2Njk3OTA3NCIgdGFyZ2V0PSJfYmxhbmsiPkZhZ3VvIFNob2VzPC9hPjwvc3Ryb25nPiBhIGTDqWNpZMOpLCBlbiBwYXJ0ZW5hcmlhdCBhdmVjIGRlcyBtYXJxdWVzIGFtaWVzIGFwcGVsw6llcyBhdXNzaSBhbWJhc3NhZGV1cnMsIGQnb3JnYW5pc2VyIHVuZSBncmFuZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vZXZlbnRzLzEwNTI5NTc3MjkzNzQ2MC8iIHRhcmdldD0iX2JsYW5rIj5jaGFzc2UgYXUgdHLDqXNvciAzLjA8L2E%IGRhbnMgbGVzIDJlbWUgZXQgMyBlbWUgYXJyb25kaXNzZW1lbnRzIGRlIFBhcmlzIFNhbWVkaSAzMSBNYXJzIMOgIDEyaC4gUGx1cyBkZSA1MCAwMDAgZmFucyBzdXIgbGVzIGRpZmbDqXJlbnRlcyBwYWdlcyBGYWNlYm9vayBkZXMgYW1iYXNzYWRldXJzIG9udCDDqXTDqSBtb2JpbGlzw6lzIHBvdXIgcGFydGljaXBlci4NCg0KTGEgRkFHVU:igJlUUsOJU09SIGVzdCB1bmUgY2hhc3NlIDMuMCBtZWxhbnQgd2ViLCBkaWdpdGFsIGV0IHN0cmVldCBtYXJrZXRpbmcuIFRvdXMgY2V1eCBxdWkgc291aGFpdGVudCBwYXJ0aWNpcGVyIHBhcnRpcm9udCDDoCBsYSByZWNoZXJjaGUgZGUgMTAwIFFSIGNvZGVzIGNhY2jDqXMuIElsIGxldXIgZmF1ZHJhIGxlcyBmbGFzaGVyIGF2ZWMgbCdhcHBsaWNhdGlvbiBtb2JpbGUgYm9va0Jlby4gMTAwIGFtYmFzc2FkZXVycyAoZGVzIGJsb2d1ZXVycywgZmFucyBGYWNlYm9vaywgbWFnYXNpbnMsIHBlcnNvbm5hbGl0w6lzIGV0IG1hcnF1ZXMgYW1pZXMpIGRpZmZ1c2Vyb250IGRlcyBpbmRpY2VzIHRvdXRlIGxhIGpvdXJuw6llIHZpYSBsZXMgcsOpc2VhdXggc29jaWF1eCBwb3VyIGFpZGVyIGxlcyBwYXJ0aWNpcGFudHMuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzkyNSIgdGl0bGU9IlFSLUNvZGUtRkFHVU8iIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL1FSLUNvZGUtRkFHVU8ucG5nIiBhbHQ9IiIgd2lkdGg9IjE1OSIgaGVpZ2h0PSIxNTMiIC8%QSBsJiM4MjE3O29jY2FzaW9uIGRlIFDDonF1ZXMsIGxhIG1hcnF1ZSBkZSBjaGF1c3N1cmVzIDxzdHJvbmc%PGEgaHJlZj0iaHR0cHM6Ly93d3cuZmFjZWJvb2suY29tL0ZBR1VPU2hvZXMvYXBwXzM2Mzc2Njk2Njk3OTA3NCIgdGFyZ2V0PSJfYmxhbmsiPkZhZ3VvIFNob2VzPC9hPjwvc3Ryb25nPiBhIGTDqWNpZMOpLCBlbiBwYXJ0ZW5hcmlhdCBhdmVjIGRlcyBtYXJxdWVzIGFtaWVzIGFwcGVsw6llcyBhdXNzaSBhbWJhc3NhZGV1cnMsIGQmIzgyMTc7b3JnYW5pc2VyIHVuZSBncmFuZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vZXZlbnRzLzEwNTI5NTc3MjkzNzQ2MC8iIHRhcmdldD0iX2JsYW5rIj5jaGFzc2UgYXUgdHLDqXNvciAzLjA8L2E%IGRhbnMgbGVzIDJlbWUgZXQgMyBlbWUgYXJyb25kaXNzZW1lbnRzIGRlIFBhcmlzIFNhbWVkaSAzMSBNYXJzIMOgIDEyaC4gUGx1cyBkZSA1MCAwMDAgZmFucyBzdXIgbGVzIGRpZmbDqXJlbnRlcyBwYWdlcyBGYWNlYm9vayBkZXMgYW1iYXNzYWRldXJzIG9udCDDqXTDqSBtb2JpbGlzw6lzIHBvdXIgcGFydGljaXBlci48L3A%DQo8cD5MYSBGQUdVT%KAmVRSw4lTT1IgZXN0IHVuZSBjaGFzc2UgMy4wIG1lbGFudCB3ZWIsIGRpZ2l0YWwgZXQgc3RyZWV0IG1hcmtldGluZy4gVG91cyBjZXV4IHF1aSBzb3VoYWl0ZW50IHBhcnRpY2lwZXIgcGFydGlyb250IMOgIGxhIHJlY2hlcmNoZSBkZSAxMDAgUVIgY29kZXMgY2FjaMOpcy4gSWwgbGV1ciBmYXVkcmEgbGVzIGZsYXNoZXIgYXZlYyBsJiM4MjE3O2FwcGxpY2F0aW9uIG1vYmlsZSBib29rQmVvLiAxMDAgYW1iYXNzYWRldXJzIChkZXMgYmxvZ3VldXJzLCBmYW5zIEZhY2Vib29rLCBtYWdhc2lucywgcGVyc29ubmFsaXTDqXMgZXQgbWFycXVlcyBhbWllcykgZGlmZnVzZXJvbnQgZGVzIGluZGljZXMgdG91dGUgbGEgam91cm7DqWUgdmlhIGxlcyByw6lzZWF1eCBzb2NpYXV4IHBvdXIgYWlkZXIgbGVzIHBhcnRpY2lwYW50cy48L3A%DQo8cD5MZSBwcmluY2lwZSBlc3Qgc2ltcGxlIDo8L3A%DQo8cD4xKSBSRFYgU2FtZWRpIMOgIDEyaCBzdXIgbGVzIHBhZ2VzIGZhbnMgZGVzIGFtYmFzc2FkZXVycyBvdSBzdXIgbGVzIGNvbXB0ZXMgdHdpdHRlciBwb3VyIGF2b2lyIGxlcyBpbmRpY2VzIGF1IHN1amV0IGRlcyAxMDAgUVIgY29kZXMgY2FjaMOpcyBkYW5zIFBhcmlzPC9wPg0KPHA%MikgQ2hlcmNoZXosIHRyb3V2ZXogZXQgc2Nhbm5leiBsZSBtYXhpbXVtIGRlIFFSIGNvZGVzIGVudHJlIDEyaCBldCAxNmggYXZlYyBsJiM4MjE3O2FwcGxpY2F0aW9uIDxhIGhyZWY9Imh0dHA6Ly9pdHVuZXMuYXBwbGUuY29tL2ZyL2FwcC9ib29rYmVvL2lkMzA2NDExNDUzP210PTgiIHRhcmdldD0iX2JsYW5rIj5Cb29rQmVvPC9hPjwvcD4NCjxwPjxpZnJhbWUgd2lkdGg9IjYwMCIgaGVpZ2h0PSIzMzUiIHNyYz0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9lbWJlZC9vUzZsby1CMWVYST9yZWw9MCIgZnJhbWVib3JkZXI9IjAiIGFsbG93ZnVsbHNjcmVlbj48L2lmcmFtZT48L3A%DQo8cD4zKSBBIDE2aCwgbGUgbGlldSBkdSBRUiBjb2RlIGZpbmFsIHNlcmEgZMOpdm9pbMOpIGV0IHRvdXQgbGUgbW9uZGUgc2UgcmV0cm91dmVyYSDDoCBjZXQgZW5kcm9pdCBwb3VyIGJvaXJlIHVuIHZlcnJlPC9wPg0KPHA%TGUgY29uY2VwdCBlc3QgaW50ZXJlc3NhbnQgcG91ciByZWdyb3VwZXIgZGVzIG1hcnF1ZXMgZXQgYXZvaXIgdW5lIGZvcmNlIGRlIGNvbW11bmljYXRpb24gcGx1cyBpbXBhY3RhbnRlIGV0IGFpbnNpIHRvdWNoZXIgZGVzIGNpYmxlcyBkaWZmw6lyZW50ZXMuPC9wPg0KPHA%UGFybWkgbGVzIGFtYmFzc2FkZXVycywgb24gcmV0cm91dmUgOiA8YSBocmVmPSJodHRwOi8vd3d3Lm1pY2hlbGV0YXVndXN0aW4uY29tLyIgdGFyZ2V0PSJfYmxhbmsiPk1pY2hlbCZhbXA7QXVndXN0aW48L2E%LCA8YSByZWw9Im5vZm9sbG93IiBocmVmPSJodHRwOi8vd3d3LmRhZ29iZWFyLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5EYWdvYmVhcjwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cubWFzcGF0dWxlLmNvbSIgdGFyZ2V0PSJfYmxhbmsiPk1hU3BhdHVsZTwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cuZmFjZWJvb2suY29tL2ZiQk9SREVSTElORT9yZWY9dHMiIHRhcmdldD0iX2JsYW5rIj5Cb3JkZXJsaW5lPC9hPiwgPGEgcmVsPSJub2ZvbGxvdyIgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vbGVzaW5zdXJnZXMudW5kZXJ3ZWFyIiB0YXJnZXQ9Il9ibGFuayI%TGVzIEluc3VyZ8OpczwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cuZmFjZWJvb2suY29tL3NvamVhbnMuZnJhbmNlIiB0YXJnZXQ9Il9ibGFuayI%U28gamVhbnM8L2E%JiM4MjMwOzwvcD4NCjxwPkRlcyBwZXJzb25uYWxpdMOpcyBjb21tZSBLaGVpcm9uLCBWZXJpbm8sIDxhIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDExLzA5LzEyL2xlLW1vb3ZqZWUtdW4tcHJpeC1kZXMtbWVudG9ycy11bi1jbHViLWV0LWRlcy1ldmVuZW1lbnRzLXBvdXItbm9zLWpldW5lcy1lbnRyZXByZW5ldXJzLyIgdGFyZ2V0PSJfYmxhbmsiPk1vb3ZqZWU8L2E%PC9wPg0KPHA%RGVzIGJsb2dzOiBM4oCZaW50ZXJuYXV0ZSwgTWVsdHkgRmFzaGlvbiwgTWFyaW9uUm9ja3MsIERhbmRpZXMsIEVuIG1vZGUgRmFzaGlvbjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzMwL2ZhZ3VvLXNob2VzLW9yZ2FuaXNlLXNhbWVkaS1hLTEyaC1sYS1mYWd1by10cmVzb3ItdW5lLWNoYXNzZS1hdS10cmVzb3ItMy0wL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bRXhjbHVdIE15RVJQLmNvbSBsYW5jZSB1bmUgdmVyc2lvbiBkZSBzb24gYXBwbGljYXRpb24gZGUgZ2VzdGlvbiBjbG91ZCBkw6lkacOpZSBhdSBQTUUgYXUgVUs8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay88L2xpbms%DQoNCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2V4Y2x1LW15ZXJwLWNvbS1sYW5jZS11bmUtdmVyc2lvbi1kZS1zb24tYXBwbGljYXRpb24tZGUtZ2VzdGlvbi1jbG91ZC1kZWRpZWUtYXUtcG1lLWF1LXVrLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPldlZCwgMjggTWFyIDIwMTIgMTI6MjQ6MzMgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkF1cmVsaWUgUGVycnVjaGU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW215RVJQXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg5NzwvZ3VpZD4NCg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzkwMCIgdGl0bGU9Im15ZXJwIiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9teWVycC5wbmciIGFsdD0iIiB3aWR0aD0iMjQzIiBoZWlnaHQ9IjExMSIgLz48YSBocmVmPSJodHRwOi8vbXllcnAuY29tLyIgdGFyZ2V0PSJfc2VsZiI%TXlFUlAuY29tPC9hPiBlc3QgbGUgPHN0cm9uZz5wcmVtaWVyIHNlcnZpY2UgY2xvdWQgZGUgZ2VzdGlvbjwvc3Ryb25nPiDDoCBkZXN0aW5hdGlvbiBkZXMgUE1FLCBsYSBzb2Npw6l0w6kgbGFuY2UgYXVqb3VyZCdodWkgdW5lIHZlcnNpb24gZGUgc29uIGFwcGxpY2F0aW9uIHN1ciBsZSBtYXJjaMOpIGJyaXRhbm5pcXVlIGFsb3JzIHF1ZSBzb24gY29uY3VycmVudCBsb2NhbCBTQUdFIG4nYSB0b3Vqb3VycyBwYXMgZGUgc29sdXRpb24gY2xvdWQuIExhbmPDqSBvZmZpY2llbGxlbWVudCBlbiA8c3Ryb25nPm1hcnMgMjAxMDwvc3Ryb25nPiBhdmVjIGxlIGxhbmNlbWVudCBkZSBHb29nbGUgQXBwcyBNYXJrZXRwbGFjZSwgbXlFUlAgY29tcHRlIHByw6hzIGRlIDUwMDAwIFBNRSDDoCB0cmF2ZXJzIHBsdXMgZGUgMTAwIHBheXMgZGlmZsOpcmVudHMgcXVpIHV0aWxpc2VudCByw6lndWxpw6hyZW1lbnQgbGEgcGxhdGVmb3JtZSBwb3VyIGfDqXJlciB0b3V0ZXMgbGVzIGFjdGl2aXTDqXMgZGUgbGV1ciBzb2Npw6l0w6kgZGVwdWlzIGxlIGNsb3VkIDogbGEgY29tcHRhYmlsaXTDqSBlbiBsaWduZSwgbGEgZmFjdHVyYXRpb24sIGxlIENSTSwgbGVzIHN0b2NrcyBldCBiaWVuIHBsdXMsIGxlIHRvdXQgaW50w6lncsOpIGF2ZWMgR29vZ2xlIEFwcHMuIEMnZXN0IHVuZSA8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMC8wNy8xNi9sZXMtZnJhbmNhaXMtZGUtbGEtdmFsbGV5LXRvdXItZGhvcnpvbi1kZXMtc3RhcnR1cHMtb3UtZW50cmVwcmVuZXVycy1mcmFuY2Fpcy8iIHRhcmdldD0iX2JsYW5rIj5zdGFydHVwIGZyYW7Dp2Fpc2UgcGFydGllIGRhbnMgbGEgc2lsaWNvbiBWYWxsZXk8L2E%Ll1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MDAiIHRpdGxlPSJteWVycCIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbXllcnAucG5nIiBhbHQ9IiIgd2lkdGg9IjI0MyIgaGVpZ2h0PSIxMTEiIC8%PGEgaHJlZj0iaHR0cDovL215ZXJwLmNvbS8iIHRhcmdldD0iX3NlbGYiPk15RVJQLmNvbTwvYT4gZXN0IGxlIDxzdHJvbmc%cHJlbWllciBzZXJ2aWNlIGNsb3VkIGRlIGdlc3Rpb248L3N0cm9uZz4gw6AgZGVzdGluYXRpb24gZGVzIFBNRSwgbGEgc29jacOpdMOpIGxhbmNlIGF1am91cmQmIzgyMTc7aHVpIHVuZSB2ZXJzaW9uIGRlIHNvbiBhcHBsaWNhdGlvbiBzdXIgbGUgbWFyY2jDqSBicml0YW5uaXF1ZSBhbG9ycyBxdWUgc29uIGNvbmN1cnJlbnQgbG9jYWwgU0FHRSBuJiM4MjE3O2EgdG91am91cnMgcGFzIGRlIHNvbHV0aW9uIGNsb3VkLiBMYW5jw6kgb2ZmaWNpZWxsZW1lbnQgZW4gPHN0cm9uZz5tYXJzIDIwMTA8L3N0cm9uZz4gYXZlYyBsZSBsYW5jZW1lbnQgZGUgR29vZ2xlIEFwcHMgTWFya2V0cGxhY2UsIG15RVJQIGNvbXB0ZSBwcsOocyBkZSA1MDAwMCBQTUUgw6AgdHJhdmVycyBwbHVzIGRlIDEwMCBwYXlzIGRpZmbDqXJlbnRzIHF1aSB1dGlsaXNlbnQgcsOpZ3VsacOocmVtZW50IGxhIHBsYXRlZm9ybWUgcG91ciBnw6lyZXIgdG91dGVzIGxlcyBhY3Rpdml0w6lzIGRlIGxldXIgc29jacOpdMOpIGRlcHVpcyBsZSBjbG91ZCA6IGxhIGNvbXB0YWJpbGl0w6kgZW4gbGlnbmUsIGxhIGZhY3R1cmF0aW9uLCBsZSBDUk0sIGxlcyBzdG9ja3MgZXQgYmllbiBwbHVzLCBsZSB0b3V0IGludMOpZ3LDqSBhdmVjIEdvb2dsZSBBcHBzLiBDJiM4MjE3O2VzdCB1bmUgPGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTAvMDcvMTYvbGVzLWZyYW5jYWlzLWRlLWxhLXZhbGxleS10b3VyLWRob3J6b24tZGVzLXN0YXJ0dXBzLW91LWVudHJlcHJlbmV1cnMtZnJhbmNhaXMvIiB0YXJnZXQ9Il9ibGFuayI%c3RhcnR1cCBmcmFuw6dhaXNlIHBhcnRpZSBkYW5zIGxhIHNpbGljb24gVmFsbGV5PC9hPi48L3A%DQo8cD5MJiM4MjE3O29mZnJlIGRlIG15RVJQIHBlcm1ldCBhdXggUE1FIGQmIzgyMTc7YWNoZXRlciB1bmUgc2V1bGUgYXBwbGljYXRpb24gc2ltcGxlIGV0IGNvbXBsw6h0ZSBhdSBsaWV1IGRlIG11bHRpcGxlcyBhcHBsaWNhdGlvbnMgY2jDqHJlcyBldCBkaWZmaWNpbGVzIMOgIHV0aWxpc2VyLiBHcsOiY2Ugw6Agc29uIGludGVyZmFjZSBzaW1wbGUgYXZlYyB1bmUgYmFycmUgZGUgbmF2aWdhdGlvbiDDoCBsYSBHb29nbGUgZXQgc29uIGFsZ29yaXRobWUgaW50ZWxsaWdlbnQgZXQgcHLDqWRpY3RpZiBxdWkgYXJyaXZlIMOgIGNvbXByZW5kcmUgZXhhY3RlbWVudCBjZSBxdWUgbCYjODIxNzt1dGlsaXNhdGV1ciBzb3VoYWl0ZSBmYWlyZSwgbCYjODIxNzthcHBsaWNhdGlvbiBteUVSUCBuZSBuw6ljZXNzaXRlIGF1Y3VuZSBmb3JtYXRpb24gYWZpbiBkZSBsJiM4MjE3O3V0aWxpc2VyLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM5MDQiIHRpdGxlPSJteWVycCIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbXllcnAyLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTYiIGhlaWdodD0iMzAyIiAvPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%PHN0cm9uZz5GcmFuw6dvaXMgTmFkYWw8L3N0cm9uZz4sIFBERyBkZSBteUVSUCwgZXhwbGlxdWUgbGUgbGFuY2VtZW50IGRlIGxhIHZlcnNpb24gYnJpdGFubmlxdWU6ICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBicml0YW5uaXF1ZSByZXByw6lzZW50ZSBzZWxvbiBub3MgZXN0aW1hdGlvbnMgbGUgNMOobWUgbWFyY2jDqSBsZSBwbHVzIGludMOpcmVzc2FudCBwb3VyIGxlcyBhcHBsaWNhdGlvbnMgY2xvdWQ8L2VtPiYjODIyMDsuIElsIHByw6ljaXNlIGVuIHBsdXMgcXVlICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBVSyBlc3QgZG9taW7DqSBwYXIgbCYjODIxNzthY3RldXIgaGlzdG9yaXF1ZSwgU2FnZSwgcXVpIG4mIzgyMTc7YSBwYXMgc3UgcHJvcG9zZXIgw6Agc2VzIGNsaWVudHMgdW5lIHZlcnNpb24gY2xvdWQuIE5vdXMgZXN0aW1vbnMgcXUmIzgyMTc7ZW4gMjAxMSwgMzUlIGRlcyBlbnRyZXByaXNlcyBicml0YW5uaXF1ZXMgc291aGFpdGFpZW50IGTDqWrDoCBtaWdyZXIgbGV1ciBnZXN0aW9uIGRhbnMgbGUgY2xvdWQuIEVuIDIwMTIsIG15RVJQIGFycml2ZSBlbmZpbiBhdmVjIHVuZSBzb2x1dGlvbiBtYXR1cmUsIHJvYnVzdGUgZXQgc8OpY3VyaXPDqWUgcG91ciBhc3N1cmVyIGNldHRlIG1pZ3JhdGlvbi48L2VtPiYjODIyMDs8L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogbGVmdDsiPkwmIzgyMTc7b3V2ZXJ0dXJlIGR1IGNvbXB0ZSBteUVSUCBlc3QgZ3JhdHVpdCBhdmVjIGRlcyBmb25jdGlvbm5hbGl0w6lzIGlsbGltaXTDqWVzIHBvdXIgMSB1dGlsaXNhdGV1ci4gTGVzIG9mZnJlcyBwYXlhbnRlcyAmIzgyMjA7UHJlbWl1bSYjODIyMTsgc29udCBkaXNwb25pYmxlcyBwb3VyIDIgdXRpbGlzYXRldXJzIG91IDUgdXRpbGlzYXRldXJzLCBhdSBkZWzDoCwgbCYjODIxNzt1dGlsaXNhdGV1ciBzdXBwbMOpbWVudGFpcmUgZXN0IGZhY3R1csOpIDEy4oKsIHBhciBtb2lzLiBCb24gbGFuY2VtZW50ICE8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4zPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkNpdGl2ZXJzaXR5LCBsZSBmZXUgZGUgY2FtcCAyLjA8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9jaXRpdmVyc2l0eS1sZS1mZXUtZGUtY2FtcC0yLTAvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%V2VkLCAyOCBNYXIgMjAxMiAxMjowODozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbY2l0eXZlcnNpdHldXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODg4PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi4NCg0KUGVybWV0dHJlIMOgIGRlcyBwYXNzaW9ubsOpcyBkZSBwYXJ0YWdlciBsZXVyIGV4cMOpcmllbmNlIGF2ZWMgdW5lIHF1aW56YWluZSBkZSBwZXJzb25uZXMgZW4gZGV1eCBoZXVyZXMgZXQgZGFucyB1biBsaWV1IGFkYXB0w6ksIHRlbCBlc3QgbOKAmW9iamVjdGlmIHF1ZSBz4oCZZXN0IGZpeMOpIDxhIGhyZWY9Imh0dHA6Ly9jaXRpdmVyc2l0eS5ldmVudGJyaXRlLmNvbSI%IENpdGl2ZXJzaXR5PC9hPi4NCg0KVW4gb2JqZWN0aWYgcXVpIG7igJllc3QgcGFzIHNhbnMgcmFwcGVsZXIgY2VsdWkgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5za2lsbHNoYXJlLmNvbSI%U2tpbGxzaGFyZTwvYT4sIHN0YXJ0LXVwIG5ldy15b3JrYWlzZSBiaWVuIGNvbm51ZSBtYWlzIHF1aSBzb3VmZnJlIGRlIGxhIGxpYmVydMOpIGxhaXNzw6llIMOgIHNlcyB1dGlsaXNhdGV1cnMgOyBu4oCZaW1wb3J0ZSBxdWkgcG91dmFudCBwcm9wb3NlciB1biBjb3VycywgY29tbWVudCBzYXZvaXIgc2kgbGUgcHJvZmVzc2V1ciBzZXJhIGRlIHF1YWxpdMOpPyBDb21tZW50LCBwb3VyIGxlcyBwcm9mZXNzZXVycywgdHJvdXZlciBldCByw6lzZXJ2ZXIgdW5lIHNhbGxlIGFkYXB0w6llIHNhbnMgbWV0dHJlIGdyYXZlbWVudCBlbiBkYW5nZXIgbGEgcmVudGFiaWxpdMOpIGRlIGzigJlvcMOpcmF0aW9uID8gVGVsbGVzIHNvbnQgbGVzIHF1ZXN0aW9ucyBhdXhxdWVsbGVzIHLDqXBvbmQgQ2l0aXZlcnNpdHksIHF1aSBzw6lsZWN0aW9ubmUgbcOpdGljdWxldXNlbWVudCBzZXMgYW5pbWF0ZXVycyBldCBwcmVuZCBlbiBjaGFyZ2UgbOKAmWFzcGVjdCBsb2dpc3RpcXVlIGRlIGzigJlvcmdhbmlzYXRpb24gZGUgbOKAmWF0ZWxpZXIgKHVuIHNlcnZpY2UgcG91ciBsZXF1ZWwgQ2l0aXZlcnNpdHkgcHLDqWzDqHZlIDI1JSBkdSB0b3RhbCwgZnJhaXMgZOKAmW9yZ2FuaXNhdGlvbiBkw6lkdWl0cykuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5QZXJtZXR0cmUgw6AgZGVzIHBhc3Npb25uw6lzIGRlIHBhcnRhZ2VyIGxldXIgZXhww6lyaWVuY2UgYXZlYyB1bmUgcXVpbnphaW5lIGRlIHBlcnNvbm5lcyBlbiBkZXV4IGhldXJlcyBldCBkYW5zIHVuIGxpZXUgYWRhcHTDqSwgdGVsIGVzdCBs4oCZb2JqZWN0aWYgcXVlIHPigJllc3QgZml4w6kgPGEgaHJlZj0iaHR0cDovL2NpdGl2ZXJzaXR5LmV2ZW50YnJpdGUuY29tIj4gQ2l0aXZlcnNpdHk8L2E%LjwvcD4NCjxwPlVuIG9iamVjdGlmIHF1aSBu4oCZZXN0IHBhcyBzYW5zIHJhcHBlbGVyIGNlbHVpIGRlIDxhIGhyZWY9Imh0dHA6Ly93d3cuc2tpbGxzaGFyZS5jb20iPlNraWxsc2hhcmU8L2E%LCBzdGFydC11cCBuZXcteW9ya2Fpc2UgYmllbiBjb25udWUgbWFpcyBxdWkgc291ZmZyZSBkZSBsYSBsaWJlcnTDqSBsYWlzc8OpZSDDoCBzZXMgdXRpbGlzYXRldXJzIDsgbuKAmWltcG9ydGUgcXVpIHBvdXZhbnQgcHJvcG9zZXIgdW4gY291cnMsIGNvbW1lbnQgc2F2b2lyIHNpIGxlIHByb2Zlc3NldXIgc2VyYSBkZSBxdWFsaXTDqT8gQ29tbWVudCwgcG91ciBsZXMgcHJvZmVzc2V1cnMsIHRyb3V2ZXIgZXQgcsOpc2VydmVyIHVuZSBzYWxsZSBhZGFwdMOpZSBzYW5zIG1ldHRyZSBncmF2ZW1lbnQgZW4gZGFuZ2VyIGxhIHJlbnRhYmlsaXTDqSBkZSBs4oCZb3DDqXJhdGlvbiA:IFRlbGxlcyBzb250IGxlcyBxdWVzdGlvbnMgYXV4cXVlbGxlcyByw6lwb25kIENpdGl2ZXJzaXR5LCBxdWkgc8OpbGVjdGlvbm5lIG3DqXRpY3VsZXVzZW1lbnQgc2VzIGFuaW1hdGV1cnMgZXQgcHJlbmQgZW4gY2hhcmdlIGzigJlhc3BlY3QgbG9naXN0aXF1ZSBkZSBs4oCZb3JnYW5pc2F0aW9uIGRlIGzigJlhdGVsaWVyICh1biBzZXJ2aWNlIHBvdXIgbGVxdWVsIENpdGl2ZXJzaXR5IHByw6lsw6h2ZSAyNSUgZHUgdG90YWwsIGZyYWlzIGTigJlvcmdhbmlzYXRpb24gZMOpZHVpdHMpLjwvcD4NCjxwPlRyw6hzIGNlbnRyw6kgc3VyIGxhIHF1YWxpdMOpIGRlIGzigJnDqWNoYW5nZSwgQ2l0aXZlcnNpdHkgcsOqdmUgYWluc2kgZGUgZmFpcmUgw6ljbG9yZSBlbiBjaGFjdW4gbOKAmWVudmllIGRlIHBhcnRhZ2VyIGNlIHF1aSBsZSByZW5kIHVuaXF1ZSA6IHNvbiBleHDDqXJpZW5jZS4gQWluc2kgYS10LW9uIHB1IHBhcnRpY2lwZXIgZW4gTWFycyDDoCB1biBhdGVsaWVyIGRlIGTDqWNvdXZlcnRlIGR1IGJhbGxldCBhbmltw6kgcGFyIHVuZSBkYW5zZXVzZSBjbGFzc2lxdWUgY29uZmlybcOpZSwgb3Ugw6AgdW4gYXV0cmUgdmlzYW50IMOgIGZvcm1lciBsZXMgYXVkaXRldXJzIMOgIGzigJlhcnQgZGUgbOKAmWludGVydmlldyBwcm9wb3PDqSBwYXIgdW4gam91cm5hbGlzdGUgcmVub21tw6kuPC9wPg0KPHA%Rm9uZMOpIHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL2tuaWxmbyI%IEtleXZhbiBOaWxmb3JvdXNoYW4gPC9hPmFwcsOocyB1bmUgcHJlbWnDqHJlIGNhcnJpw6hyZSBkZSBWQyBjaGV6IE5leHRTdGFnZSwgQ2l0aXZlcnNpdHkgaWxsdXN0cmUgcGFyZmFpdGVtZW50IGRldXggY29uY2VwdHMgdHLDqHMgZW4gdm9ndWU6IGxlIDxlbT5sZWFuPC9lbT4gZXQgbGEgPGVtPmN1cmF0aW9uPC9lbT4uIERhbnMgdW4gcHJlbWllciB0ZW1wcywgQ2l0aXZlcnNpdHkgYSBlbiBlZmZldCBjaG9pc2kgZOKAmXV0aWxpc2VyIGxhIHNvbHV0aW9uIEV2ZW50YnJpdGUgKGFpbnNpIHF1ZSBNYWlsY2hpbXAgZXQgTGF1bmNocm9jaykgbGUgdGVtcHMgZGUgcHLDqWNpc2VyIHNvbiBtb2TDqGxlLiBCaWVuIGx1aSBlbiBhIHByaXMgYXV4IHZ1ZXMgZHUgc3VjY8OocyBkZXMgcHJlbWllcnMgYXRlbGllcnMsIHF1aSBvbnQgdmFsaWTDqSBzYSBjb252aWN0aW9uIHF14oCZaWwgeSBhIHVuZSB2w6lyaXRhYmxlIHZhbGV1ciBham91dMOpZSDDoCBuZSBwcm9wb3NlciBxdWUgZGVzIGV4cMOpcmllbmNlcyBxdWFsaXRhdGl2ZXMgKGxlIHRhcmlmIG1veWVuIMOpdGFudCBkZSA1MCBldXJvcyBwYXIgcGVyc29ubmUuKTwvcD4NCjxwPkVuIGF0dGVuZGFudCBsYSB2ZXJzaW9uIDIuMCwgZGUgbm9tYnJldXggYXRlbGllcnMgc29udCBkw6lqw6AgcHJvZ3JhbW3DqXMsIHBhcm1pIGxlc3F1ZWxzIMKrIEZhaXJlIHNlcyBjb3Vyc2VzIMOgIENoaW5hdG93biDCuywgwqsgUHJlbmRyZSBsZXMgbW9udW1lbnRzIHBhcmlzaWVucyBlbiBwaG90byDCuyBldCDCqyBMZSBwaWFubyBlbiA0IGhldXJlcyDCuyAoZW4gZGV1eCBwYXJ0aWVzKS48L3A%DQo8cD5Wb3VzIHLDqnZleiBk4oCZdW4gYXRlbGllciBlbiBwYXJ0aWN1bGllciA:IERlbWFuZGV6LWxlLCA8YSBocmVmPSJodHRwOi8vZmVlZGJhY2suY2l0aXZlcnNpdHkuY29tIj51bmUgcGFnZSBkw6lkacOpZTwvYT4gZXN0IGzDoCBwb3VyIMOnYS4gU2kgbGEgY29tbXVuYXV0w6kgdm90ZSBwb3VyIHZvdHJlIGlkw6llLCA8YSBocmVmPSJodHRwOi8vY2l0aXZlcnNpdHkuZXZlbnRicml0ZS5jb20iPiBDaXRpdmVyc2l0eTwvYT4gc2UgY2hhcmdlcmEgZGUgdHJvdXZlciBs4oCZaW50ZXJ2ZW5hbnQgaWTDqWFsLCBldCBkZSBkb25uZXIgdmllIMOgIGzigJlhdGVsaWVyLiAgRXQgdm91cywgcXXigJlhdmV6LXZvdXMgw6AgcGFydGFnZXIgPzwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCg0KCQk8dGl0bGU%TGUgSmV1ZGkgMTIgQXZyaWwsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHPigJlpbnZpdGVudCBhdSBQYWxhaXMgZGUgbGEgZMOpY291dmVydGU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDIzOjAwOjMyICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5BdXJlbGllIFBlcnJ1Y2hlPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4Njg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9yZXNlYXV4LXNvY2lhdXgucG5nIiBhbHQ9IiIgd2lkdGg9IjI3MSIgaGVpZ2h0PSIxNDgiIC8%TGVzIDEyIGV0IDEzIGF2cmlsIDIwMTIsIGzigJlVbml2ZXJzaXTDqSBkZSBWZXJzYWlsbGVzIFNhaW50LVF1ZW50aW4tZW4tWXZlbGluZXMgb3JnYW5pc2UgYXUgUGFsYWlzIGRlIGxhIGTDqWNvdXZlcnRlIDxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJiMzODtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%dW48L2E%DQo8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCYjMzg7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPmNvbGxvcXVlIGNvbnNhY3LDqSBhdXggbm91dmVhdXggbcOpZGlhczwvYT4uIFVuZSB0YWJsZSByb25kZSBzdXIgbGEgdGjDqW1hdGlxdWUgZGUgPHN0cm9uZz5sYSBjdWx0dXJlIGV0IGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IGVzdA0KcHJvcG9zw6llIGxlIDxzdHJvbmc%amV1ZGkgMTIgYXZyaWwgMjAxMiBkZSA5aDMwIMOgIDEyaDAwPC9zdHJvbmc%Lg0KDQpEZXB1aXMgcGx1c2lldXJzIGFubsOpZXMsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHNvbnQgZGV2ZW51cyBkZSB2w6lyaXRhYmxlcyBvdXRpbHMgZGUgcGFydGFnZS5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9yZXNlYXV4LXNvY2lhdXgucG5nIiBhbHQ9IiIgd2lkdGg9IjI3MSIgaGVpZ2h0PSIxNDgiIC8%TGVzIDEyIGV0IDEzIGF2cmlsIDIwMTIsIGzigJlVbml2ZXJzaXTDqSBkZSBWZXJzYWlsbGVzIFNhaW50LVF1ZW50aW4tZW4tWXZlbGluZXMgb3JnYW5pc2UgYXUgUGFsYWlzIGRlIGxhIGTDqWNvdXZlcnRlIDxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJmFtcDtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%dW48L2E%PGJyIC8%DQo8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCZhbXA7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPmNvbGxvcXVlIGNvbnNhY3LDqSBhdXggbm91dmVhdXggbcOpZGlhczwvYT4uIFVuZSB0YWJsZSByb25kZSBzdXIgbGEgdGjDqW1hdGlxdWUgZGUgPHN0cm9uZz5sYSBjdWx0dXJlIGV0IGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IGVzdDxiciAvPg0KcHJvcG9zw6llIGxlIDxzdHJvbmc%amV1ZGkgMTIgYXZyaWwgMjAxMiBkZSA5aDMwIMOgIDEyaDAwPC9zdHJvbmc%LjwvcD4NCjxwPkRlcHVpcyBwbHVzaWV1cnMgYW5uw6llcywgbGVzIHLDqXNlYXV4IHNvY2lhdXggc29udCBkZXZlbnVzIGRlIHbDqXJpdGFibGVzIG91dGlscyBkZSBwYXJ0YWdlLiBEaWZmdXNhbnQgZGUgbGEgbXVzaXF1ZSwgZGVzIGZpbG1zLCBkZXMgcmVwcsOpc2VudGF0aW9ucyB0aMOpw6J0cmFsZXMgZXQgYmllbiBk4oCZYXV0cmVzIGNyw6lhdGlvbnMgYXJ0aXN0aXF1ZXMsIGlscyBzb250IGTigJlpbmNyb3lhYmxlcyBwbGF0ZWZvcm1lcyBk4oCZw6ljaGFuZ2UsIHVuIHbDqXJpdGFibGUgdHJlbXBsaW4gcG91ciBsZXMgYXJ0aXN0ZXMgZXQgdW4gbm91dmVhdSB2ZWN0ZXVyIGRlIHRyYW5zbWlzc2lvbiBkZSBsYSBjdWx0dXJlLiBEYW5zIHVuZSBzb2Npw6l0w6kgZ291dmVybsOpZSBwYXIgbGEgY29tbXVuaWNhdGlvbiBldCBsYSByYXBpZGl0w6kgZGVzIMOpY2hhbmdlcywgbGVzIHByYXRpcXVlcyBjdWx0dXJlbGxlcyBvbnQgc3ViaSBsYSBtdXRhdGlvbiBkZSBjZXR0ZSBpbnN0YW50YW7DqWl0w6kgYWJzb2x1ZS4gRW4gcXVlbHF1ZXMgY2xpY3MsIGxlcyBpbnRlcm5hdXRlcyBwZXV2ZW50IGF1am91cmTigJlodWkgZMOpY291dnJpciBkZXMgdmlkw6lvcyBldCBkZXMgY29udGVudXMgcHVibGnDqXMgc3VyIHRvdXMgbGVzIGNvbnRpbmVudHMsIHNvdXRlbmlyIHVuIGFydGlzdGUgcXXigJlpbHMgYWZmZWN0aW9ubmVudCBldCBsaXJlIHVuIHJvbWFuIG51bcOpcmlzw6kgZW4gbGlnbmUuPC9wPg0KPHA%TGVzIHLDqXNlYXV4IHNvY2lhdXggYWdpc3NlbnQgY29tbWUgZGVzIHLDqXbDqWxhdGV1cnMgZGUgdGFsZW50cyBwYXIgbGUgYmlhaXMgZGVzIHBsYXRlZm9ybWVzIHBhcnRpY2lwYXRpdmVzIGV0IHBlcm1ldHRlbnQgw6AgZGVzIGFydGlzdGVzIGRlIHNlIGZhaXJlIGNvbm5hw650cmUgZHUgcHVibGljIHNhbnMgYXZvaXIgw6Agc2Ugc291bWV0dHJlIGF1eCBjZXJjbGVzIGRlIGzDqWdpdGltYXRpb248YnIgLz4NCnRyYWRpdGlvbm5lbHMuIENlcGVuZGFudCwgw6l2b3F1ZXIgbOKAmWV4cGxvaXRhdGlvbiBkZXMgcsOpc2VhdXggc29jaWF1eCBwYXIgbGVzIGFydGlzdGVzIG7DqWNlc3NpdGUgZGUgc%KAmWludGVycm9nZXIgc3VyIGxldXIgY29udHLDtGxlIGV0IGzigJlpbXBhY3QgcXXigJlpbHMgc29udCBzdXNjZXB0aWJsZXMgZOKAmWF2b2lyIHN1ciBsZSBkcm9pdCBk4oCZYXV0ZXVyIGV0IHN1ciBsYSBwcm9wcmnDqXTDqSBpbnRlbGxlY3R1ZWxsZS48L3A%DQo8cD5Qb3VyIHLDqXBvbmRyZSDDoCBjZXMgcXVlc3Rpb25zIG5vdXZlbGxlcywgYXV0b3VyIGRlIGNldHRlIHRhYmxlIHJvbmRlIGRpZmbDqXJlbnRzIHNww6ljaWFsaXN0ZXMgc2Vyb250IHByw6lzZW50cyA6IDxzdHJvbmc%SnVsaWVuIFJBU1RFR0FSPC9zdHJvbmc%IChqb3VybmFsaXN0ZSBzY2llbnRpZmlxdWUpLCA8c3Ryb25nPk5pY29sYXMgTE9VQkVUPC9zdHJvbmc%IChlbnRyZXByZW5ldXIgZXQgY29uc3VsdGFudCBVbWFwcyk8YnIgLz4NCjxzdHJvbmc%TWFyaW5lIEpPVUFOPC9zdHJvbmc%IChjaGFyZ8OpIGRlcyBwcm9qZXRzIGRlIEtpc3NLaXNzIEJhbmtCYW5rKSwgPHN0cm9uZz5BbXlsZWU8L3N0cm9uZz4gKGFydGlzdGUgcGxhc3RpY2llbm5lKSBldCA8c3Ryb25nPk5hdGhhbGllIERSRVlGVVM8L3N0cm9uZz4gKGp1cmlzdGUpLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2xlLWpldWRpLTEyLWF2cmlsLWxlcy1yZXNlYXV4LXNvY2lhdXgtcyVlMiU4MCU5OWludml0ZW50LWF1LXBhbGFpcy1kZS1sYS1kZWNvdXZlcnRlL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjE8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5TUEVBUiBwcm9mZXNzaW9ubmFsaXNlIGxlIGNyb3dkbGVuZGluZyDDqXRoaXF1ZTwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvc3BlYXItcHJvZmVzc2lvbm5hbGlzZS1sZS1jcm93ZGxlbmRpbmctZXRoaXF1ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDE2OjA4OjQ5ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5KdWxpZW4gTWVjaGluPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2Nyb3dkbGVuZGluZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtzcGVhcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4ODA8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODgyIiB0aXRsZT0ic3BlYXIiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3NwZWFyLnBuZyIgYWx0PSIiIHdpZHRoPSIyNTAiIGhlaWdodD0iNjkiIC8%DQoNCkFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%Lg0KDQpJbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4ODIiIHRpdGxlPSJzcGVhciIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc3BlYXIucG5nIiBhbHQ9IiIgd2lkdGg9IjI1MCIgaGVpZ2h0PSI2OSIgLz48L3A%DQo8cD5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5JbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLjwvcD4NCjxwPlNQRUFSIHByb3Bvc2UgZGUgZsOpZMOpcmVyIGxlcyDDqXBhcmduYW50cyBhZmluIGRlIGxldXIgcGVybWV0dHJlIGRlIG1ldHRyZSBsZXVyIGFyZ2VudCBhdSBzZXJ2aWNlIGRlIHByb2pldHMgcXXigJlpbHMgY2hvaXNpc3NlbnQsIGV0IHF1aSBvbnQgZHUgc2VucyDDoCBsZXVycyB5ZXV4ICjDqWNvbG9naXF1ZXMsIHNvY2lhdXggb3UgY3VsdHVyZWxzKS4gw4AgbGEgZGlmZsOpcmVuY2UgZGUgc3RydWN0dXJlcyBjb21tZSBLaWNrc3RhcnRlciBvdSBNeW1ham9yY29tcGFueSwgU1BFQVIgcHJvcG9zZSBk4oCZaW52ZXN0aXIgZW4gZGV0dGUsIGV0IHPDqWxlY3Rpb25uZSBsZXMgaW5pdGlhdGl2ZXMgcXXigJlpbCBlc3QgcG9zc2libGUgZOKAmWFpZGVyIGVuIGZvbmN0aW9uIGRlIGNyaXTDqHJlcyDDqXRoaXF1ZXMgZXQgZmluYW5jaWVycy4gIExlIHRvdXQgc2FucyBhdWN1biByaXNxdWUgcG91ciBs4oCZw6lwYXJnbmFudC48L3A%DQo8cD5Qb3VyIHJlbmRyZSBwb3NzaWJsZSBjZXR0ZSDDqXF1YXRpb24sIFNQRUFSIHPigJllc3QgYWxsacOpIMOgIGRlcyBiYW5xdWVzIChsZSBDcsOpZGl0IE11bmljaXBhbCBkZSBQYXJpcyAgcG91ciBsZSBtb21lbnQsIGRlcyBwYXJ0ZW5hcmlhdCBhdmVjIGxlIENyw6lkaXQgQ29vcMOpcmF0aWYgZXQgbGEgQ2Fpc3NlIGTigJkgw4lwYXJnbmUgc29udCBlbiBib25uZSB2b2llKSBxdWkgc8OpY3VyaXNlbnQgbGUgcHLDqnQgbW95ZW5uYW50IHVuZSBjb21taXNzaW9uIGRlc3RpbsOpZSDDoCBjb21wZW5zZXIgbGUgcmlzcXVlIGRlIGTDqWZhdXQuIEzigJllbnRyZXByZW5ldXIgb2J0aWVudCBhaW5zaSBmYWNpbGVtZW50IHVuIGNyw6lkaXQgcG91ciB1biB0YXV4IGluZsOpcmlldXIgYXUgdGF1eCBkdSBtYXJjaMOpIGV0IGzigJnDqXBhcmduYW50LCBtb3llbm5hbnQgdW5lIG1vZGlxdWUgZGltaW51dGlvbiBkZSBzb24gdGF1eCBkZSByZW5kZW1lbnQsIG1ldCBzb24gYXJnZW50IGF1IHNlcnZpY2UgZGUgc2VzIGNvbnZpY3Rpb25zLiBVbiBiw6luw6lmaWNlIGF1cXVlbCBz4oCZYWpvdXRlbnQgbGVzIGNsYXNzaXF1ZXMgZGlzcG9zaXRpZnMgZGUgZMOpZHVjdGlvbiBkZSBs4oCZSVNGIGV0IGRlIGzigJlJUlBQLCBwdWlzcXVlIGzigJnDqXBhcmduZSBzZSByw6lhbGlzZSBwYXIgbGEgc291c2NyaXB0aW9uIGRlIHBhcnRzIHNvY2lhbGVzIGRlIFNQRUFSLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvQ2FwdHVyZS1k4oCZw6ljcmFuLTIwMTItMDMtMjYtw6AtMjMuMzYuNDYucG5nIj48aW1nIGNsYXNzPSJzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4ODEgYWxpZ25jZW50ZXIiIHRpdGxlPSJDYXB0dXJlIGTigJnDqWNyYW4gMjAxMi0wMy0yNiDDoCAyMy4zNi40NiIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvQ2FwdHVyZS1k4oCZw6ljcmFuLTIwMTItMDMtMjYtw6AtMjMuMzYuNDYucG5nIiBhbHQ9IiIgd2lkdGg9IjQ4NyIgaGVpZ2h0PSIzNzQiIC8%PC9hPjwvcD4NCjxwPk1vaW5zIGRlIDE1JSBkZXMgcHJvamV0cyBzb3VtaXMgw6AgU1BFQVIgc29udCByZXRlbnVzIHBhciBzb24gY29taXTDqS4gUG91ciBsZSBtb21lbnQsIDIwMCAwMDAgZXVyb3MgZOKAmSDCqyDDqXBhcmduZSB0cmFuc3BhcmVudGUgwrsgb250IGZpbmFuY8OpcyAzIHByb2pldHMsIGV0IDIgc29udCBlbiBwYXNzZSBkZSBs4oCZw6p0cmUgKDxhIGhyZWY9Imh0dHA6Ly9zcGVhci5mci9wcm9qZXRzLzE2Ij4gQ2xhaXIgJmFtcDsgTmV0IDwvYT4sIGVudHJlcHJpc2UgZOKAmWluc2VydGlvbiBwYXIgbGUgdHJhdmFpbCBkYW5zIGxlIHNlY3RldXIgZGUgbOKAmcOpY29wcm9wcmV0w6kgZXQgPGEgaHJlZj0iaHR0cDovL3NwZWFyLmZyL3Byb2pldHMvMTgiPiBCYXNpbGlhZGUgPC9hPiwgc3RydWN0dXJlIGTigJlhaWRlIGF1eCBtYWxhZGVzIGR1IFNJREEpLiA1IGF1dHJlcyBsZXMgcmVqb2luZHJvbnQgZOKAmWljaSBs4oCZw6l0w6kgKHVuIHByb2pldCB2aXNhbnQgw6AgZm91cm5pciBkZXMgbHVuZXR0ZXMgZGUgcsOpYWxpdMOpIGF1Z21lbnTDqWUgYXV4IG1hbGFkZXMgY2hyb25pcXVlcyBpbW1vYmlsaXPDqXMgc2VyYWl0IG5vdGFtbWVudCBkYW5zIGxlcyB0dXlhdXgpLjwvcD4NCjxwPkF2aXMgYXV4IGdlZWtzIGF1IGdyYW5kIGPFk3VyIDogbGEgcGxhdGVmb3JtZSwgbGF1csOpYXRlIGR1IFByaXggU0ZSIEpldW5lcyBUYWxlbnRzIEVudHJlcHJlbmV1cmlhdCBTb2NpYWwsIGVzdCBjb2TDqWUgZW4gUnVieSBvbiBSYWlscy4gRXQgZGVzIHJlY3J1dGVtZW50cyBzb250IGF1IHByb2dyYW1tZeKApjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPldhbGxpdCBjcsOpZSBkZXMgbXVycyB2aXJ0dWVscyBlbiByw6lhbGl0w6kgYXVnbWVudMOpZSBkYW5zIGxlcyBsaWV1eCBwdWJsaWNzPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvd2FsbGl0LWNyZWUtZGVzLW11cnMtdmlydHVlbHMtZW4tcmVhbGl0ZS1hdWdtZW50ZWUtZGFucy1sZXMtbGlldXgtcHVibGljcy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy93YWxsaXQtY3JlZS1kZXMtbXVycy12aXJ0dWVscy1lbi1yZWFsaXRlLWF1Z21lbnRlZS1kYW5zLWxlcy1saWV1eC1wdWJsaWNzLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPlR1ZSwgMjcgTWFyIDIwMTIgMDk6Mjk6MDYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbd2FsbGl0XV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg1MjwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9IndhbGxpdCIgc3JjPSJodHRwOi8vd2FsbGl0YXBwLmNvbS9pbWcvbG9nb193YWxsaXRfaWNvbi5wbmciIGFsdD0iIiB3aWR0aD0iMjMyIiBoZWlnaHQ9IjkyIiAvPiBBcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9jZWNpbG9nZSIgdGFyZ2V0PSJfYmxhbmsiPkPDqWNpbGUgTG9nw6k8L2E%Lg0KDQpDcsOpw6llIHBhciA8YSBocmVmPSJodHRwOi8vd3d3LmxpbmtlZGluLmNvbS9wdWIvdmV5c2VsLWJlcmsvMTAvMTExLzIxMiI%VmV5c2VsIEJlcms8L2E%LCB1biBhbmNpZW4gZGUgVUMgQmVya2VsZXkgcGxlaW4gZOKAmWlkw6llcyBldCBkw6l0ZW50ZXVyIGTigJl1biBQaEQgZW4gUGh5c2lxdWUsIDxhIGhyZWY9Imh0dHA6Ly93d3cud2FsbGl0YXBwLmNvbS8iPldhbGxpdDwvYT4gZXN0IHVuZSBub3V2ZWxsZSBhcHBsaWNhdGlvbiBpUGhvbmUgZ3JhdHVpdGUgcXVpIGNoZXJjaGUgw6AgY2hhbmdlciBub3RyZSB2aXNpb24gZGVzIGxpZXV4IHB1YmxpY3M6IGxhbmPDqWUgZMOpYnV0IG1hcnMsIGzigJlhcHBsaWNhdGlvbiBwZXJtZXQgZGUgY29tbXVuaXF1ZXIgYXZlYyBsZXMgcGVyc29ubmVzIHF1aSBzb250IGF1IG3Dqm1lIGVuZHJvaXQgYXUgbcOqbWUgbW9tZW50IHBhciBs4oCZaW50ZXJtw6lkaWFpcmUgZGUgbGEgcsOpYWxpdMOpIGF1Z21lbnTDqWUuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0id2FsbGl0IiBzcmM9Imh0dHA6Ly93YWxsaXRhcHAuY29tL2ltZy9sb2dvX3dhbGxpdF9pY29uLnBuZyIgYWx0PSIiIHdpZHRoPSIyMzIiIGhlaWdodD0iOTIiIC8%IEFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL2NlY2lsb2dlIiB0YXJnZXQ9Il9ibGFuayI%Q8OpY2lsZSBMb2fDqTwvYT4uPC9wPg0KPHA%Q3LDqcOpZSBwYXIgPGEgaHJlZj0iaHR0cDovL3d3dy5saW5rZWRpbi5jb20vcHViL3ZleXNlbC1iZXJrLzEwLzExMS8yMTIiPlZleXNlbCBCZXJrPC9hPiwgdW4gYW5jaWVuIGRlIFVDIEJlcmtlbGV5IHBsZWluIGTigJlpZMOpZXMgZXQgZMOpdGVudGV1ciBk4oCZdW4gUGhEIGVuIFBoeXNpcXVlLCA8YSBocmVmPSJodHRwOi8vd3d3LndhbGxpdGFwcC5jb20vIj5XYWxsaXQ8L2E%IGVzdCB1bmUgbm91dmVsbGUgYXBwbGljYXRpb24gaVBob25lIGdyYXR1aXRlIHF1aSBjaGVyY2hlIMOgIGNoYW5nZXIgbm90cmUgdmlzaW9uIGRlcyBsaWV1eCBwdWJsaWNzOiBsYW5jw6llIGTDqWJ1dCBtYXJzLCBs4oCZYXBwbGljYXRpb24gcGVybWV0IGRlIGNvbW11bmlxdWVyIGF2ZWMgbGVzIHBlcnNvbm5lcyBxdWkgc29udCBhdSBtw6ptZSBlbmRyb2l0IGF1IG3Dqm1lIG1vbWVudCBwYXIgbOKAmWludGVybcOpZGlhaXJlIGRlIGxhIHLDqWFsaXTDqSBhdWdtZW50w6llLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvd2FsbGl0LnBuZyI%PGltZyBjbGFzcz0ic2l6ZS1mdWxsIHdwLWltYWdlLTIzODUzIGFsaWduY2VudGVyIiB0aXRsZT0id2FsbGl0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy93YWxsaXQucG5nIiBhbHQ9IiIgd2lkdGg9IjQ0MyIgaGVpZ2h0PSIyOTciIC8%PC9hPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%RT9uIGZhaXQsIFdhbGxpdCBtw6lsYW5nZSBsZXMgdHJhaXRzIGRlcyBwbHVzIGdyYW5kcyByw6lzZWF1eCBzb2NpYXV4OiBsZXMgaW50ZXJhY3Rpb25zIHNvY2lhbGVzIGRlIEZhY2Vib29rLCBsZXMgMTQwIGNhcmFjdMOocmVzIG1heGltdW0gZGUgVHdpdHRlciBldCBsYSBnw6lvbG9jYWxpc2F0aW9uIGRlIEZvdXJzcXVhcmUsIGxlIHRvdXQgYXBwbGlxdcOpIMOgIGRlcyBtdXJzIHZpcnR1ZWxzIGFjY2Vzc2libGVzIGVuIHLDqWFsaXTDqSBhdWdtZW50w6llLiBJbWFnaW5vbnMgdW4gw6l2w6huZW1lbnQgaW1wb3J0YW50IGNvbW1lIHVuIG1hdGNoIGRlIGZvb3QsIG91IHVuIGZlc3RpdmFsOiBsZXMgcGFydGljaXBhbnRzIG7igJlhdXJvbnQgcXXigJnDoCBvdXZyaXIgbOKAmWFwcGxpY2F0aW9uLCBldCBzZSBnw6lvbG9jYWxpc2VyIHBvdXIgdm9pciBhcHBhcmFpdHJlIGxlIG11ciB2aXJ0dWVsIMOgIHRyYXZlcnMgbGEgY2Ftw6lyYSBkZSBsZXVyIGlQaG9uZSBldCBjb21tdW5pcXVlciBlbnRyZSBldXguIFBob3RvcywgY29tbWVudGFpcmVzLCB2aWTDqW9zLCBvdSBtZXNzYWdlcyBhdWRpb3MuLiBUb3V0IGVzdCBwb3NzaWJsZSE8L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3dhbGxpdDIucG5nIj48aW1nIGNsYXNzPSJzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4NTQgYWxpZ25jZW50ZXIiIHRpdGxlPSJ3YWxsaXQyIiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy93YWxsaXQyLnBuZyIgYWx0PSIiIHdpZHRoPSI0NDEiIGhlaWdodD0iMjk3IiAvPjwvYT48L3A%DQo8cD5XYWxsaXQgYSBkw6lqw6AgY3LDqcOpIHBsdXMgZGUgNzAwIG11cnMgdW4gcGV1IHBhcnRvdXQgZGFucyBsZSBtb25kZSAoTG9uZHJlcywgVG9reW8sIE5ldy1Zb3JrLCBQYXJpcy4uKS4gVW5lIGZvaXMgc3VyIHBsYWNlLCBvbiBwZXV0IGFwcG9ydGVyIHNhIGNvbnRyaWJ1dGlvbiBzb2l0IGFub255bWVtZW50LCBzb2l0IGVuIHNlIGxvZ2dhbnQgc3VyIEZhY2Vib29rIG91IFR3aXR0ZXI6IGJpZW50w7R0LCBkZXMgZm9uY3Rpb25zIHNvY2lhbGVzIHBlcm1ldHRhbnQgZGUgZmlsdHJlciBsZXMgcG9zdHMgKGFtaXMgRmFjZWJvb2sgIHNldWxlbWVudCBwYXIgZXhlbXBsZSkgc2Vyb250IMOpZ2FsZW1lbnQgZGlzcG9uaWJsZXMuPC9wPg0KPHA%QWxvcnMgcXVlIGxlcyBhdXRyZXMgYXBwcyBnw6lvbG9jYWxpc8OpZXMgZXQgbGVzIHLDqXNlYXV4IHNvY2lhdXggY29tbWUgRm91cnNxdWFyZSBzZSBmb2NhbGlzZW50IGfDqW7DqXJhbGVtZW50IHN1ciBsZXMgcHJvZmlscyBkZXMgdXRpbGlzYXRldXJzLCBjZWxsZS1jaSBhbWJpdGlvbm5lIGRlIGRvbm5lciB2aWUgYXV4IGxpZXV4IGV1eC1tw6ptZXMgZ3LDomNlIMOgIGxldXJzIHZpc2l0ZXVycy4gQmVyayBpbnNpc3RlIGTigJlhaWxsZXVycyBzdXIgbOKAmWlkw6llIHF1ZSBXYWxsaXQg4oCcPGVtPmNvbnRyaWJ1ZSDDoCBlbnRyZXRlbmlyIGzigJllc3NlbmNlIGRlcyBsaWV1eDwvZW0%4oCdIGV0IMOgIOKAnDxlbT5jdWx0aXZlciBsZXVyIHBlcnNvbm5hbGl0w6k8L2VtPuKAnSBncsOiY2UgYXUgcGFydGFnZSBk4oCZZXhww6lyaWVuY2VzLCBkZSBwaG90b3MsIGRlIGNvbW1lbnRhaXJlcyBkZXMgZ2VucyBxdWkgeSBwYXNzZW50IHBoeXNpcXVlbWVudC48L3A%DQo8cD48aWZyYW1lIHdpZHRoPSI1NjAiIGhlaWdodD0iMzE1IiBzcmM9Imh0dHA6Ly93d3cueW91dHViZS5jb20vZW1iZWQvTXgxQ3kzc21ScjAiIGZyYW1lYm9yZGVyPSIwIiBhbGxvd2Z1bGxzY3JlZW4%PC9pZnJhbWU%PC9wPg0KPHA%V2FsbGl0IGEgcsOpY2VtbWVudCBsZXbDqSAxLjJNJCBkZSBmb25kcyBhdXByw6hzIGRlIGRpZmbDqXJlbnRzIGJ1c2luZXNzIGFuZ2VscyBldCBmb25kcyBk4oCZaW52ZXN0aXNzZW1lbnRzLCBldCBkZXMgdmVyc2lvbnMgaVBhZCBldCBBbmRyb2lkIHNvbnQgZW4gY291cnMgZGUgZMOpdmVsb3BwZW1lbnQuIElsIHPigJlhZ2lyYSBlbnN1aXRlIGRlIG1vbsOpdGlzZXIgbGUgcHJvamV0IGVuIGltcGxpcXVhbnQgZGVzIHBhcnRlbmFpcmVzIGV0IGRlcyBncmFuZGVzIG1hcnF1ZXMsIG5vdGFtbWVudCBlbiBsZXMgYWlkYW50IMOgIGNyw6llciBsZXVycyBwcm9wcmVzIG11cnMvcGFubmVhdXggZGUgcHViIGludGVyYWN0aWZzIGV0IHZpcnR1ZWxzLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3dhbGxpdC1jcmVlLWRlcy1tdXJzLXZpcnR1ZWxzLWVuLXJlYWxpdGUtYXVnbWVudGVlLWRhbnMtbGVzLWxpZXV4LXB1YmxpY3MvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%NDwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPlNjaWVudGlwb2xlIEluaXRpYXRpdmUgZsOqdGUgc2VzIDEwIGFuczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPk1vbiwgMjYgTWFyIDIwMTIgMDk6MTg6MjYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc2NpZW50aXBvbGUgaW5pdGlhdGl2ZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4NDE8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc2NpZW50aXBvbGUucG5nIj48aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODQ1IiB0aXRsZT0ic2NpZW50aXBvbGUiIHNyYz0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3NjaWVudGlwb2xlLnBuZyIgYWx0PSIiIHdpZHRoPSIzNzciIGhlaWdodD0iOTEiIC8%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICENCl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9zY2llbnRpcG9sZS5wbmciPjxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4NDUiIHRpdGxlPSJzY2llbnRpcG9sZSIgc3JjPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvc2NpZW50aXBvbGUucG5nIiBhbHQ9IiIgd2lkdGg9IjM3NyIgaGVpZ2h0PSI5MSIgLz48L2E%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICE8L3A%DQo8cD5MZSBwcsOqdCBk4oCZaG9ubmV1ciBlc3QgdW4gcHLDqnQgw6AgdGF1eCAwIHF1ZSBwZXV0IHJlY2V2b2lyIHRvdXQgY3LDqWF0ZXVyIGTigJllbnRyZXByaXNlLCBzYW5zIGdhcmFudGllIHBlcnNvbm5lbGxlIGV0IGRvbnQgbGUgbW9udGFudCBwZXV0IGFsbGVyIGp1c3F14oCZw6AgNjAgMDAwIGV1cm9zIHBhciBlbnRyZXByaXNlLiBM4oCZb2JqZWN0aWYgZHUgcHLDqnQgZOKAmWhvbm5ldXIgZXN0IGTigJlhbW9yY2VyIGxhIGNvbW1lcmNpYWxpc2F0aW9uIGTigJl1biBwcm9kdWl0IG91IGTigJl1bmUgdGVjaG5vbG9naWUgZW4gdnVlIGTigJl1biBlZmZldCBkZSBsZXZpZXIgcG91ciBs4oCZb2J0ZW50aW9uIGRlIHByw6p0cyBiYW5jYWlyZXMuPC9wPg0KPHA%UG91ciBwcsOpdGVuZHJlIMOgIGNlIHR5cGUgZGUgcHLDqnQsIGwmIzgyMTc7ZW50cmVwcmlzZSBkb2l0IGF2b2lyIG1vaW5zIGRlIDMgYW5zLCDDqnRyZSBpbnN0YWxsw6llIGVuIElsZSBkZSBGcmFuY2UsIHByb3Bvc2VyIHVuZSBpbm5vdmF0aW9uLCBldCBwb3Nzw6lkZXIgdW4gcG90ZW50aWVsIGRlIGNyw6lhdGlvbnMgZCYjODIxNztlbXBsb2lzLjwvcD4NCjxwPlBvdXIgZsOqdGVyIHNhIDEww6htZSBhbm7DqWUgZGUgc291dGllbiBhdXggc3RhcnQgdXAsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIG9yZ2FuaXNlIHVuIMOpdsOobmVtZW50IGRlIDE0aCDDoCAxOWggbGUgMjggTWFycyDDoCBs4oCZaMO0dGVsIGRlIHZpbGxlIGRlIFBhcmlzLiBMZSA8YSBocmVmPSJodHRwOi8vd3d3LjEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnL3Byb2dyYW1tZS5odG1sIj5wcm9ncmFtbWU8L2E%IGFubm9uY2UgbGEgdmVudWUgZGUgUmFvdWwgTWFsbGFydCwgRGlyZWN0ZXVyIEJ1c2luZXNzIERldmVsb3BwZW1lbnQgZCYjODIxNztBcmNob3MsIG91IGVuY29yZSBkZSBSYWZpIEhhbGFkamlhbiwgZm9uZGF0ZXVyIGRlIE5hYmF6dGFnLiBMZXMgaW5zY3JpcHRpb25zIHNvbnQgPGEgaHJlZj0iaHR0cDovL3d3dy4xMGFucy1zY2llbnRpcG9sZS1pbml0aWF0aXZlLm9yZy9pbnNjcmlwdGlvbi5odG1sIj5pY2k8L2E%IGV0IGwmIzgyMTc7YWN0dWFsaXTDqSBkdSBTY2llbnRpcG9sZSBlc3QgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9TY2llbnRJbml0aWF0aXYiPmzDoC4gPC9hPjwvcD4NCjxwPjxpZnJhbWUgd2lkdGg9IjU2MCIgaGVpZ2h0PSIzMTUiIHNyYz0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9lbWJlZC9DcVYwVW82SDFiVSIgZnJhbWVib3JkZXI9IjAiIGFsbG93ZnVsbHNjcmVlbj48L2lmcmFtZT48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNi9zY2llbnRpcG9sZS1pbml0aWF0aXZlLWZldGUtc2VzLTEwLWFucy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%VENGUiDigJMgTGUgemFwcGluZyBkZSBsYSBzZW1haW5lPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAyMyBNYXIgMjAxMiAxODoyNDozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%Q2VkcmljIE8nTmVpbGw8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3RhcnR1cF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0Y2ZyXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3phcHBpbmddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODMyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMS9icmVmLmpwZyIgYWx0PSIiIHdpZHRoPSIyNDUiIGhlaWdodD0iMTgzIiAvPi0gTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQnYXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuDQoNCi0gQW50b2luZSBWaWFsbGUsIHNlcmlhbCBlbnRyZXByZW5ldXIgdmllbnQgZGUgY2FydG9ncmFwaGllciBsZXMgYWlkZXMgZXQgc3VidmVudGlvbnMgZGlzcG9uaWJsZXMgZW4gRnJhbmNlIHBvdXIgbGVzIGNyw6lhdGV1cnMgZCdlbnRyZXByaXNlLiBDaGFxdWUgbGlnbmUgY29ycmVzcG9uZCBhdSBuaXZlYXUgZGUgbWF0dXJpdMOpIGQndW5lIHNvY2nDqXTDqS4gVm91cyBwb3VycmV6IGxhIHJldHJvdXZlciDDoCA8YSBocmVmPSJodHRwOi8vd3d3LmFpZGVzLWNyZWF0aW9uLmZyL29mZnJlLXNwZWFjdXRlY2lhbGUtaW50ZXJuZXQuaHRtbCI%Y2V0dGUgYWRyZXNzZTwvYT4uXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiBzcmM9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMS9icmVmLmpwZyIgYWx0PSIiIHdpZHRoPSIyNDUiIGhlaWdodD0iMTgzIiAvPi0gTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQmIzgyMTc7YXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuPC9wPg0KPHA%LSBBbnRvaW5lIFZpYWxsZSwgc2VyaWFsIGVudHJlcHJlbmV1ciB2aWVudCBkZSBjYXJ0b2dyYXBoaWVyIGxlcyBhaWRlcyBldCBzdWJ2ZW50aW9ucyBkaXNwb25pYmxlcyBlbiBGcmFuY2UgcG91ciBsZXMgY3LDqWF0ZXVycyBkJiM4MjE3O2VudHJlcHJpc2UuIENoYXF1ZSBsaWduZSBjb3JyZXNwb25kIGF1IG5pdmVhdSBkZSBtYXR1cml0w6kgZCYjODIxNzt1bmUgc29jacOpdMOpLiBWb3VzIHBvdXJyZXogbGEgcmV0cm91dmVyIMOgIDxhIGhyZWY9Imh0dHA6Ly93d3cuYWlkZXMtY3JlYXRpb24uZnIvb2ZmcmUtc3BlYWN1dGVjaWFsZS1pbnRlcm5ldC5odG1sIj5jZXR0ZSBhZHJlc3NlPC9hPi48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cueW91c2VlbWlpLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPllvdXNlZW1paSA8L2E%cHLDqXNlbnRlIHNhIG5vdXZlbGxlIHZlcnNpb24sIGF2ZWMgdW4gbm91dmVhdSBkZXNpZ24sIGV0IHN1cnRvdXQgdW5lIG5vdXZlbGxlIGV4cMOpcmllbmNlIHV0aWxpc2F0ZXVyLiBEw6lzb3JtYWlzLCBsZSBsb2dpY2llbCBwZXJtZXQgYXVzc2kgZCYjODIxNzthbmFseXNlciBzYSBwcsOpc2VuY2Ugd2ViIHN1ciBGb3Vyc3F1YXJlLCBHb29nbGUgKywgRGFpbHltb3Rpb24sIFZpbWVvLCBldCBtw6ptZSBhdXByw6hzIGRlcyBraW9zcXVlcyBSZWxheS48L3A%DQo8cD4tTGUgcsOpc2VhdSBzb2NpYWwgbW9iaWxlIDxhIGhyZWY9Imh0dHBzOi8vcGF0aC5jb20vIj5QYXRoPC9hPiBsw6h2ZSAyMCBtaWxsaW9ucyBkZSBkb2xsYXJzLiBMZSByw6lzZWF1IHNvY2lhbCBkZSBwYXJ0YWdlIGRlIHBob3RvcyBsaW1pdMOpIMOgIDUwIGNvbnRhY3RzIGV0IGRpc3BvbmlibGUgZXhjbHVzaXZlbWVudCBzdXIgbOKAmWFwcGxpIGlQaG9uZSBkdSBtw6ptZSBub20gc2VyYWl0IGFpbnNpIHZhbG9yaXPDqSAyNTBNJC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmVkeWNhc2EuY29tLyI%QmVkeUNhc2E8L2E%IGdhZ25lIGxlcyBUcmF2ZWwgZOKAmU9yIGRhbnMgbGEgY2F0w6lnb3JpZSBzdGFydC11cCwgcXVpIHLDqWNvbXBlbnNlIGxlcyBtZWlsbGV1cnMgc2l0ZXMgZOKAmWUtdG91cmlzbWUuIEJlZHljYXNhLCBwZXJtZXQgbGEgbG9jYXRpb24gZGUgY2hhbWJyZXMgY2hleiBs4oCZaGFiaXRhbnQuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHBzOi8vc2Vlc21pYy5jb20vIj5TZWVzbWljPC9hPiBhbm5vbmNlIHVuZSB2YWd1ZSBkZSBsaWNlbmNpZW1lbnRzLiBMYSBzdGFydC11cCBmb25kw6llIHBhciA8c3Ryb25nPkxvw69jIExlIE1ldXI8L3N0cm9uZz4sIG9yZ2FuaXNhdGV1ciBkZSBsYSBjb25mw6lyZW5jZSA8c3Ryb25nPkxlV2ViPC9zdHJvbmc%IGRldnJhaXQgbGljZW5jaWVyIDE4IHBlcnNvbm5lcyBmYXV0ZSBkZSBidXNpbmVzcyBtb2RlbCB2aWFibGUuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHA6Ly93d3cuZWFzeS12ZXJyZXMuY29tLyI%RWFzeS12ZXJyZXM8L2E%LCBs4oCZb3B0aWNpZW4gbG93IGNvc3QgcXVpIGNvbXB0ZXJhaXQgcHLDqHMgZGUgNzUwIG9wdGljaWVucyBwYXJ0ZW5haXJlcyB2aWVudCBkZSBsZXZlciAxTeKCrC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuaWxsaWNvdHJhdmVsLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5pbGxpY290cmF2ZWw8L2E%LCBsZSBjb21wYXJhdGV1ciBkZSB2b2xzIGV0IGRlIHZveWFnZXMgb25saW5lIHZpZW50IGRlIGxhbmNlciB1bmUgbm91dmVsbGUgdmVyc2lvbiBkZSBzb24gaW50ZXJmYWNlLjwvcD4NCjxwPi08c3Ryb25nPiA8YSBocmVmPSJodHRwOi8vd3d3LnJveWFsY2FjdHVzLmNvbS8iPlJveWFsIENhY3R1czwvYT48L3N0cm9uZz4sIHNww6ljaWFsaXN0ZSBkdSBqZXUgZW4gbGlnbmUgY29tbXVuYXV0YWlyZSwgdmllbnQgZGUgbGV2ZXIgNTAwIDAwMCBldXJvcyBhdXByw6hzIGR1IGZvbmRzIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnQgPHN0cm9uZz5YQW5nZSBQcml2YXRlIEVxdWl0eTwvc3Ryb25nPi4gT2JqZWN0aWYgYWZmaWNow6kgOiBkZXZlbmlyIHVuIGRlcyBsZWFkZXJzIGZyYW7Dp2FpcyBkdSBTb2NpYWwgR2FtaW5nIGVuIG1lbmFudCB1bmUgc3RyYXTDqWdpZSBjcm9zcy1jaGFubmVsLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzIzL3RjZnItJWUyJTgwJTkzLWxlLXphcHBpbmctZGUtbGEtc2VtYWluZS0yL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgk8L2NoYW5uZWw%DQo8L3Jzcz4NCg"}];
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
haxe.Unserializer.DEFAULT_RESOLVER = Type;
haxe.Unserializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
haxe.Unserializer.CODES = null;
js.Lib.onerror = null;
org.intermedia.model.ApplicationModel.CELL_QTY = 15;
org.intermedia.model.Feeds.FEED_1 = { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"};
org.intermedia.model.Feeds.FEED_2 = { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"};
org.intermedia.model.Feeds.FEED_3 = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"};
org.intermedia.view.CellTextStyle.CELL_VERTICAL_SPACE = 4;
org.intermedia.view.CellTextStyle.CELL_HORIZONTAL_SPACE = 2;
org.intermedia.view.CellThumbText1BisStyle.CELL_TEXT_WIDTH_PERCENT = 60;
org.intermedia.view.CellThumbText1BisStyle.CELL_THUMB_WIDTH_PERCENT = 35;
org.intermedia.view.CellThumbText1Style.CELL_TEXT_WIDTH_PERCENT = 60;
org.intermedia.view.CellThumbText1Style.CELL_THUMB_WIDTH_PERCENT = 34;
org.intermedia.view.CellThumbText1Style.CELL_TOP_MARGIN_PERCENT = 8;
org.intermedia.view.Constants.HEADER_HOME_TITLE = "French Tech";
org.intermedia.view.Constants.HEADER_DETAIL_TITLE = "Infos";
org.intermedia.view.Constants.HEADER_BG_IMAGE_URL = "";
org.intermedia.view.Constants.HEADER_FONT_COLOR = "#EEEEEE";
org.intermedia.view.Constants.HEADER_HEIGHT = 43;
org.intermedia.view.Constants.HEADER_WITH_SHADOW_HEIGHT = 43;
org.intermedia.view.Constants.HEADER_IMAGE_URL = "assets/rss-icon.png";
org.intermedia.view.Constants.MENU_BG_IMAGE_URL = "";
org.intermedia.view.Constants.MENU_HEIGHT = 35;
org.intermedia.view.Constants.MENU_LATERAL_OFFSET = 30;
org.intermedia.view.Constants.MENU_FONT_COLOR = "#AAAAAA";
org.intermedia.view.Constants.SWIP_HORIZONTAL_WIDTH_RATIO = 0.1;
org.intermedia.view.Constants.SWIP_HORIZONTAL_TWEEN_DELAY = 150;
org.intermedia.view.Constants.LIST_TOP = 78;
org.intermedia.view.Constants.LIST_BG_GREY_COLOR = "";
org.intermedia.view.Constants.LIST_BG_BLACK_COLOR = "";
org.intermedia.view.Constants.LIST_BOTTOM_LOADER_VERTICAL_MARGIN = 10;
org.intermedia.view.Constants.CELL_BG_COLOR = "";
org.intermedia.view.Constants.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.Constants.CELL_BORDER_WIDTH = 1;
org.intermedia.view.Constants.CELL_BORDER_WIDTH_LARGE = 4;
org.intermedia.view.Constants.CELL_BORDER_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_HEIGHT = 90;
org.intermedia.view.Constants.CELL_MAX_HEIGHT = 160;
org.intermedia.view.Constants.CELL_MIN_WIDTH = 160;
org.intermedia.view.Constants.CELL_THUMB_APPARITION_DELAY = 1500;
org.intermedia.view.Constants.CELL_THUMB_TEXT_TITLE_LENGTH = 42;
org.intermedia.view.LoadingViewStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_VERTICAL_SPACE = 7;
org.intermedia.view.MenuCellTextStyle.CELL_HORIZONTAL_PADDING = 5;
org.intermedia.view.MenuListViewText.BOLD_FONT_OFFSET = 5;
org.intermedia.view.Scroll2D.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.Scroll2D.VERTICAL_TWEEN_DELTA = 50;
org.intermedia.view.Scroll2D.TIME_DELTA = 100;
org.intermedia.view.Scroll2D.VERTICAL_RELEASE_TIME = 100;
org.intermedia.view.SwippableListView.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEM_PER_LIST = 3;
org.intermedia.view.SwippableListView.LIST_QTY = 2;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEMS = 6;
org.intermedia.Application.main()