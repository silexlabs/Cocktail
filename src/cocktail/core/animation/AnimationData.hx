/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.animation;

import cocktail.core.renderer.RendererData;

/**
 * Animation and transition struct
 * 
 * @author Yannick DOMINGUEZ
 */
	
/**
 * Holds all the data necessary to start a transition.
 * It it said to be a pending animation, as it is stored
 * when the value of a CSS property changes, but the animation
 * is actually started on next layout
 */
class PendingAnimationVO {
	public var propertyName:String;
	public var startValue:Float;
	public function new():Void
	{
		
	}
}

/**
 * Contain an array of all the transitions registered
 * for a given CSS property name
 */
class TransitionsVO {
	/**
	 * every transition for the property name
	 */
	public var transitions:Array<Transition>;
	
	/**
	 * The name of the transitioned CSS style
	 */
	public var propertyName:String;
	
	public function new():Void
	{
		
	}
}