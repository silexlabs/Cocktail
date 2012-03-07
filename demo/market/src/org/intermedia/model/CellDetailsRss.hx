/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.model;

/**
 * This class contains Rss utils for CellDetailsRss
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

import org.intermedia.model.ApplicationModel;

class CellDetailsRss 
{
	/**
	 * Converts a rss to an Array of CellDatas
	 * 
	 * @param	rss
	 * @return
	 */
	public static function rss2CellDetail(rss:Xml,cellData:CellData):DetailData
	{
		//var cells:Array<CellData> = new Array<CellData>();

		// set channel node
		var channelNode:Xml = rss.firstElement().firstElement();
		
		//var cell:DetailData = { id:null, description:"" };
		var cell:DetailData =
		{
			id:cellData.id,
			title:cellData.title,
			author:cellData.author,
			thumbUrl:cellData.thumbUrl,
			category:cellData.category,
			description:""
		};
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		//for ( channelChild in channelNode.firstElement() )
		{
			if (channelChild.nodeName == "item")
			{
				//var cell:Dynamic = { imagePath:"", title:"", comment:"Posted ", description:"", commentCount:"0" };
				
				// for each node
				for (itemParam in channelChild.elements())
				//for (itemParam in channelChild.firstElement())
				{
					// Silex Labs feed
					
					// if node is a thumbnail image
					/*if (itemParam.nodeName == "post_thumbnail")
					{
						cell.thumbUrl = itemParam.firstChild().nodeValue;
					}
					// in case there is no thumbnail, fill with first image in the post
					if (itemParam.nodeName == "post_images")
					{
						if (!Reflect.hasField(cell, 'thumbnail') || (Reflect.field(cell, 'thumbnail') == ""))
						{
							for (elements in itemParam.elements())
							{
								cell.thumbUrl = itemParam.firstElement().firstChild().nodeValue;
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
						cell.title = title;
					}
					
					// if node is a author info
					if (itemParam.nodeName == "dc:creator")
					{
						/*for (authorInfo in itemParam.elements())
						{
							if (authorInfo.nodeName == "nickname")
							{
								cell.comment = cell.comment  + "by " + authorInfo.firstChild().nodeValue + " ";
							}
						}*/
						/*cell.author = cell.author  + "by " + itemParam.firstChild().nodeValue + " ";
					}
					
					// if node is a date
					/*if (itemParam.nodeName == "pubDate")
					{
						// create text
						cell.comment = cell.comment + "on " + itemParam.firstChild().nodeValue.substr(0,16) + " ";
					}*/
					
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
						cell.description = text;
						
						// take only the first item into account, as there can be multiple results for the search query
						break;
					}
					
					// if node is the number of comments
					/*if (itemParam.nodeName == "comment_count")
					{
						cell.commentCount = itemParam.firstChild().nodeValue;
					}*/
					
					// if node is the link to be opened, get the post id from it
					/*if (itemParam.nodeName == "guid")
					{
						//cell.action = "goToUrl";
						//cell.actionTarget = itemParam.firstChild().nodeValue;
						var index:Int = itemParam.firstChild().nodeValue.indexOf("p=") + 2;
						cell.id = Std.parseInt(itemParam.firstChild().nodeValue.substr(index));
					}*/
				}
				//trace(cell);
				// returns only first item in case there are multiple item returned form the search results
				return cell;
				//cell.content = cell;
				//cells.push(cell);
			}
		}
		//trace(cell);
		return cell;
		//trace(cells);
		//return cells;
	}
	
}
