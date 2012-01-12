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
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.textElement.TextElement;
import components.dataProvider.XmlLoader;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// Lists specific
import components.lists.ListBase;
import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;
import components.lists.ThumbTextList1Style;
import components.lists.ThumbTextList1;
import components.dataProvider.ThumbTextList1Rss;
import components.lists.AppList;
import components.lists.AppListStyle;

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
	//private var _homePage:ContainerDOMElement;
	
	// the template page
	private var _themesPage:ContainerDOMElement;
	
	// the plugins page
	private var _pluginsPage:ContainerDOMElement;
	
	// the blog page
	private var _blogPage:ContainerDOMElement;
	

	public function new() 
	{
		pagesContainer = Utils.getContainer();
		
		// create all pages
		createAllPages();
		
		// instanciate navigation class with pagesContainer and homePage
		//navigation = new Navigation(pagesContainer,_pluginsPage);
		
		//var footer:ContainerDOMElement = createFooterMenu();
		//pagesContainer.addChild(footer);
	}
	
	/**
	 * Create all pages
	 */
	private function createAllPages()
	{
		// create pages
		
		// plugins Page
		var pluginsRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&format=rss2&posts_per_page=10");
		pluginsRss.onLoad = onPluginsRssLoad;
		
		// themes Page
		var themesRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2&posts_per_page=10");
		themesRss.onLoad = onThemesRssLoad;
		
		// themes Page
		var blogRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=1&format=rss2&posts_per_page=10");
		blogRss.onLoad = onBlogRssLoad;
		
	}
	
	/**
	 * Callback when plugins rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPluginsRssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		//_pluginsPage = createThemePage(cells);
		_pluginsPage = createHeaderListPage("Plugins", cells);
		
		// instanciate navigation class with pagesContainer and start page
		navigation = new Navigation(pagesContainer,_pluginsPage);
	}
	
	/**
	 * Callback when themes rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onThemesRssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_themesPage = createHeaderListPage("Themes", cells);
	}
	
	/**
	 * Callback when blog rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onBlogRssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_blogPage = createHeaderListPage("Blog", cells);
		
		var footer:ContainerDOMElement = createFooterMenu();
		pagesContainer.addChild(footer);
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

		
		// create list data & style
		var list:ThumbTextList1 = createThumbList(cellDataArray);
		
		// list onChange callback
		list.onChange = onChangeListCallback;
		//list.onChange = navigation.onChangeListCallback;
		
		// build hierarchy
		page.addChild(header);
		page.addChild(list);
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
		var header:ContainerDOMElement = Utils.getContainer();
		
		// Tile image
		var headerTile:ImageDOMElement = new ImageDOMElement();
		WebAppStyle.getHeaderTileStyle(headerTile);
		var headerTilePath:String = "images/header.jpg";
		headerTile.load(headerTilePath);
		// attach to header container
		header.addChild(headerTile);
		
		// Logo image
		var headerLogo:ImageDOMElement = new ImageDOMElement();
		WebAppStyle.getHeaderLogoStyle(headerLogo);
		var headerLogoPath:String = "images/silex-labs.png";
		headerLogo.load(headerLogoPath);
		// attach to header container
		header.addChild(headerLogo);
		
		
		// header title
		var headerTitle:TextElement = new TextElement(title);
		var headerTitleContainer:ContainerDOMElement = Utils.getContainer();
		headerTitleContainer.addText(headerTitle);
		WebAppStyle.getHeaderTextStyle(headerTitleContainer);
		// attach to header container
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
		// apply page style
		WebAppStyle.getHeaderStyle(container);
		
		// Tile image
		var tile:ImageDOMElement = new ImageDOMElement();
		var headerTilePath:String = "images/footer.jpg";
		WebAppStyle.getFooterTileStyle(tile);
		tile.load(headerTilePath);
		// build hierarchy
		container.addChild(tile);
		
		// Menu items
		/*var menuList:AppList = createAppList(
			[
				{content:{icon:"images/menu1.png",title:"Plugins"}, action:"goToPage", actionTarget:_pluginsPage},
				{content:{icon:"images/menu2.png",title:"Themes"}, action:"goToPage", actionTarget:_themesPage},
				{content:{icon:"images/menu3.png",title:"Blog"}, action:"goToPage", actionTarget:_blogPage}
			]);*/
		var cells:Array<CellModel> = new Array<CellModel>();
		cells.push({content:{icon:"images/menu1.png",title:"Plugins"}, action:"goToPage", actionTarget:_pluginsPage});
		cells.push({content:{icon:"images/menu2.png",title:"Themes"}, action:"goToPage", actionTarget:_themesPage});
		cells.push({content:{icon:"images/menu3.png",title:"Blog"}, action:"goToPage", actionTarget:_blogPage});
		var menuList:AppList = createAppList(cells);
		
		// list onChange callback
		menuList.onChange = onChangeListCallback;
		//menuList.onChange = onChangeMenuListCallback;
		
		container.addChild(menuList);
		
		return container;
	}
	
	/**
	 * Create thumbList
	 * 
	 * @param	content
	 * @return	the corresponding list
	 */
	private function createThumbList(content:Array<CellModel>):ThumbTextList1
	{
		// data
		var listData:ListModel = ListBaseUtils.createListModel();
		
		listData.content = content;
		
		// style
		var listStyle:Dynamic = {
			list:ThumbTextList1Style.getListStyle,
			cell:ThumbTextList1Style.getCellStyle,
			cellInfoBlock:ThumbTextList1Style.getCellInfoBlockStyle,
			cellNumber:ThumbTextList1Style.getCellNumberStyle,
			cellInfoBlockImage:ThumbTextList1Style.getCellInfoBlockImageStyle,
			cellCommentCount:ThumbTextList1Style.getCellCommentCountStyle,
			cellThumbnail:ThumbTextList1Style.getCellThumbnailStyle,
			cellTextBlock:ThumbTextList1Style.getCellTextBlockStyle,
			cellTitle:ThumbTextList1Style.getCellTitleStyle,
			cellComment:ThumbTextList1Style.getCellCommentStyle,
			cellDescription:ThumbTextList1Style.getCellDescriptionStyle,
			cellLine:ThumbTextList1Style.getCellLineStyle,
			cellMouseOver:ThumbTextList1Style.getCellMouseOverStyle,
			cellMouseOut:ThumbTextList1Style.getCellMouseOutStyle,
			cellMouseDown:ThumbTextList1Style.getCellMouseDownStyle,
			cellMouseUp:ThumbTextList1Style.getCellMouseUpStyle}
		
		var list:ThumbTextList1 = new ThumbTextList1(listData, listStyle);
		
		return list;
	}
	
	/**
	 * Create menu list
	 * 
	 * @param	content
	 * @return	the corresponding list
	 */
	private function createAppList(content:Array<CellModel>):AppList
	{
		// data
		var listData:ListModel = ListBaseUtils.createListModel();
		
		listData.content = content;
		
		// style
		var listStyle:Dynamic = {
			list:AppListStyle.getListStyle,
			cell:AppListStyle.getCellStyle,
			cellSelected:AppListStyle.getCellSelectedStyle,
			cellIcon:AppListStyle.getCellImageStyle,
			cellTitle:AppListStyle.getCellTextStyle,
			cellMouseOver:AppListStyle.getCellMouseOverStyle,
			cellMouseOut:AppListStyle.getCellMouseOutStyle,
			cellMouseDown:AppListStyle.getCellMouseDownStyle,
			cellMouseUp:AppListStyle.getCellMouseUpStyle}
		
		var list:AppList = new AppList(listData, listStyle);
		
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
