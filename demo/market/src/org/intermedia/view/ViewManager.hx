package org.intermedia.view;

import haxe.Firebug;
import haxe.Http;
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.controller.ApplicationController;
import org.intermedia.model.ApplicationModel;
//import org.intermedia.view.SwippableListView;
import org.intermedia.model.Feeds;

/**
 * In charge of instantiating the views, listening to the application model changes and communicating with the controller.
 * 
 * @author Raphael Harmel
 */

class ViewManager
{

	// bodyDOMElement
	private var _body:Body;
	//private var _body:HtmlDom;
	
	//Reference to the header of the application, which is always displayed
	private var _header:HeaderView;
	
	// reference to the menu
	private var _menu:MenuListViewText;
	//private var _menu:ScrollableMenu;
	
	//Ref to the container managing the swippable list view
	private var _swippableListView:SwippableListView;
	
	//Ref to the view displaying full article
	private var _detailView:DetailView;
	
	//Ref to the view displayed when there is a loading error
	//private var _errorView:ErrorView;
	//private var _errorView:HtmlDom;
	
	//listen to model change on it
	private var _applicationModel:ApplicationModel;
	
	//proxies interaction with the model
	private var _applicationController:ApplicationController;
	
	//A ref to the currently displayed main view (not the header)
	//private var _currentView:ViewBase;
	
	// _time is used to compute execution time for analysing performance
	private var _time:Float;
	
	/**
	 * Store ref to application model and controller. Instantiate headerView, loadingView, swippableView then call init().
	 * 
	 * @param	applicationModel
	 * @param	applicationController
	 */
	public function new(applicationModel:ApplicationModel, applicationController:ApplicationController)
	{
		// set the time
		_time = Timer.stamp();

		// simple haxe js test
		//var text:HtmlDom = Lib.document.createTextNode("hello de LU");
		//_body.appendChild(text);
		//var image:Image = cast Lib.document.createElement("img");
		//image.src = "assets/loading.gif";
		//_body.appendChild(image);
		
		// Store ref to application model and controller
		_applicationModel = applicationModel;
		_applicationController = applicationController;
		
		// Instantiate body, headerView, loadingView, swippableView
		_body = Lib.document.body;
		ViewManagerStyle.setBodyStyle(_body);
		
		_header = new HeaderView();
		_header.data = Constants.HEADER_HOME_TITLE;
		_header.onBackButtonClick = onHeaderBackButtonPressed;
		_body.appendChild(_header.node);
		
		// init menu
		_menu = new MenuListViewText();
		//_menu = new ScrollableMenu();
		_menu.displayListBottomLoader = false;
		_body.appendChild(_menu.node);
		_menu.data = [Feeds.FEED_1, Feeds.FEED_2, Feeds.FEED_3];
		
		// init swippable view
		_swippableListView = new SwippableListView();
		// set current view on swippable view
		//_currentView = _swippableListView;
		// attach swippable view to body
		_body.appendChild(_swippableListView.node);
		
		// onresize callback
		//Lib.window.onresize = onResizeCallback;
		Lib.window.onresize = function (event:Event) { onResizeCallback();};
		// on scroll callback is placed here for iPhone & Android phones, so that swippableView is resized when navigation bar is hidden
		// can be removed in native apps
		//Lib.window.onscroll = onResizeCallback;

		// call init()
		init();
		
		//_header.node.style.visibility = "hidden";
		//_menu.node.style.visibility = "hidden";

		//Firebug.trace("ViewManager built in " + Std.string((Timer.stamp() - _time) * 1000).substr(0, 5) + "ms");
		//trace("ViewManager built in " + Std.string((Timer.stamp() - _time) * 1000).substr(0, 5) + "ms");
		
	}
	
	/**
	 * Sets callback on the model to be notified of model changes.
	 * call loadCellData() on the application controller with thedefault cell number (between 5 to 10)
	 */
	private function init():Void
	{
		// Sets callback on the model to be notified of model changes.
		_applicationModel.onModelStartsLoading = onStartLoading;
		_applicationModel.onModelDataLoadError = onLoadingError;
		_applicationModel.onModelCellDataLoaded = onCellDataLoaded;
		_applicationModel.onModelDetailDataLoaded = onDetailDataLoaded;
		
		
		// Sets callback on the view to be notified of user actions.
		// set menu item selelected callback
		_menu.onListItemSelected = onMenuItemSelectedCallback;
		
		// set swippableView callbacks
		_swippableListView.onListItemSelected = onListItemSelectedCallback;
		_swippableListView.onDataRequest = _applicationController.loadCellData;
		_swippableListView.onHorizontalMove = _menu.moveHorizontally;
		//_swippableListView.onHorizontalUp = _menu.horizontalUp;
		_swippableListView.onHorizontalTweenEnd = _menu.horizontalTweenEnd;
		
		// Call loadCellData() on the application controller with the default cell number (between 5 to 10)
		_applicationController.loadCellData(Feeds.FEED_1.url);
		_applicationController.loadCellData(Feeds.FEED_2.url);
		_applicationController.loadCellData(Feeds.FEED_3.url);
		
	}
	
	/**
	 * on menu item item clicked
	 * 
	 * @param	cellData
	 */
	private function onMenuItemSelectedCallback(cellData:CellData):Void
	{
		_swippableListView.resetInitScrollPosition();
		_swippableListView.index = cellData.id;
	}
	
