#if !macro
import js.Lib;
#end

#if macro
import haxe.macro.Expr;
#end

/**
 * This class implements the glue that allows to make a Cocktail application out of a HTML file.
 * 
 * @author Thomas Fétiveau
 */
#if !macro @:build(Cocktail.build()) #end
class Cocktail
{
	/**
	 * The path to the HTML source file.
	 */
	static var htmlSourcePath:String="index.html";

	/**
	 * The HTML source file.
	 */
	static var htmlSource:String;

	@:macro static function getSourceHtmlSource():haxe.macro.Expr
	{
		if (htmlSource == null)
			return { expr : EConst(CString("index.html")), pos : haxe.macro.Context.currentPos() };

		return { expr : EConst(CString(htmlSource)), pos : haxe.macro.Context.currentPos() };
	}

	/**
	 * The main custom class if any.
	 */
	static var customClassName:Null<String>;

	@:macro static function getCustomClassName():haxe.macro.Expr
	{
		if ( customClassName == null )
			return { expr : EConst(CIdent("null")), pos : haxe.macro.Context.currentPos() };

		return { expr : EConst(CString(customClassName)), pos : haxe.macro.Context.currentPos() };
	}

	#if !macro

	/**
	 * Starts the Cocktail application.
	 */
	static public function main()
	{
		Lib.document.documentElement.innerHTML = getSourceHtmlSource();

		if (getCustomClassName() == null)
			return;

		var customClass = Type.resolveClass(getCustomClassName());

		if (customClass != null)
		{
			Type.createInstance(customClass,[]);
		}
	}

	#else

	/**
	 * Generate an import expression for a given class.
	 * 
	 * @param	full classname (with packages)
	 * @return	an import Expr
	 */
	static function generateImport(classname : String) : Expr
	{
		var splitedClassName = classname.split(".");
		var realClassName = splitedClassName.pop();

		if (splitedClassName.length > 0)
		{
			return { expr : EType( generateImportPackagePath(splitedClassName) , realClassName), pos : haxe.macro.Context.currentPos() };
		}
		return { expr : EConst(CType(classname)), pos : haxe.macro.Context.currentPos() };
	}

	/**
	 * Generates the package part of an import Expr.
	 * 
	 * @param	path
	 * @return	an part of an import Expr
	 */
	static function generateImportPackagePath(path : Array<String>) : Expr
	{
		if (path.length > 1)
		{
			var lastPathElt = path.pop();
			return { expr : EField( generateImportPackagePath(path), lastPathElt), pos : haxe.macro.Context.currentPos() };
		}
		return { expr : EConst(CIdent(path[0])), pos : haxe.macro.Context.currentPos() };
	}

	/**
	 * Read the HTML content and embeds it in the application.
	 */
	static public function build():Array<haxe.macro.Field>
	{
		var fs = haxe.macro.Context.getBuildFields();

		if (!sys.FileSystem.exists(htmlSourcePath))
			throw "You must create a "+htmlSourcePath+" file.";

		htmlSource = sys.io.File.getContent(htmlSourcePath);

		if (customClassName == null)
			return fs;

		for (fc in 0...fs.length)
		{
			switch (fs[fc].kind)
			{
				case FFun(f) :

					switch (f.expr.expr)
					{
						case EBlock(exprs):

							if (fs[fc].name == "main")
								exprs.insert(0,generateImport(customClassName));

						default:
					}
				default:
			}
		}

		return fs;
	}

	/**
	 * Creates a Cocktail application from an HTML file. 
	 * 
	 * @param	htmlSourcePath	The path to the application HTML source page. By default "./index.html".
	 */
	@:macro static public function create(?htmlFileSourcePath:String="index.html", ?mainClass:String=null) : Void
	{
		htmlSourcePath = htmlFileSourcePath;

		customClassName = mainClass;
	}

	#end
}