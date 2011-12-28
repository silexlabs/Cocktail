/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

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
import components.richList.RichListModels;
import components.richList.RichListUtils;


/**
 * RichList class defines a list in which each cell can be composed of a text and an image
 * 
 * @author Raphael Harmel
 */
class RichList extends ContainerDOMElement
{
	// Defines onChange callback, to be called when a new cell is selected
	public var onChange : CellModel->Void;
	
	// current cell
	private var _currentCell:Int;
	
	/**
	 * constructor
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 * @param	firstElement	first element to be placed in the cell (test or image)
	 */
	public function new(richList:DynamicRichListModel, listStyle:Dynamic)
	{
		// init _currentCell
		_currentCell = 0;
		// create a ul node
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("ul")));
		createRichListDOM(richList, listStyle);
		//RichListStyle.getDefaultStyle(this);
		listStyle.list(this);
	}
	
	/**
	 * Create the list DOM with provided data and style
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 */
	private function createRichListDOM(richListModel:DynamicRichListModel, listStyle:RichListStyleModel):Void
	{
		// set list's cell content
		var content:ContainerDOMElement = Utils.getContainer();
		
		// set list's cells
		var cellData:CellModel;
		for (cellData in richListModel.content)
		{
			// create cell
			var cell:ContainerDOMElement = createCellDOM(cellData.content, listStyle);
			
			// add cell to instance
			this.addChild(cell);
			
			_currentCell++;
		}
	}
	
	/**
	 * Creates a cell with corresponding data
	 * 
	 * @param	cellData
	 */
	private function createCellDOM(cellData:Dynamic, listStyle:Dynamic):ContainerDOMElement
	{
		// create cell with text and image

		// create cell
		var cell:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));
		// apply style
		listStyle.cell(cell);
		
		var cellContent:Array<DOMElement> = getCellData(cellData, listStyle);
		
		// push content in cell
		for (container in cellContent)
		{
			cell.addChild(container);
		}
		
		// mouse
		// delegates functions are used to be able to pass an extra parameters to the callback
		// mouse over
		var onCellMouseOverDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOver;
		cell.onMouseOver = function(mouseEventData:MouseEventData) { onCellMouseOverDelegate(mouseEventData, cell, listStyle); };
		// mouse out
		var onCellMouseOutDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseOut;
		cell.onMouseOut = function(mouseEventData:MouseEventData) { onCellMouseOutDelegate(mouseEventData, cell, listStyle); };
		// mouse down
		var onCellMouseDownDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->Void = onCellMouseDown;
		cell.onMouseDown = function(mouseEventData:MouseEventData) { onCellMouseDownDelegate(mouseEventData, cell, listStyle); };
		// mouse up
		var onCellMouseUpDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->CellModel->Void = onCellMouseUp;
		cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(mouseEventData, cell, listStyle, cellData); };
			
		return cell;
	}
	
	/**
	 * To be overridden by subclass 
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<DOMElement>
	{
		var cellContent:Array<DOMElement> = new Array<DOMElement>();
		
		return cellContent;
	}
	
	/**
	 * Cell mouse roll over callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	private function onCellMouseOver(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
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
	private function onCellMouseOut(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
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
	private function onCellMouseDown(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic):Void
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
	private function onCellMouseUp(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:Dynamic, cellData:CellModel):Void
	{
		listStyle.cellMouseUp(cell);
		if (onChange != null)
		{
			onChange(cellData);
		}
	}
}
