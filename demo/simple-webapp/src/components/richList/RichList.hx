/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

// DOM
import cocktail.classInstance.ClassInstance;
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
	
	/**
	 * constructor
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 * @param	firstElement	first element to be placed in the cell (test or image)
	 */
	public function new(richListModel:RichListModel, listStyle:RichListStyleModel)
	{
		// create a ul node
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("ul")));
		createRichListDOM(richListModel, listStyle);
		//RichListStyle.getDefaultStyle(this);
		listStyle.list(this);
	}
	
	/**
	 * Create the list DOM with provided data (title & cells) and style (title and cells)
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 */
	private function createRichListDOM(richListModel:RichListModel, listStyle:RichListStyleModel):Void
	{
		// set list's cell content
		var content:ContainerDOMElement = Utils.getContainer();
		
		// set list's cells
		var cellData:CellModel;
		for (cellData in richListModel.content)
		{
			// create cell with text and image
			// empty cell part
			var cell:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));

			listStyle.cell(cell);
			
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
			var onCellMouseUpDelegate:MouseEventData->ContainerDOMElement->RichListStyleModel->CellModel->Void = onCellMouseUp;
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellMouseUpDelegate(mouseEventData, cellTextContainer, listStyle, cellData); };
			
		}
	}
	
	/**
	 * Cell mouse roll over callback
	 * 
	 * @param	mouseEventData
	 * @param	cell
	 * @param	listStyle
	 */
	private function onCellMouseOver(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
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
	private function onCellMouseOut(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
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
	private function onCellMouseDown(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel):Void
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
	private function onCellMouseUp(mouseEventData:MouseEventData, cell:ContainerDOMElement, listStyle:RichListStyleModel, cellData:CellModel):Void
	{
		listStyle.cellMouseUp(cell);
		if (onChange != null)
		{
			onChange(cellData);
		}
	}
}
