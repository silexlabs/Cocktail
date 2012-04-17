/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// RichList specific
import components.lists.ListBase;
import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;

import cocktail.keyboard.KeyboardData;

/**
 * This class defines an app cell
 * 
 * @author Raphael Harmel
 */

class AppList extends ListBase
{

	public var _selectedMenuItemImage:ImageDOMElement;
	
	/**
	 * constructor
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	public function new(list:ListModel, listStyle:Dynamic)
	{
		// create selectedImage
		
		// add selected menu item image over the selected menu item
		_selectedMenuItemImage = new ImageDOMElement();
		// set image style
		listStyle.cellSelected(_selectedMenuItemImage);
		// load image
		_selectedMenuItemImage.load("images/selectedMenuItem.png");
		
		super(list, listStyle);
		
	}
	
	/**
	 * Create the list DOM with provided data and style
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	override function createListDOM(list:ListModel, listStyle:Dynamic):Void
	{
		super.createListDOM(list, listStyle);
		
		//this.onKeyDown = onListKeyDown;
	}
	
	/**
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	override private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<DOMElement>
	{
		//trace("getCellData");
		var cellContent:Array<DOMElement> = new Array<DOMElement>();
		
		// THUMBNAIL
		
		// image part
		if (cellData.icon != "" && cellData.icon != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			listStyle.cellIcon(cellImage);
			// add image
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.icon);
		}
		
		// TEXT
		
		// add title
		if (cellData.title != "" && cellData.title != null)
		{
			var cellTitleContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			listStyle.cellTitle(cellTitleContainer);
			cellContent.push(cellTitleContainer);
		}
		
		return cellContent;
	}
	
	/**
	 * Select the cell and add a selected image to it
	 */
	//override private function selectCell(cell:ContainerDOMElement, listStyle:Dynamic):Void
	override private function selectCell(cell:ContainerDOMElement):Void
	{
		//super.selectCell(cell, listStyle);
		super.selectCell(cell);
		
		// add image
		cell.addChild(_selectedMenuItemImage);
	}
	
	/**
	 * Cell keyboard down callback
	 * 
	 * @param	key
	 */
	//override function onListKeyDown(key:KeyEventData):Void
	override function onListKeyDown(key:Dynamic):Void
	{
		//trace(key.value);
		//if (key.value == KeyboardKeyValue.right || key.value == KeyboardKeyValue.VK_RIGHT)
		if (key.keyCode == "39")
		//if (key.value == KeyboardKeyValue.VK_RIGHT)
		{
			//trace("right key pressed");
			super.selectNextCell();
		}
		//else if (key.value == KeyboardKeyValue.left || key.value == KeyboardKeyValue.VK_LEFT)
		else if (key.keyCode == "37")
		//else if (key.value == KeyboardKeyValue.VK_LEFT)
		{
			//trace("left key pressed");
			super.selectPreviousCell();
		}
	}

}