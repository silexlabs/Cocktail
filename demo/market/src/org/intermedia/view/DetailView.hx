package org.intermedia.view;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;

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
	private var _titleContainer:ContainerDOMElement;
	
	// title text Element
	private var _titleElement:TextElement;
	
	// author container
	private var _authorContainer:ContainerDOMElement;
	
	// title text Element
	private var _authorElement:TextElement;
	
	// thumbnail image
	private var _thumbnail:ImageDOMElement;
	
	// description container
	private var _descriptionContainer:ContainerDOMElement;
	
	// description text Element
	private var _descriptionElement:TextElement;
	
	// content container
	private var _contentContainer:ContainerDOMElement;
	
	// content text Element
	private var _contentElement:TextElement;
	
	public function new() 
	{
		_titleElement = new TextElement("");
		_authorElement = new TextElement("");
		_descriptionElement = new TextElement("");
		_contentElement = new TextElement("");
		
		super();
	}
	
	/**
	 * build view
	 * overrides parent's class
	 */
	override private function buildView():Void
	{
		DetailStyle.setDefault(this);

		// add title
		_titleContainer = new ContainerDOMElement();
		DetailStyle.setTitle(_titleContainer);
		_titleContainer.addText(_titleElement);
		this.addChild(_titleContainer);
		
		// add author
		_authorContainer = new ContainerDOMElement();
		DetailStyle.setAuthor(_authorContainer);
		_authorContainer.addText(_authorElement);
		this.addChild(_authorContainer);
		
		// add thumbnail
		_thumbnail = new ImageDOMElement();
		DetailStyle.setThumbnail(_thumbnail);
		this.addChild(_thumbnail);
		
		// add description
		_descriptionContainer = new ContainerDOMElement();
		DetailStyle.setDescription(_descriptionContainer);
		_descriptionContainer.addText(_descriptionElement);
		this.addChild(_descriptionContainer);
		
		// add content
		_contentContainer = new ContainerDOMElement();
		DetailStyle.setDescription(_contentContainer);
		_contentContainer.addText(_contentElement);
		this.addChild(_contentContainer);
		
	}
	
	/**
	 * update view
	 * overrides parent's class
	 */
	override private function updateView():Void
	{
		// update title
		_titleContainer.removeText(_titleElement);
		_titleElement.text = _data.title;
		_titleContainer.addText(_titleElement);
		
		// update author
		_authorContainer.removeText(_authorElement);
		_authorElement.text = _data.author;
		_authorContainer.addText(_authorElement);
		
		// detach thumbnail from detail view
		if (_thumbnail.parent != null)
		{
			this.removeChild(_thumbnail);
		}
		// update thumbnail if data exists. check is done here to avoid having a "?" if not thumb is existing
		if(_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			_thumbnail.load(_data.thumbUrl);
			this.addChild(_thumbnail);
		}
			//_thumbnail.load(_data.thumbUrl);
		
		// update description
		/*_descriptionContainer.removeText(_descriptionElement);
		_descriptionElement.text = _data.description + "\n";
		_descriptionContainer.addText(_descriptionElement);
		
		// update content
		_contentContainer.removeText(_contentElement);
		_contentElement.text = _data.content;
		_contentContainer.addText(_contentElement);*/
		
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
			this.nativeElement.appendChild(htmlPageData.htmlDom);
		}catch(msg : String){
			//trace("Error, parsing XML tag "+xml.firstElement()+"\n"+msg);
			trace("Error, parsing XML tag \n"+msg);
		} catch( unknown : Dynamic ) {
			//trace("Error, parsing XML tag "+xml.firstElement()+"\n"+Std.string(unknown));
			trace("Error, parsing XML tag \n"+Std.string(unknown));
		}
	}
	
}