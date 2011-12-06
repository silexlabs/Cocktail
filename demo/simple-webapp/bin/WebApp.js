$estr = function() { return js.Boot.__string_rec(this,''); }
if(typeof cocktailCore=='undefined') cocktailCore = {}
if(!cocktailCore.style) cocktailCore.style = {}
if(!cocktailCore.style.computer) cocktailCore.style.computer = {}
cocktailCore.style.computer.BoxStylesComputer = function(p) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.__name__ = ["cocktailCore","style","computer","BoxStylesComputer"];
cocktailCore.style.computer.BoxStylesComputer.prototype.measure = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measure");
	var $spos = $s.length;
	this.measureHorizontalPaddings(style,containingDOMElementData);
	this.measureVerticalPaddings(style,containingDOMElementData);
	this.measureWidthAndHorizontalMargins(style,containingDOMElementData);
	this.measureHeightAndVerticalMargins(style,containingDOMElementData);
	this.measurePositionOffsets(style,containingDOMElementData);
	this.measureDimensionsConstraints(style,containingDOMElementData);
	this.constrainDimensions(style);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::shrinkToFit");
	var $spos = $s.length;
	var $tmp = computedStyles.width;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureDimensionsConstraints = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureDimensionsConstraints");
	var $spos = $s.length;
	style.getComputedStyle().maxHeight = this.getComputedConstrainedDimension(style.getMaxHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minHeight = this.getComputedConstrainedDimension(style.getMinHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	style.getComputedStyle().maxWidth = this.getComputedConstrainedDimension(style.getMaxWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().minWidth = this.getComputedConstrainedDimension(style.getMinWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight,true);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measurePositionOffsets");
	var $spos = $s.length;
	style.getComputedStyle().left = this.getComputedPositionOffset(style.getLeft(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().right = this.getComputedPositionOffset(style.getRight(),containingDOMElementData.width,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().top = this.getComputedPositionOffset(style.getTop(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().bottom = this.getComputedPositionOffset(style.getBottom(),containingDOMElementData.height,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureVerticalPaddings = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureVerticalPaddings");
	var $spos = $s.length;
	style.getComputedStyle().paddingTop = this.getComputedPadding(style.getPaddingTop(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingBottom = this.getComputedPadding(style.getPaddingBottom(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHorizontalPaddings = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHorizontalPaddings");
	var $spos = $s.length;
	style.getComputedStyle().paddingLeft = this.getComputedPadding(style.getPaddingLeft(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	style.getComputedStyle().paddingRight = this.getComputedPadding(style.getPaddingRight(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureWidthAndHorizontalMargins = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureWidthAndHorizontalMargins");
	var $spos = $s.length;
	if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) this.measureAutoWidth(style,containingDOMElementData); else this.measureWidth(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureAutoWidth");
	var $spos = $s.length;
	style.getComputedStyle().width = 0;
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	style.getComputedStyle().width = this.getComputedAutoWidth(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureWidth");
	var $spos = $s.length;
	style.getComputedStyle().width = this.getComputedWidth(style,containingDOMElementData);
	style.getComputedStyle().marginLeft = this.getComputedMarginLeft(style,containingDOMElementData);
	style.getComputedStyle().marginRight = this.getComputedMarginRight(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeightAndVerticalMargins = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHeightAndVerticalMargins");
	var $spos = $s.length;
	if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) this.measureAutoHeight(style,containingDOMElementData); else this.measureHeight(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureAutoHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureAutoHeight");
	var $spos = $s.length;
	style.getComputedStyle().height = this.getComputedAutoHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.measureHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::measureHeight");
	var $spos = $s.length;
	style.getComputedStyle().height = this.getComputedHeight(style,containingDOMElementData);
	style.getComputedStyle().marginTop = this.getComputedMarginTop(style,containingDOMElementData);
	style.getComputedStyle().marginBottom = this.getComputedMarginBottom(style,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.constrainDimensions = function(style) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::constrainDimensions");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedWidth");
	var $spos = $s.length;
	var $tmp = this.getComputedDimension(style.getWidth(),containingDOMElementData.width,containingDOMElementData.isWidthAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoWidth");
	var $spos = $s.length;
	var $tmp = containingDOMElementData.width - style.getComputedStyle().paddingLeft - style.getComputedStyle().paddingRight - style.getComputedStyle().marginLeft - style.getComputedStyle().marginRight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedHeight");
	var $spos = $s.length;
	var $tmp = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoHeight");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginLeft = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginLeft");
	var $spos = $s.length;
	var $tmp = this.getComputedMargin(style.getMarginLeft(),style.getMarginRight(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginRight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginRight");
	var $spos = $s.length;
	var $tmp = this.getComputedMargin(style.getMarginRight(),style.getMarginLeft(),containingDOMElementData.width,style.getComputedStyle().width,style.getWidth() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingRight + style.getComputedStyle().paddingLeft,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginTop = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginTop");
	var $spos = $s.length;
	var $tmp = this.getComputedMargin(style.getMarginTop(),style.getMarginBottom(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMarginBottom = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMarginBottom");
	var $spos = $s.length;
	var $tmp = this.getComputedMargin(style.getMarginBottom(),style.getMarginTop(),containingDOMElementData.height,style.getComputedStyle().height,style.getHeight() == cocktail.style.DimensionStyleValue.auto,style.getComputedStyle().paddingTop + style.getComputedStyle().paddingBottom,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedMargin");
	var $spos = $s.length;
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
	$s.pop();
	return computedMargin;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.BoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
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
	$s.pop();
	return computedMargin;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedConstrainedDimension = function(constrainedDimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight,isMinConstraint) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedPositionOffset = function(positionOffsetStyleValue,containingDOMElementDimension,fontSize,xHeight) {
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
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedDimension = function(dimensionStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
		if(isContainingDimensionAuto == true) computedDimensions = 0; else computedDimensions = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
		break;
	case 2:
		computedDimensions = 0;
		break;
	}
	$s.pop();
	return computedDimensions;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedPadding = function(paddingStyleValue,containingDOMElementDimension,isContainingDimensionAuto,fontSize,xHeight) {
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
		if(isContainingDimensionAuto == true) computedPaddingValue = 0; else computedPaddingValue = Math.round(cocktailCore.unit.UnitManager.getPixelFromPercent(value,containingDOMElementDimension));
		break;
	}
	$s.pop();
	return computedPaddingValue;
	$s.pop();
}
cocktailCore.style.computer.BoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.BoxStylesComputer;
if(!cocktailCore.style.computer.boxComputers) cocktailCore.style.computer.boxComputers = {}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	$s.push("cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer::shrinkToFit");
	var $spos = $s.length;
	var shrinkedWidth;
	if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
	$s.pop();
	return shrinkedWidth;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
if(!cocktailCore.mouse) cocktailCore.mouse = {}
if(!cocktailCore.mouse["abstract"]) cocktailCore.mouse["abstract"] = {}
cocktailCore.mouse.abstract.AbstractMouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::new");
	var $spos = $s.length;
	this.setNativeMouseListeners(nativeElement);
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.__name__ = ["cocktailCore","mouse","abstract","AbstractMouse"];
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDown = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseUp = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOver = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseOut = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseMove = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.onMouseDoubleClick = null;
cocktailCore.mouse.abstract.AbstractMouse.prototype.setNativeMouseListeners = function(nativeElement) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::setNativeMouseListeners");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.unsetNativeMouseListeners = function(nativeElement) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::unsetNativeMouseListeners");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDown = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseDown");
	var $spos = $s.length;
	if(this.onMouseDown != null) this.onMouseDown(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseUp = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseUp");
	var $spos = $s.length;
	if(this.onMouseUp != null) this.onMouseUp(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOver = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseOver");
	var $spos = $s.length;
	if(this.onMouseOver != null) this.onMouseOver(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseOut = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseOut");
	var $spos = $s.length;
	if(this.onMouseOut != null) this.onMouseOut(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseMove = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseMove");
	var $spos = $s.length;
	if(this.onMouseMove != null) this.onMouseMove(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.onNativeMouseDoubleClick = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::onNativeMouseDoubleClick");
	var $spos = $s.length;
	if(this.onMouseDoubleClick != null) this.onMouseDoubleClick(this.getMouseData(event));
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.getMouseData = function(event) {
	$s.push("cocktailCore.mouse.abstract.AbstractMouse::getMouseData");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.mouse.abstract.AbstractMouse.prototype.__class__ = cocktailCore.mouse.abstract.AbstractMouse;
if(!cocktailCore.mouse.js) cocktailCore.mouse.js = {}
cocktailCore.mouse.js.Mouse = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.mouse.js.Mouse::new");
	var $spos = $s.length;
	cocktailCore.mouse.abstract.AbstractMouse.call(this,nativeElement);
	$s.pop();
}
cocktailCore.mouse.js.Mouse.__name__ = ["cocktailCore","mouse","js","Mouse"];
cocktailCore.mouse.js.Mouse.__super__ = cocktailCore.mouse.abstract.AbstractMouse;
for(var k in cocktailCore.mouse.abstract.AbstractMouse.prototype ) cocktailCore.mouse.js.Mouse.prototype[k] = cocktailCore.mouse.abstract.AbstractMouse.prototype[k];
cocktailCore.mouse.js.Mouse.prototype.setNativeMouseListeners = function(nativeElement) {
	$s.push("cocktailCore.mouse.js.Mouse::setNativeMouseListeners");
	var $spos = $s.length;
	nativeElement.onmousedown = $closure(this,"onNativeMouseDown");
	nativeElement.onmouseup = $closure(this,"onNativeMouseUp");
	nativeElement.onmouseover = $closure(this,"onNativeMouseOver");
	nativeElement.onmouseout = $closure(this,"onNativeMouseOut");
	nativeElement.onmousemove = $closure(this,"onNativeMouseMove");
	nativeElement.ondblclick = $closure(this,"onNativeMouseDoubleClick");
	$s.pop();
}
cocktailCore.mouse.js.Mouse.prototype.unsetNativeMouseListeners = function(nativeElement) {
	$s.push("cocktailCore.mouse.js.Mouse::unsetNativeMouseListeners");
	var $spos = $s.length;
	nativeElement.onmousedown = null;
	nativeElement.onmouseup = null;
	nativeElement.onmouseover = null;
	nativeElement.onmouseout = null;
	nativeElement.onmousemove = null;
	nativeElement.ondblclick = null;
	$s.pop();
}
cocktailCore.mouse.js.Mouse.prototype.getMouseData = function(event) {
	$s.push("cocktailCore.mouse.js.Mouse::getMouseData");
	var $spos = $s.length;
	var mousePosition = { localX : event.clientX, localY : event.clientY, globalX : event.screenX, globalY : event.screenY};
	var mouseEventData = { mousePosition : mousePosition, altKey : event.altKey, ctrlKey : event.ctrlKey, shiftKey : event.shiftKey};
	$s.pop();
	return mouseEventData;
	$s.pop();
}
cocktailCore.mouse.js.Mouse.prototype.__class__ = cocktailCore.mouse.js.Mouse;
if(!cocktailCore.keyboard) cocktailCore.keyboard = {}
if(!cocktailCore.keyboard["abstract"]) cocktailCore.keyboard["abstract"] = {}
cocktailCore.keyboard.abstract.AbstractKeyboard = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::new");
	var $spos = $s.length;
	this.setNativeKeyboardListeners();
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.__name__ = ["cocktailCore","keyboard","abstract","AbstractKeyboard"];
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyDown = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onKeyUp = null;
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.setNativeKeyboardListeners = function() {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::setNativeKeyboardListeners");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.unsetNativeKeyboardListeners = function() {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::unsetNativeKeyboardListeners");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyDown = function(event) {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::onNativeKeyDown");
	var $spos = $s.length;
	if(this.onKeyDown != null) this.onKeyDown(this.getKeyData(event));
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.onNativeKeyUp = function(event) {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::onNativeKeyUp");
	var $spos = $s.length;
	if(this.onKeyUp != null) this.onKeyUp(this.getKeyData(event));
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getKeyData = function(event) {
	$s.push("cocktailCore.keyboard.abstract.AbstractKeyboard::getKeyData");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.getKeyValue = function(keyCode) {
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
cocktailCore.keyboard.abstract.AbstractKeyboard.prototype.__class__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
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
ApplicationStructure = function(p) {
	if( p === $_ ) return;
	$s.push("ApplicationStructure::new");
	var $spos = $s.length;
	this.pagesContainer = Utils.getContainer();
	this.createAllPages();
	$s.pop();
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
	$s.push("ApplicationStructure::createAllPages");
	var $spos = $s.length;
	this._dayPage = this.createHeaderContentPage("Day","This is what I have planned today");
	this._calListPage = this.createHeaderListPage("Calendar",[{ text : "June 1st", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 2nd", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 3rd", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 4th", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage},{ text : "June 5th", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._dayPage}]);
	this._songPage = this.createHeaderContentPage("Song","You are listening to this song");
	this._songListPage = this.createHeaderListPage("Artist - Album",[{ text : "Song 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage},{ text : "Song 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songPage}]);
	haxe.Timer.delay($closure(this,"dolatertest"),300);
	$s.pop();
}
ApplicationStructure.prototype.dolatertest = function() {
	$s.push("ApplicationStructure::dolatertest");
	var $spos = $s.length;
	this._albumListPage = this.createHeaderListPage("Albums",[{ text : "Album 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage},{ text : "Album 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._songListPage}]);
	this._artistListPage = this.createHeaderListPage("Artists",[{ text : "Artist 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage},{ text : "Artist 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._albumListPage}]);
	this._notePage = this.createHeaderContentPage("Note","This is the content of the note");
	this._noteListPage = this.createHeaderListPage("Notes",[{ text : "Note 1", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 2", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 3", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 4", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 5", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 6", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 7", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 8", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 9", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 10", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 11", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 12", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 13", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 14", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 15", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage},{ text : "Note 16", imagePath : "images/chevron.png", action : "goToPage", actionTarget : this._notePage}]);
	this._creditsPage = this.createHeaderContentPage("Credits","This is a Cocktail demo. Cocktail is a cross-platform library for the HaXe programming language. It bridges the gap between all the targets supported by haXe, removing inconsistencies behind a common API. With it, the same code base is used to deploy to these targets: Flash, javaScript, PHP. It helps multi device application development and should be used by haXe projects requiring cross-target compilation. Silex Labs Cocktail library is released under GPL. Project home: http://www.silexlabs.org/groups/labs/cocktail/");
	haxe.Timer.delay($closure(this,"dolatertest2"),300);
	$s.pop();
}
ApplicationStructure.prototype.dolatertest2 = function() {
	$s.push("ApplicationStructure::dolatertest2");
	var $spos = $s.length;
	this._homePage = this.createHomePage([{ text : "Cal", imagePath : "images/NavButtonCalendar.png", action : "goToPage", actionTarget : this._calListPage},{ text : "Music", imagePath : "images/NavButtonMusic.png", action : "goToPage", actionTarget : this._artistListPage},{ text : "Notes", imagePath : "images/NavButtonNotes.png", action : "goToPage", actionTarget : this._noteListPage},{ text : "Credits", imagePath : "images/NavButtonCredits.png", action : "goToPage", actionTarget : this._creditsPage}]);
	this._currentPage = this._homePage;
	this.pagesContainer.addChild(this._homePage);
	$s.pop();
}
ApplicationStructure.prototype.showPage = function(page) {
	$s.push("ApplicationStructure::showPage");
	var $spos = $s.length;
	this.pagesContainer.removeChild(this._currentPage);
	this.pagesContainer.addChild(page);
	this._currentPage = page;
	$s.pop();
}
ApplicationStructure.prototype.onChangeListCallback = function(itemData) {
	$s.push("ApplicationStructure::onChangeListCallback");
	var $spos = $s.length;
	if(itemData.action == "goToPage") this.showPage(itemData.actionTarget);
	$s.pop();
}
ApplicationStructure.prototype.createHomePage = function(cellDataArray) {
	$s.push("ApplicationStructure::createHomePage");
	var $spos = $s.length;
	var page = Utils.getContainer();
	var homeTilePath = "images/blackPixel.png";
	var backGround = new cocktailCore.domElement.js.ImageDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	WebAppStyle.getBgStyle(backGround);
	cocktail.resource.ResourceLoaderManager.loadImage(homeTilePath,$closure(this,"onHomeTileLoaded"),$closure(this,"onImageLoadError"),backGround);
	var richList = this.createRichListHome(cellDataArray);
	richList.onChange = $closure(this,"onChangeListCallback");
	page.addChild(backGround);
	page.addChild(richList);
	WebAppStyle.getHomePageStyle(page);
	$s.pop();
	return page;
	$s.pop();
}
ApplicationStructure.prototype.createHeaderListPage = function(title,cellDataArray) {
	$s.push("ApplicationStructure::createHeaderListPage");
	var $spos = $s.length;
	var page = Utils.getContainer();
	var header = this.createHeader(title);
	var richList = this.createArrowRichList(cellDataArray);
	richList.onChange = $closure(this,"onChangeListCallback");
	page.addChild(header);
	page.addChild(richList);
	WebAppStyle.getPageStyle(page);
	$s.pop();
	return page;
	$s.pop();
}
ApplicationStructure.prototype.createHeaderContentPage = function(title,content) {
	$s.push("ApplicationStructure::createHeaderContentPage");
	var $spos = $s.length;
	var page = Utils.getContainer();
	var header = this.createHeader(title);
	var textElement = new cocktailCore.textElement.js.TextElement(content);
	var textContainer = Utils.getContainer();
	textContainer.addText(textElement);
	WebAppStyle.getTextContentStyle(textContainer);
	page.addChild(header);
	page.addChild(textContainer);
	WebAppStyle.getPageStyle(page);
	$s.pop();
	return page;
	$s.pop();
}
ApplicationStructure.prototype.createHeader = function(title) {
	$s.push("ApplicationStructure::createHeader");
	var $spos = $s.length;
	var header = Utils.getContainer();
	var headerTile = new cocktailCore.domElement.js.ImageDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	var headerTilePath = "images/H1.png";
	cocktail.resource.ResourceLoaderManager.loadImage(headerTilePath,$closure(this,"onHeaderTileLoaded"),$closure(this,"onImageLoadError"),headerTile);
	var backButton = new cocktailCore.textElement.js.TextElement("Back");
	var backButtonContainer = Utils.getContainer();
	backButtonContainer.addText(backButton);
	backButtonContainer.setOnMouseUp($closure(this,"onBackButtonMouseUp"));
	WebAppStyle.getBackButtonStyle(backButtonContainer);
	var headerTitle = new cocktailCore.textElement.js.TextElement(title);
	var headerTitleContainer = Utils.getContainer();
	headerTitleContainer.addText(headerTitle);
	WebAppStyle.getHeaderTextStyle(headerTitleContainer);
	header.addChild(headerTile);
	header.addChild(headerTitleContainer);
	header.addChild(backButtonContainer);
	WebAppStyle.getHeaderStyle(header);
	$s.pop();
	return header;
	$s.pop();
}
ApplicationStructure.prototype.onHeaderTileLoaded = function(image) {
	$s.push("ApplicationStructure::onHeaderTileLoaded");
	var $spos = $s.length;
	image.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
ApplicationStructure.prototype.onHomeTileLoaded = function(image) {
	$s.push("ApplicationStructure::onHomeTileLoaded");
	var $spos = $s.length;
	WebAppStyle.getBgStyle(image);
	$s.pop();
}
ApplicationStructure.prototype.onImageLoadError = function(error) {
	$s.push("ApplicationStructure::onImageLoadError");
	var $spos = $s.length;
	haxe.Log.trace(error,{ fileName : "ApplicationStructure.hx", lineNumber : 345, className : "ApplicationStructure", methodName : "onImageLoadError"});
	$s.pop();
}
ApplicationStructure.prototype.createRichListHome = function(content) {
	$s.push("ApplicationStructure::createRichListHome");
	var $spos = $s.length;
	var listData = components.richList.RichListUtils.createRichListModel();
	listData.content = content;
	var listStyle = { list : components.richList.StyleApp.getDefaultStyle, cell : components.richList.StyleApp.getCellStyle, cellImage : components.richList.StyleApp.getCellImageStyle, cellMouseOver : components.richList.StyleApp.getCellMouseOverStyle, cellMouseOut : components.richList.StyleApp.getCellMouseOutStyle, cellMouseDown : components.richList.StyleApp.getCellMouseDownStyle, cellMouseUp : components.richList.StyleApp.getCellMouseUpStyle};
	var list = new components.richList.RichList(listData,listStyle);
	$s.pop();
	return list;
	$s.pop();
}
ApplicationStructure.prototype.createArrowRichList = function(content) {
	$s.push("ApplicationStructure::createArrowRichList");
	var $spos = $s.length;
	var listData = components.richList.RichListUtils.createRichListModel();
	listData.content = content;
	var listStyle = { list : components.richList.StyleNormal.getDefaultStyle, cell : components.richList.StyleNormal.getCellStyle, cellImage : components.richList.StyleNormal.getCellImageStyle, cellMouseOver : components.richList.StyleNormal.getCellMouseOverStyle, cellMouseOut : components.richList.StyleNormal.getCellMouseOutStyle, cellMouseDown : components.richList.StyleNormal.getCellMouseDownStyle, cellMouseUp : components.richList.StyleNormal.getCellMouseUpStyle};
	var list = new components.richList.RichList(listData,listStyle);
	$s.pop();
	return list;
	$s.pop();
}
ApplicationStructure.prototype.onBackButtonMouseUp = function(mouseEvent) {
	$s.push("ApplicationStructure::onBackButtonMouseUp");
	var $spos = $s.length;
	this.showPage(this._homePage);
	$s.pop();
}
ApplicationStructure.prototype.__class__ = ApplicationStructure;
if(typeof haxe=='undefined') haxe = {}
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
if(!cocktailCore.style.positioner) cocktailCore.style.positioner = {}
cocktailCore.style.positioner.BoxPositioner = function(p) {
	$s.push("cocktailCore.style.positioner.BoxPositioner::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.positioner.BoxPositioner.__name__ = ["cocktailCore","style","positioner","BoxPositioner"];
cocktailCore.style.positioner.BoxPositioner.prototype.position = function(domElement,containingDOMElementData) {
	$s.push("cocktailCore.style.positioner.BoxPositioner::position");
	var $spos = $s.length;
	domElement.setGlobalX(containingDOMElementData.globalX);
	domElement.setGlobalY(containingDOMElementData.globalY);
	this.applyOffset(domElement,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.positioner.BoxPositioner.prototype.applyOffset = function(domElement,containingDOMElementData) {
	$s.push("cocktailCore.style.positioner.BoxPositioner::applyOffset");
	var $spos = $s.length;
	if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.auto) {
		var _g = domElement;
		_g.setX(_g.getX() + domElement.getStyle().getComputedStyle().left);
	} else if(domElement.getStyle().getRight() != cocktail.style.PositionOffsetStyleValue.auto) {
		domElement.setX(containingDOMElementData.width - domElement.getStyle().getComputedStyle().width);
		var _g = domElement;
		_g.setX(_g.getX() - domElement.getStyle().getComputedStyle().right);
	}
	if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.auto) {
		var _g = domElement;
		_g.setY(_g.getY() + domElement.getStyle().getComputedStyle().top);
	} else if(domElement.getStyle().getBottom() != cocktail.style.PositionOffsetStyleValue.auto) {
		domElement.setY(containingDOMElementData.height - domElement.getStyle().getComputedStyle().height);
		var _g = domElement;
		_g.setY(_g.getY() - domElement.getStyle().getComputedStyle().bottom);
	}
	$s.pop();
}
cocktailCore.style.positioner.BoxPositioner.prototype.__class__ = cocktailCore.style.positioner.BoxPositioner;
cocktailCore.style.positioner.AbsolutePositioner = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.positioner.AbsolutePositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.AbsolutePositioner.__name__ = ["cocktailCore","style","positioner","AbsolutePositioner"];
cocktailCore.style.positioner.AbsolutePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.AbsolutePositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.AbsolutePositioner.prototype.__class__ = cocktailCore.style.positioner.AbsolutePositioner;
if(typeof components=='undefined') components = {}
if(!components.richList) components.richList = {}
components.richList.StyleApp = function() { }
components.richList.StyleApp.__name__ = ["components","richList","StyleApp"];
components.richList.StyleApp.getDefaultStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getDefaultStyle");
	var $spos = $s.length;
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	$s.pop();
}
components.richList.StyleApp.getCellStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellStyle");
	var $spos = $s.length;
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.white));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.auto);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.auto);
	domElement.getStyle().setMarginLeft(domElement.getStyle().setMarginRight(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(12))));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(12)));
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.inlineBlock);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("BDBDCE"));
	$s.pop();
}
components.richList.StyleApp.getCellImageStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellImageStyle");
	var $spos = $s.length;
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setWidth(domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(48))));
	domElement.getStyle().setMarginBottom(cocktail.style.MarginStyleValue.length(cocktail.unit.LengthValue.px(0)));
	$s.pop();
}
components.richList.StyleApp.getCellMouseOverStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellMouseOverStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("DDDDDD"));
	$s.pop();
}
components.richList.StyleApp.getCellMouseOutStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellMouseOutStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("BDBDCE"));
	$s.pop();
}
components.richList.StyleApp.getCellMouseDownStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellMouseDownStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.white));
	$s.pop();
}
components.richList.StyleApp.getCellMouseUpStyle = function(domElement) {
	$s.push("components.richList.StyleApp::getCellMouseUpStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("BDBDCE"));
	$s.pop();
}
components.richList.StyleApp.prototype.__class__ = components.richList.StyleApp;
Utils = function() { }
Utils.__name__ = ["Utils"];
Utils.getContainer = function() {
	$s.push("Utils::getContainer");
	var $spos = $s.length;
	var ret = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	ret.setX(0);
	ret.setY(0);
	$s.pop();
	return ret;
	$s.pop();
}
Utils.getGraphic = function() {
	$s.push("Utils::getGraphic");
	var $spos = $s.length;
	var ret = new cocktailCore.domElement.js.GraphicDOMElement();
	$s.pop();
	return ret;
	$s.pop();
}
Utils.fillGraphic = function(domElement,color) {
	$s.push("Utils::fillGraphic");
	var $spos = $s.length;
	domElement.clear();
	domElement.beginFill(cocktail.domElement.FillStyleValue.monochrome({ color : color, alpha : 100}),cocktail.domElement.LineStyleValue.none);
	domElement.drawRect(0,0,domElement.getWidth(),domElement.getHeight());
	domElement.endFill();
	domElement.setAlpha(1);
	$s.pop();
}
Utils.prototype.__class__ = Utils;
components.richList.RichListUtils = function() { }
components.richList.RichListUtils.__name__ = ["components","richList","RichListUtils"];
components.richList.RichListUtils.__super__ = Utils;
for(var k in Utils.prototype ) components.richList.RichListUtils.prototype[k] = Utils.prototype[k];
components.richList.RichListUtils.createRichListModel = function() {
	$s.push("components.richList.RichListUtils::createRichListModel");
	var $spos = $s.length;
	var richListModel = { content : new Array()};
	$s.pop();
	return richListModel;
	$s.pop();
}
components.richList.RichListUtils.prototype.__class__ = components.richList.RichListUtils;
if(!cocktailCore.domElement) cocktailCore.domElement = {}
if(!cocktailCore.domElement["abstract"]) cocktailCore.domElement["abstract"] = {}
cocktailCore.domElement.abstract.AbstractDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::new");
	var $spos = $s.length;
	if(nativeElement != null) this.setNativeElement(nativeElement);
	$s.pop();
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
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._x = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.x = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.globalX = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._y = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.y = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.globalY = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._width = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.width = null;
cocktailCore.domElement.abstract.AbstractDOMElement.prototype._height = null;
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
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::init");
	var $spos = $s.length;
	this._matrix = new cocktail.geom.Matrix();
	this._keyboard = new cocktailCore.keyboard.js.Keyboard();
	this._mouse = new cocktailCore.mouse.js.Mouse(this._nativeElement);
	this._registrationPoint = cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top);
	this._x = 0;
	this._y = 0;
	this.initStyle();
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.initStyle = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::initStyle");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getParent = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getParent");
	var $spos = $s.length;
	var $tmp = this._parent;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setParent = function(domElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setParent");
	var $spos = $s.length;
	this._parent = domElement;
	var $tmp = this._parent;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setNativeElement = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setNativeElement");
	var $spos = $s.length;
	this._nativeElement = value;
	this.init();
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getNativeElement = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getNativeElement");
	var $spos = $s.length;
	var $tmp = this._nativeElement;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setIsVisible = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setIsVisible");
	var $spos = $s.length;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getIsVisible = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getIsVisible");
	var $spos = $s.length;
	$s.pop();
	return false;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setAlpha");
	var $spos = $s.length;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getAlpha = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getAlpha");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setMatrix = function(matrix) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setMatrix");
	var $spos = $s.length;
	this._matrix = matrix;
	var $tmp = this._matrix;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getMatrix = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getMatrix");
	var $spos = $s.length;
	var $tmp = this._matrix;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.resetTransformations = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::resetTransformations");
	var $spos = $s.length;
	this._matrix.identity();
	this.setMatrix(this._matrix);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRegistrationPointValueAsPoint = function(registrationPoint) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getRegistrationPointValueAsPoint");
	var $spos = $s.length;
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
	$s.pop();
	return registrationPointPoint;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.translate = function(x,y) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::translate");
	var $spos = $s.length;
	this._matrix.translate(x,y);
	this.setMatrix(this._matrix);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.rotate = function(angle,registrationPoint) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::rotate");
	var $spos = $s.length;
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.rotate(angle,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.scale = function(scaleX,scaleY,registrationPoint) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::scale");
	var $spos = $s.length;
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.scale(scaleX,scaleY,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.skew = function(skewX,skewY,registrationPoint) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::skew");
	var $spos = $s.length;
	if(registrationPoint == null) registrationPoint = this.getRegistrationPoint();
	this._matrix.skew(skewX,skewY,this.getRegistrationPointValueAsPoint(registrationPoint));
	this.setMatrix(this._matrix);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setTranslationX = function(translationX) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setTranslationX");
	var $spos = $s.length;
	this._matrix.setTranslationX(translationX);
	this.setMatrix(this._matrix);
	$s.pop();
	return translationX;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getTranslationX = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getTranslationX");
	var $spos = $s.length;
	var $tmp = this._matrix.getTranslationX();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setTranslationY = function(translationY) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setTranslationY");
	var $spos = $s.length;
	this._matrix.setTranslationY(translationY);
	this.setMatrix(this._matrix);
	$s.pop();
	return translationY;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getTranslationY = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getTranslationY");
	var $spos = $s.length;
	var $tmp = this._matrix.getTranslationY();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleX = function(scaleX) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setScaleX");
	var $spos = $s.length;
	this._matrix.setScaleX(scaleX,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	$s.pop();
	return scaleX;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleX = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getScaleX");
	var $spos = $s.length;
	var $tmp = this._matrix.getScaleX();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setScaleY = function(scaleY) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setScaleY");
	var $spos = $s.length;
	if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
	this._matrix.setScaleY(scaleY,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	$s.pop();
	return scaleY;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getScaleY = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getScaleY");
	var $spos = $s.length;
	var $tmp = this._matrix.getScaleY();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setRotation = function(angle) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setRotation");
	var $spos = $s.length;
	if(this.getRegistrationPoint() == null) this.setRegistrationPoint(cocktail.geom.RegistrationPointValue.constant(cocktail.geom.RegistrationPointXValue.left,cocktail.geom.RegistrationPointYValue.top));
	this._matrix.setRotation(angle,this.getRegistrationPointValueAsPoint(this.getRegistrationPoint()));
	this.setMatrix(this._matrix);
	$s.pop();
	return angle;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRotation = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getRotation");
	var $spos = $s.length;
	var $tmp = this._matrix.getRotation();
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setRegistrationPoint = function(registrationPoint) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setRegistrationPoint");
	var $spos = $s.length;
	this._registrationPoint = registrationPoint;
	var $tmp = this._registrationPoint;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getRegistrationPoint = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getRegistrationPoint");
	var $spos = $s.length;
	var $tmp = this._registrationPoint;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDown = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseDown");
	var $spos = $s.length;
	this._mouse.onMouseDown = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDown = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseDown");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseDown;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseUp = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseUp");
	var $spos = $s.length;
	this._mouse.onMouseUp = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseUp = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseUp");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseUp;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOver = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseOver");
	var $spos = $s.length;
	this._mouse.onMouseOver = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOver = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseOver");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseOver;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseOut = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseOut");
	var $spos = $s.length;
	this._mouse.onMouseOut = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseOut = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseOut");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseOut;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseMove = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseMove");
	var $spos = $s.length;
	this._mouse.onMouseMove = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseMove = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseMove");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseMove;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnMouseDoubleClick = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnMouseDoubleClick");
	var $spos = $s.length;
	this._mouse.onMouseDoubleClick = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnMouseDoubleClick = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnMouseDoubleClick");
	var $spos = $s.length;
	var $tmp = this._mouse.onMouseDoubleClick;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyDown = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnKeyDown");
	var $spos = $s.length;
	this._keyboard.onKeyDown = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyDown = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnKeyDown");
	var $spos = $s.length;
	var $tmp = this._keyboard.onKeyDown;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setOnKeyUp = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setOnKeyUp");
	var $spos = $s.length;
	this._keyboard.onKeyUp = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOnKeyUp = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOnKeyUp");
	var $spos = $s.length;
	var $tmp = this._keyboard.onKeyUp;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setField = function(propertyName,propertyValue) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setField");
	var $spos = $s.length;
	this._nativeElement[propertyName] = propertyValue;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getField = function(propertyName) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getField");
	var $spos = $s.length;
	var $tmp = Reflect.field(this._nativeElement,propertyName);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setX = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setX");
	var $spos = $s.length;
	this._x = value;
	var $tmp = this._x;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getX = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getX");
	var $spos = $s.length;
	var $tmp = this._x;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setY = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setY");
	var $spos = $s.length;
	this._y = value;
	var $tmp = this._y;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getY = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getY");
	var $spos = $s.length;
	var $tmp = this._y;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setWidth = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setWidth");
	var $spos = $s.length;
	this._width = value;
	var $tmp = this._width;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getWidth = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getWidth");
	var $spos = $s.length;
	var $tmp = this._width;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setHeight = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setHeight");
	var $spos = $s.length;
	this._height = value;
	var $tmp = this._height;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getHeight = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getHeight");
	var $spos = $s.length;
	var $tmp = this._height;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOffsetWidth = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOffsetWidth");
	var $spos = $s.length;
	var computedStyle = this._style.getComputedStyle();
	var $tmp = computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getOffsetHeight = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getOffsetHeight");
	var $spos = $s.length;
	var computedStyle = this._style.getComputedStyle();
	var $tmp = computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setGlobalX = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setGlobalX");
	var $spos = $s.length;
	var localX = value;
	if(this._parent != null) {
		var parentGlobalX = this._parent.getGlobalX();
		localX -= parentGlobalX;
	} else localX = 0;
	this.setX(localX);
	var $tmp = this._x;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalX = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getGlobalX");
	var $spos = $s.length;
	var newGlobalX = this.getX();
	if(this._parent != null) {
		var parentDOMElement = this._parent;
		while(parentDOMElement != null) {
			newGlobalX += parentDOMElement.getX();
			parentDOMElement = parentDOMElement.getParent();
		}
	} else newGlobalX = 0;
	$s.pop();
	return newGlobalX;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setGlobalY = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setGlobalY");
	var $spos = $s.length;
	var localY = value;
	if(this._parent != null) {
		var parentGlobalY = this._parent.getGlobalY();
		localY -= parentGlobalY;
	} else localY = 0;
	this.setY(localY);
	var $tmp = this._y;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getGlobalY = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getGlobalY");
	var $spos = $s.length;
	var newGlobalY = this.getY();
	if(this._parent != null) {
		var parentDOMElement = this._parent;
		while(parentDOMElement != null) {
			newGlobalY += parentDOMElement.getY();
			parentDOMElement = parentDOMElement.getParent();
		}
	} else newGlobalY = 0;
	$s.pop();
	return newGlobalY;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setZIndex = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::setZIndex");
	var $spos = $s.length;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getZIndex = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getZIndex");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.getStyle = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractDOMElement::getStyle");
	var $spos = $s.length;
	var $tmp = this._style;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractDOMElement;
if(!cocktailCore.domElement.js) cocktailCore.domElement.js = {}
cocktailCore.domElement.js.DOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.DOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.__name__ = ["cocktailCore","domElement","js","DOMElement"];
cocktailCore.domElement.js.DOMElement.__super__ = cocktailCore.domElement.abstract.AbstractDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractDOMElement.prototype ) cocktailCore.domElement.js.DOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractDOMElement.prototype[k];
cocktailCore.domElement.js.DOMElement.prototype.init = function() {
	$s.push("cocktailCore.domElement.js.DOMElement::init");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.init.call(this);
	if(this._nativeElement.style.width != null) this._width = Std.parseInt(this._nativeElement.style.width); else this._width = this._nativeElement.offsetWidth;
	if(this._nativeElement.style.height != null) this._height = Std.parseInt(this._nativeElement.style.height); else this._height = this._nativeElement.offsetHeight;
	this._x = Std.parseInt(this._nativeElement.style.left);
	this._y = Std.parseInt(this._nativeElement.style.top);
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setIsVisible = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setIsVisible");
	var $spos = $s.length;
	if(value == true) this._nativeElement.style.visibility = "visible"; else this._nativeElement.style.visibility = "hidden";
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.getIsVisible = function() {
	$s.push("cocktailCore.domElement.js.DOMElement::getIsVisible");
	var $spos = $s.length;
	if(this._nativeElement.style.visibility == "visible") {
		$s.pop();
		return true;
	} else {
		$s.pop();
		return false;
	}
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setAlpha = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setAlpha");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setAlpha.call(this,value);
	this._nativeElement.style.opacity = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.getAlpha = function() {
	$s.push("cocktailCore.domElement.js.DOMElement::getAlpha");
	var $spos = $s.length;
	var $tmp = Std.parseFloat(this._nativeElement.style.opacity);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setMatrix = function(matrix) {
	$s.push("cocktailCore.domElement.js.DOMElement::setMatrix");
	var $spos = $s.length;
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
	var $tmp = this._matrix;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setX = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setX");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setX.call(this,value);
	this._nativeElement.style.left = value + "px";
	var $tmp = this._x;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setY = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setY");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setY.call(this,value);
	this._nativeElement.style.top = value + "px";
	var $tmp = this._y;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setWidth = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setWidth");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setWidth.call(this,value);
	this._nativeElement.style.width = value + "px";
	var $tmp = this._width;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setHeight = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setHeight");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractDOMElement.prototype.setHeight.call(this,value);
	this._nativeElement.style.height = value + "px";
	var $tmp = this._height;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.setZIndex = function(value) {
	$s.push("cocktailCore.domElement.js.DOMElement::setZIndex");
	var $spos = $s.length;
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
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.getZIndex = function() {
	$s.push("cocktailCore.domElement.js.DOMElement::getZIndex");
	var $spos = $s.length;
	var $tmp = this._nativeElement.style.zIndex;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.DOMElement.prototype.__class__ = cocktailCore.domElement.js.DOMElement;
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	this.initDimensions();
	this.initInstrinsicDimensions();
	$s.pop();
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
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::initStyle");
	var $spos = $s.length;
	this._style = new cocktailCore.style.js.EmbeddedStyle(this);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.initDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::initDimensions");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.initInstrinsicDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::initInstrinsicDimensions");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setIntrinsicWidth = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::setIntrinsicWidth");
	var $spos = $s.length;
	this._intrinsicWidth = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicWidth = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicWidth");
	var $spos = $s.length;
	var $tmp = this._intrinsicWidth;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setIntrinsicHeight = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::setIntrinsicHeight");
	var $spos = $s.length;
	this._intrinsicHeight = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicHeight = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicHeight");
	var $spos = $s.length;
	var $tmp = this._intrinsicHeight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.getIntrinsicRatio = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::getIntrinsicRatio");
	var $spos = $s.length;
	var $tmp = this._intrinsicRatio;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.setIntrinsicRatio = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement::setIntrinsicRatio");
	var $spos = $s.length;
	this._intrinsicRatio = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
cocktailCore.domElement.js.EmbeddedDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.EmbeddedDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.EmbeddedDOMElement.__name__ = ["cocktailCore","domElement","js","EmbeddedDOMElement"];
cocktailCore.domElement.js.EmbeddedDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype ) cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement.prototype[k];
cocktailCore.domElement.js.EmbeddedDOMElement.prototype.__class__ = cocktailCore.domElement.js.EmbeddedDOMElement;
cocktailCore.domElement.abstract.AbstractGraphicDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::new");
	var $spos = $s.length;
	if(nativeElement == null) nativeElement = cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.graphic);
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractGraphicDOMElement"];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
for(var k in cocktailCore.domElement.js.EmbeddedDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype[k] = cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.initDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::initDimensions");
	var $spos = $s.length;
	this._height = 150;
	this._width = 300;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.initInstrinsicDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::initInstrinsicDimensions");
	var $spos = $s.length;
	this._intrinsicHeight = this._height;
	this._intrinsicWidth = this._width;
	this._intrinsicRatio = this._width / this._height;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill = function(fillStyle,lineStyle) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::beginFill");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.endFill = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::endFill");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.clear = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::clear");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawRect = function(x,y,width,height,cornerRadiuses) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawRect");
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
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawEllipse = function(x,y,width,height) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawEllipse");
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
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawStar = function(x,y,outerRadius,innerRadius,branches) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawStar");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawPolygon = function(x,y,radius,sides) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawPolygon");
	var $spos = $s.length;
	var angle = 360 / sides;
	this.moveTo(Math.cos(0) * radius + radius,Math.sin(0) * radius + radius);
	var _g = 0;
	while(_g < sides) {
		var i = _g++;
		this.lineTo(Math.cos(this.conversion(i * angle)) * radius + radius,Math.sin(this.conversion(i * angle)) * radius + radius);
		this.lineTo(Math.cos(this.conversion(i * angle + angle)) * radius + radius,Math.sin(this.conversion(i * angle + angle)) * radius + radius);
	}
	this.lineTo(Math.cos(0) * radius + radius,Math.sin(0) * radius + radius);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.conversion = function(val) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::conversion");
	var $spos = $s.length;
	var $tmp = val / 180 * Math.PI;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.drawImage = function(source,destinationPoint,sourceRect) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::drawImage");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.lineTo = function(x,y) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::lineTo");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.moveTo = function(x,y) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::moveTo");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.curveTo = function(controlX,controlY,x,y) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::curveTo");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeAlpha = function(genericAlpa) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::toNativeAlpha");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeColor = function(genericColor) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::toNativeColor");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeRatio = function(genericRatio) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::toNativeRatio");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeCapStyle = function(genericCapStyle) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::toNativeCapStyle");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.toNativeJointStyle = function(genericJointStyle) {
	$s.push("cocktailCore.domElement.abstract.AbstractGraphicDOMElement::toNativeJointStyle");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
if(!cocktailCore.textElement) cocktailCore.textElement = {}
if(!cocktailCore.textElement["abstract"]) cocktailCore.textElement["abstract"] = {}
cocktailCore.textElement.abstract.AbstractTextElement = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.__name__ = ["cocktailCore","textElement","abstract","AbstractTextElement"];
cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::doGetTextFragments");
	var $spos = $s.length;
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
cocktailCore.textElement.abstract.AbstractTextElement.prototype._text = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype.text = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype._textFragments = null;
cocktailCore.textElement.abstract.AbstractTextElement.prototype.reset = function() {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::reset");
	var $spos = $s.length;
	var _g1 = 0, _g = this._textFragments.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._textFragments[i].textFragmentDOMElement = null;
	}
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getTextFragments = function(text) {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getTextFragments");
	var $spos = $s.length;
	if(this._textFragments == null) this._textFragments = cocktailCore.textElement.abstract.AbstractTextElement.doGetTextFragments(text);
	var $tmp = this._textFragments;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getNativeText = function() {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getNativeText");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.getText = function() {
	$s.push("cocktailCore.textElement.abstract.AbstractTextElement::getText");
	var $spos = $s.length;
	var $tmp = this._text;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.textElement.abstract.AbstractTextElement.prototype.__class__ = cocktailCore.textElement.abstract.AbstractTextElement;
if(!cocktailCore.style["abstract"]) cocktailCore.style["abstract"] = {}
cocktailCore.style.abstract.AbstractStyle = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.abstract.AbstractStyle::new");
	var $spos = $s.length;
	this._domElement = domElement;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.__name__ = ["cocktailCore","style","abstract","AbstractStyle"];
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
cocktailCore.style.abstract.AbstractStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElementDimensions,rootDOMElementDimensions,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::layout");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.flow = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData,formatingContext) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::flow");
	var $spos = $s.length;
	if(this.isNotDisplayed() == true) {
		this._domElement.setIsVisible(false);
		$s.pop();
		return;
	} else this._domElement.setIsVisible(true);
	if(this.isClear() == true) formatingContext.clearFloat(this._computedStyle.clear,this.isFloat());
	this.computeDOMElement(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData);
	this.flowChildren(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData,formatingContext);
	this.applyComputedDimensions();
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.applyComputedDimensions = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::applyComputedDimensions");
	var $spos = $s.length;
	this._domElement.setWidth(this._computedStyle.width);
	this._domElement.setHeight(this._computedStyle.height);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.flowChildren = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData,formatingContext) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::flowChildren");
	var $spos = $s.length;
	this.insertDOMElement(formatingContext,lastPositionedDOMElementDimensions,rootDOMElementDimensions);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.positionElement = function(lastPositionedDOMElementDimensions,rootDOMElementDimensions) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::positionElement");
	var $spos = $s.length;
	var positioner;
	if(this.isRelativePositioned() == true) {
		positioner = new cocktailCore.style.positioner.RelativePositioner();
		positioner.position(this._domElement,lastPositionedDOMElementDimensions);
	} else {
		switch( (this._domElement.getStyle().getComputedStyle().position)[1] ) {
		case 3:
			positioner = new cocktailCore.style.positioner.FixedPositioner();
			var scrolledRootDOMElementDimensions = rootDOMElementDimensions;
			positioner.position(this._domElement,scrolledRootDOMElementDimensions);
			break;
		case 2:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
			positioner.position(this._domElement,lastPositionedDOMElementDimensions);
			break;
		default:
			positioner = new cocktailCore.style.positioner.AbsolutePositioner();
		}
	}
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.insertDOMElement = function(formattingContext,lastPositionedDOMElementDimensions,rootDOMElementDimensions) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::insertDOMElement");
	var $spos = $s.length;
	if(this.isFloat() == true) formattingContext.insertFloat(this._domElement); else if(this.isPositioned() == false) this.insertInFlowDOMElement(formattingContext); else if(this.isRelativePositioned() == true) {
		this.insertInFlowDOMElement(formattingContext);
		this.positionElement(lastPositionedDOMElementDimensions,rootDOMElementDimensions);
	} else this.positionElement(lastPositionedDOMElementDimensions,rootDOMElementDimensions);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.insertInFlowDOMElement = function(formattingContext) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::insertInFlowDOMElement");
	var $spos = $s.length;
	formattingContext.insert(this._domElement);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeDOMElement = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::computeDOMElement");
	var $spos = $s.length;
	this.computeDisplayStyles();
	this.computeBoxModelStyles(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions);
	this.computeTextAndFontStyles(containingDOMElementData,containingDOMElementFontMetricsData);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeDisplayStyles = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::computeDisplayStyles");
	var $spos = $s.length;
	cocktailCore.style.computer.DisplayStylesComputer.compute(this);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeTextAndFontStyles = function(containingDOMElementData,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::computeTextAndFontStyles");
	var $spos = $s.length;
	cocktailCore.style.computer.FontAndTextStylesComputer.compute(this,containingDOMElementData,containingDOMElementFontMetricsData);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.computeBoxModelStyles = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::computeBoxModelStyles");
	var $spos = $s.length;
	var boxComputer = this.getBoxStylesComputer();
	var containingBlockDimensions = this.getContainingDOMElementData(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions);
	boxComputer.measure(this,containingBlockDimensions);
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getBoxStylesComputer = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.getContainingDOMElementData = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getContainingDOMElementData");
	var $spos = $s.length;
	var containingBlockDimensions;
	if(this.isPositioned() == true) {
		if(this._computedStyle.position == cocktail.style.PositionStyleValue.fixed) containingBlockDimensions = { width : rootDOMElementDimensions.width, height : rootDOMElementDimensions.height, isHeightAuto : rootDOMElementDimensions.isHeightAuto, isWidthAuto : rootDOMElementDimensions.isWidthAuto, globalX : rootDOMElementDimensions.globalX, globalY : rootDOMElementDimensions.globalY}; else if(this._computedStyle.position == cocktail.style.PositionStyleValue.absolute) containingBlockDimensions = { width : lastPositionedDOMElementDimensions.width, height : lastPositionedDOMElementDimensions.height, isHeightAuto : lastPositionedDOMElementDimensions.isHeightAuto, isWidthAuto : lastPositionedDOMElementDimensions.isWidthAuto, globalX : lastPositionedDOMElementDimensions.globalX, globalY : lastPositionedDOMElementDimensions.globalY}; else containingBlockDimensions = containingDOMElementData;
	} else containingBlockDimensions = containingDOMElementData;
	$s.pop();
	return containingBlockDimensions;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.isEmbedded = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::isEmbedded");
	var $spos = $s.length;
	$s.pop();
	return false;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.isFloat = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::isFloat");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.isClear = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isNotDisplayed = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::isNotDisplayed");
	var $spos = $s.length;
	var $tmp = this._computedStyle.display == cocktail.style.DisplayStyleValue.none;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.isInline = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::isInline");
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
cocktailCore.style.abstract.AbstractStyle.prototype.isPositioned = function() {
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
cocktailCore.style.abstract.AbstractStyle.prototype.isRelativePositioned = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::isRelativePositioned");
	var $spos = $s.length;
	var $tmp = this._computedStyle.position == cocktail.style.PositionStyleValue.relative;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontMetricsData = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontMetricsData");
	var $spos = $s.length;
	var $tmp = this._fontMetrics;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getComputedStyle = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getComputedStyle");
	var $spos = $s.length;
	var $tmp = this._computedStyle;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setComputedStyle = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setComputedStyle");
	var $spos = $s.length;
	var $tmp = this._computedStyle = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getDOMElement = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getDOMElement");
	var $spos = $s.length;
	var $tmp = this._domElement;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginLeft = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginLeft");
	var $spos = $s.length;
	var $tmp = this._marginLeft;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginLeft = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginLeft");
	var $spos = $s.length;
	var $tmp = this._marginLeft = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginRight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginRight");
	var $spos = $s.length;
	var $tmp = this._marginRight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginRight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginRight");
	var $spos = $s.length;
	var $tmp = this._marginRight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginTop = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginTop");
	var $spos = $s.length;
	var $tmp = this._marginTop;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginTop = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginTop");
	var $spos = $s.length;
	var $tmp = this._marginTop = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMarginBottom = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMarginBottom");
	var $spos = $s.length;
	var $tmp = this._marginBottom;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMarginBottom = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMarginBottom");
	var $spos = $s.length;
	var $tmp = this._marginBottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingLeft = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingLeft");
	var $spos = $s.length;
	var $tmp = this._paddingLeft;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingLeft = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingLeft");
	var $spos = $s.length;
	var $tmp = this._paddingLeft = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingRight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingRight");
	var $spos = $s.length;
	var $tmp = this._paddingRight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingRight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingRight");
	var $spos = $s.length;
	var $tmp = this._paddingRight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingTop = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingTop");
	var $spos = $s.length;
	var $tmp = this._paddingTop;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingTop = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingTop");
	var $spos = $s.length;
	var $tmp = this._paddingTop = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPaddingBottom = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getPaddingBottom");
	var $spos = $s.length;
	var $tmp = this._paddingBottom;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPaddingBottom = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setPaddingBottom");
	var $spos = $s.length;
	var $tmp = this._paddingBottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getDisplay = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getDisplay");
	var $spos = $s.length;
	var $tmp = this._display;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setDisplay = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setDisplay");
	var $spos = $s.length;
	var $tmp = this._display = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getPosition = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getPosition");
	var $spos = $s.length;
	var $tmp = this._position;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setPosition = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setPosition");
	var $spos = $s.length;
	var $tmp = this._position = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWidth = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getWidth");
	var $spos = $s.length;
	var $tmp = this._width;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWidth = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setWidth");
	var $spos = $s.length;
	var $tmp = this._width = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getHeight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getHeight");
	var $spos = $s.length;
	var $tmp = this._height;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setHeight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setHeight");
	var $spos = $s.length;
	var $tmp = this._height = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMinHeight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMinHeight");
	var $spos = $s.length;
	var $tmp = this._minHeight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMinHeight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMinHeight");
	var $spos = $s.length;
	var $tmp = this._minHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMaxHeight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMaxHeight");
	var $spos = $s.length;
	var $tmp = this._maxHeight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMaxHeight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMaxHeight");
	var $spos = $s.length;
	var $tmp = this._maxHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMinWidth = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMinWidth");
	var $spos = $s.length;
	var $tmp = this._minWidth;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMinWidth = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMinWidth");
	var $spos = $s.length;
	var $tmp = this._minWidth = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getMaxWidth = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getMaxWidth");
	var $spos = $s.length;
	var $tmp = this._maxWidth;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setMaxWidth = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setMaxWidth");
	var $spos = $s.length;
	var $tmp = this._maxWidth = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTop = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getTop");
	var $spos = $s.length;
	var $tmp = this._top;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTop = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setTop");
	var $spos = $s.length;
	var $tmp = this._top = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLeft = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getLeft");
	var $spos = $s.length;
	var $tmp = this._left;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLeft = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setLeft");
	var $spos = $s.length;
	var $tmp = this._left = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getBottom = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getBottom");
	var $spos = $s.length;
	var $tmp = this._bottom;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setBottom = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setBottom");
	var $spos = $s.length;
	var $tmp = this._bottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getRight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getRight");
	var $spos = $s.length;
	var $tmp = this._right;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setRight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setRight");
	var $spos = $s.length;
	var $tmp = this._right = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFloat = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFloat");
	var $spos = $s.length;
	var $tmp = this._float;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFloat = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFloat");
	var $spos = $s.length;
	var $tmp = this._float = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getClear = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getClear");
	var $spos = $s.length;
	var $tmp = this._clear;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setClear = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setClear");
	var $spos = $s.length;
	var $tmp = this._clear = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontSize = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFontSize");
	var $spos = $s.length;
	var $tmp = this._fontSize = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontSize = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontSize");
	var $spos = $s.length;
	var $tmp = this._fontSize;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontWeight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFontWeight");
	var $spos = $s.length;
	var $tmp = this._fontWeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontWeight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontWeight");
	var $spos = $s.length;
	var $tmp = this._fontWeight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontStyle = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFontStyle");
	var $spos = $s.length;
	var $tmp = this._fontStyle = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontStyle = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontStyle");
	var $spos = $s.length;
	var $tmp = this._fontStyle;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontFamily = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFontFamily");
	var $spos = $s.length;
	var $tmp = this._fontFamily = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontFamily = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontFamily");
	var $spos = $s.length;
	var $tmp = this._fontFamily;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setFontVariant = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setFontVariant");
	var $spos = $s.length;
	var $tmp = this._fontVariant = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getFontVariant = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getFontVariant");
	var $spos = $s.length;
	var $tmp = this._fontVariant;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextTransform = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setTextTransform");
	var $spos = $s.length;
	var $tmp = this._textTransform = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextTransform = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getTextTransform");
	var $spos = $s.length;
	var $tmp = this._textTransform;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLetterSpacing = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setLetterSpacing");
	var $spos = $s.length;
	var $tmp = this._letterSpacing = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLetterSpacing = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getLetterSpacing");
	var $spos = $s.length;
	var $tmp = this._letterSpacing;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setColor = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setColor");
	var $spos = $s.length;
	var $tmp = this._color = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getColor = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getColor");
	var $spos = $s.length;
	var $tmp = this._color;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWordSpacing = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setWordSpacing");
	var $spos = $s.length;
	var $tmp = this._wordSpacing = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWordSpacing = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getWordSpacing");
	var $spos = $s.length;
	var $tmp = this._wordSpacing;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setLineHeight = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setLineHeight");
	var $spos = $s.length;
	var $tmp = this._lineHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getLineHeight = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getLineHeight");
	var $spos = $s.length;
	var $tmp = this._lineHeight;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setVerticalAlign = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setVerticalAlign");
	var $spos = $s.length;
	var $tmp = this._verticalAlign = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getVerticalAlign = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getVerticalAlign");
	var $spos = $s.length;
	var $tmp = this._verticalAlign;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextIndent = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getTextIndent");
	var $spos = $s.length;
	var $tmp = this._textIndent;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextIndent = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setTextIndent");
	var $spos = $s.length;
	var $tmp = this._textIndent = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setWhiteSpace = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setWhiteSpace");
	var $spos = $s.length;
	var $tmp = this._whiteSpace = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getWhiteSpace = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getWhiteSpace");
	var $spos = $s.length;
	var $tmp = this._whiteSpace;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.setTextAlign = function(value) {
	$s.push("cocktailCore.style.abstract.AbstractStyle::setTextAlign");
	var $spos = $s.length;
	var $tmp = this._textAlign = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.getTextAlign = function() {
	$s.push("cocktailCore.style.abstract.AbstractStyle::getTextAlign");
	var $spos = $s.length;
	var $tmp = this._textAlign;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractStyle;
if(!cocktailCore.style.js) cocktailCore.style.js = {}
cocktailCore.style.js.Style = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.js.Style::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.Style.__name__ = ["cocktailCore","style","js","Style"];
cocktailCore.style.js.Style.__super__ = cocktailCore.style.abstract.AbstractStyle;
for(var k in cocktailCore.style.abstract.AbstractStyle.prototype ) cocktailCore.style.js.Style.prototype[k] = cocktailCore.style.abstract.AbstractStyle.prototype[k];
cocktailCore.style.js.Style.prototype.getCSSDisplay = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSDisplay");
	var $spos = $s.length;
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
	$s.pop();
	return displayValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFloat = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFloat");
	var $spos = $s.length;
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
	$s.pop();
	return floatValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSClear = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSClear");
	var $spos = $s.length;
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
	$s.pop();
	return clearValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSPosition = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSPosition");
	var $spos = $s.length;
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
	$s.pop();
	return positionValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSMargin = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSMargin");
	var $spos = $s.length;
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
	$s.pop();
	return marginValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSPadding = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSPadding");
	var $spos = $s.length;
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
	$s.pop();
	return paddingValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSDimension = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSDimension");
	var $spos = $s.length;
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
	$s.pop();
	return dimensionValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSPositionOffset = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSPositionOffset");
	var $spos = $s.length;
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
	$s.pop();
	return positionOffsetValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSConstrainedDimension = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSConstrainedDimension");
	var $spos = $s.length;
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
	$s.pop();
	return constrainedValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSVerticalAlign = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSVerticalAlign");
	var $spos = $s.length;
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
	$s.pop();
	return verticalAlignValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSLineHeight = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSLineHeight");
	var $spos = $s.length;
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
	$s.pop();
	return lineHeightValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFontSize = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFontSize");
	var $spos = $s.length;
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
	$s.pop();
	return fontValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFontWeight = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFontWeight");
	var $spos = $s.length;
	var fontWeightValue;
	switch( (value)[1] ) {
	case 0:
		fontWeightValue = "normal";
		break;
	case 1:
		fontWeightValue = "bold";
		break;
	}
	$s.pop();
	return fontWeightValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFontStyle = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFontStyle");
	var $spos = $s.length;
	var fontStyleValue;
	switch( (value)[1] ) {
	case 0:
		fontStyleValue = "normal";
		break;
	case 1:
		fontStyleValue = "italic";
		break;
	}
	$s.pop();
	return fontStyleValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFontVariant = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFontVariant");
	var $spos = $s.length;
	var fontVariantValue;
	switch( (value)[1] ) {
	case 0:
		fontVariantValue = "normal";
		break;
	case 1:
		fontVariantValue = "small-caps";
		break;
	}
	$s.pop();
	return fontVariantValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSFontFamily = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSFontFamily");
	var $spos = $s.length;
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
	$s.pop();
	return fontFamilyValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSTextAlign = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSTextAlign");
	var $spos = $s.length;
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
	$s.pop();
	return textAlignValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSWhiteSpace = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSWhiteSpace");
	var $spos = $s.length;
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
	$s.pop();
	return whiteSpaceValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSTextTransform = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSTextTransform");
	var $spos = $s.length;
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
	$s.pop();
	return textTransformValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSTextIndent = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSTextIndent");
	var $spos = $s.length;
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
	$s.pop();
	return textIndentValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSLetterSpacing = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSLetterSpacing");
	var $spos = $s.length;
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
	$s.pop();
	return letterSpacingValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSWordSpacing = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSWordSpacing");
	var $spos = $s.length;
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
	$s.pop();
	return wordSpacingValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSColor = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSColor");
	var $spos = $s.length;
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
	$s.pop();
	return colorValue;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSLengthValue = function(lengthValue) {
	$s.push("cocktailCore.style.js.Style::getCSSLengthValue");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getCSSPercentValue = function(value) {
	$s.push("cocktailCore.style.js.Style::getCSSPercentValue");
	var $spos = $s.length;
	var $tmp = value + "%";
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.getColorFromKeyword = function(value) {
	$s.push("cocktailCore.style.js.Style::getColorFromKeyword");
	var $spos = $s.length;
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
	$s.pop();
	return hexColor;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setVerticalAlign = function(value) {
	$s.push("cocktailCore.style.js.Style::setVerticalAlign");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.verticalAlign = this.getCSSVerticalAlign(value);
	var $tmp = this._verticalAlign = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setColor = function(value) {
	$s.push("cocktailCore.style.js.Style::setColor");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.color = this.getCSSColor(value);
	var $tmp = this._color = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setWordSpacing = function(value) {
	$s.push("cocktailCore.style.js.Style::setWordSpacing");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.wordSpacing = this.getCSSWordSpacing(value);
	var $tmp = this._wordSpacing = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setLetterSpacing = function(value) {
	$s.push("cocktailCore.style.js.Style::setLetterSpacing");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.letterSpacing = this.getCSSLetterSpacing(value);
	var $tmp = this._letterSpacing = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setTextTransform = function(value) {
	$s.push("cocktailCore.style.js.Style::setTextTransform");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.textTransform = this.getCSSTextTransform(value);
	var $tmp = this._textTransform = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFontVariant = function(value) {
	$s.push("cocktailCore.style.js.Style::setFontVariant");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.fontVariant = this.getCSSFontVariant(value);
	var $tmp = this._fontVariant = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFontFamily = function(value) {
	$s.push("cocktailCore.style.js.Style::setFontFamily");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.fontFamily = this.getCSSFontFamily(value);
	var $tmp = this._fontFamily = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFontWeight = function(value) {
	$s.push("cocktailCore.style.js.Style::setFontWeight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.fontWeight = this.getCSSFontWeight(value);
	var $tmp = this._fontWeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFontStyle = function(value) {
	$s.push("cocktailCore.style.js.Style::setFontStyle");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.fontStyle = this.getCSSFontStyle(value);
	var $tmp = this._fontStyle = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFontSize = function(value) {
	$s.push("cocktailCore.style.js.Style::setFontSize");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.fontSize = this.getCSSFontSize(value);
	var $tmp = this._fontSize = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setLineHeight = function(value) {
	$s.push("cocktailCore.style.js.Style::setLineHeight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.lineHeight = this.getCSSLineHeight(value);
	var $tmp = this._lineHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMarginLeft = function(value) {
	$s.push("cocktailCore.style.js.Style::setMarginLeft");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.marginLeft = this.getCSSMargin(value);
	var $tmp = this._marginLeft = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMarginRight = function(value) {
	$s.push("cocktailCore.style.js.Style::setMarginRight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.marginRight = this.getCSSMargin(value);
	var $tmp = this._marginRight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMarginTop = function(value) {
	$s.push("cocktailCore.style.js.Style::setMarginTop");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.marginTop = this.getCSSMargin(value);
	var $tmp = this._marginTop = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMarginBottom = function(value) {
	$s.push("cocktailCore.style.js.Style::setMarginBottom");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.marginBottom = this.getCSSMargin(value);
	var $tmp = this._marginBottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setPaddingLeft = function(value) {
	$s.push("cocktailCore.style.js.Style::setPaddingLeft");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.paddingLeft = this.getCSSPadding(value);
	var $tmp = this._paddingLeft = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setPaddingRight = function(value) {
	$s.push("cocktailCore.style.js.Style::setPaddingRight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.paddingRight = this.getCSSPadding(value);
	var $tmp = this._paddingRight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setPaddingTop = function(value) {
	$s.push("cocktailCore.style.js.Style::setPaddingTop");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.paddingTop = this.getCSSPadding(value);
	var $tmp = this._paddingTop = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setPaddingBottom = function(value) {
	$s.push("cocktailCore.style.js.Style::setPaddingBottom");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.paddingBottom = this.getCSSPadding(value);
	var $tmp = this._paddingBottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setDisplay = function(value) {
	$s.push("cocktailCore.style.js.Style::setDisplay");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.display = this.getCSSDisplay(value);
	var $tmp = this._display = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setPosition = function(value) {
	$s.push("cocktailCore.style.js.Style::setPosition");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.position = this.getCSSPosition(value);
	var $tmp = this._position = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setWidth = function(value) {
	$s.push("cocktailCore.style.js.Style::setWidth");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.width = this.getCSSDimension(value);
	var $tmp = this._width = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setHeight = function(value) {
	$s.push("cocktailCore.style.js.Style::setHeight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.height = this.getCSSDimension(value);
	var $tmp = this._height = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMinHeight = function(value) {
	$s.push("cocktailCore.style.js.Style::setMinHeight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.minHeight = this.getCSSConstrainedDimension(value);
	var $tmp = this._minHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMaxHeight = function(value) {
	$s.push("cocktailCore.style.js.Style::setMaxHeight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.maxHeight = this.getCSSConstrainedDimension(value);
	var $tmp = this._maxHeight = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMinWidth = function(value) {
	$s.push("cocktailCore.style.js.Style::setMinWidth");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.minWidth = this.getCSSConstrainedDimension(value);
	var $tmp = this._minWidth = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setMaxWidth = function(value) {
	$s.push("cocktailCore.style.js.Style::setMaxWidth");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.maxWidth = this.getCSSConstrainedDimension(value);
	var $tmp = this._maxWidth = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setTop = function(value) {
	$s.push("cocktailCore.style.js.Style::setTop");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.top = this.getCSSPositionOffset(value);
	var $tmp = this._top = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setLeft = function(value) {
	$s.push("cocktailCore.style.js.Style::setLeft");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.left = this.getCSSPositionOffset(value);
	var $tmp = this._left = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setBottom = function(value) {
	$s.push("cocktailCore.style.js.Style::setBottom");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.bottom = this.getCSSPositionOffset(value);
	var $tmp = this._bottom = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setRight = function(value) {
	$s.push("cocktailCore.style.js.Style::setRight");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.right = this.getCSSPositionOffset(value);
	var $tmp = this._right = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setTextIndent = function(value) {
	$s.push("cocktailCore.style.js.Style::setTextIndent");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.textIndent = this.getCSSTextIndent(value);
	var $tmp = this._textIndent = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setFloat = function(value) {
	$s.push("cocktailCore.style.js.Style::setFloat");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.cssFloat = this.getCSSFloat(value);
	var $tmp = this._float = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setClear = function(value) {
	$s.push("cocktailCore.style.js.Style::setClear");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.clear = this.getCSSClear(value);
	var $tmp = this._clear = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setWhiteSpace = function(value) {
	$s.push("cocktailCore.style.js.Style::setWhiteSpace");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.whiteSpace = this.getCSSWhiteSpace(value);
	var $tmp = this._whiteSpace = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.setTextAlign = function(value) {
	$s.push("cocktailCore.style.js.Style::setTextAlign");
	var $spos = $s.length;
	this._domElement.getNativeElement().style.textAlign = this.getCSSTextAlign(value);
	var $tmp = this._textAlign = value;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.js.Style.prototype.__class__ = cocktailCore.style.js.Style;
cocktailCore.style.abstract.AbstractContainerStyle = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::new");
	var $spos = $s.length;
	cocktailCore.style.js.Style.call(this,domElement);
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.__name__ = ["cocktailCore","style","abstract","AbstractContainerStyle"];
cocktailCore.style.abstract.AbstractContainerStyle.__super__ = cocktailCore.style.js.Style;
for(var k in cocktailCore.style.js.Style.prototype ) cocktailCore.style.abstract.AbstractContainerStyle.prototype[k] = cocktailCore.style.js.Style.prototype[k];
cocktailCore.style.abstract.AbstractContainerStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElement,rootDOMElement,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::layout");
	var $spos = $s.length;
	this.flow(containingDOMElementData,rootDOMElement,lastPositionedDOMElement,null);
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.flowChildren = function(containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData,formatingContext) {
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
	var childrenFormattingContext;
	if(formatingContext == null) {
		formatingContext = this.getFormatingContext();
		childrenFormattingContext = this.getFormatingContext();
	} else childrenFormattingContext = this.getFormatingContext(formatingContext);
	var childrenContainingDOMElementData = this.getChildrenContainingDOMElementData();
	var childrenContainingDOMElementFontMetricsData = this.getFontMetricsData();
	var childLastPositionedDOMElementDimensions;
	if(this.isPositioned() == true) childLastPositionedDOMElementDimensions = this.getChildrenContainingDOMElementData(); else childLastPositionedDOMElementDimensions = lastPositionedDOMElementDimensions;
	var _g1 = 0, _g = containerDOMElement.getChildren().length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this.isDOMElement(containerDOMElement.getChildren()[i]) == true) {
			var childrenDOMElement = containerDOMElement.getChildren()[i].child;
			childrenDOMElement.getStyle().flow(childrenContainingDOMElementData,rootDOMElementDimensions,childLastPositionedDOMElementDimensions,childrenContainingDOMElementFontMetricsData,childrenFormattingContext);
		} else {
			var childrenTextElement = containerDOMElement.getChildren()[i].child;
			this.insertTextElement(childrenTextElement,childrenFormattingContext,childrenContainingDOMElementData,rootDOMElementDimensions,childLastPositionedDOMElementDimensions,containingDOMElementFontMetricsData);
		}
	}
	if(childrenFormattingContext != formatingContext) childrenFormattingContext.destroy();
	if(this._height == cocktail.style.DimensionStyleValue.auto) this._computedStyle.height = childrenFormattingContext.getFlowData().totalHeight;
	if(this._width == cocktail.style.DimensionStyleValue.auto) this._computedStyle.width = this.shrinkToFitIfNeeded(containingDOMElementData.width,childrenFormattingContext.getFlowData().maxWidth);
	this.insertDOMElement(formatingContext,lastPositionedDOMElementDimensions,rootDOMElementDimensions);
	formatingContext.retrieveFloats(childrenFormattingContext);
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertInFlowDOMElement = function(formattingContext) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::insertInFlowDOMElement");
	var $spos = $s.length;
	if(this.isInline() == false || this.isInlineFlow() == false) cocktailCore.style.js.Style.prototype.insertInFlowDOMElement.call(this,formattingContext);
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.insertTextElement = function(textElement,formattingContext,containingDOMElementData,rootDOMElementDimensions,lastPositionedDOMElementDimensions,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::insertTextElement");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.shrinkToFitIfNeeded = function(availableWidth,minimumWidth) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::shrinkToFitIfNeeded");
	var $spos = $s.length;
	var boxComputer = this.getBoxStylesComputer();
	var $tmp = boxComputer.shrinkToFit(this._computedStyle,availableWidth,minimumWidth);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getTextFragmentDOMElement = function(textFragmentData,text) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.createTextFragment = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::createTextFragment");
	var $spos = $s.length;
	var textFragmentDOMElement = this.doCreateTextFragment(text);
	var containerDOMElement = this._domElement;
	containerDOMElement.addTextFragment(textFragmentDOMElement);
	$s.pop();
	return textFragmentDOMElement;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.doCreateTextFragment = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::doCreateTextFragment");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.applyWhiteSpace = function(text,whiteSpace) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::applyWhiteSpace");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.applyTextTransform = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::applyTextTransform");
	var $spos = $s.length;
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
	$s.pop();
	return text;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.capitalizeText = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::capitalizeText");
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.collapseSpaceSequences = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::collapseSpaceSequences");
	var $spos = $s.length;
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
	$s.pop();
	return collapsedText;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.removeLineFeeds = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::removeLineFeeds");
	var $spos = $s.length;
	var $tmp = StringTools.replace(text,"\n","");
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.convertTabToSpace = function(text) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::convertTabToSpace");
	var $spos = $s.length;
	var $tmp = StringTools.replace(text,"\t"," ");
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getFormatingContext = function(previousFormatingContext) {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getFormatingContext");
	var $spos = $s.length;
	var containerDOMElement = this._domElement;
	var formattingContext;
	if(this.startsNewFormattingContext() == true) {
		var usedFormatingContext;
		if(this.isPositioned() == true && this.isRelativePositioned() == false) usedFormatingContext = null; else usedFormatingContext = previousFormatingContext;
		if(this.childrenInline() == true) formattingContext = new cocktailCore.style.formatter.InlineFormattingContext(containerDOMElement,usedFormatingContext); else formattingContext = new cocktailCore.style.formatter.BlockFormattingContext(containerDOMElement,usedFormatingContext);
	} else formattingContext = previousFormatingContext;
	$s.pop();
	return formattingContext;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.getChildrenContainingDOMElementData = function() {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::getChildrenContainingDOMElementData");
	var $spos = $s.length;
	var height;
	if(this.isInline() == true) height = Math.round(this._computedStyle.lineHeight); else if(this.isInline() == false && this.childrenInline() == true) height = Math.round(this._computedStyle.lineHeight); else height = this._computedStyle.height;
	var $tmp = { width : this._computedStyle.width, isWidthAuto : this._width == cocktail.style.DimensionStyleValue.auto, height : height, isHeightAuto : this._height == cocktail.style.DimensionStyleValue.auto, globalX : this._domElement.getGlobalX(), globalY : this._domElement.getGlobalY()};
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.childrenInline = function() {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::childrenInline");
	var $spos = $s.length;
	var ret = true;
	var containerDOMElement = this._domElement;
	var _g1 = 0, _g = containerDOMElement.getChildren().length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this.isDOMElement(containerDOMElement.getChildren()[i])) {
			var childrenDOMElement = containerDOMElement.getChildren()[i].child;
			if(childrenDOMElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.block) {
				if(childrenDOMElement.getStyle().isFloat() == false) ret = false; else if(childrenDOMElement.getStyle().isEmbedded() == true) ret = false;
			}
		}
	}
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.startsNewFormattingContext = function() {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::startsNewFormattingContext");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.abstract.AbstractContainerStyle.prototype.isInlineFlow = function() {
	$s.push("cocktailCore.style.abstract.AbstractContainerStyle::isInlineFlow");
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.isDOMElement = function(containerDOMElementChildData) {
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
cocktailCore.style.abstract.AbstractContainerStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractContainerStyle;
if(!cocktail.geom) cocktail.geom = {}
cocktail.geom.Matrix = function(data) {
	if( data === $_ ) return;
	$s.push("cocktail.geom.Matrix::new");
	var $spos = $s.length;
	this.setData(data);
	$s.pop();
}
cocktail.geom.Matrix.__name__ = ["cocktail","geom","Matrix"];
cocktail.geom.Matrix.prototype._data = null;
cocktail.geom.Matrix.prototype.data = null;
cocktail.geom.Matrix.prototype.identity = function() {
	$s.push("cocktail.geom.Matrix::identity");
	var $spos = $s.length;
	this._data = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : 0.0, f : 0.0};
	$s.pop();
}
cocktail.geom.Matrix.prototype.setData = function(data) {
	$s.push("cocktail.geom.Matrix::setData");
	var $spos = $s.length;
	this._data = data;
	if(this._data == null) this.identity();
	var $tmp = this._data;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.getData = function() {
	$s.push("cocktail.geom.Matrix::getData");
	var $spos = $s.length;
	var $tmp = this._data;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.concatenate = function(matrix) {
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
cocktail.geom.Matrix.prototype.translate = function(x,y) {
	$s.push("cocktail.geom.Matrix::translate");
	var $spos = $s.length;
	var translationMatrixData = { a : 1.0, b : 0.0, c : 0.0, d : 1.0, e : x, f : y};
	var translationMatrix = new cocktail.geom.Matrix(translationMatrixData);
	this.concatenate(translationMatrix);
	$s.pop();
}
cocktail.geom.Matrix.prototype.rotate = function(angle,registrationPoint) {
	$s.push("cocktail.geom.Matrix::rotate");
	var $spos = $s.length;
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
	$s.pop();
}
cocktail.geom.Matrix.prototype.scale = function(scaleX,scaleY,registrationPoint) {
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
cocktail.geom.Matrix.prototype.skew = function(skewX,skewY,registrationPoint) {
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
cocktail.geom.Matrix.prototype.setRotation = function(angle,registrationPoint) {
	$s.push("cocktail.geom.Matrix::setRotation");
	var $spos = $s.length;
	var currentRotation = this.getRotation();
	var resetAngle = 360 - currentRotation;
	this.rotate(resetAngle,registrationPoint);
	this.rotate(angle,registrationPoint);
	$s.pop();
}
cocktail.geom.Matrix.prototype.getRotation = function() {
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
	var rotationInDeg = Math.round(rotationInRad * 180 / Math.PI);
	if(rotationInDeg < 0) rotationInDeg = 360 + rotationInDeg;
	$s.pop();
	return rotationInDeg;
	$s.pop();
}
cocktail.geom.Matrix.prototype.getFlip = function() {
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
cocktail.geom.Matrix.prototype.setScaleX = function(scaleXFactor,registrationPoint) {
	$s.push("cocktail.geom.Matrix::setScaleX");
	var $spos = $s.length;
	var currentScaleX = this.getScaleX();
	var resetScaleX = 1 / currentScaleX;
	this.scale(resetScaleX,1,registrationPoint);
	this.scale(scaleXFactor,1,registrationPoint);
	$s.pop();
}
cocktail.geom.Matrix.prototype.getScaleX = function() {
	$s.push("cocktail.geom.Matrix::getScaleX");
	var $spos = $s.length;
	var $tmp = this._data.a;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.setScaleY = function(scaleYFactor,registrationPoint) {
	$s.push("cocktail.geom.Matrix::setScaleY");
	var $spos = $s.length;
	var currentScaleY = this.getScaleY();
	var resetScaleY = 1 / currentScaleY;
	this.scale(1,resetScaleY,registrationPoint);
	this.scale(1,scaleYFactor,registrationPoint);
	$s.pop();
}
cocktail.geom.Matrix.prototype.getScaleY = function() {
	$s.push("cocktail.geom.Matrix::getScaleY");
	var $spos = $s.length;
	var $tmp = this._data.d;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.setTranslationX = function(translationX) {
	$s.push("cocktail.geom.Matrix::setTranslationX");
	var $spos = $s.length;
	var currentTranslationX = this.getTranslationX();
	var resetTranslationX = currentTranslationX * -1;
	this.translate(resetTranslationX,0);
	this.translate(translationX,0);
	$s.pop();
}
cocktail.geom.Matrix.prototype.getTranslationX = function() {
	$s.push("cocktail.geom.Matrix::getTranslationX");
	var $spos = $s.length;
	var $tmp = this._data.e;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.setTranslationY = function(translationY) {
	$s.push("cocktail.geom.Matrix::setTranslationY");
	var $spos = $s.length;
	var currentTranslationY = this.getTranslationY();
	var resetTranslationY = currentTranslationY * -1;
	this.translate(0,resetTranslationY);
	this.translate(0,translationY);
	$s.pop();
}
cocktail.geom.Matrix.prototype.getTranslationY = function() {
	$s.push("cocktail.geom.Matrix::getTranslationY");
	var $spos = $s.length;
	var $tmp = this._data.f;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.getSkewX = function() {
	$s.push("cocktail.geom.Matrix::getSkewX");
	var $spos = $s.length;
	var $tmp = this._data.c;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.getSkewY = function() {
	$s.push("cocktail.geom.Matrix::getSkewY");
	var $spos = $s.length;
	var $tmp = this._data.b;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktail.geom.Matrix.prototype.__class__ = cocktail.geom.Matrix;
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
if(!cocktailCore.style.formatter) cocktailCore.style.formatter = {}
cocktailCore.style.formatter.FormattingContext = function(domElement,previousFormatingContext) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.formatter.FormattingContext::new");
	var $spos = $s.length;
	this._containingDOMElement = domElement;
	this._containingDOMElementWidth = this._containingDOMElement.getStyle().getComputedStyle().width;
	this._floatsManager = new cocktailCore.style.floats.FloatsManager();
	if(previousFormatingContext != null) {
		if(domElement.getStyle().isFloat() == false) this._floatsManager.addFloats(previousFormatingContext);
	}
	this._flowData = this.initFlowData(this._containingDOMElement);
	$s.pop();
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
	$s.push("cocktailCore.style.formatter.FormattingContext::initFlowData");
	var $spos = $s.length;
	var flowY = domElement.getStyle().getComputedStyle().paddingTop;
	var flowX;
	if(domElement.getStyle().getComputedStyle().paddingLeft > this._floatsManager.getLeftFloatOffset(flowY)) flowX = domElement.getStyle().getComputedStyle().paddingLeft; else flowX = this._floatsManager.getLeftFloatOffset(flowY);
	var $tmp = { x : flowX, y : flowY, xOffset : domElement.getStyle().getComputedStyle().paddingLeft, yOffset : domElement.getStyle().getComputedStyle().paddingTop, totalHeight : 0, maxWidth : 0};
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.insert = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::insert");
	var $spos = $s.length;
	this.doInsert(domElement);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.insertSpace = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::insertSpace");
	var $spos = $s.length;
	this.doInsert(domElement);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.insertTab = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::insertTab");
	var $spos = $s.length;
	this.doInsert(domElement);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.insertLineFeed = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::insertLineFeed");
	var $spos = $s.length;
	this.startNewLine(0);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.insertFloat = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::insertFloat");
	var $spos = $s.length;
	var floatData = this._floatsManager.computeFloatData(domElement,this._flowData,this._containingDOMElementWidth);
	this.placeFloat(domElement,floatData);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.clearFloat = function(clear,isFloat) {
	$s.push("cocktailCore.style.formatter.FormattingContext::clearFloat");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.retrieveFloats = function(formattingContext) {
	$s.push("cocktailCore.style.formatter.FormattingContext::retrieveFloats");
	var $spos = $s.length;
	this._floatsManager.retrieveFloats(formattingContext);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.destroy = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::destroy");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.startNewLine = function(domElementWidth,isLastLine) {
	$s.push("cocktailCore.style.formatter.FormattingContext::startNewLine");
	var $spos = $s.length;
	if(isLastLine == null) isLastLine = false;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.doInsert = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::doInsert");
	var $spos = $s.length;
	this.place(domElement);
	this.removeFloats();
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.getRemainingLineWidth = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::getRemainingLineWidth");
	var $spos = $s.length;
	var $tmp = this._containingDOMElementWidth - this._flowData.x + this._flowData.xOffset - this._floatsManager.getRightFloatOffset(this._flowData.y,this._containingDOMElementWidth);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.place = function(domElement) {
	$s.push("cocktailCore.style.formatter.FormattingContext::place");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.placeFloat = function(domElement,floatData) {
	$s.push("cocktailCore.style.formatter.FormattingContext::placeFloat");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.removeFloats = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::removeFloats");
	var $spos = $s.length;
	this._floatsManager.removeFloats(this._flowData.y);
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.getFloatsManager = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::getFloatsManager");
	var $spos = $s.length;
	var $tmp = this._floatsManager;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.getFlowData = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::getFlowData");
	var $spos = $s.length;
	var $tmp = this._flowData;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.getContainingDOMElement = function() {
	$s.push("cocktailCore.style.formatter.FormattingContext::getContainingDOMElement");
	var $spos = $s.length;
	var $tmp = this._containingDOMElement;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.FormattingContext.prototype.__class__ = cocktailCore.style.formatter.FormattingContext;
cocktailCore.style.positioner.FixedPositioner = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.positioner.FixedPositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.FixedPositioner.__name__ = ["cocktailCore","style","positioner","FixedPositioner"];
cocktailCore.style.positioner.FixedPositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.FixedPositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.FixedPositioner.prototype.__class__ = cocktailCore.style.positioner.FixedPositioner;
cocktailCore.domElement.abstract.AbstractImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.EmbeddedDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractImageDOMElement"];
cocktailCore.domElement.abstract.AbstractImageDOMElement.__super__ = cocktailCore.domElement.js.EmbeddedDOMElement;
for(var k in cocktailCore.domElement.js.EmbeddedDOMElement.prototype ) cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k] = cocktailCore.domElement.js.EmbeddedDOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._src = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.src = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype._smooth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.smooth = null;
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.init = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::init");
	var $spos = $s.length;
	cocktailCore.domElement.js.EmbeddedDOMElement.prototype.init.call(this);
	this.setSmooth(true);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.initDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::initDimensions");
	var $spos = $s.length;
	this._height = 0;
	this._width = 0;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.initInstrinsicDimensions = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::initInstrinsicDimensions");
	var $spos = $s.length;
	this._intrinsicHeight = 0;
	this._intrinsicWidth = 0;
	this._intrinsicRatio = 0;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getSrc = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::getSrc");
	var $spos = $s.length;
	var $tmp = this._src;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSrc = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::setSrc");
	var $spos = $s.length;
	this._src = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSmooth = function(value) {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::setSmooth");
	var $spos = $s.length;
	this._smooth = value;
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.getSmooth = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractImageDOMElement::getSmooth");
	var $spos = $s.length;
	var $tmp = this._smooth;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
cocktailCore.domElement.js.ImageDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.ImageDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.ImageDOMElement.__name__ = ["cocktailCore","domElement","js","ImageDOMElement"];
cocktailCore.domElement.js.ImageDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractImageDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype ) cocktailCore.domElement.js.ImageDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype[k];
cocktailCore.domElement.js.ImageDOMElement.prototype.setSmooth = function(value) {
	$s.push("cocktailCore.domElement.js.ImageDOMElement::setSmooth");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractImageDOMElement.prototype.setSmooth.call(this,value);
	if(value == true) this._nativeElement.style.imageRendering = "optimizeQuality"; else this._nativeElement.style.imageRendering = "optimizeSpeed";
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.ImageDOMElement.prototype.__class__ = cocktailCore.domElement.js.ImageDOMElement;
cocktailCore.domElement.abstract.AbstractContainerDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
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
for(var k in cocktailCore.domElement.js.DOMElement.prototype ) cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype[k] = cocktailCore.domElement.js.DOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._semantic = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.semantic = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._children = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.children = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype._textFragmentDOMElements = null;
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.initStyle = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::initStyle");
	var $spos = $s.length;
	this._style = new cocktailCore.style.js.ContainerStyle(this);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild = function(domElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addChild");
	var $spos = $s.length;
	domElement.setParent(this);
	this._children.push({ child : domElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.domElement});
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild = function(domElement) {
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
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText = function(textElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addText");
	var $spos = $s.length;
	this._children.push({ child : textElement, type : cocktailCore.domElement.ContainerDOMElementChildValue.textElement});
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText = function(textElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::removeText");
	var $spos = $s.length;
	var newChildrenArray = new Array();
	var _g1 = 0, _g = this._children.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this._children[i].child != textElement) newChildrenArray.push(this._children[i]);
	}
	this._children = newChildrenArray;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.getChildren = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::getChildren");
	var $spos = $s.length;
	var $tmp = this._children;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.resetTextFragments = function() {
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
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addTextFragment = function(textFragmentDOMElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::addTextFragment");
	var $spos = $s.length;
	this._textFragmentDOMElements.push(textFragmentDOMElement);
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeTextFragment = function(textFragmentDOMElement) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::removeTextFragment");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.setSemantic = function(semantic) {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::setSemantic");
	var $spos = $s.length;
	this._semantic = semantic;
	var $tmp = this._semantic;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.getSemantic = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractContainerDOMElement::getSemantic");
	var $spos = $s.length;
	var $tmp = this._semantic;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
cocktailCore.domElement.js.ContainerDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.__name__ = ["cocktailCore","domElement","js","ContainerDOMElement"];
cocktailCore.domElement.js.ContainerDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractContainerDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype ) cocktailCore.domElement.js.ContainerDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype[k];
cocktailCore.domElement.js.ContainerDOMElement.prototype.addChild = function(domElement) {
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::addChild");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addChild.call(this,domElement);
	this._nativeElement.appendChild(domElement.getNativeElement());
	domElement.getNativeElement().style.zIndex = this._children.length - 1;
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.removeChild = function(domElement) {
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::removeChild");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeChild.call(this,domElement);
	this._nativeElement.removeChild(domElement.getNativeElement());
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.addText = function(textElement) {
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::addText");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.addText.call(this,textElement);
	this.getNativeElement().appendChild(textElement.getText());
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.removeText = function(textElement) {
	$s.push("cocktailCore.domElement.js.ContainerDOMElement::removeText");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractContainerDOMElement.prototype.removeText.call(this,textElement);
	this._nativeElement.removeChild(textElement.getText());
	$s.pop();
}
cocktailCore.domElement.js.ContainerDOMElement.prototype.setSemantic = function(semantic) {
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
cocktailCore.domElement.js.ContainerDOMElement.prototype.__class__ = cocktailCore.domElement.js.ContainerDOMElement;
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
if(!cocktailCore.unit) cocktailCore.unit = {}
cocktailCore.unit.UnitManager = function(p) {
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
cocktailCore.unit.UnitManager.getColorFromColorValue = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getColorFromColorValue");
	var $spos = $s.length;
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
	$s.pop();
	return color;
	$s.pop();
}
cocktailCore.unit.UnitManager.getColorFromColorValueKeyword = function(value) {
	$s.push("cocktailCore.unit.UnitManager::getColorFromColorValueKeyword");
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
	var $tmp = cocktailCore.unit.UnitManager.getColorFromColorValue(cocktail.unit.ColorValue.hex(hexColor));
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
cocktailCore.unit.UnitManager.prototype.__class__ = cocktailCore.unit.UnitManager;
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement = function(nativeElement,style) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.DOMElement.call(this,nativeElement);
	this._style = style;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__name__ = ["cocktailCore","domElement","abstract","AbstractTextFragmentDOMElement"];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.__super__ = cocktailCore.domElement.js.DOMElement;
for(var k in cocktailCore.domElement.js.DOMElement.prototype ) cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype[k] = cocktailCore.domElement.js.DOMElement.prototype[k];
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype.initStyle = function() {
	$s.push("cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement::initStyle");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype.__class__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
cocktailCore.domElement.js.TextFragmentDOMElement = function(nativeElement,style) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.TextFragmentDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.call(this,nativeElement,style);
	$s.pop();
}
cocktailCore.domElement.js.TextFragmentDOMElement.__name__ = ["cocktailCore","domElement","js","TextFragmentDOMElement"];
cocktailCore.domElement.js.TextFragmentDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype ) cocktailCore.domElement.js.TextFragmentDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement.prototype[k];
cocktailCore.domElement.js.TextFragmentDOMElement.prototype.__class__ = cocktailCore.domElement.js.TextFragmentDOMElement;
if(!cocktailCore.resource) cocktailCore.resource = {}
if(!cocktailCore.resource["abstract"]) cocktailCore.resource["abstract"] = {}
cocktailCore.resource.abstract.AbstractResourceLoader = function(p) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.__name__ = ["cocktailCore","resource","abstract","AbstractResourceLoader"];
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadCompleteCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._onLoadErrorCallback = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype._domElement = null;
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.load = function(url,onLoadComplete,onLoadError,domElement,allowCache) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::load");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	this._onLoadCompleteCallback = onLoadComplete;
	this._onLoadErrorCallback = onLoadError;
	this._domElement = domElement;
	if(allowCache == false) url = this.disableUrlCaching(url);
	this.doLoad(url);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.doLoad = function(url) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::doLoad");
	var $spos = $s.length;
	var fileRequest = new haxe.Http(url);
	fileRequest.onData = $closure(this,"onLoadComplete");
	fileRequest.onError = $closure(this,"onLoadError");
	fileRequest.request(false);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.onLoadComplete = function(data) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::onLoadComplete");
	var $spos = $s.length;
	this._onLoadCompleteCallback(data);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.onLoadError = function(msg) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::onLoadError");
	var $spos = $s.length;
	this._onLoadErrorCallback(msg);
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.disableUrlCaching = function(url) {
	$s.push("cocktailCore.resource.abstract.AbstractResourceLoader::disableUrlCaching");
	var $spos = $s.length;
	var getId = "";
	if(url.indexOf("?") == -1) getId = "?"; else getId = "&";
	url += getId + "rand=" + Math.round(Math.random() * 10000);
	$s.pop();
	return url;
	$s.pop();
}
cocktailCore.resource.abstract.AbstractResourceLoader.prototype.__class__ = cocktailCore.resource.abstract.AbstractResourceLoader;
if(!cocktailCore.resource.js) cocktailCore.resource.js = {}
cocktailCore.resource.js.ContainerLoader = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.resource.js.ContainerLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.ContainerLoader.__name__ = ["cocktailCore","resource","js","ContainerLoader"];
cocktailCore.resource.js.ContainerLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.ContainerLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.ContainerLoader.prototype.onLoadComplete = function(data) {
	$s.push("cocktailCore.resource.js.ContainerLoader::onLoadComplete");
	var $spos = $s.length;
	var domElement = new cocktailCore.domElement.js.ContainerDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.neutral));
	domElement.getNativeElement().innerHTML = data;
	this._onLoadCompleteCallback(domElement);
	$s.pop();
}
cocktailCore.resource.js.ContainerLoader.prototype.__class__ = cocktailCore.resource.js.ContainerLoader;
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
if(!cocktailCore.keyboard.js) cocktailCore.keyboard.js = {}
cocktailCore.keyboard.js.Keyboard = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.keyboard.js.Keyboard::new");
	var $spos = $s.length;
	cocktailCore.keyboard.abstract.AbstractKeyboard.call(this);
	$s.pop();
}
cocktailCore.keyboard.js.Keyboard.__name__ = ["cocktailCore","keyboard","js","Keyboard"];
cocktailCore.keyboard.js.Keyboard.__super__ = cocktailCore.keyboard.abstract.AbstractKeyboard;
for(var k in cocktailCore.keyboard.abstract.AbstractKeyboard.prototype ) cocktailCore.keyboard.js.Keyboard.prototype[k] = cocktailCore.keyboard.abstract.AbstractKeyboard.prototype[k];
cocktailCore.keyboard.js.Keyboard.prototype.setNativeKeyboardListeners = function() {
	$s.push("cocktailCore.keyboard.js.Keyboard::setNativeKeyboardListeners");
	var $spos = $s.length;
	js.Lib.document.addEventListener("keydown",$closure(this,"onNativeKeyDown"));
	js.Lib.document.addEventListener("keyup",$closure(this,"onNativeKeyUp"));
	$s.pop();
}
cocktailCore.keyboard.js.Keyboard.prototype.unsetNativeKeyboardListeners = function() {
	$s.push("cocktailCore.keyboard.js.Keyboard::unsetNativeKeyboardListeners");
	var $spos = $s.length;
	js.Lib.document.removeEventListener("keydown",$closure(this,"onNativeKeyDown"));
	js.Lib.document.removeEventListener("keyup",$closure(this,"onNativeKeyUp"));
	$s.pop();
}
cocktailCore.keyboard.js.Keyboard.prototype.getKeyData = function(event) {
	$s.push("cocktailCore.keyboard.js.Keyboard::getKeyData");
	var $spos = $s.length;
	var key = { value : this.getKeyValue(event.keyCode), code : event.keyCode, ascii : event.charCode, altKey : event.altKey, controlKey : event.ctrlKey, shiftKey : event.shiftKey};
	$s.pop();
	return key;
	$s.pop();
}
cocktailCore.keyboard.js.Keyboard.prototype.__class__ = cocktailCore.keyboard.js.Keyboard;
if(!cocktailCore.textElement.js) cocktailCore.textElement.js = {}
cocktailCore.textElement.js.TextElement = function(text) {
	if( text === $_ ) return;
	$s.push("cocktailCore.textElement.js.TextElement::new");
	var $spos = $s.length;
	cocktailCore.textElement.abstract.AbstractTextElement.call(this,text);
	this._text = js.Lib.document.createTextNode(text);
	$s.pop();
}
cocktailCore.textElement.js.TextElement.__name__ = ["cocktailCore","textElement","js","TextElement"];
cocktailCore.textElement.js.TextElement.__super__ = cocktailCore.textElement.abstract.AbstractTextElement;
for(var k in cocktailCore.textElement.abstract.AbstractTextElement.prototype ) cocktailCore.textElement.js.TextElement.prototype[k] = cocktailCore.textElement.abstract.AbstractTextElement.prototype[k];
cocktailCore.textElement.js.TextElement.prototype.__class__ = cocktailCore.textElement.js.TextElement;
cocktailCore.resource.js.StringLoader = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.resource.js.StringLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.StringLoader.__name__ = ["cocktailCore","resource","js","StringLoader"];
cocktailCore.resource.js.StringLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.StringLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.StringLoader.prototype.__class__ = cocktailCore.resource.js.StringLoader;
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoWidth");
	var $spos = $s.length;
	var ret = 0;
	var embeddedDOMElement = style.getDOMElement();
	if(style.getHeight() == cocktail.style.DimensionStyleValue.auto) {
		if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else if(embeddedDOMElement.getIntrinsicHeight() != null && embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(embeddedDOMElement.getIntrinsicHeight() * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicRatio() != null) ret = 0;
	} else {
		var computedHeight = this.getComputedDimension(style.getHeight(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedHeight * embeddedDOMElement.getIntrinsicRatio()); else if(embeddedDOMElement.getIntrinsicWidth() != null) ret = embeddedDOMElement.getIntrinsicWidth(); else ret = 0;
	}
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoHeight");
	var $spos = $s.length;
	var embeddedDOMElement = style.getDOMElement();
	var ret = 0;
	if(style.getWidth() == cocktail.style.DimensionStyleValue.auto) {
		if(embeddedDOMElement.getIntrinsicHeight() != null) ret = embeddedDOMElement.getIntrinsicHeight();
	} else {
		var computedWidth = this.getComputedDimension(style.getWidth(),containingDOMElementData.height,containingDOMElementData.isHeightAuto,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
		if(embeddedDOMElement.getIntrinsicRatio() != null) ret = Math.round(computedWidth * embeddedDOMElement.getIntrinsicRatio()); else {
		}
	}
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	var computedMargin;
	if(isHorizontalMargin == false) computedMargin = 0; else computedMargin = cocktailCore.style.computer.BoxStylesComputer.prototype.getComputedAutoMargin.call(this,marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
	$s.pop();
	return computedMargin;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedFloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
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
haxe.Timer = function(time_ms) {
	if( time_ms === $_ ) return;
	$s.push("haxe.Timer::new");
	var $spos = $s.length;
	this.id = haxe.Timer.arr.length;
	haxe.Timer.arr[this.id] = this;
	this.timerId = window.setInterval("haxe.Timer.arr[" + this.id + "].run();",time_ms);
	$s.pop();
}
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.delay = function(f,time_ms) {
	$s.push("haxe.Timer::delay");
	var $spos = $s.length;
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		$s.push("haxe.Timer::delay@78");
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
	haxe.Timer.arr[this.id] = null;
	if(this.id > 100 && this.id == haxe.Timer.arr.length - 1) {
		var p = this.id - 1;
		while(p >= 0 && haxe.Timer.arr[p] == null) p--;
		haxe.Timer.arr = haxe.Timer.arr.slice(0,p + 1);
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
components.richList.StyleNormal = function() { }
components.richList.StyleNormal.__name__ = ["components","richList","StyleNormal"];
components.richList.StyleNormal.getDefaultStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getDefaultStyle");
	var $spos = $s.length;
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
	domElement.getStyle().setColor(cocktail.unit.ColorValue.keyword(cocktail.unit.ColorKeywordValue.black));
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.auto);
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.auto);
	domElement.getStyle().setFloat(cocktail.style.FloatStyleValue.none);
	domElement.getStyle().setClear(cocktail.style.ClearStyleValue.none);
	$s.pop();
}
components.richList.StyleNormal.getCellStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellStyle");
	var $spos = $s.length;
	components.richList.StyleNormal.getDefaultStyle(domElement);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("666666"));
	$s.pop();
}
components.richList.StyleNormal.getCellImageStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellImageStyle");
	var $spos = $s.length;
	components.richList.StyleNormal.getDefaultStyle(domElement);
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setFloat(cocktail.style.FloatStyleValue.right);
	$s.pop();
}
components.richList.StyleNormal.getCellMouseOverStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellMouseOverStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("333333"));
	$s.pop();
}
components.richList.StyleNormal.getCellMouseOutStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellMouseOutStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("666666"));
	$s.pop();
}
components.richList.StyleNormal.getCellMouseDownStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellMouseDownStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("000000"));
	$s.pop();
}
components.richList.StyleNormal.getCellMouseUpStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellMouseUpStyle");
	var $spos = $s.length;
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("333333"));
	$s.pop();
}
components.richList.StyleNormal.getCellLineStyle = function(domElement) {
	$s.push("components.richList.StyleNormal::getCellLineStyle");
	var $spos = $s.length;
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.length(cocktail.unit.LengthValue.px(1)));
	$s.pop();
}
components.richList.StyleNormal.createLine = function(color) {
	$s.push("components.richList.StyleNormal::createLine");
	var $spos = $s.length;
	var line = Utils.getGraphic();
	components.richList.StyleNormal.getCellLineStyle(line);
	Utils.fillGraphic(line,color);
	$s.pop();
	return line;
	$s.pop();
}
components.richList.StyleNormal.addLineAgain = function(domElement) {
	$s.push("components.richList.StyleNormal::addLineAgain");
	var $spos = $s.length;
	var line;
	line = components.richList.StyleNormal.createLine(14540253);
	domElement.removeChild(line);
	domElement.addChild(line);
	$s.pop();
}
components.richList.StyleNormal.prototype.__class__ = components.richList.StyleNormal;
if(!cocktailCore.nativeElement) cocktailCore.nativeElement = {}
if(!cocktailCore.nativeElement["abstract"]) cocktailCore.nativeElement["abstract"] = {}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator = function(p) {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementCreator::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementCreator"];
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype.createNativeElement = function(nativeElementType) {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementCreator::createNativeElement");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype.__class__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
if(!cocktailCore.nativeElement.js) cocktailCore.nativeElement.js = {}
cocktailCore.nativeElement.js.NativeElementCreator = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.nativeElement.js.NativeElementCreator::new");
	var $spos = $s.length;
	cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.call(this);
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementCreator.__name__ = ["cocktailCore","nativeElement","js","NativeElementCreator"];
cocktailCore.nativeElement.js.NativeElementCreator.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;
for(var k in cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype ) cocktailCore.nativeElement.js.NativeElementCreator.prototype[k] = cocktailCore.nativeElement.abstract.AbstractNativeElementCreator.prototype[k];
cocktailCore.nativeElement.js.NativeElementCreator.prototype.createNativeElement = function(nativeElementType) {
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
	case 4:
		var name = $e[2];
		nativeElement = js.Lib.document.createElement(name);
		break;
	}
	$s.pop();
	return nativeElement;
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementCreator.prototype.__class__ = cocktailCore.nativeElement.js.NativeElementCreator;
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedInlineBlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.__super__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
for(var k in cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","FloatBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.getComputedAutoWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::getComputedAutoWidth");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.shrinkToFit = function(computedStyles,availableWidth,minimumWidth) {
	$s.push("cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer::shrinkToFit");
	var $spos = $s.length;
	var shrinkedWidth;
	if(minimumWidth < availableWidth) shrinkedWidth = minimumWidth; else shrinkedWidth = availableWidth;
	$s.pop();
	return shrinkedWidth;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
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
	this.b[this.b.length] = x;
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
cocktailCore.style.abstract.AbstractEmbeddedStyle = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::new");
	var $spos = $s.length;
	cocktailCore.style.js.Style.call(this,domElement);
	$s.pop();
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.__name__ = ["cocktailCore","style","abstract","AbstractEmbeddedStyle"];
cocktailCore.style.abstract.AbstractEmbeddedStyle.__super__ = cocktailCore.style.js.Style;
for(var k in cocktailCore.style.js.Style.prototype ) cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype[k] = cocktailCore.style.js.Style.prototype[k];
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.applyComputedDimensions = function() {
	$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::applyComputedDimensions");
	var $spos = $s.length;
	cocktailCore.style.js.Style.prototype.applyComputedDimensions.call(this);
	var _g = this._domElement;
	_g.setX(_g.getX() + this._computedStyle.paddingLeft);
	var _g = this._domElement;
	_g.setY(_g.getY() + this._computedStyle.paddingTop);
	$s.pop();
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.getBoxStylesComputer = function() {
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
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.isEmbedded = function() {
	$s.push("cocktailCore.style.abstract.AbstractEmbeddedStyle::isEmbedded");
	var $spos = $s.length;
	$s.pop();
	return true;
	$s.pop();
}
cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype.__class__ = cocktailCore.style.abstract.AbstractEmbeddedStyle;
cocktailCore.style.js.EmbeddedStyle = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.js.EmbeddedStyle::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractEmbeddedStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.EmbeddedStyle.__name__ = ["cocktailCore","style","js","EmbeddedStyle"];
cocktailCore.style.js.EmbeddedStyle.__super__ = cocktailCore.style.abstract.AbstractEmbeddedStyle;
for(var k in cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype ) cocktailCore.style.js.EmbeddedStyle.prototype[k] = cocktailCore.style.abstract.AbstractEmbeddedStyle.prototype[k];
cocktailCore.style.js.EmbeddedStyle.prototype.__class__ = cocktailCore.style.js.EmbeddedStyle;
if(!cocktailCore.style.floats) cocktailCore.style.floats = {}
cocktailCore.style.floats.FloatsManager = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.floats.FloatsManager::new");
	var $spos = $s.length;
	var floatsLeft = new Array();
	var floatsRight = new Array();
	this._floats = { left : floatsLeft, right : floatsRight};
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.__name__ = ["cocktailCore","style","floats","FloatsManager"];
cocktailCore.style.floats.FloatsManager.prototype._floats = null;
cocktailCore.style.floats.FloatsManager.prototype.floats = null;
cocktailCore.style.floats.FloatsManager.prototype.addFloats = function(parentFormattingContext) {
	$s.push("cocktailCore.style.floats.FloatsManager::addFloats");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.retrieveFloats = function(childrenFormattingContext) {
	$s.push("cocktailCore.style.floats.FloatsManager::retrieveFloats");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.globalTolocal = function(floatData,flowData) {
	$s.push("cocktailCore.style.floats.FloatsManager::globalTolocal");
	var $spos = $s.length;
	var floatY = floatData.y - flowData.y;
	var convertedFloatData = { x : floatData.x, y : floatY, width : floatData.width, height : floatData.height};
	$s.pop();
	return convertedFloatData;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.clearFloat = function(clear,flowData) {
	$s.push("cocktailCore.style.floats.FloatsManager::clearFloat");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.clearLeft = function(flowData) {
	$s.push("cocktailCore.style.floats.FloatsManager::clearLeft");
	var $spos = $s.length;
	var $tmp = this.doClearFloat(flowData,this._floats.left);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.clearRight = function(flowData) {
	$s.push("cocktailCore.style.floats.FloatsManager::clearRight");
	var $spos = $s.length;
	var $tmp = this.doClearFloat(flowData,this._floats.right);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.clearBoth = function(flowData) {
	$s.push("cocktailCore.style.floats.FloatsManager::clearBoth");
	var $spos = $s.length;
	var leftY = this.doClearFloat(flowData,this._floats.left);
	var rightY = this.doClearFloat(flowData,this._floats.right);
	if(leftY > rightY) {
		$s.pop();
		return leftY;
	} else {
		$s.pop();
		return rightY;
	}
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.doClearFloat = function(flowData,floats) {
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
		var $tmp = flowData.y;
		$s.pop();
		return $tmp;
	}
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.computeFloatData = function(domElement,flowData,containingBlockWidth) {
	$s.push("cocktailCore.style.floats.FloatsManager::computeFloatData");
	var $spos = $s.length;
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
	$s.pop();
	return ret;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.getLeftFloatData = function(domElement,flowData,containingBlockWidth) {
	$s.push("cocktailCore.style.floats.FloatsManager::getLeftFloatData");
	var $spos = $s.length;
	var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
	floatData.x = flowData.xOffset + this.getLeftFloatOffset(floatData.y);
	$s.pop();
	return floatData;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.getRightFloatData = function(domElement,flowData,containingBlockWidth) {
	$s.push("cocktailCore.style.floats.FloatsManager::getRightFloatData");
	var $spos = $s.length;
	var floatData = this.getFloatData(domElement,flowData,containingBlockWidth);
	floatData.x = containingBlockWidth - floatData.width - this.getRightFloatOffset(floatData.y,containingBlockWidth) + flowData.xOffset;
	$s.pop();
	return floatData;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.getFloatData = function(domElement,flowData,containingBlockWidth) {
	$s.push("cocktailCore.style.floats.FloatsManager::getFloatData");
	var $spos = $s.length;
	var floatWidth = domElement.getOffsetWidth();
	var floatHeight = domElement.getOffsetHeight();
	var floatY = this.getFirstAvailableY(flowData,floatWidth,containingBlockWidth);
	var floatX = 0;
	var $tmp = { x : floatX, y : floatY, width : floatWidth, height : floatHeight};
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.getFirstAvailableY = function(flowData,elementWidth,containingBlockWidth) {
	$s.push("cocktailCore.style.floats.FloatsManager::getFirstAvailableY");
	var $spos = $s.length;
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
	$s.pop();
	return retY;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.removeFloats = function(flowY) {
	$s.push("cocktailCore.style.floats.FloatsManager::removeFloats");
	var $spos = $s.length;
	this._floats.left = this.doRemoveFloat(this._floats.left,flowY);
	this._floats.right = this.doRemoveFloat(this._floats.right,flowY);
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.doRemoveFloat = function(floats,flowY) {
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
cocktailCore.style.floats.FloatsManager.prototype.getRightFloatOffset = function(y,containingWidth) {
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
cocktailCore.style.floats.FloatsManager.prototype.getLeftFloatOffset = function(y) {
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
cocktailCore.style.floats.FloatsManager.prototype.getFloats = function() {
	$s.push("cocktailCore.style.floats.FloatsManager::getFloats");
	var $spos = $s.length;
	var $tmp = this._floats;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.floats.FloatsManager.prototype.__class__ = cocktailCore.style.floats.FloatsManager;
if(!cocktail.nativeElement) cocktail.nativeElement = {}
cocktail.nativeElement.NativeElementManager = function(p) {
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
cocktail.nativeElement.NativeElementManager.prototype.__class__ = cocktail.nativeElement.NativeElementManager;
cocktailCore.domElement.js.GraphicDOMElement = function(nativeElement) {
	if( nativeElement === $_ ) return;
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::new");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.call(this,nativeElement);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.__name__ = ["cocktailCore","domElement","js","GraphicDOMElement"];
cocktailCore.domElement.js.GraphicDOMElement.__super__ = cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
for(var k in cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype ) cocktailCore.domElement.js.GraphicDOMElement.prototype[k] = cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype[k];
cocktailCore.domElement.js.GraphicDOMElement.prototype.setWidth = function(value) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::setWidth");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	var imageData = canvasContext.getImageData(0,0,this.getWidth(),this.getHeight());
	this._nativeElement.width = value;
	canvasContext.putImageData(imageData,0,0);
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getWidth = function() {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getWidth");
	var $spos = $s.length;
	var $tmp = Std.parseInt(this._nativeElement.width);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.setHeight = function(value) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::setHeight");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	var imageData = canvasContext.getImageData(0,0,this.getWidth(),this.getHeight());
	this._nativeElement.height = value;
	canvasContext.putImageData(imageData,0,0);
	$s.pop();
	return value;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getHeight = function() {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getHeight");
	var $spos = $s.length;
	var $tmp = Std.parseInt(this._nativeElement.height);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.beginFill = function(fillStyle,lineStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::beginFill");
	var $spos = $s.length;
	cocktailCore.domElement.abstract.AbstractGraphicDOMElement.prototype.beginFill.call(this,fillStyle,lineStyle);
	if(fillStyle == null) fillStyle = cocktail.domElement.FillStyleValue.none;
	if(lineStyle == null) lineStyle = cocktail.domElement.LineStyleValue.none;
	this.setFillStyle(fillStyle);
	this.setLineStyle(lineStyle);
	var canvasContext = this.getContext();
	canvasContext.beginPath();
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.endFill = function() {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::endFill");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.closePath();
	canvasContext.fill();
	canvasContext.stroke();
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.clear = function() {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::clear");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.clearRect(0,0,this.getWidth(),this.getHeight());
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.setFillStyle = function(fillStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::setFillStyle");
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.setLineStyle = function(lineStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::setLineStyle");
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.drawImage = function(source,destinationPoint,sourceRect) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::drawImage");
	var $spos = $s.length;
	if(destinationPoint == null) destinationPoint = { x : 0.0, y : 0.0};
	if(sourceRect == null) {
		var width = source.getWidth();
		var height = source.getHeight();
		sourceRect = { x : 0.0, y : 0.0, width : width, height : height};
	}
	var canvasContext = this.getContext();
	canvasContext.drawImage(source.getNativeElement(),sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height,destinationPoint.x,destinationPoint.y,sourceRect.width,sourceRect.height);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.lineTo = function(x,y) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::lineTo");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.lineTo(x,y);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.moveTo = function(x,y) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::moveTo");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.moveTo(x,y);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.curveTo = function(controlX,controlY,x,y) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::curveTo");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.quadraticCurveTo(controlX,controlY,x,y);
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeAlpha = function(genericAlpha) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::toNativeAlpha");
	var $spos = $s.length;
	var $tmp = genericAlpha * 0.01;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeRatio = function(genericRatio) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::toNativeRatio");
	var $spos = $s.length;
	var $tmp = genericRatio * 0.01;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeCapStyle = function(genericCapStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::toNativeCapStyle");
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.toNativeJointStyle = function(genericJointStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::toNativeJointStyle");
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.colorStopToRGBA = function(colorStop) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::colorStopToRGBA");
	var $spos = $s.length;
	var rgb = this.hexToRGB(this.getHexColor(colorStop.color));
	var $tmp = "rgba(" + rgb.red + "," + rgb.green + "," + rgb.blue + "," + this.toNativeAlpha(colorStop.alpha) + ")";
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getHexColor = function(color) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getHexColor");
	var $spos = $s.length;
	var hexColor = StringTools.hex(color);
	while(hexColor.length < 6) hexColor = "0" + hexColor;
	var $tmp = "#" + hexColor;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.hexToRGB = function(hex) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::hexToRGB");
	var $spos = $s.length;
	var hexCopy = hex;
	var hexCopy1 = hexCopy.substr(1);
	var rgb = { red : Std.parseInt("0x" + hexCopy1.substr(0,2)), green : Std.parseInt("0x" + hexCopy1.substr(2,2)), blue : Std.parseInt("0x" + hexCopy1.substr(4,2))};
	$s.pop();
	return rgb;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.initLineStyle = function(lineStyleData) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::initLineStyle");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	canvasContext.lineWidth = lineStyleData.thickness;
	canvasContext.lineCap = this.toNativeCapStyle(lineStyleData.capStyle);
	canvasContext.lineJoin = this.toNativeJointStyle(lineStyleData.jointStyle);
	canvasContext.miterLimit = lineStyleData.miterLimit;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getContext = function() {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getContext");
	var $spos = $s.length;
	var $tmp = this._nativeElement.getContext("2d");
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getCanvasPattern = function(imageDOMElement,repeat) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getCanvasPattern");
	var $spos = $s.length;
	var canvasContext = this.getContext();
	var repeatValue = "";
	if(repeat == true) repeatValue = "repeat"; else repeatValue = "no-repeat";
	var $tmp = canvasContext.createPattern(imageDOMElement.getNativeElement(),repeatValue);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.domElement.js.GraphicDOMElement.prototype.getGradient = function(gradientStyle) {
	$s.push("cocktailCore.domElement.js.GraphicDOMElement::getGradient");
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
cocktailCore.domElement.js.GraphicDOMElement.prototype.__class__ = cocktailCore.domElement.js.GraphicDOMElement;
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
components.richList.RichList = function(richListModel,listStyle) {
	if( richListModel === $_ ) return;
	$s.push("components.richList.RichList::new");
	var $spos = $s.length;
	cocktailCore.domElement.js.ContainerDOMElement.call(this);
	this.createRichListDOM(richListModel,listStyle);
	listStyle.list(this);
	$s.pop();
}
components.richList.RichList.__name__ = ["components","richList","RichList"];
components.richList.RichList.__super__ = cocktailCore.domElement.js.ContainerDOMElement;
for(var k in cocktailCore.domElement.js.ContainerDOMElement.prototype ) components.richList.RichList.prototype[k] = cocktailCore.domElement.js.ContainerDOMElement.prototype[k];
components.richList.RichList.prototype.onChange = null;
components.richList.RichList.prototype.createRichListDOM = function(richListModel,listStyle) {
	$s.push("components.richList.RichList::createRichListDOM");
	var $spos = $s.length;
	var content = Utils.getContainer();
	var cellData;
	var _g = 0, _g1 = richListModel.content;
	while(_g < _g1.length) {
		var cellData1 = [_g1[_g]];
		++_g;
		var cell = [Utils.getContainer()];
		var cellImage = new cocktailCore.domElement.js.ImageDOMElement();
		var onPictureLoadedDelegate = [$closure(this,"onPictureLoaded")];
		cocktail.resource.ResourceLoaderManager.loadImage(cellData1[0].imagePath,(function(onPictureLoadedDelegate,cell,cellData1) {
			$s.push("components.richList.RichList::createRichListDOM@85");
			var $spos = $s.length;
			var $tmp = function(cellImage1) {
				$s.push("components.richList.RichList::createRichListDOM@85@85");
				var $spos = $s.length;
				onPictureLoadedDelegate[0](cellImage1,cell[0],listStyle,cellData1[0]);
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(onPictureLoadedDelegate,cell,cellData1),$closure(this,"onPictureLoadError"),cellImage);
		this.addChild(cell[0]);
		var onCellMouseOverDelegate = [$closure(this,"onCellMouseOver")];
		cell[0].setOnMouseOver((function(onCellMouseOverDelegate,cell) {
			$s.push("components.richList.RichList::createRichListDOM@94");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("components.richList.RichList::createRichListDOM@94@94");
				var $spos = $s.length;
				onCellMouseOverDelegate[0](mouseEventData,cell[0],listStyle);
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(onCellMouseOverDelegate,cell));
		var onCellMouseOutDelegate = [$closure(this,"onCellMouseOut")];
		cell[0].setOnMouseOut((function(onCellMouseOutDelegate,cell) {
			$s.push("components.richList.RichList::createRichListDOM@97");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("components.richList.RichList::createRichListDOM@97@97");
				var $spos = $s.length;
				onCellMouseOutDelegate[0](mouseEventData,cell[0],listStyle);
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(onCellMouseOutDelegate,cell));
		var onCellMouseDownDelegate = [$closure(this,"onCellMouseDown")];
		cell[0].setOnMouseDown((function(onCellMouseDownDelegate,cell) {
			$s.push("components.richList.RichList::createRichListDOM@100");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("components.richList.RichList::createRichListDOM@100@100");
				var $spos = $s.length;
				onCellMouseDownDelegate[0](mouseEventData,cell[0],listStyle);
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(onCellMouseDownDelegate,cell));
		var onCellMouseUpDelegate = [$closure(this,"onCellMouseUp")];
		cell[0].setOnMouseUp((function(onCellMouseUpDelegate,cell,cellData1) {
			$s.push("components.richList.RichList::createRichListDOM@103");
			var $spos = $s.length;
			var $tmp = function(mouseEventData) {
				$s.push("components.richList.RichList::createRichListDOM@103@103");
				var $spos = $s.length;
				onCellMouseUpDelegate[0](mouseEventData,cell[0],listStyle,cellData1[0]);
				$s.pop();
			};
			$s.pop();
			return $tmp;
			$s.pop();
		})(onCellMouseUpDelegate,cell,cellData1));
	}
	$s.pop();
}
components.richList.RichList.prototype.onPictureLoaded = function(domElement,cell,listStyle,cellData) {
	$s.push("components.richList.RichList::onPictureLoaded");
	var $spos = $s.length;
	listStyle.cell(cell);
	listStyle.cellImage(domElement);
	cell.addChild(domElement);
	cell.addText(new cocktailCore.textElement.js.TextElement(cellData.text));
	listStyle.cell(cell);
	$s.pop();
}
components.richList.RichList.prototype.onPictureLoadError = function(error) {
	$s.push("components.richList.RichList::onPictureLoadError");
	var $spos = $s.length;
	haxe.Log.trace(error,{ fileName : "RichList.hx", lineNumber : 140, className : "components.richList.RichList", methodName : "onPictureLoadError"});
	$s.pop();
}
components.richList.RichList.prototype.onCellMouseOver = function(mouseEventData,cell,listStyle) {
	$s.push("components.richList.RichList::onCellMouseOver");
	var $spos = $s.length;
	listStyle.cellMouseOver(cell);
	$s.pop();
}
components.richList.RichList.prototype.onCellMouseOut = function(mouseEventData,cell,listStyle) {
	$s.push("components.richList.RichList::onCellMouseOut");
	var $spos = $s.length;
	listStyle.cellMouseOut(cell);
	$s.pop();
}
components.richList.RichList.prototype.onCellMouseDown = function(mouseEventData,cell,listStyle) {
	$s.push("components.richList.RichList::onCellMouseDown");
	var $spos = $s.length;
	listStyle.cellMouseDown(cell);
	$s.pop();
}
components.richList.RichList.prototype.onCellMouseUp = function(mouseEventData,cell,listStyle,cellData) {
	$s.push("components.richList.RichList::onCellMouseUp");
	var $spos = $s.length;
	listStyle.cellMouseUp(cell);
	if(this.onChange != null) this.onChange(cellData);
	$s.pop();
}
components.richList.RichList.prototype.__class__ = components.richList.RichList;
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
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","InLineBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedAutoMargin = function(marginStyleValue,opositeMarginStyleValue,containingDOMElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin) {
	$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedAutoMargin");
	var $spos = $s.length;
	if(isHorizontalMargin == null) isHorizontalMargin = false;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedWidth = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedWidth");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.getComputedHeight = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer::getComputedHeight");
	var $spos = $s.length;
	$s.pop();
	return 0;
	$s.pop();
}
cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
cocktailCore.resource.js.ImageLoader = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.resource.js.ImageLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.ImageLoader.__name__ = ["cocktailCore","resource","js","ImageLoader"];
cocktailCore.resource.js.ImageLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.ImageLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.ImageLoader.prototype.doLoad = function(url) {
	$s.push("cocktailCore.resource.js.ImageLoader::doLoad");
	var $spos = $s.length;
	var domElement;
	if(this._domElement != null) {
		domElement = this._domElement;
		domElement.setNativeElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	} else domElement = new cocktailCore.domElement.js.ImageDOMElement(cocktail.nativeElement.NativeElementManager.createNativeElement(cocktail.nativeElement.NativeElementTypeValue.image));
	var onLoadCompleteDelegate = $closure(this,"onLoadComplete");
	var onLoadErrorDelegate = $closure(this,"onLoadError");
	domElement.getNativeElement().onload = function() {
		$s.push("cocktailCore.resource.js.ImageLoader::doLoad@73");
		var $spos = $s.length;
		domElement.setWidth(this.width);
		domElement.setHeight(this.height);
		domElement.setSrc(this.src);
		onLoadCompleteDelegate(domElement);
		$s.pop();
	};
	domElement.getNativeElement().onerror = function() {
		$s.push("cocktailCore.resource.js.ImageLoader::doLoad@83");
		var $spos = $s.length;
		onLoadErrorDelegate("couldn't load picture");
		$s.pop();
	};
	domElement.getNativeElement().setAttribute("src",url);
	$s.pop();
}
cocktailCore.resource.js.ImageLoader.prototype.__class__ = cocktailCore.resource.js.ImageLoader;
cocktailCore.style.computer.DisplayStylesComputer = function(p) {
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
	computedStyle["float"] = cocktailCore.style.computer.DisplayStylesComputer.getComputedFloat(style,computedStyle.position);
	computedStyle.display = cocktailCore.style.computer.DisplayStylesComputer.getComputedDisplay(style,computedStyle["float"]);
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
	if(computedPosition == cocktail.style.PositionStyleValue.absolute || computedPosition == cocktail.style.PositionStyleValue.fixed) ret = cocktail.style.FloatStyleValue.none; else ret = style.getFloat();
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
cocktailCore.style.computer.DisplayStylesComputer.prototype.__class__ = cocktailCore.style.computer.DisplayStylesComputer;
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
if(!cocktail.resource) cocktail.resource = {}
cocktail.resource.ResourceLoaderManager = function(p) {
	$s.push("cocktail.resource.ResourceLoaderManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.__name__ = ["cocktail","resource","ResourceLoaderManager"];
cocktail.resource.ResourceLoaderManager._resourceDataArray = null;
cocktail.resource.ResourceLoaderManager.loadImage = function(url,successCallback,errorCallback,imageDOMElement,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadImage");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, domElement : imageDOMElement, allowCache : allowCache, loadingType : cocktail.resource.LoadingTypeValue.image};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.loadContainer = function(url,successCallback,errorCallback,containerDOMElement,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadContainer");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, domElement : containerDOMElement, loadingType : cocktail.resource.LoadingTypeValue.container};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.loadString = function(url,successCallback,errorCallback,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadString");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, domElement : null, loadingType : cocktail.resource.LoadingTypeValue.data};
	cocktail.resource.ResourceLoaderManager.addResourceData(resourceDataToAdd);
	$s.pop();
}
cocktail.resource.ResourceLoaderManager.loadLibrary = function(url,successCallback,errorCallback,allowCache) {
	$s.push("cocktail.resource.ResourceLoaderManager::loadLibrary");
	var $spos = $s.length;
	if(allowCache == null) allowCache = true;
	var resourceDataToAdd = { url : url, onLoadComplete : successCallback, onLoadError : errorCallback, allowCache : allowCache, domElement : null, loadingType : cocktail.resource.LoadingTypeValue.library};
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
			resourceLoader = new cocktailCore.resource.js.ImageLoader();
			break;
		case 2:
			resourceLoader = new cocktailCore.resource.js.ContainerLoader();
			break;
		case 3:
			resourceLoader = new cocktailCore.resource.js.LibraryLoader();
			break;
		}
		resourceLoader.load(resourceDataToLoad.url,cocktail.resource.ResourceLoaderManager.onLoadComplete,cocktail.resource.ResourceLoaderManager.onLoadError,resourceDataToLoad.domElement,resourceDataToLoad.allowCache);
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
cocktail.resource.ResourceLoaderManager.prototype.__class__ = cocktail.resource.ResourceLoaderManager;
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","EmbeddedPositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
cocktailCore.style.computer.FontAndTextStylesComputer = function(p) {
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
cocktailCore.style.computer.FontAndTextStylesComputer.getComputedVerticalAlign = function(style,containingDOMElementFontMetricsData) {
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
	var $tmp = cocktailCore.unit.UnitManager.getColorFromColorValue(style.getColor());
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
		wordSpacing = Math.round(cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight));
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
		lineHeight = cocktailCore.unit.UnitManager.getPixelFromLengthValue(unit,style.getFontMetricsData().fontSize,style.getFontMetricsData().xHeight);
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
cocktailCore.style.computer.FontAndTextStylesComputer.prototype.__class__ = cocktailCore.style.computer.FontAndTextStylesComputer;
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
	var $tmp = s.b.join("");
	$s.pop();
	return $tmp;
	$s.pop();
}
Hash.prototype.__class__ = Hash;
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
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","NoneBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
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
WebApp = function(p) {
	if( p === $_ ) return;
	$s.push("WebApp::new");
	var $spos = $s.length;
	js.Lib.window.onresize = $closure(this,"refresh");
	this.drawInterface();
	$s.pop();
}
WebApp.__name__ = ["WebApp"];
WebApp.rootDOMElement = null;
WebApp.main = function() {
	$s.push("WebApp::main");
	var $spos = $s.length;
	new WebApp();
	$s.pop();
}
WebApp.prototype._mainContainer = null;
WebApp.prototype._siteLeftFloatBackground = null;
WebApp.prototype.drawInterface = function() {
	$s.push("WebApp::drawInterface");
	var $spos = $s.length;
	var applicationStructure = new ApplicationStructure();
	this._mainContainer = applicationStructure.pagesContainer;
	WebAppStyle.getDefaultStyle(this._mainContainer);
	this.attach(this._mainContainer);
	this.refresh();
	$s.pop();
}
WebApp.prototype.refresh = function(event) {
	$s.push("WebApp::refresh");
	var $spos = $s.length;
	var browserWidth;
	var browserHeight;
	browserWidth = js.Lib.document.body.clientWidth;
	browserHeight = js.Lib.document.body.clientHeight;
	this._mainContainer.getStyle().getComputedStyle().lineHeight = 70;
	this._mainContainer.getStyle().layout({ width : browserWidth, height : browserHeight, isWidthAuto : false, isHeightAuto : false, globalX : 0, globalY : 0},{ width : browserWidth, height : browserHeight, globalX : 0, globalY : 0, isWidthAuto : false, isHeightAuto : false},{ width : browserWidth, height : browserHeight, globalX : 0, globalY : 0, isWidthAuto : false, isHeightAuto : false},this._mainContainer.getStyle().getFontMetricsData());
	$s.pop();
}
WebApp.prototype.attach = function(domElement) {
	$s.push("WebApp::attach");
	var $spos = $s.length;
	js.Lib.document.body.appendChild(domElement.getNativeElement());
	js.Lib.document.body.style.margin = 0;
	$s.pop();
}
WebApp.prototype.__class__ = WebApp;
cocktail.resource.LoadingTypeValue = { __ename__ : ["cocktail","resource","LoadingTypeValue"], __constructs__ : ["data","image","container","library"] }
cocktail.resource.LoadingTypeValue.data = ["data",0];
cocktail.resource.LoadingTypeValue.data.toString = $estr;
cocktail.resource.LoadingTypeValue.data.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.image = ["image",1];
cocktail.resource.LoadingTypeValue.image.toString = $estr;
cocktail.resource.LoadingTypeValue.image.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.container = ["container",2];
cocktail.resource.LoadingTypeValue.container.toString = $estr;
cocktail.resource.LoadingTypeValue.container.__enum__ = cocktail.resource.LoadingTypeValue;
cocktail.resource.LoadingTypeValue.library = ["library",3];
cocktail.resource.LoadingTypeValue.library.toString = $estr;
cocktail.resource.LoadingTypeValue.library.__enum__ = cocktail.resource.LoadingTypeValue;
cocktailCore.style.positioner.RelativePositioner = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.positioner.RelativePositioner::new");
	var $spos = $s.length;
	cocktailCore.style.positioner.BoxPositioner.call(this);
	$s.pop();
}
cocktailCore.style.positioner.RelativePositioner.__name__ = ["cocktailCore","style","positioner","RelativePositioner"];
cocktailCore.style.positioner.RelativePositioner.__super__ = cocktailCore.style.positioner.BoxPositioner;
for(var k in cocktailCore.style.positioner.BoxPositioner.prototype ) cocktailCore.style.positioner.RelativePositioner.prototype[k] = cocktailCore.style.positioner.BoxPositioner.prototype[k];
cocktailCore.style.positioner.RelativePositioner.prototype.position = function(domElement,containingDOMElementData) {
	$s.push("cocktailCore.style.positioner.RelativePositioner::position");
	var $spos = $s.length;
	this.applyOffset(domElement,containingDOMElementData);
	$s.pop();
}
cocktailCore.style.positioner.RelativePositioner.prototype.applyOffset = function(domElement,containingDOMElementData) {
	$s.push("cocktailCore.style.positioner.RelativePositioner::applyOffset");
	var $spos = $s.length;
	if(domElement.getStyle().getLeft() != cocktail.style.PositionOffsetStyleValue.auto) domElement.setX(domElement.getStyle().getComputedStyle().left);
	if(domElement.getStyle().getTop() != cocktail.style.PositionOffsetStyleValue.auto) domElement.setY(domElement.getStyle().getComputedStyle().top);
	$s.pop();
}
cocktailCore.style.positioner.RelativePositioner.prototype.__class__ = cocktailCore.style.positioner.RelativePositioner;
WebAppStyle = function() { }
WebAppStyle.__name__ = ["WebAppStyle"];
WebAppStyle.getDefaultStyle = function(domElement) {
	$s.push("WebAppStyle::getDefaultStyle");
	var $spos = $s.length;
	var computedStyle = { width : 0, height : 0, minHeight : 0, maxHeight : 0, minWidth : 0, maxWidth : 0, marginLeft : 0, marginRight : 0, marginTop : 0, marginBottom : 0, paddingLeft : 0, paddingRight : 0, paddingTop : 0, paddingBottom : 0, left : 0, right : 0, top : 0, bottom : 0, clear : cocktail.style.ClearStyleValue.none, 'float' : cocktail.style.FloatStyleValue.none, display : cocktail.style.DisplayStyleValue.block, position : cocktail.style.PositionStyleValue.staticStyle, verticalAlign : 0.0, fontSize : 12.0, lineHeight : 14.0, fontWeight : cocktail.style.FontWeightStyleValue.normal, fontStyle : cocktail.style.FontStyleStyleValue.normal, fontFamily : [cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.serif)], fontVariant : cocktail.style.FontVariantStyleValue.normal, textTransform : cocktail.style.TextTransformStyleValue.none, letterSpacing : 0, wordSpacing : 0, textIndent : 0, whiteSpace : cocktail.style.WhiteSpaceStyleValue.normal, textAlign : cocktail.style.TextAlignStyleValue.left, color : 0};
	domElement.getStyle().setComputedStyle(computedStyle);
	$s.pop();
}
WebAppStyle.getMainContainerStyle = function(domElement) {
	$s.push("WebAppStyle::getMainContainerStyle");
	var $spos = $s.length;
	WebAppStyle.getDefaultStyle(domElement);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(0)));
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.staticStyle);
	$s.pop();
}
WebAppStyle.getPageContainerStyle = function(domElement) {
	$s.push("WebAppStyle::getPageContainerStyle");
	var $spos = $s.length;
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setLeft(cocktail.style.PositionOffsetStyleValue.auto);
	domElement.getStyle().setTop(cocktail.style.PositionOffsetStyleValue.auto);
	$s.pop();
}
WebAppStyle.getHomePageStyle = function(domElement) {
	$s.push("WebAppStyle::getHomePageStyle");
	var $spos = $s.length;
	$s.pop();
}
WebAppStyle.getPageStyle = function(domElement) {
	$s.push("WebAppStyle::getPageStyle");
	var $spos = $s.length;
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
WebAppStyle.getBgStyle = function(domElement) {
	$s.push("WebAppStyle::getBgStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
WebAppStyle.getHeaderStyle = function(domElement) {
	$s.push("WebAppStyle::getHeaderStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.relative);
	domElement.getStyle().setDisplay(cocktail.style.DisplayStyleValue.block);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("222222"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	$s.pop();
}
WebAppStyle.getBackButtonStyle = function(domElement) {
	$s.push("WebAppStyle::getBackButtonStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setFloat(cocktail.style.FloatStyleValue.left);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(14)));
	domElement.getStyle().setLineHeight(cocktail.style.LineHeightStyleValue.normal);
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(15)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(12)));
	$s.pop();
}
WebAppStyle.getHeaderTextStyle = function(domElement) {
	$s.push("WebAppStyle::getHeaderTextStyle");
	var $spos = $s.length;
	domElement.getStyle().setPosition(cocktail.style.PositionStyleValue.absolute);
	domElement.getStyle().setColor(cocktail.unit.ColorValue.hex("EEEEEE"));
	domElement.getStyle().setFontSize(cocktail.style.FontSizeStyleValue.length(cocktail.unit.LengthValue.px(20)));
	domElement.getStyle().setFontWeight(cocktail.style.FontWeightStyleValue.bold);
	domElement.getStyle().setFontStyle(cocktail.style.FontStyleStyleValue.normal);
	domElement.getStyle().setFontFamily([cocktail.style.FontFamilyStyleValue.familyName("Helvetica"),cocktail.style.FontFamilyStyleValue.genericFamily(cocktail.style.GenericFontFamilyValue.sansSerif)]);
	domElement.getStyle().setTextAlign(cocktail.style.TextAlignStyleValue.center);
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setVerticalAlign(cocktail.style.VerticalAlignStyleValue.middle);
	domElement.getStyle().setWidth(cocktail.style.DimensionStyleValue.percent(100));
	domElement.getStyle().setHeight(cocktail.style.DimensionStyleValue.percent(100));
	$s.pop();
}
WebAppStyle.getTextContentStyle = function(domElement) {
	$s.push("WebAppStyle::getTextContentStyle");
	var $spos = $s.length;
	domElement.getStyle().setPaddingBottom(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingLeft(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingTop(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	domElement.getStyle().setPaddingRight(cocktail.style.PaddingStyleValue.length(cocktail.unit.LengthValue.px(8)));
	$s.pop();
}
WebAppStyle.prototype.__class__ = WebAppStyle;
cocktailCore.resource.js.LibraryLoader = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.resource.js.LibraryLoader::new");
	var $spos = $s.length;
	cocktailCore.resource.abstract.AbstractResourceLoader.call(this);
	$s.pop();
}
cocktailCore.resource.js.LibraryLoader.__name__ = ["cocktailCore","resource","js","LibraryLoader"];
cocktailCore.resource.js.LibraryLoader.__super__ = cocktailCore.resource.abstract.AbstractResourceLoader;
for(var k in cocktailCore.resource.abstract.AbstractResourceLoader.prototype ) cocktailCore.resource.js.LibraryLoader.prototype[k] = cocktailCore.resource.abstract.AbstractResourceLoader.prototype[k];
cocktailCore.resource.js.LibraryLoader.prototype.doLoad = function(url) {
	$s.push("cocktailCore.resource.js.LibraryLoader::doLoad");
	var $spos = $s.length;
	var scrptE = js.Lib.document.createElement("script");
	scrptE.setAttribute("type","text/javascript");
	scrptE.setAttribute("language","JavaScript");
	scrptE.setAttribute("src",url);
	scrptE.onload = $closure(this,"onLoadComplete");
	scrptE.onerror = $closure(this,"onLoadError");
	js.Lib.document.getElementsByTagName("head")[0].appendChild(scrptE);
	$s.pop();
}
cocktailCore.resource.js.LibraryLoader.prototype.onLoadComplete = function(data) {
	$s.push("cocktailCore.resource.js.LibraryLoader::onLoadComplete");
	var $spos = $s.length;
	this._onLoadCompleteCallback(null);
	$s.pop();
}
cocktailCore.resource.js.LibraryLoader.prototype.__class__ = cocktailCore.resource.js.LibraryLoader;
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager = function(p) {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager::new");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.__name__ = ["cocktailCore","nativeElement","abstract","AbstractNativeElementPathManager"];
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype.getRoot = function() {
	$s.push("cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager::getRoot");
	var $spos = $s.length;
	$s.pop();
	return null;
	$s.pop();
}
cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype.__class__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
cocktailCore.nativeElement.js.NativeElementPathManager = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.nativeElement.js.NativeElementPathManager::new");
	var $spos = $s.length;
	cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.call(this);
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementPathManager.__name__ = ["cocktailCore","nativeElement","js","NativeElementPathManager"];
cocktailCore.nativeElement.js.NativeElementPathManager.__super__ = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
for(var k in cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype ) cocktailCore.nativeElement.js.NativeElementPathManager.prototype[k] = cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager.prototype[k];
cocktailCore.nativeElement.js.NativeElementPathManager.prototype.getRoot = function() {
	$s.push("cocktailCore.nativeElement.js.NativeElementPathManager::getRoot");
	var $spos = $s.length;
	var $tmp = js.Lib.document.body;
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.nativeElement.js.NativeElementPathManager.prototype.__class__ = cocktailCore.nativeElement.js.NativeElementPathManager;
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","BlockBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
cocktailCore.style.js.ContainerStyle = function(domElement) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.js.ContainerStyle::new");
	var $spos = $s.length;
	cocktailCore.style.abstract.AbstractContainerStyle.call(this,domElement);
	$s.pop();
}
cocktailCore.style.js.ContainerStyle.__name__ = ["cocktailCore","style","js","ContainerStyle"];
cocktailCore.style.js.ContainerStyle.__super__ = cocktailCore.style.abstract.AbstractContainerStyle;
for(var k in cocktailCore.style.abstract.AbstractContainerStyle.prototype ) cocktailCore.style.js.ContainerStyle.prototype[k] = cocktailCore.style.abstract.AbstractContainerStyle.prototype[k];
cocktailCore.style.js.ContainerStyle.prototype.layout = function(containingDOMElementData,lastPositionedDOMElement,rootDOMElement,containingDOMElementFontMetricsData) {
	$s.push("cocktailCore.style.js.ContainerStyle::layout");
	var $spos = $s.length;
	$s.pop();
}
cocktailCore.style.js.ContainerStyle.prototype.__class__ = cocktailCore.style.js.ContainerStyle;
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer = function(p) {
	if( p === $_ ) return;
	$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::new");
	var $spos = $s.length;
	cocktailCore.style.computer.BoxStylesComputer.call(this);
	$s.pop();
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__name__ = ["cocktailCore","style","computer","boxComputers","PositionedBoxStylesComputer"];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.__super__ = cocktailCore.style.computer.BoxStylesComputer;
for(var k in cocktailCore.style.computer.BoxStylesComputer.prototype ) cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype[k] = cocktailCore.style.computer.BoxStylesComputer.prototype[k];
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.measurePositionOffsets = function(style,containingDOMElementData) {
	$s.push("cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer::measurePositionOffsets");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer.prototype.__class__ = cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer;
cocktailCore.style.formatter.BlockFormattingContext = function(domElement,previousFormattingContext) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.formatter.BlockFormattingContext::new");
	var $spos = $s.length;
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
	$s.pop();
}
cocktailCore.style.formatter.BlockFormattingContext.__name__ = ["cocktailCore","style","formatter","BlockFormattingContext"];
cocktailCore.style.formatter.BlockFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
for(var k in cocktailCore.style.formatter.FormattingContext.prototype ) cocktailCore.style.formatter.BlockFormattingContext.prototype[k] = cocktailCore.style.formatter.FormattingContext.prototype[k];
cocktailCore.style.formatter.BlockFormattingContext.prototype.place = function(domElement) {
	$s.push("cocktailCore.style.formatter.BlockFormattingContext::place");
	var $spos = $s.length;
	cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement);
	var leftFloatOffset = 0;
	if(domElement.getStyle().isEmbedded() == true) {
		this._flowData.y = this._floatsManager.getFirstAvailableY(this.getFlowData(),domElement.getOffsetWidth(),this._containingDOMElementWidth);
		leftFloatOffset = this._floatsManager.getLeftFloatOffset(this._flowData.y + domElement.getStyle().getComputedStyle().marginTop);
	}
	this._flowData.x = this._flowData.xOffset + leftFloatOffset;
	domElement.setX(this._flowData.x + domElement.getStyle().getComputedStyle().marginLeft);
	if(this._flowData.x + domElement.getOffsetWidth() + domElement.getStyle().getComputedStyle().marginLeft > this._flowData.maxWidth) this._flowData.maxWidth = this._flowData.x + domElement.getOffsetWidth() + domElement.getStyle().getComputedStyle().marginLeft;
	domElement.setY(this._flowData.y + domElement.getStyle().getComputedStyle().marginTop);
	this._flowData.y += domElement.getOffsetHeight();
	this._flowData.totalHeight = this._flowData.y;
	$s.pop();
}
cocktailCore.style.formatter.BlockFormattingContext.prototype.placeFloat = function(domElement,floatData) {
	$s.push("cocktailCore.style.formatter.BlockFormattingContext::placeFloat");
	var $spos = $s.length;
	domElement.setX(floatData.x + domElement.getStyle().getComputedStyle().marginLeft);
	domElement.setY(floatData.y + domElement.getStyle().getComputedStyle().marginTop);
	this._flowData.y = floatData.y;
	$s.pop();
}
cocktailCore.style.formatter.BlockFormattingContext.prototype.clearFloat = function(clear,isFloat) {
	$s.push("cocktailCore.style.formatter.BlockFormattingContext::clearFloat");
	var $spos = $s.length;
	this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
	$s.pop();
}
cocktailCore.style.formatter.BlockFormattingContext.prototype.__class__ = cocktailCore.style.formatter.BlockFormattingContext;
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
cocktailCore.style.formatter.InlineFormattingContext = function(domElement,previousFormattingContext) {
	if( domElement === $_ ) return;
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::new");
	var $spos = $s.length;
	this._firstLineLaidOut = false;
	cocktailCore.style.formatter.FormattingContext.call(this,domElement,previousFormattingContext);
	this._domElementInLineBox = new Array();
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.__name__ = ["cocktailCore","style","formatter","InlineFormattingContext"];
cocktailCore.style.formatter.InlineFormattingContext.__super__ = cocktailCore.style.formatter.FormattingContext;
for(var k in cocktailCore.style.formatter.FormattingContext.prototype ) cocktailCore.style.formatter.InlineFormattingContext.prototype[k] = cocktailCore.style.formatter.FormattingContext.prototype[k];
cocktailCore.style.formatter.InlineFormattingContext.prototype._domElementInLineBox = null;
cocktailCore.style.formatter.InlineFormattingContext.prototype._firstLineLaidOut = null;
cocktailCore.style.formatter.InlineFormattingContext.prototype.destroy = function() {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::destroy");
	var $spos = $s.length;
	this.startNewLine(0,true);
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.insert = function(domElement) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::insert");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.insertSpace = function(domElement) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::insertSpace");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.place = function(domElement) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::place");
	var $spos = $s.length;
	cocktailCore.style.formatter.FormattingContext.prototype.place.call(this,domElement);
	this._flowData.x += domElement.getOffsetWidth();
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.startNewLine = function(domElementWidth,isLastLine) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::startNewLine");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.clearFloat = function(clear,isFloat) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::clearFloat");
	var $spos = $s.length;
	if(isFloat == true) this._flowData.y = this._floatsManager.clearFloat(clear,this._flowData);
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.placeFloat = function(domElement,floatData) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::placeFloat");
	var $spos = $s.length;
	domElement.setX(floatData.x + domElement.getStyle().getComputedStyle().marginLeft);
	domElement.setY(floatData.y + domElement.getStyle().getComputedStyle().marginTop);
	if(this._floatsManager.getLeftFloatOffset(this._flowData.y) > this._flowData.xOffset) this.getFlowData().x = this._floatsManager.getLeftFloatOffset(this._flowData.y); else this._flowData.x = this._flowData.xOffset;
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.removeSpaces = function() {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::removeSpaces");
	var $spos = $s.length;
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
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.alignText = function(firstLine,isLastLine) {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::alignText");
	var $spos = $s.length;
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
			this._domElementInLineBox[i].domElement.setX(localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 1:
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._domElementInLineBox[i].domElement.setX(localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft + remainingSpace);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 2:
		var _g1 = 0, _g = this._domElementInLineBox.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._domElementInLineBox[i].domElement.setX(Math.round(remainingSpace / 2) + localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
			localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
		}
		break;
	case 3:
		if(isLastLine == true) {
			var _g1 = 0, _g = this._domElementInLineBox.length;
			while(_g1 < _g) {
				var i = _g1++;
				this._domElementInLineBox[i].domElement.setX(localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
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
				this._domElementInLineBox[i].domElement.setX(localFlow + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginLeft);
				localFlow += this._domElementInLineBox[i].domElement.getOffsetWidth();
			}
		}
		break;
	}
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.computeLineBoxHeight = function() {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
	var $spos = $s.length;
	var lineBoxAscent = this._containingDOMElement.getStyle().getFontMetricsData().ascent;
	var lineBoxDescent = this._containingDOMElement.getStyle().getFontMetricsData().descent;
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
		}
		if(domElementAscent - domElementVerticalAlign > lineBoxAscent) lineBoxAscent = domElementAscent - domElementVerticalAlign;
		if(domElementDescent + domElementVerticalAlign > lineBoxDescent) lineBoxDescent = domElementDescent + domElementVerticalAlign;
	}
	var lineBoxHeight = lineBoxAscent + lineBoxDescent;
	var _g1 = 0, _g = this._domElementInLineBox.length;
	while(_g1 < _g) {
		var i = _g1++;
		this._domElementInLineBox[i].domElement.setY(Math.round(lineBoxAscent) + Math.round(this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().verticalAlign) + this._flowData.y + this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().marginTop);
		if(this._domElementInLineBox[i].domElement.getStyle().getComputedStyle().display == cocktail.style.DisplayStyleValue.inlineBlock) {
		}
		if(this._domElementInLineBox[i].domElement.getStyle().isEmbedded() == true || this._domElementInLineBox[i].domElement.getStyle().getDisplay() == cocktail.style.DisplayStyleValue.inlineBlock) {
			var _g2 = this._domElementInLineBox[i].domElement;
			_g2.setY(_g2.getY() - this._domElementInLineBox[i].domElement.getOffsetHeight());
		}
	}
	var $tmp = Math.round(lineBoxHeight);
	$s.pop();
	return $tmp;
	$s.pop();
}
cocktailCore.style.formatter.InlineFormattingContext.prototype.__class__ = cocktailCore.style.formatter.InlineFormattingContext;
$_ = {}
js.Boot.__res = {}
$s = [];
$e = [];
js.Boot.__init();
js["XMLHttpRequest"] = window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function() {
	$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
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
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
		var $spos = $s.length;
		var $tmp = isFinite(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
	Math.isNaN = function(i) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
		var $spos = $s.length;
		var $tmp = isNaN(i);
		$s.pop();
		return $tmp;
		$s.pop();
	};
}
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
	var d = Date;
	d.now = function() {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
		var $spos = $s.length;
		var $tmp = new Date();
		$s.pop();
		return $tmp;
		$s.pop();
	};
	d.fromTime = function(t) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
		var $spos = $s.length;
		var d1 = new Date();
		d1["setTime"](t);
		$s.pop();
		return d1;
		$s.pop();
	};
	d.fromString = function(s) {
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
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
		$s.push("cocktailCore.style.formatter.InlineFormattingContext::computeLineBoxHeight");
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
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_QUALITY = "optimizeQuality";
cocktailCore.domElement.js.ImageDOMElement.IMAGE_RENDERING_OPTIMIZE_SPEED = "optimizeSpeed";
haxe.Timer.arr = new Array();
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
WebApp.main()