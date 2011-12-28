/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.keyboard;

/**
 * This file contains keyboard related structures
 * and enums
 */

/**
 * Represents a keyboard key on a up/down event
 * and the state of the modifier keys then
 */ 
typedef KeyEventData = {
	
	/**
	 * an enum value of the key or unknown if 
	 * unlisted key
	 */
	var value:KeyboardKeyValue;
	
	/**
	 * the key code
	 */
	var code:Int;
	
	/**
	 * the key ascii code
	 */
	var ascii:Int;
	
	/**
	 * wether alt is pressed
	 */
	var altKey:Bool;
	
	/**
	 * wether ctrl is pressed
	 */
	var controlKey:Bool;
	
	/**
	 * wether shift is pressed
	 */
	var shiftKey:Bool;
}

/**
 * Lists all the keyboard's keys. Default to "unknow" for
 * non listed keys
 */
enum KeyboardKeyValue {
	unknown;
	a;
	b;
	c;
	d;
	e;
	f;
	g;
	h;
	i;
	j;
	k;
	l;
	m;
	n;
	o;
	p;
	q;
	r;
	s;
	t;
	u;
	v;
	w;
	x;
	y;
	z;
	backSpace;
	capsLock;
	control;
	del;
	down;
	end;
	escape;
	enter;
	F1;
	F2;
	F3;
	F4;
	F5;
	F6;
	F7;
	F8;
	F9;
	F10;
	F11;
	F12;
	F13;
	F14;
	F15;
	home;
	insert;
	left;
	numpad0;
	numpad1;
	numpad2;
	numpad3;
	numpad4;
	numpad5;
	numpad6;
	numpad7;
	numpad8;
	numpad9;
	numpadAdd;
	numpadSpecial;
	numpadDecimal;
	numpadDivide;
	numpadEnter;
	numpadMultiply;
	numpadSubstract;
	pageDown;
	pageUp;
	right;
	shift;
	space;
	tab;
	up;
}