	/**
	 * on list item selected callback
	 */
	private function onListItemSelectedCallback(cellData:CellData):Void
	{
		//trace(Lib.window.innerWidth);
		//trace(Lib.window.screen.width);
		// remove swippable view touch events listener
		//_swippableListView.unsetTouchEvents();
		// remove swippableListView and menu and add empty detail view
		_body.removeChild(_swippableListView.node);
		_body.removeChild(_menu.node);

		// to be used once switching to cocktail js version
		//_swippableListView.style.visibility = VisibilityStyleValue.hidden;
		//_menu.style.display = DisplayStyleValue.none;
		
		// create detail view and add it to the body
		_detailView = new DetailView();
		_body.appendChild(_detailView.node);
		
		// start listening to touch event on detail view
		//_detailView.addTouchEvents();
		
		// set current view to detail view
		//_currentView = _detailView;

		// request detail view loading to controller
		//_applicationController.openDetailView(cellData);
		onDetailDataLoaded(cellData);
	}
	
	/**
	 * Open the listView and / or refresh its data.
	 * 
	 * @param	cellsData
	 */
	//public function onCellDataLoaded(cellsData:Array<CellData>):Void
	public function onCellDataLoaded(listData:ListData):Void
	{
		//trace("onCellDataLoaded");
		// if no more data fetched, remove bottom loader
		if (listData.cells.length == 0) _swippableListView.displayListBottomLoader = false;
		
		// update data
		//_swippableListView.data = listData.cells;
		_swippableListView.data = listData;
		
		// update header zIndex using a workaround so it always visible
		updateZIndexes();
		//setZIndexToMax(_menu);
		//setZIndexToMax(_header);
		
		// remove loading view from swippable view
		//_swippableListView.displayLoading = false;
	}
	
	/**
	 * Open the detailView and / or refresh its data. Set displayBackButton on the headerView
	 * 
	 * @param	detailData
	 */
	public function onDetailDataLoaded(detailData:DetailData):Void
	{
		// update detail view data
		_detailView.data = detailData;
		// update header title
		_header.data = Constants.HEADER_DETAIL_TITLE;
		// display header back button
		_header.displayBackButton = true;
		
		// update header zIndex using a workaround
		//updateZIndexes();
		setZIndexToMax(_header);
		
		// hide loader
		_detailView.displayLoading = false;
		
		onResizeCallback();
	}
	
	/**
	 * set displayLoading to true on the current view
	 */
	public function onStartLoading():Void
	{
		//trace("onStartLoading");
		//_currentView.displayLoading = true;
	}
	
	/**
	 * Display the error view
	 */
	public function onLoadingError(error:Dynamic):Void
	{
		trace("Load error: " + Std.string(error));
		haxe.Firebug.trace("Load error: " + Std.string(error));
	}
	
	/**
	 * Call goBackToListView on the application controller.
	 */
	public function onHeaderBackButtonPressed():Void
	{
		//trace(Lib.window.innerWidth);
		//trace(Lib.window.screen.width);
		
		//_applicationController.goBackToListView();

		// update header title
		_header.data = Constants.HEADER_HOME_TITLE;
		// hide header back button
		_header.displayBackButton = false;
		
		// remove detail view and add swippableListView
		_body.removeChild(_detailView.node);
		_body.appendChild(_menu.node);
		_body.appendChild(_swippableListView.node);
		//_swippableListView.style.display = "inline-block";
		//_swippableListView.isVisible = true;
		
		
		// to be used once switching to cocktail js version
		//_swippableListView.style.visibility = VisibilityStyleValue.hidden;
		//_menu.style.display = "block";

		
		// update zIndex
		updateZIndexes();
		//setZIndexToMax(_menu);
		//setZIndexToMax(_header);

		// set current view on swippable view
		//_currentView = _swippableListView;
		
		// remove detailview touch events listener
		//_detailView.unsetTouchEvents();

		// start listening to touch event on _swippableListView
		//_swippableListView.addTouchEvents();
		
		// on resize callback is called here to resolve an Android Browser bug, where application width is not refreshed correctly
		_swippableListView.scrollToCurrentList();
		//Timer.delay( onResizeCallback, 1);
		onResizeCallback();
	}
	
	/**
	 * updates header and menu zIndex to the maximum value.
	 * Uses a workaround as zIndex is not implemented yet in Cocktail
	 */
	private function updateZIndexes():Void
	{
		setZIndexToMax(_menu);
		setZIndexToMax(_header);
	}
	
	/**
	 * updates zIndex to the maximum value.
	 * Uses a workaround as zIndex is not implemented yet in Cocktail
	 */
	private function setZIndexToMax(view:ViewBase):Void
	{
		// remove and add dom so it has the higher zIndex
		_body.removeChild(view.node);
		_body.appendChild(view.node);
	}
	
	/**
	 * on rezize callback
	 */
	//private function onResizeCallback(event:Event):Void
	private function onResizeCallback():Void
	{
		// launch needed callbacks
		//_header.refreshStyles();
		//_menu.onResizeCallback();
		_menu.refreshStyles();
		//_swippableListView.onResizeCallback(event);
		_swippableListView.refreshStyles();
		
		_detailView.refreshStyles();
	}

	
}
