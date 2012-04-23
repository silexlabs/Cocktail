$estr = function() { return js.Boot.__string_rec(this,''); }
if(typeof haxe=='undefined') haxe = {}
haxe.Public = function() { }
haxe.Public.__name__ = ["haxe","Public"];
haxe.Public.prototype.__class__ = haxe.Public;
if(typeof feffects=='undefined') feffects = {}
if(!feffects.easing) feffects.easing = {}
feffects.easing.Quint = function() { }
feffects.easing.Quint.__name__ = ["feffects","easing","Quint"];
feffects.easing.Quint.easeIn = function(t,b,c,d) {
	$s.push("feffects.easing.Quint::easeIn");
	var $spos = $s.length;
	var $tmp = c * (t /= d) * t * t * t * t + b;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.easing.Quint.easeOut = function(t,b,c,d) {
	$s.push("feffects.easing.Quint::easeOut");
	var $spos = $s.length;
	var $tmp = c * ((t = t / d - 1) * t * t * t * t + 1) + b;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.easing.Quint.easeInOut = function(t,b,c,d) {
	$s.push("feffects.easing.Quint::easeInOut");
	var $spos = $s.length;
	if((t /= d * 0.5) < 1) {
		var $tmp = c * 0.5 * t * t * t * t * t + b;
		$s.pop();
		return $tmp;
	} else {
		var $tmp = c * 0.5 * ((t -= 2) * t * t * t * t + 2) + b;
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
feffects.easing.Quint.prototype.__class__ = feffects.easing.Quint;
feffects.easing.Quint.__interfaces__ = [haxe.Public];
haxe.Http = function(url) {
	if( url === $_ ) return;
	$s.push("haxe.Http::new");
	var $spos = $s.length;
	this.url = url;
	this.headers = new Hash();
	this.params = new Hash();
	this.async = true;
	$s.pop();
}
haxe.Http.__name__ = ["haxe","Http"];
haxe.Http.requestUrl = function(url) {
	$s.push("haxe.Http::requestUrl");
	var $spos = $s.length;
	var h = new haxe.Http(url);
	h.async = false;
	var r = null;
	h.onData = function(d) {
		$s.push("haxe.Http::requestUrl@636");
		var $spos = $s.length;
		r = d;
		$s.pop();
	};
	h.onError = function(e) {
		$s.push("haxe.Http::requestUrl@639");
		var $spos = $s.length;
		throw e;
		$s.pop();
	};
	h.request(false);
	$s.pop();
	return r;
	$s.pop();
}
haxe.Http.prototype.url = null;
haxe.Http.prototype.async = null;
haxe.Http.prototype.postData = null;
haxe.Http.prototype.headers = null;
haxe.Http.prototype.params = null;
haxe.Http.prototype.setHeader = function(header,value) {
	$s.push("haxe.Http::setHeader");
	var $spos = $s.length;
	this.headers.set(header,value);
	$s.pop();
}
haxe.Http.prototype.setParameter = function(param,value) {
	$s.push("haxe.Http::setParameter");
	var $spos = $s.length;
	this.params.set(param,value);
	$s.pop();
}
haxe.Http.prototype.setPostData = function(data) {
	$s.push("haxe.Http::setPostData");
	var $spos = $s.length;
	this.postData = data;
	$s.pop();
}
haxe.Http.prototype.request = function(post) {
	$s.push("haxe.Http::request");
	var $spos = $s.length;
	var me = this;
	var r = new js.XMLHttpRequest();
	var onreadystatechange = function() {
		$s.push("haxe.Http::request@108");
		var $spos = $s.length;
		if(r.readyState != 4) {
			$s.pop();
			return;
		}
		var s = (function($this) {
			var $r;
			try {
				$r = r.status;
			} catch( e ) {
				$r = (function($this) {
					var $r;
					$e = [];
					while($s.length >= $spos) $e.unshift($s.pop());
					$s.push($e[0]);
					$r = null;
					return $r;
				}($this));
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
		$s.pop();
	};
	if(this.async) r.onreadystatechange = onreadystatechange;
	var uri = this.postData;
	if(uri != null) post = true; else {
		var $it0 = this.params.keys();
		while( $it0.hasNext() ) {
			var p = $it0.next();
			if(uri == null) uri = ""; else uri += "&";
			uri += StringTools.urlDecode(p) + "=" + StringTools.urlEncode(this.params.get(p));
		}
	}
	try {
		if(post) r.open("POST",this.url,this.async); else if(uri != null) {
			var question = this.url.split("?").length <= 1;
			r.open("GET",this.url + (question?"?":"&") + uri,this.async);
			uri = null;
		} else r.open("GET",this.url,this.async);
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		this.onError(e.toString());
		$s.pop();
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
	$s.pop();
}
haxe.Http.prototype.onData = function(data) {
	$s.push("haxe.Http::onData");
	var $spos = $s.length;
	$s.pop();
}
haxe.Http.prototype.onError = function(msg) {
	$s.push("haxe.Http::onError");
	var $spos = $s.length;
	$s.pop();
}
haxe.Http.prototype.onStatus = function(status) {
	$s.push("haxe.Http::onStatus");
	var $spos = $s.length;
	$s.pop();
}
haxe.Http.prototype.__class__ = haxe.Http;
List = function(p) {
	if( p === $_ ) return;
	$s.push("List::new");
	var $spos = $s.length;
	this.length = 0;
	$s.pop();
}
List.__name__ = ["List"];
List.prototype.h = null;
List.prototype.q = null;
List.prototype.length = null;
List.prototype.add = function(item) {
	$s.push("List::add");
	var $spos = $s.length;
	var x = [item];
	if(this.h == null) this.h = x; else this.q[1] = x;
	this.q = x;
	this.length++;
	$s.pop();
}
List.prototype.push = function(item) {
	$s.push("List::push");
	var $spos = $s.length;
	var x = [item,this.h];
	this.h = x;
	if(this.q == null) this.q = x;
	this.length++;
	$s.pop();
}
List.prototype.first = function() {
	$s.push("List::first");
	var $spos = $s.length;
	var $tmp = this.h == null?null:this.h[0];
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.last = function() {
	$s.push("List::last");
	var $spos = $s.length;
	var $tmp = this.q == null?null:this.q[0];
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.pop = function() {
	$s.push("List::pop");
	var $spos = $s.length;
	if(this.h == null) {
		$s.pop();
		return null;
	}
	var x = this.h[0];
	this.h = this.h[1];
	if(this.h == null) this.q = null;
	this.length--;
	$s.pop();
	return x;
	$s.pop();
}
List.prototype.isEmpty = function() {
	$s.push("List::isEmpty");
	var $spos = $s.length;
	var $tmp = this.h == null;
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.clear = function() {
	$s.push("List::clear");
	var $spos = $s.length;
	this.h = null;
	this.q = null;
	this.length = 0;
	$s.pop();
}
List.prototype.remove = function(v) {
	$s.push("List::remove");
	var $spos = $s.length;
	var prev = null;
	var l = this.h;
	while(l != null) {
		if(l[0] == v) {
			if(prev == null) this.h = l[1]; else prev[1] = l[1];
			if(this.q == l) this.q = prev;
			this.length--;
			$s.pop();
			return true;
		}
		prev = l;
		l = l[1];
	}
	$s.pop();
	return false;
	$s.pop();
}
List.prototype.iterator = function() {
	$s.push("List::iterator");
	var $spos = $s.length;
	var $tmp = { h : this.h, hasNext : function() {
		$s.push("List::iterator@155");
		var $spos = $s.length;
		var $tmp = this.h != null;
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("List::iterator@158");
		var $spos = $s.length;
		if(this.h == null) {
			$s.pop();
			return null;
		}
		var x = this.h[0];
		this.h = this.h[1];
		$s.pop();
		return x;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.toString = function() {
	$s.push("List::toString");
	var $spos = $s.length;
	var s = new StringBuf();
	var first = true;
	var l = this.h;
	s.b[s.b.length] = "{" == null?"null":"{";
	while(l != null) {
		if(first) first = false; else s.b[s.b.length] = ", " == null?"null":", ";
		s.add(Std.string(l[0]));
		l = l[1];
	}
	s.b[s.b.length] = "}" == null?"null":"}";
	var $tmp = s.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.join = function(sep) {
	$s.push("List::join");
	var $spos = $s.length;
	var s = new StringBuf();
	var first = true;
	var l = this.h;
	while(l != null) {
		if(first) first = false; else s.b[s.b.length] = sep == null?"null":sep;
		s.add(l[0]);
		l = l[1];
	}
	var $tmp = s.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
List.prototype.filter = function(f) {
	$s.push("List::filter");
	var $spos = $s.length;
	var l2 = new List();
	var l = this.h;
	while(l != null) {
		var v = l[0];
		l = l[1];
		if(f(v)) l2.add(v);
	}
	$s.pop();
	return l2;
	$s.pop();
}
List.prototype.map = function(f) {
	$s.push("List::map");
	var $spos = $s.length;
	var b = new List();
	var l = this.h;
	while(l != null) {
		var v = l[0];
		l = l[1];
		b.add(f(v));
	}
	$s.pop();
	return b;
	$s.pop();
}
List.prototype.__class__ = List;
if(typeof org=='undefined') org = {}
if(!org.intermedia) org.intermedia = {}
if(!org.intermedia.view) org.intermedia.view = {}
org.intermedia.view.ViewBase = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.ViewBase::new");
	var $spos = $s.length;
	this.node = js.Lib.document.createElement("div");
	this.setDisplayLoading(false);
	this.buildView();
	$s.pop();
}
org.intermedia.view.ViewBase.__name__ = ["org","intermedia","view","ViewBase"];
org.intermedia.view.ViewBase.prototype.node = null;
org.intermedia.view.ViewBase.prototype._data = null;
org.intermedia.view.ViewBase.prototype.data = null;
org.intermedia.view.ViewBase.prototype.displayLoading = null;
org.intermedia.view.ViewBase.prototype._loadingView = null;
org.intermedia.view.ViewBase.prototype.getData = function() {
	$s.push("org.intermedia.view.ViewBase::getData");
	var $spos = $s.length;
	var $tmp = this._data;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.ViewBase.prototype.setData = function(v) {
	$s.push("org.intermedia.view.ViewBase::setData");
	var $spos = $s.length;
	this._data = v;
	this.updateView();
	var $tmp = this._data;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.ViewBase.prototype.setDisplayLoading = function(v) {
	$s.push("org.intermedia.view.ViewBase::setDisplayLoading");
	var $spos = $s.length;
	if(v) {
		if(this._loadingView == null) this._loadingView = new org.intermedia.view.LoadingView();
		if(this._loadingView.node.parentNode == null) this.node.appendChild(this._loadingView.node);
	} else if(this._loadingView != null) {
		if(this._loadingView.node.parentNode != null) this.node.removeChild(this._loadingView.node);
	}
	$s.pop();
	return v;
	$s.pop();
}
org.intermedia.view.ViewBase.prototype.buildView = function() {
	$s.push("org.intermedia.view.ViewBase::buildView");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.ViewBase.prototype.updateView = function() {
	$s.push("org.intermedia.view.ViewBase::updateView");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.ViewBase.prototype.__class__ = org.intermedia.view.ViewBase;
org.intermedia.view.CellBase = function(cellPerLine,cellStyle) {
	if( cellPerLine === $_ ) return;
	$s.push("org.intermedia.view.CellBase::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ViewBase.call(this);
	if(cellStyle != null) this._cellStyle = cellStyle; else this.initCellStyle();
	this._cellStyle.cell(this.node,cellPerLine);
	$s.pop();
}
org.intermedia.view.CellBase.__name__ = ["org","intermedia","view","CellBase"];
org.intermedia.view.CellBase.__super__ = org.intermedia.view.ViewBase;
for(var k in org.intermedia.view.ViewBase.prototype ) org.intermedia.view.CellBase.prototype[k] = org.intermedia.view.ViewBase.prototype[k];
org.intermedia.view.CellBase.prototype._cellStyle = null;
org.intermedia.view.CellBase.prototype.initCellStyle = function() {
	$s.push("org.intermedia.view.CellBase::initCellStyle");
	var $spos = $s.length;
	this._cellStyle = { cell : org.intermedia.view.CellStyle.setCellStyle, thumbnail : null, textBlock : null, title : null, author : null, line : null};
	$s.pop();
}
org.intermedia.view.CellBase.prototype.__class__ = org.intermedia.view.CellBase;
org.intermedia.view.MenuCellText = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.MenuCellText::new");
	var $spos = $s.length;
	org.intermedia.view.CellBase.call(this);
	org.intermedia.view.MenuCellTextStyle.setCellStyle(this.node);
	$s.pop();
}
org.intermedia.view.MenuCellText.__name__ = ["org","intermedia","view","MenuCellText"];
org.intermedia.view.MenuCellText.__super__ = org.intermedia.view.CellBase;
for(var k in org.intermedia.view.CellBase.prototype ) org.intermedia.view.MenuCellText.prototype[k] = org.intermedia.view.CellBase.prototype[k];
org.intermedia.view.MenuCellText.prototype.updateView = function() {
	$s.push("org.intermedia.view.MenuCellText::updateView");
	var $spos = $s.length;
	var cellData = this._data;
	var cellTextContainer = js.Lib.document.createElement("div");
	if(cellData.title != "" && cellData.title != null) {
		var textElement = js.Lib.document.createTextNode(cellData.title);
		cellTextContainer.appendChild(textElement);
		this.node.appendChild(cellTextContainer);
		org.intermedia.view.MenuCellTextStyle.setCellTextStyle(cellTextContainer);
	}
	$s.pop();
}
org.intermedia.view.MenuCellText.prototype.__class__ = org.intermedia.view.MenuCellText;
org.intermedia.view.CellStyle = function() { }
org.intermedia.view.CellStyle.__name__ = ["org","intermedia","view","CellStyle"];
org.intermedia.view.CellStyle.setCellStyle = function(node,cellPerLine) {
	$s.push("org.intermedia.view.CellStyle::setCellStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.CellStyle.computeWidthPercentage = function(cellPerLine) {
	$s.push("org.intermedia.view.CellStyle::computeWidthPercentage");
	var $spos = $s.length;
	var cellWidthPercent = 100;
	if(cellPerLine != 0) {
		cellWidthPercent = 100 / cellPerLine;
		cellWidthPercent -= 1;
	}
	$s.pop();
	return cellWidthPercent;
	$s.pop();
}
org.intermedia.view.CellStyle.computeWidthPixels = function(cellPerLine) {
	$s.push("org.intermedia.view.CellStyle::computeWidthPixels");
	var $spos = $s.length;
	var cellWidthPixels = js.Lib.window.innerWidth;
	if(cellPerLine != 0) cellWidthPixels = Std["int"](cellWidthPixels / cellPerLine);
	$s.pop();
	return cellWidthPixels;
	$s.pop();
}
org.intermedia.view.CellStyle.addBorder = function(node) {
	$s.push("org.intermedia.view.CellStyle::addBorder");
	var $spos = $s.length;
	node.style.margin = Std.string(1) + "px";
	$s.pop();
}
org.intermedia.view.CellStyle.removeBorder = function(node) {
	$s.push("org.intermedia.view.CellStyle::removeBorder");
	var $spos = $s.length;
	node.style.margin = "0px";
	$s.pop();
}
org.intermedia.view.CellStyle.prototype.__class__ = org.intermedia.view.CellStyle;
org.intermedia.view.ScreenResolutionSize = { __ename__ : ["org","intermedia","view","ScreenResolutionSize"], __constructs__ : ["small","normal","large"] }
org.intermedia.view.ScreenResolutionSize.small = ["small",0];
org.intermedia.view.ScreenResolutionSize.small.toString = $estr;
org.intermedia.view.ScreenResolutionSize.small.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolutionSize.normal = ["normal",1];
org.intermedia.view.ScreenResolutionSize.normal.toString = $estr;
org.intermedia.view.ScreenResolutionSize.normal.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolutionSize.large = ["large",2];
org.intermedia.view.ScreenResolutionSize.large.toString = $estr;
org.intermedia.view.ScreenResolutionSize.large.__enum__ = org.intermedia.view.ScreenResolutionSize;
org.intermedia.view.ScreenResolution = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.ScreenResolution::new");
	var $spos = $s.length;
	if(js.Lib.window.innerWidth < 400) this.size = org.intermedia.view.ScreenResolutionSize.small; else if(js.Lib.window.innerWidth < 600) this.size = org.intermedia.view.ScreenResolutionSize.normal; else this.size = org.intermedia.view.ScreenResolutionSize.large;
	$s.pop();
}
org.intermedia.view.ScreenResolution.__name__ = ["org","intermedia","view","ScreenResolution"];
org.intermedia.view.ScreenResolution.prototype.size = null;
org.intermedia.view.ScreenResolution.prototype.__class__ = org.intermedia.view.ScreenResolution;
org.intermedia.view.LoadingViewStyle = function() { }
org.intermedia.view.LoadingViewStyle.__name__ = ["org","intermedia","view","LoadingViewStyle"];
org.intermedia.view.LoadingViewStyle.setLoadingStyle = function(node) {
	$s.push("org.intermedia.view.LoadingViewStyle::setLoadingStyle");
	var $spos = $s.length;
	node.style.display = "block";
	node.style.position = "absolute";
	node.style.width = Std.string(js.Lib.window.innerWidth) + "px";
	node.style.height = Std.string(js.Lib.window.innerHeight) + "px";
	node.style.textAlign = "center";
	node.style.top = "0px";
	node.style.bottom = "0px";
	node.style.color = "#FFFFFF";
	$s.pop();
}
org.intermedia.view.LoadingViewStyle.setThumbnailStyle = function(node) {
	$s.push("org.intermedia.view.LoadingViewStyle::setThumbnailStyle");
	var $spos = $s.length;
	node.style.position = "relative";
	node.style.marginTop = "auto";
	node.style.marginBottom = "auto";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.top = "45%";
	$s.pop();
}
org.intermedia.view.LoadingViewStyle.prototype.__class__ = org.intermedia.view.LoadingViewStyle;
org.intermedia.view.DetailView = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.DetailView::new");
	var $spos = $s.length;
	this._titleElement = js.Lib.document.createTextNode("");
	this._authorElement = js.Lib.document.createTextNode("");
	this._descriptionElement = js.Lib.document.createTextNode("");
	this._contentElement = js.Lib.document.createTextNode("");
	org.intermedia.view.ViewBase.call(this);
	this._moveHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.vertical);
	this._moveHandler.onVerticalScroll = $closure(this,"onVerticalMove");
	$s.pop();
}
org.intermedia.view.DetailView.__name__ = ["org","intermedia","view","DetailView"];
org.intermedia.view.DetailView.__super__ = org.intermedia.view.ViewBase;
for(var k in org.intermedia.view.ViewBase.prototype ) org.intermedia.view.DetailView.prototype[k] = org.intermedia.view.ViewBase.prototype[k];
org.intermedia.view.DetailView.prototype._titleContainer = null;
org.intermedia.view.DetailView.prototype._titleElement = null;
org.intermedia.view.DetailView.prototype._authorContainer = null;
org.intermedia.view.DetailView.prototype._authorElement = null;
org.intermedia.view.DetailView.prototype._thumbnail = null;
org.intermedia.view.DetailView.prototype._descriptionContainer = null;
org.intermedia.view.DetailView.prototype._descriptionElement = null;
org.intermedia.view.DetailView.prototype._contentContainer = null;
org.intermedia.view.DetailView.prototype._contentElement = null;
org.intermedia.view.DetailView.prototype._moveHandler = null;
org.intermedia.view.DetailView.prototype.buildView = function() {
	$s.push("org.intermedia.view.DetailView::buildView");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.DetailView.prototype.updateView = function() {
	$s.push("org.intermedia.view.DetailView::updateView");
	var $spos = $s.length;
	this._titleContainer.removeChild(this._titleElement);
	this._titleElement = js.Lib.document.createTextNode(this._data.title);
	this._titleContainer.appendChild(this._titleElement);
	this._authorContainer.removeChild(this._authorElement);
	this._authorElement = js.Lib.document.createTextNode(this._data.author);
	this._authorContainer.appendChild(this._authorElement);
	this.node.innerHTML += this._data.content;
	$s.pop();
}
org.intermedia.view.DetailView.prototype.touchStart = function(event) {
	$s.push("org.intermedia.view.DetailView::touchStart");
	var $spos = $s.length;
	this._moveHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this.node.scrollTop};
	this._moveHandler.touchHandler(event);
	$s.pop();
}
org.intermedia.view.DetailView.prototype.addTouchEvents = function() {
	$s.push("org.intermedia.view.DetailView::addTouchEvents");
	var $spos = $s.length;
	this.node.addEventListener("touchstart",$closure(this,"touchStart"),false);
	this.node.addEventListener("touchmove",$closure(this._moveHandler,"touchHandler"),false);
	this.node.addEventListener("touchend",$closure(this._moveHandler,"touchHandler"),false);
	this.node.addEventListener("touchcancel",$closure(this._moveHandler,"touchHandler"),false);
	$s.pop();
}
org.intermedia.view.DetailView.prototype.onVerticalMove = function(y) {
	$s.push("org.intermedia.view.DetailView::onVerticalMove");
	var $spos = $s.length;
	this.node.scrollTop = y;
	$s.pop();
}
org.intermedia.view.DetailView.prototype.__class__ = org.intermedia.view.DetailView;
if(!org.intermedia.controller) org.intermedia.controller = {}
org.intermedia.controller.ApplicationController = function(applicationModel) {
	if( applicationModel === $_ ) return;
	$s.push("org.intermedia.controller.ApplicationController::new");
	var $spos = $s.length;
	this._applicationModel = applicationModel;
	$s.pop();
}
org.intermedia.controller.ApplicationController.__name__ = ["org","intermedia","controller","ApplicationController"];
org.intermedia.controller.ApplicationController.prototype._applicationModel = null;
org.intermedia.controller.ApplicationController.prototype.loadCellData = function(feed) {
	$s.push("org.intermedia.controller.ApplicationController::loadCellData");
	var $spos = $s.length;
	this._applicationModel.loadCellData(feed);
	$s.pop();
}
org.intermedia.controller.ApplicationController.prototype.openDetailView = function(cellData) {
	$s.push("org.intermedia.controller.ApplicationController::openDetailView");
	var $spos = $s.length;
	this._applicationModel.loadDetailData(cellData);
	$s.pop();
}
org.intermedia.controller.ApplicationController.prototype.__class__ = org.intermedia.controller.ApplicationController;
org.intermedia.view.HeaderStyle = function() { }
org.intermedia.view.HeaderStyle.__name__ = ["org","intermedia","view","HeaderStyle"];
org.intermedia.view.HeaderStyle.setHeaderStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderStyle");
	var $spos = $s.length;
	node.style.position = "fixed";
	node.style.display = "block";
	node.style.top = "0px";
	node.style.bottom = "auto";
	node.style.left = "0px";
	node.style.top = "0px";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = Std.string(43) + "px";
	$s.pop();
}
org.intermedia.view.HeaderStyle.setHeaderStaticStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderStaticStyle");
	var $spos = $s.length;
	node.style.position = "static";
	node.style.display = "block";
	node.style.minWidth = "100%";
	node.style.width = "100%";
	node.style.height = Std.string(43) + "px";
	$s.pop();
}
org.intermedia.view.HeaderStyle.setHeaderTextStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderTextStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonStyle");
	var $spos = $s.length;
	node.style.position = "absolute";
	node.style.paddingTop = "6px";
	node.style.paddingLeft = "10px";
	node.style.top = "0px";
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonTextStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonTextStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonImageStyle = function(node) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonImageStyle");
	var $spos = $s.length;
	node.style.display = "inline";
	node.style.position = "relative";
	node.style.top = "0px";
	node.style.left = "0px";
	$s.pop();
}
org.intermedia.view.HeaderStyle.prototype.__class__ = org.intermedia.view.HeaderStyle;
haxe.FastList = function(p) {
	$s.push("haxe.FastList::new");
	var $spos = $s.length;
	$s.pop();
}
haxe.FastList.__name__ = ["haxe","FastList"];
haxe.FastList.prototype.head = null;
haxe.FastList.prototype.add = function(item) {
	$s.push("haxe.FastList::add");
	var $spos = $s.length;
	this.head = new haxe.FastCell(item,this.head);
	$s.pop();
}
haxe.FastList.prototype.first = function() {
	$s.push("haxe.FastList::first");
	var $spos = $s.length;
	var $tmp = this.head == null?null:this.head.elt;
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.FastList.prototype.pop = function() {
	$s.push("haxe.FastList::pop");
	var $spos = $s.length;
	var k = this.head;
	if(k == null) {
		$s.pop();
		return null;
	} else {
		this.head = k.next;
		var $tmp = k.elt;
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
haxe.FastList.prototype.isEmpty = function() {
	$s.push("haxe.FastList::isEmpty");
	var $spos = $s.length;
	var $tmp = this.head == null;
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.FastList.prototype.remove = function(v) {
	$s.push("haxe.FastList::remove");
	var $spos = $s.length;
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
	var $tmp = l != null;
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.FastList.prototype.iterator = function() {
	$s.push("haxe.FastList::iterator");
	var $spos = $s.length;
	var l = this.head;
	var $tmp = { hasNext : function() {
		$s.push("haxe.FastList::iterator@126");
		var $spos = $s.length;
		var $tmp = l != null;
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("haxe.FastList::iterator@129");
		var $spos = $s.length;
		var k = l;
		l = k.next;
		var $tmp = k.elt;
		$s.pop();
		return $tmp;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.FastList.prototype.toString = function() {
	$s.push("haxe.FastList::toString");
	var $spos = $s.length;
	var a = new Array();
	var l = this.head;
	while(l != null) {
		a.push(l.elt);
		l = l.next;
	}
	var $tmp = "{" + a.join(",") + "}";
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.FastList.prototype.__class__ = haxe.FastList;
feffects.Tween = function(init,end,dur,_obj,_prop,easing) {
	if( init === $_ ) return;
	$s.push("feffects.Tween::new");
	var $spos = $s.length;
	this._initVal = init;
	this._endVal = end;
	this.duration = dur;
	this._offsetTime = 0;
	this._obj = _obj;
	this._prop = _prop;
	if(easing != null) this._easingF = easing; else if(Reflect.isFunction(_obj)) this._easingF = _obj; else this._easingF = $closure(this,"easingEquation");
	this.isPlaying = false;
	$s.pop();
}
feffects.Tween.__name__ = ["feffects","Tween"];
feffects.Tween._timer = null;
feffects.Tween.AddTween = function(tween) {
	$s.push("feffects.Tween::AddTween");
	var $spos = $s.length;
	feffects.Tween._aTweens.add(tween);
	feffects.Tween._timer.run = feffects.Tween.DispatchTweens;
	$s.pop();
}
feffects.Tween.RemoveTween = function(tween) {
	$s.push("feffects.Tween::RemoveTween");
	var $spos = $s.length;
	if(tween == null || feffects.Tween._timer == null) {
		$s.pop();
		return;
	}
	feffects.Tween._aTweens.remove(tween);
	if(feffects.Tween._aTweens.head == null && feffects.Tween._aPaused.head == null) {
		feffects.Tween._timer.stop();
		feffects.Tween._timer = null;
	}
	$s.pop();
}
feffects.Tween.getActiveTweens = function() {
	$s.push("feffects.Tween::getActiveTweens");
	var $spos = $s.length;
	var $tmp = feffects.Tween._aTweens;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.Tween.getPausedTweens = function() {
	$s.push("feffects.Tween::getPausedTweens");
	var $spos = $s.length;
	var $tmp = feffects.Tween._aPaused;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.Tween.setTweenPaused = function(tween) {
	$s.push("feffects.Tween::setTweenPaused");
	var $spos = $s.length;
	if(tween == null || feffects.Tween._timer == null) {
		$s.pop();
		return;
	}
	feffects.Tween._aPaused.add(tween);
	feffects.Tween._aTweens.remove(tween);
	$s.pop();
}
feffects.Tween.setTweenActive = function(tween) {
	$s.push("feffects.Tween::setTweenActive");
	var $spos = $s.length;
	if(tween == null || feffects.Tween._timer == null) {
		$s.pop();
		return;
	}
	feffects.Tween._aTweens.add(tween);
	feffects.Tween._aPaused.remove(tween);
	$s.pop();
}
feffects.Tween.DispatchTweens = function() {
	$s.push("feffects.Tween::DispatchTweens");
	var $spos = $s.length;
	var $it0 = feffects.Tween._aTweens.iterator();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		i.doInterval();
	}
	$s.pop();
}
feffects.Tween.prototype.duration = null;
feffects.Tween.prototype.position = null;
feffects.Tween.prototype.reversed = null;
feffects.Tween.prototype.isPlaying = null;
feffects.Tween.prototype._initVal = null;
feffects.Tween.prototype._endVal = null;
feffects.Tween.prototype._startTime = null;
feffects.Tween.prototype._pauseTime = null;
feffects.Tween.prototype._offsetTime = null;
feffects.Tween.prototype._reverseTime = null;
feffects.Tween.prototype._easingF = null;
feffects.Tween.prototype._obj = null;
feffects.Tween.prototype._prop = null;
feffects.Tween.prototype.start = function() {
	$s.push("feffects.Tween::start");
	var $spos = $s.length;
	if(feffects.Tween._timer != null) feffects.Tween._timer.stop();
	feffects.Tween._timer = new haxe.Timer(10);
	this._startTime = Date.now().getTime();
	if(this.duration == 0) this.endTween(); else feffects.Tween.AddTween(this);
	this.isPlaying = true;
	this.position = 0;
	this._reverseTime = this._startTime;
	this.reversed = false;
	$s.pop();
}
feffects.Tween.prototype.pause = function() {
	$s.push("feffects.Tween::pause");
	var $spos = $s.length;
	this._pauseTime = Date.now().getTime();
	feffects.Tween.setTweenPaused(this);
	this.isPlaying = false;
	$s.pop();
}
feffects.Tween.prototype.resume = function() {
	$s.push("feffects.Tween::resume");
	var $spos = $s.length;
	this._startTime += Date.now().getTime() - this._pauseTime;
	this._reverseTime += Date.now().getTime() - this._pauseTime;
	feffects.Tween.setTweenActive(this);
	this.isPlaying = true;
	$s.pop();
}
feffects.Tween.prototype.seek = function(ms) {
	$s.push("feffects.Tween::seek");
	var $spos = $s.length;
	this._offsetTime = ms;
	$s.pop();
}
feffects.Tween.prototype.reverse = function() {
	$s.push("feffects.Tween::reverse");
	var $spos = $s.length;
	this.reversed = !this.reversed;
	if(!this.reversed) this._startTime += (Date.now().getTime() - this._reverseTime) * 2;
	this._reverseTime = Date.now().getTime();
	$s.pop();
}
feffects.Tween.prototype.stop = function() {
	$s.push("feffects.Tween::stop");
	var $spos = $s.length;
	feffects.Tween.RemoveTween(this);
	this.isPlaying = false;
	$s.pop();
}
feffects.Tween.prototype.setTweenHandlers = function(update,end) {
	$s.push("feffects.Tween::setTweenHandlers");
	var $spos = $s.length;
	this.updateFunc = update;
	this.endFunc = end;
	$s.pop();
}
feffects.Tween.prototype.setEasing = function(easingFunc) {
	$s.push("feffects.Tween::setEasing");
	var $spos = $s.length;
	if(easingFunc != null) this._easingF = easingFunc;
	$s.pop();
}
feffects.Tween.prototype.updateFunc = function(e) {
	$s.push("feffects.Tween::updateFunc");
	var $spos = $s.length;
	$s.pop();
}
feffects.Tween.prototype.endFunc = function(e) {
	$s.push("feffects.Tween::endFunc");
	var $spos = $s.length;
	$s.pop();
}
feffects.Tween.prototype.doInterval = function() {
	$s.push("feffects.Tween::doInterval");
	var $spos = $s.length;
	var stamp = Date.now().getTime();
	var curTime = 0;
	if(this.reversed) curTime = this._reverseTime * 2 - stamp - this._startTime + this._offsetTime; else curTime = stamp - this._startTime + this._offsetTime;
	var curVal = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
	if(curTime >= this.duration || curTime <= 0) this.endTween(); else {
		if($closure(this,"updateFunc") != null) this.updateFunc(curVal);
		if(this._prop != null) this._obj[this._prop] = curVal;
	}
	this.position = curTime;
	$s.pop();
}
feffects.Tween.prototype.getCurVal = function(curTime) {
	$s.push("feffects.Tween::getCurVal");
	var $spos = $s.length;
	var $tmp = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.Tween.prototype.getStamp = function() {
	$s.push("feffects.Tween::getStamp");
	var $spos = $s.length;
	var $tmp = Date.now().getTime();
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.Tween.prototype.endTween = function() {
	$s.push("feffects.Tween::endTween");
	var $spos = $s.length;
	feffects.Tween.RemoveTween(this);
	var val = 0.0;
	if(this.reversed) val = this._initVal; else val = this._endVal;
	if($closure(this,"updateFunc") != null) this.updateFunc(val);
	if($closure(this,"endFunc") != null) this.endFunc(val);
	if(this._prop != null) this._obj[this._prop] = val;
	$s.pop();
}
feffects.Tween.prototype.easingEquation = function(t,b,c,d) {
	$s.push("feffects.Tween::easingEquation");
	var $spos = $s.length;
	var $tmp = c / 2 * (Math.sin(Math.PI * (t / d - 0.5)) + 1) + b;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.Tween.prototype.__class__ = feffects.Tween;
org.intermedia.view.ImageUtils = function() { }
org.intermedia.view.ImageUtils.__name__ = ["org","intermedia","view","ImageUtils"];
org.intermedia.view.ImageUtils.computeMaskSize = function(cellPerLine,thumbWidthPercent) {
	$s.push("org.intermedia.view.ImageUtils::computeMaskSize");
	var $spos = $s.length;
	if(thumbWidthPercent == null) thumbWidthPercent = 100;
	var maskPixelSize = { width : 0, height : 0};
	if(cellPerLine != 0) maskPixelSize.width = Std["int"](js.Lib.window.innerWidth * thumbWidthPercent / (cellPerLine * 100)); else maskPixelSize.width = Std["int"](js.Lib.window.innerWidth * thumbWidthPercent / 100);
	maskPixelSize.height = 90;
	$s.pop();
	return maskPixelSize;
	$s.pop();
}
org.intermedia.view.ImageUtils.cropImage = function(image,maskSize) {
	$s.push("org.intermedia.view.ImageUtils::cropImage");
	var $spos = $s.length;
	var maskRatio = maskSize.width / maskSize.height;
	var imageRatio = 0;
	if(image.naturalHeight != 0) imageRatio = image.naturalWidth / image.naturalHeight;
	var resizedImageSize = { width : 0, height : 0};
	if(imageRatio > maskRatio) {
		resizedImageSize.height = maskSize.height;
		resizedImageSize.width = Std["int"](resizedImageSize.height * imageRatio);
		image.style.height = Std.string(resizedImageSize.height) + "px";
		image.style.marginLeft = Std.string(-Math.abs(maskSize.width - resizedImageSize.width) / 2) + "px";
	} else {
		resizedImageSize.width = maskSize.width;
		resizedImageSize.height = Std["int"](resizedImageSize.width / imageRatio);
		image.style.width = Std.string(resizedImageSize.width) + "px";
		image.style.marginTop = Std.string(-Math.abs(maskSize.height - resizedImageSize.height) / 2) + "px";
	}
	$s.pop();
	return image;
	$s.pop();
}
org.intermedia.view.ImageUtils.prototype.__class__ = org.intermedia.view.ImageUtils;
org.intermedia.view.CellText = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.CellText::new");
	var $spos = $s.length;
	org.intermedia.view.CellBase.call(this);
	org.intermedia.view.CellTextStyle.setCellStyle(this.node);
	$s.pop();
}
org.intermedia.view.CellText.__name__ = ["org","intermedia","view","CellText"];
org.intermedia.view.CellText.__super__ = org.intermedia.view.CellBase;
for(var k in org.intermedia.view.CellBase.prototype ) org.intermedia.view.CellText.prototype[k] = org.intermedia.view.CellBase.prototype[k];
org.intermedia.view.CellText.prototype.updateView = function() {
	$s.push("org.intermedia.view.CellText::updateView");
	var $spos = $s.length;
	var cellData = this._data;
	var cellTextContainer = js.Lib.document.createElement("div");
	if(cellData.title != "" && cellData.title != null) {
		var textElement = js.Lib.document.createTextNode(cellData.title);
		cellTextContainer.appendChild(textElement);
		org.intermedia.view.CellTextStyle.setCellTextStyle(cellTextContainer);
		this.node.appendChild(cellTextContainer);
	}
	$s.pop();
}
org.intermedia.view.CellText.prototype.__class__ = org.intermedia.view.CellText;
org.intermedia.view.CellThumbText1 = function(cellPerLine,cellStyle) {
	if( cellPerLine === $_ ) return;
	$s.push("org.intermedia.view.CellThumbText1::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine);
	this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine,35);
	$s.pop();
}
org.intermedia.view.CellThumbText1.__name__ = ["org","intermedia","view","CellThumbText1"];
org.intermedia.view.CellThumbText1.__super__ = org.intermedia.view.CellBase;
for(var k in org.intermedia.view.CellBase.prototype ) org.intermedia.view.CellThumbText1.prototype[k] = org.intermedia.view.CellBase.prototype[k];
org.intermedia.view.CellThumbText1.prototype._thumbMask = null;
org.intermedia.view.CellThumbText1.prototype.initCellStyle = function() {
	$s.push("org.intermedia.view.CellThumbText1::initCellStyle");
	var $spos = $s.length;
	this._cellStyle = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, thumbnail : org.intermedia.view.CellThumbText1Style.setThumbnailStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
	$s.pop();
}
org.intermedia.view.CellThumbText1.prototype.updateView = function() {
	$s.push("org.intermedia.view.CellThumbText1::updateView");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.CellThumbText1.prototype.__class__ = org.intermedia.view.CellThumbText1;
org.intermedia.view.ListViewBase = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.ListViewBase::new");
	var $spos = $s.length;
	org.intermedia.view.ViewBase.call(this);
	org.intermedia.view.ListViewStyle.setListStyle(this.node);
	this.displayListBottomLoader = true;
	this._cells = new Array();
	this._listBottomLoader = js.Lib.document.createElement("img");
	org.intermedia.view.ListViewStyle.loader(this._listBottomLoader);
	this._listBottomLoader.src = "assets/loading.gif";
	this.node.onscroll = $closure(this,"onScrollCallback");
	$s.pop();
}
org.intermedia.view.ListViewBase.__name__ = ["org","intermedia","view","ListViewBase"];
org.intermedia.view.ListViewBase.__super__ = org.intermedia.view.ViewBase;
for(var k in org.intermedia.view.ViewBase.prototype ) org.intermedia.view.ListViewBase.prototype[k] = org.intermedia.view.ViewBase.prototype[k];
org.intermedia.view.ListViewBase.prototype.onListItemSelected = null;
org.intermedia.view.ListViewBase.prototype.onDataRequest = null;
org.intermedia.view.ListViewBase.prototype.displayListBottomLoader = null;
org.intermedia.view.ListViewBase.prototype._cells = null;
org.intermedia.view.ListViewBase.prototype.id = null;
org.intermedia.view.ListViewBase.prototype._listBottomLoader = null;
org.intermedia.view.ListViewBase.prototype.updateView = function() {
	$s.push("org.intermedia.view.ListViewBase::updateView");
	var $spos = $s.length;
	var me = this;
	var _g = 0, _g1 = Reflect.fields(this._data);
	while(_g < _g1.length) {
		var index = _g1[_g];
		++_g;
		var cell = [this.createCell()];
		cell[0].setData(Reflect.field(this._data,index));
		cell[0].node.onmouseup = (function(cell) {
			$s.push("org.intermedia.view.ListViewBase::updateView@78");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("org.intermedia.view.ListViewBase::updateView@78@78");
				var $spos = $s.length;
				me.onListItemSelectedCallback(cell[0].getData());
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(cell);
		this._cells.push(cell[0]);
		this.node.appendChild(cell[0].node);
	}
	if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
	if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
	$s.pop();
}
org.intermedia.view.ListViewBase.prototype.createCell = function() {
	$s.push("org.intermedia.view.ListViewBase::createCell");
	var $spos = $s.length;
	var cell = new org.intermedia.view.CellBase();
	$s.pop();
	return cell;
	$s.pop();
}
org.intermedia.view.ListViewBase.prototype.onListItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.ListViewBase::onListItemSelectedCallback");
	var $spos = $s.length;
	if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	$s.pop();
}
org.intermedia.view.ListViewBase.prototype.onScrollCallback = function(event) {
	$s.push("org.intermedia.view.ListViewBase::onScrollCallback");
	var $spos = $s.length;
	if(this.node.scrollTop >= this.node.scrollHeight - js.Lib.window.innerHeight) this.onDataRequestCallback(this.id);
	$s.pop();
}
org.intermedia.view.ListViewBase.prototype.onDataRequestCallback = function(id) {
	$s.push("org.intermedia.view.ListViewBase::onDataRequestCallback");
	var $spos = $s.length;
	if(this.onDataRequest != null) this.onDataRequest(id);
	$s.pop();
}
org.intermedia.view.ListViewBase.prototype.__class__ = org.intermedia.view.ListViewBase;
org.intermedia.view.MenuListViewText = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.MenuListViewText::new");
	var $spos = $s.length;
	this._index = 0;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.MenuListViewStyle.setListStyle(this.node);
	$s.pop();
}
org.intermedia.view.MenuListViewText.__name__ = ["org","intermedia","view","MenuListViewText"];
org.intermedia.view.MenuListViewText.__super__ = org.intermedia.view.ListViewBase;
for(var k in org.intermedia.view.ListViewBase.prototype ) org.intermedia.view.MenuListViewText.prototype[k] = org.intermedia.view.ListViewBase.prototype[k];
org.intermedia.view.MenuListViewText.prototype._index = null;
org.intermedia.view.MenuListViewText.prototype.index = null;
org.intermedia.view.MenuListViewText.prototype._menuItem0Width = null;
org.intermedia.view.MenuListViewText.prototype._menuItem1Width = null;
org.intermedia.view.MenuListViewText.prototype._menuItem2Width = null;
org.intermedia.view.MenuListViewText.prototype._menuItem0LeftPos = null;
org.intermedia.view.MenuListViewText.prototype._menuItem1LeftPos = null;
org.intermedia.view.MenuListViewText.prototype._menuItem2LeftPos = null;
org.intermedia.view.MenuListViewText.prototype.getIndex = function() {
	$s.push("org.intermedia.view.MenuListViewText::getIndex");
	var $spos = $s.length;
	var $tmp = this._index;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.setIndex = function(v) {
	$s.push("org.intermedia.view.MenuListViewText::setIndex");
	var $spos = $s.length;
	this._index = v;
	var menuItem0LeftEnd = 0;
	var menuItem1LeftEnd = 0;
	var menuItem2LeftEnd = 0;
	switch(this._index) {
	case 0:
		menuItem0LeftEnd = Std["int"]((js.Lib.window.innerWidth - this._menuItem0Width) / 2);
		menuItem1LeftEnd = js.Lib.window.innerWidth - this._menuItem1Width;
		menuItem2LeftEnd = js.Lib.window.innerWidth;
		break;
	case 1:
		menuItem0LeftEnd = 0;
		menuItem1LeftEnd = Std["int"]((js.Lib.window.innerWidth - this._menuItem1Width) / 2);
		menuItem2LeftEnd = js.Lib.window.innerWidth - this._menuItem2Width;
		break;
	case 2:
		menuItem0LeftEnd = -this._menuItem0Width;
		menuItem1LeftEnd = 0;
		menuItem2LeftEnd = Std["int"]((js.Lib.window.innerWidth - this._menuItem2Width) / 2);
		break;
	default:
	}
	var tween0 = new feffects.Tween(this._cells[0].node.offsetLeft,menuItem0LeftEnd,600,feffects.easing.Quint.easeOut);
	tween0.setTweenHandlers($closure(this,"menuItem0Move"),$closure(this,"menuItemMoveEnd"));
	tween0.start();
	var tween1 = new feffects.Tween(this._cells[1].node.offsetLeft,menuItem1LeftEnd,600,feffects.easing.Quint.easeOut);
	tween1.setTweenHandlers($closure(this,"menuItem1Move"),$closure(this,"menuItemMoveEnd"));
	tween1.start();
	var tween2 = new feffects.Tween(this._cells[2].node.offsetLeft,menuItem2LeftEnd,600,feffects.easing.Quint.easeOut);
	tween2.setTweenHandlers($closure(this,"menuItem2Move"),$closure(this,"menuItemMoveEnd"));
	tween2.start();
	haxe.Log.trace(this._cells[0].node.offsetLeft + "," + this._cells[1].node.offsetLeft + "," + this._cells[2].node.offsetLeft,{ fileName : "MenuListViewText.hx", lineNumber : 130, className : "org.intermedia.view.MenuListViewText", methodName : "setIndex"});
	$s.pop();
	return v;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.menuItem0Move = function(e) {
	$s.push("org.intermedia.view.MenuListViewText::menuItem0Move");
	var $spos = $s.length;
	this._cells[0].node.style.left = Std["int"](e) + "px";
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.menuItem1Move = function(e) {
	$s.push("org.intermedia.view.MenuListViewText::menuItem1Move");
	var $spos = $s.length;
	this._cells[1].node.style.left = Std["int"](e) + "px";
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.menuItem2Move = function(e) {
	$s.push("org.intermedia.view.MenuListViewText::menuItem2Move");
	var $spos = $s.length;
	this._cells[2].node.style.left = Std["int"](e) + "px";
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.menuItemMoveEnd = function(e) {
	$s.push("org.intermedia.view.MenuListViewText::menuItemMoveEnd");
	var $spos = $s.length;
	this.computeMenuItemsLeftPos();
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.computeMenuItemsWidth = function() {
	$s.push("org.intermedia.view.MenuListViewText::computeMenuItemsWidth");
	var $spos = $s.length;
	this._menuItem0Width = this._cells[0].node.clientWidth;
	this._menuItem1Width = this._cells[1].node.clientWidth;
	this._menuItem2Width = this._cells[2].node.clientWidth;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.computeMenuItemsLeftPos = function() {
	$s.push("org.intermedia.view.MenuListViewText::computeMenuItemsLeftPos");
	var $spos = $s.length;
	this._menuItem0LeftPos = this._cells[0].node.offsetLeft;
	this._menuItem1LeftPos = this._cells[1].node.offsetLeft;
	this._menuItem2LeftPos = this._cells[2].node.offsetLeft;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.updateView = function() {
	$s.push("org.intermedia.view.MenuListViewText::updateView");
	var $spos = $s.length;
	var me = this;
	this._index = 0;
	var _g = 0, _g1 = Reflect.fields(this._data);
	while(_g < _g1.length) {
		var field = _g1[_g];
		++_g;
		var cell = [this.createCell()];
		cell[0].setData(Reflect.field(this._data,field));
		cell[0].node.onmouseup = (function(cell) {
			$s.push("org.intermedia.view.MenuListViewText::updateView@220");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("org.intermedia.view.MenuListViewText::updateView@220@220");
				var $spos = $s.length;
				me.onListItemSelectedCallback(cell[0].getData());
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
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
	if(this._listBottomLoader.parentNode != null) this.node.removeChild(this._listBottomLoader);
	if(this.displayListBottomLoader == true) this.node.appendChild(this._listBottomLoader);
	this.computeMenuItemsWidth();
	this.computeMenuItemsLeftPos();
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.createCell = function() {
	$s.push("org.intermedia.view.MenuListViewText::createCell");
	var $spos = $s.length;
	var cell = new org.intermedia.view.MenuCellText();
	$s.pop();
	return cell;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.setCellsStyle = function() {
	$s.push("org.intermedia.view.MenuListViewText::setCellsStyle");
	var $spos = $s.length;
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
	$s.pop();
	return style;
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.onListItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.MenuListViewText::onListItemSelectedCallback");
	var $spos = $s.length;
	this.setIndex(cellData.id);
	org.intermedia.view.ListViewBase.prototype.onListItemSelectedCallback.call(this,cellData);
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.moveHorizontally = function(ratio) {
	$s.push("org.intermedia.view.MenuListViewText::moveHorizontally");
	var $spos = $s.length;
	this.menuItem0Move(this._menuItem0LeftPos + (js.Lib.window.innerWidth - this._menuItem0Width) * ratio / 2);
	this.menuItem1Move(this._menuItem1LeftPos + (js.Lib.window.innerWidth - this._menuItem1Width) * ratio / 2);
	this.menuItem2Move(this._menuItem2LeftPos + (js.Lib.window.innerWidth - this._menuItem2Width) * ratio / 2);
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.horizontalRelease = function(listIndex) {
	$s.push("org.intermedia.view.MenuListViewText::horizontalRelease");
	var $spos = $s.length;
	this.setIndex(listIndex);
	$s.pop();
}
org.intermedia.view.MenuListViewText.prototype.__class__ = org.intermedia.view.MenuListViewText;
org.intermedia.view.CellThumb = function(cellPerLine,cellStyle,thumbWidthPercent) {
	if( cellPerLine === $_ ) return;
	$s.push("org.intermedia.view.CellThumb::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this,cellPerLine);
	this._thumbMask = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine);
	$s.pop();
}
org.intermedia.view.CellThumb.__name__ = ["org","intermedia","view","CellThumb"];
org.intermedia.view.CellThumb.__super__ = org.intermedia.view.CellBase;
for(var k in org.intermedia.view.CellBase.prototype ) org.intermedia.view.CellThumb.prototype[k] = org.intermedia.view.CellBase.prototype[k];
org.intermedia.view.CellThumb.prototype._thumbMask = null;
org.intermedia.view.CellThumb.prototype.initCellStyle = function() {
	$s.push("org.intermedia.view.CellThumb::initCellStyle");
	var $spos = $s.length;
	this._cellStyle = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : org.intermedia.view.CellThumbStyle.setThumbnailStyle, textBlock : null, title : null, author : null, line : null};
	$s.pop();
}
org.intermedia.view.CellThumb.prototype.updateView = function() {
	$s.push("org.intermedia.view.CellThumb::updateView");
	var $spos = $s.length;
	if(this._data.thumbUrl != "" && this._data.thumbUrl != null) {
		var croppedImage = new org.intermedia.view.CroppedImage(this._data.thumbUrl,this._thumbMask);
		this.node.appendChild(croppedImage.node);
	}
	$s.pop();
}
org.intermedia.view.CellThumb.prototype.__class__ = org.intermedia.view.CellThumb;
org.intermedia.view.ListViewStyle = function() { }
org.intermedia.view.ListViewStyle.__name__ = ["org","intermedia","view","ListViewStyle"];
org.intermedia.view.ListViewStyle.setListStyle = function(node) {
	$s.push("org.intermedia.view.ListViewStyle::setListStyle");
	var $spos = $s.length;
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
	node.style.overflowY = "scroll";
	node.style.backgroundColor = "#CCCCCC";
	$s.pop();
}
org.intermedia.view.ListViewStyle.loader = function(node) {
	$s.push("org.intermedia.view.ListViewStyle::loader");
	var $spos = $s.length;
	var VERTICAL_MARGIN = 20;
	node.style.display = "block";
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.marginTop = Std.string(VERTICAL_MARGIN) + "px";
	node.style.marginBottom = Std.string(VERTICAL_MARGIN) + "px";
	node.style.top = Std.string(js.Lib.window.innerHeight) + "px";
	$s.pop();
}
org.intermedia.view.ListViewStyle.prototype.__class__ = org.intermedia.view.ListViewStyle;
Reflect = function() { }
Reflect.__name__ = ["Reflect"];
Reflect.hasField = function(o,field) {
	$s.push("Reflect::hasField");
	var $spos = $s.length;
	if(o.hasOwnProperty != null) {
		var $tmp = o.hasOwnProperty(field);
		$s.pop();
		return $tmp;
	}
	var arr = Reflect.fields(o);
	var $it0 = arr.iterator();
	while( $it0.hasNext() ) {
		var t = $it0.next();
		if(t == field) {
			$s.pop();
			return true;
		}
	}
	$s.pop();
	return false;
	$s.pop();
}
Reflect.field = function(o,field) {
	$s.push("Reflect::field");
	var $spos = $s.length;
	var v = null;
	try {
		v = o[field];
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
	}
	$s.pop();
	return v;
	$s.pop();
}
Reflect.setField = function(o,field,value) {
	$s.push("Reflect::setField");
	var $spos = $s.length;
	o[field] = value;
	$s.pop();
}
Reflect.callMethod = function(o,func,args) {
	$s.push("Reflect::callMethod");
	var $spos = $s.length;
	var $tmp = func.apply(o,args);
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.fields = function(o) {
	$s.push("Reflect::fields");
	var $spos = $s.length;
	if(o == null) {
		var $tmp = new Array();
		$s.pop();
		return $tmp;
	}
	var a = new Array();
	if(o.hasOwnProperty) {
		for(var i in o) if( o.hasOwnProperty(i) ) a.push(i);
	} else {
		var t;
		try {
			t = o.__proto__;
		} catch( e ) {
			$e = [];
			while($s.length >= $spos) $e.unshift($s.pop());
			$s.push($e[0]);
			t = null;
		}
		if(t != null) o.__proto__ = null;
		for(var i in o) if( i != "__proto__" ) a.push(i);
		if(t != null) o.__proto__ = t;
	}
	$s.pop();
	return a;
	$s.pop();
}
Reflect.isFunction = function(f) {
	$s.push("Reflect::isFunction");
	var $spos = $s.length;
	var $tmp = typeof(f) == "function" && f.__name__ == null;
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.compare = function(a,b) {
	$s.push("Reflect::compare");
	var $spos = $s.length;
	var $tmp = a == b?0:a > b?1:-1;
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.compareMethods = function(f1,f2) {
	$s.push("Reflect::compareMethods");
	var $spos = $s.length;
	if(f1 == f2) {
		$s.pop();
		return true;
	}
	if(!Reflect.isFunction(f1) || !Reflect.isFunction(f2)) {
		$s.pop();
		return false;
	}
	var $tmp = f1.scope == f2.scope && f1.method == f2.method && f1.method != null;
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.isObject = function(v) {
	$s.push("Reflect::isObject");
	var $spos = $s.length;
	if(v == null) {
		$s.pop();
		return false;
	}
	var t = typeof(v);
	var $tmp = t == "string" || t == "object" && !v.__enum__ || t == "function" && v.__name__ != null;
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.deleteField = function(o,f) {
	$s.push("Reflect::deleteField");
	var $spos = $s.length;
	if(!Reflect.hasField(o,f)) {
		$s.pop();
		return false;
	}
	delete(o[f]);
	$s.pop();
	return true;
	$s.pop();
}
Reflect.copy = function(o) {
	$s.push("Reflect::copy");
	var $spos = $s.length;
	var o2 = { };
	var _g = 0, _g1 = Reflect.fields(o);
	while(_g < _g1.length) {
		var f = _g1[_g];
		++_g;
		o2[f] = Reflect.field(o,f);
	}
	$s.pop();
	return o2;
	$s.pop();
}
Reflect.makeVarArgs = function(f) {
	$s.push("Reflect::makeVarArgs");
	var $spos = $s.length;
	var $tmp = function() {
		$s.push("Reflect::makeVarArgs@108");
		var $spos = $s.length;
		var a = new Array();
		var _g1 = 0, _g = arguments.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(arguments[i]);
		}
		var $tmp = f(a);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.prototype.__class__ = Reflect;
org.intermedia.view.ScrollableMenu = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.ScrollableMenu::new");
	var $spos = $s.length;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.MenuListViewStyle.setMenuStyle(this.node);
	this._menu = new org.intermedia.view.MenuListViewText();
	this._menu.displayListBottomLoader = false;
	this.node.appendChild(this._menu.node);
	this._menu.onListItemSelected = $closure(this,"onListItemSelectedCallback");
	$s.pop();
}
org.intermedia.view.ScrollableMenu.__name__ = ["org","intermedia","view","ScrollableMenu"];
org.intermedia.view.ScrollableMenu.__super__ = org.intermedia.view.ListViewBase;
for(var k in org.intermedia.view.ListViewBase.prototype ) org.intermedia.view.ScrollableMenu.prototype[k] = org.intermedia.view.ListViewBase.prototype[k];
org.intermedia.view.ScrollableMenu.prototype._menu = null;
org.intermedia.view.ScrollableMenu.prototype._index = null;
org.intermedia.view.ScrollableMenu.prototype.index = null;
org.intermedia.view.ScrollableMenu.prototype.updateView = function() {
	$s.push("org.intermedia.view.ScrollableMenu::updateView");
	var $spos = $s.length;
	this._menu.setData(this._data);
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.getIndex = function() {
	$s.push("org.intermedia.view.ScrollableMenu::getIndex");
	var $spos = $s.length;
	var $tmp = this._index;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.setIndex = function(v) {
	$s.push("org.intermedia.view.ScrollableMenu::setIndex");
	var $spos = $s.length;
	this._index = v;
	this._menu.setIndex(v);
	$s.pop();
	return v;
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.onListItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.ScrollableMenu::onListItemSelectedCallback");
	var $spos = $s.length;
	this.setIndex(cellData.id);
	org.intermedia.view.ListViewBase.prototype.onListItemSelectedCallback.call(this,cellData);
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.horizontalMove = function(ratio) {
	$s.push("org.intermedia.view.ScrollableMenu::horizontalMove");
	var $spos = $s.length;
	haxe.Firebug.trace(ratio,{ fileName : "ScrollableMenu.hx", lineNumber : 121, className : "org.intermedia.view.ScrollableMenu", methodName : "horizontalMove"});
	this._menu.moveHorizontally(ratio);
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.horizontalRelease = function(listIndex) {
	$s.push("org.intermedia.view.ScrollableMenu::horizontalRelease");
	var $spos = $s.length;
	this._menu.horizontalRelease(listIndex);
	$s.pop();
}
org.intermedia.view.ScrollableMenu.prototype.__class__ = org.intermedia.view.ScrollableMenu;
if(!org.intermedia.model) org.intermedia.model = {}
org.intermedia.model.XmlLoader = function(xmlUrl,online,successCallback,errorCallback,listId) {
	if( xmlUrl === $_ ) return;
	$s.push("org.intermedia.model.XmlLoader::new");
	var $spos = $s.length;
	if(listId == null) listId = "";
	this._online = online;
	this.onLoadSuccess = successCallback;
	this.onLoadError = errorCallback;
	this.loadXmlFeed(listId,xmlUrl);
	$s.pop();
}
org.intermedia.model.XmlLoader.__name__ = ["org","intermedia","model","XmlLoader"];
org.intermedia.model.XmlLoader.prototype.onLoadSuccess = null;
org.intermedia.model.XmlLoader.prototype.onLoadError = null;
org.intermedia.model.XmlLoader.prototype._online = null;
org.intermedia.model.XmlLoader.prototype.loadXmlFeed = function(listId,xmlUrl) {
	$s.push("org.intermedia.model.XmlLoader::loadXmlFeed");
	var $spos = $s.length;
	var me = this;
	var fullUrl = "";
	if(!this._online) fullUrl = xmlUrl; else fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);
	try {
		var httpRequest = new haxe.Http(fullUrl);
		httpRequest.onData = function(xml) {
			$s.push("org.intermedia.model.XmlLoader::loadXmlFeed@70");
			var $spos = $s.length;
			me.onXmlLoaded(listId,xml);
			$s.pop();
		};
		httpRequest.onError = $closure(this,"onXmlError");
		httpRequest.request(false);
	} catch( error ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		this.onXmlError(error);
	}
	$s.pop();
}
org.intermedia.model.XmlLoader.prototype.onXmlError = function(error) {
	$s.push("org.intermedia.model.XmlLoader::onXmlError");
	var $spos = $s.length;
	if(this.onLoadError != null) this.onLoadError(error);
	$s.pop();
}
org.intermedia.model.XmlLoader.prototype.onXmlLoaded = function(listId,xmlString) {
	$s.push("org.intermedia.model.XmlLoader::onXmlLoaded");
	var $spos = $s.length;
	var xml = Xml.parse(xmlString);
	if(this.onLoadSuccess != null) this.onLoadSuccess(listId,xml);
	$s.pop();
}
org.intermedia.model.XmlLoader.prototype.__class__ = org.intermedia.model.XmlLoader;
org.intermedia.view.CellThumbText1Style = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = ["org","intermedia","view","CellThumbText1Style"];
org.intermedia.view.CellThumbText1Style.setCellStyle = function(node,cellPerLine) {
	$s.push("org.intermedia.view.CellThumbText1Style::setCellStyle");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellSize = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine,35);
	node.style.height = Std.string(cellSize.height) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	$s.pop();
	return cellSize;
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setThumbnailStyle = function(image,maskSize) {
	$s.push("org.intermedia.view.CellThumbText1Style::setThumbnailStyle");
	var $spos = $s.length;
	org.intermedia.view.CellThumbStyle.setThumbnailStyle(image,maskSize);
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTextBlockStyle = function(node) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTextBlockStyle");
	var $spos = $s.length;
	node.style.display = "inline-block";
	node.style.marginLeft = "2%";
	node.style.verticalAlign = "top";
	node.style.width = Std.string(60) + "%";
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTextStyle = function(node) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTextStyle");
	var $spos = $s.length;
	node.style.display = "block";
	node.style.color = "#202020";
	node.style.fontFamily = "Arial, sans-serif";
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTitleStyle = function(node,screenResolutionSize) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTitleStyle");
	var $spos = $s.length;
	org.intermedia.view.CellThumbText1Style.setTextStyle(node);
	if(screenResolutionSize == null) screenResolutionSize = org.intermedia.view.ScreenResolutionSize.small;
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	node.style.fontSize = Std.string(fontSize) + "px";
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setAuthorStyle = function(node,screenResolutionSize) {
	$s.push("org.intermedia.view.CellThumbText1Style::setAuthorStyle");
	var $spos = $s.length;
	org.intermedia.view.CellThumbText1Style.setTextStyle(node);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "normal";
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setLineStyle = function(node) {
	$s.push("org.intermedia.view.CellThumbText1Style::setLineStyle");
	var $spos = $s.length;
	node.style.display = "block";
	node.style.position = "relative";
	node.style.width = "100%";
	node.style.height = "1px";
	node.style.marginTop = Std.string(2) + "px";
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.prototype.__class__ = org.intermedia.view.CellThumbText1Style;
org.intermedia.view.CellTextStyle = function() { }
org.intermedia.view.CellTextStyle.__name__ = ["org","intermedia","view","CellTextStyle"];
org.intermedia.view.CellTextStyle.setCellStyle = function(node) {
	$s.push("org.intermedia.view.CellTextStyle::setCellStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.CellTextStyle.setCellTextStyle = function(node) {
	$s.push("org.intermedia.view.CellTextStyle::setCellTextStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.CellTextStyle.setCellLineStyle = function(node) {
	$s.push("org.intermedia.view.CellTextStyle::setCellLineStyle");
	var $spos = $s.length;
	node.style.display = "block";
	node.style.position = "relative";
	node.style.width = "100%";
	node.style.height = Std.string(1) + "px";
	node.style.marginTop = Std.string(5) + "px";
	$s.pop();
}
org.intermedia.view.CellTextStyle.prototype.__class__ = org.intermedia.view.CellTextStyle;
haxe.FastCell = function(elt,next) {
	if( elt === $_ ) return;
	$s.push("haxe.FastCell::new");
	var $spos = $s.length;
	this.elt = elt;
	this.next = next;
	$s.pop();
}
haxe.FastCell.__name__ = ["haxe","FastCell"];
haxe.FastCell.prototype.elt = null;
haxe.FastCell.prototype.next = null;
haxe.FastCell.prototype.__class__ = haxe.FastCell;
IntIter = function(min,max) {
	if( min === $_ ) return;
	$s.push("IntIter::new");
	var $spos = $s.length;
	this.min = min;
	this.max = max;
	$s.pop();
}
IntIter.__name__ = ["IntIter"];
IntIter.prototype.min = null;
IntIter.prototype.max = null;
IntIter.prototype.hasNext = function() {
	$s.push("IntIter::hasNext");
	var $spos = $s.length;
	var $tmp = this.min < this.max;
	$s.pop();
	return $tmp;
	$s.pop();
}
IntIter.prototype.next = function() {
	$s.push("IntIter::next");
	var $spos = $s.length;
	var $tmp = this.min++;
	$s.pop();
	return $tmp;
	$s.pop();
}
IntIter.prototype.__class__ = IntIter;
org.intermedia.view.MenuListViewStyle = function() { }
org.intermedia.view.MenuListViewStyle.__name__ = ["org","intermedia","view","MenuListViewStyle"];
org.intermedia.view.MenuListViewStyle.setMenuStyle = function(node) {
	$s.push("org.intermedia.view.MenuListViewStyle::setMenuStyle");
	var $spos = $s.length;
	node.style.position = "absolute";
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
	node.style.overflowX = "hidden";
	node.style.overflowY = "auto";
	$s.pop();
}
org.intermedia.view.MenuListViewStyle.setListStyle = function(node) {
	$s.push("org.intermedia.view.MenuListViewStyle::setListStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.MenuListViewStyle.prototype.__class__ = org.intermedia.view.MenuListViewStyle;
org.intermedia.model.Feeds = function() { }
org.intermedia.model.Feeds.__name__ = ["org","intermedia","model","Feeds"];
org.intermedia.model.Feeds.prototype.__class__ = org.intermedia.model.Feeds;
org.intermedia.view.Constants = function() { }
org.intermedia.view.Constants.__name__ = ["org","intermedia","view","Constants"];
org.intermedia.view.Constants.prototype.__class__ = org.intermedia.view.Constants;
org.intermedia.view.ListViewText = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.ListViewText::new");
	var $spos = $s.length;
	org.intermedia.view.ListViewBase.call(this);
	$s.pop();
}
org.intermedia.view.ListViewText.__name__ = ["org","intermedia","view","ListViewText"];
org.intermedia.view.ListViewText.__super__ = org.intermedia.view.ListViewBase;
for(var k in org.intermedia.view.ListViewBase.prototype ) org.intermedia.view.ListViewText.prototype[k] = org.intermedia.view.ListViewBase.prototype[k];
org.intermedia.view.ListViewText.prototype.createCell = function() {
	$s.push("org.intermedia.view.ListViewText::createCell");
	var $spos = $s.length;
	var cell = new org.intermedia.view.CellText();
	$s.pop();
	return cell;
	$s.pop();
}
org.intermedia.view.ListViewText.prototype.__class__ = org.intermedia.view.ListViewText;
if(typeof js=='undefined') js = {}
js.Boot = function() { }
js.Boot.__name__ = ["js","Boot"];
js.Boot.__unhtml = function(s) {
	$s.push("js.Boot::__unhtml");
	var $spos = $s.length;
	var $tmp = s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
	$s.pop();
	return $tmp;
	$s.pop();
}
js.Boot.__trace = function(v,i) {
	$s.push("js.Boot::__trace");
	var $spos = $s.length;
	var msg = i != null?i.fileName + ":" + i.lineNumber + ": ":"";
	msg += js.Boot.__unhtml(js.Boot.__string_rec(v,"")) + "<br/>";
	var d = document.getElementById("haxe:trace");
	if(d == null) alert("No haxe:trace element defined\n" + msg); else d.innerHTML += msg;
	$s.pop();
}
js.Boot.__clear_trace = function() {
	$s.push("js.Boot::__clear_trace");
	var $spos = $s.length;
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML = "";
	$s.pop();
}
js.Boot.__closure = function(o,f) {
	$s.push("js.Boot::__closure");
	var $spos = $s.length;
	var m = o[f];
	if(m == null) {
		$s.pop();
		return null;
	}
	var f1 = function() {
		$s.push("js.Boot::__closure@67");
		var $spos = $s.length;
		var $tmp = m.apply(o,arguments);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	f1.scope = o;
	f1.method = m;
	$s.pop();
	return f1;
	$s.pop();
}
js.Boot.__string_rec = function(o,s) {
	$s.push("js.Boot::__string_rec");
	var $spos = $s.length;
	if(o == null) {
		$s.pop();
		return "null";
	}
	if(s.length >= 5) {
		$s.pop();
		return "<...>";
	}
	var t = typeof(o);
	if(t == "function" && (o.__name__ != null || o.__ename__ != null)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__ != null) {
				if(o.length == 2) {
					var $tmp = o[0];
					$s.pop();
					return $tmp;
				}
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2, _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				var $tmp = str + ")";
				$s.pop();
				return $tmp;
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
			$s.pop();
			return str;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			$e = [];
			while($s.length >= $spos) $e.unshift($s.pop());
			$s.push($e[0]);
			$s.pop();
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") {
				$s.pop();
				return s2;
			}
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) { ;
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		$s.pop();
		return str;
	case "function":
		$s.pop();
		return "<function>";
	case "string":
		$s.pop();
		return o;
	default:
		var $tmp = String(o);
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
js.Boot.__interfLoop = function(cc,cl) {
	$s.push("js.Boot::__interfLoop");
	var $spos = $s.length;
	if(cc == null) {
		$s.pop();
		return false;
	}
	if(cc == cl) {
		$s.pop();
		return true;
	}
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0, _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) {
				$s.pop();
				return true;
			}
		}
	}
	var $tmp = js.Boot.__interfLoop(cc.__super__,cl);
	$s.pop();
	return $tmp;
	$s.pop();
}
js.Boot.__instanceof = function(o,cl) {
	$s.push("js.Boot::__instanceof");
	var $spos = $s.length;
	try {
		if(o instanceof cl) {
			if(cl == Array) {
				var $tmp = o.__enum__ == null;
				$s.pop();
				return $tmp;
			}
			$s.pop();
			return true;
		}
		if(js.Boot.__interfLoop(o.__class__,cl)) {
			$s.pop();
			return true;
		}
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		if(cl == null) {
			$s.pop();
			return false;
		}
	}
	switch(cl) {
	case Int:
		var $tmp = Math.ceil(o%2147483648.0) === o;
		$s.pop();
		return $tmp;
	case Float:
		var $tmp = typeof(o) == "number";
		$s.pop();
		return $tmp;
	case Bool:
		var $tmp = o === true || o === false;
		$s.pop();
		return $tmp;
	case String:
		var $tmp = typeof(o) == "string";
		$s.pop();
		return $tmp;
	case Dynamic:
		$s.pop();
		return true;
	default:
		if(o == null) {
			$s.pop();
			return false;
		}
		var $tmp = o.__enum__ == cl || cl == Class && o.__name__ != null || cl == Enum && o.__ename__ != null;
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
js.Boot.__init = function() {
	$s.push("js.Boot::__init");
	var $spos = $s.length;
	js.Lib.isIE = typeof document!='undefined' && document.all != null && typeof window!='undefined' && window.opera == null;
	js.Lib.isOpera = typeof window!='undefined' && window.opera != null;
	Array.prototype.copy = Array.prototype.slice;
	Array.prototype.insert = function(i,x) {
		$s.push("js.Boot::__init@205");
		var $spos = $s.length;
		this.splice(i,0,x);
		$s.pop();
	};
	Array.prototype.remove = Array.prototype.indexOf?function(obj) {
		$s.push("js.Boot::__init@208");
		var $spos = $s.length;
		var idx = this.indexOf(obj);
		if(idx == -1) {
			$s.pop();
			return false;
		}
		this.splice(idx,1);
		$s.pop();
		return true;
		$s.pop();
	}:function(obj) {
		$s.push("js.Boot::__init@213");
		var $spos = $s.length;
		var i = 0;
		var l = this.length;
		while(i < l) {
			if(this[i] == obj) {
				this.splice(i,1);
				$s.pop();
				return true;
			}
			i++;
		}
		$s.pop();
		return false;
		$s.pop();
	};
	Array.prototype.iterator = function() {
		$s.push("js.Boot::__init@225");
		var $spos = $s.length;
		var $tmp = { cur : 0, arr : this, hasNext : function() {
			$s.push("js.Boot::__init@225@229");
			var $spos = $s.length;
			var $tmp = this.cur < this.arr.length;
			$s.pop();
			return $tmp;
			$s.pop();
		}, next : function() {
			$s.push("js.Boot::__init@225@232");
			var $spos = $s.length;
			var $tmp = this.arr[this.cur++];
			$s.pop();
			return $tmp;
			$s.pop();
		}};
		$s.pop();
		return $tmp;
		$s.pop();
	};
	if(String.prototype.cca == null) String.prototype.cca = String.prototype.charCodeAt;
	String.prototype.charCodeAt = function(i) {
		$s.push("js.Boot::__init@239");
		var $spos = $s.length;
		var x = this.cca(i);
		if(x != x) {
			$s.pop();
			return null;
		}
		$s.pop();
		return x;
		$s.pop();
	};
	var oldsub = String.prototype.substr;
	String.prototype.substr = function(pos,len) {
		$s.push("js.Boot::__init@246");
		var $spos = $s.length;
		if(pos != null && pos != 0 && len != null && len < 0) {
			$s.pop();
			return "";
		}
		if(len == null) len = this.length;
		if(pos < 0) {
			pos = this.length + pos;
			if(pos < 0) pos = 0;
		} else if(len < 0) len = this.length + len - pos;
		var $tmp = oldsub.apply(this,[pos,len]);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	$closure = js.Boot.__closure;
	$s.pop();
}
js.Boot.prototype.__class__ = js.Boot;
haxe.Firebug = function() { }
haxe.Firebug.__name__ = ["haxe","Firebug"];
haxe.Firebug.detect = function() {
	$s.push("haxe.Firebug::detect");
	var $spos = $s.length;
	try {
		var $tmp = console != null && console.error != null;
		$s.pop();
		return $tmp;
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		$s.pop();
		return false;
	}
	$s.pop();
}
haxe.Firebug.redirectTraces = function() {
	$s.push("haxe.Firebug::redirectTraces");
	var $spos = $s.length;
	haxe.Log.trace = haxe.Firebug.trace;
	js.Lib.setErrorHandler(haxe.Firebug.onError);
	$s.pop();
}
haxe.Firebug.onError = function(err,stack) {
	$s.push("haxe.Firebug::onError");
	var $spos = $s.length;
	var buf = err + "\n";
	var _g = 0;
	while(_g < stack.length) {
		var s = stack[_g];
		++_g;
		buf += "Called from " + s + "\n";
	}
	haxe.Firebug.trace(buf,null);
	$s.pop();
	return true;
	$s.pop();
}
haxe.Firebug.trace = function(v,inf) {
	$s.push("haxe.Firebug::trace");
	var $spos = $s.length;
	var type = inf != null && inf.customParams != null?inf.customParams[0]:null;
	if(type != "warn" && type != "info" && type != "debug" && type != "error") type = inf == null?"error":"log";
	console[type]((inf == null?"":inf.fileName + ":" + inf.lineNumber + " : ") + Std.string(v));
	$s.pop();
}
haxe.Firebug.prototype.__class__ = haxe.Firebug;
org.intermedia.view.MenuCellTextStyle = function() { }
org.intermedia.view.MenuCellTextStyle.__name__ = ["org","intermedia","view","MenuCellTextStyle"];
org.intermedia.view.MenuCellTextStyle.setCellStyle = function(node) {
	$s.push("org.intermedia.view.MenuCellTextStyle::setCellStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.MenuCellTextStyle.setLeftCellStyle = function(node) {
	$s.push("org.intermedia.view.MenuCellTextStyle::setLeftCellStyle");
	var $spos = $s.length;
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.left = "0px";
	$s.pop();
}
org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle = function(node) {
	$s.push("org.intermedia.view.MenuCellTextStyle::setMiddleCellStyle");
	var $spos = $s.length;
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.marginLeft = "auto";
	node.style.marginRight = "auto";
	node.style.left = Std["int"]((js.Lib.window.innerWidth - node.offsetWidth) / 2) + "px";
	$s.pop();
}
org.intermedia.view.MenuCellTextStyle.setRightCellStyle = function(node) {
	$s.push("org.intermedia.view.MenuCellTextStyle::setRightCellStyle");
	var $spos = $s.length;
	org.intermedia.view.MenuCellTextStyle.setCellStyle(node);
	node.style.right = "0px";
	$s.pop();
}
org.intermedia.view.MenuCellTextStyle.setCellTextStyle = function(node) {
	$s.push("org.intermedia.view.MenuCellTextStyle::setCellTextStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.MenuCellTextStyle.prototype.__class__ = org.intermedia.view.MenuCellTextStyle;
EReg = function(r,opt) {
	if( r === $_ ) return;
	$s.push("EReg::new");
	var $spos = $s.length;
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
	$s.pop();
}
EReg.__name__ = ["EReg"];
EReg.prototype.r = null;
EReg.prototype.match = function(s) {
	$s.push("EReg::match");
	var $spos = $s.length;
	this.r.m = this.r.exec(s);
	this.r.s = s;
	this.r.l = RegExp.leftContext;
	this.r.r = RegExp.rightContext;
	var $tmp = this.r.m != null;
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.matched = function(n) {
	$s.push("EReg::matched");
	var $spos = $s.length;
	var $tmp = this.r.m != null && n >= 0 && n < this.r.m.length?this.r.m[n]:(function($this) {
		var $r;
		throw "EReg::matched";
		return $r;
	}(this));
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.matchedLeft = function() {
	$s.push("EReg::matchedLeft");
	var $spos = $s.length;
	if(this.r.m == null) throw "No string matched";
	if(this.r.l == null) {
		var $tmp = this.r.s.substr(0,this.r.m.index);
		$s.pop();
		return $tmp;
	}
	var $tmp = this.r.l;
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.matchedRight = function() {
	$s.push("EReg::matchedRight");
	var $spos = $s.length;
	if(this.r.m == null) throw "No string matched";
	if(this.r.r == null) {
		var sz = this.r.m.index + this.r.m[0].length;
		var $tmp = this.r.s.substr(sz,this.r.s.length - sz);
		$s.pop();
		return $tmp;
	}
	var $tmp = this.r.r;
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.matchedPos = function() {
	$s.push("EReg::matchedPos");
	var $spos = $s.length;
	if(this.r.m == null) throw "No string matched";
	var $tmp = { pos : this.r.m.index, len : this.r.m[0].length};
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.split = function(s) {
	$s.push("EReg::split");
	var $spos = $s.length;
	var d = "#__delim__#";
	var $tmp = s.replace(this.r,d).split(d);
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.replace = function(s,by) {
	$s.push("EReg::replace");
	var $spos = $s.length;
	var $tmp = s.replace(this.r,by);
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.customReplace = function(s,f) {
	$s.push("EReg::customReplace");
	var $spos = $s.length;
	var buf = new StringBuf();
	while(true) {
		if(!this.match(s)) break;
		buf.add(this.matchedLeft());
		buf.add(f(this));
		s = this.matchedRight();
	}
	buf.b[buf.b.length] = s == null?"null":s;
	var $tmp = buf.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
EReg.prototype.__class__ = EReg;
Xml = function(p) {
	$s.push("Xml::new");
	var $spos = $s.length;
	$s.pop();
}
Xml.__name__ = ["Xml"];
Xml.Element = null;
Xml.PCData = null;
Xml.CData = null;
Xml.Comment = null;
Xml.DocType = null;
Xml.Prolog = null;
Xml.Document = null;
Xml.parse = function(str) {
	$s.push("Xml::parse");
	var $spos = $s.length;
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
	$s.pop();
	return current;
	$s.pop();
}
Xml.createElement = function(name) {
	$s.push("Xml::createElement");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.Element;
	r._children = new Array();
	r._attributes = new Hash();
	r.setNodeName(name);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createPCData = function(data) {
	$s.push("Xml::createPCData");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.PCData;
	r.setNodeValue(data);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createCData = function(data) {
	$s.push("Xml::createCData");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.CData;
	r.setNodeValue(data);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createComment = function(data) {
	$s.push("Xml::createComment");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.Comment;
	r.setNodeValue(data);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createDocType = function(data) {
	$s.push("Xml::createDocType");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.DocType;
	r.setNodeValue(data);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createProlog = function(data) {
	$s.push("Xml::createProlog");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.Prolog;
	r.setNodeValue(data);
	$s.pop();
	return r;
	$s.pop();
}
Xml.createDocument = function() {
	$s.push("Xml::createDocument");
	var $spos = $s.length;
	var r = new Xml();
	r.nodeType = Xml.Document;
	r._children = new Array();
	$s.pop();
	return r;
	$s.pop();
}
Xml.prototype.nodeType = null;
Xml.prototype.nodeName = null;
Xml.prototype.nodeValue = null;
Xml.prototype.parent = null;
Xml.prototype._nodeName = null;
Xml.prototype._nodeValue = null;
Xml.prototype._attributes = null;
Xml.prototype._children = null;
Xml.prototype._parent = null;
Xml.prototype.getNodeName = function() {
	$s.push("Xml::getNodeName");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	var $tmp = this._nodeName;
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.setNodeName = function(n) {
	$s.push("Xml::setNodeName");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	var $tmp = this._nodeName = n;
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.getNodeValue = function() {
	$s.push("Xml::getNodeValue");
	var $spos = $s.length;
	if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
	var $tmp = this._nodeValue;
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.setNodeValue = function(v) {
	$s.push("Xml::setNodeValue");
	var $spos = $s.length;
	if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
	var $tmp = this._nodeValue = v;
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.getParent = function() {
	$s.push("Xml::getParent");
	var $spos = $s.length;
	var $tmp = this._parent;
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.get = function(att) {
	$s.push("Xml::get");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	var $tmp = this._attributes.get(att);
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.set = function(att,value) {
	$s.push("Xml::set");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	this._attributes.set(att,value);
	$s.pop();
}
Xml.prototype.remove = function(att) {
	$s.push("Xml::remove");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	this._attributes.remove(att);
	$s.pop();
}
Xml.prototype.exists = function(att) {
	$s.push("Xml::exists");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	var $tmp = this._attributes.exists(att);
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.attributes = function() {
	$s.push("Xml::attributes");
	var $spos = $s.length;
	if(this.nodeType != Xml.Element) throw "bad nodeType";
	var $tmp = this._attributes.keys();
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.iterator = function() {
	$s.push("Xml::iterator");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var $tmp = { cur : 0, x : this._children, hasNext : function() {
		$s.push("Xml::iterator@281");
		var $spos = $s.length;
		var $tmp = this.cur < this.x.length;
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("Xml::iterator@284");
		var $spos = $s.length;
		var $tmp = this.x[this.cur++];
		$s.pop();
		return $tmp;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.elements = function() {
	$s.push("Xml::elements");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var $tmp = { cur : 0, x : this._children, hasNext : function() {
		$s.push("Xml::elements@295");
		var $spos = $s.length;
		var k = this.cur;
		var l = this.x.length;
		while(k < l) {
			if(this.x[k].nodeType == Xml.Element) break;
			k += 1;
		}
		this.cur = k;
		var $tmp = k < l;
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("Xml::elements@306");
		var $spos = $s.length;
		var k = this.cur;
		var l = this.x.length;
		while(k < l) {
			var n = this.x[k];
			k += 1;
			if(n.nodeType == Xml.Element) {
				this.cur = k;
				$s.pop();
				return n;
			}
		}
		$s.pop();
		return null;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.elementsNamed = function(name) {
	$s.push("Xml::elementsNamed");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var $tmp = { cur : 0, x : this._children, hasNext : function() {
		$s.push("Xml::elementsNamed@327");
		var $spos = $s.length;
		var k = this.cur;
		var l = this.x.length;
		while(k < l) {
			var n = this.x[k];
			if(n.nodeType == Xml.Element && n._nodeName == name) break;
			k++;
		}
		this.cur = k;
		var $tmp = k < l;
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("Xml::elementsNamed@339");
		var $spos = $s.length;
		var k = this.cur;
		var l = this.x.length;
		while(k < l) {
			var n = this.x[k];
			k++;
			if(n.nodeType == Xml.Element && n._nodeName == name) {
				this.cur = k;
				$s.pop();
				return n;
			}
		}
		$s.pop();
		return null;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.firstChild = function() {
	$s.push("Xml::firstChild");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var $tmp = this._children[0];
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.firstElement = function() {
	$s.push("Xml::firstElement");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var cur = 0;
	var l = this._children.length;
	while(cur < l) {
		var n = this._children[cur];
		if(n.nodeType == Xml.Element) {
			$s.pop();
			return n;
		}
		cur++;
	}
	$s.pop();
	return null;
	$s.pop();
}
Xml.prototype.addChild = function(x) {
	$s.push("Xml::addChild");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	if(x._parent != null) x._parent._children.remove(x);
	x._parent = this;
	this._children.push(x);
	$s.pop();
}
Xml.prototype.removeChild = function(x) {
	$s.push("Xml::removeChild");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	var b = this._children.remove(x);
	if(b) x._parent = null;
	$s.pop();
	return b;
	$s.pop();
}
Xml.prototype.insertChild = function(x,pos) {
	$s.push("Xml::insertChild");
	var $spos = $s.length;
	if(this._children == null) throw "bad nodetype";
	if(x._parent != null) x._parent._children.remove(x);
	x._parent = this;
	this._children.insert(pos,x);
	$s.pop();
}
Xml.prototype.toString = function() {
	$s.push("Xml::toString");
	var $spos = $s.length;
	if(this.nodeType == Xml.PCData) {
		var $tmp = this._nodeValue;
		$s.pop();
		return $tmp;
	}
	if(this.nodeType == Xml.CData) {
		var $tmp = "<![CDATA[" + this._nodeValue + "]]>";
		$s.pop();
		return $tmp;
	}
	if(this.nodeType == Xml.Comment) {
		var $tmp = "<!--" + this._nodeValue + "-->";
		$s.pop();
		return $tmp;
	}
	if(this.nodeType == Xml.DocType) {
		var $tmp = "<!DOCTYPE " + this._nodeValue + ">";
		$s.pop();
		return $tmp;
	}
	if(this.nodeType == Xml.Prolog) {
		var $tmp = "<?" + this._nodeValue + "?>";
		$s.pop();
		return $tmp;
	}
	var s = new StringBuf();
	if(this.nodeType == Xml.Element) {
		s.b[s.b.length] = "<" == null?"null":"<";
		s.add(this._nodeName);
		var $it0 = this._attributes.keys();
		while( $it0.hasNext() ) {
			var k = $it0.next();
			s.b[s.b.length] = " " == null?"null":" ";
			s.b[s.b.length] = k == null?"null":k;
			s.b[s.b.length] = "=\"" == null?"null":"=\"";
			s.add(this._attributes.get(k));
			s.b[s.b.length] = "\"" == null?"null":"\"";
		}
		if(this._children.length == 0) {
			s.b[s.b.length] = "/>" == null?"null":"/>";
			var $tmp = s.b.join("");
			$s.pop();
			return $tmp;
		}
		s.b[s.b.length] = ">" == null?"null":">";
	}
	var $it1 = this.iterator();
	while( $it1.hasNext() ) {
		var x = $it1.next();
		s.add(x.toString());
	}
	if(this.nodeType == Xml.Element) {
		s.b[s.b.length] = "</" == null?"null":"</";
		s.add(this._nodeName);
		s.b[s.b.length] = ">" == null?"null":">";
	}
	var $tmp = s.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
Xml.prototype.__class__ = Xml;
haxe.Timer = function(time_ms) {
	if( time_ms === $_ ) return;
	$s.push("haxe.Timer::new");
	var $spos = $s.length;
	var arr = haxe_timers;
	this.id = arr.length;
	arr[this.id] = this;
	this.timerId = window.setInterval("haxe_timers[" + this.id + "].run();",time_ms);
	$s.pop();
}
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.delay = function(f,time_ms) {
	$s.push("haxe.Timer::delay");
	var $spos = $s.length;
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		$s.push("haxe.Timer::delay@79");
		var $spos = $s.length;
		t.stop();
		f();
		$s.pop();
	};
	$s.pop();
	return t;
	$s.pop();
}
haxe.Timer.measure = function(f,pos) {
	$s.push("haxe.Timer::measure");
	var $spos = $s.length;
	var t0 = haxe.Timer.stamp();
	var r = f();
	haxe.Log.trace(haxe.Timer.stamp() - t0 + "s",pos);
	$s.pop();
	return r;
	$s.pop();
}
haxe.Timer.stamp = function() {
	$s.push("haxe.Timer::stamp");
	var $spos = $s.length;
	var $tmp = Date.now().getTime() / 1000;
	$s.pop();
	return $tmp;
	$s.pop();
}
haxe.Timer.prototype.id = null;
haxe.Timer.prototype.timerId = null;
haxe.Timer.prototype.stop = function() {
	$s.push("haxe.Timer::stop");
	var $spos = $s.length;
	if(this.id == null) {
		$s.pop();
		return;
	}
	window.clearInterval(this.timerId);
	var arr = haxe_timers;
	arr[this.id] = null;
	if(this.id > 100 && this.id == arr.length - 1) {
		var p = this.id - 1;
		while(p >= 0 && arr[p] == null) p--;
		arr = arr.slice(0,p + 1);
	}
	this.id = null;
	$s.pop();
}
haxe.Timer.prototype.run = function() {
	$s.push("haxe.Timer::run");
	var $spos = $s.length;
	$s.pop();
}
haxe.Timer.prototype.__class__ = haxe.Timer;
org.intermedia.view.ViewManager = function(applicationModel,applicationController) {
	if( applicationModel === $_ ) return;
	$s.push("org.intermedia.view.ViewManager::new");
	var $spos = $s.length;
	this._applicationModel = applicationModel;
	this._applicationController = applicationController;
	this._body = js.Lib.document.body;
	org.intermedia.view.ViewManagerStyle.setBodyStyle(this._body);
	this._header = new org.intermedia.view.HeaderView();
	this._header.setData("Market");
	this._header.onBackButtonClick = $closure(this,"onHeaderBackButtonPressed");
	this._body.appendChild(this._header.node);
	this._menu = new org.intermedia.view.ScrollableMenu();
	this._menu.displayListBottomLoader = false;
	this._body.appendChild(this._menu.node);
	this._menu.setData([{ id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"},{ id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"},{ id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}]);
	org.intermedia.view.MenuCellTextStyle.setMiddleCellStyle(js.Lib.document.getElementById("menu_item1"));
	this._swippableListView = new org.intermedia.view.SwippableListView();
	this._currentView = this._swippableListView;
	this._body.appendChild(this._swippableListView.node);
	this.init();
	$s.pop();
}
org.intermedia.view.ViewManager.__name__ = ["org","intermedia","view","ViewManager"];
org.intermedia.view.ViewManager.prototype._body = null;
org.intermedia.view.ViewManager.prototype._header = null;
org.intermedia.view.ViewManager.prototype._menu = null;
org.intermedia.view.ViewManager.prototype._swippableListView = null;
org.intermedia.view.ViewManager.prototype._detailView = null;
org.intermedia.view.ViewManager.prototype._applicationModel = null;
org.intermedia.view.ViewManager.prototype._applicationController = null;
org.intermedia.view.ViewManager.prototype._currentView = null;
org.intermedia.view.ViewManager.prototype.init = function() {
	$s.push("org.intermedia.view.ViewManager::init");
	var $spos = $s.length;
	this._applicationModel.onModelStartsLoading = $closure(this,"onStartLoading");
	this._applicationModel.onModelDataLoadError = $closure(this,"onLoadingError");
	this._applicationModel.onModelCellDataLoaded = $closure(this,"onCellDataLoaded");
	this._applicationModel.onModelDetailDataLoaded = $closure(this,"onDetailDataLoaded");
	this._menu.onListItemSelected = $closure(this,"onMenuItemSelectedCallback");
	this._swippableListView.onListItemSelected = $closure(this,"onListItemSelectedCallback");
	this._swippableListView.onDataRequest = $closure(this._applicationController,"loadCellData");
	this._swippableListView.onHorizontalMove = $closure(this._menu,"horizontalMove");
	this._swippableListView.onHorizontalUp = $closure(this._menu,"horizontalRelease");
	this._applicationController.loadCellData({ id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url);
	this._applicationController.loadCellData({ id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url);
	this._applicationController.loadCellData({ id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onMenuItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.ViewManager::onMenuItemSelectedCallback");
	var $spos = $s.length;
	this._swippableListView.setIndex(cellData.id);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onListItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.ViewManager::onListItemSelectedCallback");
	var $spos = $s.length;
	this._body.removeChild(this._swippableListView.node);
	this._body.removeChild(this._menu.node);
	this._detailView = new org.intermedia.view.DetailView();
	this._body.appendChild(this._detailView.node);
	this._detailView.addTouchEvents();
	this._currentView = this._detailView;
	this.onDetailDataLoaded(cellData);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onCellDataLoaded = function(listData) {
	$s.push("org.intermedia.view.ViewManager::onCellDataLoaded");
	var $spos = $s.length;
	if(listData.cells.length == 0) this._swippableListView.displayListBottomLoader = false;
	this._swippableListView.setData(listData);
	this.updateZIndexes();
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onDetailDataLoaded = function(detailData) {
	$s.push("org.intermedia.view.ViewManager::onDetailDataLoaded");
	var $spos = $s.length;
	this._detailView.setData(detailData);
	this._header.setData("Infos");
	this._header.setDisplayBackButton(true);
	this.setZIndexToMax(this._header);
	this._detailView.setDisplayLoading(false);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onStartLoading = function() {
	$s.push("org.intermedia.view.ViewManager::onStartLoading");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onLoadingError = function(error) {
	$s.push("org.intermedia.view.ViewManager::onLoadingError");
	var $spos = $s.length;
	haxe.Firebug.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 254, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.onHeaderBackButtonPressed = function() {
	$s.push("org.intermedia.view.ViewManager::onHeaderBackButtonPressed");
	var $spos = $s.length;
	this._header.setData("Market");
	this._header.setDisplayBackButton(false);
	this._body.removeChild(this._detailView.node);
	this._body.appendChild(this._menu.node);
	this._body.appendChild(this._swippableListView.node);
	this._swippableListView.scrollToCurrentList();
	this.updateZIndexes();
	this._currentView = this._swippableListView;
	this._swippableListView.addTouchEvents();
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.updateZIndexes = function() {
	$s.push("org.intermedia.view.ViewManager::updateZIndexes");
	var $spos = $s.length;
	this.setZIndexToMax(this._menu);
	this.setZIndexToMax(this._header);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.setZIndexToMax = function(view) {
	$s.push("org.intermedia.view.ViewManager::setZIndexToMax");
	var $spos = $s.length;
	this._body.removeChild(view.node);
	this._body.appendChild(view.node);
	$s.pop();
}
org.intermedia.view.ViewManager.prototype.__class__ = org.intermedia.view.ViewManager;
org.intermedia.view.SwippableListViewStyle = function() { }
org.intermedia.view.SwippableListViewStyle.__name__ = ["org","intermedia","view","SwippableListViewStyle"];
org.intermedia.view.SwippableListViewStyle.setSwippableListStyle = function(node) {
	$s.push("org.intermedia.view.SwippableListViewStyle::setSwippableListStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.SwippableListViewStyle.setListsContainerStyle = function(node) {
	$s.push("org.intermedia.view.SwippableListViewStyle::setListsContainerStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.SwippableListViewStyle.prototype.__class__ = org.intermedia.view.SwippableListViewStyle;
org.intermedia.view.CroppedImage = function(imageUrl,maskSize) {
	if( imageUrl === $_ ) return;
	$s.push("org.intermedia.view.CroppedImage::new");
	var $spos = $s.length;
	this.node = js.Lib.document.createElement("div");
	this.node.style.width = Std.string(maskSize.width) + "px";
	this.node.style.height = Std.string(maskSize.height) + "px";
	this.node.style.overflowX = "hidden";
	this.node.style.overflowY = "hidden";
	this.node.style.display = "inline-block";
	this._image = js.Lib.document.createElement("img");
	this._maskSize = maskSize;
	this.loadThumb(imageUrl);
	$s.pop();
}
org.intermedia.view.CroppedImage.__name__ = ["org","intermedia","view","CroppedImage"];
org.intermedia.view.CroppedImage.prototype.node = null;
org.intermedia.view.CroppedImage.prototype._image = null;
org.intermedia.view.CroppedImage.prototype._maskSize = null;
org.intermedia.view.CroppedImage.prototype.loadThumb = function(imageUrl) {
	$s.push("org.intermedia.view.CroppedImage::loadThumb");
	var $spos = $s.length;
	this._image.onload = $closure(this,"onImageLoadSuccess");
	this._image.src = imageUrl;
	$s.pop();
}
org.intermedia.view.CroppedImage.prototype.onImageLoadSuccess = function(event) {
	$s.push("org.intermedia.view.CroppedImage::onImageLoadSuccess");
	var $spos = $s.length;
	this._image.style.opacity = 0;
	this.node.appendChild(org.intermedia.view.ImageUtils.cropImage(this._image,this._maskSize));
	haxe.Timer.delay($closure(this,"fadeIn"),Std.random(1000));
	$s.pop();
}
org.intermedia.view.CroppedImage.prototype.fadeIn = function() {
	$s.push("org.intermedia.view.CroppedImage::fadeIn");
	var $spos = $s.length;
	var tween = new feffects.Tween(0,1,400);
	tween.setTweenHandlers($closure(this,"tweenOpacity"),$closure(this,"tweenEnd"));
	tween.start();
	$s.pop();
}
org.intermedia.view.CroppedImage.prototype.tweenOpacity = function(e) {
	$s.push("org.intermedia.view.CroppedImage::tweenOpacity");
	var $spos = $s.length;
	this._image.style.opacity = e;
	$s.pop();
}
org.intermedia.view.CroppedImage.prototype.tweenEnd = function(e) {
	$s.push("org.intermedia.view.CroppedImage::tweenEnd");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.CroppedImage.prototype.__class__ = org.intermedia.view.CroppedImage;
StringBuf = function(p) {
	if( p === $_ ) return;
	$s.push("StringBuf::new");
	var $spos = $s.length;
	this.b = new Array();
	$s.pop();
}
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype.add = function(x) {
	$s.push("StringBuf::add");
	var $spos = $s.length;
	this.b[this.b.length] = x == null?"null":x;
	$s.pop();
}
StringBuf.prototype.addSub = function(s,pos,len) {
	$s.push("StringBuf::addSub");
	var $spos = $s.length;
	this.b[this.b.length] = s.substr(pos,len);
	$s.pop();
}
StringBuf.prototype.addChar = function(c) {
	$s.push("StringBuf::addChar");
	var $spos = $s.length;
	this.b[this.b.length] = String.fromCharCode(c);
	$s.pop();
}
StringBuf.prototype.toString = function() {
	$s.push("StringBuf::toString");
	var $spos = $s.length;
	var $tmp = this.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
StringBuf.prototype.b = null;
StringBuf.prototype.__class__ = StringBuf;
org.intermedia.view.ThumbTextList1 = function(cellPerLine) {
	if( cellPerLine === $_ ) return;
	$s.push("org.intermedia.view.ThumbTextList1::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	this._cellsPerLine = cellPerLine;
	org.intermedia.view.ListViewBase.call(this);
	$s.pop();
}
org.intermedia.view.ThumbTextList1.__name__ = ["org","intermedia","view","ThumbTextList1"];
org.intermedia.view.ThumbTextList1.__super__ = org.intermedia.view.ListViewBase;
for(var k in org.intermedia.view.ListViewBase.prototype ) org.intermedia.view.ThumbTextList1.prototype[k] = org.intermedia.view.ListViewBase.prototype[k];
org.intermedia.view.ThumbTextList1.prototype._cellsPerLine = null;
org.intermedia.view.ThumbTextList1.prototype.createCell = function() {
	$s.push("org.intermedia.view.ThumbTextList1::createCell");
	var $spos = $s.length;
	var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine);
	$s.pop();
	return cell;
	$s.pop();
}
org.intermedia.view.ThumbTextList1.prototype.__class__ = org.intermedia.view.ThumbTextList1;
org.intermedia.view.ThumbTextList1Bis = function(cellPerLine) {
	if( cellPerLine === $_ ) return;
	$s.push("org.intermedia.view.ThumbTextList1Bis::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ThumbTextList1.call(this,cellPerLine);
	$s.pop();
}
org.intermedia.view.ThumbTextList1Bis.__name__ = ["org","intermedia","view","ThumbTextList1Bis"];
org.intermedia.view.ThumbTextList1Bis.__super__ = org.intermedia.view.ThumbTextList1;
for(var k in org.intermedia.view.ThumbTextList1.prototype ) org.intermedia.view.ThumbTextList1Bis.prototype[k] = org.intermedia.view.ThumbTextList1.prototype[k];
org.intermedia.view.ThumbTextList1Bis.prototype._homePageData = null;
org.intermedia.view.ThumbTextList1Bis.prototype.buildHomePage = function(homePageData) {
	$s.push("org.intermedia.view.ThumbTextList1Bis::buildHomePage");
	var $spos = $s.length;
	var homePage = new org.intermedia.view.HomePage(homePageData);
	homePage.onListItemSelected = $closure(this,"onListItemSelectedCallback");
	this.node.appendChild(homePage.node);
	$s.pop();
}
org.intermedia.view.ThumbTextList1Bis.prototype.__class__ = org.intermedia.view.ThumbTextList1Bis;
org.intermedia.view.LoadingView = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.LoadingView::new");
	var $spos = $s.length;
	this.node = js.Lib.document.createElement("div");
	org.intermedia.view.LoadingViewStyle.setLoadingStyle(this.node);
	this.loadThumb();
	$s.pop();
}
org.intermedia.view.LoadingView.__name__ = ["org","intermedia","view","LoadingView"];
org.intermedia.view.LoadingView.prototype.node = null;
org.intermedia.view.LoadingView.prototype._viewStyle = null;
org.intermedia.view.LoadingView.prototype.loadThumb = function() {
	$s.push("org.intermedia.view.LoadingView::loadThumb");
	var $spos = $s.length;
	var image = js.Lib.document.createElement("img");
	org.intermedia.view.LoadingViewStyle.setThumbnailStyle(image);
	this.node.appendChild(image);
	image.src = "assets/loading.gif";
	$s.pop();
}
org.intermedia.view.LoadingView.prototype.__class__ = org.intermedia.view.LoadingView;
org.intermedia.view.HomePage = function(initData) {
	if( initData === $_ ) return;
	$s.push("org.intermedia.view.HomePage::new");
	var $spos = $s.length;
	this._data = initData;
	org.intermedia.view.ViewBase.call(this);
	$s.pop();
}
org.intermedia.view.HomePage.__name__ = ["org","intermedia","view","HomePage"];
org.intermedia.view.HomePage.__super__ = org.intermedia.view.ViewBase;
for(var k in org.intermedia.view.ViewBase.prototype ) org.intermedia.view.HomePage.prototype[k] = org.intermedia.view.ViewBase.prototype[k];
org.intermedia.view.HomePage.prototype.onListItemSelected = null;
org.intermedia.view.HomePage.prototype.buildView = function() {
	$s.push("org.intermedia.view.HomePage::buildView");
	var $spos = $s.length;
	var me = this;
	var cell0Style = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : org.intermedia.view.CellThumbStyle.setThumbnailStyle, textBlock : null, title : null, author : null, line : null};
	var cell0 = new org.intermedia.view.CellThumb(1,cell0Style);
	cell0.setData(this._data[0]);
	cell0.node.onmouseup = function(mouseEventData) {
		$s.push("org.intermedia.view.HomePage::buildView@48");
		var $spos = $s.length;
		me.onListItemSelectedCallback(cell0.getData());
		$s.pop();
	};
	this.node.appendChild(cell0.node);
	var cell1 = new org.intermedia.view.CellThumb(2,cell0Style);
	cell1.setData(this._data[1]);
	cell1.node.onmouseup = function(mouseEventData) {
		$s.push("org.intermedia.view.HomePage::buildView@54");
		var $spos = $s.length;
		me.onListItemSelectedCallback(cell1.getData());
		$s.pop();
	};
	this.node.appendChild(cell1.node);
	var cell2 = new org.intermedia.view.CellThumb(2,cell0Style);
	cell2.setData(this._data[2]);
	cell2.node.onmouseup = function(mouseEventData) {
		$s.push("org.intermedia.view.HomePage::buildView@60");
		var $spos = $s.length;
		me.onListItemSelectedCallback(cell2.getData());
		$s.pop();
	};
	this.node.appendChild(cell2.node);
	var cell3 = new org.intermedia.view.CellThumb(2,cell0Style);
	cell3.setData(this._data[3]);
	cell3.node.onmouseup = function(mouseEventData) {
		$s.push("org.intermedia.view.HomePage::buildView@68");
		var $spos = $s.length;
		me.onListItemSelectedCallback(cell3.getData());
		$s.pop();
	};
	this.node.appendChild(cell3.node);
	var cell4 = new org.intermedia.view.CellThumb(2,cell0Style);
	cell4.setData(this._data[4]);
	cell4.node.onmouseup = function(mouseEventData) {
		$s.push("org.intermedia.view.HomePage::buildView@75");
		var $spos = $s.length;
		me.onListItemSelectedCallback(cell4.getData());
		$s.pop();
	};
	this.node.appendChild(cell4.node);
	$s.pop();
}
org.intermedia.view.HomePage.prototype.loadThumb = function(url) {
	$s.push("org.intermedia.view.HomePage::loadThumb");
	var $spos = $s.length;
	var image = js.Lib.document.createElement("img");
	image.style.verticalAlign = "middle";
	this.node.appendChild(image);
	image.src = url;
	$s.pop();
	return image;
	$s.pop();
}
org.intermedia.view.HomePage.prototype.onListItemSelectedCallback = function(cellData) {
	$s.push("org.intermedia.view.HomePage::onListItemSelectedCallback");
	var $spos = $s.length;
	if(this.onListItemSelected != null) this.onListItemSelected(cellData);
	$s.pop();
}
org.intermedia.view.HomePage.prototype.__class__ = org.intermedia.view.HomePage;
org.intermedia.view.SwippableListView = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.SwippableListView::new");
	var $spos = $s.length;
	org.intermedia.view.ListViewBase.call(this);
	this.setDisplayLoading(true);
	this._offset = { x : 0, y : 0};
	this._offsetStart = { x : 0, y : 0};
	this._initialPosition = { x : 0, y : 0};
	this._direction = org.intermedia.view.Direction.notYetSet;
	this._viewportWidth = js.Lib.window.innerWidth;
	this._viewportHeight = js.Lib.window.innerHeight;
	js.Lib.window.onresize = $closure(this,"onResizeCallback");
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
		listView.onDataRequest = $closure(this,"onDataRequestCallback");
		listView.onListItemSelected = $closure(this,"onListItemSelectedCallback");
		this._listsContainer.appendChild(listView.node);
	}
	this._index = 1;
	this._currentListView = this._listViews[this._index];
	this._currentListView.onListItemSelected = $closure(this,"onListItemSelectedCallback");
	this._moveHandler = new org.intermedia.view.Scroll2D(org.intermedia.view.ScrollType.both);
	this._moveHandler.onHorizontalScroll = $closure(this,"onHorizontalMoveCallback");
	this._moveHandler.onVerticalScroll = $closure(this,"onVerticalMove");
	this._moveHandler.onHorizontalUp = $closure(this,"onHorizontalUpCallback");
	this.addTouchEvents();
	$s.pop();
}
org.intermedia.view.SwippableListView.__name__ = ["org","intermedia","view","SwippableListView"];
org.intermedia.view.SwippableListView.__super__ = org.intermedia.view.ListViewBase;
for(var k in org.intermedia.view.ListViewBase.prototype ) org.intermedia.view.SwippableListView.prototype[k] = org.intermedia.view.ListViewBase.prototype[k];
org.intermedia.view.SwippableListView.prototype._listsContainer = null;
org.intermedia.view.SwippableListView.prototype._listViews = null;
org.intermedia.view.SwippableListView.prototype.list0 = null;
org.intermedia.view.SwippableListView.prototype.list1 = null;
org.intermedia.view.SwippableListView.prototype.list2 = null;
org.intermedia.view.SwippableListView.prototype._list1Data = null;
org.intermedia.view.SwippableListView.prototype._currentListView = null;
org.intermedia.view.SwippableListView.prototype._index = null;
org.intermedia.view.SwippableListView.prototype.index = null;
org.intermedia.view.SwippableListView.prototype._offset = null;
org.intermedia.view.SwippableListView.prototype._offsetStart = null;
org.intermedia.view.SwippableListView.prototype._initialPosition = null;
org.intermedia.view.SwippableListView.prototype._direction = null;
org.intermedia.view.SwippableListView.prototype._homePageData = null;
org.intermedia.view.SwippableListView.prototype._homePageDataSet = null;
org.intermedia.view.SwippableListView.prototype._viewportWidth = null;
org.intermedia.view.SwippableListView.prototype._viewportHeight = null;
org.intermedia.view.SwippableListView.prototype._moveHandler = null;
org.intermedia.view.SwippableListView.prototype.onHorizontalMove = null;
org.intermedia.view.SwippableListView.prototype.onHorizontalUp = null;
org.intermedia.view.SwippableListView.prototype.positionLists = function() {
	$s.push("org.intermedia.view.SwippableListView::positionLists");
	var $spos = $s.length;
	this.list1.node.style.left = Std.string(this._viewportWidth) + "px";
	this.list2.node.style.left = Std.string(2 * this._viewportWidth) + "px";
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.setData = function(v) {
	$s.push("org.intermedia.view.SwippableListView::setData");
	var $spos = $s.length;
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
	var $tmp = this._data;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.getIndex = function() {
	$s.push("org.intermedia.view.SwippableListView::getIndex");
	var $spos = $s.length;
	var $tmp = this._index;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.setIndex = function(v) {
	$s.push("org.intermedia.view.SwippableListView::setIndex");
	var $spos = $s.length;
	this._currentListView.onListItemSelected = null;
	this._index = v;
	this._currentListView = this._listViews[v];
	this._currentListView.onListItemSelected = $closure(this,"onListItemSelectedCallback");
	this._moveHandler.horizontalReleaseTween(this.node.scrollLeft,Std.parseInt(this._currentListView.node.style.left));
	$s.pop();
	return v;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.scrollToCurrentList = function() {
	$s.push("org.intermedia.view.SwippableListView::scrollToCurrentList");
	var $spos = $s.length;
	this.node.scrollLeft = Std.parseInt(this._currentListView.node.style.left.substr(0,-2));
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.onResizeCallback = function(event) {
	$s.push("org.intermedia.view.SwippableListView::onResizeCallback");
	var $spos = $s.length;
	this._viewportWidth = js.Lib.window.innerWidth;
	this._viewportHeight = js.Lib.window.innerHeight;
	this.positionLists();
	this.scrollToCurrentList();
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.onHorizontalMoveCallback = function(XScroll,XOffset) {
	$s.push("org.intermedia.view.SwippableListView::onHorizontalMoveCallback");
	var $spos = $s.length;
	this.node.scrollLeft = XScroll;
	var horizontalRatio = this.computeHorizontalRatio(XOffset);
	if(this.onHorizontalMove != null && horizontalRatio != 0) this.onHorizontalMove(horizontalRatio);
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.onVerticalMove = function(y) {
	$s.push("org.intermedia.view.SwippableListView::onVerticalMove");
	var $spos = $s.length;
	this._currentListView.node.scrollTop = y;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.onHorizontalUpCallback = function(event,XOffset) {
	$s.push("org.intermedia.view.SwippableListView::onHorizontalUpCallback");
	var $spos = $s.length;
	event.preventDefault();
	if(XOffset < -this._viewportWidth / 2) {
		if(this.getIndex() < this._listViews.length - 1) {
			var _g = this, _g1 = _g.getIndex();
			_g.setIndex(_g1 + 1);
			_g1;
		}
	} else if(XOffset > this._viewportWidth / 2) {
		if(this.getIndex() > 0) {
			var _g = this, _g1 = _g.getIndex();
			_g.setIndex(_g1 - 1);
			_g1;
		}
	} else this.setIndex(this.getIndex());
	var horizontalRatio = this.computeHorizontalRatio(XOffset);
	if(this.onHorizontalUp != null) this.onHorizontalUp(this._index);
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.onScrollCallback = function(event) {
	$s.push("org.intermedia.view.SwippableListView::onScrollCallback");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.addTouchEvents = function() {
	$s.push("org.intermedia.view.SwippableListView::addTouchEvents");
	var $spos = $s.length;
	this.node.addEventListener("touchstart",$closure(this,"touchStart"),false);
	this.node.addEventListener("touchmove",$closure(this._moveHandler,"touchHandler"),false);
	this.node.addEventListener("touchend",$closure(this._moveHandler,"touchHandler"),false);
	this.node.addEventListener("touchcancel",$closure(this._moveHandler,"touchHandler"),false);
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.touchStart = function(event) {
	$s.push("org.intermedia.view.SwippableListView::touchStart");
	var $spos = $s.length;
	this._moveHandler.initialScrollPosition = { x : this.node.scrollLeft, y : this._currentListView.node.scrollTop};
	this._moveHandler.touchHandler(event);
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.computeHorizontalRatio = function(XOffset) {
	$s.push("org.intermedia.view.SwippableListView::computeHorizontalRatio");
	var $spos = $s.length;
	var ratio = 0;
	if(this._viewportWidth != 0) ratio = XOffset / this._viewportWidth;
	$s.pop();
	return ratio;
	$s.pop();
}
org.intermedia.view.SwippableListView.prototype.__class__ = org.intermedia.view.SwippableListView;
org.intermedia.model.CellDetailsRss = function() { }
org.intermedia.model.CellDetailsRss.__name__ = ["org","intermedia","model","CellDetailsRss"];
org.intermedia.model.CellDetailsRss.rss2CellDetail = function(rss,cellData) {
	$s.push("org.intermedia.model.CellDetailsRss::rss2CellDetail");
	var $spos = $s.length;
	var cell = { id : cellData.id, title : cellData.title, author : cellData.author, thumbUrl : cellData.thumbUrl, category : cellData.category, description : ""};
	var channelNode = rss.firstElement().firstElement();
	if(channelNode == null) {
		$s.pop();
		return cell;
	}
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
			$s.pop();
			return cell;
		}
	}
	$s.pop();
	return cell;
	$s.pop();
}
org.intermedia.model.CellDetailsRss.prototype.__class__ = org.intermedia.model.CellDetailsRss;
haxe.Log = function() { }
haxe.Log.__name__ = ["haxe","Log"];
haxe.Log.trace = function(v,infos) {
	$s.push("haxe.Log::trace");
	var $spos = $s.length;
	js.Boot.__trace(v,infos);
	$s.pop();
}
haxe.Log.clear = function() {
	$s.push("haxe.Log::clear");
	var $spos = $s.length;
	js.Boot.__clear_trace();
	$s.pop();
}
haxe.Log.prototype.__class__ = haxe.Log;
feffects.easing.Quart = function() { }
feffects.easing.Quart.__name__ = ["feffects","easing","Quart"];
feffects.easing.Quart.easeIn = function(t,b,c,d) {
	$s.push("feffects.easing.Quart::easeIn");
	var $spos = $s.length;
	var $tmp = c * (t /= d) * t * t * t + b;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.easing.Quart.easeOut = function(t,b,c,d) {
	$s.push("feffects.easing.Quart::easeOut");
	var $spos = $s.length;
	var $tmp = -c * ((t = t / d - 1) * t * t * t - 1) + b;
	$s.pop();
	return $tmp;
	$s.pop();
}
feffects.easing.Quart.easeInOut = function(t,b,c,d) {
	$s.push("feffects.easing.Quart::easeInOut");
	var $spos = $s.length;
	if((t /= d * 0.5) < 1) {
		var $tmp = c * 0.5 * t * t * t * t + b;
		$s.pop();
		return $tmp;
	} else {
		var $tmp = -c * 0.5 * ((t -= 2) * t * t * t - 2) + b;
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
feffects.easing.Quart.prototype.__class__ = feffects.easing.Quart;
feffects.easing.Quart.__interfaces__ = [haxe.Public];
Hash = function(p) {
	if( p === $_ ) return;
	$s.push("Hash::new");
	var $spos = $s.length;
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
	$s.pop();
}
Hash.__name__ = ["Hash"];
Hash.prototype.h = null;
Hash.prototype.set = function(key,value) {
	$s.push("Hash::set");
	var $spos = $s.length;
	this.h["$" + key] = value;
	$s.pop();
}
Hash.prototype.get = function(key) {
	$s.push("Hash::get");
	var $spos = $s.length;
	var $tmp = this.h["$" + key];
	$s.pop();
	return $tmp;
	$s.pop();
}
Hash.prototype.exists = function(key) {
	$s.push("Hash::exists");
	var $spos = $s.length;
	try {
		key = "$" + key;
		var $tmp = this.hasOwnProperty.call(this.h,key);
		$s.pop();
		return $tmp;
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		for(var i in this.h) if( i == key ) return true;
		$s.pop();
		return false;
	}
	$s.pop();
}
Hash.prototype.remove = function(key) {
	$s.push("Hash::remove");
	var $spos = $s.length;
	if(!this.exists(key)) {
		$s.pop();
		return false;
	}
	delete(this.h["$" + key]);
	$s.pop();
	return true;
	$s.pop();
}
Hash.prototype.keys = function() {
	$s.push("Hash::keys");
	var $spos = $s.length;
	var a = new Array();
	for(var i in this.h) a.push(i.substr(1));
	var $tmp = a.iterator();
	$s.pop();
	return $tmp;
	$s.pop();
}
Hash.prototype.iterator = function() {
	$s.push("Hash::iterator");
	var $spos = $s.length;
	var $tmp = { ref : this.h, it : this.keys(), hasNext : function() {
		$s.push("Hash::iterator@75");
		var $spos = $s.length;
		var $tmp = this.it.hasNext();
		$s.pop();
		return $tmp;
		$s.pop();
	}, next : function() {
		$s.push("Hash::iterator@76");
		var $spos = $s.length;
		var i = this.it.next();
		var $tmp = this.ref["$" + i];
		$s.pop();
		return $tmp;
		$s.pop();
	}};
	$s.pop();
	return $tmp;
	$s.pop();
}
Hash.prototype.toString = function() {
	$s.push("Hash::toString");
	var $spos = $s.length;
	var s = new StringBuf();
	s.b[s.b.length] = "{" == null?"null":"{";
	var it = this.keys();
	while( it.hasNext() ) {
		var i = it.next();
		s.b[s.b.length] = i == null?"null":i;
		s.b[s.b.length] = " => " == null?"null":" => ";
		s.add(Std.string(this.get(i)));
		if(it.hasNext()) s.b[s.b.length] = ", " == null?"null":", ";
	}
	s.b[s.b.length] = "}" == null?"null":"}";
	var $tmp = s.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
Hash.prototype.__class__ = Hash;
org.intermedia.view.ViewManagerStyle = function() { }
org.intermedia.view.ViewManagerStyle.__name__ = ["org","intermedia","view","ViewManagerStyle"];
org.intermedia.view.ViewManagerStyle.setBodyStyle = function(node) {
	$s.push("org.intermedia.view.ViewManagerStyle::setBodyStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.ViewManagerStyle.prototype.__class__ = org.intermedia.view.ViewManagerStyle;
Std = function() { }
Std.__name__ = ["Std"];
Std["is"] = function(v,t) {
	$s.push("Std::is");
	var $spos = $s.length;
	var $tmp = js.Boot.__instanceof(v,t);
	$s.pop();
	return $tmp;
	$s.pop();
}
Std.string = function(s) {
	$s.push("Std::string");
	var $spos = $s.length;
	var $tmp = js.Boot.__string_rec(s,"");
	$s.pop();
	return $tmp;
	$s.pop();
}
Std["int"] = function(x) {
	$s.push("Std::int");
	var $spos = $s.length;
	if(x < 0) {
		var $tmp = Math.ceil(x);
		$s.pop();
		return $tmp;
	}
	var $tmp = Math.floor(x);
	$s.pop();
	return $tmp;
	$s.pop();
}
Std.parseInt = function(x) {
	$s.push("Std::parseInt");
	var $spos = $s.length;
	var v = parseInt(x,10);
	if(v == 0 && x.charCodeAt(1) == 120) v = parseInt(x);
	if(isNaN(v)) {
		$s.pop();
		return null;
	}
	var $tmp = v;
	$s.pop();
	return $tmp;
	$s.pop();
}
Std.parseFloat = function(x) {
	$s.push("Std::parseFloat");
	var $spos = $s.length;
	var $tmp = parseFloat(x);
	$s.pop();
	return $tmp;
	$s.pop();
}
Std.random = function(x) {
	$s.push("Std::random");
	var $spos = $s.length;
	var $tmp = Math.floor(Math.random() * x);
	$s.pop();
	return $tmp;
	$s.pop();
}
Std.prototype.__class__ = Std;
org.intermedia.model.DataLoader = function(online) {
	if( online === $_ ) return;
	$s.push("org.intermedia.model.DataLoader::new");
	var $spos = $s.length;
	if(online == null) online = true;
	this._pageIndex = 1;
	this._pageIndexHash = new Hash();
	this._online = online;
	$s.pop();
}
org.intermedia.model.DataLoader.__name__ = ["org","intermedia","model","DataLoader"];
org.intermedia.model.DataLoader.prototype.onCellDataLoaded = null;
org.intermedia.model.DataLoader.prototype.onCellDetailLoaded = null;
org.intermedia.model.DataLoader.prototype.onLoadingError = null;
org.intermedia.model.DataLoader.prototype._online = null;
org.intermedia.model.DataLoader.prototype._itemsToLoad = null;
org.intermedia.model.DataLoader.prototype._pageIndex = null;
org.intermedia.model.DataLoader.prototype._pageIndexHash = null;
org.intermedia.model.DataLoader.prototype.loadCellData = function(feed,itemsPerPage,successCallback,errorCallback) {
	$s.push("org.intermedia.model.DataLoader::loadCellData");
	var $spos = $s.length;
	this.onCellDataLoaded = successCallback;
	this.onLoadingError = errorCallback;
	var fullUrl = "";
	if(this._online) {
		var pageIndex = 1;
		if(this._pageIndexHash.exists(feed)) pageIndex = this._pageIndexHash.get(feed) + 1;
		this._pageIndexHash.set(feed,pageIndex);
		fullUrl = feed + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex;
	} else if(feed == { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"}.url) fullUrl = "data/feed1.rss"; else if(feed == { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"}.url) fullUrl = "data/feed2.rss"; else if(feed == { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"}.url) fullUrl = "data/feed3.rss";
	var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,$closure(this,"onCellsXmlLoaded"),this.onLoadingError,feed);
	$s.pop();
}
org.intermedia.model.DataLoader.prototype.loadDetailData = function(cellData,successCallback,errorCallback) {
	$s.push("org.intermedia.model.DataLoader::loadDetailData");
	var $spos = $s.length;
	var me = this;
	this.onCellDetailLoaded = successCallback;
	this.onLoadingError = errorCallback;
	var onLoadSuccessDelegate = function(listId,xml) {
		$s.push("org.intermedia.model.DataLoader::loadDetailData@108");
		var $spos = $s.length;
		me.onCellDetailXmlLoaded(xml,cellData);
		$s.pop();
	};
	var fullUrl = "";
	if(this._online) fullUrl = "http://www.silexlabs.org/feed/ep_get_item_info?format=rss2&p=" + cellData.id; else fullUrl = "data/detail.rss";
	var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,onLoadSuccessDelegate,this.onLoadingError);
	$s.pop();
}
org.intermedia.model.DataLoader.prototype.onCellsXmlLoaded = function(listId,xml) {
	$s.push("org.intermedia.model.DataLoader::onCellsXmlLoaded");
	var $spos = $s.length;
	this.onCellDataLoaded({ id : listId, cells : org.intermedia.model.ThumbTextListRssStandard.rss2Cells(xml)});
	$s.pop();
}
org.intermedia.model.DataLoader.prototype.onCellDetailXmlLoaded = function(xml,cellData) {
	$s.push("org.intermedia.model.DataLoader::onCellDetailXmlLoaded");
	var $spos = $s.length;
	this.onCellDetailLoaded(org.intermedia.model.CellDetailsRss.rss2CellDetail(xml,cellData));
	$s.pop();
}
org.intermedia.model.DataLoader.prototype.__class__ = org.intermedia.model.DataLoader;
org.intermedia.model.ThumbTextListRssStandard = function() { }
org.intermedia.model.ThumbTextListRssStandard.__name__ = ["org","intermedia","model","ThumbTextListRssStandard"];
org.intermedia.model.ThumbTextListRssStandard.rss2Cells = function(rss) {
	$s.push("org.intermedia.model.ThumbTextListRssStandard::rss2Cells");
	var $spos = $s.length;
	var cells = new Array();
	var channelNode = rss.firstElement().firstElement();
	if(channelNode == null) {
		$s.pop();
		return cells;
	}
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
	$s.pop();
	return cells;
	$s.pop();
}
org.intermedia.model.ThumbTextListRssStandard.cleanText = function(text) {
	$s.push("org.intermedia.model.ThumbTextListRssStandard::cleanText");
	var $spos = $s.length;
	var $tmp = StringTools.htmlUnescape(org.intermedia.model.ThumbTextListRssStandard.cleanCharCodes(text));
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.model.ThumbTextListRssStandard.cleanCharCodes = function(text) {
	$s.push("org.intermedia.model.ThumbTextListRssStandard::cleanCharCodes");
	var $spos = $s.length;
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
	$s.pop();
	return text;
	$s.pop();
	return text;
	$s.pop();
}
org.intermedia.model.ThumbTextListRssStandard.getThumb = function(htmlString) {
	$s.push("org.intermedia.model.ThumbTextListRssStandard::getThumb");
	var $spos = $s.length;
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
			$s.pop();
			return imgUrl;
		}
	} else {
		imgUrlStartIndex = htmlString.indexOf("<p>http://");
		if(imgUrlStartIndex != -1) {
			var srcKeyWord = "<p>";
			imgUrl = htmlString.substr(imgUrlStartIndex + srcKeyWord.length);
			var imgUrlEndIndex = imgUrl.indexOf("</p>");
			imgUrl = imgUrl.substr(0,imgUrlEndIndex);
			$s.pop();
			return imgUrl;
		}
	}
	$s.pop();
	return "";
	$s.pop();
}
org.intermedia.model.ThumbTextListRssStandard.prototype.__class__ = org.intermedia.model.ThumbTextListRssStandard;
org.intermedia.Application = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.Application::new");
	var $spos = $s.length;
	var applicationModel = new org.intermedia.model.ApplicationModel();
	var applicationController = new org.intermedia.controller.ApplicationController(applicationModel);
	var view = new org.intermedia.view.ViewManager(applicationModel,applicationController);
	$s.pop();
}
org.intermedia.Application.__name__ = ["org","intermedia","Application"];
org.intermedia.Application.main = function() {
	$s.push("org.intermedia.Application::main");
	var $spos = $s.length;
	new org.intermedia.Application();
	$s.pop();
}
org.intermedia.Application.prototype.__class__ = org.intermedia.Application;
org.intermedia.view.HeaderView = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.view.HeaderView::new");
	var $spos = $s.length;
	org.intermedia.view.ViewBase.call(this);
	this._data = "";
	this._backButtonContainer = this.buildBackButtonView();
	$s.pop();
}
org.intermedia.view.HeaderView.__name__ = ["org","intermedia","view","HeaderView"];
org.intermedia.view.HeaderView.__super__ = org.intermedia.view.ViewBase;
for(var k in org.intermedia.view.ViewBase.prototype ) org.intermedia.view.HeaderView.prototype[k] = org.intermedia.view.ViewBase.prototype[k];
org.intermedia.view.HeaderView.prototype.onBackButtonClick = null;
org.intermedia.view.HeaderView.prototype._displayBackButton = null;
org.intermedia.view.HeaderView.prototype.displayBackButton = null;
org.intermedia.view.HeaderView.prototype._titleContainer = null;
org.intermedia.view.HeaderView.prototype._titleTextElement = null;
org.intermedia.view.HeaderView.prototype._backButtonContainer = null;
org.intermedia.view.HeaderView.prototype.getDisplayBackButton = function() {
	$s.push("org.intermedia.view.HeaderView::getDisplayBackButton");
	var $spos = $s.length;
	var $tmp = this._displayBackButton;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.setDisplayBackButton = function(v) {
	$s.push("org.intermedia.view.HeaderView::setDisplayBackButton");
	var $spos = $s.length;
	this._displayBackButton = v;
	if(this._displayBackButton) this.node.appendChild(this._backButtonContainer); else if(this._backButtonContainer.parentNode != null) this.node.removeChild(this._backButtonContainer);
	var $tmp = this._displayBackButton;
	$s.pop();
	return $tmp;
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.buildView = function() {
	$s.push("org.intermedia.view.HeaderView::buildView");
	var $spos = $s.length;
	org.intermedia.view.HeaderStyle.setHeaderStyle(this.node);
	this._titleTextElement = js.Lib.document.createTextNode(this._data);
	this._titleContainer = js.Lib.document.createElement("div");
	this._titleContainer.appendChild(this._titleTextElement);
	org.intermedia.view.HeaderStyle.setHeaderTextStyle(this._titleContainer);
	this.node.appendChild(this._titleContainer);
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.updateView = function() {
	$s.push("org.intermedia.view.HeaderView::updateView");
	var $spos = $s.length;
	this._titleContainer.removeChild(this._titleTextElement);
	this._titleTextElement = js.Lib.document.createTextNode(this._data);
	this._titleContainer.appendChild(this._titleTextElement);
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.buildBackButtonView = function() {
	$s.push("org.intermedia.view.HeaderView::buildBackButtonView");
	var $spos = $s.length;
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
		$s.push("org.intermedia.view.HeaderView::buildBackButtonView@138");
		var $spos = $s.length;
		me.onBackButtonClickCallback();
		$s.pop();
	};
	$s.pop();
	return backButtonContainer;
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.onBackButtonClickCallback = function() {
	$s.push("org.intermedia.view.HeaderView::onBackButtonClickCallback");
	var $spos = $s.length;
	if(this.onBackButtonClick != null) this.onBackButtonClick();
	$s.pop();
}
org.intermedia.view.HeaderView.prototype.__class__ = org.intermedia.view.HeaderView;
org.intermedia.view.Scroll2D = function(scrollType) {
	if( scrollType === $_ ) return;
	$s.push("org.intermedia.view.Scroll2D::new");
	var $spos = $s.length;
	this._scrollType = scrollType;
	this._initialPosition = { x : 0, y : 0};
	this._offset = { x : 0, y : 0};
	this._scrollPosition = { x : 0, y : 0};
	this.initialScrollPosition = { x : 0, y : 0};
	this._direction = org.intermedia.view.Direction.notYetSet;
	$s.pop();
}
org.intermedia.view.Scroll2D.__name__ = ["org","intermedia","view","Scroll2D"];
org.intermedia.view.Scroll2D.prototype._offset = null;
org.intermedia.view.Scroll2D.prototype._initialPosition = null;
org.intermedia.view.Scroll2D.prototype.initialScrollPosition = null;
org.intermedia.view.Scroll2D.prototype._scrollPosition = null;
org.intermedia.view.Scroll2D.prototype._scrollType = null;
org.intermedia.view.Scroll2D.prototype._direction = null;
org.intermedia.view.Scroll2D.prototype.onHorizontalScroll = null;
org.intermedia.view.Scroll2D.prototype.onVerticalScroll = null;
org.intermedia.view.Scroll2D.prototype.onHorizontalUp = null;
org.intermedia.view.Scroll2D.prototype.onHorizontalTweenEnd = null;
org.intermedia.view.Scroll2D.prototype._horizontalTween = null;
org.intermedia.view.Scroll2D.prototype._verticalTween = null;
org.intermedia.view.Scroll2D.prototype.touchHandler = function(event) {
	$s.push("org.intermedia.view.Scroll2D::touchHandler");
	var $spos = $s.length;
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
		$s.pop();
		return;
	}
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onDownCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onDownCallback");
	var $spos = $s.length;
	this.stopTweens();
	this._initialPosition.x = event.touches[0].pageX;
	this._initialPosition.y = event.touches[0].pageY;
	if(this._scrollType == org.intermedia.view.ScrollType.horizontal) this._direction = org.intermedia.view.Direction.horizontal; else if(this._scrollType == org.intermedia.view.ScrollType.vertical) this._direction = org.intermedia.view.Direction.vertical; else this._direction = org.intermedia.view.Direction.notYetSet;
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onMoveCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onMoveCallback");
	var $spos = $s.length;
	this._offset.x = Std["int"](event.touches[0].pageX - this._initialPosition.x);
	this._offset.y = Std["int"](event.touches[0].pageY - this._initialPosition.y);
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
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onHorizontalMoveCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onHorizontalMoveCallback");
	var $spos = $s.length;
	event.preventDefault();
	this._scrollPosition = { x : this.initialScrollPosition.x - this._offset.x, y : this.initialScrollPosition.x};
	this.onHorizontalScrollCallback(this._scrollPosition.x);
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onVerticalMoveCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onVerticalMoveCallback");
	var $spos = $s.length;
	event.preventDefault();
	this._scrollPosition = { x : this.initialScrollPosition.x, y : this.initialScrollPosition.y - this._offset.y};
	this.onVerticalScrollCallback(this._scrollPosition.y);
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onUpCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onUpCallback");
	var $spos = $s.length;
	if(this._direction == org.intermedia.view.Direction.horizontal) this.onHorizontalUpCallback(event); else if(this._direction == org.intermedia.view.Direction.vertical) this.verticalReleaseTween();
	this._direction = org.intermedia.view.Direction.notYetSet;
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onHorizontalUpCallback = function(event) {
	$s.push("org.intermedia.view.Scroll2D::onHorizontalUpCallback");
	var $spos = $s.length;
	if(this.onHorizontalUp != null) this.onHorizontalUp(event,this._offset.x);
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.horizontalReleaseTween = function(xOrigin,xTarget) {
	$s.push("org.intermedia.view.Scroll2D::horizontalReleaseTween");
	var $spos = $s.length;
	this._horizontalTween = new feffects.Tween(xOrigin,xTarget,600,feffects.easing.Quint.easeOut);
	this._horizontalTween.setTweenHandlers($closure(this,"onHorizontalScrollCallback"),$closure(this,"horizontalTweenEnd"));
	this._horizontalTween.start();
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onHorizontalScrollCallback = function(e) {
	$s.push("org.intermedia.view.Scroll2D::onHorizontalScrollCallback");
	var $spos = $s.length;
	if(this.onHorizontalScroll != null) this.onHorizontalScroll(Std["int"](e),this._offset.x);
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.horizontalTweenEnd = function(e) {
	$s.push("org.intermedia.view.Scroll2D::horizontalTweenEnd");
	var $spos = $s.length;
	if(this.onHorizontalTweenEnd != null) this.onHorizontalTweenEnd();
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.verticalReleaseTween = function() {
	$s.push("org.intermedia.view.Scroll2D::verticalReleaseTween");
	var $spos = $s.length;
	var verticalTweenEnd = 0;
	if(this._offset.y > 0) verticalTweenEnd = this._scrollPosition.y - 100; else verticalTweenEnd = this._scrollPosition.y + 100;
	this._verticalTween = new feffects.Tween(this._scrollPosition.y,verticalTweenEnd,600,feffects.easing.Quint.easeOut);
	this._verticalTween.setTweenHandlers($closure(this,"onVerticalScrollCallback"),$closure(this,"onVerticalTweenEnd"));
	this._verticalTween.start();
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onVerticalScrollCallback = function(e) {
	$s.push("org.intermedia.view.Scroll2D::onVerticalScrollCallback");
	var $spos = $s.length;
	if(this.onVerticalScroll != null) this.onVerticalScroll(Std["int"](e));
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.onVerticalTweenEnd = function(e) {
	$s.push("org.intermedia.view.Scroll2D::onVerticalTweenEnd");
	var $spos = $s.length;
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.stopTweens = function() {
	$s.push("org.intermedia.view.Scroll2D::stopTweens");
	var $spos = $s.length;
	if(this._horizontalTween != null && this._horizontalTween.isPlaying) this._horizontalTween.pause();
	if(this._verticalTween != null && this._verticalTween.isPlaying) this._verticalTween.stop();
	$s.pop();
}
org.intermedia.view.Scroll2D.prototype.__class__ = org.intermedia.view.Scroll2D;
org.intermedia.view.Direction = { __ename__ : ["org","intermedia","view","Direction"], __constructs__ : ["horizontal","vertical","notYetSet"] }
org.intermedia.view.Direction.horizontal = ["horizontal",0];
org.intermedia.view.Direction.horizontal.toString = $estr;
org.intermedia.view.Direction.horizontal.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.vertical = ["vertical",1];
org.intermedia.view.Direction.vertical.toString = $estr;
org.intermedia.view.Direction.vertical.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.Direction.notYetSet = ["notYetSet",2];
org.intermedia.view.Direction.notYetSet.toString = $estr;
org.intermedia.view.Direction.notYetSet.__enum__ = org.intermedia.view.Direction;
org.intermedia.view.ScrollType = { __ename__ : ["org","intermedia","view","ScrollType"], __constructs__ : ["horizontal","vertical","both"] }
org.intermedia.view.ScrollType.horizontal = ["horizontal",0];
org.intermedia.view.ScrollType.horizontal.toString = $estr;
org.intermedia.view.ScrollType.horizontal.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.vertical = ["vertical",1];
org.intermedia.view.ScrollType.vertical.toString = $estr;
org.intermedia.view.ScrollType.vertical.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.ScrollType.both = ["both",2];
org.intermedia.view.ScrollType.both.toString = $estr;
org.intermedia.view.ScrollType.both.__enum__ = org.intermedia.view.ScrollType;
org.intermedia.view.CellThumbStyle = function() { }
org.intermedia.view.CellThumbStyle.__name__ = ["org","intermedia","view","CellThumbStyle"];
org.intermedia.view.CellThumbStyle.setCellStyle = function(node,cellPerLine) {
	$s.push("org.intermedia.view.CellThumbStyle::setCellStyle");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellStyle.setCellStyle(node,cellPerLine);
	var cellSize = org.intermedia.view.ImageUtils.computeMaskSize(cellPerLine);
	node.style.height = Std.string(cellSize.height) + "px";
	node.style.maxHeight = Std.string(150) + "px";
	node.style.overflowX = "hidden";
	node.style.overflowY = "hidden";
	org.intermedia.view.CellStyle.addBorder(node);
	$s.pop();
	return cellSize;
	$s.pop();
}
org.intermedia.view.CellThumbStyle.setThumbnailStyle = function(image,maskSize) {
	$s.push("org.intermedia.view.CellThumbStyle::setThumbnailStyle");
	var $spos = $s.length;
	image.style.display = "inline";
	image.style.verticalAlign = "middle";
	image.style.opacity = 0;
	org.intermedia.view.ImageUtils.cropImage(image,maskSize);
	$s.pop();
}
org.intermedia.view.CellThumbStyle.prototype.__class__ = org.intermedia.view.CellThumbStyle;
org.intermedia.model.ApplicationModel = function(p) {
	if( p === $_ ) return;
	$s.push("org.intermedia.model.ApplicationModel::new");
	var $spos = $s.length;
	this._online = false;
	this._loadedCellsData = new Array();
	this._loadedDetailData = new Array();
	this._dataLoader = new org.intermedia.model.DataLoader(this._online);
	$s.pop();
}
org.intermedia.model.ApplicationModel.__name__ = ["org","intermedia","model","ApplicationModel"];
org.intermedia.model.ApplicationModel.prototype.onModelCellDataLoaded = null;
org.intermedia.model.ApplicationModel.prototype.onModelDetailDataLoaded = null;
org.intermedia.model.ApplicationModel.prototype.onModelDataLoadError = null;
org.intermedia.model.ApplicationModel.prototype.onModelStartsLoading = null;
org.intermedia.model.ApplicationModel.prototype._dataLoader = null;
org.intermedia.model.ApplicationModel.prototype._loadedCellsData = null;
org.intermedia.model.ApplicationModel.prototype._loadedDetailData = null;
org.intermedia.model.ApplicationModel.prototype._online = null;
org.intermedia.model.ApplicationModel.prototype.loadCellData = function(feed) {
	$s.push("org.intermedia.model.ApplicationModel::loadCellData");
	var $spos = $s.length;
	if(this._loadedCellsData.length == 0) {
		if(this.onModelStartsLoading != null) this.onModelStartsLoading();
	}
	this._dataLoader.loadCellData(feed,10,$closure(this,"onCellsDataLoadComplete"),this.onModelDataLoadError);
	$s.pop();
}
org.intermedia.model.ApplicationModel.prototype.loadDetailData = function(cellData) {
	$s.push("org.intermedia.model.ApplicationModel::loadDetailData");
	var $spos = $s.length;
	if(this.onModelStartsLoading != null) this.onModelStartsLoading();
	this._dataLoader.loadDetailData(cellData,$closure(this,"onDetailDataLoadComplete"),this.onModelDataLoadError);
	$s.pop();
}
org.intermedia.model.ApplicationModel.prototype.onCellsDataLoadComplete = function(listData) {
	$s.push("org.intermedia.model.ApplicationModel::onCellsDataLoadComplete");
	var $spos = $s.length;
	this._loadedCellsData = new Array();
	var _g = 0, _g1 = listData.cells;
	while(_g < _g1.length) {
		var cellData = _g1[_g];
		++_g;
		this._loadedCellsData.push(cellData);
	}
	if(this.onModelCellDataLoaded != null) this.onModelCellDataLoaded(listData);
	$s.pop();
}
org.intermedia.model.ApplicationModel.prototype.onDetailDataLoadComplete = function(detailData) {
	$s.push("org.intermedia.model.ApplicationModel::onDetailDataLoadComplete");
	var $spos = $s.length;
	this._loadedDetailData.push(detailData);
	if(this.onModelDetailDataLoaded != null) this.onModelDetailDataLoaded(detailData);
	$s.pop();
}
org.intermedia.model.ApplicationModel.prototype.__class__ = org.intermedia.model.ApplicationModel;
js.Lib = function() { }
js.Lib.__name__ = ["js","Lib"];
js.Lib.isIE = null;
js.Lib.isOpera = null;
js.Lib.document = null;
js.Lib.window = null;
js.Lib.alert = function(v) {
	$s.push("js.Lib::alert");
	var $spos = $s.length;
	alert(js.Boot.__string_rec(v,""));
	$s.pop();
}
js.Lib.eval = function(code) {
	$s.push("js.Lib::eval");
	var $spos = $s.length;
	var $tmp = eval(code);
	$s.pop();
	return $tmp;
	$s.pop();
}
js.Lib.setErrorHandler = function(f) {
	$s.push("js.Lib::setErrorHandler");
	var $spos = $s.length;
	js.Lib.onerror = f;
	$s.pop();
}
js.Lib.prototype.__class__ = js.Lib;
org.intermedia.view.DetailStyle = function() { }
org.intermedia.view.DetailStyle.__name__ = ["org","intermedia","view","DetailStyle"];
org.intermedia.view.DetailStyle.setDetailStyle = function(node) {
	$s.push("org.intermedia.view.DetailStyle::setDetailStyle");
	var $spos = $s.length;
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
	$s.pop();
}
org.intermedia.view.DetailStyle.setThumbnail = function(node) {
	$s.push("org.intermedia.view.DetailStyle::setThumbnail");
	var $spos = $s.length;
	var imageMaxWidth = 250;
	node.style.display = "block";
	node.style.maxWidth = Std.string(imageMaxWidth) + "px";
	node.style.maxHeight = "50%";
	node.style.width = "80%";
	$s.pop();
}
org.intermedia.view.DetailStyle.setText = function(node) {
	$s.push("org.intermedia.view.DetailStyle::setText");
	var $spos = $s.length;
	node.style.display = "block";
	node.style.color = "#202020";
	node.style.fontFamily = "Arial, sans-serif";
	$s.pop();
}
org.intermedia.view.DetailStyle.setTitle = function(node,screenResolutionSize) {
	$s.push("org.intermedia.view.DetailStyle::setTitle");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(node);
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "bold";
	$s.pop();
}
org.intermedia.view.DetailStyle.setAuthor = function(node,screenResolutionSize) {
	$s.push("org.intermedia.view.DetailStyle::setAuthor");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(node);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	node.style.fontSize = Std.string(fontSize) + "px";
	node.style.fontWeight = "normal";
	$s.pop();
}
org.intermedia.view.DetailStyle.setDescription = function(node) {
	$s.push("org.intermedia.view.DetailStyle::setDescription");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(node);
	node.style.marginTop = Std.string(10) + "px";
	node.style.marginBottom = Std.string(10) + "px";
	node.style.fontSize = "14px";
	$s.pop();
}
org.intermedia.view.DetailStyle.prototype.__class__ = org.intermedia.view.DetailStyle;
StringTools = function() { }
StringTools.__name__ = ["StringTools"];
StringTools.urlEncode = function(s) {
	$s.push("StringTools::urlEncode");
	var $spos = $s.length;
	var $tmp = encodeURIComponent(s);
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.urlDecode = function(s) {
	$s.push("StringTools::urlDecode");
	var $spos = $s.length;
	var $tmp = decodeURIComponent(s.split("+").join(" "));
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.htmlEscape = function(s) {
	$s.push("StringTools::htmlEscape");
	var $spos = $s.length;
	var $tmp = s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.htmlUnescape = function(s) {
	$s.push("StringTools::htmlUnescape");
	var $spos = $s.length;
	var $tmp = s.split("&gt;").join(">").split("&lt;").join("<").split("&amp;").join("&");
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.startsWith = function(s,start) {
	$s.push("StringTools::startsWith");
	var $spos = $s.length;
	var $tmp = s.length >= start.length && s.substr(0,start.length) == start;
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.endsWith = function(s,end) {
	$s.push("StringTools::endsWith");
	var $spos = $s.length;
	var elen = end.length;
	var slen = s.length;
	var $tmp = slen >= elen && s.substr(slen - elen,elen) == end;
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.isSpace = function(s,pos) {
	$s.push("StringTools::isSpace");
	var $spos = $s.length;
	var c = s.charCodeAt(pos);
	var $tmp = c >= 9 && c <= 13 || c == 32;
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.ltrim = function(s) {
	$s.push("StringTools::ltrim");
	var $spos = $s.length;
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,r)) r++;
	if(r > 0) {
		var $tmp = s.substr(r,l - r);
		$s.pop();
		return $tmp;
	} else {
		$s.pop();
		return s;
	}
	$s.pop();
}
StringTools.rtrim = function(s) {
	$s.push("StringTools::rtrim");
	var $spos = $s.length;
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) r++;
	if(r > 0) {
		var $tmp = s.substr(0,l - r);
		$s.pop();
		return $tmp;
	} else {
		$s.pop();
		return s;
	}
	$s.pop();
}
StringTools.trim = function(s) {
	$s.push("StringTools::trim");
	var $spos = $s.length;
	var $tmp = StringTools.ltrim(StringTools.rtrim(s));
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.rpad = function(s,c,l) {
	$s.push("StringTools::rpad");
	var $spos = $s.length;
	var sl = s.length;
	var cl = c.length;
	while(sl < l) if(l - sl < cl) {
		s += c.substr(0,l - sl);
		sl = l;
	} else {
		s += c;
		sl += cl;
	}
	$s.pop();
	return s;
	$s.pop();
}
StringTools.lpad = function(s,c,l) {
	$s.push("StringTools::lpad");
	var $spos = $s.length;
	var ns = "";
	var sl = s.length;
	if(sl >= l) {
		$s.pop();
		return s;
	}
	var cl = c.length;
	while(sl < l) if(l - sl < cl) {
		ns += c.substr(0,l - sl);
		sl = l;
	} else {
		ns += c;
		sl += cl;
	}
	var $tmp = ns + s;
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.replace = function(s,sub,by) {
	$s.push("StringTools::replace");
	var $spos = $s.length;
	var $tmp = s.split(sub).join(by);
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.hex = function(n,digits) {
	$s.push("StringTools::hex");
	var $spos = $s.length;
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(n & 15) + s;
		n >>>= 4;
	} while(n > 0);
	if(digits != null) while(s.length < digits) s = "0" + s;
	$s.pop();
	return s;
	$s.pop();
}
StringTools.fastCodeAt = function(s,index) {
	$s.push("StringTools::fastCodeAt");
	var $spos = $s.length;
	var $tmp = s.cca(index);
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.isEOF = function(c) {
	$s.push("StringTools::isEOF");
	var $spos = $s.length;
	var $tmp = c != c;
	$s.pop();
	return $tmp;
	$s.pop();
}
StringTools.prototype.__class__ = StringTools;
$_ = {}
js.Boot.__res = {}
$s = [];
$e = [];
js.Boot.__init();
js["XMLHttpRequest"] = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
	$s.push("StringTools::isEOF");
	var $spos = $s.length;
	try {
		var $tmp = new ActiveXObject("Msxml2.XMLHTTP");
		$s.pop();
		return $tmp;
	} catch( e ) {
		$e = [];
		while($s.length >= $spos) $e.unshift($s.pop());
		$s.push($e[0]);
		try {
			var $tmp = new ActiveXObject("Microsoft.XMLHTTP");
			$s.pop();
			return $tmp;
		} catch( e1 ) {
			$e = [];
			while($s.length >= $spos) $e.unshift($s.pop());
			$s.push($e[0]);
			throw "Unable to create XMLHttpRequest object.";
		}
	}
	$s.pop();
}:(function($this) {
	var $r;
	throw "Unable to create XMLHttpRequest object.";
	return $r;
}(this));
{
	Math.__name__ = ["Math"];
	Math.NaN = Number["NaN"];
	Math.NEGATIVE_INFINITY = Number["NEGATIVE_INFINITY"];
	Math.POSITIVE_INFINITY = Number["POSITIVE_INFINITY"];
	Math.isFinite = function(i) {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		var $tmp = isFinite(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	Math.isNaN = function(i) {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		var $tmp = isNaN(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
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
if(typeof(haxe_timers) == "undefined") haxe_timers = [];
{
	String.prototype.__class__ = String;
	String.__name__ = ["String"];
	Array.prototype.__class__ = Array;
	Array.__name__ = ["Array"];
	Int = { __name__ : ["Int"]};
	Dynamic = { __name__ : ["Dynamic"]};
	Float = Number;
	Float.__name__ = ["Float"];
	Bool = { __ename__ : ["Bool"]};
	Class = { __name__ : ["Class"]};
	Enum = { };
	Void = { __ename__ : ["Void"]};
}
{
	js.Lib.document = document;
	js.Lib.window = window;
	onerror = function(msg,url,line) {
		var stack = $s.copy();
		var f = js.Lib.onerror;
		$s.splice(0,$s.length);
		if( f == null ) {
			var i = stack.length;
			var s = "";
			while( --i >= 0 )
				s += "Called from "+stack[i]+"\n";
			alert(msg+"\n\n"+s);
			return false;
		}
		return f(msg,stack);
	}
}
{
	var d = Date;
	d.now = function() {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		var $tmp = new Date();
		$s.pop();
		return $tmp;
		$s.pop();
	};
	d.fromTime = function(t) {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		var d1 = new Date();
		d1["setTime"](t);
		$s.pop();
		return d1;
		$s.pop();
	};
	d.fromString = function(s) {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		switch(s.length) {
		case 8:
			var k = s.split(":");
			var d1 = new Date();
			d1["setTime"](0);
			d1["setUTCHours"](k[0]);
			d1["setUTCMinutes"](k[1]);
			d1["setUTCSeconds"](k[2]);
			$s.pop();
			return d1;
		case 10:
			var k = s.split("-");
			var $tmp = new Date(k[0],k[1] - 1,k[2],0,0,0);
			$s.pop();
			return $tmp;
		case 19:
			var k = s.split(" ");
			var y = k[0].split("-");
			var t = k[1].split(":");
			var $tmp = new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
			$s.pop();
			return $tmp;
		default:
			throw "Invalid date format : " + s;
		}
		$s.pop();
	};
	d.prototype["toString"] = function() {
		$s.push("StringTools::isEOF");
		var $spos = $s.length;
		var date = this;
		var m = date.getMonth() + 1;
		var d1 = date.getDate();
		var h = date.getHours();
		var mi = date.getMinutes();
		var s = date.getSeconds();
		var $tmp = date.getFullYear() + "-" + (m < 10?"0" + m:"" + m) + "-" + (d1 < 10?"0" + d1:"" + d1) + " " + (h < 10?"0" + h:"" + h) + ":" + (mi < 10?"0" + mi:"" + mi) + ":" + (s < 10?"0" + s:"" + s);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	d.prototype.__class__ = d;
	d.__name__ = ["Date"];
}
org.intermedia.view.LoadingViewStyle.CELL_VERTICAL_SPACE = 5;
feffects.Tween._aTweens = new haxe.FastList();
feffects.Tween._aPaused = new haxe.FastList();
feffects.Tween.INTERVAL = 10;
org.intermedia.view.CellThumbText1.TITLE_LENGTH = 40;
org.intermedia.view.CellThumbText1Style.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbText1Style.CELL_TEXT_WIDTH_PERCENT = 60;
org.intermedia.view.CellThumbText1Style.CELL_THUMB_WIDTH_PERCENT = 35;
org.intermedia.view.CellTextStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.model.Feeds.FEED_1 = { id : 0, title : "Techcrunch", url : "http://fr.techcrunch.com/feed/"};
org.intermedia.model.Feeds.FEED_2 = { id : 1, title : "SiliconSentier", url : "http://siliconsentier.org/feed/"};
org.intermedia.model.Feeds.FEED_3 = { id : 2, title : "Frenchweb", url : "http://frenchweb.fr/feed/"};
org.intermedia.view.Constants.HEADER_HEIGHT = 43;
org.intermedia.view.Constants.MENU_HEIGHT = 35;
org.intermedia.view.Constants.LIST_TOP = 78;
org.intermedia.view.Constants.LIST_BG_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_BG_COLOR = "#FFFFFF";
org.intermedia.view.Constants.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.Constants.CELL_BORDER_WIDTH = 1;
org.intermedia.view.Constants.CELL_BORDER_COLOR = "#CCCCCC";
org.intermedia.view.Constants.CELL_HEIGHT = 90;
org.intermedia.view.MenuCellTextStyle.CELL_VERTICAL_SPACE = 5;
org.intermedia.view.MenuCellTextStyle.CELL_HORIZONTAL_PADDING = 5;
Xml.enode = new EReg("^<([a-zA-Z0-9:_-]+)","");
Xml.ecdata = new EReg("^<!\\[CDATA\\[","i");
Xml.edoctype = new EReg("^<!DOCTYPE ","i");
Xml.eend = new EReg("^</([a-zA-Z0-9:_-]+)>","");
Xml.epcdata = new EReg("^[^<]+","");
Xml.ecomment = new EReg("^<!--","");
Xml.eprolog = new EReg("^<\\?[^\\?]+\\?>","");
Xml.eattribute = new EReg("^\\s*([a-zA-Z0-9:_-]+)\\s*=\\s*([\"'])([^\\2]*?)\\2","");
Xml.eclose = new EReg("^[ \r\n\t]*(>|(/>))","");
Xml.ecdata_end = new EReg("\\]\\]>","");
Xml.edoctype_elt = new EReg("[\\[|\\]>]","");
Xml.ecomment_end = new EReg("-->","");
org.intermedia.view.ViewManager.HEADER_HOME_TITLE = "Market";
org.intermedia.view.ViewManager.HEADER_DETAIL_TITLE = "Infos";
org.intermedia.view.SwippableListView.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.SwippableListView.VERTICAL_TWEEN_DELTA = 150;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEM_PER_LIST = 3;
org.intermedia.view.SwippableListView.LIST_QTY = 2;
org.intermedia.view.SwippableListView.HOMEPAGE_ITEMS = 6;
org.intermedia.view.Scroll2D.DIRECTION_PIXEL_MINIMUM = 5;
org.intermedia.view.Scroll2D.VERTICAL_TWEEN_DELTA = 100;
org.intermedia.view.CellThumbStyle.CELL_VERTICAL_SPACE = 2;
org.intermedia.view.CellThumbStyle.CELL_RATIO = 16 / 9;
org.intermedia.view.CellThumbStyle.CELL_MAX_HEIGHT = 150;
org.intermedia.view.CellThumbStyle.CELL_HEIGHT = 100;
org.intermedia.model.ApplicationModel.CELL_QTY = 10;
js.Lib.onerror = null;
org.intermedia.Application.main()