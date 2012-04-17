/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.dataProvider;

/**
 * This class contains Rss utils for ThumbTextList1
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

import components.lists.ListBaseModels;
import components.lists.ListBaseUtils;

class ThumbTextList1Rss 
{
	/**
	 * Converts a rss to an Array of CellModels
	 * 
	 * @param	rss
	 * @return
	 */
	public static function rss2Cells(rss:Xml):Array<CellModel>
	{
		var cells:Array<CellModel> = new Array<CellModel>();

		// set channel node
		var channelNode:Xml = rss.firstElement().firstElement();
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				var cell:CellModel = { content:Dynamic, action:"", actionTarget:"" };
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
					// in case there is no thumbnail, fill with first image in the post
					if (itemParam.nodeName == "post_images")
					{
						if (!Reflect.hasField(cellContent, 'thumbnail') || (Reflect.field(cellContent, 'thumbnail') == ""))
						{
							for (elements in itemParam.elements())
							{
								cellContent.thumbnail = itemParam.firstElement().firstChild().nodeValue;
								break;
							}
						}
					}
					
					// if node is a title
					if (itemParam.nodeName == "title")
					{
						var title:String = itemParam.firstChild().nodeValue;
						// remove all characters after "Name" string, used to clean themes and plugins title
						var index:Int = title.indexOf("Name");
						if (index != -1)
						{
							title = title.substr(0, index);
						}
						// Samsung TV display bug workaround
						// clean white spaces at the end of the title, needed for silex plugins & themes rss feeds, otherwise square characters are displayed
						title = StringTools.rtrim(title);
						
						cellContent.title = title;
					}
					
					// if node is a author info
					if (itemParam.nodeName == "dc:creator")
					{
						/*for (authorInfo in itemParam.elements())
						{
							if (authorInfo.nodeName == "nickname")
							{
								cellContent.comment = cellContent.comment  + "by " + authorInfo.firstChild().nodeValue + " ";
							}
						}*/
						cellContent.comment = cellContent.comment  + "by " + itemParam.firstChild().nodeValue + " ";
					}
					
					// if node is a date
					if (itemParam.nodeName == "pubDate")
					{
						// create text
						cellContent.comment = cellContent.comment + "on " + itemParam.firstChild().nodeValue.substr(0,16) + " ";
					}
					
					// if node is a post content - removed as can contain html
					if (itemParam.nodeName == "description")
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
						//text = text.substr(0, 95) + "...";
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
						cell.action = "goToUrl";
						cell.actionTarget = itemParam.firstChild().nodeValue;
					}
				}
				cell.content = cellContent;
				cells.push(cell);
			}
		}
		return cells;
	}
	
}
