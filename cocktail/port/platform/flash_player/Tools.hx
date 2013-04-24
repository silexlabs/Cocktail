package cocktail.port.platform.flash_player;

/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
class Tools
{
	
	/**
	* when the mouse event target is not the hit testing sprite (might be a text field for instance),
	* convert the mouse event point on the space of the hit testing sprite
	*/
	public static function convertToHitTestingSpriteSpace(point:flash.geom.Point, target:flash.display.DisplayObject, hitTestingSprite:flash.display.DisplayObject):flash.geom.Point
	{
		if (target == hitTestingSprite)
		{
			return point;
		}

		point.x += target.x;
		point.y += target.y;

		var parent:flash.display.DisplayObjectContainer = target.parent;
		while (parent != hitTestingSprite)
		{
			point.x += parent.x;
			point.y += parent.y;

			parent = parent.parent;

			if (parent == null)
			{
				return point;
			}
		}

		return point;
	}

}