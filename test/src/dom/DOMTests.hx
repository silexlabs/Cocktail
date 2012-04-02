/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package dom;

import cocktail.Cocktail;
import cocktail.Lib;
import core.dom.Attr;
import core.dom.Element;
import core.dom.NamedNodeMap;
import core.dom.Node;
import core.dom.Text;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class DOMTests 
{
	
	public static function main()
	{	
		var runner = new Runner();
		runner.addCase(new DOMTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	function testDocument()
	{
		Assert.equals(Lib.document.nodeType, NodeType.DOCUMENT_NODE);
		
		var div = Lib.document.createElement("div");
		
		Assert.equals(div.tagName, "div");
		
		var txt = Lib.document.createTextNode("test text");
		
		Assert.equals(txt.nodeValue, "test text");
		
		Lib.document.body.appendChild(div);
		div.setIdAttribute("id", true);
		div.setAttribute("id", "myDiv");
		var retrievedDiv = Lib.document.getElementById("myDiv");
		
		Assert.equals(div, retrievedDiv);
		
	}
	
	function testNode()
	{
		
		var node = new Node();
		var childNode = new Node();
		node.appendChild(childNode);
		
		Assert.isTrue(node.hasChildNodes());
		Assert.equals(node.childNodes.length, 1);
		Assert.equals(node.firstChild, childNode);
		Assert.equals(node.lastChild, childNode);
		Assert.equals(childNode.parentNode, node);
		
		Assert.isNull(node.nodeType);
		
		var siblingNode = new Node();
		node.appendChild(siblingNode);
		
		Assert.equals(childNode.nextSibling, siblingNode);
		Assert.equals(siblingNode.previousSibling, childNode);
		
		var removedNode = node.removeChild(childNode);
		
		Assert.equals(removedNode, childNode);
		Assert.isTrue(removedNode.isSameNode(childNode));
		Assert.isNull(childNode.parentNode);
		
		siblingNode.appendChild(childNode);
		
		Assert.equals(siblingNode.firstChild, childNode);
		
		var nodeInsertedBefore = new Node();
		siblingNode.insertBefore(nodeInsertedBefore, childNode);
		
		Assert.equals(siblingNode.firstChild, nodeInsertedBefore);
		
		var replacedNode = siblingNode.replaceChild(node, childNode);
		
		Assert.equals(replacedNode, childNode);
		Assert.equals(siblingNode.lastChild, node);
	}
	
	function testElement()
	{
		var el = new Element("div");
		
		Assert.equals(el.tagName, "div");
		Assert.equals(el.nodeName, "div");
		Assert.isNull(el.nodeValue);
		Assert.equals(el.nodeType, NodeType.ELEMENT_NODE);
		
		var childEl = new Element("div");
		el.appendChild(childEl);
		
		Assert.equals(el.firstElementChild, childEl);
		Assert.equals(el.lastElementChild, childEl);
		Assert.isNull(el.nextElementSibling);
		
		var txt = new Text();
		el.appendChild(txt);
		
		Assert.equals(el.firstElementChild, childEl);
		
		var siblingEl =  new Element("div");
		
		el.appendChild(siblingEl);
		
		Assert.equals(siblingEl.previousElementSibling, childEl);
		Assert.equals(childEl.nextElementSibling, siblingEl);
		Assert.equals(el.childElementCount, 2);
		
		el.setAttribute("test", "value");
		
		Assert.equals(el.getAttribute("test"), "value");
		
		el.setAttribute("test", "newValue");
		
		Assert.equals(el.getAttribute("test"), "newValue");
		Assert.isNull(el.getAttribute("undefined"));
		Assert.isTrue(el.hasAttribute("test"));
		Assert.isFalse(el.hasAttribute("undefined"));
		Assert.isTrue(el.hasAttributes());
		
		el.removeAttribute("test");
		Assert.isFalse(el.hasAttribute("test"));
		Assert.isFalse(el.hasAttributes());
		
		var attr:Attr = new Attr("test");
		el.setAttributeNode(attr);
		
		Assert.equals(el.getAttributeNode("test"), attr);
		
	}
	
	function testText()
	{
		var txt = new Text();
		txt.nodeValue = "bim";
		
		Assert.equals(txt.nodeValue, "bim");
		Assert.equals(txt.data, "bim");
		
		txt.data = "bam";
		Assert.equals(txt.nodeValue, "bam");
		Assert.equals(txt.data, "bam");
		
		Assert.equals(txt.nodeType, NodeType.TEXT_NODE);
	}
	
	function testNamedNodeMap()
	{
		var nnm = new NamedNodeMap();
		var attr:Attr = new Attr("test");
		var ret = nnm.setNamedItem(attr);
		
		Assert.isNull(ret);
		Assert.equals(nnm.getNamedItem("test"), attr);
		
		var replacementNode = new Attr("test");
		ret = nnm.setNamedItem(replacementNode);
		
		Assert.equals(ret, attr);
		Assert.equals(nnm.getNamedItem("test"), replacementNode);
		
		var addedAttr = new Attr("test2");
		nnm.setNamedItem(addedAttr);
		
		Assert.equals(addedAttr, nnm.item(1));
	}
	
	function testAttr()
	{
		var attr = new Attr("test");
		
		Assert.equals(attr.nodeName, "test");
		Assert.equals(attr.nodeType, NodeType.ATTRIBUTE_NODE);
		Assert.isFalse(attr.specified);
		
		attr.value = "value";
		
		Assert.equals(attr.nodeValue, "value");
		Assert.equals(attr.value, "value");
		Assert.isTrue(attr.specified);
		
		attr.nodeValue = "value2";
		
		Assert.equals(attr.nodeValue, "value2");
		Assert.equals(attr.value, "value2");
		
		var el = Lib.document.createElement("div");
		el.setAttributeNode(attr);
		
		Assert.equals(attr.ownerElement, el);
		
	}
}