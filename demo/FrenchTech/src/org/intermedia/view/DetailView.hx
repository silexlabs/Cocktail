/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Scroll2D;
import haxe.Firebug;

/**
 * Display the detail of an RSS feed entry (title, picture, content...)
 * 
 * @author Raphael Harmel
 */

class DetailView extends ViewBase
{
	// title container
	private var _titleContainer:HtmlDom;
	
	// title text Element
	private var _titleElement:HtmlDom;
	
	// author container
	private var _authorContainer:HtmlDom;
	
	// title text Element
	private var _authorElement:HtmlDom;
	
	// thumbnail image
	private var _thumbnail:Image;
	
	// description container
	private var _descriptionContainer:HtmlDom;
	
	// description text Element
	private var _descriptionElement:HtmlDom;
	
	// content container
	private var _contentContainer:HtmlDom;
	
	// content text Element
	private var _contentElement:HtmlDom;
	
	// touch & mouse handler
	private var _scrollHandler:Scroll2D;
	
	// initial scroll position
	//private var _initialScrollPosition:Coordinate;

	public function new() 
	{
		_titleElement = Lib.document.createTextNode("");
		_authorElement = Lib.document.createTextNode("");
		_descriptionElement = Lib.document.createTextNode("");
		_contentElement = Lib.document.createTextNode("");
		
		super();
		
		//_initialScrollPosition = { x:0, y:0 };
		
		// initialise move handler
		//_scrollHandler = new Scroll2D(ScrollType.vertical);
		//_scrollHandler.onVerticalScroll = onVerticalScroll;

		// js touch events handling
		//addTouchEvents();	
	}
	
	/**
	 * build view
	 * overrides parent's class
	 */
	override private function buildView():Void
	{
		DetailStyle.setDetailStyle(node);

		// add title
		_titleContainer = Lib.document.createElement("div");
		DetailStyle.setTitle(_titleContainer);
		_titleContainer.appendChild(_titleElement);
		node.appendChild(_titleContainer);
		
		// add author
		_authorContainer = Lib.document.createElement("div");
		DetailStyle.setAuthor(_authorContainer);
		_authorContainer.appendChild(_authorElement);
		node.appendChild(_authorContainer);
		
		// add thumbnail
		//_thumbnail = cast Lib.document.createElement("img");
		//DetailStyle.setThumbnail(_thumbnail);
		//node.appendChild(_thumbnail);
		
		// add description
		//_descriptionContainer = Lib.document.createElement("div");
		//DetailStyle.setDescription(_descriptionContainer);
		//_descriptionContainer.appendChild(_descriptionElement);
		//node.appendChild(_descriptionContainer);
		
		// add content
		_contentContainer = Lib.document.createElement("div");
		DetailStyle.setDescription(_contentContainer);
		//_contentContainer.appendChild(_contentElement);
		node.appendChild(_contentContainer);
		
	}
	
	/**
	 * update view
	 * overrides parent's class
	 */
	override private function updateView():Void
	{
		// update title
		_titleContainer.removeChild(_titleElement);
		//_titleElement.text = _data.title;
		_titleElement = Lib.document.createTextNode(_data.title);
		_titleContainer.appendChild(_titleElement);
		
		// update author
		_authorContainer.removeChild(_authorElement);
		//_authorElement.text = _data.author;
		_authorElement = Lib.document.createTextNode(_data.author);
		_authorContainer.appendChild(_authorElement);
		
		// detach thumbnail from detail view
		/*if (_thumbnail.parentNode != null)
		{
			node.removeChild(_thumbnail);
		}
		// update thumbnail if data exists. check is done here to avoid having a "?" if not thumb is existing
		if(_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			_thumbnail.src = _data.thumbUrl;
			node.appendChild(_thumbnail);
		}*/
			//_thumbnail.src(_data.thumbUrl);
		
		// update description
		/*_descriptionContainer.removeChild(_descriptionElement);
		_descriptionElement.text = _data.description + "\n";
		_descriptionContainer.appendChild(_descriptionElement);*/
		
		// update content
		// remove node
		node.removeChild(_contentContainer);
		_contentContainer.innerHTML = _data.description;
		// resize children iframe & img
		resizeNodeChildrenTag(_contentContainer,"iframe");
		resizeNodeChildrenTag(_contentContainer, "img");
		// attach node
		node.appendChild(_contentContainer);
		
		// update content
		// remove node
		/*node.removeChild(_contentContainer);
		_contentContainer.innerHTML = _data.content;
		// resize children iframe & img
		resizeNodeChildrenTag(_contentContainer,"iframe");
		resizeNodeChildrenTag(_contentContainer, "img");
		// attach node
		node.appendChild(_contentContainer);*/
		
	}


