#ifndef INCLUDED_nme_display_Loader
#define INCLUDED_nme_display_Loader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Loader)
HX_DECLARE_CLASS2(nme,display,LoaderInfo)
HX_DECLARE_CLASS2(nme,display,MovieClip)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,net,URLLoader)
HX_DECLARE_CLASS2(nme,net,URLRequest)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
namespace display{


class Loader_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef Loader_obj OBJ_;
		Loader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Loader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Loader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Loader"); }

		::nme::display::DisplayObject content; /* REM */ 
		::nme::display::LoaderInfo contentLoaderInfo; /* REM */ 
		::nme::display::BitmapData nmeImage; /* REM */ 
		::nme::display::MovieClip nmeSWF; /* REM */ 
		virtual bool doLoad( ::nme::utils::ByteArray inBytes);
		Dynamic doLoad_dyn();

		virtual Void load( ::nme::net::URLRequest request);
		Dynamic load_dyn();

		virtual Void loadBytes( ::nme::utils::ByteArray bytes);
		Dynamic loadBytes_dyn();

		virtual Void unload( );
		Dynamic unload_dyn();

		virtual Void onData( ::nme::events::Event event);
		Dynamic onData_dyn();

};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Loader */ 
