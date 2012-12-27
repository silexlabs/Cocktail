var $hxClasses = $hxClasses || {},$estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var Hash = $hxClasses["Hash"] = function() {
	this.h = { };
};
Hash.__name__ = true;
Hash.prototype = {
	keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,set: function(key,value) {
		this.h["$" + key] = value;
	}
	,__class__: Hash
}
var HxOverrides = $hxClasses["HxOverrides"] = function() { }
HxOverrides.__name__ = true;
HxOverrides.strDate = function(s) {
	switch(s.length) {
	case 8:
		var k = s.split(":");
		var d = new Date();
		d.setTime(0);
		d.setUTCHours(k[0]);
		d.setUTCMinutes(k[1]);
		d.setUTCSeconds(k[2]);
		return d;
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
}
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
}
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
}
HxOverrides.remove = function(a,obj) {
	var i = 0;
	var l = a.length;
	while(i < l) {
		if(a[i] == obj) {
			a.splice(i,1);
			return true;
		}
		i++;
	}
	return false;
}
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
}
var IntHash = $hxClasses["IntHash"] = function() {
	this.h = { };
};
IntHash.__name__ = true;
IntHash.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,__class__: IntHash
}
var List = $hxClasses["List"] = function() {
	this.length = 0;
};
List.__name__ = true;
List.prototype = {
	iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,__class__: List
}
var Reflect = $hxClasses["Reflect"] = function() { }
Reflect.__name__ = true;
Reflect.field = function(o,field) {
	var v = null;
	try {
		v = o[field];
	} catch( e ) {
	}
	return v;
}
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
}
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
}
var Std = $hxClasses["Std"] = function() { }
Std.__name__ = true;
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
}
Std.parseFloat = function(x) {
	return parseFloat(x);
}
Std.random = function(x) {
	return Math.floor(Math.random() * x);
}
var StringTools = $hxClasses["StringTools"] = function() { }
StringTools.__name__ = true;
StringTools.urlEncode = function(s) {
	return encodeURIComponent(s);
}
StringTools.urlDecode = function(s) {
	return decodeURIComponent(s.split("+").join(" "));
}
StringTools.htmlUnescape = function(s) {
	return s.split("&gt;").join(">").split("&lt;").join("<").split("&quot;").join("\"").split("&#039;").join("'").split("&amp;").join("&");
}
StringTools.isSpace = function(s,pos) {
	var c = HxOverrides.cca(s,pos);
	return c >= 9 && c <= 13 || c == 32;
}
StringTools.rtrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) r++;
	if(r > 0) return HxOverrides.substr(s,0,l - r); else return s;
}
var Type = $hxClasses["Type"] = function() { }
Type.__name__ = true;
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !cl.__name__) return null;
	return cl;
}
Type.resolveEnum = function(name) {
	var e = $hxClasses[name];
	if(e == null || !e.__ename__) return null;
	return e;
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
Type.getEnumConstructs = function(e) {
	var a = e.__constructs__;
	return a.slice();
}
var Xml = $hxClasses["Xml"] = function() {
};
Xml.__name__ = true;
Xml.parse = function(str) {
	return haxe.xml.Parser.parse(str);
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
	addChild: function(x) {
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) HxOverrides.remove(x._parent._children,x);
		x._parent = this;
		this._children.push(x);
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
	,firstChild: function() {
		if(this._children == null) throw "bad nodetype";
		return this._children[0];
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
	,exists: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.exists(att);
	}
	,set: function(att,value) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.set(att,value);
	}
	,getParent: function() {
		return this._parent;
	}
	,setNodeValue: function(v) {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue = v;
	}
	,getNodeValue: function() {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue;
	}
	,setNodeName: function(n) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName = n;
	}
	,getNodeName: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName;
	}
	,__class__: Xml
}
var feffects = feffects || {}
feffects.TweenObject = $hxClasses["feffects.TweenObject"] = function() { }
feffects.TweenObject.__name__ = true;
feffects.TweenObject.prototype = {
	get_isPlaying: function() {
		var $it0 = this.tweens.iterator();
		while( $it0.hasNext() ) {
			var tween = $it0.next();
			if(tween.isPlaying) return true;
		}
		return false;
	}
	,__class__: feffects.TweenObject
}
var haxe = haxe || {}
haxe.FastList = $hxClasses["haxe.FastList"] = function() {
};
haxe.FastList.__name__ = true;
haxe.FastList.prototype = {
	iterator: function() {
		var l = this.head;
		return { hasNext : function() {
			return l != null;
		}, next : function() {
			var k = l;
			l = k.next;
			return k.elt;
		}};
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
	,add: function(item) {
		this.head = new haxe.FastCell(item,this.head);
	}
	,__class__: haxe.FastList
}
feffects.Tween = $hxClasses["feffects.Tween"] = function(init,end,dur,easing,autoStart,onUpdate,onUpdateParams,onFinish,onFinishParams) {
	if(autoStart == null) autoStart = false;
	this._initVal = init;
	this._endVal = end;
	this.duration = dur;
	this.onUpdate(onUpdate,onUpdateParams);
	this.onFinish(onFinish,onFinishParams);
	this._offsetTime = 0;
	this.position = 0;
	this.isPlaying = false;
	this.isPaused = false;
	this.isReversed = false;
	if(easing != null) this._easingF = easing; else this._easingF = feffects.Tween.easingEquation;
	if(autoStart) this.start();
};
feffects.Tween.__name__ = true;
feffects.Tween.AddTween = function(tween) {
	if(!feffects.Tween._isTweening) {
		feffects.Tween._timer = new haxe.Timer(feffects.Tween.INTERVAL);
		feffects.Tween._timer.run = feffects.Tween.cb_tick;
		feffects.Tween._isTweening = true;
		feffects.Tween.cb_tick();
	}
	feffects.Tween._aTweens.add(tween);
}
feffects.Tween.RemoveActiveTween = function(tween) {
	feffects.Tween._aTweens.remove(tween);
	feffects.Tween.checkActiveTweens();
}
feffects.Tween.RemovePausedTween = function(tween) {
	feffects.Tween._aPaused.remove(tween);
	feffects.Tween.checkActiveTweens();
}
feffects.Tween.checkActiveTweens = function() {
	if(feffects.Tween._aTweens.head == null) {
		if(feffects.Tween._timer != null) {
			feffects.Tween._timer.stop();
			feffects.Tween._timer = null;
		}
		feffects.Tween._isTweening = false;
	}
}
feffects.Tween.setTweenPaused = function(tween) {
	if(!tween.isPlaying) return;
	feffects.Tween._aPaused.add(tween);
	feffects.Tween._aTweens.remove(tween);
	feffects.Tween.checkActiveTweens();
}
feffects.Tween.cb_tick = function() {
	var $it0 = feffects.Tween._aTweens.iterator();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		i.doInterval();
	}
}
feffects.Tween.easingEquation = function(t,b,c,d) {
	return c / 2 * (Math.sin(Math.PI * (t / d - 0.5)) + 1) + b;
}
feffects.Tween.prototype = {
	doInterval: function() {
		var stamp = new Date().getTime();
		var curTime = 0;
		if(this.isReversed) curTime = this._reverseTime * 2 - stamp - this._startTime + this._offsetTime; else curTime = stamp - this._startTime + this._offsetTime;
		var curVal = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
		if(curTime >= this.duration || curTime < 0) this.finish(); else if(this._onUpdate != null) {
			this._onUpdateParams[0] = curVal;
			this._onUpdate.apply(null,this._onUpdateParams);
		}
		this.position = curTime;
	}
	,onFinish: function(f,params) {
		this._onFinish = f;
		this._onFinishParams = params == null?[]:params;
		return this;
	}
	,onUpdate: function(f,params) {
		this._onUpdate = f;
		this._onUpdateParams = [0];
		if(params != null) this._onUpdateParams = this._onUpdateParams.concat(params);
		return this;
	}
	,finish: function() {
		feffects.Tween.RemoveActiveTween(this);
		this.isPlaying = false;
		this._onUpdateParams[0] = this.isReversed?this._initVal:this._endVal;
		if(this._onUpdate != null) this._onUpdate.apply(null,this._onUpdateParams);
		if(this._onFinish != null) this._onFinish.apply(null,this._onFinishParams);
	}
	,stop: function(doFinish) {
		if(this.isPaused) feffects.Tween.RemovePausedTween(this); else if(this.isPlaying) feffects.Tween.RemoveActiveTween(this);
		if(doFinish) this.finish();
		this.isPaused = false;
		this.isPlaying = false;
	}
	,seek: function(ms) {
		this._offsetTime = ms < this.duration?ms:this.duration;
		return this;
	}
	,pause: function() {
		if(!this.isPlaying) return;
		this._pauseTime = new Date().getTime();
		feffects.Tween.setTweenPaused(this);
		this.isPlaying = false;
		this.isPaused = true;
	}
	,start: function(position) {
		if(position == null) position = 0;
		this._startTime = new Date().getTime();
		this._reverseTime = new Date().getTime();
		this.seek(position);
		if(this.isPaused) feffects.Tween.RemovePausedTween(this);
		feffects.Tween.AddTween(this);
		this.isPlaying = true;
		if(this.duration == 0 || position >= this.duration) this.finish();
	}
	,__class__: feffects.Tween
}
haxe.Public = $hxClasses["haxe.Public"] = function() { }
haxe.Public.__name__ = true;
if(!feffects.easing) feffects.easing = {}
feffects.easing.Quad = $hxClasses["feffects.easing.Quad"] = function() { }
feffects.easing.Quad.__name__ = true;
feffects.easing.Quad.__interfaces__ = [haxe.Public];
feffects.easing.Quad.easeOut = function(t,b,c,d) {
	return -c * (t /= d) * (t - 2) + b;
}
haxe.FastCell = $hxClasses["haxe.FastCell"] = function(elt,next) {
	this.elt = elt;
	this.next = next;
};
haxe.FastCell.__name__ = true;
haxe.FastCell.prototype = {
	__class__: haxe.FastCell
}
haxe.Firebug = $hxClasses["haxe.Firebug"] = function() { }
haxe.Firebug.__name__ = true;
haxe.Firebug.trace = function(v,inf) {
	var type = inf != null && inf.customParams != null?inf.customParams[0]:null;
	if(type != "warn" && type != "info" && type != "debug" && type != "error") type = inf == null?"error":"log";
	console[type]((inf == null?"":inf.fileName + ":" + inf.lineNumber + " : ") + Std.string(v));
}
haxe.Http = $hxClasses["haxe.Http"] = function(url) {
	this.url = url;
	this.headers = new Hash();
	this.params = new Hash();
	this.async = true;
};
haxe.Http.__name__ = true;
haxe.Http.prototype = {
	onStatus: function(status) {
	}
	,onError: function(msg) {
	}
	,onData: function(data) {
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
	,__class__: haxe.Http
}
haxe.Resource = $hxClasses["haxe.Resource"] = function() { }
haxe.Resource.__name__ = true;
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
haxe.Timer = $hxClasses["haxe.Timer"] = function(time_ms) {
	var me = this;
	this.id = window.setInterval(function() {
		me.run();
	},time_ms);
};
haxe.Timer.__name__ = true;
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
}
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
}
haxe.Timer.prototype = {
	run: function() {
	}
	,stop: function() {
		if(this.id == null) return;
		window.clearInterval(this.id);
		this.id = null;
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
haxe.Unserializer.__name__ = true;
haxe.Unserializer.initCodes = function() {
	var codes = new Array();
	var _g1 = 0, _g = haxe.Unserializer.BASE64.length;
	while(_g1 < _g) {
		var i = _g1++;
		codes[haxe.Unserializer.BASE64.charCodeAt(i)] = i;
	}
	return codes;
}
haxe.Unserializer.run = function(v) {
	return new haxe.Unserializer(v).unserialize();
}
haxe.Unserializer.prototype = {
	unserialize: function() {
		switch(this.buf.charCodeAt(this.pos++)) {
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
				var c = this.buf.charCodeAt(this.pos);
				if(c >= 43 && c < 58 || c == 101 || c == 69) this.pos++; else break;
			}
			return Std.parseFloat(HxOverrides.substr(this.buf,p1,this.pos - p1));
		case 121:
			var len = this.readDigits();
			if(this.buf.charCodeAt(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid string length";
			var s = HxOverrides.substr(this.buf,this.pos,len);
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
				var c = this.buf.charCodeAt(this.pos);
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
			while(this.buf.charCodeAt(this.pos) != 104) l.add(this.unserialize());
			this.pos++;
			return l;
		case 98:
			var h = new Hash();
			this.cache.push(h);
			var buf = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) {
				var s = this.unserialize();
				h.set(s,this.unserialize());
			}
			this.pos++;
			return h;
		case 113:
			var h = new IntHash();
			this.cache.push(h);
			var buf = this.buf;
			var c = this.buf.charCodeAt(this.pos++);
			while(c == 58) {
				var i = this.readDigits();
				h.set(i,this.unserialize());
				c = this.buf.charCodeAt(this.pos++);
			}
			if(c != 104) throw "Invalid IntHash format";
			return h;
		case 118:
			var d = HxOverrides.strDate(HxOverrides.substr(this.buf,this.pos,19));
			this.cache.push(d);
			this.pos += 19;
			return d;
		case 115:
			var len = this.readDigits();
			var buf = this.buf;
			if(this.buf.charCodeAt(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid bytes length";
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
				var c1 = codes[buf.charCodeAt(i++)];
				var c2 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				var c3 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c2 << 4 | c3 >> 2) & 255;
				var c4 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c3 << 6 | c4) & 255;
			}
			if(rest >= 2) {
				var c1 = codes[buf.charCodeAt(i++)];
				var c2 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				if(rest == 3) {
					var c3 = codes[buf.charCodeAt(i++)];
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
			if(this.buf.charCodeAt(this.pos++) != 103) throw "Invalid custom data";
			return o;
		default:
		}
		this.pos--;
		throw "Invalid char " + this.buf.charAt(this.pos) + " at position " + this.pos;
	}
	,unserializeEnum: function(edecl,tag) {
		if(this.buf.charCodeAt(this.pos++) != 58) throw "Invalid enum format";
		var nargs = this.readDigits();
		if(nargs == 0) return Type.createEnum(edecl,tag);
		var args = new Array();
		while(nargs-- > 0) args.push(this.unserialize());
		return Type.createEnum(edecl,tag,args);
	}
	,unserializeObject: function(o) {
		while(true) {
			if(this.pos >= this.length) throw "Invalid object";
			if(this.buf.charCodeAt(this.pos) == 103) break;
			var k = this.unserialize();
			if(!js.Boot.__instanceof(k,String)) throw "Invalid object key";
			var v = this.unserialize();
			o[k] = v;
		}
		this.pos++;
	}
	,readDigits: function() {
		var k = 0;
		var s = false;
		var fpos = this.pos;
		while(true) {
			var c = this.buf.charCodeAt(this.pos);
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
	,setResolver: function(r) {
		if(r == null) this.resolver = { resolveClass : function(_) {
			return null;
		}, resolveEnum : function(_) {
			return null;
		}}; else this.resolver = r;
	}
	,__class__: haxe.Unserializer
}
if(!haxe.io) haxe.io = {}
haxe.io.Bytes = $hxClasses["haxe.io.Bytes"] = function(length,b) {
	this.length = length;
	this.b = b;
};
haxe.io.Bytes.__name__ = true;
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
}
haxe.io.Bytes.prototype = {
	toString: function() {
		return this.readString(0,this.length);
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
	,__class__: haxe.io.Bytes
}
haxe.io.Error = $hxClasses["haxe.io.Error"] = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] }
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
if(!haxe.xml) haxe.xml = {}
haxe.xml.Parser = $hxClasses["haxe.xml.Parser"] = function() { }
haxe.xml.Parser.__name__ = true;
haxe.xml.Parser.parse = function(str) {
	var doc = Xml.createDocument();
	haxe.xml.Parser.doParse(str,0,doc);
	return doc;
}
haxe.xml.Parser.doParse = function(str,p,parent) {
	if(p == null) p = 0;
	var xml = null;
	var state = 1;
	var next = 1;
	var aname = null;
	var start = 0;
	var nsubs = 0;
	var nbrackets = 0;
	var c = str.charCodeAt(p);
	while(!(c != c)) {
		switch(state) {
		case 0:
			switch(c) {
			case 10:case 13:case 9:case 32:
				break;
			default:
				state = next;
				continue;
			}
			break;
		case 1:
			switch(c) {
			case 60:
				state = 0;
				next = 2;
				break;
			default:
				start = p;
				state = 13;
				continue;
			}
			break;
		case 13:
			if(c == 60) {
				var child = Xml.createPCData(HxOverrides.substr(str,start,p - start));
				parent.addChild(child);
				nsubs++;
				state = 0;
				next = 2;
			}
			break;
		case 17:
			if(c == 93 && str.charCodeAt(p + 1) == 93 && str.charCodeAt(p + 2) == 62) {
				var child = Xml.createCData(HxOverrides.substr(str,start,p - start));
				parent.addChild(child);
				nsubs++;
				p += 2;
				state = 1;
			}
			break;
		case 2:
			switch(c) {
			case 33:
				if(str.charCodeAt(p + 1) == 91) {
					p += 2;
					if(HxOverrides.substr(str,p,6).toUpperCase() != "CDATA[") throw "Expected <![CDATA[";
					p += 5;
					state = 17;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) == 68 || str.charCodeAt(p + 1) == 100) {
					if(HxOverrides.substr(str,p + 2,6).toUpperCase() != "OCTYPE") throw "Expected <!DOCTYPE";
					p += 8;
					state = 16;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) != 45 || str.charCodeAt(p + 2) != 45) throw "Expected <!--"; else {
					p += 2;
					state = 15;
					start = p + 1;
				}
				break;
			case 63:
				state = 14;
				start = p;
				break;
			case 47:
				if(parent == null) throw "Expected node name";
				start = p + 1;
				state = 0;
				next = 10;
				break;
			default:
				state = 3;
				start = p;
				continue;
			}
			break;
		case 3:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(p == start) throw "Expected node name";
				xml = Xml.createElement(HxOverrides.substr(str,start,p - start));
				parent.addChild(xml);
				state = 0;
				next = 4;
				continue;
			}
			break;
		case 4:
			switch(c) {
			case 47:
				state = 11;
				nsubs++;
				break;
			case 62:
				state = 9;
				nsubs++;
				break;
			default:
				state = 5;
				start = p;
				continue;
			}
			break;
		case 5:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				var tmp;
				if(start == p) throw "Expected attribute name";
				tmp = HxOverrides.substr(str,start,p - start);
				aname = tmp;
				if(xml.exists(aname)) throw "Duplicate attribute";
				state = 0;
				next = 6;
				continue;
			}
			break;
		case 6:
			switch(c) {
			case 61:
				state = 0;
				next = 7;
				break;
			default:
				throw "Expected =";
			}
			break;
		case 7:
			switch(c) {
			case 34:case 39:
				state = 8;
				start = p;
				break;
			default:
				throw "Expected \"";
			}
			break;
		case 8:
			if(c == str.charCodeAt(start)) {
				var val = HxOverrides.substr(str,start + 1,p - start - 1);
				xml.set(aname,val);
				state = 0;
				next = 4;
			}
			break;
		case 9:
			p = haxe.xml.Parser.doParse(str,p,xml);
			start = p;
			state = 1;
			break;
		case 11:
			switch(c) {
			case 62:
				state = 1;
				break;
			default:
				throw "Expected >";
			}
			break;
		case 12:
			switch(c) {
			case 62:
				if(nsubs == 0) parent.addChild(Xml.createPCData(""));
				return p;
			default:
				throw "Expected >";
			}
			break;
		case 10:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(start == p) throw "Expected node name";
				var v = HxOverrides.substr(str,start,p - start);
				if(v != parent.getNodeName()) throw "Expected </" + parent.getNodeName() + ">";
				state = 0;
				next = 12;
				continue;
			}
			break;
		case 15:
			if(c == 45 && str.charCodeAt(p + 1) == 45 && str.charCodeAt(p + 2) == 62) {
				parent.addChild(Xml.createComment(HxOverrides.substr(str,start,p - start)));
				p += 2;
				state = 1;
			}
			break;
		case 16:
			if(c == 91) nbrackets++; else if(c == 93) nbrackets--; else if(c == 62 && nbrackets == 0) {
				parent.addChild(Xml.createDocType(HxOverrides.substr(str,start,p - start)));
				state = 1;
			}
			break;
		case 14:
			if(c == 63 && str.charCodeAt(p + 1) == 62) {
				p++;
				var str1 = HxOverrides.substr(str,start + 1,p - start - 2);
				parent.addChild(Xml.createProlog(str1));
				state = 1;
			}
			break;
		}
		c = str.charCodeAt(++p);
	}
	if(state == 1) {
		start = p;
		state = 13;
	}
	if(state == 13) {
		if(p != start || nsubs == 0) parent.addChild(Xml.createPCData(HxOverrides.substr(str,start,p - start)));
		return p;
	}
	throw "Unexpected end";
}
var js = js || {}
js.Boot = $hxClasses["js.Boot"] = function() { }
js.Boot.__name__ = true;
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
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
		if(cl == Class && o.__name__ != null) return true; else null;
		if(cl == Enum && o.__ename__ != null) return true; else null;
		return o.__enum__ == cl;
	}
}
js.Lib = $hxClasses["js.Lib"] = function() { }
js.Lib.__name__ = true;
var org = org || {}
if(!org.intermedia) org.intermedia = {}
org.intermedia.Application = $hxClasses["org.intermedia.Application"] = function() {
	var applicationModel = new org.intermedia.model.ApplicationModel();
	var applicationController = new org.intermedia.controller.ApplicationController(applicationModel);
	var view = new org.intermedia.view.ViewManager(applicationModel,applicationController);
};
org.intermedia.Application.__name__ = true;
org.intermedia.Application.main = function() {
	new org.intermedia.Application();
}
org.intermedia.Application.prototype = {
	__class__: org.intermedia.Application
}
org.intermedia.Debug = $hxClasses["org.intermedia.Debug"] = function() {
	this._timer = haxe.Timer.stamp();
};
org.intermedia.Debug.__name__ = true;
org.intermedia.Debug.prototype = {
	traceDuration: function(msg) {
		console.log(msg + ": " + (haxe.Timer.stamp() - this._timer));
		this._timer = haxe.Timer.stamp();
	}
	,__class__: org.intermedia.Debug
}
org.intermedia.Settings = $hxClasses["org.intermedia.Settings"] = function() { }
org.intermedia.Settings.__name__ = true;
if(!org.intermedia.controller) org.intermedia.controller = {}
org.intermedia.controller.ApplicationController = $hxClasses["org.intermedia.controller.ApplicationController"] = function(applicationModel) {
	this._applicationModel = applicationModel;
};
org.intermedia.controller.ApplicationController.__name__ = true;
org.intermedia.controller.ApplicationController.prototype = {
	loadCellData: function(feed) {
		this._applicationModel.loadCellData(feed);
	}
	,__class__: org.intermedia.controller.ApplicationController
}
if(!org.intermedia.model) org.intermedia.model = {}
org.intermedia.model.ApplicationModel = $hxClasses["org.intermedia.model.ApplicationModel"] = function() {
	this._loadedCellsData = new Array();
	this._loadedDetailData = new Array();
	this._dataLoader = new org.intermedia.model.DataLoader(true);
};
org.intermedia.model.ApplicationModel.__name__ = true;
org.intermedia.model.ApplicationModel.prototype = {
	onCellsDataLoadComplete: function(listData) {
		this._loadedCellsData = new Array();
		var _g = 0, _g1 = listData.cells;
		while(_g < _g1.length) {
			var cellData = _g1[_g];
			++_g;
			this._loadedCellsData.push(cellData);
		}
		if(this.onModelCellDataLoaded != null) this.onModelCellDataLoaded(listData);
	}
	,loadCellData: function(id) {
		var feed = { id : 0, thumb : "", title : "", url : "", generatedBy : ""};
		if(id == { id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"}.url) feed = { id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"}; else if(id == { id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"}.url) feed = { id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"}; else if(id == { id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"}.url) feed = { id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"};
		if(this._loadedCellsData.length == 0) {
			if(this.onModelStartsLoading != null) this.onModelStartsLoading();
		}
		this._dataLoader.loadCellData(feed,15,$bind(this,this.onCellsDataLoadComplete),this.onModelDataLoadError);
	}
	,__class__: org.intermedia.model.ApplicationModel
}
org.intermedia.model.DataLoader = $hxClasses["org.intermedia.model.DataLoader"] = function(online) {
	if(online == null) online = true;
	this._pageIndex = 1;
	this._pageIndexHash = new Hash();
	this._online = online;
};
org.intermedia.model.DataLoader.__name__ = true;
org.intermedia.model.DataLoader.prototype = {
	onCellsXmlLoaded: function(feed,xml) {
		this.onCellDataLoaded({ id : feed.url, cells : org.intermedia.model.ThumbTextListRssStandard.rss2Cells(xml,feed)});
	}
	,loadCellData: function(feed,itemsPerPage,successCallback,errorCallback) {
		this.onCellDataLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var fullUrl = "";
		if(this._online) {
			var debug = new org.intermedia.Debug();
			debug.traceDuration("DataLoader step0");
			var pageIndex = 1;
			if(this._pageIndexHash.exists(feed.url)) pageIndex = this._pageIndexHash.get(feed.url) + 1;
			this._pageIndexHash.set(feed.url,pageIndex);
			if(feed.generatedBy == "wordpress") fullUrl = feed.url + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex; else fullUrl = feed.url;
			var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,$bind(this,this.onCellsXmlLoaded),this.onLoadingError,feed);
			debug.traceDuration("DataLoader feed " + feed.url);
		} else {
			var debug = new org.intermedia.Debug();
			debug.traceDuration("DataLoader step0");
			if(feed.url == { id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed1"))); else if(feed.url == { id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed2"))); else if(feed.url == { id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"}.url) this.onCellsXmlLoaded(feed,Xml.parse(haxe.Resource.getString("feed3")));
			debug.traceDuration("DataLoader feed " + Std.string(feed));
		}
	}
	,__class__: org.intermedia.model.DataLoader
}
org.intermedia.model.Feeds = $hxClasses["org.intermedia.model.Feeds"] = function() { }
org.intermedia.model.Feeds.__name__ = true;
org.intermedia.model.ThumbTextListRssStandard = $hxClasses["org.intermedia.model.ThumbTextListRssStandard"] = function() { }
org.intermedia.model.ThumbTextListRssStandard.__name__ = true;
org.intermedia.model.ThumbTextListRssStandard.rss2Cells = function(rss,feed) {
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
					if(index != -1) title = HxOverrides.substr(title,0,index);
					title = StringTools.rtrim(title);
					cell.title = title;
				}
				if(itemParam.getNodeName() == "dc:creator") cell.author = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "description") {
					cell.description = org.intermedia.model.ThumbTextListRssStandard.cleanText(itemParam.firstChild().getNodeValue());
					console.log(cell.description);
					if(cell.thumbUrl == "") cell.thumbUrl = org.intermedia.model.ThumbTextListRssStandard.getThumb(cell.description);
				}
				if(itemParam.getNodeName() == "content:encoded") {
					cell.content = org.intermedia.model.ThumbTextListRssStandard.cleanText(itemParam.firstChild().getNodeValue());
					if(cell.thumbUrl == "") cell.thumbUrl = org.intermedia.model.ThumbTextListRssStandard.getThumb(cell.content);
				}
			}
			if(cell.thumbUrl == "") cell.thumbUrl = feed.thumb;
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
		charCodeString = HxOverrides.substr(text,charCodeStartPosition + charCodeStart.length,null);
		charCodeEndPosition = charCodeString.indexOf(charCodeEnd);
		textEnd = HxOverrides.substr(charCodeString,charCodeEndPosition + 1,null);
		charCodeString = HxOverrides.substr(charCodeString,0,charCodeEndPosition);
		charCode = Std.parseInt(charCodeString);
		$char = String.fromCharCode(charCode);
		text = HxOverrides.substr(text,0,charCodeStartPosition) + $char + textEnd;
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
		htmlString = HxOverrides.substr(htmlString,imgNodeStartIndex,null);
		var imgNodeEndIndex = htmlString.indexOf(">") + 1;
		imgNode = HxOverrides.substr(htmlString,0,imgNodeEndIndex);
		var srcKeyWord = "src=";
		imgUrlStartIndex = imgNode.indexOf(srcKeyWord);
		if(imgUrlStartIndex != -1) {
			var imgUrlDelimitor = HxOverrides.substr(imgNode,imgUrlStartIndex + srcKeyWord.length,1);
			imgUrl = HxOverrides.substr(imgNode,imgUrlStartIndex + srcKeyWord.length + 1,null);
			var imgUrlEndIndex = imgUrl.indexOf(imgUrlDelimitor);
			imgUrl = HxOverrides.substr(imgUrl,0,imgUrlEndIndex);
			return imgUrl;
		}
	} else {
		imgUrlStartIndex = htmlString.indexOf("<p>http://");
		if(imgUrlStartIndex != -1) {
			var srcKeyWord = "<p>";
			imgUrl = HxOverrides.substr(htmlString,imgUrlStartIndex + srcKeyWord.length,null);
			var imgUrlEndIndex = imgUrl.indexOf("</p>");
			imgUrl = HxOverrides.substr(imgUrl,0,imgUrlEndIndex);
			return imgUrl;
		}
	}
	return "";
}
org.intermedia.model.XmlLoader = $hxClasses["org.intermedia.model.XmlLoader"] = function(xmlUrl,online,successCallback,errorCallback,feed) {
	this._online = online;
	this.onLoadSuccess = successCallback;
	this.onLoadError = errorCallback;
	this.loadXmlFeed(feed,xmlUrl);
};
org.intermedia.model.XmlLoader.__name__ = true;
org.intermedia.model.XmlLoader.prototype = {
	onXmlLoaded: function(feed,xmlString) {
		var xml = Xml.parse(xmlString);
		if(this.onLoadSuccess != null) this.onLoadSuccess(feed,xml);
	}
	,onXmlError: function(error) {
		if(this.onLoadError != null) this.onLoadError(error);
	}
	,loadXmlFeed: function(feed,xmlUrl) {
		var _g = this;
		var fullUrl = "";
		fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);
		try {
			var httpRequest = new haxe.Http(fullUrl);
			httpRequest.onData = function(xml) {
				_g.onXmlLoaded(feed,xml);
			};
			httpRequest.onError = $bind(this,this.onXmlError);
			httpRequest.request(false);
		} catch( error ) {
			this.onXmlError(error);
		}
	}
	,__class__: org.intermedia.model.XmlLoader
}
if(!org.intermedia.view) org.intermedia.view = {}
org.intermedia.view.ViewBase = $hxClasses["org.intermedia.view.ViewBase"] = function() {
	this.node = js.Lib.document.createElement("div");
	this.setDisplayLoading(false);
	this.buildView();
};
org.intermedia.view.ViewBase.__name__ = true;
org.intermedia.view.ViewBase.prototype = {
	updateView: function() {
	}
	,buildView: function() {
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
	,setData: function(v) {
		this._data = v;
		this.updateView();
		return this._data;
	}
	,getData: function() {
		return this._data;
	}
	,__class__: org.intermedia.view.ViewBase
}
org.intermedia.view.CellBase = $hxClasses["org.intermedia.view.CellBase"] = function(cellPerLine,style) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ViewBase.call(this);
	this._style = this._style;
	this._cellPerLine = cellPerLine;
	if(style != null) this._style = style; else this.initStyle();
	this._style.cell(this.node,cellPerLine);
};
org.intermedia.view.CellBase.__name__ = true;
org.intermedia.view.CellBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CellBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	refreshStyles: function() {
		this._style.cell(this.node,this._cellPerLine);
	}
	,initStyle: function() {
		this._style = { cell : org.intermedia.view.CellStyle.setCellStyle, thumbnailMask : null, thumbnail : null, textBlock : null, title : null, author : null};
	}
	,__class__: org.intermedia.view.CellBase
});
org.intermedia.view.CellStyle = $hxClasses["org.intermedia.view.CellStyle"] = function() { }
org.intermedia.view.CellStyle.__name__ = true;
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
	node.style.backgroundColor = "#FEFEFE";
}
org.intermedia.view.CellStyle.computeWidthPercentage = function(cellPerLine,borderWidth) {
	if(borderWidth == null) borderWidth = 0;
	var cellWidthPercent = 100;
	if(cellPerLine != 0) cellWidthPercent = 100 / cellPerLine - borderWidth * 100 / js.Lib.window.innerWidth - borderWidth * 100 / (js.Lib.window.innerWidth * cellPerLine);
	return cellWidthPercent;
}
org.intermedia.view.CellStyle.addBorder = function(node,borderWidth) {
	node.style.marginBottom = Std.string(borderWidth) + "px";
	node.style.marginLeft = Std.string(borderWidth) + "px";
}
org.intermedia.view.CellStyle.removeBorder = function(node) {
	node.style.marginBottom = "0px";
	node.style.marginTop = "0px";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
}
org.intermedia.view.CellText = $hxClasses["org.intermedia.view.CellText"] = function() {
	org.intermedia.view.CellBase.call(this);
};
org.intermedia.view.CellText.__name__ = true;
org.intermedia.view.CellText.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellText.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	updateView: function() {
		var cellData = this._data;
		var cellTextContainer = js.Lib.document.createElement("div");
		if(cellData.title != "" && cellData.title != null) {
			var textElement = js.Lib.document.createTextNode(cellData.title);
			cellTextContainer.appendChild(textElement);
			this._style.title(cellTextContainer);
			this.node.appendChild(cellTextContainer);
		}
	}
	,initStyle: function() {
		this._style = { cell : org.intermedia.view.CellTextStyle.setCellStyle, thumbnailMask : null, thumbnail : null, textBlock : null, title : org.intermedia.view.CellTextStyle.setCellTextStyle, author : null};
	}
	,__class__: org.intermedia.view.CellText
});
org.intermedia.view.CellTextStyle = $hxClasses["org.intermedia.view.CellTextStyle"] = function() { }
org.intermedia.view.CellTextStyle.__name__ = true;
org.intermedia.view.CellTextStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
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
	node.style.backgroundColor = "#FEFEFE";
}
org.intermedia.view.CellTextStyle.setCellTextStyle = function(node) {
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.fontSize = "16px";
	node.style.lineHeight = "normal";
	node.style.fontWeight = "normal";
	node.style.fontStyle = "normal";
	node.style.fontFamily = "Arial, sans-serif";
	node.style.fontVariant = "normal";
	node.style.textTransform = "none";
	node.style.letterSpacing = "normal";
	node.style.wordSpacing = "normal";
	node.style.textIndent = "0px";
	node.style.whiteSpace = "normal";
	node.style.textAlign = "justify";
	node.style.verticalAlign = "middle";
	node.style.color = "#444444";
}
org.intermedia.view.CellThumb = $hxClasses["org.intermedia.view.CellThumb"] = function(cellPerLine,style) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine,style);
};
org.intermedia.view.CellThumb.__name__ = true;
org.intermedia.view.CellThumb.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumb.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	refreshStyles: function() {
		org.intermedia.view.CellBase.prototype.refreshStyles.call(this);
		this._croppedImage.refreshStyles();
	}
	,updateView: function() {
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._style);
			this._croppedImage.setData(this._data);
			this.node.appendChild(this._croppedImage.node);
		}
	}
	,initStyle: function() {
		this._style = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbStyle.setThumbnailMaskStyle, thumbnail : null, textBlock : null, title : null, author : null};
	}
	,__class__: org.intermedia.view.CellThumb
});
org.intermedia.view.CellThumbStyle = $hxClasses["org.intermedia.view.CellThumbStyle"] = function() { }
org.intermedia.view.CellThumbStyle.__name__ = true;
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
org.intermedia.view.CellThumbText1 = $hxClasses["org.intermedia.view.CellThumbText1"] = function(cellPerLine,style) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine,style);
};
org.intermedia.view.CellThumbText1.__name__ = true;
org.intermedia.view.CellThumbText1.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumbText1.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	refreshStyles: function() {
		org.intermedia.view.CellBase.prototype.refreshStyles.call(this);
		this._croppedImage.refreshStyles();
	}
	,updateView: function() {
		org.intermedia.view.CellBase.prototype.updateView.call(this);
		if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
			this._croppedImage = new org.intermedia.view.CroppedImage(this._style);
			this._croppedImage.setData(this._data);
			this.node.appendChild(this._croppedImage.node);
		}
		var cellTextBlockContainer = js.Lib.document.createElement("div");
		this._style.textBlock(cellTextBlockContainer);
		this.node.appendChild(cellTextBlockContainer);
		if(this._data.title != "" && this._data.title != null) {
			var text = this._data.title;
			if(text.length > 42) {
				text = HxOverrides.substr(text,0,42);
				text = HxOverrides.substr(text,0,text.lastIndexOf(" ")) + "...";
			}
			var textElement = js.Lib.document.createTextNode(text);
			var cellTitleContainer = js.Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
			this._style.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
	}
	,initStyle: function() {
		this._style = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbText1Style.setThumbnailMaskStyle, thumbnail : null, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : null};
	}
	,__class__: org.intermedia.view.CellThumbText1
});
org.intermedia.view.CellThumbText1BisStyle = $hxClasses["org.intermedia.view.CellThumbText1BisStyle"] = function() { }
org.intermedia.view.CellThumbText1BisStyle.__name__ = true;
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
org.intermedia.view.CellThumbText1Style = $hxClasses["org.intermedia.view.CellThumbText1Style"] = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = true;
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
	node.style.marginLeft = "2%";
	node.style.width = Std.string(34) + "%";
	node.style.height = Std.string(70) + "%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	node.style.display = "inline-block";
}
org.intermedia.view.CellThumbText1Style.setTextBlockStyle = function(node) {
	node.style.display = "inline-block";
	node.style.marginTop = Std.string(4) + "%";
	node.style.marginLeft = "2%";
	node.style.verticalAlign = "top";
	node.style.width = Std.string(60) + "%";
}
org.intermedia.view.CellThumbText1Style.setTextStyle = function(node) {
	node.style.display = "block";
	node.style.color = "#444444";
	node.style.fontFamily = "Arial, sans-serif";
}
org.intermedia.view.CellThumbText1Style.setTitleStyle = function(node) {
	org.intermedia.view.CellThumbText1Style.setTextStyle(node);
	node.style.fontSize = "14px";
}
org.intermedia.view.Constants = $hxClasses["org.intermedia.view.Constants"] = function() { }
org.intermedia.view.Constants.__name__ = true;
org.intermedia.view.CroppedImage = $hxClasses["org.intermedia.view.CroppedImage"] = function(style) {
	org.intermedia.view.ViewBase.call(this);
	this._style = style;
	this.node = js.Lib.document.createElement("div");
};
org.intermedia.view.CroppedImage.__name__ = true;
org.intermedia.view.CroppedImage.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CroppedImage.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	refreshStyles: function() {
		var maskSize = { width : this.node.clientWidth, height : this.node.clientHeight};
		org.intermedia.view.ImageUtils.cropImage(this._image,maskSize);
	}
	,tweenEnd: function(e) {
	}
	,tweenOpacity: function(e) {
		this._image.style.opacity = e;
	}
	,fadeIn: function() {
		var tween = new feffects.Tween(0,1,400);
		tween.onUpdate($bind(this,this.tweenOpacity));
		tween.onFinish($bind(this,this.tweenEnd));
		tween.start();
	}
	,onImageLoadSuccessCallback: function(event) {
		this.refreshStyles();
		this._image.style.opacity = 0;
		this.node.appendChild(this._image);
		haxe.Timer.delay($bind(this,this.fadeIn),Std.random(1500));
		if(this.onImageLoadSuccess != null) this.onImageLoadSuccess();
	}
	,loadThumb: function(imageUrl) {
		this._image = js.Lib.document.createElement("img");
		this._image.onload = $bind(this,this.onImageLoadSuccessCallback);
		this._image.src = imageUrl;
	}
	,updateView: function() {
		this._style.thumbnailMask(this.node);
		this.loadThumb(this._data.thumbUrl);
	}
	,__class__: org.intermedia.view.CroppedImage
});
org.intermedia.view.DetailStyle = $hxClasses["org.intermedia.view.DetailStyle"] = function() { }
org.intermedia.view.DetailStyle.__name__ = true;
org.intermedia.view.DetailStyle.setDetailStyle = function(node) {
	node.style.display = "inline-block";
	node.style.position = "static";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.marginTop = Std.string(43) + "px";
	node.style.marginBottom = "0px";
	node.style.paddingLeft = Std.string(5) + "%";
	node.style.paddingRight = Std.string(5) + "%";
	node.style.paddingTop = Std.string(10) + "px";
	node.style.paddingBottom = Std.string(10) + "px";
	node.style.width = Std.string(90) + "%";
	node.style.height = "auto";
	node.style.top = Std.string(43) + "px";
	node.style.bottom = "0px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	node.style.backgroundColor = "#FEFEFE";
	node.style.textAlign = "justify";
}
org.intermedia.view.DetailStyle.setText = function(node) {
	node.style.display = "block";
	node.style.color = "#202020";
	node.style.fontFamily = "Arial, sans-serif";
}
org.intermedia.view.DetailStyle.setTitle = function(node) {
	org.intermedia.view.DetailStyle.setText(node);
	node.style.fontSize = "18px";
	node.style.fontWeight = "bold";
}
org.intermedia.view.DetailStyle.setAuthor = function(node) {
	org.intermedia.view.DetailStyle.setText(node);
	node.style.fontSize = "12px";
	node.style.fontWeight = "normal";
}
org.intermedia.view.DetailStyle.setDescription = function(node) {
	org.intermedia.view.DetailStyle.setText(node);
	node.style.marginTop = Std.string(10) + "px";
	node.style.marginBottom = Std.string(10) + "px";
	node.style.fontSize = "14px";
}
org.intermedia.view.DetailView = $hxClasses["org.intermedia.view.DetailView"] = function() {
	this._titleElement = js.Lib.document.createTextNode("");
	this._authorElement = js.Lib.document.createTextNode("");
	this._descriptionElement = js.Lib.document.createTextNode("");
	this._contentElement = js.Lib.document.createTextNode("");
	org.intermedia.view.ViewBase.call(this);
};
org.intermedia.view.DetailView.__name__ = true;
org.intermedia.view.DetailView.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.DetailView.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	resizeNode: function(nodeToResize) {
		var originalWidth = Std.parseInt(nodeToResize.getAttribute("width"));
		var originalHeight = Std.parseInt(nodeToResize.getAttribute("height"));
		if(Std.parseInt(nodeToResize.getAttribute("width")) > js.Lib.window.innerWidth) {
			var newWidth = 90 * js.Lib.window.innerWidth / 100 | 0;
			nodeToResize.style.width = Std.string(90) + "%";
			var newHeight = originalHeight * newWidth / originalWidth | 0;
			nodeToResize.style.height = Std.string(newHeight) + "px";
		} else {
			nodeToResize.style.width = Std.parseInt(nodeToResize.getAttribute("width")) + "px";
			nodeToResize.style.height = Std.parseInt(nodeToResize.getAttribute("height")) + "px";
		}
	}
	,resizeNodeChildrenTag: function(nodeToResize,tagName) {
		var tagNodes = nodeToResize.getElementsByTagName(tagName);
		var _g1 = 0, _g = tagNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.resizeNode(tagNodes[i]);
		}
	}
	,refreshStyles: function() {
		org.intermedia.view.DetailStyle.setDetailStyle(this.node);
		this.resizeNodeChildrenTag(this._contentContainer,"iframe");
		this.resizeNodeChildrenTag(this._contentContainer,"img");
	}
	,updateView: function() {
		this._titleContainer.removeChild(this._titleElement);
		this._titleElement = js.Lib.document.createTextNode(this._data.title);
		this._titleContainer.appendChild(this._titleElement);
		this._authorContainer.removeChild(this._authorElement);
		this._authorElement = js.Lib.document.createTextNode(this._data.author);
		this._authorContainer.appendChild(this._authorElement);
		if(this._data.content == "") this._data.content = this._data.description;
		this.node.removeChild(this._contentContainer);
		this._contentContainer.innerHTML = this._data.content;
		this.resizeNodeChildrenTag(this._contentContainer,"iframe");
		this.resizeNodeChildrenTag(this._contentContainer,"img");
		this.node.appendChild(this._contentContainer);
	}
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
		this._contentContainer = js.Lib.document.createElement("div");
		org.intermedia.view.DetailStyle.setDescription(this._contentContainer);
		this.node.appendChild(this._contentContainer);
	}
	,__class__: org.intermedia.view.DetailView
});
org.intermedia.view.HeaderStyle = $hxClasses["org.intermedia.view.HeaderStyle"] = function() { }
org.intermedia.view.HeaderStyle.__name__ = true;
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
	node.style.backgroundImage = "url(" + "assets/tile_french-tech.png" + ")";
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
org.intermedia.view.HeaderView = $hxClasses["org.intermedia.view.HeaderView"] = function() {
	org.intermedia.view.ViewBase.call(this);
	this._data = "";
	this._backButtonContainer = this.buildBackButtonView();
};
org.intermedia.view.HeaderView.__name__ = true;
org.intermedia.view.HeaderView.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.HeaderView.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onBackButtonClickCallback: function() {
		if(this.onBackButtonClick != null) this.onBackButtonClick();
	}
	,buildBackButtonView: function() {
		var _g = this;
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
			_g.onBackButtonClickCallback();
		};
		return backButtonContainer;
	}
	,updateView: function() {
		this._titleContainer.removeChild(this._titleTextElement);
		this._titleTextElement = js.Lib.document.createTextNode(this._data);
		this._titleContainer.appendChild(this._titleTextElement);
	}
	,buildView: function() {
		org.intermedia.view.HeaderStyle.setHeaderStyle(this.node);
		this._titleTextElement = js.Lib.document.createTextNode(this._data);
		this._titleContainer = js.Lib.document.createElement("div");
		this._titleContainer.appendChild(this._titleTextElement);
		org.intermedia.view.HeaderStyle.setHeaderTextStyle(this._titleContainer);
		this.node.appendChild(this._titleContainer);
	}
	,setDisplayBackButton: function(v) {
		this._displayBackButton = v;
		if(this._displayBackButton) this.node.appendChild(this._backButtonContainer); else if(this._backButtonContainer.parentNode != null) this.node.removeChild(this._backButtonContainer);
		return this._displayBackButton;
	}
	,getDisplayBackButton: function() {
		return this._displayBackButton;
	}
	,__class__: org.intermedia.view.HeaderView
});
org.intermedia.view.HomePage = $hxClasses["org.intermedia.view.HomePage"] = function(initData) {
	this._data = initData;
	this.cells = new Array();
	org.intermedia.view.ViewBase.call(this);
};
org.intermedia.view.HomePage.__name__ = true;
org.intermedia.view.HomePage.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.HomePage.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onListItemSelectedCallback: function(cellData) {
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	}
	,buildView: function() {
		var _g2 = this;
		var cellStyle = { cell : org.intermedia.view.CellThumbText1BisStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbStyle.setThumbnailMaskStyle, thumbnail : null, textBlock : null, title : null, author : null};
		var cell0 = new org.intermedia.view.CellThumb(1,cellStyle);
		this.cells.push(cell0);
		var cell1 = new org.intermedia.view.CellThumb(2,cellStyle);
		this.cells.push(cell1);
		var cell2 = new org.intermedia.view.CellThumb(2,cellStyle);
		this.cells.push(cell2);
		var cell3 = new org.intermedia.view.CellThumb(2,cellStyle);
		this.cells.push(cell3);
		var cell4 = new org.intermedia.view.CellThumb(2,cellStyle);
		this.cells.push(cell4);
		var _g1 = 0, _g = this.cells.length;
		while(_g1 < _g) {
			var i = [_g1++];
			this.cells[i[0]].setData(this._data[i[0]]);
			this.cells[i[0]].node.onmouseup = (function(i) {
				return function(mouseEventData) {
					_g2.onListItemSelectedCallback(_g2.cells[i[0]].getData());
				};
			})(i);
			this.node.appendChild(this.cells[i[0]].node);
		}
	}
	,__class__: org.intermedia.view.HomePage
});
org.intermedia.view.ImageUtils = $hxClasses["org.intermedia.view.ImageUtils"] = function() { }
org.intermedia.view.ImageUtils.__name__ = true;
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
org.intermedia.view.ListViewBase = $hxClasses["org.intermedia.view.ListViewBase"] = function() {
	org.intermedia.view.ViewBase.call(this);
	this.initStyle();
	this._style.list(this.node);
	this._dataRequested = false;
	this.displayListBottomLoader = true;
	this._cells = new Array();
	this.buildBottomLoader();
	this.node.onscroll = $bind(this,this.onScrollCallback);
};
org.intermedia.view.ListViewBase.__name__ = true;
org.intermedia.view.ListViewBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.ListViewBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	refreshStyles: function() {
		this._style.list(this.node);
		var _g = 0, _g1 = this._cells;
		while(_g < _g1.length) {
			var cell = _g1[_g];
			++_g;
			cell.refreshStyles();
		}
	}
	,onDataRequestCallback: function(id) {
		if(this.onDataRequest != null) this.onDataRequest(id);
	}
	,onScrollCallback: function(event) {
		if(!this._dataRequested && this.node.scrollTop >= this.node.scrollHeight - (js.Lib.window.innerHeight - 78) - 10) {
			this._dataRequested = true;
			this.onDataRequestCallback(this.id);
		}
	}
	,onListItemSelectedCallback: function(cellData) {
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	}
	,createCell: function() {
		var cell = new org.intermedia.view.CellBase();
		return cell;
	}
	,updateView: function() {
		var _g2 = this;
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var index = _g1[_g];
			++_g;
			var cell = [this.createCell()];
			cell[0].setData(Reflect.field(this._data,index));
			cell[0].node.onmouseup = (function(cell) {
				return function(mouseEventData) {
					_g2.onListItemSelectedCallback(cell[0].getData());
				};
			})(cell);
			this._cells.push(cell[0]);
			this.node.appendChild(cell[0].node);
		}
		if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
		if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
		if(this.node.parentNode.parentNode != null) {
		}
		this._dataRequested = false;
	}
	,buildBottomLoader: function() {
		this._bottomLoaderImage = js.Lib.document.createElement("img");
		org.intermedia.view.ListViewStyle.loaderImage(this._bottomLoaderImage);
		this._bottomLoaderImage.src = "assets/loading.gif";
		this._listBottomLoader = js.Lib.document.createElement("div");
		this._listBottomLoader.appendChild(this._bottomLoaderImage);
		org.intermedia.view.CellStyle.setCellStyle(this._listBottomLoader);
	}
	,initStyle: function() {
		this._style = { list : org.intermedia.view.ListViewStyle.setListStyle};
	}
	,__class__: org.intermedia.view.ListViewBase
});
org.intermedia.view.ListViewStyle = $hxClasses["org.intermedia.view.ListViewStyle"] = function() { }
org.intermedia.view.ListViewStyle.__name__ = true;
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
	node.style.width = Std.string(js.Lib.window.innerWidth) + "px";
	node.style.height = "100%";
	node.style.top = "0px";
	node.style.bottom = "0px";
	node.style.verticalAlign = "top";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
	node.style.backgroundColor = "#CCCCCC";
}
org.intermedia.view.ListViewStyle.loaderImage = function(node) {
	node.style.display = "block";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.marginTop = "10px";
	node.style.marginBottom = Std.string(10) + "px";
	node.style.top = Std.string(js.Lib.window.innerHeight) + "px";
}
org.intermedia.view.ListViewText = $hxClasses["org.intermedia.view.ListViewText"] = function() {
	org.intermedia.view.ListViewBase.call(this);
};
org.intermedia.view.ListViewText.__name__ = true;
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
org.intermedia.view.LoadingView.__name__ = true;
org.intermedia.view.LoadingView.prototype = {
	loadThumb: function() {
		var image = js.Lib.document.createElement("img");
		org.intermedia.view.LoadingViewStyle.setThumbnailStyle(image);
		this.node.appendChild(image);
		image.src = "assets/loading.gif";
	}
	,__class__: org.intermedia.view.LoadingView
}
org.intermedia.view.LoadingViewStyle = $hxClasses["org.intermedia.view.LoadingViewStyle"] = function() { }
org.intermedia.view.LoadingViewStyle.__name__ = true;
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
org.intermedia.view.MenuCellText = $hxClasses["org.intermedia.view.MenuCellText"] = function() {
	org.intermedia.view.CellBase.call(this);
};
org.intermedia.view.MenuCellText.__name__ = true;
org.intermedia.view.MenuCellText.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.MenuCellText.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	updateView: function() {
		var cellData = this._data;
		var cellTextContainer = js.Lib.document.createElement("div");
		if(cellData.title != "" && cellData.title != null) {
			var textElement = js.Lib.document.createTextNode(cellData.title);
			cellTextContainer.appendChild(textElement);
			this.node.appendChild(cellTextContainer);
			this._style.title(cellTextContainer);
		}
	}
	,initStyle: function() {
		this._style = { cell : org.intermedia.view.MenuCellTextStyle.setCellStyle, thumbnailMask : null, thumbnail : null, textBlock : null, title : org.intermedia.view.MenuCellTextStyle.setCellTextStyle, author : null};
	}
	,__class__: org.intermedia.view.MenuCellText
});
org.intermedia.view.MenuCellTextStyle = $hxClasses["org.intermedia.view.MenuCellTextStyle"] = function() { }
org.intermedia.view.MenuCellTextStyle.__name__ = true;
org.intermedia.view.MenuCellTextStyle.setCellStyle = function(node,cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
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
org.intermedia.view.MenuListViewStyle = $hxClasses["org.intermedia.view.MenuListViewStyle"] = function() { }
org.intermedia.view.MenuListViewStyle.__name__ = true;
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
	node.style.backgroundImage = "url(" + "assets/tile_french-tech2.png" + ")";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
}
org.intermedia.view.MenuListViewText = $hxClasses["org.intermedia.view.MenuListViewText"] = function() {
	this._index = 0;
	this._menuItem0LeftTarget = 0;
	this._menuItem1LeftTarget = 0;
	this._menuItem2LeftTarget = 0;
	org.intermedia.view.ListViewBase.call(this);
	this.displayListBottomLoader = false;
};
org.intermedia.view.MenuListViewText.__name__ = true;
org.intermedia.view.MenuListViewText.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.MenuListViewText.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	refreshStyles: function() {
		this.computeMenuItemsLeftTarget(this._index);
		this.menuItem0Move(this._menuItem0LeftTarget);
		this.menuItem1Move(this._menuItem1LeftTarget);
		this.menuItem2Move(this._menuItem2LeftTarget);
		this.computeMenuItemsLeftPos();
	}
	,horizontalTweenEnd: function(newIndex) {
		this.setIndex(newIndex);
		this.refreshStyles();
	}
	,moveHorizontally: function(ratio) {
		if(ratio > 0) this.computeMenuItemsLeftTarget(Math.max(this._index - 1,0) | 0); else if(ratio < 0) this.computeMenuItemsLeftTarget(Math.min(this._index + 1,2) | 0);
		this.menuItem0Move(this._menuItem0LeftPos + Math.abs(this._menuItem0LeftTarget - this._menuItem0LeftPos) * ratio);
		this.menuItem1Move(this._menuItem1LeftPos + Math.abs(this._menuItem1LeftTarget - this._menuItem1LeftPos) * ratio);
		this.menuItem2Move(this._menuItem2LeftPos + Math.abs(this._menuItem2LeftTarget - this._menuItem2LeftPos) * ratio);
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
	,computeMenuItemsLeftPos: function() {
		this._menuItem0LeftPos = this._cells[0].node.offsetLeft;
		this._menuItem1LeftPos = this._cells[1].node.offsetLeft;
		this._menuItem2LeftPos = this._cells[2].node.offsetLeft;
	}
	,computeMenuItemsWidth: function() {
		this._menuItem0Width = this._cells[0].node.clientWidth;
		this._menuItem1Width = this._cells[1].node.clientWidth;
		this._menuItem2Width = this._cells[2].node.clientWidth;
	}
	,menuItem2Move: function(e) {
		this._cells[2].node.style.left = (e | 0) + "px";
	}
	,menuItem1Move: function(e) {
		this._cells[1].node.style.left = (e | 0) + "px";
	}
	,menuItem0Move: function(e) {
		this._cells[0].node.style.left = (e | 0) + "px";
	}
	,setIndex: function(v) {
		this._cells[this._index].node.style.fontWeight = "normal";
		this._cells[v].node.style.fontWeight = "bold";
		this._index = v;
		return v;
	}
	,getIndex: function() {
		return this._index;
	}
	,createCell: function() {
		var cell = new org.intermedia.view.MenuCellText();
		return cell;
	}
	,updateView: function() {
		var _g2 = this;
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var field = _g1[_g];
			++_g;
			var cell = [this.createCell()];
			cell[0].setData(Reflect.field(this._data,field));
			cell[0].node.onmouseup = (function(cell) {
				return function(mouseEventData) {
					_g2.onListItemSelectedCallback(cell[0].getData());
				};
			})(cell);
			this._cells.push(cell[0]);
			this.node.appendChild(cell[0].node);
		}
		if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
		if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
		this.computeMenuItemsWidth();
		this.setIndex(1);
		this.refreshStyles();
	}
	,initStyle: function() {
		this._style = { list : org.intermedia.view.MenuListViewStyle.setMenuStyle};
	}
	,__class__: org.intermedia.view.MenuListViewText
});
org.intermedia.view.Scroll2D = $hxClasses["org.intermedia.view.Scroll2D"] = function(scrollType) {
	this._scrollType = scrollType;
	this.initialScrollPosition = { x : 0, y : 0};
	this.init();
};
org.intermedia.view.Scroll2D.__name__ = true;
org.intermedia.view.Scroll2D.prototype = {
	computeAverageVelocity: function() {
		this._verticalVelocity = 0;
		var sum = 0;
		var _g1 = 0, _g = this._verticalVelocityArray.length;
		while(_g1 < _g) {
			var i = _g1++;
			sum += this._verticalVelocityArray[i] * (5 - i);
		}
		this._verticalVelocity = sum / 15.;
	}
	,computeVelocity: function(time) {
		this._verticalVelocity = (this._offset.y - this._previousY) / time;
		this._previousY = this._offset.y;
		if(this._verticalVelocityArray.length < 5) {
			var _g = 0;
			while(_g < 5) {
				var i = _g++;
				this._verticalVelocityArray.push(this._verticalVelocity);
			}
		} else {
			this._verticalVelocityArray.unshift(this._verticalVelocity);
			this._verticalVelocityArray.pop();
		}
	}
	,onVerticalReleaseCallback: function() {
		if(this.onVerticalScroll != null) {
			var timeDelta = haxe.Timer.stamp() * 1000 - this._time;
			var releaseTime = Math.abs(this._verticalVelocity / 0.01);
			var amplitude = this._verticalVelocity * releaseTime;
			var verticalReleaseDelta = this._offset.y + (amplitude * (1 - Math.exp(-timeDelta / releaseTime)) | 0);
			this.onVerticalScroll(verticalReleaseDelta);
			if(timeDelta > 6 * releaseTime) this._decelerationTimer.stop();
		}
	}
	,onVerticalScrollCallback: function(e) {
		if(this.onVerticalScroll != null) this.onVerticalScroll(e | 0);
	}
	,verticalReleaseTween: function() {
		this._time = haxe.Timer.stamp() * 1000;
		if(this._offset.y > 0) this._verticalReleaseDeceleration = -0.01; else this._verticalReleaseDeceleration = 0.01;
		this.computeAverageVelocity();
		this._decelerationTimer = new haxe.Timer(10);
		this._decelerationTimer.run = $bind(this,this.onVerticalReleaseCallback);
	}
	,horizontalTweenEnd: function(e) {
		if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd(e | 0);
	}
	,onHorizontalScrollCallback: function(xOffset) {
		if(this.onHorizontalScroll != null) this.onHorizontalScroll(xOffset | 0);
	}
	,horizontalReleaseTween: function(xOrigin,xTarget) {
		this._horizontalTween = new feffects.Tween(xOrigin,xTarget,150,feffects.easing.Quad.easeOut);
		this._horizontalTween.onUpdate($bind(this,this.onHorizontalScrollCallback));
		this._horizontalTween.onFinish($bind(this,this.horizontalTweenEnd));
		this._horizontalTween.start();
	}
	,onHorizontalUpCallback: function(event) {
		if(this.onHorizontalUp != null) this.onHorizontalUp(event,this._offset.x);
	}
	,onUpCallback: function(event) {
		if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalUpCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) this.verticalReleaseTween();
		this._direction = org.intermedia.view.Direction.notYetSet;
	}
	,onVerticalMoveCallback: function(event) {
		var timeDelta = haxe.Timer.stamp() * 1000 - this._time;
		this._time = haxe.Timer.stamp() * 1000;
		this.computeVelocity(timeDelta);
		this._scrollPosition = { x : this.initialScrollPosition.x, y : this.initialScrollPosition.y - this._offset.y};
		if(this._scrollPosition.y > 0) event.preventDefault();
		this.onVerticalScrollCallback(this._offset.y);
	}
	,onHorizontalMoveCallback: function(event) {
		event.preventDefault();
		this._scrollPosition = { x : this.initialScrollPosition.x - this._offset.x, y : this.initialScrollPosition.y};
		this.onHorizontalScrollCallback(this._offset.x);
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
	,onDownCallback: function(event) {
		this.init();
		if(this._horizontalTween != null && this._horizontalTween.isPlaying) this._horizontalTween.pause();
		if(this._verticalTween != null && this._verticalTween.isPlaying) this._verticalTween.stop();
		this._initialPosition.x = event.touches[0].pageX;
		this._initialPosition.y = event.touches[0].pageY;
		if(this._scrollType == org.intermedia.view.ScrollType.horizontal) this._direction = org.intermedia.view.Direction.horizontal; else if(this._scrollType == org.intermedia.view.ScrollType.vertical) this._direction = org.intermedia.view.Direction.vertical; else this._direction = org.intermedia.view.Direction.notYetSet;
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
	,init: function() {
		this._initialPosition = { x : 0, y : 0};
		this._offset = { x : 0, y : 0};
		this._scrollPosition = { x : 0, y : 0};
		this._direction = org.intermedia.view.Direction.notYetSet;
		this._verticalVelocityArray = new Array();
		this._yDelta = 0;
		this._time = haxe.Timer.stamp() * 1000;
		this._verticalVelocity = 0;
		this._previousY = 0;
	}
	,__class__: org.intermedia.view.Scroll2D
}
org.intermedia.view.Direction = $hxClasses["org.intermedia.view.Direction"] = { __ename__ : true, __constructs__ : ["horizontal","vertical","notYetSet"] }
org.intermedia.view.Direction.horizontal = ["horizontal",0];
org.intermedia.view.Direction.horizontal.toString = $estr;
org.intermedia.view.Direction.horizontal.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.vertical = ["vertical",1];
org.intermedia.view.Direction.vertical.toString = $estr;
org.intermedia.view.Direction.vertical.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.notYetSet = ["notYetSet",2];
org.intermedia.view.Direction.notYetSet.toString = $estr;
org.intermedia.view.Direction.notYetSet.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.ScrollType = $hxClasses["org.intermedia.view.ScrollType"] = { __ename__ : true, __constructs__ : ["horizontal","vertical","both"] }
org.intermedia.view.ScrollType.horizontal = ["horizontal",0];
org.intermedia.view.ScrollType.horizontal.toString = $estr;
org.intermedia.view.ScrollType.horizontal.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.vertical = ["vertical",1];
org.intermedia.view.ScrollType.vertical.toString = $estr;
org.intermedia.view.ScrollType.vertical.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.both = ["both",2];
org.intermedia.view.ScrollType.both.toString = $estr;
org.intermedia.view.ScrollType.both.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.SplashScreenView = $hxClasses["org.intermedia.view.SplashScreenView"] = function() {
	this.node = js.Lib.document.createElement("div");
	org.intermedia.view.SplashScreenViewStyle.setLoadingStyle(this.node);
};
org.intermedia.view.SplashScreenView.__name__ = true;
org.intermedia.view.SplashScreenView.prototype = {
	__class__: org.intermedia.view.SplashScreenView
}
org.intermedia.view.SplashScreenViewStyle = $hxClasses["org.intermedia.view.SplashScreenViewStyle"] = function() { }
org.intermedia.view.SplashScreenViewStyle.__name__ = true;
org.intermedia.view.SplashScreenViewStyle.setLoadingStyle = function(node) {
	node.style.position = "absolute";
	node.style.marginBottom = "0px";
	node.style.marginTop = "0px";
	node.style.marginLeft = "0px";
	node.style.marginRight = "0px";
	node.style.paddingBottom = "0px";
	node.style.paddingTop = "0px";
	node.style.paddingLeft = "0px";
	node.style.paddingRight = "0px";
	node.style.width = "100%";
	node.style.height = "100%";
	node.style.backgroundColor = "#191919";
	var splashScreenUrl = "";
	var userAgent = js.Lib.window.navigator.userAgent.toLowerCase();
	if(userAgent.indexOf("iphone") != -1 || userAgent.indexOf("ipad") != -1) splashScreenUrl = "splashScreens/splashScreen-640x920.png"; else if(userAgent.indexOf("android") != -1) splashScreenUrl = "splashScreens/splashScreen-480x800.png"; else splashScreenUrl = "splashScreens/splashScreen-640x960.png";
	node.style.backgroundImage = "url(" + splashScreenUrl + ")";
	node.style.backgroundRepeat = "no-repeat";
	node.style.backgroundSize = "100% 100%";
	node.style.zIndex = 1000;
}
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
	this.list0.id = { id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"}.url;
	this._listViews.push(this.list0);
	this.list1 = new org.intermedia.view.ThumbTextList1Bis(2);
	this.list1.id = { id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"}.url;
	this._listViews.push(this.list1);
	this.list2 = new org.intermedia.view.ThumbTextList1(2);
	this.list2.id = { id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"}.url;
	this._listViews.push(this.list2);
	this.positionLists();
	var _g = 0, _g1 = this._listViews;
	while(_g < _g1.length) {
		var listView = _g1[_g];
		++_g;
		listView.onDataRequest = $bind(this,this.onDataRequestCallback);
		listView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		this._listsContainer.appendChild(listView.node);
	}
	this._index = 1;
	this._currentListView = this._listViews[this._index];
	this._currentListView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
	this._scrollHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.both);
	this._scrollHandler.onVerticalScroll = $bind(this,this.onVerticalScroll);
	this._scrollHandler.onHorizontalScroll = $bind(this,this.onHorizontalScrollCallback);
	this._scrollHandler.onHorizontalUp = $bind(this,this.onHorizontalUpCallback);
	this._scrollHandler.onHorizontalTween = $bind(this,this.onHorizontalScrollCallback);
	this._scrollHandler.onHorizontalTweenEnd = $bind(this,this.onHorizontalTweenEndCallback);
	this.addTouchEvents();
};
org.intermedia.view.SwippableListView.__name__ = true;
org.intermedia.view.SwippableListView.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.SwippableListView.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	resetInitScrollPosition: function() {
		this._scrollHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this._currentListView.node.scrollTop};
	}
	,computeHorizontalRatio: function(xOffset) {
		var ratio = 0;
		if(js.Lib.window.innerWidth != 0) ratio = xOffset / js.Lib.window.innerWidth;
		return ratio;
	}
	,touchEnd: function(event) {
		this._currentListView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		this._scrollHandler.touchHandler(event);
	}
	,touchMove: function(event) {
		this._currentListView.onListItemSelected = null;
		this._scrollHandler.touchHandler(event);
	}
	,touchStart: function(event) {
		this.resetInitScrollPosition();
		this._scrollHandler.touchHandler(event);
	}
	,addTouchEvents: function() {
		this.node.addEventListener("touchstart",$bind(this,this.touchStart),false);
		this.node.addEventListener("touchmove",$bind(this,this.touchMove),false);
		this.node.addEventListener("touchend",$bind(this,this.touchEnd),false);
		this.node.addEventListener("touchcancel",($_=this._scrollHandler,$bind($_,$_.touchHandler)),false);
	}
	,onScrollCallback: function(event) {
	}
	,onHorizontalUpCallback: function(event,xOffset) {
		event.preventDefault();
		if(xOffset < -js.Lib.window.innerHeight * 0.06) {
			if(this.getIndex() < this._listViews.length - 1) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 + 1);
				_g1;
			}
		} else if(xOffset > js.Lib.window.innerHeight * 0.06) {
			if(this.getIndex() > 0) {
				var _g = this, _g1 = _g.getIndex();
				_g.setIndex(_g1 - 1);
				_g1;
			}
		} else this.setIndex(this.getIndex());
	}
	,onVerticalScroll: function(yOffset) {
		this._currentListView.node.scrollTop = this._scrollHandler.initialScrollPosition.y - yOffset;
	}
	,onHorizontalTweenEndCallback: function(xOffset) {
		this._currentListView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		var horizontalRatio = this.computeHorizontalRatio(xOffset);
		if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd(this._index);
	}
	,onHorizontalScrollCallback: function(xOffset) {
		this._currentListView.onListItemSelected = null;
		var horizontalRatio = this.computeHorizontalRatio(xOffset);
		this.node.scrollLeft = this._scrollHandler.initialScrollPosition.x - xOffset;
		if(this.node.scrollLeft > this.list0.node.offsetLeft && this.node.scrollLeft < this.list2.node.offsetLeft) {
			if(this.onHorizontalMove != null && horizontalRatio != 0) this.onHorizontalMove(horizontalRatio);
		}
	}
	,refreshStyles: function() {
		org.intermedia.view.ListViewBase.prototype.refreshStyles.call(this);
		this.positionLists();
		this.scrollToCurrentList();
		org.intermedia.view.SwippableListViewStyle.setListsContainerStyle(this._listsContainer);
		var _g = 0, _g1 = this._listViews;
		while(_g < _g1.length) {
			var list = _g1[_g];
			++_g;
			list.refreshStyles();
		}
	}
	,scrollToCurrentList: function() {
		this.node.scrollLeft = Std.parseInt(HxOverrides.substr(this._currentListView.node.style.left,0,-2));
		this.resetInitScrollPosition();
	}
	,setIndex: function(v) {
		this._currentListView.onListItemSelected = null;
		this._index = v;
		this._currentListView = this._listViews[v];
		this._currentListView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		this._scrollHandler.horizontalReleaseTween(this._scrollHandler.initialScrollPosition.x - this.node.scrollLeft,this._scrollHandler.initialScrollPosition.x - this._currentListView.node.offsetLeft);
		return v;
	}
	,getIndex: function() {
		return this._index;
	}
	,updateView: function() {
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
	,positionLists: function() {
		this.list1.node.style.left = Std.string(js.Lib.window.innerWidth) + "px";
		this.list2.node.style.left = Std.string(2 * js.Lib.window.innerWidth) + "px";
	}
	,initStyle: function() {
		this._style = { list : org.intermedia.view.SwippableListViewStyle.setSwippableListStyle};
	}
	,__class__: org.intermedia.view.SwippableListView
});
org.intermedia.view.SwippableListViewStyle = $hxClasses["org.intermedia.view.SwippableListViewStyle"] = function() { }
org.intermedia.view.SwippableListViewStyle.__name__ = true;
org.intermedia.view.SwippableListViewStyle.setSwippableListStyle = function(node) {
	node.style.display = "block";
	node.style.position = "static";
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
org.intermedia.view.ThumbTextList1 = $hxClasses["org.intermedia.view.ThumbTextList1"] = function(cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	this._cellsPerLine = cellPerLine;
	org.intermedia.view.ListViewBase.call(this);
};
org.intermedia.view.ThumbTextList1.__name__ = true;
org.intermedia.view.ThumbTextList1.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ThumbTextList1.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	createCell: function() {
		var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine);
		return cell;
	}
	,__class__: org.intermedia.view.ThumbTextList1
});
org.intermedia.view.ThumbTextList1Bis = $hxClasses["org.intermedia.view.ThumbTextList1Bis"] = function(cellPerLine) {
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ThumbTextList1.call(this,cellPerLine);
};
org.intermedia.view.ThumbTextList1Bis.__name__ = true;
org.intermedia.view.ThumbTextList1Bis.__super__ = org.intermedia.view.ThumbTextList1;
org.intermedia.view.ThumbTextList1Bis.prototype = $extend(org.intermedia.view.ThumbTextList1.prototype,{
	createCell: function() {
		var cellStyle = { cell : org.intermedia.view.CellThumbText1BisStyle.setCellStyle, thumbnailMask : org.intermedia.view.CellThumbText1Style.setThumbnailMaskStyle, thumbnail : null, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : null};
		var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine,cellStyle);
		return cell;
	}
	,buildHomePage: function(homePageData) {
		var homePage = new org.intermedia.view.HomePage(homePageData);
		homePage.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		var _g1 = 0, _g = homePage.cells.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._cells.push(homePage.cells[i]);
			this.node.appendChild(this._cells[i].node);
		}
	}
	,initStyle: function() {
		this._style = { list : org.intermedia.view.ThumbTextList1BisStyle.setListStyle};
	}
	,__class__: org.intermedia.view.ThumbTextList1Bis
});
org.intermedia.view.ThumbTextList1BisStyle = $hxClasses["org.intermedia.view.ThumbTextList1BisStyle"] = function() { }
org.intermedia.view.ThumbTextList1BisStyle.__name__ = true;
org.intermedia.view.ThumbTextList1BisStyle.setListStyle = function(node) {
	org.intermedia.view.ListViewStyle.setListStyle(node);
	node.style.backgroundColor = "#191919";
}
org.intermedia.view.ViewManager = $hxClasses["org.intermedia.view.ViewManager"] = function(applicationModel,applicationController) {
	this._applicationModel = applicationModel;
	this._applicationController = applicationController;
	this._body = js.Lib.document.body;
	org.intermedia.view.ViewManagerStyle.setBodyStyle(this._body);
	this._loadingView = new org.intermedia.view.SplashScreenView();
	this._body.appendChild(this._loadingView.node);
	js.Lib.window.onload = $bind(this,this.onLoad);
};
org.intermedia.view.ViewManager.__name__ = true;
org.intermedia.view.ViewManager.prototype = {
	refreshStyles: function() {
		if(this._currentView == this._swippableListView) {
			this._menu.refreshStyles();
			this._swippableListView.refreshStyles();
		} else if(this._currentView == this._detailView) this._detailView.refreshStyles();
	}
	,setZIndexToMax: function(view) {
		this._body.removeChild(view.node);
		this._body.appendChild(view.node);
	}
	,updateZIndexes: function() {
		this.setZIndexToMax(this._menu);
		this.setZIndexToMax(this._header);
	}
	,onHeaderBackButtonPressed: function() {
		this._header.setData("French Tech");
		this._header.setDisplayBackButton(false);
		js.Lib.document.removeEventListener("backbutton",$bind(this,this.onHeaderBackButtonPressed),false);
		this._body.removeChild(this._detailView.node);
		this._body.appendChild(this._menu.node);
		this._body.appendChild(this._swippableListView.node);
		this._currentView = this._swippableListView;
		this.updateZIndexes();
		this._swippableListView.scrollToCurrentList();
		this.refreshStyles();
	}
	,onLoadingError: function(error) {
		console.log("Load error: " + Std.string(error));
		haxe.Firebug.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 253, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
	}
	,onStartLoading: function() {
	}
	,onDetailDataLoaded: function(detailData) {
		this._detailView.setData(detailData);
		this._header.setData("Infos");
		this._header.setDisplayBackButton(true);
		this.setZIndexToMax(this._header);
		this.refreshStyles();
		this._detailView.setDisplayLoading(false);
	}
	,onCellDataLoaded: function(listData) {
		if(listData.cells.length == 0) this._swippableListView.displayListBottomLoader = false;
		this._swippableListView.setData(listData);
		this.updateZIndexes();
	}
	,onListItemSelectedCallback: function(cellData) {
		this._body.removeChild(this._swippableListView.node);
		this._body.removeChild(this._menu.node);
		this._detailView = new org.intermedia.view.DetailView();
		this._body.appendChild(this._detailView.node);
		js.Lib.document.addEventListener("backbutton",$bind(this,this.onHeaderBackButtonPressed),false);
		this._currentView = this._detailView;
		this.onDetailDataLoaded(cellData);
	}
	,onMenuItemSelectedCallback: function(cellData) {
		this._swippableListView.resetInitScrollPosition();
		this._swippableListView.setIndex(cellData.id);
	}
	,init: function() {
		var _g = this;
		this._header = new org.intermedia.view.HeaderView();
		this._header.setData("French Tech");
		this._header.onBackButtonClick = $bind(this,this.onHeaderBackButtonPressed);
		this._body.appendChild(this._header.node);
		this._menu = new org.intermedia.view.MenuListViewText();
		this._menu.displayListBottomLoader = false;
		this._body.appendChild(this._menu.node);
		this._menu.setData([{ id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"},{ id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"},{ id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"}]);
		this._swippableListView = new org.intermedia.view.SwippableListView();
		this._body.appendChild(this._swippableListView.node);
		this._currentView = this._swippableListView;
		this._detailView = new org.intermedia.view.DetailView();
		js.Lib.window.onresize = function(event) {
			_g.refreshStyles();
		};
		this._applicationModel.onModelStartsLoading = $bind(this,this.onStartLoading);
		this._applicationModel.onModelDataLoadError = $bind(this,this.onLoadingError);
		this._applicationModel.onModelCellDataLoaded = $bind(this,this.onCellDataLoaded);
		this._applicationModel.onModelDetailDataLoaded = $bind(this,this.onDetailDataLoaded);
		this._menu.onListItemSelected = $bind(this,this.onMenuItemSelectedCallback);
		this._swippableListView.onListItemSelected = $bind(this,this.onListItemSelectedCallback);
		this._swippableListView.onDataRequest = ($_=this._applicationController,$bind($_,$_.loadCellData));
		this._swippableListView.onHorizontalMove = ($_=this._menu,$bind($_,$_.moveHorizontally));
		this._swippableListView.onHorizontalTweenEnd = ($_=this._menu,$bind($_,$_.horizontalTweenEnd));
		this._applicationController.loadCellData({ id : 0, title : "iPhon.fr", thumb : "assets/iphon_fr-logo.jpg", url : "http://www.iphon.fr/feed/rss2", generatedBy : "wordpress"}.url);
		this._applicationController.loadCellData({ id : 1, title : "FrAndroid", thumb : "assets/frandroid-logo.png", url : "http://www.frandroid.com/feed", generatedBy : "wordpress"}.url);
		this._applicationController.loadCellData({ id : 2, title : "frenchiPhone", thumb : "assets/frenchiphone-logo.png", url : "http://www.frenchiphone.com/feed/", generatedBy : "wordpress"}.url);
		this._body.removeChild(this._loadingView.node);
	}
	,onLoad: function(event) {
		haxe.Timer.delay($bind(this,this.init),100);
	}
	,__class__: org.intermedia.view.ViewManager
}
org.intermedia.view.ViewManagerStyle = $hxClasses["org.intermedia.view.ViewManagerStyle"] = function() { }
org.intermedia.view.ViewManagerStyle.__name__ = true;
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
	node.style.height = "100%";
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
}
var $_;
function $bind(o,m) { var f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; return f; };
if(Array.prototype.indexOf) HxOverrides.remove = function(a,o) {
	var i = a.indexOf(o);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
}; else null;
Math.__name__ = ["Math"];
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
$hxClasses.Math = Math;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i) {
	return isNaN(i);
};
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = true;
Array.prototype.__class__ = $hxClasses.Array = Array;
Array.__name__ = true;
Date.prototype.__class__ = $hxClasses.Date = Date;
Date.__name__ = ["Date"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = $hxClasses.Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = $hxClasses.Class = { __name__ : ["Class"]};
var Enum = { };
Xml.Element = "element";
Xml.PCData = "pcdata";
Xml.CData = "cdata";
Xml.Comment = "comment";
Xml.DocType = "doctype";
Xml.Prolog = "prolog";
Xml.Document = "document";
haxe.Resource.content = [{ name : "feed3", data : "s88214:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPkZyZW5jaFdlYi5mcjwvdGl0bGU%DQoJPGF0b206bGluayBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2ZlZWQvP3Bvc3RzX3Blcl9wYWdlPTEwIiByZWw9InNlbGYiIHR5cGU9ImFwcGxpY2F0aW9uL3Jzcyt4bWwiIC8%DQoJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mcjwvbGluaz4NCgk8ZGVzY3JpcHRpb24%TGUgbWFnYXppbmUgZGVzIHByb2Zlc3Npb25uZWxzIGRlIGwmIzAzOTtpbnRlcm5ldCAtIEJ1c2luZXNzLCBtYXJrZXRpbmcsIHRlY2gsIGRlc2lnbiwgbWFuYWdlbWVudDwvZGVzY3JpcHRpb24%DQoJPGxhc3RCdWlsZERhdGU%RnJpLCAzMCBNYXIgMjAxMiAxNTo1ODo1NiArMDAwMDwvbGFzdEJ1aWxkRGF0ZT4NCg0KCTxsYW5ndWFnZT5lbjwvbGFuZ3VhZ2U%DQoJPHN5OnVwZGF0ZVBlcmlvZD5ob3VybHk8L3N5OnVwZGF0ZVBlcmlvZD4NCgk8c3k6dXBkYXRlRnJlcXVlbmN5PjE8L3N5OnVwZGF0ZUZyZXF1ZW5jeT4NCgk8Z2VuZXJhdG9yPmh0dHA6Ly93b3JkcHJlc3Mub3JnLz92PTMuMy4xPC9nZW5lcmF0b3I%DQoJPGF0b206bGluayByZWw9J2h1YicgaHJlZj0naHR0cDovL2ZyZW5jaHdlYi5mci8:cHVzaHByZXNzPWh1YicvPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkxlcyBvZmZyZXMgZCYjODIxNztlbXBsb2kgZGUgbGEgc2VtYWluZSA6IFJlc3BvbnNhYmxlIFByb2R1aXQgV2ViIEIyQywgQXVkaWVuY2UgTWFuYWdlciYjODIzMDs8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW9mZnJlcy1kZW1wbG9pLWRlLWxhLXNlbWFpbmUtcmVzcG9uc2FibGUtcHJvZHVpdC13ZWItYjJjLWF1ZGllbmNlLW1hbmFnZXItNjExNDMvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtb2ZmcmVzLWRlbXBsb2ktZGUtbGEtc2VtYWluZS1yZXNwb25zYWJsZS1wcm9kdWl0LXdlYi1iMmMtYXVkaWVuY2UtbWFuYWdlci02MTE0My8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE1OjU4OjU2ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5yTWVuPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtNYXJrZXRpbmddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQXVkaWVuY2UgTWFuYWdlcl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtlbXBsb2ldXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtSZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkNdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTYxMTwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0NoYXF1ZSB2ZW5kcmVkaSwgbCYjODIxNztlbXBsb2kgZXN0IGF1IHJlbmRlei12b3VzIHN1ciBGcmVuY2h3ZWIgISBSZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkMsIENoZWYgZGUgcHJvamV0IHNlbmlvciB3ZWJtYXJrZXRpbmcgLyBTRU8sIFJlc3BvbnNhYmxlIENvbW1lcmNpYWwgTW9iaWxlJiM4MjMwOyBSZXRyb3V2ZXogbGVzIGRlcm5pw6hyZXMgb2ZmcmVzIGQmIzgyMTc7ZW1wbG9pIGR1IHNlY3RldXIgSW50ZXJuZXQuDQoNCg0KUmVzcG9uc2FibGUgUHJvZHVpdCBXZWIgQjJDIEAgTGFGb3VyY2hldHRlLmNvbQ0KQXVkaWVuY2UgTWFuYWdlciBAIENBVEFMSU5BDQpDaGVmIGRlIHByb2pldCBzZW5pb3Igd2VibWFya2V0aW5nIC8gU0VPIEAgRS1Nb25kZW9zDQpSZXNwb25zYWJsZSBDb21tZXJjaWFsIE1vYmlsZSAobWVkaWEgZXQgcGVyZm9ybWFuY2UgbWFya2V0aW5nKSBAIFBVUkUgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5DaGFxdWUgdmVuZHJlZGksIGwmIzgyMTc7ZW1wbG9pIGVzdCBhdSByZW5kZXotdm91cyBzdXIgRnJlbmNod2ViICEgUmVzcG9uc2FibGUgUHJvZHVpdCBXZWIgQjJDLCBDaGVmIGRlIHByb2pldCBzZW5pb3Igd2VibWFya2V0aW5nIC8gU0VPLCBSZXNwb25zYWJsZSBDb21tZXJjaWFsIE1vYmlsZSYjODIzMDsgUmV0cm91dmV6IGxlcyBkZXJuacOocmVzIG9mZnJlcyBkJiM4MjE3O2VtcGxvaSBkdSBzZWN0ZXVyIEludGVybmV0LjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciIgdGl0bGU9ImlTdG9ja18wMDAwMTM4MzYxODJTbWFsbDEiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMS8xMC9pU3RvY2tfMDAwMDEzODM2MTgyU21hbGwxLmpwZWciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMxNiIgLz48L3A%DQo8dWw%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL3Jlc3BvbnNhYmxlLXByb2R1aXQtd2ViLWIyYy1oZi8iIHRhcmdldD0iX2JsYW5rIj5SZXNwb25zYWJsZSBQcm9kdWl0IFdlYiBCMkMgQCBMYUZvdXJjaGV0dGUuY29tPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL2F1ZGllbmNlLW1hbmFnZXIvIiB0YXJnZXQ9Il9ibGFuayI%QXVkaWVuY2UgTWFuYWdlciBAIENBVEFMSU5BPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL2VtcGxvaS5mcmVuY2h3ZWIuZnIvb2ZmcmUtZW1wbG9pL2NoZWYtZGUtcHJvamV0LXNlbmlvci13ZWJtYXJrZXRpbmctc2VvLWhmLyIgdGFyZ2V0PSJfYmxhbmsiPkNoZWYgZGUgcHJvamV0IHNlbmlvciB3ZWJtYXJrZXRpbmcgLyBTRU8gQCBFLU1vbmRlb3M8L2E%PC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vZW1wbG9pLmZyZW5jaHdlYi5mci9vZmZyZS1lbXBsb2kvcmVzcG9uc2FibGUtY29tbWVyY2lhbC1tb2JpbGUtbWVkaWEtZXQtcGVyZm9ybWFuY2UtbWFya2V0aW5nLWhmLyIgdGFyZ2V0PSJfYmxhbmsiPlJlc3BvbnNhYmxlIENvbW1lcmNpYWwgTW9iaWxlIChtZWRpYSBldCBwZXJmb3JtYW5jZSBtYXJrZXRpbmcpIEAgUFVSRSBBR0VOQ1k8L2E%PC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vZW1wbG9pLmZyZW5jaHdlYi5mci9vZmZyZS1lbXBsb2kvcmVzcG9uc2FibGUtcGFydGVuYXJpYXRzLWRpcmVjdHMtZ3JvdXBlLWUtY29tbWVyY2UtaGYvIiB0YXJnZXQ9Il9ibGFuayI%UmVzcG9uc2FibGUgcGFydGVuYXJpYXRzIGRpcmVjdHMgLyBncm91cGUgZS1jb21tZXJjZSBAIE5ldCBOZXcgVGFsZW50PC9hPjwvbGk%DQo8L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW9mZnJlcy1kZW1wbG9pLWRlLWxhLXNlbWFpbmUtcmVzcG9uc2FibGUtcHJvZHVpdC13ZWItYjJjLWF1ZGllbmNlLW1hbmFnZXItNjExNDMvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCg0KCQk8aXRlbT4NCgkJPHRpdGxlPltHYWRnZXQgZGUgbGEgc2VtYWluZV0gRS1wYXBlciwgbCYjODIxNzvDqWNyYW4gZmxleGlibGUgZGUgTEc8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2dhZGdldC1kZS1sYS1zZW1haW5lLWUtcGFwZXItZWNyYW4tZmxleGlibGUtZGUtbGctNjExNDIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9nYWRnZXQtZGUtbGEtc2VtYWluZS1lLXBhcGVyLWVjcmFuLWZsZXhpYmxlLWRlLWxnLTYxMTQyLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTU6NDY6MzUgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1RlY2hdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZSBwYXBlcl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtFUERdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTEddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTczMzwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0xvbmd0ZW1wcyBmYW50YXNtw6lzIHBhciBkZSBub21icmV1eCBnZWVrcywgbGVzIMOpY3JhbnMgZmxleGlibGVzIGRldnJhaWVudCBiaWVudMO0dCDDqnRyZSBjb21tZXJjaWFsaXPDqXMuIEVuIGVmZmV0LCBMRyBhIHLDqWNlbW1lbnQgYW5ub25jw6kgcXVlIGxlcyBwcmVtaWVycyDDqWNyYW5zIGRlIGNlIGdlbnJlLCBkZXN0aW7DqXMgYXV4IGUtcmVhZGVycywgZGV2YWllbnQgZmFpcmUgbGV1ciBhcnJpdsOpZSBlbiBFdXJvcGUsIGQmIzgyMTc7aWNpIGxhIGZpbiBkdSBtb2lzIGQmIzgyMTc7YXZyaWwuDQoNCkJhcHRpc8OpIEVQRCBwb3VyIMKrZWxlY3Ryb25pYyBwYXBlciBkaXNwbGF5wrssIGNlIGdhZGdldCBncmFuZCBkZSBzaXggcG91Y2VzIG5lIGZlcmFpdCBxdWUgMCw3IG1tIGQmIzgyMTc7w6lwYWlzc2V1ci4gU2Vsb24gWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5Mb25ndGVtcHMgZmFudGFzbcOpcyBwYXIgZGUgbm9tYnJldXggZ2Vla3MsIGxlcyDDqWNyYW5zIGZsZXhpYmxlcyBkZXZyYWllbnQgYmllbnTDtHQgw6p0cmUgY29tbWVyY2lhbGlzw6lzLiBFbiBlZmZldCwgPGEgaHJlZj0iaHR0cDovL3d3dy5sZy5jb20vZnIvaW5kZXguanNwIiB0YXJnZXQ9Il9ibGFuayI%TEc8L2E%IGEgcsOpY2VtbWVudCBhbm5vbmPDqSBxdWUgbGVzIHByZW1pZXJzIMOpY3JhbnMgZGUgY2UgZ2VucmUsIGRlc3RpbsOpcyBhdXggZS1yZWFkZXJzLCBkZXZhaWVudCBmYWlyZSBsZXVyIGFycml2w6llIGVuIEV1cm9wZSwgZCYjODIxNztpY2kgbGEgZmluIGR1IG1vaXMgZCYjODIxNzthdnJpbC48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1tZWRpdW0gd3AtaW1hZ2UtNTU3MzciIHRpdGxlPSJFLXBhcGVyIiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvRS1wYXBlci01NTB4MjM5LmpwZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjM5IiAvPjwvcD4NCjxwPkJhcHRpc8OpIEVQRCBwb3VyIMKrZWxlY3Ryb25pYyBwYXBlciBkaXNwbGF5wrssIGNlIGdhZGdldCBncmFuZCBkZSBzaXggcG91Y2VzIG5lIGZlcmFpdCBxdWUgMCw3IG1tIGQmIzgyMTc7w6lwYWlzc2V1ci4gU2Vsb24gbGUgc3VkLWNvcsOpZW4sIGwmIzgyMTc7w6ljcmFuIG9mZnJlIHVuZSByw6lzb2x1dGlvbiBkZSAxMDI0JiMyMTU7NzY4IHBpeGVscy4gRVBEIHMmIzgyMTc7YXBwdWllIHN1ciBsYSB0ZWNobm9sb2dpZSBlLWluayBldCBuZSBwcm9wb3NlIGRvbmMgcXVlIGRpZmbDqXJlbnRzIHRvbnMgZGUgZ3Jpcy4gT3V0cmUgc2EgZmxleGliaWxpdMOpICg0MMKwKSwgY2Ugbm91dmVhdSBwcm9kdWl0IHNlcmFpdCDDqWdhbGVtZW50IHRyw6hzIHLDqXNpc3RhbnQgZXQgc3Vydml2cmFpdCBhaW5zaSDDoCB1bmUgY2h1dGUgZGUgcGx1cyBkJiM4MjE3O3VuIG3DqHRyZS48L3A%DQo8cD5BcHLDqHMgTEcsIGxlcyBjb25zdHJ1Y3RldXJzIFNhbXN1bmcgZXQgU2hhcnAgZGV2cmFpZW50IMOpZ2FsZW1lbnQgY29tbWVyY2lhbGlzZXIgdHLDqHMgcHJvY2hhaW5lbWVudCBsZXMgbcOqbWVzIHR5cGVzIGRlIHByb2R1aXRzLjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvcGFwZXItbGktbm91dmVsbGUtbGV2ZWUtMi0xLW0vIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5VbmUgbm91dmVsbGUgbGV2w6llIGRlIDIuMSBNJCBwb3VyIFBhcGVyLmxpICE8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9wYXBlci1saS1sYW5jZS12ZXJzaW9uLWZyYW5jYWlzZS0xNTIzOC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPlBhcGVyLmxpIGxhbmNlIHNhIHZlcnNpb24gZnJhbsOnYWlzZSAmIzgyMTE7IEVudHJldGllbjwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2dhZGdldC1kZS1sYS1zZW1haW5lLWxlLXNhbXN1bmctZ2FsYXh5LXNraW4tZXQtc29uLWVjcmFuLWZsZXhpYmxlLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0dhZGdldCBkZSBsYSBzZW1haW5lXSBMZSBTYW1zdW5nIEdhbGF4eSBTa2luIGV0IHNvbiDDqWNyYW4gZmxleGlibGU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbi1zdWlzc2Utb24tZmFpdC1kdS1ib24tY2hvY29sYXQtbWFpcy1hdXNzaS1kZXMtc3RhcnR1cHMvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5FbiBTdWlzc2UsIG9uIGZhaXQgZHUgYm9uIGNob2NvbGF0IG1haXMgYXVzc2kgZGVzIHN0YXJ0dXBzICE8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sYW5uZWUtMjAxMC12dWUtcGFyLWNlZHJpYy1naW9yZ2ktdGVjaGNydW5jaC1mcmFuY2UvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MJiM4MjE3O2FubsOpZSAyMDEwIHZ1ZSBwYXIgQ8OpZHJpYyBHaW9yZ2ksIFRlY2hDcnVuY2ggRnJhbmNlPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZ2FkZ2V0LWRlLWxhLXNlbWFpbmUtZS1wYXBlci1lY3Jhbi1mbGV4aWJsZS1kZS1sZy02MTE0Mi9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjExNDEvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtbW91dmVtZW50cy1kZS1sYS1zZW1haW5lLTEyLTYxMTQxLyNjb21tZW50czwvY29tbWVudHM%DQoNCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxNToxODoyNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0RpZ2l0YXNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbRHVrZSBSYXpvcmZpc2hdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGFnYXJkZXJlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01pbGt5XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW25vbWluYXRpb25dXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtTRlJdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3ludGhlc2lvXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3RyYW5zZsOocmVzXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1MTM8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtBdWpvdXJkJiM4MjE3O2h1aSBsZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lIHNvbnQgYXUgcmVuZGV6LXZvdXMgc3VyIEZyZW5jaFdlYiAhIFN5bnRoZXNpbywgU0ZSLCBEaWdpdGFzLCBZYWhvbyEgRHVrZSBSYXpvcmZpc2gsIFBlcmZlbyYjODIzMDsgUmV0cm91dmV6IGxlcyBkZXJuaWVycyB0cmFuc2ZlcnRzIG1hcnF1YW50cyBkdSBzZWN0ZXVyLg0KDQoNClN0w6lwaGFuZSBHdWVycnksIERpcmVjdGV1ciBnw6luw6lyYWwgZGUgRHVrZSBSYXpvcmZpc2gsIGFubm9uY2UgbOKAmWFycml2w6llIGRlIGRldXggbm91dmVhdXggRGlyZWN0ZXVycyBjb25zZWlsIDogVGhvbWFzIERlIExhdHRyZSBldCBBZHJpw6FuIFJ1aXogTWVkaWF2aWxsYS4NCk1pbGt5LCBs4oCZYWdlbmNlIGRlIHNvY2lhbCBjb21tZXJjZSBjcsOpw6llIHBhciBQaWVycmUgTWF0dWNoZXQgYW5ub25jZSBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkF1am91cmQmIzgyMTc7aHVpIGxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmUgc29udCBhdSByZW5kZXotdm91cyBzdXIgRnJlbmNoV2ViICEgU3ludGhlc2lvLCBTRlIsIERpZ2l0YXMsIFlhaG9vISBEdWtlIFJhem9yZmlzaCwgUGVyZmVvJiM4MjMwOyBSZXRyb3V2ZXogbGVzIGRlcm5pZXJzIHRyYW5zZmVydHMgbWFycXVhbnRzIGR1IHNlY3RldXIuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTcyNCIgdGl0bGU9ImxlcyBtb3V2ZW1lbnRzIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbGVzLW1vdXZlbWVudHMzLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMTE3IiAvPjwvcD4NCjx1bD4NCjxsaT48c3Ryb25nPlN0w6lwaGFuZSBHdWVycnk8L3N0cm9uZz4sIERpcmVjdGV1ciBnw6luw6lyYWwgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5kdWtlLXJhem9yZmlzaC5jb20vIiB0YXJnZXQ9Il9ibGFuayI%RHVrZSBSYXpvcmZpc2g8L2E%LCBhbm5vbmNlIGzigJlhcnJpdsOpZSBkZSBkZXV4IG5vdXZlYXV4IERpcmVjdGV1cnMgY29uc2VpbCA6IFRob21hcyBEZSBMYXR0cmUgZXQgQWRyacOhbiBSdWl6IE1lZGlhdmlsbGEuPC9saT4NCjxsaT48YSBocmVmPSJodHRwOi8vd3d3Lm1pbGt5LmZyLyIgdGFyZ2V0PSJfYmxhbmsiPk1pbGt5LDwvYT4gbOKAmWFnZW5jZSBkZSBzb2NpYWwgY29tbWVyY2UgY3LDqcOpZSBwYXIgUGllcnJlIE1hdHVjaGV0IGFubm9uY2UgdHJvaXMgbm91dmVsbGVzIHJlY3J1ZXMgOiA8c3Ryb25nPkVtaWxpZSBNYXNjbGV0PC9zdHJvbmc%IHJlam9pbnQgbOKAmcOpcXVpcGUgY29tbWUgRGlyZWN0cmljZSBkZXMgT3DDqXJhdGlvbnMsIDxzdHJvbmc%TWFyeWxlbmUgRHVyaWV1PC9zdHJvbmc%IHJlam9pbnQgbOKAmWFnZW5jZSBhdSBwb3N0ZSBkZSBTb2NpYWwgbWVkaWEgY29uc3VsdGFudCBldCA8c3Ryb25nPkplcmVtaWUgRHVwdWlzPC9zdHJvbmc%IGVuIHRhbnQgcXVlIFNlbmlvciBwcm9kdWN0IG1hbmFnZXIuPC9saT4NCjxsaT48c3Ryb25nPllhbm5pY2sgTGFjb21iZTwvc3Ryb25nPiBhIMOpdMOpIG5vbW3DqSBkaXJlY3RldXIgZ8OpbsOpcmFsIGFkam9pbnQgZW4gY2hhcmdlIGR1IG1hcmtldGluZyBldCBkZSBsYSBzdHJhdMOpZ2llIGNoZXogPGEgaHJlZj0iaHR0cDovL3d3dy5sYWdhcmRlcmUtcHViLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5MYWdhcmTDqHJlIHB1YmxpY2l0w6kuPC9hPjwvbGk%DQo8bGk%PHN0cm9uZz5KZWFuLVBoaWxpcHBlIE1hcnR6ZWw8L3N0cm9uZz4gYSDDqXTDqSBub21tw6kgRGlyZWN0ZXVyIEfDqW7DqXJhbCBBZGpvaW50IGVuIGNoYXJnZSBkdSA8c3BhbiBpZD0ibW9yZS01NTUxMyI%PC9zcGFuPlBsYW5uaW5nIFN0cmF0w6lnaXF1ZSBkZSA8YSBocmVmPSJodHRwOi8vd3d3LmRpZ2l0YXMuZnIvIiB0YXJnZXQ9Il9ibGFuayI%RGlnaXRhcyBGcmFuY2UuPC9hPjwvbGk%DQo8bGk%PGEgaHJlZj0iaHR0cDovL3d3dy50dXJuLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5UdXJuPC9hPiwgcGxhdGVmb3JtZSBtb25kaWFsZSBkZSBkb25uw6llcyBwb3VyIGxhIHB1YmxpY2l0w6kgZXQgbGUgbWFya2V0aW5nIGRpZ2l0YWwsIGEgcsOpY2VtbWVudCByZW5mb3JjZXIgc29uIMOpcXVpcGUgY29tbWVyY2lhbGUgcGFuLWV1cm9ww6llbm5lIGF2ZWMgbGEgbm9taW5hdGlvbiBkZSA8c3Ryb25nPkplYW4tQ2xhdWRlIE11cmF0b3JlPC9zdHJvbmc%IGF1IHBvc3RlIGRlIGRpcmVjdGV1ciBjb21tZXJjaWFsIHBvdXIgbGEgRnJhbmNlLCBs4oCZSXRhbGllIGV0IGxhIHDDqW5pbnN1bGUgaWLDqXJpcXVlIGRlcHVpcyBsZSBub3V2ZWF1IGJ1cmVhdSBkZSBsYSBzb2Npw6l0w6ksIGJhc8OpIMOgIFBhcmlzLjwvbGk%DQo8bGk%U2Vsb24gZGVzIHNvdXJjZXMgcHJvY2hlcyBkdSBkb3NzaWVyLCA8YSBocmVmPSJodHRwOi8vd3d3LnNmci5mci8iIHRhcmdldD0iX2JsYW5rIj5TRlI8L2E%IGRldnJhaXQgYW5ub25jZXIgbGEgbm9taW5hdGlvbiA8c3Ryb25nPmTigJlPbGl2aWVyIFNpY2hlbDwvc3Ryb25nPiwgcHLDqXNzZW50aSBhdSBwb3N0ZSBkZSBQREcgZGUgU0ZSIHN1aXRlIGF1IGTDqXBhcnQgcHLDqWNpcGl0w6kgZGUgPHN0cm9uZz5GcmFuY2sgRXNzZXI8L3N0cm9uZz4sIHRlbXBvcmFpcmVtZW50IHJlbXBsYWPDqSBwYXIgPHN0cm9uZz5KZWFuLUJlcm5hcmQgTMOpdnk8L3N0cm9uZz4sIHNpbXVsdGFuw6ltZW50IFByw6lzaWRlbnQgZHUgRGlyZWN0b2lyZSBkZSBWaXZlbmRpLjwvbGk%DQo8bGk%PHN0cm9uZz5UaG9tYXMgTGUgR2FjPC9zdHJvbmc%LCBwcsOpY8OpZGVtbWVudCBkaXJlY3RldXIgZGUgbGEgcmVsYXRpb24gY2xpZW50IDIuMCBjaGV6IE9yYW5nZSwgcmVqb2ludCA8YSBocmVmPSJodHRwOi8vc3ludGhlc2lvLmNvbS9jb3Jwb3JhdGUvZnIvIiB0YXJnZXQ9Il9ibGFuayI%U3ludGhlc2lvPC9hPiwgc3DDqWNpYWxpc3RlIGRlIGwmIzgyMTc7ZS1yw6lwdXRhdGlvbiBldCBkdSBzb2NpYWwtQ1JNLCBlbiB0YW50IHF1ZSBkaXJlY3RldXIgZ8OpbsOpcmFsIEZyYW5jZS48L2xpPg0KPGxpPlNlbG9uIGxlcyBpbmZvcm1hdGlvbiBkdSBKb3VybmFsIGR1IG5ldCw8c3Ryb25nPiBBbnRvaW5lIENsw6ltZW50LCA8L3N0cm9uZz5EaXJlY3RldXIgZ8OpbsOpcmFsIFdlYiBkZSAyMCBNaW51dGVzLCBkb2l0IHF1aXR0ZXIgc2VzIGZvbmN0aW9ucyBhdWpvdXJkJiM4MjE3O2h1aSBwb3VyIHJlam9pbmRyZSA8YSBocmVmPSJodHRwOi8vd3d3Lm5leHRyYWRpb3R2LmNvbS8iIHRhcmdldD0iX2JsYW5rIj5OZXh0IEludGVyYWN0aXZlIE1lZGlhPC9hPiwgZmlsaWFsZSBudW3DqXJpcXVlIGR1IGdyb3VwZSBOZXh0IFJhZGlvIFRWLjwvbGk%DQo8bGk%PHN0cm9uZz5NYXRoaWV1IFF1aWxsw6hyZTwvc3Ryb25nPiBhIHLDqWNlbW1lbnQgcmVqb2ludCBsJiM4MjE3O2FnZW5jZSBkZSBjb21tdW5pY2F0aW9uIGRpZ2l0YWxlIG1hcnNlaWxsYWlzZSA8YSBocmVmPSJodHRwOi8vd3d3LnBlcmZlby5jb20vIiB0YXJnZXQ9Il9ibGFuayI%UGVyZmVvIDwvYT5hdSBwb3N0ZSBkZSBjaGFyZ8OpIGRlIGNvbXB0ZXMuPC9saT4NCjxsaT48c3Ryb25nPkRhdmlkIFNvdXJlbmlhbjwvc3Ryb25nPiwgZXgtRGlyZWN0ZXVyIGTigJlFdHVkZXMgYXUgc2VpbiBkdSBkw6lwYXJ0ZW1lbnQgTWVkaWEsIFRlY2hub2xvZ2llICZhbXA7IEVudGVydGFpbm1lbnQgZGUgSGFycmlzIEludGVyYWN0aXZlLCBhIMOpdMOpIG5vbW3DqSBEaXJlY3RldXIgZGVzIEV0dWRlcyBjaGV6IDxhIGhyZWY9Imh0dHA6Ly9mci55YWhvby5jb20vIiB0YXJnZXQ9Il9ibGFuayI%WWFob28hIEZyYW5jZTwvYT48L2xpPg0KPC91bD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW1vdXZlbWVudHMtZGUtbGEtc2VtYWluZS0xMi02MTA3NC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkxlcyBtb3V2ZW1lbnRzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9sZXMtbW91dmVtZW50cy1kZS1sYS1zZW1haW5lLTEyLTYwNzk1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TGVzIG1vdXZlbWVudHMgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjAxMDkvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbGVzLW1vdXZlbWVudHMtZGUtbGEtc2VtYWluZS05LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TGVzIG1vdXZlbWVudHMgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjA4NzUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5MZXMgbW91dmVtZW50cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2xlcy1tb3V2ZW1lbnRzLWRlLWxhLXNlbWFpbmUtMTItNjExNDEvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KDQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2VuLWRpcmVjdC1kZXMtYWdlbmNlcy1sZXMtbmV3cy1kZS1sYS1zZW1haW5lLTYtNjExNDAvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS02LTYxMTQwLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTQ6MzU6MDQgKzAwMDA8L3B1YkRhdGU%DQoNCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtNYXJrZXRpbmddXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU29jaWFsIE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2J1enptYW5dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQ3JpZXVyIDIuMF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtMQ1BdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGVnXV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTWV0aG9kZSBCZXJuYXJkXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU2ODI8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtCdWRnZXRzLCBjYW1wYWduZXMgd2ViLCBjaGlmZnJlcywgaGlnaC10ZWNoLCBub3V2ZWF1eCBtw6lkaWFzJiM4MjMwOyBSZXRvdXIgc3VyIGzigJlhY3R1YWxpdMOpIGRlIGxhIGNvbW11bmljYXRpb24sIGR1IG1hcmtldGluZyBldCBkZSBsYSBwdWJsaWNpdMOpIGRlIGNldHRlIHNlbWFpbmUuDQpXZWINClNpbW9uIDogbGUgcHJlbWllciBjcmlldXIgcHVibGljIDIuMC4gRW4gc291dmVuaXIgZHUgdGVtcHMgb8O5IGxlcyBjcmlldXJzIHNvbm5haWVudCBsZXVyIGNsb2NoZXR0ZSBwdWlzIHNjYW5kYWllbnQgbGVzIG1vdHMgZGVzIGhhYml0YW50cyBkZXMgYWxlbnRvdXJzLCBNZXJjaSBBbGZyZWQsIGxhIG5ld3NsZXR0ZXIgZMOpZGnDqWUgYXV4IGhvbW1lcyBkdSBncm91cGUgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5CdWRnZXRzLCBjYW1wYWduZXMgd2ViLCBjaGlmZnJlcywgaGlnaC10ZWNoLCBub3V2ZWF1eCBtw6lkaWFzJiM4MjMwOyBSZXRvdXIgc3VyIGzigJlhY3R1YWxpdMOpIGRlIGxhIGNvbW11bmljYXRpb24sIGR1IG1hcmtldGluZyBldCBkZSBsYSBwdWJsaWNpdMOpIGRlIGNldHRlIHNlbWFpbmUuPC9wPg0KPGgyPldlYjwvaDI%DQo8cD48c3Ryb25nPlNpbW9uIDogbGUgcHJlbWllciBjcmlldXIgcHVibGljIDIuMDwvc3Ryb25nPi4gRW4gc291dmVuaXIgZHUgdGVtcHMgb8O5IGxlcyBjcmlldXJzIHNvbm5haWVudCBsZXVyIGNsb2NoZXR0ZSBwdWlzIHNjYW5kYWllbnQgbGVzIG1vdHMgZGVzIGhhYml0YW50cyBkZXMgYWxlbnRvdXJzLCA8YSBocmVmPSJodHRwOi8vbWVyY2lhbGZyZWQuY29tLyIgdGFyZ2V0PSJfYmxhbmsiPk1lcmNpIEFsZnJlZDwvYT4sIGxhIG5ld3NsZXR0ZXIgZMOpZGnDqWUgYXV4IGhvbW1lcyBkdSBncm91cGUgTXkgTGl0dGxlIFBhcmlzLCBvZmZyZSDDoCBzZXMgYWJvbm7DqXMgdW5lIG9ww6lyYXRpb24gw6Agc29uIGltYWdlLCBkw6ljYWzDqWUgZXQgcGxlaW5lIGTigJlodW1vdXIuIEFpbnNpLCBhdWpvdXJkJiM4MjE3O2h1aSDDoCBwYXJ0aXIgZGUgMTdoLCBzdXIgbGEgcGxhY2UgZGUgbOKAmU9ww6lyYSDDoCBQYXJpcywgU2ltb24gZMOpY2xhbWVyYSBsZXMgZMOpY2xhcmF0aW9ucyBk4oCZYW1vdXIgZGVzIHRpbWlkZXMsIGxlcyBjb3VwcyBkZSBndWV1bGUgZGVzIG3DqWNvbnRlbnRzIG91IGVuY29yZSBkZXMgY291cHMgZGUgcHViIGRlcyBjb21tZXLDp2FudHMsIHR3ZWV0w6lzIHN1ciBsZSBoYXNodGFnICNjcmlldXJwdWJsaWMuIElscyBzZXJvbnQgZW5zdWl0ZSBkaWZmdXPDqXMgc3VyIFlvdVR1YmUgcG91ciBsYSBwb3N0w6lyaXTDqS48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL21lcmNpYWxmcmVkLmNvbS9zaW1vbi1jcmlldXItZGUtdHdlZXRzLmh0bWwiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtbWVkaXVtIHdwLWltYWdlLTU1NzA0IiB0aXRsZT0iQ3JpZXVyLXB1YmxpYyAyLjAiIHNyYz0iYXNzZXRzL2ZlZWRzX2ltYWdlcy9DcmlldXItcHVibGljLTIuanBnIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIyNDQiIC8%PC9hPjwvcD4NCjxwPk9yY2hlc3Ryw6llIHBhciBsYSBmYW1ldXNlIGFnZW5jZSA8YSBocmVmPSJodHRwOi8vd3d3LmJ1enptYW4uZnIvIiB0YXJnZXQ9Il9ibGFuayI%QnV6ek1hbjwvYT4sIEF4YSBhIGxhbmPDqSBjZXR0ZSBzZW1haW5lIHVuZSBub3V2ZWxsZSBjYW1wYWduZSBiYXB0aXPDqWUgPHN0cm9uZz48YSBocmVmPSJodHRwOi8vd3d3LnlvdXR1YmUuY29tL2F4YWZyYW5jZWNoYWluZSIgdGFyZ2V0PSJfYmxhbmsiPkxhIE3DqXRob2RlIEJlcm5hcmQ8L2E%PC9zdHJvbmc%LiBDb21wb3PDqSBkZSB0cm9pcyBmaWxtcyB2aXJhdXggZXQgZCYjODIxNzt1bmUgPHNwYW4gaWQ9Im1vcmUtNTU2ODIiPjwvc3Bhbj5hY3RpdmF0aW9uIGRpZ2l0YWxlLCBsZSBkaXNwb3NpdGlmIGEgcG91ciBvYmplY3RpZiBkJiM4MjE3O2FwcHV5ZXIgbGUgbGFuY2VtZW50IGR1IG5vdXZlYXUgc2VydmljZSBkJiM4MjE3O0F4YSBjb250cmUgbGVzIGRhbmdlcnMgZCYjODIxNztJbnRlcm5ldC4gQmFwdGlzw6llIFByb3RlY3Rpb24gZmFtaWxpYWxlIGludMOpZ3JhbGUsIGNldHRlIG9mZnJlIHByb3TDqGdlIGxlcyBjbGllbnRzIGRlcyBhY2NpZGVudHMgbWFpcyBzdXJ0b3V0IGRlcyByaXNxdWVzIGRlIGzigJl1c3VycGF0aW9uIGRlIHZvdHJlIGlkZW50aXTDqSwgZXQgZGVzIGF0dGVpbnRlcyDDoCBs4oCZZS1yw6lwdXRhdGlvbuKApi4gTOKAmWFnZW5jZSBhIG5vdGFtbWVudCBtaXMgZW4gcGxhY2UgPGEgaHJlZj0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9heGFmcmFuY2VjaGFpbmUiIHRhcmdldD0iX2JsYW5rIj51biBzaXRlIGludGVybmV0PC9hPiBxdWkgcGVybWV0IGF1eCBpbnRlcm5hdXRlcyBkZSBwacOpZ2VyIGxldXJzIGFtaXMgZW4gZMOpdG91cm5hbnQgbGV1ciBwcm9maWwgKGF2ZWMgcGhvdG9zLCBub21z4oCmKSBwb3VyIGxlcyBpbmNydXN0ZXIgc3VyIGRlcyBzaXRlcyBwZXUgZmxhdHRldXJzLjwvcD4NCjxwPjxjZW50ZXI%PGlmcmFtZSBzcmM9Imh0dHA6Ly93d3cueW91dHViZS5jb20vZW1iZWQvZ2lhb0dKMld3ZGciIGZyYW1lYm9yZGVyPSIwIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMwOSI%PC9pZnJhbWU%PC9jZW50ZXI%PC9wPg0KPHA%PC9icj5MYSBjaGHDrm5lIHBhcmxlbWVudGFpcmUgYSByw6ljZW1tZW50IG1pcyBlbiBwbGFjZSB1biBkaXNwb3NpdGlmIG9yaWdpbmFsIHF1aSBwZXJtZXQgPHN0cm9uZz5kZSBkw6l0b3VybmVyIGxlcyBhZmZpY2hlcyBkZSBjYW1wYWduZS48L3N0cm9uZz4gTGEgY2hhw65uZSBhIGFpbnNpIGZhaXQgYXBwZWwgw6AgbCYjODIxNzthZ2VuY2UgZGUgY29tbXVuaWNhdGlvbiBDb252ZXJzaW9ubmVsIHBvdXIgZMOpdmVsb3BwZXIgbCYjODIxNzthcHBsaWNhdGlvbiBNQ1AgOiBwb3VyIDxhIGhyZWY9Imh0dHA6Ly9tY3AubGNwLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPm1hIGNhbXBhZ25lIHByw6lzaWRlbnRpZWxsZTwvYT4uIEwmIzgyMTc7YXBwbGljYXRpb24gcGVybWV0IGFpbnNpIGF1eCBpbnRlcm5hdXRlcyBkZSByw6lhbGlzZXIgbGV1ciBwcm9wcmUgYWZmaWNoZSDDqWxlY3RvcmFsZSwgYXZlYyBsZXVyIHByb3ByZSBzbG9nYW4gZGUgY2FtcGFnbmUuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHA6Ly9tY3AubGNwLmZyLyMxOTQiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTcwMCIgdGl0bGU9Ik1DUCIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01DUC5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjI0MiIgLz48L2E%PC9wPg0KPHA%TCYjODIxNzthZ2VuY2UgUGFzc2FnZSBQacOpdG9uIGEgcsOpY2VtbWVudCBsYW5jw6kgbGEgbm91dmVsbGUgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vbXJwcm9wcmUiIHRhcmdldD0iX2JsYW5rIj5wYWdlIEZhY2Vib29rIGRlIE1yIFByb3ByZSA8L2E%cXVpIGFjY3VlaWxsZXJhIGxlIDkgYXZyaWwgcHJvY2hhaW4gdW5lIGFwcGxpY2F0aW9uIGJhcHRpc8OpZSA8c3Ryb25nPiZsYXF1bzsmbmJzcDttw6luYWdlIGRpZ2l0YWwmbmJzcDsmcmFxdW87Ljwvc3Ryb25nPiBMJiM4MjE3O2lkw6llIDogYWlkZXIgbGVzIGludGVybmF1dGVzIMOgIGZhaXJlIGxlIHRyaSBkZSBsZXVycyBhbmNpZW5uZXMgcGhvdG9zIGV0IHBvc3RzIGV0IGJpZW4gY29tcHJlbmRyZSB0b3VzIGxlcyBub3V2ZWF1eCBwYXJhbcOpdHJhZ2VzIGRlIGxhIFRpbWVsaW5lLjwvcD4NCjxwPk9yY2hlc3Ryw6llIHBhciBUQldBXFBBUklTLCBsYSBjYW1wYWduZSA8c3Ryb25nPiZsYXF1bzsmbmJzcDtDb250cmUgbGUgY29tbWVyY2UgaXJyZXNwb25zYWJsZSBkZXMgYXJtZXMmbmJzcDsmcmFxdW87PC9zdHJvbmc%IGQmIzgyMTc7QW1uZXN0eSBJbnRlcm5hdGlvbmFsIEZyYW5jZSBwcm9wb3NlcmEgcGVuZGFudCAxMDAgam91cnMsIHVuZSBjcsOpYXRpb24gb3JpZ2luYWxlIHN1ciA8YSBocmVmPSJodHRwOi8vd3d3LmZhY2Vib29rLmNvbS9BbW5lc3R5QXJtZXMiIHRhcmdldD0iX2JsYW5rIj5sYSBwYWdlIEZhY2Vib29rIGTDqWRpw6llPC9hPi4gQ2VzIDE0IGNyw6lhdGlvbnMgb250IHBvdXIgb2JqZWN0aWYgZGUgcGVybWV0dHJlIGRlIHByZW5kcmUgY29uc2NpZW5jZSBkZXMgYXRyb2NpdMOpcyBlbmdlbmRyw6llcyBwYXIgbGVzIGFybWVzLjwvcD4NCjxwPlBvdXIgY8OpbMOpYnJlciBsZSBsYW5jZW1lbnQgZHUgZmlsbSBUaXRhbmljIGVuIDNEIChzb3J0aWUgcHLDqXZ1ZSBsZSA0IGF2cmlsKSwgTGEgMjB0aCBDZW50dXJ5IEZveCBhIG1pcyBlbiBwbGFjZSBsYSBwcmVtacOocmUgYWR2ZXJ0aXNlciBwYWdlIHNwb25zb3Jpc8OpZSBkYW5zIFNwb3RpZnksIHF1aSBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5kZXMtYW5ub25jZXMgcGVyc29ubmFsaXPDqWVzLiBMZXMgaW50ZXJuYXV0ZXMgcG91cnJvbnQgYWluc2kgY3LDqWVyIGV0IDxzdHJvbmc%ZGV2ZW5pciBsYSBzdGFyIGRlIGxldXIgcHJvcHJlIGJhbmRlLWFubm9uY2UuPC9zdHJvbmc%PC9wPg0KPGhyIC8%DQo8aDI%QnVzaW5lc3M8L2gyPg0KPHA%PGEgaHJlZj0iaHR0cHM6Ly93d3cuZmFjZWJvb2suY29tL2FnZW5jZS5sZWciIHRhcmdldD0iX2JsYW5rIj5MJiM4MjE3O2FnZW5jZSBMZWc8L2E%IGEgYW5ub25jw6kgcXVlIHBvdXIgc2VzIDEwIGFucyBlbGxlIHMmIzgyMTc7b2ZmcmFpdCBsJiM4MjE3O3VuIGRlcyBwbHVzIGJlYXV4IGNhZGVhdXggZCYjODIxNzthbm5pdmVyc2FpcmUmIzgyMzA7IDxzdHJvbmc%bmUgcGx1cyBwYXJ0aWNpcGVyIGF1eCBjb21ww6l0aXRpb25zLjwvc3Ryb25nPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwczovL3d3dy5mYWNlYm9vay5jb20vcGhvdG8ucGhwP2ZiaWQ9MzkwMTgwNjc0MzM5NDk2JmFtcDtzZXQ9YS4yOTEwNTQxMjc1ODU0ODUuNzg3MzQuMjkxMDM3NDUwOTIwNDg2JmFtcDt0eXBlPTEmYW1wO3RoZWF0ZXIiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtbWVkaXVtIHdwLWltYWdlLTU1NzA5IiB0aXRsZT0ibGVnLWltYWdlIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbGVnLWltYWdlLTU1MHgxMTEucG5nIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIxMTEiIC8%PC9hPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%UHJpY2VNaW5pc3RlciBldCBTb0NvbGlzc2ltbyAgb250IHJlbXBvcnRlciA8c3Ryb25nPmxlIEdyYW5kIFByaXggT3IgZHUgQnJhbmQgQ29udGVudDwvc3Ryb25nPiwgY2F0w6lnb3JpZSBDb21tZXJjZSBldCBEaXN0cmlidXRpb24sIGF2ZWMgbCYjODIxNztvcMOpcmF0aW9uIMKrIFBldGl0cyBDYWRlYXV4IGVudHJlIEFtaXMgwrs8L3A%DQo8cD5TZWxvbiBsZXMgaW5mb3JtYXRpb25zIGRlIFN0cmF0w6lnaWVzLCBsYSBtYXJxdWUgZGUganVzIGRlIGZydWl0cyA8YSBocmVmPSJodHRwOi8vd3d3LnRyb3BpY2FuYS5mci8iIHRhcmdldD0iX2JsYW5rIj5Ucm9waWNhbmE8L2E%IGEgZMOpY2lkw6kgJiM4MjExOyBzYW5zIGNvbXDDqXRpdGlvbiAmIzgyMTE7IGRlIGNvbmZpZXIgw6AgPGEgaHJlZj0iaHR0cDovL3d3dy5kZGIuZnIvIiB0YXJnZXQ9Il9ibGFuayI%c29uIGFnZW5jZSBwdWJsaWNpdGFpcmUgRERCIDwvYT5QYXJpcyBsJiM4MjE3O2Vuc2VtYmxlIGRlIHNhIHN0cmF0w6lnaWUgZGlnaXRhbGUsIHF1aSDDqXRhaXQgZ8OpcsOpZSBwYXIgTnVydW4gRnJhbmNlIGRlcHVpcyAyMDEwLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vd3d3LnRyb3BpY2FuYS5mci8jL2NhcnJvdXNlbHByb2R1aXQiPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTcwNyIgdGl0bGU9InRyb3BpY2FuYSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3Ryb3BpY2FuYS5wbmciIGFsdD0iIiB3aWR0aD0iNTA0IiBoZWlnaHQ9IjE4MCIgLz48L2E%PC9wPg0KPHA%VG91am91cnMgc2Vsb24gbGVzIGluZm9ybWF0aW9ucyBkZSBTdHJhdMOpZ2llcywgbGUgbGFib3JhdG9pcmUgcGhhcm1hY2V1dGlxdWUgTm92byBOb3JkaXNrIEZyYW5jZSBhIHJldGVudSBsJiM4MjE3O2FnZW5jZSA8YSBocmVmPSJodHRwOi8vd3d3Lm5ld2JiZG8uZnIvI2hvbWUiIHRhcmdldD0iX2JsYW5rIj5OZXcgQkJETzwvYT4gcG91ciBnw6lyZXIgc29uIGJ1ZGdldCBkZSBjb21tdW5pY2F0aW9uIGRpZ2l0YWxlLjwvcD4NCjxwPjxhIGhyZWY9Imh0dHA6Ly93d3cucGljdGltZS5jb20vMDEwLUFDQ1VFSUwvMDEwLWhvbWUucGhwIiB0YXJnZXQ9Il9ibGFuayI%UGljdGltZSw8L2E%IHNww6ljaWFsaXN0ZSBlbiBjb25zZWlsIGV0IHNvbHV0aW9ucyBlLWNvbW1lcmNlLCBhbm5vbmNlIGxlIGdhaW4gZGUgZGV1eCBub3V2ZWF1eCBidWRnZXRzOiBOb2NpYsOpLCBxdWkgbHVpIGEgY29uZmnDqSBsYSByw6lhbGlzYXRpb24gZGUgc29uIHNpdGUgbW9iaWxlLCBtLm5vY2liZS5mciwgZXQgQnJpY29tYW4sIHF1aSBsdWkgYSBjb25macOpIGxhIHJlZm9udGUgZGUgc29uIHNpdGUgZCYjODIxNztlLWNvbW1lcmNlLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48YSBocmVmPSJodHRwOi8vd3d3LnBpY3RpbWUuY29tLzAxMC1BQ0NVRUlMLzAxMC1ob21lLnBocCI%PGltZyBjbGFzcz0iYWxpZ25jZW50ZXIgc2l6ZS1mdWxsIHdwLWltYWdlLTU1NzA2IiB0aXRsZT0icGljdGltZSIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3BpY3RpbWUucG5nIiBhbHQ9IiIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIxMDgiIC8%PC9hPjwvcD4NCjxwPkdyYW5kT3B0aWNhbCBhIGNob2lzaSBsJiM4MjE3O2FnZW5jZSA8YSBocmVmPSJodHRwOi8vd3d3LnZhbmtzZW4uZnIvIiB0YXJnZXQ9Il9ibGFuayI%VmFua3NlbjwvYT4sIHF1aSBzZXJhIGTDqXNvcm1haXMgZW4gY2hhcmdlIGR1IHNpdGUgPGEgaHJlZj0iaHR0cDovL3d3dy5ncmFuZG9wdGljYWwuY29tLyI%Z3JhbmRvcHRpY2FsLmNvbTwvYT4sIGRvbnQgdW5lIHJlZm9udGUgZXN0IHByw6l2dWUgZW4gYXZyaWwgcHJvY2hhaW4uIEwmIzgyMTc7YWdlbmNlIGF1cmEgw6lnYWxlbWVudCBwb3VyIG1pc3Npb24gZCYjODIxNzthbmltZXIgbGUgc2l0ZSB0b3V0IGF1IGxvbmcgZGUgbCYjODIxNzthbm7DqWUsIGVuIHJlbGF5YW50IGxlcyBjYW1wYWduZXMgZGUgbGEgbWFycXVlIGV0IGVuIGRpZmZ1c2FudCBkZSBub21icmV1eCBhcnRpY2xlcyBhdXRvdXIgZGUgbCYjODIxNztvcHRpcXVlLiBDZXMgaW5mb3JtYXRpb25zIHNlcm9udCByZWxhecOpZXMgc3VyIGxlcyBwcmluY2lwYXV4IG1lZGlhIHNvY2lhdXggZXQgYXV0cmVzIHBsYXRlZm9ybWVzIGNvbGxhYm9yYXRpdmVzLjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZW4tZGlyZWN0LWRlcy1hZ2VuY2VzLWxlcy1uZXdzLWRlLWxhLXNlbWFpbmUtNi02MDg3NC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbiBkaXJlY3QgZGVzIGFnZW5jZXNdIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS02LTYwOTMyLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VuIGRpcmVjdCBkZXMgYWdlbmNlc10gTGVzIG5ld3MgZGUgbGEgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VuLWRpcmVjdC1kZXMtYWdlbmNlcy1sZXMtbmV3cy1kZS1sYS1zZW1haW5lLTUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRW4gZGlyZWN0IGRlcyBhZ2VuY2VzXSBMZXMgbmV3cyBkZSBsYSBzZW1haW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZW4tZGlyZWN0LWRlcy1hZ2VuY2VzLWxlcy1uZXdzLWRlLWxhLXNlbWFpbmVzLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VuIGRpcmVjdCBkZXMgYWdlbmNlc10gIExlcyBuZXdzIGRlIGxhIHNlbWFpbmU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS03LTYwNzA5LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VuIGRpcmVjdCBkZXMgYWdlbmNlc10gTGVzIG5ld3MgZGUgbGEgc2VtYWluZTwvYT48L2xpPjwvdWw%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9lbi1kaXJlY3QtZGVzLWFnZW5jZXMtbGVzLW5ld3MtZGUtbGEtc2VtYWluZS02LTYxMTQwL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjA8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoNCgkJPGl0ZW0%DQoJCTx0aXRsZT5bRXR1ZGVdIE3DqWRpYW3DqXRyaWUgZGVzc2luZSBsZSBwb3J0cmFpdCByb2JvdCBkdSB0YWJsb25hdXRlPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9ldHVkZS1tZWRpYW1ldHJpZS1kZXNzaW5lLWxlLXBvcnRyYWl0LXJvYm90LWR1LXRhYmxvbmF1dGUtNjExMzkvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9ldHVkZS1tZWRpYW1ldHJpZS1kZXNzaW5lLWxlLXBvcnRyYWl0LXJvYm90LWR1LXRhYmxvbmF1dGUtNjExMzkvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxMzoxODoyNCArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KDQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbSW50ZXJuZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTW9iaWxlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2NoaWZmcmVzXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW8OpdHVkZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtpUGFkXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3BvcnRyYWl0XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3RhYmxldHRlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3VzYWdlXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU2NjQ8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtEYW5zIGxlIGNhZHJlIGTigJl1bmUgbWF0aW7DqWUgZGUgcsOpZmxleGlvbiBvcmdhbmlzw6llIHBhciBsZSBHZXN0ZSAoR3JvdXBlbWVudCBkZXMgRWRpdGV1cnMgZGUgY29udGVudXMgZXQgZGUgc2VydmljZXMgZW4gbGlnbmUpLCBNw6lkaWFtw6l0cmllIHMmIzgyMTc7ZXN0IHBlbmNow6kgcG91ciBsYSBwcmVtacOocmUgZm9pcyBzdXIgbGVzIHVzYWdlcyBldCBsZSBwcm9maWwgZGVzIHRhYmxvbmF1dGVzLiBDb21tZSBzb24gbm9tIGwmIzgyMTc7aW5kaXF1ZSwgY2UgbsOpb2xvZ2lzbWUgZMOpc2lnbmUgbGVzIHV0aWxpc2F0ZXVycyBkZSB0YWJsZXR0ZXMsIGF1IG5vbWJyZSBkJiM4MjE3OzEsNyBtaWxsaW9uIGVuIEZyYW5jZSwgZW4gaGF1c3NlIGRlIDIzJSBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbWF0aW5lZS1wcm9zcGVjdGl2ZS1kdS1nZXN0ZS1xdWVsLWZ1dHVyLXBvdXItbGVzLW1lZGlhcy1lbi1saWduZS02MTEzNC8iIHRhcmdldD0iX2JsYW5rIj5EYW5zIGxlIGNhZHJlIGTigJl1bmUgbWF0aW7DqWUgZGUgcsOpZmxleGlvbjwvYT4gb3JnYW5pc8OpZSBwYXIgbGUgR2VzdGUgKEdyb3VwZW1lbnQgZGVzIEVkaXRldXJzIGRlIGNvbnRlbnVzIGV0IGRlIHNlcnZpY2VzIGVuIGxpZ25lKSwgPGEgaHJlZj0iaHR0cDovL3d3dy5tZWRpYW1ldHJpZS5mci8iIHRhcmdldD0iX2JsYW5rIj5Nw6lkaWFtw6l0cmllPC9hPiBzJiM4MjE3O2VzdCBwZW5jaMOpIHBvdXIgbGEgcHJlbWnDqHJlIGZvaXMgc3VyIGxlcyB1c2FnZXMgZXQgbGUgcHJvZmlsIGRlcyB0YWJsb25hdXRlcy4gQ29tbWUgc29uIG5vbSBsJiM4MjE3O2luZGlxdWUsIGNlIG7DqW9sb2dpc21lIGTDqXNpZ25lIGxlcyB1dGlsaXNhdGV1cnMgZGUgdGFibGV0dGVzLCBhdSBub21icmUgZCYjODIxNzsxLDcgbWlsbGlvbiBlbiBGcmFuY2UsIGVuIGhhdXNzZSBkZSAyMyUgZW4gdW4gYW4uIDxhIGhyZWY9Imh0dHA6Ly93d3cubWVkaWFtZXRyaWUuZnIvd2VibWFpbC9kb3dubG9hZC9NZWRpYW1ldHJpZV9QYW5lbFRhYmxldHRlc19Db25mZXJlbmNlR0VTVEUyOTAzMTIucGRmIiB0YXJnZXQ9Il9ibGFuayI%TCYjODIxNzvDqXR1ZGUgPC9hPm1lbsOpZSBwYXIgbCYjODIxNztpbnN0aXR1dCByZXBvc2Ugc3VyIHVuZSBlbnF1w6p0ZSBlZmZlY3R1w6llIGF1cHLDqHMgZCYjODIxNzt1biBwYW5lbCBkZSBwcsOocyBkZSAxMDAwIHV0aWxpc2F0ZXVycyBwcmluY2lwYXV4IGQmIzgyMTc7aVBhZC48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy5tZWRpYW1ldHJpZS5mci93ZWJtYWlsL2Rvd25sb2FkL01lZGlhbWV0cmllX1BhbmVsVGFibGV0dGVzX0NvbmZlcmVuY2VHRVNURTI5MDMxMi5wZGYiPjxpbWcgY2xhc3M9InNpemUtZnVsbCB3cC1pbWFnZS01NTY3MSBhbGlnbmNlbnRlciIgdGl0bGU9Im1lZGlhbWV0cmllIiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvbWVkaWFtZXRyaWUyLmpwZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjM0IiAvPjwvYT48L3A%DQo8cD5TZWxvbiBsZXMgcHJlbWllcnMgcsOpc3VsdGF0cyBkZSBsJiM4MjE3O8OpdHVkZSwgbGUgdGFibG9uYXV0ZSBlc3QgZG9uYyA6IHVuIGhvbW1lICg2OCUpIHVyYmFpbiAoNTklKSBhcHBhcnRlbmFudCBhdXggQ1NQKyAoNTMlKSBldCA8c3BhbiBpZD0ibW9yZS01NTY2NCI%PC9zcGFuPmF5YW50IGVudHJlIDM1IGV0IDQ5IGFucyAoMzMlKS48L3A%DQo8cD5Gb3J0IGRlIGNlcyBkb25uw6llcywgbCYjODIxNzvDqXR1ZGUgYSBlbnN1aXRlIHBvaW50w6kgZHUgZG9pZ3QgbGVzIHByaW5jaXBhbGVzIGRpZmbDqXJlbmNlcyBxdWkgZGlzdGluZ3VlbnQgbGUgcHJvZmlsIGQmIzgyMTc7dW4gbW9iaW5hdXRlIGV0IGNlbHVpIGQmIzgyMTc7dW4gdGFibG9uYXV0ZS4gTCYjODIxNztlbnF1w6p0ZSBzb3VsaWduZSBhaW5zaSB1bmUgbGFyZ2Ugc3VycmVwcsOpc2VudGF0aW9uIGRlcyBob21tZXMgcGFybWkgbGVzIHRhYmxvbmF1dGVzICg3MCUgY29udHJlIDU3JSBkZSBtb2JpbmF1dGVzKS4gTGVzIHV0aWxpc2F0ZXVycyBkZSB0YWJsZXR0ZSBzb250IMOpZ2FsZW1lbnQgcGx1cyDDomfDqXMgOiAzMCUgZCYjODIxNztlbnRyZSBldXggb250IGVudHJlIDM1IGV0IDQ5IGFucywgY29udHJlIDI0JSBkZXMgbW9iaW5hdXRlcy4gTGVzIHRhYmxvbmF1dGVzIGFwcGFydGllbm5lbnQgw6lnYWxlbWVudCBkJiM4MjE3O2F2YW50YWdlIGF1eCBDU1ArICAoNDclIGNvbnRyZSAzNCUgcG91ciBsZXMgbW9iaW5hdXRlcykuIEVuZmluLCBsYSBjb25jZW50cmF0aW9uIGRlcyB0YWJsb25hdXRlcyAoMzAlKSBlbiByw6lnaW9uIHBhcmlzaWVubmUgc2UgcsOpdsOobGUgYmVhdWNvdXAgcGx1cyBtYXJxdcOpZSBxdWUgcG91ciBsZXMgdXRpbGlzYXRldXJzIGRlIHNtYXJ0cGhvbmVzICgyNSUpLjwvcD4NCjxwPlBhcm1pIGxlcyBhdXRyZXMgZW5zZWlnbmVtZW50cyDDoCByZXRlbmlyLCBsJiM4MjE3O2VucXXDqnRlIG1vbnRyZSDDoCBxdWVsIHBvaW50ICZsYXF1bzsmbmJzcDtsYSBjb25zb21tYXRpb24mbmJzcDsmcmFxdW87IGRlcyB0YWJsZXR0ZSBlc3Qgc8OpZGVudGFpcmUuIEVuIGVmZmV0LCBsJiM4MjE3O3V0aWxpc2F0aW9uIGRlIGwmIzgyMTc7aVBhZCBzZSBmYWl0IGVzc2VudGllbGxlbWVudCDDoCBkb21pY2lsZSAoOTIlKS4gTG9pbiBkZXJyacOocmUsIGwmIzgyMTc7dXNhZ2Ugc3VyIGxlcyBsaWV1eCBkZSB0cmF2YWlsIGFycml2ZSBlbiBzZWNvbmRlIHBvc2l0aW9uICgyNSUpLiBBdXRyZSBjYXJhY3TDqXJpc3RpcXVlIDogbCYjODIxNzt1c2FnZSBkJiM4MjE3O3VuIGlQYWQgZXN0IGJlYXVjb3VwIG1vaW5zIGV4Y2x1c2lmIHF1JiM4MjE3O3VuIHNtYXJ0cGhvbmUgOiAzMyUgZGVzIHV0aWxpc2F0ZXVycyBwcmluY2lwYXV4IGTDqWNsYXJlbnQgcXUmIzgyMTc7YXUgc2VpbiBkJiM4MjE3O3VuIG3Dqm1lIGZveWVyIGRldXggcGVyc29ubmVzIHV0aWxpc2VudCB1bmUgdW5pcXVlIHRhYmxldHRlLiBEYW5zIDI0JSBkZXMgY2FzLCBsJiM4MjE3O3V0aWxpc2F0aW9uIGRlIGxhIHRhYmxldHRlIGNvbmNlcm5lcmFpdCBhdSBtb2lucyAzIHBlcnNvbm5lcy4gTCYjODIxNzvDqXR1ZGUgcyYjODIxNztlc3QgZW5maW4gaW50w6lyZXNzw6llIMOgIGxhIGpvdXJuw6llIHR5cGUgZGVzIHRhYmxvbmF1dGVzIGV0IG1vbnRyZSBhaW5zaSBxdWUgbGEgbWFqb3JpdMOpIGRlcyB1dGlsaXNhdGV1cnMgZCYjODIxNztpUGFkICg2NSUpIHN1cmZlbnQgc3VyIGxldXIgdGFibGV0dGUgZW50cmUgMTdoIGV0IDIxaC48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V0dWRlLWxlcy10YWJsZXR0ZXMtbW9pbnMtbXVsdGl0YWNoZXMtcXVlLWxlcy1zbWFydHBob25lcy01MDQwMi8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFdHVkZV0gTGVzIHRhYmxldHRlcyBtb2lucyBtdWx0aXTDomNoZXMgcXVlIGxlcyBzbWFydHBob25lczwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2NoaWZmcmVzLWxhLXZvZC1hdHRpcmUtcGx1cy11bi1pbnRlcm5hdXRlLXN1ci01LTYwMDY1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0NoaWZmcmVzXSBMYSBWT0QgYXR0aXJlIGTDqXNvcm1haXMgcGx1cyBkJiM4MjE3O3VuIGludGVybmF1dGUgZnJhbsOnYWlzIHN1ciA1PC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXR1ZGUtbGVzLWZyYW5jYWlzLWFjY3Jvcy1hdXgtdGFibGV0dGVzLTUwMDE1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0V0dWRlXSBMZXMgRnJhbsOnYWlzIGFjY3JvcyBhdXggdGFibGV0dGVzITwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2NoaWZmcmVzLWF1ZGllbmNlLWRlLWludGVybmV0LW1vYmlsZS1hdS00ZW1lLXRyaW1lc3RyZS0yMDExLTYwMjU1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0NoaWZmcmVzXSBMJiM4MjE3O2F1ZGllbmNlIGRlIGwmIzgyMTc7aW50ZXJuZXQgbW9iaWxlIGF1IDTDqG1lIHRyaW1lc3RyZSAyMDExPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXR1ZGUtbGVzLWhvbW1lcy1ldC1sZXMtZmVtbWVzLXN1ci1sZS13ZWItbW9kZS1lbXBsb2ktNTAzMTIvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRXR1ZGVdIExlcyBob21tZXMgZXQgbGVzIGZlbW1lcyBzdXIgbGUgd2ViIDogbGUgbW9kZSBkJiM4MjE3O2VtcGxvaTwvYT48L2xpPjwvdWw%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9ldHVkZS1tZWRpYW1ldHJpZS1kZXNzaW5lLWxlLXBvcnRyYWl0LXJvYm90LWR1LXRhYmxvbmF1dGUtNjExMzkvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoNCgkJPHRpdGxlPltEb3NzaWVyXSBMZSBjYXMgTGlua2VvbCAvIExpbmtlZGluLCBvdSBsZXMgZW5qZXV4IGR1IG5hbWluZzwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZG9zc2llci1sZS1jYXMtbGlua2VvbC1saW5rZWRpbi1vdS1sZXMtZW5qZXV4LWR1LW5hbWluZy02MTEzOC88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2Rvc3NpZXItbGUtY2FzLWxpbmtlb2wtbGlua2VkaW4tb3UtbGVzLWVuamV1eC1kdS1uYW1pbmctNjExMzgvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxMjoxODowNyArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%TWFyaW9uIE1vcmVhdTwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYnVzaW5lc3NdXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtTb2NpYWwgTWVkaWFdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU3RhcnR1cF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtWaWRlb11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtncmFucnV0XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2xpbmtlZGluXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0xpbmtlb2xdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9tZW5dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbdW5lXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTUyNjA8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtMZSBnw6lhbnQgYW3DqXJpY2FpbiBkZW1hbmRlIMOgIGxhIHN0YXJ0LXVwIGZyYW7Dp2Fpc2UgZGUgcmV0aXJlciBzYSBtYXJxdWUgZXQgbGVzIG5vbXMgZGUgZG9tYWluZXMgYXNzb2Npw6lzLiBGcmVuY2hXZWIgb3V2cmUgbGUgZG9zc2llciBkdSBuYW1pbmcgYXZlYyAzIGVudHJldGllbnMgcG91ciBjb21wcmVuZHJlIGxlcyBlbmpldXggZXQgYmVzdCBwcmFjdGljZXMuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%QSBsJiM4MjE3O29yaWdpbmUgZGUgY2UgZG9zc2llciBvdXZlcnQgcGFyIEZyZW5jaFdlYiwgdW4gY291cnJpZXIgZHUgY2FiaW5ldCBkJiM4MjE3O2F2b2NhdHMgcGFyaXNpZW4gPGEgaHJlZj0iaHR0cDovL3d3dy5rb3BhY3otcGFyaXMuZnIvIiB0YXJnZXQ9Il9ibGFuayI%TGF3IE9mZmljZXMgS29wYWN6PC9hPiwgcmVwcsOpc2VudGFudCBlbiBGcmFuY2UgZHUgcsOpc2VhdSBzb2NpYWwgcHJvZmVzc2lvbm5lbCBhbcOpcmljYWluIExpbmtlZEluLCDDoCBkZXN0aW5hdGlvbiBkZSBHaWxsZXMgRHVsdWNxLCBQcsOpc2lkZW50LUZvbmRhdGV1ciBkZSBMaW5rZW9sLCBwbGF0ZWZvcm1lIHJlbGF0aW9ubmVsbGUgZW50cmUgcG9ydGV1cnMgZGUgcHJvamV0cyBldCBleHBlcnRzLiBMaW5rZWRJbiBkZW1hbmRlIMOgIExpbmtlb2wgZGUgcmV0aXJlciBzYSBtYXJxdWUgZXQgbGVzIG5vbXMgZGUgZG9tYWluZXMgYXNzb2Npw6lzLCBhdSBtb3RpZnMgcXUmIzgyMTc7aWwgeSBhdXJhaXQgc2ltaWxpdHVkZSBlbnRyZSBsZXMgZGV1eCBtYXJxdWVzIGV0IHF1ZSBMaW5rZW9sICZsYXF1bzsmbmJzcDtjb3V2cmUgZGVzIHNlcnZpY2VzIGlkZW50aXF1ZXMmbmJzcDsmcmFxdW87LjwvcD4NCjxwPjxpbWcgY2xhc3M9ImFsaWducmlnaHQgIHdwLWltYWdlLTU1NjU2IiB0aXRsZT0iR2lsbGVzLWR1bHVjcS1MaW5rZW9sIiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvR2lsbGVzLWR1bHVjcS1MaW5rZW9sLmpwZyIgYWx0PSIiIHdpZHRoPSIxMjYiIGhlaWdodD0iMTI2IiAvPlZvaWNpIHRyb2lzIHRyb2lzIGVudHJldGllbnMgcG91ciBjb21wcmVuZHJlIGxlcyBlbmpldXggcHJvcHJlcyDDoCBjZSBjYXMgZXQgw6lsYXJnaXIgbGUgZMOpYmF0IGF1eCBiZXN0IHByYWN0aWNlcyBldCBwcsOpY2F1dGlvbnMgw6AgcHJlbmRyZSBlbiBtYXRpw6hyZSBkZSBuYW1pbmcgZGVzIHN0YXJ0dXBzIDogPHN0cm9uZz5HaWxsZXMgRHVsdWNxIGRlIDxhIGhyZWY9Imh0dHA6Ly93d3cubGlua2VvbC5mci8iIHRhcmdldD0iX2JsYW5rIj5MaW5rZW9sPC9hPiwgTWHDrnRyZSBSaWNoYXJkIE1pbGNoaW9yIGR1IGNhYmluZXQgPGEgaHJlZj0iaHR0cDovL3d3dy5ncmFucnV0LmNvbS8tQWNjdWVpbC0uaHRtbCIgdGFyZ2V0PSJfYmxhbmsiPkdyYW5ydXQgQXZvY2F0cyA8L2E%ZXQgTWFyY2VsIEJvdHRvbiwgZm9uZGF0ZXVyIGRlIDxhIGhyZWY9Imh0dHA6Ly93d3cubm9tZW4uY29tLyIgdGFyZ2V0PSJfYmxhbmsiPk5vbWVuPC9hPi48L3N0cm9uZz48L3A%DQo8cD48c3Ryb25nPkdpbGxlcyBEdWx1Y3E8L3N0cm9uZz4gZMOpdGFpbGxlIGxlICZsYXF1bzsmbmJzcDtkb3NzaWVyIExpbmtlZEluJm5ic3A7JnJhcXVvOyBldCBsZXMgcmFpc29ucyBwb3VyIGxlc3F1ZWxsZXMgaWwgZXN0aW1lIHF1ZSBMaW5rZW9sLCBsYW5jw6kgZmluIDIwMSwgbiYjODIxNztlbnRyZSBwYXMgZW4gJmxhcXVvOyZuYnNwO2NvbmN1cnJlbmNlJm5ic3A7JnJhcXVvOyBhdmVjIGxlIGfDqWFudCBhbcOpcmljYWluLjwvcD4NCjxwPjxjZW50ZXI%PGlmcmFtZSBzcmM9Imh0dHA6Ly93d3cuZGFpbHltb3Rpb24uY29tL2VtYmVkL3ZpZGVvL3hwcDc3dSIgZnJhbWVib3JkZXI9IjAiIHdpZHRoPSI1NTAiIGhlaWdodD0iMzA5Ij48L2lmcmFtZT48L2NlbnRlcj48YnIgLz4NCjxzdHJvbmc%TWHDrnRyZSBSaWNoYXJkIE1pbGNoaW9yPC9zdHJvbmc%IGR1IGNhYmluZXQgR3JhbnJ1dCBBdm9jYXQsIGNvbnN1bHRhbnQgcsOpZ3VsaWVyIGRlIEZyZW5jaFdlYiwgw6l2b3F1ZSBsZXMgY29uZGl0aW9ucyBkZSByZWNldmFiaWxpdMOpIGRlIGxhIGRlbWFuZGUgZGUgTGlua2VkSW4gZXQgbGVzIHByw6ljYXV0aW9ucyDDoCBwcmVuZHJlIGxvcnNxdSYjODIxNztvbiBjcsOpw6kgdW5lIHN0YXJ0LXVwLjwvcD4NCjxwPjxjZW50ZXI%PCEtLSBkZWdyYWRhYmxlIGh0bWw1IGF1ZGlvIGFuZCB2aWRlbyBwbHVnaW4gLS0%PGRpdiBjbGFzcz0iYXVkaW9fd3JhcCBodG1sNWF1ZGlvIj48ZGl2IHN0eWxlPSJkaXNwbGF5Om5vbmU7Ij48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01pbGNoaW9yLUxpbmtlZGluLWxpbmtlb2wubXAzIiB0aXRsZT0iQ2xpY2sgdG8gb3BlbiIgaWQ9ImYtaHRtbDVhdWRpby0wIj5BdWRpbyBNUDM8L2E%PHNjcmlwdCB0eXBlPSJ0ZXh0L2phdmFzY3JpcHQiPkF1ZGlvUGxheWVyLmVtYmVkKCJmLWh0bWw1YXVkaW8tMCIsIHtzb3VuZEZpbGU6ICJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01pbGNoaW9yLUxpbmtlZGluLWxpbmtlb2wubXAzIn0pOzwvc2NyaXB0PjwvZGl2PjxhdWRpbyBjb250cm9scyBhdXRvYnVmZmVyIGlkPSJodG1sNWF1ZGlvLTAiIGNsYXNzPSJodG1sNWF1ZGlvIj48c291cmNlIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9NaWxjaGlvci1MaW5rZWRpbi1saW5rZW9sLm1wMyIgdHlwZT0iYXVkaW8vbXBlZyIgLz48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01pbGNoaW9yLUxpbmtlZGluLWxpbmtlb2wubXAzIiB0aXRsZT0iQ2xpY2sgdG8gb3BlbiIgaWQ9ImYtaHRtbDVhdWRpby0wIj5BdWRpbyBNUDM8L2E%PHNjcmlwdCB0eXBlPSJ0ZXh0L2phdmFzY3JpcHQiPkF1ZGlvUGxheWVyLmVtYmVkKCJmLWh0bWw1YXVkaW8tMCIsIHtzb3VuZEZpbGU6ICJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01pbGNoaW9yLUxpbmtlZGluLWxpbmtlb2wubXAzIn0pOzwvc2NyaXB0PjwvYXVkaW8%PC9kaXY%PHNjcmlwdCB0eXBlPSJ0ZXh0L2phdmFzY3JpcHQiPmlmIChqUXVlcnkuYnJvd3Nlci5tb3ppbGxhKSB7dGVtcGF1ZD1kb2N1bWVudC5nZXRFbGVtZW50c0J5VGFnTmFtZSgiYXVkaW8iKVswXTsgalF1ZXJ5KHRlbXBhdWQpLnJlbW92ZSgpOyBqUXVlcnkoImRpdi5hdWRpb193cmFwIGRpdiIpLnNob3coKX0gZWxzZSBqUXVlcnkoImRpdi5hdWRpb193cmFwIGRpdiAqIikucmVtb3ZlKCk7PC9zY3JpcHQ%PC9jZW50ZXI%Jm5ic3A7PC9wPg0KPHA%PGEgaHJlZj0iaHR0cDovL3d3dy5ub21lbi5jb20vZnJhbmNhaXMvbm9tZW4tbWFycXVlcy5odG1sIiB0YXJnZXQ9Il9ibGFuayI%Tm9tZW4gSW50ZXJuYXRpb25hbDwvYT4sIGNyw6nDqSBwYXIgPHN0cm9uZz5NYXJjZWwgQm90dG9uPC9zdHJvbmc%IGVuIDE5ODEgZXN0IGF1am91cmQmIzgyMTc7aHVpIHVuIGRlcyBsZWFkZXJzIGRhbnMgbGEgY3LDqWF0aW9uIGRlIG5vbXMgZGUgbWFycXVlcyBldCBkZSBwcm9kdWl0cy4gTm9tZW4gYSBhaW5zaSB0cm91dsOpIHBsdXMgZGUgMTUwMCBub21zLCBjZXJ0YWlucyB0csOocyBjw6lsw6hicmVzIDogUMO0bGUgRW1wbG9pLCBBcmV2YSwgV2FuYWRvbywgUHJpY2VNaW5pc3RlciYjODIzMDsgTWFyY2VsIEJvdHRvbiwgZXhwZXJ0IGV0IHBhc3Npb25uw6kgZGUgbGluZ3Vpc3RpcXVlIGV0IGQmIzgyMTc7w6ljb25vbWllLCBsaXZyZSBxdWVscXVlcyBwZXRpdHMgc2VjcmV0cyBwb3VyIMOpdml0ZXIgbGVzIHBpw6hnZXMgZXQgcyYjODIxNztpbXBvc2VyIHN1ciBzb24gbWFyY2jDqS48L3A%DQo8cD48Y2VudGVyPjxpZnJhbWUgc3JjPSJodHRwOi8vd3d3LmRhaWx5bW90aW9uLmNvbS9lbWJlZC92aWRlby9rNEo2YmhVSGpnNWlRMTJWNVpuIiBmcmFtZWJvcmRlcj0iMCIgd2lkdGg9IjU1MCIgaGVpZ2h0PSIzMDkiPjwvaWZyYW1lPjwvY2VudGVyPjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvcmVzZWF1eC1zb2NpYXV4LXByby1sYW5jZW1lbnQtYXVqb3VyZGh1aS1kZS1tdXhpLWV0LWxpbmtlb2wtNTA2OTAvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bUsOpc2VhdXggc29jaWF1eCBwcm9dIExhbmNlbWVudCBhdWpvdXJkJiM4MjE3O2h1aSBkZSBNdXhpIGV0IExpbmtlb2w8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9oYXVzc2UtdHZhLW1vYmlsZXMtbG9pLWVmZmV0cy1hdWJhaW5lLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%SGF1c3NlIGRlIGxhIFRWQSBzdXIgbW9iaWxlcywgbGEgbG9pIGV0IGxlcyBlZmZldHMgZCYjODIxNzthdWJhaW5lPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvaWRlZXMtMjAxMi1sZS1kZWJyaWVmLXBhci1naWxsZXMtYmFiaW5ldC1wcmVzaWRlbnQtZHUtY25udW0tNjA5NDEvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bSWTDqWVzIDIwMTJdIExlIERlYnJpZWYsIHBhciBHaWxsZXMgQmFiaW5ldCwgcHLDqXNpZGVudCBkdSBDTk51bTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2lkZWVzLTIwMTItbGUtZGVicmllZi1wYXItZ2lsbGVzLWJhYmluZXQtcHJlc2lkZW50LWR1LWNubnVtLTYwODM0LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0lkw6llcyAyMDEyXSBMZSBEZWJyaWVmLCBwYXIgR2lsbGVzIEJhYmluZXQsIHByw6lzaWRlbnQgZHUgQ05OdW08L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9pZGVlcy0yMDEyLWxlLWRlYnJpZWYtYXZlYy1naWxsZXMtYmFiaW5ldC1wcmVzaWRlbnQtZHUtY25uLTYwMjgyLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0lkw6llcyAyMDEyXSBMZSBEZWJyaWVmLCBhdmVjIEdpbGxlcyBCYWJpbmV0LCBwcsOpc2lkZW50IGR1IENOTjwvYT48L2xpPjwvdWw%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9kb3NzaWVyLWxlLWNhcy1saW5rZW9sLWxpbmtlZGluLW91LWxlcy1lbmpldXgtZHUtbmFtaW5nLTYxMTM4L2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjI8L3NsYXNoOmNvbW1lbnRzPg0KPGVuY2xvc3VyZSB1cmw9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWlsY2hpb3ItTGlua2VkaW4tbGlua2VvbC5tcDMiIGxlbmd0aD0iNjM1MzMxNSIgdHlwZT0iYXVkaW8vbXBlZyIgLz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCg0KCQk8dGl0bGU%RHJvcEdpZnRzLFRvdXNjb3Byb2QsIE1haXNvbiAmYW1wOyBEw6ljbywgU21hcnRBbmdlbHMmIzgyMzA7IFpvb20gc3VyIDYgbm91dmVhdXTDqXM8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2Ryb3BnaWZ0c3RvdXNjb3Byb2QtbWFpc29uLWRlY28tc21hcnRhbmdlbHMtem9vbS1zdXItNi1ub3V2ZWF1dGVzLTYxMTM3LzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZHJvcGdpZnRzdG91c2NvcHJvZC1tYWlzb24tZGVjby1zbWFydGFuZ2Vscy16b29tLXN1ci02LW5vdXZlYXV0ZXMtNjExMzcvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxMDoxMzo1MSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KDQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQWxsb1ZldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtEcm9wR2lmdHNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbR29vZ2xlIMOpbGVjdGlvbnNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTWFpc29uICYgRMOpY29dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU21hcnRBbmdlbHNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbVG91c2NvcHJvZF1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NTc5PC9ndWlkPg0KDQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtTbWFydEFuZ2VscywgRHJvcEdpZnRzLCBUb3VzY29wcm9kLCBNYWlzb24gJiMzODsgRMOpY28sIEdvb2dsZSDDqWxlY3Rpb25zLCBBbGxvVmV0JiM4MjMwOyBab29tIHN1ciBzaXggbm91dmVsbGVzIHBsYXRlZm9ybWVzLg0KDQpTbWFydEFuZ2VscyA6IG5vdXZlbGxlIHBsYXRlZm9ybWUgZCYjODIxNztpbnZlc3Rpc3NlbWVudHMgZMOpZGnDqWUgYXV4IFBNRQ0KQ3LDqcOpZSBlbiBzZXB0ZW1icmUgMjAxMSBwYXIgQmVub8OudCBCYXp6YW9jY2hpLCBTbWFydEFuZ2Vscy5mciBlc3QgdW5lIG5vdXZlbGxlIHBsYXRlZm9ybWUgZW4gbGlnbmUgc3VyIGxhcXVlbGxlIGxlcyBwYXJ0aWN1bGllcnMgcGV1dmVudCBpbnZlc3RpciBkaXJlY3RlbWVudCBhdSBjYXBpdGFsIGRlIFBNRS4gT2ZmcmFudCB1bmUgc29sdXRpb24gZGUgZ2VzdGlvbiBkZSBwYXRyaW1vaW5lIGF1eCBwYXJ0aWN1bGllcnMsIFNtYXJ0QW5nZWxzIFsuLi5dXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGEgaHJlZj0iaHR0cHM6Ly93d3cuc21hcnRhbmdlbHMuZnIvaG9tZXBhZ2UiIHRhcmdldD0iX2JsYW5rIj5TbWFydEFuZ2VsczwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cuZHJvcGdpZnRzLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPkRyb3BHaWZ0czwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cudG91c2NvcHJvZC5jb20vIiB0YXJnZXQ9Il9ibGFuayI%VG91c2NvcHJvZDwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cubWFpc29uLWRlY28uY29tLyIgdGFyZ2V0PSJfYmxhbmsiPk1haXNvbiAmYW1wOyBEw6ljbzwvYT4sIDxhIGhyZWY9Imh0dHA6Ly93d3cuZ29vZ2xlLmZyL2VsZWN0aW9ucy9lZC9mciIgdGFyZ2V0PSJfYmxhbmsiPkdvb2dsZSDDqWxlY3Rpb25zPC9hPiwgPGEgaHJlZj0iaHR0cDovL2FsbG92ZXQuY29tLyIgdGFyZ2V0PSJfYmxhbmsiPkFsbG9WZXQ8L2E%JiM4MjMwOyBab29tIHN1ciBzaXggbm91dmVsbGVzIHBsYXRlZm9ybWVzLjwvcD4NCjxwPjxpbWcgdGl0bGU9Im5vdXZlYXV4LXNpdGVzIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvbm91dmVhdXgtc2l0ZXMucG5nIiBhbHQ9IiIgd2lkdGg9IjE0OSIgaGVpZ2h0PSIzMCIgLz48L3A%DQo8aDI%U21hcnRBbmdlbHMgOiBub3V2ZWxsZSBwbGF0ZWZvcm1lIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnRzIGTDqWRpw6llIGF1eCBQTUU8L2gyPg0KPHA%Q3LDqcOpZSBlbiBzZXB0ZW1icmUgMjAxMSBwYXIgQmVub8OudCBCYXp6YW9jY2hpLCA8YSBocmVmPSJodHRwczovL3d3dy5zbWFydGFuZ2Vscy5mci9ob21lcGFnZSIgdGFyZ2V0PSJfYmxhbmsiPlNtYXJ0QW5nZWxzLmZyPC9hPiBlc3QgdW5lIG5vdXZlbGxlIHBsYXRlZm9ybWUgZW4gbGlnbmUgc3VyIGxhcXVlbGxlIGxlcyBwYXJ0aWN1bGllcnMgcGV1dmVudCBpbnZlc3RpciBkaXJlY3RlbWVudCBhdSBjYXBpdGFsIGRlIFBNRS4gT2ZmcmFudCB1bmUgc29sdXRpb24gZGUgZ2VzdGlvbiBkZSBwYXRyaW1vaW5lIGF1eCBwYXJ0aWN1bGllcnMsIFNtYXJ0QW5nZWxzIHByb3Bvc2UgZG9uYyBhdXggZW50cmVwcmlzZXMgZGUgbGV2ZXIgZGVzIGZvbmRzIHZpYSBkZXMgaW52ZXN0aXNzZW1lbnRzIHByaXbDqXMgcG91ciBmaW5hbmNlciBsZXVyIGNyb2lzc2FuY2UuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHBzOi8vd3d3LnNtYXJ0YW5nZWxzLmZyL2hvbWVwYWdlIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1ODkiIHRpdGxlPSJzbWFydGFuZ2VscyIgc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL3NtYXJ0YW5nZWxzLnBuZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMTYxIiAvPjwvYT48L3A%DQo8aHIgLz4NCjxoMj5Ecm9wZ2lmdHMgOiBRdWFuZCBsZXMgY2FydGVzIGNhZGVhdXggZGV2aWVubmVudCB2aXJhbGVzPC9oMj4NCjxwPjxhIGhyZWY9Imh0dHA6Ly93d3cuZHJvcGdpZnRzLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPkRyb3BHaWZ0czwvYT4sIHNww6ljaWFsaXN0ZSBkdSBzb2NpYWwgZ2lmdGluZywgdmllbnQgZCYjODIxNzthcnJpdmVyIGVuIDxzcGFuIGlkPSJtb3JlLTU1NTc5Ij48L3NwYW4%RnJhbmNlLiBQcsOpc2VudGUgZGFucyAzMCBwYXlzLCBsYSBwbGF0ZWZvcm1lIHByb3Bvc2UgYXV4IG1hcnF1ZXMgZGUgZGlzdHJpYnVlciBsZXVycyBjYXJ0ZXMgY2FkZWF1eCB2aWEgRmFjZWJvb2ssIGVuIGludml0YW50IGxlcyDCqyBhbWlzIMK7IMOgIHNlIGxlcyBvZmZyaXIgZW50cmUgZXV4LiBVbmUgZm9pcyBsYSBjYXJ0ZSBlbnZvecOpZSBzdXIgbGUgbXVyIEZhY2Vib29rIGR1IGRlc3RpbmF0YWlyZSwgZXQgZG9uYyB2dWUgcGFyIGzigJllbnNlbWJsZSBkZSBzZXMgYW1pcywgY2VzIGRlcm5pZXJzIHBldXZlbnQgeSBjb250cmlidWVyIGV0IGF1Z21lbnRlciBhaW5zaSBzYSB2YWxldXIuIFBhcm1pIGxhIHRyZW50YWluZSBkZSBwYXJ0ZW5haXJlcyBhdSBsYW5jZW1lbnQsIG9uIHJldHJvdXZlIDogQW1hem9uLCBHYXVtb250IFBhdGjDqSwgS3VzbWkgVGVhLCBNaWNyb21hbmlhLCBUb3lzICZsYXF1bzsmbmJzcDtSJm5ic3A7JnJhcXVvOyBVcywgVXJiYW4gT3V0Zml0dGVycywgWWVsbG93S29ybmVyLCBaYWxhbmRv4oCmIERyb3BnaWZ0cyBlc3QgZGlzcG9uaWJsZSBzdXIgPGEgaHJlZj0iaHR0cDovL2l0dW5lcy5hcHBsZS5jb20vZnIvYXBwL2Ryb3BnaWZ0cy9pZDUwODExMzgxNz9tdD04IiB0YXJnZXQ9Il9ibGFuayI%bCYjODIxNztBcHAgU3RvcmU8L2E%IGV0IHN1ciA8YSBocmVmPSJodHRwczovL3d3dy5mYWNlYm9vay5jb20vZGlhbG9nL29hdXRoP2NsaWVudF9pZD0yODA2NTM2NTg2NTQ0MjQmYW1wO3JlZGlyZWN0X3VyaT1odHRwJTNBJTJGJTJGd3d3LmRyb3BnaWZ0cy5mciUyRmF1dGglMkZsb2dpbiUyRiZhbXA7c3RhdGU9ZDYxMWFiOWVjMWJkYjkxYzA4ODQ2OWZjZDk0OTk4ZDMmYW1wO3Njb3BlPXB1Ymxpc2hfc3RyZWFtJTJDdXNlcl9iaXJ0aGRheSUyQ2ZyaWVuZHNfYmlydGhkYXklMkN1c2VyX2xvY2F0aW9uJTJDZnJpZW5kc19sb2NhdGlvbiUyQ3VzZXJfcmVsYXRpb25zaGlwcyUyQ2ZyaWVuZHNfcmVsYXRpb25zaGlwcyUyQ3VzZXJfcmVsYXRpb25zaGlwX2RldGFpbHMlMkNmcmllbmRzX3JlbGF0aW9uc2hpcF9kZXRhaWxzJTJDdXNlcl9ob21ldG93biUyQ2ZyaWVuZHNfaG9tZXRvd24lMkNvZmZsaW5lX2FjY2VzcyUyQ2VtYWlsIiB0YXJnZXQ9Il9ibGFuayI%RmFjZWJvb2suIDwvYT48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL2l0dW5lcy5hcHBsZS5jb20vZnIvYXBwL2Ryb3BnaWZ0cy9pZDUwODExMzgxNz9tdD04Ij48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLW1lZGl1bSB3cC1pbWFnZS01NTYyMSIgdGl0bGU9ImRyb3BnaWZ0cy0yIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvZHJvcGdpZnRzLTItNTUweDIwNS5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjIwNSIgLz48L2E%PC9wPg0KPGhyIC8%PC9kaXY%XV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9kcm9wZ2lmdHN0b3VzY29wcm9kLW1haXNvbi1kZWNvLXNtYXJ0YW5nZWxzLXpvb20tc3VyLTYtbm91dmVhdXRlcy02MTEzNy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltDaHJvbmlxdWVdIERpZ2l0YWwgTXVzaWMgIzI4PC90aXRsZT4NCg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2Nocm9uaXF1ZS1kaWdpdGFsLW11c2ljLTI4LTYxMTM2LzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY2hyb25pcXVlLWRpZ2l0YWwtbXVzaWMtMjgtNjExMzYvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAwOTozNzo1NCArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%TGF1cmUgRGVjYWlsbHk8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbSW50ZXJuZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTW9iaWxlXV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFba2FyYW9rw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbT3VybGFiZWxdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU3BvdGlmeV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtUcmFja3NdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbVHVybnRhYmxlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3R3aXR0ZXJdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTU5NDwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW05ld3MgZMOpY2Fsw6llcywgdmlkw6lvcyBtdXNpY2FsZXMgZXQgY29uY2VydHMgaW5kw6lz4oCmQ%KAmWVzdCBsYSBjaHJvbmlxdWUgbXVzaXF1ZSBGcmVuY2h3ZWIgZGUgbGEgc2VtYWluZSAhIEF1IHNvbW1haXJlIDogbGVzIDExIG5vdXZlbGxlcyBhcHBsaWNhdGlvbnMgU3BvdGlmeSDDoCBsYSBsb3VwZSwgVHJhY2tzLmJ5IGVuIGLDqnRhIHB1YmxpcXVlLCBPdXJsYWJlbCBsYW5jZSBsZSAxZXIgbGFiZWwgcGFydGljaXBhdGlmIGVudGnDqHJlbWVudCBnw6lyw6kgcGFyIGxlcyBmYW5zLCBUdXJudGFibGUuZm0gc2lnbmUgZGVzIGFjY29yZHMgYXZlYyBsZXMgNCBNYWpvcnMgZHUgZGlzcXVlLCBUd2l0dGVyIHB1YmxpZSBzb24gZ3VpZGUgb2ZmaWNpZWwgcG91ciBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoNCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%TmV3cyBkw6ljYWzDqWVzLCB2aWTDqW9zIG11c2ljYWxlcyBldCBjb25jZXJ0cyBpbmTDqXPigKZD4oCZZXN0IGxhIGNocm9uaXF1ZSBtdXNpcXVlIEZyZW5jaHdlYiBkZSBsYSBzZW1haW5lICEgQXUgc29tbWFpcmUgOiBsZXMgMTEgbm91dmVsbGVzIGFwcGxpY2F0aW9ucyBTcG90aWZ5IMOgIGxhIGxvdXBlLCBUcmFja3MuYnkgZW4gYsOqdGEgcHVibGlxdWUsIE91cmxhYmVsIGxhbmNlIGxlIDFlciBsYWJlbCBwYXJ0aWNpcGF0aWYgZW50acOocmVtZW50IGfDqXLDqSBwYXIgbGVzIGZhbnMsIFR1cm50YWJsZS5mbSBzaWduZSBkZXMgYWNjb3JkcyBhdmVjIGxlcyA0IE1ham9ycyBkdSBkaXNxdWUsIFR3aXR0ZXIgcHVibGllIHNvbiBndWlkZSBvZmZpY2llbCBwb3VyIGxlcyBhcnRpc3RlcywgZXQgbGUgcmV0b3VyIGRlIGh5cGUgZHUga2FyYW9rw6kuPC9wPg0KPHA%PHN0cm9uZz5bU1BPVElGWV0gMTEgbm91dmVsbGVzIGFwcGxpY2F0aW9ucyBtdXNpY2FsZXMgZW4gbGlnbmUuPC9zdHJvbmc%PC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjxhIGhyZWY9Imh0dHA6Ly93d3cuc3BvdGlmeS5jb20vZnIvIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1OTgiIHRpdGxlPSJzcG90aWZ5IiBzcmM9ImFzc2V0cy9GcmVuY2h3ZWItTG9nby03MDB4NzAwLmpwZyIgYWx0PSIiIHdpZHRoPSI3MDAiIGhlaWdodD0iNzAwIiAvPjwvYT48L3A%DQo8cD5FbiBub3ZlbWJyZSBkZXJuaWVyLCA8YSBocmVmPSJodHRwOi8vd3d3LnNwb3RpZnkuY29tL2ZyIj5TcG90aWZ5PC9hPiBvdXZyYWl0IHNhIHBsYXRlZm9ybWUgYXV4IGFwcGxpY2F0aW9ucyBtdXNpY2FsZXMuIFVuZSByw6l2b2x1dGlvbiBkYW5zIGxlIHBldGl0IG1vbmRlIGR1IHN0cmVhbWluZyBxdWksIHBvdXIgbGEgcHJlbWnDqHJlIGZvaXMsIHByb3Bvc2FpdCDDoCBzZXMgdXRpbGlzYXRldXJzIGRlcyBleHDDqXJpZW5jZXMgbXVzaWNhbGVzIGludGVyYWN0aXZlcyBzdXItbWVzdXJlLiBGb3J0IGRlIGNldCBlbmdvdWVtZW50LCA8YSBocmVmPSJodHRwOi8vd3d3LnNwb3RpZnkuY29tL2ZyIj5TcG90aWZ5PC9hPiBhIGTDqXZvaWzDqSBsZSAyMiBtYXJzIG9uemUgbm91dmVsbGVzIGFwcGxpY2F0aW9ucywgZMOpdmVsb3Bww6llcyBub3RhbW1lbnQgcGFyIGxlcyBsYWJlbHMgVW5pdmVyc2FsIE11c2ljLCBTb255IE11c2ljLCBXYXJuZXIgTXVzaWMsIExFR0FDWSwgRGVmIEphbSwgRG9taW5vLCBNYXRhZG9yLCBQSUFTIG91IGVuY29yZSBYNS4gUGV0aXQgdG91ciBk4oCZaG9yaXpvbiBkZXMgbm91dmVhdXTDqXPigKY8c3BhbiBpZD0ibW9yZS01NTU5NCI%PC9zcGFuPjwvcD4NCjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY2hyb25pcXVlLWRpZ2l0YWwtbXVzaWMtMjgtNjExMzYvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bTWF0aW7DqWUgcHJvc3BlY3RpdmUgZHUgR2VzdGVdIFF1ZWwgZnV0dXIgcG91ciBsZXMgbcOpZGlhcyBlbiBsaWduZSA:PC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9tYXRpbmVlLXByb3NwZWN0aXZlLWR1LWdlc3RlLXF1ZWwtZnV0dXItcG91ci1sZXMtbWVkaWFzLWVuLWxpZ25lLTYxMTM0LzwvbGluaz4NCg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9tYXRpbmVlLXByb3NwZWN0aXZlLWR1LWdlc3RlLXF1ZWwtZnV0dXItcG91ci1sZXMtbWVkaWFzLWVuLWxpZ25lLTYxMTM0LyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDk6MjQ6MjAgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTWVkaWFdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbU29jaWFsIE1lZGlhXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2ZyYW5jZSB0ZWxldmlzaW9uc11dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2dlc3RlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3NvY2lhbCBUVl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtUViBjb25uZWN0w6llXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU0NDg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtMZSBHZXN0ZSwgbGUgR3JvdXBlbWVudCBkZXMgRWRpdGV1cnMgZGUgY29udGVudXMgZXQgZGUgc2VydmljZXMgZW4gbGlnbmUsIGEgb3JnYW5pc8OpIGhpZXIgYXUgc2VpbiBkdSBzacOoZ2UgZGUgRnJhbmNlIFTDqWzDqXZpc2lvbnMgdW5lIG1hdGluw6llIHByb3NwZWN0aXZlIGludGl0dWzDqWUgOiAiTcOpZGlhcyBlbiBsaWduZSA6IFdoYXQmIzgyMTc7cyBuZXh0ID8iLiBMJiM4MjE3O29iamVjdGlmIDogaWRlbnRpZmllciBsZXMgbm91dmVhdXggdXNhZ2VzIGxpw6lzIGF1eCB0YWJsZXR0ZXMsIHNtYXJ0cGhvbmVzLCBsYXB0b3BzLCByw6lzZWF1eCBzb2NpYXV4IGV0YyYjODIzMDsgVW5lIGNvbnNvbW1hdGlvbiBxdWkgdHJhbnNmb3JtZSBub3RhbW1lbnQgbGEgcmVsYXRpb24gWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5MZSBHZXN0ZSwgbGUgR3JvdXBlbWVudCBkZXMgRWRpdGV1cnMgZGUgY29udGVudXMgZXQgZGUgc2VydmljZXMgZW4gbGlnbmUsIGEgb3JnYW5pc8OpIGhpZXIgYXUgc2VpbiBkdSBzacOoZ2UgZGUgRnJhbmNlIFTDqWzDqXZpc2lvbnMgdW5lIG1hdGluw6llIHByb3NwZWN0aXZlIGludGl0dWzDqWUgOjxjb2RlPiAiPC9jb2RlPk3DqWRpYXMgZW4gbGlnbmUgOiBXaGF0JiM4MjE3O3MgbmV4dCA:PGNvZGU%IjwvY29kZT4uIEwmIzgyMTc7b2JqZWN0aWYgOiBpZGVudGlmaWVyIGxlcyBub3V2ZWF1eCB1c2FnZXMgbGnDqXMgYXV4IHRhYmxldHRlcywgc21hcnRwaG9uZXMsIGxhcHRvcHMsIHLDqXNlYXV4IHNvY2lhdXggZXRjJiM4MjMwOyBVbmUgY29uc29tbWF0aW9uIHF1aSB0cmFuc2Zvcm1lIG5vdGFtbWVudCBsYSByZWxhdGlvbiBkdSBtZWRpYSBhdmVjIHNvbiBhdWRpZW5jZSAoZXQgcsOpY2lwcm9xdWVtZW50ICEpLjwvcD4NCjxwPkRldXggdGFibGVzIHJvbmRlcyBvbnQgw6l0w6kgbCYjODIxNztvY2Nhc2lvbiBkJiM4MjE3O8OpY2hhbmdlciBzdXIgbGVzIHRlbmRhbmNlcyBkJiM4MjE3O2F1am91cmQmIzgyMTc7aHVpIGV0IGRlIGRlbWFpbiwgYXZlYyBkZXMgcHJvZmVzc2lvbm5lbHMgZGVzIG3DqWRpYXMuIFBhcm1pIGV1eCwgRXJpYyBTY2hlcmVyLCBEaXJlY3RldXIgZGUgbGEgUHJvc3BlY3RpdmUgZGUgbGEgU3RyYXTDqWdpZSBldCBkZXMgUmVsYXRpb25zIEludGVybmF0aW9uYWxlcyBkZSBGcmFuY2UgVMOpbMOpdmlzaW9ucy48L3A%DQo8cD48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU0ODMiIHRpdGxlPSJHZXN0ZSIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL0dlc3RlMS5qcGciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjEzMiIgLz48L3A%DQo8cD5SZXZlbmFudCBkZXB1aXMgcGV1IGR1ICZsYXF1bzsmbmJzcDtTb3V0aCBCeSBTb3V0aFdlc3QmbmJzcDsmcmFxdW87IMOgIEF1c3RpbiBhdXggRXRhdHMtVW5pcywgaWwgYSBwdSB0w6ltb2lnbmVyIGRlIGwmIzgyMTc7ZXNzb3IgZ3JhbmRpc3NhbnQgZGUgbGEgc29jaWFsIFRWLCBsYSB0w6lsw6l2aXNpb24gcXVpIGludMOoZ3JlIGxlcyByw6lzZWF1eCBzb2NpYXV4IGRhbnMgc29uIGludGVyZmFjZSA6ICZsYXF1bzsmbmJzcDs8ZW0%IElsIHkgYSB1biBlbnJpY2hpc3NlbWVudCBkZSBsJiM4MjE3O2V4cMOpcmllbmNlIHV0aWxpc2F0ZXVyIHF1aSBlc3QgaW50ZXJ2ZW51IGNlcyAxOCBkZXJuaWVycyBtb2lzLCBncsOiY2UgYXV4IHRhYmxldHRlcyBldCBhdXggc21hcnRwaG9uZXM8L2VtPjxjb2RlPiI8L2NvZGU%LCBwcsOpY2lzZS10LWlsLiBBdXggRXRhdHMtVW5pcywgcHLDqHMgZGUgbGEgbW9pdGnDqSBkZXMgdXRpbGlzYXRldXJzIGRlIGNlcyBkZXZpY2VzIHNlIGNvbm5lY3RlbnQgZW4gcmVnYXJkYW50IGxhIHTDqWzDqXZpc2lvbi4gRW4gRnJhbmNlLCBsZSBjaGlmZnJlIHRvdXJuZSBhdXRvdXIgPHNwYW4gaWQ9Im1vcmUtNTU0NDgiPjwvc3Bhbj5kZXMgMzAlLjwvcD4NCjxwPkxlcyBncmFuZGVzIGNoYcOubmVzIGRlIFRWIG9udCBjb21tZW5jw6kgw6AgaW50w6lncmVyIGNldHRlIG5vdXZlbGxlIGNvbnNvbW1hdGlvbiBlbiBtaXNhbnQgc3VyIGxlIGNhbmFsIFR3aXR0ZXIgZXQgRmFjZWJvb2ssIHN1ciBkZXMgw6ltaXNzaW9ucyBwcmltZS10aW1lIGNvbW1lICZsYXF1bzsmbmJzcDtUb3AgQ2hlZiZuYnNwOyZyYXF1bzsgb3UgZGVzIMOpbWlzc2lvbnMgcG9saXRpcXVlcyDDoCBmb3J0ZSBhdWRpZW5jZSwgY29tbWUgJmxhcXVvOyZuYnNwO0RlcyBQYXJvbGVzIGV0IGRlcyBBY3RlcyZuYnNwOyZyYXF1bzsuIExlcyBkZXJuacOocmVzIFZpY3RvaXJlcyBkZSBsYSBNdXNpcXVlIG9udCBnw6luw6lyw6kgcGx1cyBkZSAzMCAwMDAgdHdlZXRzIHBlbmRhbnQgbGEgZGlmZnVzaW9uLjwvcD4NCjxwPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01NTYwOSIgdGl0bGU9ImJhbmRlYXUgR2VzdGUiIHNyYz0iaHR0cDovL2ZyZW5jaHdlYi5mci93cC1jb250ZW50L3VwbG9hZHMvMjAxMi8wMy9iYW5kZWF1LUdlc3RlMS5wbmciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjE4MyIgLz48L3A%DQo8L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL21hdGluZWUtcHJvc3BlY3RpdmUtZHUtZ2VzdGUtcXVlbC1mdXR1ci1wb3VyLWxlcy1tZWRpYXMtZW4tbGlnbmUtNjExMzQvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KDQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltTaG9wcGluZ10gQm9uaWFsLCBsZSBndWlkZSBwb3VyIHByw6lwYXJlciBzZXMgYWNoYXRzIGVuIG1hZ2FzaW48L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2JvbmlhbC1ndWlkZS1wb3VyLXByZXBhcmVyLXNlcy1hY2hhdHMtZW4tbWFnYXNpbi02MTEzMy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2JvbmlhbC1ndWlkZS1wb3VyLXByZXBhcmVyLXNlcy1hY2hhdHMtZW4tbWFnYXNpbi02MTEzMy8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5GcmksIDMwIE1hciAyMDEyIDA4OjMwOjQxICswMDAwPC9wdWJEYXRlPg0KDQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZUNvbW1lcmNlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01hcmtldGluZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtWaWRlb11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVthY2hhdF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtCb25pYWxdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZ3VpZGVdXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVt1bmVdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01NTQ5NzwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0ZpbGlhbGUgZGUgS2F1ZkRhIGR1IEdyb3VwZSBBeGVsIFNwcmluZ2VyLCBCb25pYWwgYSBkw6liYXJxdcOpIGVuIEZyYW5jZSBlbiBkw6ljZW1icmUgZGVybmllci4gQ2UgZ3VpZGUgcGVybWV0IGRlIGNvbnN1bHRlciBwbHVzaWV1cnMgbWlsbGllcnMgZGUgcGFnZXMgcHJvZHVpdHMuIEVudHJldGllbiBhdmVjIGxlIENFTyBGcmFuY2UgZGUgQm9uaWFsLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkxhbmPDqSBlbiBkw6ljZW1icmUgMjAxMSwgPGEgaHJlZj0iaHR0cDovL3d3dy5ib25pYWwuZnIvIiB0YXJnZXQ9Il9ibGFuayI%Qm9uaWFsPC9hPiBwZXJtZXQgZGUgcHLDqXBhcmVyIHNlcyBhY2hhdHMgZW4gdW4gY2xpbiBkJiM4MjE3O29laWwgOiBvbiBwZXV0IHJlY2hlcmNoZXIgdW4gcHJvZHVpdCwgY29uc3VsdGVyIHNhIGRpc3BvbmliaWxpdMOpLCBjb25uYcOudHJlIGxlcyBhZHJlc3NlcyBldCBob3JhaXJlcyBk4oCZb3V2ZXJ0dXJlIGRlcyBtYWdhc2lucyBwcm9jaGVzIGRlIHNvaeKApjwvcD4NCjxwPkxlIHNpdGUgZXN0IGTDqWNsaW7DqSBlbiA8YSBocmVmPSJodHRwOi8vaXR1bmVzLmFwcGxlLmNvbS9mci9hcHAvYm9uaWFsL2lkNDY4NjI0NTY3P210PTgiIHRhcmdldD0iX2JsYW5rIj5hcHBsaWNhdGlvbjwvYT4sIGRpc3BvbmlibGUgc3VyIGlQaG9uZSwgaVBhZCBldCBBbmRyb2lkLiBBdSAwOSBtYXJzLCBCb25pYWwgw6l0YWl0IGwmIzgyMTc7YXBwbGljYXRpb24gbGEgcGx1cyB0w6lsw6ljaGFyZ8OpZSBzdXIgQXBwIFN0b3JlIGRhbnMgbGEgY2F0w6lnb3JpZSAmbGFxdW87Jm5ic3A7YXBwbGljYXRpb25zIGdyYXR1aXRlcyZuYnNwOyZyYXF1bzssIGV0IHNlIHBsYcOnYWl0IGRhbnMgbGUgVE9QIDUgZGVzIGFwcGxpY2F0aW9ucyBsZXMgcGx1cyB0w6lsw6ljaGFyZ8OpZXMgc3VyIGlQYWQuIExlIG1vZMOobGUgZGUgQm9uYWwgcmVwb3NlIHN1ciBsYSBwZXJmb3JtYW5jZSA6IEJvbmlhbCBwcm9wb3NlIGRlcyB2b2x1bWVzIGRlIGNvbnN1bHRhdGlvbiBzdXIgbGVzIGNhdGFsb2d1ZXMsIHRyw6hzIGNvbnN1bHTDqXMgcGFyIGxlcyB1dGlsaXNhdGV1cnMuPC9wPg0KPHA%RmlsaWFsZSBkZSBsYSBzb2Npw6l0w6kgYWxsZW1hbmRlIDxhIGhyZWY9Imh0dHA6Ly93d3cua2F1ZmRhLmRlL0JlcmxpbiIgdGFyZ2V0PSJfYmxhbmsiPmthdWZEQTwvYT4gKEdyb3VwZSBBeGVsIFNwcmluZ2VyKSwgQm9uaWFsIHJldmVuZGlxdWUgdW5lIGF1ZGllbmNlIGRlIDRNIGRlIFZVIGVuIEFsbGVtYWduZS4ga2F1ZkRBIGEgZMOpdmVsb3Bww6kgdW5lIHRlY2hub2xvZ2llIGV0IHVuIHNhdm9pci1mYWlyZSBlbiBtYXJrZXRpbmcgZGlnaXRhbCBldCBTRU8uPC9wPg0KPHA%PHN0cm9uZz5FbnRyZXRpZW4gYXZlYyBNYXR0aGlhcyBCZXJhaHlhLUxhemFydXMsIENFTyBkZSBCb25pYWwgRnJhbmNlIDwvc3Ryb25nPjwvcD4NCjxwPjxjZW50ZXI%PGlmcmFtZSBzcmM9Imh0dHA6Ly93d3cuZGFpbHltb3Rpb24uY29tL2VtYmVkL3ZpZGVvL2szQ1BYckJCR01vQmNlMlZxYmMiIGZyYW1lYm9yZGVyPSIwIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjMwOSI%PC9pZnJhbWU%PC9jZW50ZXI%PC9wPg0KPGRpdiBpZD0iY3JwX3JlbGF0ZWQiPjxoMz5BcnRpY2xlcyBzdXIgbGUgbcOqbWUgc3VqZXQ8L2gzPjx1bD48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9uZXdzLWNlLXF1ZS1pbC1mYXV0LXNhdm9pci1jZS1tYXRpbi01MDQ0MC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltOZXdzXSBDZSBxdSYjODIxNztpbCBmYXV0IHNhdm9pciBjZSBtYXRpbjwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL29obXlkZWFsLWxhbmNlLW9mZmljaWVsbGVtZW50LXNvbi1hcHBsaWNhdGlvbi1pcGFkLTUwMjM2LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%T2hNeURlYWwgbGFuY2Ugc29uIGFwcGxpY2F0aW9uIGlQYWQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9za3lwZS1kZXZyYWl0LWV0cmUtZGlzcG9uaWJsZS1lbi12ZXJzaW9uLWlwYWQtZGVzLWNldHRlLXNlbWFpbmUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5Ta3lwZSBkZXZyYWl0IMOqdHJlIGRpc3BvbmlibGUgZW4gdmVyc2lvbiBpUGFkIGTDqHMgY2V0dGUgc2VtYWluZTwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2V4Y2x1LWJvbnMtcGxhbnMtb2hteWRlYWwtZGlzcG9uaWJsZXMtc3VyLWlwYWQvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRXhjbHVdIExlcyBib25zIHBsYW5zIGQmIzgyMTc7T2hNeWRlYWwgZGlzcG9uaWJsZXMgc3VyIElwYWQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ub3V2ZWF1LXN0YXItYXBwLWxlLWdvb2dsZS1kZXMtYXBwbGljYXRpb25zLW1vYmlsZXMtNjA3MzEvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bTm91dmVhdV0gU3RhciBhcHAsIGxlIEdvb2dsZSBkZXMgYXBwbGljYXRpb25zIG1vYmlsZXM8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvYm9uaWFsLWd1aWRlLXBvdXItcHJlcGFyZXItc2VzLWFjaGF0cy1lbi1tYWdhc2luLTYxMTMzL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjM8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoNCgkJPGl0ZW0%DQoJCTx0aXRsZT5bQXRlbGllciBudW3DqXJpcXVlIC0gQkZNIEJ1c2luZXNzXSBMYSBjaHJvbmlxdWUgc3RhcnQtdXAgZGUgRnJlbmNod2ViICMyMiA6IE1lbnRpb24ubmV0PC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9hdGVsaWVyLW51bWVyaXF1ZS1iZm0tYnVzaW5lc3MtbGEtY2hyb25pcXVlLXN0YXJ0LXVwLWRlLWZyZW5jaHdlYi0yMi1tZW50aW9uLW5ldC02MTEzMy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2F0ZWxpZXItbnVtZXJpcXVlLWJmbS1idXNpbmVzcy1sYS1jaHJvbmlxdWUtc3RhcnQtdXAtZGUtZnJlbmNod2ViLTIyLW1lbnRpb24tbmV0LTYxMTMzLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDg6MzA6MzggKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkJlcnRyYW5kIExlbm90cmU8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQWN0dV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtJbnRlcm5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtTdGFydHVwXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW01lbnRpb25dXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbdmVpbGxlXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1NjI8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtDcsOpw6kgZW50cmUgUGFyaXMgZXQgQnJ1eGVsbGVzIHBhciA0IGNyw6lhdGV1cnMgZG9udCB1biBmb25kYXRldXIgZGUgRm90b2xpYSwgVGhpYmF1bHQgRWx6aWVyZSBldCBsJiM4MjE3O2V4IENFTyBkZSBQcmVzc2tpbmcsIEVkb3VhcmQgIGRlIGxhIEpvbnF1acOocmUsIE1lbnRpb24gZXN0IHVuIG5vdXZlbCBvdXRpbCBkZSB2ZWlsbGUgcG91ciBtb25pdG9yZXIgZW4gdGVtcHMgcsOpZWwgY2UgcXVpIHNlIGRpdCBzdXIgdm91cywgdm90cmUgbWFycXVlIG91IHZvdHJlIHNvY2nDqXTDqSBzdXIgbCYjODIxNztlbnNlbWJsZSBkZSBsJiM4MjE3O0ludGVybmV0IChXZWIsIFR3aXR0ZXIsIEZsaWNrciwgR29vZ2xlIE5ld3MsIGxlcyBbLi4uXV1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkNyw6nDqSBlbnRyZSBQYXJpcyBldCBCcnV4ZWxsZXMgcGFyIDQgY3LDqWF0ZXVycyBkb250IHVuIGZvbmRhdGV1ciBkZSBGb3RvbGlhLCBUaGliYXVsdCBFbHppZXJlIGV0IGwmIzgyMTc7ZXggQ0VPIGRlIFByZXNza2luZywgRWRvdWFyZCAgZGUgbGEgSm9ucXVpw6hyZSwgPGEgaHJlZj0iaHR0cHM6Ly9mci5tZW50aW9uLm5ldC8iIHRhcmdldD0iX2JsYW5rIj5NZW50aW9uPC9hPiBlc3QgdW4gbm91dmVsIG91dGlsIGRlIHZlaWxsZSBwb3VyIG1vbml0b3JlciBlbiB0ZW1wcyByw6llbCBjZSBxdWkgc2UgZGl0IHN1ciB2b3VzLCB2b3RyZSBtYXJxdWUgb3Ugdm90cmUgc29jacOpdMOpIHN1ciBsJiM4MjE3O2Vuc2VtYmxlIGRlIGwmIzgyMTc7SW50ZXJuZXQgKFdlYiwgVHdpdHRlciwgRmxpY2tyLCBHb29nbGUgTmV3cywgbGVzIGJsb2dzLCBmb3J1bXMsIHBsYXRlZm9ybWVzIHZpZMOpbyYjODIzMDspLjwvcD4NCjxwPjxhIGhyZWY9Imh0dHBzOi8vZnIubWVudGlvbi5uZXQvIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1NzciIHRpdGxlPSJNZW50aW9uIiBzcmM9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5qcGVnIiBhbHQ9IiIgd2lkdGg9IjQ1MiIgaGVpZ2h0PSIyNTkiIC8%PC9hPjwvcD4NCjxwPlVuIG91dGlsIGRlIHZlaWxsZSBleGhhdXN0aWYgcXVpIGVudGVuZCBzZSBwb3NpdGlvbm5lciBjb21tZSB1biBEcm9wYm94IG91IHVuIEV2ZXJub3RlIMOgIGxhIGxpc2nDqHJlIGRlcyB1dGlsaXNhdGlvbnMgcGVyc29ubmVsbGVzIC8gcHJvZmVzc2lvbm5lbGxlcyBkYW5zIHVuZSBnYW1tZSBkZSB0YXJpZnMgcGx1cyBhY2Nlc3NpYmxlIHF1ZSBjZWxsZSBkZXMgc29sdXRpb25zIEIyQiBleGlzdGFudGVzIHN1ciBsZSBtYXJjaMOpLiBNZW50aW9uIGVzdCB1bmUgJmxhcXVvOyZuYnNwO3NpbmdsZS1wYWdlLWFwcCZuYnNwOyZyYXF1bzsgKE1hYyAvIFdpbmRvd3MgLyBMaW51eCksIGJpZW50w7R0IHN1ciBtb2JpbGUsIGV0IGRpc3BvbmlibGUgZW4gMyBsYW5ndWVzIChmcmFuw6dhaXMsIGFuZ2xhaXMsIGFsbGVtYW5kKS4gTGVzIGNvbnRlbnVzIHNvbnQsIGV1eCwgdHJhY2vDqXMgZGFucyA0MiBsYW5ndWVzLiBVbiBjaG9peCBjYXTDqWdvcmllbCBkZXMgYWxlcnRlcyBwZXJtZXQgZGUgY2libGVyIHNlcyBjaGFtcHMgZGUgdmVpbGxlLjwvcD4NCjxwPkxlIGJ1c2luZXNzIG1vZGVsIGRlIE1lbnRpb24gdGllbnQgw6AgdW5lIG9mZnJlIGZyZWVtaXVtIDogZGUgNC45MCDigqwgcG91ciA1MDAgbWVudGlvbnMgcGFyIG1vaXMgw6AgMTk5IOKCrCBwb3VyIDUwIDAwMCBtZW50aW9ucy48L3A%DQo8IS0tIGRlZ3JhZGFibGUgaHRtbDUgYXVkaW8gYW5kIHZpZGVvIHBsdWdpbiAtLT48ZGl2IGNsYXNzPSJhdWRpb193cmFwIGh0bWw1YXVkaW8iPjxkaXYgc3R5bGU9ImRpc3BsYXk6bm9uZTsiPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMiIHRpdGxlPSJDbGljayB0byBvcGVuIiBpZD0iZi1odG1sNWF1ZGlvLTEiPkF1ZGlvIE1QMzwvYT48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%QXVkaW9QbGF5ZXIuZW1iZWQoImYtaHRtbDVhdWRpby0xIiwge3NvdW5kRmlsZTogImh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMifSk7PC9zY3JpcHQ%PC9kaXY%PGF1ZGlvIGNvbnRyb2xzIGF1dG9idWZmZXIgaWQ9Imh0bWw1YXVkaW8tMSIgY2xhc3M9Imh0bWw1YXVkaW8iPjxzb3VyY2Ugc3JjPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01lbnRpb24ubXAzIiB0eXBlPSJhdWRpby9tcGVnIiAvPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMiIHRpdGxlPSJDbGljayB0byBvcGVuIiBpZD0iZi1odG1sNWF1ZGlvLTEiPkF1ZGlvIE1QMzwvYT48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%QXVkaW9QbGF5ZXIuZW1iZWQoImYtaHRtbDVhdWRpby0xIiwge3NvdW5kRmlsZTogImh0dHA6Ly9mcmVuY2h3ZWIuZnIvd3AtY29udGVudC91cGxvYWRzLzIwMTIvMDMvTWVudGlvbi5tcDMifSk7PC9zY3JpcHQ%PC9hdWRpbz48L2Rpdj48c2NyaXB0IHR5cGU9InRleHQvamF2YXNjcmlwdCI%aWYgKGpRdWVyeS5icm93c2VyLm1vemlsbGEpIHt0ZW1wYXVkPWRvY3VtZW50LmdldEVsZW1lbnRzQnlUYWdOYW1lKCJhdWRpbyIpWzBdOyBqUXVlcnkodGVtcGF1ZCkucmVtb3ZlKCk7IGpRdWVyeSgiZGl2LmF1ZGlvX3dyYXAgZGl2Iikuc2hvdygpfSBlbHNlIGpRdWVyeSgiZGl2LmF1ZGlvX3dyYXAgZGl2ICoiKS5yZW1vdmUoKTs8L3NjcmlwdD4NCjxwPjwvcD4NCjxkaXYgaWQ9ImNycF9yZWxhdGVkIj48aDM%QXJ0aWNsZXMgc3VyIGxlIG3Dqm1lIHN1amV0PC9oMz48dWw%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbWVudGlvbi1zb3J0aXItY29tLWluZm9uYWlzc2FuY2UtYmRzcGhlcmUtbGVzLTQtZGVybmllcmVzLW5vdXZlYXV0ZXMtNjEwNDIvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5NZW50aW9uLCBTb3J0aXIuY29tLCBJbmZvbmFpc3NhbmNlLCBCRHNwaMOocmUgOiBsZXMgNCBkZXJuacOocmVzIG5vdXZlYXV0w6lzPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvYXVqb3VyZGh1aS1zdXItZnJlbmNod2ViLTIwLTYxMDUxLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%QXVqb3VyZCYjODIxNztodWkgc3VyIEZyZW5jaFdlYiYjODIzMDs8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9ncmFuZGVzLW1hcnF1ZXMtZmFjZWJvb2stdHdpdHRlci8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPk1haXMgb8O5IHNvbnQgbGVzIEZhY2Vib29rIGV0IFR3aXR0ZXIgZGVzIGdyYW5kZXMgbWFycXVlcyA:PC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvYnV6enBhcmFkaXNlLWRldmllbnQtbGEtMWVyZS1wbGF0ZWZvcm1lLWV1cm9wZWVubmUtZGUtc29jaWFsLW1lZGlhLWFkdmVydGlzaW5nLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%QnV6elBhcmFkaXNlIGRldmllbnQgbGEgMcOocmUgcGxhdGVmb3JtZSBldXJvcMOpZW5uZSBkZSBzb2NpYWwgbWVkaWEgYWR2ZXJ0aXNpbmc8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9kZXJyaWVyZS1sYS1yZXZvbHV0aW9uLWR1LW1vYmlsZS1zZS1jYWNoZXJhaXQtbnVtZXJpY2FibGUvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5EZXJyacOocmUgJmxhcXVvOyZuYnNwO0xhIFLDqXZvbHV0aW9uIGR1IE1vYmlsZSZuYnNwOyZyYXF1bzsgc2UgY2FjaGVyYWl0IE51bWVyaWNhYmxlICE8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KDQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyZW5jaHdlYi5mci9hdGVsaWVyLW51bWVyaXF1ZS1iZm0tYnVzaW5lc3MtbGEtY2hyb25pcXVlLXN0YXJ0LXVwLWRlLWZyZW5jaHdlYi0yMi1tZW50aW9uLW5ldC02MTEzMy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCjxlbmNsb3N1cmUgdXJsPSJodHRwOi8vZnJlbmNod2ViLmZyL3dwLWNvbnRlbnQvdXBsb2Fkcy8yMDEyLzAzL01lbnRpb24ubXAzIiBsZW5ndGg9IjM3NjE1NTAiIHR5cGU9ImF1ZGlvL21wZWciIC8%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bSW5mb2dyYXBoaWVdIExlIG1hcmNow6kgZGVzIGFwcGxpY2F0aW9ucyBtb2JpbGVzIG11c2ljYWxlczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvaW5mb2dyYXBoaWUtbGUtbWFyY2hlLWRlcy1hcHBsaWNhdGlvbnMtbW9iaWxlcy1tdXNpY2FsZXMtNjExMzIvPC9saW5rPg0KDQoJCTxjb21tZW50cz5odHRwOi8vZnJlbmNod2ViLmZyL2luZm9ncmFwaGllLWxlLW1hcmNoZS1kZXMtYXBwbGljYXRpb25zLW1vYmlsZXMtbXVzaWNhbGVzLTYxMTMyLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDg6MDk6MDQgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGlldHRlIFJheW5hbDwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbSW50ZXJuZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTGVzIGNoaWZmcmVzIGR1IG5ldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtNb2JpbGVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYXBwbGljYXRpb25dXT48L2NhdGVnb3J5Pg0KDQoJCTxjYXRlZ29yeT48IVtDREFUQVtjb21wYXJhaXNvbl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtlc3ByaXQgbXVzaXF1ZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtTb3VuZFBsYWNlc11dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NTYwPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbQSBsJiM4MjE3O29jY2FzaW9uIGRlIGxhIHNvcnRpZSBkZSBsYSBub3V2ZWxsZSB2ZXJzaW9uIGRlIGwmIzgyMTc7YXBwbGljYXRpb24gU291bmRwbGFjZXMsIGTDqWRpw6llIMOgIGxhIGTDqWNvdXZlcnRlIGRlIGpldW5lcyB0YWxlbnRzIG11c2ljYXV4LCBFc3ByaXQgTXVzaXF1ZSBhIHLDqWFsaXPDqSB1bmUgaW5mb2dyYXBoaWUgc3VyIGxlcyBhcHBsaWNhdGlvbnMgbW9iaWxlcyBtdXNpY2FsZXMuIEF1IG1lbnUgOiB1c2FnZXMgZXQgY2hpZmZyZXMgZHUgbWFyY2jDqSwgbWFpcyDDqWdhbGVtZW50IGNvbXBhcmFpc29uIGRlcyBkaWZmw6lyZW50ZXMgYXBwbGljYXRpb25zIG1vYmlsZXMgZGlzcG9uaWJsZXMsIHNhbnMgb3VibGllciBxdWVscXVlcyBjaGlmZnJlcyByw6ljYXBpdHVsYXRpZnMgZHUgZGlzcG9zaXRpZiBTb3VuZHBsYWNlcy4NCg0KUGFybWkgWy4uLl1dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5BIGwmIzgyMTc7b2NjYXNpb24gZGUgbGEgc29ydGllIGRlIGxhIG5vdXZlbGxlIHZlcnNpb24gZGU8YSBocmVmPSJodHRwOi8vaXR1bmVzLmFwcGxlLmNvbS9mci9hcHAvc291bmQtcGxhY2VzLWVzcHJpdC1tdXNpcXVlL2lkNDM3Nzk2OTQ1P210PTgiIHRhcmdldD0iX2JsYW5rIj4gbCYjODIxNzthcHBsaWNhdGlvbiBTb3VuZHBsYWNlczwvYT4sIGTDqWRpw6llIMOgIGxhIGTDqWNvdXZlcnRlIGRlIGpldW5lcyB0YWxlbnRzIG11c2ljYXV4LCBFc3ByaXQgTXVzaXF1ZSBhIHLDqWFsaXPDqSB1bmUgaW5mb2dyYXBoaWUgc3VyIGxlcyBhcHBsaWNhdGlvbnMgbW9iaWxlcyBtdXNpY2FsZXMuIEF1IG1lbnUgOiB1c2FnZXMgZXQgY2hpZmZyZXMgZHUgbWFyY2jDqSwgbWFpcyDDqWdhbGVtZW50IGNvbXBhcmFpc29uIGRlcyBkaWZmw6lyZW50ZXMgYXBwbGljYXRpb25zIG1vYmlsZXMgZGlzcG9uaWJsZXMsIHNhbnMgb3VibGllciBxdWVscXVlcyBjaGlmZnJlcyByw6ljYXBpdHVsYXRpZnMgZHUgZGlzcG9zaXRpZiBTb3VuZHBsYWNlcy48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy5lc3ByaXRtdXNpcXVlLmZyL2luZm9ncmFwaGllIj48aW1nIGNsYXNzPSJhbGlnbmNlbnRlciBzaXplLWZ1bGwgd3AtaW1hZ2UtNTU1NjQiIHRpdGxlPSJhcHBsaWNhdGlvbnMtbW9iaWxlcy1tdXNpcXVlcyIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL2FwcGxpY2F0aW9ucy1tb2JpbGVzLW11c2lxdWVzLmpwZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjcxIiAvPjwvYT48L3A%DQo8cD5QYXJtaSBsZXMgY2hpZmZyZXMgY2xlZnMgOjwvcD4NCjx1bD4NCjxsaT4yMCUgZGVzIGdlbnMgdXRpbGlzZW50IGxldXIgbW9iaWxlIHBvdXIgw6ljb3V0ZXIgZGUgbGEgbXVzaXF1ZTwvbGk%DQo8bGk%OU0gZGUgdGl0cmVzIHTDqWzDqWNoYXJnw6lzIHN1ciBtb2JpbGU8L2xpPg0KPGxpPlBsdXMgZGUgPHNwYW4gaWQ9Im1vcmUtNTU1NjAiPjwvc3Bhbj4xNiUgZHUgQ0EgZHUgbWFyY2jDqSBkZSBsYSBtdXNpcXVlIG51bcOpcmlxdWUgZXN0IHLDqWFsaXPDqSBzdXIgbGVzIG1vYmlsZXM8L2xpPg0KPGxpPjIxIDI3NyBhcHBsaWNhdGlvbnMgbXVzaWNhbGVzIGRpc3BvbmlibGVzIHN1ciBsJiM4MjE3O0FwcCBTdG9yZSwgZG9udCA1NSUgZ3JhdHVpdGVzPC9saT4NCjxsaT4xMDAgMDAwIHTDqWzDqWNoYXJnZW1lbnRzIHBvdXIgU291bmRwbGFjZXM8L2xpPg0KPC91bD4NCjxwPjwvY2VudGVyPg0KPGRpdiBjbGFzcz0iZXNwcml0bXVzaXF1ZV9lbWJlZCI%DQo8ZGl2IGNsYXNzPSJnY19hcnRpY2xlX2dyYXBoaWNfYnV0dG9uX2VtYmVkIj48L2Rpdj4NCjxkaXYgY2xhc3M9ImdjX2FydGljbGVfZ3JhcGhpY19jb3B5Ij48c3BhbiBjbGFzcz0iZXNwcml0bXVzaXF1ZV9lbWJlZF90aXRsZV9jb3B5Ij5JbnTDqWdyZXIgbCYjODIxNztpbmZvZ3JhcGhpZSBjaSBkZXNzb3VzIMOgIHZvdHJlIHNpdGU8L3NwYW4%PHNwYW4gY2xhc3M9ImVzcHJpdG11c2lxdWVfZW1iZWRfd2lkdGhfY29weSI%VGFpbGxlIGRlIGwmIzgyMTc7aW1hZ2UgKGVuIHBpeGVsKSA6PC9zcGFuPjxiciAvPg0KPGlucHV0IHR5cGU9InRleHQiIG5hbWU9ImVzcHJpdG11c2lxdWVfZW1iZWRfd2lkdGgiIHZhbHVlPSI1NTAiIC8%IDxzcGFuIGNsYXNzPSJlc3ByaXRtdXNpcXVlX2VtYmVkX3dpZHRoX2NvcHkiPkNvcGllciBsZSBjb250ZW51IGR1IGNoYW1wIGNpIGRlc3NvdXMgOjwvc3Bhbj48YnIgLz4NCjxpbnB1dCBpZD0iZXNwcml0bXVzaXF1ZV9lbWJlZF9jb3B5IiB0eXBlPSJ0ZXh0IiBuYW1lPSJlc3ByaXRtdXNpcXVlX2VtYmVkX2NvcHkiIHZhbHVlPSIiIC8%PC9kaXY%DQo8L2Rpdj4NCjxwPiA8L2NlbnRlcj48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xhLWNhaXNzZS1lcGFyZ25lLWFmZmluZS1zYS1zdHJhdGVnaWUtbXVzaWNhbGUtYXZlYy11bmUtbm91dmVsbGUtdmVyc2lvbi1kZS1zb3VuZHBsYWNlcy1ldC1lc3ByaXRtdXNpcXVlLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TGEgQ2Fpc3NlIGQmIzgyMTc7RXBhcmduZSBhZmZpbmUgc2Egc3RyYXTDqWdpZSBtdXNpY2FsZSBhdmVjIHVuZSBub3V2ZWxsZSB2ZXJzaW9uIGRlIFNvdW5kUGxhY2VzIGV0IEVzcHJpdE11c2lxdWU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci91c2VyYWRnZW50cy1wYXNzZS1hcHAtc3RvcmUtYXBwbGUtYXUtY3JpYmxlLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%VXNlckFEZ2VudHMgcGFzc2UgbCYjODIxNztBcHAgU3RvcmUgZCYjODIxNztBcHBsZSBhdSBjcmlibGU8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9wZXRpdC10ZXN0LWRlLWdvb2dsZS1mcmllbmQtY29ubmVjdC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPlBldGl0IHRlc3QgZGUgR29vZ2xlIEZyaWVuZCBDb25uZWN0PC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbG9ycy1kdS1wcm9jaGFpbi1yZW1hbmllbWVudC1taW5pc3RlcmllbC1xdWVsLXBvbGl0aXF1ZS12b3VzLXBhcmFpdC1sZS1wbHVzLWEtbWVtZS1kZS1yZW1wbGFjZXItZGVyaWMtYmVzc29uLWNvbW1lLXNlY3JldGFpcmUtZCVlMiU4MCU5OWV0YXQtYS1sJWUyJTgwJTk5ZWNvbm9taWUtbnVtZXJpcXVlLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%TG9ycyBkdSBwcm9jaGFpbiByZW1hbmllbWVudCBtaW5pc3RlcmllbCwgcXVlbCBwb2xpdGlxdWUgdm91cyBwYXJhaXQgbGUgcGx1cyDDoCBtw6ptZSBkZSByZW1wbGFjZXIgRXJpYyBCZXNzb24sIGNvbW1lIHNlY3LDqXRhaXJlIGTigJnDqXRhdCDDoCBs4oCZw6ljb25vbWllIG51bcOpcmlxdWU:PC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvaWxzLWFpbWVudC1mcmVuY2h3ZWItZnItZXQtdm91cy8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPklscyBhaW1lbnQgRnJlbmNod2ViLmZyIGV0IHZvdXM:PC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2luZm9ncmFwaGllLWxlLW1hcmNoZS1kZXMtYXBwbGljYXRpb25zLW1vYmlsZXMtbXVzaWNhbGVzLTYxMTMyL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%MTwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bRWxlY3Rpb24gUHLDqXNpZGVudGllbGxlXSBNb24gaWTDqWUgcG91ciAyMDEyICYjODIxMTsgRW1tYW51ZWwgVml2aWVyPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItZW1tYW51ZWwtdml2aWVyLTYxMTMxLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvZWxlY3Rpb24tcHJlc2lkZW50aWVsbGUtbW9uLWlkZWUtcG91ci0yMDEyLWVtbWFudWVsLXZpdmllci02MTEzMS8jY29tbWVudHM8L2NvbW1lbnRzPg0KDQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMDc6MjU6NTkgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPk1hcmlvbiBNb3JlYXU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbRnJlbmNoV2ViXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1ZpZGVvXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0VtbWFudWVsIFZpdmllcl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtpZMOpZSAyMDEyXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3VuZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnJlbmNod2ViLmZyLz9wPTU1NDY4PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbSWwgZmF1dCB1biBTbWFsbCBBY3QgZW4gRnJhbmNlICEgQydlc3QgbCdpZMOpZSBkw6lmZW5kdWUgcGFyIEVtbWFudWVsIFZpY2llciwgYW5jaWVuIGNvLSBmb25kYXRldXIgZGUgbCdhZ2VuY2UgVmFua3NlbiwgYXVqb3VyZCdodWkgY29uc3VsdGFudCBlbiBtYXJrZXRpbmcgZGlnaXRhbC5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5DaGFxdWUgam91ciwgdW4gYWN0ZXVyIGR1IG5ldCBub3VzIGxpdnJlIHNvbiBpZMOpZSBwb3VyIDIwMTIsIHBvdXIgaW50ZXJwZWxsZXIgbGVzIGNhbmRpZGF0cyDDoCBsJiM4MjE3O8OpbGVjdGlvbiBwcsOpc2lkZW50aWVsbGUgc3VyIGxlcyBlbmpldXggZHUgbnVtw6lyaXF1ZS4gQXVqb3VyZCYjODIxNztodWksIEVtbWFudWVsIFZpdmllciwgYW5jaWVuIGNvLSBmb25kYXRldXIgZGUgbCYjODIxNzthZ2VuY2UgPGEgaHJlZj0iaHR0cDovL3d3dy52YW5rc2VuLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5WYW5rc2VuPC9hPiwgYXVqb3VyZCYjODIxNztodWkgY29uc3VsdGFudCBlbiBtYXJrZXRpbmcgZGlnaXRhbC48L3A%DQo8cD48c3Ryb25nPlLDqWFnaXNzZXogc3VyIFR3aXR0ZXIgOiAjRlcyMDEyPC9zdHJvbmc%PC9wPg0KPHA%PGNlbnRlcj48aWZyYW1lIHNyYz0iaHR0cDovL3d3dy5kYWlseW1vdGlvbi5jb20vZW1iZWQvdmlkZW8va3pJS2d2RjJpR0I1U3kyVjR2OCIgZnJhbWVib3JkZXI9IjAiIHdpZHRoPSI1NTAiIGhlaWdodD0iMzA5Ij48L2lmcmFtZT48L2NlbnRlcj48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VsZWN0aW9uLXByZXNpZGVudGllbGxlLW1vbi1pZGVlLXBvdXItMjAxMi02MTA5Mi8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbGVjdGlvbiBQcsOpc2lkZW50aWVsbGVdIE1vbiBpZMOpZSBwb3VyIDIwMTIgJiM4MjExOyBSZW5hdWQgQ2hhbXBpb24gLyBQcmltbmV4dDwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2VsZWN0aW9uLXByZXNpZGVudGllbGxlLW1vbi1pZGVlLXBvdXItMjAxMi1hcm5hdWQtcG9pc3Nvbm5pZXItYmFieWxvYW4tNjEwNzkvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRWxlY3Rpb24gUHLDqXNpZGVudGllbGxlXSBNb24gaWTDqWUgcG91ciAyMDEyICYjODIxMTsgQXJuYXVkIFBvaXNzb25uaWVyIC8gQmFieWxvYW48L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItbWFyYy10cmlsbGluZy1sb2dpY2EtYnVzaW5lc3MtY29uc3VsdGluZy02MTEwOC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbGVjdGlvbiBQcsOpc2lkZW50aWVsbGVdIE1vbiBpZMOpZSBwb3VyIDIwMTIgJiM4MjExOyBNYXJjIFRyaWxsaW5nIC8gTG9naWNhIEJ1c2luZXNzIENvbnN1bHRpbmc8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9lbGVjdGlvbi1wcmVzaWRlbnRpZWxsZS1tb24taWRlZS1wb3VyLTIwMTItbmljb2xhcy1nYXVtZS1zbmp2LTYxMTE1LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0VsZWN0aW9uIFByw6lzaWRlbnRpZWxsZV0gTW9uIGlkw6llIHBvdXIgMjAxMiAmIzgyMTE7IE5pY29sYXMgR2F1bWUgLyBTTkpWPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZWxlY3Rpb24tcHJlc2lkZW50aWVsbGUtbW9uLWlkZWUtcG91ci0yMDEyLWVtZXJ5LWRvbGlnZS01MDIwOC8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPltFbGVjdGlvbiBQcsOpc2lkZW50aWVsbGVdIE1vbiBpZMOpZSBwb3VyIDIwMTIgJiM4MjExOyBFbWVyeSBEb2xpZ8OpPC9hPjwvbGk%PC91bD48L2Rpdj5dXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2VsZWN0aW9uLXByZXNpZGVudGllbGxlLW1vbi1pZGVlLXBvdXItMjAxMi1lbW1hbnVlbC12aXZpZXItNjExMzEvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoNCgkJPHRpdGxlPltDb2ZmcmV0cyBjYWRlYXV4XSBZb3VrYWRvIGJvdWNsZSB1bmUgcHJlbWnDqHJlIGxldsOpZSBkZSBmb25kcyBkZSBwcsOocyBkZSAxLDUgbWlsbGlvbiBkJiM4MjE3O2V1cm9zPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyZW5jaHdlYi5mci9jb2ZmcmV0cy1jYWRlYXV4LXlvdWthZG8tYm91Y2xlLXVuZS1wcmVtaWVyZS1sZXZlZS1kZS1mb25kcy1kZS1wcmVzLWRlLTE1LW1pbGxpb24tZXVyb3MtNjExMzAvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyZW5jaHdlYi5mci9jb2ZmcmV0cy1jYWRlYXV4LXlvdWthZG8tYm91Y2xlLXVuZS1wcmVtaWVyZS1sZXZlZS1kZS1mb25kcy1kZS1wcmVzLWRlLTE1LW1pbGxpb24tZXVyb3MtNjExMzAvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAwNzoyNDowNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWV0dGUgUmF5bmFsPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtBY3R1XV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbYnVzaW5lc3NdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZUNvbW1lcmNlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0ludGVybmV0XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW0J0b0JdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbY29mZnJldF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtsZXbDqWVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbcGVyc29ubmFsaXNhdGlvbl1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtZb3VrYWRvXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvP3A9NTU1MDQ8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtZb3VrYWRvLCBwbGF0ZWZvcm1lIGRlIGNvZmZyZXRzIGNhZGVhdXggZW4gbGlnbmUsIHZpZW50IGRlIGZpbmFsaXNlciB1bmUgbGV2w6llIGRlIHByw6hzIGRlIDEsNU0g4oKsIGF1cHLDqHMgZOKAmWludmVzdGlzc2V1cnMgcHJvZmVzc2lvbm5lbHMsIGRvbnQgRmlub3JwYSwgZXQgZOKAmWludmVzdGlzc2V1cnMgcHJpdsOpcy4NCg0KRm9uZMOpZSBkw6lidXQgMjAwOSBwYXIgUGhpbGlwcGUgRGVzcHJldHMgZXQgU3TDqXBoYW5lIEZyZW15LCBsYSBzb2Npw6l0w6kgYSBkJiM4MjE3O2Fib3JkIGTDqXZlbG9wcMOpIHVuZSBvZmZyZSBncmFuZCBwdWJsaWMgZGVwdWlzIHNhIHBsYXRlZm9ybWUgZW4gbGlnbmUuIExhIHNvY2nDqXTDqSBzJiM4MjE3O2VzdCBlbnN1aXRlIGNvbmNlbnRyw6llIHN1ciB1biBzZWN0ZXVyIFsuLi5dXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGEgaHJlZj0iaHR0cDovL3d3dy55b3VrYWRvLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5Zb3VrYWRvLDwvYT4gcGxhdGVmb3JtZSBkZSBjb2ZmcmV0cyBjYWRlYXV4IGVuIGxpZ25lLCB2aWVudCBkZSBmaW5hbGlzZXIgdW5lIGxldsOpZSBkZSBwcsOocyBkZSAxLDVNIOKCrCBhdXByw6hzIGTigJlpbnZlc3Rpc3NldXJzIHByb2Zlc3Npb25uZWxzLCBkb250IDxhIGhyZWY9Imh0dHA6Ly93d3cuZmlub3JwYS5mci8iIHRhcmdldD0iX2JsYW5rIj5GaW5vcnBhPC9hPiwgZXQgZOKAmWludmVzdGlzc2V1cnMgcHJpdsOpcy48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PGEgaHJlZj0iaHR0cDovL3d3dy55b3VrYWRvLmNvbS8iPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtbWVkaXVtIHdwLWltYWdlLTU1NTEwIiB0aXRsZT0ieW91a2FkbyIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL3lvdWthZG8tNTUweDE2OC5qcGciIGFsdD0iIiB3aWR0aD0iNTUwIiBoZWlnaHQ9IjE2OCIgLz48L2E%PC9wPg0KPHA%Rm9uZMOpZSBkw6lidXQgMjAwOSBwYXIgUGhpbGlwcGUgRGVzcHJldHMgZXQgU3TDqXBoYW5lIEZyZW15LCBsYSBzb2Npw6l0w6kgYSBkJiM4MjE3O2Fib3JkIGTDqXZlbG9wcMOpIHVuZSBvZmZyZSBncmFuZCBwdWJsaWMgZGVwdWlzIHNhIHBsYXRlZm9ybWUgZW4gbGlnbmUuIExhIHNvY2nDqXTDqSBzJiM4MjE3O2VzdCBlbnN1aXRlIGNvbmNlbnRyw6llIHN1ciB1biBzZWN0ZXVyIEJ0b0IgZXQgYSByYXBpZGVtZW50IDxzcGFuIGlkPSJtb3JlLTU1NTA0Ij48L3NwYW4%YWZmaWNow6kgdW5lIGZvcnRlIHDDqW7DqXRyYXRpb24gc3VyIGxlIG1hcmNow6kgZHUgY2FkZWF1IGTigJlhZmZhaXJlcy48L3A%DQo8cD5Tb24gc3VjY8OocyBzdXIgY2Ugc2VnbWVudCBhIGRvbm7DqSBuYWlzc2FuY2UgZW4gMjAxMSDDoCBsYSBjcsOpYXRpb24gZGUgZGV1eCBww7RsZXMgb3JnYW5pc2F0aW9ubmVscyA6IFlvdWthZG8gQnVzaW5lc3MgU29sdXRpb25zLCBjb25jZXZhbnQgZGVzIHNvbHV0aW9ucyBjYWRlYXV4IHBvdXIgbGUgY29tcHRlIGRlIG1hcnF1ZXMgZXQgZGUgbGljZW5jZXMgZXQgWW91a2FkbyBwcm8sIHNww6ljaWFsaXN0ZSBkZSBsYSBzb2x1dGlvbiBjYWRlYXUgcGVyc29ubmFsaXPDqWUsIGTDqWRpw6llIMOgIGxhIGZvaXMgYXV4IMOpdsOpbmVtZW50cyBkZXMgY29taXTDqXMgZOKAmWVudHJlcHJpc2VzIGFpbnNpIHF14oCZYXV4IG9ww6lyYXRpb25zIGTigJlpbmNlbnRpdmUgZXQgZGUgcGFycmFpbmFnZSBwb3VyIGxlcyBlbnRyZXByaXNlcy48L3A%DQo8cD5MYSBsZXbDqWUgZGUgZm9uZHMgZG9pdCBwZXJtZXR0cmUgw6AgWW91a2FkbyBkJiM4MjE3O2FjY8OpbMOpcmVyIGxlIGTDqXZlbG9wcGVtZW50IGRlIHNlcyBhY3Rpdml0w6lzIGV0IGRlIHRvdWNoZXIgZGUgbm91dmVsbGVzIG1hcnF1ZXMgZXQgbGljZW5jZXMgaW5kdXN0cmllbGxlcy48L3A%DQo8ZGl2IGlkPSJjcnBfcmVsYXRlZCI%PGgzPkFydGljbGVzIHN1ciBsZSBtw6ptZSBzdWpldDwvaDM%PHVsPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2dyYWluZS1kZS1jYWRlYXV4LWxlLW5vdXZlbC1pbnZlc3Rpc3NlbWVudC1kZS1raW1hLXZlbnR1cmVzLyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%R3JhaW5lIGRlIENhZGVhdXgsIGxlIG5vdXZlbCBpbnZlc3Rpc3NlbWVudCBkZSBLaW1hIFZlbnR1cmVzPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvbm91dmVsbGUtbGV2ZWUtZGUtZm9uZC1wb3VyLWF0dHJhY3RpdmUtd29ybGQvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5Ob3V2ZWxsZSBsZXbDqWUgZGUgZm9uZCBwb3VyIEF0dHJhY3RpdmUgV29ybGQ8L2E%PC9saT48bGk%PGEgaHJlZj0iaHR0cDovL2ZyZW5jaHdlYi5mci9iaWxsZXR0ZXJpZS1lbi1saWduZS13ZWV6ZXZlbnQtZmluYWxpc2UtdW5lLXByZW1pZXJlLWxldmVlLWQtMS1taWxsaW9uLWV1cm9zLTYwMDg5LyIgcmVsPSJib29rbWFyayIgY2xhc3M9ImNycF90aXRsZSI%W0JpbGxldHRlcmllIGVuIGxpZ25lXSBXZWV6ZXZlbnQgZmluYWxpc2UgdW5lIHByZW1pw6hyZSBsZXbDqWUgZCYjODIxNzsxIG1pbGxpb24gZCYjODIxNztldXJvczwvYT48L2xpPjxsaT48YSBocmVmPSJodHRwOi8vZnJlbmNod2ViLmZyL2xldmVlLWRlLWZvbmRzLWRlLTExLW1pbGxpb25zLWRldXJvcy1wb3VyLWxlLWdyb3VwZS1lZGlsaXZyZS1pa2lvc3F1ZS8iIHJlbD0iYm9va21hcmsiIGNsYXNzPSJjcnBfdGl0bGUiPkxldsOpZSBkZSBmb25kcyBkZSAxLDEgbWlsbGlvbiBkJiM4MjE3O2V1cm9zIHBvdXIgbGUgZ3JvdXBlIEVkaWxpdnJlLWlLaW9zcXVlPC9hPjwvbGk%PGxpPjxhIGhyZWY9Imh0dHA6Ly9mcmVuY2h3ZWIuZnIvZXhjbHUta3dhZ2EtZWRpdGV1ci1kZS13cml0ZXRoYXQtbmFtZS1sZXZlLTEyLW1pbGxpb24tZXVyb3MtNjAwODgvIiByZWw9ImJvb2ttYXJrIiBjbGFzcz0iY3JwX3RpdGxlIj5bRXhjbHVdIEt3YWdhLCDDqWRpdGV1ciBkZSBXcml0ZVRoYXQubmFtZSBsw6h2ZSAxLDIgbWlsbGlvbiBk4oCZZXVyb3M8L2E%PC9saT48L3VsPjwvZGl2Pl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY29mZnJldHMtY2FkZWF1eC15b3VrYWRvLWJvdWNsZS11bmUtcHJlbWllcmUtbGV2ZWUtZGUtZm9uZHMtZGUtcHJlcy1kZS0xNS1taWxsaW9uLWV1cm9zLTYxMTMwL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjA8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoNCgk8L2NoYW5uZWw%DQo8L3Jzcz4NCg0KPCEtLSBEeW5hbWljIHBhZ2UgZ2VuZXJhdGVkIGluIDEwLjc3MiBzZWNvbmRzLiAtLT4NCg0KPCEtLSBDYWNoZWQgcGFnZSBnZW5lcmF0ZWQgYnkgV1AtU3VwZXItQ2FjaGUgb24gMjAxMi0wMy0zMCAxNzowMjoyNSAtLT4NCg"},{ name : "feed2", data : "s42006:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPlRlY2hDcnVuY2ggRnJhbmNlPC90aXRsZT4NCgk8YXRvbTpsaW5rIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS9mZWVkLyIgcmVsPSJzZWxmIiB0eXBlPSJhcHBsaWNhdGlvbi9yc3MreG1sIiAvPg0KCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbTwvbGluaz4NCgk8ZGVzY3JpcHRpb24%SnVzdCBhbm90aGVyIFdvcmRQcmVzcyBzaXRlPC9kZXNjcmlwdGlvbj4NCgk8bGFzdEJ1aWxkRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE0OjM3OjE3ICswMDAwPC9sYXN0QnVpbGREYXRlPg0KDQoJPGxhbmd1YWdlPmVuPC9sYW5ndWFnZT4NCgk8c3k6dXBkYXRlUGVyaW9kPmhvdXJseTwvc3k6dXBkYXRlUGVyaW9kPg0KCTxzeTp1cGRhdGVGcmVxdWVuY3k%MTwvc3k6dXBkYXRlRnJlcXVlbmN5Pg0KCTxnZW5lcmF0b3I%aHR0cDovL3dvcmRwcmVzcy5vcmcvP3Y9My4wPC9nZW5lcmF0b3I%DQoJCTxpdGVtPg0KCQk8dGl0bGU%UGl0Y2hleiBhdSBURUR4UGFyaXNVbml2ZXJzaXTDqXMgZXQgcGFydGV6IGVuIENhbGlmb3JuaWUgITwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9zaWxpY29uc2VudGllci5vcmcvcGl0Y2hlei1hdS10ZWR4cGFyaXN1bml2ZXJzaXRlcy1ldC1wYXJ0ZXotZW4tY2FsaWZvcm5pZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vc2lsaWNvbnNlbnRpZXIub3JnL3BpdGNoZXotYXUtdGVkeHBhcmlzdW5pdmVyc2l0ZXMtZXQtcGFydGV6LWVuLWNhbGlmb3JuaWUvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%TW9uLCAyMyBBcHIgMjAxMiAxMzozMzoxOCArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%U2lsaWNvbiBTZW50aWVyPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVthX2xhX3VuZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vc2lsaWNvbnNlbnRpZXIub3JnLz9wPTkwMzAxPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPHA%YXNzZXRzL1NpbGljb24tU2VudGllci5qcGc8L3A%DQpdXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD4mbmJzcDs8L3A%DQo8cD5Wb3VzIGF2ZXogdW5lIHN0YXJ0dXAgcXVpIHZhIGNoYW5nZXIgbGUgbW9uZGUgPyBTaWxpY29uIE1hbmlhY3Mgdm91cyBkb25uZSBsYSBjaGFuY2UgZGUgbW9udGVyIHN1ciBzY8OobmUgbGUgMTkgbWFpIHBvdXIgVEVEeFBhcmlzVW5pdmVyc2l0w6kuIEF1eCBjb3TDqXMgZOKAmcOpdHVkaWFudHMgZXQgZGUgZG9jdG9yYW50cyB0cmnDqXMgc3VyIGxlIHZvbGV0LCB2b3VzIHBvdXJyZXogcGl0Y2hlciB2b3RyZSBzdGFydHVwIGV0IHBldXQtw6p0cmUgZ2FnbmVyIHVuIGJpbGxldCBwb3VyIGxhIGNvbmbDqXJlbmNlIFRFRCDDoCBMb25nIEJlYWNoLCBlbiBDYWxpZm9ybmllICE8L3A%DQo8cD48c3Ryb25nPlBvdXIgcGFydGljaXBlciwgY%KAmWVzdCB0csOocyBzaW1wbGUsIGVudm95ZXogdW5lIHZpZMOpbyBkZSAzIG1pbnV0ZXMgYXZlYyB2b3RyZSBwaXRjaCDDoCA8YSBocmVmPSJtYWlsdG86Y29uY291cnNAc2lsaWNvbm1hbmlhY3Mub3JnP3N1YmplY3Q9Q29uY291cnMlMjBJLlQlMjBCb3lzJTIwJTJGJTIwR2lybHMlMjBDaGFsbGVuZ2UlMjAyMDEyJmFtcDtib2R5PVZvaWNpJTIwbW9uJTIwcGl0Y2glMjAlMjElMEEiPmNvbmNvdXJzQHNpbGljb25tYW5pYWNzLm9yZzwvYT4uIERhdGUgbGltaXRlLCBsZSAxZXIgbWFpIMOgIG1pbnVpdC4gTGVzIHZpZMOpb3Mgc2Vyb250IGVuc3VpdGUganVnw6llcyBwYXIgdW4ganVyeSBk4oCZZXhwZXJ0cyBkZXMgbm91dmVsbGVzIHRlY2hub2xvZ2llcyBldCBkZSBs4oCZaW5ub3ZhdGlvbjwvc3Ryb25nPi48L3A%DQo8cD4mbmJzcDs8L3A%DQo8cD48YSBocmVmPSJodHRwOi8vd3d3LnNpbGljb25tYW5pYWNzLm9yZy9pLXQtYm95cy1pLXQtZ2lybHMtY2hhbGxlbmdlLTIwMTItZ2FnbmUtdG9uLWJpbGxldC1wb3VyLWxvbmctYmVhY2gvIj5FbiBzYXZvaXIgcGx1czwvYT48L3A%DQo8cD4mbmJzcDs8L3A%DQo8cD4mbmJzcDs8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vc2lsaWNvbnNlbnRpZXIub3JnL3BpdGNoZXotYXUtdGVkeHBhcmlzdW5pdmVyc2l0ZXMtZXQtcGFydGV6LWVuLWNhbGlmb3JuaWUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5bRXhjbHVdIE15RVJQLmNvbSBsYW5jZSB1bmUgdmVyc2lvbiBkZSBzb24gYXBwbGljYXRpb24gZGUgZ2VzdGlvbiBjbG91ZCBkw6lkacOpZSBhdSBQTUUgYXUgVUs8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay88L2xpbms%DQoNCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2V4Y2x1LW15ZXJwLWNvbS1sYW5jZS11bmUtdmVyc2lvbi1kZS1zb24tYXBwbGljYXRpb24tZGUtZ2VzdGlvbi1jbG91ZC1kZWRpZWUtYXUtcG1lLWF1LXVrLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPldlZCwgMjggTWFyIDIwMTIgMTI6MjQ6MzMgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkF1cmVsaWUgUGVycnVjaGU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW215RVJQXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg5NzwvZ3VpZD4NCg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGEgaHJlZj0iaHR0cDovL215ZXJwLmNvbS8iIHRhcmdldD0iX3NlbGYiPk15RVJQLmNvbTwvYT4gZXN0IGxlIDxzdHJvbmc%cHJlbWllciBzZXJ2aWNlIGNsb3VkIGRlIGdlc3Rpb248L3N0cm9uZz4gw6AgZGVzdGluYXRpb24gZGVzIFBNRSwgbGEgc29jacOpdMOpIGxhbmNlIGF1am91cmQnaHVpIHVuZSB2ZXJzaW9uIGRlIHNvbiBhcHBsaWNhdGlvbiBzdXIgbGUgbWFyY2jDqSBicml0YW5uaXF1ZSBhbG9ycyBxdWUgc29uIGNvbmN1cnJlbnQgbG9jYWwgU0FHRSBuJ2EgdG91am91cnMgcGFzIGRlIHNvbHV0aW9uIGNsb3VkLiBMYW5jw6kgb2ZmaWNpZWxsZW1lbnQgZW4gPHN0cm9uZz5tYXJzIDIwMTA8L3N0cm9uZz4gYXZlYyBsZSBsYW5jZW1lbnQgZGUgR29vZ2xlIEFwcHMgTWFya2V0cGxhY2UsIG15RVJQIGNvbXB0ZSBwcsOocyBkZSA1MDAwMCBQTUUgw6AgdHJhdmVycyBwbHVzIGRlIDEwMCBwYXlzIGRpZmbDqXJlbnRzIHF1aSB1dGlsaXNlbnQgcsOpZ3VsacOocmVtZW50IGxhIHBsYXRlZm9ybWUgcG91ciBnw6lyZXIgdG91dGVzIGxlcyBhY3Rpdml0w6lzIGRlIGxldXIgc29jacOpdMOpIGRlcHVpcyBsZSBjbG91ZCA6IGxhIGNvbXB0YWJpbGl0w6kgZW4gbGlnbmUsIGxhIGZhY3R1cmF0aW9uLCBsZSBDUk0sIGxlcyBzdG9ja3MgZXQgYmllbiBwbHVzLCBsZSB0b3V0IGludMOpZ3LDqSBhdmVjIEdvb2dsZSBBcHBzLiBDJ2VzdCB1bmUgPGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTAvMDcvMTYvbGVzLWZyYW5jYWlzLWRlLWxhLXZhbGxleS10b3VyLWRob3J6b24tZGVzLXN0YXJ0dXBzLW91LWVudHJlcHJlbmV1cnMtZnJhbmNhaXMvIiB0YXJnZXQ9Il9ibGFuayI%c3RhcnR1cCBmcmFuw6dhaXNlIHBhcnRpZSBkYW5zIGxhIHNpbGljb24gVmFsbGV5PC9hPi5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48YSBocmVmPSJodHRwOi8vbXllcnAuY29tLyIgdGFyZ2V0PSJfc2VsZiI%TXlFUlAuY29tPC9hPiBlc3QgbGUgPHN0cm9uZz5wcmVtaWVyIHNlcnZpY2UgY2xvdWQgZGUgZ2VzdGlvbjwvc3Ryb25nPiDDoCBkZXN0aW5hdGlvbiBkZXMgUE1FLCBsYSBzb2Npw6l0w6kgbGFuY2UgYXVqb3VyZCYjODIxNztodWkgdW5lIHZlcnNpb24gZGUgc29uIGFwcGxpY2F0aW9uIHN1ciBsZSBtYXJjaMOpIGJyaXRhbm5pcXVlIGFsb3JzIHF1ZSBzb24gY29uY3VycmVudCBsb2NhbCBTQUdFIG4mIzgyMTc7YSB0b3Vqb3VycyBwYXMgZGUgc29sdXRpb24gY2xvdWQuIExhbmPDqSBvZmZpY2llbGxlbWVudCBlbiA8c3Ryb25nPm1hcnMgMjAxMDwvc3Ryb25nPiBhdmVjIGxlIGxhbmNlbWVudCBkZSBHb29nbGUgQXBwcyBNYXJrZXRwbGFjZSwgbXlFUlAgY29tcHRlIHByw6hzIGRlIDUwMDAwIFBNRSDDoCB0cmF2ZXJzIHBsdXMgZGUgMTAwIHBheXMgZGlmZsOpcmVudHMgcXVpIHV0aWxpc2VudCByw6lndWxpw6hyZW1lbnQgbGEgcGxhdGVmb3JtZSBwb3VyIGfDqXJlciB0b3V0ZXMgbGVzIGFjdGl2aXTDqXMgZGUgbGV1ciBzb2Npw6l0w6kgZGVwdWlzIGxlIGNsb3VkIDogbGEgY29tcHRhYmlsaXTDqSBlbiBsaWduZSwgbGEgZmFjdHVyYXRpb24sIGxlIENSTSwgbGVzIHN0b2NrcyBldCBiaWVuIHBsdXMsIGxlIHRvdXQgaW50w6lncsOpIGF2ZWMgR29vZ2xlIEFwcHMuIEMmIzgyMTc7ZXN0IHVuZSA8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMC8wNy8xNi9sZXMtZnJhbmNhaXMtZGUtbGEtdmFsbGV5LXRvdXItZGhvcnpvbi1kZXMtc3RhcnR1cHMtb3UtZW50cmVwcmVuZXVycy1mcmFuY2Fpcy8iIHRhcmdldD0iX2JsYW5rIj5zdGFydHVwIGZyYW7Dp2Fpc2UgcGFydGllIGRhbnMgbGEgc2lsaWNvbiBWYWxsZXk8L2E%LjwvcD4NCjxwPkwmIzgyMTc7b2ZmcmUgZGUgbXlFUlAgcGVybWV0IGF1eCBQTUUgZCYjODIxNzthY2hldGVyIHVuZSBzZXVsZSBhcHBsaWNhdGlvbiBzaW1wbGUgZXQgY29tcGzDqHRlIGF1IGxpZXUgZGUgbXVsdGlwbGVzIGFwcGxpY2F0aW9ucyBjaMOocmVzIGV0IGRpZmZpY2lsZXMgw6AgdXRpbGlzZXIuIEdyw6JjZSDDoCBzb24gaW50ZXJmYWNlIHNpbXBsZSBhdmVjIHVuZSBiYXJyZSBkZSBuYXZpZ2F0aW9uIMOgIGxhIEdvb2dsZSBldCBzb24gYWxnb3JpdGhtZSBpbnRlbGxpZ2VudCBldCBwcsOpZGljdGlmIHF1aSBhcnJpdmUgw6AgY29tcHJlbmRyZSBleGFjdGVtZW50IGNlIHF1ZSBsJiM4MjE3O3V0aWxpc2F0ZXVyIHNvdWhhaXRlIGZhaXJlLCBsJiM4MjE3O2FwcGxpY2F0aW9uIG15RVJQIG5lIG7DqWNlc3NpdGUgYXVjdW5lIGZvcm1hdGlvbiBhZmluIGRlIGwmIzgyMTc7dXRpbGlzZXIuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%PHN0cm9uZz5GcmFuw6dvaXMgTmFkYWw8L3N0cm9uZz4sIFBERyBkZSBteUVSUCwgZXhwbGlxdWUgbGUgbGFuY2VtZW50IGRlIGxhIHZlcnNpb24gYnJpdGFubmlxdWU6ICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBicml0YW5uaXF1ZSByZXByw6lzZW50ZSBzZWxvbiBub3MgZXN0aW1hdGlvbnMgbGUgNMOobWUgbWFyY2jDqSBsZSBwbHVzIGludMOpcmVzc2FudCBwb3VyIGxlcyBhcHBsaWNhdGlvbnMgY2xvdWQ8L2VtPiYjODIyMDsuIElsIHByw6ljaXNlIGVuIHBsdXMgcXVlICYjODIyMDs8ZW0%bGUgbWFyY2jDqSBVSyBlc3QgZG9taW7DqSBwYXIgbCYjODIxNzthY3RldXIgaGlzdG9yaXF1ZSwgU2FnZSwgcXVpIG4mIzgyMTc7YSBwYXMgc3UgcHJvcG9zZXIgw6Agc2VzIGNsaWVudHMgdW5lIHZlcnNpb24gY2xvdWQuIE5vdXMgZXN0aW1vbnMgcXUmIzgyMTc7ZW4gMjAxMSwgMzUlIGRlcyBlbnRyZXByaXNlcyBicml0YW5uaXF1ZXMgc291aGFpdGFpZW50IGTDqWrDoCBtaWdyZXIgbGV1ciBnZXN0aW9uIGRhbnMgbGUgY2xvdWQuIEVuIDIwMTIsIG15RVJQIGFycml2ZSBlbmZpbiBhdmVjIHVuZSBzb2x1dGlvbiBtYXR1cmUsIHJvYnVzdGUgZXQgc8OpY3VyaXPDqWUgcG91ciBhc3N1cmVyIGNldHRlIG1pZ3JhdGlvbi48L2VtPiYjODIyMDs8L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogbGVmdDsiPkwmIzgyMTc7b3V2ZXJ0dXJlIGR1IGNvbXB0ZSBteUVSUCBlc3QgZ3JhdHVpdCBhdmVjIGRlcyBmb25jdGlvbm5hbGl0w6lzIGlsbGltaXTDqWVzIHBvdXIgMSB1dGlsaXNhdGV1ci4gTGVzIG9mZnJlcyBwYXlhbnRlcyAmIzgyMjA7UHJlbWl1bSYjODIyMTsgc29udCBkaXNwb25pYmxlcyBwb3VyIDIgdXRpbGlzYXRldXJzIG91IDUgdXRpbGlzYXRldXJzLCBhdSBkZWzDoCwgbCYjODIxNzt1dGlsaXNhdGV1ciBzdXBwbMOpbWVudGFpcmUgZXN0IGZhY3R1csOpIDEy4oKsIHBhciBtb2lzLiBCb24gbGFuY2VtZW50ICE8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9leGNsdS1teWVycC1jb20tbGFuY2UtdW5lLXZlcnNpb24tZGUtc29uLWFwcGxpY2F0aW9uLWRlLWdlc3Rpb24tY2xvdWQtZGVkaWVlLWF1LXBtZS1hdS11ay9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4zPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkNpdGl2ZXJzaXR5LCBsZSBmZXUgZGUgY2FtcCAyLjA8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9jaXRpdmVyc2l0eS1sZS1mZXUtZGUtY2FtcC0yLTAvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%V2VkLCAyOCBNYXIgMjAxMiAxMjowODozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbY2l0eXZlcnNpdHldXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODg4PC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi4NCg0KUGVybWV0dHJlIMOgIGRlcyBwYXNzaW9ubsOpcyBkZSBwYXJ0YWdlciBsZXVyIGV4cMOpcmllbmNlIGF2ZWMgdW5lIHF1aW56YWluZSBkZSBwZXJzb25uZXMgZW4gZGV1eCBoZXVyZXMgZXQgZGFucyB1biBsaWV1IGFkYXB0w6ksIHRlbCBlc3QgbOKAmW9iamVjdGlmIHF1ZSBz4oCZZXN0IGZpeMOpIDxhIGhyZWY9Imh0dHA6Ly9jaXRpdmVyc2l0eS5ldmVudGJyaXRlLmNvbSI%IENpdGl2ZXJzaXR5PC9hPi4NCg0KVW4gb2JqZWN0aWYgcXVpIG7igJllc3QgcGFzIHNhbnMgcmFwcGVsZXIgY2VsdWkgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5za2lsbHNoYXJlLmNvbSI%U2tpbGxzaGFyZTwvYT4sIHN0YXJ0LXVwIG5ldy15b3JrYWlzZSBiaWVuIGNvbm51ZSBtYWlzIHF1aSBzb3VmZnJlIGRlIGxhIGxpYmVydMOpIGxhaXNzw6llIMOgIHNlcyB1dGlsaXNhdGV1cnMgOyBu4oCZaW1wb3J0ZSBxdWkgcG91dmFudCBwcm9wb3NlciB1biBjb3VycywgY29tbWVudCBzYXZvaXIgc2kgbGUgcHJvZmVzc2V1ciBzZXJhIGRlIHF1YWxpdMOpPyBDb21tZW50LCBwb3VyIGxlcyBwcm9mZXNzZXVycywgdHJvdXZlciBldCByw6lzZXJ2ZXIgdW5lIHNhbGxlIGFkYXB0w6llIHNhbnMgbWV0dHJlIGdyYXZlbWVudCBlbiBkYW5nZXIgbGEgcmVudGFiaWxpdMOpIGRlIGzigJlvcMOpcmF0aW9uID8gVGVsbGVzIHNvbnQgbGVzIHF1ZXN0aW9ucyBhdXhxdWVsbGVzIHLDqXBvbmQgQ2l0aXZlcnNpdHksIHF1aSBzw6lsZWN0aW9ubmUgbcOpdGljdWxldXNlbWVudCBzZXMgYW5pbWF0ZXVycyBldCBwcmVuZCBlbiBjaGFyZ2UgbOKAmWFzcGVjdCBsb2dpc3RpcXVlIGRlIGzigJlvcmdhbmlzYXRpb24gZGUgbOKAmWF0ZWxpZXIgKHVuIHNlcnZpY2UgcG91ciBsZXF1ZWwgQ2l0aXZlcnNpdHkgcHLDqWzDqHZlIDI1JSBkdSB0b3RhbCwgZnJhaXMgZOKAmW9yZ2FuaXNhdGlvbiBkw6lkdWl0cykuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0iY2l0eXZlcnNpdHkiIHNyYz0iaHR0cDovL2VibWVkaWEuZXZlbnRicml0ZS5jb20vczMtYnVpbGQvaW1hZ2VzLzEyNDA4NS8yNjcwNjI5OTU4NS8xL2xvZ28ucG5nIiBhbHQ9IiIgd2lkdGg9IjIyNSIgaGVpZ2h0PSI1NSIgLz5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5QZXJtZXR0cmUgw6AgZGVzIHBhc3Npb25uw6lzIGRlIHBhcnRhZ2VyIGxldXIgZXhww6lyaWVuY2UgYXZlYyB1bmUgcXVpbnphaW5lIGRlIHBlcnNvbm5lcyBlbiBkZXV4IGhldXJlcyBldCBkYW5zIHVuIGxpZXUgYWRhcHTDqSwgdGVsIGVzdCBs4oCZb2JqZWN0aWYgcXVlIHPigJllc3QgZml4w6kgPGEgaHJlZj0iaHR0cDovL2NpdGl2ZXJzaXR5LmV2ZW50YnJpdGUuY29tIj4gQ2l0aXZlcnNpdHk8L2E%LjwvcD4NCjxwPlVuIG9iamVjdGlmIHF1aSBu4oCZZXN0IHBhcyBzYW5zIHJhcHBlbGVyIGNlbHVpIGRlIDxhIGhyZWY9Imh0dHA6Ly93d3cuc2tpbGxzaGFyZS5jb20iPlNraWxsc2hhcmU8L2E%LCBzdGFydC11cCBuZXcteW9ya2Fpc2UgYmllbiBjb25udWUgbWFpcyBxdWkgc291ZmZyZSBkZSBsYSBsaWJlcnTDqSBsYWlzc8OpZSDDoCBzZXMgdXRpbGlzYXRldXJzIDsgbuKAmWltcG9ydGUgcXVpIHBvdXZhbnQgcHJvcG9zZXIgdW4gY291cnMsIGNvbW1lbnQgc2F2b2lyIHNpIGxlIHByb2Zlc3NldXIgc2VyYSBkZSBxdWFsaXTDqT8gQ29tbWVudCwgcG91ciBsZXMgcHJvZmVzc2V1cnMsIHRyb3V2ZXIgZXQgcsOpc2VydmVyIHVuZSBzYWxsZSBhZGFwdMOpZSBzYW5zIG1ldHRyZSBncmF2ZW1lbnQgZW4gZGFuZ2VyIGxhIHJlbnRhYmlsaXTDqSBkZSBs4oCZb3DDqXJhdGlvbiA:IFRlbGxlcyBzb250IGxlcyBxdWVzdGlvbnMgYXV4cXVlbGxlcyByw6lwb25kIENpdGl2ZXJzaXR5LCBxdWkgc8OpbGVjdGlvbm5lIG3DqXRpY3VsZXVzZW1lbnQgc2VzIGFuaW1hdGV1cnMgZXQgcHJlbmQgZW4gY2hhcmdlIGzigJlhc3BlY3QgbG9naXN0aXF1ZSBkZSBs4oCZb3JnYW5pc2F0aW9uIGRlIGzigJlhdGVsaWVyICh1biBzZXJ2aWNlIHBvdXIgbGVxdWVsIENpdGl2ZXJzaXR5IHByw6lsw6h2ZSAyNSUgZHUgdG90YWwsIGZyYWlzIGTigJlvcmdhbmlzYXRpb24gZMOpZHVpdHMpLjwvcD4NCjxwPlRyw6hzIGNlbnRyw6kgc3VyIGxhIHF1YWxpdMOpIGRlIGzigJnDqWNoYW5nZSwgQ2l0aXZlcnNpdHkgcsOqdmUgYWluc2kgZGUgZmFpcmUgw6ljbG9yZSBlbiBjaGFjdW4gbOKAmWVudmllIGRlIHBhcnRhZ2VyIGNlIHF1aSBsZSByZW5kIHVuaXF1ZSA6IHNvbiBleHDDqXJpZW5jZS4gQWluc2kgYS10LW9uIHB1IHBhcnRpY2lwZXIgZW4gTWFycyDDoCB1biBhdGVsaWVyIGRlIGTDqWNvdXZlcnRlIGR1IGJhbGxldCBhbmltw6kgcGFyIHVuZSBkYW5zZXVzZSBjbGFzc2lxdWUgY29uZmlybcOpZSwgb3Ugw6AgdW4gYXV0cmUgdmlzYW50IMOgIGZvcm1lciBsZXMgYXVkaXRldXJzIMOgIGzigJlhcnQgZGUgbOKAmWludGVydmlldyBwcm9wb3PDqSBwYXIgdW4gam91cm5hbGlzdGUgcmVub21tw6kuPC9wPg0KPHA%Rm9uZMOpIHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL2tuaWxmbyI%IEtleXZhbiBOaWxmb3JvdXNoYW4gPC9hPmFwcsOocyB1bmUgcHJlbWnDqHJlIGNhcnJpw6hyZSBkZSBWQyBjaGV6IE5leHRTdGFnZSwgQ2l0aXZlcnNpdHkgaWxsdXN0cmUgcGFyZmFpdGVtZW50IGRldXggY29uY2VwdHMgdHLDqHMgZW4gdm9ndWU6IGxlIDxlbT5sZWFuPC9lbT4gZXQgbGEgPGVtPmN1cmF0aW9uPC9lbT4uIERhbnMgdW4gcHJlbWllciB0ZW1wcywgQ2l0aXZlcnNpdHkgYSBlbiBlZmZldCBjaG9pc2kgZOKAmXV0aWxpc2VyIGxhIHNvbHV0aW9uIEV2ZW50YnJpdGUgKGFpbnNpIHF1ZSBNYWlsY2hpbXAgZXQgTGF1bmNocm9jaykgbGUgdGVtcHMgZGUgcHLDqWNpc2VyIHNvbiBtb2TDqGxlLiBCaWVuIGx1aSBlbiBhIHByaXMgYXV4IHZ1ZXMgZHUgc3VjY8OocyBkZXMgcHJlbWllcnMgYXRlbGllcnMsIHF1aSBvbnQgdmFsaWTDqSBzYSBjb252aWN0aW9uIHF14oCZaWwgeSBhIHVuZSB2w6lyaXRhYmxlIHZhbGV1ciBham91dMOpZSDDoCBuZSBwcm9wb3NlciBxdWUgZGVzIGV4cMOpcmllbmNlcyBxdWFsaXRhdGl2ZXMgKGxlIHRhcmlmIG1veWVuIMOpdGFudCBkZSA1MCBldXJvcyBwYXIgcGVyc29ubmUuKTwvcD4NCjxwPkVuIGF0dGVuZGFudCBsYSB2ZXJzaW9uIDIuMCwgZGUgbm9tYnJldXggYXRlbGllcnMgc29udCBkw6lqw6AgcHJvZ3JhbW3DqXMsIHBhcm1pIGxlc3F1ZWxzIMKrIEZhaXJlIHNlcyBjb3Vyc2VzIMOgIENoaW5hdG93biDCuywgwqsgUHJlbmRyZSBsZXMgbW9udW1lbnRzIHBhcmlzaWVucyBlbiBwaG90byDCuyBldCDCqyBMZSBwaWFubyBlbiA0IGhldXJlcyDCuyAoZW4gZGV1eCBwYXJ0aWVzKS48L3A%DQo8cD5Wb3VzIHLDqnZleiBk4oCZdW4gYXRlbGllciBlbiBwYXJ0aWN1bGllciA:IERlbWFuZGV6LWxlLCA8YSBocmVmPSJodHRwOi8vZmVlZGJhY2suY2l0aXZlcnNpdHkuY29tIj51bmUgcGFnZSBkw6lkacOpZTwvYT4gZXN0IGzDoCBwb3VyIMOnYS4gU2kgbGEgY29tbXVuYXV0w6kgdm90ZSBwb3VyIHZvdHJlIGlkw6llLCA8YSBocmVmPSJodHRwOi8vY2l0aXZlcnNpdHkuZXZlbnRicml0ZS5jb20iPiBDaXRpdmVyc2l0eTwvYT4gc2UgY2hhcmdlcmEgZGUgdHJvdXZlciBs4oCZaW50ZXJ2ZW5hbnQgaWTDqWFsLCBldCBkZSBkb25uZXIgdmllIMOgIGzigJlhdGVsaWVyLiAgRXQgdm91cywgcXXigJlhdmV6LXZvdXMgw6AgcGFydGFnZXIgPzwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCg0KCQk8dGl0bGU%TGUgSmV1ZGkgMTIgQXZyaWwsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHPigJlpbnZpdGVudCBhdSBQYWxhaXMgZGUgbGEgZMOpY291dmVydGU8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDIzOjAwOjMyICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5BdXJlbGllIFBlcnJ1Y2hlPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4Njg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvcmVzZWF1eC1zb2NpYXV4LmpwZyIgYWx0PSIiIHdpZHRoPSIyNzEiIGhlaWdodD0iMTQ4IiAvPkxlcyAxMiBldCAxMyBhdnJpbCAyMDEyLCBs4oCZVW5pdmVyc2l0w6kgZGUgVmVyc2FpbGxlcyBTYWludC1RdWVudGluLWVuLVl2ZWxpbmVzIG9yZ2FuaXNlIGF1IFBhbGFpcyBkZSBsYSBkw6ljb3V2ZXJ0ZSA8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCYjMzg7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPnVuPC9hPg0KPGEgdGl0bGU9IlLDqXNlYXV4IHNvY2lhdXgiIGhyZWY9Imh0dHA6Ly93d3cubm91dmVhdXhtZWRpYXMudXZzcS5mci9tZWRpYXBvbGlzLTE3NjA2My5ranNwP1JIPTEzMjc1MTgyMTM3OTAmIzM4O1JGPTEzMjczMTg3NzYwMzAiIHRhcmdldD0iX2JsYW5rIj5jb2xsb3F1ZSBjb25zYWNyw6kgYXV4IG5vdXZlYXV4IG3DqWRpYXM8L2E%LiBVbmUgdGFibGUgcm9uZGUgc3VyIGxhIHRow6ltYXRpcXVlIGRlIDxzdHJvbmc%bGEgY3VsdHVyZSBldCBkZXMgcsOpc2VhdXggc29jaWF1eDwvc3Ryb25nPiBlc3QNCnByb3Bvc8OpZSBsZSA8c3Ryb25nPmpldWRpIDEyIGF2cmlsIDIwMTIgZGUgOWgzMCDDoCAxMmgwMDwvc3Ryb25nPi4NCg0KRGVwdWlzIHBsdXNpZXVycyBhbm7DqWVzLCBsZXMgcsOpc2VhdXggc29jaWF1eCBzb250IGRldmVudXMgZGUgdsOpcml0YWJsZXMgb3V0aWxzIGRlIHBhcnRhZ2UuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IHNpemUtZnVsbCB3cC1pbWFnZS0yMzg2OSIgdGl0bGU9InJlc2VhdXggc29jaWF1eCIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL3Jlc2VhdXgtc29jaWF1eC5qcGciIGFsdD0iIiB3aWR0aD0iMjcxIiBoZWlnaHQ9IjE0OCIgLz5MZXMgMTIgZXQgMTMgYXZyaWwgMjAxMiwgbOKAmVVuaXZlcnNpdMOpIGRlIFZlcnNhaWxsZXMgU2FpbnQtUXVlbnRpbi1lbi1ZdmVsaW5lcyBvcmdhbmlzZSBhdSBQYWxhaXMgZGUgbGEgZMOpY291dmVydGUgPGEgdGl0bGU9IlLDqXNlYXV4IHNvY2lhdXgiIGhyZWY9Imh0dHA6Ly93d3cubm91dmVhdXhtZWRpYXMudXZzcS5mci9tZWRpYXBvbGlzLTE3NjA2My5ranNwP1JIPTEzMjc1MTgyMTM3OTAmYW1wO1JGPTEzMjczMTg3NzYwMzAiIHRhcmdldD0iX2JsYW5rIj51bjwvYT48YnIgLz4NCjxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJmFtcDtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%Y29sbG9xdWUgY29uc2FjcsOpIGF1eCBub3V2ZWF1eCBtw6lkaWFzPC9hPi4gVW5lIHRhYmxlIHJvbmRlIHN1ciBsYSB0aMOpbWF0aXF1ZSBkZSA8c3Ryb25nPmxhIGN1bHR1cmUgZXQgZGVzIHLDqXNlYXV4IHNvY2lhdXg8L3N0cm9uZz4gZXN0PGJyIC8%DQpwcm9wb3PDqWUgbGUgPHN0cm9uZz5qZXVkaSAxMiBhdnJpbCAyMDEyIGRlIDloMzAgw6AgMTJoMDA8L3N0cm9uZz4uPC9wPg0KPHA%RGVwdWlzIHBsdXNpZXVycyBhbm7DqWVzLCBsZXMgcsOpc2VhdXggc29jaWF1eCBzb250IGRldmVudXMgZGUgdsOpcml0YWJsZXMgb3V0aWxzIGRlIHBhcnRhZ2UuIERpZmZ1c2FudCBkZSBsYSBtdXNpcXVlLCBkZXMgZmlsbXMsIGRlcyByZXByw6lzZW50YXRpb25zIHRow6nDonRyYWxlcyBldCBiaWVuIGTigJlhdXRyZXMgY3LDqWF0aW9ucyBhcnRpc3RpcXVlcywgaWxzIHNvbnQgZOKAmWluY3JveWFibGVzIHBsYXRlZm9ybWVzIGTigJnDqWNoYW5nZSwgdW4gdsOpcml0YWJsZSB0cmVtcGxpbiBwb3VyIGxlcyBhcnRpc3RlcyBldCB1biBub3V2ZWF1IHZlY3RldXIgZGUgdHJhbnNtaXNzaW9uIGRlIGxhIGN1bHR1cmUuIERhbnMgdW5lIHNvY2nDqXTDqSBnb3V2ZXJuw6llIHBhciBsYSBjb21tdW5pY2F0aW9uIGV0IGxhIHJhcGlkaXTDqSBkZXMgw6ljaGFuZ2VzLCBsZXMgcHJhdGlxdWVzIGN1bHR1cmVsbGVzIG9udCBzdWJpIGxhIG11dGF0aW9uIGRlIGNldHRlIGluc3RhbnRhbsOpaXTDqSBhYnNvbHVlLiBFbiBxdWVscXVlcyBjbGljcywgbGVzIGludGVybmF1dGVzIHBldXZlbnQgYXVqb3VyZOKAmWh1aSBkw6ljb3V2cmlyIGRlcyB2aWTDqW9zIGV0IGRlcyBjb250ZW51cyBwdWJsacOpcyBzdXIgdG91cyBsZXMgY29udGluZW50cywgc291dGVuaXIgdW4gYXJ0aXN0ZSBxdeKAmWlscyBhZmZlY3Rpb25uZW50IGV0IGxpcmUgdW4gcm9tYW4gbnVtw6lyaXPDqSBlbiBsaWduZS48L3A%DQo8cD5MZXMgcsOpc2VhdXggc29jaWF1eCBhZ2lzc2VudCBjb21tZSBkZXMgcsOpdsOpbGF0ZXVycyBkZSB0YWxlbnRzIHBhciBsZSBiaWFpcyBkZXMgcGxhdGVmb3JtZXMgcGFydGljaXBhdGl2ZXMgZXQgcGVybWV0dGVudCDDoCBkZXMgYXJ0aXN0ZXMgZGUgc2UgZmFpcmUgY29ubmHDrnRyZSBkdSBwdWJsaWMgc2FucyBhdm9pciDDoCBzZSBzb3VtZXR0cmUgYXV4IGNlcmNsZXMgZGUgbMOpZ2l0aW1hdGlvbjxiciAvPg0KdHJhZGl0aW9ubmVscy4gQ2VwZW5kYW50LCDDqXZvcXVlciBs4oCZZXhwbG9pdGF0aW9uIGRlcyByw6lzZWF1eCBzb2NpYXV4IHBhciBsZXMgYXJ0aXN0ZXMgbsOpY2Vzc2l0ZSBkZSBz4oCZaW50ZXJyb2dlciBzdXIgbGV1ciBjb250csO0bGUgZXQgbOKAmWltcGFjdCBxdeKAmWlscyBzb250IHN1c2NlcHRpYmxlcyBk4oCZYXZvaXIgc3VyIGxlIGRyb2l0IGTigJlhdXRldXIgZXQgc3VyIGxhIHByb3ByacOpdMOpIGludGVsbGVjdHVlbGxlLjwvcD4NCjxwPlBvdXIgcsOpcG9uZHJlIMOgIGNlcyBxdWVzdGlvbnMgbm91dmVsbGVzLCBhdXRvdXIgZGUgY2V0dGUgdGFibGUgcm9uZGUgZGlmZsOpcmVudHMgc3DDqWNpYWxpc3RlcyBzZXJvbnQgcHLDqXNlbnRzIDogPHN0cm9uZz5KdWxpZW4gUkFTVEVHQVI8L3N0cm9uZz4gKGpvdXJuYWxpc3RlIHNjaWVudGlmaXF1ZSksIDxzdHJvbmc%Tmljb2xhcyBMT1VCRVQ8L3N0cm9uZz4gKGVudHJlcHJlbmV1ciBldCBjb25zdWx0YW50IFVtYXBzKTxiciAvPg0KPHN0cm9uZz5NYXJpbmUgSk9VQU48L3N0cm9uZz4gKGNoYXJnw6kgZGVzIHByb2pldHMgZGUgS2lzc0tpc3MgQmFua0JhbmspLCA8c3Ryb25nPkFteWxlZTwvc3Ryb25nPiAoYXJ0aXN0ZSBwbGFzdGljaWVubmUpIGV0IDxzdHJvbmc%TmF0aGFsaWUgRFJFWUZVUzwvc3Ryb25nPiAoanVyaXN0ZSkuPC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvbGUtamV1ZGktMTItYXZyaWwtbGVzLXJlc2VhdXgtc29jaWF1eC1zJWUyJTgwJTk5aW52aXRlbnQtYXUtcGFsYWlzLWRlLWxhLWRlY291dmVydGUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%MTwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoNCgkJPHRpdGxlPlNQRUFSIHByb2Zlc3Npb25uYWxpc2UgbGUgY3Jvd2RsZW5kaW5nIMOpdGhpcXVlPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvc3BlYXItcHJvZmVzc2lvbm5hbGlzZS1sZS1jcm93ZGxlbmRpbmctZXRoaXF1ZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy9zcGVhci1wcm9mZXNzaW9ubmFsaXNlLWxlLWNyb3dkbGVuZGluZy1ldGhpcXVlLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPlR1ZSwgMjcgTWFyIDIwMTIgMTY6MDg6NDkgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbY3Jvd2RsZW5kaW5nXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3NwZWFyXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg4MDwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW0FydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%Lg0KDQpJbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPkFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%LjwvcD4NCjxwPkludGVybmV0IHBlcm1ldCBkZSBjcsOpZXIgZGVzIGJhbnF1ZXMgbW9pbnMgY2jDqHJlcywgbWFpcyBhdXNzaSBkZXMgYmFucXVlcyBwbHVzIMOpdGhpcXVlcy4gQ%KAmWVzdCBlbiB0b3V0IGNhcyBsYSBjb252aWN0aW9uIGRlIDxhIGhyZWY9Imh0dHA6Ly9zcGVhci5mciI%U1BFQVI8L2E%IChTb2Npw6l0w6kgcG91ciB1bmUgw4lwYXJnbmUgQWN0aXZlbWVudCBSZXNwb25zYWJsZSksIGNvb3DDqXJhdGl2ZSBmb25kw6llIGF2YW50IG3Dqm1lIGxldXIgc29ydGllIGTigJnDqWNvbGUgcGFyIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9uaWNvZGFiYmFnaGlhbiI%Tmljb2xhcyBEYWJiYWdoaWFuPC9hPiAoSEVDKSwgPGEgaHJlZj0iaHR0cDovL3R3aXR0ZXIuY29tLyMhL3F1ZW50aW5iZGgiPlF1ZW50aW4gQnJhY2tlcnMgZGUgSHVnbzwvYT4gKENlbnRyYWxlIFBhcmlzKSBldCA8YSBocmVmPSIgaHR0cDovL3R3aXR0ZXIuY29tLyMhL2ZkZXNyb3ppZXJzICI%RnJhbsOnb2lzIERlc3JvemllcnM8L2E%IChEYXVwaGluZSkuPC9wPg0KPHA%U1BFQVIgcHJvcG9zZSBkZSBmw6lkw6lyZXIgbGVzIMOpcGFyZ25hbnRzIGFmaW4gZGUgbGV1ciBwZXJtZXR0cmUgZGUgbWV0dHJlIGxldXIgYXJnZW50IGF1IHNlcnZpY2UgZGUgcHJvamV0cyBxdeKAmWlscyBjaG9pc2lzc2VudCwgZXQgcXVpIG9udCBkdSBzZW5zIMOgIGxldXJzIHlldXggKMOpY29sb2dpcXVlcywgc29jaWF1eCBvdSBjdWx0dXJlbHMpLiDDgCBsYSBkaWZmw6lyZW5jZSBkZSBzdHJ1Y3R1cmVzIGNvbW1lIEtpY2tzdGFydGVyIG91IE15bWFqb3Jjb21wYW55LCBTUEVBUiBwcm9wb3NlIGTigJlpbnZlc3RpciBlbiBkZXR0ZSwgZXQgc8OpbGVjdGlvbm5lIGxlcyBpbml0aWF0aXZlcyBxdeKAmWlsIGVzdCBwb3NzaWJsZSBk4oCZYWlkZXIgZW4gZm9uY3Rpb24gZGUgY3JpdMOocmVzIMOpdGhpcXVlcyBldCBmaW5hbmNpZXJzLiAgTGUgdG91dCBzYW5zIGF1Y3VuIHJpc3F1ZSBwb3VyIGzigJnDqXBhcmduYW50LjwvcD4NCjxwPlBvdXIgcmVuZHJlIHBvc3NpYmxlIGNldHRlIMOpcXVhdGlvbiwgU1BFQVIgc%KAmWVzdCBhbGxpw6kgw6AgZGVzIGJhbnF1ZXMgKGxlIENyw6lkaXQgTXVuaWNpcGFsIGRlIFBhcmlzICBwb3VyIGxlIG1vbWVudCwgZGVzIHBhcnRlbmFyaWF0IGF2ZWMgbGUgQ3LDqWRpdCBDb29ww6lyYXRpZiBldCBsYSBDYWlzc2UgZOKAmSDDiXBhcmduZSBzb250IGVuIGJvbm5lIHZvaWUpIHF1aSBzw6ljdXJpc2VudCBsZSBwcsOqdCBtb3llbm5hbnQgdW5lIGNvbW1pc3Npb24gZGVzdGluw6llIMOgIGNvbXBlbnNlciBsZSByaXNxdWUgZGUgZMOpZmF1dC4gTOKAmWVudHJlcHJlbmV1ciBvYnRpZW50IGFpbnNpIGZhY2lsZW1lbnQgdW4gY3LDqWRpdCBwb3VyIHVuIHRhdXggaW5mw6lyaWV1ciBhdSB0YXV4IGR1IG1hcmNow6kgZXQgbOKAmcOpcGFyZ25hbnQsIG1veWVubmFudCB1bmUgbW9kaXF1ZSBkaW1pbnV0aW9uIGRlIHNvbiB0YXV4IGRlIHJlbmRlbWVudCwgbWV0IHNvbiBhcmdlbnQgYXUgc2VydmljZSBkZSBzZXMgY29udmljdGlvbnMuIFVuIGLDqW7DqWZpY2UgYXVxdWVsIHPigJlham91dGVudCBsZXMgY2xhc3NpcXVlcyBkaXNwb3NpdGlmcyBkZSBkw6lkdWN0aW9uIGRlIGzigJlJU0YgZXQgZGUgbOKAmUlSUFAsIHB1aXNxdWUgbOKAmcOpcGFyZ25lIHNlIHLDqWFsaXNlIHBhciBsYSBzb3VzY3JpcHRpb24gZGUgcGFydHMgc29jaWFsZXMgZGUgU1BFQVIuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPjwvcD4NCjxwPk1vaW5zIGRlIDE1JSBkZXMgcHJvamV0cyBzb3VtaXMgw6AgU1BFQVIgc29udCByZXRlbnVzIHBhciBzb24gY29taXTDqS4gUG91ciBsZSBtb21lbnQsIDIwMCAwMDAgZXVyb3MgZOKAmSDCqyDDqXBhcmduZSB0cmFuc3BhcmVudGUgwrsgb250IGZpbmFuY8OpcyAzIHByb2pldHMsIGV0IDIgc29udCBlbiBwYXNzZSBkZSBs4oCZw6p0cmUgKDxhIGhyZWY9Imh0dHA6Ly9zcGVhci5mci9wcm9qZXRzLzE2Ij4gQ2xhaXIgJmFtcDsgTmV0IDwvYT4sIGVudHJlcHJpc2UgZOKAmWluc2VydGlvbiBwYXIgbGUgdHJhdmFpbCBkYW5zIGxlIHNlY3RldXIgZGUgbOKAmcOpY29wcm9wcmV0w6kgZXQgPGEgaHJlZj0iaHR0cDovL3NwZWFyLmZyL3Byb2pldHMvMTgiPiBCYXNpbGlhZGUgPC9hPiwgc3RydWN0dXJlIGTigJlhaWRlIGF1eCBtYWxhZGVzIGR1IFNJREEpLiA1IGF1dHJlcyBsZXMgcmVqb2luZHJvbnQgZOKAmWljaSBs4oCZw6l0w6kgKHVuIHByb2pldCB2aXNhbnQgw6AgZm91cm5pciBkZXMgbHVuZXR0ZXMgZGUgcsOpYWxpdMOpIGF1Z21lbnTDqWUgYXV4IG1hbGFkZXMgY2hyb25pcXVlcyBpbW1vYmlsaXPDqXMgc2VyYWl0IG5vdGFtbWVudCBkYW5zIGxlcyB0dXlhdXgpLjwvcD4NCjxwPkF2aXMgYXV4IGdlZWtzIGF1IGdyYW5kIGPFk3VyIDogbGEgcGxhdGVmb3JtZSwgbGF1csOpYXRlIGR1IFByaXggU0ZSIEpldW5lcyBUYWxlbnRzIEVudHJlcHJlbmV1cmlhdCBTb2NpYWwsIGVzdCBjb2TDqWUgZW4gUnVieSBvbiBSYWlscy4gRXQgZGVzIHJlY3J1dGVtZW50cyBzb250IGF1IHByb2dyYW1tZeKApjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPldhbGxpdCBjcsOpZSBkZXMgbXVycyB2aXJ0dWVscyBlbiByw6lhbGl0w6kgYXVnbWVudMOpZSBkYW5zIGxlcyBsaWV1eCBwdWJsaWNzPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvd2FsbGl0LWNyZWUtZGVzLW11cnMtdmlydHVlbHMtZW4tcmVhbGl0ZS1hdWdtZW50ZWUtZGFucy1sZXMtbGlldXgtcHVibGljcy88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy93YWxsaXQtY3JlZS1kZXMtbXVycy12aXJ0dWVscy1lbi1yZWFsaXRlLWF1Z21lbnRlZS1kYW5zLWxlcy1saWV1eC1wdWJsaWNzLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPlR1ZSwgMjcgTWFyIDIwMTIgMDk6Mjk6MDYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbd2FsbGl0XV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg1MjwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9IndhbGxpdCIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL2xvZ29fd2FsbGl0X2ljb24uanBnIiBhbHQ9IiIgd2lkdGg9IjIzMiIgaGVpZ2h0PSI5MiIgLz4gQXJ0aWNsZSDDqWNyaXQgcGFyIDxhIGhyZWY9Imh0dHBzOi8vdHdpdHRlci5jb20vIyEvY2VjaWxvZ2UiIHRhcmdldD0iX2JsYW5rIj5Dw6ljaWxlIExvZ8OpPC9hPi4NCg0KQ3LDqcOpZSBwYXIgPGEgaHJlZj0iaHR0cDovL3d3dy5saW5rZWRpbi5jb20vcHViL3ZleXNlbC1iZXJrLzEwLzExMS8yMTIiPlZleXNlbCBCZXJrPC9hPiwgdW4gYW5jaWVuIGRlIFVDIEJlcmtlbGV5IHBsZWluIGTigJlpZMOpZXMgZXQgZMOpdGVudGV1ciBk4oCZdW4gUGhEIGVuIFBoeXNpcXVlLCA8YSBocmVmPSJodHRwOi8vd3d3LndhbGxpdGFwcC5jb20vIj5XYWxsaXQ8L2E%IGVzdCB1bmUgbm91dmVsbGUgYXBwbGljYXRpb24gaVBob25lIGdyYXR1aXRlIHF1aSBjaGVyY2hlIMOgIGNoYW5nZXIgbm90cmUgdmlzaW9uIGRlcyBsaWV1eCBwdWJsaWNzOiBsYW5jw6llIGTDqWJ1dCBtYXJzLCBs4oCZYXBwbGljYXRpb24gcGVybWV0IGRlIGNvbW11bmlxdWVyIGF2ZWMgbGVzIHBlcnNvbm5lcyBxdWkgc29udCBhdSBtw6ptZSBlbmRyb2l0IGF1IG3Dqm1lIG1vbWVudCBwYXIgbOKAmWludGVybcOpZGlhaXJlIGRlIGxhIHLDqWFsaXTDqSBhdWdtZW50w6llLl1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9IndhbGxpdCIgc3JjPSJhc3NldHMvZmVlZHNfaW1hZ2VzL2xvZ29fd2FsbGl0X2ljb24uanBnIiBhbHQ9IiIgd2lkdGg9IjIzMiIgaGVpZ2h0PSI5MiIgLz4gQXJ0aWNsZSDDqWNyaXQgcGFyIDxhIGhyZWY9Imh0dHBzOi8vdHdpdHRlci5jb20vIyEvY2VjaWxvZ2UiIHRhcmdldD0iX2JsYW5rIj5Dw6ljaWxlIExvZ8OpPC9hPi48L3A%DQo8cD5DcsOpw6llIHBhciA8YSBocmVmPSJodHRwOi8vd3d3LmxpbmtlZGluLmNvbS9wdWIvdmV5c2VsLWJlcmsvMTAvMTExLzIxMiI%VmV5c2VsIEJlcms8L2E%LCB1biBhbmNpZW4gZGUgVUMgQmVya2VsZXkgcGxlaW4gZOKAmWlkw6llcyBldCBkw6l0ZW50ZXVyIGTigJl1biBQaEQgZW4gUGh5c2lxdWUsIDxhIGhyZWY9Imh0dHA6Ly93d3cud2FsbGl0YXBwLmNvbS8iPldhbGxpdDwvYT4gZXN0IHVuZSBub3V2ZWxsZSBhcHBsaWNhdGlvbiBpUGhvbmUgZ3JhdHVpdGUgcXVpIGNoZXJjaGUgw6AgY2hhbmdlciBub3RyZSB2aXNpb24gZGVzIGxpZXV4IHB1YmxpY3M6IGxhbmPDqWUgZMOpYnV0IG1hcnMsIGzigJlhcHBsaWNhdGlvbiBwZXJtZXQgZGUgY29tbXVuaXF1ZXIgYXZlYyBsZXMgcGVyc29ubmVzIHF1aSBzb250IGF1IG3Dqm1lIGVuZHJvaXQgYXUgbcOqbWUgbW9tZW50IHBhciBs4oCZaW50ZXJtw6lkaWFpcmUgZGUgbGEgcsOpYWxpdMOpIGF1Z21lbnTDqWUuPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsiPC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGxlZnQ7Ij5FP24gZmFpdCwgV2FsbGl0IG3DqWxhbmdlIGxlcyB0cmFpdHMgZGVzIHBsdXMgZ3JhbmRzIHLDqXNlYXV4IHNvY2lhdXg6IGxlcyBpbnRlcmFjdGlvbnMgc29jaWFsZXMgZGUgRmFjZWJvb2ssIGxlcyAxNDAgY2FyYWN0w6hyZXMgbWF4aW11bSBkZSBUd2l0dGVyIGV0IGxhIGfDqW9sb2NhbGlzYXRpb24gZGUgRm91cnNxdWFyZSwgbGUgdG91dCBhcHBsaXF1w6kgw6AgZGVzIG11cnMgdmlydHVlbHMgYWNjZXNzaWJsZXMgZW4gcsOpYWxpdMOpIGF1Z21lbnTDqWUuIEltYWdpbm9ucyB1biDDqXbDqG5lbWVudCBpbXBvcnRhbnQgY29tbWUgdW4gbWF0Y2ggZGUgZm9vdCwgb3UgdW4gZmVzdGl2YWw6IGxlcyBwYXJ0aWNpcGFudHMgbuKAmWF1cm9udCBxdeKAmcOgIG91dnJpciBs4oCZYXBwbGljYXRpb24sIGV0IHNlIGfDqW9sb2NhbGlzZXIgcG91ciB2b2lyIGFwcGFyYWl0cmUgbGUgbXVyIHZpcnR1ZWwgw6AgdHJhdmVycyBsYSBjYW3DqXJhIGRlIGxldXIgaVBob25lIGV0IGNvbW11bmlxdWVyIGVudHJlIGV1eC4gUGhvdG9zLCBjb21tZW50YWlyZXMsIHZpZMOpb3MsIG91IG1lc3NhZ2VzIGF1ZGlvcy4uIFRvdXQgZXN0IHBvc3NpYmxlITwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48L3A%DQo8cD5XYWxsaXQgYSBkw6lqw6AgY3LDqcOpIHBsdXMgZGUgNzAwIG11cnMgdW4gcGV1IHBhcnRvdXQgZGFucyBsZSBtb25kZSAoTG9uZHJlcywgVG9reW8sIE5ldy1Zb3JrLCBQYXJpcy4uKS4gVW5lIGZvaXMgc3VyIHBsYWNlLCBvbiBwZXV0IGFwcG9ydGVyIHNhIGNvbnRyaWJ1dGlvbiBzb2l0IGFub255bWVtZW50LCBzb2l0IGVuIHNlIGxvZ2dhbnQgc3VyIEZhY2Vib29rIG91IFR3aXR0ZXI6IGJpZW50w7R0LCBkZXMgZm9uY3Rpb25zIHNvY2lhbGVzIHBlcm1ldHRhbnQgZGUgZmlsdHJlciBsZXMgcG9zdHMgKGFtaXMgRmFjZWJvb2sgIHNldWxlbWVudCBwYXIgZXhlbXBsZSkgc2Vyb250IMOpZ2FsZW1lbnQgZGlzcG9uaWJsZXMuPC9wPg0KPHA%QWxvcnMgcXVlIGxlcyBhdXRyZXMgYXBwcyBnw6lvbG9jYWxpc8OpZXMgZXQgbGVzIHLDqXNlYXV4IHNvY2lhdXggY29tbWUgRm91cnNxdWFyZSBzZSBmb2NhbGlzZW50IGfDqW7DqXJhbGVtZW50IHN1ciBsZXMgcHJvZmlscyBkZXMgdXRpbGlzYXRldXJzLCBjZWxsZS1jaSBhbWJpdGlvbm5lIGRlIGRvbm5lciB2aWUgYXV4IGxpZXV4IGV1eC1tw6ptZXMgZ3LDomNlIMOgIGxldXJzIHZpc2l0ZXVycy4gQmVyayBpbnNpc3RlIGTigJlhaWxsZXVycyBzdXIgbOKAmWlkw6llIHF1ZSBXYWxsaXQg4oCcPGVtPmNvbnRyaWJ1ZSDDoCBlbnRyZXRlbmlyIGzigJllc3NlbmNlIGRlcyBsaWV1eDwvZW0%4oCdIGV0IMOgIOKAnDxlbT5jdWx0aXZlciBsZXVyIHBlcnNvbm5hbGl0w6k8L2VtPuKAnSBncsOiY2UgYXUgcGFydGFnZSBk4oCZZXhww6lyaWVuY2VzLCBkZSBwaG90b3MsIGRlIGNvbW1lbnRhaXJlcyBkZXMgZ2VucyBxdWkgeSBwYXNzZW50IHBoeXNpcXVlbWVudC48L3A%DQo8cD48aWZyYW1lIHdpZHRoPSI1NjAiIGhlaWdodD0iMzE1IiBzcmM9Imh0dHA6Ly93d3cueW91dHViZS5jb20vZW1iZWQvTXgxQ3kzc21ScjAiIGZyYW1lYm9yZGVyPSIwIiBhbGxvd2Z1bGxzY3JlZW4%PC9pZnJhbWU%PC9wPg0KPHA%V2FsbGl0IGEgcsOpY2VtbWVudCBsZXbDqSAxLjJNJCBkZSBmb25kcyBhdXByw6hzIGRlIGRpZmbDqXJlbnRzIGJ1c2luZXNzIGFuZ2VscyBldCBmb25kcyBk4oCZaW52ZXN0aXNzZW1lbnRzLCBldCBkZXMgdmVyc2lvbnMgaVBhZCBldCBBbmRyb2lkIHNvbnQgZW4gY291cnMgZGUgZMOpdmVsb3BwZW1lbnQuIElsIHPigJlhZ2lyYSBlbnN1aXRlIGRlIG1vbsOpdGlzZXIgbGUgcHJvamV0IGVuIGltcGxpcXVhbnQgZGVzIHBhcnRlbmFpcmVzIGV0IGRlcyBncmFuZGVzIG1hcnF1ZXMsIG5vdGFtbWVudCBlbiBsZXMgYWlkYW50IMOgIGNyw6llciBsZXVycyBwcm9wcmVzIG11cnMvcGFubmVhdXggZGUgcHViIGludGVyYWN0aWZzIGV0IHZpcnR1ZWxzLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3dhbGxpdC1jcmVlLWRlcy1tdXJzLXZpcnR1ZWxzLWVuLXJlYWxpdGUtYXVnbWVudGVlLWRhbnMtbGVzLWxpZXV4LXB1YmxpY3MvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%NDwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPlNjaWVudGlwb2xlIEluaXRpYXRpdmUgZsOqdGUgc2VzIDEwIGFuczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPk1vbiwgMjYgTWFyIDIwMTIgMDk6MTg6MjYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc2NpZW50aXBvbGUgaW5pdGlhdGl2ZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4NDE8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vMTBhbnMtc2NpZW50aXBvbGUtaW5pdGlhdGl2ZS5vcmciPlNjaWVudGlww7RsZSBJbml0aWF0aXZlPC9hPiBlc3QgdW5lIGFzc29jaWF0aW9uIGRvbnQgbGUgYnV0IGVzdCBkZSBmaW5hbmNlciBsZXMgc3RhcnR1cHMgaW5ub3ZhbnRlcyBlbiBJbGUgZGUgRnJhbmNlLiBNZW1icmUgZGUgRnJhbmNlIEluaXRpYXRpdmUsIHByZW1pZXIgcsOpc2VhdSBkZSBmaW5hbmNlbWVudCBldCBk4oCZYWNjb21wYWduZW1lbnQgZGVzIGVudHJlcHJpc2VzIGVuIEZyYW5jZSwgU2NpZW50aXDDtGxlIEluaXRpYXRpdmUgYXBwb3J0ZSB1bmUgc29sdXRpb24gZGUgZmluYW5jZW1lbnQgcGFyIGxlIGJpYWlzIGR1IHByw6p0IGTigJlob25uZXVyIGRlcHVpcyAxMCBhbnMgIQ0KXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICE8L3A%DQo8cD5MZSBwcsOqdCBk4oCZaG9ubmV1ciBlc3QgdW4gcHLDqnQgw6AgdGF1eCAwIHF1ZSBwZXV0IHJlY2V2b2lyIHRvdXQgY3LDqWF0ZXVyIGTigJllbnRyZXByaXNlLCBzYW5zIGdhcmFudGllIHBlcnNvbm5lbGxlIGV0IGRvbnQgbGUgbW9udGFudCBwZXV0IGFsbGVyIGp1c3F14oCZw6AgNjAgMDAwIGV1cm9zIHBhciBlbnRyZXByaXNlLiBM4oCZb2JqZWN0aWYgZHUgcHLDqnQgZOKAmWhvbm5ldXIgZXN0IGTigJlhbW9yY2VyIGxhIGNvbW1lcmNpYWxpc2F0aW9uIGTigJl1biBwcm9kdWl0IG91IGTigJl1bmUgdGVjaG5vbG9naWUgZW4gdnVlIGTigJl1biBlZmZldCBkZSBsZXZpZXIgcG91ciBs4oCZb2J0ZW50aW9uIGRlIHByw6p0cyBiYW5jYWlyZXMuPC9wPg0KPHA%UG91ciBwcsOpdGVuZHJlIMOgIGNlIHR5cGUgZGUgcHLDqnQsIGwmIzgyMTc7ZW50cmVwcmlzZSBkb2l0IGF2b2lyIG1vaW5zIGRlIDMgYW5zLCDDqnRyZSBpbnN0YWxsw6llIGVuIElsZSBkZSBGcmFuY2UsIHByb3Bvc2VyIHVuZSBpbm5vdmF0aW9uLCBldCBwb3Nzw6lkZXIgdW4gcG90ZW50aWVsIGRlIGNyw6lhdGlvbnMgZCYjODIxNztlbXBsb2lzLjwvcD4NCjxwPlBvdXIgZsOqdGVyIHNhIDEww6htZSBhbm7DqWUgZGUgc291dGllbiBhdXggc3RhcnQgdXAsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIG9yZ2FuaXNlIHVuIMOpdsOobmVtZW50IGRlIDE0aCDDoCAxOWggbGUgMjggTWFycyDDoCBs4oCZaMO0dGVsIGRlIHZpbGxlIGRlIFBhcmlzLiBMZSA8YSBocmVmPSJodHRwOi8vd3d3LjEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnL3Byb2dyYW1tZS5odG1sIj5wcm9ncmFtbWU8L2E%IGFubm9uY2UgbGEgdmVudWUgZGUgUmFvdWwgTWFsbGFydCwgRGlyZWN0ZXVyIEJ1c2luZXNzIERldmVsb3BwZW1lbnQgZCYjODIxNztBcmNob3MsIG91IGVuY29yZSBkZSBSYWZpIEhhbGFkamlhbiwgZm9uZGF0ZXVyIGRlIE5hYmF6dGFnLiBMZXMgaW5zY3JpcHRpb25zIHNvbnQgPGEgaHJlZj0iaHR0cDovL3d3dy4xMGFucy1zY2llbnRpcG9sZS1pbml0aWF0aXZlLm9yZy9pbnNjcmlwdGlvbi5odG1sIj5pY2k8L2E%IGV0IGwmIzgyMTc7YWN0dWFsaXTDqSBkdSBTY2llbnRpcG9sZSBlc3QgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9TY2llbnRJbml0aWF0aXYiPmzDoC4gPC9hPjwvcD4NCjxwPjxpZnJhbWUgd2lkdGg9IjU2MCIgaGVpZ2h0PSIzMTUiIHNyYz0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9lbWJlZC9DcVYwVW82SDFiVSIgZnJhbWVib3JkZXI9IjAiIGFsbG93ZnVsbHNjcmVlbj48L2lmcmFtZT48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNi9zY2llbnRpcG9sZS1pbml0aWF0aXZlLWZldGUtc2VzLTEwLWFucy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%VENGUiDigJMgTGUgemFwcGluZyBkZSBsYSBzZW1haW5lPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAyMyBNYXIgMjAxMiAxODoyNDozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%Q2VkcmljIE8nTmVpbGw8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3RhcnR1cF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0Y2ZyXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3phcHBpbmddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODMyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQnYXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuDQoNCi0gQW50b2luZSBWaWFsbGUsIHNlcmlhbCBlbnRyZXByZW5ldXIgdmllbnQgZGUgY2FydG9ncmFwaGllciBsZXMgYWlkZXMgZXQgc3VidmVudGlvbnMgZGlzcG9uaWJsZXMgZW4gRnJhbmNlIHBvdXIgbGVzIGNyw6lhdGV1cnMgZCdlbnRyZXByaXNlLiBDaGFxdWUgbGlnbmUgY29ycmVzcG9uZCBhdSBuaXZlYXUgZGUgbWF0dXJpdMOpIGQndW5lIHNvY2nDqXTDqS4gVm91cyBwb3VycmV6IGxhIHJldHJvdXZlciDDoCA8YSBocmVmPSJodHRwOi8vd3d3LmFpZGVzLWNyZWF0aW9uLmZyL29mZnJlLXNwZWFjdXRlY2lhbGUtaW50ZXJuZXQuaHRtbCI%Y2V0dGUgYWRyZXNzZTwvYT4uXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%TGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQmIzgyMTc7YXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuPC9wPg0KPHA%LSBBbnRvaW5lIFZpYWxsZSwgc2VyaWFsIGVudHJlcHJlbmV1ciB2aWVudCBkZSBjYXJ0b2dyYXBoaWVyIGxlcyBhaWRlcyBldCBzdWJ2ZW50aW9ucyBkaXNwb25pYmxlcyBlbiBGcmFuY2UgcG91ciBsZXMgY3LDqWF0ZXVycyBkJiM4MjE3O2VudHJlcHJpc2UuIENoYXF1ZSBsaWduZSBjb3JyZXNwb25kIGF1IG5pdmVhdSBkZSBtYXR1cml0w6kgZCYjODIxNzt1bmUgc29jacOpdMOpLiBWb3VzIHBvdXJyZXogbGEgcmV0cm91dmVyIMOgIDxhIGhyZWY9Imh0dHA6Ly93d3cuYWlkZXMtY3JlYXRpb24uZnIvb2ZmcmUtc3BlYWN1dGVjaWFsZS1pbnRlcm5ldC5odG1sIj5jZXR0ZSBhZHJlc3NlPC9hPi48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cueW91c2VlbWlpLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPllvdXNlZW1paSA8L2E%cHLDqXNlbnRlIHNhIG5vdXZlbGxlIHZlcnNpb24sIGF2ZWMgdW4gbm91dmVhdSBkZXNpZ24sIGV0IHN1cnRvdXQgdW5lIG5vdXZlbGxlIGV4cMOpcmllbmNlIHV0aWxpc2F0ZXVyLiBEw6lzb3JtYWlzLCBsZSBsb2dpY2llbCBwZXJtZXQgYXVzc2kgZCYjODIxNzthbmFseXNlciBzYSBwcsOpc2VuY2Ugd2ViIHN1ciBGb3Vyc3F1YXJlLCBHb29nbGUgKywgRGFpbHltb3Rpb24sIFZpbWVvLCBldCBtw6ptZSBhdXByw6hzIGRlcyBraW9zcXVlcyBSZWxheS48L3A%DQo8cD4tTGUgcsOpc2VhdSBzb2NpYWwgbW9iaWxlIDxhIGhyZWY9Imh0dHBzOi8vcGF0aC5jb20vIj5QYXRoPC9hPiBsw6h2ZSAyMCBtaWxsaW9ucyBkZSBkb2xsYXJzLiBMZSByw6lzZWF1IHNvY2lhbCBkZSBwYXJ0YWdlIGRlIHBob3RvcyBsaW1pdMOpIMOgIDUwIGNvbnRhY3RzIGV0IGRpc3BvbmlibGUgZXhjbHVzaXZlbWVudCBzdXIgbOKAmWFwcGxpIGlQaG9uZSBkdSBtw6ptZSBub20gc2VyYWl0IGFpbnNpIHZhbG9yaXPDqSAyNTBNJC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmVkeWNhc2EuY29tLyI%QmVkeUNhc2E8L2E%IGdhZ25lIGxlcyBUcmF2ZWwgZOKAmU9yIGRhbnMgbGEgY2F0w6lnb3JpZSBzdGFydC11cCwgcXVpIHLDqWNvbXBlbnNlIGxlcyBtZWlsbGV1cnMgc2l0ZXMgZOKAmWUtdG91cmlzbWUuIEJlZHljYXNhLCBwZXJtZXQgbGEgbG9jYXRpb24gZGUgY2hhbWJyZXMgY2hleiBs4oCZaGFiaXRhbnQuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHBzOi8vc2Vlc21pYy5jb20vIj5TZWVzbWljPC9hPiBhbm5vbmNlIHVuZSB2YWd1ZSBkZSBsaWNlbmNpZW1lbnRzLiBMYSBzdGFydC11cCBmb25kw6llIHBhciA8c3Ryb25nPkxvw69jIExlIE1ldXI8L3N0cm9uZz4sIG9yZ2FuaXNhdGV1ciBkZSBsYSBjb25mw6lyZW5jZSA8c3Ryb25nPkxlV2ViPC9zdHJvbmc%IGRldnJhaXQgbGljZW5jaWVyIDE4IHBlcnNvbm5lcyBmYXV0ZSBkZSBidXNpbmVzcyBtb2RlbCB2aWFibGUuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHA6Ly93d3cuZWFzeS12ZXJyZXMuY29tLyI%RWFzeS12ZXJyZXM8L2E%LCBs4oCZb3B0aWNpZW4gbG93IGNvc3QgcXVpIGNvbXB0ZXJhaXQgcHLDqHMgZGUgNzUwIG9wdGljaWVucyBwYXJ0ZW5haXJlcyB2aWVudCBkZSBsZXZlciAxTeKCrC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuaWxsaWNvdHJhdmVsLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5pbGxpY290cmF2ZWw8L2E%LCBsZSBjb21wYXJhdGV1ciBkZSB2b2xzIGV0IGRlIHZveWFnZXMgb25saW5lIHZpZW50IGRlIGxhbmNlciB1bmUgbm91dmVsbGUgdmVyc2lvbiBkZSBzb24gaW50ZXJmYWNlLjwvcD4NCjxwPi08c3Ryb25nPiA8YSBocmVmPSJodHRwOi8vd3d3LnJveWFsY2FjdHVzLmNvbS8iPlJveWFsIENhY3R1czwvYT48L3N0cm9uZz4sIHNww6ljaWFsaXN0ZSBkdSBqZXUgZW4gbGlnbmUgY29tbXVuYXV0YWlyZSwgdmllbnQgZGUgbGV2ZXIgNTAwIDAwMCBldXJvcyBhdXByw6hzIGR1IGZvbmRzIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnQgPHN0cm9uZz5YQW5nZSBQcml2YXRlIEVxdWl0eTwvc3Ryb25nPi4gT2JqZWN0aWYgYWZmaWNow6kgOiBkZXZlbmlyIHVuIGRlcyBsZWFkZXJzIGZyYW7Dp2FpcyBkdSBTb2NpYWwgR2FtaW5nIGVuIG1lbmFudCB1bmUgc3RyYXTDqWdpZSBjcm9zcy1jaGFubmVsLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzIzL3RjZnItJWUyJTgwJTkzLWxlLXphcHBpbmctZGUtbGEtc2VtYWluZS0yL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgk8L2NoYW5uZWw%DQo8L3Jzcz4NCg"},{ name : "feed1", data : "s68627:PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4NCjxyc3MgdmVyc2lvbj0iMi4wIg0KCXhtbG5zOmNvbnRlbnQ9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvY29udGVudC8iDQoJeG1sbnM6d2Z3PSJodHRwOi8vd2VsbGZvcm1lZHdlYi5vcmcvQ29tbWVudEFQSS8iDQoJeG1sbnM6ZGM9Imh0dHA6Ly9wdXJsLm9yZy9kYy9lbGVtZW50cy8xLjEvIg0KCXhtbG5zOmF0b209Imh0dHA6Ly93d3cudzMub3JnLzIwMDUvQXRvbSINCgl4bWxuczpzeT0iaHR0cDovL3B1cmwub3JnL3Jzcy8xLjAvbW9kdWxlcy9zeW5kaWNhdGlvbi8iDQoJeG1sbnM6c2xhc2g9Imh0dHA6Ly9wdXJsLm9yZy9yc3MvMS4wL21vZHVsZXMvc2xhc2gvIg0KCT4NCg0KPGNoYW5uZWw%DQoJPHRpdGxlPlRlY2hDcnVuY2ggRnJhbmNlPC90aXRsZT4NCgk8YXRvbTpsaW5rIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS9mZWVkLyIgcmVsPSJzZWxmIiB0eXBlPSJhcHBsaWNhdGlvbi9yc3MreG1sIiAvPg0KCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbTwvbGluaz4NCgk8ZGVzY3JpcHRpb24%SnVzdCBhbm90aGVyIFdvcmRQcmVzcyBzaXRlPC9kZXNjcmlwdGlvbj4NCgk8bGFzdEJ1aWxkRGF0ZT5GcmksIDMwIE1hciAyMDEyIDE0OjM3OjE3ICswMDAwPC9sYXN0QnVpbGREYXRlPg0KDQoJPGxhbmd1YWdlPmVuPC9sYW5ndWFnZT4NCgk8c3k6dXBkYXRlUGVyaW9kPmhvdXJseTwvc3k6dXBkYXRlUGVyaW9kPg0KCTxzeTp1cGRhdGVGcmVxdWVuY3k%MTwvc3k6dXBkYXRlRnJlcXVlbmN5Pg0KCTxnZW5lcmF0b3I%aHR0cDovL3dvcmRwcmVzcy5vcmcvP3Y9My4wPC9nZW5lcmF0b3I%DQoJCTxpdGVtPg0KCQk8dGl0bGU%W0Nocm9uaXF1ZV0gRGlnaXRhbCBtdXNpYyAjMzI8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnJlbmNod2ViLmZyL2Nocm9uaXF1ZS1kaWdpdGFsLW11c2ljLTMyLTYxMzgxLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mcmVuY2h3ZWIuZnIvY2hyb25pcXVlLWRpZ2l0YWwtbXVzaWMtMzItNjEzODEvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAyNyBBcHIgMjAxMiAwOTozNzoxMyArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%TGF1cmUgRGVjYWlsbHk8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW0FjdHVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbSW50ZXJuZXRdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbQmVsaWV2ZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtpdHVuZXNdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbamFtZW5kb11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVttdXNpcXVlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1JpZmZ4XV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW1Nwb3RpZnldXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyZW5jaHdlYi5mci8:cD01OTU1NTwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBW05ld3MgZMOpY2Fsw6llcywgdmlkw6lvcyBtdXNpY2FsZXMgZXQgY29uY2VydHMgaW5kw6lz4oCmQ%KAmWVzdCBsYSBjaHJvbmlxdWUgbXVzaXF1ZSBGcmVuY2h3ZWIgZGUgbGEgc2VtYWluZSAhIEF1IHNvbW1haXJlIDogSmFtZW5kbyBmYWl0IHBlYXUgbmV1dmUsIE9yYW5nZSBSb2NrQ29ycHMgdGVzdGUgc29uIDFlciBjb25jZXJ0IGNvbGxhYm9yYXRpZiBhdmVjIFRoZSBUaW5nIFRpbmdzLCBsZSBDcsOpZGl0IE11dHVlbCBsYW5jZSBzb24gMWVyIHLDqXNlYXUgc29jaWFsIG11c2ljYWwsIFNwb3RpZnkgZXQgVGhlIENvY2EgQ29sYSBDb21wYW55IHNpZ25lbnQgdW4gcGFydGVuYXJpYXQgc3RyYXTDqWdpcXVlIHDDqXRpbGxhbnQsIEJlbGlldmUgRGlnaXRhbCBtaXNlIChwcmVzcXVlIFsuLi5dXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%TmV3cyBkw6ljYWzDqWVzLCB2aWTDqW9zIG11c2ljYWxlcyBldCBjb25jZXJ0cyBpbmTDqXPigKZD4oCZZXN0IGxhIGNocm9uaXF1ZSBtdXNpcXVlIEZyZW5jaHdlYiBkZSBsYSBzZW1haW5lICEgPGJyIC8%QXUgc29tbWFpcmUgOiBKYW1lbmRvIGZhaXQgcGVhdSBuZXV2ZSwgT3JhbmdlIFJvY2tDb3JwcyB0ZXN0ZSBzb24gMWVyIGNvbmNlcnQgY29sbGFib3JhdGlmIGF2ZWMgVGhlIFRpbmcgVGluZ3MsIGxlIENyw6lkaXQgTXV0dWVsIGxhbmNlIHNvbiAxZXIgcsOpc2VhdSBzb2NpYWwgbXVzaWNhbCwgU3BvdGlmeSBldCBUaGUgQ29jYSBDb2xhIENvbXBhbnkgc2lnbmVudCB1biBwYXJ0ZW5hcmlhdCBzdHJhdMOpZ2lxdWUgcMOpdGlsbGFudCwgQmVsaWV2ZSBEaWdpdGFsIG1pc2UgKHByZXNxdWUgdG91dCkgc3VyIGxhIHZpZMOpbywgbGUgbWlsbGlhcmQgZOKAmWV1cm9zIGRlIGNoaWZmcmUgZOKAmWFmZmFpcmVzIGVuIEV1cm9wZSBwb3VyIEl0dW5lcywgZXQgbGVzIGRlcm5pZXJzIGNsaXBzIGRlIEJvdyBXb3cgKGVuIGZvcm1lIGRlIHBsYWdpYXQpIGV0IFBhdWwgTWNDYXJ0bmV5IChlbiBsYW5ndWUgZGVzIHNpZ25lcykuPC9wPg0KPHA%PHN0cm9uZz4oTElGVElORykgSmFtZW5kbyBmYWl0IHBlYXUgbmV1dmUuPC9zdHJvbmc%PC9wPg0KPHA%PGEgaHJlZj0iaHR0cDovL3d3dy5qYW1lbmRvLmNvbS9mci8iPjxpbWcgY2xhc3M9ImFsaWduY2VudGVyIHNpemUtZnVsbCB3cC1pbWFnZS01OTU1NyIgdGl0bGU9IkphbWVuZG8iIHNyYz0iYXNzZXRzL2ZlZWRzX2ltYWdlcy9KYW1lbmRvLmpwZyIgYWx0PSIiIHdpZHRoPSI1NTAiIGhlaWdodD0iMjY0IiAvPjwvYT48L3A%DQo8cD48YSBocmVmPSJodHRwOi8vd3d3LmphbWVuZG8uY29tL2ZyLyI%SmFtZW5kbzwvYT4gdmllbnQgZGUgbGFuY2VyIHVuZSB0b3V0ZSBub3V2ZWxsZSB2ZXJzaW9uIGRlIHNhIHBsYXRlZm9ybWUgZGUgbXVzaXF1ZSBsaWJyZS48YnIgLz4NCkzigJlvYmplY3RpZiBkZSBjZXR0ZSDDqXZvbHV0aW9uIGVzdCBkZSBwcm9wb3NlciB1biBzaXRlIHBsdXMgY29udml2aWFsIGV0IHBsdXMgc2ltcGxlIHBvdXIgcG91dm9pciBlbmNvcmUgcGx1cyBmYWNpbGVtZW50IDxzcGFuIGlkPSJtb3JlLTU5NTU1Ij48L3NwYW4%ZMOpY291dnJpciwgw6ljb3V0ZXIgZXQgdMOpbMOpY2hhcmdlciBkZXMgbWlsbGllcnMgZOKAmWFydGlzdGVzIHNhbnMgYXVjdW5lIGxpbWl0ZS4gUGFybWkgbGVzIG5vdXZlYXV0w6lzLCBkZSBub3V2ZWF1eCBUb3BzLCBkZXMgc8OpbGVjdGlvbnMgZOKAmWFydGlzdGVzIHBvdXIgZMOpY291dnJpciBsZSBtZWlsbGV1ciBkZSBsYSBtdXNpcXVlLCAxMCBub3V2ZWxsZXMgcmFkaW9zIHRow6ltYXRpcXVlcywgdW4gbm91dmVhdSBtb3RldXIgZGUgcmVjaGVyY2hlIGV0IHVuIHBsYXllciBtdXNpY2FsIGVudGnDqHJlbWVudCByZXZ1IHBvdXIgbmF2aWd1ZXIgc3VyIDxhIGhyZWY9Imh0dHA6Ly93d3cuamFtZW5kby5jb20vZnIvIj5KYW1lbmRvPC9hPiB0b3V0IGVuIGNvbnRpbnVhbnQgw6Agw6ljb3V0ZXIgbGEgbXVzaXF1ZSBzYW5zIGludGVycnVwdGlvbiBldCByZWNvbW1hbmRlciBzZXMgdGl0cmVzIHByw6lmw6lyw6lzIMOgIHNlcyBhbWlzLiBE4oCZYXV0cmVzIG5vdXZlYXV0w6lzIHNlcm9udCBkw6l2b2lsw6llcyBkYW5zIGxlcyBwcm9jaGFpbnMgbW9pcy48YnIgLz4NCkF1am91cmTigJlodWksIDxhIGhyZWY9Imh0dHA6Ly93d3cuamFtZW5kby5jb20vZnIvIj5KYW1lbmRvPC9hPiBjb21wdGUgcGx1cyBkZSAxMi4wMDAgY2xpZW50cyDDoCB0cmF2ZXJzIGxlIG1vbmRlLCBldCBvZmZyZSBwbHVzIGRlIDM1MC4wMDAgdGl0cmVzIGVuIHN0cmVhbWluZyBldCBlbiB0w6lsw6ljaGFyZ2VtZW50IHNvdXMgbGljZW5jZXMgQ3JlYXRpdmUgQ29tbW9ucy48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnJlbmNod2ViLmZyL2Nocm9uaXF1ZS1kaWdpdGFsLW11c2ljLTMyLTYxMzgxL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjM8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5MZSBKZXVkaSAxMiBBdnJpbCwgbGVzIHLDqXNlYXV4IHNvY2lhdXggc%KAmWludml0ZW50IGF1IFBhbGFpcyBkZSBsYSBkw6ljb3V2ZXJ0ZTwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2xlLWpldWRpLTEyLWF2cmlsLWxlcy1yZXNlYXV4LXNvY2lhdXgtcyVlMiU4MCU5OWludml0ZW50LWF1LXBhbGFpcy1kZS1sYS1kZWNvdXZlcnRlLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2xlLWpldWRpLTEyLWF2cmlsLWxlcy1yZXNlYXV4LXNvY2lhdXgtcyVlMiU4MCU5OWludml0ZW50LWF1LXBhbGFpcy1kZS1sYS1kZWNvdXZlcnRlLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPlR1ZSwgMjcgTWFyIDIwMTIgMjM6MDA6MzIgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkF1cmVsaWUgUGVycnVjaGU8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzg2ODwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxpbWcgY2xhc3M9ImFsaWdubGVmdCBzaXplLWZ1bGwgd3AtaW1hZ2UtMjM4NjkiIHRpdGxlPSJyZXNlYXV4IHNvY2lhdXgiIHNyYz0iYXNzZXRzL2ZlZWRzX2ltYWdlcy9yZXNlYXV4LXNvY2lhdXguanBnIiBhbHQ9IiIgd2lkdGg9IjI3MSIgaGVpZ2h0PSIxNDgiIC8%TGVzIDEyIGV0IDEzIGF2cmlsIDIwMTIsIGzigJlVbml2ZXJzaXTDqSBkZSBWZXJzYWlsbGVzIFNhaW50LVF1ZW50aW4tZW4tWXZlbGluZXMgb3JnYW5pc2UgYXUgUGFsYWlzIGRlIGxhIGTDqWNvdXZlcnRlIDxhIHRpdGxlPSJSw6lzZWF1eCBzb2NpYXV4IiBocmVmPSJodHRwOi8vd3d3Lm5vdXZlYXV4bWVkaWFzLnV2c3EuZnIvbWVkaWFwb2xpcy0xNzYwNjMua2pzcD9SSD0xMzI3NTE4MjEzNzkwJiMzODtSRj0xMzI3MzE4Nzc2MDMwIiB0YXJnZXQ9Il9ibGFuayI%dW48L2E%DQo8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCYjMzg7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPmNvbGxvcXVlIGNvbnNhY3LDqSBhdXggbm91dmVhdXggbcOpZGlhczwvYT4uIFVuZSB0YWJsZSByb25kZSBzdXIgbGEgdGjDqW1hdGlxdWUgZGUgPHN0cm9uZz5sYSBjdWx0dXJlIGV0IGRlcyByw6lzZWF1eCBzb2NpYXV4PC9zdHJvbmc%IGVzdA0KcHJvcG9zw6llIGxlIDxzdHJvbmc%amV1ZGkgMTIgYXZyaWwgMjAxMiBkZSA5aDMwIMOgIDEyaDAwPC9zdHJvbmc%Lg0KDQpEZXB1aXMgcGx1c2lldXJzIGFubsOpZXMsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHNvbnQgZGV2ZW51cyBkZSB2w6lyaXRhYmxlcyBvdXRpbHMgZGUgcGFydGFnZS5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48aW1nIGNsYXNzPSJhbGlnbmxlZnQgc2l6ZS1mdWxsIHdwLWltYWdlLTIzODY5IiB0aXRsZT0icmVzZWF1eCBzb2NpYXV4IiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvcmVzZWF1eC1zb2NpYXV4LmpwZyIgYWx0PSIiIHdpZHRoPSIyNzEiIGhlaWdodD0iMTQ4IiAvPkxlcyAxMiBldCAxMyBhdnJpbCAyMDEyLCBs4oCZVW5pdmVyc2l0w6kgZGUgVmVyc2FpbGxlcyBTYWludC1RdWVudGluLWVuLVl2ZWxpbmVzIG9yZ2FuaXNlIGF1IFBhbGFpcyBkZSBsYSBkw6ljb3V2ZXJ0ZSA8YSB0aXRsZT0iUsOpc2VhdXggc29jaWF1eCIgaHJlZj0iaHR0cDovL3d3dy5ub3V2ZWF1eG1lZGlhcy51dnNxLmZyL21lZGlhcG9saXMtMTc2MDYzLmtqc3A:Ukg9MTMyNzUxODIxMzc5MCZhbXA7UkY9MTMyNzMxODc3NjAzMCIgdGFyZ2V0PSJfYmxhbmsiPnVuPC9hPjxiciAvPg0KPGEgdGl0bGU9IlLDqXNlYXV4IHNvY2lhdXgiIGhyZWY9Imh0dHA6Ly93d3cubm91dmVhdXhtZWRpYXMudXZzcS5mci9tZWRpYXBvbGlzLTE3NjA2My5ranNwP1JIPTEzMjc1MTgyMTM3OTAmYW1wO1JGPTEzMjczMTg3NzYwMzAiIHRhcmdldD0iX2JsYW5rIj5jb2xsb3F1ZSBjb25zYWNyw6kgYXV4IG5vdXZlYXV4IG3DqWRpYXM8L2E%LiBVbmUgdGFibGUgcm9uZGUgc3VyIGxhIHRow6ltYXRpcXVlIGRlIDxzdHJvbmc%bGEgY3VsdHVyZSBldCBkZXMgcsOpc2VhdXggc29jaWF1eDwvc3Ryb25nPiBlc3Q8YnIgLz4NCnByb3Bvc8OpZSBsZSA8c3Ryb25nPmpldWRpIDEyIGF2cmlsIDIwMTIgZGUgOWgzMCDDoCAxMmgwMDwvc3Ryb25nPi48L3A%DQo8cD5EZXB1aXMgcGx1c2lldXJzIGFubsOpZXMsIGxlcyByw6lzZWF1eCBzb2NpYXV4IHNvbnQgZGV2ZW51cyBkZSB2w6lyaXRhYmxlcyBvdXRpbHMgZGUgcGFydGFnZS4gRGlmZnVzYW50IGRlIGxhIG11c2lxdWUsIGRlcyBmaWxtcywgZGVzIHJlcHLDqXNlbnRhdGlvbnMgdGjDqcOidHJhbGVzIGV0IGJpZW4gZOKAmWF1dHJlcyBjcsOpYXRpb25zIGFydGlzdGlxdWVzLCBpbHMgc29udCBk4oCZaW5jcm95YWJsZXMgcGxhdGVmb3JtZXMgZOKAmcOpY2hhbmdlLCB1biB2w6lyaXRhYmxlIHRyZW1wbGluIHBvdXIgbGVzIGFydGlzdGVzIGV0IHVuIG5vdXZlYXUgdmVjdGV1ciBkZSB0cmFuc21pc3Npb24gZGUgbGEgY3VsdHVyZS4gRGFucyB1bmUgc29jacOpdMOpIGdvdXZlcm7DqWUgcGFyIGxhIGNvbW11bmljYXRpb24gZXQgbGEgcmFwaWRpdMOpIGRlcyDDqWNoYW5nZXMsIGxlcyBwcmF0aXF1ZXMgY3VsdHVyZWxsZXMgb250IHN1YmkgbGEgbXV0YXRpb24gZGUgY2V0dGUgaW5zdGFudGFuw6lpdMOpIGFic29sdWUuIEVuIHF1ZWxxdWVzIGNsaWNzLCBsZXMgaW50ZXJuYXV0ZXMgcGV1dmVudCBhdWpvdXJk4oCZaHVpIGTDqWNvdXZyaXIgZGVzIHZpZMOpb3MgZXQgZGVzIGNvbnRlbnVzIHB1Ymxpw6lzIHN1ciB0b3VzIGxlcyBjb250aW5lbnRzLCBzb3V0ZW5pciB1biBhcnRpc3RlIHF14oCZaWxzIGFmZmVjdGlvbm5lbnQgZXQgbGlyZSB1biByb21hbiBudW3DqXJpc8OpIGVuIGxpZ25lLjwvcD4NCjxwPkxlcyByw6lzZWF1eCBzb2NpYXV4IGFnaXNzZW50IGNvbW1lIGRlcyByw6l2w6lsYXRldXJzIGRlIHRhbGVudHMgcGFyIGxlIGJpYWlzIGRlcyBwbGF0ZWZvcm1lcyBwYXJ0aWNpcGF0aXZlcyBldCBwZXJtZXR0ZW50IMOgIGRlcyBhcnRpc3RlcyBkZSBzZSBmYWlyZSBjb25uYcOudHJlIGR1IHB1YmxpYyBzYW5zIGF2b2lyIMOgIHNlIHNvdW1ldHRyZSBhdXggY2VyY2xlcyBkZSBsw6lnaXRpbWF0aW9uPGJyIC8%DQp0cmFkaXRpb25uZWxzLiBDZXBlbmRhbnQsIMOpdm9xdWVyIGzigJlleHBsb2l0YXRpb24gZGVzIHLDqXNlYXV4IHNvY2lhdXggcGFyIGxlcyBhcnRpc3RlcyBuw6ljZXNzaXRlIGRlIHPigJlpbnRlcnJvZ2VyIHN1ciBsZXVyIGNvbnRyw7RsZSBldCBs4oCZaW1wYWN0IHF14oCZaWxzIHNvbnQgc3VzY2VwdGlibGVzIGTigJlhdm9pciBzdXIgbGUgZHJvaXQgZOKAmWF1dGV1ciBldCBzdXIgbGEgcHJvcHJpw6l0w6kgaW50ZWxsZWN0dWVsbGUuPC9wPg0KPHA%UG91ciByw6lwb25kcmUgw6AgY2VzIHF1ZXN0aW9ucyBub3V2ZWxsZXMsIGF1dG91ciBkZSBjZXR0ZSB0YWJsZSByb25kZSBkaWZmw6lyZW50cyBzcMOpY2lhbGlzdGVzIHNlcm9udCBwcsOpc2VudHMgOiA8c3Ryb25nPkp1bGllbiBSQVNURUdBUjwvc3Ryb25nPiAoam91cm5hbGlzdGUgc2NpZW50aWZpcXVlKSwgPHN0cm9uZz5OaWNvbGFzIExPVUJFVDwvc3Ryb25nPiAoZW50cmVwcmVuZXVyIGV0IGNvbnN1bHRhbnQgVW1hcHMpPGJyIC8%DQo8c3Ryb25nPk1hcmluZSBKT1VBTjwvc3Ryb25nPiAoY2hhcmfDqSBkZXMgcHJvamV0cyBkZSBLaXNzS2lzcyBCYW5rQmFuayksIDxzdHJvbmc%QW15bGVlPC9zdHJvbmc%IChhcnRpc3RlIHBsYXN0aWNpZW5uZSkgZXQgPHN0cm9uZz5OYXRoYWxpZSBEUkVZRlVTPC9zdHJvbmc%IChqdXJpc3RlKS48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9sZS1qZXVkaS0xMi1hdnJpbC1sZXMtcmVzZWF1eC1zb2NpYXV4LXMlZTIlODAlOTlpbnZpdGVudC1hdS1wYWxhaXMtZGUtbGEtZGVjb3V2ZXJ0ZS9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkZhZ3VvIFNob2VzIG9yZ2FuaXNlIHNhbWVkaSDDoCAxMmggbGEgRkFHVU8gVHLDqXNvciwgdW5lIGNoYXNzZSBhdSB0csOpc29yIDMuMDwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzMwL2ZhZ3VvLXNob2VzLW9yZ2FuaXNlLXNhbWVkaS1hLTEyaC1sYS1mYWd1by10cmVzb3ItdW5lLWNoYXNzZS1hdS10cmVzb3ItMy0wLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzMwL2ZhZ3VvLXNob2VzLW9yZ2FuaXNlLXNhbWVkaS1hLTEyaC1sYS1mYWd1by10cmVzb3ItdW5lLWNoYXNzZS1hdS10cmVzb3ItMy0wLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPkZyaSwgMzAgTWFyIDIwMTIgMTA6MjQ6MTIgKzAwMDA8L3B1YkRhdGU%DQoNCgkJPGRjOmNyZWF0b3I%QXVyZWxpZSBQZXJydWNoZTwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbZmFndW8gdHLDqXNvcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM5MjI8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtBIGwnb2NjYXNpb24gZGUgUMOicXVlcywgbGEgbWFycXVlIGRlIGNoYXVzc3VyZXMgPHN0cm9uZz48YSBocmVmPSJodHRwczovL3d3dy5mYWNlYm9vay5jb20vRkFHVU9TaG9lcy9hcHBfMzYzNzY2OTY2OTc5MDc0IiB0YXJnZXQ9Il9ibGFuayI%RmFndW8gU2hvZXM8L2E%PC9zdHJvbmc%IGEgZMOpY2lkw6ksIGVuIHBhcnRlbmFyaWF0IGF2ZWMgZGVzIG1hcnF1ZXMgYW1pZXMgYXBwZWzDqWVzIGF1c3NpIGFtYmFzc2FkZXVycywgZCdvcmdhbmlzZXIgdW5lIGdyYW5kZSA8YSBocmVmPSJodHRwOi8vd3d3LmZhY2Vib29rLmNvbS9ldmVudHMvMTA1Mjk1NzcyOTM3NDYwLyIgdGFyZ2V0PSJfYmxhbmsiPmNoYXNzZSBhdSB0csOpc29yIDMuMDwvYT4gZGFucyBsZXMgMmVtZSBldCAzIGVtZSBhcnJvbmRpc3NlbWVudHMgZGUgUGFyaXMgU2FtZWRpIDMxIE1hcnMgw6AgMTJoLiBQbHVzIGRlIDUwIDAwMCBmYW5zIHN1ciBsZXMgZGlmZsOpcmVudGVzIHBhZ2VzIEZhY2Vib29rIGRlcyBhbWJhc3NhZGV1cnMgb250IMOpdMOpIG1vYmlsaXPDqXMgcG91ciBwYXJ0aWNpcGVyLg0KDQpMYSBGQUdVT%KAmVRSw4lTT1IgZXN0IHVuZSBjaGFzc2UgMy4wIG1lbGFudCB3ZWIsIGRpZ2l0YWwgZXQgc3RyZWV0IG1hcmtldGluZy4gVG91cyBjZXV4IHF1aSBzb3VoYWl0ZW50IHBhcnRpY2lwZXIgcGFydGlyb250IMOgIGxhIHJlY2hlcmNoZSBkZSAxMDAgUVIgY29kZXMgY2FjaMOpcy4gSWwgbGV1ciBmYXVkcmEgbGVzIGZsYXNoZXIgYXZlYyBsJ2FwcGxpY2F0aW9uIG1vYmlsZSBib29rQmVvLiAxMDAgYW1iYXNzYWRldXJzIChkZXMgYmxvZ3VldXJzLCBmYW5zIEZhY2Vib29rLCBtYWdhc2lucywgcGVyc29ubmFsaXTDqXMgZXQgbWFycXVlcyBhbWllcykgZGlmZnVzZXJvbnQgZGVzIGluZGljZXMgdG91dGUgbGEgam91cm7DqWUgdmlhIGxlcyByw6lzZWF1eCBzb2NpYXV4IHBvdXIgYWlkZXIgbGVzIHBhcnRpY2lwYW50cy5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5BIGwmIzgyMTc7b2NjYXNpb24gZGUgUMOicXVlcywgbGEgbWFycXVlIGRlIGNoYXVzc3VyZXMgPHN0cm9uZz48YSBocmVmPSJodHRwczovL3d3dy5mYWNlYm9vay5jb20vRkFHVU9TaG9lcy9hcHBfMzYzNzY2OTY2OTc5MDc0IiB0YXJnZXQ9Il9ibGFuayI%RmFndW8gU2hvZXM8L2E%PC9zdHJvbmc%IGEgZMOpY2lkw6ksIGVuIHBhcnRlbmFyaWF0IGF2ZWMgZGVzIG1hcnF1ZXMgYW1pZXMgYXBwZWzDqWVzIGF1c3NpIGFtYmFzc2FkZXVycywgZCYjODIxNztvcmdhbmlzZXIgdW5lIGdyYW5kZSA8YSBocmVmPSJodHRwOi8vd3d3LmZhY2Vib29rLmNvbS9ldmVudHMvMTA1Mjk1NzcyOTM3NDYwLyIgdGFyZ2V0PSJfYmxhbmsiPmNoYXNzZSBhdSB0csOpc29yIDMuMDwvYT4gZGFucyBsZXMgMmVtZSBldCAzIGVtZSBhcnJvbmRpc3NlbWVudHMgZGUgUGFyaXMgU2FtZWRpIDMxIE1hcnMgw6AgMTJoLiBQbHVzIGRlIDUwIDAwMCBmYW5zIHN1ciBsZXMgZGlmZsOpcmVudGVzIHBhZ2VzIEZhY2Vib29rIGRlcyBhbWJhc3NhZGV1cnMgb250IMOpdMOpIG1vYmlsaXPDqXMgcG91ciBwYXJ0aWNpcGVyLjwvcD4NCjxwPkxhIEZBR1VP4oCZVFLDiVNPUiBlc3QgdW5lIGNoYXNzZSAzLjAgbWVsYW50IHdlYiwgZGlnaXRhbCBldCBzdHJlZXQgbWFya2V0aW5nLiBUb3VzIGNldXggcXVpIHNvdWhhaXRlbnQgcGFydGljaXBlciBwYXJ0aXJvbnQgw6AgbGEgcmVjaGVyY2hlIGRlIDEwMCBRUiBjb2RlcyBjYWNow6lzLiBJbCBsZXVyIGZhdWRyYSBsZXMgZmxhc2hlciBhdmVjIGwmIzgyMTc7YXBwbGljYXRpb24gbW9iaWxlIGJvb2tCZW8uIDEwMCBhbWJhc3NhZGV1cnMgKGRlcyBibG9ndWV1cnMsIGZhbnMgRmFjZWJvb2ssIG1hZ2FzaW5zLCBwZXJzb25uYWxpdMOpcyBldCBtYXJxdWVzIGFtaWVzKSBkaWZmdXNlcm9udCBkZXMgaW5kaWNlcyB0b3V0ZSBsYSBqb3VybsOpZSB2aWEgbGVzIHLDqXNlYXV4IHNvY2lhdXggcG91ciBhaWRlciBsZXMgcGFydGljaXBhbnRzLjwvcD4NCjxwPkxlIHByaW5jaXBlIGVzdCBzaW1wbGUgOjwvcD4NCjxwPjEpIFJEViBTYW1lZGkgw6AgMTJoIHN1ciBsZXMgcGFnZXMgZmFucyBkZXMgYW1iYXNzYWRldXJzIG91IHN1ciBsZXMgY29tcHRlcyB0d2l0dGVyIHBvdXIgYXZvaXIgbGVzIGluZGljZXMgYXUgc3VqZXQgZGVzIDEwMCBRUiBjb2RlcyBjYWNow6lzIGRhbnMgUGFyaXM8L3A%DQo8cD4yKSBDaGVyY2hleiwgdHJvdXZleiBldCBzY2FubmV6IGxlIG1heGltdW0gZGUgUVIgY29kZXMgZW50cmUgMTJoIGV0IDE2aCBhdmVjIGwmIzgyMTc7YXBwbGljYXRpb24gPGEgaHJlZj0iaHR0cDovL2l0dW5lcy5hcHBsZS5jb20vZnIvYXBwL2Jvb2tiZW8vaWQzMDY0MTE0NTM:bXQ9OCIgdGFyZ2V0PSJfYmxhbmsiPkJvb2tCZW88L2E%PC9wPg0KPHA%PGlmcmFtZSB3aWR0aD0iNjAwIiBoZWlnaHQ9IjMzNSIgc3JjPSJodHRwOi8vd3d3LnlvdXR1YmUuY29tL2VtYmVkL29TNmxvLUIxZVhJP3JlbD0wIiBmcmFtZWJvcmRlcj0iMCIgYWxsb3dmdWxsc2NyZWVuPjwvaWZyYW1lPjwvcD4NCjxwPjMpIEEgMTZoLCBsZSBsaWV1IGR1IFFSIGNvZGUgZmluYWwgc2VyYSBkw6l2b2lsw6kgZXQgdG91dCBsZSBtb25kZSBzZSByZXRyb3V2ZXJhIMOgIGNldCBlbmRyb2l0IHBvdXIgYm9pcmUgdW4gdmVycmU8L3A%DQo8cD5MZSBjb25jZXB0IGVzdCBpbnRlcmVzc2FudCBwb3VyIHJlZ3JvdXBlciBkZXMgbWFycXVlcyBldCBhdm9pciB1bmUgZm9yY2UgZGUgY29tbXVuaWNhdGlvbiBwbHVzIGltcGFjdGFudGUgZXQgYWluc2kgdG91Y2hlciBkZXMgY2libGVzIGRpZmbDqXJlbnRlcy48L3A%DQo8cD5QYXJtaSBsZXMgYW1iYXNzYWRldXJzLCBvbiByZXRyb3V2ZSA6IDxhIGhyZWY9Imh0dHA6Ly93d3cubWljaGVsZXRhdWd1c3Rpbi5jb20vIiB0YXJnZXQ9Il9ibGFuayI%TWljaGVsJmFtcDtBdWd1c3RpbjwvYT4sIDxhIHJlbD0ibm9mb2xsb3ciIGhyZWY9Imh0dHA6Ly93d3cuZGFnb2JlYXIuY29tLyIgdGFyZ2V0PSJfYmxhbmsiPkRhZ29iZWFyPC9hPiwgPGEgaHJlZj0iaHR0cDovL3d3dy5tYXNwYXR1bGUuY29tIiB0YXJnZXQ9Il9ibGFuayI%TWFTcGF0dWxlPC9hPiwgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vZmJCT1JERVJMSU5FP3JlZj10cyIgdGFyZ2V0PSJfYmxhbmsiPkJvcmRlcmxpbmU8L2E%LCA8YSByZWw9Im5vZm9sbG93IiBocmVmPSJodHRwOi8vd3d3LmZhY2Vib29rLmNvbS9sZXNpbnN1cmdlcy51bmRlcndlYXIiIHRhcmdldD0iX2JsYW5rIj5MZXMgSW5zdXJnw6lzPC9hPiwgPGEgaHJlZj0iaHR0cDovL3d3dy5mYWNlYm9vay5jb20vc29qZWFucy5mcmFuY2UiIHRhcmdldD0iX2JsYW5rIj5TbyBqZWFuczwvYT4mIzgyMzA7PC9wPg0KPHA%RGVzIHBlcnNvbm5hbGl0w6lzIGNvbW1lIEtoZWlyb24sIFZlcmlubywgPGEgaHJlZj0iaHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTEvMDkvMTIvbGUtbW9vdmplZS11bi1wcml4LWRlcy1tZW50b3JzLXVuLWNsdWItZXQtZGVzLWV2ZW5lbWVudHMtcG91ci1ub3MtamV1bmVzLWVudHJlcHJlbmV1cnMvIiB0YXJnZXQ9Il9ibGFuayI%TW9vdmplZTwvYT48L3A%DQo8cD5EZXMgYmxvZ3M6IEzigJlpbnRlcm5hdXRlLCBNZWx0eSBGYXNoaW9uLCBNYXJpb25Sb2NrcywgRGFuZGllcywgRW4gbW9kZSBGYXNoaW9uPC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMzAvZmFndW8tc2hvZXMtb3JnYW5pc2Utc2FtZWRpLWEtMTJoLWxhLWZhZ3VvLXRyZXNvci11bmUtY2hhc3NlLWF1LXRyZXNvci0zLTAvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KDQoJCTxzbGFzaDpjb21tZW50cz4wPC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPltFeGNsdV0gTXlFUlAuY29tIGxhbmNlIHVuZSB2ZXJzaW9uIGRlIHNvbiBhcHBsaWNhdGlvbiBkZSBnZXN0aW9uIGNsb3VkIGTDqWRpw6llIGF1IFBNRSBhdSBVSzwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2V4Y2x1LW15ZXJwLWNvbS1sYW5jZS11bmUtdmVyc2lvbi1kZS1zb24tYXBwbGljYXRpb24tZGUtZ2VzdGlvbi1jbG91ZC1kZWRpZWUtYXUtcG1lLWF1LXVrLzwvbGluaz4NCg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvZXhjbHUtbXllcnAtY29tLWxhbmNlLXVuZS12ZXJzaW9uLWRlLXNvbi1hcHBsaWNhdGlvbi1kZS1nZXN0aW9uLWNsb3VkLWRlZGllZS1hdS1wbWUtYXUtdWsvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%V2VkLCAyOCBNYXIgMjAxMiAxMjoyNDozMyArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%QXVyZWxpZSBQZXJydWNoZTwvZGM6Y3JlYXRvcj4NCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbbXlFUlBdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODk3PC9ndWlkPg0KDQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vbXllcnAuY29tLyIgdGFyZ2V0PSJfc2VsZiI%TXlFUlAuY29tPC9hPiBlc3QgbGUgPHN0cm9uZz5wcmVtaWVyIHNlcnZpY2UgY2xvdWQgZGUgZ2VzdGlvbjwvc3Ryb25nPiDDoCBkZXN0aW5hdGlvbiBkZXMgUE1FLCBsYSBzb2Npw6l0w6kgbGFuY2UgYXVqb3VyZCdodWkgdW5lIHZlcnNpb24gZGUgc29uIGFwcGxpY2F0aW9uIHN1ciBsZSBtYXJjaMOpIGJyaXRhbm5pcXVlIGFsb3JzIHF1ZSBzb24gY29uY3VycmVudCBsb2NhbCBTQUdFIG4nYSB0b3Vqb3VycyBwYXMgZGUgc29sdXRpb24gY2xvdWQuIExhbmPDqSBvZmZpY2llbGxlbWVudCBlbiA8c3Ryb25nPm1hcnMgMjAxMDwvc3Ryb25nPiBhdmVjIGxlIGxhbmNlbWVudCBkZSBHb29nbGUgQXBwcyBNYXJrZXRwbGFjZSwgbXlFUlAgY29tcHRlIHByw6hzIGRlIDUwMDAwIFBNRSDDoCB0cmF2ZXJzIHBsdXMgZGUgMTAwIHBheXMgZGlmZsOpcmVudHMgcXVpIHV0aWxpc2VudCByw6lndWxpw6hyZW1lbnQgbGEgcGxhdGVmb3JtZSBwb3VyIGfDqXJlciB0b3V0ZXMgbGVzIGFjdGl2aXTDqXMgZGUgbGV1ciBzb2Npw6l0w6kgZGVwdWlzIGxlIGNsb3VkIDogbGEgY29tcHRhYmlsaXTDqSBlbiBsaWduZSwgbGEgZmFjdHVyYXRpb24sIGxlIENSTSwgbGVzIHN0b2NrcyBldCBiaWVuIHBsdXMsIGxlIHRvdXQgaW50w6lncsOpIGF2ZWMgR29vZ2xlIEFwcHMuIEMnZXN0IHVuZSA8YSBocmVmPSJodHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMC8wNy8xNi9sZXMtZnJhbmNhaXMtZGUtbGEtdmFsbGV5LXRvdXItZGhvcnpvbi1kZXMtc3RhcnR1cHMtb3UtZW50cmVwcmVuZXVycy1mcmFuY2Fpcy8iIHRhcmdldD0iX2JsYW5rIj5zdGFydHVwIGZyYW7Dp2Fpc2UgcGFydGllIGRhbnMgbGEgc2lsaWNvbiBWYWxsZXk8L2E%Ll1dPjwvZGVzY3JpcHRpb24%DQoJCQk8Y29udGVudDplbmNvZGVkPjwhW0NEQVRBWzxwPjxhIGhyZWY9Imh0dHA6Ly9teWVycC5jb20vIiB0YXJnZXQ9Il9zZWxmIj5NeUVSUC5jb208L2E%IGVzdCBsZSA8c3Ryb25nPnByZW1pZXIgc2VydmljZSBjbG91ZCBkZSBnZXN0aW9uPC9zdHJvbmc%IMOgIGRlc3RpbmF0aW9uIGRlcyBQTUUsIGxhIHNvY2nDqXTDqSBsYW5jZSBhdWpvdXJkJiM4MjE3O2h1aSB1bmUgdmVyc2lvbiBkZSBzb24gYXBwbGljYXRpb24gc3VyIGxlIG1hcmNow6kgYnJpdGFubmlxdWUgYWxvcnMgcXVlIHNvbiBjb25jdXJyZW50IGxvY2FsIFNBR0UgbiYjODIxNzthIHRvdWpvdXJzIHBhcyBkZSBzb2x1dGlvbiBjbG91ZC4gTGFuY8OpIG9mZmljaWVsbGVtZW50IGVuIDxzdHJvbmc%bWFycyAyMDEwPC9zdHJvbmc%IGF2ZWMgbGUgbGFuY2VtZW50IGRlIEdvb2dsZSBBcHBzIE1hcmtldHBsYWNlLCBteUVSUCBjb21wdGUgcHLDqHMgZGUgNTAwMDAgUE1FIMOgIHRyYXZlcnMgcGx1cyBkZSAxMDAgcGF5cyBkaWZmw6lyZW50cyBxdWkgdXRpbGlzZW50IHLDqWd1bGnDqHJlbWVudCBsYSBwbGF0ZWZvcm1lIHBvdXIgZ8OpcmVyIHRvdXRlcyBsZXMgYWN0aXZpdMOpcyBkZSBsZXVyIHNvY2nDqXTDqSBkZXB1aXMgbGUgY2xvdWQgOiBsYSBjb21wdGFiaWxpdMOpIGVuIGxpZ25lLCBsYSBmYWN0dXJhdGlvbiwgbGUgQ1JNLCBsZXMgc3RvY2tzIGV0IGJpZW4gcGx1cywgbGUgdG91dCBpbnTDqWdyw6kgYXZlYyBHb29nbGUgQXBwcy4gQyYjODIxNztlc3QgdW5lIDxhIGhyZWY9Imh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEwLzA3LzE2L2xlcy1mcmFuY2Fpcy1kZS1sYS12YWxsZXktdG91ci1kaG9yem9uLWRlcy1zdGFydHVwcy1vdS1lbnRyZXByZW5ldXJzLWZyYW5jYWlzLyIgdGFyZ2V0PSJfYmxhbmsiPnN0YXJ0dXAgZnJhbsOnYWlzZSBwYXJ0aWUgZGFucyBsYSBzaWxpY29uIFZhbGxleTwvYT4uPC9wPg0KPHA%TCYjODIxNztvZmZyZSBkZSBteUVSUCBwZXJtZXQgYXV4IFBNRSBkJiM4MjE3O2FjaGV0ZXIgdW5lIHNldWxlIGFwcGxpY2F0aW9uIHNpbXBsZSBldCBjb21wbMOodGUgYXUgbGlldSBkZSBtdWx0aXBsZXMgYXBwbGljYXRpb25zIGNow6hyZXMgZXQgZGlmZmljaWxlcyDDoCB1dGlsaXNlci4gR3LDomNlIMOgIHNvbiBpbnRlcmZhY2Ugc2ltcGxlIGF2ZWMgdW5lIGJhcnJlIGRlIG5hdmlnYXRpb24gw6AgbGEgR29vZ2xlIGV0IHNvbiBhbGdvcml0aG1lIGludGVsbGlnZW50IGV0IHByw6lkaWN0aWYgcXVpIGFycml2ZSDDoCBjb21wcmVuZHJlIGV4YWN0ZW1lbnQgY2UgcXVlIGwmIzgyMTc7dXRpbGlzYXRldXIgc291aGFpdGUgZmFpcmUsIGwmIzgyMTc7YXBwbGljYXRpb24gbXlFUlAgbmUgbsOpY2Vzc2l0ZSBhdWN1bmUgZm9ybWF0aW9uIGFmaW4gZGUgbCYjODIxNzt1dGlsaXNlci48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGxlZnQ7Ij48c3Ryb25nPkZyYW7Dp29pcyBOYWRhbDwvc3Ryb25nPiwgUERHIGRlIG15RVJQLCBleHBsaXF1ZSBsZSBsYW5jZW1lbnQgZGUgbGEgdmVyc2lvbiBicml0YW5uaXF1ZTogJiM4MjIwOzxlbT5sZSBtYXJjaMOpIGJyaXRhbm5pcXVlIHJlcHLDqXNlbnRlIHNlbG9uIG5vcyBlc3RpbWF0aW9ucyBsZSA0w6htZSBtYXJjaMOpIGxlIHBsdXMgaW50w6lyZXNzYW50IHBvdXIgbGVzIGFwcGxpY2F0aW9ucyBjbG91ZDwvZW0%JiM4MjIwOy4gSWwgcHLDqWNpc2UgZW4gcGx1cyBxdWUgJiM4MjIwOzxlbT5sZSBtYXJjaMOpIFVLIGVzdCBkb21pbsOpIHBhciBsJiM4MjE3O2FjdGV1ciBoaXN0b3JpcXVlLCBTYWdlLCBxdWkgbiYjODIxNzthIHBhcyBzdSBwcm9wb3NlciDDoCBzZXMgY2xpZW50cyB1bmUgdmVyc2lvbiBjbG91ZC4gTm91cyBlc3RpbW9ucyBxdSYjODIxNztlbiAyMDExLCAzNSUgZGVzIGVudHJlcHJpc2VzIGJyaXRhbm5pcXVlcyBzb3VoYWl0YWllbnQgZMOpasOgIG1pZ3JlciBsZXVyIGdlc3Rpb24gZGFucyBsZSBjbG91ZC4gRW4gMjAxMiwgbXlFUlAgYXJyaXZlIGVuZmluIGF2ZWMgdW5lIHNvbHV0aW9uIG1hdHVyZSwgcm9idXN0ZSBldCBzw6ljdXJpc8OpZSBwb3VyIGFzc3VyZXIgY2V0dGUgbWlncmF0aW9uLjwvZW0%JiM4MjIwOzwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBsZWZ0OyI%TCYjODIxNztvdXZlcnR1cmUgZHUgY29tcHRlIG15RVJQIGVzdCBncmF0dWl0IGF2ZWMgZGVzIGZvbmN0aW9ubmFsaXTDqXMgaWxsaW1pdMOpZXMgcG91ciAxIHV0aWxpc2F0ZXVyLiBMZXMgb2ZmcmVzIHBheWFudGVzICYjODIyMDtQcmVtaXVtJiM4MjIxOyBzb250IGRpc3BvbmlibGVzIHBvdXIgMiB1dGlsaXNhdGV1cnMgb3UgNSB1dGlsaXNhdGV1cnMsIGF1IGRlbMOgLCBsJiM4MjE3O3V0aWxpc2F0ZXVyIHN1cHBsw6ltZW50YWlyZSBlc3QgZmFjdHVyw6kgMTLigqwgcGFyIG1vaXMuIEJvbiBsYW5jZW1lbnQgITwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2V4Y2x1LW15ZXJwLWNvbS1sYW5jZS11bmUtdmVyc2lvbi1kZS1zb24tYXBwbGljYXRpb24tZGUtZ2VzdGlvbi1jbG91ZC1kZWRpZWUtYXUtcG1lLWF1LXVrL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjM8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%Q2l0aXZlcnNpdHksIGxlIGZldSBkZSBjYW1wIDIuMDwvdGl0bGU%DQoNCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvY2l0aXZlcnNpdHktbGUtZmV1LWRlLWNhbXAtMi0wLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI4L2NpdGl2ZXJzaXR5LWxlLWZldS1kZS1jYW1wLTItMC8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5XZWQsIDI4IE1hciAyMDEyIDEyOjA4OjM1ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5KdWxpZW4gTWVjaGluPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtjaXR5dmVyc2l0eV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4ODg8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8aW1nIGNsYXNzPSJhbGlnbmxlZnQiIHRpdGxlPSJjaXR5dmVyc2l0eSIgc3JjPSJodHRwOi8vZWJtZWRpYS5ldmVudGJyaXRlLmNvbS9zMy1idWlsZC9pbWFnZXMvMTI0MDg1LzI2NzA2Mjk5NTg1LzEvbG9nby5wbmciIGFsdD0iIiB3aWR0aD0iMjI1IiBoZWlnaHQ9IjU1IiAvPkFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%Lg0KDQpQZXJtZXR0cmUgw6AgZGVzIHBhc3Npb25uw6lzIGRlIHBhcnRhZ2VyIGxldXIgZXhww6lyaWVuY2UgYXZlYyB1bmUgcXVpbnphaW5lIGRlIHBlcnNvbm5lcyBlbiBkZXV4IGhldXJlcyBldCBkYW5zIHVuIGxpZXUgYWRhcHTDqSwgdGVsIGVzdCBs4oCZb2JqZWN0aWYgcXVlIHPigJllc3QgZml4w6kgPGEgaHJlZj0iaHR0cDovL2NpdGl2ZXJzaXR5LmV2ZW50YnJpdGUuY29tIj4gQ2l0aXZlcnNpdHk8L2E%Lg0KDQpVbiBvYmplY3RpZiBxdWkgbuKAmWVzdCBwYXMgc2FucyByYXBwZWxlciBjZWx1aSBkZSA8YSBocmVmPSJodHRwOi8vd3d3LnNraWxsc2hhcmUuY29tIj5Ta2lsbHNoYXJlPC9hPiwgc3RhcnQtdXAgbmV3LXlvcmthaXNlIGJpZW4gY29ubnVlIG1haXMgcXVpIHNvdWZmcmUgZGUgbGEgbGliZXJ0w6kgbGFpc3PDqWUgw6Agc2VzIHV0aWxpc2F0ZXVycyA7IG7igJlpbXBvcnRlIHF1aSBwb3V2YW50IHByb3Bvc2VyIHVuIGNvdXJzLCBjb21tZW50IHNhdm9pciBzaSBsZSBwcm9mZXNzZXVyIHNlcmEgZGUgcXVhbGl0w6k:IENvbW1lbnQsIHBvdXIgbGVzIHByb2Zlc3NldXJzLCB0cm91dmVyIGV0IHLDqXNlcnZlciB1bmUgc2FsbGUgYWRhcHTDqWUgc2FucyBtZXR0cmUgZ3JhdmVtZW50IGVuIGRhbmdlciBsYSByZW50YWJpbGl0w6kgZGUgbOKAmW9ww6lyYXRpb24gPyBUZWxsZXMgc29udCBsZXMgcXVlc3Rpb25zIGF1eHF1ZWxsZXMgcsOpcG9uZCBDaXRpdmVyc2l0eSwgcXVpIHPDqWxlY3Rpb25uZSBtw6l0aWN1bGV1c2VtZW50IHNlcyBhbmltYXRldXJzIGV0IHByZW5kIGVuIGNoYXJnZSBs4oCZYXNwZWN0IGxvZ2lzdGlxdWUgZGUgbOKAmW9yZ2FuaXNhdGlvbiBkZSBs4oCZYXRlbGllciAodW4gc2VydmljZSBwb3VyIGxlcXVlbCBDaXRpdmVyc2l0eSBwcsOpbMOodmUgMjUlIGR1IHRvdGFsLCBmcmFpcyBk4oCZb3JnYW5pc2F0aW9uIGTDqWR1aXRzKS5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD48aW1nIGNsYXNzPSJhbGlnbmxlZnQiIHRpdGxlPSJjaXR5dmVyc2l0eSIgc3JjPSJodHRwOi8vZWJtZWRpYS5ldmVudGJyaXRlLmNvbS9zMy1idWlsZC9pbWFnZXMvMTI0MDg1LzI2NzA2Mjk5NTg1LzEvbG9nby5wbmciIGFsdD0iIiB3aWR0aD0iMjI1IiBoZWlnaHQ9IjU1IiAvPkFydGljbGUgw6ljcml0IHBhciA8YSBocmVmPSJodHRwczovL3R3aXR0ZXIuY29tLyMhL1BFbnRyZW1vbnQiPlBpZXJyZSBFbnRyZW1vbnQ8L2E%LjwvcD4NCjxwPlBlcm1ldHRyZSDDoCBkZXMgcGFzc2lvbm7DqXMgZGUgcGFydGFnZXIgbGV1ciBleHDDqXJpZW5jZSBhdmVjIHVuZSBxdWluemFpbmUgZGUgcGVyc29ubmVzIGVuIGRldXggaGV1cmVzIGV0IGRhbnMgdW4gbGlldSBhZGFwdMOpLCB0ZWwgZXN0IGzigJlvYmplY3RpZiBxdWUgc%KAmWVzdCBmaXjDqSA8YSBocmVmPSJodHRwOi8vY2l0aXZlcnNpdHkuZXZlbnRicml0ZS5jb20iPiBDaXRpdmVyc2l0eTwvYT4uPC9wPg0KPHA%VW4gb2JqZWN0aWYgcXVpIG7igJllc3QgcGFzIHNhbnMgcmFwcGVsZXIgY2VsdWkgZGUgPGEgaHJlZj0iaHR0cDovL3d3dy5za2lsbHNoYXJlLmNvbSI%U2tpbGxzaGFyZTwvYT4sIHN0YXJ0LXVwIG5ldy15b3JrYWlzZSBiaWVuIGNvbm51ZSBtYWlzIHF1aSBzb3VmZnJlIGRlIGxhIGxpYmVydMOpIGxhaXNzw6llIMOgIHNlcyB1dGlsaXNhdGV1cnMgOyBu4oCZaW1wb3J0ZSBxdWkgcG91dmFudCBwcm9wb3NlciB1biBjb3VycywgY29tbWVudCBzYXZvaXIgc2kgbGUgcHJvZmVzc2V1ciBzZXJhIGRlIHF1YWxpdMOpPyBDb21tZW50LCBwb3VyIGxlcyBwcm9mZXNzZXVycywgdHJvdXZlciBldCByw6lzZXJ2ZXIgdW5lIHNhbGxlIGFkYXB0w6llIHNhbnMgbWV0dHJlIGdyYXZlbWVudCBlbiBkYW5nZXIgbGEgcmVudGFiaWxpdMOpIGRlIGzigJlvcMOpcmF0aW9uID8gVGVsbGVzIHNvbnQgbGVzIHF1ZXN0aW9ucyBhdXhxdWVsbGVzIHLDqXBvbmQgQ2l0aXZlcnNpdHksIHF1aSBzw6lsZWN0aW9ubmUgbcOpdGljdWxldXNlbWVudCBzZXMgYW5pbWF0ZXVycyBldCBwcmVuZCBlbiBjaGFyZ2UgbOKAmWFzcGVjdCBsb2dpc3RpcXVlIGRlIGzigJlvcmdhbmlzYXRpb24gZGUgbOKAmWF0ZWxpZXIgKHVuIHNlcnZpY2UgcG91ciBsZXF1ZWwgQ2l0aXZlcnNpdHkgcHLDqWzDqHZlIDI1JSBkdSB0b3RhbCwgZnJhaXMgZOKAmW9yZ2FuaXNhdGlvbiBkw6lkdWl0cykuPC9wPg0KPHA%VHLDqHMgY2VudHLDqSBzdXIgbGEgcXVhbGl0w6kgZGUgbOKAmcOpY2hhbmdlLCBDaXRpdmVyc2l0eSByw6p2ZSBhaW5zaSBkZSBmYWlyZSDDqWNsb3JlIGVuIGNoYWN1biBs4oCZZW52aWUgZGUgcGFydGFnZXIgY2UgcXVpIGxlIHJlbmQgdW5pcXVlIDogc29uIGV4cMOpcmllbmNlLiBBaW5zaSBhLXQtb24gcHUgcGFydGljaXBlciBlbiBNYXJzIMOgIHVuIGF0ZWxpZXIgZGUgZMOpY291dmVydGUgZHUgYmFsbGV0IGFuaW3DqSBwYXIgdW5lIGRhbnNldXNlIGNsYXNzaXF1ZSBjb25maXJtw6llLCBvdSDDoCB1biBhdXRyZSB2aXNhbnQgw6AgZm9ybWVyIGxlcyBhdWRpdGV1cnMgw6AgbOKAmWFydCBkZSBs4oCZaW50ZXJ2aWV3IHByb3Bvc8OpIHBhciB1biBqb3VybmFsaXN0ZSByZW5vbW3DqS48L3A%DQo8cD5Gb25kw6kgcGFyIDxhIGhyZWY9Imh0dHBzOi8vdHdpdHRlci5jb20vIyEva25pbGZvIj4gS2V5dmFuIE5pbGZvcm91c2hhbiA8L2E%YXByw6hzIHVuZSBwcmVtacOocmUgY2FycmnDqHJlIGRlIFZDIGNoZXogTmV4dFN0YWdlLCBDaXRpdmVyc2l0eSBpbGx1c3RyZSBwYXJmYWl0ZW1lbnQgZGV1eCBjb25jZXB0cyB0csOocyBlbiB2b2d1ZTogbGUgPGVtPmxlYW48L2VtPiBldCBsYSA8ZW0%Y3VyYXRpb248L2VtPi4gRGFucyB1biBwcmVtaWVyIHRlbXBzLCBDaXRpdmVyc2l0eSBhIGVuIGVmZmV0IGNob2lzaSBk4oCZdXRpbGlzZXIgbGEgc29sdXRpb24gRXZlbnRicml0ZSAoYWluc2kgcXVlIE1haWxjaGltcCBldCBMYXVuY2hyb2NrKSBsZSB0ZW1wcyBkZSBwcsOpY2lzZXIgc29uIG1vZMOobGUuIEJpZW4gbHVpIGVuIGEgcHJpcyBhdXggdnVlcyBkdSBzdWNjw6hzIGRlcyBwcmVtaWVycyBhdGVsaWVycywgcXVpIG9udCB2YWxpZMOpIHNhIGNvbnZpY3Rpb24gcXXigJlpbCB5IGEgdW5lIHbDqXJpdGFibGUgdmFsZXVyIGFqb3V0w6llIMOgIG5lIHByb3Bvc2VyIHF1ZSBkZXMgZXhww6lyaWVuY2VzIHF1YWxpdGF0aXZlcyAobGUgdGFyaWYgbW95ZW4gw6l0YW50IGRlIDUwIGV1cm9zIHBhciBwZXJzb25uZS4pPC9wPg0KPHA%RW4gYXR0ZW5kYW50IGxhIHZlcnNpb24gMi4wLCBkZSBub21icmV1eCBhdGVsaWVycyBzb250IGTDqWrDoCBwcm9ncmFtbcOpcywgcGFybWkgbGVzcXVlbHMgwqsgRmFpcmUgc2VzIGNvdXJzZXMgw6AgQ2hpbmF0b3duIMK7LCDCqyBQcmVuZHJlIGxlcyBtb251bWVudHMgcGFyaXNpZW5zIGVuIHBob3RvIMK7IGV0IMKrIExlIHBpYW5vIGVuIDQgaGV1cmVzIMK7IChlbiBkZXV4IHBhcnRpZXMpLjwvcD4NCjxwPlZvdXMgcsOqdmV6IGTigJl1biBhdGVsaWVyIGVuIHBhcnRpY3VsaWVyID8gRGVtYW5kZXotbGUsIDxhIGhyZWY9Imh0dHA6Ly9mZWVkYmFjay5jaXRpdmVyc2l0eS5jb20iPnVuZSBwYWdlIGTDqWRpw6llPC9hPiBlc3QgbMOgIHBvdXIgw6dhLiBTaSBsYSBjb21tdW5hdXTDqSB2b3RlIHBvdXIgdm90cmUgaWTDqWUsIDxhIGhyZWY9Imh0dHA6Ly9jaXRpdmVyc2l0eS5ldmVudGJyaXRlLmNvbSI%IENpdGl2ZXJzaXR5PC9hPiBzZSBjaGFyZ2VyYSBkZSB0cm91dmVyIGzigJlpbnRlcnZlbmFudCBpZMOpYWwsIGV0IGRlIGRvbm5lciB2aWUgw6AgbOKAmWF0ZWxpZXIuICBFdCB2b3VzLCBxdeKAmWF2ZXotdm91cyDDoCBwYXJ0YWdlciA:PC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvY2l0aXZlcnNpdHktbGUtZmV1LWRlLWNhbXAtMi0wL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjE8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KDQoJCTx0aXRsZT5TUEVBUiBwcm9mZXNzaW9ubmFsaXNlIGxlIGNyb3dkbGVuZGluZyDDqXRoaXF1ZTwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3NwZWFyLXByb2Zlc3Npb25uYWxpc2UtbGUtY3Jvd2RsZW5kaW5nLWV0aGlxdWUvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjcvc3BlYXItcHJvZmVzc2lvbm5hbGlzZS1sZS1jcm93ZGxlbmRpbmctZXRoaXF1ZS8jY29tbWVudHM8L2NvbW1lbnRzPg0KCQk8cHViRGF0ZT5UdWUsIDI3IE1hciAyMDEyIDE2OjA4OjQ5ICswMDAwPC9wdWJEYXRlPg0KCQk8ZGM6Y3JlYXRvcj5KdWxpZW4gTWVjaGluPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2Nyb3dkbGVuZGluZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtzcGVhcl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4ODA8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVtBcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi4NCg0KSW50ZXJuZXQgcGVybWV0IGRlIGNyw6llciBkZXMgYmFucXVlcyBtb2lucyBjaMOocmVzLCBtYWlzIGF1c3NpIGRlcyBiYW5xdWVzIHBsdXMgw6l0aGlxdWVzLiBD4oCZZXN0IGVuIHRvdXQgY2FzIGxhIGNvbnZpY3Rpb24gZGUgPGEgaHJlZj0iaHR0cDovL3NwZWFyLmZyIj5TUEVBUjwvYT4gKFNvY2nDqXTDqSBwb3VyIHVuZSDDiXBhcmduZSBBY3RpdmVtZW50IFJlc3BvbnNhYmxlKSwgY29vcMOpcmF0aXZlIGZvbmTDqWUgYXZhbnQgbcOqbWUgbGV1ciBzb3J0aWUgZOKAmcOpY29sZSBwYXIgPGEgaHJlZj0iaHR0cDovL3R3aXR0ZXIuY29tLyMhL25pY29kYWJiYWdoaWFuIj5OaWNvbGFzIERhYmJhZ2hpYW48L2E%IChIRUMpLCA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvcXVlbnRpbmJkaCI%UXVlbnRpbiBCcmFja2VycyBkZSBIdWdvPC9hPiAoQ2VudHJhbGUgUGFyaXMpIGV0IDxhIGhyZWY9IiBodHRwOi8vdHdpdHRlci5jb20vIyEvZmRlc3JvemllcnMgIj5GcmFuw6dvaXMgRGVzcm96aWVyczwvYT4gKERhdXBoaW5lKS5dXT48L2Rlc2NyaXB0aW9uPg0KCQkJPGNvbnRlbnQ6ZW5jb2RlZD48IVtDREFUQVs8cD5BcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9QRW50cmVtb250Ij5QaWVycmUgRW50cmVtb250PC9hPi48L3A%DQo8cD5JbnRlcm5ldCBwZXJtZXQgZGUgY3LDqWVyIGRlcyBiYW5xdWVzIG1vaW5zIGNow6hyZXMsIG1haXMgYXVzc2kgZGVzIGJhbnF1ZXMgcGx1cyDDqXRoaXF1ZXMuIEPigJllc3QgZW4gdG91dCBjYXMgbGEgY29udmljdGlvbiBkZSA8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIiPlNQRUFSPC9hPiAoU29jacOpdMOpIHBvdXIgdW5lIMOJcGFyZ25lIEFjdGl2ZW1lbnQgUmVzcG9uc2FibGUpLCBjb29ww6lyYXRpdmUgZm9uZMOpZSBhdmFudCBtw6ptZSBsZXVyIHNvcnRpZSBk4oCZw6ljb2xlIHBhciA8YSBocmVmPSJodHRwOi8vdHdpdHRlci5jb20vIyEvbmljb2RhYmJhZ2hpYW4iPk5pY29sYXMgRGFiYmFnaGlhbjwvYT4gKEhFQyksIDxhIGhyZWY9Imh0dHA6Ly90d2l0dGVyLmNvbS8jIS9xdWVudGluYmRoIj5RdWVudGluIEJyYWNrZXJzIGRlIEh1Z288L2E%IChDZW50cmFsZSBQYXJpcykgZXQgPGEgaHJlZj0iIGh0dHA6Ly90d2l0dGVyLmNvbS8jIS9mZGVzcm96aWVycyAiPkZyYW7Dp29pcyBEZXNyb3ppZXJzPC9hPiAoRGF1cGhpbmUpLjwvcD4NCjxwPlNQRUFSIHByb3Bvc2UgZGUgZsOpZMOpcmVyIGxlcyDDqXBhcmduYW50cyBhZmluIGRlIGxldXIgcGVybWV0dHJlIGRlIG1ldHRyZSBsZXVyIGFyZ2VudCBhdSBzZXJ2aWNlIGRlIHByb2pldHMgcXXigJlpbHMgY2hvaXNpc3NlbnQsIGV0IHF1aSBvbnQgZHUgc2VucyDDoCBsZXVycyB5ZXV4ICjDqWNvbG9naXF1ZXMsIHNvY2lhdXggb3UgY3VsdHVyZWxzKS4gw4AgbGEgZGlmZsOpcmVuY2UgZGUgc3RydWN0dXJlcyBjb21tZSBLaWNrc3RhcnRlciBvdSBNeW1ham9yY29tcGFueSwgU1BFQVIgcHJvcG9zZSBk4oCZaW52ZXN0aXIgZW4gZGV0dGUsIGV0IHPDqWxlY3Rpb25uZSBsZXMgaW5pdGlhdGl2ZXMgcXXigJlpbCBlc3QgcG9zc2libGUgZOKAmWFpZGVyIGVuIGZvbmN0aW9uIGRlIGNyaXTDqHJlcyDDqXRoaXF1ZXMgZXQgZmluYW5jaWVycy4gIExlIHRvdXQgc2FucyBhdWN1biByaXNxdWUgcG91ciBs4oCZw6lwYXJnbmFudC48L3A%DQo8cD5Qb3VyIHJlbmRyZSBwb3NzaWJsZSBjZXR0ZSDDqXF1YXRpb24sIFNQRUFSIHPigJllc3QgYWxsacOpIMOgIGRlcyBiYW5xdWVzIChsZSBDcsOpZGl0IE11bmljaXBhbCBkZSBQYXJpcyAgcG91ciBsZSBtb21lbnQsIGRlcyBwYXJ0ZW5hcmlhdCBhdmVjIGxlIENyw6lkaXQgQ29vcMOpcmF0aWYgZXQgbGEgQ2Fpc3NlIGTigJkgw4lwYXJnbmUgc29udCBlbiBib25uZSB2b2llKSBxdWkgc8OpY3VyaXNlbnQgbGUgcHLDqnQgbW95ZW5uYW50IHVuZSBjb21taXNzaW9uIGRlc3RpbsOpZSDDoCBjb21wZW5zZXIgbGUgcmlzcXVlIGRlIGTDqWZhdXQuIEzigJllbnRyZXByZW5ldXIgb2J0aWVudCBhaW5zaSBmYWNpbGVtZW50IHVuIGNyw6lkaXQgcG91ciB1biB0YXV4IGluZsOpcmlldXIgYXUgdGF1eCBkdSBtYXJjaMOpIGV0IGzigJnDqXBhcmduYW50LCBtb3llbm5hbnQgdW5lIG1vZGlxdWUgZGltaW51dGlvbiBkZSBzb24gdGF1eCBkZSByZW5kZW1lbnQsIG1ldCBzb24gYXJnZW50IGF1IHNlcnZpY2UgZGUgc2VzIGNvbnZpY3Rpb25zLiBVbiBiw6luw6lmaWNlIGF1cXVlbCBz4oCZYWpvdXRlbnQgbGVzIGNsYXNzaXF1ZXMgZGlzcG9zaXRpZnMgZGUgZMOpZHVjdGlvbiBkZSBs4oCZSVNGIGV0IGRlIGzigJlJUlBQLCBwdWlzcXVlIGzigJnDqXBhcmduZSBzZSByw6lhbGlzZSBwYXIgbGEgc291c2NyaXB0aW9uIGRlIHBhcnRzIHNvY2lhbGVzIGRlIFNQRUFSLjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48L3A%DQo8cD5Nb2lucyBkZSAxNSUgZGVzIHByb2pldHMgc291bWlzIMOgIFNQRUFSIHNvbnQgcmV0ZW51cyBwYXIgc29uIGNvbWl0w6kuIFBvdXIgbGUgbW9tZW50LCAyMDAgMDAwIGV1cm9zIGTigJkgwqsgw6lwYXJnbmUgdHJhbnNwYXJlbnRlIMK7IG9udCBmaW5hbmPDqXMgMyBwcm9qZXRzLCBldCAyIHNvbnQgZW4gcGFzc2UgZGUgbOKAmcOqdHJlICg8YSBocmVmPSJodHRwOi8vc3BlYXIuZnIvcHJvamV0cy8xNiI%IENsYWlyICZhbXA7IE5ldCA8L2E%LCBlbnRyZXByaXNlIGTigJlpbnNlcnRpb24gcGFyIGxlIHRyYXZhaWwgZGFucyBsZSBzZWN0ZXVyIGRlIGzigJnDqWNvcHJvcHJldMOpIGV0IDxhIGhyZWY9Imh0dHA6Ly9zcGVhci5mci9wcm9qZXRzLzE4Ij4gQmFzaWxpYWRlIDwvYT4sIHN0cnVjdHVyZSBk4oCZYWlkZSBhdXggbWFsYWRlcyBkdSBTSURBKS4gNSBhdXRyZXMgbGVzIHJlam9pbmRyb250IGTigJlpY2kgbOKAmcOpdMOpICh1biBwcm9qZXQgdmlzYW50IMOgIGZvdXJuaXIgZGVzIGx1bmV0dGVzIGRlIHLDqWFsaXTDqSBhdWdtZW50w6llIGF1eCBtYWxhZGVzIGNocm9uaXF1ZXMgaW1tb2JpbGlzw6lzIHNlcmFpdCBub3RhbW1lbnQgZGFucyBsZXMgdHV5YXV4KS48L3A%DQo8cD5BdmlzIGF1eCBnZWVrcyBhdSBncmFuZCBjxZN1ciA6IGxhIHBsYXRlZm9ybWUsIGxhdXLDqWF0ZSBkdSBQcml4IFNGUiBKZXVuZXMgVGFsZW50cyBFbnRyZXByZW5ldXJpYXQgU29jaWFsLCBlc3QgY29kw6llIGVuIFJ1Ynkgb24gUmFpbHMuIEV0IGRlcyByZWNydXRlbWVudHMgc29udCBhdSBwcm9ncmFtbWXigKY8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy9zcGVhci1wcm9mZXNzaW9ubmFsaXNlLWxlLWNyb3dkbGVuZGluZy1ldGhpcXVlL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCgkJPHNsYXNoOmNvbW1lbnRzPjM8L3NsYXNoOmNvbW1lbnRzPg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%V2FsbGl0IGNyw6llIGRlcyBtdXJzIHZpcnR1ZWxzIGVuIHLDqWFsaXTDqSBhdWdtZW50w6llIGRhbnMgbGVzIGxpZXV4IHB1YmxpY3M8L3RpdGxlPg0KCQk8bGluaz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNy93YWxsaXQtY3JlZS1kZXMtbXVycy12aXJ0dWVscy1lbi1yZWFsaXRlLWF1Z21lbnRlZS1kYW5zLWxlcy1saWV1eC1wdWJsaWNzLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3dhbGxpdC1jcmVlLWRlcy1tdXJzLXZpcnR1ZWxzLWVuLXJlYWxpdGUtYXVnbWVudGVlLWRhbnMtbGVzLWxpZXV4LXB1YmxpY3MvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%VHVlLCAyNyBNYXIgMjAxMiAwOToyOTowNiArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%SnVsaWVuIE1lY2hpbjwvZGM6Y3JlYXRvcj4NCg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt3YWxsaXRdXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODUyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbPGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0id2FsbGl0IiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvbG9nb193YWxsaXRfaWNvbi5qcGciIGFsdD0iIiB3aWR0aD0iMjMyIiBoZWlnaHQ9IjkyIiAvPiBBcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9jZWNpbG9nZSIgdGFyZ2V0PSJfYmxhbmsiPkPDqWNpbGUgTG9nw6k8L2E%Lg0KDQpDcsOpw6llIHBhciA8YSBocmVmPSJodHRwOi8vd3d3LmxpbmtlZGluLmNvbS9wdWIvdmV5c2VsLWJlcmsvMTAvMTExLzIxMiI%VmV5c2VsIEJlcms8L2E%LCB1biBhbmNpZW4gZGUgVUMgQmVya2VsZXkgcGxlaW4gZOKAmWlkw6llcyBldCBkw6l0ZW50ZXVyIGTigJl1biBQaEQgZW4gUGh5c2lxdWUsIDxhIGhyZWY9Imh0dHA6Ly93d3cud2FsbGl0YXBwLmNvbS8iPldhbGxpdDwvYT4gZXN0IHVuZSBub3V2ZWxsZSBhcHBsaWNhdGlvbiBpUGhvbmUgZ3JhdHVpdGUgcXVpIGNoZXJjaGUgw6AgY2hhbmdlciBub3RyZSB2aXNpb24gZGVzIGxpZXV4IHB1YmxpY3M6IGxhbmPDqWUgZMOpYnV0IG1hcnMsIGzigJlhcHBsaWNhdGlvbiBwZXJtZXQgZGUgY29tbXVuaXF1ZXIgYXZlYyBsZXMgcGVyc29ubmVzIHF1aSBzb250IGF1IG3Dqm1lIGVuZHJvaXQgYXUgbcOqbWUgbW9tZW50IHBhciBs4oCZaW50ZXJtw6lkaWFpcmUgZGUgbGEgcsOpYWxpdMOpIGF1Z21lbnTDqWUuXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0id2FsbGl0IiBzcmM9ImFzc2V0cy9mZWVkc19pbWFnZXMvbG9nb193YWxsaXRfaWNvbi5qcGciIGFsdD0iIiB3aWR0aD0iMjMyIiBoZWlnaHQ9IjkyIiAvPiBBcnRpY2xlIMOpY3JpdCBwYXIgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9jZWNpbG9nZSIgdGFyZ2V0PSJfYmxhbmsiPkPDqWNpbGUgTG9nw6k8L2E%LjwvcD4NCjxwPkNyw6nDqWUgcGFyIDxhIGhyZWY9Imh0dHA6Ly93d3cubGlua2VkaW4uY29tL3B1Yi92ZXlzZWwtYmVyay8xMC8xMTEvMjEyIj5WZXlzZWwgQmVyazwvYT4sIHVuIGFuY2llbiBkZSBVQyBCZXJrZWxleSBwbGVpbiBk4oCZaWTDqWVzIGV0IGTDqXRlbnRldXIgZOKAmXVuIFBoRCBlbiBQaHlzaXF1ZSwgPGEgaHJlZj0iaHR0cDovL3d3dy53YWxsaXRhcHAuY29tLyI%V2FsbGl0PC9hPiBlc3QgdW5lIG5vdXZlbGxlIGFwcGxpY2F0aW9uIGlQaG9uZSBncmF0dWl0ZSBxdWkgY2hlcmNoZSDDoCBjaGFuZ2VyIG5vdHJlIHZpc2lvbiBkZXMgbGlldXggcHVibGljczogbGFuY8OpZSBkw6lidXQgbWFycywgbOKAmWFwcGxpY2F0aW9uIHBlcm1ldCBkZSBjb21tdW5pcXVlciBhdmVjIGxlcyBwZXJzb25uZXMgcXVpIHNvbnQgYXUgbcOqbWUgZW5kcm9pdCBhdSBtw6ptZSBtb21lbnQgcGFyIGzigJlpbnRlcm3DqWRpYWlyZSBkZSBsYSByw6lhbGl0w6kgYXVnbWVudMOpZS48L3A%DQo8cCBzdHlsZT0idGV4dC1hbGlnbjogY2VudGVyOyI%PC9wPg0KPHAgc3R5bGU9InRleHQtYWxpZ246IGxlZnQ7Ij5FP24gZmFpdCwgV2FsbGl0IG3DqWxhbmdlIGxlcyB0cmFpdHMgZGVzIHBsdXMgZ3JhbmRzIHLDqXNlYXV4IHNvY2lhdXg6IGxlcyBpbnRlcmFjdGlvbnMgc29jaWFsZXMgZGUgRmFjZWJvb2ssIGxlcyAxNDAgY2FyYWN0w6hyZXMgbWF4aW11bSBkZSBUd2l0dGVyIGV0IGxhIGfDqW9sb2NhbGlzYXRpb24gZGUgRm91cnNxdWFyZSwgbGUgdG91dCBhcHBsaXF1w6kgw6AgZGVzIG11cnMgdmlydHVlbHMgYWNjZXNzaWJsZXMgZW4gcsOpYWxpdMOpIGF1Z21lbnTDqWUuIEltYWdpbm9ucyB1biDDqXbDqG5lbWVudCBpbXBvcnRhbnQgY29tbWUgdW4gbWF0Y2ggZGUgZm9vdCwgb3UgdW4gZmVzdGl2YWw6IGxlcyBwYXJ0aWNpcGFudHMgbuKAmWF1cm9udCBxdeKAmcOgIG91dnJpciBs4oCZYXBwbGljYXRpb24sIGV0IHNlIGfDqW9sb2NhbGlzZXIgcG91ciB2b2lyIGFwcGFyYWl0cmUgbGUgbXVyIHZpcnR1ZWwgw6AgdHJhdmVycyBsYSBjYW3DqXJhIGRlIGxldXIgaVBob25lIGV0IGNvbW11bmlxdWVyIGVudHJlIGV1eC4gUGhvdG9zLCBjb21tZW50YWlyZXMsIHZpZMOpb3MsIG91IG1lc3NhZ2VzIGF1ZGlvcy4uIFRvdXQgZXN0IHBvc3NpYmxlITwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij48L3A%DQo8cD5XYWxsaXQgYSBkw6lqw6AgY3LDqcOpIHBsdXMgZGUgNzAwIG11cnMgdW4gcGV1IHBhcnRvdXQgZGFucyBsZSBtb25kZSAoTG9uZHJlcywgVG9reW8sIE5ldy1Zb3JrLCBQYXJpcy4uKS4gVW5lIGZvaXMgc3VyIHBsYWNlLCBvbiBwZXV0IGFwcG9ydGVyIHNhIGNvbnRyaWJ1dGlvbiBzb2l0IGFub255bWVtZW50LCBzb2l0IGVuIHNlIGxvZ2dhbnQgc3VyIEZhY2Vib29rIG91IFR3aXR0ZXI6IGJpZW50w7R0LCBkZXMgZm9uY3Rpb25zIHNvY2lhbGVzIHBlcm1ldHRhbnQgZGUgZmlsdHJlciBsZXMgcG9zdHMgKGFtaXMgRmFjZWJvb2sgIHNldWxlbWVudCBwYXIgZXhlbXBsZSkgc2Vyb250IMOpZ2FsZW1lbnQgZGlzcG9uaWJsZXMuPC9wPg0KPHA%QWxvcnMgcXVlIGxlcyBhdXRyZXMgYXBwcyBnw6lvbG9jYWxpc8OpZXMgZXQgbGVzIHLDqXNlYXV4IHNvY2lhdXggY29tbWUgRm91cnNxdWFyZSBzZSBmb2NhbGlzZW50IGfDqW7DqXJhbGVtZW50IHN1ciBsZXMgcHJvZmlscyBkZXMgdXRpbGlzYXRldXJzLCBjZWxsZS1jaSBhbWJpdGlvbm5lIGRlIGRvbm5lciB2aWUgYXV4IGxpZXV4IGV1eC1tw6ptZXMgZ3LDomNlIMOgIGxldXJzIHZpc2l0ZXVycy4gQmVyayBpbnNpc3RlIGTigJlhaWxsZXVycyBzdXIgbOKAmWlkw6llIHF1ZSBXYWxsaXQg4oCcPGVtPmNvbnRyaWJ1ZSDDoCBlbnRyZXRlbmlyIGzigJllc3NlbmNlIGRlcyBsaWV1eDwvZW0%4oCdIGV0IMOgIOKAnDxlbT5jdWx0aXZlciBsZXVyIHBlcnNvbm5hbGl0w6k8L2VtPuKAnSBncsOiY2UgYXUgcGFydGFnZSBk4oCZZXhww6lyaWVuY2VzLCBkZSBwaG90b3MsIGRlIGNvbW1lbnRhaXJlcyBkZXMgZ2VucyBxdWkgeSBwYXNzZW50IHBoeXNpcXVlbWVudC48L3A%DQo8cD48aWZyYW1lIHdpZHRoPSI1NjAiIGhlaWdodD0iMzE1IiBzcmM9Imh0dHA6Ly93d3cueW91dHViZS5jb20vZW1iZWQvTXgxQ3kzc21ScjAiIGZyYW1lYm9yZGVyPSIwIiBhbGxvd2Z1bGxzY3JlZW4%PC9pZnJhbWU%PC9wPg0KPHA%V2FsbGl0IGEgcsOpY2VtbWVudCBsZXbDqSAxLjJNJCBkZSBmb25kcyBhdXByw6hzIGRlIGRpZmbDqXJlbnRzIGJ1c2luZXNzIGFuZ2VscyBldCBmb25kcyBk4oCZaW52ZXN0aXNzZW1lbnRzLCBldCBkZXMgdmVyc2lvbnMgaVBhZCBldCBBbmRyb2lkIHNvbnQgZW4gY291cnMgZGUgZMOpdmVsb3BwZW1lbnQuIElsIHPigJlhZ2lyYSBlbnN1aXRlIGRlIG1vbsOpdGlzZXIgbGUgcHJvamV0IGVuIGltcGxpcXVhbnQgZGVzIHBhcnRlbmFpcmVzIGV0IGRlcyBncmFuZGVzIG1hcnF1ZXMsIG5vdGFtbWVudCBlbiBsZXMgYWlkYW50IMOgIGNyw6llciBsZXVycyBwcm9wcmVzIG11cnMvcGFubmVhdXggZGUgcHViIGludGVyYWN0aWZzIGV0IHZpcnR1ZWxzLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI3L3dhbGxpdC1jcmVlLWRlcy1tdXJzLXZpcnR1ZWxzLWVuLXJlYWxpdGUtYXVnbWVudGVlLWRhbnMtbGVzLWxpZXV4LXB1YmxpY3MvZmVlZC88L3dmdzpjb21tZW50UnNzPg0KCQk8c2xhc2g6Y29tbWVudHM%NDwvc2xhc2g6Y29tbWVudHM%DQoNCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPlNjaWVudGlwb2xlIEluaXRpYXRpdmUgZsOqdGUgc2VzIDEwIGFuczwvdGl0bGU%DQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLzwvbGluaz4NCgkJPGNvbW1lbnRzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzI2L3NjaWVudGlwb2xlLWluaXRpYXRpdmUtZmV0ZS1zZXMtMTAtYW5zLyNjb21tZW50czwvY29tbWVudHM%DQoJCTxwdWJEYXRlPk1vbiwgMjYgTWFyIDIwMTIgMDk6MTg6MjYgKzAwMDA8L3B1YkRhdGU%DQoJCTxkYzpjcmVhdG9yPkp1bGllbiBNZWNoaW48L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc2NpZW50aXBvbGUgaW5pdGlhdGl2ZV1dPjwvY2F0ZWdvcnk%DQoNCgkJPGd1aWQgaXNQZXJtYUxpbms9ImZhbHNlIj5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vP3A9MjM4NDE8L2d1aWQ%DQoJCTxkZXNjcmlwdGlvbj48IVtDREFUQVs8YSBocmVmPSJodHRwOi8vMTBhbnMtc2NpZW50aXBvbGUtaW5pdGlhdGl2ZS5vcmciPlNjaWVudGlww7RsZSBJbml0aWF0aXZlPC9hPiBlc3QgdW5lIGFzc29jaWF0aW9uIGRvbnQgbGUgYnV0IGVzdCBkZSBmaW5hbmNlciBsZXMgc3RhcnR1cHMgaW5ub3ZhbnRlcyBlbiBJbGUgZGUgRnJhbmNlLiBNZW1icmUgZGUgRnJhbmNlIEluaXRpYXRpdmUsIHByZW1pZXIgcsOpc2VhdSBkZSBmaW5hbmNlbWVudCBldCBk4oCZYWNjb21wYWduZW1lbnQgZGVzIGVudHJlcHJpc2VzIGVuIEZyYW5jZSwgU2NpZW50aXDDtGxlIEluaXRpYXRpdmUgYXBwb3J0ZSB1bmUgc29sdXRpb24gZGUgZmluYW5jZW1lbnQgcGFyIGxlIGJpYWlzIGR1IHByw6p0IGTigJlob25uZXVyIGRlcHVpcyAxMCBhbnMgIQ0KXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGEgaHJlZj0iaHR0cDovLzEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnIj5TY2llbnRpcMO0bGUgSW5pdGlhdGl2ZTwvYT4gZXN0IHVuZSBhc3NvY2lhdGlvbiBkb250IGxlIGJ1dCBlc3QgZGUgZmluYW5jZXIgbGVzIHN0YXJ0dXBzIGlubm92YW50ZXMgZW4gSWxlIGRlIEZyYW5jZS4gTWVtYnJlIGRlIEZyYW5jZSBJbml0aWF0aXZlLCBwcmVtaWVyIHLDqXNlYXUgZGUgZmluYW5jZW1lbnQgZXQgZOKAmWFjY29tcGFnbmVtZW50IGRlcyBlbnRyZXByaXNlcyBlbiBGcmFuY2UsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIGFwcG9ydGUgdW5lIHNvbHV0aW9uIGRlIGZpbmFuY2VtZW50IHBhciBsZSBiaWFpcyBkdSBwcsOqdCBk4oCZaG9ubmV1ciBkZXB1aXMgMTAgYW5zICE8L3A%DQo8cD5MZSBwcsOqdCBk4oCZaG9ubmV1ciBlc3QgdW4gcHLDqnQgw6AgdGF1eCAwIHF1ZSBwZXV0IHJlY2V2b2lyIHRvdXQgY3LDqWF0ZXVyIGTigJllbnRyZXByaXNlLCBzYW5zIGdhcmFudGllIHBlcnNvbm5lbGxlIGV0IGRvbnQgbGUgbW9udGFudCBwZXV0IGFsbGVyIGp1c3F14oCZw6AgNjAgMDAwIGV1cm9zIHBhciBlbnRyZXByaXNlLiBM4oCZb2JqZWN0aWYgZHUgcHLDqnQgZOKAmWhvbm5ldXIgZXN0IGTigJlhbW9yY2VyIGxhIGNvbW1lcmNpYWxpc2F0aW9uIGTigJl1biBwcm9kdWl0IG91IGTigJl1bmUgdGVjaG5vbG9naWUgZW4gdnVlIGTigJl1biBlZmZldCBkZSBsZXZpZXIgcG91ciBs4oCZb2J0ZW50aW9uIGRlIHByw6p0cyBiYW5jYWlyZXMuPC9wPg0KPHA%UG91ciBwcsOpdGVuZHJlIMOgIGNlIHR5cGUgZGUgcHLDqnQsIGwmIzgyMTc7ZW50cmVwcmlzZSBkb2l0IGF2b2lyIG1vaW5zIGRlIDMgYW5zLCDDqnRyZSBpbnN0YWxsw6llIGVuIElsZSBkZSBGcmFuY2UsIHByb3Bvc2VyIHVuZSBpbm5vdmF0aW9uLCBldCBwb3Nzw6lkZXIgdW4gcG90ZW50aWVsIGRlIGNyw6lhdGlvbnMgZCYjODIxNztlbXBsb2lzLjwvcD4NCjxwPlBvdXIgZsOqdGVyIHNhIDEww6htZSBhbm7DqWUgZGUgc291dGllbiBhdXggc3RhcnQgdXAsIFNjaWVudGlww7RsZSBJbml0aWF0aXZlIG9yZ2FuaXNlIHVuIMOpdsOobmVtZW50IGRlIDE0aCDDoCAxOWggbGUgMjggTWFycyDDoCBs4oCZaMO0dGVsIGRlIHZpbGxlIGRlIFBhcmlzLiBMZSA8YSBocmVmPSJodHRwOi8vd3d3LjEwYW5zLXNjaWVudGlwb2xlLWluaXRpYXRpdmUub3JnL3Byb2dyYW1tZS5odG1sIj5wcm9ncmFtbWU8L2E%IGFubm9uY2UgbGEgdmVudWUgZGUgUmFvdWwgTWFsbGFydCwgRGlyZWN0ZXVyIEJ1c2luZXNzIERldmVsb3BwZW1lbnQgZCYjODIxNztBcmNob3MsIG91IGVuY29yZSBkZSBSYWZpIEhhbGFkamlhbiwgZm9uZGF0ZXVyIGRlIE5hYmF6dGFnLiBMZXMgaW5zY3JpcHRpb25zIHNvbnQgPGEgaHJlZj0iaHR0cDovL3d3dy4xMGFucy1zY2llbnRpcG9sZS1pbml0aWF0aXZlLm9yZy9pbnNjcmlwdGlvbi5odG1sIj5pY2k8L2E%IGV0IGwmIzgyMTc7YWN0dWFsaXTDqSBkdSBTY2llbnRpcG9sZSBlc3QgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jIS9TY2llbnRJbml0aWF0aXYiPmzDoC4gPC9hPjwvcD4NCjxwPjxpZnJhbWUgd2lkdGg9IjU2MCIgaGVpZ2h0PSIzMTUiIHNyYz0iaHR0cDovL3d3dy55b3V0dWJlLmNvbS9lbWJlZC9DcVYwVW82SDFiVSIgZnJhbWVib3JkZXI9IjAiIGFsbG93ZnVsbHNjcmVlbj48L2lmcmFtZT48L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yNi9zY2llbnRpcG9sZS1pbml0aWF0aXZlLWZldGUtc2VzLTEwLWFucy9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz4xPC9zbGFzaDpjb21tZW50cz4NCg0KCQk8L2l0ZW0%DQoJCTxpdGVtPg0KCQk8dGl0bGU%VENGUiDigJMgTGUgemFwcGluZyBkZSBsYSBzZW1haW5lPC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjMvdGNmci0lZTIlODAlOTMtbGUtemFwcGluZy1kZS1sYS1zZW1haW5lLTIvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAyMyBNYXIgMjAxMiAxODoyNDozNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%Q2VkcmljIE8nTmVpbGw8L2RjOmNyZWF0b3I%DQoNCgkJCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbTm9uIGNsYXNzw6ldXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc3RhcnR1cF1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVt0Y2ZyXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3phcHBpbmddXT48L2NhdGVnb3J5Pg0KDQoJCTxndWlkIGlzUGVybWFMaW5rPSJmYWxzZSI%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLz9wPTIzODMyPC9ndWlkPg0KCQk8ZGVzY3JpcHRpb24%PCFbQ0RBVEFbTGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQnYXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuDQoNCi0gQW50b2luZSBWaWFsbGUsIHNlcmlhbCBlbnRyZXByZW5ldXIgdmllbnQgZGUgY2FydG9ncmFwaGllciBsZXMgYWlkZXMgZXQgc3VidmVudGlvbnMgZGlzcG9uaWJsZXMgZW4gRnJhbmNlIHBvdXIgbGVzIGNyw6lhdGV1cnMgZCdlbnRyZXByaXNlLiBDaGFxdWUgbGlnbmUgY29ycmVzcG9uZCBhdSBuaXZlYXUgZGUgbWF0dXJpdMOpIGQndW5lIHNvY2nDqXTDqS4gVm91cyBwb3VycmV6IGxhIHJldHJvdXZlciDDoCA8YSBocmVmPSJodHRwOi8vd3d3LmFpZGVzLWNyZWF0aW9uLmZyL29mZnJlLXNwZWFjdXRlY2lhbGUtaW50ZXJuZXQuaHRtbCI%Y2V0dGUgYWRyZXNzZTwvYT4uXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%TGEgc3RhcnR1cCBmcmFuw6dhaXNlIDxzdHJvbmc%U29mdW4gR2FtaW5nPC9zdHJvbmc%IGEgaW50cm9kdWl0IGNldHRlIHNlbWFpbmUgbGVzIG1pc2VzIGQmIzgyMTc7YXJnZW50IHN1ciBzb24gc2l0ZSBkZSBwYXJpcyBzcG9ydGlmcyBjb21tdW5hdXRhaXJlIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmV0a3VwLmZyLyI%QmV0a3VwPC9hPi4gUGFyYWxsw6hsZW1lbnQgw6AgY2V0dGUgaW50cm9kdWN0aW9uLCBsZSBzaXRlIG9mZnJlIMOpZ2FsZW1lbnQgdW4gcGx1cyBncmFuZCBjaG9peCBkZSBjb21ww6l0aXRpb25zIHNwb3J0aXZlcyBzdXIgbGVzcXVlbGxlcyBwYXJpZXIuPC9wPg0KPHA%LSBBbnRvaW5lIFZpYWxsZSwgc2VyaWFsIGVudHJlcHJlbmV1ciB2aWVudCBkZSBjYXJ0b2dyYXBoaWVyIGxlcyBhaWRlcyBldCBzdWJ2ZW50aW9ucyBkaXNwb25pYmxlcyBlbiBGcmFuY2UgcG91ciBsZXMgY3LDqWF0ZXVycyBkJiM4MjE3O2VudHJlcHJpc2UuIENoYXF1ZSBsaWduZSBjb3JyZXNwb25kIGF1IG5pdmVhdSBkZSBtYXR1cml0w6kgZCYjODIxNzt1bmUgc29jacOpdMOpLiBWb3VzIHBvdXJyZXogbGEgcmV0cm91dmVyIMOgIDxhIGhyZWY9Imh0dHA6Ly93d3cuYWlkZXMtY3JlYXRpb24uZnIvb2ZmcmUtc3BlYWN1dGVjaWFsZS1pbnRlcm5ldC5odG1sIj5jZXR0ZSBhZHJlc3NlPC9hPi48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cueW91c2VlbWlpLmZyLyIgdGFyZ2V0PSJfYmxhbmsiPllvdXNlZW1paSA8L2E%cHLDqXNlbnRlIHNhIG5vdXZlbGxlIHZlcnNpb24sIGF2ZWMgdW4gbm91dmVhdSBkZXNpZ24sIGV0IHN1cnRvdXQgdW5lIG5vdXZlbGxlIGV4cMOpcmllbmNlIHV0aWxpc2F0ZXVyLiBEw6lzb3JtYWlzLCBsZSBsb2dpY2llbCBwZXJtZXQgYXVzc2kgZCYjODIxNzthbmFseXNlciBzYSBwcsOpc2VuY2Ugd2ViIHN1ciBGb3Vyc3F1YXJlLCBHb29nbGUgKywgRGFpbHltb3Rpb24sIFZpbWVvLCBldCBtw6ptZSBhdXByw6hzIGRlcyBraW9zcXVlcyBSZWxheS48L3A%DQo8cD4tTGUgcsOpc2VhdSBzb2NpYWwgbW9iaWxlIDxhIGhyZWY9Imh0dHBzOi8vcGF0aC5jb20vIj5QYXRoPC9hPiBsw6h2ZSAyMCBtaWxsaW9ucyBkZSBkb2xsYXJzLiBMZSByw6lzZWF1IHNvY2lhbCBkZSBwYXJ0YWdlIGRlIHBob3RvcyBsaW1pdMOpIMOgIDUwIGNvbnRhY3RzIGV0IGRpc3BvbmlibGUgZXhjbHVzaXZlbWVudCBzdXIgbOKAmWFwcGxpIGlQaG9uZSBkdSBtw6ptZSBub20gc2VyYWl0IGFpbnNpIHZhbG9yaXPDqSAyNTBNJC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuYmVkeWNhc2EuY29tLyI%QmVkeUNhc2E8L2E%IGdhZ25lIGxlcyBUcmF2ZWwgZOKAmU9yIGRhbnMgbGEgY2F0w6lnb3JpZSBzdGFydC11cCwgcXVpIHLDqWNvbXBlbnNlIGxlcyBtZWlsbGV1cnMgc2l0ZXMgZOKAmWUtdG91cmlzbWUuIEJlZHljYXNhLCBwZXJtZXQgbGEgbG9jYXRpb24gZGUgY2hhbWJyZXMgY2hleiBs4oCZaGFiaXRhbnQuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHBzOi8vc2Vlc21pYy5jb20vIj5TZWVzbWljPC9hPiBhbm5vbmNlIHVuZSB2YWd1ZSBkZSBsaWNlbmNpZW1lbnRzLiBMYSBzdGFydC11cCBmb25kw6llIHBhciA8c3Ryb25nPkxvw69jIExlIE1ldXI8L3N0cm9uZz4sIG9yZ2FuaXNhdGV1ciBkZSBsYSBjb25mw6lyZW5jZSA8c3Ryb25nPkxlV2ViPC9zdHJvbmc%IGRldnJhaXQgbGljZW5jaWVyIDE4IHBlcnNvbm5lcyBmYXV0ZSBkZSBidXNpbmVzcyBtb2RlbCB2aWFibGUuPC9wPg0KPHA%LTxhIGhyZWY9Imh0dHA6Ly93d3cuZWFzeS12ZXJyZXMuY29tLyI%RWFzeS12ZXJyZXM8L2E%LCBs4oCZb3B0aWNpZW4gbG93IGNvc3QgcXVpIGNvbXB0ZXJhaXQgcHLDqHMgZGUgNzUwIG9wdGljaWVucyBwYXJ0ZW5haXJlcyB2aWVudCBkZSBsZXZlciAxTeKCrC48L3A%DQo8cD4tIDxhIGhyZWY9Imh0dHA6Ly93d3cuaWxsaWNvdHJhdmVsLmNvbS8iIHRhcmdldD0iX2JsYW5rIj5pbGxpY290cmF2ZWw8L2E%LCBsZSBjb21wYXJhdGV1ciBkZSB2b2xzIGV0IGRlIHZveWFnZXMgb25saW5lIHZpZW50IGRlIGxhbmNlciB1bmUgbm91dmVsbGUgdmVyc2lvbiBkZSBzb24gaW50ZXJmYWNlLjwvcD4NCjxwPi08c3Ryb25nPiA8YSBocmVmPSJodHRwOi8vd3d3LnJveWFsY2FjdHVzLmNvbS8iPlJveWFsIENhY3R1czwvYT48L3N0cm9uZz4sIHNww6ljaWFsaXN0ZSBkdSBqZXUgZW4gbGlnbmUgY29tbXVuYXV0YWlyZSwgdmllbnQgZGUgbGV2ZXIgNTAwIDAwMCBldXJvcyBhdXByw6hzIGR1IGZvbmRzIGQmIzgyMTc7aW52ZXN0aXNzZW1lbnQgPHN0cm9uZz5YQW5nZSBQcml2YXRlIEVxdWl0eTwvc3Ryb25nPi4gT2JqZWN0aWYgYWZmaWNow6kgOiBkZXZlbmlyIHVuIGRlcyBsZWFkZXJzIGZyYW7Dp2FpcyBkdSBTb2NpYWwgR2FtaW5nIGVuIG1lbmFudCB1bmUgc3RyYXTDqWdpZSBjcm9zcy1jaGFubmVsLjwvcD4NCl1dPjwvY29udGVudDplbmNvZGVkPg0KCQkJPHdmdzpjb21tZW50UnNzPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzIzL3RjZnItJWUyJTgwJTkzLWxlLXphcHBpbmctZGUtbGEtc2VtYWluZS0yL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%Mzwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4NCgkJPGl0ZW0%DQoJCTx0aXRsZT5RdWFuZCBsZXMgZnLDqHJlcyBTYW13ZXIgcGFydGVudCBlbiBndWVycmUmIzgyMzA7PC90aXRsZT4NCgkJPGxpbms%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvcXVhbmQtbGVzLWZyZXJlcy1zYW13ZXItcGFydGVudC1lbi1ndWVycmUvPC9saW5rPg0KCQk8Y29tbWVudHM%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMjgvcXVhbmQtbGVzLWZyZXJlcy1zYW13ZXItcGFydGVudC1lbi1ndWVycmUvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%V2VkLCAyOCBNYXIgMjAxMiAxNjozMzoyNCArMDAwMDwvcHViRGF0ZT4NCg0KCQk8ZGM6Y3JlYXRvcj5KdWxpZW4gTWVjaGluPC9kYzpjcmVhdG9yPg0KCQkJCTxjYXRlZ29yeT48IVtDREFUQVtOb24gY2xhc3PDqV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtibGlldHprcmllZ11dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtndWVycmVdXT48L2NhdGVnb3J5Pg0KCQk8Y2F0ZWdvcnk%PCFbQ0RBVEFbc2Ftd2VyXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzgzODwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxpbWcgY2xhc3M9ImFsaWdubGVmdCIgdGl0bGU9InJvY2tldCBpbnRlcm5ldCIgc3JjPSJodHRwOi8vd3d3LmpvYnNwaW5veS5jb20vdXBsb2FkX2ZpbGVzL2ltYWdlcy83L2MvNS83YzVmOTNmNzBjNDg1YTEzODFiYjljMzEyMjNiMDhkOS5qcGciIGFsdD0iIiB3aWR0aD0iMzYwIiBoZWlnaHQ9IjkwIiAvPg0KVHJhZHVjdGlvbiBldCBhZGFwdGF0aW9uIGQndW4gPGEgaHJlZj0iaHR0cDovL3RlY2hjcnVuY2guY29tLzIwMTEvMTIvMjIvaW4tY29uZmlkZW50aWFsLWVtYWlsLXNhbXdlci1kZXNjcmliZXMtb25saW5lLWZ1cm5pdHVyZS1zdHJhdGVneS1hcy1hLWJsaXR6a3JpZWcvICAiPmFydGljbGUgPC9hPmRlIE1pa2UgQnV0Y2hlci4NCg0KUm9ja2V0IEludGVybmV0LCBsZSBmb25kcyBkZXMgZnLDqHJlcyBTYW13ZXIsIHZpZW50IGRlIHNlIGxhbmNlciBlbiBGcmFuY2UsIGV0IGNlcnRhaW5zIHZvbnQgY2VydGFpbmVtZW50IGVuIGZhaXJlIGxlcyBmcmFpcy4gUG91ciB2b3VzIGVuIGRvbm5lciB1biBhcGVyw6d1LCB2b2ljaSBsYSB0cmFkdWN0aW9uIGQndW4gZS1tYWlsIGNvbmZpZGVudGllbCBlbnZvecOpIHBhciBPbGl2ZXIgU2Ftd2VyIMOgIHNlcyDDqXF1aXBlcywgZGFucyBsZXF1ZWwgaWwgdXRpbGlzZSBsZSBtb3QgwqsgQmxpdHprcmllZyDCuyBwb3VyIGTDqWNyaXJlIHNhIHN0cmF0w6lnaWUgZGUgdmVudGUgZGUgbWV1YmxlcyBlbiBsaWduZS4NCl1dPjwvZGVzY3JpcHRpb24%DQoNCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGltZyBjbGFzcz0iYWxpZ25sZWZ0IiB0aXRsZT0icm9ja2V0IGludGVybmV0IiBzcmM9Imh0dHA6Ly93d3cuam9ic3Bpbm95LmNvbS91cGxvYWRfZmlsZXMvaW1hZ2VzLzcvYy81LzdjNWY5M2Y3MGM0ODVhMTM4MWJiOWMzMTIyM2IwOGQ5LmpwZyIgYWx0PSIiIHdpZHRoPSIzNjAiIGhlaWdodD0iOTAiIC8%PGJyIC8%DQpUcmFkdWN0aW9uIGV0IGFkYXB0YXRpb24gZCYjODIxNzt1biA8YSBocmVmPSJodHRwOi8vdGVjaGNydW5jaC5jb20vMjAxMS8xMi8yMi9pbi1jb25maWRlbnRpYWwtZW1haWwtc2Ftd2VyLWRlc2NyaWJlcy1vbmxpbmUtZnVybml0dXJlLXN0cmF0ZWd5LWFzLWEtYmxpdHprcmllZy8gICI%YXJ0aWNsZSA8L2E%ZGUgTWlrZSBCdXRjaGVyLjwvcD4NCjxwPlJvY2tldCBJbnRlcm5ldCwgbGUgZm9uZHMgZGVzIGZyw6hyZXMgU2Ftd2VyLCB2aWVudCBkZSBzZSBsYW5jZXIgZW4gRnJhbmNlLCBldCBjZXJ0YWlucyB2b250IGNlcnRhaW5lbWVudCBlbiBmYWlyZSBsZXMgZnJhaXMuIFBvdXIgdm91cyBlbiBkb25uZXIgdW4gYXBlcsOndSwgdm9pY2kgbGEgdHJhZHVjdGlvbiBkJiM4MjE3O3VuIGUtbWFpbCBjb25maWRlbnRpZWwgZW52b3nDqSBwYXIgT2xpdmVyIFNhbXdlciDDoCBzZXMgw6lxdWlwZXMsIGRhbnMgbGVxdWVsIGlsIHV0aWxpc2UgbGUgbW90IMKrIEJsaXR6a3JpZWcgwrsgcG91ciBkw6ljcmlyZSBzYSBzdHJhdMOpZ2llIGRlIHZlbnRlIGRlIG1ldWJsZXMgZW4gbGlnbmUuPC9wPg0KPHA%Um9ja2V0IGludGVybmV0LCBs4oCZaW5jdWJhdGV1ciBiZXJsaW5vaXMgY29ubnUgcG91ciBsZXMgdmVyc2lvbnMgYWxsZW1hbmRlcyBkZSBzdGFydHVwcyBhbcOpcmljYWluZXMgY29tbWUgWmFwcG9zIGV0IEdyb3Vwb24sIGEgbWFpbnRlbmFudCBkZSBncmFuZGVzIGFtYml0aW9ucywgc3VydG91dCBkYW5zIGxlIHNlY3RldXIgZHUgbWV1YmxlIGVuIGxpZ25lLCBzZWxvbiBkZXMgaW5mb3JtYXRpb25zIGRvbm7DqWVzIMOgIFRlY2hDcnVuY2ggRXVyb3BlLjwvcD4NCjxwPkRhbnMgdW4gZS1tYWlsIGNvbmZpZGVudGllbCBlbnZvecOpIHBhciBPbGl2ZXIgU2Ftd2VyIChxdWkgZGlyaWdlIGxlIGZvbmRzIGF2ZWMgc2VzIGZyw6hyZXMgTWFyYyBldCBBbGV4YW5kZXIpLCBpbCBkw6ljbGFyZSBxdWUgbGV1ciBzdHJhdMOpZ2llIGVzdCBkZSBkZXZlbmlyIGxlIMKrIG51bcOpcm8gdW4gwrsgZHUgZS1jb21tZXJjZSBkZSBtZXVibGVzIGRhbnMgbGVzIHByb2NoYWluZXMgYW5uw6llcy4gTWFpcyBsZSBsYW5nYWdlIHV0aWxpc8OpIGNvbW1lIGxlIG1vdCDCq2JsaXR6a3JpZWfCuyBtb250cmUgdW4gdHlwZSBkZSBtYW5hZ2VtZW50IHRyw6hzIGFncmVzc2lmLCBxdWkgbmUgbGFpc3NlIGF1Y3VuZSBwbGFjZSBhdXggc2VudGltZW50cywgZXQgcXVpIGFwcGFyYcOudCBjb21tZSDDqXRhbnQgdW4g4oCZbW9kdXMgb3BlcmFuZGnigJkgZGUgbGEgY3VsdHVyZSBkZSBSb2NrZXQgKGxlIG5vbSBuJiM4MjE3O2EgZCYjODIxNzthaWxsZXVycyBwYXMgw6l0w6kgY2hvaXNpIHBhciBoYXNhcmQpLiBTYW13ZXIgc%KAmWVzdCBkZXB1aXMgZXhjdXPDqSBk4oCZYXZvaXIgdXRpbGlzw6kgY2VzIHRlcm1lcy48L3A%DQo8cD5EYW5zIGzigJllLW1haWwsIMOpY3JpdCBkYW5zIHVuIGFuZ2xhaXMgaMOpc2l0YW50LCBPbGl2ZXIgU2Ftd2VyIGRpdCDDoCBzb24gw6lxdWlwZSBjaGV6IFJvY2tldCBxdeKAmWlsIHkgYSBzZXVsZW1lbnQgMyBzZWN0ZXVycyBkYW5zIGxlIGUtY29tbWVyY2UgcG91ciBjcsOpZXIgdW5lIGVudHJlcHJpc2UgZGUgcGx1c2lldXJzIG1pbGxpYXJkIGRlIGRvbGxhcnMgOjwvcD4NCjxwPiYjODIyMTsgPGVtPk7igJlvdWJsaWV6IGphbWFpcyBxdeKAmWlsIG7igJl5IGEgcXVlIGRldXggZ3JvcyBzZWN0ZXVycyBkYW5zIGxlIGUtY29tbWVyY2UgOiBBbWF6b24gZXQgWmFwcG9zLiBD4oCZZXN0IGxhIGRlcm5pw6hyZSBjaGFuY2UgZGUgdm90cmUgdmllIDogbGEgY2hhbmNlIHBvdXIgdW5lIGF1dHJlIGVudHJlcHJpc2UgZGUgZS1jb21tZXJjZSBkZSB2YWxvaXIgcGx1c2lldXJzIG1pbGxpYXJkIGRlIGRvbGxhcnMsIHVuZSBjaGFuY2UgcXVpIG5lIHNlIHJlcHLDqXNlbnRlcmEgcGx1cyAhPGJyIC8%DQpD4oCZZXN0IHRlcm1pbsOpLCBhcHLDqHMgQW1hem9uIGlsIG4mIzgyMTc7eSBhIHF1ZSBaYXBwb3MsIGRvbmMgb24gbmUgcGV1dCBwYXMgcmF0ZXIgY2V0dGUgb2NjYXNpb24sIHNpbm9uIHZvcyBwZXRpdHMtZW5mYW50cyB2b3VzIGRlbWFuZGVyb250IHRvdXRlIHZvdHJlIHZpZSBwb3VycXVvaSB2b3VzIG5lIGwmIzgyMTc7YXZleiBwYXMgZmFpdCA8L2VtPsK7LjwvcD4NCjxwPkFpbnNpLCBpbCBkaXQgw6Agc29uIMOpcXVpcGUgOiDCqyA8ZW0%Vm91cyBkZXZleiB0b3V0IGFudGljaXBlcjwvZW0%PGVtPiBkYW5zIHZvdHJlIHBsYW4gcG91ciBxdeKAmWlsIG7igJl5IGFpdCBwYXMgZGUgc3VycHJpc2UuIEplIG7igJlhY2NlcHRlIHBhcyBsZXMgc3VycHJpc2VzLiBKZSB2ZXV4IHF1ZSB0b3V0IHNvaXQgdmFsaWTDqSBldCB2w6lyaWZpw6kgPC9lbT48ZW0%cGFyIHZvdXMgdHJvaXMgZm9pczogdm91cyBkZXZleiBsZSBzaWduZXIgYXZlYyB2b3RyZSBzYW5nPC9lbT4uIMK7LCBldCBham91dGUgOiDCqzxlbT4gSmUgbmUgZmVyYWkgcXXigJl1biBwbGFuIGF1cXVlbCB2b3VzIGNyb2lyZXogw6AgMTAwJSBldCBxdWkgc2VyYSBzaWduw6kgYXZlYyBkdSBzYW5nPC9lbT7Cuy48L3A%DQo8cD5JbCBwcsOpY2lzZSDDqWdhbGVtZW50IHF1ZSBjZXJ0YWlucyBtYW5hZ2VycyBxdeKAmWlsIGVtcGxveWFpdCBldCBxdWkgbuKAmW9udCBwYXMgZmFpdCB0b3V0IGNlbGEsIGx1aSBvbnQgZmFpcmUgcGVyZHJlIMKrIGJlYXVjb3VwIGTigJlhcmdlbnQgwrsgZXQgcXVlIMKrIGNlcyBtYW5hZ2VycyBvbnQgcGVyZHUgNTAlIGRlIGxldXIgY2FwaXRhbCDCuyBldCBu4oCZb250IMKrIHBhcyBldSBkZSBzYWxhaXJlIHBlbmRhbnQgNiBtb2lzLiDCuzwvcD4NCjxwPkwmIzgyMTc7ZS1tYWlsIHByZW5kIHVuIHRvbiBwbHVzIGNvbnRyb3ZlcnPDqSwgc3VydG91dCBwb3VyIHVuIGJ1c2luZXNzbWFuIGNvbW1lIGx1aSwgbG9yc3F1JiM4MjE3O2lsIHV0aWxpc2UgbGUgbGFuZ2FnZSBkZSBsYSBzZWNvbmRlIGd1ZXJyZSBtb25kaWFsZSA6IMKrIDxlbT5MYSBjaG9zZSDDoCBsYXF1ZWxsZSBub3VzIGRldm9ucyBmYWlyZSBsZSBwbHVzIGF0dGVudGlvbiwgYyYjODIxNztlc3QgcXVlIG5vdXMgZGV2b25zIGJpZW4gY2hvaXNpciBsZSBtb21lbnQgcG91ciBsYSBCbGl0emtyaWVnLCBhZmluIHF1ZSBjaGFxdWUgcGF5cyBtZSBkaXNlIGF2ZWMgc29uIHNhbmcgcXVhbmQgY%KAmWVzdCBsZSBib24gbW9tZW50LiBKZSBzZXJhaSBwcsOqdCDigJMgbuKAmWltcG9ydGUgcXVhbmQgITwvZW0%IMK7PC9wPg0KPHA%wqsgQmxpdHprcmllZyDCuyDDqXRhaXQgYmllbiDDqXZpZGVtbWVudCB1biB0ZXJtZSB1dGlsaXPDqSBwYXIgbGVzIG1pbGl0YWlyZXMgYWxsZW1hbmRzIHBvdXIgZMOpY3JpcmUgbGV1ciB0YWN0aXF1ZSBkZSBkw6lwbGFjZW1lbnQgcmFwaWRlLCBzb2l0IHVuZSDCqyBHdWVycmUgw6ljbGFpciDCuy4gTGEgc291cmNlIGJpZW4gcGxhY8OpZSBxdWkgbm91cyBhIGZhaXQgc3VpdnJlIGNldCBlLW1haWwgbm91cyBkaXQgOiDCqyBTYW11ZWwgZXN0IGNvbm51IHBvdXIgdXRpbGlzZXIgZGVzIHRlcm1lcyBtaWxpdGFpcmVzLCBhdXRhbnQgcXVlIGRlIG5vbWJyZXV4IHRlcm1lcyBkZSBsYW5nYWdlIG9ic2PDqG5lcywgYWxvcnMgY2UgZ2VucmUgZGUg4oCYbW90aXZhdGlvbuKAmSBlc3QgYXNzdXLDqW1lbnQgbGUg4oCYc3R5bGUgZOKAmU9sbGkgU2Ftd2Vy4oCZLiBKZSBuZSBjb25uYWlzIHBhcyB1biBzZXVsIGF1dHJlIGJ1c2luZXNzbWFuIHV0aWxpc2FudCB1biB0ZWwgbGFuZ2FnZSDCuy48L3A%DQo8cD48aW1nIGNsYXNzPSJhbGlnbmxlZnQiIHRpdGxlPSJzYW13ZXIiIHNyYz0iaHR0cDovL3d3dy5jcnVuY2hiYXNlLmNvbS9hc3NldHMvaW1hZ2VzL3Jlc2l6ZWQvMDAwNi8yMTM3LzYyMTM3djEtbWF4LTI1MHgyNTAuanBnIiBhbHQ9IiIgd2lkdGg9IjI1MCIgaGVpZ2h0PSIxMDUiIC8%PC9wPg0KPHA%PHN0cm9uZz5Sw6lzdW3DqSBkZSBsJiM4MjE3O2UtbWFpbCA8L3N0cm9uZz46ICYjODIyMDs8ZW0%SmUgdm91cyBkb25uZSB0b3V0IGzigJlhcmdlbnQgZG9udCB2b3VzIGF1cmV6IGJlc29pbiBwb3VyIGdhZ25lciwgamUgdm91cyBkb25uZSB0b3V0ZSBtYSBjb25maWFuY2UsIG1haXMgdm91cyBkZXZleiByZXZlbmlyIHZlcnMgbW9pIGF2ZWMgdW4gc3VjY8OocyBpbsOpZ2Fsw6kuIFNpIGplIHZvaXMgcXVlIHZvdXMgZ2FzcGlsbGV6IG1vbiBhcmdlbnQsIHF1ZSB2b3VzIG7igJnDqnRlcyBwYXMgY29uY2VudHLDqXMgc3VyIGxlIGTDqXRhaWwgY29tbWUgdW4gYWxsZW1hbmQsIHF1ZSB2b3VzIG7igJnDqnRlcyBwYXMgcmFwaWRlcywgcXVlIHZvdXMgbuKAmcOqdGVzIHBhcyBhZ3Jlc3NpZnMsIHF1ZSB2b3VzIG5lIHN1aXZleiBwYXMgbGVzIGluZm9ybWF0aW9ucywgcXVlIHZvdXMgbuKAmWVmZmVjdHVleiBwYXMgbGEgbG9naXN0aXF1ZSBkZSBsYSBib25uZSBmYcOnb24sIHF1ZSB2b3VzIG5lIG1ldHRleiBwYXMgcmFwaWRlbWVudCBlbiBsaWduZSBsZXMgcHJvZHVpdHMsIG91IHF1ZSB2b3VzIGFjaGV0ZXogZGUgbWF1dmFpc2VzIG1hcmNoYW5kaXNlcywgYWxvcnMgamUgbWUgbWV0dHJhaXMgZW4gY29sw6hyZSBldCBqZSBmZXJhaXMgY29tbWUgZW4gUnVzc2llLCBvw7kgYWN0dWVsbGVtZW50IGF1Y3VuIGRlcyBtYW5hZ2VycyBuZSBkaXJpZ2UgbCYjODIxNztlbnRyZXByaXNlLiBK4oCZYWkgcGVyZHUgYmVhdWNvdXAgZOKAmWFyZ2VudCBldCBsZXMgZm9uZGF0ZXVycyBvbnQgcGVyZHUgNTAlIGRlIGxldXIgY2FwaXRhbC4gQXVjdW4gc2FsYWlyZSBu4oCZYSBwbHVzIMOpdMOpIHZlcnPDqSBwZW5kYW50IDYgbW9pcy4gTm91cyBzb21tZXMgZGFucyBsZSBtw6ptZSBiYXRlYXUsIHRvdXQgbGUgbW9uZGUgZG9pdCBlZmZlY3R1ZXIgc2EgbWlzc2lvbi48L2VtPjwvcD4NCjxwPjxlbT5Ob3VzIGFycml2b25zIHRhcmQsIGFsb3JzIG5vdXMgYXZvbnMgYmVzb2luIGTigJnDqnRyZSBsZXMgcGx1cyBhZ3Jlc3NpZnMuIFRlbGxlbWVudCBhZ3Jlc3NpZnMgcXVlIGNoYXF1ZSBjb25jdXJyZW50IHNlcmEgc3VycHJpcyBwYXJjZSBxdeKAmWlsIG5lIHBvdXZhaXQgIGltYWdpbmVyIHF1ZSBub3VzIHNlcmlvbnMgc2kgYWdyZXNzaWZzLiBQb3VyIHZvdXMgZG9ubmVyIHVuIGV4ZW1wbGUgYXUgQnLDqXNpbCBhdmVjIEdyb3Vwb24gOiBtb24gY29uY3VycmVudCByw6lhbGlzYWl0IHRyb2lzIG1pbGxpb25zIHBhciBtb2lzIGV0IGF2YWl0IDgwIHZlbmRldXJzLiAgSuKAmWFpIHN1cHBvc8OpIHF14oCZZW4gNCBtb2lzIGlsIGlyYWl0IGp1c3F14oCZw6AgMzAwIHZlbmRldXJzIGV0IDYgbWlsbGlvbnMsIGFsb3JzIGrigJlhaSBkaXQgw6AgbOKAmcOpcXVpcGUgZGUgcHJlbmRyZSA1MDAgdmVuZGV1cnMgZW4gNCBtb2lzLCBldCAxMCBtaWxsaW9ucyBkZSBjaGlmZnJlIGQmIzgyMTc7YWZmYWlyZXMgZW4gb250IGTDqWNvdWzDqXMuIE5vdXMgYXZvbnMgZ2FnbsOpLiBPdWksIGlsIHkgYSBldSBkZXMgZG9tbWFnZXMgY29sbGF0w6lyYXV4IChjZWxhIGF1cmFpdCDDqXTDqSBtb2lucyBjaGVyIGF2ZWMgcGx1cyBkZSB0ZW1wcyksIG1haXMgauKAmWFpIGdhZ27DqSBldCBj4oCZZXN0IHRvdXQgY2UgcXVpIGNvbXB0ZS4gSiYjODIxNzthaSBhbG9ycyBwdSByw6ljb2x0ZXIgZGUgbOKAmWFyZ2VudCBldCBvcHRpbWlzZXIgbGVzIGxhY3VuZXMuPC9lbT48L3A%DQo8cD48ZW0%Rm91cm5pc3NleiB1biBwbGFuIHBvdXIgY2Ugd2Vlay1lbmQgcXVpIGNvbXByZW5kIHRvdXRlcyB2b3MgcmVjb21tYW5kYXRpb25zLCBwZW5zZXogeSBwYXJjZSBxdWUgamUgcGV1eCB2b3VzIGRvbm5lciBs4oCZYXJnZW50LCBsZSBzYXZvaXItZmFpcmUsIGxhIHN0cmF0w6lnaWUsIG1haXMgamUgbmUgZmVyYWkgcXXigJl1biBwbGFuIGF1cXVlbCB2b3VzIGNyb2lyZXogw6AgMTAwJSBldCBxdWkgc2VyYSBzaWduw6kgYXZlYyBkdSBzYW5nLiBDZSBu4oCZZXN0IHBhcyBsZSBwbGFuIGQmIzgyMTc7T2xpLCDDp2EgZG9pdCDDqnRyZSB2b3RyZSBwbGFuLCBub3RyZSBwbGFuLjwvZW0%PC9wPg0KPHA%PGVtPk7igJlvdWJsaWV6IGphbWFpcyBxdeKAmWlsIG7igJl5IGEgcXVlIGRldXggZ3JvcyBzZWN0ZXVycyBkYW5zIGxlIGUtY29tbWVyY2UgOiBBbWF6b24gZXQgWmFwcG9zLiBD4oCZZXN0IGxhIGRlcm5pw6hyZSBjaGFuY2UgZGUgdm90cmUgdmllIDogbGEgY2hhbmNlIHBvdXIgdW5lIGF1dHJlIGVudHJlcHJpc2UgZGUgZS1jb21tZXJjZSBkZSB2YWxvaXIgcGx1c2lldXJzIG1pbGxpYXJkIGRlIGRvbGxhcnMsIHVuZSBjaGFuY2UgcXVpIG5lIHNlIHJlcHLDqXNlbnRlcmEgcGx1cyAhIEPigJllc3QgdGVybWluw6ksIGFwcsOocyBBbWF6b24gdmllbnQgc2V1bGVtZW50IFphcHBvcywgZG9uYyBvbiBuZSBwZXV0IHBhcyByYXRlciDDp2EuIFBhcmNlIHF1ZSBzaW5vbiB2b3MgcGV0aXRzLWVuZmFudHMgdm91cyBkZW1hbmRlcm9udCB0b3V0ZSB2b3RyZSB2aWUgcG91cnF1b2kgdm91cyBuZSBsJiM4MjE3O2F2ZXogcGFzIGZhaXQuIDwvZW0%PC9wPg0KPHA%PGVtPlN1cnByZW5lei1tb2kgYXZlYyB2b3RyZSBhZ3Jlc3Npdml0w6ksIHNveWV6IGludGVsbGlnZW50cyBldCBwZW5zZXogIGRlIG1hbmnDqHJlIGFncmVzc2l2ZSDigJMgYXBwcmVuZXogZGVzIGVycmV1cnMgZGVzIHJ1c3NlcyBldCBkZXMgamFwb25haXMsIGV0IGR1IHN1Y2PDqHMgZGVzIGFsbGVtYW5kcyBldCBkZXMgYnLDqXNpbGllbnMgITwvZW0%PC9wPg0KPHA%PGVtPkPigJllc3Qgbm90cmUgZGVybmnDqHJlIGNoYW5jZSBkYW5zIGxlIGUtY29tbWVyY2UgZGUgY29uc3RydWlyZSB1bmUgZW50cmVwcmlzZSBjb21tZSBBbWF6b24uIEFwcsOocyBub3VzLCB2b3VzIHBvdXJyZXogbW9udGVyIHVuZSBlbnRyZXByaXNlIGRlIGpldXggZW4gbGlnbmUsIG1haXMgcGx1cyByaWVuIGVuIGUtY29tbWVyY2UuIEPigJllc3QgbGEgREVSTklFUkUgb2NjYXNpb24gZGFucyB2b3RyZSB2aWUgcG91ciB2b3VzIGxhbmNlciBkYW5zIGxlIGUtY29tbWVyY2UgZXQgamUgdmV1eCBxdWUgdm91cyBtaXNpZXogdG91dCBzdXIgY2V0dGUgb3Bwb3J0dW5pdMOpLiBQYXMgYXZlYyAyMCUgb3UgMzAlLCBtYWlzIGF2ZWMgODAlIGRlIHBhcnRzIGRlIG1hcmNow6ksIGMmIzgyMTc7ZXN0IHBvc3NpYmxlIGRhbnMgbm9zIHBheXMhPC9lbT48L3A%DQo8cD48ZW0%SmUgc3VpcyBsZSBtZWMgbGUgcGx1cyBhZ3Jlc3NpZiBkJiM4MjE3O2ludGVybmV0IHN1ciBsYSBwbGFuw6h0ZS4gSmUgbW91cnJhaSBwb3VyIGdhZ25lciBldCBq4oCZZW4gYXR0ZW5kcyBkZSBtw6ptZSBkZSB2b3RyZSBwYXJ0ICEmIzgyMjE7PC9lbT48L3A%DQo8cD4mIzgyMTE7PC9wPg0KPHA%SWwgZXN0IGNsYWlyIHF1ZSBkYW5zIGxlIGRvbWFpbmUgZGVzIGVudHJlcHJpc2VzIMOgIGZvcnRlIGNyb2lzc2FuY2Ugc3VyIGludGVybmV0LCBsZXMgaW5kaXZpZHVzIHBldXZlbnQgcGFyZm9pcyDDqnRyZSBzdXJleGNpdMOpcyBldCBhbGxlciB0cm9wIGxvaW4uIEljaSwgbGUgbGFuZ2FnZSB1dGlsaXPDqSBtYW5xdWUgY3J1ZWxsZW1lbnQgZGUgdGFjdCwgY%KAmWVzdCB1biBldXBow6ltaXNtZS4gQ29udGFjdMOpIHBhciBUZWNoQ3J1bmNoIEV1cm9wZSDDoCBwcm9wb3MgZGUgbOKAmWUtbWFpbCwgT2xpdmVyIFNhbXdlciBhIGNvbmZpcm3DqSBxdeKAmWlsIMOpdGFpdCBiaWVuIGRlIGx1aSwgZXQgYSByw6lwb25kdSBwYXIgY2V0dGUgZMOpY2xhcmF0aW9uIDo8L3A%DQo8cD7CqyA8ZW0%PGVtPkPigJnDqXRhaXQgdW4gZS1tYWlsIHF1ZSBq4oCZYWkgZW52b3nDqSBhdXggbWVtYnJlIGTigJl1biBwcm9qZXQgZOKAmcOpcXVpcGUgZW4gb2N0b2JyZS4gQXUgbWlsaWV1IGRlIG1vbiBlbnRob3VzaWFzbWUgZXQgZGVzIGlkw6llcyBkZSBkw6lwbG9pZW1lbnQgcmFwaWRlLCBq4oCZYWkgdXRpbGlzw6kgbGUgdGVybWUgdG90YWxlbWVudCBpbmFwcHJvcHJpw6kgZGUgJiM4MjIwO0JsaXR6a3JpZWcmIzgyMjE7LiBKZSBzdWlzIHByb2ZvbmTDqW1lbnQgZMOpc29sw6kgcG91ciBjZWxhLiBKZSBt4oCZZXhjdXNlIGF1cHLDqHMgZGUgY2V1eCBxdWkgb250IHB1IMOqdHJlIG9mZmVuc8OpcyBwYXIgY2UgbW90LCBldCBsZSB0b24gZ8OpbsOpcmFsIGRlIGzigJllbWFpbC4gQ2UgbuKAmcOpdGFpdCBwYXMgZGFucyBtb24gaW50ZW50aW9uIGRlIGJsZXNzZXIgcXVlbHF14oCZdW4uIErigJllbnZvaWUgbGUgbcOqbWUgZS1tYWlsIGTigJlleGN1c2VzIGF1eCBkZXN0aW5hdGFpcmVzIGTigJlvcmlnaW5lIGRlIGNldCBlLW1haWwuIEplIHNhaXMgcXVlIGrigJlhaSBldSB0b3J0IGV0IGplIG5lIG1lIHNlcmFpIGphbWFpcyBtb2ktbcOqbWUgZXhwcmltw6kgZGUgY2V0dGUgZmHDp29uPC9lbT48L2VtPi4gwrs8L3A%DQpdXT48L2NvbnRlbnQ6ZW5jb2RlZD4NCgkJCTx3Znc6Y29tbWVudFJzcz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8yOC9xdWFuZC1sZXMtZnJlcmVzLXNhbXdlci1wYXJ0ZW50LWVuLWd1ZXJyZS9mZWVkLzwvd2Z3OmNvbW1lbnRSc3M%DQoJCTxzbGFzaDpjb21tZW50cz42PC9zbGFzaDpjb21tZW50cz4NCgkJPC9pdGVtPg0KCQk8aXRlbT4NCgkJPHRpdGxlPkF2ZGljZSwgbGEgbm91dmVsbGUgcGxhY2UgZGUgbWFyY2jDqSAyLjAgc3DDqWNpYWxpc8OpZSBkYW5zIGxhIHByZXN0YXRpb24gaW50ZWxsZWN0dWVsbGU8L3RpdGxlPg0KDQoJCTxsaW5rPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8yMDEyLzAzLzMwL2F2ZGljZS1sYS1ub3V2ZWxsZS1wbGFjZS1kZS1tYXJjaGUtMi0wLXNwZWNpYWxpc2VlLWRhbnMtbGEtcHJlc3RhdGlvbi1pbnRlbGxlY3R1ZWxsZS88L2xpbms%DQoJCTxjb21tZW50cz5odHRwOi8vZnIudGVjaGNydW5jaC5jb20vMjAxMi8wMy8zMC9hdmRpY2UtbGEtbm91dmVsbGUtcGxhY2UtZGUtbWFyY2hlLTItMC1zcGVjaWFsaXNlZS1kYW5zLWxhLXByZXN0YXRpb24taW50ZWxsZWN0dWVsbGUvI2NvbW1lbnRzPC9jb21tZW50cz4NCgkJPHB1YkRhdGU%RnJpLCAzMCBNYXIgMjAxMiAxNDoyNzowNSArMDAwMDwvcHViRGF0ZT4NCgkJPGRjOmNyZWF0b3I%Q2VkcmljIE8nTmVpbGw8L2RjOmNyZWF0b3I%DQoJCQkJPGNhdGVnb3J5PjwhW0NEQVRBW05vbiBjbGFzc8OpXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW2F2ZGljZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtMaW5rZWRpbl1dPjwvY2F0ZWdvcnk%DQoNCgkJPGNhdGVnb3J5PjwhW0NEQVRBW21hcmtldHBsYWNlXV0%PC9jYXRlZ29yeT4NCgkJPGNhdGVnb3J5PjwhW0NEQVRBW3ByZXN0YXRpb24gaW50ZWxlY3R1ZWxsZV1dPjwvY2F0ZWdvcnk%DQoJCTxjYXRlZ29yeT48IVtDREFUQVtUd2l0dGVyXV0%PC9jYXRlZ29yeT4NCg0KCQk8Z3VpZCBpc1Blcm1hTGluaz0iZmFsc2UiPmh0dHA6Ly9mci50ZWNoY3J1bmNoLmNvbS8:cD0yMzkzMDwvZ3VpZD4NCgkJPGRlc2NyaXB0aW9uPjwhW0NEQVRBWzxhIGhyZWY9Imh0dHA6Ly93d3cuYXZkaWNlLmNvbS8iPkF2ZGljZTwvYT4gdmllbnQgZGUgbGFuY2VyIHNhIGLDqnRhIHB1YmxpcXVlLiBDZXR0ZSA8c3Ryb25nPnBsYWNlIGRlIG1hcmNow6k8L3N0cm9uZz4gdm91cyBwZXJtZXQgZGUgdHJvdXZlciBkZXMgY29tcMOpdGVuY2VzIHBsdXMgZmFjaWxlbWVudCBncsOiY2Ugw6AgPHN0cm9uZz5s4oCZdXRpbGlzYXRpb24gZGVzIHLDqXNlYXV4IHNvY2lhdXg8L3N0cm9uZz4gOiB1bmUgbm91dmVsbGUgZmHDp29uIGRlIG1ldHRyZSBlbiByZWxhdGlvbiBkb25uZXVycyBk4oCZb3JkcmVzIGV0IHByZXN0YXRhaXJlcy4NCg0KRW4gZCdhdXRyZXMgdGVybWVzLCBpbCBzJ2FnaXQgZCd1bmUgYXBwbGljYXRpb24gd2ViIHF1aSBwZXJtZXQgYXV4IHByZXN0YXRhaXJlcyBkZSBzZXJ2aWNlcyBpbmTDqXBlbmRhbnRzIG91IGFzc29jacOpcyBkJ29yZ2FuaXNlciBsZXVyIHByb3NwZWN0aW9uLCBkZSBsaXNzZXIgbGV1ciBhY3Rpdml0w6kgZXQgZGUgZ2FnbmVyIGVuIHZpc2liaWxpdMOpLiBQb3VyIGxlcyBkb25uZXVycyBkJ29yZHJlcywgbOKAmW9iamVjdGlmIGVzdCBkZSBkw6luaWNoZXIgbGVzIG1laWxsZXVycyBwcmVzdGF0YWlyZXMgZGUgbGV1ciByw6lzZWF1IGdyw6JjZSBub3RhbW1lbnQgw6AgPHN0cm9uZz5Ud2l0dGVyPC9zdHJvbmc%IGV0IDxzdHJvbmc%TGlua2VkaW48L3N0cm9uZz4uXV0%PC9kZXNjcmlwdGlvbj4NCgkJCTxjb250ZW50OmVuY29kZWQ%PCFbQ0RBVEFbPHA%PGEgaHJlZj0iaHR0cDovL3d3dy5hdmRpY2UuY29tLyI%QXZkaWNlPC9hPiB2aWVudCBkZSBsYW5jZXIgc2EgYsOqdGEgcHVibGlxdWUuIENldHRlIDxzdHJvbmc%cGxhY2UgZGUgbWFyY2jDqTwvc3Ryb25nPiB2b3VzIHBlcm1ldCBkZSB0cm91dmVyIGRlcyBjb21ww6l0ZW5jZXMgcGx1cyBmYWNpbGVtZW50IGdyw6JjZSDDoCA8c3Ryb25nPmzigJl1dGlsaXNhdGlvbiBkZXMgcsOpc2VhdXggc29jaWF1eDwvc3Ryb25nPiA6IHVuZSBub3V2ZWxsZSBmYcOnb24gZGUgbWV0dHJlIGVuIHJlbGF0aW9uIGRvbm5ldXJzIGTigJlvcmRyZXMgZXQgcHJlc3RhdGFpcmVzLjwvcD4NCjxwPkVuIGQmIzgyMTc7YXV0cmVzIHRlcm1lcywgaWwgcyYjODIxNzthZ2l0IGQmIzgyMTc7dW5lIGFwcGxpY2F0aW9uIHdlYiBxdWkgcGVybWV0IGF1eCBwcmVzdGF0YWlyZXMgZGUgc2VydmljZXMgaW5kw6lwZW5kYW50cyBvdSBhc3NvY2nDqXMgZCYjODIxNztvcmdhbmlzZXIgbGV1ciBwcm9zcGVjdGlvbiwgZGUgbGlzc2VyIGxldXIgYWN0aXZpdMOpIGV0IGRlIGdhZ25lciBlbiB2aXNpYmlsaXTDqS4gUG91ciBsZXMgZG9ubmV1cnMgZCYjODIxNztvcmRyZXMsIGzigJlvYmplY3RpZiBlc3QgZGUgZMOpbmljaGVyIGxlcyBtZWlsbGV1cnMgcHJlc3RhdGFpcmVzIGRlIGxldXIgcsOpc2VhdSBncsOiY2Ugbm90YW1tZW50IMOgIDxzdHJvbmc%VHdpdHRlcjwvc3Ryb25nPiBldCA8c3Ryb25nPkxpbmtlZGluPC9zdHJvbmc%LjwvcD4NCjxwIHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXIiPjwvcD4NCjxwPkVuIHN1cHByaW1hbnQgbGVzIGludGVybcOpZGlhaXJlcywgPHN0cm9uZz5BdmRpY2U8L3N0cm9uZz4gcGVybWV0IGF1eCBkb25uZXVycyBk4oCZb3JkcmVzIGRlIHRyb3V2ZXIgZGVzIGluZMOpcGVuZGFudHMgw6AgbGV1ciBqdXN0ZSB2YWxldXIuIFBvdXIgY2VsYSwgQXZkaWNlIHByb3Bvc2UgYXV4IGRvbm5ldXJzIGTigJlvcmRyZXMgZGUgZGlmZnVzZXIgbGV1cnMgb2ZmcmVzIGF1cHLDqHMgZGUgbGV1ciByw6lzZWF1IGFpbnNpIHF14oCZYXV4IHByZXN0YXRhaXJlcyBob3JzIHLDqXNlYXUgcXVpIGNvcnJlc3BvbmRlbnQgYXV4IGNhcmFjdMOpcmlzdGlxdWVzIGRlIGxhIG1pc3Npb24uIENlcyBwcmVzdGF0YWlyZXMgc29udCBhdmVydGlzIGV0IHBldXZlbnQgZGlyZWN0ZW1lbnQgZXQgZ3JhdHVpdGVtZW50IGNvbnRhY3RlciBsZSBkb25uZXVyIGTigJlvcmRyZXMuPC9wPg0KPHA%TOKAmXV0aWxpc2F0aW9uIGRlIGxhIHBsYXRlZm9ybWUgZXN0IDxzdHJvbmc%ZW50acOocmVtZW50IGdyYXR1aXRlPC9zdHJvbmc%IHBvdXIgbGUgbW9tZW50LiBBdmRpY2Ugc2UgcGxhY2UgZW4gY29uY3VycmVuY2UgZGlyZWN0IGZhY2Ugw6AgZGUgbm9tYnJldXggYXV0cmVzIGFjdGV1cnMgZHUgbWFyY2jDqSBkZSBsYSBwcmVzdGF0aW9uIGludGVsbGVjdHVlbGxlIG9ubGluZSwgbWFpcyDDoCBsYSBkaWZmw6lyZW5jZSBkZSBjZXMgYWN0ZXVycywgQXZkaWNlIG7igJllc3QgcGFzIHNww6ljaWFsaXPDqSBldCBwcm9wb3NlIGRlcyBwcmVzdGF0aW9ucyBhbGxhbnQgZGUgPHN0cm9uZz5s4oCZYW5hbHlzZSBmaW5hbmNpw6hyZSDDoCBsYSBjcsOpYXRpb24gZGUgdm90cmUgbm91dmVsbGUgY2hhcnRlIGdyYXBoaXF1ZTwvc3Ryb25nPi4gTGEgZGlmZmljdWx0w6ksIMOgIG1vbiBzZW5zLCBzZXJhIHN1cmVtZW50IGRhbnMgbGEgY29udmVyc2lvbiBpbiBmaW5lIGRlcyB1dGlsaXNhdGV1cnMuIE1haXMgPGEgaHJlZj0iaHR0cHM6Ly90d2l0dGVyLmNvbS8jJTIxL1lpb2t0dSI%SsOpcsOpbXkgQmxvY2ssPC9hPiBzb24gQ0VPIGFubm9uY2UgbGFuY2VyIHRyw6hzIHByb2NoYWluZW1lbnQgZOKAmWF1dHJlcyBmb25jdGlvbm5hbGl0w6lzIHZlbmFudCBjb21wbMOpdGVyIGV0IMOpbGFyZ2lyIGxlIHNlcnZpY2UuPC9wPg0KXV0%PC9jb250ZW50OmVuY29kZWQ%DQoJCQk8d2Z3OmNvbW1lbnRSc3M%aHR0cDovL2ZyLnRlY2hjcnVuY2guY29tLzIwMTIvMDMvMzAvYXZkaWNlLWxhLW5vdXZlbGxlLXBsYWNlLWRlLW1hcmNoZS0yLTAtc3BlY2lhbGlzZWUtZGFucy1sYS1wcmVzdGF0aW9uLWludGVsbGVjdHVlbGxlL2ZlZWQvPC93Znc6Y29tbWVudFJzcz4NCg0KCQk8c2xhc2g6Y29tbWVudHM%MDwvc2xhc2g6Y29tbWVudHM%DQoJCTwvaXRlbT4JPC9jaGFubmVsPg0KPC9yc3M%DQo"}];
if(typeof document != "undefined") js.Lib.document = document;
if(typeof window != "undefined") {
	js.Lib.window = window;
	js.Lib.window.onerror = function(msg,url,line) {
		var f = js.Lib.onerror;
		if(f == null) return false;
		return f(msg,[url + ":" + line]);
	};
}
js.XMLHttpRequest = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
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
feffects.Tween._aTweens = new haxe.FastList();
feffects.Tween._aPaused = new haxe.FastList();
feffects.Tween.INTERVAL = 10;
haxe.Unserializer.DEFAULT_RESOLVER = Type;
haxe.Unserializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
org.intermedia.Application.main();
