/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.as3;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.text.engine.ContentElement;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.GroupElement;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.TextField;
import flash.Vector;
import haxe.Log;
import cocktail.domElement.abstract.AbstractTextDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

/**
 * This is the Text DOMElement implementation for Flash.
 * 
 * @author Yannick DOMINGUEZ
 */
class TextDOMElement extends AbstractTextDOMElement
{

	public function new(nativeElement:NativeElement = null) 
	{
		if (nativeElement ==  null)
		{
			nativeElement = NativeElementManager.createNativeElement(neutral);
		}
		super(nativeElement);
	}
	
	//TO DO : the method attaching lines should go in the TextStyle object. This object should create a 
	//Sprite, add lines to it, then set this Sprite as the native element of the Text DOMElement
	
	/**
	 * Append a text node to the current text content.
	 * @param	text a raw string of text
	 */
	override public function appendText(text:TextNode):Void
	{
		super.appendText(text);
		
		for (i in 0...this._nativeElement.numChildren - 1)
		{
			this._nativeElement.removeChildAt(0);
		}
		
		var textElements:Vector<ContentElement> = new Vector<ContentElement>();
		
		for (i in 0...this._children.length)
		{
			//Log.trace(this._children[i]);
			//textElements.push(cast(this._children[i]));
		}
		
		var e1:TextElement = new TextElement('Consider, what makes a text line a ', new ElementFormat(new FontDescription(), 12));
		var e2:TextElement = new TextElement('text line', new ElementFormat(new FontDescription("_serif", FontWeight.NORMAL, FontPosture.ITALIC), 12));
		var e3:TextElement = new TextElement('?', new ElementFormat(new FontDescription(), 12));
		
		 var e:Vector<ContentElement> = new Vector<ContentElement>();
		e.push(e1);
		e.push(e2);
		e.push(e3);
		
		var block:TextBlock = new TextBlock(new GroupElement(e));
		var line:TextLine = block.createTextLine(null, 100);
		
		//textElements.push(new TextElement("bim", new ElementFormat()));
		
		//var groupElement:GroupElement = new GroupElement(textElements);
		
		//var textBlock:TextBlock = new TextBlock(new GroupElement(textElements));
		
		//this._nativeElement.appendChild(text);
		//var textLine:TextLine = textBlock.createTextLine(null, 100);
		
		var _y:Float = 0;
		  while(line != null)
		  {
			this._nativeElement.addChild(line);
			_y += line.height;
			line.y = _y;
			line = block.createTextLine(line, 100);
		  }
		
		
		//line.y = 100;
		//this._nativeElement.addChild(line);
	}


}