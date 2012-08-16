package domElement;

/**
 * ...
 * @author Raphael HARMEL
 */

 // DOM
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ImageDOMElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// utest
import utest.Assert;
import utest.Runner;
import utest.ui.Report;


class ImageDOMElementTests 
{

	// the main container which will be attached to the body of the publication
	private var _body:BodyDOMElement;
	private var _image:ImageDOMElement;
	
	private static inline var _x:Int = 180;
	private static inline var _y:Int = 500;
	private static inline var _width:Int = 114;
	private static inline var _height:Int = 115;
	private static inline var _newWidth:Int = 50;
	private static inline var _newHeight:Int = 50;
	
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new ImageDOMElementTests());
		Report.create(runner);
		runner.run();
	}
	
	/**
	 * Contructor
	 */
	public function new() 
	{
		_body = new BodyDOMElement();

		// image creation
		
		_image = new ImageDOMElement();
		_image.style.position = PositionStyleValue.absolute;
		//_image.style.position = PositionStyleValue.staticStyle;
		_image.style.top = PositionOffsetStyleValue.length(px(_x));
		_image.style.left = PositionOffsetStyleValue.length(px(_y));
		
		_body.addChild(_image);
	}
	
    public function test_IntrinsicSize() {
		
		var successCallback:Dynamic->Void = Assert.createEvent(onPictureLoadedTest);
		
		_image.onLoad = successCallback;
		_image.load("Assets/icon.png");
		
    }
	
	private function onPictureLoadedTest(data:Dynamic):Void
	{
		Assert.equals(_width, _image.intrinsicWidth);
		Assert.equals(_height, _image.intrinsicHeight);
	}
	
	public function test_Position()
	{
		Assert.same(PositionOffsetStyleValue.length(px(_x)), _image.style.top);
		Assert.same(PositionOffsetStyleValue.length(px(_y)), _image.style.left);
	}
	
	public function test_Resize()
	{
		_image.width = _newWidth;
		_image.height = _newHeight;
		
		Assert.equals(_newWidth, _image.width);
		Assert.equals(_newHeight, _image.height);
		Assert.same(DimensionStyleValue.length(px(_newWidth)), _image.style.width);
		Assert.same(DimensionStyleValue.length(px(_newHeight)), _image.style.height);
	}
	
}