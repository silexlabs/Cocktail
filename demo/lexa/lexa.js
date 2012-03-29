var $_, $hxClasses = $hxClasses || {}, $estr = function() { return js.Boot.__string_rec(this,''); }
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var core = core || {}
if(!core.nativeElement) core.nativeElement = {}
core.nativeElement.NativeElementManager = $hxClasses["core.nativeElement.NativeElementManager"] = function() {
}
core.nativeElement.NativeElementManager.__name__ = ["core","nativeElement","NativeElementManager"];
core.nativeElement.NativeElementManager._nativeElementCreator = null;
core.nativeElement.NativeElementManager._nativeElementPathManager = null;
core.nativeElement.NativeElementManager.getRoot = function() {
	if(core.nativeElement.NativeElementManager._nativeElementPathManager == null) core.nativeElement.NativeElementManager._nativeElementPathManager = new port.browser.NativeElementPathManager();
	return core.nativeElement.NativeElementManager._nativeElementPathManager.getRoot();
}
core.nativeElement.NativeElementManager.createNativeElement = function(nativeElementType) {
	if(core.nativeElement.NativeElementManager._nativeElementCreator == null) core.nativeElement.NativeElementManager._nativeElementCreator = new port.browser.NativeElementCreator();
	return core.nativeElement.NativeElementManager._nativeElementCreator.createNativeElement(nativeElementType);
}
core.nativeElement.NativeElementManager.prototype = {
	__class__: core.nativeElement.NativeElementManager
}
if(!core.dom) core.dom = {}
core.dom.Node = $hxClasses["core.dom.Node"] = function() {
	this._childNodes = new Array();
}
core.dom.Node.__name__ = ["core","dom","Node"];
core.dom.Node.prototype = {
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
	,hasChildNodes: null
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
		if(newChild.get_parentNode() != null) {
			var parentNode = newChild.get_parentNode();
			parentNode.removeChild(newChild);
		}
		newChild.set_parentNode(this);
		this._childNodes.push(newChild);
		return newChild;
	}
	,get_firstChild: function() {
		if(this.get_hasChildNodes() == true) return this._childNodes[0]; else return null;
	}
	,get_lastChild: function() {
		if(this.get_hasChildNodes() == true) return this._childNodes[this._childNodes.length - 1]; else return null;
	}
	,get_nextSibling: function() {
		if(this._parentNode == null) return null; else if(this._parentNode.get_lastChild() != this) {
			var _g1 = 0, _g = this._parentNode.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._parentNode.get_childNodes()[i] == this) return this._parentNode.get_childNodes()[i + 1];
			}
		}
		return null;
	}
	,get_previousSibling: function() {
		if(this._parentNode == null) return null; else if(this._parentNode.get_firstChild() != this) {
			var _g1 = 0, _g = this._parentNode.get_childNodes().length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._parentNode.get_childNodes()[i] == this) return this._parentNode.get_childNodes()[i - 1];
			}
		}
		return null;
	}
	,get_hasChildNodes: function() {
		return this._childNodes.length > 0;
	}
	,get_nodeType: function() {
		return null;
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
	,__class__: core.dom.Node
	,__properties__: {get_hasChildNodes:"get_hasChildNodes",get_previousSibling:"get_previousSibling",get_nextSibling:"get_nextSibling",get_lastChild:"get_lastChild",get_firstChild:"get_firstChild",get_childNodes:"get_childNodes",set_parentNode:"set_parentNode",get_parentNode:"get_parentNode",get_nodeName:"get_nodeName",set_nodeValue:"set_nodeValue",get_nodeValue:"get_nodeValue",get_nodeType:"get_nodeType"}
}
core.dom.Element = $hxClasses["core.dom.Element"] = function(tagName) {
	this._tagName = tagName;
	core.dom.Node.call(this);
}
core.dom.Element.__name__ = ["core","dom","Element"];
core.dom.Element.__super__ = core.dom.Node;
core.dom.Element.prototype = $extend(core.dom.Node.prototype,{
	_tagName: null
	,tagName: null
	,get_nodeName: function() {
		return this._tagName;
	}
	,get_nodeType: function() {
		return core.dom.NodeType.ELEMENT_NODE;
	}
	,get_tagName: function() {
		return this._tagName;
	}
	,__class__: core.dom.Element
	,__properties__: $extend(core.dom.Node.prototype.__properties__,{get_tagName:"get_tagName"})
});
if(!core.event) core.event = {}
core.event.IEventTarget = $hxClasses["core.event.IEventTarget"] = function() { }
core.event.IEventTarget.__name__ = ["core","event","IEventTarget"];
core.event.IEventTarget.prototype = {
	__class__: core.event.IEventTarget
}
if(!core.html) core.html = {}
core.html.AbstractHTMLElement = $hxClasses["core.html.AbstractHTMLElement"] = function(tagName) {
	core.dom.Element.call(this,tagName);
	this.init();
}
core.html.AbstractHTMLElement.__name__ = ["core","html","AbstractHTMLElement"];
core.html.AbstractHTMLElement.__interfaces__ = [core.event.IEventTarget];
core.html.AbstractHTMLElement.__super__ = core.dom.Element;
core.html.AbstractHTMLElement.prototype = $extend(core.dom.Element.prototype,{
	_mouse: null
	,_onClick: null
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
	,_keyboard: null
	,_onKeyDown: null
	,onKeyDown: null
	,_onKeyUp: null
	,onKeyUp: null
	,_tabIndex: null
	,tabIndex: null
	,isDefaultFocusable: null
	,_onFocus: null
	,onFocus: null
	,_onBlur: null
	,onBlur: null
	,_onScroll: null
	,onScroll: null
	,scrollTop: null
	,scrollLeft: null
	,scrollHeight: null
	,scrollWidth: null
	,_nativeElement: null
	,nativeElement: null
	,offsetParent: null
	,offsetWidth: null
	,offsetHeight: null
	,offsetLeft: null
	,offsetTop: null
	,clientWidth: null
	,clientHeight: null
	,clientLeft: null
	,clientTop: null
	,_style: null
	,style: null
	,init: function() {
		this.initNativeElement();
		this.initMouse();
		this.initKeyboard();
		this.initStyle();
	}
	,initNativeElement: function() {
		this._nativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.custom(this._tagName));
	}
	,initMouse: function() {
		this._mouse = new port.browser.Mouse(this);
	}
	,initKeyboard: function() {
		this._keyboard = new port.browser.Keyboard(this);
	}
	,initStyle: function() {
		this._style = new core.style.AbstractContainerStyle(this);
	}
	,appendChild: function(newChild) {
		core.dom.Element.prototype.appendChild.call(this,newChild);
		this._style.invalidate();
		return newChild;
	}
	,removeChild: function(oldChild) {
		core.dom.Element.prototype.removeChild.call(this,oldChild);
		this._style.invalidate();
		return oldChild;
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
	,focus: function() {
		cocktailCore.focus.FocusManager.getInstance().setActiveElement(this);
	}
	,blur: function() {
		cocktailCore.focus.FocusManager.getInstance().setActiveElement(null);
	}
	,get_isDefaultFocusable: function() {
		return false;
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
		cocktailCore.focus.FocusManager.getInstance().invalidate();
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
	,get_offsetParent: function() {
		return this._style.getFirstPositionedAncestor();
	}
	,get_offsetWidth: function() {
		var computedStyle = this._style.getComputedStyle();
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	,get_offsetHeight: function() {
		var computedStyle = this._style.getComputedStyle();
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	,get_offsetLeft: function() {
		var firstPositionedAncestor = this.get_offsetParent();
		var offsetLeft = 0;
		if(firstPositionedAncestor != null) {
			var parent = this.get_parentNode();
			while(parent != firstPositionedAncestor) {
				offsetLeft += parent.get_style().getComputedStyle().paddingLeft + parent.get_style().getComputedStyle().marginLeft;
				parent = parent.get_parentNode();
			}
		}
		return offsetLeft;
	}
	,get_offsetTop: function() {
		var firstPositionedAncestor = this.get_offsetParent();
		var offsetTop = 0;
		if(firstPositionedAncestor != null) {
			var parent = this.get_parentNode();
			while(parent != firstPositionedAncestor) {
				offsetTop += parent.get_style().getComputedStyle().paddingTop + parent.get_style().getComputedStyle().marginTop;
				parent = parent.get_parentNode();
			}
		}
		return offsetTop;
	}
	,get_clientWidth: function() {
		return this._style.getComputedStyle().width;
	}
	,get_clientHeight: function() {
		return this._style.getComputedStyle().height;
	}
	,get_clientTop: function() {
		return this._style.getComputedStyle().paddingTop;
	}
	,get_clientLeft: function() {
		return this._style.getComputedStyle().paddingLeft;
	}
	,get_style: function() {
		return this._style;
	}
	,__class__: core.html.AbstractHTMLElement
	,__properties__: $extend(core.dom.Element.prototype.__properties__,{get_style:"get_style",get_clientTop:"get_clientTop",get_clientLeft:"get_clientLeft",get_clientHeight:"get_clientHeight",get_clientWidth:"get_clientWidth",get_offsetTop:"get_offsetTop",get_offsetLeft:"get_offsetLeft",get_offsetHeight:"get_offsetHeight",get_offsetWidth:"get_offsetWidth",get_offsetParent:"get_offsetParent",get_nativeElement:"get_nativeElement",get_scrollWidth:"get_scrollWidth",get_scrollHeight:"get_scrollHeight",set_scrollLeft:"set_scrollLeft",get_scrollLeft:"get_scrollLeft",set_scrollTop:"set_scrollTop",get_scrollTop:"get_scrollTop",set_onScroll:"set_onScroll",get_onScroll:"get_onScroll",set_onBlur:"set_onBlur",get_onBlur:"get_onBlur",set_onFocus:"set_onFocus",get_onFocus:"get_onFocus",get_isDefaultFocusable:"get_isDefaultFocusable",set_tabIndex:"set_tabIndex",get_tabIndex:"get_tabIndex",set_onKeyUp:"set_onKeyUp",get_onKeyUp:"get_onKeyUp",set_onKeyDown:"set_onKeyDown",get_onKeyDown:"get_onKeyDown",set_onMouseMove:"set_onMouseMove",get_onMouseMove:"get_onMouseMove",set_onMouseOut:"set_onMouseOut",get_onMouseOut:"get_onMouseOut",set_onMouseOver:"set_onMouseOver",get_onMouseOver:"get_onMouseOver",set_onMouseUp:"set_onMouseUp",get_onMouseUp:"get_onMouseUp",set_onMouseDown:"set_onMouseDown",get_onMouseDown:"get_onMouseDown",set_onClick:"set_onClick",get_onClick:"get_onClick"})
});
var port = port || {}
if(!port.browser) port.browser = {}
port.browser.HTMLElement = $hxClasses["port.browser.HTMLElement"] = function(tagName) {
	core.html.AbstractHTMLElement.call(this,tagName);
}
port.browser.HTMLElement.__name__ = ["port","browser","HTMLElement"];
port.browser.HTMLElement.__super__ = core.html.AbstractHTMLElement;
port.browser.HTMLElement.prototype = $extend(core.html.AbstractHTMLElement.prototype,{
	removeChild: function(oldChild) {
		core.html.AbstractHTMLElement.prototype.removeChild.call(this,oldChild);
		switch( (oldChild.get_nodeType())[1] ) {
		case 0:
			var childHTMLElement = oldChild;
			this._nativeElement.removeChild(childHTMLElement.get_nativeElement());
			break;
		case 1:
			var childTextElement = oldChild;
			this._nativeElement.removeChild(childTextElement.get_nativeElement());
			break;
		case 2:
			break;
		}
		return oldChild;
	}
	,appendChild: function(newChild) {
		core.html.AbstractHTMLElement.prototype.appendChild.call(this,newChild);
		switch( (newChild.get_nodeType())[1] ) {
		case 0:
			var childHTMLElement = newChild;
			this._nativeElement.appendChild(childHTMLElement.get_nativeElement());
			break;
		case 1:
			var childTextElement = newChild;
			this._nativeElement.appendChild(childTextElement.get_nativeElement());
			break;
		case 2:
			break;
		}
		return newChild;
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
		core.html.AbstractHTMLElement.prototype.set_tabIndex.call(this,value);
		this._nativeElement.tabIndex = value;
		return this._tabIndex;
	}
	,focus: function() {
		this._nativeElement.focus();
	}
	,blur: function() {
		this._nativeElement.blur();
	}
	,onNativeFocus: function(event) {
		if(this.get_onFocus() != null) (this.get_onFocus())(new core.event.Event("focus",this));
	}
	,onNativeBlur: function(event) {
		if(this.get_onBlur() != null) (this.get_onBlur())(new core.event.Event("blur",this));
	}
	,set_onScroll: function(value) {
		this._nativeElement.removeEventListener("scroll",this.onNativeScroll.$bind(this));
		this._onScroll = value;
		if(this._onScroll != null) this._nativeElement.addEventListener("scroll",this.onNativeScroll.$bind(this));
		return value;
	}
	,onNativeScroll: function(event) {
		this.onScrollCallback(new core.event.Event("scroll",this));
	}
	,__class__: port.browser.HTMLElement
});
core.html.AbstractHTMLInputElement = $hxClasses["core.html.AbstractHTMLInputElement"] = function() {
	port.browser.HTMLElement.call(this,"input");
}
core.html.AbstractHTMLInputElement.__name__ = ["core","html","AbstractHTMLInputElement"];
core.html.AbstractHTMLInputElement.__super__ = port.browser.HTMLElement;
core.html.AbstractHTMLInputElement.prototype = $extend(port.browser.HTMLElement.prototype,{
	_onChange: null
	,onChange: null
	,_disabled: null
	,disabled: null
	,_maxLength: null
	,maxLength: null
	,_value: null
	,value: null
	,init: function() {
		port.browser.HTMLElement.prototype.init.call(this);
		this._disabled = false;
		this._value = "";
	}
	,initStyle: function() {
		this._style = new core.style.AbstractEmbeddedStyle(this);
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
	,__class__: core.html.AbstractHTMLInputElement
	,__properties__: $extend(port.browser.HTMLElement.prototype.__properties__,{set_value:"set_value",get_value:"get_value",set_maxLength:"set_maxLength",get_maxLength:"get_maxLength",set_disabled:"set_disabled",get_disabled:"get_disabled",set_onChange:"set_onChange",get_onChange:"get_onChange"})
});
port.browser.HTMLInputElement = $hxClasses["port.browser.HTMLInputElement"] = function() {
	core.html.AbstractHTMLInputElement.call(this);
}
port.browser.HTMLInputElement.__name__ = ["port","browser","HTMLInputElement"];
port.browser.HTMLInputElement.__super__ = core.html.AbstractHTMLInputElement;
port.browser.HTMLInputElement.prototype = $extend(core.html.AbstractHTMLInputElement.prototype,{
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
	,__class__: port.browser.HTMLInputElement
});
if(!core.style) core.style = {}
if(!core.style.formatter) core.style.formatter = {}
core.style.formatter.FormattingContext = $hxClasses["core.style.formatter.FormattingContext"] = function(formattingContextRoot) {
	this._formattingContextRoot = formattingContextRoot;
	this._floatsManager = new core.style.floats.FloatsManager();
	this.initFormattingContextData();
	this._elementsInFormattingContext = new Array();
}
core.style.formatter.FormattingContext.__name__ = ["core","style","formatter","FormattingContext"];
core.style.formatter.FormattingContext.prototype = {
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
					var htmlElementAscent = elements[i].getStyle().getFontMetricsData().ascent;
					var htmlElementDescent = elements[i].getStyle().getFontMetricsData().descent;
					var leading = elements[i].getStyle().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
					htmlElementAscent = Math.round(htmlElementAscent + leading / 2);
					htmlElementDescent = Math.round(htmlElementDescent + leading / 2);
					top = elements[i].getBounds().y - htmlElementAscent;
				}
			}
			if(elements[i].getBounds().x + elements[i].getBounds().width > right) right = elements[i].getBounds().x + elements[i].getBounds().width;
			if(elements[i].getBounds().y + elements[i].getBounds().height > bottom) {
				if(elements[i].isText() == false) bottom = elements[i].getBounds().y + elements[i].getBounds().height; else {
					var htmlElementAscent = elements[i].getStyle().getFontMetricsData().ascent;
					var htmlElementDescent = elements[i].getStyle().getFontMetricsData().descent;
					var leading = elements[i].getStyle().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
					htmlElementAscent = Math.round(htmlElementAscent + leading / 2);
					htmlElementDescent = Math.round(htmlElementDescent + leading / 2);
					bottom = elements[i].getBounds().y - htmlElementAscent + elements[i].getBounds().height;
				}
			}
		}
		bounds = { x : left, y : top, width : right - left, height : bottom - top};
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
			if(element.getStyle().establishesNewFormattingContext() == true) this.insertFormattingContextRootElement(element); else this.insertContainerElement(element);
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
	,__class__: core.style.formatter.FormattingContext
	,__properties__: {get_maxWidth:"getMaxWidth"}
}
core.style.formatter.InlineFormattingContext = $hxClasses["core.style.formatter.InlineFormattingContext"] = function(formattingContextRoot) {
	this._elementsInLineBox = new Array();
	this._unbreakableLineBoxElements = new Array();
	this._unbreakableWidth = 0;
	this._currentInlineBoxesData = new Array();
	core.style.formatter.FormattingContext.call(this,formattingContextRoot);
}
core.style.formatter.InlineFormattingContext.__name__ = ["core","style","formatter","InlineFormattingContext"];
core.style.formatter.InlineFormattingContext.__super__ = core.style.formatter.FormattingContext;
core.style.formatter.InlineFormattingContext.prototype = $extend(core.style.formatter.FormattingContext.prototype,{
	_elementsInLineBox: null
	,_unbreakableLineBoxElements: null
	,_unbreakableWidth: null
	,_currentInlineBoxesData: null
	,dispose: function() {
		core.style.formatter.FormattingContext.prototype.dispose.call(this);
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
		core.style.formatter.FormattingContext.prototype.doFormat.call(this,elementsInFormattingContext);
		this.insertBreakOpportunity(true,true);
	}
	,getRemainingLineWidth: function() {
		return this._formattingContextRoot.getStyle().getComputedStyle().width - this._formattingContextData.x - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._formattingContextRoot.getStyle().getComputedStyle().width);
	}
	,insertEmbeddedElement: function(element) {
		this.insertBreakOpportunity(false);
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(Math.round(element.getBounds().width));
		this.insertBreakOpportunity(false);
	}
	,insertFormattingContextRootElement: function(element) {
		element.getBounds().width = element.getStyle().get_htmlElement().get_offsetWidth();
		element.getBounds().height = element.getStyle().get_htmlElement().get_offsetHeight();
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
				if(this._elementsInLineBox[i].get_parentNode() != this._formattingContextRoot.getStyle().getElementRenderer()) this.getParentInlineBoxesData(this._elementsInLineBox[i].get_parentNode()).children.push(this._elementsInLineBox[i]); else lineBoxElements.push(this._elementsInLineBox[i]);
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
				var inlineBoxRenderer = new core.renderer.InlineBoxRenderer(this._currentInlineBoxesData[i].element.getStyle());
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
				this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,elementWidth,this._formattingContextRoot.getStyle().getComputedStyle().width);
				if(this._formattingContextData.y + lineBoxHeight > this._formattingContextData.maxHeight) this._formattingContextData.maxHeight = this._formattingContextData.y + lineBoxHeight;
				this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
			} else if(this._layOutLastLine == true) {
				this._formattingContextData.y += lineBoxHeight;
				this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,elementWidth,this._formattingContextRoot.getStyle().getComputedStyle().width);
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
		remainingSpace = this._formattingContextRoot.getStyle().getComputedStyle().width - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._formattingContextData.y) - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._formattingContextRoot.getStyle().getComputedStyle().width);
		flowX = this._formattingContextRoot.getStyle().getComputedStyle().paddingLeft;
		flowX += this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
		switch( (this._formattingContextRoot.getStyle().getComputedStyle().textAlign)[1] ) {
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
				concatenatedLength = this._formattingContextRoot.getStyle().getComputedStyle().width;
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
			var htmlElement = this._elementsInLineBox[i].getStyle().get_htmlElement();
			var htmlElementAscent;
			var htmlElementDescent;
			var htmlElementVerticalAlign = htmlElement.get_style().getComputedStyle().verticalAlign;
			if(this._elementsInLineBox[i].isEmbedded() == true && this._elementsInLineBox[i].isText() == false || this._elementsInLineBox[i].establishesNewFormattingContext() == true) {
				htmlElementAscent = htmlElement.get_offsetHeight() + this._elementsInLineBox[i].getStyle().getComputedStyle().marginTop + this._elementsInLineBox[i].getStyle().getComputedStyle().marginBottom;
				htmlElementDescent = 0;
				switch( (htmlElement.get_style().getVerticalAlign())[1] ) {
				case 3:
					htmlElementAscent = Math.round(lineBoxAscent);
					htmlElementDescent = Math.round(htmlElement.get_offsetHeight() - lineBoxAscent);
					break;
				default:
				}
			} else {
				htmlElementAscent = htmlElement.get_style().getFontMetricsData().ascent;
				htmlElementDescent = htmlElement.get_style().getFontMetricsData().descent;
				var leading = htmlElement.get_style().getComputedStyle().lineHeight - (htmlElementAscent + htmlElementDescent);
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
			var htmlElement = this._elementsInLineBox[i].getStyle().get_htmlElement();
			var verticalAlign;
			switch( (htmlElement.get_style().getVerticalAlign())[1] ) {
			case 3:
				verticalAlign = 0;
				break;
			case 6:
				verticalAlign = 0;
				break;
			default:
				verticalAlign = htmlElement.get_style().getComputedStyle().verticalAlign;
			}
			this._elementsInLineBox[i].getBounds().y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + this._formattingContextData.y + this._formattingContextRoot.getStyle().getComputedStyle().paddingTop;
			if(this._elementsInLineBox[i].isEmbedded() == true && this._elementsInLineBox[i].isText() == false || this._elementsInLineBox[i].establishesNewFormattingContext() == true) {
				switch( (htmlElement.get_style().getVerticalAlign())[1] ) {
				case 3:
					this._elementsInLineBox[i].getBounds().y = this._formattingContextData.y;
					break;
				default:
					this._elementsInLineBox[i].getBounds().y -= htmlElement.get_offsetHeight() + this._elementsInLineBox[i].getStyle().getComputedStyle().marginTop + this._elementsInLineBox[i].getStyle().getComputedStyle().marginBottom;
				}
			}
		}
		return Math.round(lineBoxHeight);
	}
	,__class__: core.style.formatter.InlineFormattingContext
});
var cocktailCore = cocktailCore || {}
if(!cocktailCore.focus) cocktailCore.focus = {}
if(!cocktailCore.focus["abstract"]) cocktailCore.focus["abstract"] = {}
cocktailCore.focus.abstract.AbstractFocusManagerImpl = $hxClasses["cocktailCore.focus.abstract.AbstractFocusManagerImpl"] = function() {
	this.initKeyboardListeners();
}
cocktailCore.focus.abstract.AbstractFocusManagerImpl.__name__ = ["cocktailCore","focus","abstract","AbstractFocusManagerImpl"];
cocktailCore.focus.abstract.AbstractFocusManagerImpl.prototype = {
	_bodyElement: null
	,bodyElement: null
	,_activeElement: null
	,activeElement: null
	,_tabList: null
	,_tabListIndex: null
	,initKeyboardListeners: function() {
	}
	,invalidate: function() {
		this._tabList == null;
	}
	,onKeyDown: function(keyboardEvent) {
	}
	,onKeyUp: function(keyEventData) {
		if(this._activeElement.get_onKeyUp() != null) (this._activeElement.get_onKeyUp())(keyEventData);
	}
	,doTabFocus: function(reverse) {
		if(this._tabList == null) this._tabList = this.buildTabList(this._bodyElement);
		if(this.getActiveElement() != this._bodyElement) {
			if(reverse == false) {
				if(this._tabListIndex == this._tabList.length - 1) this._tabListIndex = 0; else this._tabListIndex++;
			} else if(this._tabListIndex == 0) this._tabListIndex = this._tabList.length - 1; else this._tabListIndex--;
		} else if(reverse == false) this._tabListIndex = 0; else this._tabListIndex = this._tabList.length - 1;
		this.setActiveElement(this._tabList[this._tabListIndex]);
	}
	,buildTabList: function(htmlElement) {
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
	,doBuildTabList: function(htmlElement,orderedTabList,indexedTabList) {
	}
	,simulateMouseClick: function(keyEventData) {
		if(this.getActiveElement().get_onMouseDown() != null) {
			var mouseEvent = new core.event.MouseEvent("mousedown",this._activeElement,0.0,0.0,0.0,0.0,0.0,false,false,false);
			(this.getActiveElement().get_onMouseDown())(mouseEvent);
		}
	}
	,setActiveElement: function(value) {
		if(this._activeElement != null) {
			if(this._activeElement.get_onBlur() != null) (this._activeElement.get_onBlur())(new core.event.Event("blur",this._activeElement));
		}
		if(value == null) value = this._bodyElement;
		if(value != this._activeElement) {
			this._activeElement = value;
			if(this._activeElement.get_onFocus() != null) (this._activeElement.get_onFocus())(new core.event.Event("focus",this._activeElement));
		}
		return this._activeElement;
	}
	,getActiveElement: function() {
		return this._activeElement;
	}
	,setBodyElement: function(value) {
		this._bodyElement = value;
		this.setActiveElement(null);
		this.invalidate();
		return this._bodyElement;
	}
	,getBodyElement: function() {
		return this._bodyElement;
	}
	,__class__: cocktailCore.focus.abstract.AbstractFocusManagerImpl
	,__properties__: {set_activeElement:"setActiveElement",get_activeElement:"getActiveElement",set_bodyElement:"setBodyElement",get_bodyElement:"getBodyElement"}
}
core.style.AbstractStyle = $hxClasses["core.style.AbstractStyle"] = function(htmlElement) {
	this._htmlElement = htmlElement;
	this._isDirty = true;
	this.initDefaultStyleValues();
}
core.style.AbstractStyle.__name__ = ["core","style","AbstractStyle"];
core.style.AbstractStyle.getDefaultStyle = function() {
	return { fontFamily : [core.style.FontFamily.genericFamily(core.style.GenericFontFamily.serif)], color : core.unit.ColorValue.keyword(core.unit.ColorKeyword.black)};
}
core.style.AbstractStyle.prototype = {
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
		this._width = core.style.Dimension.cssAuto;
		this._height = core.style.Dimension.cssAuto;
		this._minWidth = core.style.ConstrainedDimension.length(core.unit.Length.px(0));
		this._maxWidth = core.style.ConstrainedDimension.none;
		this._minHeight = core.style.ConstrainedDimension.length(core.unit.Length.px(0));
		this._maxHeight = core.style.ConstrainedDimension.none;
		this._marginTop = core.style.Margin.length(core.unit.Length.px(0));
		this._marginBottom = core.style.Margin.length(core.unit.Length.px(0));
		this._marginLeft = core.style.Margin.length(core.unit.Length.px(0));
		this._marginRight = core.style.Margin.length(core.unit.Length.px(0));
		this._paddingTop = core.style.Padding.length(core.unit.Length.px(0));
		this._paddingBottom = core.style.Padding.length(core.unit.Length.px(0));
		this._paddingLeft = core.style.Padding.length(core.unit.Length.px(0));
		this._paddingRight = core.style.Padding.length(core.unit.Length.px(0));
		this._lineHeight = core.style.LineHeight.normal;
		this._verticalAlign = core.style.VerticalAlign.baseline;
		this._display = core.style.Display.cssInline;
		this._position = core.style.Position.cssStatic;
		this._top = core.style.PositionOffset.cssAuto;
		this._bottom = core.style.PositionOffset.cssAuto;
		this._left = core.style.PositionOffset.cssAuto;
		this._right = core.style.PositionOffset.cssAuto;
		this._cssFloat = core.style.CSSFloat.none;
		this._clear = core.style.Clear.none;
		this._backgroundColor = core.unit.ColorValue.transparent;
		this._backgroundImage = [core.style.BackgroundImage.none];
		this._backgroundRepeat = [{ x : core.style.BackgroundRepeatValue.repeat, y : core.style.BackgroundRepeatValue.repeat}];
		this._backgroundPosition = [{ x : core.style.BackgroundPositionX.percent(0), y : core.style.BackgroundPositionY.percent(0)}];
		this._backgroundOrigin = [core.style.BackgroundOrigin.paddingBox];
		this._backgroundSize = [core.style.BackgroundSize.dimensions({ x : core.style.BackgroundSizeDimension.cssAuto, y : core.style.BackgroundSizeDimension.cssAuto})];
		this._backgroundClip = [core.style.BackgroundClip.borderBox];
		this._fontStyle = core.style.FontStyle.normal;
		this._fontVariant = core.style.FontVariant.normal;
		this._fontWeight = core.style.FontWeight.normal;
		this._fontSize = core.style.FontSize.absoluteSize(core.unit.FontSizeAbsoluteSize.medium);
		this._textIndent = core.style.TextIndent.length(core.unit.Length.px(0));
		this._textAlign = core.style.TextAlign.left;
		this._letterSpacing = core.style.LetterSpacing.normal;
		this._wordSpacing = core.style.WordSpacing.normal;
		this._textTransform = core.style.TextTransform.none;
		this._whiteSpace = core.style.WhiteSpace.normal;
		this._visibility = core.style.Visibility.visible;
		this._opacity = 1.0;
		this._overflowX = core.style.Overflow.visible;
		this._overflowY = core.style.Overflow.visible;
		this._transformOrigin = { x : core.style.TransformOriginX.center, y : core.style.TransformOriginY.center};
		this._transform = core.style.Transform.none;
		this._cursor = core.style.Cursor.cssDefault;
		var defaultStyles = core.style.AbstractStyle.getDefaultStyle();
		this._fontFamily = defaultStyles.fontFamily;
		this._color = defaultStyles.color;
		this.applyDefaultHTMLStyles();
	}
	,initComputedStyles: function() {
		this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : core.style.Clear.none, cssFloat : core.style.CSSFloat.none, display : core.style.Display.block, position : core.style.Position.cssStatic, verticalAlign : 0.0, fontSize : 16.0, lineHeight : 14.0, fontWeight : core.style.FontWeight.normal, fontStyle : core.style.FontStyle.normal, fontFamily : [core.style.FontFamily.genericFamily(core.style.GenericFontFamily.serif)], fontVariant : core.style.FontVariant.normal, textTransform : core.style.TextTransform.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : core.style.WhiteSpace.normal, textAlign : core.style.TextAlign.left, color : { color : 0, alpha : 1.0}, visibility : true, opacity : 1.0, overflowX : core.style.Overflow.visible, overflowY : core.style.Overflow.visible, transformOrigin : { x : 0.0, y : 0.0}, transform : new core.geom.Matrix(), backgroundColor : { color : 0, alpha : 1.0}, backgroundSize : [], backgroundOrigin : [], backgroundImage : [], backgroundClip : [], backgroundPosition : [], backgroundRepeat : [], cursor : core.style.Cursor.cssDefault};
	}
	,applyDefaultHTMLStyles: function() {
		switch(this._htmlElement.get_tagName()) {
		case "html":case "adress":case "dd":case "div":case "dl":case "dt":case "fieldset":case "form":case "frame":case "frameset":case "noframes":case "ol":case "ul":case "center":case "dir":case "hr":case "menu":
			this._display = core.style.Display.block;
			break;
		case "head":
			this._display = core.style.Display.none;
			break;
		case "body":
			this._display = core.style.Display.block;
			this._marginLeft = this._marginRight = this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.px(8));
			break;
		case "h1":
			this._display = core.style.Display.block;
			this._fontSize = core.style.FontSize.length(core.unit.Length.em(2));
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(0.67));
			break;
		case "h2":
			this._display = core.style.Display.block;
			this._fontSize = core.style.FontSize.length(core.unit.Length.em(1.5));
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(0.75));
			break;
		case "h3":
			this._display = core.style.Display.block;
			this._fontSize = core.style.FontSize.length(core.unit.Length.em(1.17));
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(0.83));
			break;
		case "h4":
			this._display = core.style.Display.block;
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(1.12));
			break;
		case "h5":
			this._display = core.style.Display.block;
			this._fontSize = core.style.FontSize.length(core.unit.Length.em(0.83));
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(1.5));
			break;
		case "h6":
			this._display = core.style.Display.block;
			this._fontSize = core.style.FontSize.length(core.unit.Length.em(0.75));
			this._fontWeight = core.style.FontWeight.bolder;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(1.67));
			break;
		case "p":
			this._display = core.style.Display.block;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(1.67));
			break;
		case "pre":
			this._display = core.style.Display.block;
			this._whiteSpace = core.style.WhiteSpace.pre;
			this._fontFamily = [core.style.FontFamily.genericFamily(core.style.GenericFontFamily.monospace)];
			break;
		case "code":
			this._fontFamily = [core.style.FontFamily.genericFamily(core.style.GenericFontFamily.monospace)];
			break;
		case "i":case "cite":case "em":case "var":
			this._fontStyle = core.style.FontStyle.italic;
			break;
		case "input":
			this._display = core.style.Display.inlineBlock;
			break;
		case "blockquote":
			this._display = core.style.Display.block;
			this._marginTop = this._marginBottom = core.style.Margin.length(core.unit.Length.em(1.12));
			this._marginLeft = this._marginRight = core.style.Margin.length(core.unit.Length.px(40));
			break;
		}
	}
	,createElementRenderer: function(parentElementRenderer) {
		var elementRenderer = new core.renderer.EmbeddedBoxRenderer(this);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		parentElementRenderer.appendChild(elementRenderer);
		return elementRenderer;
	}
	,getLayerRenderer: function(elementRenderer,parentElementRenderer) {
		var layerRenderer;
		if(this.isPositioned() == true) layerRenderer = new core.renderer.LayerRenderer(elementRenderer); else layerRenderer = parentElementRenderer.getLayerRenderer();
		return layerRenderer;
	}
	,layout: function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
	}
	,flow: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext,parentElementRenderer) {
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
	,positionElement: function(lastPositionedHTMLElementData,viewportData,staticPosition) {
		var positioner;
		switch( (this._htmlElement.get_style().getComputedStyle().position)[1] ) {
		case 1:
			positioner = new core.style.positioner.RelativePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedHTMLElementData,staticPosition);
			break;
		case 3:
			positioner = new core.style.positioner.FixedPositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,viewportData,staticPosition);
			break;
		case 2:
			positioner = new core.style.positioner.AbsolutePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedHTMLElementData,staticPosition);
			break;
		default:
		}
		this._elementRenderer.getBounds().width = this._htmlElement.get_offsetWidth();
		this._elementRenderer.getBounds().height = this._htmlElement.get_offsetHeight();
		return this._elementRenderer;
	}
	,scheduleLayout: function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData) {
		var layoutDelegate = this.layout.$bind(this);
		haxe.Timer.delay(function() {
			layoutDelegate(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,null);
		},1);
	}
	,flowChildren: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
	}
	,insertHTMLElement: function(formattingContext,lastPositionedHTMLElementData,viewportData) {
		if(this.isPositioned() == false) formattingContext.insertElement(this._elementRenderer); else {
			var staticPosition = formattingContext.getStaticPosition(this._elementRenderer);
			if(this.isRelativePositioned() == true) formattingContext.insertElement(this._elementRenderer);
			var positionedHTMLElementData = { staticPosition : staticPosition, style : this};
			lastPositionedHTMLElementData.children.push(positionedHTMLElementData);
		}
	}
	,invalidate: function() {
		if(this._isDirty == false) {
			this._isDirty = true;
			if(this._htmlElement.get_parentNode() != null) {
				if(this.isParentDirty() == true) {
					var parent = this._htmlElement.get_parentNode();
					parent.get_style().invalidate();
				} else {
					var parent = this._htmlElement.get_parentNode();
					var parentStyle = parent.get_style();
					var containingHTMLElementData = parentStyle.getContainerHTMLElementData();
					var viewPortData = this.getWindowData();
					var lastPositionedHTMLElementData = { children : new Array(), data : this.getFirstPositionedAncestorData()};
					this.scheduleLayout(containingHTMLElementData,lastPositionedHTMLElementData,viewPortData);
				}
			}
		}
	}
	,invalidateText: function() {
		this._fontMetrics = null;
		this.invalidate();
	}
	,invalidatePositionOffset: function() {
		if(this.isPositioned() == false) this.invalidate();
	}
	,invalidateMargin: function() {
		if(this.getPosition() == core.style.Position.relative || this.getPosition() == core.style.Position.cssStatic) this.invalidate();
	}
	,isParentDirty: function() {
		var ret = true;
		return ret;
	}
	,computeDisplayStyles: function() {
		core.style.computer.DisplayStylesComputer.compute(this);
	}
	,computeBackgroundStyles: function() {
		core.style.computer.BackgroundStylesComputer.compute(this);
	}
	,computeHTMLElementStyles: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData) {
		this.computeDisplayStyles();
		this.computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		this.computeBoxModelStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
	}
	,computeVisualEffectStyles: function() {
		core.style.computer.VisualEffectStylesComputer.compute(this);
	}
	,computeTextAndFontStyles: function(containingHTMLElementData,containingHTMLElementFontMetricsData) {
		core.style.computer.FontAndTextStylesComputer.compute(this,containingHTMLElementData,containingHTMLElementFontMetricsData);
	}
	,computeBoxModelStyles: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
		var boxComputer = this.getBoxStylesComputer();
		var containingBlockDimensions = this.getContainingHTMLElementData(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
		boxComputer.measure(this,containingBlockDimensions);
	}
	,getBoxStylesComputer: function() {
		var boxComputer;
		if(this.isFloat() == true) boxComputer = new core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer(); else {
			switch( (this._computedStyle.display)[1] ) {
			case 0:
				boxComputer = new core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer();
				break;
			case 1:
				boxComputer = new core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer();
				break;
			case 3:
				boxComputer = null;
				break;
			case 2:
				boxComputer = new core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer();
				break;
			}
		}
		return boxComputer;
	}
	,getContainingHTMLElementData: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData) {
		var containingBlockDimensions;
		if(this.isPositioned() == true) {
			if(this._computedStyle.position == core.style.Position.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto}; else if(this._computedStyle.position == core.style.Position.absolute) containingBlockDimensions = { width : lastPositionedHTMLElementData.width, height : lastPositionedHTMLElementData.height, isHeightAuto : lastPositionedHTMLElementData.isHeightAuto, isWidthAuto : lastPositionedHTMLElementData.isWidthAuto}; else containingBlockDimensions = containingHTMLElementData;
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
		return this._computedStyle.position == core.style.Position.relative;
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
		var isPositioned = parent.get_style().isPositioned();
		while(isPositioned == false) if(parent.get_parentNode() != null) {
			parent = parent.get_parentNode();
			isPositioned = parent.get_style().isPositioned();
		} else isPositioned = true;
		return parent;
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
	,isNotDisplayed: function() {
		return this._computedStyle.display == core.style.Display.none;
	}
	,getFirstPositionedAncestorData: function() {
		var firstPositionedAncestorData;
		var firstPositionedAncestor = this.getFirstPositionedAncestor();
		if(firstPositionedAncestor != null) {
			var firstPositionedAncestorStyle = firstPositionedAncestor.get_style();
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
		this.invalidateMargin();
		return this._marginLeft = value;
	}
	,setMarginRight: function(value) {
		this.invalidateMargin();
		return this._marginRight = value;
	}
	,setMarginTop: function(value) {
		this.invalidateMargin();
		return this._marginTop = value;
	}
	,setMarginBottom: function(value) {
		this.invalidateMargin();
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
		this.invalidatePositionOffset();
		return this._top = value;
	}
	,setLeft: function(value) {
		this.invalidatePositionOffset();
		return this._left = value;
	}
	,setBottom: function(value) {
		this.invalidatePositionOffset();
		return this._bottom = value;
	}
	,setRight: function(value) {
		this.invalidatePositionOffset();
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
		this.invalidateText();
		return this._fontSize = value;
	}
	,setFontWeight: function(value) {
		this.invalidateText();
		return this._fontWeight = value;
	}
	,setFontStyle: function(value) {
		this.invalidateText();
		return this._fontStyle = value;
	}
	,setFontFamily: function(value) {
		this.invalidateText();
		return this._fontFamily = value;
	}
	,setFontVariant: function(value) {
		this.invalidateText();
		return this._fontVariant = value;
	}
	,setTextTransform: function(value) {
		this.invalidateText();
		return this._textTransform = value;
	}
	,setLetterSpacing: function(value) {
		this.invalidateText();
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
		this.invalidateText();
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
		return this._backgroundColor = value;
	}
	,getBackgroundColor: function() {
		return this._backgroundColor;
	}
	,setBackgroundImage: function(value) {
		return this._backgroundImage = value;
	}
	,getBackgroundImage: function() {
		return this._backgroundImage;
	}
	,setBackgroundRepeat: function(value) {
		return this._backgroundRepeat = value;
	}
	,getBackgroundRepeat: function() {
		return this._backgroundRepeat;
	}
	,setBackgroundSize: function(value) {
		return this._backgroundSize = value;
	}
	,getBackgroundSize: function() {
		return this._backgroundSize;
	}
	,setBackgroundClip: function(value) {
		return this._backgroundClip = value;
	}
	,getBackgroundClip: function() {
		return this._backgroundClip;
	}
	,setBackgroundPosition: function(value) {
		return this._backgroundPosition = value;
	}
	,getBackgroundPosition: function() {
		return this._backgroundPosition;
	}
	,setBackgroundOrigin: function(value) {
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
	,__class__: core.style.AbstractStyle
	,__properties__: {get_elementRenderer:"getElementRenderer",get_fontMetrics:"getFontMetricsData",get_htmlElement:"get_htmlElement",set_computedStyle:"setComputedStyle",get_computedStyle:"getComputedStyle",set_cursor:"setCursor",get_cursor:"getCursor",set_overflowY:"setOverflowY",get_overflowY:"getOverflowY",set_overflowX:"setOverflowX",get_overflowX:"getOverflowX",set_visibility:"setVisibility",get_visibility:"getVisibility",set_opacity:"setOpacity",get_opacity:"getOpacity",set_verticalAlign:"setVerticalAlign",get_verticalAlign:"getVerticalAlign",set_textIndent:"setTextIndent",get_textIndent:"getTextIndent",set_textAlign:"setTextAlign",get_textAlign:"getTextAlign",set_whiteSpace:"setWhiteSpace",get_whiteSpace:"getWhiteSpace",set_wordSpacing:"setWordSpacing",get_wordSpacing:"getWordSpacing",set_letterSpacing:"setLetterSpacing",get_letterSpacing:"getLetterSpacing",set_textTransform:"setTextTransform",get_textTransform:"getTextTransform",set_lineHeight:"setLineHeight",get_lineHeight:"getLineHeight",set_color:"setColor",get_color:"getColor",set_fontVariant:"setFontVariant",get_fontVariant:"getFontVariant",set_fontFamily:"setFontFamily",get_fontFamily:"getFontFamily",set_fontStyle:"setFontStyle",get_fontStyle:"getFontStyle",set_fontWeight:"setFontWeight",get_fontWeight:"getFontWeight",set_fontSize:"setFontSize",get_fontSize:"getFontSize",set_backgroundClip:"setBackgroundClip",get_backgroundClip:"getBackgroundClip",set_backgroundPosition:"setBackgroundPosition",get_backgroundPosition:"getBackgroundPosition",set_backgroundSize:"setBackgroundSize",get_backgroundSize:"getBackgroundSize",set_backgroundOrigin:"setBackgroundOrigin",get_backgroundOrigin:"getBackgroundOrigin",set_backgroundRepeat:"setBackgroundRepeat",get_backgroundRepeat:"getBackgroundRepeat",set_backgroundImage:"setBackgroundImage",get_backgroundImage:"getBackgroundImage",set_backgroundColor:"setBackgroundColor",get_backgroundColor:"getBackgroundColor",set_right:"setRight",get_right:"getRight",set_bottom:"setBottom",get_bottom:"getBottom",set_left:"setLeft",get_left:"getLeft",set_top:"setTop",get_top:"getTop",set_maxWidth:"setMaxWidth",get_maxWidth:"getMaxWidth",set_minWidth:"setMinWidth",get_minWidth:"getMinWidth",set_maxHeight:"setMaxHeight",get_maxHeight:"getMaxHeight",set_minHeight:"setMinHeight",get_minHeight:"getMinHeight",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_paddingBottom:"setPaddingBottom",get_paddingBottom:"getPaddingBottom",set_paddingTop:"setPaddingTop",get_paddingTop:"getPaddingTop",set_paddingRight:"setPaddingRight",get_paddingRight:"getPaddingRight",set_paddingLeft:"setPaddingLeft",get_paddingLeft:"getPaddingLeft",set_marginBottom:"setMarginBottom",get_marginBottom:"getMarginBottom",set_marginTop:"setMarginTop",get_marginTop:"getMarginTop",set_marginRight:"setMarginRight",get_marginRight:"getMarginRight",set_marginLeft:"setMarginLeft",get_marginLeft:"getMarginLeft",set_transform:"setTransform",get_transform:"getTransform",set_transformOrigin:"setTransformOrigin",get_transformOrigin:"getTransformOrigin",set_clear:"setClear",get_clear:"getClear",set_cssFloat:"setCSSFloat",get_cssFloat:"getCSSFloat",set_position:"setPosition",get_position:"getPosition",set_display:"setDisplay",get_display:"getDisplay"}
}
if(!core.style.floats) core.style.floats = {}
core.style.floats.FloatsManager = $hxClasses["core.style.floats.FloatsManager"] = function() {
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
}
core.style.floats.FloatsManager.__name__ = ["core","style","floats","FloatsManager"];
core.style.floats.FloatsManager.prototype = {
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
		switch( (elementRenderer.getStyle().getComputedStyle().cssFloat)[1] ) {
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
		var floatWidth = elementRenderer.getStyle().get_htmlElement().get_offsetWidth();
		var floatHeight = elementRenderer.getStyle().get_htmlElement().get_offsetHeight();
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
	,__class__: core.style.floats.FloatsManager
	,__properties__: {get_floats:"getFloats"}
}
if(!core.drawing) core.drawing = {}
core.drawing.AbstractDrawingManager = $hxClasses["core.drawing.AbstractDrawingManager"] = function(nativeElement,width,height) {
	this._nativeElement = nativeElement;
	this._width = width;
	this._height = height;
}
core.drawing.AbstractDrawingManager.__name__ = ["core","drawing","AbstractDrawingManager"];
core.drawing.AbstractDrawingManager.prototype = {
	_nativeElement: null
	,nativeElement: null
	,_width: null
	,width: null
	,_height: null
	,height: null
	,beginFill: function(fillStyle,lineStyle) {
		if(fillStyle == null) fillStyle = core.dom.FillStyleValue.none;
		if(lineStyle == null) lineStyle = core.dom.LineStyleValue.none;
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
	,__class__: core.drawing.AbstractDrawingManager
	,__properties__: {set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",get_nativeElement:"getNativeElement"}
}
port.browser.DrawingManager = $hxClasses["port.browser.DrawingManager"] = function(nativeElement,width,height) {
	core.drawing.AbstractDrawingManager.call(this,nativeElement,width,height);
}
port.browser.DrawingManager.__name__ = ["port","browser","DrawingManager"];
port.browser.DrawingManager.__super__ = core.drawing.AbstractDrawingManager;
port.browser.DrawingManager.prototype = $extend(core.drawing.AbstractDrawingManager.prototype,{
	beginFill: function(fillStyle,lineStyle) {
		core.drawing.AbstractDrawingManager.prototype.beginFill.call(this,fillStyle,lineStyle);
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
		if(matrix == null) matrix = new core.geom.Matrix();
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
		core.drawing.AbstractDrawingManager.prototype.setWidth.call(this,value);
		this._nativeElement.width = value;
		return this._width = value;
	}
	,setHeight: function(value) {
		this.clear();
		core.drawing.AbstractDrawingManager.prototype.setHeight.call(this,value);
		this._nativeElement.height = value;
		return this._height = value;
	}
	,__class__: port.browser.DrawingManager
});
core.dom.CharacterData = $hxClasses["core.dom.CharacterData"] = function() {
	core.dom.Node.call(this);
}
core.dom.CharacterData.__name__ = ["core","dom","CharacterData"];
core.dom.CharacterData.__super__ = core.dom.Node;
core.dom.CharacterData.prototype = $extend(core.dom.Node.prototype,{
	_data: null
	,data: null
	,get_nodeType: function() {
		return core.dom.NodeType.TEXT_NODE;
	}
	,get_data: function() {
		return this._data;
	}
	,set_data: function(value) {
		return this._data = value;
	}
	,__class__: core.dom.CharacterData
	,__properties__: $extend(core.dom.Node.prototype.__properties__,{set_data:"set_data",get_data:"get_data"})
});
core.dom.Text = $hxClasses["core.dom.Text"] = function() {
	core.dom.CharacterData.call(this);
	this._textFragments = new Array();
}
core.dom.Text.__name__ = ["core","dom","Text"];
core.dom.Text.applyTextTransform = function(text,textTransform) {
	switch( (textTransform)[1] ) {
	case 1:
		text = text.toUpperCase();
		break;
	case 2:
		text = text.toLowerCase();
		break;
	case 0:
		text = core.dom.Text.capitalizeText(text);
		break;
	case 3:
		break;
	}
	return text;
}
core.dom.Text.capitalizeText = function(text) {
	var capitalizedText = text.charAt(0);
	var _g1 = 1, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
	}
	return capitalizedText;
}
core.dom.Text.doGetTextFragments = function(text) {
	var textFragments = new Array();
	var textFragment = "";
	var i = 0;
	while(i < text.length) {
		if(text.charAt(i) == "\\") {
			if(i < text.length - 1) {
				if(text.charAt(i + 1) == "n") {
					if(textFragment != null) {
						textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.lineFeed));
					i++;
				} else if(text.charAt(i + 1) == "t") {
					if(textFragment != null) {
						textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.tab));
					i++;
				}
			}
		}
		if(StringTools.isSpace(text,i) == true) {
			if(textFragment != null) {
				textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.word(textFragment)));
				textFragment = null;
			}
			textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.space));
		} else {
			if(textFragment == null) textFragment = "";
			textFragment += text.charAt(i);
		}
		i++;
	}
	if(textFragment != null) textFragments.push(core.dom.Text.insertTextToken(core.dom.TextTokenValue.word(textFragment)));
	return textFragments;
}
core.dom.Text.insertTextToken = function(textToken) {
	return { textToken : textToken, textRenderer : null};
}
core.dom.Text.__super__ = core.dom.CharacterData;
core.dom.Text.prototype = $extend(core.dom.CharacterData.prototype,{
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
		if(this._textFragments.length == 0) this._textFragments = core.dom.Text.doGetTextFragments(text);
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
	,__class__: core.dom.Text
	,__properties__: $extend(core.dom.CharacterData.prototype.__properties__,{get_nativeElement:"get_nativeElement"})
});
var IntIter = $hxClasses["IntIter"] = function(min,max) {
	this.min = min;
	this.max = max;
}
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
if(!core.style.positioner) core.style.positioner = {}
core.style.positioner.BoxPositioner = $hxClasses["core.style.positioner.BoxPositioner"] = function() {
}
core.style.positioner.BoxPositioner.__name__ = ["core","style","positioner","BoxPositioner"];
core.style.positioner.BoxPositioner.prototype = {
	position: function(elementRenderer,containingHTMLElementData,staticPosition) {
		var htmlElement = elementRenderer.getStyle().get_htmlElement();
		if(htmlElement.get_style().getLeft() != core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getLeftOffset(htmlElement,Math.round(staticPosition.x)); else if(htmlElement.get_style().getRight() != core.style.PositionOffset.cssAuto) elementRenderer.getBounds().x = this.getRightOffset(htmlElement,containingHTMLElementData.width,Math.round(staticPosition.x)); else elementRenderer.getBounds().x = Math.round(staticPosition.x);
		if(htmlElement.get_style().getTop() != core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getTopOffset(htmlElement,Math.round(staticPosition.y)); else if(htmlElement.get_style().getBottom() != core.style.PositionOffset.cssAuto) elementRenderer.getBounds().y = this.getBottomOffset(htmlElement,containingHTMLElementData.height,Math.round(staticPosition.y)); else elementRenderer.getBounds().y = Math.round(staticPosition.y);
		return elementRenderer;
	}
	,getLeftOffset: function(htmlElement,staticPosition) {
		return htmlElement.get_style().getComputedStyle().left;
	}
	,getRightOffset: function(htmlElement,containingHTMLElementWidth,staticPosition) {
		return containingHTMLElementWidth - htmlElement.get_offsetWidth() - htmlElement.get_style().getComputedStyle().right;
	}
	,getTopOffset: function(htmlElement,staticPosition) {
		return htmlElement.get_style().getComputedStyle().top;
	}
	,getBottomOffset: function(htmlElement,containingHTMLElementHeight,staticPosition) {
		return containingHTMLElementHeight - htmlElement.get_offsetHeight() - htmlElement.get_style().getComputedStyle().bottom;
	}
	,__class__: core.style.positioner.BoxPositioner
}
core.style.positioner.RelativePositioner = $hxClasses["core.style.positioner.RelativePositioner"] = function() {
	core.style.positioner.BoxPositioner.call(this);
}
core.style.positioner.RelativePositioner.__name__ = ["core","style","positioner","RelativePositioner"];
core.style.positioner.RelativePositioner.__super__ = core.style.positioner.BoxPositioner;
core.style.positioner.RelativePositioner.prototype = $extend(core.style.positioner.BoxPositioner.prototype,{
	getLeftOffset: function(htmlElement,staticPosition) {
		return staticPosition + htmlElement.get_style().getComputedStyle().left;
	}
	,getRightOffset: function(htmlElement,containingHTMLElementWidth,staticPosition) {
		return staticPosition - htmlElement.get_style().getComputedStyle().right;
	}
	,getTopOffset: function(htmlElement,staticPosition) {
		return staticPosition + htmlElement.get_style().getComputedStyle().top;
	}
	,getBottomOffset: function(htmlElement,containingHTMLElementHeight,staticPosition) {
		return staticPosition - htmlElement.get_style().getComputedStyle().bottom;
	}
	,__class__: core.style.positioner.RelativePositioner
});
if(!core.mouse) core.mouse = {}
core.mouse.MouseCursorManager = $hxClasses["core.mouse.MouseCursorManager"] = function() {
}
core.mouse.MouseCursorManager.__name__ = ["core","mouse","MouseCursorManager"];
core.mouse.MouseCursorManager._mouseCursor = null;
core.mouse.MouseCursorManager.setMouseCursor = function(mouseCursorValue) {
	if(core.mouse.MouseCursorManager._mouseCursor == null) core.mouse.MouseCursorManager._mouseCursor = new port.browser.MouseCursor();
	core.mouse.MouseCursorManager._mouseCursor.setNativeMouseCursor(mouseCursorValue);
}
core.mouse.MouseCursorManager.getMousecursor = function() {
	if(core.mouse.MouseCursorManager._mouseCursor == null) core.mouse.MouseCursorManager._mouseCursor = new port.browser.MouseCursor();
	return core.mouse.MouseCursorManager._mouseCursor.getNativeMouseCursor();
}
core.mouse.MouseCursorManager.prototype = {
	__class__: core.mouse.MouseCursorManager
}
var Hash = $hxClasses["Hash"] = function() {
	this.h = {}
	if(this.h.__proto__ != null) {
		this.h.__proto__ = null;
		delete(this.h.__proto__);
	}
}
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
if(!core.geom) core.geom = {}
core.geom.Matrix = $hxClasses["core.geom.Matrix"] = function(data) {
	this.setData(data);
}
core.geom.Matrix.__name__ = ["core","geom","Matrix"];
core.geom.Matrix.prototype = {
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
		var translationMatrix = new core.geom.Matrix(translationMatrixData);
		this.concatenate(translationMatrix);
	}
	,rotate: function(angle,registrationPoint) {
		var rotatedMatrix = new core.geom.Matrix();
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
		var rotationMatrix = new core.geom.Matrix(rotationMatrixData);
		rotatedMatrix.concatenate(rotationMatrix);
		rotatedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(rotatedMatrix);
	}
	,scale: function(scaleX,scaleY,registrationPoint) {
		var scaledMatrix = new core.geom.Matrix();
		scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
		var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
		var scalingMatrix = new core.geom.Matrix(scalingMatrixData);
		scaledMatrix.concatenate(scalingMatrix);
		scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(scaledMatrix);
	}
	,skew: function(skewX,skewY,registrationPoint) {
		var skewedMatrix = new core.geom.Matrix();
		skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
		var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
		var skewingMatrix = new core.geom.Matrix(skewingMatrixData);
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
	,__class__: core.geom.Matrix
	,__properties__: {set_data:"setData",get_data:"getData"}
}
port.browser.Style = $hxClasses["port.browser.Style"] = function(htmlElement) {
	core.style.AbstractStyle.call(this,htmlElement);
}
port.browser.Style.__name__ = ["port","browser","Style"];
port.browser.Style.__super__ = core.style.AbstractStyle;
port.browser.Style.prototype = $extend(core.style.AbstractStyle.prototype,{
	getCSSDisplay: function(value) {
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
	,getCSSFloatAsString: function(value) {
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
	,getCSSClear: function(value) {
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
	,getCSSPosition: function(value) {
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
	,getCSSOverflow: function(value) {
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
	,getCSSOpacity: function(value) {
		var cssOpacityValue;
		cssOpacityValue = Std.string(value);
		return cssOpacityValue;
	}
	,getCSSVisibility: function(value) {
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
	,getCSSTransform: function(value) {
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
				cssTransformValue += this.getCSSTransformFunction(value1[i]);
				if(i < value1.length - 1) cssTransformValue += " ";
			}
			break;
		}
		return cssTransformValue;
	}
	,getCSSTransformFunction: function(transformFunction) {
		var cssTransformFunction;
		var $e = (transformFunction);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			cssTransformFunction = "matrix(" + value.a + "," + value.b + "," + value.c + "," + value.d + "," + value.e + "," + value.f + ")";
			break;
		case 7:
			var angle = $e[2];
			cssTransformFunction = "rotate(" + this.getCSSAngle(angle) + ")";
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
			cssTransformFunction = "skew(" + this.getCSSAngle(skewX) + "," + this.getCSSAngle(skewY) + ")";
			break;
		case 8:
			var skewX = $e[2];
			cssTransformFunction = "skewX(" + this.getCSSAngle(skewX) + ")";
			break;
		case 9:
			var skewY = $e[2];
			cssTransformFunction = "skewY(" + this.getCSSAngle(skewY) + ")";
			break;
		case 1:
			var ty = $e[3], tx = $e[2];
			cssTransformFunction = "translate(" + this.getCSSTranslation(tx) + "," + this.getCSSTranslation(ty) + ")";
			break;
		case 2:
			var tx = $e[2];
			cssTransformFunction = "translateX(" + this.getCSSTranslation(tx) + ")";
			break;
		case 3:
			var ty = $e[2];
			cssTransformFunction = "translateY(" + this.getCSSTranslation(ty) + ")";
			break;
		}
		return cssTransformFunction;
	}
	,getCSSTranslation: function(translation) {
		var cssTranslation;
		var $e = (translation);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			cssTranslation = this.getCSSLength(value);
			break;
		case 1:
			var value = $e[2];
			cssTranslation = this.getCSSPercentValue(value);
			break;
		}
		return cssTranslation;
	}
	,getCSSTransformOrigin: function(value) {
		var cssTransformOriginValue;
		var $e = (value.x);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssTransformOriginValue = this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssTransformOriginValue = this.getCSSPercentValue(value1);
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
			cssTransformOriginValue += this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssTransformOriginValue += this.getCSSPercentValue(value1);
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
	,getCSSMargin: function(value) {
		var cssMarginValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssMarginValue = this.getCSSLength(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssMarginValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssMarginValue = "auto";
			break;
		}
		return cssMarginValue;
	}
	,getCSSPadding: function(value) {
		var cssPaddingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssPaddingValue = this.getCSSLength(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssPaddingValue = this.getCSSPercentValue(percentValue);
			break;
		}
		return cssPaddingValue;
	}
	,getCSSDimension: function(value) {
		var cssDimensionValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssDimensionValue = this.getCSSLength(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssDimensionValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssDimensionValue = "auto";
			break;
		}
		return cssDimensionValue;
	}
	,getCSSPositionOffset: function(value) {
		var cssPositionOffsetValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssPositionOffsetValue = this.getCSSLength(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssPositionOffsetValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssPositionOffsetValue = "auto";
			break;
		}
		return cssPositionOffsetValue;
	}
	,getCSSConstrainedDimension: function(value) {
		var cssConstrainedValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssConstrainedValue = this.getCSSLength(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssConstrainedValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssConstrainedValue = "none";
			break;
		}
		return cssConstrainedValue;
	}
	,getCSSVerticalAlign: function(value) {
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
			cssVerticalAlignValue = this.getCSSPercentValue(value1);
			break;
		case 9:
			var value1 = $e[2];
			cssVerticalAlignValue = this.getCSSLength(value1);
			break;
		}
		return cssVerticalAlignValue;
	}
	,getCSSLineHeight: function(value) {
		var cssLineHeightValue;
		var $e = (value);
		switch( $e[1] ) {
		case 2:
			var unit = $e[2];
			cssLineHeightValue = this.getCSSLength(unit);
			break;
		case 0:
			cssLineHeightValue = "normal";
			break;
		case 3:
			var value1 = $e[2];
			cssLineHeightValue = this.getCSSPercentValue(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssLineHeightValue = Std.string(value1);
			break;
		}
		return cssLineHeightValue;
	}
	,getCSSFontSize: function(value) {
		var cssFontSizeValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssFontSizeValue = this.getCSSLength(unit);
			break;
		case 1:
			var percent = $e[2];
			cssFontSizeValue = this.getCSSPercentValue(percent);
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
	,getCSSFontWeight: function(value) {
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
	,getCSSFontStyle: function(value) {
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
	,getCSSFontVariant: function(value) {
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
	,getCSSFontFamily: function(value) {
		var cssFontFamilyValue = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			var fontName;
			var $e = (value[i]);
			switch( $e[1] ) {
			case 0:
				var name = $e[2];
				fontName = name;
				break;
			case 1:
				var genericName = $e[2];
				switch( (genericName)[1] ) {
				case 0:
					fontName = "serif";
					break;
				case 1:
					fontName = "sans-serif";
					break;
				case 2:
					fontName = "monospace";
					break;
				}
				break;
			}
			if(fontName.indexOf(" ") != -1) fontName = "'" + fontName + "'";
			cssFontFamilyValue += fontName;
			if(i < value.length - 1) cssFontFamilyValue += ",";
		}
		return cssFontFamilyValue;
	}
	,getCSSTextAlign: function(value) {
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
	,getCSSWhiteSpace: function(value) {
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
	,getCSSTextTransform: function(value) {
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
	,getCSSTextIndent: function(value) {
		var cssTextIndentValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssTextIndentValue = this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssTextIndentValue = this.getCSSPercentValue(value1);
			break;
		}
		return cssTextIndentValue;
	}
	,getCSSLetterSpacing: function(value) {
		var cssLetterSpacingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			cssLetterSpacingValue = "normal";
			break;
		case 1:
			var unit = $e[2];
			cssLetterSpacingValue = this.getCSSLength(unit);
			break;
		}
		return cssLetterSpacingValue;
	}
	,getCSSWordSpacing: function(value) {
		var cssWordSpacingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			cssWordSpacingValue = "normal";
			break;
		case 1:
			var unit = $e[2];
			cssWordSpacingValue = this.getCSSLength(unit);
			break;
		}
		return cssWordSpacingValue;
	}
	,getCSSBackgroundColor: function(value) {
		var cssBackgroundColor;
		cssBackgroundColor = this.getCSSColor(value);
		return cssBackgroundColor;
	}
	,getCSSBackgroundOrigin: function(value) {
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
	,getCSSBackgroundClip: function(value) {
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
	,getCSSBackgroundImage: function(value) {
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
				cssBackgroundImage += this.getCSSImageValue(value1);
				break;
			}
			if(i < value.length - 1) cssBackgroundImage += ",";
		}
		return cssBackgroundImage;
	}
	,getCSSBackgroundSize: function(value) {
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
				cssBackgroundSize += this.getCSSBackgroundSizeDimensions(value1);
				break;
			}
			if(i < value.length - 1) cssBackgroundSize += ",";
		}
		return cssBackgroundSize;
	}
	,getCSSBackgroundSizeDimensions: function(value) {
		var cssBackgroundSizeDimensions = this.getCSSBackgroundSizeDimension(value.x) + " " + this.getCSSBackgroundSizeDimension(value.y);
		return cssBackgroundSizeDimensions;
	}
	,getCSSBackgroundSizeDimension: function(value) {
		var cssBackgroundSizeDimension;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundSizeDimension = this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssBackgroundSizeDimension = this.getCSSPercentValue(value1);
			break;
		case 2:
			cssBackgroundSizeDimension = "auto";
			break;
		}
		return cssBackgroundSizeDimension;
	}
	,getCSSBackgroundPosition: function(value) {
		var cssBackgroundPositionData = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssBackgroundPositionData += this.getCSSBackgroundPositionX(value[i].x) + " " + this.getCSSBackgroundPositionY(value[i].y);
			if(i < value.length - 1) cssBackgroundPositionData += ",";
		}
		return cssBackgroundPositionData;
	}
	,getCSSBackgroundPositionX: function(value) {
		var cssBackgroundPositionX;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundPositionX = this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssBackgroundPositionX = this.getCSSPercentValue(value1);
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
	,getCSSBackgroundPositionY: function(value) {
		var cssBackgroundPositionY;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundPositionY = this.getCSSLength(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssBackgroundPositionY = this.getCSSPercentValue(value1);
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
	,getCSSBackgroundRepeat: function(value) {
		var cssBackgroundRepeat = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssBackgroundRepeat += this.getCSSBackgroundRepeatValue(value[i].x) + " " + this.getCSSBackgroundRepeatValue(value[i].y);
			if(i < value.length - 1) cssBackgroundRepeat += ",";
		}
		return cssBackgroundRepeat;
	}
	,getCSSBackgroundRepeatValue: function(value) {
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
	,getCSSCursor: function(value) {
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
	,getCSSImageValue: function(value) {
		var cssImageValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssImageValue = "url(\"" + value1 + "\")";
			break;
		case 1:
			var value1 = $e[2];
			cssImageValue = "image(" + this.getCSSImageList(value1) + ")";
			break;
		case 2:
			var value1 = $e[2];
			cssImageValue = this.getCSSGradientValue(value1);
			break;
		}
		return cssImageValue;
	}
	,getCSSImageList: function(value) {
		var cssImageList = "";
		var _g1 = 0, _g = value.urls.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssImageList += "\"" + value.urls[i] + "\"";
			if(i < value.urls.length - 1) cssImageList += ","; else cssImageList += "," + this.getCSSColor(value.fallbackColor);
		}
		return cssImageList;
	}
	,getCSSGradientValue: function(value) {
		var cssGradientValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssGradientValue = "linear-gradient(" + this.getCSSLinearGradientValue(value1) + ")";
			break;
		}
		return cssGradientValue;
	}
	,getCSSLinearGradientValue: function(value) {
		var cssLinearGradientValue = this.getCSSGradientAngle(value.angle) + "," + this.getCSSColorStopsValue(value.colorStops);
		return cssLinearGradientValue;
	}
	,getCSSColorStopsValue: function(value) {
		var cssColorStopsData = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssColorStopsData += this.getCSSColor(value[i].color) + " " + this.getCSSColorStopValue(value[i].stop);
			if(i < value.length - 1) cssColorStopsData += ",";
		}
		return cssColorStopsData;
	}
	,getCSSColorStopValue: function(value) {
		var cssColorStopValue;
		var $e = (value);
		switch( $e[1] ) {
		case 1:
			var value1 = $e[2];
			cssColorStopValue = this.getCSSPercentValue(value1);
			break;
		case 0:
			var value1 = $e[2];
			cssColorStopValue = this.getCSSLength(value1);
			break;
		}
		return cssColorStopValue;
	}
	,getCSSGradientAngle: function(value) {
		var cssGradientAngle;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssGradientAngle = this.getCSSAngle(value1);
			break;
		case 2:
			var value1 = $e[2];
			cssGradientAngle = this.getCSSCornerValue(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssGradientAngle = this.getCSSSideValue(value1);
			break;
		}
		return cssGradientAngle;
	}
	,getCSSSideValue: function(value) {
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
	,getCSSCornerValue: function(value) {
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
	,getCSSColor: function(value) {
		var cssColorValue;
		var $e = (value);
		switch( $e[1] ) {
		case 2:
			var value1 = $e[2];
			cssColorValue = value1;
			break;
		case 0:
			var blue = $e[4], green = $e[3], red = $e[2];
			cssColorValue = "rgb(" + red + "," + green + "," + blue + ")";
			break;
		case 1:
			var alpha = $e[5], blue = $e[4], green = $e[3], red = $e[2];
			cssColorValue = "rgba(" + red + "," + green + "," + blue + "," + alpha + ")";
			break;
		case 3:
			var value1 = $e[2];
			cssColorValue = this.getColorFromKeyword(value1);
			break;
		case 4:
			cssColorValue = "transparent";
			break;
		}
		return cssColorValue;
	}
	,getCSSLength: function(lengthValue) {
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
	,getCSSPercentValue: function(value) {
		return Std.string(value) + "%";
	}
	,getCSSAngle: function(value) {
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
	,getColorFromKeyword: function(value) {
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
	,getVendorSpecificStyleName: function(nativeStyle,styleName) {
		var vendorSpecificStyleName;
		if(Reflect.hasField(nativeStyle,styleName)) vendorSpecificStyleName = styleName; else {
			var styleNameCap = styleName.charAt(0).toUpperCase();
			var styleNameEnd = styleName.substr(1);
			styleName = styleNameCap + styleNameEnd;
			if(Reflect.field(nativeStyle,"Moz" + styleName) != null) vendorSpecificStyleName = "Moz" + styleName; else if(Reflect.field(nativeStyle,"Webkit" + styleName) != null) vendorSpecificStyleName = "Webkit" + styleName; else if(Reflect.field(nativeStyle,"Ms" + styleName) != null) vendorSpecificStyleName = "Ms" + styleName; else if(Reflect.field(nativeStyle,"O" + styleName) != null) vendorSpecificStyleName = "O" + styleName; else vendorSpecificStyleName = null;
		}
		return vendorSpecificStyleName;
	}
	,setVerticalAlign: function(value) {
		this._htmlElement.get_nativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
		core.style.AbstractStyle.prototype.setVerticalAlign.call(this,value);
		return this._verticalAlign = value;
	}
	,setColor: function(value) {
		this._htmlElement.get_nativeElement().style.color = this.getCSSColor(value);
		core.style.AbstractStyle.prototype.setColor.call(this,value);
		return this._color = value;
	}
	,setWordSpacing: function(value) {
		this._htmlElement.get_nativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
		core.style.AbstractStyle.prototype.setWordSpacing.call(this,value);
		return this._wordSpacing = value;
	}
	,setLetterSpacing: function(value) {
		this._htmlElement.get_nativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
		core.style.AbstractStyle.prototype.setLetterSpacing.call(this,value);
		return this._letterSpacing = value;
	}
	,setTextTransform: function(value) {
		this._htmlElement.get_nativeElement().style.textTransform = this.getCSSTextTransform(value);
		core.style.AbstractStyle.prototype.setTextTransform.call(this,value);
		return this._textTransform = value;
	}
	,setFontVariant: function(value) {
		this._htmlElement.get_nativeElement().style.fontVariant = this.getCSSFontVariant(value);
		core.style.AbstractStyle.prototype.setFontVariant.call(this,value);
		return this._fontVariant = value;
	}
	,setFontFamily: function(value) {
		this._htmlElement.get_nativeElement().style.fontFamily = this.getCSSFontFamily(value);
		core.style.AbstractStyle.prototype.setFontFamily.call(this,value);
		return this._fontFamily = value;
	}
	,setFontWeight: function(value) {
		this._htmlElement.get_nativeElement().style.fontWeight = this.getCSSFontWeight(value);
		core.style.AbstractStyle.prototype.setFontWeight.call(this,value);
		return this._fontWeight = value;
	}
	,setFontStyle: function(value) {
		this._htmlElement.get_nativeElement().style.fontStyle = this.getCSSFontStyle(value);
		core.style.AbstractStyle.prototype.setFontStyle.call(this,value);
		return this._fontStyle = value;
	}
	,setFontSize: function(value) {
		this._htmlElement.get_nativeElement().style.fontSize = this.getCSSFontSize(value);
		core.style.AbstractStyle.prototype.setFontSize.call(this,value);
		return this._fontSize = value;
	}
	,setLineHeight: function(value) {
		this._htmlElement.get_nativeElement().style.lineHeight = this.getCSSLineHeight(value);
		core.style.AbstractStyle.prototype.setLineHeight.call(this,value);
		return this._lineHeight = value;
	}
	,setMarginLeft: function(value) {
		this._htmlElement.get_nativeElement().style.marginLeft = this.getCSSMargin(value);
		core.style.AbstractStyle.prototype.setMarginLeft.call(this,value);
		return this._marginLeft = value;
	}
	,setMarginRight: function(value) {
		this._htmlElement.get_nativeElement().style.marginRight = this.getCSSMargin(value);
		core.style.AbstractStyle.prototype.setMarginRight.call(this,value);
		return this._marginRight = value;
	}
	,setMarginTop: function(value) {
		this._htmlElement.get_nativeElement().style.marginTop = this.getCSSMargin(value);
		core.style.AbstractStyle.prototype.setMarginTop.call(this,value);
		return this._marginTop = value;
	}
	,setMarginBottom: function(value) {
		this._htmlElement.get_nativeElement().style.marginBottom = this.getCSSMargin(value);
		core.style.AbstractStyle.prototype.setMarginBottom.call(this,value);
		return this._marginBottom = value;
	}
	,setPaddingLeft: function(value) {
		this._htmlElement.get_nativeElement().style.paddingLeft = this.getCSSPadding(value);
		core.style.AbstractStyle.prototype.setPaddingLeft.call(this,value);
		return this._paddingLeft = value;
	}
	,setPaddingRight: function(value) {
		this._htmlElement.get_nativeElement().style.paddingRight = this.getCSSPadding(value);
		core.style.AbstractStyle.prototype.setPaddingRight.call(this,value);
		return this._paddingRight = value;
	}
	,setPaddingTop: function(value) {
		this._htmlElement.get_nativeElement().style.paddingTop = this.getCSSPadding(value);
		core.style.AbstractStyle.prototype.setPaddingTop.call(this,value);
		return this._paddingTop = value;
	}
	,setPaddingBottom: function(value) {
		this._htmlElement.get_nativeElement().style.paddingBottom = this.getCSSPadding(value);
		core.style.AbstractStyle.prototype.setPaddingBottom.call(this,value);
		return this._paddingBottom = value;
	}
	,setDisplay: function(value) {
		this._htmlElement.get_nativeElement().style.display = this.getCSSDisplay(value);
		core.style.AbstractStyle.prototype.setDisplay.call(this,value);
		return this._display = value;
	}
	,setPosition: function(value) {
		this._htmlElement.get_nativeElement().style.position = this.getCSSPosition(value);
		core.style.AbstractStyle.prototype.setPosition.call(this,value);
		return this._position = value;
	}
	,setWidth: function(value) {
		this._htmlElement.get_nativeElement().style.width = this.getCSSDimension(value);
		core.style.AbstractStyle.prototype.setWidth.call(this,value);
		return this._width = value;
	}
	,setHeight: function(value) {
		this._htmlElement.get_nativeElement().style.height = this.getCSSDimension(value);
		core.style.AbstractStyle.prototype.setHeight.call(this,value);
		return this._height = value;
	}
	,setMinHeight: function(value) {
		this._htmlElement.get_nativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
		core.style.AbstractStyle.prototype.setMinHeight.call(this,value);
		return this._minHeight = value;
	}
	,setMaxHeight: function(value) {
		this._htmlElement.get_nativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
		core.style.AbstractStyle.prototype.setMaxHeight.call(this,value);
		return this._maxHeight = value;
	}
	,setMinWidth: function(value) {
		this._htmlElement.get_nativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
		core.style.AbstractStyle.prototype.setMinWidth.call(this,value);
		return this._minWidth = value;
	}
	,setMaxWidth: function(value) {
		this._htmlElement.get_nativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
		core.style.AbstractStyle.prototype.setMaxWidth.call(this,value);
		return this._maxWidth = value;
	}
	,setTop: function(value) {
		this._htmlElement.get_nativeElement().style.top = this.getCSSPositionOffset(value);
		core.style.AbstractStyle.prototype.setTop.call(this,value);
		return this._top = value;
	}
	,setLeft: function(value) {
		this._htmlElement.get_nativeElement().style.left = this.getCSSPositionOffset(value);
		core.style.AbstractStyle.prototype.setLeft.call(this,value);
		return this._left = value;
	}
	,setBottom: function(value) {
		this._htmlElement.get_nativeElement().style.bottom = this.getCSSPositionOffset(value);
		core.style.AbstractStyle.prototype.setBottom.call(this,value);
		return this._bottom = value;
	}
	,setRight: function(value) {
		this._htmlElement.get_nativeElement().style.right = this.getCSSPositionOffset(value);
		core.style.AbstractStyle.prototype.setRight.call(this,value);
		return this._right = value;
	}
	,setTextIndent: function(value) {
		this._htmlElement.get_nativeElement().style.textIndent = this.getCSSTextIndent(value);
		core.style.AbstractStyle.prototype.setTextIndent.call(this,value);
		return this._textIndent = value;
	}
	,setCSSFloat: function(value) {
		this._htmlElement.get_nativeElement().style.cssFloat = this.getCSSFloatAsString(value);
		core.style.AbstractStyle.prototype.setCSSFloat.call(this,value);
		return this._cssFloat = value;
	}
	,setClear: function(value) {
		this._htmlElement.get_nativeElement().style.clear = this.getCSSClear(value);
		core.style.AbstractStyle.prototype.setClear.call(this,value);
		return this._clear = value;
	}
	,setWhiteSpace: function(value) {
		this._htmlElement.get_nativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
		core.style.AbstractStyle.prototype.setWhiteSpace.call(this,value);
		return this._whiteSpace = value;
	}
	,setTextAlign: function(value) {
		this._htmlElement.get_nativeElement().style.textAlign = this.getCSSTextAlign(value);
		core.style.AbstractStyle.prototype.setTextAlign.call(this,value);
		return this._textAlign = value;
	}
	,setOpacity: function(value) {
		this._htmlElement.get_nativeElement().style.opacity = this.getCSSOpacity(value);
		core.style.AbstractStyle.prototype.setOpacity.call(this,value);
		return this._opacity = value;
	}
	,setVisibility: function(value) {
		this._htmlElement.get_nativeElement().style.visibility = this.getCSSVisibility(value);
		core.style.AbstractStyle.prototype.setVisibility.call(this,value);
		return this._visibility = value;
	}
	,setTransformOrigin: function(value) {
		var nativeStyle = this._htmlElement.get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transformOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransformOrigin(value);
		core.style.AbstractStyle.prototype.setTransformOrigin.call(this,value);
		return this._transformOrigin = value;
	}
	,setTransform: function(value) {
		var nativeStyle = this._htmlElement.get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transform");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransform(value);
		core.style.AbstractStyle.prototype.setTransform.call(this,value);
		return this._transform = value;
	}
	,setBackgroundColor: function(value) {
		this._htmlElement.get_nativeElement().style.backgroundColor = this.getCSSBackgroundColor(value);
		core.style.AbstractStyle.prototype.setBackgroundColor.call(this,value);
		return this._backgroundColor;
	}
	,setBackgroundOrigin: function(value) {
		var nativeStyle = this._htmlElement.get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundOrigin(value);
		core.style.AbstractStyle.prototype.setBackgroundOrigin.call(this,value);
		return this._backgroundOrigin;
	}
	,setBackgroundClip: function(value) {
		var nativeStyle = this._htmlElement.get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundClip");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundClip(value);
		core.style.AbstractStyle.prototype.setBackgroundClip.call(this,value);
		return this._backgroundClip;
	}
	,setBackgroundImage: function(value) {
		var cssBackgroundImage = this.getCSSBackgroundImage(value);
		this._htmlElement.get_nativeElement().style.backgroundImage = cssBackgroundImage;
		this._htmlElement.get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-webkit-linear-gradient");
		this._htmlElement.get_nativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-moz-linear-gradient");
		core.style.AbstractStyle.prototype.setBackgroundImage.call(this,value);
		return this._backgroundImage;
	}
	,setBackgroundPosition: function(value) {
		this._htmlElement.get_nativeElement().style.backgroundPosition = this.getCSSBackgroundPosition(value);
		core.style.AbstractStyle.prototype.setBackgroundPosition.call(this,value);
		return this._backgroundPosition;
	}
	,setBackgroundSize: function(value) {
		var nativeStyle = this._htmlElement.get_nativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundSize");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundSize(value);
		core.style.AbstractStyle.prototype.setBackgroundSize.call(this,value);
		return this._backgroundSize;
	}
	,setBackgroundRepeat: function(value) {
		this._htmlElement.get_nativeElement().style.backgroundRepeat = this.getCSSBackgroundRepeat(value);
		core.style.AbstractStyle.prototype.setBackgroundRepeat.call(this,value);
		return this._backgroundRepeat;
	}
	,setOverflowX: function(value) {
		this._htmlElement.get_nativeElement().style.overflowX = this.getCSSOverflow(value);
		core.style.AbstractStyle.prototype.setOverflowX.call(this,value);
		return this._overflowX = value;
	}
	,setOverflowY: function(value) {
		this._htmlElement.get_nativeElement().style.overflowY = this.getCSSOverflow(value);
		core.style.AbstractStyle.prototype.setOverflowY.call(this,value);
		return this._overflowY = value;
	}
	,setCursor: function(value) {
		this._htmlElement.get_nativeElement().style.cursor = this.getCSSCursor(value);
		core.style.AbstractStyle.prototype.setCursor.call(this,value);
		return this._cursor = value;
	}
	,__class__: port.browser.Style
});
core.style.AbstractEmbeddedStyle = $hxClasses["core.style.AbstractEmbeddedStyle"] = function(htmlElement) {
	port.browser.Style.call(this,htmlElement);
}
core.style.AbstractEmbeddedStyle.__name__ = ["core","style","AbstractEmbeddedStyle"];
core.style.AbstractEmbeddedStyle.__super__ = port.browser.Style;
core.style.AbstractEmbeddedStyle.prototype = $extend(port.browser.Style.prototype,{
	__class__: core.style.AbstractEmbeddedStyle
});
core.event.Event = $hxClasses["core.event.Event"] = function(type,target) {
	this._type = type;
	this._target = target;
}
core.event.Event.__name__ = ["core","event","Event"];
core.event.Event.prototype = {
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
	,__class__: core.event.Event
	,__properties__: {get_defaultPrevented:"get_defaultPrevented",get_target:"get_target",get_type:"get_type"}
}
core.event.UIEvent = $hxClasses["core.event.UIEvent"] = function(type,target,detail) {
	this._detail = detail;
	core.event.Event.call(this,type,target);
}
core.event.UIEvent.__name__ = ["core","event","UIEvent"];
core.event.UIEvent.__super__ = core.event.Event;
core.event.UIEvent.prototype = $extend(core.event.Event.prototype,{
	_detail: null
	,detail: null
	,get_detail: function() {
		return this._detail;
	}
	,set_detail: function(value) {
		return this._detail = value;
	}
	,__class__: core.event.UIEvent
	,__properties__: $extend(core.event.Event.prototype.__properties__,{set_detail:"set_detail",get_detail:"get_detail"})
});
core.event.KeyboardEvent = $hxClasses["core.event.KeyboardEvent"] = function(type,target,detail,$char,key,ctrlKey,shiftKey,altKey) {
	core.event.UIEvent.call(this,type,target,detail);
	this._char = $char;
	this._key = key;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
}
core.event.KeyboardEvent.__name__ = ["core","event","KeyboardEvent"];
core.event.KeyboardEvent.__super__ = core.event.UIEvent;
core.event.KeyboardEvent.prototype = $extend(core.event.UIEvent.prototype,{
	_char: null
	,'char': null
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
	,get_char: function() {
		return this._char;
	}
	,get_key: function() {
		return this._key;
	}
	,__class__: core.event.KeyboardEvent
	,__properties__: $extend(core.event.UIEvent.prototype.__properties__,{get_altKey:"get_altKey",get_shiftKey:"get_shiftKey",get_ctrlKey:"get_ctrlKey",get_key:"get_key",get_char:"get_char"})
});
if(!core.renderer) core.renderer = {}
core.renderer.ElementRenderer = $hxClasses["core.renderer.ElementRenderer"] = function(style) {
	core.dom.Node.call(this);
	this._style = style;
	this._bounds = { x : 0.0, y : 0.0, width : 0.0, height : 0.0};
}
core.renderer.ElementRenderer.__name__ = ["core","renderer","ElementRenderer"];
core.renderer.ElementRenderer.__super__ = core.dom.Node;
core.renderer.ElementRenderer.prototype = $extend(core.dom.Node.prototype,{
	_bounds: null
	,bounds: null
	,_style: null
	,style: null
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
		this._style = null;
		this._layerRenderer = null;
	}
	,establishesNewFormattingContext: function() {
		return false;
	}
	,canHaveChildren: function() {
		return false;
	}
	,isFloat: function() {
		return this._style.isFloat();
	}
	,isPositioned: function() {
		return this._style.isPositioned();
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
	,setLayerRenderer: function(value) {
		return this._layerRenderer = value;
	}
	,getLayerRenderer: function() {
		return this._layerRenderer;
	}
	,getStyle: function() {
		return this._style;
	}
	,getBounds: function() {
		return this._bounds;
	}
	,setBounds: function(value) {
		return this._bounds = value;
	}
	,__class__: core.renderer.ElementRenderer
	,__properties__: $extend(core.dom.Node.prototype.__properties__,{set_layerRenderer:"setLayerRenderer",get_layerRenderer:"getLayerRenderer",get_style:"getStyle",set_bounds:"setBounds",get_bounds:"getBounds"})
});
core.renderer.BoxRenderer = $hxClasses["core.renderer.BoxRenderer"] = function(style) {
	core.renderer.ElementRenderer.call(this,style);
	this.init();
}
core.renderer.BoxRenderer.__name__ = ["core","renderer","BoxRenderer"];
core.renderer.BoxRenderer.__super__ = core.renderer.ElementRenderer;
core.renderer.BoxRenderer.prototype = $extend(core.renderer.ElementRenderer.prototype,{
	_backgroundManager: null
	,init: function() {
		this._backgroundManager = new core.background.BackgroundManager();
	}
	,dispose: function() {
		core.renderer.ElementRenderer.prototype.dispose.call(this);
		this._backgroundManager.dispose();
		this._backgroundManager = null;
	}
	,renderBackground: function() {
		var backgrounds = this._backgroundManager.render(this._bounds,this._style);
		var _g1 = 0, _g = backgrounds.length;
		while(_g1 < _g) {
			var i = _g1++;
		}
		return backgrounds;
	}
	,__class__: core.renderer.BoxRenderer
});
core.renderer.FlowBoxRenderer = $hxClasses["core.renderer.FlowBoxRenderer"] = function(style) {
	core.renderer.BoxRenderer.call(this,style);
}
core.renderer.FlowBoxRenderer.__name__ = ["core","renderer","FlowBoxRenderer"];
core.renderer.FlowBoxRenderer.__super__ = core.renderer.BoxRenderer;
core.renderer.FlowBoxRenderer.prototype = $extend(core.renderer.BoxRenderer.prototype,{
	dispose: function() {
		core.renderer.BoxRenderer.prototype.dispose.call(this);
		var _g1 = 0, _g = this._childNodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = this._childNodes[i];
			child.dispose();
		}
		this._childNodes = null;
	}
	,establishesNewFormattingContext: function() {
		return this._style.establishesNewFormattingContext();
	}
	,isEmbedded: function() {
		return false;
	}
	,canHaveChildren: function() {
		return true;
	}
	,__class__: core.renderer.FlowBoxRenderer
});
core.mouse.AbstractMouseCursor = $hxClasses["core.mouse.AbstractMouseCursor"] = function() {
	this._nativeMouseCursor = core.mouse.MouseCursorValue.cssAuto;
}
core.mouse.AbstractMouseCursor.__name__ = ["core","mouse","AbstractMouseCursor"];
core.mouse.AbstractMouseCursor.prototype = {
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
	,__class__: core.mouse.AbstractMouseCursor
	,__properties__: {set_nativeMouseCursor:"setNativeMouseCursor",get_nativeMouseCursor:"getNativeMouseCursor"}
}
port.browser.MouseCursor = $hxClasses["port.browser.MouseCursor"] = function() {
	core.mouse.AbstractMouseCursor.call(this);
}
port.browser.MouseCursor.__name__ = ["port","browser","MouseCursor"];
port.browser.MouseCursor.__super__ = core.mouse.AbstractMouseCursor;
port.browser.MouseCursor.prototype = $extend(core.mouse.AbstractMouseCursor.prototype,{
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
	,__class__: port.browser.MouseCursor
});
core.nativeElement.AbstractNativeElementCreator = $hxClasses["core.nativeElement.AbstractNativeElementCreator"] = function() {
}
core.nativeElement.AbstractNativeElementCreator.__name__ = ["core","nativeElement","AbstractNativeElementCreator"];
core.nativeElement.AbstractNativeElementCreator.prototype = {
	createNativeElement: function(nativeElementType) {
		return null;
	}
	,__class__: core.nativeElement.AbstractNativeElementCreator
}
if(!core.style.computer) core.style.computer = {}
if(!core.style.computer.boxComputers) core.style.computer.boxComputers = {}
core.style.computer.boxComputers.BoxStylesComputer = $hxClasses["core.style.computer.boxComputers.BoxStylesComputer"] = function() {
}
core.style.computer.boxComputers.BoxStylesComputer.__name__ = ["core","style","computer","boxComputers","BoxStylesComputer"];
core.style.computer.boxComputers.BoxStylesComputer.prototype = {
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
		if(style.getWidth() == core.style.Dimension.cssAuto) this.measureAutoWidth(style,containingHTMLElementData); else this.measureWidth(style,containingHTMLElementData);
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
		if(style.getHeight() == core.style.Dimension.cssAuto) this.measureAutoHeight(style,containingHTMLElementData); else this.measureHeight(style,containingHTMLElementData);
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
		if(style.getMaxWidth() != core.style.ConstrainedDimension.none) {
			if(computedWidth > computedStyle.maxWidth) computedWidth = computedStyle.maxWidth;
		}
		if(computedWidth < computedStyle.minWidth) computedWidth = computedStyle.minWidth;
		return computedWidth;
	}
	,constrainHeight: function(style,computedHeight) {
		var computedStyle = style.getComputedStyle();
		if(style.getMaxHeight() != core.style.ConstrainedDimension.none) {
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
		return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginRight: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingHTMLElementData.width,style.getComputedStyle().width,style.getWidth() == core.style.Dimension.cssAuto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginTop: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMarginBottom: function(style,containingHTMLElementData) {
		return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingHTMLElementData.height,style.getComputedStyle().height,style.getHeight() == core.style.Dimension.cssAuto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		var computedMargin;
		var $e = (marginStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedMargin = core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isDimensionAuto == true) computedMargin = 0; else computedMargin = Math.round(core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		case 2:
			computedMargin = this.getComputedAutoMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
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
			computedConstraintDimension = core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isContainingDimensionAuto == true) {
				if(isMinConstraint == true) computedConstraintDimension = 0; else computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
			} else computedConstraintDimension = Math.round(core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
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
			computedPositionOffset = core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPositionOffset = Math.round(core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
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
			computedDimensions = core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedDimensions = Math.round(core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
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
			computedPaddingValue = core.unit.UnitManager.getPixelFromLength(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPaddingValue = Math.round(core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementDimension));
			break;
		}
		return computedPaddingValue;
	}
	,__class__: core.style.computer.boxComputers.BoxStylesComputer
}
core.style.computer.boxComputers.InlineBlockBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.InlineBlockBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
core.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = core.style.computer.boxComputers.BoxStylesComputer;
core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,shrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < containingHTMLElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingHTMLElementData.width;
		return shrinkedWidth;
	}
	,__class__: core.style.computer.boxComputers.InlineBlockBoxStylesComputer
});
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
core.style.computer.boxComputers.FloatBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.FloatBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
}
core.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","FloatBoxStylesComputer"];
core.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
core.style.computer.boxComputers.FloatBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype,{
	getComputedAutoWidth: function(style,containingHTMLElementData) {
		return 0;
	}
	,__class__: core.style.computer.boxComputers.FloatBoxStylesComputer
});
if(!core.resource) core.resource = {}
core.resource.XMLHTTPRequest = $hxClasses["core.resource.XMLHTTPRequest"] = function() {
	this._http = new haxe.Http("");
	this._http.onData = this.onHTTPData.$bind(this);
	this._http.onStatus = this.onHTTPStatus.$bind(this);
	this._http.onError = this.onHTTPError.$bind(this);
	this.setReadyState(0);
}
core.resource.XMLHTTPRequest.__name__ = ["core","resource","XMLHTTPRequest"];
core.resource.XMLHTTPRequest.__interfaces__ = [core.event.IEventTarget];
core.resource.XMLHTTPRequest.prototype = {
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
		if(this.onReadyStateChange != null) this.onReadyStateChange(new core.event.Event("readystatechange",this));
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
	,__class__: core.resource.XMLHTTPRequest
	,__properties__: {get_status:"get_status",get_responseText:"get_responseText",get_readyState:"get_readyState"}
}
core.style.AbstractContainerStyle = $hxClasses["core.style.AbstractContainerStyle"] = function(htmlElement) {
	port.browser.Style.call(this,htmlElement);
}
core.style.AbstractContainerStyle.__name__ = ["core","style","AbstractContainerStyle"];
core.style.AbstractContainerStyle.__super__ = port.browser.Style;
core.style.AbstractContainerStyle.prototype = $extend(port.browser.Style.prototype,{
	createElementRenderer: function(parentElementRenderer) {
		var elementRenderer;
		if(this.isInlineLevel() == true && this.establishesNewFormattingContext() == false) elementRenderer = new core.renderer.InlineBoxRenderer(this); else elementRenderer = new core.renderer.BlockBoxRenderer(this);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		parentElementRenderer.appendChild(elementRenderer);
		return elementRenderer;
	}
	,layout: function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
		this.flow(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,null,null,null);
	}
	,flowChildren: function(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext) {
		var _g1 = 0, _g = this._htmlElement.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isElementNode(this._htmlElement.get_childNodes()[i]) == true) {
				var childHTMLElement = this._htmlElement.get_childNodes()[i];
				childHTMLElement.get_style().computeDisplayStyles();
			}
		}
		var childrenFormattingContext = this.getformattingContext(formattingContext);
		var childrenContainingHTMLElementData = this.getContainerHTMLElementData();
		var childrenContainingHTMLElementFontMetricsData = this.getFontMetricsData();
		var childLastPositionedHTMLElementData;
		childLastPositionedHTMLElementData = this.getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		childrenFormattingContext = this.doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext);
		if(this._width == core.style.Dimension.cssAuto) this.shrinkToFitIfNeeded(containingHTMLElementData,childrenFormattingContext.getMaxWidth(),formattingContext,lastPositionedHTMLElementData,viewportData);
		if(this._height == core.style.Dimension.cssAuto) {
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
			if(this.isElementNode(this._htmlElement.get_childNodes()[i]) == true) {
				var childHTMLElement = this._htmlElement.get_childNodes()[i];
				childHTMLElement.get_style().flow(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext,this._elementRenderer);
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
			positionedHTMLElementData.style.positionElement(childLastPositionedHTMLElementData.data,viewportData,positionedHTMLElementData.staticPosition);
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
		if(this.isFloat() == true) boxComputer = new core.style.computer.boxComputers.FloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new core.style.computer.boxComputers.PositionedBoxStylesComputer(); else {
			switch( (this._computedStyle.display)[1] ) {
			case 0:
				boxComputer = new core.style.computer.boxComputers.BlockBoxStylesComputer();
				break;
			case 1:
				boxComputer = new core.style.computer.boxComputers.InlineBlockBoxStylesComputer();
				break;
			case 3:
				boxComputer = null;
				break;
			case 2:
				boxComputer = new core.style.computer.boxComputers.InLineBoxStylesComputer();
				break;
			}
		}
		return boxComputer;
	}
	,getTextRenderer: function(textFragmentData,text) {
		var textRenderer;
		textRenderer = this.createTextRenderer(text,textFragmentData.textToken);
		textRenderer.setLayerRenderer(this._elementRenderer.getLayerRenderer());
		textFragmentData.textRenderer = textRenderer;
		return textRenderer;
	}
	,createTextRenderer: function(text,textToken) {
		return this.doCreateTextRenderer(text,textToken);
	}
	,doCreateTextRenderer: function(text,textToken) {
		return null;
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
		return { width : this._computedStyle.width, isWidthAuto : this._width == core.style.Dimension.cssAuto, height : height, isHeightAuto : this._height == core.style.Dimension.cssAuto};
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
			if(this.childrenInline() == true) formattingContext = new core.style.formatter.InlineFormattingContext(formattingContextRoot); else formattingContext = new core.style.formatter.BlockFormattingContext(formattingContextRoot);
		} else formattingContext = previousformattingContext;
		return formattingContext;
	}
	,isChildInline: function(child) {
		var ret = true;
		if(this.isElementNode(child)) {
			var childHTMLElement = child;
			if(childHTMLElement.get_style().getComputedStyle().display == core.style.Display.block) {
				if(childHTMLElement.get_style().isFloat() == false) ret = false; else if(childHTMLElement.get_style().isPositioned() == false || childHTMLElement.get_style().isRelativePositioned() == true) ret = false;
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
	,isElementNode: function(node) {
		var ret = false;
		switch( (node.get_nodeType())[1] ) {
		case 0:
			ret = true;
			break;
		case 1:
		case 2:
			ret = false;
			break;
		}
		return ret;
	}
	,__class__: core.style.AbstractContainerStyle
});
core.style.computer.boxComputers.InLineBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.InLineBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
core.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","InLineBoxStylesComputer"];
core.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = core.style.computer.boxComputers.BoxStylesComputer;
core.style.computer.boxComputers.InLineBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.BoxStylesComputer.prototype,{
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
	,__class__: core.style.computer.boxComputers.InLineBoxStylesComputer
});
core.html.HTMLBodyElement = $hxClasses["core.html.HTMLBodyElement"] = function() {
	port.browser.HTMLElement.call(this,"body");
}
core.html.HTMLBodyElement.__name__ = ["core","html","HTMLBodyElement"];
core.html.HTMLBodyElement.__super__ = port.browser.HTMLElement;
core.html.HTMLBodyElement.prototype = $extend(port.browser.HTMLElement.prototype,{
	initNativeElement: function() {
		this._nativeElement = core.nativeElement.NativeElementManager.getRoot();
	}
	,initStyle: function() {
		this._style = new port.browser.BodyStyle(this);
	}
	,__class__: core.html.HTMLBodyElement
});
core.style.positioner.FixedPositioner = $hxClasses["core.style.positioner.FixedPositioner"] = function() {
	core.style.positioner.BoxPositioner.call(this);
}
core.style.positioner.FixedPositioner.__name__ = ["core","style","positioner","FixedPositioner"];
core.style.positioner.FixedPositioner.__super__ = core.style.positioner.BoxPositioner;
core.style.positioner.FixedPositioner.prototype = $extend(core.style.positioner.BoxPositioner.prototype,{
	__class__: core.style.positioner.FixedPositioner
});
cocktailCore.focus.FocusManager = $hxClasses["cocktailCore.focus.FocusManager"] = function() {
	this._focusManagerImpl = new cocktailCore.focus.js.FocusManagerImpl();
}
cocktailCore.focus.FocusManager.__name__ = ["cocktailCore","focus","FocusManager"];
cocktailCore.focus.FocusManager._instance = null;
cocktailCore.focus.FocusManager.getInstance = function() {
	if(cocktailCore.focus.FocusManager._instance == null) cocktailCore.focus.FocusManager._instance = new cocktailCore.focus.FocusManager();
	return cocktailCore.focus.FocusManager._instance;
}
cocktailCore.focus.FocusManager.prototype = {
	bodyElement: null
	,activeElement: null
	,_focusManagerImpl: null
	,invalidate: function() {
		this._focusManagerImpl.invalidate();
	}
	,setActiveElement: function(value) {
		return this._focusManagerImpl.setActiveElement(value);
	}
	,getActiveElement: function() {
		return this._focusManagerImpl.getActiveElement();
	}
	,setBodyElement: function(value) {
		return this._focusManagerImpl.setBodyElement(value);
	}
	,getBodyElement: function() {
		return this._focusManagerImpl.getBodyElement();
	}
	,__class__: cocktailCore.focus.FocusManager
	,__properties__: {set_activeElement:"setActiveElement",get_activeElement:"getActiveElement",set_bodyElement:"setBodyElement",get_bodyElement:"getBodyElement"}
}
core.resource.AbstractResourceLoader = $hxClasses["core.resource.AbstractResourceLoader"] = function() {
}
core.resource.AbstractResourceLoader.__name__ = ["core","resource","AbstractResourceLoader"];
core.resource.AbstractResourceLoader.prototype = {
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
	,__class__: core.resource.AbstractResourceLoader
}
core.resource.AbstractMediaLoader = $hxClasses["core.resource.AbstractMediaLoader"] = function(nativeElement) {
	this._nativeElement = nativeElement;
	core.resource.AbstractResourceLoader.call(this);
}
core.resource.AbstractMediaLoader.__name__ = ["core","resource","AbstractMediaLoader"];
core.resource.AbstractMediaLoader.__super__ = core.resource.AbstractResourceLoader;
core.resource.AbstractMediaLoader.prototype = $extend(core.resource.AbstractResourceLoader.prototype,{
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
	,__class__: core.resource.AbstractMediaLoader
	,__properties__: {get_intrinsicRatio:"getIntrinsicRatio",get_intrinsicHeight:"getIntrinsicHeight",get_intrinsicWidth:"getIntrinsicWidth",get_nativeElement:"getNativeElement"}
});
port.browser.MediaLoader = $hxClasses["port.browser.MediaLoader"] = function(nativeElement) {
	core.resource.AbstractMediaLoader.call(this,nativeElement);
}
port.browser.MediaLoader.__name__ = ["port","browser","MediaLoader"];
port.browser.MediaLoader.__super__ = core.resource.AbstractMediaLoader;
port.browser.MediaLoader.prototype = $extend(core.resource.AbstractMediaLoader.prototype,{
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
	,__class__: port.browser.MediaLoader
});
if(!core.window) core.window = {}
core.window.AbstractWindow = $hxClasses["core.window.AbstractWindow"] = function(document) {
	this._document = document;
}
core.window.AbstractWindow.__name__ = ["core","window","AbstractWindow"];
core.window.AbstractWindow.__interfaces__ = [core.event.IEventTarget];
core.window.AbstractWindow.prototype = {
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
	,__class__: core.window.AbstractWindow
	,__properties__: {get_innerWidth:"get_innerWidth",get_innerHeight:"get_innerHeight",get_document:"get_document",set_onResize:"set_onResize",get_onResize:"get_onResize"}
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
port.browser.Window = $hxClasses["port.browser.Window"] = function(document) {
	core.window.AbstractWindow.call(this,document);
}
port.browser.Window.__name__ = ["port","browser","Window"];
port.browser.Window.__super__ = core.window.AbstractWindow;
port.browser.Window.prototype = $extend(core.window.AbstractWindow.prototype,{
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
		if(this._onResize != null) this._onResize(new core.event.Event("resize",this));
	}
	,__class__: port.browser.Window
});
core.style.computer.VisualEffectStylesComputer = $hxClasses["core.style.computer.VisualEffectStylesComputer"] = function() {
}
core.style.computer.VisualEffectStylesComputer.__name__ = ["core","style","computer","VisualEffectStylesComputer"];
core.style.computer.VisualEffectStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.opacity = style.getOpacity();
	computedStyle.visibility = core.style.computer.VisualEffectStylesComputer.getComputedVisibility(style);
	computedStyle.overflowX = style.getOverflowX();
	computedStyle.overflowY = style.getOverflowY();
	computedStyle.transformOrigin = core.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin(style);
	computedStyle.transform = core.style.computer.VisualEffectStylesComputer.getComputedTransform(style);
}
core.style.computer.VisualEffectStylesComputer.getComputedVisibility = function(style) {
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
core.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin = function(style) {
	var x;
	var y;
	var $e = (style.getTransformOrigin().x);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		x = core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		x = core.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		x = core.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		x = core.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		x = core.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var $e = (style.getTransformOrigin().y);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		y = core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		y = core.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		y = core.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		y = core.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		y = core.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var transformOriginPoint = { x : x, y : y};
	return transformOriginPoint;
}
core.style.computer.VisualEffectStylesComputer.getComputedTransform = function(style) {
	var transformFunctions;
	var transformOrigin = style.getComputedStyle().transformOrigin;
	var matrix = new core.geom.Matrix();
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
			matrix.concatenate(new core.geom.Matrix(data));
			break;
		case 7:
			var value = $e[2];
			var angle = Math.round(core.unit.UnitManager.getRadFromAngle(value));
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
			var skewX = core.unit.UnitManager.getRadFromAngle(angleX);
			var skewY = core.unit.UnitManager.getRadFromAngle(angleY);
			matrix.skew(skewX,skewY,transformOrigin);
			break;
		case 8:
			var angleX = $e[2];
			var skewX = core.unit.UnitManager.getRadFromAngle(angleX);
			matrix.skew(skewX,1,transformOrigin);
			break;
		case 9:
			var angleY = $e[2];
			var skewY = core.unit.UnitManager.getRadFromAngle(angleY);
			matrix.skew(1,skewY,transformOrigin);
			break;
		case 1:
			var ty = $e[3], tx = $e[2];
			var translationX = core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			var translationY = core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(translationX,translationY);
			break;
		case 2:
			var tx = $e[2];
			var translationX = core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			matrix.translate(translationX,0.0);
			break;
		case 3:
			var ty = $e[2];
			var translationY = core.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(0.0,translationY);
			break;
		}
	}
	return matrix;
}
core.style.computer.VisualEffectStylesComputer.getComputedTranslation = function(style,translation,percentReference) {
	var computedTranslation;
	var $e = (translation);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedTranslation = core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		computedTranslation = core.unit.UnitManager.getPixelFromPercent(value,percentReference);
		break;
	}
	return computedTranslation;
}
core.style.computer.VisualEffectStylesComputer.prototype = {
	__class__: core.style.computer.VisualEffectStylesComputer
}
core.nativeElement.AbstractNativeElementPathManager = $hxClasses["core.nativeElement.AbstractNativeElementPathManager"] = function() {
}
core.nativeElement.AbstractNativeElementPathManager.__name__ = ["core","nativeElement","AbstractNativeElementPathManager"];
core.nativeElement.AbstractNativeElementPathManager.prototype = {
	getRoot: function() {
		return null;
	}
	,__class__: core.nativeElement.AbstractNativeElementPathManager
}
port.browser.NativeElementPathManager = $hxClasses["port.browser.NativeElementPathManager"] = function() {
	core.nativeElement.AbstractNativeElementPathManager.call(this);
}
port.browser.NativeElementPathManager.__name__ = ["port","browser","NativeElementPathManager"];
port.browser.NativeElementPathManager.__super__ = core.nativeElement.AbstractNativeElementPathManager;
port.browser.NativeElementPathManager.prototype = $extend(core.nativeElement.AbstractNativeElementPathManager.prototype,{
	getRoot: function() {
		return js.Lib.document.body;
	}
	,__class__: port.browser.NativeElementPathManager
});
if(!core.keyboard) core.keyboard = {}
core.keyboard.AbstractKeyboard = $hxClasses["core.keyboard.AbstractKeyboard"] = function(htmlElement) {
	this._htmlElement = htmlElement;
}
core.keyboard.AbstractKeyboard.__name__ = ["core","keyboard","AbstractKeyboard"];
core.keyboard.AbstractKeyboard.prototype = {
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
	,getKeyValue: function(keyCode) {
		var keyboardKeyValue = core.keyboard.KeyboardKeyValue.unknown;
		switch(keyCode) {
		case 65:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.a;
			break;
		case 66:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.b;
			break;
		case 67:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.c;
			break;
		case 68:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.d;
			break;
		case 69:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.e;
			break;
		case 70:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.f;
			break;
		case 71:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.g;
			break;
		case 72:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.h;
			break;
		case 73:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.i;
			break;
		case 74:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.j;
			break;
		case 75:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.k;
			break;
		case 76:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.l;
			break;
		case 77:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.m;
			break;
		case 78:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.n;
			break;
		case 79:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.o;
			break;
		case 80:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.p;
			break;
		case 81:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.q;
			break;
		case 82:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.r;
			break;
		case 83:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.s;
			break;
		case 84:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.t;
			break;
		case 85:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.u;
			break;
		case 86:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.v;
			break;
		case 87:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.w;
			break;
		case 88:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.x;
			break;
		case 89:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.y;
			break;
		case 90:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.z;
			break;
		case 8:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.backSpace;
			break;
		case 20:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.capsLock;
			break;
		case 17:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.control;
			break;
		case 46:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.del;
			break;
		case 40:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.down;
			break;
		case 35:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.end;
			break;
		case 13:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.enter;
			break;
		case 27:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.escape;
			break;
		case 112:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F1;
			break;
		case 121:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F10;
			break;
		case 122:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F11;
			break;
		case 123:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F12;
			break;
		case 124:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F13;
			break;
		case 125:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F14;
			break;
		case 126:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F15;
			break;
		case 113:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F2;
			break;
		case 114:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F3;
			break;
		case 115:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F4;
			break;
		case 116:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F5;
			break;
		case 117:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F6;
			break;
		case 118:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F7;
			break;
		case 119:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F8;
			break;
		case 120:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.F9;
			break;
		case 36:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.home;
			break;
		case 45:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.insert;
			break;
		case 37:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.left;
			break;
		case 96:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad0;
			break;
		case 97:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad1;
			break;
		case 98:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad2;
			break;
		case 99:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad3;
			break;
		case 100:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad4;
			break;
		case 101:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad5;
			break;
		case 102:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad6;
			break;
		case 103:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad7;
			break;
		case 104:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad8;
			break;
		case 105:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpad9;
			break;
		case 107:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadAdd;
			break;
		case 108:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadEnter;
			break;
		case 110:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadDecimal;
			break;
		case 111:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadDivide;
			break;
		case 106:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadMultiply;
			break;
		case 109:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.numpadSubstract;
			break;
		case 34:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.pageDown;
			break;
		case 33:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.pageUp;
			break;
		case 39:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.right;
			break;
		case 16:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.shift;
			break;
		case 32:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.space;
			break;
		case 9:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.tab;
			break;
		case 38:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.up;
			break;
		default:
			keyboardKeyValue = core.keyboard.KeyboardKeyValue.unknown;
		}
		return keyboardKeyValue;
	}
	,__class__: core.keyboard.AbstractKeyboard
	,__properties__: {set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown"}
}
port.browser.Keyboard = $hxClasses["port.browser.Keyboard"] = function(htmlElement) {
	core.keyboard.AbstractKeyboard.call(this,htmlElement);
	this._keyDownEvent = "keydown";
	this._keyUpEvent = "keyup";
}
port.browser.Keyboard.__name__ = ["port","browser","Keyboard"];
port.browser.Keyboard.__super__ = core.keyboard.AbstractKeyboard;
port.browser.Keyboard.prototype = $extend(core.keyboard.AbstractKeyboard.prototype,{
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
		var keyboardEvent = new core.event.KeyboardEvent(eventType,this._htmlElement,0.0,event.charCode,event.keyCode,event.ctrlKey,event.shiftKey,event.altKey);
		return keyboardEvent;
	}
	,__class__: port.browser.Keyboard
});
core.renderer.TextRenderer = $hxClasses["core.renderer.TextRenderer"] = function(style,nativeElement,textToken) {
	this._textToken = textToken;
	this._nativeElement = nativeElement;
	core.renderer.ElementRenderer.call(this,style);
}
core.renderer.TextRenderer.__name__ = ["core","renderer","TextRenderer"];
core.renderer.TextRenderer.__super__ = core.renderer.ElementRenderer;
core.renderer.TextRenderer.prototype = $extend(core.renderer.ElementRenderer.prototype,{
	_textToken: null
	,_nativeElement: null
	,dispose: function() {
		core.renderer.ElementRenderer.prototype.dispose.call(this);
		this._textToken = null;
		this._nativeElement = null;
	}
	,render: function() {
		var ret = [];
		ret.push(this._nativeElement);
		return ret;
	}
	,getOffsetHeight: function() {
		var ascent = this._style.getFontMetricsData().ascent;
		var descent = this._style.getFontMetricsData().descent;
		var leading = this._style.getComputedStyle().lineHeight - (ascent + descent);
		var leadedAscent = ascent + leading / 2;
		var leadedDescent = descent + leading / 2;
		return Math.round(leadedAscent + leadedDescent);
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
	,__class__: core.renderer.TextRenderer
});
core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = core.style.computer.boxComputers.BoxStylesComputer;
core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	measureAutoWidth: function(style,containingHTMLElementData) {
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingHTMLElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
	}
	,getComputedAutoWidth: function(style,containingHTMLElementData) {
		var ret = 0;
		var embeddedHTMLElement = style.get_htmlElement();
		if(style.getHeight() == core.style.Dimension.cssAuto) {
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
		if(style.getWidth() == core.style.Dimension.cssAuto) {
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
		if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = core.style.computer.boxComputers.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
		return computedMargin;
	}
	,__class__: core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer
});
core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,__class__: core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer
});
core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer
});
if(!cocktailCore.focus.js) cocktailCore.focus.js = {}
cocktailCore.focus.js.FocusManagerImpl = $hxClasses["cocktailCore.focus.js.FocusManagerImpl"] = function() {
	cocktailCore.focus.abstract.AbstractFocusManagerImpl.call(this);
}
cocktailCore.focus.js.FocusManagerImpl.__name__ = ["cocktailCore","focus","js","FocusManagerImpl"];
cocktailCore.focus.js.FocusManagerImpl.__super__ = cocktailCore.focus.abstract.AbstractFocusManagerImpl;
cocktailCore.focus.js.FocusManagerImpl.prototype = $extend(cocktailCore.focus.abstract.AbstractFocusManagerImpl.prototype,{
	initKeyboardListeners: function() {
	}
	,setActiveElement: function(value) {
		return this._activeElement = value;
	}
	,setBodyElement: function(value) {
		return this._bodyElement = value;
	}
	,__class__: cocktailCore.focus.js.FocusManagerImpl
});
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
var Lexa = $hxClasses["Lexa"] = function() { }
Lexa.__name__ = ["Lexa"];
Lexa.main = function() {
	var site = cocktail.Lib.get_document().createElement("div");
	site.get_style().setWidth(core.style.Dimension.percent(30));
	site.get_style().setMarginLeft(site.get_style().setMarginRight(core.style.Margin.cssAuto));
	var title = cocktail.Lib.get_document().createElement("h1");
	title.appendChild(cocktail.Lib.get_document().createTextNode("Cocktail"));
	title.get_style().setColor(core.unit.ColorValue.keyword(core.unit.ColorKeyword.orange));
	title.get_style().setFontSize(core.style.FontSize.length(core.unit.Length.px(48)));
	title.get_style().setTextAlign(core.style.TextAlign.center);
	var subTitle = cocktail.Lib.get_document().createElement("h2");
	subTitle.appendChild(cocktail.Lib.get_document().createTextNode("cross-platform haXe UIs"));
	subTitle.get_style().setFontSize(core.style.FontSize.length(core.unit.Length.px(36)));
	subTitle.get_style().setTextAlign(core.style.TextAlign.center);
	title.get_style().setFontFamily(subTitle.get_style().setFontFamily([core.style.FontFamily.familyName("arial")]));
	var logo = new port.browser.HTMLImageElement();
	logo.set_src("cocktail.jpg");
	logo.get_style().setBackgroundColor(core.unit.ColorValue.keyword(core.unit.ColorKeyword.gray));
	var text = cocktail.Lib.get_document().createElement("p");
	text.appendChild(cocktail.Lib.get_document().createTextNode("Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe."));
	text.get_style().setBackgroundColor(core.unit.ColorValue.keyword(core.unit.ColorKeyword.orange));
	text.get_style().setColor(core.unit.ColorValue.hex("#FFFFFF"));
	text.get_style().setPaddingLeft(text.get_style().setPaddingTop(text.get_style().setPaddingBottom(text.get_style().setPaddingRight(core.style.Padding.length(core.unit.Length.px(10))))));
	var logoContainer = cocktail.Lib.get_document().createElement("a");
	logoContainer.get_style().setTextAlign(core.style.TextAlign.center);
	logoContainer.appendChild(logo);
	logoContainer.get_style().setDisplay(core.style.Display.block);
	logoContainer.set_href("http://www.silexlabs.org/groups/labs/cocktail/");
	site.appendChild(title);
	site.appendChild(subTitle);
	site.appendChild(text);
	site.appendChild(logoContainer);
	cocktail.Lib.get_document().get_body().appendChild(site);
}
Lexa.prototype = {
	__class__: Lexa
}
core.renderer.InlineBoxRenderer = $hxClasses["core.renderer.InlineBoxRenderer"] = function(style) {
	core.renderer.FlowBoxRenderer.call(this,style);
}
core.renderer.InlineBoxRenderer.__name__ = ["core","renderer","InlineBoxRenderer"];
core.renderer.InlineBoxRenderer.__super__ = core.renderer.FlowBoxRenderer;
core.renderer.InlineBoxRenderer.prototype = $extend(core.renderer.FlowBoxRenderer.prototype,{
	render: function() {
		return this.renderBackground();
	}
	,__class__: core.renderer.InlineBoxRenderer
});
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
core.style.AbstractBodyStyle = $hxClasses["core.style.AbstractBodyStyle"] = function(htmlElement) {
	core.style.AbstractContainerStyle.call(this,htmlElement);
	this._nativeElements = new Array();
	this._isDirty = false;
}
core.style.AbstractBodyStyle.__name__ = ["core","style","AbstractBodyStyle"];
core.style.AbstractBodyStyle.__super__ = core.style.AbstractContainerStyle;
core.style.AbstractBodyStyle.prototype = $extend(core.style.AbstractContainerStyle.prototype,{
	_nativeElements: null
	,invalidate: function() {
		if(this._isDirty == false) {
			this._isDirty = true;
			var windowData = this.getWindowData();
			var lastPositionedHTMLElementData = { children : new Array(), data : windowData};
			this.scheduleLayout(windowData,lastPositionedHTMLElementData,windowData);
		}
	}
	,render: function(nativeElement) {
		this._nativeElements = this._elementRenderer.getLayerRenderer().render();
		this._nativeElements.reverse();
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
	,createElementRenderer: function(parentElementRenderer) {
		var elementRenderer = new core.renderer.InitialBlockRenderer(this);
		elementRenderer.setLayerRenderer(new core.renderer.LayerRenderer(elementRenderer));
		return elementRenderer;
	}
	,layout: function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
		this.detachNativeElements(this._nativeElements);
		core.style.AbstractContainerStyle.prototype.layout.call(this,containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData);
		this.render(this._htmlElement.get_nativeElement());
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
	,getformattingContext: function(previousformattingContext) {
		return new core.style.formatter.BlockFormattingContext(this._elementRenderer);
	}
	,establishesNewFormattingContext: function() {
		return true;
	}
	,__class__: core.style.AbstractBodyStyle
});
port.browser.BodyStyle = $hxClasses["port.browser.BodyStyle"] = function(htmlElement) {
	core.style.AbstractBodyStyle.call(this,htmlElement);
}
port.browser.BodyStyle.__name__ = ["port","browser","BodyStyle"];
port.browser.BodyStyle.__super__ = core.style.AbstractBodyStyle;
port.browser.BodyStyle.prototype = $extend(core.style.AbstractBodyStyle.prototype,{
	render: function(nativeElement) {
	}
	,layout: function(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData) {
	}
	,__class__: port.browser.BodyStyle
});
core.style.computer.boxComputers.BlockBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.BlockBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
core.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","BlockBoxStylesComputer"];
core.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = core.style.computer.boxComputers.BoxStylesComputer;
core.style.computer.boxComputers.BlockBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	__class__: core.style.computer.boxComputers.BlockBoxStylesComputer
});
port.browser.NativeElementCreator = $hxClasses["port.browser.NativeElementCreator"] = function() {
	core.nativeElement.AbstractNativeElementCreator.call(this);
}
port.browser.NativeElementCreator.__name__ = ["port","browser","NativeElementCreator"];
port.browser.NativeElementCreator.__super__ = core.nativeElement.AbstractNativeElementCreator;
port.browser.NativeElementCreator.prototype = $extend(core.nativeElement.AbstractNativeElementCreator.prototype,{
	createNativeElement: function(nativeElementType) {
		var nativeElement;
		var $e = (nativeElementType);
		switch( $e[1] ) {
		case 3:
			nativeElement = js.Lib.document.createElement("img");
			break;
		case 2:
			nativeElement = js.Lib.document.createElement("div");
			break;
		case 0:
			nativeElement = js.Lib.document.createElement("div");
			break;
		case 1:
			nativeElement = js.Lib.document.createElement("canvas");
			break;
		case 8:
			var name = $e[2];
			nativeElement = js.Lib.document.createElement(name);
			break;
		case 4:
			nativeElement = js.Lib.document.createElement("script");
			break;
		case 5:
			nativeElement = js.Lib.document.createElement("div");
			break;
		case 6:
			nativeElement = js.Lib.document.createElement("a");
			break;
		case 7:
			nativeElement = js.Lib.document.createElement("input");
			nativeElement.type = "text";
			break;
		}
		return nativeElement;
	}
	,__class__: port.browser.NativeElementCreator
});
core.mouse.MouseCursorValue = $hxClasses["core.mouse.MouseCursorValue"] = { __ename__ : ["core","mouse","MouseCursorValue"], __constructs__ : ["custom","cssAuto","none","native"] }
core.mouse.MouseCursorValue.custom = function(htmlImageElement,hotSpot) { var $x = ["custom",0,htmlImageElement,hotSpot]; $x.__enum__ = core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
core.mouse.MouseCursorValue.cssAuto = ["cssAuto",1];
core.mouse.MouseCursorValue.cssAuto.toString = $estr;
core.mouse.MouseCursorValue.cssAuto.__enum__ = core.mouse.MouseCursorValue;
core.mouse.MouseCursorValue.none = ["none",2];
core.mouse.MouseCursorValue.none.toString = $estr;
core.mouse.MouseCursorValue.none.__enum__ = core.mouse.MouseCursorValue;
core.mouse.MouseCursorValue["native"] = function(nativeOSMouseCursorValue) { var $x = ["native",3,nativeOSMouseCursorValue]; $x.__enum__ = core.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
core.mouse.NativeOSMouseCursorValue = $hxClasses["core.mouse.NativeOSMouseCursorValue"] = { __ename__ : ["core","mouse","NativeOSMouseCursorValue"], __constructs__ : ["pointer","text"] }
core.mouse.NativeOSMouseCursorValue.pointer = ["pointer",0];
core.mouse.NativeOSMouseCursorValue.pointer.toString = $estr;
core.mouse.NativeOSMouseCursorValue.pointer.__enum__ = core.mouse.NativeOSMouseCursorValue;
core.mouse.NativeOSMouseCursorValue.text = ["text",1];
core.mouse.NativeOSMouseCursorValue.text.toString = $estr;
core.mouse.NativeOSMouseCursorValue.text.__enum__ = core.mouse.NativeOSMouseCursorValue;
core.style.positioner.AbsolutePositioner = $hxClasses["core.style.positioner.AbsolutePositioner"] = function() {
	core.style.positioner.BoxPositioner.call(this);
}
core.style.positioner.AbsolutePositioner.__name__ = ["core","style","positioner","AbsolutePositioner"];
core.style.positioner.AbsolutePositioner.__super__ = core.style.positioner.BoxPositioner;
core.style.positioner.AbsolutePositioner.prototype = $extend(core.style.positioner.BoxPositioner.prototype,{
	__class__: core.style.positioner.AbsolutePositioner
});
if(!core.background) core.background = {}
core.background.BackgroundManager = $hxClasses["core.background.BackgroundManager"] = function() {
	this._backgroundDrawingManagers = new Array();
}
core.background.BackgroundManager.__name__ = ["core","background","BackgroundManager"];
core.background.BackgroundManager.prototype = {
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
					var imageDeclaration = { urls : [value1], fallbackColor : core.unit.ColorValue.transparent};
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
				var backgroundColorNativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.graphic);
				this.drawBackgroundColor(style,style.getComputedStyle().backgroundColor,backgroundColorNativeElement,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
				nativeElements.reverse();
				nativeElements.unshift(backgroundColorNativeElement);
			}
		}
		return nativeElements;
	}
	,drawBackgroundImage: function(imageDeclaration,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var backgroundImageNativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.graphic);
		var imageLoader = new core.resource.AbstractImageLoader();
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
		var computedGradientStyles = core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundImageDrawingManager = new core.background.BackgroundDrawingManager(backgroundImageNativeElement,backgroundBox);
		backgroundImageDrawingManager.drawBackgroundImage(loadedBackgroundImage,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		this._backgroundDrawingManagers.push(backgroundImageDrawingManager);
	}
	,onBackgroundImageLoadError: function(error,backgroundColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		this.drawBackgroundColor(style,core.unit.UnitManager.getColorDataFromColorValue(backgroundColor),backgroundImageNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	}
	,drawBackgroundColor: function(style,backgroundColor,backgroundColorNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var computedBackgroundStyles = core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundColorDrawingManager = new core.background.BackgroundDrawingManager(backgroundColorNativeElement,backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor,this.getBackgroundPaintingBox(computedBackgroundStyles.backgroundClip));
		this._backgroundDrawingManagers.push(backgroundColorDrawingManager);
	}
	,drawBackgroundGradient: function(style,gradientValue,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		var computedGradientStyles = core.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var gradientNativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.graphic);
		var backgroundGradientDrawingManager = new core.background.BackgroundDrawingManager(gradientNativeElement,backgroundBox);
		backgroundGradientDrawingManager.drawBackgroundGradient(gradientValue,this.getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),this.getBackgroundPaintingBox(computedGradientStyles.backgroundClip),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		return gradientNativeElement;
	}
	,getBackgroundPaintingBox: function(computedBackgroundBox) {
		return computedBackgroundBox;
	}
	,getBackgroundPositioningBox: function(computedPositioningBox) {
		return computedPositioningBox;
	}
	,__class__: core.background.BackgroundManager
}
core.renderer.EmbeddedBoxRenderer = $hxClasses["core.renderer.EmbeddedBoxRenderer"] = function(style) {
	core.renderer.BoxRenderer.call(this,style);
	this._bounds.width = style.get_htmlElement().get_offsetWidth();
	this._bounds.height = style.get_htmlElement().get_offsetHeight();
}
core.renderer.EmbeddedBoxRenderer.__name__ = ["core","renderer","EmbeddedBoxRenderer"];
core.renderer.EmbeddedBoxRenderer.__super__ = core.renderer.BoxRenderer;
core.renderer.EmbeddedBoxRenderer.prototype = $extend(core.renderer.BoxRenderer.prototype,{
	render: function() {
		var ret = [];
		var embeddedHTMLElement = this._style.get_htmlElement();
		ret.push(embeddedHTMLElement.get_embeddedAsset());
		return ret;
	}
	,__class__: core.renderer.EmbeddedBoxRenderer
});
core.event.MouseEvent = $hxClasses["core.event.MouseEvent"] = function(type,target,detail,screenX,screenY,clientX,clientY,ctrlKey,shiftKey,altKey) {
	core.event.UIEvent.call(this,type,target,detail);
	this._screenX = screenX;
	this._screenY = screenY;
	this._clientX = clientX;
	this._clientY = clientY;
	this._ctrlKey = ctrlKey;
	this._shiftKey = shiftKey;
	this._altKey = altKey;
}
core.event.MouseEvent.__name__ = ["core","event","MouseEvent"];
core.event.MouseEvent.__super__ = core.event.UIEvent;
core.event.MouseEvent.prototype = $extend(core.event.UIEvent.prototype,{
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
	,__class__: core.event.MouseEvent
	,__properties__: $extend(core.event.UIEvent.prototype.__properties__,{get_altKey:"get_altKey",get_shiftKey:"get_shiftKey",get_ctrlKey:"get_ctrlKey",get_clientY:"get_clientY",get_clientX:"get_clientX",get_screenY:"get_screenY",get_screenX:"get_screenX"})
});
core.html.AbstractHTMLAnchorElement = $hxClasses["core.html.AbstractHTMLAnchorElement"] = function() {
	port.browser.HTMLElement.call(this,"a");
	this._target = core.dom.AnchorTarget.self;
}
core.html.AbstractHTMLAnchorElement.__name__ = ["core","html","AbstractHTMLAnchorElement"];
core.html.AbstractHTMLAnchorElement.__super__ = port.browser.HTMLElement;
core.html.AbstractHTMLAnchorElement.prototype = $extend(port.browser.HTMLElement.prototype,{
	_href: null
	,href: null
	,_target: null
	,target: null
	,initNativeElement: function() {
		this._nativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.link);
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
	,openDocument: function() {
	}
	,displayPointerCursor: function() {
		core.mouse.MouseCursorManager.setMouseCursor(core.mouse.MouseCursorValue["native"](core.mouse.NativeOSMouseCursorValue.pointer));
	}
	,hidePointerCursor: function() {
		core.mouse.MouseCursorManager.setMouseCursor(core.mouse.MouseCursorValue.cssAuto);
	}
	,getTargetAsString: function(value) {
		var target;
		switch( (value)[1] ) {
		case 0:
			target = "_blank";
			break;
		case 2:
			target = "_parent";
			break;
		case 1:
			target = "_self";
			break;
		case 3:
			target = "_top";
			break;
		}
		return target;
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
	,__class__: core.html.AbstractHTMLAnchorElement
	,__properties__: $extend(port.browser.HTMLElement.prototype.__properties__,{set_target:"set_target",get_target:"get_target",set_href:"set_href",get_href:"get_href"})
});
core.mouse.AbstractMouse = $hxClasses["core.mouse.AbstractMouse"] = function(htmlElement) {
	this._htmlElement = htmlElement;
}
core.mouse.AbstractMouse.__name__ = ["core","mouse","AbstractMouse"];
core.mouse.AbstractMouse.prototype = {
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
	,__class__: core.mouse.AbstractMouse
	,__properties__: {set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown",set_onClick:"set_onClick",get_onClick:"get_onClick"}
}
core.dom.NodeType = $hxClasses["core.dom.NodeType"] = { __ename__ : ["core","dom","NodeType"], __constructs__ : ["ELEMENT_NODE","TEXT_NODE","DOCUMENT_NODE"] }
core.dom.NodeType.ELEMENT_NODE = ["ELEMENT_NODE",0];
core.dom.NodeType.ELEMENT_NODE.toString = $estr;
core.dom.NodeType.ELEMENT_NODE.__enum__ = core.dom.NodeType;
core.dom.NodeType.TEXT_NODE = ["TEXT_NODE",1];
core.dom.NodeType.TEXT_NODE.toString = $estr;
core.dom.NodeType.TEXT_NODE.__enum__ = core.dom.NodeType;
core.dom.NodeType.DOCUMENT_NODE = ["DOCUMENT_NODE",2];
core.dom.NodeType.DOCUMENT_NODE.toString = $estr;
core.dom.NodeType.DOCUMENT_NODE.__enum__ = core.dom.NodeType;
core.dom.AnchorTarget = $hxClasses["core.dom.AnchorTarget"] = { __ename__ : ["core","dom","AnchorTarget"], __constructs__ : ["blank","self","parent","top"] }
core.dom.AnchorTarget.blank = ["blank",0];
core.dom.AnchorTarget.blank.toString = $estr;
core.dom.AnchorTarget.blank.__enum__ = core.dom.AnchorTarget;
core.dom.AnchorTarget.self = ["self",1];
core.dom.AnchorTarget.self.toString = $estr;
core.dom.AnchorTarget.self.__enum__ = core.dom.AnchorTarget;
core.dom.AnchorTarget.parent = ["parent",2];
core.dom.AnchorTarget.parent.toString = $estr;
core.dom.AnchorTarget.parent.__enum__ = core.dom.AnchorTarget;
core.dom.AnchorTarget.top = ["top",3];
core.dom.AnchorTarget.top.toString = $estr;
core.dom.AnchorTarget.top.__enum__ = core.dom.AnchorTarget;
core.dom.TextTokenValue = $hxClasses["core.dom.TextTokenValue"] = { __ename__ : ["core","dom","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
core.dom.TextTokenValue.word = function(value) { var $x = ["word",0,value]; $x.__enum__ = core.dom.TextTokenValue; $x.toString = $estr; return $x; }
core.dom.TextTokenValue.space = ["space",1];
core.dom.TextTokenValue.space.toString = $estr;
core.dom.TextTokenValue.space.__enum__ = core.dom.TextTokenValue;
core.dom.TextTokenValue.tab = ["tab",2];
core.dom.TextTokenValue.tab.toString = $estr;
core.dom.TextTokenValue.tab.__enum__ = core.dom.TextTokenValue;
core.dom.TextTokenValue.lineFeed = ["lineFeed",3];
core.dom.TextTokenValue.lineFeed.toString = $estr;
core.dom.TextTokenValue.lineFeed.__enum__ = core.dom.TextTokenValue;
core.dom.FillStyleValue = $hxClasses["core.dom.FillStyleValue"] = { __ename__ : ["core","dom","FillStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
core.dom.FillStyleValue.none = ["none",0];
core.dom.FillStyleValue.none.toString = $estr;
core.dom.FillStyleValue.none.__enum__ = core.dom.FillStyleValue;
core.dom.FillStyleValue.monochrome = function(colorStop) { var $x = ["monochrome",1,colorStop]; $x.__enum__ = core.dom.FillStyleValue; $x.toString = $estr; return $x; }
core.dom.FillStyleValue.gradient = function(gradientStyle) { var $x = ["gradient",2,gradientStyle]; $x.__enum__ = core.dom.FillStyleValue; $x.toString = $estr; return $x; }
core.dom.FillStyleValue.bitmap = function(htmlImageElement,repeat) { var $x = ["bitmap",3,htmlImageElement,repeat]; $x.__enum__ = core.dom.FillStyleValue; $x.toString = $estr; return $x; }
core.dom.LineStyleValue = $hxClasses["core.dom.LineStyleValue"] = { __ename__ : ["core","dom","LineStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
core.dom.LineStyleValue.none = ["none",0];
core.dom.LineStyleValue.none.toString = $estr;
core.dom.LineStyleValue.none.__enum__ = core.dom.LineStyleValue;
core.dom.LineStyleValue.monochrome = function(color,lineStyle) { var $x = ["monochrome",1,color,lineStyle]; $x.__enum__ = core.dom.LineStyleValue; $x.toString = $estr; return $x; }
core.dom.LineStyleValue.gradient = function(gradientStyle,lineStyle) { var $x = ["gradient",2,gradientStyle,lineStyle]; $x.__enum__ = core.dom.LineStyleValue; $x.toString = $estr; return $x; }
core.dom.LineStyleValue.bitmap = function(htmlImageElement,lineStyle,repeat) { var $x = ["bitmap",3,htmlImageElement,lineStyle,repeat]; $x.__enum__ = core.dom.LineStyleValue; $x.toString = $estr; return $x; }
core.dom.GradientTypeValue = $hxClasses["core.dom.GradientTypeValue"] = { __ename__ : ["core","dom","GradientTypeValue"], __constructs__ : ["linear","radial"] }
core.dom.GradientTypeValue.linear = ["linear",0];
core.dom.GradientTypeValue.linear.toString = $estr;
core.dom.GradientTypeValue.linear.__enum__ = core.dom.GradientTypeValue;
core.dom.GradientTypeValue.radial = ["radial",1];
core.dom.GradientTypeValue.radial.toString = $estr;
core.dom.GradientTypeValue.radial.__enum__ = core.dom.GradientTypeValue;
core.dom.CapsStyleValue = $hxClasses["core.dom.CapsStyleValue"] = { __ename__ : ["core","dom","CapsStyleValue"], __constructs__ : ["none","square","round"] }
core.dom.CapsStyleValue.none = ["none",0];
core.dom.CapsStyleValue.none.toString = $estr;
core.dom.CapsStyleValue.none.__enum__ = core.dom.CapsStyleValue;
core.dom.CapsStyleValue.square = ["square",1];
core.dom.CapsStyleValue.square.toString = $estr;
core.dom.CapsStyleValue.square.__enum__ = core.dom.CapsStyleValue;
core.dom.CapsStyleValue.round = ["round",2];
core.dom.CapsStyleValue.round.toString = $estr;
core.dom.CapsStyleValue.round.__enum__ = core.dom.CapsStyleValue;
core.dom.JointStyleValue = $hxClasses["core.dom.JointStyleValue"] = { __ename__ : ["core","dom","JointStyleValue"], __constructs__ : ["miter","round","bevel"] }
core.dom.JointStyleValue.miter = ["miter",0];
core.dom.JointStyleValue.miter.toString = $estr;
core.dom.JointStyleValue.miter.__enum__ = core.dom.JointStyleValue;
core.dom.JointStyleValue.round = ["round",1];
core.dom.JointStyleValue.round.toString = $estr;
core.dom.JointStyleValue.round.__enum__ = core.dom.JointStyleValue;
core.dom.JointStyleValue.bevel = ["bevel",2];
core.dom.JointStyleValue.bevel.toString = $estr;
core.dom.JointStyleValue.bevel.__enum__ = core.dom.JointStyleValue;
core.nativeElement.NativeElementTypeValue = $hxClasses["core.nativeElement.NativeElementTypeValue"] = { __ename__ : ["core","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","library","skin","link","textInput","custom"] }
core.nativeElement.NativeElementTypeValue.neutral = ["neutral",0];
core.nativeElement.NativeElementTypeValue.neutral.toString = $estr;
core.nativeElement.NativeElementTypeValue.neutral.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.graphic = ["graphic",1];
core.nativeElement.NativeElementTypeValue.graphic.toString = $estr;
core.nativeElement.NativeElementTypeValue.graphic.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.text = ["text",2];
core.nativeElement.NativeElementTypeValue.text.toString = $estr;
core.nativeElement.NativeElementTypeValue.text.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.image = ["image",3];
core.nativeElement.NativeElementTypeValue.image.toString = $estr;
core.nativeElement.NativeElementTypeValue.image.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.library = ["library",4];
core.nativeElement.NativeElementTypeValue.library.toString = $estr;
core.nativeElement.NativeElementTypeValue.library.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.skin = ["skin",5];
core.nativeElement.NativeElementTypeValue.skin.toString = $estr;
core.nativeElement.NativeElementTypeValue.skin.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.link = ["link",6];
core.nativeElement.NativeElementTypeValue.link.toString = $estr;
core.nativeElement.NativeElementTypeValue.link.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.textInput = ["textInput",7];
core.nativeElement.NativeElementTypeValue.textInput.toString = $estr;
core.nativeElement.NativeElementTypeValue.textInput.__enum__ = core.nativeElement.NativeElementTypeValue;
core.nativeElement.NativeElementTypeValue.custom = function(name) { var $x = ["custom",8,name]; $x.__enum__ = core.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
var StringBuf = $hxClasses["StringBuf"] = function() {
	this.b = new Array();
}
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
core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	measurePositionOffsets: function(style,containingHTMLElementData) {
		this.measureHorizontalPositionOffsets(style,containingHTMLElementData);
		this.measureVerticalPositionOffsets(style,containingHTMLElementData);
	}
	,measureHorizontalPositionOffsets: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getLeft() == core.style.PositionOffset.cssAuto || style.getRight() == core.style.PositionOffset.cssAuto) {
			if(style.getMarginLeft() == core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = 0;
			if(style.getMarginRight() == core.style.Margin.cssAuto) style.getComputedStyle().marginRight = 0;
			if(style.getLeft() == core.style.PositionOffset.cssAuto && style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			} else if(style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		} else {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == core.style.Margin.cssAuto && style.getMarginRight() == core.style.Margin.cssAuto) {
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
			} else if(style.getMarginLeft() == core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight; else if(style.getMarginRight() == core.style.Margin.cssAuto) style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
		}
	}
	,measureVerticalPositionOffsets: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getTop() == core.style.PositionOffset.cssAuto || style.getBottom() == core.style.PositionOffset.cssAuto) {
			if(style.getMarginTop() == core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0;
			if(style.getMarginBottom() == core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0;
			if(style.getTop() == core.style.PositionOffset.cssAuto && style.getBottom() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingHTMLElementData);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().top = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else if(style.getBottom() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			}
		} else {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == core.style.Margin.cssAuto && style.getMarginBottom() == core.style.Margin.cssAuto) {
				var margin = Math.round((containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2);
				var computedMargin = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginTop = 0;
					style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			} else if(style.getMarginTop() == core.style.Margin.cssAuto) style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom; else if(style.getMarginBottom() == core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
		}
	}
	,getComputedStaticLeft: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginLeft;
	}
	,getComputedStaticTop: function(style,containingHTMLElementData) {
		return style.getComputedStyle().marginTop;
	}
	,__class__: core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer
});
core.style.computer.FontAndTextStylesComputer = $hxClasses["core.style.computer.FontAndTextStylesComputer"] = function() {
}
core.style.computer.FontAndTextStylesComputer.__name__ = ["core","style","computer","FontAndTextStylesComputer"];
core.style.computer.FontAndTextStylesComputer.compute = function(style,containingHTMLElementData,containingHTMLElementFontMetricsData) {
	var computedStyle = style.getComputedStyle();
	if(containingHTMLElementFontMetricsData != null) computedStyle.fontSize = core.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,containingHTMLElementFontMetricsData.fontSize,containingHTMLElementFontMetricsData.xHeight); else computedStyle.fontSize = core.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,12.0,10.0);
	computedStyle.lineHeight = core.style.computer.FontAndTextStylesComputer.getComputedLineHeight(style);
	computedStyle.verticalAlign = core.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign(style,containingHTMLElementData,containingHTMLElementFontMetricsData);
	computedStyle.fontWeight = style.getFontWeight();
	computedStyle.fontStyle = style.getFontStyle();
	computedStyle.fontFamily = style.getFontFamily();
	computedStyle.fontVariant = style.getFontVariant();
	computedStyle.textTransform = style.getTextTransform();
	computedStyle.letterSpacing = core.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing(style);
	computedStyle.wordSpacing = core.style.computer.FontAndTextStylesComputer.getComputedWordSpacing(style);
	computedStyle.textIndent = core.style.computer.FontAndTextStylesComputer.getComputedTextIndent(style,containingHTMLElementData);
	computedStyle.whiteSpace = style.getWhiteSpace();
	computedStyle.textAlign = core.style.computer.FontAndTextStylesComputer.getComputedTextAlign(style,computedStyle.whiteSpace);
	computedStyle.color = core.style.computer.FontAndTextStylesComputer.getComputedColor(style);
}
core.style.computer.FontAndTextStylesComputer.getComputedTextIndent = function(style,containingHTMLElementData) {
	var textIndent;
	var $e = (style.getTextIndent());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		textIndent = core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		textIndent = core.unit.UnitManager.getPixelFromPercent(value,containingHTMLElementData.width);
		break;
	}
	return Math.round(textIndent);
}
core.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingHTMLElementData,containingHTMLElementFontMetricsData) {
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
		verticalAlign = core.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().lineHeight));
		break;
	case 9:
		var value = $e[2];
		verticalAlign = core.unit.UnitManager.getPixelFromLength(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
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
core.style.computer.FontAndTextStylesComputer.getComputedTextAlign = function(style,computedWhiteSpace) {
	var textAlign = style.getTextAlign();
	switch( (computedWhiteSpace)[1] ) {
	case 1:
		if(style.getTextAlign() == core.style.TextAlign.justify) textAlign = core.style.TextAlign.left;
		break;
	default:
	}
	return textAlign;
}
core.style.computer.FontAndTextStylesComputer.getComputedColor = function(style) {
	return core.unit.UnitManager.getColorDataFromColorValue(style.getColor());
}
core.style.computer.FontAndTextStylesComputer.getComputedWordSpacing = function(style) {
	var wordSpacing;
	var $e = (style.getWordSpacing());
	switch( $e[1] ) {
	case 0:
		wordSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		wordSpacing = Math.round(core.unit.UnitManager.getPixelFromLength(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	return wordSpacing;
}
core.style.computer.FontAndTextStylesComputer.getComputedLineHeight = function(style) {
	var lineHeight;
	var $e = (style.getLineHeight());
	switch( $e[1] ) {
	case 2:
		var unit = $e[2];
		lineHeight = core.unit.UnitManager.getPixelFromLength(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 0:
		lineHeight = style.getComputedStyle().fontSize * 1.2;
		break;
	case 3:
		var value = $e[2];
		lineHeight = core.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().fontSize));
		break;
	case 1:
		var value = $e[2];
		lineHeight = style.getComputedStyle().fontSize * value;
		break;
	}
	return lineHeight;
}
core.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing = function(style) {
	var letterSpacing;
	var $e = (style.getLetterSpacing());
	switch( $e[1] ) {
	case 0:
		letterSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		letterSpacing = Math.round(core.unit.UnitManager.getPixelFromLength(unit,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	return letterSpacing;
}
core.style.computer.FontAndTextStylesComputer.getComputedFontSize = function(style,parentFontSize,parentXHeight) {
	var fontSize;
	var $e = (style.getFontSize());
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		fontSize = core.unit.UnitManager.getPixelFromLength(unit,parentFontSize,parentXHeight);
		break;
	case 1:
		var percent = $e[2];
		fontSize = core.unit.UnitManager.getPixelFromPercent(percent,Math.round(parentFontSize));
		break;
	case 2:
		var value = $e[2];
		fontSize = core.unit.UnitManager.getFontSizeFromAbsoluteSizeValue(value);
		break;
	case 3:
		var value = $e[2];
		fontSize = core.unit.UnitManager.getFontSizeFromRelativeSizeValue(value,parentFontSize);
		break;
	}
	return fontSize;
}
core.style.computer.FontAndTextStylesComputer.prototype = {
	__class__: core.style.computer.FontAndTextStylesComputer
}
var haxe = haxe || {}
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
port.browser.Text = $hxClasses["port.browser.Text"] = function() {
	core.dom.Text.call(this);
}
port.browser.Text.__name__ = ["port","browser","Text"];
port.browser.Text.__super__ = core.dom.Text;
port.browser.Text.prototype = $extend(core.dom.Text.prototype,{
	set_data: function(value) {
		if(this._nativeElement == null) this._nativeElement = js.Lib.document.createTextNode(value); else this._nativeElement.nodeValue = value;
		core.dom.Text.prototype.set_data.call(this,value);
		return value;
	}
	,__class__: port.browser.Text
});
core.html.EmbeddedElement = $hxClasses["core.html.EmbeddedElement"] = function(tagName) {
	port.browser.HTMLElement.call(this,tagName);
}
core.html.EmbeddedElement.__name__ = ["core","html","EmbeddedElement"];
core.html.EmbeddedElement.__super__ = port.browser.HTMLElement;
core.html.EmbeddedElement.prototype = $extend(port.browser.HTMLElement.prototype,{
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
		port.browser.HTMLElement.prototype.init.call(this);
	}
	,initEmbeddedAsset: function() {
	}
	,initStyle: function() {
		this._style = new core.style.AbstractEmbeddedStyle(this);
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
	,__class__: core.html.EmbeddedElement
	,__properties__: $extend(port.browser.HTMLElement.prototype.__properties__,{get_embeddedAsset:"get_embeddedAsset",set_width:"set_width",get_width:"get_width",set_height:"set_height",get_height:"get_height",get_intrinsicRatio:"get_intrinsicRatio",get_intrinsicWidth:"get_intrinsicWidth",get_intrinsicHeight:"get_intrinsicHeight"})
});
core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer
});
if(!core.unit) core.unit = {}
core.unit.Length = $hxClasses["core.unit.Length"] = { __ename__ : ["core","unit","Length"], __constructs__ : ["px","cm","mm","pt","pc","_in","em","ex"] }
core.unit.Length.px = function(value) { var $x = ["px",0,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.cm = function(value) { var $x = ["cm",1,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.mm = function(value) { var $x = ["mm",2,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.pt = function(value) { var $x = ["pt",3,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.pc = function(value) { var $x = ["pc",4,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length._in = function(value) { var $x = ["_in",5,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.em = function(value) { var $x = ["em",6,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.Length.ex = function(value) { var $x = ["ex",7,value]; $x.__enum__ = core.unit.Length; $x.toString = $estr; return $x; }
core.unit.FontSizeAbsoluteSize = $hxClasses["core.unit.FontSizeAbsoluteSize"] = { __ename__ : ["core","unit","FontSizeAbsoluteSize"], __constructs__ : ["xxSmall","xSmall","small","medium","large","xLarge","xxLarge"] }
core.unit.FontSizeAbsoluteSize.xxSmall = ["xxSmall",0];
core.unit.FontSizeAbsoluteSize.xxSmall.toString = $estr;
core.unit.FontSizeAbsoluteSize.xxSmall.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.xSmall = ["xSmall",1];
core.unit.FontSizeAbsoluteSize.xSmall.toString = $estr;
core.unit.FontSizeAbsoluteSize.xSmall.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.small = ["small",2];
core.unit.FontSizeAbsoluteSize.small.toString = $estr;
core.unit.FontSizeAbsoluteSize.small.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.medium = ["medium",3];
core.unit.FontSizeAbsoluteSize.medium.toString = $estr;
core.unit.FontSizeAbsoluteSize.medium.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.large = ["large",4];
core.unit.FontSizeAbsoluteSize.large.toString = $estr;
core.unit.FontSizeAbsoluteSize.large.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.xLarge = ["xLarge",5];
core.unit.FontSizeAbsoluteSize.xLarge.toString = $estr;
core.unit.FontSizeAbsoluteSize.xLarge.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeAbsoluteSize.xxLarge = ["xxLarge",6];
core.unit.FontSizeAbsoluteSize.xxLarge.toString = $estr;
core.unit.FontSizeAbsoluteSize.xxLarge.__enum__ = core.unit.FontSizeAbsoluteSize;
core.unit.FontSizeRelativeSize = $hxClasses["core.unit.FontSizeRelativeSize"] = { __ename__ : ["core","unit","FontSizeRelativeSize"], __constructs__ : ["larger","smaller"] }
core.unit.FontSizeRelativeSize.larger = ["larger",0];
core.unit.FontSizeRelativeSize.larger.toString = $estr;
core.unit.FontSizeRelativeSize.larger.__enum__ = core.unit.FontSizeRelativeSize;
core.unit.FontSizeRelativeSize.smaller = ["smaller",1];
core.unit.FontSizeRelativeSize.smaller.toString = $estr;
core.unit.FontSizeRelativeSize.smaller.__enum__ = core.unit.FontSizeRelativeSize;
core.unit.ColorValue = $hxClasses["core.unit.ColorValue"] = { __ename__ : ["core","unit","ColorValue"], __constructs__ : ["rgb","rgba","hex","keyword","transparent"] }
core.unit.ColorValue.rgb = function(red,green,blue) { var $x = ["rgb",0,red,green,blue]; $x.__enum__ = core.unit.ColorValue; $x.toString = $estr; return $x; }
core.unit.ColorValue.rgba = function(red,green,blue,alpha) { var $x = ["rgba",1,red,green,blue,alpha]; $x.__enum__ = core.unit.ColorValue; $x.toString = $estr; return $x; }
core.unit.ColorValue.hex = function(value) { var $x = ["hex",2,value]; $x.__enum__ = core.unit.ColorValue; $x.toString = $estr; return $x; }
core.unit.ColorValue.keyword = function(value) { var $x = ["keyword",3,value]; $x.__enum__ = core.unit.ColorValue; $x.toString = $estr; return $x; }
core.unit.ColorValue.transparent = ["transparent",4];
core.unit.ColorValue.transparent.toString = $estr;
core.unit.ColorValue.transparent.__enum__ = core.unit.ColorValue;
core.unit.ImageValue = $hxClasses["core.unit.ImageValue"] = { __ename__ : ["core","unit","ImageValue"], __constructs__ : ["url","imageList","gradient"] }
core.unit.ImageValue.url = function(value) { var $x = ["url",0,value]; $x.__enum__ = core.unit.ImageValue; $x.toString = $estr; return $x; }
core.unit.ImageValue.imageList = function(value) { var $x = ["imageList",1,value]; $x.__enum__ = core.unit.ImageValue; $x.toString = $estr; return $x; }
core.unit.ImageValue.gradient = function(value) { var $x = ["gradient",2,value]; $x.__enum__ = core.unit.ImageValue; $x.toString = $estr; return $x; }
core.unit.GradientValue = $hxClasses["core.unit.GradientValue"] = { __ename__ : ["core","unit","GradientValue"], __constructs__ : ["linear"] }
core.unit.GradientValue.linear = function(value) { var $x = ["linear",0,value]; $x.__enum__ = core.unit.GradientValue; $x.toString = $estr; return $x; }
core.unit.GradientStopValue = $hxClasses["core.unit.GradientStopValue"] = { __ename__ : ["core","unit","GradientStopValue"], __constructs__ : ["length","percent"] }
core.unit.GradientStopValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.unit.GradientStopValue; $x.toString = $estr; return $x; }
core.unit.GradientStopValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.unit.GradientStopValue; $x.toString = $estr; return $x; }
core.unit.GradientAngle = $hxClasses["core.unit.GradientAngle"] = { __ename__ : ["core","unit","GradientAngle"], __constructs__ : ["angle","side","corner"] }
core.unit.GradientAngle.angle = function(value) { var $x = ["angle",0,value]; $x.__enum__ = core.unit.GradientAngle; $x.toString = $estr; return $x; }
core.unit.GradientAngle.side = function(value) { var $x = ["side",1,value]; $x.__enum__ = core.unit.GradientAngle; $x.toString = $estr; return $x; }
core.unit.GradientAngle.corner = function(value) { var $x = ["corner",2,value]; $x.__enum__ = core.unit.GradientAngle; $x.toString = $estr; return $x; }
core.unit.GradientSideValue = $hxClasses["core.unit.GradientSideValue"] = { __ename__ : ["core","unit","GradientSideValue"], __constructs__ : ["top","left","bottom","right"] }
core.unit.GradientSideValue.top = ["top",0];
core.unit.GradientSideValue.top.toString = $estr;
core.unit.GradientSideValue.top.__enum__ = core.unit.GradientSideValue;
core.unit.GradientSideValue.left = ["left",1];
core.unit.GradientSideValue.left.toString = $estr;
core.unit.GradientSideValue.left.__enum__ = core.unit.GradientSideValue;
core.unit.GradientSideValue.bottom = ["bottom",2];
core.unit.GradientSideValue.bottom.toString = $estr;
core.unit.GradientSideValue.bottom.__enum__ = core.unit.GradientSideValue;
core.unit.GradientSideValue.right = ["right",3];
core.unit.GradientSideValue.right.toString = $estr;
core.unit.GradientSideValue.right.__enum__ = core.unit.GradientSideValue;
core.unit.GradientCornerValue = $hxClasses["core.unit.GradientCornerValue"] = { __ename__ : ["core","unit","GradientCornerValue"], __constructs__ : ["topRight","bottomRight","bottomLeft","topLeft"] }
core.unit.GradientCornerValue.topRight = ["topRight",0];
core.unit.GradientCornerValue.topRight.toString = $estr;
core.unit.GradientCornerValue.topRight.__enum__ = core.unit.GradientCornerValue;
core.unit.GradientCornerValue.bottomRight = ["bottomRight",1];
core.unit.GradientCornerValue.bottomRight.toString = $estr;
core.unit.GradientCornerValue.bottomRight.__enum__ = core.unit.GradientCornerValue;
core.unit.GradientCornerValue.bottomLeft = ["bottomLeft",2];
core.unit.GradientCornerValue.bottomLeft.toString = $estr;
core.unit.GradientCornerValue.bottomLeft.__enum__ = core.unit.GradientCornerValue;
core.unit.GradientCornerValue.topLeft = ["topLeft",3];
core.unit.GradientCornerValue.topLeft.toString = $estr;
core.unit.GradientCornerValue.topLeft.__enum__ = core.unit.GradientCornerValue;
core.unit.ColorKeyword = $hxClasses["core.unit.ColorKeyword"] = { __ename__ : ["core","unit","ColorKeyword"], __constructs__ : ["aqua","black","blue","fuchsia","gray","green","lime","maroon","navy","olive","orange","purple","red","silver","teal","white","yellow"] }
core.unit.ColorKeyword.aqua = ["aqua",0];
core.unit.ColorKeyword.aqua.toString = $estr;
core.unit.ColorKeyword.aqua.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.black = ["black",1];
core.unit.ColorKeyword.black.toString = $estr;
core.unit.ColorKeyword.black.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.blue = ["blue",2];
core.unit.ColorKeyword.blue.toString = $estr;
core.unit.ColorKeyword.blue.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.fuchsia = ["fuchsia",3];
core.unit.ColorKeyword.fuchsia.toString = $estr;
core.unit.ColorKeyword.fuchsia.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.gray = ["gray",4];
core.unit.ColorKeyword.gray.toString = $estr;
core.unit.ColorKeyword.gray.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.green = ["green",5];
core.unit.ColorKeyword.green.toString = $estr;
core.unit.ColorKeyword.green.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.lime = ["lime",6];
core.unit.ColorKeyword.lime.toString = $estr;
core.unit.ColorKeyword.lime.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.maroon = ["maroon",7];
core.unit.ColorKeyword.maroon.toString = $estr;
core.unit.ColorKeyword.maroon.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.navy = ["navy",8];
core.unit.ColorKeyword.navy.toString = $estr;
core.unit.ColorKeyword.navy.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.olive = ["olive",9];
core.unit.ColorKeyword.olive.toString = $estr;
core.unit.ColorKeyword.olive.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.orange = ["orange",10];
core.unit.ColorKeyword.orange.toString = $estr;
core.unit.ColorKeyword.orange.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.purple = ["purple",11];
core.unit.ColorKeyword.purple.toString = $estr;
core.unit.ColorKeyword.purple.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.red = ["red",12];
core.unit.ColorKeyword.red.toString = $estr;
core.unit.ColorKeyword.red.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.silver = ["silver",13];
core.unit.ColorKeyword.silver.toString = $estr;
core.unit.ColorKeyword.silver.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.teal = ["teal",14];
core.unit.ColorKeyword.teal.toString = $estr;
core.unit.ColorKeyword.teal.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.white = ["white",15];
core.unit.ColorKeyword.white.toString = $estr;
core.unit.ColorKeyword.white.__enum__ = core.unit.ColorKeyword;
core.unit.ColorKeyword.yellow = ["yellow",16];
core.unit.ColorKeyword.yellow.toString = $estr;
core.unit.ColorKeyword.yellow.__enum__ = core.unit.ColorKeyword;
core.unit.Angle = $hxClasses["core.unit.Angle"] = { __ename__ : ["core","unit","Angle"], __constructs__ : ["deg","grad","rad","turn"] }
core.unit.Angle.deg = function(value) { var $x = ["deg",0,value]; $x.__enum__ = core.unit.Angle; $x.toString = $estr; return $x; }
core.unit.Angle.grad = function(value) { var $x = ["grad",1,value]; $x.__enum__ = core.unit.Angle; $x.toString = $estr; return $x; }
core.unit.Angle.rad = function(value) { var $x = ["rad",2,value]; $x.__enum__ = core.unit.Angle; $x.toString = $estr; return $x; }
core.unit.Angle.turn = function(value) { var $x = ["turn",3,value]; $x.__enum__ = core.unit.Angle; $x.toString = $estr; return $x; }
core.unit.UnitManager = $hxClasses["core.unit.UnitManager"] = function() {
}
core.unit.UnitManager.__name__ = ["core","unit","UnitManager"];
core.unit.UnitManager.getPixelFromLength = function(length,emReference,exReference) {
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
core.unit.UnitManager.getFontSizeFromAbsoluteSizeValue = function(absoluteSize) {
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
core.unit.UnitManager.getFontSizeFromRelativeSizeValue = function(relativeSize,parentFontSize) {
	var fontSize;
	switch( (relativeSize)[1] ) {
	case 0:
		fontSize = core.unit.UnitManager.getLargerFontSize(parentFontSize);
		break;
	case 1:
		fontSize = core.unit.UnitManager.getSmallerFontSize(parentFontSize);
		break;
	}
	return fontSize;
}
core.unit.UnitManager.getPixelFromPercent = function(percent,reference) {
	return reference * (percent * 0.01);
}
core.unit.UnitManager.getPercentFromPixel = function(pixel,reference) {
	return reference / pixel * 100;
}
core.unit.UnitManager.getColorDataFromColorValue = function(value) {
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
		colorValue = core.unit.UnitManager.getColorDataFromColorValueKeyword(value1).color;
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
core.unit.UnitManager.getRadFromAngle = function(value) {
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
core.unit.UnitManager.getDegreeFromAngle = function(value) {
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
core.unit.UnitManager.getColorDataFromColorValueKeyword = function(value) {
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
	return core.unit.UnitManager.getColorDataFromColorValue(core.unit.ColorValue.hex(hexColor));
}
core.unit.UnitManager.getLargerFontSize = function(parentFontSize) {
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
core.unit.UnitManager.getSmallerFontSize = function(parentFontSize) {
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
core.unit.UnitManager.prototype = {
	__class__: core.unit.UnitManager
}
core.keyboard.KeyboardKeyValue = $hxClasses["core.keyboard.KeyboardKeyValue"] = { __ename__ : ["core","keyboard","KeyboardKeyValue"], __constructs__ : ["unknown","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","backSpace","capsLock","control","del","down","end","escape","enter","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","F13","F14","F15","home","insert","left","numpad0","numpad1","numpad2","numpad3","numpad4","numpad5","numpad6","numpad7","numpad8","numpad9","numpadAdd","numpadSpecial","numpadDecimal","numpadDivide","numpadEnter","numpadMultiply","numpadSubstract","pageDown","pageUp","right","shift","space","tab","up"] }
core.keyboard.KeyboardKeyValue.unknown = ["unknown",0];
core.keyboard.KeyboardKeyValue.unknown.toString = $estr;
core.keyboard.KeyboardKeyValue.unknown.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.a = ["a",1];
core.keyboard.KeyboardKeyValue.a.toString = $estr;
core.keyboard.KeyboardKeyValue.a.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.b = ["b",2];
core.keyboard.KeyboardKeyValue.b.toString = $estr;
core.keyboard.KeyboardKeyValue.b.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.c = ["c",3];
core.keyboard.KeyboardKeyValue.c.toString = $estr;
core.keyboard.KeyboardKeyValue.c.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.d = ["d",4];
core.keyboard.KeyboardKeyValue.d.toString = $estr;
core.keyboard.KeyboardKeyValue.d.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.e = ["e",5];
core.keyboard.KeyboardKeyValue.e.toString = $estr;
core.keyboard.KeyboardKeyValue.e.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.f = ["f",6];
core.keyboard.KeyboardKeyValue.f.toString = $estr;
core.keyboard.KeyboardKeyValue.f.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.g = ["g",7];
core.keyboard.KeyboardKeyValue.g.toString = $estr;
core.keyboard.KeyboardKeyValue.g.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.h = ["h",8];
core.keyboard.KeyboardKeyValue.h.toString = $estr;
core.keyboard.KeyboardKeyValue.h.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.i = ["i",9];
core.keyboard.KeyboardKeyValue.i.toString = $estr;
core.keyboard.KeyboardKeyValue.i.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.j = ["j",10];
core.keyboard.KeyboardKeyValue.j.toString = $estr;
core.keyboard.KeyboardKeyValue.j.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.k = ["k",11];
core.keyboard.KeyboardKeyValue.k.toString = $estr;
core.keyboard.KeyboardKeyValue.k.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.l = ["l",12];
core.keyboard.KeyboardKeyValue.l.toString = $estr;
core.keyboard.KeyboardKeyValue.l.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.m = ["m",13];
core.keyboard.KeyboardKeyValue.m.toString = $estr;
core.keyboard.KeyboardKeyValue.m.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.n = ["n",14];
core.keyboard.KeyboardKeyValue.n.toString = $estr;
core.keyboard.KeyboardKeyValue.n.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.o = ["o",15];
core.keyboard.KeyboardKeyValue.o.toString = $estr;
core.keyboard.KeyboardKeyValue.o.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.p = ["p",16];
core.keyboard.KeyboardKeyValue.p.toString = $estr;
core.keyboard.KeyboardKeyValue.p.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.q = ["q",17];
core.keyboard.KeyboardKeyValue.q.toString = $estr;
core.keyboard.KeyboardKeyValue.q.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.r = ["r",18];
core.keyboard.KeyboardKeyValue.r.toString = $estr;
core.keyboard.KeyboardKeyValue.r.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.s = ["s",19];
core.keyboard.KeyboardKeyValue.s.toString = $estr;
core.keyboard.KeyboardKeyValue.s.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.t = ["t",20];
core.keyboard.KeyboardKeyValue.t.toString = $estr;
core.keyboard.KeyboardKeyValue.t.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.u = ["u",21];
core.keyboard.KeyboardKeyValue.u.toString = $estr;
core.keyboard.KeyboardKeyValue.u.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.v = ["v",22];
core.keyboard.KeyboardKeyValue.v.toString = $estr;
core.keyboard.KeyboardKeyValue.v.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.w = ["w",23];
core.keyboard.KeyboardKeyValue.w.toString = $estr;
core.keyboard.KeyboardKeyValue.w.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.x = ["x",24];
core.keyboard.KeyboardKeyValue.x.toString = $estr;
core.keyboard.KeyboardKeyValue.x.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.y = ["y",25];
core.keyboard.KeyboardKeyValue.y.toString = $estr;
core.keyboard.KeyboardKeyValue.y.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.z = ["z",26];
core.keyboard.KeyboardKeyValue.z.toString = $estr;
core.keyboard.KeyboardKeyValue.z.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.backSpace = ["backSpace",27];
core.keyboard.KeyboardKeyValue.backSpace.toString = $estr;
core.keyboard.KeyboardKeyValue.backSpace.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.capsLock = ["capsLock",28];
core.keyboard.KeyboardKeyValue.capsLock.toString = $estr;
core.keyboard.KeyboardKeyValue.capsLock.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.control = ["control",29];
core.keyboard.KeyboardKeyValue.control.toString = $estr;
core.keyboard.KeyboardKeyValue.control.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.del = ["del",30];
core.keyboard.KeyboardKeyValue.del.toString = $estr;
core.keyboard.KeyboardKeyValue.del.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.down = ["down",31];
core.keyboard.KeyboardKeyValue.down.toString = $estr;
core.keyboard.KeyboardKeyValue.down.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.end = ["end",32];
core.keyboard.KeyboardKeyValue.end.toString = $estr;
core.keyboard.KeyboardKeyValue.end.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.escape = ["escape",33];
core.keyboard.KeyboardKeyValue.escape.toString = $estr;
core.keyboard.KeyboardKeyValue.escape.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.enter = ["enter",34];
core.keyboard.KeyboardKeyValue.enter.toString = $estr;
core.keyboard.KeyboardKeyValue.enter.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F1 = ["F1",35];
core.keyboard.KeyboardKeyValue.F1.toString = $estr;
core.keyboard.KeyboardKeyValue.F1.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F2 = ["F2",36];
core.keyboard.KeyboardKeyValue.F2.toString = $estr;
core.keyboard.KeyboardKeyValue.F2.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F3 = ["F3",37];
core.keyboard.KeyboardKeyValue.F3.toString = $estr;
core.keyboard.KeyboardKeyValue.F3.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F4 = ["F4",38];
core.keyboard.KeyboardKeyValue.F4.toString = $estr;
core.keyboard.KeyboardKeyValue.F4.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F5 = ["F5",39];
core.keyboard.KeyboardKeyValue.F5.toString = $estr;
core.keyboard.KeyboardKeyValue.F5.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F6 = ["F6",40];
core.keyboard.KeyboardKeyValue.F6.toString = $estr;
core.keyboard.KeyboardKeyValue.F6.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F7 = ["F7",41];
core.keyboard.KeyboardKeyValue.F7.toString = $estr;
core.keyboard.KeyboardKeyValue.F7.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F8 = ["F8",42];
core.keyboard.KeyboardKeyValue.F8.toString = $estr;
core.keyboard.KeyboardKeyValue.F8.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F9 = ["F9",43];
core.keyboard.KeyboardKeyValue.F9.toString = $estr;
core.keyboard.KeyboardKeyValue.F9.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F10 = ["F10",44];
core.keyboard.KeyboardKeyValue.F10.toString = $estr;
core.keyboard.KeyboardKeyValue.F10.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F11 = ["F11",45];
core.keyboard.KeyboardKeyValue.F11.toString = $estr;
core.keyboard.KeyboardKeyValue.F11.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F12 = ["F12",46];
core.keyboard.KeyboardKeyValue.F12.toString = $estr;
core.keyboard.KeyboardKeyValue.F12.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F13 = ["F13",47];
core.keyboard.KeyboardKeyValue.F13.toString = $estr;
core.keyboard.KeyboardKeyValue.F13.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F14 = ["F14",48];
core.keyboard.KeyboardKeyValue.F14.toString = $estr;
core.keyboard.KeyboardKeyValue.F14.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.F15 = ["F15",49];
core.keyboard.KeyboardKeyValue.F15.toString = $estr;
core.keyboard.KeyboardKeyValue.F15.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.home = ["home",50];
core.keyboard.KeyboardKeyValue.home.toString = $estr;
core.keyboard.KeyboardKeyValue.home.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.insert = ["insert",51];
core.keyboard.KeyboardKeyValue.insert.toString = $estr;
core.keyboard.KeyboardKeyValue.insert.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.left = ["left",52];
core.keyboard.KeyboardKeyValue.left.toString = $estr;
core.keyboard.KeyboardKeyValue.left.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad0 = ["numpad0",53];
core.keyboard.KeyboardKeyValue.numpad0.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad0.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad1 = ["numpad1",54];
core.keyboard.KeyboardKeyValue.numpad1.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad1.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad2 = ["numpad2",55];
core.keyboard.KeyboardKeyValue.numpad2.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad2.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad3 = ["numpad3",56];
core.keyboard.KeyboardKeyValue.numpad3.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad3.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad4 = ["numpad4",57];
core.keyboard.KeyboardKeyValue.numpad4.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad4.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad5 = ["numpad5",58];
core.keyboard.KeyboardKeyValue.numpad5.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad5.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad6 = ["numpad6",59];
core.keyboard.KeyboardKeyValue.numpad6.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad6.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad7 = ["numpad7",60];
core.keyboard.KeyboardKeyValue.numpad7.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad7.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad8 = ["numpad8",61];
core.keyboard.KeyboardKeyValue.numpad8.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad8.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpad9 = ["numpad9",62];
core.keyboard.KeyboardKeyValue.numpad9.toString = $estr;
core.keyboard.KeyboardKeyValue.numpad9.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadAdd = ["numpadAdd",63];
core.keyboard.KeyboardKeyValue.numpadAdd.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadAdd.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadSpecial = ["numpadSpecial",64];
core.keyboard.KeyboardKeyValue.numpadSpecial.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadSpecial.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadDecimal = ["numpadDecimal",65];
core.keyboard.KeyboardKeyValue.numpadDecimal.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadDecimal.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadDivide = ["numpadDivide",66];
core.keyboard.KeyboardKeyValue.numpadDivide.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadDivide.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadEnter = ["numpadEnter",67];
core.keyboard.KeyboardKeyValue.numpadEnter.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadEnter.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadMultiply = ["numpadMultiply",68];
core.keyboard.KeyboardKeyValue.numpadMultiply.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadMultiply.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.numpadSubstract = ["numpadSubstract",69];
core.keyboard.KeyboardKeyValue.numpadSubstract.toString = $estr;
core.keyboard.KeyboardKeyValue.numpadSubstract.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.pageDown = ["pageDown",70];
core.keyboard.KeyboardKeyValue.pageDown.toString = $estr;
core.keyboard.KeyboardKeyValue.pageDown.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.pageUp = ["pageUp",71];
core.keyboard.KeyboardKeyValue.pageUp.toString = $estr;
core.keyboard.KeyboardKeyValue.pageUp.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.right = ["right",72];
core.keyboard.KeyboardKeyValue.right.toString = $estr;
core.keyboard.KeyboardKeyValue.right.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.shift = ["shift",73];
core.keyboard.KeyboardKeyValue.shift.toString = $estr;
core.keyboard.KeyboardKeyValue.shift.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.space = ["space",74];
core.keyboard.KeyboardKeyValue.space.toString = $estr;
core.keyboard.KeyboardKeyValue.space.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.tab = ["tab",75];
core.keyboard.KeyboardKeyValue.tab.toString = $estr;
core.keyboard.KeyboardKeyValue.tab.__enum__ = core.keyboard.KeyboardKeyValue;
core.keyboard.KeyboardKeyValue.up = ["up",76];
core.keyboard.KeyboardKeyValue.up.toString = $estr;
core.keyboard.KeyboardKeyValue.up.__enum__ = core.keyboard.KeyboardKeyValue;
port.browser.HTMLAnchorElement = $hxClasses["port.browser.HTMLAnchorElement"] = function() {
	core.html.AbstractHTMLAnchorElement.call(this);
}
port.browser.HTMLAnchorElement.__name__ = ["port","browser","HTMLAnchorElement"];
port.browser.HTMLAnchorElement.__super__ = core.html.AbstractHTMLAnchorElement;
port.browser.HTMLAnchorElement.prototype = $extend(core.html.AbstractHTMLAnchorElement.prototype,{
	set_href: function(value) {
		this._nativeElement.href = value;
		core.html.AbstractHTMLAnchorElement.prototype.set_href.call(this,value);
		return value;
	}
	,set_target: function(value) {
		this._nativeElement.target = this.getTargetAsString(value);
		core.html.AbstractHTMLAnchorElement.prototype.set_target.call(this,value);
		return value;
	}
	,__class__: port.browser.HTMLAnchorElement
});
core.style.FontSize = $hxClasses["core.style.FontSize"] = { __ename__ : ["core","style","FontSize"], __constructs__ : ["length","percentage","absoluteSize","relativeSize"] }
core.style.FontSize.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.FontSize; $x.toString = $estr; return $x; }
core.style.FontSize.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = core.style.FontSize; $x.toString = $estr; return $x; }
core.style.FontSize.absoluteSize = function(value) { var $x = ["absoluteSize",2,value]; $x.__enum__ = core.style.FontSize; $x.toString = $estr; return $x; }
core.style.FontSize.relativeSize = function(value) { var $x = ["relativeSize",3,value]; $x.__enum__ = core.style.FontSize; $x.toString = $estr; return $x; }
core.style.FontWeight = $hxClasses["core.style.FontWeight"] = { __ename__ : ["core","style","FontWeight"], __constructs__ : ["normal","bold","bolder","lighter","css100","css200","css300","css400","css500","css600","css700","css800","css900"] }
core.style.FontWeight.normal = ["normal",0];
core.style.FontWeight.normal.toString = $estr;
core.style.FontWeight.normal.__enum__ = core.style.FontWeight;
core.style.FontWeight.bold = ["bold",1];
core.style.FontWeight.bold.toString = $estr;
core.style.FontWeight.bold.__enum__ = core.style.FontWeight;
core.style.FontWeight.bolder = ["bolder",2];
core.style.FontWeight.bolder.toString = $estr;
core.style.FontWeight.bolder.__enum__ = core.style.FontWeight;
core.style.FontWeight.lighter = ["lighter",3];
core.style.FontWeight.lighter.toString = $estr;
core.style.FontWeight.lighter.__enum__ = core.style.FontWeight;
core.style.FontWeight.css100 = ["css100",4];
core.style.FontWeight.css100.toString = $estr;
core.style.FontWeight.css100.__enum__ = core.style.FontWeight;
core.style.FontWeight.css200 = ["css200",5];
core.style.FontWeight.css200.toString = $estr;
core.style.FontWeight.css200.__enum__ = core.style.FontWeight;
core.style.FontWeight.css300 = ["css300",6];
core.style.FontWeight.css300.toString = $estr;
core.style.FontWeight.css300.__enum__ = core.style.FontWeight;
core.style.FontWeight.css400 = ["css400",7];
core.style.FontWeight.css400.toString = $estr;
core.style.FontWeight.css400.__enum__ = core.style.FontWeight;
core.style.FontWeight.css500 = ["css500",8];
core.style.FontWeight.css500.toString = $estr;
core.style.FontWeight.css500.__enum__ = core.style.FontWeight;
core.style.FontWeight.css600 = ["css600",9];
core.style.FontWeight.css600.toString = $estr;
core.style.FontWeight.css600.__enum__ = core.style.FontWeight;
core.style.FontWeight.css700 = ["css700",10];
core.style.FontWeight.css700.toString = $estr;
core.style.FontWeight.css700.__enum__ = core.style.FontWeight;
core.style.FontWeight.css800 = ["css800",11];
core.style.FontWeight.css800.toString = $estr;
core.style.FontWeight.css800.__enum__ = core.style.FontWeight;
core.style.FontWeight.css900 = ["css900",12];
core.style.FontWeight.css900.toString = $estr;
core.style.FontWeight.css900.__enum__ = core.style.FontWeight;
core.style.FontStyle = $hxClasses["core.style.FontStyle"] = { __ename__ : ["core","style","FontStyle"], __constructs__ : ["normal","italic"] }
core.style.FontStyle.normal = ["normal",0];
core.style.FontStyle.normal.toString = $estr;
core.style.FontStyle.normal.__enum__ = core.style.FontStyle;
core.style.FontStyle.italic = ["italic",1];
core.style.FontStyle.italic.toString = $estr;
core.style.FontStyle.italic.__enum__ = core.style.FontStyle;
core.style.FontFamily = $hxClasses["core.style.FontFamily"] = { __ename__ : ["core","style","FontFamily"], __constructs__ : ["familyName","genericFamily"] }
core.style.FontFamily.familyName = function(name) { var $x = ["familyName",0,name]; $x.__enum__ = core.style.FontFamily; $x.toString = $estr; return $x; }
core.style.FontFamily.genericFamily = function(genericName) { var $x = ["genericFamily",1,genericName]; $x.__enum__ = core.style.FontFamily; $x.toString = $estr; return $x; }
core.style.GenericFontFamily = $hxClasses["core.style.GenericFontFamily"] = { __ename__ : ["core","style","GenericFontFamily"], __constructs__ : ["serif","sansSerif","monospace"] }
core.style.GenericFontFamily.serif = ["serif",0];
core.style.GenericFontFamily.serif.toString = $estr;
core.style.GenericFontFamily.serif.__enum__ = core.style.GenericFontFamily;
core.style.GenericFontFamily.sansSerif = ["sansSerif",1];
core.style.GenericFontFamily.sansSerif.toString = $estr;
core.style.GenericFontFamily.sansSerif.__enum__ = core.style.GenericFontFamily;
core.style.GenericFontFamily.monospace = ["monospace",2];
core.style.GenericFontFamily.monospace.toString = $estr;
core.style.GenericFontFamily.monospace.__enum__ = core.style.GenericFontFamily;
core.style.FontVariant = $hxClasses["core.style.FontVariant"] = { __ename__ : ["core","style","FontVariant"], __constructs__ : ["normal","smallCaps"] }
core.style.FontVariant.normal = ["normal",0];
core.style.FontVariant.normal.toString = $estr;
core.style.FontVariant.normal.__enum__ = core.style.FontVariant;
core.style.FontVariant.smallCaps = ["smallCaps",1];
core.style.FontVariant.smallCaps.toString = $estr;
core.style.FontVariant.smallCaps.__enum__ = core.style.FontVariant;
core.style.WhiteSpace = $hxClasses["core.style.WhiteSpace"] = { __ename__ : ["core","style","WhiteSpace"], __constructs__ : ["normal","pre","nowrap","preWrap","preLine"] }
core.style.WhiteSpace.normal = ["normal",0];
core.style.WhiteSpace.normal.toString = $estr;
core.style.WhiteSpace.normal.__enum__ = core.style.WhiteSpace;
core.style.WhiteSpace.pre = ["pre",1];
core.style.WhiteSpace.pre.toString = $estr;
core.style.WhiteSpace.pre.__enum__ = core.style.WhiteSpace;
core.style.WhiteSpace.nowrap = ["nowrap",2];
core.style.WhiteSpace.nowrap.toString = $estr;
core.style.WhiteSpace.nowrap.__enum__ = core.style.WhiteSpace;
core.style.WhiteSpace.preWrap = ["preWrap",3];
core.style.WhiteSpace.preWrap.toString = $estr;
core.style.WhiteSpace.preWrap.__enum__ = core.style.WhiteSpace;
core.style.WhiteSpace.preLine = ["preLine",4];
core.style.WhiteSpace.preLine.toString = $estr;
core.style.WhiteSpace.preLine.__enum__ = core.style.WhiteSpace;
core.style.LetterSpacing = $hxClasses["core.style.LetterSpacing"] = { __ename__ : ["core","style","LetterSpacing"], __constructs__ : ["normal","length"] }
core.style.LetterSpacing.normal = ["normal",0];
core.style.LetterSpacing.normal.toString = $estr;
core.style.LetterSpacing.normal.__enum__ = core.style.LetterSpacing;
core.style.LetterSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = core.style.LetterSpacing; $x.toString = $estr; return $x; }
core.style.WordSpacing = $hxClasses["core.style.WordSpacing"] = { __ename__ : ["core","style","WordSpacing"], __constructs__ : ["normal","length"] }
core.style.WordSpacing.normal = ["normal",0];
core.style.WordSpacing.normal.toString = $estr;
core.style.WordSpacing.normal.__enum__ = core.style.WordSpacing;
core.style.WordSpacing.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = core.style.WordSpacing; $x.toString = $estr; return $x; }
core.style.TextIndent = $hxClasses["core.style.TextIndent"] = { __ename__ : ["core","style","TextIndent"], __constructs__ : ["length","percentage"] }
core.style.TextIndent.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.TextIndent; $x.toString = $estr; return $x; }
core.style.TextIndent.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = core.style.TextIndent; $x.toString = $estr; return $x; }
core.style.TextAlign = $hxClasses["core.style.TextAlign"] = { __ename__ : ["core","style","TextAlign"], __constructs__ : ["left","right","center","justify"] }
core.style.TextAlign.left = ["left",0];
core.style.TextAlign.left.toString = $estr;
core.style.TextAlign.left.__enum__ = core.style.TextAlign;
core.style.TextAlign.right = ["right",1];
core.style.TextAlign.right.toString = $estr;
core.style.TextAlign.right.__enum__ = core.style.TextAlign;
core.style.TextAlign.center = ["center",2];
core.style.TextAlign.center.toString = $estr;
core.style.TextAlign.center.__enum__ = core.style.TextAlign;
core.style.TextAlign.justify = ["justify",3];
core.style.TextAlign.justify.toString = $estr;
core.style.TextAlign.justify.__enum__ = core.style.TextAlign;
core.style.TextTransform = $hxClasses["core.style.TextTransform"] = { __ename__ : ["core","style","TextTransform"], __constructs__ : ["capitalize","uppercase","lowercase","none"] }
core.style.TextTransform.capitalize = ["capitalize",0];
core.style.TextTransform.capitalize.toString = $estr;
core.style.TextTransform.capitalize.__enum__ = core.style.TextTransform;
core.style.TextTransform.uppercase = ["uppercase",1];
core.style.TextTransform.uppercase.toString = $estr;
core.style.TextTransform.uppercase.__enum__ = core.style.TextTransform;
core.style.TextTransform.lowercase = ["lowercase",2];
core.style.TextTransform.lowercase.toString = $estr;
core.style.TextTransform.lowercase.__enum__ = core.style.TextTransform;
core.style.TextTransform.none = ["none",3];
core.style.TextTransform.none.toString = $estr;
core.style.TextTransform.none.__enum__ = core.style.TextTransform;
core.style.LineHeight = $hxClasses["core.style.LineHeight"] = { __ename__ : ["core","style","LineHeight"], __constructs__ : ["normal","number","length","percentage"] }
core.style.LineHeight.normal = ["normal",0];
core.style.LineHeight.normal.toString = $estr;
core.style.LineHeight.normal.__enum__ = core.style.LineHeight;
core.style.LineHeight.number = function(value) { var $x = ["number",1,value]; $x.__enum__ = core.style.LineHeight; $x.toString = $estr; return $x; }
core.style.LineHeight.length = function(value) { var $x = ["length",2,value]; $x.__enum__ = core.style.LineHeight; $x.toString = $estr; return $x; }
core.style.LineHeight.percentage = function(value) { var $x = ["percentage",3,value]; $x.__enum__ = core.style.LineHeight; $x.toString = $estr; return $x; }
core.style.VerticalAlign = $hxClasses["core.style.VerticalAlign"] = { __ename__ : ["core","style","VerticalAlign"], __constructs__ : ["baseline","sub","superStyle","top","textTop","middle","bottom","textBottom","percent","length"] }
core.style.VerticalAlign.baseline = ["baseline",0];
core.style.VerticalAlign.baseline.toString = $estr;
core.style.VerticalAlign.baseline.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.sub = ["sub",1];
core.style.VerticalAlign.sub.toString = $estr;
core.style.VerticalAlign.sub.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.superStyle = ["superStyle",2];
core.style.VerticalAlign.superStyle.toString = $estr;
core.style.VerticalAlign.superStyle.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.top = ["top",3];
core.style.VerticalAlign.top.toString = $estr;
core.style.VerticalAlign.top.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.textTop = ["textTop",4];
core.style.VerticalAlign.textTop.toString = $estr;
core.style.VerticalAlign.textTop.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.middle = ["middle",5];
core.style.VerticalAlign.middle.toString = $estr;
core.style.VerticalAlign.middle.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.bottom = ["bottom",6];
core.style.VerticalAlign.bottom.toString = $estr;
core.style.VerticalAlign.bottom.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.textBottom = ["textBottom",7];
core.style.VerticalAlign.textBottom.toString = $estr;
core.style.VerticalAlign.textBottom.__enum__ = core.style.VerticalAlign;
core.style.VerticalAlign.percent = function(value) { var $x = ["percent",8,value]; $x.__enum__ = core.style.VerticalAlign; $x.toString = $estr; return $x; }
core.style.VerticalAlign.length = function(value) { var $x = ["length",9,value]; $x.__enum__ = core.style.VerticalAlign; $x.toString = $estr; return $x; }
core.style.Margin = $hxClasses["core.style.Margin"] = { __ename__ : ["core","style","Margin"], __constructs__ : ["length","percent","cssAuto"] }
core.style.Margin.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.Margin; $x.toString = $estr; return $x; }
core.style.Margin.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.Margin; $x.toString = $estr; return $x; }
core.style.Margin.cssAuto = ["cssAuto",2];
core.style.Margin.cssAuto.toString = $estr;
core.style.Margin.cssAuto.__enum__ = core.style.Margin;
core.style.Padding = $hxClasses["core.style.Padding"] = { __ename__ : ["core","style","Padding"], __constructs__ : ["length","percent"] }
core.style.Padding.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.Padding; $x.toString = $estr; return $x; }
core.style.Padding.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.Padding; $x.toString = $estr; return $x; }
core.style.Dimension = $hxClasses["core.style.Dimension"] = { __ename__ : ["core","style","Dimension"], __constructs__ : ["length","percent","cssAuto"] }
core.style.Dimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.Dimension; $x.toString = $estr; return $x; }
core.style.Dimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.Dimension; $x.toString = $estr; return $x; }
core.style.Dimension.cssAuto = ["cssAuto",2];
core.style.Dimension.cssAuto.toString = $estr;
core.style.Dimension.cssAuto.__enum__ = core.style.Dimension;
core.style.ConstrainedDimension = $hxClasses["core.style.ConstrainedDimension"] = { __ename__ : ["core","style","ConstrainedDimension"], __constructs__ : ["length","percent","none"] }
core.style.ConstrainedDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
core.style.ConstrainedDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.ConstrainedDimension; $x.toString = $estr; return $x; }
core.style.ConstrainedDimension.none = ["none",2];
core.style.ConstrainedDimension.none.toString = $estr;
core.style.ConstrainedDimension.none.__enum__ = core.style.ConstrainedDimension;
core.style.Display = $hxClasses["core.style.Display"] = { __ename__ : ["core","style","Display"], __constructs__ : ["block","inlineBlock","cssInline","none"] }
core.style.Display.block = ["block",0];
core.style.Display.block.toString = $estr;
core.style.Display.block.__enum__ = core.style.Display;
core.style.Display.inlineBlock = ["inlineBlock",1];
core.style.Display.inlineBlock.toString = $estr;
core.style.Display.inlineBlock.__enum__ = core.style.Display;
core.style.Display.cssInline = ["cssInline",2];
core.style.Display.cssInline.toString = $estr;
core.style.Display.cssInline.__enum__ = core.style.Display;
core.style.Display.none = ["none",3];
core.style.Display.none.toString = $estr;
core.style.Display.none.__enum__ = core.style.Display;
core.style.CSSFloat = $hxClasses["core.style.CSSFloat"] = { __ename__ : ["core","style","CSSFloat"], __constructs__ : ["left","right","none"] }
core.style.CSSFloat.left = ["left",0];
core.style.CSSFloat.left.toString = $estr;
core.style.CSSFloat.left.__enum__ = core.style.CSSFloat;
core.style.CSSFloat.right = ["right",1];
core.style.CSSFloat.right.toString = $estr;
core.style.CSSFloat.right.__enum__ = core.style.CSSFloat;
core.style.CSSFloat.none = ["none",2];
core.style.CSSFloat.none.toString = $estr;
core.style.CSSFloat.none.__enum__ = core.style.CSSFloat;
core.style.Clear = $hxClasses["core.style.Clear"] = { __ename__ : ["core","style","Clear"], __constructs__ : ["none","left","right","both"] }
core.style.Clear.none = ["none",0];
core.style.Clear.none.toString = $estr;
core.style.Clear.none.__enum__ = core.style.Clear;
core.style.Clear.left = ["left",1];
core.style.Clear.left.toString = $estr;
core.style.Clear.left.__enum__ = core.style.Clear;
core.style.Clear.right = ["right",2];
core.style.Clear.right.toString = $estr;
core.style.Clear.right.__enum__ = core.style.Clear;
core.style.Clear.both = ["both",3];
core.style.Clear.both.toString = $estr;
core.style.Clear.both.__enum__ = core.style.Clear;
core.style.Position = $hxClasses["core.style.Position"] = { __ename__ : ["core","style","Position"], __constructs__ : ["cssStatic","relative","absolute","fixed"] }
core.style.Position.cssStatic = ["cssStatic",0];
core.style.Position.cssStatic.toString = $estr;
core.style.Position.cssStatic.__enum__ = core.style.Position;
core.style.Position.relative = ["relative",1];
core.style.Position.relative.toString = $estr;
core.style.Position.relative.__enum__ = core.style.Position;
core.style.Position.absolute = ["absolute",2];
core.style.Position.absolute.toString = $estr;
core.style.Position.absolute.__enum__ = core.style.Position;
core.style.Position.fixed = ["fixed",3];
core.style.Position.fixed.toString = $estr;
core.style.Position.fixed.__enum__ = core.style.Position;
core.style.PositionOffset = $hxClasses["core.style.PositionOffset"] = { __ename__ : ["core","style","PositionOffset"], __constructs__ : ["length","percent","cssAuto"] }
core.style.PositionOffset.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.PositionOffset; $x.toString = $estr; return $x; }
core.style.PositionOffset.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.PositionOffset; $x.toString = $estr; return $x; }
core.style.PositionOffset.cssAuto = ["cssAuto",2];
core.style.PositionOffset.cssAuto.toString = $estr;
core.style.PositionOffset.cssAuto.__enum__ = core.style.PositionOffset;
core.style.Overflow = $hxClasses["core.style.Overflow"] = { __ename__ : ["core","style","Overflow"], __constructs__ : ["visible","hidden","scroll","cssAuto"] }
core.style.Overflow.visible = ["visible",0];
core.style.Overflow.visible.toString = $estr;
core.style.Overflow.visible.__enum__ = core.style.Overflow;
core.style.Overflow.hidden = ["hidden",1];
core.style.Overflow.hidden.toString = $estr;
core.style.Overflow.hidden.__enum__ = core.style.Overflow;
core.style.Overflow.scroll = ["scroll",2];
core.style.Overflow.scroll.toString = $estr;
core.style.Overflow.scroll.__enum__ = core.style.Overflow;
core.style.Overflow.cssAuto = ["cssAuto",3];
core.style.Overflow.cssAuto.toString = $estr;
core.style.Overflow.cssAuto.__enum__ = core.style.Overflow;
core.style.Visibility = $hxClasses["core.style.Visibility"] = { __ename__ : ["core","style","Visibility"], __constructs__ : ["visible","hidden"] }
core.style.Visibility.visible = ["visible",0];
core.style.Visibility.visible.toString = $estr;
core.style.Visibility.visible.__enum__ = core.style.Visibility;
core.style.Visibility.hidden = ["hidden",1];
core.style.Visibility.hidden.toString = $estr;
core.style.Visibility.hidden.__enum__ = core.style.Visibility;
core.style.Transform = $hxClasses["core.style.Transform"] = { __ename__ : ["core","style","Transform"], __constructs__ : ["none","transformFunctions"] }
core.style.Transform.none = ["none",0];
core.style.Transform.none.toString = $estr;
core.style.Transform.none.__enum__ = core.style.Transform;
core.style.Transform.transformFunctions = function(transformFunctions) { var $x = ["transformFunctions",1,transformFunctions]; $x.__enum__ = core.style.Transform; $x.toString = $estr; return $x; }
core.style.TransformFunction = $hxClasses["core.style.TransformFunction"] = { __ename__ : ["core","style","TransformFunction"], __constructs__ : ["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","skew"] }
core.style.TransformFunction.matrix = function(data) { var $x = ["matrix",0,data]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.translate = function(tx,ty) { var $x = ["translate",1,tx,ty]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.translateX = function(tx) { var $x = ["translateX",2,tx]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.translateY = function(ty) { var $x = ["translateY",3,ty]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.scale = function(sx,sy) { var $x = ["scale",4,sx,sy]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.scaleX = function(sx) { var $x = ["scaleX",5,sx]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.scaleY = function(sy) { var $x = ["scaleY",6,sy]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.rotate = function(angle) { var $x = ["rotate",7,angle]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.skewX = function(angle) { var $x = ["skewX",8,angle]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.skewY = function(angle) { var $x = ["skewY",9,angle]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.TransformFunction.skew = function(angleX,angleY) { var $x = ["skew",10,angleX,angleY]; $x.__enum__ = core.style.TransformFunction; $x.toString = $estr; return $x; }
core.style.Translation = $hxClasses["core.style.Translation"] = { __ename__ : ["core","style","Translation"], __constructs__ : ["length","percent"] }
core.style.Translation.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.Translation; $x.toString = $estr; return $x; }
core.style.Translation.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.Translation; $x.toString = $estr; return $x; }
core.style.TransformOriginX = $hxClasses["core.style.TransformOriginX"] = { __ename__ : ["core","style","TransformOriginX"], __constructs__ : ["length","percent","left","center","right"] }
core.style.TransformOriginX.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.TransformOriginX; $x.toString = $estr; return $x; }
core.style.TransformOriginX.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.TransformOriginX; $x.toString = $estr; return $x; }
core.style.TransformOriginX.left = ["left",2];
core.style.TransformOriginX.left.toString = $estr;
core.style.TransformOriginX.left.__enum__ = core.style.TransformOriginX;
core.style.TransformOriginX.center = ["center",3];
core.style.TransformOriginX.center.toString = $estr;
core.style.TransformOriginX.center.__enum__ = core.style.TransformOriginX;
core.style.TransformOriginX.right = ["right",4];
core.style.TransformOriginX.right.toString = $estr;
core.style.TransformOriginX.right.__enum__ = core.style.TransformOriginX;
core.style.TransformOriginY = $hxClasses["core.style.TransformOriginY"] = { __ename__ : ["core","style","TransformOriginY"], __constructs__ : ["length","percent","top","center","bottom"] }
core.style.TransformOriginY.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.TransformOriginY; $x.toString = $estr; return $x; }
core.style.TransformOriginY.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.TransformOriginY; $x.toString = $estr; return $x; }
core.style.TransformOriginY.top = ["top",2];
core.style.TransformOriginY.top.toString = $estr;
core.style.TransformOriginY.top.__enum__ = core.style.TransformOriginY;
core.style.TransformOriginY.center = ["center",3];
core.style.TransformOriginY.center.toString = $estr;
core.style.TransformOriginY.center.__enum__ = core.style.TransformOriginY;
core.style.TransformOriginY.bottom = ["bottom",4];
core.style.TransformOriginY.bottom.toString = $estr;
core.style.TransformOriginY.bottom.__enum__ = core.style.TransformOriginY;
core.style.BackgroundImage = $hxClasses["core.style.BackgroundImage"] = { __ename__ : ["core","style","BackgroundImage"], __constructs__ : ["none","image"] }
core.style.BackgroundImage.none = ["none",0];
core.style.BackgroundImage.none.toString = $estr;
core.style.BackgroundImage.none.__enum__ = core.style.BackgroundImage;
core.style.BackgroundImage.image = function(value) { var $x = ["image",1,value]; $x.__enum__ = core.style.BackgroundImage; $x.toString = $estr; return $x; }
core.style.BackgroundRepeatValue = $hxClasses["core.style.BackgroundRepeatValue"] = { __ename__ : ["core","style","BackgroundRepeatValue"], __constructs__ : ["repeat","space","round","noRepeat"] }
core.style.BackgroundRepeatValue.repeat = ["repeat",0];
core.style.BackgroundRepeatValue.repeat.toString = $estr;
core.style.BackgroundRepeatValue.repeat.__enum__ = core.style.BackgroundRepeatValue;
core.style.BackgroundRepeatValue.space = ["space",1];
core.style.BackgroundRepeatValue.space.toString = $estr;
core.style.BackgroundRepeatValue.space.__enum__ = core.style.BackgroundRepeatValue;
core.style.BackgroundRepeatValue.round = ["round",2];
core.style.BackgroundRepeatValue.round.toString = $estr;
core.style.BackgroundRepeatValue.round.__enum__ = core.style.BackgroundRepeatValue;
core.style.BackgroundRepeatValue.noRepeat = ["noRepeat",3];
core.style.BackgroundRepeatValue.noRepeat.toString = $estr;
core.style.BackgroundRepeatValue.noRepeat.__enum__ = core.style.BackgroundRepeatValue;
core.style.BackgroundPositionX = $hxClasses["core.style.BackgroundPositionX"] = { __ename__ : ["core","style","BackgroundPositionX"], __constructs__ : ["length","percent","left","center","right"] }
core.style.BackgroundPositionX.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.BackgroundPositionX; $x.toString = $estr; return $x; }
core.style.BackgroundPositionX.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.BackgroundPositionX; $x.toString = $estr; return $x; }
core.style.BackgroundPositionX.left = ["left",2];
core.style.BackgroundPositionX.left.toString = $estr;
core.style.BackgroundPositionX.left.__enum__ = core.style.BackgroundPositionX;
core.style.BackgroundPositionX.center = ["center",3];
core.style.BackgroundPositionX.center.toString = $estr;
core.style.BackgroundPositionX.center.__enum__ = core.style.BackgroundPositionX;
core.style.BackgroundPositionX.right = ["right",4];
core.style.BackgroundPositionX.right.toString = $estr;
core.style.BackgroundPositionX.right.__enum__ = core.style.BackgroundPositionX;
core.style.BackgroundPositionY = $hxClasses["core.style.BackgroundPositionY"] = { __ename__ : ["core","style","BackgroundPositionY"], __constructs__ : ["length","percent","top","center","bottom"] }
core.style.BackgroundPositionY.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.BackgroundPositionY; $x.toString = $estr; return $x; }
core.style.BackgroundPositionY.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.BackgroundPositionY; $x.toString = $estr; return $x; }
core.style.BackgroundPositionY.top = ["top",2];
core.style.BackgroundPositionY.top.toString = $estr;
core.style.BackgroundPositionY.top.__enum__ = core.style.BackgroundPositionY;
core.style.BackgroundPositionY.center = ["center",3];
core.style.BackgroundPositionY.center.toString = $estr;
core.style.BackgroundPositionY.center.__enum__ = core.style.BackgroundPositionY;
core.style.BackgroundPositionY.bottom = ["bottom",4];
core.style.BackgroundPositionY.bottom.toString = $estr;
core.style.BackgroundPositionY.bottom.__enum__ = core.style.BackgroundPositionY;
core.style.BackgroundClip = $hxClasses["core.style.BackgroundClip"] = { __ename__ : ["core","style","BackgroundClip"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
core.style.BackgroundClip.borderBox = ["borderBox",0];
core.style.BackgroundClip.borderBox.toString = $estr;
core.style.BackgroundClip.borderBox.__enum__ = core.style.BackgroundClip;
core.style.BackgroundClip.paddingBox = ["paddingBox",1];
core.style.BackgroundClip.paddingBox.toString = $estr;
core.style.BackgroundClip.paddingBox.__enum__ = core.style.BackgroundClip;
core.style.BackgroundClip.contentBox = ["contentBox",2];
core.style.BackgroundClip.contentBox.toString = $estr;
core.style.BackgroundClip.contentBox.__enum__ = core.style.BackgroundClip;
core.style.BackgroundOrigin = $hxClasses["core.style.BackgroundOrigin"] = { __ename__ : ["core","style","BackgroundOrigin"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
core.style.BackgroundOrigin.borderBox = ["borderBox",0];
core.style.BackgroundOrigin.borderBox.toString = $estr;
core.style.BackgroundOrigin.borderBox.__enum__ = core.style.BackgroundOrigin;
core.style.BackgroundOrigin.paddingBox = ["paddingBox",1];
core.style.BackgroundOrigin.paddingBox.toString = $estr;
core.style.BackgroundOrigin.paddingBox.__enum__ = core.style.BackgroundOrigin;
core.style.BackgroundOrigin.contentBox = ["contentBox",2];
core.style.BackgroundOrigin.contentBox.toString = $estr;
core.style.BackgroundOrigin.contentBox.__enum__ = core.style.BackgroundOrigin;
core.style.BackgroundSize = $hxClasses["core.style.BackgroundSize"] = { __ename__ : ["core","style","BackgroundSize"], __constructs__ : ["contain","cover","dimensions"] }
core.style.BackgroundSize.contain = ["contain",0];
core.style.BackgroundSize.contain.toString = $estr;
core.style.BackgroundSize.contain.__enum__ = core.style.BackgroundSize;
core.style.BackgroundSize.cover = ["cover",1];
core.style.BackgroundSize.cover.toString = $estr;
core.style.BackgroundSize.cover.__enum__ = core.style.BackgroundSize;
core.style.BackgroundSize.dimensions = function(value) { var $x = ["dimensions",2,value]; $x.__enum__ = core.style.BackgroundSize; $x.toString = $estr; return $x; }
core.style.BackgroundSizeDimension = $hxClasses["core.style.BackgroundSizeDimension"] = { __ename__ : ["core","style","BackgroundSizeDimension"], __constructs__ : ["length","percent","cssAuto"] }
core.style.BackgroundSizeDimension.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
core.style.BackgroundSizeDimension.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = core.style.BackgroundSizeDimension; $x.toString = $estr; return $x; }
core.style.BackgroundSizeDimension.cssAuto = ["cssAuto",2];
core.style.BackgroundSizeDimension.cssAuto.toString = $estr;
core.style.BackgroundSizeDimension.cssAuto.__enum__ = core.style.BackgroundSizeDimension;
core.style.Cursor = $hxClasses["core.style.Cursor"] = { __ename__ : ["core","style","Cursor"], __constructs__ : ["auto","crosshair","cssDefault","pointer"] }
core.style.Cursor.auto = ["auto",0];
core.style.Cursor.auto.toString = $estr;
core.style.Cursor.auto.__enum__ = core.style.Cursor;
core.style.Cursor.crosshair = ["crosshair",1];
core.style.Cursor.crosshair.toString = $estr;
core.style.Cursor.crosshair.__enum__ = core.style.Cursor;
core.style.Cursor.cssDefault = ["cssDefault",2];
core.style.Cursor.cssDefault.toString = $estr;
core.style.Cursor.cssDefault.__enum__ = core.style.Cursor;
core.style.Cursor.pointer = ["pointer",3];
core.style.Cursor.pointer.toString = $estr;
core.style.Cursor.pointer.__enum__ = core.style.Cursor;
var Std = $hxClasses["Std"] = function() { }
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
Std.prototype = {
	__class__: Std
}
core.renderer.BlockBoxRenderer = $hxClasses["core.renderer.BlockBoxRenderer"] = function(style) {
	core.renderer.FlowBoxRenderer.call(this,style);
}
core.renderer.BlockBoxRenderer.__name__ = ["core","renderer","BlockBoxRenderer"];
core.renderer.BlockBoxRenderer.__super__ = core.renderer.FlowBoxRenderer;
core.renderer.BlockBoxRenderer.prototype = $extend(core.renderer.FlowBoxRenderer.prototype,{
	_lineBoxes: null
	,lineBoxes: null
	,dispose: function() {
		core.renderer.FlowBoxRenderer.prototype.dispose.call(this);
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
	,render: function() {
		var ret = [];
		return ret;
	}
	,getLineBoxes: function() {
		return this._lineBoxes;
	}
	,__class__: core.renderer.BlockBoxRenderer
	,__properties__: $extend(core.renderer.FlowBoxRenderer.prototype.__properties__,{get_lineBoxes:"getLineBoxes"})
});
core.renderer.InitialBlockRenderer = $hxClasses["core.renderer.InitialBlockRenderer"] = function(style) {
	core.renderer.BlockBoxRenderer.call(this,style);
	var width = cocktail.Lib.get_window().get_innerWidth();
	var height = cocktail.Lib.get_window().get_innerHeight();
	this._bounds.width = width;
	this._bounds.height = height;
}
core.renderer.InitialBlockRenderer.__name__ = ["core","renderer","InitialBlockRenderer"];
core.renderer.InitialBlockRenderer.__super__ = core.renderer.BlockBoxRenderer;
core.renderer.InitialBlockRenderer.prototype = $extend(core.renderer.BlockBoxRenderer.prototype,{
	isInitialContainer: function() {
		return true;
	}
	,init: function() {
		this._backgroundManager = new core.background.InitialBlockBackgroundManager();
	}
	,__class__: core.renderer.InitialBlockRenderer
});
haxe.Timer = $hxClasses["haxe.Timer"] = function(time_ms) {
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
core.dom.Document = $hxClasses["core.dom.Document"] = function() {
	core.dom.Node.call(this);
}
core.dom.Document.__name__ = ["core","dom","Document"];
core.dom.Document.__super__ = core.dom.Node;
core.dom.Document.prototype = $extend(core.dom.Node.prototype,{
	createElement: function(tagName) {
		var element = new core.dom.Element(tagName);
		return element;
	}
	,createTextNode: function(data) {
		var text = new port.browser.Text();
		text.set_nodeValue(data);
		return text;
	}
	,__class__: core.dom.Document
});
core.html.AbstractHTMLImageElement = $hxClasses["core.html.AbstractHTMLImageElement"] = function() {
	this._imageLoader = new core.resource.AbstractImageLoader();
	core.html.EmbeddedElement.call(this,"img");
}
core.html.AbstractHTMLImageElement.__name__ = ["core","html","AbstractHTMLImageElement"];
core.html.AbstractHTMLImageElement.__super__ = core.html.EmbeddedElement;
core.html.AbstractHTMLImageElement.prototype = $extend(core.html.EmbeddedElement.prototype,{
	onLoad: null
	,onError: null
	,naturalWidth: null
	,naturalHeight: null
	,_src: null
	,src: null
	,_imageLoader: null
	,initEmbeddedAsset: function() {
		this._embeddedAsset = this._imageLoader.getNativeElement();
	}
	,set_src: function(value) {
		this._src = value;
		this._imageLoader.load([value],this.onLoadComplete.$bind(this),this.onLoadError.$bind(this));
		return this._src;
	}
	,onLoadComplete: function(image) {
		this._intrinsicHeight = this._imageLoader.getIntrinsicHeight();
		this._intrinsicWidth = this._imageLoader.getIntrinsicWidth();
		this._intrinsicRatio = this._intrinsicHeight / this._intrinsicWidth;
		this._style.invalidate();
		if(this.onLoad != null) {
			var loadEvent = new core.event.Event("load",this);
			this.onLoad(loadEvent);
		}
	}
	,onLoadError: function(message) {
		if(this.onError != null) this.onError(new core.event.Event("error",this));
	}
	,get_src: function() {
		return this._src;
	}
	,get_naturalHeight: function() {
		return this._intrinsicHeight;
	}
	,get_naturalWidth: function() {
		return this._intrinsicWidth;
	}
	,__class__: core.html.AbstractHTMLImageElement
	,__properties__: $extend(core.html.EmbeddedElement.prototype.__properties__,{set_src:"set_src",get_src:"get_src",get_naturalHeight:"get_naturalHeight",get_naturalWidth:"get_naturalWidth"})
});
core.background.InitialBlockBackgroundManager = $hxClasses["core.background.InitialBlockBackgroundManager"] = function() {
	core.background.BackgroundManager.call(this);
}
core.background.InitialBlockBackgroundManager.__name__ = ["core","background","InitialBlockBackgroundManager"];
core.background.InitialBlockBackgroundManager.__super__ = core.background.BackgroundManager;
core.background.InitialBlockBackgroundManager.prototype = $extend(core.background.BackgroundManager.prototype,{
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
	,__class__: core.background.InitialBlockBackgroundManager
});
core.style.computer.DisplayStylesComputer = $hxClasses["core.style.computer.DisplayStylesComputer"] = function() {
}
core.style.computer.DisplayStylesComputer.__name__ = ["core","style","computer","DisplayStylesComputer"];
core.style.computer.DisplayStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.position = core.style.computer.DisplayStylesComputer.getComputedPosition(style);
	computedStyle.cssFloat = core.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = core.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle.cssFloat);
	computedStyle.clear = core.style.computer.DisplayStylesComputer.getComputedClear(style,computedStyle.position,computedStyle.display);
}
core.style.computer.DisplayStylesComputer.getComputedPosition = function(style) {
	return style.getPosition();
}
core.style.computer.DisplayStylesComputer.getComputedFloat = function(style,computedPosition) {
	var ret;
	if(computedPosition == core.style.Position.absolute || computedPosition == core.style.Position.fixed) ret = core.style.CSSFloat.none; else ret = style.getCSSFloat();
	return ret;
}
core.style.computer.DisplayStylesComputer.getComputedDisplay = function(style,computedFloat) {
	var ret;
	if(computedFloat != core.style.CSSFloat.none) {
		switch( (style.getDisplay())[1] ) {
		case 2:
		case 1:
			ret = core.style.Display.block;
			break;
		default:
			ret = style.getDisplay();
		}
	} else ret = style.getDisplay();
	return ret;
}
core.style.computer.DisplayStylesComputer.getComputedClear = function(style,computedPosition,computedDisplay) {
	var ret;
	if(computedDisplay == core.style.Display.cssInline || computedDisplay == core.style.Display.inlineBlock) ret = core.style.Clear.none; else if(computedPosition == core.style.Position.absolute || computedPosition == core.style.Position.fixed) ret = core.style.Clear.none; else ret = style.getClear();
	return ret;
}
core.style.computer.DisplayStylesComputer.prototype = {
	__class__: core.style.computer.DisplayStylesComputer
}
core.resource.AbstractImageLoader = $hxClasses["core.resource.AbstractImageLoader"] = function() {
	var nativeElement = core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.image);
	port.browser.MediaLoader.call(this,nativeElement);
}
core.resource.AbstractImageLoader.__name__ = ["core","resource","AbstractImageLoader"];
core.resource.AbstractImageLoader.__super__ = port.browser.MediaLoader;
core.resource.AbstractImageLoader.prototype = $extend(port.browser.MediaLoader.prototype,{
	__class__: core.resource.AbstractImageLoader
});
core.style.formatter.BlockFormattingContext = $hxClasses["core.style.formatter.BlockFormattingContext"] = function(formattingContextRoot) {
	core.style.formatter.FormattingContext.call(this,formattingContextRoot);
}
core.style.formatter.BlockFormattingContext.__name__ = ["core","style","formatter","BlockFormattingContext"];
core.style.formatter.BlockFormattingContext.__super__ = core.style.formatter.FormattingContext;
core.style.formatter.BlockFormattingContext.prototype = $extend(core.style.formatter.FormattingContext.prototype,{
	doFormat: function(elementsInFormattingContext) {
		this.doFormat2(this._formattingContextRoot,0);
	}
	,doFormat2: function(elementRenderer,concatenatedX) {
		var currentAddedSiblingsHeight = 0;
		concatenatedX += elementRenderer.getStyle().getComputedStyle().marginLeft;
		var _g1 = 0, _g = elementRenderer.get_childNodes().length;
		while(_g1 < _g) {
			var i = _g1++;
			var child = elementRenderer.get_childNodes()[i];
			var marginTop = child.getStyle().getComputedStyle().marginTop;
			if(i == 0) {
				if(child.get_firstChild() != null) {
					var firstChild = child.get_firstChild();
					if(firstChild.getStyle().getComputedStyle().marginTop > marginTop && child.getStyle().getComputedStyle().paddingTop == 0) marginTop = firstChild.getStyle().getComputedStyle().marginTop;
				}
			}
			if(child.get_hasChildNodes() == true) {
				if(child.establishesNewFormattingContext() == false) this.doFormat2(child,concatenatedX);
			}
			var marginBottom = this.getCollapsedMarginBottom(child);
			var x = this._formattingContextData.x + concatenatedX + child.getStyle().getComputedStyle().marginLeft;
			var y = this._formattingContextData.y + marginTop + elementRenderer.getStyle().getComputedStyle().paddingTop;
			var width = child.getStyle().get_htmlElement().get_offsetWidth();
			var height = child.getStyle().get_htmlElement().get_offsetHeight();
			child.setBounds({ x : x, y : y, width : width, height : height});
			this._formattingContextData.y += Math.round(child.getBounds().height) + marginTop + marginBottom;
			currentAddedSiblingsHeight += Math.round(child.getBounds().height) + marginTop + marginBottom;
		}
		this._formattingContextData.y -= currentAddedSiblingsHeight;
	}
	,getCollapsedMarginBottom: function(child) {
		var marginBottom = child.getStyle().getComputedStyle().marginBottom;
		if(child.get_nextSibling() != null) {
			var nextSibling = child.get_nextSibling();
			if(nextSibling.getStyle().getComputedStyle().marginTop > marginBottom) marginBottom = 0; else marginBottom -= nextSibling.getStyle().getComputedStyle().marginTop;
		}
		return marginBottom;
	}
	,insertFloat: function(element) {
		var parent = element.get_parentNode();
		var floatData = this._floatsManager.computeFloatData(element,this._formattingContextData,Math.round(parent.getStyle().getComputedStyle().width));
		var x = floatData.x + parent.getStyle().getComputedStyle().paddingLeft;
		var y = floatData.y + parent.getStyle().getComputedStyle().paddingTop;
		var width = floatData.width;
		var height = floatData.height;
		element.setBounds({ x : x, y : y, width : width, height : height});
	}
	,__class__: core.style.formatter.BlockFormattingContext
});
var cocktail = cocktail || {}
cocktail.Lib = $hxClasses["cocktail.Lib"] = function() {
}
cocktail.Lib.__name__ = ["cocktail","Lib"];
cocktail.Lib.__properties__ = {get_window:"get_window",get_document:"get_document"}
cocktail.Lib._document = null;
cocktail.Lib.document = null;
cocktail.Lib._window = null;
cocktail.Lib.window = null;
cocktail.Lib.init = function() {
	cocktail.Lib._document = new core.html.HTMLDocument();
	cocktail.Lib._window = new port.browser.Window(cocktail.Lib._document);
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
core.html.HTMLCanvasElement = $hxClasses["core.html.HTMLCanvasElement"] = function() {
	core.html.EmbeddedElement.call(this,"canvas");
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	this._drawingManager = new port.browser.DrawingManager(this._nativeElement,this._intrinsicHeight,this._intrinsicWidth);
}
core.html.HTMLCanvasElement.__name__ = ["core","html","HTMLCanvasElement"];
core.html.HTMLCanvasElement.__super__ = core.html.EmbeddedElement;
core.html.HTMLCanvasElement.prototype = $extend(core.html.EmbeddedElement.prototype,{
	_drawingManager: null
	,initEmbeddedAsset: function() {
		this._embeddedAsset = this._nativeElement;
	}
	,getContext: function(contextID) {
		return this._drawingManager;
	}
	,set_width: function(value) {
		this._drawingManager.setWidth(value);
		return this._width = value;
	}
	,set_height: function(value) {
		this._drawingManager.setHeight(value);
		return this._height = value;
	}
	,__class__: core.html.HTMLCanvasElement
});
core.renderer.LayerRenderer = $hxClasses["core.renderer.LayerRenderer"] = function(rootRenderer) {
	this._rootRenderer = rootRenderer;
}
core.renderer.LayerRenderer.__name__ = ["core","renderer","LayerRenderer"];
core.renderer.LayerRenderer.prototype = {
	_rootRenderer: null
	,dispose: function() {
		this._rootRenderer = null;
	}
	,render: function() {
		var nativeElements = new Array();
		if(this._rootRenderer.canHaveChildren() == true && this._rootRenderer.getStyle().isInlineLevel() == false || this._rootRenderer.getStyle().getDisplay() == core.style.Display.inlineBlock) {
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
				if(child.canHaveChildren() == true && child.getStyle().getDisplay() != core.style.Display.inlineBlock) {
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
			if(inFlowChildren[i].getStyle().getDisplay() == core.style.Display.inlineBlock) {
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
	,getInFlowChildren: function(rootRenderer) {
		var ret = new Array();
		if(rootRenderer.establishesNewFormattingContext() == true && rootRenderer.getStyle().childrenInline() == true) {
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
	,setNativeMatrix: function(matrix) {
	}
	,getConcatenatedMatrix: function(matrix) {
		var currentMatrix = new core.geom.Matrix();
		return currentMatrix;
	}
	,getConcatenatedMatrix2: function(matrix) {
		var currentMatrix = new core.geom.Matrix();
		return currentMatrix;
	}
	,__class__: core.renderer.LayerRenderer
}
core.background.BackgroundDrawingManager = $hxClasses["core.background.BackgroundDrawingManager"] = function(nativeElement,backgroundBox) {
	port.browser.DrawingManager.call(this,nativeElement,Math.round(backgroundBox.width),Math.round(backgroundBox.height));
}
core.background.BackgroundDrawingManager.__name__ = ["core","background","BackgroundDrawingManager"];
core.background.BackgroundDrawingManager.__super__ = port.browser.DrawingManager;
core.background.BackgroundDrawingManager.prototype = $extend(port.browser.DrawingManager.prototype,{
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
			var matrix = new core.geom.Matrix();
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
		var fillStyle = core.dom.FillStyleValue.monochrome(color);
		var lineStyle = core.dom.LineStyleValue.none;
		this.beginFill(fillStyle,lineStyle);
		this.drawRect(Math.round(backgroundPaintingBox.x),Math.round(backgroundPaintingBox.y),Math.round(backgroundPaintingBox.width),Math.round(backgroundPaintingBox.height));
		this.endFill();
	}
	,drawBackgroundGradient: function(gradient,backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
		var gradientSurface = new port.browser.DrawingManager(core.nativeElement.NativeElementManager.createNativeElement(core.nativeElement.NativeElementTypeValue.graphic),computedBackgroundSize.width,computedBackgroundSize.height);
		var fillStyle;
		var lineStyle = core.dom.LineStyleValue.none;
		var $e = (gradient);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			var gradientStyle = { gradientType : core.dom.GradientTypeValue.linear, gradientStops : this.getGradientStops(value.colorStops), rotation : this.getRotation(value.angle)};
			fillStyle = core.dom.FillStyleValue.gradient(gradientStyle);
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
			var color = core.unit.UnitManager.getColorDataFromColorValue(value[i].color);
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
			rotation = Math.round(core.unit.UnitManager.getDegreeFromAngle(value1));
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
	,__class__: core.background.BackgroundDrawingManager
});
port.browser.Mouse = $hxClasses["port.browser.Mouse"] = function(htmlElement) {
	core.mouse.AbstractMouse.call(this,htmlElement);
	this._clickEvent = "click";
	this._mouseDownEvent = "mousedown";
	this._mouseUpEvent = "mouseup";
	this._mouseOverEvent = "mouseover";
	this._mouseOutEvent = "mouseout";
	this._mouseMoveEvent = "mousemove";
}
port.browser.Mouse.__name__ = ["port","browser","Mouse"];
port.browser.Mouse.__super__ = core.mouse.AbstractMouse;
port.browser.Mouse.prototype = $extend(core.mouse.AbstractMouse.prototype,{
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
		var mouseEvent = new core.event.MouseEvent(eventType,this._htmlElement,0.0,event.stageX,event.stageY,event.localX,event.localY,event.ctrlKey,event.shiftKey,event.altKey);
		return mouseEvent;
	}
	,__class__: port.browser.Mouse
});
haxe.Http = $hxClasses["haxe.Http"] = function(url) {
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
	,onData: function(data) {
	}
	,onError: function(msg) {
	}
	,onStatus: function(status) {
	}
	,__class__: haxe.Http
}
core.style.computer.BackgroundStylesComputer = $hxClasses["core.style.computer.BackgroundStylesComputer"] = function() {
}
core.style.computer.BackgroundStylesComputer.__name__ = ["core","style","computer","BackgroundStylesComputer"];
core.style.computer.BackgroundStylesComputer.compute = function(style) {
	style.getComputedStyle().backgroundColor = core.style.computer.BackgroundStylesComputer.getComputedBackgroundColor(style);
	style.getComputedStyle().backgroundRepeat = style.getBackgroundRepeat();
	style.getComputedStyle().backgroundClip = style.getBackgroundClip();
	style.getComputedStyle().backgroundSize = style.getBackgroundSize();
	style.getComputedStyle().backgroundPosition = style.getBackgroundPosition();
	style.getComputedStyle().backgroundOrigin = style.getBackgroundOrigin();
	style.getComputedStyle().backgroundImage = style.getBackgroundImage();
}
core.style.computer.BackgroundStylesComputer.computeIndividualBackground = function(style,backgroundBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	var backgroundPositioningArea = core.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea(style,backgroundOrigin,backgroundBox);
	var computedBackgroundSize = core.style.computer.BackgroundStylesComputer.getComputedBackgroundSize(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundPosition = core.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundClip = core.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea(style,backgroundClip,backgroundBox);
	var computedBackgroundStyle = { backgroundOrigin : backgroundPositioningArea, backgroundClip : computedBackgroundClip, backgroundRepeat : backgroundRepeat, backgroundImage : backgroundImage, backgroundSize : computedBackgroundSize, backgroundPosition : computedBackgroundPosition};
	return computedBackgroundStyle;
}
core.style.computer.BackgroundStylesComputer.getComputedBackgroundColor = function(style) {
	var computedColor;
	computedColor = core.unit.UnitManager.getColorDataFromColorValue(style.getBackgroundColor());
	return computedColor;
}
core.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition = function(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,emReference,exReference) {
	var computedBackgroundXPosition = core.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition(backgroundPosition.x,Math.round(backgroundPositioningArea.width),computedBackgroundSize.width,emReference,exReference);
	var computedBackgroundYPosition = core.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition(backgroundPosition.y,Math.round(backgroundPositioningArea.height),computedBackgroundSize.height,emReference,exReference);
	var computedBackgroundPosition = { x : computedBackgroundXPosition, y : computedBackgroundYPosition};
	return computedBackgroundPosition;
}
core.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	var computedBackgroundXPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundXPosition = core.unit.UnitManager.getPixelFromLength(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundXPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundXPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundXPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundXPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	return computedBackgroundXPosition;
}
core.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	var computedBackgroundYPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundYPosition = core.unit.UnitManager.getPixelFromLength(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundYPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundYPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundYPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundYPosition = Math.round(core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	return computedBackgroundYPosition;
}
core.style.computer.BackgroundStylesComputer.getComputedBackgroundSize = function(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference) {
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
		computedBackgroundSize = { width : core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.x,value.y,Math.round(backgroundPositioningArea.width),Math.round(backgroundPositioningArea.height),intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference), height : core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.y,value.x,Math.round(backgroundPositioningArea.height),Math.round(backgroundPositioningArea.width),intrinsicHeight,intrinsicWidth,intrinsicRatio,emReference,exReference)};
		break;
	}
	return computedBackgroundSize;
}
core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData = function(value,opositeBackgroundSizeValue,backgroundPositioningAreaDimension,opositeBackgroundAreaDimension,intrinsicDimension,opositeIntrinsicDimension,intrinsicRatio,emReference,exReference) {
	var backgroundSizeStyleDimension;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		backgroundSizeStyleDimension = core.unit.UnitManager.getPixelFromLength(value1,emReference,exReference);
		break;
	case 1:
		var value1 = $e[2];
		backgroundSizeStyleDimension = Math.round(core.unit.UnitManager.getPixelFromPercent(value1,backgroundPositioningAreaDimension));
		break;
	case 2:
		if(intrinsicDimension != null && opositeBackgroundSizeValue == core.style.BackgroundSizeDimension.cssAuto) backgroundSizeStyleDimension = intrinsicDimension; else if(opositeIntrinsicDimension != null && intrinsicRatio != null) {
			var opositeDimension = core.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(opositeBackgroundSizeValue,value,opositeBackgroundAreaDimension,backgroundPositioningAreaDimension,opositeIntrinsicDimension,intrinsicDimension,intrinsicRatio,emReference,exReference);
			backgroundSizeStyleDimension = Math.round(opositeDimension * intrinsicRatio);
		} else backgroundSizeStyleDimension = Math.round(core.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension));
		break;
	}
	return backgroundSizeStyleDimension;
}
core.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea = function(style,backgroundOrigin,backgroundBox) {
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
core.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea = function(style,backgroundClip,backgroundBox) {
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
core.style.computer.BackgroundStylesComputer.prototype = {
	__class__: core.style.computer.BackgroundStylesComputer
}
port.browser.HTMLImageElement = $hxClasses["port.browser.HTMLImageElement"] = function() {
	core.html.AbstractHTMLImageElement.call(this);
}
port.browser.HTMLImageElement.__name__ = ["port","browser","HTMLImageElement"];
port.browser.HTMLImageElement.__super__ = core.html.AbstractHTMLImageElement;
port.browser.HTMLImageElement.prototype = $extend(core.html.AbstractHTMLImageElement.prototype,{
	initNativeElement: function() {
		this._nativeElement = this._embeddedAsset;
	}
	,__class__: port.browser.HTMLImageElement
});
core.html.HTMLDocument = $hxClasses["core.html.HTMLDocument"] = function() {
	core.dom.Document.call(this);
	this._body = new core.html.HTMLBodyElement();
	cocktailCore.focus.FocusManager.getInstance().setBodyElement(this._body);
	this._window = new port.browser.Window();
	this._window.set_onResize(this.onWindowResize.$bind(this));
}
core.html.HTMLDocument.__name__ = ["core","html","HTMLDocument"];
core.html.HTMLDocument.__super__ = core.dom.Document;
core.html.HTMLDocument.prototype = $extend(core.dom.Document.prototype,{
	_body: null
	,body: null
	,_window: null
	,createElement: function(tagName) {
		var element;
		switch(tagName.toLowerCase()) {
		case "img":
			element = new port.browser.HTMLImageElement();
			break;
		case "canvas":
			element = new core.html.HTMLCanvasElement();
			break;
		case "input":
			element = new port.browser.HTMLInputElement();
			break;
		case "a":
			element = new port.browser.HTMLAnchorElement();
			break;
		default:
			element = new port.browser.HTMLElement(tagName);
		}
		return element;
	}
	,onWindowResize: function(event) {
		this._body.get_style().invalidate();
	}
	,get_body: function() {
		return this._body;
	}
	,__class__: core.html.HTMLDocument
	,__properties__: $extend(core.dom.Document.prototype.__properties__,{get_body:"get_body"})
});
core.style.computer.boxComputers.PositionedBoxStylesComputer = $hxClasses["core.style.computer.boxComputers.PositionedBoxStylesComputer"] = function() {
	core.style.computer.boxComputers.BoxStylesComputer.call(this);
}
core.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["core","style","computer","boxComputers","PositionedBoxStylesComputer"];
core.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = core.style.computer.boxComputers.BoxStylesComputer;
core.style.computer.boxComputers.PositionedBoxStylesComputer.prototype = $extend(core.style.computer.boxComputers.BoxStylesComputer.prototype,{
	shrinkToFit: function(style,containingHTMLElementData,minimumWidth) {
		var shrinkedWidth;
		if(style.getLeft() == core.style.PositionOffset.cssAuto || style.getRight() == core.style.PositionOffset.cssAuto) {
			var computedStyle = style.getComputedStyle();
			shrinkedWidth = this.doShrinkToFit(style,containingHTMLElementData,minimumWidth);
			if(style.getLeft() == core.style.PositionOffset.cssAuto && style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
		} else shrinkedWidth = style.getComputedStyle().width;
		shrinkedWidth = this.constrainWidth(style,shrinkedWidth);
		return shrinkedWidth;
	}
	,applyContentHeight: function(style,containingHTMLElementData,childrenHeight) {
		var height;
		if(style.getTop() != core.style.PositionOffset.cssAuto && style.getBottom() != core.style.PositionOffset.cssAuto) {
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
		if(style.getMarginLeft() == core.style.Margin.cssAuto) computedStyle.marginLeft = 0; else computedStyle.marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
		if(style.getMarginRight() == core.style.Margin.cssAuto) computedStyle.marginRight = 0; else computedStyle.marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
		if(style.getLeft() != core.style.PositionOffset.cssAuto && style.getRight() != core.style.PositionOffset.cssAuto) {
			computedStyle.left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			computedStyle.right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight);
		} else this.setComputedWidth(style,1000000);
	}
	,measureWidth: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		this.setComputedWidth(style,this.getComputedWidth(style,containingHTMLElementData));
		if(style.getLeft() != core.style.PositionOffset.cssAuto && style.getRight() != core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == core.style.Margin.cssAuto && style.getMarginRight() == core.style.Margin.cssAuto) {
				var computedMargin = Math.round((containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginLeft = computedMargin;
					style.getComputedStyle().marginRight = computedMargin;
				} else {
					style.getComputedStyle().marginLeft = 0;
					style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			} else if(style.getMarginLeft() == core.style.Margin.cssAuto) {
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
				style.getComputedStyle().marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			} else if(style.getMarginRight() == core.style.Margin.cssAuto) {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
				style.getComputedStyle().marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			} else {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
			}
		} else {
			if(style.getMarginLeft() == core.style.Margin.cssAuto) style.getComputedStyle().marginLeft = 0; else style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingHTMLElementData);
			if(style.getMarginRight() == core.style.Margin.cssAuto) style.getComputedStyle().marginRight = 0; else style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingHTMLElementData);
			if(style.getLeft() == core.style.PositionOffset.cssAuto && style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingHTMLElementData);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			} else if(style.getRight() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingHTMLElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
	}
	,measureAutoHeight: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getMarginTop() == core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
		if(style.getMarginBottom() == core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
		if(style.getTop() != core.style.PositionOffset.cssAuto && style.getBottom() != core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,containingHTMLElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom);
		} else if(style.getBottom() == core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
		} else if(style.getTop() == core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().top = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
		}
	}
	,measureHeight: function(style,containingHTMLElementData) {
		var computedStyle = style.getComputedStyle();
		this.setComputedHeight(style,this.getComputedHeight(style,containingHTMLElementData));
		if(style.getTop() != core.style.PositionOffset.cssAuto && style.getBottom() != core.style.PositionOffset.cssAuto) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == core.style.Margin.cssAuto && style.getMarginBottom() == core.style.Margin.cssAuto) {
				var computedMargin = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginBottom = 0;
					style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			} else if(style.getMarginTop() == core.style.Margin.cssAuto) {
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
				style.getComputedStyle().marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			} else if(style.getMarginBottom() == core.style.Margin.cssAuto) {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
				style.getComputedStyle().marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			} else {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
			}
		} else {
			if(style.getMarginTop() == core.style.Margin.cssAuto) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingHTMLElementData);
			if(style.getMarginBottom() == core.style.Margin.cssAuto) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingHTMLElementData);
			if(style.getTop() == core.style.PositionOffset.cssAuto && style.getBottom() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingHTMLElementData);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getBottom() == core.style.PositionOffset.cssAuto) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingHTMLElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == core.style.PositionOffset.cssAuto) {
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
	,__class__: core.style.computer.boxComputers.PositionedBoxStylesComputer
});
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
	String.prototype.__class__ = $hxClasses["String"] = String;
	String.__name__ = ["String"];
	Array.prototype.__class__ = $hxClasses["Array"] = Array;
	Array.__name__ = ["Array"];
	Int = $hxClasses["Int"] = { __name__ : ["Int"]};
	Dynamic = $hxClasses["Dynamic"] = { __name__ : ["Dynamic"]};
	Float = $hxClasses["Float"] = Number;
	Float.__name__ = ["Float"];
	Bool = $hxClasses["Bool"] = { __ename__ : ["Bool"]};
	Class = $hxClasses["Class"] = { __name__ : ["Class"]};
	Enum = { };
	Void = $hxClasses["Void"] = { __ename__ : ["Void"]};
}
if(typeof(haxe_timers) == "undefined") haxe_timers = [];
core.html.AbstractHTMLInputElement.HTML_INPUT_TAG_NAME = "input";
port.browser.DrawingManager.CAPS_STYLE_VALUE_NONE = "butt";
port.browser.DrawingManager.CAPS_STYLE_VALUE_ROUND = "round";
port.browser.DrawingManager.CAPS_STYLE_VALUE_SQUARE = "square";
port.browser.DrawingManager.JOINT_STYLE_VALUE_ROUND = "round";
port.browser.DrawingManager.JOINT_STYLE_VALUE_MITER = "miter";
port.browser.DrawingManager.JOINT_STYLE_VALUE_BEVEL = "bevel";
port.browser.DrawingManager.CANVAS_PATTERN_REPEAT = "repeat";
port.browser.DrawingManager.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
core.event.Event.SCROLL = "scroll";
core.event.Event.LOAD = "load";
core.event.Event.FOCUS = "focus";
core.event.Event.BLUR = "blur";
core.event.Event.ERROR = "error";
core.event.Event.READY_STATE_CHANGE = "readystatechange";
core.event.Event.RESIZE = "resize";
core.event.KeyboardEvent.KEY_DOWN = "keydown";
core.event.KeyboardEvent.KEY_UP = "keyup";
port.browser.MouseCursor.MOUSE_CURSOR_STYLE_NONE = "none";
port.browser.MouseCursor.MOUSE_CURSOR_STYLE_POINTER = "pointer";
port.browser.MouseCursor.MOUSE_CURSOR_STYLE_TEXT = "text";
port.browser.MouseCursor.MOUSE_CURSOR_STYLE_AUTO = "auto";
core.resource.XMLHTTPRequest.READY_STATE_UNSENT = 0;
core.resource.XMLHTTPRequest.READY_STATE_OPENED = 1;
core.resource.XMLHTTPRequest.READY_STATE_HEADERS_RECEIVED = 2;
core.resource.XMLHTTPRequest.READY_STATE_LOADING = 3;
core.resource.XMLHTTPRequest.READY_STATE_DONE = 4;
core.html.HTMLBodyElement.HTML_BODY_TAG_NAME = "body";
core.keyboard.AbstractKeyboard.TAB = 9;
core.keyboard.AbstractKeyboard.ENTER = 13;
core.keyboard.AbstractKeyboard.SPACE = 32;
port.browser.Keyboard.KEY_DOWN_EVENT = "keydown";
port.browser.Keyboard.KEY_UP_EVENT = "keyup";
js.Lib.onerror = null;
core.event.MouseEvent.CLICK = "click";
core.event.MouseEvent.MOUSE_UP = "mouseup";
core.event.MouseEvent.MOUSE_DOWN = "mousedown";
core.event.MouseEvent.MOUSE_OVER = "mouseover";
core.event.MouseEvent.MOUSE_OUT = "mouseout";
core.event.MouseEvent.MOUSE_MOVE = "mousemove";
core.html.AbstractHTMLAnchorElement.HTML_ANCHOR_TAG_NAME = "a";
core.html.AbstractHTMLImageElement.HTML_IMAGE_TAG_NAME = "img";
core.html.HTMLCanvasElement.CANVAS_INTRINSIC_HEIGHT = 150;
core.html.HTMLCanvasElement.CANVAS_INTRINSIC_WIDTH = 300;
core.html.HTMLCanvasElement.HTML_CANVAS_TAG_NAME = "canvas";
port.browser.Mouse.MOUSE_CLICK_EVENT = "click";
port.browser.Mouse.MOUSE_UP_EVENT = "mouseup";
port.browser.Mouse.MOUSE_DOWN_EVENT = "mousedown";
port.browser.Mouse.MOUSE_OVER_EVENT = "mouseover";
port.browser.Mouse.MOUSE_OUT_EVENT = "mouseout";
port.browser.Mouse.MOUSE_MOVE_EVENT = "mousemove";
core.html.HTMLDocument.HTML_IMAGE_ELEMENT_TAG_NAME = "img";
core.html.HTMLDocument.HTML_CANVAS_ELEMENT_TAG_NAME = "canvas";
core.html.HTMLDocument.HTML_INPUT_ELEMENT_TAG_NAME = "input";
core.html.HTMLDocument.HTML_ANCHOR_ELEMENT_TAG_NAME = "a";
Lexa.main()