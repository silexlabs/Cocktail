/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.nativeElement;

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
	  * drawing type such as a Canvas in 
	  * HTML or a sprite (with a graphic
	  * object) in Flash
	  */
	 canvas;
	 
	 /**
	  * Image type such as an HTML img tag
	  */
	 img;
	 
	 /**
	  * Class library such as a script
	  * tag in HTML
	  */
	 script;
	 
	 /**
	  * http link type such as an <a> tag in
	  * HTML
	  */
	 anchor;
	 
	 /**
	  * an input where the user can type
	  * text
	  */
	 input;
	 
	 /**
	  * Can be any other type of native element.
	  * The name can be used for instance in HTML
	  * as a tag name
	  */
	 semantic(name:String);
 }
 
