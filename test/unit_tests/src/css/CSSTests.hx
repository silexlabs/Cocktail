/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package css;

import js.Lib;
import js.Dom;
//
//import utest.Assert;
//import utest.Runner;
//import utest.ui.Report;

class CSSTests 
{
	
	public static function main()
	{	
		//var runner = new Runner();
		//runner.addCase(new CSSTests());
		//Report.create(runner);
		//runner.run();
		
			
		new CSSTests();
	}
	
	public function new() 
	{
		var style:String = 'div[bam="boum"]{background-color:green; font-size:90px; position:fixed; bottom:30px; color:orange;}';
			style += ' input:focus {background-color:red;} :enabled{width:300px;} :link{color:aqua;} div.boum{ transition-duration:2s;  margin-left:100px; margin:10px; padding:50px; width:200px; height:300px; font-size:50px; position:absolute; right:20%; top:10px; font-weight:bold; background-color:red;}';
			
			style += ' div.boum:hover {background-color:green; width:300px;} div.boum:active {color:blue;}';
			
			Lib.document.documentElement.innerHTML = "<style>"+style+"</style><body><div id='stl' bam='boum' style='font-size:3em; width:500px;'><b>bold</b><i id='bim'>bim</i><input></input><a href='#'>Link</a></div><div id='bang'>bang</div><div class='boum'><div>aaa</div><div>boum</div></div></body>";
		
		var bang = Lib.document.getElementById("bang");
		bang.style.backgroundColor = "orange";
		var style = Lib.document.createElement("style");
		bang.onclick = function(e) { 
				
				//Lib.document.body.appendChild(style);
				bang.style.margin = "25px 35px";
				//style.appendChild(Lib.document.createTextNode(" b + i{font-style:normal; letter-spacing:20px;} i{position:absolute; width:200px; background-color:red; top:0;} div{font-family:times;} div#bang{text-transform:uppercase; font-weight:bold; margin-top:30px; height: 1500px; font-size:30px; color:red; width:5em; min-width:10em;}"));
			
			};
			
		var bim = Lib.document.getElementById("bim");
		
		var stl = Lib.document.getElementById("stl");
		
		
		bim.onclick  = function(e) {
			//Lib.document.body.removeChild(style);
			
			bang.style.marginTop = null;
		}
			
	}
	
}