	/**
	 * Touch start event handler
	 * 
	 * @param	event
	 */
	private function touchStart(event:Dynamic):Void
	{
		_scrollHandler.initialScrollPosition = { x:node.scrollLeft, y:node.scrollTop };
		_scrollHandler.touchHandler(event);
	}

	/**
	 * Adds touch events
	 */
	/*public function addTouchEvents():Void
	{
		#if js
		untyped
		{
			node.addEventListener("touchstart", touchStart, false);
			node.addEventListener("touchmove", _scrollHandler.touchHandler, false);
			node.addEventListener("touchend", _scrollHandler.touchHandler, false);
			node.addEventListener("touchcancel", _scrollHandler.touchHandler, false);
		}
		#end
	}
	

	/**
	 * Removes touch events
	 */
	/*public function unsetTouchEvents():Void
	{
		#if js
		untyped
		{
			node.removeEventListener("touchstart", touchStart, false);
			node.removeEventListener("touchmove", _scrollHandler.touchHandler, false);
			node.removeEventListener("touchend", _scrollHandler.touchHandler, false);
			node.removeEventListener("touchcancel", _scrollHandler.touchHandler, false);
		}
		#end
	}
	
	/**
	 * move view on the vertical axis
	 * 
	 * @param	e
	 */
    /*private function onVerticalScroll( y : Int )
    {
		node.scrollTop = _scrollHandler.initialScrollPosition.y - y;
    }
	
	/**
	 * Refresh styles
	 */
	public function refreshStyles():Void
	{
		// reset style
		DetailStyle.setDetailStyle(node);
		// resize children iframe & img
		resizeNodeChildrenTag(_contentContainer,"iframe");
		resizeNodeChildrenTag(_contentContainer,"img");
	}
	
	/**
	 * Resizes the node's selected children tag
	 * Used for better user experience.
	 * Resolves also a bug of Android browser where window.screen.width & window.innerWidth take the width of the the most large iframe in the DOM
	 * => to resolve this issue, get all iframes and resize them to match the window.innerWidth
	 * => already tried using maxWidth & maxHeight, but creates bugs on Alex' Android Phone
	 * 
	 * @param	node
	 */
	private function resizeNodeChildrenTag(nodeToResize:HtmlDom, tagName:String):Void
	{
		var tagNodes:HtmlCollection<HtmlDom> = nodeToResize.getElementsByTagName(tagName);
		
		// for all nodes with the given tag name
		for (i in 0...tagNodes.length)
		{
			resizeNode(tagNodes[i]);
		}
	}

	/**
	 * Resizes the node
	 * Used for better user experience.
	 * Resolves also a bug of Android browser where window.screen.width & window.innerWidth take the width of the the most large iframe in the DOM
	 * => to resolve this issue, get all iframes and resize them to match the window.innerWidth
	 * => already tried using maxWidth & maxHeight, but creates bugs on Alex' Android Phone
	 * 
	 * @param	node
	 */
	private function resizeNode(nodeToResize:HtmlDom):Void
	{
		var originalWidth:Int = Std.parseInt(nodeToResize.getAttribute("width"));
		var originalHeight:Int = Std.parseInt(nodeToResize.getAttribute("height"));
		
		// set width & heigth
		if ( Std.parseInt(nodeToResize.getAttribute("width")) > Lib.window.innerWidth )
		{
			var newWidth:Int = Std.int(Constants.DETAIL_HORIZONTAL_PERCENT * Lib.window.innerWidth / 100);
			nodeToResize.style.width = Std.string(Constants.DETAIL_HORIZONTAL_PERCENT) + "%";
			
			// compute & set height
			var newHeight:Int = Std.int(originalHeight * newWidth / originalWidth);
			nodeToResize.style.height = Std.string(newHeight) + "px";
		}
		else
		{
			nodeToResize.style.width = Std.parseInt(nodeToResize.getAttribute("width")) + "px";
			nodeToResize.style.height = Std.parseInt(nodeToResize.getAttribute("height")) + "px";
		}
	
		// remove width & height attributes to avoid browsers incorrect behaviours
		//untyped { tagNodes[i].removeAttribute("width"); };
		//untyped { tagNodes[i].removeAttribute("height"); };
		
	}

}