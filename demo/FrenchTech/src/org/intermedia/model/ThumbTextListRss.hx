/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.model;

/**
 * This class contains Rss utils for ThumbTextList
 * 
 * @author Raphael Harmel
 */

import org.intermedia.model.ApplicationModel;

class ThumbTextListRss 
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
				var cell:CellData = { id:0, title:"", author:"", thumbUrl:"", category:""};
				
				// for each node
				for (itemParam in channelChild.elements())
				{
					// Silex Labs feed
					
					// if node is a thumbnail image
					if (itemParam.nodeName == "post_thumbnail")
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
						// remove unneeded white charaters at the end of the string (avoids display issues on specific devices)
						title = StringTools.rtrim(title);
						cell.title = title;
					}
					
					// if node is a author info
					if (itemParam.nodeName == "dc:creator")
					{
						cell.author = itemParam.firstChild().nodeValue;
					}
					
					// if node is the id
					if (itemParam.nodeName == "ID")
					{
						cell.id = Std.parseInt(itemParam.firstChild().nodeValue);
					}

					// if node is the category
					if (itemParam.nodeName == "category")
					{
						cell.category = itemParam.firstChild().nodeValue;
					}
				}
				// add cell to cell array
				cells.push(cell);
			}
		}
		
		// return cell array
		return cells;
	}
	
}
