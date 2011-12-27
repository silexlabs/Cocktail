/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeElement;

import cocktail.nativeElement.NativeElement;

/**
 * This file contain structs and enums representing NativeElement data.
 * A native element is an abstraction of a native DOM element such as a 
 * div in HTML or a Sprite in Flash
 */

 /**
  * Lists the different type of 
  * native element which can be created.
  */
 enum NativeElementTypeValue {
	 
	 /**
	  * standard container type, such as 
	  * a div in HTML
	  */
	 neutral;
	 
	 /**
	  * drawing type such as a Canvas in 
	  * HTML or a sprite (with a graphic
	  * object) in Flash
	  */
	 graphic;
	 
	 /**
	  * text type such as an HTML TextElement
	  */
	 text;
	 
	 /**
	  * Image type such as an HTML img tag
	  */
	 image;
	 
	 /**
	  * Class library such as a script
	  * tag in HTML
	  */
	 library;
	 
	 /**
	  * Skin such as an HTML String in
	  * HTML
	  */
	 skin;
	 
	 /**
	  * Can be any other type of native element.
	  * The name can be used for instance in HTML
	  * as a tag name
	  */
	 custom(name:String);
 }
 
