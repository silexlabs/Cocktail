/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import haxe.Timer;
import cocktail.geom.GeomData;
import cocktail.resource.ResourceLoaderManager;
import cocktailCore.resource.ResourceLoader;
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
	// pagesContainer is the container for all pages
	public var pagesContainer:ContainerDOMElement;

	// the home page looking like a smartphone desktop
	private var _homePage:ContainerDOMElement;
	
	// the calendar pages
	private var _calListPage:ContainerDOMElement;
	private var _dayPage:ContainerDOMElement;
	
	// the music pages
	private var _artistListPage:ContainerDOMElement;
	private var _albumListPage:ContainerDOMElement;
	private var _songListPage:ContainerDOMElement;
	private var _songPage:ContainerDOMElement;
	
	// the notes pages
	private var _noteListPage:ContainerDOMElement;
	private var _notePage:ContainerDOMElement;
	
	// the credit page
	private var _creditsPage:ContainerDOMElement;
	
	// the current visible page
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
		
		// the calendar pages
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

		// the music pages
		_songPage = createHeaderContentPage("Song","You are listening to this song");
		//_songPage = createEmbedContentPage("Song","http://w.soundcloud.com/player/?url=http%3A%2F%2Fapi.soundcloud.com%2Ftracks%2F16530992&auto_play=false&show_artwork=true&color=2b877f");
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

		// the notes pages
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
		
		// the credit page
		//_creditsPage = createHeaderContentPage("Credits", "This is a Cocktail demo. Cocktail is a cross-platform library for the HaXe programming language. It bridges the gap between all the targets supported by haXe, removing inconsistencies behind a common API. With it, the same code base is used to deploy to these targets: Flash, javaScript, PHP. It helps multi device application development and should be used by haXe projects requiring cross-target compilation. Silex Labs Cocktail library is released under GPL. Project home: http://www.silexlabs.org/groups/labs/cocktail/");
		_creditsPage = createHeaderListPage(
			"Credits",
			[
				{text:"made with Cocktail", imagePath:"images/cocktail.jpg", action:"goToUrl", actionTarget:"http://www.silexlabs.org/groups/labs/cocktail/" },
				{text:"using haXe language", imagePath:"images/haxe.png", action:"goToUrl", actionTarget:"http://haxe.org/" },
				{text:"done for Silex Labs", imagePath:"images/silex_labs.jpg", action:"goToUrl", actionTarget:"http://www.silexlabs.org/" },
				{text:"by Raphael Harmel", imagePath:"images/google+.ico", action:"goToUrl", actionTarget:"http://plus.google.com/104338051403006926915" },
				{text:"source Code", imagePath:"images/github.jpg", action:"goToUrl", actionTarget:"https://github.com/silexlabs/Cocktail/tree/develop/demo/simple-webapp" },
				{text:"", imagePath:null, action:"", actionTarget:"" },
				{text:"based on jPint project idea", imagePath:"images/chevron.png", action:"goToUrl", actionTarget:"http://www.journyx.com/jpint/" },
				{text:"which is based on Joe Hewitt iUI", imagePath:"images/chevron.png", action:"", actionTarget:"http://www.iui-js.org/" },
				{text:"iconspedia.com", imagePath:"images/chevron.png", action:"goToUrl", actionTarget:"http://www.iconspedia.com/pack/iphone/" },
				{text:"iconarchive.com", imagePath:"images/chevron.png", action:"goToUrl", actionTarget:"http://www.iconarchive.com/category/business/dragon-soft-icons-by-artua.html" }
			]
		);

		// the home page
		_homePage = createHomePage(
			[
				{text:"Cal", imagePath:"images/NavButtonCalendarHD.png", action:"goToPage", actionTarget:_calListPage },
				{text:"Music", imagePath:"images/NavButtonMusicHD.png", action:"goToPage", actionTarget:_artistListPage },
				{text:"Gallery", imagePath:"images/NavButtonGalleryHD.png", action:"goToPage", actionTarget:_artistListPage },
				{text:"Notes", imagePath:"images/NavButtonNotesHD.png", action:"goToPage", actionTarget:_noteListPage },
				{text:"Credits", imagePath:"images/NavButtonCreditsHD.png", action:"goToPage", actionTarget:_creditsPage }
			]
		);
		_currentPage = _homePage;
		
		// adds the home page to pagesContainer
		pagesContainer.addChild(_homePage);
	}
	
	/**
	 * Hides the current page and shows the wanted page
	 * 
	 * @param	page			the wanted page
	 */
	private function showPage(page:ContainerDOMElement):Void
	{
		pagesContainer.removeChild(_currentPage);
		pagesContainer.addChild(page);
		_currentPage = page;
	}
	
	/**
	 * Opens the wanted URL - not supported by Cocktail yet so conditionnal compilation is used
	 * 
	 * @param	url		the url to open
	 */
	private function goToUrl(url:String)
	{
		#if js
		js.Lib.window.open(url);
		
		#elseif flash9
		var request:flash.net.URLRequest = new flash.net.URLRequest(url);
		flash.Lib.getURL(request);

		#end
	}
	
	/**
	 * Called when a new cell is selected in a list
	 * 
	 * @param	cell
	 */
	private function onChangeListCallback(cell:CellModel)
	{
		if (cell.action == "goToPage")
		{
			showPage(cell.actionTarget);
		}
		if (cell.action == "goToUrl")
		{
			goToUrl(cell.actionTarget);
		}
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
		backGround.load(homeTilePath);

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
	 * @param	title
	 * @param	cellDataArray
	 * @return	the corresponding page
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
	 * @param	title
	 * @param	content
	 * @return	the corresponding page
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
	 * Creates an embedded header page
	 * 
	 * @param	title
	 * @param	embeddedLink
	 * @return	the corresponding page
	 */
	private function createEmbedContentPage(title:String, embeddedLink:String):ContainerDOMElement
	{
		var page:ContainerDOMElement = Utils.getContainer();
		
		// create header
		var header:ContainerDOMElement = createHeader(title);

		
		// create content
		/*var textElement:TextElement = new TextElement(content);
		var textContainer:ContainerDOMElement = Utils.getContainer();
		textContainer.addText(textElement);
		WebAppStyle.getTextContentStyle(textContainer);*/
		// create embedded element
		var embeddedElement:EmbeddedDOMElement = new EmbeddedDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("embed")));
		//var rl:ResourceLoader = new ResourceLoader();
		//rl.load(embeddedLink, null,null);
		
		// build hierarchy
		page.addChild(header);
		//page.addChild(textContainer);
		//page.addChild(rl);
		WebAppStyle.getPageStyle(page);
		
		return page;
	}
	
	/**
	 * Creates a header with a Tile, a title and a back button
	 * 
	 * @param	title
	 * @return	the header
	 */
	private function createHeader(title:String):ContainerDOMElement
	{
		// create header
		
		// Tile image
		var header:ContainerDOMElement = Utils.getContainer();
		var headerTile:ImageDOMElement = new ImageDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.image));
		var headerTilePath:String = "images/H1.png";
		
		//headerTile.style.width = DimensionStyleValue.percent(100);
		//headerTile.style.height = DimensionStyleValue.length(px(43));
		WebAppStyle.getHeaderTileStyle(headerTile);
		headerTile.load(headerTilePath);
		
		
		// Back button
		var backButtonContainer:ContainerDOMElement = Utils.getContainer();
		WebAppStyle.getBackButtonStyle(backButtonContainer);
		// image
		var backButtonArrowLeft:ImageDOMElement = new ImageDOMElement();
		WebAppStyle.getBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.load('images/blackButtonLeft.png');
		backButtonContainer.addChild(backButtonArrowLeft);
		var backButtonArrowRight:ImageDOMElement = new ImageDOMElement();
		WebAppStyle.getBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.load('images/blackButtonRight.png');
		backButtonContainer.addChild(backButtonArrowRight);
		// text
		var backButtonTextContainer:ContainerDOMElement = Utils.getContainer();
		WebAppStyle.getBackButtonTextStyle(backButtonTextContainer);
		var backButtonText:TextElement = new TextElement('Back');
		backButtonTextContainer.addText(backButtonText);
		backButtonContainer.addChild(backButtonTextContainer);
		backButtonContainer.onMouseUp = onBackButtonMouseUp;

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
	
	/**
	 * Called when there is an error while loading a picture
	 * @param	error
	 */
	private function onImageLoadError(error:String):Void
	{
		trace(error);
	}
	
	/**
	 * Create home's richList
	 * 
	 * @param	content
	 * @return	the corresponding richlist
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
			cellText:StyleApp.getCellTextStyle,
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
	 * @param	content
	 * @return	the corresponding richlist
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
			cellText:StyleNormal.getCellTextStyle,
			cellMouseOver:StyleNormal.getCellMouseOverStyle,
			cellMouseOut:StyleNormal.getCellMouseOutStyle,
			cellMouseDown:StyleNormal.getCellMouseDownStyle,
			cellMouseUp:StyleNormal.getCellMouseUpStyle}
		
		var list:RichList = new RichList(listData, listStyle);
		
		return list;
	}
	
	/**
	 * Callback called on mouse release of the back header button
	 * 
	 * @param	mouseEvent
	 */
	private function onBackButtonMouseUp(mouseEvent:MouseEventData):Void
	{
		showPage(_homePage);
	}
}
