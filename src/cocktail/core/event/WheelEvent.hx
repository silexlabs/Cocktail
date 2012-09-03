/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The WheelEvent interface provides specific contextual information associated with omnidirectional mouse wheel events.
 * To create an instance of the WheelEvent interface, use the DocumentEvent.createEvent("WheelEvent") method call.
 * 
 * @author Yannick DOMINGUEZ
 */
class WheelEvent extends MouseEvent
{
	/**
	 * This set of constants must be used to indicate the units of measurement for the delta values.
	 * The precise measurement is specific to device, operating system, and application configurations.
	 */
	
	 /**
	  * The units of measurement 
	  * for the delta must be pixels. This is the most
	  * typical case in most operating system and implementation configurations.
	  */
	private static inline var DOM_DELTA_PIXEL:Int = 0x00;
	
	/**
	 * The units of measurement for the delta must be individual
	 * lines of text. This is the case for many form controls.
	 */
	private static inline var DOM_DELTA_LINE:Int = 0x01;
	
	/**
	 * The units of measurement for the delta must be pages
	 * , either defined as a single screen or as a demarcated page.
	 */
	private static inline var DOM_DELTA_PAGE:Int = 0x02;
	
	/**
	 * The distance the wheel has rotated around the x-axis.
	 */
	public var deltaX(default, null):Float;
	
	/**
	 * The distance the wheel has rotated around the y-axis.
	 */
	public var deltaY(default, null):Float;
	
	/**
	 * The distance the wheel has rotated around the z-axis.
	 */
	public var deltaZ(default, null):Float;
	
	/**
	 * he deltaMode attribute contains an indication of to indicate the units of measurement for the delta values.
	 * The default value is DOM_DELTA_PIXEL (pixels).
	 * The value of deltaMode may be different for each
	 * of deltaX, deltaY, and deltaZ, based on system configuration.
	 */
	public var deltaMode(default, null):Int;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of a WheelEvent object. 
	 * This method has the same behavior as MouseEvent.initMouseEvent().
	 * 
	 * TODO 4 : modifiersListArg is different form MouseEvent signature
	 * 
	 * @param	typeArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	canBubbleArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	cancelableArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	viewArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	detailArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	screenXArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	screenYArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	clientXArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	clientYArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	buttonArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	relatedTargetArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	modifiersListArg Refer to the MouseEvent.initMouseEvent() method for a description of this parameter.
	 * @param	deltaXArg Specifies WheelEvent.deltaX.
	 * @param	deltaYArg Specifies WheelEvent.deltaY.
	 * @param	deltaZArg Specifies WheelEvent.deltaZ.
	 * @param	deltaModeArg Specifies WheelEvent.deltaMode.
	 */
	public function initWheelEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, detailArg:Float,
	screenXArg:Int, screenYArg:Int, clientXArg:Int, clientYArg:Int, buttonArg:Int, relatedTargetArg:EventTarget,
	modifiersListArg:String, deltaXArg:Float, deltaYArg:Float, deltaZArg:Float, deltaModeArg:Int ):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initMouseEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg,
		false, false, false, false, buttonArg, relatedTargetArg);
		
		deltaY = deltaYArg;
		deltaX = deltaXArg;
		deltaMode = deltaModeArg;
		deltaZ = deltaZArg;
	}
}