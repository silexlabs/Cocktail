<?php

class cocktail_port_platform_nativeMedia_NativeMedia {
	public function __construct() {
		;
	}
	public function set_viewport($value) {
		return $this->viewport = $value;
	}
	public function get_viewport() {
		return $this->viewport;
	}
	public function set_volume($value) {
		return $value;
	}
	public function set_src($value) {
		return $value;
	}
	public function get_duration() {
		return 0;
	}
	public function get_nativeElement() {
		return null;
	}
	public function get_width() {
		return null;
	}
	public function get_height() {
		return null;
	}
	public function get_currentTime() {
		return 0;
	}
	public function get_bytesLoaded() {
		return 0;
	}
	public function get_bytesTotal() {
		return 0;
	}
	public function onNativeLoadedMetaData() {
		if($this->onLoadedMetaData !== null) {
			$loaddedMetadataEvent = new cocktail_core_event_Event();
			$loaddedMetadataEvent->initEvent("loadedmetadata", false, false);
			$this->onLoadedMetaData($loaddedMetadataEvent);
		}
	}
	public function attach($graphicsContext) {
	}
	public function canPlayType($type) {
		return null;
	}
	public function seek($time) {
	}
	public function pause() {
	}
	public function play() {
	}
	public $viewport;
	public $onLoadedMetaData;
	public $bytesTotal;
	public $bytesLoaded;
	public $nativeElement;
	public $currentTime;
	public $height;
	public $width;
	public $src;
	public $volume;
	public $duration;
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
	static $__properties__ = array("get_duration" => "get_duration","set_volume" => "set_volume","set_src" => "set_src","get_width" => "get_width","get_height" => "get_height","get_currentTime" => "get_currentTime","get_nativeElement" => "get_nativeElement","get_bytesLoaded" => "get_bytesLoaded","get_bytesTotal" => "get_bytesTotal","set_viewport" => "set_viewport","get_viewport" => "get_viewport");
	function __toString() { return 'cocktail.port.platform.nativeMedia.NativeMedia'; }
}
