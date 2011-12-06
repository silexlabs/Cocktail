/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import haxe.Timer;
import cocktail.geom.GeomData;
import cocktail.resource.ResourceLoaderManager;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.textElement.TextElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList specific
import components.richList.RichList;
import components.richList.RichListModels;
import components.richList.StyleNormal;
import components.richList.StyleApp;
import components.richList.RichListUtils;

/**
 * Handles all applications pages
 * 
 * @author	Raphael Harmel
 * @date	2001-11-30
 */

class ApplicationStructure 
{
	public var pagesContainer:ContainerDOMElement;

	private var _homePage:ContainerDOMElement;
	
	private var _calListPage:ContainerDOMElement;
	private var _dayPage:ContainerDOMElement;
	
	private var _artistListPage:ContainerDOMElement;
	private var _albumListPage:ContainerDOMElement;
	private var _songListPage:ContainerDOMElement;
	private var _songPage:ContainerDOMElement;
	
	private var _noteListPage:ContainerDOMElement;
	private var _notePage:ContainerDOMElement;
	
	private var _creditsPage:ContainerDOMElement;
	
	private var _currentPage:ContainerDOMElement;
	
	public function new() 
	{
		pagesContainer = Utils.getContainer();
		//IphoneStyle.getPageContainerStyle(pagesContainer);

		createAllPages();
	}
	
	private function createAllPages()
	{
		// create pages
		_dayPage = createHeaderContentPage("Day","This is what I have planned today");
		_calListPage = createHeaderListPage(
			"Calendar",
			[
				{text:"June 1st", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_dayPage },
				{text:"June 2nd", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_dayPage },
				{text:"June 3rd", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_dayPage },
				{text:"June 4th", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_dayPage },
				{text:"June 5th", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_dayPage }
			]
		);
		_songPage = createHeaderContentPage("Song","You are listening to this song");
		_songListPage = createHeaderListPage(
			"Artist - Album",
			[
				{text:"Song 1", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songPage },
				{text:"Song 2", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songPage },
				{text:"Song 3", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songPage },
				{text:"Song 4", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songPage },
				{text:"Song 5", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songPage }
			]
		);
		Timer.delay(dolatertest, 300);
	}
	
	// this method is here only for tests purposes. to be merged with preceding function
	private function dolatertest()
	{
		_albumListPage = createHeaderListPage(
			"Albums",
			[
				{text:"Album 1", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songListPage },
				{text:"Album 2", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songListPage },
				{text:"Album 3", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songListPage },
				{text:"Album 4", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songListPage },
				{text:"Album 5", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_songListPage }
			]
		);
		_artistListPage = createHeaderListPage(
			"Artists",
			[
				{text:"Artist 1", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_albumListPage },
				{text:"Artist 2", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_albumListPage },
				{text:"Artist 3", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_albumListPage },
				{text:"Artist 4", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_albumListPage },
				{text:"Artist 5", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_albumListPage }
			]
		);
		_notePage = createHeaderContentPage("Note","This is the content of the note");
		_noteListPage = createHeaderListPage(
			"Notes",
			[
				{text:"Note 1", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 2", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 3", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 4", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 5", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 6", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 7", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 8", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 9", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 10", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 11", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 12", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 13", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 14", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 15", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage },
				{text:"Note 16", imagePath:"images/chevron.png", action:"goToPage", actionTarget:_notePage }
			]
		);
		_creditsPage = createHeaderContentPage("Credits", "This is a Cocktail demo. Cocktail is a cross-platform library for the HaXe programming language. It bridges the gap between all the targets supported by haXe, removing inconsistencies behind a common API. With it, the same code base is used to deploy to these targets: Flash, javaScript, PHP. It helps multi device application development and should be used by haXe projects requiring cross-target compilation. Silex Labs Cocktail library is released under GPL. Project home: http://www.silexlabs.org/groups/labs/cocktail/");

		Timer.delay(dolatertest2, 300);
	}
	
