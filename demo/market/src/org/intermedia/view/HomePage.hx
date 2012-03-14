package org.intermedia.view;

/**
 * This class builds the static part of the home page
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ImageDOMElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.Constants;
import cocktail.mouse.MouseData;
import org.intermedia.view.StyleModel;


class HomePage extends ListViewBase
{

	public function new() 
	{
		super();
	}
	
	override private function buildView():Void
	{
		// add custom cells to the homepage
		
		var cell0Style:CellThumbText1StyleModel = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnail:CellThumbStyle2.setThumbnailStyle,
			textBlock:null,
			title:null,
			author:null,
			line:null
		};
		
		var cell0 = new CellThumb(1,cell0Style);
		cell0.data = {
			id:130523,
			thumbUrl:"assets/400-156.png",
			title:"incredible plugin",
			author:"vador"
			}
		// set mouseUp callback
		cell0.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell0.data); };
		this.addChild(cell0);

		var cell1 = new CellThumb(2,cell0Style);
		cell1.data = {
			id:130523,
			thumbUrl:"assets/200-156_red.png",
			title:"incredible plugin",
			author:"vador"
			}
		// set mouseUp callback
		cell1.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell1.data); };
		this.addChild(cell1);

		var cell2 = new CellThumb(2,cell0Style);
		cell2.data = {
			id:130523,
			thumbUrl:"assets/200-156_purple.png",
			title:"incredible plugin",
			author:"vador"
			}
		// set mouseUp callback
		cell2.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell2.data); };
		this.addChild(cell2);

		var cell3 = new CellThumb(2,cell0Style);
		cell3.data = {
			id:130523,
			thumbUrl:"assets/200-156_purple.png",
			title:"incredible plugin",
			author:"vador"
			}
		// set mouseUp callback
		cell3.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell3.data); };
		this.addChild(cell3);

		var cell10 = new CellThumbText1(2);
		cell10.data = {
			id:130523,
			title:"incredible plugin",
			author:"itzel",
			thumbUrl:"assets/200-156_red.png"
			}
		// set mouseUp callback
		cell10.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell10.data); };
		this.addChild(cell10);
		
		var cell20 = new CellThumbText1(2);
		cell20.data = {
			id:130523,
			title:"incredible theme",
			author:"raph",
			thumbUrl:"assets/200-156_red.png"
			}
		this.addChild(cell20);
		// set mouseUp callback
		cell20.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell20.data); };
		
		var cell4 = new CellThumb(2,cell0Style);
		cell4.data = {
			id:130523,
			thumbUrl:"assets/200-156_purple.png",
			title:"incredible plugin",
			author:"vador"
			}
		// set mouseUp callback
		cell4.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell4.data); };
		this.addChild(cell4);

	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb(url:String):ImageDOMElement
	{
		// THUMBNAIL
		var image = new ImageDOMElement();
		// set image style
		image.style.verticalAlign = middle;
		// add image
		this.addChild(image);
		// load image
		image.load(url);
		
		return image;
	}
	
}