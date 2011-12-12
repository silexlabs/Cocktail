$estr = function() { return js.Boot.__string_rec(this,''); }
if(typeof cocktailCore=='undefined') cocktailCore = {}
if(!cocktailCore.domElement) cocktailCore.domElement = {}
if(!cocktailCore.domElement["abstract"]) cocktailCore.domElement["abstract"] = {}
cocktailCore.domElement.abstract.AbstractDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	if(nativeElement != null) this.setNativeElement(nativeElement);
}
cocktailCore.domElement.abstract.AbstractDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractDOMElement"];
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._mouse = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseDown = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseUp = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseOver = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseOut = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseMove = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onMouseDoubleClick = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._keyboard = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onKeyDown = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.onKeyUp = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._nativeElement = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.nativeElement = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._parent = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.parent = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.x = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.globalX = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.y = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.globalY = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.width = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.height = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.offsetWidth = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.offsetHeight = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._style = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.style = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._registrationPoint = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.registrationPoint = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._matrix = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.matrix = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scaleX = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scaleY = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.translationX = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.translationY = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.rotation = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.alpha = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.isVisible = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.zIndex = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.init = function() {
	this._matrix = new cocktail.geom.Matrix();
	this._keyboard = new cocktailCore.keyboard.js.Keyboard();
	this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
	this._registrationPoint = cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top);
	this.initStyle();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.initStyle = function() {
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getParent = function() {
	return this._parent;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setParent = function(domElement) {
	this._parent = domElement;
	return this._parent;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setNativeElement = function(value) {
	this._nativeElement = value;
	this.init();
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getNativeElement = function() {
	return this._nativeElement;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setIsVisible = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getIsVisible = function() {
	return false;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getAlpha = function() {
	return 0;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setMatrix = function(matrix) {
	this._matrix = matrix;
	return this._matrix;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getMatrix = function() {
	return this._matrix;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.resetTransformations = function() {
	this._matrix.identity();
	this.setMatrix(this._matrix);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRegistrationPointValueAsPoint = function(registrationPoint) {
	var registrationPointPoint = { x : 0.0, y : 0.0};
	var $e = (registrationPoint);
	switch( $e[1] ) {
	case 1:
		var point = $e[2];
		registrationPointPoint = point;
		break;
	case 0:
		var registrationPointY = $e[3], registrationPointX = $e[2];
		switch( (registrationPointX)[1] ) {
		case 0:
			registrationPointPoint.x = 0;
			break;
		case 1:
			registrationPointPoint.x = this.getWidth() / 2;
			break;
		case 2:
			registrationPointPoint.x = this.getWidth();
			break;
		}
		switch( (registrationPointY)[1] ) {
		case 0:
			registrationPointPoint.y = 0;
			break;
		case 1:
			registrationPointPoint.y = this.getHeight() / 2;
			break;
		case 2:
			registrationPointPoint.y = this.getHeight();
			break;
		}
		break;
	}
	return registrationPointPoint;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.translate = function(x,y) {
	this._matrix.translate(x,y);
	this.setMatrix(this._matrix);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.rotate = function(angle,registrationPoint) {
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.rotate(angle,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scale = function(scaleX,scaleY,registrationPoint) {
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.scale(scaleX,scaleY,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.skew = function(skewX,skewY,registrationPoint) {
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.skew(skewX,skewY,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setTranslationX = function(translationX) {
	this._matrix.setTranslationX(translationX);
	this.setMatrix(this._matrix);
	return translationX;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getTranslationX = function() {
	return this._matrix.getTranslationX();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setTranslationY = function(translationY) {
	this._matrix.setTranslationY(translationY);
	this.setMatrix(this._matrix);
	return translationY;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getTranslationY = function() {
	return this._matrix.getTranslationY();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleX = function(scaleX) {
	this._matrix.setScaleX(scaleX,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	return scaleX;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleX = function() {
	return this._matrix.getScaleX();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleY = function(scaleY) {
	if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
	this._matrix.setScaleY(scaleY,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	return scaleY;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleY = function() {
	return this._matrix.getScaleY();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setRotation = function(angle) {
	if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
	this._matrix.setRotation(angle,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	return angle;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRotation = function() {
	return this._matrix.getRotation();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setRegistrationPoint = function(registrationPoint) {
	this._registrationPoint = registrationPoint;
	return this._registrationPoint;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRegistrationPoint = function() {
	return this._registrationPoint;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDown = function(value) {
	this._mouse.onMouseDown = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDown = function() {
	return this._mouse.onMouseDown;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseUp = function(value) {
	this._mouse.onMouseUp = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseUp = function() {
	return this._mouse.onMouseUp;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOver = function(value) {
	this._mouse.onMouseOver = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOver = function() {
	return this._mouse.onMouseOver;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOut = function(value) {
	this._mouse.onMouseOut = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOut = function() {
	return this._mouse.onMouseOut;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseMove = function(value) {
	this._mouse.onMouseMove = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseMove = function() {
	return this._mouse.onMouseMove;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDoubleClick = function(value) {
	this._mouse.onMouseDoubleClick = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDoubleClick = function() {
	return this._mouse.onMouseDoubleClick;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyDown = function(value) {
	this._keyboard.onKeyDown = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyDown = function() {
	return this._keyboard.onKeyDown;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyUp = function(value) {
	this._keyboard.onKeyUp = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyUp = function() {
	return this._keyboard.onKeyUp;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setField = function(propertyName,propertyValue) {
	this._nativeElement[propertyName] = propertyValue;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getField = function(propertyName) {
	return Reflect.field(this._nativeElement,propertyName);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setX = function(value) {
	this._style.setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getX = function() {
	return this._style.getNativeX(this);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setY = function(value) {
	this._style.setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getY = function() {
	return this._style.getNativeY(this);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setWidth = function(value) {
	this._style.setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getWidth = function() {
	return this._style.getNativeWidth(this);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setHeight = function(value) {
	this._style.setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getHeight = function() {
	return this._style.getNativeHeight(this);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOffsetWidth = function() {
	var computedStyle = this._style.getComputedStyle();
	return computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOffsetHeight = function() {
	var computedStyle = this._style.getComputedStyle();
	return computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setGlobalX = function(value) {
	var localX = value;
	if(this._parent != null) {
		var parentGlobalX = this._parent.getGlobalX();
		localX -= parentGlobalX;
	} else localX = 0;
	this.setX(localX);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalX = function() {
	var newGlobalX = this.getX();
	if(this._parent != null) {
		var parentDOMElement = this._parent;
		while(parentDOMElement != null) {
			newGlobalX += parentDOMElement.getX();
			parentDOMElement = parentDOMElement.getParent();
		}
	} else newGlobalX = 0;
	return newGlobalX;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setGlobalY = function(value) {
	var localY = value;
	if(this._parent != null) {
		var parentGlobalY = this._parent.getGlobalY();
		localY -= parentGlobalY;
	} else localY = 0;
	this.setY(localY);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalY = function() {
	var newGlobalY = this.getY();
	if(this._parent != null) {
		var parentDOMElement = this._parent;
		while(parentDOMElement != null) {
			newGlobalY += parentDOMElement.getY();
			parentDOMElement = parentDOMElement.getParent();
		}
	} else newGlobalY = 0;
	return newGlobalY;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setZIndex = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getZIndex = function() {
	return 0;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getStyle = function() {
	return this._style;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractDOMElement;
if(!cocktailCore.domElement.js) cocktailCore.domElement.js = {}
cocktailCore.domElement.js.DOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.DOMElement.__name__ = ["cocktailCore","domElement","js","DOMElement"];
cocktailCore.domElement.js.DOMElement.__super__ = cocktailCore.domElement.abstract.AbstractDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractDOMElement.prototype ) cocktailCore.domElement.js.DOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractDOMElement.prototype[k];
cocktailCore.domElement.js.DOMElement.prototype.setIsVisible = function(value) {
	if(value == true) this._nativeElement.style.visibility = "visible"; else this._nativeElement.style.visibility = "hidden";
	return value;
}
cocktailCore.domElement.js.DOMElement.prototype.getIsVisible = function() {
	if(this._nativeElement.style.visibility == "visible") return true; else return false;
}
cocktailCore.domElement.js.DOMElement.prototype.setAlpha = function(value) {
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha.call(this,value);
	this._nativeElement.style.opacity = value;
	return value;
}
cocktailCore.domElement.js.DOMElement.prototype.getAlpha = function() {
	return Std.parseFloat(this._nativeElement.style.opacity);
}
cocktailCore.domElement.js.DOMElement.prototype.setMatrix = function(matrix) {
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setMatrix.call(this,matrix);
	var matrixData = matrix.getData();
	var a = matrixData.a;
	a = a.toFixed(2);
	var b = matrixData.b;
	b = b.toFixed(2);
	var c = matrixData.c;
	c = c.toFixed(2);
	var d = matrixData.d;
	d = d.toFixed(2);
	var e = matrixData.e;
	e = e.toFixed(2);
	var f = matrixData.f;
	f = f.toFixed(2);
	var cssMatrixProperty = "matrix(" + a + "," + b + "," + c + "," + d + "," + e + "," + f + ")";
	if(this._nativeElement.style.transform != null) {
		this._nativeElement.style.transform = cssMatrixProperty;
		this._nativeElement.style.transformOrigin = "0 0";
	}
	if(this._nativeElement.style.MozTransform != null) {
		this._nativeElement.style.MozTransform = cssMatrixProperty;
		this._nativeElement.style.MozTransformOrigin = "0 0";
	} else if(this._nativeElement.style.WebkitTransform != null) {
		this._nativeElement.style.WebkitTransform = cssMatrixProperty;
		this._nativeElement.style.WebkitTransformOrigin = "0 0";
	} else if(this._nativeElement.style.OTransform != null) {
		this._nativeElement.style.OTransform = cssMatrixProperty;
		this._nativeElement.style.OTransform = "0 0";
	}
	return this._matrix;
}
cocktailCore.domElement.js.DOMElement.prototype.setZIndex = function(value) {
	if(value > this._parent.getChildren().length - 1) value = this._parent.getChildren().length - 1;
	var nativeParent = this._nativeElement.parentNode;
	var numChildren = nativeParent.childNodes.length;
	var oldIndex = this.getZIndex();
	var newIndex = value;
	var _g = 0;
	while(_g < numChildren) {
		var i = _g++;
		var currentChildren = nativeParent.childNodes[i];
		if(currentChildren.style != null) {
			var currentChildrenZIndex = currentChildren.style.zIndex;
			if(currentChildrenZIndex > oldIndex) {
				currentChildrenZIndex--;
				currentChildren.style.zIndex = currentChildrenZIndex;
			}
		}
	}
	var _g = 0;
	while(_g < numChildren) {
		var i = _g++;
		var currentChildren = nativeParent.childNodes[i];
		if(currentChildren.style != null) {
			var currentChildrenZIndex = currentChildren.style.zIndex;
			if(currentChildrenZIndex >= newIndex) {
				currentChildrenZIndex++;
				currentChildren.style.zIndex = currentChildrenZIndex;
			}
		}
	}
	this._nativeElement.style.zIndex = value;
	return value;
}
cocktailCore.domElement.js.DOMElement.prototype.getZIndex = function() {
	return this._nativeElement.style.zIndex;
}
cocktailCore.domElement.js.DOMElement.prototype.__class__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractEmbeddedDOMElement"];
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
for(var k in cocktailCore.domElement.js.DOMElement.prototype ) cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype[k] = cocktailCore.domElement.js.DOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype._intrinsicWidth = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.intrinsicWidth = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype._intrinsicHeight = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.intrinsicHeight = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype._intrinsicRatio = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.intrinsicRatio = null;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.initStyle = function() {
	this._style = new cocktailCore.style.js.EmbeddedStyle(this);
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setWidth = function(value) {
	this._intrinsicWidth = value;
	this._style.invalidate();
	return value;
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setHeight = function(value) {
	this._intrinsicHeight = value;
	this._style.invalidate();
	return value;
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicWidth = function() {
	return this._intrinsicWidth;
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicHeight = function() {
	return this._intrinsicHeight;
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicRatio = function() {
	return this._intrinsicRatio;
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
cocktailCore.domElement.js.EmbeddedDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.EmbeddedDOMElement.__name__ = ["cocktailCore","domElement","js","EmbeddedDOMElement"];
cocktailCore.domElement.js.EmbeddedDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype ) cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype[k];
cocktailCore.domElement.js.EmbeddedDOMElement.prototype.setWidth = function(value) {
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setWidth.call(this,value);
	this._nativeElement.width = value;
	return value;
}
cocktailCore.domElement.js.EmbeddedDOMElement.prototype.setHeight = function(value) {
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setHeight.call(this,value);
	this._nativeElement.height = value;
	return value;
}
cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__class__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	this._imageLoader = new cocktailCore.resource.js.ImageLoader();
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,this._imageLoader.getNativeElement());
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractImageDOMElement"];
cocktailCore.domElement.abstract.AbstractImageDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
for(var k in cocktailCore.domElement.js.EmbeddedDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k] = cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoad = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onError = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._naturalWidth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.naturalWidth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._naturalHeight = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.naturalHeight = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._src = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.src = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._imageLoader = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._smooth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.smooth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.init = function() {
	cocktailCore.domElement.js.EmbeddedDOMElement.prototype.init.call(this);
	this.setSmooth(true);
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.load = function(url,allowCache) {
	if(allowCache == null) allowCache = true;
	this._imageLoader.load(url,$closure(this,"onLoadComplete"),$closure(this,"onLoadError"),allowCache);
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoadComplete = function(image) {
	this._style.invalidate();
	this.setSmooth(this.getSmooth());
	if(this.onLoad != null) this.onLoad();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoadError = function(message) {
	if(this.onError != null) this.onError(message);
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getSrc = function() {
	return this._src;
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSmooth = function(value) {
	this._smooth = value;
	return value;
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getSmooth = function() {
	return this._smooth;
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getNaturalWidth = function() {
	if(this._naturalWidth == null) return 0;
	return this._naturalWidth;
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getNaturalHeight = function() {
	if(this._naturalHeight == null) return 0;
	return this._naturalHeight;
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
if(!cocktailCore.viewport) cocktailCore.viewport = {}
if(!cocktailCore.viewport["abstract"]) cocktailCore.viewport["abstract"] = {}
cocktailCore.viewport.abstract.AbstractViewport = function(p) {
}
cocktailCore.viewport.abstract.AbstractViewport.__name__ = ["cocktailCore","viewport","abstract","AbstractViewport"];
cocktailCore.viewport.abstract.AbstractViewport.prototype.onResize = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype.onOrientationChange = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype.width = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype.height = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype.orientation = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype._lastOrientationObserved = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype._addResizeEvent = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._removeResizeEvent = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._addOrientationChangeEvent = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._removeOrientationChangeEvent = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._getWidth = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
	return -1;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._getHeight = function() {
	throw "this function is virtual, it is supposed to be implemented in the derived class";
	return -1;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._getOrientation = function() {
	if(this._getHeight() > this._getWidth()) return cocktail.viewport.OrientationValue.vertical; else return cocktail.viewport.OrientationValue.horizontal;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._onResizeCallback = function(e) {
	if(this._getOnResize() != null) (this._getOnResize())();
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._onOrientationChangeCallback = function(e) {
	if(this._getOnOrientationChange() != null && this._lastOrientationObserved != this._getOrientation()) {
		this._lastOrientationObserved = this._getOrientation();
		(this._getOnOrientationChange())();
	}
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._onResize = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype._getOnResize = function() {
	return this._onResize;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._setOnResize = function(callbackFunction) {
	if(this._onResize == null && callbackFunction != null) this._addResizeEvent(); else if(this._onResize != null && callbackFunction == null) this._removeResizeEvent();
	this._onResize = callbackFunction;
	return this._onResize;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._onOrientationChange = null;
cocktailCore.viewport.abstract.AbstractViewport.prototype._getOnOrientationChange = function() {
	return this._onOrientationChange;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype._setOnOrientationChange = function(callbackFunction) {
	this._lastOrientationObserved = this._getOrientation();
	if(this._onOrientationChange == null && callbackFunction != null) this._addOrientationChangeEvent(); else if(this._onOrientationChange != null && callbackFunction == null) this._removeOrientationChangeEvent();
	this._onOrientationChange = callbackFunction;
	return this._onOrientationChange;
}
cocktailCore.viewport.abstract.AbstractViewport.prototype.__class__ = cocktailCore.viewport.abstract.AbstractViewport;
if(!cocktailCore.viewport.js) cocktailCore.viewport.js = {}
cocktailCore.viewport.js.Viewport = function(p) {
	if( p === $_ ) return;
	cocktailCore.viewport.abstract.AbstractViewport.call(this);
}
cocktailCore.viewport.js.Viewport.__name__ = ["cocktailCore","viewport","js","Viewport"];
cocktailCore.viewport.js.Viewport.__super__ = cocktailCore.viewport.abstract.AbstractViewport;
for(var k in cocktailCore.viewport.abstract.AbstractViewport.prototype ) cocktailCore.viewport.js.Viewport.prototype[k] = cocktailCore.viewport.abstract.AbstractViewport.prototype[k];
cocktailCore.viewport.js.Viewport.prototype._addResizeEvent = function() {
	js.Lib.window.addEventListener("resize",$closure(this,"_onResizeCallback"),false);
}
cocktailCore.viewport.js.Viewport.prototype._removeResizeEvent = function() {
	js.Lib.window.removeEventListener("resize",$closure(this,"_onResizeCallback"),false);
}
cocktailCore.viewport.js.Viewport.prototype._addOrientationChangeEvent = function() {
	js.Lib.window.addEventListener("resize",$closure(this,"_onOrientationChangeCallback"),false);
}
cocktailCore.viewport.js.Viewport.prototype._removeOrientationChangeEvent = function() {
	js.Lib.window.removeEventListener("resize",$closure(this,"_onOrientationChangeCallback"),false);
}
cocktailCore.viewport.js.Viewport.prototype._getWidth = function() {
	return js.Lib.window.innerWidth;
}
cocktailCore.viewport.js.Viewport.prototype._getHeight = function() {
	return js.Lib.window.innerHeight;
}
cocktailCore.viewport.js.Viewport.prototype.__class__ = cocktailCore.viewport.js.Viewport;
if(!cocktailCore.style) cocktailCore.style = {}
if(!cocktailCore.style["abstract"]) cocktailCore.style["abstract"] = {}
cocktailCore.style.abstract.AbstractStyle = function(domElement) {
	if( domElement === $_ ) return;
	this._domElement = domElement;
	this._isInvalid = true;
	this.initDefaultStyleValues();
}
cocktailCore.style.abstract.AbstractStyle.__name__ = ["cocktailCore","style","abstract","AbstractStyle"];
cocktailCore.style.abstract.AbstractStyle.getDefaultStyle = function() {
	return { fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], color : cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black)};
}
cocktailCore.style.abstract.AbstractStyle.prototype._marginLeft = null;
cocktailCore.style.abstract.AbstractStyle.prototype.marginLeft = null;
cocktailCore.style.abstract.AbstractStyle.prototype._marginRight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.marginRight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._marginTop = null;
cocktailCore.style.abstract.AbstractStyle.prototype.marginTop = null;
cocktailCore.style.abstract.AbstractStyle.prototype._marginBottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype.marginBottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype._paddingLeft = null;
cocktailCore.style.abstract.AbstractStyle.prototype.paddingLeft = null;
cocktailCore.style.abstract.AbstractStyle.prototype._paddingRight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.paddingRight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._paddingTop = null;
cocktailCore.style.abstract.AbstractStyle.prototype.paddingTop = null;
cocktailCore.style.abstract.AbstractStyle.prototype._paddingBottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype.paddingBottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype._display = null;
cocktailCore.style.abstract.AbstractStyle.prototype.display = null;
cocktailCore.style.abstract.AbstractStyle.prototype._position = null;
cocktailCore.style.abstract.AbstractStyle.prototype.position = null;
cocktailCore.style.abstract.AbstractStyle.prototype._width = null;
cocktailCore.style.abstract.AbstractStyle.prototype.width = null;
cocktailCore.style.abstract.AbstractStyle.prototype._height = null;
cocktailCore.style.abstract.AbstractStyle.prototype.height = null;
cocktailCore.style.abstract.AbstractStyle.prototype._minHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.minHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._maxHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.maxHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._minWidth = null;
cocktailCore.style.abstract.AbstractStyle.prototype.minWidth = null;
cocktailCore.style.abstract.AbstractStyle.prototype._maxWidth = null;
cocktailCore.style.abstract.AbstractStyle.prototype.maxWidth = null;
cocktailCore.style.abstract.AbstractStyle.prototype._top = null;
cocktailCore.style.abstract.AbstractStyle.prototype.top = null;
cocktailCore.style.abstract.AbstractStyle.prototype._left = null;
cocktailCore.style.abstract.AbstractStyle.prototype.left = null;
cocktailCore.style.abstract.AbstractStyle.prototype._bottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype.bottom = null;
cocktailCore.style.abstract.AbstractStyle.prototype._right = null;
cocktailCore.style.abstract.AbstractStyle.prototype.right = null;
cocktailCore.style.abstract.AbstractStyle.prototype._verticalAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype.verticalAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype._float = null;
cocktailCore.style.abstract.AbstractStyle.prototype["float"] = null;
cocktailCore.style.abstract.AbstractStyle.prototype._clear = null;
cocktailCore.style.abstract.AbstractStyle.prototype.clear = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontSize = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontSize = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontWeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontWeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontFamily = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontFamily = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontVariant = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontVariant = null;
cocktailCore.style.abstract.AbstractStyle.prototype._color = null;
cocktailCore.style.abstract.AbstractStyle.prototype.color = null;
cocktailCore.style.abstract.AbstractStyle.prototype._lineHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype.lineHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._textTransform = null;
cocktailCore.style.abstract.AbstractStyle.prototype.textTransform = null;
cocktailCore.style.abstract.AbstractStyle.prototype._letterSpacing = null;
cocktailCore.style.abstract.AbstractStyle.prototype.letterSpacing = null;
cocktailCore.style.abstract.AbstractStyle.prototype._wordSpacing = null;
cocktailCore.style.abstract.AbstractStyle.prototype.wordSpacing = null;
cocktailCore.style.abstract.AbstractStyle.prototype._whiteSpace = null;
cocktailCore.style.abstract.AbstractStyle.prototype.whiteSpace = null;
cocktailCore.style.abstract.AbstractStyle.prototype._textAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype.textAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype._textIndent = null;
cocktailCore.style.abstract.AbstractStyle.prototype.textIndent = null;
cocktailCore.style.abstract.AbstractStyle.prototype._computedStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype.computedStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype._domElement = null;
cocktailCore.style.abstract.AbstractStyle.prototype.domElement = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontMetrics = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontMetrics = null;
cocktailCore.style.abstract.AbstractStyle.prototype._isInvalid = null;
cocktailCore.style.abstract.AbstractStyle.prototype.initDefaultStyleValues = function() {
	this._width = cocktail.style.DimensionStyleValue.auto;
	this._height = cocktail.style.DimensionStyleValue.auto;
	this._minWidth = cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._maxWidth = cocktail.style.ConstrainedDimensionStyleValue.none;
	this._minHeight = cocktail.style.ConstrainedDimensionStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._maxHeight = cocktail.style.ConstrainedDimensionStyleValue.none;
	this._marginTop = cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._marginBottom = cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._marginLeft = cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._marginRight = cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._paddingTop = cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._paddingBottom = cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._paddingLeft = cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._paddingRight = cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._lineHeight = cocktail.style.LineHeightStyleValue.normal;
	this._verticalAlign = cocktail.style.VerticalAlignStyleValue.baseline;
	this._display = cocktail.style.DisplayStyleValue.inlineStyle;
	this._position = cocktail.style.PositionStyleValue.staticStyle;
	this._top = cocktail.style.PositionOffsetStyleValue.auto;
	this._bottom = cocktail.style.PositionOffsetStyleValue.auto;
	this._left = cocktail.style.PositionOffsetStyleValue.auto;
	this._right = cocktail.style.PositionOffsetStyleValue.auto;
	this._float = cocktail.style.FloatStyleValue.none;
	this._clear = cocktail.style.ClearStyleValue.none;
	this._fontStyle = cocktail.style.FontStyleStyleValue.normal;
	this._fontVariant = cocktail.style.FontVariantStyleValue.normal;
	this._fontWeight = cocktail.style.FontWeightStyleValue.normal;
	this._fontSize = cocktail.style.FontSizeStyleValue.absoluteSize(cocktail.unit.FontSizeAbsoluteSizeValue.medium);
	this._textIndent = cocktail.style.TextIndentStyleValue.length(cocktail.unit.LengthValue.px(0));
	this._textAlign = cocktail.style.TextAlignStyleValue.left;
	this._letterSpacing = cocktail.style.LetterSpacingStyleValue.normal;
	this._wordSpacing = cocktail.style.WordSpacingStyleValue.normal;
	this._textTransform = cocktail.style.TextTransformStyleValue.none;
	this._whiteSpace = cocktail.style.WhiteSpaceStyleValue.normal;
	this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
}
cocktailCore.style.abstract.AbstractStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.flow = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	if(this.isNotDisplayed() == true) {
		this._domElement.setIsVisible(false);
		return;
	} else this._domElement.setIsVisible(true);
	if(this.isClear() == true) formatingContext.clearFloat(this._computedStyle.clear,this.isFloat());
	this.computeDOMElement(containingDOMElementData,viewportData,lastPositionedDOMElementData.data,containingDOMElementFontMetricsData);
	this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
	this.setNativeHeight(this._domElement,this._computedStyle.height);
	this.setNativeWidth(this._domElement,this._computedStyle.width);
	this._isInvalid = false;
}
cocktailCore.style.abstract.AbstractStyle.prototype.positionElement = function(lastPositionedDOMElementData,viewportData,staticPosition) {
	var positioner;
	if(this.isRelativePositioned() == true) {
		positioner = new cocktailCore.style.positioner.RelativePositioner();
		positioner.position(this._domElement,lastPositionedDOMElementData,staticPosition);
	} else {
		switch( (this._domElement.getStyle().getComputedStyle().position)[1] ) {
		case 3:
			positioner = new cocktailCore.style.positioner.FixedPositioner();
			positioner.position(this._domElement,viewportData,staticPosition);
			break;
		case 2:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
			positioner.position(this._domElement,lastPositionedDOMElementData,staticPosition);
			break;
		default:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
		}
	}
}
cocktailCore.style.abstract.AbstractStyle.prototype.scheduleLayout = function(containingDOMElementData,lastPositionedDOMElementData,viewportData) {
	var layoutDelegate = $closure(this,"layout");
	haxe.Timer.delay(function() {
		layoutDelegate(containingDOMElementData,lastPositionedDOMElementData,viewportData,null);
	},1);
}
cocktailCore.style.abstract.AbstractStyle.prototype.flowChildren = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
}
cocktailCore.style.abstract.AbstractStyle.prototype.insertDOMElement = function(formattingContext,lastPositionedDOMElementData,viewportData) {
	if(this.isFloat() == true) formattingContext.insertFloat(this._domElement); else if(this.isPositioned() == false) this.insertInFlowDOMElement(formattingContext); else {
		var x = formattingContext.getFlowData().x;
		var y = formattingContext.getFlowData().y;
		var staticPosition = { x : x, y : y};
		if(this.isRelativePositioned() == true) {
			this.insertInFlowDOMElement(formattingContext);
			this.positionElement(lastPositionedDOMElementData.data,viewportData,staticPosition);
		} else {
			var positionedDOMElementData = { staticPosition : staticPosition, style : this};
			lastPositionedDOMElementData.children.push(positionedDOMElementData);
		}
	}
}
cocktailCore.style.abstract.AbstractStyle.prototype.insertInFlowDOMElement = function(formattingContext) {
	formattingContext.insert(this._domElement);
}
cocktailCore.style.abstract.AbstractStyle.prototype.invalidate = function() {
	if(this._isInvalid == false) {
		this._isInvalid = true;
		if(this._domElement.getParent() != null) {
			if(this.isParentInvalid() == true) this._domElement.getParent().getStyle().invalidate(); else {
				var parentStyle = this._domElement.getParent().getStyle();
				var containingDOMElementData = parentStyle.getContainerDOMElementData();
				var viewPort = new cocktailCore.viewport.js.Viewport();
				var viewPortData = { globalX : 0, globalY : 0, isHeightAuto : false, isWidthAuto : false, width : viewPort._getWidth(), height : viewPort._getHeight()};
				var lastPositionedDOMElementData = { children : new Array(), data : viewPortData};
				this.scheduleLayout(containingDOMElementData,lastPositionedDOMElementData,viewPortData);
			}
		}
	}
}
cocktailCore.style.abstract.AbstractStyle.prototype.invalidateText = function() {
	this._fontMetrics = null;
	this.invalidate();
}
cocktailCore.style.abstract.AbstractStyle.prototype.invalidatePositionOffset = function() {
	if(this.getPosition() != cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
}
cocktailCore.style.abstract.AbstractStyle.prototype.invalidateMargin = function() {
	if(this.getPosition() == cocktail.style.PositionStyleValue.relative || this.getPosition() == cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
}
cocktailCore.style.abstract.AbstractStyle.prototype.isParentInvalid = function() {
	var ret = true;
	if(this.isPositioned() == true && this.isRelativePositioned() == false) ret = false;
	return ret;
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeDOMElement = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData) {
	this.computeDisplayStyles();
	this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
	this.computeBoxModelStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData);
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeDisplayStyles = function() {
	cocktailCore.style.computer.DisplayStylesComputer.compute(this);
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeTextAndFontStyles = function(containingDOMElementData,containingDOMElementFontMetricsData) {
	cocktailCore.style.computer.FontAndTextStylesComputer.compute(this,containingDOMElementData,containingDOMElementFontMetricsData);
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeBoxModelStyles = function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
	var boxComputer = this.getBoxStylesComputer();
	var containingBlockDimensions = this.getContainingDOMElementData(containingDOMElementData,viewportData,lastPositionedDOMElementData);
	boxComputer.measure(this,containingBlockDimensions);
}
cocktailCore.style.abstract.AbstractStyle.prototype.getBoxStylesComputer = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.getContainingDOMElementData = function(containingDOMElementData,viewportData,lastPositionedDOMElementData) {
	var containingBlockDimensions;
	if(this.isPositioned() == true) {
		if(this._computedStyle.position == cocktail.style.PositionStyleValue.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto, globalX : viewportData.globalX, globalY : viewportData.globalY}; else if(this._computedStyle.position == cocktail.style.PositionStyleValue.absolute) containingBlockDimensions = { width : lastPositionedDOMElementData.width, height : lastPositionedDOMElementData.height, isHeightAuto : lastPositionedDOMElementData.isHeightAuto, isWidthAuto : lastPositionedDOMElementData.isWidthAuto, globalX : lastPositionedDOMElementData.globalX, globalY : lastPositionedDOMElementData.globalY}; else containingBlockDimensions = containingDOMElementData;
	} else containingBlockDimensions = containingDOMElementData;
	return containingBlockDimensions;
}
cocktailCore.style.abstract.AbstractStyle.prototype.isEmbedded = function() {
	return false;
}
cocktailCore.style.abstract.AbstractStyle.prototype.isFloat = function() {
	var ret = false;
	switch( (this._computedStyle["float"])[1] ) {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isClear = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isNotDisplayed = function() {
	return this._computedStyle.display == cocktail.style.DisplayStyleValue.none;
}
cocktailCore.style.abstract.AbstractStyle.prototype.isInline = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isPositioned = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isRelativePositioned = function() {
	return this._computedStyle.position == cocktail.style.PositionStyleValue.relative;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeX = function(domElement,x) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeY = function(domElement,y) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeWidth = function(domElement,width) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeHeight = function(domElement,height) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeX = function(domElement) {
	return 0;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeY = function(domElement) {
	return 0;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeWidth = function(domElement) {
	return 0;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeHeight = function(domElement) {
	return 0;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontMetricsData = function() {
	return this._fontMetrics;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getComputedStyle = function() {
	return this._computedStyle;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setComputedStyle = function(value) {
	return this._computedStyle = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getDOMElement = function() {
	return this._domElement;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWidth = function(value) {
	this.invalidate();
	return this._width = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginLeft = function(value) {
	this.invalidateMargin();
	return this._marginLeft = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginRight = function(value) {
	this.invalidateMargin();
	return this._marginRight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginTop = function(value) {
	this.invalidateMargin();
	return this._marginTop = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginBottom = function(value) {
	this.invalidateMargin();
	return this._marginBottom = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingLeft = function(value) {
	this.invalidate();
	return this._paddingLeft = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingRight = function(value) {
	this.invalidate();
	return this._paddingRight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingTop = function(value) {
	this.invalidate();
	return this._paddingTop = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingBottom = function(value) {
	this.invalidate();
	return this._paddingBottom = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setDisplay = function(value) {
	this.invalidate();
	return this._display = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPosition = function(value) {
	this.invalidate();
	return this._position = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setHeight = function(value) {
	this.invalidate();
	return this._height = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMinHeight = function(value) {
	this.invalidate();
	return this._minHeight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMaxHeight = function(value) {
	this.invalidate();
	return this._maxHeight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMinWidth = function(value) {
	this.invalidate();
	return this._minWidth = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMaxWidth = function(value) {
	this.invalidate();
	return this._maxWidth = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTop = function(value) {
	this.invalidatePositionOffset();
	return this._top = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLeft = function(value) {
	this.invalidatePositionOffset();
	return this._left = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setBottom = function(value) {
	this.invalidatePositionOffset();
	return this._bottom = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setRight = function(value) {
	this.invalidatePositionOffset();
	return this._right = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFloat = function(value) {
	this.invalidate();
	return this._float = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setClear = function(value) {
	this.invalidate();
	return this._clear = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontSize = function(value) {
	this.invalidateText();
	return this._fontSize = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontWeight = function(value) {
	this.invalidateText();
	return this._fontWeight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontStyle = function(value) {
	this.invalidateText();
	return this._fontStyle = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontFamily = function(value) {
	this.invalidateText();
	return this._fontFamily = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontVariant = function(value) {
	this.invalidateText();
	return this._fontVariant = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextTransform = function(value) {
	this.invalidateText();
	return this._textTransform = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLetterSpacing = function(value) {
	this.invalidateText();
	return this._letterSpacing = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWordSpacing = function(value) {
	this.invalidate();
	return this._wordSpacing = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLineHeight = function(value) {
	this.invalidate();
	return this._lineHeight = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setVerticalAlign = function(value) {
	this.invalidate();
	return this._verticalAlign = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextIndent = function(value) {
	this.invalidate();
	return this._textIndent = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWhiteSpace = function(value) {
	this.invalidate();
	return this._whiteSpace = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextAlign = function(value) {
	this.invalidate();
	return this._textAlign = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginLeft = function() {
	return this._marginLeft;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginRight = function() {
	return this._marginRight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginTop = function() {
	return this._marginTop;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginBottom = function() {
	return this._marginBottom;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingLeft = function() {
	return this._paddingLeft;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingRight = function() {
	return this._paddingRight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingTop = function() {
	return this._paddingTop;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingBottom = function() {
	return this._paddingBottom;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getDisplay = function() {
	return this._display;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPosition = function() {
	return this._position;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWidth = function() {
	return this._width;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getHeight = function() {
	return this._height;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMinHeight = function() {
	return this._minHeight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMaxHeight = function() {
	return this._maxHeight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMinWidth = function() {
	return this._minWidth;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMaxWidth = function() {
	return this._maxWidth;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTop = function() {
	return this._top;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLeft = function() {
	return this._left;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getBottom = function() {
	return this._bottom;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getRight = function() {
	return this._right;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFloat = function() {
	return this._float;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getClear = function() {
	return this._clear;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontSize = function() {
	return this._fontSize;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontWeight = function() {
	return this._fontWeight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontStyle = function() {
	return this._fontStyle;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontFamily = function() {
	return this._fontFamily;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontVariant = function() {
	return this._fontVariant;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextTransform = function() {
	return this._textTransform;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLetterSpacing = function() {
	return this._letterSpacing;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setColor = function(value) {
	return this._color = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getColor = function() {
	return this._color;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWordSpacing = function() {
	return this._wordSpacing;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLineHeight = function() {
	return this._lineHeight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getVerticalAlign = function() {
	return this._verticalAlign;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextIndent = function() {
	return this._textIndent;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWhiteSpace = function() {
	return this._whiteSpace;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextAlign = function() {
	return this._textAlign;
}
cocktailCore.style.abstract.AbstractStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractStyle;
if(!cocktailCore.style.js) cocktailCore.style.js = {}
cocktailCore.style.js.Style = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.abstract.AbstractStyle.call(this,domElement);
}
cocktailCore.style.js.Style.__name__ = ["cocktailCore","style","js","Style"];
cocktailCore.style.js.Style.__super__ = cocktailCore.style.abstract.AbstractStyle;
for(var k in cocktailCore.style.abstract.AbstractStyle.prototype ) cocktailCore.style.js.Style.prototype[k] = cocktailCore.style.abstract.AbstractStyle.prototype[k];
cocktailCore.style.js.Style.prototype.getCSSDisplay = function(value) {
	var displayValue;
	switch( (value)[1] ) {
	case 0:
		displayValue = "block";
		break;
	case 2:
		displayValue = "inline";
		break;
	case 1:
		displayValue = "inline-block";
		break;
	case 3:
		displayValue = "none";
		break;
	}
	return displayValue;
}
cocktailCore.style.js.Style.prototype.getCSSFloat = function(value) {
	var floatValue;
	switch( (value)[1] ) {
	case 0:
		floatValue = "left";
		break;
	case 1:
		floatValue = "right";
		break;
	case 2:
		floatValue = "none";
		break;
	}
	return floatValue;
}
cocktailCore.style.js.Style.prototype.getCSSClear = function(value) {
	var clearValue;
	switch( (value)[1] ) {
	case 1:
		clearValue = "left";
		break;
	case 2:
		clearValue = "right";
		break;
	case 3:
		clearValue = "both";
		break;
	case 0:
		clearValue = "none";
		break;
	}
	return clearValue;
}
cocktailCore.style.js.Style.prototype.getCSSPosition = function(value) {
	var positionValue;
	switch( (value)[1] ) {
	case 0:
		positionValue = "static";
		break;
	case 1:
		positionValue = "relative";
		break;
	case 2:
		positionValue = "absolute";
		break;
	case 3:
		positionValue = "fixed";
		break;
	}
	return positionValue;
}
cocktailCore.style.js.Style.prototype.getCSSMargin = function(value) {
	var marginValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		marginValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percentValue = $e[2];
		marginValue = this.getCSSPercentValue(Std.string(percentValue));
		break;
	case 2:
		marginValue = "auto";
		break;
	}
	return marginValue;
}
cocktailCore.style.js.Style.prototype.getCSSPadding = function(value) {
	var paddingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		paddingValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percentValue = $e[2];
		paddingValue = this.getCSSPercentValue(Std.string(percentValue));
		break;
	}
	return paddingValue;
}
cocktailCore.style.js.Style.prototype.getCSSDimension = function(value) {
	var dimensionValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		dimensionValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percentValue = $e[2];
		dimensionValue = this.getCSSPercentValue(Std.string(percentValue));
		break;
	case 2:
		dimensionValue = "auto";
		break;
	}
	return dimensionValue;
}
cocktailCore.style.js.Style.prototype.getCSSPositionOffset = function(value) {
	var positionOffsetValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		positionOffsetValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percentValue = $e[2];
		positionOffsetValue = this.getCSSPercentValue(Std.string(percentValue));
		break;
	case 2:
		positionOffsetValue = "auto";
		break;
	}
	return positionOffsetValue;
}
cocktailCore.style.js.Style.prototype.getCSSConstrainedDimension = function(value) {
	var constrainedValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		constrainedValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percentValue = $e[2];
		constrainedValue = this.getCSSPercentValue(Std.string(percentValue));
		break;
	case 2:
		constrainedValue = "none";
		break;
	}
	return constrainedValue;
}
cocktailCore.style.js.Style.prototype.getCSSVerticalAlign = function(value) {
	var verticalAlignValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		verticalAlignValue = "baseline";
		break;
	case 5:
		verticalAlignValue = "middle";
		break;
	case 1:
		verticalAlignValue = "sub";
		break;
	case 2:
		verticalAlignValue = "super";
		break;
	case 4:
		verticalAlignValue = "text-top";
		break;
	case 7:
		verticalAlignValue = "text-bottom";
		break;
	case 3:
		verticalAlignValue = "top";
		break;
	case 6:
		verticalAlignValue = "bottom";
		break;
	case 8:
		var value1 = $e[2];
		verticalAlignValue = this.getCSSPercentValue(Std.string(value1));
		break;
	case 9:
		var value1 = $e[2];
		verticalAlignValue = this.getCSSLengthValue(value1);
		break;
	}
	return verticalAlignValue;
}
cocktailCore.style.js.Style.prototype.getCSSLineHeight = function(value) {
	var lineHeightValue;
	var $e = (value);
	switch( $e[1] ) {
	case 2:
		var unit = $e[2];
		lineHeightValue = this.getCSSLengthValue(unit);
		break;
	case 0:
		lineHeightValue = "normal";
		break;
	case 3:
		var value1 = $e[2];
		lineHeightValue = this.getCSSPercentValue(Std.string(value1));
		break;
	case 1:
		var value1 = $e[2];
		lineHeightValue = Std.string(value1);
		break;
	}
	return lineHeightValue;
}
cocktailCore.style.js.Style.prototype.getCSSFontSize = function(value) {
	var fontValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var unit = $e[2];
		fontValue = this.getCSSLengthValue(unit);
		break;
	case 1:
		var percent = $e[2];
		fontValue = this.getCSSPercentValue(Std.string(percent));
		break;
	case 2:
		var value1 = $e[2];
		switch( (value1)[1] ) {
		case 0:
			fontValue = "xx-small";
			break;
		case 1:
			fontValue = "x-small";
			break;
		case 2:
			fontValue = "small";
			break;
		case 3:
			fontValue = "medium";
			break;
		case 4:
			fontValue = "large";
			break;
		case 5:
			fontValue = "x-large";
			break;
		case 6:
			fontValue = "xx-large";
			break;
		}
		break;
	case 3:
		var value1 = $e[2];
		switch( (value1)[1] ) {
		case 0:
			fontValue = "larger";
			break;
		case 1:
			fontValue = "smaller";
			break;
		}
		break;
	}
	return fontValue;
}
cocktailCore.style.js.Style.prototype.getCSSFontWeight = function(value) {
	var fontWeightValue;
	switch( (value)[1] ) {
	case 0:
		fontWeightValue = "normal";
		break;
	case 1:
		fontWeightValue = "bold";
		break;
	}
	return fontWeightValue;
}
cocktailCore.style.js.Style.prototype.getCSSFontStyle = function(value) {
	var fontStyleValue;
	switch( (value)[1] ) {
	case 0:
		fontStyleValue = "normal";
		break;
	case 1:
		fontStyleValue = "italic";
		break;
	}
	return fontStyleValue;
}
cocktailCore.style.js.Style.prototype.getCSSFontVariant = function(value) {
	var fontVariantValue;
	switch( (value)[1] ) {
	case 0:
		fontVariantValue = "normal";
		break;
	case 1:
		fontVariantValue = "small-caps";
		break;
	}
	return fontVariantValue;
}
cocktailCore.style.js.Style.prototype.getCSSFontFamily = function(value) {
	var fontFamilyValue = "";
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
		fontFamilyValue += fontName;
		if(i < value.length - 1) fontFamilyValue += ",";
	}
	return fontFamilyValue;
}
cocktailCore.style.js.Style.prototype.getCSSTextAlign = function(value) {
	var textAlignValue;
	switch( (value)[1] ) {
	case 0:
		textAlignValue = "left";
		break;
	case 1:
		textAlignValue = "right";
		break;
	case 2:
		textAlignValue = "center";
		break;
	case 3:
		textAlignValue = "justify";
		break;
	}
	return textAlignValue;
}
cocktailCore.style.js.Style.prototype.getCSSWhiteSpace = function(value) {
	var whiteSpaceValue;
	switch( (value)[1] ) {
	case 0:
		whiteSpaceValue = "normal";
		break;
	case 1:
		whiteSpaceValue = "pre";
		break;
	case 2:
		whiteSpaceValue = "nowrap";
		break;
	case 3:
		whiteSpaceValue = "pre-wrap";
		break;
	case 4:
		whiteSpaceValue = "pre-line";
		break;
	}
	return whiteSpaceValue;
}
cocktailCore.style.js.Style.prototype.getCSSTextTransform = function(value) {
	var textTransformValue;
	switch( (value)[1] ) {
	case 3:
		textTransformValue = "none";
		break;
	case 1:
		textTransformValue = "uppercase";
		break;
	case 2:
		textTransformValue = "lowercase";
		break;
	case 0:
		textTransformValue = "capitalize";
		break;
	}
	return textTransformValue;
}
cocktailCore.style.js.Style.prototype.getCSSTextIndent = function(value) {
	var textIndentValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		var value1 = $e[2];
		textIndentValue = this.getCSSLengthValue(value1);
		break;
	case 1:
		var value1 = $e[2];
		textIndentValue = this.getCSSPercentValue(Std.string(value1));
		break;
	}
	return textIndentValue;
}
cocktailCore.style.js.Style.prototype.getCSSLetterSpacing = function(value) {
	var letterSpacingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		letterSpacingValue = "normal";
		break;
	case 1:
		var unit = $e[2];
		letterSpacingValue = this.getCSSLengthValue(unit);
		break;
	}
	return letterSpacingValue;
}
cocktailCore.style.js.Style.prototype.getCSSWordSpacing = function(value) {
	var wordSpacingValue;
	var $e = (value);
	switch( $e[1] ) {
	case 0:
		wordSpacingValue = "normal";
		break;
	case 1:
		var unit = $e[2];
		wordSpacingValue = this.getCSSLengthValue(unit);
		break;
	}
	return wordSpacingValue;
}
cocktailCore.style.js.Style.prototype.getCSSColor = function(value) {
	var colorValue;
	var $e = (value);
	switch( $e[1] ) {
	case 1:
		var value1 = $e[2];
		colorValue = value1;
		break;
	case 0:
		var blue = $e[4], green = $e[3], red = $e[2];
		colorValue = "rgb(" + red + "," + green + "," + blue + ")";
		break;
	case 2:
		var value1 = $e[2];
		colorValue = this.getColorFromKeyword(value1);
		break;
	}
	return colorValue;
}
cocktailCore.style.js.Style.prototype.getCSSLengthValue = function(lengthValue) {
	var ret;
	var $e = (lengthValue);
	switch( $e[1] ) {
	case 0:
		var pixelValue = $e[2];
		ret = Std.string(pixelValue) + "px";
		break;
	case 3:
		var pointValue = $e[2];
		ret = Std.string(pointValue) + "pt";
		break;
	case 2:
		var milimetersValue = $e[2];
		ret = Std.string(milimetersValue) + "mm";
		break;
	case 4:
		var picasValue = $e[2];
		ret = Std.string(picasValue) + "pc";
		break;
	case 1:
		var centimetersValue = $e[2];
		ret = Std.string(centimetersValue) + "cm";
		break;
	case 5:
		var inchesValue = $e[2];
		ret = Std.string(inchesValue) + "in";
		break;
	case 6:
		var emValue = $e[2];
		ret = Std.string(emValue) + "em";
		break;
	case 7:
		var exValue = $e[2];
		ret = Std.string(exValue) + "ex";
		break;
	}
	return ret;
}
cocktailCore.style.js.Style.prototype.getCSSPercentValue = function(value) {
	return value + "%";
}
cocktailCore.style.js.Style.prototype.getColorFromKeyword = function(value) {
	var hexColor;
	switch( (value)[1] ) {
	case 0:
		hexColor = "aqua";
		break;
	case 1:
		hexColor = "black";
		break;
	case 2:
		hexColor = "blue";
		break;
	case 3:
		hexColor = "fuchsia";
		break;
	case 4:
		hexColor = "gray";
		break;
	case 5:
		hexColor = "green";
		break;
	case 6:
		hexColor = "lime";
		break;
	case 7:
		hexColor = "maroon";
		break;
	case 8:
		hexColor = "navy";
		break;
	case 9:
		hexColor = "olive";
		break;
	case 10:
		hexColor = "orange";
		break;
	case 11:
		hexColor = "purple";
		break;
	case 12:
		hexColor = "red";
		break;
	case 13:
		hexColor = "silver";
		break;
	case 14:
		hexColor = "teal";
		break;
	case 15:
		hexColor = "white";
		break;
	case 16:
		hexColor = "yellow";
		break;
	}
	return hexColor;
}
cocktailCore.style.js.Style.prototype.setVerticalAlign = function(value) {
	this._domElement.getNativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
	return this._verticalAlign = value;
}
cocktailCore.style.js.Style.prototype.setColor = function(value) {
	this._domElement.getNativeElement().style.color = this.getCSSColor(value);
	return this._color = value;
}
cocktailCore.style.js.Style.prototype.setWordSpacing = function(value) {
	this._domElement.getNativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
	return this._wordSpacing = value;
}
cocktailCore.style.js.Style.prototype.setLetterSpacing = function(value) {
	this._domElement.getNativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
	return this._letterSpacing = value;
}
cocktailCore.style.js.Style.prototype.setTextTransform = function(value) {
	this._domElement.getNativeElement().style.textTransform = this.getCSSTextTransform(value);
	return this._textTransform = value;
}
cocktailCore.style.js.Style.prototype.setFontVariant = function(value) {
	this._domElement.getNativeElement().style.fontVariant = this.getCSSFontVariant(value);
	return this._fontVariant = value;
}
cocktailCore.style.js.Style.prototype.setFontFamily = function(value) {
	this._domElement.getNativeElement().style.fontFamily = this.getCSSFontFamily(value);
	return this._fontFamily = value;
}
cocktailCore.style.js.Style.prototype.setFontWeight = function(value) {
	this._domElement.getNativeElement().style.fontWeight = this.getCSSFontWeight(value);
	return this._fontWeight = value;
}
cocktailCore.style.js.Style.prototype.setFontStyle = function(value) {
	this._domElement.getNativeElement().style.fontStyle = this.getCSSFontStyle(value);
	return this._fontStyle = value;
}
cocktailCore.style.js.Style.prototype.setFontSize = function(value) {
	this._domElement.getNativeElement().style.fontSize = this.getCSSFontSize(value);
	return this._fontSize = value;
}
cocktailCore.style.js.Style.prototype.setLineHeight = function(value) {
	this._domElement.getNativeElement().style.lineHeight = this.getCSSLineHeight(value);
	return this._lineHeight = value;
}
cocktailCore.style.js.Style.prototype.setMarginLeft = function(value) {
	this._domElement.getNativeElement().style.marginLeft = this.getCSSMargin(value);
	return this._marginLeft = value;
}
cocktailCore.style.js.Style.prototype.setMarginRight = function(value) {
	this._domElement.getNativeElement().style.marginRight = this.getCSSMargin(value);
	return this._marginRight = value;
}
cocktailCore.style.js.Style.prototype.setMarginTop = function(value) {
	this._domElement.getNativeElement().style.marginTop = this.getCSSMargin(value);
	return this._marginTop = value;
}
cocktailCore.style.js.Style.prototype.setMarginBottom = function(value) {
	this._domElement.getNativeElement().style.marginBottom = this.getCSSMargin(value);
	return this._marginBottom = value;
}
cocktailCore.style.js.Style.prototype.setPaddingLeft = function(value) {
	this._domElement.getNativeElement().style.paddingLeft = this.getCSSPadding(value);
	return this._paddingLeft = value;
}
cocktailCore.style.js.Style.prototype.setPaddingRight = function(value) {
	this._domElement.getNativeElement().style.paddingRight = this.getCSSPadding(value);
	return this._paddingRight = value;
}
cocktailCore.style.js.Style.prototype.setPaddingTop = function(value) {
	this._domElement.getNativeElement().style.paddingTop = this.getCSSPadding(value);
	return this._paddingTop = value;
}
cocktailCore.style.js.Style.prototype.setPaddingBottom = function(value) {
	this._domElement.getNativeElement().style.paddingBottom = this.getCSSPadding(value);
	return this._paddingBottom = value;
}
cocktailCore.style.js.Style.prototype.setDisplay = function(value) {
	this._domElement.getNativeElement().style.display = this.getCSSDisplay(value);
	return this._display = value;
}
cocktailCore.style.js.Style.prototype.setPosition = function(value) {
	this._domElement.getNativeElement().style.position = this.getCSSPosition(value);
	return this._position = value;
}
cocktailCore.style.js.Style.prototype.setWidth = function(value) {
	this._domElement.getNativeElement().style.width = this.getCSSDimension(value);
	return this._width = value;
}
cocktailCore.style.js.Style.prototype.setHeight = function(value) {
	this._domElement.getNativeElement().style.height = this.getCSSDimension(value);
	return this._height = value;
}
cocktailCore.style.js.Style.prototype.setMinHeight = function(value) {
	this._domElement.getNativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
	return this._minHeight = value;
}
cocktailCore.style.js.Style.prototype.setMaxHeight = function(value) {
	this._domElement.getNativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
	return this._maxHeight = value;
}
cocktailCore.style.js.Style.prototype.setMinWidth = function(value) {
	this._domElement.getNativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
	return this._minWidth = value;
}
cocktailCore.style.js.Style.prototype.setMaxWidth = function(value) {
	this._domElement.getNativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
	return this._maxWidth = value;
}
cocktailCore.style.js.Style.prototype.setTop = function(value) {
	this._domElement.getNativeElement().style.top = this.getCSSPositionOffset(value);
	return this._top = value;
}
cocktailCore.style.js.Style.prototype.setLeft = function(value) {
	this._domElement.getNativeElement().style.left = this.getCSSPositionOffset(value);
	return this._left = value;
}
cocktailCore.style.js.Style.prototype.setBottom = function(value) {
	this._domElement.getNativeElement().style.bottom = this.getCSSPositionOffset(value);
	return this._bottom = value;
}
cocktailCore.style.js.Style.prototype.setRight = function(value) {
	this._domElement.getNativeElement().style.right = this.getCSSPositionOffset(value);
	return this._right = value;
}
cocktailCore.style.js.Style.prototype.setTextIndent = function(value) {
	this._domElement.getNativeElement().style.textIndent = this.getCSSTextIndent(value);
	return this._textIndent = value;
}
cocktailCore.style.js.Style.prototype.setFloat = function(value) {
	this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
	return this._float = value;
}
cocktailCore.style.js.Style.prototype.setClear = function(value) {
	this._domElement.getNativeElement().style.clear = this.getCSSClear(value);
	return this._clear = value;
}
cocktailCore.style.js.Style.prototype.setWhiteSpace = function(value) {
	this._domElement.getNativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
	return this._whiteSpace = value;
}
cocktailCore.style.js.Style.prototype.setTextAlign = function(value) {
	this._domElement.getNativeElement().style.textAlign = this.getCSSTextAlign(value);
	return this._textAlign = value;
}
cocktailCore.style.js.Style.prototype.__class__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractContainerStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.js.Style.call(this,domElement);
}
cocktailCore.style.abstract.AbstractContainerStyle.__name__ = ["cocktailCore","style","abstract","AbstractContainerStyle"];
cocktailCore.style.abstract.AbstractContainerStyle.__super__ = cocktailCore.style.js.Style;
for(var k in cocktailCore.style.js.Style.prototype ) cocktailCore.style.abstract.AbstractContainerStyle.prototype[k] = cocktailCore.style.js.Style.prototype[k];
cocktailCore.style.abstract.AbstractContainerStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
	this.flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,null);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.flowChildren = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
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
	if(this.isPositioned() == true) childLastPositionedDOMElementData = { data : this.getContainerDOMElementData(), children : new Array()}; else childLastPositionedDOMElementData = lastPositionedDOMElementData;
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
	if(childrenFormattingContext != formatingContext) childrenFormattingContext.destroy();
	if(this._height == cocktail.style.DimensionStyleValue.auto) this._computedStyle.height = childrenFormattingContext.getFlowData().totalHeight;
	if(this._width == cocktail.style.DimensionStyleValue.auto) this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData.width,childrenFormattingContext.getFlowData().maxWidth);
	this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
	formatingContext.retrieveFloats(childrenFormattingContext);
	if(childLastPositionedDOMElementData != lastPositionedDOMElementData) {
		childLastPositionedDOMElementData.data = this.getContainerDOMElementData();
		var _g1 = 0, _g = childLastPositionedDOMElementData.children.length;
		while(_g1 < _g) {
			var i = _g1++;
			var positionedDOMElementData = childLastPositionedDOMElementData.children[i];
			positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data,viewportData,positionedDOMElementData.staticPosition);
		}
	}
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertInFlowDOMElement = function(formattingContext) {
	if(this.isInline() == false || this.isInlineFlow() == false) cocktailCore.style.js.Style.prototype.insertInFlowDOMElement.call(this,formattingContext);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertTextElement = function(textElement,formattingContext,containingDOMElementData) {
	var containerDOMElement = this._domElement;
	var text = textElement.getNativeText();
	text = this.applyWhiteSpace(text,this._computedStyle.whiteSpace);
	var textFragments = textElement.getTextFragments(text);
	var _g1 = 0, _g = textFragments.length;
	while(_g1 < _g) {
		var i = _g1++;
		var $e = (textFragments[i].textToken);
		switch( $e[1] ) {
		case 0:
			var value = $e[2];
			formattingContext.insert(this.getTextFragmentDOMElement(textFragments[i],value));
			break;
		case 1:
			formattingContext.insertSpace(this.getTextFragmentDOMElement(textFragments[i]," "));
			break;
		case 2:
			formattingContext.insertTab(this.getTextFragmentDOMElement(textFragments[i]," "));
			break;
		case 3:
			formattingContext.insertLineFeed();
			break;
		}
	}
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.shrinkToFitIfNeeded = function(availableWidth,minimumWidth) {
	var boxComputer = this.getBoxStylesComputer();
	return boxComputer.shrinkToFit(this._computedStyle,availableWidth,minimumWidth);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.invalidateText = function() {
	var containerDOMElement = this._domElement;
	containerDOMElement.resetTextFragments();
	cocktailCore.style.js.Style.prototype.invalidateText.call(this);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getTextFragmentDOMElement = function(textFragmentData,text) {
	var textFragmentDOMElement;
	if(textFragmentData.textFragmentDOMElement == null) {
		textFragmentDOMElement = this.createTextFragment(text);
		textFragmentData.textFragmentDOMElement = textFragmentDOMElement;
	} else textFragmentDOMElement = textFragmentData.textFragmentDOMElement;
	return textFragmentDOMElement;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.createTextFragment = function(text) {
	var textFragmentDOMElement = this.doCreateTextFragment(text);
	var containerDOMElement = this._domElement;
	containerDOMElement.addTextFragment(textFragmentDOMElement);
	return textFragmentDOMElement;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.doCreateTextFragment = function(text) {
	return null;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.applyWhiteSpace = function(text,whiteSpace) {
	var ret = text;
	switch( (whiteSpace)[1] ) {
	case 0:
		ret = this.collapseSpaceSequences(text);
		break;
	case 1:
		ret = this.removeLineFeeds(text);
		break;
	case 2:
		ret = this.collapseSpaceSequences(text);
		ret = this.removeLineFeeds(text);
		ret = this.convertTabToSpace(text);
		break;
	case 3:
		break;
	case 4:
		ret = this.collapseSpaceSequences(text);
		break;
	}
	return ret;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.applyTextTransform = function(text) {
	switch( (this._computedStyle.textTransform)[1] ) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.capitalizeText = function(text) {
	var capitalizedText = text.charAt(0);
	var _g1 = 1, _g = text.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
	}
	return capitalizedText;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.collapseSpaceSequences = function(text) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.removeLineFeeds = function(text) {
	return StringTools.replace(text,"\n","");
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.convertTabToSpace = function(text) {
	return StringTools.replace(text,"\t"," ");
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getContainerDOMElementData = function() {
	var height;
	if(this.isInline() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.isInline() == false && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
	return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.auto, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.auto, globalX : this._domElement.getGlobalX(), globalY : this._domElement.getGlobalY()};
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getFormatingContext = function(previousFormatingContext) {
	var containerDOMElement = this._domElement;
	var formattingContext;
	if(this.startsNewFormattingContext() == true) {
		var usedFormatingContext;
		if(this.isPositioned() == true && this.isRelativePositioned() == false) usedFormatingContext = null; else usedFormatingContext = previousFormatingContext;
		if(this.childrenInline() == true) formattingContext = new cocktailCore.style.formatter.InlineFormattingContext(containerDOMElement,usedFormatingContext); else formattingContext = new cocktailCore.style.formatter.BlockFormattingContext(containerDOMElement,usedFormatingContext);
	} else formattingContext = previousFormatingContext;
	return formattingContext;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.childrenInline = function() {
	var ret = true;
	var containerDOMElement = this._domElement;
	var _g1 = 0, _g = containerDOMElement.getChildren().length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this.isDOMElement(containerDOMElement.getChildren()[i])) {
			var childrenDOMElement = containerDOMElement.getChildren()[i].child;
			if(childrenDOMElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.block) {
				if(childrenDOMElement.getStyle().isFloat() == false) ret = false; else if(childrenDOMElement.getStyle().isPositioned() == false || childrenDOMElement.getStyle().isRelativePositioned() == true) ret = false;
			}
		}
	}
	return ret;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.startsNewFormattingContext = function() {
	var ret = false;
	if(this.isFloat() == true) ret = true; else if(this.isPositioned() == true && this.isRelativePositioned() == false) ret = true; else {
		switch( (this._computedStyle.display)[1] ) {
		case 0:
		case 1:
			ret = true;
			break;
		default:
		}
	}
	return ret;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.isInlineFlow = function() {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.isDOMElement = function(containerDOMElementChildData) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractContainerStyle;
cocktailCore.domElement.abstract.AbstractContainerDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral);
	this._children = new Array();
	this._textFragmentDOMElements = new Array();
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractContainerDOMElement"];
cocktailCore.domElement.abstract.AbstractContainerDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
for(var k in cocktailCore.domElement.js.DOMElement.prototype ) cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype[k] = cocktailCore.domElement.js.DOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._semantic = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.semantic = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._children = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.children = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._textFragmentDOMElements = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.initStyle = function() {
	this._style = new cocktailCore.style.js.ContainerStyle(this);
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild = function(domElement) {
	domElement.setParent(this);
	this._children.push({ child : domElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.domElement});
	this._style.invalidate();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild = function(domElement) {
	domElement.setParent(null);
	var newChildrenArray = new Array();
	var _g1 = 0, _g = this._children.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._children[i].child != domElement) newChildrenArray.push(this._children[i]);
	}
	this._children = newChildrenArray;
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText = function(textElement) {
	this._children.push({ child : textElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.textElement});
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText = function(textElement) {
	var newChildrenArray = new Array();
	var _g1 = 0, _g = this._children.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._children[i].child != textElement) newChildrenArray.push(this._children[i]);
	}
	this._children = newChildrenArray;
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.getChildren = function() {
	return this._children;
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.resetTextFragments = function() {
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
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addTextFragment = function(textFragmentDOMElement) {
	this._textFragmentDOMElements.push(textFragmentDOMElement);
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeTextFragment = function(textFragmentDOMElement) {
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.setSemantic = function(semantic) {
	this._semantic = semantic;
	return this._semantic;
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.getSemantic = function() {
	return this._semantic;
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
cocktailCore.domElement.js.ContainerDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.ContainerDOMElement.__name__ = ["cocktailCore","domElement","js","ContainerDOMElement"];
cocktailCore.domElement.js.ContainerDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype ) cocktailCore.domElement.js.ContainerDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype[k];
cocktailCore.domElement.js.ContainerDOMElement.prototype.addChild = function(domElement) {
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild.call(this,domElement);
	this._nativeElement.appendChild(domElement.getNativeElement());
	domElement.getNativeElement().style.zIndex = this._children.length - 1;
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.removeChild = function(domElement) {
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild.call(this,domElement);
	this._nativeElement.removeChild(domElement.getNativeElement());
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.addText = function(textElement) {
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText.call(this,textElement);
	this.getNativeElement().appendChild(textElement.getText());
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.removeText = function(textElement) {
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText.call(this,textElement);
	this._nativeElement.removeChild(textElement.getText());
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.setSemantic = function(semantic) {
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
cocktailCore.domElement.js.ContainerDOMElement.prototype.__class__ = cocktailCore.domElement.js.ContainerDOMElement;
if(typeof components=='undefined') components = {}
if(!components.richList) components.richList = {}
components.richList.RichList = function(richListModel,listStyle) {
	if( richListModel === $_ ) return;
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom("ul")));
	this.createRichListDOM(richListModel,listStyle);
	listStyle.list(this);
}
components.richList.RichList.__name__ = ["components","richList","RichList"];
components.richList.RichList.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
for(var k in cocktailCore.domElement.js.ContainerDOMElement.prototype ) components.richList.RichList.prototype[k] = cocktailCore.domElement.js.ContainerDOMElement.prototype[k];
components.richList.RichList.prototype.onChange = null;
components.richList.RichList.prototype.createRichListDOM = function(richListModel,listStyle) {
	var content = Utils.getContainer();
	var cellData;
	var _g = 0, _g1 = richListModel.content;
	while(_g < _g1.length) {
		var cellData1 = [_g1[_g]];
		++_g;
		var cell = [new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom("li")))];
		listStyle.cell(cell[0]);
		var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
		listStyle.cellImage(cellImage);
		cell[0].addChild(cellImage);
		var cellTextContainer = Utils.getContainer();
		var textElement = new cocktailCore.textElement.js.TextElement(cellData1[0].text);
		cellTextContainer.addText(textElement);
		listStyle.cellText(cellTextContainer);
		cell[0].addChild(cellTextContainer);
		cellImage.load(cellData1[0].imagePath);
		this.addChild(cell[0]);
		var onCellMouseOverDelegate = [$closure(this,"onCellMouseOver")];
		cell[0].setOnMouseOver((function(onCellMouseOverDelegate,cell) {
			return function(mouseEventData) {
				onCellMouseOverDelegate[0](mouseEventData,cell[0],listStyle);
			};
		})(onCellMouseOverDelegate,cell));
		var onCellMouseOutDelegate = [$closure(this,"onCellMouseOut")];
		cell[0].setOnMouseOut((function(onCellMouseOutDelegate,cell) {
			return function(mouseEventData) {
				onCellMouseOutDelegate[0](mouseEventData,cell[0],listStyle);
			};
		})(onCellMouseOutDelegate,cell));
		var onCellMouseDownDelegate = [$closure(this,"onCellMouseDown")];
		cell[0].setOnMouseDown((function(onCellMouseDownDelegate,cell) {
			return function(mouseEventData) {
				onCellMouseDownDelegate[0](mouseEventData,cell[0],listStyle);
			};
		})(onCellMouseDownDelegate,cell));
		var onCellMouseUpDelegate = [$closure(this,"onCellMouseUp")];
		cell[0].setOnMouseUp((function(onCellMouseUpDelegate,cell,cellData1) {
			return function(mouseEventData) {
				onCellMouseUpDelegate[0](mouseEventData,cell[0],listStyle,cellData1[0]);
			};
		})(onCellMouseUpDelegate,cell,cellData1));
	}
}
components.richList.RichList.prototype.onPictureLoadError = function(error) {
	haxe.Log.trace(error,{ fileName : "RichList.hx", lineNumber : 130, className : "components.richList.RichList", methodName : "onPictureLoadError"});
}
components.richList.RichList.prototype.onCellMouseOver = function(mouseEventData,cell,listStyle) {
	listStyle.cellMouseOver(cell);
}
components.richList.RichList.prototype.onCellMouseOut = function(mouseEventData,cell,listStyle) {
	listStyle.cellMouseOut(cell);
}
components.richList.RichList.prototype.onCellMouseDown = function(mouseEventData,cell,listStyle) {
	listStyle.cellMouseDown(cell);
}
components.richList.RichList.prototype.onCellMouseUp = function(mouseEventData,cell,listStyle,cellData) {
	listStyle.cellMouseUp(cell);
	if(this.onChange != null) this.onChange(cellData);
}
components.richList.RichList.prototype.__class__ = components.richList.RichList;
if(!cocktailCore.keyboard) cocktailCore.keyboard = {}
if(!cocktailCore.keyboard["abstract"]) cocktailCore.keyboard["abstract"] = {}
cocktailCore.keyboard.abstract.AbstractKeyboard = function(p) {
	if( p === $_ ) return;
	this.setNativeKeyboardListeners();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.__name__ = ["cocktailCore","keyboard","abstract","AbstractKeyboard"];
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyDown = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyUp = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.setNativeKeyboardListeners = function() {
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.unsetNativeKeyboardListeners = function() {
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyDown = function(event) {
	if(this.onKeyDown != null) this.onKeyDown(this.getKeyData(event));
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyUp = function(event) {
	if(this.onKeyUp != null) this.onKeyUp(this.getKeyData(event));
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getKeyData = function(event) {
	return null;
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getKeyValue = function(keyCode) {
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
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.__class__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
if(!cocktailCore.keyboard.js) cocktailCore.keyboard.js = {}
cocktailCore.keyboard.js.Keyboard = function(p) {
	if( p === $_ ) return;
	cocktailCore.keyboard.abstract.AbstractKeyboard.call(this);
}
cocktailCore.keyboard.js.Keyboard.__name__ = ["cocktailCore","keyboard","js","Keyboard"];
cocktailCore.keyboard.js.Keyboard.__super__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
for(var k in cocktailCore.keyboard.abstract.AbstractKeyboard.prototype ) cocktailCore.keyboard.js.Keyboard.prototype[k] = cocktailCore.keyboard.abstract.AbstractKeyboard.prototype[k];
cocktailCore.keyboard.js.Keyboard.prototype.setNativeKeyboardListeners = function() {
	js.Lib.document.addEventListener("keydown",$closure(this,"onNativeKeyDown"));
	js.Lib.document.addEventListener("keyup",$closure(this,"onNativeKeyUp"));
}
cocktailCore.keyboard.js.Keyboard.prototype.unsetNativeKeyboardListeners = function() {
	js.Lib.document.removeEventListener("keydown",$closure(this,"onNativeKeyDown"));
	js.Lib.document.removeEventListener("keyup",$closure(this,"onNativeKeyUp"));
}
cocktailCore.keyboard.js.Keyboard.prototype.getKeyData = function(event) {
	var key = { value : this.getKeyValue(event.keyCode), code : event.keyCode, ascii : event.charCode, altKey : event.altKey, controlKey : event.ctrlKey, shiftKey : event.shiftKey};
	return key;
}
cocktailCore.keyboard.js.Keyboard.prototype.__class__ = cocktailCore.keyboard.js.Keyboard;
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
	s.b[s.b.length] = "{";
	var it = this.keys();
	while( it.hasNext() ) {
		var i = it.next();
		s.b[s.b.length] = i;
		s.b[s.b.length] = " => ";
		s.b[s.b.length] = Std.string(this.get(i));
		if(it.hasNext()) s.b[s.b.length] = ", ";
	}
	s.b[s.b.length] = "}";
	return s.b.join("");
}
Hash.prototype.__class__ = Hash;
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = function(p) {
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadCompleteCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadErrorCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.load = function(url,onLoadComplete,onLoadError,allowCache) {
	if(allowCache == null) allowCache = true;
	this._onLoadCompleteCallback = onLoadComplete;
	this._onLoadErrorCallback = onLoadError;
	if(allowCache == false) url = this.disableUrlCaching(url);
	this.doLoad(url);
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.doLoad = function(url) {
	var fileRequest = new haxe.Http(url);
	fileRequest.onData = $closure(this,"onLoadComplete");
	fileRequest.onError = $closure(this,"onLoadError");
	fileRequest.request(false);
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.onLoadComplete = function(data) {
	this._onLoadCompleteCallback(data);
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.onLoadError = function(msg) {
	this._onLoadErrorCallback(msg);
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.disableUrlCaching = function(url) {
	var getId = "";
	if(url.indexOf("?") == -1) getId = "?"; else getId = "&";
	url += getId + "rand=" + Math.round(Math.random() * 10000);
	return url;
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.__class__ = cocktailCore.resource.abstract.AbstractResourceLoader;
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ResourceLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.ResourceLoader.__name__ = ["cocktailCore","resource","js","ResourceLoader"];
cocktailCore.resource.js.ResourceLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.ResourceLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.ResourceLoader.prototype.__class__ = cocktailCore.resource.js.ResourceLoader;
if(!cocktailCore.style.computer) cocktailCore.style.computer = {}
cocktailCore.style.computer.BoxStylesComputer = function(p) {
}
cocktailCore.style.computer.BoxStylesComputer.__name__ = ["cocktailCore","style","computer","BoxStylesComputer"];
cocktailCore.style.computer.BoxStylesComputer.prototype.measure = function(style,containingDOMElementData) {
	this.measureHorizontalPaddings(style,containingDOMElementData);
	this.measureVerticalPaddings(style,containingDOMElementData);
	this.measureWidthAndHorizontalMargins(style,containingDOMElementData);
	this.measureHeightAndVerticalMargins(style,containingDOMElementData);
	this.measurePositionOffsets(style,containingDOMElementData);
	this.measureDimensionsConstraints(style,containingDOMElementData);
	this.constrainDimensions(style);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	return computedStyles.width;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureDimensionsConstraints = function(style,containingDOMElementData) {
	style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
	style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureVerticalPaddings = function(style,containingDOMElementData) {
	style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHorizontalPaddings = function(style,containingDOMElementData) {
	style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureWidthAndHorizontalMargins = function(style,containingDOMElementData) {
	if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoWidth = function(style,containingDOMElementData) {
	style.getComputedStyle().width = 0;
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	style.getComputedStyle().width = this.getComputedAutoWidth(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureWidth = function(style,containingDOMElementData) {
	style.getComputedStyle().width = this.getNativeWidth(style,containingDOMElementData);
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeightAndVerticalMargins = function(style,containingDOMElementData) {
	if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoHeight = function(style,containingDOMElementData) {
	style.getComputedStyle().height = this.getComputedAutoHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeight = function(style,containingDOMElementData) {
	style.getComputedStyle().height = this.getNativeHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.constrainDimensions = function(style) {
	var computedStyle = style.getComputedStyle();
	if(style.getMaxWidth() != cocktail.style.ConstrainedDimensionStyleValue.none) {
		if(computedStyle.width > computedStyle.maxWidth) computedStyle.width = computedStyle.maxWidth;
	}
	if(computedStyle.width < computedStyle.minWidth) computedStyle.width = computedStyle.minWidth;
	if(style.getHeight() != cocktail.style.DimensionStyleValue.auto) {
		if(style.getMaxHeight() != cocktail.style.ConstrainedDimensionStyleValue.none) {
			if(computedStyle.height > computedStyle.maxHeight) computedStyle.height = computedStyle.maxHeight;
		}
		if(computedStyle.height < computedStyle.minHeight) computedStyle.height = computedStyle.minHeight;
	}
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getNativeWidth = function(style,containingDOMElementData) {
	return this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	return containingDOMElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getNativeHeight = function(style,containingDOMElementData) {
	return this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginLeft = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginRight = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginTop = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginBottom = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
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
		computedMargin = this.getComputedAutoMargin(opositeMarginStyleValue,marginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight);
		break;
	}
	return computedMargin;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	var computedMargin;
	if(isHorizontalMargin == true || isDimensionAuto == true) computedMargin = 0; else {
		switch( (opositeMarginStyleValue)[1] ) {
		case 2:
			computedMargin = Math.round((containingDOMElementDimension - computedDimension - computedPaddingsDimension) / 2);
			break;
		default:
			var opositeComputedMargin = this.getComputedMargin(opositeMarginStyleValue,marginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight);
			computedMargin = containingDOMElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin;
		}
	}
	return computedMargin;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedConstrainedDimension = function(constrainedDimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedPositionOffset = function(positionOffsetStyleValue,containingDOMElementDimension,fontSize,xHeight) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedDimension = function(dimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedPadding = function(paddingStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
	var computedPaddingValue;
	var $e = (paddingStyleValue);
	switch( $e[1] ) {
	case 0:
		var value = $e[2];
		computedPaddingValue = cocktailCore.unit.UnitManager.getPixelFromLengthValue(value,fontSize,xHeight);
		break;
	case 1:
		var value = $e[2];
		if(isContainingDimensionAuto == true) computedPaddingValue = 0; else computedPaddingValue = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
		break;
	}
	return computedPaddingValue;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.BoxStylesComputer;
if(!cocktailCore.style.computer.boxComputers) cocktailCore.style.computer.boxComputers = {}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	var ret = 0;
	var embeddedDOMElement = style.getDOMElement();
	if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
		if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else if(embeddedDOMElement.getIntrinsicHeight() != null && embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(embeddedDOMElement.getIntrinsicHeight() * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicRatio() != null) ret = 0;
	} else {
		var computedHeight = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedHeight * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else ret = 0;
	}
	return ret;
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	var embeddedDOMElement = style.getDOMElement();
	var ret = 0;
	if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) {
		if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
	} else {
		var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedWidth * embeddedDOMElement.getIntrinsicRatio()); else {
		}
	}
	return ret;
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	var computedMargin;
	if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
	return computedMargin;
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	return 0;
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
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
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	return 0;
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	var shrinkedWidth;
	if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
	return shrinkedWidth;
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
cocktailCore.resource.abstract.AbstractImageLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.js.ResourceLoader.call(this);
}
cocktailCore.resource.abstract.AbstractImageLoader.__name__ = ["cocktailCore","resource","abstract","AbstractImageLoader"];
cocktailCore.resource.abstract.AbstractImageLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
for(var k in cocktailCore.resource.js.ResourceLoader.prototype ) cocktailCore.resource.abstract.AbstractImageLoader.prototype[k] = cocktailCore.resource.js.ResourceLoader.prototype[k];
cocktailCore.resource.abstract.AbstractImageLoader.prototype._nativeElement = null;
cocktailCore.resource.abstract.AbstractImageLoader.prototype.nativeElement = null;
cocktailCore.resource.abstract.AbstractImageLoader.prototype.getNativeElement = function() {
	return this._nativeElement;
}
cocktailCore.resource.abstract.AbstractImageLoader.prototype.__class__ = cocktailCore.resource.abstract.AbstractImageLoader;
cocktailCore.style.InlineBoxValue = { __ename__ : ["cocktailCore","style","InlineBoxValue"], __constructs__ : ["domElement","space","tab"] }
cocktailCore.style.InlineBoxValue.domElement = ["domElement",0];
cocktailCore.style.InlineBoxValue.domElement.toString = $estr;
cocktailCore.style.InlineBoxValue.domElement.__enum__ = cocktailCore.style.InlineBoxValue;
cocktailCore.style.InlineBoxValue.space = ["space",1];
cocktailCore.style.InlineBoxValue.space.toString = $estr;
cocktailCore.style.InlineBoxValue.space.__enum__ = cocktailCore.style.InlineBoxValue;
cocktailCore.style.InlineBoxValue.tab = ["tab",2];
cocktailCore.style.InlineBoxValue.tab.toString = $estr;
cocktailCore.style.InlineBoxValue.tab.__enum__ = cocktailCore.style.InlineBoxValue;
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = function(p) {
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype.position = function(domElement,containingDOMElementData,staticPosition) {
	this.applyOffset(domElement,containingDOMElementData,staticPosition);
}
cocktailCore.style.positioner.BoxPositioner.prototype.applyOffset = function(domElement,containingDOMElementData,staticPosition) {
	if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeX(domElement,domElement.getStyle().getNativeX(domElement) + domElement.getStyle().getComputedStyle().left); else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeX(domElement,containingDOMElementData.width - domElement.getStyle().getComputedStyle().width - domElement.getStyle().getComputedStyle().right); else domElement.getStyle().setNativeX(domElement,Math.round(staticPosition.x));
	if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeY(domElement,domElement.getStyle().getNativeY(domElement) + domElement.getStyle().getComputedStyle().top); else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeY(domElement,containingDOMElementData.height - domElement.getStyle().getComputedStyle().height - domElement.getStyle().getComputedStyle().bottom); else domElement.getStyle().setNativeY(domElement,Math.round(staticPosition.y));
}
cocktailCore.style.positioner.BoxPositioner.prototype.__class__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.js.ContainerStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.abstract.AbstractContainerStyle.call(this,domElement);
}
cocktailCore.style.js.ContainerStyle.__name__ = ["cocktailCore","style","js","ContainerStyle"];
cocktailCore.style.js.ContainerStyle.__super__ = cocktailCore.style.abstract.AbstractContainerStyle;
for(var k in cocktailCore.style.abstract.AbstractContainerStyle.prototype ) cocktailCore.style.js.ContainerStyle.prototype[k] = cocktailCore.style.abstract.AbstractContainerStyle.prototype[k];
cocktailCore.style.js.ContainerStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElement,rootDOMElement,containingDOMElementFontMetricsData) {
}
cocktailCore.style.js.ContainerStyle.prototype.__class__ = cocktailCore.style.js.ContainerStyle;
if(!cocktailCore.unit) cocktailCore.unit = {}
cocktailCore.unit.UnitManager = function(p) {
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
cocktailCore.unit.UnitManager.prototype.__class__ = cocktailCore.unit.UnitManager;
if(!cocktailCore.textElement) cocktailCore.textElement = {}
cocktailCore.textElement.TextTokenValue = { __ename__ : ["cocktailCore","textElement","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
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
cocktailCore.style.computer.DisplayStylesComputer = function(p) {
}
cocktailCore.style.computer.DisplayStylesComputer.__name__ = ["cocktailCore","style","computer","DisplayStylesComputer"];
cocktailCore.style.computer.DisplayStylesComputer.compute = function(style) {
	var computedStyle = style.getComputedStyle();
	computedStyle.position = cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition(style);
	computedStyle["float"] = cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle["float"]);
	computedStyle.clear = cocktailCore.style.computer.DisplayStylesComputer.getComputedClear(style,computedStyle.position,computedStyle.display);
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedPosition = function(style) {
	return style.getPosition();
}
cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat = function(style,computedPosition) {
	var ret;
	if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.FloatStyleValue.none; else ret = style.getFloat();
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
cocktailCore.style.computer.DisplayStylesComputer.prototype.__class__ = cocktailCore.style.computer.DisplayStylesComputer;
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
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement = function(nativeElement,style) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	this._style = style;
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractTextFragmentDOMElement"];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
for(var k in cocktailCore.domElement.js.DOMElement.prototype ) cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype[k] = cocktailCore.domElement.js.DOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype.initStyle = function() {
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
cocktailCore.style.computer.FontAndTextStylesComputer = function(p) {
}
cocktailCore.style.computer.FontAndTextStylesComputer.__name__ = ["cocktailCore","style","computer","FontAndTextStylesComputer"];
cocktailCore.style.computer.FontAndTextStylesComputer.compute = function(style,containingDOMElementData,containingDOMElementFontMetricsData) {
	var computedStyle = style.getComputedStyle();
	if(containingDOMElementFontMetricsData != null) computedStyle.fontSize = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,containingDOMElementFontMetricsData.fontSize,containingDOMElementFontMetricsData.xHeight); else computedStyle.fontSize = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedFontSize(style,12.0,10.0);
	computedStyle.lineHeight = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedLineHeight(style);
	computedStyle.verticalAlign = cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign(style,containingDOMElementFontMetricsData);
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
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingDOMElementFontMetricsData) {
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
cocktailCore.style.computer.FontAndTextStylesComputer.prototype.__class__ = cocktailCore.style.computer.FontAndTextStylesComputer;
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
cocktailCore.domElement.js.ImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.ImageDOMElement.__name__ = ["cocktailCore","domElement","js","ImageDOMElement"];
cocktailCore.domElement.js.ImageDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype ) cocktailCore.domElement.js.ImageDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k];
cocktailCore.domElement.js.ImageDOMElement.prototype.onLoadComplete = function(image) {
	this._src = image.src;
	this._naturalHeight = image.naturalHeight;
	this._naturalWidth = image.naturalWidth;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoadComplete.call(this,image);
}
cocktailCore.domElement.js.ImageDOMElement.prototype.setSmooth = function(value) {
	cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSmooth.call(this,value);
	if(value == true) this._nativeElement.style.imageRendering = "optimizeQuality"; else this._nativeElement.style.imageRendering = "optimizeSpeed";
	return value;
}
cocktailCore.domElement.js.ImageDOMElement.prototype.__class__ = cocktailCore.domElement.js.ImageDOMElement;
cocktailCore.style.positioner.RelativePositioner = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.RelativePositioner.__name__ = ["cocktailCore","style","positioner","RelativePositioner"];
cocktailCore.style.positioner.RelativePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.RelativePositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.RelativePositioner.prototype.position = function(domElement,containingDOMElementData,staticPosition) {
	this.applyOffset(domElement,containingDOMElementData,staticPosition);
}
cocktailCore.style.positioner.RelativePositioner.prototype.applyOffset = function(domElement,containingDOMElementData,staticPosition) {
	if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeX(domElement,domElement.getStyle().getNativeX(domElement) + domElement.getStyle().getComputedStyle().left);
	if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.auto) domElement.getStyle().setNativeY(domElement,domElement.getStyle().getNativeY(domElement) + domElement.getStyle().getComputedStyle().top);
}
cocktailCore.style.positioner.RelativePositioner.prototype.__class__ = cocktailCore.style.positioner.RelativePositioner;
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = function(text) {
	if( text === $_ ) return;
	this._textFragments = new Array();
}
cocktailCore.textElement.abstract.AbstractTextElement.__name__ = ["cocktailCore","textElement","abstract","AbstractTextElement"];
cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments = function(text) {
	var textFragments = new Array();
	var textFragment = "";
	var i = 0;
	while(i < text.length) {
		if(text.charAt(i) == "\\") {
			if(text.charAt(i + 1) != null) {
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
		} else if(StringTools.isSpace(text,i) == true) {
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
cocktailCore.textElement.abstract.AbstractTextElement.prototype._text = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype.text = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype._textFragments = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype.reset = function() {
	var _g1 = 0, _g = this._textFragments.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._textFragments[i].textFragmentDOMElement = null;
	}
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getTextFragments = function(text) {
	if(this._textFragments.length == 0) this._textFragments = cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments(text);
	return this._textFragments;
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getNativeText = function() {
	return null;
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getText = function() {
	return this._text;
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.__class__ = cocktailCore.textElement.abstract.AbstractTextElement;
if(!cocktailCore.textElement.js) cocktailCore.textElement.js = {}
cocktailCore.textElement.js.TextElement = function(text) {
	if( text === $_ ) return;
	cocktailCore.textElement.abstract.AbstractTextElement.call(this,text);
	this._text = js.Lib.document.createTextNode(text);
}
cocktailCore.textElement.js.TextElement.__name__ = ["cocktailCore","textElement","js","TextElement"];
cocktailCore.textElement.js.TextElement.__super__ = cocktailCore.textElement.abstract.AbstractTextElement;
for(var k in cocktailCore.textElement.abstract.AbstractTextElement.prototype ) cocktailCore.textElement.js.TextElement.prototype[k] = cocktailCore.textElement.abstract.AbstractTextElement.prototype[k];
cocktailCore.textElement.js.TextElement.prototype.__class__ = cocktailCore.textElement.js.TextElement;
if(typeof cocktail=='undefined') cocktail = {}
if(!cocktail.keyboard) cocktail.keyboard = {}
cocktail.keyboard.KeyboardKeyValue = { __ename__ : ["cocktail","keyboard","KeyboardKeyValue"], __constructs__ : ["unknown","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","backSpace","capsLock","control","del","down","end","escape","enter","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","F13","F14","F15","home","insert","left","numpad0","numpad1","numpad2","numpad3","numpad4","numpad5","numpad6","numpad7","numpad8","numpad9","numpadAdd","numpadSpecial","numpadDecimal","numpadDivide","numpadEnter","numpadMultiply","numpadSubstract","pageDown","pageUp","right","shift","space","tab","up"] }
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
components.richList.StyleNormal = function() { }
components.richList.StyleNormal.__name__ = ["components","richList","StyleNormal"];
components.richList.StyleNormal.initStyle = function(domElement) {
	var computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
	domElement.getStyle().setComputedStyle(computedStyle);
}
components.richList.StyleNormal.getDefaultStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
components.richList.StyleNormal.getCellStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	components.richList.StyleNormal.getDefaultStyle(domElement);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#666666"));
}
components.richList.StyleNormal.getCellImageStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	components.richList.StyleNormal.getDefaultStyle(domElement);
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setFloat(cocktail.style.FloatStyleValue.right);
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(16)));
}
components.richList.StyleNormal.getCellTextStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
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
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
}
components.richList.StyleNormal.getCellMouseOverStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#333333"));
}
components.richList.StyleNormal.getCellMouseOutStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#666666"));
}
components.richList.StyleNormal.getCellMouseDownStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#000000"));
}
components.richList.StyleNormal.getCellMouseUpStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#333333"));
}
components.richList.StyleNormal.getCellLineStyle = function(domElement) {
	components.richList.StyleNormal.initStyle(domElement);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(1)));
}
components.richList.StyleNormal.prototype.__class__ = components.richList.StyleNormal;
Utils = function() { }
Utils.__name__ = ["Utils"];
Utils.getContainer = function() {
	var ret = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	ret.setX(0);
	ret.setY(0);
	return ret;
}
Utils.getGraphic = function() {
	var ret = new cocktailCore.domElement.js.GraphicDOMElement();
	return ret;
}
Utils.fillGraphic = function(domElement,color) {
	domElement.clear();
	domElement.beginFill(cocktail.domElement.FillStyleValue.monochrome({ color : color, alpha : 100}),cocktail.domElement.LineStyleValue.none);
	domElement.drawRect(0,0,domElement.getWidth(),domElement.getHeight());
	domElement.endFill();
	domElement.setAlpha(1);
}
Utils.prototype.__class__ = Utils;
components.richList.RichListUtils = function() { }
components.richList.RichListUtils.__name__ = ["components","richList","RichListUtils"];
components.richList.RichListUtils.__super__ = Utils;
for(var k in Utils.prototype ) components.richList.RichListUtils.prototype[k] = Utils.prototype[k];
components.richList.RichListUtils.createRichListModel = function() {
	var richListModel = { content : new Array()};
	return richListModel;
}
components.richList.RichListUtils.prototype.__class__ = components.richList.RichListUtils;
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
if(!cocktail.mouse) cocktail.mouse = {}
cocktail.mouse.MouseCursorValue = { __ename__ : ["cocktail","mouse","MouseCursorValue"], __constructs__ : ["custom","auto","none","native"] }
cocktail.mouse.MouseCursorValue.custom = function(imageDOMElement,hotSpot) { var $x = ["custom",0,imageDOMElement,hotSpot]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.MouseCursorValue.auto = ["auto",1];
cocktail.mouse.MouseCursorValue.auto.toString = $estr;
cocktail.mouse.MouseCursorValue.auto.__enum__ = cocktail.mouse.MouseCursorValue;
cocktail.mouse.MouseCursorValue.none = ["none",2];
cocktail.mouse.MouseCursorValue.none.toString = $estr;
cocktail.mouse.MouseCursorValue.none.__enum__ = cocktail.mouse.MouseCursorValue;
cocktail.mouse.MouseCursorValue["native"] = function(nativeOSMouseCursorValue) { var $x = ["native",3,nativeOSMouseCursorValue]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.NativeOSMouseCursorValue = { __ename__ : ["cocktail","mouse","NativeOSMouseCursorValue"], __constructs__ : ["pointer","text"] }
cocktail.mouse.NativeOSMouseCursorValue.pointer = ["pointer",0];
cocktail.mouse.NativeOSMouseCursorValue.pointer.toString = $estr;
cocktail.mouse.NativeOSMouseCursorValue.pointer.__enum__ = cocktail.mouse.NativeOSMouseCursorValue;
cocktail.mouse.NativeOSMouseCursorValue.text = ["text",1];
cocktail.mouse.NativeOSMouseCursorValue.text.toString = $estr;
cocktail.mouse.NativeOSMouseCursorValue.text.__enum__ = cocktail.mouse.NativeOSMouseCursorValue;
if(!cocktail.geom) cocktail.geom = {}
cocktail.geom.Matrix = function(data) {
	if( data === $_ ) return;
	this.setData(data);
}
cocktail.geom.Matrix.__name__ = ["cocktail","geom","Matrix"];
cocktail.geom.Matrix.prototype._data = null;
cocktail.geom.Matrix.prototype.data = null;
cocktail.geom.Matrix.prototype.identity = function() {
	this._data = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : 0.0, f : 0.0};
}
cocktail.geom.Matrix.prototype.setData = function(data) {
	this._data = data;
	if(this._data == null) this.identity();
	return this._data;
}
cocktail.geom.Matrix.prototype.getData = function() {
	return this._data;
}
cocktail.geom.Matrix.prototype.concatenate = function(matrix) {
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
cocktail.geom.Matrix.prototype.translate = function(x,y) {
	var translationMatrixData = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : x, f : y};
	var translationMatrix = new cocktail.geom.Matrix(translationMatrixData);
	this.concatenate(translationMatrix);
}
cocktail.geom.Matrix.prototype.rotate = function(angle,registrationPoint) {
	var angleInRad = angle / 180 * Math.PI;
	var rotatedMatrix = new cocktail.geom.Matrix();
	rotatedMatrix.translate(registrationPoint.x,registrationPoint.y);
	var a = 0.0;
	var b = 0.0;
	var c = 0.0;
	var d = 0.0;
	if(angle == 90) {
		a = d = 0.0;
		c = b = 1.0;
	} else if(angle == 180) {
		a = d = -1.0;
		c = b = 0.0;
	} else if(angle == 270) {
		a = d = 0.0;
		c = b = -1.0;
	} else {
		a = d = Math.cos(angleInRad);
		c = b = Math.sin(angleInRad);
	}
	var rotationMatrixData = { a : a, b : b, c : c * -1.0, d : d, e : 0.0, f : 0.0};
	var rotationMatrix = new cocktail.geom.Matrix(rotationMatrixData);
	rotatedMatrix.concatenate(rotationMatrix);
	rotatedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
	this.concatenate(rotatedMatrix);
}
cocktail.geom.Matrix.prototype.scale = function(scaleX,scaleY,registrationPoint) {
	var scaledMatrix = new cocktail.geom.Matrix();
	scaledMatrix.translate(registrationPoint.x,registrationPoint.y);
	var scalingMatrixData = { a : scaleX, b : 0.0, c : 0.0, d : scaleY, e : 0.0, f : 0.0};
	var scalingMatrix = new cocktail.geom.Matrix(scalingMatrixData);
	scaledMatrix.concatenate(scalingMatrix);
	scaledMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
	this.concatenate(scaledMatrix);
}
cocktail.geom.Matrix.prototype.skew = function(skewX,skewY,registrationPoint) {
	var skewedMatrix = new cocktail.geom.Matrix();
	skewedMatrix.translate(registrationPoint.x,registrationPoint.y);
	var skewingMatrixData = { a : 1.0, b : Math.tan(skewY), c : Math.tan(skewX), d : 1.0, e : 0.0, f : 0.0};
	var skewingMatrix = new cocktail.geom.Matrix(skewingMatrixData);
	skewedMatrix.concatenate(skewingMatrix);
	skewedMatrix.translate(registrationPoint.x * -1,registrationPoint.y * -1);
	this.concatenate(skewedMatrix);
}
cocktail.geom.Matrix.prototype.setRotation = function(angle,registrationPoint) {
	var currentRotation = this.getRotation();
	var resetAngle = 360 - currentRotation;
	this.rotate(resetAngle,registrationPoint);
	this.rotate(angle,registrationPoint);
}
cocktail.geom.Matrix.prototype.getRotation = function() {
	var flip = this.getFlip();
	var scaleX = this.getScaleX();
	var skewX = this.getSkewX();
	var actualScaleX = Math.sqrt(scaleX * scaleX + skewX * skewX);
	var scaleY = this.getScaleY();
	var skewY = this.getSkewY() * flip;
	var actualScaleY = Math.sqrt(scaleY * scaleY + skewY * skewY);
	var rotationInRad = Math.atan2(skewY / actualScaleY - skewX / actualScaleX,scaleY / actualScaleY + scaleX / actualScaleX);
	var rotationInDeg = Math.round(rotationInRad * 180 / Math.PI);
	if(rotationInDeg < 0) rotationInDeg = 360 + rotationInDeg;
	return rotationInDeg;
}
cocktail.geom.Matrix.prototype.getFlip = function() {
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
cocktail.geom.Matrix.prototype.setScaleX = function(scaleXFactor,registrationPoint) {
	var currentScaleX = this.getScaleX();
	var resetScaleX = 1 / currentScaleX;
	this.scale(resetScaleX,1,registrationPoint);
	this.scale(scaleXFactor,1,registrationPoint);
}
cocktail.geom.Matrix.prototype.getScaleX = function() {
	return this._data.a;
}
cocktail.geom.Matrix.prototype.setScaleY = function(scaleYFactor,registrationPoint) {
	var currentScaleY = this.getScaleY();
	var resetScaleY = 1 / currentScaleY;
	this.scale(1,resetScaleY,registrationPoint);
	this.scale(1,scaleYFactor,registrationPoint);
}
cocktail.geom.Matrix.prototype.getScaleY = function() {
	return this._data.d;
}
cocktail.geom.Matrix.prototype.setTranslationX = function(translationX) {
	var currentTranslationX = this.getTranslationX();
	var resetTranslationX = currentTranslationX * -1;
	this.translate(resetTranslationX,0);
	this.translate(translationX,0);
}
cocktail.geom.Matrix.prototype.getTranslationX = function() {
	return this._data.e;
}
cocktail.geom.Matrix.prototype.setTranslationY = function(translationY) {
	var currentTranslationY = this.getTranslationY();
	var resetTranslationY = currentTranslationY * -1;
	this.translate(0,resetTranslationY);
	this.translate(0,translationY);
}
cocktail.geom.Matrix.prototype.getTranslationY = function() {
	return this._data.f;
}
cocktail.geom.Matrix.prototype.getSkewX = function() {
	return this._data.c;
}
cocktail.geom.Matrix.prototype.getSkewY = function() {
	return this._data.b;
}
cocktail.geom.Matrix.prototype.__class__ = cocktail.geom.Matrix;
cocktailCore.style.positioner.AbsolutePositioner = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.AbsolutePositioner.__name__ = ["cocktailCore","style","positioner","AbsolutePositioner"];
cocktailCore.style.positioner.AbsolutePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.AbsolutePositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.AbsolutePositioner.prototype.__class__ = cocktailCore.style.positioner.AbsolutePositioner;
if(!cocktailCore.nativeElement) cocktailCore.nativeElement = {}
if(!cocktailCore.nativeElement["abstract"]) cocktailCore.nativeElement["abstract"] = {}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager = function(p) {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementPathManager"];
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype.getRoot = function() {
	return null;
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype.__class__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
if(!cocktailCore.nativeElement.js) cocktailCore.nativeElement.js = {}
cocktailCore.nativeElement.js.NativeElementPathManager = function(p) {
	if( p === $_ ) return;
	cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.call(this);
}
cocktailCore.nativeElement.js.NativeElementPathManager.__name__ = ["cocktailCore","nativeElement","js","NativeElementPathManager"];
cocktailCore.nativeElement.js.NativeElementPathManager.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
for(var k in cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype ) cocktailCore.nativeElement.js.NativeElementPathManager.prototype[k] = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype[k];
cocktailCore.nativeElement.js.NativeElementPathManager.prototype.getRoot = function() {
	return js.Lib.document.body;
}
cocktailCore.nativeElement.js.NativeElementPathManager.prototype.__class__ = cocktailCore.nativeElement.js.NativeElementPathManager;
cocktailCore.style.abstract.AbstractEmbeddedStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.js.Style.call(this,domElement);
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.__name__ = ["cocktailCore","style","abstract","AbstractEmbeddedStyle"];
cocktailCore.style.abstract.AbstractEmbeddedStyle.__super__ = cocktailCore.style.js.Style;
for(var k in cocktailCore.style.js.Style.prototype ) cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype[k] = cocktailCore.style.js.Style.prototype[k];
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.setNativeX = function(domElement,x) {
	x += this._computedStyle.paddingLeft;
	cocktailCore.style.js.Style.prototype.setNativeX.call(this,domElement,x);
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.setNativeY = function(domElement,y) {
	y += this._computedStyle.paddingTop;
	cocktailCore.style.js.Style.prototype.setNativeY.call(this,domElement,y);
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.getBoxStylesComputer = function() {
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
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.isEmbedded = function() {
	return true;
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractEmbeddedStyle;
cocktailCore.style.js.EmbeddedStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.abstract.AbstractEmbeddedStyle.call(this,domElement);
}
cocktailCore.style.js.EmbeddedStyle.__name__ = ["cocktailCore","style","js","EmbeddedStyle"];
cocktailCore.style.js.EmbeddedStyle.__super__ = cocktailCore.style.abstract.AbstractEmbeddedStyle;
for(var k in cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype ) cocktailCore.style.js.EmbeddedStyle.prototype[k] = cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype[k];
cocktailCore.style.js.EmbeddedStyle.prototype.getNativeX = function(domElement) {
	return domElement.getNativeElement().offsetLeft;
}
cocktailCore.style.js.EmbeddedStyle.prototype.getNativeY = function(domElement) {
	return domElement.getNativeElement().offsetTop;
}
cocktailCore.style.js.EmbeddedStyle.prototype.getNativeWidth = function(domElement) {
	return domElement.getNativeElement().clientWidth;
}
cocktailCore.style.js.EmbeddedStyle.prototype.getNativeHeight = function(domElement) {
	return domElement.getNativeElement().clientHeight;
}
cocktailCore.style.js.EmbeddedStyle.prototype.__class__ = cocktailCore.style.js.EmbeddedStyle;
if(!cocktail.viewport) cocktail.viewport = {}
cocktail.viewport.OrientationValue = { __ename__ : ["cocktail","viewport","OrientationValue"], __constructs__ : ["vertical","horizontal"] }
cocktail.viewport.OrientationValue.vertical = ["vertical",0];
cocktail.viewport.OrientationValue.vertical.toString = $estr;
cocktail.viewport.OrientationValue.vertical.__enum__ = cocktail.viewport.OrientationValue;
cocktail.viewport.OrientationValue.horizontal = ["horizontal",1];
cocktail.viewport.OrientationValue.horizontal.toString = $estr;
cocktail.viewport.OrientationValue.horizontal.__enum__ = cocktail.viewport.OrientationValue;
cocktailCore.domElement.abstract.AbstractBodyDOMElement = function(p) {
	if( p === $_ ) return;
	cocktailCore.domElement.js.ContainerDOMElement.call(this,cocktail.nativeElement.NativeElementManager.getRoot());
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractBodyDOMElement"];
cocktailCore.domElement.abstract.AbstractBodyDOMElement.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
for(var k in cocktailCore.domElement.js.ContainerDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype[k] = cocktailCore.domElement.js.ContainerDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype._viewPort = null;
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.initStyle = function() {
	this._style = new cocktailCore.style.js.BodyStyle(this);
	this._viewPort = new cocktailCore.viewport.js.Viewport();
	this._viewPort._setOnResize($closure(this,"onViewPortResize"));
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.onViewPortResize = function() {
	this._style.invalidate();
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.setX = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.setY = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.setWidth = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.setHeight = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.setIsVisible = function(value) {
	return value;
}
cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractBodyDOMElement;
cocktailCore.domElement.js.TextFragmentDOMElement = function(nativeElement,style) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype ) cocktailCore.domElement.js.TextFragmentDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype[k];
cocktailCore.domElement.js.TextFragmentDOMElement.prototype.__class__ = cocktailCore.domElement.js.TextFragmentDOMElement;
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	return 0;
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	var shrinkedWidth;
	if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
	return shrinkedWidth;
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktailCore.resource.js.ImageLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.abstract.AbstractImageLoader.call(this);
	this._nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image);
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractImageLoader;
for(var k in cocktailCore.resource.abstract.AbstractImageLoader.prototype ) cocktailCore.resource.js.ImageLoader.prototype[k] = cocktailCore.resource.abstract.AbstractImageLoader.prototype[k];
cocktailCore.resource.js.ImageLoader.prototype.doLoad = function(url) {
	var onLoadCompleteDelegate = $closure(this,"onLoadComplete");
	var onLoadErrorDelegate = $closure(this,"onLoadError");
	var nativeElementDelegate = this._nativeElement;
	this._nativeElement.onload = function() {
		onLoadCompleteDelegate(nativeElementDelegate);
	};
	this._nativeElement.onerror = function() {
		onLoadErrorDelegate("couldn't load picture");
	};
	this._nativeElement.setAttribute("src",url);
}
cocktailCore.resource.js.ImageLoader.prototype.__class__ = cocktailCore.resource.js.ImageLoader;
if(!cocktailCore.classInstance) cocktailCore.classInstance = {}
if(!cocktailCore.classInstance["abstract"]) cocktailCore.classInstance["abstract"] = {}
cocktailCore.classInstance.abstract.AbstractClassInstance = function(nativeInstanceClassName) {
}
cocktailCore.classInstance.abstract.AbstractClassInstance.__name__ = ["cocktailCore","classInstance","abstract","AbstractClassInstance"];
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype._nativeInstance = null;
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.nativeInstance = null;
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.callMethod = function(methodName,args) {
	if(this.isFunction(methodName)) {
		var method = Reflect.field(this._nativeInstance,methodName);
		return method.apply(this._nativeInstance,args);
	}
	return null;
}
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.getField = function(fieldName) {
	var fieldGetterName = "get" + fieldName.substr(0,1).toUpperCase() + fieldName.substr(1);
	if(this.isFunction(fieldGetterName)) return Reflect.field(this._nativeInstance,fieldGetterName).apply(this._nativeInstance,[]); else return Reflect.field(this._nativeInstance,fieldName);
}
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.setField = function(fieldName,fieldValue) {
	var fieldSetterName = "set" + fieldName.substr(0,1).toUpperCase() + fieldName.substr(1);
	if(this.isFunction(fieldSetterName)) Reflect.field(this._nativeInstance,fieldSetterName).apply(this._nativeInstance,[fieldValue]); else this._nativeInstance[fieldName] = fieldValue;
}
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.isFunction = function(functionName) {
	return Reflect.isFunction(Reflect.field(this._nativeInstance,functionName));
}
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.getNativeInstance = function() {
	return this._nativeInstance;
}
cocktailCore.classInstance.abstract.AbstractClassInstance.prototype.__class__ = cocktailCore.classInstance.abstract.AbstractClassInstance;
if(!cocktail.nativeElement) cocktail.nativeElement = {}
cocktail.nativeElement.NativeElementTypeValue = { __ename__ : ["cocktail","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","custom"] }
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
cocktail.nativeElement.NativeElementTypeValue.custom = function(name) { var $x = ["custom",4,name]; $x.__enum__ = cocktail.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
cocktailCore.domElement.TextTokenValue = { __ename__ : ["cocktailCore","domElement","TextTokenValue"], __constructs__ : ["word","space","tab","lineFeed"] }
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
cocktailCore.domElement.ContainerDOMElementChildValue = { __ename__ : ["cocktailCore","domElement","ContainerDOMElementChildValue"], __constructs__ : ["domElement","textElement"] }
cocktailCore.domElement.ContainerDOMElementChildValue.domElement = ["domElement",0];
cocktailCore.domElement.ContainerDOMElementChildValue.domElement.toString = $estr;
cocktailCore.domElement.ContainerDOMElementChildValue.domElement.__enum__ = cocktailCore.domElement.ContainerDOMElementChildValue;
cocktailCore.domElement.ContainerDOMElementChildValue.textElement = ["textElement",1];
cocktailCore.domElement.ContainerDOMElementChildValue.textElement.toString = $estr;
cocktailCore.domElement.ContainerDOMElementChildValue.textElement.__enum__ = cocktailCore.domElement.ContainerDOMElementChildValue;
if(!cocktailCore.style.formatter) cocktailCore.style.formatter = {}
cocktailCore.style.formatter.FormattingContext = function(domElement,previousFormatingContext) {
	if( domElement === $_ ) return;
	this._containingDOMElement = domElement;
	this._containingDOMElementWidth = this._containingDOMElement.getStyle().getComputedStyle().width;
	this._floatsManager = new cocktailCore.style.floats.FloatsManager();
	if(previousFormatingContext != null) {
		if(domElement.getStyle().isFloat() == false) this._floatsManager.addFloats(previousFormatingContext);
	}
	this._flowData = this.initFlowData(this._containingDOMElement);
}
cocktailCore.style.formatter.FormattingContext.__name__ = ["cocktailCore","style","formatter","FormattingContext"];
cocktailCore.style.formatter.FormattingContext.prototype._containingDOMElement = null;
cocktailCore.style.formatter.FormattingContext.prototype.containingDOMElement = null;
cocktailCore.style.formatter.FormattingContext.prototype._containingDOMElementWidth = null;
cocktailCore.style.formatter.FormattingContext.prototype._floatsManager = null;
cocktailCore.style.formatter.FormattingContext.prototype.floatsManager = null;
cocktailCore.style.formatter.FormattingContext.prototype._flowData = null;
cocktailCore.style.formatter.FormattingContext.prototype.flowData = null;
cocktailCore.style.formatter.FormattingContext.prototype.initFlowData = function(domElement) {
	var flowY = domElement.getStyle().getComputedStyle().paddingTop;
	var flowX;
	if(domElement.getStyle().getComputedStyle().paddingLeft > this._floatsManager.getLeftFloatOffset(flowY)) flowX = domElement.getStyle().getComputedStyle().paddingLeft; else flowX = this._floatsManager.getLeftFloatOffset(flowY);
	return { x : flowX, y : flowY, xOffset : domElement.getStyle().getComputedStyle().paddingLeft, yOffset : domElement.getStyle().getComputedStyle().paddingTop, totalHeight : 0, maxWidth : 0};
}
cocktailCore.style.formatter.FormattingContext.prototype.insert = function(domElement) {
	this.doInsert(domElement);
}
cocktailCore.style.formatter.FormattingContext.prototype.insertSpace = function(domElement) {
	this.doInsert(domElement);
}
cocktailCore.style.formatter.FormattingContext.prototype.insertTab = function(domElement) {
	this.doInsert(domElement);
}
cocktailCore.style.formatter.FormattingContext.prototype.insertLineFeed = function() {
	this.startNewLine(0);
}
cocktailCore.style.formatter.FormattingContext.prototype.insertFloat = function(domElement) {
	var floatData = this._floatsManager.computeFloatData(domElement,this._flowData,this._containingDOMElementWidth);
	this.placeFloat(domElement,floatData);
}
cocktailCore.style.formatter.FormattingContext.prototype.clearFloat = function(clear,isFloat) {
}
cocktailCore.style.formatter.FormattingContext.prototype.retrieveFloats = function(formattingContext) {
	this._floatsManager.retrieveFloats(formattingContext);
}
cocktailCore.style.formatter.FormattingContext.prototype.destroy = function() {
}
cocktailCore.style.formatter.FormattingContext.prototype.startNewLine = function(domElementWidth,isLastLine) {
	if(isLastLine == null) isLastLine = false;
}
cocktailCore.style.formatter.FormattingContext.prototype.doInsert = function(domElement) {
	this.place(domElement);
	this.removeFloats();
}
cocktailCore.style.formatter.FormattingContext.prototype.getRemainingLineWidth = function() {
	return this._containingDOMElementWidth - this._flowData.x + this._flowData.xOffset - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
}
cocktailCore.style.formatter.FormattingContext.prototype.place = function(domElement) {
}
cocktailCore.style.formatter.FormattingContext.prototype.placeFloat = function(domElement,floatData) {
	domElement.getStyle().setNativeX(domElement,floatData.x + domElement.getStyle().getComputedStyle().marginLeft);
	domElement.getStyle().setNativeY(domElement,floatData.x + floatData.y + domElement.getStyle().getComputedStyle().marginTop);
}
cocktailCore.style.formatter.FormattingContext.prototype.removeFloats = function() {
	this._floatsManager.removeFloats(this._flowData.y);
}
cocktailCore.style.formatter.FormattingContext.prototype.getFloatsManager = function() {
	return this._floatsManager;
}
cocktailCore.style.formatter.FormattingContext.prototype.getFlowData = function() {
	return this._flowData;
}
cocktailCore.style.formatter.FormattingContext.prototype.getContainingDOMElement = function() {
	return this._containingDOMElement;
}
cocktailCore.style.formatter.FormattingContext.prototype.__class__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.BlockFormattingContext = function(domElement,previousFormattingContext) {
	if( domElement === $_ ) return;
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
}
cocktailCore.style.formatter.BlockFormattingContext.__name__ = ["cocktailCore","style","formatter","BlockFormattingContext"];
cocktailCore.style.formatter.BlockFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
for(var k in cocktailCore.style.formatter.FormattingContext.prototype ) cocktailCore.style.formatter.BlockFormattingContext.prototype[k] = cocktailCore.style.formatter.FormattingContext.prototype[k];
cocktailCore.style.formatter.BlockFormattingContext.prototype.place = function(domElement) {
	cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement);
	var leftFloatOffset = 0;
	if(domElement.getStyle().isEmbedded() == true) {
		this._flowData.y = this._floatsManager.getFirstAvailableY(this.getFlowData(),domElement.getOffsetWidth(),this._containingDOMElementWidth);
		leftFloatOffset = this._floatsManager.getLeftFloatOffset(this._flowData.y + domElement.getStyle().getComputedStyle().marginTop);
	}
	this._flowData.x = this._flowData.xOffset + leftFloatOffset;
	domElement.getStyle().setNativeX(domElement,this._flowData.x + domElement.getStyle().getComputedStyle().marginLeft);
	domElement.getStyle().setNativeY(domElement,this._flowData.y + domElement.getStyle().getComputedStyle().marginTop);
	this._flowData.y += domElement.getOffsetHeight();
	this._flowData.totalHeight = this._flowData.y;
	if(this._flowData.x + domElement.getOffsetWidth() + domElement.getStyle().getComputedStyle().marginLeft > this._flowData.maxWidth) this._flowData.maxWidth = this._flowData.x + domElement.getOffsetWidth() + domElement.getStyle().getComputedStyle().marginLeft;
}
cocktailCore.style.formatter.BlockFormattingContext.prototype.clearFloat = function(clear,isFloat) {
	this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
}
cocktailCore.style.formatter.BlockFormattingContext.prototype.__class__ = cocktailCore.style.formatter.BlockFormattingContext;
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	return 0;
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getNativeWidth = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getNativeHeight = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
StringBuf = function(p) {
	if( p === $_ ) return;
	this.b = new Array();
}
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype.add = function(x) {
	this.b[this.b.length] = x;
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
if(typeof haxe=='undefined') haxe = {}
haxe.Log = function() { }
haxe.Log.__name__ = ["haxe","Log"];
haxe.Log.trace = function(v,infos) {
	js.Boot.__trace(v,infos);
}
haxe.Log.clear = function() {
	js.Boot.__clear_trace();
}
haxe.Log.prototype.__class__ = haxe.Log;
cocktailCore.resource.js.ContainerLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.ContainerLoader.__name__ = ["cocktailCore","resource","js","ContainerLoader"];
cocktailCore.resource.js.ContainerLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.ContainerLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.ContainerLoader.prototype.onLoadComplete = function(data) {
	var domElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	domElement.getNativeElement().innerHTML = data;
	this._onLoadCompleteCallback(domElement);
}
cocktailCore.resource.js.ContainerLoader.prototype.__class__ = cocktailCore.resource.js.ContainerLoader;
cocktailCore.domElement.js.BodyDOMElement = function(p) {
	if( p === $_ ) return;
	cocktailCore.domElement.abstract.AbstractBodyDOMElement.call(this);
}
cocktailCore.domElement.js.BodyDOMElement.__name__ = ["cocktailCore","domElement","js","BodyDOMElement"];
cocktailCore.domElement.js.BodyDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractBodyDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype ) cocktailCore.domElement.js.BodyDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractBodyDOMElement.prototype[k];
cocktailCore.domElement.js.BodyDOMElement.prototype.__class__ = cocktailCore.domElement.js.BodyDOMElement;
cocktailCore.domElement.abstract.AbstractGraphicDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractGraphicDOMElement"];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
for(var k in cocktailCore.domElement.js.EmbeddedDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype[k] = cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill = function(fillStyle,lineStyle) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.endFill = function() {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.clear = function() {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawRect = function(x,y,width,height,cornerRadiuses) {
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
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawEllipse = function(x,y,width,height) {
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
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawStar = function(x,y,outerRadius,innerRadius,branches) {
	var angle = 360 / branches;
	var angleDecal = angle * 0.5;
	this.moveTo(Math.cos(0) * outerRadius + outerRadius,Math.sin(0) * outerRadius + outerRadius);
	var _g = 0;
	while(_g < branches) {
		var i = _g++;
		this.lineTo(Math.cos(this.conversion(i * angle)) * outerRadius + outerRadius,Math.sin(this.conversion(i * angle)) * outerRadius + outerRadius);
		this.lineTo(Math.cos(this.conversion(i * angle + angleDecal)) * innerRadius + outerRadius,Math.sin(this.conversion(i * angle + angleDecal)) * innerRadius + outerRadius);
	}
	this.lineTo(Math.cos(0) * outerRadius + outerRadius,Math.sin(0) * outerRadius + outerRadius);
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawPolygon = function(x,y,radius,sides) {
	var angle = 360 / sides;
	this.moveTo(Math.cos(0) * radius + radius,Math.sin(0) * radius + radius);
	var _g = 0;
	while(_g < sides) {
		var i = _g++;
		this.lineTo(Math.cos(this.conversion(i * angle)) * radius + radius,Math.sin(this.conversion(i * angle)) * radius + radius);
		this.lineTo(Math.cos(this.conversion(i * angle + angle)) * radius + radius,Math.sin(this.conversion(i * angle + angle)) * radius + radius);
	}
	this.lineTo(Math.cos(0) * radius + radius,Math.sin(0) * radius + radius);
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.conversion = function(val) {
	return val / 180 * Math.PI;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawImage = function(source,destinationPoint,sourceRect) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.lineTo = function(x,y) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.moveTo = function(x,y) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.curveTo = function(controlX,controlY,x,y) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeAlpha = function(genericAlpa) {
	return null;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeColor = function(genericColor) {
	return null;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeRatio = function(genericRatio) {
	return null;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeCapStyle = function(genericCapStyle) {
	return null;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeJointStyle = function(genericJointStyle) {
	return null;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
cocktailCore.domElement.js.GraphicDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.GraphicDOMElement.__name__ = ["cocktailCore","domElement","js","GraphicDOMElement"];
cocktailCore.domElement.js.GraphicDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype ) cocktailCore.domElement.js.GraphicDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype[k];
cocktailCore.domElement.js.GraphicDOMElement.prototype.setWidth = function(value) {
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setWidth.call(this,value);
	if(this._style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
		var canvasContext = this.getContext();
		var imageData = canvasContext.getImageData(0,0,value,this.getHeight());
		this._nativeElement.width = value;
		canvasContext.putImageData(imageData,0,0);
	}
	return value;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getWidth = function() {
	return Std.parseInt(this._nativeElement.width);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.setHeight = function(value) {
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setHeight.call(this,value);
	if(this._style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
		var canvasContext = this.getContext();
		var imageData = canvasContext.getImageData(0,0,this.getWidth(),value);
		this._nativeElement.height = value;
		canvasContext.putImageData(imageData,0,0);
	}
	return value;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getHeight = function() {
	return Std.parseInt(this._nativeElement.height);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.beginFill = function(fillStyle,lineStyle) {
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill.call(this,fillStyle,lineStyle);
	if(fillStyle == null) fillStyle = cocktail.domElement.FillStyleValue.none;
	if(lineStyle == null) lineStyle = cocktail.domElement.LineStyleValue.none;
	this.setFillStyle(fillStyle);
	this.setLineStyle(lineStyle);
	var canvasContext = this.getContext();
	canvasContext.beginPath();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.endFill = function() {
	var canvasContext = this.getContext();
	canvasContext.closePath();
	canvasContext.fill();
	canvasContext.stroke();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.clear = function() {
	var canvasContext = this.getContext();
	canvasContext.clearRect(0,0,this.getWidth(),this.getHeight());
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.setFillStyle = function(fillStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.setLineStyle = function(lineStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.drawImage = function(source,destinationPoint,sourceRect) {
	if(destinationPoint == null) destinationPoint = { x : 0.0, y : 0.0};
	if(sourceRect == null) {
		var width = source.getWidth();
		var height = source.getHeight();
		sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
	}
	var canvasContext = this.getContext();
	canvasContext.drawImage(source.getNativeElement(),sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height,destinationPoint.x,destinationPoint.y,sourceRect.width,sourceRect.height);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.lineTo = function(x,y) {
	var canvasContext = this.getContext();
	canvasContext.lineTo(x,y);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.moveTo = function(x,y) {
	var canvasContext = this.getContext();
	canvasContext.moveTo(x,y);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.curveTo = function(controlX,controlY,x,y) {
	var canvasContext = this.getContext();
	canvasContext.quadraticCurveTo(controlX,controlY,x,y);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeAlpha = function(genericAlpha) {
	return genericAlpha * 0.01;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeRatio = function(genericRatio) {
	return genericRatio * 0.01;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeCapStyle = function(genericCapStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeJointStyle = function(genericJointStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.colorStopToRGBA = function(colorStop) {
	var rgb = this.hexToRGB(this.getHexColor(colorStop.color));
	return "rgba(" + rgb.red + "," + rgb.green + "," + rgb.blue + "," + this.toNativeAlpha(colorStop.alpha) + ")";
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getHexColor = function(color) {
	var hexColor = StringTools.hex(color);
	while(hexColor.length < 6) hexColor = "0" + hexColor;
	return "#" + hexColor;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.hexToRGB = function(hex) {
	var hexCopy = hex;
	var hexCopy1 = hexCopy.substr(1);
	var rgb = { red : Std.parseInt("0x" + hexCopy1.substr(0,2)), green : Std.parseInt("0x" + hexCopy1.substr(2,2)), blue : Std.parseInt("0x" + hexCopy1.substr(4,2))};
	return rgb;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.initLineStyle = function(lineStyleData) {
	var canvasContext = this.getContext();
	canvasContext.lineWidth = lineStyleData.thickness;
	canvasContext.lineCap = this.toNativeCapStyle(lineStyleData.capStyle);
	canvasContext.lineJoin = this.toNativeJointStyle(lineStyleData.jointStyle);
	canvasContext.miterLimit = lineStyleData.miterLimit;
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getContext = function() {
	return this._nativeElement.getContext("2d");
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getCanvasPattern = function(imageDOMElement,repeat) {
	var canvasContext = this.getContext();
	var repeatValue = "";
	if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
	return canvasContext.createPattern(imageDOMElement.getNativeElement(),repeatValue);
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getGradient = function(gradientStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.__class__ = cocktailCore.domElement.js.GraphicDOMElement;
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator = function(p) {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementCreator"];
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype.createNativeElement = function(nativeElementType) {
	return null;
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype.__class__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
cocktailCore.style.positioner.FixedPositioner = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.FixedPositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.FixedPositioner.prototype.__class__ = cocktailCore.style.positioner.FixedPositioner;
components.richList.StyleApp = function() { }
components.richList.StyleApp.__name__ = ["components","richList","StyleApp"];
components.richList.StyleApp.initStyle = function(domElement) {
	var computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
	domElement.getStyle().setComputedStyle(computedStyle);
}
components.richList.StyleApp.getDefaultStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
}
components.richList.StyleApp.getCellStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(18)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(10)));
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#BDBDCE"));
}
components.richList.StyleApp.getCellImageStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setWidth(domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(57))));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
components.richList.StyleApp.getCellTextStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(57)));
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#BDBDCE"));
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
}
components.richList.StyleApp.getCellMouseOverStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#DDDDDD"));
}
components.richList.StyleApp.getCellMouseOutStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#BDBDCE"));
}
components.richList.StyleApp.getCellMouseDownStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.white));
}
components.richList.StyleApp.getCellMouseUpStyle = function(domElement) {
	components.richList.StyleApp.initStyle(domElement);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#BDBDCE"));
}
components.richList.StyleApp.prototype.__class__ = components.richList.StyleApp;
if(!cocktail.resource) cocktail.resource = {}
cocktail.resource.LoadingTypeValue = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",1];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.ResourceLoaderManager = function(p) {
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
cocktail.resource.ResourceLoaderManager.prototype.__class__ = cocktail.resource.ResourceLoaderManager;
cocktailCore.nativeElement.js.NativeElementCreator = function(p) {
	if( p === $_ ) return;
	cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.call(this);
}
cocktailCore.nativeElement.js.NativeElementCreator.__name__ = ["cocktailCore","nativeElement","js","NativeElementCreator"];
cocktailCore.nativeElement.js.NativeElementCreator.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
for(var k in cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype ) cocktailCore.nativeElement.js.NativeElementCreator.prototype[k] = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype[k];
cocktailCore.nativeElement.js.NativeElementCreator.prototype.createNativeElement = function(nativeElementType) {
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
	case 4:
		var name = $e[2];
		nativeElement = js.Lib.document.createElement(name);
		break;
	}
	return nativeElement;
}
cocktailCore.nativeElement.js.NativeElementCreator.prototype.__class__ = cocktailCore.nativeElement.js.NativeElementCreator;
if(!cocktail.domElement) cocktail.domElement = {}
cocktail.domElement.FillStyleValue = { __ename__ : ["cocktail","domElement","FillStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.domElement.FillStyleValue.none = ["none",0];
cocktail.domElement.FillStyleValue.none.toString = $estr;
cocktail.domElement.FillStyleValue.none.__enum__ = cocktail.domElement.FillStyleValue;
cocktail.domElement.FillStyleValue.monochrome = function(colorStop) { var $x = ["monochrome",1,colorStop]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.FillStyleValue.gradient = function(gradientStyle) { var $x = ["gradient",2,gradientStyle]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.FillStyleValue.bitmap = function(imageDOMElement,repeat) { var $x = ["bitmap",3,imageDOMElement,repeat]; $x.__enum__ = cocktail.domElement.FillStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue = { __ename__ : ["cocktail","domElement","LineStyleValue"], __constructs__ : ["none","monochrome","gradient","bitmap"] }
cocktail.domElement.LineStyleValue.none = ["none",0];
cocktail.domElement.LineStyleValue.none.toString = $estr;
cocktail.domElement.LineStyleValue.none.__enum__ = cocktail.domElement.LineStyleValue;
cocktail.domElement.LineStyleValue.monochrome = function(colorStop,lineStyle) { var $x = ["monochrome",1,colorStop,lineStyle]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue.gradient = function(gradientStyle,lineStyle) { var $x = ["gradient",2,gradientStyle,lineStyle]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.LineStyleValue.bitmap = function(imageDOMElement,lineStyle,repeat) { var $x = ["bitmap",3,imageDOMElement,lineStyle,repeat]; $x.__enum__ = cocktail.domElement.LineStyleValue; $x.toString = $estr; return $x; }
cocktail.domElement.GradientTypeValue = { __ename__ : ["cocktail","domElement","GradientTypeValue"], __constructs__ : ["linear","radial"] }
cocktail.domElement.GradientTypeValue.linear = ["linear",0];
cocktail.domElement.GradientTypeValue.linear.toString = $estr;
cocktail.domElement.GradientTypeValue.linear.__enum__ = cocktail.domElement.GradientTypeValue;
cocktail.domElement.GradientTypeValue.radial = ["radial",1];
cocktail.domElement.GradientTypeValue.radial.toString = $estr;
cocktail.domElement.GradientTypeValue.radial.__enum__ = cocktail.domElement.GradientTypeValue;
cocktail.domElement.CapsStyleValue = { __ename__ : ["cocktail","domElement","CapsStyleValue"], __constructs__ : ["none","square","round"] }
cocktail.domElement.CapsStyleValue.none = ["none",0];
cocktail.domElement.CapsStyleValue.none.toString = $estr;
cocktail.domElement.CapsStyleValue.none.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.CapsStyleValue.square = ["square",1];
cocktail.domElement.CapsStyleValue.square.toString = $estr;
cocktail.domElement.CapsStyleValue.square.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.CapsStyleValue.round = ["round",2];
cocktail.domElement.CapsStyleValue.round.toString = $estr;
cocktail.domElement.CapsStyleValue.round.__enum__ = cocktail.domElement.CapsStyleValue;
cocktail.domElement.JointStyleValue = { __ename__ : ["cocktail","domElement","JointStyleValue"], __constructs__ : ["miter","round","bevel"] }
cocktail.domElement.JointStyleValue.miter = ["miter",0];
cocktail.domElement.JointStyleValue.miter.toString = $estr;
cocktail.domElement.JointStyleValue.miter.__enum__ = cocktail.domElement.JointStyleValue;
cocktail.domElement.JointStyleValue.round = ["round",1];
cocktail.domElement.JointStyleValue.round.toString = $estr;
cocktail.domElement.JointStyleValue.round.__enum__ = cocktail.domElement.JointStyleValue;
cocktail.domElement.JointStyleValue.bevel = ["bevel",2];
cocktail.domElement.JointStyleValue.bevel.toString = $estr;
cocktail.domElement.JointStyleValue.bevel.__enum__ = cocktail.domElement.JointStyleValue;
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
	cocktailCore.style.computer.BoxStylesComputer.prototype.measurePositionOffsets.call(this,style,containingDOMElementData);
	if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) {
		if(style.getLeft() != cocktail.style.PositionOffsetStyleValue.auto && style.getRight() != cocktail.style.PositionOffsetStyleValue.auto) {
			var computedStyle = style.getComputedStyle();
			style.getComputedStyle().width = containingDOMElementData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.marginLeft - computedStyle.marginRight;
		}
	}
	if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
		if(style.getTop() != cocktail.style.PositionOffsetStyleValue.auto && style.getBottom() != cocktail.style.PositionOffsetStyleValue.auto) {
			var computedStyle = style.getComputedStyle();
			style.getComputedStyle().height = containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		}
	}
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer;
cocktailCore.style.formatter.InlineFormattingContext = function(domElement,previousFormattingContext) {
	if( domElement === $_ ) return;
	this._firstLineLaidOut = false;
	this._domElementInLineBox = new Array();
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
}
cocktailCore.style.formatter.InlineFormattingContext.__name__ = ["cocktailCore","style","formatter","InlineFormattingContext"];
cocktailCore.style.formatter.InlineFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
for(var k in cocktailCore.style.formatter.FormattingContext.prototype ) cocktailCore.style.formatter.InlineFormattingContext.prototype[k] = cocktailCore.style.formatter.FormattingContext.prototype[k];
cocktailCore.style.formatter.InlineFormattingContext.prototype._domElementInLineBox = null;
cocktailCore.style.formatter.InlineFormattingContext.prototype._firstLineLaidOut = null;
cocktailCore.style.formatter.InlineFormattingContext.prototype.destroy = function() {
	this.startNewLine(0,true);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.insert = function(domElement) {
	var remainingWidth = this.getRemainingLineWidth();
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
	this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktailCore.style.InlineBoxValue.domElement});
	cocktailCore.style.formatter.FormattingContext.prototype.insert.call(this,domElement);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.insertSpace = function(domElement) {
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
	this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktailCore.style.InlineBoxValue.space});
	cocktailCore.style.formatter.FormattingContext.prototype.insertSpace.call(this,domElement);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.place = function(domElement) {
	cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement);
	this._flowData.x += domElement.getOffsetWidth();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.startNewLine = function(domElementWidth,isLastLine) {
	if(isLastLine == null) isLastLine = false;
	if(this._domElementInLineBox.length > 0) {
		this.removeSpaces();
		var lineBoxHeight = this.computeLineBoxHeight();
		this.alignText(this._firstLineLaidOut == false,isLastLine);
		this._domElementInLineBox = new Array();
		this._flowData.y += lineBoxHeight;
		this._flowData.y = this._floatsManager.getFirstAvailableY(this._flowData,domElementWidth,this._containingDOMElementWidth);
		this._flowData.totalHeight = this._flowData.y;
		if(this._floatsManager.getLeftFloatOffset(this._flowData.y) > this._flowData.xOffset) this.getFlowData().x = this._floatsManager.getLeftFloatOffset(this._flowData.y); else this._flowData.x = this._flowData.xOffset;
		this._firstLineLaidOut = true;
	} else {
		this._flowData.y = this._floatsManager.getFirstAvailableY(this._flowData,domElementWidth,this._containingDOMElementWidth);
		if(this._floatsManager.getLeftFloatOffset(this._flowData.y) > this._flowData.xOffset) this.getFlowData().x = this._floatsManager.getLeftFloatOffset(this._flowData.y); else this._flowData.x = this._flowData.xOffset;
	}
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.clearFloat = function(clear,isFloat) {
	if(isFloat == true) this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.placeFloat = function(domElement,floatData) {
	cocktailCore.style.formatter.FormattingContext.prototype.placeFloat.call(this,domElement,floatData);
	if(this._floatsManager.getLeftFloatOffset(this._flowData.y) > this._flowData.xOffset) this.getFlowData().x = this._floatsManager.getLeftFloatOffset(this._flowData.y); else this._flowData.x = this._flowData.xOffset;
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.removeSpaces = function() {
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
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignText = function(firstLine,isLastLine) {
	var concatenatedLength = 0;
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		concatenatedLength += this._domElementInLineBox[i].domElement.getOffsetWidth();
	}
	var remainingSpace;
	var localFlow;
	if(firstLine == true) {
		remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._containingDOMElement.getStyle().getComputedStyle().textIndent - this._floatsManager.getLeftFloatOffset(this._flowData.y) - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
		localFlow = this._containingDOMElement.getStyle().getComputedStyle().textIndent;
	} else {
		remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._flowData.y) - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
		localFlow = 0;
	}
	localFlow += this._floatsManager.getLeftFloatOffset(this._flowData.y) + this._flowData.xOffset;
	switch( (this._containingDOMElement.getStyle().getComputedStyle().textAlign)[1] ) {
	case 0:
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 1:
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft + remainingSpace);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 2:
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,Math.round(remainingSpace / 2) + localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 3:
		if(isLastLine == true) {
			var _g1 = 0, _g = this._domElementInLineBox.length;
			while(_g1 < _g) {
				var i = _g1++;
				this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
				localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
			}
		} else {
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
				switch( (this._domElementInLineBox[i].domElementType)[1] ) {
				case 1:
					var spaceWidth = Math.round(remainingSpace / spacesNumber);
					spacesNumber--;
					remainingSpace -= spaceWidth;
					localFlow += spaceWidth;
					break;
				default:
				}
				this._domElementInLineBox[i].domElement.getStyle().setNativeX(this._domElementInLineBox[i].domElement,localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
				localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
			}
		}
		break;
	}
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.computeLineBoxHeight = function() {
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
		domElement.getStyle().setNativeY(domElement,Math.round(lineBoxAscent) + Math.round(domElement.getStyle().getComputedStyle().verticalAlign) + this._flowData.y + domElement.getStyle().getComputedStyle().marginTop);
		if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) domElement.getStyle().setNativeY(domElement,domElement.getStyle().getNativeY(domElement) - domElement.getOffsetHeight());
	}
	return Math.round(lineBoxHeight);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.__class__ = cocktailCore.style.formatter.InlineFormattingContext;
WebAppStyle = function() { }
WebAppStyle.__name__ = ["WebAppStyle"];
WebAppStyle.initStyle = function(domElement) {
	var computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
	domElement.getStyle().setComputedStyle(computedStyle);
}
WebAppStyle.getDefaultStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(130));
}
WebAppStyle.getBodyStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
}
WebAppStyle.getMainContainerStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
}
WebAppStyle.getPageContainerStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.auto);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.auto);
	domElement.getStyle().setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(130));
}
WebAppStyle.getHomePageStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
}
WebAppStyle.getPageStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
}
WebAppStyle.getBgStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.percent(130));
}
WebAppStyle.getHeaderStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
}
WebAppStyle.getHeaderTileStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
}
WebAppStyle.getHeaderTextStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(43)));
}
WebAppStyle.getBackButtonStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(6)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(10)));
}
WebAppStyle.getBackButtonTextStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("#EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(30)));
}
WebAppStyle.getBackButtonImageStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
}
WebAppStyle.getTextContentStyle = function(domElement) {
	WebAppStyle.initStyle(domElement);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
}
WebAppStyle.prototype.__class__ = WebAppStyle;
cocktail.geom.RegistrationPointValue = { __ename__ : ["cocktail","geom","RegistrationPointValue"], __constructs__ : ["constant","point"] }
cocktail.geom.RegistrationPointValue.constant = function(registrationPointX,registrationPointY) { var $x = ["constant",0,registrationPointX,registrationPointY]; $x.__enum__ = cocktail.geom.RegistrationPointValue; $x.toString = $estr; return $x; }
cocktail.geom.RegistrationPointValue.point = function(point) { var $x = ["point",1,point]; $x.__enum__ = cocktail.geom.RegistrationPointValue; $x.toString = $estr; return $x; }
cocktail.geom.RegistrationPointXValue = { __ename__ : ["cocktail","geom","RegistrationPointXValue"], __constructs__ : ["left","center","right"] }
cocktail.geom.RegistrationPointXValue.left = ["left",0];
cocktail.geom.RegistrationPointXValue.left.toString = $estr;
cocktail.geom.RegistrationPointXValue.left.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointXValue.center = ["center",1];
cocktail.geom.RegistrationPointXValue.center.toString = $estr;
cocktail.geom.RegistrationPointXValue.center.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointXValue.right = ["right",2];
cocktail.geom.RegistrationPointXValue.right.toString = $estr;
cocktail.geom.RegistrationPointXValue.right.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointYValue = { __ename__ : ["cocktail","geom","RegistrationPointYValue"], __constructs__ : ["top","middle","bottom"] }
cocktail.geom.RegistrationPointYValue.top = ["top",0];
cocktail.geom.RegistrationPointYValue.top.toString = $estr;
cocktail.geom.RegistrationPointYValue.top.__enum__ = cocktail.geom.RegistrationPointYValue;
cocktail.geom.RegistrationPointYValue.middle = ["middle",1];
cocktail.geom.RegistrationPointYValue.middle.toString = $estr;
cocktail.geom.RegistrationPointYValue.middle.__enum__ = cocktail.geom.RegistrationPointYValue;
cocktail.geom.RegistrationPointYValue.bottom = ["bottom",2];
cocktail.geom.RegistrationPointYValue.bottom.toString = $estr;
cocktail.geom.RegistrationPointYValue.bottom.__enum__ = cocktail.geom.RegistrationPointYValue;
if(!cocktail.style) cocktail.style = {}
cocktail.style.FontSizeStyleValue = { __ename__ : ["cocktail","style","FontSizeStyleValue"], __constructs__ : ["length","percentage","absoluteSize","relativeSize"] }
cocktail.style.FontSizeStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.absoluteSize = function(value) { var $x = ["absoluteSize",2,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontSizeStyleValue.relativeSize = function(value) { var $x = ["relativeSize",3,value]; $x.__enum__ = cocktail.style.FontSizeStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontWeightStyleValue = { __ename__ : ["cocktail","style","FontWeightStyleValue"], __constructs__ : ["normal","bold"] }
cocktail.style.FontWeightStyleValue.normal = ["normal",0];
cocktail.style.FontWeightStyleValue.normal.toString = $estr;
cocktail.style.FontWeightStyleValue.normal.__enum__ = cocktail.style.FontWeightStyleValue;
cocktail.style.FontWeightStyleValue.bold = ["bold",1];
cocktail.style.FontWeightStyleValue.bold.toString = $estr;
cocktail.style.FontWeightStyleValue.bold.__enum__ = cocktail.style.FontWeightStyleValue;
cocktail.style.FontStyleStyleValue = { __ename__ : ["cocktail","style","FontStyleStyleValue"], __constructs__ : ["normal","italic"] }
cocktail.style.FontStyleStyleValue.normal = ["normal",0];
cocktail.style.FontStyleStyleValue.normal.toString = $estr;
cocktail.style.FontStyleStyleValue.normal.__enum__ = cocktail.style.FontStyleStyleValue;
cocktail.style.FontStyleStyleValue.italic = ["italic",1];
cocktail.style.FontStyleStyleValue.italic.toString = $estr;
cocktail.style.FontStyleStyleValue.italic.__enum__ = cocktail.style.FontStyleStyleValue;
cocktail.style.FontFamilyStyleValue = { __ename__ : ["cocktail","style","FontFamilyStyleValue"], __constructs__ : ["familyName","genericFamily"] }
cocktail.style.FontFamilyStyleValue.familyName = function(name) { var $x = ["familyName",0,name]; $x.__enum__ = cocktail.style.FontFamilyStyleValue; $x.toString = $estr; return $x; }
cocktail.style.FontFamilyStyleValue.genericFamily = function(genericName) { var $x = ["genericFamily",1,genericName]; $x.__enum__ = cocktail.style.FontFamilyStyleValue; $x.toString = $estr; return $x; }
cocktail.style.GenericFontFamilyValue = { __ename__ : ["cocktail","style","GenericFontFamilyValue"], __constructs__ : ["serif","sansSerif","monospace"] }
cocktail.style.GenericFontFamilyValue.serif = ["serif",0];
cocktail.style.GenericFontFamilyValue.serif.toString = $estr;
cocktail.style.GenericFontFamilyValue.serif.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.GenericFontFamilyValue.sansSerif = ["sansSerif",1];
cocktail.style.GenericFontFamilyValue.sansSerif.toString = $estr;
cocktail.style.GenericFontFamilyValue.sansSerif.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.GenericFontFamilyValue.monospace = ["monospace",2];
cocktail.style.GenericFontFamilyValue.monospace.toString = $estr;
cocktail.style.GenericFontFamilyValue.monospace.__enum__ = cocktail.style.GenericFontFamilyValue;
cocktail.style.FontVariantStyleValue = { __ename__ : ["cocktail","style","FontVariantStyleValue"], __constructs__ : ["normal","smallCaps"] }
cocktail.style.FontVariantStyleValue.normal = ["normal",0];
cocktail.style.FontVariantStyleValue.normal.toString = $estr;
cocktail.style.FontVariantStyleValue.normal.__enum__ = cocktail.style.FontVariantStyleValue;
cocktail.style.FontVariantStyleValue.smallCaps = ["smallCaps",1];
cocktail.style.FontVariantStyleValue.smallCaps.toString = $estr;
cocktail.style.FontVariantStyleValue.smallCaps.__enum__ = cocktail.style.FontVariantStyleValue;
cocktail.style.WhiteSpaceStyleValue = { __ename__ : ["cocktail","style","WhiteSpaceStyleValue"], __constructs__ : ["normal","pre","nowrap","preWrap","preLine"] }
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
cocktail.style.LetterSpacingStyleValue = { __ename__ : ["cocktail","style","LetterSpacingStyleValue"], __constructs__ : ["normal","length"] }
cocktail.style.LetterSpacingStyleValue.normal = ["normal",0];
cocktail.style.LetterSpacingStyleValue.normal.toString = $estr;
cocktail.style.LetterSpacingStyleValue.normal.__enum__ = cocktail.style.LetterSpacingStyleValue;
cocktail.style.LetterSpacingStyleValue.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.style.LetterSpacingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.WordSpacingStyleValue = { __ename__ : ["cocktail","style","WordSpacingStyleValue"], __constructs__ : ["normal","length"] }
cocktail.style.WordSpacingStyleValue.normal = ["normal",0];
cocktail.style.WordSpacingStyleValue.normal.toString = $estr;
cocktail.style.WordSpacingStyleValue.normal.__enum__ = cocktail.style.WordSpacingStyleValue;
cocktail.style.WordSpacingStyleValue.length = function(value) { var $x = ["length",1,value]; $x.__enum__ = cocktail.style.WordSpacingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextIndentStyleValue = { __ename__ : ["cocktail","style","TextIndentStyleValue"], __constructs__ : ["length","percentage"] }
cocktail.style.TextIndentStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TextIndentStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextIndentStyleValue.percentage = function(value) { var $x = ["percentage",1,value]; $x.__enum__ = cocktail.style.TextIndentStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TextAlignStyleValue = { __ename__ : ["cocktail","style","TextAlignStyleValue"], __constructs__ : ["left","right","center","justify"] }
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
cocktail.style.TextTransformStyleValue = { __ename__ : ["cocktail","style","TextTransformStyleValue"], __constructs__ : ["capitalize","uppercase","lowercase","none"] }
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
cocktail.style.LineHeightStyleValue = { __ename__ : ["cocktail","style","LineHeightStyleValue"], __constructs__ : ["normal","number","length","percentage"] }
cocktail.style.LineHeightStyleValue.normal = ["normal",0];
cocktail.style.LineHeightStyleValue.normal.toString = $estr;
cocktail.style.LineHeightStyleValue.normal.__enum__ = cocktail.style.LineHeightStyleValue;
cocktail.style.LineHeightStyleValue.number = function(value) { var $x = ["number",1,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.LineHeightStyleValue.length = function(value) { var $x = ["length",2,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.LineHeightStyleValue.percentage = function(value) { var $x = ["percentage",3,value]; $x.__enum__ = cocktail.style.LineHeightStyleValue; $x.toString = $estr; return $x; }
cocktail.style.VerticalAlignStyleValue = { __ename__ : ["cocktail","style","VerticalAlignStyleValue"], __constructs__ : ["baseline","sub","superStyle","top","textTop","middle","bottom","textBottom","percent","length"] }
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
cocktail.style.MarginStyleValue = { __ename__ : ["cocktail","style","MarginStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.MarginStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.auto = ["auto",2];
cocktail.style.MarginStyleValue.auto.toString = $estr;
cocktail.style.MarginStyleValue.auto.__enum__ = cocktail.style.MarginStyleValue;
cocktail.style.PaddingStyleValue = { __ename__ : ["cocktail","style","PaddingStyleValue"], __constructs__ : ["length","percent"] }
cocktail.style.PaddingStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PaddingStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue = { __ename__ : ["cocktail","style","DimensionStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.DimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.auto = ["auto",2];
cocktail.style.DimensionStyleValue.auto.toString = $estr;
cocktail.style.DimensionStyleValue.auto.__enum__ = cocktail.style.DimensionStyleValue;
cocktail.style.DisplayStyleValue = { __ename__ : ["cocktail","style","DisplayStyleValue"], __constructs__ : ["block","inlineBlock","inlineStyle","none"] }
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
cocktail.style.FloatStyleValue = { __ename__ : ["cocktail","style","FloatStyleValue"], __constructs__ : ["left","right","none"] }
cocktail.style.FloatStyleValue.left = ["left",0];
cocktail.style.FloatStyleValue.left.toString = $estr;
cocktail.style.FloatStyleValue.left.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.FloatStyleValue.right = ["right",1];
cocktail.style.FloatStyleValue.right.toString = $estr;
cocktail.style.FloatStyleValue.right.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.FloatStyleValue.none = ["none",2];
cocktail.style.FloatStyleValue.none.toString = $estr;
cocktail.style.FloatStyleValue.none.__enum__ = cocktail.style.FloatStyleValue;
cocktail.style.ClearStyleValue = { __ename__ : ["cocktail","style","ClearStyleValue"], __constructs__ : ["none","left","right","both"] }
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
cocktail.style.PositionStyleValue = { __ename__ : ["cocktail","style","PositionStyleValue"], __constructs__ : ["staticStyle","relative","absolute","fixed"] }
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
cocktail.style.PositionOffsetStyleValue = { __ename__ : ["cocktail","style","PositionOffsetStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.PositionOffsetStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.auto = ["auto",2];
cocktail.style.PositionOffsetStyleValue.auto.toString = $estr;
cocktail.style.PositionOffsetStyleValue.auto.__enum__ = cocktail.style.PositionOffsetStyleValue;
cocktail.style.ConstrainedDimensionStyleValue = { __ename__ : ["cocktail","style","ConstrainedDimensionStyleValue"], __constructs__ : ["length","percent","none"] }
cocktail.style.ConstrainedDimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.none = ["none",2];
cocktail.style.ConstrainedDimensionStyleValue.none.toString = $estr;
cocktail.style.ConstrainedDimensionStyleValue.none.__enum__ = cocktail.style.ConstrainedDimensionStyleValue;
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
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
haxe.Timer = function(time_ms) {
	if( time_ms === $_ ) return;
	this.id = haxe.Timer.arr.length;
	haxe.Timer.arr[this.id] = this;
	this.timerId = window.setInterval("haxe.Timer.arr[" + this.id + "].run();",time_ms);
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
	haxe.Timer.arr[this.id] = null;
	if(this.id > 100 && this.id == haxe.Timer.arr.length - 1) {
		var p = this.id - 1;
		while(p >= 0 && haxe.Timer.arr[p] == null) p--;
		haxe.Timer.arr = haxe.Timer.arr.slice(0,p + 1);
	}
	this.id = null;
}
haxe.Timer.prototype.run = function() {
}
haxe.Timer.prototype.__class__ = haxe.Timer;
if(!cocktail.unit) cocktail.unit = {}
cocktail.unit.LengthValue = { __ename__ : ["cocktail","unit","LengthValue"], __constructs__ : ["px","cm","mm","pt","pc","_in","em","ex"] }
cocktail.unit.LengthValue.px = function(value) { var $x = ["px",0,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.cm = function(value) { var $x = ["cm",1,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.mm = function(value) { var $x = ["mm",2,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.pt = function(value) { var $x = ["pt",3,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.pc = function(value) { var $x = ["pc",4,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue._in = function(value) { var $x = ["_in",5,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.em = function(value) { var $x = ["em",6,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.LengthValue.ex = function(value) { var $x = ["ex",7,value]; $x.__enum__ = cocktail.unit.LengthValue; $x.toString = $estr; return $x; }
cocktail.unit.FontSizeAbsoluteSizeValue = { __ename__ : ["cocktail","unit","FontSizeAbsoluteSizeValue"], __constructs__ : ["xxSmall","xSmall","small","medium","large","xLarge","xxLarge"] }
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
cocktail.unit.FontSizeRelativeSizeValue = { __ename__ : ["cocktail","unit","FontSizeRelativeSizeValue"], __constructs__ : ["larger","smaller"] }
cocktail.unit.FontSizeRelativeSizeValue.larger = ["larger",0];
cocktail.unit.FontSizeRelativeSizeValue.larger.toString = $estr;
cocktail.unit.FontSizeRelativeSizeValue.larger.__enum__ = cocktail.unit.FontSizeRelativeSizeValue;
cocktail.unit.FontSizeRelativeSizeValue.smaller = ["smaller",1];
cocktail.unit.FontSizeRelativeSizeValue.smaller.toString = $estr;
cocktail.unit.FontSizeRelativeSizeValue.smaller.__enum__ = cocktail.unit.FontSizeRelativeSizeValue;
cocktail.unit.ColorValue = { __ename__ : ["cocktail","unit","ColorValue"], __constructs__ : ["RGB","hex","keyword"] }
cocktail.unit.ColorValue.RGB = function(red,green,blue) { var $x = ["RGB",0,red,green,blue]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.hex = function(value) { var $x = ["hex",1,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorValue.keyword = function(value) { var $x = ["keyword",2,value]; $x.__enum__ = cocktail.unit.ColorValue; $x.toString = $estr; return $x; }
cocktail.unit.ColorKeywordValue = { __ename__ : ["cocktail","unit","ColorKeywordValue"], __constructs__ : ["aqua","black","blue","fuchsia","gray","green","lime","maroon","navy","olive","orange","purple","red","silver","teal","white","yellow"] }
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
cocktailCore.resource.js.LibraryLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.LibraryLoader.__name__ = ["cocktailCore","resource","js","LibraryLoader"];
cocktailCore.resource.js.LibraryLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.LibraryLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.LibraryLoader.prototype.doLoad = function(url) {
	var scrptE = js.Lib.document.createElement("script");
	scrptE.setAttribute("type","text/javascript");
	scrptE.setAttribute("language","JavaScript");
	scrptE.setAttribute("src",url);
	scrptE.onload = $closure(this,"onLoadComplete");
	scrptE.onerror = $closure(this,"onLoadError");
	js.Lib.document.getElementsByTagName("head")[0].appendChild(scrptE);
}
cocktailCore.resource.js.LibraryLoader.prototype.onLoadComplete = function(data) {
	this._onLoadCompleteCallback(null);
}
cocktailCore.resource.js.LibraryLoader.prototype.__class__ = cocktailCore.resource.js.LibraryLoader;
if(!cocktailCore.mouse) cocktailCore.mouse = {}
if(!cocktailCore.mouse["abstract"]) cocktailCore.mouse["abstract"] = {}
cocktailCore.mouse.abstract.AbstractMouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	this.setNativeMouseListeners(nativeElement);
}
cocktailCore.mouse.abstract.AbstractMouse.__name__ = ["cocktailCore","mouse","abstract","AbstractMouse"];
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDown = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseUp = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOver = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOut = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseMove = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDoubleClick = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.setNativeMouseListeners = function(nativeElement) {
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.unsetNativeMouseListeners = function(nativeElement) {
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDown = function(event) {
	if(this.onMouseDown != null) this.onMouseDown(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseUp = function(event) {
	if(this.onMouseUp != null) this.onMouseUp(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOver = function(event) {
	if(this.onMouseOver != null) this.onMouseOver(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOut = function(event) {
	if(this.onMouseOut != null) this.onMouseOut(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseMove = function(event) {
	if(this.onMouseMove != null) this.onMouseMove(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDoubleClick = function(event) {
	if(this.onMouseDoubleClick != null) this.onMouseDoubleClick(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getMouseData = function(event) {
	return null;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.__class__ = cocktailCore.mouse.abstract.AbstractMouse;
ApplicationStructure = function(p) {
	if( p === $_ ) return;
	this.pagesContainer = Utils.getContainer();
	this.createAllPages();
}
ApplicationStructure.__name__ = ["ApplicationStructure"];
ApplicationStructure.prototype.pagesContainer = null;
ApplicationStructure.prototype._homePage = null;
ApplicationStructure.prototype._calListPage = null;
ApplicationStructure.prototype._dayPage = null;
ApplicationStructure.prototype._artistListPage = null;
ApplicationStructure.prototype._albumListPage = null;
ApplicationStructure.prototype._songListPage = null;
ApplicationStructure.prototype._songPage = null;
ApplicationStructure.prototype._noteListPage = null;
ApplicationStructure.prototype._notePage = null;
ApplicationStructure.prototype._creditsPage = null;
ApplicationStructure.prototype._currentPage = null;
ApplicationStructure.prototype.createAllPages = function() {
	this._dayPage = this.createHeaderContentPage("Day","This is what I have planned today");
	this._calListPage = this.createHeaderListPage("Calendar",[{ text : "June 1st", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 2nd", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 3rd", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 4th", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 5th", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage}]);
	this._songPage = this.createHeaderContentPage("Song","You are listening to this song");
	this._songListPage = this.createHeaderListPage("Artist - Album",[{ text : "Song 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage}]);
	this._albumListPage = this.createHeaderListPage("Albums",[{ text : "Album 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage}]);
	this._artistListPage = this.createHeaderListPage("Artists",[{ text : "Artist 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage}]);
	this._notePage = this.createHeaderContentPage("Note","This is the content of the note");
	this._noteListPage = this.createHeaderListPage("Notes",[{ text : "Note 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 6", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 7", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 8", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 9", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 10", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 11", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 12", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 13", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 14", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 15", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 16", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage}]);
	this._creditsPage = this.createHeaderListPage("Credits",[{ text : "made with Cocktail", imagePath : "images/cocktail.jpg", action : "goToUrl", actionTarget : "http://www.silexlabs.org/groups/labs/cocktail/"},{ text : "using haXe language", imagePath : "images/haxe.png", action : "goToUrl", actionTarget : "http://haxe.org/"},{ text : "done for Silex Labs", imagePath : "images/silex_labs.jpg", action : "goToUrl", actionTarget : "http://www.silexlabs.org/"},{ text : "by Raphael Harmel", imagePath : "images/google+.ico", action : "goToUrl", actionTarget : "http://plus.google.com/104338051403006926915"},{ text : "source Code", imagePath : "images/github.jpg", action : "goToUrl", actionTarget : "https://github.com/silexlabs/Cocktail/tree/develop/demo/simple-webapp"}]);
	this._homePage = this.createHomePage([{ text : "Cal", imagePath : "images/NavButtonCalendar.png", action : "goToPage", actionTarget : this._calListPage},{ text : "Music", imagePath : "images/NavButtonMusic.png", action : "goToPage", actionTarget : this._artistListPage},{ text : "Notes", imagePath : "images/NavButtonNotes.png", action : "goToPage", actionTarget : this._noteListPage},{ text : "Credits", imagePath : "images/NavButtonCredits.png", action : "goToPage", actionTarget : this._creditsPage}]);
	this._currentPage = this._homePage;
	this.pagesContainer.addChild(this._homePage);
}
ApplicationStructure.prototype.showPage = function(page) {
	this.pagesContainer.removeChild(this._currentPage);
	this.pagesContainer.addChild(page);
	this._currentPage = page;
}
ApplicationStructure.prototype.onChangeListCallback = function(cell) {
	if(cell.action == "goToPage") this.showPage(cell.actionTarget);
	if(cell.action == "goToUrl") this.goToUrl(cell.actionTarget);
}
ApplicationStructure.prototype.goToUrl = function(url) {
	js.Lib.window.open(url);
}
ApplicationStructure.prototype.createHomePage = function(cellDataArray) {
	var page = Utils.getContainer();
	var homeTilePath = "images/blackPixel.png";
	var backGround = new cocktailCore.domElement.js.ImageDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	WebAppStyle.getBgStyle(backGround);
	backGround.load(homeTilePath);
	var richList = this.createRichListHome(cellDataArray);
	richList.onChange = $closure(this,"onChangeListCallback");
	page.addChild(backGround);
	page.addChild(richList);
	WebAppStyle.getHomePageStyle(page);
	return page;
}
ApplicationStructure.prototype.createHeaderListPage = function(title,cellDataArray) {
	var page = Utils.getContainer();
	var header = this.createHeader(title);
	var richList = this.createArrowRichList(cellDataArray);
	richList.onChange = $closure(this,"onChangeListCallback");
	page.addChild(header);
	page.addChild(richList);
	WebAppStyle.getPageStyle(page);
	return page;
}
ApplicationStructure.prototype.createHeaderContentPage = function(title,content) {
	var page = Utils.getContainer();
	var header = this.createHeader(title);
	var textElement = new cocktailCore.textElement.js.TextElement(content);
	var textContainer = Utils.getContainer();
	textContainer.addText(textElement);
	WebAppStyle.getTextContentStyle(textContainer);
	page.addChild(header);
	page.addChild(textContainer);
	WebAppStyle.getPageStyle(page);
	return page;
}
ApplicationStructure.prototype.createEmbedContentPage = function(title,embeddedLink) {
	var page = Utils.getContainer();
	var header = this.createHeader(title);
	var embeddedElement = new cocktailCore.domElement.js.EmbeddedDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.custom("embed")));
	page.addChild(header);
	WebAppStyle.getPageStyle(page);
	return page;
}
ApplicationStructure.prototype.createHeader = function(title) {
	var header = Utils.getContainer();
	var headerTile = new cocktailCore.domElement.js.ImageDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	var headerTilePath = "images/H1.png";
	WebAppStyle.getHeaderTileStyle(headerTile);
	headerTile.load(headerTilePath);
	var backButtonContainer = Utils.getContainer();
	WebAppStyle.getBackButtonStyle(backButtonContainer);
	var backButtonArrowLeft = new cocktailCore.domElement.js.ImageDOMElement();
	WebAppStyle.getBackButtonImageStyle(backButtonArrowLeft);
	backButtonArrowLeft.load("images/blackButtonLeft.png");
	backButtonContainer.addChild(backButtonArrowLeft);
	var backButtonArrowRight = new cocktailCore.domElement.js.ImageDOMElement();
	WebAppStyle.getBackButtonImageStyle(backButtonArrowRight);
	backButtonArrowRight.load("images/blackButtonRight.png");
	backButtonContainer.addChild(backButtonArrowRight);
	var backButtonTextContainer = Utils.getContainer();
	WebAppStyle.getBackButtonTextStyle(backButtonTextContainer);
	var backButtonText = new cocktailCore.textElement.js.TextElement("Back");
	backButtonTextContainer.addText(backButtonText);
	backButtonContainer.addChild(backButtonTextContainer);
	backButtonContainer.setOnMouseUp($closure(this,"onBackButtonMouseUp"));
	var headerTitle = new cocktailCore.textElement.js.TextElement(title);
	var headerTitleContainer = Utils.getContainer();
	headerTitleContainer.addText(headerTitle);
	WebAppStyle.getHeaderTextStyle(headerTitleContainer);
	header.addChild(headerTile);
	header.addChild(headerTitleContainer);
	header.addChild(backButtonContainer);
	WebAppStyle.getHeaderStyle(header);
	return header;
}
ApplicationStructure.prototype.onImageLoadError = function(error) {
	haxe.Log.trace(error,{ fileName : "ApplicationStructure.hx", lineNumber : 422, className : "ApplicationStructure", methodName : "onImageLoadError"});
}
ApplicationStructure.prototype.createRichListHome = function(content) {
	var listData = components.richList.RichListUtils.createRichListModel();
	listData.content = content;
	var listStyle = { list : components.richList.StyleApp.getDefaultStyle, cell : components.richList.StyleApp.getCellStyle, cellImage : components.richList.StyleApp.getCellImageStyle, cellText : components.richList.StyleApp.getCellTextStyle, cellMouseOver : components.richList.StyleApp.getCellMouseOverStyle, cellMouseOut : components.richList.StyleApp.getCellMouseOutStyle, cellMouseDown : components.richList.StyleApp.getCellMouseDownStyle, cellMouseUp : components.richList.StyleApp.getCellMouseUpStyle};
	var list = new components.richList.RichList(listData,listStyle);
	return list;
}
ApplicationStructure.prototype.createArrowRichList = function(content) {
	var listData = components.richList.RichListUtils.createRichListModel();
	listData.content = content;
	var listStyle = { list : components.richList.StyleNormal.getDefaultStyle, cell : components.richList.StyleNormal.getCellStyle, cellImage : components.richList.StyleNormal.getCellImageStyle, cellText : components.richList.StyleNormal.getCellTextStyle, cellMouseOver : components.richList.StyleNormal.getCellMouseOverStyle, cellMouseOut : components.richList.StyleNormal.getCellMouseOutStyle, cellMouseDown : components.richList.StyleNormal.getCellMouseDownStyle, cellMouseUp : components.richList.StyleNormal.getCellMouseUpStyle};
	var list = new components.richList.RichList(listData,listStyle);
	return list;
}
ApplicationStructure.prototype.onBackButtonMouseUp = function(mouseEvent) {
	this.showPage(this._homePage);
}
ApplicationStructure.prototype.__class__ = ApplicationStructure;
if(!cocktailCore.style.floats) cocktailCore.style.floats = {}
cocktailCore.style.floats.FloatsManager = function(p) {
	if( p === $_ ) return;
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
}
cocktailCore.style.floats.FloatsManager.__name__ = ["cocktailCore","style","floats","FloatsManager"];
cocktailCore.style.floats.FloatsManager.prototype._floats = null;
cocktailCore.style.floats.FloatsManager.prototype.floats = null;
cocktailCore.style.floats.FloatsManager.prototype.addFloats = function(parentFormattingContext) {
	var _g1 = 0, _g = parentFormattingContext.getFloatsManager().getFloats().left.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._floats.left.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().left[i],parentFormattingContext.getFlowData()));
	}
	var _g1 = 0, _g = parentFormattingContext.getFloatsManager().getFloats().right.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._floats.right.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().right[i],parentFormattingContext.getFlowData()));
	}
}
cocktailCore.style.floats.FloatsManager.prototype.retrieveFloats = function(childrenFormattingContext) {
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
cocktailCore.style.floats.FloatsManager.prototype.globalTolocal = function(floatData,flowData) {
	var floatY = floatData.y - flowData.y;
	var convertedFloatData = { x : floatData.x, y : floatY, width : floatData.width, height : floatData.height};
	return convertedFloatData;
}
cocktailCore.style.floats.FloatsManager.prototype.clearFloat = function(clear,flowData) {
	var ret;
	switch( (clear)[1] ) {
	case 1:
		ret = this.clearLeft(flowData);
		this._floats.left = new Array();
		break;
	case 2:
		ret = this.clearRight(flowData);
		this._floats.right = new Array();
		break;
	case 3:
		ret = this.clearBoth(flowData);
		this._floats.right = new Array();
		this._floats.left = new Array();
		break;
	case 0:
		ret = flowData.y;
		break;
	}
	return ret;
}
cocktailCore.style.floats.FloatsManager.prototype.clearLeft = function(flowData) {
	return this.doClearFloat(flowData,this._floats.left);
}
cocktailCore.style.floats.FloatsManager.prototype.clearRight = function(flowData) {
	return this.doClearFloat(flowData,this._floats.right);
}
cocktailCore.style.floats.FloatsManager.prototype.clearBoth = function(flowData) {
	var leftY = this.doClearFloat(flowData,this._floats.left);
	var rightY = this.doClearFloat(flowData,this._floats.right);
	if(leftY > rightY) return leftY; else return rightY;
}
cocktailCore.style.floats.FloatsManager.prototype.doClearFloat = function(flowData,floats) {
	if(floats.length > 0) {
		var highestFloat = floats[0];
		var _g1 = 0, _g = floats.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(floats[i].y + floats[i].height > highestFloat.y + highestFloat.height) highestFloat = floats[i];
		}
		return highestFloat.y + highestFloat.height;
	} else return flowData.y;
}
cocktailCore.style.floats.FloatsManager.prototype.computeFloatData = function(domElement,flowData,containingBlockWidth) {
	var ret;
	switch( (domElement.getStyle().getComputedStyle()["float"])[1] ) {
	case 0:
		ret = this.getLeftFloatData(domElement,flowData,containingBlockWidth);
		this._floats.left.push(ret);
		break;
	case 1:
		ret = this.getRightFloatData(domElement,flowData,containingBlockWidth);
		this._floats.right.push(ret);
		break;
	default:
		ret = null;
	}
	return ret;
}
cocktailCore.style.floats.FloatsManager.prototype.getLeftFloatData = function(domElement,flowData,containingBlockWidth) {
	var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
	floatData.x = flowData.xOffset + this.getLeftFloatOffset(floatData.y);
	return floatData;
}
cocktailCore.style.floats.FloatsManager.prototype.getRightFloatData = function(domElement,flowData,containingBlockWidth) {
	var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
	floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth) + flowData.xOffset;
	return floatData;
}
cocktailCore.style.floats.FloatsManager.prototype.getFloatData = function(domElement,flowData,containingBlockWidth) {
	var floatWidth = domElement.getOffsetWidth();
	var floatHeight = domElement.getOffsetHeight();
	var floatY = this.getFirstAvailableY(flowData,floatWidth,containingBlockWidth);
	var floatX = 0;
	return { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
}
cocktailCore.style.floats.FloatsManager.prototype.getFirstAvailableY = function(flowData,elementWidth,containingBlockWidth) {
	var retY = flowData.y;
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
cocktailCore.style.floats.FloatsManager.prototype.removeFloats = function(flowY) {
	this._floats.left = this.doRemoveFloat(this._floats.left,flowY);
	this._floats.right = this.doRemoveFloat(this._floats.right,flowY);
}
cocktailCore.style.floats.FloatsManager.prototype.doRemoveFloat = function(floats,flowY) {
	var newFloats = new Array();
	var _g1 = 0, _g = floats.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(floats[i].y + floats[i].height > flowY) newFloats.push(floats[i]);
	}
	return newFloats;
}
cocktailCore.style.floats.FloatsManager.prototype.getRightFloatOffset = function(y,containingWidth) {
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
cocktailCore.style.floats.FloatsManager.prototype.getLeftFloatOffset = function(y) {
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
cocktailCore.style.floats.FloatsManager.prototype.getFloats = function() {
	return this._floats;
}
cocktailCore.style.floats.FloatsManager.prototype.__class__ = cocktailCore.style.floats.FloatsManager;
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","NoneBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
cocktail.nativeElement.NativeElementManager = function(p) {
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
cocktail.nativeElement.NativeElementManager.prototype.__class__ = cocktail.nativeElement.NativeElementManager;
WebApp = function(p) {
	if( p === $_ ) return;
	this._body = new cocktailCore.domElement.js.BodyDOMElement();
	WebAppStyle.getBodyStyle(this._body);
	this.drawInterface();
}
WebApp.__name__ = ["WebApp"];
WebApp.main = function() {
	new WebApp();
}
WebApp.prototype._body = null;
WebApp.prototype._mainContainer = null;
WebApp.prototype.drawInterface = function() {
	var applicationStructure = new ApplicationStructure();
	this._mainContainer = applicationStructure.pagesContainer;
	WebAppStyle.getDefaultStyle(this._mainContainer);
	this._body.addChild(this._mainContainer);
}
WebApp.prototype.__class__ = WebApp;
cocktailCore.resource.js.StringLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.StringLoader.__name__ = ["cocktailCore","resource","js","StringLoader"];
cocktailCore.resource.js.StringLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.StringLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.StringLoader.prototype.__class__ = cocktailCore.resource.js.StringLoader;
cocktailCore.style.abstract.AbstractBodyStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.js.ContainerStyle.call(this,domElement);
	this._isInvalid = false;
}
cocktailCore.style.abstract.AbstractBodyStyle.__name__ = ["cocktailCore","style","abstract","AbstractBodyStyle"];
cocktailCore.style.abstract.AbstractBodyStyle.__super__ = cocktailCore.style.js.ContainerStyle;
for(var k in cocktailCore.style.js.ContainerStyle.prototype ) cocktailCore.style.abstract.AbstractBodyStyle.prototype[k] = cocktailCore.style.js.ContainerStyle.prototype[k];
cocktailCore.style.abstract.AbstractBodyStyle.prototype.invalidate = function() {
	if(this._isInvalid == false) {
		var viewPort = new cocktailCore.viewport.js.Viewport();
		this._isInvalid = true;
		var viewPortData = { globalX : 0, globalY : 0, isHeightAuto : false, isWidthAuto : false, width : viewPort._getWidth(), height : viewPort._getHeight()};
		var lastPositionedDOMElementData = { children : new Array(), data : viewPortData};
		this.scheduleLayout(viewPortData,lastPositionedDOMElementData,viewPortData);
	}
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.getFormatingContext = function(previousFormatingContext) {
	return new cocktailCore.style.formatter.BlockFormattingContext(this._domElement,null);
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.setNativeX = function(domElement,x) {
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.setNativeY = function(domElement,y) {
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.setNativeWidth = function(domElement,width) {
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.setNativeHeight = function(domElement,height) {
}
cocktailCore.style.abstract.AbstractBodyStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractBodyStyle;
cocktailCore.style.js.BodyStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.abstract.AbstractBodyStyle.call(this,domElement);
}
cocktailCore.style.js.BodyStyle.__name__ = ["cocktailCore","style","js","BodyStyle"];
cocktailCore.style.js.BodyStyle.__super__ = cocktailCore.style.abstract.AbstractBodyStyle;
for(var k in cocktailCore.style.abstract.AbstractBodyStyle.prototype ) cocktailCore.style.js.BodyStyle.prototype[k] = cocktailCore.style.abstract.AbstractBodyStyle.prototype[k];
cocktailCore.style.js.BodyStyle.prototype.__class__ = cocktailCore.style.js.BodyStyle;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
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
if(!cocktailCore.classInstance.js) cocktailCore.classInstance.js = {}
cocktailCore.classInstance.js.ClassInstance = function(nativeInstanceClassName) {
	if( nativeInstanceClassName === $_ ) return;
	cocktailCore.classInstance.abstract.AbstractClassInstance.call(this,nativeInstanceClassName);
	if(Type.resolveClass(nativeInstanceClassName) != null) this._nativeInstance = Type.createInstance(Type.resolveClass(nativeInstanceClassName),[]); else this._nativeInstance = js.Lib.eval("new " + nativeInstanceClassName + "()");
}
cocktailCore.classInstance.js.ClassInstance.__name__ = ["cocktailCore","classInstance","js","ClassInstance"];
cocktailCore.classInstance.js.ClassInstance.__super__ = cocktailCore.classInstance.abstract.AbstractClassInstance;
for(var k in cocktailCore.classInstance.abstract.AbstractClassInstance.prototype ) cocktailCore.classInstance.js.ClassInstance.prototype[k] = cocktailCore.classInstance.abstract.AbstractClassInstance.prototype[k];
cocktailCore.classInstance.js.ClassInstance.prototype.__class__ = cocktailCore.classInstance.js.ClassInstance;
if(!cocktailCore.mouse.js) cocktailCore.mouse.js = {}
cocktailCore.mouse.js.Mouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.mouse.abstract.AbstractMouse.call(this,nativeElement);
}
cocktailCore.mouse.js.Mouse.__name__ = ["cocktailCore","mouse","js","Mouse"];
cocktailCore.mouse.js.Mouse.__super__ = cocktailCore.mouse.abstract.AbstractMouse;
for(var k in cocktailCore.mouse.abstract.AbstractMouse.prototype ) cocktailCore.mouse.js.Mouse.prototype[k] = cocktailCore.mouse.abstract.AbstractMouse.prototype[k];
cocktailCore.mouse.js.Mouse.prototype.setNativeMouseListeners = function(nativeElement) {
	nativeElement.onmousedown = $closure(this,"onNativeMouseDown");
	nativeElement.onmouseup = $closure(this,"onNativeMouseUp");
	nativeElement.onmouseover = $closure(this,"onNativeMouseOver");
	nativeElement.onmouseout = $closure(this,"onNativeMouseOut");
	nativeElement.onmousemove = $closure(this,"onNativeMouseMove");
	nativeElement.ondblclick = $closure(this,"onNativeMouseDoubleClick");
}
cocktailCore.mouse.js.Mouse.prototype.unsetNativeMouseListeners = function(nativeElement) {
	nativeElement.onmousedown = null;
	nativeElement.onmouseup = null;
	nativeElement.onmouseover = null;
	nativeElement.onmouseout = null;
	nativeElement.onmousemove = null;
	nativeElement.ondblclick = null;
}
cocktailCore.mouse.js.Mouse.prototype.getMouseData = function(event) {
	var mousePosition = { localX : event.clientX, localY : event.clientY, globalX : event.screenX, globalY : event.screenY};
	var mouseEventData = { mousePosition : mousePosition, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
	return mouseEventData;
}
cocktailCore.mouse.js.Mouse.prototype.__class__ = cocktailCore.mouse.js.Mouse;
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
js.Lib.onerror = null;
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_QUALITY = "optimizeQuality";
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_SPEED = "optimizeSpeed";
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
haxe.Timer.arr = new Array();
WebApp.main()