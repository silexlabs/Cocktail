package org.intermedia.view;

//import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.nativeElement.NativeElement;
import org.intermedia.controller.ApplicationController;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.SwippableListView;

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
	
	//Ref to the container managing the swippable list view
	private var _swippableListView:SwippableListView;
	
	//Ref to the view displaying full article
	private var _detailView:DetailView;
	
	//Ref to the view displayed when there is a loading error
	//private var _errorView:ErrorView;
	//private var _errorView:ContainerDOMElement;
	
	//listen to model change on it
	private var _applicationModel:ApplicationModel;
	
	//proxies interaction with the model
	private var _applicationController:ApplicationController;
	
	//A ref to the currently displayed main view (not the header)
	private var _currentView:ViewBase;
	
	static inline var CELL_QTY:Int = 5;

	/**
	 * Store ref to application model and controller. Instantiate headerView, loadingView, swippableView then call init().
	 * 
	 * @param	applicationModel
	 * @param	applicationController
	 */
	public function new(applicationModel:ApplicationModel, applicationController:ApplicationController)
	{
		// Store ref to application model and controller.
		_applicationModel = applicationModel;
		_applicationController = applicationController;
		
		// Instantiate body headerView, loadingView, swippableView
		_body = new BodyDOMElement();
		ViewManagerStyle.setBodyStyle(_body);
		_header = new HeaderView();
		_header.data = HEADER_HOME_TITLE;
		_header.onBackButtonClick = onHeaderBackButtonPressed;
		_body.addChild(_header);
		
		_swippableListView = new SwippableListView();
		_body.addChild(_swippableListView);
		_detailView = new DetailView();
		_currentView = new ViewBase();
		
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
		
		// set detail callback
		_swippableListView.onListItemSelected = _applicationController.openDetailView;
		
		// Call loadCellData() on the application controller with thedefault cell number (between 5 to 10)
		_applicationController.loadCellData(CELL_QTY);
	}
	
	/**
	 * Open the listView and / or refresh its data.
	 * 
	 * @param	cellsData
	 */
	public function onCellDataLoaded(cellsData:Array<CellData>):Void
	{
		_swippableListView.data = cellsData;
		
		// update zIndex using a workaround
		updateHeaderZIndex();
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
		//_header.data = detailData.title;
		_header.data = HEADER_DETAIL_TITLE;
		// display header back button
		_header.displayBackButton = true;
		
		// remove swippableListView and add detail view
		_body.removeChild(_swippableListView);
		_body.addChild(_detailView);
		
		// update zIndex using a workaround
		updateHeaderZIndex();
	}
	
	/**
	 * set displayLoading to true on the current view
	 */
	public function onStartLoading():Void
	{
		_currentView.displayLoading = true;
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
		_body.addChild(_swippableListView);
		
		// update zIndex using a workaround
		updateHeaderZIndex();
	}
	
	/**
	 * updates header zIndex.
	 * Uses a workaround as zIndex is not implemented yet in Cocktail
	 */
	private function updateHeaderZIndex():Void
	{
		// remove and add header so it has the higher zIndex
		_body.removeChild(_header);
		_body.addChild(_header);
	}
	
}
