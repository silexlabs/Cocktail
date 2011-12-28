/**
 * This class defines a thumbList
 * 
 * @author Raphael Harmel
 */

package components.richList.thumbList;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;

// RichList specific
import components.richList.RichList;
import components.richList.RichListModels;
import components.richList.RichListUtils;
import components.richList.thumbList.ThumbList1Models;


class ThumbList1 extends RichList
{

	/**
	 * constructor
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 */
	public function new(richList:DynamicRichListModel, listStyle:Dynamic)
	{
		super(richList, listStyle);
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
		var textElement:TextElement = new TextElement(Std.string(_currentCell));
		cellNumberContainer.addText(textElement);
		//listStyle.cellText(cellTitleContainer);
		listStyle.cellNumber(cellNumberContainer);
		//cell.addChild(cellTextContainer);
		//cellContent.push(cellTitleContainer);
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
			//listStyle.cellText(cellTitleContainer);
			listStyle.cellCommentCount(cellCommentCountContainer);
			//cell.addChild(cellTextContainer);
			//cellContent.push(cellTitleContainer);
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
			//cell.addChild(cellImage);
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.thumbnail);
		}
		
		
		// TEXT INFO
		
		// add text block
		var cellTextBlockContainer:ContainerDOMElement = Utils.getContainer();
		//var textElement:TextElement = new TextElement(cellData.title);
		//cellTitleContainer.addText(textElement);
		listStyle.cellTextBlock(cellTextBlockContainer);
		//cell.addChild(cellTextContainer);
		cellContent.push(cellTextBlockContainer);
		
		// add title
		if (cellData.title != "" && cellData.title != null)
		{
			var cellTitleContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			//listStyle.cellText(cellTitleContainer);
			listStyle.cellTitle(cellTitleContainer);
			//cell.addChild(cellTextContainer);
			//cellContent.push(cellTitleContainer);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		
		// add comment
		if (cellData.comment != "" && cellData.comment != null)
		{
			var cellCommentContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.comment);
			cellCommentContainer.addText(textElement);
			listStyle.cellComment(cellCommentContainer);
			//cell.addChild(cellTextContainer);
			//cellContent.push(cellCommentContainer);
			cellTextBlockContainer.addChild(cellCommentContainer);
		}
		
		// add description
		if (cellData.description != "" && cellData.description != null)
		{
			var cellDescriptionContainer:ContainerDOMElement = Utils.getContainer();
			var textElement:TextElement = new TextElement(cellData.description);
			cellDescriptionContainer.addText(textElement);
			listStyle.cellDescription(cellDescriptionContainer);
			//cell.addChild(cellTextContainer);
			//cellContent.push(cellCommentContainer);
			cellTextBlockContainer.addChild(cellDescriptionContainer);
		}
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		listStyle.cellLine(line);
		cellContent.push(line);
		line.load("images/greyPixel.png");

		return cellContent;
	}
	
}