$estr = function() { return js.Boot.__string_rec(this,''); }
if(typeof cocktail=='undefined') cocktail = {}
if(!cocktail.core) cocktail.core = {}
if(!cocktail.core.dom) cocktail.core.dom = {}
cocktail.core.dom.Node = function(p) {
	if( p === $_ ) return;
	this._childNodes = new Array();
}
cocktail.core.dom.Node.__name__ = ["cocktail","core","dom","Node"];
cocktail.core.dom.Node.prototype.nodeType = null;
cocktail.core.dom.Node.prototype.nodeValue = null;
cocktail.core.dom.Node.prototype.nodeName = null;
cocktail.core.dom.Node.prototype._parentNode = null;
cocktail.core.dom.Node.prototype.parentNode = null;
cocktail.core.dom.Node.prototype._childNodes = null;
cocktail.core.dom.Node.prototype.childNodes = null;
cocktail.core.dom.Node.prototype.firstChild = null;
cocktail.core.dom.Node.prototype.lastChild = null;
cocktail.core.dom.Node.prototype.nextSibling = null;
cocktail.core.dom.Node.prototype.previousSibling = null;
cocktail.core.dom.Node.prototype._attributes = null;
cocktail.core.dom.Node.prototype.attributes = null;
cocktail.core.dom.Node.prototype._ownerDocument = null;
cocktail.core.dom.Node.prototype.ownerDocument = null;
cocktail.core.dom.Node.prototype.removeChild = function(oldChild) {
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
cocktail.core.dom.Node.prototype.appendChild = function(newChild) {
	this.removeFromParentIfNecessary(newChild);
	newChild.set_parentNode(this);
	this._childNodes.push(newChild);
	return newChild;
}
cocktail.core.dom.Node.prototype.insertBefore = function(newChild,refChild) {
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
cocktail.core.dom.Node.prototype.replaceChild = function(newChild,oldChild) {
	var newChildNodes = new Array();
	var _g1 = 0, _g = this._childNodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._childNodes[i] == oldChild) newChildNodes.push(newChild); else newChildNodes.push(this._childNodes[i]);
	}
	this._childNodes = newChildNodes;
	return oldChild;
}
cocktail.core.dom.Node.prototype.isSameNode = function(other) {
	return other == this;
}
cocktail.core.dom.Node.prototype.hasChildNodes = function() {
	return this._childNodes.length > 0;
}
cocktail.core.dom.Node.prototype.hasAttributes = function() {
	return false;
}
cocktail.core.dom.Node.prototype.removeFromParentIfNecessary = function(newChild) {
	if(newChild.get_parentNode() != null) {
		var parentNode = newChild.get_parentNode();
		parentNode.removeChild(newChild);
	}
}
cocktail.core.dom.Node.prototype.get_firstChild = function() {
	if(this.hasChildNodes() == true) return this._childNodes[0]; else return null;
}
cocktail.core.dom.Node.prototype.get_lastChild = function() {
	if(this.hasChildNodes() == true) return this._childNodes[this._childNodes.length - 1]; else return null;
}
cocktail.core.dom.Node.prototype.get_nextSibling = function() {
	if(this._parentNode == null) return null; else if(this._parentNode.get_lastChild() != this) {
		var _g1 = 0, _g = this._parentNode.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isSameNode(this._parentNode.get_childNodes()[i]) == true) return this._parentNode.get_childNodes()[i + 1];
		}
	}
	return null;
}
cocktail.core.dom.Node.prototype.get_previousSibling = function() {
	if(this._parentNode == null) return null; else if(this._parentNode.get_firstChild() != this) {
		var _g1 = 0, _g = this._parentNode.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isSameNode(this._parentNode.get_childNodes()[i]) == true) return this._parentNode.get_childNodes()[i - 1];
		}
	}
	return null;
}
cocktail.core.dom.Node.prototype.get_nodeType = function() {
	return -1;
}
cocktail.core.dom.Node.prototype.get_parentNode = function() {
	return this._parentNode;
}
cocktail.core.dom.Node.prototype.set_parentNode = function(value) {
	return this._parentNode = value;
}
cocktail.core.dom.Node.prototype.get_childNodes = function() {
	return this._childNodes;
}
cocktail.core.dom.Node.prototype.get_nodeValue = function() {
	return null;
}
cocktail.core.dom.Node.prototype.set_nodeValue = function(value) {
	return value;
}
cocktail.core.dom.Node.prototype.get_nodeName = function() {
	return null;
}
cocktail.core.dom.Node.prototype.get_attributes = function() {
	return null;
}
cocktail.core.dom.Node.prototype.get_ownerDocument = function() {
	return this._ownerDocument;
}
cocktail.core.dom.Node.prototype.set_ownerDocument = function(value) {
	return this._ownerDocument = value;
}
cocktail.core.dom.Node.prototype.__class__ = cocktail.core.dom.Node;
cocktail.core.dom.Element = function(tagName) {
	if( tagName === $_ ) return;
	this._tagName = tagName;
	this._attributes = new cocktail.core.dom.NamedNodeMap();
	cocktail.core.dom.Node.call(this);
}
cocktail.core.dom.Element.__name__ = ["cocktail","core","dom","Element"];
cocktail.core.dom.Element.__super__ = cocktail.core.dom.Node;
for(var k in cocktail.core.dom.Node.prototype ) cocktail.core.dom.Element.prototype[k] = cocktail.core.dom.Node.prototype[k];
cocktail.core.dom.Element.prototype._tagName = null;
cocktail.core.dom.Element.prototype.tagName = null;
cocktail.core.dom.Element.prototype.firstElementChild = null;
cocktail.core.dom.Element.prototype.lastElementChild = null;
cocktail.core.dom.Element.prototype.previousElementSibling = null;
cocktail.core.dom.Element.prototype.nextElementSibling = null;
cocktail.core.dom.Element.prototype.childElementCount = null;
cocktail.core.dom.Element.prototype.getAttribute = function(name) {
	var attribute = this.getAttributeNode(name);
	if(attribute != null) return attribute.get_value(); else return null;
}
cocktail.core.dom.Element.prototype.setAttribute = function(name,value) {
	var attribute = this._attributes.getNamedItem(name);
	if(attribute == null) {
		attribute = new cocktail.core.dom.Attr(name);
		this._attributes.setNamedItem(attribute);
		attribute.set_ownerElement(this);
	}
	attribute.set_value(value);
}
cocktail.core.dom.Element.prototype.getAttributeNode = function(name) {
	var attribute = this._attributes.getNamedItem(name);
	if(attribute != null) return attribute;
	return null;
}
cocktail.core.dom.Element.prototype.setAttributeNode = function(newAttr) {
	newAttr.set_ownerElement(this);
	return this._attributes.setNamedItem(newAttr);
}
cocktail.core.dom.Element.prototype.removeAttribute = function(name) {
	var removedAttribute = this._attributes.removeNamedItem(name);
	if(removedAttribute != null) removedAttribute.set_ownerElement(null);
}
cocktail.core.dom.Element.prototype.setIdAttribute = function(name,isId) {
	var idAttribute = this._attributes.getNamedItem(name);
	if(idAttribute == null) {
		idAttribute = new cocktail.core.dom.Attr(name);
		this._attributes.setNamedItem(idAttribute);
		idAttribute.set_ownerElement(this);
	}
	idAttribute.set_isId(isId);
}
cocktail.core.dom.Element.prototype.setIdAttributeNode = function(idAttr,isId) {
	idAttr.set_isId(isId);
	this._attributes.setNamedItem(idAttr);
}
cocktail.core.dom.Element.prototype.hasAttribute = function(name) {
	return this._attributes.getNamedItem(name) != null;
}
cocktail.core.dom.Element.prototype.getElementsByTagName = function(tagName) {
	var elements = new Array();
	this.doGetElementsByTagName(this,tagName,elements);
	return elements;
}
cocktail.core.dom.Element.prototype.doGetElementsByTagName = function(node,tagName,elements) {
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
cocktail.core.dom.Element.prototype.hasAttributes = function() {
	return this._attributes.get_length() > 0;
}
cocktail.core.dom.Element.prototype.get_nodeName = function() {
	return this._tagName;
}
cocktail.core.dom.Element.prototype.get_nodeType = function() {
	return 1;
}
cocktail.core.dom.Element.prototype.get_attributes = function() {
	return this._attributes;
}
cocktail.core.dom.Element.prototype.get_firstElementChild = function() {
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
cocktail.core.dom.Element.prototype.get_lastElementChild = function() {
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
cocktail.core.dom.Element.prototype.get_nextElementSibling = function() {
	if(this.get_nextSibling() == null) return null;
	var nextElementSibling = this.get_nextSibling();
	while(nextElementSibling.get_nodeType() != 1) {
		nextElementSibling = nextElementSibling.get_nextSibling();
		if(nextElementSibling == null) return null;
	}
	return nextElementSibling;
}
cocktail.core.dom.Element.prototype.get_previousElementSibling = function() {
	if(this.get_previousSibling() == null) return null;
	var previousElementSibling = this.get_previousSibling();
	while(previousElementSibling.get_nodeType() != 1) {
		previousElementSibling = previousElementSibling.get_previousSibling();
		if(previousElementSibling == null) return null;
	}
	return previousElementSibling;
}
cocktail.core.dom.Element.prototype.get_childElementCount = function() {
	var childElementCount = 0;
	var _g1 = 0, _g = this._childNodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._childNodes[i].get_nodeType() == 1) childElementCount++;
	}
	return childElementCount;
}
cocktail.core.dom.Element.prototype.get_tagName = function() {
	return this._tagName;
}
cocktail.core.dom.Element.prototype.__class__ = cocktail.core.dom.Element;
if(!cocktail.core.event) cocktail.core.event = {}
cocktail.core.event.IEventTarget = function() { }
cocktail.core.event.IEventTarget.__name__ = ["cocktail","core","event","IEventTarget"];
cocktail.core.event.IEventTarget.prototype.__class__ = cocktail.core.event.IEventTarget;
if(!cocktail.core.html) cocktail.core.html = {}
cocktail.core.html.AbstractHTMLElement = function(tagName) {
	if( tagName === $_ ) return;
	cocktail.core.dom.Element.call(this,tagName);
	this.init();
}
cocktail.core.html.AbstractHTMLElement.__name__ = ["cocktail","core","html","AbstractHTMLElement"];
cocktail.core.html.AbstractHTMLElement.__super__ = cocktail.core.dom.Element;
for(var k in cocktail.core.dom.Element.prototype ) cocktail.core.html.AbstractHTMLElement.prototype[k] = cocktail.core.dom.Element.prototype[k];
cocktail.core.html.AbstractHTMLElement.prototype._mouse = null;
cocktail.core.html.AbstractHTMLElement.prototype._onClick = null;
cocktail.core.html.AbstractHTMLElement.prototype.onclick = null;
cocktail.core.html.AbstractHTMLElement.prototype._onMouseDown = null;
cocktail.core.html.AbstractHTMLElement.prototype.onmousedown = null;
cocktail.core.html.AbstractHTMLElement.prototype._onMouseUp = null;
cocktail.core.html.AbstractHTMLElement.prototype.onmouseup = null;
cocktail.core.html.AbstractHTMLElement.prototype._onMouseOver = null;
cocktail.core.html.AbstractHTMLElement.prototype.onmouseover = null;
cocktail.core.html.AbstractHTMLElement.prototype._onMouseOut = null;
cocktail.core.html.AbstractHTMLElement.prototype.onmouseout = null;
cocktail.core.html.AbstractHTMLElement.prototype._onMouseMove = null;
cocktail.core.html.AbstractHTMLElement.prototype.onmousemove = null;
cocktail.core.html.AbstractHTMLElement.prototype._keyboard = null;
cocktail.core.html.AbstractHTMLElement.prototype._onKeyDown = null;
cocktail.core.html.AbstractHTMLElement.prototype.onkeydown = null;
cocktail.core.html.AbstractHTMLElement.prototype._onKeyUp = null;
cocktail.core.html.AbstractHTMLElement.prototype.onkeyup = null;
cocktail.core.html.AbstractHTMLElement.prototype._tabIndex = null;
cocktail.core.html.AbstractHTMLElement.prototype.tabIndex = null;
cocktail.core.html.AbstractHTMLElement.prototype.isDefaultFocusable = null;
cocktail.core.html.AbstractHTMLElement.prototype._onFocus = null;
cocktail.core.html.AbstractHTMLElement.prototype.onfocus = null;
cocktail.core.html.AbstractHTMLElement.prototype._onBlur = null;
cocktail.core.html.AbstractHTMLElement.prototype.onblur = null;
cocktail.core.html.AbstractHTMLElement.prototype._onScroll = null;
cocktail.core.html.AbstractHTMLElement.prototype.onscroll = null;
cocktail.core.html.AbstractHTMLElement.prototype.scrollTop = null;
cocktail.core.html.AbstractHTMLElement.prototype.scrollLeft = null;
cocktail.core.html.AbstractHTMLElement.prototype.scrollHeight = null;
cocktail.core.html.AbstractHTMLElement.prototype.scrollWidth = null;
cocktail.core.html.AbstractHTMLElement.prototype._nativeElement = null;
cocktail.core.html.AbstractHTMLElement.prototype.nativeElement = null;
cocktail.core.html.AbstractHTMLElement.prototype._id = null;
cocktail.core.html.AbstractHTMLElement.prototype.id = null;
cocktail.core.html.AbstractHTMLElement.prototype.offsetParent = null;
cocktail.core.html.AbstractHTMLElement.prototype.offsetWidth = null;
cocktail.core.html.AbstractHTMLElement.prototype.offsetHeight = null;
cocktail.core.html.AbstractHTMLElement.prototype.offsetLeft = null;
cocktail.core.html.AbstractHTMLElement.prototype.offsetTop = null;
cocktail.core.html.AbstractHTMLElement.prototype.clientWidth = null;
cocktail.core.html.AbstractHTMLElement.prototype.clientHeight = null;
cocktail.core.html.AbstractHTMLElement.prototype.clientLeft = null;
cocktail.core.html.AbstractHTMLElement.prototype.clientTop = null;
cocktail.core.html.AbstractHTMLElement.prototype._coreStyle = null;
cocktail.core.html.AbstractHTMLElement.prototype.coreStyle = null;
cocktail.core.html.AbstractHTMLElement.prototype._style = null;
cocktail.core.html.AbstractHTMLElement.prototype.style = null;
cocktail.core.html.AbstractHTMLElement.prototype.init = function() {
	this.initNativeElement();
	this.initMouse();
	this.initKeyboard();
	this.initCoreStyle();
	this.initStyle();
	this.initId();
}
cocktail.core.html.AbstractHTMLElement.prototype.initNativeElement = function() {
	this._nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.semantic(this._tagName));
}
cocktail.core.html.AbstractHTMLElement.prototype.initMouse = function() {
	this._mouse = new cocktail.port.browser.Mouse(this);
}
cocktail.core.html.AbstractHTMLElement.prototype.initKeyboard = function() {
	this._keyboard = new cocktail.port.browser.Keyboard(this);
}
cocktail.core.html.AbstractHTMLElement.prototype.initCoreStyle = function() {
	this._coreStyle = new cocktail.core.style.ContainerCoreStyle(this);
}
cocktail.core.html.AbstractHTMLElement.prototype.initStyle = function() {
	this._style = new cocktail.port.browser.Style(this._coreStyle);
}
cocktail.core.html.AbstractHTMLElement.prototype.initId = function() {
	this._id = new cocktail.core.dom.Attr("id");
	this.setIdAttributeNode(this._id,true);
}
cocktail.core.html.AbstractHTMLElement.prototype.appendChild = function(newChild) {
	cocktail.core.dom.Element.prototype.appendChild.call(this,newChild);
	this._coreStyle.invalidate();
	return newChild;
}
cocktail.core.html.AbstractHTMLElement.prototype.removeChild = function(oldChild) {
	cocktail.core.dom.Element.prototype.removeChild.call(this,oldChild);
	this._coreStyle.invalidate();
	return oldChild;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onClick = function(value) {
	this._onClick = value;
	if(this._onClick == null) this._mouse.set_onClick(null); else this._mouse.set_onClick($closure(this,"onClickCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onClick = function() {
	return this._onClick;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onMouseDown = function(value) {
	this._onMouseDown = value;
	if(this._onMouseDown == null) this._mouse.setOnMouseDown(null); else this._mouse.setOnMouseDown($closure(this,"onMouseDownCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onMouseDown = function() {
	return this._onMouseDown;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onMouseUp = function(value) {
	this._onMouseUp = value;
	if(this._onMouseUp == null) this._mouse.setOnMouseUp(null); else this._mouse.setOnMouseUp($closure(this,"onMouseUpCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onMouseUp = function() {
	return this._onMouseUp;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onMouseOver = function(value) {
	this._onMouseOver = value;
	if(this._onMouseOver == null) this._mouse.setOnMouseOver(null); else this._mouse.setOnMouseOver($closure(this,"onMouseOverCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onMouseOver = function() {
	return this._onMouseOver;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onMouseOut = function(value) {
	this._onMouseOut = value;
	if(this._onMouseOut == null) this._mouse.setOnMouseOut(null); else this._mouse.setOnMouseOut($closure(this,"onMouseOutCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onMouseOut = function() {
	return this._onMouseOut;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onMouseMove = function(value) {
	this._onMouseMove = value;
	if(this._onMouseMove == null) this._mouse.setOnMouseMove(null); else this._mouse.setOnMouseMove($closure(this,"onMouseMoveCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onMouseMove = function() {
	return this._onMouseMove;
}
cocktail.core.html.AbstractHTMLElement.prototype.onClickCallback = function(mouseEvent) {
	this._onClick(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.onMouseDownCallback = function(mouseEvent) {
	this._onMouseDown(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.onMouseUpCallback = function(mouseEvent) {
	this._onMouseUp(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.onMouseMoveCallback = function(mouseEvent) {
	this._onMouseMove(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.onMouseOverCallback = function(mouseEvent) {
	this._onMouseOver(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.onMouseOutCallback = function(mouseEvent) {
	this._onMouseOut(mouseEvent);
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onKeyDown = function(value) {
	this._onKeyDown = value;
	if(this._onKeyDown == null) this._keyboard.setOnKeyDown(null); else this._keyboard.setOnKeyDown($closure(this,"onKeyDownCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onKeyDown = function() {
	return this._keyboard.getOnKeyDown();
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onKeyUp = function(value) {
	this._onKeyUp = value;
	if(this._onKeyUp == null) this._keyboard.setOnKeyUp(null); else this._keyboard.setOnKeyUp($closure(this,"onKeyUpCallback"));
	return value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onKeyUp = function() {
	return this._keyboard.getOnKeyUp();
}
cocktail.core.html.AbstractHTMLElement.prototype.onKeyDownCallback = function(keyEventData) {
	this._onKeyDown(keyEventData);
}
cocktail.core.html.AbstractHTMLElement.prototype.onKeyUpCallback = function(keyEventData) {
	this._onKeyUp(keyEventData);
}
cocktail.core.html.AbstractHTMLElement.prototype.focus = function() {
}
cocktail.core.html.AbstractHTMLElement.prototype.blur = function() {
}
cocktail.core.html.AbstractHTMLElement.prototype.get_isDefaultFocusable = function() {
	return false;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onFocus = function(value) {
	return this._onFocus = value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onFocus = function() {
	return this._onFocus;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onBlur = function(value) {
	return this._onBlur = value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onBlur = function() {
	return this._onBlur;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_tabIndex = function(value) {
	return this._tabIndex = value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_tabIndex = function() {
	return this._tabIndex;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_onScroll = function(value) {
	return this._onScroll = value;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_onScroll = function() {
	return this._onScroll;
}
cocktail.core.html.AbstractHTMLElement.prototype.onScrollCallback = function(event) {
	if(this._onScroll != null) this._onScroll(event);
}
cocktail.core.html.AbstractHTMLElement.prototype.get_scrollHeight = function() {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_scrollWidth = function() {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_scrollLeft = function(value) {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_scrollLeft = function() {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.set_scrollTop = function(value) {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_scrollTop = function() {
	return -1;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_nativeElement = function() {
	return this._nativeElement;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_id = function() {
	return this._id.get_value();
}
cocktail.core.html.AbstractHTMLElement.prototype.set_id = function(value) {
	return this._id.set_value(value);
}
cocktail.core.html.AbstractHTMLElement.prototype.get_offsetParent = function() {
	return this._coreStyle.getFirstPositionedAncestor();
}
cocktail.core.html.AbstractHTMLElement.prototype.get_offsetWidth = function() {
	this._coreStyle.invalidate(true);
	var computedStyle = this._coreStyle.getComputedStyle();
	return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_offsetHeight = function() {
	this._coreStyle.invalidate(true);
	var computedStyle = this._coreStyle.getComputedStyle();
	return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_offsetLeft = function() {
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
cocktail.core.html.AbstractHTMLElement.prototype.get_offsetTop = function() {
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
cocktail.core.html.AbstractHTMLElement.prototype.get_clientWidth = function() {
	this._coreStyle.invalidate(true);
	var computedStyle = this._coreStyle.getComputedStyle();
	return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_clientHeight = function() {
	this._coreStyle.invalidate(true);
	var computedStyle = this._coreStyle.getComputedStyle();
	return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_clientTop = function() {
	this._coreStyle.invalidate(true);
	return 0;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_clientLeft = function() {
	this._coreStyle.invalidate(true);
	return 0;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_coreStyle = function() {
	return this._coreStyle;
}
cocktail.core.html.AbstractHTMLElement.prototype.get_style = function() {
	return this._style;
}
cocktail.core.html.AbstractHTMLElement.prototype.__class__ = cocktail.core.html.AbstractHTMLElement;
cocktail.core.html.AbstractHTMLElement.__interfaces__ = [cocktail.core.event.IEventTarget];
if(!cocktail.port) cocktail.port = {}
if(!cocktail.port.browser) cocktail.port.browser = {}
cocktail.port.browser.HTMLElement = function(tagName) {
	if( tagName === $_ ) return;
	cocktail.core.html.AbstractHTMLElement.call(this,tagName);
}
cocktail.port.browser.HTMLElement.__name__ = ["cocktail","port","browser","HTMLElement"];
cocktail.port.browser.HTMLElement.__super__ = cocktail.core.html.AbstractHTMLElement;
for(var k in cocktail.core.html.AbstractHTMLElement.prototype ) cocktail.port.browser.HTMLElement.prototype[k] = cocktail.core.html.AbstractHTMLElement.prototype[k];
cocktail.port.browser.HTMLElement.prototype.removeChild = function(oldChild) {
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
cocktail.port.browser.HTMLElement.prototype.appendChild = function(newChild) {
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
cocktail.port.browser.HTMLElement.prototype.insertBefore = function(newChild,refChild) {
	cocktail.core.html.AbstractHTMLElement.prototype.insertBefore.call(this,newChild,refChild);
	this._nativeElement.insertBefore(newChild.nativeElement,refChild.nativeElement);
	return newChild;
}
cocktail.port.browser.HTMLElement.prototype.replaceChild = function(newChild,oldChild) {
	cocktail.core.html.AbstractHTMLElement.prototype.replaceChild.call(this,newChild,oldChild);
	this._nativeElement.replaceChild(newChild.nativeElement,refChild.nativeElement);
	return oldChild;
}
cocktail.port.browser.HTMLElement.prototype.get_offsetWidth = function() {
	return this._nativeElement.offsetWidth;
}
cocktail.port.browser.HTMLElement.prototype.get_offsetHeight = function() {
	return this._nativeElement.offsetHeight;
}
cocktail.port.browser.HTMLElement.prototype.get_offsetLeft = function() {
	return this._nativeElement.offsetLeft;
}
cocktail.port.browser.HTMLElement.prototype.get_offsetTop = function() {
	return this._nativeElement.offsetTop;
}
cocktail.port.browser.HTMLElement.prototype.get_clientWidth = function() {
	return this._nativeElement.clientWidth;
}
cocktail.port.browser.HTMLElement.prototype.get_clientHeight = function() {
	return this._nativeElement.clientHeight;
}
cocktail.port.browser.HTMLElement.prototype.get_clientLeft = function() {
	return this._nativeElement.clientLeft;
}
cocktail.port.browser.HTMLElement.prototype.get_clientTop = function() {
	return this._nativeElement.clientTop;
}
cocktail.port.browser.HTMLElement.prototype.set_scrollTop = function(value) {
	return this._nativeElement.scrollTop = value;
}
cocktail.port.browser.HTMLElement.prototype.get_scrollTop = function() {
	return this._nativeElement.scrollTop;
}
cocktail.port.browser.HTMLElement.prototype.set_scrollLeft = function(value) {
	return this._nativeElement.scrollLeft = value;
}
cocktail.port.browser.HTMLElement.prototype.get_scrollLeft = function() {
	return this._nativeElement.scrollLeft;
}
cocktail.port.browser.HTMLElement.prototype.get_scrollWidth = function() {
	return this._nativeElement.scrollWidth;
}
cocktail.port.browser.HTMLElement.prototype.get_scrollHeight = function() {
	return this._nativeElement.scrollHeight;
}
cocktail.port.browser.HTMLElement.prototype.set_onFocus = function(value) {
	if(value == null) this._nativeElement.removeEventListener("focus",$closure(this,"onNativeFocus")); else this._nativeElement.addEventListener("focus",$closure(this,"onNativeFocus"));
	return this._onFocus = value;
}
cocktail.port.browser.HTMLElement.prototype.set_onBlur = function(value) {
	if(value == null) this._nativeElement.removeEventListener("blur",$closure(this,"onNativeBlur")); else this._nativeElement.addEventListener("blur",$closure(this,"onNativeBlur"));
	return this._onBlur = value;
}
cocktail.port.browser.HTMLElement.prototype.set_tabIndex = function(value) {
	cocktail.core.html.AbstractHTMLElement.prototype.set_tabIndex.call(this,value);
	this._nativeElement.tabIndex = value;
	return this._tabIndex;
}
cocktail.port.browser.HTMLElement.prototype.focus = function() {
	this._nativeElement.focus();
}
cocktail.port.browser.HTMLElement.prototype.blur = function() {
	this._nativeElement.blur();
}
cocktail.port.browser.HTMLElement.prototype.onNativeFocus = function(event) {
	if(this._onFocus != null) this._onFocus(new cocktail.core.event.Event("focus",this));
}
cocktail.port.browser.HTMLElement.prototype.onNativeBlur = function(event) {
	if(this._onBlur != null) this._onBlur(new cocktail.core.event.Event("blur",this));
}
cocktail.port.browser.HTMLElement.prototype.set_onScroll = function(value) {
	this._nativeElement.removeEventListener("scroll",$closure(this,"onNativeScroll"));
	this._onScroll = value;
	if(this._onScroll != null) this._nativeElement.addEventListener("scroll",$closure(this,"onNativeScroll"));
	return value;
}
cocktail.port.browser.HTMLElement.prototype.onNativeScroll = function(event) {
	this.onScrollCallback(new cocktail.core.event.Event("scroll",this));
}
cocktail.port.browser.HTMLElement.prototype.__class__ = cocktail.port.browser.HTMLElement;
cocktail.core.html.AbstractHTMLAnchorElement = function(p) {
	if( p === $_ ) return;
	cocktail.port.browser.HTMLElement.call(this,"a");
	this._target = "_self";
}
cocktail.core.html.AbstractHTMLAnchorElement.__name__ = ["cocktail","core","html","AbstractHTMLAnchorElement"];
cocktail.core.html.AbstractHTMLAnchorElement.__super__ = cocktail.port.browser.HTMLElement;
for(var k in cocktail.port.browser.HTMLElement.prototype ) cocktail.core.html.AbstractHTMLAnchorElement.prototype[k] = cocktail.port.browser.HTMLElement.prototype[k];
cocktail.core.html.AbstractHTMLAnchorElement.prototype._href = null;
cocktail.core.html.AbstractHTMLAnchorElement.prototype.href = null;
cocktail.core.html.AbstractHTMLAnchorElement.prototype._target = null;
cocktail.core.html.AbstractHTMLAnchorElement.prototype.target = null;
cocktail.core.html.AbstractHTMLAnchorElement.prototype.initNativeElement = function() {
	this._nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.anchor);
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_onMouseDown = function(value) {
	this._onMouseDown = value;
	this._mouse.setOnMouseDown($closure(this,"onMouseDownCallback"));
	return this._onMouseDown;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_onMouseOver = function(value) {
	this._onMouseOver = value;
	this._mouse.setOnMouseOver($closure(this,"onMouseOverCallback"));
	return this._onMouseOver;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_onMouseOut = function(value) {
	this._onMouseOut = value;
	this._mouse.setOnMouseOut($closure(this,"onMouseOutCallback"));
	return this._onMouseOut;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.onMouseDownCallback = function(mouseEvent) {
	if(this._onMouseDown != null) this._onMouseDown(mouseEvent);
	if(mouseEvent.get_defaultPrevented() == false) this.openDocument();
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.onMouseOverCallback = function(mouseEvent) {
	if(this._onMouseOver != null) this._onMouseOver(mouseEvent);
	this.displayPointerCursor();
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.onMouseOutCallback = function(mouseEvent) {
	if(this._onMouseOut != null) this._onMouseOut(mouseEvent);
	this.hidePointerCursor();
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.openDocument = function() {
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.displayPointerCursor = function() {
	cocktail.core.mouse.MouseCursorManager.setMouseCursor(cocktail.core.mouse.MouseCursorValue["native"](cocktail.core.mouse.NativeOSMouseCursorValue.pointer));
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.hidePointerCursor = function() {
	cocktail.core.mouse.MouseCursorManager.setMouseCursor(cocktail.core.mouse.MouseCursorValue.cssAuto);
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_href = function(value) {
	this._href = value;
	this.set_onMouseDown(this._onMouseDown);
	this.set_onMouseOver(this._onMouseOver);
	this.set_onMouseOut(this._onMouseOut);
	return value;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.get_href = function() {
	return this._href;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_target = function(value) {
	this._target = value;
	this.set_onMouseDown(this._onMouseDown);
	this.set_onMouseOver(this._onMouseOver);
	this.set_onMouseOut(this._onMouseOut);
	return value;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.get_target = function() {
	return this._target;
}
cocktail.core.html.AbstractHTMLAnchorElement.prototype.__class__ = cocktail.core.html.AbstractHTMLAnchorElement;
cocktail.port.browser.HTMLAnchorElement = function(p) {
	if( p === $_ ) return;
	cocktail.core.html.AbstractHTMLAnchorElement.call(this);
}
cocktail.port.browser.HTMLAnchorElement.__name__ = ["cocktail","port","browser","HTMLAnchorElement"];
cocktail.port.browser.HTMLAnchorElement.__super__ = cocktail.core.html.AbstractHTMLAnchorElement;
for(var k in cocktail.core.html.AbstractHTMLAnchorElement.prototype ) cocktail.port.browser.HTMLAnchorElement.prototype[k] = cocktail.core.html.AbstractHTMLAnchorElement.prototype[k];
cocktail.port.browser.HTMLAnchorElement.prototype.set_href = function(value) {
	this._nativeElement.href = value;
	cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_href.call(this,value);
	return value;
}
cocktail.port.browser.HTMLAnchorElement.prototype.set_target = function(value) {
	this._nativeElement.target = value;
	cocktail.core.html.AbstractHTMLAnchorElement.prototype.set_target.call(this,value);
	return value;
}
cocktail.port.browser.HTMLAnchorElement.prototype.__class__ = cocktail.port.browser.HTMLAnchorElement;
if(!cocktail.core.style) cocktail.core.style = {}
cocktail.core.style.CoreStyle = function(htmlElement) {
	if( htmlElement === $_ ) return;
	this._htmlElement = htmlElement;
	this._isDirty = false;
	this.initDefaultStyleValues();
}
cocktail.core.style.CoreStyle.__name__ = ["cocktail","core","style","CoreStyle"];
cocktail.core.style.CoreStyle.getDefaultStyle = function() {
	return { fontFamily : ["serif"], color : cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.black)};
}
cocktail.core.style.CoreStyle.prototype._display = null;
cocktail.core.style.CoreStyle.prototype.display = null;
cocktail.core.style.CoreStyle.prototype._position = null;
cocktail.core.style.CoreStyle.prototype.position = null;
cocktail.core.style.CoreStyle.prototype._cssFloat = null;
cocktail.core.style.CoreStyle.prototype.cssFloat = null;
cocktail.core.style.CoreStyle.prototype._clear = null;
cocktail.core.style.CoreStyle.prototype.clear = null;
cocktail.core.style.CoreStyle.prototype._transformOrigin = null;
cocktail.core.style.CoreStyle.prototype.transformOrigin = null;
cocktail.core.style.CoreStyle.prototype._transform = null;
cocktail.core.style.CoreStyle.prototype.transform = null;
cocktail.core.style.CoreStyle.prototype._marginLeft = null;
cocktail.core.style.CoreStyle.prototype.marginLeft = null;
cocktail.core.style.CoreStyle.prototype._marginRight = null;
cocktail.core.style.CoreStyle.prototype.marginRight = null;
cocktail.core.style.CoreStyle.prototype._marginTop = null;
cocktail.core.style.CoreStyle.prototype.marginTop = null;
cocktail.core.style.CoreStyle.prototype._marginBottom = null;
cocktail.core.style.CoreStyle.prototype.marginBottom = null;
cocktail.core.style.CoreStyle.prototype._paddingLeft = null;
cocktail.core.style.CoreStyle.prototype.paddingLeft = null;
cocktail.core.style.CoreStyle.prototype._paddingRight = null;
cocktail.core.style.CoreStyle.prototype.paddingRight = null;
cocktail.core.style.CoreStyle.prototype._paddingTop = null;
cocktail.core.style.CoreStyle.prototype.paddingTop = null;
cocktail.core.style.CoreStyle.prototype._paddingBottom = null;
cocktail.core.style.CoreStyle.prototype.paddingBottom = null;
cocktail.core.style.CoreStyle.prototype._width = null;
cocktail.core.style.CoreStyle.prototype.width = null;
cocktail.core.style.CoreStyle.prototype._height = null;
cocktail.core.style.CoreStyle.prototype.height = null;
cocktail.core.style.CoreStyle.prototype._minHeight = null;
cocktail.core.style.CoreStyle.prototype.minHeight = null;
cocktail.core.style.CoreStyle.prototype._maxHeight = null;
cocktail.core.style.CoreStyle.prototype.maxHeight = null;
cocktail.core.style.CoreStyle.prototype._minWidth = null;
cocktail.core.style.CoreStyle.prototype.minWidth = null;
cocktail.core.style.CoreStyle.prototype._maxWidth = null;
cocktail.core.style.CoreStyle.prototype.maxWidth = null;
cocktail.core.style.CoreStyle.prototype._top = null;
cocktail.core.style.CoreStyle.prototype.top = null;
cocktail.core.style.CoreStyle.prototype._left = null;
cocktail.core.style.CoreStyle.prototype.left = null;
cocktail.core.style.CoreStyle.prototype._bottom = null;
cocktail.core.style.CoreStyle.prototype.bottom = null;
cocktail.core.style.CoreStyle.prototype._right = null;
cocktail.core.style.CoreStyle.prototype.right = null;
cocktail.core.style.CoreStyle.prototype._backgroundColor = null;
cocktail.core.style.CoreStyle.prototype.backgroundColor = null;
cocktail.core.style.CoreStyle.prototype._backgroundImage = null;
cocktail.core.style.CoreStyle.prototype.backgroundImage = null;
cocktail.core.style.CoreStyle.prototype._backgroundRepeat = null;
cocktail.core.style.CoreStyle.prototype.backgroundRepeat = null;
cocktail.core.style.CoreStyle.prototype._backgroundOrigin = null;
cocktail.core.style.CoreStyle.prototype.backgroundOrigin = null;
cocktail.core.style.CoreStyle.prototype._backgroundSize = null;
cocktail.core.style.CoreStyle.prototype.backgroundSize = null;
cocktail.core.style.CoreStyle.prototype._backgroundPosition = null;
cocktail.core.style.CoreStyle.prototype.backgroundPosition = null;
cocktail.core.style.CoreStyle.prototype._backgroundClip = null;
cocktail.core.style.CoreStyle.prototype.backgroundClip = null;
cocktail.core.style.CoreStyle.prototype._fontSize = null;
cocktail.core.style.CoreStyle.prototype.fontSize = null;
cocktail.core.style.CoreStyle.prototype._fontWeight = null;
cocktail.core.style.CoreStyle.prototype.fontWeight = null;
cocktail.core.style.CoreStyle.prototype._fontStyle = null;
cocktail.core.style.CoreStyle.prototype.fontStyle = null;
cocktail.core.style.CoreStyle.prototype._fontFamily = null;
cocktail.core.style.CoreStyle.prototype.fontFamily = null;
cocktail.core.style.CoreStyle.prototype._fontVariant = null;
cocktail.core.style.CoreStyle.prototype.fontVariant = null;
cocktail.core.style.CoreStyle.prototype._color = null;
cocktail.core.style.CoreStyle.prototype.color = null;
cocktail.core.style.CoreStyle.prototype._lineHeight = null;
cocktail.core.style.CoreStyle.prototype.lineHeight = null;
cocktail.core.style.CoreStyle.prototype._textTransform = null;
cocktail.core.style.CoreStyle.prototype.textTransform = null;
cocktail.core.style.CoreStyle.prototype._letterSpacing = null;
cocktail.core.style.CoreStyle.prototype.letterSpacing = null;
cocktail.core.style.CoreStyle.prototype._wordSpacing = null;
cocktail.core.style.CoreStyle.prototype.wordSpacing = null;
cocktail.core.style.CoreStyle.prototype._whiteSpace = null;
cocktail.core.style.CoreStyle.prototype.whiteSpace = null;
cocktail.core.style.CoreStyle.prototype._textAlign = null;
cocktail.core.style.CoreStyle.prototype.textAlign = null;
cocktail.core.style.CoreStyle.prototype._textIndent = null;
cocktail.core.style.CoreStyle.prototype.textIndent = null;
cocktail.core.style.CoreStyle.prototype._verticalAlign = null;
cocktail.core.style.CoreStyle.prototype.verticalAlign = null;
cocktail.core.style.CoreStyle.prototype._opacity = null;
cocktail.core.style.CoreStyle.prototype.opacity = null;
cocktail.core.style.CoreStyle.prototype._visibility = null;
cocktail.core.style.CoreStyle.prototype.visibility = null;
cocktail.core.style.CoreStyle.prototype._overflowX = null;
cocktail.core.style.CoreStyle.prototype.overflowX = null;
cocktail.core.style.CoreStyle.prototype._overflowY = null;
cocktail.core.style.CoreStyle.prototype.overflowY = null;
cocktail.core.style.CoreStyle.prototype._cursor = null;
cocktail.core.style.CoreStyle.prototype.cursor = null;
cocktail.core.style.CoreStyle.prototype._computedStyle = null;
cocktail.core.style.CoreStyle.prototype.computedStyle = null;
cocktail.core.style.CoreStyle.prototype._htmlElement = null;
cocktail.core.style.CoreStyle.prototype.htmlElement = null;
cocktail.core.style.CoreStyle.prototype._fontMetrics = null;
cocktail.core.style.CoreStyle.prototype.fontMetrics = null;
cocktail.core.style.CoreStyle.prototype._isDirty = null;
cocktail.core.style.CoreStyle.prototype._elementRenderer = null;
cocktail.core.style.CoreStyle.prototype.elementRenderer = null;
cocktail.core.style.CoreStyle.prototype.initDefaultStyleValues = function() {
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
cocktail.core.style.CoreStyle.prototype.initComputedStyles = function() {
	this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.core.style.Clear.none, cssFloat : cocktail.core.style.CSSFloat.none, display : cocktail.core.style.Display.block, position : cocktail.core.style.Position.cssStatic, verticalAlign : 0.0, fontSize : 16.0, lineHeight : 14.0, fontWeight : cocktail.core.style.FontWeight.normal, fontStyle : cocktail.core.style.FontStyle.normal, fontFamily : ["serif"], fontVariant : cocktail.core.style.FontVariant.normal, textTransform : cocktail.core.style.TextTransform.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.core.style.WhiteSpace.normal, textAlign : cocktail.core.style.TextAlign.left, color : { color : 0, alpha : 1.0}, visibility : true, opacity : 1.0, overflowX : cocktail.core.style.Overflow.visible, overflowY : cocktail.core.style.Overflow.visible, transformOrigin : { x : 0.0, y : 0.0}, transform : new cocktail.core.geom.Matrix(), backgroundColor : { color : 0, alpha : 1.0}, backgroundSize : [], backgroundOrigin : [], backgroundImage : [], backgroundClip : [], backgroundPosition : [], backgroundRepeat : [], cursor : cocktail.core.style.Cursor.cssDefault};
}
cocktail.core.style.CoreStyle.prototype.applyDefaultHTMLStyles = function() {
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
cocktail.core.style.CoreStyle.prototype.createElementRenderer = function(parentElementRenderer) {
	var elementRenderer = new cocktail.core.renderer.EmbeddedBoxRenderer(this);
	elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
	parentElementRenderer.appendChild(elementRenderer);
	return elementRenderer;
}
cocktail.core.style.CoreStyle.prototype.getLayerRenderer = function(elementRenderer,parentElementRenderer) {
	var layerRenderer;
	if(this.isPositioned() == true) layerRenderer = new cocktail.core.renderer.LayerRenderer(elementRenderer); else layerRenderer = parentElementRenderer.getLayerRenderer();
	return layerRenderer;
}
cocktail.core.style.CoreStyle.prototype.layout = function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
}
cocktail.core.style.CoreStyle.prototype.flow = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext,parentElementRenderer) {
	if(this._elementRenderer != null && parentElementRenderer != null) parentElementRenderer.removeChild(this._elementRenderer);
	if(this.isNotDisplayed() == true) return;
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
cocktail.core.style.CoreStyle.prototype.positionElement = function(lastPositionedHTMLElementData,viewportData,staticPosition) {
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
cocktail.core.style.CoreStyle.prototype.scheduleLayout = function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData) {
	var layoutDelegate = $closure(this,"layout");
	haxe.Timer.delay(function() {
		layoutDelegate(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,null);
	},1);
}
cocktail.core.style.CoreStyle.prototype.flowChildren = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
}
cocktail.core.style.CoreStyle.prototype.insertHTMLElement = function(formattingContext,lastPositionedHTMLElementData,viewportData) {
	if(this.isPositioned() == false) formattingContext.insertElement(this._elementRenderer); else {
		var staticPosition = formattingContext.getStaticPosition(this._elementRenderer);
		if(this.isRelativePositioned() == true) formattingContext.insertElement(this._elementRenderer);
		var positionedHTMLElementData = { staticPosition : staticPosition, coreStyle : this};
		lastPositionedHTMLElementData.children.push(positionedHTMLElementData);
	}
}
cocktail.core.style.CoreStyle.prototype.invalidate = function(immediate) {
	if(immediate == null) immediate = false;
	if(this._isDirty == false || immediate == true) {
		this._isDirty = true;
		if(this._htmlElement.get_parentNode() != null) {
			var parent = this._htmlElement.get_parentNode();
			parent.get_coreStyle().invalidate(immediate);
		}
	}
}
cocktail.core.style.CoreStyle.prototype.invalidateText = function() {
	this._fontMetrics = null;
	this.invalidate();
}
cocktail.core.style.CoreStyle.prototype.computeDisplayStyles = function() {
	cocktail.core.style.computer.DisplayStylesComputer.compute(this);
}
cocktail.core.style.CoreStyle.prototype.computeBackgroundStyles = function() {
	cocktail.core.style.computer.BackgroundStylesComputer.compute(this);
}
cocktail.core.style.CoreStyle.prototype.computeHTMLElementStyles = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData) {
	this.computeDisplayStyles();
	this.computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
	this.computeBoxModelStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
}
cocktail.core.style.CoreStyle.prototype.computeVisualEffectStyles = function() {
	cocktail.core.style.computer.VisualEffectStylesComputer.compute(this);
}
cocktail.core.style.CoreStyle.prototype.computeTextAndFontStyles = function(containingHTMLElementData,containingHTMLElementFontMetricsData) {
	cocktail.core.style.computer.FontAndTextStylesComputer.compute(this,containingHTMLElementData,containingHTMLElementFontMetricsData);
}
cocktail.core.style.CoreStyle.prototype.computeBoxModelStyles = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
	var boxComputer = this.getBoxStylesComputer();
	var containingBlockDimensions = this.getContainingHTMLElementData(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
	boxComputer.measure(this,containingBlockDimensions);
}
cocktail.core.style.CoreStyle.prototype.getBoxStylesComputer = function() {
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
cocktail.core.style.CoreStyle.prototype.getContainingHTMLElementData = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
	var containingBlockDimensions;
	if(this.isPositioned() == true) {
		if(this._computedStyle.position == cocktail.core.style.Position.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto}; else if(this._computedStyle.position == cocktail.core.style.Position.absolute) containingBlockDimensions = { width : lastPositionedHTMLElementData.width, height : lastPositionedHTMLElementData.height, isHeightAuto : lastPositionedHTMLElementData.isHeightAuto, isWidthAuto : lastPositionedHTMLElementData.isWidthAuto}; else containingBlockDimensions = containingHTMLElementData;
	} else containingBlockDimensions = containingHTMLElementData;
	return containingBlockDimensions;
}
cocktail.core.style.CoreStyle.prototype.isFloat = function() {
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
cocktail.core.style.CoreStyle.prototype.isPositioned = function() {
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
cocktail.core.style.CoreStyle.prototype.isRelativePositioned = function() {
	return this._computedStyle.position == cocktail.core.style.Position.relative;
}
cocktail.core.style.CoreStyle.prototype.childrenInline = function() {
	return false;
}
cocktail.core.style.CoreStyle.prototype.isInlineLevel = function() {
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
cocktail.core.style.CoreStyle.prototype.establishesNewFormattingContext = function() {
	return false;
}
cocktail.core.style.CoreStyle.prototype.getFirstPositionedAncestor = function() {
	if(this._htmlElement.get_parentNode() == null) return null;
	var parent = this._htmlElement.get_parentNode();
	var isOffsetParent = parent.get_coreStyle().isOffsetParent();
	while(isOffsetParent == false) if(parent.get_parentNode() != null) {
		parent = parent.get_parentNode();
		isOffsetParent = parent.get_coreStyle().isOffsetParent();
	} else isOffsetParent = true;
	return parent;
}
cocktail.core.style.CoreStyle.prototype.isOffsetParent = function() {
	return this.isPositioned();
}
cocktail.core.style.CoreStyle.prototype.isClear = function() {
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
cocktail.core.style.CoreStyle.prototype.isNotDisplayed = function() {
	return this._computedStyle.display == cocktail.core.style.Display.none;
}
cocktail.core.style.CoreStyle.prototype.getFirstPositionedAncestorData = function() {
	var firstPositionedAncestorData;
	var firstPositionedAncestor = this.getFirstPositionedAncestor();
	if(firstPositionedAncestor != null) {
		var firstPositionedAncestorStyle = firstPositionedAncestor.get_coreStyle();
		firstPositionedAncestorData = firstPositionedAncestorStyle.getContainerHTMLElementData();
	} else firstPositionedAncestorData = this.getWindowData();
	return firstPositionedAncestorData;
}
cocktail.core.style.CoreStyle.prototype.getWindowData = function() {
	var windowData = { isHeightAuto : false, isWidthAuto : false, width : cocktail.Lib.get_window().get_innerWidth(), height : cocktail.Lib.get_window().get_innerHeight()};
	return windowData;
}
cocktail.core.style.CoreStyle.prototype.getElementRenderer = function() {
	return this._elementRenderer;
}
cocktail.core.style.CoreStyle.prototype.getFontMetricsData = function() {
	if(this._fontMetrics == null) {
		var fontManager = new cocktail.port.browser.FontManager();
		this._fontMetrics = fontManager.getFontMetrics(cocktail.core.unit.UnitManager.getCSSFontFamily(this._computedStyle.fontFamily),this._computedStyle.fontSize);
	}
	return this._fontMetrics;
}
cocktail.core.style.CoreStyle.prototype.getComputedStyle = function() {
	return this._computedStyle;
}
cocktail.core.style.CoreStyle.prototype.setComputedStyle = function(value) {
	return this._computedStyle = value;
}
cocktail.core.style.CoreStyle.prototype.get_htmlElement = function() {
	return this._htmlElement;
}
cocktail.core.style.CoreStyle.prototype.setWidth = function(value) {
	this.invalidate();
	return this._width = value;
}
cocktail.core.style.CoreStyle.prototype.setMarginLeft = function(value) {
	this.invalidate();
	return this._marginLeft = value;
}
cocktail.core.style.CoreStyle.prototype.setMarginRight = function(value) {
	this.invalidate();
	return this._marginRight = value;
}
cocktail.core.style.CoreStyle.prototype.setMarginTop = function(value) {
	this.invalidate();
	return this._marginTop = value;
}
cocktail.core.style.CoreStyle.prototype.setMarginBottom = function(value) {
	this.invalidate();
	return this._marginBottom = value;
}
cocktail.core.style.CoreStyle.prototype.setPaddingLeft = function(value) {
	this.invalidate();
	return this._paddingLeft = value;
}
cocktail.core.style.CoreStyle.prototype.setPaddingRight = function(value) {
	this.invalidate();
	return this._paddingRight = value;
}
cocktail.core.style.CoreStyle.prototype.setPaddingTop = function(value) {
	this.invalidate();
	return this._paddingTop = value;
}
cocktail.core.style.CoreStyle.prototype.setPaddingBottom = function(value) {
	this.invalidate();
	return this._paddingBottom = value;
}
cocktail.core.style.CoreStyle.prototype.setDisplay = function(value) {
	this.invalidate();
	return this._display = value;
}
cocktail.core.style.CoreStyle.prototype.setPosition = function(value) {
	this.invalidate();
	return this._position = value;
}
cocktail.core.style.CoreStyle.prototype.setHeight = function(value) {
	this.invalidate();
	return this._height = value;
}
cocktail.core.style.CoreStyle.prototype.setMinHeight = function(value) {
	this.invalidate();
	return this._minHeight = value;
}
cocktail.core.style.CoreStyle.prototype.setMaxHeight = function(value) {
	this.invalidate();
	return this._maxHeight = value;
}
cocktail.core.style.CoreStyle.prototype.setMinWidth = function(value) {
	this.invalidate();
	return this._minWidth = value;
}
cocktail.core.style.CoreStyle.prototype.setMaxWidth = function(value) {
	this.invalidate();
	return this._maxWidth = value;
}
cocktail.core.style.CoreStyle.prototype.setTop = function(value) {
	this.invalidate();
	return this._top = value;
}
cocktail.core.style.CoreStyle.prototype.setLeft = function(value) {
	this.invalidate();
	return this._left = value;
}
cocktail.core.style.CoreStyle.prototype.setBottom = function(value) {
	this.invalidate();
	return this._bottom = value;
}
cocktail.core.style.CoreStyle.prototype.setRight = function(value) {
	this.invalidate();
	return this._right = value;
}
cocktail.core.style.CoreStyle.prototype.setCSSFloat = function(value) {
	this.invalidate();
	return this._cssFloat = value;
}
cocktail.core.style.CoreStyle.prototype.setClear = function(value) {
	this.invalidate();
	return this._clear = value;
}
cocktail.core.style.CoreStyle.prototype.setFontSize = function(value) {
	this.invalidateText();
	return this._fontSize = value;
}
cocktail.core.style.CoreStyle.prototype.setFontWeight = function(value) {
	this.invalidateText();
	return this._fontWeight = value;
}
cocktail.core.style.CoreStyle.prototype.setFontStyle = function(value) {
	this.invalidateText();
	return this._fontStyle = value;
}
cocktail.core.style.CoreStyle.prototype.setFontFamily = function(value) {
	this.invalidateText();
	return this._fontFamily = value;
}
cocktail.core.style.CoreStyle.prototype.setFontVariant = function(value) {
	this.invalidateText();
	return this._fontVariant = value;
}
cocktail.core.style.CoreStyle.prototype.setTextTransform = function(value) {
	this.invalidateText();
	return this._textTransform = value;
}
cocktail.core.style.CoreStyle.prototype.setLetterSpacing = function(value) {
	this.invalidateText();
	return this._letterSpacing = value;
}
cocktail.core.style.CoreStyle.prototype.setWordSpacing = function(value) {
	this.invalidate();
	return this._wordSpacing = value;
}
cocktail.core.style.CoreStyle.prototype.setLineHeight = function(value) {
	this.invalidate();
	return this._lineHeight = value;
}
cocktail.core.style.CoreStyle.prototype.setColor = function(value) {
	this.invalidateText();
	return this._color = value;
}
cocktail.core.style.CoreStyle.prototype.setVerticalAlign = function(value) {
	this.invalidate();
	return this._verticalAlign = value;
}
cocktail.core.style.CoreStyle.prototype.setTextIndent = function(value) {
	this.invalidate();
	return this._textIndent = value;
}
cocktail.core.style.CoreStyle.prototype.setWhiteSpace = function(value) {
	this.invalidate();
	return this._whiteSpace = value;
}
cocktail.core.style.CoreStyle.prototype.setTextAlign = function(value) {
	this.invalidate();
	return this._textAlign = value;
}
cocktail.core.style.CoreStyle.prototype.setOpacity = function(value) {
	this._opacity = value;
	this.invalidate();
	return this._opacity;
}
cocktail.core.style.CoreStyle.prototype.setVisibility = function(value) {
	this._visibility = value;
	this.invalidate();
	return this._visibility;
}
cocktail.core.style.CoreStyle.prototype.setTransformOrigin = function(value) {
	this.invalidate();
	return this._transformOrigin = value;
}
cocktail.core.style.CoreStyle.prototype.setTransform = function(value) {
	this.invalidate();
	return this._transform = value;
}
cocktail.core.style.CoreStyle.prototype.setOverflowX = function(value) {
	this.invalidate();
	return this._overflowX = value;
}
cocktail.core.style.CoreStyle.prototype.setOverflowY = function(value) {
	this.invalidate();
	return this._overflowY = value;
}
cocktail.core.style.CoreStyle.prototype.getOpacity = function() {
	return this._opacity;
}
cocktail.core.style.CoreStyle.prototype.getVisibility = function() {
	return this._visibility;
}
cocktail.core.style.CoreStyle.prototype.getMarginLeft = function() {
	return this._marginLeft;
}
cocktail.core.style.CoreStyle.prototype.getMarginRight = function() {
	return this._marginRight;
}
cocktail.core.style.CoreStyle.prototype.getMarginTop = function() {
	return this._marginTop;
}
cocktail.core.style.CoreStyle.prototype.getMarginBottom = function() {
	return this._marginBottom;
}
cocktail.core.style.CoreStyle.prototype.getPaddingLeft = function() {
	return this._paddingLeft;
}
cocktail.core.style.CoreStyle.prototype.getPaddingRight = function() {
	return this._paddingRight;
}
cocktail.core.style.CoreStyle.prototype.getPaddingTop = function() {
	return this._paddingTop;
}
cocktail.core.style.CoreStyle.prototype.getPaddingBottom = function() {
	return this._paddingBottom;
}
cocktail.core.style.CoreStyle.prototype.getDisplay = function() {
	return this._display;
}
cocktail.core.style.CoreStyle.prototype.getPosition = function() {
	return this._position;
}
cocktail.core.style.CoreStyle.prototype.getWidth = function() {
	return this._width;
}
cocktail.core.style.CoreStyle.prototype.getHeight = function() {
	return this._height;
}
cocktail.core.style.CoreStyle.prototype.getMinHeight = function() {
	return this._minHeight;
}
cocktail.core.style.CoreStyle.prototype.getMaxHeight = function() {
	return this._maxHeight;
}
cocktail.core.style.CoreStyle.prototype.getMinWidth = function() {
	return this._minWidth;
}
cocktail.core.style.CoreStyle.prototype.getMaxWidth = function() {
	return this._maxWidth;
}
cocktail.core.style.CoreStyle.prototype.getTop = function() {
	return this._top;
}
cocktail.core.style.CoreStyle.prototype.getLeft = function() {
	return this._left;
}
cocktail.core.style.CoreStyle.prototype.getBottom = function() {
	return this._bottom;
}
cocktail.core.style.CoreStyle.prototype.getRight = function() {
	return this._right;
}
cocktail.core.style.CoreStyle.prototype.getCSSFloat = function() {
	return this._cssFloat;
}
cocktail.core.style.CoreStyle.prototype.getClear = function() {
	return this._clear;
}
cocktail.core.style.CoreStyle.prototype.getFontSize = function() {
	return this._fontSize;
}
cocktail.core.style.CoreStyle.prototype.getFontWeight = function() {
	return this._fontWeight;
}
cocktail.core.style.CoreStyle.prototype.getFontStyle = function() {
	return this._fontStyle;
}
cocktail.core.style.CoreStyle.prototype.getFontFamily = function() {
	return this._fontFamily;
}
cocktail.core.style.CoreStyle.prototype.getFontVariant = function() {
	return this._fontVariant;
}
cocktail.core.style.CoreStyle.prototype.getTextTransform = function() {
	return this._textTransform;
}
cocktail.core.style.CoreStyle.prototype.getLetterSpacing = function() {
	return this._letterSpacing;
}
cocktail.core.style.CoreStyle.prototype.getColor = function() {
	return this._color;
}
cocktail.core.style.CoreStyle.prototype.getWordSpacing = function() {
	return this._wordSpacing;
}
cocktail.core.style.CoreStyle.prototype.getLineHeight = function() {
	return this._lineHeight;
}
cocktail.core.style.CoreStyle.prototype.getVerticalAlign = function() {
	return this._verticalAlign;
}
cocktail.core.style.CoreStyle.prototype.getTextIndent = function() {
	return this._textIndent;
}
cocktail.core.style.CoreStyle.prototype.getWhiteSpace = function() {
	return this._whiteSpace;
}
cocktail.core.style.CoreStyle.prototype.getTextAlign = function() {
	return this._textAlign;
}
cocktail.core.style.CoreStyle.prototype.getTransform = function() {
	return this._transform;
}
cocktail.core.style.CoreStyle.prototype.getTransformOrigin = function() {
	return this._transformOrigin;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundColor = function(value) {
	return this._backgroundColor = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundColor = function() {
	return this._backgroundColor;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundImage = function(value) {
	return this._backgroundImage = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundImage = function() {
	return this._backgroundImage;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundRepeat = function(value) {
	return this._backgroundRepeat = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundRepeat = function() {
	return this._backgroundRepeat;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundSize = function(value) {
	return this._backgroundSize = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundSize = function() {
	return this._backgroundSize;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundClip = function(value) {
	return this._backgroundClip = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundClip = function() {
	return this._backgroundClip;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundPosition = function(value) {
	return this._backgroundPosition = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundPosition = function() {
	return this._backgroundPosition;
}
cocktail.core.style.CoreStyle.prototype.setBackgroundOrigin = function(value) {
	return this._backgroundOrigin = value;
}
cocktail.core.style.CoreStyle.prototype.getBackgroundOrigin = function() {
	return this._backgroundOrigin;
}
cocktail.core.style.CoreStyle.prototype.getOverflowX = function() {
	return this._overflowX;
}
cocktail.core.style.CoreStyle.prototype.getOverflowY = function() {
	return this._overflowY;
}
cocktail.core.style.CoreStyle.prototype.setCursor = function(value) {
	return this._cursor = value;
}
cocktail.core.style.CoreStyle.prototype.getCursor = function() {
	return this._cursor;
}
cocktail.core.style.CoreStyle.prototype.__class__ = cocktail.core.style.CoreStyle;
cocktail.core.style.ContainerCoreStyle = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.style.CoreStyle.call(this,htmlElement);
}
cocktail.core.style.ContainerCoreStyle.__name__ = ["cocktail","core","style","ContainerCoreStyle"];
cocktail.core.style.ContainerCoreStyle.__super__ = cocktail.core.style.CoreStyle;
for(var k in cocktail.core.style.CoreStyle.prototype ) cocktail.core.style.ContainerCoreStyle.prototype[k] = cocktail.core.style.CoreStyle.prototype[k];
cocktail.core.style.ContainerCoreStyle.prototype.createElementRenderer = function(parentElementRenderer) {
	var elementRenderer;
	if(this.isInlineLevel() == true && this.establishesNewFormattingContext() == false) elementRenderer = new cocktail.core.renderer.InlineBoxRenderer(this); else elementRenderer = new cocktail.core.renderer.BlockBoxRenderer(this);
	elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
	parentElementRenderer.appendChild(elementRenderer);
	return elementRenderer;
}
cocktail.core.style.ContainerCoreStyle.prototype.layout = function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
	this.flow(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,null,null,null);
}
cocktail.core.style.ContainerCoreStyle.prototype.flowChildren = function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
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
cocktail.core.style.ContainerCoreStyle.prototype.doFlowChildren = function(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext) {
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
cocktail.core.style.ContainerCoreStyle.prototype.positionAbsolutelyPositionedHTMLElementsIfNeeded = function(childLastPositionedHTMLElementData,viewportData) {
	if(this.isPositioned() == true) this.doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
}
cocktail.core.style.ContainerCoreStyle.prototype.doPositionAbsolutelyPositionedHTMLElements = function(childLastPositionedHTMLElementData,viewportData) {
	childLastPositionedHTMLElementData.data = this.getPositionedHTMLElementData();
	var _g1 = 0, _g = childLastPositionedHTMLElementData.children.length;
	while(_g1 < _g) {
		var i = _g1++;
		var positionedHTMLElementData = childLastPositionedHTMLElementData.children[i];
		positionedHTMLElementData.coreStyle.positionElement(childLastPositionedHTMLElementData.data,viewportData,positionedHTMLElementData.staticPosition);
	}
}
cocktail.core.style.ContainerCoreStyle.prototype.insertTextElement = function(textElement,formattingContext,containingHTMLElementData) {
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
cocktail.core.style.ContainerCoreStyle.prototype.createTextRendererFromTextFragment = function(textFragment) {
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
cocktail.core.style.ContainerCoreStyle.prototype.shrinkToFitIfNeeded = function(containingHTMLElementData,minimumWidth,formattingContext,lastPositionedHTMLElementData,viewportData) {
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
cocktail.core.style.ContainerCoreStyle.prototype.applyContentHeightIfNeeded = function(containingHTMLElementData,childrenHeight) {
	var boxComputer = this.getBoxStylesComputer();
	return boxComputer.applyContentHeight(this,containingHTMLElementData,childrenHeight);
}
cocktail.core.style.ContainerCoreStyle.prototype.getBoxStylesComputer = function() {
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
cocktail.core.style.ContainerCoreStyle.prototype.getTextRenderer = function(textFragmentData,text) {
	var fontManager = new cocktail.port.browser.FontManager();
	var nativeTextElement = fontManager.createNativeTextElement(text,this._computedStyle);
	var textRenderer = new cocktail.core.renderer.TextRenderer(this,nativeTextElement,textFragmentData.textToken);
	textRenderer.setLayerRenderer(this._elementRenderer.getLayerRenderer());
	textFragmentData.textRenderer = textRenderer;
	return textRenderer;
}
cocktail.core.style.ContainerCoreStyle.prototype.establishesNewFormattingContext = function() {
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
cocktail.core.style.ContainerCoreStyle.prototype.childrenInline = function() {
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
cocktail.core.style.ContainerCoreStyle.prototype.getContainerHTMLElementData = function() {
	var height;
	if(this.isInlineLevel() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.establishesNewFormattingContext() == true && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
	return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.core.style.Dimension.cssAuto, height : height, isHeightAuto : this._height == cocktail.core.style.Dimension.cssAuto};
}
cocktail.core.style.ContainerCoreStyle.prototype.getPositionedHTMLElementData = function() {
	var positionedHTMLElementData = this.getContainerHTMLElementData();
	positionedHTMLElementData.height = this.getComputedHeight();
	return positionedHTMLElementData;
}
cocktail.core.style.ContainerCoreStyle.prototype.getformattingContext = function(previousformattingContext) {
	var formattingContext;
	if(this.establishesNewFormattingContext() == true || previousformattingContext == null) {
		var formattingContextRoot = this._elementRenderer;
		if(this.childrenInline() == true) formattingContext = new cocktail.core.style.formatter.InlineFormattingContext(formattingContextRoot); else formattingContext = new cocktail.core.style.formatter.BlockFormattingContext(formattingContextRoot);
	} else formattingContext = previousformattingContext;
	return formattingContext;
}
cocktail.core.style.ContainerCoreStyle.prototype.isChildInline = function(child) {
	var ret = true;
	if(child.get_nodeType() == 1) {
		var childHTMLElement = child;
		if(childHTMLElement.get_coreStyle().getComputedStyle().display == cocktail.core.style.Display.block) {
			if(childHTMLElement.get_coreStyle().isFloat() == false) ret = false; else if(childHTMLElement.get_coreStyle().isPositioned() == false || childHTMLElement.get_coreStyle().isRelativePositioned() == true) ret = false;
		} else ret = true;
	} else ret = true;
	return ret;
}
cocktail.core.style.ContainerCoreStyle.prototype.getChildLastPositionedHTMLElementData = function(lastPositionedHTMLElementData) {
	var childLastPositionedHTMLElementData;
	if(this.isPositioned() == true) childLastPositionedHTMLElementData = { data : this.getContainerHTMLElementData(), children : new Array()}; else childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
	return childLastPositionedHTMLElementData;
}
cocktail.core.style.ContainerCoreStyle.prototype.isInlineContainer = function() {
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
cocktail.core.style.ContainerCoreStyle.prototype.getComputedHeight = function() {
	return this._computedStyle.height;
}
cocktail.core.style.ContainerCoreStyle.prototype.__class__ = cocktail.core.style.ContainerCoreStyle;
if(typeof utest=='undefined') utest = {}
if(!utest.ui) utest.ui = {}
if(!utest.ui.common) utest.ui.common = {}
utest.ui.common.ResultAggregator = function(runner,flattenPackage) {
	if( runner === $_ ) return;
	if(flattenPackage == null) flattenPackage = false;
	if(runner == null) throw "runner argument is null";
	this.flattenPackage = flattenPackage;
	this.runner = runner;
	runner.onStart.add($closure(this,"start"));
	runner.onProgress.add($closure(this,"progress"));
	runner.onComplete.add($closure(this,"complete"));
	this.onStart = new utest.Notifier();
	this.onComplete = new utest.Dispatcher();
	this.onProgress = new utest.Dispatcher();
}
utest.ui.common.ResultAggregator.__name__ = ["utest","ui","common","ResultAggregator"];
utest.ui.common.ResultAggregator.prototype.runner = null;
utest.ui.common.ResultAggregator.prototype.flattenPackage = null;
utest.ui.common.ResultAggregator.prototype.root = null;
utest.ui.common.ResultAggregator.prototype.onStart = null;
utest.ui.common.ResultAggregator.prototype.onComplete = null;
utest.ui.common.ResultAggregator.prototype.onProgress = null;
utest.ui.common.ResultAggregator.prototype.start = function(runner) {
	this.root = new utest.ui.common.PackageResult(null);
	this.onStart.dispatch();
}
utest.ui.common.ResultAggregator.prototype.getOrCreatePackage = function(pack,flat,ref) {
	if(ref == null) ref = this.root;
	if(pack == null || pack == "") return ref;
	if(flat) {
		if(ref.existsPackage(pack)) return ref.getPackage(pack);
		var p = new utest.ui.common.PackageResult(pack);
		ref.addPackage(p);
		return p;
	} else {
		var parts = pack.split(".");
		var _g = 0;
		while(_g < parts.length) {
			var part = parts[_g];
			++_g;
			ref = this.getOrCreatePackage(part,true,ref);
		}
		return ref;
	}
}
utest.ui.common.ResultAggregator.prototype.getOrCreateClass = function(pack,cls,setup,teardown) {
	if(pack.existsClass(cls)) return pack.getClass(cls);
	var c = new utest.ui.common.ClassResult(cls,setup,teardown);
	pack.addClass(c);
	return c;
}
utest.ui.common.ResultAggregator.prototype.createFixture = function(result) {
	var f = new utest.ui.common.FixtureResult(result.method);
	var $it0 = result.assertations.iterator();
	while( $it0.hasNext() ) {
		var assertation = $it0.next();
		f.add(assertation);
	}
	return f;
}
utest.ui.common.ResultAggregator.prototype.progress = function(e) {
	this.root.addResult(e.result,this.flattenPackage);
	this.onProgress.dispatch(e);
}
utest.ui.common.ResultAggregator.prototype.complete = function(runner) {
	this.onComplete.dispatch(this.root);
}
utest.ui.common.ResultAggregator.prototype.__class__ = utest.ui.common.ResultAggregator;
cocktail.core.dom.Document = function(p) {
	if( p === $_ ) return;
	cocktail.core.dom.Node.call(this);
}
cocktail.core.dom.Document.__name__ = ["cocktail","core","dom","Document"];
cocktail.core.dom.Document.__super__ = cocktail.core.dom.Node;
for(var k in cocktail.core.dom.Node.prototype ) cocktail.core.dom.Document.prototype[k] = cocktail.core.dom.Node.prototype[k];
cocktail.core.dom.Document.prototype._documentElement = null;
cocktail.core.dom.Document.prototype.documentElement = null;
cocktail.core.dom.Document.prototype.createElement = function(tagName) {
	var element = new cocktail.port.browser.HTMLElement(tagName);
	element.set_ownerDocument(this);
	return element;
}
cocktail.core.dom.Document.prototype.createTextNode = function(data) {
	var text = new cocktail.port.browser.Text();
	text.set_nodeValue(data);
	return text;
}
cocktail.core.dom.Document.prototype.createAttribute = function(name) {
	var attribute = new cocktail.core.dom.Attr(name);
	return attribute;
}
cocktail.core.dom.Document.prototype.getElementById = function(elementId) {
	return this.doGetElementById(this._documentElement,elementId);
}
cocktail.core.dom.Document.prototype.doGetElementById = function(node,elementId) {
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
cocktail.core.dom.Document.prototype.getElementsByTagName = function(tagName) {
	return this._documentElement.getElementsByTagName(tagName);
}
cocktail.core.dom.Document.prototype.get_nodeType = function() {
	return 9;
}
cocktail.core.dom.Document.prototype.get_documentElement = function() {
	return this._documentElement;
}
cocktail.core.dom.Document.prototype.__class__ = cocktail.core.dom.Document;
if(!cocktail.core.background) cocktail.core.background = {}
cocktail.core.background.BackgroundManager = function(p) {
	if( p === $_ ) return;
	this._backgroundDrawingManagers = new Array();
}
cocktail.core.background.BackgroundManager.__name__ = ["cocktail","core","background","BackgroundManager"];
cocktail.core.background.BackgroundManager.prototype._backgroundDrawingManagers = null;
cocktail.core.background.BackgroundManager.prototype.dispose = function() {
	this._backgroundDrawingManagers = null;
}
cocktail.core.background.BackgroundManager.prototype.render = function(backgroundBox,style) {
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
cocktail.core.background.BackgroundManager.prototype.drawBackgroundImage = function(imageDeclaration,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var backgroundImageNativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas);
	var imageLoader = new cocktail.core.resource.AbstractImageLoader();
	var onBackgroundImageLoadedDelegate = $closure(this,"onBackgroundImageLoaded");
	var onBackgroundImageLoadErrorDelegate = $closure(this,"onBackgroundImageLoadError");
	imageLoader.load(imageDeclaration.urls,function(loadedImage) {
		onBackgroundImageLoadedDelegate(backgroundImageNativeElement,loadedImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	},function(error) {
		onBackgroundImageLoadErrorDelegate(error,imageDeclaration.fallbackColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	});
	return backgroundImageNativeElement;
}
cocktail.core.background.BackgroundManager.prototype.onBackgroundImageLoaded = function(backgroundImageNativeElement,loadedBackgroundImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var computedGradientStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	var backgroundImageDrawingManager = new cocktail.core.background.BackgroundDrawingManager(backgroundImageNativeElement,backgroundBox);
	backgroundImageDrawingManager.drawBackgroundImage(loadedBackgroundImage,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
	this._backgroundDrawingManagers.push(backgroundImageDrawingManager);
}
cocktail.core.background.BackgroundManager.prototype.onBackgroundImageLoadError = function(error,backgroundColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	this.drawBackgroundColor(style,cocktail.core.unit.UnitManager.getColorDataFromCSSColor(backgroundColor),backgroundImageNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
}
cocktail.core.background.BackgroundManager.prototype.drawBackgroundColor = function(style,backgroundColor,backgroundColorNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var computedBackgroundStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	var backgroundColorDrawingManager = new cocktail.core.background.BackgroundDrawingManager(backgroundColorNativeElement,backgroundBox);
	backgroundColorDrawingManager.drawBackgroundColor(backgroundColor,this.getBackgroundPaintingBox(computedBackgroundStyles.backgroundClip));
	this._backgroundDrawingManagers.push(backgroundColorDrawingManager);
}
cocktail.core.background.BackgroundManager.prototype.drawBackgroundGradient = function(style,gradientValue,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var computedGradientStyles = cocktail.core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	var gradientNativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.canvas);
	var backgroundGradientDrawingManager = new cocktail.core.background.BackgroundDrawingManager(gradientNativeElement,backgroundBox);
	backgroundGradientDrawingManager.drawBackgroundGradient(gradientValue,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
	return gradientNativeElement;
}
cocktail.core.background.BackgroundManager.prototype.getBackgroundPaintingBox = function(computedBackgroundBox) {
	return computedBackgroundBox;
}
cocktail.core.background.BackgroundManager.prototype.getBackgroundPositioningBox = function(computedPositioningBox) {
	return computedPositioningBox;
}
cocktail.core.background.BackgroundManager.prototype.__class__ = cocktail.core.background.BackgroundManager;
cocktail.core.background.InitialBlockBackgroundManager = function(p) {
	if( p === $_ ) return;
	cocktail.core.background.BackgroundManager.call(this);
}
cocktail.core.background.InitialBlockBackgroundManager.__name__ = ["cocktail","core","background","InitialBlockBackgroundManager"];
cocktail.core.background.InitialBlockBackgroundManager.__super__ = cocktail.core.background.BackgroundManager;
for(var k in cocktail.core.background.BackgroundManager.prototype ) cocktail.core.background.InitialBlockBackgroundManager.prototype[k] = cocktail.core.background.BackgroundManager.prototype[k];
cocktail.core.background.InitialBlockBackgroundManager.prototype.getBackgroundPaintingBox = function(computedBackgroundBox) {
	return this.getWindowRectangleData();
}
cocktail.core.background.InitialBlockBackgroundManager.prototype.getBackgroundPositioningBox = function(computedPositioningBox) {
	return this.getWindowRectangleData();
}
cocktail.core.background.InitialBlockBackgroundManager.prototype.getWindowRectangleData = function() {
	var windowWidth = cocktail.Lib.get_window().get_innerWidth();
	var windowHeight = cocktail.Lib.get_window().get_innerHeight();
	var window = { x : 0.0, y : 0.0, width : windowWidth, height : windowHeight};
	return window;
}
cocktail.core.background.InitialBlockBackgroundManager.prototype.__class__ = cocktail.core.background.InitialBlockBackgroundManager;
if(!cocktail.core.style.formatter) cocktail.core.style.formatter = {}
cocktail.core.style.formatter.FormattingContext = function(formattingContextRoot) {
	if( formattingContextRoot === $_ ) return;
	this._formattingContextRoot = formattingContextRoot;
	this._floatsManager = new cocktail.core.style.floats.FloatsManager();
	this.initFormattingContextData();
	this._elementsInFormattingContext = new Array();
}
cocktail.core.style.formatter.FormattingContext.__name__ = ["cocktail","core","style","formatter","FormattingContext"];
cocktail.core.style.formatter.FormattingContext.prototype._formattingContextRoot = null;
cocktail.core.style.formatter.FormattingContext.prototype._floatsManager = null;
cocktail.core.style.formatter.FormattingContext.prototype._formattingContextData = null;
cocktail.core.style.formatter.FormattingContext.prototype._elementsInFormattingContext = null;
cocktail.core.style.formatter.FormattingContext.prototype._lastInsertedElement = null;
cocktail.core.style.formatter.FormattingContext.prototype.maxWidth = null;
cocktail.core.style.formatter.FormattingContext.prototype._layOutLastLine = null;
cocktail.core.style.formatter.FormattingContext.prototype.initFormattingContextData = function() {
	this._formattingContextData = { x : 0, y : 0, maxHeight : 0, maxWidth : 0};
}
cocktail.core.style.formatter.FormattingContext.prototype.dispose = function() {
	this._elementsInFormattingContext = null;
	this._formattingContextData = null;
	this._lastInsertedElement = null;
	this._floatsManager.dispose();
	this._floatsManager = null;
	this._formattingContextRoot = null;
}
cocktail.core.style.formatter.FormattingContext.prototype.insertElement = function(element) {
	this._elementsInFormattingContext.push(element);
}
cocktail.core.style.formatter.FormattingContext.prototype.format = function() {
	this._layOutLastLine = true;
	this.doFormat(this._elementsInFormattingContext);
}
cocktail.core.style.formatter.FormattingContext.prototype.getStaticPosition = function(element) {
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
cocktail.core.style.formatter.FormattingContext.prototype.getChildrenHeight = function(elementRenderer) {
	var height = 0;
	var elementRenderers = this.getChildElementRenderers(elementRenderer);
	height = Math.round(this.getBounds(elementRenderers).height);
	return height;
}
cocktail.core.style.formatter.FormattingContext.prototype.getBounds = function(elements) {
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
cocktail.core.style.formatter.FormattingContext.prototype.doFormat = function(elementsInFormattingContext) {
	this.initFormattingContextData();
	var _g1 = 0, _g = elementsInFormattingContext.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.doInsertElement(elementsInFormattingContext[i],this.isNextElementALineFeed(elementsInFormattingContext,i));
	}
}
cocktail.core.style.formatter.FormattingContext.prototype.doInsertElement = function(element,isNextElementALineFeed) {
	if(element.isFloat() == true) this.insertFloat(element); else if(element.canHaveChildren() == true) {
		if(element.getCoreStyle().establishesNewFormattingContext() == true) this.insertFormattingContextRootElement(element); else this.insertContainerElement(element);
	} else if(element.isText() == true) {
		if(element.isSpace() == true) this.insertSpace(element,isNextElementALineFeed); else this.insertText(element);
	} else this.insertEmbeddedElement(element);
}
cocktail.core.style.formatter.FormattingContext.prototype.getChildElementRenderers = function(elementRenderer) {
	var elementRenderers = new Array();
	var _g1 = 0, _g = this._elementsInFormattingContext.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._elementsInFormattingContext[i].get_parentNode() == elementRenderer) elementRenderers.push(this._elementsInFormattingContext[i]);
	}
	return elementRenderers;
}
cocktail.core.style.formatter.FormattingContext.prototype.insertEmbeddedElement = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertFormattingContextRootElement = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertContainerElement = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertText = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertSpace = function(element,isNextElementALineFeed) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertHorizontalOffset = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertTab = function(element,isNextElementALineFeed) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertLineFeed = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.insertFloat = function(element) {
}
cocktail.core.style.formatter.FormattingContext.prototype.clearFloat = function(clear) {
	this._floatsManager.clearFloat(clear,this._formattingContextData);
}
cocktail.core.style.formatter.FormattingContext.prototype.removeFloats = function() {
	this._floatsManager.removeFloats(this._formattingContextData.y);
}
cocktail.core.style.formatter.FormattingContext.prototype.isNextElementALineFeed = function(elementsInFormattingContext,currentIndex) {
	var isNextElementALineFeed;
	if(currentIndex + 1 >= elementsInFormattingContext.length) isNextElementALineFeed = false; else isNextElementALineFeed = elementsInFormattingContext[currentIndex + 1].isLineFeed();
	return isNextElementALineFeed;
}
cocktail.core.style.formatter.FormattingContext.prototype.getMaxWidth = function() {
	return this._formattingContextData.maxWidth;
}
cocktail.core.style.formatter.FormattingContext.prototype.__class__ = cocktail.core.style.formatter.FormattingContext;
cocktail.core.style.formatter.InlineFormattingContext = function(formattingContextRoot) {
	if( formattingContextRoot === $_ ) return;
	this._elementsInLineBox = new Array();
	this._unbreakableLineBoxElements = new Array();
	this._unbreakableWidth = 0;
	this._currentInlineBoxesData = new Array();
	cocktail.core.style.formatter.FormattingContext.call(this,formattingContextRoot);
}
cocktail.core.style.formatter.InlineFormattingContext.__name__ = ["cocktail","core","style","formatter","InlineFormattingContext"];
cocktail.core.style.formatter.InlineFormattingContext.__super__ = cocktail.core.style.formatter.FormattingContext;
for(var k in cocktail.core.style.formatter.FormattingContext.prototype ) cocktail.core.style.formatter.InlineFormattingContext.prototype[k] = cocktail.core.style.formatter.FormattingContext.prototype[k];
cocktail.core.style.formatter.InlineFormattingContext.prototype._elementsInLineBox = null;
cocktail.core.style.formatter.InlineFormattingContext.prototype._unbreakableLineBoxElements = null;
cocktail.core.style.formatter.InlineFormattingContext.prototype._unbreakableWidth = null;
cocktail.core.style.formatter.InlineFormattingContext.prototype._currentInlineBoxesData = null;
cocktail.core.style.formatter.InlineFormattingContext.prototype.dispose = function() {
	cocktail.core.style.formatter.FormattingContext.prototype.dispose.call(this);
	this._unbreakableLineBoxElements = null;
	this._elementsInLineBox = null;
	this._currentInlineBoxesData = null;
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.doFormat = function(elementsInFormattingContext) {
	this._elementsInLineBox = new Array();
	this._unbreakableLineBoxElements = new Array();
	this._unbreakableWidth = 0;
	this._formattingContextRoot.removeLineBoxes();
	this._currentInlineBoxesData = new Array();
	cocktail.core.style.formatter.FormattingContext.prototype.doFormat.call(this,elementsInFormattingContext);
	this.insertBreakOpportunity(true,true);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.getRemainingLineWidth = function() {
	return this._formattingContextRoot.getCoreStyle().getComputedStyle().width - this._formattingContextData.x - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._formattingContextRoot.getCoreStyle().getComputedStyle().width);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertEmbeddedElement = function(element) {
	this.insertBreakOpportunity(false);
	this._unbreakableLineBoxElements.push(element);
	this._lastInsertedElement = element;
	this.addWidth(Math.round(element.getBounds().width));
	this.insertBreakOpportunity(false);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertFormattingContextRootElement = function(element) {
	var computedStyle = element.getCoreStyle().getComputedStyle();
	element.getBounds().width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	element.getBounds().height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	this.insertBreakOpportunity(false);
	this._unbreakableLineBoxElements.push(element);
	this._lastInsertedElement = element;
	this.addWidth(Math.round(element.getBounds().width));
	this.insertBreakOpportunity(false);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertContainerElement = function(element) {
	this._unbreakableLineBoxElements.push(element);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertText = function(element) {
	this._unbreakableLineBoxElements.push(element);
	this._lastInsertedElement = element;
	this.addWidth(Math.round(element.getBounds().width));
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertSpace = function(element,isNextElementALineFeed) {
	this._unbreakableLineBoxElements.push(element);
	this._lastInsertedElement = element;
	this.addWidth(Math.round(element.getBounds().width));
	this.insertBreakOpportunity(false);
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertHorizontalOffset = function(element) {
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertTab = function(element,isNextElementALineFeed) {
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertLineFeed = function(element) {
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.insertBreakOpportunity = function(forced,isLastLine) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.addWidth = function(width) {
	this._unbreakableWidth += width;
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.shouldTabBeConvertedToSpace = function(whiteSpace) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.isLineFeedAllowed = function(whiteSpace) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.shouldInsertSpace = function(whiteSpace,isNexElementALineFeed) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.isCollapsed = function(lastInsertedElement,whiteSpace) {
	return false;
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.getParentInlineBoxesData = function(parent) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.startNewLine = function(elementWidth,isLastLine) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.removeSpaces = function() {
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.alignLineBox = function(isLastLine) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.alignLeft = function(flowX) {
	var _g1 = 0, _g = this._elementsInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._elementsInLineBox[i].getBounds().x = flowX;
		flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
	}
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.alignCenter = function(flowX,remainingSpace) {
	var _g1 = 0, _g = this._elementsInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._elementsInLineBox[i].getBounds().x = Math.round(remainingSpace / 2) + flowX;
		flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
	}
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.alignRight = function(flowX,remainingSpace) {
	var _g1 = 0, _g = this._elementsInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._elementsInLineBox[i].getBounds().x = flowX + remainingSpace;
		flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
	}
}
cocktail.core.style.formatter.InlineFormattingContext.prototype.alignJustify = function(flowX,remainingSpace) {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.computeLineBoxHeight = function() {
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
cocktail.core.style.formatter.InlineFormattingContext.prototype.__class__ = cocktail.core.style.formatter.InlineFormattingContext;
if(!cocktail.core.nativeElement) cocktail.core.nativeElement = {}
cocktail.core.nativeElement.AbstractNativeElementManagerImpl = function(p) {
}
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.__name__ = ["cocktail","core","nativeElement","AbstractNativeElementManagerImpl"];
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype.getRoot = function() {
	return null;
}
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype.createNativeElement = function(nativeElementType) {
	return null;
}
cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype.__class__ = cocktail.core.nativeElement.AbstractNativeElementManagerImpl;
cocktail.port.browser.NativeElementManagerImpl = function(p) {
	if( p === $_ ) return;
	cocktail.core.nativeElement.AbstractNativeElementManagerImpl.call(this);
}
cocktail.port.browser.NativeElementManagerImpl.__name__ = ["cocktail","port","browser","NativeElementManagerImpl"];
cocktail.port.browser.NativeElementManagerImpl.__super__ = cocktail.core.nativeElement.AbstractNativeElementManagerImpl;
for(var k in cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype ) cocktail.port.browser.NativeElementManagerImpl.prototype[k] = cocktail.core.nativeElement.AbstractNativeElementManagerImpl.prototype[k];
cocktail.port.browser.NativeElementManagerImpl.prototype.getRoot = function() {
	return js.Lib.document.body;
}
cocktail.port.browser.NativeElementManagerImpl.prototype.createNativeElement = function(nativeElementType) {
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
cocktail.port.browser.NativeElementManagerImpl.prototype.__class__ = cocktail.port.browser.NativeElementManagerImpl;
if(!cocktail.core.style.computer) cocktail.core.style.computer = {}
if(!cocktail.core.style.computer.boxComputers) cocktail.core.style.computer.boxComputers = {}
cocktail.core.style.computer.boxComputers.BoxStylesComputer = function(p) {
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","BoxStylesComputer"];
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measure = function(style,containingHTMLElementData) {
	this.measureHorizontalPaddings(style,containingHTMLElementData);
	this.measureVerticalPaddings(style,containingHTMLElementData);
	this.measureDimensionsConstraints(style,containingHTMLElementData);
	this.measureWidthAndHorizontalMargins(style,containingHTMLElementData);
	this.measureHeightAndVerticalMargins(style,containingHTMLElementData);
	this.measurePositionOffsets(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.shrinkToFit = function(style,containingHTMLElementData,minimumWidth) {
	return style.getComputedStyle().width;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.applyContentHeight = function(style,cotainingHTMLElementData,childrenHeight) {
	return childrenHeight;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureDimensionsConstraints = function(style,containingHTMLElementData) {
	style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measurePositionOffsets = function(style,containingHTMLElementData) {
	style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureVerticalPaddings = function(style,containingHTMLElementData) {
	style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureHorizontalPaddings = function(style,containingHTMLElementData) {
	style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureWidthAndHorizontalMargins = function(style,containingHTMLElementData) {
	if(style.getWidth() == cocktail.core.style.Dimension.cssAuto) this.measureAutoWidth(style,containingHTMLElementData); else this.measureWidth(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureAutoWidth = function(style,containingHTMLElementData) {
	this.setComputedWidth(style,0);
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
	this.setComputedWidth(style,this.getComputedAutoWidth(style,containingHTMLElementData));
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureWidth = function(style,containingHTMLElementData) {
	this.setComputedWidth(style,this.getComputedWidth(style,containingHTMLElementData));
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureHeightAndVerticalMargins = function(style,containingHTMLElementData) {
	if(style.getHeight() == cocktail.core.style.Dimension.cssAuto) this.measureAutoHeight(style,containingHTMLElementData); else this.measureHeight(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureAutoHeight = function(style,containingHTMLElementData) {
	this.setComputedHeight(style,this.getComputedAutoHeight(style,containingHTMLElementData));
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.measureHeight = function(style,containingHTMLElementData) {
	this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.constrainWidth = function(style,computedWidth) {
	var computedStyle = style.getComputedStyle();
	if(style.getMaxWidth() != cocktail.core.style.ConstrainedDimension.none) {
		if(computedWidth > computedStyle.maxWidth) computedWidth = computedStyle.maxWidth;
	}
	if(computedWidth < computedStyle.minWidth) computedWidth = computedStyle.minWidth;
	return computedWidth;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.constrainHeight = function(style,computedHeight) {
	var computedStyle = style.getComputedStyle();
	if(style.getMaxHeight() != cocktail.core.style.ConstrainedDimension.none) {
		if(computedHeight > computedStyle.maxHeight) computedHeight = computedStyle.maxHeight;
	}
	if(computedHeight < computedStyle.minHeight) computedHeight = computedStyle.minHeight;
	return computedHeight;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.setComputedHeight = function(style,computedHeight) {
	style.getComputedStyle().height = this.constrainHeight(style,computedHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.setComputedWidth = function(style,computedWidth) {
	style.getComputedStyle().width = this.constrainWidth(style,computedWidth);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedWidth = function(style,containingHTMLElementData) {
	return this.getComputedDimension(style.getWidth(),containingHTMLElementData.width,containingHTMLElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingHTMLElementData) {
	return containingHTMLElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedHeight = function(style,containingHTMLElementData) {
	return this.getComputedDimension(style.getHeight(),containingHTMLElementData.height,containingHTMLElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingHTMLElementData) {
	return 0;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedMarginLeft = function(style,containingHTMLElementData) {
	return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedMarginRight = function(style,containingHTMLElementData) {
	return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedMarginTop = function(style,containingHTMLElementData) {
	return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedMarginBottom = function(style,containingHTMLElementData) {
	return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
		computedMargin = this.getComputedAutoMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
		break;
	}
	return computedMargin;
}
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedConstrainedDimension = function(constrainedDimension,containingHTMLElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
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
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedPositionOffset = function(positionOffsetStyleValue,containingHTMLElementDimension,fontSize,xHeight) {
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
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedDimension = function(dimensionStyleValue,containingHTMLElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedPadding = function(paddingStyleValue,containingHTMLElementDimension,fontSize,xHeight) {
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
cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.shrinkToFit = function(style,containingHTMLElementData,minimumWidth) {
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
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.applyContentHeight = function(style,containingHTMLElementData,childrenHeight) {
	var height;
	if(style.getTop() != cocktail.core.style.PositionOffset.cssAuto && style.getBottom() != cocktail.core.style.PositionOffset.cssAuto) {
		var computedStyle = style.getComputedStyle();
		height = containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
	} else height = childrenHeight;
	height = this.constrainHeight(style,height);
	return height;
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingHTMLElementData) {
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureAutoWidth = function(style,containingHTMLElementData) {
	var computedStyle = style.getComputedStyle();
	if(style.getMarginLeft() == cocktail.core.style.Margin.cssAuto) computedStyle.marginLeft = 0; else computedStyle.marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
	if(style.getMarginRight() == cocktail.core.style.Margin.cssAuto) computedStyle.marginRight = 0; else computedStyle.marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
	if(style.getLeft() != cocktail.core.style.PositionOffset.cssAuto && style.getRight() != cocktail.core.style.PositionOffset.cssAuto) {
		computedStyle.left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		computedStyle.right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		this.setComputedWidth(style,containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight);
	} else this.setComputedWidth(style,1000000);
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureWidth = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureAutoHeight = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureHeight = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.getComputedStaticLeft = function(style,containingHTMLElementData) {
	return style.getComputedStyle().marginLeft;
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.getComputedStaticTop = function(style,containingHTMLElementData) {
	return style.getComputedStyle().marginTop;
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.doShrinkToFit = function(style,containingHTMLElementData,minimumWidth) {
	return minimumWidth;
}
cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.measureAutoWidth = function(style,containingHTMLElementData) {
	this.setComputedWidth(style,this.getComputedAutoWidth(style,containingHTMLElementData));
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	var computedMargin;
	if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
	return computedMargin;
}
cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	return 0;
}
cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
cocktail.core.style.computer.FontAndTextStylesComputer = function(p) {
}
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
cocktail.core.style.computer.FontAndTextStylesComputer.prototype.__class__ = cocktail.core.style.computer.FontAndTextStylesComputer;
cocktail.core.nativeElement.NativeElementManager = function(p) {
}
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
cocktail.core.nativeElement.NativeElementManager.prototype.__class__ = cocktail.core.nativeElement.NativeElementManager;
List = function(p) {
	if( p === $_ ) return;
	this.length = 0;
}
List.__name__ = ["List"];
List.prototype.h = null;
List.prototype.q = null;
List.prototype.length = null;
List.prototype.add = function(item) {
	var x = [item];
	if(this.h == null) this.h = x; else this.q[1] = x;
	this.q = x;
	this.length++;
}
List.prototype.push = function(item) {
	var x = [item,this.h];
	this.h = x;
	if(this.q == null) this.q = x;
	this.length++;
}
List.prototype.first = function() {
	return this.h == null?null:this.h[0];
}
List.prototype.last = function() {
	return this.q == null?null:this.q[0];
}
List.prototype.pop = function() {
	if(this.h == null) return null;
	var x = this.h[0];
	this.h = this.h[1];
	if(this.h == null) this.q = null;
	this.length--;
	return x;
}
List.prototype.isEmpty = function() {
	return this.h == null;
}
List.prototype.clear = function() {
	this.h = null;
	this.q = null;
	this.length = 0;
}
List.prototype.remove = function(v) {
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
List.prototype.iterator = function() {
	return { h : this.h, hasNext : function() {
		return this.h != null;
	}, next : function() {
		if(this.h == null) return null;
		var x = this.h[0];
		this.h = this.h[1];
		return x;
	}};
}
List.prototype.toString = function() {
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
	return s.b.join("");
}
List.prototype.join = function(sep) {
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
List.prototype.filter = function(f) {
	var l2 = new List();
	var l = this.h;
	while(l != null) {
		var v = l[0];
		l = l[1];
		if(f(v)) l2.add(v);
	}
	return l2;
}
List.prototype.map = function(f) {
	var b = new List();
	var l = this.h;
	while(l != null) {
		var v = l[0];
		l = l[1];
		b.add(f(v));
	}
	return b;
}
List.prototype.__class__ = List;
cocktail.core.html.HTMLDocument = function(p) {
	if( p === $_ ) return;
	cocktail.core.dom.Document.call(this);
	this._body = new cocktail.core.html.HTMLBodyElement();
	this._documentElement = new cocktail.port.browser.HTMLHtmlElement();
	this._documentElement.appendChild(this._body);
	cocktail.core.focus.FocusManager.getInstance().setBodyElement(this._body);
	this._window = new cocktail.port.browser.Window();
	this._window.set_onResize($closure(this,"onWindowResize"));
}
cocktail.core.html.HTMLDocument.__name__ = ["cocktail","core","html","HTMLDocument"];
cocktail.core.html.HTMLDocument.__super__ = cocktail.core.dom.Document;
for(var k in cocktail.core.dom.Document.prototype ) cocktail.core.html.HTMLDocument.prototype[k] = cocktail.core.dom.Document.prototype[k];
cocktail.core.html.HTMLDocument.prototype._body = null;
cocktail.core.html.HTMLDocument.prototype.body = null;
cocktail.core.html.HTMLDocument.prototype._window = null;
cocktail.core.html.HTMLDocument.prototype.createElement = function(tagName) {
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
	default:
		element = new cocktail.port.browser.HTMLElement(tagName);
	}
	element.set_ownerDocument(this);
	return element;
}
cocktail.core.html.HTMLDocument.prototype.onWindowResize = function(event) {
	this._body.get_coreStyle().invalidate();
}
cocktail.core.html.HTMLDocument.prototype.get_body = function() {
	return this._body;
}
cocktail.core.html.HTMLDocument.prototype.__class__ = cocktail.core.html.HTMLDocument;
if(!utest._Dispatcher) utest._Dispatcher = {}
utest._Dispatcher.EventException = { __ename__ : ["utest","_Dispatcher","EventException"], __constructs__ : ["StopPropagation"] }
utest._Dispatcher.EventException.StopPropagation = ["StopPropagation",0];
utest._Dispatcher.EventException.StopPropagation.toString = $estr;
utest._Dispatcher.EventException.StopPropagation.__enum__ = utest._Dispatcher.EventException;
utest.Dispatcher = function(p) {
	if( p === $_ ) return;
	this.handlers = new Array();
}
utest.Dispatcher.__name__ = ["utest","Dispatcher"];
utest.Dispatcher.stop = function() {
	throw utest._Dispatcher.EventException.StopPropagation;
}
utest.Dispatcher.prototype.handlers = null;
utest.Dispatcher.prototype.add = function(h) {
	this.handlers.push(h);
	return h;
}
utest.Dispatcher.prototype.remove = function(h) {
	var _g1 = 0, _g = this.handlers.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(Reflect.compareMethods(this.handlers[i],h)) return this.handlers.splice(i,1)[0];
	}
	return null;
}
utest.Dispatcher.prototype.clear = function() {
	this.handlers = new Array();
}
utest.Dispatcher.prototype.dispatch = function(e) {
	try {
		var list = this.handlers.copy();
		var _g = 0;
		while(_g < list.length) {
			var l = list[_g];
			++_g;
			l(e);
		}
		return true;
	} catch( exc ) {
		if( js.Boot.__instanceof(exc,utest._Dispatcher.EventException) ) {
			return false;
		} else throw(exc);
	}
}
utest.Dispatcher.prototype.has = function() {
	return this.handlers.length > 0;
}
utest.Dispatcher.prototype.__class__ = utest.Dispatcher;
utest.Notifier = function(p) {
	if( p === $_ ) return;
	this.handlers = new Array();
}
utest.Notifier.__name__ = ["utest","Notifier"];
utest.Notifier.stop = function() {
	throw utest._Dispatcher.EventException.StopPropagation;
}
utest.Notifier.prototype.handlers = null;
utest.Notifier.prototype.add = function(h) {
	this.handlers.push(h);
	return h;
}
utest.Notifier.prototype.remove = function(h) {
	var _g1 = 0, _g = this.handlers.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(Reflect.compareMethods(this.handlers[i],h)) return this.handlers.splice(i,1)[0];
	}
	return null;
}
utest.Notifier.prototype.clear = function() {
	this.handlers = new Array();
}
utest.Notifier.prototype.dispatch = function() {
	try {
		var list = this.handlers.copy();
		var _g = 0;
		while(_g < list.length) {
			var l = list[_g];
			++_g;
			l();
		}
		return true;
	} catch( exc ) {
		if( js.Boot.__instanceof(exc,utest._Dispatcher.EventException) ) {
			return false;
		} else throw(exc);
	}
}
utest.Notifier.prototype.has = function() {
	return this.handlers.length > 0;
}
utest.Notifier.prototype.__class__ = utest.Notifier;
IntIter = function(min,max) {
	if( min === $_ ) return;
	this.min = min;
	this.max = max;
}
IntIter.__name__ = ["IntIter"];
IntIter.prototype.min = null;
IntIter.prototype.max = null;
IntIter.prototype.hasNext = function() {
	return this.min < this.max;
}
IntIter.prototype.next = function() {
	return this.min++;
}
IntIter.prototype.__class__ = IntIter;
cocktail.core.event.Event = function(type,target) {
	if( type === $_ ) return;
	this._type = type;
	this._target = target;
}
cocktail.core.event.Event.__name__ = ["cocktail","core","event","Event"];
cocktail.core.event.Event.prototype._type = null;
cocktail.core.event.Event.prototype.type = null;
cocktail.core.event.Event.prototype._target = null;
cocktail.core.event.Event.prototype.target = null;
cocktail.core.event.Event.prototype._defaultPrevented = null;
cocktail.core.event.Event.prototype.defaultPrevented = null;
cocktail.core.event.Event.prototype.preventDefault = function() {
	this._defaultPrevented = true;
}
cocktail.core.event.Event.prototype.get_defaultPrevented = function() {
	return this._defaultPrevented;
}
cocktail.core.event.Event.prototype.get_type = function() {
	return this._type;
}
cocktail.core.event.Event.prototype.get_target = function() {
	return this._target;
}
cocktail.core.event.Event.prototype.__class__ = cocktail.core.event.Event;
cocktail.core.event.UIEvent = function(type,target,detail) {
	if( type === $_ ) return;
	this._detail = detail;
	cocktail.core.event.Event.call(this,type,target);
}
cocktail.core.event.UIEvent.__name__ = ["cocktail","core","event","UIEvent"];
cocktail.core.event.UIEvent.__super__ = cocktail.core.event.Event;
for(var k in cocktail.core.event.Event.prototype ) cocktail.core.event.UIEvent.prototype[k] = cocktail.core.event.Event.prototype[k];
cocktail.core.event.UIEvent.prototype._detail = null;
cocktail.core.event.UIEvent.prototype.detail = null;
cocktail.core.event.UIEvent.prototype.get_detail = function() {
	return this._detail;
}
cocktail.core.event.UIEvent.prototype.set_detail = function(value) {
	return this._detail = value;
}
cocktail.core.event.UIEvent.prototype.__class__ = cocktail.core.event.UIEvent;
cocktail.core.event.KeyboardEvent = function(type,target,detail,keyChar,key,ctrlKey,shiftKey,altKey) {
	if( type === $_ ) return;
	cocktail.core.event.UIEvent.call(this,type,target,detail);
	this._keyChar = keyChar;
	this._key = key;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
}
cocktail.core.event.KeyboardEvent.__name__ = ["cocktail","core","event","KeyboardEvent"];
cocktail.core.event.KeyboardEvent.__super__ = cocktail.core.event.UIEvent;
for(var k in cocktail.core.event.UIEvent.prototype ) cocktail.core.event.KeyboardEvent.prototype[k] = cocktail.core.event.UIEvent.prototype[k];
cocktail.core.event.KeyboardEvent.prototype._keyChar = null;
cocktail.core.event.KeyboardEvent.prototype.keyChar = null;
cocktail.core.event.KeyboardEvent.prototype._key = null;
cocktail.core.event.KeyboardEvent.prototype.key = null;
cocktail.core.event.KeyboardEvent.prototype._ctrlKey = null;
cocktail.core.event.KeyboardEvent.prototype.ctrlKey = null;
cocktail.core.event.KeyboardEvent.prototype._shiftKey = null;
cocktail.core.event.KeyboardEvent.prototype.shiftKey = null;
cocktail.core.event.KeyboardEvent.prototype._altKey = null;
cocktail.core.event.KeyboardEvent.prototype.altKey = null;
cocktail.core.event.KeyboardEvent.prototype.get_altKey = function() {
	return this._altKey;
}
cocktail.core.event.KeyboardEvent.prototype.get_shiftKey = function() {
	return this._shiftKey;
}
cocktail.core.event.KeyboardEvent.prototype.get_ctrlKey = function() {
	return this._ctrlKey;
}
cocktail.core.event.KeyboardEvent.prototype.get_keyChar = function() {
	return this._keyChar;
}
cocktail.core.event.KeyboardEvent.prototype.get_key = function() {
	return this._key;
}
cocktail.core.event.KeyboardEvent.prototype.__class__ = cocktail.core.event.KeyboardEvent;
if(!cocktail.core.renderer) cocktail.core.renderer = {}
cocktail.core.renderer.ElementRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.dom.Node.call(this);
	this._coreStyle = style;
	this._bounds = { x : 0.0, y : 0.0, width : 0.0, height : 0.0};
}
cocktail.core.renderer.ElementRenderer.__name__ = ["cocktail","core","renderer","ElementRenderer"];
cocktail.core.renderer.ElementRenderer.__super__ = cocktail.core.dom.Node;
for(var k in cocktail.core.dom.Node.prototype ) cocktail.core.renderer.ElementRenderer.prototype[k] = cocktail.core.dom.Node.prototype[k];
cocktail.core.renderer.ElementRenderer.prototype._bounds = null;
cocktail.core.renderer.ElementRenderer.prototype.bounds = null;
cocktail.core.renderer.ElementRenderer.prototype._coreStyle = null;
cocktail.core.renderer.ElementRenderer.prototype.coreStyle = null;
cocktail.core.renderer.ElementRenderer.prototype._layerRenderer = null;
cocktail.core.renderer.ElementRenderer.prototype.layerRenderer = null;
cocktail.core.renderer.ElementRenderer.prototype.render = function() {
	return [];
}
cocktail.core.renderer.ElementRenderer.prototype.renderBackground = function() {
	return [];
}
cocktail.core.renderer.ElementRenderer.prototype.dispose = function() {
	this._bounds = null;
	this._coreStyle = null;
	this._layerRenderer = null;
}
cocktail.core.renderer.ElementRenderer.prototype.establishesNewFormattingContext = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.canHaveChildren = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.isFloat = function() {
	return this._coreStyle.isFloat();
}
cocktail.core.renderer.ElementRenderer.prototype.isPositioned = function() {
	return this._coreStyle.isPositioned();
}
cocktail.core.renderer.ElementRenderer.prototype.isEmbedded = function() {
	return true;
}
cocktail.core.renderer.ElementRenderer.prototype.isText = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.isSpace = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.isLineFeed = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.isTab = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.isInitialContainer = function() {
	return false;
}
cocktail.core.renderer.ElementRenderer.prototype.setLayerRenderer = function(value) {
	return this._layerRenderer = value;
}
cocktail.core.renderer.ElementRenderer.prototype.getLayerRenderer = function() {
	return this._layerRenderer;
}
cocktail.core.renderer.ElementRenderer.prototype.getCoreStyle = function() {
	return this._coreStyle;
}
cocktail.core.renderer.ElementRenderer.prototype.getBounds = function() {
	return this._bounds;
}
cocktail.core.renderer.ElementRenderer.prototype.setBounds = function(value) {
	return this._bounds = value;
}
cocktail.core.renderer.ElementRenderer.prototype.__class__ = cocktail.core.renderer.ElementRenderer;
cocktail.core.renderer.BoxRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.ElementRenderer.call(this,style);
	this.init();
}
cocktail.core.renderer.BoxRenderer.__name__ = ["cocktail","core","renderer","BoxRenderer"];
cocktail.core.renderer.BoxRenderer.__super__ = cocktail.core.renderer.ElementRenderer;
for(var k in cocktail.core.renderer.ElementRenderer.prototype ) cocktail.core.renderer.BoxRenderer.prototype[k] = cocktail.core.renderer.ElementRenderer.prototype[k];
cocktail.core.renderer.BoxRenderer.prototype._backgroundManager = null;
cocktail.core.renderer.BoxRenderer.prototype.init = function() {
	this._backgroundManager = new cocktail.core.background.BackgroundManager();
}
cocktail.core.renderer.BoxRenderer.prototype.dispose = function() {
	cocktail.core.renderer.ElementRenderer.prototype.dispose.call(this);
	this._backgroundManager.dispose();
	this._backgroundManager = null;
}
cocktail.core.renderer.BoxRenderer.prototype.renderBackground = function() {
	var backgrounds = this._backgroundManager.render(this._bounds,this._coreStyle);
	var _g1 = 0, _g = backgrounds.length;
	while(_g1 < _g) {
		var i = _g1++;
	}
	return backgrounds;
}
cocktail.core.renderer.BoxRenderer.prototype.__class__ = cocktail.core.renderer.BoxRenderer;
cocktail.core.renderer.FlowBoxRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.BoxRenderer.call(this,style);
}
cocktail.core.renderer.FlowBoxRenderer.__name__ = ["cocktail","core","renderer","FlowBoxRenderer"];
cocktail.core.renderer.FlowBoxRenderer.__super__ = cocktail.core.renderer.BoxRenderer;
for(var k in cocktail.core.renderer.BoxRenderer.prototype ) cocktail.core.renderer.FlowBoxRenderer.prototype[k] = cocktail.core.renderer.BoxRenderer.prototype[k];
cocktail.core.renderer.FlowBoxRenderer.prototype.dispose = function() {
	cocktail.core.renderer.BoxRenderer.prototype.dispose.call(this);
	var _g1 = 0, _g = this._childNodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		var child = this._childNodes[i];
		child.dispose();
	}
	this._childNodes = null;
}
cocktail.core.renderer.FlowBoxRenderer.prototype.establishesNewFormattingContext = function() {
	return this.getCoreStyle().establishesNewFormattingContext();
}
cocktail.core.renderer.FlowBoxRenderer.prototype.isEmbedded = function() {
	return false;
}
cocktail.core.renderer.FlowBoxRenderer.prototype.canHaveChildren = function() {
	return true;
}
cocktail.core.renderer.FlowBoxRenderer.prototype.__class__ = cocktail.core.renderer.FlowBoxRenderer;
cocktail.core.renderer.BlockBoxRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.FlowBoxRenderer.call(this,style);
}
cocktail.core.renderer.BlockBoxRenderer.__name__ = ["cocktail","core","renderer","BlockBoxRenderer"];
cocktail.core.renderer.BlockBoxRenderer.__super__ = cocktail.core.renderer.FlowBoxRenderer;
for(var k in cocktail.core.renderer.FlowBoxRenderer.prototype ) cocktail.core.renderer.BlockBoxRenderer.prototype[k] = cocktail.core.renderer.FlowBoxRenderer.prototype[k];
cocktail.core.renderer.BlockBoxRenderer.prototype._lineBoxes = null;
cocktail.core.renderer.BlockBoxRenderer.prototype.lineBoxes = null;
cocktail.core.renderer.BlockBoxRenderer.prototype.dispose = function() {
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
cocktail.core.renderer.BlockBoxRenderer.prototype.addLineBox = function(lineBoxElements) {
	this._lineBoxes.push(lineBoxElements);
}
cocktail.core.renderer.BlockBoxRenderer.prototype.removeLineBoxes = function() {
	this._lineBoxes = new Array();
}
cocktail.core.renderer.BlockBoxRenderer.prototype.render = function() {
	var ret = [];
	return ret;
}
cocktail.core.renderer.BlockBoxRenderer.prototype.getLineBoxes = function() {
	return this._lineBoxes;
}
cocktail.core.renderer.BlockBoxRenderer.prototype.__class__ = cocktail.core.renderer.BlockBoxRenderer;
cocktail.core.html.EmbeddedElement = function(tagName) {
	if( tagName === $_ ) return;
	cocktail.port.browser.HTMLElement.call(this,tagName);
}
cocktail.core.html.EmbeddedElement.__name__ = ["cocktail","core","html","EmbeddedElement"];
cocktail.core.html.EmbeddedElement.__super__ = cocktail.port.browser.HTMLElement;
for(var k in cocktail.port.browser.HTMLElement.prototype ) cocktail.core.html.EmbeddedElement.prototype[k] = cocktail.port.browser.HTMLElement.prototype[k];
cocktail.core.html.EmbeddedElement.prototype._intrinsicHeight = null;
cocktail.core.html.EmbeddedElement.prototype.intrinsicHeight = null;
cocktail.core.html.EmbeddedElement.prototype._intrinsicWidth = null;
cocktail.core.html.EmbeddedElement.prototype.intrinsicWidth = null;
cocktail.core.html.EmbeddedElement.prototype._intrinsicRatio = null;
cocktail.core.html.EmbeddedElement.prototype.intrinsicRatio = null;
cocktail.core.html.EmbeddedElement.prototype._height = null;
cocktail.core.html.EmbeddedElement.prototype.height = null;
cocktail.core.html.EmbeddedElement.prototype._width = null;
cocktail.core.html.EmbeddedElement.prototype.width = null;
cocktail.core.html.EmbeddedElement.prototype._embeddedAsset = null;
cocktail.core.html.EmbeddedElement.prototype.embeddedAsset = null;
cocktail.core.html.EmbeddedElement.prototype.init = function() {
	this.initEmbeddedAsset();
	cocktail.port.browser.HTMLElement.prototype.init.call(this);
}
cocktail.core.html.EmbeddedElement.prototype.initEmbeddedAsset = function() {
}
cocktail.core.html.EmbeddedElement.prototype.initCoreStyle = function() {
	this._coreStyle = new cocktail.core.style.EmbeddedCoreStyle(this);
}
cocktail.core.html.EmbeddedElement.prototype.appendChild = function(newChild) {
	return newChild;
}
cocktail.core.html.EmbeddedElement.prototype.removeChild = function(oldChild) {
	return oldChild;
}
cocktail.core.html.EmbeddedElement.prototype.get_embeddedAsset = function() {
	return this._embeddedAsset;
}
cocktail.core.html.EmbeddedElement.prototype.get_intrinsicHeight = function() {
	return this._intrinsicHeight;
}
cocktail.core.html.EmbeddedElement.prototype.get_intrinsicWidth = function() {
	return this._intrinsicWidth;
}
cocktail.core.html.EmbeddedElement.prototype.get_intrinsicRatio = function() {
	return this._intrinsicRatio;
}
cocktail.core.html.EmbeddedElement.prototype.set_width = function(value) {
	return this._width = value;
}
cocktail.core.html.EmbeddedElement.prototype.get_width = function() {
	return this._width;
}
cocktail.core.html.EmbeddedElement.prototype.set_height = function(value) {
	return this._height = value;
}
cocktail.core.html.EmbeddedElement.prototype.get_height = function() {
	return this._height;
}
cocktail.core.html.EmbeddedElement.prototype.__class__ = cocktail.core.html.EmbeddedElement;
cocktail.core.html.AbstractHTMLImageElement = function(p) {
	if( p === $_ ) return;
	this._imageLoader = new cocktail.core.resource.AbstractImageLoader();
	cocktail.core.html.EmbeddedElement.call(this,"img");
}
cocktail.core.html.AbstractHTMLImageElement.__name__ = ["cocktail","core","html","AbstractHTMLImageElement"];
cocktail.core.html.AbstractHTMLImageElement.__super__ = cocktail.core.html.EmbeddedElement;
for(var k in cocktail.core.html.EmbeddedElement.prototype ) cocktail.core.html.AbstractHTMLImageElement.prototype[k] = cocktail.core.html.EmbeddedElement.prototype[k];
cocktail.core.html.AbstractHTMLImageElement.prototype.onLoad = null;
cocktail.core.html.AbstractHTMLImageElement.prototype.onError = null;
cocktail.core.html.AbstractHTMLImageElement.prototype.naturalWidth = null;
cocktail.core.html.AbstractHTMLImageElement.prototype.naturalHeight = null;
cocktail.core.html.AbstractHTMLImageElement.prototype._src = null;
cocktail.core.html.AbstractHTMLImageElement.prototype.src = null;
cocktail.core.html.AbstractHTMLImageElement.prototype._imageLoader = null;
cocktail.core.html.AbstractHTMLImageElement.prototype.initEmbeddedAsset = function() {
	this._embeddedAsset = this._imageLoader.getNativeElement();
}
cocktail.core.html.AbstractHTMLImageElement.prototype.set_src = function(value) {
	this._src = value;
	this._imageLoader.load([value],$closure(this,"onLoadComplete"),$closure(this,"onLoadError"));
	return this._src;
}
cocktail.core.html.AbstractHTMLImageElement.prototype.onLoadComplete = function(image) {
	this._intrinsicHeight = this._imageLoader.getIntrinsicHeight();
	this._intrinsicWidth = this._imageLoader.getIntrinsicWidth();
	this._intrinsicRatio = this._intrinsicHeight / this._intrinsicWidth;
	this._coreStyle.invalidate();
	if(this.onLoad != null) {
		var loadEvent = new cocktail.core.event.Event("load",this);
		this.onLoad(loadEvent);
	}
}
cocktail.core.html.AbstractHTMLImageElement.prototype.onLoadError = function(message) {
	if(this.onError != null) this.onError(new cocktail.core.event.Event("error",this));
}
cocktail.core.html.AbstractHTMLImageElement.prototype.get_src = function() {
	return this._src;
}
cocktail.core.html.AbstractHTMLImageElement.prototype.get_naturalHeight = function() {
	if(this._intrinsicHeight == null) return 0;
	return this._intrinsicHeight;
}
cocktail.core.html.AbstractHTMLImageElement.prototype.get_naturalWidth = function() {
	if(this._intrinsicWidth == null) return 0;
	return this._intrinsicWidth;
}
cocktail.core.html.AbstractHTMLImageElement.prototype.__class__ = cocktail.core.html.AbstractHTMLImageElement;
Hash = function(p) {
	if( p === $_ ) return;
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
}
Hash.__name__ = ["Hash"];
Hash.prototype.h = null;
Hash.prototype.set = function(key,value) {
	this.h["$" + key] = value;
}
Hash.prototype.get = function(key) {
	return this.h["$" + key];
}
Hash.prototype.exists = function(key) {
	try {
		key = "$" + key;
		return this.hasOwnProperty.call(this.h,key);
	} catch( e ) {
		for(var i in this.h) if( i == key ) return true;
		return false;
	}
}
Hash.prototype.remove = function(key) {
	if(!this.exists(key)) return false;
	delete(this.h["$" + key]);
	return true;
}
Hash.prototype.keys = function() {
	var a = new Array();
	for(var i in this.h) a.push(i.substr(1));
	return a.iterator();
}
Hash.prototype.iterator = function() {
	return { ref : this.h, it : this.keys(), hasNext : function() {
		return this.it.hasNext();
	}, next : function() {
		var i = this.it.next();
		return this.ref["$" + i];
	}};
}
Hash.prototype.toString = function() {
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
	return s.b.join("");
}
Hash.prototype.__class__ = Hash;
IntHash = function(p) {
	if( p === $_ ) return;
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
}
IntHash.__name__ = ["IntHash"];
IntHash.prototype.h = null;
IntHash.prototype.set = function(key,value) {
	this.h[key] = value;
}
IntHash.prototype.get = function(key) {
	return this.h[key];
}
IntHash.prototype.exists = function(key) {
	return this.h[key] != null;
}
IntHash.prototype.remove = function(key) {
	if(this.h[key] == null) return false;
	delete(this.h[key]);
	return true;
}
IntHash.prototype.keys = function() {
	var a = new Array();
	for( x in this.h ) a.push(x);
	return a.iterator();
}
IntHash.prototype.iterator = function() {
	return { ref : this.h, it : this.keys(), hasNext : function() {
		return this.it.hasNext();
	}, next : function() {
		var i = this.it.next();
		return this.ref[i];
	}};
}
IntHash.prototype.toString = function() {
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
	return s.b.join("");
}
IntHash.prototype.__class__ = IntHash;
cocktail.core.html.AbstractHTMLHtmlElement = function(p) {
	if( p === $_ ) return;
	cocktail.port.browser.HTMLElement.call(this,"html");
}
cocktail.core.html.AbstractHTMLHtmlElement.__name__ = ["cocktail","core","html","AbstractHTMLHtmlElement"];
cocktail.core.html.AbstractHTMLHtmlElement.__super__ = cocktail.port.browser.HTMLElement;
for(var k in cocktail.port.browser.HTMLElement.prototype ) cocktail.core.html.AbstractHTMLHtmlElement.prototype[k] = cocktail.port.browser.HTMLElement.prototype[k];
cocktail.core.html.AbstractHTMLHtmlElement.prototype.__class__ = cocktail.core.html.AbstractHTMLHtmlElement;
cocktail.port.browser.HTMLHtmlElement = function(p) {
	if( p === $_ ) return;
	cocktail.core.html.AbstractHTMLHtmlElement.call(this);
}
cocktail.port.browser.HTMLHtmlElement.__name__ = ["cocktail","port","browser","HTMLHtmlElement"];
cocktail.port.browser.HTMLHtmlElement.__super__ = cocktail.core.html.AbstractHTMLHtmlElement;
for(var k in cocktail.core.html.AbstractHTMLHtmlElement.prototype ) cocktail.port.browser.HTMLHtmlElement.prototype[k] = cocktail.core.html.AbstractHTMLHtmlElement.prototype[k];
cocktail.port.browser.HTMLHtmlElement.prototype.appendChild = function(newChild) {
	this.removeFromParentIfNecessary(newChild);
	newChild.set_parentNode(this);
	this._childNodes.push(newChild);
	return newChild;
}
cocktail.port.browser.HTMLHtmlElement.prototype.__class__ = cocktail.port.browser.HTMLHtmlElement;
cocktail.core.style.formatter.BlockFormattingContext = function(formattingContextRoot) {
	if( formattingContextRoot === $_ ) return;
	cocktail.core.style.formatter.FormattingContext.call(this,formattingContextRoot);
}
cocktail.core.style.formatter.BlockFormattingContext.__name__ = ["cocktail","core","style","formatter","BlockFormattingContext"];
cocktail.core.style.formatter.BlockFormattingContext.__super__ = cocktail.core.style.formatter.FormattingContext;
for(var k in cocktail.core.style.formatter.FormattingContext.prototype ) cocktail.core.style.formatter.BlockFormattingContext.prototype[k] = cocktail.core.style.formatter.FormattingContext.prototype[k];
cocktail.core.style.formatter.BlockFormattingContext.prototype.doFormat = function(elementsInFormattingContext) {
	this.doFormat2(this._formattingContextRoot,0);
}
cocktail.core.style.formatter.BlockFormattingContext.prototype.doFormat2 = function(elementRenderer,concatenatedX) {
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
cocktail.core.style.formatter.BlockFormattingContext.prototype.getCollapsedMarginBottom = function(child) {
	var marginBottom = child.getCoreStyle().getComputedStyle().marginBottom;
	if(child.get_nextSibling() != null) {
		var nextSibling = child.get_nextSibling();
		if(nextSibling.getCoreStyle().getComputedStyle().marginTop > marginBottom) marginBottom = 0; else marginBottom -= nextSibling.getCoreStyle().getComputedStyle().marginTop;
	}
	return marginBottom;
}
cocktail.core.style.formatter.BlockFormattingContext.prototype.insertFloat = function(element) {
	var parent = element.get_parentNode();
	var floatData = this._floatsManager.computeFloatData(element,this._formattingContextData,Math.round(parent.getCoreStyle().getComputedStyle().width));
	var x = floatData.x + parent.getCoreStyle().getComputedStyle().paddingLeft;
	var y = floatData.y + parent.getCoreStyle().getComputedStyle().paddingTop;
	var width = floatData.width;
	var height = floatData.height;
	element.setBounds({ x : x, y : y, width : width, height : height});
}
cocktail.core.style.formatter.BlockFormattingContext.prototype.__class__ = cocktail.core.style.formatter.BlockFormattingContext;
cocktail.core.style.computer.VisualEffectStylesComputer = function(p) {
}
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
cocktail.core.style.computer.VisualEffectStylesComputer.prototype.__class__ = cocktail.core.style.computer.VisualEffectStylesComputer;
StringTools = function() { }
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
StringTools.prototype.__class__ = StringTools;
utest.ui.common.ReportTools = function() { }
utest.ui.common.ReportTools.__name__ = ["utest","ui","common","ReportTools"];
utest.ui.common.ReportTools.hasHeader = function(report,stats) {
	switch( (report.displayHeader)[1] ) {
	case 1:
		return false;
	case 2:
		if(!stats.isOk) return true;
		switch( (report.displaySuccessResults)[1] ) {
		case 1:
			return false;
		case 0:
		case 2:
			return true;
		}
		break;
	case 0:
		return true;
	}
}
utest.ui.common.ReportTools.skipResult = function(report,stats,isOk) {
	if(!stats.isOk) return false;
	return (function($this) {
		var $r;
		switch( (report.displaySuccessResults)[1] ) {
		case 1:
			$r = true;
			break;
		case 0:
			$r = false;
			break;
		case 2:
			$r = !isOk;
			break;
		}
		return $r;
	}(this));
}
utest.ui.common.ReportTools.hasOutput = function(report,stats) {
	if(!stats.isOk) return true;
	return utest.ui.common.ReportTools.hasHeader(report,stats);
}
utest.ui.common.ReportTools.prototype.__class__ = utest.ui.common.ReportTools;
if(typeof haxe=='undefined') haxe = {}
if(!haxe.io) haxe.io = {}
haxe.io.Bytes = function(length,b) {
	if( length === $_ ) return;
	this.length = length;
	this.b = b;
}
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
haxe.io.Bytes.prototype.length = null;
haxe.io.Bytes.prototype.b = null;
haxe.io.Bytes.prototype.get = function(pos) {
	return this.b[pos];
}
haxe.io.Bytes.prototype.set = function(pos,v) {
	this.b[pos] = v & 255;
}
haxe.io.Bytes.prototype.blit = function(pos,src,srcpos,len) {
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
haxe.io.Bytes.prototype.sub = function(pos,len) {
	if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
	return new haxe.io.Bytes(len,this.b.slice(pos,pos + len));
}
haxe.io.Bytes.prototype.compare = function(other) {
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
haxe.io.Bytes.prototype.readString = function(pos,len) {
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
haxe.io.Bytes.prototype.toString = function() {
	return this.readString(0,this.length);
}
haxe.io.Bytes.prototype.toHex = function() {
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
haxe.io.Bytes.prototype.getData = function() {
	return this.b;
}
haxe.io.Bytes.prototype.__class__ = haxe.io.Bytes;
if(!cocktail.core.focus) cocktail.core.focus = {}
cocktail.core.focus.FocusManager = function(p) {
	if( p === $_ ) return;
	this._focusManagerImpl = new cocktail.port.browser.FocusManagerImpl();
}
cocktail.core.focus.FocusManager.__name__ = ["cocktail","core","focus","FocusManager"];
cocktail.core.focus.FocusManager._instance = null;
cocktail.core.focus.FocusManager.getInstance = function() {
	if(cocktail.core.focus.FocusManager._instance == null) cocktail.core.focus.FocusManager._instance = new cocktail.core.focus.FocusManager();
	return cocktail.core.focus.FocusManager._instance;
}
cocktail.core.focus.FocusManager.prototype.bodyElement = null;
cocktail.core.focus.FocusManager.prototype.activeElement = null;
cocktail.core.focus.FocusManager.prototype._focusManagerImpl = null;
cocktail.core.focus.FocusManager.prototype.invalidate = function() {
	this._focusManagerImpl.invalidate();
}
cocktail.core.focus.FocusManager.prototype.setActiveElement = function(value) {
	return this._focusManagerImpl.setActiveElement(value);
}
cocktail.core.focus.FocusManager.prototype.getActiveElement = function() {
	return this._focusManagerImpl.getActiveElement();
}
cocktail.core.focus.FocusManager.prototype.setBodyElement = function(value) {
	return this._focusManagerImpl.setBodyElement(value);
}
cocktail.core.focus.FocusManager.prototype.getBodyElement = function() {
	return this._focusManagerImpl.getBodyElement();
}
cocktail.core.focus.FocusManager.prototype.__class__ = cocktail.core.focus.FocusManager;
if(!cocktail.core.style.positioner) cocktail.core.style.positioner = {}
cocktail.core.style.positioner.BoxPositioner = function(p) {
}
cocktail.core.style.positioner.BoxPositioner.__name__ = ["cocktail","core","style","positioner","BoxPositioner"];
cocktail.core.style.positioner.BoxPositioner.prototype.position = function(elementRenderer,containingHTMLElementData,staticPosition) {
	var htmlElement = elementRenderer.getCoreStyle().get_htmlElement();
	if(htmlElement.get_coreStyle().getLeft() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getLeftOffset(htmlElement,Math.round(staticPosition.x)); else if(htmlElement.get_coreStyle().getRight() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getRightOffset(htmlElement,containingHTMLElementData.width,Math.round(staticPosition.x)); else elementRenderer.getBounds().x = Math.round(staticPosition.x);
	if(htmlElement.get_coreStyle().getTop() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getTopOffset(htmlElement,Math.round(staticPosition.y)); else if(htmlElement.get_coreStyle().getBottom() != cocktail.core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getBottomOffset(htmlElement,containingHTMLElementData.height,Math.round(staticPosition.y)); else elementRenderer.getBounds().y = Math.round(staticPosition.y);
	return elementRenderer;
}
cocktail.core.style.positioner.BoxPositioner.prototype.getLeftOffset = function(htmlElement,staticPosition) {
	return htmlElement.get_coreStyle().getComputedStyle().left;
}
cocktail.core.style.positioner.BoxPositioner.prototype.getRightOffset = function(htmlElement,containingHTMLElementWidth,staticPosition) {
	return containingHTMLElementWidth - htmlElement.get_coreStyle().getComputedStyle().width + htmlElement.get_coreStyle().getComputedStyle().paddingLeft + htmlElement.get_coreStyle().getComputedStyle().width - htmlElement.get_coreStyle().getComputedStyle().right;
}
cocktail.core.style.positioner.BoxPositioner.prototype.getTopOffset = function(htmlElement,staticPosition) {
	return htmlElement.get_coreStyle().getComputedStyle().top;
}
cocktail.core.style.positioner.BoxPositioner.prototype.getBottomOffset = function(htmlElement,containingHTMLElementHeight,staticPosition) {
	return containingHTMLElementHeight - htmlElement.get_coreStyle().getComputedStyle().height + htmlElement.get_coreStyle().getComputedStyle().paddingTop + htmlElement.get_coreStyle().getComputedStyle().paddingBottom - htmlElement.get_coreStyle().getComputedStyle().bottom;
}
cocktail.core.style.positioner.BoxPositioner.prototype.__class__ = cocktail.core.style.positioner.BoxPositioner;
cocktail.core.style.positioner.AbsolutePositioner = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.positioner.BoxPositioner.call(this);
}
cocktail.core.style.positioner.AbsolutePositioner.__name__ = ["cocktail","core","style","positioner","AbsolutePositioner"];
cocktail.core.style.positioner.AbsolutePositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
for(var k in cocktail.core.style.positioner.BoxPositioner.prototype ) cocktail.core.style.positioner.AbsolutePositioner.prototype[k] = cocktail.core.style.positioner.BoxPositioner.prototype[k];
cocktail.core.style.positioner.AbsolutePositioner.prototype.__class__ = cocktail.core.style.positioner.AbsolutePositioner;
utest.ui.common.IReport = function() { }
utest.ui.common.IReport.__name__ = ["utest","ui","common","IReport"];
utest.ui.common.IReport.prototype.displaySuccessResults = null;
utest.ui.common.IReport.prototype.displayHeader = null;
utest.ui.common.IReport.prototype.setHandler = null;
utest.ui.common.IReport.prototype.__class__ = utest.ui.common.IReport;
cocktail.core.dom.CharacterData = function(p) {
	if( p === $_ ) return;
	cocktail.core.dom.Node.call(this);
}
cocktail.core.dom.CharacterData.__name__ = ["cocktail","core","dom","CharacterData"];
cocktail.core.dom.CharacterData.__super__ = cocktail.core.dom.Node;
for(var k in cocktail.core.dom.Node.prototype ) cocktail.core.dom.CharacterData.prototype[k] = cocktail.core.dom.Node.prototype[k];
cocktail.core.dom.CharacterData.prototype._data = null;
cocktail.core.dom.CharacterData.prototype.data = null;
cocktail.core.dom.CharacterData.prototype.get_nodeType = function() {
	return 3;
}
cocktail.core.dom.CharacterData.prototype.get_data = function() {
	return this._data;
}
cocktail.core.dom.CharacterData.prototype.set_data = function(value) {
	return this._data = value;
}
cocktail.core.dom.CharacterData.prototype.__class__ = cocktail.core.dom.CharacterData;
cocktail.core.dom.Text = function(p) {
	if( p === $_ ) return;
	cocktail.core.dom.CharacterData.call(this);
	this._textFragments = new Array();
}
cocktail.core.dom.Text.__name__ = ["cocktail","core","dom","Text"];
cocktail.core.dom.Text.__super__ = cocktail.core.dom.CharacterData;
for(var k in cocktail.core.dom.CharacterData.prototype ) cocktail.core.dom.Text.prototype[k] = cocktail.core.dom.CharacterData.prototype[k];
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
cocktail.core.dom.Text.prototype._nativeElement = null;
cocktail.core.dom.Text.prototype.nativeElement = null;
cocktail.core.dom.Text.prototype._textFragments = null;
cocktail.core.dom.Text.prototype.reset = function() {
	var _g1 = 0, _g = this._textFragments.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._textFragments[i].textRenderer = null;
	}
}
cocktail.core.dom.Text.prototype.getTextFragments = function(text) {
	if(this._textFragments.length == 0) this._textFragments = cocktail.core.dom.Text.doGetTextFragments(text);
	return this._textFragments;
}
cocktail.core.dom.Text.prototype.get_nativeElement = function() {
	return this._nativeElement;
}
cocktail.core.dom.Text.prototype.get_nodeValue = function() {
	return this._data;
}
cocktail.core.dom.Text.prototype.set_nodeValue = function(value) {
	return this.set_data(value);
}
cocktail.core.dom.Text.prototype.__class__ = cocktail.core.dom.Text;
cocktail.port.browser.Text = function(p) {
	if( p === $_ ) return;
	cocktail.core.dom.Text.call(this);
}
cocktail.port.browser.Text.__name__ = ["cocktail","port","browser","Text"];
cocktail.port.browser.Text.__super__ = cocktail.core.dom.Text;
for(var k in cocktail.core.dom.Text.prototype ) cocktail.port.browser.Text.prototype[k] = cocktail.core.dom.Text.prototype[k];
cocktail.port.browser.Text.prototype.set_data = function(value) {
	if(this._nativeElement == null) this._nativeElement = js.Lib.document.createTextNode(value); else this._nativeElement.nodeValue = value;
	cocktail.core.dom.Text.prototype.set_data.call(this,value);
	return value;
}
cocktail.port.browser.Text.prototype.__class__ = cocktail.port.browser.Text;
cocktail.core.focus.AbstractFocusManagerImpl = function(p) {
	if( p === $_ ) return;
	this.initKeyboardListeners();
}
cocktail.core.focus.AbstractFocusManagerImpl.__name__ = ["cocktail","core","focus","AbstractFocusManagerImpl"];
cocktail.core.focus.AbstractFocusManagerImpl.prototype._bodyElement = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype.bodyElement = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype._activeElement = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype.activeElement = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype._tabList = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype._tabListIndex = null;
cocktail.core.focus.AbstractFocusManagerImpl.prototype.initKeyboardListeners = function() {
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.invalidate = function() {
	this._tabList == null;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.onKeyDown = function(keyboardEvent) {
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.onKeyUp = function(keyEventData) {
	if(this._activeElement.get_onKeyUp() != null) (this._activeElement.get_onKeyUp())(keyEventData);
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.doTabFocus = function(reverse) {
	if(this._tabList == null) this._tabList = this.buildTabList(this._bodyElement);
	if(this.getActiveElement() != this._bodyElement) {
		if(reverse == false) {
			if(this._tabListIndex == this._tabList.length - 1) this._tabListIndex = 0; else this._tabListIndex++;
		} else if(this._tabListIndex == 0) this._tabListIndex = this._tabList.length - 1; else this._tabListIndex--;
	} else if(reverse == false) this._tabListIndex = 0; else this._tabListIndex = this._tabList.length - 1;
	this.setActiveElement(this._tabList[this._tabListIndex]);
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.buildTabList = function(htmlElement) {
	this._tabListIndex = 0;
	var orderedTabList = new Array();
	var indexedTabList = new Array();
	this.doBuildTabList(htmlElement,orderedTabList,indexedTabList);
	var _g1 = 0, _g = orderedTabList.length;
	while(_g1 < _g) {
		var i = _g1++;
		indexedTabList.push(orderedTabList[i]);
	}
	return indexedTabList;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.doBuildTabList = function(htmlElement,orderedTabList,indexedTabList) {
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.simulateMouseClick = function(keyEventData) {
	if(this.getActiveElement().get_onMouseDown() != null) {
		var mouseEvent = new cocktail.core.event.MouseEvent("mousedown",this._activeElement,0.0,0.0,0.0,0.0,0.0,false,false,false);
		(this.getActiveElement().get_onMouseDown())(mouseEvent);
	}
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.setActiveElement = function(value) {
	if(this._activeElement != null) {
		if(this._activeElement.get_onBlur() != null) (this._activeElement.get_onBlur())(new cocktail.core.event.Event("blur",this._activeElement));
	}
	if(value == null) value = this._bodyElement;
	if(value != this._activeElement) {
		this._activeElement = value;
		if(this._activeElement.get_onFocus() != null) (this._activeElement.get_onFocus())(new cocktail.core.event.Event("focus",this._activeElement));
	}
	return this._activeElement;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.getActiveElement = function() {
	return this._activeElement;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.setBodyElement = function(value) {
	this._bodyElement = value;
	this.setActiveElement(null);
	this.invalidate();
	return this._bodyElement;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.getBodyElement = function() {
	return this._bodyElement;
}
cocktail.core.focus.AbstractFocusManagerImpl.prototype.__class__ = cocktail.core.focus.AbstractFocusManagerImpl;
cocktail.port.browser.FocusManagerImpl = function(p) {
	if( p === $_ ) return;
	cocktail.core.focus.AbstractFocusManagerImpl.call(this);
}
cocktail.port.browser.FocusManagerImpl.__name__ = ["cocktail","port","browser","FocusManagerImpl"];
cocktail.port.browser.FocusManagerImpl.__super__ = cocktail.core.focus.AbstractFocusManagerImpl;
for(var k in cocktail.core.focus.AbstractFocusManagerImpl.prototype ) cocktail.port.browser.FocusManagerImpl.prototype[k] = cocktail.core.focus.AbstractFocusManagerImpl.prototype[k];
cocktail.port.browser.FocusManagerImpl.prototype.initKeyboardListeners = function() {
}
cocktail.port.browser.FocusManagerImpl.prototype.setActiveElement = function(value) {
	return this._activeElement = value;
}
cocktail.port.browser.FocusManagerImpl.prototype.setBodyElement = function(value) {
	return this._bodyElement = value;
}
cocktail.port.browser.FocusManagerImpl.prototype.__class__ = cocktail.port.browser.FocusManagerImpl;
utest.ui.Report = function() { }
utest.ui.Report.__name__ = ["utest","ui","Report"];
utest.ui.Report.create = function(runner,displaySuccessResults,headerDisplayMode) {
	var report;
	report = new utest.ui.text.HtmlReport(runner,null,true);
	if(null == displaySuccessResults) report.displaySuccessResults = utest.ui.common.SuccessResultsDisplayMode.ShowSuccessResultsWithNoErrors; else report.displaySuccessResults = displaySuccessResults;
	if(null == headerDisplayMode) report.displayHeader = utest.ui.common.HeaderDisplayMode.ShowHeaderWithResults; else report.displayHeader = headerDisplayMode;
	return report;
}
utest.ui.Report.prototype.__class__ = utest.ui.Report;
cocktail.core.renderer.LayerRenderer = function(rootRenderer) {
	if( rootRenderer === $_ ) return;
	this._rootRenderer = rootRenderer;
}
cocktail.core.renderer.LayerRenderer.__name__ = ["cocktail","core","renderer","LayerRenderer"];
cocktail.core.renderer.LayerRenderer.prototype._rootRenderer = null;
cocktail.core.renderer.LayerRenderer.prototype.dispose = function() {
	this._rootRenderer = null;
}
cocktail.core.renderer.LayerRenderer.prototype.render = function() {
	var nativeElements = new Array();
	if(this._rootRenderer.canHaveChildren() == true && this._rootRenderer.getCoreStyle().isInlineLevel() == false || this._rootRenderer.getCoreStyle().getDisplay() == cocktail.core.style.Display.inlineBlock) {
		var childLayers = this.renderChildLayer();
		var _g1 = 0, _g = childLayers.length;
		while(_g1 < _g) {
			var i = _g1++;
			nativeElements.push(childLayers[i]);
		}
		var inFlowChildren = this.renderInFlowChildren();
		var _g1 = 0, _g = inFlowChildren.length;
		while(_g1 < _g) {
			var i = _g1++;
			nativeElements.push(inFlowChildren[i]);
		}
		var childrenBlockContainerBackground = this.renderChildrenBlockContainerBackground();
		var _g1 = 0, _g = childrenBlockContainerBackground.length;
		while(_g1 < _g) {
			var i = _g1++;
			nativeElements.push(childrenBlockContainerBackground[i]);
		}
		var rootRendererBackground = this._rootRenderer.renderBackground();
		var _g1 = 0, _g = rootRendererBackground.length;
		while(_g1 < _g) {
			var i = _g1++;
			nativeElements.push(rootRendererBackground[i]);
		}
	} else {
		nativeElements = this._rootRenderer.render();
		var rootRendererBackground = this._rootRenderer.renderBackground();
		var _g1 = 0, _g = rootRendererBackground.length;
		while(_g1 < _g) {
			var i = _g1++;
			nativeElements.push(rootRendererBackground[i]);
		}
	}
	return nativeElements;
}
cocktail.core.renderer.LayerRenderer.prototype.renderChildrenBlockContainerBackground = function() {
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
cocktail.core.renderer.LayerRenderer.prototype.getBlockContainerChildren = function(rootRenderer) {
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
cocktail.core.renderer.LayerRenderer.prototype.renderChildLayer = function() {
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
cocktail.core.renderer.LayerRenderer.prototype.getChildLayers = function(rootRenderer,referenceLayer) {
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
cocktail.core.renderer.LayerRenderer.prototype.renderInFlowChildren = function() {
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
		var _g3 = 0, _g2 = nativeElements.length;
		while(_g3 < _g2) {
			var j = _g3++;
			ret.push(nativeElements[j]);
		}
		if(inFlowChildren[i].canHaveChildren() == false && inFlowChildren[i].isText() == false) {
			var bg = inFlowChildren[i].renderBackground();
			var _g3 = 0, _g2 = bg.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(bg[j]);
			}
		}
	}
	return ret;
}
cocktail.core.renderer.LayerRenderer.prototype.getInFlowChildren = function(rootRenderer) {
	var ret = new Array();
	if(rootRenderer.establishesNewFormattingContext() == true && rootRenderer.getCoreStyle().childrenInline() == true) {
		var blockBoxRenderer = rootRenderer;
		var _g1 = 0, _g = blockBoxRenderer.getLineBoxes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var _g3 = 0, _g2 = blockBoxRenderer.getLineBoxes()[i].length;
			while(_g3 < _g2) {
				var j = _g3++;
				if(blockBoxRenderer.getLineBoxes()[i][j].isPositioned() == false) ret.push(blockBoxRenderer.getLineBoxes()[i][j]);
			}
		}
	} else {
		var _g1 = 0, _g = rootRenderer.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = rootRenderer.get_childNodes()[i];
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
	return ret;
}
cocktail.core.renderer.LayerRenderer.prototype.setNativeMatrix = function(matrix) {
}
cocktail.core.renderer.LayerRenderer.prototype.getConcatenatedMatrix = function(matrix) {
	var currentMatrix = new cocktail.core.geom.Matrix();
	return currentMatrix;
}
cocktail.core.renderer.LayerRenderer.prototype.getConcatenatedMatrix2 = function(matrix) {
	var currentMatrix = new cocktail.core.geom.Matrix();
	return currentMatrix;
}
cocktail.core.renderer.LayerRenderer.prototype.__class__ = cocktail.core.renderer.LayerRenderer;
cocktail.core.style.positioner.RelativePositioner = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.positioner.BoxPositioner.call(this);
}
cocktail.core.style.positioner.RelativePositioner.__name__ = ["cocktail","core","style","positioner","RelativePositioner"];
cocktail.core.style.positioner.RelativePositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
for(var k in cocktail.core.style.positioner.BoxPositioner.prototype ) cocktail.core.style.positioner.RelativePositioner.prototype[k] = cocktail.core.style.positioner.BoxPositioner.prototype[k];
cocktail.core.style.positioner.RelativePositioner.prototype.getLeftOffset = function(htmlElement,staticPosition) {
	return staticPosition + htmlElement.get_coreStyle().getComputedStyle().left;
}
cocktail.core.style.positioner.RelativePositioner.prototype.getRightOffset = function(htmlElement,containingHTMLElementWidth,staticPosition) {
	return staticPosition - htmlElement.get_coreStyle().getComputedStyle().right;
}
cocktail.core.style.positioner.RelativePositioner.prototype.getTopOffset = function(htmlElement,staticPosition) {
	return staticPosition + htmlElement.get_coreStyle().getComputedStyle().top;
}
cocktail.core.style.positioner.RelativePositioner.prototype.getBottomOffset = function(htmlElement,containingHTMLElementHeight,staticPosition) {
	return staticPosition - htmlElement.get_coreStyle().getComputedStyle().bottom;
}
cocktail.core.style.positioner.RelativePositioner.prototype.__class__ = cocktail.core.style.positioner.RelativePositioner;
if(!utest.ui.text) utest.ui.text = {}
utest.ui.text.HtmlReport = function(runner,outputHandler,traceRedirected) {
	if( runner === $_ ) return;
	if(traceRedirected == null) traceRedirected = true;
	this.aggregator = new utest.ui.common.ResultAggregator(runner,true);
	runner.onStart.add($closure(this,"start"));
	this.aggregator.onComplete.add($closure(this,"complete"));
	if(null == outputHandler) this.setHandler($closure(this,"_handler")); else this.setHandler(outputHandler);
	if(traceRedirected) this.redirectTrace();
	this.displaySuccessResults = utest.ui.common.SuccessResultsDisplayMode.AlwaysShowSuccessResults;
	this.displayHeader = utest.ui.common.HeaderDisplayMode.AlwaysShowHeader;
}
utest.ui.text.HtmlReport.__name__ = ["utest","ui","text","HtmlReport"];
utest.ui.text.HtmlReport.prototype.traceRedirected = null;
utest.ui.text.HtmlReport.prototype.displaySuccessResults = null;
utest.ui.text.HtmlReport.prototype.displayHeader = null;
utest.ui.text.HtmlReport.prototype.handler = null;
utest.ui.text.HtmlReport.prototype.aggregator = null;
utest.ui.text.HtmlReport.prototype.oldTrace = null;
utest.ui.text.HtmlReport.prototype._traces = null;
utest.ui.text.HtmlReport.prototype.setHandler = function(handler) {
	this.handler = handler;
}
utest.ui.text.HtmlReport.prototype.redirectTrace = function() {
	if(this.traceRedirected) return;
	this._traces = [];
	this.oldTrace = haxe.Log.trace;
	haxe.Log.trace = $closure(this,"_trace");
}
utest.ui.text.HtmlReport.prototype.restoreTrace = function() {
	if(!this.traceRedirected) return;
	haxe.Log.trace = this.oldTrace;
}
utest.ui.text.HtmlReport.prototype._traceTime = null;
utest.ui.text.HtmlReport.prototype._trace = function(v,infos) {
	var time = haxe.Timer.stamp();
	var delta = this._traceTime == null?0:time - this._traceTime;
	this._traces.push({ msg : StringTools.htmlEscape(Std.string(v)), infos : infos, time : time - this.startTime, delta : delta, stack : haxe.Stack.callStack()});
	this._traceTime = haxe.Timer.stamp();
}
utest.ui.text.HtmlReport.prototype.startTime = null;
utest.ui.text.HtmlReport.prototype.start = function(e) {
	this.startTime = haxe.Timer.stamp();
}
utest.ui.text.HtmlReport.prototype.cls = function(stats) {
	if(stats.hasErrors) return "error"; else if(stats.hasFailures) return "failure"; else if(stats.hasWarnings) return "warn"; else return "ok";
}
utest.ui.text.HtmlReport.prototype.resultNumbers = function(buf,stats) {
	var numbers = [];
	if(stats.assertations == 1) numbers.push("<strong>1</strong> test"); else numbers.push("<strong>" + stats.assertations + "</strong> tests");
	if(stats.successes != stats.assertations) {
		if(stats.successes == 1) numbers.push("<strong>1</strong> pass"); else if(stats.successes > 0) numbers.push("<strong>" + stats.successes + "</strong> passes");
	}
	if(stats.errors == 1) numbers.push("<strong>1</strong> error"); else if(stats.errors > 0) numbers.push("<strong>" + stats.errors + "</strong> errors");
	if(stats.failures == 1) numbers.push("<strong>1</strong> failure"); else if(stats.failures > 0) numbers.push("<strong>" + stats.failures + "</strong> failures");
	if(stats.warnings == 1) numbers.push("<strong>1</strong> warning"); else if(stats.warnings > 0) numbers.push("<strong>" + stats.warnings + "</strong> warnings");
	buf.add(numbers.join(", "));
}
utest.ui.text.HtmlReport.prototype.blockNumbers = function(buf,stats) {
	buf.add("<div class=\"" + this.cls(stats) + "bg statnumbers\">");
	this.resultNumbers(buf,stats);
	buf.b[buf.b.length] = "</div>" == null?"null":"</div>";
}
utest.ui.text.HtmlReport.prototype.formatStack = function(stack,addNL) {
	if(addNL == null) addNL = true;
	var parts = [];
	var nl = addNL?"\n":"";
	var last = null;
	var count = 1;
	var _g = 0, _g1 = haxe.Stack.toString(stack).split("\n");
	while(_g < _g1.length) {
		var part = _g1[_g];
		++_g;
		if(StringTools.trim(part) == "") continue;
		if(-1 < part.indexOf("Called from utest.")) continue;
		if(part == last) parts[parts.length - 1] = part + " (#" + ++count + ")"; else {
			count = 1;
			parts.push(last = part);
		}
	}
	var s = "<ul><li>" + parts.join("</li>" + nl + "<li>") + "</li></ul>" + nl;
	return "<div>" + s + "</div>" + nl;
}
utest.ui.text.HtmlReport.prototype.addFixture = function(buf,result,name,isOk) {
	if(utest.ui.common.ReportTools.skipResult(this,result.stats,isOk)) return;
	buf.b[buf.b.length] = "<li class=\"fixture\"><div class=\"li\">" == null?"null":"<li class=\"fixture\"><div class=\"li\">";
	buf.add("<span class=\"" + this.cls(result.stats) + "bg fixtureresult\">");
	if(result.stats.isOk) buf.b[buf.b.length] = "OK " == null?"null":"OK "; else if(result.stats.hasErrors) buf.b[buf.b.length] = "ERROR " == null?"null":"ERROR "; else if(result.stats.hasFailures) buf.b[buf.b.length] = "FAILURE " == null?"null":"FAILURE "; else if(result.stats.hasWarnings) buf.b[buf.b.length] = "WARNING " == null?"null":"WARNING ";
	buf.b[buf.b.length] = "</span>" == null?"null":"</span>";
	buf.b[buf.b.length] = "<div class=\"fixturedetails\">" == null?"null":"<div class=\"fixturedetails\">";
	buf.add("<strong>" + name + "</strong>");
	buf.b[buf.b.length] = ": " == null?"null":": ";
	this.resultNumbers(buf,result.stats);
	var messages = [];
	var $it0 = result.iterator();
	while( $it0.hasNext() ) {
		var assertation = $it0.next();
		var $e = (assertation);
		switch( $e[1] ) {
		case 0:
			var pos = $e[2];
			break;
		case 1:
			var pos = $e[3], msg = $e[2];
			messages.push("<strong>line " + pos.lineNumber + "</strong>: <em>" + StringTools.htmlEscape(msg) + "</em>");
			break;
		case 2:
			var s = $e[3], e = $e[2];
			messages.push("<strong>error</strong>: <em>" + this.getErrorDescription(e) + "</em>\n<br/><strong>stack</strong>:" + this.getErrorStack(s,e));
			break;
		case 3:
			var s = $e[3], e = $e[2];
			messages.push("<strong>setup error</strong>: " + this.getErrorDescription(e) + "\n<br/><strong>stack</strong>:" + this.getErrorStack(s,e));
			break;
		case 4:
			var s = $e[3], e = $e[2];
			messages.push("<strong>tear-down error</strong>: " + this.getErrorDescription(e) + "\n<br/><strong>stack</strong>:" + this.getErrorStack(s,e));
			break;
		case 5:
			var s = $e[3], missedAsyncs = $e[2];
			messages.push("<strong>missed async call(s)</strong>: " + missedAsyncs);
			break;
		case 6:
			var s = $e[3], e = $e[2];
			messages.push("<strong>async error</strong>: " + this.getErrorDescription(e) + "\n<br/><strong>stack</strong>:" + this.getErrorStack(s,e));
			break;
		case 7:
			var msg = $e[2];
			messages.push(StringTools.htmlEscape(msg));
			break;
		}
	}
	if(messages.length > 0) {
		buf.b[buf.b.length] = "<div class=\"testoutput\">" == null?"null":"<div class=\"testoutput\">";
		buf.add(messages.join("<br/>"));
		buf.b[buf.b.length] = "</div>\n" == null?"null":"</div>\n";
	}
	buf.b[buf.b.length] = "</div>\n" == null?"null":"</div>\n";
	buf.b[buf.b.length] = "</div></li>\n" == null?"null":"</div></li>\n";
}
utest.ui.text.HtmlReport.prototype.getErrorDescription = function(e) {
	return Std.string(e);
}
utest.ui.text.HtmlReport.prototype.getErrorStack = function(s,e) {
	return this.formatStack(s);
}
utest.ui.text.HtmlReport.prototype.addClass = function(buf,result,name,isOk) {
	if(utest.ui.common.ReportTools.skipResult(this,result.stats,isOk)) return;
	buf.b[buf.b.length] = "<li>" == null?"null":"<li>";
	buf.add("<h2 class=\"classname\">" + name + "</h2>");
	this.blockNumbers(buf,result.stats);
	buf.b[buf.b.length] = "<ul>\n" == null?"null":"<ul>\n";
	var _g = 0, _g1 = result.methodNames();
	while(_g < _g1.length) {
		var mname = _g1[_g];
		++_g;
		this.addFixture(buf,result.get(mname),mname,isOk);
	}
	buf.b[buf.b.length] = "</ul>\n" == null?"null":"</ul>\n";
	buf.b[buf.b.length] = "</li>\n" == null?"null":"</li>\n";
}
utest.ui.text.HtmlReport.prototype.addPackages = function(buf,result,isOk) {
	if(utest.ui.common.ReportTools.skipResult(this,result.stats,isOk)) return;
	buf.b[buf.b.length] = "<ul id=\"utest-results-packages\">\n" == null?"null":"<ul id=\"utest-results-packages\">\n";
	var _g = 0, _g1 = result.packageNames(false);
	while(_g < _g1.length) {
		var name = _g1[_g];
		++_g;
		this.addPackage(buf,result.getPackage(name),name,isOk);
	}
	buf.b[buf.b.length] = "</ul>\n" == null?"null":"</ul>\n";
}
utest.ui.text.HtmlReport.prototype.addPackage = function(buf,result,name,isOk) {
	if(utest.ui.common.ReportTools.skipResult(this,result.stats,isOk)) return;
	if(name == "" && result.classNames().length == 0) return;
	buf.b[buf.b.length] = "<li>" == null?"null":"<li>";
	buf.add("<h2>" + name + "</h2>");
	this.blockNumbers(buf,result.stats);
	buf.b[buf.b.length] = "<ul>\n" == null?"null":"<ul>\n";
	var _g = 0, _g1 = result.classNames();
	while(_g < _g1.length) {
		var cname = _g1[_g];
		++_g;
		this.addClass(buf,result.getClass(cname),cname,isOk);
	}
	buf.b[buf.b.length] = "</ul>\n" == null?"null":"</ul>\n";
	buf.b[buf.b.length] = "</li>\n" == null?"null":"</li>\n";
}
utest.ui.text.HtmlReport.prototype.getHeader = function() {
	var buf = new StringBuf();
	if(!utest.ui.common.ReportTools.hasHeader(this,this.result.stats)) return "";
	var end = haxe.Timer.stamp();
	var time = Std["int"]((end - this.startTime) * 1000) / 1000;
	var msg = "TEST OK";
	if(this.result.stats.hasErrors) msg = "TEST ERRORS"; else if(this.result.stats.hasFailures) msg = "TEST FAILED"; else if(this.result.stats.hasWarnings) msg = "WARNING REPORTED";
	buf.add("<h1 class=\"" + this.cls(this.result.stats) + "bg header\">" + msg + "</h1>\n");
	buf.b[buf.b.length] = "<div class=\"headerinfo\">" == null?"null":"<div class=\"headerinfo\">";
	this.resultNumbers(buf,this.result.stats);
	buf.add(" performed on <strong>" + utest.ui.text.HtmlReport.platform + "</strong>, executed in <strong> " + time + " sec. </strong></div >\n ");
	return buf.b.join("");
}
utest.ui.text.HtmlReport.prototype.getTrace = function() {
	var buf = new StringBuf();
	if(this._traces == null || this._traces.length == 0) return "";
	buf.b[buf.b.length] = "<div class=\"trace\"><h2>traces</h2><ol>" == null?"null":"<div class=\"trace\"><h2>traces</h2><ol>";
	var _g = 0, _g1 = this._traces;
	while(_g < _g1.length) {
		var t = _g1[_g];
		++_g;
		buf.b[buf.b.length] = "<li><div class=\"li\">" == null?"null":"<li><div class=\"li\">";
		var stack = StringTools.replace(this.formatStack(t.stack,false),"'","\\'");
		var method = "<span class=\"tracepackage\">" + t.infos.className + "</span><br/>" + t.infos.methodName + "(" + t.infos.lineNumber + ")";
		buf.add("<span class=\"tracepos\" onmouseover=\"utestTooltip(this.parentNode, '" + stack + "')\" onmouseout=\"utestRemoveTooltip()\">");
		buf.b[buf.b.length] = method == null?"null":method;
		buf.b[buf.b.length] = "</span><span class=\"tracetime\">" == null?"null":"</span><span class=\"tracetime\">";
		buf.add("@ " + this.formatTime(t.time));
		if(Math.round(t.delta * 1000) > 0) buf.add(", ~" + this.formatTime(t.delta));
		buf.b[buf.b.length] = "</span><span class=\"tracemsg\">" == null?"null":"</span><span class=\"tracemsg\">";
		buf.add(StringTools.replace(StringTools.trim(t.msg),"\n","<br/>\n"));
		buf.b[buf.b.length] = "</span><div class=\"clr\"></div></div></li>" == null?"null":"</span><div class=\"clr\"></div></div></li>";
	}
	buf.b[buf.b.length] = "</ol></div>" == null?"null":"</ol></div>";
	return buf.b.join("");
}
utest.ui.text.HtmlReport.prototype.getResults = function() {
	var buf = new StringBuf();
	this.addPackages(buf,this.result,this.result.stats.isOk);
	return buf.b.join("");
}
utest.ui.text.HtmlReport.prototype.getAll = function() {
	if(!utest.ui.common.ReportTools.hasOutput(this,this.result.stats)) return ""; else return this.getHeader() + this.getTrace() + this.getResults();
}
utest.ui.text.HtmlReport.prototype.getHtml = function(title) {
	if(null == title) title = "utest: " + utest.ui.text.HtmlReport.platform;
	var s = this.getAll();
	if("" == s) return ""; else return this.wrapHtml(title,s);
}
utest.ui.text.HtmlReport.prototype.result = null;
utest.ui.text.HtmlReport.prototype.complete = function(result) {
	this.result = result;
	this.handler(this);
	this.restoreTrace();
}
utest.ui.text.HtmlReport.prototype.formatTime = function(t) {
	return Math.round(t * 1000) + " ms";
}
utest.ui.text.HtmlReport.prototype.cssStyle = function() {
	return "body, dd, dt {\r\n\tfont-family: Verdana, Arial, Sans-serif;\r\n\tfont-size: 12px;\r\n}\r\ndl {\r\n\twidth: 180px;\r\n}\r\ndd, dt {\r\n\tmargin : 0;\r\n\tpadding : 2px 5px;\r\n\tborder-top: 1px solid #f0f0f0;\r\n\tborder-left: 1px solid #f0f0f0;\r\n\tborder-right: 1px solid #CCCCCC;\r\n\tborder-bottom: 1px solid #CCCCCC;\r\n}\r\ndd.value {\r\n\ttext-align: center;\r\n\tbackground-color: #eeeeee;\r\n}\r\ndt {\r\n\ttext-align: left;\r\n\tbackground-color: #e6e6e6;\r\n\tfloat: left;\r\n\twidth: 100px;\r\n}\r\n\r\nh1, h2, h3, h4, h5, h6 {\r\n\tmargin: 0;\r\n\tpadding: 0;\r\n}\r\n\r\nh1 {\r\n\ttext-align: center;\r\n\tfont-weight: bold;\r\n\tpadding: 5px 0 4px 0;\r\n\tfont-family: Arial, Sans-serif;\r\n\tfont-size: 18px;\r\n\tborder-top: 1px solid #f0f0f0;\r\n\tborder-left: 1px solid #f0f0f0;\r\n\tborder-right: 1px solid #CCCCCC;\r\n\tborder-bottom: 1px solid #CCCCCC;\r\n\tmargin: 0 2px 0px 2px;\r\n}\r\n\r\nh2 {\r\n\tfont-weight: bold;\r\n\tpadding: 2px 0 2px 8px;\r\n\tfont-family: Arial, Sans-serif;\r\n\tfont-size: 13px;\r\n\tborder-top: 1px solid #f0f0f0;\r\n\tborder-left: 1px solid #f0f0f0;\r\n\tborder-right: 1px solid #CCCCCC;\r\n\tborder-bottom: 1px solid #CCCCCC;\r\n\tmargin: 0 0 0px 0;\r\n\tbackground-color: #FFFFFF;\r\n\tcolor: #777777;\r\n}\r\n\r\nh2.classname {\r\n\tcolor: #000000;\r\n}\r\n\r\n.okbg {\r\n\tbackground-color: #66FF55;\r\n}\r\n.errorbg {\r\n\tbackground-color: #CC1100;\r\n}\r\n.failurebg {\r\n\tbackground-color: #EE3322;\r\n}\r\n.warnbg {\r\n\tbackground-color: #FFCC99;\r\n}\r\n.headerinfo {\r\n\ttext-align: right;\r\n\tfont-size: 11px;\r\n\tfont - color: 0xCCCCCC;\r\n\tmargin: 0 2px 5px 2px;\r\n\tborder-left: 1px solid #f0f0f0;\r\n\tborder-right: 1px solid #CCCCCC;\r\n\tborder-bottom: 1px solid #CCCCCC;\r\n\tpadding: 2px;\r\n}\r\n\r\nli {\r\n\tpadding: 4px;\r\n\tmargin: 2px;\r\n\tborder-top: 1px solid #f0f0f0;\r\n\tborder-left: 1px solid #f0f0f0;\r\n\tborder-right: 1px solid #CCCCCC;\r\n\tborder-bottom: 1px solid #CCCCCC;\r\n\tbackground-color: #e6e6e6;\r\n}\r\n\r\nli.fixture {\r\n\tbackground-color: #f6f6f6;\r\n\tpadding-bottom: 6px;\r\n}\r\n\r\ndiv.fixturedetails {\r\n\tpadding-left: 108px;\r\n}\r\n\r\nul {\r\n\tpadding: 0;\r\n\tmargin: 6px 0 0 0;\r\n\tlist-style-type: none;\r\n}\r\n\r\nol {\r\n\tpadding: 0 0 0 28px;\r\n\tmargin: 0px 0 0 0;\r\n}\r\n\r\n.statnumbers {\r\n\tpadding: 2px 8px;\r\n}\r\n\r\n.fixtureresult {\r\n\twidth: 100px;\r\n\ttext-align: center;\r\n\tdisplay: block;\r\n\tfloat: left;\r\n\tfont-weight: bold;\r\n\tpadding: 1px;\r\n\tmargin: 0 0 0 0;\r\n}\r\n\r\n.testoutput {\r\n\tborder: 1px dashed #CCCCCC;\r\n\tmargin: 4px 0 0 0;\r\n\tpadding: 4px 8px;\r\n\tbackground-color: #eeeeee;\r\n}\r\n\r\nspan.tracepos, span.traceposempty {\r\n\tdisplay: block;\r\n\tfloat: left;\r\n\tfont-weight: bold;\r\n\tfont-size: 9px;\r\n\twidth: 170px;\r\n\tmargin: 2px 0 0 2px;\r\n}\r\n\r\nspan.tracepos:hover {\r\n\tcursor : pointer;\r\n\tbackground-color: #ffff99;\r\n}\r\n\r\nspan.tracemsg {\r\n\tdisplay: block;\r\n\tmargin-left: 180px;\r\n\tbackground-color: #eeeeee;\r\n\tpadding: 7px;\r\n}\r\n\r\nspan.tracetime {\r\n\tdisplay: block;\r\n\tfloat: right;\r\n\tmargin: 2px;\r\n\tfont-size: 9px;\r\n\tcolor: #777777;\r\n}\r\n\r\n\r\ndiv.trace ol {\r\n\tpadding: 0 0 0 40px;\r\n\tcolor: #777777;\r\n}\r\n\r\ndiv.trace li {\r\n\tpadding: 0;\r\n}\r\n\r\ndiv.trace li div.li {\r\n\tcolor: #000000;\r\n}\r\n\r\ndiv.trace h2 {\r\n\tmargin: 0 2px 0px 2px;\r\n\tpadding-left: 4px;\r\n}\r\n\r\n.tracepackage {\r\n\tcolor: #777777;\r\n\tfont-weight: normal;\r\n}\r\n\r\n.clr {\r\n\tclear: both;\r\n}\r\n\r\n#utesttip {\r\n\tmargin-top: -3px;\r\n\tmargin-left: 170px;\r\n\tfont-size: 9px;\r\n}\r\n\r\n#utesttip li {\r\n\tmargin: 0;\r\n\tbackground-color: #ffff99;\r\n\tpadding: 2px 4px;\r\n\tborder: 0;\r\n\tborder-bottom: 1px dashed #ffff33;\r\n}";
}
utest.ui.text.HtmlReport.prototype.jsScript = function() {
	return "function utestTooltip(ref, text) {\r\n\tvar el = document.getElementById(\"utesttip\");\r\n\tif(!el) {\r\n\t\tvar el = document.createElement(\"div\")\r\n\t\tel.id = \"utesttip\";\r\n\t\tel.style.position = \"absolute\";\r\n\t\tdocument.body.appendChild(el)\r\n\t}\r\n\tvar p = utestFindPos(ref);\r\n\tel.style.left = (4 + p[0]) + \"px\";\r\n\tel.style.top = (p[1] - 1) + \"px\";\r\n\tel.innerHTML =  text;\r\n}\r\n\r\nfunction utestFindPos(el) {\r\n\tvar left = 0;\r\n\tvar top = 0;\r\n\tdo {\r\n\t\tleft += el.offsetLeft;\r\n\t\ttop += el.offsetTop;\r\n\t} while(el = el.offsetParent)\r\n\treturn [left, top];\r\n}\r\n\r\nfunction utestRemoveTooltip() {\r\n\tvar el = document.getElementById(\"utesttip\")\r\n\tif(el)\r\n\t\tdocument.body.removeChild(el)\r\n}";
}
utest.ui.text.HtmlReport.prototype.wrapHtml = function(title,s) {
	return "<head>\n<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\" />\n<title>" + title + "</title>\r\n\t\t\t<style type=\"text/css\">" + this.cssStyle() + "</style>\r\n\t\t\t<script type=\"text/javascript\">\n" + this.jsScript() + "\n</script>\n</head>\r\n\t\t\t<body>\n" + s + "\n</body>\n</html>";
}
utest.ui.text.HtmlReport.prototype._handler = function(report) {
	var isDef = function(v) {
		return typeof v != 'undefined';
	};
	var head = js.Lib.document.getElementsByTagName("head")[0];
	var script = js.Lib.document.createElement("script");
	script.type = "text/javascript";
	var sjs = report.jsScript();
	if(isDef(script.text)) script.text = sjs; else script.innerHTML = sjs;
	head.appendChild(script);
	var style = js.Lib.document.createElement("style");
	style.type = "text/css";
	var scss = report.cssStyle();
	if(isDef(style.styleSheet)) style.styleSheet.cssText = scss; else if(isDef(style.cssText)) style.cssText = scss; else if(isDef(style.innerText)) style.innerText = scss; else style.innerHTML = scss;
	head.appendChild(style);
	var el = js.Lib.document.getElementById("utest-results");
	if(null == el) {
		el = js.Lib.document.createElement("div");
		el.id = "utest-results";
		js.Lib.document.body.appendChild(el);
	}
	el.innerHTML = report.getAll();
}
utest.ui.text.HtmlReport.prototype.__class__ = utest.ui.text.HtmlReport;
utest.ui.text.HtmlReport.__interfaces__ = [utest.ui.common.IReport];
if(!cocktail.core.style.adapter) cocktail.core.style.adapter = {}
cocktail.core.style.adapter.AbstractStyle = function(coreStyle) {
	if( coreStyle === $_ ) return;
	this._coreStyle = coreStyle;
}
cocktail.core.style.adapter.AbstractStyle.__name__ = ["cocktail","core","style","adapter","AbstractStyle"];
cocktail.core.style.adapter.AbstractStyle.prototype.display = null;
cocktail.core.style.adapter.AbstractStyle.prototype.position = null;
cocktail.core.style.adapter.AbstractStyle.prototype.cssFloat = null;
cocktail.core.style.adapter.AbstractStyle.prototype.clear = null;
cocktail.core.style.adapter.AbstractStyle.prototype.marginLeft = null;
cocktail.core.style.adapter.AbstractStyle.prototype.marginRight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.marginTop = null;
cocktail.core.style.adapter.AbstractStyle.prototype.marginBottom = null;
cocktail.core.style.adapter.AbstractStyle.prototype.paddingLeft = null;
cocktail.core.style.adapter.AbstractStyle.prototype.paddingRight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.paddingTop = null;
cocktail.core.style.adapter.AbstractStyle.prototype.paddingBottom = null;
cocktail.core.style.adapter.AbstractStyle.prototype.width = null;
cocktail.core.style.adapter.AbstractStyle.prototype.height = null;
cocktail.core.style.adapter.AbstractStyle.prototype.minHeight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.maxHeight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.minWidth = null;
cocktail.core.style.adapter.AbstractStyle.prototype.maxWidth = null;
cocktail.core.style.adapter.AbstractStyle.prototype.top = null;
cocktail.core.style.adapter.AbstractStyle.prototype.left = null;
cocktail.core.style.adapter.AbstractStyle.prototype.bottom = null;
cocktail.core.style.adapter.AbstractStyle.prototype.right = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundColor = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundImage = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundRepeat = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundOrigin = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundSize = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundPosition = null;
cocktail.core.style.adapter.AbstractStyle.prototype.backgroundClip = null;
cocktail.core.style.adapter.AbstractStyle.prototype.fontSize = null;
cocktail.core.style.adapter.AbstractStyle.prototype.fontWeight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.fontStyle = null;
cocktail.core.style.adapter.AbstractStyle.prototype.fontFamily = null;
cocktail.core.style.adapter.AbstractStyle.prototype.fontVariant = null;
cocktail.core.style.adapter.AbstractStyle.prototype.color = null;
cocktail.core.style.adapter.AbstractStyle.prototype.lineHeight = null;
cocktail.core.style.adapter.AbstractStyle.prototype.textTransform = null;
cocktail.core.style.adapter.AbstractStyle.prototype.letterSpacing = null;
cocktail.core.style.adapter.AbstractStyle.prototype.wordSpacing = null;
cocktail.core.style.adapter.AbstractStyle.prototype.whiteSpace = null;
cocktail.core.style.adapter.AbstractStyle.prototype.textAlign = null;
cocktail.core.style.adapter.AbstractStyle.prototype.textIndent = null;
cocktail.core.style.adapter.AbstractStyle.prototype.verticalAlign = null;
cocktail.core.style.adapter.AbstractStyle.prototype.opacity = null;
cocktail.core.style.adapter.AbstractStyle.prototype.visibility = null;
cocktail.core.style.adapter.AbstractStyle.prototype.overflowX = null;
cocktail.core.style.adapter.AbstractStyle.prototype.overflowY = null;
cocktail.core.style.adapter.AbstractStyle.prototype.cursor = null;
cocktail.core.style.adapter.AbstractStyle.prototype._coreStyle = null;
cocktail.core.style.adapter.AbstractStyle.prototype.get_opacity = function() {
	return cocktail.core.unit.UnitManager.getCSSOpacity(this._coreStyle.getOpacity());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_opacity = function(value) {
	this._coreStyle.setOpacity(Std.parseFloat(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_visibility = function() {
	return cocktail.core.unit.UnitManager.getCSSVisibility(this._coreStyle.getVisibility());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_visibility = function(value) {
	this._coreStyle.setVisibility(cocktail.core.unit.UnitManager.visibilityEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_marginLeft = function() {
	return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginLeft());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_marginLeft = function(value) {
	this._coreStyle.setMarginLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_marginRight = function() {
	return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginRight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_marginRight = function(value) {
	this._coreStyle.setMarginRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_marginTop = function() {
	return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginTop());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_marginTop = function(value) {
	this._coreStyle.setMarginTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_marginBottom = function() {
	return cocktail.core.unit.UnitManager.getCSSMargin(this._coreStyle.getMarginBottom());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_marginBottom = function(value) {
	this._coreStyle.setMarginBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_paddingLeft = function() {
	return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingLeft());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingLeft = function(value) {
	this._coreStyle.setPaddingLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_paddingRight = function() {
	return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingRight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingRight = function(value) {
	this._coreStyle.setPaddingRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_paddingTop = function() {
	return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingTop());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingTop = function(value) {
	this._coreStyle.setPaddingTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_paddingBottom = function() {
	return cocktail.core.unit.UnitManager.getCSSPadding(this._coreStyle.getPaddingBottom());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingBottom = function(value) {
	this._coreStyle.setPaddingBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Padding,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_display = function() {
	return cocktail.core.unit.UnitManager.getCSSDisplay(this._coreStyle.getDisplay());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_display = function(value) {
	this._coreStyle.setDisplay(cocktail.core.unit.UnitManager.displayEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_position = function() {
	return cocktail.core.unit.UnitManager.getCSSPosition(this._coreStyle.getPosition());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_position = function(value) {
	this._coreStyle.setPosition(cocktail.core.unit.UnitManager.positionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_width = function() {
	return cocktail.core.unit.UnitManager.getCSSDimension(this._coreStyle.getWidth());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_width = function(value) {
	this._coreStyle.setWidth(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Dimension,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_height = function() {
	return cocktail.core.unit.UnitManager.getCSSDimension(this._coreStyle.getHeight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_height = function(value) {
	this._coreStyle.setHeight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Dimension,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_minHeight = function() {
	return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMinHeight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_minHeight = function(value) {
	this._coreStyle.setMinHeight(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_maxHeight = function() {
	return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMaxHeight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_maxHeight = function(value) {
	this._coreStyle.setMaxHeight(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_minWidth = function() {
	return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMinWidth());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_minWidth = function(value) {
	this._coreStyle.setMinWidth(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_maxWidth = function() {
	return cocktail.core.unit.UnitManager.getCSSConstrainedDimension(this._coreStyle.getMaxWidth());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_maxWidth = function(value) {
	this._coreStyle.setMaxWidth(cocktail.core.unit.UnitManager.constrainedDimensionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_top = function() {
	return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getTop());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_top = function(value) {
	this._coreStyle.setTop(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_left = function() {
	return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getLeft());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_left = function(value) {
	this._coreStyle.setLeft(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_bottom = function() {
	return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getBottom());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_bottom = function(value) {
	this._coreStyle.setBottom(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_right = function() {
	return cocktail.core.unit.UnitManager.getCSSPositionOffset(this._coreStyle.getRight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_right = function(value) {
	this._coreStyle.setRight(cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.PositionOffset,value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_CSSFloat = function() {
	return cocktail.core.unit.UnitManager.getCSSFloatAsString(this._coreStyle.getCSSFloat());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_CSSFloat = function(value) {
	this._coreStyle.setCSSFloat(cocktail.core.unit.UnitManager.cssFloatEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_clear = function() {
	return cocktail.core.unit.UnitManager.getCSSClear(this._coreStyle.getClear());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_clear = function(value) {
	this._coreStyle.setClear(cocktail.core.unit.UnitManager.clearEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_fontSize = function() {
	return cocktail.core.unit.UnitManager.getCSSFontSize(this._coreStyle.getFontSize());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_fontSize = function(value) {
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_fontWeight = function() {
	return cocktail.core.unit.UnitManager.getCSSFontWeight(this._coreStyle.getFontWeight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_fontWeight = function(value) {
	this._coreStyle.setFontWeight(cocktail.core.unit.UnitManager.fontWeightEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_fontStyle = function() {
	return cocktail.core.unit.UnitManager.getCSSFontStyle(this._coreStyle.getFontStyle());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_fontStyle = function(value) {
	this._coreStyle.setFontStyle(cocktail.core.unit.UnitManager.fontStyleEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_fontFamily = function() {
	return cocktail.core.unit.UnitManager.getCSSFontFamily(this._coreStyle.getFontFamily());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_fontFamily = function(value) {
	this._coreStyle.setFontFamily(cocktail.core.unit.UnitManager.fontFamilyEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_fontVariant = function() {
	return cocktail.core.unit.UnitManager.getCSSFontVariant(this._coreStyle.getFontVariant());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_fontVariant = function(value) {
	this._coreStyle.setFontVariant(cocktail.core.unit.UnitManager.fontVariantEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_textTransform = function() {
	return cocktail.core.unit.UnitManager.getCSSTextTransform(this._coreStyle.getTextTransform());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_textTransform = function(value) {
	this._coreStyle.setTextTransform(cocktail.core.unit.UnitManager.textTransformEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_letterSpacing = function() {
	return cocktail.core.unit.UnitManager.getCSSLetterSpacing(this._coreStyle.getLetterSpacing());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_letterSpacing = function(value) {
	this._coreStyle.setLetterSpacing(cocktail.core.unit.UnitManager.letterSpacingEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_color = function() {
	return cocktail.core.unit.UnitManager.getCSSColor(this._coreStyle.getColor());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_color = function(value) {
	this._coreStyle.setColor(cocktail.core.unit.UnitManager.colorEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_wordSpacing = function() {
	return cocktail.core.unit.UnitManager.getCSSWordSpacing(this._coreStyle.getWordSpacing());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_wordSpacing = function(value) {
	this._coreStyle.setWordSpacing(cocktail.core.unit.UnitManager.wordSpacingEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_lineHeight = function() {
	return cocktail.core.unit.UnitManager.getCSSLineHeight(this._coreStyle.getLineHeight());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_lineHeight = function(value) {
	this._coreStyle.setLineHeight(cocktail.core.unit.UnitManager.lineHeightEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_verticalAlign = function() {
	return cocktail.core.unit.UnitManager.getCSSVerticalAlign(this._coreStyle.getVerticalAlign());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_verticalAlign = function(value) {
	this._coreStyle.setVerticalAlign(cocktail.core.unit.UnitManager.verticalAlignEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_textIndent = function() {
	return cocktail.core.unit.UnitManager.getCSSTextIndent(this._coreStyle.getTextIndent());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_textIndent = function(value) {
	this._coreStyle.setTextIndent(cocktail.core.unit.UnitManager.textIndentEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_whiteSpace = function() {
	return cocktail.core.unit.UnitManager.getCSSWhiteSpace(this._coreStyle.getWhiteSpace());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_whiteSpace = function(value) {
	this._coreStyle.setWhiteSpace(cocktail.core.unit.UnitManager.whiteSpaceEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_textAlign = function() {
	return cocktail.core.unit.UnitManager.getCSSTextAlign(this._coreStyle.getTextAlign());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_textAlign = function(value) {
	this._coreStyle.setTextAlign(cocktail.core.unit.UnitManager.textAlignEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundColor = function(value) {
	this._coreStyle.setBackgroundColor(cocktail.core.unit.UnitManager.colorEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundColor = function() {
	return cocktail.core.unit.UnitManager.getCSSColor(this._coreStyle.getBackgroundColor());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundImage = function(value) {
	this._coreStyle.setBackgroundImage(cocktail.core.unit.UnitManager.backgroundImageEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundImage = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundImage(this._coreStyle.getBackgroundImage());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundRepeat = function(value) {
	this._coreStyle.setBackgroundRepeat(cocktail.core.unit.UnitManager.backgroundRepeatEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundRepeat = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundRepeat(this._coreStyle.getBackgroundRepeat());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundSize = function(value) {
	this._coreStyle.setBackgroundSize(cocktail.core.unit.UnitManager.backgroundSizeEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundSize = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundSize(this._coreStyle.getBackgroundSize());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundClip = function(value) {
	this._coreStyle.setBackgroundClip(cocktail.core.unit.UnitManager.backgroundClipEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundClip = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundClip(this._coreStyle.getBackgroundClip());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundPosition = function(value) {
	this._coreStyle.setBackgroundPosition(cocktail.core.unit.UnitManager.backgroundPositionEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundPosition = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundPosition(this._coreStyle.getBackgroundPosition());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundOrigin = function(value) {
	this._coreStyle.setBackgroundOrigin(cocktail.core.unit.UnitManager.backgroundOriginEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_backgroundOrigin = function() {
	return cocktail.core.unit.UnitManager.getCSSBackgroundOrigin(this._coreStyle.getBackgroundOrigin());
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_overflowX = function() {
	return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowX());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowX = function(value) {
	this._coreStyle.setOverflowX(cocktail.core.unit.UnitManager.overflowEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_overflowY = function() {
	return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowY());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowY = function(value) {
	this._coreStyle.setOverflowY(cocktail.core.unit.UnitManager.overflowEnum(value));
	return cocktail.core.unit.UnitManager.getCSSOverflow(this._coreStyle.getOverflowY());
}
cocktail.core.style.adapter.AbstractStyle.prototype.set_cursor = function(value) {
	this._coreStyle.setCursor(cocktail.core.unit.UnitManager.cursorEnum(value));
	return value;
}
cocktail.core.style.adapter.AbstractStyle.prototype.get_cursor = function() {
	return cocktail.core.unit.UnitManager.getCSSCursor(this._coreStyle.getCursor());
}
cocktail.core.style.adapter.AbstractStyle.prototype.__class__ = cocktail.core.style.adapter.AbstractStyle;
if(typeof js=='undefined') js = {}
js.Boot = function() { }
js.Boot.__name__ = ["js","Boot"];
js.Boot.__unhtml = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
}
js.Boot.__trace = function(v,i) {
	var msg = i != null?i.fileName + ":" + i.lineNumber + ": ":"";
	msg += js.Boot.__unhtml(js.Boot.__string_rec(v,"")) + "<br/>";
	var d = document.getElementById("haxe:trace");
	if(d == null) alert("No haxe:trace element defined\n" + msg); else d.innerHTML += msg;
}
js.Boot.__clear_trace = function() {
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML = "";
}
js.Boot.__closure = function(o,f) {
	var m = o[f];
	if(m == null) return null;
	var f1 = function() {
		return m.apply(o,arguments);
	};
	f1.scope = o;
	f1.method = m;
	return f1;
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
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__") {
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
		if(x != x) return null;
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
	$closure = js.Boot.__closure;
}
js.Boot.prototype.__class__ = js.Boot;
utest.ui.common.ResultStats = function(p) {
	if( p === $_ ) return;
	this.assertations = 0;
	this.successes = 0;
	this.failures = 0;
	this.errors = 0;
	this.warnings = 0;
	this.isOk = true;
	this.hasFailures = false;
	this.hasErrors = false;
	this.hasWarnings = false;
	this.onAddSuccesses = new utest.Dispatcher();
	this.onAddFailures = new utest.Dispatcher();
	this.onAddErrors = new utest.Dispatcher();
	this.onAddWarnings = new utest.Dispatcher();
}
utest.ui.common.ResultStats.__name__ = ["utest","ui","common","ResultStats"];
utest.ui.common.ResultStats.prototype.assertations = null;
utest.ui.common.ResultStats.prototype.successes = null;
utest.ui.common.ResultStats.prototype.failures = null;
utest.ui.common.ResultStats.prototype.errors = null;
utest.ui.common.ResultStats.prototype.warnings = null;
utest.ui.common.ResultStats.prototype.onAddSuccesses = null;
utest.ui.common.ResultStats.prototype.onAddFailures = null;
utest.ui.common.ResultStats.prototype.onAddErrors = null;
utest.ui.common.ResultStats.prototype.onAddWarnings = null;
utest.ui.common.ResultStats.prototype.isOk = null;
utest.ui.common.ResultStats.prototype.hasFailures = null;
utest.ui.common.ResultStats.prototype.hasErrors = null;
utest.ui.common.ResultStats.prototype.hasWarnings = null;
utest.ui.common.ResultStats.prototype.addSuccesses = function(v) {
	if(v == 0) return;
	this.assertations += v;
	this.successes += v;
	this.onAddSuccesses.dispatch(v);
}
utest.ui.common.ResultStats.prototype.addFailures = function(v) {
	if(v == 0) return;
	this.assertations += v;
	this.failures += v;
	this.hasFailures = this.failures > 0;
	this.isOk = !(this.hasFailures || this.hasErrors || this.hasWarnings);
	this.onAddFailures.dispatch(v);
}
utest.ui.common.ResultStats.prototype.addErrors = function(v) {
	if(v == 0) return;
	this.assertations += v;
	this.errors += v;
	this.hasErrors = this.errors > 0;
	this.isOk = !(this.hasFailures || this.hasErrors || this.hasWarnings);
	this.onAddErrors.dispatch(v);
}
utest.ui.common.ResultStats.prototype.addWarnings = function(v) {
	if(v == 0) return;
	this.assertations += v;
	this.warnings += v;
	this.hasWarnings = this.warnings > 0;
	this.isOk = !(this.hasFailures || this.hasErrors || this.hasWarnings);
	this.onAddWarnings.dispatch(v);
}
utest.ui.common.ResultStats.prototype.sum = function(other) {
	this.addSuccesses(other.successes);
	this.addFailures(other.failures);
	this.addErrors(other.errors);
	this.addWarnings(other.warnings);
}
utest.ui.common.ResultStats.prototype.subtract = function(other) {
	this.addSuccesses(-other.successes);
	this.addFailures(-other.failures);
	this.addErrors(-other.errors);
	this.addWarnings(-other.warnings);
}
utest.ui.common.ResultStats.prototype.wire = function(dependant) {
	dependant.onAddSuccesses.add($closure(this,"addSuccesses"));
	dependant.onAddFailures.add($closure(this,"addFailures"));
	dependant.onAddErrors.add($closure(this,"addErrors"));
	dependant.onAddWarnings.add($closure(this,"addWarnings"));
	this.sum(dependant);
}
utest.ui.common.ResultStats.prototype.unwire = function(dependant) {
	dependant.onAddSuccesses.remove($closure(this,"addSuccesses"));
	dependant.onAddFailures.remove($closure(this,"addFailures"));
	dependant.onAddErrors.remove($closure(this,"addErrors"));
	dependant.onAddWarnings.remove($closure(this,"addWarnings"));
	this.subtract(dependant);
}
utest.ui.common.ResultStats.prototype.__class__ = utest.ui.common.ResultStats;
if(!cocktail.core.font) cocktail.core.font = {}
cocktail.core.font.AbstractFontManager = function(p) {
	if( p === $_ ) return;
	if(cocktail.core.font.AbstractFontManager._fontLoaderArray == null) cocktail.core.font.AbstractFontManager._fontLoaderArray = new Array();
	if(cocktail.core.font.AbstractFontManager._loadedFonts == null) cocktail.core.font.AbstractFontManager._loadedFonts = new Array();
}
cocktail.core.font.AbstractFontManager.__name__ = ["cocktail","core","font","AbstractFontManager"];
cocktail.core.font.AbstractFontManager._loadedFonts = null;
cocktail.core.font.AbstractFontManager._fontLoaderArray = null;
cocktail.core.font.AbstractFontManager.prototype.loadFont = function(url,name,successCallback,errorCallback) {
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
	fontLoader.addCallback($closure(this,"_onFontLoadingSuccess"),$closure(this,"_onFontLoadingError"));
	fontLoader.addCallback(successCallback,errorCallback);
	fontLoader.load(url,name);
	cocktail.core.font.AbstractFontManager._fontLoaderArray.push(fontLoader);
}
cocktail.core.font.AbstractFontManager.prototype.getEmbeddedFonts = function() {
	return cocktail.core.font.AbstractFontManager._loadedFonts;
}
cocktail.core.font.AbstractFontManager.prototype.getSystemFonts = function() {
	throw "Virtual method should be implemented in sub class";
	return null;
}
cocktail.core.font.AbstractFontManager.prototype.hasFont = function(fontName) {
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
cocktail.core.font.AbstractFontManager.prototype.getFontMetrics = function(fontFamily,fontSize) {
	throw "Virtual method should be implemented in sub class";
	return null;
}
cocktail.core.font.AbstractFontManager.prototype.createNativeTextElement = function(text,computedStyle) {
	throw "Virtual method should be implemented in sub class";
	return null;
}
cocktail.core.font.AbstractFontManager.prototype.applyTextTransform = function(text,textTransform) {
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
cocktail.core.font.AbstractFontManager.prototype.capitalizeText = function(text) {
	var capitalizedText = text.charAt(0);
	var _g1 = 1, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
	}
	return capitalizedText;
}
cocktail.core.font.AbstractFontManager.prototype._onFontLoadingSuccess = function(fontData) {
	cocktail.core.font.AbstractFontManager._loadedFonts.push(fontData);
	if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font was successfully loaded",{ fileName : "AbstractFontManager.hx", lineNumber : 212, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingSuccess"});
}
cocktail.core.font.AbstractFontManager.prototype._onFontLoadingError = function(fontData,errorStr) {
	haxe.Log.trace("font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 221, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingError"});
	if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 227, className : "cocktail.core.font.AbstractFontManager", methodName : "_onFontLoadingError"});
}
cocktail.core.font.AbstractFontManager.prototype._removeFontLoader = function(fontData) {
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
cocktail.core.font.AbstractFontManager.prototype.__class__ = cocktail.core.font.AbstractFontManager;
cocktail.core.style.computer.DisplayStylesComputer = function(p) {
}
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
cocktail.core.style.computer.DisplayStylesComputer.prototype.__class__ = cocktail.core.style.computer.DisplayStylesComputer;
cocktail.port.browser.Style = function(coreStyle) {
	if( coreStyle === $_ ) return;
	cocktail.core.style.adapter.AbstractStyle.call(this,coreStyle);
}
cocktail.port.browser.Style.__name__ = ["cocktail","port","browser","Style"];
cocktail.port.browser.Style.__super__ = cocktail.core.style.adapter.AbstractStyle;
for(var k in cocktail.core.style.adapter.AbstractStyle.prototype ) cocktail.port.browser.Style.prototype[k] = cocktail.core.style.adapter.AbstractStyle.prototype[k];
cocktail.port.browser.Style.prototype.getVendorSpecificStyleName = function(nativeStyle,styleName) {
	var vendorSpecificStyleName;
	if(Reflect.hasField(nativeStyle,styleName)) vendorSpecificStyleName = styleName; else {
		var styleNameCap = styleName.charAt(0).toUpperCase();
		var styleNameEnd = styleName.substr(1);
		styleName = styleNameCap + styleNameEnd;
		if(Reflect.field(nativeStyle,"Moz" + styleName) != null) vendorSpecificStyleName = "Moz" + styleName; else if(Reflect.field(nativeStyle,"Webkit" + styleName) != null) vendorSpecificStyleName = "Webkit" + styleName; else if(Reflect.field(nativeStyle,"Ms" + styleName) != null) vendorSpecificStyleName = "Ms" + styleName; else if(Reflect.field(nativeStyle,"O" + styleName) != null) vendorSpecificStyleName = "O" + styleName; else vendorSpecificStyleName = null;
	}
	return vendorSpecificStyleName;
}
cocktail.port.browser.Style.prototype.set_verticalAlign = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.verticalAlign = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_verticalAlign.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_color = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.color = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_color.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_wordSpacing = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.wordSpacing = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_wordSpacing.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_letterSpacing = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.letterSpacing = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_letterSpacing.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_textTransform = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.textTransform = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_textTransform.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_fontVariant = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.fontVariant = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_fontVariant.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_fontFamily = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.fontFamily = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_fontFamily.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_fontWeight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.fontWeight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_fontWeight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_fontStyle = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.fontStyle = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_fontStyle.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_fontSize = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.fontSize = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_fontSize.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_lineHeight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.lineHeight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_lineHeight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_marginLeft = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.marginLeft = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_marginLeft.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_marginRight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.marginRight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_marginRight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_marginTop = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.marginTop = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_marginTop.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_marginBottom = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.marginBottom = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_marginBottom.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_paddingLeft = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.paddingLeft = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingLeft.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_paddingRight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.paddingRight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingRight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_paddingTop = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.paddingTop = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingTop.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_paddingBottom = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.paddingBottom = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_paddingBottom.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_display = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.display = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_display.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_position = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.position = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_position.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_width = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.width = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_width.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_height = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.height = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_height.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_minHeight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.minHeight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_minHeight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_maxHeight = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.maxHeight = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_maxHeight.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_minWidth = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.minWidth = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_minWidth.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_maxWidth = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.maxWidth = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_maxWidth.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_top = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.top = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_top.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_left = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.left = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_left.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_bottom = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.bottom = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_bottom.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_right = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.right = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_right.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_textIndent = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.textIndent = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_textIndent.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_CSSFloat = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.cssFloat = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_CSSFloat.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_clear = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.clear = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_clear.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_whiteSpace = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.whiteSpace = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_whiteSpace.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_textAlign = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.textAlign = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_textAlign.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_opacity = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.opacity = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_opacity.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_visibility = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.visibility = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_visibility.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundColor = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundColor = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundColor.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundOrigin = function(value) {
	var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
	var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundOrigin");
	if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundOrigin.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundClip = function(value) {
	var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
	var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundClip");
	if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundClip.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundImage = function(value) {
	var cssBackgroundImage = value;
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = cssBackgroundImage;
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-webkit-linear-gradient");
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-moz-linear-gradient");
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundImage.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundPosition = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundPosition = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundPosition.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundSize = function(value) {
	var nativeStyle = this._coreStyle.get_htmlElement().get_nativeElement().style;
	var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundSize");
	if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundSize.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_backgroundRepeat = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.backgroundRepeat = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_backgroundRepeat.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_overflowX = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.overflowX = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowX.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_overflowY = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.overflowY = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_overflowY.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.set_cursor = function(value) {
	this._coreStyle.get_htmlElement().get_nativeElement().style.cursor = value;
	cocktail.core.style.adapter.AbstractStyle.prototype.set_cursor.call(this,value);
	return value;
}
cocktail.port.browser.Style.prototype.__class__ = cocktail.port.browser.Style;
cocktail.core.renderer.EmbeddedBoxRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.BoxRenderer.call(this,style);
	var computedStyle = style.getComputedStyle();
	this._bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	this._bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
}
cocktail.core.renderer.EmbeddedBoxRenderer.__name__ = ["cocktail","core","renderer","EmbeddedBoxRenderer"];
cocktail.core.renderer.EmbeddedBoxRenderer.__super__ = cocktail.core.renderer.BoxRenderer;
for(var k in cocktail.core.renderer.BoxRenderer.prototype ) cocktail.core.renderer.EmbeddedBoxRenderer.prototype[k] = cocktail.core.renderer.BoxRenderer.prototype[k];
cocktail.core.renderer.EmbeddedBoxRenderer.prototype.render = function() {
	var ret = [];
	var embeddedHTMLElement = this._coreStyle.get_htmlElement();
	ret.push(embeddedHTMLElement.get_embeddedAsset());
	return ret;
}
cocktail.core.renderer.EmbeddedBoxRenderer.prototype.__class__ = cocktail.core.renderer.EmbeddedBoxRenderer;
utest.ui.common.ClassResult = function(className,setupName,teardownName) {
	if( className === $_ ) return;
	this.fixtures = new Hash();
	this.className = className;
	this.setupName = setupName;
	this.hasSetup = setupName != null;
	this.teardownName = teardownName;
	this.hasTeardown = teardownName != null;
	this.methods = 0;
	this.stats = new utest.ui.common.ResultStats();
}
utest.ui.common.ClassResult.__name__ = ["utest","ui","common","ClassResult"];
utest.ui.common.ClassResult.prototype.fixtures = null;
utest.ui.common.ClassResult.prototype.className = null;
utest.ui.common.ClassResult.prototype.setupName = null;
utest.ui.common.ClassResult.prototype.teardownName = null;
utest.ui.common.ClassResult.prototype.hasSetup = null;
utest.ui.common.ClassResult.prototype.hasTeardown = null;
utest.ui.common.ClassResult.prototype.methods = null;
utest.ui.common.ClassResult.prototype.stats = null;
utest.ui.common.ClassResult.prototype.add = function(result) {
	if(this.fixtures.exists(result.methodName)) throw "invalid duplicated fixture result";
	this.stats.wire(result.stats);
	this.methods++;
	this.fixtures.set(result.methodName,result);
}
utest.ui.common.ClassResult.prototype.get = function(method) {
	return this.fixtures.get(method);
}
utest.ui.common.ClassResult.prototype.exists = function(method) {
	return this.fixtures.exists(method);
}
utest.ui.common.ClassResult.prototype.methodNames = function(errorsHavePriority) {
	if(errorsHavePriority == null) errorsHavePriority = true;
	var names = [];
	var $it0 = this.fixtures.keys();
	while( $it0.hasNext() ) {
		var name = $it0.next();
		names.push(name);
	}
	if(errorsHavePriority) {
		var me = this;
		names.sort(function(a,b) {
			var $as = me.get(a).stats;
			var bs = me.get(b).stats;
			if($as.hasErrors) return !bs.hasErrors?-1:$as.errors == bs.errors?Reflect.compare(a,b):Reflect.compare($as.errors,bs.errors); else if(bs.hasErrors) return 1; else if($as.hasFailures) return !bs.hasFailures?-1:$as.failures == bs.failures?Reflect.compare(a,b):Reflect.compare($as.failures,bs.failures); else if(bs.hasFailures) return 1; else if($as.hasWarnings) return !bs.hasWarnings?-1:$as.warnings == bs.warnings?Reflect.compare(a,b):Reflect.compare($as.warnings,bs.warnings); else if(bs.hasWarnings) return 1; else return Reflect.compare(a,b);
		});
	} else names.sort(function(a,b) {
		return Reflect.compare(a,b);
	});
	return names;
}
utest.ui.common.ClassResult.prototype.__class__ = utest.ui.common.ClassResult;
haxe.StackItem = { __ename__ : ["haxe","StackItem"], __constructs__ : ["CFunction","Module","FilePos","Method","Lambda"] }
haxe.StackItem.CFunction = ["CFunction",0];
haxe.StackItem.CFunction.toString = $estr;
haxe.StackItem.CFunction.__enum__ = haxe.StackItem;
haxe.StackItem.Module = function(m) { var $x = ["Module",1,m]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.FilePos = function(s,file,line) { var $x = ["FilePos",2,s,file,line]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.Method = function(classname,method) { var $x = ["Method",3,classname,method]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.Lambda = function(v) { var $x = ["Lambda",4,v]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.Stack = function() { }
haxe.Stack.__name__ = ["haxe","Stack"];
haxe.Stack.callStack = function() {
	return haxe.Stack.makeStack("$s");
}
haxe.Stack.exceptionStack = function() {
	return haxe.Stack.makeStack("$e");
}
haxe.Stack.toString = function(stack) {
	var b = new StringBuf();
	var _g = 0;
	while(_g < stack.length) {
		var s = stack[_g];
		++_g;
		b.b[b.b.length] = "\nCalled from " == null?"null":"\nCalled from ";
		haxe.Stack.itemToString(b,s);
	}
	return b.b.join("");
}
haxe.Stack.itemToString = function(b,s) {
	var $e = (s);
	switch( $e[1] ) {
	case 0:
		b.b[b.b.length] = "a C function" == null?"null":"a C function";
		break;
	case 1:
		var m = $e[2];
		b.b[b.b.length] = "module " == null?"null":"module ";
		b.b[b.b.length] = m == null?"null":m;
		break;
	case 2:
		var line = $e[4], file = $e[3], s1 = $e[2];
		if(s1 != null) {
			haxe.Stack.itemToString(b,s1);
			b.b[b.b.length] = " (" == null?"null":" (";
		}
		b.b[b.b.length] = file == null?"null":file;
		b.b[b.b.length] = " line " == null?"null":" line ";
		b.b[b.b.length] = line == null?"null":line;
		if(s1 != null) b.b[b.b.length] = ")" == null?"null":")";
		break;
	case 3:
		var meth = $e[3], cname = $e[2];
		b.b[b.b.length] = cname == null?"null":cname;
		b.b[b.b.length] = "." == null?"null":".";
		b.b[b.b.length] = meth == null?"null":meth;
		break;
	case 4:
		var n = $e[2];
		b.b[b.b.length] = "local function #" == null?"null":"local function #";
		b.b[b.b.length] = n == null?"null":n;
		break;
	}
}
haxe.Stack.makeStack = function(s) {
	var a = (function($this) {
		var $r;
		try {
			$r = eval(s);
		} catch( e ) {
			$r = [];
		}
		return $r;
	}(this));
	var m = new Array();
	var _g1 = 0, _g = a.length - (s == "$s"?2:0);
	while(_g1 < _g) {
		var i = _g1++;
		var d = a[i].split("::");
		m.unshift(haxe.StackItem.Method(d[0],d[1]));
	}
	return m;
}
haxe.Stack.prototype.__class__ = haxe.Stack;
ValueType = { __ename__ : ["ValueType"], __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] }
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
Type = function() { }
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
	var cl;
	try {
		cl = eval(name);
	} catch( e ) {
		cl = null;
	}
	if(cl == null || cl.__name__ == null) return null;
	return cl;
}
Type.resolveEnum = function(name) {
	var e;
	try {
		e = eval(name);
	} catch( err ) {
		e = null;
	}
	if(e == null || e.__ename__ == null) return null;
	return e;
}
Type.createInstance = function(cl,args) {
	if(args.length <= 3) return new cl(args[0],args[1],args[2]);
	if(args.length > 8) throw "Too many arguments";
	return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
}
Type.createEmptyInstance = function(cl) {
	return new cl($_);
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
	var a = Reflect.fields(c.prototype);
	a.remove("__class__");
	return a;
}
Type.getClassFields = function(c) {
	var a = Reflect.fields(c);
	a.remove("__name__");
	a.remove("__interfaces__");
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
Type.prototype.__class__ = Type;
js.Lib = function() { }
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
js.Lib.prototype.__class__ = js.Lib;
cocktail.core.dom.NamedNodeMap = function(p) {
	if( p === $_ ) return;
	this._nodes = new Array();
}
cocktail.core.dom.NamedNodeMap.__name__ = ["cocktail","core","dom","NamedNodeMap"];
cocktail.core.dom.NamedNodeMap.prototype._nodes = null;
cocktail.core.dom.NamedNodeMap.prototype.length = null;
cocktail.core.dom.NamedNodeMap.prototype.getNamedItem = function(name) {
	var _g1 = 0, _g = this._nodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._nodes[i].get_nodeName() == name) return this._nodes[i];
	}
	return null;
}
cocktail.core.dom.NamedNodeMap.prototype.setNamedItem = function(arg) {
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
cocktail.core.dom.NamedNodeMap.prototype.removeNamedItem = function(name) {
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
cocktail.core.dom.NamedNodeMap.prototype.item = function(index) {
	if(index > this.get_length() - 1) return null; else return this._nodes[index];
}
cocktail.core.dom.NamedNodeMap.prototype.get_length = function() {
	return this._nodes.length;
}
cocktail.core.dom.NamedNodeMap.prototype.__class__ = cocktail.core.dom.NamedNodeMap;
UnitManagerTests = function(p) {
	if( p === $_ ) return;
	this.container = new cocktail.port.browser.HTMLElement("div");
	this.text = cocktail.Lib.get_document().createTextNode("Hello Cocktail !");
	this.container.appendChild(this.text);
	cocktail.Lib.get_document().get_body().appendChild(this.container);
}
UnitManagerTests.__name__ = ["UnitManagerTests"];
UnitManagerTests.main = function() {
	var runner = new utest.Runner();
	runner.addCase(new UnitManagerTests());
	utest.ui.Report.create(runner);
	runner.run();
}
UnitManagerTests.prototype.container = null;
UnitManagerTests.prototype.text = null;
UnitManagerTests.prototype.testConversionToEnums = function() {
	utest.Assert.isTrue(true,null,{ fileName : "UnitManagerTests.hx", lineNumber : 68, className : "UnitManagerTests", methodName : "testConversionToEnums"});
}
UnitManagerTests.prototype.testBoxStyleEnum = function() {
	utest.Assert.same(cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(100)),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100px"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 73, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(100)),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100 px"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 74, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(100)),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100px "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 75, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(100)),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100 px "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 76, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.percent(100),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100%"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 79, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.percent(100),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100 %"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 80, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.percent(100),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100% "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 81, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.percent(100),cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"100 % "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 82, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
	utest.Assert.same(cocktail.core.style.Margin.cssAuto,cocktail.core.unit.UnitManager.boxStyleEnum(cocktail.core.style.Margin,"auto"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 85, className : "UnitManagerTests", methodName : "testBoxStyleEnum"});
}
UnitManagerTests.prototype.testBackground = function() {
	utest.Assert.same([cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./abc.gif")),cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./def.jpg"))],cocktail.core.unit.UnitManager.backgroundImageEnum("url (./abc.gif),  url(./def.jpg)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 89, className : "UnitManagerTests", methodName : "testBackground"});
	var res = cocktail.core.unit.UnitManager.backgroundImageEnum("url(./abc.gif), url(./def.jpg)");
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./abc.gif")),res[0],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 91, className : "UnitManagerTests", methodName : "testBackground"});
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./def.jpg")),res[1],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 92, className : "UnitManagerTests", methodName : "testBackground"});
	var res1 = cocktail.core.unit.UnitManager.backgroundImageEnum("url (./abc.gif),  url(./def.jpg)");
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./abc.gif")),res1[0],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 95, className : "UnitManagerTests", methodName : "testBackground"});
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./def.jpg")),res1[1],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 96, className : "UnitManagerTests", methodName : "testBackground"});
	var res2 = cocktail.core.unit.UnitManager.backgroundImageEnum("url(\"./abc.gif\"),url  (./def.jpg)");
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./abc.gif")),res2[0],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 99, className : "UnitManagerTests", methodName : "testBackground"});
	utest.Assert.same(cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./def.jpg")),res2[1],null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 100, className : "UnitManagerTests", methodName : "testBackground"});
}
UnitManagerTests.prototype.testFont = function() {
	utest.Assert.same(["Times New Roman","Georgia","Serif"],cocktail.core.unit.UnitManager.fontFamilyEnum("\"Times New Roman\",Georgia,Serif"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 104, className : "UnitManagerTests", methodName : "testFont"});
	utest.Assert.same(["Times New Roman","Georgia","Serif"],cocktail.core.unit.UnitManager.fontFamilyEnum("Times New Roman, \"Georgia\" , Serif"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 105, className : "UnitManagerTests", methodName : "testFont"});
	utest.Assert.same(["Times New Roman","Georgia","Serif"],cocktail.core.unit.UnitManager.fontFamilyEnum("\"Times New Roman\" ,Georgia , Serif"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 106, className : "UnitManagerTests", methodName : "testFont"});
	utest.Assert.same(["Times New Roman","Georgia","Serif"],cocktail.core.unit.UnitManager.fontFamilyEnum(" \"Times New Roman\" ,  Georgia,Serif"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 107, className : "UnitManagerTests", methodName : "testFont"});
}
UnitManagerTests.prototype.testColor = function() {
	utest.Assert.same(cocktail.core.unit.CSSColor.keyword(cocktail.core.unit.ColorKeyword.yellow),cocktail.core.unit.UnitManager.colorEnum("yellow"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 112, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.transparent,cocktail.core.unit.UnitManager.colorEnum("transparent"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 113, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgba(10,20,30,.5),cocktail.core.unit.UnitManager.colorEnum("rgba(10,20,30,.5)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 116, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgba(10,20,30,.5),cocktail.core.unit.UnitManager.colorEnum("rgba(10,20,30,0.5)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 117, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgba(10,20,30,.5),cocktail.core.unit.UnitManager.colorEnum("rgba(10,20,30 ,.5)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 118, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgba(10,20,30,.5),cocktail.core.unit.UnitManager.colorEnum("rgba(10,20, 30 ,.5)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 119, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgba(10,20,30,.5),cocktail.core.unit.UnitManager.colorEnum("rgba( 10,20,30,.5) "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 120, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgb(10,20,30),cocktail.core.unit.UnitManager.colorEnum("rgb(10,20,30)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 123, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgb(10,20,30),cocktail.core.unit.UnitManager.colorEnum("rgb(10,20 ,30)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 124, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgb(10,20,30),cocktail.core.unit.UnitManager.colorEnum("rgb(10,20, 30)"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 125, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.rgb(10,20,30),cocktail.core.unit.UnitManager.colorEnum("rgb( 10,20,30) "),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 126, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.hex("6789AB"),cocktail.core.unit.UnitManager.colorEnum("#6789AB"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 129, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.hex("789AB"),cocktail.core.unit.UnitManager.colorEnum("#789AB"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 130, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.hex("89AB"),cocktail.core.unit.UnitManager.colorEnum("#89AB"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 131, className : "UnitManagerTests", methodName : "testColor"});
	utest.Assert.same(cocktail.core.unit.CSSColor.hex("AB"),cocktail.core.unit.UnitManager.colorEnum("#AB"),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 132, className : "UnitManagerTests", methodName : "testColor"});
}
UnitManagerTests.prototype.testSetterGetter = function() {
	this.container.get_style().set_marginLeft("100px");
	utest.Assert.same(cocktail.core.style.Margin.length(cocktail.core.unit.Length.px(100)),this.container.get_coreStyle().getMarginLeft(),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 137, className : "UnitManagerTests", methodName : "testSetterGetter"});
	this.container.get_style().set_marginLeft("100%");
	utest.Assert.same(cocktail.core.style.Margin.percent(100),this.container.get_coreStyle().getMarginLeft(),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 139, className : "UnitManagerTests", methodName : "testSetterGetter"});
	this.container.get_style().set_marginLeft("auto");
	utest.Assert.same(cocktail.core.style.Margin.cssAuto,this.container.get_coreStyle().getMarginLeft(),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 141, className : "UnitManagerTests", methodName : "testSetterGetter"});
	this.container.get_style().set_backgroundImage(" url(./abc.gif), url(\"./def.jpg\") ");
	utest.Assert.same([cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./abc.gif")),cocktail.core.style.BackgroundImage.image(cocktail.core.unit.ImageValue.url("./def.jpg"))],this.container.get_coreStyle().getBackgroundImage(),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 144, className : "UnitManagerTests", methodName : "testSetterGetter"});
	this.container.get_style().set_fontFamily("\"Times New Roman\",Georgia, Serif");
	utest.Assert.same(["Times New Roman","Georgia","Serif"],this.container.get_coreStyle().getFontFamily(),null,null,{ fileName : "UnitManagerTests.hx", lineNumber : 147, className : "UnitManagerTests", methodName : "testSetterGetter"});
}
UnitManagerTests.prototype.__class__ = UnitManagerTests;
cocktail.core.html.AbstractHTMLInputElement = function(p) {
	if( p === $_ ) return;
	cocktail.port.browser.HTMLElement.call(this,"input");
}
cocktail.core.html.AbstractHTMLInputElement.__name__ = ["cocktail","core","html","AbstractHTMLInputElement"];
cocktail.core.html.AbstractHTMLInputElement.__super__ = cocktail.port.browser.HTMLElement;
for(var k in cocktail.port.browser.HTMLElement.prototype ) cocktail.core.html.AbstractHTMLInputElement.prototype[k] = cocktail.port.browser.HTMLElement.prototype[k];
cocktail.core.html.AbstractHTMLInputElement.prototype._onChange = null;
cocktail.core.html.AbstractHTMLInputElement.prototype.onchange = null;
cocktail.core.html.AbstractHTMLInputElement.prototype._disabled = null;
cocktail.core.html.AbstractHTMLInputElement.prototype.disabled = null;
cocktail.core.html.AbstractHTMLInputElement.prototype._maxLength = null;
cocktail.core.html.AbstractHTMLInputElement.prototype.maxLength = null;
cocktail.core.html.AbstractHTMLInputElement.prototype._value = null;
cocktail.core.html.AbstractHTMLInputElement.prototype.value = null;
cocktail.core.html.AbstractHTMLInputElement.prototype.init = function() {
	cocktail.port.browser.HTMLElement.prototype.init.call(this);
	this._disabled = false;
	this._value = "";
}
cocktail.core.html.AbstractHTMLInputElement.prototype.initCoreStyle = function() {
	this._coreStyle = new cocktail.core.style.EmbeddedCoreStyle(this);
}
cocktail.core.html.AbstractHTMLInputElement.prototype.set_onChange = function(value) {
	return this._onChange = value;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.get_onChange = function() {
	return this._onChange;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.onChangeCallback = function() {
	if(this._onChange != null) this._onChange();
}
cocktail.core.html.AbstractHTMLInputElement.prototype.set_disabled = function(value) {
	return this._disabled = value;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.get_disabled = function() {
	return this._disabled;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.set_maxLength = function(value) {
	return this._maxLength = value;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.get_maxLength = function() {
	return this._maxLength;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.set_value = function(value) {
	return this._value = value;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.get_value = function() {
	return this._value;
}
cocktail.core.html.AbstractHTMLInputElement.prototype.__class__ = cocktail.core.html.AbstractHTMLInputElement;
utest.Runner = function(p) {
	if( p === $_ ) return;
	this.fixtures = new Array();
	this.onProgress = new utest.Dispatcher();
	this.onStart = new utest.Dispatcher();
	this.onComplete = new utest.Dispatcher();
	this.length = 0;
}
utest.Runner.__name__ = ["utest","Runner"];
utest.Runner.prototype.fixtures = null;
utest.Runner.prototype.onProgress = null;
utest.Runner.prototype.onStart = null;
utest.Runner.prototype.onComplete = null;
utest.Runner.prototype.length = null;
utest.Runner.prototype.addCase = function(test,setup,teardown,prefix,pattern) {
	if(prefix == null) prefix = "test";
	if(teardown == null) teardown = "teardown";
	if(setup == null) setup = "setup";
	if(!Reflect.isObject(test)) throw "can't add a null object as a test case";
	if(!this.isMethod(test,setup)) setup = null;
	if(!this.isMethod(test,teardown)) teardown = null;
	var fields = Type.getInstanceFields(Type.getClass(test));
	if(pattern == null) {
		var _g = 0;
		while(_g < fields.length) {
			var field = fields[_g];
			++_g;
			if(!StringTools.startsWith(field,prefix)) continue;
			if(!this.isMethod(test,field)) continue;
			this.addFixture(new utest.TestFixture(test,field,setup,teardown));
		}
	} else {
		var _g = 0;
		while(_g < fields.length) {
			var field = fields[_g];
			++_g;
			if(!pattern.match(field)) continue;
			if(!this.isMethod(test,field)) continue;
			this.addFixture(new utest.TestFixture(test,field,setup,teardown));
		}
	}
}
utest.Runner.prototype.addFixture = function(fixture) {
	this.fixtures.push(fixture);
	this.length++;
}
utest.Runner.prototype.getFixture = function(index) {
	return this.fixtures[index];
}
utest.Runner.prototype.isMethod = function(test,name) {
	try {
		return Reflect.isFunction(Reflect.field(test,name));
	} catch( e ) {
		return false;
	}
}
utest.Runner.prototype.pos = null;
utest.Runner.prototype.run = function() {
	this.pos = 0;
	this.onStart.dispatch(this);
	this.runNext();
}
utest.Runner.prototype.runNext = function() {
	if(this.fixtures.length > this.pos) this.runFixture(this.fixtures[this.pos++]); else this.onComplete.dispatch(this);
}
utest.Runner.prototype.runFixture = function(fixture) {
	var handler = new utest.TestHandler(fixture);
	handler.onComplete.add($closure(this,"testComplete"));
	handler.execute();
}
utest.Runner.prototype.testComplete = function(h) {
	this.onProgress.dispatch({ result : utest.TestResult.ofHandler(h), done : this.pos, totals : this.length});
	this.runNext();
}
utest.Runner.prototype.__class__ = utest.Runner;
Reflect = function() { }
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
Reflect.prototype.__class__ = Reflect;
if(!cocktail.core.window) cocktail.core.window = {}
cocktail.core.window.AbstractWindow = function(document) {
	if( document === $_ ) return;
	this._document = document;
}
cocktail.core.window.AbstractWindow.__name__ = ["cocktail","core","window","AbstractWindow"];
cocktail.core.window.AbstractWindow.prototype._onResize = null;
cocktail.core.window.AbstractWindow.prototype.onResize = null;
cocktail.core.window.AbstractWindow.prototype._document = null;
cocktail.core.window.AbstractWindow.prototype.document = null;
cocktail.core.window.AbstractWindow.prototype.innerHeight = null;
cocktail.core.window.AbstractWindow.prototype.innerWidth = null;
cocktail.core.window.AbstractWindow.prototype.set_onResize = function(value) {
	return this._onResize = value;
}
cocktail.core.window.AbstractWindow.prototype.get_onResize = function() {
	return this._onResize;
}
cocktail.core.window.AbstractWindow.prototype.get_innerHeight = function() {
	return -1;
}
cocktail.core.window.AbstractWindow.prototype.get_innerWidth = function() {
	return -1;
}
cocktail.core.window.AbstractWindow.prototype.get_document = function() {
	return this._document;
}
cocktail.core.window.AbstractWindow.prototype.__class__ = cocktail.core.window.AbstractWindow;
cocktail.core.window.AbstractWindow.__interfaces__ = [cocktail.core.event.IEventTarget];
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	return 0;
}
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.shrinkToFit = function(style,containingHTMLElementData,minimumWidth) {
	var shrinkedWidth;
	if(minimumWidth < containingHTMLElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingHTMLElementData.width;
	return shrinkedWidth;
}
cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingHTMLElementData) {
	return 0;
}
cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
utest.ui.text.PlainTextReport = function(runner,outputHandler) {
	if( runner === $_ ) return;
	this.aggregator = new utest.ui.common.ResultAggregator(runner,true);
	runner.onStart.add($closure(this,"start"));
	this.aggregator.onComplete.add($closure(this,"complete"));
	if(null != outputHandler) this.setHandler(outputHandler);
	this.displaySuccessResults = utest.ui.common.SuccessResultsDisplayMode.AlwaysShowSuccessResults;
	this.displayHeader = utest.ui.common.HeaderDisplayMode.AlwaysShowHeader;
}
utest.ui.text.PlainTextReport.__name__ = ["utest","ui","text","PlainTextReport"];
utest.ui.text.PlainTextReport.prototype.displaySuccessResults = null;
utest.ui.text.PlainTextReport.prototype.displayHeader = null;
utest.ui.text.PlainTextReport.prototype.handler = null;
utest.ui.text.PlainTextReport.prototype.aggregator = null;
utest.ui.text.PlainTextReport.prototype.newline = null;
utest.ui.text.PlainTextReport.prototype.indent = null;
utest.ui.text.PlainTextReport.prototype.setHandler = function(handler) {
	this.handler = handler;
}
utest.ui.text.PlainTextReport.prototype.startTime = null;
utest.ui.text.PlainTextReport.prototype.start = function(e) {
	this.startTime = haxe.Timer.stamp();
}
utest.ui.text.PlainTextReport.prototype.indents = function(c) {
	var s = "";
	var _g = 0;
	while(_g < c) {
		var _ = _g++;
		s += this.indent;
	}
	return s;
}
utest.ui.text.PlainTextReport.prototype.dumpStack = function(stack) {
	if(stack.length == 0) return "";
	var parts = haxe.Stack.toString(stack).split("\n");
	var r = [];
	var _g = 0;
	while(_g < parts.length) {
		var part = parts[_g];
		++_g;
		if(part.indexOf(" utest.") >= 0) continue;
		r.push(part);
	}
	return r.join(this.newline);
}
utest.ui.text.PlainTextReport.prototype.addHeader = function(buf,result) {
	if(!utest.ui.common.ReportTools.hasHeader(this,result.stats)) return;
	var end = haxe.Timer.stamp();
	var time = Std["int"]((end - this.startTime) * 1000) / 1000;
	buf.add("results: " + (result.stats.isOk?"ALL TESTS OK":"SOME TESTS FAILURES") + this.newline + " " + this.newline);
	buf.add("assertations: " + result.stats.assertations + this.newline);
	buf.add("successes: " + result.stats.successes + this.newline);
	buf.add("errors: " + result.stats.errors + this.newline);
	buf.add("failures: " + result.stats.failures + this.newline);
	buf.add("warnings: " + result.stats.warnings + this.newline);
	buf.add("execution time: " + time + this.newline);
	buf.add(this.newline);
}
utest.ui.text.PlainTextReport.prototype.result = null;
utest.ui.text.PlainTextReport.prototype.getResults = function() {
	var buf = new StringBuf();
	this.addHeader(buf,this.result);
	var _g = 0, _g1 = this.result.packageNames();
	while(_g < _g1.length) {
		var pname = _g1[_g];
		++_g;
		var pack = this.result.getPackage(pname);
		if(utest.ui.common.ReportTools.skipResult(this,pack.stats,this.result.stats.isOk)) continue;
		var _g2 = 0, _g3 = pack.classNames();
		while(_g2 < _g3.length) {
			var cname = _g3[_g2];
			++_g2;
			var cls = pack.getClass(cname);
			if(utest.ui.common.ReportTools.skipResult(this,cls.stats,this.result.stats.isOk)) continue;
			buf.add((pname == ""?"":pname + ".") + cname + this.newline);
			var _g4 = 0, _g5 = cls.methodNames();
			while(_g4 < _g5.length) {
				var mname = _g5[_g4];
				++_g4;
				var fix = cls.get(mname);
				if(utest.ui.common.ReportTools.skipResult(this,fix.stats,this.result.stats.isOk)) continue;
				buf.add(this.indents(1) + mname + ": ");
				if(fix.stats.isOk) buf.b[buf.b.length] = "OK " == null?"null":"OK "; else if(fix.stats.hasErrors) buf.b[buf.b.length] = "ERROR " == null?"null":"ERROR "; else if(fix.stats.hasFailures) buf.b[buf.b.length] = "FAILURE " == null?"null":"FAILURE "; else if(fix.stats.hasWarnings) buf.b[buf.b.length] = "WARNING " == null?"null":"WARNING ";
				var messages = "";
				var $it0 = fix.iterator();
				while( $it0.hasNext() ) {
					var assertation = $it0.next();
					var $e = (assertation);
					switch( $e[1] ) {
					case 0:
						var pos = $e[2];
						buf.b[buf.b.length] = "." == null?"null":".";
						break;
					case 1:
						var pos = $e[3], msg = $e[2];
						buf.b[buf.b.length] = "F" == null?"null":"F";
						messages += this.indents(2) + "line: " + pos.lineNumber + ", " + msg + this.newline;
						break;
					case 2:
						var s = $e[3], e = $e[2];
						buf.b[buf.b.length] = "E" == null?"null":"E";
						messages += this.indents(2) + Std.string(e) + this.dumpStack(s) + this.newline;
						break;
					case 3:
						var s = $e[3], e = $e[2];
						buf.b[buf.b.length] = "S" == null?"null":"S";
						messages += this.indents(2) + Std.string(e) + this.dumpStack(s) + this.newline;
						break;
					case 4:
						var s = $e[3], e = $e[2];
						buf.b[buf.b.length] = "T" == null?"null":"T";
						messages += this.indents(2) + Std.string(e) + this.dumpStack(s) + this.newline;
						break;
					case 5:
						var s = $e[3], missedAsyncs = $e[2];
						buf.b[buf.b.length] = "O" == null?"null":"O";
						messages += this.indents(2) + "missed async calls: " + missedAsyncs + this.dumpStack(s) + this.newline;
						break;
					case 6:
						var s = $e[3], e = $e[2];
						buf.b[buf.b.length] = "A" == null?"null":"A";
						messages += this.indents(2) + Std.string(e) + this.dumpStack(s) + this.newline;
						break;
					case 7:
						var msg = $e[2];
						buf.b[buf.b.length] = "W" == null?"null":"W";
						messages += this.indents(2) + msg + this.newline;
						break;
					}
				}
				buf.add(this.newline);
				buf.b[buf.b.length] = messages == null?"null":messages;
			}
		}
	}
	return buf.b.join("");
}
utest.ui.text.PlainTextReport.prototype.complete = function(result) {
	this.result = result;
	this.handler(this);
}
utest.ui.text.PlainTextReport.prototype.__class__ = utest.ui.text.PlainTextReport;
utest.ui.text.PlainTextReport.__interfaces__ = [utest.ui.common.IReport];
utest.ui.text.PrintReport = function(runner) {
	if( runner === $_ ) return;
	utest.ui.text.PlainTextReport.call(this,runner,$closure(this,"_handler"));
	this.newline = "\n";
	this.indent = "  ";
}
utest.ui.text.PrintReport.__name__ = ["utest","ui","text","PrintReport"];
utest.ui.text.PrintReport.__super__ = utest.ui.text.PlainTextReport;
for(var k in utest.ui.text.PlainTextReport.prototype ) utest.ui.text.PrintReport.prototype[k] = utest.ui.text.PlainTextReport.prototype[k];
utest.ui.text.PrintReport.prototype.useTrace = null;
utest.ui.text.PrintReport.prototype._handler = function(report) {
	this._trace(report.getResults());
}
utest.ui.text.PrintReport.prototype._trace = function(s) {
	s = StringTools.replace(s,"  ",this.indent);
	s = StringTools.replace(s,"\n",this.newline);
	haxe.Log.trace(s,{ fileName : "PrintReport.hx", lineNumber : 66, className : "utest.ui.text.PrintReport", methodName : "_trace"});
}
utest.ui.text.PrintReport.prototype.__class__ = utest.ui.text.PrintReport;
cocktail.core.renderer.TextRenderer = function(style,nativeElement,textToken) {
	if( style === $_ ) return;
	this._textToken = textToken;
	this._nativeElement = nativeElement;
	cocktail.core.renderer.ElementRenderer.call(this,style);
}
cocktail.core.renderer.TextRenderer.__name__ = ["cocktail","core","renderer","TextRenderer"];
cocktail.core.renderer.TextRenderer.__super__ = cocktail.core.renderer.ElementRenderer;
for(var k in cocktail.core.renderer.ElementRenderer.prototype ) cocktail.core.renderer.TextRenderer.prototype[k] = cocktail.core.renderer.ElementRenderer.prototype[k];
cocktail.core.renderer.TextRenderer.prototype._textToken = null;
cocktail.core.renderer.TextRenderer.prototype._nativeElement = null;
cocktail.core.renderer.TextRenderer.prototype.dispose = function() {
	cocktail.core.renderer.ElementRenderer.prototype.dispose.call(this);
	this._textToken = null;
	this._nativeElement = null;
}
cocktail.core.renderer.TextRenderer.prototype.render = function() {
	var ret = [];
	ret.push(this._nativeElement);
	return ret;
}
cocktail.core.renderer.TextRenderer.prototype.getOffsetHeight = function() {
	var ascent = this._coreStyle.getFontMetricsData().ascent;
	var descent = this._coreStyle.getFontMetricsData().descent;
	var leading = this._coreStyle.getComputedStyle().lineHeight - (ascent + descent);
	var leadedAscent = ascent + leading / 2;
	var leadedDescent = descent + leading / 2;
	return Math.round(leadedAscent + leadedDescent);
	return 50;
}
cocktail.core.renderer.TextRenderer.prototype.isFloat = function() {
	return false;
}
cocktail.core.renderer.TextRenderer.prototype.isPositioned = function() {
	return false;
}
cocktail.core.renderer.TextRenderer.prototype.isText = function() {
	return true;
}
cocktail.core.renderer.TextRenderer.prototype.isSpace = function() {
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
cocktail.core.renderer.TextRenderer.prototype.isLineFeed = function() {
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
cocktail.core.renderer.TextRenderer.prototype.isTab = function() {
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
cocktail.core.renderer.TextRenderer.prototype.__class__ = cocktail.core.renderer.TextRenderer;
Lambda = function() { }
Lambda.__name__ = ["Lambda"];
Lambda.array = function(it) {
	var a = new Array();
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		a.push(i);
	}
	return a;
}
Lambda.list = function(it) {
	var l = new List();
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		l.add(i);
	}
	return l;
}
Lambda.map = function(it,f) {
	var l = new List();
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		l.add(f(x));
	}
	return l;
}
Lambda.mapi = function(it,f) {
	var l = new List();
	var i = 0;
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		l.add(f(i++,x));
	}
	return l;
}
Lambda.has = function(it,elt,cmp) {
	if(cmp == null) {
		var $it0 = it.iterator();
		while( $it0.hasNext() ) {
			var x = $it0.next();
			if(x == elt) return true;
		}
	} else {
		var $it1 = it.iterator();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			if(cmp(x,elt)) return true;
		}
	}
	return false;
}
Lambda.exists = function(it,f) {
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		if(f(x)) return true;
	}
	return false;
}
Lambda.foreach = function(it,f) {
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		if(!f(x)) return false;
	}
	return true;
}
Lambda.iter = function(it,f) {
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		f(x);
	}
}
Lambda.filter = function(it,f) {
	var l = new List();
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		if(f(x)) l.add(x);
	}
	return l;
}
Lambda.fold = function(it,f,first) {
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		first = f(x,first);
	}
	return first;
}
Lambda.count = function(it,pred) {
	var n = 0;
	if(pred == null) {
		var $it0 = it.iterator();
		while( $it0.hasNext() ) {
			var _ = $it0.next();
			n++;
		}
	} else {
		var $it1 = it.iterator();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			if(pred(x)) n++;
		}
	}
	return n;
}
Lambda.empty = function(it) {
	return !it.iterator().hasNext();
}
Lambda.indexOf = function(it,v) {
	var i = 0;
	var $it0 = it.iterator();
	while( $it0.hasNext() ) {
		var v2 = $it0.next();
		if(v == v2) return i;
		i++;
	}
	return -1;
}
Lambda.concat = function(a,b) {
	var l = new List();
	var $it0 = a.iterator();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		l.add(x);
	}
	var $it1 = b.iterator();
	while( $it1.hasNext() ) {
		var x = $it1.next();
		l.add(x);
	}
	return l;
}
Lambda.prototype.__class__ = Lambda;
cocktail.core.style.computer.BackgroundStylesComputer = function(p) {
}
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
cocktail.core.style.computer.BackgroundStylesComputer.prototype.__class__ = cocktail.core.style.computer.BackgroundStylesComputer;
cocktail.core.html.HTMLBodyElement = function(p) {
	if( p === $_ ) return;
	cocktail.port.browser.HTMLElement.call(this,"body");
}
cocktail.core.html.HTMLBodyElement.__name__ = ["cocktail","core","html","HTMLBodyElement"];
cocktail.core.html.HTMLBodyElement.__super__ = cocktail.port.browser.HTMLElement;
for(var k in cocktail.port.browser.HTMLElement.prototype ) cocktail.core.html.HTMLBodyElement.prototype[k] = cocktail.port.browser.HTMLElement.prototype[k];
cocktail.core.html.HTMLBodyElement.prototype.initNativeElement = function() {
	this._nativeElement = cocktail.core.nativeElement.NativeElementManager.getRoot();
}
cocktail.core.html.HTMLBodyElement.prototype.initCoreStyle = function() {
	this._coreStyle = new cocktail.port.browser.BodyCoreStyle(this);
}
cocktail.core.html.HTMLBodyElement.prototype.__class__ = cocktail.core.html.HTMLBodyElement;
cocktail.core.font.AbstractFontLoader = function(p) {
	if( p === $_ ) return;
	this._successCallbackArray = new Array();
	this._errorCallbackArray = new Array();
}
cocktail.core.font.AbstractFontLoader.__name__ = ["cocktail","core","font","AbstractFontLoader"];
cocktail.core.font.AbstractFontLoader.prototype.fontData = null;
cocktail.core.font.AbstractFontLoader.prototype._successCallbackArray = null;
cocktail.core.font.AbstractFontLoader.prototype._errorCallbackArray = null;
cocktail.core.font.AbstractFontLoader.prototype.load = function(url,name) {
	var extension = url.substr(url.lastIndexOf("."),url.length);
	this.fontData = { url : url, name : name, type : cocktail.core.font.FontType.unknown};
	if(extension == ".ttf") this.fontData.type = cocktail.core.font.FontType.ttf; else if(extension == ".eot") this.fontData.type = cocktail.core.font.FontType.eot; else if(extension == ".otf") this.fontData.type = cocktail.core.font.FontType.otf; else if(extension == ".swf") this.fontData.type = cocktail.core.font.FontType.swf; else this.fontData.type = cocktail.core.font.FontType.unknown;
}
cocktail.core.font.AbstractFontLoader.prototype.addCallback = function(successCallback,errorCallback) {
	if(successCallback != null) this._successCallbackArray.push(successCallback);
	if(errorCallback != null) this._errorCallbackArray.push(errorCallback);
}
cocktail.core.font.AbstractFontLoader.prototype._successCallback = function() {
	var idx;
	var _g1 = 0, _g = this._successCallbackArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		this._successCallbackArray[idx1](this.fontData);
	}
	this.cleanup();
}
cocktail.core.font.AbstractFontLoader.prototype._errorCallback = function(errorStr) {
	var idx;
	var _g1 = 0, _g = this._errorCallbackArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		this._errorCallbackArray[idx1](this.fontData,errorStr);
	}
	this.cleanup();
}
cocktail.core.font.AbstractFontLoader.prototype.cleanup = function() {
	while(this._successCallbackArray.length > 0) this._successCallbackArray.pop();
	while(this._errorCallbackArray.length > 0) this._errorCallbackArray.pop();
}
cocktail.core.font.AbstractFontLoader.prototype.__class__ = cocktail.core.font.AbstractFontLoader;
cocktail.core.style.AbstractBodyCoreStyle = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.style.ContainerCoreStyle.call(this,htmlElement);
	this._nativeElements = new Array();
	this._isDirty = false;
}
cocktail.core.style.AbstractBodyCoreStyle.__name__ = ["cocktail","core","style","AbstractBodyCoreStyle"];
cocktail.core.style.AbstractBodyCoreStyle.__super__ = cocktail.core.style.ContainerCoreStyle;
for(var k in cocktail.core.style.ContainerCoreStyle.prototype ) cocktail.core.style.AbstractBodyCoreStyle.prototype[k] = cocktail.core.style.ContainerCoreStyle.prototype[k];
cocktail.core.style.AbstractBodyCoreStyle.prototype._nativeElements = null;
cocktail.core.style.AbstractBodyCoreStyle.prototype.invalidate = function(immediate) {
	if(immediate == null) immediate = false;
	if(this._isDirty == false || immediate == true) {
		this._isDirty = true;
		var windowData = this.getWindowData();
		var lastPositionedHTMLElementData = { children : new Array(), data : windowData};
		if(immediate == false) this.scheduleLayout(windowData,lastPositionedHTMLElementData,windowData); else this.layout(windowData,lastPositionedHTMLElementData,windowData,null);
	}
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.render = function(nativeElement) {
	this._nativeElements = this._elementRenderer.getLayerRenderer().render();
	this._nativeElements.reverse();
	this.attachNativeElements(this._nativeElements);
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.attachNativeElement = function(nativeElement) {
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.detachNativeElement = function(nativeElement) {
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.attachNativeElements = function(nativeElements) {
	var _g1 = 0, _g = nativeElements.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.attachNativeElement(nativeElements[i]);
	}
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.detachNativeElements = function(nativeElements) {
	var _g1 = 0, _g = nativeElements.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.detachNativeElement(nativeElements[i]);
	}
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.createElementRenderer = function(parentElementRenderer) {
	var elementRenderer = new cocktail.core.renderer.InitialBlockRenderer(this);
	elementRenderer.setLayerRenderer(new cocktail.core.renderer.LayerRenderer(elementRenderer));
	return elementRenderer;
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.layout = function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
	this.detachNativeElements(this._nativeElements);
	cocktail.core.style.ContainerCoreStyle.prototype.layout.call(this,containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData);
	this.render(this._htmlElement.get_nativeElement());
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.insertHTMLElement = function(formattingContext,lastPositionedHTMLElementData,viewportData) {
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.positionAbsolutelyPositionedHTMLElementsIfNeeded = function(childLastPositionedHTMLElementData,viewportData) {
	this.doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.getPositionedHTMLElementData = function() {
	return this.getWindowData();
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.isInlineLevel = function() {
	return false;
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.isOffsetParent = function() {
	return true;
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.getFirstPositionedAncestor = function() {
	return null;
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.getformattingContext = function(previousformattingContext) {
	return new cocktail.core.style.formatter.BlockFormattingContext(this._elementRenderer);
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.establishesNewFormattingContext = function() {
	return true;
}
cocktail.core.style.AbstractBodyCoreStyle.prototype.__class__ = cocktail.core.style.AbstractBodyCoreStyle;
cocktail.port.browser.BodyCoreStyle = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.style.AbstractBodyCoreStyle.call(this,htmlElement);
}
cocktail.port.browser.BodyCoreStyle.__name__ = ["cocktail","port","browser","BodyCoreStyle"];
cocktail.port.browser.BodyCoreStyle.__super__ = cocktail.core.style.AbstractBodyCoreStyle;
for(var k in cocktail.core.style.AbstractBodyCoreStyle.prototype ) cocktail.port.browser.BodyCoreStyle.prototype[k] = cocktail.core.style.AbstractBodyCoreStyle.prototype[k];
cocktail.port.browser.BodyCoreStyle.prototype.render = function(nativeElement) {
}
cocktail.port.browser.BodyCoreStyle.prototype.layout = function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
}
cocktail.port.browser.BodyCoreStyle.prototype.__class__ = cocktail.port.browser.BodyCoreStyle;
if(!cocktail.core.style.floats) cocktail.core.style.floats = {}
cocktail.core.style.floats.FloatsManager = function(p) {
	if( p === $_ ) return;
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
}
cocktail.core.style.floats.FloatsManager.__name__ = ["cocktail","core","style","floats","FloatsManager"];
cocktail.core.style.floats.FloatsManager.prototype._floats = null;
cocktail.core.style.floats.FloatsManager.prototype.floats = null;
cocktail.core.style.floats.FloatsManager.prototype.dispose = function() {
	this._floats.left = null;
	this._floats.right = null;
	this._floats = null;
}
cocktail.core.style.floats.FloatsManager.prototype.clearFloat = function(clear,formattingContextData) {
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
cocktail.core.style.floats.FloatsManager.prototype.clearLeft = function(formattingContextData) {
	return this.doClearFloat(formattingContextData,this._floats.left);
}
cocktail.core.style.floats.FloatsManager.prototype.clearRight = function(formattingContextData) {
	return this.doClearFloat(formattingContextData,this._floats.right);
}
cocktail.core.style.floats.FloatsManager.prototype.clearBoth = function(formattingContextData) {
	var leftY = this.doClearFloat(formattingContextData,this._floats.left);
	var rightY = this.doClearFloat(formattingContextData,this._floats.right);
	if(leftY > rightY) return leftY; else return rightY;
}
cocktail.core.style.floats.FloatsManager.prototype.doClearFloat = function(formattingContextData,floats) {
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
cocktail.core.style.floats.FloatsManager.prototype.computeFloatData = function(elementRenderer,formattingContextData,containingBlockWidth) {
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
cocktail.core.style.floats.FloatsManager.prototype.getLeftFloatData = function(elementRenderer,formattingContextData,containingBlockWidth) {
	var floatData = this.getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
	floatData.x = this.getLeftFloatOffset(floatData.y);
	return floatData;
}
cocktail.core.style.floats.FloatsManager.prototype.getRightFloatData = function(elementRenderer,formattingContextData,containingBlockWidth) {
	var floatData = this.getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
	floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth);
	return floatData;
}
cocktail.core.style.floats.FloatsManager.prototype.getFloatData = function(elementRenderer,formattingContextData,containingBlockWidth) {
	var computedStyle = elementRenderer.getCoreStyle().getComputedStyle();
	var floatWidth = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	var floatHeight = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	var floatY = this.getFirstAvailableY(formattingContextData,floatWidth,containingBlockWidth);
	var floatX = 0;
	return { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
}
cocktail.core.style.floats.FloatsManager.prototype.getFirstAvailableY = function(formattingContextData,elementWidth,containingBlockWidth) {
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
cocktail.core.style.floats.FloatsManager.prototype.removeFloats = function(flowY) {
	this._floats.left = this.doRemoveFloat(this._floats.left,flowY);
	this._floats.right = this.doRemoveFloat(this._floats.right,flowY);
}
cocktail.core.style.floats.FloatsManager.prototype.doRemoveFloat = function(floats,flowY) {
	var newFloats = new Array();
	var _g1 = 0, _g = floats.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(floats[i].y + floats[i].height > flowY) newFloats.push(floats[i]);
	}
	return newFloats;
}
cocktail.core.style.floats.FloatsManager.prototype.getRightFloatOffset = function(y,containingWidth) {
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
cocktail.core.style.floats.FloatsManager.prototype.getLeftFloatOffset = function(y) {
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
cocktail.core.style.floats.FloatsManager.prototype.getFloats = function() {
	return this._floats;
}
cocktail.core.style.floats.FloatsManager.prototype.__class__ = cocktail.core.style.floats.FloatsManager;
cocktail.core.event.MouseEvent = function(type,target,detail,screenX,screenY,clientX,clientY,ctrlKey,shiftKey,altKey) {
	if( type === $_ ) return;
	cocktail.core.event.UIEvent.call(this,type,target,detail);
	this._screenX = screenX;
	this._screenY = screenY;
	this._clientX = clientX;
	this._clientY = clientY;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
}
cocktail.core.event.MouseEvent.__name__ = ["cocktail","core","event","MouseEvent"];
cocktail.core.event.MouseEvent.__super__ = cocktail.core.event.UIEvent;
for(var k in cocktail.core.event.UIEvent.prototype ) cocktail.core.event.MouseEvent.prototype[k] = cocktail.core.event.UIEvent.prototype[k];
cocktail.core.event.MouseEvent.prototype._screenX = null;
cocktail.core.event.MouseEvent.prototype.screenX = null;
cocktail.core.event.MouseEvent.prototype._screenY = null;
cocktail.core.event.MouseEvent.prototype.screenY = null;
cocktail.core.event.MouseEvent.prototype._clientX = null;
cocktail.core.event.MouseEvent.prototype.clientX = null;
cocktail.core.event.MouseEvent.prototype._clientY = null;
cocktail.core.event.MouseEvent.prototype.clientY = null;
cocktail.core.event.MouseEvent.prototype._ctrlKey = null;
cocktail.core.event.MouseEvent.prototype.ctrlKey = null;
cocktail.core.event.MouseEvent.prototype._shiftKey = null;
cocktail.core.event.MouseEvent.prototype.shiftKey = null;
cocktail.core.event.MouseEvent.prototype._altKey = null;
cocktail.core.event.MouseEvent.prototype.altKey = null;
cocktail.core.event.MouseEvent.prototype.get_altKey = function() {
	return this._altKey;
}
cocktail.core.event.MouseEvent.prototype.get_shiftKey = function() {
	return this._shiftKey;
}
cocktail.core.event.MouseEvent.prototype.get_ctrlKey = function() {
	return this._ctrlKey;
}
cocktail.core.event.MouseEvent.prototype.get_clientY = function() {
	return this._clientY;
}
cocktail.core.event.MouseEvent.prototype.get_clientX = function() {
	return this._clientX;
}
cocktail.core.event.MouseEvent.prototype.get_screenX = function() {
	return this._screenX;
}
cocktail.core.event.MouseEvent.prototype.get_screenY = function() {
	return this._screenY;
}
cocktail.core.event.MouseEvent.prototype.__class__ = cocktail.core.event.MouseEvent;
utest.TestResult = function(p) {
}
utest.TestResult.__name__ = ["utest","TestResult"];
utest.TestResult.ofHandler = function(handler) {
	var r = new utest.TestResult();
	var path = Type.getClassName(Type.getClass(handler.fixture.target)).split(".");
	r.cls = path.pop();
	r.pack = path.join(".");
	r.method = handler.fixture.method;
	r.setup = handler.fixture.setup;
	r.teardown = handler.fixture.teardown;
	r.assertations = handler.results;
	return r;
}
utest.TestResult.prototype.pack = null;
utest.TestResult.prototype.cls = null;
utest.TestResult.prototype.method = null;
utest.TestResult.prototype.setup = null;
utest.TestResult.prototype.teardown = null;
utest.TestResult.prototype.assertations = null;
utest.TestResult.prototype.allOk = function() {
	try {
		var $it0 = this.assertations.iterator();
		while( $it0.hasNext() ) {
			var l = $it0.next();
			var $e = (l);
			switch( $e[1] ) {
			case 0:
				var pos = $e[2];
				throw "__break__";
				break;
			default:
				return false;
			}
		}
	} catch( e ) { if( e != "__break__" ) throw e; }
	return true;
}
utest.TestResult.prototype.__class__ = utest.TestResult;
if(!cocktail.core.mouse) cocktail.core.mouse = {}
cocktail.core.mouse.MouseCursorManager = function(p) {
}
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
cocktail.core.mouse.MouseCursorManager.prototype.__class__ = cocktail.core.mouse.MouseCursorManager;
if(!cocktail.core.resource) cocktail.core.resource = {}
cocktail.core.resource.AbstractResourceLoader = function(p) {
}
cocktail.core.resource.AbstractResourceLoader.__name__ = ["cocktail","core","resource","AbstractResourceLoader"];
cocktail.core.resource.AbstractResourceLoader.prototype._onLoadCompleteCallback = null;
cocktail.core.resource.AbstractResourceLoader.prototype._onLoadErrorCallback = null;
cocktail.core.resource.AbstractResourceLoader.prototype._urlToLoadIdx = null;
cocktail.core.resource.AbstractResourceLoader.prototype._urls = null;
cocktail.core.resource.AbstractResourceLoader.prototype.load = function(urls,onLoadComplete,onLoadError) {
	this._onLoadCompleteCallback = onLoadComplete;
	this._onLoadErrorCallback = onLoadError;
	this._urls = urls;
	this._urlToLoadIdx = 0;
	this.doLoad(this._urls[this._urlToLoadIdx]);
}
cocktail.core.resource.AbstractResourceLoader.prototype.doLoad = function(url) {
}
cocktail.core.resource.AbstractResourceLoader.prototype.onLoadComplete = function(data) {
	this._onLoadCompleteCallback(data);
}
cocktail.core.resource.AbstractResourceLoader.prototype.onLoadError = function(msg) {
	this._urlToLoadIdx++;
	if(this._urlToLoadIdx < this._urls.length - 1) this.doLoad(this._urls[this._urlToLoadIdx]); else this._onLoadErrorCallback(msg);
}
cocktail.core.resource.AbstractResourceLoader.prototype.__class__ = cocktail.core.resource.AbstractResourceLoader;
cocktail.core.mouse.AbstractMouse = function(htmlElement) {
	if( htmlElement === $_ ) return;
	this._htmlElement = htmlElement;
}
cocktail.core.mouse.AbstractMouse.__name__ = ["cocktail","core","mouse","AbstractMouse"];
cocktail.core.mouse.AbstractMouse.prototype._onClick = null;
cocktail.core.mouse.AbstractMouse.prototype.onClick = null;
cocktail.core.mouse.AbstractMouse.prototype._onMouseDown = null;
cocktail.core.mouse.AbstractMouse.prototype.onMouseDown = null;
cocktail.core.mouse.AbstractMouse.prototype._onMouseUp = null;
cocktail.core.mouse.AbstractMouse.prototype.onMouseUp = null;
cocktail.core.mouse.AbstractMouse.prototype._onMouseOver = null;
cocktail.core.mouse.AbstractMouse.prototype.onMouseOver = null;
cocktail.core.mouse.AbstractMouse.prototype._onMouseOut = null;
cocktail.core.mouse.AbstractMouse.prototype.onMouseOut = null;
cocktail.core.mouse.AbstractMouse.prototype._onMouseMove = null;
cocktail.core.mouse.AbstractMouse.prototype.onMouseMove = null;
cocktail.core.mouse.AbstractMouse.prototype._clickEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._mouseDownEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._mouseUpEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._mouseOverEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._mouseOutEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._mouseMoveEvent = null;
cocktail.core.mouse.AbstractMouse.prototype._htmlElement = null;
cocktail.core.mouse.AbstractMouse.prototype.onNativeClick = function(event) {
	if(this.get_onClick() != null) (this.get_onClick())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.onNativeMouseDown = function(event) {
	if(this.getOnMouseDown() != null) (this.getOnMouseDown())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.onNativeMouseUp = function(event) {
	if(this.getOnMouseUp() != null) (this.getOnMouseUp())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.onNativeMouseOver = function(event) {
	if(this.getOnMouseOver() != null) (this.getOnMouseOver())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.onNativeMouseOut = function(event) {
	if(this.getOnMouseOut() != null) (this.getOnMouseOut())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.onNativeMouseMove = function(event) {
	if(this.getOnMouseMove() != null) (this.getOnMouseMove())(this.getMouseEvent(event));
}
cocktail.core.mouse.AbstractMouse.prototype.updateListeners = function(mouseEvent,nativeCallback,htmlElementCallback) {
}
cocktail.core.mouse.AbstractMouse.prototype.getMouseEvent = function(event) {
	return null;
}
cocktail.core.mouse.AbstractMouse.prototype.set_onClick = function(value) {
	this.updateListeners(this._clickEvent,$closure(this,"onNativeClick"),value);
	return this._onClick = value;
}
cocktail.core.mouse.AbstractMouse.prototype.get_onClick = function() {
	return this._onClick;
}
cocktail.core.mouse.AbstractMouse.prototype.setOnMouseDown = function(value) {
	this.updateListeners(this._mouseDownEvent,$closure(this,"onNativeMouseDown"),value);
	return this._onMouseDown = value;
}
cocktail.core.mouse.AbstractMouse.prototype.getOnMouseDown = function() {
	return this._onMouseDown;
}
cocktail.core.mouse.AbstractMouse.prototype.setOnMouseUp = function(value) {
	this.updateListeners(this._mouseUpEvent,$closure(this,"onNativeMouseUp"),value);
	return this._onMouseUp = value;
}
cocktail.core.mouse.AbstractMouse.prototype.getOnMouseUp = function() {
	return this._onMouseUp;
}
cocktail.core.mouse.AbstractMouse.prototype.setOnMouseOver = function(value) {
	this.updateListeners(this._mouseOverEvent,$closure(this,"onNativeMouseOver"),value);
	return this._onMouseOver = value;
}
cocktail.core.mouse.AbstractMouse.prototype.getOnMouseOver = function() {
	return this._onMouseOver;
}
cocktail.core.mouse.AbstractMouse.prototype.setOnMouseOut = function(value) {
	this.updateListeners(this._mouseOutEvent,$closure(this,"onNativeMouseOut"),value);
	return this._onMouseOut = value;
}
cocktail.core.mouse.AbstractMouse.prototype.getOnMouseOut = function() {
	return this._onMouseOut;
}
cocktail.core.mouse.AbstractMouse.prototype.setOnMouseMove = function(value) {
	this.updateListeners(this._mouseMoveEvent,$closure(this,"onNativeMouseMove"),value);
	return this._onMouseMove = value;
}
cocktail.core.mouse.AbstractMouse.prototype.getOnMouseMove = function() {
	return this._onMouseMove;
}
cocktail.core.mouse.AbstractMouse.prototype.__class__ = cocktail.core.mouse.AbstractMouse;
cocktail.port.browser.Mouse = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.mouse.AbstractMouse.call(this,htmlElement);
	this._clickEvent = "click";
	this._mouseDownEvent = "mousedown";
	this._mouseUpEvent = "mouseup";
	this._mouseOverEvent = "mouseover";
	this._mouseOutEvent = "mouseout";
	this._mouseMoveEvent = "mousemove";
}
cocktail.port.browser.Mouse.__name__ = ["cocktail","port","browser","Mouse"];
cocktail.port.browser.Mouse.__super__ = cocktail.core.mouse.AbstractMouse;
for(var k in cocktail.core.mouse.AbstractMouse.prototype ) cocktail.port.browser.Mouse.prototype[k] = cocktail.core.mouse.AbstractMouse.prototype[k];
cocktail.port.browser.Mouse.prototype.updateListeners = function(mouseEvent,nativeCallback,htmlElementCallback) {
	this._htmlElement.get_nativeElement().removeEventListener(mouseEvent,nativeCallback);
	if(htmlElementCallback != null) this._htmlElement.get_nativeElement().addEventListener(mouseEvent,nativeCallback);
}
cocktail.port.browser.Mouse.prototype.getMouseEvent = function(event) {
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
cocktail.port.browser.Mouse.prototype.__class__ = cocktail.port.browser.Mouse;
cocktail.core.renderer.InlineBoxRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.FlowBoxRenderer.call(this,style);
}
cocktail.core.renderer.InlineBoxRenderer.__name__ = ["cocktail","core","renderer","InlineBoxRenderer"];
cocktail.core.renderer.InlineBoxRenderer.__super__ = cocktail.core.renderer.FlowBoxRenderer;
for(var k in cocktail.core.renderer.FlowBoxRenderer.prototype ) cocktail.core.renderer.InlineBoxRenderer.prototype[k] = cocktail.core.renderer.FlowBoxRenderer.prototype[k];
cocktail.core.renderer.InlineBoxRenderer.prototype.render = function() {
	return this.renderBackground();
}
cocktail.core.renderer.InlineBoxRenderer.prototype.__class__ = cocktail.core.renderer.InlineBoxRenderer;
StringBuf = function(p) {
	if( p === $_ ) return;
	this.b = new Array();
}
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype.add = function(x) {
	this.b[this.b.length] = x == null?"null":x;
}
StringBuf.prototype.addSub = function(s,pos,len) {
	this.b[this.b.length] = s.substr(pos,len);
}
StringBuf.prototype.addChar = function(c) {
	this.b[this.b.length] = String.fromCharCode(c);
}
StringBuf.prototype.toString = function() {
	return this.b.join("");
}
StringBuf.prototype.b = null;
StringBuf.prototype.__class__ = StringBuf;
if(!cocktail.core.keyboard) cocktail.core.keyboard = {}
cocktail.core.keyboard.KeyboardKeyValue = { __ename__ : ["cocktail","core","keyboard","KeyboardKeyValue"], __constructs__ : ["unknown","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","backSpace","capsLock","control","del","down","end","escape","enter","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","F13","F14","F15","home","insert","left","numpad0","numpad1","numpad2","numpad3","numpad4","numpad5","numpad6","numpad7","numpad8","numpad9","numpadAdd","numpadSpecial","numpadDecimal","numpadDivide","numpadEnter","numpadMultiply","numpadSubstract","pageDown","pageUp","right","shift","space","tab","up"] }
cocktail.core.keyboard.KeyboardKeyValue.unknown = ["unknown",0];
cocktail.core.keyboard.KeyboardKeyValue.unknown.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.unknown.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.a = ["a",1];
cocktail.core.keyboard.KeyboardKeyValue.a.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.a.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.b = ["b",2];
cocktail.core.keyboard.KeyboardKeyValue.b.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.b.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.c = ["c",3];
cocktail.core.keyboard.KeyboardKeyValue.c.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.c.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.d = ["d",4];
cocktail.core.keyboard.KeyboardKeyValue.d.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.d.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.e = ["e",5];
cocktail.core.keyboard.KeyboardKeyValue.e.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.e.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.f = ["f",6];
cocktail.core.keyboard.KeyboardKeyValue.f.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.f.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.g = ["g",7];
cocktail.core.keyboard.KeyboardKeyValue.g.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.g.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.h = ["h",8];
cocktail.core.keyboard.KeyboardKeyValue.h.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.h.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.i = ["i",9];
cocktail.core.keyboard.KeyboardKeyValue.i.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.i.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.j = ["j",10];
cocktail.core.keyboard.KeyboardKeyValue.j.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.j.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.k = ["k",11];
cocktail.core.keyboard.KeyboardKeyValue.k.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.k.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.l = ["l",12];
cocktail.core.keyboard.KeyboardKeyValue.l.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.l.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.m = ["m",13];
cocktail.core.keyboard.KeyboardKeyValue.m.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.m.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.n = ["n",14];
cocktail.core.keyboard.KeyboardKeyValue.n.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.n.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.o = ["o",15];
cocktail.core.keyboard.KeyboardKeyValue.o.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.o.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.p = ["p",16];
cocktail.core.keyboard.KeyboardKeyValue.p.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.p.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.q = ["q",17];
cocktail.core.keyboard.KeyboardKeyValue.q.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.q.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.r = ["r",18];
cocktail.core.keyboard.KeyboardKeyValue.r.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.r.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.s = ["s",19];
cocktail.core.keyboard.KeyboardKeyValue.s.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.s.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.t = ["t",20];
cocktail.core.keyboard.KeyboardKeyValue.t.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.t.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.u = ["u",21];
cocktail.core.keyboard.KeyboardKeyValue.u.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.u.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.v = ["v",22];
cocktail.core.keyboard.KeyboardKeyValue.v.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.v.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.w = ["w",23];
cocktail.core.keyboard.KeyboardKeyValue.w.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.w.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.x = ["x",24];
cocktail.core.keyboard.KeyboardKeyValue.x.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.x.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.y = ["y",25];
cocktail.core.keyboard.KeyboardKeyValue.y.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.y.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.z = ["z",26];
cocktail.core.keyboard.KeyboardKeyValue.z.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.z.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.backSpace = ["backSpace",27];
cocktail.core.keyboard.KeyboardKeyValue.backSpace.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.backSpace.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.capsLock = ["capsLock",28];
cocktail.core.keyboard.KeyboardKeyValue.capsLock.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.capsLock.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.control = ["control",29];
cocktail.core.keyboard.KeyboardKeyValue.control.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.control.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.del = ["del",30];
cocktail.core.keyboard.KeyboardKeyValue.del.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.del.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.down = ["down",31];
cocktail.core.keyboard.KeyboardKeyValue.down.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.down.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.end = ["end",32];
cocktail.core.keyboard.KeyboardKeyValue.end.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.end.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.escape = ["escape",33];
cocktail.core.keyboard.KeyboardKeyValue.escape.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.escape.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.enter = ["enter",34];
cocktail.core.keyboard.KeyboardKeyValue.enter.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.enter.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F1 = ["F1",35];
cocktail.core.keyboard.KeyboardKeyValue.F1.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F1.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F2 = ["F2",36];
cocktail.core.keyboard.KeyboardKeyValue.F2.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F2.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F3 = ["F3",37];
cocktail.core.keyboard.KeyboardKeyValue.F3.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F3.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F4 = ["F4",38];
cocktail.core.keyboard.KeyboardKeyValue.F4.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F4.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F5 = ["F5",39];
cocktail.core.keyboard.KeyboardKeyValue.F5.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F5.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F6 = ["F6",40];
cocktail.core.keyboard.KeyboardKeyValue.F6.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F6.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F7 = ["F7",41];
cocktail.core.keyboard.KeyboardKeyValue.F7.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F7.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F8 = ["F8",42];
cocktail.core.keyboard.KeyboardKeyValue.F8.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F8.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F9 = ["F9",43];
cocktail.core.keyboard.KeyboardKeyValue.F9.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F9.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F10 = ["F10",44];
cocktail.core.keyboard.KeyboardKeyValue.F10.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F10.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F11 = ["F11",45];
cocktail.core.keyboard.KeyboardKeyValue.F11.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F11.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F12 = ["F12",46];
cocktail.core.keyboard.KeyboardKeyValue.F12.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F12.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F13 = ["F13",47];
cocktail.core.keyboard.KeyboardKeyValue.F13.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F13.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F14 = ["F14",48];
cocktail.core.keyboard.KeyboardKeyValue.F14.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F14.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.F15 = ["F15",49];
cocktail.core.keyboard.KeyboardKeyValue.F15.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.F15.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.home = ["home",50];
cocktail.core.keyboard.KeyboardKeyValue.home.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.home.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.insert = ["insert",51];
cocktail.core.keyboard.KeyboardKeyValue.insert.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.insert.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.left = ["left",52];
cocktail.core.keyboard.KeyboardKeyValue.left.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.left.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad0 = ["numpad0",53];
cocktail.core.keyboard.KeyboardKeyValue.numpad0.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad0.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad1 = ["numpad1",54];
cocktail.core.keyboard.KeyboardKeyValue.numpad1.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad1.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad2 = ["numpad2",55];
cocktail.core.keyboard.KeyboardKeyValue.numpad2.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad2.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad3 = ["numpad3",56];
cocktail.core.keyboard.KeyboardKeyValue.numpad3.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad3.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad4 = ["numpad4",57];
cocktail.core.keyboard.KeyboardKeyValue.numpad4.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad4.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad5 = ["numpad5",58];
cocktail.core.keyboard.KeyboardKeyValue.numpad5.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad5.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad6 = ["numpad6",59];
cocktail.core.keyboard.KeyboardKeyValue.numpad6.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad6.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad7 = ["numpad7",60];
cocktail.core.keyboard.KeyboardKeyValue.numpad7.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad7.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad8 = ["numpad8",61];
cocktail.core.keyboard.KeyboardKeyValue.numpad8.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad8.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpad9 = ["numpad9",62];
cocktail.core.keyboard.KeyboardKeyValue.numpad9.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpad9.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadAdd = ["numpadAdd",63];
cocktail.core.keyboard.KeyboardKeyValue.numpadAdd.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadAdd.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadSpecial = ["numpadSpecial",64];
cocktail.core.keyboard.KeyboardKeyValue.numpadSpecial.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadSpecial.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadDecimal = ["numpadDecimal",65];
cocktail.core.keyboard.KeyboardKeyValue.numpadDecimal.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadDecimal.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadDivide = ["numpadDivide",66];
cocktail.core.keyboard.KeyboardKeyValue.numpadDivide.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadDivide.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadEnter = ["numpadEnter",67];
cocktail.core.keyboard.KeyboardKeyValue.numpadEnter.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadEnter.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadMultiply = ["numpadMultiply",68];
cocktail.core.keyboard.KeyboardKeyValue.numpadMultiply.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadMultiply.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.numpadSubstract = ["numpadSubstract",69];
cocktail.core.keyboard.KeyboardKeyValue.numpadSubstract.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.numpadSubstract.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.pageDown = ["pageDown",70];
cocktail.core.keyboard.KeyboardKeyValue.pageDown.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.pageDown.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.pageUp = ["pageUp",71];
cocktail.core.keyboard.KeyboardKeyValue.pageUp.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.pageUp.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.right = ["right",72];
cocktail.core.keyboard.KeyboardKeyValue.right.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.right.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.shift = ["shift",73];
cocktail.core.keyboard.KeyboardKeyValue.shift.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.shift.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.space = ["space",74];
cocktail.core.keyboard.KeyboardKeyValue.space.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.space.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.tab = ["tab",75];
cocktail.core.keyboard.KeyboardKeyValue.tab.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.tab.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
cocktail.core.keyboard.KeyboardKeyValue.up = ["up",76];
cocktail.core.keyboard.KeyboardKeyValue.up.toString = $estr;
cocktail.core.keyboard.KeyboardKeyValue.up.__enum__ = cocktail.core.keyboard.KeyboardKeyValue;
haxe.Log = function() { }
haxe.Log.__name__ = ["haxe","Log"];
haxe.Log.trace = function(v,infos) {
	js.Boot.__trace(v,infos);
}
haxe.Log.clear = function() {
	js.Boot.__clear_trace();
}
haxe.Log.prototype.__class__ = haxe.Log;
cocktail.core.mouse.AbstractMouseCursor = function(p) {
	if( p === $_ ) return;
	this._nativeMouseCursor = cocktail.core.mouse.MouseCursorValue.cssAuto;
}
cocktail.core.mouse.AbstractMouseCursor.__name__ = ["cocktail","core","mouse","AbstractMouseCursor"];
cocktail.core.mouse.AbstractMouseCursor.prototype._nativeMouseCursor = null;
cocktail.core.mouse.AbstractMouseCursor.prototype.nativeMouseCursor = null;
cocktail.core.mouse.AbstractMouseCursor.prototype.setNativeMouseCursor = function(value) {
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
cocktail.core.mouse.AbstractMouseCursor.prototype.getNativeMouseCursor = function() {
	return this._nativeMouseCursor;
}
cocktail.core.mouse.AbstractMouseCursor.prototype.setBitmapCursor = function(imageHTMLElement,hotSpot) {
}
cocktail.core.mouse.AbstractMouseCursor.prototype.hideCursor = function() {
}
cocktail.core.mouse.AbstractMouseCursor.prototype.setDefaultCursor = function() {
}
cocktail.core.mouse.AbstractMouseCursor.prototype.setNativeOSCursor = function(value) {
}
cocktail.core.mouse.AbstractMouseCursor.prototype.__class__ = cocktail.core.mouse.AbstractMouseCursor;
cocktail.core.renderer.InitialBlockRenderer = function(style) {
	if( style === $_ ) return;
	cocktail.core.renderer.BlockBoxRenderer.call(this,style);
	var width = cocktail.Lib.get_window().get_innerWidth();
	var height = cocktail.Lib.get_window().get_innerHeight();
	this._bounds.width = width;
	this._bounds.height = height;
}
cocktail.core.renderer.InitialBlockRenderer.__name__ = ["cocktail","core","renderer","InitialBlockRenderer"];
cocktail.core.renderer.InitialBlockRenderer.__super__ = cocktail.core.renderer.BlockBoxRenderer;
for(var k in cocktail.core.renderer.BlockBoxRenderer.prototype ) cocktail.core.renderer.InitialBlockRenderer.prototype[k] = cocktail.core.renderer.BlockBoxRenderer.prototype[k];
cocktail.core.renderer.InitialBlockRenderer.prototype.isInitialContainer = function() {
	return true;
}
cocktail.core.renderer.InitialBlockRenderer.prototype.init = function() {
	this._backgroundManager = new cocktail.core.background.InitialBlockBackgroundManager();
}
cocktail.core.renderer.InitialBlockRenderer.prototype.__class__ = cocktail.core.renderer.InitialBlockRenderer;
cocktail.port.browser.HTMLImageElement = function(p) {
	if( p === $_ ) return;
	cocktail.core.html.AbstractHTMLImageElement.call(this);
}
cocktail.port.browser.HTMLImageElement.__name__ = ["cocktail","port","browser","HTMLImageElement"];
cocktail.port.browser.HTMLImageElement.__super__ = cocktail.core.html.AbstractHTMLImageElement;
for(var k in cocktail.core.html.AbstractHTMLImageElement.prototype ) cocktail.port.browser.HTMLImageElement.prototype[k] = cocktail.core.html.AbstractHTMLImageElement.prototype[k];
cocktail.port.browser.HTMLImageElement.prototype.initNativeElement = function() {
	this._nativeElement = this._embeddedAsset;
}
cocktail.port.browser.HTMLImageElement.prototype.__class__ = cocktail.port.browser.HTMLImageElement;
cocktail.core.resource.XMLHTTPRequest = function(p) {
	if( p === $_ ) return;
	this._http = new haxe.Http("");
	this._http.onData = $closure(this,"onHTTPData");
	this._http.onStatus = $closure(this,"onHTTPStatus");
	this._http.onError = $closure(this,"onHTTPError");
	this.setReadyState(0);
}
cocktail.core.resource.XMLHTTPRequest.__name__ = ["cocktail","core","resource","XMLHTTPRequest"];
cocktail.core.resource.XMLHTTPRequest.prototype._readyState = null;
cocktail.core.resource.XMLHTTPRequest.prototype.readyState = null;
cocktail.core.resource.XMLHTTPRequest.prototype._responseText = null;
cocktail.core.resource.XMLHTTPRequest.prototype.responseText = null;
cocktail.core.resource.XMLHTTPRequest.prototype._status = null;
cocktail.core.resource.XMLHTTPRequest.prototype.status = null;
cocktail.core.resource.XMLHTTPRequest.prototype.onReadyStateChange = null;
cocktail.core.resource.XMLHTTPRequest.prototype._http = null;
cocktail.core.resource.XMLHTTPRequest.prototype._method = null;
cocktail.core.resource.XMLHTTPRequest.prototype.open = function(method,url) {
	this._http.url = url;
	this._method = method;
	this.setReadyState(1);
}
cocktail.core.resource.XMLHTTPRequest.prototype.send = function(content) {
	var post = false;
	switch(this._method.toUpperCase()) {
	case "POST":
		post = true;
		break;
	}
	this._http.request(post);
	this.setReadyState(3);
}
cocktail.core.resource.XMLHTTPRequest.prototype.setRequestHeader = function(name,value) {
	this._http.setHeader(name,value);
}
cocktail.core.resource.XMLHTTPRequest.prototype.onHTTPStatus = function(status) {
	this._status = status;
}
cocktail.core.resource.XMLHTTPRequest.prototype.onHTTPData = function(data) {
	this._responseText = data;
	this.setReadyState(4);
}
cocktail.core.resource.XMLHTTPRequest.prototype.onHTTPError = function(data) {
	this._responseText = data;
	this.setReadyState(4);
}
cocktail.core.resource.XMLHTTPRequest.prototype.setReadyState = function(value) {
	this._readyState = value;
	if(this.onReadyStateChange != null) this.onReadyStateChange(new cocktail.core.event.Event("readystatechange",this));
}
cocktail.core.resource.XMLHTTPRequest.prototype.get_readyState = function() {
	return this._readyState;
}
cocktail.core.resource.XMLHTTPRequest.prototype.get_status = function() {
	return this._status;
}
cocktail.core.resource.XMLHTTPRequest.prototype.get_responseText = function() {
	return this._responseText;
}
cocktail.core.resource.XMLHTTPRequest.prototype.__class__ = cocktail.core.resource.XMLHTTPRequest;
cocktail.core.resource.XMLHTTPRequest.__interfaces__ = [cocktail.core.event.IEventTarget];
cocktail.core.html.HTMLCanvasElement = function(p) {
	if( p === $_ ) return;
	cocktail.core.html.EmbeddedElement.call(this,"canvas");
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
}
cocktail.core.html.HTMLCanvasElement.__name__ = ["cocktail","core","html","HTMLCanvasElement"];
cocktail.core.html.HTMLCanvasElement.__super__ = cocktail.core.html.EmbeddedElement;
for(var k in cocktail.core.html.EmbeddedElement.prototype ) cocktail.core.html.HTMLCanvasElement.prototype[k] = cocktail.core.html.EmbeddedElement.prototype[k];
cocktail.core.html.HTMLCanvasElement.prototype._drawingManager = null;
cocktail.core.html.HTMLCanvasElement.prototype.initEmbeddedAsset = function() {
	this._embeddedAsset = this._nativeElement;
}
cocktail.core.html.HTMLCanvasElement.prototype.getContext = function(contextID) {
	if(contextID == "2d") {
		if(this._drawingManager == null) this._drawingManager = new cocktail.port.browser.DrawingManager(this._nativeElement,this._intrinsicHeight,this._intrinsicWidth);
		return this._drawingManager;
	} else return null;
}
cocktail.core.html.HTMLCanvasElement.prototype.set_width = function(value) {
	this._drawingManager.setWidth(value);
	return this._width = value;
}
cocktail.core.html.HTMLCanvasElement.prototype.set_height = function(value) {
	this._drawingManager.setHeight(value);
	return this._height = value;
}
cocktail.core.html.HTMLCanvasElement.prototype.__class__ = cocktail.core.html.HTMLCanvasElement;
utest.ui.common.HeaderDisplayMode = { __ename__ : ["utest","ui","common","HeaderDisplayMode"], __constructs__ : ["AlwaysShowHeader","NeverShowHeader","ShowHeaderWithResults"] }
utest.ui.common.HeaderDisplayMode.AlwaysShowHeader = ["AlwaysShowHeader",0];
utest.ui.common.HeaderDisplayMode.AlwaysShowHeader.toString = $estr;
utest.ui.common.HeaderDisplayMode.AlwaysShowHeader.__enum__ = utest.ui.common.HeaderDisplayMode;
utest.ui.common.HeaderDisplayMode.NeverShowHeader = ["NeverShowHeader",1];
utest.ui.common.HeaderDisplayMode.NeverShowHeader.toString = $estr;
utest.ui.common.HeaderDisplayMode.NeverShowHeader.__enum__ = utest.ui.common.HeaderDisplayMode;
utest.ui.common.HeaderDisplayMode.ShowHeaderWithResults = ["ShowHeaderWithResults",2];
utest.ui.common.HeaderDisplayMode.ShowHeaderWithResults.toString = $estr;
utest.ui.common.HeaderDisplayMode.ShowHeaderWithResults.__enum__ = utest.ui.common.HeaderDisplayMode;
utest.ui.common.SuccessResultsDisplayMode = { __ename__ : ["utest","ui","common","SuccessResultsDisplayMode"], __constructs__ : ["AlwaysShowSuccessResults","NeverShowSuccessResults","ShowSuccessResultsWithNoErrors"] }
utest.ui.common.SuccessResultsDisplayMode.AlwaysShowSuccessResults = ["AlwaysShowSuccessResults",0];
utest.ui.common.SuccessResultsDisplayMode.AlwaysShowSuccessResults.toString = $estr;
utest.ui.common.SuccessResultsDisplayMode.AlwaysShowSuccessResults.__enum__ = utest.ui.common.SuccessResultsDisplayMode;
utest.ui.common.SuccessResultsDisplayMode.NeverShowSuccessResults = ["NeverShowSuccessResults",1];
utest.ui.common.SuccessResultsDisplayMode.NeverShowSuccessResults.toString = $estr;
utest.ui.common.SuccessResultsDisplayMode.NeverShowSuccessResults.__enum__ = utest.ui.common.SuccessResultsDisplayMode;
utest.ui.common.SuccessResultsDisplayMode.ShowSuccessResultsWithNoErrors = ["ShowSuccessResultsWithNoErrors",2];
utest.ui.common.SuccessResultsDisplayMode.ShowSuccessResultsWithNoErrors.toString = $estr;
utest.ui.common.SuccessResultsDisplayMode.ShowSuccessResultsWithNoErrors.__enum__ = utest.ui.common.SuccessResultsDisplayMode;
utest.ui.common.PackageResult = function(packageName) {
	if( packageName === $_ ) return;
	this.packageName = packageName;
	this.classes = new Hash();
	this.packages = new Hash();
	this.stats = new utest.ui.common.ResultStats();
}
utest.ui.common.PackageResult.__name__ = ["utest","ui","common","PackageResult"];
utest.ui.common.PackageResult.prototype.packageName = null;
utest.ui.common.PackageResult.prototype.classes = null;
utest.ui.common.PackageResult.prototype.packages = null;
utest.ui.common.PackageResult.prototype.stats = null;
utest.ui.common.PackageResult.prototype.addResult = function(result,flattenPackage) {
	var pack = this.getOrCreatePackage(result.pack,flattenPackage,this);
	var cls = this.getOrCreateClass(pack,result.cls,result.setup,result.teardown);
	var fix = this.createFixture(result.method,result.assertations);
	cls.add(fix);
}
utest.ui.common.PackageResult.prototype.addClass = function(result) {
	this.classes.set(result.className,result);
	this.stats.wire(result.stats);
}
utest.ui.common.PackageResult.prototype.addPackage = function(result) {
	this.packages.set(result.packageName,result);
	this.stats.wire(result.stats);
}
utest.ui.common.PackageResult.prototype.existsPackage = function(name) {
	return this.packages.exists(name);
}
utest.ui.common.PackageResult.prototype.existsClass = function(name) {
	return this.classes.exists(name);
}
utest.ui.common.PackageResult.prototype.getPackage = function(name) {
	if(this.packageName == null && name == "") return this;
	return this.packages.get(name);
}
utest.ui.common.PackageResult.prototype.getClass = function(name) {
	return this.classes.get(name);
}
utest.ui.common.PackageResult.prototype.classNames = function(errorsHavePriority) {
	if(errorsHavePriority == null) errorsHavePriority = true;
	var names = [];
	var $it0 = this.classes.keys();
	while( $it0.hasNext() ) {
		var name = $it0.next();
		names.push(name);
	}
	if(errorsHavePriority) {
		var me = this;
		names.sort(function(a,b) {
			var $as = me.getClass(a).stats;
			var bs = me.getClass(b).stats;
			if($as.hasErrors) return !bs.hasErrors?-1:$as.errors == bs.errors?Reflect.compare(a,b):Reflect.compare($as.errors,bs.errors); else if(bs.hasErrors) return 1; else if($as.hasFailures) return !bs.hasFailures?-1:$as.failures == bs.failures?Reflect.compare(a,b):Reflect.compare($as.failures,bs.failures); else if(bs.hasFailures) return 1; else if($as.hasWarnings) return !bs.hasWarnings?-1:$as.warnings == bs.warnings?Reflect.compare(a,b):Reflect.compare($as.warnings,bs.warnings); else if(bs.hasWarnings) return 1; else return Reflect.compare(a,b);
		});
	} else names.sort(function(a,b) {
		return Reflect.compare(a,b);
	});
	return names;
}
utest.ui.common.PackageResult.prototype.packageNames = function(errorsHavePriority) {
	if(errorsHavePriority == null) errorsHavePriority = true;
	var names = [];
	if(this.packageName == null) names.push("");
	var $it0 = this.packages.keys();
	while( $it0.hasNext() ) {
		var name = $it0.next();
		names.push(name);
	}
	if(errorsHavePriority) {
		var me = this;
		names.sort(function(a,b) {
			var $as = me.getPackage(a).stats;
			var bs = me.getPackage(b).stats;
			if($as.hasErrors) return !bs.hasErrors?-1:$as.errors == bs.errors?Reflect.compare(a,b):Reflect.compare($as.errors,bs.errors); else if(bs.hasErrors) return 1; else if($as.hasFailures) return !bs.hasFailures?-1:$as.failures == bs.failures?Reflect.compare(a,b):Reflect.compare($as.failures,bs.failures); else if(bs.hasFailures) return 1; else if($as.hasWarnings) return !bs.hasWarnings?-1:$as.warnings == bs.warnings?Reflect.compare(a,b):Reflect.compare($as.warnings,bs.warnings); else if(bs.hasWarnings) return 1; else return Reflect.compare(a,b);
		});
	} else names.sort(function(a,b) {
		return Reflect.compare(a,b);
	});
	return names;
}
utest.ui.common.PackageResult.prototype.createFixture = function(method,assertations) {
	var f = new utest.ui.common.FixtureResult(method);
	var $it0 = assertations.iterator();
	while( $it0.hasNext() ) {
		var assertation = $it0.next();
		f.add(assertation);
	}
	return f;
}
utest.ui.common.PackageResult.prototype.getOrCreateClass = function(pack,cls,setup,teardown) {
	if(pack.existsClass(cls)) return pack.getClass(cls);
	var c = new utest.ui.common.ClassResult(cls,setup,teardown);
	pack.addClass(c);
	return c;
}
utest.ui.common.PackageResult.prototype.getOrCreatePackage = function(pack,flat,ref) {
	if(pack == null || pack == "") return ref;
	if(flat) {
		if(ref.existsPackage(pack)) return ref.getPackage(pack);
		var p = new utest.ui.common.PackageResult(pack);
		ref.addPackage(p);
		return p;
	} else {
		var parts = pack.split(".");
		var _g = 0;
		while(_g < parts.length) {
			var part = parts[_g];
			++_g;
			ref = this.getOrCreatePackage(part,true,ref);
		}
		return ref;
	}
}
utest.ui.common.PackageResult.prototype.__class__ = utest.ui.common.PackageResult;
utest.TestHandler = function(fixture) {
	if( fixture === $_ ) return;
	if(fixture == null) throw "fixture argument is null";
	this.fixture = fixture;
	this.results = new List();
	this.asyncStack = new List();
	this.onTested = new utest.Dispatcher();
	this.onTimeout = new utest.Dispatcher();
	this.onComplete = new utest.Dispatcher();
}
utest.TestHandler.__name__ = ["utest","TestHandler"];
utest.TestHandler.exceptionStack = function(pops) {
	if(pops == null) pops = 2;
	var stack = haxe.Stack.exceptionStack();
	while(pops-- > 0) stack.pop();
	return stack;
}
utest.TestHandler.prototype.results = null;
utest.TestHandler.prototype.fixture = null;
utest.TestHandler.prototype.asyncStack = null;
utest.TestHandler.prototype.onTested = null;
utest.TestHandler.prototype.onTimeout = null;
utest.TestHandler.prototype.onComplete = null;
utest.TestHandler.prototype.execute = function() {
	try {
		this.executeMethod(this.fixture.setup);
		try {
			this.executeMethod(this.fixture.method);
		} catch( e ) {
			this.results.add(utest.Assertation.Error(e,utest.TestHandler.exceptionStack()));
		}
	} catch( e ) {
		this.results.add(utest.Assertation.SetupError(e,utest.TestHandler.exceptionStack()));
	}
	this.checkTested();
}
utest.TestHandler.prototype.checkTested = function() {
	if(this.expireson == null || this.asyncStack.length == 0) this.tested(); else if(haxe.Timer.stamp() > this.expireson) this.timeout(); else haxe.Timer.delay($closure(this,"checkTested"),10);
}
utest.TestHandler.prototype.expireson = null;
utest.TestHandler.prototype.setTimeout = function(timeout) {
	var newexpire = haxe.Timer.stamp() + timeout / 1000;
	this.expireson = this.expireson == null?newexpire:newexpire > this.expireson?newexpire:this.expireson;
}
utest.TestHandler.prototype.bindHandler = function() {
	utest.Assert.results = this.results;
	utest.Assert.createAsync = $closure(this,"addAsync");
	utest.Assert.createEvent = $closure(this,"addEvent");
}
utest.TestHandler.prototype.unbindHandler = function() {
	utest.Assert.results = null;
	utest.Assert.createAsync = function(f,t) {
		return function() {
		};
	};
	utest.Assert.createEvent = function(f,t) {
		return function(e) {
		};
	};
}
utest.TestHandler.prototype.addAsync = function(f,timeout) {
	if(timeout == null) timeout = 250;
	if(null == f) f = function() {
	};
	this.asyncStack.add(f);
	var handler = this;
	this.setTimeout(timeout);
	return function() {
		if(!handler.asyncStack.remove(f)) {
			handler.results.add(utest.Assertation.AsyncError("method already executed",[]));
			return;
		}
		try {
			handler.bindHandler();
			f();
		} catch( e ) {
			handler.results.add(utest.Assertation.AsyncError(e,utest.TestHandler.exceptionStack(0)));
		}
	};
}
utest.TestHandler.prototype.addEvent = function(f,timeout) {
	if(timeout == null) timeout = 250;
	this.asyncStack.add(f);
	var handler = this;
	this.setTimeout(timeout);
	return function(e) {
		if(!handler.asyncStack.remove(f)) {
			handler.results.add(utest.Assertation.AsyncError("event already executed",[]));
			return;
		}
		try {
			handler.bindHandler();
			f(e);
		} catch( e1 ) {
			handler.results.add(utest.Assertation.AsyncError(e1,utest.TestHandler.exceptionStack(0)));
		}
	};
}
utest.TestHandler.prototype.executeMethod = function(name) {
	if(name == null) return;
	this.bindHandler();
	Reflect.field(this.fixture.target,name).apply(this.fixture.target,[]);
}
utest.TestHandler.prototype.tested = function() {
	if(this.results.length == 0) this.results.add(utest.Assertation.Warning("no assertions"));
	this.onTested.dispatch(this);
	this.completed();
}
utest.TestHandler.prototype.timeout = function() {
	this.results.add(utest.Assertation.TimeoutError(this.asyncStack.length,[]));
	this.onTimeout.dispatch(this);
	this.completed();
}
utest.TestHandler.prototype.completed = function() {
	try {
		this.executeMethod(this.fixture.teardown);
	} catch( e ) {
		this.results.add(utest.Assertation.TeardownError(e,utest.TestHandler.exceptionStack(2)));
	}
	this.unbindHandler();
	this.onComplete.dispatch(this);
}
utest.TestHandler.prototype.__class__ = utest.TestHandler;
utest.TestFixture = function(target,method,setup,teardown) {
	if( target === $_ ) return;
	this.target = target;
	this.method = method;
	this.setup = setup;
	this.teardown = teardown;
}
utest.TestFixture.__name__ = ["utest","TestFixture"];
utest.TestFixture.prototype.target = null;
utest.TestFixture.prototype.method = null;
utest.TestFixture.prototype.setup = null;
utest.TestFixture.prototype.teardown = null;
utest.TestFixture.prototype.checkMethod = function(name,arg) {
	var field = Reflect.field(this.target,name);
	if(field == null) throw arg + " function " + name + " is not a field of target";
	if(!Reflect.isFunction(field)) throw arg + " function " + name + " is not a function";
}
utest.TestFixture.prototype.__class__ = utest.TestFixture;
if(!cocktail.core.drawing) cocktail.core.drawing = {}
cocktail.core.drawing.AbstractDrawingManager = function(nativeElement,width,height) {
	if( nativeElement === $_ ) return;
	this._nativeElement = nativeElement;
	this._width = width;
	this._height = height;
}
cocktail.core.drawing.AbstractDrawingManager.__name__ = ["cocktail","core","drawing","AbstractDrawingManager"];
cocktail.core.drawing.AbstractDrawingManager.prototype._nativeElement = null;
cocktail.core.drawing.AbstractDrawingManager.prototype.nativeElement = null;
cocktail.core.drawing.AbstractDrawingManager.prototype._width = null;
cocktail.core.drawing.AbstractDrawingManager.prototype.width = null;
cocktail.core.drawing.AbstractDrawingManager.prototype._height = null;
cocktail.core.drawing.AbstractDrawingManager.prototype.height = null;
cocktail.core.drawing.AbstractDrawingManager.prototype.beginFill = function(fillStyle,lineStyle) {
	if(fillStyle == null) fillStyle = cocktail.core.dom.FillStyleValue.none;
	if(lineStyle == null) lineStyle = cocktail.core.dom.LineStyleValue.none;
	this.setFillStyle(fillStyle);
	this.setLineStyle(lineStyle);
}
cocktail.core.drawing.AbstractDrawingManager.prototype.endFill = function() {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.clear = function() {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.setLineStyle = function(lineStyle) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.setFillStyle = function(fillStyle) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.drawRect = function(x,y,width,height,cornerRadiuses) {
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
cocktail.core.drawing.AbstractDrawingManager.prototype.drawEllipse = function(x,y,width,height) {
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
cocktail.core.drawing.AbstractDrawingManager.prototype.drawImage = function(source,matrix,sourceRect) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.lineTo = function(x,y) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.moveTo = function(x,y) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.curveTo = function(controlX,controlY,x,y) {
}
cocktail.core.drawing.AbstractDrawingManager.prototype.toNativeAlpha = function(genericAlpa) {
	return null;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.toNativeColor = function(genericColor) {
	return null;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.toNativeRatio = function(genericRatio) {
	return null;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.toNativeCapStyle = function(genericCapStyle) {
	return null;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.toNativeJointStyle = function(genericJointStyle) {
	return null;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.getNativeElement = function() {
	return this._nativeElement;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.setWidth = function(value) {
	return this._width = value;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.getWidth = function() {
	return this._width;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.setHeight = function(value) {
	return this._height = value;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.getHeight = function() {
	return this._height;
}
cocktail.core.drawing.AbstractDrawingManager.prototype.__class__ = cocktail.core.drawing.AbstractDrawingManager;
cocktail.core.resource.AbstractMediaLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	this._nativeElement = nativeElement;
	cocktail.core.resource.AbstractResourceLoader.call(this);
}
cocktail.core.resource.AbstractMediaLoader.__name__ = ["cocktail","core","resource","AbstractMediaLoader"];
cocktail.core.resource.AbstractMediaLoader.__super__ = cocktail.core.resource.AbstractResourceLoader;
for(var k in cocktail.core.resource.AbstractResourceLoader.prototype ) cocktail.core.resource.AbstractMediaLoader.prototype[k] = cocktail.core.resource.AbstractResourceLoader.prototype[k];
cocktail.core.resource.AbstractMediaLoader.prototype._nativeElement = null;
cocktail.core.resource.AbstractMediaLoader.prototype.nativeElement = null;
cocktail.core.resource.AbstractMediaLoader.prototype._intrinsicWidth = null;
cocktail.core.resource.AbstractMediaLoader.prototype.intrinsicWidth = null;
cocktail.core.resource.AbstractMediaLoader.prototype._intrinsicHeight = null;
cocktail.core.resource.AbstractMediaLoader.prototype.intrinsicHeight = null;
cocktail.core.resource.AbstractMediaLoader.prototype._intrinsicRatio = null;
cocktail.core.resource.AbstractMediaLoader.prototype.intrinsicRatio = null;
cocktail.core.resource.AbstractMediaLoader.prototype.getNativeElement = function() {
	return this._nativeElement;
}
cocktail.core.resource.AbstractMediaLoader.prototype.getIntrinsicWidth = function() {
	return this._intrinsicWidth;
}
cocktail.core.resource.AbstractMediaLoader.prototype.getIntrinsicHeight = function() {
	return this._intrinsicHeight;
}
cocktail.core.resource.AbstractMediaLoader.prototype.getIntrinsicRatio = function() {
	return this._intrinsicRatio;
}
cocktail.core.resource.AbstractMediaLoader.prototype.__class__ = cocktail.core.resource.AbstractMediaLoader;
Std = function() { }
Std.__name__ = ["Std"];
Std["is"] = function(v,t) {
	return js.Boot.__instanceof(v,t);
}
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std["int"] = function(x) {
	if(x < 0) return Math.ceil(x);
	return Math.floor(x);
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
Std.prototype.__class__ = Std;
cocktail.core.style.EmbeddedCoreStyle = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.style.CoreStyle.call(this,htmlElement);
}
cocktail.core.style.EmbeddedCoreStyle.__name__ = ["cocktail","core","style","EmbeddedCoreStyle"];
cocktail.core.style.EmbeddedCoreStyle.__super__ = cocktail.core.style.CoreStyle;
for(var k in cocktail.core.style.CoreStyle.prototype ) cocktail.core.style.EmbeddedCoreStyle.prototype[k] = cocktail.core.style.CoreStyle.prototype[k];
cocktail.core.style.EmbeddedCoreStyle.prototype.__class__ = cocktail.core.style.EmbeddedCoreStyle;
haxe.Timer = function(time_ms) {
	if( time_ms === $_ ) return;
	var arr = haxe_timers;
	this.id = arr.length;
	arr[this.id] = this;
	this.timerId = window.setInterval("haxe_timers[" + this.id + "].run();",time_ms);
}
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
haxe.Timer.prototype.id = null;
haxe.Timer.prototype.timerId = null;
haxe.Timer.prototype.stop = function() {
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
haxe.Timer.prototype.run = function() {
}
haxe.Timer.prototype.__class__ = haxe.Timer;
cocktail.core.style.FontSize = { __ename__ : ["cocktail","core","style","FontSize"], __constructs__ : ["length","percentage","absoluteSize","relativeSize"] }
cocktail.core.style.FontSize.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.absoluteSize = function(value) { var $x = ["absoluteSize",2,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontSize.relativeSize = function(value) { var $x = ["relativeSize",3,value]; $x.__enum__ = cocktail.core.style.FontSize; $x.toString = $estr; return $x; }
cocktail.core.style.FontWeight = { __ename__ : ["cocktail","core","style","FontWeight"], __constructs__ : ["normal","bold","bolder","lighter","css100","css200","css300","css400","css500","css600","css700","css800","css900"] }
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
cocktail.core.style.FontStyle = { __ename__ : ["cocktail","core","style","FontStyle"], __constructs__ : ["normal","italic"] }
cocktail.core.style.FontStyle.normal = ["normal",0];
cocktail.core.style.FontStyle.normal.toString = $estr;
cocktail.core.style.FontStyle.normal.__enum__ = cocktail.core.style.FontStyle;
cocktail.core.style.FontStyle.italic = ["italic",1];
cocktail.core.style.FontStyle.italic.toString = $estr;
cocktail.core.style.FontStyle.italic.__enum__ = cocktail.core.style.FontStyle;
cocktail.core.style.FontVariant = { __ename__ : ["cocktail","core","style","FontVariant"], __constructs__ : ["normal","smallCaps"] }
cocktail.core.style.FontVariant.normal = ["normal",0];
cocktail.core.style.FontVariant.normal.toString = $estr;
cocktail.core.style.FontVariant.normal.__enum__ = cocktail.core.style.FontVariant;
cocktail.core.style.FontVariant.smallCaps = ["smallCaps",1];
cocktail.core.style.FontVariant.smallCaps.toString = $estr;
cocktail.core.style.FontVariant.smallCaps.__enum__ = cocktail.core.style.FontVariant;
cocktail.core.style.WhiteSpace = { __ename__ : ["cocktail","core","style","WhiteSpace"], __constructs__ : ["normal","pre","nowrap","preWrap","preLine"] }
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
cocktail.core.style.LetterSpacing = { __ename__ : ["cocktail","core","style","LetterSpacing"], __constructs__ : ["normal","length"] }
cocktail.core.style.LetterSpacing.normal = ["normal",0];
cocktail.core.style.LetterSpacing.normal.toString = $estr;
cocktail.core.style.LetterSpacing.normal.__enum__ = cocktail.core.style.LetterSpacing;
cocktail.core.style.LetterSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.core.style.LetterSpacing; $x.toString = $estr; return $x; }
cocktail.core.style.WordSpacing = { __ename__ : ["cocktail","core","style","WordSpacing"], __constructs__ : ["normal","length"] }
cocktail.core.style.WordSpacing.normal = ["normal",0];
cocktail.core.style.WordSpacing.normal.toString = $estr;
cocktail.core.style.WordSpacing.normal.__enum__ = cocktail.core.style.WordSpacing;
cocktail.core.style.WordSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.core.style.WordSpacing; $x.toString = $estr; return $x; }
cocktail.core.style.TextIndent = { __ename__ : ["cocktail","core","style","TextIndent"], __constructs__ : ["length","percentage"] }
cocktail.core.style.TextIndent.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.TextIndent; $x.toString = $estr; return $x; }
cocktail.core.style.TextIndent.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.core.style.TextIndent; $x.toString = $estr; return $x; }
cocktail.core.style.TextAlign = { __ename__ : ["cocktail","core","style","TextAlign"], __constructs__ : ["left","right","center","justify"] }
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
cocktail.core.style.TextTransform = { __ename__ : ["cocktail","core","style","TextTransform"], __constructs__ : ["capitalize","uppercase","lowercase","none"] }
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
cocktail.core.style.LineHeight = { __ename__ : ["cocktail","core","style","LineHeight"], __constructs__ : ["normal","number","length","percentage"] }
cocktail.core.style.LineHeight.normal = ["normal",0];
cocktail.core.style.LineHeight.normal.toString = $estr;
cocktail.core.style.LineHeight.normal.__enum__ = cocktail.core.style.LineHeight;
cocktail.core.style.LineHeight.number = function(value) { var $x = ["number",1,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.LineHeight.length = function(value) { var $x = ["length",2,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.LineHeight.percentage = function(value) { var $x = ["percentage",3,value]; $x.__enum__ = cocktail.core.style.LineHeight; $x.toString = $estr; return $x; }
cocktail.core.style.VerticalAlign = { __ename__ : ["cocktail","core","style","VerticalAlign"], __constructs__ : ["baseline","sub","cssSuper","top","textTop","middle","bottom","textBottom","percent","length"] }
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
cocktail.core.style.Margin = { __ename__ : ["cocktail","core","style","Margin"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.Margin.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Margin; $x.toString = $estr; return $x; }
cocktail.core.style.Margin.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Margin; $x.toString = $estr; return $x; }
cocktail.core.style.Margin.cssAuto = ["cssAuto",2];
cocktail.core.style.Margin.cssAuto.toString = $estr;
cocktail.core.style.Margin.cssAuto.__enum__ = cocktail.core.style.Margin;
cocktail.core.style.Padding = { __ename__ : ["cocktail","core","style","Padding"], __constructs__ : ["length","percent"] }
cocktail.core.style.Padding.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Padding; $x.toString = $estr; return $x; }
cocktail.core.style.Padding.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Padding; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension = { __ename__ : ["cocktail","core","style","Dimension"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.Dimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Dimension; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Dimension; $x.toString = $estr; return $x; }
cocktail.core.style.Dimension.cssAuto = ["cssAuto",2];
cocktail.core.style.Dimension.cssAuto.toString = $estr;
cocktail.core.style.Dimension.cssAuto.__enum__ = cocktail.core.style.Dimension;
cocktail.core.style.ConstrainedDimension = { __ename__ : ["cocktail","core","style","ConstrainedDimension"], __constructs__ : ["length","percent","none"] }
cocktail.core.style.ConstrainedDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
cocktail.core.style.ConstrainedDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
cocktail.core.style.ConstrainedDimension.none = ["none",2];
cocktail.core.style.ConstrainedDimension.none.toString = $estr;
cocktail.core.style.ConstrainedDimension.none.__enum__ = cocktail.core.style.ConstrainedDimension;
cocktail.core.style.Display = { __ename__ : ["cocktail","core","style","Display"], __constructs__ : ["block","inlineBlock","cssInline","none"] }
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
cocktail.core.style.CSSFloat = { __ename__ : ["cocktail","core","style","CSSFloat"], __constructs__ : ["left","right","none"] }
cocktail.core.style.CSSFloat.left = ["left",0];
cocktail.core.style.CSSFloat.left.toString = $estr;
cocktail.core.style.CSSFloat.left.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.CSSFloat.right = ["right",1];
cocktail.core.style.CSSFloat.right.toString = $estr;
cocktail.core.style.CSSFloat.right.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.CSSFloat.none = ["none",2];
cocktail.core.style.CSSFloat.none.toString = $estr;
cocktail.core.style.CSSFloat.none.__enum__ = cocktail.core.style.CSSFloat;
cocktail.core.style.Clear = { __ename__ : ["cocktail","core","style","Clear"], __constructs__ : ["none","left","right","both"] }
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
cocktail.core.style.Position = { __ename__ : ["cocktail","core","style","Position"], __constructs__ : ["cssStatic","relative","absolute","fixed"] }
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
cocktail.core.style.PositionOffset = { __ename__ : ["cocktail","core","style","PositionOffset"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.PositionOffset.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.PositionOffset; $x.toString = $estr; return $x; }
cocktail.core.style.PositionOffset.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.PositionOffset; $x.toString = $estr; return $x; }
cocktail.core.style.PositionOffset.cssAuto = ["cssAuto",2];
cocktail.core.style.PositionOffset.cssAuto.toString = $estr;
cocktail.core.style.PositionOffset.cssAuto.__enum__ = cocktail.core.style.PositionOffset;
cocktail.core.style.Overflow = { __ename__ : ["cocktail","core","style","Overflow"], __constructs__ : ["visible","hidden","scroll","cssAuto"] }
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
cocktail.core.style.Visibility = { __ename__ : ["cocktail","core","style","Visibility"], __constructs__ : ["visible","hidden"] }
cocktail.core.style.Visibility.visible = ["visible",0];
cocktail.core.style.Visibility.visible.toString = $estr;
cocktail.core.style.Visibility.visible.__enum__ = cocktail.core.style.Visibility;
cocktail.core.style.Visibility.hidden = ["hidden",1];
cocktail.core.style.Visibility.hidden.toString = $estr;
cocktail.core.style.Visibility.hidden.__enum__ = cocktail.core.style.Visibility;
cocktail.core.style.Transform = { __ename__ : ["cocktail","core","style","Transform"], __constructs__ : ["none","transformFunctions"] }
cocktail.core.style.Transform.none = ["none",0];
cocktail.core.style.Transform.none.toString = $estr;
cocktail.core.style.Transform.none.__enum__ = cocktail.core.style.Transform;
cocktail.core.style.Transform.transformFunctions = function(transformFunctions) { var $x = ["transformFunctions",1,transformFunctions]; $x.__enum__ = cocktail.core.style.Transform; $x.toString = $estr; return $x; }
cocktail.core.style.TransformFunction = { __ename__ : ["cocktail","core","style","TransformFunction"], __constructs__ : ["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","skew"] }
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
cocktail.core.style.Translation = { __ename__ : ["cocktail","core","style","Translation"], __constructs__ : ["length","percent"] }
cocktail.core.style.Translation.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.Translation; $x.toString = $estr; return $x; }
cocktail.core.style.Translation.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.Translation; $x.toString = $estr; return $x; }
cocktail.core.style.TransformOriginX = { __ename__ : ["cocktail","core","style","TransformOriginX"], __constructs__ : ["length","percent","left","center","right"] }
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
cocktail.core.style.TransformOriginY = { __ename__ : ["cocktail","core","style","TransformOriginY"], __constructs__ : ["length","percent","top","center","bottom"] }
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
cocktail.core.style.BackgroundImage = { __ename__ : ["cocktail","core","style","BackgroundImage"], __constructs__ : ["none","image"] }
cocktail.core.style.BackgroundImage.none = ["none",0];
cocktail.core.style.BackgroundImage.none.toString = $estr;
cocktail.core.style.BackgroundImage.none.__enum__ = cocktail.core.style.BackgroundImage;
cocktail.core.style.BackgroundImage.image = function(value) { var $x = ["image",1,value]; $x.__enum__ = cocktail.core.style.BackgroundImage; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundRepeatValue = { __ename__ : ["cocktail","core","style","BackgroundRepeatValue"], __constructs__ : ["repeat","space","round","noRepeat"] }
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
cocktail.core.style.BackgroundPositionX = { __ename__ : ["cocktail","core","style","BackgroundPositionX"], __constructs__ : ["length","percent","left","center","right"] }
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
cocktail.core.style.BackgroundPositionY = { __ename__ : ["cocktail","core","style","BackgroundPositionY"], __constructs__ : ["length","percent","top","center","bottom"] }
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
cocktail.core.style.BackgroundClip = { __ename__ : ["cocktail","core","style","BackgroundClip"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.core.style.BackgroundClip.borderBox = ["borderBox",0];
cocktail.core.style.BackgroundClip.borderBox.toString = $estr;
cocktail.core.style.BackgroundClip.borderBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundClip.paddingBox = ["paddingBox",1];
cocktail.core.style.BackgroundClip.paddingBox.toString = $estr;
cocktail.core.style.BackgroundClip.paddingBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundClip.contentBox = ["contentBox",2];
cocktail.core.style.BackgroundClip.contentBox.toString = $estr;
cocktail.core.style.BackgroundClip.contentBox.__enum__ = cocktail.core.style.BackgroundClip;
cocktail.core.style.BackgroundOrigin = { __ename__ : ["cocktail","core","style","BackgroundOrigin"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.core.style.BackgroundOrigin.borderBox = ["borderBox",0];
cocktail.core.style.BackgroundOrigin.borderBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.borderBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundOrigin.paddingBox = ["paddingBox",1];
cocktail.core.style.BackgroundOrigin.paddingBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.paddingBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundOrigin.contentBox = ["contentBox",2];
cocktail.core.style.BackgroundOrigin.contentBox.toString = $estr;
cocktail.core.style.BackgroundOrigin.contentBox.__enum__ = cocktail.core.style.BackgroundOrigin;
cocktail.core.style.BackgroundSize = { __ename__ : ["cocktail","core","style","BackgroundSize"], __constructs__ : ["contain","cover","dimensions"] }
cocktail.core.style.BackgroundSize.contain = ["contain",0];
cocktail.core.style.BackgroundSize.contain.toString = $estr;
cocktail.core.style.BackgroundSize.contain.__enum__ = cocktail.core.style.BackgroundSize;
cocktail.core.style.BackgroundSize.cover = ["cover",1];
cocktail.core.style.BackgroundSize.cover.toString = $estr;
cocktail.core.style.BackgroundSize.cover.__enum__ = cocktail.core.style.BackgroundSize;
cocktail.core.style.BackgroundSize.dimensions = function(value) { var $x = ["dimensions",2,value]; $x.__enum__ = cocktail.core.style.BackgroundSize; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension = { __ename__ : ["cocktail","core","style","BackgroundSizeDimension"], __constructs__ : ["length","percent","cssAuto"] }
cocktail.core.style.BackgroundSizeDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
cocktail.core.style.BackgroundSizeDimension.cssAuto = ["cssAuto",2];
cocktail.core.style.BackgroundSizeDimension.cssAuto.toString = $estr;
cocktail.core.style.BackgroundSizeDimension.cssAuto.__enum__ = cocktail.core.style.BackgroundSizeDimension;
cocktail.core.style.Cursor = { __ename__ : ["cocktail","core","style","Cursor"], __constructs__ : ["cssAuto","crosshair","cssDefault","pointer"] }
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
cocktail.core.style.positioner.FixedPositioner = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.positioner.BoxPositioner.call(this);
}
cocktail.core.style.positioner.FixedPositioner.__name__ = ["cocktail","core","style","positioner","FixedPositioner"];
cocktail.core.style.positioner.FixedPositioner.__super__ = cocktail.core.style.positioner.BoxPositioner;
for(var k in cocktail.core.style.positioner.BoxPositioner.prototype ) cocktail.core.style.positioner.FixedPositioner.prototype[k] = cocktail.core.style.positioner.BoxPositioner.prototype[k];
cocktail.core.style.positioner.FixedPositioner.prototype.__class__ = cocktail.core.style.positioner.FixedPositioner;
if(!cocktail.core.unit) cocktail.core.unit = {}
cocktail.core.unit.UnitManager = function(p) {
}
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
cocktail.core.unit.UnitManager.prototype.__class__ = cocktail.core.unit.UnitManager;
cocktail.core.nativeElement.NativeElementTypeValue = { __ename__ : ["cocktail","core","nativeElement","NativeElementTypeValue"], __constructs__ : ["canvas","img","script","anchor","input","semantic"] }
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
cocktail.core.font.FontType = { __ename__ : ["cocktail","core","font","FontType"], __constructs__ : ["ttf","otf","eot","swf","system","unknown"] }
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
cocktail.core.geom.Matrix = function(data) {
	if( data === $_ ) return;
	this.setData(data);
}
cocktail.core.geom.Matrix.__name__ = ["cocktail","core","geom","Matrix"];
cocktail.core.geom.Matrix.prototype._data = null;
cocktail.core.geom.Matrix.prototype.data = null;
cocktail.core.geom.Matrix.prototype.identity = function() {
	this._data = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : 0.0, f : 0.0};
}
cocktail.core.geom.Matrix.prototype.setData = function(data) {
	this._data = data;
	if(this._data == null) this.identity();
	return this._data;
}
cocktail.core.geom.Matrix.prototype.getData = function() {
	return this._data;
}
cocktail.core.geom.Matrix.prototype.concatenate = function(matrix) {
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
cocktail.core.geom.Matrix.prototype.translate = function(x,y) {
	var translationMatrixData = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : x, f : y};
	var translationMatrix = new cocktail.core.geom.Matrix(translationMatrixData);
	this.concatenate(translationMatrix);
}
cocktail.core.geom.Matrix.prototype.rotate = function(angle,registrationPoint) {
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
cocktail.core.geom.Matrix.prototype.scale = function(scaleX,scaleY,registrationPoint) {
	var scaledMatrix = new cocktail.core.geom.Matrix();
	scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
	var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
	var scalingMatrix = new cocktail.core.geom.Matrix(scalingMatrixData);
	scaledMatrix.concatenate(scalingMatrix);
	scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
	this.concatenate(scaledMatrix);
}
cocktail.core.geom.Matrix.prototype.skew = function(skewX,skewY,registrationPoint) {
	var skewedMatrix = new cocktail.core.geom.Matrix();
	skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
	var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
	var skewingMatrix = new cocktail.core.geom.Matrix(skewingMatrixData);
	skewedMatrix.concatenate(skewingMatrix);
	skewedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
	this.concatenate(skewedMatrix);
}
cocktail.core.geom.Matrix.prototype.setRotation = function(angle,registrationPoint) {
	var currentRotation = this.getRotation();
	var resetAngle = Math.PI * 2 - currentRotation;
	this.rotate(resetAngle,registrationPoint);
	this.rotate(angle,registrationPoint);
}
cocktail.core.geom.Matrix.prototype.getRotation = function() {
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
cocktail.core.geom.Matrix.prototype.getFlip = function() {
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
cocktail.core.geom.Matrix.prototype.setScaleX = function(scaleXFactor,registrationPoint) {
	var currentScaleX = this.getScaleX();
	var resetScaleX = 1 / currentScaleX;
	this.scale(resetScaleX,1,registrationPoint);
	this.scale(scaleXFactor,1,registrationPoint);
}
cocktail.core.geom.Matrix.prototype.getScaleX = function() {
	return this._data.a;
}
cocktail.core.geom.Matrix.prototype.setScaleY = function(scaleYFactor,registrationPoint) {
	var currentScaleY = this.getScaleY();
	var resetScaleY = 1 / currentScaleY;
	this.scale(1,resetScaleY,registrationPoint);
	this.scale(1,scaleYFactor,registrationPoint);
}
cocktail.core.geom.Matrix.prototype.getScaleY = function() {
	return this._data.d;
}
cocktail.core.geom.Matrix.prototype.setTranslationX = function(translationX) {
	var currentTranslationX = this.getTranslationX();
	var resetTranslationX = currentTranslationX * -1;
	this.translate(resetTranslationX,0);
	this.translate(translationX,0);
}
cocktail.core.geom.Matrix.prototype.getTranslationX = function() {
	return this._data.e;
}
cocktail.core.geom.Matrix.prototype.setTranslationY = function(translationY) {
	var currentTranslationY = this.getTranslationY();
	var resetTranslationY = currentTranslationY * -1;
	this.translate(0,resetTranslationY);
	this.translate(0,translationY);
}
cocktail.core.geom.Matrix.prototype.getTranslationY = function() {
	return this._data.f;
}
cocktail.core.geom.Matrix.prototype.getSkewX = function() {
	return this._data.c;
}
cocktail.core.geom.Matrix.prototype.getSkewY = function() {
	return this._data.b;
}
cocktail.core.geom.Matrix.prototype.__class__ = cocktail.core.geom.Matrix;
utest.Assertation = { __ename__ : ["utest","Assertation"], __constructs__ : ["Success","Failure","Error","SetupError","TeardownError","TimeoutError","AsyncError","Warning"] }
utest.Assertation.Success = function(pos) { var $x = ["Success",0,pos]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Failure = function(msg,pos) { var $x = ["Failure",1,msg,pos]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Error = function(e,stack) { var $x = ["Error",2,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.SetupError = function(e,stack) { var $x = ["SetupError",3,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.TeardownError = function(e,stack) { var $x = ["TeardownError",4,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.TimeoutError = function(missedAsyncs,stack) { var $x = ["TimeoutError",5,missedAsyncs,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.AsyncError = function(e,stack) { var $x = ["AsyncError",6,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Warning = function(msg) { var $x = ["Warning",7,msg]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
cocktail.port.browser.DrawingManager = function(nativeElement,width,height) {
	if( nativeElement === $_ ) return;
	cocktail.core.drawing.AbstractDrawingManager.call(this,nativeElement,width,height);
}
cocktail.port.browser.DrawingManager.__name__ = ["cocktail","port","browser","DrawingManager"];
cocktail.port.browser.DrawingManager.__super__ = cocktail.core.drawing.AbstractDrawingManager;
for(var k in cocktail.core.drawing.AbstractDrawingManager.prototype ) cocktail.port.browser.DrawingManager.prototype[k] = cocktail.core.drawing.AbstractDrawingManager.prototype[k];
cocktail.port.browser.DrawingManager.prototype.beginFill = function(fillStyle,lineStyle) {
	cocktail.core.drawing.AbstractDrawingManager.prototype.beginFill.call(this,fillStyle,lineStyle);
	var canvasContext = this.getContext();
	canvasContext.beginPath();
}
cocktail.port.browser.DrawingManager.prototype.endFill = function() {
	var canvasContext = this.getContext();
	canvasContext.closePath();
	canvasContext.fill();
	canvasContext.stroke();
}
cocktail.port.browser.DrawingManager.prototype.clear = function() {
	var canvasContext = this.getContext();
	canvasContext.clearRect(0,0,this.getWidth(),this.getHeight());
}
cocktail.port.browser.DrawingManager.prototype.setFillStyle = function(fillStyle) {
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
cocktail.port.browser.DrawingManager.prototype.setLineStyle = function(lineStyle) {
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
cocktail.port.browser.DrawingManager.prototype.drawImage = function(source,matrix,sourceRect) {
	if(matrix == null) matrix = new cocktail.core.geom.Matrix();
	if(sourceRect == null) {
		var width = source.width;
		var height = source.height;
		sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
	}
	var canvasContext = this.getContext();
}
cocktail.port.browser.DrawingManager.prototype.lineTo = function(x,y) {
	var canvasContext = this.getContext();
	canvasContext.lineTo(x,y);
}
cocktail.port.browser.DrawingManager.prototype.moveTo = function(x,y) {
	var canvasContext = this.getContext();
	canvasContext.moveTo(x,y);
}
cocktail.port.browser.DrawingManager.prototype.curveTo = function(controlX,controlY,x,y) {
	var canvasContext = this.getContext();
	canvasContext.quadraticCurveTo(controlX,controlY,x,y);
}
cocktail.port.browser.DrawingManager.prototype.toNativeAlpha = function(genericAlpha) {
	return genericAlpha;
}
cocktail.port.browser.DrawingManager.prototype.toNativeRatio = function(genericRatio) {
	return genericRatio * 0.01;
}
cocktail.port.browser.DrawingManager.prototype.toNativeCapStyle = function(genericCapStyle) {
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
cocktail.port.browser.DrawingManager.prototype.toNativeJointStyle = function(genericJointStyle) {
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
cocktail.port.browser.DrawingManager.prototype.colorStopToRGBA = function(colorStop) {
	var rgb = this.hexToRGB(this.getHexColor(colorStop.color));
	return "rgba(" + rgb.red + "," + rgb.green + "," + rgb.blue + "," + this.toNativeAlpha(colorStop.alpha) + ")";
}
cocktail.port.browser.DrawingManager.prototype.getHexColor = function(color) {
	var hexColor = StringTools.hex(color);
	while(hexColor.length < 6) hexColor = "0" + hexColor;
	return "#" + hexColor;
}
cocktail.port.browser.DrawingManager.prototype.hexToRGB = function(hex) {
	var hexCopy = hex;
	var hexCopy1 = hexCopy.substr(1);
	var rgb = { red : Std.parseInt("0x" + hexCopy1.substr(0,2)), green : Std.parseInt("0x" + hexCopy1.substr(2,2)), blue : Std.parseInt("0x" + hexCopy1.substr(4,2))};
	return rgb;
}
cocktail.port.browser.DrawingManager.prototype.initLineStyle = function(lineStyleData) {
	var canvasContext = this.getContext();
	canvasContext.lineWidth = lineStyleData.thickness;
	canvasContext.lineCap = this.toNativeCapStyle(lineStyleData.capStyle);
	canvasContext.lineJoin = this.toNativeJointStyle(lineStyleData.jointStyle);
	canvasContext.miterLimit = lineStyleData.miterLimit;
}
cocktail.port.browser.DrawingManager.prototype.getContext = function() {
	return this._nativeElement.getContext("2d");
}
cocktail.port.browser.DrawingManager.prototype.getCanvasPattern = function(htmlImageElement,repeat) {
	var canvasContext = this.getContext();
	var repeatValue = "";
	if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
	return canvasContext.createPattern(htmlImageElement.get_nativeElement(),repeatValue);
}
cocktail.port.browser.DrawingManager.prototype.getGradient = function(gradientStyle) {
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
cocktail.port.browser.DrawingManager.prototype.setWidth = function(value) {
	this.clear();
	cocktail.core.drawing.AbstractDrawingManager.prototype.setWidth.call(this,value);
	this._nativeElement.width = value;
	return this._width = value;
}
cocktail.port.browser.DrawingManager.prototype.setHeight = function(value) {
	this.clear();
	cocktail.core.drawing.AbstractDrawingManager.prototype.setHeight.call(this,value);
	this._nativeElement.height = value;
	return this._height = value;
}
cocktail.port.browser.DrawingManager.prototype.__class__ = cocktail.port.browser.DrawingManager;
cocktail.Lib = function(p) {
}
cocktail.Lib.__name__ = ["cocktail","Lib"];
cocktail.Lib._document = null;
cocktail.Lib.document = null;
cocktail.Lib._window = null;
cocktail.Lib.window = null;
cocktail.Lib.init = function() {
	cocktail.Lib._document = new cocktail.core.html.HTMLDocument();
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
cocktail.Lib.prototype.__class__ = cocktail.Lib;
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
cocktail.port.browser.Window = function(document) {
	if( document === $_ ) return;
	cocktail.core.window.AbstractWindow.call(this,document);
}
cocktail.port.browser.Window.__name__ = ["cocktail","port","browser","Window"];
cocktail.port.browser.Window.__super__ = cocktail.core.window.AbstractWindow;
for(var k in cocktail.core.window.AbstractWindow.prototype ) cocktail.port.browser.Window.prototype[k] = cocktail.core.window.AbstractWindow.prototype[k];
cocktail.port.browser.Window.prototype.set_onResize = function(value) {
	if(value == null) js.Lib.window.removeEventListener("resize",$closure(this,"onNativeResize")); else js.Lib.window.addEventListener("resize",$closure(this,"onNativeResize"));
	return this._onResize = value;
}
cocktail.port.browser.Window.prototype.get_innerHeight = function() {
	return js.Lib.window.innerHeight;
}
cocktail.port.browser.Window.prototype.get_innerWidth = function() {
	return js.Lib.window.innerWidth;
}
cocktail.port.browser.Window.prototype.onNativeResize = function(event) {
	if(this._onResize != null) this._onResize(new cocktail.core.event.Event("resize",this));
}
cocktail.port.browser.Window.prototype.__class__ = cocktail.port.browser.Window;
haxe.io.Error = { __ename__ : ["haxe","io","Error"], __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] }
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
cocktail.core.keyboard.AbstractKeyboard = function(htmlElement) {
	if( htmlElement === $_ ) return;
	this._htmlElement = htmlElement;
}
cocktail.core.keyboard.AbstractKeyboard.__name__ = ["cocktail","core","keyboard","AbstractKeyboard"];
cocktail.core.keyboard.AbstractKeyboard.prototype._onKeyDown = null;
cocktail.core.keyboard.AbstractKeyboard.prototype.onKeyDown = null;
cocktail.core.keyboard.AbstractKeyboard.prototype._onKeyUp = null;
cocktail.core.keyboard.AbstractKeyboard.prototype.onKeyUp = null;
cocktail.core.keyboard.AbstractKeyboard.prototype._htmlElement = null;
cocktail.core.keyboard.AbstractKeyboard.prototype._keyDownEvent = null;
cocktail.core.keyboard.AbstractKeyboard.prototype._keyUpEvent = null;
cocktail.core.keyboard.AbstractKeyboard.prototype.onNativeKeyDown = function(event) {
	if(this.getOnKeyDown() != null) (this.getOnKeyDown())(this.getKeyData(event));
}
cocktail.core.keyboard.AbstractKeyboard.prototype.onNativeKeyUp = function(event) {
	if(this.getOnKeyUp() != null) (this.getOnKeyUp())(this.getKeyData(event));
}
cocktail.core.keyboard.AbstractKeyboard.prototype.setOnKeyDown = function(value) {
	this.updateListeners(this._keyDownEvent,$closure(this,"onNativeKeyDown"),value);
	return this._onKeyDown = value;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.getOnKeyDown = function() {
	return this._onKeyDown;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.setOnKeyUp = function(value) {
	this.updateListeners(this._keyUpEvent,$closure(this,"onNativeKeyUp"),value);
	return this._onKeyUp = value;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.getOnKeyUp = function() {
	return this._onKeyUp;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.updateListeners = function(keyboardEvent,nativeCallback,htmlElementCallback) {
}
cocktail.core.keyboard.AbstractKeyboard.prototype.getKeyData = function(event) {
	return null;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.getKeyValue = function(keyCode) {
	var keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.unknown;
	switch(keyCode) {
	case 65:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.a;
		break;
	case 66:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.b;
		break;
	case 67:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.c;
		break;
	case 68:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.d;
		break;
	case 69:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.e;
		break;
	case 70:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.f;
		break;
	case 71:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.g;
		break;
	case 72:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.h;
		break;
	case 73:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.i;
		break;
	case 74:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.j;
		break;
	case 75:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.k;
		break;
	case 76:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.l;
		break;
	case 77:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.m;
		break;
	case 78:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.n;
		break;
	case 79:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.o;
		break;
	case 80:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.p;
		break;
	case 81:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.q;
		break;
	case 82:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.r;
		break;
	case 83:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.s;
		break;
	case 84:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.t;
		break;
	case 85:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.u;
		break;
	case 86:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.v;
		break;
	case 87:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.w;
		break;
	case 88:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.x;
		break;
	case 89:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.y;
		break;
	case 90:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.z;
		break;
	case 8:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.backSpace;
		break;
	case 20:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.capsLock;
		break;
	case 17:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.control;
		break;
	case 46:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.del;
		break;
	case 40:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.down;
		break;
	case 35:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.end;
		break;
	case 13:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.enter;
		break;
	case 27:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.escape;
		break;
	case 112:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F1;
		break;
	case 121:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F10;
		break;
	case 122:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F11;
		break;
	case 123:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F12;
		break;
	case 124:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F13;
		break;
	case 125:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F14;
		break;
	case 126:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F15;
		break;
	case 113:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F2;
		break;
	case 114:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F3;
		break;
	case 115:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F4;
		break;
	case 116:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F5;
		break;
	case 117:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F6;
		break;
	case 118:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F7;
		break;
	case 119:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F8;
		break;
	case 120:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.F9;
		break;
	case 36:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.home;
		break;
	case 45:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.insert;
		break;
	case 37:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.left;
		break;
	case 96:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad0;
		break;
	case 97:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad1;
		break;
	case 98:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad2;
		break;
	case 99:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad3;
		break;
	case 100:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad4;
		break;
	case 101:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad5;
		break;
	case 102:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad6;
		break;
	case 103:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad7;
		break;
	case 104:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad8;
		break;
	case 105:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpad9;
		break;
	case 107:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadAdd;
		break;
	case 108:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadEnter;
		break;
	case 110:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadDecimal;
		break;
	case 111:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadDivide;
		break;
	case 106:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadMultiply;
		break;
	case 109:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.numpadSubstract;
		break;
	case 34:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.pageDown;
		break;
	case 33:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.pageUp;
		break;
	case 39:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.right;
		break;
	case 16:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.shift;
		break;
	case 32:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.space;
		break;
	case 9:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.tab;
		break;
	case 38:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.up;
		break;
	default:
		keyboardKeyValue = cocktail.core.keyboard.KeyboardKeyValue.unknown;
	}
	return keyboardKeyValue;
}
cocktail.core.keyboard.AbstractKeyboard.prototype.__class__ = cocktail.core.keyboard.AbstractKeyboard;
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
cocktail.core.dom.Attr = function(name) {
	if( name === $_ ) return;
	this._name = name;
	this._specified = false;
	cocktail.core.dom.Node.call(this);
}
cocktail.core.dom.Attr.__name__ = ["cocktail","core","dom","Attr"];
cocktail.core.dom.Attr.__super__ = cocktail.core.dom.Node;
for(var k in cocktail.core.dom.Node.prototype ) cocktail.core.dom.Attr.prototype[k] = cocktail.core.dom.Node.prototype[k];
cocktail.core.dom.Attr.prototype._name = null;
cocktail.core.dom.Attr.prototype.name = null;
cocktail.core.dom.Attr.prototype._value = null;
cocktail.core.dom.Attr.prototype.value = null;
cocktail.core.dom.Attr.prototype._specified = null;
cocktail.core.dom.Attr.prototype.specified = null;
cocktail.core.dom.Attr.prototype._isId = null;
cocktail.core.dom.Attr.prototype.isId = null;
cocktail.core.dom.Attr.prototype._ownerElement = null;
cocktail.core.dom.Attr.prototype.ownerElement = null;
cocktail.core.dom.Attr.prototype.get_nodeName = function() {
	return this._name;
}
cocktail.core.dom.Attr.prototype.get_nodeType = function() {
	return 2;
}
cocktail.core.dom.Attr.prototype.get_nodeValue = function() {
	return this.get_value();
}
cocktail.core.dom.Attr.prototype.set_nodeValue = function(value) {
	return this.set_value(value);
}
cocktail.core.dom.Attr.prototype.get_ownerElement = function() {
	return this._ownerElement;
}
cocktail.core.dom.Attr.prototype.set_ownerElement = function(value) {
	return this._ownerElement = value;
}
cocktail.core.dom.Attr.prototype.get_isId = function() {
	return this._isId;
}
cocktail.core.dom.Attr.prototype.set_isId = function(value) {
	return this._isId = value;
}
cocktail.core.dom.Attr.prototype.get_name = function() {
	return this._name;
}
cocktail.core.dom.Attr.prototype.get_value = function() {
	if(this._value == null) return "";
	return this._value;
}
cocktail.core.dom.Attr.prototype.set_value = function(value) {
	this._specified = true;
	return this._value = value;
}
cocktail.core.dom.Attr.prototype.get_specified = function() {
	return this._specified;
}
cocktail.core.dom.Attr.prototype.__class__ = cocktail.core.dom.Attr;
cocktail.port.browser.MediaLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktail.core.resource.AbstractMediaLoader.call(this,nativeElement);
}
cocktail.port.browser.MediaLoader.__name__ = ["cocktail","port","browser","MediaLoader"];
cocktail.port.browser.MediaLoader.__super__ = cocktail.core.resource.AbstractMediaLoader;
for(var k in cocktail.core.resource.AbstractMediaLoader.prototype ) cocktail.port.browser.MediaLoader.prototype[k] = cocktail.core.resource.AbstractMediaLoader.prototype[k];
cocktail.port.browser.MediaLoader.prototype.doLoad = function(url) {
	var onLoadCompleteDelegate = $closure(this,"onNativeLoadComplete");
	var onLoadErrorDelegate = $closure(this,"onNativeLoadError");
	var nativeElementDelegate = this._nativeElement;
	this._nativeElement.onload = function() {
		onLoadCompleteDelegate(nativeElementDelegate);
	};
	this._nativeElement.onerror = function() {
		onLoadErrorDelegate("couldn't load picture");
	};
	this._nativeElement.setAttribute("src",url);
}
cocktail.port.browser.MediaLoader.prototype.onNativeLoadComplete = function(nativeElement) {
	this.setIntrinsicDimensions(nativeElement);
	this.onLoadComplete(nativeElement);
}
cocktail.port.browser.MediaLoader.prototype.onNativeLoadError = function(event) {
	this.onLoadError(event.toString());
}
cocktail.port.browser.MediaLoader.prototype.setIntrinsicDimensions = function(nativeElement) {
	this._intrinsicHeight = nativeElement.naturalHeight;
	this._intrinsicWidth = nativeElement.naturalWidth;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
}
cocktail.port.browser.MediaLoader.prototype.__class__ = cocktail.port.browser.MediaLoader;
cocktail.core.resource.AbstractImageLoader = function(p) {
	if( p === $_ ) return;
	var nativeElement = cocktail.core.nativeElement.NativeElementManager.createNativeElement(cocktail.core.nativeElement.NativeElementTypeValue.img);
	cocktail.port.browser.MediaLoader.call(this,nativeElement);
}
cocktail.core.resource.AbstractImageLoader.__name__ = ["cocktail","core","resource","AbstractImageLoader"];
cocktail.core.resource.AbstractImageLoader.__super__ = cocktail.port.browser.MediaLoader;
for(var k in cocktail.port.browser.MediaLoader.prototype ) cocktail.core.resource.AbstractImageLoader.prototype[k] = cocktail.port.browser.MediaLoader.prototype[k];
cocktail.core.resource.AbstractImageLoader.prototype.__class__ = cocktail.core.resource.AbstractImageLoader;
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.BoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.BoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.measureVerticalPaddings = function(style,containingHTMLElementData) {
	style.getComputedStyle().paddingTop = 0;
	style.getComputedStyle().paddingBottom = 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.measureAutoHeight = function(style,containingHTMLElementData) {
	this.setComputedHeight(style,this.getComputedAutoHeight(style,containingHTMLElementData));
	style.getComputedStyle().marginTop = 0;
	style.getComputedStyle().marginBottom = 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.measureHeight = function(style,containingHTMLElementData) {
	this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
	style.getComputedStyle().marginTop = 0;
	style.getComputedStyle().marginBottom = 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	return 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedWidth = function(style,containingHTMLElementData) {
	return 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedHeight = function(style,containingHTMLElementData) {
	return 0;
}
cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
cocktail.port.browser.FontManager = function(p) {
	if( p === $_ ) return;
	cocktail.core.font.AbstractFontManager.call(this);
}
cocktail.port.browser.FontManager.__name__ = ["cocktail","port","browser","FontManager"];
cocktail.port.browser.FontManager.__super__ = cocktail.core.font.AbstractFontManager;
for(var k in cocktail.core.font.AbstractFontManager.prototype ) cocktail.port.browser.FontManager.prototype[k] = cocktail.core.font.AbstractFontManager.prototype[k];
cocktail.port.browser.FontManager.prototype.getSystemFonts = function() {
	haxe.Log.trace("It is impossible to list the system fonts in javascript",{ fileName : "FontManager.hx", lineNumber : 38, className : "cocktail.port.browser.FontManager", methodName : "getSystemFonts"});
	return new Array();
}
cocktail.port.browser.FontManager.prototype.__class__ = cocktail.port.browser.FontManager;
haxe.Http = function(url) {
	if( url === $_ ) return;
	this.url = url;
	this.headers = new Hash();
	this.params = new Hash();
	this.async = true;
}
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
haxe.Http.prototype.url = null;
haxe.Http.prototype.async = null;
haxe.Http.prototype.postData = null;
haxe.Http.prototype.headers = null;
haxe.Http.prototype.params = null;
haxe.Http.prototype.setHeader = function(header,value) {
	this.headers.set(header,value);
}
haxe.Http.prototype.setParameter = function(param,value) {
	this.params.set(param,value);
}
haxe.Http.prototype.setPostData = function(data) {
	this.postData = data;
}
haxe.Http.prototype.request = function(post) {
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
haxe.Http.prototype.onData = function(data) {
}
haxe.Http.prototype.onError = function(msg) {
}
haxe.Http.prototype.onStatus = function(status) {
}
haxe.Http.prototype.__class__ = haxe.Http;
utest.Assert = function() { }
utest.Assert.__name__ = ["utest","Assert"];
utest.Assert.results = null;
utest.Assert.isTrue = function(cond,msg,pos) {
	if(utest.Assert.results == null) throw "Assert.results is not currently bound to any assert context";
	if(null == msg) msg = "expected true";
	if(cond) utest.Assert.results.add(utest.Assertation.Success(pos)); else utest.Assert.results.add(utest.Assertation.Failure(msg,pos));
}
utest.Assert.isFalse = function(value,msg,pos) {
	if(null == msg) msg = "expected false";
	utest.Assert.isTrue(value == false,msg,pos);
}
utest.Assert.isNull = function(value,msg,pos) {
	if(msg == null) msg = "expected null but was " + utest.Assert.q(value);
	utest.Assert.isTrue(value == null,msg,pos);
}
utest.Assert.notNull = function(value,msg,pos) {
	if(null == msg) msg = "expected false";
	utest.Assert.isTrue(value != null,msg,pos);
}
utest.Assert["is"] = function(value,type,msg,pos) {
	if(msg == null) msg = "expected type " + utest.Assert.typeToString(type) + " but was " + utest.Assert.typeToString(value);
	utest.Assert.isTrue(Std["is"](value,type),msg,pos);
}
utest.Assert.notEquals = function(expected,value,msg,pos) {
	if(msg == null) msg = "expected " + utest.Assert.q(expected) + " and testa value " + utest.Assert.q(value) + " should be different";
	utest.Assert.isFalse(expected == value,msg,pos);
}
utest.Assert.equals = function(expected,value,msg,pos) {
	if(msg == null) msg = "expected " + utest.Assert.q(expected) + " but was " + utest.Assert.q(value);
	utest.Assert.isTrue(expected == value,msg,pos);
}
utest.Assert.match = function(pattern,value,msg,pos) {
	if(msg == null) msg = "the value " + utest.Assert.q(value) + "does not match the provided pattern";
	utest.Assert.isTrue(pattern.match(value),msg,pos);
}
utest.Assert.floatEquals = function(expected,value,approx,msg,pos) {
	if(msg == null) msg = "expected " + utest.Assert.q(expected) + " but was " + utest.Assert.q(value);
	return utest.Assert.isTrue(utest.Assert._floatEquals(expected,value,approx),msg,pos);
}
utest.Assert._floatEquals = function(expected,value,approx) {
	if(Math.isNaN(expected)) return Math.isNaN(value); else if(Math.isNaN(value)) return false; else if(!Math.isFinite(expected) && !Math.isFinite(value)) return expected > 0 == value > 0;
	if(null == approx) approx = 1e-5;
	return Math.abs(value - expected) < approx;
}
utest.Assert.getTypeName = function(v) {
	var $e = (Type["typeof"](v));
	switch( $e[1] ) {
	case 0:
		return "[null]";
	case 1:
		return "Int";
	case 2:
		return "Float";
	case 3:
		return "Bool";
	case 5:
		return "function";
	case 6:
		var c = $e[2];
		return Type.getClassName(c);
	case 7:
		var e = $e[2];
		return Type.getEnumName(e);
	case 4:
		return "Object";
	case 8:
		return "Unknown";
	}
}
utest.Assert.isIterable = function(v,isAnonym) {
	var fields = isAnonym?Reflect.fields(v):Type.getInstanceFields(Type.getClass(v));
	if(!Lambda.has(fields,"iterator")) return false;
	return Reflect.isFunction(Reflect.field(v,"iterator"));
}
utest.Assert.isIterator = function(v,isAnonym) {
	var fields = isAnonym?Reflect.fields(v):Type.getInstanceFields(Type.getClass(v));
	if(!Lambda.has(fields,"next") || !Lambda.has(fields,"hasNext")) return false;
	return Reflect.isFunction(Reflect.field(v,"next")) && Reflect.isFunction(Reflect.field(v,"hasNext"));
}
utest.Assert.sameAs = function(expected,value,status) {
	var texpected = utest.Assert.getTypeName(expected);
	var tvalue = utest.Assert.getTypeName(value);
	if(texpected != tvalue) {
		status.error = "expected type " + texpected + " but it is " + tvalue + (status.path == ""?"":" for field " + status.path);
		return false;
	}
	var $e = (Type["typeof"](expected));
	switch( $e[1] ) {
	case 2:
		if(!utest.Assert._floatEquals(expected,value)) {
			status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
			return false;
		}
		return true;
	case 0:
	case 1:
	case 3:
		if(expected != value) {
			status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
			return false;
		}
		return true;
	case 5:
		if(!Reflect.compareMethods(expected,value)) {
			status.error = "expected same function reference" + (status.path == ""?"":" for field " + status.path);
			return false;
		}
		return true;
	case 6:
		var c = $e[2];
		var cexpected = Type.getClassName(c);
		var cvalue = Type.getClassName(Type.getClass(value));
		if(cexpected != cvalue) {
			status.error = "expected instance of " + utest.Assert.q(cexpected) + " but it is " + utest.Assert.q(cvalue) + (status.path == ""?"":" for field " + status.path);
			return false;
		}
		if(Std["is"](expected,String) && expected != value) {
			status.error = "expected '" + expected + "' but it is '" + value + "'";
			return false;
		}
		if(Std["is"](expected,Array)) {
			if(status.recursive || status.path == "") {
				if(expected.length != value.length) {
					status.error = "expected " + expected.length + " elements but they were " + value.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g1 = 0, _g = expected.length;
				while(_g1 < _g) {
					var i = _g1++;
					status.path = path == ""?"array[" + i + "]":path + "[" + i + "]";
					if(!utest.Assert.sameAs(expected[i],value[i],status)) {
						status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
						return false;
					}
				}
			}
			return true;
		}
		if(Std["is"](expected,Date)) {
			if(expected.getTime() != value.getTime()) {
				status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
				return false;
			}
			return true;
		}
		if(Std["is"](expected,haxe.io.Bytes)) {
			if(status.recursive || status.path == "") {
				var ebytes = expected;
				var vbytes = value;
				if(ebytes.length != vbytes.length) return false;
				var _g1 = 0, _g = ebytes.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(ebytes.b[i] != vbytes.b[i]) {
						status.error = "expected byte " + ebytes.b[i] + " but wss " + ebytes.b[i] + (status.path == ""?"":" for field " + status.path);
						return false;
					}
				}
			}
			return true;
		}
		if(Std["is"](expected,Hash) || Std["is"](expected,IntHash)) {
			if(status.recursive || status.path == "") {
				var keys = Lambda.array({ iterator : function() {
					return expected.keys();
				}});
				var vkeys = Lambda.array({ iterator : function() {
					return value.keys();
				}});
				if(keys.length != vkeys.length) {
					status.error = "expected " + keys.length + " keys but they were " + vkeys.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g = 0;
				while(_g < keys.length) {
					var key = keys[_g];
					++_g;
					status.path = path == ""?"hash[" + key + "]":path + "[" + key + "]";
					if(!utest.Assert.sameAs(expected.get(key),value.get(key),status)) {
						status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
						return false;
					}
				}
			}
			return true;
		}
		if(utest.Assert.isIterator(expected,false)) {
			if(status.recursive || status.path == "") {
				var evalues = Lambda.array({ iterator : function() {
					return expected;
				}});
				var vvalues = Lambda.array({ iterator : function() {
					return value;
				}});
				if(evalues.length != vvalues.length) {
					status.error = "expected " + evalues.length + " values in Iterator but they were " + vvalues.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g1 = 0, _g = evalues.length;
				while(_g1 < _g) {
					var i = _g1++;
					status.path = path == ""?"iterator[" + i + "]":path + "[" + i + "]";
					if(!utest.Assert.sameAs(evalues[i],vvalues[i],status)) {
						status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
						return false;
					}
				}
			}
			return true;
		}
		if(utest.Assert.isIterable(expected,false)) {
			if(status.recursive || status.path == "") {
				var evalues = Lambda.array(expected);
				var vvalues = Lambda.array(value);
				if(evalues.length != vvalues.length) {
					status.error = "expected " + evalues.length + " values in Iterable but they were " + vvalues.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g1 = 0, _g = evalues.length;
				while(_g1 < _g) {
					var i = _g1++;
					status.path = path == ""?"iterable[" + i + "]":path + "[" + i + "]";
					if(!utest.Assert.sameAs(evalues[i],vvalues[i],status)) return false;
				}
			}
			return true;
		}
		if(status.recursive || status.path == "") {
			var fields = Type.getInstanceFields(Type.getClass(expected));
			var path = status.path;
			var _g = 0;
			while(_g < fields.length) {
				var field = fields[_g];
				++_g;
				status.path = path == ""?field:path + "." + field;
				var e = Reflect.field(expected,field);
				if(Reflect.isFunction(e)) continue;
				var v = Reflect.field(value,field);
				if(!utest.Assert.sameAs(e,v,status)) return false;
			}
		}
		return true;
	case 7:
		var e = $e[2];
		var eexpected = Type.getEnumName(e);
		var evalue = Type.getEnumName(Type.getEnum(value));
		if(eexpected != evalue) {
			status.error = "expected enumeration of " + utest.Assert.q(eexpected) + " but it is " + utest.Assert.q(evalue) + (status.path == ""?"":" for field " + status.path);
			return false;
		}
		if(status.recursive || status.path == "") {
			if(expected[1] != value[1]) {
				status.error = "expected " + utest.Assert.q(expected[0]) + " but is " + utest.Assert.q(value[0]) + (status.path == ""?"":" for field " + status.path);
				return false;
			}
			var eparams = expected.slice(2);
			var vparams = value.slice(2);
			var path = status.path;
			var _g1 = 0, _g = eparams.length;
			while(_g1 < _g) {
				var i = _g1++;
				status.path = path == ""?"enum[" + i + "]":path + "[" + i + "]";
				if(!utest.Assert.sameAs(eparams[i],vparams[i],status)) {
					status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
					return false;
				}
			}
		}
		return true;
	case 4:
		if(status.recursive || status.path == "") {
			var tfields = Reflect.fields(value);
			var fields = Reflect.fields(expected);
			var path = status.path;
			var _g = 0;
			while(_g < fields.length) {
				var field = fields[_g];
				++_g;
				tfields.remove(field);
				status.path = path == ""?field:path + "." + field;
				if(!Reflect.hasField(value,field)) {
					status.error = "expected field " + status.path + " does not exist in " + utest.Assert.q(value);
					return false;
				}
				var e = Reflect.field(expected,field);
				if(Reflect.isFunction(e)) continue;
				var v = Reflect.field(value,field);
				if(!utest.Assert.sameAs(e,v,status)) return false;
			}
			if(tfields.length > 0) {
				status.error = "the tested object has extra field(s) (" + tfields.join(", ") + ") not included in the expected ones";
				return false;
			}
		}
		if(utest.Assert.isIterator(expected,true)) {
			if(!utest.Assert.isIterator(value,true)) {
				status.error = "expected Iterable but it is not " + (status.path == ""?"":" for field " + status.path);
				return false;
			}
			if(status.recursive || status.path == "") {
				var evalues = Lambda.array({ iterator : function() {
					return expected;
				}});
				var vvalues = Lambda.array({ iterator : function() {
					return value;
				}});
				if(evalues.length != vvalues.length) {
					status.error = "expected " + evalues.length + " values in Iterator but they were " + vvalues.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g1 = 0, _g = evalues.length;
				while(_g1 < _g) {
					var i = _g1++;
					status.path = path == ""?"iterator[" + i + "]":path + "[" + i + "]";
					if(!utest.Assert.sameAs(evalues[i],vvalues[i],status)) {
						status.error = "expected " + utest.Assert.q(expected) + " but it is " + utest.Assert.q(value) + (status.path == ""?"":" for field " + status.path);
						return false;
					}
				}
			}
			return true;
		}
		if(utest.Assert.isIterable(expected,true)) {
			if(!utest.Assert.isIterable(value,true)) {
				status.error = "expected Iterator but it is not " + (status.path == ""?"":" for field " + status.path);
				return false;
			}
			if(status.recursive || status.path == "") {
				var evalues = Lambda.array(expected);
				var vvalues = Lambda.array(value);
				if(evalues.length != vvalues.length) {
					status.error = "expected " + evalues.length + " values in Iterable but they were " + vvalues.length + (status.path == ""?"":" for field " + status.path);
					return false;
				}
				var path = status.path;
				var _g1 = 0, _g = evalues.length;
				while(_g1 < _g) {
					var i = _g1++;
					status.path = path == ""?"iterable[" + i + "]":path + "[" + i + "]";
					if(!utest.Assert.sameAs(evalues[i],vvalues[i],status)) return false;
				}
			}
			return true;
		}
		return true;
	case 8:
		return (function($this) {
			var $r;
			throw "Unable to compare two unknown types";
			return $r;
		}(this));
	}
	return (function($this) {
		var $r;
		throw "Unable to compare values: " + utest.Assert.q(expected) + " and " + utest.Assert.q(value);
		return $r;
	}(this));
}
utest.Assert.q = function(v) {
	if(Std["is"](v,String)) return "\"" + StringTools.replace(v,"\"","\\\"") + "\""; else return Std.string(v);
}
utest.Assert.same = function(expected,value,recursive,msg,pos) {
	var status = { recursive : null == recursive?true:recursive, path : "", error : null};
	if(utest.Assert.sameAs(expected,value,status)) utest.Assert.isTrue(true,msg,pos); else utest.Assert.fail(msg == null?status.error:msg,pos);
}
utest.Assert.raises = function(method,type,msgNotThrown,msgWrongType,pos) {
	if(type == null) type = String;
	try {
		method();
		var name = Type.getClassName(type);
		if(name == null) name = "" + type;
		if(null == msgNotThrown) msgNotThrown = "exception of type " + name + " not raised";
		utest.Assert.fail(msgNotThrown,pos);
	} catch( ex ) {
		var name = Type.getClassName(type);
		if(name == null) name = "" + type;
		if(null == msgWrongType) msgWrongType = "expected throw of type " + name + " but was " + ex;
		utest.Assert.isTrue(Std["is"](ex,type),msgWrongType,pos);
	}
}
utest.Assert.allows = function(possibilities,value,msg,pos) {
	if(Lambda.has(possibilities,value)) utest.Assert.isTrue(true,msg,pos); else utest.Assert.fail(msg == null?"value " + utest.Assert.q(value) + " not found in the expected possibilities " + possibilities:msg,pos);
}
utest.Assert.contains = function(match,values,msg,pos) {
	if(Lambda.has(values,match)) utest.Assert.isTrue(true,msg,pos); else utest.Assert.fail(msg == null?"values " + utest.Assert.q(values) + " do not contain " + match:msg,pos);
}
utest.Assert.notContains = function(match,values,msg,pos) {
	if(!Lambda.has(values,match)) utest.Assert.isTrue(true,msg,pos); else utest.Assert.fail(msg == null?"values " + utest.Assert.q(values) + " do contain " + match:msg,pos);
}
utest.Assert.stringContains = function(match,value,msg,pos) {
	if(value != null && value.indexOf(match) >= 0) utest.Assert.isTrue(true,msg,pos); else utest.Assert.fail(msg == null?"value " + utest.Assert.q(value) + " does not contain " + utest.Assert.q(match):msg,pos);
}
utest.Assert.stringSequence = function(sequence,value,msg,pos) {
	if(null == value) {
		utest.Assert.fail(msg == null?"null argument value":msg,pos);
		return;
	}
	var p = 0;
	var _g = 0;
	while(_g < sequence.length) {
		var s = sequence[_g];
		++_g;
		var p2 = value.indexOf(s,p);
		if(p2 < 0) {
			if(msg == null) {
				msg = "expected '" + s + "' after ";
				if(p > 0) {
					var cut = value.substr(0,p);
					if(cut.length > 30) cut = "..." + cut.substr(-27);
					msg += " '" + cut + "'";
				} else msg += " begin";
			}
			utest.Assert.fail(msg,pos);
			return;
		}
		p = p2 + s.length;
	}
	utest.Assert.isTrue(true,msg,pos);
}
utest.Assert.fail = function(msg,pos) {
	if(msg == null) msg = "failure expected";
	utest.Assert.isTrue(false,msg,pos);
}
utest.Assert.warn = function(msg) {
	utest.Assert.results.add(utest.Assertation.Warning(msg));
}
utest.Assert.createAsync = function(f,timeout) {
	return function() {
	};
}
utest.Assert.createEvent = function(f,timeout) {
	return function(e) {
	};
}
utest.Assert.typeToString = function(t) {
	try {
		var _t = Type.getClass(t);
		if(_t != null) t = _t;
	} catch( e ) {
	}
	try {
		return Type.getClassName(t);
	} catch( e ) {
	}
	try {
		var _t = Type.getEnum(t);
		if(_t != null) t = _t;
	} catch( e ) {
	}
	try {
		return Type.getEnumName(t);
	} catch( e ) {
	}
	try {
		return Std.string(Type["typeof"](t));
	} catch( e ) {
	}
	try {
		return Std.string(t);
	} catch( e ) {
	}
	return "<unable to retrieve type name>";
}
utest.Assert.prototype.__class__ = utest.Assert;
cocktail.port.browser.HTMLInputElement = function(p) {
	if( p === $_ ) return;
	cocktail.core.html.AbstractHTMLInputElement.call(this);
}
cocktail.port.browser.HTMLInputElement.__name__ = ["cocktail","port","browser","HTMLInputElement"];
cocktail.port.browser.HTMLInputElement.__super__ = cocktail.core.html.AbstractHTMLInputElement;
for(var k in cocktail.core.html.AbstractHTMLInputElement.prototype ) cocktail.port.browser.HTMLInputElement.prototype[k] = cocktail.core.html.AbstractHTMLInputElement.prototype[k];
cocktail.port.browser.HTMLInputElement.prototype.set_onChange = function(value) {
	this._nativeElement.removeEventListener("change",$closure(this,"onNativeChange"));
	this._onChange = value;
	if(this._onChange != null) this._nativeElement.addEventListener("change",$closure(this,"onNativeChange"));
	return value;
}
cocktail.port.browser.HTMLInputElement.prototype.onNativeChange = function(event) {
	this.onChangeCallback();
}
cocktail.port.browser.HTMLInputElement.prototype.set_disabled = function(value) {
	this._nativeElement.disabled = value;
	return this._disabled = value;
}
cocktail.port.browser.HTMLInputElement.prototype.set_maxLength = function(value) {
	this._nativeElement.maxLength = value;
	return this._maxLength = value;
}
cocktail.port.browser.HTMLInputElement.prototype.set_value = function(value) {
	this._nativeElement.value = value;
	return this._value = value;
}
cocktail.port.browser.HTMLInputElement.prototype.get_value = function() {
	this._value = this._nativeElement.value;
	return this._value;
}
cocktail.port.browser.HTMLInputElement.prototype.__class__ = cocktail.port.browser.HTMLInputElement;
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktail","core","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
for(var k in cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype ) cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype[k] = cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k];
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingHTMLElementData) {
	this.measureHorizontalPositionOffsets(style,containingHTMLElementData);
	this.measureVerticalPositionOffsets(style,containingHTMLElementData);
}
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measureHorizontalPositionOffsets = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measureVerticalPositionOffsets = function(style,containingHTMLElementData) {
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
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.getComputedStaticLeft = function(style,containingHTMLElementData) {
	return style.getComputedStyle().marginLeft;
}
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.getComputedStaticTop = function(style,containingHTMLElementData) {
	return style.getComputedStyle().marginTop;
}
cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.__class__ = cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
cocktail.port.browser.FontLoader = function(p) {
	if( p === $_ ) return;
	cocktail.core.font.AbstractFontLoader.call(this);
}
cocktail.port.browser.FontLoader.__name__ = ["cocktail","port","browser","FontLoader"];
cocktail.port.browser.FontLoader.__super__ = cocktail.core.font.AbstractFontLoader;
for(var k in cocktail.core.font.AbstractFontLoader.prototype ) cocktail.port.browser.FontLoader.prototype[k] = cocktail.core.font.AbstractFontLoader.prototype[k];
cocktail.port.browser.FontLoader.prototype._styleE = null;
cocktail.port.browser.FontLoader.prototype.load = function(url,name) {
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
cocktail.port.browser.FontLoader.prototype.cleanup = function() {
	cocktail.core.font.AbstractFontLoader.prototype.cleanup.call(this);
}
cocktail.port.browser.FontLoader.prototype.__class__ = cocktail.port.browser.FontLoader;
cocktail.core.mouse.MouseCursorValue = { __ename__ : ["cocktail","core","mouse","MouseCursorValue"], __constructs__ : ["custom","cssAuto","none","native"] }
cocktail.core.mouse.MouseCursorValue.custom = function(htmlImageElement,hotSpot) { var $x = ["custom",0,htmlImageElement,hotSpot]; $x.__enum__ = cocktail.core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.core.mouse.MouseCursorValue.cssAuto = ["cssAuto",1];
cocktail.core.mouse.MouseCursorValue.cssAuto.toString = $estr;
cocktail.core.mouse.MouseCursorValue.cssAuto.__enum__ = cocktail.core.mouse.MouseCursorValue;
cocktail.core.mouse.MouseCursorValue.none = ["none",2];
cocktail.core.mouse.MouseCursorValue.none.toString = $estr;
cocktail.core.mouse.MouseCursorValue.none.__enum__ = cocktail.core.mouse.MouseCursorValue;
cocktail.core.mouse.MouseCursorValue["native"] = function(nativeOSMouseCursorValue) { var $x = ["native",3,nativeOSMouseCursorValue]; $x.__enum__ = cocktail.core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.core.mouse.NativeOSMouseCursorValue = { __ename__ : ["cocktail","core","mouse","NativeOSMouseCursorValue"], __constructs__ : ["pointer","text"] }
cocktail.core.mouse.NativeOSMouseCursorValue.pointer = ["pointer",0];
cocktail.core.mouse.NativeOSMouseCursorValue.pointer.toString = $estr;
cocktail.core.mouse.NativeOSMouseCursorValue.pointer.__enum__ = cocktail.core.mouse.NativeOSMouseCursorValue;
cocktail.core.mouse.NativeOSMouseCursorValue.text = ["text",1];
cocktail.core.mouse.NativeOSMouseCursorValue.text.toString = $estr;
cocktail.core.mouse.NativeOSMouseCursorValue.text.__enum__ = cocktail.core.mouse.NativeOSMouseCursorValue;
cocktail.core.dom.TextTokenValue = { __ename__ : ["cocktail","core","dom","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
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
cocktail.core.dom.FillStyleValue = { __ename__ : ["cocktail","core","dom","FillStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.core.dom.FillStyleValue.none = ["none",0];
cocktail.core.dom.FillStyleValue.none.toString = $estr;
cocktail.core.dom.FillStyleValue.none.__enum__ = cocktail.core.dom.FillStyleValue;
cocktail.core.dom.FillStyleValue.monochrome = function(colorStop) { var $x = ["monochrome",1,colorStop]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.FillStyleValue.gradient = function(gradientStyle) { var $x = ["gradient",2,gradientStyle]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.FillStyleValue.bitmap = function(htmlImageElement,repeat) { var $x = ["bitmap",3,htmlImageElement,repeat]; $x.__enum__ = cocktail.core.dom.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue = { __ename__ : ["cocktail","core","dom","LineStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.core.dom.LineStyleValue.none = ["none",0];
cocktail.core.dom.LineStyleValue.none.toString = $estr;
cocktail.core.dom.LineStyleValue.none.__enum__ = cocktail.core.dom.LineStyleValue;
cocktail.core.dom.LineStyleValue.monochrome = function(color,lineStyle) { var $x = ["monochrome",1,color,lineStyle]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue.gradient = function(gradientStyle,lineStyle) { var $x = ["gradient",2,gradientStyle,lineStyle]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.LineStyleValue.bitmap = function(htmlImageElement,lineStyle,repeat) { var $x = ["bitmap",3,htmlImageElement,lineStyle,repeat]; $x.__enum__ = cocktail.core.dom.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.core.dom.GradientTypeValue = { __ename__ : ["cocktail","core","dom","GradientTypeValue"], __constructs__ : ["linear","radial"] }
cocktail.core.dom.GradientTypeValue.linear = ["linear",0];
cocktail.core.dom.GradientTypeValue.linear.toString = $estr;
cocktail.core.dom.GradientTypeValue.linear.__enum__ = cocktail.core.dom.GradientTypeValue;
cocktail.core.dom.GradientTypeValue.radial = ["radial",1];
cocktail.core.dom.GradientTypeValue.radial.toString = $estr;
cocktail.core.dom.GradientTypeValue.radial.__enum__ = cocktail.core.dom.GradientTypeValue;
cocktail.core.dom.CapsStyleValue = { __ename__ : ["cocktail","core","dom","CapsStyleValue"], __constructs__ : ["none","square","round"] }
cocktail.core.dom.CapsStyleValue.none = ["none",0];
cocktail.core.dom.CapsStyleValue.none.toString = $estr;
cocktail.core.dom.CapsStyleValue.none.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.CapsStyleValue.square = ["square",1];
cocktail.core.dom.CapsStyleValue.square.toString = $estr;
cocktail.core.dom.CapsStyleValue.square.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.CapsStyleValue.round = ["round",2];
cocktail.core.dom.CapsStyleValue.round.toString = $estr;
cocktail.core.dom.CapsStyleValue.round.__enum__ = cocktail.core.dom.CapsStyleValue;
cocktail.core.dom.JointStyleValue = { __ename__ : ["cocktail","core","dom","JointStyleValue"], __constructs__ : ["miter","round","bevel"] }
cocktail.core.dom.JointStyleValue.miter = ["miter",0];
cocktail.core.dom.JointStyleValue.miter.toString = $estr;
cocktail.core.dom.JointStyleValue.miter.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.core.dom.JointStyleValue.round = ["round",1];
cocktail.core.dom.JointStyleValue.round.toString = $estr;
cocktail.core.dom.JointStyleValue.round.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.core.dom.JointStyleValue.bevel = ["bevel",2];
cocktail.core.dom.JointStyleValue.bevel.toString = $estr;
cocktail.core.dom.JointStyleValue.bevel.__enum__ = cocktail.core.dom.JointStyleValue;
cocktail.port.browser.Keyboard = function(htmlElement) {
	if( htmlElement === $_ ) return;
	cocktail.core.keyboard.AbstractKeyboard.call(this,htmlElement);
	this._keyDownEvent = "keydown";
	this._keyUpEvent = "keyup";
}
cocktail.port.browser.Keyboard.__name__ = ["cocktail","port","browser","Keyboard"];
cocktail.port.browser.Keyboard.__super__ = cocktail.core.keyboard.AbstractKeyboard;
for(var k in cocktail.core.keyboard.AbstractKeyboard.prototype ) cocktail.port.browser.Keyboard.prototype[k] = cocktail.core.keyboard.AbstractKeyboard.prototype[k];
cocktail.port.browser.Keyboard.prototype.updateListeners = function(keyboardEvent,nativeCallback,htmlElementCallback) {
	this._htmlElement.get_nativeElement().removeEventListener(keyboardEvent,nativeCallback);
	if(htmlElementCallback != null) this._htmlElement.get_nativeElement().addEventListener(keyboardEvent,nativeCallback);
}
cocktail.port.browser.Keyboard.prototype.getKeyData = function(event) {
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
cocktail.port.browser.Keyboard.prototype.__class__ = cocktail.port.browser.Keyboard;
cocktail.core.background.BackgroundDrawingManager = function(nativeElement,backgroundBox) {
	if( nativeElement === $_ ) return;
	cocktail.port.browser.DrawingManager.call(this,nativeElement,Math.round(backgroundBox.width),Math.round(backgroundBox.height));
}
cocktail.core.background.BackgroundDrawingManager.__name__ = ["cocktail","core","background","BackgroundDrawingManager"];
cocktail.core.background.BackgroundDrawingManager.__super__ = cocktail.port.browser.DrawingManager;
for(var k in cocktail.port.browser.DrawingManager.prototype ) cocktail.core.background.BackgroundDrawingManager.prototype[k] = cocktail.port.browser.DrawingManager.prototype[k];
cocktail.core.background.BackgroundDrawingManager.prototype.drawBackgroundImage = function(nativeImage,backgroundPositioningBox,backgroundPaintingBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
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
cocktail.core.background.BackgroundDrawingManager.prototype.drawBackgroundColor = function(color,backgroundPaintingBox) {
	var fillStyle = cocktail.core.dom.FillStyleValue.monochrome(color);
	var lineStyle = cocktail.core.dom.LineStyleValue.none;
	this.beginFill(fillStyle,lineStyle);
	this.drawRect(Math.round(backgroundPaintingBox.x),Math.round(backgroundPaintingBox.y),Math.round(backgroundPaintingBox.width),Math.round(backgroundPaintingBox.height));
	this.endFill();
}
cocktail.core.background.BackgroundDrawingManager.prototype.drawBackgroundGradient = function(gradient,backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
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
cocktail.core.background.BackgroundDrawingManager.prototype.getGradientStops = function(value) {
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
cocktail.core.background.BackgroundDrawingManager.prototype.getRotation = function(value) {
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
cocktail.core.background.BackgroundDrawingManager.prototype.__class__ = cocktail.core.background.BackgroundDrawingManager;
cocktail.port.browser.MouseCursor = function(p) {
	if( p === $_ ) return;
	cocktail.core.mouse.AbstractMouseCursor.call(this);
}
cocktail.port.browser.MouseCursor.__name__ = ["cocktail","port","browser","MouseCursor"];
cocktail.port.browser.MouseCursor.__super__ = cocktail.core.mouse.AbstractMouseCursor;
for(var k in cocktail.core.mouse.AbstractMouseCursor.prototype ) cocktail.port.browser.MouseCursor.prototype[k] = cocktail.core.mouse.AbstractMouseCursor.prototype[k];
cocktail.port.browser.MouseCursor.prototype.setBitmapCursor = function(imageHTMLElement,hotSpot) {
	var cursorURL = imageHTMLElement.get_nativeElement().src;
	if(hotSpot == null) hotSpot = { x : 0.0, y : 0.0};
	this.setCursorStyle("url(" + cursorURL + ") " + hotSpot.x + " " + hotSpot.y + ", auto");
}
cocktail.port.browser.MouseCursor.prototype.hideCursor = function() {
	this.setCursorStyle("none");
}
cocktail.port.browser.MouseCursor.prototype.setDefaultCursor = function() {
	this.setCursorStyle("auto");
}
cocktail.port.browser.MouseCursor.prototype.setNativeOSCursor = function(value) {
	switch( (value)[1] ) {
	case 0:
		this.setCursorStyle("pointer");
		break;
	case 1:
		this.setCursorStyle("text");
		break;
	}
}
cocktail.port.browser.MouseCursor.prototype.setCursorStyle = function(style) {
	js.Lib.document.body.style.cursor = style;
}
cocktail.port.browser.MouseCursor.prototype.__class__ = cocktail.port.browser.MouseCursor;
EReg = function(r,opt) {
	if( r === $_ ) return;
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
}
EReg.__name__ = ["EReg"];
EReg.prototype.r = null;
EReg.prototype.match = function(s) {
	this.r.m = this.r.exec(s);
	this.r.s = s;
	this.r.l = RegExp.leftContext;
	this.r.r = RegExp.rightContext;
	return this.r.m != null;
}
EReg.prototype.matched = function(n) {
	return this.r.m != null && n >= 0 && n < this.r.m.length?this.r.m[n]:(function($this) {
		var $r;
		throw "EReg::matched";
		return $r;
	}(this));
}
EReg.prototype.matchedLeft = function() {
	if(this.r.m == null) throw "No string matched";
	if(this.r.l == null) return this.r.s.substr(0,this.r.m.index);
	return this.r.l;
}
EReg.prototype.matchedRight = function() {
	if(this.r.m == null) throw "No string matched";
	if(this.r.r == null) {
		var sz = this.r.m.index + this.r.m[0].length;
		return this.r.s.substr(sz,this.r.s.length - sz);
	}
	return this.r.r;
}
EReg.prototype.matchedPos = function() {
	if(this.r.m == null) throw "No string matched";
	return { pos : this.r.m.index, len : this.r.m[0].length};
}
EReg.prototype.split = function(s) {
	var d = "#__delim__#";
	return s.replace(this.r,d).split(d);
}
EReg.prototype.replace = function(s,by) {
	return s.replace(this.r,by);
}
EReg.prototype.customReplace = function(s,f) {
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
EReg.prototype.__class__ = EReg;
cocktail.core.unit.Length = { __ename__ : ["cocktail","core","unit","Length"], __constructs__ : ["px","cm","mm","pt","pc","cssIn","em","ex"] }
cocktail.core.unit.Length.px = function(value) { var $x = ["px",0,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.cm = function(value) { var $x = ["cm",1,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.mm = function(value) { var $x = ["mm",2,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.pt = function(value) { var $x = ["pt",3,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.pc = function(value) { var $x = ["pc",4,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.cssIn = function(value) { var $x = ["cssIn",5,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.em = function(value) { var $x = ["em",6,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.Length.ex = function(value) { var $x = ["ex",7,value]; $x.__enum__ = cocktail.core.unit.Length; $x.toString = $estr; return $x; }
cocktail.core.unit.FontSizeAbsoluteSize = { __ename__ : ["cocktail","core","unit","FontSizeAbsoluteSize"], __constructs__ : ["xxSmall","xSmall","small","medium","large","xLarge","xxLarge"] }
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
cocktail.core.unit.FontSizeRelativeSize = { __ename__ : ["cocktail","core","unit","FontSizeRelativeSize"], __constructs__ : ["larger","smaller"] }
cocktail.core.unit.FontSizeRelativeSize.larger = ["larger",0];
cocktail.core.unit.FontSizeRelativeSize.larger.toString = $estr;
cocktail.core.unit.FontSizeRelativeSize.larger.__enum__ = cocktail.core.unit.FontSizeRelativeSize;
cocktail.core.unit.FontSizeRelativeSize.smaller = ["smaller",1];
cocktail.core.unit.FontSizeRelativeSize.smaller.toString = $estr;
cocktail.core.unit.FontSizeRelativeSize.smaller.__enum__ = cocktail.core.unit.FontSizeRelativeSize;
cocktail.core.unit.CSSColor = { __ename__ : ["cocktail","core","unit","CSSColor"], __constructs__ : ["rgb","rgba","hex","keyword","transparent"] }
cocktail.core.unit.CSSColor.rgb = function(red,green,blue) { var $x = ["rgb",0,red,green,blue]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.rgba = function(red,green,blue,alpha) { var $x = ["rgba",1,red,green,blue,alpha]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.hex = function(value) { var $x = ["hex",2,value]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.keyword = function(value) { var $x = ["keyword",3,value]; $x.__enum__ = cocktail.core.unit.CSSColor; $x.toString = $estr; return $x; }
cocktail.core.unit.CSSColor.transparent = ["transparent",4];
cocktail.core.unit.CSSColor.transparent.toString = $estr;
cocktail.core.unit.CSSColor.transparent.__enum__ = cocktail.core.unit.CSSColor;
cocktail.core.unit.ImageValue = { __ename__ : ["cocktail","core","unit","ImageValue"], __constructs__ : ["url","imageList","gradient"] }
cocktail.core.unit.ImageValue.url = function(value) { var $x = ["url",0,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.ImageValue.imageList = function(value) { var $x = ["imageList",1,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.ImageValue.gradient = function(value) { var $x = ["gradient",2,value]; $x.__enum__ = cocktail.core.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientValue = { __ename__ : ["cocktail","core","unit","GradientValue"], __constructs__ : ["linear"] }
cocktail.core.unit.GradientValue.linear = function(value) { var $x = ["linear",0,value]; $x.__enum__ = cocktail.core.unit.GradientValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientStopValue = { __ename__ : ["cocktail","core","unit","GradientStopValue"], __constructs__ : ["length","percent"] }
cocktail.core.unit.GradientStopValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.core.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientStopValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.core.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle = { __ename__ : ["cocktail","core","unit","GradientAngle"], __constructs__ : ["angle","side","corner"] }
cocktail.core.unit.GradientAngle.angle = function(value) { var $x = ["angle",0,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle.side = function(value) { var $x = ["side",1,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientAngle.corner = function(value) { var $x = ["corner",2,value]; $x.__enum__ = cocktail.core.unit.GradientAngle; $x.toString = $estr; return $x; }
cocktail.core.unit.GradientSideValue = { __ename__ : ["cocktail","core","unit","GradientSideValue"], __constructs__ : ["top","left","bottom","right"] }
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
cocktail.core.unit.GradientCornerValue = { __ename__ : ["cocktail","core","unit","GradientCornerValue"], __constructs__ : ["topRight","bottomRight","bottomLeft","topLeft"] }
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
cocktail.core.unit.ColorKeyword = { __ename__ : ["cocktail","core","unit","ColorKeyword"], __constructs__ : ["aqua","black","blue","fuchsia","gray","green","lime","maroon","navy","olive","orange","purple","red","silver","teal","white","yellow"] }
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
cocktail.core.unit.Angle = { __ename__ : ["cocktail","core","unit","Angle"], __constructs__ : ["deg","grad","rad","turn"] }
cocktail.core.unit.Angle.deg = function(value) { var $x = ["deg",0,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.grad = function(value) { var $x = ["grad",1,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.rad = function(value) { var $x = ["rad",2,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
cocktail.core.unit.Angle.turn = function(value) { var $x = ["turn",3,value]; $x.__enum__ = cocktail.core.unit.Angle; $x.toString = $estr; return $x; }
utest.ui.common.FixtureResult = function(methodName) {
	if( methodName === $_ ) return;
	this.methodName = methodName;
	this.list = new List();
	this.hasTestError = false;
	this.hasSetupError = false;
	this.hasTeardownError = false;
	this.hasTimeoutError = false;
	this.hasAsyncError = false;
	this.stats = new utest.ui.common.ResultStats();
}
utest.ui.common.FixtureResult.__name__ = ["utest","ui","common","FixtureResult"];
utest.ui.common.FixtureResult.prototype.methodName = null;
utest.ui.common.FixtureResult.prototype.hasTestError = null;
utest.ui.common.FixtureResult.prototype.hasSetupError = null;
utest.ui.common.FixtureResult.prototype.hasTeardownError = null;
utest.ui.common.FixtureResult.prototype.hasTimeoutError = null;
utest.ui.common.FixtureResult.prototype.hasAsyncError = null;
utest.ui.common.FixtureResult.prototype.stats = null;
utest.ui.common.FixtureResult.prototype.list = null;
utest.ui.common.FixtureResult.prototype.iterator = function() {
	return this.list.iterator();
}
utest.ui.common.FixtureResult.prototype.add = function(assertation) {
	this.list.add(assertation);
	switch( (assertation)[1] ) {
	case 0:
		this.stats.addSuccesses(1);
		break;
	case 1:
		this.stats.addFailures(1);
		break;
	case 2:
		this.stats.addErrors(1);
		break;
	case 3:
		this.stats.addErrors(1);
		this.hasSetupError = true;
		break;
	case 4:
		this.stats.addErrors(1);
		this.hasTeardownError = true;
		break;
	case 5:
		this.stats.addErrors(1);
		this.hasTimeoutError = true;
		break;
	case 6:
		this.stats.addErrors(1);
		this.hasAsyncError = true;
		break;
	case 7:
		this.stats.addWarnings(1);
		break;
	}
}
utest.ui.common.FixtureResult.prototype.__class__ = utest.ui.common.FixtureResult;
$_ = {}
js.Boot.__res = {}
js.Boot.__init();
{
	js.Lib.document = document;
	js.Lib.window = window;
	onerror = function(msg,url,line) {
		var f = js.Lib.onerror;
		if( f == null )
			return false;
		return f(msg,[url+":"+line]);
	}
}
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
	d.prototype.__class__ = d;
	d.__name__ = ["Date"];
}
{
	Math.__name__ = ["Math"];
	Math.NaN = Number["NaN"];
	Math.NEGATIVE_INFINITY = Number["NEGATIVE_INFINITY"];
	Math.POSITIVE_INFINITY = Number["POSITIVE_INFINITY"];
	Math.isFinite = function(i) {
		return isFinite(i);
	};
	Math.isNaN = function(i) {
		return isNaN(i);
	};
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
if(typeof(haxe_timers) == "undefined") haxe_timers = [];
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
cocktail.core.html.AbstractHTMLElement.HTML_ID_ATTRIBUTE = "id";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_BLANK = "_blank";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_SELF = "_self";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_PARENT = "_parent";
cocktail.core.html.AbstractHTMLAnchorElement.TARGET_TOP = "_top";
cocktail.core.html.AbstractHTMLAnchorElement.HTML_ANCHOR_TAG_NAME = "a";
cocktail.core.html.HTMLDocument.HTML_IMAGE_ELEMENT_TAG_NAME = "img";
cocktail.core.html.HTMLDocument.HTML_CANVAS_ELEMENT_TAG_NAME = "canvas";
cocktail.core.html.HTMLDocument.HTML_INPUT_ELEMENT_TAG_NAME = "input";
cocktail.core.html.HTMLDocument.HTML_ANCHOR_ELEMENT_TAG_NAME = "a";
cocktail.core.html.HTMLDocument.HTML_HTML_TAG_NAME = "html";
cocktail.core.event.Event.SCROLL = "scroll";
cocktail.core.event.Event.LOAD = "load";
cocktail.core.event.Event.FOCUS = "focus";
cocktail.core.event.Event.BLUR = "blur";
cocktail.core.event.Event.ERROR = "error";
cocktail.core.event.Event.READY_STATE_CHANGE = "readystatechange";
cocktail.core.event.Event.RESIZE = "resize";
cocktail.core.event.KeyboardEvent.KEY_DOWN = "keydown";
cocktail.core.event.KeyboardEvent.KEY_UP = "keyup";
cocktail.core.html.AbstractHTMLImageElement.HTML_IMAGE_TAG_NAME = "img";
cocktail.core.html.AbstractHTMLHtmlElement.HTML_HTML_TAG_NAME = "html";
utest.ui.text.HtmlReport.platform = "javascript";
js.Lib.onerror = null;
cocktail.core.html.AbstractHTMLInputElement.HTML_INPUT_TAG_NAME = "input";
cocktail.core.html.HTMLBodyElement.HTML_BODY_TAG_NAME = "body";
cocktail.core.event.MouseEvent.CLICK = "click";
cocktail.core.event.MouseEvent.MOUSE_UP = "mouseup";
cocktail.core.event.MouseEvent.MOUSE_DOWN = "mousedown";
cocktail.core.event.MouseEvent.MOUSE_OVER = "mouseover";
cocktail.core.event.MouseEvent.MOUSE_OUT = "mouseout";
cocktail.core.event.MouseEvent.MOUSE_MOVE = "mousemove";
cocktail.port.browser.Mouse.MOUSE_CLICK_EVENT = "click";
cocktail.port.browser.Mouse.MOUSE_UP_EVENT = "mouseup";
cocktail.port.browser.Mouse.MOUSE_DOWN_EVENT = "mousedown";
cocktail.port.browser.Mouse.MOUSE_OVER_EVENT = "mouseover";
cocktail.port.browser.Mouse.MOUSE_OUT_EVENT = "mouseout";
cocktail.port.browser.Mouse.MOUSE_MOVE_EVENT = "mousemove";
cocktail.core.resource.XMLHTTPRequest.READY_STATE_UNSENT = 0;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_OPENED = 1;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_HEADERS_RECEIVED = 2;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_LOADING = 3;
cocktail.core.resource.XMLHTTPRequest.READY_STATE_DONE = 4;
cocktail.core.html.HTMLCanvasElement.CANVAS_INTRINSIC_HEIGHT = 150;
cocktail.core.html.HTMLCanvasElement.CANVAS_INTRINSIC_WIDTH = 300;
cocktail.core.html.HTMLCanvasElement.HTML_CANVAS_TAG_NAME = "canvas";
cocktail.core.html.HTMLCanvasElement.CANVAS_2D_CONTEXT = "2d";
utest.TestHandler.POLLING_TIME = 10;
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_NONE = "butt";
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_ROUND = "round";
cocktail.port.browser.DrawingManager.CAPS_STYLE_VALUE_SQUARE = "square";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_ROUND = "round";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_MITER = "miter";
cocktail.port.browser.DrawingManager.JOINT_STYLE_VALUE_BEVEL = "bevel";
cocktail.port.browser.DrawingManager.CANVAS_PATTERN_REPEAT = "repeat";
cocktail.port.browser.DrawingManager.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
cocktail.core.keyboard.AbstractKeyboard.TAB = 9;
cocktail.core.keyboard.AbstractKeyboard.ENTER = 13;
cocktail.core.keyboard.AbstractKeyboard.SPACE = 32;
cocktail.port.browser.Keyboard.KEY_DOWN_EVENT = "keydown";
cocktail.port.browser.Keyboard.KEY_UP_EVENT = "keyup";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_NONE = "none";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_POINTER = "pointer";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_TEXT = "text";
cocktail.port.browser.MouseCursor.MOUSE_CURSOR_STYLE_AUTO = "auto";
UnitManagerTests.main()