Cocktail, an HTML/CSS rendering engine for the [Haxe](http://haxe.org/) language 
=============

* Cocktail is implementing the [W3C](http://www.w3.org/) HTML and CSS standards in Haxe.

* With Cocktail, write HTML/CSS applications in Haxe and build them for [NME](http://www.nme.io/) and flash/Air. As Cocktail uses the standard DOM API, you can also build your app to regular JavaScript.

* Use it by embedding it inside your app/game, like a webview, and create your UI in HTML/CSS.

Project home page
-------------

For tutorials, demos and community support :
http://www.silexlabs.org/haxe/cocktail/

See you there !

Interactive demo
-------------

If you want to try cocktail in your browser :
http://demos.silexlabs.org/trycocktail/

Requirements
-------------
Cocktail is a library for the Haxe programming language, you should be familiar with it to use Cocktail. Being familiar with NME (another Haxe library) can also help but is not required to use Cocktail.

Building
-------------

1. Cocktail is written for Haxe 3, you need to [download and install](http://haxe.org/download) it first:

2. Cocktail is available on [haxelib](http://haxe.org/haxelib), once Haxe is installed, open you command prompt and type:
> haxelib install cocktail

3. Optionnaly, if you also want to build for NME as well as flash/Air : 
> haxelib install nme

4. **You can build now !** Haxe uses .hxml files to build projects. You should start with the samples provided in the folder of the cocktail haxelib. Haxelibs are installed in the folder of your Haxe installation. Each sample has a build folder containing .hxml files. To build, open you command prompt and type : 
> haxe mybuildfile.hxml

 If you're on windows, you can just double-click the .hxml file instead.
5. If you've made it this far, you should check [the getting started tutorial !](http://www.silexlabs.org/haxe/cocktail/tutorials/getting-started-with-cocktail/) 

Maturity
-------------
This project has been used in production by core members of the project which could easily debug it. So it's getting stable but expect quirks, especially when using some tricky CSS layout. The API however, as it is based on the W3C standards is very stable.

Haxe 2
-------------
For Haxe 2 users, cocktail is also available on haxelib, although the Haxe 2 version won't be maintained.

Licence
-------------

Cocktail is open-source, released under the MIT licence, see licence.txt.
