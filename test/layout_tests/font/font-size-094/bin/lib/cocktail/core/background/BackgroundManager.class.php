<?php

class cocktail_core_background_BackgroundManager {
	public function __construct() { 
	}
	static function render($graphicContext, $backgroundBox, $style, $elementRenderer) {
		if(Math::round($backgroundBox->width) <= 0 || Math::round($backgroundBox->height) <= 0) {
			return;
		}
		if($style->backgroundColor != cocktail_core_unit_CSSColor::$transparent) {
			$graphicContext->fillRect($backgroundBox, $style->computedStyle->backgroundColor);
		}
		$length = $style->backgroundImage->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$퍁 = ($style->backgroundImage[$i]);
				switch($퍁->index) {
				case 0:
				{
				}break;
				case 1:
				$value = $퍁->params[0];
				{
					$퍁2 = ($value);
					switch($퍁2->index) {
					case 0:
					$value1 = $퍁2->params[0];
					{
						$imageDeclaration = _hx_anonymous(array("urls" => new _hx_array(array($value1)), "fallbackColor" => cocktail_core_unit_CSSColor::$transparent));
						cocktail_core_background_BackgroundManager::drawBackgroundImage($graphicContext, $imageDeclaration, $style, $backgroundBox, $style->backgroundPosition[$i], $style->backgroundSize[$i], $style->backgroundOrigin[$i], $style->backgroundClip[$i], $style->backgroundRepeat[$i], $style->backgroundImage[$i], $elementRenderer);
					}break;
					case 1:
					$value1 = $퍁2->params[0];
					{
						cocktail_core_background_BackgroundManager::drawBackgroundImage($graphicContext, $value1, $style, $backgroundBox, $style->backgroundPosition[$i], $style->backgroundSize[$i], $style->backgroundOrigin[$i], $style->backgroundClip[$i], $style->backgroundRepeat[$i], $style->backgroundImage[$i], $elementRenderer);
					}break;
					case 2:
					$value1 = $퍁2->params[0];
					{
						cocktail_core_background_BackgroundManager::drawBackgroundGradient($graphicContext, $style, $value1, $backgroundBox, $style->backgroundPosition[$i], $style->backgroundSize[$i], $style->backgroundOrigin[$i], $style->backgroundClip[$i], $style->backgroundRepeat[$i], $style->backgroundImage[$i]);
					}break;
					}
				}break;
				}
				unset($i);
			}
		}
	}
	static function drawBackgroundImage($graphicContext, $imageDeclaration, $style, $backgroundBox, $backgroundPosition, $backgroundSize, $backgroundOrigin, $backgroundClip, $backgroundRepeat, $backgroundImage, $elementRenderer) {
		$foundResource = false;
		{
			$_g1 = 0; $_g = $imageDeclaration->urls->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$resource = cocktail_core_resource_ResourceManager::getResource($imageDeclaration->urls[$i]);
				if($resource->loaded === true) {
					$computedGradientStyles = cocktail_core_style_computer_BackgroundStylesComputer::computeIndividualBackground($style, $backgroundBox, $resource->intrinsicWidth, $resource->intrinsicHeight, $resource->intrinsicRatio, $backgroundPosition, $backgroundSize, $backgroundOrigin, $backgroundClip, $backgroundRepeat, $backgroundImage);
					cocktail_core_background_BackgroundManager::doDrawBackgroundImage($backgroundBox, $graphicContext, $resource, $computedGradientStyles->backgroundOrigin, $computedGradientStyles->backgroundClip, $resource->intrinsicWidth, $resource->intrinsicHeight, $resource->intrinsicRatio, $computedGradientStyles->backgroundSize, $computedGradientStyles->backgroundPosition, $computedGradientStyles->backgroundRepeat);
					$foundResource = true;
					break;
					unset($computedGradientStyles);
				} else {
					if($resource->loadedWithError === false) {
						$resource->addEventListener("load", array(new _hx_lambda(array(&$_g, &$_g1, &$backgroundBox, &$backgroundClip, &$backgroundImage, &$backgroundOrigin, &$backgroundPosition, &$backgroundRepeat, &$backgroundSize, &$elementRenderer, &$foundResource, &$graphicContext, &$i, &$imageDeclaration, &$resource, &$style), "cocktail_core_background_BackgroundManager_0"), 'execute'), null);
						$resource->addEventListener("error", array(new _hx_lambda(array(&$_g, &$_g1, &$backgroundBox, &$backgroundClip, &$backgroundImage, &$backgroundOrigin, &$backgroundPosition, &$backgroundRepeat, &$backgroundSize, &$elementRenderer, &$foundResource, &$graphicContext, &$i, &$imageDeclaration, &$resource, &$style), "cocktail_core_background_BackgroundManager_1"), 'execute'), null);
						$foundResource = true;
						break;
					}
				}
				unset($resource,$i);
			}
		}
		if($foundResource === false) {
			$backgroundColor = cocktail_core_unit_UnitManager::getColorDataFromCSSColor($imageDeclaration->fallbackColor);
			$graphicContext->fillRect($backgroundBox, $backgroundColor);
		}
	}
	static function doDrawBackgroundImage($backgroundBox, $graphicContext, $resource, $backgroundPositioningBox, $backgroundPaintingBox, $intrinsicWidth, $intrinsicHeight, $intrinsicRatio, $computedBackgroundSize, $computedBackgroundPosition, $backgroundRepeat) {
		$totalWidth = $computedBackgroundPosition->x + $backgroundPositioningBox->x;
		$maxWidth = $backgroundPaintingBox->x + $backgroundPaintingBox->width;
		$imageWidth = $computedBackgroundSize->width;
		$퍁 = ($backgroundRepeat->x);
		switch($퍁->index) {
		case 3:
		{
			$maxWidth = $totalWidth + $imageWidth;
		}break;
		case 0:
		{
			while($totalWidth > $backgroundPaintingBox->x) {
				$totalWidth -= $imageWidth;
			}
		}break;
		case 1:
		{
			$imageWidth = Math::round($backgroundPositioningBox->width / $computedBackgroundSize->width);
			while($totalWidth > $backgroundPaintingBox->x) {
				$totalWidth -= $imageWidth;
			}
		}break;
		case 2:
		{
			while($totalWidth > $backgroundPaintingBox->x) {
				$totalWidth -= $imageWidth;
			}
		}break;
		}
		$initialWidth = $totalWidth;
		$totalHeight = $computedBackgroundPosition->y + Math::round($backgroundPositioningBox->y);
		$maxHeight = $backgroundPaintingBox->y + $backgroundPaintingBox->height;
		$imageHeight = $computedBackgroundSize->height;
		$퍁 = ($backgroundRepeat->y);
		switch($퍁->index) {
		case 3:
		{
			$maxHeight = $totalHeight + $imageHeight;
		}break;
		case 0:
		{
			while($totalHeight > $backgroundPaintingBox->y) {
				$totalHeight -= $imageHeight;
			}
		}break;
		case 1:
		{
			$imageHeight = $backgroundPositioningBox->height / $computedBackgroundSize->height;
			while($totalHeight > $backgroundPaintingBox->y) {
				$totalHeight -= $imageHeight;
			}
		}break;
		case 2:
		{
			while($totalHeight > $backgroundPaintingBox->y) {
				$totalHeight -= $imageHeight;
			}
		}break;
		}
		$initialHeight = $totalHeight;
		if(_hx_equal($imageWidth / $intrinsicWidth, 1) && _hx_equal($imageHeight / $intrinsicHeight, 1)) {
			$destinationPoint = _hx_anonymous(array("x" => $totalWidth + $backgroundBox->x - $computedBackgroundPosition->x, "y" => $totalHeight + $backgroundBox->y - $computedBackgroundPosition->y));
			$intWidth = $intrinsicWidth;
			$intHeight = $intrinsicHeight;
			$box = _hx_anonymous(array("x" => $backgroundPaintingBox->x - $computedBackgroundPosition->x, "y" => $backgroundPaintingBox->y - $computedBackgroundPosition->y, "width" => $backgroundPaintingBox->width, "height" => $backgroundPaintingBox->height));
			while($totalHeight < $maxHeight) {
				$graphicContext->copyPixels($resource->nativeResource, $box, $destinationPoint);
				$totalWidth += $imageWidth;
				if($totalWidth >= $maxWidth) {
					$totalWidth = $initialWidth;
					$totalHeight += $imageHeight;
				}
				$destinationPoint->x = $totalWidth + $backgroundBox->x - $computedBackgroundPosition->x;
				$destinationPoint->y = $totalHeight + $backgroundBox->y - $computedBackgroundPosition->y;
			}
		} else {
			$matrix = new cocktail_core_geom_Matrix(null);
			$backgroundPaintingBox->x += $backgroundBox->x;
			$backgroundPaintingBox->y += $backgroundBox->y;
			while($totalHeight < $maxHeight) {
				$matrix->identity();
				$matrix->translate($totalWidth + $backgroundBox->x, $totalHeight + $backgroundBox->y);
				$matrix->scale($imageWidth / $intrinsicWidth, $imageHeight / $intrinsicHeight);
				$graphicContext->drawImage($resource->nativeResource, $matrix, $backgroundPaintingBox);
				$totalWidth += $imageWidth;
				if($totalWidth >= $maxWidth) {
					$totalWidth = $initialWidth;
					$totalHeight += $imageHeight;
				}
			}
		}
	}
	static function drawBackgroundGradient($graphicContext, $style, $gradientValue, $backgroundBox, $backgroundPosition, $backgroundSize, $backgroundOrigin, $backgroundClip, $backgroundRepeat, $backgroundImage) {
		$computedGradientStyles = cocktail_core_style_computer_BackgroundStylesComputer::computeIndividualBackground($style, $backgroundBox, null, null, null, $backgroundPosition, $backgroundSize, $backgroundOrigin, $backgroundClip, $backgroundRepeat, $backgroundImage);
	}
	function __toString() { return 'cocktail.core.background.BackgroundManager'; }
}
function cocktail_core_background_BackgroundManager_0(&$_g, &$_g1, &$backgroundBox, &$backgroundClip, &$backgroundImage, &$backgroundOrigin, &$backgroundPosition, &$backgroundRepeat, &$backgroundSize, &$elementRenderer, &$foundResource, &$graphicContext, &$i, &$imageDeclaration, &$resource, &$style, $e) {
	{
		$elementRenderer->invalidate(cocktail_core_renderer_InvalidationReason::$backgroundImageLoaded);
	}
}
function cocktail_core_background_BackgroundManager_1(&$_g, &$_g1, &$backgroundBox, &$backgroundClip, &$backgroundImage, &$backgroundOrigin, &$backgroundPosition, &$backgroundRepeat, &$backgroundSize, &$elementRenderer, &$foundResource, &$graphicContext, &$i, &$imageDeclaration, &$resource, &$style, $e) {
	{
		$elementRenderer->invalidate(cocktail_core_renderer_InvalidationReason::$backgroundImageLoaded);
	}
}
