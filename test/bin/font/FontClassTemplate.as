package  
{
	import flash.display.Sprite;
	import flash.text.Font;

	/**
	 * @author Martin Raedlinger (mr@formatlos.de)
	 */
	public class %className extends Sprite 
	{

		[Embed(source="%source", fontName="%fontName", fontWeight="%fontWeight", fontStyle="%fontStyle", mimeType="%mimeType", unicodeRange="%unicodeRange")]
		private static var _fontClass : Class;

		public function %className() 
		{
			super();
			Font.registerFont(_fontClass);
		}
	}
}


