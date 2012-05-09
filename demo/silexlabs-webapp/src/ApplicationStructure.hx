/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

import js.Lib;
import js.Dom;

import components.dataProvider.XmlLoader;


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
	public var pagesContainer:HtmlDom;

	// navigation is used for navigation
	private var navigation:Navigation;
	
	// the home page
	//private var _homePage:ContainerDOMElement;
	
	// footer
	private var _footer:HtmlDom;
	
	// page 1
	private var _page1:HtmlDom;
	
	// page 2
	private var _page2:HtmlDom;
	
	// page 3
	private var _page3:HtmlDom;
	
	// page 4
	private var _page4:HtmlDom;
	
	// page 5
	private var _page5:HtmlDom;
	
	// quantity of rss items to return
	//static inline var ITEM_QUANTITY:Int = 5;
	
	// page 1 title
	static inline var PAGE1_TITLE:String = "Silex Labs";

	// page 2 title
	static inline var PAGE2_TITLE:String = "amfPHP";

	// page 3 title
	static inline var PAGE3_TITLE:String = "Silex";

	// page 4 title
	static inline var PAGE4_TITLE:String = "Themes";

	// page 5 title
	static inline var PAGE5_TITLE:String = "Plugins";

	public function new() 
	{
		pagesContainer = Utils.getContainer();
		
		//_footer = createFooterMenu();
		//pagesContainer.addChild(_footer);
		
		// create all pages
		createAllPages();
		
		// instanciate navigation class with pagesContainer and homePage
		//navigation = new Navigation(pagesContainer,_page2);
		
	}
	
	/**
	 * Create all pages
	 */
	private function createAllPages()
	{
		// create pages
		
		// Silex Labs BLog Page
		//var pluginsRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&format=rss2&posts_per_page=" + ITEM_QUANTITY);
		var pluginsRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=5318&format=rss2");
		pluginsRss.onLoad = onPage1RssLoad;
		
		// AmfPHP Blog Page
		//var blogRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=1&format=rss2&posts_per_page=" + ITEM_QUANTITY);
		var blogRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=358&format=rss2");
		blogRss.onLoad = onPage2RssLoad;
		
		// Silex Blog Page
		//var themesRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2&posts_per_page=" + ITEM_QUANTITY);
		var themesRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=642&format=rss2");
		themesRss.onLoad = onPage3RssLoad;
		
		// Silex Themes Page
		//var themesRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2&posts_per_page=" + ITEM_QUANTITY);
		var themesRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=646&format=rss2");
		themesRss.onLoad = onPage4RssLoad;
		
		// Silex plugins Page
		//var pluginsRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&format=rss2&posts_per_page=" + ITEM_QUANTITY);
		var pluginsRss:XmlLoader = new XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=657&format=rss2");
		pluginsRss.onLoad = onPage5RssLoad;
		
	}
	
	/**
	 * Callback when page 1 rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPage1RssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_page2 = createHeaderListPage(PAGE1_TITLE, cells);
		
		// instanciate navigation class with pagesContainer and start page
		navigation = new Navigation(pagesContainer,_page2);
	}
	
	/**
	 * Callback when page 2 rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPage2RssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_page1 = createHeaderListPage(PAGE2_TITLE, cells);
	}
	
	/**
	 * Callback when page 3 rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPage3RssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_page3 = createHeaderListPage(PAGE3_TITLE, cells);
	}
	
	/**
	 * Callback when page 4 rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPage4RssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_page4 = createHeaderListPage(PAGE4_TITLE, cells);
	}
	
	/**
	 * Callback when page 1 rss has been loaded
	 * 
	 * @param	rss
	 */
	private function onPage5RssLoad(rss:Xml):Void
	{
		var cells:Array<CellModel> = ThumbTextList1Rss.rss2Cells(rss);
		_page5 = createHeaderListPage(PAGE5_TITLE, cells);
		
		_footer = createFooterMenu();
		pagesContainer.appendChild(_footer);
		//pagesContainer.onKeyDown = onKeyDownPages;
		
		// workaround for browsers not supporting well css "fixed" position
		#if js

		function resetFooterStyle(event) {
			// footer is removed and added again as a workaround
			pagesContainer.removeChild(_footer);
			pagesContainer.appendChild(_footer);
		};
		
		js.Lib.window.onscroll = resetFooterStyle;
		js.Lib.window.onresize = resetFooterStyle;
		
		// this part is done only for keyboard event part
		resetFooterStyle(null);
		js.Lib.document.onkeydown = onKeyDownPages;
		#end

	}
	
	/**
	 * Creates a list header page
	 * 
	 * @param	title
	 * @param	cellDataArray
	 * @return	the corresponding page
	 */
	private function createHeaderListPage(title:String, cellDataArray:Array<CellModel>):HtmlDom
	{
		var page = Utils.getContainer();
		
		// create header
		var header = createHeader(title);

		
		// create list data & style
		var list:ThumbTextList1 = createThumbList(cellDataArray);
		
		// list onChange callback
		list.onChange = onChangeListCallback;
		//list.onChange = navigation.onChangeListCallback;
		
		// build hierarchy
		page.appendChild(list.htmlDom);
		page.appendChild(header);
		WebAppStyle.getPageStyle(page);
		
		return page;
	}
	
	
	/**
	 * Creates a header with a Tile and a title
	 * 
	 * @param	title
	 * @return	the header
	 */
	private function createHeader(title:String):HtmlDom
	{
		// create header
		var header = Utils.getContainer();
		
		// Tile image
		var headerTile:Image = cast(Lib.document.createElement("img"));
		WebAppStyle.getHeaderTileStyle(headerTile);
		var headerTilePath:String = "images/header.jpg";
		headerTile.src = headerTilePath;
		// attach to header container
		header.appendChild(headerTile);
		
		// Logo image
		var headerLogo:Image = cast(Lib.document.createElement("img"));
		WebAppStyle.getHeaderLogoStyle(headerLogo);
		var headerLogoPath:String = "images/silex-labs.png";
		headerLogo.src = headerLogoPath;
		// attach to header container
		header.appendChild(headerLogo);
		
		
		// header title
		var headerTitle = Lib.document.createTextNode(title);
		var headerTitleContainer = Utils.getContainer();
		headerTitleContainer.appendChild(headerTitle);
		WebAppStyle.getHeaderTextStyle(headerTitleContainer);
		// attach to header container
		header.appendChild(headerTitleContainer);
		
		
		// build page style & domElement
		WebAppStyle.getHeaderStyle(header);

		return header;
	}
	
	/**
	 * Creates a menu footer
	 * 
	 * @return	the footer
	 */
	private function createFooterMenu():HtmlDom
	{
		// create footer
		var container = Utils.getContainer();
		// apply page style
		WebAppStyle.getFooterStyle(container);
		
		// Tile image
		var tile:Image = cast(Lib.document.createElement("img"));
		var headerTilePath:String = "images/footer.jpg";
		WebAppStyle.getFooterTileStyle(tile);
		tile.src = headerTilePath;
		// build hierarchy
		container.appendChild(tile);
		
		// Menu items
		/*var menuList:AppList = createAppList(
			[
				{content:{icon:"images/menu1.png",title:PAGE1_TITLE}, action:"goToPage", actionTarget:_page2},
				{content:{icon:"images/menu2.png",title:PAGE2_TITLE}, action:"goToPage", actionTarget:_page1},
				{content:{icon:"images/menu3.png",title:PAGE3_TITLE}, action:"goToPage", actionTarget:_page3}
			]);*/
		var cells:Array<CellModel> = new Array<CellModel>();
		//var cell1:CellModel = {content:{}, action:"", actionTarget:null}
		//cell1.content = { icon:"images/menu1.png", title:PAGE1_TITLE };
		//cell1.action = "goToPage";
		//cell1.actionTarget = _page2;
		//cells.push(cell1);
		cells.push({content:{icon:"images/menu3.png",title:PAGE1_TITLE}, action:"goToPage", actionTarget:_page2});
		//var cell2:CellModel = {content:{}, action:"", actionTarget:null}
		//cell2.content = { icon:"images/menu2.png", title:PAGE2_TITLE };
		//cell2.action = "goToPage";
		//cell2.actionTarget = _page1;
		//cells.push(cell2);
		cells.push({content:{icon:"images/menu3.png",title:PAGE2_TITLE}, action:"goToPage", actionTarget:_page1});
		//var cell3:CellModel = {content:{}, action:"", actionTarget:null}
		//cell3.content = { icon:"images/menu3.png", title:PAGE3_TITLE };
		//cell3.action = "goToPage";
		//cell3.actionTarget = _page3;
		//cells.push(cell3);
		cells.push({content:{icon:"images/menu3.png",title:PAGE3_TITLE}, action:"goToPage", actionTarget:_page3});
		cells.push({content:{icon:"images/menu2.png",title:PAGE4_TITLE}, action:"goToPage", actionTarget:_page4});
		cells.push({content:{icon:"images/menu1.png",title:PAGE5_TITLE}, action:"goToPage", actionTarget:_page5});

		
		var menuList:AppList = createAppList(cells);
		
		// list onChange callback
		menuList.onChange = onChangeListCallback;
		//menuList.onChange = onChangeMenuListCallback;

		// list keyboard down callback
		//menuList.onKeyDown = onMenuKeyDown;
		
		container.appendChild(menuList.htmlDom);
		
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
			cellInfoBlockLine:ThumbTextList1Style.getCellInfoBlockLineStyle,
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
	public function goToPreviousPage(mouseEvent:Event):Void
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
	
	/**
	 * Called when a key is pressed
	 */
	//private function onKeyDownPages(key:KeyEventData):Void
	private function onKeyDownPages(key:Dynamic):Void
	{
		//trace("onKeyDownPages: " + key.keyCode);
		/*if (key.value == KeyboardKeyValue.right || key.value == KeyboardKeyValue.VK_RIGHT || key.value == KeyboardKeyValue.left || key.value == KeyboardKeyValue.VK_LEFT)
		{*/
			// dispatch menu list item change
			// TODO: remove hardcoding
			//_footer.childNodes[1].child.onListKeyDown(key);
		/*}*/
	}
	
}
