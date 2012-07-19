package cocktail;

/**
 * This class implements the glue that allows to make a Cocktail application out of a HTML file.
 * 
 * @author Thomas Fétiveau
 */
class HTMLBuilder
{
	/**
	 * The HTML source file.
	 */
	static var htmlSource:String;
	
	/**
	 * The main custom class if any.
	 */
	static var customClassName:Null<String>;
	
	/**
	 * Starts the Cocktail application.
	 */
	static public function main()
	{
		cocktail.Lib.document.documentElement.innerHTML = htmlSource;
		
		if (customClassName == null)
			return;
		
		var customClass = Type.resolveClass(customClassName);
		
		if (customClass != null)
		{
			Type.createInstance(customClass,[]);
		}
	}
	
	/**
	 * Creates a Cocktail application from an HTML file. 
	 * 
	 * @param	htmlSourcePath	The path to the application HTML source page. By default "./index.html".
	 */
	@:macro static public function create(?htmlSourcePath:String="index.html", ?mainClass:String=null) : Void
	{
		if (!sys.FileSystem.exists(htmlSourcePath))
			throw htmlSourcePath + " not found !";
		
		htmlSource = sys.io.File.getContent(htmlSourcePath);
		trace(htmlSource);
		customClassName = mainClass; 
	}
}