/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;

/**
 * The class defines the models used by the RichList
 * 
 * @author Raphael Harmel
 */

/**
 * Defines a title model
 */
/*typedef TitleModel =
{
	public var text:String;
	public var imagePath:String;
}*/

/**
 * Defines a cell model
 */
typedef CellModel =
{
	public var text:String;
	public var imagePath:String;
	public var action:String;
	public var actionTarget:Dynamic;
}

/**
 * Defines a rich list model
 */
typedef RichListModel =
{
	//public var title:TitleModel;
	public var content:Array<CellModel>;
}

/**
 * Defines a rich list style model
 */
typedef RichListStyleModel =
{
	public var list:DOMElement->Void;
	//public var title:DOMElement->Void;
	public var cell:ContainerDOMElement->Void;
	public var cellImage:DOMElement->Void;
	public var cellMouseOver:ContainerDOMElement->Void;
	public var cellMouseOut:ContainerDOMElement->Void;
	public var cellMouseDown:ContainerDOMElement->Void;
	public var cellMouseUp:ContainerDOMElement->Void;
}
