<<<<<<< HEAD
package org.intermedia.view;

import js.Lib;
import js.Dom;

/**
 * Display application title and a back button when in detail view to go back to list view.
 * 
 * @author Raphael Harmel
 */

class HeaderView extends ViewBase
//class HeaderView
{

	//public var dom:HtmlDom;
	
	// Called when the back button is clicked
	public var onBackButtonClick:Void->Void;
	
	// set / get displaying the back button
	private var _displayBackButton:Bool;
	public var displayBackButton(getDisplayBackButton, setDisplayBackButton):Bool;
	
	// text container, to be built in the constructor
	//private var _titleContainer:HtmlDom;
	private var _titleContainer:HtmlDom;
	
	//private var _titleTextElement:HtmlDom;
	private var _titleTextElement:HtmlDom;
	
	//private var _titleTextElement:HtmlDom;
	private var _image:Image;
	
	// back button container, to be built in the constructor, and attached/detached depending on displayBackButton value
	//private var _backButtonContainer:HtmlDom;
	private var _backButtonContainer:HtmlDom;

	public function new()
	{
		super();
		
		// init attributes
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
		
		// if back button has to be displayed, remove thumb image, and attach backbutton to this
		if (_displayBackButton)
		{
			node.removeChild(_image);
			//node.appendChild(_backButtonContainer);
			node.appendChild(_backButtonContainer);
		}
		// if it has to be hidden, first check if back button is already attached to this, and then remove it and then add thumb
		else
		{
			if(_backButtonContainer.parentNode != null)
			{
				//this.removeChild(_backButtonContainer);
				node.removeChild(_backButtonContainer);
				node.appendChild(_image);
			}
		}
		return _displayBackButton;
	}
	
	/**
	 * build header view, with tile and title
	 */
	override private function buildView():Void
	{
		// set header style
		HeaderStyle.setHeaderStyle(node);
		
		// build thumbnail and attach it
		_image = cast Lib.document.createElement("img");
		HeaderStyle.setThumbImageStyle(_image);
		_image.src = Constants.HEADER_IMAGE_URL;
		node.appendChild(_image);
		
		// build title and attach it
		_titleTextElement = Lib.document.createTextNode(_data);
		//_titleTextElement = Lib.document.createTextNode("Yo");
		_titleContainer = Lib.document.createElement("div");
		_titleContainer.appendChild(_titleTextElement);
		HeaderStyle.setHeaderTextStyle(_titleContainer);
		node.appendChild(_titleContainer);
	}
	
	/**
	 * update view
	 * overrides parent's class method
	 */
	override private function updateView():Void
	{
		_titleContainer.removeChild(_titleTextElement);
		_titleTextElement = Lib.document.createTextNode(_data);
		_titleContainer.appendChild(_titleTextElement);
	}

	/**
	 * build back button view
	 * @return
	 */
	private function buildBackButtonView():HtmlDom
	{
		// Back button
		var backButtonContainer:HtmlDom = Lib.document.createElement("div");
		HeaderStyle.setBackButtonStyle(backButtonContainer);
		
		// arrow images
		var backButtonArrowLeft:Image = cast Lib.document.createElement("img");
		HeaderStyle.setBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.src = 'assets/blackButtonLeft.png';
		backButtonContainer.appendChild(backButtonArrowLeft);
		var backButtonArrowRight:Image = cast Lib.document.createElement("img");
		HeaderStyle.setBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.src = 'assets/blackButtonRight.png';
		backButtonContainer.appendChild(backButtonArrowRight);
		
		// text
		var backButtonTextContainer:HtmlDom = Lib.document.createElement("div");
		HeaderStyle.setBackButtonTextStyle(backButtonTextContainer);
		var backButtonText:HtmlDom = Lib.document.createTextNode('Back');
		backButtonTextContainer.appendChild(backButtonText);
		backButtonContainer.appendChild(backButtonTextContainer);
		
		// set callback
		//backButtonContainer.onMouseUp = function (mouseEvent:MouseEventData) { onBackButtonClickCallback(); };
		backButtonContainer.onmouseup = function (event:Event) { onBackButtonClickCallback(); };
		
		return backButtonContainer;
	}
	
	/**
	 * on back button click callback
	 */
	private function onBackButtonClickCallback():Void
	{
		if (onBackButtonClick != null)
		{
			onBackButtonClick();
		}
	}
	
}
=======
package org.intermedia.view;

