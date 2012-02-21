/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

// DOM
import cocktail.classInstance.ClassInstance;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.resource.ResourceLoaderManager;
import cocktail.textElement.TextElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList specific
import components.lists.ListBaseModels;
import components.lists.RichListModels;
import components.lists.RichListUtils;

import cocktail.keyboard.KeyboardData;


/**
 * RichList class defines a list in which each cell can be composed of a text and an image
 * 
 * @author Raphael Harmel
 */
class RichList extends ListBase
{
	// Defines onChange callback, to be called when a new cell is selected
	/*public var onChange : CellModel->Void;
	
	// list data
	private var _listData:Array<CellModel>;
	
	// current cell index
	private var _currentCellIndex:Int;
	
	// selected cell data
	private var _selectedCellData:CellModel;
	
	// selected cell DOM
	private var _selectedCellDOM:ContainerDOMElement;*/
	
	/**
	 * constructor
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 * @param	firstElement	first element to be placed in the cell (test or image)
	 */
	public function new(list:ListModel, listStyle:Dynamic)
	{
		/*// init richlist data
		_listData = richListModel.content;
		// init _currentCellIndex
		_currentCellIndex = 0;
		// init _selectedCell
		_selectedCellData = _listData[_currentCellIndex];
		
		// create a ul node
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("ul")));
		createRichListDOM(richListModel, listStyle);
		//RichListStyle.getDefaultStyle(this);
		listStyle.list(this);
		
		//_selectedCellDOM = _selectedCellDOM;*/
		
		super(list, listStyle);
	}
	
	/**
	 * Create the list DOM with provided data (title & cells) and style (title and cells)
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 */
	/*private function createRichListDOM(richListModel:RichListModel, listStyle:RichListStyleModel):Void
	{
		this.onKeyDown = onListKeyDown;
		
		// set list's cell content
		var content:ContainerDOMElement = Utils.getContainer();
		
		// set list's cells
		var cellData:CellModel;
		for (cellData in richListModel.content)
		{
			// create cell with text and image
			// empty cell part
			var cell:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));

			// image part
			if (cellData.imagePath != "" && cellData.imagePath != null)
			{
				var cellImage:ImageDOMElement = new ImageDOMElement();
				// set image style
				listStyle.cellImage(cellImage);
				// add image
				cell.addChild(cellImage);
				// load image
				cellImage.load(cellData.imagePath);
			}
			
			// add text
			var cellTextContainer:ContainerDOMElement = Utils.getContainer();
			if (cellData.text != "" && cellData.text != null)
			{
				var textElement:TextElement = new TextElement(cellData.text);
				cellTextContainer.addText(textElement);
				listStyle.cellText(cellTextContainer);
				cell.addChild(cellTextContainer);
			}

			// add cell to instance
			this.addChild(cell);
			
			listStyle.cell(cell);
			
			// mouse
			// delegates functions are used to be able to pass an extra parameters to the callback
			// mouse over
			var onCellMouseOverDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOver;
			cell.onMouseOver = function(mouseEventData:MouseEventData) { onCellMouseOverDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse out
			var onCellMouseOutDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOut;
			cell.onMouseOut = function(mouseEventData:MouseEventData) { onCellMouseOutDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse down
			var onCellMouseDownDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseDown;
			cell.onMouseDown = function(mouseEventData:MouseEventData) { onCellMouseDownDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse up
			var onCellMouseUpDelegate:ContainerDOMElement->CellModel->Void = onCellSelected;
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(cellTextContainer, cellData); };
			
		}
	}
	
	/**
	 * Cell mouse roll over callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	/*private function onCellMouseOver(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
	{
		listStyle.cellMouseOver(cell);
	}
	
	/**
	 * Cell mouse out callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	/*private function onCellMouseOut(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
	{
		//trace("out");
		listStyle.cellMouseOut(cell);
	}
	
	/**
	 * Cell mouse down callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	/*private function onCellMouseDown(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
	{
		listStyle.cellMouseDown(cell);
	}
	
	/**
	 * Cell mouse up callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 * @param	cellData
	 */
	//private function onCellMouseUp(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel, cellData:CellModel):Void
	//private function onCellSelected(cell:ContainerDOMElement, listStyle:RichListStyleModel, cellData:CellModel):Void
	/*private function onCellSelected(cell:ContainerDOMElement, cellData:CellModel):Void
	{
		//listStyle.cellMouseUp(cell);
		if (onChange != null)
		{
			onChange(cellData);
		}
		_selectedCellDOM = cell;
	}
	
	/**
	 * Cell keyboard down callback
	 * 
	 * @param	key
	 */
	/*private function onListKeyDown(key:KeyEventData):Void
	{
		if (key.value == KeyboardKeyValue.right)
		{
			selectNextCell();
		}
		else if (key.value == KeyboardKeyValue.left)
		{
			selectPreviousCell();
		}
		else if (key.value == KeyboardKeyValue.enter)
		{
			selectCell(this._children[_currentCellIndex].child);
			onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
	}

	/**
	 * Select the cell and add a selected image to it
	 */
	//private function selectCell(cell:ContainerDOMElement, listStyle:Dynamic):Void
	/*private function selectCell(cell:ContainerDOMElement):Void
	{
		_selectedCellDOM = cell;
		//_selectedCellData = list.content[_currentCellIndex];

	}
	
	/**
	 * Selects next cell
	 */
	/*private function selectNextCell()
	{
		//trace(this._children.length);
		
		if(_currentCellIndex < this._children.length-1)
		{
			_currentCellIndex++;
			//selectCell(this._children[_currentCellIndex].child);
			//onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
		
	}
	
	/**
	 * Selects previous cell
	 */
	/*private function selectPreviousCell()
	{
		//trace("selectPreviousCell");

		if(_currentCellIndex > 0)
		{
			_currentCellIndex--;
			//selectCell(this._children[_currentCellIndex].child);
			//onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
	}*/	/**
	 * Create the list DOM with provided data and style
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	override function createListDOM(list:ListModel, listStyle:Dynamic):Void
	{
		super.createListDOM(list, listStyle);
		
		this.onKeyDown = onListKeyDown;
	}
	
	/**
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	override private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<DOMElement>
	{
		var cellContent:Array<DOMElement> = new Array<DOMElement>();
		
		// THUMBNAIL
		
		// image part
		/*if (cellData.icon != "" && cellData.icon != null)
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
		
		return cellContent;*/
		
		
		/*for (cellData in richListModel.content)
		{*/
			// create cell with text and image
			// empty cell part
			//var cell:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));

