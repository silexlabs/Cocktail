package org.intermedia.view;

import haxe.Firebug;
<<<<<<< HEAD
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for thumb text list cell. Each ListView has its own cell class inherited from this one.
=======
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for thumb text list cell
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
 * 
 * @author Raphael Harmel
 */

<<<<<<< HEAD
=======
import org.intermedia.view.CellBase;
import org.intermedia.view.StyleModel;

>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
class CellThumbText1 extends CellBase
{
	// cropping mask containing the image
	private var _croppedImage:CroppedImage;
<<<<<<< HEAD

	// blockThumb containing cropped image
	//private var _blockThumb:BlockThumb;
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
<<<<<<< HEAD
	 * @param	?cellStyle		cell style
=======
	 * @param	?style		cell style
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	 */
	public function new(?cellPerLine:Int = 1, ?style:CellStyleModel) 
	{
<<<<<<< HEAD
		super(cellPerLine,cellStyle);
=======
		super(cellPerLine,style);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}

	/**
	 * cell style init
	 */
	override private function initStyle():Void
	{
		// init style model
<<<<<<< HEAD
		_cellStyle = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnailMask:CellThumbText1Style.setThumbnailMaskStyle,
=======
		_style = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnailMask:CellThumbText1Style.setThumbnailMaskStyle,
			thumbnail:null,
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			textBlock:CellThumbText1Style.setTextBlockStyle,
			title:CellThumbText1Style.setTitleStyle,
			author:null
		}
		
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		super.updateView();
		
		// THUMBNAIL
		
		// load cropped thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
<<<<<<< HEAD
			// create cropped image
			/*_croppedImage = new CroppedImage();
			_croppedImage.onImageLoadSuccess = refreshStyles;
			_croppedImage.loadThumb(_data.thumbUrl);
			// apply style
			_cellStyle.thumbnailMask(_croppedImage.node);
			// attach it to hierarchy
			node.appendChild(_croppedImage.node);*/

			// create blockThumb containing cropped thumb image
			_croppedImage = new CroppedImage(_cellStyle);
			_croppedImage.data = _data;
			node.appendChild(_croppedImage.node);
			
=======
			// create cropped thumb image
			_croppedImage = new CroppedImage(_style);
			_croppedImage.data = _data;
			node.appendChild(_croppedImage.node);	
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		}

		
		// TEXT
		
		// add text block
		var cellTextBlockContainer:HtmlDom = Lib.document.createElement("div");
<<<<<<< HEAD
		_cellStyle.textBlock(cellTextBlockContainer);
=======
		_style.textBlock(cellTextBlockContainer);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		node.appendChild(cellTextBlockContainer);
		
		// add title
		if (_data.title != "" && _data.title != null)
		{
			var text:String = _data.title;
			// shorten title
			if (text.length > Constants.CELL_THUMB_TEXT_TITLE_LENGTH)
			{
				// shorten title to TITLE_LENGTH
				text = text.substr(0, Constants.CELL_THUMB_TEXT_TITLE_LENGTH);
				// then shorten it until the last space character and add "..." at the end
				text = text.substr(0, text.lastIndexOf(" ")) + "...";
			}
			var textElement:HtmlDom = Lib.document.createTextNode(text);
			var cellTitleContainer:HtmlDom = Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
<<<<<<< HEAD
			_cellStyle.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
		
		// add author
		/*if (_data.author != "" && _data.author != null)
		{
			var cellAuthorContainer:HtmlDom = Lib.document.createElement("div");
			var textElement:HtmlDom = Lib.document.createTextNode(_data.author);
			cellAuthorContainer.appendChild(textElement);
			_cellStyle.author(cellAuthorContainer);
			//listStyle.cellComment(cellAuthorContainer, screenResolutionSize);
			cellTextBlockContainer.appendChild(cellAuthorContainer);
		}*/
		
		
		// LINE
		
		// add separation line
		/*var line:HtmlDom = Lib.document.createElement("div");
		// set image style
		_cellStyle.line(line);
		node.appendChild(line);
		line.src("assets/greyPixel.png");*/

		//Timer.delay(refreshStyles, Constants.CELL_STYLE_REFRESH_DELAY);
=======
			_style.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
		
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}
	
	override public function refreshStyles():Void 
	{
<<<<<<< HEAD
		// reset cropped image style
		//_croppedImage.refreshStyles();
=======
		super.refreshStyles();
		// reset cropped image style
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		_croppedImage.refreshStyles();
	}

}