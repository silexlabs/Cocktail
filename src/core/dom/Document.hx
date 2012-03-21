/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.dom;

/**
 * The Document interface represents the entire HTML or XML document.
 * Conceptually, it is the root of the document tree, and provides the
 * primary access to the document's data. Since elements, text nodes,
 * comments, processing instructions, etc. cannot exist outside the
 * context of a Document, the Document interface also contains the
 * factory methods needed to create these objects. The Node objects 
 * created have a ownerDocument attribute which associates them with
 * the Document within whose context they were created. 
 * 
 * TODO : implement ownerDocument ?
 * 
 * @author Yannick DOMINGUEZ
 */
class Document extends Node
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
}