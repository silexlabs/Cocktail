package org.intermedia.model;

/**
 * This class contains the different feeds urls
 * @author Raphael Harmel
 */

class Feeds 
{
	/*public static inline var FEED_1_URL:String = "http://fr.techcrunch.com/feed/";	
	public static inline var FEED_2_URL:String = "http://siliconsentier.org/feed/";	
	public static inline var FEED_3_URL:String = "http://frenchweb.fr/feed/";	

	public static inline var FEED_1_TITLE:String = "Techcrunch";	
	public static inline var FEED_2_TITLE:String = "Siliconsentier";	
	public static inline var FEED_3_TITLE:String = "Frenchweb";*/
	
	public static inline var FEED_1:Feed = { id:0, title:"Techcrunch", url:"http://fr.techcrunch.com/feed/"};	
	public static inline var FEED_2:Feed = { id:1, title:"SiliconSentier", url:"http://siliconsentier.org/feed/"};	
	public static inline var FEED_3:Feed = { id:2, title:"Frenchweb", url:"http://frenchweb.fr/feed/" };	
}

typedef Feed =
{
	var id:Int;
	var title:String;
	var url:String;
}