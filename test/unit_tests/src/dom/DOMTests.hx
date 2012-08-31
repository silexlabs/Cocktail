/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package dom;

import cocktail.Lib;
import cocktail.Dom;

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
		
		Assert.equals(Lib.document.nodeType, Node.DOCUMENT_NODE);
		
		var div = Lib.document.createElement("div");
		
		Assert.equals(div.tagName, "div");
		
		var txt = Lib.document.createTextNode("test text");
		
		Assert.equals(txt.nodeValue, "test text");
		
		Lib.document.body.appendChild(div);
		
		div.setIdAttribute("id", true);
		div.setAttribute("id", "myDiv");
		var retrievedDiv = Lib.document.getElementById("myDiv");
		
		Assert.equals(div, retrievedDiv);
		
		var li = Lib.document.createElement("li");
		
		var li2 = Lib.document.createElement("li");
		
		li.appendChild(li2);
		
		Lib.document.body.appendChild(li);
		
		var lis = Lib.document.getElementsByTagName("li");
		
		Assert.equals(lis[0], li);
		Assert.equals(lis[1], li2);
		
		
		var attr = Lib.document.createAttribute("bim");
		
		Assert.equals(attr.nodeName, "bim");
		Assert.equals(attr.value, "");
		
		
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
		
		Assert.equals(node.nodeType, -1);
		
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
		Assert.equals(el.nodeType, Node.ELEMENT_NODE);
		
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
		
		
		var childDivs = el.getElementsByTagName("div");
		
		Assert.equals(childDivs[0], childEl);
		Assert.equals(childDivs[1], siblingEl);
		
		var childEls = el.getElementsByTagName("*");
		
		Assert.equals(childEls[0], childEl);
		Assert.equals(childEls[1], siblingEl);
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
		
		Assert.equals(txt.nodeType, Node.TEXT_NODE);
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
		Assert.equals(attr.nodeType, Node.ATTRIBUTE_NODE);
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