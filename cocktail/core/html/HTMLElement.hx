/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.css.CascadeManager;
import cocktail.css.CSSStyleDeclaration;
import cocktail.css.InitialStyleDeclaration;
import cocktail.css.parsers.CSSSelectorParser;
import cocktail.css.CSSSelectorData;
import cocktail.core.dom.Document;
import cocktail.core.css.CSSCascadeData;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.DOMException;
import cocktail.core.dom.Element;
import cocktail.core.dom.Node;
import cocktail.core.dom.NodeList;
import cocktail.event.EventConstants;
import cocktail.event.EventTarget;
import cocktail.event.FocusEvent;
import cocktail.event.UIEvent;
import cocktail.event.WheelEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.parser.DOMParser;
import cocktail.timer.Timer;

import haxe.xml.Parser;
import cocktail.event.Event;
import cocktail.event.KeyboardEvent;
import cocktail.event.MouseEvent;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.css.CoreStyle;
import haxe.Log;
import cocktail.core.focus.FocusManager;
import cocktail.core.layout.LayoutData;
import cocktail.core.parser.ParserData;
import cocktail.core.font.FontData;

/**
 * All HTML element interfaces derive from this class.
 * Elements that only expose the HTML core attributes are represented 
 * by the base HTMLElement interface.
 * 
 * TODO 3 : eventually, style and rendering tree functionnality should
 * be moved to Element class so that css can be reused for any XML
 * document
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLElement extends Element
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The tab index order of the HTMLElement. If the index
	 * is set, it is used to determine focus order when the
	 * user press the TAB key. If it is not set or set to 0, the document
	 * order is used to establish focus order and the HTMLElement
	 * is only focused if it is intrinsically focusable, like for
	 * instance an HTMLInputElement
	 */
	public var tabIndex(get_tabIndex, set_tabIndex):Int;
	
	/**
	 * This attribute assigns an id to an element. 
	 * This id must be unique in a document.
	 * 
	 * get/set the id attribute from the attributes
	 * map
	 */
	public var id(get_id, set_id):String;
	
	/**
	 * get/set a class on the HTMLElement.
	 * An array of class can be given by separating each
	 * class name by a space
	 * 
	 * className is used instead of class for conflict with
	 * language reserved word
	 */
	public var className(get_className, set_className):String;
	
	/**
	 * Return the space separated classes
	 * of the node as an array
	 */
	public var classList(default, null):Array<String>;
	
	/**
	 * When specified on an element, it indicates that the element 
	 * is not yet, or is no longer, directly relevant to the page's
	 * current state, or that it is being used to
	 * declare content to be reused by other parts of the page 
	 * as opposed to being directly accessed by the user.
	 * HTMLElement with hiden attribute set are not rendered.
	 */
	public var hidden(get_hidden, set_hidden):Bool;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Gets/sets the top scroll offset of an element
	 */
	public var scrollTop(get_scrollTop, set_scrollTop):Int;
	
	/**
	 * Gets/sets the left scroll offset of an element
	 */
	public var scrollLeft(get_scrollLeft, set_scrollLeft):Int;
	
	/**
	 * The scroll view height of the HTMLElement. Returns either
	 * the height of the HTMLElement or the height of its content,
	 * whichever is greater. For instance if the HTMLElement displays
	 * scrollbars because its content is higher than its content area,
	 * scrollHeight will be larger than clientHeight
	 */
	public var scrollHeight(get_scrollHeight, never):Int;
	
	/**
	 * Same as scrollHeight for width
	 */
	public var scrollWidth(get_scrollWidth, never):Int;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * sets or gets the inner HTML
	 * syntax describing the element's descendants.
	 */
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
	/**
	 * sets or gets the outer HTML
	 * syntax describing the element and its descendants.
	 */
	public var outerHTML(get_outerHTML, set_outerHTML):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Rendering attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This object is part of the rendering tree
	 * and is used to render this HTMLElement using
	 * its computed styles. It is only instantiated
	 * if the HTMLElement must be displayed.
	 */
	public var elementRenderer(default, null):ElementRenderer;
	
	/////////////////////////////////
	// COORDS attributes
	////////////////////////////////
	
	/**
	 * The element from which all offset calculations are currently computed,
	 * this is the first positioned ancestor of the HTMLElement
	 */
	public var offsetParent(get_offsetParent, never):HTMLElement;
	
	/**
	 * The width of an element, relative to the layout
	 */
	public var offsetWidth(get_offsetWidth, never):Int;
	
	/**
	 * The height of an element, relative to the layout
	 */
	public var offsetHeight(get_offsetHeight, never):Int;
	
	/**
	 * The distance from this element's left border to its 
	 * offsetParent's left border.
	 */
	public var offsetLeft(get_offsetLeft, never):Int;
	
	/**
	 * The distance from this element's top border to its
	 * offsetParent's top border.
	 */
	public var offsetTop(get_offsetTop, never):Int;
	
	/**
	 * The inner width of an element
	 */
	public var clientWidth(get_clientWidth, never):Int;
	
	/**
	 * The inner height of an element
	 */
	public var clientHeight(get_clientHeight, never):Int;
	
	/**
	 * The width of the left border of an element
	 */
	public var clientLeft(get_clientLeft, never):Int;
	
	/**
	 * The width of the top border of an element
	 */
	public var clientTop(get_clientTop, never):Int;
	
	/////////////////////////////////
	// STYLE attribute
	////////////////////////////////
	
	/**
	 * This object's purpose is to cascade the
	 * different styles applying to the HTMLElement which
	 * can come from either the inline style definition,
	 * the document's style sheet definition or be
	 * inherited from the parent node.
	 * 
	 * It exposes attribute allowing access to each
	 * of the style values applying to this HTMLElement
	 * after the cascade
	 */
	public var coreStyle(default, null):CoreStyle;
	
	/**
	 * This is the style object exposed by the public API.
	 * It is used to set and get CSS styles with strings, like
	 * when using JavaScript in the browser. 
	 * When a value is updated through it, this HTMLElement
	 * cascades and cascade its children to keep an up to date
	 * style definition
	 */
	public var style(default, null):CSSStyleDeclaration;
	
	/**
	 * This objects holds all the style declarations from the document's
	 * style sheets which applies to this HTMLElement. It it used during
	 * the cascade to determine for each style which value to use
	 */	
	public var styleManagerCSSDeclaration(default, null):CSSStyleDeclaration;
	
	/////////////////////////////////
	// attributes
	////////////////////////////////
	
	/**
	 * Wether the htmlElement is currently
	 * attached to the DOM, meaning that
	 * the document itself is its ancestor
	 */
	public var attachedToDOM(default, null):Bool;
	
	/**
	 * Wether the style of this HTMLElement need to be
	 * cascaded. Cascading determine for each supported
	 * style, which value to use
	 */
	private var _needsCascading:Bool;
	
	/**
	 * Wether the style declaration for this HTMLElement
	 * retrieved from the style manager needs to be updated
	 */
	private var _needsStyleDeclarationUpdate:Bool;
	
	/**
	 * Wheter the ElementRenderer for this HTMLElement
	 * should be re-instantiated and attached to the
	 * rendering tree. Happens for instance when a style
	 * affecting positioning shceme is changed, like
	 * "display"
	 */
	private var _needsElementRendererUpdate:Bool;
	
	/**
	 * Between 2 cascade, store the index of all the
	 * properties whose value changed and which need
	 * to be re-cascaded.
	 */
	private var _pendingChangedProperties:Array<Int>;
	
	/**
	 * A flag determining wether all the CSS styles
	 * of this HTMLElement needs to be cascaded.
	 * Happens for instance the first time this
	 * HTMLElement is added to the DOM
	 */
	private var _shouldCascadeAllProperties:Bool;
	
	/**
	 * A reference to the ownerDocument, typed as
	 * an HTMLDocument to easily access method
	 * specific to this sub-class
	 * 
	 * TODO 3 : eventually shoul become type
	 * parameter
	 */
	private var _ownerHTMLDocument:HTMLDocument;
	
	/**
	 * a reference to an object containing all
	 * the default CSS style defintions
	 */
	private var _initialStyleDeclaration:InitialStyleDeclaration;
	
	/**
	 * wether the init method was already called
	 */
	private var _isInitialised:Bool;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor. Html element is initialised
	 * once it is given a reference to a document
	 */
	public function new(tagName:String) 
	{
		super(tagName);
		
		attachedToDOM = false;
		_isInitialised = false;
		_needsCascading = false;
		_needsStyleDeclarationUpdate = false;
		_shouldCascadeAllProperties = true;
		_needsElementRendererUpdate = true;
		_pendingChangedProperties = new Array<Int>();
		
		_initialStyleDeclaration = InitialStyleDeclaration.getInstance();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_ownerHTMLDocument = null;
		ownerDocument = null;
		_initialStyleDeclaration = null;
		_pendingChangedProperties = null;
		coreStyle.dispose();
		coreStyle = null;
		style.dispose();
		style = null;
	}
	
	/**
	 * Init the HTMLElement attributes
	 */
	private function init():Void
	{	
		//init the core style for this HTMLElement
		initCoreStyle();
		
		//init the CSS inline style declaration
		initStyle();
	}
	
	/**
	 * Instantiate the core style object,
	 * sotring the style of this element
	 */
	private function initCoreStyle():Void
	{
		coreStyle = new CoreStyle(this);
	}
	
	/**
	 * Init the inline style declaration
	 */
	private function initStyle():Void
	{
		style = new CSSStyleDeclaration(null, onInlineStyleChange);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to initialise the html element once is document is
	 * set. The document is set immediately after the html element creation.
	 * Also store a casted ref to the html document
	 */
	override private function set_ownerDocument(value:Document):Document
	{
		super.set_ownerDocument(value);
		
		if (_isInitialised == false)
		{
			init();
			_isInitialised = true;
		}
		
		_ownerHTMLDocument = cast(value);
		
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a child is added to the DOM, an init
	 * method is called on it
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		if (newChild.nodeType == DOMConstants.ELEMENT_NODE)
		{
			var child:HTMLElement = cast(newChild);
			child.appended();
		}
        //if the new child is a text node, then this html element element renderer
        //will need to be updated to create text node renderers as well
        else if (newChild.nodeType == DOMConstants.TEXT_NODE)
        {
            invalidateElementRenderer();
        }
		
		//when a new child is added, refreh the style of this html element
		//TODO 2 : don't seem necessary, but tried to remove it and add
		//regression when testing an html doc with just a body, style
		//seemed not to be set on htmlhtmlelement
		invalidateCascade();
		return newChild;
	}
	
	/**
	 * When a child is removed, a method is
	 * called on it so that it
	 * can be cleaned-up
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		
		if(oldChild.nodeType == DOMConstants.ELEMENT_NODE)
		{
			var child:HTMLElement = cast(oldChild);
			child.removed();
		}
        //if a text node is removed, then this html element's element renderer
        //will need to be updated to also remove the text node renderer
        else if (oldChild.nodeType == DOMConstants.TEXT_NODE)
        {
            invalidateElementRenderer();
        }
		
		return oldChild;
	}
	
	/**
	 * When a child is added to the DOM, an init
	 * method is called on it
	 */
	override public function insertBefore(newChild:Node, refChild:Node):Node
	{
		super.insertBefore(newChild, refChild);
		
		//if refChild is null, this method
		//will use appendChild which takes care
		//of calling the init method
		if (refChild != null)
		{
			if(newChild.nodeType == DOMConstants.ELEMENT_NODE)
			{
				var child:HTMLElement = cast(newChild);
				child.appended();
				invalidateCascade();
			}
			
		}
	
		return newChild;
	}
	
	/**
	 * Overriden to make the tag name case-insensitive in an
	 * HTML document
	 */
	override public function getElementsByTagName(tagName:String):Array<HTMLElement>
	{
		return super.getElementsByTagName(tagName.toUpperCase());
	}
	
	/**
	 * Overriden to call specific setter merhod for some
	 * attributes
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		//attributes name are case-insensitive
		name = name.toLowerCase();
		
		//when the value of the "style" attribute changes, the whole
		//inline style declaration is refreshed
		if (name == HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME)
		{
			style.cssText = value;
			invalidateCascade();
		}
		//setting the class name must also update
		//the classList
		else if (name == HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME)
		{
			className = value;
		}
		else
		{
			super.setAttribute(name, value);
			invalidateStyleDeclaration(true);
		}
	}
	
	/**
	 * Overriden to run through the necessary check for 
	 * HTML attribute retrieval
	 */
	override public function getAttribute(name:String):String
	{
		//special case for the style attribute, as it has
		//its dedicated object
		//TODO 1 : a "style" attribute should always be specified, like for the id
		//attribute else, it won't be serialized when calling get_innerHTML, or add
		//it in the html serializer if not empty string ?
		if (name == HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME)
		{
			return style.cssText;
		}
		else
		{
			return super.getAttribute(name);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also add the html document and the window
	 * as targets ancestors for the bubbling and capture phase
	 * of the event
	 */
	override private function getTargetAncestors():Array<EventTarget>
	{
		var targetAncestors:Array<EventTarget> = super.getTargetAncestors();
		targetAncestors.push(_ownerHTMLDocument);
		if (_ownerHTMLDocument.defaultView != null)
		{
			targetAncestors.push(_ownerHTMLDocument.defaultView);
		}
		return targetAncestors;
	}
	
	/**
	 * Execute the default actions of the HTMLElement for a given event type,
	 * if the default was not prevented
	 */
	override private function executeDefaultActionIfNeeded(defaultPrevented:Bool, event:Event):Void
	{
		if (defaultPrevented == false)
		{
			switch (event.type)
			{
				//if the element is focusable, by default
				//on mouse down, it will gain focus
				case EventConstants.MOUSE_DOWN:
					focus();
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Resets the element, implementation vary
	 * based on wether the element is a form or
	 * a form element
	 * 
	 * note : implemented here as it is used
	 * by multiple form related element not sharing
	 * a base class or interface
	 */
	public function reset():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * generic invalidation method, invalidate
	 * all aspects of the element renderer
	 * if not null
	 */
	public function invalidate():Void
	{
		if (elementRenderer != null)
		{
			elementRenderer.invalidate();
		}
	}
	
	/**
	 * Called when the specified value of a style 
	 * changed, may invalidated the layout and/or
	 * rendering of the element renderer
	 */
	public function invalidateStyle(styleIndex:Int):Void
	{
		if (elementRenderer != null)
		{
			elementRenderer.invalidateStyle(styleIndex);
		}
	}
	
	/**
	 * Called when the element renderer of this HTMLElement
	 * has become invalid and needs to be re-created before
	 * next layout and rendering
	 */
	public function invalidateElementRenderer():Void
	{
		_needsElementRendererUpdate = true;
		if (_ownerHTMLDocument != null)
		{
			_ownerHTMLDocument.invalidationManager.invalidateRenderingTree();
		}
	}
	
	/**
	 * Called when the layer renderer of the element
	 * renderer becomes invalid and needs to be 
	 * re-created before next layout
	 */
	public function invalidateLayerRenderer():Void
	{
		if (elementRenderer != null)
		{
			elementRenderer.invalidateLayerRenderer();
		}
	}
	
	/**
	 * Invalidate the style declaration retrieved
	 * from the style manager. This declaration will
	 * be updated on next cascade
	 * 
	 * @param	recursive wether this invalidation should also
	 * apply to every children of this node recursively
	 */
	public function invalidateStyleDeclaration(recursive:Bool):Void
	{
		_needsStyleDeclarationUpdate = true;
		
		//apply to all child if recursive
		if (recursive == true)
		{
			if (nodeType == DOMConstants.ELEMENT_NODE)
			{
				var length:Int = childNodes.length;
				for (i in 0...length)
				{
					if (childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
					{
						var child:HTMLElement = cast(childNodes[i]);
						child.invalidateStyleDeclaration(true);
					}
				}
			}
		}
		invalidateCascade();
	}
	
	/**
	 * Invalidate cascading of the HTMLElement.
	 * The styles applying to it will be re-computed
	 * on next cascade
	 */
	public function invalidateCascade():Void
	{
		_needsCascading = true;
		
		if (_ownerHTMLDocument != null)
		{
			_ownerHTMLDocument.invalidationManager.invalidateCascade();

		}
	}
	
	/**
	 * invalidate the rendering of this HTMLElement, 
	 * so that it gets redrawn on next update
	 */
	private function invalidateRendering():Void
	{
		if (elementRenderer != null)
		{
			_ownerHTMLDocument.invalidationManager.invalidateRendering();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * update the document immediately instead of waiting
	 * for the next scheduled update. Needed by some public
	 * API, like for instance those returning the computed
	 * position of an element, those dimensions should be returned
	 * synchronously
	 */
	private function updateDocumentImmediately():Void
	{
		_ownerHTMLDocument.invalidationManager.updateDocumentImmediately();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC DOM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called by the parent HTMLElement
	 * when this HTMLElement is attached to it,
	 * check wether this HTMLElement is now
	 * attached to the DOM, meaning that
	 * the document itself is its ancesotr
	 */
	public function appended():Void
	{
		//do nothing if already attached to the DOM
		if (attachedToDOM == false)
		{
			if (isAttachedToDOM() == true)
			{
				attachedToDOM = true;
				addedToDOM();
				
				//all the child of this htmlelement are
				//now attached to the DOM as well
				var child:Node = firstChild;
				while (child != null)
				{
					if (child.nodeType == DOMConstants.ELEMENT_NODE)
					{
						var htmlChild:HTMLElement = cast(child);
						htmlChild.appended();
					}
					child = child.nextSibling;
				}
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE DOM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called by the parent HTMLElement
	 * when this HTMLElement is removed from it
	 */
	private function removed():Void
	{
		attachedToDOM = false;
		
		removedFromDOM();
		
		//all child are now detached from DOM
		//as well
		var child:Node = firstChild;
		while (child != null)
		{
			if (child.nodeType == DOMConstants.ELEMENT_NODE)
			{
				var htmlChild:HTMLElement = cast(child);
				htmlChild.removed();
			}
			child = child.nextSibling;
		}
	}
	
	/**
	 * Called when the htmlelement is attached
	 * to the DOM
	 */
	private function addedToDOM():Void
	{
		//schedule an update of the element renderer of this
		//HTMLElement
		//
		//only element and text node are visual and can be
		//attached to the rendering tree, no need to 
		//update the rendering tree for other types
		switch (nodeType)
		{
			case DOMConstants.ELEMENT_NODE, DOMConstants.TEXT_NODE:
				invalidateElementRenderer();
				
		}
		
		//when attached to a new parent, 
		//the styles definition must be updated
		//and cascaded
		invalidateStyleDeclaration(true);
		invalidateCascade();
	}
	
	/**
	 * Called when the htmlelement is
	 * removed from the DOM
	 */
	private function removedFromDOM():Void
	{
		switch (nodeType)
		{
			//synchronously detach the element renderer
			//of this HTMLElement and its child, and 
			//schedule an update of the rendering tree
			//
			//only element and text node can belong to the
			//rendering tree
			case DOMConstants.ELEMENT_NODE, DOMConstants.TEXT_NODE:
				detach(true);
				invalidateElementRenderer();
		}
	}
	
	/**
	 * Return wether this htmlelement is attached to the
	 * DOM. Check all ancestors until either a document
	 * is found, meaning the htmlelement is in factg attached
	 * to the DOM or null
	 */
	private function isAttachedToDOM():Bool
	{
		var parent:Node = parentNode;
		while (parent != null)
		{
			if (parent.nodeType == DOMConstants.DOCUMENT_NODE)
			{
				return true;
			}
			parent = parent.parentNode;
		}
		
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING TREE METHODS
	//
	// The HTMLElement is in charge of attaching and detaching its ElementRenderer to/from
	// the rendering tree when appropriate. The HTMLElement is only displayed to the screen
	// when attached to the rendering tree.
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Main method to update the rendering tree.
	 * Traverse the DOM tree recursively until
	 * the rendering tree is updated
	 * 
	 * HTMLElements with invalid element renderer
	 * detach/attach them as needed so that the
	 * rendering becomes again valid
	 * 
	 * Called by the document when the rendering tree
	 * needs to be updated
	 */
	public function updateElementRenderer():Void
	{
		//check wether this HTMLElement needs to update
		//its element renderer
		if (_needsElementRendererUpdate == true)
		{
			//once here, the element renderer is considered
			//updated
			_needsElementRendererUpdate = false;
		
			//here the HTMLElement should not
			//be rendered
			if (isRendered() == false)
			{
				//if it was previously rendered, it
				//is detached
				if (elementRenderer != null)
				{
					detach(true);
		
					//return as none of its children
					//needs to be attached
					return;
				}
			}
			//here the HTMLElement should be
			//rendered
			else
			{
				//if it is not yet rendered, attach
				//it and attach its children
				if (elementRenderer == null)
				{
					attach(true);
					
					//return as all its children are now attached
					return;
				}
				//else, update only its own
				//element renderer, no need
				//to re-create all its children
				else
				{
					//detach and attach only own element renderer
					detach(false);
					attach(false);
				}	
			}
		}
		
		if (nodeType == DOMConstants.ELEMENT_NODE)
		{
			//traverse all the DOM recursively to be
			//sure to update all element renderers
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				if (childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
				{
					var child:HTMLElement = cast(childNodes[i]);
					child.updateElementRenderer();
				}
			}
		}
	}
		
	/**
	 * Tries to attach the ElementRender to the rendering tree.
	 * 
	 * if the attachement is recursive, all children are attached
	 * too
	 * 
	 * The parent HTMLElement's ElementRenderer is always attached before
	 * its children ElementRenderers
	 */
	public function attach(recursive:Bool):Void
	{
		//if its parent is not rendered, then
		//this HTMLElemenet should not be
		//rendered either
		if (isParentRendered() == false)
		{
			return;
		}
		
		//check if can potentially be rendered
		if (isRendered() == true)
		{
			//actually instantiate the element renderer
			createElementRenderer();
		}
		
		//if the ElementRenderer wasn't instantiated, then this
		//HTMLElement is not supposed to be rendered
		//
		//TODO 3 : element renderers should always be rendered at this
		//point ? for instance, for head element should not be rendered
		//because has a display none style ?
		if (elementRenderer != null)
		{
			attachToParentElementRenderer();
			
            if (nodeType == DOMConstants.ELEMENT_NODE)
            {
                var length:Int = childNodes.length;
                for (i in 0...length)
                {
                    //if the attachement is recursive, then this node must also starts
                    //the attachement of its child html nodes
                    if (recursive == true && childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
                    {
                        var child:HTMLElement = cast(childNodes[i]);
                        child.attach(true);
                    }
                    else if (childNodes[i].nodeType == DOMConstants.TEXT_NODE)
                    {
                        attachTextNode(childNodes[i]);
                    }
                }
            }
		}
		
		_needsElementRendererUpdate = false;
	}
	
	/**
	 * Detach the ElementRenderer from the rendering tree
	 * 
	 * if the detachement is recursive, detach also all 
	 * of its children
	 * 
	 * The children ElementRenderer are always detached before
	 * their parent ElementRenderer
	 */
	public function detach(recursive:Bool):Void
	{
		//if this HTMLElement isn't currently rendered, no need
		//to detach it
		if (elementRenderer != null)
		{			
            if (nodeType == DOMConstants.ELEMENT_NODE)
            {
                var length:Int = childNodes.length;
                for (i in 0...length)
                {
                    //if detachement is recursive than this node must also detach all of
                    //its child html nodes 
                    if (recursive == true && childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
                    {
                        var child:HTMLElement = cast(childNodes[i]);
                        child.detach(true);
                    }
                    else if (childNodes[i].nodeType == DOMConstants.TEXT_NODE)
                    {
                        detachTextNode(childNodes[i]);
                    }
                }
            }
			
			//then detach this ElementRenderer from the parent 
			//ElementRenderer
			detachFromParentElementRenderer();
			
			//TODO 1 : trouble for now in HTMLDocument, when disposing
			//of element renderer, if it is the currently hovered element
			//throws exception when mouse move. Store hovered HTMLElement 
			//instead ?
			//elementRenderer.dispose();
			elementRenderer = null;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Retrieve the style definitions applying to this HTMLElement which can 
	 * come from the document's style sheet, the inline style declaration
	 * of this HTMLElement and inherited through the parent node, and
	 * for each supported CSS style, find the right value to use among
	 * the different provided values
	 * 
	 * @param cascadeManager keep track of the style that need to be cascaded. For
	 * instance contain the styles of the parent which were just cascaded
	 * 
	 * @param programmaticChange wether the cascade was caused by a scripted property
	 * cahnge. Some pseudo class like :hover are also considered like scripting a change
	 */
	public function cascade(cascadeManager:CascadeManager, programmaticChange:Bool):Void
	{	
		//cascade the style of this HTMLElement if needed, and store
		//the name of all the style which changed during cascading
		//
		//style is cascaded either id tis HTMLElement explicitely needs cascading
		//for instance, if one of its attribute changed since last cascade or
		//if some of its parent styles just changed
		if (_needsCascading == true || cascadeManager.hasPropertiesToCascade == true)
		{
			cascadeSelf(cascadeManager, programmaticChange);
			_needsCascading = false;
			
			//when one of those property specified value changes, it may affect the rendering of
			//the HTMLElement. The element renderer is invalidated, so that it will be updated
			//before next layout
			if (cascadeManager.hasDisplay == true || cascadeManager.hasFloat == true
			|| cascadeManager.hasOverflowX == true || cascadeManager.hasOverflowY == true ||
			cascadeManager.hasPosition == true)
			{
				detach(true);
				invalidateElementRenderer();
			}
			//if one of those properties changed, then the layer renderer of the element renderer needs
			//to be invalidated, so that it will be updated before next rendering
			else if (cascadeManager.hasTransform == true || cascadeManager.hasZIndex == true || cascadeManager.hasOpacity == true)
			{
				invalidateLayerRenderer();
			}
		}
		
		//cascade all the children, to cascade all the DOM tree
		//recursively
		var childLength:Int = childNodes.length;
		for (i in 0...childLength)
		{
			if (childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
			{
				var htmlChild:HTMLElement = cast(childNodes[i]);
				htmlChild.cascade(cascadeManager, programmaticChange);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the style declaration for this HTMLElement
	 * coming from the style manager
	 */
	private function getStyleDeclaration():Void
	{
		//set all the styles to be cascaded
		//
		//TODO 3 : eventually, should only update style which actually changed
		_shouldCascadeAllProperties = true;
		
		//update style definition
		styleManagerCSSDeclaration = _ownerHTMLDocument.getStyleDeclaration(this);
	}
	
	/**
	 * Make the HTMLElement cascade its styles. The cascaded styles are those whihc have
	 * been modified since last cascade on this HTMLElement and the styles of the direct
	 * parent which have been modified during this cascade
	 * @param	cascadeManager contain the properties which changed on the parent during this
	 * cascade
	 * @param	programmaticChange wether the change is programmatic. If it is,
	 * animations may be started
	 */
	private function cascadeSelf(cascadeManager:CascadeManager, programmaticChange:Bool):Void
	{
		if (parentNode != null)
		{
			var parent:HTMLElement = cast(parentNode);
			if (parent.styleManagerCSSDeclaration != null)
			{
				if (_needsStyleDeclarationUpdate == true || styleManagerCSSDeclaration == null)
				{
					getStyleDeclaration();
					_needsStyleDeclarationUpdate = false;
				}
				
				
				var parentStyleDeclaration:CSSStyleDeclaration = parent.coreStyle.computedValues;
				var parentFontMetrics:FontMetricsVO = parent.coreStyle.fontMetrics;
			
				if (_shouldCascadeAllProperties == true)
				{
					cascadeManager.shouldCascadeAll();
				}
				else
				{
					var length:Int = _pendingChangedProperties.length;
					for (i in 0...length)
					{
						cascadeManager.addPropertyToCascade(_pendingChangedProperties[i]);
					}
				}
	
				//update the relative reference for the cascade of this node
				cascadeManager.parentRelativeLengthReference.em = parentFontMetrics.fontSize;
				cascadeManager.parentRelativeLengthReference.ch = parentFontMetrics.zeroHeight;
				cascadeManager.parentRelativeLengthReference.ex = parentFontMetrics.xHeight;
				
				coreStyle.cascade(cascadeManager, _initialStyleDeclaration, styleManagerCSSDeclaration, style, parentStyleDeclaration, programmaticChange);
			}
		}
		
		_shouldCascadeAllProperties = false;
		_pendingChangedProperties = [];
	}
	
	/**
	 * When a value of the inline style declaration
	 * of the HTMLElement changes, store the index
	 * of the changed property in the properties
	 * to cascade and invalidate the cascade
	 * 
	 * @param changedPropertyIndex the index of the property
	 * which changed
	 */
	private function onInlineStyleChange(changedPropertyIndex:Int):Void
	{
		//no need to store the property if all properties
		//are supposed to be cascaded anyway
		if (_shouldCascadeAllProperties == false)
		{
			_pendingChangedProperties.push(changedPropertyIndex);
		}
		
		invalidateCascade();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the first HTMLElement sibling which has an
	 * ElementRenderer attached to the rendering tree or null
	 * if there is none. It is used to know where to attach this
	 * HTMLElement's ElementRenderer in the rendering tree
	 */
	private function getNextElementRendererSibling():ElementRenderer
	{
		var nextSibling:Node = this.nextSibling;
					
		if (nextSibling == null)
		{
			return null;
		}
		else
		{
			while (nextSibling != null)
			{
				if (nextSibling.nodeType == DOMConstants.ELEMENT_NODE)
				{
					var htmlNextSibling:HTMLElement = cast(nextSibling);
					if (htmlNextSibling.elementRenderer != null)
					{
						var elementRenderParent:ElementRenderer = htmlNextSibling.elementRenderer.parentNode;
						
						//in the case where the parent of the next sibling's elementRenderer is an 
						//anonymous block, the anonymous block should be return as sibling
						if (elementRenderParent.isAnonymousBlockBox() == true)
						{
							return elementRenderParent;
						}
						
						return htmlNextSibling.elementRenderer;
					}
				}
				
				
				nextSibling = nextSibling.nextSibling;
			}
		}
		
		return null;
	}
	
	/**
	 * attach the created ElementRenderer to the rendering tree before the ElementRenderer
	 * of the first next HTMLElement sibling which also has an attached ElementRenderer.
	 * If there is none such sibling, it is appended as the last child of this node of
	 * the rendering tree
	 */
	private function attachToParentElementRenderer():Void
	{
		var parent:HTMLElement = cast(parentNode);
		parent.elementRenderer.insertBefore(elementRenderer, getNextElementRendererSibling());
	}
	
	/**
	 * When this HTMLElement is detached, it detaches its
	 * ElementRenderer from its parent ElementRenderer
	 */
	private function detachFromParentElementRenderer():Void
	{
		elementRenderer.parentNode.removeChild(elementRenderer);
	}
	
	/**
	 * This HTMLElement is responsible for instantiating text renderer
	 * for it's child text nodes and to attach to text renderers to
	 * the rendering tree
	 * @param	textNode the text node that must be attached to the rendering
	 * tree
	 */
	private function attachTextNode(textNode:Node):Void
	{
		var textRenderer:TextRenderer = new TextRenderer(textNode, coreStyle);
		elementRenderer.appendChild(textRenderer);
	}
	
	/**
	 * The HTMLElement is also in charge of detaching is rendered text child nodes
	 * from the rendering tree. When a text node must be detached, find
	 * the node it owns in the rendering tree then remove it from the rendering
	 * tree
	 * @param textNode the text node to remove from the rendering tree
	 */
	private function detachTextNode(textNode:Node):Void
	{
		var child:ElementRenderer = elementRenderer.firstChild;
		while (child != null)
		{
			if (child.domNode == textNode)
			{
				elementRenderer.removeChild(child);
				return;
			}
			//special case for anonymous block, check wether the wrapped
			//child is the text renderer owned by the text node
			else if (child.isAnonymousBlockBox() == true)
			{
				if (child.firstChild != null)
				{
					if (child.firstChild.domNode == textNode)
					{
						elementRenderer.removeChild(child);
						return;
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Instantiate the right ElementRenderer
	 * based on the Display style and/or the 
	 * type of HTMLElement
	 */
	private function createElementRenderer():Void
	{
		
		
		switch (coreStyle.getKeyword(coreStyle.display))
		{
			case BLOCK, INLINE_BLOCK:
				elementRenderer = new BlockBoxRenderer(this, coreStyle);
				
			case INLINE:
				elementRenderer = new InlineBoxRenderer(this, coreStyle);
				
			case NONE:
				
			default:
				throw 'Illegal value for display style';
		}
	}
	
	/**
	 * Return wether this HTMLElement is supposed to be rendered
	 */
	private function isRendered():Bool
	{
		//use "hidden" HTML attribute
		if (hidden == true)
		{
			return false;
		}
	
		//use "display" CSS style
		if (coreStyle.isNone(coreStyle.display))
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * Determine wether the parent HTMLElement is
	 * rendered and attached to the rendering tree
	 */
	private function isParentRendered():Bool
	{
		if (parentNode == null)
		{
			return false;
		}
		var parent:HTMLElement = cast(parentNode);
		return parent.elementRenderer != null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * start pending transitions of self and of all children.
	 * 
	 * @return Wether at least one transition started
	 */
	public function startPendingTransitions():Bool
	{
		var atLeastOneTransitionStarted:Bool = false;
		
		var transitionStarted:Bool = coreStyle.startPendingTransitions();
		
		if (transitionStarted == true)
		{
			atLeastOneTransitionStarted = true;
		}
		
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			if (childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
			{
				var child:HTMLElement = cast(childNodes[i]);
				var transitionStarted:Bool = child.startPendingTransitions();
				
				if (transitionStarted == true)
				{
					atLeastOneTransitionStarted = true;
				}
			}
			
		}
		
		return atLeastOneTransitionStarted;
	}
	
	/**
	 * end pending transition of self and
	 * children
	 */
	public function endPendingTransitions():Void
	{
		coreStyle.endPendingTransitions();
	
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			if (childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
			{
				var child:HTMLElement = cast(childNodes[i]);
				child.endPendingTransitions();
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SELECTORS API METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the first element nodes matching the provided selector, looking in all
	 * the DOM tree starting from this node
	 * @param	selectors
	 * @return	the first matching node or null if there are none
	 */
	public function querySelector(selectors:String):HTMLElement
	{
		var typedSelectors:Array<SelectorVO> = new Array<SelectorVO>();
		var isValidSelector:Bool = parseSelectors(selectors, typedSelectors);
		if (isValidSelector == false)
		{
			throw DOMException.SYNTAX_ERR;
		}
		
		var nodes:NodeList = doQuerySelector(this, typedSelectors, false);
		
		if (nodes.length == 0)
		{
			return null;
		}
		else
		{
			return cast(nodes[0]);
		}
	}
	
	/**
	 * Return the descendant element nodes of this node which
	 * match the provided selector
	 * @param	selectors
	 * @return	a node list, possibly empty of no matches
	 */
	public function querySelectorAll(selectors:String):NodeList
	{
		var typedSelectors:Array<SelectorVO> = new Array<SelectorVO>();
		var isValidSelector:Bool = parseSelectors(selectors, typedSelectors);
		if (isValidSelector == false)
		{
			throw DOMException.SYNTAX_ERR;
		}
		
		return doQuerySelector(this, typedSelectors, true);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SELECTORS API METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Do get the node matching the selectors, starting from this node and checking
	 * all the descendants recursively
	 * 
	 * @param	node the current node
	 * @param	selectors the typed parsed selectors
	 * @param	queryAll wether to get all matching descendant (true) or
	 * stop at the first match (false)
	 * @return	the list of matching nodes, might be empty
	 */
	private function doQuerySelector(node:HTMLElement, selectors:Array<SelectorVO>, queryAll:Bool):NodeList
	{
		//will hold all matching nodes
		var nodes:NodeList = new NodeList();
		
		//first check the current node
		var matches:Bool = _ownerHTMLDocument.matchesSelector(node, selectors);
		if (matches == true)
		{
			nodes.push(node);
			
			//if false, stop on first matching node
			if (queryAll == false)
			{
				return nodes;
			}
		}
		
		//check all descendant
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			//only applies to element nodes
			if (node.childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
			{
				var matchingNodes:NodeList = doQuerySelector(cast(node.childNodes[i]), selectors, queryAll);
				
				//if queryAll false, stop on first match
				if (queryAll == false && matchingNodes.length > 0)
				{
					return matchingNodes;
				}
				
				//else add all matching nodes
				var matchingNodesLength:Int = matchingNodes.length;
				for (j in 0...matchingNodesLength)
				{
					nodes.push(matchingNodes[j]);
				}
			}
		}
		
		return nodes;
	}
	
	/**
	 * Parse the provided css selectors into an array
	 * of typed selectors
	 * @param	selectors	the selectors as a comma separated string
	 * @param	typedSelectors the array which should be filled by the parsed
	 * selectors
	 * @return	wether the selectors are valid, return false if at least one
	 * is not valid
	 */
	private function parseSelectors(selectors:String, typedSelectors:Array<SelectorVO>):Bool
	{
		var selectorParser:CSSSelectorParser = new CSSSelectorParser();
		
		var separatedSelectors:Array<String> = selectors.split(",");
		for (i in 0...separatedSelectors.length)
		{
			var isValidSelector:Bool = selectorParser.parseSelector(separatedSelectors[i], typedSelectors);
			if (isValidSelector == false)
			{
				return false;
			}
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CLICK SYNTHESIS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Simulates a mouse click on an element.
	 * 
	 * The screen and client coordinate of the 
	 * generated MouseEvent are 0 and modifier
	 * key (Shift, control...) correspond
	 * to the current modifier key state
	 * 
	 * TODO 2 : get current modifier key state
	 */
	public function click():Void
	{
		dispatchEvent(createMouseClickEvent());
	}
	
	/**
	 * Create and return a simulated click event
	 */
	private function createMouseClickEvent():MouseEvent
	{
		var mouseEvent:MouseEvent = new MouseEvent();
		mouseEvent.initMouseEvent(EventConstants.CLICK, false, false, null, 0, 0, 0, 0, 0, false, false, false, false,
		0, null); 
		
		return mouseEvent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENT DISPATCH HELPERS
	// helper methods to dispatch events on this HTMLElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * dispatch event of type Event
	 * 
	 * @return wether the default action was prevented
	 */
	private function fireEvent(eventType:String, bubbles:Bool, cancelable:Bool):Bool
	{
		var event:Event = new Event();
		event.initEvent(eventType, bubbles, cancelable);
		dispatchEvent(event);
		
		return event.defaultPrevented;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the htmlElement can receive
	 * focus
	 */
	public function isFocusable():Bool
	{
		//if it isn't attached to the DOM,
		//it can't be focused
		if (parentNode == null)
		{
			return false;
		}
		
		//if it isn't currently rendered,
		//it can't be focused
		if (elementRenderer == null)
		{
			return false;
		}
		
		//it can be focused if it is inherently
		//focusable
		else if (isDefaultFocusable() == true)
		{
			return true;
		}
		
		//else, an element with a tab index 
		//superior to 0 can receive focus
		else if (tabIndex > 0)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Return wether this HTMLElement can intrinsically recieve
	 * focus, this is the case for instance for HTMLInputElement
	 */
	private function isDefaultFocusable():Bool
	{
		return false;
	}
	
	/**
	 * Gives keyboard focus to the HTMLElement
	 * The focus manager determines if the HTMLElement can
	 * actually receive focus
	 */
	public function focus():Void
	{
		_ownerHTMLDocument.activeElement = this;
	}
	
	/**
	 * Removes keyboard focus from this HTMLElement and 
	 * the focus on the Document
	 */
	public function blur():Void
	{
		_ownerHTMLDocument.body.focus();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FULLSCREEN METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Displays the element fullscreen
	 * 
	 * TODO 5 : the implementation is different from
	 * the spec, simpler. However the spec are only
	 * at early stage, will be updated once they
	 * are more widely implemented
	 */
	public function requestFullScreen():Void
	{
		_ownerHTMLDocument.fullscreenElement = this;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// ACTIVATION BEHAVIOUR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Certain elements in HTML have an activation behavior,
	 * which means that the user can activate them. 
	 * This triggers a sequence of events dependent on the activation mechanism,
	 * and normally culminating in a click event, as described below.
	 * 
	 * For instance, an HTMLAnchorElement has the activation behaviour of
	 * following a link. If one of its children is clicked by the user,
	 * it will trigger its activation behaviour
	 */
	
	 /**
	 * Run the full activation behaviour of this element, including
	 * dispatching the click event which triggered the activation. If the click event
	 * is null, for instance if it was triggered by keyboard, simulate a click instead
	 */
	public function triggerActivationBehaviour(clickEvent:MouseEvent = null):Void
	{
		//find the first parent which has an activation behaviour, might
		//return null
		var nearestActivatableElement:HTMLElement = getNearestActivatableElement();

		//execute pre activation
		if (nearestActivatableElement != null)
		{
			nearestActivatableElement.runPreClickActivation();
		}
		
		//might be null if triggered by keyboard or other input method
		if (clickEvent == null)
		{
			clickEvent = createMouseClickEvent();
		}
		
		dispatchEvent(clickEvent);
		
		//execute post or canceled activation behaviour
		if (nearestActivatableElement != null)
		{
			if (clickEvent.defaultPrevented == true)
			{
				nearestActivatableElement.runCanceledActivationStep();
			}
			else
			{
				nearestActivatableElement.runPostClickActivationStep(clickEvent);
			}
		}
	}
	 
	 /**
	  * Wheter this HTMLElement has any activation 
	  * behaviour associated with it
	  */
	public function hasActivationBehaviour():Bool
	{
		return false;
	}
	
	/**
	 * called before the click event is dipatched
	 */
	public function runPreClickActivation():Void
	{
		
	}
	
	/**
	 * Called if the activation behaviour is cancelled
	 */
	public function runCanceledActivationStep():Void
	{
		
	}
	
	/**
	 * Called after the click was dispatched
	 */
	public function runPostClickActivationStep(event:MouseEvent):Void
	{
		
	}
	
	/**
	 * Return the first ancestor HTMLElement which has an 
	 * activation behaviour. HTMLElement return itself if
	 * it has one
	 */
	public function getNearestActivatableElement():HTMLElement
	{
		var htmlElement:HTMLElement = this;
		while (htmlElement.hasActivationBehaviour() == false)
		{
			if (htmlElement.parentNode == null || htmlElement.parentNode.nodeType == DOMConstants.DOCUMENT_NODE)
			{
				return null;
			}
			
			htmlElement = cast(htmlElement.parentNode);
		}
		
		return htmlElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLING SETTER/GETTER AND METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	private function get_scrollHeight():Int
	{
		updateDocumentImmediately();
		
		if (elementRenderer != null)
		{
			return Math.round(elementRenderer.scrollHeight);
		}
		return 0;
	}
	
	private function get_scrollWidth():Int
	{
		updateDocumentImmediately();
		
		if (elementRenderer != null)
		{
			return Math.round(elementRenderer.scrollWidth);
		}
		return 0;
	}
	
	private function set_scrollLeft(value:Int):Int
	{
		if (elementRenderer != null)
		{
			elementRenderer.scrollLeft = value;
		}
		return value;
	}
	
	private function get_scrollLeft():Int
	{
		updateDocumentImmediately();
		
		if (elementRenderer != null)
		{
			return Math.round(elementRenderer.scrollLeft);
		}
		return 0;
	}
	
	private function set_scrollTop(value:Int):Int
	{
		if (elementRenderer != null)
		{
			elementRenderer.scrollTop = value;
		}
		return value;
	}
	
	private function get_scrollTop():Int
	{
		updateDocumentImmediately();
		
		if (elementRenderer != null)
		{
			return Math.round(elementRenderer.scrollTop);
		}
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_tabIndex(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	/**
	 * Return the tab index as an int
	 * @return
	 */
	private function get_tabIndex():Int
	{
		var tabIndex:String = super.getAttribute(HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME);
		
		if (tabIndex == null)
		{
			//default value for focusable element is 0,
			//else its -1
			if (isDefaultFocusable() == true)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return Std.parseInt(tabIndex);
		}
	}
	
	/**
	 * Retrieve the id value from the attributes
	 * map
	 * @return the id as a string or the empty string
	 * if it was not set 
	 */
	private function get_id():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_ID_ATTRIBUTE_NAME);
	}
	
	/**
	 * update the id value on the attributes map
	 */
	private function set_id(value:String):String
	{
		setAttribute(HTMLConstants.HTML_ID_ATTRIBUTE_NAME, value);
		return value;
	}
	
	/**
	 * Return the class name value from the attributes
	 * hash
	 */
	private function get_className():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME);
	}
	
	/**
	 * set the class name value on the attributes
	 * hash, update the classList
	 */
	private function set_className(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME, value);
		
		//update the class list as well
		classList = value.split(" ");
		
		//when the class name is set, the style declaration
		//of this HTMLElement should be updated on next cascade
		invalidateStyleDeclaration(true);
		
		return value;
	}
	
	private function get_hidden():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_HIDDEN_ATTRIBUTE_NAME);
	}
	
	private function set_hidden(value:Bool):Bool
	{
		setAttributeAsBool(HTMLConstants.HTML_HIDDEN_ATTRIBUTE_NAME, value);
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER HELPERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the named attribute's value as a string, or
	 * the empty string if the attribute does not exist
	 */
	private function getAttributeAsDOMString(name:String):String
	{
		var attribute:String = getAttribute(name);
		if (attribute == null)
		{
			attribute = "";
		}
		return attribute;
	}
	
	/**
	 * Return the named attribute's value as a string. This is a special
	 * case for enumerated attribute, which can only take a limited number
	 * of values
	 * @param	name
	 * @param	allowedValues the value allowed for this particular attribute
	 * @param	missingValueDefault the value to use if the attribute is not set, might be
	 * null
	 * @param	invalidValueDefault, the value to use if the attribute doesn't match any of 
	 * the enumerated values, might be null
	 * @return	the value of the attribute or the empty string, if no attribute is set and
	 * there is no missing default values
	 */
	private function getEnumeratedAttributeAsDOMString(name:String, allowedValues:Array<String>, missingValueDefault:String, invalidValueDefault:String):String
	{
		var attribute:String = getAttribute(name);
		
		//attribute is missing
		if (attribute == null)
		{
			if (missingValueDefault != null)
			{
				return missingValueDefault;
			}
			else
			{
				return "";
			}
		}
		
		var allowedValuesLength:Int = allowedValues.length;
		for (i in 0...allowedValuesLength)
		{
			if (attribute == allowedValues[i])
			{
				//attribute has an allowed value
				return attribute;
			}
		}
		
		//attribute has not an allowed value
		//might take invalid or missing default
		if (invalidValueDefault != null)
		{
			return invalidValueDefault;
		}
		else if (missingValueDefault != null)
		{
			return missingValueDefault;
		}
		else
		{
			return "";
		}
	}
	
	/**
	 * For attribute of type Bool, they are always
	 * true if any value is specified
	 */
	private function getAttributeAsBool(name:String):Bool
	{
		if (getAttribute(name) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/**
	 * When an attribute is set to false, its attribute node
	 * is removed, else its attribute value is set to the empty
	 * string
	 */
	private function setAttributeAsBool(name:String, value:Bool):Void
	{
		var attribute:String = getAttribute(name);
		if (value == false)
		{
			if (attribute != null)
			{
				removeAttribute(name);
			}
		}
		else
		{
			setAttribute(name, "");
		}
	}
	
	/**
	 * If unsigned attribute absent, returns default value or 0
	 */
	private function getAttributeAsSignedInteger(name:String, defaultValue:Null<Int>):Int
	{
		var attribute:String = getAttribute(name);
		if (attribute == null)
		{
			if (defaultValue != null)
			{
				return defaultValue;
			}
			else
			{
				return 0;
			}
		}
		
		return Std.parseInt(attribute);
	}
	
	/**
	 * Same as above but returns -1 instead of 0 if missing value and default
	 */
	private function getAttributeAsPositiveSignedInteger(name:String, defaultValue:Null<Int>):Int
	{
		var attribute:String = getAttribute(name);
		if (attribute == null)
		{
			if (defaultValue != null)
			{
				return defaultValue;
			}
			else
			{
				return -1;
			}
		}
		
		var valueAsInt:Int = Std.parseInt(attribute);
		if (valueAsInt < 0)
		{
			return -1;
		}
		else
		{
			return valueAsInt;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove all the currently added child nodes,
	 * deserialize the passed HTML string and attach
	 * the resulting child nodes
	 * 
	 * @param	value an HTML String 
	 */
	private function set_innerHTML(value:String):String
	{
		var childLength:Int = childNodes.length;
		for (i in 0...childLength)
		{
			removeChild(childNodes[0]);	
		}

		//wrap the HTML String in a div element, else
		//when creating the html node, only the first 
		//node content is deserialized and not its
		//siblings
		var wrappedHTML:String = HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;
		wrappedHTML += value;
		wrappedHTML += HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_TOKEN_SOLIDUS + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;
		
		//parse the html string into a node object
		var node:Node = DOMParser.parse(wrappedHTML, ownerDocument);

		//the returned node might be null for instance, if 
		//only an empty string was provided
		if (node == null)
		{
			return value;
		}
		
		//append all children of the generated node
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			appendChild(node.childNodes[0]);
		}
		
		return value;
	}

	/**
	 * Remove all the currently added child nodes,
	 * deserialize the passed HTML string and attach
	 * the resulting child nodes
	 * 
	 * @param	value an HTML String 
	 */
	private function set_outerHTML(value:String):String
	{
		//parse the html string into a node object
		var node:Node = DOMParser.parse(value, ownerDocument);

		var oldNextSibling:HTMLElement = cast(this.nextSibling);
		parentNode.removeChild(cast(this));

		if (node == null)
		{
			return value;
		}

		parentNode.insertBefore( node, oldNextSibling );

		return value;
	}

	/**
	 * Serialize the descendant nodes of this HTMLElement
	 * and return the result as an HTML String
	 */
	private function get_innerHTML():String
	{
		//serialise this node into an HTML string
		var str:String = DOMParser.serialize(this);
		
		//remove the first and last tag, as they correspond to this HTMLElement
		//tag which should not be returned as its inner html
		str = str.substr(str.indexOf(HTMLConstants.HTML_TOKEN_MORE_THAN) + 1 , str.lastIndexOf(HTMLConstants.HTML_TOKEN_LESS_THAN) - str.indexOf(HTMLConstants.HTML_TOKEN_MORE_THAN) - 1);
		
		return str;
	}
	
	/**
	 * Serialize the HTMLElement and it's children
	 * and return the result as an HTML String
	 */
	private function get_outerHTML():String
	{
		//serialise this node into an HTML string
		var str:String = DOMParser.serialize(this);
		
		return str;
	}
	
	/**
	 * Utils method describing wether the HTMLElement
	 * is a void element, meaning it can't have any
	 * content and can be represented by a self-closing
	 * tag, like for instance the <img/> tag
	 */
	public function isVoidElement():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// COORDS SETTERS/GETTERS
	// Setters/Getters for an HTMLElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the first positioned ancestor of the HTMLElement
	 * 
	 * @return an HTMLElement or null if this HTMLElement is not yet
	 * added to the DOM
	 */
	private function get_offsetParent():HTMLElement
	{
		//here the HTMLElement is not
		//rendered 
		if (elementRenderer == null)
		{
			return null;
		}
		
		//fixed positioned element are relative to the viewport
		switch(coreStyle.getKeyword(coreStyle.position))
		{
			case FIXED:
				return null;
			
			default:	
		}
		
		//find the first non-static parent or return the body
		var parent:HTMLElement = cast(parentNode);
		while (parent != null)
		{
			if (parent.elementRenderer.isPositioned() == true || parent.tagName == HTMLConstants.HTML_BODY_TAG_NAME)
			{
				return parent;
			}
			parent = cast(parent.parentNode);
		}
		
		return null;
	}
	
	private function get_offsetWidth():Int
	{
		//need to perform an immediate update to be sure
		//that the computed styles are up to date
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.width + usedValues.paddingLeft + usedValues.paddingRight + usedValues.borderLeftWidth + usedValues.borderRightWidth);
		}
		
		return 0;
	}
	
	private function get_offsetHeight():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.height + usedValues.paddingTop + usedValues.paddingBottom + usedValues.borderTopWidth + usedValues.borderBottomWidth);
		}
		
		return 0;
	}
	
	private function get_offsetLeft():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var offsetParent:HTMLElement = get_offsetParent();
			//if there is no offset parent, return x relative to the viewport
			if (offsetParent == null)
			{
				return Math.round(elementRenderer.globalBounds.x);
			}
			//else subtract from offset parent x
			else
			{
				var globalX:Float = offsetParent.elementRenderer.globalBounds.x;
				
				//special case if the parent is the body, unless absolutely positioned, always
				//considered to be at the origin of the viewport
				if (offsetParent.tagName == HTMLConstants.HTML_BODY_TAG_NAME && offsetParent.elementRenderer.isAbsolutelyPositioned() == false)
				{
					globalX = 0;
				}
				
				return Math.round(elementRenderer.globalBounds.x - globalX);
			}
		}
		
		return 0;
	}
	
	private function get_offsetTop():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var offsetParent:HTMLElement = get_offsetParent();
			//if there is no offset parent, return y relative to the viewport
			if (offsetParent == null)
			{
				return Math.round(elementRenderer.globalBounds.y);
			}
			//else subtract from offset parent y
			else
			{
				var globalY:Float = offsetParent.elementRenderer.globalBounds.y;
				
				//special case if the parent is the body, unless absolutely positioned, always
				//considered to be at the origin of the viewport
				if (offsetParent.tagName == HTMLConstants.HTML_BODY_TAG_NAME && offsetParent.elementRenderer.isAbsolutelyPositioned() == false)
				{
					globalY = 0;
				}
				
				return Math.round(elementRenderer.globalBounds.y - globalY);
			}
		}
		
		return 0;
	}
	
	private function get_clientWidth():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.width + usedValues.paddingLeft + usedValues.paddingRight);
		}
		
		return 0;
	}
	
	private function get_clientHeight():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.height + usedValues.paddingTop + usedValues.paddingBottom);
		}
		
		return 0;
	}
	
	private function get_clientTop():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.borderTopWidth);
		}
		return 0;
	}
	
	private function get_clientLeft():Int
	{
		updateDocumentImmediately();
		if (elementRenderer != null)
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			return Math.round(usedValues.borderBottomWidth);
		}
		return 0;
	}
}
