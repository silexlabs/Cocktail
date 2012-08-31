/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package components.lists;

// list specific
import components.lists.ListBase;
import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;

import js.Lib;
import js.Dom;

//import cocktail.viewport.Viewport;
import ScreenResolution;


/**
 * This class defines a thumb & text cell
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1 extends ListBase
{

	//var smallSize:Bool;
	var screenResolutionSize:ScreenResolutionSize;
	
	/**
	 * constructor
	 * 
	 * @param	list
	 * @param	listStyle
	 */
	public function new(list:ListModel, listStyle:Dynamic)
	{
		var screenResolution:ScreenResolution = new ScreenResolution();
		screenResolutionSize = screenResolution.size;
		//var viewport:Viewport = new Viewport();
		//if (viewport.width < 500) smallSize = true;
		//else smallSize = false;

		super(list, listStyle);
	}
	
	/**
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	override private function getCellData(cellData:Dynamic, listStyle:Dynamic):Array<HtmlDom>
	{
		var cellContent:Array<HtmlDom> = new Array<HtmlDom>();
		
		// INFO
		
		// add text block
		var cellInfoBlockContainer = Utils.getContainer();
		listStyle.cellInfoBlock(cellInfoBlockContainer);
		cellContent.push(cellInfoBlockContainer);
		
		// add cell number
		var cellNumberContainer = Utils.getContainer();
		var textElement = Lib.document.createTextNode(Std.string(_currentCellIndex + 1));
		cellNumberContainer.appendChild(textElement);
		listStyle.cellNumber(cellNumberContainer,screenResolutionSize);
		cellInfoBlockContainer.appendChild(cellNumberContainer);
		
		// add dots line
		var celldotsLine:Image = cast(Lib.document.createElement("img"));
		// set image style
		listStyle.cellInfoBlockLine(celldotsLine,screenResolutionSize);
		// add image
		cellInfoBlockContainer.appendChild(celldotsLine);
		// load image
		celldotsLine.src = "images/dotsLine.png";
		
		// add comment image
		var cellCommentImage:Image = cast(Lib.document.createElement("img"));
		// set image style
		listStyle.cellInfoBlockImage(cellCommentImage,screenResolutionSize);
		// add image
		cellInfoBlockContainer.appendChild(cellCommentImage);
		// load image
		cellCommentImage.src = "images/bubble.png";
		
		// add comment count
		if (cellData.commentCount != "" && cellData.commentCount != null)
		{
			var cellCommentCountContainer = Utils.getContainer();
			var textElement = Lib.document.createTextNode(cellData.commentCount);
			cellCommentCountContainer.appendChild(textElement);
			listStyle.cellCommentCount(cellCommentCountContainer,screenResolutionSize);
			cellInfoBlockContainer.appendChild(cellCommentCountContainer);
		}
		
		
		// THUMBNAIL
		
		// image part
		if (cellData.thumbnail != "" && cellData.thumbnail != null)
		{
			var cellImage:Image = cast(Lib.document.createElement("img"));
			// set image style
			listStyle.cellThumbnail(cellImage,screenResolutionSize);
			// add image
			cellContent.push(cellImage);
			// load image
			cellImage.src = cellData.thumbnail;
		}
		
		
		// TEXT
		
		// add text block
		var cellTextBlockContainer = Utils.getContainer();
		listStyle.cellTextBlock(cellTextBlockContainer);
		cellContent.push(cellTextBlockContainer);
		
		// add title
		if (cellData.title != "" && cellData.title != null)
		{
			var cellTitleContainer = Utils.getContainer();
			var textElement = Lib.document.createTextNode(cellData.title);
			cellTitleContainer.appendChild(textElement);
			listStyle.cellTitle(cellTitleContainer, screenResolutionSize);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
		
		// add comment
		if (cellData.comment != "" && cellData.comment != null)
		{
			var cellCommentContainer = Utils.getContainer();
			var textElement = Lib.document.createTextNode(cellData.comment);
			cellCommentContainer.appendChild(textElement);
			listStyle.cellComment(cellCommentContainer, screenResolutionSize);
			cellTextBlockContainer.appendChild(cellCommentContainer);
		}
		
		// if screen resolution is large
		if (screenResolutionSize == ScreenResolutionSize.large)
		{
			// add description
			if (cellData.description != "" && cellData.description != null)
			{
				var textLength:Int;
				if (screenResolutionSize == normal) textLength = 95;
				else textLength = 200;
				
				var cellDescriptionContainer = Utils.getContainer();
				var shortenedText = cellData.description.substr(0, textLength) + "...";
				var textElement = Lib.document.createTextNode(shortenedText);
				cellDescriptionContainer.appendChild(textElement);
				listStyle.cellDescription(cellDescriptionContainer);
				cellTextBlockContainer.appendChild(cellDescriptionContainer);
			}
		}
		
		// LINE
		
		// add separation line
		var line:Image = cast(Lib.document.createElement("img"));
		// set image style
		listStyle.cellLine(line);
		cellContent.push(line);
		line.src = "images/greyPixel.png";

		return cellContent;
	}
	
}