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

// list specific
import components.lists.ListBase;
import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;


/**
 * This class defines a thumb & text cell
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1 extends ListBase
{

	/**
	 * constructor
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	public function new(list:ListModel, listStyle:Dynamic)
	{
		super(list, listStyle);
	}
	
	/**
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	override private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<DOMElement>
	{
		var cellContent:Array<DOMElement> = new Array<DOMElement>();
		
		// INFO
		
		// add text block
		var cellInfoBlockContainer:ContainerDOMElement = Utils.getContainer();
		listStyle.cellInfoBlock(cellInfoBlockContainer);
		cellContent.push(cellInfoBlockContainer);
		
		// add cell number
		var cellNumberContainer:ContainerDOMElement = Utils.getContainer();
		var textElement:TextElement = new TextElement(Std.string(_currentCellIndex + 1));
		cellNumberContainer.addText(textElement);
		listStyle.cellNumber(cellNumberContainer);
		cellInfoBlockContainer.addChild(cellNumberContainer);
		
		// add dots line
		var celldotsLine:ImageDOMElement = new ImageDOMElement();
		// set image style
		listStyle.cellInfoBlockImage(celldotsLine);
		// add image
		cellInfoBlockContainer.addChild(celldotsLine);
		// load image
		celldotsLine.load("images/dotsLine.png");
		
		// add comment image
		var celldotsLine:ImageDOMElement = new ImageDOMElement();
		// set image style
		listStyle.cellInfoBlockImage(celldotsLine);
		// add image
		cellInfoBlockContainer.addChild(celldotsLine);
		// load image
		celldotsLine.load("images/bubble.png");
		
		// add comment count
		if (cellData.commentCount != "" && cellData.commentCount != null)
		{
			var cellCommentCountContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.commentCount);
			cellCommentCountContainer.addText(textElement);
			listStyle.cellCommentCount(cellCommentCountContainer);
			cellInfoBlockContainer.addChild(cellCommentCountContainer);
		}
		
		
		// THUMBNAIL
		
		// image part
		if (cellData.thumbnail != "" && cellData.thumbnail != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			listStyle.cellThumbnail(cellImage);
			// add image
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.thumbnail);
		}
		
		
		// TEXT
		
		// add text block
		var cellTextBlockContainer:ContainerDOMElement = Utils.getContainer();
		listStyle.cellTextBlock(cellTextBlockContainer);
		cellContent.push(cellTextBlockContainer);
		
		// add title
		if (cellData.title != "" && cellData.title != null)
		{
			var cellTitleContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			listStyle.cellTitle(cellTitleContainer);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		
		// add comment
		if (cellData.comment != "" && cellData.comment != null)
		{
			var cellCommentContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.comment);
			cellCommentContainer.addText(textElement);
			listStyle.cellComment(cellCommentContainer);
			cellTextBlockContainer.addChild(cellCommentContainer);
		}
		
		// add description
		if (cellData.description != "" && cellData.description != null)
		{
			var cellDescriptionContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.description);
			cellDescriptionContainer.addText(textElement);
			listStyle.cellDescription(cellDescriptionContainer);
			cellTextBlockContainer.addChild(cellDescriptionContainer);
		}
		
		
		// LINE
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		listStyle.cellLine(line);
		cellContent.push(line);
		line.load("images/greyPixel.png");

		return cellContent;
	}
	
}