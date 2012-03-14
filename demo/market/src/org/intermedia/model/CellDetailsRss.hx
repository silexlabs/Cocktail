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
	 * Converts a cell detail rss feed to a DetailData
	 * 
	 * @param	rss
	 * @return
	 */
	public static function rss2CellDetail(rss:Xml,cellData:CellData):DetailData
	{
		// init cell
		var cell:DetailData =
		{
			id:cellData.id,
			title:cellData.title,
			author:cellData.author,
			thumbUrl:cellData.thumbUrl,
			category:cellData.category,
			description:""
		};
		
		// set channel node
		var channelNode:Xml = rss.firstElement().firstElement();
		
		// exit if no data
		if (channelNode == null)
			return cell;
		
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
					// if node is a post content (without html)
					//if (itemParam.nodeName == "description")
					if (itemParam.nodeName == "post_excerpt")
					{
						// create text
						var text:String = itemParam.firstChild().nodeValue;
						// remove "Online demo" and description texts
						var toRemove:Array<String> = ["Online Demo", "Online demo", "Description :"];
						for (string in toRemove)
						{
							text = StringTools.replace(text, string, "");
						}
						// remove ending white characters (done to avoid display issues in samsung TVs)
						text = StringTools.ltrim(text);
						// shorten description
						//text = text.substr(0, 95) + "...";
						cell.description = text;
						
						// take only the first item into account, as there can be multiple results for the search query
						break;
					}
				}
				// returns only first item in case there are multiple item returned form the search results
				return cell;
			}
		}
		// if no data has been found, return empty cell
		return cell;
	}
	
}
