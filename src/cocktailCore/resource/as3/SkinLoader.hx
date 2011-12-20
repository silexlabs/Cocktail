/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.as3;

import cocktail.nativeElement.NativeElement;
import cocktailCore.resource.abstract.AbstractSkinLoader;
import flash.display.Loader;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.net.URLRequest;
import flash.system.ApplicationDomain;
import flash.system.LoaderContext;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Skin loader implementation for the Flash runtime. It is used to 
 * load complex object, such as a .swf file.
 * 
 * @author Yannick DOMINGUEZ
 */
class SkinLoader extends AbstractSkinLoader
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
}