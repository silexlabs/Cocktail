package org.intermedia.view;

//import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.viewport.Viewport;
import haxe.Timer;
import org.intermedia.controller.ApplicationController;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.SwippableListView;
import org.intermedia.model.Feeds;
//import cocktail.domElement.DOMElementData;

/**
 * In charge of instantiating the views, listening to the application model changes and communicating with the controller.
 * 
 * @author Raphael Harmel
 */

class ViewManager
{

	// bodyDOMElement
	private var _body:BodyDOMElement;
	
	//Reference to the header of the application, which is always displayed
	private var _header:HeaderView;
	//private var _header:ContainerDOMElement;
	
	static inline var HEADER_HOME_TITLE:String = "Market";
	static inline var HEADER_DETAIL_TITLE:String = "Infos";
	
	// reference to the menu
	private var _menu:MenuListViewText;
	
	//Ref to the container managing the swippable list view
	private var _swippableListView:SwippableListView;
	
	//Ref to the view displaying full article
	private var _detailView:DetailView;
	
	// loading view
	//private var _loadingView:LoadingView;
	
	//Ref to the view displayed when there is a loading error
	//private var _errorView:ErrorView;
	//private var _errorView:ContainerDOMElement;
	
	//listen to model change on it
	private var _applicationModel:ApplicationModel;
	
	//proxies interaction with the model
	private var _applicationController:ApplicationController;
	
	//A ref to the currently displayed main view (not the header)
	private var _currentView:ViewBase;
	
	/**
	 * Store ref to application model and controller. Instantiate headerView, loadingView, swippableView then call init().
	 * 
	 * @param	applicationModel
	 * @param	applicationController
	 */
	public function new(applicationModel:ApplicationModel, applicationController:ApplicationController)
	{
		// Store ref to application model and controller
		_applicationModel = applicationModel;
		_applicationController = applicationController;
		
		// Instantiate body headerView, loadingView, swippableView
		_detailView = new DetailView();
		_currentView = new ViewBase();
		_body = new BodyDOMElement();
		ViewManagerStyle.setBodyStyle(_body);
		_header = new HeaderView();
		_header.data = HEADER_HOME_TITLE;
		_header.onBackButtonClick = onHeaderBackButtonPressed;
		_body.addChild(_header);
		
		// init menu
		_menu = new MenuListViewText();
		_menu.displayListBottomLoader = false;
		_menu.data = [Feeds.FEED_1, Feeds.FEED_2, Feeds.FEED_3];
		_body.addChild(_menu);
		
		_header.isVisible = false;
		_menu.isVisible = false;
		
		// init swippable view
		_swippableListView = new SwippableListView();
		// set current view on swippable view
		_currentView = _swippableListView;
		// attach swippable view to body
		_body.addChild(_swippableListView);
		
		// call init()
		init();
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
		// set list item selelected callback
		_menu.onListItemSelected = onMenuItemSelectedCallback;
		_swippableListView.onListItemSelected = onListItemSelectedCallback;
		_swippableListView.onHorizontalTweenEnd = updateZIndexes;
		// set callback when the bottom of the scrollbar is reached
		//_swippableListView.onListScrolled = function () { _applicationController.loadCellData(CELL_QTY); };
		//_swippableListView.onListScrolled = function (feed:String) { _applicationController.loadCellData(feed); };
		//_swippableListView.onListScrolled = _applicationController.loadCellData;
		_swippableListView.onDataRequest = _applicationController.loadCellData;
		// Call loadCellData() on the application controller with the default cell number (between 5 to 10)
		//_applicationController.loadCellData(CELL_QTY);
		//_applicationController.loadCellData("http://www.silexlabs.org/feed/ep_posts_small/?cat=646&format=rss2");
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
		//trace(cellData.title + " clicked");
		//trace(cellData.id + " clicked");
		_swippableListView.index = cellData.id;
	}
	
	/**
	 * on list item selected callback
	 */
	private function onListItemSelectedCallback(cellData:CellData):Void
	{
		// remove swippableListView and menu and add empty detail view
		_body.removeChild(_swippableListView);
		_body.removeChild(_menu);
		_detailView = new DetailView();
		_body.addChild(_detailView);

		// set current view to detail view
		_currentView = _detailView;

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
		// if no more data fetched, remove bottom loader
		if (listData.cells.length == 0) _swippableListView.displayListBottomLoader = false;
		
		// update data
		//_swippableListView.data = listData.cells;
		_swippableListView.data = listData;
		
		// update header zIndex using a workaround so it always visible
		//updateZIndexes();
		setZIndexToMax(_menu);
		setZIndexToMax(_header);
		
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
		_header.data = HEADER_DETAIL_TITLE;
		// display header back button
		_header.displayBackButton = true;
		
		// update header zIndex using a workaround
		//updateZIndexes();
		setZIndexToMax(_header);
		
		// hide loader
		_detailView.displayLoading = false;
	}
	
	/**
	 * set displayLoading to true on the current view
	 */
	public function onStartLoading():Void
	{
		//_currentView.displayLoading = true;
	}
	
	/**
	 * Display the error view
	 */
	public function onLoadingError(error:Dynamic):Void
	{
		trace("Load error: " + Std.string(error));
	}
	
	/**
	 * Call goBackToListView on the application controller.
	 */
	public function onHeaderBackButtonPressed():Void
	{
		//_applicationController.goBackToListView();

		// update header title
		_header.data = HEADER_HOME_TITLE;
		// hide header back button
		_header.displayBackButton = false;
		
		// remove detail view and add swippableListView
		_body.removeChild(_detailView);
		_body.addChild(_menu);
		_body.addChild(_swippableListView);
		_swippableListView.scrollToCurrentList();
		
		// update zIndex using a workaround
		//updateZIndexes();
		setZIndexToMax(_menu);
		setZIndexToMax(_header);

		// set current view on swippable view
		_currentView = _swippableListView;
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
	private function setZIndexToMax(dom:DOMElement):Void
	{
		// remove and add dom so it has the higher zIndex
		_body.removeChild(dom);
		_body.addChild(dom);
	}
	
}
