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
import cocktail.geom.GeomData;
import cocktail.resource.ResourceLoaderManager;
import cocktailCore.resource.ResourceLoader;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.textElement.TextElement;
import components.dataProvider.RssUtils;
import components.dataProvider.XmlLoader;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList specific
import components.richList.RichList;
import components.richList.RichListModels;
import components.richList.StyleNormal;
import components.richList.StyleThumbText;
import components.richList.StyleApp;
import components.richList.RichListUtils;

// Gallery specific
import components.gallery.Gallery;

// Navigation
import Navigation;

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

	// navigation is used for navigation
	private var navigation:Navigation;

	
	// the home page
	private var _homePage:ContainerDOMElement;
	
	// the template page
	private var _themesPage:ContainerDOMElement;
	
	// the plugins page
	private var _pluginsPage:ContainerDOMElement;
	

	public function new() 
	{
		pagesContainer = Utils.getContainer();
		//IphoneStyle.getPageContainerStyle(pagesContainer);
		
		// create all pages
		createAllPages();
		
		// instanciate navigation class with pagesContainer and homePage
		//navigation = new Navigation(pagesContainer,_homePage);
		//navigation = new Navigation(pagesContainer,_themesPage);
	}
	
	/**
	 * Create all pages
	 */
	private function createAllPages()
	{
		// create pages
		_homePage = createHeaderListPage(
			"Silex Labs",
			[
				{text:"Item 1", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 2", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 3", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 4", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 5", imagePath:"", action:"", actionTarget:"" }
			]
		);
		
		//var rss:XmlLoader = new XmlLoader("http://www.silexlabs.org/category/feed/ep_posts_in_category/?format=rss2&cat=646");
		var rss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2");
		//var rss:XmlLoader = new XmlLoader("http://feeds.feedburner.com/France2-ActuSciencesTech?format=xml");
		//var rss:XmlLoader = new XmlLoader("http://api.flickr.com/services/feeds/photos_public.gne?lang=fr-fr&format=rss_200");
		rss.onLoad = onThemeRssLoad;
		
		// create picture and text richlist page
		_pluginsPage = createHeaderListPage(
			"Plugins",
			[
				{text:"Plugin 1", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 2", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 3", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 4", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 5", imagePath:"", action:"", actionTarget:"" }
			]
		);
	}
	
	/**
	 * Callback when theme rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onThemeRssLoad(rss:Xml):Void
	{
		var pluginsCells:Array<CellModel> = RssUtils.rss2Cells(rss);
		_themesPage = createThemePage(pluginsCells);
		
		// instanciate navigation class with pagesContainer and homePage
		//navigation = new Navigation(pagesContainer,_homePage);
		navigation = new Navigation(pagesContainer,_themesPage);

	}
	
	private function createThemePage(cells:Array<CellModel>):ContainerDOMElement
	{
		// create picture and text richlist page
		_themesPage = createHeaderListPage("Themes", cells);
		
		return _themesPage;
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
		var richList:RichList = createImageTextRichList(cellDataArray);
		
		// rich list onChange callback
		richList.onChange = onChangeListCallback;
		//richList.onChange = navigation.onChangeListCallback;
		
		// build hierarchy
		page.addChild(header);
		page.addChild(richList);
		WebAppStyle.getPageStyle(page);
		
		return page;
	}
	
	
	/**
	 * Creates a header with a Tile and a title
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
		
		WebAppStyle.getHeaderTileStyle(headerTile);
		headerTile.load(headerTilePath);
		
		// header title
		var headerTitle:TextElement = new TextElement(title);
		var headerTitleContainer:ContainerDOMElement = Utils.getContainer();
		headerTitleContainer.addText(headerTitle);
		WebAppStyle.getHeaderTextStyle(headerTitleContainer);
		
		// build hierarchy
		header.addChild(headerTile);
		header.addChild(headerTitleContainer);
		
		// build page style & domElement
		WebAppStyle.getHeaderStyle(header);

		return header;
	}
	
	/**
	 * Creates a back button arrow with a title
	 * 
	 * @param	title
	 * @return	the back button
	 */
	private function createBackButton(title:String):ContainerDOMElement
	{
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
		backButtonContainer.onMouseUp = goToPreviousPage;

		return backButtonContainer;
	}
	
	/**
	 * Create music's richList
	 * 
	 * @param	content
	 * @return	the corresponding richlist
	 */
	private function createImageTextRichList(content:Array<CellModel>):RichList
	{
		// data
		var listData:RichListModel = RichListUtils.createRichListModel();
		
		listData.content = content;
		
		// style
		var listStyle:RichListStyleModel = {
			list:StyleThumbText.getDefaultStyle,
			cell:StyleThumbText.getCellStyle,
			cellImage:StyleThumbText.getCellImageStyle,
			cellText:StyleThumbText.getCellTextStyle,
			cellMouseOver:StyleThumbText.getCellMouseOverStyle,
			cellMouseOut:StyleThumbText.getCellMouseOutStyle,
			cellMouseDown:StyleThumbText.getCellMouseDownStyle,
			cellMouseUp:StyleThumbText.getCellMouseUpStyle}
		
		var list:RichList = new RichList(listData, listStyle);
		
		return list;
	}
	
	/**
	 * Callback called on mouse release of the back header button
	 * 
	 * @param	mouseEvent
	 */
	public function goToPreviousPage(mouseEvent:MouseEventData):Void
	{
		// show previous page in the history
		navigation.goToPreviousPage();
	}

	/**
	 * Called when a new cell is selected in a list
	 * 
	 * @param	cell
	 */
	public function onChangeListCallback(cell:CellModel)
	{
		navigation.onChangeListCallback(cell);
	}
	
}
