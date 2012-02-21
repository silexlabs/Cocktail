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
	if(nativeElement != null) this.setNativeElement(nativeElement);
}
cocktailCore.domElement.abstract.AbstractDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractDOMElement"];
cocktailCore.domElement.abstract.AbstractDOMElement.prototype = {
	_mouse: null
	,onMouseDown: null
	,onMouseUp: null
	,onMouseOver: null
	,onMouseOut: null
	,onMouseMove: null
	,onMouseDoubleClick: null
	,_keyboard: null
	,onKeyDown: null
	,onKeyUp: null
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
		this._keyboard = new cocktailCore.keyboard.js.Keyboard();
		this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
		this.initStyle();
	}
	,initStyle: function() {
	}
	,getParent: function() {
		return this._parent;
	}
	,setParent: function(domElement) {
		this._parent = domElement;
		return this._parent;
	}
	,setNativeElement: function(value) {
		this._nativeElement = value;
		this.init();
		return value;
	}
	,getNativeElement: function() {
		return this._nativeElement;
	}
	,setIsVisible: function(value) {
		var visibility;
		if(value == true) visibility = cocktail.style.VisibilityStyleValue.visible; else visibility = cocktail.style.VisibilityStyleValue.hidden;
		this._style.setVisibility(visibility);
		return value;
	}
	,getIsVisible: function() {
		return this._style.getNativeVisibility();
	}
	,setAlpha: function(value) {
		this._style.setOpacity(cocktail.style.OpacityStyleValue.number(value));
		return value;
	}
	,getAlpha: function() {
		return this._style.getNativeOpacity();
	}
	,setMatrix: function(matrix) {
		this._style.setNativeMatrix(matrix);
		return matrix;
	}
	,getMatrix: function() {
		return this._style.getNativeMatrix();
	}
	,setScaleX: function(scaleX) {
		this._style.setNativeScaleX(scaleX);
		this.updateTransforms();
		return scaleX;
	}
	,getScaleX: function() {
		return this._style.getNativeScaleX();
	}
	,setScaleY: function(scaleY) {
		this._style.setNativeScaleY(scaleY);
		this.updateTransforms();
		return scaleY;
	}
	,getScaleY: function() {
		return this._style.getNativeScaleY();
	}
	,setRotation: function(angle) {
		this._style.setNativeRotation(cocktailCore.unit.UnitManager.getRadFromAngleValue(cocktail.unit.AngleValue.deg(angle)));
		this.updateTransforms();
		return angle;
	}
	,getRotation: function() {
		return Math.round(cocktailCore.unit.UnitManager.getDegreeFromAngleValue(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())));
	}
	,updateTransforms: function() {
		this._style.setTransformOrigin({ x : cocktail.style.TransformOriginXStyleValue.left, y : cocktail.style.TransformOriginYStyleValue.top});
		this._style.setTransform(cocktail.style.TransformStyleValue.transformFunctions([cocktail.style.TransformFunctionValue.rotate(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())),cocktail.style.TransformFunctionValue.scaleY(this._style.getNativeScaleY()),cocktail.style.TransformFunctionValue.scaleX(this._style.getNativeScaleX())]));
	}
	,setOnMouseDown: function(value) {
		this._mouse.setOnMouseDown(value);
		return value;
	}
	,getOnMouseDown: function() {
		return this._mouse.getOnMouseDown();
	}
	,setOnMouseUp: function(value) {
		this._mouse.setOnMouseUp(value);
		return value;
	}
	,getOnMouseUp: function() {
		return this._mouse.getOnMouseUp();
	}
	,setOnMouseOver: function(value) {
		this._mouse.setOnMouseOver(value);
		return value;
	}
	,getOnMouseOver: function() {
		return this._mouse.getOnMouseOver();
	}
	,setOnMouseOut: function(value) {
		this._mouse.setOnMouseOut(value);
		return value;
	}
	,getOnMouseOut: function() {
		return this._mouse.getOnMouseOut();
	}
	,setOnMouseMove: function(value) {
		this._mouse.setOnMouseMove(value);
		return value;
	}
	,getOnMouseMove: function() {
		return this._mouse.getOnMouseMove();
	}
	,setOnMouseDoubleClick: function(value) {
		this._mouse.setOnMouseDoubleClick(value);
		return value;
	}
	,getOnMouseDoubleClick: function() {
		return this._mouse.getOnMouseDoubleClick();
	}
	,setOnKeyDown: function(value) {
		this._keyboard.setOnKeyDown(value);
		return value;
	}
	,getOnKeyDown: function() {
		return this._keyboard.getOnKeyDown();
	}
	,setOnKeyUp: function(value) {
		this._keyboard.setOnKeyUp(value);
		return value;
	}
	,getOnKeyUp: function() {
		return this._keyboard.getOnKeyUp();
	}
	,setField: function(propertyName,propertyValue) {
		this._nativeElement[propertyName] = propertyValue;
	}
	,getField: function(propertyName) {
		return Reflect.field(this._nativeElement,propertyName);
	}
	,setX: function(value) {
		this._style.setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeX(this,value);
		return value;
	}
	,getX: function() {
		return this._style.getNativeX();
	}
	,setY: function(value) {
		this._style.setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeY(this,value);
		return value;
	}
	,getY: function() {
		return this._style.getNativeY();
	}
	,setWidth: function(value) {
		this._style.setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeWidth(value);
		return value;
	}
	,getWidth: function() {
		return this._style.getNativeWidth();
	}
	,setHeight: function(value) {
		this._style.setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeHeight(value);
		return value;
	}
	,getHeight: function() {
		return this._style.getNativeHeight();
	}
	,getOffsetWidth: function() {
		var computedStyle = this._style.getComputedStyle();
		return computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	,getOffsetHeight: function() {
		var computedStyle = this._style.getComputedStyle();
		return computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	,setGlobalX: function(value) {
		var localX = value;
		if(this._parent != null) {
			var parentGlobalX = this._parent.getGlobalX();
			localX -= parentGlobalX;
		} else localX = 0;
		this._style.setNativeX(this,localX);
		return value;
	}
	,getGlobalX: function() {
		var newGlobalX = this._style.getNativeX();
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalX += parentDOMElement.getStyle().getNativeX();
				parentDOMElement = parentDOMElement.getParent();
			}
		} else newGlobalX = 0;
		return newGlobalX;
	}
	,setGlobalY: function(value) {
		var localY = value;
		if(this._parent != null) {
			var parentGlobalY = this._parent.getGlobalY();
			localY -= parentGlobalY;
		} else localY = 0;
		this._style.setNativeY(this,localY);
		return value;
	}
	,getGlobalY: function() {
		var newGlobalY = this._style.getNativeY();
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalY += parentDOMElement.getStyle().getNativeY();
				parentDOMElement = parentDOMElement.getParent();
			}
		} else newGlobalY = 0;
		return newGlobalY;
	}
	,getStyle: function() {
		return this._style;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractDOMElement
	,__properties__: {set_isVisible:"setIsVisible",get_isVisible:"getIsVisible",set_alpha:"setAlpha",get_alpha:"getAlpha",set_rotation:"setRotation",get_rotation:"getRotation",set_scaleY:"setScaleY",get_scaleY:"getScaleY",set_scaleX:"setScaleX",get_scaleX:"getScaleX",set_matrix:"setMatrix",get_matrix:"getMatrix",get_style:"getStyle",get_offsetHeight:"getOffsetHeight",get_offsetWidth:"getOffsetWidth",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_globalY:"setGlobalY",get_globalY:"getGlobalY",set_y:"setY",get_y:"getY",set_globalX:"setGlobalX",get_globalX:"getGlobalX",set_x:"setX",get_x:"getX",set_parent:"setParent",get_parent:"getParent",set_nativeElement:"setNativeElement",get_nativeElement:"getNativeElement",set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown",set_onMouseDoubleClick:"setOnMouseDoubleClick",get_onMouseDoubleClick:"getOnMouseDoubleClick",set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown"}
}
if(!cocktailCore.domElement.js) cocktailCore.domElement.js = {}
cocktailCore.domElement.js.DOMElement = $hxClasses["cocktailCore.domElement.js.DOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.DOMElement.__name__ = ["cocktailCore","domElement","js","DOMElement"];
cocktailCore.domElement.js.DOMElement.__super__ = cocktailCore.domElement.abstract.AbstractDOMElement;
cocktailCore.domElement.js.DOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.DOMElement
});
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement"] = function(nativeElement) {
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
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
	,initStyle: function() {
		this._style = new cocktailCore.style.js.EmbeddedStyle(this);
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
	,__class__: cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.DOMElement.prototype.__properties__,{get_intrinsicRatio:"getIntrinsicRatio",get_intrinsicHeight:"getIntrinsicHeight",get_intrinsicWidth:"getIntrinsicWidth"})
});
cocktailCore.domElement.js.EmbeddedDOMElement = $hxClasses["cocktailCore.domElement.js.EmbeddedDOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.EmbeddedDOMElement.__name__ = ["cocktailCore","domElement","js","EmbeddedDOMElement"];
cocktailCore.domElement.js.EmbeddedDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
cocktailCore.domElement.js.EmbeddedDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.EmbeddedDOMElement
});
cocktailCore.domElement.abstract.AbstractImageDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractImageDOMElement"] = function(nativeElement) {
	this._imageLoader = new cocktailCore.resource.js.ImageLoader(nativeElement);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,this._imageLoader.getNativeElement());
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
		if(allowCache == null) allowCache = true;
		this._imageLoader.load(url,this.onLoadComplete.$bind(this),this.onLoadError.$bind(this),allowCache);
	}
	,onLoadComplete: function(image) {
		this._style.invalidate();
		if(this.onLoad != null) this.onLoad(this);
	}
	,onLoadError: function(message) {
		if(this.onError != null) this.onError(message);
	}
	,getSrc: function() {
		return this._src;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractImageDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__properties__,{get_src:"getSrc"})
});
if(!cocktailCore.viewport) cocktailCore.viewport = {}
if(!cocktailCore.viewport["abstract"]) cocktailCore.viewport["abstract"] = {}
cocktailCore.viewport.abstract.AbstractViewport = $hxClasses["cocktailCore.viewport.abstract.AbstractViewport"] = function() {
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
		throw "this function is virtual, it is supposed to be implemented in the derived class";
	}
	,_removeResizeEvent: function() {
		throw "this function is virtual, it is supposed to be implemented in the derived class";
	}
	,_addOrientationChangeEvent: function() {
		throw "this function is virtual, it is supposed to be implemented in the derived class";
	}
	,_removeOrientationChangeEvent: function() {
		throw "this function is virtual, it is supposed to be implemented in the derived class";
	}
	,_getWidth: function() {
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		return -1;
	}
	,_getHeight: function() {
		throw "this function is virtual, it is supposed to be implemented in the derived class";
		return -1;
	}
	,_getOrientation: function() {
		if(this._getHeight() > this._getWidth()) return cocktail.viewport.OrientationValue.vertical; else return cocktail.viewport.OrientationValue.horizontal;
	}
	,_onResizeCallback: function(e) {
		if(this._getOnResize() != null) (this._getOnResize())();
	}
	,_onOrientationChangeCallback: function(e) {
		if(this._getOnOrientationChange() != null && this._lastOrientationObserved != this._getOrientation()) {
			this._lastOrientationObserved = this._getOrientation();
			(this._getOnOrientationChange())();
		}
	}
	,_onResize: null
	,_getOnResize: function() {
		return this._onResize;
	}
	,_setOnResize: function(callbackFunction) {
		if(this._onResize == null && callbackFunction != null) this._addResizeEvent(); else if(this._onResize != null && callbackFunction == null) this._removeResizeEvent();
		this._onResize = callbackFunction;
		return this._onResize;
	}
	,_onOrientationChange: null
	,_getOnOrientationChange: function() {
		return this._onOrientationChange;
	}
	,_setOnOrientationChange: function(callbackFunction) {
		this._lastOrientationObserved = this._getOrientation();
		if(this._onOrientationChange == null && callbackFunction != null) this._addOrientationChangeEvent(); else if(this._onOrientationChange != null && callbackFunction == null) this._removeOrientationChangeEvent();
		this._onOrientationChange = callbackFunction;
		return this._onOrientationChange;
	}
	,__class__: cocktailCore.viewport.abstract.AbstractViewport
	,__properties__: {get_orientation:"_getOrientation",get_height:"_getHeight",get_width:"_getWidth",set_onOrientationChange:"_setOnOrientationChange",get_onOrientationChange:"_getOnOrientationChange",set_onResize:"_setOnResize",get_onResize:"_getOnResize"}
}
if(!cocktailCore.viewport.js) cocktailCore.viewport.js = {}
cocktailCore.viewport.js.Viewport = $hxClasses["cocktailCore.viewport.js.Viewport"] = function() {
	cocktailCore.viewport.abstract.AbstractViewport.call(this);
}
cocktailCore.viewport.js.Viewport.__name__ = ["cocktailCore","viewport","js","Viewport"];
cocktailCore.viewport.js.Viewport.__super__ = cocktailCore.viewport.abstract.AbstractViewport;
cocktailCore.viewport.js.Viewport.prototype = $extend(cocktailCore.viewport.abstract.AbstractViewport.prototype,{
	_addResizeEvent: function() {
		js.Lib.window.addEventListener("resize",this._onResizeCallback.$bind(this),false);
	}
	,_removeResizeEvent: function() {
		js.Lib.window.removeEventListener("resize",this._onResizeCallback.$bind(this),false);
	}
	,_addOrientationChangeEvent: function() {
		js.Lib.window.addEventListener("resize",this._onOrientationChangeCallback.$bind(this),false);
	}
	,_removeOrientationChangeEvent: function() {
		js.Lib.window.removeEventListener("resize",this._onOrientationChangeCallback.$bind(this),false);
	}
	,_getWidth: function() {
		return js.Lib.window.innerWidth;
	}
	,_getHeight: function() {
		return js.Lib.window.innerHeight;
	}
	,__class__: cocktailCore.viewport.js.Viewport
});
if(!cocktailCore.style) cocktailCore.style = {}
if(!cocktailCore.style["abstract"]) cocktailCore.style["abstract"] = {}
cocktailCore.style.abstract.AbstractStyle = $hxClasses["cocktailCore.style.abstract.AbstractStyle"] = function(domElement) {
	this._domElement = domElement;
	this._isDirty = true;
	this._childrenTemporaryPositionData = new Array();
	this.initDefaultStyleValues();
}
cocktailCore.style.abstract.AbstractStyle.__name__ = ["cocktailCore","style","abstract","AbstractStyle"];
cocktailCore.style.abstract.AbstractStyle.getDefaultStyle = function() {
	return { fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], color : cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black)};
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
	,_opacity: null
	,opacity: null
	,_visibility: null
	,visibility: null
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
	,_childrenTemporaryPositionData: null
	,initDefaultStyleValues: function() {
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
		this.setTransformOrigin({ x : cocktail.style.TransformOriginXStyleValue.center, y : cocktail.style.TransformOriginYStyleValue.center});
		this.setTransform(cocktail.style.TransformStyleValue.none);
		var defaultStyles = cocktailCore.style.abstract.AbstractStyle.getDefaultStyle();
		this.setFontFamily(defaultStyles.fontFamily);
		this.setColor(defaultStyles.color);
	}
	,initComputedStyles: function() {
		this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, floatValue : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0, visibility : true, opacity : 1.0, transformOrigin : { x : 0.0, y : 0.0}, transform : new cocktail.geom.Matrix()};
	}
	,initNativeProperties: function() {
		this._nativeHeight = 0;
		this._nativeOpacity = 1.0;
		this._nativeRotation = 0.0;
		this._nativeScaleX = 1.0;
		this._nativeScaleY = 1.0;
		this._nativeVisibility = true;
		this._nativeWidth = 0;
		this._nativeX = 0;
		this._nativeY = 0;
	}
	,render: function() {
		var _g1 = 0, _g = this._childrenTemporaryPositionData.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeX(this._childrenTemporaryPositionData[i].domElement,this._childrenTemporaryPositionData[i].x + this._computedStyle.marginLeft + this._computedStyle.paddingLeft);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeY(this._childrenTemporaryPositionData[i].domElement,this._childrenTemporaryPositionData[i].y + this._computedStyle.marginTop + this._computedStyle.paddingTop);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeHeight(this._childrenTemporaryPositionData[i].domElement.getStyle().getComputedStyle().height);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeWidth(this._childrenTemporaryPositionData[i].domElement.getStyle().getComputedStyle().width);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeMatrix(this._childrenTemporaryPositionData[i].domElement.getStyle().getComputedStyle().transform);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeOpacity(this._childrenTemporaryPositionData[i].domElement.getStyle().getComputedStyle().opacity);
			this._childrenTemporaryPositionData[i].domElement.getStyle().setNativeVisibility(this._childrenTemporaryPositionData[i].domElement.getStyle().getComputedStyle().visibility);
			this.attachChild(this._childrenTemporaryPositionData[i].domElement);
		}
	}
	,attachChild: function(domElement) {
	}
	,detachChildren: function() {
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
	}
	,flow: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		this.detachChildren();
		if(this.isNotDisplayed() == true) {
			this.setNativeVisibility(false);
			return;
		} else this.setNativeVisibility(true);
		if(this.isClear() == true) formatingContext.clearFloat(this._computedStyle.clear,this.isFloat());
		this.initComputedStyles();
		this.computeDOMElementStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData.data,containingDOMElementFontMetricsData);
		this._childrenTemporaryPositionData = this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
		this.computeVisualEffectStyles();
		this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
		this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
		this._isDirty = false;
	}
	,positionElement: function(lastPositionedDOMElementData,viewportData,staticPosition) {
		var positioner;
		var childTemporaryPositionData;
		switch( (this._domElement.getStyle().getComputedStyle().position)[1] ) {
		case 1:
			positioner = new cocktailCore.style.positioner.RelativePositioner();
			childTemporaryPositionData = positioner.position(this._domElement,lastPositionedDOMElementData,staticPosition);
			break;
		case 3:
			positioner = new cocktailCore.style.positioner.FixedPositioner();
			childTemporaryPositionData = positioner.position(this._domElement,viewportData,staticPosition);
			break;
		case 2:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
			childTemporaryPositionData = positioner.position(this._domElement,lastPositionedDOMElementData,staticPosition);
			break;
		default:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
			childTemporaryPositionData = { domElement : this.getDOMElement(), x : 0, y : 0, lineIndex : 0};
		}
		return childTemporaryPositionData;
	}
	,scheduleLayout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData) {
		var layoutDelegate = this.layout.$bind(this);
		haxe.Timer.delay(function() {
			layoutDelegate(containingDOMElementData,lastPositionedDOMElementData,viewportData,null);
		},1);
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		return new Array();
	}
	,insertDOMElement: function(formattingContext,lastPositionedDOMElementData,viewportData) {
		if(this.isFloat() == true) formattingContext.insertFloat(this._domElement,this._domElement.getParent()); else if(this.isPositioned() == false) this.insertInFlowDOMElement(formattingContext); else {
			var x = 0;
			var y = 0;
			if(formattingContext != null) {
				x = formattingContext.getFormattingContextData().x;
				y = formattingContext.getFormattingContextData().y;
			}
			var staticPosition = { x : x, y : y};
			if(this.isRelativePositioned() == true) this.insertInFlowDOMElement(formattingContext);
			var positionedDOMElementData = { staticPosition : staticPosition, style : this, formattingContext : formattingContext};
			lastPositionedDOMElementData.children.push(positionedDOMElementData);
		}
	}
	,insertInFlowDOMElement: function(formattingContext) {
		if(this._domElement.getParent() != null) formattingContext.insert(this._domElement,this._domElement.getParent(),true);
	}
	,invalidate: function() {
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
	}
	,invalidateText: function() {
		this._fontMetrics = null;
		this.invalidate();
	}
	,invalidatePositionOffset: function() {
		if(this.isPositioned() == false) this.invalidate();
	}
	,invalidateMargin: function() {
		if(this.getPosition() == cocktail.style.PositionStyleValue.relative || this.getPosition() == cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
	}
	,isParentDirty: function() {
		var ret = true;
		if(this.isPositioned() == true && this.isRelativePositioned() == false) ret = false;
		return ret;
	}
	,computeDisplayStyles: function() {
		cocktailCore.style.computer.DisplayStylesComputer.compute(this);
	}
	,computeDOMElementStyles: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData) {
		this.computeDisplayStyles();
		this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
		this.computeBoxModelStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData);
	}
	,computeVisualEffectStyles: function() {
		cocktailCore.style.computer.VisualEffectStylesComputer.compute(this);
	}
	,computeTextAndFontStyles: function(containingDOMElementData,containingDOMElementFontMetricsData) {
		cocktailCore.style.computer.FontAndTextStylesComputer.compute(this,containingDOMElementData,containingDOMElementFontMetricsData);
	}
	,computeBoxModelStyles: function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
		var boxComputer = this.getBoxStylesComputer();
		var containingBlockDimensions = this.getContainingDOMElementData(containingDOMElementData,viewportData,lastPositionedDOMElementData);
		boxComputer.measure(this,containingBlockDimensions);
	}
	,getBoxStylesComputer: function() {
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
		return boxComputer;
	}
	,getContainingDOMElementData: function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
		var containingBlockDimensions;
		if(this.isPositioned() == true) {
			if(this._computedStyle.position == cocktail.style.PositionStyleValue.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto}; else if(this._computedStyle.position == cocktail.style.PositionStyleValue.absolute) containingBlockDimensions = { width : lastPositionedDOMElementData.width, height : lastPositionedDOMElementData.height, isHeightAuto : lastPositionedDOMElementData.isHeightAuto, isWidthAuto : lastPositionedDOMElementData.isWidthAuto}; else containingBlockDimensions = containingDOMElementData;
		} else containingBlockDimensions = containingDOMElementData;
		return containingBlockDimensions;
	}
	,isEmbedded: function() {
		return false;
	}
	,isFloat: function() {
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
		return this._computedStyle.position == cocktail.style.PositionStyleValue.relative;
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
		return this._computedStyle.display == cocktail.style.DisplayStyleValue.none;
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
	,getFirstPositionedAncestorData: function() {
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
		return firstPositionedAncestorData;
	}
	,getViewportData: function() {
		var viewPort = new cocktailCore.viewport.js.Viewport();
		var viewPortData = { isHeightAuto : false, isWidthAuto : false, width : viewPort._getWidth(), height : viewPort._getHeight()};
		return viewPortData;
	}
	,setNativeX: function(domElement,x) {
		if(domElement == this._domElement) this._nativeX = x;
	}
	,getNativeX: function() {
		return this._nativeX;
	}
	,setNativeY: function(domElement,y) {
		if(domElement == this._domElement) this._nativeY = y;
	}
	,getNativeY: function() {
		return this._nativeY;
	}
	,setNativeWidth: function(width) {
		this._nativeWidth = width;
	}
	,getNativeWidth: function() {
		return this._nativeWidth;
	}
	,setNativeHeight: function(height) {
		this._nativeHeight = height;
	}
	,getNativeHeight: function() {
		return this._nativeHeight;
	}
	,setNativeScaleX: function(scaleX) {
		this._nativeScaleX = scaleX;
	}
	,getNativeScaleX: function() {
		return this._nativeScaleX;
	}
	,setNativeScaleY: function(scaleY) {
		this._nativeScaleY = scaleY;
	}
	,getNativeScaleY: function() {
		return this._nativeScaleY;
	}
	,setNativeRotation: function(rotation) {
		this._nativeRotation = rotation;
	}
	,getNativeRotation: function() {
		return this._nativeRotation;
	}
	,setNativeMatrix: function(matrix) {
		this._nativeMatrix = matrix;
	}
	,getNativeMatrix: function() {
		return this._nativeMatrix;
	}
	,setNativeOpacity: function(opacity) {
		this._nativeOpacity = opacity;
	}
	,getNativeOpacity: function() {
		return this._nativeOpacity;
	}
	,setNativeVisibility: function(visible) {
		this._nativeVisibility = visible;
	}
	,getNativeVisibility: function() {
		return this._nativeVisibility;
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
	,getDOMElement: function() {
		return this._domElement;
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
	,setFloatValue: function(value) {
		this.invalidate();
		return this._floatValue = value;
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
	,getFloatValue: function() {
		return this._floatValue;
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
	,__class__: cocktailCore.style.abstract.AbstractStyle
	,__properties__: {get_fontMetrics:"getFontMetricsData",get_domElement:"getDOMElement",set_computedStyle:"setComputedStyle",get_computedStyle:"getComputedStyle",set_verticalAlign:"setVerticalAlign",get_verticalAlign:"getVerticalAlign",set_textIndent:"setTextIndent",get_textIndent:"getTextIndent",set_textAlign:"setTextAlign",get_textAlign:"getTextAlign",set_whiteSpace:"setWhiteSpace",get_whiteSpace:"getWhiteSpace",set_wordSpacing:"setWordSpacing",get_wordSpacing:"getWordSpacing",set_letterSpacing:"setLetterSpacing",get_letterSpacing:"getLetterSpacing",set_textTransform:"setTextTransform",get_textTransform:"getTextTransform",set_lineHeight:"setLineHeight",get_lineHeight:"getLineHeight",set_color:"setColor",get_color:"getColor",set_fontVariant:"setFontVariant",get_fontVariant:"getFontVariant",set_fontFamily:"setFontFamily",get_fontFamily:"getFontFamily",set_fontStyle:"setFontStyle",get_fontStyle:"getFontStyle",set_fontWeight:"setFontWeight",get_fontWeight:"getFontWeight",set_fontSize:"setFontSize",get_fontSize:"getFontSize",set_right:"setRight",get_right:"getRight",set_bottom:"setBottom",get_bottom:"getBottom",set_left:"setLeft",get_left:"getLeft",set_top:"setTop",get_top:"getTop",set_maxWidth:"setMaxWidth",get_maxWidth:"getMaxWidth",set_minWidth:"setMinWidth",get_minWidth:"getMinWidth",set_maxHeight:"setMaxHeight",get_maxHeight:"getMaxHeight",set_minHeight:"setMinHeight",get_minHeight:"getMinHeight",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_paddingBottom:"setPaddingBottom",get_paddingBottom:"getPaddingBottom",set_paddingTop:"setPaddingTop",get_paddingTop:"getPaddingTop",set_paddingRight:"setPaddingRight",get_paddingRight:"getPaddingRight",set_paddingLeft:"setPaddingLeft",get_paddingLeft:"getPaddingLeft",set_marginBottom:"setMarginBottom",get_marginBottom:"getMarginBottom",set_marginTop:"setMarginTop",get_marginTop:"getMarginTop",set_marginRight:"setMarginRight",get_marginRight:"getMarginRight",set_marginLeft:"setMarginLeft",get_marginLeft:"getMarginLeft",set_transform:"setTransform",get_transform:"getTransform",set_transformOrigin:"setTransformOrigin",get_transformOrigin:"getTransformOrigin",set_visibility:"setVisibility",get_visibility:"getVisibility",set_opacity:"setOpacity",get_opacity:"getOpacity",set_clear:"setClear",get_clear:"getClear",set_floatValue:"setFloatValue",get_floatValue:"getFloatValue",set_position:"setPosition",get_position:"getPosition",set_display:"setDisplay",get_display:"getDisplay"}
}
if(!cocktailCore.style.js) cocktailCore.style.js = {}
cocktailCore.style.js.Style = $hxClasses["cocktailCore.style.js.Style"] = function(domElement) {
	cocktailCore.style.abstract.AbstractStyle.call(this,domElement);
}
cocktailCore.style.js.Style.__name__ = ["cocktailCore","style","js","Style"];
cocktailCore.style.js.Style.__super__ = cocktailCore.style.abstract.AbstractStyle;
cocktailCore.style.js.Style.prototype = $extend(cocktailCore.style.abstract.AbstractStyle.prototype,{
	flow: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
		this.setNativeHeight(this._domElement.getNativeElement().clientHeight);
		this.setNativeWidth(this._domElement.getNativeElement().clientWidth);
		this.setNativeX(this._domElement,this._domElement.getNativeElement().offsetLeft);
		this.setNativeY(this._domElement,this._domElement.getNativeElement().offsetTop);
		this._isDirty = false;
	}
	,getCSSDisplay: function(value) {
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
	,getCSSFloat: function(value) {
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
		return cssFloatValue;
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
	,getCSSOpacity: function(value) {
		var cssOpacityValue;
		var $e = (value);
		switch( $e[1] ) {
		case 0:
			var value1 = $e[2];
			cssOpacityValue = Std.string(value1);
			break;
		}
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
		return cssTransformFunction;
	}
	,getCSSTranslation: function(translation) {
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
		return cssTranslationValue;
	}
	,getCSSTransformOrigin: function(value) {
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
		return cssTransformOriginValue;
	}
	,getCSSMargin: function(value) {
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
		return cssMarginValue;
	}
	,getCSSPadding: function(value) {
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
		return cssPaddingValue;
	}
	,getCSSDimension: function(value) {
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
		return cssDimensionValue;
	}
	,getCSSPositionOffset: function(value) {
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
		return cssPositionOffsetValue;
	}
	,getCSSConstrainedDimension: function(value) {
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
			cssVerticalAlignValue = this.getCSSLengthValue(value1);
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
		return cssLineHeightValue;
	}
	,getCSSFontSize: function(value) {
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
			cssTextIndentValue = this.getCSSLengthValue(value1);
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
			cssLetterSpacingValue = this.getCSSLengthValue(unit);
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
			cssWordSpacingValue = this.getCSSLengthValue(unit);
			break;
		}
		return cssWordSpacingValue;
	}
	,getCSSColor: function(value) {
		var cssColorValue;
		var $e = (value);
		switch( $e[1] ) {
		case 1:
			var value1 = $e[2];
			cssColorValue = value1;
			break;
		case 0:
			var blue = $e[4], green = $e[3], red = $e[2];
			cssColorValue = "rgb(" + red + "," + green + "," + blue + ")";
			break;
		case 2:
			var value1 = $e[2];
			cssColorValue = this.getColorFromKeyword(value1);
			break;
		}
		return cssColorValue;
	}
	,getCSSLengthValue: function(lengthValue) {
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
	,getCSSAngleValue: function(value) {
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
		this._domElement.getNativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setVerticalAlign.call(this,value);
		return this._verticalAlign = value;
	}
	,setColor: function(value) {
		this._domElement.getNativeElement().style.color = this.getCSSColor(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setColor.call(this,value);
		return this._color = value;
	}
	,setWordSpacing: function(value) {
		this._domElement.getNativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWordSpacing.call(this,value);
		return this._wordSpacing = value;
	}
	,setLetterSpacing: function(value) {
		this._domElement.getNativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLetterSpacing.call(this,value);
		return this._letterSpacing = value;
	}
	,setTextTransform: function(value) {
		this._domElement.getNativeElement().style.textTransform = this.getCSSTextTransform(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextTransform.call(this,value);
		return this._textTransform = value;
	}
	,setFontVariant: function(value) {
		this._domElement.getNativeElement().style.fontVariant = this.getCSSFontVariant(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontVariant.call(this,value);
		return this._fontVariant = value;
	}
	,setFontFamily: function(value) {
		this._domElement.getNativeElement().style.fontFamily = this.getCSSFontFamily(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontFamily.call(this,value);
		return this._fontFamily = value;
	}
	,setFontWeight: function(value) {
		this._domElement.getNativeElement().style.fontWeight = this.getCSSFontWeight(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontWeight.call(this,value);
		return this._fontWeight = value;
	}
	,setFontStyle: function(value) {
		this._domElement.getNativeElement().style.fontStyle = this.getCSSFontStyle(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontStyle.call(this,value);
		return this._fontStyle = value;
	}
	,setFontSize: function(value) {
		this._domElement.getNativeElement().style.fontSize = this.getCSSFontSize(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFontSize.call(this,value);
		return this._fontSize = value;
	}
	,setLineHeight: function(value) {
		this._domElement.getNativeElement().style.lineHeight = this.getCSSLineHeight(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLineHeight.call(this,value);
		return this._lineHeight = value;
	}
	,setMarginLeft: function(value) {
		this._domElement.getNativeElement().style.marginLeft = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginLeft.call(this,value);
		return this._marginLeft = value;
	}
	,setMarginRight: function(value) {
		this._domElement.getNativeElement().style.marginRight = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginRight.call(this,value);
		return this._marginRight = value;
	}
	,setMarginTop: function(value) {
		this._domElement.getNativeElement().style.marginTop = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginTop.call(this,value);
		return this._marginTop = value;
	}
	,setMarginBottom: function(value) {
		this._domElement.getNativeElement().style.marginBottom = this.getCSSMargin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMarginBottom.call(this,value);
		return this._marginBottom = value;
	}
	,setPaddingLeft: function(value) {
		this._domElement.getNativeElement().style.paddingLeft = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingLeft.call(this,value);
		return this._paddingLeft = value;
	}
	,setPaddingRight: function(value) {
		this._domElement.getNativeElement().style.paddingRight = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingRight.call(this,value);
		return this._paddingRight = value;
	}
	,setPaddingTop: function(value) {
		this._domElement.getNativeElement().style.paddingTop = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingTop.call(this,value);
		return this._paddingTop = value;
	}
	,setPaddingBottom: function(value) {
		this._domElement.getNativeElement().style.paddingBottom = this.getCSSPadding(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingBottom.call(this,value);
		return this._paddingBottom = value;
	}
	,setDisplay: function(value) {
		this._domElement.getNativeElement().style.display = this.getCSSDisplay(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setDisplay.call(this,value);
		return this._display = value;
	}
	,setPosition: function(value) {
		this._domElement.getNativeElement().style.position = this.getCSSPosition(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setPosition.call(this,value);
		return this._position = value;
	}
	,setWidth: function(value) {
		this._domElement.getNativeElement().style.width = this.getCSSDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWidth.call(this,value);
		return this._width = value;
	}
	,setHeight: function(value) {
		this._domElement.getNativeElement().style.height = this.getCSSDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setHeight.call(this,value);
		return this._height = value;
	}
	,setMinHeight: function(value) {
		this._domElement.getNativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMinHeight.call(this,value);
		return this._minHeight = value;
	}
	,setMaxHeight: function(value) {
		this._domElement.getNativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMaxHeight.call(this,value);
		return this._maxHeight = value;
	}
	,setMinWidth: function(value) {
		this._domElement.getNativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMinWidth.call(this,value);
		return this._minWidth = value;
	}
	,setMaxWidth: function(value) {
		this._domElement.getNativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setMaxWidth.call(this,value);
		return this._maxWidth = value;
	}
	,setTop: function(value) {
		this._domElement.getNativeElement().style.top = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTop.call(this,value);
		return this._top = value;
	}
	,setLeft: function(value) {
		this._domElement.getNativeElement().style.left = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setLeft.call(this,value);
		return this._left = value;
	}
	,setBottom: function(value) {
		this._domElement.getNativeElement().style.bottom = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setBottom.call(this,value);
		return this._bottom = value;
	}
	,setRight: function(value) {
		this._domElement.getNativeElement().style.right = this.getCSSPositionOffset(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setRight.call(this,value);
		return this._right = value;
	}
	,setTextIndent: function(value) {
		this._domElement.getNativeElement().style.textIndent = this.getCSSTextIndent(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextIndent.call(this,value);
		return this._textIndent = value;
	}
	,setFloatValue: function(value) {
		this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFloatValue.call(this,value);
		return this.floatValue = value;
	}
	,setClear: function(value) {
		this._domElement.getNativeElement().style.clear = this.getCSSClear(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setClear.call(this,value);
		return this._clear = value;
	}
	,setWhiteSpace: function(value) {
		this._domElement.getNativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setWhiteSpace.call(this,value);
		return this._whiteSpace = value;
	}
	,setTextAlign: function(value) {
		this._domElement.getNativeElement().style.textAlign = this.getCSSTextAlign(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTextAlign.call(this,value);
		return this._textAlign = value;
	}
	,setOpacity: function(value) {
		this._domElement.getNativeElement().style.opacity = this.getCSSOpacity(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setOpacity.call(this,value);
		return this._opacity = value;
	}
	,setVisibility: function(value) {
		this._domElement.getNativeElement().style.visibility = this.getCSSVisibility(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setVisibility.call(this,value);
		return this._visibility = value;
	}
	,setTransformOrigin: function(value) {
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transformOrigin");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransformOrigin(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTransformOrigin.call(this,value);
		return this._transformOrigin = value;
	}
	,setTransform: function(value) {
		var nativeStyle = this._domElement.getNativeElement().style;
		var vendorSpecificName = this.getVendorSpecificStyleName(nativeStyle,"transform");
		if(vendorSpecificName != null) nativeStyle[vendorSpecificName] = this.getCSSTransform(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setTransform.call(this,value);
		return this._transform = value;
	}
	,__class__: cocktailCore.style.js.Style
});
cocktailCore.style.abstract.AbstractContainerStyle = $hxClasses["cocktailCore.style.abstract.AbstractContainerStyle"] = function(domElement) {
	cocktailCore.style.js.Style.call(this,domElement);
}
cocktailCore.style.abstract.AbstractContainerStyle.__name__ = ["cocktailCore","style","abstract","AbstractContainerStyle"];
cocktailCore.style.abstract.AbstractContainerStyle.__super__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractContainerStyle.prototype = $extend(cocktailCore.style.js.Style.prototype,{
	render: function() {
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().render();
			}
		}
		cocktailCore.style.js.Style.prototype.render.call(this);
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
		this.flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,null,null);
		this.render();
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().computeDisplayStyles();
			}
		}
		var childrenFormattingContext;
		if(formatingContext == null) {
			formatingContext = this.getFormatingContext();
			childrenFormattingContext = this.getFormatingContext();
		} else childrenFormattingContext = this.getFormatingContext(formatingContext);
		var childrenContainingDOMElementData = this.getContainerDOMElementData();
		var childrenContainingDOMElementFontMetricsData = this.getFontMetricsData();
		var childLastPositionedDOMElementData;
		childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		var childrenTemporaryPositionsData = this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
		if(this._width == cocktail.style.DimensionStyleValue.autoValue) {
			var currentWidth = this._computedStyle.width;
			this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData,childrenFormattingContext.getFormattingContextData().maxWidth);
			if(currentWidth != this._computedStyle.width) {
				childrenFormattingContext = this.getFormatingContext(formatingContext);
				childrenContainingDOMElementData = this.getContainerDOMElementData();
				childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
				childrenTemporaryPositionsData = this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
			}
		}
		if(this._height == cocktail.style.DimensionStyleValue.autoValue) this._computedStyle.height = this.applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getFormattingContextData().maxHeight);
		formatingContext.retrieveFloats(childrenFormattingContext);
		var absolutelyPositionedChildrenTemporaryPositionsData = this.doPositionAbsolutelyPositionedDOMElements(this.isPositioned(),childLastPositionedDOMElementData,viewportData);
		var _g1 = 0, _g = absolutelyPositionedChildrenTemporaryPositionsData.length;
		while(_g1 < _g) {
			var i = _g1++;
			childrenTemporaryPositionsData.push(absolutelyPositionedChildrenTemporaryPositionsData[i]);
		}
		return childrenTemporaryPositionsData;
	}
	,insertInFlowDOMElement: function(formattingContext) {
		if(this.establishesNewFormattingContext() == true) {
			if(this._domElement.getParent() != null) formattingContext.insert(this._domElement,this._domElement.getParent(),true);
		} else if(this._domElement.getParent() != null) formattingContext.insert(this._domElement,this._domElement.getParent(),false);
	}
	,doFlowChildren: function(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext) {
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().flow(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
			} else {
				var childrenTextElement = containerDOMElement.getChildren()[i].child;
				this.insertTextElement(childrenTextElement,childrenFormattingContext,childrenContainingDOMElementData);
			}
		}
		if(this.establishesNewFormattingContext() == true) childrenFormattingContext.destroy();
		var childrenTemporaryPositionData = childrenFormattingContext.getChildrenTemporaryPositionData(this._domElement);
		return childrenTemporaryPositionData;
	}
	,doPositionAbsolutelyPositionedDOMElements: function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
		var childrenTemporaryPositionData = new Array();
		if(isFirstPositionedAncestor == true) {
			childLastPositionedDOMElementData.data = this.getContainerDOMElementData();
			childLastPositionedDOMElementData.data.height = this._computedStyle.height;
			var _g1 = 0, _g = childLastPositionedDOMElementData.children.length;
			while(_g1 < _g) {
				var i = _g1++;
				var positionedDOMElementData = childLastPositionedDOMElementData.children[i];
				if(positionedDOMElementData.style.isRelativePositioned() == true) {
					if(positionedDOMElementData.formattingContext != null) {
						var children = positionedDOMElementData.formattingContext.getChildrenTemporaryPositionData(positionedDOMElementData.style.getDOMElement().getParent());
						var _g3 = 0, _g2 = children.length;
						while(_g3 < _g2) {
							var i1 = _g3++;
							if(children[i1].domElement == positionedDOMElementData.style.getDOMElement()) {
								var x = children[i1].x;
								var y = children[i1].y;
								positionedDOMElementData.staticPosition = { x : x, y : y};
							}
						}
					}
				}
				var childTemporaryPositionData = positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data,viewportData,positionedDOMElementData.staticPosition);
				if(positionedDOMElementData.formattingContext != null) {
					var formattingContextRootParent = positionedDOMElementData.formattingContext.getContainingDOMElement();
					var xOffset = formattingContextRootParent.getGlobalX() - this._domElement.getGlobalX();
					var yOffset = formattingContextRootParent.getGlobalY() - this._domElement.getGlobalY();
					childTemporaryPositionData.x += xOffset;
					childTemporaryPositionData.y += yOffset;
				}
				if(childTemporaryPositionData.domElement.getStyle().isRelativePositioned() == false) {
					childTemporaryPositionData.x -= this._computedStyle.paddingLeft + this._computedStyle.marginLeft;
					childTemporaryPositionData.y -= this._computedStyle.marginTop + this._computedStyle.paddingTop;
				}
				childrenTemporaryPositionData.push(childTemporaryPositionData);
			}
		}
		return childrenTemporaryPositionData;
	}
	,insertTextElement: function(textElement,formattingContext,containingDOMElementData) {
		var containerDOMElement = this._domElement;
		var text = textElement.getNativeText();
		text = cocktailCore.textElement.abstract.AbstractTextElement.applyWhiteSpace(text,this._computedStyle.whiteSpace);
		var textFragments = textElement.getTextFragments(text);
		var _g1 = 0, _g = textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			var $e = (textFragments[i].textToken);
			switch( $e[1] ) {
			case 0:
				var value = $e[2];
				formattingContext.insert(this.getTextFragmentDOMElement(textFragments[i],value),this._domElement,true);
				break;
			case 1:
				formattingContext.insertSpace(this.getTextFragmentDOMElement(textFragments[i]," "),this._domElement);
				break;
			case 2:
				formattingContext.insertTab(this.getTextFragmentDOMElement(textFragments[i]," "),this._domElement);
				break;
			case 3:
				formattingContext.insertLineFeed();
				break;
			}
		}
	}
	,shrinkToFitIfNeeded: function(containingDOMElementData,minimumWidth) {
		var boxComputer = this.getBoxStylesComputer();
		return boxComputer.shrinkToFit(this,containingDOMElementData,minimumWidth);
	}
	,applyContentHeightIfNeeded: function(containingDOMElementData,childrenHeight) {
		var boxComputer = this.getBoxStylesComputer();
		return boxComputer.applyContentHeight(this,containingDOMElementData,childrenHeight);
	}
	,invalidateText: function() {
		var containerDOMElement = this._domElement;
		containerDOMElement.resetTextFragments();
		cocktailCore.style.js.Style.prototype.invalidateText.call(this);
	}
	,getTextFragmentDOMElement: function(textFragmentData,text) {
		var textFragmentDOMElement;
		if(textFragmentData.textFragmentDOMElement == null) {
			textFragmentDOMElement = this.createTextFragment(text);
			textFragmentData.textFragmentDOMElement = textFragmentDOMElement;
		} else textFragmentDOMElement = textFragmentData.textFragmentDOMElement;
		return textFragmentDOMElement;
	}
	,createTextFragment: function(text) {
		var textFragmentDOMElement = this.doCreateTextFragment(text);
		var containerDOMElement = this._domElement;
		containerDOMElement.addTextFragment(textFragmentDOMElement);
		return textFragmentDOMElement;
	}
	,doCreateTextFragment: function(text) {
		return null;
	}
	,getContainerDOMElementData: function() {
		var height;
		if(this.isInlineLevel() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.isInlineLevel() == false && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
		return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.autoValue, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.autoValue};
	}
	,getFormatingContext: function(previousFormatingContext) {
		var containerDOMElement = this._domElement;
		var formattingContext;
		if(this.establishesNewFormattingContext() == true) {
			var usedFormatingContext;
			if(this.isPositioned() == true && this.isRelativePositioned() == false) usedFormatingContext = null; else usedFormatingContext = previousFormatingContext;
			if(this.childrenInline() == true) formattingContext = new cocktailCore.style.formatter.InlineFormattingContext(containerDOMElement,usedFormatingContext); else formattingContext = new cocktailCore.style.formatter.BlockFormattingContext(containerDOMElement,usedFormatingContext);
		} else formattingContext = previousFormatingContext;
		return formattingContext;
	}
	,childrenInline: function() {
		var containerDOMElement = this._domElement;
		if(containerDOMElement.getChildren().length == 0) return false;
		var ret = this.isChildInline(containerDOMElement.getChildren()[0]);
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isChildInline(containerDOMElement.getChildren()[i]) != ret) {
			}
		}
		return ret;
	}
	,isChildInline: function(child) {
		var ret = true;
		if(this.isDOMElement(child)) {
			var childrenDOMElement = child.child;
			if(childrenDOMElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.block) {
				if(childrenDOMElement.getStyle().isFloat() == false) ret = false; else if(childrenDOMElement.getStyle().isPositioned() == false || childrenDOMElement.getStyle().isRelativePositioned() == true) ret = false;
			} else ret = true;
		} else ret = true;
		return ret;
	}
	,getChildLastPositionedDOMElementData: function(lastPositionedDOMElementData) {
		var childLastPositionedDOMElementData;
		if(this.isPositioned() == true) childLastPositionedDOMElementData = { data : this.getContainerDOMElementData(), children : new Array()}; else childLastPositionedDOMElementData = lastPositionedDOMElementData;
		return childLastPositionedDOMElementData;
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
	,isDOMElement: function(containerDOMElementChildData) {
		var ret = false;
		switch( (containerDOMElementChildData.type)[1] ) {
		case 0:
			ret = true;
			break;
		case 1:
			ret = false;
			break;
		}
		return ret;
	}
	,__class__: cocktailCore.style.abstract.AbstractContainerStyle
});
var List = $hxClasses["List"] = function() {
	this.length = 0;
}
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
if(!cocktailCore.keyboard) cocktailCore.keyboard = {}
if(!cocktailCore.keyboard["abstract"]) cocktailCore.keyboard["abstract"] = {}
cocktailCore.keyboard.abstract.AbstractKeyboard = $hxClasses["cocktailCore.keyboard.abstract.AbstractKeyboard"] = function() {
}
cocktailCore.keyboard.abstract.AbstractKeyboard.__name__ = ["cocktailCore","keyboard","abstract","AbstractKeyboard"];
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype = {
	_onKeyDown: null
	,onKeyDown: null
	,_onKeyUp: null
	,onKeyUp: null
	,onNativeKeyDown: function(event) {
		if(this.getOnKeyDown() != null) (this.getOnKeyDown())(this.getKeyData(event));
	}
	,onNativeKeyUp: function(event) {
		if(this.getOnKeyUp() != null) (this.getOnKeyUp())(this.getKeyData(event));
	}
	,setOnKeyDown: function(value) {
		return this._onKeyDown = value;
	}
	,getOnKeyDown: function() {
		return this._onKeyDown;
	}
	,setOnKeyUp: function(value) {
		return this._onKeyUp = value;
	}
	,getOnKeyUp: function() {
		return this._onKeyUp;
	}
	,getKeyData: function(event) {
		return null;
	}
	,getKeyValue: function(keyCode) {
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
		return keyboardKeyValue;
	}
	,__class__: cocktailCore.keyboard.abstract.AbstractKeyboard
	,__properties__: {set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown"}
}
if(!cocktailCore.keyboard.js) cocktailCore.keyboard.js = {}
cocktailCore.keyboard.js.Keyboard = $hxClasses["cocktailCore.keyboard.js.Keyboard"] = function() {
	cocktailCore.keyboard.abstract.AbstractKeyboard.call(this);
}
cocktailCore.keyboard.js.Keyboard.__name__ = ["cocktailCore","keyboard","js","Keyboard"];
cocktailCore.keyboard.js.Keyboard.__super__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
cocktailCore.keyboard.js.Keyboard.prototype = $extend(cocktailCore.keyboard.abstract.AbstractKeyboard.prototype,{
	setOnKeyDown: function(value) {
		if(value == null) js.Lib.document.removeEventListener("keydown",this.onNativeKeyDown.$bind(this)); else js.Lib.document.addEventListener("keydown",this.onNativeKeyDown.$bind(this));
		return this._onKeyDown = value;
	}
	,setOnKeyUp: function(value) {
		if(value == null) js.Lib.document.removeEventListener("keyup",this.onNativeKeyUp.$bind(this)); else js.Lib.document.addEventListener("keyup",this.onNativeKeyUp.$bind(this));
		return this._onKeyUp = value;
	}
	,getKeyData: function(event) {
		var key = { value : this.getKeyValue(event.keyCode), code : event.keyCode, ascii : event.charCode, altKey : event.altKey, controlKey : event.ctrlKey, shiftKey : event.shiftKey};
		return key;
	}
	,__class__: cocktailCore.keyboard.js.Keyboard
});
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
var components = components || {}
if(!components.dataProvider) components.dataProvider = {}
components.dataProvider.ThumbTextList1Rss = $hxClasses["components.dataProvider.ThumbTextList1Rss"] = function() { }
components.dataProvider.ThumbTextList1Rss.__name__ = ["components","dataProvider","ThumbTextList1Rss"];
components.dataProvider.ThumbTextList1Rss.rss2Cells = function(rss) {
	var cells = new Array();
	var channelNode = rss.firstElement().firstElement();
	var $it0 = channelNode.elements();
	while( $it0.hasNext() ) {
		var channelChild = $it0.next();
		if(channelChild.getNodeName() == "item") {
			var cell = { content : Dynamic, action : "", actionTarget : ""};
			var cellContent = { imagePath : "", title : "", comment : "Posted ", description : "", commentCount : "0"};
			var $it1 = channelChild.elements();
			while( $it1.hasNext() ) {
				var itemParam = $it1.next();
				if(itemParam.getNodeName() == "post_thumbnail") cellContent.thumbnail = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "post_images") {
					if(!Reflect.hasField(cellContent,"thumbnail") || Reflect.field(cellContent,"thumbnail") == "") {
						var $it2 = itemParam.elements();
						while( $it2.hasNext() ) {
							var elements = $it2.next();
							cellContent.thumbnail = itemParam.firstElement().firstChild().getNodeValue();
							break;
						}
					}
				}
				if(itemParam.getNodeName() == "title") {
					var title = itemParam.firstChild().getNodeValue();
					var index = title.indexOf("Name");
					if(index != -1) title = title.substr(0,index);
					cellContent.title = title;
				}
				if(itemParam.getNodeName() == "dc:creator") cellContent.comment = cellContent.comment + "by " + itemParam.firstChild().getNodeValue() + " ";
				if(itemParam.getNodeName() == "pubDate") cellContent.comment = cellContent.comment + "on " + itemParam.firstChild().getNodeValue().substr(0,16) + " ";
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
					cellContent.description = text;
				}
				if(itemParam.getNodeName() == "comment_count") cellContent.commentCount = itemParam.firstChild().getNodeValue();
				if(itemParam.getNodeName() == "guid") {
					cell.action = "goToUrl";
					cell.actionTarget = itemParam.firstChild().getNodeValue();
				}
			}
			cell.content = cellContent;
			cells.push(cell);
		}
	}
	return cells;
}
components.dataProvider.ThumbTextList1Rss.prototype = {
	__class__: components.dataProvider.ThumbTextList1Rss
}
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = $hxClasses["cocktailCore.resource.abstract.AbstractResourceLoader"] = function(nativeElement) {
	if(nativeElement != null) this._nativeElement = nativeElement;
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype = {
	_onLoadCompleteCallback: null
	,_onLoadErrorCallback: null
	,_nativeElement: null
	,nativeElement: null
	,load: function(url,onLoadComplete,onLoadError,allowCache) {
		if(allowCache == null) allowCache = true;
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		if(allowCache == false) url = this.disableUrlCaching(url);
		this.doLoad(url);
	}
	,doLoad: function(url) {
	}
	,onLoadComplete: function(data) {
		this._onLoadCompleteCallback(data);
	}
	,onLoadError: function(msg) {
		this._onLoadErrorCallback(msg);
	}
	,disableUrlCaching: function(url) {
		var getId = "";
		if(url.indexOf("?") == -1) getId = "?"; else getId = "&";
		url += getId + "rand=" + Math.round(Math.random() * 10000);
		return url;
	}
	,getNativeElement: function() {
		return this._nativeElement;
	}
	,__class__: cocktailCore.resource.abstract.AbstractResourceLoader
	,__properties__: {get_nativeElement:"getNativeElement"}
}
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ResourceLoader = $hxClasses["cocktailCore.resource.js.ResourceLoader"] = function(nativeElement) {
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.js.ResourceLoader.__name__ = ["cocktailCore","resource","js","ResourceLoader"];
cocktailCore.resource.js.ResourceLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.ResourceLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	doLoad: function(url) {
		var onLoadCompleteDelegate = this.onLoadComplete.$bind(this);
		var onLoadErrorDelegate = this.onLoadError.$bind(this);
		var nativeElementDelegate = this._nativeElement;
		this._nativeElement.onload = function() {
			onLoadCompleteDelegate(nativeElementDelegate);
		};
		this._nativeElement.onerror = function() {
			onLoadErrorDelegate("couldn't load picture");
		};
		this._nativeElement.setAttribute("src",url);
	}
	,__class__: cocktailCore.resource.js.ResourceLoader
});
cocktailCore.resource.abstract.AbstractLibraryLoader = $hxClasses["cocktailCore.resource.abstract.AbstractLibraryLoader"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.library);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.abstract.AbstractLibraryLoader.__name__ = ["cocktailCore","resource","abstract","AbstractLibraryLoader"];
cocktailCore.resource.abstract.AbstractLibraryLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractLibraryLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	onLoadComplete: function(data) {
		this._onLoadCompleteCallback(null);
	}
	,__class__: cocktailCore.resource.abstract.AbstractLibraryLoader
});
if(!cocktailCore.style.computer) cocktailCore.style.computer = {}
cocktailCore.style.computer.BoxStylesComputer = $hxClasses["cocktailCore.style.computer.BoxStylesComputer"] = function() {
}
cocktailCore.style.computer.BoxStylesComputer.__name__ = ["cocktailCore","style","computer","BoxStylesComputer"];
cocktailCore.style.computer.BoxStylesComputer.prototype = {
	measure: function(style,containingDOMElementData) {
		this.measureHorizontalPaddings(style,containingDOMElementData);
		this.measureVerticalPaddings(style,containingDOMElementData);
		this.measureDimensionsConstraints(style,containingDOMElementData);
		this.measureWidthAndHorizontalMargins(style,containingDOMElementData);
		this.measureHeightAndVerticalMargins(style,containingDOMElementData);
		this.measurePositionOffsets(style,containingDOMElementData);
	}
	,shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		return style.getComputedStyle().width;
	}
	,applyContentHeight: function(style,cotainingDOMElementData,childrenHeight) {
		return childrenHeight;
	}
	,measureDimensionsConstraints: function(style,containingDOMElementData) {
		style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
		style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,measurePositionOffsets: function(style,containingDOMElementData) {
		style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureVerticalPaddings: function(style,containingDOMElementData) {
		style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureHorizontalPaddings: function(style,containingDOMElementData) {
		style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureWidthAndHorizontalMargins: function(style,containingDOMElementData) {
		if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
	}
	,measureAutoWidth: function(style,containingDOMElementData) {
		this.setComputedWidth(style,0);
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingDOMElementData));
	}
	,measureWidth: function(style,containingDOMElementData) {
		this.setComputedWidth(style,this.getComputedWidth(style,containingDOMElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	}
	,measureHeightAndVerticalMargins: function(style,containingDOMElementData) {
		if(style.getHeight() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	}
	,measureHeight: function(style,containingDOMElementData) {
		this.setComputedHeight(style,this.getComputedHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	}
	,constrainWidth: function(style) {
		var computedStyle = style.getComputedStyle();
		if(style.getMaxWidth() != cocktail.style.ConstrainedDimensionStyleValue.none) {
			if(computedStyle.width > computedStyle.maxWidth) computedStyle.width = computedStyle.maxWidth;
		}
		if(computedStyle.width < computedStyle.minWidth) computedStyle.width = computedStyle.minWidth;
	}
	,constrainHeight: function(style) {
		var computedStyle = style.getComputedStyle();
		if(style.getHeight() != cocktail.style.DimensionStyleValue.autoValue) {
			if(style.getMaxHeight() != cocktail.style.ConstrainedDimensionStyleValue.none) {
				if(computedStyle.height > computedStyle.maxHeight) computedStyle.height = computedStyle.maxHeight;
			}
			if(computedStyle.height < computedStyle.minHeight) computedStyle.height = computedStyle.minHeight;
		}
	}
	,setComputedHeight: function(style,computedHeight) {
		style.getComputedStyle().height = computedHeight;
		this.constrainHeight(style);
	}
	,setComputedWidth: function(style,computedWidth) {
		style.getComputedStyle().width = computedWidth;
		this.constrainWidth(style);
	}
	,getComputedWidth: function(style,containingDOMElementData) {
		return this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedAutoWidth: function(style,containingDOMElementData) {
		return containingDOMElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
	}
	,getComputedHeight: function(style,containingDOMElementData) {
		return this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedAutoHeight: function(style,containingDOMElementData) {
		return 0;
	}
	,getComputedMarginLeft: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginRight: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	}
	,getComputedMarginTop: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMarginBottom: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,false);
	}
	,getComputedMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
		return computedMargin;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
		return computedMargin;
	}
	,getComputedConstrainedDimension: function(constrainedDimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
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
		return computedConstraintDimension;
	}
	,getComputedPositionOffset: function(positionOffsetStyleValue,containingDOMElementDimension,fontSize,xHeight) {
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
		return computedPositionOffset;
	}
	,getComputedDimension: function(dimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
		return computedDimensions;
	}
	,getComputedPadding: function(paddingStyleValue,containingDOMElementDimension,fontSize,xHeight) {
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
		return computedPaddingValue;
	}
	,__class__: cocktailCore.style.computer.BoxStylesComputer
}
if(!cocktailCore.style.computer.boxComputers) cocktailCore.style.computer.boxComputers = {}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	measureAutoWidth: function(style,containingDOMElementData) {
		this.setComputedWidth(style,this.getComputedAutoWidth(style,containingDOMElementData));
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	}
	,getComputedAutoWidth: function(style,containingDOMElementData) {
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
		return ret;
	}
	,getComputedAutoHeight: function(style,containingDOMElementData) {
		var embeddedDOMElement = style.getDOMElement();
		var ret = 0;
		if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) {
			if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
		} else {
			var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedWidth(style,computedWidth);
			if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(style.getComputedStyle().width / embeddedDOMElement.getIntrinsicRatio()); else ret = 150;
		}
		return ret;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		var computedMargin;
		if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
		return computedMargin;
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer
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
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < containingDOMElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingDOMElementData.width;
		return shrinkedWidth;
	}
	,__class__: cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype,{
	getComputedAutoWidth: function(style,containingDOMElementData) {
		return 0;
	}
	,__class__: cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer
});
var Utils = $hxClasses["Utils"] = function() { }
Utils.__name__ = ["Utils"];
Utils.getContainer = function() {
	var ret = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	ret.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	return ret;
}
Utils.prototype = {
	__class__: Utils
}
if(!components.lists) components.lists = {}
components.lists.ListBaseUtils = $hxClasses["components.lists.ListBaseUtils"] = function() { }
components.lists.ListBaseUtils.__name__ = ["components","lists","ListBaseUtils"];
components.lists.ListBaseUtils.createListModel = function() {
	var richListModel = { content : new Array()};
	return richListModel;
}
components.lists.ListBaseUtils.__super__ = Utils;
components.lists.ListBaseUtils.prototype = $extend(Utils.prototype,{
	__class__: components.lists.ListBaseUtils
});
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer
});
cocktailCore.resource.abstract.AbstractImageLoader = $hxClasses["cocktailCore.resource.abstract.AbstractImageLoader"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.abstract.AbstractImageLoader.__name__ = ["cocktailCore","resource","abstract","AbstractImageLoader"];
cocktailCore.resource.abstract.AbstractImageLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractImageLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	__class__: cocktailCore.resource.abstract.AbstractImageLoader
});
var Navigation = $hxClasses["Navigation"] = function(container,startPage) {
	this.pagesContainer = container;
	this.currentPage = startPage;
	this._previousPages = new Array();
	this._previousPages.push(startPage);
	this.pagesContainer.addChild(startPage);
}
Navigation.__name__ = ["Navigation"];
Navigation.prototype = {
	pagesContainer: null
	,currentPage: null
	,_previousPages: null
	,goToPreviousPage: function() {
		this.showPage(this.getPreviousPage());
	}
	,getPreviousPage: function() {
		this._previousPages.pop();
		var previousPage = this._previousPages[this._previousPages.length - 1];
		if(previousPage == null) return this._previousPages[0];
		return previousPage;
	}
	,addToHistory: function(page) {
		if(page == this._previousPages[0]) this._previousPages = [page]; else this._previousPages.push(page);
	}
	,showPage: function(page) {
		this.pagesContainer.removeChild(this.currentPage);
		this.pagesContainer.addChild(page);
		this.currentPage = page;
	}
	,onChangeListCallback: function(cell) {
		if(cell.action == "goToPage") {
			var page = cell.actionTarget;
			this.addToHistory(page);
			this.showPage(page);
		} else if(cell.action == "goToUrl") this.goToUrl(cell.actionTarget); else if(cell.action == "openUrl") this.openUrl(cell.actionTarget);
	}
	,goToUrl: function(url) {
		js.Lib.window.open(url);
	}
	,openUrl: function(url) {
		js.Lib.window.open(url,"_self");
	}
	,__class__: Navigation
}
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = $hxClasses["cocktailCore.style.positioner.BoxPositioner"] = function() {
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype = {
	position: function(domElement,containingDOMElementData,staticPosition) {
		var childrenTemporaryPositionData = { domElement : domElement, x : 0, y : 0, lineIndex : 0};
		if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue) childrenTemporaryPositionData.x = this.getLeftOffset(domElement,Math.round(staticPosition.x)); else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) childrenTemporaryPositionData.x = this.getRightOffset(domElement,containingDOMElementData.width,Math.round(staticPosition.x)); else childrenTemporaryPositionData.x = Math.round(staticPosition.x);
		if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.autoValue) childrenTemporaryPositionData.y = this.getTopOffset(domElement,Math.round(staticPosition.y)); else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) childrenTemporaryPositionData.y = this.getBottomOffset(domElement,containingDOMElementData.height,Math.round(staticPosition.y)); else childrenTemporaryPositionData.y = Math.round(staticPosition.y);
		return childrenTemporaryPositionData;
	}
	,getLeftOffset: function(domElement,staticPosition) {
		return domElement.getStyle().getComputedStyle().left;
	}
	,getRightOffset: function(domElement,containingDOMElementWidth,staticPosition) {
		return containingDOMElementWidth - domElement.getOffsetWidth() - domElement.getStyle().getComputedStyle().right;
	}
	,getTopOffset: function(domElement,staticPosition) {
		return domElement.getStyle().getComputedStyle().top;
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight,staticPosition) {
		return containingDOMElementHeight - domElement.getOffsetHeight() - domElement.getStyle().getComputedStyle().bottom;
	}
	,__class__: cocktailCore.style.positioner.BoxPositioner
}
cocktailCore.style.js.ContainerStyle = $hxClasses["cocktailCore.style.js.ContainerStyle"] = function(domElement) {
	cocktailCore.style.abstract.AbstractContainerStyle.call(this,domElement);
}
cocktailCore.style.js.ContainerStyle.__name__ = ["cocktailCore","style","js","ContainerStyle"];
cocktailCore.style.js.ContainerStyle.__super__ = cocktailCore.style.abstract.AbstractContainerStyle;
cocktailCore.style.js.ContainerStyle.prototype = $extend(cocktailCore.style.abstract.AbstractContainerStyle.prototype,{
	flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		var containerDOMElement = this._domElement;
		var _g1 = 0, _g = containerDOMElement.getChildren().length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
				var childrenDOMElement = containerDOMElement.getChildren()[i].child;
				childrenDOMElement.getStyle().flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
			}
		}
		return new Array();
	}
	,__class__: cocktailCore.style.js.ContainerStyle
});
cocktailCore.domElement.abstract.AbstractContainerDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractContainerDOMElement"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral);
	this._children = new Array();
	this._textFragmentDOMElements = new Array();
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
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
		this._style = new cocktailCore.style.js.ContainerStyle(this);
	}
	,addChild: function(domElement) {
		if(domElement.getParent() != null) {
			var parent = domElement.getParent();
			parent.removeChild(domElement);
		}
		domElement.setParent(this);
		this._children.push({ child : domElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.domElement});
		this._style.invalidate();
	}
	,removeChild: function(domElement) {
		domElement.setParent(null);
		var newChildrenArray = new Array();
		var _g1 = 0, _g = this._children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._children[i].child != domElement) newChildrenArray.push(this._children[i]);
		}
		this._children = newChildrenArray;
		this._style.invalidate();
	}
	,addText: function(textElement) {
		this._children.push({ child : textElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.textElement});
	}
	,removeText: function(textElement) {
		var newChildrenArray = new Array();
		var _g1 = 0, _g = this._children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._children[i].child != textElement) newChildrenArray.push(this._children[i]);
		}
		this._children = newChildrenArray;
	}
	,getChildren: function() {
		return this._children;
	}
	,resetTextFragments: function() {
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
	}
	,addTextFragment: function(textFragmentDOMElement) {
		this._textFragmentDOMElements.push(textFragmentDOMElement);
	}
	,removeTextFragment: function(textFragmentDOMElement) {
	}
	,setSemantic: function(semantic) {
		this._semantic = semantic;
		return this._semantic;
	}
	,getSemantic: function() {
		return this._semantic;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractContainerDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.DOMElement.prototype.__properties__,{get_children:"getChildren",set_semantic:"setSemantic",get_semantic:"getSemantic"})
});
components.lists.ThumbTextList1Style = $hxClasses["components.lists.ThumbTextList1Style"] = function() { }
components.lists.ThumbTextList1Style.__name__ = ["components","lists","ThumbTextList1Style"];
components.lists.ThumbTextList1Style.getListStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(48)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(43)));
}
components.lists.ThumbTextList1Style.getCellStyle = function(domElement) {
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.percent(1));
}
components.lists.ThumbTextList1Style.getCellInfoBlockStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(10));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
}
components.lists.ThumbTextList1Style.getCellNumberStyle = function(domElement,screenResolutionSize) {
	components.lists.ThumbTextList1Style.getCellTextStyle(domElement);
	var fontSize = 12;
	if(screenResolutionSize == ScreenResolutionSize.small) fontSize = 12; else if(screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16; else fontSize = 20;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#989898"));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.percent(2));
}
components.lists.ThumbTextList1Style.getCellCommentCountStyle = function(domElement,screenResolutionSize) {
	components.lists.ThumbTextList1Style.getCellTextStyle(domElement);
	var fontSize = 11;
	if(screenResolutionSize == ScreenResolutionSize.small) fontSize = 11; else if(screenResolutionSize == ScreenResolutionSize.normal) fontSize = 14; else fontSize = 17;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#CC3517"));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
}
components.lists.ThumbTextList1Style.getCellInfoBlockLineStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.percent(5));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(50)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(90));
}
components.lists.ThumbTextList1Style.getCellInfoBlockImageStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.percent(2));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(50));
}
components.lists.ThumbTextList1Style.getCellThumbnailStyle = function(domElement) {
	components.lists.ThumbTextList1Style.getCellStyle(domElement);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.percent(1));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(200)));
	domElement.getStyle().setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(50));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(30));
}
components.lists.ThumbTextList1Style.getCellLineStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(1)));
}
components.lists.ThumbTextList1Style.getCellTextBlockStyle = function(domElement) {
	components.lists.ThumbTextList1Style.getCellStyle(domElement);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.percent(2));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(55));
}
components.lists.ThumbTextList1Style.getCellTextStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#202020"));
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("HelveticaNeue"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
}
components.lists.ThumbTextList1Style.getCellTitleStyle = function(domElement,screenResolutionSize) {
	components.lists.ThumbTextList1Style.getCellTextStyle(domElement);
	var fontSize = 14;
	if(screenResolutionSize == ScreenResolutionSize.small) fontSize = 14; else if(screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16; else fontSize = 18;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
}
components.lists.ThumbTextList1Style.getCellCommentStyle = function(domElement,screenResolutionSize) {
	components.lists.ThumbTextList1Style.getCellTextStyle(domElement);
	var fontSize = 10;
	if(screenResolutionSize == ScreenResolutionSize.small) fontSize = 10; else if(screenResolutionSize == ScreenResolutionSize.normal) fontSize = 11; else fontSize = 12;
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(fontSize)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.normal);
}
components.lists.ThumbTextList1Style.getCellDescriptionStyle = function(domElement) {
	components.lists.ThumbTextList1Style.getCellTextStyle(domElement);
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
}
components.lists.ThumbTextList1Style.getCellMouseOverStyle = function(domElement) {
}
components.lists.ThumbTextList1Style.getCellMouseOutStyle = function(domElement) {
}
components.lists.ThumbTextList1Style.getCellMouseDownStyle = function(domElement) {
}
components.lists.ThumbTextList1Style.getCellMouseUpStyle = function(domElement) {
}
components.lists.ThumbTextList1Style.prototype = {
	__class__: components.lists.ThumbTextList1Style
}
cocktailCore.resource.abstract.AbstractSkinLoader = $hxClasses["cocktailCore.resource.abstract.AbstractSkinLoader"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.skin);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.abstract.AbstractSkinLoader.__name__ = ["cocktailCore","resource","abstract","AbstractSkinLoader"];
cocktailCore.resource.abstract.AbstractSkinLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractSkinLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	__class__: cocktailCore.resource.abstract.AbstractSkinLoader
});
if(!cocktailCore.unit) cocktailCore.unit = {}
cocktailCore.unit.UnitManager = $hxClasses["cocktailCore.unit.UnitManager"] = function() {
}
cocktailCore.unit.UnitManager.__name__ = ["cocktailCore","unit","UnitManager"];
cocktailCore.unit.UnitManager.getPixelFromLengthValue = function(length,emReference,exReference) {
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
cocktailCore.unit.UnitManager.getFontSizeFromAbsoluteSizeValue = function(absoluteSize) {
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
cocktailCore.unit.UnitManager.getFontSizeFromRelativeSizeValue = function(relativeSize,parentFontSize) {
	var fontSize;
	switch( (relativeSize)[1] ) {
	case 0:
		fontSize = cocktailCore.unit.UnitManager.getLargerFontSize(parentFontSize);
		break;
	case 1:
		fontSize = cocktailCore.unit.UnitManager.getSmallerFontSize(parentFontSize);
		break;
	}
	return fontSize;
}
cocktailCore.unit.UnitManager.getPixelFromPercent = function(percent,reference) {
	return reference * (percent * 0.01);
}
cocktailCore.unit.UnitManager.getColorFromColorValue = function(value) {
	var color;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var blue = $e[4], green = $e[3], red = $e[2];
		color = red;
		color = (color << 8) + green;
		color = (color << 8) + blue;
		break;
	case 1:
		var value1 = $e[2];
		color = Std.parseInt(StringTools.replace(value1,"#","0x"));
		break;
	case 2:
		var value1 = $e[2];
		color = cocktailCore.unit.UnitManager.getColorFromColorValueKeyword(value1);
		break;
	}
	return color;
}
cocktailCore.unit.UnitManager.getRadFromAngleValue = function(value) {
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
cocktailCore.unit.UnitManager.getDegreeFromAngleValue = function(value) {
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
cocktailCore.unit.UnitManager.getColorFromColorValueKeyword = function(value) {
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
	return cocktailCore.unit.UnitManager.getColorFromColorValue(cocktail.unit.ColorValue.hex(hexColor));
}
cocktailCore.unit.UnitManager.getLargerFontSize = function(parentFontSize) {
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
cocktailCore.unit.UnitManager.getSmallerFontSize = function(parentFontSize) {
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
cocktailCore.unit.UnitManager.prototype = {
	__class__: cocktailCore.unit.UnitManager
}
cocktailCore.resource.abstract.AbstractStringLoader = $hxClasses["cocktailCore.resource.abstract.AbstractStringLoader"] = function(nativeElement) {
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.abstract.AbstractStringLoader.__name__ = ["cocktailCore","resource","abstract","AbstractStringLoader"];
cocktailCore.resource.abstract.AbstractStringLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractStringLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	doLoad: function(url) {
		var fileRequest = new haxe.Http(url);
		fileRequest.onData = this.onLoadComplete.$bind(this);
		fileRequest.onError = this.onLoadError.$bind(this);
		fileRequest.request(false);
	}
	,__class__: cocktailCore.resource.abstract.AbstractStringLoader
});
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
}
cocktailCore.style.computer.DisplayStylesComputer.__name__ = ["cocktailCore","style","computer","DisplayStylesComputer"];
cocktailCore.style.computer.DisplayStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.position = cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition(style);
	computedStyle.floatValue = cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle.floatValue);
	computedStyle.clear = cocktailCore.style.computer.DisplayStylesComputer.getComputedClear(style,computedStyle.position,computedStyle.display);
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition = function(style) {
	return style.getPosition();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat = function(style,computedPosition) {
	var ret;
	if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.FloatStyleValue.none; else ret = style.getFloatValue();
	return ret;
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay = function(style,computedFloat) {
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
	return ret;
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedClear = function(style,computedPosition,computedDisplay) {
	var ret;
	if(computedDisplay == cocktail.style.DisplayStyleValue.inlineStyle || computedDisplay == cocktail.style.DisplayStyleValue.inlineBlock) ret = cocktail.style.ClearStyleValue.none; else if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.ClearStyleValue.none; else ret = style.getClear();
	return ret;
}
cocktailCore.style.computer.DisplayStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.DisplayStylesComputer
}
cocktailCore.resource.js.SkinLoader = $hxClasses["cocktailCore.resource.js.SkinLoader"] = function() {
	cocktailCore.resource.abstract.AbstractSkinLoader.call(this);
}
cocktailCore.resource.js.SkinLoader.__name__ = ["cocktailCore","resource","js","SkinLoader"];
cocktailCore.resource.js.SkinLoader.__super__ = cocktailCore.resource.abstract.AbstractSkinLoader;
cocktailCore.resource.js.SkinLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractSkinLoader.prototype,{
	doLoad: function(url) {
		var fileRequest = new haxe.Http(url);
		fileRequest.onData = this.onLoadComplete.$bind(this);
		fileRequest.onError = this.onLoadError.$bind(this);
		fileRequest.request(false);
	}
	,onLoadComplete: function(data) {
		var domElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
		domElement.getNativeElement().innerHTML = data;
		this._onLoadCompleteCallback(domElement);
	}
	,__class__: cocktailCore.resource.js.SkinLoader
});
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
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement"] = function(nativeElement,style) {
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	this._style = style;
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractTextFragmentDOMElement"];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype = $extend(cocktailCore.domElement.js.DOMElement.prototype,{
	initStyle: function() {
	}
	,__class__: cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement
});
cocktailCore.style.computer.FontAndTextStylesComputer = $hxClasses["cocktailCore.style.computer.FontAndTextStylesComputer"] = function() {
}
cocktailCore.style.computer.FontAndTextStylesComputer.__name__ = ["cocktailCore","style","computer","FontAndTextStylesComputer"];
cocktailCore.style.computer.FontAndTextStylesComputer.compute = function(style,containingDOMElementData,containingDOMElementFontMetricsData) {
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
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextIndent = function(style,containingDOMElementData) {
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
	return Math.round(textIndent);
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingDOMElementData,containingDOMElementFontMetricsData) {
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
	return verticalAlign;
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedTextAlign = function(style,computedWhiteSpace) {
	var textAlign = style.getTextAlign();
	switch( (computedWhiteSpace)[1] ) {
	case 1:
		if(style.getTextAlign() == cocktail.style.TextAlignStyleValue.justify) textAlign = cocktail.style.TextAlignStyleValue.left;
		break;
	default:
	}
	return textAlign;
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedColor = function(style) {
	return cocktailCore.unit.UnitManager.getColorFromColorValue(style.getColor());
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedWordSpacing = function(style) {
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
	return wordSpacing;
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLineHeight = function(style) {
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
	return lineHeight;
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLetterSpacing = function(style) {
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
	return letterSpacing;
}
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize = function(style,parentFontSize,parentXHeight) {
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
	return fontSize;
}
cocktailCore.style.computer.FontAndTextStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.FontAndTextStylesComputer
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
	if(args.length <= 3) return new cl(args[0],args[1],args[2]);
	if(args.length > 8) throw "Too many arguments";
	return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
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
cocktailCore.domElement.js.ImageDOMElement = $hxClasses["cocktailCore.domElement.js.ImageDOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractImageDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.ImageDOMElement.__name__ = ["cocktailCore","domElement","js","ImageDOMElement"];
cocktailCore.domElement.js.ImageDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
cocktailCore.domElement.js.ImageDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype,{
	onLoadComplete: function(image) {
		this._src = image.src;
		this._intrinsicHeight = image.naturalHeight;
		this._intrinsicWidth = image.naturalWidth;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
		cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoadComplete.call(this,image);
	}
	,__class__: cocktailCore.domElement.js.ImageDOMElement
});
cocktailCore.domElement.js.ContainerDOMElement = $hxClasses["cocktailCore.domElement.js.ContainerDOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.ContainerDOMElement.__name__ = ["cocktailCore","domElement","js","ContainerDOMElement"];
cocktailCore.domElement.js.ContainerDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
cocktailCore.domElement.js.ContainerDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype,{
	addChild: function(domElement) {
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild.call(this,domElement);
		this._nativeElement.appendChild(domElement.getNativeElement());
		domElement.getNativeElement().style.zIndex = this._children.length - 1;
	}
	,removeChild: function(domElement) {
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild.call(this,domElement);
		this._nativeElement.removeChild(domElement.getNativeElement());
	}
	,addText: function(textElement) {
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText.call(this,textElement);
		this.getNativeElement().appendChild(textElement.getText());
	}
	,removeText: function(textElement) {
		cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText.call(this,textElement);
		this._nativeElement.removeChild(textElement.getText());
	}
	,setSemantic: function(semantic) {
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
		return semantic;
	}
	,__class__: cocktailCore.domElement.js.ContainerDOMElement
});
components.lists.ListBase = $hxClasses["components.lists.ListBase"] = function(list,listStyle) {
	this._listData = list.content;
	this._currentCellIndex = 0;
	this._selectedCellData = this._listData[this._currentCellIndex];
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom("ul")));
	this.createListDOM(list,listStyle);
	listStyle.list(this);
	this.selectCell(this._selectedCellDOM);
}
components.lists.ListBase.__name__ = ["components","lists","ListBase"];
components.lists.ListBase.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
components.lists.ListBase.prototype = $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype,{
	onChange: null
	,_listData: null
	,_currentCellIndex: null
	,_selectedCellData: null
	,_selectedCellDOM: null
	,createListDOM: function(list,listStyle) {
		var content = Utils.getContainer();
		var cellData;
		var _g = 0, _g1 = list.content;
		while(_g < _g1.length) {
			var cellData1 = _g1[_g];
			++_g;
			var cell = this.createCellDOM(cellData1,listStyle);
			this.addChild(cell);
			if(this._currentCellIndex == 0) this._selectedCellDOM = cell;
			this._currentCellIndex++;
		}
		this._currentCellIndex = 0;
	}
	,createCellDOM: function(cellData,listStyle) {
		var cell = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom("li")));
		var cellLink = new cocktailCore.domElement.js.LinkDOMElement();
		if(cellData.action == "openUrl" || cellData.action == "goToUrl") {
			cellLink.setHref(cellData.actionTarget);
			cellLink.setTarget(cocktail.domElement.LinkTargetValue.blank);
		} else {
			var onCellMouseUpDelegate = this.onCellSelected.$bind(this);
			cell.setOnMouseUp(function(mouseEventData) {
				onCellMouseUpDelegate(cell,cellData);
			});
		}
		listStyle.cell(cell);
		var cellContent = this.getCellData(cellData.content,listStyle);
		var _g = 0;
		while(_g < cellContent.length) {
			var container = cellContent[_g];
			++_g;
			cellLink.addChild(container);
		}
		cell.addChild(cellLink);
		return cell;
	}
	,getCellData: function(cellData,listStyle) {
		var cellContent = new Array();
		return cellContent;
	}
	,onCellSelected: function(cell,cellData) {
		if(this.onChange != null) this.onChange(cellData);
		this.selectCell(cell);
	}
	,selectCell: function(cell) {
		this._selectedCellDOM = cell;
	}
	,onListKeyDown: function(key) {
	}
	,selectNextCell: function() {
		if(this._currentCellIndex < this._children.length - 1) {
			this._currentCellIndex++;
			this.selectCell(this._children[this._currentCellIndex].child);
			this.onCellSelected(this._selectedCellDOM,this._listData[this._currentCellIndex]);
		}
	}
	,selectPreviousCell: function() {
		if(this._currentCellIndex > 0) {
			this._currentCellIndex--;
			this.selectCell(this._children[this._currentCellIndex].child);
			this.onCellSelected(this._selectedCellDOM,this._listData[this._currentCellIndex]);
		}
	}
	,__class__: components.lists.ListBase
});
components.lists.AppList = $hxClasses["components.lists.AppList"] = function(list,listStyle) {
	this._selectedMenuItemImage = new cocktailCore.domElement.js.ImageDOMElement();
	listStyle.cellSelected(this._selectedMenuItemImage);
	this._selectedMenuItemImage.load("images/selectedMenuItem.png");
	components.lists.ListBase.call(this,list,listStyle);
}
components.lists.AppList.__name__ = ["components","lists","AppList"];
components.lists.AppList.__super__ = components.lists.ListBase;
components.lists.AppList.prototype = $extend(components.lists.ListBase.prototype,{
	_selectedMenuItemImage: null
	,createListDOM: function(list,listStyle) {
		components.lists.ListBase.prototype.createListDOM.call(this,list,listStyle);
		this.setOnKeyDown(this.onListKeyDown.$bind(this));
	}
	,getCellData: function(cellData,listStyle) {
		var cellContent = new Array();
		if(cellData.icon != "" && cellData.icon != null) {
			var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
			listStyle.cellIcon(cellImage);
			cellContent.push(cellImage);
			cellImage.load(cellData.icon);
		}
		if(cellData.title != "" && cellData.title != null) {
			var cellTitleContainer = Utils.getContainer();
			var textElement = new cocktailCore.textElement.js.TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			listStyle.cellTitle(cellTitleContainer);
			cellContent.push(cellTitleContainer);
		}
		return cellContent;
	}
	,selectCell: function(cell) {
		components.lists.ListBase.prototype.selectCell.call(this,cell);
		cell.addChild(this._selectedMenuItemImage);
	}
	,onListKeyDown: function(key) {
		if(key.value == cocktail.keyboard.KeyboardKeyValue.right) components.lists.ListBase.prototype.selectNextCell.call(this); else if(key.value == cocktail.keyboard.KeyboardKeyValue.left) components.lists.ListBase.prototype.selectPreviousCell.call(this);
	}
	,__class__: components.lists.AppList
});
cocktailCore.style.positioner.RelativePositioner = $hxClasses["cocktailCore.style.positioner.RelativePositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.RelativePositioner.__name__ = ["cocktailCore","style","positioner","RelativePositioner"];
cocktailCore.style.positioner.RelativePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.RelativePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	getLeftOffset: function(domElement,staticPosition) {
		return staticPosition + domElement.getStyle().getComputedStyle().left;
	}
	,getRightOffset: function(domElement,containingDOMElementWidth,staticPosition) {
		return staticPosition + containingDOMElementWidth - domElement.getOffsetWidth() - domElement.getStyle().getComputedStyle().right;
	}
	,getTopOffset: function(domElement,staticPosition) {
		return staticPosition + domElement.getStyle().getComputedStyle().top;
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight,staticPosition) {
		return staticPosition + containingDOMElementHeight - domElement.getOffsetHeight() - domElement.getStyle().getComputedStyle().bottom;
	}
	,__class__: cocktailCore.style.positioner.RelativePositioner
});
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = $hxClasses["cocktailCore.textElement.abstract.AbstractTextElement"] = function(text) {
	this._textFragments = new Array();
}
cocktailCore.textElement.abstract.AbstractTextElement.__name__ = ["cocktailCore","textElement","abstract","AbstractTextElement"];
cocktailCore.textElement.abstract.AbstractTextElement.applyWhiteSpace = function(text,whiteSpace) {
	var ret = text;
	switch( (whiteSpace)[1] ) {
	case 0:
		ret = cocktailCore.textElement.abstract.AbstractTextElement.collapseSpaceSequences(text);
		break;
	case 1:
		ret = cocktailCore.textElement.abstract.AbstractTextElement.removeLineFeeds(text);
		break;
	case 2:
		ret = cocktailCore.textElement.abstract.AbstractTextElement.collapseSpaceSequences(text);
		ret = cocktailCore.textElement.abstract.AbstractTextElement.removeLineFeeds(text);
		ret = cocktailCore.textElement.abstract.AbstractTextElement.convertTabToSpace(text);
		break;
	case 3:
		break;
	case 4:
		ret = cocktailCore.textElement.abstract.AbstractTextElement.collapseSpaceSequences(text);
		break;
	}
	return ret;
}
cocktailCore.textElement.abstract.AbstractTextElement.applyTextTransform = function(text,textTransform) {
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
	return text;
}
cocktailCore.textElement.abstract.AbstractTextElement.capitalizeText = function(text) {
	var capitalizedText = text.charAt(0);
	var _g1 = 1, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
	}
	return capitalizedText;
}
cocktailCore.textElement.abstract.AbstractTextElement.collapseSpaceSequences = function(text) {
	var collapsedText = "";
	var isSpaceSequence = false;
	var _g1 = 0, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(StringTools.isSpace(text,i)) {
			if(isSpaceSequence == false) {
				collapsedText += text.charAt(i);
				isSpaceSequence = true;
			}
		} else {
			isSpaceSequence = false;
			collapsedText += text.charAt(i);
		}
	}
	return collapsedText;
}
cocktailCore.textElement.abstract.AbstractTextElement.removeLineFeeds = function(text) {
	return StringTools.replace(text,"\n","");
}
cocktailCore.textElement.abstract.AbstractTextElement.convertTabToSpace = function(text) {
	return StringTools.replace(text,"\t"," ");
}
cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments = function(text) {
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
	return textFragments;
}
cocktailCore.textElement.abstract.AbstractTextElement.insertTextToken = function(textToken) {
	return { textToken : textToken, textFragmentDOMElement : null};
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype = {
	_text: null
	,text: null
	,_textFragments: null
	,reset: function() {
		var _g1 = 0, _g = this._textFragments.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._textFragments[i].textFragmentDOMElement = null;
		}
	}
	,getTextFragments: function(text) {
		if(this._textFragments.length == 0) this._textFragments = cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments(text);
		return this._textFragments;
	}
	,getNativeText: function() {
		return null;
	}
	,getText: function() {
		return this._text;
	}
	,__class__: cocktailCore.textElement.abstract.AbstractTextElement
	,__properties__: {get_text:"getText"}
}
if(!cocktailCore.textElement.js) cocktailCore.textElement.js = {}
cocktailCore.textElement.js.TextElement = $hxClasses["cocktailCore.textElement.js.TextElement"] = function(text) {
	cocktailCore.textElement.abstract.AbstractTextElement.call(this,text);
	this._text = js.Lib.document.createTextNode(text);
}
cocktailCore.textElement.js.TextElement.__name__ = ["cocktailCore","textElement","js","TextElement"];
cocktailCore.textElement.js.TextElement.__super__ = cocktailCore.textElement.abstract.AbstractTextElement;
cocktailCore.textElement.js.TextElement.prototype = $extend(cocktailCore.textElement.abstract.AbstractTextElement.prototype,{
	__class__: cocktailCore.textElement.js.TextElement
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
components.dataProvider.XmlLoader = $hxClasses["components.dataProvider.XmlLoader"] = function(xmlUrl) {
	this.loadXmlFeed(xmlUrl);
}
components.dataProvider.XmlLoader.__name__ = ["components","dataProvider","XmlLoader"];
components.dataProvider.XmlLoader.prototype = {
	onLoad: null
	,loadXmlFeed: function(xmlUrl) {
		cocktail.resource.ResourceLoaderManager.loadString("http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl),this.onXmlLoaded.$bind(this),this.onXmlError.$bind(this));
	}
	,onXmlError: function(msg) {
		haxe.Log.trace("Error while loading XML feed : " + msg,{ fileName : "XmlLoader.hx", lineNumber : 51, className : "components.dataProvider.XmlLoader", methodName : "onXmlError"});
	}
	,onXmlLoaded: function(xmlString) {
		var xml = Xml.parse(xmlString);
		if(this.onLoad != null) this.onLoad(xml);
	}
	,__class__: components.dataProvider.XmlLoader
}
components.lists.AppListStyle = $hxClasses["components.lists.AppListStyle"] = function() { }
components.lists.AppListStyle.__name__ = ["components","lists","AppListStyle"];
components.lists.AppListStyle.getListStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setRight(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(48)));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
}
components.lists.AppListStyle.getCellStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(2)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(62)));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#BDBDCE"));
}
components.lists.AppListStyle.getCellSelectedStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(62)));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(2)));
}
components.lists.AppListStyle.getCellImageStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.autoValue);
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(31)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
components.lists.AppListStyle.getCellTextStyle = function(domElement) {
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#999999"));
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("HelveticaNeue"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
}
components.lists.AppListStyle.getCellMouseOverStyle = function(domElement) {
}
components.lists.AppListStyle.getCellMouseOutStyle = function(domElement) {
}
components.lists.AppListStyle.getCellMouseDownStyle = function(domElement) {
}
components.lists.AppListStyle.getCellMouseUpStyle = function(domElement) {
}
components.lists.AppListStyle.prototype = {
	__class__: components.lists.AppListStyle
}
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
	this.setData(data);
}
cocktail.geom.Matrix.__name__ = ["cocktail","geom","Matrix"];
cocktail.geom.Matrix.prototype = {
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
		var translationMatrix = new cocktail.geom.Matrix(translationMatrixData);
		this.concatenate(translationMatrix);
	}
	,rotate: function(angle,registrationPoint) {
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
	}
	,scale: function(scaleX,scaleY,registrationPoint) {
		var scaledMatrix = new cocktail.geom.Matrix();
		scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
		var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
		var scalingMatrix = new cocktail.geom.Matrix(scalingMatrixData);
		scaledMatrix.concatenate(scalingMatrix);
		scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
		this.concatenate(scaledMatrix);
	}
	,skew: function(skewX,skewY,registrationPoint) {
		var skewedMatrix = new cocktail.geom.Matrix();
		skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
		var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
		var skewingMatrix = new cocktail.geom.Matrix(skewingMatrixData);
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
	,__class__: cocktail.geom.Matrix
	,__properties__: {set_data:"setData",get_data:"getData"}
}
cocktailCore.style.positioner.AbsolutePositioner = $hxClasses["cocktailCore.style.positioner.AbsolutePositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.AbsolutePositioner.__name__ = ["cocktailCore","style","positioner","AbsolutePositioner"];
cocktailCore.style.positioner.AbsolutePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.AbsolutePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	__class__: cocktailCore.style.positioner.AbsolutePositioner
});
if(!cocktailCore.nativeElement) cocktailCore.nativeElement = {}
if(!cocktailCore.nativeElement["abstract"]) cocktailCore.nativeElement["abstract"] = {}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager"] = function() {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementPathManager"];
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype = {
	getRoot: function() {
		return null;
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager
}
if(!cocktailCore.nativeElement.js) cocktailCore.nativeElement.js = {}
cocktailCore.nativeElement.js.NativeElementPathManager = $hxClasses["cocktailCore.nativeElement.js.NativeElementPathManager"] = function() {
	cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.call(this);
}
cocktailCore.nativeElement.js.NativeElementPathManager.__name__ = ["cocktailCore","nativeElement","js","NativeElementPathManager"];
cocktailCore.nativeElement.js.NativeElementPathManager.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
cocktailCore.nativeElement.js.NativeElementPathManager.prototype = $extend(cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype,{
	getRoot: function() {
		return js.Lib.document.body;
	}
	,__class__: cocktailCore.nativeElement.js.NativeElementPathManager
});
cocktailCore.style.abstract.AbstractEmbeddedStyle = $hxClasses["cocktailCore.style.abstract.AbstractEmbeddedStyle"] = function(domElement) {
	cocktailCore.style.js.Style.call(this,domElement);
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.__name__ = ["cocktailCore","style","abstract","AbstractEmbeddedStyle"];
cocktailCore.style.abstract.AbstractEmbeddedStyle.__super__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype = $extend(cocktailCore.style.js.Style.prototype,{
	getBoxStylesComputer: function() {
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
		return boxComputer;
	}
	,isEmbedded: function() {
		return true;
	}
	,__class__: cocktailCore.style.abstract.AbstractEmbeddedStyle
});
cocktailCore.style.js.EmbeddedStyle = $hxClasses["cocktailCore.style.js.EmbeddedStyle"] = function(domElement) {
	cocktailCore.style.abstract.AbstractEmbeddedStyle.call(this,domElement);
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
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.getRoot());
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractBodyDOMElement"];
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype = $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype,{
	_viewPort: null
	,initStyle: function() {
		this._style = new cocktailCore.style.js.BodyStyle(this);
		this._viewPort = new cocktailCore.viewport.js.Viewport();
		this._viewPort._setOnResize(this.onViewPortResize.$bind(this));
	}
	,onViewPortResize: function() {
		this._style.invalidate();
	}
	,setX: function(value) {
		return value;
	}
	,setY: function(value) {
		return value;
	}
	,setWidth: function(value) {
		return value;
	}
	,setHeight: function(value) {
		return value;
	}
	,setIsVisible: function(value) {
		return value;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractBodyDOMElement
});
cocktailCore.domElement.js.TextFragmentDOMElement = $hxClasses["cocktailCore.domElement.js.TextFragmentDOMElement"] = function(nativeElement,style) {
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
cocktailCore.domElement.js.TextFragmentDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.TextFragmentDOMElement
});
cocktailCore.domElement.abstract.AbstractLinkDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractLinkDOMElement"] = function() {
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.link));
	this._target = cocktail.domElement.LinkTargetValue.self;
}
cocktailCore.domElement.abstract.AbstractLinkDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractLinkDOMElement"];
cocktailCore.domElement.abstract.AbstractLinkDOMElement.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
cocktailCore.domElement.abstract.AbstractLinkDOMElement.prototype = $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype,{
	_href: null
	,href: null
	,_target: null
	,target: null
	,_onMouseDown: null
	,setOnMouseDown: function(value) {
		this._onMouseDown = value;
		this._mouse.setOnMouseDown(this.onLinkMouseDown.$bind(this));
		return this._mouse.getOnMouseDown();
	}
	,onLinkMouseDown: function(mouseEventData) {
		if(this._onMouseDown != null) this._onMouseDown(mouseEventData);
		this.openLink();
	}
	,openLink: function() {
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
	,setHref: function(value) {
		this._href = value;
		this.setOnMouseDown(this._onMouseDown);
		return value;
	}
	,getHref: function() {
		return this._href;
	}
	,setTarget: function(value) {
		this._target = value;
		this.setOnMouseDown(this._onMouseDown);
		return value;
	}
	,getTarget: function() {
		return this._target;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractLinkDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.ContainerDOMElement.prototype.__properties__,{set_target:"setTarget",get_target:"getTarget",set_href:"setHref",get_href:"getHref"})
});
cocktailCore.resource.js.ImageLoader = $hxClasses["cocktailCore.resource.js.ImageLoader"] = function(nativeElement) {
	cocktailCore.resource.abstract.AbstractImageLoader.call(this,nativeElement);
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractImageLoader;
cocktailCore.resource.js.ImageLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractImageLoader.prototype,{
	__class__: cocktailCore.resource.js.ImageLoader
});
if(!cocktailCore.drawing) cocktailCore.drawing = {}
if(!cocktailCore.drawing["abstract"]) cocktailCore.drawing["abstract"] = {}
cocktailCore.drawing.abstract.AbstractDrawingManager = $hxClasses["cocktailCore.drawing.abstract.AbstractDrawingManager"] = function(nativeElement) {
	this._nativeElement = nativeElement;
}
cocktailCore.drawing.abstract.AbstractDrawingManager.__name__ = ["cocktailCore","drawing","abstract","AbstractDrawingManager"];
cocktailCore.drawing.abstract.AbstractDrawingManager.prototype = {
	_nativeElement: null
	,beginFill: function(fillStyle,lineStyle) {
		if(fillStyle == null) fillStyle = cocktail.domElement.FillStyleValue.none;
		if(lineStyle == null) lineStyle = cocktail.domElement.LineStyleValue.none;
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
	,drawImage: function(source,destinationPoint,sourceRect) {
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
	,__class__: cocktailCore.drawing.abstract.AbstractDrawingManager
}
if(!cocktailCore.classInstance) cocktailCore.classInstance = {}
if(!cocktailCore.classInstance["abstract"]) cocktailCore.classInstance["abstract"] = {}
cocktailCore.classInstance.abstract.AbstractClassInstance = $hxClasses["cocktailCore.classInstance.abstract.AbstractClassInstance"] = function(nativeInstanceClassName) {
}
cocktailCore.classInstance.abstract.AbstractClassInstance.__name__ = ["cocktailCore","classInstance","abstract","AbstractClassInstance"];
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype = {
	_nativeInstance: null
	,nativeInstance: null
	,callMethod: function(methodName,args) {
		if(this.isFunction(methodName)) {
			var method = Reflect.field(this._nativeInstance,methodName);
			return method.apply(this._nativeInstance,args);
		}
		return null;
	}
	,getField: function(fieldName) {
		var fieldGetterName = "get" + fieldName.substr(0,1).toUpperCase() + fieldName.substr(1);
		if(this.isFunction(fieldGetterName)) return Reflect.field(this._nativeInstance,fieldGetterName).apply(this._nativeInstance,[]); else return Reflect.field(this._nativeInstance,fieldName);
	}
	,setField: function(fieldName,fieldValue) {
		var fieldSetterName = "set" + fieldName.substr(0,1).toUpperCase() + fieldName.substr(1);
		if(this.isFunction(fieldSetterName)) Reflect.field(this._nativeInstance,fieldSetterName).apply(this._nativeInstance,[fieldValue]); else this._nativeInstance[fieldName] = fieldValue;
	}
	,isFunction: function(functionName) {
		return Reflect.isFunction(Reflect.field(this._nativeInstance,functionName));
	}
	,getNativeInstance: function() {
		return this._nativeInstance;
	}
	,__class__: cocktailCore.classInstance.abstract.AbstractClassInstance
	,__properties__: {get_nativeInstance:"getNativeInstance"}
}
if(!cocktail.nativeElement) cocktail.nativeElement = {}
cocktail.nativeElement.NativeElementTypeValue = $hxClasses["cocktail.nativeElement.NativeElementTypeValue"] = { __ename__ : ["cocktail","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","library","skin","link","custom"] }
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
cocktail.nativeElement.NativeElementTypeValue.custom = function(name) { var $x = ["custom",7,name]; $x.__enum__ = cocktail.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
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
cocktailCore.style.formatter.FormattingContext = $hxClasses["cocktailCore.style.formatter.FormattingContext"] = function(domElement,previousFormatingContext) {
	this._containingDOMElement = domElement;
	this._containingDOMElementWidth = this._containingDOMElement.getStyle().getComputedStyle().width;
	this._floatsManager = new cocktailCore.style.floats.FloatsManager();
	if(previousFormatingContext != null) this._floatsManager.addFloats(previousFormatingContext);
	this._formattingContextData = this.initFormattingContextData(this._containingDOMElement);
	this._childrenTemporaryPositionsData = new Array();
}
cocktailCore.style.formatter.FormattingContext.__name__ = ["cocktailCore","style","formatter","FormattingContext"];
cocktailCore.style.formatter.FormattingContext.prototype = {
	_containingDOMElement: null
	,containingDOMElement: null
	,_containingDOMElementWidth: null
	,_floatsManager: null
	,floatsManager: null
	,_formattingContextData: null
	,formattingContextData: null
	,_childrenTemporaryPositionsData: null
	,initFormattingContextData: function(domElement) {
		var flowY = 0;
		var flowX = this._floatsManager.getLeftFloatOffset(flowY);
		return { x : flowX, y : flowY, maxHeight : 0, maxWidth : 0};
	}
	,getChildrenTemporaryPositionData: function(parentDOMElement) {
		var childrenTemporaryPositionData = new Array();
		var foundFlag = false;
		var _g1 = 0, _g = this._childrenTemporaryPositionsData.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._childrenTemporaryPositionsData[i].parentDOMElement == parentDOMElement) {
				childrenTemporaryPositionData = this._childrenTemporaryPositionsData[i].children;
				foundFlag = true;
			}
		}
		if(foundFlag == false) {
			var childrenTemporaryPositionsData = { parentDOMElement : parentDOMElement, children : childrenTemporaryPositionData};
			this._childrenTemporaryPositionsData.push(childrenTemporaryPositionsData);
		}
		return childrenTemporaryPositionData;
	}
	,insert: function(domElement,parentDOMElement,position) {
		this.doInsert(domElement,parentDOMElement,position);
	}
	,insertSpace: function(domElement,parentDOMElement) {
		this.doInsert(domElement,parentDOMElement);
	}
	,insertTab: function(domElement,parentDOMElement) {
		this.doInsert(domElement,parentDOMElement);
	}
	,insertLineFeed: function() {
		this.startNewLine(0);
	}
	,insertFloat: function(domElement,parentDOMElement) {
		var floatData = this._floatsManager.computeFloatData(domElement,this._formattingContextData,parentDOMElement.getStyle().getComputedStyle().width);
		this.placeFloat(domElement,parentDOMElement,floatData);
	}
	,clearFloat: function(clear,isFloat) {
	}
	,retrieveFloats: function(formattingContext) {
		this._floatsManager.retrieveFloats(formattingContext);
	}
	,destroy: function() {
	}
	,startNewLine: function(domElementWidth,isLastLine) {
		if(isLastLine == null) isLastLine = false;
	}
	,doInsert: function(domElement,parentDOMElement,establishesNewFormattingContext) {
		if(establishesNewFormattingContext == null) establishesNewFormattingContext = false;
		this.place(domElement,parentDOMElement,establishesNewFormattingContext);
		this.removeFloats();
	}
	,getRemainingLineWidth: function() {
		return this._containingDOMElementWidth - this._formattingContextData.x - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._containingDOMElementWidth);
	}
	,place: function(domElement,parentDOMElement,establishesNewFormattingContext) {
	}
	,placeFloat: function(domElement,parentDOMElement,floatData) {
		this.getChildrenTemporaryPositionData(parentDOMElement).push(this.getChildTemporaryPositionData(domElement,floatData.x,floatData.y,0,true));
	}
	,removeFloats: function() {
		this._floatsManager.removeFloats(this._formattingContextData.y);
	}
	,getChildTemporaryPositionData: function(domElement,x,y,lineIndex,position) {
		var childTemporaryPositionData;
		if(position == true) childTemporaryPositionData = { domElement : domElement, x : x, y : y, lineIndex : lineIndex}; else childTemporaryPositionData = { domElement : domElement, x : 0, y : 0, lineIndex : lineIndex};
		return childTemporaryPositionData;
	}
	,getFloatsManager: function() {
		return this._floatsManager;
	}
	,getFormattingContextData: function() {
		return this._formattingContextData;
	}
	,getContainingDOMElement: function() {
		return this._containingDOMElement;
	}
	,__class__: cocktailCore.style.formatter.FormattingContext
	,__properties__: {get_formattingContextData:"getFormattingContextData",get_floatsManager:"getFloatsManager",get_containingDOMElement:"getContainingDOMElement"}
}
cocktailCore.style.formatter.BlockFormattingContext = $hxClasses["cocktailCore.style.formatter.BlockFormattingContext"] = function(domElement,previousFormattingContext) {
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
}
cocktailCore.style.formatter.BlockFormattingContext.__name__ = ["cocktailCore","style","formatter","BlockFormattingContext"];
cocktailCore.style.formatter.BlockFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.BlockFormattingContext.prototype = $extend(cocktailCore.style.formatter.FormattingContext.prototype,{
	place: function(domElement,parentDOMElement,position) {
		cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement,parentDOMElement,position);
		var leftFloatOffset = 0;
		if(domElement.getStyle().isEmbedded() == true) {
			this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this.getFormattingContextData(),domElement.getOffsetWidth(),this._containingDOMElementWidth);
			leftFloatOffset = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
		}
		this._formattingContextData.x = leftFloatOffset;
		var childTemporaryPositionData = this.getChildTemporaryPositionData(domElement,this._formattingContextData.x,this._formattingContextData.y,0,position);
		this.getChildrenTemporaryPositionData(parentDOMElement).push(childTemporaryPositionData);
		domElement.getStyle().setNativeX(domElement,childTemporaryPositionData.x);
		domElement.getStyle().setNativeY(domElement,childTemporaryPositionData.y);
		if(position == true) this._formattingContextData.y += domElement.getOffsetHeight(); else this._formattingContextData.y += domElement.getOffsetHeight() - domElement.getStyle().getComputedStyle().height;
		this._formattingContextData.maxHeight = this._formattingContextData.y;
		if(this._formattingContextData.x + domElement.getOffsetWidth() > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = this._formattingContextData.x + domElement.getOffsetWidth();
	}
	,clearFloat: function(clear,isFloat) {
		this._formattingContextData.y = this._floatsManager.clearFloat(clear,this._formattingContextData);
	}
	,__class__: cocktailCore.style.formatter.BlockFormattingContext
});
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	measureVerticalPaddings: function(style,containingDOMElementData) {
		style.getComputedStyle().paddingTop = 0;
		style.getComputedStyle().paddingBottom = 0;
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		this.setComputedHeight(style,this.getComputedAutoHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
	}
	,measureHeight: function(style,containingDOMElementData) {
		this.setComputedHeight(style,this.getComputedHeight(style,containingDOMElementData));
		style.getComputedStyle().marginTop = 0;
		style.getComputedStyle().marginBottom = 0;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		return 0;
	}
	,getComputedWidth: function(style,containingDOMElementData) {
		return 0;
	}
	,getComputedHeight: function(style,containingDOMElementData) {
		return 0;
	}
	,__class__: cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer
});
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
cocktailCore.domElement.js.BodyDOMElement = $hxClasses["cocktailCore.domElement.js.BodyDOMElement"] = function() {
	cocktailCore.domElement.abstract.AbstractBodyDOMElement.call(this);
}
cocktailCore.domElement.js.BodyDOMElement.__name__ = ["cocktailCore","domElement","js","BodyDOMElement"];
cocktailCore.domElement.js.BodyDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractBodyDOMElement;
cocktailCore.domElement.js.BodyDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.BodyDOMElement
});
cocktailCore.domElement.abstract.AbstractGraphicDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractGraphicDOMElement"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
	this._drawingManager = new cocktailCore.drawing.js.DrawingManager(nativeElement);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractGraphicDOMElement"];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype = $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype,{
	_drawingManager: null
	,beginFill: function(fillStyle,lineStyle) {
		this._drawingManager.beginFill(fillStyle,lineStyle);
	}
	,endFill: function() {
		this._drawingManager.endFill();
	}
	,clear: function() {
		this._drawingManager.clear();
	}
	,setLineStyle: function(lineStyle) {
		this._drawingManager.setLineStyle(lineStyle);
	}
	,setFillStyle: function(fillStyle) {
		this._drawingManager.setFillStyle(fillStyle);
	}
	,drawRect: function(x,y,width,height,cornerRadiuses) {
		this._drawingManager.drawRect(x,y,width,height,cornerRadiuses);
	}
	,drawEllipse: function(x,y,width,height) {
		this._drawingManager.drawEllipse(x,y,width,height);
	}
	,drawImage: function(source,destinationPoint,sourceRect) {
		this._drawingManager.drawImage(source,destinationPoint,sourceRect);
	}
	,lineTo: function(x,y) {
		this._drawingManager.lineTo(x,y);
	}
	,moveTo: function(x,y) {
		this._drawingManager.moveTo(x,y);
	}
	,curveTo: function(controlX,controlY,x,y) {
		this._drawingManager.curveTo(controlX,controlY,x,y);
	}
	,__class__: cocktailCore.domElement.abstract.AbstractGraphicDOMElement
});
cocktailCore.domElement.js.GraphicDOMElement = $hxClasses["cocktailCore.domElement.js.GraphicDOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.GraphicDOMElement.__name__ = ["cocktailCore","domElement","js","GraphicDOMElement"];
cocktailCore.domElement.js.GraphicDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
cocktailCore.domElement.js.GraphicDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype,{
	beginFill: function(fillStyle,lineStyle) {
		cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill.call(this,fillStyle,lineStyle);
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
			var repeat = $e[3], imageDOMElement = $e[2];
			canvasContext.fillStyle = this.getCanvasPattern(imageDOMElement,repeat);
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
			var repeat = $e[4], lineStyleData = $e[3], imageDOMElement = $e[2];
			this.initLineStyle(lineStyleData);
			canvasContext.strokeStyle = this.getCanvasPattern(imageDOMElement,repeat);
			break;
		}
	}
	,drawImage: function(source,destinationPoint,sourceRect) {
		if(destinationPoint == null) destinationPoint = { x : 0.0, y : 0.0};
		if(sourceRect == null) {
			var width = source.getWidth();
			var height = source.getHeight();
			sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
		}
		var canvasContext = this.getContext();
		canvasContext.drawImage(source.getNativeElement(),sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height,destinationPoint.x,destinationPoint.y,sourceRect.width,sourceRect.height);
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
		return genericAlpha * 0.01;
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
	,getCanvasPattern: function(imageDOMElement,repeat) {
		var canvasContext = this.getContext();
		var repeatValue = "";
		if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
		return canvasContext.createPattern(imageDOMElement.getNativeElement(),repeatValue);
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
	,__class__: cocktailCore.domElement.js.GraphicDOMElement
});
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementCreator"] = function() {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementCreator"];
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype = {
	createNativeElement: function(nativeElementType) {
		return null;
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementCreator
}
cocktailCore.style.positioner.FixedPositioner = $hxClasses["cocktailCore.style.positioner.FixedPositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.FixedPositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	__class__: cocktailCore.style.positioner.FixedPositioner
});
var ScreenResolutionSize = $hxClasses["ScreenResolutionSize"] = { __ename__ : ["ScreenResolutionSize"], __constructs__ : ["small","normal","large"] }
ScreenResolutionSize.small = ["small",0];
ScreenResolutionSize.small.toString = $estr;
ScreenResolutionSize.small.__enum__ = ScreenResolutionSize;
ScreenResolutionSize.normal = ["normal",1];
ScreenResolutionSize.normal.toString = $estr;
ScreenResolutionSize.normal.__enum__ = ScreenResolutionSize;
ScreenResolutionSize.large = ["large",2];
ScreenResolutionSize.large.toString = $estr;
ScreenResolutionSize.large.__enum__ = ScreenResolutionSize;
var ScreenResolution = $hxClasses["ScreenResolution"] = function() {
	var viewport = new cocktailCore.viewport.js.Viewport();
	if(viewport._getWidth() < 400) this.size = ScreenResolutionSize.small; else if(viewport._getWidth() < 600) this.size = ScreenResolutionSize.normal; else this.size = ScreenResolutionSize.large;
}
ScreenResolution.__name__ = ["ScreenResolution"];
ScreenResolution.prototype = {
	size: null
	,__class__: ScreenResolution
}
if(!cocktail.resource) cocktail.resource = {}
cocktail.resource.LoadingTypeValue = $hxClasses["cocktail.resource.LoadingTypeValue"] = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",1];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.ResourceLoaderManager = $hxClasses["cocktail.resource.ResourceLoaderManager"] = function() {
}
cocktail.resource.ResourceLoaderManager.__name__ = ["cocktail","resource","ResourceLoaderManager"];
cocktail.resource.ResourceLoaderManager._resourceDataArray = null;
cocktail.resource.ResourceLoaderManager.loadString = function(url,successCallback,errorCallback,allowCache) {
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, loadingType : cocktail.resource.LoadingTypeValue.data};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
}
cocktail.resource.ResourceLoaderManager.loadLibrary = function(url,successCallback,errorCallback,allowCache) {
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, loadingType : cocktail.resource.LoadingTypeValue.library};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
}
cocktail.resource.ResourceLoaderManager.addResourceData = function(resourceData) {
	if(cocktail.resource.ResourceLoaderManager._resourceDataArray == null) cocktail.resource.ResourceLoaderManager._resourceDataArray = new Array();
	cocktail.resource.ResourceLoaderManager._resourceDataArray.push(resourceData);
	if(cocktail.resource.ResourceLoaderManager._isLoading == false) cocktail.resource.ResourceLoaderManager.loadNextResource();
}
cocktail.resource.ResourceLoaderManager.loadNextResource = function() {
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
		resourceLoader.load(resourceDataToLoad.url,cocktail.resource.ResourceLoaderManager.onLoadComplete,cocktail.resource.ResourceLoaderManager.onLoadError,resourceDataToLoad.allowCache);
	}
}
cocktail.resource.ResourceLoaderManager.onLoadComplete = function(data) {
	var loadedResourceData = cocktail.resource.ResourceLoaderManager._resourceDataArray.shift();
	loadedResourceData.onLoadComplete(data);
	cocktail.resource.ResourceLoaderManager.loadNextResource();
}
cocktail.resource.ResourceLoaderManager.onLoadError = function(data) {
	var errorResourceData = cocktail.resource.ResourceLoaderManager._resourceDataArray.shift();
	errorResourceData.onLoadError(data);
	cocktail.resource.ResourceLoaderManager.loadNextResource();
}
cocktail.resource.ResourceLoaderManager.prototype = {
	__class__: cocktail.resource.ResourceLoaderManager
}
cocktailCore.nativeElement.js.NativeElementCreator = $hxClasses["cocktailCore.nativeElement.js.NativeElementCreator"] = function() {
	cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.call(this);
}
cocktailCore.nativeElement.js.NativeElementCreator.__name__ = ["cocktailCore","nativeElement","js","NativeElementCreator"];
cocktailCore.nativeElement.js.NativeElementCreator.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
cocktailCore.nativeElement.js.NativeElementCreator.prototype = $extend(cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype,{
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
		case 7:
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
		}
		return nativeElement;
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
cocktail.domElement.LineStyleValue.monochrome = function(colorStop,lineStyle) { var $x = ["monochrome",1,colorStop,lineStyle]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
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
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	shrinkToFit: function(style,containingDOMElementData,minimumWidth) {
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
		return shrinkedWidth;
	}
	,applyContentHeight: function(style,containingDOMElementData,childrenHeight) {
		var height;
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			var computedStyle = style.getComputedStyle();
			height = containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		} else height = childrenHeight;
		return height;
	}
	,measurePositionOffsets: function(style,containingDOMElementData) {
	}
	,measureAutoWidth: function(style,containingDOMElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) computedStyle.marginLeft = 0; else computedStyle.marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) computedStyle.marginRight = 0; else computedStyle.marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		if(style.getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			computedStyle.left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			computedStyle.right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			computedStyle.width = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
		} else computedStyle.width = 10000000;
	}
	,measureWidth: function(style,containingDOMElementData) {
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
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		var computedStyle = style.getComputedStyle();
		if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
			style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			this.setComputedHeight(style,containingDOMElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom);
		}
	}
	,measureHeight: function(style,containingDOMElementData) {
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
	}
	,getComputedStaticLeft: function(style,containingDOMElementData) {
		return style.getComputedStyle().marginLeft;
	}
	,getComputedStaticTop: function(style,containingDOMElementData) {
		return style.getComputedStyle().marginTop;
	}
	,doShrinkToFit: function(style,containingDOMElementData,minimumWidth) {
		return minimumWidth;
	}
	,__class__: cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer
});
cocktailCore.style.formatter.InlineFormattingContext = $hxClasses["cocktailCore.style.formatter.InlineFormattingContext"] = function(domElement,previousFormattingContext) {
	this._firstLineLaidOut = false;
	this._domElementInLineBox = new Array();
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
}
cocktailCore.style.formatter.InlineFormattingContext.__name__ = ["cocktailCore","style","formatter","InlineFormattingContext"];
cocktailCore.style.formatter.InlineFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.InlineFormattingContext.prototype = $extend(cocktailCore.style.formatter.FormattingContext.prototype,{
	_domElementInLineBox: null
	,_firstLineLaidOut: null
	,destroy: function() {
		this.startNewLine(0,true);
	}
	,insert: function(domElement,parentDOMElement,position) {
		var remainingWidth = this.getRemainingLineWidth();
		if(position == true) {
			if(this._firstLineLaidOut == false) remainingWidth -= this._containingDOMElement.getStyle().getComputedStyle().textIndent;
			if(remainingWidth - domElement.getOffsetWidth() < 0) {
				switch( (domElement.getStyle().getComputedStyle().whiteSpace)[1] ) {
				case 0:
				case 4:
					if(this._firstLineLaidOut == false) this.startNewLine(domElement.getOffsetWidth() + this._containingDOMElement.getStyle().getComputedStyle().textIndent); else this.startNewLine(domElement.getOffsetWidth());
					break;
				default:
				}
			}
		}
		this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktail.style.InlineBoxValue.domElement, parentDOMElement : parentDOMElement, x : 0, y : 0, position : position});
		if(position == true) cocktailCore.style.formatter.FormattingContext.prototype.insert.call(this,domElement,parentDOMElement,position);
	}
	,insertSpace: function(domElement,parentDOMElement) {
		var remainingWidth = this.getRemainingLineWidth();
		if(this._firstLineLaidOut == false) remainingWidth -= this._containingDOMElement.getStyle().getComputedStyle().textIndent;
		if(remainingWidth - domElement.getOffsetWidth() < 0) {
			switch( (domElement.getStyle().getComputedStyle().whiteSpace)[1] ) {
			case 0:
			case 4:
				this.startNewLine(domElement.getOffsetWidth());
				break;
			default:
			}
		}
		this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktail.style.InlineBoxValue.domElement, parentDOMElement : parentDOMElement, x : 0, y : 0, position : true});
		cocktailCore.style.formatter.FormattingContext.prototype.insertSpace.call(this,domElement,parentDOMElement);
	}
	,place: function(domElement,parentDOMElement,position) {
		cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement,parentDOMElement,position);
		this._formattingContextData.x += domElement.getOffsetWidth();
	}
	,startNewLine: function(domElementWidth,isLastLine) {
		if(isLastLine == null) isLastLine = false;
		if(this._domElementInLineBox.length > 0) {
			this.removeSpaces();
			var lineBoxHeight = this.computeLineBoxHeight();
			var lineWidth = this.alignLineBox(this._firstLineLaidOut == false,isLastLine);
			if(lineWidth > this._formattingContextData.maxWidth) this._formattingContextData.maxWidth = lineWidth;
			var _g1 = 0, _g = this._domElementInLineBox.length;
			while(_g1 < _g) {
				var i = _g1++;
				var childTemporaryPositionData = this.getChildTemporaryPositionData(this._domElementInLineBox[i].domElement,this._domElementInLineBox[i].x,this._domElementInLineBox[i].y,0,this._domElementInLineBox[i].position);
				this.getChildrenTemporaryPositionData(this._domElementInLineBox[i].parentDOMElement).push(childTemporaryPositionData);
				this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,childTemporaryPositionData.x);
				this._domElementInLineBox[i].domElement.getStyle().setNativeY(this._domElementInLineBox[i].domElement,childTemporaryPositionData.y);
			}
			this._domElementInLineBox = new Array();
			this._formattingContextData.y += lineBoxHeight;
			this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,domElementWidth,this._containingDOMElementWidth);
			this._formattingContextData.maxHeight = this._formattingContextData.y;
			this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
			this._firstLineLaidOut = true;
		} else {
			this._formattingContextData.y = this._floatsManager.getFirstAvailableY(this._formattingContextData,domElementWidth,this._containingDOMElementWidth);
			this._formattingContextData.x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
		}
	}
	,clearFloat: function(clear,isFloat) {
		if(isFloat == true) this._formattingContextData.y = this._floatsManager.clearFloat(clear,this._formattingContextData);
	}
	,placeFloat: function(domElement,parentDOMElement,floatData) {
		cocktailCore.style.formatter.FormattingContext.prototype.placeFloat.call(this,domElement,parentDOMElement,floatData);
		this.getFormattingContextData().x = this._floatsManager.getLeftFloatOffset(this._formattingContextData.y);
	}
	,removeSpaces: function() {
		switch( (this._domElementInLineBox[0].domElement.getStyle().getComputedStyle().whiteSpace)[1] ) {
		case 0:
		case 2:
		case 4:
			switch( (this._domElementInLineBox[0].domElementType)[1] ) {
			case 1:
				this._domElementInLineBox.shift();
				break;
			default:
			}
			break;
		default:
		}
		if(this._domElementInLineBox.length > 0) {
			switch( (this._domElementInLineBox[this._domElementInLineBox.length - 1].domElement.getStyle().getComputedStyle().whiteSpace)[1] ) {
			case 0:
			case 2:
			case 4:
				switch( (this._domElementInLineBox[this._domElementInLineBox.length - 1].domElementType)[1] ) {
				case 1:
					this._domElementInLineBox.pop();
					break;
				default:
				}
				break;
			default:
			}
		}
	}
	,alignLineBox: function(isFirstLine,isLastLine) {
		var concatenatedLength = 0;
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._domElementInLineBox[i].position == true) concatenatedLength += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		var remainingSpace;
		var flowX;
		if(isFirstLine == true) {
			remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._containingDOMElement.getStyle().getComputedStyle().textIndent - this._floatsManager.getLeftFloatOffset(this._formattingContextData.y) - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._containingDOMElementWidth);
			flowX = this._containingDOMElement.getStyle().getComputedStyle().textIndent;
		} else {
			remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._formattingContextData.y) - this._floatsManager.getRightFloatOffset(this._formattingContextData.y,this._containingDOMElementWidth);
			flowX = 0;
		}
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
		return concatenatedLength;
	}
	,alignLeft: function(flowX) {
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._domElementInLineBox[i].position == true) {
				var domElement = this._domElementInLineBox[i].domElement;
				this._domElementInLineBox[i].x = flowX;
				flowX += domElement.getOffsetWidth();
			}
		}
	}
	,alignCenter: function(flowX,remainingSpace) {
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._domElementInLineBox[i].position == true) {
				var domElement = this._domElementInLineBox[i].domElement;
				this._domElementInLineBox[i].x = Math.round(remainingSpace / 2) + flowX;
				flowX += domElement.getOffsetWidth();
			}
		}
	}
	,alignRight: function(flowX,remainingSpace) {
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._domElementInLineBox[i].position == true) {
				var domElement = this._domElementInLineBox[i].domElement;
				this._domElementInLineBox[i].x = flowX + remainingSpace;
				flowX += domElement.getOffsetWidth();
			}
		}
	}
	,alignJustify: function(flowX,remainingSpace) {
		var spacesNumber = 0;
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			switch( (this._domElementInLineBox[i].domElementType)[1] ) {
			case 1:
				spacesNumber++;
				break;
			default:
			}
		}
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var domElement = this._domElementInLineBox[i].domElement;
			switch( (this._domElementInLineBox[i].domElementType)[1] ) {
			case 1:
				var spaceWidth = Math.round(remainingSpace / spacesNumber);
				spacesNumber--;
				remainingSpace -= spaceWidth;
				flowX += spaceWidth;
				break;
			default:
			}
			this._domElementInLineBox[i].x = flowX;
			flowX += domElement.getOffsetWidth();
		}
	}
	,computeLineBoxHeight: function() {
		var lineBoxAscent = 0;
		var lineBoxDescent = 0;
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var domElement = this._domElementInLineBox[i].domElement;
			var domElementAscent;
			var domElementDescent;
			var domElementVerticalAlign = domElement.getStyle().getComputedStyle().verticalAlign;
			if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) {
				domElementAscent = domElement.getOffsetHeight();
				domElementDescent = 0;
				switch( (this._domElementInLineBox[i].domElement.getStyle().getVerticalAlign())[1] ) {
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
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			var domElement = this._domElementInLineBox[i].domElement;
			if(this._domElementInLineBox[i].position == true) {
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
				this._domElementInLineBox[i].y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + this._formattingContextData.y;
				if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) {
					switch( (domElement.getStyle().getVerticalAlign())[1] ) {
					case 3:
						this._domElementInLineBox[i].y = this._formattingContextData.y;
						break;
					default:
						this._domElementInLineBox[i].y -= domElement.getOffsetHeight();
					}
				}
			}
		}
		return Math.round(lineBoxHeight);
	}
	,__class__: cocktailCore.style.formatter.InlineFormattingContext
});
var WebAppStyle = $hxClasses["WebAppStyle"] = function() { }
WebAppStyle.__name__ = ["WebAppStyle"];
WebAppStyle.getDefaultStyle = function(domElement) {
	domElement.getStyle().setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(130));
}
WebAppStyle.getBodyStyle = function(domElement) {
	WebAppStyle.getDefaultStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
WebAppStyle.getMainContainerStyle = function(domElement) {
	WebAppStyle.getDefaultStyle(domElement);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
}
WebAppStyle.getPageContainerStyle = function(domElement) {
	WebAppStyle.getDefaultStyle(domElement);
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
}
WebAppStyle.getHomePageStyle = function(domElement) {
}
WebAppStyle.getPageStyle = function(domElement) {
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
}
WebAppStyle.getBgStyle = function(domElement) {
	WebAppStyle.getDefaultStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setRight(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
}
WebAppStyle.getHeaderStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
WebAppStyle.getHeaderTileStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
}
WebAppStyle.getHeaderLogoStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(4)));
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setRight(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(44)));
}
WebAppStyle.getFooterStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
WebAppStyle.getFooterMenuStyle = function(domElement) {
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.autoValue);
}
WebAppStyle.getFooterTileStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.fixed);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.autoValue);
	domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(48)));
}
WebAppStyle.getHeaderTextStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#454545"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("HelveticaNeue"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.percent(100));
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
}
WebAppStyle.getBackButtonStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(6)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(10)));
}
WebAppStyle.getBackButtonTextStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("HelveticaNeue"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(30)));
}
WebAppStyle.getBackButtonImageStyle = function(domElement) {
	WebAppStyle.getHeaderStyle(domElement);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineStyle);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
