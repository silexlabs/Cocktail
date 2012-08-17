/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

import js.Dom;
import js.Lib;

// RichList specific
import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;


/**
 * RichList class defines a list in which each cell can be composed of a text and an image
 * 
 * @author Raphael Harmel
 */
class ListBase
{
	// Defines onChange callback, to be called when a new cell is selected
	public var onChange : CellModel->Void;
	
	// list data
	private var _listData:Array<CellModel>;
	
	// current cell index
	private var _currentCellIndex:Int;
	
	// selected cell data
	private var _selectedCellData:CellModel;
	
	// selected cell DOM
	private var _selectedCellDOM:HtmlDom;
	
	private var _htmlDom:HtmlDom;
	public var htmlDom(get_htmlDom, never):HtmlDom;
	
	/**
	 * constructor
	 * 
	 * @param	list
	 * @param	listStyle
	 * @param	firstElement	first element to be placed in the cell (test or image)
	 */
	public function new(list:ListModel, listStyle:Dynamic)
	{
		// init list data
		_listData = list.content;
		// init _currentCellIndex
		_currentCellIndex = 0;
		// init _selectedCell
		_selectedCellData = _listData[_currentCellIndex];
		
		// create a ul node
		_htmlDom = Lib.document.createElement("ul");
		
		createListDOM(list, listStyle);
		listStyle.list(_htmlDom);
		
		//selectCell(_selectedCellDOM, listStyle);
		selectCell(_selectedCellDOM);
	}
	
	/**
	 * Create the list DOM with provided data and style
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	private function createListDOM(list:ListModel, listStyle:Dynamic):Void
	{
		// set list's cell content
		var content = Utils.getContainer();
		
		// set list's cells
		var cellData:CellModel;
		for (cellData in list.content)
		{
			// create cell
			var cell = createCellDOM(cellData, listStyle);
			
			// add cell to instance
			_htmlDom.appendChild(cell);
			
			// init _selectedCellDOM with first cell
			if (_currentCellIndex == 0)
				_selectedCellDOM = cell;
			
			_currentCellIndex++;
		}
		_currentCellIndex = 0;
		
		//this.onKeyDown = onListKeyDown;
	}
	
	/**
	 * Creates a cell with corresponding data
	 * 
	 * @param	cellData
	 */
	private function createCellDOM(cellData:Dynamic, listStyle:Dynamic):HtmlDom
	{
		// create cell with text and image

		// create cell
		var cell = Lib.document.createElement("li");
		
		// add link for focus
		var cellLink:Anchor = cast(Lib.document.createElement("a"));
		cellLink.style.textAlign = "left";
		cellLink.style.display = "block";
		
		// in case the cellcontent is leading to an url, set le linkdomelement href for it to be focusable
		if(cellData.action == "openUrl" || cellData.action == "goToUrl" )
		{
			cellLink.href = cellData.actionTarget;
			cellLink.target = "blank";
		}
		// if cellcontent is leading to an internal page, set mousecallback
		else
		{
			// TODO: add tabIndex to cell
			//cellLink.href = "#";
			// mouse up
			//var onCellMouseUpDelegate:MouseEventData->ContainerDOMElement->Dynamic->CellModel->Void = onCellMouseUp;
			//cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(mouseEventData, cell, listStyle, cellData); };
			//var onCellMouseUpDelegate:MouseEventData->ContainerDOMElement->CellModel->Void = onCellMouseUp;
			//cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(mouseEventData, cell, cellData); };
			var onCellMouseUpDelegate:HtmlDom->CellModel->Void = onCellSelected;
			cell.onmouseup = function(mouseEventData:Event) { onCellMouseUpDelegate(cell, cellData); };
			
			//cell.onKeyDown = onKeyboardDown;
			/*var onCellKeyDownDelegate:KeyEventData->ContainerDOMElement->CellModel->Void = onCellKeyDown;
			cell.onKeyDown = function(keyEventData:KeyEventData) { onCellKeyDownDelegate(keyEventData, cell, cellData); };*/
		}
		
		// apply style
		listStyle.cell(cell);
		
		var cellContent:Array<HtmlDom> = getCellData(cellData.content, listStyle);
		
		// push content in cell
		for (container in cellContent)
		{
			//cell.addChild(container);
			cellLink.appendChild(container);
		}
		cell.appendChild(cellLink);
		
		// mouse
		// delegates functions are used to be able to pass an extra parameters to the callback
		// mouse over
		/*var onCellMouseOverDelegate:MouseEventData->ContainerDOMElement->Dynamic->Void = onCellMouseOver;
		cell.onMouseOver = function(mouseEventData:MouseEventData) { onCellMouseOverDelegate(mouseEventData, cell, listStyle); };
		// mouse out
		var onCellMouseOutDelegate:MouseEventData->ContainerDOMElement->Dynamic->Void = onCellMouseOut;
		cell.onMouseOut = function(mouseEventData:MouseEventData) { onCellMouseOutDelegate(mouseEventData, cell, listStyle); };
		// mouse down
		var onCellMouseDownDelegate:MouseEventData->ContainerDOMElement->Dynamic->Void = onCellMouseDown;
		cell.onMouseDown = function(mouseEventData:MouseEventData) { onCellMouseDownDelegate(mouseEventData, cell, listStyle); };*/
		 //mouse up
		//var onCellMouseUpDelegate:MouseEventData->ContainerDOMElement->Dynamic->CellModel->Void = onCellMouseUp;
		//cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(mouseEventData, cell, listStyle, cellData); };
			
		return cell;
	}
	
