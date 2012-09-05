/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.InitialStyleDeclaration;
import cocktail.core.dom.Attr;
import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Element;
import cocktail.core.dom.NamedNodeMap;
import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.event.EventConstants;
import cocktail.core.event.EventTarget;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.parser.DOMParser;
import cocktail.core.css.CSSConstants;
import haxe.Stack;
import haxe.xml.Parser;
import cocktail.port.NativeElement;
import cocktail.core.event.Event;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.css.CoreStyle;
import cocktail.Lib;
import haxe.Log;
import cocktail.core.focus.FocusManager;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;
import cocktail.core.renderer.RendererData;
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
class HTMLElement extends Element<HTMLElement>
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
	 * sets or gets the HTML
	 * syntax describing the element's descendants.
	 */
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
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
	 * Between 2 cascade, store the names of all the
	 * properties whose value changed and which need
	 * to be re-cascaded.
	 * 
	 * Stored as a hash, for easy retrieval and so that properties
	 * which are changed multiple times between cascade are
	 * only stored and cascaded once
	 */
	private var _pendingChangedProperties:Hash<Void>;
	
	/**
	 * A reference to the ownerDocument, typed as
	 * an HTMLDocument to easily access method
	 * specific to this sub-class
	 * 
	 * TODO 3 : eventually shoul become type
	 * parameter
	 */
	private var _ownerHTMLDocument:HTMLDocument;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor.
	 */
	public function new(tagName:String) 
	{
		super(tagName);
		init();
		
		_needsCascading = false;
		_needsStyleDeclarationUpdate = false;
		_pendingChangedProperties = new Hash<Void>();
	}
	
	/**
	 * Init the HTMLElement attributes
	 */
	private function init():Void
	{	
		//init the core style for this HTMLElement
		initCoreStyle();
		
		//init the CSS style adapter
		initStyle();
		
		//init the Id attribute
		initId();
	}
	
	/**
	 * Instantiate the right style object for this
	 * HTMLElement. Overriden by HTMLElements with
	 * specific style objects, such as HTMLImageElement
	 */
	private function initCoreStyle():Void
	{
		coreStyle = new CoreStyle(this);
	}
	
	/**
	 * Init the style adapter providing manipulation
	 * of the styles through CSS strings
	 */
	private function initStyle():Void
	{
		style = new CSSStyleDeclaration(null, onInlineStyleChange);
	}
	
	/**
	 * Define the id attribute in the
	 * attribute maps, but it has no
	 * value yet
	 */
	private function initId():Void
	{
		var id:Attr<HTMLElement> = new Attr<HTMLElement>(HTMLConstants.HTML_ID_ATTRIBUTE_NAME);
		setIdAttributeNode(id, true);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * try to attach the new child to the
	 * rendering tree
	 */
	override public function appendChild(newChild:HTMLElement):HTMLElement
	{
		super.appendChild(newChild);
		
		//only element and text node are visual and can be
		//attached to the rendering tree
		switch (newChild.nodeType)
		{
			case DOMConstants.ELEMENT_NODE:
				newChild.attach();
				
			case DOMConstants.TEXT_NODE:
				var textChild:Text = cast(newChild);
				textChild.attach();
		}
		
		return newChild;
	}
	
	/**
	 * try to detach the old child from the
	 * rendering tree
	 */
	override public function removeChild(oldChild:HTMLElement):HTMLElement
	{
		//must happen before calling super, else
		//the HTMLElement won't have a parent to be detached
		//from anymore
		switch (oldChild.nodeType)
		{
			case DOMConstants.ELEMENT_NODE:
				var htmlChild:HTMLElement = oldChild;
				htmlChild.detach();
				
			case DOMConstants.TEXT_NODE:
				var textChild:Text = cast(oldChild);
				textChild.detach();
		}
		
		super.removeChild(oldChild);
	
		return oldChild;
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
	 * Overriden to update the style of the HTMLElement when
	 * the style attribte is set
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		//when the value of the "style" attribute changes, the whole
		//inline style delcaration is refreshed
		if (name == HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME)
		{
			style.cssText = value;
			super.setAttribute(name, value);
			
			//TODO 1 : retrieve changed style or done automatically via callback ?
			//when replacing style attribute, should first remove all styles ?
			invalidateCascade();
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
		if (name == HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME)
		{
			return Std.string(get_tabIndex());
		}
		//TODO 1 : a "style" attribute should always be specified, like for the id
		//attribute else, it won't be serialized when calling get_innerHTML, or add
		//it in the html serializer if not empty string ?
		else if (name == HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME)
		{
			//serialize the inline style object into a css string
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
		targetAncestors.push(Lib.document);
		targetAncestors.push(Lib.window);
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
	// OVERRIDEN SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also store a casted HTMLDocument
	 */
	override private function set_ownerDocument(value:Document):Document
	{
		super.set_ownerDocument(value);
		_ownerHTMLDocument = cast(value);
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the specified value of a style requiring a re-layout
	 * is changed, for instance when the width is changed. Invalidate
	 * the layout of the elementRenderer if the HTMLElement is rendered
	 */
	public function invalidate(invalidationReason:InvalidationReason):Void
	{
		if (elementRenderer != null)
		{
			elementRenderer.invalidate(invalidationReason);
		}
	}
	
	/**
	 * When a style defining the positioning scheme of this HTMLElement
	 * changes, such as display or position, this special case happen, as the 
	 * ElementRenderer might need to be changed.
	 * 
	 * For instance if the previous value of Display was
	 * "block" and it is changed to "none", then the ElementRenderer
	 * must be removed from the rendering tree and destroyed
	 * 
	 * Another example is if the value of Display is "inline" and
	 * it is swiched to "block", then the current inline ElementRenderer
	 * must be replaced by a block ElementRenderer
	 * 
	 * The detach and attach method are called on the parent HTMLElement. They
	 * should be called on the parent as for instance if an HTMLElement was displayed
	 * as block and is now displayed as inline, the formatting context of the parent
	 * ElementRenderer might be affected. Calling detach and attach on the parent also
	 * refresh all th siblings of the element whose positioning scheme changed
	 */
	public function invalidatePositioningScheme():Void
	{
		if (parentNode != null)
		{
			parentNode.detach();
			parentNode.attach();
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
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				childNodes[i].invalidateStyleDeclaration(true);
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
		#if macro
		#else
		_needsCascading = true;
		_ownerHTMLDocument.invalidateCascade();
			
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING TREE METHODS
	//
	// The HTMLElement is in charge of attaching and detaching its ElementRenderer to/from
	// the rendering tree when appropriate. The HTMLElement is only displayed to the screen
	// when attached to the rendering tree.
	//
	// When attached, the HTMLElement also retrieve the style declarations applying to 
	// to it, and cascade them
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Tries to attach the ElementRender to the rendering tree. If it is
	 * in fact attached, all of its children will be attached too.
	 * 
	 * The parent HTMLElement's ElementRenderer is always attached before
	 * its children ElementRenderers
	 * 
	 * Also responsible to start an initial cascade of the HTMLElement's
	 * style now that it is attached to the DOM
	 */
	public function attach():Void
	{
		//do an initial cascading
		//of the style of this HTMLElement
		initialCascadeSelf();

		//if the parent HTMLElement ElementRenderers is null, then
		//the parent is either not attached to the DOM or not rendered,
		//and this HTMLElement is not rendered either
		if (isParentRendered() == true)
		{
			//create the ElementRenderer if needed
			if (elementRenderer == null && isRendered() == true)
			{
				createElementRenderer();
				if (elementRenderer != null)
				{
					attachCoreStyle();
				}
			}
			
			//if the ElementRenderer wasn't instantiated, then this
			//HTMLElement is not supposed to be rendered
			if (elementRenderer != null)
			{
				//do attach to parent ElementRenderer
				attachToParentElementRenderer();
			}
			
			//the HTMLElement is now attached and can attach its children
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				//only text and element node can be attached, as other nodes
				//types are not visual
				switch (childNodes[i].nodeType)
				{
					//attach element node
					case DOMConstants.ELEMENT_NODE:
						var child:HTMLElement = childNodes[i];
						child.attach();
					
					//attach text node
					case DOMConstants.TEXT_NODE:
						var child:Text = cast(childNodes[i]);
						child.attach();
				}
			}
		}
	}
	
	/**
	 * Detach the ElementRenderer from the rendering tree
	 * and all of its children.
	 * 
	 * The children ElementRenderer are always detached before
	 * their parent ElementRenderer
	 */
	public function detach():Void
	{
		//if the parent is not attached, then this ElementRenderer
		//is not attached
		if (isParentRendered() == true)
		{
			//if this HTMLElement isn't currently rendered, no need
			//to detach it
			if (elementRenderer != null)
			{	
				//detach first all children
				var length:Int = childNodes.length;
				for (i in 0...length)
				{
					switch (childNodes[i].nodeType)
					{
						case DOMConstants.ELEMENT_NODE:
							var child:HTMLElement = childNodes[i];
							child.detach();
							
						case DOMConstants.TEXT_NODE:
							var child:Text = cast(childNodes[i]);
							child.detach();
					}
				}
											
				//then detach this ElementRenderer from the parent 
				//ElementRenderer, then destroy it
				detachFromParentElementRenderer();
				
				elementRenderer = null;
			}
		}
		
		//the style declaration is now invalide as
		//the HTMLElement is no longer attached to the
		//DOM
		styleManagerCSSDeclaration = null;
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
	 * @param parentChangedProperties a hash containing the names of all of the
	 * styles of the parent whose values changed during cascading
	 * 
	 * @param programmaticChange wether the cascade was caused by a scripted property
	 * cahnge. Some pseudo class like :hover are also considered like scripting a change
	 */
	public function cascade(parentChangedProperties:Hash<Void>, programmaticChange:Bool):Void
	{	
		//will hold all the property of this HTMLElement which changed during
		//cascading
		var changedProperties:Hash<Void> = new Hash<Void>();
		
		//cascade the style of this HTMLElement if needed, and store
		//the name of all the style which changed during cascading
		if (_needsCascading == true)
		{
			changedProperties = cascadeSelf(parentChangedProperties, programmaticChange);
			_needsCascading = false;
		}
		
		//when one of those property specified value changes, it may affect the rendering of
		//the HTMLElement. The cascade is interupted and the element is re-attached
		if (changedProperties.exists(CSSConstants.DISPLAY) || changedProperties.exists(CSSConstants.POSITION) ||
		changedProperties.exists(CSSConstants.FLOAT) || changedProperties.exists(CSSConstants.TRANSFORM) ||
		changedProperties.exists(CSSConstants.Z_INDEX) || changedProperties.exists(CSSConstants.OVERFLOW_X) ||
		changedProperties.exists(CSSConstants.OVERFLOW_Y))
		{
			invalidatePositioningScheme();
			return;
		}
		
		//cascade all the children, to cascade all the DOM tree
		//recursively
		var childNodes:Array<HTMLElement> = this.childNodes;
		var childLength:Int = childNodes.length;
		for (i in 0...childLength)
		{
			var childNode:HTMLElement = childNodes[i];
			childNode.cascade(changedProperties, programmaticChange);
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
		//store all the current style of the style declaration
		//which will need to be cascaded on next cascade
		if (styleManagerCSSDeclaration != null)
		{
			for (i in 0...styleManagerCSSDeclaration.length)
			{
				_pendingChangedProperties.set(styleManagerCSSDeclaration.item(i), null);
			}
		}
		
		//update style definition
		styleManagerCSSDeclaration = _ownerHTMLDocument.getStyleDeclaration(this);
		
		//store all the new declared styles which will need to be
		//cascaded too
		//
		//TODO 2 : should do same thing when updating "style" attribute
		if (styleManagerCSSDeclaration != null)
		{
			for (i in 0...styleManagerCSSDeclaration.length)
			{
				_pendingChangedProperties.set(styleManagerCSSDeclaration.item(i), null);
			}
		}
	}
	
	/**
	 * Called when the HTMLElement is attached to the DOM
	 * to do an initial cascading of its styles
	 */
	private function initialCascadeSelf():Void
	{
		_needsCascading = true;
		_needsStyleDeclarationUpdate = true;
		
		_ownerHTMLDocument.invalidateCascade();
		
		var initialStyleDeclaration:InitialStyleDeclaration = _ownerHTMLDocument.initialStyleDeclaration;
		//set all the supported CSS properties to be updated
		_pendingChangedProperties = initialStyleDeclaration.supportedCSSProperties;
		
		cascadeSelf(new Hash<Void>(), false);
	}
	
	/**
	 * Make the HTMLElement cascade its styles. The cascaded styles are those whihc have
	 * been modified since last cascade on this HTMLElement and the styles of the direct
	 * parent which have been modified during this cascade
	 * @param	parentChangedProperties the properties which changed on the parent during this
	 * cascade
	 * @param	programmaticChange wether the change is programmatic. If it is,
	 * animations may be started
	 * @return
	 * 
	 * TODO 1 : should subclass in HTMLHTMLElement
	 */
	private function cascadeSelf(parentChangedProperties:Hash<Void>, programmaticChange:Bool):Hash<Void>
	{
		var initialStyleDeclaration:InitialStyleDeclaration = _ownerHTMLDocument.initialStyleDeclaration;
		
		var changedProperties:Hash<Void> = new Hash<Void>();
		
		if (parentNode != null)
		{
			if (parentNode.styleManagerCSSDeclaration != null)
			{
				if (_needsStyleDeclarationUpdate == true || styleManagerCSSDeclaration == null)
				{
					getStyleDeclaration();
					_needsStyleDeclarationUpdate = false;
				}
				
				var parentStyleDeclaration:CSSStyleDeclaration = parentNode.coreStyle.computedValues;
				var parentFontMetrics:FontMetricsVO = parentNode.coreStyle.fontMetrics;
			
				for (propertyName in parentChangedProperties.keys())
				{
					_pendingChangedProperties.set(propertyName, null);
				}
				

				changedProperties = coreStyle.cascade(_pendingChangedProperties, initialStyleDeclaration, styleManagerCSSDeclaration, style, parentStyleDeclaration, parentFontMetrics.fontSize, parentFontMetrics.xHeight, programmaticChange);
				
			}
		}
		else
		{
			if (_needsStyleDeclarationUpdate == true || styleManagerCSSDeclaration == null)
			{
				getStyleDeclaration();
				_needsStyleDeclarationUpdate = false;
			}
			
			changedProperties = coreStyle.cascade(_pendingChangedProperties, initialStyleDeclaration, styleManagerCSSDeclaration, style, initialStyleDeclaration, 12, 12, programmaticChange);
		}
		
		_pendingChangedProperties = new Hash<Void>();
		
		return changedProperties;
	}
	
	/**
	 * When a value of the inline style declaration
	 * of the HTMLElement changes, store the name
	 * of the changed property in the hash of property
	 * to cascade and invalidate the cascade
	 * 
	 * @param changedProperty the name of the property
	 * which changed
	 */
	private function onInlineStyleChange(changedProperty:String):Void
	{
		_pendingChangedProperties.set(changedProperty, null);
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
		var nextSibling:HTMLElement = this.nextSibling;
					
		if (nextSibling == null)
		{
			return null;
		}
		else
		{
			while (nextSibling != null)
			{
				if (nextSibling.elementRenderer != null)
				{
					var elementRenderParent:ElementRenderer = nextSibling.elementRenderer.parentNode;
					
					//in the case where the parent of the next sibling's elementRenderer is an 
					//anonymous block, the anonymous block should be return as sibling
					if (elementRenderParent.isAnonymousBlockBox() == true)
					{
						return elementRenderParent;
					}
					return nextSibling.elementRenderer;
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
		parentNode.elementRenderer.insertBefore(elementRenderer, getNextElementRendererSibling());
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
	 * Instantiate the right ElementRenderer
	 * based on the Display style and/or the 
	 * type of HTMLElement
	 */
	private function createElementRenderer():Void
	{
		switch (coreStyle.getKeyword(coreStyle.display))
		{
			case BLOCK, INLINE_BLOCK:
				elementRenderer = new BlockBoxRenderer(this);
				
			case INLINE:
				elementRenderer = new InlineBoxRenderer(this);
				
			case NONE:
				
			default:
				throw 'Illegal value for display style';
		}
	}
	
	/**
	 * Set the ElementRenderer's style
	 */
	private function attachCoreStyle():Void
	{
		elementRenderer.coreStyle = coreStyle;
	}
	
	/**
	 * Return wether this HTMLElement is supposed to be rendered
	 * 
	 * TODO 3 : unit tests for "hidden" attribute
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
		var htmlParent:HTMLElement = parentNode;
		if (htmlParent.elementRenderer != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Recursively start pending animation
	 * 
	 * @return Wether at least one animation started
	 */
	public function startPendingAnimation():Bool
	{
		return doStartPendingAnimation();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * start pending animations of self and of all children.
	 * 
	 * @return Wether at least one animation started
	 */
	private function doStartPendingAnimation():Bool
	{
		var atLeastOneAnimationStarted:Bool = false;
		
		var animationStarted:Bool = coreStyle.startPendingAnimations();
		
		if (animationStarted == true)
		{
			atLeastOneAnimationStarted = true;
		}
		
		for (i in 0...childNodes.length)
		{
			var animationStarted:Bool = childNodes[i].startPendingAnimation();
			
			if (animationStarted == true)
			{
				atLeastOneAnimationStarted = true;
			}
		}
		
		return atLeastOneAnimationStarted;
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
		var mouseEvent:MouseEvent = new MouseEvent();
		mouseEvent.initMouseEvent(EventConstants.CLICK, false, false, null, 0, 0, 0, 0, 0, false, false, false, false,
		0, null); 
		dispatchEvent(mouseEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENT DISPATCH HELPERS
	// helper methods to dispatch events on this HTMLElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * dispatch event of type Event
	 */
	private function fireEvent(eventTye:String, bubbles:Bool, cancelable:Bool):Void
	{
		var event:Event = new Event();
		event.initEvent(eventTye, bubbles, cancelable);
		dispatchEvent(event);
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
			if (htmlElement.parentNode == null)
			{
				return null;
			}
			htmlElement = htmlElement.parentNode;
		}
		
		return htmlElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLING SETTER/GETTER AND METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method determining wether
	 * the HTMLElement displays an active
	 * vertical scrolbar
	 * @param scrollOffset an optionnal parameter determining
	 * the scroll offset which tries to be applied to the vertical scrollbar.
	 * If applying the offset doesn't scroll the HTMLElement, for instance
	 * if the HTMLElement is completely scrolled and a positive offset
	 * is applied to it, then the method return false
	 * 
	 * @return true if a vertical scrollbar is displayed
	 * and isactive
	 */
	public function isVerticallyScrollable(scrollOffset:Int = 0):Bool
	{
		if (elementRenderer != null)
		{
			return elementRenderer.isVerticallyScrollable(scrollOffset);
		}
		return false;
	}
	
	/**
	 * same as absove for the horizontal scrollbar
	 */
	public function isHorizontallyScrollable(scrollOffset:Int = 0):Bool
	{
		if (elementRenderer != null)
		{
			return elementRenderer.isHorizontallyScrollable(scrollOffset);
		}
		return false;
	}
	
	//TODO 3 : should unit test, not very sure what this getter
	//is supposed to return
	private function get_scrollHeight():Int
	{
		if (elementRenderer != null)
		{
			return Math.round(elementRenderer.scrollHeight);
		}
		return 0;
	}
	
	private function get_scrollWidth():Int
	{
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
		
		if (tabIndex == "")
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
	 * @return the id as a String or null
	 * if it was not set 
	 */
	private function get_id():String
	{
		return getAttribute(HTMLConstants.HTML_ID_ATTRIBUTE_NAME);
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
		return getAttribute(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME);
	}
	
	/**
	 * set the class name value on the attributes
	 * hash
	 */
	private function set_className(value:String):String
	{
		setAttribute(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_hidden():Bool
	{
		if (getAttribute(HTMLConstants.HTML_HIDDEN_ATTRIBUTE_NAME) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private function set_hidden(value:Bool):Bool
	{
		super.setAttribute(HTMLConstants.HTML_HIDDEN_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove all the currently added child nodes,
	 * deserialise the passed HTML string and attach
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
		var node:HTMLElement = DOMParser.parse(wrappedHTML, ownerDocument);

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
	 * Serialise the descendant nodes of this HTMLElement
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
	 * Utils method describing wether the HTMLElement
	 * is a void element, meaning it can't have any
	 * context and can be represented by a self-closing
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
		//attached to the DOM
		if (parentNode == null)
		{
			return null;
		}
		
		var parent:HTMLElement = parentNode;
		
		//loop in all the parents until a positioned or a null parent is found
		var isOffsetParent:Bool = parent.elementRenderer.isPositioned();
		
		while (isOffsetParent == false)
		{
			if (parent.parentNode != null)
			{
				parent = parent.parentNode;
				isOffsetParent = parent.elementRenderer.isPositioned();
			}
			//break the loop if the current parent has no parent
			else
			{
				isOffsetParent = true;
			}
		}
		
		return parent;
	}
	
	private function get_offsetWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		invalidate(InvalidationReason.needsImmediateLayout);
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		return Math.round(usedValues.width + usedValues.paddingLeft + usedValues.paddingRight);
	}
	
	private function get_offsetHeight():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		return Math.round(usedValues.height + usedValues.paddingTop + usedValues.paddingBottom);
	}
	
	//TODO 3  : unit test
	private function get_offsetLeft():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return Math.round(elementRenderer.positionedOrigin.x);
	}
	
	private function get_offsetTop():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return Math.round(elementRenderer.positionedOrigin.y);
	}
	
	private function get_clientWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		invalidate(InvalidationReason.needsImmediateLayout);
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		return Math.round(usedValues.width + usedValues.paddingLeft + usedValues.paddingRight);
	}
	
	private function get_clientHeight():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		return Math.round(usedValues.height + usedValues.paddingTop + usedValues.paddingBottom);
	}
	
	//TODO 5 : should be top border height
	private function get_clientTop():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return 0;
	}
	
	//TODO 5 : should be left border width
	private function get_clientLeft():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return 0;
	}
}