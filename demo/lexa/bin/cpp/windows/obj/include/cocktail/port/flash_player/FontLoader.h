#ifndef INCLUDED_cocktail_port_flash_player_FontLoader
#define INCLUDED_cocktail_port_flash_player_FontLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/font/AbstractFontLoader.h>
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontLoader)
HX_DECLARE_CLASS3(cocktail,port,flash_player,FontLoader)
namespace cocktail{
namespace port{
namespace flash_player{


class FontLoader_obj : public ::cocktail::core::font::AbstractFontLoader_obj{
	public:
		typedef ::cocktail::core::font::AbstractFontLoader_obj super;
		typedef FontLoader_obj OBJ_;
		FontLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FontLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontLoader"); }

		virtual Void load( ::String url,::String name);
		Dynamic load_dyn();

		virtual Void _onLoadComplete( Dynamic data);
		Dynamic _onLoadComplete_dyn();

		virtual Void _onLoadError( Dynamic data);
		Dynamic _onLoadError_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_FontLoader */ 
