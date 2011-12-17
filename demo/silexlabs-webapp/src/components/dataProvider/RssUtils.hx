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

import components.richList.RichListModels;

class RssUtils 
{
	
	public static function rss2Cells(xml:Xml):Array<CellModel>
	{
		var cells:Array<CellModel> = new Array<CellModel>();

		// set channel node
		var channelNode:Xml = xml.firstElement().firstElement();
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				var cell:CellModel = { text:"", imagePath:"", action:"", actionTarget:"" };
				
				// for each node
				for (itemParam in channelChild.elements())
				{
					// Silex Labs feed
					// if node is a title
					if (itemParam.nodeName == "post_title")
					{
						cell.text = itemParam.firstChild().nodeValue;
					}
					// if node is a thumb image
					else if (itemParam.nodeName == "post_thumbnail")
					{
						cell.imagePath = itemParam.firstChild().nodeValue;
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
				cells.push(cell);
			}
		}
		return cells;
	}
}
