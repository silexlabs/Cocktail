var $_, $hxClasses = $hxClasses || {}, $estr = function() { return js.Boot.__string_rec(this,''); }
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var cocktailCore = cocktailCore || {}
if(!cocktailCore.domElement) cocktailCore.domElement = {}
if(!cocktailCore.domElement["abstract"]) cocktailCore.domElement["abstract"] = {}
cocktailCore.domElement.abstract.AbstractDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::new");
	var $spos = $s.length;
	if(nativeElement != null) this.setNativeElement(nativeElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractDOMElement"];
cocktailCore.domElement.abstract.AbstractDOMElement.prototype = {
	_mouse: null
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
	,_onMouseDoubleClick: null
	,onMouseDoubleClick: null
	,_keyboard: null
	,_onKeyDown: null
	,onKeyDown: null
	,_onKeyUp: null
	,onKeyUp: null
	,_tabEnabled: null
	,tabEnabled: null
	,_tabIndex: null
	,tabIndex: null
	,_onFocusIn: null
	,onFocusIn: null
	,_onFocusOut: null
	,onFocusOut: null
	,_onScroll: null
	,onScroll: null
	,_nativeElement: null
	,nativeElement: null
	,_parent: null
	,parent: null
	,x: null
	,globalX: null
	,y: null
	,globalY: null
	,width: null
	,height: null
	,offsetWidth: null
	,offsetHeight: null
	,_style: null
	,style: null
	,matrix: null
	,scaleX: null
	,scaleY: null
	,rotation: null
	,alpha: null
	,isVisible: null
	,init: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::init");
		var $spos = $s.length;
		this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
		this.initKeyboard();
		this.initStyle();
		this.initFocus();
		$s.pop();
	}
	,initKeyboard: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::initKeyboard");
		var $spos = $s.length;
		this._keyboard = new cocktailCore.keyboard.js.Keyboard(this._nativeElement);
		$s.pop();
	}
	,initStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::initStyle");
		var $spos = $s.length;
		$s.pop();
	}
	,initFocus: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::initFocus");
		var $spos = $s.length;
		this._tabIndex = 0;
		this._tabEnabled = false;
		$s.pop();
	}
	,getParent: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getParent");
		var $spos = $s.length;
		var $tmp = this._parent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setParent: function(domElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setParent");
		var $spos = $s.length;
		this._parent = domElement;
		var $tmp = this._parent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeElement: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setNativeElement");
		var $spos = $s.length;
		this._nativeElement = value;
		this.init();
		$s.pop();
		return value;
		$s.pop();
	}
	,getNativeElement: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getNativeElement");
		var $spos = $s.length;
		var $tmp = this._nativeElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setIsVisible: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setIsVisible");
		var $spos = $s.length;
		var visibility;
		if(value == true) visibility = cocktail.style.VisibilityStyleValue.visible; else visibility = cocktail.style.VisibilityStyleValue.hidden;
		this._style.setVisibility(visibility);
		$s.pop();
		return value;
		$s.pop();
	}
	,getIsVisible: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getIsVisible");
		var $spos = $s.length;
		var $tmp = this._style.getNativeVisibility();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setAlpha: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setAlpha");
		var $spos = $s.length;
		this._style.setOpacity(cocktail.style.OpacityStyleValue.number(value));
		$s.pop();
		return value;
		$s.pop();
	}
	,getAlpha: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getAlpha");
		var $spos = $s.length;
		var $tmp = this._style.getNativeOpacity();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMatrix: function(matrix) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setMatrix");
		var $spos = $s.length;
		this._style.setNativeMatrix(matrix);
		$s.pop();
		return matrix;
		$s.pop();
	}
	,getMatrix: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getMatrix");
		var $spos = $s.length;
		var $tmp = this._style.getNativeMatrix();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setScaleX: function(scaleX) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setScaleX");
		var $spos = $s.length;
		this._style.setNativeScaleX(scaleX);
		this.updateTransforms();
		$s.pop();
		return scaleX;
		$s.pop();
	}
	,getScaleX: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getScaleX");
		var $spos = $s.length;
		var $tmp = this._style.getNativeScaleX();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setScaleY: function(scaleY) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setScaleY");
		var $spos = $s.length;
		this._style.setNativeScaleY(scaleY);
		this.updateTransforms();
		$s.pop();
		return scaleY;
		$s.pop();
	}
	,getScaleY: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getScaleY");
		var $spos = $s.length;
		var $tmp = this._style.getNativeScaleY();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setRotation: function(angle) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setRotation");
		var $spos = $s.length;
		this._style.setNativeRotation(cocktailCore.unit.UnitManager.getRadFromAngleValue(cocktail.unit.AngleValue.deg(angle)));
		this.updateTransforms();
		$s.pop();
		return angle;
		$s.pop();
	}
	,getRotation: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getRotation");
		var $spos = $s.length;
		var $tmp = Math.round(cocktailCore.unit.UnitManager.getDegreeFromAngleValue(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())));
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,updateTransforms: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::updateTransforms");
		var $spos = $s.length;
		this._style.setTransformOrigin({ x : cocktail.style.TransformOriginXStyleValue.left, y : cocktail.style.TransformOriginYStyleValue.top});
		this._style.setTransform(cocktail.style.TransformStyleValue.transformFunctions([cocktail.style.TransformFunctionValue.rotate(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())),cocktail.style.TransformFunctionValue.scaleY(this._style.getNativeScaleY()),cocktail.style.TransformFunctionValue.scaleX(this._style.getNativeScaleX())]));
		$s.pop();
	}
	,setOnMouseDown: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseDown");
		var $spos = $s.length;
		this._onMouseDown = value;
		if(this._onMouseDown == null) this._mouse.setOnMouseDown(null); else this._mouse.setOnMouseDown(this.onMouseDownCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseDown: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseDown");
		var $spos = $s.length;
		var $tmp = this._onMouseDown;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseUp: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseUp");
		var $spos = $s.length;
		this._onMouseUp = value;
		if(this._onMouseUp == null) this._mouse.setOnMouseUp(null); else this._mouse.setOnMouseUp(this.onMouseUpCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseUp: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseUp");
		var $spos = $s.length;
		var $tmp = this._onMouseUp;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseOver: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseOver");
		var $spos = $s.length;
		this._onMouseOver = value;
		if(this._onMouseOver == null) this._mouse.setOnMouseOver(null); else this._mouse.setOnMouseOver(this.onMouseOverCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseOver: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseOver");
		var $spos = $s.length;
		var $tmp = this._onMouseOver;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseOut: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseOut");
		var $spos = $s.length;
		this._onMouseOut = value;
		if(this._onMouseOut == null) this._mouse.setOnMouseOut(null); else this._mouse.setOnMouseOut(this.onMouseOutCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseOut: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseOut");
		var $spos = $s.length;
		var $tmp = this._onMouseOut;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseMove: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseMove");
		var $spos = $s.length;
		this._onMouseMove = value;
		if(this._onMouseMove == null) this._mouse.setOnMouseMove(null); else this._mouse.setOnMouseMove(this.onMouseMoveCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseMove: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseMove");
		var $spos = $s.length;
		var $tmp = this._onMouseMove;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseDoubleClick: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseDoubleClick");
		var $spos = $s.length;
		this._onMouseDoubleClick = value;
		if(this._onMouseDoubleClick == null) this._mouse.setOnMouseDoubleClick(null); else this._mouse.setOnMouseDoubleClick(this.onMouseDoubleClickCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnMouseDoubleClick: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseDoubleClick");
		var $spos = $s.length;
		var $tmp = this._onMouseDoubleClick;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,onMouseDownCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseDownCallback");
		var $spos = $s.length;
		this._onMouseDown(mouseEventData);
		$s.pop();
	}
	,onMouseUpCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseUpCallback");
		var $spos = $s.length;
		this._onMouseUp(mouseEventData);
		$s.pop();
	}
	,onMouseMoveCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseMoveCallback");
		var $spos = $s.length;
		this._onMouseMove(mouseEventData);
		$s.pop();
	}
	,onMouseOverCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseOverCallback");
		var $spos = $s.length;
		this._onMouseOver(mouseEventData);
		$s.pop();
	}
	,onMouseOutCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseOutCallback");
		var $spos = $s.length;
		this._onMouseOut(mouseEventData);
		$s.pop();
	}
	,onMouseDoubleClickCallback: function(mouseEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onMouseDoubleClickCallback");
		var $spos = $s.length;
		this._onMouseDoubleClick(mouseEventData);
		$s.pop();
	}
	,setOnKeyDown: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnKeyDown");
		var $spos = $s.length;
		this._onKeyDown = value;
		if(this._onKeyDown == null) this._keyboard.setOnKeyDown(null); else this._keyboard.setOnKeyDown(this.onKeyDownCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnKeyDown: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnKeyDown");
		var $spos = $s.length;
		var $tmp = this._keyboard.getOnKeyDown();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnKeyUp: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnKeyUp");
		var $spos = $s.length;
		this._onKeyUp = value;
		if(this._onKeyUp == null) this._keyboard.setOnKeyUp(null); else this._keyboard.setOnKeyUp(this.onKeyUpCallback.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,getOnKeyUp: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnKeyUp");
		var $spos = $s.length;
		var $tmp = this._keyboard.getOnKeyUp();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,onKeyDownCallback: function(keyEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onKeyDownCallback");
		var $spos = $s.length;
		this._onKeyDown(keyEventData);
		$s.pop();
	}
	,onKeyUpCallback: function(keyEventData) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onKeyUpCallback");
		var $spos = $s.length;
		this._onKeyUp(keyEventData);
		$s.pop();
	}
	,focus: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::focus");
		var $spos = $s.length;
		cocktailCore.focus.FocusManager.getInstance().setActiveDOMElement(this);
		$s.pop();
	}
	,setOnFocusIn: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnFocusIn");
		var $spos = $s.length;
		var $tmp = this._onFocusIn = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnFocusIn: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnFocusIn");
		var $spos = $s.length;
		var $tmp = this._onFocusIn;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnFocusOut: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnFocusOut");
		var $spos = $s.length;
		var $tmp = this._onFocusOut = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnFocusOut: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnFocusOut");
		var $spos = $s.length;
		var $tmp = this._onFocusOut;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTabEnabled: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setTabEnabled");
		var $spos = $s.length;
		cocktailCore.focus.FocusManager.getInstance().invalidate();
		var $tmp = this._tabEnabled = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTabEnabled: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getTabEnabled");
		var $spos = $s.length;
		var $tmp = this._tabEnabled;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTabIndex: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setTabIndex");
		var $spos = $s.length;
		cocktailCore.focus.FocusManager.getInstance().invalidate();
		var $tmp = this._tabIndex = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTabIndex: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getTabIndex");
		var $spos = $s.length;
		var $tmp = this._tabIndex;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnScroll: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnScroll");
		var $spos = $s.length;
		var $tmp = this._onScroll = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnScroll: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnScroll");
		var $spos = $s.length;
		var $tmp = this._onScroll;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,onScrollCallback: function(event) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::onScrollCallback");
		var $spos = $s.length;
		if(this._onScroll != null) this._onScroll(event);
		$s.pop();
	}
	,setX: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setX");
		var $spos = $s.length;
		this._style.setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeX(this,value);
		$s.pop();
		return value;
		$s.pop();
	}
	,getX: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getX");
		var $spos = $s.length;
		var $tmp = this._style.getNativeX();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setY: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setY");
		var $spos = $s.length;
		this._style.setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeY(this,value);
		$s.pop();
		return value;
		$s.pop();
	}
	,getY: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getY");
		var $spos = $s.length;
		var $tmp = this._style.getNativeY();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setWidth");
		var $spos = $s.length;
		this._style.setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeWidth(value);
		$s.pop();
		return value;
		$s.pop();
	}
	,getWidth: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getWidth");
		var $spos = $s.length;
		var $tmp = this._style.getNativeWidth();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setHeight");
		var $spos = $s.length;
		this._style.setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeHeight(value);
		$s.pop();
		return value;
		$s.pop();
	}
	,getHeight: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getHeight");
		var $spos = $s.length;
		var $tmp = this._style.getNativeHeight();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOffsetWidth: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOffsetWidth");
		var $spos = $s.length;
		var computedStyle = this._style.getComputedStyle();
		var $tmp = computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOffsetHeight: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOffsetHeight");
		var $spos = $s.length;
		var computedStyle = this._style.getComputedStyle();
		var $tmp = computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setGlobalX: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setGlobalX");
		var $spos = $s.length;
		var localX = value;
		if(this._parent != null) {
			var parentGlobalX = this._parent.getGlobalX();
			localX -= parentGlobalX;
		} else localX = 0;
		this._style.setNativeX(this,localX);
		$s.pop();
		return value;
		$s.pop();
	}
	,getGlobalX: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getGlobalX");
		var $spos = $s.length;
		var newGlobalX = this._style.getNativeX();
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalX += parentDOMElement.getStyle().getNativeX();
				parentDOMElement = parentDOMElement.getParent();
			}
		} else newGlobalX = 0;
		$s.pop();
		return newGlobalX;
		$s.pop();
	}
	,setGlobalY: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setGlobalY");
		var $spos = $s.length;
		var localY = value;
		if(this._parent != null) {
			var parentGlobalY = this._parent.getGlobalY();
			localY -= parentGlobalY;
		} else localY = 0;
		this._style.setNativeY(this,localY);
		$s.pop();
		return value;
		$s.pop();
	}
	,getGlobalY: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getGlobalY");
		var $spos = $s.length;
		var newGlobalY = this._style.getNativeY();
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalY += parentDOMElement.getStyle().getNativeY();
				parentDOMElement = parentDOMElement.getParent();
			}
		} else newGlobalY = 0;
		$s.pop();
		return newGlobalY;
		$s.pop();
	}
	,getStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getStyle");
		var $spos = $s.length;
		var $tmp = this._style;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractDOMElement
	,__properties__: {set_isVisible:"setIsVisible",get_isVisible:"getIsVisible",set_alpha:"setAlpha",get_alpha:"getAlpha",set_rotation:"setRotation",get_rotation:"getRotation",set_scaleY:"setScaleY",get_scaleY:"getScaleY",set_scaleX:"setScaleX",get_scaleX:"getScaleX",set_matrix:"setMatrix",get_matrix:"getMatrix",get_style:"getStyle",get_offsetHeight:"getOffsetHeight",get_offsetWidth:"getOffsetWidth",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_globalY:"setGlobalY",get_globalY:"getGlobalY",set_y:"setY",get_y:"getY",set_globalX:"setGlobalX",get_globalX:"getGlobalX",set_x:"setX",get_x:"getX",set_parent:"setParent",get_parent:"getParent",set_nativeElement:"setNativeElement",get_nativeElement:"getNativeElement",set_onScroll:"setOnScroll",get_onScroll:"getOnScroll",set_onFocusOut:"setOnFocusOut",get_onFocusOut:"getOnFocusOut",set_onFocusIn:"setOnFocusIn",get_onFocusIn:"getOnFocusIn",set_tabIndex:"setTabIndex",get_tabIndex:"getTabIndex",set_tabEnabled:"setTabEnabled",get_tabEnabled:"getTabEnabled",set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown",set_onMouseDoubleClick:"setOnMouseDoubleClick",get_onMouseDoubleClick:"getOnMouseDoubleClick",set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown"}
}
if(!cocktailCore.domElement.js) cocktailCore.domElement.js = {}
cocktailCore.domElement.js.DOMElement = $hxClasses["cocktailCore.domElement.js.DOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.js.DOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.__name__ = ["cocktailCore","domElement","js","DOMElement"];
cocktailCore.domElement.js.DOMElement.__super__ = cocktailCore.domElement.abstract.AbstractDOMElement;
cocktailCore.domElement.js.DOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractDOMElement.prototype,{
	getOffsetWidth: function() {
		$s.push("cocktailCore.domElement.js.DOMElement::getOffsetWidth");
		var $spos = $s.length;
		var $tmp = this._nativeElement.offsetWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOffsetHeight: function() {
		$s.push("cocktailCore.domElement.js.DOMElement::getOffsetHeight");
		var $spos = $s.length;
		var $tmp = this._nativeElement.offsetHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnFocusIn: function(value) {
		$s.push("cocktailCore.domElement.js.DOMElement::setOnFocusIn");
		var $spos = $s.length;
		if(value == null) this._nativeElement.onfocus = null; else this._nativeElement.onfocus = this.onNativeFocusIn.$bind(this);
		var $tmp = this._onFocusIn = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnFocusOut: function(value) {
		$s.push("cocktailCore.domElement.js.DOMElement::setOnFocusOut");
		var $spos = $s.length;
		if(value == null) this._nativeElement.onblur = null; else this._nativeElement.onblur = this.onNativeFocusOut.$bind(this);
		var $tmp = this._onFocusOut = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTabEnabled: function(value) {
		$s.push("cocktailCore.domElement.js.DOMElement::setTabEnabled");
		var $spos = $s.length;
		if(value == true) this._nativeElement.tabIndex = this.getTabIndex(); else this._nativeElement.tabIndex = null;
		var $tmp = this._tabEnabled = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTabIndex: function(value) {
		$s.push("cocktailCore.domElement.js.DOMElement::setTabIndex");
		var $spos = $s.length;
		this._tabIndex = value;
		this.setTabEnabled(this.getTabEnabled());
		var $tmp = this._tabIndex;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,focus: function() {
		$s.push("cocktailCore.domElement.js.DOMElement::focus");
		var $spos = $s.length;
		this._nativeElement.focus();
		$s.pop();
	}
	,onNativeFocusIn: function(event) {
		$s.push("cocktailCore.domElement.js.DOMElement::onNativeFocusIn");
		var $spos = $s.length;
		if(this.getOnFocusIn() != null) (this.getOnFocusIn())();
		$s.pop();
	}
	,onNativeFocusOut: function(event) {
		$s.push("cocktailCore.domElement.js.DOMElement::onNativeFocusOut");
		var $spos = $s.length;
		if(this.getOnFocusOut() != null) (this.getOnFocusOut())();
		$s.pop();
	}
	,setOnScroll: function(value) {
		$s.push("cocktailCore.domElement.js.DOMElement::setOnScroll");
		var $spos = $s.length;
		this._nativeElement.removeEventListener("scroll",this.onNativeScroll.$bind(this));
		this._onScroll = value;
		if(this._onScroll != null) this._nativeElement.addEventListener("scroll",this.onNativeScroll.$bind(this));
		$s.pop();
		return value;
		$s.pop();
	}
	,onNativeScroll: function(event) {
		$s.push("cocktailCore.domElement.js.DOMElement::onNativeScroll");
		var $spos = $s.length;
		var scrollEventData = { scrollLeft : this._nativeElement.scrollLeft, scrollTop : this._nativeElement.scrollTop, scrollWidth : this._nativeElement.scrollWidth, scrollHeight : this._nativeElement.scrollHeight};
		this.onScrollCallback(scrollEventData);
		$s.pop();
	}
	,__class__: cocktailCore.domElement.js.DOMElement
});
cocktailCore.domElement.abstract.AbstractContainerDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractContainerDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral);
	this._children = new Array();
	this._textFragmentDOMElements = new Array();
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractContainerDOMElement"];
cocktailCore.domElement.abstract.AbstractContainerDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype = $extend(cocktailCore.domElement.js.DOMElement.prototype,{
	_semantic: null
	,semantic: null
	,_children: null
	,children: null
	,_textFragmentDOMElements: null
	,initStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::initStyle");
		var $spos = $s.length;
		this._style = new cocktailCore.style.js.ContainerStyle(this);
		$s.pop();
	}
	,addChild: function(domElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addChild");
		var $spos = $s.length;
		if(domElement.getParent() != null) {
			var parent = domElement.getParent();
			parent.removeChild(domElement);
		}
		domElement.setParent(this);
		this._children.push({ child : domElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.domElement});
		this._style.invalidate();
		$s.pop();
	}
	,removeChild: function(domElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::removeChild");
		var $spos = $s.length;
		domElement.setParent(null);
		var newChildrenArray = new Array();
		var _g1 = 0, _g = this._children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._children[i].child != domElement) newChildrenArray.push(this._children[i]);
		}
		this._children = newChildrenArray;
		this._style.invalidate();
		$s.pop();
	}
	,addText: function(textElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addText");
		var $spos = $s.length;
		this._children.push({ child : textElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.textElement});
		textElement.setParent(this);
		$s.pop();
	}
	,removeText: function(textElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::removeText");
		var $spos = $s.length;
		var newChildrenArray = new Array();
		var _g1 = 0, _g = this._children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._children[i].child != textElement) newChildrenArray.push(this._children[i]); else this._children[i].child.parent = null;
		}
		this._children = newChildrenArray;
		$s.pop();
	}
	,getChildren: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::getChildren");
		var $spos = $s.length;
		var $tmp = this._children;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,resetTextFragments: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::resetTextFragments");
		var $spos = $s.length;
		var _g1 = 0, _g = this._textFragmentDOMElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.removeTextFragment(this._textFragmentDOMElements[i]);
		}
		this._textFragmentDOMElements = new Array();
		var _g1 = 0, _g = this._children.length;
		while(_g1 < _g) {
			var i = _g1++;
			switch( (this._children[i].type)[1] ) {
			case 1:
				var textElement = this._children[i].child;
				textElement.reset();
				break;
			default:
			}
		}
		$s.pop();
	}
	,addTextFragment: function(textFragmentDOMElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addTextFragment");
		var $spos = $s.length;
		this._textFragmentDOMElements.push(textFragmentDOMElement);
		$s.pop();
	}
	,removeTextFragment: function(textFragmentDOMElement) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::removeTextFragment");
		var $spos = $s.length;
		$s.pop();
	}
	,setSemantic: function(semantic) {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::setSemantic");
		var $spos = $s.length;
		this._semantic = semantic;
		var $tmp = this._semantic;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getSemantic: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::getSemantic");
		var $spos = $s.length;
		var $tmp = this._semantic;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractContainerDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.DOMElement.prototype.__properties__,{get_children:"getChildren",set_semantic:"setSemantic",get_semantic:"getSemantic"})
});
cocktailCore.domElement.js.ContainerDOMElement = $hxClasses["cocktailCore.domElement.js.ContainerDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.__name__ = ["cocktailCore","domElement","js","ContainerDOMElement"];
cocktailCore.domElement.js.ContainerDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
cocktailCore.domElement.js.ContainerDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype,{
	addChild: function(domElement) {
		$s.push("cocktailCore.domElement.js.ContainerDOMElement::addChild");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild.call(this,domElement);
		this._nativeElement.appendChild(domElement.getNativeElement());
		domElement.getNativeElement().style.zIndex = this._children.length - 1;
		$s.pop();
	}
	,removeChild: function(domElement) {
		$s.push("cocktailCore.domElement.js.ContainerDOMElement::removeChild");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild.call(this,domElement);
		this._nativeElement.removeChild(domElement.getNativeElement());
		$s.pop();
	}
	,addText: function(textElement) {
		$s.push("cocktailCore.domElement.js.ContainerDOMElement::addText");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText.call(this,textElement);
		this.getNativeElement().appendChild(textElement.getNativeText());
		$s.pop();
	}
	,removeText: function(textElement) {
		$s.push("cocktailCore.domElement.js.ContainerDOMElement::removeText");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText.call(this,textElement);
		this._nativeElement.removeChild(textElement.getNativeText());
		$s.pop();
	}
	,setSemantic: function(semantic) {
		$s.push("cocktailCore.domElement.js.ContainerDOMElement::setSemantic");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.setSemantic.call(this,semantic);
		var currentNativeElementContent = this._nativeElement.innerHTML;
		var currentNativeElementAttributes = this._nativeElement.attributes;
		var newNativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom(semantic));
		newNativeElement.innerHTML = currentNativeElementContent;
		var _g1 = 0, _g = currentNativeElementAttributes.length;
		while(_g1 < _g) {
			var i = _g1++;
			newNativeElement.setAttribute(currentNativeElementAttributes[i].nodeName,currentNativeElementAttributes[i].nodeValue);
		}
		this._nativeElement.parentNode.replaceChild(newNativeElement,this._nativeElement);
		this._nativeElement = newNativeElement;
		$s.pop();
		return semantic;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.js.ContainerDOMElement
});
var org = org || {}
if(!org.intermedia) org.intermedia = {}
if(!org.intermedia.view) org.intermedia.view = {}
org.intermedia.view.ViewBase = $hxClasses["org.intermedia.view.ViewBase"] = function() {
	$s.push("org.intermedia.view.ViewBase::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.ContainerDOMElement.call(this);
	this.buildView();
	$s.pop();
}
org.intermedia.view.ViewBase.__name__ = ["org","intermedia","view","ViewBase"];
org.intermedia.view.ViewBase.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
org.intermedia.view.ViewBase.prototype = $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype,{
	_data: null
	,data: null
	,displayLoading: null
	,getData: function() {
		$s.push("org.intermedia.view.ViewBase::getData");
		var $spos = $s.length;
		var $tmp = this._data;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setData: function(v) {
		$s.push("org.intermedia.view.ViewBase::setData");
		var $spos = $s.length;
		this._data = v;
		this.updateView();
		var $tmp = this._data;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,buildView: function() {
		$s.push("org.intermedia.view.ViewBase::buildView");
		var $spos = $s.length;
		$s.pop();
	}
	,updateView: function() {
		$s.push("org.intermedia.view.ViewBase::updateView");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: org.intermedia.view.ViewBase
	,__properties__: $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype.__properties__,{set_data:"setData",get_data:"getData"})
});
org.intermedia.view.HeaderView = $hxClasses["org.intermedia.view.HeaderView"] = function() {
	$s.push("org.intermedia.view.HeaderView::new");
	var $spos = $s.length;
	org.intermedia.view.ViewBase.call(this);
	this._data = "";
	this._backButtonContainer = this.buildBackButtonView();
	$s.pop();
}
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
		$s.push("org.intermedia.view.HeaderView::getDisplayBackButton");
		var $spos = $s.length;
		var $tmp = this._displayBackButton;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setDisplayBackButton: function(v) {
		$s.push("org.intermedia.view.HeaderView::setDisplayBackButton");
		var $spos = $s.length;
		this._displayBackButton = v;
		if(this._displayBackButton) this.addChild(this._backButtonContainer); else if(this._backButtonContainer.getParent() != null) this.removeChild(this._backButtonContainer);
		var $tmp = this._displayBackButton;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,buildView: function() {
		$s.push("org.intermedia.view.HeaderView::buildView");
		var $spos = $s.length;
		org.intermedia.view.HeaderStyle.setHeaderStyle(this);
		this._titleTextElement = new cocktailCore.textElement.js.TextElement(this._data);
		this._titleContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		this._titleContainer.addText(this._titleTextElement);
		org.intermedia.view.HeaderStyle.setHeaderTextStyle(this._titleContainer);
		this.addChild(this._titleContainer);
		$s.pop();
	}
	,updateView: function() {
		$s.push("org.intermedia.view.HeaderView::updateView");
		var $spos = $s.length;
		this._titleContainer.removeText(this._titleTextElement);
		this._titleTextElement = new cocktailCore.textElement.js.TextElement(this._data);
		this._titleContainer.addText(this._titleTextElement);
		$s.pop();
	}
	,buildBackButtonView: function() {
		$s.push("org.intermedia.view.HeaderView::buildBackButtonView");
		var $spos = $s.length;
		var me = this;
		var backButtonContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		org.intermedia.view.HeaderStyle.setBackButtonStyle(backButtonContainer);
		var backButtonArrowLeft = new cocktailCore.domElement.js.ImageDOMElement();
		org.intermedia.view.HeaderStyle.setBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.load("assets/blackButtonLeft.png");
		backButtonContainer.addChild(backButtonArrowLeft);
		var backButtonArrowRight = new cocktailCore.domElement.js.ImageDOMElement();
		org.intermedia.view.HeaderStyle.setBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.load("assets/blackButtonRight.png");
		backButtonContainer.addChild(backButtonArrowRight);
		var backButtonTextContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		org.intermedia.view.HeaderStyle.setBackButtonTextStyle(backButtonTextContainer);
		var backButtonText = new cocktailCore.textElement.js.TextElement("Back");
		backButtonTextContainer.addText(backButtonText);
		backButtonContainer.addChild(backButtonTextContainer);
		backButtonContainer.setOnMouseUp(function(mouseEvent) {
			$s.push("org.intermedia.view.HeaderView::buildBackButtonView@168");
			var $spos = $s.length;
			me.onBackButtonClickCallback();
			$s.pop();
		});
		$s.pop();
		return backButtonContainer;
		$s.pop();
	}
	,onBackButtonClickCallback: function() {
		$s.push("org.intermedia.view.HeaderView::onBackButtonClickCallback");
		var $spos = $s.length;
		if(this.onBackButtonClick != null) this.onBackButtonClick();
		$s.pop();
	}
	,__class__: org.intermedia.view.HeaderView
	,__properties__: $extend(org.intermedia.view.ViewBase.prototype.__properties__,{set_displayBackButton:"setDisplayBackButton",get_displayBackButton:"getDisplayBackButton"})
});
org.intermedia.view.ViewManager = $hxClasses["org.intermedia.view.ViewManager"] = function(applicationModel,applicationController) {
	$s.push("org.intermedia.view.ViewManager::new");
	var $spos = $s.length;
	this._applicationModel = applicationModel;
	this._applicationController = applicationController;
	this._body = new cocktailCore.domElement.js.BodyDOMElement();
	org.intermedia.view.ViewManagerStyle.setBodyStyle(this._body);
	this._header = new org.intermedia.view.HeaderView();
	this._header.setData("Market");
	this._header.onBackButtonClick = this.onHeaderBackButtonPressed.$bind(this);
	this._body.addChild(this._header);
	this._swippableListView = new org.intermedia.view.SwippableListView();
	this._body.addChild(this._swippableListView);
	this._detailView = new org.intermedia.view.DetailView();
	this._currentView = new org.intermedia.view.ViewBase();
	this.init();
	$s.pop();
}
org.intermedia.view.ViewManager.__name__ = ["org","intermedia","view","ViewManager"];
org.intermedia.view.ViewManager.prototype = {
	_body: null
	,_header: null
	,_swippableListView: null
	,_detailView: null
	,_applicationModel: null
	,_applicationController: null
	,_currentView: null
	,init: function() {
		$s.push("org.intermedia.view.ViewManager::init");
		var $spos = $s.length;
		this._applicationModel.onModelStartsLoading = this.onStartLoading.$bind(this);
		this._applicationModel.onModelDataLoadError = this.onLoadingError.$bind(this);
		this._applicationModel.onModelCellDataLoaded = this.onCellDataLoaded.$bind(this);
		this._applicationModel.onModelDetailDataLoaded = this.onDetailDataLoaded.$bind(this);
		this._swippableListView.onListItemSelected = ($_=this._applicationController,$_.openDetailView.$bind($_));
		this._applicationController.loadCellData(5);
		$s.pop();
	}
	,onCellDataLoaded: function(cellsData) {
		$s.push("org.intermedia.view.ViewManager::onCellDataLoaded");
		var $spos = $s.length;
		this._swippableListView.setData(cellsData);
		this.updateHeaderZIndex();
		$s.pop();
	}
	,onDetailDataLoaded: function(detailData) {
		$s.push("org.intermedia.view.ViewManager::onDetailDataLoaded");
		var $spos = $s.length;
		this._detailView.setData(detailData);
		this._header.setData("Infos");
		this._header.setDisplayBackButton(true);
		this._body.removeChild(this._swippableListView);
		this._body.addChild(this._detailView);
		this.updateHeaderZIndex();
		$s.pop();
	}
	,onStartLoading: function() {
		$s.push("org.intermedia.view.ViewManager::onStartLoading");
		var $spos = $s.length;
		this._currentView.displayLoading = true;
		$s.pop();
	}
	,onLoadingError: function(error) {
		$s.push("org.intermedia.view.ViewManager::onLoadingError");
		var $spos = $s.length;
		haxe.Log.trace("Load error: " + Std.string(error),{ fileName : "ViewManager.hx", lineNumber : 152, className : "org.intermedia.view.ViewManager", methodName : "onLoadingError"});
		$s.pop();
	}
	,onHeaderBackButtonPressed: function() {
		$s.push("org.intermedia.view.ViewManager::onHeaderBackButtonPressed");
		var $spos = $s.length;
		this._header.setData("Market");
		this._header.setDisplayBackButton(false);
		this._body.removeChild(this._detailView);
		this._body.addChild(this._swippableListView);
		this.updateHeaderZIndex();
		$s.pop();
	}
	,updateHeaderZIndex: function() {
		$s.push("org.intermedia.view.ViewManager::updateHeaderZIndex");
		var $spos = $s.length;
		this._body.removeChild(this._header);
		this._body.addChild(this._header);
		$s.pop();
	}
	,__class__: org.intermedia.view.ViewManager
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractEmbeddedDOMElement"];
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype = $extend(cocktailCore.domElement.js.DOMElement.prototype,{
	_intrinsicWidth: null
	,intrinsicWidth: null
	,_intrinsicHeight: null
	,intrinsicHeight: null
	,_intrinsicRatio: null
	,intrinsicRatio: null
	,_embeddedAsset: null
	,embeddedAsset: null
	,initStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::initStyle");
		var $spos = $s.length;
		this._style = new cocktailCore.style.js.EmbeddedStyle(this);
		$s.pop();
	}
	,getEmbeddedAsset: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getEmbeddedAsset");
		var $spos = $s.length;
		var $tmp = this._embeddedAsset;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicWidth: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicWidth");
		var $spos = $s.length;
		var $tmp = this._intrinsicWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicHeight: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicHeight");
		var $spos = $s.length;
		var $tmp = this._intrinsicHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicRatio: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicRatio");
		var $spos = $s.length;
		var $tmp = this._intrinsicRatio;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.DOMElement.prototype.__properties__,{get_embeddedAsset:"getEmbeddedAsset",get_intrinsicRatio:"getIntrinsicRatio",get_intrinsicHeight:"getIntrinsicHeight",get_intrinsicWidth:"getIntrinsicWidth"})
});
cocktailCore.domElement.js.EmbeddedDOMElement = $hxClasses["cocktailCore.domElement.js.EmbeddedDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.js.EmbeddedDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.EmbeddedDOMElement.__name__ = ["cocktailCore","domElement","js","EmbeddedDOMElement"];
cocktailCore.domElement.js.EmbeddedDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
cocktailCore.domElement.js.EmbeddedDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.EmbeddedDOMElement
});
cocktailCore.domElement.abstract.AbstractImageDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractImageDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::new");
	var $spos = $s.length;
	this._imageLoader = new cocktailCore.resource.js.ImageLoader();
	this._embeddedAsset = this._imageLoader.getNativeElement();
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractImageDOMElement"];
cocktailCore.domElement.abstract.AbstractImageDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype = $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype,{
	onLoad: null
	,onError: null
	,_src: null
	,src: null
	,_imageLoader: null
	,load: function(url,allowCache) {
		$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::load");
		var $spos = $s.length;
		if(allowCache == null) allowCache = true;
		this._src = url;
		this._imageLoader.load([url],this.onLoadComplete.$bind(this),this.onLoadError.$bind(this),allowCache);
		$s.pop();
	}
	,onLoadComplete: function(image) {
		$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::onLoadComplete");
		var $spos = $s.length;
		this._intrinsicHeight = this._imageLoader.getIntrinsicHeight();
		this._intrinsicWidth = this._imageLoader.getIntrinsicWidth();
		this._intrinsicRatio = this._imageLoader.getIntrinsicRatio();
		this._style.invalidate();
		if(this.onLoad != null) this.onLoad(this);
		$s.pop();
	}
	,onLoadError: function(message) {
		$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::onLoadError");
		var $spos = $s.length;
		if(this.onError != null) this.onError(message);
		$s.pop();
	}
	,getSrc: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::getSrc");
		var $spos = $s.length;
		var $tmp = this._src;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractImageDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__properties__,{get_src:"getSrc"})
});
if(!cocktailCore.viewport) cocktailCore.viewport = {}
if(!cocktailCore.viewport["abstract"]) cocktailCore.viewport["abstract"] = {}
cocktailCore.viewport.abstract.AbstractViewport = $hxClasses["cocktailCore.viewport.abstract.AbstractViewport"] = function() {
	$s.push("cocktailCore.viewport.abstract.AbstractViewport::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.viewport.abstract.AbstractViewport.__name__ = ["cocktailCore","viewport","abstract","AbstractViewport"];
cocktailCore.viewport.abstract.AbstractViewport.prototype = {
	onResize: null
	,onOrientationChange: null
	,width: null
	,height: null
	,orientation: null
	,_lastOrientationObserved: null
	,_addResizeEvent: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_addResizeEvent");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
	}
	,_removeResizeEvent: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_removeResizeEvent");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
	}
	,_addOrientationChangeEvent: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_addOrientationChangeEvent");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
	}
	,_removeOrientationChangeEvent: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_removeOrientationChangeEvent");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
	}
	,_getWidth: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_getWidth");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
		return -1;
		$s.pop();
	}
	,_getHeight: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_getHeight");
		var $spos = $s.length;
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		$s.pop();
		return -1;
		$s.pop();
	}
	,_getOrientation: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_getOrientation");
		var $spos = $s.length;
		if(this._getHeight() > this._getWidth()) {
			var $tmp = cocktail.viewport.OrientationValue.vertical;
			$s.pop();
			return $tmp;
		} else {
			var $tmp = cocktail.viewport.OrientationValue.horizontal;
			$s.pop();
			return $tmp;
		}
		$s.pop();
	}
	,_onResizeCallback: function(e) {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_onResizeCallback");
		var $spos = $s.length;
		if(this._getOnResize() != null) (this._getOnResize())();
		$s.pop();
	}
	,_onOrientationChangeCallback: function(e) {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_onOrientationChangeCallback");
		var $spos = $s.length;
		if(this._getOnOrientationChange() != null && this._lastOrientationObserved != this._getOrientation()) {
			this._lastOrientationObserved = this._getOrientation();
			(this._getOnOrientationChange())();
		}
		$s.pop();
	}
	,_onResize: null
	,_getOnResize: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_getOnResize");
		var $spos = $s.length;
		var $tmp = this._onResize;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,_setOnResize: function(callbackFunction) {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_setOnResize");
		var $spos = $s.length;
		if(this._onResize == null && callbackFunction != null) this._addResizeEvent(); else if(this._onResize != null && callbackFunction == null) this._removeResizeEvent();
		this._onResize = callbackFunction;
		var $tmp = this._onResize;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,_onOrientationChange: null
	,_getOnOrientationChange: function() {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_getOnOrientationChange");
		var $spos = $s.length;
		var $tmp = this._onOrientationChange;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,_setOnOrientationChange: function(callbackFunction) {
		$s.push("cocktailCore.viewport.abstract.AbstractViewport::_setOnOrientationChange");
		var $spos = $s.length;
		this._lastOrientationObserved = this._getOrientation();
		if(this._onOrientationChange == null && callbackFunction != null) this._addOrientationChangeEvent(); else if(this._onOrientationChange != null && callbackFunction == null) this._removeOrientationChangeEvent();
		this._onOrientationChange = callbackFunction;
		var $tmp = this._onOrientationChange;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.viewport.abstract.AbstractViewport
	,__properties__: {get_orientation:"_getOrientation",get_height:"_getHeight",get_width:"_getWidth",set_onOrientationChange:"_setOnOrientationChange",get_onOrientationChange:"_getOnOrientationChange",set_onResize:"_setOnResize",get_onResize:"_getOnResize"}
}
if(!cocktailCore.viewport.js) cocktailCore.viewport.js = {}
cocktailCore.viewport.js.Viewport = $hxClasses["cocktailCore.viewport.js.Viewport"] = function() {
	$s.push("cocktailCore.viewport.js.Viewport::new");
	var $spos = $s.length;
	cocktailCore.viewport.abstract.AbstractViewport.call(this);
	$s.pop();
}
cocktailCore.viewport.js.Viewport.__name__ = ["cocktailCore","viewport","js","Viewport"];
cocktailCore.viewport.js.Viewport.__super__ = cocktailCore.viewport.abstract.AbstractViewport;
cocktailCore.viewport.js.Viewport.prototype = $extend(cocktailCore.viewport.abstract.AbstractViewport.prototype,{
	_addResizeEvent: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_addResizeEvent");
		var $spos = $s.length;
		js.Lib.window.addEventListener("resize",this._onResizeCallback.$bind(this),false);
		$s.pop();
	}
	,_removeResizeEvent: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_removeResizeEvent");
		var $spos = $s.length;
		js.Lib.window.removeEventListener("resize",this._onResizeCallback.$bind(this),false);
		$s.pop();
	}
	,_addOrientationChangeEvent: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_addOrientationChangeEvent");
		var $spos = $s.length;
		js.Lib.window.addEventListener("resize",this._onOrientationChangeCallback.$bind(this),false);
		$s.pop();
	}
	,_removeOrientationChangeEvent: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_removeOrientationChangeEvent");
		var $spos = $s.length;
		js.Lib.window.removeEventListener("resize",this._onOrientationChangeCallback.$bind(this),false);
		$s.pop();
	}
	,_getWidth: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_getWidth");
		var $spos = $s.length;
		var $tmp = js.Lib.window.innerWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,_getHeight: function() {
		$s.push("cocktailCore.viewport.js.Viewport::_getHeight");
		var $spos = $s.length;
		var $tmp = js.Lib.window.innerHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.viewport.js.Viewport
});
if(!cocktailCore.style) cocktailCore.style = {}
if(!cocktailCore.style["abstract"]) cocktailCore.style["abstract"] = {}
cocktailCore.style.abstract.AbstractStyle = $hxClasses["cocktailCore.style.abstract.AbstractStyle"] = function(domElement) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::new");
	var $spos = $s.length;
	this._domElement = domElement;
	this._isDirty = true;
	this._nativeElements = new Array();
	this.initDefaultStyleValues();
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.__name__ = ["cocktailCore","style","abstract","AbstractStyle"];
cocktailCore.style.abstract.AbstractStyle.getDefaultStyle = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getDefaultStyle");
	var $spos = $s.length;
	var $tmp = { fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], color : cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black)};
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype = {
	_display: null
	,display: null
	,_position: null
	,position: null
	,_floatValue: null
	,floatValue: null
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
	,_overflow: null
	,overflow: null
	,_computedStyle: null
	,computedStyle: null
	,_domElement: null
	,domElement: null
	,_fontMetrics: null
	,fontMetrics: null
	,_isDirty: null
	,_nativeX: null
	,_nativeY: null
	,_nativeWidth: null
	,_nativeHeight: null
	,_nativeScaleX: null
	,_nativeScaleY: null
	,_nativeRotation: null
	,_nativeOpacity: null
	,_nativeVisibility: null
	,_nativeMatrix: null
	,_nativeElements: null
	,_elementRenderer: null
	,elementRenderer: null
	,initDefaultStyleValues: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::initDefaultStyleValues");
		var $spos = $s.length;
		this.initComputedStyles();
		this.initNativeProperties();
		this.setWidth(cocktail.style.DimensionStyleValue.autoValue);
		this.setHeight(cocktail.style.DimensionStyleValue.autoValue);
		this.setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.none);
		this.setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.none);
		this.setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setLineHeight(cocktail.style.LineHeightStyleValue.normal);
		this.setVerticalAlign(cocktail.style.VerticalAlignStyleValue.baseline);
		this.setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
		this.setPosition(cocktail.style.PositionStyleValue.staticStyle);
		this.setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
		this.setBottom(cocktail.style.PositionOffsetStyleValue.autoValue);
		this.setLeft(cocktail.style.PositionOffsetStyleValue.autoValue);
		this.setRight(cocktail.style.PositionOffsetStyleValue.autoValue);
		this.setFloatValue(cocktail.style.FloatStyleValue.none);
		this.setClear(cocktail.style.ClearStyleValue.none);
		this.setBackgroundColor(cocktail.style.BackgroundColorStyleValue.colorValue(cocktail.unit.ColorValue.transparent));
		this.setBackgroundImage([cocktail.style.BackgroundImageStyleValue.none]);
		this.setBackgroundRepeat([{ x : cocktail.style.BackgroundRepeatStyleValue.repeat, y : cocktail.style.BackgroundRepeatStyleValue.repeat}]);
		this.setBackgroundPosition([{ x : cocktail.style.BackgroundPositionXStyleValue.percent(0), y : cocktail.style.BackgroundPositionYStyleValue.percent(0)}]);
		this.setBackgroundOrigin([cocktail.style.BackgroundOriginStyleValue.paddingBox]);
		this.setBackgroundSize([cocktail.style.BackgroundSizeStyleValue.dimensions({ x : cocktail.style.BackgroundSizeStyleDimensionValue.autoValue, y : cocktail.style.BackgroundSizeStyleDimensionValue.autoValue})]);
		this.setBackgroundClip([cocktail.style.BackgroundClipStyleValue.borderBox]);
		this.setFontStyle(cocktail.style.FontStyleStyleValue.normal);
		this.setFontVariant(cocktail.style.FontVariantStyleValue.normal);
		this.setFontWeight(cocktail.style.FontWeightStyleValue.normal);
		this.setFontSize(cocktail.style.FontSizeStyleValue.absoluteSize(cocktail.unit.FontSizeAbsoluteSizeValue.medium));
		this.setTextIndent(cocktail.style.TextIndentStyleValue.length(cocktail.unit.LengthValue.px(0)));
		this.setTextAlign(cocktail.style.TextAlignStyleValue.left);
		this.setLetterSpacing(cocktail.style.LetterSpacingStyleValue.normal);
		this.setWordSpacing(cocktail.style.WordSpacingStyleValue.normal);
		this.setTextTransform(cocktail.style.TextTransformStyleValue.none);
		this.setWhiteSpace(cocktail.style.WhiteSpaceStyleValue.normal);
		this.setVisibility(cocktail.style.VisibilityStyleValue.visible);
		this.setOpacity(cocktail.style.OpacityStyleValue.number(1.0));
		this.setOverflow({ x : cocktail.style.OverflowStyleValue.visible, y : cocktail.style.OverflowStyleValue.visible});
		this.setTransformOrigin({ x : cocktail.style.TransformOriginXStyleValue.center, y : cocktail.style.TransformOriginYStyleValue.center});
		this.setTransform(cocktail.style.TransformStyleValue.none);
		var defaultStyles = cocktailCore.style.abstract.AbstractStyle.getDefaultStyle();
		this.setFontFamily(defaultStyles.fontFamily);
		this.setColor(defaultStyles.color);
		$s.pop();
	}
	,initComputedStyles: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::initComputedStyles");
		var $spos = $s.length;
		this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, floatValue : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : { color : 0, alpha : 1.0}, visibility : true, opacity : 1.0, overflow : { x : cocktail.style.OverflowStyleValue.visible, y : cocktail.style.OverflowStyleValue.visible}, transformOrigin : { x : 0.0, y : 0.0}, transform : new cocktail.geom.Matrix(), backgroundColor : { color : 0, alpha : 1.0}, backgroundSize : [], backgroundOrigin : [], backgroundImage : [], backgroundClip : [], backgroundPosition : [], backgroundRepeat : []};
		$s.pop();
	}
	,initNativeProperties: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::initNativeProperties");
		var $spos = $s.length;
		this._nativeHeight = 0;
		this._nativeOpacity = 1.0;
		this._nativeRotation = 0.0;
		this._nativeScaleX = 1.0;
		this._nativeScaleY = 1.0;
		this._nativeVisibility = true;
		this._nativeWidth = 0;
		this._nativeX = 0;
		this._nativeY = 0;
		$s.pop();
	}
	,render: function(nativeElement) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::render");
		var $spos = $s.length;
		this.setNativeHeight(this._computedStyle.height);
		this.setNativeWidth(this._computedStyle.width);
		this.setNativeMatrix(this._computedStyle.transform);
		this.setNativeOpacity(this._computedStyle.opacity);
		this.setNativeVisibility(this._computedStyle.visibility);
		$s.pop();
	}
	,attachNativeElement: function(nativeElement) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::attachNativeElement");
		var $spos = $s.length;
		$s.pop();
	}
	,detachNativeElement: function(nativeElement) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::detachNativeElement");
		var $spos = $s.length;
		$s.pop();
	}
	,attachNativeElements: function(nativeElements) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::attachNativeElements");
		var $spos = $s.length;
		var _g1 = 0, _g = nativeElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.attachNativeElement(nativeElements[i]);
		}
		$s.pop();
	}
	,detachNativeElements: function(nativeElements) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::detachNativeElements");
		var $spos = $s.length;
		var _g1 = 0, _g = nativeElements.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.detachNativeElement(nativeElements[i]);
		}
		$s.pop();
	}
	,createElementRenderer: function(parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::createElementRenderer");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,getLayerRenderer: function(elementRenderer,parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getLayerRenderer");
		var $spos = $s.length;
		var ret;
		if(this.isPositioned() == true || this.isFloat() == true) ret = new cocktailCore.style.renderer.LayerRenderer(elementRenderer); else ret = parentElementRenderer.getLayerRenderer();
		$s.pop();
		return ret;
		$s.pop();
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::layout");
		var $spos = $s.length;
		$s.pop();
	}
	,flow: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext,parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::flow");
		var $spos = $s.length;
		this.detachNativeElements(this._nativeElements);
		if(this.isNotDisplayed() == true) {
			$s.pop();
			return;
		}
		this.initComputedStyles();
		this.computeDOMElementStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData.data,containingDOMElementFontMetricsData);
		this._elementRenderer = this.createElementRenderer(parentElementRenderer);
		this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext);
		this.computeVisualEffectStyles();
		this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
		this.computeBackgroundStyles();
		this.insertDOMElement(formattingContext,lastPositionedDOMElementData,viewportData);
		this._isDirty = false;
		$s.pop();
	}
	,positionElement: function(lastPositionedDOMElementData,viewportData,staticPosition) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::positionElement");
		var $spos = $s.length;
		var positioner;
		switch( (this._domElement.getStyle().getComputedStyle().position)[1] ) {
		case 1:
			positioner = new cocktailCore.style.positioner.RelativePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedDOMElementData,staticPosition);
			break;
		case 3:
			positioner = new cocktailCore.style.positioner.FixedPositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,viewportData,staticPosition);
			break;
		case 2:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
			this._elementRenderer = positioner.position(this._elementRenderer,lastPositionedDOMElementData,staticPosition);
			break;
		default:
		}
		var $tmp = this._elementRenderer;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,scheduleLayout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::scheduleLayout");
		var $spos = $s.length;
		var layoutDelegate = this.layout.$bind(this);
		haxe.Timer.delay(function() {
			$s.push("cocktailCore.style.abstract.AbstractStyle::scheduleLayout@753");
			var $spos = $s.length;
			layoutDelegate(containingDOMElementData,lastPositionedDOMElementData,viewportData,null);
			$s.pop();
		},1);
		$s.pop();
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::flowChildren");
		var $spos = $s.length;
		$s.pop();
	}
	,insertDOMElement: function(formattingContext,lastPositionedDOMElementData,viewportData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::insertDOMElement");
		var $spos = $s.length;
		if(this.isPositioned() == false) formattingContext.insertElement(this._elementRenderer); else {
			var x = 0.0;
			var y = 0.0;
			formattingContext.format();
			x = formattingContext.getFormattingContextData().x;
			y = formattingContext.getFormattingContextData().y;
			var staticPosition = { x : x, y : y};
			if(this.isRelativePositioned() == true) formattingContext.insertElement(this._elementRenderer);
			var positionedDOMElementData = { staticPosition : staticPosition, style : this, formattingContext : formattingContext};
			lastPositionedDOMElementData.children.push(positionedDOMElementData);
		}
		$s.pop();
	}
	,invalidate: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::invalidate");
		var $spos = $s.length;
		if(this._isDirty == false) {
			this._isDirty = true;
			if(this._domElement.getParent() != null) {
				if(this.isParentDirty() == true) this._domElement.getParent().getStyle().invalidate(); else {
					var parentStyle = this._domElement.getParent().getStyle();
					var containingDOMElementData = parentStyle.getContainerDOMElementData();
					var viewPortData = this.getViewportData();
					var lastPositionedDOMElementData = { children : new Array(), data : this.getFirstPositionedAncestorData()};
					this.scheduleLayout(containingDOMElementData,lastPositionedDOMElementData,viewPortData);
				}
			}
		}
		$s.pop();
	}
	,invalidateText: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::invalidateText");
		var $spos = $s.length;
		this._fontMetrics = null;
		this.invalidate();
		$s.pop();
	}
	,invalidatePositionOffset: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::invalidatePositionOffset");
		var $spos = $s.length;
		if(this.isPositioned() == false) this.invalidate();
		$s.pop();
	}
	,invalidateMargin: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::invalidateMargin");
		var $spos = $s.length;
		if(this.getPosition() == cocktail.style.PositionStyleValue.relative || this.getPosition() == cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
		$s.pop();
	}
	,isParentDirty: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isParentDirty");
		var $spos = $s.length;
		var ret = true;
		$s.pop();
		return ret;
		$s.pop();
	}
	,computeDisplayStyles: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeDisplayStyles");
		var $spos = $s.length;
		cocktailCore.style.computer.DisplayStylesComputer.compute(this);
		$s.pop();
	}
	,computeBackgroundStyles: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeBackgroundStyles");
		var $spos = $s.length;
		cocktailCore.style.computer.BackgroundStylesComputer.compute(this);
		$s.pop();
	}
	,computeDOMElementStyles: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeDOMElementStyles");
		var $spos = $s.length;
		this.computeDisplayStyles();
		this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
		this.computeBoxModelStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData);
		$s.pop();
	}
	,computeVisualEffectStyles: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeVisualEffectStyles");
		var $spos = $s.length;
		cocktailCore.style.computer.VisualEffectStylesComputer.compute(this);
		$s.pop();
	}
	,computeTextAndFontStyles: function(containingDOMElementData,containingDOMElementFontMetricsData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeTextAndFontStyles");
		var $spos = $s.length;
		cocktailCore.style.computer.FontAndTextStylesComputer.compute(this,containingDOMElementData,containingDOMElementFontMetricsData);
		$s.pop();
	}
	,computeBoxModelStyles: function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::computeBoxModelStyles");
		var $spos = $s.length;
		var boxComputer = this.getBoxStylesComputer();
		var containingBlockDimensions = this.getContainingDOMElementData(containingDOMElementData,viewportData,lastPositionedDOMElementData);
		boxComputer.measure(this,containingBlockDimensions);
		$s.pop();
	}
	,getBoxStylesComputer: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBoxStylesComputer");
		var $spos = $s.length;
		var boxComputer;
		if(this.isFloat() == true) boxComputer = new cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer(); else {
			switch( (this._computedStyle.display)[1] ) {
			case 0:
				boxComputer = new cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer();
				break;
			case 1:
				boxComputer = new cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer();
				break;
			case 3:
				boxComputer = new cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer();
				break;
			case 2:
				boxComputer = new cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer();
				break;
			}
		}
		$s.pop();
		return boxComputer;
		$s.pop();
	}
	,getContainingDOMElementData: function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getContainingDOMElementData");
		var $spos = $s.length;
		var containingBlockDimensions;
		if(this.isPositioned() == true) {
			if(this._computedStyle.position == cocktail.style.PositionStyleValue.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto}; else if(this._computedStyle.position == cocktail.style.PositionStyleValue.absolute) containingBlockDimensions = { width : lastPositionedDOMElementData.width, height : lastPositionedDOMElementData.height, isHeightAuto : lastPositionedDOMElementData.isHeightAuto, isWidthAuto : lastPositionedDOMElementData.isWidthAuto}; else containingBlockDimensions = containingDOMElementData;
		} else containingBlockDimensions = containingDOMElementData;
		$s.pop();
		return containingBlockDimensions;
		$s.pop();
	}
	,isEmbedded: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isEmbedded");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isFloat: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isFloat");
		var $spos = $s.length;
		var ret = false;
		switch( (this._computedStyle.floatValue)[1] ) {
		case 0:
		case 1:
			ret = true;
			break;
		case 2:
			ret = false;
			break;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,isPositioned: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isPositioned");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,isRelativePositioned: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isRelativePositioned");
		var $spos = $s.length;
		var $tmp = this._computedStyle.position == cocktail.style.PositionStyleValue.relative;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,isClear: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isClear");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,childrenInline: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::childrenInline");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isNotDisplayed: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isNotDisplayed");
		var $spos = $s.length;
		var $tmp = this._computedStyle.display == cocktail.style.DisplayStyleValue.none;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,isInlineLevel: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isInlineLevel");
		var $spos = $s.length;
		var ret = false;
		switch( (this._computedStyle.display)[1] ) {
		case 2:
		case 1:
			ret = true;
			break;
		default:
			ret = false;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getFirstPositionedAncestorData: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFirstPositionedAncestorData");
		var $spos = $s.length;
		var firstPositionedAncestorData;
		var parent = this._domElement.getParent();
		if(parent != null) {
			var isPositioned = parent.getStyle().isPositioned();
			while(isPositioned == false) if(parent.getParent() != null) {
				parent = parent.getParent();
				isPositioned = parent.getStyle().isPositioned();
			} else isPositioned = true;
			var parentStyle = parent.getStyle();
			firstPositionedAncestorData = parentStyle.getContainerDOMElementData();
		} else firstPositionedAncestorData = this.getViewportData();
		$s.pop();
		return firstPositionedAncestorData;
		$s.pop();
	}
	,establishesNewFormattingContext: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::establishesNewFormattingContext");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isInFlow: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::isInFlow");
		var $spos = $s.length;
		var $tmp = this.isPositioned() == false;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getViewportData: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getViewportData");
		var $spos = $s.length;
		var viewPort = new cocktailCore.viewport.js.Viewport();
		var viewPortData = { isHeightAuto : false, isWidthAuto : false, width : viewPort._getWidth(), height : viewPort._getHeight()};
		$s.pop();
		return viewPortData;
		$s.pop();
	}
	,setNativeX: function(domElement,x) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeX");
		var $spos = $s.length;
		if(domElement == this._domElement) this._nativeX = x;
		$s.pop();
	}
	,getNativeX: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeX");
		var $spos = $s.length;
		var $tmp = this._nativeX;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeY: function(domElement,y) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeY");
		var $spos = $s.length;
		if(domElement == this._domElement) this._nativeY = y;
		$s.pop();
	}
	,getNativeY: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeY");
		var $spos = $s.length;
		var $tmp = this._nativeY;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeWidth: function(width) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeWidth");
		var $spos = $s.length;
		this._nativeWidth = width;
		$s.pop();
	}
	,getNativeWidth: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeWidth");
		var $spos = $s.length;
		var $tmp = this._nativeWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeHeight: function(height) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeHeight");
		var $spos = $s.length;
		this._nativeHeight = height;
		$s.pop();
	}
	,getNativeHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeHeight");
		var $spos = $s.length;
		var $tmp = this._nativeHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeScaleX: function(scaleX) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeScaleX");
		var $spos = $s.length;
		this._nativeScaleX = scaleX;
		$s.pop();
	}
	,getNativeScaleX: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeScaleX");
		var $spos = $s.length;
		var $tmp = this._nativeScaleX;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeScaleY: function(scaleY) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeScaleY");
		var $spos = $s.length;
		this._nativeScaleY = scaleY;
		$s.pop();
	}
	,getNativeScaleY: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeScaleY");
		var $spos = $s.length;
		var $tmp = this._nativeScaleY;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeRotation: function(rotation) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeRotation");
		var $spos = $s.length;
		this._nativeRotation = rotation;
		$s.pop();
	}
	,getNativeRotation: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeRotation");
		var $spos = $s.length;
		var $tmp = this._nativeRotation;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeMatrix: function(matrix) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeMatrix");
		var $spos = $s.length;
		this._nativeMatrix = matrix;
		$s.pop();
	}
	,getNativeMatrix: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeMatrix");
		var $spos = $s.length;
		var $tmp = this._nativeMatrix;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeOpacity: function(opacity) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeOpacity");
		var $spos = $s.length;
		this._nativeOpacity = opacity;
		$s.pop();
	}
	,getNativeOpacity: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeOpacity");
		var $spos = $s.length;
		var $tmp = this._nativeOpacity;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNativeVisibility: function(visible) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setNativeVisibility");
		var $spos = $s.length;
		this._nativeVisibility = visible;
		$s.pop();
	}
	,getNativeVisibility: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getNativeVisibility");
		var $spos = $s.length;
		var $tmp = this._nativeVisibility;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getElementRenderer: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getElementRenderer");
		var $spos = $s.length;
		var $tmp = this._elementRenderer;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontMetricsData: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontMetricsData");
		var $spos = $s.length;
		var $tmp = this._fontMetrics;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedStyle: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getComputedStyle");
		var $spos = $s.length;
		var $tmp = this._computedStyle;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setComputedStyle: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setComputedStyle");
		var $spos = $s.length;
		var $tmp = this._computedStyle = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getDOMElement: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getDOMElement");
		var $spos = $s.length;
		var $tmp = this._domElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setWidth");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._width = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginLeft: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginLeft");
		var $spos = $s.length;
		this.invalidateMargin();
		var $tmp = this._marginLeft = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginRight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginRight");
		var $spos = $s.length;
		this.invalidateMargin();
		var $tmp = this._marginRight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginTop: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginTop");
		var $spos = $s.length;
		this.invalidateMargin();
		var $tmp = this._marginTop = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginBottom: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginBottom");
		var $spos = $s.length;
		this.invalidateMargin();
		var $tmp = this._marginBottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingLeft: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingLeft");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._paddingLeft = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingRight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingRight");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._paddingRight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingTop: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingTop");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._paddingTop = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingBottom: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingBottom");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._paddingBottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setDisplay: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setDisplay");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._display = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPosition: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setPosition");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._position = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setHeight");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._height = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMinHeight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMinHeight");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._minHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMaxHeight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMaxHeight");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._maxHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMinWidth: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMinWidth");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._minWidth = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMaxWidth: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setMaxWidth");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._maxWidth = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTop: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTop");
		var $spos = $s.length;
		this.invalidatePositionOffset();
		var $tmp = this._top = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLeft: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setLeft");
		var $spos = $s.length;
		this.invalidatePositionOffset();
		var $tmp = this._left = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBottom: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBottom");
		var $spos = $s.length;
		this.invalidatePositionOffset();
		var $tmp = this._bottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setRight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setRight");
		var $spos = $s.length;
		this.invalidatePositionOffset();
		var $tmp = this._right = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFloatValue: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFloatValue");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._floatValue = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setClear: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setClear");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._clear = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontSize: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFontSize");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._fontSize = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontWeight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFontWeight");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._fontWeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontStyle: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFontStyle");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._fontStyle = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontFamily: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFontFamily");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._fontFamily = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontVariant: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setFontVariant");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._fontVariant = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextTransform: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTextTransform");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._textTransform = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLetterSpacing: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setLetterSpacing");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._letterSpacing = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWordSpacing: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setWordSpacing");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._wordSpacing = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLineHeight: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setLineHeight");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._lineHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setColor: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setColor");
		var $spos = $s.length;
		this.invalidateText();
		var $tmp = this._color = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setVerticalAlign: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setVerticalAlign");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._verticalAlign = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextIndent: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTextIndent");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._textIndent = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWhiteSpace: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setWhiteSpace");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._whiteSpace = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextAlign: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTextAlign");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._textAlign = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOpacity: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setOpacity");
		var $spos = $s.length;
		this._opacity = value;
		this.invalidate();
		var $tmp = this._opacity;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setVisibility: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setVisibility");
		var $spos = $s.length;
		this._visibility = value;
		this.invalidate();
		var $tmp = this._visibility;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTransformOrigin: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTransformOrigin");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._transformOrigin = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTransform: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setTransform");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._transform = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOverflow: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setOverflow");
		var $spos = $s.length;
		this.invalidate();
		var $tmp = this._overflow = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOpacity: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getOpacity");
		var $spos = $s.length;
		var $tmp = this._opacity;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getVisibility: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getVisibility");
		var $spos = $s.length;
		var $tmp = this._visibility;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMarginLeft: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginLeft");
		var $spos = $s.length;
		var $tmp = this._marginLeft;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMarginRight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginRight");
		var $spos = $s.length;
		var $tmp = this._marginRight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMarginTop: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginTop");
		var $spos = $s.length;
		var $tmp = this._marginTop;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMarginBottom: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginBottom");
		var $spos = $s.length;
		var $tmp = this._marginBottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getPaddingLeft: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingLeft");
		var $spos = $s.length;
		var $tmp = this._paddingLeft;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getPaddingRight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingRight");
		var $spos = $s.length;
		var $tmp = this._paddingRight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getPaddingTop: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingTop");
		var $spos = $s.length;
		var $tmp = this._paddingTop;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getPaddingBottom: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingBottom");
		var $spos = $s.length;
		var $tmp = this._paddingBottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getDisplay: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getDisplay");
		var $spos = $s.length;
		var $tmp = this._display;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getPosition: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getPosition");
		var $spos = $s.length;
		var $tmp = this._position;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getWidth: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getWidth");
		var $spos = $s.length;
		var $tmp = this._width;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getHeight");
		var $spos = $s.length;
		var $tmp = this._height;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMinHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMinHeight");
		var $spos = $s.length;
		var $tmp = this._minHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMaxHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMaxHeight");
		var $spos = $s.length;
		var $tmp = this._maxHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMinWidth: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMinWidth");
		var $spos = $s.length;
		var $tmp = this._minWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getMaxWidth: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getMaxWidth");
		var $spos = $s.length;
		var $tmp = this._maxWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTop: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTop");
		var $spos = $s.length;
		var $tmp = this._top;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getLeft: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getLeft");
		var $spos = $s.length;
		var $tmp = this._left;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBottom: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBottom");
		var $spos = $s.length;
		var $tmp = this._bottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getRight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getRight");
		var $spos = $s.length;
		var $tmp = this._right;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFloatValue: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFloatValue");
		var $spos = $s.length;
		var $tmp = this._floatValue;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getClear: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getClear");
		var $spos = $s.length;
		var $tmp = this._clear;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontSize: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontSize");
		var $spos = $s.length;
		var $tmp = this._fontSize;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontWeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontWeight");
		var $spos = $s.length;
		var $tmp = this._fontWeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontStyle: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontStyle");
		var $spos = $s.length;
		var $tmp = this._fontStyle;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontFamily: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontFamily");
		var $spos = $s.length;
		var $tmp = this._fontFamily;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFontVariant: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getFontVariant");
		var $spos = $s.length;
		var $tmp = this._fontVariant;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTextTransform: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTextTransform");
		var $spos = $s.length;
		var $tmp = this._textTransform;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getLetterSpacing: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getLetterSpacing");
		var $spos = $s.length;
		var $tmp = this._letterSpacing;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getColor: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getColor");
		var $spos = $s.length;
		var $tmp = this._color;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getWordSpacing: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getWordSpacing");
		var $spos = $s.length;
		var $tmp = this._wordSpacing;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getLineHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getLineHeight");
		var $spos = $s.length;
		var $tmp = this._lineHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getVerticalAlign: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getVerticalAlign");
		var $spos = $s.length;
		var $tmp = this._verticalAlign;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTextIndent: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTextIndent");
		var $spos = $s.length;
		var $tmp = this._textIndent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getWhiteSpace: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getWhiteSpace");
		var $spos = $s.length;
		var $tmp = this._whiteSpace;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTextAlign: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTextAlign");
		var $spos = $s.length;
		var $tmp = this._textAlign;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTransform: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTransform");
		var $spos = $s.length;
		var $tmp = this._transform;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTransformOrigin: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getTransformOrigin");
		var $spos = $s.length;
		var $tmp = this._transformOrigin;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundColor: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundColor");
		var $spos = $s.length;
		var $tmp = this._backgroundColor = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundColor: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundColor");
		var $spos = $s.length;
		var $tmp = this._backgroundColor;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundImage: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundImage");
		var $spos = $s.length;
		var $tmp = this._backgroundImage = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundImage: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundImage");
		var $spos = $s.length;
		var $tmp = this._backgroundImage;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundRepeat: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundRepeat");
		var $spos = $s.length;
		var $tmp = this._backgroundRepeat = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundRepeat: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundRepeat");
		var $spos = $s.length;
		var $tmp = this._backgroundRepeat;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundSize: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundSize");
		var $spos = $s.length;
		var $tmp = this._backgroundSize = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundSize: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundSize");
		var $spos = $s.length;
		var $tmp = this._backgroundSize;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundClip: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundClip");
		var $spos = $s.length;
		var $tmp = this._backgroundClip = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundClip: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundClip");
		var $spos = $s.length;
		var $tmp = this._backgroundClip;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundPosition: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundPosition");
		var $spos = $s.length;
		var $tmp = this._backgroundPosition = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundPosition: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundPosition");
		var $spos = $s.length;
		var $tmp = this._backgroundPosition;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundOrigin: function(value) {
		$s.push("cocktailCore.style.abstract.AbstractStyle::setBackgroundOrigin");
		var $spos = $s.length;
		var $tmp = this._backgroundOrigin = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBackgroundOrigin: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getBackgroundOrigin");
		var $spos = $s.length;
		var $tmp = this._backgroundOrigin;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOverflow: function() {
		$s.push("cocktailCore.style.abstract.AbstractStyle::getOverflow");
		var $spos = $s.length;
		var $tmp = this._overflow;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.abstract.AbstractStyle
	,__properties__: {get_elementRenderer:"getElementRenderer",get_fontMetrics:"getFontMetricsData",get_domElement:"getDOMElement",set_computedStyle:"setComputedStyle",get_computedStyle:"getComputedStyle",set_overflow:"setOverflow",get_overflow:"getOverflow",set_visibility:"setVisibility",get_visibility:"getVisibility",set_opacity:"setOpacity",get_opacity:"getOpacity",set_verticalAlign:"setVerticalAlign",get_verticalAlign:"getVerticalAlign",set_textIndent:"setTextIndent",get_textIndent:"getTextIndent",set_textAlign:"setTextAlign",get_textAlign:"getTextAlign",set_whiteSpace:"setWhiteSpace",get_whiteSpace:"getWhiteSpace",set_wordSpacing:"setWordSpacing",get_wordSpacing:"getWordSpacing",set_letterSpacing:"setLetterSpacing",get_letterSpacing:"getLetterSpacing",set_textTransform:"setTextTransform",get_textTransform:"getTextTransform",set_lineHeight:"setLineHeight",get_lineHeight:"getLineHeight",set_color:"setColor",get_color:"getColor",set_fontVariant:"setFontVariant",get_fontVariant:"getFontVariant",set_fontFamily:"setFontFamily",get_fontFamily:"getFontFamily",set_fontStyle:"setFontStyle",get_fontStyle:"getFontStyle",set_fontWeight:"setFontWeight",get_fontWeight:"getFontWeight",set_fontSize:"setFontSize",get_fontSize:"getFontSize",set_backgroundClip:"setBackgroundClip",get_backgroundClip:"getBackgroundClip",set_backgroundPosition:"setBackgroundPosition",get_backgroundPosition:"getBackgroundPosition",set_backgroundSize:"setBackgroundSize",get_backgroundSize:"getBackgroundSize",set_backgroundOrigin:"setBackgroundOrigin",get_backgroundOrigin:"getBackgroundOrigin",set_backgroundRepeat:"setBackgroundRepeat",get_backgroundRepeat:"getBackgroundRepeat",set_backgroundImage:"setBackgroundImage",get_backgroundImage:"getBackgroundImage",set_backgroundColor:"setBackgroundColor",get_backgroundColor:"getBackgroundColor",set_right:"setRight",get_right:"getRight",set_bottom:"setBottom",get_bottom:"getBottom",set_left:"setLeft",get_left:"getLeft",set_top:"setTop",get_top:"getTop",set_maxWidth:"setMaxWidth",get_maxWidth:"getMaxWidth",set_minWidth:"setMinWidth",get_minWidth:"getMinWidth",set_maxHeight:"setMaxHeight",get_maxHeight:"getMaxHeight",set_minHeight:"setMinHeight",get_minHeight:"getMinHeight",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_paddingBottom:"setPaddingBottom",get_paddingBottom:"getPaddingBottom",set_paddingTop:"setPaddingTop",get_paddingTop:"getPaddingTop",set_paddingRight:"setPaddingRight",get_paddingRight:"getPaddingRight",set_paddingLeft:"setPaddingLeft",get_paddingLeft:"getPaddingLeft",set_marginBottom:"setMarginBottom",get_marginBottom:"getMarginBottom",set_marginTop:"setMarginTop",get_marginTop:"getMarginTop",set_marginRight:"setMarginRight",get_marginRight:"getMarginRight",set_marginLeft:"setMarginLeft",get_marginLeft:"getMarginLeft",set_transform:"setTransform",get_transform:"getTransform",set_transformOrigin:"setTransformOrigin",get_transformOrigin:"getTransformOrigin",set_clear:"setClear",get_clear:"getClear",set_floatValue:"setFloatValue",get_floatValue:"getFloatValue",set_position:"setPosition",get_position:"getPosition",set_display:"setDisplay",get_display:"getDisplay"}
}
if(!cocktailCore.style.js) cocktailCore.style.js = {}
cocktailCore.style.js.Style = $hxClasses["cocktailCore.style.js.Style"] = function(domElement) {
	$s.push("cocktailCore.style.js.Style::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.Style.__name__ = ["cocktailCore","style","js","Style"];
cocktailCore.style.js.Style.__super__ = cocktailCore.style.abstract.AbstractStyle;
cocktailCore.style.js.Style.prototype = $extend(cocktailCore.style.abstract.AbstractStyle.prototype,{
	render: function(nativeElement) {
		$s.push("cocktailCore.style.js.Style::render");
		var $spos = $s.length;
		$s.pop();
	}
	,flow: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext,parentElementRenderer) {
		$s.push("cocktailCore.style.js.Style::flow");
		var $spos = $s.length;
		this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext);
		this.setNativeHeight(this._domElement.getNativeElement().clientHeight);
		this.setNativeWidth(this._domElement.getNativeElement().clientWidth);
		this.setNativeX(this._domElement,this._domElement.getNativeElement().offsetLeft);
		this.setNativeY(this._domElement,this._domElement.getNativeElement().offsetTop);
		this._isDirty = false;
		$s.pop();
	}
	,getCSSDisplay: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSDisplay");
		var $spos = $s.length;
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
		$s.pop();
		return cssDisplayValue;
		$s.pop();
	}
	,getCSSFloat: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFloat");
		var $spos = $s.length;
		var cssFloatValue;
		switch( (value)[1] ) {
		case 0:
			cssFloatValue = "left";
			break;
		case 1:
			cssFloatValue = "right";
			break;
		case 2:
			cssFloatValue = "none";
			break;
		}
		$s.pop();
		return cssFloatValue;
		$s.pop();
	}
	,getCSSClear: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSClear");
		var $spos = $s.length;
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
		$s.pop();
		return cssClearValue;
		$s.pop();
	}
	,getCSSPosition: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSPosition");
		var $spos = $s.length;
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
		$s.pop();
		return cssPositionValue;
		$s.pop();
	}
	,getCSSOverflow: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSOverflow");
		var $spos = $s.length;
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
		$s.pop();
		return cssOverflowValue;
		$s.pop();
	}
	,getCSSOpacity: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSOpacity");
		var $spos = $s.length;
		var cssOpacityValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssOpacityValue = Std.string(value1);
			break;
		}
		$s.pop();
		return cssOpacityValue;
		$s.pop();
	}
	,getCSSVisibility: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSVisibility");
		var $spos = $s.length;
		var cssVisibilityValue;
		switch( (value)[1] ) {
		case 0:
			cssVisibilityValue = "visible";
			break;
		case 1:
			cssVisibilityValue = "hidden";
			break;
		}
		$s.pop();
		return cssVisibilityValue;
		$s.pop();
	}
	,getCSSTransform: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSTransform");
		var $spos = $s.length;
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
		$s.pop();
		return cssTransformValue;
		$s.pop();
	}
	,getCSSTransformFunction: function(transformFunction) {
		$s.push("cocktailCore.style.js.Style::getCSSTransformFunction");
		var $spos = $s.length;
		var cssTransformFunction;
		var $e = (transformFunction);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			cssTransformFunction = "matrix(" + value.a + "," + value.b + "," + value.c + "," + value.d + "," + value.e + "," + value.f + ")";
			break;
		case 7:
			var angle = $e[2];
			cssTransformFunction = "rotate(" + this.getCSSAngleValue(angle) + ")";
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
			cssTransformFunction = "skew(" + this.getCSSAngleValue(skewX) + "," + this.getCSSAngleValue(skewY) + ")";
			break;
		case 8:
			var skewX = $e[2];
			cssTransformFunction = "skewX(" + this.getCSSAngleValue(skewX) + ")";
			break;
		case 9:
			var skewY = $e[2];
			cssTransformFunction = "skewY(" + this.getCSSAngleValue(skewY) + ")";
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
		$s.pop();
		return cssTransformFunction;
		$s.pop();
	}
	,getCSSTranslation: function(translation) {
		$s.push("cocktailCore.style.js.Style::getCSSTranslation");
		var $spos = $s.length;
		var cssTranslationValue;
		var $e = (translation);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			cssTranslationValue = this.getCSSLengthValue(value);
			break;
		case 1:
			var value = $e[2];
			cssTranslationValue = this.getCSSPercentValue(value);
			break;
		}
		$s.pop();
		return cssTranslationValue;
		$s.pop();
	}
	,getCSSTransformOrigin: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSTransformOrigin");
		var $spos = $s.length;
		var cssTransformOriginValue;
		var $e = (value.x);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssTransformOriginValue = this.getCSSLengthValue(value1);
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
			cssTransformOriginValue += this.getCSSLengthValue(value1);
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
		$s.pop();
		return cssTransformOriginValue;
		$s.pop();
	}
	,getCSSMargin: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSMargin");
		var $spos = $s.length;
		var cssMarginValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssMarginValue = this.getCSSLengthValue(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssMarginValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssMarginValue = "auto";
			break;
		}
		$s.pop();
		return cssMarginValue;
		$s.pop();
	}
	,getCSSPadding: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSPadding");
		var $spos = $s.length;
		var cssPaddingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssPaddingValue = this.getCSSLengthValue(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssPaddingValue = this.getCSSPercentValue(percentValue);
			break;
		}
		$s.pop();
		return cssPaddingValue;
		$s.pop();
	}
	,getCSSDimension: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSDimension");
		var $spos = $s.length;
		var cssDimensionValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssDimensionValue = this.getCSSLengthValue(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssDimensionValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssDimensionValue = "auto";
			break;
		}
		$s.pop();
		return cssDimensionValue;
		$s.pop();
	}
	,getCSSPositionOffset: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSPositionOffset");
		var $spos = $s.length;
		var cssPositionOffsetValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssPositionOffsetValue = this.getCSSLengthValue(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssPositionOffsetValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssPositionOffsetValue = "auto";
			break;
		}
		$s.pop();
		return cssPositionOffsetValue;
		$s.pop();
	}
	,getCSSConstrainedDimension: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSConstrainedDimension");
		var $spos = $s.length;
		var cssConstrainedValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssConstrainedValue = this.getCSSLengthValue(unit);
			break;
		case 1:
			var percentValue = $e[2];
			cssConstrainedValue = this.getCSSPercentValue(percentValue);
			break;
		case 2:
			cssConstrainedValue = "none";
			break;
		}
		$s.pop();
		return cssConstrainedValue;
		$s.pop();
	}
	,getCSSVerticalAlign: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSVerticalAlign");
		var $spos = $s.length;
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
			cssVerticalAlignValue = this.getCSSLengthValue(value1);
			break;
		}
		$s.pop();
		return cssVerticalAlignValue;
		$s.pop();
	}
	,getCSSLineHeight: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSLineHeight");
		var $spos = $s.length;
		var cssLineHeightValue;
		var $e = (value);
		switch( $e[1] ) {
		case 2:
			var unit = $e[2];
			cssLineHeightValue = this.getCSSLengthValue(unit);
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
		$s.pop();
		return cssLineHeightValue;
		$s.pop();
	}
	,getCSSFontSize: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFontSize");
		var $spos = $s.length;
		var cssFontSizeValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var unit = $e[2];
			cssFontSizeValue = this.getCSSLengthValue(unit);
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
		$s.pop();
		return cssFontSizeValue;
		$s.pop();
	}
	,getCSSFontWeight: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFontWeight");
		var $spos = $s.length;
		var cssFontWeightValue;
		switch( (value)[1] ) {
		case 0:
			cssFontWeightValue = "normal";
			break;
		case 1:
			cssFontWeightValue = "bold";
			break;
		}
		$s.pop();
		return cssFontWeightValue;
		$s.pop();
	}
	,getCSSFontStyle: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFontStyle");
		var $spos = $s.length;
		var cssFontStyleValue;
		switch( (value)[1] ) {
		case 0:
			cssFontStyleValue = "normal";
			break;
		case 1:
			cssFontStyleValue = "italic";
			break;
		}
		$s.pop();
		return cssFontStyleValue;
		$s.pop();
	}
	,getCSSFontVariant: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFontVariant");
		var $spos = $s.length;
		var cssFontVariantValue;
		switch( (value)[1] ) {
		case 0:
			cssFontVariantValue = "normal";
			break;
		case 1:
			cssFontVariantValue = "small-caps";
			break;
		}
		$s.pop();
		return cssFontVariantValue;
		$s.pop();
	}
	,getCSSFontFamily: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSFontFamily");
		var $spos = $s.length;
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
		$s.pop();
		return cssFontFamilyValue;
		$s.pop();
	}
	,getCSSTextAlign: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSTextAlign");
		var $spos = $s.length;
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
		$s.pop();
		return cssTextAlignValue;
		$s.pop();
	}
	,getCSSWhiteSpace: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSWhiteSpace");
		var $spos = $s.length;
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
		$s.pop();
		return cssWhiteSpaceValue;
		$s.pop();
	}
	,getCSSTextTransform: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSTextTransform");
		var $spos = $s.length;
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
		$s.pop();
		return cssTextTransformValue;
		$s.pop();
	}
	,getCSSTextIndent: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSTextIndent");
		var $spos = $s.length;
		var cssTextIndentValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssTextIndentValue = this.getCSSLengthValue(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssTextIndentValue = this.getCSSPercentValue(value1);
			break;
		}
		$s.pop();
		return cssTextIndentValue;
		$s.pop();
	}
	,getCSSLetterSpacing: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSLetterSpacing");
		var $spos = $s.length;
		var cssLetterSpacingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			cssLetterSpacingValue = "normal";
			break;
		case 1:
			var unit = $e[2];
			cssLetterSpacingValue = this.getCSSLengthValue(unit);
			break;
		}
		$s.pop();
		return cssLetterSpacingValue;
		$s.pop();
	}
	,getCSSWordSpacing: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSWordSpacing");
		var $spos = $s.length;
		var cssWordSpacingValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			cssWordSpacingValue = "normal";
			break;
		case 1:
			var unit = $e[2];
			cssWordSpacingValue = this.getCSSLengthValue(unit);
			break;
		}
		$s.pop();
		return cssWordSpacingValue;
		$s.pop();
	}
	,getCSSBackgroundColor: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundColor");
		var $spos = $s.length;
		var cssBackgroundColor;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundColor = this.getCSSColor(value1);
			break;
		}
		$s.pop();
		return cssBackgroundColor;
		$s.pop();
	}
	,getCSSBackgroundOrigin: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundOrigin");
		var $spos = $s.length;
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
		$s.pop();
		return cssBackgroundOrigin;
		$s.pop();
	}
	,getCSSBackgroundClip: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundClip");
		var $spos = $s.length;
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
		$s.pop();
		return cssBackgroundClip;
		$s.pop();
	}
	,getCSSBackgroundImage: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundImage");
		var $spos = $s.length;
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
		$s.pop();
		return cssBackgroundImage;
		$s.pop();
	}
	,getCSSBackgroundSize: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundSize");
		var $spos = $s.length;
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
		$s.pop();
		return cssBackgroundSize;
		$s.pop();
	}
	,getCSSBackgroundSizeDimensions: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundSizeDimensions");
		var $spos = $s.length;
		var cssBackgroundSizeDimensions = this.getCSSBackgroundSizeDimension(value.x) + " " + this.getCSSBackgroundSizeDimension(value.y);
		$s.pop();
		return cssBackgroundSizeDimensions;
		$s.pop();
	}
	,getCSSBackgroundSizeDimension: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundSizeDimension");
		var $spos = $s.length;
		var cssBackgroundSizeDimension;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundSizeDimension = this.getCSSLengthValue(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssBackgroundSizeDimension = this.getCSSPercentValue(value1);
			break;
		case 2:
			cssBackgroundSizeDimension = "auto";
			break;
		}
		$s.pop();
		return cssBackgroundSizeDimension;
		$s.pop();
	}
	,getCSSBackgroundPosition: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundPosition");
		var $spos = $s.length;
		var cssBackgroundPositionData = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssBackgroundPositionData += this.getCSSBackgroundPositionXStyleValue(value[i].x) + " " + this.getCSSBackgroundPositionYStyleValue(value[i].y);
			if(i < value.length - 1) cssBackgroundPositionData += ",";
		}
		$s.pop();
		return cssBackgroundPositionData;
		$s.pop();
	}
	,getCSSBackgroundPositionXStyleValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundPositionXStyleValue");
		var $spos = $s.length;
		var cssBackgroundPositionX;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundPositionX = this.getCSSLengthValue(value1);
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
		$s.pop();
		return cssBackgroundPositionX;
		$s.pop();
	}
	,getCSSBackgroundPositionYStyleValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundPositionYStyleValue");
		var $spos = $s.length;
		var cssBackgroundPositionY;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssBackgroundPositionY = this.getCSSLengthValue(value1);
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
		$s.pop();
		return cssBackgroundPositionY;
		$s.pop();
	}
	,getCSSBackgroundRepeat: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundRepeat");
		var $spos = $s.length;
		var cssBackgroundRepeat = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssBackgroundRepeat += this.getCSSBackgroundRepeatValue(value[i].x) + " " + this.getCSSBackgroundRepeatValue(value[i].y);
			if(i < value.length - 1) cssBackgroundRepeat += ",";
		}
		$s.pop();
		return cssBackgroundRepeat;
		$s.pop();
	}
	,getCSSBackgroundRepeatValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSBackgroundRepeatValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssBackgroundRepeatValue;
		$s.pop();
	}
	,getCSSImageValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSImageValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssImageValue;
		$s.pop();
	}
	,getCSSImageList: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSImageList");
		var $spos = $s.length;
		var cssImageList = "";
		var _g1 = 0, _g = value.urls.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssImageList += "\"" + value.urls[i] + "\"";
			if(i < value.urls.length - 1) cssImageList += ","; else cssImageList += "," + this.getCSSColor(value.fallbackColor);
		}
		$s.pop();
		return cssImageList;
		$s.pop();
	}
	,getCSSGradientValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSGradientValue");
		var $spos = $s.length;
		var cssGradientValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssGradientValue = "linear-gradient(" + this.getCSSLinearGradientValue(value1) + ")";
			break;
		}
		$s.pop();
		return cssGradientValue;
		$s.pop();
	}
	,getCSSLinearGradientValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSLinearGradientValue");
		var $spos = $s.length;
		var cssLinearGradientValue = this.getCSSGradientAngleValue(value.angle) + "," + this.getCSSColorStopsValue(value.colorStops);
		$s.pop();
		return cssLinearGradientValue;
		$s.pop();
	}
	,getCSSColorStopsValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSColorStopsValue");
		var $spos = $s.length;
		var cssColorStopsData = "";
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			cssColorStopsData += this.getCSSColor(value[i].color) + " " + this.getCSSColorStopValue(value[i].stop);
			if(i < value.length - 1) cssColorStopsData += ",";
		}
		$s.pop();
		return cssColorStopsData;
		$s.pop();
	}
	,getCSSColorStopValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSColorStopValue");
		var $spos = $s.length;
		var cssColorStopValue;
		var $e = (value);
		switch( $e[1] ) {
		case 1:
			var value1 = $e[2];
			cssColorStopValue = this.getCSSPercentValue(value1);
			break;
		case 0:
			var value1 = $e[2];
			cssColorStopValue = this.getCSSLengthValue(value1);
			break;
		}
		$s.pop();
		return cssColorStopValue;
		$s.pop();
	}
	,getCSSGradientAngleValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSGradientAngleValue");
		var $spos = $s.length;
		var cssGradientAngleValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssGradientAngleValue = this.getCSSAngleValue(value1);
			break;
		case 2:
			var value1 = $e[2];
			cssGradientAngleValue = this.getCSSCornerValue(value1);
			break;
		case 1:
			var value1 = $e[2];
			cssGradientAngleValue = this.getCSSSideValue(value1);
			break;
		}
		$s.pop();
		return cssGradientAngleValue;
		$s.pop();
	}
	,getCSSSideValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSSideValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssSideValue;
		$s.pop();
	}
	,getCSSCornerValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSCornerValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssCornerValue;
		$s.pop();
	}
	,getCSSColor: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSColor");
		var $spos = $s.length;
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
		$s.pop();
		return cssColorValue;
		$s.pop();
	}
	,getCSSLengthValue: function(lengthValue) {
		$s.push("cocktailCore.style.js.Style::getCSSLengthValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssLength;
		$s.pop();
	}
	,getCSSPercentValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSPercentValue");
		var $spos = $s.length;
		var $tmp = Std.string(value) + "%";
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getCSSAngleValue: function(value) {
		$s.push("cocktailCore.style.js.Style::getCSSAngleValue");
		var $spos = $s.length;
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
		$s.pop();
		return cssAngle;
		$s.pop();
	}
	,getColorFromKeyword: function(value) {
		$s.push("cocktailCore.style.js.Style::getColorFromKeyword");
		var $spos = $s.length;
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
		$s.pop();
		return cssColor;
		$s.pop();
	}
	,getVendorSpecificStyleName: function(nativeStyle,styleName) {
		$s.push("cocktailCore.style.js.Style::getVendorSpecificStyleName");
		var $spos = $s.length;
		var vendorSpecificStyleName;
		if(Reflect.hasField(nativeStyle,styleName)) vendorSpecificStyleName = styleName; else {
			var styleNameCap = styleName.charAt(0).toUpperCase();
			var styleNameEnd = styleName.substr(1);
			styleName = styleNameCap + styleNameEnd;
			if(Reflect.field(nativeStyle,"Moz" + styleName) != null) vendorSpecificStyleName = "Moz" + styleName; else if(Reflect.field(nativeStyle,"Webkit" + styleName) != null) vendorSpecificStyleName = "Webkit" + styleName; else if(Reflect.field(nativeStyle,"Ms" + styleName) != null) vendorSpecificStyleName = "Ms" + styleName; else if(Reflect.field(nativeStyle,"O" + styleName) != null) vendorSpecificStyleName = "O" + styleName; else vendorSpecificStyleName = null;
		}
		$s.pop();
		return vendorSpecificStyleName;
		$s.pop();
	}
	,setVerticalAlign: function(value) {
		$s.push("cocktailCore.style.js.Style::setVerticalAlign");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setVerticalAlign.call(this,value);
		var $tmp = this._verticalAlign = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setColor: function(value) {
		$s.push("cocktailCore.style.js.Style::setColor");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.color = this.getCSSColor(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setColor.call(this,value);
		var $tmp = this._color = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWordSpacing: function(value) {
		$s.push("cocktailCore.style.js.Style::setWordSpacing");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWordSpacing.call(this,value);
		var $tmp = this._wordSpacing = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLetterSpacing: function(value) {
		$s.push("cocktailCore.style.js.Style::setLetterSpacing");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLetterSpacing.call(this,value);
		var $tmp = this._letterSpacing = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextTransform: function(value) {
		$s.push("cocktailCore.style.js.Style::setTextTransform");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.textTransform = this.getCSSTextTransform(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextTransform.call(this,value);
		var $tmp = this._textTransform = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontVariant: function(value) {
		$s.push("cocktailCore.style.js.Style::setFontVariant");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.fontVariant = this.getCSSFontVariant(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontVariant.call(this,value);
		var $tmp = this._fontVariant = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontFamily: function(value) {
		$s.push("cocktailCore.style.js.Style::setFontFamily");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.fontFamily = this.getCSSFontFamily(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontFamily.call(this,value);
		var $tmp = this._fontFamily = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontWeight: function(value) {
		$s.push("cocktailCore.style.js.Style::setFontWeight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.fontWeight = this.getCSSFontWeight(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontWeight.call(this,value);
		var $tmp = this._fontWeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontStyle: function(value) {
		$s.push("cocktailCore.style.js.Style::setFontStyle");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.fontStyle = this.getCSSFontStyle(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontStyle.call(this,value);
		var $tmp = this._fontStyle = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFontSize: function(value) {
		$s.push("cocktailCore.style.js.Style::setFontSize");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.fontSize = this.getCSSFontSize(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontSize.call(this,value);
		var $tmp = this._fontSize = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLineHeight: function(value) {
		$s.push("cocktailCore.style.js.Style::setLineHeight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.lineHeight = this.getCSSLineHeight(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLineHeight.call(this,value);
		var $tmp = this._lineHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginLeft: function(value) {
		$s.push("cocktailCore.style.js.Style::setMarginLeft");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.marginLeft = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginLeft.call(this,value);
		var $tmp = this._marginLeft = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginRight: function(value) {
		$s.push("cocktailCore.style.js.Style::setMarginRight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.marginRight = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginRight.call(this,value);
		var $tmp = this._marginRight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginTop: function(value) {
		$s.push("cocktailCore.style.js.Style::setMarginTop");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.marginTop = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginTop.call(this,value);
		var $tmp = this._marginTop = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMarginBottom: function(value) {
		$s.push("cocktailCore.style.js.Style::setMarginBottom");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.marginBottom = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginBottom.call(this,value);
		var $tmp = this._marginBottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingLeft: function(value) {
		$s.push("cocktailCore.style.js.Style::setPaddingLeft");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.paddingLeft = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingLeft.call(this,value);
		var $tmp = this._paddingLeft = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingRight: function(value) {
		$s.push("cocktailCore.style.js.Style::setPaddingRight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.paddingRight = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingRight.call(this,value);
		var $tmp = this._paddingRight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingTop: function(value) {
		$s.push("cocktailCore.style.js.Style::setPaddingTop");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.paddingTop = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingTop.call(this,value);
		var $tmp = this._paddingTop = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPaddingBottom: function(value) {
		$s.push("cocktailCore.style.js.Style::setPaddingBottom");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.paddingBottom = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingBottom.call(this,value);
		var $tmp = this._paddingBottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setDisplay: function(value) {
		$s.push("cocktailCore.style.js.Style::setDisplay");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.display = this.getCSSDisplay(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setDisplay.call(this,value);
		var $tmp = this._display = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setPosition: function(value) {
		$s.push("cocktailCore.style.js.Style::setPosition");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.position = this.getCSSPosition(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPosition.call(this,value);
		var $tmp = this._position = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.style.js.Style::setWidth");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.width = this.getCSSDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWidth.call(this,value);
		var $tmp = this._width = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.style.js.Style::setHeight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.height = this.getCSSDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setHeight.call(this,value);
		var $tmp = this._height = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMinHeight: function(value) {
		$s.push("cocktailCore.style.js.Style::setMinHeight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMinHeight.call(this,value);
		var $tmp = this._minHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMaxHeight: function(value) {
		$s.push("cocktailCore.style.js.Style::setMaxHeight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMaxHeight.call(this,value);
		var $tmp = this._maxHeight = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMinWidth: function(value) {
		$s.push("cocktailCore.style.js.Style::setMinWidth");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMinWidth.call(this,value);
		var $tmp = this._minWidth = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setMaxWidth: function(value) {
		$s.push("cocktailCore.style.js.Style::setMaxWidth");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMaxWidth.call(this,value);
		var $tmp = this._maxWidth = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTop: function(value) {
		$s.push("cocktailCore.style.js.Style::setTop");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.top = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTop.call(this,value);
		var $tmp = this._top = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLeft: function(value) {
		$s.push("cocktailCore.style.js.Style::setLeft");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.left = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLeft.call(this,value);
		var $tmp = this._left = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBottom: function(value) {
		$s.push("cocktailCore.style.js.Style::setBottom");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.bottom = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBottom.call(this,value);
		var $tmp = this._bottom = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setRight: function(value) {
		$s.push("cocktailCore.style.js.Style::setRight");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.right = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setRight.call(this,value);
		var $tmp = this._right = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextIndent: function(value) {
		$s.push("cocktailCore.style.js.Style::setTextIndent");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.textIndent = this.getCSSTextIndent(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextIndent.call(this,value);
		var $tmp = this._textIndent = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setFloatValue: function(value) {
		$s.push("cocktailCore.style.js.Style::setFloatValue");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFloatValue.call(this,value);
		var $tmp = this.floatValue = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setClear: function(value) {
		$s.push("cocktailCore.style.js.Style::setClear");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.clear = this.getCSSClear(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setClear.call(this,value);
		var $tmp = this._clear = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWhiteSpace: function(value) {
		$s.push("cocktailCore.style.js.Style::setWhiteSpace");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWhiteSpace.call(this,value);
		var $tmp = this._whiteSpace = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTextAlign: function(value) {
		$s.push("cocktailCore.style.js.Style::setTextAlign");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.textAlign = this.getCSSTextAlign(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextAlign.call(this,value);
		var $tmp = this._textAlign = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOpacity: function(value) {
		$s.push("cocktailCore.style.js.Style::setOpacity");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.opacity = this.getCSSOpacity(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setOpacity.call(this,value);
		var $tmp = this._opacity = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setVisibility: function(value) {
		$s.push("cocktailCore.style.js.Style::setVisibility");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.visibility = this.getCSSVisibility(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setVisibility.call(this,value);
		var $tmp = this._visibility = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTransformOrigin: function(value) {
		$s.push("cocktailCore.style.js.Style::setTransformOrigin");
		var $spos = $s.length;
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transformOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransformOrigin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTransformOrigin.call(this,value);
		var $tmp = this._transformOrigin = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTransform: function(value) {
		$s.push("cocktailCore.style.js.Style::setTransform");
		var $spos = $s.length;
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transform");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransform(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTransform.call(this,value);
		var $tmp = this._transform = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundColor: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundColor");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.backgroundColor = this.getCSSBackgroundColor(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundColor.call(this,value);
		var $tmp = this._backgroundColor;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundOrigin: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundOrigin");
		var $spos = $s.length;
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundOrigin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundOrigin.call(this,value);
		var $tmp = this._backgroundOrigin;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundClip: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundClip");
		var $spos = $s.length;
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundClip");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundClip(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundClip.call(this,value);
		var $tmp = this._backgroundClip;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundImage: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundImage");
		var $spos = $s.length;
		var cssBackgroundImage = this.getCSSBackgroundImage(value);
		this._domElement.getNativeElement().style.backgroundImage = cssBackgroundImage;
		this._domElement.getNativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-webkit-linear-gradient");
		this._domElement.getNativeElement().style.backgroundImage = StringTools.replace(cssBackgroundImage,"linear-gradient","-moz-linear-gradient");
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundImage.call(this,value);
		var $tmp = this._backgroundImage;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundPosition: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundPosition");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.backgroundPosition = this.getCSSBackgroundPosition(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundPosition.call(this,value);
		var $tmp = this._backgroundPosition;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundSize: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundSize");
		var $spos = $s.length;
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"backgroundSize");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSBackgroundSize(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundSize.call(this,value);
		var $tmp = this._backgroundSize;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBackgroundRepeat: function(value) {
		$s.push("cocktailCore.style.js.Style::setBackgroundRepeat");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.backgroundRepeat = this.getCSSBackgroundRepeat(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBackgroundRepeat.call(this,value);
		var $tmp = this._backgroundRepeat;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOverflow: function(value) {
		$s.push("cocktailCore.style.js.Style::setOverflow");
		var $spos = $s.length;
		this._domElement.getNativeElement().style.overflowX = this.getCSSOverflow(value.x);
		this._domElement.getNativeElement().style.overflowY = this.getCSSOverflow(value.y);
		cocktailCore.style.abstract.AbstractStyle.prototype.setOverflow.call(this,value);
		var $tmp = this._overflow = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.js.Style
});
cocktailCore.style.abstract.AbstractContainerStyle = $hxClasses["cocktailCore.style.abstract.AbstractContainerStyle"] = function(domElement) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::new");
	var $spos = $s.length;
	cocktailCore.style.js.Style.call(this,domElement);
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.__name__ = ["cocktailCore","style","abstract","AbstractContainerStyle"];
cocktailCore.style.abstract.AbstractContainerStyle.__super__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractContainerStyle.prototype = $extend(cocktailCore.style.js.Style.prototype,{
	render: function(nativeElement) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::render");
		var $spos = $s.length;
		this._nativeElements = this._elementRenderer.getLayerRenderer().render(nativeElement);
		this._nativeElements.reverse();
		this.attachNativeElements(this._nativeElements);
		$s.pop();
	}
	,createElementRenderer: function(parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::createElementRenderer");
		var $spos = $s.length;
		var elementRenderer;
		if(this.isInlineLevel() == true) elementRenderer = new cocktailCore.style.renderer.InlineBoxRenderer(this._domElement); else elementRenderer = new cocktailCore.style.renderer.BlockBoxRenderer(this._domElement);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		parentElementRenderer.addChild(elementRenderer);
		$s.pop();
		return elementRenderer;
		$s.pop();
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::layout");
		var $spos = $s.length;
		this.flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,null,null,null);
		$s.pop();
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::flowChildren");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().computeDisplayStyles();
			}
		}
		var childrenFormattingContext = this.getformattingContext(formattingContext);
		var childrenContainingDOMElementData = this.getContainerDOMElementData();
		var childrenContainingDOMElementFontMetricsData = this.getFontMetricsData();
		var childLastPositionedDOMElementData;
		childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		childrenFormattingContext = this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
		if(this._width == cocktail.style.DimensionStyleValue.autoValue) {
			var currentWidth = this._computedStyle.width;
			this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData,childrenFormattingContext.getFormattingContextData().maxWidth);
			if(currentWidth != this._computedStyle.width) {
				childrenFormattingContext = this.getformattingContext(formattingContext);
				childrenContainingDOMElementData = this.getContainerDOMElementData();
				childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
				childrenFormattingContext = this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
			}
		}
		if(this._height == cocktail.style.DimensionStyleValue.autoValue) {
			if(this.establishesNewFormattingContext() == false) {
				childrenFormattingContext.format();
				this._computedStyle.height = this.applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getChildrenHeight(this._elementRenderer));
			} else this._computedStyle.height = this.applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getFormattingContextData().maxHeight);
		}
		this.doPositionAbsolutelyPositionedDOMElements(this.isPositioned(),childLastPositionedDOMElementData,viewportData);
		$s.pop();
	}
	,doFlowChildren: function(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::doFlowChildren");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		var flowBoxRenderer = this._elementRenderer;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().flow(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext,this._elementRenderer);
			} else {
				var childrenTextElement = containerDOMElement.getChildren()[i].child;
				var insertedText = this.insertTextElement(childrenTextElement,childrenFormattingContext,childrenContainingDOMElementData);
				var _g3 = 0, _g2 = insertedText.length;
				while(_g3 < _g2) {
					var j = _g3++;
					flowBoxRenderer.addChild(insertedText[j]);
				}
			}
		}
		if(this.establishesNewFormattingContext() == true) childrenFormattingContext.format();
		$s.pop();
		return childrenFormattingContext;
		$s.pop();
	}
	,doPositionAbsolutelyPositionedDOMElements: function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::doPositionAbsolutelyPositionedDOMElements");
		var $spos = $s.length;
		var boxElementsData = new Array();
		if(isFirstPositionedAncestor == true) {
			childLastPositionedDOMElementData.data = this.getContainerDOMElementData();
			childLastPositionedDOMElementData.data.height = this.getComputedHeight();
			var _g1 = 0, _g = childLastPositionedDOMElementData.children.length;
			while(_g1 < _g) {
				var i = _g1++;
				var positionedDOMElementData = childLastPositionedDOMElementData.children[i];
				var formattingContextRootParent = positionedDOMElementData.formattingContext.getContainingDOMElement();
				var xOffset = formattingContextRootParent.getGlobalX() - this._domElement.getGlobalX();
				var yOffset = formattingContextRootParent.getGlobalY() - this._domElement.getGlobalY();
				positionedDOMElementData.staticPosition.x += xOffset;
				positionedDOMElementData.staticPosition.y += yOffset;
				var boxElementData = positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data,viewportData,positionedDOMElementData.staticPosition);
				boxElementData.getBounds().x -= this._computedStyle.paddingLeft + this._computedStyle.marginLeft;
				boxElementData.getBounds().y -= this._computedStyle.marginTop + this._computedStyle.paddingTop;
				boxElementsData.push(boxElementData);
			}
		}
		$s.pop();
		return boxElementsData;
		$s.pop();
	}
	,insertTextElement: function(textElement,formattingContext,containingDOMElementData) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::insertTextElement");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		var rendereredText = new Array();
		var text = textElement.getText();
		var textFragments = textElement.getTextFragments(text);
		var _g1 = 0, _g = textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			var $e = (textFragments[i].textToken);
			switch( $e[1] ) {
			case 0:
				var value = $e[2];
				var textFragmentDOMElement = this.getTextFragmentDOMElement(textFragments[i],value);
				var textRenderer = new cocktailCore.style.renderer.TextRenderer(textFragmentDOMElement,textFragments[i].textToken);
				textRenderer.setLayerRenderer(this._elementRenderer.getLayerRenderer());
				rendereredText.push(textRenderer);
				formattingContext.insertElement(textRenderer);
				break;
			case 1:
				var textFragmentDOMElement = this.getTextFragmentDOMElement(textFragments[i]," ");
				var textRenderer = new cocktailCore.style.renderer.TextRenderer(textFragmentDOMElement,textFragments[i].textToken);
				textRenderer.setLayerRenderer(this._elementRenderer.getLayerRenderer());
				rendereredText.push(textRenderer);
				formattingContext.insertElement(textRenderer);
				break;
			case 2:
				break;
			case 3:
				break;
			}
		}
		$s.pop();
		return rendereredText;
		var $tmp = [];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,shrinkToFitIfNeeded: function(containingDOMElementData,minimumWidth) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::shrinkToFitIfNeeded");
		var $spos = $s.length;
		var boxComputer = this.getBoxStylesComputer();
		var $tmp = boxComputer.shrinkToFit(this,containingDOMElementData,minimumWidth);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,applyContentHeightIfNeeded: function(containingDOMElementData,childrenHeight) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::applyContentHeightIfNeeded");
		var $spos = $s.length;
		var boxComputer = this.getBoxStylesComputer();
		var $tmp = boxComputer.applyContentHeight(this,containingDOMElementData,childrenHeight);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,invalidateText: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::invalidateText");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		containerDOMElement.resetTextFragments();
		cocktailCore.style.js.Style.prototype.invalidateText.call(this);
		$s.pop();
	}
	,getTextFragmentDOMElement: function(textFragmentData,text) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getTextFragmentDOMElement");
		var $spos = $s.length;
		var textFragmentDOMElement;
		if(textFragmentData.textFragmentDOMElement == null) {
			textFragmentDOMElement = this.createTextFragment(text);
			textFragmentData.textFragmentDOMElement = textFragmentDOMElement;
		} else textFragmentDOMElement = textFragmentData.textFragmentDOMElement;
		$s.pop();
		return textFragmentDOMElement;
		$s.pop();
	}
	,createTextFragment: function(text) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::createTextFragment");
		var $spos = $s.length;
		var textFragmentDOMElement = this.doCreateTextFragment(text);
		var containerDOMElement = this._domElement;
		containerDOMElement.addTextFragment(textFragmentDOMElement);
		$s.pop();
		return textFragmentDOMElement;
		$s.pop();
	}
	,doCreateTextFragment: function(text) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::doCreateTextFragment");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,getContainerDOMElementData: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getContainerDOMElementData");
		var $spos = $s.length;
		var height;
		if(this.isInlineLevel() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.establishesNewFormattingContext() == true && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
		var $tmp = { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.autoValue, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.autoValue};
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getformattingContext: function(previousformattingContext) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getformattingContext");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		var formattingContext;
		if(this.establishesNewFormattingContext() == true || previousformattingContext == null) {
			if(this.childrenInline() == true) formattingContext = new cocktailCore.style.formatter.InlineFormattingContext(containerDOMElement); else formattingContext = new cocktailCore.style.formatter.BlockFormattingContext(containerDOMElement);
		} else formattingContext = previousformattingContext;
		$s.pop();
		return formattingContext;
		$s.pop();
	}
	,childrenInline: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::childrenInline");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		if(containerDOMElement.getChildren().length == 0) {
			$s.pop();
			return false;
		}
		var ret = this.isChildInline(containerDOMElement.getChildren()[0]);
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isChildInline(containerDOMElement.getChildren()[i]) != ret) {
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,isChildInline: function(child) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::isChildInline");
		var $spos = $s.length;
		var ret = true;
		if(this.isDOMElement(child)) {
			var childrenDOMElement = child.child;
			if(childrenDOMElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.block) {
				if(childrenDOMElement.getStyle().isFloat() == false) ret = false; else if(childrenDOMElement.getStyle().isPositioned() == false || childrenDOMElement.getStyle().isRelativePositioned() == true) ret = false;
			} else ret = true;
		} else ret = true;
		$s.pop();
		return ret;
		$s.pop();
	}
	,getChildLastPositionedDOMElementData: function(lastPositionedDOMElementData) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getChildLastPositionedDOMElementData");
		var $spos = $s.length;
		var childLastPositionedDOMElementData;
		if(this.isPositioned() == true) childLastPositionedDOMElementData = { data : this.getContainerDOMElementData(), children : new Array()}; else childLastPositionedDOMElementData = lastPositionedDOMElementData;
		$s.pop();
		return childLastPositionedDOMElementData;
		$s.pop();
	}
	,establishesNewFormattingContext: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::establishesNewFormattingContext");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,isInlineContainer: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::isInlineContainer");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,getComputedHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getComputedHeight");
		var $spos = $s.length;
		var $tmp = this._computedStyle.height;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,isDOMElement: function(containerDOMElementChildData) {
		$s.push("cocktailCore.style.abstract.AbstractContainerStyle::isDOMElement");
		var $spos = $s.length;
		var ret = false;
		switch( (containerDOMElementChildData.type)[1] ) {
		case 0:
			ret = true;
			break;
		case 1:
			ret = false;
			break;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,__class__: cocktailCore.style.abstract.AbstractContainerStyle
});
if(!cocktailCore.focus) cocktailCore.focus = {}
if(!cocktailCore.focus["abstract"]) cocktailCore.focus["abstract"] = {}
cocktailCore.focus.abstract.AbstractFocusManagerImpl = $hxClasses["cocktailCore.focus.abstract.AbstractFocusManagerImpl"] = function() {
	$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::new");
	var $spos = $s.length;
	this.initKeyboardListeners();
	$s.pop();
}
cocktailCore.focus.abstract.AbstractFocusManagerImpl.__name__ = ["cocktailCore","focus","abstract","AbstractFocusManagerImpl"];
cocktailCore.focus.abstract.AbstractFocusManagerImpl.prototype = {
	_bodyDOMElement: null
	,bodyDOMElement: null
	,_activeDOMElement: null
	,activeDOMElement: null
	,_tabList: null
	,_tabListIndex: null
	,initKeyboardListeners: function() {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::initKeyboardListeners");
		var $spos = $s.length;
		var keyboard = new cocktailCore.keyboard.js.Keyboard(cocktail.nativeElement.NativeElementManager.getRoot());
		keyboard.setOnKeyDown(this.onKeyDown.$bind(this));
		keyboard.setOnKeyUp(this.onKeyUp.$bind(this));
		$s.pop();
	}
	,invalidate: function() {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::invalidate");
		var $spos = $s.length;
		this._tabList == null;
		$s.pop();
	}
	,onKeyDown: function(keyEventData) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::onKeyDown");
		var $spos = $s.length;
		switch( (keyEventData.value)[1] ) {
		case 75:
			this.doTabFocus(keyEventData.shiftKey);
			break;
		case 34:
		case 74:
			this.simulateMouseClick(keyEventData);
			break;
		default:
			if(this.getActiveDOMElement().getOnKeyDown() != null) (this.getActiveDOMElement().getOnKeyDown())(keyEventData);
		}
		$s.pop();
	}
	,onKeyUp: function(keyEventData) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::onKeyUp");
		var $spos = $s.length;
		if(this._activeDOMElement.getOnKeyUp() != null) (this._activeDOMElement.getOnKeyUp())(keyEventData);
		$s.pop();
	}
	,doTabFocus: function(reverse) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::doTabFocus");
		var $spos = $s.length;
		if(this._tabList == null) this._tabList = this.buildTabList(this._bodyDOMElement);
		if(this.getActiveDOMElement() != this._bodyDOMElement) {
			if(reverse == false) {
				if(this._tabListIndex == this._tabList.length - 1) this._tabListIndex = 0; else this._tabListIndex++;
			} else if(this._tabListIndex == 0) this._tabListIndex = this._tabList.length - 1; else this._tabListIndex--;
		} else if(reverse == false) this._tabListIndex = 0; else this._tabListIndex = this._tabList.length - 1;
		this.setActiveDOMElement(this._tabList[this._tabListIndex]);
		$s.pop();
	}
	,buildTabList: function(containerDOMElement) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::buildTabList");
		var $spos = $s.length;
		this._tabListIndex = 0;
		var orderedTabList = new Array();
		var indexedTabList = new Array();
		this.doBuildTabList(containerDOMElement,orderedTabList,indexedTabList);
		var _g1 = 0, _g = orderedTabList.length;
		while(_g1 < _g) {
			var i = _g1++;
			indexedTabList.push(orderedTabList[i]);
		}
		$s.pop();
		return indexedTabList;
		$s.pop();
	}
	,doBuildTabList: function(containerDOMElement,orderedTabList,indexedTabList) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::doBuildTabList");
		var $spos = $s.length;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(containerDOMElement.getChildren()[i].type == cocktailCore.domElement.ContainerDOMElementChildValue.domElement) {
				var child = containerDOMElement.getChildren()[i].child;
				if(Std["is"](child,cocktailCore.domElement.js.ContainerDOMElement) == true) {
					var containerChild = child;
					this.doBuildTabList(containerChild,orderedTabList,indexedTabList);
				}
				if(child.getTabEnabled() == true) {
					if(child.getTabIndex() == 0) orderedTabList.push(child); else if(child.getTabIndex() > 0) {
						if(indexedTabList.length == 0) indexedTabList.push(child); else {
							var foundSpotFlag = false;
							var _g3 = 0, _g2 = indexedTabList.length;
							while(_g3 < _g2) {
								var j = _g3++;
								if(child.getTabIndex() < indexedTabList[j].getTabIndex()) {
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
		$s.pop();
	}
	,simulateMouseClick: function(keyEventData) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::simulateMouseClick");
		var $spos = $s.length;
		if(this.getActiveDOMElement().getOnMouseDown() != null) {
			var mousePositionData = { localX : 0.0, localY : 0.0, globalX : this.getActiveDOMElement().getGlobalX(), globalY : this.getActiveDOMElement().getGlobalY()};
			var mouseEventData = { mousePosition : mousePositionData, ctrlKey : keyEventData.ctrlKey, altKey : keyEventData.altKey, shiftKey : keyEventData.shiftKey};
			(this.getActiveDOMElement().getOnMouseDown())(mouseEventData);
		}
		$s.pop();
	}
	,setActiveDOMElement: function(value) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::setActiveDOMElement");
		var $spos = $s.length;
		if(this._activeDOMElement != null) {
			if(this._activeDOMElement.getOnFocusOut() != null) (this._activeDOMElement.getOnFocusOut())();
		}
		if(value == null) value = this._bodyDOMElement;
		if(value != this._activeDOMElement) {
			this._activeDOMElement = value;
			if(this._activeDOMElement.getOnFocusIn() != null) (this._activeDOMElement.getOnFocusIn())();
		}
		var $tmp = this._activeDOMElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getActiveDOMElement: function() {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::getActiveDOMElement");
		var $spos = $s.length;
		var $tmp = this._activeDOMElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBodyDOMElement: function(value) {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::setBodyDOMElement");
		var $spos = $s.length;
		this._bodyDOMElement = value;
		this.setActiveDOMElement(null);
		this.invalidate();
		var $tmp = this._bodyDOMElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBodyDOMElement: function() {
		$s.push("cocktailCore.focus.abstract.AbstractFocusManagerImpl::getBodyDOMElement");
		var $spos = $s.length;
		var $tmp = this._bodyDOMElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.focus.abstract.AbstractFocusManagerImpl
	,__properties__: {set_activeDOMElement:"setActiveDOMElement",get_activeDOMElement:"getActiveDOMElement",set_bodyDOMElement:"setBodyDOMElement",get_bodyDOMElement:"getBodyDOMElement"}
}
var List = $hxClasses["List"] = function() {
	$s.push("List::new");
	var $spos = $s.length;
	this.length = 0;
	$s.pop();
}
List.__name__ = ["List"];
List.prototype = {
	h: null
	,q: null
	,length: null
	,add: function(item) {
		$s.push("List::add");
		var $spos = $s.length;
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
		$s.pop();
	}
	,push: function(item) {
		$s.push("List::push");
		var $spos = $s.length;
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
		$s.pop();
	}
	,first: function() {
		$s.push("List::first");
		var $spos = $s.length;
		var $tmp = this.h == null?null:this.h[0];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,last: function() {
		$s.push("List::last");
		var $spos = $s.length;
		var $tmp = this.q == null?null:this.q[0];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,pop: function() {
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
	,isEmpty: function() {
		$s.push("List::isEmpty");
		var $spos = $s.length;
		var $tmp = this.h == null;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,clear: function() {
		$s.push("List::clear");
		var $spos = $s.length;
		this.h = null;
		this.q = null;
		this.length = 0;
		$s.pop();
	}
	,remove: function(v) {
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
	,iterator: function() {
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
	,toString: function() {
		$s.push("List::toString");
		var $spos = $s.length;
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
		var $tmp = s.b.join("");
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,join: function(sep) {
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
	,filter: function(f) {
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
	,map: function(f) {
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
	,__class__: List
}
org.intermedia.view.ListViewBase = $hxClasses["org.intermedia.view.ListViewBase"] = function() {
	$s.push("org.intermedia.view.ListViewBase::new");
	var $spos = $s.length;
	org.intermedia.view.ViewBase.call(this);
	this._cells = new Array();
	$s.pop();
}
org.intermedia.view.ListViewBase.__name__ = ["org","intermedia","view","ListViewBase"];
org.intermedia.view.ListViewBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.ListViewBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	onListItemSelected: null
	,onListScrolled: null
	,_cells: null
	,updateView: function() {
		$s.push("org.intermedia.view.ListViewBase::updateView");
		var $spos = $s.length;
		var me = this;
		var _g = 0, _g1 = Reflect.fields(this._data);
		while(_g < _g1.length) {
			var index = _g1[_g];
			++_g;
			var cell = [this.createCell()];
			cell[0].setData(Reflect.field(this._data,index));
			cell[0].setOnMouseUp((function(cell) {
				$s.push("org.intermedia.view.ListViewBase::updateView@52");
				var $spos = $s.length;
				var $tmp = function(mouseEventData) {
					$s.push("org.intermedia.view.ListViewBase::updateView@52@52");
					var $spos = $s.length;
					me.onListItemSelectedCallback(cell[0].getData());
					$s.pop();
				};
				$s.pop();
				return $tmp;
				$s.pop();
			})(cell));
			this._cells.push(cell[0]);
			this.addChild(cell[0]);
		}
		$s.pop();
	}
	,createCell: function() {
		$s.push("org.intermedia.view.ListViewBase::createCell");
		var $spos = $s.length;
		var cell = new org.intermedia.view.CellBase();
		$s.pop();
		return cell;
		$s.pop();
	}
	,onListItemSelectedCallback: function(cellData) {
		$s.push("org.intermedia.view.ListViewBase::onListItemSelectedCallback");
		var $spos = $s.length;
		if(this.onListItemSelected != null) this.onListItemSelected(cellData);
		$s.pop();
	}
	,__class__: org.intermedia.view.ListViewBase
});
var IntIter = $hxClasses["IntIter"] = function(min,max) {
	$s.push("IntIter::new");
	var $spos = $s.length;
	this.min = min;
	this.max = max;
	$s.pop();
}
IntIter.__name__ = ["IntIter"];
IntIter.prototype = {
	min: null
	,max: null
	,hasNext: function() {
		$s.push("IntIter::hasNext");
		var $spos = $s.length;
		var $tmp = this.min < this.max;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,next: function() {
		$s.push("IntIter::next");
		var $spos = $s.length;
		var $tmp = this.min++;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: IntIter
}
if(!cocktailCore.keyboard) cocktailCore.keyboard = {}
if(!cocktailCore.keyboard["abstract"]) cocktailCore.keyboard["abstract"] = {}
cocktailCore.keyboard.abstract.AbstractKeyboard = $hxClasses["cocktailCore.keyboard.abstract.AbstractKeyboard"] = function(nativeElement) {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::new");
	var $spos = $s.length;
	this._nativeElement = nativeElement;
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.__name__ = ["cocktailCore","keyboard","abstract","AbstractKeyboard"];
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype = {
	_onKeyDown: null
	,onKeyDown: null
	,_onKeyUp: null
	,onKeyUp: null
	,_nativeElement: null
	,_keyDownEvent: null
	,_keyUpEvent: null
	,onNativeKeyDown: function(event) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::onNativeKeyDown");
		var $spos = $s.length;
		if(this.getOnKeyDown() != null) (this.getOnKeyDown())(this.getKeyData(event));
		$s.pop();
	}
	,onNativeKeyUp: function(event) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::onNativeKeyUp");
		var $spos = $s.length;
		if(this.getOnKeyUp() != null) (this.getOnKeyUp())(this.getKeyData(event));
		$s.pop();
	}
	,setOnKeyDown: function(value) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::setOnKeyDown");
		var $spos = $s.length;
		this.updateListeners(this._keyDownEvent,this.onNativeKeyDown.$bind(this),value);
		var $tmp = this._onKeyDown = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnKeyDown: function() {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::getOnKeyDown");
		var $spos = $s.length;
		var $tmp = this._onKeyDown;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnKeyUp: function(value) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::setOnKeyUp");
		var $spos = $s.length;
		this.updateListeners(this._keyUpEvent,this.onNativeKeyUp.$bind(this),value);
		var $tmp = this._onKeyUp = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnKeyUp: function() {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::getOnKeyUp");
		var $spos = $s.length;
		var $tmp = this._onKeyUp;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,updateListeners: function(keyboardEvent,nativeCallback,domElementCallback) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::updateListeners");
		var $spos = $s.length;
		$s.pop();
	}
	,getKeyData: function(event) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::getKeyData");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,getKeyValue: function(keyCode) {
		$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::getKeyValue");
		var $spos = $s.length;
		var keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.unknown;
		switch(keyCode) {
		case 65:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.a;
			break;
		case 66:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.b;
			break;
		case 67:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.c;
			break;
		case 68:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.d;
			break;
		case 69:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.e;
			break;
		case 70:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.f;
			break;
		case 71:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.g;
			break;
		case 72:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.h;
			break;
		case 73:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.i;
			break;
		case 74:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.j;
			break;
		case 75:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.k;
			break;
		case 76:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.l;
			break;
		case 77:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.m;
			break;
		case 78:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.n;
			break;
		case 79:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.o;
			break;
		case 80:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.p;
			break;
		case 81:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.q;
			break;
		case 82:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.r;
			break;
		case 83:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.s;
			break;
		case 84:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.t;
			break;
		case 85:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.u;
			break;
		case 86:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.v;
			break;
		case 87:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.w;
			break;
		case 88:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.x;
			break;
		case 89:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.y;
			break;
		case 90:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.z;
			break;
		case 8:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.backSpace;
			break;
		case 20:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.capsLock;
			break;
		case 17:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.control;
			break;
		case 46:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.del;
			break;
		case 40:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.down;
			break;
		case 35:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.end;
			break;
		case 13:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.enter;
			break;
		case 27:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.escape;
			break;
		case 112:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F1;
			break;
		case 121:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F10;
			break;
		case 122:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F11;
			break;
		case 123:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F12;
			break;
		case 124:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F13;
			break;
		case 125:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F14;
			break;
		case 126:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F15;
			break;
		case 113:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F2;
			break;
		case 114:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F3;
			break;
		case 115:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F4;
			break;
		case 116:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F5;
			break;
		case 117:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F6;
			break;
		case 118:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F7;
			break;
		case 119:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F8;
			break;
		case 120:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.F9;
			break;
		case 36:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.home;
			break;
		case 45:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.insert;
			break;
		case 37:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.left;
			break;
		case 96:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad0;
			break;
		case 97:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad1;
			break;
		case 98:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad2;
			break;
		case 99:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad3;
			break;
		case 100:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad4;
			break;
		case 101:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad5;
			break;
		case 102:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad6;
			break;
		case 103:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad7;
			break;
		case 104:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad8;
			break;
		case 105:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpad9;
			break;
		case 107:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadAdd;
			break;
		case 108:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadEnter;
			break;
		case 110:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadDecimal;
			break;
		case 111:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadDivide;
			break;
		case 106:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadMultiply;
			break;
		case 109:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.numpadSubstract;
			break;
		case 34:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.pageDown;
			break;
		case 33:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.pageUp;
			break;
		case 39:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.right;
			break;
		case 16:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.shift;
			break;
		case 32:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.space;
			break;
		case 9:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.tab;
			break;
		case 38:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.up;
			break;
		default:
			keyboardKeyValue = cocktail.keyboard.KeyboardKeyValue.unknown;
		}
		$s.pop();
		return keyboardKeyValue;
		$s.pop();
	}
	,__class__: cocktailCore.keyboard.abstract.AbstractKeyboard
	,__properties__: {set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown"}
}
if(!cocktailCore.keyboard.js) cocktailCore.keyboard.js = {}
cocktailCore.keyboard.js.Keyboard = $hxClasses["cocktailCore.keyboard.js.Keyboard"] = function(nativeElement) {
	$s.push("cocktailCore.keyboard.js.Keyboard::new");
	var $spos = $s.length;
	cocktailCore.keyboard.abstract.AbstractKeyboard.call(this,nativeElement);
	this._keyDownEvent = "keydown";
	this._keyUpEvent = "keyup";
	$s.pop();
}
cocktailCore.keyboard.js.Keyboard.__name__ = ["cocktailCore","keyboard","js","Keyboard"];
cocktailCore.keyboard.js.Keyboard.__super__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
cocktailCore.keyboard.js.Keyboard.prototype = $extend(cocktailCore.keyboard.abstract.AbstractKeyboard.prototype,{
	updateListeners: function(keyboardEvent,nativeCallback,domElementCallback) {
		$s.push("cocktailCore.keyboard.js.Keyboard::updateListeners");
		var $spos = $s.length;
		this._nativeElement.removeEventListener(keyboardEvent,nativeCallback);
		if(domElementCallback != null) this._nativeElement.addEventListener(keyboardEvent,nativeCallback);
		$s.pop();
	}
	,getKeyData: function(event) {
		$s.push("cocktailCore.keyboard.js.Keyboard::getKeyData");
		var $spos = $s.length;
		var key = { value : this.getKeyValue(event.keyCode), code : event.keyCode, ascii : event.charCode, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
		$s.pop();
		return key;
		$s.pop();
	}
	,__class__: cocktailCore.keyboard.js.Keyboard
});
org.intermedia.view.ListViewStyle = $hxClasses["org.intermedia.view.ListViewStyle"] = function() { }
org.intermedia.view.ListViewStyle.__name__ = ["org","intermedia","view","ListViewStyle"];
org.intermedia.view.ListViewStyle.setListStyle = function(domElement) {
	$s.push("org.intermedia.view.ListViewStyle::setListStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(43)));
	$s.pop();
}
org.intermedia.view.ListViewStyle.prototype = {
	__class__: org.intermedia.view.ListViewStyle
}
org.intermedia.view.SwippableListView = $hxClasses["org.intermedia.view.SwippableListView"] = function() {
	$s.push("org.intermedia.view.SwippableListView::new");
	var $spos = $s.length;
	org.intermedia.view.ListViewBase.call(this);
	this._xOffset = 0;
	this._xOffsetStart = 0;
	this._initialPosition = 0;
	this._viewportWidth = new cocktailCore.viewport.js.Viewport()._getWidth();
	org.intermedia.view.SwippableListViewStyle.setListStyle(this);
	this.setOnMouseDown(this.onMouseDownCallback2.$bind(this));
	this._listViews = new Array();
	this.list0 = new org.intermedia.view.ListViewText();
	this.list0.setX(-this._viewportWidth);
	this._listViews.push(this.list0);
	this.list1 = new org.intermedia.view.ViewBase();
	this.list1.setX(0);
	org.intermedia.view.SwippableListViewStyle.setContainerStyle(this.list1);
	this.list11 = new org.intermedia.view.ThumbList(3);
	this.list1.addChild(this.list11);
	this._listViews.push(this.list11);
	this.list12 = new org.intermedia.view.ThumbTextList1Bis(3);
	this.list2 = new org.intermedia.view.ThumbTextList1(2);
	this._listViews.push(this.list2);
	this.list2.setX(this._viewportWidth);
	var _g = 0, _g1 = this._listViews;
	while(_g < _g1.length) {
		var listView = _g1[_g];
		++_g;
		this.addChild(listView);
	}
	this._index = 1;
	this._currentListView = this._listViews[this._index];
	this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
	$s.pop();
}
org.intermedia.view.SwippableListView.__name__ = ["org","intermedia","view","SwippableListView"];
org.intermedia.view.SwippableListView.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.SwippableListView.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_listViews: null
	,list0: null
	,list1: null
	,list11: null
	,list12: null
	,list2: null
	,_currentListView: null
	,_index: null
	,_xOffset: null
	,_xOffsetStart: null
	,_initialPosition: null
	,_viewportWidth: null
	,setData: function(v) {
		$s.push("org.intermedia.view.SwippableListView::setData");
		var $spos = $s.length;
		this._data = v;
		this.list0.setData(this._data);
		this.list1.setData(this._data);
		this.list11.setData(this._data);
		this.list12.setData(this._data);
		this.list2.setData(this._data);
		var $tmp = this._data;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,onMouseDownCallback2: function(mouseEvent) {
		$s.push("org.intermedia.view.SwippableListView::onMouseDownCallback2");
		var $spos = $s.length;
		this._xOffsetStart = Std["int"](mouseEvent.mousePosition.localX);
		this._initialPosition = this.getX();
		this.setOnMouseMove(this.onMouseMoveCallback2.$bind(this));
		this.setOnMouseUp(this.onMouseUpCallback2.$bind(this));
		$s.pop();
	}
	,onMouseMoveCallback2: function(mouseEvent) {
		$s.push("org.intermedia.view.SwippableListView::onMouseMoveCallback2");
		var $spos = $s.length;
		this._xOffset = Std["int"](mouseEvent.mousePosition.localX) - this._xOffsetStart;
		this.setX(this._initialPosition + this._xOffset);
		this._currentListView.onListItemSelected = null;
		$s.pop();
	}
	,onMouseUpCallback2: function(mouseEvent) {
		$s.push("org.intermedia.view.SwippableListView::onMouseUpCallback2");
		var $spos = $s.length;
		this._xOffset = Std["int"](mouseEvent.mousePosition.localX) - this._xOffsetStart;
		if(this._xOffset < -this._viewportWidth / 2) {
			if(this._index < this._listViews.length - 1) {
				this._index++;
				this._currentListView = this._listViews[this._index];
			}
		} else if(this._xOffset > this._viewportWidth / 2) {
			if(this._index > 0) {
				this._index--;
				this._currentListView = this._listViews[this._index];
			}
		}
		this._currentListView.onListItemSelected = this.onListItemSelectedCallback.$bind(this);
		this.animate();
		js.Lib.window.scrollTo(0,0);
		this.setOnMouseMove(null);
		this.setOnMouseUp(null);
		$s.pop();
	}
	,animate: function() {
		$s.push("org.intermedia.view.SwippableListView::animate");
		var $spos = $s.length;
		var tween = new feffects.Tween(this.getX(),-this._currentListView.getX(),600,feffects.easing.Quint.easeOut);
		tween.setTweenHandlers(this.tweenMove.$bind(this),this.tweenEnd.$bind(this));
		tween.start();
		$s.pop();
	}
	,tweenMove: function(e) {
		$s.push("org.intermedia.view.SwippableListView::tweenMove");
		var $spos = $s.length;
		this.setX(Std["int"](e));
		$s.pop();
	}
	,tweenEnd: function(e) {
		$s.push("org.intermedia.view.SwippableListView::tweenEnd");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: org.intermedia.view.SwippableListView
});
org.intermedia.view.CellThumbStyle = $hxClasses["org.intermedia.view.CellThumbStyle"] = function() { }
org.intermedia.view.CellThumbStyle.__name__ = ["org","intermedia","view","CellThumbStyle"];
org.intermedia.view.CellThumbStyle.setCellStyle = function(domElement,cellPerLine) {
	$s.push("org.intermedia.view.CellThumbStyle::setCellStyle");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(5)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	var cellPercentWidth = 0;
	if(cellPerLine != 0) cellPercentWidth = Std["int"](100 / cellPerLine); else cellPercentWidth = 100;
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(cellPercentWidth));
	$s.pop();
}
org.intermedia.view.CellThumbStyle.setThumbnailStyle = function(domElement) {
	$s.push("org.intermedia.view.CellThumbStyle::setThumbnailStyle");
	var $spos = $s.length;
	var imageMaxWidth = 200;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(imageMaxWidth)));
	domElement.getStyle().setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(50));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
org.intermedia.view.CellThumbStyle.prototype = {
	__class__: org.intermedia.view.CellThumbStyle
}
var Hash = $hxClasses["Hash"] = function() {
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
Hash.prototype = {
	h: null
	,set: function(key,value) {
		$s.push("Hash::set");
		var $spos = $s.length;
		this.h["$" + key] = value;
		$s.pop();
	}
	,get: function(key) {
		$s.push("Hash::get");
		var $spos = $s.length;
		var $tmp = this.h["$" + key];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,exists: function(key) {
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
	,remove: function(key) {
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
	,keys: function() {
		$s.push("Hash::keys");
		var $spos = $s.length;
		var a = new Array();
		for(var i in this.h) a.push(i.substr(1));
		var $tmp = a.iterator();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,iterator: function() {
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
	,toString: function() {
		$s.push("Hash::toString");
		var $spos = $s.length;
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
		var $tmp = s.b.join("");
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: Hash
}
org.intermedia.view.CellBase = $hxClasses["org.intermedia.view.CellBase"] = function() {
	$s.push("org.intermedia.view.CellBase::new");
	var $spos = $s.length;
	org.intermedia.view.ViewBase.call(this);
	$s.pop();
}
org.intermedia.view.CellBase.__name__ = ["org","intermedia","view","CellBase"];
org.intermedia.view.CellBase.__super__ = org.intermedia.view.ViewBase;
org.intermedia.view.CellBase.prototype = $extend(org.intermedia.view.ViewBase.prototype,{
	__class__: org.intermedia.view.CellBase
});
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = $hxClasses["cocktailCore.resource.abstract.AbstractResourceLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::new");
	var $spos = $s.length;
	if(nativeElement != null) this._nativeElement = nativeElement;
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype = {
	_onLoadCompleteCallback: null
	,_onLoadErrorCallback: null
	,_nativeElement: null
	,nativeElement: null
	,_intrinsicWidth: null
	,intrinsicWidth: null
	,_intrinsicHeight: null
	,intrinsicHeight: null
	,_intrinsicRatio: null
	,intrinsicRatio: null
	,_urlToLoadIdx: null
	,_urls: null
	,load: function(urls,onLoadComplete,onLoadError,allowCache) {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::load");
		var $spos = $s.length;
		if(allowCache == null) allowCache = true;
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		this._urls = urls;
		this._urlToLoadIdx = 0;
		if(allowCache == false) {
			var _g1 = 0, _g = urls.length;
			while(_g1 < _g) {
				var i = _g1++;
				urls[i] = this.disableUrlCaching(urls[i]);
			}
		}
		this.doLoad(this._urls[this._urlToLoadIdx]);
		$s.pop();
	}
	,doLoad: function(url) {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::doLoad");
		var $spos = $s.length;
		$s.pop();
	}
	,onLoadComplete: function(data) {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::onLoadComplete");
		var $spos = $s.length;
		this._onLoadCompleteCallback(data);
		$s.pop();
	}
	,onLoadError: function(msg) {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::onLoadError");
		var $spos = $s.length;
		this._urlToLoadIdx++;
		if(this._urlToLoadIdx < this._urls.length - 1) this.doLoad(this._urls[this._urlToLoadIdx]); else this._onLoadErrorCallback(msg);
		$s.pop();
	}
	,disableUrlCaching: function(url) {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::disableUrlCaching");
		var $spos = $s.length;
		var getId = "";
		if(url.indexOf("?") == -1) getId = "?"; else getId = "&";
		url += getId + "rand=" + Math.round(Math.random() * 10000);
		$s.pop();
		return url;
		$s.pop();
	}
	,getNativeElement: function() {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::getNativeElement");
		var $spos = $s.length;
		var $tmp = this._nativeElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicWidth: function() {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::getIntrinsicWidth");
		var $spos = $s.length;
		var $tmp = this._intrinsicWidth;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicHeight: function() {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::getIntrinsicHeight");
		var $spos = $s.length;
		var $tmp = this._intrinsicHeight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getIntrinsicRatio: function() {
		$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::getIntrinsicRatio");
		var $spos = $s.length;
		var $tmp = this._intrinsicRatio;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.resource.abstract.AbstractResourceLoader
	,__properties__: {get_intrinsicRatio:"getIntrinsicRatio",get_intrinsicHeight:"getIntrinsicHeight",get_intrinsicWidth:"getIntrinsicWidth",get_nativeElement:"getNativeElement"}
}
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ResourceLoader = $hxClasses["cocktailCore.resource.js.ResourceLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.js.ResourceLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.js.ResourceLoader.__name__ = ["cocktailCore","resource","js","ResourceLoader"];
cocktailCore.resource.js.ResourceLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.ResourceLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	doLoad: function(url) {
		$s.push("cocktailCore.resource.js.ResourceLoader::doLoad");
		var $spos = $s.length;
		var onLoadCompleteDelegate = this.onNativeLoadComplete.$bind(this);
		var onLoadErrorDelegate = this.onNativeLoadError.$bind(this);
		var nativeElementDelegate = this._nativeElement;
		this._nativeElement.onload = function() {
			$s.push("cocktailCore.resource.js.ResourceLoader::doLoad@51");
			var $spos = $s.length;
			onLoadCompleteDelegate(nativeElementDelegate);
			$s.pop();
		};
		this._nativeElement.onerror = function() {
			$s.push("cocktailCore.resource.js.ResourceLoader::doLoad@56");
			var $spos = $s.length;
			onLoadErrorDelegate("couldn't load picture");
			$s.pop();
		};
		this._nativeElement.setAttribute("src",url);
		$s.pop();
	}
	,onNativeLoadComplete: function(nativeElement) {
		$s.push("cocktailCore.resource.js.ResourceLoader::onNativeLoadComplete");
		var $spos = $s.length;
		this.setIntrinsicDimensions(nativeElement);
		this.onLoadComplete(nativeElement);
		$s.pop();
	}
	,onNativeLoadError: function(event) {
		$s.push("cocktailCore.resource.js.ResourceLoader::onNativeLoadError");
		var $spos = $s.length;
		this.onLoadError(event.toString());
		$s.pop();
	}
	,setIntrinsicDimensions: function(nativeElement) {
		$s.push("cocktailCore.resource.js.ResourceLoader::setIntrinsicDimensions");
		var $spos = $s.length;
		this._intrinsicHeight = nativeElement.naturalHeight;
		this._intrinsicWidth = nativeElement.naturalWidth;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
		$s.pop();
	}
	,__class__: cocktailCore.resource.js.ResourceLoader
});
cocktailCore.resource.abstract.AbstractLibraryLoader = $hxClasses["cocktailCore.resource.abstract.AbstractLibraryLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.abstract.AbstractLibraryLoader::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.library);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractLibraryLoader.__name__ = ["cocktailCore","resource","abstract","AbstractLibraryLoader"];
cocktailCore.resource.abstract.AbstractLibraryLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractLibraryLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	onLoadComplete: function(data) {
		$s.push("cocktailCore.resource.abstract.AbstractLibraryLoader::onLoadComplete");
		var $spos = $s.length;
		this._onLoadCompleteCallback(null);
		$s.pop();
	}
	,__class__: cocktailCore.resource.abstract.AbstractLibraryLoader
});
if(!cocktailCore.style.computer) cocktailCore.style.computer = {}
cocktailCore.style.computer.BoxStylesComputer = $hxClasses["cocktailCore.style.computer.BoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.__name__ = ["cocktailCore","style","computer","BoxStylesComputer"];
cocktailCore.style.computer.BoxStylesComputer.prototype = {
	measure: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measure");
		var $spos = $s.length;
		this.measureHorizontalPaddings(style,containingDOMElementData);
		this.measureVerticalPaddings(style,containingDOMElementData);
		this.measureDimensionsConstraints(style,containingDOMElementData);
		this.measureWidthAndHorizontalMargins(style,containingDOMElementData);
		this.measureHeightAndVerticalMargins(style,containingDOMElementData);
		this.measurePositionOffsets(style,containingDOMElementData);
		$s.pop();
	}
	,shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::shrinkToFit");
		var $spos = $s.length;
		var $tmp = style.getComputedStyle().width;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,applyContentHeight: function(style,cotainingDOMElementData,childrenHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::applyContentHeight");
		var $spos = $s.length;
		$s.pop();
		return childrenHeight;
		$s.pop();
	}
	,measureDimensionsConstraints: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureDimensionsConstraints");
		var $spos = $s.length;
		style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		$s.pop();
	}
	,measurePositionOffsets: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measurePositionOffsets");
		var $spos = $s.length;
		style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		$s.pop();
	}
	,measureVerticalPaddings: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureVerticalPaddings");
		var $spos = $s.length;
		style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		$s.pop();
	}
	,measureHorizontalPaddings: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHorizontalPaddings");
		var $spos = $s.length;
		style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		$s.pop();
	}
	,measureWidthAndHorizontalMargins: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureWidthAndHorizontalMargins");
		var $spos = $s.length;
		if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
		$s.pop();
	}
	,measureAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureAutoWidth");
		var $spos = $s.length;
		this.setComputedWidth(style,0);
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingDOMElementData));
		$s.pop();
	}
	,measureWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureWidth");
		var $spos = $s.length;
		this.setComputedWidth(style,this.getComputedWidth(style,containingDOMElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		$s.pop();
	}
	,measureHeightAndVerticalMargins: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHeightAndVerticalMargins");
		var $spos = $s.length;
		if(style.getHeight() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
		$s.pop();
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureAutoHeight");
		var $spos = $s.length;
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
		$s.pop();
	}
	,measureHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHeight");
		var $spos = $s.length;
		this.setComputedHeight(style,this.getComputedHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
		$s.pop();
	}
	,constrainWidth: function(style,computedWidth) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::constrainWidth");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getMaxWidth() != cocktail.style.ConstrainedDimensionStyleValue.none) {
			if(computedWidth > computedStyle.maxWidth) computedWidth = computedStyle.maxWidth;
		}
		if(computedWidth < computedStyle.minWidth) computedWidth = computedStyle.minWidth;
		$s.pop();
		return computedWidth;
		$s.pop();
	}
	,constrainHeight: function(style,computedHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::constrainHeight");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getMaxHeight() != cocktail.style.ConstrainedDimensionStyleValue.none) {
			if(computedHeight > computedStyle.maxHeight) computedHeight = computedStyle.maxHeight;
		}
		if(computedHeight < computedStyle.minHeight) computedHeight = computedStyle.minHeight;
		$s.pop();
		return computedHeight;
		$s.pop();
	}
	,setComputedHeight: function(style,computedHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::setComputedHeight");
		var $spos = $s.length;
		style.getComputedStyle().height = this.constrainHeight(style,computedHeight);
		$s.pop();
	}
	,setComputedWidth: function(style,computedWidth) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::setComputedWidth");
		var $spos = $s.length;
		style.getComputedStyle().width = this.constrainWidth(style,computedWidth);
		$s.pop();
	}
	,getComputedWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedWidth");
		var $spos = $s.length;
		var $tmp = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoWidth");
		var $spos = $s.length;
		var $tmp = containingDOMElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedHeight");
		var $spos = $s.length;
		var $tmp = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedAutoHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoHeight");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,getComputedMarginLeft: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginLeft");
		var $spos = $s.length;
		var $tmp = this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedMarginRight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginRight");
		var $spos = $s.length;
		var $tmp = this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedMarginTop: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginTop");
		var $spos = $s.length;
		var $tmp = this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedMarginBottom: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginBottom");
		var $spos = $s.length;
		var $tmp = this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMargin");
		var $spos = $s.length;
		var computedMargin;
		var $e = (marginStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedMargin = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isDimensionAuto == true) computedMargin = 0; else computedMargin = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
			break;
		case 2:
			computedMargin = this.getComputedAutoMargin(opositeMarginStyleValue,marginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
			break;
		}
		$s.pop();
		return computedMargin;
		$s.pop();
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoMargin");
		var $spos = $s.length;
		var computedMargin;
		if(isHorizontalMargin == false || isDimensionAuto == true) computedMargin = 0; else {
			switch( (opositeMarginStyleValue)[1] ) {
			case 2:
				computedMargin = Math.round((containingDOMElementDimension - computedDimension - computedPaddingsDimension) / 2);
				break;
			default:
				var opositeComputedMargin = this.getComputedMargin(opositeMarginStyleValue,marginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
				computedMargin = containingDOMElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin;
			}
		}
		$s.pop();
		return computedMargin;
		$s.pop();
	}
	,getComputedConstrainedDimension: function(constrainedDimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedConstrainedDimension");
		var $spos = $s.length;
		if(isMinConstraint == null) isMinConstraint = false;
		var computedConstraintDimension;
		var $e = (constrainedDimensionStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedConstraintDimension = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			if(isContainingDimensionAuto == true) {
				if(isMinConstraint == true) computedConstraintDimension = 0; else computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
			} else computedConstraintDimension = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
			break;
		case 2:
			if(isMinConstraint == true) computedConstraintDimension = 0; else computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
			break;
		}
		$s.pop();
		return computedConstraintDimension;
		$s.pop();
	}
	,getComputedPositionOffset: function(positionOffsetStyleValue,containingDOMElementDimension,fontSize,xHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedPositionOffset");
		var $spos = $s.length;
		var computedPositionOffset;
		var $e = (positionOffsetStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedPositionOffset = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPositionOffset = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
			break;
		case 2:
			computedPositionOffset = 0;
			break;
		}
		$s.pop();
		return computedPositionOffset;
		$s.pop();
	}
	,getComputedDimension: function(dimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedDimension");
		var $spos = $s.length;
		var computedDimensions;
		var $e = (dimensionStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedDimensions = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedDimensions = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
			break;
		case 2:
			computedDimensions = 0;
			break;
		}
		$s.pop();
		return computedDimensions;
		$s.pop();
	}
	,getComputedPadding: function(paddingStyleValue,containingDOMElementDimension,fontSize,xHeight) {
		$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedPadding");
		var $spos = $s.length;
		var computedPaddingValue;
		var $e = (paddingStyleValue);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			computedPaddingValue = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
			break;
		case 1:
			var value = $e[2];
			computedPaddingValue = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
			break;
		}
		$s.pop();
		return computedPaddingValue;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.BoxStylesComputer
}
if(!cocktailCore.style.computer.boxComputers) cocktailCore.style.computer.boxComputers = {}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	measureAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::measureAutoWidth");
		var $spos = $s.length;
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingDOMElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		$s.pop();
	}
	,getComputedAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoWidth");
		var $spos = $s.length;
		var ret = 0;
		var embeddedDOMElement = style.getDOMElement();
		if(style.getHeight() == cocktail.style.DimensionStyleValue.autoValue) {
			if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else if(embeddedDOMElement.getIntrinsicHeight() != null && embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(embeddedDOMElement.getIntrinsicHeight() * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicRatio() != null) {
				if(containingDOMElementData.isWidthAuto == false) {
					var computedStyle = style.getComputedStyle();
					ret = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
				} else ret = 0;
			}
		} else {
			var computedHeight = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,computedHeight);
			if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedHeight * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else ret = 300;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getComputedAutoHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoHeight");
		var $spos = $s.length;
		var embeddedDOMElement = style.getDOMElement();
		var ret = 0;
		if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) {
			if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
		} else {
			var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,computedWidth);
			if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(style.getComputedStyle().width / embeddedDOMElement.getIntrinsicRatio()); else ret = 150;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoMargin");
		var $spos = $s.length;
		var computedMargin;
		if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
		$s.pop();
		return computedMargin;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer::getComputedAutoMargin");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer
});
var StringTools = $hxClasses["StringTools"] = function() { }
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
StringTools.prototype = {
	__class__: StringTools
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::getComputedAutoMargin");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::shrinkToFit");
		var $spos = $s.length;
		var shrinkedWidth;
		if(minimumWidth < containingDOMElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingDOMElementData.width;
		$s.pop();
		return shrinkedWidth;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype,{
	getComputedAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::getComputedAutoWidth");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer
});
if(!cocktailCore.style.renderer) cocktailCore.style.renderer = {}
cocktailCore.style.renderer.ElementRenderer = $hxClasses["cocktailCore.style.renderer.ElementRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.ElementRenderer::new");
	var $spos = $s.length;
	this._domElement = domElement;
	this._bounds = { x : 0.0, y : 0.0, width : 0.0, height : 0.0};
	$s.pop();
}
cocktailCore.style.renderer.ElementRenderer.__name__ = ["cocktailCore","style","renderer","ElementRenderer"];
cocktailCore.style.renderer.ElementRenderer.prototype = {
	_bounds: null
	,bounds: null
	,_domElement: null
	,domElement: null
	,_parent: null
	,parent: null
	,_layerRenderer: null
	,layerRenderer: null
	,canHaveChildren: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::canHaveChildren");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isText: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::isText");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isSpace: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::isSpace");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,isLineFeed: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::isLineFeed");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,render: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::render");
		var $spos = $s.length;
		var $tmp = [];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,renderBackground: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::renderBackground");
		var $spos = $s.length;
		var $tmp = [];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setLayerRenderer: function(value) {
		$s.push("cocktailCore.style.renderer.ElementRenderer::setLayerRenderer");
		var $spos = $s.length;
		var $tmp = this._layerRenderer = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getLayerRenderer: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::getLayerRenderer");
		var $spos = $s.length;
		var $tmp = this._layerRenderer;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getDOMElement: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::getDOMElement");
		var $spos = $s.length;
		var $tmp = this._domElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getParent: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::getParent");
		var $spos = $s.length;
		var $tmp = this._parent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setParent: function(value) {
		$s.push("cocktailCore.style.renderer.ElementRenderer::setParent");
		var $spos = $s.length;
		var $tmp = this._parent = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBounds: function() {
		$s.push("cocktailCore.style.renderer.ElementRenderer::getBounds");
		var $spos = $s.length;
		var $tmp = this._bounds;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBounds: function(value) {
		$s.push("cocktailCore.style.renderer.ElementRenderer::setBounds");
		var $spos = $s.length;
		var $tmp = this._bounds = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.ElementRenderer
	,__properties__: {set_layerRenderer:"setLayerRenderer",get_layerRenderer:"getLayerRenderer",set_parent:"setParent",get_parent:"getParent",get_domElement:"getDOMElement",set_bounds:"setBounds",get_bounds:"getBounds"}
}
cocktailCore.resource.abstract.AbstractImageLoader = $hxClasses["cocktailCore.resource.abstract.AbstractImageLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.abstract.AbstractImageLoader::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractImageLoader.__name__ = ["cocktailCore","resource","abstract","AbstractImageLoader"];
cocktailCore.resource.abstract.AbstractImageLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractImageLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	__class__: cocktailCore.resource.abstract.AbstractImageLoader
});
cocktailCore.style.renderer.TextRenderer = $hxClasses["cocktailCore.style.renderer.TextRenderer"] = function(domElement,textToken) {
	$s.push("cocktailCore.style.renderer.TextRenderer::new");
	var $spos = $s.length;
	this._textToken = textToken;
	cocktailCore.style.renderer.ElementRenderer.call(this,domElement);
	this._bounds.width = domElement.getOffsetWidth();
	this._bounds.height = domElement.getOffsetHeight();
	$s.pop();
}
cocktailCore.style.renderer.TextRenderer.__name__ = ["cocktailCore","style","renderer","TextRenderer"];
cocktailCore.style.renderer.TextRenderer.__super__ = cocktailCore.style.renderer.ElementRenderer;
cocktailCore.style.renderer.TextRenderer.prototype = $extend(cocktailCore.style.renderer.ElementRenderer.prototype,{
	_textToken: null
	,render: function() {
		$s.push("cocktailCore.style.renderer.TextRenderer::render");
		var $spos = $s.length;
		var ret = [];
		ret.push(this._domElement.getNativeElement());
		$s.pop();
		return ret;
		$s.pop();
	}
	,isText: function() {
		$s.push("cocktailCore.style.renderer.TextRenderer::isText");
		var $spos = $s.length;
		$s.pop();
		return true;
		$s.pop();
	}
	,isSpace: function() {
		$s.push("cocktailCore.style.renderer.TextRenderer::isSpace");
		var $spos = $s.length;
		var isSpace;
		switch( (this._textToken)[1] ) {
		case 1:
			isSpace = true;
			break;
		default:
			isSpace = false;
		}
		$s.pop();
		return isSpace;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.TextRenderer
});
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = $hxClasses["cocktailCore.style.positioner.BoxPositioner"] = function() {
	$s.push("cocktailCore.style.positioner.BoxPositioner::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype = {
	position: function(elementRenderer,containingDOMElementData,staticPosition) {
		$s.push("cocktailCore.style.positioner.BoxPositioner::position");
		var $spos = $s.length;
		var domElement = elementRenderer.getDOMElement();
		if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue) elementRenderer.getBounds().x = this.getLeftOffset(domElement,Math.round(staticPosition.x)); else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) elementRenderer.getBounds().x = this.getRightOffset(domElement,containingDOMElementData.width,Math.round(staticPosition.x)); else elementRenderer.getBounds().x = Math.round(staticPosition.x);
		if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.autoValue) elementRenderer.getBounds().y = this.getTopOffset(domElement,Math.round(staticPosition.y)); else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) elementRenderer.getBounds().y = this.getBottomOffset(domElement,containingDOMElementData.height,Math.round(staticPosition.y)); else elementRenderer.getBounds().y = Math.round(staticPosition.y);
		elementRenderer.getBounds().width = elementRenderer.getDOMElement().getOffsetWidth();
		elementRenderer.getBounds().height = elementRenderer.getDOMElement().getOffsetHeight();
		$s.pop();
		return elementRenderer;
		$s.pop();
	}
	,getLeftOffset: function(domElement,staticPosition) {
		$s.push("cocktailCore.style.positioner.BoxPositioner::getLeftOffset");
		var $spos = $s.length;
		var $tmp = domElement.getStyle().getComputedStyle().left;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getRightOffset: function(domElement,containingDOMElementWidth,staticPosition) {
		$s.push("cocktailCore.style.positioner.BoxPositioner::getRightOffset");
		var $spos = $s.length;
		var $tmp = containingDOMElementWidth - domElement.getOffsetWidth() - domElement.getStyle().getComputedStyle().right;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTopOffset: function(domElement,staticPosition) {
		$s.push("cocktailCore.style.positioner.BoxPositioner::getTopOffset");
		var $spos = $s.length;
		var $tmp = domElement.getStyle().getComputedStyle().top;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight,staticPosition) {
		$s.push("cocktailCore.style.positioner.BoxPositioner::getBottomOffset");
		var $spos = $s.length;
		var $tmp = containingDOMElementHeight - domElement.getOffsetHeight() - domElement.getStyle().getComputedStyle().bottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.positioner.BoxPositioner
}
cocktailCore.style.js.ContainerStyle = $hxClasses["cocktailCore.style.js.ContainerStyle"] = function(domElement) {
	$s.push("cocktailCore.style.js.ContainerStyle::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractContainerStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.ContainerStyle.__name__ = ["cocktailCore","style","js","ContainerStyle"];
cocktailCore.style.js.ContainerStyle.__super__ = cocktailCore.style.abstract.AbstractContainerStyle;
cocktailCore.style.js.ContainerStyle.prototype = $extend(cocktailCore.style.abstract.AbstractContainerStyle.prototype,{
	render: function(nativeElement) {
		$s.push("cocktailCore.style.js.ContainerStyle::render");
		var $spos = $s.length;
		$s.pop();
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext) {
		$s.push("cocktailCore.style.js.ContainerStyle::flowChildren");
		var $spos = $s.length;
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formattingContext,this._elementRenderer);
			}
		}
		$s.pop();
	}
	,__class__: cocktailCore.style.js.ContainerStyle
});
cocktailCore.resource.abstract.AbstractSkinLoader = $hxClasses["cocktailCore.resource.abstract.AbstractSkinLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.abstract.AbstractSkinLoader::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.skin);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractSkinLoader.__name__ = ["cocktailCore","resource","abstract","AbstractSkinLoader"];
cocktailCore.resource.abstract.AbstractSkinLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractSkinLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	__class__: cocktailCore.resource.abstract.AbstractSkinLoader
});
if(!cocktailCore.unit) cocktailCore.unit = {}
cocktailCore.unit.UnitManager = $hxClasses["cocktailCore.unit.UnitManager"] = function() {
	$s.push("cocktailCore.unit.UnitManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.unit.UnitManager.__name__ = ["cocktailCore","unit","UnitManager"];
cocktailCore.unit.UnitManager.getPixelFromLengthValue = function(length,emReference,exReference) {
	$s.push("cocktailCore.unit.UnitManager::getPixelFromLengthValue");
	var $spos = $s.length;
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
	var $tmp = Math.round(lengthValue);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.unit.UnitManager.getFontSizeFromAbsoluteSizeValue = function(absoluteSize) {
	$s.push("cocktailCore.unit.UnitManager::getFontSizeFromAbsoluteSizeValue");
	var $spos = $s.length;
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
	$s.pop();
	return fontSize;
	$s.pop();
}
cocktailCore.unit.UnitManager.getFontSizeFromRelativeSizeValue = function(relativeSize,parentFontSize) {
	$s.push("cocktailCore.unit.UnitManager::getFontSizeFromRelativeSizeValue");
	var $spos = $s.length;
	var fontSize;
	switch( (relativeSize)[1] ) {
	case 0:
		fontSize = cocktailCore.unit.UnitManager.getLargerFontSize(parentFontSize);
		break;
	case 1:
		fontSize = cocktailCore.unit.UnitManager.getSmallerFontSize(parentFontSize);
		break;
	}
	$s.pop();
	return fontSize;
	$s.pop();
}
cocktailCore.unit.UnitManager.getPixelFromPercent = function(percent,reference) {
	$s.push("cocktailCore.unit.UnitManager::getPixelFromPercent");
	var $spos = $s.length;
	var $tmp = reference * (percent * 0.01);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.unit.UnitManager.getPercentFromPixel = function(pixel,reference) {
	$s.push("cocktailCore.unit.UnitManager::getPercentFromPixel");
	var $spos = $s.length;
	var $tmp = reference / pixel * 100;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.unit.UnitManager.getColorDataFromColorValue = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getColorDataFromColorValue");
	var $spos = $s.length;
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
		colorValue = cocktailCore.unit.UnitManager.getColorDataFromColorValueKeyword(value1).color;
		alphaValue = 1.0;
		break;
	case 4:
		colorValue = 16777215;
		alphaValue = 0.0;
		break;
	}
	var colorData = { color : colorValue, alpha : alphaValue};
	$s.pop();
	return colorData;
	$s.pop();
}
cocktailCore.unit.UnitManager.getRadFromAngleValue = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getRadFromAngleValue");
	var $spos = $s.length;
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
	$s.pop();
	return angle;
	$s.pop();
}
cocktailCore.unit.UnitManager.getDegreeFromAngleValue = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getDegreeFromAngleValue");
	var $spos = $s.length;
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
	$s.pop();
	return angle;
	$s.pop();
}
cocktailCore.unit.UnitManager.getColorDataFromColorValueKeyword = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getColorDataFromColorValueKeyword");
	var $spos = $s.length;
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
	var $tmp = cocktailCore.unit.UnitManager.getColorDataFromColorValue(cocktail.unit.ColorValue.hex(hexColor));
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.unit.UnitManager.getLargerFontSize = function(parentFontSize) {
	$s.push("cocktailCore.unit.UnitManager::getLargerFontSize");
	var $spos = $s.length;
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
	$s.pop();
	return fontSize;
	$s.pop();
}
cocktailCore.unit.UnitManager.getSmallerFontSize = function(parentFontSize) {
	$s.push("cocktailCore.unit.UnitManager::getSmallerFontSize");
	var $spos = $s.length;
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
	$s.pop();
	return fontSize;
	$s.pop();
}
cocktailCore.unit.UnitManager.prototype = {
	__class__: cocktailCore.unit.UnitManager
}
cocktailCore.resource.abstract.AbstractStringLoader = $hxClasses["cocktailCore.resource.abstract.AbstractStringLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.abstract.AbstractStringLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractStringLoader.__name__ = ["cocktailCore","resource","abstract","AbstractStringLoader"];
cocktailCore.resource.abstract.AbstractStringLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractStringLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	doLoad: function(url) {
		$s.push("cocktailCore.resource.abstract.AbstractStringLoader::doLoad");
		var $spos = $s.length;
		var fileRequest = new haxe.Http(url);
		fileRequest.onData = this.onLoadComplete.$bind(this);
		fileRequest.onError = this.onLoadError.$bind(this);
		fileRequest.request(false);
		$s.pop();
	}
	,__class__: cocktailCore.resource.abstract.AbstractStringLoader
});
cocktailCore.focus.FocusManager = $hxClasses["cocktailCore.focus.FocusManager"] = function() {
	$s.push("cocktailCore.focus.FocusManager::new");
	var $spos = $s.length;
	this._focusManagerImpl = new cocktailCore.focus.js.FocusManagerImpl();
	$s.pop();
}
cocktailCore.focus.FocusManager.__name__ = ["cocktailCore","focus","FocusManager"];
cocktailCore.focus.FocusManager._instance = null;
cocktailCore.focus.FocusManager.getInstance = function() {
	$s.push("cocktailCore.focus.FocusManager::getInstance");
	var $spos = $s.length;
	if(cocktailCore.focus.FocusManager._instance == null) cocktailCore.focus.FocusManager._instance = new cocktailCore.focus.FocusManager();
	var $tmp = cocktailCore.focus.FocusManager._instance;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.focus.FocusManager.prototype = {
	bodyDOMElement: null
	,activeDOMElement: null
	,_focusManagerImpl: null
	,invalidate: function() {
		$s.push("cocktailCore.focus.FocusManager::invalidate");
		var $spos = $s.length;
		this._focusManagerImpl.invalidate();
		$s.pop();
	}
	,setActiveDOMElement: function(value) {
		$s.push("cocktailCore.focus.FocusManager::setActiveDOMElement");
		var $spos = $s.length;
		var $tmp = this._focusManagerImpl.setActiveDOMElement(value);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getActiveDOMElement: function() {
		$s.push("cocktailCore.focus.FocusManager::getActiveDOMElement");
		var $spos = $s.length;
		var $tmp = this._focusManagerImpl.getActiveDOMElement();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBodyDOMElement: function(value) {
		$s.push("cocktailCore.focus.FocusManager::setBodyDOMElement");
		var $spos = $s.length;
		var $tmp = this._focusManagerImpl.setBodyDOMElement(value);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBodyDOMElement: function() {
		$s.push("cocktailCore.focus.FocusManager::getBodyDOMElement");
		var $spos = $s.length;
		var $tmp = this._focusManagerImpl.getBodyDOMElement();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.focus.FocusManager
	,__properties__: {set_activeDOMElement:"setActiveDOMElement",get_activeDOMElement:"getActiveDOMElement",set_bodyDOMElement:"setBodyDOMElement",get_bodyDOMElement:"getBodyDOMElement"}
}
if(!cocktailCore.textElement) cocktailCore.textElement = {}
cocktailCore.textElement.TextTokenValue = $hxClasses["cocktailCore.textElement.TextTokenValue"] = { __ename__ : ["cocktailCore","textElement","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
cocktailCore.textElement.TextTokenValue.word = function(value) { var $x = ["word",0,value]; $x.__enum__ = cocktailCore.textElement.TextTokenValue; $x.toString = $estr; return $x; }
cocktailCore.textElement.TextTokenValue.space = ["space",1];
cocktailCore.textElement.TextTokenValue.space.toString = $estr;
cocktailCore.textElement.TextTokenValue.space.__enum__ = cocktailCore.textElement.TextTokenValue;
cocktailCore.textElement.TextTokenValue.tab = ["tab",2];
cocktailCore.textElement.TextTokenValue.tab.toString = $estr;
cocktailCore.textElement.TextTokenValue.tab.__enum__ = cocktailCore.textElement.TextTokenValue;
cocktailCore.textElement.TextTokenValue.lineFeed = ["lineFeed",3];
cocktailCore.textElement.TextTokenValue.lineFeed.toString = $estr;
cocktailCore.textElement.TextTokenValue.lineFeed.__enum__ = cocktailCore.textElement.TextTokenValue;
cocktailCore.style.computer.DisplayStylesComputer = $hxClasses["cocktailCore.style.computer.DisplayStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.__name__ = ["cocktailCore","style","computer","DisplayStylesComputer"];
cocktailCore.style.computer.DisplayStylesComputer.compute = function(style) {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::compute");
	var $spos = $s.length;
	var computedStyle = style.getComputedStyle();
	computedStyle.position = cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition(style);
	computedStyle.floatValue = cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle.floatValue);
	computedStyle.clear = cocktailCore.style.computer.DisplayStylesComputer.getComputedClear(style,computedStyle.position,computedStyle.display);
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition = function(style) {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::getComputedPosition");
	var $spos = $s.length;
	var $tmp = style.getPosition();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat = function(style,computedPosition) {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::getComputedFloat");
	var $spos = $s.length;
	var ret;
	if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.FloatStyleValue.none; else ret = style.getFloatValue();
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay = function(style,computedFloat) {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::getComputedDisplay");
	var $spos = $s.length;
	var ret;
	if(computedFloat != cocktail.style.FloatStyleValue.none) {
		switch( (style.getDisplay())[1] ) {
		case 2:
		case 1:
			ret = cocktail.style.DisplayStyleValue.block;
			break;
		default:
			ret = style.getDisplay();
		}
	} else ret = style.getDisplay();
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedClear = function(style,computedPosition,computedDisplay) {
	$s.push("cocktailCore.style.computer.DisplayStylesComputer::getComputedClear");
	var $spos = $s.length;
	var ret;
	if(computedDisplay == cocktail.style.DisplayStyleValue.inlineStyle || computedDisplay == cocktail.style.DisplayStyleValue.inlineBlock) ret = cocktail.style.ClearStyleValue.none; else if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.ClearStyleValue.none; else ret = style.getClear();
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.computer.DisplayStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.DisplayStylesComputer
}
cocktailCore.resource.js.SkinLoader = $hxClasses["cocktailCore.resource.js.SkinLoader"] = function() {
	$s.push("cocktailCore.resource.js.SkinLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractSkinLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.SkinLoader.__name__ = ["cocktailCore","resource","js","SkinLoader"];
cocktailCore.resource.js.SkinLoader.__super__ = cocktailCore.resource.abstract.AbstractSkinLoader;
cocktailCore.resource.js.SkinLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractSkinLoader.prototype,{
	doLoad: function(url) {
		$s.push("cocktailCore.resource.js.SkinLoader::doLoad");
		var $spos = $s.length;
		var fileRequest = new haxe.Http(url);
		fileRequest.onData = this.onLoadComplete.$bind(this);
		fileRequest.onError = this.onLoadError.$bind(this);
		fileRequest.request(false);
		$s.pop();
	}
	,onLoadComplete: function(data) {
		$s.push("cocktailCore.resource.js.SkinLoader::onLoadComplete");
		var $spos = $s.length;
		var domElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
		domElement.getNativeElement().innerHTML = data;
		this._onLoadCompleteCallback(domElement);
		$s.pop();
	}
	,__class__: cocktailCore.resource.js.SkinLoader
});
cocktailCore.style.renderer.BoxRenderer = $hxClasses["cocktailCore.style.renderer.BoxRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.BoxRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.ElementRenderer.call(this,domElement);
	this._backgroundManager = new cocktailCore.background.BackgroundManager();
	$s.pop();
}
cocktailCore.style.renderer.BoxRenderer.__name__ = ["cocktailCore","style","renderer","BoxRenderer"];
cocktailCore.style.renderer.BoxRenderer.__super__ = cocktailCore.style.renderer.ElementRenderer;
cocktailCore.style.renderer.BoxRenderer.prototype = $extend(cocktailCore.style.renderer.ElementRenderer.prototype,{
	_backgroundManager: null
	,render: function() {
		$s.push("cocktailCore.style.renderer.BoxRenderer::render");
		var $spos = $s.length;
		var $tmp = [];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,renderBackground: function() {
		$s.push("cocktailCore.style.renderer.BoxRenderer::renderBackground");
		var $spos = $s.length;
		var $tmp = this._backgroundManager.render(this._bounds,this._domElement.getStyle());
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.BoxRenderer
});
cocktailCore.style.renderer.EmbeddedBoxRenderer = $hxClasses["cocktailCore.style.renderer.EmbeddedBoxRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.EmbeddedBoxRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.BoxRenderer.call(this,domElement);
	$s.pop();
}
cocktailCore.style.renderer.EmbeddedBoxRenderer.__name__ = ["cocktailCore","style","renderer","EmbeddedBoxRenderer"];
cocktailCore.style.renderer.EmbeddedBoxRenderer.__super__ = cocktailCore.style.renderer.BoxRenderer;
cocktailCore.style.renderer.EmbeddedBoxRenderer.prototype = $extend(cocktailCore.style.renderer.BoxRenderer.prototype,{
	render: function() {
		$s.push("cocktailCore.style.renderer.EmbeddedBoxRenderer::render");
		var $spos = $s.length;
		var ret = [];
		var embeddedDOMElement = this._domElement;
		ret.push(embeddedDOMElement.getEmbeddedAsset());
		this._domElement.getStyle().setNativeOpacity(this._domElement.getStyle().getComputedStyle().opacity);
		this._domElement.getStyle().setNativeVisibility(this._domElement.getStyle().getComputedStyle().visibility);
		$s.pop();
		return ret;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.EmbeddedBoxRenderer
});
if(!org.intermedia.model) org.intermedia.model = {}
org.intermedia.model.ThumbTextListRss = $hxClasses["org.intermedia.model.ThumbTextListRss"] = function() { }
org.intermedia.model.ThumbTextListRss.__name__ = ["org","intermedia","model","ThumbTextListRss"];
org.intermedia.model.ThumbTextListRss.rss2Cells = function(rss) {
	$s.push("org.intermedia.model.ThumbTextListRss::rss2Cells");
	var $spos = $s.length;
	var cells = new Array();
	var channelNode = rss.firstElement().firstElement();
	var $it0 = channelNode.elements();
	while( $it0.hasNext() ) {
		var channelChild = $it0.next();
		if(channelChild.getNodeName() == "item") {
			var cell = { id : 0, title : "", author : "", thumbUrl : "", category : ""};
			var $it1 = channelChild.elements();
			while( $it1.hasNext() ) {
				var itemParam = $it1.next();
				if(itemParam.getNodeName() == "post_thumbnail") cell.thumbUrl = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "post_images") {
					if(!Reflect.hasField(cell,"thumbnail") || Reflect.field(cell,"thumbnail") == "") {
						var $it2 = itemParam.elements();
						while( $it2.hasNext() ) {
							var elements = $it2.next();
							cell.thumbUrl = itemParam.firstElement().firstChild().getNodeValue();
							break;
						}
					}
				}
				if(itemParam.getNodeName() == "title") {
					var title = itemParam.firstChild().getNodeValue();
					var index = title.indexOf("Name");
					if(index != -1) title = title.substr(0,index);
					title = StringTools.rtrim(title);
					cell.title = title;
				}
				if(itemParam.getNodeName() == "dc:creator") cell.author = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "guid") {
					var index = itemParam.firstChild().getNodeValue().indexOf("p=") + 2;
					cell.id = Std.parseInt(itemParam.firstChild().getNodeValue().substr(index));
				}
				if(itemParam.getNodeName() == "category") cell.category = itemParam.firstChild().getNodeValue();
			}
			cells.push(cell);
		}
	}
	$s.pop();
	return cells;
	$s.pop();
}
org.intermedia.model.ThumbTextListRss.prototype = {
	__class__: org.intermedia.model.ThumbTextListRss
}
var js = js || {}
js.Boot = $hxClasses["js.Boot"] = function() { }
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
	msg += js.Boot.__string_rec(v,"");
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML += js.Boot.__unhtml(msg) + "<br/>"; else if(typeof(console) != "undefined" && console.log != null) console.log(msg);
	$s.pop();
}
js.Boot.__clear_trace = function() {
	$s.push("js.Boot::__clear_trace");
	var $spos = $s.length;
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML = "";
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
		$s.push("js.Boot::__init@187");
		var $spos = $s.length;
		this.splice(i,0,x);
		$s.pop();
	};
	Array.prototype.remove = Array.prototype.indexOf?function(obj) {
		$s.push("js.Boot::__init@190");
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
		$s.push("js.Boot::__init@195");
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
		$s.push("js.Boot::__init@207");
		var $spos = $s.length;
		var $tmp = { cur : 0, arr : this, hasNext : function() {
			$s.push("js.Boot::__init@207@211");
			var $spos = $s.length;
			var $tmp = this.cur < this.arr.length;
			$s.pop();
			return $tmp;
			$s.pop();
		}, next : function() {
			$s.push("js.Boot::__init@207@214");
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
		$s.push("js.Boot::__init@221");
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
		$s.push("js.Boot::__init@228");
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
	Function.prototype["$bind"] = function(o) {
		$s.push("js.Boot::__init@239");
		var $spos = $s.length;
		var f = function() {
			$s.push("js.Boot::__init@239@240");
			var $spos = $s.length;
			var $tmp = f.method.apply(f.scope,arguments);
			$s.pop();
			return $tmp;
			$s.pop();
		};
		f.scope = o;
		f.method = this;
		$s.pop();
		return f;
		$s.pop();
	};
	$s.pop();
}
js.Boot.prototype = {
	__class__: js.Boot
}
org.intermedia.Application = $hxClasses["org.intermedia.Application"] = function() {
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
org.intermedia.Application.prototype = {
	__class__: org.intermedia.Application
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement"] = function(nativeElement,style) {
	$s.push("cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	this._style = style;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractTextFragmentDOMElement"];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype = $extend(cocktailCore.domElement.js.DOMElement.prototype,{
	initStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement::initStyle");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement
});
cocktailCore.style.computer.FontAndTextStylesComputer = $hxClasses["cocktailCore.style.computer.FontAndTextStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.__name__ = ["cocktailCore","style","computer","FontAndTextStylesComputer"];
cocktailCore.style.computer.FontAndTextStylesComputer.compute = function(style,containingDOMElementData,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::compute");
	var $spos = $s.length;
	var computedStyle = style.getComputedStyle();
	if(containingDOMElementFontMetricsData != null) computedStyle.fontSize = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,containingDOMElementFontMetricsData.fontSize,containingDOMElementFontMetricsData.xHeight); else computedStyle.fontSize = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,12.0,10.0);
	computedStyle.lineHeight = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLineHeight(style);
	computedStyle.verticalAlign = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign(style,containingDOMElementData,containingDOMElementFontMetricsData);
	computedStyle.fontWeight = style.getFontWeight();
	computedStyle.fontStyle = style.getFontStyle();
	computedStyle.fontFamily = style.getFontFamily();
	computedStyle.fontVariant = style.getFontVariant();
	computedStyle.textTransform = style.getTextTransform();
	computedStyle.letterSpacing = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing(style);
	computedStyle.wordSpacing = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedWordSpacing(style);
	computedStyle.textIndent = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextIndent(style,containingDOMElementData);
	computedStyle.whiteSpace = style.getWhiteSpace();
	computedStyle.textAlign = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextAlign(style,computedStyle.whiteSpace);
	computedStyle.color = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedColor(style);
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextIndent = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedTextIndent");
	var $spos = $s.length;
	var textIndent;
	var $e = (style.getTextIndent());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		textIndent = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		textIndent = cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementData.width);
		break;
	}
	var $tmp = Math.round(textIndent);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingDOMElementData,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedVerticalAlign");
	var $spos = $s.length;
	var verticalAlign;
	var $e = (style.getVerticalAlign());
	switch( $e[1] ) {
	case 0:
		verticalAlign = 0;
		break;
	case 5:
		verticalAlign = style.getDOMElement().getOffsetHeight() / 2 + containingDOMElementFontMetricsData.xHeight / 2;
		break;
	case 1:
		verticalAlign = containingDOMElementFontMetricsData.subscriptOffset;
		break;
	case 2:
		verticalAlign = containingDOMElementFontMetricsData.superscriptOffset;
		break;
	case 4:
		verticalAlign = 0;
		break;
	case 7:
		verticalAlign = 0;
		break;
	case 8:
		var value = $e[2];
		verticalAlign = cocktailCore.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().lineHeight));
		break;
	case 9:
		var value = $e[2];
		verticalAlign = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 3:
		verticalAlign = 0;
		break;
	case 6:
		verticalAlign = 0;
		break;
	}
	$s.pop();
	return verticalAlign;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextAlign = function(style,computedWhiteSpace) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedTextAlign");
	var $spos = $s.length;
	var textAlign = style.getTextAlign();
	switch( (computedWhiteSpace)[1] ) {
	case 1:
		if(style.getTextAlign() == cocktail.style.TextAlignStyleValue.justify) textAlign = cocktail.style.TextAlignStyleValue.left;
		break;
	default:
	}
	$s.pop();
	return textAlign;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedColor = function(style) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedColor");
	var $spos = $s.length;
	var $tmp = cocktailCore.unit.UnitManager.getColorDataFromColorValue(style.getColor());
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedWordSpacing = function(style) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedWordSpacing");
	var $spos = $s.length;
	var wordSpacing;
	var $e = (style.getWordSpacing());
	switch( $e[1] ) {
	case 0:
		wordSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		wordSpacing = Math.round(cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	$s.pop();
	return wordSpacing;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLineHeight = function(style) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedLineHeight");
	var $spos = $s.length;
	var lineHeight;
	var $e = (style.getLineHeight());
	switch( $e[1] ) {
	case 2:
		var unit = $e[2];
		lineHeight = cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,style.getComputedStyle().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 0:
		lineHeight = style.getComputedStyle().fontSize * 1.2;
		break;
	case 3:
		var value = $e[2];
		lineHeight = cocktailCore.unit.UnitManager.getPixelFromPercent(value,Math.round(style.getComputedStyle().fontSize));
		break;
	case 1:
		var value = $e[2];
		lineHeight = style.getComputedStyle().fontSize * value;
		break;
	}
	$s.pop();
	return lineHeight;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing = function(style) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedLetterSpacing");
	var $spos = $s.length;
	var letterSpacing;
	var $e = (style.getLetterSpacing());
	switch( $e[1] ) {
	case 0:
		letterSpacing = 0;
		break;
	case 1:
		var unit = $e[2];
		letterSpacing = Math.round(cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight));
		break;
	}
	$s.pop();
	return letterSpacing;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize = function(style,parentFontSize,parentXHeight) {
	$s.push("cocktailCore.style.computer.FontAndTextStylesComputer::getComputedFontSize");
	var $spos = $s.length;
	var fontSize;
	var $e = (style.getFontSize());
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		fontSize = cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,parentFontSize,parentXHeight);
		break;
	case 1:
		var percent = $e[2];
		fontSize = cocktailCore.unit.UnitManager.getPixelFromPercent(percent,Math.round(parentFontSize));
		break;
	case 2:
		var value = $e[2];
		fontSize = cocktailCore.unit.UnitManager.getFontSizeFromAbsoluteSizeValue(value);
		break;
	case 3:
		var value = $e[2];
		fontSize = cocktailCore.unit.UnitManager.getFontSizeFromRelativeSizeValue(value,parentFontSize);
		break;
	}
	$s.pop();
	return fontSize;
	$s.pop();
}
cocktailCore.style.computer.FontAndTextStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.FontAndTextStylesComputer
}
org.intermedia.view.DetailStyle = $hxClasses["org.intermedia.view.DetailStyle"] = function() { }
org.intermedia.view.DetailStyle.__name__ = ["org","intermedia","view","DetailStyle"];
org.intermedia.view.DetailStyle.setDefault = function(domElement) {
	$s.push("org.intermedia.view.DetailStyle::setDefault");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(43)));
	$s.pop();
}
org.intermedia.view.DetailStyle.setThumbnail = function(domElement) {
	$s.push("org.intermedia.view.DetailStyle::setThumbnail");
	var $spos = $s.length;
	var imageMaxWidth = 250;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(imageMaxWidth)));
	domElement.getStyle().setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(50));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(80));
	$s.pop();
}
org.intermedia.view.DetailStyle.setText = function(domElement) {
	$s.push("org.intermedia.view.DetailStyle::setText");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#202020"));
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Arial"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	$s.pop();
}
org.intermedia.view.DetailStyle.setTitle = function(domElement,screenResolutionSize) {
	$s.push("org.intermedia.view.DetailStyle::setTitle");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(domElement);
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	$s.pop();
}
org.intermedia.view.DetailStyle.setAuthor = function(domElement,screenResolutionSize) {
	$s.push("org.intermedia.view.DetailStyle::setAuthor");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(domElement);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.normal);
	$s.pop();
}
org.intermedia.view.DetailStyle.setDescription = function(domElement) {
	$s.push("org.intermedia.view.DetailStyle::setDescription");
	var $spos = $s.length;
	org.intermedia.view.DetailStyle.setText(domElement);
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	$s.pop();
}
org.intermedia.view.DetailStyle.prototype = {
	__class__: org.intermedia.view.DetailStyle
}
if(!cocktailCore.focus.js) cocktailCore.focus.js = {}
cocktailCore.focus.js.FocusManagerImpl = $hxClasses["cocktailCore.focus.js.FocusManagerImpl"] = function() {
	$s.push("cocktailCore.focus.js.FocusManagerImpl::new");
	var $spos = $s.length;
	cocktailCore.focus.abstract.AbstractFocusManagerImpl.call(this);
	$s.pop();
}
cocktailCore.focus.js.FocusManagerImpl.__name__ = ["cocktailCore","focus","js","FocusManagerImpl"];
cocktailCore.focus.js.FocusManagerImpl.__super__ = cocktailCore.focus.abstract.AbstractFocusManagerImpl;
cocktailCore.focus.js.FocusManagerImpl.prototype = $extend(cocktailCore.focus.abstract.AbstractFocusManagerImpl.prototype,{
	initKeyboardListeners: function() {
		$s.push("cocktailCore.focus.js.FocusManagerImpl::initKeyboardListeners");
		var $spos = $s.length;
		$s.pop();
	}
	,setActiveDOMElement: function(value) {
		$s.push("cocktailCore.focus.js.FocusManagerImpl::setActiveDOMElement");
		var $spos = $s.length;
		var $tmp = this._activeDOMElement = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setBodyDOMElement: function(value) {
		$s.push("cocktailCore.focus.js.FocusManagerImpl::setBodyDOMElement");
		var $spos = $s.length;
		var $tmp = this._bodyDOMElement = value;
		$s.pop();
		return $tmp;
		$s.pop();
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
js.Lib.prototype = {
	__class__: js.Lib
}
org.intermedia.view.CellTextStyle = $hxClasses["org.intermedia.view.CellTextStyle"] = function() { }
org.intermedia.view.CellTextStyle.__name__ = ["org","intermedia","view","CellTextStyle"];
org.intermedia.view.CellTextStyle.setCellStyle = function(domElement) {
	$s.push("org.intermedia.view.CellTextStyle::setCellStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(5)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	$s.pop();
}
org.intermedia.view.CellTextStyle.setCellTextStyle = function(domElement) {
	$s.push("org.intermedia.view.CellTextStyle::setCellTextStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setFontVariant(cocktail.style.FontVariantStyleValue.normal);
	domElement.getStyle().setTextTransform(cocktail.style.TextTransformStyleValue.none);
	domElement.getStyle().setLetterSpacing(cocktail.style.LetterSpacingStyleValue.normal);
	domElement.getStyle().setWordSpacing(cocktail.style.WordSpacingStyleValue.normal);
	domElement.getStyle().setTextIndent(cocktail.style.TextIndentStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWhiteSpace(cocktail.style.WhiteSpaceStyleValue.normal);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.left);
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#666666"));
	$s.pop();
}
org.intermedia.view.CellTextStyle.setCellLineStyle = function(domElement) {
	$s.push("org.intermedia.view.CellTextStyle::setCellLineStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(1)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(5)));
	$s.pop();
}
org.intermedia.view.CellTextStyle.prototype = {
	__class__: org.intermedia.view.CellTextStyle
}
cocktailCore.domElement.js.ImageDOMElement = $hxClasses["cocktailCore.domElement.js.ImageDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.js.ImageDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.call(this,nativeElement);
	this._nativeElement = this._embeddedAsset;
	$s.pop();
}
cocktailCore.domElement.js.ImageDOMElement.__name__ = ["cocktailCore","domElement","js","ImageDOMElement"];
cocktailCore.domElement.js.ImageDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
cocktailCore.domElement.js.ImageDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.ImageDOMElement
});
cocktailCore.style.positioner.RelativePositioner = $hxClasses["cocktailCore.style.positioner.RelativePositioner"] = function() {
	$s.push("cocktailCore.style.positioner.RelativePositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.RelativePositioner.__name__ = ["cocktailCore","style","positioner","RelativePositioner"];
cocktailCore.style.positioner.RelativePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.RelativePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	getLeftOffset: function(domElement,staticPosition) {
		$s.push("cocktailCore.style.positioner.RelativePositioner::getLeftOffset");
		var $spos = $s.length;
		var $tmp = staticPosition + domElement.getStyle().getComputedStyle().left;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getRightOffset: function(domElement,containingDOMElementWidth,staticPosition) {
		$s.push("cocktailCore.style.positioner.RelativePositioner::getRightOffset");
		var $spos = $s.length;
		var $tmp = staticPosition + containingDOMElementWidth - domElement.getOffsetWidth() - domElement.getStyle().getComputedStyle().right;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getTopOffset: function(domElement,staticPosition) {
		$s.push("cocktailCore.style.positioner.RelativePositioner::getTopOffset");
		var $spos = $s.length;
		var $tmp = staticPosition + domElement.getStyle().getComputedStyle().top;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight,staticPosition) {
		$s.push("cocktailCore.style.positioner.RelativePositioner::getBottomOffset");
		var $spos = $s.length;
		var $tmp = staticPosition + containingDOMElementHeight - domElement.getOffsetHeight() - domElement.getStyle().getComputedStyle().bottom;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.positioner.RelativePositioner
});
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = $hxClasses["cocktailCore.textElement.abstract.AbstractTextElement"] = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::new");
	var $spos = $s.length;
	this._textFragments = new Array();
	this.setText(text);
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.__name__ = ["cocktailCore","textElement","abstract","AbstractTextElement"];
cocktailCore.textElement.abstract.AbstractTextElement.applyTextTransform = function(text,textTransform) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::applyTextTransform");
	var $spos = $s.length;
	switch( (textTransform)[1] ) {
	case 1:
		text = text.toUpperCase();
		break;
	case 2:
		text = text.toLowerCase();
		break;
	case 0:
		text = cocktailCore.textElement.abstract.AbstractTextElement.capitalizeText(text);
		break;
	case 3:
		break;
	}
	$s.pop();
	return text;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.capitalizeText = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::capitalizeText");
	var $spos = $s.length;
	var capitalizedText = text.charAt(0);
	var _g1 = 1, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
	}
	$s.pop();
	return capitalizedText;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::doGetTextFragments");
	var $spos = $s.length;
	var textFragments = new Array();
	var textFragment = "";
	var i = 0;
	while(i < text.length) {
		if(text.charAt(i) == "\\") {
			if(i < text.length - 1) {
				if(text.charAt(i + 1) == "n") {
					if(textFragment != null) {
						textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.lineFeed));
					i++;
				} else if(text.charAt(i + 1) == "t") {
					if(textFragment != null) {
						textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.word(textFragment)));
						textFragment = null;
					}
					textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.tab));
					i++;
				}
			}
		}
		if(StringTools.isSpace(text,i) == true) {
			if(textFragment != null) {
				textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.word(textFragment)));
				textFragment = null;
			}
			textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.space));
		} else {
			if(textFragment == null) textFragment = "";
			textFragment += text.charAt(i);
		}
		i++;
	}
	if(textFragment != null) textFragments.push(cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken(cocktailCore.textElement.TextTokenValue.word(textFragment)));
	$s.pop();
	return textFragments;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken = function(textToken) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::insertTextToken");
	var $spos = $s.length;
	var $tmp = { textToken : textToken, textFragmentDOMElement : null};
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype = {
	_text: null
	,text: null
	,_nativeText: null
	,nativeText: null
	,_textFragments: null
	,_parent: null
	,parent: null
	,reset: function() {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::reset");
		var $spos = $s.length;
		var _g1 = 0, _g = this._textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._textFragments[i].textFragmentDOMElement = null;
		}
		$s.pop();
	}
	,getTextFragments: function(text) {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getTextFragments");
		var $spos = $s.length;
		if(this._textFragments.length == 0) this._textFragments = cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments(text);
		var $tmp = this._textFragments;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setText: function(value) {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::setText");
		var $spos = $s.length;
		var $tmp = this._text = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getText: function() {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getText");
		var $spos = $s.length;
		var $tmp = this._text;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getNativeText: function() {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getNativeText");
		var $spos = $s.length;
		var $tmp = this._nativeText;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setParent: function(value) {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::setParent");
		var $spos = $s.length;
		var $tmp = this._parent = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getParent: function() {
		$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getParent");
		var $spos = $s.length;
		var $tmp = this._parent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.textElement.abstract.AbstractTextElement
	,__properties__: {set_parent:"setParent",get_parent:"getParent",get_nativeText:"getNativeText",set_text:"setText",get_text:"getText"}
}
if(!cocktailCore.textElement.js) cocktailCore.textElement.js = {}
cocktailCore.textElement.js.TextElement = $hxClasses["cocktailCore.textElement.js.TextElement"] = function(text) {
	$s.push("cocktailCore.textElement.js.TextElement::new");
	var $spos = $s.length;
	this._nativeText = js.Lib.document.createTextNode(text);
	cocktailCore.textElement.abstract.AbstractTextElement.call(this,text);
	$s.pop();
}
cocktailCore.textElement.js.TextElement.__name__ = ["cocktailCore","textElement","js","TextElement"];
cocktailCore.textElement.js.TextElement.__super__ = cocktailCore.textElement.abstract.AbstractTextElement;
cocktailCore.textElement.js.TextElement.prototype = $extend(cocktailCore.textElement.abstract.AbstractTextElement.prototype,{
	setText: function(value) {
		$s.push("cocktailCore.textElement.js.TextElement::setText");
		var $spos = $s.length;
		this._text = value;
		this._nativeText.nodeValue = value;
		$s.pop();
		return value;
		$s.pop();
	}
	,__class__: cocktailCore.textElement.js.TextElement
});
var cocktail = cocktail || {}
if(!cocktail.keyboard) cocktail.keyboard = {}
cocktail.keyboard.KeyboardKeyValue = $hxClasses["cocktail.keyboard.KeyboardKeyValue"] = { __ename__ : ["cocktail","keyboard","KeyboardKeyValue"], __constructs__ : ["unknown","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","backSpace","capsLock","control","del","down","end","escape","enter","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","F13","F14","F15","home","insert","left","numpad0","numpad1","numpad2","numpad3","numpad4","numpad5","numpad6","numpad7","numpad8","numpad9","numpadAdd","numpadSpecial","numpadDecimal","numpadDivide","numpadEnter","numpadMultiply","numpadSubstract","pageDown","pageUp","right","shift","space","tab","up"] }
cocktail.keyboard.KeyboardKeyValue.unknown = ["unknown",0];
cocktail.keyboard.KeyboardKeyValue.unknown.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.unknown.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.a = ["a",1];
cocktail.keyboard.KeyboardKeyValue.a.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.a.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.b = ["b",2];
cocktail.keyboard.KeyboardKeyValue.b.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.b.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.c = ["c",3];
cocktail.keyboard.KeyboardKeyValue.c.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.c.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.d = ["d",4];
cocktail.keyboard.KeyboardKeyValue.d.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.d.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.e = ["e",5];
cocktail.keyboard.KeyboardKeyValue.e.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.e.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.f = ["f",6];
cocktail.keyboard.KeyboardKeyValue.f.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.f.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.g = ["g",7];
cocktail.keyboard.KeyboardKeyValue.g.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.g.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.h = ["h",8];
cocktail.keyboard.KeyboardKeyValue.h.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.h.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.i = ["i",9];
cocktail.keyboard.KeyboardKeyValue.i.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.i.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.j = ["j",10];
cocktail.keyboard.KeyboardKeyValue.j.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.j.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.k = ["k",11];
cocktail.keyboard.KeyboardKeyValue.k.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.k.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.l = ["l",12];
cocktail.keyboard.KeyboardKeyValue.l.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.l.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.m = ["m",13];
cocktail.keyboard.KeyboardKeyValue.m.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.m.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.n = ["n",14];
cocktail.keyboard.KeyboardKeyValue.n.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.n.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.o = ["o",15];
cocktail.keyboard.KeyboardKeyValue.o.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.o.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.p = ["p",16];
cocktail.keyboard.KeyboardKeyValue.p.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.p.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.q = ["q",17];
cocktail.keyboard.KeyboardKeyValue.q.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.q.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.r = ["r",18];
cocktail.keyboard.KeyboardKeyValue.r.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.r.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.s = ["s",19];
cocktail.keyboard.KeyboardKeyValue.s.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.s.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.t = ["t",20];
cocktail.keyboard.KeyboardKeyValue.t.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.t.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.u = ["u",21];
cocktail.keyboard.KeyboardKeyValue.u.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.u.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.v = ["v",22];
cocktail.keyboard.KeyboardKeyValue.v.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.v.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.w = ["w",23];
cocktail.keyboard.KeyboardKeyValue.w.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.w.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.x = ["x",24];
cocktail.keyboard.KeyboardKeyValue.x.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.x.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.y = ["y",25];
cocktail.keyboard.KeyboardKeyValue.y.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.y.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.z = ["z",26];
cocktail.keyboard.KeyboardKeyValue.z.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.z.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.backSpace = ["backSpace",27];
cocktail.keyboard.KeyboardKeyValue.backSpace.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.backSpace.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.capsLock = ["capsLock",28];
cocktail.keyboard.KeyboardKeyValue.capsLock.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.capsLock.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.control = ["control",29];
cocktail.keyboard.KeyboardKeyValue.control.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.control.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.del = ["del",30];
cocktail.keyboard.KeyboardKeyValue.del.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.del.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.down = ["down",31];
cocktail.keyboard.KeyboardKeyValue.down.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.down.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.end = ["end",32];
cocktail.keyboard.KeyboardKeyValue.end.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.end.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.escape = ["escape",33];
cocktail.keyboard.KeyboardKeyValue.escape.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.escape.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.enter = ["enter",34];
cocktail.keyboard.KeyboardKeyValue.enter.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.enter.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F1 = ["F1",35];
cocktail.keyboard.KeyboardKeyValue.F1.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F1.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F2 = ["F2",36];
cocktail.keyboard.KeyboardKeyValue.F2.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F2.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F3 = ["F3",37];
cocktail.keyboard.KeyboardKeyValue.F3.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F3.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F4 = ["F4",38];
cocktail.keyboard.KeyboardKeyValue.F4.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F4.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F5 = ["F5",39];
cocktail.keyboard.KeyboardKeyValue.F5.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F5.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F6 = ["F6",40];
cocktail.keyboard.KeyboardKeyValue.F6.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F6.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F7 = ["F7",41];
cocktail.keyboard.KeyboardKeyValue.F7.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F7.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F8 = ["F8",42];
cocktail.keyboard.KeyboardKeyValue.F8.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F8.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F9 = ["F9",43];
cocktail.keyboard.KeyboardKeyValue.F9.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F9.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F10 = ["F10",44];
cocktail.keyboard.KeyboardKeyValue.F10.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F10.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F11 = ["F11",45];
cocktail.keyboard.KeyboardKeyValue.F11.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F11.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F12 = ["F12",46];
cocktail.keyboard.KeyboardKeyValue.F12.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F12.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F13 = ["F13",47];
cocktail.keyboard.KeyboardKeyValue.F13.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F13.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F14 = ["F14",48];
cocktail.keyboard.KeyboardKeyValue.F14.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F14.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.F15 = ["F15",49];
cocktail.keyboard.KeyboardKeyValue.F15.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.F15.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.home = ["home",50];
cocktail.keyboard.KeyboardKeyValue.home.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.home.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.insert = ["insert",51];
cocktail.keyboard.KeyboardKeyValue.insert.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.insert.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.left = ["left",52];
cocktail.keyboard.KeyboardKeyValue.left.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.left.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad0 = ["numpad0",53];
cocktail.keyboard.KeyboardKeyValue.numpad0.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad0.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad1 = ["numpad1",54];
cocktail.keyboard.KeyboardKeyValue.numpad1.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad1.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad2 = ["numpad2",55];
cocktail.keyboard.KeyboardKeyValue.numpad2.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad2.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad3 = ["numpad3",56];
cocktail.keyboard.KeyboardKeyValue.numpad3.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad3.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad4 = ["numpad4",57];
cocktail.keyboard.KeyboardKeyValue.numpad4.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad4.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad5 = ["numpad5",58];
cocktail.keyboard.KeyboardKeyValue.numpad5.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad5.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad6 = ["numpad6",59];
cocktail.keyboard.KeyboardKeyValue.numpad6.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad6.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad7 = ["numpad7",60];
cocktail.keyboard.KeyboardKeyValue.numpad7.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad7.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad8 = ["numpad8",61];
cocktail.keyboard.KeyboardKeyValue.numpad8.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad8.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpad9 = ["numpad9",62];
cocktail.keyboard.KeyboardKeyValue.numpad9.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpad9.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadAdd = ["numpadAdd",63];
cocktail.keyboard.KeyboardKeyValue.numpadAdd.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadAdd.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadSpecial = ["numpadSpecial",64];
cocktail.keyboard.KeyboardKeyValue.numpadSpecial.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadSpecial.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadDecimal = ["numpadDecimal",65];
cocktail.keyboard.KeyboardKeyValue.numpadDecimal.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadDecimal.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadDivide = ["numpadDivide",66];
cocktail.keyboard.KeyboardKeyValue.numpadDivide.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadDivide.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadEnter = ["numpadEnter",67];
cocktail.keyboard.KeyboardKeyValue.numpadEnter.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadEnter.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadMultiply = ["numpadMultiply",68];
cocktail.keyboard.KeyboardKeyValue.numpadMultiply.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadMultiply.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.numpadSubstract = ["numpadSubstract",69];
cocktail.keyboard.KeyboardKeyValue.numpadSubstract.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.numpadSubstract.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.pageDown = ["pageDown",70];
cocktail.keyboard.KeyboardKeyValue.pageDown.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.pageDown.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.pageUp = ["pageUp",71];
cocktail.keyboard.KeyboardKeyValue.pageUp.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.pageUp.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.right = ["right",72];
cocktail.keyboard.KeyboardKeyValue.right.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.right.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.shift = ["shift",73];
cocktail.keyboard.KeyboardKeyValue.shift.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.shift.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.space = ["space",74];
cocktail.keyboard.KeyboardKeyValue.space.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.space.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.tab = ["tab",75];
cocktail.keyboard.KeyboardKeyValue.tab.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.tab.__enum__ = cocktail.keyboard.KeyboardKeyValue;
cocktail.keyboard.KeyboardKeyValue.up = ["up",76];
cocktail.keyboard.KeyboardKeyValue.up.toString = $estr;
cocktail.keyboard.KeyboardKeyValue.up.__enum__ = cocktail.keyboard.KeyboardKeyValue;
var Reflect = $hxClasses["Reflect"] = function() { }
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
Reflect.getProperty = function(o,field) {
	$s.push("Reflect::getProperty");
	var $spos = $s.length;
	var tmp;
	var $tmp = o == null?null:o.__properties__ && (tmp = o.__properties__["get_" + field])?o[tmp]():o[field];
	$s.pop();
	return $tmp;
	$s.pop();
}
Reflect.setProperty = function(o,field,value) {
	$s.push("Reflect::setProperty");
	var $spos = $s.length;
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
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
		$s.push("Reflect::makeVarArgs@118");
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
Reflect.prototype = {
	__class__: Reflect
}
org.intermedia.view.ThumbTextList1 = $hxClasses["org.intermedia.view.ThumbTextList1"] = function(cellPerLine) {
	$s.push("org.intermedia.view.ThumbTextList1::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	this._cellsPerLine = cellPerLine;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.ListViewStyle.setListStyle(this);
	$s.pop();
}
org.intermedia.view.ThumbTextList1.__name__ = ["org","intermedia","view","ThumbTextList1"];
org.intermedia.view.ThumbTextList1.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ThumbTextList1.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_cellsPerLine: null
	,createCell: function() {
		$s.push("org.intermedia.view.ThumbTextList1::createCell");
		var $spos = $s.length;
		var cell = new org.intermedia.view.CellThumbText1(this._cellsPerLine);
		$s.pop();
		return cell;
		$s.pop();
	}
	,__class__: org.intermedia.view.ThumbTextList1
});
org.intermedia.view.ThumbTextList1Bis = $hxClasses["org.intermedia.view.ThumbTextList1Bis"] = function(cellPerLine) {
	$s.push("org.intermedia.view.ThumbTextList1Bis::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.ThumbTextList1.call(this,cellPerLine);
	$s.pop();
}
org.intermedia.view.ThumbTextList1Bis.__name__ = ["org","intermedia","view","ThumbTextList1Bis"];
org.intermedia.view.ThumbTextList1Bis.__super__ = org.intermedia.view.ThumbTextList1;
org.intermedia.view.ThumbTextList1Bis.prototype = $extend(org.intermedia.view.ThumbTextList1.prototype,{
	__class__: org.intermedia.view.ThumbTextList1Bis
});
if(!cocktail.mouse) cocktail.mouse = {}
cocktail.mouse.MouseCursorValue = $hxClasses["cocktail.mouse.MouseCursorValue"] = { __ename__ : ["cocktail","mouse","MouseCursorValue"], __constructs__ : ["custom","autoValue","none","native"] }
cocktail.mouse.MouseCursorValue.custom = function(imageDOMElement,hotSpot) { var $x = ["custom",0,imageDOMElement,hotSpot]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.MouseCursorValue.autoValue = ["autoValue",1];
cocktail.mouse.MouseCursorValue.autoValue.toString = $estr;
cocktail.mouse.MouseCursorValue.autoValue.__enum__ = cocktail.mouse.MouseCursorValue;
cocktail.mouse.MouseCursorValue.none = ["none",2];
cocktail.mouse.MouseCursorValue.none.toString = $estr;
cocktail.mouse.MouseCursorValue.none.__enum__ = cocktail.mouse.MouseCursorValue;
cocktail.mouse.MouseCursorValue["native"] = function(nativeOSMouseCursorValue) { var $x = ["native",3,nativeOSMouseCursorValue]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.NativeOSMouseCursorValue = $hxClasses["cocktail.mouse.NativeOSMouseCursorValue"] = { __ename__ : ["cocktail","mouse","NativeOSMouseCursorValue"], __constructs__ : ["pointer","text"] }
cocktail.mouse.NativeOSMouseCursorValue.pointer = ["pointer",0];
cocktail.mouse.NativeOSMouseCursorValue.pointer.toString = $estr;
cocktail.mouse.NativeOSMouseCursorValue.pointer.__enum__ = cocktail.mouse.NativeOSMouseCursorValue;
cocktail.mouse.NativeOSMouseCursorValue.text = ["text",1];
cocktail.mouse.NativeOSMouseCursorValue.text.toString = $estr;
cocktail.mouse.NativeOSMouseCursorValue.text.__enum__ = cocktail.mouse.NativeOSMouseCursorValue;
if(!cocktail.geom) cocktail.geom = {}
cocktail.geom.Matrix = $hxClasses["cocktail.geom.Matrix"] = function(data) {
	$s.push("cocktail.geom.Matrix::new");
	var $spos = $s.length;
	this.setData(data);
	$s.pop();
}
cocktail.geom.Matrix.__name__ = ["cocktail","geom","Matrix"];
cocktail.geom.Matrix.prototype = {
	_data: null
	,data: null
	,identity: function() {
		$s.push("cocktail.geom.Matrix::identity");
		var $spos = $s.length;
		this._data = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : 0.0, f : 0.0};
		$s.pop();
	}
	,setData: function(data) {
		$s.push("cocktail.geom.Matrix::setData");
		var $spos = $s.length;
		this._data = data;
		if(this._data == null) this.identity();
		var $tmp = this._data;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getData: function() {
		$s.push("cocktail.geom.Matrix::getData");
		var $spos = $s.length;
		var $tmp = this._data;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,concatenate: function(matrix) {
		$s.push("cocktail.geom.Matrix::concatenate");
		var $spos = $s.length;
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
		$s.pop();
	}
	,translate: function(x,y) {
		$s.push("cocktail.geom.Matrix::translate");
		var $spos = $s.length;
		var translationMatrixData = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : x, f : y};
		var translationMatrix = new cocktail.geom.Matrix(translationMatrixData);
		this.concatenate(translationMatrix);
		$s.pop();
	}
	,rotate: function(angle,registrationPoint) {
		$s.push("cocktail.geom.Matrix::rotate");
		var $spos = $s.length;
		var rotatedMatrix = new cocktail.geom.Matrix();
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
		var rotationMatrix = new cocktail.geom.Matrix(rotationMatrixData);
		rotatedMatrix.concatenate(rotationMatrix);
		rotatedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(rotatedMatrix);
		$s.pop();
	}
	,scale: function(scaleX,scaleY,registrationPoint) {
		$s.push("cocktail.geom.Matrix::scale");
		var $spos = $s.length;
		var scaledMatrix = new cocktail.geom.Matrix();
		scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
		var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
		var scalingMatrix = new cocktail.geom.Matrix(scalingMatrixData);
		scaledMatrix.concatenate(scalingMatrix);
		scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(scaledMatrix);
		$s.pop();
	}
	,skew: function(skewX,skewY,registrationPoint) {
		$s.push("cocktail.geom.Matrix::skew");
		var $spos = $s.length;
		var skewedMatrix = new cocktail.geom.Matrix();
		skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
		var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
		var skewingMatrix = new cocktail.geom.Matrix(skewingMatrixData);
		skewedMatrix.concatenate(skewingMatrix);
		skewedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(skewedMatrix);
		$s.pop();
	}
	,setRotation: function(angle,registrationPoint) {
		$s.push("cocktail.geom.Matrix::setRotation");
		var $spos = $s.length;
		var currentRotation = this.getRotation();
		var resetAngle = Math.PI * 2 - currentRotation;
		this.rotate(resetAngle,registrationPoint);
		this.rotate(angle,registrationPoint);
		$s.pop();
	}
	,getRotation: function() {
		$s.push("cocktail.geom.Matrix::getRotation");
		var $spos = $s.length;
		var flip = this.getFlip();
		var scaleX = this.getScaleX();
		var skewX = this.getSkewX();
		var actualScaleX = Math.sqrt(scaleX * scaleX + skewX * skewX);
		var scaleY = this.getScaleY();
		var skewY = this.getSkewY() * flip;
		var actualScaleY = Math.sqrt(scaleY * scaleY + skewY * skewY);
		var rotationInRad = Math.atan2(skewY / actualScaleY - skewX / actualScaleX,scaleY / actualScaleY + scaleX / actualScaleX);
		if(rotationInRad < 0) rotationInRad = Math.PI + rotationInRad;
		$s.pop();
		return rotationInRad;
		$s.pop();
	}
	,getFlip: function() {
		$s.push("cocktail.geom.Matrix::getFlip");
		var $spos = $s.length;
		var scaleX = this.getScaleX();
		var scaleXSign = 0;
		if(scaleX >= 0) scaleXSign = 1; else scaleXSign = -1;
		var scaleY = this.getScaleY();
		var scaleYSign = scaleY >= 0?1:-1;
		var skewX = this.getSkewX();
		var skewXSign = skewX >= 0?1:-1;
		var skewY = this.getSkewY();
		var skewYSign = skewY >= 0?1:-1;
		if(scaleXSign == scaleYSign && skewXSign == skewYSign * -1) {
			$s.pop();
			return 1;
		}
		if(scaleXSign == scaleYSign * -1 && skewXSign == skewYSign) {
			$s.pop();
			return -1;
		}
		$s.pop();
		return 1;
		$s.pop();
	}
	,setScaleX: function(scaleXFactor,registrationPoint) {
		$s.push("cocktail.geom.Matrix::setScaleX");
		var $spos = $s.length;
		var currentScaleX = this.getScaleX();
		var resetScaleX = 1 / currentScaleX;
		this.scale(resetScaleX,1,registrationPoint);
		this.scale(scaleXFactor,1,registrationPoint);
		$s.pop();
	}
	,getScaleX: function() {
		$s.push("cocktail.geom.Matrix::getScaleX");
		var $spos = $s.length;
		var $tmp = this._data.a;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setScaleY: function(scaleYFactor,registrationPoint) {
		$s.push("cocktail.geom.Matrix::setScaleY");
		var $spos = $s.length;
		var currentScaleY = this.getScaleY();
		var resetScaleY = 1 / currentScaleY;
		this.scale(1,resetScaleY,registrationPoint);
		this.scale(1,scaleYFactor,registrationPoint);
		$s.pop();
	}
	,getScaleY: function() {
		$s.push("cocktail.geom.Matrix::getScaleY");
		var $spos = $s.length;
		var $tmp = this._data.d;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTranslationX: function(translationX) {
		$s.push("cocktail.geom.Matrix::setTranslationX");
		var $spos = $s.length;
		var currentTranslationX = this.getTranslationX();
		var resetTranslationX = currentTranslationX * -1;
		this.translate(resetTranslationX,0);
		this.translate(translationX,0);
		$s.pop();
	}
	,getTranslationX: function() {
		$s.push("cocktail.geom.Matrix::getTranslationX");
		var $spos = $s.length;
		var $tmp = this._data.e;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setTranslationY: function(translationY) {
		$s.push("cocktail.geom.Matrix::setTranslationY");
		var $spos = $s.length;
		var currentTranslationY = this.getTranslationY();
		var resetTranslationY = currentTranslationY * -1;
		this.translate(0,resetTranslationY);
		this.translate(0,translationY);
		$s.pop();
	}
	,getTranslationY: function() {
		$s.push("cocktail.geom.Matrix::getTranslationY");
		var $spos = $s.length;
		var $tmp = this._data.f;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getSkewX: function() {
		$s.push("cocktail.geom.Matrix::getSkewX");
		var $spos = $s.length;
		var $tmp = this._data.c;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getSkewY: function() {
		$s.push("cocktail.geom.Matrix::getSkewY");
		var $spos = $s.length;
		var $tmp = this._data.b;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktail.geom.Matrix
	,__properties__: {set_data:"setData",get_data:"getData"}
}
cocktailCore.style.positioner.AbsolutePositioner = $hxClasses["cocktailCore.style.positioner.AbsolutePositioner"] = function() {
	$s.push("cocktailCore.style.positioner.AbsolutePositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.AbsolutePositioner.__name__ = ["cocktailCore","style","positioner","AbsolutePositioner"];
cocktailCore.style.positioner.AbsolutePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.AbsolutePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	__class__: cocktailCore.style.positioner.AbsolutePositioner
});
org.intermedia.view.CellThumbText1 = $hxClasses["org.intermedia.view.CellThumbText1"] = function(cellPerLine) {
	$s.push("org.intermedia.view.CellThumbText1::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this);
	this.initCellStyle();
	this._cellStyle.cell(this,cellPerLine);
	$s.pop();
}
org.intermedia.view.CellThumbText1.__name__ = ["org","intermedia","view","CellThumbText1"];
org.intermedia.view.CellThumbText1.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumbText1.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_cellStyle: null
	,initCellStyle: function() {
		$s.push("org.intermedia.view.CellThumbText1::initCellStyle");
		var $spos = $s.length;
		this._cellStyle = { cell : org.intermedia.view.CellThumbText1Style.setCellStyle, thumbnail : org.intermedia.view.CellThumbText1Style.setThumbnailStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
		$s.pop();
	}
	,updateView: function() {
		$s.push("org.intermedia.view.CellThumbText1::updateView");
		var $spos = $s.length;
		var cellData = this._data;
		if(cellData.thumbUrl != "" && cellData.thumbUrl != null) {
			var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
			this._cellStyle.thumbnail(cellImage);
			this.addChild(cellImage);
			cellImage.load(cellData.thumbUrl);
		}
		var cellTextBlockContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		this._cellStyle.textBlock(cellTextBlockContainer);
		this.addChild(cellTextBlockContainer);
		if(cellData.title != "" && cellData.title != null) {
			var cellTitleContainer = new cocktailCore.domElement.js.ContainerDOMElement();
			var textElement = new cocktailCore.textElement.js.TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			this._cellStyle.title(cellTitleContainer);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		if(cellData.author != "" && cellData.author != null) {
			var cellAuthorContainer = new cocktailCore.domElement.js.ContainerDOMElement();
			var textElement = new cocktailCore.textElement.js.TextElement(cellData.author);
			cellAuthorContainer.addText(textElement);
			this._cellStyle.author(cellAuthorContainer);
			cellTextBlockContainer.addChild(cellAuthorContainer);
		}
		var line = new cocktailCore.domElement.js.ImageDOMElement();
		this._cellStyle.line(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");
		$s.pop();
	}
	,__class__: org.intermedia.view.CellThumbText1
});
if(!cocktailCore.nativeElement) cocktailCore.nativeElement = {}
if(!cocktailCore.nativeElement["abstract"]) cocktailCore.nativeElement["abstract"] = {}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager"] = function() {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementPathManager"];
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype = {
	getRoot: function() {
		$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager::getRoot");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager
}
if(!cocktailCore.nativeElement.js) cocktailCore.nativeElement.js = {}
cocktailCore.nativeElement.js.NativeElementPathManager = $hxClasses["cocktailCore.nativeElement.js.NativeElementPathManager"] = function() {
	$s.push("cocktailCore.nativeElement.js.NativeElementPathManager::new");
	var $spos = $s.length;
	cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.call(this);
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementPathManager.__name__ = ["cocktailCore","nativeElement","js","NativeElementPathManager"];
cocktailCore.nativeElement.js.NativeElementPathManager.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
cocktailCore.nativeElement.js.NativeElementPathManager.prototype = $extend(cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype,{
	getRoot: function() {
		$s.push("cocktailCore.nativeElement.js.NativeElementPathManager::getRoot");
		var $spos = $s.length;
		var $tmp = js.Lib.document.body;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.nativeElement.js.NativeElementPathManager
});
cocktailCore.style.renderer.FlowBoxRenderer = $hxClasses["cocktailCore.style.renderer.FlowBoxRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.FlowBoxRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.BoxRenderer.call(this,domElement);
	this._children = new Array();
	this._lineBoxes = new Array();
	$s.pop();
}
cocktailCore.style.renderer.FlowBoxRenderer.__name__ = ["cocktailCore","style","renderer","FlowBoxRenderer"];
cocktailCore.style.renderer.FlowBoxRenderer.__super__ = cocktailCore.style.renderer.BoxRenderer;
cocktailCore.style.renderer.FlowBoxRenderer.prototype = $extend(cocktailCore.style.renderer.BoxRenderer.prototype,{
	_children: null
	,children: null
	,_lineBoxes: null
	,lineBoxes: null
	,addChild: function(elementRenderer) {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::addChild");
		var $spos = $s.length;
		this._children.push(elementRenderer);
		elementRenderer.setParent(this);
		$s.pop();
	}
	,addLineBox: function(lineBoxElements) {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::addLineBox");
		var $spos = $s.length;
		this._lineBoxes.push(lineBoxElements);
		$s.pop();
	}
	,removeLineBoxes: function() {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::removeLineBoxes");
		var $spos = $s.length;
		this._lineBoxes = new Array();
		$s.pop();
	}
	,removeChild: function(elementRenderer) {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::removeChild");
		var $spos = $s.length;
		this._children.remove(elementRenderer);
		$s.pop();
	}
	,canHaveChildren: function() {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::canHaveChildren");
		var $spos = $s.length;
		$s.pop();
		return true;
		$s.pop();
	}
	,getChildren: function() {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::getChildren");
		var $spos = $s.length;
		var $tmp = this._children;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getLineBoxes: function() {
		$s.push("cocktailCore.style.renderer.FlowBoxRenderer::getLineBoxes");
		var $spos = $s.length;
		var $tmp = this._lineBoxes;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.FlowBoxRenderer
	,__properties__: $extend(cocktailCore.style.renderer.BoxRenderer.prototype.__properties__,{get_lineBoxes:"getLineBoxes",get_children:"getChildren"})
});
cocktailCore.style.renderer.BlockBoxRenderer = $hxClasses["cocktailCore.style.renderer.BlockBoxRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.BlockBoxRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.FlowBoxRenderer.call(this,domElement);
	$s.pop();
}
cocktailCore.style.renderer.BlockBoxRenderer.__name__ = ["cocktailCore","style","renderer","BlockBoxRenderer"];
cocktailCore.style.renderer.BlockBoxRenderer.__super__ = cocktailCore.style.renderer.FlowBoxRenderer;
cocktailCore.style.renderer.BlockBoxRenderer.prototype = $extend(cocktailCore.style.renderer.FlowBoxRenderer.prototype,{
	__class__: cocktailCore.style.renderer.BlockBoxRenderer
});
cocktailCore.style.renderer.InitialBlockRenderer = $hxClasses["cocktailCore.style.renderer.InitialBlockRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.InitialBlockRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.BlockBoxRenderer.call(this,domElement);
	$s.pop();
}
cocktailCore.style.renderer.InitialBlockRenderer.__name__ = ["cocktailCore","style","renderer","InitialBlockRenderer"];
cocktailCore.style.renderer.InitialBlockRenderer.__super__ = cocktailCore.style.renderer.BlockBoxRenderer;
cocktailCore.style.renderer.InitialBlockRenderer.prototype = $extend(cocktailCore.style.renderer.BlockBoxRenderer.prototype,{
	renderBackground: function() {
		$s.push("cocktailCore.style.renderer.InitialBlockRenderer::renderBackground");
		var $spos = $s.length;
		var viewport = new cocktailCore.viewport.js.Viewport();
		var width = viewport._getWidth();
		var height = viewport._getHeight();
		var viewportBounds = { x : 0.0, y : 0.0, width : width, height : height};
		var $tmp = this._backgroundManager.render(viewportBounds,this._domElement.getStyle());
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.InitialBlockRenderer
});
cocktailCore.style.abstract.AbstractEmbeddedStyle = $hxClasses["cocktailCore.style.abstract.AbstractEmbeddedStyle"] = function(domElement) {
	$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::new");
	var $spos = $s.length;
	cocktailCore.style.js.Style.call(this,domElement);
	$s.pop();
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.__name__ = ["cocktailCore","style","abstract","AbstractEmbeddedStyle"];
cocktailCore.style.abstract.AbstractEmbeddedStyle.__super__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype = $extend(cocktailCore.style.js.Style.prototype,{
	createElementRenderer: function(parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::createElementRenderer");
		var $spos = $s.length;
		var elementRenderer = new cocktailCore.style.renderer.EmbeddedBoxRenderer(this._domElement);
		elementRenderer.setLayerRenderer(this.getLayerRenderer(elementRenderer,parentElementRenderer));
		elementRenderer.getBounds().width = this._computedStyle.width;
		elementRenderer.getBounds().height = this._computedStyle.height;
		parentElementRenderer.addChild(elementRenderer);
		$s.pop();
		return elementRenderer;
		$s.pop();
	}
	,getBoxStylesComputer: function() {
		$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::getBoxStylesComputer");
		var $spos = $s.length;
		var boxComputer;
		if(this.isFloat() == true) boxComputer = new cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer(); else if(this.isPositioned() == true && this.isRelativePositioned() == false) boxComputer = new cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer();
		switch( (this._computedStyle.display)[1] ) {
		case 0:
			boxComputer = new cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer();
			break;
		case 1:
			boxComputer = new cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer();
			break;
		case 3:
			boxComputer = new cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer();
			break;
		case 2:
			boxComputer = new cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer();
			break;
		}
		$s.pop();
		return boxComputer;
		$s.pop();
	}
	,isEmbedded: function() {
		$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::isEmbedded");
		var $spos = $s.length;
		$s.pop();
		return true;
		$s.pop();
	}
	,__class__: cocktailCore.style.abstract.AbstractEmbeddedStyle
});
cocktailCore.style.js.EmbeddedStyle = $hxClasses["cocktailCore.style.js.EmbeddedStyle"] = function(domElement) {
	$s.push("cocktailCore.style.js.EmbeddedStyle::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractEmbeddedStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.EmbeddedStyle.__name__ = ["cocktailCore","style","js","EmbeddedStyle"];
cocktailCore.style.js.EmbeddedStyle.__super__ = cocktailCore.style.abstract.AbstractEmbeddedStyle;
cocktailCore.style.js.EmbeddedStyle.prototype = $extend(cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype,{
	__class__: cocktailCore.style.js.EmbeddedStyle
});
if(!cocktail.viewport) cocktail.viewport = {}
cocktail.viewport.OrientationValue = $hxClasses["cocktail.viewport.OrientationValue"] = { __ename__ : ["cocktail","viewport","OrientationValue"], __constructs__ : ["vertical","horizontal"] }
cocktail.viewport.OrientationValue.vertical = ["vertical",0];
cocktail.viewport.OrientationValue.vertical.toString = $estr;
cocktail.viewport.OrientationValue.vertical.__enum__ = cocktail.viewport.OrientationValue;
cocktail.viewport.OrientationValue.horizontal = ["horizontal",1];
cocktail.viewport.OrientationValue.horizontal.toString = $estr;
cocktail.viewport.OrientationValue.horizontal.__enum__ = cocktail.viewport.OrientationValue;
cocktailCore.domElement.abstract.AbstractBodyDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractBodyDOMElement"] = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.getRoot());
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractBodyDOMElement"];
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype = $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype,{
	_viewPort: null
	,initStyle: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::initStyle");
		var $spos = $s.length;
		this._style = new cocktailCore.style.js.BodyStyle(this);
		this._viewPort = new cocktailCore.viewport.js.Viewport();
		this._viewPort._setOnResize(this.onViewPortResize.$bind(this));
		$s.pop();
	}
	,initFocus: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::initFocus");
		var $spos = $s.length;
		cocktailCore.focus.FocusManager.getInstance().setBodyDOMElement(this);
		cocktailCore.domElement.js.ContainerDOMElement.prototype.initFocus.call(this);
		$s.pop();
	}
	,onViewPortResize: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::onViewPortResize");
		var $spos = $s.length;
		this._style.invalidate();
		$s.pop();
	}
	,setX: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::setX");
		var $spos = $s.length;
		$s.pop();
		return value;
		$s.pop();
	}
	,setY: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::setY");
		var $spos = $s.length;
		$s.pop();
		return value;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::setWidth");
		var $spos = $s.length;
		$s.pop();
		return value;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::setHeight");
		var $spos = $s.length;
		$s.pop();
		return value;
		$s.pop();
	}
	,setIsVisible: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractBodyDOMElement::setIsVisible");
		var $spos = $s.length;
		$s.pop();
		return value;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractBodyDOMElement
});
org.intermedia.view.HeaderStyle = $hxClasses["org.intermedia.view.HeaderStyle"] = function() { }
org.intermedia.view.HeaderStyle.__name__ = ["org","intermedia","view","HeaderStyle"];
org.intermedia.view.HeaderStyle.setHeaderStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
	domElement.getStyle().setBackgroundImage([cocktail.style.BackgroundImageStyleValue.image(cocktail.unit.ImageValue.url("assets/headerGrey.jpg"))]);
	$s.pop();
}
org.intermedia.view.HeaderStyle.setHeaderStaticStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderStaticStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
	$s.pop();
}
org.intermedia.view.HeaderStyle.setHeaderTextStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setHeaderTextStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#454545"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("HelveticaNeue"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(6)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonTextStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonTextStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Arial"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(30)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	$s.pop();
}
org.intermedia.view.HeaderStyle.setBackButtonImageStyle = function(domElement) {
	$s.push("org.intermedia.view.HeaderStyle::setBackButtonImageStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	$s.pop();
}
org.intermedia.view.HeaderStyle.prototype = {
	__class__: org.intermedia.view.HeaderStyle
}
cocktailCore.domElement.js.TextFragmentDOMElement = $hxClasses["cocktailCore.domElement.js.TextFragmentDOMElement"] = function(nativeElement,style) {
	$s.push("cocktailCore.domElement.js.TextFragmentDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
	$s.pop();
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
cocktailCore.domElement.js.TextFragmentDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.TextFragmentDOMElement
});
cocktailCore.resource.js.ImageLoader = $hxClasses["cocktailCore.resource.js.ImageLoader"] = function(nativeElement) {
	$s.push("cocktailCore.resource.js.ImageLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractImageLoader.call(this,nativeElement);
	$s.pop();
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractImageLoader;
cocktailCore.resource.js.ImageLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractImageLoader.prototype,{
	__class__: cocktailCore.resource.js.ImageLoader
});
if(!cocktailCore.drawing) cocktailCore.drawing = {}
if(!cocktailCore.drawing["abstract"]) cocktailCore.drawing["abstract"] = {}
cocktailCore.drawing.abstract.AbstractDrawingManager = $hxClasses["cocktailCore.drawing.abstract.AbstractDrawingManager"] = function(nativeElement,width,height) {
	$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::new");
	var $spos = $s.length;
	this._nativeElement = nativeElement;
	this._width = width;
	this._height = height;
	$s.pop();
}
cocktailCore.drawing.abstract.AbstractDrawingManager.__name__ = ["cocktailCore","drawing","abstract","AbstractDrawingManager"];
cocktailCore.drawing.abstract.AbstractDrawingManager.prototype = {
	_nativeElement: null
	,nativeElement: null
	,_width: null
	,width: null
	,_height: null
	,height: null
	,beginFill: function(fillStyle,lineStyle) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::beginFill");
		var $spos = $s.length;
		if(fillStyle == null) fillStyle = cocktail.domElement.FillStyleValue.none;
		if(lineStyle == null) lineStyle = cocktail.domElement.LineStyleValue.none;
		this.setFillStyle(fillStyle);
		this.setLineStyle(lineStyle);
		$s.pop();
	}
	,endFill: function() {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::endFill");
		var $spos = $s.length;
		$s.pop();
	}
	,clear: function() {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::clear");
		var $spos = $s.length;
		$s.pop();
	}
	,setLineStyle: function(lineStyle) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::setLineStyle");
		var $spos = $s.length;
		$s.pop();
	}
	,setFillStyle: function(fillStyle) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::setFillStyle");
		var $spos = $s.length;
		$s.pop();
	}
	,drawRect: function(x,y,width,height,cornerRadiuses) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::drawRect");
		var $spos = $s.length;
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
		$s.pop();
	}
	,drawEllipse: function(x,y,width,height) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::drawEllipse");
		var $spos = $s.length;
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
		$s.pop();
	}
	,drawImage: function(source,matrix,sourceRect) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::drawImage");
		var $spos = $s.length;
		$s.pop();
	}
	,lineTo: function(x,y) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::lineTo");
		var $spos = $s.length;
		$s.pop();
	}
	,moveTo: function(x,y) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::moveTo");
		var $spos = $s.length;
		$s.pop();
	}
	,curveTo: function(controlX,controlY,x,y) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::curveTo");
		var $spos = $s.length;
		$s.pop();
	}
	,toNativeAlpha: function(genericAlpa) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::toNativeAlpha");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,toNativeColor: function(genericColor) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::toNativeColor");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,toNativeRatio: function(genericRatio) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::toNativeRatio");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,toNativeCapStyle: function(genericCapStyle) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::toNativeCapStyle");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,toNativeJointStyle: function(genericJointStyle) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::toNativeJointStyle");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,getNativeElement: function() {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::getNativeElement");
		var $spos = $s.length;
		var $tmp = this._nativeElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::setWidth");
		var $spos = $s.length;
		var $tmp = this._width = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getWidth: function() {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::getWidth");
		var $spos = $s.length;
		var $tmp = this._width;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::setHeight");
		var $spos = $s.length;
		var $tmp = this._height = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getHeight: function() {
		$s.push("cocktailCore.drawing.abstract.AbstractDrawingManager::getHeight");
		var $spos = $s.length;
		var $tmp = this._height;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.drawing.abstract.AbstractDrawingManager
	,__properties__: {set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",get_nativeElement:"getNativeElement"}
}
cocktailCore.style.renderer.LayerRenderer = $hxClasses["cocktailCore.style.renderer.LayerRenderer"] = function(rootRenderer) {
	$s.push("cocktailCore.style.renderer.LayerRenderer::new");
	var $spos = $s.length;
	this._rootRenderer = rootRenderer;
	$s.pop();
}
cocktailCore.style.renderer.LayerRenderer.__name__ = ["cocktailCore","style","renderer","LayerRenderer"];
cocktailCore.style.renderer.LayerRenderer.prototype = {
	_rootRenderer: null
	,render: function(nativeElement) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::render");
		var $spos = $s.length;
		var ret = new Array();
		if(this._rootRenderer.canHaveChildren() == true && this._rootRenderer.getDOMElement().getStyle().isInlineLevel() == false) {
			ret = this._rootRenderer.renderBackground();
			var d = this.renderChildLayer(nativeElement);
			var _g1 = 0, _g = d.length;
			while(_g1 < _g) {
				var i = _g1++;
				ret.push(d[i]);
			}
			var c = this.renderInFlowChildren(nativeElement);
			var _g1 = 0, _g = c.length;
			while(_g1 < _g) {
				var i = _g1++;
				ret.push(c[i]);
			}
			var bg = this.renderChildrenBlockContainerBackground(nativeElement);
			var _g1 = 0, _g = bg.length;
			while(_g1 < _g) {
				var i = _g1++;
				ret.push(bg[i]);
			}
		} else {
			ret = this._rootRenderer.renderBackground();
			var e = this._rootRenderer.render();
			var _g1 = 0, _g = e.length;
			while(_g1 < _g) {
				var i = _g1++;
				ret.push(e[i]);
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,renderChildrenBlockContainerBackground: function(nativeElement) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::renderChildrenBlockContainerBackground");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,renderChildLayer: function(nativeElement) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::renderChildLayer");
		var $spos = $s.length;
		var childLayers = this.getChildLayers(this._rootRenderer,this);
		var ret = new Array();
		var _g1 = 0, _g = childLayers.length;
		while(_g1 < _g) {
			var i = _g1++;
			var nativeElements = childLayers[i].render(nativeElement);
			var _g3 = 0, _g2 = nativeElements.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(nativeElements[j]);
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getChildLayers: function(rootRenderer,referenceLayer) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::getChildLayers");
		var $spos = $s.length;
		var ret = new Array();
		var _g1 = 0, _g = rootRenderer.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(rootRenderer.getChildren()[i].getLayerRenderer() == referenceLayer) {
				if(rootRenderer.getChildren()[i].canHaveChildren() == true) {
					var childElementRenderer = this.getChildLayers(rootRenderer.getChildren()[i],referenceLayer);
					var _g3 = 0, _g2 = childElementRenderer.length;
					while(_g3 < _g2) {
						var j = _g3++;
						ret.push(childElementRenderer[j]);
					}
				}
			} else ret.push(rootRenderer.getChildren()[i].getLayerRenderer());
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,renderInFlowChildren: function(nativeElement) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::renderInFlowChildren");
		var $spos = $s.length;
		var inFlowChildren = this.getInFlowChildren(this._rootRenderer);
		var ret = new Array();
		var _g1 = 0, _g = inFlowChildren.length;
		while(_g1 < _g) {
			var i = _g1++;
			var nativeElements = inFlowChildren[i].render();
			var _g3 = 0, _g2 = nativeElements.length;
			while(_g3 < _g2) {
				var j = _g3++;
				ret.push(nativeElements[j]);
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getInFlowChildren: function(rootRenderer) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::getInFlowChildren");
		var $spos = $s.length;
		var ret = new Array();
		var _g1 = 0, _g = rootRenderer.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(rootRenderer.getChildren()[i].getLayerRenderer() == this) {
				if(rootRenderer.getDOMElement().getStyle().establishesNewFormattingContext() == true && rootRenderer.getDOMElement().getStyle().childrenInline() == true) {
					var _g3 = 0, _g2 = rootRenderer.getLineBoxes().length;
					while(_g3 < _g2) {
						var j = _g3++;
						var _g5 = 0, _g4 = rootRenderer.getLineBoxes()[j].length;
						while(_g5 < _g4) {
							var k = _g5++;
							ret.push(rootRenderer.getLineBoxes()[j][k]);
						}
					}
				} else if(rootRenderer.getChildren()[i].getDOMElement().getStyle().isInFlow() == true) {
					if(rootRenderer.getChildren()[i].canHaveChildren() == true) {
						var childElementRenderer = this.getInFlowChildren(rootRenderer.getChildren()[i]);
						var _g3 = 0, _g2 = childElementRenderer.length;
						while(_g3 < _g2) {
							var j = _g3++;
							ret.push(childElementRenderer[j]);
						}
					}
					ret.push(rootRenderer.getChildren()[i]);
				}
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getBlockContainerChildren: function(rootRenderer) {
		$s.push("cocktailCore.style.renderer.LayerRenderer::getBlockContainerChildren");
		var $spos = $s.length;
		var ret = new Array();
		var _g1 = 0, _g = rootRenderer.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(rootRenderer.getChildren()[i].getLayerRenderer() == this) {
				if(rootRenderer.getChildren()[i].canHaveChildren() == true) {
					var childElementRenderer = this.getBlockContainerChildren(rootRenderer.getChildren()[i]);
					var _g3 = 0, _g2 = childElementRenderer.length;
					while(_g3 < _g2) {
						var j = _g3++;
						ret.push(childElementRenderer[j]);
					}
					ret.push(rootRenderer.getChildren()[i]);
				}
			}
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.LayerRenderer
}
cocktailCore.style.computer.BackgroundStylesComputer = $hxClasses["cocktailCore.style.computer.BackgroundStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.__name__ = ["cocktailCore","style","computer","BackgroundStylesComputer"];
cocktailCore.style.computer.BackgroundStylesComputer.compute = function(style) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::compute");
	var $spos = $s.length;
	style.getComputedStyle().backgroundColor = cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundColor(style);
	style.getComputedStyle().backgroundRepeat = style.getBackgroundRepeat();
	style.getComputedStyle().backgroundClip = style.getBackgroundClip();
	style.getComputedStyle().backgroundSize = style.getBackgroundSize();
	style.getComputedStyle().backgroundPosition = style.getBackgroundPosition();
	style.getComputedStyle().backgroundOrigin = style.getBackgroundOrigin();
	style.getComputedStyle().backgroundImage = style.getBackgroundImage();
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.computeIndividualBackground = function(style,backgroundBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::computeIndividualBackground");
	var $spos = $s.length;
	var backgroundPositioningArea = cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea(style,backgroundOrigin,backgroundBox);
	var computedBackgroundSize = cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundSize(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundPosition = cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	var computedBackgroundClip = cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea(style,backgroundClip,backgroundBox);
	var computedBackgroundStyle = { backgroundOrigin : backgroundPositioningArea, backgroundClip : computedBackgroundClip, backgroundRepeat : backgroundRepeat, backgroundImage : backgroundImage, backgroundSize : computedBackgroundSize, backgroundPosition : computedBackgroundPosition};
	$s.pop();
	return computedBackgroundStyle;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundColor = function(style) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getComputedBackgroundColor");
	var $spos = $s.length;
	var computedColor;
	var $e = (style.getBackgroundColor());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedColor = cocktailCore.unit.UnitManager.getColorDataFromColorValue(value);
		break;
	}
	$s.pop();
	return computedColor;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundPosition = function(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,emReference,exReference) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getComputedBackgroundPosition");
	var $spos = $s.length;
	var computedBackgroundXPosition = cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition(backgroundPosition.x,Math.round(backgroundPositioningArea.width),computedBackgroundSize.width,emReference,exReference);
	var computedBackgroundYPosition = cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition(backgroundPosition.y,Math.round(backgroundPositioningArea.height),computedBackgroundSize.height,emReference,exReference);
	var computedBackgroundPosition = { x : computedBackgroundXPosition, y : computedBackgroundYPosition};
	$s.pop();
	return computedBackgroundPosition;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundXPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getComputedBackgroundXPosition");
	var $spos = $s.length;
	var computedBackgroundXPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundXPosition = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundXPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundXPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundXPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundXPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	$s.pop();
	return computedBackgroundXPosition;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundYPosition = function(backgroundPosition,backgroundPositioningAreaDimension,imageDimension,emReference,exReference) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getComputedBackgroundYPosition");
	var $spos = $s.length;
	var computedBackgroundYPosition;
	var $e = (backgroundPosition);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedBackgroundYPosition = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,emReference,exReference);
		break;
	case 1:
		var value = $e[2];
		computedBackgroundYPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 3:
		computedBackgroundYPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(50,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 2:
		computedBackgroundYPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(0,backgroundPositioningAreaDimension - imageDimension));
		break;
	case 4:
		computedBackgroundYPosition = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension - imageDimension));
		break;
	}
	$s.pop();
	return computedBackgroundYPosition;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getComputedBackgroundSize = function(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getComputedBackgroundSize");
	var $spos = $s.length;
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
		computedBackgroundSize = { width : cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.x,value.y,Math.round(backgroundPositioningArea.width),Math.round(backgroundPositioningArea.height),intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference), height : cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(value.y,value.x,Math.round(backgroundPositioningArea.height),Math.round(backgroundPositioningArea.width),intrinsicHeight,intrinsicWidth,intrinsicRatio,emReference,exReference)};
		break;
	}
	$s.pop();
	return computedBackgroundSize;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData = function(value,opositeBackgroundSizeStyleDimensionValue,backgroundPositioningAreaDimension,opositeBackgroundAreaDimension,intrinsicDimension,opositeIntrinsicDimension,intrinsicRatio,emReference,exReference) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getBackgroundSizeStyleDimensionData");
	var $spos = $s.length;
	var backgroundSizeStyleDimension;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		backgroundSizeStyleDimension = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value1,emReference,exReference);
		break;
	case 1:
		var value1 = $e[2];
		backgroundSizeStyleDimension = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value1,backgroundPositioningAreaDimension));
		break;
	case 2:
		if(intrinsicDimension != null && opositeBackgroundSizeStyleDimensionValue == cocktail.style.BackgroundSizeStyleDimensionValue.autoValue) backgroundSizeStyleDimension = intrinsicDimension; else if(opositeIntrinsicDimension != null && intrinsicRatio != null) {
			var opositeDimension = cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundSizeStyleDimensionData(opositeBackgroundSizeStyleDimensionValue,value,opositeBackgroundAreaDimension,backgroundPositioningAreaDimension,opositeIntrinsicDimension,intrinsicDimension,intrinsicRatio,emReference,exReference);
			backgroundSizeStyleDimension = Math.round(opositeDimension * intrinsicRatio);
		} else backgroundSizeStyleDimension = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(100,backgroundPositioningAreaDimension));
		break;
	}
	$s.pop();
	return backgroundSizeStyleDimension;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundPositioningArea = function(style,backgroundOrigin,backgroundBox) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getBackgroundPositioningArea");
	var $spos = $s.length;
	var backgroundPositioningArea;
	var height;
	var width;
	var x;
	var y;
	switch( (backgroundOrigin)[1] ) {
	case 0:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
		x = style.getComputedStyle().marginLeft;
		y = style.getComputedStyle().marginTop;
		break;
	case 1:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
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
	$s.pop();
	return backgroundPositioningArea;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.getBackgroundPaintingArea = function(style,backgroundClip,backgroundBox) {
	$s.push("cocktailCore.style.computer.BackgroundStylesComputer::getBackgroundPaintingArea");
	var $spos = $s.length;
	var backgroundPaintingArea;
	var height;
	var width;
	var x;
	var y;
	switch( (backgroundClip)[1] ) {
	case 0:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
		x = style.getComputedStyle().marginLeft;
		y = style.getComputedStyle().marginTop;
		break;
	case 1:
		height = backgroundBox.height - style.getComputedStyle().marginTop - style.getComputedStyle().marginBottom;
		width = backgroundBox.width - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
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
	$s.pop();
	return backgroundPaintingArea;
	$s.pop();
}
cocktailCore.style.computer.BackgroundStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.BackgroundStylesComputer
}
if(!cocktail.nativeElement) cocktail.nativeElement = {}
cocktail.nativeElement.NativeElementTypeValue = $hxClasses["cocktail.nativeElement.NativeElementTypeValue"] = { __ename__ : ["cocktail","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","library","skin","link","textInput","custom"] }
cocktail.nativeElement.NativeElementTypeValue.neutral = ["neutral",0];
cocktail.nativeElement.NativeElementTypeValue.neutral.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.neutral.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.graphic = ["graphic",1];
cocktail.nativeElement.NativeElementTypeValue.graphic.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.graphic.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.text = ["text",2];
cocktail.nativeElement.NativeElementTypeValue.text.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.text.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.image = ["image",3];
cocktail.nativeElement.NativeElementTypeValue.image.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.image.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.library = ["library",4];
cocktail.nativeElement.NativeElementTypeValue.library.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.library.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.skin = ["skin",5];
cocktail.nativeElement.NativeElementTypeValue.skin.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.skin.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.link = ["link",6];
cocktail.nativeElement.NativeElementTypeValue.link.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.link.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.textInput = ["textInput",7];
cocktail.nativeElement.NativeElementTypeValue.textInput.toString = $estr;
cocktail.nativeElement.NativeElementTypeValue.textInput.__enum__ = cocktail.nativeElement.NativeElementTypeValue;
cocktail.nativeElement.NativeElementTypeValue.custom = function(name) { var $x = ["custom",8,name]; $x.__enum__ = cocktail.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
cocktailCore.domElement.TextTokenValue = $hxClasses["cocktailCore.domElement.TextTokenValue"] = { __ename__ : ["cocktailCore","domElement","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
cocktailCore.domElement.TextTokenValue.word = function(value) { var $x = ["word",0,value]; $x.__enum__ = cocktailCore.domElement.TextTokenValue; $x.toString = $estr; return $x; }
cocktailCore.domElement.TextTokenValue.space = ["space",1];
cocktailCore.domElement.TextTokenValue.space.toString = $estr;
cocktailCore.domElement.TextTokenValue.space.__enum__ = cocktailCore.domElement.TextTokenValue;
cocktailCore.domElement.TextTokenValue.tab = ["tab",2];
cocktailCore.domElement.TextTokenValue.tab.toString = $estr;
cocktailCore.domElement.TextTokenValue.tab.__enum__ = cocktailCore.domElement.TextTokenValue;
cocktailCore.domElement.TextTokenValue.lineFeed = ["lineFeed",3];
cocktailCore.domElement.TextTokenValue.lineFeed.toString = $estr;
cocktailCore.domElement.TextTokenValue.lineFeed.__enum__ = cocktailCore.domElement.TextTokenValue;
cocktailCore.domElement.ContainerDOMElementChildValue = $hxClasses["cocktailCore.domElement.ContainerDOMElementChildValue"] = { __ename__ : ["cocktailCore","domElement","ContainerDOMElementChildValue"], __constructs__ : ["domElement","textElement"] }
cocktailCore.domElement.ContainerDOMElementChildValue.domElement = ["domElement",0];
cocktailCore.domElement.ContainerDOMElementChildValue.domElement.toString = $estr;
cocktailCore.domElement.ContainerDOMElementChildValue.domElement.__enum__ = cocktailCore.domElement.ContainerDOMElementChildValue;
cocktailCore.domElement.ContainerDOMElementChildValue.textElement = ["textElement",1];
cocktailCore.domElement.ContainerDOMElementChildValue.textElement.toString = $estr;
cocktailCore.domElement.ContainerDOMElementChildValue.textElement.__enum__ = cocktailCore.domElement.ContainerDOMElementChildValue;
if(!cocktailCore.style.formatter) cocktailCore.style.formatter = {}
cocktailCore.style.formatter.FormattingContext = $hxClasses["cocktailCore.style.formatter.FormattingContext"] = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::new");
	var $spos = $s.length;
	this._containingDOMElement = domElement;
	this._containingDOMElementWidth = this._containingDOMElement.getStyle().getComputedStyle().width;
	this._floatsManager = new cocktailCore.style.floats.FloatsManager();
	this._formattingContextData = this.initFormattingContextData(this._containingDOMElement);
	this._elementsInFormattingContext = new Array();
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.__name__ = ["cocktailCore","style","formatter","FormattingContext"];
cocktailCore.style.formatter.FormattingContext.prototype = {
	_containingDOMElement: null
	,containingDOMElement: null
	,_containingDOMElementWidth: null
	,_floatsManager: null
	,_formattingContextData: null
	,formattingContextData: null
	,_elementsInFormattingContext: null
	,initFormattingContextData: function(domElement) {
		$s.push("cocktailCore.style.formatter.FormattingContext::initFormattingContextData");
		var $spos = $s.length;
		var flowY = 0;
		var flowX = 0;
		var $tmp = { x : flowX, y : flowY, maxHeight : 0, maxWidth : 0};
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,insertElement: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertElement");
		var $spos = $s.length;
		this._elementsInFormattingContext.push(element);
		$s.pop();
	}
	,format: function() {
		$s.push("cocktailCore.style.formatter.FormattingContext::format");
		var $spos = $s.length;
		this._formattingContextData = this.initFormattingContextData(this._containingDOMElement);
		var _g1 = 0, _g = this._elementsInFormattingContext.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.doInsertElement(this._elementsInFormattingContext[i],this.isNextElementALineFeed(this._elementsInFormattingContext,i));
		}
		$s.pop();
	}
	,doInsertElement: function(element,isNextElementALineFeed) {
		$s.push("cocktailCore.style.formatter.FormattingContext::doInsertElement");
		var $spos = $s.length;
		if(element.canHaveChildren() == true) {
			if(element.getDOMElement().getStyle().establishesNewFormattingContext() == true) this.insertFormattingContextRootElement(element); else this.insertContainerElement(element);
		} else if(element.isText() == true) {
			if(element.isSpace() == true) this.insertSpace(element,isNextElementALineFeed); else this.insertText(element);
		} else this.insertEmbeddedElement(element);
		$s.pop();
	}
	,getChildrenHeight: function(elementRenderer) {
		$s.push("cocktailCore.style.formatter.FormattingContext::getChildrenHeight");
		var $spos = $s.length;
		var height = 0;
		var elementRenderers = this.getParentElementRenderers(elementRenderer);
		var _g1 = 0, _g = elementRenderers.length;
		while(_g1 < _g) {
			var i = _g1++;
			height += Math.round(elementRenderers[i].getBounds().height);
		}
		$s.pop();
		return height;
		$s.pop();
	}
	,getParentElementRenderers: function(elementRenderer) {
		$s.push("cocktailCore.style.formatter.FormattingContext::getParentElementRenderers");
		var $spos = $s.length;
		var $tmp = this.doGetParentElementRenderers(elementRenderer,this._elementsInFormattingContext);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,doGetParentElementRenderers: function(elementRenderer,targetElementRenderers) {
		$s.push("cocktailCore.style.formatter.FormattingContext::doGetParentElementRenderers");
		var $spos = $s.length;
		var elementRenderers = new Array();
		var _g1 = 0, _g = targetElementRenderers.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(targetElementRenderers[i].getParent() == elementRenderer) elementRenderers.push(targetElementRenderers[i]);
		}
		if(elementRenderers.length == 0) targetElementRenderers.push(elementRenderer);
		$s.pop();
		return elementRenderers;
		$s.pop();
	}
	,getBounds: function(elements) {
		$s.push("cocktailCore.style.formatter.FormattingContext::getBounds");
		var $spos = $s.length;
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
				if(elements[i].isText() == false) top = elements[i].getBounds().y; else top = elements[i].getBounds().y - elements[i].getDOMElement().getStyle().getFontMetricsData().ascent;
			}
			if(elements[i].getBounds().x + elements[i].getBounds().width > right) right = elements[i].getBounds().x + elements[i].getBounds().width;
			if(elements[i].getBounds().y + elements[i].getBounds().height > bottom) {
				if(elements[i].isText() == false) bottom = elements[i].getBounds().y + elements[i].getBounds().height; else bottom = elements[i].getBounds().y - elements[i].getDOMElement().getStyle().getFontMetricsData().ascent + elements[i].getBounds().height;
			}
		}
		bounds = { x : left, y : top, width : right - left, height : bottom - top};
		$s.pop();
		return bounds;
		$s.pop();
	}
	,insertEmbeddedElement: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertEmbeddedElement");
		var $spos = $s.length;
		$s.pop();
	}
	,insertFormattingContextRootElement: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertFormattingContextRootElement");
		var $spos = $s.length;
		$s.pop();
	}
	,insertContainerElement: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertContainerElement");
		var $spos = $s.length;
		$s.pop();
	}
	,insertText: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertText");
		var $spos = $s.length;
		$s.pop();
	}
	,insertSpace: function(element,isNextElementALineFeed) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertSpace");
		var $spos = $s.length;
		$s.pop();
	}
	,insertHorizontalOffset: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertHorizontalOffset");
		var $spos = $s.length;
		$s.pop();
	}
	,insertTab: function(element,isNextElementALineFeed) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertTab");
		var $spos = $s.length;
		$s.pop();
	}
	,insertLineFeed: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertLineFeed");
		var $spos = $s.length;
		$s.pop();
	}
	,insertFloat: function(element) {
		$s.push("cocktailCore.style.formatter.FormattingContext::insertFloat");
		var $spos = $s.length;
		$s.pop();
	}
	,clearFloat: function(clear) {
		$s.push("cocktailCore.style.formatter.FormattingContext::clearFloat");
		var $spos = $s.length;
		this._floatsManager.clearFloat(clear,this.getFormattingContextData());
		$s.pop();
	}
	,removeFloats: function() {
		$s.push("cocktailCore.style.formatter.FormattingContext::removeFloats");
		var $spos = $s.length;
		this._floatsManager.removeFloats(this._formattingContextData.y);
		$s.pop();
	}
	,isNextElementALineFeed: function(elementsInFormattingContext,currentIndex) {
		$s.push("cocktailCore.style.formatter.FormattingContext::isNextElementALineFeed");
		var $spos = $s.length;
		var isNextElementALineFeed;
		if(currentIndex + 1 >= elementsInFormattingContext.length) isNextElementALineFeed = false; else isNextElementALineFeed = elementsInFormattingContext[currentIndex + 1].isLineFeed();
		$s.pop();
		return isNextElementALineFeed;
		$s.pop();
	}
	,getFormattingContextData: function() {
		$s.push("cocktailCore.style.formatter.FormattingContext::getFormattingContextData");
		var $spos = $s.length;
		var $tmp = this._formattingContextData;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getContainingDOMElement: function() {
		$s.push("cocktailCore.style.formatter.FormattingContext::getContainingDOMElement");
		var $spos = $s.length;
		var $tmp = this._containingDOMElement;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.formatter.FormattingContext
	,__properties__: {get_formattingContextData:"getFormattingContextData",get_containingDOMElement:"getContainingDOMElement"}
}
cocktailCore.style.formatter.BlockFormattingContext = $hxClasses["cocktailCore.style.formatter.BlockFormattingContext"] = function(domElement) {
	$s.push("cocktailCore.style.formatter.BlockFormattingContext::new");
	var $spos = $s.length;
	this._currentAddedSiblingsHeight = 0;
	cocktailCore.style.formatter.FormattingContext.call(this,domElement);
	$s.pop();
}
cocktailCore.style.formatter.BlockFormattingContext.__name__ = ["cocktailCore","style","formatter","BlockFormattingContext"];
cocktailCore.style.formatter.BlockFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.BlockFormattingContext.prototype = $extend(cocktailCore.style.formatter.FormattingContext.prototype,{
	_currentAddedSiblingsHeight: null
	,_lastInsertedElement: null
	,format: function() {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::format");
		var $spos = $s.length;
		this._formattingContextData = this.initFormattingContextData(this._containingDOMElement);
		this._lastInsertedElement = this._containingDOMElement.getStyle().getElementRenderer();
		var _g1 = 0, _g = this._elementsInFormattingContext.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isSiblingOfLastInsertedElement(this._elementsInFormattingContext[i])) {
			} else if(this.isParentOfLastInsertedElement(this._elementsInFormattingContext[i])) {
				this._formattingContextData.y -= this._currentAddedSiblingsHeight;
				this._currentAddedSiblingsHeight = 0;
			} else this._currentAddedSiblingsHeight = 0;
			this._lastInsertedElement = this._elementsInFormattingContext[i];
			this.doInsertElement(this._elementsInFormattingContext[i],this.isNextElementALineFeed(this._elementsInFormattingContext,i));
		}
		$s.pop();
	}
	,isParentOfLastInsertedElement: function(element) {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::isParentOfLastInsertedElement");
		var $spos = $s.length;
		var $tmp = element.getDOMElement() == this._lastInsertedElement.getDOMElement().getParent();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,isSiblingOfLastInsertedElement: function(element) {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::isSiblingOfLastInsertedElement");
		var $spos = $s.length;
		var $tmp = this._lastInsertedElement.getDOMElement().getParent() == element.getDOMElement().getParent();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,insertEmbeddedElement: function(element) {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::insertEmbeddedElement");
		var $spos = $s.length;
		var x = this._formattingContextData.x;
		var y = this._formattingContextData.y;
		var width = element.getDOMElement().getOffsetWidth();
		var height = element.getDOMElement().getOffsetHeight();
		element.setBounds({ x : x, y : y, width : width, height : height});
		if(element.getBounds().width > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = Math.round(element.getBounds().width);
		this._formattingContextData.y += Math.round(element.getBounds().height);
		this._currentAddedSiblingsHeight += Math.round(element.getBounds().height);
		$s.pop();
	}
	,insertFormattingContextRootElement: function(element) {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::insertFormattingContextRootElement");
		var $spos = $s.length;
		var x = this._formattingContextData.x;
		var y = this._formattingContextData.y;
		var width = element.getDOMElement().getOffsetWidth();
		var height = element.getDOMElement().getOffsetHeight();
		element.setBounds({ x : x, y : y, width : width, height : height});
		if(element.getBounds().width > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = Math.round(element.getBounds().width);
		this._formattingContextData.y += Math.round(element.getBounds().height);
		this._currentAddedSiblingsHeight += Math.round(element.getBounds().height);
		$s.pop();
	}
	,insertContainerElement: function(element) {
		$s.push("cocktailCore.style.formatter.BlockFormattingContext::insertContainerElement");
		var $spos = $s.length;
		var x = 0.0;
		var y = this._formattingContextData.y;
		var width = element.getDOMElement().getOffsetWidth();
		var height = element.getDOMElement().getOffsetHeight();
		element.setBounds({ x : x, y : y, width : width, height : height});
		if(element.getBounds().width > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = Math.round(element.getBounds().width);
		this._formattingContextData.y += Math.round(element.getBounds().height);
		this._currentAddedSiblingsHeight += Math.round(element.getBounds().height);
		$s.pop();
	}
	,__class__: cocktailCore.style.formatter.BlockFormattingContext
});
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	measureVerticalPaddings: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::measureVerticalPaddings");
		var $spos = $s.length;
		style.getComputedStyle().paddingTop = 0;
		style.getComputedStyle().paddingBottom = 0;
		$s.pop();
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::measureAutoHeight");
		var $spos = $s.length;
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
		$s.pop();
	}
	,measureHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::measureHeight");
		var $spos = $s.length;
		this.setComputedHeight(style,this.getComputedHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
		$s.pop();
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedAutoMargin");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,getComputedWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedWidth");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,getComputedHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedHeight");
		var $spos = $s.length;
		$s.pop();
		return 0;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer
});
org.intermedia.model.CellDetailsRss = $hxClasses["org.intermedia.model.CellDetailsRss"] = function() { }
org.intermedia.model.CellDetailsRss.__name__ = ["org","intermedia","model","CellDetailsRss"];
org.intermedia.model.CellDetailsRss.rss2CellDetail = function(rss,cellData) {
	$s.push("org.intermedia.model.CellDetailsRss::rss2CellDetail");
	var $spos = $s.length;
	var channelNode = rss.firstElement().firstElement();
	var cell = { id : cellData.id, title : cellData.title, author : cellData.author, thumbUrl : cellData.thumbUrl, category : cellData.category, description : ""};
	var $it0 = channelNode.elements();
	while( $it0.hasNext() ) {
		var channelChild = $it0.next();
		if(channelChild.getNodeName() == "item") {
			var $it1 = channelChild.elements();
			while( $it1.hasNext() ) {
				var itemParam = $it1.next();
				if(itemParam.getNodeName() == "description") {
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
org.intermedia.model.CellDetailsRss.prototype = {
	__class__: org.intermedia.model.CellDetailsRss
}
var StringBuf = $hxClasses["StringBuf"] = function() {
	$s.push("StringBuf::new");
	var $spos = $s.length;
	this.b = new Array();
	$s.pop();
}
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		$s.push("StringBuf::add");
		var $spos = $s.length;
		this.b[this.b.length] = x == null?"null":x;
		$s.pop();
	}
	,addSub: function(s,pos,len) {
		$s.push("StringBuf::addSub");
		var $spos = $s.length;
		this.b[this.b.length] = s.substr(pos,len);
		$s.pop();
	}
	,addChar: function(c) {
		$s.push("StringBuf::addChar");
		var $spos = $s.length;
		this.b[this.b.length] = String.fromCharCode(c);
		$s.pop();
	}
	,toString: function() {
		$s.push("StringBuf::toString");
		var $spos = $s.length;
		var $tmp = this.b.join("");
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,b: null
	,__class__: StringBuf
}
var haxe = haxe || {}
haxe.Log = $hxClasses["haxe.Log"] = function() { }
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
haxe.Log.prototype = {
	__class__: haxe.Log
}
cocktailCore.domElement.js.BodyDOMElement = $hxClasses["cocktailCore.domElement.js.BodyDOMElement"] = function() {
	$s.push("cocktailCore.domElement.js.BodyDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractBodyDOMElement.call(this);
	$s.pop();
}
cocktailCore.domElement.js.BodyDOMElement.__name__ = ["cocktailCore","domElement","js","BodyDOMElement"];
cocktailCore.domElement.js.BodyDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractBodyDOMElement;
cocktailCore.domElement.js.BodyDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype,{
	initKeyboard: function() {
		$s.push("cocktailCore.domElement.js.BodyDOMElement::initKeyboard");
		var $spos = $s.length;
		this._keyboard = new cocktailCore.keyboard.js.Keyboard(js.Lib.document);
		$s.pop();
	}
	,__class__: cocktailCore.domElement.js.BodyDOMElement
});
cocktailCore.domElement.abstract.AbstractGraphicDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractGraphicDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
	this._drawingManager = new cocktailCore.drawing.js.DrawingManager(nativeElement,this._intrinsicHeight,this._intrinsicWidth);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractGraphicDOMElement"];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype = $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype,{
	_drawingManager: null
	,beginFill: function(fillStyle,lineStyle) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::beginFill");
		var $spos = $s.length;
		this._drawingManager.beginFill(fillStyle,lineStyle);
		$s.pop();
	}
	,endFill: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::endFill");
		var $spos = $s.length;
		this._drawingManager.endFill();
		$s.pop();
	}
	,clear: function() {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::clear");
		var $spos = $s.length;
		this._drawingManager.clear();
		$s.pop();
	}
	,setLineStyle: function(lineStyle) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::setLineStyle");
		var $spos = $s.length;
		this._drawingManager.setLineStyle(lineStyle);
		$s.pop();
	}
	,setFillStyle: function(fillStyle) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::setFillStyle");
		var $spos = $s.length;
		this._drawingManager.setFillStyle(fillStyle);
		$s.pop();
	}
	,drawRect: function(x,y,width,height,cornerRadiuses) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawRect");
		var $spos = $s.length;
		this._drawingManager.drawRect(x,y,width,height,cornerRadiuses);
		$s.pop();
	}
	,drawEllipse: function(x,y,width,height) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawEllipse");
		var $spos = $s.length;
		this._drawingManager.drawEllipse(x,y,width,height);
		$s.pop();
	}
	,drawImage: function(source,matrix,sourceRect) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawImage");
		var $spos = $s.length;
		this._drawingManager.drawImage(source,matrix,sourceRect);
		$s.pop();
	}
	,lineTo: function(x,y) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::lineTo");
		var $spos = $s.length;
		this._drawingManager.lineTo(x,y);
		$s.pop();
	}
	,moveTo: function(x,y) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::moveTo");
		var $spos = $s.length;
		this._drawingManager.moveTo(x,y);
		$s.pop();
	}
	,curveTo: function(controlX,controlY,x,y) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::curveTo");
		var $spos = $s.length;
		this._drawingManager.curveTo(controlX,controlY,x,y);
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::setWidth");
		var $spos = $s.length;
		cocktailCore.domElement.js.EmbeddedDOMElement.prototype.setWidth.call(this,value);
		this._intrinsicWidth = value;
		this._drawingManager.setWidth(value);
		$s.pop();
		return value;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::setHeight");
		var $spos = $s.length;
		cocktailCore.domElement.js.EmbeddedDOMElement.prototype.setHeight.call(this,value);
		this._intrinsicHeight = value;
		this._drawingManager.setHeight(value);
		$s.pop();
		return value;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.abstract.AbstractGraphicDOMElement
});
cocktailCore.domElement.js.GraphicDOMElement = $hxClasses["cocktailCore.domElement.js.GraphicDOMElement"] = function(nativeElement) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.__name__ = ["cocktailCore","domElement","js","GraphicDOMElement"];
cocktailCore.domElement.js.GraphicDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
cocktailCore.domElement.js.GraphicDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype,{
	setWidth: function(value) {
		$s.push("cocktailCore.domElement.js.GraphicDOMElement::setWidth");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setWidth.call(this,value);
		this._nativeElement.width = value;
		$s.pop();
		return value;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.domElement.js.GraphicDOMElement::setHeight");
		var $spos = $s.length;
		cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setHeight.call(this,value);
		this._nativeElement.height = value;
		$s.pop();
		return value;
		$s.pop();
	}
	,__class__: cocktailCore.domElement.js.GraphicDOMElement
});
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementCreator"] = function() {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementCreator::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementCreator"];
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype = {
	createNativeElement: function(nativeElementType) {
		$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementCreator::createNativeElement");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementCreator
}
cocktailCore.style.positioner.FixedPositioner = $hxClasses["cocktailCore.style.positioner.FixedPositioner"] = function() {
	$s.push("cocktailCore.style.positioner.FixedPositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.FixedPositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	__class__: cocktailCore.style.positioner.FixedPositioner
});
if(!cocktail.resource) cocktail.resource = {}
cocktail.resource.LoadingTypeValue = $hxClasses["cocktail.resource.LoadingTypeValue"] = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",1];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
org.intermedia.model.DataLoader = $hxClasses["org.intermedia.model.DataLoader"] = function(online) {
	$s.push("org.intermedia.model.DataLoader::new");
	var $spos = $s.length;
	if(online == null) online = true;
	this._online = online;
	$s.pop();
}
org.intermedia.model.DataLoader.__name__ = ["org","intermedia","model","DataLoader"];
org.intermedia.model.DataLoader.prototype = {
	onCellDataLoaded: null
	,onCellDetailLoaded: null
	,onLoadingError: null
	,_online: null
	,loadCellData: function(startIndex,endIndex,successCallback,errorCallback) {
		$s.push("org.intermedia.model.DataLoader::loadCellData");
		var $spos = $s.length;
		this.onCellDataLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var fullUrl = "";
		if(this._online) fullUrl = "http://www.silexlabs.org/feed/ep_posts_small/?cat=657&format=rss2"; else fullUrl = "data/silex_plugins.rss";
		var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,this.onCellsXmlLoaded.$bind(this),this.onLoadingError);
		$s.pop();
	}
	,loadDetailData: function(cellData,successCallback,errorCallback) {
		$s.push("org.intermedia.model.DataLoader::loadDetailData");
		var $spos = $s.length;
		var me = this;
		this.onCellDetailLoaded = successCallback;
		this.onLoadingError = errorCallback;
		var onLoadSuccessDelegate = function(xml) {
			$s.push("org.intermedia.model.DataLoader::loadDetailData@71");
			var $spos = $s.length;
			me.onCellDetailXmlLoaded(xml,cellData);
			$s.pop();
		};
		var fullUrl = "";
		if(this._online) fullUrl = "http://www.silexlabs.org/feed/?s=" + cellData.title.substr(0,cellData.title.indexOf(" ")) + "&format=rss2"; else fullUrl = "data/detail.rss";
		var xmlLoader = new org.intermedia.model.XmlLoader(fullUrl,this._online,onLoadSuccessDelegate,this.onLoadingError);
		$s.pop();
	}
	,onCellsXmlLoaded: function(xml) {
		$s.push("org.intermedia.model.DataLoader::onCellsXmlLoaded");
		var $spos = $s.length;
		this.onCellDataLoaded(org.intermedia.model.ThumbTextListRss.rss2Cells(xml));
		$s.pop();
	}
	,onCellDetailXmlLoaded: function(xml,cellData) {
		$s.push("org.intermedia.model.DataLoader::onCellDetailXmlLoaded");
		var $spos = $s.length;
		this.onCellDetailLoaded(org.intermedia.model.CellDetailsRss.rss2CellDetail(xml,cellData));
		$s.pop();
	}
	,__class__: org.intermedia.model.DataLoader
}
cocktail.resource.ResourceLoaderManager = $hxClasses["cocktail.resource.ResourceLoaderManager"] = function() {
	$s.push("cocktail.resource.ResourceLoaderManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.__name__ = ["cocktail","resource","ResourceLoaderManager"];
cocktail.resource.ResourceLoaderManager._resourceDataArray = null;
cocktail.resource.ResourceLoaderManager.loadString = function(url,successCallback,errorCallback,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadString");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, loadingType : cocktail.resource.LoadingTypeValue.data};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.loadLibrary = function(url,successCallback,errorCallback,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadLibrary");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, loadingType : cocktail.resource.LoadingTypeValue.library};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.addResourceData = function(resourceData) {
	$s.push("cocktail.resource.ResourceLoaderManager::addResourceData");
	var $spos = $s.length;
	if(cocktail.resource.ResourceLoaderManager._resourceDataArray == null) cocktail.resource.ResourceLoaderManager._resourceDataArray = new Array();
	cocktail.resource.ResourceLoaderManager._resourceDataArray.push(resourceData);
	if(cocktail.resource.ResourceLoaderManager._isLoading == false) cocktail.resource.ResourceLoaderManager.loadNextResource();
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.loadNextResource = function() {
	$s.push("cocktail.resource.ResourceLoaderManager::loadNextResource");
	var $spos = $s.length;
	if(cocktail.resource.ResourceLoaderManager._resourceDataArray.length == 0) cocktail.resource.ResourceLoaderManager._isLoading = false; else {
		cocktail.resource.ResourceLoaderManager._isLoading = true;
		var resourceDataToLoad = cocktail.resource.ResourceLoaderManager._resourceDataArray[0];
		var resourceLoader;
		switch( (resourceDataToLoad.loadingType)[1] ) {
		case 0:
			resourceLoader = new cocktailCore.resource.js.StringLoader();
			break;
		case 1:
			resourceLoader = new cocktailCore.resource.js.LibraryLoader();
			break;
		}
		resourceLoader.load([resourceDataToLoad.url],cocktail.resource.ResourceLoaderManager.onLoadComplete,cocktail.resource.ResourceLoaderManager.onLoadError,resourceDataToLoad.allowCache);
	}
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.onLoadComplete = function(data) {
	$s.push("cocktail.resource.ResourceLoaderManager::onLoadComplete");
	var $spos = $s.length;
	var loadedResourceData = cocktail.resource.ResourceLoaderManager._resourceDataArray.shift();
	loadedResourceData.onLoadComplete(data);
	cocktail.resource.ResourceLoaderManager.loadNextResource();
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.onLoadError = function(data) {
	$s.push("cocktail.resource.ResourceLoaderManager::onLoadError");
	var $spos = $s.length;
	var errorResourceData = cocktail.resource.ResourceLoaderManager._resourceDataArray.shift();
	errorResourceData.onLoadError(data);
	cocktail.resource.ResourceLoaderManager.loadNextResource();
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.prototype = {
	__class__: cocktail.resource.ResourceLoaderManager
}
cocktailCore.nativeElement.js.NativeElementCreator = $hxClasses["cocktailCore.nativeElement.js.NativeElementCreator"] = function() {
	$s.push("cocktailCore.nativeElement.js.NativeElementCreator::new");
	var $spos = $s.length;
	cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.call(this);
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementCreator.__name__ = ["cocktailCore","nativeElement","js","NativeElementCreator"];
cocktailCore.nativeElement.js.NativeElementCreator.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
cocktailCore.nativeElement.js.NativeElementCreator.prototype = $extend(cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype,{
	createNativeElement: function(nativeElementType) {
		$s.push("cocktailCore.nativeElement.js.NativeElementCreator::createNativeElement");
		var $spos = $s.length;
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
		$s.pop();
		return nativeElement;
		$s.pop();
	}
	,__class__: cocktailCore.nativeElement.js.NativeElementCreator
});
if(!cocktail.domElement) cocktail.domElement = {}
cocktail.domElement.LinkTargetValue = $hxClasses["cocktail.domElement.LinkTargetValue"] = { __ename__ : ["cocktail","domElement","LinkTargetValue"], __constructs__ : ["blank","self","parent","top"] }
cocktail.domElement.LinkTargetValue.blank = ["blank",0];
cocktail.domElement.LinkTargetValue.blank.toString = $estr;
cocktail.domElement.LinkTargetValue.blank.__enum__ = cocktail.domElement.LinkTargetValue;
cocktail.domElement.LinkTargetValue.self = ["self",1];
cocktail.domElement.LinkTargetValue.self.toString = $estr;
cocktail.domElement.LinkTargetValue.self.__enum__ = cocktail.domElement.LinkTargetValue;
cocktail.domElement.LinkTargetValue.parent = ["parent",2];
cocktail.domElement.LinkTargetValue.parent.toString = $estr;
cocktail.domElement.LinkTargetValue.parent.__enum__ = cocktail.domElement.LinkTargetValue;
cocktail.domElement.LinkTargetValue.top = ["top",3];
cocktail.domElement.LinkTargetValue.top.toString = $estr;
cocktail.domElement.LinkTargetValue.top.__enum__ = cocktail.domElement.LinkTargetValue;
cocktail.domElement.FillStyleValue = $hxClasses["cocktail.domElement.FillStyleValue"] = { __ename__ : ["cocktail","domElement","FillStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.domElement.FillStyleValue.none = ["none",0];
cocktail.domElement.FillStyleValue.none.toString = $estr;
cocktail.domElement.FillStyleValue.none.__enum__ = cocktail.domElement.FillStyleValue;
cocktail.domElement.FillStyleValue.monochrome = function(colorStop) { var $x = ["monochrome",1,colorStop]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.FillStyleValue.gradient = function(gradientStyle) { var $x = ["gradient",2,gradientStyle]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.FillStyleValue.bitmap = function(imageDOMElement,repeat) { var $x = ["bitmap",3,imageDOMElement,repeat]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue = $hxClasses["cocktail.domElement.LineStyleValue"] = { __ename__ : ["cocktail","domElement","LineStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.domElement.LineStyleValue.none = ["none",0];
cocktail.domElement.LineStyleValue.none.toString = $estr;
cocktail.domElement.LineStyleValue.none.__enum__ = cocktail.domElement.LineStyleValue;
cocktail.domElement.LineStyleValue.monochrome = function(color,lineStyle) { var $x = ["monochrome",1,color,lineStyle]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue.gradient = function(gradientStyle,lineStyle) { var $x = ["gradient",2,gradientStyle,lineStyle]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue.bitmap = function(imageDOMElement,lineStyle,repeat) { var $x = ["bitmap",3,imageDOMElement,lineStyle,repeat]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.GradientTypeValue = $hxClasses["cocktail.domElement.GradientTypeValue"] = { __ename__ : ["cocktail","domElement","GradientTypeValue"], __constructs__ : ["linear","radial"] }
cocktail.domElement.GradientTypeValue.linear = ["linear",0];
cocktail.domElement.GradientTypeValue.linear.toString = $estr;
cocktail.domElement.GradientTypeValue.linear.__enum__ = cocktail.domElement.GradientTypeValue;
cocktail.domElement.GradientTypeValue.radial = ["radial",1];
cocktail.domElement.GradientTypeValue.radial.toString = $estr;
cocktail.domElement.GradientTypeValue.radial.__enum__ = cocktail.domElement.GradientTypeValue;
cocktail.domElement.CapsStyleValue = $hxClasses["cocktail.domElement.CapsStyleValue"] = { __ename__ : ["cocktail","domElement","CapsStyleValue"], __constructs__ : ["none","square","round"] }
cocktail.domElement.CapsStyleValue.none = ["none",0];
cocktail.domElement.CapsStyleValue.none.toString = $estr;
cocktail.domElement.CapsStyleValue.none.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.CapsStyleValue.square = ["square",1];
cocktail.domElement.CapsStyleValue.square.toString = $estr;
cocktail.domElement.CapsStyleValue.square.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.CapsStyleValue.round = ["round",2];
cocktail.domElement.CapsStyleValue.round.toString = $estr;
cocktail.domElement.CapsStyleValue.round.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.JointStyleValue = $hxClasses["cocktail.domElement.JointStyleValue"] = { __ename__ : ["cocktail","domElement","JointStyleValue"], __constructs__ : ["miter","round","bevel"] }
cocktail.domElement.JointStyleValue.miter = ["miter",0];
cocktail.domElement.JointStyleValue.miter.toString = $estr;
cocktail.domElement.JointStyleValue.miter.__enum__ = cocktail.domElement.JointStyleValue;
cocktail.domElement.JointStyleValue.round = ["round",1];
cocktail.domElement.JointStyleValue.round.toString = $estr;
cocktail.domElement.JointStyleValue.round.__enum__ = cocktail.domElement.JointStyleValue;
cocktail.domElement.JointStyleValue.bevel = ["bevel",2];
cocktail.domElement.JointStyleValue.bevel.toString = $estr;
cocktail.domElement.JointStyleValue.bevel.__enum__ = cocktail.domElement.JointStyleValue;
org.intermedia.view.ViewManagerStyle = $hxClasses["org.intermedia.view.ViewManagerStyle"] = function() { }
org.intermedia.view.ViewManagerStyle.__name__ = ["org","intermedia","view","ViewManagerStyle"];
org.intermedia.view.ViewManagerStyle.setBodyStyle = function(domElement) {
	$s.push("org.intermedia.view.ViewManagerStyle::setBodyStyle");
	var $spos = $s.length;
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(130));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setOverflow({ x : cocktail.style.OverflowStyleValue.hidden, y : cocktail.style.OverflowStyleValue.autoValue});
	$s.pop();
}
org.intermedia.view.ViewManagerStyle.prototype = {
	__class__: org.intermedia.view.ViewManagerStyle
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::shrinkToFit");
		var $spos = $s.length;
		var shrinkedWidth;
		if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue || style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
			var computedStyle = style.getComputedStyle();
			shrinkedWidth = this.doShrinkToFit(style,containingDOMElementData,minimumWidth);
			if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingDOMElementData);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
		} else shrinkedWidth = style.getComputedStyle().width;
		shrinkedWidth = this.constrainWidth(style,shrinkedWidth);
		$s.pop();
		return shrinkedWidth;
		$s.pop();
	}
	,applyContentHeight: function(style,containingDOMElementData,childrenHeight) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::applyContentHeight");
		var $spos = $s.length;
		var height;
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			var computedStyle = style.getComputedStyle();
			height = containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		} else height = childrenHeight;
		height = this.constrainHeight(style,height);
		$s.pop();
		return height;
		$s.pop();
	}
	,measurePositionOffsets: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measurePositionOffsets");
		var $spos = $s.length;
		$s.pop();
	}
	,measureAutoWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measureAutoWidth");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) computedStyle.marginLeft = 0; else computedStyle.marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) computedStyle.marginRight = 0; else computedStyle.marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		if(style.getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			computedStyle.left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			computedStyle.right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,containingDOMElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight);
		} else this.setComputedWidth(style,10000000);
		$s.pop();
	}
	,measureWidth: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measureWidth");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		this.setComputedWidth(style,this.getComputedWidth(style,containingDOMElementData));
		if(style.getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue && style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) {
				var computedMargin = Math.round((containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginLeft = computedMargin;
					style.getComputedStyle().marginRight = computedMargin;
				} else {
					style.getComputedStyle().marginLeft = 0;
					style.getComputedStyle().marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			} else if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) {
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
				style.getComputedStyle().marginLeft = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			} else if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
				style.getComputedStyle().marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			} else {
				style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
				style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
			}
		} else {
			if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginLeft = 0; else style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
			if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginRight = 0; else style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
			if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingDOMElementData);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			} else if(style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
		$s.pop();
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measureAutoHeight");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,containingDOMElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom);
		}
		$s.pop();
	}
	,measureHeight: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measureHeight");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		this.setComputedHeight(style,this.getComputedHeight(style,containingDOMElementData));
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue && style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) {
				var computedMargin = Math.round((containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginBottom = 0;
					style.getComputedStyle().marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			} else if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) {
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
				style.getComputedStyle().marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			} else if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
				style.getComputedStyle().marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			} else {
				style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
				style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
			}
		} else {
			if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
			if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
			if(style.getTop() == cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingDOMElementData);
				style.getComputedStyle().bottom = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getBottom() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().top = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
			}
		}
		$s.pop();
	}
	,getComputedStaticLeft: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::getComputedStaticLeft");
		var $spos = $s.length;
		var $tmp = style.getComputedStyle().marginLeft;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedStaticTop: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::getComputedStaticTop");
		var $spos = $s.length;
		var $tmp = style.getComputedStyle().marginTop;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,doShrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::doShrinkToFit");
		var $spos = $s.length;
		$s.pop();
		return minimumWidth;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer
});
cocktailCore.style.formatter.InlineFormattingContext = $hxClasses["cocktailCore.style.formatter.InlineFormattingContext"] = function(domElement) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::new");
	var $spos = $s.length;
	this._elementsInLineBox = new Array();
	this._unbreakableLineBoxElements = new Array();
	this._unbreakableWidth = 0;
	this._currentInlineBoxesData = new Array();
	cocktailCore.style.formatter.FormattingContext.call(this,domElement);
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.__name__ = ["cocktailCore","style","formatter","InlineFormattingContext"];
cocktailCore.style.formatter.InlineFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.InlineFormattingContext.prototype = $extend(cocktailCore.style.formatter.FormattingContext.prototype,{
	_elementsInLineBox: null
	,_unbreakableLineBoxElements: null
	,_unbreakableWidth: null
	,_lastInsertedElement: null
	,_currentInlineBoxesData: null
	,format: function() {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::format");
		var $spos = $s.length;
		this._elementsInLineBox = new Array();
		this._unbreakableLineBoxElements = new Array();
		this._unbreakableWidth = 0;
		var flowBoxRenderer = this._containingDOMElement.getStyle().getElementRenderer();
		flowBoxRenderer.removeLineBoxes();
		this._currentInlineBoxesData = new Array();
		cocktailCore.style.formatter.FormattingContext.prototype.format.call(this);
		this.insertBreakOpportunity(true,true);
		$s.pop();
	}
	,getRemainingLineWidth: function() {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::getRemainingLineWidth");
		var $spos = $s.length;
		var $tmp = this._containingDOMElementWidth - this._formattingContextData.x - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._containingDOMElementWidth);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,insertEmbeddedElement: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertEmbeddedElement");
		var $spos = $s.length;
		this.insertBreakOpportunity(false);
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(element.getDOMElement().getOffsetWidth());
		this.insertBreakOpportunity(false);
		$s.pop();
	}
	,insertFormattingContextRootElement: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertFormattingContextRootElement");
		var $spos = $s.length;
		this.insertBreakOpportunity(false);
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(element.getDOMElement().getOffsetWidth());
		this.insertBreakOpportunity(false);
		$s.pop();
	}
	,insertContainerElement: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertContainerElement");
		var $spos = $s.length;
		this._unbreakableLineBoxElements.push(element);
		$s.pop();
	}
	,insertText: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertText");
		var $spos = $s.length;
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(element.getDOMElement().getOffsetWidth());
		$s.pop();
	}
	,insertSpace: function(element,isNextElementALineFeed) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertSpace");
		var $spos = $s.length;
		this._unbreakableLineBoxElements.push(element);
		this._lastInsertedElement = element;
		this.addWidth(element.getDOMElement().getOffsetWidth());
		this.insertBreakOpportunity(false);
		$s.pop();
	}
	,insertHorizontalOffset: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertHorizontalOffset");
		var $spos = $s.length;
		$s.pop();
	}
	,insertTab: function(element,isNextElementALineFeed) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertTab");
		var $spos = $s.length;
		$s.pop();
	}
	,insertLineFeed: function(element) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertLineFeed");
		var $spos = $s.length;
		$s.pop();
	}
	,insertBreakOpportunity: function(forced,isLastLine) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertBreakOpportunity");
		var $spos = $s.length;
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
		$s.pop();
	}
	,addWidth: function(width) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::addWidth");
		var $spos = $s.length;
		this._unbreakableWidth += width;
		$s.pop();
	}
	,shouldTabBeConvertedToSpace: function(whiteSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::shouldTabBeConvertedToSpace");
		var $spos = $s.length;
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
		$s.pop();
		return shouldTabBeConvertedToSpace;
		$s.pop();
	}
	,isLineFeedAllowed: function(whiteSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::isLineFeedAllowed");
		var $spos = $s.length;
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
		$s.pop();
		return lineFeedAllowed;
		$s.pop();
	}
	,shouldInsertSpace: function(whiteSpace,isNexElementALineFeed) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::shouldInsertSpace");
		var $spos = $s.length;
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
		$s.pop();
		return shouldInsertSpace;
		$s.pop();
	}
	,isCollapsed: function(lastInsertedElement,whiteSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::isCollapsed");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,getParentInlineBoxesData: function(parent) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::getParentInlineBoxesData");
		var $spos = $s.length;
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
		$s.pop();
		return inlineBoxData;
		$s.pop();
	}
	,startNewLine: function(elementWidth,isLastLine) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::startNewLine");
		var $spos = $s.length;
		if(isLastLine == null) isLastLine = false;
		if(this._elementsInLineBox.length > 0) {
			this.removeSpaces();
			var lineBoxHeight = this.computeLineBoxHeight();
			var lineWidth = this.alignLineBox(isLastLine);
			if(lineWidth > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = lineWidth;
			var lineBoxElements = new Array();
			var containingDOMElementRenderer = this._containingDOMElement.getStyle().getElementRenderer();
			containingDOMElementRenderer.addLineBox(lineBoxElements);
			var _g1 = 0, _g = this._elementsInLineBox.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(this._elementsInLineBox[i].getParent() != this._containingDOMElement.getStyle().getElementRenderer()) this.getParentInlineBoxesData(this._elementsInLineBox[i].getParent()).children.push(this._elementsInLineBox[i]); else lineBoxElements.push(this._elementsInLineBox[i]);
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
				var inlineBoxRenderer = new cocktailCore.style.renderer.InlineBoxRenderer(this._currentInlineBoxesData[i].element.getDOMElement());
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
				this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,elementWidth,this._containingDOMElementWidth);
				this._formattingContextData.maxHeight = this._formattingContextData.y;
				this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
			}
		}
		$s.pop();
	}
	,removeSpaces: function() {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::removeSpaces");
		var $spos = $s.length;
		$s.pop();
	}
	,alignLineBox: function(isLastLine) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignLineBox");
		var $spos = $s.length;
		var concatenatedLength = 0;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			concatenatedLength += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
		var remainingSpace;
		var flowX;
		remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._formattingContextData.y) - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._containingDOMElementWidth);
		flowX = 0;
		flowX += this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
		switch( (this._containingDOMElement.getStyle().getComputedStyle().textAlign)[1] ) {
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
				concatenatedLength = this._containingDOMElementWidth;
				this.alignJustify(flowX,remainingSpace);
			}
			break;
		}
		$s.pop();
		return concatenatedLength;
		$s.pop();
	}
	,alignLeft: function(flowX) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignLeft");
		var $spos = $s.length;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = flowX;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
		$s.pop();
	}
	,alignCenter: function(flowX,remainingSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignCenter");
		var $spos = $s.length;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = Math.round(remainingSpace / 2) + flowX;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
		$s.pop();
	}
	,alignRight: function(flowX,remainingSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignRight");
		var $spos = $s.length;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._elementsInLineBox[i].getBounds().x = flowX + remainingSpace;
			flowX += Math.round(this._elementsInLineBox[i].getBounds().width);
		}
		$s.pop();
	}
	,alignJustify: function(flowX,remainingSpace) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignJustify");
		var $spos = $s.length;
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
			flowX += this._elementsInLineBox[i].getDOMElement().getOffsetWidth();
		}
		$s.pop();
	}
	,computeLineBoxHeight: function() {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
		var $spos = $s.length;
		var lineBoxAscent = 0;
		var lineBoxDescent = 0;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var domElement = this._elementsInLineBox[i].getDOMElement();
			var domElementAscent;
			var domElementDescent;
			var domElementVerticalAlign = domElement.getStyle().getComputedStyle().verticalAlign;
			if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) {
				domElementAscent = domElement.getOffsetHeight();
				domElementDescent = 0;
				switch( (domElement.getStyle().getVerticalAlign())[1] ) {
				case 3:
					domElementAscent = Math.round(lineBoxAscent);
					domElementDescent = Math.round(domElement.getOffsetHeight() - lineBoxAscent);
					break;
				default:
				}
			} else {
				domElementAscent = domElement.getStyle().getFontMetricsData().ascent;
				domElementDescent = domElement.getStyle().getFontMetricsData().descent;
				var leading = domElement.getStyle().getComputedStyle().lineHeight - (domElementAscent + domElementDescent);
				domElementAscent = Math.round(domElementAscent + leading / 2);
				domElementDescent = Math.round(domElementDescent + leading / 2);
			}
			if(domElementAscent - domElementVerticalAlign > lineBoxAscent) lineBoxAscent = domElementAscent - domElementVerticalAlign;
			if(domElementDescent + domElementVerticalAlign > lineBoxDescent) lineBoxDescent = domElementDescent + domElementVerticalAlign;
		}
		var lineBoxHeight = lineBoxAscent + lineBoxDescent;
		var _g1 = 0, _g = this._elementsInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var domElement = this._elementsInLineBox[i].getDOMElement();
			var verticalAlign;
			switch( (domElement.getStyle().getVerticalAlign())[1] ) {
			case 3:
				verticalAlign = 0;
				break;
			case 6:
				verticalAlign = 0;
				break;
			default:
				verticalAlign = domElement.getStyle().getComputedStyle().verticalAlign;
			}
			this._elementsInLineBox[i].getBounds().y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + this._formattingContextData.y;
			if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) {
				switch( (domElement.getStyle().getVerticalAlign())[1] ) {
				case 3:
					this._elementsInLineBox[i].getBounds().y = this._formattingContextData.y;
					break;
				default:
					this._elementsInLineBox[i].getBounds().y -= domElement.getOffsetHeight();
				}
			}
		}
		var $tmp = Math.round(lineBoxHeight);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.formatter.InlineFormattingContext
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
	$s.push("org.intermedia.view.ScreenResolution::new");
	var $spos = $s.length;
	var viewport = new cocktailCore.viewport.js.Viewport();
	if(viewport._getWidth() < 400) this.size = org.intermedia.view.ScreenResolutionSize.small; else if(viewport._getWidth() < 600) this.size = org.intermedia.view.ScreenResolutionSize.normal; else this.size = org.intermedia.view.ScreenResolutionSize.large;
	$s.pop();
}
org.intermedia.view.ScreenResolution.__name__ = ["org","intermedia","view","ScreenResolution"];
org.intermedia.view.ScreenResolution.prototype = {
	size: null
	,__class__: org.intermedia.view.ScreenResolution
}
if(!cocktail.style) cocktail.style = {}
cocktail.style.FontSizeStyleValue = $hxClasses["cocktail.style.FontSizeStyleValue"] = { __ename__ : ["cocktail","style","FontSizeStyleValue"], __constructs__ : ["length","percentage","absoluteSize","relativeSize"] }
cocktail.style.FontSizeStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.absoluteSize = function(value) { var $x = ["absoluteSize",2,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.relativeSize = function(value) { var $x = ["relativeSize",3,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontWeightStyleValue = $hxClasses["cocktail.style.FontWeightStyleValue"] = { __ename__ : ["cocktail","style","FontWeightStyleValue"], __constructs__ : ["normal","bold"] }
cocktail.style.FontWeightStyleValue.normal = ["normal",0];
cocktail.style.FontWeightStyleValue.normal.toString = $estr;
cocktail.style.FontWeightStyleValue.normal.__enum__ = cocktail.style.FontWeightStyleValue;
cocktail.style.FontWeightStyleValue.bold = ["bold",1];
cocktail.style.FontWeightStyleValue.bold.toString = $estr;
cocktail.style.FontWeightStyleValue.bold.__enum__ = cocktail.style.FontWeightStyleValue;
cocktail.style.FontStyleStyleValue = $hxClasses["cocktail.style.FontStyleStyleValue"] = { __ename__ : ["cocktail","style","FontStyleStyleValue"], __constructs__ : ["normal","italic"] }
cocktail.style.FontStyleStyleValue.normal = ["normal",0];
cocktail.style.FontStyleStyleValue.normal.toString = $estr;
cocktail.style.FontStyleStyleValue.normal.__enum__ = cocktail.style.FontStyleStyleValue;
cocktail.style.FontStyleStyleValue.italic = ["italic",1];
cocktail.style.FontStyleStyleValue.italic.toString = $estr;
cocktail.style.FontStyleStyleValue.italic.__enum__ = cocktail.style.FontStyleStyleValue;
cocktail.style.FontFamilyStyleValue = $hxClasses["cocktail.style.FontFamilyStyleValue"] = { __ename__ : ["cocktail","style","FontFamilyStyleValue"], __constructs__ : ["familyName","genericFamily"] }
cocktail.style.FontFamilyStyleValue.familyName = function(name) { var $x = ["familyName",0,name]; $x.__enum__ = cocktail.style.FontFamilyStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontFamilyStyleValue.genericFamily = function(genericName) { var $x = ["genericFamily",1,genericName]; $x.__enum__ = cocktail.style.FontFamilyStyleValue; $x.toString = $estr; return $x; }
cocktail.style.GenericFontFamilyValue = $hxClasses["cocktail.style.GenericFontFamilyValue"] = { __ename__ : ["cocktail","style","GenericFontFamilyValue"], __constructs__ : ["serif","sansSerif","monospace"] }
cocktail.style.GenericFontFamilyValue.serif = ["serif",0];
cocktail.style.GenericFontFamilyValue.serif.toString = $estr;
cocktail.style.GenericFontFamilyValue.serif.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.GenericFontFamilyValue.sansSerif = ["sansSerif",1];
cocktail.style.GenericFontFamilyValue.sansSerif.toString = $estr;
cocktail.style.GenericFontFamilyValue.sansSerif.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.GenericFontFamilyValue.monospace = ["monospace",2];
cocktail.style.GenericFontFamilyValue.monospace.toString = $estr;
cocktail.style.GenericFontFamilyValue.monospace.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.FontVariantStyleValue = $hxClasses["cocktail.style.FontVariantStyleValue"] = { __ename__ : ["cocktail","style","FontVariantStyleValue"], __constructs__ : ["normal","smallCaps"] }
cocktail.style.FontVariantStyleValue.normal = ["normal",0];
cocktail.style.FontVariantStyleValue.normal.toString = $estr;
cocktail.style.FontVariantStyleValue.normal.__enum__ = cocktail.style.FontVariantStyleValue;
cocktail.style.FontVariantStyleValue.smallCaps = ["smallCaps",1];
cocktail.style.FontVariantStyleValue.smallCaps.toString = $estr;
cocktail.style.FontVariantStyleValue.smallCaps.__enum__ = cocktail.style.FontVariantStyleValue;
cocktail.style.WhiteSpaceStyleValue = $hxClasses["cocktail.style.WhiteSpaceStyleValue"] = { __ename__ : ["cocktail","style","WhiteSpaceStyleValue"], __constructs__ : ["normal","pre","nowrap","preWrap","preLine"] }
cocktail.style.WhiteSpaceStyleValue.normal = ["normal",0];
cocktail.style.WhiteSpaceStyleValue.normal.toString = $estr;
cocktail.style.WhiteSpaceStyleValue.normal.__enum__ = cocktail.style.WhiteSpaceStyleValue;
cocktail.style.WhiteSpaceStyleValue.pre = ["pre",1];
cocktail.style.WhiteSpaceStyleValue.pre.toString = $estr;
cocktail.style.WhiteSpaceStyleValue.pre.__enum__ = cocktail.style.WhiteSpaceStyleValue;
cocktail.style.WhiteSpaceStyleValue.nowrap = ["nowrap",2];
cocktail.style.WhiteSpaceStyleValue.nowrap.toString = $estr;
cocktail.style.WhiteSpaceStyleValue.nowrap.__enum__ = cocktail.style.WhiteSpaceStyleValue;
cocktail.style.WhiteSpaceStyleValue.preWrap = ["preWrap",3];
cocktail.style.WhiteSpaceStyleValue.preWrap.toString = $estr;
cocktail.style.WhiteSpaceStyleValue.preWrap.__enum__ = cocktail.style.WhiteSpaceStyleValue;
cocktail.style.WhiteSpaceStyleValue.preLine = ["preLine",4];
cocktail.style.WhiteSpaceStyleValue.preLine.toString = $estr;
cocktail.style.WhiteSpaceStyleValue.preLine.__enum__ = cocktail.style.WhiteSpaceStyleValue;
cocktail.style.LetterSpacingStyleValue = $hxClasses["cocktail.style.LetterSpacingStyleValue"] = { __ename__ : ["cocktail","style","LetterSpacingStyleValue"], __constructs__ : ["normal","length"] }
cocktail.style.LetterSpacingStyleValue.normal = ["normal",0];
cocktail.style.LetterSpacingStyleValue.normal.toString = $estr;
cocktail.style.LetterSpacingStyleValue.normal.__enum__ = cocktail.style.LetterSpacingStyleValue;
cocktail.style.LetterSpacingStyleValue.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.style.LetterSpacingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.WordSpacingStyleValue = $hxClasses["cocktail.style.WordSpacingStyleValue"] = { __ename__ : ["cocktail","style","WordSpacingStyleValue"], __constructs__ : ["normal","length"] }
cocktail.style.WordSpacingStyleValue.normal = ["normal",0];
cocktail.style.WordSpacingStyleValue.normal.toString = $estr;
cocktail.style.WordSpacingStyleValue.normal.__enum__ = cocktail.style.WordSpacingStyleValue;
cocktail.style.WordSpacingStyleValue.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.style.WordSpacingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextIndentStyleValue = $hxClasses["cocktail.style.TextIndentStyleValue"] = { __ename__ : ["cocktail","style","TextIndentStyleValue"], __constructs__ : ["length","percentage"] }
cocktail.style.TextIndentStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TextIndentStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextIndentStyleValue.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.style.TextIndentStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextAlignStyleValue = $hxClasses["cocktail.style.TextAlignStyleValue"] = { __ename__ : ["cocktail","style","TextAlignStyleValue"], __constructs__ : ["left","right","center","justify"] }
cocktail.style.TextAlignStyleValue.left = ["left",0];
cocktail.style.TextAlignStyleValue.left.toString = $estr;
cocktail.style.TextAlignStyleValue.left.__enum__ = cocktail.style.TextAlignStyleValue;
cocktail.style.TextAlignStyleValue.right = ["right",1];
cocktail.style.TextAlignStyleValue.right.toString = $estr;
cocktail.style.TextAlignStyleValue.right.__enum__ = cocktail.style.TextAlignStyleValue;
cocktail.style.TextAlignStyleValue.center = ["center",2];
cocktail.style.TextAlignStyleValue.center.toString = $estr;
cocktail.style.TextAlignStyleValue.center.__enum__ = cocktail.style.TextAlignStyleValue;
cocktail.style.TextAlignStyleValue.justify = ["justify",3];
cocktail.style.TextAlignStyleValue.justify.toString = $estr;
cocktail.style.TextAlignStyleValue.justify.__enum__ = cocktail.style.TextAlignStyleValue;
cocktail.style.TextTransformStyleValue = $hxClasses["cocktail.style.TextTransformStyleValue"] = { __ename__ : ["cocktail","style","TextTransformStyleValue"], __constructs__ : ["capitalize","uppercase","lowercase","none"] }
cocktail.style.TextTransformStyleValue.capitalize = ["capitalize",0];
cocktail.style.TextTransformStyleValue.capitalize.toString = $estr;
cocktail.style.TextTransformStyleValue.capitalize.__enum__ = cocktail.style.TextTransformStyleValue;
cocktail.style.TextTransformStyleValue.uppercase = ["uppercase",1];
cocktail.style.TextTransformStyleValue.uppercase.toString = $estr;
cocktail.style.TextTransformStyleValue.uppercase.__enum__ = cocktail.style.TextTransformStyleValue;
cocktail.style.TextTransformStyleValue.lowercase = ["lowercase",2];
cocktail.style.TextTransformStyleValue.lowercase.toString = $estr;
cocktail.style.TextTransformStyleValue.lowercase.__enum__ = cocktail.style.TextTransformStyleValue;
cocktail.style.TextTransformStyleValue.none = ["none",3];
cocktail.style.TextTransformStyleValue.none.toString = $estr;
cocktail.style.TextTransformStyleValue.none.__enum__ = cocktail.style.TextTransformStyleValue;
cocktail.style.LineHeightStyleValue = $hxClasses["cocktail.style.LineHeightStyleValue"] = { __ename__ : ["cocktail","style","LineHeightStyleValue"], __constructs__ : ["normal","number","length","percentage"] }
cocktail.style.LineHeightStyleValue.normal = ["normal",0];
cocktail.style.LineHeightStyleValue.normal.toString = $estr;
cocktail.style.LineHeightStyleValue.normal.__enum__ = cocktail.style.LineHeightStyleValue;
cocktail.style.LineHeightStyleValue.number = function(value) { var $x = ["number",1,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.LineHeightStyleValue.length = function(value) { var $x = ["length",2,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.LineHeightStyleValue.percentage = function(value) { var $x = ["percentage",3,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.VerticalAlignStyleValue = $hxClasses["cocktail.style.VerticalAlignStyleValue"] = { __ename__ : ["cocktail","style","VerticalAlignStyleValue"], __constructs__ : ["baseline","sub","superStyle","top","textTop","middle","bottom","textBottom","percent","length"] }
cocktail.style.VerticalAlignStyleValue.baseline = ["baseline",0];
cocktail.style.VerticalAlignStyleValue.baseline.toString = $estr;
cocktail.style.VerticalAlignStyleValue.baseline.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.sub = ["sub",1];
cocktail.style.VerticalAlignStyleValue.sub.toString = $estr;
cocktail.style.VerticalAlignStyleValue.sub.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.superStyle = ["superStyle",2];
cocktail.style.VerticalAlignStyleValue.superStyle.toString = $estr;
cocktail.style.VerticalAlignStyleValue.superStyle.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.top = ["top",3];
cocktail.style.VerticalAlignStyleValue.top.toString = $estr;
cocktail.style.VerticalAlignStyleValue.top.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.textTop = ["textTop",4];
cocktail.style.VerticalAlignStyleValue.textTop.toString = $estr;
cocktail.style.VerticalAlignStyleValue.textTop.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.middle = ["middle",5];
cocktail.style.VerticalAlignStyleValue.middle.toString = $estr;
cocktail.style.VerticalAlignStyleValue.middle.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.bottom = ["bottom",6];
cocktail.style.VerticalAlignStyleValue.bottom.toString = $estr;
cocktail.style.VerticalAlignStyleValue.bottom.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.textBottom = ["textBottom",7];
cocktail.style.VerticalAlignStyleValue.textBottom.toString = $estr;
cocktail.style.VerticalAlignStyleValue.textBottom.__enum__ = cocktail.style.VerticalAlignStyleValue;
cocktail.style.VerticalAlignStyleValue.percent = function(value) { var $x = ["percent",8,value]; $x.__enum__ = cocktail.style.VerticalAlignStyleValue; $x.toString = $estr; return $x; }
cocktail.style.VerticalAlignStyleValue.length = function(value) { var $x = ["length",9,value]; $x.__enum__ = cocktail.style.VerticalAlignStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue = $hxClasses["cocktail.style.MarginStyleValue"] = { __ename__ : ["cocktail","style","MarginStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.MarginStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.autoValue = ["autoValue",2];
cocktail.style.MarginStyleValue.autoValue.toString = $estr;
cocktail.style.MarginStyleValue.autoValue.__enum__ = cocktail.style.MarginStyleValue;
cocktail.style.PaddingStyleValue = $hxClasses["cocktail.style.PaddingStyleValue"] = { __ename__ : ["cocktail","style","PaddingStyleValue"], __constructs__ : ["length","percent"] }
cocktail.style.PaddingStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PaddingStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue = $hxClasses["cocktail.style.DimensionStyleValue"] = { __ename__ : ["cocktail","style","DimensionStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.DimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.autoValue = ["autoValue",2];
cocktail.style.DimensionStyleValue.autoValue.toString = $estr;
cocktail.style.DimensionStyleValue.autoValue.__enum__ = cocktail.style.DimensionStyleValue;
cocktail.style.ConstrainedDimensionStyleValue = $hxClasses["cocktail.style.ConstrainedDimensionStyleValue"] = { __ename__ : ["cocktail","style","ConstrainedDimensionStyleValue"], __constructs__ : ["length","percent","none"] }
cocktail.style.ConstrainedDimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.none = ["none",2];
cocktail.style.ConstrainedDimensionStyleValue.none.toString = $estr;
cocktail.style.ConstrainedDimensionStyleValue.none.__enum__ = cocktail.style.ConstrainedDimensionStyleValue;
cocktail.style.DisplayStyleValue = $hxClasses["cocktail.style.DisplayStyleValue"] = { __ename__ : ["cocktail","style","DisplayStyleValue"], __constructs__ : ["block","inlineBlock","inlineStyle","none"] }
cocktail.style.DisplayStyleValue.block = ["block",0];
cocktail.style.DisplayStyleValue.block.toString = $estr;
cocktail.style.DisplayStyleValue.block.__enum__ = cocktail.style.DisplayStyleValue;
cocktail.style.DisplayStyleValue.inlineBlock = ["inlineBlock",1];
cocktail.style.DisplayStyleValue.inlineBlock.toString = $estr;
cocktail.style.DisplayStyleValue.inlineBlock.__enum__ = cocktail.style.DisplayStyleValue;
cocktail.style.DisplayStyleValue.inlineStyle = ["inlineStyle",2];
cocktail.style.DisplayStyleValue.inlineStyle.toString = $estr;
cocktail.style.DisplayStyleValue.inlineStyle.__enum__ = cocktail.style.DisplayStyleValue;
cocktail.style.DisplayStyleValue.none = ["none",3];
cocktail.style.DisplayStyleValue.none.toString = $estr;
cocktail.style.DisplayStyleValue.none.__enum__ = cocktail.style.DisplayStyleValue;
cocktail.style.FloatStyleValue = $hxClasses["cocktail.style.FloatStyleValue"] = { __ename__ : ["cocktail","style","FloatStyleValue"], __constructs__ : ["left","right","none"] }
cocktail.style.FloatStyleValue.left = ["left",0];
cocktail.style.FloatStyleValue.left.toString = $estr;
cocktail.style.FloatStyleValue.left.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.FloatStyleValue.right = ["right",1];
cocktail.style.FloatStyleValue.right.toString = $estr;
cocktail.style.FloatStyleValue.right.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.FloatStyleValue.none = ["none",2];
cocktail.style.FloatStyleValue.none.toString = $estr;
cocktail.style.FloatStyleValue.none.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.ClearStyleValue = $hxClasses["cocktail.style.ClearStyleValue"] = { __ename__ : ["cocktail","style","ClearStyleValue"], __constructs__ : ["none","left","right","both"] }
cocktail.style.ClearStyleValue.none = ["none",0];
cocktail.style.ClearStyleValue.none.toString = $estr;
cocktail.style.ClearStyleValue.none.__enum__ = cocktail.style.ClearStyleValue;
cocktail.style.ClearStyleValue.left = ["left",1];
cocktail.style.ClearStyleValue.left.toString = $estr;
cocktail.style.ClearStyleValue.left.__enum__ = cocktail.style.ClearStyleValue;
cocktail.style.ClearStyleValue.right = ["right",2];
cocktail.style.ClearStyleValue.right.toString = $estr;
cocktail.style.ClearStyleValue.right.__enum__ = cocktail.style.ClearStyleValue;
cocktail.style.ClearStyleValue.both = ["both",3];
cocktail.style.ClearStyleValue.both.toString = $estr;
cocktail.style.ClearStyleValue.both.__enum__ = cocktail.style.ClearStyleValue;
cocktail.style.PositionStyleValue = $hxClasses["cocktail.style.PositionStyleValue"] = { __ename__ : ["cocktail","style","PositionStyleValue"], __constructs__ : ["staticStyle","relative","absolute","fixed"] }
cocktail.style.PositionStyleValue.staticStyle = ["staticStyle",0];
cocktail.style.PositionStyleValue.staticStyle.toString = $estr;
cocktail.style.PositionStyleValue.staticStyle.__enum__ = cocktail.style.PositionStyleValue;
cocktail.style.PositionStyleValue.relative = ["relative",1];
cocktail.style.PositionStyleValue.relative.toString = $estr;
cocktail.style.PositionStyleValue.relative.__enum__ = cocktail.style.PositionStyleValue;
cocktail.style.PositionStyleValue.absolute = ["absolute",2];
cocktail.style.PositionStyleValue.absolute.toString = $estr;
cocktail.style.PositionStyleValue.absolute.__enum__ = cocktail.style.PositionStyleValue;
cocktail.style.PositionStyleValue.fixed = ["fixed",3];
cocktail.style.PositionStyleValue.fixed.toString = $estr;
cocktail.style.PositionStyleValue.fixed.__enum__ = cocktail.style.PositionStyleValue;
cocktail.style.PositionOffsetStyleValue = $hxClasses["cocktail.style.PositionOffsetStyleValue"] = { __ename__ : ["cocktail","style","PositionOffsetStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.PositionOffsetStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.autoValue = ["autoValue",2];
cocktail.style.PositionOffsetStyleValue.autoValue.toString = $estr;
cocktail.style.PositionOffsetStyleValue.autoValue.__enum__ = cocktail.style.PositionOffsetStyleValue;
cocktail.style.OverflowStyleValue = $hxClasses["cocktail.style.OverflowStyleValue"] = { __ename__ : ["cocktail","style","OverflowStyleValue"], __constructs__ : ["visible","hidden","scroll","autoValue"] }
cocktail.style.OverflowStyleValue.visible = ["visible",0];
cocktail.style.OverflowStyleValue.visible.toString = $estr;
cocktail.style.OverflowStyleValue.visible.__enum__ = cocktail.style.OverflowStyleValue;
cocktail.style.OverflowStyleValue.hidden = ["hidden",1];
cocktail.style.OverflowStyleValue.hidden.toString = $estr;
cocktail.style.OverflowStyleValue.hidden.__enum__ = cocktail.style.OverflowStyleValue;
cocktail.style.OverflowStyleValue.scroll = ["scroll",2];
cocktail.style.OverflowStyleValue.scroll.toString = $estr;
cocktail.style.OverflowStyleValue.scroll.__enum__ = cocktail.style.OverflowStyleValue;
cocktail.style.OverflowStyleValue.autoValue = ["autoValue",3];
cocktail.style.OverflowStyleValue.autoValue.toString = $estr;
cocktail.style.OverflowStyleValue.autoValue.__enum__ = cocktail.style.OverflowStyleValue;
cocktail.style.VisibilityStyleValue = $hxClasses["cocktail.style.VisibilityStyleValue"] = { __ename__ : ["cocktail","style","VisibilityStyleValue"], __constructs__ : ["visible","hidden"] }
cocktail.style.VisibilityStyleValue.visible = ["visible",0];
cocktail.style.VisibilityStyleValue.visible.toString = $estr;
cocktail.style.VisibilityStyleValue.visible.__enum__ = cocktail.style.VisibilityStyleValue;
cocktail.style.VisibilityStyleValue.hidden = ["hidden",1];
cocktail.style.VisibilityStyleValue.hidden.toString = $estr;
cocktail.style.VisibilityStyleValue.hidden.__enum__ = cocktail.style.VisibilityStyleValue;
cocktail.style.OpacityStyleValue = $hxClasses["cocktail.style.OpacityStyleValue"] = { __ename__ : ["cocktail","style","OpacityStyleValue"], __constructs__ : ["number"] }
cocktail.style.OpacityStyleValue.number = function(value) { var $x = ["number",0,value]; $x.__enum__ = cocktail.style.OpacityStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformStyleValue = $hxClasses["cocktail.style.TransformStyleValue"] = { __ename__ : ["cocktail","style","TransformStyleValue"], __constructs__ : ["none","transformFunctions"] }
cocktail.style.TransformStyleValue.none = ["none",0];
cocktail.style.TransformStyleValue.none.toString = $estr;
cocktail.style.TransformStyleValue.none.__enum__ = cocktail.style.TransformStyleValue;
cocktail.style.TransformStyleValue.transformFunctions = function(transformFunctions) { var $x = ["transformFunctions",1,transformFunctions]; $x.__enum__ = cocktail.style.TransformStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue = $hxClasses["cocktail.style.TransformFunctionValue"] = { __ename__ : ["cocktail","style","TransformFunctionValue"], __constructs__ : ["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","skew"] }
cocktail.style.TransformFunctionValue.matrix = function(data) { var $x = ["matrix",0,data]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.translate = function(tx,ty) { var $x = ["translate",1,tx,ty]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.translateX = function(tx) { var $x = ["translateX",2,tx]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.translateY = function(ty) { var $x = ["translateY",3,ty]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.scale = function(sx,sy) { var $x = ["scale",4,sx,sy]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.scaleX = function(sx) { var $x = ["scaleX",5,sx]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.scaleY = function(sy) { var $x = ["scaleY",6,sy]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.rotate = function(angle) { var $x = ["rotate",7,angle]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.skewX = function(angle) { var $x = ["skewX",8,angle]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.skewY = function(angle) { var $x = ["skewY",9,angle]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue.skew = function(angleX,angleY) { var $x = ["skew",10,angleX,angleY]; $x.__enum__ = cocktail.style.TransformFunctionValue; $x.toString = $estr; return $x; }
cocktail.style.TranslationValue = $hxClasses["cocktail.style.TranslationValue"] = { __ename__ : ["cocktail","style","TranslationValue"], __constructs__ : ["length","percent"] }
cocktail.style.TranslationValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TranslationValue; $x.toString = $estr; return $x; }
cocktail.style.TranslationValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.TranslationValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginXStyleValue = $hxClasses["cocktail.style.TransformOriginXStyleValue"] = { __ename__ : ["cocktail","style","TransformOriginXStyleValue"], __constructs__ : ["length","percent","left","center","right"] }
cocktail.style.TransformOriginXStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TransformOriginXStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginXStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.TransformOriginXStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginXStyleValue.left = ["left",2];
cocktail.style.TransformOriginXStyleValue.left.toString = $estr;
cocktail.style.TransformOriginXStyleValue.left.__enum__ = cocktail.style.TransformOriginXStyleValue;
cocktail.style.TransformOriginXStyleValue.center = ["center",3];
cocktail.style.TransformOriginXStyleValue.center.toString = $estr;
cocktail.style.TransformOriginXStyleValue.center.__enum__ = cocktail.style.TransformOriginXStyleValue;
cocktail.style.TransformOriginXStyleValue.right = ["right",4];
cocktail.style.TransformOriginXStyleValue.right.toString = $estr;
cocktail.style.TransformOriginXStyleValue.right.__enum__ = cocktail.style.TransformOriginXStyleValue;
cocktail.style.TransformOriginYStyleValue = $hxClasses["cocktail.style.TransformOriginYStyleValue"] = { __ename__ : ["cocktail","style","TransformOriginYStyleValue"], __constructs__ : ["length","percent","top","center","bottom"] }
cocktail.style.TransformOriginYStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TransformOriginYStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginYStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.TransformOriginYStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginYStyleValue.top = ["top",2];
cocktail.style.TransformOriginYStyleValue.top.toString = $estr;
cocktail.style.TransformOriginYStyleValue.top.__enum__ = cocktail.style.TransformOriginYStyleValue;
cocktail.style.TransformOriginYStyleValue.center = ["center",3];
cocktail.style.TransformOriginYStyleValue.center.toString = $estr;
cocktail.style.TransformOriginYStyleValue.center.__enum__ = cocktail.style.TransformOriginYStyleValue;
cocktail.style.TransformOriginYStyleValue.bottom = ["bottom",4];
cocktail.style.TransformOriginYStyleValue.bottom.toString = $estr;
cocktail.style.TransformOriginYStyleValue.bottom.__enum__ = cocktail.style.TransformOriginYStyleValue;
cocktail.style.BackgroundColorStyleValue = $hxClasses["cocktail.style.BackgroundColorStyleValue"] = { __ename__ : ["cocktail","style","BackgroundColorStyleValue"], __constructs__ : ["colorValue"] }
cocktail.style.BackgroundColorStyleValue.colorValue = function(value) { var $x = ["colorValue",0,value]; $x.__enum__ = cocktail.style.BackgroundColorStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundImageStyleValue = $hxClasses["cocktail.style.BackgroundImageStyleValue"] = { __ename__ : ["cocktail","style","BackgroundImageStyleValue"], __constructs__ : ["none","image"] }
cocktail.style.BackgroundImageStyleValue.none = ["none",0];
cocktail.style.BackgroundImageStyleValue.none.toString = $estr;
cocktail.style.BackgroundImageStyleValue.none.__enum__ = cocktail.style.BackgroundImageStyleValue;
cocktail.style.BackgroundImageStyleValue.image = function(value) { var $x = ["image",1,value]; $x.__enum__ = cocktail.style.BackgroundImageStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundRepeatStyleValue = $hxClasses["cocktail.style.BackgroundRepeatStyleValue"] = { __ename__ : ["cocktail","style","BackgroundRepeatStyleValue"], __constructs__ : ["repeat","space","round","noRepeat"] }
cocktail.style.BackgroundRepeatStyleValue.repeat = ["repeat",0];
cocktail.style.BackgroundRepeatStyleValue.repeat.toString = $estr;
cocktail.style.BackgroundRepeatStyleValue.repeat.__enum__ = cocktail.style.BackgroundRepeatStyleValue;
cocktail.style.BackgroundRepeatStyleValue.space = ["space",1];
cocktail.style.BackgroundRepeatStyleValue.space.toString = $estr;
cocktail.style.BackgroundRepeatStyleValue.space.__enum__ = cocktail.style.BackgroundRepeatStyleValue;
cocktail.style.BackgroundRepeatStyleValue.round = ["round",2];
cocktail.style.BackgroundRepeatStyleValue.round.toString = $estr;
cocktail.style.BackgroundRepeatStyleValue.round.__enum__ = cocktail.style.BackgroundRepeatStyleValue;
cocktail.style.BackgroundRepeatStyleValue.noRepeat = ["noRepeat",3];
cocktail.style.BackgroundRepeatStyleValue.noRepeat.toString = $estr;
cocktail.style.BackgroundRepeatStyleValue.noRepeat.__enum__ = cocktail.style.BackgroundRepeatStyleValue;
cocktail.style.BackgroundPositionXStyleValue = $hxClasses["cocktail.style.BackgroundPositionXStyleValue"] = { __ename__ : ["cocktail","style","BackgroundPositionXStyleValue"], __constructs__ : ["length","percent","left","center","right"] }
cocktail.style.BackgroundPositionXStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.BackgroundPositionXStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundPositionXStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.BackgroundPositionXStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundPositionXStyleValue.left = ["left",2];
cocktail.style.BackgroundPositionXStyleValue.left.toString = $estr;
cocktail.style.BackgroundPositionXStyleValue.left.__enum__ = cocktail.style.BackgroundPositionXStyleValue;
cocktail.style.BackgroundPositionXStyleValue.center = ["center",3];
cocktail.style.BackgroundPositionXStyleValue.center.toString = $estr;
cocktail.style.BackgroundPositionXStyleValue.center.__enum__ = cocktail.style.BackgroundPositionXStyleValue;
cocktail.style.BackgroundPositionXStyleValue.right = ["right",4];
cocktail.style.BackgroundPositionXStyleValue.right.toString = $estr;
cocktail.style.BackgroundPositionXStyleValue.right.__enum__ = cocktail.style.BackgroundPositionXStyleValue;
cocktail.style.BackgroundPositionYStyleValue = $hxClasses["cocktail.style.BackgroundPositionYStyleValue"] = { __ename__ : ["cocktail","style","BackgroundPositionYStyleValue"], __constructs__ : ["length","percent","top","center","bottom"] }
cocktail.style.BackgroundPositionYStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.BackgroundPositionYStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundPositionYStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.BackgroundPositionYStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundPositionYStyleValue.top = ["top",2];
cocktail.style.BackgroundPositionYStyleValue.top.toString = $estr;
cocktail.style.BackgroundPositionYStyleValue.top.__enum__ = cocktail.style.BackgroundPositionYStyleValue;
cocktail.style.BackgroundPositionYStyleValue.center = ["center",3];
cocktail.style.BackgroundPositionYStyleValue.center.toString = $estr;
cocktail.style.BackgroundPositionYStyleValue.center.__enum__ = cocktail.style.BackgroundPositionYStyleValue;
cocktail.style.BackgroundPositionYStyleValue.bottom = ["bottom",4];
cocktail.style.BackgroundPositionYStyleValue.bottom.toString = $estr;
cocktail.style.BackgroundPositionYStyleValue.bottom.__enum__ = cocktail.style.BackgroundPositionYStyleValue;
cocktail.style.BackgroundClipStyleValue = $hxClasses["cocktail.style.BackgroundClipStyleValue"] = { __ename__ : ["cocktail","style","BackgroundClipStyleValue"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.style.BackgroundClipStyleValue.borderBox = ["borderBox",0];
cocktail.style.BackgroundClipStyleValue.borderBox.toString = $estr;
cocktail.style.BackgroundClipStyleValue.borderBox.__enum__ = cocktail.style.BackgroundClipStyleValue;
cocktail.style.BackgroundClipStyleValue.paddingBox = ["paddingBox",1];
cocktail.style.BackgroundClipStyleValue.paddingBox.toString = $estr;
cocktail.style.BackgroundClipStyleValue.paddingBox.__enum__ = cocktail.style.BackgroundClipStyleValue;
cocktail.style.BackgroundClipStyleValue.contentBox = ["contentBox",2];
cocktail.style.BackgroundClipStyleValue.contentBox.toString = $estr;
cocktail.style.BackgroundClipStyleValue.contentBox.__enum__ = cocktail.style.BackgroundClipStyleValue;
cocktail.style.BackgroundOriginStyleValue = $hxClasses["cocktail.style.BackgroundOriginStyleValue"] = { __ename__ : ["cocktail","style","BackgroundOriginStyleValue"], __constructs__ : ["borderBox","paddingBox","contentBox"] }
cocktail.style.BackgroundOriginStyleValue.borderBox = ["borderBox",0];
cocktail.style.BackgroundOriginStyleValue.borderBox.toString = $estr;
cocktail.style.BackgroundOriginStyleValue.borderBox.__enum__ = cocktail.style.BackgroundOriginStyleValue;
cocktail.style.BackgroundOriginStyleValue.paddingBox = ["paddingBox",1];
cocktail.style.BackgroundOriginStyleValue.paddingBox.toString = $estr;
cocktail.style.BackgroundOriginStyleValue.paddingBox.__enum__ = cocktail.style.BackgroundOriginStyleValue;
cocktail.style.BackgroundOriginStyleValue.contentBox = ["contentBox",2];
cocktail.style.BackgroundOriginStyleValue.contentBox.toString = $estr;
cocktail.style.BackgroundOriginStyleValue.contentBox.__enum__ = cocktail.style.BackgroundOriginStyleValue;
cocktail.style.BackgroundSizeStyleValue = $hxClasses["cocktail.style.BackgroundSizeStyleValue"] = { __ename__ : ["cocktail","style","BackgroundSizeStyleValue"], __constructs__ : ["contain","cover","dimensions"] }
cocktail.style.BackgroundSizeStyleValue.contain = ["contain",0];
cocktail.style.BackgroundSizeStyleValue.contain.toString = $estr;
cocktail.style.BackgroundSizeStyleValue.contain.__enum__ = cocktail.style.BackgroundSizeStyleValue;
cocktail.style.BackgroundSizeStyleValue.cover = ["cover",1];
cocktail.style.BackgroundSizeStyleValue.cover.toString = $estr;
cocktail.style.BackgroundSizeStyleValue.cover.__enum__ = cocktail.style.BackgroundSizeStyleValue;
cocktail.style.BackgroundSizeStyleValue.dimensions = function(value) { var $x = ["dimensions",2,value]; $x.__enum__ = cocktail.style.BackgroundSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundSizeStyleDimensionValue = $hxClasses["cocktail.style.BackgroundSizeStyleDimensionValue"] = { __ename__ : ["cocktail","style","BackgroundSizeStyleDimensionValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.BackgroundSizeStyleDimensionValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.BackgroundSizeStyleDimensionValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundSizeStyleDimensionValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.BackgroundSizeStyleDimensionValue; $x.toString = $estr; return $x; }
cocktail.style.BackgroundSizeStyleDimensionValue.autoValue = ["autoValue",2];
cocktail.style.BackgroundSizeStyleDimensionValue.autoValue.toString = $estr;
cocktail.style.BackgroundSizeStyleDimensionValue.autoValue.__enum__ = cocktail.style.BackgroundSizeStyleDimensionValue;
var Std = $hxClasses["Std"] = function() { }
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
Std.prototype = {
	__class__: Std
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	measurePositionOffsets: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::measurePositionOffsets");
		var $spos = $s.length;
		this.measureHorizontalPositionOffsets(style,containingDOMElementData);
		this.measureVerticalPositionOffsets(style,containingDOMElementData);
		$s.pop();
	}
	,measureHorizontalPositionOffsets: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::measureHorizontalPositionOffsets");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue || style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
			if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginLeft = 0;
			if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginRight = 0;
			if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedStaticLeft(style,containingDOMElementData);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			} else if(style.getLeft() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().left = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			} else if(style.getRight() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().right = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		} else {
			style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue && style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) {
				var margin = Math.round((containingDOMElementData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight) / 2);
				var computedMargin = Math.round((containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginLeft = computedMargin;
					style.getComputedStyle().marginRight = computedMargin;
				} else {
					style.getComputedStyle().marginLeft = 0;
					style.getComputedStyle().marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			} else if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginLeft = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight; else if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
		}
		$s.pop();
	}
	,measureVerticalPositionOffsets: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::measureVerticalPositionOffsets");
		var $spos = $s.length;
		var computedStyle = style.getComputedStyle();
		if(style.getTop() == cocktail.style.PositionOffsetStyleValue.autoValue || style.getBottom() == cocktail.style.PositionOffsetStyleValue.autoValue) {
			if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = 0;
			if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = 0;
			if(style.getTop() == cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().top = this.getComputedStaticTop(style,containingDOMElementData);
				style.getComputedStyle().bottom = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			} else if(style.getTop() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().top = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else if(style.getBottom() == cocktail.style.PositionOffsetStyleValue.autoValue) {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			} else {
				style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
				style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			}
		} else {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue && style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) {
				var margin = Math.round((containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2);
				var computedMargin = Math.round((containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				if(computedMargin >= 0) {
					style.getComputedStyle().marginTop = computedMargin;
					style.getComputedStyle().marginBottom = computedMargin;
				} else {
					style.getComputedStyle().marginTop = 0;
					style.getComputedStyle().marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			} else if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom; else if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
		}
		$s.pop();
	}
	,getComputedStaticLeft: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::getComputedStaticLeft");
		var $spos = $s.length;
		var $tmp = style.getComputedStyle().marginLeft;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedStaticTop: function(style,containingDOMElementData) {
		$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::getComputedStaticTop");
		var $spos = $s.length;
		var $tmp = style.getComputedStyle().marginTop;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer
});
org.intermedia.model.XmlLoader = $hxClasses["org.intermedia.model.XmlLoader"] = function(xmlUrl,online,successCallback,errorCallback) {
	$s.push("org.intermedia.model.XmlLoader::new");
	var $spos = $s.length;
	this._online = online;
	this.onLoadSuccess = successCallback;
	this.onLoadError = errorCallback;
	this.loadXmlFeed(xmlUrl);
	$s.pop();
}
org.intermedia.model.XmlLoader.__name__ = ["org","intermedia","model","XmlLoader"];
org.intermedia.model.XmlLoader.prototype = {
	onLoadSuccess: null
	,onLoadError: null
	,_online: null
	,loadXmlFeed: function(xmlUrl) {
		$s.push("org.intermedia.model.XmlLoader::loadXmlFeed");
		var $spos = $s.length;
		var fullUrl = "";
		if(!this._online) fullUrl = xmlUrl; else fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);
		try {
			cocktail.resource.ResourceLoaderManager.loadString(fullUrl,this.onXmlLoaded.$bind(this),this.onXmlError.$bind(this));
		} catch( error ) {
			$e = [];
			while($s.length >= $spos) $e.unshift($s.pop());
			$s.push($e[0]);
			this.onXmlError(error);
		}
		$s.pop();
	}
	,onXmlError: function(error) {
		$s.push("org.intermedia.model.XmlLoader::onXmlError");
		var $spos = $s.length;
		if(this.onLoadError != null) this.onLoadError(error);
		$s.pop();
	}
	,onXmlLoaded: function(xmlString) {
		$s.push("org.intermedia.model.XmlLoader::onXmlLoaded");
		var $spos = $s.length;
		var xml = Xml.parse(xmlString);
		if(this.onLoadSuccess != null) this.onLoadSuccess(xml);
		$s.pop();
	}
	,__class__: org.intermedia.model.XmlLoader
}
haxe.Timer = $hxClasses["haxe.Timer"] = function(time_ms) {
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
haxe.Timer.prototype = {
	id: null
	,timerId: null
	,stop: function() {
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
	,run: function() {
		$s.push("haxe.Timer::run");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: haxe.Timer
}
org.intermedia.view.Constants = $hxClasses["org.intermedia.view.Constants"] = function() { }
org.intermedia.view.Constants.__name__ = ["org","intermedia","view","Constants"];
org.intermedia.view.Constants.prototype = {
	__class__: org.intermedia.view.Constants
}
if(!cocktail.unit) cocktail.unit = {}
cocktail.unit.LengthValue = $hxClasses["cocktail.unit.LengthValue"] = { __ename__ : ["cocktail","unit","LengthValue"], __constructs__ : ["px","cm","mm","pt","pc","_in","em","ex"] }
cocktail.unit.LengthValue.px = function(value) { var $x = ["px",0,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.cm = function(value) { var $x = ["cm",1,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.mm = function(value) { var $x = ["mm",2,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.pt = function(value) { var $x = ["pt",3,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.pc = function(value) { var $x = ["pc",4,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue._in = function(value) { var $x = ["_in",5,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.em = function(value) { var $x = ["em",6,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.ex = function(value) { var $x = ["ex",7,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.FontSizeAbsoluteSizeValue = $hxClasses["cocktail.unit.FontSizeAbsoluteSizeValue"] = { __ename__ : ["cocktail","unit","FontSizeAbsoluteSizeValue"], __constructs__ : ["xxSmall","xSmall","small","medium","large","xLarge","xxLarge"] }
cocktail.unit.FontSizeAbsoluteSizeValue.xxSmall = ["xxSmall",0];
cocktail.unit.FontSizeAbsoluteSizeValue.xxSmall.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.xxSmall.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.xSmall = ["xSmall",1];
cocktail.unit.FontSizeAbsoluteSizeValue.xSmall.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.xSmall.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.small = ["small",2];
cocktail.unit.FontSizeAbsoluteSizeValue.small.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.small.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.medium = ["medium",3];
cocktail.unit.FontSizeAbsoluteSizeValue.medium.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.medium.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.large = ["large",4];
cocktail.unit.FontSizeAbsoluteSizeValue.large.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.large.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.xLarge = ["xLarge",5];
cocktail.unit.FontSizeAbsoluteSizeValue.xLarge.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.xLarge.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeAbsoluteSizeValue.xxLarge = ["xxLarge",6];
cocktail.unit.FontSizeAbsoluteSizeValue.xxLarge.toString = $estr;
cocktail.unit.FontSizeAbsoluteSizeValue.xxLarge.__enum__ = cocktail.unit.FontSizeAbsoluteSizeValue;
cocktail.unit.FontSizeRelativeSizeValue = $hxClasses["cocktail.unit.FontSizeRelativeSizeValue"] = { __ename__ : ["cocktail","unit","FontSizeRelativeSizeValue"], __constructs__ : ["larger","smaller"] }
cocktail.unit.FontSizeRelativeSizeValue.larger = ["larger",0];
cocktail.unit.FontSizeRelativeSizeValue.larger.toString = $estr;
cocktail.unit.FontSizeRelativeSizeValue.larger.__enum__ = cocktail.unit.FontSizeRelativeSizeValue;
cocktail.unit.FontSizeRelativeSizeValue.smaller = ["smaller",1];
cocktail.unit.FontSizeRelativeSizeValue.smaller.toString = $estr;
cocktail.unit.FontSizeRelativeSizeValue.smaller.__enum__ = cocktail.unit.FontSizeRelativeSizeValue;
cocktail.unit.ColorValue = $hxClasses["cocktail.unit.ColorValue"] = { __ename__ : ["cocktail","unit","ColorValue"], __constructs__ : ["rgb","rgba","hex","keyword","transparent"] }
cocktail.unit.ColorValue.rgb = function(red,green,blue) { var $x = ["rgb",0,red,green,blue]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.rgba = function(red,green,blue,alpha) { var $x = ["rgba",1,red,green,blue,alpha]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.hex = function(value) { var $x = ["hex",2,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.keyword = function(value) { var $x = ["keyword",3,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.transparent = ["transparent",4];
cocktail.unit.ColorValue.transparent.toString = $estr;
cocktail.unit.ColorValue.transparent.__enum__ = cocktail.unit.ColorValue;
cocktail.unit.ImageValue = $hxClasses["cocktail.unit.ImageValue"] = { __ename__ : ["cocktail","unit","ImageValue"], __constructs__ : ["url","imageList","gradient"] }
cocktail.unit.ImageValue.url = function(value) { var $x = ["url",0,value]; $x.__enum__ = cocktail.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.unit.ImageValue.imageList = function(value) { var $x = ["imageList",1,value]; $x.__enum__ = cocktail.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.unit.ImageValue.gradient = function(value) { var $x = ["gradient",2,value]; $x.__enum__ = cocktail.unit.ImageValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientValue = $hxClasses["cocktail.unit.GradientValue"] = { __ename__ : ["cocktail","unit","GradientValue"], __constructs__ : ["linear"] }
cocktail.unit.GradientValue.linear = function(value) { var $x = ["linear",0,value]; $x.__enum__ = cocktail.unit.GradientValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientStopValue = $hxClasses["cocktail.unit.GradientStopValue"] = { __ename__ : ["cocktail","unit","GradientStopValue"], __constructs__ : ["length","percent"] }
cocktail.unit.GradientStopValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientStopValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.unit.GradientStopValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientAngleValue = $hxClasses["cocktail.unit.GradientAngleValue"] = { __ename__ : ["cocktail","unit","GradientAngleValue"], __constructs__ : ["angle","side","corner"] }
cocktail.unit.GradientAngleValue.angle = function(value) { var $x = ["angle",0,value]; $x.__enum__ = cocktail.unit.GradientAngleValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientAngleValue.side = function(value) { var $x = ["side",1,value]; $x.__enum__ = cocktail.unit.GradientAngleValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientAngleValue.corner = function(value) { var $x = ["corner",2,value]; $x.__enum__ = cocktail.unit.GradientAngleValue; $x.toString = $estr; return $x; }
cocktail.unit.GradientSideValue = $hxClasses["cocktail.unit.GradientSideValue"] = { __ename__ : ["cocktail","unit","GradientSideValue"], __constructs__ : ["top","left","bottom","right"] }
cocktail.unit.GradientSideValue.top = ["top",0];
cocktail.unit.GradientSideValue.top.toString = $estr;
cocktail.unit.GradientSideValue.top.__enum__ = cocktail.unit.GradientSideValue;
cocktail.unit.GradientSideValue.left = ["left",1];
cocktail.unit.GradientSideValue.left.toString = $estr;
cocktail.unit.GradientSideValue.left.__enum__ = cocktail.unit.GradientSideValue;
cocktail.unit.GradientSideValue.bottom = ["bottom",2];
cocktail.unit.GradientSideValue.bottom.toString = $estr;
cocktail.unit.GradientSideValue.bottom.__enum__ = cocktail.unit.GradientSideValue;
cocktail.unit.GradientSideValue.right = ["right",3];
cocktail.unit.GradientSideValue.right.toString = $estr;
cocktail.unit.GradientSideValue.right.__enum__ = cocktail.unit.GradientSideValue;
cocktail.unit.GradientCornerValue = $hxClasses["cocktail.unit.GradientCornerValue"] = { __ename__ : ["cocktail","unit","GradientCornerValue"], __constructs__ : ["topRight","bottomRight","bottomLeft","topLeft"] }
cocktail.unit.GradientCornerValue.topRight = ["topRight",0];
cocktail.unit.GradientCornerValue.topRight.toString = $estr;
cocktail.unit.GradientCornerValue.topRight.__enum__ = cocktail.unit.GradientCornerValue;
cocktail.unit.GradientCornerValue.bottomRight = ["bottomRight",1];
cocktail.unit.GradientCornerValue.bottomRight.toString = $estr;
cocktail.unit.GradientCornerValue.bottomRight.__enum__ = cocktail.unit.GradientCornerValue;
cocktail.unit.GradientCornerValue.bottomLeft = ["bottomLeft",2];
cocktail.unit.GradientCornerValue.bottomLeft.toString = $estr;
cocktail.unit.GradientCornerValue.bottomLeft.__enum__ = cocktail.unit.GradientCornerValue;
cocktail.unit.GradientCornerValue.topLeft = ["topLeft",3];
cocktail.unit.GradientCornerValue.topLeft.toString = $estr;
cocktail.unit.GradientCornerValue.topLeft.__enum__ = cocktail.unit.GradientCornerValue;
cocktail.unit.ColorKeywordValue = $hxClasses["cocktail.unit.ColorKeywordValue"] = { __ename__ : ["cocktail","unit","ColorKeywordValue"], __constructs__ : ["aqua","black","blue","fuchsia","gray","green","lime","maroon","navy","olive","orange","purple","red","silver","teal","white","yellow"] }
cocktail.unit.ColorKeywordValue.aqua = ["aqua",0];
cocktail.unit.ColorKeywordValue.aqua.toString = $estr;
cocktail.unit.ColorKeywordValue.aqua.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.black = ["black",1];
cocktail.unit.ColorKeywordValue.black.toString = $estr;
cocktail.unit.ColorKeywordValue.black.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.blue = ["blue",2];
cocktail.unit.ColorKeywordValue.blue.toString = $estr;
cocktail.unit.ColorKeywordValue.blue.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.fuchsia = ["fuchsia",3];
cocktail.unit.ColorKeywordValue.fuchsia.toString = $estr;
cocktail.unit.ColorKeywordValue.fuchsia.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.gray = ["gray",4];
cocktail.unit.ColorKeywordValue.gray.toString = $estr;
cocktail.unit.ColorKeywordValue.gray.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.green = ["green",5];
cocktail.unit.ColorKeywordValue.green.toString = $estr;
cocktail.unit.ColorKeywordValue.green.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.lime = ["lime",6];
cocktail.unit.ColorKeywordValue.lime.toString = $estr;
cocktail.unit.ColorKeywordValue.lime.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.maroon = ["maroon",7];
cocktail.unit.ColorKeywordValue.maroon.toString = $estr;
cocktail.unit.ColorKeywordValue.maroon.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.navy = ["navy",8];
cocktail.unit.ColorKeywordValue.navy.toString = $estr;
cocktail.unit.ColorKeywordValue.navy.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.olive = ["olive",9];
cocktail.unit.ColorKeywordValue.olive.toString = $estr;
cocktail.unit.ColorKeywordValue.olive.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.orange = ["orange",10];
cocktail.unit.ColorKeywordValue.orange.toString = $estr;
cocktail.unit.ColorKeywordValue.orange.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.purple = ["purple",11];
cocktail.unit.ColorKeywordValue.purple.toString = $estr;
cocktail.unit.ColorKeywordValue.purple.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.red = ["red",12];
cocktail.unit.ColorKeywordValue.red.toString = $estr;
cocktail.unit.ColorKeywordValue.red.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.silver = ["silver",13];
cocktail.unit.ColorKeywordValue.silver.toString = $estr;
cocktail.unit.ColorKeywordValue.silver.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.teal = ["teal",14];
cocktail.unit.ColorKeywordValue.teal.toString = $estr;
cocktail.unit.ColorKeywordValue.teal.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.white = ["white",15];
cocktail.unit.ColorKeywordValue.white.toString = $estr;
cocktail.unit.ColorKeywordValue.white.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.ColorKeywordValue.yellow = ["yellow",16];
cocktail.unit.ColorKeywordValue.yellow.toString = $estr;
cocktail.unit.ColorKeywordValue.yellow.__enum__ = cocktail.unit.ColorKeywordValue;
cocktail.unit.AngleValue = $hxClasses["cocktail.unit.AngleValue"] = { __ename__ : ["cocktail","unit","AngleValue"], __constructs__ : ["deg","grad","rad","turn"] }
cocktail.unit.AngleValue.deg = function(value) { var $x = ["deg",0,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.grad = function(value) { var $x = ["grad",1,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.rad = function(value) { var $x = ["rad",2,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.turn = function(value) { var $x = ["turn",3,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
org.intermedia.view.SwippableListViewStyle = $hxClasses["org.intermedia.view.SwippableListViewStyle"] = function() { }
org.intermedia.view.SwippableListViewStyle.__name__ = ["org","intermedia","view","SwippableListViewStyle"];
org.intermedia.view.SwippableListViewStyle.setListStyle = function(domElement) {
	$s.push("org.intermedia.view.SwippableListViewStyle::setListStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
org.intermedia.view.SwippableListViewStyle.setContainerStyle = function(domElement) {
	$s.push("org.intermedia.view.SwippableListViewStyle::setContainerStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	$s.pop();
}
org.intermedia.view.SwippableListViewStyle.prototype = {
	__class__: org.intermedia.view.SwippableListViewStyle
}
haxe.FastCell = $hxClasses["haxe.FastCell"] = function(elt,next) {
	$s.push("haxe.FastCell::new");
	var $spos = $s.length;
	this.elt = elt;
	this.next = next;
	$s.pop();
}
haxe.FastCell.__name__ = ["haxe","FastCell"];
haxe.FastCell.prototype = {
	elt: null
	,next: null
	,__class__: haxe.FastCell
}
haxe.FastList = $hxClasses["haxe.FastList"] = function() {
	$s.push("haxe.FastList::new");
	var $spos = $s.length;
	$s.pop();
}
haxe.FastList.__name__ = ["haxe","FastList"];
haxe.FastList.prototype = {
	head: null
	,add: function(item) {
		$s.push("haxe.FastList::add");
		var $spos = $s.length;
		this.head = new haxe.FastCell(item,this.head);
		$s.pop();
	}
	,first: function() {
		$s.push("haxe.FastList::first");
		var $spos = $s.length;
		var $tmp = this.head == null?null:this.head.elt;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,pop: function() {
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
	,isEmpty: function() {
		$s.push("haxe.FastList::isEmpty");
		var $spos = $s.length;
		var $tmp = this.head == null;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,remove: function(v) {
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
	,iterator: function() {
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
	,toString: function() {
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
	,__class__: haxe.FastList
}
if(!cocktailCore.drawing.js) cocktailCore.drawing.js = {}
cocktailCore.drawing.js.DrawingManager = $hxClasses["cocktailCore.drawing.js.DrawingManager"] = function(nativeElement,width,height) {
	$s.push("cocktailCore.drawing.js.DrawingManager::new");
	var $spos = $s.length;
	cocktailCore.drawing.abstract.AbstractDrawingManager.call(this,nativeElement,width,height);
	$s.pop();
}
cocktailCore.drawing.js.DrawingManager.__name__ = ["cocktailCore","drawing","js","DrawingManager"];
cocktailCore.drawing.js.DrawingManager.__super__ = cocktailCore.drawing.abstract.AbstractDrawingManager;
cocktailCore.drawing.js.DrawingManager.prototype = $extend(cocktailCore.drawing.abstract.AbstractDrawingManager.prototype,{
	beginFill: function(fillStyle,lineStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::beginFill");
		var $spos = $s.length;
		cocktailCore.drawing.abstract.AbstractDrawingManager.prototype.beginFill.call(this,fillStyle,lineStyle);
		var canvasContext = this.getContext();
		canvasContext.beginPath();
		$s.pop();
	}
	,endFill: function() {
		$s.push("cocktailCore.drawing.js.DrawingManager::endFill");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.closePath();
		canvasContext.fill();
		canvasContext.stroke();
		$s.pop();
	}
	,clear: function() {
		$s.push("cocktailCore.drawing.js.DrawingManager::clear");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.clearRect(0,0,this.getWidth(),this.getHeight());
		$s.pop();
	}
	,setFillStyle: function(fillStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::setFillStyle");
		var $spos = $s.length;
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
			var repeat = $e[3], imageDOMElement = $e[2];
			canvasContext.fillStyle = this.getCanvasPattern(imageDOMElement,repeat);
			break;
		}
		$s.pop();
	}
	,setLineStyle: function(lineStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::setLineStyle");
		var $spos = $s.length;
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
			var repeat = $e[4], lineStyleData = $e[3], imageDOMElement = $e[2];
			this.initLineStyle(lineStyleData);
			canvasContext.strokeStyle = this.getCanvasPattern(imageDOMElement,repeat);
			break;
		}
		$s.pop();
	}
	,drawImage: function(source,matrix,sourceRect) {
		$s.push("cocktailCore.drawing.js.DrawingManager::drawImage");
		var $spos = $s.length;
		if(matrix == null) matrix = new cocktail.geom.Matrix();
		if(sourceRect == null) {
			var width = source.width;
			var height = source.height;
			sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
		}
		var canvasContext = this.getContext();
		$s.pop();
	}
	,lineTo: function(x,y) {
		$s.push("cocktailCore.drawing.js.DrawingManager::lineTo");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.lineTo(x,y);
		$s.pop();
	}
	,moveTo: function(x,y) {
		$s.push("cocktailCore.drawing.js.DrawingManager::moveTo");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.moveTo(x,y);
		$s.pop();
	}
	,curveTo: function(controlX,controlY,x,y) {
		$s.push("cocktailCore.drawing.js.DrawingManager::curveTo");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.quadraticCurveTo(controlX,controlY,x,y);
		$s.pop();
	}
	,toNativeAlpha: function(genericAlpha) {
		$s.push("cocktailCore.drawing.js.DrawingManager::toNativeAlpha");
		var $spos = $s.length;
		$s.pop();
		return genericAlpha;
		$s.pop();
	}
	,toNativeRatio: function(genericRatio) {
		$s.push("cocktailCore.drawing.js.DrawingManager::toNativeRatio");
		var $spos = $s.length;
		var $tmp = genericRatio * 0.01;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,toNativeCapStyle: function(genericCapStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::toNativeCapStyle");
		var $spos = $s.length;
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
		$s.pop();
		return capStyle;
		$s.pop();
	}
	,toNativeJointStyle: function(genericJointStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::toNativeJointStyle");
		var $spos = $s.length;
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
		$s.pop();
		return jointStyle;
		$s.pop();
	}
	,colorStopToRGBA: function(colorStop) {
		$s.push("cocktailCore.drawing.js.DrawingManager::colorStopToRGBA");
		var $spos = $s.length;
		var rgb = this.hexToRGB(this.getHexColor(colorStop.color));
		var $tmp = "rgba(" + rgb.red + "," + rgb.green + "," + rgb.blue + "," + this.toNativeAlpha(colorStop.alpha) + ")";
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getHexColor: function(color) {
		$s.push("cocktailCore.drawing.js.DrawingManager::getHexColor");
		var $spos = $s.length;
		var hexColor = StringTools.hex(color);
		while(hexColor.length < 6) hexColor = "0" + hexColor;
		var $tmp = "#" + hexColor;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,hexToRGB: function(hex) {
		$s.push("cocktailCore.drawing.js.DrawingManager::hexToRGB");
		var $spos = $s.length;
		var hexCopy = hex;
		var hexCopy1 = hexCopy.substr(1);
		var rgb = { red : Std.parseInt("0x" + hexCopy1.substr(0,2)), green : Std.parseInt("0x" + hexCopy1.substr(2,2)), blue : Std.parseInt("0x" + hexCopy1.substr(4,2))};
		$s.pop();
		return rgb;
		$s.pop();
	}
	,initLineStyle: function(lineStyleData) {
		$s.push("cocktailCore.drawing.js.DrawingManager::initLineStyle");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		canvasContext.lineWidth = lineStyleData.thickness;
		canvasContext.lineCap = this.toNativeCapStyle(lineStyleData.capStyle);
		canvasContext.lineJoin = this.toNativeJointStyle(lineStyleData.jointStyle);
		canvasContext.miterLimit = lineStyleData.miterLimit;
		$s.pop();
	}
	,getContext: function() {
		$s.push("cocktailCore.drawing.js.DrawingManager::getContext");
		var $spos = $s.length;
		var $tmp = this._nativeElement.getContext("2d");
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getCanvasPattern: function(imageDOMElement,repeat) {
		$s.push("cocktailCore.drawing.js.DrawingManager::getCanvasPattern");
		var $spos = $s.length;
		var canvasContext = this.getContext();
		var repeatValue = "";
		if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
		var $tmp = canvasContext.createPattern(imageDOMElement.getNativeElement(),repeatValue);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getGradient: function(gradientStyle) {
		$s.push("cocktailCore.drawing.js.DrawingManager::getGradient");
		var $spos = $s.length;
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
		$s.pop();
		return gradient;
		$s.pop();
	}
	,setWidth: function(value) {
		$s.push("cocktailCore.drawing.js.DrawingManager::setWidth");
		var $spos = $s.length;
		this.clear();
		cocktailCore.drawing.abstract.AbstractDrawingManager.prototype.setWidth.call(this,value);
		var $tmp = this._width = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setHeight: function(value) {
		$s.push("cocktailCore.drawing.js.DrawingManager::setHeight");
		var $spos = $s.length;
		this.clear();
		cocktailCore.drawing.abstract.AbstractDrawingManager.prototype.setHeight.call(this,value);
		var $tmp = this._height = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.drawing.js.DrawingManager
});
if(!cocktailCore.background) cocktailCore.background = {}
cocktailCore.background.BackgroundDrawingManager = $hxClasses["cocktailCore.background.BackgroundDrawingManager"] = function(nativeElement,backgroundBox) {
	$s.push("cocktailCore.background.BackgroundDrawingManager::new");
	var $spos = $s.length;
	cocktailCore.drawing.js.DrawingManager.call(this,nativeElement,Math.round(backgroundBox.width),Math.round(backgroundBox.height));
	$s.pop();
}
cocktailCore.background.BackgroundDrawingManager.__name__ = ["cocktailCore","background","BackgroundDrawingManager"];
cocktailCore.background.BackgroundDrawingManager.__super__ = cocktailCore.drawing.js.DrawingManager;
cocktailCore.background.BackgroundDrawingManager.prototype = $extend(cocktailCore.drawing.js.DrawingManager.prototype,{
	drawBackgroundImage: function(nativeImage,backgroundPositioningBox,backgroundPaintingBox,intrinsicWidth,intrinsicHeight,intrinsicRatio,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
		$s.push("cocktailCore.background.BackgroundDrawingManager::drawBackgroundImage");
		var $spos = $s.length;
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
			var matrix = new cocktail.geom.Matrix();
			matrix.translate(totalWidth,totalHeight);
			matrix.scale(imageWidth / intrinsicWidth,imageHeight / intrinsicHeight,{ x : 0.0, y : 0.0});
			this.drawImage(nativeImage,matrix,backgroundPaintingBox);
			totalWidth += imageWidth;
			if(totalWidth >= maxWidth) {
				totalWidth = initialWidth;
				totalHeight += imageHeight;
			}
		}
		$s.pop();
	}
	,drawBackgroundColor: function(color,backgroundPaintingBox) {
		$s.push("cocktailCore.background.BackgroundDrawingManager::drawBackgroundColor");
		var $spos = $s.length;
		var fillStyle = cocktail.domElement.FillStyleValue.monochrome(color);
		var lineStyle = cocktail.domElement.LineStyleValue.none;
		this.beginFill(fillStyle,lineStyle);
		this.drawRect(Math.round(backgroundPaintingBox.x),Math.round(backgroundPaintingBox.y),Math.round(backgroundPaintingBox.width),Math.round(backgroundPaintingBox.height));
		this.endFill();
		$s.pop();
	}
	,drawBackgroundGradient: function(gradient,backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat) {
		$s.push("cocktailCore.background.BackgroundDrawingManager::drawBackgroundGradient");
		var $spos = $s.length;
		var gradientSurface = new cocktailCore.drawing.js.DrawingManager(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic),computedBackgroundSize.width,computedBackgroundSize.height);
		var fillStyle;
		var lineStyle = cocktail.domElement.LineStyleValue.none;
		var $e = (gradient);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			var gradientStyle = { gradientType : cocktail.domElement.GradientTypeValue.linear, gradientStops : this.getGradientStops(value.colorStops), rotation : this.getRotation(value.angle)};
			fillStyle = cocktail.domElement.FillStyleValue.gradient(gradientStyle);
			break;
		}
		gradientSurface.beginFill(fillStyle,lineStyle);
		gradientSurface.drawRect(0,0,computedBackgroundSize.width,computedBackgroundSize.height);
		gradientSurface.endFill();
		this.drawBackgroundImage(gradientSurface.getNativeElement(),backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize.width,computedBackgroundSize.height,computedBackgroundSize.width / computedBackgroundSize.height,computedBackgroundSize,computedBackgroundPosition,backgroundRepeat);
		$s.pop();
	}
	,getGradientStops: function(value) {
		$s.push("cocktailCore.background.BackgroundDrawingManager::getGradientStops");
		var $spos = $s.length;
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
			var color = cocktailCore.unit.UnitManager.getColorDataFromColorValue(value[i].color);
			gradientStopsData.push({ colorStop : color, ratio : ratio});
		}
		$s.pop();
		return gradientStopsData;
		$s.pop();
	}
	,getRotation: function(value) {
		$s.push("cocktailCore.background.BackgroundDrawingManager::getRotation");
		var $spos = $s.length;
		var rotation;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			rotation = Math.round(cocktailCore.unit.UnitManager.getDegreeFromAngleValue(value1));
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
		$s.pop();
		return rotation;
		$s.pop();
	}
	,__class__: cocktailCore.background.BackgroundDrawingManager
});
org.intermedia.view.CellThumb = $hxClasses["org.intermedia.view.CellThumb"] = function(cellPerLine) {
	$s.push("org.intermedia.view.CellThumb::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	org.intermedia.view.CellBase.call(this);
	this.initCellStyle();
	this._cellStyle.cell(this,cellPerLine);
	$s.pop();
}
org.intermedia.view.CellThumb.__name__ = ["org","intermedia","view","CellThumb"];
org.intermedia.view.CellThumb.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellThumb.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	_cellStyle: null
	,initCellStyle: function() {
		$s.push("org.intermedia.view.CellThumb::initCellStyle");
		var $spos = $s.length;
		this._cellStyle = { cell : org.intermedia.view.CellThumbStyle.setCellStyle, thumbnail : org.intermedia.view.CellThumbStyle.setThumbnailStyle, textBlock : org.intermedia.view.CellThumbText1Style.setTextBlockStyle, title : org.intermedia.view.CellThumbText1Style.setTitleStyle, author : org.intermedia.view.CellThumbText1Style.setAuthorStyle, line : org.intermedia.view.CellThumbText1Style.setLineStyle};
		$s.pop();
	}
	,updateView: function() {
		$s.push("org.intermedia.view.CellThumb::updateView");
		var $spos = $s.length;
		var cellData = this._data;
		if(cellData.thumbUrl != "" && cellData.thumbUrl != null) {
			var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
			this._cellStyle.thumbnail(cellImage);
			this.addChild(cellImage);
			cellImage.load(cellData.thumbUrl);
		}
		$s.pop();
	}
	,__class__: org.intermedia.view.CellThumb
});
cocktailCore.resource.js.LibraryLoader = $hxClasses["cocktailCore.resource.js.LibraryLoader"] = function() {
	$s.push("cocktailCore.resource.js.LibraryLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractLibraryLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.LibraryLoader.__name__ = ["cocktailCore","resource","js","LibraryLoader"];
cocktailCore.resource.js.LibraryLoader.__super__ = cocktailCore.resource.abstract.AbstractLibraryLoader;
cocktailCore.resource.js.LibraryLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractLibraryLoader.prototype,{
	doLoad: function(url) {
		$s.push("cocktailCore.resource.js.LibraryLoader::doLoad");
		var $spos = $s.length;
		this._nativeElement.setAttribute("type","text/javascript");
		this._nativeElement.setAttribute("language","JavaScript");
		js.Lib.document.getElementsByTagName("head")[0].appendChild(this._nativeElement);
		cocktailCore.resource.abstract.AbstractLibraryLoader.prototype.doLoad.call(this,url);
		$s.pop();
	}
	,__class__: cocktailCore.resource.js.LibraryLoader
});
if(!cocktailCore.mouse) cocktailCore.mouse = {}
if(!cocktailCore.mouse["abstract"]) cocktailCore.mouse["abstract"] = {}
cocktailCore.mouse.abstract.AbstractMouse = $hxClasses["cocktailCore.mouse.abstract.AbstractMouse"] = function(nativeElement) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::new");
	var $spos = $s.length;
	this._nativeElement = nativeElement;
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.__name__ = ["cocktailCore","mouse","abstract","AbstractMouse"];
cocktailCore.mouse.abstract.AbstractMouse.prototype = {
	_onMouseDown: null
	,onMouseDown: null
	,_onMouseUp: null
	,onMouseUp: null
	,_onMouseOver: null
	,onMouseOver: null
	,_onMouseOut: null
	,onMouseOut: null
	,_onMouseMove: null
	,onMouseMove: null
	,_onMouseDoubleClick: null
	,onMouseDoubleClick: null
	,_mouseDownEvent: null
	,_mouseUpEvent: null
	,_mouseOverEvent: null
	,_mouseOutEvent: null
	,_mouseMoveEvent: null
	,_mouseDoubleClickEvent: null
	,_nativeElement: null
	,onNativeMouseDown: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseDown");
		var $spos = $s.length;
		if(this.getOnMouseDown() != null) (this.getOnMouseDown())(this.getMouseData(event));
		$s.pop();
	}
	,onNativeMouseUp: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseUp");
		var $spos = $s.length;
		if(this.getOnMouseUp() != null) (this.getOnMouseUp())(this.getMouseData(event));
		$s.pop();
	}
	,onNativeMouseOver: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseOver");
		var $spos = $s.length;
		if(this.getOnMouseOver() != null) (this.getOnMouseOver())(this.getMouseData(event));
		$s.pop();
	}
	,onNativeMouseOut: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseOut");
		var $spos = $s.length;
		if(this.getOnMouseOut() != null) (this.getOnMouseOut())(this.getMouseData(event));
		$s.pop();
	}
	,onNativeMouseMove: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseMove");
		var $spos = $s.length;
		if(this.getOnMouseMove() != null) (this.getOnMouseMove())(this.getMouseData(event));
		$s.pop();
	}
	,onNativeMouseDoubleClick: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseDoubleClick");
		var $spos = $s.length;
		if(this.getOnMouseDoubleClick() != null) (this.getOnMouseDoubleClick())(this.getMouseData(event));
		$s.pop();
	}
	,updateListeners: function(mouseEvent,nativeCallback,domElementCallback) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::updateListeners");
		var $spos = $s.length;
		$s.pop();
	}
	,getMouseData: function(event) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getMouseData");
		var $spos = $s.length;
		$s.pop();
		return null;
		$s.pop();
	}
	,setOnMouseDown: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseDown");
		var $spos = $s.length;
		this.updateListeners(this._mouseDownEvent,this.onNativeMouseDown.$bind(this),value);
		var $tmp = this._onMouseDown = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseDown: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseDown");
		var $spos = $s.length;
		var $tmp = this._onMouseDown;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseUp: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseUp");
		var $spos = $s.length;
		this.updateListeners(this._mouseUpEvent,this.onNativeMouseUp.$bind(this),value);
		var $tmp = this._onMouseUp = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseUp: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseUp");
		var $spos = $s.length;
		var $tmp = this._onMouseUp;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseOver: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseOver");
		var $spos = $s.length;
		this.updateListeners(this._mouseOverEvent,this.onNativeMouseOver.$bind(this),value);
		var $tmp = this._onMouseOver = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseOver: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseOver");
		var $spos = $s.length;
		var $tmp = this._onMouseOver;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseOut: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseOut");
		var $spos = $s.length;
		this.updateListeners(this._mouseOutEvent,this.onNativeMouseOut.$bind(this),value);
		var $tmp = this._onMouseOut = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseOut: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseOut");
		var $spos = $s.length;
		var $tmp = this._onMouseOut;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseMove: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseMove");
		var $spos = $s.length;
		this.updateListeners(this._mouseMoveEvent,this.onNativeMouseMove.$bind(this),value);
		var $tmp = this._onMouseMove = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseMove: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseMove");
		var $spos = $s.length;
		var $tmp = this._onMouseMove;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setOnMouseDoubleClick: function(value) {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::setOnMouseDoubleClick");
		var $spos = $s.length;
		this.updateListeners(this._mouseDoubleClickEvent,this.onNativeMouseDoubleClick.$bind(this),value);
		var $tmp = this._onMouseDoubleClick = value;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getOnMouseDoubleClick: function() {
		$s.push("cocktailCore.mouse.abstract.AbstractMouse::getOnMouseDoubleClick");
		var $spos = $s.length;
		var $tmp = this._onMouseDoubleClick;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.mouse.abstract.AbstractMouse
	,__properties__: {set_onMouseDoubleClick:"setOnMouseDoubleClick",get_onMouseDoubleClick:"getOnMouseDoubleClick",set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown"}
}
org.intermedia.view.DetailView = $hxClasses["org.intermedia.view.DetailView"] = function() {
	$s.push("org.intermedia.view.DetailView::new");
	var $spos = $s.length;
	this._titleElement = new cocktailCore.textElement.js.TextElement("");
	this._authorElement = new cocktailCore.textElement.js.TextElement("");
	this._descriptionElement = new cocktailCore.textElement.js.TextElement("");
	org.intermedia.view.ViewBase.call(this);
	$s.pop();
}
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
	,buildView: function() {
		$s.push("org.intermedia.view.DetailView::buildView");
		var $spos = $s.length;
		org.intermedia.view.DetailStyle.setDefault(this);
		this._titleContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		org.intermedia.view.DetailStyle.setTitle(this._titleContainer);
		this._titleContainer.addText(this._titleElement);
		this.addChild(this._titleContainer);
		this._authorContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		org.intermedia.view.DetailStyle.setAuthor(this._authorContainer);
		this._authorContainer.addText(this._authorElement);
		this.addChild(this._authorContainer);
		this._thumbnail = new cocktailCore.domElement.js.ImageDOMElement();
		org.intermedia.view.DetailStyle.setThumbnail(this._thumbnail);
		this.addChild(this._thumbnail);
		this._descriptionContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		org.intermedia.view.DetailStyle.setDescription(this._descriptionContainer);
		this._descriptionContainer.addText(this._descriptionElement);
		this.addChild(this._descriptionContainer);
		$s.pop();
	}
	,updateView: function() {
		$s.push("org.intermedia.view.DetailView::updateView");
		var $spos = $s.length;
		this._titleContainer.removeText(this._titleElement);
		this._titleElement.setText(this._data.title);
		this._titleContainer.addText(this._titleElement);
		this._authorContainer.removeText(this._authorElement);
		this._authorElement.setText(this._data.author);
		this._authorContainer.addText(this._authorElement);
		this._thumbnail.load(this._data.thumbUrl);
		this._descriptionContainer.removeText(this._descriptionElement);
		this._descriptionElement.setText(this._data.description);
		this._descriptionContainer.addText(this._descriptionElement);
		$s.pop();
	}
	,__class__: org.intermedia.view.DetailView
});
if(!cocktailCore.style.floats) cocktailCore.style.floats = {}
cocktailCore.style.floats.FloatsManager = $hxClasses["cocktailCore.style.floats.FloatsManager"] = function() {
	$s.push("cocktailCore.style.floats.FloatsManager::new");
	var $spos = $s.length;
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.__name__ = ["cocktailCore","style","floats","FloatsManager"];
cocktailCore.style.floats.FloatsManager.prototype = {
	_floats: null
	,floats: null
	,clearFloat: function(clear,formattingContextData) {
		$s.push("cocktailCore.style.floats.FloatsManager::clearFloat");
		var $spos = $s.length;
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
		$s.pop();
		return ret;
		$s.pop();
	}
	,clearLeft: function(formattingContextData) {
		$s.push("cocktailCore.style.floats.FloatsManager::clearLeft");
		var $spos = $s.length;
		var $tmp = this.doClearFloat(formattingContextData,this._floats.left);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,clearRight: function(formattingContextData) {
		$s.push("cocktailCore.style.floats.FloatsManager::clearRight");
		var $spos = $s.length;
		var $tmp = this.doClearFloat(formattingContextData,this._floats.right);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,clearBoth: function(formattingContextData) {
		$s.push("cocktailCore.style.floats.FloatsManager::clearBoth");
		var $spos = $s.length;
		var leftY = this.doClearFloat(formattingContextData,this._floats.left);
		var rightY = this.doClearFloat(formattingContextData,this._floats.right);
		if(leftY > rightY) {
			$s.pop();
			return leftY;
		} else {
			$s.pop();
			return rightY;
		}
		$s.pop();
	}
	,doClearFloat: function(formattingContextData,floats) {
		$s.push("cocktailCore.style.floats.FloatsManager::doClearFloat");
		var $spos = $s.length;
		if(floats.length > 0) {
			var highestFloat = floats[0];
			var _g1 = 0, _g = floats.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(floats[i].y + floats[i].height > highestFloat.y + highestFloat.height) highestFloat = floats[i];
			}
			var $tmp = highestFloat.y + highestFloat.height;
			$s.pop();
			return $tmp;
		} else {
			var $tmp = formattingContextData.y;
			$s.pop();
			return $tmp;
		}
		$s.pop();
	}
	,computeFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::computeFloatData");
		var $spos = $s.length;
		var ret;
		switch( (domElement.getStyle().getComputedStyle().floatValue)[1] ) {
		case 0:
			ret = this.getLeftFloatData(domElement,formattingContextData,containingBlockWidth);
			this._floats.left.push(ret);
			break;
		case 1:
			ret = this.getRightFloatData(domElement,formattingContextData,containingBlockWidth);
			this._floats.right.push(ret);
			break;
		default:
			ret = null;
		}
		$s.pop();
		return ret;
		$s.pop();
	}
	,getLeftFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::getLeftFloatData");
		var $spos = $s.length;
		var floatData = this.getFloatData(domElement,formattingContextData,containingBlockWidth);
		floatData.x = this.getLeftFloatOffset(floatData.y);
		$s.pop();
		return floatData;
		$s.pop();
	}
	,getRightFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::getRightFloatData");
		var $spos = $s.length;
		var floatData = this.getFloatData(domElement,formattingContextData,containingBlockWidth);
		floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth);
		$s.pop();
		return floatData;
		$s.pop();
	}
	,getFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::getFloatData");
		var $spos = $s.length;
		var floatWidth = domElement.getOffsetWidth();
		var floatHeight = domElement.getOffsetHeight();
		var floatY = this.getFirstAvailableY(formattingContextData,floatWidth,containingBlockWidth);
		var floatX = 0;
		var $tmp = { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getFirstAvailableY: function(formattingContextData,elementWidth,containingBlockWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::getFirstAvailableY");
		var $spos = $s.length;
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
		$s.pop();
		return retY;
		$s.pop();
	}
	,removeFloats: function(flowY) {
		$s.push("cocktailCore.style.floats.FloatsManager::removeFloats");
		var $spos = $s.length;
		this._floats.left = this.doRemoveFloat(this._floats.left,flowY);
		this._floats.right = this.doRemoveFloat(this._floats.right,flowY);
		$s.pop();
	}
	,doRemoveFloat: function(floats,flowY) {
		$s.push("cocktailCore.style.floats.FloatsManager::doRemoveFloat");
		var $spos = $s.length;
		var newFloats = new Array();
		var _g1 = 0, _g = floats.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(floats[i].y + floats[i].height > flowY) newFloats.push(floats[i]);
		}
		$s.pop();
		return newFloats;
		$s.pop();
	}
	,getRightFloatOffset: function(y,containingWidth) {
		$s.push("cocktailCore.style.floats.FloatsManager::getRightFloatOffset");
		var $spos = $s.length;
		var rightFloatOffset = 0;
		var _g1 = 0, _g = this._floats.right.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._floats.right[i].y + this._floats.right[i].height > y && this._floats.right[i].y <= y) {
				if(containingWidth - this._floats.right[i].x > rightFloatOffset) rightFloatOffset = containingWidth - this._floats.right[i].x;
			}
		}
		$s.pop();
		return rightFloatOffset;
		$s.pop();
	}
	,getLeftFloatOffset: function(y) {
		$s.push("cocktailCore.style.floats.FloatsManager::getLeftFloatOffset");
		var $spos = $s.length;
		var leftFloatOffset = 0;
		var _g1 = 0, _g = this._floats.left.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._floats.left[i].y + this._floats.left[i].height > y && this._floats.left[i].y <= y) {
				if(this._floats.left[i].x + this._floats.left[i].width > leftFloatOffset) leftFloatOffset = this._floats.left[i].x + this._floats.left[i].width;
			}
		}
		$s.pop();
		return leftFloatOffset;
		$s.pop();
	}
	,getFloats: function() {
		$s.push("cocktailCore.style.floats.FloatsManager::getFloats");
		var $spos = $s.length;
		var $tmp = this._floats;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.floats.FloatsManager
	,__properties__: {get_floats:"getFloats"}
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","NoneBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer
});
org.intermedia.view.ThumbList = $hxClasses["org.intermedia.view.ThumbList"] = function(cellPerLine) {
	$s.push("org.intermedia.view.ThumbList::new");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	this._cellsPerLine = cellPerLine;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.ListViewStyle.setListStyle(this);
	$s.pop();
}
org.intermedia.view.ThumbList.__name__ = ["org","intermedia","view","ThumbList"];
org.intermedia.view.ThumbList.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ThumbList.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	_cellsPerLine: null
	,createCell: function() {
		$s.push("org.intermedia.view.ThumbList::createCell");
		var $spos = $s.length;
		var cell = new org.intermedia.view.CellThumb(this._cellsPerLine);
		$s.pop();
		return cell;
		$s.pop();
	}
	,__class__: org.intermedia.view.ThumbList
});
cocktail.nativeElement.NativeElementManager = $hxClasses["cocktail.nativeElement.NativeElementManager"] = function() {
	$s.push("cocktail.nativeElement.NativeElementManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktail.nativeElement.NativeElementManager.__name__ = ["cocktail","nativeElement","NativeElementManager"];
cocktail.nativeElement.NativeElementManager._nativeElementCreator = null;
cocktail.nativeElement.NativeElementManager._nativeElementPathManager = null;
cocktail.nativeElement.NativeElementManager.getRoot = function() {
	$s.push("cocktail.nativeElement.NativeElementManager::getRoot");
	var $spos = $s.length;
	if(cocktail.nativeElement.NativeElementManager._nativeElementPathManager == null) cocktail.nativeElement.NativeElementManager._nativeElementPathManager = new cocktailCore.nativeElement.js.NativeElementPathManager();
	var $tmp = cocktail.nativeElement.NativeElementManager._nativeElementPathManager.getRoot();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.nativeElement.NativeElementManager.createNativeElement = function(nativeElementType) {
	$s.push("cocktail.nativeElement.NativeElementManager::createNativeElement");
	var $spos = $s.length;
	if(cocktail.nativeElement.NativeElementManager._nativeElementCreator == null) cocktail.nativeElement.NativeElementManager._nativeElementCreator = new cocktailCore.nativeElement.js.NativeElementCreator();
	var $tmp = cocktail.nativeElement.NativeElementManager._nativeElementCreator.createNativeElement(nativeElementType);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.nativeElement.NativeElementManager.prototype = {
	__class__: cocktail.nativeElement.NativeElementManager
}
org.intermedia.view.ListViewText = $hxClasses["org.intermedia.view.ListViewText"] = function() {
	$s.push("org.intermedia.view.ListViewText::new");
	var $spos = $s.length;
	org.intermedia.view.ListViewBase.call(this);
	org.intermedia.view.ListViewStyle.setListStyle(this);
	$s.pop();
}
org.intermedia.view.ListViewText.__name__ = ["org","intermedia","view","ListViewText"];
org.intermedia.view.ListViewText.__super__ = org.intermedia.view.ListViewBase;
org.intermedia.view.ListViewText.prototype = $extend(org.intermedia.view.ListViewBase.prototype,{
	createCell: function() {
		$s.push("org.intermedia.view.ListViewText::createCell");
		var $spos = $s.length;
		var cell = new org.intermedia.view.CellText();
		$s.pop();
		return cell;
		$s.pop();
	}
	,__class__: org.intermedia.view.ListViewText
});
haxe.Public = $hxClasses["haxe.Public"] = function() { }
haxe.Public.__name__ = ["haxe","Public"];
haxe.Public.prototype = {
	__class__: haxe.Public
}
var feffects = feffects || {}
feffects.Tween = $hxClasses["feffects.Tween"] = function(init,end,dur,_obj,_prop,easing) {
	$s.push("feffects.Tween::new");
	var $spos = $s.length;
	this._initVal = init;
	this._endVal = end;
	this.duration = dur;
	this._offsetTime = 0;
	this._obj = _obj;
	this._prop = _prop;
	if(easing != null) this._easingF = easing; else if(Reflect.isFunction(_obj)) this._easingF = _obj; else this._easingF = this.easingEquation.$bind(this);
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
	,pause: function() {
		$s.push("feffects.Tween::pause");
		var $spos = $s.length;
		this._pauseTime = Date.now().getTime();
		feffects.Tween.setTweenPaused(this);
		this.isPlaying = false;
		$s.pop();
	}
	,resume: function() {
		$s.push("feffects.Tween::resume");
		var $spos = $s.length;
		this._startTime += Date.now().getTime() - this._pauseTime;
		this._reverseTime += Date.now().getTime() - this._pauseTime;
		feffects.Tween.setTweenActive(this);
		this.isPlaying = true;
		$s.pop();
	}
	,seek: function(ms) {
		$s.push("feffects.Tween::seek");
		var $spos = $s.length;
		this._offsetTime = ms;
		$s.pop();
	}
	,reverse: function() {
		$s.push("feffects.Tween::reverse");
		var $spos = $s.length;
		this.reversed = !this.reversed;
		if(!this.reversed) this._startTime += (Date.now().getTime() - this._reverseTime) * 2;
		this._reverseTime = Date.now().getTime();
		$s.pop();
	}
	,stop: function() {
		$s.push("feffects.Tween::stop");
		var $spos = $s.length;
		feffects.Tween.RemoveTween(this);
		this.isPlaying = false;
		$s.pop();
	}
	,setTweenHandlers: function(update,end) {
		$s.push("feffects.Tween::setTweenHandlers");
		var $spos = $s.length;
		this.updateFunc = update;
		this.endFunc = end;
		$s.pop();
	}
	,setEasing: function(easingFunc) {
		$s.push("feffects.Tween::setEasing");
		var $spos = $s.length;
		if(easingFunc != null) this._easingF = easingFunc;
		$s.pop();
	}
	,updateFunc: function(e) {
		$s.push("feffects.Tween::updateFunc");
		var $spos = $s.length;
		$s.pop();
	}
	,endFunc: function(e) {
		$s.push("feffects.Tween::endFunc");
		var $spos = $s.length;
		$s.pop();
	}
	,doInterval: function() {
		$s.push("feffects.Tween::doInterval");
		var $spos = $s.length;
		var stamp = Date.now().getTime();
		var curTime = 0;
		if(this.reversed) curTime = this._reverseTime * 2 - stamp - this._startTime + this._offsetTime; else curTime = stamp - this._startTime + this._offsetTime;
		var curVal = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
		if(curTime >= this.duration || curTime <= 0) this.endTween(); else {
			if(this.updateFunc.$bind(this) != null) this.updateFunc(curVal);
			if(this._prop != null) this._obj[this._prop] = curVal;
		}
		this.position = curTime;
		$s.pop();
	}
	,getCurVal: function(curTime) {
		$s.push("feffects.Tween::getCurVal");
		var $spos = $s.length;
		var $tmp = this._easingF(curTime,this._initVal,this._endVal - this._initVal,this.duration);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getStamp: function() {
		$s.push("feffects.Tween::getStamp");
		var $spos = $s.length;
		var $tmp = Date.now().getTime();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,endTween: function() {
		$s.push("feffects.Tween::endTween");
		var $spos = $s.length;
		feffects.Tween.RemoveTween(this);
		var val = 0.0;
		if(this.reversed) val = this._initVal; else val = this._endVal;
		if(this.updateFunc.$bind(this) != null) this.updateFunc(val);
		if(this.endFunc.$bind(this) != null) this.endFunc(val);
		if(this._prop != null) this._obj[this._prop] = val;
		$s.pop();
	}
	,easingEquation: function(t,b,c,d) {
		$s.push("feffects.Tween::easingEquation");
		var $spos = $s.length;
		var $tmp = c / 2 * (Math.sin(Math.PI * (t / d - 0.5)) + 1) + b;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: feffects.Tween
}
org.intermedia.model.ApplicationModel = $hxClasses["org.intermedia.model.ApplicationModel"] = function() {
	$s.push("org.intermedia.model.ApplicationModel::new");
	var $spos = $s.length;
	this._online = false;
	this._loadedCellsData = new Array();
	this._loadedDetailData = new Array();
	this._dataLoader = new org.intermedia.model.DataLoader(this._online);
	$s.pop();
}
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
	,loadCellData: function(numberOfCellsToLoad) {
		$s.push("org.intermedia.model.ApplicationModel::loadCellData");
		var $spos = $s.length;
		if(this.onModelStartsLoading != null) this.onModelStartsLoading();
		var loadedCellsQty = this._loadedCellsData.length;
		this._dataLoader.loadCellData(loadedCellsQty,loadedCellsQty + numberOfCellsToLoad - 1,this.onCellsDataLoadComplete.$bind(this),this.onModelDataLoadError);
		$s.pop();
	}
	,loadDetailData: function(cellData) {
		$s.push("org.intermedia.model.ApplicationModel::loadDetailData");
		var $spos = $s.length;
		if(this.onModelStartsLoading != null) this.onModelStartsLoading();
		this._dataLoader.loadDetailData(cellData,this.onDetailDataLoadComplete.$bind(this),this.onModelDataLoadError);
		$s.pop();
	}
	,onCellsDataLoadComplete: function(cellsData) {
		$s.push("org.intermedia.model.ApplicationModel::onCellsDataLoadComplete");
		var $spos = $s.length;
		var _g = 0;
		while(_g < cellsData.length) {
			var cellData = cellsData[_g];
			++_g;
			this._loadedCellsData.push(cellData);
		}
		if(this.onModelCellDataLoaded != null) this.onModelCellDataLoaded(this._loadedCellsData);
		$s.pop();
	}
	,onDetailDataLoadComplete: function(detailData) {
		$s.push("org.intermedia.model.ApplicationModel::onDetailDataLoadComplete");
		var $spos = $s.length;
		this._loadedDetailData.push(detailData);
		if(this.onModelDetailDataLoaded != null) this.onModelDetailDataLoaded(detailData);
		$s.pop();
	}
	,__class__: org.intermedia.model.ApplicationModel
}
cocktailCore.resource.js.StringLoader = $hxClasses["cocktailCore.resource.js.StringLoader"] = function() {
	$s.push("cocktailCore.resource.js.StringLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractStringLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.StringLoader.__name__ = ["cocktailCore","resource","js","StringLoader"];
cocktailCore.resource.js.StringLoader.__super__ = cocktailCore.resource.abstract.AbstractStringLoader;
cocktailCore.resource.js.StringLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractStringLoader.prototype,{
	__class__: cocktailCore.resource.js.StringLoader
});
cocktailCore.background.BackgroundManager = $hxClasses["cocktailCore.background.BackgroundManager"] = function() {
	$s.push("cocktailCore.background.BackgroundManager::new");
	var $spos = $s.length;
	this._backgroundDrawingManagers = new Array();
	$s.pop();
}
cocktailCore.background.BackgroundManager.__name__ = ["cocktailCore","background","BackgroundManager"];
cocktailCore.background.BackgroundManager.prototype = {
	_backgroundDrawingManagers: null
	,render: function(backgroundBox,style) {
		$s.push("cocktailCore.background.BackgroundManager::render");
		var $spos = $s.length;
		var nativeElements = new Array();
		if(backgroundBox.width <= 0 || backgroundBox.height <= 0) {
			$s.pop();
			return nativeElements;
		}
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
					var imageDeclaration = { urls : [value1], fallbackColor : cocktail.unit.ColorValue.transparent};
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
				var backgroundColorNativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
				this.drawBackgroundColor(style,style.getComputedStyle().backgroundColor,backgroundColorNativeElement,backgroundBox,style.getBackgroundPosition()[i],style.getBackgroundSize()[i],style.getBackgroundOrigin()[i],style.getBackgroundClip()[i],style.getBackgroundRepeat()[i],style.getBackgroundImage()[i]);
				nativeElements.reverse();
				nativeElements.unshift(backgroundColorNativeElement);
			}
		}
		var _g1 = 0, _g = nativeElements.length;
		while(_g1 < _g) {
			var i = _g1++;
		}
		$s.pop();
		return nativeElements;
		$s.pop();
	}
	,drawBackgroundImage: function(imageDeclaration,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		$s.push("cocktailCore.background.BackgroundManager::drawBackgroundImage");
		var $spos = $s.length;
		var backgroundImageNativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
		var imageLoader = new cocktailCore.resource.js.ImageLoader();
		var onBackgroundImageLoadedDelegate = this.onBackgroundImageLoaded.$bind(this);
		var onBackgroundImageLoadErrorDelegate = this.onBackgroundImageLoadError.$bind(this);
		imageLoader.load(imageDeclaration.urls,function(loadedImage) {
			$s.push("cocktailCore.background.BackgroundManager::drawBackgroundImage@202");
			var $spos = $s.length;
			onBackgroundImageLoadedDelegate(backgroundImageNativeElement,loadedImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
			$s.pop();
		},function(error) {
			$s.push("cocktailCore.background.BackgroundManager::drawBackgroundImage@205");
			var $spos = $s.length;
			onBackgroundImageLoadErrorDelegate(error,imageDeclaration.fallbackColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
			$s.pop();
		});
		$s.pop();
		return backgroundImageNativeElement;
		$s.pop();
	}
	,onBackgroundImageLoaded: function(backgroundImageNativeElement,loadedBackgroundImage,imageLoader,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		$s.push("cocktailCore.background.BackgroundManager::onBackgroundImageLoaded");
		var $spos = $s.length;
		var computedGradientStyles = cocktailCore.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundImageDrawingManager = new cocktailCore.background.BackgroundDrawingManager(backgroundImageNativeElement,backgroundBox);
		backgroundImageDrawingManager.drawBackgroundImage(loadedBackgroundImage,computedGradientStyles.backgroundOrigin,computedGradientStyles.backgroundClip,imageLoader.getIntrinsicWidth(),imageLoader.getIntrinsicHeight(),imageLoader.getIntrinsicRatio(),computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		this._backgroundDrawingManagers.push(backgroundImageDrawingManager);
		$s.pop();
	}
	,onBackgroundImageLoadError: function(error,backgroundColor,backgroundImageNativeElement,style,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		$s.push("cocktailCore.background.BackgroundManager::onBackgroundImageLoadError");
		var $spos = $s.length;
		this.drawBackgroundColor(style,cocktailCore.unit.UnitManager.getColorDataFromColorValue(backgroundColor),backgroundImageNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		$s.pop();
	}
	,drawBackgroundColor: function(style,backgroundColor,backgroundColorNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		$s.push("cocktailCore.background.BackgroundManager::drawBackgroundColor");
		var $spos = $s.length;
		var computedBackgroundStyles = cocktailCore.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var backgroundColorDrawingManager = new cocktailCore.background.BackgroundDrawingManager(backgroundColorNativeElement,backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor,computedBackgroundStyles.backgroundClip);
		this._backgroundDrawingManagers.push(backgroundColorDrawingManager);
		$s.pop();
	}
	,drawBackgroundGradient: function(style,gradientValue,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage) {
		$s.push("cocktailCore.background.BackgroundManager::drawBackgroundGradient");
		var $spos = $s.length;
		var computedGradientStyles = cocktailCore.style.computer.BackgroundStylesComputer.computeIndividualBackground(style,backgroundBox,null,null,null,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		var gradientNativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
		var backgroundGradientDrawingManager = new cocktailCore.background.BackgroundDrawingManager(gradientNativeElement,backgroundBox);
		backgroundGradientDrawingManager.drawBackgroundGradient(gradientValue,computedGradientStyles.backgroundOrigin,computedGradientStyles.backgroundClip,computedGradientStyles.backgroundSize,computedGradientStyles.backgroundPosition,computedGradientStyles.backgroundRepeat);
		$s.pop();
		return gradientNativeElement;
		$s.pop();
	}
	,__class__: cocktailCore.background.BackgroundManager
}
cocktailCore.style.abstract.AbstractBodyStyle = $hxClasses["cocktailCore.style.abstract.AbstractBodyStyle"] = function(domElement) {
	$s.push("cocktailCore.style.abstract.AbstractBodyStyle::new");
	var $spos = $s.length;
	cocktailCore.style.js.ContainerStyle.call(this,domElement);
	this._isDirty = false;
	$s.pop();
}
cocktailCore.style.abstract.AbstractBodyStyle.__name__ = ["cocktailCore","style","abstract","AbstractBodyStyle"];
cocktailCore.style.abstract.AbstractBodyStyle.__super__ = cocktailCore.style.js.ContainerStyle;
cocktailCore.style.abstract.AbstractBodyStyle.prototype = $extend(cocktailCore.style.js.ContainerStyle.prototype,{
	invalidate: function() {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::invalidate");
		var $spos = $s.length;
		if(this._isDirty == false) {
			this._isDirty = true;
			var viewPortData = this.getViewportData();
			var lastPositionedDOMElementData = { children : new Array(), data : viewPortData};
			this.scheduleLayout(viewPortData,lastPositionedDOMElementData,viewPortData);
		}
		$s.pop();
	}
	,createElementRenderer: function(parentElementRenderer) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::createElementRenderer");
		var $spos = $s.length;
		var elementRenderer = new cocktailCore.style.renderer.InitialBlockRenderer(this._domElement);
		elementRenderer.setLayerRenderer(new cocktailCore.style.renderer.LayerRenderer(elementRenderer));
		$s.pop();
		return elementRenderer;
		$s.pop();
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::layout");
		var $spos = $s.length;
		cocktailCore.style.js.ContainerStyle.prototype.layout.call(this,containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData);
		this.render(this._domElement.getNativeElement());
		$s.pop();
	}
	,insertDOMElement: function(formattingContext,lastPositionedDOMElementData,viewportData) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::insertDOMElement");
		var $spos = $s.length;
		$s.pop();
	}
	,doPositionAbsolutelyPositionedDOMElements: function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::doPositionAbsolutelyPositionedDOMElements");
		var $spos = $s.length;
		isFirstPositionedAncestor = true;
		var $tmp = cocktailCore.style.js.ContainerStyle.prototype.doPositionAbsolutelyPositionedDOMElements.call(this,isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getContainerDOMElementData: function() {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::getContainerDOMElementData");
		var $spos = $s.length;
		var viewPort = new cocktailCore.viewport.js.Viewport();
		var $tmp = { width : viewPort._getWidth(), isWidthAuto : this._width == cocktail.style.DimensionStyleValue.autoValue, height : viewPort._getHeight(), isHeightAuto : this._height == cocktail.style.DimensionStyleValue.autoValue};
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,isInlineLevel: function() {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::isInlineLevel");
		var $spos = $s.length;
		$s.pop();
		return false;
		$s.pop();
	}
	,getformattingContext: function(previousformattingContext) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::getformattingContext");
		var $spos = $s.length;
		var $tmp = new cocktailCore.style.formatter.BlockFormattingContext(this._domElement);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getComputedHeight: function() {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::getComputedHeight");
		var $spos = $s.length;
		var $tmp = new cocktailCore.viewport.js.Viewport()._getHeight();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,establishesNewFormattingContext: function() {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::establishesNewFormattingContext");
		var $spos = $s.length;
		$s.pop();
		return true;
		$s.pop();
	}
	,setNativeX: function(domElement,x) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeX");
		var $spos = $s.length;
		$s.pop();
	}
	,setNativeY: function(domElement,y) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeY");
		var $spos = $s.length;
		$s.pop();
	}
	,setNativeWidth: function(width) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeWidth");
		var $spos = $s.length;
		$s.pop();
	}
	,setNativeHeight: function(height) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeHeight");
		var $spos = $s.length;
		$s.pop();
	}
	,setNativeOpacity: function(opacity) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeOpacity");
		var $spos = $s.length;
		$s.pop();
	}
	,setNativeVisibility: function(visibility) {
		$s.push("cocktailCore.style.abstract.AbstractBodyStyle::setNativeVisibility");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: cocktailCore.style.abstract.AbstractBodyStyle
});
cocktailCore.style.js.BodyStyle = $hxClasses["cocktailCore.style.js.BodyStyle"] = function(domElement) {
	$s.push("cocktailCore.style.js.BodyStyle::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractBodyStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.BodyStyle.__name__ = ["cocktailCore","style","js","BodyStyle"];
cocktailCore.style.js.BodyStyle.__super__ = cocktailCore.style.abstract.AbstractBodyStyle;
cocktailCore.style.js.BodyStyle.prototype = $extend(cocktailCore.style.abstract.AbstractBodyStyle.prototype,{
	__class__: cocktailCore.style.js.BodyStyle
});
org.intermedia.view.CellText = $hxClasses["org.intermedia.view.CellText"] = function() {
	$s.push("org.intermedia.view.CellText::new");
	var $spos = $s.length;
	org.intermedia.view.CellBase.call(this);
	org.intermedia.view.CellTextStyle.setCellStyle(this);
	$s.pop();
}
org.intermedia.view.CellText.__name__ = ["org","intermedia","view","CellText"];
org.intermedia.view.CellText.__super__ = org.intermedia.view.CellBase;
org.intermedia.view.CellText.prototype = $extend(org.intermedia.view.CellBase.prototype,{
	updateView: function() {
		$s.push("org.intermedia.view.CellText::updateView");
		var $spos = $s.length;
		var cellData = this._data;
		var cellTextContainer = new cocktailCore.domElement.js.ContainerDOMElement();
		if(cellData.title != "" && cellData.title != null) {
			var textElement = new cocktailCore.textElement.js.TextElement(cellData.title);
			cellTextContainer.addText(textElement);
			org.intermedia.view.CellTextStyle.setCellTextStyle(cellTextContainer);
			this.addChild(cellTextContainer);
		}
		var line = new cocktailCore.domElement.js.ImageDOMElement();
		org.intermedia.view.CellTextStyle.setCellLineStyle(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");
		$s.pop();
	}
	,__class__: org.intermedia.view.CellText
});
cocktailCore.style.computer.VisualEffectStylesComputer = $hxClasses["cocktailCore.style.computer.VisualEffectStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.__name__ = ["cocktailCore","style","computer","VisualEffectStylesComputer"];
cocktailCore.style.computer.VisualEffectStylesComputer.compute = function(style) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::compute");
	var $spos = $s.length;
	var computedStyle = style.getComputedStyle();
	computedStyle.opacity = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedOpacity(style);
	computedStyle.visibility = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedVisibility(style);
	computedStyle.overflow = style.getOverflow();
	computedStyle.transformOrigin = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin(style);
	computedStyle.transform = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransform(style);
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedOpacity = function(style) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::getComputedOpacity");
	var $spos = $s.length;
	var opacity;
	var $e = (style.getOpacity());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		opacity = value;
		break;
	}
	$s.pop();
	return opacity;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedVisibility = function(style) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::getComputedVisibility");
	var $spos = $s.length;
	var visibility;
	switch( (style.getVisibility())[1] ) {
	case 0:
		visibility = true;
		break;
	case 1:
		visibility = false;
		break;
	}
	$s.pop();
	return visibility;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin = function(style) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::getComputedTransformOrigin");
	var $spos = $s.length;
	var x;
	var y;
	var $e = (style.getTransformOrigin().x);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		x = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		x = cocktailCore.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		x = cocktailCore.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		x = cocktailCore.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		x = cocktailCore.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var $e = (style.getTransformOrigin().y);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		y = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		y = cocktailCore.unit.UnitManager.getPixelFromPercent(value,style.getComputedStyle().width);
		break;
	case 2:
		y = cocktailCore.unit.UnitManager.getPixelFromPercent(0,style.getComputedStyle().width);
		break;
	case 3:
		y = cocktailCore.unit.UnitManager.getPixelFromPercent(50,style.getComputedStyle().width);
		break;
	case 4:
		y = cocktailCore.unit.UnitManager.getPixelFromPercent(100,style.getComputedStyle().width);
		break;
	}
	var transformOriginPoint = { x : x, y : y};
	$s.pop();
	return transformOriginPoint;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransform = function(style) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::getComputedTransform");
	var $spos = $s.length;
	var transformFunctions;
	var transformOrigin = style.getComputedStyle().transformOrigin;
	var matrix = new cocktail.geom.Matrix();
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
			matrix.concatenate(new cocktail.geom.Matrix(data));
			break;
		case 7:
			var value = $e[2];
			var angle = Math.round(cocktailCore.unit.UnitManager.getRadFromAngleValue(value));
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
			var skewX = cocktailCore.unit.UnitManager.getRadFromAngleValue(angleX);
			var skewY = cocktailCore.unit.UnitManager.getRadFromAngleValue(angleY);
			matrix.skew(skewX,skewY,transformOrigin);
			break;
		case 8:
			var angleX = $e[2];
			var skewX = cocktailCore.unit.UnitManager.getRadFromAngleValue(angleX);
			matrix.skew(skewX,1,transformOrigin);
			break;
		case 9:
			var angleY = $e[2];
			var skewY = cocktailCore.unit.UnitManager.getRadFromAngleValue(angleY);
			matrix.skew(1,skewY,transformOrigin);
			break;
		case 1:
			var ty = $e[3], tx = $e[2];
			var translationX = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			var translationY = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(translationX,translationY);
			break;
		case 2:
			var tx = $e[2];
			var translationX = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,tx,style.getComputedStyle().width);
			matrix.translate(translationX,0.0);
			break;
		case 3:
			var ty = $e[2];
			var translationY = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation(style,ty,style.getComputedStyle().height);
			matrix.translate(0.0,translationY);
			break;
		}
	}
	$s.pop();
	return matrix;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation = function(style,translation,percentReference) {
	$s.push("cocktailCore.style.computer.VisualEffectStylesComputer::getComputedTranslation");
	var $spos = $s.length;
	var computedTranslation;
	var $e = (translation);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedTranslation = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		break;
	case 1:
		var value = $e[2];
		computedTranslation = cocktailCore.unit.UnitManager.getPixelFromPercent(value,percentReference);
		break;
	}
	$s.pop();
	return computedTranslation;
	$s.pop();
}
cocktailCore.style.computer.VisualEffectStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.VisualEffectStylesComputer
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"] = function() {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer
});
haxe.Http = $hxClasses["haxe.Http"] = function(url) {
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
haxe.Http.prototype = {
	url: null
	,async: null
	,postData: null
	,headers: null
	,params: null
	,setHeader: function(header,value) {
		$s.push("haxe.Http::setHeader");
		var $spos = $s.length;
		this.headers.set(header,value);
		$s.pop();
	}
	,setParameter: function(param,value) {
		$s.push("haxe.Http::setParameter");
		var $spos = $s.length;
		this.params.set(param,value);
		$s.pop();
	}
	,setPostData: function(data) {
		$s.push("haxe.Http::setPostData");
		var $spos = $s.length;
		this.postData = data;
		$s.pop();
	}
	,request: function(post) {
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
	,onData: function(data) {
		$s.push("haxe.Http::onData");
		var $spos = $s.length;
		$s.pop();
	}
	,onError: function(msg) {
		$s.push("haxe.Http::onError");
		var $spos = $s.length;
		$s.pop();
	}
	,onStatus: function(status) {
		$s.push("haxe.Http::onStatus");
		var $spos = $s.length;
		$s.pop();
	}
	,__class__: haxe.Http
}
org.intermedia.view.CellThumbText1Style = $hxClasses["org.intermedia.view.CellThumbText1Style"] = function() { }
org.intermedia.view.CellThumbText1Style.__name__ = ["org","intermedia","view","CellThumbText1Style"];
org.intermedia.view.CellThumbText1Style.setCellStyle = function(domElement,cellPerLine) {
	$s.push("org.intermedia.view.CellThumbText1Style::setCellStyle");
	var $spos = $s.length;
	if(cellPerLine == null) cellPerLine = 1;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(5)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	var cellPercentWidth = 0;
	if(cellPerLine != 0) cellPercentWidth = Std["int"](100 / cellPerLine); else cellPercentWidth = 100;
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(cellPercentWidth));
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setThumbnailStyle = function(domElement) {
	$s.push("org.intermedia.view.CellThumbText1Style::setThumbnailStyle");
	var $spos = $s.length;
	var imageMaxWidth = 200;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(imageMaxWidth)));
	domElement.getStyle().setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(50));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(30));
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTextBlockStyle = function(domElement) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTextBlockStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.percent(2));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(55));
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTextStyle = function(domElement) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTextStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#202020"));
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Arial"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setTitleStyle = function(domElement,screenResolutionSize) {
	$s.push("org.intermedia.view.CellThumbText1Style::setTitleStyle");
	var $spos = $s.length;
	org.intermedia.view.CellThumbText1Style.setTextStyle(domElement);
	var fontSize = 14;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setAuthorStyle = function(domElement,screenResolutionSize) {
	$s.push("org.intermedia.view.CellThumbText1Style::setAuthorStyle");
	var $spos = $s.length;
	org.intermedia.view.CellThumbText1Style.setTextStyle(domElement);
	var fontSize = 10;
	if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == org.intermedia.view.ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.normal);
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.setLineStyle = function(domElement) {
	$s.push("org.intermedia.view.CellThumbText1Style::setLineStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(1)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(5)));
	$s.pop();
}
org.intermedia.view.CellThumbText1Style.prototype = {
	__class__: org.intermedia.view.CellThumbText1Style
}
if(!feffects.easing) feffects.easing = {}
feffects.easing.Quart = $hxClasses["feffects.easing.Quart"] = function() { }
feffects.easing.Quart.__name__ = ["feffects","easing","Quart"];
feffects.easing.Quart.__interfaces__ = [haxe.Public];
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
feffects.easing.Quart.prototype = {
	__class__: feffects.easing.Quart
}
feffects.easing.Quint = $hxClasses["feffects.easing.Quint"] = function() { }
feffects.easing.Quint.__name__ = ["feffects","easing","Quint"];
feffects.easing.Quint.__interfaces__ = [haxe.Public];
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
feffects.easing.Quint.prototype = {
	__class__: feffects.easing.Quint
}
if(!org.intermedia.controller) org.intermedia.controller = {}
org.intermedia.controller.ApplicationController = $hxClasses["org.intermedia.controller.ApplicationController"] = function(applicationModel) {
	$s.push("org.intermedia.controller.ApplicationController::new");
	var $spos = $s.length;
	this._applicationModel = applicationModel;
	$s.pop();
}
org.intermedia.controller.ApplicationController.__name__ = ["org","intermedia","controller","ApplicationController"];
org.intermedia.controller.ApplicationController.prototype = {
	_applicationModel: null
	,loadCellData: function(numberOfCellsToLoad) {
		$s.push("org.intermedia.controller.ApplicationController::loadCellData");
		var $spos = $s.length;
		this._applicationModel.loadCellData(numberOfCellsToLoad);
		$s.pop();
	}
	,openDetailView: function(cellData) {
		$s.push("org.intermedia.controller.ApplicationController::openDetailView");
		var $spos = $s.length;
		this._applicationModel.loadDetailData(cellData);
		$s.pop();
	}
	,__class__: org.intermedia.controller.ApplicationController
}
if(!cocktailCore.mouse.js) cocktailCore.mouse.js = {}
cocktailCore.mouse.js.Mouse = $hxClasses["cocktailCore.mouse.js.Mouse"] = function(nativeElement) {
	$s.push("cocktailCore.mouse.js.Mouse::new");
	var $spos = $s.length;
	cocktailCore.mouse.abstract.AbstractMouse.call(this,nativeElement);
	this._mouseDownEvent = "mousedown";
	this._mouseUpEvent = "mouseup";
	this._mouseOverEvent = "mouseover";
	this._mouseOutEvent = "mouseout";
	this._mouseDoubleClickEvent = "dblclick";
	this._mouseMoveEvent = "mousemove";
	$s.pop();
}
cocktailCore.mouse.js.Mouse.__name__ = ["cocktailCore","mouse","js","Mouse"];
cocktailCore.mouse.js.Mouse.__super__ = cocktailCore.mouse.abstract.AbstractMouse;
cocktailCore.mouse.js.Mouse.prototype = $extend(cocktailCore.mouse.abstract.AbstractMouse.prototype,{
	updateListeners: function(mouseEvent,nativeCallback,domElementCallback) {
		$s.push("cocktailCore.mouse.js.Mouse::updateListeners");
		var $spos = $s.length;
		this._nativeElement.removeEventListener(mouseEvent,nativeCallback);
		if(domElementCallback != null) this._nativeElement.addEventListener(mouseEvent,nativeCallback);
		$s.pop();
	}
	,getMouseData: function(event) {
		$s.push("cocktailCore.mouse.js.Mouse::getMouseData");
		var $spos = $s.length;
		var mousePosition = { localX : event.clientX, localY : event.clientY, globalX : event.screenX, globalY : event.screenY};
		var mouseEventData = { mousePosition : mousePosition, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
		$s.pop();
		return mouseEventData;
		$s.pop();
	}
	,__class__: cocktailCore.mouse.js.Mouse
});
cocktailCore.style.renderer.InlineBoxRenderer = $hxClasses["cocktailCore.style.renderer.InlineBoxRenderer"] = function(domElement) {
	$s.push("cocktailCore.style.renderer.InlineBoxRenderer::new");
	var $spos = $s.length;
	cocktailCore.style.renderer.FlowBoxRenderer.call(this,domElement);
	$s.pop();
}
cocktailCore.style.renderer.InlineBoxRenderer.__name__ = ["cocktailCore","style","renderer","InlineBoxRenderer"];
cocktailCore.style.renderer.InlineBoxRenderer.__super__ = cocktailCore.style.renderer.FlowBoxRenderer;
cocktailCore.style.renderer.InlineBoxRenderer.prototype = $extend(cocktailCore.style.renderer.FlowBoxRenderer.prototype,{
	render: function() {
		$s.push("cocktailCore.style.renderer.InlineBoxRenderer::render");
		var $spos = $s.length;
		var $tmp = this.renderBackground();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: cocktailCore.style.renderer.InlineBoxRenderer
});
var EReg = $hxClasses["EReg"] = function(r,opt) {
	$s.push("EReg::new");
	var $spos = $s.length;
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
	$s.pop();
}
EReg.__name__ = ["EReg"];
EReg.prototype = {
	r: null
	,match: function(s) {
		$s.push("EReg::match");
		var $spos = $s.length;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		var $tmp = this.r.m != null;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,matched: function(n) {
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
	,matchedLeft: function() {
		$s.push("EReg::matchedLeft");
		var $spos = $s.length;
		if(this.r.m == null) throw "No string matched";
		var $tmp = this.r.s.substr(0,this.r.m.index);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,matchedRight: function() {
		$s.push("EReg::matchedRight");
		var $spos = $s.length;
		if(this.r.m == null) throw "No string matched";
		var sz = this.r.m.index + this.r.m[0].length;
		var $tmp = this.r.s.substr(sz,this.r.s.length - sz);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,matchedPos: function() {
		$s.push("EReg::matchedPos");
		var $spos = $s.length;
		if(this.r.m == null) throw "No string matched";
		var $tmp = { pos : this.r.m.index, len : this.r.m[0].length};
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,split: function(s) {
		$s.push("EReg::split");
		var $spos = $s.length;
		var d = "#__delim__#";
		var $tmp = s.replace(this.r,d).split(d);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,replace: function(s,by) {
		$s.push("EReg::replace");
		var $spos = $s.length;
		var $tmp = s.replace(this.r,by);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,customReplace: function(s,f) {
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
	,__class__: EReg
}
var Xml = $hxClasses["Xml"] = function() {
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
		$s.push("Xml::getNodeName");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		var $tmp = this._nodeName;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNodeName: function(n) {
		$s.push("Xml::setNodeName");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		var $tmp = this._nodeName = n;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getNodeValue: function() {
		$s.push("Xml::getNodeValue");
		var $spos = $s.length;
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		var $tmp = this._nodeValue;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,setNodeValue: function(v) {
		$s.push("Xml::setNodeValue");
		var $spos = $s.length;
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		var $tmp = this._nodeValue = v;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,getParent: function() {
		$s.push("Xml::getParent");
		var $spos = $s.length;
		var $tmp = this._parent;
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,get: function(att) {
		$s.push("Xml::get");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		var $tmp = this._attributes.get(att);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,set: function(att,value) {
		$s.push("Xml::set");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.set(att,value);
		$s.pop();
	}
	,remove: function(att) {
		$s.push("Xml::remove");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.remove(att);
		$s.pop();
	}
	,exists: function(att) {
		$s.push("Xml::exists");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		var $tmp = this._attributes.exists(att);
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,attributes: function() {
		$s.push("Xml::attributes");
		var $spos = $s.length;
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		var $tmp = this._attributes.keys();
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,iterator: function() {
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
	,elements: function() {
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
	,elementsNamed: function(name) {
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
	,firstChild: function() {
		$s.push("Xml::firstChild");
		var $spos = $s.length;
		if(this._children == null) throw "bad nodetype";
		var $tmp = this._children[0];
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,firstElement: function() {
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
	,addChild: function(x) {
		$s.push("Xml::addChild");
		var $spos = $s.length;
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) x._parent._children.remove(x);
		x._parent = this;
		this._children.push(x);
		$s.pop();
	}
	,removeChild: function(x) {
		$s.push("Xml::removeChild");
		var $spos = $s.length;
		if(this._children == null) throw "bad nodetype";
		var b = this._children.remove(x);
		if(b) x._parent = null;
		$s.pop();
		return b;
		$s.pop();
	}
	,insertChild: function(x,pos) {
		$s.push("Xml::insertChild");
		var $spos = $s.length;
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) x._parent._children.remove(x);
		x._parent = this;
		this._children.insert(pos,x);
		$s.pop();
	}
	,toString: function() {
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
				var $tmp = s.b.join("");
				$s.pop();
				return $tmp;
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
		var $tmp = s.b.join("");
		$s.pop();
		return $tmp;
		$s.pop();
	}
	,__class__: Xml
	,__properties__: {get_parent:"getParent",set_nodeValue:"setNodeValue",get_nodeValue:"getNodeValue",set_nodeName:"setNodeName",get_nodeName:"getNodeName"}
}
js.Boot.__res = {}
$s = [];
$e = [];
js.Boot.__init();
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
		$s.push("Xml::toString");
		var $spos = $s.length;
		var $tmp = new Date();
		$s.pop();
		return $tmp;
		$s.pop();
	};
	d.fromTime = function(t) {
		$s.push("Xml::toString");
		var $spos = $s.length;
		var d1 = new Date();
		d1["setTime"](t);
		$s.pop();
		return d1;
		$s.pop();
	};
	d.fromString = function(s) {
		$s.push("Xml::toString");
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
		$s.push("Xml::toString");
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
		$s.push("Xml::toString");
		var $spos = $s.length;
		var $tmp = isFinite(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	Math.isNaN = function(i) {
		$s.push("Xml::toString");
		var $spos = $s.length;
		var $tmp = isNaN(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
}
js["XMLHttpRequest"] = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
	$s.push("Xml::toString");
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
{
	Xml.Element = "element";
	Xml.PCData = "pcdata";
	Xml.CData = "cdata";
	Xml.Comment = "comment";
	Xml.DocType = "doctype";
	Xml.Prolog = "prolog";
	Xml.Document = "document";
}
org.intermedia.view.ViewManager.HEADER_HOME_TITLE = "Market";
org.intermedia.view.ViewManager.HEADER_DETAIL_TITLE = "Infos";
org.intermedia.view.ViewManager.CELL_QTY = 5;
cocktailCore.keyboard.js.Keyboard.KEY_DOWN_EVENT = "keydown";
cocktailCore.keyboard.js.Keyboard.KEY_UP_EVENT = "keyup";
org.intermedia.view.CellThumbStyle.CELL_VERTICAL_SPACE = 5;
js.Lib.onerror = null;
org.intermedia.view.CellTextStyle.CELL_VERTICAL_SPACE = 5;
cocktail.resource.ResourceLoaderManager._isLoading = false;
org.intermedia.view.Constants.HEADER_HEIGHT = 43;
cocktailCore.drawing.js.DrawingManager.CAPS_STYLE_VALUE_NONE = "butt";
cocktailCore.drawing.js.DrawingManager.CAPS_STYLE_VALUE_ROUND = "round";
cocktailCore.drawing.js.DrawingManager.CAPS_STYLE_VALUE_SQUARE = "square";
cocktailCore.drawing.js.DrawingManager.JOINT_STYLE_VALUE_ROUND = "round";
cocktailCore.drawing.js.DrawingManager.JOINT_STYLE_VALUE_MITER = "miter";
cocktailCore.drawing.js.DrawingManager.JOINT_STYLE_VALUE_BEVEL = "bevel";
cocktailCore.drawing.js.DrawingManager.CANVAS_PATTERN_REPEAT = "repeat";
cocktailCore.drawing.js.DrawingManager.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
feffects.Tween._aTweens = new haxe.FastList();
feffects.Tween._aPaused = new haxe.FastList();
feffects.Tween.INTERVAL = 10;
org.intermedia.view.CellThumbText1Style.CELL_VERTICAL_SPACE = 5;
cocktailCore.mouse.js.Mouse.MOUSE_UP_EVENT = "mouseup";
cocktailCore.mouse.js.Mouse.MOUSE_DOWN_EVENT = "mousedown";
cocktailCore.mouse.js.Mouse.MOUSE_OVER_EVENT = "mouseover";
cocktailCore.mouse.js.Mouse.MOUSE_OUT_EVENT = "mouseout";
cocktailCore.mouse.js.Mouse.MOUSE_DOUBLE_CLICK_EVENT = "dblclick";
cocktailCore.mouse.js.Mouse.MOUSE_MOVE_EVENT = "mousemove";
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
org.intermedia.Application.main()