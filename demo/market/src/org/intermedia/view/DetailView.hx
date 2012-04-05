package org.intermedia.view;

import js.Lib;
import js.Dom;
import haxe.Firebug;

// hxtml
import hxtml2.HTMLPageData;
import hxtml2.HTMLParser;

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
	
	public function new() 
	{
		_titleElement = Lib.document.createTextNode("");
		_authorElement = Lib.document.createTextNode("");
		_descriptionElement = Lib.document.createTextNode("");
		_contentElement = Lib.document.createTextNode("");
		
		super();
	}
	
	/**
	 * build view
	 * overrides parent's class
	 */
	override private function buildView():Void
	{
		DetailStyle.setDefault(node);

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
		_thumbnail = cast Lib.document.createElement("img");
		DetailStyle.setThumbnail(_thumbnail);
		node.appendChild(_thumbnail);
		
		// add description
		_descriptionContainer = Lib.document.createElement("div");
		DetailStyle.setDescription(_descriptionContainer);
		_descriptionContainer.appendChild(_descriptionElement);
		node.appendChild(_descriptionContainer);
		
		// add content
		_contentContainer = Lib.document.createElement("div");
		DetailStyle.setDescription(_contentContainer);
		_contentContainer.appendChild(_contentElement);
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
		if (_thumbnail.parentNode != null)
		{
			node.removeChild(_thumbnail);
		}
		// update thumbnail if data exists. check is done here to avoid having a "?" if not thumb is existing
		if(_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			_thumbnail.src = _data.thumbUrl;
			node.appendChild(_thumbnail);
		}
			//_thumbnail.src(_data.thumbUrl);
		
		// update description
		/*_descriptionContainer.removeChild(_descriptionElement);
		_descriptionElement.text = _data.description + "\n";
		_descriptionContainer.appendChild(_descriptionElement);
		
		// update content
		_contentContainer.removeChild(_contentElement);
		_contentElement.text = _data.content;
		_contentContainer.appendChild(_contentElement);*/
		
		//html2DOM(_data.description);
		html2DOM(_data.content);
	}
	
	private function html2DOM(htmlString:String):Void
	{
		try
		{
			var xml:Xml = Xml.parse(htmlString);
			var htmlPageData:HTMLPageData = null;
			htmlPageData = (new HTMLParser()).parse(xml.firstElement());
			// add the parsed data to the detail view
			node.appendChild(htmlPageData.htmlDom);
		}catch(msg : String){
			//trace("Error, parsing XML tag "+xml.firstElement()+"\n"+msg);
			Firebug.trace("Error, parsing XML tag \n"+msg);
		} catch( unknown : Dynamic ) {
			//trace("Error, parsing XML tag "+xml.firstElement()+"\n"+Std.string(unknown));
			Firebug.trace("Error, parsing XML tag \n"+Std.string(unknown));
		}
	}
	
}