WebAppStyle.getTextContentStyle = function(domElement) {
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
}
WebAppStyle.prototype = {
	__class__: WebAppStyle
}
var Constants = $hxClasses["Constants"] = function() { }
Constants.__name__ = ["Constants"];
Constants.prototype = {
	__class__: Constants
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
cocktail.style.InlineBoxValue = $hxClasses["cocktail.style.InlineBoxValue"] = { __ename__ : ["cocktail","style","InlineBoxValue"], __constructs__ : ["domElement","space","tab"] }
cocktail.style.InlineBoxValue.domElement = ["domElement",0];
cocktail.style.InlineBoxValue.domElement.toString = $estr;
cocktail.style.InlineBoxValue.domElement.__enum__ = cocktail.style.InlineBoxValue;
cocktail.style.InlineBoxValue.space = ["space",1];
cocktail.style.InlineBoxValue.space.toString = $estr;
cocktail.style.InlineBoxValue.space.__enum__ = cocktail.style.InlineBoxValue;
cocktail.style.InlineBoxValue.tab = ["tab",2];
cocktail.style.InlineBoxValue.tab.toString = $estr;
cocktail.style.InlineBoxValue.tab.__enum__ = cocktail.style.InlineBoxValue;
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
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype,{
	measurePositionOffsets: function(style,containingDOMElementData) {
		this.measureHorizontalPositionOffsets(style,containingDOMElementData);
		this.measureVerticalPositionOffsets(style,containingDOMElementData);
		style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureHorizontalPositionOffsets: function(style,containingDOMElementData) {
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
	}
	,measureVerticalPositionOffsets: function(style,containingDOMElementData) {
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
	}
	,getComputedStaticLeft: function(style,containingDOMElementData) {
		return style.getComputedStyle().marginLeft;
	}
	,getComputedStaticTop: function(style,containingDOMElementData) {
		return style.getComputedStyle().marginTop;
	}
	,__class__: cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer
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
cocktail.unit.ColorValue = $hxClasses["cocktail.unit.ColorValue"] = { __ename__ : ["cocktail","unit","ColorValue"], __constructs__ : ["RGB","hex","keyword"] }
cocktail.unit.ColorValue.RGB = function(red,green,blue) { var $x = ["RGB",0,red,green,blue]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.hex = function(value) { var $x = ["hex",1,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.keyword = function(value) { var $x = ["keyword",2,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
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
cocktailCore.resource.js.LibraryLoader = $hxClasses["cocktailCore.resource.js.LibraryLoader"] = function() {
	cocktailCore.resource.abstract.AbstractLibraryLoader.call(this);
}
cocktailCore.resource.js.LibraryLoader.__name__ = ["cocktailCore","resource","js","LibraryLoader"];
cocktailCore.resource.js.LibraryLoader.__super__ = cocktailCore.resource.abstract.AbstractLibraryLoader;
cocktailCore.resource.js.LibraryLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractLibraryLoader.prototype,{
	doLoad: function(url) {
		this._nativeElement.setAttribute("type","text/javascript");
		this._nativeElement.setAttribute("language","JavaScript");
		js.Lib.document.getElementsByTagName("head")[0].appendChild(this._nativeElement);
		cocktailCore.resource.abstract.AbstractLibraryLoader.prototype.doLoad.call(this,url);
	}
	,__class__: cocktailCore.resource.js.LibraryLoader
});
if(!cocktailCore.mouse) cocktailCore.mouse = {}
if(!cocktailCore.mouse["abstract"]) cocktailCore.mouse["abstract"] = {}
cocktailCore.mouse.abstract.AbstractMouse = $hxClasses["cocktailCore.mouse.abstract.AbstractMouse"] = function(nativeElement) {
	this._nativeElement = nativeElement;
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
	,_nativeElement: null
	,onNativeMouseDown: function(event) {
		if(this.getOnMouseDown() != null) (this.getOnMouseDown())(this.getMouseData(event));
	}
	,onNativeMouseUp: function(event) {
		if(this.getOnMouseUp() != null) (this.getOnMouseUp())(this.getMouseData(event));
	}
	,onNativeMouseOver: function(event) {
		if(this.getOnMouseOver() != null) (this.getOnMouseOver())(this.getMouseData(event));
	}
	,onNativeMouseOut: function(event) {
		if(this.getOnMouseOut() != null) (this.getOnMouseOut())(this.getMouseData(event));
	}
	,onNativeMouseMove: function(event) {
		if(this.getOnMouseMove() != null) (this.getOnMouseMove())(this.getMouseData(event));
	}
	,onNativeMouseDoubleClick: function(event) {
		if(this.getOnMouseDoubleClick() != null) (this.getOnMouseDoubleClick())(this.getMouseData(event));
	}
	,getMouseData: function(event) {
		return null;
	}
	,setOnMouseDown: function(value) {
		return this._onMouseDown = value;
	}
	,getOnMouseDown: function() {
		return this._onMouseDown;
	}
	,setOnMouseUp: function(value) {
		return this._onMouseUp = value;
	}
	,getOnMouseUp: function() {
		return this._onMouseUp;
	}
	,setOnMouseOver: function(value) {
		return this._onMouseOver = value;
	}
	,getOnMouseOver: function() {
		return this._onMouseOver;
	}
	,setOnMouseOut: function(value) {
		return this._onMouseOut = value;
	}
	,getOnMouseOut: function() {
		return this._onMouseOut;
	}
	,setOnMouseMove: function(value) {
		return this._onMouseMove = value;
	}
	,getOnMouseMove: function() {
		return this._onMouseMove;
	}
	,setOnMouseDoubleClick: function(value) {
		return this._onMouseDoubleClick = value;
	}
	,getOnMouseDoubleClick: function() {
		return this._onMouseDoubleClick;
	}
	,__class__: cocktailCore.mouse.abstract.AbstractMouse
	,__properties__: {set_onMouseDoubleClick:"setOnMouseDoubleClick",get_onMouseDoubleClick:"getOnMouseDoubleClick",set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown"}
}
var ApplicationStructure = $hxClasses["ApplicationStructure"] = function() {
	this.pagesContainer = Utils.getContainer();
	this.createAllPages();
}
ApplicationStructure.__name__ = ["ApplicationStructure"];
ApplicationStructure.prototype = {
	pagesContainer: null
	,navigation: null
	,_page1: null
	,_page2: null
	,_page3: null
	,_page4: null
	,_page5: null
	,createAllPages: function() {
		var pluginsRss = new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=5318&format=rss2");
		pluginsRss.onLoad = this.onPage1RssLoad.$bind(this);
		var blogRss = new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=358&format=rss2");
		blogRss.onLoad = this.onPage2RssLoad.$bind(this);
		var themesRss = new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=642&format=rss2");
		themesRss.onLoad = this.onPage3RssLoad.$bind(this);
		var themesRss1 = new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=646&format=rss2");
		themesRss1.onLoad = this.onPage4RssLoad.$bind(this);
		var pluginsRss1 = new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=657&format=rss2");
		pluginsRss1.onLoad = this.onPage5RssLoad.$bind(this);
	}
	,onPage1RssLoad: function(rss) {
		var cells = components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);
		this._page2 = this.createHeaderListPage("Silex Labs",cells);
		this.navigation = new Navigation(this.pagesContainer,this._page2);
	}
	,onPage2RssLoad: function(rss) {
		var cells = components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);
		this._page1 = this.createHeaderListPage("amfPHP",cells);
	}
	,onPage3RssLoad: function(rss) {
		var cells = components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);
		this._page3 = this.createHeaderListPage("Silex",cells);
	}
	,onPage4RssLoad: function(rss) {
		var cells = components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);
		this._page4 = this.createHeaderListPage("Themes",cells);
	}
	,onPage5RssLoad: function(rss) {
		var me = this;
		var cells = components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);
		this._page5 = this.createHeaderListPage("Plugins",cells);
		var footer = this.createFooterMenu();
		this.pagesContainer.addChild(footer);
		var resetFooterStyle = function(event) {
			me.pagesContainer.removeChild(footer);
			me.pagesContainer.addChild(footer);
		};
		js.Lib.window.onscroll = resetFooterStyle;
		js.Lib.window.onresize = resetFooterStyle;
	}
	,createHeaderListPage: function(title,cellDataArray) {
		var page = Utils.getContainer();
		var header = this.createHeader(title);
		var list = this.createThumbList(cellDataArray);
		list.onChange = this.onChangeListCallback.$bind(this);
		page.addChild(list);
		page.addChild(header);
		WebAppStyle.getPageStyle(page);
		return page;
	}
	,createHeader: function(title) {
		var header = Utils.getContainer();
		var headerTile = new cocktailCore.domElement.js.ImageDOMElement();
		WebAppStyle.getHeaderTileStyle(headerTile);
		var headerTilePath = "images/header.jpg";
		headerTile.load(headerTilePath);
		header.addChild(headerTile);
		var headerLogo = new cocktailCore.domElement.js.ImageDOMElement();
		WebAppStyle.getHeaderLogoStyle(headerLogo);
		var headerLogoPath = "images/silex-labs.png";
		headerLogo.load(headerLogoPath);
		header.addChild(headerLogo);
		var headerTitle = new cocktailCore.textElement.js.TextElement(title);
		var headerTitleContainer = Utils.getContainer();
		headerTitleContainer.addText(headerTitle);
		WebAppStyle.getHeaderTextStyle(headerTitleContainer);
		header.addChild(headerTitleContainer);
		WebAppStyle.getHeaderStyle(header);
		return header;
	}
	,createFooterMenu: function() {
		var container = Utils.getContainer();
		WebAppStyle.getFooterStyle(container);
		var tile = new cocktailCore.domElement.js.ImageDOMElement();
		var headerTilePath = "images/footer.jpg";
		WebAppStyle.getFooterTileStyle(tile);
		tile.load(headerTilePath);
		container.addChild(tile);
		var cells = new Array();
		cells.push({ content : { icon : "images/menu3.png", title : "Silex Labs"}, action : "goToPage", actionTarget : this._page2});
		cells.push({ content : { icon : "images/menu3.png", title : "amfPHP"}, action : "goToPage", actionTarget : this._page1});
		cells.push({ content : { icon : "images/menu3.png", title : "Silex"}, action : "goToPage", actionTarget : this._page3});
		cells.push({ content : { icon : "images/menu2.png", title : "Themes"}, action : "goToPage", actionTarget : this._page4});
		cells.push({ content : { icon : "images/menu1.png", title : "Plugins"}, action : "goToPage", actionTarget : this._page5});
		var menuList = this.createAppList(cells);
		menuList.onChange = this.onChangeListCallback.$bind(this);
		container.addChild(menuList);
		return container;
	}
	,createThumbList: function(content) {
		var listData = components.lists.ListBaseUtils.createListModel();
		listData.content = content;
		var listStyle = { list : components.lists.ThumbTextList1Style.getListStyle, cell : components.lists.ThumbTextList1Style.getCellStyle, cellInfoBlock : components.lists.ThumbTextList1Style.getCellInfoBlockStyle, cellNumber : components.lists.ThumbTextList1Style.getCellNumberStyle, cellInfoBlockLine : components.lists.ThumbTextList1Style.getCellInfoBlockLineStyle, cellInfoBlockImage : components.lists.ThumbTextList1Style.getCellInfoBlockImageStyle, cellCommentCount : components.lists.ThumbTextList1Style.getCellCommentCountStyle, cellThumbnail : components.lists.ThumbTextList1Style.getCellThumbnailStyle, cellTextBlock : components.lists.ThumbTextList1Style.getCellTextBlockStyle, cellTitle : components.lists.ThumbTextList1Style.getCellTitleStyle, cellComment : components.lists.ThumbTextList1Style.getCellCommentStyle, cellDescription : components.lists.ThumbTextList1Style.getCellDescriptionStyle, cellLine : components.lists.ThumbTextList1Style.getCellLineStyle, cellMouseOver : components.lists.ThumbTextList1Style.getCellMouseOverStyle, cellMouseOut : components.lists.ThumbTextList1Style.getCellMouseOutStyle, cellMouseDown : components.lists.ThumbTextList1Style.getCellMouseDownStyle, cellMouseUp : components.lists.ThumbTextList1Style.getCellMouseUpStyle};
		var list = new components.lists.ThumbTextList1(listData,listStyle);
		return list;
	}
	,createAppList: function(content) {
		var listData = components.lists.ListBaseUtils.createListModel();
		listData.content = content;
		var listStyle = { list : components.lists.AppListStyle.getListStyle, cell : components.lists.AppListStyle.getCellStyle, cellSelected : components.lists.AppListStyle.getCellSelectedStyle, cellIcon : components.lists.AppListStyle.getCellImageStyle, cellTitle : components.lists.AppListStyle.getCellTextStyle, cellMouseOver : components.lists.AppListStyle.getCellMouseOverStyle, cellMouseOut : components.lists.AppListStyle.getCellMouseOutStyle, cellMouseDown : components.lists.AppListStyle.getCellMouseDownStyle, cellMouseUp : components.lists.AppListStyle.getCellMouseUpStyle};
		var list = new components.lists.AppList(listData,listStyle);
		return list;
	}
	,goToPreviousPage: function(mouseEvent) {
		this.navigation.goToPreviousPage();
	}
	,onChangeListCallback: function(cell) {
		this.navigation.onChangeListCallback(cell);
	}
	,__class__: ApplicationStructure
}
if(!cocktailCore.drawing.js) cocktailCore.drawing.js = {}
cocktailCore.drawing.js.DrawingManager = $hxClasses["cocktailCore.drawing.js.DrawingManager"] = function(nativeElement) {
	cocktailCore.drawing.abstract.AbstractDrawingManager.call(this,nativeElement);
}
cocktailCore.drawing.js.DrawingManager.__name__ = ["cocktailCore","drawing","js","DrawingManager"];
cocktailCore.drawing.js.DrawingManager.__super__ = cocktailCore.drawing.abstract.AbstractDrawingManager;
cocktailCore.drawing.js.DrawingManager.prototype = $extend(cocktailCore.drawing.abstract.AbstractDrawingManager.prototype,{
	__class__: cocktailCore.drawing.js.DrawingManager
});
if(!cocktailCore.style.floats) cocktailCore.style.floats = {}
cocktailCore.style.floats.FloatsManager = $hxClasses["cocktailCore.style.floats.FloatsManager"] = function() {
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
}
cocktailCore.style.floats.FloatsManager.__name__ = ["cocktailCore","style","floats","FloatsManager"];
cocktailCore.style.floats.FloatsManager.prototype = {
	_floats: null
	,floats: null
	,addFloats: function(parentFormattingContext) {
		var _g1 = 0, _g = parentFormattingContext.getFloatsManager().getFloats().left.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._floats.left.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().left[i],parentFormattingContext.getFormattingContextData()));
		}
		var _g1 = 0, _g = parentFormattingContext.getFloatsManager().getFloats().right.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._floats.right.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().right[i],parentFormattingContext.getFormattingContextData()));
		}
	}
	,retrieveFloats: function(childrenFormattingContext) {
		if(childrenFormattingContext != null) {
			var _g1 = 0, _g = childrenFormattingContext.getFloatsManager().getFloats().left.length;
			while(_g1 < _g) {
				var i = _g1++;
				this._floats.left.push(childrenFormattingContext.getFloatsManager().getFloats().left[i]);
			}
			var _g1 = 0, _g = childrenFormattingContext.getFloatsManager().getFloats().right.length;
			while(_g1 < _g) {
				var i = _g1++;
				this._floats.right.push(childrenFormattingContext.getFloatsManager().getFloats().right[i]);
			}
		}
	}
	,globalTolocal: function(floatData,formattingContextData) {
		var floatY = floatData.y - formattingContextData.y;
		var convertedFloatData = { x : floatData.x, y : floatY, width : floatData.width, height : floatData.height};
		return convertedFloatData;
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
	,computeFloatData: function(domElement,formattingContextData,containingBlockWidth) {
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
		return ret;
	}
	,getLeftFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		var floatData = this.getFloatData(domElement,formattingContextData,containingBlockWidth);
		floatData.x = this.getLeftFloatOffset(floatData.y);
		return floatData;
	}
	,getRightFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		var floatData = this.getFloatData(domElement,formattingContextData,containingBlockWidth);
		floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth);
		return floatData;
	}
	,getFloatData: function(domElement,formattingContextData,containingBlockWidth) {
		var floatWidth = domElement.getOffsetWidth();
		var floatHeight = domElement.getOffsetHeight();
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
	,__class__: cocktailCore.style.floats.FloatsManager
	,__properties__: {get_floats:"getFloats"}
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","NoneBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer
});
cocktail.nativeElement.NativeElementManager = $hxClasses["cocktail.nativeElement.NativeElementManager"] = function() {
}
cocktail.nativeElement.NativeElementManager.__name__ = ["cocktail","nativeElement","NativeElementManager"];
cocktail.nativeElement.NativeElementManager._nativeElementCreator = null;
cocktail.nativeElement.NativeElementManager._nativeElementPathManager = null;
cocktail.nativeElement.NativeElementManager.getRoot = function() {
	if(cocktail.nativeElement.NativeElementManager._nativeElementPathManager == null) cocktail.nativeElement.NativeElementManager._nativeElementPathManager = new cocktailCore.nativeElement.js.NativeElementPathManager();
	return cocktail.nativeElement.NativeElementManager._nativeElementPathManager.getRoot();
}
cocktail.nativeElement.NativeElementManager.createNativeElement = function(nativeElementType) {
	if(cocktail.nativeElement.NativeElementManager._nativeElementCreator == null) cocktail.nativeElement.NativeElementManager._nativeElementCreator = new cocktailCore.nativeElement.js.NativeElementCreator();
	return cocktail.nativeElement.NativeElementManager._nativeElementCreator.createNativeElement(nativeElementType);
}
cocktail.nativeElement.NativeElementManager.prototype = {
	__class__: cocktail.nativeElement.NativeElementManager
}
var WebApp = $hxClasses["WebApp"] = function() {
	this._body = new cocktailCore.domElement.js.BodyDOMElement();
	WebAppStyle.getBodyStyle(this._body);
	this.drawInterface();
}
WebApp.__name__ = ["WebApp"];
WebApp.main = function() {
	new WebApp();
}
WebApp.prototype = {
	_body: null
	,_mainContainer: null
	,drawInterface: function() {
		var applicationStructure = new ApplicationStructure();
		this._mainContainer = applicationStructure.pagesContainer;
		WebAppStyle.getDefaultStyle(this._mainContainer);
		this._body.addChild(this._mainContainer);
	}
	,__class__: WebApp
}
cocktailCore.resource.js.StringLoader = $hxClasses["cocktailCore.resource.js.StringLoader"] = function() {
	cocktailCore.resource.abstract.AbstractStringLoader.call(this);
}
cocktailCore.resource.js.StringLoader.__name__ = ["cocktailCore","resource","js","StringLoader"];
cocktailCore.resource.js.StringLoader.__super__ = cocktailCore.resource.abstract.AbstractStringLoader;
cocktailCore.resource.js.StringLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractStringLoader.prototype,{
	__class__: cocktailCore.resource.js.StringLoader
});
cocktailCore.style.abstract.AbstractBodyStyle = $hxClasses["cocktailCore.style.abstract.AbstractBodyStyle"] = function(domElement) {
	cocktailCore.style.js.ContainerStyle.call(this,domElement);
	this._isDirty = false;
}
cocktailCore.style.abstract.AbstractBodyStyle.__name__ = ["cocktailCore","style","abstract","AbstractBodyStyle"];
cocktailCore.style.abstract.AbstractBodyStyle.__super__ = cocktailCore.style.js.ContainerStyle;
cocktailCore.style.abstract.AbstractBodyStyle.prototype = $extend(cocktailCore.style.js.ContainerStyle.prototype,{
	invalidate: function() {
		if(this._isDirty == false) {
			this._isDirty = true;
			var viewPortData = this.getViewportData();
			var lastPositionedDOMElementData = { children : new Array(), data : viewPortData};
			this.scheduleLayout(viewPortData,lastPositionedDOMElementData,viewPortData);
		}
	}
	,doPositionAbsolutelyPositionedDOMElements: function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
		isFirstPositionedAncestor = true;
		return cocktailCore.style.js.ContainerStyle.prototype.doPositionAbsolutelyPositionedDOMElements.call(this,isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData);
	}
	,getFormatingContext: function(previousFormatingContext) {
		return new cocktailCore.style.formatter.BlockFormattingContext(this._domElement,null);
	}
	,setNativeX: function(domElement,x) {
	}
	,setNativeY: function(domElement,y) {
	}
	,setNativeWidth: function(width) {
	}
	,setNativeHeight: function(height) {
	}
	,setNativeOpacity: function(opacity) {
	}
	,setNativeVisibility: function(visibility) {
	}
	,__class__: cocktailCore.style.abstract.AbstractBodyStyle
});
cocktailCore.style.js.BodyStyle = $hxClasses["cocktailCore.style.js.BodyStyle"] = function(domElement) {
	cocktailCore.style.abstract.AbstractBodyStyle.call(this,domElement);
}
cocktailCore.style.js.BodyStyle.__name__ = ["cocktailCore","style","js","BodyStyle"];
cocktailCore.style.js.BodyStyle.__super__ = cocktailCore.style.abstract.AbstractBodyStyle;
cocktailCore.style.js.BodyStyle.prototype = $extend(cocktailCore.style.abstract.AbstractBodyStyle.prototype,{
	__class__: cocktailCore.style.js.BodyStyle
});
cocktailCore.style.computer.VisualEffectStylesComputer = $hxClasses["cocktailCore.style.computer.VisualEffectStylesComputer"] = function() {
}
cocktailCore.style.computer.VisualEffectStylesComputer.__name__ = ["cocktailCore","style","computer","VisualEffectStylesComputer"];
cocktailCore.style.computer.VisualEffectStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.opacity = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedOpacity(style);
	computedStyle.visibility = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedVisibility(style);
	computedStyle.transformOrigin = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin(style);
	computedStyle.transform = cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransform(style);
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedOpacity = function(style) {
	var opacity;
	var $e = (style.getOpacity());
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		opacity = value;
		break;
	}
	return opacity;
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedVisibility = function(style) {
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
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransformOrigin = function(style) {
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
	return transformOriginPoint;
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTransform = function(style) {
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
	return matrix;
}
cocktailCore.style.computer.VisualEffectStylesComputer.getComputedTranslation = function(style,translation,percentReference) {
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
	return computedTranslation;
}
cocktailCore.style.computer.VisualEffectStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.VisualEffectStylesComputer
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer
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
if(!cocktailCore.classInstance.js) cocktailCore.classInstance.js = {}
cocktailCore.classInstance.js.ClassInstance = $hxClasses["cocktailCore.classInstance.js.ClassInstance"] = function(nativeInstanceClassName) {
	cocktailCore.classInstance.abstract.AbstractClassInstance.call(this,nativeInstanceClassName);
	if(Type.resolveClass(nativeInstanceClassName) != null) this._nativeInstance = Type.createInstance(Type.resolveClass(nativeInstanceClassName),[]); else this._nativeInstance = js.Lib.eval("new " + nativeInstanceClassName + "()");
}
cocktailCore.classInstance.js.ClassInstance.__name__ = ["cocktailCore","classInstance","js","ClassInstance"];
cocktailCore.classInstance.js.ClassInstance.__super__ = cocktailCore.classInstance.abstract.AbstractClassInstance;
cocktailCore.classInstance.js.ClassInstance.prototype = $extend(cocktailCore.classInstance.abstract.AbstractClassInstance.prototype,{
	__class__: cocktailCore.classInstance.js.ClassInstance
});
cocktailCore.domElement.js.LinkDOMElement = $hxClasses["cocktailCore.domElement.js.LinkDOMElement"] = function() {
	cocktailCore.domElement.abstract.AbstractLinkDOMElement.call(this);
}
cocktailCore.domElement.js.LinkDOMElement.__name__ = ["cocktailCore","domElement","js","LinkDOMElement"];
cocktailCore.domElement.js.LinkDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractLinkDOMElement;
cocktailCore.domElement.js.LinkDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractLinkDOMElement.prototype,{
	setHref: function(value) {
		this._nativeElement.href = value;
		cocktailCore.domElement.abstract.AbstractLinkDOMElement.prototype.setHref.call(this,value);
		return value;
	}
	,setTarget: function(value) {
		this._nativeElement.target = this.getTargetAsString(value);
		cocktailCore.domElement.abstract.AbstractLinkDOMElement.prototype.setTarget.call(this,value);
		return value;
	}
	,__class__: cocktailCore.domElement.js.LinkDOMElement
});
components.lists.ThumbTextList1 = $hxClasses["components.lists.ThumbTextList1"] = function(list,listStyle) {
	var screenResolution = new ScreenResolution();
	this.screenResolutionSize = screenResolution.size;
	components.lists.ListBase.call(this,list,listStyle);
}
components.lists.ThumbTextList1.__name__ = ["components","lists","ThumbTextList1"];
components.lists.ThumbTextList1.__super__ = components.lists.ListBase;
components.lists.ThumbTextList1.prototype = $extend(components.lists.ListBase.prototype,{
	screenResolutionSize: null
	,getCellData: function(cellData,listStyle) {
		var cellContent = new Array();
		var cellInfoBlockContainer = Utils.getContainer();
		listStyle.cellInfoBlock(cellInfoBlockContainer);
		cellContent.push(cellInfoBlockContainer);
		var cellNumberContainer = Utils.getContainer();
		var textElement = new cocktailCore.textElement.js.TextElement(Std.string(this._currentCellIndex + 1));
		cellNumberContainer.addText(textElement);
		listStyle.cellNumber(cellNumberContainer,this.screenResolutionSize);
		cellInfoBlockContainer.addChild(cellNumberContainer);
		var celldotsLine = new cocktailCore.domElement.js.ImageDOMElement();
		listStyle.cellInfoBlockLine(celldotsLine);
		cellInfoBlockContainer.addChild(celldotsLine);
		celldotsLine.load("images/dotsLine.png");
		var celldotsLine1 = new cocktailCore.domElement.js.ImageDOMElement();
		listStyle.cellInfoBlockImage(celldotsLine1,this.screenResolutionSize);
		cellInfoBlockContainer.addChild(celldotsLine1);
		celldotsLine1.load("images/bubble.png");
		if(cellData.commentCount != "" && cellData.commentCount != null) {
			var cellCommentCountContainer = Utils.getContainer();
			var textElement1 = new cocktailCore.textElement.js.TextElement(cellData.commentCount);
			cellCommentCountContainer.addText(textElement1);
			listStyle.cellCommentCount(cellCommentCountContainer,this.screenResolutionSize);
			cellInfoBlockContainer.addChild(cellCommentCountContainer);
		}
		if(cellData.thumbnail != "" && cellData.thumbnail != null) {
			var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
			listStyle.cellThumbnail(cellImage);
			cellContent.push(cellImage);
			cellImage.load(cellData.thumbnail);
		}
		var cellTextBlockContainer = Utils.getContainer();
		listStyle.cellTextBlock(cellTextBlockContainer);
		cellContent.push(cellTextBlockContainer);
		if(cellData.title != "" && cellData.title != null) {
			var cellTitleContainer = Utils.getContainer();
			var textElement1 = new cocktailCore.textElement.js.TextElement(cellData.title);
			cellTitleContainer.addText(textElement1);
			listStyle.cellTitle(cellTitleContainer,this.screenResolutionSize);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		if(cellData.comment != "" && cellData.comment != null) {
			var cellCommentContainer = Utils.getContainer();
			var textElement1 = new cocktailCore.textElement.js.TextElement(cellData.comment);
			cellCommentContainer.addText(textElement1);
			listStyle.cellComment(cellCommentContainer,this.screenResolutionSize);
			cellTextBlockContainer.addChild(cellCommentContainer);
		}
		if(this.screenResolutionSize == ScreenResolutionSize.large) {
			if(cellData.description != "" && cellData.description != null) {
				var textLength;
				if(this.screenResolutionSize == ScreenResolutionSize.normal) textLength = 95; else textLength = 200;
				var cellDescriptionContainer = Utils.getContainer();
				var shortenedText = cellData.description.substr(0,textLength) + "...";
				var textElement1 = new cocktailCore.textElement.js.TextElement(shortenedText);
				cellDescriptionContainer.addText(textElement1);
				listStyle.cellDescription(cellDescriptionContainer);
				cellTextBlockContainer.addChild(cellDescriptionContainer);
			}
		}
		var line = new cocktailCore.domElement.js.ImageDOMElement();
		listStyle.cellLine(line);
		cellContent.push(line);
		line.load("images/greyPixel.png");
		return cellContent;
	}
	,__class__: components.lists.ThumbTextList1
});
if(!cocktailCore.mouse.js) cocktailCore.mouse.js = {}
cocktailCore.mouse.js.Mouse = $hxClasses["cocktailCore.mouse.js.Mouse"] = function(nativeElement) {
	cocktailCore.mouse.abstract.AbstractMouse.call(this,nativeElement);
}
cocktailCore.mouse.js.Mouse.__name__ = ["cocktailCore","mouse","js","Mouse"];
cocktailCore.mouse.js.Mouse.__super__ = cocktailCore.mouse.abstract.AbstractMouse;
cocktailCore.mouse.js.Mouse.prototype = $extend(cocktailCore.mouse.abstract.AbstractMouse.prototype,{
	setOnMouseDown: function(value) {
		if(value == null) this._nativeElement.onmousedown = null; else this._nativeElement.onmousedown = this.onNativeMouseDown.$bind(this);
		return this._onMouseDown = value;
	}
	,setOnMouseUp: function(value) {
		if(value == null) this._nativeElement.onmouseup = null; else this._nativeElement.onmouseup = this.onNativeMouseUp.$bind(this);
		return this._onMouseUp = value;
	}
	,setOnMouseOver: function(value) {
		if(value == null) this._nativeElement.onmouseover = null; else this._nativeElement.onmouseover = this.onNativeMouseOver.$bind(this);
		return this._onMouseOver = value;
	}
	,setOnMouseOut: function(value) {
		if(value == null) this._nativeElement.onmouseout = null; else this._nativeElement.onmouseout = this.onNativeMouseOut.$bind(this);
		return this._onMouseOut = value;
	}
	,setOnMouseMove: function(value) {
		if(value == null) this._nativeElement.onmousemove = null; else this._nativeElement.onmousemove = this.onNativeMouseMove.$bind(this);
		return this._onMouseMove = value;
	}
	,setOnMouseDoubleClick: function(value) {
		if(value == null) this._nativeElement.ondblclick = null; else this._nativeElement.ondblclick = this.onNativeMouseDoubleClick.$bind(this);
		return this._onMouseDoubleClick = value;
	}
	,getMouseData: function(event) {
		var mousePosition = { localX : event.clientX, localY : event.clientY, globalX : event.screenX, globalY : event.screenY};
		var mouseEventData = { mousePosition : mousePosition, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
		return mouseEventData;
	}
	,__class__: cocktailCore.mouse.js.Mouse
});
var EReg = $hxClasses["EReg"] = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
}
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
var Xml = $hxClasses["Xml"] = function() {
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
{
	Xml.Element = "element";
	Xml.PCData = "pcdata";
	Xml.CData = "cdata";
	Xml.Comment = "comment";
	Xml.DocType = "doctype";
	Xml.Prolog = "prolog";
	Xml.Document = "document";
}
js.Lib.onerror = null;
components.lists.AppListStyle.cellWidth = 62;
components.lists.AppListStyle.cellHeight = 43;
cocktailCore.classInstance.abstract.AbstractClassInstance.SETTER_PREFIX = "set";
cocktailCore.classInstance.abstract.AbstractClassInstance.GETTER_PREFIX = "get";
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_NONE = "butt";
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_ROUND = "round";
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_SQUARE = "square";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_ROUND = "round";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_MITER = "miter";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_BEVEL = "bevel";
cocktailCore.domElement.js.GraphicDOMElement.CANVAS_PATTERN_REPEAT = "repeat";
cocktailCore.domElement.js.GraphicDOMElement.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
cocktail.resource.ResourceLoaderManager._isLoading = false;
Constants.headerHeight = 43;
Constants.footerHeight = 48;
ApplicationStructure.PAGE1_TITLE = "Silex Labs";
ApplicationStructure.PAGE2_TITLE = "amfPHP";
ApplicationStructure.PAGE3_TITLE = "Silex";
ApplicationStructure.PAGE4_TITLE = "Themes";
ApplicationStructure.PAGE5_TITLE = "Plugins";
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
WebApp.main()