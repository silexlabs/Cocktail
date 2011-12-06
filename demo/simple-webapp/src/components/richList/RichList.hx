/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

// DOM
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
		super();
		createRichListDOM(richListModel, listStyle);
		//RichListStyle.getDefaultStyle(this);
		listStyle.list(this);
	}
	
	/**
	 * Create the list DOM with provided data (title & cells) and style (title and cells)
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 * @param	firstCellElement
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
			var cell:ContainerDOMElement = Utils.getContainer();
			
			// text part => moved to the image callback
			//cell.addText(NativeElementManager.createNativeTextNode(cellData.text));
			
			// image part
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// a delegate function is used to be able to pass an extra parameter to the callback
			var onPictureLoadedDelegate:ImageDOMElement->ContainerDOMElement->RichListStyleModel->CellModel->Void = onPictureLoaded;
			ResourceLoaderManager.loadImage(cellData.imagePath, function(cellImage:ImageDOMElement) { onPictureLoadedDelegate(cellImage, cell, listStyle, cellData); }, onPictureLoadError, cellImage);

			// add cell to instance
			this.addChild(cell);
			
			// mouse
			// delegates functions are used to be able to pass an extra parameter to the callback
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
			
		}
	}
	
	/**
	 * Called when the image is loaded correctly. Atttach the image to the cell and set the style
	 * 
	 * @param	domElement
	 * @param	cell
	 */
	private function onPictureLoaded(domElement:ImageDOMElement, cell:ContainerDOMElement, listStyle:RichListStyleModel, cellData:CellModel):Void
	{
		// create line to separate cells
		listStyle.cell(cell);
		
		//var line:GraphicDOMElement = Utils.getGraphic();
		//StyleNormal.getCellLine(line);
		//Utils.fillGraphic(line, 0xDDDDDD);
			
		// set image style
		listStyle.cellImage(domElement);
		
		// add line, then image and then text
		//cell.addChild(line);
		cell.addChild(domElement);
		cell.addText(new TextElement(cellData.text));
		// create line to separate cells
		listStyle.cell(cell);
	}

	/**
	 * Called when there is an error while loading picture
	 * @param	error
	 */
	private function onPictureLoadError(error:String):Void
	{
		trace(error);
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
		//MouseCursorValue.native(NativeOSMouseCursorValue.pointer);
		//MouseCursorManager.setMouseCursor(NativeOSMouseCursorValue.pointer);
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