import js.Lib;
import js.Dom;

/**
 * Display application title and a back button when in detail view to go back to list view.
 * 
 * @author Raphael Harmel
 */

class HeaderView extends ViewBase
{

	// Called when the back button is clicked
	public var onBackButtonClick:Void->Void;
	
	// set / get displaying the back button
	private var _displayBackButton:Bool;
	public var displayBackButton(getDisplayBackButton, setDisplayBackButton):Bool;
	
	// text container, to be built in the constructor
	private var _titleContainer:HtmlDom;
	
	//private var _titleTextElement:HtmlDom;
	private var _titleTextElement:HtmlDom;
	
	//private var _titleTextElement:HtmlDom;
	private var _image:Image;
	
	// back button container, to be built in the constructor, and attached/detached depending on displayBackButton value
	private var _backButtonContainer:HtmlDom;

	public function new()
	{
		super();
		
		// init attributes
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
		
		// if back button has to be displayed, remove thumb image, and attach backbutton to this
		if (_displayBackButton)
		{
			//node.removeChild(_image);
			node.appendChild(_backButtonContainer);
		}
		// if it has to be hidden, first check if back button is already attached to this, and then remove it and then add thumb
		else
		{
			if(_backButtonContainer.parentNode != null)
			{
				node.removeChild(_backButtonContainer);
				//node.appendChild(_image);
			}
		}
		return _displayBackButton;
	}
	
	/**
	 * build header view, with tile and title
	 */
	override private function buildView():Void
	{
		// set header style
		HeaderStyle.setHeaderStyle(node);
		
		// build thumbnail and attach it
		/*_image = cast Lib.document.createElement("img");
		HeaderStyle.setThumbImageStyle(_image);
		_image.src = Constants.HEADER_IMAGE_URL;
		node.appendChild(_image);*/
		
		// build title and attach it
		_titleTextElement = Lib.document.createTextNode(_data);
		_titleContainer = Lib.document.createElement("div");
		_titleContainer.appendChild(_titleTextElement);
		HeaderStyle.setHeaderTextStyle(_titleContainer);
		node.appendChild(_titleContainer);
	}
	
	/**
	 * update view
	 * overrides parent's class method
	 */
	override private function updateView():Void
	{
		_titleContainer.removeChild(_titleTextElement);
		_titleTextElement = Lib.document.createTextNode(_data);
		_titleContainer.appendChild(_titleTextElement);
	}

	/**
	 * build back button view
	 * @return
	 */
	private function buildBackButtonView():HtmlDom
	{
		// Back button
		var backButtonContainer:HtmlDom = Lib.document.createElement("div");
		HeaderStyle.setBackButtonStyle(backButtonContainer);
		
		// arrow images
		var backButtonArrowLeft:Image = cast Lib.document.createElement("img");
		HeaderStyle.setBackButtonImageStyle(backButtonArrowLeft);
		backButtonArrowLeft.src = 'assets/blackButtonLeft.png';
		backButtonContainer.appendChild(backButtonArrowLeft);
		var backButtonArrowRight:Image = cast Lib.document.createElement("img");
		HeaderStyle.setBackButtonImageStyle(backButtonArrowRight);
		backButtonArrowRight.src = 'assets/blackButtonRight.png';
		backButtonContainer.appendChild(backButtonArrowRight);
		
		// text
		var backButtonTextContainer:HtmlDom = Lib.document.createElement("div");
		HeaderStyle.setBackButtonTextStyle(backButtonTextContainer);
		var backButtonText:HtmlDom = Lib.document.createTextNode('Back');
		backButtonTextContainer.appendChild(backButtonText);
		backButtonContainer.appendChild(backButtonTextContainer);
		
		// set callback
		backButtonContainer.onmouseup = function (event:Event) { onBackButtonClickCallback(); };
		
		return backButtonContainer;
	}
	
	/**
	 * on back button click callback
	 */
	private function onBackButtonClickCallback():Void
	{
		if (onBackButtonClick != null)
		{
			onBackButtonClick();
		}
	}
	
}
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
