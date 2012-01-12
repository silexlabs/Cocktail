/**
 * This class defines the style used by the gallery
 * 
 * @author Raphael Harmel
 */

package components.gallery;

// DOM
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
//import cocktailCore.style.StyleData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

class StyleGallery 
{

	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.staticStyle;
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.width = DimensionStyleValue.autoValue;

		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		//domElement.style.position = PositionStyleValue.relative;
		domElement.style.display = DisplayStyleValue.inlineBlock;
		
		//domElement.style.marginTop = MarginStyleValue.length(px(4));
		//domElement.style.marginLeft = MarginStyleValue.length(px(4));
//
		//domElement.style.width = DimensionStyleValue.length(px(75));
		//domElement.style.height = DimensionStyleValue.length(px(75));
	}
	
	/**
	 * Defines thumbnails Style
	 * 
	 * @param	domElement
	 */
	public static function getThumbStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.relative;
		
		domElement.style.marginTop = MarginStyleValue.length(px(4));
		domElement.style.marginLeft = MarginStyleValue.length(px(4));

		domElement.style.width = DimensionStyleValue.length(px(75));
		domElement.style.height = DimensionStyleValue.length(px(75));
	}
	
	/**
	 * Defines full-size picture Style
	 * 
	 * @param	domElement
	 */
	public static function getFullSizePictureStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.staticStyle;
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.height = DimensionStyleValue.percent(200);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}
	
	
}