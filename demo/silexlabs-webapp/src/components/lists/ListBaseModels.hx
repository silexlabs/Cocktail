/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package components.lists;

/**
 * The class defines the models used by the RichList
 * 
 * @author Raphael Harmel
 */

/**
 * Defines a cell model
 */
typedef CellModel =
{
	public var content:Dynamic;
	public var action:String;
	public var actionTarget:Dynamic;
}

/**
 * Defines a rich list model
 */
typedef ListModel =
{
	public var content:Array<CellModel>;
}


//typedef ListModel = Array<CellModel>;

/**
 * Defines a rich list style model
 */
/*typedef RichListStyleModel =
{
	public var list:DOMElement->Void;
	public var cell:ContainerDOMElement->Void;
	public var cellImage:DOMElement->Void;
	public var cellText:DOMElement->Void;
	public var cellMouseOver:ContainerDOMElement->Void;
	public var cellMouseOut:ContainerDOMElement->Void;
	public var cellMouseDown:ContainerDOMElement->Void;
	public var cellMouseUp:ContainerDOMElement->Void;
}*/
