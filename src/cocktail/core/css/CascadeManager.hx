/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

using cocktail.core.utils.Utils;

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
	 * Contains all the index of the properties which
	 * currently need cascading
	 */
	public var propertiesToCascade(default, null):Array<Int>;
	
	/**
	 * Wether all the supprted properties should be cascaded
	 */
	public var cascadeAll(default, null):Bool;
	
	/**
	 * Wether at least one property needs cascading
	 */
	public var hasPropertiesToCascade(default, null):Bool;
	
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
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		propertiesToCascade = new Array<Int>();
		reset();
	}
	
	/**
	 * Init/reset the cascade state
	 */
	public function reset():Void
	{
		if (hasPropertiesToCascade == true)
		{
			propertiesToCascade = propertiesToCascade.clear();
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
		
		//update the right if the added property match
		//a flag. If the flagged property was already
		//added, no need to add it again
		var wasAlreadyAdded:Bool = flagProperty(index);
		if (wasAlreadyAdded == true)
		{
			return;
		}
		
		//check if the property was already added
		var length:Int = propertiesToCascade.length;
		for (i in 0...length)
		{
			if (propertiesToCascade[i] == index)
			{
				return;
			}
		}
		
		propertiesToCascade.push(index);
		hasPropertiesToCascade = true;
	}
	
	/**
	 * remove a property to cascade
	 */
	public function removePropertyToCascade(index:Int):Void
	{
		var length:Int = propertiesToCascade.length;
		for (i in 0...length)
		{
			if (propertiesToCascade[i] == index)
			{
				propertiesToCascade.remove(propertiesToCascade[i]);
				//set property flag to false if needed
				deFlagProperty(index);
				break;
			}
		}
		
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
	 * @param	index the index of the property to add
	 * @return wether the property was already previously
	 * added, in which case it doesn't need to be 
	 * re-added
	 */
	private function flagProperty(index:Int):Bool
	{
		switch(index)
		{
			//check wether the property is fon-size
			case CSSConstants.FONT_SIZE:
				if (hasFontSize == false)
				{
					hasFontSize = true;
				}
				//here the property already was
				//added
				else
				{
					return true;
				}
			case CSSConstants.MARGIN_TOP:
				if (hasMarginTop == false)
				{
					hasMarginTop = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.MARGIN_BOTTOM:
				if (hasMarginBottom == false)
				{
					hasMarginBottom = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.MARGIN_LEFT:
				if (hasMarginLeft == false)
				{
					hasMarginLeft = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.MARGIN_RIGHT:
				if (hasMarginRight == false)
				{
					hasMarginRight = true; 
				}
				else
				{
					return true;
				}		
			case CSSConstants.TOP:
				if (hasTop == false)
				{
					hasTop = true; 
				}
				else
				{
					return true;
				}
			case CSSConstants.BOTTOM:
				if (hasBottom == false)
				{
					hasBottom = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.LEFT:
				if (hasLeft == false)
				{
					hasLeft = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.RIGHT:
				if (hasRight == false)
				{
					hasRight = true; 
				}
				else
				{
					return true;
				}	
			case CSSConstants.TEXT_ALIGN:	
				if (hasTextAlign == false)
				{
					hasTextAlign = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.MAX_HEIGHT:
				if (hasMaxHeight == false)
				{
					hasMaxHeight = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.MAX_WIDTH:
				if (hasMaxWidth == false)
				{
					hasMaxWidth = true;
				}
				else
				{
					return true;
				}		
			case CSSConstants.WIDTH:
				if (hasWidth == false)
				{
					hasWidth = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.HEIGHT:
				if (hasHeight == false)
				{
					hasHeight = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.CLEAR:
				if (hasClear == false)
				{
					hasClear = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.WHITE_SPACE:
				if (hasWhiteSpace == false)
				{
					hasWhiteSpace = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.BACKGROUND_IMAGE:
				if (hasBackgroundImage == false)
				{
					hasBackgroundImage = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.VERTICAL_ALIGN:
				if (hasVerticalAlign == false)
				{
					hasVerticalAlign = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.LINE_HEIGHT:
				if (hasLineHeight == false)
				{
					hasLineHeight = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.LETTER_SPACING:
				if (hasLetterSpacing == false)
				{
					hasLetterSpacing = true;
				}
				else
				{
					return true;
				}	
				
			case CSSConstants.OPACITY:
				if (hasOpacity == false)
				{
					hasOpacity = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.FONT_FAMILY:
				if (hasFontFamily == false)
				{
					hasFontFamily = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.VISIBILITY:
				if (hasVisible == false)
				{
					hasVisible = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.BACKGROUND_COLOR:
				if (hasBackgroundColor == false)
				{
					hasBackgroundColor = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.COLOR:
				if (hasColor == false)
				{
					hasColor = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.DISPLAY:
				if (hasDisplay == false)
				{
					hasDisplay = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.FLOAT:
				if (hasFloat == false)
				{
					hasFloat = true;
				}
				else
				{
					return true;
				}
			case CSSConstants.OVERFLOW_X:
				if (hasOverflowX == false)
				{
					hasOverflowX = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.OVERFLOW_Y:
				if (hasOverflowY == false)
				{
					hasOverflowY = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.TRANSFORM:
				if (hasTransform == false)
				{
					hasTransform = true;
				}
				else
				{
					return true;
				}	
			case CSSConstants.Z_INDEX:
				if (hasZIndex == false)
				{
					hasZIndex = true;
				}
				else
				{
					return true;
				}		
			case CSSConstants.POSITION:
				if (hasPosition == false)
				{
					hasPosition = true;
				}
				else
				{
					return true;
				}		
		}
		
		return false;
	}
	
	/**
	 * if the removed proeprty has an associated flag,
	 * set it to false
	 */
	private function deFlagProperty(index:Int):Void
	{
		switch(index)
		{
			case CSSConstants.COLOR:
				hasColor = false;
				
			case CSSConstants.FONT_SIZE:
				hasFontSize = false;	
				
			case CSSConstants.FONT_FAMILY:
				hasFontFamily = false;
				
			default:	
		}
	}
}