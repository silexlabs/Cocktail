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
import components.richList.thumbList.ThumbList1;
import components.richList.thumbList.ThumbList1Models;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList specific
import components.richList.RichList;
import components.richList.RichListModels;
import components.richList.StyleNormal;
import components.richList.thumbList.ThumbList1Style;
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
		
		var footer:ContainerDOMElement = createFooterMenu();
		pagesContainer.addChild(footer);
	}
	
	/**
	 * Create all pages
	 */
	private function createAllPages()
	{
		// create pages
		/*_homePage = createHeaderListPage(
			"Silex Labs",
			[
				{text:"Item 1", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 2", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 3", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 4", imagePath:"", action:"", actionTarget:"" },
				{text:"Item 5", imagePath:"", action:"", actionTarget:"" }
			]
		);*/
		
		//var rss:XmlLoader = new XmlLoader("http://www.silexlabs.org/category/feed/ep_posts_in_category/?format=rss2&cat=646");
		var rss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2");
		//var rss:XmlLoader = new XmlLoader("http://feeds.feedburner.com/France2-ActuSciencesTech?format=xml");
		//var rss:XmlLoader = new XmlLoader("http://api.flickr.com/services/feeds/photos_public.gne?lang=fr-fr&format=rss_200");
		rss.onLoad = onThemeRssLoad;
		
		// create picture and text richlist page
		/*_pluginsPage = createHeaderListPage(
			"Plugins",
			[
				{text:"Plugin 1", imagePath:"", action:"goToUrl", actionTarget:"http://www.google.com" },
				{text:"Plugin 2", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 3", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 4", imagePath:"", action:"", actionTarget:"" },
				{text:"Plugin 5", imagePath:"", action:"", actionTarget:"" }
			]
		);*/
	}
	
	/**
	 * Callback when theme rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onThemeRssLoad(rss:Xml):Void
	{
		var pluginsCells:Array<DynamicCellModel> = RssUtils.rss2Cells(rss);
		//trace(pluginsCells);
		//var pluginsCells:Array<ContainerCellModel> = RssUtils.rss2ContainerCells(rss);
		//var pluginsCells:ContainerRichListModel = RssUtils.rss2ContainerCells(rss);
		_themesPage = createThemePage(pluginsCells);
		
		// instanciate navigation class with pagesContainer and homePage
		//navigation = new Navigation(pagesContainer,_homePage);
		navigation = new Navigation(pagesContainer,_themesPage);
		//navigation = new Navigation(pagesContainer,_pluginsPage);

	}
	
	private function createThemePage(cells:Array<DynamicCellModel>):ContainerDOMElement
	//private function createThemePage(cells:Array<ContainerCellModel>):ContainerDOMElement
	{
		// create picture and text richlist page
		_themesPage = createHeaderListPage("Themes", cells);
		//_themesPage = createHeaderContainerPage("Themes", cells);
		
		return _themesPage;
	}
	
	/**
	 * Creates a list header page
	 * 
	 * @param	title
	 * @param	cellDataArray
	 * @return	the corresponding page
	 */
	private function createHeaderListPage(title:String, cellDataArray:Array<DynamicCellModel>):ContainerDOMElement
	{
		var page:ContainerDOMElement = Utils.getContainer();
		
		// create header
		var header:ContainerDOMElement = createHeader(title);

		
		// create richList data & style
		//var richList:RichList = createImageTextRichList(cellDataArray);
		var richList:ThumbList1 = createThumbList(cellDataArray);
		
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
		//var headerTilePath:String = "images/H1.png";
		var headerTilePath:String = "images/greyPixel.png";
		
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
	 * Creates a menu footer
	 * 
	 * @return	the footer
	 */
	private function createFooterMenu():ContainerDOMElement
	{
		// create footer
		var container:ContainerDOMElement = Utils.getContainer();
		
		// Tile image
		var tile:ImageDOMElement = new ImageDOMElement();
		var headerTilePath:String = "images/blackPixel.png";
		WebAppStyle.getFooterTileStyle(tile);
		tile.load(headerTilePath);
		
		// Menu1 image
		/*var menu1Image:ImageDOMElement = new ImageDOMElement();
		var menu1ImagePath:String = "images/speaker.png";
		WebAppStyle.getFooterMenuStyle(menu1Image);
		tile.load(menu1ImagePath);*/
		
		// build hierarchy
		container.addChild(tile);
		//container.addChild(menu1Image);
		
		// build page style & domElement
		WebAppStyle.getHeaderStyle(container);

		return container;
	}
	
	/**
	 * Creates a back button arrow with a title
	 * 
	 * @param	title
	 * @return	the back button
	 */
	/*private function createBackButton(title:String):ContainerDOMElement
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
	}*/
	
	/**
	 * Create richList
	 * 
	 * @param	content
	 * @return	the corresponding richlist
	 */
	/*private function createImageTextRichList(content:Array<DynamicCellModel>):RichList
	{
		// data
		var listData:DynamicRichListModel = RichListUtils.createDynamicRichListModel();
		
		listData.content = content;
		
		// style
		//var listStyle:ThumbListStyleModel = {
		var listStyle:Dynamic = {
			list:ThumbListStyle1.getDefaultStyle,
			cell:ThumbListStyle1.getCellStyle,
			cellInfoBlock:ThumbListStyle1.getCellInfoBlockStyle,
			cellNumber:ThumbListStyle1.getCellNumberStyle,
			cellInfoBlockImage:ThumbListStyle1.getCellInfoBlockImageStyle,
			cellCommentCount:ThumbListStyle1.getCellCommentCountStyle,
			cellThumbnail:ThumbListStyle1.getCellThumbnailStyle,
			cellTextBlock:ThumbListStyle1.getCellTextBlockStyle,
			cellTitle:ThumbListStyle1.getCellTitleStyle,
			cellComment:ThumbListStyle1.getCellCommentStyle,
			cellDescription:ThumbListStyle1.getCellDescriptionStyle,
			cellLine:ThumbListStyle1.getCellLineStyle,
			cellMouseOver:ThumbListStyle1.getCellMouseOverStyle,
			cellMouseOut:ThumbListStyle1.getCellMouseOutStyle,
			cellMouseDown:ThumbListStyle1.getCellMouseDownStyle,
			cellMouseUp:ThumbListStyle1.getCellMouseUpStyle}
		
		var list:RichList = new RichList(listData, listStyle);
		
		return list;
	}*/
	
	/**
	 * Create thumbList
	 * 
	 * @param	content
	 * @return	the corresponding richlist
	 */
	private function createThumbList(content:Array<DynamicCellModel>):ThumbList1
	{
		// data
		var listData:DynamicRichListModel = RichListUtils.createDynamicRichListModel();
		
		listData.content = content;
		
		// style
		//var listStyle:ThumbListStyleModel = {
		var listStyle:Dynamic = {
			list:ThumbListStyle1.getDefaultStyle,
			cell:ThumbListStyle1.getCellStyle,
			cellInfoBlock:ThumbListStyle1.getCellInfoBlockStyle,
			cellNumber:ThumbListStyle1.getCellNumberStyle,
			cellInfoBlockImage:ThumbListStyle1.getCellInfoBlockImageStyle,
			cellCommentCount:ThumbListStyle1.getCellCommentCountStyle,
			cellThumbnail:ThumbListStyle1.getCellThumbnailStyle,
			cellTextBlock:ThumbListStyle1.getCellTextBlockStyle,
			cellTitle:ThumbListStyle1.getCellTitleStyle,
			cellComment:ThumbListStyle1.getCellCommentStyle,
			cellDescription:ThumbListStyle1.getCellDescriptionStyle,
			cellLine:ThumbListStyle1.getCellLineStyle,
			cellMouseOver:ThumbListStyle1.getCellMouseOverStyle,
			cellMouseOut:ThumbListStyle1.getCellMouseOutStyle,
			cellMouseDown:ThumbListStyle1.getCellMouseDownStyle,
			cellMouseUp:ThumbListStyle1.getCellMouseUpStyle}
		
		var list:ThumbList1 = new ThumbList1(listData, listStyle);
		
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
