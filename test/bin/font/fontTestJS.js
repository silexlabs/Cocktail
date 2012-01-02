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
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.matrix = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scaleX = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scaleY = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.rotation = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.alpha = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.isVisible = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.zIndex = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.init = function() {
	this._keyboard = new cocktailCore.keyboard.js.Keyboard();
	this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
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
	var visibility;
	if(value == true) visibility = cocktail.style.VisibilityStyleValue.visible; else visibility = cocktail.style.VisibilityStyleValue.hidden;
	this._style.setVisibility(visibility);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getIsVisible = function() {
	return this._style.getNativeVisibility();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha = function(value) {
	this._style.setOpacity(cocktail.style.OpacityStyleValue.number(value));
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getAlpha = function() {
	return this._style.getNativeOpacity();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setMatrix = function(matrix) {
	this._style.setNativeMatrix(matrix);
	return matrix;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getMatrix = function() {
	return this._style.getNativeMatrix();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleX = function(scaleX) {
	this._style.setNativeScaleX(scaleX);
	this.updateTransforms();
	return scaleX;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleX = function() {
	return this._style.getNativeScaleX();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleY = function(scaleY) {
	this._style.setNativeScaleY(scaleY);
	this.updateTransforms();
	return scaleY;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleY = function() {
	return this._style.getNativeScaleY();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setRotation = function(angle) {
	this._style.setNativeRotation(cocktailCore.unit.UnitManager.getRadFromAngleValue(cocktail.unit.AngleValue.deg(angle)));
	this.updateTransforms();
	return angle;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRotation = function() {
	return Math.round(cocktailCore.unit.UnitManager.getDegreeFromAngleValue(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())));
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.updateTransforms = function() {
	this._style.setTransformOrigin({ x : cocktail.style.TransformOriginXStyleValue.left, y : cocktail.style.TransformOriginYStyleValue.top});
	this._style.setTransform(cocktail.style.TransformStyleValue.transformFunctions([cocktail.style.TransformFunctionValue.rotate(cocktail.unit.AngleValue.rad(this._style.getNativeRotation())),cocktail.style.TransformFunctionValue.scaleY(this._style.getNativeScaleY()),cocktail.style.TransformFunctionValue.scaleX(this._style.getNativeScaleX())]));
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDown = function(value) {
	this._mouse.setOnMouseDown(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDown = function() {
	return this._mouse.getOnMouseDown();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseUp = function(value) {
	this._mouse.setOnMouseUp(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseUp = function() {
	return this._mouse.getOnMouseUp();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOver = function(value) {
	this._mouse.setOnMouseOver(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOver = function() {
	return this._mouse.getOnMouseOver();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOut = function(value) {
	this._mouse.setOnMouseOut(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOut = function() {
	return this._mouse.getOnMouseOut();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseMove = function(value) {
	this._mouse.setOnMouseMove(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseMove = function() {
	return this._mouse.getOnMouseMove();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDoubleClick = function(value) {
	this._mouse.setOnMouseDoubleClick(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDoubleClick = function() {
	return this._mouse.getOnMouseDoubleClick();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyDown = function(value) {
	this._keyboard.setOnKeyDown(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyDown = function() {
	return this._keyboard.getOnKeyDown();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyUp = function(value) {
	this._keyboard.setOnKeyUp(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyUp = function() {
	return this._keyboard.getOnKeyUp();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setField = function(propertyName,propertyValue) {
	this._nativeElement[propertyName] = propertyValue;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getField = function(propertyName) {
	return Reflect.field(this._nativeElement,propertyName);
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setX = function(value) {
	this._style.setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
	this._style.setNativeX(this,value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getX = function() {
	return this._style.getNativeX();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setY = function(value) {
	this._style.setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
	this._style.setNativeY(this,value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getY = function() {
	return this._style.getNativeY();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setWidth = function(value) {
	this._style.setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
	this._style.setNativeWidth(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getWidth = function() {
	return this._style.getNativeWidth();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setHeight = function(value) {
	this._style.setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
	this._style.setNativeHeight(value);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getHeight = function() {
	return this._style.getNativeHeight();
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
	this._style.setNativeX(this,localX);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalX = function() {
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
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setGlobalY = function(value) {
	var localY = value;
	if(this._parent != null) {
		var parentGlobalY = this._parent.getGlobalY();
		localY -= parentGlobalY;
	} else localY = 0;
	this._style.setNativeY(this,localY);
	return value;
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalY = function() {
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
cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__class__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	this._imageLoader = new cocktailCore.resource.js.ImageLoader(nativeElement);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,this._imageLoader.getNativeElement());
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractImageDOMElement"];
cocktailCore.domElement.abstract.AbstractImageDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
for(var k in cocktailCore.domElement.js.EmbeddedDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k] = cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onLoad = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.onError = null;
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
	if(this.onLoad != null) this.onLoad(this);
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
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
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
cocktailCore.style.abstract.AbstractStyle.prototype._display = null;
cocktailCore.style.abstract.AbstractStyle.prototype.display = null;
cocktailCore.style.abstract.AbstractStyle.prototype._position = null;
cocktailCore.style.abstract.AbstractStyle.prototype.position = null;
cocktailCore.style.abstract.AbstractStyle.prototype._floatValue = null;
cocktailCore.style.abstract.AbstractStyle.prototype.floatValue = null;
cocktailCore.style.abstract.AbstractStyle.prototype._clear = null;
cocktailCore.style.abstract.AbstractStyle.prototype.clear = null;
cocktailCore.style.abstract.AbstractStyle.prototype._opacity = null;
cocktailCore.style.abstract.AbstractStyle.prototype.opacity = null;
cocktailCore.style.abstract.AbstractStyle.prototype._visibility = null;
cocktailCore.style.abstract.AbstractStyle.prototype.visibility = null;
cocktailCore.style.abstract.AbstractStyle.prototype._tranformOrigin = null;
cocktailCore.style.abstract.AbstractStyle.prototype.transformOrigin = null;
cocktailCore.style.abstract.AbstractStyle.prototype._transform = null;
cocktailCore.style.abstract.AbstractStyle.prototype.transform = null;
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
cocktailCore.style.abstract.AbstractStyle.prototype._verticalAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype.verticalAlign = null;
cocktailCore.style.abstract.AbstractStyle.prototype._computedStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype.computedStyle = null;
cocktailCore.style.abstract.AbstractStyle.prototype._domElement = null;
cocktailCore.style.abstract.AbstractStyle.prototype.domElement = null;
cocktailCore.style.abstract.AbstractStyle.prototype._fontMetrics = null;
cocktailCore.style.abstract.AbstractStyle.prototype.fontMetrics = null;
cocktailCore.style.abstract.AbstractStyle.prototype._isInvalid = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeX = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeY = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeWidth = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeHeight = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeScaleX = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeScaleY = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeRotation = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeOpacity = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeVisibility = null;
cocktailCore.style.abstract.AbstractStyle.prototype._nativeMatrix = null;
cocktailCore.style.abstract.AbstractStyle.prototype.initDefaultStyleValues = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.initComputedStyles = function() {
	this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, floatValue : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0, visibility : true, opacity : 1.0, transformOrigin : { x : 0.0, y : 0.0}, transform : new cocktail.geom.Matrix()};
}
cocktailCore.style.abstract.AbstractStyle.prototype.initNativeProperties = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
}
cocktailCore.style.abstract.AbstractStyle.prototype.flow = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	if(this.isNotDisplayed() == true) {
		this.setNativeVisibility(false);
		return;
	} else this.setNativeVisibility(true);
	if(this.isClear() == true) formatingContext.clearFloat(this._computedStyle.clear,this.isFloat());
	this.computeDOMElement(containingDOMElementData,viewportData,lastPositionedDOMElementData.data,containingDOMElementFontMetricsData);
	this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
	this.setNativeHeight(this._computedStyle.height);
	this.setNativeWidth(this._computedStyle.width);
	this.computeVisualEffectStyles();
	this.setNativeMatrix(this._computedStyle.transform);
	this.setNativeOpacity(this._computedStyle.opacity);
	this.setNativeVisibility(this._computedStyle.visibility);
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
				var viewPortData = this.getViewportData();
				var lastPositionedDOMElementData = { children : new Array(), data : this.getFirstPositionedAncestorData()};
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
	this.initComputedStyles();
	this.computeDisplayStyles();
	this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
	this.computeBoxModelStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData);
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeDisplayStyles = function() {
	cocktailCore.style.computer.DisplayStylesComputer.compute(this);
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeVisualEffectStyles = function() {
	cocktailCore.style.computer.VisualEffectStylesComputer.compute(this);
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
cocktailCore.style.abstract.AbstractStyle.prototype.isRelativePositioned = function() {
	return this._computedStyle.position == cocktail.style.PositionStyleValue.relative;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFirstPositionedAncestorData = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.getViewportData = function() {
	var viewPort = new cocktailCore.viewport.js.Viewport();
	var viewPortData = { globalX : 0, globalY : 0, isHeightAuto : false, isWidthAuto : false, width : viewPort._getWidth(), height : viewPort._getHeight()};
	return viewPortData;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeX = function(domElement,x) {
	if(domElement == this._domElement) this._nativeX = x;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeX = function() {
	return this._nativeX;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeY = function(domElement,y) {
	if(domElement == this._domElement) this._nativeY = y;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeY = function() {
	return this._nativeY;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeWidth = function(width) {
	this._nativeWidth = width;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeWidth = function() {
	return this._nativeWidth;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeHeight = function(height) {
	this._nativeHeight = height;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeHeight = function() {
	return this._nativeHeight;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeScaleX = function(scaleX) {
	this._nativeScaleX = scaleX;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeScaleX = function() {
	return this._nativeScaleX;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeScaleY = function(scaleY) {
	this._nativeScaleY = scaleY;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeScaleY = function() {
	return this._nativeScaleY;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeRotation = function(rotation) {
	this._nativeRotation = rotation;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeRotation = function() {
	return this._nativeRotation;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeMatrix = function(matrix) {
	this._nativeMatrix = matrix;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeMatrix = function() {
	return this._nativeMatrix;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeOpacity = function(opacity) {
	this._nativeOpacity = opacity;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeOpacity = function() {
	return this._nativeOpacity;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setNativeVisibility = function(visible) {
	this._nativeVisibility = visible;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getNativeVisibility = function() {
	return this._nativeVisibility;
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
cocktailCore.style.abstract.AbstractStyle.prototype.setFloatValue = function(value) {
	this.invalidate();
	return this._floatValue = value;
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
cocktailCore.style.abstract.AbstractStyle.prototype.setColor = function(value) {
	this.invalidateText();
	return this._color = value;
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
cocktailCore.style.abstract.AbstractStyle.prototype.setOpacity = function(value) {
	this._opacity = value;
	this.invalidate();
	return this._opacity;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setVisibility = function(value) {
	this._visibility = value;
	this.invalidate();
	return this._visibility;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTransformOrigin = function(value) {
	this.invalidate();
	return this._tranformOrigin = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTransform = function(value) {
	this.invalidate();
	return this._transform = value;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getOpacity = function() {
	return this._opacity;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getVisibility = function() {
	return this._visibility;
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
cocktailCore.style.abstract.AbstractStyle.prototype.getFloatValue = function() {
	return this._floatValue;
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
cocktailCore.style.abstract.AbstractStyle.prototype.getTransform = function() {
	return this._transform;
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTransformOrigin = function() {
	return this._tranformOrigin;
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
cocktailCore.style.js.Style.prototype.flow = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	this.flowChildren(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
	this.setNativeHeight(this._domElement.getNativeElement().clientHeight);
	this.setNativeWidth(this._domElement.getNativeElement().clientWidth);
	this.setNativeX(this._domElement,this._domElement.getNativeElement().offsetLeft);
	this.setNativeY(this._domElement,this._domElement.getNativeElement().offsetTop);
	this._isInvalid = false;
}
cocktailCore.style.js.Style.prototype.flowChildren = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
}
cocktailCore.style.js.Style.prototype.getCSSDisplay = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFloat = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSClear = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSPosition = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSOpacity = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSVisibility = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSTransform = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSTransformFunction = function(transformFunction) {
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
cocktailCore.style.js.Style.prototype.getCSSTranslation = function(translation) {
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
cocktailCore.style.js.Style.prototype.getCSSTransformOrigin = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSMargin = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSPadding = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSDimension = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSPositionOffset = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSConstrainedDimension = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSVerticalAlign = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSLineHeight = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFontSize = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFontWeight = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFontStyle = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFontVariant = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSFontFamily = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSTextAlign = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSWhiteSpace = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSTextTransform = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSTextIndent = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSLetterSpacing = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSWordSpacing = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSColor = function(value) {
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
cocktailCore.style.js.Style.prototype.getCSSLengthValue = function(lengthValue) {
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
cocktailCore.style.js.Style.prototype.getCSSPercentValue = function(value) {
	return Std.string(value) + "%";
}
cocktailCore.style.js.Style.prototype.getCSSAngleValue = function(value) {
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
cocktailCore.style.js.Style.prototype.getColorFromKeyword = function(value) {
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
cocktailCore.style.js.Style.prototype.getVendorSpecificStyleName = function(nativeStyle,styleName) {
	var vendorSpecificStyleName = styleName;
	if(Reflect.hasField(nativeStyle,styleName)) vendorSpecificStyleName = styleName; else {
		var styleNameCap = styleName.charAt(0).toUpperCase();
		var styleNameEnd = styleName.substr(1);
		styleName = styleNameCap + styleNameEnd;
		if(Reflect.field(nativeStyle,"Moz" + styleName) != null) vendorSpecificStyleName = "Moz" + styleName; else if(Reflect.field(nativeStyle,"Webkit" + styleName) != null) vendorSpecificStyleName = "Webkit" + styleName; else if(Reflect.field(nativeStyle,"Ms" + styleName) != null) vendorSpecificStyleName = "Ms" + styleName; else if(Reflect.field(nativeStyle,"O" + styleName) != null) vendorSpecificStyleName = "O" + styleName;
	}
	return vendorSpecificStyleName;
}
cocktailCore.style.js.Style.prototype.setVerticalAlign = function(value) {
	this._domElement.getNativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setVerticalAlign.call(this,value);
	return this._verticalAlign = value;
}
cocktailCore.style.js.Style.prototype.setColor = function(value) {
	this._domElement.getNativeElement().style.color = this.getCSSColor(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setColor.call(this,value);
	return this._color = value;
}
cocktailCore.style.js.Style.prototype.setWordSpacing = function(value) {
	this._domElement.getNativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setWordSpacing.call(this,value);
	return this._wordSpacing = value;
}
cocktailCore.style.js.Style.prototype.setLetterSpacing = function(value) {
	this._domElement.getNativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setLetterSpacing.call(this,value);
	return this._letterSpacing = value;
}
cocktailCore.style.js.Style.prototype.setTextTransform = function(value) {
	this._domElement.getNativeElement().style.textTransform = this.getCSSTextTransform(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTextTransform.call(this,value);
	return this._textTransform = value;
}
cocktailCore.style.js.Style.prototype.setFontVariant = function(value) {
	this._domElement.getNativeElement().style.fontVariant = this.getCSSFontVariant(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFontVariant.call(this,value);
	return this._fontVariant = value;
}
cocktailCore.style.js.Style.prototype.setFontFamily = function(value) {
	this._domElement.getNativeElement().style.fontFamily = this.getCSSFontFamily(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFontFamily.call(this,value);
	return this._fontFamily = value;
}
cocktailCore.style.js.Style.prototype.setFontWeight = function(value) {
	this._domElement.getNativeElement().style.fontWeight = this.getCSSFontWeight(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFontWeight.call(this,value);
	return this._fontWeight = value;
}
cocktailCore.style.js.Style.prototype.setFontStyle = function(value) {
	this._domElement.getNativeElement().style.fontStyle = this.getCSSFontStyle(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFontStyle.call(this,value);
	return this._fontStyle = value;
}
cocktailCore.style.js.Style.prototype.setFontSize = function(value) {
	this._domElement.getNativeElement().style.fontSize = this.getCSSFontSize(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFontSize.call(this,value);
	return this._fontSize = value;
}
cocktailCore.style.js.Style.prototype.setLineHeight = function(value) {
	this._domElement.getNativeElement().style.lineHeight = this.getCSSLineHeight(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setLineHeight.call(this,value);
	return this._lineHeight = value;
}
cocktailCore.style.js.Style.prototype.setMarginLeft = function(value) {
	this._domElement.getNativeElement().style.marginLeft = this.getCSSMargin(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMarginLeft.call(this,value);
	return this._marginLeft = value;
}
cocktailCore.style.js.Style.prototype.setMarginRight = function(value) {
	this._domElement.getNativeElement().style.marginRight = this.getCSSMargin(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMarginRight.call(this,value);
	return this._marginRight = value;
}
cocktailCore.style.js.Style.prototype.setMarginTop = function(value) {
	this._domElement.getNativeElement().style.marginTop = this.getCSSMargin(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMarginTop.call(this,value);
	return this._marginTop = value;
}
cocktailCore.style.js.Style.prototype.setMarginBottom = function(value) {
	this._domElement.getNativeElement().style.marginBottom = this.getCSSMargin(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMarginBottom.call(this,value);
	return this._marginBottom = value;
}
cocktailCore.style.js.Style.prototype.setPaddingLeft = function(value) {
	this._domElement.getNativeElement().style.paddingLeft = this.getCSSPadding(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingLeft.call(this,value);
	return this._paddingLeft = value;
}
cocktailCore.style.js.Style.prototype.setPaddingRight = function(value) {
	this._domElement.getNativeElement().style.paddingRight = this.getCSSPadding(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingRight.call(this,value);
	return this._paddingRight = value;
}
cocktailCore.style.js.Style.prototype.setPaddingTop = function(value) {
	this._domElement.getNativeElement().style.paddingTop = this.getCSSPadding(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingTop.call(this,value);
	return this._paddingTop = value;
}
cocktailCore.style.js.Style.prototype.setPaddingBottom = function(value) {
	this._domElement.getNativeElement().style.paddingBottom = this.getCSSPadding(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingBottom.call(this,value);
	return this._paddingBottom = value;
}
cocktailCore.style.js.Style.prototype.setDisplay = function(value) {
	this._domElement.getNativeElement().style.display = this.getCSSDisplay(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setDisplay.call(this,value);
	return this._display = value;
}
cocktailCore.style.js.Style.prototype.setPosition = function(value) {
	this._domElement.getNativeElement().style.position = this.getCSSPosition(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setPosition.call(this,value);
	return this._position = value;
}
cocktailCore.style.js.Style.prototype.setWidth = function(value) {
	this._domElement.getNativeElement().style.width = this.getCSSDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setWidth.call(this,value);
	return this._width = value;
}
cocktailCore.style.js.Style.prototype.setHeight = function(value) {
	this._domElement.getNativeElement().style.height = this.getCSSDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setHeight.call(this,value);
	return this._height = value;
}
cocktailCore.style.js.Style.prototype.setMinHeight = function(value) {
	this._domElement.getNativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMinHeight.call(this,value);
	return this._minHeight = value;
}
cocktailCore.style.js.Style.prototype.setMaxHeight = function(value) {
	this._domElement.getNativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMaxHeight.call(this,value);
	return this._maxHeight = value;
}
cocktailCore.style.js.Style.prototype.setMinWidth = function(value) {
	this._domElement.getNativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMinWidth.call(this,value);
	return this._minWidth = value;
}
cocktailCore.style.js.Style.prototype.setMaxWidth = function(value) {
	this._domElement.getNativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setMaxWidth.call(this,value);
	return this._maxWidth = value;
}
cocktailCore.style.js.Style.prototype.setTop = function(value) {
	this._domElement.getNativeElement().style.top = this.getCSSPositionOffset(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTop.call(this,value);
	return this._top = value;
}
cocktailCore.style.js.Style.prototype.setLeft = function(value) {
	this._domElement.getNativeElement().style.left = this.getCSSPositionOffset(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setLeft.call(this,value);
	return this._left = value;
}
cocktailCore.style.js.Style.prototype.setBottom = function(value) {
	this._domElement.getNativeElement().style.bottom = this.getCSSPositionOffset(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setBottom.call(this,value);
	return this._bottom = value;
}
cocktailCore.style.js.Style.prototype.setRight = function(value) {
	this._domElement.getNativeElement().style.right = this.getCSSPositionOffset(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setRight.call(this,value);
	return this._right = value;
}
cocktailCore.style.js.Style.prototype.setTextIndent = function(value) {
	this._domElement.getNativeElement().style.textIndent = this.getCSSTextIndent(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTextIndent.call(this,value);
	return this._textIndent = value;
}
cocktailCore.style.js.Style.prototype.setFloatValue = function(value) {
	this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setFloatValue.call(this,value);
	return this.floatValue = value;
}
cocktailCore.style.js.Style.prototype.setClear = function(value) {
	this._domElement.getNativeElement().style.clear = this.getCSSClear(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setClear.call(this,value);
	return this._clear = value;
}
cocktailCore.style.js.Style.prototype.setWhiteSpace = function(value) {
	this._domElement.getNativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setWhiteSpace.call(this,value);
	return this._whiteSpace = value;
}
cocktailCore.style.js.Style.prototype.setTextAlign = function(value) {
	this._domElement.getNativeElement().style.textAlign = this.getCSSTextAlign(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTextAlign.call(this,value);
	return this._textAlign = value;
}
cocktailCore.style.js.Style.prototype.setOpacity = function(value) {
	this._domElement.getNativeElement().style.opacity = this.getCSSOpacity(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setOpacity.call(this,value);
	return this._opacity = value;
}
cocktailCore.style.js.Style.prototype.setVisibility = function(value) {
	this._domElement.getNativeElement().style.visibility = this.getCSSVisibility(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setVisibility.call(this,value);
	return this._visibility = value;
}
cocktailCore.style.js.Style.prototype.setTransformOrigin = function(value) {
	var nativeStyle = this._domElement.getNativeElement().style;
	nativeStyle[this.getVendorSpecificStyleName(nativeStyle,"transformOrigin")] = this.getCSSTransformOrigin(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTransformOrigin.call(this,value);
	return this._tranformOrigin = value;
}
cocktailCore.style.js.Style.prototype.setTransform = function(value) {
	var nativeStyle = this._domElement.getNativeElement().style;
	nativeStyle[this.getVendorSpecificStyleName(nativeStyle,"transform")] = this.getCSSTransform(value);
	cocktailCore.style.abstract.AbstractStyle.prototype.setTransform.call(this,value);
	return this._transform = value;
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
	childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
	this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
	if(childrenFormattingContext != formatingContext) childrenFormattingContext.destroy();
	if(this._width == cocktail.style.DimensionStyleValue.autoValue) {
		var currentWidth = this._computedStyle.width;
		this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData,childrenFormattingContext.getFlowData().maxWidth);
		if(currentWidth != this._computedStyle.width) {
			childrenFormattingContext = this.getFormatingContext(formatingContext);
			childrenContainingDOMElementData = this.getContainerDOMElementData();
			childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
			this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
		}
	}
	if(this._height == cocktail.style.DimensionStyleValue.autoValue) this._computedStyle.height = this.applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getFlowData().totalHeight);
	this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
	formatingContext.retrieveFloats(childrenFormattingContext);
	var isFirstPositionedAncestor = childLastPositionedDOMElementData != lastPositionedDOMElementData;
	this.doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertInFlowDOMElement = function(formattingContext) {
	if(this.isInline() == false || this.isInlineFlow() == false) cocktailCore.style.js.Style.prototype.insertInFlowDOMElement.call(this,formattingContext);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.doFlowChildren = function(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext) {
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
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.doPositionAbsolutelyPositionedDOMElements = function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
	if(isFirstPositionedAncestor == true) {
		childLastPositionedDOMElementData.data = this.getContainerDOMElementData();
		var _g1 = 0, _g = childLastPositionedDOMElementData.children.length;
		while(_g1 < _g) {
			var i = _g1++;
			var positionedDOMElementData = childLastPositionedDOMElementData.children[i];
			positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data,viewportData,positionedDOMElementData.staticPosition);
		}
	}
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertTextElement = function(textElement,formattingContext,containingDOMElementData) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.shrinkToFitIfNeeded = function(containingDOMElementData,minimumWidth) {
	var boxComputer = this.getBoxStylesComputer();
	return boxComputer.shrinkToFit(this,containingDOMElementData,minimumWidth);
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.applyContentHeightIfNeeded = function(containingDOMElementData,childrenHeight) {
	var boxComputer = this.getBoxStylesComputer();
	return boxComputer.applyContentHeight(this,containingDOMElementData,childrenHeight);
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getContainerDOMElementData = function() {
	var height;
	if(this.isInline() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.isInline() == false && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
	return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.autoValue, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.autoValue, globalX : this._domElement.getGlobalX(), globalY : this._domElement.getGlobalY()};
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.isChildInline = function(child) {
	var ret = true;
	if(this.isDOMElement(child)) {
		var childrenDOMElement = child.child;
		if(childrenDOMElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.block) {
			if(childrenDOMElement.getStyle().isFloat() == false) ret = false; else if(childrenDOMElement.getStyle().isPositioned() == false || childrenDOMElement.getStyle().isRelativePositioned() == true) ret = false;
		} else ret = true;
	} else ret = true;
	return ret;
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getChildLastPositionedDOMElementData = function(lastPositionedDOMElementData) {
	var childLastPositionedDOMElementData;
	if(this.isPositioned() == true) childLastPositionedDOMElementData = { data : this.getContainerDOMElementData(), children : new Array()}; else childLastPositionedDOMElementData = lastPositionedDOMElementData;
	return childLastPositionedDOMElementData;
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
if(!cocktailCore.font) cocktailCore.font = {}
if(!cocktailCore.font["abstract"]) cocktailCore.font["abstract"] = {}
cocktailCore.font.abstract.AbstractFontManager = function(p) {
	if( p === $_ ) return;
	if(cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray == null) cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray = new Array();
	if(cocktailCore.font.abstract.AbstractFontManager._loadedFonts == null) cocktailCore.font.abstract.AbstractFontManager._loadedFonts = new Array();
}
cocktailCore.font.abstract.AbstractFontManager.__name__ = ["cocktailCore","font","abstract","AbstractFontManager"];
cocktailCore.font.abstract.AbstractFontManager._loadedFonts = null;
cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray = null;
cocktailCore.font.abstract.AbstractFontManager.prototype.loadFont = function(url,name,successCallback,errorCallback) {
	var fontLoader;
	var idx;
	var _g1 = 0, _g = cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		if(cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1].fontData.url == url && cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1].fontData.name == name) {
			cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1].addCallback(successCallback,errorCallback);
			return;
		}
	}
	fontLoader = new cocktailCore.font.js.FontLoader();
	fontLoader.addCallback($closure(this,"_onFontLoadingSuccess"),$closure(this,"_onFontLoadingError"));
	fontLoader.addCallback(successCallback,errorCallback);
	fontLoader.load(url,name);
	cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray.push(fontLoader);
}
cocktailCore.font.abstract.AbstractFontManager.prototype.getEmbeddedFonts = function() {
	return cocktailCore.font.abstract.AbstractFontManager._loadedFonts;
}
cocktailCore.font.abstract.AbstractFontManager.prototype.getSystemFonts = function() {
	throw "Virtual method should be implemented in sub class";
	return null;
}
cocktailCore.font.abstract.AbstractFontManager.prototype.hasFont = function(fontName) {
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
cocktailCore.font.abstract.AbstractFontManager.prototype._onFontLoadingSuccess = function(fontData) {
	cocktailCore.font.abstract.AbstractFontManager._loadedFonts.push(fontData);
	if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font was successfully loaded",{ fileName : "AbstractFontManager.hx", lineNumber : 131, className : "cocktailCore.font.abstract.AbstractFontManager", methodName : "_onFontLoadingSuccess"});
}
cocktailCore.font.abstract.AbstractFontManager.prototype._onFontLoadingError = function(fontData,errorStr) {
	haxe.Log.trace("font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 140, className : "cocktailCore.font.abstract.AbstractFontManager", methodName : "_onFontLoadingError"});
	if(this._removeFontLoader(fontData) == false) haxe.Log.trace("could not remove font loader from the list after the font loading has failed",{ fileName : "AbstractFontManager.hx", lineNumber : 146, className : "cocktailCore.font.abstract.AbstractFontManager", methodName : "_onFontLoadingError"});
}
cocktailCore.font.abstract.AbstractFontManager.prototype._removeFontLoader = function(fontData) {
	var fontLoader;
	var idx;
	var _g1 = 0, _g = cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		if(cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1].fontData.url == fontData.url && cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1].fontData.name == fontData.name) {
			cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray.remove(cocktailCore.font.abstract.AbstractFontManager._fontLoaderArray[idx1]);
			return true;
		}
	}
	return false;
}
cocktailCore.font.abstract.AbstractFontManager.prototype.__class__ = cocktailCore.font.abstract.AbstractFontManager;
if(!cocktailCore.font.js) cocktailCore.font.js = {}
cocktailCore.font.js.FontManager = function(p) {
	if( p === $_ ) return;
	cocktailCore.font.abstract.AbstractFontManager.call(this);
}
cocktailCore.font.js.FontManager.__name__ = ["cocktailCore","font","js","FontManager"];
cocktailCore.font.js.FontManager.__super__ = cocktailCore.font.abstract.AbstractFontManager;
for(var k in cocktailCore.font.abstract.AbstractFontManager.prototype ) cocktailCore.font.js.FontManager.prototype[k] = cocktailCore.font.abstract.AbstractFontManager.prototype[k];
cocktailCore.font.js.FontManager.prototype.getSystemFonts = function() {
	haxe.Log.trace("It is impossible to list the system fonts in javascript",{ fileName : "FontManager.hx", lineNumber : 38, className : "cocktailCore.font.js.FontManager", methodName : "getSystemFonts"});
	return new Array();
}
cocktailCore.font.js.FontManager.prototype.__class__ = cocktailCore.font.js.FontManager;
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
if(!cocktailCore.keyboard) cocktailCore.keyboard = {}
if(!cocktailCore.keyboard["abstract"]) cocktailCore.keyboard["abstract"] = {}
cocktailCore.keyboard.abstract.AbstractKeyboard = function(p) {
}
cocktailCore.keyboard.abstract.AbstractKeyboard.__name__ = ["cocktailCore","keyboard","abstract","AbstractKeyboard"];
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype._onKeyDown = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyDown = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype._onKeyUp = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyUp = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyDown = function(event) {
	if(this.getOnKeyDown() != null) (this.getOnKeyDown())(this.getKeyData(event));
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyUp = function(event) {
	if(this.getOnKeyUp() != null) (this.getOnKeyUp())(this.getKeyData(event));
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.setOnKeyDown = function(value) {
	return this._onKeyDown = value;
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getOnKeyDown = function() {
	return this._onKeyDown;
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.setOnKeyUp = function(value) {
	return this._onKeyUp = value;
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getOnKeyUp = function() {
	return this._onKeyUp;
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
cocktailCore.keyboard.js.Keyboard.prototype.setOnKeyDown = function(value) {
	if(value == null) js.Lib.document.removeEventListener("keydown",$closure(this,"onNativeKeyDown")); else js.Lib.document.addEventListener("keydown",$closure(this,"onNativeKeyDown"));
	return this._onKeyDown = value;
}
cocktailCore.keyboard.js.Keyboard.prototype.setOnKeyUp = function(value) {
	if(value == null) js.Lib.document.removeEventListener("keyup",$closure(this,"onNativeKeyUp")); else js.Lib.document.addEventListener("keyup",$closure(this,"onNativeKeyUp"));
	return this._onKeyUp = value;
}
cocktailCore.keyboard.js.Keyboard.prototype.getKeyData = function(event) {
	var key = { value : this.getKeyValue(event.keyCode), code : event.keyCode, ascii : event.charCode, altKey : event.altKey, controlKey : event.ctrlKey, shiftKey : event.shiftKey};
	return key;
}
cocktailCore.keyboard.js.Keyboard.prototype.__class__ = cocktailCore.keyboard.js.Keyboard;
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
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	if(nativeElement != null) this._nativeElement = nativeElement;
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadCompleteCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadErrorCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._nativeElement = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.nativeElement = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.load = function(url,onLoadComplete,onLoadError,allowCache) {
	if(allowCache == null) allowCache = true;
	this._onLoadCompleteCallback = onLoadComplete;
	this._onLoadErrorCallback = onLoadError;
	if(allowCache == false) url = this.disableUrlCaching(url);
	this.doLoad(url);
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.doLoad = function(url) {
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
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.getNativeElement = function() {
	return this._nativeElement;
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.__class__ = cocktailCore.resource.abstract.AbstractResourceLoader;
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ResourceLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.js.ResourceLoader.__name__ = ["cocktailCore","resource","js","ResourceLoader"];
cocktailCore.resource.js.ResourceLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.ResourceLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.ResourceLoader.prototype.doLoad = function(url) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.shrinkToFit = function(style,containingDOMElementData,minimumWidth) {
	return style.getComputedStyle().width;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.applyContentHeight = function(style,cotainingDOMElementData,childrenHeight) {
	return childrenHeight;
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
	if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoWidth = function(style,containingDOMElementData) {
	style.getComputedStyle().width = 0;
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	style.getComputedStyle().width = this.getComputedAutoWidth(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureWidth = function(style,containingDOMElementData) {
	style.getComputedStyle().width = this.getComputedWidth(style,containingDOMElementData);
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeightAndVerticalMargins = function(style,containingDOMElementData) {
	if(style.getHeight() == cocktail.style.DimensionStyleValue.autoValue) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoHeight = function(style,containingDOMElementData) {
	style.getComputedStyle().height = this.getComputedAutoHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeight = function(style,containingDOMElementData) {
	style.getComputedStyle().height = this.getComputedHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.constrainDimensions = function(style) {
	var computedStyle = style.getComputedStyle();
	if(style.getMaxWidth() != cocktail.style.ConstrainedDimensionStyleValue.none) {
		if(computedStyle.width > computedStyle.maxWidth) computedStyle.width = computedStyle.maxWidth;
	}
	if(computedStyle.width < computedStyle.minWidth) computedStyle.width = computedStyle.minWidth;
	if(style.getHeight() != cocktail.style.DimensionStyleValue.autoValue) {
		if(style.getMaxHeight() != cocktail.style.ConstrainedDimensionStyleValue.none) {
			if(computedStyle.height > computedStyle.maxHeight) computedStyle.height = computedStyle.maxHeight;
		}
		if(computedStyle.height < computedStyle.minHeight) computedStyle.height = computedStyle.minHeight;
	}
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedWidth = function(style,containingDOMElementData) {
	return this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	return containingDOMElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedHeight = function(style,containingDOMElementData) {
	return this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginLeft = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginRight = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginTop = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginBottom = function(style,containingDOMElementData) {
	return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.autoValue,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
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
	if(style.getHeight() == cocktail.style.DimensionStyleValue.autoValue) {
		if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else if(embeddedDOMElement.getIntrinsicHeight() != null && embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(embeddedDOMElement.getIntrinsicHeight() * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicRatio() != null) {
			if(containingDOMElementData.isWidthAuto == false) {
				var computedStyle = style.getComputedStyle();
				ret = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
			} else ret = 0;
		}
	} else {
		var computedHeight = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedHeight * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else ret = 300;
	}
	return ret;
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	var embeddedDOMElement = style.getDOMElement();
	var ret = 0;
	if(style.getWidth() == cocktail.style.DimensionStyleValue.autoValue) {
		if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
	} else {
		var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedWidth / embeddedDOMElement.getIntrinsicRatio()); else ret = 150;
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
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.shrinkToFit = function(style,containingDOMElementData,minimumWidth) {
	var shrinkedWidth;
	if(minimumWidth < containingDOMElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingDOMElementData.width;
	return shrinkedWidth;
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
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
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
cocktailCore.resource.abstract.AbstractImageLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image);
	cocktailCore.resource.js.ResourceLoader.call(this,nativeElement);
}
cocktailCore.resource.abstract.AbstractImageLoader.__name__ = ["cocktailCore","resource","abstract","AbstractImageLoader"];
cocktailCore.resource.abstract.AbstractImageLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
for(var k in cocktailCore.resource.js.ResourceLoader.prototype ) cocktailCore.resource.abstract.AbstractImageLoader.prototype[k] = cocktailCore.resource.js.ResourceLoader.prototype[k];
cocktailCore.resource.abstract.AbstractImageLoader.prototype.__class__ = cocktailCore.resource.abstract.AbstractImageLoader;
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = function(p) {
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype.position = function(domElement,containingDOMElementData,staticPosition) {
	if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		this.applyGlobalX(domElement,containingDOMElementData.globalX);
		domElement.getStyle().setNativeX(domElement,this.getLeftOffset(domElement));
	} else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		this.applyGlobalX(domElement,containingDOMElementData.globalX);
		domElement.getStyle().setNativeX(domElement,this.getRightOffset(domElement,containingDOMElementData.width));
	} else domElement.getStyle().setNativeX(domElement,Math.round(staticPosition.x));
	if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		this.applyGlobalY(domElement,containingDOMElementData.globalY);
		domElement.getStyle().setNativeY(domElement,this.getTopOffset(domElement));
	} else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		this.applyGlobalY(domElement,containingDOMElementData.globalY);
		domElement.getStyle().setNativeY(domElement,this.getBottomOffset(domElement,containingDOMElementData.height));
	} else domElement.getStyle().setNativeY(domElement,Math.round(staticPosition.y));
}
cocktailCore.style.positioner.BoxPositioner.prototype.applyGlobalX = function(domElement,globalX) {
	domElement.setGlobalX(globalX);
}
cocktailCore.style.positioner.BoxPositioner.prototype.applyGlobalY = function(domElement,globalY) {
	domElement.setGlobalY(globalY);
}
cocktailCore.style.positioner.BoxPositioner.prototype.getLeftOffset = function(domElement) {
	return domElement.getStyle().getNativeX() + domElement.getStyle().getComputedStyle().left + domElement.getStyle().getComputedStyle().marginLeft;
}
cocktailCore.style.positioner.BoxPositioner.prototype.getRightOffset = function(domElement,containingDOMElementWidth) {
	return domElement.getStyle().getNativeX() + containingDOMElementWidth - domElement.getStyle().getComputedStyle().width - domElement.getStyle().getComputedStyle().right - domElement.getStyle().getComputedStyle().marginRight;
}
cocktailCore.style.positioner.BoxPositioner.prototype.getTopOffset = function(domElement) {
	return domElement.getStyle().getNativeY() + domElement.getStyle().getComputedStyle().top + domElement.getStyle().getComputedStyle().marginTop;
}
cocktailCore.style.positioner.BoxPositioner.prototype.getBottomOffset = function(domElement,containingDOMElementHeight) {
	return domElement.getStyle().getNativeY() + containingDOMElementHeight - domElement.getStyle().getComputedStyle().height - domElement.getStyle().getComputedStyle().bottom - domElement.getStyle().getComputedStyle().marginBottom;
}
cocktailCore.style.positioner.BoxPositioner.prototype.__class__ = cocktailCore.style.positioner.BoxPositioner;
utest.ui.common.IReport = function() { }
utest.ui.common.IReport.__name__ = ["utest","ui","common","IReport"];
utest.ui.common.IReport.prototype.displaySuccessResults = null;
utest.ui.common.IReport.prototype.displayHeader = null;
utest.ui.common.IReport.prototype.setHandler = null;
utest.ui.common.IReport.prototype.__class__ = utest.ui.common.IReport;
cocktailCore.style.js.ContainerStyle = function(domElement) {
	if( domElement === $_ ) return;
	cocktailCore.style.abstract.AbstractContainerStyle.call(this,domElement);
}
cocktailCore.style.js.ContainerStyle.__name__ = ["cocktailCore","style","js","ContainerStyle"];
cocktailCore.style.js.ContainerStyle.__super__ = cocktailCore.style.abstract.AbstractContainerStyle;
for(var k in cocktailCore.style.abstract.AbstractContainerStyle.prototype ) cocktailCore.style.js.ContainerStyle.prototype[k] = cocktailCore.style.abstract.AbstractContainerStyle.prototype[k];
cocktailCore.style.js.ContainerStyle.prototype.flowChildren = function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	var containerDOMElement = this._domElement;
	var _g1 = 0, _g = containerDOMElement.getChildren().length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
			var childrenDOMElement = containerDOMElement.getChildren()[i].child;
			childrenDOMElement.getStyle().flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext);
		}
	}
}
cocktailCore.style.js.ContainerStyle.prototype.__class__ = cocktailCore.style.js.ContainerStyle;
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
cocktailCore.unit.UnitManager.prototype.__class__ = cocktailCore.unit.UnitManager;
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
cocktailCore.font.abstract.AbstractFontLoader = function(p) {
	if( p === $_ ) return;
	this._successCallbackArray = new Array();
	this._errorCallbackArray = new Array();
}
cocktailCore.font.abstract.AbstractFontLoader.__name__ = ["cocktailCore","font","abstract","AbstractFontLoader"];
cocktailCore.font.abstract.AbstractFontLoader.prototype.fontData = null;
cocktailCore.font.abstract.AbstractFontLoader.prototype._successCallbackArray = null;
cocktailCore.font.abstract.AbstractFontLoader.prototype._errorCallbackArray = null;
cocktailCore.font.abstract.AbstractFontLoader.prototype.load = function(url,name) {
	var extension = url.substr(url.lastIndexOf("."),url.length);
	this.fontData = { url : url, name : name, type : cocktail.font.FontType.unknown};
	if(extension == ".ttf") this.fontData.type = cocktail.font.FontType.ttf; else if(extension == ".eot") this.fontData.type = cocktail.font.FontType.eot; else if(extension == ".otf") this.fontData.type = cocktail.font.FontType.otf; else if(extension == ".swf") this.fontData.type = cocktail.font.FontType.swf; else this.fontData.type = cocktail.font.FontType.unknown;
}
cocktailCore.font.abstract.AbstractFontLoader.prototype.addCallback = function(successCallback,errorCallback) {
	if(successCallback != null) this._successCallbackArray.push(successCallback);
	if(errorCallback != null) this._errorCallbackArray.push(errorCallback);
}
cocktailCore.font.abstract.AbstractFontLoader.prototype._successCallback = function() {
	var idx;
	var _g1 = 0, _g = this._successCallbackArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		this._successCallbackArray[idx1](this.fontData);
	}
	this.cleanup();
}
cocktailCore.font.abstract.AbstractFontLoader.prototype._errorCallback = function(errorStr) {
	var idx;
	var _g1 = 0, _g = this._errorCallbackArray.length;
	while(_g1 < _g) {
		var idx1 = _g1++;
		this._errorCallbackArray[idx1](this.fontData,errorStr);
	}
	this.cleanup();
}
cocktailCore.font.abstract.AbstractFontLoader.prototype.cleanup = function() {
	while(this._successCallbackArray.length > 0) this._successCallbackArray.pop();
	while(this._errorCallbackArray.length > 0) this._errorCallbackArray.pop();
}
cocktailCore.font.abstract.AbstractFontLoader.prototype.__class__ = cocktailCore.font.abstract.AbstractFontLoader;
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
		verticalAlign = 0;
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
cocktailCore.domElement.js.ImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.ImageDOMElement.__name__ = ["cocktailCore","domElement","js","ImageDOMElement"];
cocktailCore.domElement.js.ImageDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype ) cocktailCore.domElement.js.ImageDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k];
cocktailCore.domElement.js.ImageDOMElement.prototype.onLoadComplete = function(image) {
	this._src = image.src;
	this._intrinsicHeight = image.naturalHeight;
	this._intrinsicWidth = image.naturalWidth;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
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
cocktailCore.style.positioner.RelativePositioner.prototype.applyGlobalX = function(domElement,globalX) {
}
cocktailCore.style.positioner.RelativePositioner.prototype.applyGlobalY = function(domElement,globalY) {
}
cocktailCore.style.positioner.RelativePositioner.prototype.getLeftOffset = function(domElement) {
	return domElement.getStyle().getNativeX() + domElement.getStyle().getComputedStyle().left;
}
cocktailCore.style.positioner.RelativePositioner.prototype.getRightOffset = function(domElement,containingDOMElementWidth) {
	return domElement.getStyle().getNativeX() + containingDOMElementWidth - domElement.getStyle().getComputedStyle().width - domElement.getStyle().getComputedStyle().right;
}
cocktailCore.style.positioner.RelativePositioner.prototype.getTopOffset = function(domElement) {
	return domElement.getStyle().getNativeY() + domElement.getStyle().getComputedStyle().top;
}
cocktailCore.style.positioner.RelativePositioner.prototype.getBottomOffset = function(domElement,containingDOMElementHeight) {
	return domElement.getStyle().getNativeY() + containingDOMElementHeight - domElement.getStyle().getComputedStyle().height - domElement.getStyle().getComputedStyle().bottom;
}
cocktailCore.style.positioner.RelativePositioner.prototype.__class__ = cocktailCore.style.positioner.RelativePositioner;
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = function(text) {
	if( text === $_ ) return;
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
if(!cocktail.mouse) cocktail.mouse = {}
cocktail.mouse.MouseCursorValue = { __ename__ : ["cocktail","mouse","MouseCursorValue"], __constructs__ : ["custom","autoValue","none","native"] }
cocktail.mouse.MouseCursorValue.custom = function(imageDOMElement,hotSpot) { var $x = ["custom",0,imageDOMElement,hotSpot]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.MouseCursorValue.autoValue = ["autoValue",1];
cocktail.mouse.MouseCursorValue.autoValue.toString = $estr;
cocktail.mouse.MouseCursorValue.autoValue.__enum__ = cocktail.mouse.MouseCursorValue;
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
	var resetAngle = Math.PI * 2 - currentRotation;
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
	if(rotationInRad < 0) rotationInRad = Math.PI + rotationInRad;
	return rotationInRad;
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
cocktailCore.style.js.EmbeddedStyle.prototype.__class__ = cocktailCore.style.js.EmbeddedStyle;
if(!cocktail.viewport) cocktail.viewport = {}
cocktail.viewport.OrientationValue = { __ename__ : ["cocktail","viewport","OrientationValue"], __constructs__ : ["vertical","horizontal"] }
cocktail.viewport.OrientationValue.vertical = ["vertical",0];
cocktail.viewport.OrientationValue.vertical.toString = $estr;
cocktail.viewport.OrientationValue.vertical.__enum__ = cocktail.viewport.OrientationValue;
cocktail.viewport.OrientationValue.horizontal = ["horizontal",1];
cocktail.viewport.OrientationValue.horizontal.toString = $estr;
cocktail.viewport.OrientationValue.horizontal.__enum__ = cocktail.viewport.OrientationValue;
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
cocktailCore.domElement.js.TextFragmentDOMElement = function(nativeElement,style) {
	if( nativeElement === $_ ) return;
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype ) cocktailCore.domElement.js.TextFragmentDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype[k];
cocktailCore.domElement.js.TextFragmentDOMElement.prototype.__class__ = cocktailCore.domElement.js.TextFragmentDOMElement;
cocktailCore.resource.js.ImageLoader = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.resource.abstract.AbstractImageLoader.call(this,nativeElement);
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractImageLoader;
for(var k in cocktailCore.resource.abstract.AbstractImageLoader.prototype ) cocktailCore.resource.js.ImageLoader.prototype[k] = cocktailCore.resource.abstract.AbstractImageLoader.prototype[k];
cocktailCore.resource.js.ImageLoader.prototype.__class__ = cocktailCore.resource.js.ImageLoader;
if(!cocktail.font) cocktail.font = {}
cocktail.font.FontType = { __ename__ : ["cocktail","font","FontType"], __constructs__ : ["ttf","otf","eot","swf","system","unknown"] }
cocktail.font.FontType.ttf = ["ttf",0];
cocktail.font.FontType.ttf.toString = $estr;
cocktail.font.FontType.ttf.__enum__ = cocktail.font.FontType;
cocktail.font.FontType.otf = ["otf",1];
cocktail.font.FontType.otf.toString = $estr;
cocktail.font.FontType.otf.__enum__ = cocktail.font.FontType;
cocktail.font.FontType.eot = ["eot",2];
cocktail.font.FontType.eot.toString = $estr;
cocktail.font.FontType.eot.__enum__ = cocktail.font.FontType;
cocktail.font.FontType.swf = ["swf",3];
cocktail.font.FontType.swf.toString = $estr;
cocktail.font.FontType.swf.__enum__ = cocktail.font.FontType;
cocktail.font.FontType.system = ["system",4];
cocktail.font.FontType.system.toString = $estr;
cocktail.font.FontType.system.__enum__ = cocktail.font.FontType;
cocktail.font.FontType.unknown = ["unknown",5];
cocktail.font.FontType.unknown.toString = $estr;
cocktail.font.FontType.unknown.__enum__ = cocktail.font.FontType;
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
if(!cocktail.nativeElement) cocktail.nativeElement = {}
cocktail.nativeElement.NativeElementTypeValue = { __ename__ : ["cocktail","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","library","skin","custom"] }
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
cocktail.nativeElement.NativeElementTypeValue.custom = function(name) { var $x = ["custom",6,name]; $x.__enum__ = cocktail.nativeElement.NativeElementTypeValue; $x.toString = $estr; return $x; }
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
	if(previousFormatingContext != null) this._floatsManager.addFloats(previousFormatingContext);
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
	domElement.getStyle().setNativeY(domElement,floatData.y + domElement.getStyle().getComputedStyle().marginTop);
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
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedWidth = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedHeight = function(style,containingDOMElementData) {
	return 0;
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
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
haxe.Log = function() { }
haxe.Log.__name__ = ["haxe","Log"];
haxe.Log.trace = function(v,infos) {
	js.Boot.__trace(v,infos);
}
haxe.Log.clear = function() {
	js.Boot.__clear_trace();
}
haxe.Log.prototype.__class__ = haxe.Log;
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
	if(fillStyle == null) fillStyle = cocktail.domElement.FillStyleValue.none;
	if(lineStyle == null) lineStyle = cocktail.domElement.LineStyleValue.none;
	this.setFillStyle(fillStyle);
	this.setLineStyle(lineStyle);
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.endFill = function() {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.clear = function() {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setLineStyle = function(lineStyle) {
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.setFillStyle = function(fillStyle) {
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.beginFill = function(fillStyle,lineStyle) {
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill.call(this,fillStyle,lineStyle);
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
cocktailCore.font.js.FontLoader = function(p) {
	if( p === $_ ) return;
	cocktailCore.font.abstract.AbstractFontLoader.call(this);
}
cocktailCore.font.js.FontLoader.__name__ = ["cocktailCore","font","js","FontLoader"];
cocktailCore.font.js.FontLoader.__super__ = cocktailCore.font.abstract.AbstractFontLoader;
for(var k in cocktailCore.font.abstract.AbstractFontLoader.prototype ) cocktailCore.font.js.FontLoader.prototype[k] = cocktailCore.font.abstract.AbstractFontLoader.prototype[k];
cocktailCore.font.js.FontLoader.prototype._styleE = null;
cocktailCore.font.js.FontLoader.prototype.load = function(url,name) {
	cocktailCore.font.abstract.AbstractFontLoader.prototype.load.call(this,url,name);
	if(this.fontData.type != cocktail.font.FontType.swf) {
		var fontTypeString = "";
		if(this.fontData.type == cocktail.font.FontType.ttf) fontTypeString = " format(\"truetype\")"; else fontTypeString = "";
		this._styleE = js.Lib.document.createElement("style");
		this._styleE.innerHTML = "@font-face{font-family: " + name + " ; src: url( \"" + url + "\" )" + fontTypeString + ";}";
		js.Lib.document.getElementsByTagName("head")[0].appendChild(this._styleE);
		this._successCallback();
	} else {
		haxe.Log.trace("Could not load font, the font format is not appropriate for the target: " + url,{ fileName : "FontLoader.hx", lineNumber : 81, className : "cocktailCore.font.js.FontLoader", methodName : "load"});
		this._errorCallback("Could not load font, the font format is not appropriate for the target: " + url);
	}
}
cocktailCore.font.js.FontLoader.prototype.cleanup = function() {
	cocktailCore.font.abstract.AbstractFontLoader.prototype.cleanup.call(this);
}
cocktailCore.font.js.FontLoader.prototype.__class__ = cocktailCore.font.js.FontLoader;
cocktailCore.style.positioner.FixedPositioner = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.FixedPositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.FixedPositioner.prototype.applyGlobalX = function(domElement,globalX) {
	domElement.setGlobalX(0);
}
cocktailCore.style.positioner.FixedPositioner.prototype.applyGlobalY = function(domElement,globalY) {
	domElement.setGlobalY(0);
}
cocktailCore.style.positioner.FixedPositioner.prototype.__class__ = cocktailCore.style.positioner.FixedPositioner;
if(!cocktail.resource) cocktail.resource = {}
cocktail.resource.LoadingTypeValue = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",1];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
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
	case 6:
		var name = $e[2];
		nativeElement = js.Lib.document.createElement(name);
		break;
	case 4:
		nativeElement = js.Lib.document.createElement("script");
		break;
	case 5:
		nativeElement = js.Lib.document.createElement("div");
		break;
	}
	return nativeElement;
}
cocktailCore.nativeElement.js.NativeElementCreator.prototype.__class__ = cocktailCore.nativeElement.js.NativeElementCreator;
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
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.shrinkToFit = function(style,containingDOMElementData,minimumWidth) {
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
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.applyContentHeight = function(style,containingDOMElementData,childrenHeight) {
	var height;
	if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		var computedStyle = style.getComputedStyle();
		height = containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
	} else height = childrenHeight;
	return height;
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureAutoWidth = function(style,containingDOMElementData) {
	var computedStyle = style.getComputedStyle();
	if(style.getMarginLeft() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginLeft = 0; else style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	if(style.getMarginRight() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginRight = 0; else style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	if(style.getLeft() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getRight() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().width = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
	}
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureWidth = function(style,containingDOMElementData) {
	var computedStyle = style.getComputedStyle();
	style.getComputedStyle().width = this.getComputedWidth(style,containingDOMElementData);
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
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureAutoHeight = function(style,containingDOMElementData) {
	var computedStyle = style.getComputedStyle();
	if(style.getMarginTop() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginTop = 0; else style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	if(style.getMarginBottom() == cocktail.style.MarginStyleValue.autoValue) style.getComputedStyle().marginBottom = 0; else style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	if(style.getTop() != cocktail.style.PositionOffsetStyleValue.autoValue && style.getBottom() != cocktail.style.PositionOffsetStyleValue.autoValue) {
		style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().height = containingDOMElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom;
	}
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measureHeight = function(style,containingDOMElementData) {
	var computedStyle = style.getComputedStyle();
	style.getComputedStyle().height = this.getComputedHeight(style,containingDOMElementData);
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
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.getComputedStaticLeft = function(style,containingDOMElementData) {
	return style.getComputedStyle().marginLeft;
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.getComputedStaticTop = function(style,containingDOMElementData) {
	return style.getComputedStyle().marginTop;
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.doShrinkToFit = function(style,containingDOMElementData,minimumWidth) {
	var shrinkedWidth;
	if(minimumWidth < containingDOMElementData.width) shrinkedWidth = minimumWidth; else shrinkedWidth = containingDOMElementData.width;
	return shrinkedWidth;
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
	this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktail.style.InlineBoxValue.domElement});
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
	this._domElementInLineBox.push({ domElement : domElement, domElementType : cocktail.style.InlineBoxValue.space});
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
		var lineWidth = this.alignLineBox(this._firstLineLaidOut == false,isLastLine);
		if(lineWidth > this._flowData.maxWidth) this._flowData.maxWidth = lineWidth;
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
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignLineBox = function(isFirstLine,isLastLine) {
	var concatenatedLength = 0;
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		concatenatedLength += this._domElementInLineBox[i].domElement.getOffsetWidth();
	}
	var remainingSpace;
	var flowX;
	if(isFirstLine == true) {
		remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._containingDOMElement.getStyle().getComputedStyle().textIndent - this._floatsManager.getLeftFloatOffset(this._flowData.y) - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
		flowX = this._containingDOMElement.getStyle().getComputedStyle().textIndent;
	} else {
		remainingSpace = this._containingDOMElementWidth - concatenatedLength - this._floatsManager.getLeftFloatOffset(this._flowData.y) - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
		flowX = 0;
	}
	flowX += this._floatsManager.getLeftFloatOffset(this._flowData.y) + this._flowData.xOffset;
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
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignLeft = function(flowX) {
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		var domElement = this._domElementInLineBox[i].domElement;
		domElement.getStyle().setNativeX(domElement,flowX + domElement.getStyle().getComputedStyle().marginLeft);
		flowX += domElement.getOffsetWidth();
	}
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignCenter = function(flowX,remainingSpace) {
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		var domElement = this._domElementInLineBox[i].domElement;
		domElement.getStyle().setNativeX(domElement,Math.round(remainingSpace / 2) + flowX + domElement.getStyle().getComputedStyle().marginLeft);
		flowX += domElement.getOffsetWidth();
	}
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignRight = function(flowX,remainingSpace) {
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		var domElement = this._domElementInLineBox[i].domElement;
		domElement.getStyle().setNativeX(domElement,flowX + domElement.getStyle().getComputedStyle().marginLeft + remainingSpace);
		flowX += domElement.getOffsetWidth();
	}
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignJustify = function(flowX,remainingSpace) {
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
		domElement.getStyle().setNativeX(domElement,flowX + domElement.getStyle().getComputedStyle().marginLeft);
		flowX += domElement.getOffsetWidth();
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
		if(domElement.getStyle().isEmbedded() == true || domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) domElement.getStyle().setNativeY(domElement,domElement.getStyle().getNativeY() - domElement.getOffsetHeight());
	}
	return Math.round(lineBoxHeight);
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.__class__ = cocktailCore.style.formatter.InlineFormattingContext;
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
cocktail.style.MarginStyleValue = { __ename__ : ["cocktail","style","MarginStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.MarginStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.autoValue = ["autoValue",2];
cocktail.style.MarginStyleValue.autoValue.toString = $estr;
cocktail.style.MarginStyleValue.autoValue.__enum__ = cocktail.style.MarginStyleValue;
cocktail.style.PaddingStyleValue = { __ename__ : ["cocktail","style","PaddingStyleValue"], __constructs__ : ["length","percent"] }
cocktail.style.PaddingStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PaddingStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue = { __ename__ : ["cocktail","style","DimensionStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.DimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.autoValue = ["autoValue",2];
cocktail.style.DimensionStyleValue.autoValue.toString = $estr;
cocktail.style.DimensionStyleValue.autoValue.__enum__ = cocktail.style.DimensionStyleValue;
cocktail.style.ConstrainedDimensionStyleValue = { __ename__ : ["cocktail","style","ConstrainedDimensionStyleValue"], __constructs__ : ["length","percent","none"] }
cocktail.style.ConstrainedDimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.none = ["none",2];
cocktail.style.ConstrainedDimensionStyleValue.none.toString = $estr;
cocktail.style.ConstrainedDimensionStyleValue.none.__enum__ = cocktail.style.ConstrainedDimensionStyleValue;
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
cocktail.style.PositionOffsetStyleValue = { __ename__ : ["cocktail","style","PositionOffsetStyleValue"], __constructs__ : ["length","percent","autoValue"] }
cocktail.style.PositionOffsetStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.autoValue = ["autoValue",2];
cocktail.style.PositionOffsetStyleValue.autoValue.toString = $estr;
cocktail.style.PositionOffsetStyleValue.autoValue.__enum__ = cocktail.style.PositionOffsetStyleValue;
cocktail.style.VisibilityStyleValue = { __ename__ : ["cocktail","style","VisibilityStyleValue"], __constructs__ : ["visible","hidden"] }
cocktail.style.VisibilityStyleValue.visible = ["visible",0];
cocktail.style.VisibilityStyleValue.visible.toString = $estr;
cocktail.style.VisibilityStyleValue.visible.__enum__ = cocktail.style.VisibilityStyleValue;
cocktail.style.VisibilityStyleValue.hidden = ["hidden",1];
cocktail.style.VisibilityStyleValue.hidden.toString = $estr;
cocktail.style.VisibilityStyleValue.hidden.__enum__ = cocktail.style.VisibilityStyleValue;
cocktail.style.OpacityStyleValue = { __ename__ : ["cocktail","style","OpacityStyleValue"], __constructs__ : ["number"] }
cocktail.style.OpacityStyleValue.number = function(value) { var $x = ["number",0,value]; $x.__enum__ = cocktail.style.OpacityStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformStyleValue = { __ename__ : ["cocktail","style","TransformStyleValue"], __constructs__ : ["none","transformFunctions"] }
cocktail.style.TransformStyleValue.none = ["none",0];
cocktail.style.TransformStyleValue.none.toString = $estr;
cocktail.style.TransformStyleValue.none.__enum__ = cocktail.style.TransformStyleValue;
cocktail.style.TransformStyleValue.transformFunctions = function(transformFunctions) { var $x = ["transformFunctions",1,transformFunctions]; $x.__enum__ = cocktail.style.TransformStyleValue; $x.toString = $estr; return $x; }
cocktail.style.TransformFunctionValue = { __ename__ : ["cocktail","style","TransformFunctionValue"], __constructs__ : ["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","skew"] }
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
cocktail.style.TranslationValue = { __ename__ : ["cocktail","style","TranslationValue"], __constructs__ : ["length","percent"] }
cocktail.style.TranslationValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.TranslationValue; $x.toString = $estr; return $x; }
cocktail.style.TranslationValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.TranslationValue; $x.toString = $estr; return $x; }
cocktail.style.TransformOriginXStyleValue = { __ename__ : ["cocktail","style","TransformOriginXStyleValue"], __constructs__ : ["length","percent","left","center","right"] }
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
cocktail.style.TransformOriginYStyleValue = { __ename__ : ["cocktail","style","TransformOriginYStyleValue"], __constructs__ : ["length","percent","top","center","bottom"] }
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
cocktail.style.InlineBoxValue = { __ename__ : ["cocktail","style","InlineBoxValue"], __constructs__ : ["domElement","space","tab"] }
cocktail.style.InlineBoxValue.domElement = ["domElement",0];
cocktail.style.InlineBoxValue.domElement.toString = $estr;
cocktail.style.InlineBoxValue.domElement.__enum__ = cocktail.style.InlineBoxValue;
cocktail.style.InlineBoxValue.space = ["space",1];
cocktail.style.InlineBoxValue.space.toString = $estr;
cocktail.style.InlineBoxValue.space.__enum__ = cocktail.style.InlineBoxValue;
cocktail.style.InlineBoxValue.tab = ["tab",2];
cocktail.style.InlineBoxValue.tab.toString = $estr;
cocktail.style.InlineBoxValue.tab.__enum__ = cocktail.style.InlineBoxValue;
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
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
	this.measureHorizontalPositionOffsets(style,containingDOMElementData);
	this.measureVerticalPositionOffsets(style,containingDOMElementData);
	style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measureHorizontalPositionOffsets = function(style,containingDOMElementData) {
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
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.measureVerticalPositionOffsets = function(style,containingDOMElementData) {
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
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.getComputedStaticLeft = function(style,containingDOMElementData) {
	return style.getComputedStyle().marginLeft;
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.getComputedStaticTop = function(style,containingDOMElementData) {
	return style.getComputedStyle().marginTop;
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
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
cocktail.unit.AngleValue = { __ename__ : ["cocktail","unit","AngleValue"], __constructs__ : ["deg","grad","rad","turn"] }
cocktail.unit.AngleValue.deg = function(value) { var $x = ["deg",0,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.grad = function(value) { var $x = ["grad",1,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.rad = function(value) { var $x = ["rad",2,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
cocktail.unit.AngleValue.turn = function(value) { var $x = ["turn",3,value]; $x.__enum__ = cocktail.unit.AngleValue; $x.toString = $estr; return $x; }
if(typeof font=='undefined') font = {}
font.FontTests = function(p) {
	if( p === $_ ) return;
	font.FontTests._fontManager = new cocktailCore.font.js.FontManager();
}
font.FontTests.__name__ = ["font","FontTests"];
font.FontTests._fontManager = null;
font.FontTests.main = function() {
	var runner = new utest.Runner();
	runner.addCase(new font.FontTests());
	utest.ui.Report.create(runner);
	runner.run();
}
font.FontTests.prototype.testFontLoad = function() {
	haxe.Log.trace("*************** *************** *************** ***************",{ fileName : "FontTests.hx", lineNumber : 77, className : "font.FontTests", methodName : "testFontLoad"});
	haxe.Log.trace("IMPORTANT CHECK TO DO : check that the text on top of the page has an embeded font",{ fileName : "FontTests.hx", lineNumber : 78, className : "font.FontTests", methodName : "testFontLoad"});
	haxe.Log.trace("*************** *************** *************** ***************",{ fileName : "FontTests.hx", lineNumber : 79, className : "font.FontTests", methodName : "testFontLoad"});
	var successCallback = utest.Assert.createEvent($closure(this,"onFontLoaded"));
	font.FontTests._fontManager.loadFont("embed_test_font.ttf","EmbedFontTest",successCallback,$closure(this,"onFontLoadError"));
	js.Lib.document.body.innerHTML += "<h1>Here is text with embed font</h1><br />\n\t\t\t\t<span style=\"font-size: 16pt; font-family: EmbedFontTest;\">ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789.:,;(:*!?&apos;&quot;) The quick brown fox jumps over the lazy dog.<br /><hr /><br />";
}
font.FontTests.prototype.onFontLoaded = function(fontData) {
	utest.Assert.isTrue(true,null,{ fileName : "FontTests.hx", lineNumber : 98, className : "font.FontTests", methodName : "onFontLoaded"});
	var successCallback = utest.Assert.createEvent($closure(this,"onFontLoaded2"));
	font.FontTests._fontManager.loadFont("embed_test_font.eot","EmbedFontTest",successCallback,$closure(this,"onFontLoadError"));
}
font.FontTests.prototype.onFontLoaded2 = function(fontData) {
	utest.Assert.isTrue(true,null,{ fileName : "FontTests.hx", lineNumber : 107, className : "font.FontTests", methodName : "onFontLoaded2"});
	var successCallback = utest.Assert.createEvent($closure(this,"onFontLoaded3"));
	font.FontTests._fontManager.loadFont("embed_test_font.otf","EmbedFontTest",successCallback,$closure(this,"onFontLoadError"));
}
font.FontTests.prototype.onFontLoaded3 = function(fontData) {
	utest.Assert.isTrue(true,null,{ fileName : "FontTests.hx", lineNumber : 132, className : "font.FontTests", methodName : "onFontLoaded3"});
	haxe.Log.trace(font.FontTests._fontManager.getEmbeddedFonts(),{ fileName : "FontTests.hx", lineNumber : 135, className : "font.FontTests", methodName : "onFontLoaded3"});
	utest.Assert.isTrue(font.FontTests._fontManager.hasFont("EmbedFontTest"),null,{ fileName : "FontTests.hx", lineNumber : 136, className : "font.FontTests", methodName : "onFontLoaded3"});
}
font.FontTests.prototype.errorCallbackAssync = null;
font.FontTests.prototype.onFontLoaded4 = function(fontData) {
}
font.FontTests.prototype.onFontLoadError = function(fontData,msg) {
	this.errorCallbackAssync(msg);
}
font.FontTests.prototype.onFontLoadErrorUTest = function(msg) {
	utest.Assert.isTrue(true,null,{ fileName : "FontTests.hx", lineNumber : 161, className : "font.FontTests", methodName : "onFontLoadErrorUTest"});
	haxe.Log.trace("Font loading error : " + msg,{ fileName : "FontTests.hx", lineNumber : 162, className : "font.FontTests", methodName : "onFontLoadErrorUTest"});
}
font.FontTests.prototype.__class__ = font.FontTests;
utest.Assertation = { __ename__ : ["utest","Assertation"], __constructs__ : ["Success","Failure","Error","SetupError","TeardownError","TimeoutError","AsyncError","Warning"] }
utest.Assertation.Success = function(pos) { var $x = ["Success",0,pos]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Failure = function(msg,pos) { var $x = ["Failure",1,msg,pos]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Error = function(e,stack) { var $x = ["Error",2,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.SetupError = function(e,stack) { var $x = ["SetupError",3,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.TeardownError = function(e,stack) { var $x = ["TeardownError",4,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.TimeoutError = function(missedAsyncs,stack) { var $x = ["TimeoutError",5,missedAsyncs,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.AsyncError = function(e,stack) { var $x = ["AsyncError",6,e,stack]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
utest.Assertation.Warning = function(msg) { var $x = ["Warning",7,msg]; $x.__enum__ = utest.Assertation; $x.toString = $estr; return $x; }
if(!cocktailCore.mouse) cocktailCore.mouse = {}
if(!cocktailCore.mouse["abstract"]) cocktailCore.mouse["abstract"] = {}
cocktailCore.mouse.abstract.AbstractMouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	this._nativeElement = nativeElement;
}
cocktailCore.mouse.abstract.AbstractMouse.__name__ = ["cocktailCore","mouse","abstract","AbstractMouse"];
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseDown = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDown = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseUp = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseUp = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseOver = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOver = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseOut = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOut = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseMove = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseMove = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._onMouseDoubleClick = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDoubleClick = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype._nativeElement = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDown = function(event) {
	if(this.getOnMouseDown() != null) (this.getOnMouseDown())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseUp = function(event) {
	if(this.getOnMouseUp() != null) (this.getOnMouseUp())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOver = function(event) {
	if(this.getOnMouseOver() != null) (this.getOnMouseOver())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOut = function(event) {
	if(this.getOnMouseOut() != null) (this.getOnMouseOut())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseMove = function(event) {
	if(this.getOnMouseMove() != null) (this.getOnMouseMove())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDoubleClick = function(event) {
	if(this.getOnMouseDoubleClick() != null) (this.getOnMouseDoubleClick())(this.getMouseData(event));
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getMouseData = function(event) {
	return null;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseDown = function(value) {
	return this._onMouseDown = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseDown = function() {
	return this._onMouseDown;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseUp = function(value) {
	return this._onMouseUp = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseUp = function() {
	return this._onMouseUp;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseOver = function(value) {
	return this._onMouseOver = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseOver = function() {
	return this._onMouseOver;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseOut = function(value) {
	return this._onMouseOut = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseOut = function() {
	return this._onMouseOut;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseMove = function(value) {
	return this._onMouseMove = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseMove = function() {
	return this._onMouseMove;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.setOnMouseDoubleClick = function(value) {
	return this._onMouseDoubleClick = value;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getOnMouseDoubleClick = function() {
	return this._onMouseDoubleClick;
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.__class__ = cocktailCore.mouse.abstract.AbstractMouse;
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
	switch( (domElement.getStyle().getComputedStyle().floatValue)[1] ) {
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
cocktailCore.style.computer.VisualEffectStylesComputer = function(p) {
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
cocktailCore.style.computer.VisualEffectStylesComputer.prototype.__class__ = cocktailCore.style.computer.VisualEffectStylesComputer;
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
if(!cocktail.nativeInstance) cocktail.nativeInstance = {}
cocktail.nativeInstance.NativeInstanceManager = function(p) {
}
cocktail.nativeInstance.NativeInstanceManager.__name__ = ["cocktail","nativeInstance","NativeInstanceManager"];
cocktail.nativeInstance.NativeInstanceManager.getClassInstanceByClassName = function(className) {
	return new cocktailCore.classInstance.js.ClassInstance(className);
}
cocktail.nativeInstance.NativeInstanceManager.createInstanceOf = function(classReference) {
	return cocktail.nativeInstance.NativeInstanceManager.getClassInstanceByClassName(Type.getClassName(classReference));
}
cocktail.nativeInstance.NativeInstanceManager.prototype.__class__ = cocktail.nativeInstance.NativeInstanceManager;
if(!cocktailCore.mouse.js) cocktailCore.mouse.js = {}
cocktailCore.mouse.js.Mouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	cocktailCore.mouse.abstract.AbstractMouse.call(this,nativeElement);
}
cocktailCore.mouse.js.Mouse.__name__ = ["cocktailCore","mouse","js","Mouse"];
cocktailCore.mouse.js.Mouse.__super__ = cocktailCore.mouse.abstract.AbstractMouse;
for(var k in cocktailCore.mouse.abstract.AbstractMouse.prototype ) cocktailCore.mouse.js.Mouse.prototype[k] = cocktailCore.mouse.abstract.AbstractMouse.prototype[k];
cocktailCore.mouse.js.Mouse.prototype.setOnMouseDown = function(value) {
	if(value == null) this._nativeElement.onmousedown = null; else this._nativeElement.onmousedown = $closure(this,"onNativeMouseDown");
	return this._onMouseDown = value;
}
cocktailCore.mouse.js.Mouse.prototype.setOnMouseUp = function(value) {
	if(value == null) this._nativeElement.onmouseup = null; else this._nativeElement.onmouseup = $closure(this,"onNativeMouseUp");
	return this._onMouseUp = value;
}
cocktailCore.mouse.js.Mouse.prototype.setOnMouseOver = function(value) {
	if(value == null) this._nativeElement.onmouseover = null; else this._nativeElement.onmouseover = $closure(this,"onNativeMouseOver");
	return this._onMouseOver = value;
}
cocktailCore.mouse.js.Mouse.prototype.setOnMouseOut = function(value) {
	if(value == null) this._nativeElement.onmouseout = null; else this._nativeElement.onmouseout = $closure(this,"onNativeMouseOut");
	return this._onMouseOut = value;
}
cocktailCore.mouse.js.Mouse.prototype.setOnMouseMove = function(value) {
	if(value == null) this._nativeElement.onmousemove = null; else this._nativeElement.onmousemove = $closure(this,"onNativeMouseMove");
	return this._onMouseMove = value;
}
cocktailCore.mouse.js.Mouse.prototype.setOnMouseDoubleClick = function(value) {
	if(value == null) this._nativeElement.ondblclick = null; else this._nativeElement.ondblclick = $closure(this,"onNativeMouseDoubleClick");
	return this._onMouseDoubleClick = value;
}
cocktailCore.mouse.js.Mouse.prototype.getMouseData = function(event) {
	var mousePosition = { localX : event.clientX, localY : event.clientY, globalX : event.screenX, globalY : event.screenY};
	var mouseEventData = { mousePosition : mousePosition, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
	return mouseEventData;
}
cocktailCore.mouse.js.Mouse.prototype.__class__ = cocktailCore.mouse.js.Mouse;
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
utest.ui.text.HtmlReport.platform = "javascript";
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
utest.TestHandler.POLLING_TIME = 10;
font.FontTests.main()