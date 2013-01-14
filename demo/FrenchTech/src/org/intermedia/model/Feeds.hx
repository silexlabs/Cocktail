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
 * This class contains the different feeds urls
 * @author Raphael Harmel
 */

class Feeds 
{
	public static inline var FEED_QTY:Int = 3;
	
	public static inline var FEED_1:Feed = {
		id:0,
		ressource:"feed1",
		title:"iPhon.fr",
		thumb:"assets/iphon_fr-logo.jpg",
		//url:"http://feeds.feedburner.com/IphonfrBlogIphone",
		url:"http://www.iphon.fr/feed/rss2",
		generatedBy:"wordpress"
		};
	public static inline var FEED_2:Feed = {
		id:1,
		ressource:"feed2",
		title:"FrAndroid",
		thumb:"assets/frandroid-logo.png",
		//url:"http://feeds.feedburner.com/Frandroid",
		url:"http://www.frandroid.com/feed",
		generatedBy:"wordpress"
		};
	public static inline var FEED_3:Feed = {
		id:2,
		ressource:"feed3",
		title:"frenchiPhone",
		thumb:"assets/frenchiphone-logo.png",
		//url:"http://feeds.feedburner.com/IphoneFranceFrFrenchiphone",
		url:"http://www.frenchiphone.com/feed/",
		generatedBy:"wordpress"
		};
}