	/**
	 * To be overridden by subclass 
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<HtmlDom>
	{
		var cellContent:Array<HtmlDom> = new Array<HtmlDom>();
		
		return cellContent;
	}
	
	/**
	 * Cell mouse roll over callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	/*private function onCellMouseOver(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
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
	/*private function onCellMouseOut(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
	{
		listStyle.cellMouseOut(cell);
	}
	
	/**
	 * Cell mouse down callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	/*private function onCellMouseDown(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
	{
		listStyle.cellMouseDown(cell);
	}*/
	
	/**
	 * Cell mouse up callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 * @param	cellData
	 */
	//private function onCellMouseUp(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic, cellData:CellModel):Void
	//private function onCellMouseUp(mouseEventData:MouseEventData, cell:ContainerDOMElement, cellData:CellModel):Void
	//private function onCellMouseUp(cell:ContainerDOMElement, cellData:CellModel):Void
	private function onCellSelected(cell:HtmlDom, cellData:CellModel):Void
	{
		//trace("onCellMouseUp");
		//listStyle.cellMouseUp(cell);
		if (onChange != null)
		{
			onChange(cellData);
		}
		
		//selectCell(cell, listStyle);
		selectCell(cell);
	}
	
	/**
	 * Select the cell and add a selected image to it
	 */
	//private function selectCell(cell:ContainerDOMElement, listStyle:Dynamic):Void
	private function selectCell(cell:HtmlDom):Void
	{
		_selectedCellDOM = cell;
		//_selectedCellData = list.content[_currentCellIndex];

	}
	
	/**
	 * Cell keyboard down callback
	 * 
	 * @param	key
	 */
	//private function onListKeyDown(key:KeyEventData, cell:ContainerDOMElement, cellData:CellModel):Void
	//public function onListKeyDown(key:KeyEventData):Void
	public function onListKeyDown(key:Dynamic):Void
	{
		//trace(key.value);
		/*if (key.value == KeyboardKeyValue.right)
		{
			trace("right key pressed");
			/*if (onChange != null)
			{
				onChange(cellData);
			}
			selectCell(cell);
		}
		else if (key.value == KeyboardKeyValue.left)
		{
			trace("left key pressed");
			
		}*/
	}
	
	/**
	 * Selects next cell
	 */
	private function selectNextCell()
	{
		//trace(this._children.length);
		/**
		if(_currentCellIndex < _htmlDom.childNodes.length-1)
		{
			_currentCellIndex++;
			selectCell(_htmlDom.childNodes[_currentCellIndex].child);
			onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
		*/
	}
	
	/**
	 * Selects previous cell
	 */
	private function selectPreviousCell()
	{
		//trace("selectPreviousCell");
/**
		if(_currentCellIndex > 0)
		{
			_currentCellIndex--;
			selectCell(_htmlDom.childNodes[_currentCellIndex].child);
			onCellSelected(_selectedCellDOM, _listData[_currentCellIndex]);
		}
		*/
	}
	
	private function get_htmlDom():HtmlDom
	{
		return _htmlDom;
	}
	
}
