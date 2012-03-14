package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import cocktail.style.StyleData;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

import org.intermedia.view.CellThumbText1Style;
import org.intermedia.view.StyleModel;

import feffects.Tween;


/**
 * This class defines a CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumb extends CellBase
{
	// cell style
	private var _cellStyle:CellThumbText1StyleModel;
	
	private var _cellImage:ImageDOMElement;

	/**
	 * 
	 * 
	 * @param	?cellPerLine	number of cells per line
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellThumbText1StyleModel) 
	{
		super();
		if (cellStyle != null) _cellStyle = cellStyle;
		else initCellStyle();
		_cellStyle.cell(this,cellPerLine);
	}
	
	private function initCellStyle():Void
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
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			_cellImage = new ImageDOMElement();
			// set image style
			//listStyle.cellThumbnail(cellImage,screenResolutionSize);
			_cellStyle.thumbnail(_cellImage);
			// add image
			this.addChild(_cellImage);
			// load image
			_cellImage.onLoad = onImageLoadSuccess;
			_cellImage.load(_data.thumbUrl);
		}
		
	}
	
	/**
	 * image load success callback
	 */
	private function onImageLoadSuccess(image:ImageDOMElement):Void
	{
		fadeIn();
	}
	
	/**
	 * thum display fade in
	 */
	private function fadeIn():Void
	{
		// create the tween
        var tween = new Tween( 0, 1, 400 );
		tween.setTweenHandlers( tweenOpacity, tweenEnd );
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
