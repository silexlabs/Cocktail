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
 * This class contains Rss utils for ThumbTextListStandard
 * 
 * @author Raphael Harmel
 */

import haxe.Firebug;
import js.Dom;
import js.Lib;
import org.intermedia.model.ApplicationModel;
import haxe.Timer;

class ThumbTextListRssStandard 
{
	/**
	 * Converts a rss to an Array of CellDatas
	 * 
	 * @param	rss
	 * @return
	 */
	public static function rss2Cells(rss:Xml,?listId:String = ""):Array<CellData>
	{
		// init cells Array
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
				var cell:CellData = { id:0, title:"", author:"", thumbUrl:"", category:"", description:"", content:""};
				
				// for each node
				for (itemParam in channelChild.elements())
				{
					// if node is a title
					if (itemParam.nodeName == "title")
					{
						// get and clean the node text
						var title:String = cleanText(itemParam.firstChild().nodeValue);
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
						// get and clean the node text
						cell.description = cleanText(itemParam.firstChild().nodeValue);
						
						// get the thumb image
						cell.thumbUrl = getThumb(cell.description);
						
					}
					
					// if node is a content
					if (itemParam.nodeName == "content:encoded")
					{
						// get and clean the node text
						cell.content = cleanText(itemParam.firstChild().nodeValue);
						
						// get the thumb image
						if(cell.thumbUrl == "") cell.thumbUrl = getThumb(cell.content);
					}
					
				}
				
				// if thumb url is empty, fill it with default image
				if (cell.thumbUrl == "")
				{
					// for silicon sentier feed, add thumb if missing
					if (listId == Feeds.FEED_2.url)
					{
						cell.thumbUrl = Feeds.FEED_2.thumb;
					}
				}
				
				// if the cell contains at least a title, a thumb and a either a description or a content
				if (cell.title != "" && cell.thumbUrl != ""  && ( cell.description != "" || cell.content != "" ) )
				{
					// add cell to cell array
					cells.push(cell);
				}
			}
		}

		return cells;
	}
	
	/**
	 * Cleans a text by converting html codes and html entities in it
	 * 
	 * @param	text	dirty string
	 * @return			cleaned string
	 */
	static private function cleanText(text:String):String
	{
		return(StringTools.htmlUnescape(cleanCharCodes(text)));
	}
	
	/**
	 * This method cleans a string by converting all character codes such as &#8217; (cf. http://www.ascii.cl/htmlcodes.htm)
	 * these are not html entities nor url encoding
	 * 
	 * @param	text	dirty string
	 * @return			cleaned string
	 */
	static public function cleanCharCodes(text:String):String
	{
		// init variables
		var charCodeStart:String = '&#';
		var charCodeEnd:String = ';';
		var charCodeStartPosition:Int = 0;
		var charCodeEndPosition:Int = 0;
		var charCode:Int = 0;
		var charCodeString:String = "";
		var char:String = "";
		var textEnd:String = "";
		
		// get the character code position
		charCodeStartPosition = text.indexOf(charCodeStart);
		
		// if character code has been found, start loop until ther are no more
		while (charCodeStartPosition != -1)
		{
			// retrieve the code
			charCodeString = text.substr(charCodeStartPosition + charCodeStart.length);
			charCodeEndPosition = charCodeString.indexOf(charCodeEnd);
			
			// keep the text string end
			textEnd = charCodeString.substr(charCodeEndPosition + 1);
			
			// continue retrieving the code
			charCodeString = charCodeString.substr(0, charCodeEndPosition);
			charCode = Std.parseInt(charCodeString);
			
			// convert the code
			char = String.fromCharCode(charCode);
			
			// build the new string
			text = text.substr(0, charCodeStartPosition) + char + textEnd;
			
			// get the next character code
			charCodeStartPosition = text.indexOf(charCodeStart);
		}
		
		// return the cleaned string
		return text;
		
		// Nicolas Cannasse's proposal to do it
		//~/&#([0-9A-Fa-f]+);/.customReplace(function(r) return String.fromCharCode(Std.parseInt("0x" + r.matched(1))));
		
		return text;
	}
	
	/**
	 * Gets the thumb, i.e. the first image in the html string
	 * 
	 * @param	htmlString
	 */
	static private function getThumb(htmlString:String):String
	{
		// get thumbnail from description
		var imgNodeStartIndex:Int = htmlString.indexOf("<img ");
		var imgNode:String = "";
		var imgUrl:String = "";
		var imgUrlStartIndex:Int = 0;
		
		// if img node name has been found
		if ( imgNodeStartIndex != -1)
		{
			// get img node content
			htmlString = htmlString.substr(imgNodeStartIndex);
			var imgNodeEndIndex:Int = htmlString.indexOf(">") + 1;
			imgNode = htmlString.substr(0, imgNodeEndIndex);
			
			// get image url
			var srcKeyWord:String = 'src=';
			imgUrlStartIndex = imgNode.indexOf(srcKeyWord);
			
			// if srcKeyWord string has been found
			if (imgUrlStartIndex != -1)
			{
				// get the delimitor
				var imgUrlDelimitor:String = imgNode.substr(imgUrlStartIndex + srcKeyWord.length, 1);
				
				// get the image url
				imgUrl = imgNode.substr(imgUrlStartIndex + srcKeyWord.length + 1);
				var imgUrlEndIndex:Int = imgUrl.indexOf(imgUrlDelimitor);
				imgUrl = imgUrl.substr(0, imgUrlEndIndex);
				
				return imgUrl;
			}
		}
		// workaround for silicon sentier feed: if no img field, get the thumb from description only
		else
		{
			imgUrlStartIndex = htmlString.indexOf("<p>http://");
			if ( imgUrlStartIndex != -1)
			{
				// get image url
				var srcKeyWord:String = '<p>';
				imgUrl = htmlString.substr(imgUrlStartIndex + srcKeyWord.length);
				var imgUrlEndIndex:Int = imgUrl.indexOf("</p>");
				imgUrl = imgUrl.substr(0, imgUrlEndIndex);
				
				return imgUrl;
			}
		}
		
		return "";
		
	}
	
}