	// this method is here only for tests purposes. to be merged with preceding function
	private function dolatertest2()
	{
		_homePage = createHomePage(
			[
				{text:"Cal", imagePath:"images/NavButtonCalendar.png", action:"goToPage", actionTarget:_calListPage },
				{text:"Music", imagePath:"images/NavButtonMusic.png", action:"goToPage", actionTarget:_artistListPage },
				{text:"Notes", imagePath:"images/NavButtonNotes.png", action:"goToPage", actionTarget:_noteListPage },
				{text:"Credits", imagePath:"images/NavButtonCredits.png", action:"goToPage", actionTarget:_creditsPage }
			]
		);
		_currentPage = _homePage;
		
		pagesContainer.addChild(_homePage);
	}
	
	/**
	 * Hides the current page and shows the wanted page
	 * 
	 * @param	application		the main containerDOMElement where to attach the page
	 * @param	page			the wanted page
	 */
	private function showPage(page:ContainerDOMElement):Void
	{
		pagesContainer.removeChild(_currentPage);
		pagesContainer.addChild(page);
		_currentPage = page;
	}
	
	function onChangeListCallback(itemData : CellModel)
	{
		if (itemData.action == "goToPage")
		{
			showPage(itemData.actionTarget);
		}
		//if (cellData.action == "gotoURLAction")
			//gotoURL(cellData.actionTarget);
	}
	
