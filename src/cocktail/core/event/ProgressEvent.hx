/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * This event is used for measuring progress
 * while a resource is loaded
 * 
 * TODO 2 : to be coherent with the other event objects,
 * this one as an init method which will become
 * obsolete with the DOM4 specification which
 * uses constructor instead.
 * 
 * @author Yannick DOMINGUEZ
 */
class ProgressEvent extends Event
{
	/**
	 * Return wether the total length of the loaded
	 * resource is known
	 */
	public var lengthComputable(default, null):Bool;
	
	/**
	 * The current amount of loaded data
	 */
	public var loaded(default, null):Float;
	
	/**
	 * The total size of the loaded resource
	 */
	public var total(default, null):Float;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		lengthComputable = false;
		loaded = 0;
		total = 0;
	}
	
	/**
	 * Init the ProgressEvent, similar to initEvent
	 * on Event
	 */
	public function initProgressEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, lengthComputableArg:Bool,
	loadedArg:Float, totalArg:Float):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initEvent(eventTypeArg, canBubbleArg, cancelableArg);
		
		lengthComputable = lengthComputableArg;
		loaded = loadedArg;
		total = totalArg;
	}
	
}