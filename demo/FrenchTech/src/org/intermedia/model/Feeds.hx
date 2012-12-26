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
	public static inline var FEED_1:Feed = {
		id:0,
		title:"Frenchweb",
		url:"http://frenchweb.fr/feed/",
		thumb:"assets/Frenchweb-Logo-700x700.jpg",
		generatedBy:"wordpress"
		};
	/*public static inline var FEED_1:Feed = {
		id:0,
		title:"Google High Tech",
		thumb:"assets/Frenchweb-Logo-700x700.jpg",
		url:"http://news.google.fr/news?pz=1&cf=all&ned=fr&hl=fr&topic=t&output=rss",
		generatedBy:"google"
		};*/
	public static inline var FEED_2:Feed = {
		id:1,
		title:"Techcrunch",
		thumb:"assets/techcrunch-logo.png",
		url:"http://fr.techcrunch.com/feed/",
		generatedBy:"wordpress"
		};
/*	public static inline var FEED_3:Feed = {
		id:2,
		title:"SiliconSentier",
		thumb:"assets/Silicon-Sentier.jpg"
		url:"http://siliconsentier.org/feed/",
		generatedBy:"wordpress";
		};*/
	public static inline var FEED_3:Feed = {
		id:2,
		title:"01net",
		thumb:"assets/01net-logo.jpg",
		url:"http://www.01net.com/rss/actus.xml",
		generatedBy:"wordpress"
		};
}