#Cocktail SWC

This tool builds a [SWC file](http://en.wikipedia.org/wiki/Adobe_SWC_file) containing the cocktail's code base.
With this SWC, you can use cocktail from a pure ActionScript 3 project.

##Build

To build the SWC, you need Haxe 3. To build, run : 
 > haxe build.hxml
 
This creates the SWC in the bin folder.

##Use in ActionScript Project

Link the resulting SWC file into your ActionScript project. Instructions for FlashDevelop: 
Put the resulting cocktail.swc into your FlashDevelop-AS3-Projects /lib directory and check
the “Add to library” option in FD.

Your code needs to import the CocktailView class:

```as3
import cocktail.api.CocktailView;
```

The steps to get it running are pretty much as described elsewhere. You need
to init haxe (to be on the safe side, wait first for the stage to be initialised).
Then you need to initialize cocktail.
Just keep in mind, that haxe properties must be accessed as functions from ActionScript.
So the property “cv.viewport” becomes “cv.get_viewport” or “cv.set_viewport” alternatively.


```as3
public class Main extends Sprite 
{
		private var cv:CocktailView;
		public function Main():void 
		{
			if (stage) init();
				else addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event = null):void 
		{
			removeEventListener(Event.ADDED_TO_STAGE, init);
			
			
			// setup stage
			
			stage.scaleMode = "noScale";
			stage.align = "TL";
			stage.addEventListener(Event.RESIZE, resize );
			
			
			// init Haxe
			
			var mc:MovieClip = new MovieClip();
			addChild(mc);
			haxe.initSwc(mc);
			
			
			// init Cocktail
			
			cv = new CocktailView();
			
			cv.viewport = { x:100, y:100, width: 500, height: 500 };
			cv.initPlatform();
			
			cv.loadURL("index.html");
			
			// callback, when document ready
			cv.window.set_onload( domReady );
			
			//attach cocktail root to native flash root
			addChild( cv.root as DisplayObject );
			
		}
		
		// executed on document ready
		private function domReady(e:UIEvent):void {
			// you have access to the DOM now
			var document:HTMLDocument = cv.document;
			var button:HTMLElement = document.getElementById("button");
		}
		
		private function resize(e:Event):void {
			var o:Object = cv.viewport;
			o.width = stage.stageWidth - 200;
			o.height = stage.stageHeight - 200;
			cv.set_viewport(o);
		}
}
```
