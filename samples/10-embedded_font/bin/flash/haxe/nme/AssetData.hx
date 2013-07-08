package nme;


import nme.Assets;


class AssetData {

	
	public static var className = new #if haxe3 Map <String, #else Hash <#end Dynamic> ();
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			className.set ("index.html", nme.NME_index_html);
			type.set ("index.html", Reflect.field (AssetType, "text".toUpperCase ()));
			className.set ("assets/KatamotzIkasi.ttf", nme.NME_assets_katamotzikasi_ttf);
			type.set ("assets/KatamotzIkasi.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}


class NME_index_html extends nme.utils.ByteArray { }
class NME_assets_katamotzikasi_ttf extends nme.text.Font { }
