var $_, $hxClasses = $hxClasses || {}, $estr = function() { return js.Boot.__string_rec(this,''); }
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	return proto;
}
var cocktailCore = cocktailCore || {}
if(!cocktailCore.style) cocktailCore.style = {}
if(!cocktailCore.style.computer) cocktailCore.style.computer = {}
cocktailCore.style.computer.BoxStylesComputer = $hxClasses["cocktailCore.style.computer.BoxStylesComputer"] = function() {
}
cocktailCore.style.computer.BoxStylesComputer.__name__ = ["cocktailCore","style","computer","BoxStylesComputer"];
cocktailCore.style.computer.BoxStylesComputer.prototype = {
	measure: function(style,containingDOMElementData) {
		this.measureHorizontalPaddings(style,containingDOMElementData);
		this.measureVerticalPaddings(style,containingDOMElementData);
		this.measureWidthAndHorizontalMargins(style,containingDOMElementData);
		this.measureHeightAndVerticalMargins(style,containingDOMElementData);
		this.measurePositionOffsets(style,containingDOMElementData);
		this.measureDimensionsConstraints(style,containingDOMElementData);
		this.constrainDimensions(style);
	}
	,shrinkToFit: function(computedStyles,availableWidth,minimumWidth) {
		return computedStyles.width;
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
		style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureHorizontalPaddings: function(style,containingDOMElementData) {
		style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,measureWidthAndHorizontalMargins: function(style,containingDOMElementData) {
		if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
	}
	,measureAutoWidth: function(style,containingDOMElementData) {
		style.getComputedStyle().width = 0;
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
		style.getComputedStyle().width = this.getComputedAutoWidth(style,containingDOMElementData);
	}
	,measureWidth: function(style,containingDOMElementData) {
		style.getComputedStyle().width = this.getNativeWidth(style,containingDOMElementData);
		style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
		style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	}
	,measureHeightAndVerticalMargins: function(style,containingDOMElementData) {
		if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
	}
	,measureAutoHeight: function(style,containingDOMElementData) {
		style.getComputedStyle().height = this.getComputedAutoHeight(style,containingDOMElementData);
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	}
	,measureHeight: function(style,containingDOMElementData) {
		style.getComputedStyle().height = this.getComputedHeight(style,containingDOMElementData);
		style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
		style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	}
	,constrainDimensions: function(style) {
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
	,getNativeWidth: function(style,containingDOMElementData) {
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
		return this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedMarginRight: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedMarginTop: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedMarginBottom: function(style,containingDOMElementData) {
		return this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	}
	,getComputedMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
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
	,getComputedPadding: function(paddingStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
	,__class__: cocktailCore.style.computer.BoxStylesComputer
}
if(!cocktailCore.style.computer.boxComputers) cocktailCore.style.computer.boxComputers = {}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		if(isHorizontalMargin == null) isHorizontalMargin = false;
		return 0;
	}
	,shrinkToFit: function(computedStyles,availableWidth,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
		return shrinkedWidth;
	}
	,__class__: cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer
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
var haxe = haxe || {}
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
var Gallery = $hxClasses["Gallery"] = function() {
	this.getDefaultStyle(Gallery.rootDOMElement);
	this.stageWidth = 640;
	this.stageHeight = 480;
	if(this.currentAlbumUrl == null) {
		this.currentAlbumUrl = "http://api.flickr.com/services/feeds/photos_public.gne?lang=fr-fr&format=rss_200";
		this.picturesElements = new Array();
	}
	this.loadGallery(this.currentAlbumUrl);
}
Gallery.__name__ = ["Gallery"];
Gallery.rootDOMElement = null;
Gallery.main = function() {
	Gallery.rootDOMElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.getRoot());
	new Gallery();
}
Gallery.prototype = {
	stageHeight: null
	,stageWidth: null
	,currentMainImage: null
	,currentAlbumUrl: null
	,picturesElements: null
	,loadGallery: function(rssFeedUrl) {
		cocktail.resource.ResourceLoaderManager.loadString("GalleryRssProxy.php?url=" + StringTools.urlEncode(rssFeedUrl),this.onRssFeedLoaded.$bind(this),this.onRssFeedError.$bind(this));
	}
	,onRssFeedError: function(msg) {
	}
	,onRssFeedLoaded: function(response) {
		var galleryXml = Xml.parse(response);
		var channelNode = galleryXml.firstElement().firstElement();
		var $it0 = channelNode.elements();
		while( $it0.hasNext() ) {
			var channelChild = $it0.next();
			if(channelChild.getNodeName() == "item") {
				var $it1 = channelChild.elements();
				while( $it1.hasNext() ) {
					var entryElement = $it1.next();
					if(entryElement.getNodeName() == "media:content") {
						var imageDOMElement = new cocktailCore.domElement.js.ImageDOMElement();
						imageDOMElement.load(entryElement.get("url"));
						this.onPictureLoaded(imageDOMElement);
					}
				}
			}
		}
	}
	,onPictureLoaded: function(imageDOMElement) {
		this.getDefaultStyle(imageDOMElement);
		imageDOMElement.setWidth(80);
		imageDOMElement.setHeight(80);
		imageDOMElement.setX(5 + this.picturesElements.length * 85);
		imageDOMElement.setY(this.stageHeight - 85);
		imageDOMElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
		imageDOMElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(81)));
		imageDOMElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(54)));
		Gallery.rootDOMElement.addChild(imageDOMElement);
		var displayPictureDelegate = this.displayPicture.$bind(this);
		imageDOMElement.setOnMouseUp(function(event) {
			displayPictureDelegate(imageDOMElement);
		});
		this.picturesElements.push(imageDOMElement);
	}
	,displayPicture: function(imageDOMElement) {
		if(this.currentMainImage == null) this.currentMainImage = new cocktailCore.domElement.js.ImageDOMElement();
		this.currentMainImage.load(imageDOMElement.getSrc());
		this.onMainPictureLoaded(imageDOMElement);
	}
	,onMainPictureLoaded: function(imageDOMElement) {
		this.getDefaultStyle(this.currentMainImage);
		this.currentMainImage.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
		this.currentMainImage.setX(5);
		this.currentMainImage.setY(5);
		this.currentMainImage.getStyle().setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(300)));
		this.currentMainImage.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(240)));
		Gallery.rootDOMElement.addChild(this.currentMainImage);
	}
	,getDefaultStyle: function(domElement) {
		domElement.getStyle().setMarginLeft(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setMarginTop(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setRight(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setBottom(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setMinWidth(cocktail.style.ConstrainedDimensionStyleValue.none);
		domElement.getStyle().setMaxWidth(cocktail.style.ConstrainedDimensionStyleValue.none);
		domElement.getStyle().setMinHeight(cocktail.style.ConstrainedDimensionStyleValue.none);
		domElement.getStyle().setMaxHeight(cocktail.style.ConstrainedDimensionStyleValue.none);
		domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(12)));
		domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
		domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.normal);
		domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
		domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
		domElement.getStyle().setFontVariant(cocktail.style.FontVariantStyleValue.normal);
		domElement.getStyle().setTextTransform(cocktail.style.TextTransformStyleValue.none);
		domElement.getStyle().setLetterSpacing(cocktail.style.LetterSpacingStyleValue.normal);
		domElement.getStyle().setWordSpacing(cocktail.style.WordSpacingStyleValue.normal);
		domElement.getStyle().setTextIndent(cocktail.style.TextIndentStyleValue.length(cocktail.unit.LengthValue.px(0)));
		domElement.getStyle().setWhiteSpace(cocktail.style.WhiteSpaceStyleValue.normal);
		domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.left);
		domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.baseline);
		domElement.getStyle().setColor(cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black));
		domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
		domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
		domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.auto);
		domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.auto);
		domElement.getStyle().setFloat(cocktail.style.FloatStyleValue.none);
		domElement.getStyle().setClear(cocktail.style.ClearStyleValue.none);
	}
	,__class__: Gallery
}
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
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = $hxClasses["cocktailCore.style.positioner.BoxPositioner"] = function() {
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype = {
	position: function(domElement,containingDOMElementData,staticPosition) {
		if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.auto) {
			this.applyGlobalX(domElement,containingDOMElementData.globalX);
			domElement.getStyle().setNativeX(domElement,this.getLeftOffset(domElement));
		} else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.auto) {
			this.applyGlobalX(domElement,containingDOMElementData.globalX);
			domElement.getStyle().setNativeX(domElement,this.getRightOffset(domElement,containingDOMElementData.width));
		} else domElement.getStyle().setNativeX(domElement,Math.round(staticPosition.x));
		if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.auto) {
			this.applyGlobalY(domElement,containingDOMElementData.globalY);
			domElement.getStyle().setNativeY(domElement,this.getTopOffset(domElement));
		} else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.auto) {
			this.applyGlobalY(domElement,containingDOMElementData.globalY);
			domElement.getStyle().setNativeY(domElement,this.getBottomOffset(domElement,containingDOMElementData.height));
		} else domElement.getStyle().setNativeY(domElement,Math.round(staticPosition.y));
	}
	,applyGlobalX: function(domElement,globalX) {
		domElement.setGlobalX(globalX);
	}
	,applyGlobalY: function(domElement,globalY) {
		domElement.setGlobalY(globalY);
	}
	,getLeftOffset: function(domElement) {
		return domElement.getStyle().getNativeX(domElement) + domElement.getStyle().getComputedStyle().left + domElement.getStyle().getComputedStyle().marginLeft;
	}
	,getRightOffset: function(domElement,containingDOMElementWidth) {
		return domElement.getStyle().getNativeX(domElement) + containingDOMElementWidth - domElement.getStyle().getComputedStyle().width - domElement.getStyle().getComputedStyle().right - domElement.getStyle().getComputedStyle().marginRight;
	}
	,getTopOffset: function(domElement) {
		return domElement.getStyle().getNativeY(domElement) + domElement.getStyle().getComputedStyle().top + domElement.getStyle().getComputedStyle().marginTop;
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight) {
		return domElement.getStyle().getNativeY(domElement) + containingDOMElementHeight - domElement.getStyle().getComputedStyle().height - domElement.getStyle().getComputedStyle().bottom - domElement.getStyle().getComputedStyle().marginBottom;
	}
	,__class__: cocktailCore.style.positioner.BoxPositioner
}
cocktailCore.style.positioner.AbsolutePositioner = $hxClasses["cocktailCore.style.positioner.AbsolutePositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.AbsolutePositioner.__name__ = ["cocktailCore","style","positioner","AbsolutePositioner"];
cocktailCore.style.positioner.AbsolutePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.AbsolutePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	__class__: cocktailCore.style.positioner.AbsolutePositioner
});
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
	,_registrationPoint: null
	,registrationPoint: null
	,_matrix: null
	,matrix: null
	,scaleX: null
	,scaleY: null
	,translationX: null
	,translationY: null
	,rotation: null
	,alpha: null
	,isVisible: null
	,zIndex: null
	,init: function() {
		this._matrix = new cocktail.geom.Matrix();
		this._keyboard = new cocktailCore.keyboard.js.Keyboard();
		this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
		this._registrationPoint = cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top);
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
		return value;
	}
	,getIsVisible: function() {
		return false;
	}
	,setAlpha: function(value) {
		return value;
	}
	,getAlpha: function() {
		return 0;
	}
	,setMatrix: function(matrix) {
		this._matrix = matrix;
		return this._matrix;
	}
	,getMatrix: function() {
		return this._matrix;
	}
	,resetTransformations: function() {
		this._matrix.identity();
		this.setMatrix(this._matrix);
	}
	,getRegistrationPointValueAsPoint: function(registrationPoint) {
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
	,translate: function(x,y) {
		this._matrix.translate(x,y);
		this.setMatrix(this._matrix);
	}
	,rotate: function(angle,registrationPoint) {
		if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
		this._matrix.rotate(angle,this.getRegistrationPointValueAsPoint(registrationPoint));
		this.setMatrix(this._matrix);
	}
	,scale: function(scaleX,scaleY,registrationPoint) {
		if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
		this._matrix.scale(scaleX,scaleY,this.getRegistrationPointValueAsPoint(registrationPoint));
		this.setMatrix(this._matrix);
	}
	,skew: function(skewX,skewY,registrationPoint) {
		if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
		this._matrix.skew(skewX,skewY,this.getRegistrationPointValueAsPoint(registrationPoint));
		this.setMatrix(this._matrix);
	}
	,setTranslationX: function(translationX) {
		this._matrix.setTranslationX(translationX);
		this.setMatrix(this._matrix);
		return translationX;
	}
	,getTranslationX: function() {
		return this._matrix.getTranslationX();
	}
	,setTranslationY: function(translationY) {
		this._matrix.setTranslationY(translationY);
		this.setMatrix(this._matrix);
		return translationY;
	}
	,getTranslationY: function() {
		return this._matrix.getTranslationY();
	}
	,setScaleX: function(scaleX) {
		this._matrix.setScaleX(scaleX,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
		this.setMatrix(this._matrix);
		return scaleX;
	}
	,getScaleX: function() {
		return this._matrix.getScaleX();
	}
	,setScaleY: function(scaleY) {
		if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
		this._matrix.setScaleY(scaleY,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
		this.setMatrix(this._matrix);
		return scaleY;
	}
	,getScaleY: function() {
		return this._matrix.getScaleY();
	}
	,setRotation: function(angle) {
		if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
		this._matrix.setRotation(angle,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
		this.setMatrix(this._matrix);
		return angle;
	}
	,getRotation: function() {
		return this._matrix.getRotation();
	}
	,setRegistrationPoint: function(registrationPoint) {
		this._registrationPoint = registrationPoint;
		return this._registrationPoint;
	}
	,getRegistrationPoint: function() {
		return this._registrationPoint;
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
		return this._style.getNativeX(this);
	}
	,setY: function(value) {
		this._style.setTop(cocktail.style.PositionOffsetStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeY(this,value);
		return value;
	}
	,getY: function() {
		return this._style.getNativeY(this);
	}
	,setWidth: function(value) {
		this._style.setWidth(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeWidth(this,value);
		return value;
	}
	,getWidth: function() {
		return this._style.getNativeWidth(this);
	}
	,setHeight: function(value) {
		this._style.setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(value)));
		this._style.setNativeHeight(this,value);
		return value;
	}
	,getHeight: function() {
		return this._style.getNativeHeight(this);
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
		var newGlobalX = this._style.getNativeX(this);
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalX += parentDOMElement.getStyle().getNativeX(parentDOMElement);
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
		var newGlobalY = this._style.getNativeY(this);
		if(this._parent != null) {
			var parentDOMElement = this._parent;
			while(parentDOMElement != null) {
				newGlobalY += parentDOMElement.getStyle().getNativeY(parentDOMElement);
				parentDOMElement = parentDOMElement.getParent();
			}
		} else newGlobalY = 0;
		return newGlobalY;
	}
	,setZIndex: function(value) {
		return value;
	}
	,getZIndex: function() {
		return 0;
	}
	,getStyle: function() {
		return this._style;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractDOMElement
	,__properties__: {set_zIndex:"setZIndex",get_zIndex:"getZIndex",set_isVisible:"setIsVisible",get_isVisible:"getIsVisible",set_alpha:"setAlpha",get_alpha:"getAlpha",set_rotation:"setRotation",get_rotation:"getRotation",set_translationY:"setTranslationY",get_translationY:"getTranslationY",set_translationX:"setTranslationX",get_translationX:"getTranslationX",set_scaleY:"setScaleY",get_scaleY:"getScaleY",set_scaleX:"setScaleX",get_scaleX:"getScaleX",set_matrix:"setMatrix",get_matrix:"getMatrix",set_registrationPoint:"setRegistrationPoint",get_registrationPoint:"getRegistrationPoint",get_style:"getStyle",get_offsetHeight:"getOffsetHeight",get_offsetWidth:"getOffsetWidth",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_globalY:"setGlobalY",get_globalY:"getGlobalY",set_y:"setY",get_y:"getY",set_globalX:"setGlobalX",get_globalX:"getGlobalX",set_x:"setX",get_x:"getX",set_parent:"setParent",get_parent:"getParent",set_nativeElement:"setNativeElement",get_nativeElement:"getNativeElement",set_onKeyUp:"setOnKeyUp",get_onKeyUp:"getOnKeyUp",set_onKeyDown:"setOnKeyDown",get_onKeyDown:"getOnKeyDown",set_onMouseDoubleClick:"setOnMouseDoubleClick",get_onMouseDoubleClick:"getOnMouseDoubleClick",set_onMouseMove:"setOnMouseMove",get_onMouseMove:"getOnMouseMove",set_onMouseOut:"setOnMouseOut",get_onMouseOut:"getOnMouseOut",set_onMouseOver:"setOnMouseOver",get_onMouseOver:"getOnMouseOver",set_onMouseUp:"setOnMouseUp",get_onMouseUp:"getOnMouseUp",set_onMouseDown:"setOnMouseDown",get_onMouseDown:"getOnMouseDown"}
}
if(!cocktailCore.domElement.js) cocktailCore.domElement.js = {}
cocktailCore.domElement.js.DOMElement = $hxClasses["cocktailCore.domElement.js.DOMElement"] = function(nativeElement) {
	cocktailCore.domElement.abstract.AbstractDOMElement.call(this,nativeElement);
}
cocktailCore.domElement.js.DOMElement.__name__ = ["cocktailCore","domElement","js","DOMElement"];
cocktailCore.domElement.js.DOMElement.__super__ = cocktailCore.domElement.abstract.AbstractDOMElement;
cocktailCore.domElement.js.DOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractDOMElement.prototype,{
	setIsVisible: function(value) {
		if(value == true) this._nativeElement.style.visibility = "visible"; else this._nativeElement.style.visibility = "hidden";
		return value;
	}
	,getIsVisible: function() {
		if(this._nativeElement.style.visibility == "visible") return true; else return false;
	}
	,setAlpha: function(value) {
		cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha.call(this,value);
		this._nativeElement.style.opacity = value;
		return value;
	}
	,getAlpha: function() {
		return Std.parseFloat(this._nativeElement.style.opacity);
	}
	,setMatrix: function(matrix) {
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
	,setZIndex: function(value) {
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
	,getZIndex: function() {
		return this._nativeElement.style.zIndex;
	}
	,__class__: cocktailCore.domElement.js.DOMElement
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
cocktailCore.domElement.abstract.AbstractGraphicDOMElement = $hxClasses["cocktailCore.domElement.abstract.AbstractGraphicDOMElement"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	this._intrinsicHeight = 150;
	this._intrinsicWidth = 300;
	this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractGraphicDOMElement"];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype = $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype,{
	beginFill: function(fillStyle,lineStyle) {
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
	,drawStar: function(x,y,outerRadius,innerRadius,branches) {
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
	,drawPolygon: function(x,y,radius,sides) {
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
	,conversion: function(val) {
		return val / 180 * Math.PI;
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
	,__class__: cocktailCore.domElement.abstract.AbstractGraphicDOMElement
});
if(!cocktailCore.style["abstract"]) cocktailCore.style["abstract"] = {}
cocktailCore.style.abstract.AbstractStyle = $hxClasses["cocktailCore.style.abstract.AbstractStyle"] = function(domElement) {
	this._domElement = domElement;
	this._isInvalid = true;
	this.initDefaultStyleValues();
}
cocktailCore.style.abstract.AbstractStyle.__name__ = ["cocktailCore","style","abstract","AbstractStyle"];
cocktailCore.style.abstract.AbstractStyle.getDefaultStyle = function() {
	return { fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], color : cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black)};
}
cocktailCore.style.abstract.AbstractStyle.prototype = {
	_marginLeft: null
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
	,_display: null
	,display: null
	,_position: null
	,position: null
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
	,_verticalAlign: null
	,verticalAlign: null
	,_float: null
	,'float': null
	,_clear: null
	,clear: null
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
	,_computedStyle: null
	,computedStyle: null
	,_domElement: null
	,domElement: null
	,_fontMetrics: null
	,fontMetrics: null
	,_isInvalid: null
	,_nativeX: null
	,_nativeY: null
	,_nativeWidth: null
	,_nativeHeight: null
	,initDefaultStyleValues: function() {
		this.setWidth(cocktail.style.DimensionStyleValue.auto);
		this.setHeight(cocktail.style.DimensionStyleValue.auto);
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
		this.setTop(cocktail.style.PositionOffsetStyleValue.auto);
		this.setBottom(cocktail.style.PositionOffsetStyleValue.auto);
		this.setLeft(cocktail.style.PositionOffsetStyleValue.auto);
		this.setRight(cocktail.style.PositionOffsetStyleValue.auto);
		this.setFloat(cocktail.style.FloatStyleValue.none);
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
		var defaultStyles = cocktailCore.style.abstract.AbstractStyle.getDefaultStyle();
		this.setFontFamily(defaultStyles.fontFamily);
		this.setColor(defaultStyles.color);
		this.initComputedStyles();
	}
	,initComputedStyles: function() {
		this._computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
	}
	,layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
	}
	,flow: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
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
	,positionElement: function(lastPositionedDOMElementData,viewportData,staticPosition) {
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
	,scheduleLayout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData) {
		var layoutDelegate = this.layout.$bind(this);
		haxe.Timer.delay(function() {
			layoutDelegate(containingDOMElementData,lastPositionedDOMElementData,viewportData,null);
		},1);
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
		this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
	}
	,insertDOMElement: function(formattingContext,lastPositionedDOMElementData,viewportData) {
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
	,insertInFlowDOMElement: function(formattingContext) {
		formattingContext.insert(this._domElement);
	}
	,invalidate: function() {
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
	,invalidateText: function() {
		this._fontMetrics = null;
		this.invalidate();
	}
	,invalidatePositionOffset: function() {
		if(this.getPosition() != cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
	}
	,invalidateMargin: function() {
		if(this.getPosition() == cocktail.style.PositionStyleValue.relative || this.getPosition() == cocktail.style.PositionStyleValue.staticStyle) this.invalidate();
	}
	,isParentInvalid: function() {
		var ret = true;
		if(this.isPositioned() == true && this.isRelativePositioned() == false) ret = false;
		return ret;
	}
	,computeDOMElement: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData) {
		this.initComputedStyles();
		this.computeDisplayStyles();
		this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
		this.computeBoxModelStyles(containingDOMElementData,viewportData,lastPositionedDOMElementData);
	}
	,computeDisplayStyles: function() {
		cocktailCore.style.computer.DisplayStylesComputer.compute(this);
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
			if(this._computedStyle.position == cocktail.style.PositionStyleValue.fixed) containingBlockDimensions = { width : viewportData.width, height : viewportData.height, isHeightAuto : viewportData.isHeightAuto, isWidthAuto : viewportData.isWidthAuto, globalX : viewportData.globalX, globalY : viewportData.globalY}; else if(this._computedStyle.position == cocktail.style.PositionStyleValue.absolute) containingBlockDimensions = { width : lastPositionedDOMElementData.width, height : lastPositionedDOMElementData.height, isHeightAuto : lastPositionedDOMElementData.isHeightAuto, isWidthAuto : lastPositionedDOMElementData.isWidthAuto, globalX : lastPositionedDOMElementData.globalX, globalY : lastPositionedDOMElementData.globalY}; else containingBlockDimensions = containingDOMElementData;
		} else containingBlockDimensions = containingDOMElementData;
		return containingBlockDimensions;
	}
	,isEmbedded: function() {
		return false;
	}
	,isFloat: function() {
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
	,isInline: function() {
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
	,setNativeX: function(domElement,x) {
		if(domElement == this._domElement) this._nativeX = x;
	}
	,setNativeY: function(domElement,y) {
		if(domElement == this._domElement) this._nativeY = y;
	}
	,setNativeWidth: function(domElement,width) {
		if(domElement == this._domElement) this._nativeWidth = width;
	}
	,setNativeHeight: function(domElement,height) {
		if(domElement == this._domElement) this._nativeHeight = height;
	}
	,getNativeX: function(domElement) {
		return this._nativeX;
	}
	,getNativeY: function(domElement) {
		return this._nativeY;
	}
	,getNativeWidth: function(domElement) {
		return this._nativeWidth;
	}
	,getNativeHeight: function(domElement) {
		return this._nativeHeight;
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
	,setFloat: function(value) {
		this.invalidate();
		return this._float = value;
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
	,getFloat: function() {
		return this._float;
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
	,__class__: cocktailCore.style.abstract.AbstractStyle
	,__properties__: {get_fontMetrics:"getFontMetricsData",get_domElement:"getDOMElement",set_computedStyle:"setComputedStyle",get_computedStyle:"getComputedStyle",set_textIndent:"setTextIndent",get_textIndent:"getTextIndent",set_textAlign:"setTextAlign",get_textAlign:"getTextAlign",set_whiteSpace:"setWhiteSpace",get_whiteSpace:"getWhiteSpace",set_wordSpacing:"setWordSpacing",get_wordSpacing:"getWordSpacing",set_letterSpacing:"setLetterSpacing",get_letterSpacing:"getLetterSpacing",set_textTransform:"setTextTransform",get_textTransform:"getTextTransform",set_lineHeight:"setLineHeight",get_lineHeight:"getLineHeight",set_color:"setColor",get_color:"getColor",set_fontVariant:"setFontVariant",get_fontVariant:"getFontVariant",set_fontFamily:"setFontFamily",get_fontFamily:"getFontFamily",set_fontStyle:"setFontStyle",get_fontStyle:"getFontStyle",set_fontWeight:"setFontWeight",get_fontWeight:"getFontWeight",set_fontSize:"setFontSize",get_fontSize:"getFontSize",set_clear:"setClear",get_clear:"getClear",set_float:"setFloat",get_float:"getFloat",set_verticalAlign:"setVerticalAlign",get_verticalAlign:"getVerticalAlign",set_right:"setRight",get_right:"getRight",set_bottom:"setBottom",get_bottom:"getBottom",set_left:"setLeft",get_left:"getLeft",set_top:"setTop",get_top:"getTop",set_maxWidth:"setMaxWidth",get_maxWidth:"getMaxWidth",set_minWidth:"setMinWidth",get_minWidth:"getMinWidth",set_maxHeight:"setMaxHeight",get_maxHeight:"getMaxHeight",set_minHeight:"setMinHeight",get_minHeight:"getMinHeight",set_height:"setHeight",get_height:"getHeight",set_width:"setWidth",get_width:"getWidth",set_position:"setPosition",get_position:"getPosition",set_display:"setDisplay",get_display:"getDisplay",set_paddingBottom:"setPaddingBottom",get_paddingBottom:"getPaddingBottom",set_paddingTop:"setPaddingTop",get_paddingTop:"getPaddingTop",set_paddingRight:"setPaddingRight",get_paddingRight:"getPaddingRight",set_paddingLeft:"setPaddingLeft",get_paddingLeft:"getPaddingLeft",set_marginBottom:"setMarginBottom",get_marginBottom:"getMarginBottom",set_marginTop:"setMarginTop",get_marginTop:"getMarginTop",set_marginRight:"setMarginRight",get_marginRight:"getMarginRight",set_marginLeft:"setMarginLeft",get_marginLeft:"getMarginLeft"}
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
		this.setNativeHeight(this._domElement,this._domElement.getNativeElement().clientHeight);
		this.setNativeWidth(this._domElement,this._domElement.getNativeElement().clientWidth);
		this.setNativeX(this._domElement,this._domElement.getNativeElement().offsetLeft);
		this.setNativeY(this._domElement,this._domElement.getNativeElement().offsetTop);
		this._isInvalid = false;
	}
	,flowChildren: function(containingDOMElementData,viewportData,lastPositionedDOMElementData,containingDOMElementFontMetricsData,formatingContext) {
	}
	,getCSSDisplay: function(value) {
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
	,getCSSFloat: function(value) {
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
	,getCSSClear: function(value) {
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
	,getCSSPosition: function(value) {
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
	,getCSSMargin: function(value) {
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
	,getCSSPadding: function(value) {
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
	,getCSSDimension: function(value) {
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
	,getCSSPositionOffset: function(value) {
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
	,getCSSConstrainedDimension: function(value) {
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
	,getCSSVerticalAlign: function(value) {
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
	,getCSSLineHeight: function(value) {
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
	,getCSSFontSize: function(value) {
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
	,getCSSFontWeight: function(value) {
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
	,getCSSFontStyle: function(value) {
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
	,getCSSFontVariant: function(value) {
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
	,getCSSFontFamily: function(value) {
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
	,getCSSTextAlign: function(value) {
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
	,getCSSWhiteSpace: function(value) {
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
	,getCSSTextTransform: function(value) {
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
	,getCSSTextIndent: function(value) {
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
	,getCSSLetterSpacing: function(value) {
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
	,getCSSWordSpacing: function(value) {
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
	,getCSSColor: function(value) {
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
	,getCSSLengthValue: function(lengthValue) {
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
	,getCSSPercentValue: function(value) {
		return value + "%";
	}
	,getColorFromKeyword: function(value) {
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
	,setFloat: function(value) {
		this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
		cocktailCore.style.abstract.AbstractStyle.prototype.setFloat.call(this,value);
		return this._float = value;
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
	,__class__: cocktailCore.style.js.Style
});
cocktailCore.style.abstract.AbstractContainerStyle = $hxClasses["cocktailCore.style.abstract.AbstractContainerStyle"] = function(domElement) {
	cocktailCore.style.js.Style.call(this,domElement);
}
cocktailCore.style.abstract.AbstractContainerStyle.__name__ = ["cocktailCore","style","abstract","AbstractContainerStyle"];
cocktailCore.style.abstract.AbstractContainerStyle.__super__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractContainerStyle.prototype = $extend(cocktailCore.style.js.Style.prototype,{
	layout: function(containingDOMElementData,lastPositionedDOMElementData,viewportData,containingDOMElementFontMetricsData) {
		this.flow(containingDOMElementData,viewportData,lastPositionedDOMElementData,null);
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
		this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
		if(childrenFormattingContext != formatingContext) childrenFormattingContext.destroy();
		if(this._width == cocktail.style.DimensionStyleValue.auto) {
			var currentWidth = this._computedStyle.width;
			this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData.width,childrenFormattingContext.getFlowData().maxWidth);
			if(currentWidth != this._computedStyle.width) {
				childrenFormattingContext = this.getFormatingContext(formatingContext);
				childrenContainingDOMElementData = this.getContainerDOMElementData();
				childLastPositionedDOMElementData = this.getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
				this.doFlowChildren(childrenContainingDOMElementData,viewportData,childLastPositionedDOMElementData,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
			}
		}
		if(this._height == cocktail.style.DimensionStyleValue.auto) this._computedStyle.height = childrenFormattingContext.getFlowData().totalHeight;
		this.insertDOMElement(formatingContext,lastPositionedDOMElementData,viewportData);
		formatingContext.retrieveFloats(childrenFormattingContext);
		var isFirstPositionedAncestor = childLastPositionedDOMElementData != lastPositionedDOMElementData;
		this.doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData);
	}
	,insertInFlowDOMElement: function(formattingContext) {
		if(this.isInline() == false || this.isInlineFlow() == false) cocktailCore.style.js.Style.prototype.insertInFlowDOMElement.call(this,formattingContext);
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
	}
	,doPositionAbsolutelyPositionedDOMElements: function(isFirstPositionedAncestor,childLastPositionedDOMElementData,viewportData) {
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
	,insertTextElement: function(textElement,formattingContext,containingDOMElementData) {
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
	,shrinkToFitIfNeeded: function(availableWidth,minimumWidth) {
		var boxComputer = this.getBoxStylesComputer();
		return boxComputer.shrinkToFit(this._computedStyle,availableWidth,minimumWidth);
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
	,applyWhiteSpace: function(text,whiteSpace) {
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
	,applyTextTransform: function(text) {
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
	,capitalizeText: function(text) {
		var capitalizedText = text.charAt(0);
		var _g1 = 1, _g = text.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(text.charAt(i - 1) == " ") capitalizedText += text.charAt(i).toUpperCase(); else capitalizedText += text.charAt(i);
		}
		return capitalizedText;
	}
	,collapseSpaceSequences: function(text) {
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
	,removeLineFeeds: function(text) {
		return StringTools.replace(text,"\n","");
	}
	,convertTabToSpace: function(text) {
		return StringTools.replace(text,"\t"," ");
	}
	,getContainerDOMElementData: function() {
		var height;
		if(this.isInline() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.isInline() == false && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
		return { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.auto, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.auto, globalX : this._domElement.getGlobalX(), globalY : this._domElement.getGlobalY()};
	}
	,getFormatingContext: function(previousFormatingContext) {
		var containerDOMElement = this._domElement;
		var formattingContext;
		if(this.startsNewFormattingContext() == true) {
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
	,startsNewFormattingContext: function() {
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
	,isInlineFlow: function() {
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
if(!cocktailCore.textElement) cocktailCore.textElement = {}
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = $hxClasses["cocktailCore.textElement.abstract.AbstractTextElement"] = function(text) {
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
		var resetAngle = 360 - currentRotation;
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
		var rotationInDeg = Math.round(rotationInRad * 180 / Math.PI);
		if(rotationInDeg < 0) rotationInDeg = 360 + rotationInDeg;
		return rotationInDeg;
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
if(!cocktailCore.style.formatter) cocktailCore.style.formatter = {}
cocktailCore.style.formatter.FormattingContext = $hxClasses["cocktailCore.style.formatter.FormattingContext"] = function(domElement,previousFormatingContext) {
	this._containingDOMElement = domElement;
	this._containingDOMElementWidth = this._containingDOMElement.getStyle().getComputedStyle().width;
	this._floatsManager = new cocktailCore.style.floats.FloatsManager();
	if(previousFormatingContext != null) this._floatsManager.addFloats(previousFormatingContext);
	this._flowData = this.initFlowData(this._containingDOMElement);
}
cocktailCore.style.formatter.FormattingContext.__name__ = ["cocktailCore","style","formatter","FormattingContext"];
cocktailCore.style.formatter.FormattingContext.prototype = {
	_containingDOMElement: null
	,containingDOMElement: null
	,_containingDOMElementWidth: null
	,_floatsManager: null
	,floatsManager: null
	,_flowData: null
	,flowData: null
	,initFlowData: function(domElement) {
		var flowY = domElement.getStyle().getComputedStyle().paddingTop;
		var flowX;
		if(domElement.getStyle().getComputedStyle().paddingLeft > this._floatsManager.getLeftFloatOffset(flowY)) flowX = domElement.getStyle().getComputedStyle().paddingLeft; else flowX = this._floatsManager.getLeftFloatOffset(flowY);
		return { x : flowX, y : flowY, xOffset : domElement.getStyle().getComputedStyle().paddingLeft, yOffset : domElement.getStyle().getComputedStyle().paddingTop, totalHeight : 0, maxWidth : 0};
	}
	,insert: function(domElement) {
		this.doInsert(domElement);
	}
	,insertSpace: function(domElement) {
		this.doInsert(domElement);
	}
	,insertTab: function(domElement) {
		this.doInsert(domElement);
	}
	,insertLineFeed: function() {
		this.startNewLine(0);
	}
	,insertFloat: function(domElement) {
		var floatData = this._floatsManager.computeFloatData(domElement,this._flowData,this._containingDOMElementWidth);
		this.placeFloat(domElement,floatData);
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
	,doInsert: function(domElement) {
		this.place(domElement);
		this.removeFloats();
	}
	,getRemainingLineWidth: function() {
		return this._containingDOMElementWidth - this._flowData.x + this._flowData.xOffset - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
	}
	,place: function(domElement) {
	}
	,placeFloat: function(domElement,floatData) {
		domElement.getStyle().setNativeX(domElement,floatData.x + domElement.getStyle().getComputedStyle().marginLeft);
		domElement.getStyle().setNativeY(domElement,floatData.y + domElement.getStyle().getComputedStyle().marginTop);
	}
	,removeFloats: function() {
		this._floatsManager.removeFloats(this._flowData.y);
	}
	,getFloatsManager: function() {
		return this._floatsManager;
	}
	,getFlowData: function() {
		return this._flowData;
	}
	,getContainingDOMElement: function() {
		return this._containingDOMElement;
	}
	,__class__: cocktailCore.style.formatter.FormattingContext
	,__properties__: {get_flowData:"getFlowData",get_floatsManager:"getFloatsManager",get_containingDOMElement:"getContainingDOMElement"}
}
if(!cocktail.domElement) cocktail.domElement = {}
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
if(!cocktail.viewport) cocktail.viewport = {}
cocktail.viewport.OrientationValue = $hxClasses["cocktail.viewport.OrientationValue"] = { __ename__ : ["cocktail","viewport","OrientationValue"], __constructs__ : ["vertical","horizontal"] }
cocktail.viewport.OrientationValue.vertical = ["vertical",0];
cocktail.viewport.OrientationValue.vertical.toString = $estr;
cocktail.viewport.OrientationValue.vertical.__enum__ = cocktail.viewport.OrientationValue;
cocktail.viewport.OrientationValue.horizontal = ["horizontal",1];
cocktail.viewport.OrientationValue.horizontal.toString = $estr;
cocktail.viewport.OrientationValue.horizontal.__enum__ = cocktail.viewport.OrientationValue;
cocktailCore.style.positioner.FixedPositioner = $hxClasses["cocktailCore.style.positioner.FixedPositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.FixedPositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	applyGlobalX: function(domElement,globalX) {
		domElement.setGlobalX(0);
	}
	,applyGlobalY: function(domElement,globalY) {
		domElement.setGlobalY(0);
	}
	,__class__: cocktailCore.style.positioner.FixedPositioner
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
	,_smooth: null
	,smooth: null
	,init: function() {
		cocktailCore.domElement.js.EmbeddedDOMElement.prototype.init.call(this);
		this.setSmooth(true);
	}
	,load: function(url,allowCache) {
		if(allowCache == null) allowCache = true;
		this._imageLoader.load(url,this.onLoadComplete.$bind(this),this.onLoadError.$bind(this),allowCache);
	}
	,onLoadComplete: function(image) {
		this._style.invalidate();
		this.setSmooth(this.getSmooth());
		if(this.onLoad != null) this.onLoad(this);
	}
	,onLoadError: function(message) {
		if(this.onError != null) this.onError(message);
	}
	,getSrc: function() {
		return this._src;
	}
	,setSmooth: function(value) {
		this._smooth = value;
		return value;
	}
	,getSmooth: function() {
		return this._smooth;
	}
	,__class__: cocktailCore.domElement.abstract.AbstractImageDOMElement
	,__properties__: $extend(cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__properties__,{set_smooth:"setSmooth",get_smooth:"getSmooth",get_src:"getSrc"})
});
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
	,setSmooth: function(value) {
		cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSmooth.call(this,value);
		if(value == true) this._nativeElement.style.imageRendering = "optimizeQuality"; else this._nativeElement.style.imageRendering = "optimizeSpeed";
		return value;
	}
	,__class__: cocktailCore.domElement.js.ImageDOMElement
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
cocktailCore.domElement.js.TextFragmentDOMElement = $hxClasses["cocktailCore.domElement.js.TextFragmentDOMElement"] = function(nativeElement,style) {
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
cocktailCore.domElement.js.TextFragmentDOMElement.prototype = $extend(cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype,{
	__class__: cocktailCore.domElement.js.TextFragmentDOMElement
});
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = $hxClasses["cocktailCore.resource.abstract.AbstractResourceLoader"] = function() {
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype = {
	_onLoadCompleteCallback: null
	,_onLoadErrorCallback: null
	,load: function(url,onLoadComplete,onLoadError,allowCache) {
		if(allowCache == null) allowCache = true;
		this._onLoadCompleteCallback = onLoadComplete;
		this._onLoadErrorCallback = onLoadError;
		if(allowCache == false) url = this.disableUrlCaching(url);
		this.doLoad(url);
	}
	,doLoad: function(url) {
		var fileRequest = new haxe.Http(url);
		fileRequest.onData = this.onLoadComplete.$bind(this);
		fileRequest.onError = this.onLoadError.$bind(this);
		fileRequest.request(false);
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
	,__class__: cocktailCore.resource.abstract.AbstractResourceLoader
}
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ContainerLoader = $hxClasses["cocktailCore.resource.js.ContainerLoader"] = function() {
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.ContainerLoader.__name__ = ["cocktailCore","resource","js","ContainerLoader"];
cocktailCore.resource.js.ContainerLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.ContainerLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	onLoadComplete: function(data) {
		var domElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
		domElement.getNativeElement().innerHTML = data;
		this._onLoadCompleteCallback(domElement);
	}
	,__class__: cocktailCore.resource.js.ContainerLoader
});
if(!cocktail.mouse) cocktail.mouse = {}
cocktail.mouse.MouseCursorValue = $hxClasses["cocktail.mouse.MouseCursorValue"] = { __ename__ : ["cocktail","mouse","MouseCursorValue"], __constructs__ : ["custom","auto","none","native"] }
cocktail.mouse.MouseCursorValue.custom = function(imageDOMElement,hotSpot) { var $x = ["custom",0,imageDOMElement,hotSpot]; $x.__enum__ = cocktail.mouse.MouseCursorValue; $x.toString = $estr; return $x; }
cocktail.mouse.MouseCursorValue.auto = ["auto",1];
cocktail.mouse.MouseCursorValue.auto.toString = $estr;
cocktail.mouse.MouseCursorValue.auto.__enum__ = cocktail.mouse.MouseCursorValue;
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
cocktailCore.resource.js.StringLoader = $hxClasses["cocktailCore.resource.js.StringLoader"] = function() {
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.StringLoader.__name__ = ["cocktailCore","resource","js","StringLoader"];
cocktailCore.resource.js.StringLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.StringLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	__class__: cocktailCore.resource.js.StringLoader
});
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoWidth: function(style,containingDOMElementData) {
		var ret = 0;
		var embeddedDOMElement = style.getDOMElement();
		if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
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
	,getComputedAutoHeight: function(style,containingDOMElementData) {
		var embeddedDOMElement = style.getDOMElement();
		var ret = 0;
		if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) {
			if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
		} else {
			var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
			if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedWidth / embeddedDOMElement.getIntrinsicRatio()); else ret = 150;
		}
		return ret;
	}
	,getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		if(isHorizontalMargin == null) isHorizontalMargin = false;
		var computedMargin;
		if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
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
		if(isHorizontalMargin == null) isHorizontalMargin = false;
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
cocktail.geom.RegistrationPointValue = $hxClasses["cocktail.geom.RegistrationPointValue"] = { __ename__ : ["cocktail","geom","RegistrationPointValue"], __constructs__ : ["constant","point"] }
cocktail.geom.RegistrationPointValue.constant = function(registrationPointX,registrationPointY) { var $x = ["constant",0,registrationPointX,registrationPointY]; $x.__enum__ = cocktail.geom.RegistrationPointValue; $x.toString = $estr; return $x; }
cocktail.geom.RegistrationPointValue.point = function(point) { var $x = ["point",1,point]; $x.__enum__ = cocktail.geom.RegistrationPointValue; $x.toString = $estr; return $x; }
cocktail.geom.RegistrationPointXValue = $hxClasses["cocktail.geom.RegistrationPointXValue"] = { __ename__ : ["cocktail","geom","RegistrationPointXValue"], __constructs__ : ["left","center","right"] }
cocktail.geom.RegistrationPointXValue.left = ["left",0];
cocktail.geom.RegistrationPointXValue.left.toString = $estr;
cocktail.geom.RegistrationPointXValue.left.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointXValue.center = ["center",1];
cocktail.geom.RegistrationPointXValue.center.toString = $estr;
cocktail.geom.RegistrationPointXValue.center.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointXValue.right = ["right",2];
cocktail.geom.RegistrationPointXValue.right.toString = $estr;
cocktail.geom.RegistrationPointXValue.right.__enum__ = cocktail.geom.RegistrationPointXValue;
cocktail.geom.RegistrationPointYValue = $hxClasses["cocktail.geom.RegistrationPointYValue"] = { __ename__ : ["cocktail","geom","RegistrationPointYValue"], __constructs__ : ["top","middle","bottom"] }
cocktail.geom.RegistrationPointYValue.top = ["top",0];
cocktail.geom.RegistrationPointYValue.top.toString = $estr;
cocktail.geom.RegistrationPointYValue.top.__enum__ = cocktail.geom.RegistrationPointYValue;
cocktail.geom.RegistrationPointYValue.middle = ["middle",1];
cocktail.geom.RegistrationPointYValue.middle.toString = $estr;
cocktail.geom.RegistrationPointYValue.middle.__enum__ = cocktail.geom.RegistrationPointYValue;
cocktail.geom.RegistrationPointYValue.bottom = ["bottom",2];
cocktail.geom.RegistrationPointYValue.bottom.toString = $estr;
cocktail.geom.RegistrationPointYValue.bottom.__enum__ = cocktail.geom.RegistrationPointYValue;
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
if(!cocktailCore.nativeElement) cocktailCore.nativeElement = {}
if(!cocktailCore.nativeElement["abstract"]) cocktailCore.nativeElement["abstract"] = {}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementCreator"] = function() {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementCreator"];
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype = {
	createNativeElement: function(nativeElementType) {
		return null;
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementCreator
}
if(!cocktailCore.nativeElement.js) cocktailCore.nativeElement.js = {}
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
		case 4:
			var name = $e[2];
			nativeElement = js.Lib.document.createElement(name);
			break;
		}
		return nativeElement;
	}
	,__class__: cocktailCore.nativeElement.js.NativeElementCreator
});
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer
});
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		if(isHorizontalMargin == null) isHorizontalMargin = false;
		return 0;
	}
	,getComputedAutoWidth: function(style,containingDOMElementData) {
		return 0;
	}
	,shrinkToFit: function(computedStyles,availableWidth,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
		return shrinkedWidth;
	}
	,__class__: cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer
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
cocktailCore.resource.js.ResourceLoader = $hxClasses["cocktailCore.resource.js.ResourceLoader"] = function() {
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.ResourceLoader.__name__ = ["cocktailCore","resource","js","ResourceLoader"];
cocktailCore.resource.js.ResourceLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.ResourceLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	__class__: cocktailCore.resource.js.ResourceLoader
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
			this._floats.left.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().left[i],parentFormattingContext.getFlowData()));
		}
		var _g1 = 0, _g = parentFormattingContext.getFloatsManager().getFloats().right.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._floats.right.push(this.globalTolocal(parentFormattingContext.getFloatsManager().getFloats().right[i],parentFormattingContext.getFlowData()));
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
	,globalTolocal: function(floatData,flowData) {
		var floatY = floatData.y - flowData.y;
		var convertedFloatData = { x : floatData.x, y : floatY, width : floatData.width, height : floatData.height};
		return convertedFloatData;
	}
	,clearFloat: function(clear,flowData) {
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
	,clearLeft: function(flowData) {
		return this.doClearFloat(flowData,this._floats.left);
	}
	,clearRight: function(flowData) {
		return this.doClearFloat(flowData,this._floats.right);
	}
	,clearBoth: function(flowData) {
		var leftY = this.doClearFloat(flowData,this._floats.left);
		var rightY = this.doClearFloat(flowData,this._floats.right);
		if(leftY > rightY) return leftY; else return rightY;
	}
	,doClearFloat: function(flowData,floats) {
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
	,computeFloatData: function(domElement,flowData,containingBlockWidth) {
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
	,getLeftFloatData: function(domElement,flowData,containingBlockWidth) {
		var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
		floatData.x = flowData.xOffset + this.getLeftFloatOffset(floatData.y);
		return floatData;
	}
	,getRightFloatData: function(domElement,flowData,containingBlockWidth) {
		var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
		floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth) + flowData.xOffset;
		return floatData;
	}
	,getFloatData: function(domElement,flowData,containingBlockWidth) {
		var floatWidth = domElement.getOffsetWidth();
		var floatHeight = domElement.getOffsetHeight();
		var floatY = this.getFirstAvailableY(flowData,floatWidth,containingBlockWidth);
		var floatX = 0;
		return { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
	}
	,getFirstAvailableY: function(flowData,elementWidth,containingBlockWidth) {
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
if(!cocktail.nativeElement) cocktail.nativeElement = {}
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
cocktailCore.resource.abstract.AbstractImageLoader = $hxClasses["cocktailCore.resource.abstract.AbstractImageLoader"] = function(nativeElement) {
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image);
	this._nativeElement = nativeElement;
	cocktailCore.resource.js.ResourceLoader.call(this);
}
cocktailCore.resource.abstract.AbstractImageLoader.__name__ = ["cocktailCore","resource","abstract","AbstractImageLoader"];
cocktailCore.resource.abstract.AbstractImageLoader.__super__ = cocktailCore.resource.js.ResourceLoader;
cocktailCore.resource.abstract.AbstractImageLoader.prototype = $extend(cocktailCore.resource.js.ResourceLoader.prototype,{
	_nativeElement: null
	,nativeElement: null
	,getNativeElement: function() {
		return this._nativeElement;
	}
	,__class__: cocktailCore.resource.abstract.AbstractImageLoader
	,__properties__: {get_nativeElement:"getNativeElement"}
});
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
cocktail.style.MarginStyleValue = $hxClasses["cocktail.style.MarginStyleValue"] = { __ename__ : ["cocktail","style","MarginStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.MarginStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.MarginStyleValue; $x.toString = $estr; return $x; }
cocktail.style.MarginStyleValue.auto = ["auto",2];
cocktail.style.MarginStyleValue.auto.toString = $estr;
cocktail.style.MarginStyleValue.auto.__enum__ = cocktail.style.MarginStyleValue;
cocktail.style.PaddingStyleValue = $hxClasses["cocktail.style.PaddingStyleValue"] = { __ename__ : ["cocktail","style","PaddingStyleValue"], __constructs__ : ["length","percent"] }
cocktail.style.PaddingStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PaddingStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PaddingStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue = $hxClasses["cocktail.style.DimensionStyleValue"] = { __ename__ : ["cocktail","style","DimensionStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.DimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.DimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.DimensionStyleValue.auto = ["auto",2];
cocktail.style.DimensionStyleValue.auto.toString = $estr;
cocktail.style.DimensionStyleValue.auto.__enum__ = cocktail.style.DimensionStyleValue;
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
cocktail.style.PositionOffsetStyleValue = $hxClasses["cocktail.style.PositionOffsetStyleValue"] = { __ename__ : ["cocktail","style","PositionOffsetStyleValue"], __constructs__ : ["length","percent","auto"] }
cocktail.style.PositionOffsetStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.PositionOffsetStyleValue; $x.toString = $estr; return $x; }
cocktail.style.PositionOffsetStyleValue.auto = ["auto",2];
cocktail.style.PositionOffsetStyleValue.auto.toString = $estr;
cocktail.style.PositionOffsetStyleValue.auto.__enum__ = cocktail.style.PositionOffsetStyleValue;
cocktail.style.ConstrainedDimensionStyleValue = $hxClasses["cocktail.style.ConstrainedDimensionStyleValue"] = { __ename__ : ["cocktail","style","ConstrainedDimensionStyleValue"], __constructs__ : ["length","percent","none"] }
cocktail.style.ConstrainedDimensionStyleValue.length = function(value) { var $x = ["length",0,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.percent = function(value) { var $x = ["percent",1,value]; $x.__enum__ = cocktail.style.ConstrainedDimensionStyleValue; $x.toString = $estr; return $x; }
cocktail.style.ConstrainedDimensionStyleValue.none = ["none",2];
cocktail.style.ConstrainedDimensionStyleValue.none.toString = $estr;
cocktail.style.ConstrainedDimensionStyleValue.none.__enum__ = cocktail.style.ConstrainedDimensionStyleValue;
cocktailCore.style.InlineBoxValue = $hxClasses["cocktailCore.style.InlineBoxValue"] = { __ename__ : ["cocktailCore","style","InlineBoxValue"], __constructs__ : ["domElement","space","tab"] }
cocktailCore.style.InlineBoxValue.domElement = ["domElement",0];
cocktailCore.style.InlineBoxValue.domElement.toString = $estr;
cocktailCore.style.InlineBoxValue.domElement.__enum__ = cocktailCore.style.InlineBoxValue;
cocktailCore.style.InlineBoxValue.space = ["space",1];
cocktailCore.style.InlineBoxValue.space.toString = $estr;
cocktailCore.style.InlineBoxValue.space.__enum__ = cocktailCore.style.InlineBoxValue;
cocktailCore.style.InlineBoxValue.tab = ["tab",2];
cocktailCore.style.InlineBoxValue.tab.toString = $estr;
cocktailCore.style.InlineBoxValue.tab.__enum__ = cocktailCore.style.InlineBoxValue;
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	getComputedAutoMargin: function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
		if(isHorizontalMargin == null) isHorizontalMargin = false;
		return 0;
	}
	,getNativeWidth: function(style,containingDOMElementData) {
		return 0;
	}
	,getComputedHeight: function(style,containingDOMElementData) {
		return 0;
	}
	,__class__: cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer
});
cocktailCore.resource.js.ImageLoader = $hxClasses["cocktailCore.resource.js.ImageLoader"] = function(nativeElement) {
	cocktailCore.resource.abstract.AbstractImageLoader.call(this,nativeElement);
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractImageLoader;
cocktailCore.resource.js.ImageLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractImageLoader.prototype,{
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
	,__class__: cocktailCore.resource.js.ImageLoader
});
cocktailCore.style.computer.DisplayStylesComputer = $hxClasses["cocktailCore.style.computer.DisplayStylesComputer"] = function() {
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
cocktailCore.style.computer.DisplayStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.DisplayStylesComputer
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
if(!cocktail.resource) cocktail.resource = {}
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
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer
});
cocktailCore.style.computer.FontAndTextStylesComputer = $hxClasses["cocktailCore.style.computer.FontAndTextStylesComputer"] = function() {
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
cocktailCore.style.computer.FontAndTextStylesComputer.prototype = {
	__class__: cocktailCore.style.computer.FontAndTextStylesComputer
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
cocktail.nativeElement.NativeElementTypeValue = $hxClasses["cocktail.nativeElement.NativeElementTypeValue"] = { __ename__ : ["cocktail","nativeElement","NativeElementTypeValue"], __constructs__ : ["neutral","graphic","text","image","custom"] }
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
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","NoneBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer
});
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
cocktail.resource.LoadingTypeValue = $hxClasses["cocktail.resource.LoadingTypeValue"] = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",1];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
cocktailCore.style.positioner.RelativePositioner = $hxClasses["cocktailCore.style.positioner.RelativePositioner"] = function() {
	cocktailCore.style.positioner.BoxPositioner.call(this);
}
cocktailCore.style.positioner.RelativePositioner.__name__ = ["cocktailCore","style","positioner","RelativePositioner"];
cocktailCore.style.positioner.RelativePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.RelativePositioner.prototype = $extend(cocktailCore.style.positioner.BoxPositioner.prototype,{
	applyGlobalX: function(domElement,globalX) {
	}
	,applyGlobalY: function(domElement,globalY) {
	}
	,getLeftOffset: function(domElement) {
		return domElement.getStyle().getNativeX(domElement) + domElement.getStyle().getComputedStyle().left;
	}
	,getRightOffset: function(domElement,containingDOMElementWidth) {
		return domElement.getStyle().getNativeX(domElement) + containingDOMElementWidth - domElement.getStyle().getComputedStyle().width - domElement.getStyle().getComputedStyle().right;
	}
	,getTopOffset: function(domElement) {
		return domElement.getStyle().getNativeY(domElement) + domElement.getStyle().getComputedStyle().top;
	}
	,getBottomOffset: function(domElement,containingDOMElementHeight) {
		return domElement.getStyle().getNativeY(domElement) + containingDOMElementHeight - domElement.getStyle().getComputedStyle().height - domElement.getStyle().getComputedStyle().bottom;
	}
	,__class__: cocktailCore.style.positioner.RelativePositioner
});
cocktailCore.resource.js.LibraryLoader = $hxClasses["cocktailCore.resource.js.LibraryLoader"] = function() {
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
}
cocktailCore.resource.js.LibraryLoader.__name__ = ["cocktailCore","resource","js","LibraryLoader"];
cocktailCore.resource.js.LibraryLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
cocktailCore.resource.js.LibraryLoader.prototype = $extend(cocktailCore.resource.abstract.AbstractResourceLoader.prototype,{
	doLoad: function(url) {
		var scrptE = js.Lib.document.createElement("script");
		scrptE.setAttribute("type","text/javascript");
		scrptE.setAttribute("language","JavaScript");
		scrptE.setAttribute("src",url);
		scrptE.onload = this.onLoadComplete.$bind(this);
		scrptE.onerror = this.onLoadError.$bind(this);
		js.Lib.document.getElementsByTagName("head")[0].appendChild(scrptE);
	}
	,onLoadComplete: function(data) {
		this._onLoadCompleteCallback(null);
	}
	,__class__: cocktailCore.resource.js.LibraryLoader
});
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager = $hxClasses["cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager"] = function() {
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementPathManager"];
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype = {
	getRoot: function() {
		return null;
	}
	,__class__: cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager
}
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
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	__class__: cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer
});
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
	}
	,__class__: cocktailCore.style.js.ContainerStyle
});
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = $hxClasses["cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer"] = function() {
	cocktailCore.style.computer.BoxStylesComputer.call(this);
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype = $extend(cocktailCore.style.computer.BoxStylesComputer.prototype,{
	measurePositionOffsets: function(style,containingDOMElementData) {
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
	,shrinkToFit: function(computedStyles,availableWidth,minimumWidth) {
		var shrinkedWidth;
		if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
		return shrinkedWidth;
	}
	,__class__: cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer
});
cocktailCore.style.formatter.BlockFormattingContext = $hxClasses["cocktailCore.style.formatter.BlockFormattingContext"] = function(domElement,previousFormattingContext) {
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
}
cocktailCore.style.formatter.BlockFormattingContext.__name__ = ["cocktailCore","style","formatter","BlockFormattingContext"];
cocktailCore.style.formatter.BlockFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.formatter.BlockFormattingContext.prototype = $extend(cocktailCore.style.formatter.FormattingContext.prototype,{
	place: function(domElement) {
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
	,clearFloat: function(clear,isFloat) {
		this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
	}
	,__class__: cocktailCore.style.formatter.BlockFormattingContext
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
	,insert: function(domElement) {
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
	,insertSpace: function(domElement) {
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
	,place: function(domElement) {
		cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement);
		this._flowData.x += domElement.getOffsetWidth();
	}
	,startNewLine: function(domElementWidth,isLastLine) {
		if(isLastLine == null) isLastLine = false;
		if(this._domElementInLineBox.length > 0) {
			this.removeSpaces();
			var lineBoxHeight = this.computeLineBoxHeight();
			var lineWidth = this.alignText(this._firstLineLaidOut == false,isLastLine);
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
	,clearFloat: function(clear,isFloat) {
		if(isFloat == true) this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
	}
	,placeFloat: function(domElement,floatData) {
		cocktailCore.style.formatter.FormattingContext.prototype.placeFloat.call(this,domElement,floatData);
		if(this._floatsManager.getLeftFloatOffset(this._flowData.y) > this._flowData.xOffset) this.getFlowData().x = this._floatsManager.getLeftFloatOffset(this._flowData.y); else this._flowData.x = this._flowData.xOffset;
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
	,alignText: function(firstLine,isLastLine) {
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
				concatenatedLength = this._containingDOMElementWidth;
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
		return concatenatedLength;
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
	,__class__: cocktailCore.style.formatter.InlineFormattingContext
});
js.Boot.__res = {}
js.Boot.__init();
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
	js.Lib.document = document;
	js.Lib.window = window;
	onerror = function(msg,url,line) {
		var f = js.Lib.onerror;
		if( f == null )
			return false;
		return f(msg,[url+":"+line]);
	}
}
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_QUALITY = "optimizeQuality";
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_SPEED = "optimizeSpeed";
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
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_NONE = "butt";
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_ROUND = "round";
cocktailCore.domElement.js.GraphicDOMElement.CAPS_STYLE_VALUE_SQUARE = "square";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_ROUND = "round";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_MITER = "miter";
cocktailCore.domElement.js.GraphicDOMElement.JOINT_STYLE_VALUE_BEVEL = "bevel";
cocktailCore.domElement.js.GraphicDOMElement.CANVAS_PATTERN_REPEAT = "repeat";
cocktailCore.domElement.js.GraphicDOMElement.CANVAS_PATTERN_NO_REPEAT = "no-repeat";
cocktail.resource.ResourceLoaderManager._isLoading = false;
js.Lib.onerror = null;
Gallery.main()