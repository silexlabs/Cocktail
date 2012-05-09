package org.intermedia.model;

/**
 * This class contains the different feeds urls
 * @author Raphael Harmel
 */

class Feeds 
{
	public static inline var FEED_1:Feed = {
		id:0,
		title:"Techcrunch",
		url:"http://fr.techcrunch.com/feed/",
		thumb:"http://demos.silexlabs.org/cocktail/market/assets/techcrunch-logo.png"
		};	
	public static inline var FEED_2:Feed = {
		id:1,
		title:"SiliconSentier",
		url:"http://siliconsentier.org/feed/",
		thumb:"http://demos.silexlabs.org/cocktail/market/assets/Silicon-Sentier.jpg"
		};	
	public static inline var FEED_3:Feed = {
		id:2,
		title:"Frenchweb",
		url:"http://frenchweb.fr/feed/",
		thumb:"http://demos.silexlabs.org/cocktail/market/assets/Frenchweb-Logo-700x700.jpg"
		};	
}

typedef Feed =
{
	var id:Int;
	var title:String;
	var url:String;
	var thumb:String;
}