package org.intermedia.view;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;

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
	
	public function new() 
	{
		_titleElement = new TextElement("");
		_authorElement = new TextElement("");
		_descriptionElement = new TextElement("");
		
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
		
		// update thumbnail
		_thumbnail.load(_data.thumbUrl);
		
		// update description
		_descriptionContainer.removeText(_descriptionElement);
		_descriptionElement.text = _data.description;
		_descriptionContainer.addText(_descriptionElement);
		
	}
	
}