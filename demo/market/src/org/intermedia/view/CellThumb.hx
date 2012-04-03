package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import cocktail.style.StyleData;
import haxe.Timer;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

//import org.intermedia.view.CellThumbText1Style;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;

import feffects.Tween;


/**
 * This class defines a CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumb extends CellBase
{
	// cell style
	//private var _cellStyle:CellStyleModel;
	
	// thumb mask
	private var _thumbMask:Size;
	
	// cell thumb image
	private var _cellImage:ImageDOMElement;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine			number of cells per line
	 * @param	?cellStyle				cell style
	 * @param	?thumbWidthPercent		thumb percentage of the cell
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel, ?thumbWidthPercent:Int) 
	{
		super(cellPerLine);
		//if (cellStyle != null) _cellStyle = cellStyle;
		//else initCellStyle();
		// apply cell style and gets the cell dimension, for image cropping
		//_thumbMask = _cellStyle.cell(this, cellPerLine, thumbWidthPercent);
		_thumbMask = _cellStyle.cell(this, cellPerLine);
	}
	
	/**
	 * initialize the default cell style
	 */
	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			cell:CellThumbStyle.setCellStyle,
			thumbnail:CellThumbStyle.setThumbnailStyle,
			textBlock:null,
			title:null,
			author:null,
			line:null
		}
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		// load thumb image
		loadThumb();
	}

	/**
	 *  load thumb image
	 */
	private function loadThumb():Void
	{
		// image part
		//if (Reflect.hasField(_data, "thumbUrl"))
		//{
			if (_data.thumbUrl != "" && _data.thumbUrl != null)
			{
				_cellImage = new ImageDOMElement();
				// add image
				this.addChild(_cellImage);
				// load image
				_cellImage.onLoad = onImageLoadSuccess;
				_cellImage.load(_data.thumbUrl);
			}
		//}
	}
	
	/**
	 * image load success callback
	 */
	private function onImageLoadSuccess(image:ImageDOMElement):Void
	{
		// set image style. It is needed to do it here as we need to access to the intrisic size of the image,
		// which we can access only when the image has been loaded
		//listStyle.cellThumbnail(cellImage,screenResolutionSize);
		_cellStyle.thumbnail(_cellImage, _thumbMask);
		
		// display thumb using a random effect
		Timer.delay(fadeIn,Std.random(1000));
	}
	
	/**
	 * thum display fade in
	 */
	private function fadeIn():Void
	{
		// create the tween
        var tween = new Tween( 0, 1, 400 );
		tween.setTweenHandlers( tweenOpacity, tweenEnd );
		//tween.setTweenHandlers( tweenOpacity, null );
        // launch the tween
        tween.start();
	}
	
	/**
	 * opacity tweening
	 * @param	e
	 */
    function tweenOpacity( e : Float )
    {
        _cellImage.style.opacity = OpacityStyleValue.number(e);
    }

    function tweenEnd(e : Float )
	{
		
	}

}
