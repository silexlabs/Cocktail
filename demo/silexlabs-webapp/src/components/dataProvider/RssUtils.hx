/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.dataProvider;

/**
 * This class contains Rss utils
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
//import cocktail.textElement.TextElement;

import components.richList.RichListModels;

class RssUtils 
{
	/**
	 * Converts a rss to an Array of CellModels
	 * 
	 * @param	rss
	 * @return
	 */
	//public static function rss2Cells(rss:Xml):Array<CellModel>
	public static function rss2Cells(rss:Xml):Array<DynamicCellModel>
	{
		var cells:Array<DynamicCellModel> = new Array<DynamicCellModel>();

		// set channel node
		var channelNode:Xml = rss.firstElement().firstElement();
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				//var cell:CellModel = { text:"", imagePath:"", action:"openUrl", actionTarget:"http://www.google.com/" };
				var cell:DynamicCellModel = { content:Dynamic, action:"", actionTarget:"" };
				var cellContent:Dynamic = { imagePath:"", title:"", comment:"Posted ", description:"", commentCount:"0" };
				
				// for each node
				for (itemParam in channelChild.elements())
				{
					// Silex Labs feed
					
					// if node is a thumbnail image
					if (itemParam.nodeName == "post_thumbnail")
					{
						cellContent.thumbnail = itemParam.firstChild().nodeValue;
					}
					// if node is a title
					if (itemParam.nodeName == "post_title")
					{
						cellContent.title = itemParam.firstChild().nodeValue;
					}
					// if node is a author info
					if (itemParam.nodeName == "post_author")
					{
						for (authorInfo in itemParam.elements())
						{
							if (authorInfo.nodeName == "nickname")
							{
								cellContent.comment = cellContent.comment  + "by " + authorInfo.firstChild().nodeValue + " ";
							}
						}
					}
					// if node is a date
					if (itemParam.nodeName == "post_date_gmt")
					{
						// create text
						//cellContent.comment = cellContent.comment  + "on " + itemParam.firstChild().nodeValue.substr(0,10) + " ";
						cellContent.comment = cellContent.comment + itemParam.firstChild().nodeValue.substr(0,10) + " ";
					}
					// if node is a post content - removed as can contain html
					if (itemParam.nodeName == "post_excerpt")
					{
						// create text
						var text:String = itemParam.firstChild().nodeValue;
						// remove "Online demo" texts
						var toRemove:Array<String> = ["Online Demo", "Online demo", "Description :"];
						for (string in toRemove)
						{
							text = StringTools.replace(text, string, "");
						}
						text = StringTools.ltrim(text);
						// shorten description
						text = text.substr(0, 95) + "...";
						// create container
						//var textContainer:ContainerDOMElement = Utils.getTextContainer(text);
						// apply style
						//listStyle.cellText(dateContainer);
						// add container to cellcontent
						cellContent.description = text;
					}
					// if node is the number of comments
					if (itemParam.nodeName == "comment_count")
					{
						cellContent.commentCount = itemParam.firstChild().nodeValue;
					}
					// if node is the link to be opened
					if (itemParam.nodeName == "guid")
					{
						cellContent.action = "openUrl";
						cellContent.actionTarget = itemParam.firstChild().nodeValue;
					}
					// FTV feed
					// if node is a title
					/*if (itemParam.nodeName == "title")
					{
						cell.text = itemParam.firstChild().nodeValue;
					}
					// if node is a thumb image
					else if (itemParam.nodeName == "enclosure")
					{
						cell.imagePath = itemParam.get("url");
					}*/
					
					// flikr feed
					// if node is a title
					/*if (itemParam.nodeName == "media:title")
					{
						cell.text = itemParam.firstChild().nodeValue;
					}
					// if node is a thumb image
					//if (itemParam.nodeName == "media:thumbnail")
					else if (itemParam.nodeName == "media:content")
					{
						cell.imagePath = itemParam.get("url");
					}*/
				}
				cell.content = cellContent;
				cells.push(cell);
			}
		}
		return cells;
	}
	
}
