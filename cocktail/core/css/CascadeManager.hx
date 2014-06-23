/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.css.CSSStyleData;
import cocktail.css.*;


/**
 * During cascading, an instance of this
 * clas is passed to each children in need
 * of cascading. Its goal is to keep track
 * of which properties needs to be cascaded
 * for the current child
 * 
 * @author Yannick DOMINGUEZ
 */
class CascadeManager 
{
	/**
	 * Has an item for each supported CSS properties.
	 * Each of this item is a flag determining wether
	 * the property should be cascaded
	 */
	public var propertiesToCascade(default, null):Array<Bool>;
	
	/**
	 * Wether all the supprted properties should be cascaded
	 */
	public var cascadeAll(default, null):Bool;
	
	/**
	 * Wether at least one property needs cascading
	 */
	public var hasPropertiesToCascade(default, null):Bool;
	
	/**
	 * holds the data from the parent node necessary to compute
	 * a relative length into an absolute one. Used when the current
	 * node must compute a relative length for its 'font-size', it will
	 * needs reference from its parent
	 */
	public var parentRelativeLengthReference(default, null):RelativeLengthReferenceData;
	
	/**
	 * holds the data from the currently cascaded node necessary to compute
	 * a relative length into an absolute value. For instance it holds the 
	 * computed font-size of the node, used to compute length of with a 'em' unit
	 */
	public var relativeLengthReference(default, null):RelativeLengthReferenceData;
	
	//////////////////////////////
	// flags for property which need cascading,
	// true when a property needs cascading
	
	public var hasFontSize:Bool;
	
	public var hasFontFamily:Bool;
	
	public var hasBackgroundColor:Bool;
	
	public var hasColor:Bool;
	
	public var hasDisplay:Bool;
	
	public var hasLineHeight:Bool;
	
	public var hasLetterSpacing:Bool;
	
	public var hasFloat:Bool;
	
	public var hasOverflowX:Bool;
	
	public var hasOverflowY:Bool;
	
	public var hasTransform:Bool;
	
	public var hasZIndex:Bool;
	
	public var hasPosition:Bool;
	
	public var hasVisible:Bool;
	
	public var hasOpacity:Bool;
	
	public var hasBackgroundImage:Bool;
	
	public var hasVerticalAlign:Bool;
	
	public var hasClear:Bool;
	
	public var hasWhiteSpace:Bool;
	
	public var hasWidth:Bool;
	
	public var hasHeight:Bool;
	
	public var hasMaxHeight:Bool;
	
	public var hasMaxWidth:Bool;
	
	public var hasTextAlign:Bool;
	
	public var hasTop:Bool;
	
	public var hasBottom:Bool;
	
	public var hasLeft:Bool;
	
	public var hasRight:Bool;
	
	public var hasMarginLeft:Bool;
	
	public var hasMarginTop:Bool;
	
	public var hasMarginRight:Bool;
	
	public var hasMarginBottom:Bool;
	
	public var hasTransitionProperty:Bool;
	
	public var hasLeftBorderStyle:Bool;
	
	public var hasRightBorderStyle:Bool;
	
	public var hasTopBorderStyle:Bool;
	
	public var hasBottomBorderStyle:Bool;
	
	public var hasLeftBorderColor:Bool;
	
	public var hasRightBorderColor:Bool;
	
	public var hasTopBorderColor:Bool;
	
	public var hasBottomBorderColor:Bool;
	
	public var hasOutlineStyle:Bool;
	
