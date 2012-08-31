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
 * This class contains Rss utils for CellDetailsRss
 * 
 * @author Raphael Harmel
 */

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
		{
			if (channelChild.nodeName == "item")
			{
				// for each node
				for (itemParam in channelChild.elements())
				{
					// if node is a post content (without html)
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
						
						// set cell.description
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
