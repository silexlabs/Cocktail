package org.intermedia.view;
import cocktail.domElement.ContainerDOMElement;
import cocktail.textElement.TextElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktail.domElement.ImageDOMElement;
import org.intermedia.view.HeaderStyle;
import cocktail.mouse.MouseData;

/**
 * Display application title and a back button when in detail view to go back to list view.
 * 
 * @author Raphael Harmel
 */

class HeaderView extends ViewBase
{

	// Called when the back button is clicked
	//public var onBackButtonClick:MouseEventData->Void;
	public var onBackButtonClick:Void->Void;
	
	// set / get displaying the back button
	private var _displayBackButton:Bool;
	public var displayBackButton(getDisplayBackButton, setDisplayBackButton):Bool;
	
	// set/get the header title
	/*private var _title:String;
	public var title(getTitle, setTitle):String;*/
	
	// text container, to be built in the constructor
	private var _titleContainer:ContainerDOMElement;
	
	private var _titleTextElement:TextElement;
	
	// back button container, to be built in the constructor, and attached/detached depending on displayBackButton value
	private var _backButtonContainer:ContainerDOMElement;

	public function new()
	{
		super();

		// init attributes
		//_titleContainer = buildTitleView();
		//buildView();
		_data = "";
		_backButtonContainer = buildBackButtonView();
	}
	
	/**
	 * back button getter
	 * @return
	 */
	private function getDisplayBackButton():Bool
	{
		return _displayBackButton;
	}
	
	/**
	 * back button setter
	 * @param	v
	 * @return
	 */
	private function setDisplayBackButton(v:Bool):Bool
	{
		_displayBackButton = v;
		
		// if back button has to be displayed, attach it to this
		if (_displayBackButton)
		{
			this.addChild(_backButtonContainer);
		}
		// if it has to be hidden, first check if back button is already attached to this, and then remove it
		else
		{
			if(_backButtonContainer.parent != null)
			{
				this.removeChild(_backButtonContainer);
			}
		}
		return _displayBackButton;
	}
	
	/**
	 * title getter
	 * @return
	 */
	/*private function getTitle():String
	{
		return _title;
	}
	
	/**
	 * title setter
	 * @param	v
	 * @return
	 */
	/*private function setTitle(v:String):String
	{
		_title = v;
		//buildView();
		return _title;
	}*/
	
	/**
	 * build header view, with tile and title
	 */
	override private function buildView():Void
	{
		// set header style
		HeaderStyle.setHeaderStyle(this);
		
		// build tile
		/*var tile:ImageDOMElement = new ImageDOMElement();
		tile.load("assets/header.jpg");
		HeaderStyle.setHeaderTileStyle(tile);
		this.addChild(tile);*/
		
		// build title
		//var textElement:TextElement = new TextElement(_title);
		//var textElement:TextElement = new TextElement(_data);
		_titleTextElement = new TextElement(_data);
		//var textContainer:ContainerDOMElement = new ContainerDOMElement();
		_titleContainer = new ContainerDOMElement();
		//textContainer.addText(textElement);
		_titleContainer.addText(_titleTextElement);
		HeaderStyle.setHeaderTextStyle(_titleContainer);
		this.addChild(_titleContainer);
	}
	
	/**
	 * update view
	 * overrides parent's class method
	 */
	override private function updateView():Void
	{
		//trace(_data);
		_titleContainer.removeText(_titleTextElement);
		_titleTextElement = new TextElement(_data);
		_titleContainer.addText(_titleTextElement);
	}

	private function buildBackButtonView():ContainerDOMElement
	{
		// Back button
		var backButtonContainer:ContainerDOMElement = new ContainerDOMElement();
		HeaderStyle.setBackButtonStyle(backButtonContainer);
		
		// arrow images
		var backButtonArrowLeft:ImageDOMElement = new ImageDOMElement();
		HeaderStyle.setBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.load('assets/blackButtonLeft.png');
		backButtonContainer.addChild(backButtonArrowLeft);
		var backButtonArrowRight:ImageDOMElement = new ImageDOMElement();
		HeaderStyle.setBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.load('assets/blackButtonRight.png');
		backButtonContainer.addChild(backButtonArrowRight);
		
		// text
		var backButtonTextContainer:ContainerDOMElement = new ContainerDOMElement();
		HeaderStyle.setBackButtonTextStyle(backButtonTextContainer);
		var backButtonText:TextElement = new TextElement('Back');
		backButtonTextContainer.addText(backButtonText);
		backButtonContainer.addChild(backButtonTextContainer);
		
		// set callback
		backButtonContainer.onMouseUp = function (mouseEvent:MouseEventData) { onBackButtonClickCallback(); };
		//backButtonContainer.onMouseUp = onBackButtonClickCallback;
		
		return backButtonContainer;
	}
	
	//private function onBackButtonClickCallback(mouseEvent:MouseEventData):Void
	private function onBackButtonClickCallback():Void
	{
		if (onBackButtonClick != null)
		{
			//onBackButtonClick(mouseEvent);
			onBackButtonClick();
		}
	}
	
}
