<?php

class cocktail_core_drawing_AbstractDrawingManager {
	public function __construct($width, $height) {
		if(!php_Boot::$skip_constructor) {
		$this->_width = $width;
		$this->_height = $height;
	}}
	public function toNativeJointStyle($genericJointStyle) {
		return null;
	}
	public function toNativeCapStyle($genericCapStyle) {
		return null;
	}
	public function toNativeRatio($genericRatio) {
		return null;
	}
	public function toNativeColor($genericColor) {
		return null;
	}
	public function toNativeAlpha($genericAlpa) {
		return null;
	}
	public function get_nativeBitmapData() {
		return null;
	}
	public function curveTo($controlX, $controlY, $x, $y) {
	}
	public function moveTo($x, $y) {
	}
	public function lineTo($x, $y) {
	}
	public function fillRect($rect, $color) {
	}
	public function copyPixels($bitmapData, $sourceRect, $destPoint) {
	}
	public function drawImage($bitmapData, $matrix = null, $sourceRect = null) {
	}
	public function drawEllipse($x, $y, $width, $height) {
		$xRadius = $width / 2;
		$yRadius = $height / 2;
		$xCenter = $width / 2 + $x;
		$yCenter = $height / 2 + $y;
		$angleDelta = Math::$PI / 4;
		$xCtrlDist = $xRadius / Math::cos($angleDelta / 2);
		$yCtrlDist = $yRadius / Math::cos($angleDelta / 2);
		$this->moveTo($xCenter + $xRadius, $yCenter);
		$angle = 0;
		$rx = null; $ry = null; $ax = null; $ay = null;
		{
			$_g = 0;
			while($_g < 8) {
				$i = $_g++;
				$angle += $angleDelta;
				$rx = $xCenter + Math::cos($angle - $angleDelta / 2) * $xCtrlDist;
				$ry = $yCenter + Math::sin($angle - $angleDelta / 2) * $yCtrlDist;
				$ax = $xCenter + Math::cos($angle) * $xRadius;
				$ay = $yCenter + Math::sin($angle) * $yRadius;
				$this->curveTo($rx, $ry, $ax, $ay);
				unset($i);
			}
		}
	}
	public function drawRect($x, $y, $width, $height, $cornerRadiuses = null) {
		if($cornerRadiuses === null) {
			$cornerRadiuses = _hx_anonymous(array("tlCornerRadius" => 0, "trCornerRadius" => 0, "blCornerRadius" => 0, "brCornerRadius" => 0));
		}
		$this->moveTo($cornerRadiuses->tlCornerRadius + $x, $y);
		$this->lineTo($width - $cornerRadiuses->trCornerRadius + $x, $y);
		$this->curveTo($width + $x, $y, $width + $x, $cornerRadiuses->trCornerRadius + $y);
		$this->lineTo($width + $x, $cornerRadiuses->trCornerRadius + $y);
		$this->lineTo($width + $x, $height - $cornerRadiuses->brCornerRadius + $y);
		$this->curveTo($width + $x, $height + $y, $width - $cornerRadiuses->brCornerRadius + $x, $height + $y);
		$this->lineTo($width - $cornerRadiuses->brCornerRadius + $x, $height + $y);
		$this->lineTo($cornerRadiuses->blCornerRadius + $x, $height + $y);
		$this->curveTo($x, $height + $y, $x, $height - $cornerRadiuses->blCornerRadius + $y);
		$this->lineTo($x, $height - $cornerRadiuses->blCornerRadius + $y);
		$this->lineTo($x, $cornerRadiuses->tlCornerRadius + $y);
		$this->curveTo($x, $y, $cornerRadiuses->tlCornerRadius + $x, $y);
		$this->lineTo($cornerRadiuses->tlCornerRadius + $x, $y);
	}
	public function setFillStyle($fillStyle) {
	}
	public function setLineStyle($lineStyle) {
	}
	public function clear() {
	}
	public function endFill() {
	}
	public function beginFill($fillStyle = null, $lineStyle = null) {
		if($fillStyle === null) {
			$fillStyle = cocktail_core_drawing_FillStyleValue::$none;
		}
		if($lineStyle === null) {
			$lineStyle = cocktail_core_drawing_LineStyleValue::$none;
		}
		$this->setFillStyle($fillStyle);
		$this->setLineStyle($lineStyle);
	}
	public $_height;
	public $_width;
	public $nativeBitmapData;
	public $nativeElement;
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
	static $__properties__ = array("get_nativeBitmapData" => "get_nativeBitmapData");
	function __toString() { return 'cocktail.core.drawing.AbstractDrawingManager'; }
}
