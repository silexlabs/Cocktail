/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.model;

/**
 * This class contains Rss utils for ThumbTextListStandard
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

import org.intermedia.model.ApplicationModel;

class ThumbTextListRssStandard 
{
	/**
	 * Converts a rss to an Array of CellDatas
	 * 
	 * @param	rss
	 * @return
	 */
	public static function rss2Cells(rss:Xml):Array<CellData>
	{
		var cells:Array<CellData> = new Array<CellData>();

		// set channel node
		var channelNode:Xml = rss.firstElement().firstElement();
		
		// exit if no data
		if (channelNode == null)
			return cells;
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				//var cell:CellData = { id:0, title:"", author:"", thumbUrl:"", category:""};
				var cell:CellData = { id:0, title:"", author:"", thumbUrl:"", category:"", description:"", content:""};
				//var cell:Dynamic = { imagePath:"", title:"", comment:"Posted ", description:"", commentCount:"0" };
				
				// for each node
				for (itemParam in channelChild.elements())
				{
					// Standard feed
					
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
					}*/
					
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
						// remove unneeded white charaters at the end of the string (avoids display issues on specific devices)
						title = StringTools.rtrim(title);
						cell.title = title;
					}
					
					// if node is a author info
					if (itemParam.nodeName == "dc:creator")
					{
						cell.author = itemParam.firstChild().nodeValue;
					}
					
					// if node is a description
					if (itemParam.nodeName == "description")
					{
						cell.description = itemParam.firstChild().nodeValue;
					}
					
					// if node is a description
					if (itemParam.nodeName == "content:encoded")
					{
						cell.content = itemParam.firstChild().nodeValue;
					}
					
					// if node is the id
					/*if (itemParam.nodeName == "ID")
					{
						cell.id = Std.parseInt(itemParam.firstChild().nodeValue);
					}*/

					// if node is the category
					/*if (itemParam.nodeName == "category")
					{
						cell.category = itemParam.firstChild().nodeValue;
					}*/
				}
				// add cell to cell array
				cells.push(cell);
			}
		}
		// return cell array
		return cells;
	}
	
}
