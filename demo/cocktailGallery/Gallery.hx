/**
 * ...
 * @author Thomas Fétiveau
 */

import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import haxe.Http;
//import cocktail.domElement.abstract.AbstractDOMElement;
//import cocktail.domElement.DOMElementData;
import cocktail.resource.ResourceLoaderManager;
import cocktail.nativeElement.NativeElementManager;
import cocktail.mouse.MouseData;
import cocktail.unit.UnitData;

import cocktail.style.StyleData;
 
class Gallery 
{
	private static var rootDOMElement:ContainerDOMElement;
	
	private var stageHeight:Int;
	private var stageWidth:Int;
	
	private var currentMainImage:ImageDOMElement;
	
	private var currentAlbumUrl:String;
	
	private var picturesElements:Array<ImageDOMElement>;
	
	public function new() 
	{
		getDefaultStyle(rootDOMElement);
		
		// keep the stage width and height in variables as there is no possibility to get it dynamically through cocktail yet
		stageWidth = 640;
		stageHeight = 480;
		
		// 1 lecture de sources
		// TODO plusieurs albums
		//http://api.flickr.com/services/feeds/photoset.gne?set=350266&nsid=23548413@N00&lang=fr-fr
		if (currentAlbumUrl == null)
		{
			//currentAlbumUrl = "http://api.flickr.com/services/feeds/photos_public.gne?id=24662369@N07&lang=fr-fr&format=rss_200";
			currentAlbumUrl = "http://api.flickr.com/services/feeds/photos_public.gne?lang=fr-fr&format=rss_200";
			picturesElements = new Array();
		}
		//trace("loading "+currentAlbumUrl);
		loadGallery(currentAlbumUrl);
	}
	
	private function loadGallery(rssFeedUrl:String)
	{
		ResourceLoaderManager.loadString( "GalleryRssProxy.php?url="+StringTools.urlEncode(rssFeedUrl), onRssFeedLoaded, onRssFeedError);
	}
	
	private function onRssFeedError( msg : String )
	{
		//trace("Error while loading RSS feed : "+msg);
	}
	
	private function onRssFeedLoaded(response:String)
	{
		//trace("onRssFeedLoaded called ");
		var galleryXml:Xml =  Xml.parse(response);
		
		var channelNode:Xml = galleryXml.firstElement().firstElement();
		
		// 2 listage du contenu 
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				for (entryElement in channelChild.elements())
				{
					if (entryElement.nodeName == "media:content")
					{
						//trace("load picture");
						//ResourceLoaderManager.loadImage(entryElement.get("url"), onPictureLoaded, function(err){});
						var imageDOMElement:ImageDOMElement = new ImageDOMElement();
						//imageDOMElement.onLoad = onPictureLoaded;
						imageDOMElement.load(entryElement.get("url"));
						onPictureLoaded(imageDOMElement);
					}
				}
			}
		}
	}
	
	private function onPictureLoaded(imageDOMElement:ImageDOMElement):Void
	{
		//trace("onPictureLoaded called");
		getDefaultStyle(imageDOMElement);
		imageDOMElement.width = 80;
		imageDOMElement.height = 80;
		imageDOMElement.x = 5 + picturesElements.length * 85;
		imageDOMElement.y = stageHeight - 85;
		imageDOMElement.style.position = PositionStyleValue.absolute;
		imageDOMElement.style.width = DimensionStyleValue.length(px(81));
		imageDOMElement.style.height = DimensionStyleValue.length(px(54));
		rootDOMElement.addChild(imageDOMElement);
		
		//ImageDOMElement.onMouseUp = displayPicture;
		
		var displayPictureDelegate = displayPicture;
		imageDOMElement.onMouseUp = function(event) {
			displayPictureDelegate(imageDOMElement);
		}
		
		picturesElements.push(imageDOMElement);
	}
	
	private function displayPicture(imageDOMElement:ImageDOMElement)
	{
		if (currentMainImage == null)
		{
			//trace("new currentMainImage initialized");
			currentMainImage = new ImageDOMElement();
		}
		//ResourceLoaderManager.loadImage(imageDOMElement.src, onMainPictureLoaded, function(err){}, currentMainImage);
		//var image:ImageDOMElement = new ImageDOMElement();
		//currentMainImage.onLoad = onMainPictureLoaded;
		
		currentMainImage.style.width = DimensionStyleValue.length(px(300));
		currentMainImage.style.height = DimensionStyleValue.length(px(240));
		currentMainImage.width = 300;
		currentMainImage.height = 240;
		currentMainImage.load(imageDOMElement.src);
		onMainPictureLoaded(imageDOMElement);
	}
	
	private function onMainPictureLoaded(imageDOMElement:ImageDOMElement)
	//private function onMainPictureLoaded()
	{
		getDefaultStyle(currentMainImage);
		currentMainImage.style.position = PositionStyleValue.absolute;
		
		//trace("is currentMainImage null ? "+(currentMainImage==null));
		currentMainImage.x = 5;
		currentMainImage.y = 5;
		//currentMainImage.width = stageWidth - 10;
		//currentMainImage.height = stageHeight - 15 - 80;
		//currentMainImage.scaleX = 1;
		//currentMainImage.scaleX = (stageHeight - 15 - 80) / currentMainImage.height ;
		//currentMainImage.scaleY = currentMainImage.scaleX;


		rootDOMElement.addChild(currentMainImage);
	}
	
	private function getDefaultStyle(domElement:DOMElement):Void
	{
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));

		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));

		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
		domElement.style.right = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom  = PositionOffsetStyleValue.length(px(0));

		domElement.style.minWidth = ConstrainedDimensionStyleValue.none;
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.none;
		domElement.style.minHeight = ConstrainedDimensionStyleValue.none;
		domElement.style.maxHeight = ConstrainedDimensionStyleValue.none;

		domElement.style.fontSize = FontSizeStyleValue.length(px(12));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.normal;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily = [FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)];
		domElement.style.fontVariant = FontVariantStyleValue.normal;
		domElement.style.textTransform = TextTransformStyleValue.none;
		domElement.style.letterSpacing = LetterSpacingStyleValue.normal;
		domElement.style.wordSpacing = WordSpacingStyleValue.normal;
		domElement.style.textIndent = TextIndentStyleValue.length(px(0));
		domElement.style.whiteSpace = WhiteSpaceStyleValue.normal;
		domElement.style.textAlign = TextAlignStyleValue.left;

		domElement.style.verticalAlign = VerticalAlignStyleValue.baseline;

		domElement.style.color = ColorValue.keyword(ColorKeywordValue.black);

		domElement.style.display = block;

		domElement.style.position = staticStyle;

		domElement.style.width = DimensionStyleValue.auto;
		domElement.style.height = DimensionStyleValue.auto;

		domElement.style.float = FloatStyleValue.none;
		domElement.style.clear = ClearStyleValue.none;
	}
	
	static function main()
	{
		//create the root DOM Element of the gallery
		//the getRoot method returns the root of the current runtime (Stage for flash, body for js)
		rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		
		//rootDOMElement.style.layout
		// instanciate the gallery
		new Gallery();
	}
	
}