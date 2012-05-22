package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import flash.Lib;
import flash.text.TextField;
import flash.text.TextFieldType;
import flash.text.TextFormat;
import cocktail.core.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextInputRenderer extends EmbeddedBoxRenderer
{

	private var _nativeTextField:TextField;
	
		/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "typewriter";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	public function new(node:Node) 
	{
		super(node);
		
		_nativeTextField = new TextField();
		
	}
	
	override private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		updateNativeTextField();
		graphicContext.addChild(_nativeTextField);
	}
	
	private function updateNativeTextField():Void
	{
		_nativeTextField.type = TextFieldType.INPUT;
		_nativeTextField.x = globalBounds.x;
		_nativeTextField.y = globalBounds.y + globalBounds.height / 2;
		_nativeTextField.width = globalBounds.width;
		_nativeTextField.height = globalBounds.height;
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(computedStyle.fontFamily);
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		textFormat.size = computedStyle.fontSize;
		
		var bold:Bool;
		
		switch (computedStyle.fontWeight)
		{
			case lighter, FontWeight.normal,
			css100, css200, css300, css400:
				bold = false;
				
			case FontWeight.bold, bolder, css500, css600,
			css700, css800, css900:
				bold = true;
		}
		
		textFormat.bold = bold;
		textFormat.italic = computedStyle.fontStyle == FontStyle.italic;
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		
		textFormat.color = computedStyle.color.color;
		
		_nativeTextField.setTextFormat(textFormat);
		
	}
	
	private function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String = value[i];
			
			switch (fontName)
			{
				case SERIF_GENERIC_FONT_NAME:
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_GENERIC_FONT_NAME:
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_GENERIC_FONT_NAME:
					fontName = MONOSPACE_FLASH_FONT_NAME;
			}
			
			fontFamily += fontName;
			
			if (i < value.length - 1)
			{
				fontFamily += ",";
			}
		}
		
		return fontFamily;
	}
	
	
}