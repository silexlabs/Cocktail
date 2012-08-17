<?php

class cocktail_core_style_CoreStyle {
	public function __construct($htmlElement) {
		if(!php_Boot::$skip_constructor) {
		$this->htmlElement = $htmlElement;
		$this->_fontManager = cocktail_core_font_FontManager::getInstance();
		$this->_pendingAnimations = new _hx_array(array());
		$this->initDefaultStyleValues($htmlElement->tagName);
	}}
	public function setCursor($value) {
		$this->cursor = $value;
		$this->computedStyle->cursor = $value;
		return $value;
	}
	public function setBackgroundOrigin($value) {
		$this->backgroundOrigin = $value;
		$this->computedStyle->backgroundOrigin = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-origin"));
		return $value;
	}
	public function setBackgroundRepeat($value) {
		$this->backgroundRepeat = $value;
		$this->computedStyle->backgroundRepeat = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-repeat"));
		return $value;
	}
	public function setBackgroundPosition($value) {
		$this->backgroundPosition = $value;
		$this->computedStyle->backgroundPosition = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-position"));
		return $value;
	}
	public function setBackgroundClip($value) {
		$this->backgroundClip = $value;
		$this->computedStyle->backgroundClip = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-clip"));
		return $value;
	}
	public function setBackgroundSize($value) {
		$this->backgroundSize = $value;
		$this->computedStyle->backgroundSize = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-size"));
		return $value;
	}
	public function setBackgroundImage($value) {
		$this->backgroundImage = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-image"));
		return $value;
	}
	public function setBackgroundColor($value) {
		$this->backgroundColor = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("background-color"));
		return $value;
	}
	public function setTransitionTimingFunction($value) {
		$this->transitionTimingFunction = $value;
		$this->computedStyle->transitionTimingFunction = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("transition-timing-function"));
		return $value;
	}
	public function setTransitionDelay($value) {
		$this->transitionDelay = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("transition-delay"));
		return $value;
	}
	public function setTransitionDuration($value) {
		$this->transitionDuration = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("transition-duration"));
		return $value;
	}
	public function setTransitionProperty($value) {
		$this->transitionProperty = $value;
		$this->computedStyle->transitionProperty = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("transition-property"));
		return $value;
	}
	public function setOverflowY($value) {
		$this->overflowY = $value;
		$this->computedStyle->overflowY = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setOverflowX($value) {
		$this->overflowX = $value;
		$this->computedStyle->overflowX = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setTransform($value) {
		$this->transform = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setTransformOrigin($value) {
		$this->transformOrigin = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("transform-origin"));
		return $value;
	}
	public function setVisibility($value) {
		$this->visibility = $value;
		$this->computedStyle->visibility = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("visibility"));
		return $value;
	}
	public function setOpacity($value) {
		$this->opacity = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("opacity");
		$this->registerPendingAnimation("opacity", $invalidationReason, $this->computedStyle->getOpacity());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setTextAlign($value) {
		$this->textAlign = $value;
		$this->computedStyle->textAlign = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("text-align"));
		return $value;
	}
	public function setWhiteSpace($value) {
		$this->whiteSpace = $value;
		$this->computedStyle->whiteSpace = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("white-space"));
		return $value;
	}
	public function setTextIndent($value) {
		$this->textIndent = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("text-indent");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setVerticalAlign($value) {
		$this->verticalAlign = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("vertical-align");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setColor($value) {
		$this->color = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("color"));
		return $value;
	}
	public function setLineHeight($value) {
		$this->lineHeight = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("line-height");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setWordSpacing($value) {
		$this->wordSpacing = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("word-spacing");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setLetterSpacing($value) {
		$this->letterSpacing = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("letter-spacing");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setTextTransform($value) {
		$this->textTransform = $value;
		$this->computedStyle->textTransform = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("text-tranform"));
		return $value;
	}
	public function setFontVariant($value) {
		$this->fontVariant = $value;
		$this->computedStyle->fontVariant = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("font-variant"));
		return $value;
	}
	public function setFontFamily($value) {
		$this->fontFamily = $value;
		$this->computedStyle->fontFamily = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("font-family"));
		return $value;
	}
	public function setFontStyle($value) {
		$this->fontStyle = $value;
		$this->computedStyle->fontStyle = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("font-style"));
		return $value;
	}
	public function setFontWeight($value) {
		$this->fontWeight = $value;
		$this->computedStyle->fontWeight = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("font-weight"));
		return $value;
	}
	public function setFontSize($value) {
		$this->fontSize = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("font-size");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setZIndex($value) {
		$this->zIndex = $value;
		$this->computedStyle->zIndex = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setClear($value) {
		$this->clear = $value;
		$this->invalidate(cocktail_core_renderer_InvalidationReason::styleChanged("clear"));
		return $value;
	}
	public function setCSSFloat($value) {
		$this->cssFloat = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setRight($value) {
		$this->right = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("right");
		$this->registerPendingAnimation("right", $invalidationReason, $this->computedStyle->getRight());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setBottom($value) {
		$this->bottom = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("bottom");
		$this->registerPendingAnimation("bottom", $invalidationReason, $this->computedStyle->getBottom());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setLeft($value) {
		$this->left = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("left");
		$this->registerPendingAnimation("left", $invalidationReason, $this->computedStyle->getLeft());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setTop($value) {
		$this->top = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("top");
		$this->registerPendingAnimation("top", $invalidationReason, $this->computedStyle->getTop());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMaxWidth($value) {
		$this->maxWidth = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("max-width");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMinWidth($value) {
		$this->minWidth = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("min-width");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMaxHeight($value) {
		$this->maxHeight = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("max-height");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMinHeight($value) {
		$this->minHeight = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("min-height");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setHeight($value) {
		$this->height = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("height");
		$this->registerPendingAnimation("height", $invalidationReason, $this->computedStyle->getHeight());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setPosition($value) {
		$this->position = $value;
		$this->computedStyle->position = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setDisplay($value) {
		$this->display = $value;
		$this->invalidatePositioningScheme();
		return $value;
	}
	public function setPaddingBottom($value) {
		$this->paddingBottom = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("padding-bottom");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setPaddingTop($value) {
		$this->paddingTop = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("padding-top");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setPaddingRight($value) {
		$this->paddingRight = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("padding-right");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setPaddingLeft($value) {
		$this->paddingLeft = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("padding-left");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMarginBottom($value) {
		$this->marginBottom = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("margin-bottom");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMarginTop($value) {
		$this->marginTop = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("margin-top");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMarginRight($value) {
		$this->marginRight = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("margin-right");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setMarginLeft($value) {
		$this->marginLeft = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("margin-left");
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function setWidth($value) {
		$this->width = $value;
		$invalidationReason = cocktail_core_renderer_InvalidationReason::styleChanged("width");
		$this->registerPendingAnimation("width", $invalidationReason, $this->computedStyle->getWidth());
		$this->invalidate($invalidationReason);
		return $value;
	}
	public function get_fontMetricsData() {
		return $this->_fontManager->getFontMetrics(cocktail_core_unit_UnitManager::getCSSFontFamily($this->computedStyle->fontFamily), $this->computedStyle->getFontSize());
	}
	public function onTransitionUpdate($transition) {
		$this->invalidate($transition->invalidationReason);
	}
	public function onTransitionComplete($transition) {
		$this->invalidate($transition->invalidationReason);
		$transitionEvent = new cocktail_core_event_TransitionEvent();
		$transitionEvent->initTransitionEvent("transitionend", true, true, $transition->propertyName, $transition->transitionDuration, "");
		$this->htmlElement->dispatchEvent($transitionEvent);
	}
	public function getRepeatedIndex($index, $length) {
		if($index < $length) {
			return $index;
		}
		return _hx_mod($length, $index);
	}
	public function startTransitionIfNeeded($pendingAnimation) {
		$propertyIndex = 0;
		$»t = ($this->computedStyle->transitionProperty);
		switch($»t->index) {
		case 0:
		{
			return false;
		}break;
		case 2:
		$value = $»t->params[0];
		{
			$foundFlag = false;
			{
				$_g1 = 0; $_g = $value->length;
				while($_g1 < $_g) {
					$i = $_g1++;
					if($value[$i] === $pendingAnimation->propertyName) {
						$propertyIndex = $i;
						$foundFlag = true;
						break;
					}
					unset($i);
				}
			}
			if($foundFlag === false) {
				return false;
			}
		}break;
		case 1:
		{
		}break;
		}
		$combinedDuration = 0.0;
		$transitionDelay = $this->computedStyle->transitionDelay[$this->getRepeatedIndex($propertyIndex, $this->computedStyle->transitionDelay->length)];
		$transitionDuration = $this->computedStyle->transitionDuration[$this->getRepeatedIndex($propertyIndex, $this->computedStyle->transitionDuration->length)];
		$combinedDuration = $transitionDuration + $transitionDelay;
		if($combinedDuration <= 0) {
			return false;
		}
		$transitionTimingFunction = $this->computedStyle->transitionTimingFunction[$this->getRepeatedIndex($propertyIndex, $this->computedStyle->transitionTimingFunction->length)];
		$transitionManager = cocktail_core_style_transition_TransitionManager::getInstance();
		$transition = $transitionManager->getTransition($pendingAnimation->propertyName, $this->computedStyle);
		if($transition !== null) {
			return false;
		}
		$endValue = Reflect::getProperty($this->computedStyle, $pendingAnimation->propertyName);
		$transitionManager->startTransition($this->computedStyle, $pendingAnimation->propertyName, $pendingAnimation->startValue, $endValue, $transitionDuration, $transitionDelay, $transitionTimingFunction, (isset($this->onTransitionComplete) ? $this->onTransitionComplete: array($this, "onTransitionComplete")), (isset($this->onTransitionUpdate) ? $this->onTransitionUpdate: array($this, "onTransitionUpdate")), $pendingAnimation->invalidationReason);
		return true;
	}
	public function registerPendingAnimation($propertyName, $invalidationReason, $startValue) {
		$this->_pendingAnimations->push(_hx_anonymous(array("propertyName" => $propertyName, "invalidationReason" => $invalidationReason, "startValue" => $startValue)));
	}
	public function startPendingAnimations() {
		$atLeastOneAnimationStarted = false;
		{
			$_g1 = 0; $_g = $this->_pendingAnimations->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$animationStarted = $this->startTransitionIfNeeded($this->_pendingAnimations[$i]);
				if($animationStarted === true) {
					$atLeastOneAnimationStarted = true;
				}
				unset($i,$animationStarted);
			}
		}
		$this->_pendingAnimations = new _hx_array(array());
		return $atLeastOneAnimationStarted;
	}
	public function invalidatePositioningScheme() {
		$this->htmlElement->invalidatePositioningScheme();
	}
	public function invalidate($invalidationReason) {
		$this->htmlElement->invalidate($invalidationReason);
	}
	public function applyDefaultHTMLStyles($tagName) {
		switch(strtoupper($tagName)) {
		case "HTML":case "ADRESS":case "DD":case "DIV":case "DL":case "DT":case "FIELDSET":case "FORM":case "FRAME":case "FRAMESET":case "NOFRAMES":case "OL":case "CENTER":case "DIR":case "HR":case "MENU":{
			$this->setDisplay(cocktail_core_style_Display::$block);
		}break;
		case "LI":{
			$this->setDisplay(cocktail_core_style_Display::$block);
		}break;
		case "A":{
			$this->setCursor(cocktail_core_style_Cursor::$pointer);
		}break;
		case "UL":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1.12))));
			$this->setMarginLeft(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(40)));
		}break;
		case "HEAD":{
			$this->setDisplay(cocktail_core_style_Display::$none);
		}break;
		case "BODY":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setMarginLeft($this->setMarginRight($this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(8))))));
		}break;
		case "H1":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(2)));
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(0.67))));
		}break;
		case "H2":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(1.5)));
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(0.75))));
		}break;
		case "H3":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(1.17)));
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(0.83))));
		}break;
		case "H4":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1.12))));
		}break;
		case "H5":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(0.83)));
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1.5))));
		}break;
		case "H6":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(0.75)));
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1.67))));
		}break;
		case "P":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1))));
		}break;
		case "PRE":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setWhiteSpace(cocktail_core_style_WhiteSpace::$pre);
			$this->setFontFamily(new _hx_array(array("monospace")));
		}break;
		case "CODE":{
			$this->setFontFamily(new _hx_array(array("monospace")));
		}break;
		case "I":case "CITE":case "EM":case "VAR":{
			$this->setFontStyle(cocktail_core_style_FontStyle::$italic);
		}break;
		case "INPUT":{
			$this->setDisplay(cocktail_core_style_Display::$inlineBlock);
		}break;
		case "BLOCKQUOTE":{
			$this->setDisplay(cocktail_core_style_Display::$block);
			$this->setMarginTop($this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::em(1.12))));
			$this->setMarginLeft($this->setMarginRight(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(40))));
		}break;
		case "STRONG":{
			$this->setFontWeight(cocktail_core_style_FontWeight::$bolder);
		}break;
		case "BIG":{
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(1.17)));
		}break;
		case "SMALL":{
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(0.83)));
		}break;
		case "SUB":{
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(0.83)));
			$this->setVerticalAlign(cocktail_core_style_VerticalAlign::$sub);
		}break;
		case "SUP":{
			$this->setFontSize(cocktail_core_style_FontSize::length(cocktail_core_unit_Length::em(0.83)));
			$this->setVerticalAlign(cocktail_core_style_VerticalAlign::$cssSuper);
		}break;
		}
	}
	public function initComputedStyles() {
		$this->computedStyle->init();
	}
	public function initDefaultStyleValues($tagName) {
		$this->computedStyle = new cocktail_core_style_ComputedStyle($this);
		$this->initComputedStyles();
		$this->setWidth(cocktail_core_style_CoreStyle::getWidthDefaultValue());
		$this->setHeight(cocktail_core_style_CoreStyle::getHeightDefaultValue());
		$this->setMinWidth(cocktail_core_style_CoreStyle::getMinWidthDefaultValue());
		$this->setMaxWidth(cocktail_core_style_CoreStyle::getMaxWidthDefaultValue());
		$this->setMinHeight(cocktail_core_style_CoreStyle::getMinHeightDefaultValue());
		$this->setMaxHeight(cocktail_core_style_CoreStyle::getMaxHeightDefaultValue());
		$this->setMarginTop(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(0)));
		$this->setMarginBottom(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(0)));
		$this->setMarginLeft(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(0)));
		$this->setMarginRight(cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(0)));
		$this->setPaddingTop(cocktail_core_style_Padding::length(cocktail_core_unit_Length::px(0)));
		$this->setPaddingBottom(cocktail_core_style_Padding::length(cocktail_core_unit_Length::px(0)));
		$this->setPaddingLeft(cocktail_core_style_Padding::length(cocktail_core_unit_Length::px(0)));
		$this->setPaddingRight(cocktail_core_style_Padding::length(cocktail_core_unit_Length::px(0)));
		$this->setLineHeight(cocktail_core_style_LineHeight::$normal);
		$this->setVerticalAlign(cocktail_core_style_VerticalAlign::$baseline);
		$this->setDisplay(cocktail_core_style_Display::$cssInline);
		$this->setPosition(cocktail_core_style_Position::$cssStatic);
		$this->setZIndex(cocktail_core_style_ZIndex::$cssAuto);
		$this->setTop(cocktail_core_style_PositionOffset::$cssAuto);
		$this->setBottom(cocktail_core_style_PositionOffset::$cssAuto);
		$this->setLeft(cocktail_core_style_PositionOffset::$cssAuto);
		$this->setRight(cocktail_core_style_PositionOffset::$cssAuto);
		$this->setCSSFloat(cocktail_core_style_CSSFloat::$none);
		$this->setClear(cocktail_core_style_Clear::$none);
		$this->setBackgroundColor(cocktail_core_unit_CSSColor::$transparent);
		$this->setBackgroundImage(new _hx_array(array(cocktail_core_style_BackgroundImage::$none)));
		$this->setBackgroundRepeat(new _hx_array(array(_hx_anonymous(array("x" => cocktail_core_style_BackgroundRepeatValue::$repeat, "y" => cocktail_core_style_BackgroundRepeatValue::$repeat)))));
		$this->setBackgroundPosition(cocktail_core_style_CoreStyle::getBackgroundPositionDefaultValue());
		$this->setBackgroundOrigin(new _hx_array(array(cocktail_core_style_BackgroundOrigin::$paddingBox)));
		$this->setBackgroundSize(new _hx_array(array(cocktail_core_style_BackgroundSize::dimensions(_hx_anonymous(array("x" => cocktail_core_style_BackgroundSizeDimension::$cssAuto, "y" => cocktail_core_style_BackgroundSizeDimension::$cssAuto))))));
		$this->setBackgroundClip(new _hx_array(array(cocktail_core_style_BackgroundClip::$borderBox)));
		$this->setFontStyle(cocktail_core_style_FontStyle::$normal);
		$this->setFontVariant(cocktail_core_style_FontVariant::$normal);
		$this->setFontWeight(cocktail_core_style_FontWeight::$normal);
		$this->setFontSize(cocktail_core_style_FontSize::absoluteSize(cocktail_core_unit_FontSizeAbsoluteSize::$medium));
		$this->setTextIndent(cocktail_core_style_TextIndent::length(cocktail_core_unit_Length::px(0)));
		$this->setTextAlign(cocktail_core_style_TextAlign::$left);
		$this->setLetterSpacing(cocktail_core_style_LetterSpacing::$normal);
		$this->setWordSpacing(cocktail_core_style_WordSpacing::$normal);
		$this->setTextTransform(cocktail_core_style_TextTransform::$none);
		$this->setWhiteSpace(cocktail_core_style_WhiteSpace::$normal);
		$this->setVisibility(cocktail_core_style_Visibility::$visible);
		$this->setOpacity(1.0);
		$this->setOverflowX(cocktail_core_style_Overflow::$visible);
		$this->setOverflowY(cocktail_core_style_Overflow::$visible);
		$this->setTransitionDelay(new _hx_array(array(cocktail_core_unit_TimeValue::seconds(0))));
		$this->setTransitionDuration(new _hx_array(array(cocktail_core_unit_TimeValue::seconds(0))));
		$this->setTransitionProperty(cocktail_core_style_TransitionProperty::$all);
		$this->setTransitionTimingFunction(new _hx_array(array(cocktail_core_style_TransitionTimingFunctionValue::$ease)));
		$this->setTransformOrigin(_hx_anonymous(array("x" => cocktail_core_style_TransformOriginX::$center, "y" => cocktail_core_style_TransformOriginY::$center)));
		$this->setTransform(cocktail_core_style_Transform::$none);
		$this->setCursor(cocktail_core_style_Cursor::$cssAuto);
		$defaultStyles = cocktail_core_style_CoreStyle::getDefaultStyle();
		$this->setFontFamily($defaultStyles->fontFamily);
		$this->setColor($defaultStyles->color);
		$this->applyDefaultHTMLStyles($tagName);
	}
	public $_pendingAnimations;
	public $_fontManager;
	public $htmlElement;
	public $fontMetrics;
	public $computedStyle;
	public $transitionTimingFunction;
	public $transitionDelay;
	public $transitionDuration;
	public $transitionProperty;
	public $cursor;
	public $transform;
	public $transformOrigin;
	public $overflowY;
	public $overflowX;
	public $visibility;
	public $opacity;
	public $verticalAlign;
	public $textIndent;
	public $textAlign;
	public $whiteSpace;
	public $wordSpacing;
	public $letterSpacing;
	public $textTransform;
	public $lineHeight;
	public $color;
	public $fontVariant;
	public $fontFamily;
	public $fontStyle;
	public $fontWeight;
	public $fontSize;
	public $backgroundClip;
	public $backgroundPosition;
	public $backgroundSize;
	public $backgroundOrigin;
	public $backgroundRepeat;
	public $backgroundImage;
	public $backgroundColor;
	public $right;
	public $bottom;
	public $left;
	public $top;
	public $maxWidth;
	public $minWidth;
	public $maxHeight;
	public $minHeight;
	public $height;
	public $width;
	public $paddingBottom;
	public $paddingTop;
	public $paddingRight;
	public $paddingLeft;
	public $marginBottom;
	public $marginTop;
	public $marginRight;
	public $marginLeft;
	public $zIndex;
	public $clear;
	public $cssFloat;
	public $position;
	public $display;
	public function __call($m, $a) {
		if(isset($this->$m) && is_callable($this->$m))
			return call_user_func_array($this->$m, $a);
		else if(isset($this->»dynamics[$m]) && is_callable($this->»dynamics[$m]))
			return call_user_func_array($this->»dynamics[$m], $a);
		else if('toString' == $m)
			return $this->__toString();
		else
			throw new HException('Unable to call «'.$m.'»');
	}
	static function getDefaultStyle() {
		return _hx_anonymous(array("fontFamily" => new _hx_array(array("serif")), "color" => cocktail_core_style_CoreStyle::getColorDefaultValue()));
	}
	static function getBackgroundColorDefaultValue() {
		return cocktail_core_unit_CSSColor::$transparent;
	}
	static function getBackgroundPositionDefaultValue() {
		return new _hx_array(array(_hx_anonymous(array("x" => cocktail_core_style_BackgroundPositionX::percent(0), "y" => cocktail_core_style_BackgroundPositionY::percent(0)))));
	}
	static function getColorDefaultValue() {
		return cocktail_core_unit_CSSColor::keyword(cocktail_core_unit_ColorKeyword::$black);
	}
	static function getDisplayDefaultValue() {
		return cocktail_core_style_Display::$cssInline;
	}
	static function getPositionDefaultValue() {
		return cocktail_core_style_Position::$cssStatic;
	}
	static function getWidthDefaultValue() {
		return cocktail_core_style_Dimension::$cssAuto;
	}
	static function getHeightDefaultValue() {
		return cocktail_core_style_Dimension::$cssAuto;
	}
	static function getMinHeightDefaultValue() {
		return cocktail_core_style_ConstrainedDimension::length(cocktail_core_unit_Length::px(0));
	}
	static function getMinWidthDefaultValue() {
		return cocktail_core_style_ConstrainedDimension::length(cocktail_core_unit_Length::px(0));
	}
	static function getMaxWidthDefaultValue() {
		return cocktail_core_style_ConstrainedDimension::$none;
	}
	static function getMaxHeightDefaultValue() {
		return cocktail_core_style_ConstrainedDimension::$none;
	}
	static function getMarginDefaultValue() {
		return cocktail_core_style_Margin::length(cocktail_core_unit_Length::px(0));
	}
	static function getPaddingDefaultValue() {
		return cocktail_core_style_Padding::length(cocktail_core_unit_Length::px(0));
	}
	static function getLineHeightDefaultValue() {
		return cocktail_core_style_LineHeight::$normal;
	}
	static $__properties__ = array("set_display" => "setDisplay","set_position" => "setPosition","set_cssFloat" => "setCSSFloat","set_clear" => "setClear","set_zIndex" => "setZIndex","set_marginLeft" => "setMarginLeft","set_marginRight" => "setMarginRight","set_marginTop" => "setMarginTop","set_marginBottom" => "setMarginBottom","set_paddingLeft" => "setPaddingLeft","set_paddingRight" => "setPaddingRight","set_paddingTop" => "setPaddingTop","set_paddingBottom" => "setPaddingBottom","set_width" => "setWidth","set_height" => "setHeight","set_minHeight" => "setMinHeight","set_maxHeight" => "setMaxHeight","set_minWidth" => "setMinWidth","set_maxWidth" => "setMaxWidth","set_top" => "setTop","set_left" => "setLeft","set_bottom" => "setBottom","set_right" => "setRight","set_backgroundColor" => "setBackgroundColor","set_backgroundImage" => "setBackgroundImage","set_backgroundRepeat" => "setBackgroundRepeat","set_backgroundOrigin" => "setBackgroundOrigin","set_backgroundSize" => "setBackgroundSize","set_backgroundPosition" => "setBackgroundPosition","set_backgroundClip" => "setBackgroundClip","set_fontSize" => "setFontSize","set_fontWeight" => "setFontWeight","set_fontStyle" => "setFontStyle","set_fontFamily" => "setFontFamily","set_fontVariant" => "setFontVariant","set_color" => "setColor","set_lineHeight" => "setLineHeight","set_textTransform" => "setTextTransform","set_letterSpacing" => "setLetterSpacing","set_wordSpacing" => "setWordSpacing","set_whiteSpace" => "setWhiteSpace","set_textAlign" => "setTextAlign","set_textIndent" => "setTextIndent","set_verticalAlign" => "setVerticalAlign","set_opacity" => "setOpacity","set_visibility" => "setVisibility","set_overflowX" => "setOverflowX","set_overflowY" => "setOverflowY","set_transformOrigin" => "setTransformOrigin","set_transform" => "setTransform","set_cursor" => "setCursor","set_transitionProperty" => "setTransitionProperty","set_transitionDuration" => "setTransitionDuration","set_transitionDelay" => "setTransitionDelay","set_transitionTimingFunction" => "setTransitionTimingFunction","get_fontMetrics" => "get_fontMetricsData");
	function __toString() { return 'cocktail.core.style.CoreStyle'; }
}