	/**
	 * Creates home page
	 * 
	 * @return
	 */
	private function createHomePage(cellDataArray:Array<CellModel>):ContainerDOMElement
	{
		var page:ContainerDOMElement = Utils.getContainer();
		
		// richList for home page

		// richList background
		var homeTilePath = "images/blackPixel.png";
		var backGround:ImageDOMElement = new ImageDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.image));
		// style is applied here even if image is not loaded so RichList assets are placed on the correct position
		WebAppStyle.getBgStyle(backGround);
		ResourceLoaderManager.loadImage(homeTilePath, onHomeTileLoaded, onImageLoadError, backGround);

		// create richList data & style
		var richList:RichList = createRichListHome(cellDataArray);
		
		// rich list onChange callback
		richList.onChange = onChangeListCallback;
		
		
		// build page domElement
		page.addChild(backGround);
		page.addChild(richList);
		
		WebAppStyle.getHomePageStyle(page);
		
		return page;
	}
	
	/**
	 * Creates a list header page
	 * 
	 * @return
	 */
	private function createHeaderListPage(title:String, cellDataArray:Array<CellModel>):ContainerDOMElement
	{
		var page:ContainerDOMElement = Utils.getContainer();
		
		// create header
		var header:ContainerDOMElement = createHeader(title);

		
		// create richList data & style
		var richList:RichList = createArrowRichList(cellDataArray);
		
		// rich list onChange callback
		richList.onChange = onChangeListCallback;
		
		
		// build hierarchy
		page.addChild(header);
		page.addChild(richList);
		WebAppStyle.getPageStyle(page);
		
		return page;
	}
	
	/**
	 * Creates a content header page
	 * 
	 * @return
	 */
	private function createHeaderContentPage(title:String, content:String):ContainerDOMElement
	{
		var page:ContainerDOMElement = Utils.getContainer();
		
		// create header
		var header:ContainerDOMElement = createHeader(title);

		
		// create content
		var textElement:TextElement = new TextElement(content);
		var textContainer:ContainerDOMElement = Utils.getContainer();
		textContainer.addText(textElement);
		WebAppStyle.getTextContentStyle(textContainer);
		
		// build hierarchy
		page.addChild(header);
		page.addChild(textContainer);
		WebAppStyle.getPageStyle(page);
		
		return page;
	}
	
	/**
	 * Creates a header with a Tile, a title and a back button
	 * 
	 * @return
	 */
	private function createHeader(title:String):ContainerDOMElement
	{
		// create header
		
		// Tile image
		var header:ContainerDOMElement = Utils.getContainer();
		var headerTile:ImageDOMElement = new ImageDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.image));
		var headerTilePath:String = "images/H1.png";
		
		//var onHeaderTileLoadedDelegate:ImageDOMElement->ContainerDOMElement->Void = onHeaderTileLoaded;
		//ResourceLoaderManager.loadImage(headerTilePath, function(headerTile:ImageDOMElement) { onHeaderTileLoadedDelegate(headerTile, header); }, onHeaderTileLoadError, headerTile);
		ResourceLoaderManager.loadImage(headerTilePath, onHeaderTileLoaded, onImageLoadError, headerTile);
		
		// Back button
		var backButton:TextElement = new TextElement('Back');
		var backButtonContainer:ContainerDOMElement = Utils.getContainer();
		backButtonContainer.addText(backButton);
		backButtonContainer.onMouseUp = onBackButtonMouseUp;
		WebAppStyle.getBackButtonStyle(backButtonContainer);

		// header title
		var headerTitle:TextElement = new TextElement(title);
		var headerTitleContainer:ContainerDOMElement = Utils.getContainer();
		headerTitleContainer.addText(headerTitle);
		WebAppStyle.getHeaderTextStyle(headerTitleContainer);

		
		// build hierarchy
		header.addChild(headerTile);
		header.addChild(headerTitleContainer);
		header.addChild(backButtonContainer);
		
		// build page style & domElement
		WebAppStyle.getHeaderStyle(header);

		return header;
	}
	
	//private function onHeaderTileLoaded(image:ImageDOMElement, container:ContainerDOMElement):Void
	private function onHeaderTileLoaded(image:ImageDOMElement):Void
	{
		// set image style
		image.style.width = DimensionStyleValue.percent(100);
		
		// add image to container
		//container.addChild(image);
	}
	
	private function onHomeTileLoaded(image:ImageDOMElement):Void
	{
		// set image style. this has to be done once when image has been loaded
		WebAppStyle.getBgStyle(image);
	}
	
	/**
	 * Called when there is an error while loading picture
	 * @param	error
	 */
	private function onImageLoadError(error:String):Void
	{
		trace(error);
	}
	
	
	/**
	 * Create home's richList
	 * 
	 * @return
	 */
	private function createRichListHome(content:Array<CellModel>):RichList
	{
		// data
		var listData:RichListModel = RichListUtils.createRichListModel();
		//listData.title.text = "Mon titre";
		listData.content = content;
		
		// style
		var listStyle:RichListStyleModel = {
			list:StyleApp.getDefaultStyle,
			cell:StyleApp.getCellStyle,
			cellImage:StyleApp.getCellImageStyle,
			cellMouseOver:StyleApp.getCellMouseOverStyle,
			cellMouseOut:StyleApp.getCellMouseOutStyle,
			cellMouseDown:StyleApp.getCellMouseDownStyle,
			cellMouseUp:StyleApp.getCellMouseUpStyle}
		
		var list:RichList = new RichList(listData, listStyle);
		
		return list;
	}
	
	/**
	 * Create music's richList
	 * 
	 * @return
	 */
	private function createArrowRichList(content:Array<CellModel>):RichList
	{
		// data
		var listData:RichListModel = RichListUtils.createRichListModel();
		
		listData.content = content;
		
		// style
		var listStyle:RichListStyleModel = {
			list:StyleNormal.getDefaultStyle,
			cell:StyleNormal.getCellStyle,
			cellImage:StyleNormal.getCellImageStyle,
			cellMouseOver:StyleNormal.getCellMouseOverStyle,
			cellMouseOut:StyleNormal.getCellMouseOutStyle,
			cellMouseDown:StyleNormal.getCellMouseDownStyle,
			cellMouseUp:StyleNormal.getCellMouseUpStyle}
		
		var list:RichList = new RichList(listData, listStyle);
		
		return list;
	}
	
	private function onBackButtonMouseUp(mouseEvent:MouseEventData):Void
	{
		showPage(_homePage);
	}
}