package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CascadeManager 
{

	public var propertiesToCascade(default, null):Array<String>;
	
	public var cascadeAll(default, null):Bool;
	
	public var hasPropertiesToCascade(default, null):Bool;
	
	public var hasFontSize(default, null):Bool;
	
	public var hasFontFamily(default, null):Bool;
	
	public var hasBackgroundColor(default, null):Bool;
	
	public var hasColor(default, null):Bool;
	
	public var hasDisplay(default, null):Bool;
	
	public var hasFloat(default, null):Bool;
	
	public var hasOverflowX(default, null):Bool;
	
	public var hasOverflowY(default, null):Bool;
	
	public var hasTransform(default, null):Bool;
	
	public var hasZIndex(default, null):Bool;
	
	public var hasPosition(default, null):Bool;
	
	public function new() 
	{
		reset();
	}
	
	public function addPropertyToCascade(name:String):Void
	{     
		if (cascadeAll == true)
		{
			return;
		}
		
		var wasAlreadyAdded:Bool = flagProperty(name);
		if (wasAlreadyAdded == true)
		{
			return;
		}
		
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
	
	public function shouldCascadeAll():Void
	{
		cascadeAll = true;
		hasPropertiesToCascade = true;
	}
	
	private function flagProperty(name:String):Bool
	{
		switch(name)
		{
			case CSSConstants.FONT_SIZE:
				if (hasFontSize == false)
				{
					hasFontSize = true;
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
	
	public function reset():Void
	{
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
		
		propertiesToCascade = new Array<String>();
	}
}