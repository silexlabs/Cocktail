#ifndef INCLUDED_cocktail_Lib
#define INCLUDED_cocktail_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(cocktail,Lib)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,window,AbstractWindow)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Window)
namespace cocktail{


class Lib_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lib_obj OBJ_;
		Lib_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Lib_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Lib_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Lib"); }

		static ::cocktail::port::flash_player::HTMLDocument _document; /* REM */ 
		static ::cocktail::port::flash_player::HTMLDocument document; /* REM */ 
		static ::cocktail::port::flash_player::Window _window; /* REM */ 
		static ::cocktail::port::flash_player::Window window; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static ::cocktail::port::flash_player::HTMLDocument get_document( );
		static Dynamic get_document_dyn();

		static ::cocktail::port::flash_player::Window get_window( );
		static Dynamic get_window_dyn();

};

} // end namespace cocktail

#endif /* INCLUDED_cocktail_Lib */ 