	public var hasOutlineColor:Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		propertiesToCascade = new Array<Bool>();
		parentRelativeLengthReference = new RelativeLengthReferenceData();
		relativeLengthReference = new RelativeLengthReferenceData();
		reset();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		propertiesToCascade = null;
	}
	
	/**
	 * Init/reset the cascade state
	 */
	public function reset():Void
	{
		if (hasPropertiesToCascade == true)
		{
			//unset all the properties flag
			for (i in 0...CSSConstants.SUPPORTED_STYLES_NUMBER)
			{
				propertiesToCascade[i] = false;
			}
		}
		
		hasFontSize = false;
		hasFontFamily = false;
		hasBackgroundColor = false;
		hasColor = false;
		hasDisplay = false;
		hasFloat = false;
		hasOverflowX = false;
		hasOverflowY = false;
		hasLetterSpacing = false;
		hasLineHeight = false;
		hasTransform = false;
		hasZIndex = false;
		hasPosition = false;
		hasVisible = false;
		hasOpacity = false;
		hasBackgroundImage = false;
		hasVerticalAlign = false;
		hasClear = false;
		hasWhiteSpace = false;
		hasWidth = false;
		hasHeight = false;
		hasMaxHeight = false;
		hasMaxWidth = false;
		hasTextAlign = false;
		hasTop = false;
		hasBottom = false;
		hasLeft = false;
		hasRight = false;
		hasMarginTop = false;
		hasMarginBottom = false;
		hasMarginLeft = false;
		hasMarginRight = false;
		hasTransitionProperty = false;
		hasLeftBorderStyle = false;
		hasTopBorderStyle = false;
		hasRightBorderStyle = false;
		hasBottomBorderStyle = false;
		hasBottomBorderColor = false;
		hasTopBorderColor = false;
		hasLeftBorderColor = false;
		hasRightBorderColor = false;
		hasOutlineStyle = false;
		hasOutlineColor = false;
		
		hasPropertiesToCascade = false;
		cascadeAll = false;
	}
	
	/**
	 * Add a property to cascade
	 */
	public function addPropertyToCascade(index:Int):Void
	{     
		//don't need to add if all properties should
		//already be updated
		if (cascadeAll == true)
		{
			return;
		}
		
		propertiesToCascade[index] = true;
		flagProperty(index);
		hasPropertiesToCascade = true;
	}
	
	/**
	 * remove a property to cascade
	 */
	public function removePropertyToCascade(index:Int):Void
	{
		unFlagProperty(index);
		propertiesToCascade[index] = false;
	}
	
	/**
	 * When called, the next cascade will update
	 * all the properties
	 */
	public function shouldCascadeAll():Void
	{
		cascadeAll = true;
		hasPropertiesToCascade = true;
	}
	
	/**
	 * Some properties have an associated flag determining
	 * wether they are set. It is used to quickly determine
	 * if they were set during cascade.
	 * 
	 * This method set the flag for the added property if
	 * needed
	 * 
	 * @param	index the index of the property to flag
	 */
	private function flagProperty(index:Int):Void
	{
		switch(index)
		{
			//check wether the property is fon-size
			case CSSConstants.FONT_SIZE:
				hasFontSize = true;
				
			case CSSConstants.MARGIN_TOP:
				hasMarginTop = true;
				
			case CSSConstants.MARGIN_BOTTOM:
				hasMarginBottom = true; 
				
			case CSSConstants.MARGIN_LEFT:
				hasMarginLeft = true;
				
			case CSSConstants.MARGIN_RIGHT:
				hasMarginRight = true; 
				
			case CSSConstants.TRANSITION_PROPERTY:
				hasTransitionProperty = true;
			
			case CSSConstants.TOP:
				hasTop = true; 	
				
			case CSSConstants.BOTTOM:
				hasBottom = true; 
				
			case CSSConstants.LEFT:
				hasLeft = true; 
				
			case CSSConstants.RIGHT:
				hasRight = true; 
				
			case CSSConstants.TEXT_ALIGN:	
				hasTextAlign = true;
				
			case CSSConstants.MAX_HEIGHT:
				hasMaxHeight = true;
				
			case CSSConstants.MAX_WIDTH:
				hasMaxWidth = true;
				
			case CSSConstants.WIDTH:
				hasWidth = true;
					
			case CSSConstants.HEIGHT:
				hasHeight = true;
				
			case CSSConstants.CLEAR:
				hasClear = true;
				
			case CSSConstants.WHITE_SPACE:
				hasWhiteSpace = true;
				
			case CSSConstants.BACKGROUND_IMAGE:
				hasBackgroundImage = true;
				
			case CSSConstants.VERTICAL_ALIGN:
				hasVerticalAlign = true;
				
			case CSSConstants.LINE_HEIGHT:
				hasLineHeight = true;
				
			case CSSConstants.LETTER_SPACING:
				hasLetterSpacing = true;
				
			case CSSConstants.OPACITY:
				hasOpacity = true;
				
			case CSSConstants.FONT_FAMILY:
				hasFontFamily = true;
				
			case CSSConstants.VISIBILITY:
				hasVisible = true;
					
			case CSSConstants.BACKGROUND_COLOR:
				hasBackgroundColor = true;
				
			case CSSConstants.COLOR:
				hasColor = true;
				
			case CSSConstants.DISPLAY:
				hasDisplay = true;
					
			case CSSConstants.FLOAT:
				hasFloat = true;
				
			case CSSConstants.OVERFLOW_X:
				hasOverflowX = true;
					
			case CSSConstants.OVERFLOW_Y:
				hasOverflowY = true;
				
			case CSSConstants.TRANSFORM:
				hasTransform = true;
					
			case CSSConstants.Z_INDEX:
				hasZIndex = true;
				
			case CSSConstants.POSITION:
				hasPosition = true;
				
			case CSSConstants.BORDER_LEFT_STYLE:
				hasLeftBorderStyle = true;
				
			case CSSConstants.BORDER_TOP_STYLE:
				hasTopBorderStyle = true;
				
			case CSSConstants.BORDER_RIGHT_STYLE:
				hasRightBorderStyle = true;
				
			case CSSConstants.BORDER_BOTTOM_STYLE:
				hasBottomBorderStyle = true;
				
			case CSSConstants.BORDER_TOP_COLOR:
				hasTopBorderColor = true;
				
			case CSSConstants.BORDER_BOTTOM_COLOR:
				hasBottomBorderColor = true;
				
			case CSSConstants.BORDER_RIGHT_COLOR:
				hasRightBorderColor = true;
				
			case CSSConstants.BORDER_LEFT_COLOR:
				hasLeftBorderColor = true;
				
			case CSSConstants.OUTLINE_STYLE:
				hasOutlineStyle = true;
				
			case CSSConstants.OUTLINE_COLOR:
				hasOutlineColor = true;
		}
	}
	
	/**
	 * if the removed proeprty has an associated flag,
	 * set it to false
	 */
	private function unFlagProperty(index:Int):Void
	{
		switch(index)
		{
			case CSSConstants.COLOR:
				hasColor = false;
				
			case CSSConstants.FONT_SIZE:
				hasFontSize = false;	
				
			case CSSConstants.FONT_FAMILY:
				hasFontFamily = false;
				
			case CSSConstants.TRANSITION_PROPERTY:
				hasTransitionProperty = false;
				
			case CSSConstants.BORDER_TOP_STYLE:
				hasTopBorderStyle = false;
				
			case CSSConstants.BORDER_RIGHT_STYLE:
				hasRightBorderStyle = false;
				
			case CSSConstants.BORDER_LEFT_STYLE:
				hasLeftBorderStyle = false;
				
			case CSSConstants.BORDER_BOTTOM_STYLE:
				hasBottomBorderStyle = false;
				
			case CSSConstants.OUTLINE_STYLE:
				hasOutlineStyle = false;
				
			default:	
		}
	}
}
