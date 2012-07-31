package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSRule 
{

	public static inline var STYLE_RULE:Int = 1;
	
	public static inline var IMPORT_RULE:Int = 3;
	
	public static inline var MEDIA_RULE:Int = 4;
	
	public static inline var FONT_FACE_RULE:Int = 5;
	
	public static inline var NAMESPACE_RULE:Int = 10;
	
	public var type(default, null):Int;
	
	public var cssText:String;
	
	public var parentRule(default, null):CSSRule;
	
	public var parentStyleSheet(default, null):CSSStyleSheet;
	
	public function new() 
	{
		
	}
	
}