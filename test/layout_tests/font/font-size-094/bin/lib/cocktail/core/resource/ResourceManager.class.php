<?php

class cocktail_core_resource_ResourceManager {
	public function __construct() { 
	}
	static $_resources;
	static function getResource($url) {
		if(cocktail_core_resource_ResourceManager::$_resources === null) {
			cocktail_core_resource_ResourceManager::$_resources = new Hash();
		}
		if(cocktail_core_resource_ResourceManager::$_resources->exists($url) === false) {
			$resource = new cocktail_core_resource_AbstractResource($url);
			cocktail_core_resource_ResourceManager::$_resources->set($url, $resource);
		}
		return cocktail_core_resource_ResourceManager::$_resources->get($url);
	}
	function __toString() { return 'cocktail.core.resource.ResourceManager'; }
}