		// image part
		if (cellData.imagePath != "" && cellData.imagePath != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			listStyle.cellImage(cellImage);
			// add image
			//cell.addChild(cellImage);
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.imagePath);
		}
		
		// add text
		var cellTextContainer:ContainerDOMElement = Utils.getContainer();
		if (cellData.text != "" && cellData.text != null)
		{
			var textElement:TextElement = new TextElement(cellData.text);
			cellTextContainer.addText(textElement);
			listStyle.cellText(cellTextContainer);
			//cell.addChild(cellTextContainer);
			cellContent.push(cellTextContainer);
		}
			
		// LINE
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		listStyle.cellLine(line);
		cellContent.push(line);
		line.load("images/greyPixel.png");

		return cellContent;
			
			/*
			// add cell to instance
			this.addChild(cell);
			
			listStyle.cell(cell);
			
			// mouse
			// delegates functions are used to be able to pass an extra parameters to the callback
			// mouse over
			var onCellMouseOverDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOver;
			cell.onMouseOver = function(mouseEventData:MouseEventData) { onCellMouseOverDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse out
			var onCellMouseOutDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOut;
			cell.onMouseOut = function(mouseEventData:MouseEventData) { onCellMouseOutDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse down
			var onCellMouseDownDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseDown;
			cell.onMouseDown = function(mouseEventData:MouseEventData) { onCellMouseDownDelegate(mouseEventData, cellTextContainer, listStyle); };
			// mouse up
			var onCellMouseUpDelegate:ContainerDOMElement->CellModel->Void = onCellSelected;
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(cellTextContainer, cellData); };
			
		}*/

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
		//cell.addChild(_selectedMenuItemImage);
	}
	
	/**
	 * Cell keyboard down callback
	 * 
	 * @param	key
	 */
	/*override function onListKeyDown(key:KeyEventData):Void
	{
		if (key.value == KeyboardKeyValue.right)
		{
			//trace("right key pressed");
			super.selectNextCell();
		}
		else if (key.value == KeyboardKeyValue.left)
		{
			//trace("left key pressed");
			super.selectPreviousCell();
		}
		else if (key.value == KeyboardKeyValue.enter)
		{
			selectCell(this._children[_currentCellIndex].child);
			onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
	}*/
	
}
