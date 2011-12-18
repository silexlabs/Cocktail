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

class ThumbList extends RichList
{

	/**
	 * constructor
	 * 
	 * @param	richListModel
	 * @param	listStyle
	 */
	public function new(richList:DynamicRichListModel, listStyle:RichListStyleModel)
	{
		super(richList, listStyle);
	}
	
	/**
	 * Create an array containing all the data of the cell
	 * 
	 * @return the array of data DOM to be added into the cell
	 */
	override private function getCellData(cellData:Dynamic, listStyle:RichListStyleModel):Array<DOMElement>
	{
		var cellContent:Array<DOMElement> = new Array<DOMElement>();
		
		// image part
		if (cellData.thumbnail != "" && cellData.thumbnail != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			listStyle.cellImage(cellImage);
			// add image
			//cell.addChild(cellImage);
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.thumbnail);
		}
		
		// add title
		var cellTitleContainer:ContainerDOMElement = Utils.getContainer();
		if (cellData.title != "" && cellData.title != null)
		{
			var textElement:TextElement = new TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			listStyle.cellText(cellTitleContainer);
			//cell.addChild(cellTextContainer);
			cellContent.push(cellTitleContainer);
		}
		
		// add comment
		var cellCommentContainer:ContainerDOMElement = Utils.getContainer();
		if (cellData.comment != "" && cellData.comment != null)
		{
			var textElement:TextElement = new TextElement(cellData.comment);
			cellCommentContainer.addText(textElement);
			listStyle.cellText(cellCommentContainer);
			//cell.addChild(cellTextContainer);
			cellContent.push(cellCommentContainer);
		}
		
		return cellContent;
	}
	
}