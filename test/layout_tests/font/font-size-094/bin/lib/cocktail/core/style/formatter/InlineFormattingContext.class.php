<?php

class cocktail_core_style_formatter_InlineFormattingContext extends cocktail_core_style_formatter_FormattingContext {
	public function __construct($formattingContextRoot) {
		if(!php_Boot::$skip_constructor) {
		$this->_unbreakableLineBoxes = new _hx_array(array());
		$this->_unbreakableWidth = 0.0;
		$this->_firstLineFormatted = false;
		parent::__construct($formattingContextRoot);
	}}
	public function alignLineBoxesVertically($lineBox, $lineBoxAscent, $formattingContextY, $parentBaseLineOffset, $formattingContextFontMetrics) {
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				$baselineOffset = $child->getBaselineOffset($parentBaseLineOffset, $formattingContextFontMetrics->xHeight);
				$»t = ($child->elementRenderer->coreStyle->verticalAlign);
				switch($»t->index) {
				case 3:
				{
					$child->get_bounds()->y = $formattingContextY;
				}break;
				default:{
					$child->get_bounds()->y = $formattingContextY - $baselineOffset + $lineBoxAscent;
					$child->get_bounds()->y -= $child->leadedAscent;
				}break;
				}
				if($child->hasChildNodes() === true) {
					$this->alignLineBoxesVertically($child, $lineBoxAscent, $formattingContextY, $baselineOffset, $formattingContextFontMetrics);
				}
				unset($i,$child,$baselineOffset);
			}
		}
	}
	public function setRootLineBoxMetrics($lineBox, $rootLineBox, $parentBaseLineOffset, $formattingContextFontMetrics) {
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->isStaticPosition() === false) {
					$leadedAscent = $child->leadedAscent;
					$leadedDescent = $child->leadedDescent;
					$baselineOffset = $child->getBaselineOffset($parentBaseLineOffset, $formattingContextFontMetrics->xHeight);
					if($leadedAscent + $baselineOffset > $rootLineBox->leadedAscent) {
						$rootLineBox->leadedAscent = $leadedAscent + $baselineOffset;
					}
					if($leadedDescent + $baselineOffset > $rootLineBox->leadedDescent) {
						$rootLineBox->leadedDescent = $leadedDescent + $baselineOffset;
					}
					if($child->hasChildNodes() === true) {
						$this->setRootLineBoxMetrics($child, $rootLineBox, $baselineOffset, $formattingContextFontMetrics);
					}
					unset($leadedDescent,$leadedAscent,$baselineOffset);
				}
				unset($i,$child);
			}
		}
	}
	public function computeLineBoxHeight($rootLineBox) {
		$formattingContextFontMetrics = $this->_formattingContextRoot->coreStyle->get_fontMetricsData();
		$this->setRootLineBoxMetrics($rootLineBox, $rootLineBox, 0.0, $formattingContextFontMetrics);
		$this->alignLineBoxesVertically($rootLineBox, $rootLineBox->leadedAscent, $this->_formattingContextData->y, 0.0, $formattingContextFontMetrics);
		$lineBoxHeight = $rootLineBox->get_bounds()->height;
		return $lineBoxHeight;
	}
	public function getLineBoxTreeAsArray($rootLineBox) {
		$ret = new _hx_array(array());
		{
			$_g1 = 0; $_g = $rootLineBox->childNodes->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$child = $rootLineBox->childNodes[$i];
				if($child->hasChildNodes() === true && $child->isStaticPosition() === false) {
					$children = $this->getLineBoxTreeAsArray($child);
					{
						$_g3 = 0; $_g2 = $children->length;
						while($_g3 < $_g2) {
							$j = $_g3++;
							$ret->push($children[$j]);
							unset($j);
						}
						unset($_g3,$_g2);
					}
					unset($children);
				} else {
					$ret->push($child);
				}
				unset($i,$child);
			}
		}
		return $ret;
	}
	public function removeSpaces($rootLineBox) {
		$lineBoxes = $this->getLineBoxTreeAsArray($rootLineBox);
		if($lineBoxes->length === 0) {
			return;
		}
		$i = 0;
		while($i < $lineBoxes->length) {
			$lineBox = $lineBoxes[$i];
			if($lineBox->isSpace() === true) {
				$»t = ($lineBox->elementRenderer->coreStyle->computedStyle->whiteSpace);
				switch($»t->index) {
				case 0:
				case 2:
				case 4:
				{
					$lineBox->parentNode->removeChild($lineBox);
				}break;
				default:{
					break 2;
				}break;
				}
			} else {
				if($lineBox->isStaticPosition() === false) {
					break;
				}
			}
			$i++;
			unset($lineBox);
		}
		$lineBoxes = $this->getLineBoxTreeAsArray($rootLineBox);
		if($lineBoxes->length === 0) {
			return;
		}
		$i1 = $lineBoxes->length - 1;
		while($i1 >= 0) {
			$lineBox = $lineBoxes[$i1];
			if($lineBox->isSpace() === true) {
				$»t = ($lineBox->elementRenderer->coreStyle->computedStyle->whiteSpace);
				switch($»t->index) {
				case 0:
				case 2:
				case 4:
				{
					$lineBox->parentNode->removeChild($lineBox);
				}break;
				default:{
					break 2;
				}break;
				}
			} else {
				if($lineBox->isStaticPosition() === false) {
					break;
				}
			}
			$i1--;
			unset($lineBox);
		}
	}
	public function alignJustify($flowX, $remainingSpace, $lineBox, $spacesInLine) {
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->isSpace() === true) {
					$spaceWidth = $remainingSpace / $spacesInLine;
					$spacesInLine--;
					$remainingSpace -= $spaceWidth;
					$flowX += $spaceWidth;
					unset($spaceWidth);
				}
				$child->get_bounds()->x = $flowX;
				$flowX += $child->get_bounds()->width;
				if($child->hasChildNodes() === true) {
					$this->alignJustify($flowX, $remainingSpace, $child, $spacesInLine);
				}
				unset($i,$child);
			}
		}
	}
	public function alignRight($flowX, $remainingSpace, $lineBox) {
		$flowX += $lineBox->marginLeft + $lineBox->paddingLeft;
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->hasChildNodes() === true) {
					$flowX = $this->alignRight($flowX, $remainingSpace, $child);
				}
				$child->get_bounds()->x = $flowX + $remainingSpace;
				$flowX += $child->get_bounds()->width;
				unset($i,$child);
			}
		}
		$flowX += $lineBox->marginRight + $lineBox->paddingRight;
		return $flowX;
	}
	public function alignCenter($flowX, $remainingSpace, $lineBox) {
		$flowX += $lineBox->marginLeft + $lineBox->paddingLeft;
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->hasChildNodes() === true) {
					$flowX = $this->alignCenter($flowX, $remainingSpace, $child);
				}
				$child->get_bounds()->x = $remainingSpace / 2 + $flowX;
				$flowX += $child->get_bounds()->width;
				unset($i,$child);
			}
		}
		$flowX += $lineBox->marginRight + $lineBox->paddingRight;
		return $flowX;
	}
	public function alignLeft($flowX, $lineBox) {
		$flowX += $lineBox->paddingLeft + $lineBox->marginLeft;
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->hasChildNodes() === true && $child->isStaticPosition() === false) {
					$flowX = $this->alignLeft($flowX, $child);
				} else {
					$child->get_bounds()->x = $flowX + $child->marginLeft;
					if($child->isStaticPosition() === false) {
						$flowX += $child->get_bounds()->width + $child->marginLeft + $child->marginRight;
					}
				}
				unset($i,$child);
			}
		}
		$flowX += $lineBox->paddingRight + $lineBox->marginRight;
		return $flowX;
	}
	public function alignLineBox($rootLineBox, $isLastLine, $concatenatedLength) {
		$remainingSpace = null;
		$flowX = null;
		$formattingContextRootComputedStyle = $this->_formattingContextRoot->coreStyle->computedStyle;
		$remainingSpace = $formattingContextRootComputedStyle->getWidth() - $concatenatedLength - $this->_floatsManager->getLeftFloatOffset($this->_formattingContextData->y) - $this->_floatsManager->getRightFloatOffset($this->_formattingContextData->y + $this->_formattingContextRoot->get_bounds()->y, $formattingContextRootComputedStyle->getWidth());
		$flowX = $formattingContextRootComputedStyle->getPaddingLeft();
		if($this->_firstLineFormatted === false) {
			$flowX += $formattingContextRootComputedStyle->getTextIndent();
			$remainingSpace -= $formattingContextRootComputedStyle->getTextIndent();
		}
		$flowX += $this->_floatsManager->getLeftFloatOffset($this->_formattingContextData->y + $this->_formattingContextRoot->get_bounds()->y);
		$»t = ($formattingContextRootComputedStyle->textAlign);
		switch($»t->index) {
		case 0:
		{
			$this->alignLeft($flowX, $rootLineBox);
		}break;
		case 1:
		{
			$this->alignRight($flowX, $remainingSpace, $rootLineBox);
		}break;
		case 2:
		{
			$this->alignCenter($flowX, $remainingSpace, $rootLineBox);
		}break;
		case 3:
		{
			if($isLastLine === true) {
				$this->alignLeft($flowX, $rootLineBox);
			} else {
				$concatenatedLength = $formattingContextRootComputedStyle->getWidth();
				$this->alignJustify($flowX, $remainingSpace, $rootLineBox, $this->getSpacesNumber($rootLineBox));
			}
		}break;
		}
		return $concatenatedLength;
	}
	public function getRemainingLineWidth() {
		return $this->_formattingContextRoot->coreStyle->computedStyle->getWidth() - $this->_formattingContextData->x - $this->_floatsManager->getRightFloatOffset($this->_formattingContextData->y + $this->_formattingContextRoot->get_bounds()->y, $this->_formattingContextRoot->coreStyle->computedStyle->getWidth());
	}
	public function getSpacesNumber($lineBox) {
		$spacesNumber = 0;
		{
			$_g1 = 0; $_g = $lineBox->childNodes->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$child = $lineBox->childNodes[$i];
				if($child->hasChildNodes() === true) {
					$spacesNumber += $this->getSpacesNumber($child);
				}
				if($child->isSpace() === true) {
					$spacesNumber++;
				}
				unset($i,$child);
			}
		}
		return $spacesNumber;
	}
	public function getConcatenatedWidth($lineBox) {
		$concatenatedWidth = 0.0;
		$length = $lineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $lineBox->childNodes[$i];
				if($child->isStaticPosition() === false) {
					if($child->hasChildNodes() === true) {
						$concatenatedWidth += $this->getConcatenatedWidth($child);
					}
					$concatenatedWidth += $child->get_bounds()->width;
				}
				unset($i,$child);
			}
		}
		return $concatenatedWidth;
	}
	public function formatLine($rootLineBox, $isLastLine) {
		$this->removeSpaces($rootLineBox);
		$lineBoxWidth = $this->alignLineBox($rootLineBox, $isLastLine, $this->getConcatenatedWidth($rootLineBox));
		if($lineBoxWidth > $this->_formattingContextData->width) {
			$this->_formattingContextData->width = $lineBoxWidth;
		}
		$lineBoxHeight = $this->computeLineBoxHeight($rootLineBox);
		$this->_formattingContextData->y += $lineBoxHeight;
		$this->_firstLineFormatted = true;
	}
	public function insertIntoLine($lineBoxes, $lineBox, $rootLineBoxes, $openedElementRenderers) {
		$length = $lineBoxes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$this->_unbreakableLineBoxes->push($lineBoxes[$i]);
				if(_hx_array_get($lineBoxes, $i)->isStaticPosition() === false) {
					$this->_unbreakableWidth += _hx_array_get($lineBoxes, $i)->get_bounds()->width + $lineBox->marginLeft + $lineBox->marginRight;
				}
				$remainingLineWidth = $this->getRemainingLineWidth();
				if($remainingLineWidth - $this->_unbreakableWidth < 0) {
					$this->_formattingContextData->y = $this->_floatsManager->getFirstAvailableY($this->_formattingContextData->y + $this->_formattingContextRoot->get_bounds()->y, $this->_unbreakableWidth, $this->_formattingContextRoot->coreStyle->computedStyle->getWidth());
					$this->_formattingContextData->y -= $this->_formattingContextRoot->get_bounds()->y;
					$this->_formattingContextData->x = $this->_floatsManager->getLeftFloatOffset($this->_formattingContextData->y + $this->_formattingContextRoot->get_bounds()->y);
					$this->formatLine($rootLineBoxes[$rootLineBoxes->length - 1], false);
					$rootLineBox = new cocktail_core_linebox_RootLineBox($this->_formattingContextRoot);
					$rootLineBoxes->push($rootLineBox);
					$lineBox = $rootLineBox;
					{
						$_g2 = 0; $_g1 = $openedElementRenderers->length;
						while($_g2 < $_g1) {
							$j = $_g2++;
							$childLineBox = $this->createContainerLineBox($openedElementRenderers[$j]);
							$lineBox->appendChild($childLineBox);
							$lineBox = $childLineBox;
							unset($j,$childLineBox);
						}
						unset($_g2,$_g1);
					}
					unset($rootLineBox);
				}
				$unbreakableLength = $this->_unbreakableLineBoxes->length;
				{
					$_g1 = 0;
					while($_g1 < $unbreakableLength) {
						$j = $_g1++;
						$lineBox->appendChild($this->_unbreakableLineBoxes[$j]);
						unset($j);
					}
					unset($_g1);
				}
				$this->_formattingContextData->x += $this->_unbreakableWidth;
				$this->_unbreakableLineBoxes = new _hx_array(array());
				$this->_unbreakableWidth = 0;
				unset($unbreakableLength,$remainingLineWidth,$i);
			}
		}
		return $lineBox;
	}
	public function createContainerLineBox($child) {
		$lineBox = new cocktail_core_linebox_LineBox($child);
		$child->lineBoxes->push($lineBox);
		return $lineBox;
	}
	public function doFormat($elementRenderer, $lineBox, $rootLineBoxes, $openedElementRenderers) {
		$length = $elementRenderer->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $elementRenderer->childNodes[$i];
				if($child->isPositioned() === true && $child->isRelativePositioned() === false) {
					$staticLineBox = new cocktail_core_linebox_StaticPositionLineBox($child);
					$child->get_bounds()->width = $child->coreStyle->computedStyle->getWidth() + $child->coreStyle->computedStyle->getPaddingLeft() + $child->coreStyle->computedStyle->getPaddingRight();
					$child->get_bounds()->height = $child->coreStyle->computedStyle->getHeight() + $child->coreStyle->computedStyle->getPaddingTop() + $child->coreStyle->computedStyle->getPaddingBottom();
					$lineBox = $this->insertIntoLine(new _hx_array(array($staticLineBox)), $lineBox, $rootLineBoxes, $openedElementRenderers);
					unset($staticLineBox);
				} else {
					if($child->establishesNewFormattingContext() === true || $child->isReplaced() === true) {
						$childComputedStyle = $child->coreStyle->computedStyle;
						$childBounds = $child->get_bounds();
						$childBounds->width = $childComputedStyle->getWidth() + $childComputedStyle->getPaddingLeft() + $childComputedStyle->getPaddingRight();
						$childBounds->height = $childComputedStyle->getHeight() + $childComputedStyle->getPaddingTop() + $childComputedStyle->getPaddingBottom();
						$embeddedLineBox = new cocktail_core_linebox_EmbeddedLineBox($child);
						$embeddedLineBox->marginLeft = $childComputedStyle->getMarginLeft();
						$embeddedLineBox->marginRight = $childComputedStyle->getMarginRight();
						$lineBox = $this->insertIntoLine(new _hx_array(array($embeddedLineBox)), $lineBox, $rootLineBoxes, $openedElementRenderers);
						unset($embeddedLineBox,$childComputedStyle,$childBounds);
					} else {
						if($child->hasChildNodes() === true) {
							$child->lineBoxes = new _hx_array(array());
							$childLineBox = $this->createContainerLineBox($child);
							$childComputedStyle = $child->coreStyle->computedStyle;
							$childLineBox->marginLeft = $childComputedStyle->getMarginLeft();
							$childLineBox->paddingLeft = $childComputedStyle->getPaddingLeft();
							$this->_unbreakableWidth += $childComputedStyle->getMarginLeft() + $childComputedStyle->getPaddingLeft();
							$lineBox->appendChild($childLineBox);
							$openedElementRenderers->push($child);
							$lineBox = $this->doFormat($child, $childLineBox, $rootLineBoxes, $openedElementRenderers);
							$openedElementRenderers->pop();
							$lineBox = $lineBox->parentNode;
							$lastLineBox = $child->lineBoxes[$child->lineBoxes->length - 1];
							$lastLineBox->marginRight = $childComputedStyle->getMarginRight();
							$lastLineBox->paddingRight = $childComputedStyle->getPaddingRight();
							$this->_unbreakableWidth += $childComputedStyle->getMarginRight() + $childComputedStyle->getPaddingRight();
							unset($lastLineBox,$childLineBox,$childComputedStyle);
						} else {
							$lineBox = $this->insertIntoLine($child->lineBoxes, $lineBox, $rootLineBoxes, $openedElementRenderers);
						}
					}
				}
				unset($i,$child);
			}
		}
		return $lineBox;
	}
	public function startFormatting() {
		$this->_unbreakableLineBoxes = new _hx_array(array());
		$rootLineBoxes = new _hx_array(array());
		$initialRootLineBox = new cocktail_core_linebox_RootLineBox($this->_formattingContextRoot);
		$rootLineBoxes->push($initialRootLineBox);
		$this->_firstLineFormatted = false;
		$this->_unbreakableWidth = $this->_formattingContextRoot->coreStyle->computedStyle->getTextIndent();
		$this->_formattingContextData->x = $this->_formattingContextRoot->coreStyle->computedStyle->getTextIndent();
		$this->_formattingContextData->x += $this->_floatsManager->getLeftFloatOffset($this->_formattingContextRoot->get_bounds()->y);
		$this->doFormat($this->_formattingContextRoot, $initialRootLineBox, $rootLineBoxes, new _hx_array(array()));
		$this->formatLine($rootLineBoxes[$rootLineBoxes->length - 1], true);
		$this->_formattingContextRoot->lineBoxes = $rootLineBoxes;
		if($this->_formattingContextRoot->coreStyle->height == cocktail_core_style_Dimension::$cssAuto) {
			$formattingContextComputedStyle = $this->_formattingContextRoot->coreStyle->computedStyle;
			$this->_formattingContextRoot->get_bounds()->height = $this->_formattingContextData->y + $formattingContextComputedStyle->getPaddingBottom();
			$formattingContextComputedStyle->set_height($this->_formattingContextData->y - $formattingContextComputedStyle->getPaddingTop());
		}
	}
	public $_firstLineFormatted;
	public $_unbreakableWidth;
	public $_unbreakableLineBoxes;
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
	function __toString() { return 'cocktail.core.style.formatter.InlineFormattingContext'; }
}
