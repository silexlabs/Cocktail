/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The DocumentEvent interface provides a mechanism by which
 * the user can create an Event object of a type supported by
 * the implementation. If the feature “Events”
 * is supported by the Document object, the DocumentEvent
 * interface must be implemented on the same object.
 * Language-specific type casting may be required.
 * 
 * @author Yannick DOMINGUEZ
 */
interface IDocumentEvent 
{
	/**
	 * Creates an event object of the type specified. 
	 * 
	 * @param	eventInterface The eventInterface parameter specifies the name of the DOM Events
	 * interface to be supported by the created event object, e.g., "Event", "MouseEvent", "UIEvent",
	 * and so on. If the Event is to be dispatched via the EventTarget.dispatchEvent()
	 * method, the appropriate event initialization method must
	 * be called after creation in order to initialize the Event's values.
	 * 
	 * If the parameter does not match an event interface name supported
	 * by the implementation, the implementation must raise a NOT_SUPPORTED_ERR
	 * DOMException
	 * 
	 * @return The newly created event object.
	 */
	function createEvent(eventInterface:String):Event;
}