package cocktail.port.browser;
import cocktail.core.style.adapter.AbstractStyle;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Style extends AbstractStyle
{

	public function new(coreStyle:CoreStyle) 
	{
		super(coreStyle);
	}
	
	/////////////////////////////////
	// UTIL METHOD
	////////////////////////////////
	
	/**
	 * For CSS styles not yet available across browser, find
	 * the vendor specific style name to use. Might return
	 * null if no style was found
	 * @param	nativeStyle the JavaScript Style object
	 */
	private function getVendorSpecificStyleName(nativeStyle:Dynamic, styleName:String):String
	{
		var vendorSpecificStyleName:String;
		
		//first check if the standard style exists
		if (Reflect.hasField(nativeStyle, styleName))
		{
			vendorSpecificStyleName = styleName;
		}
		else
		{
			//capitalise the style name to respect camel case
			//convention
			var styleNameCap:String = styleName.charAt(0).toUpperCase();
			var styleNameEnd:String = styleName.substr(1);
			styleName = styleNameCap + styleNameEnd;
			
			//firefox
			if (Reflect.field(nativeStyle, "Moz" + styleName) != null)
			{
				vendorSpecificStyleName = "Moz" + styleName;
			}
			//webkit (chrome, safari...)
			else if (Reflect.field(nativeStyle, "Webkit" + styleName) != null)
			{
				vendorSpecificStyleName = "Webkit" + styleName;
			}
			//ie
			else if (Reflect.field(nativeStyle, "Ms" + styleName) != null)
			{
				vendorSpecificStyleName = "Ms" + styleName;
			}
			//opera
			else if (Reflect.field(nativeStyle, "O" + styleName) != null)
			{
				vendorSpecificStyleName = "O" + styleName;
			}
			else
			{
				vendorSpecificStyleName = null;
			}
		}
		
		return vendorSpecificStyleName;
	}
	
	/////////////////////////////////
	// OVERRIDEN STYLES SETTERS
	// All methods convert the Style
	// value into a CSS style value
	// (as a String) and set the native
	// CSS style on the HTMLElement's
	// NativeElement
	////////////////////////////////
	
	override private function set_verticalAlign(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.verticalAlign = value;
		super.set_verticalAlign(value);
		return value;
	}
	
	override private function set_color(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.color = value;
		super.set_color(value);
		return value;
	}
	
	override private function set_wordSpacing(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.wordSpacing = value;
		super.set_wordSpacing(value);
		return value;
	}
	
	override private function set_letterSpacing(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.letterSpacing = value;
		super.set_letterSpacing(value);
		return value;
	}
	
	override private function set_textTransform(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.textTransform = value;
		super.set_textTransform(value);
		return value;
	}
	
	override private function set_fontVariant(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.fontVariant = value;
		super.set_fontVariant(value);
		return value;
	}
	
	override private function set_fontFamily(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.fontFamily = value;
		super.set_fontFamily(value);
		return value;
	}
	
	override private function set_fontWeight(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.fontWeight = value;
		super.set_fontWeight(value);
		return value;
	}
	
	override private function set_fontStyle(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.fontStyle = value;
		super.set_fontStyle(value);
		return value;
	}
	
	override private function set_fontSize(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.fontSize = value;
		super.set_fontSize(value);
		return value;
	}
	
	override private function set_lineHeight(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.lineHeight = value;
		super.set_lineHeight(value);
		return value;
	}
	
	override private function set_marginLeft(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.marginLeft = value;
		super.set_marginLeft(value);
		return value;
	}
	
	override private function set_marginRight(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.marginRight = value;
		super.set_marginRight(value);
		return value;
	}
	
	override private function set_marginTop(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.marginTop = value;
		super.set_marginTop(value);
		return value;
	}
	
	override private function set_marginBottom(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.marginBottom = value;
		super.set_marginBottom(value);
		return value;
	}
	
	override private function set_paddingLeft(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.paddingLeft = value;
		super.set_paddingLeft(value);
		return value;
	}
	
	override private function set_paddingRight(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.paddingRight = value;
		super.set_paddingRight(value);
		return value;
	}
	
	override private function set_paddingTop(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.paddingTop = value;
		super.set_paddingTop(value);
		return value;
	}
	
	override private function set_paddingBottom(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.paddingBottom = value;
		super.set_paddingBottom(value);
		return value;
	}
	
	override private function set_display(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.display = value;
		super.set_display(value);
		return value;
	}
	
	override private function set_position(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.position = value;
		super.set_position(value);
		return value;
	}
	
	override private function set_width(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.width = value;
		super.set_width(value);
		return value;
	}
	
	override private function set_height(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.height = value;
		super.set_height(value);
		return value;
	}
	
	override private function set_minHeight(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.minHeight = value;
		super.set_minHeight(value);
		return value;
	}
	
	override private function set_maxHeight(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.maxHeight = value;
		super.set_maxHeight(value);
		return value;
	}
	
	override private function set_minWidth(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.minWidth = value;
		super.set_minWidth(value);
		return value;
	}
	
	override private function set_maxWidth(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.maxWidth = value;
		super.set_maxWidth(value);
		return value;
	}
	
	override private function set_top(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.top = value;
		super.set_top(value);
		return value;
	}
	
	override private function set_left(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.left = value;
		super.set_left(value);
		return value;
	}
	
	override private function set_bottom(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.bottom = value;
		super.set_bottom(value);
		return value;
	}
	
	override private function set_right(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.right = value;
		super.set_right(value);
		return value;
	}
	
	override private function set_textIndent(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.textIndent = value;
		super.set_textIndent(value);
		return value;
	}
	
	override private function set_CSSFloat(value:String):String 
	{
		untyped _coreStyle.htmlElement.nativeElement.style.cssFloat = value;
		super.set_CSSFloat(value);
		return value;
	}
	
	override private function set_clear(value:String):String 
	{
		_coreStyle.htmlElement.nativeElement.style.clear = value;
		super.set_clear(value);
		return value;
	}
	
	override private function set_whiteSpace(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.whiteSpace = value;
		super.set_whiteSpace(value);
		return value;
	}
	
	override private function set_textAlign(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.textAlign = value;
		super.set_textAlign(value);
		return  value;
	}
	
	override private function set_opacity(value:String):String
	{
		untyped _coreStyle.htmlElement.nativeElement.style.opacity = value;
		super.set_opacity(value);
		return value;
	}
	
	override private function set_visibility(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.visibility = value;
		super.set_visibility(value);
		return value;
	}
	
	override private function set_backgroundColor(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.backgroundColor = value;
		super.set_backgroundColor(value);
		return value;
	}
	
	override private function set_backgroundOrigin(value:String):String
	{
		var nativeStyle:Dynamic = _coreStyle.htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundOrigin");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , value);
		}
		
		super.set_backgroundOrigin(value);
		return value;
	}
	
	override private function set_backgroundClip(value:String):String
	{
		var nativeStyle:Dynamic = _coreStyle.htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundClip");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , value);
		}
		
		super.set_backgroundClip(value);
		return value;
	}
	
	override private function set_backgroundImage(value:String):String
	{
		var cssBackgroundImage:String = value;
		
		//as gradient are not standard yet in CSS, the property has to be applied with each vendor speicific prefix, only the 
		//right one will be used
		_coreStyle.htmlElement.nativeElement.style.backgroundImage = cssBackgroundImage;
		_coreStyle.htmlElement.nativeElement.style.backgroundImage = StringTools.replace(cssBackgroundImage, 'linear-gradient', '-webkit-linear-gradient');
		_coreStyle.htmlElement.nativeElement.style.backgroundImage = StringTools.replace(cssBackgroundImage, 'linear-gradient', '-moz-linear-gradient');
		
		super.set_backgroundImage(value);
		return value;
	}
	
	override private function set_backgroundPosition(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.backgroundPosition = value;
		super.set_backgroundPosition(value);
		return value;
	}
	
	override private function set_backgroundSize(value:String):String
	{
		var nativeStyle:Dynamic = _coreStyle.htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundSize");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , value);
		}
		
		super.set_backgroundSize(value);
		return value;
	}
	
	override private function set_backgroundRepeat(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.backgroundRepeat = value;
		super.set_backgroundRepeat(value);
		return value;
	}
	
	override private function set_overflowX(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.overflowX = value;
		super.set_overflowX(value);
		return value;
	}
	
	override private function set_overflowY(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.overflowY = value;
		super.set_overflowY(value);
		return value;
	}
	
	override private function set_cursor(value:String):String
	{
		_coreStyle.htmlElement.nativeElement.style.cursor = value;
		super.set_cursor(value);
		return value;
	}
	
}