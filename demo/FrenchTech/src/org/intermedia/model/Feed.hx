/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia.model;

/**
 * This class the Feed Model
 * @author Raphael Harmel
 */

typedef Feed =
{
	var id:Int;
	var ressource:String;
	var thumb:String;
	var title:String;
	var url:String;
	var generatedBy:String;
}