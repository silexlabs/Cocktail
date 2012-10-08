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
	 * Contains all the names of the properties which
	 * currently need cascading
	 */
	public var propertiesToCascade(default, null):Array<String>;
	
	/**
	 * Wether all the supprted properties should be cascaded
	 */
	public var cascadeAll(default, null):Bool;
	
	/**
	 * Wether at least one property needs cascading
	 */
	public var hasPropertiesToCascade(default, null):Bool;
	
	/**
	 * wether the font-size property needs cascading
	 */
	public var hasFontSize(default, null):Bool;
	
	/**
	 * wether the font-family property needs cascading
	 */
	public var hasFontFamily(default, null):Bool;
	
	/**
	 * wether the background-color property needs cascading
	 */
	public var hasBackgroundColor(default, null):Bool;
	
	/**
	 * wether the color property needs cascading
	 */
	public var hasColor(default, null):Bool;
	
	/**
	 * wether the display property needs cascading
	 */
	public var hasDisplay(default, null):Bool;
	
	/**
	 * wether the float property needs cascading
	 */
	public var hasFloat(default, null):Bool;
	
	/**
	 * wether the overflow-x property needs cascading
	 */
	public var hasOverflowX(default, null):Bool;
	
	/**
	 * wether the overflow-y property needs cascading
	 */
	public var hasOverflowY(default, null):Bool;
	
	/**
	 * wether the transform property needs cascading
	 */
	public var hasTransform(default, null):Bool;
	
	/**
	 * wether the z-index property needs cascading
	 */
	public var hasZIndex(default, null):Bool;
	
	/**
	 * wether the position property needs cascading
	 */
	public var hasPosition(default, null):Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		propertiesToCascade = new Array<String>();
		reset();
	}
	
	/**
	 * Init/reset the cascade state
	 */
	public function reset():Void
	{
		if (hasPropertiesToCascade == true)
		{
			propertiesToCascade.clear();
		}
		
		hasFontSize = false;
		hasFontFamily = false;
		hasBackgroundColor = false;
		hasColor = false;
		hasDisplay = false;
		hasFloat = false;
		hasOverflowX = false;
		hasOverflowY = false;
		hasTransform = false;
		hasZIndex = false;
		hasPosition = false;
		hasPropertiesToCascade = false;
		cascadeAll = false;
	}
	
	/**
	 * Add a property to cascade
	 */
	public function addPropertyToCascade(name:String):Void
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
		var wasAlreadyAdded:Bool = flagProperty(name);
		if (wasAlreadyAdded == true)
		{
			return;
		}
		
		//check if the property was already added
		var length:Int = propertiesToCascade.length;
		for (i in 0...length)
		{
			if (propertiesToCascade[i] == name)
			{
				return;
			}
		}
		
		propertiesToCascade.push(name);
		hasPropertiesToCascade = true;
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
	 * @param	name the property to add
	 * @return wether the property was already previously
	 * added, in which case it doesn't need to be 
	 * re-added
	 */
	private function flagProperty(name:String):Bool
	{
		switch(name)
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
				
			case CSSConstants.FONT_FAMILY:
				if (hasFontFamily == false)
				{
					hasFontFamily = true;
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
}