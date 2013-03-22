#ifndef INCLUDED_neash_display_Loader
#define INCLUDED_neash_display_Loader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Loader)
HX_DECLARE_CLASS2(neash,display,LoaderInfo)
HX_DECLARE_CLASS2(neash,display,MovieClip)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,net,URLLoader)
HX_DECLARE_CLASS2(neash,net,URLRequest)
HX_DECLARE_CLASS2(neash,utils,ByteArray)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
namespace neash{
namespace display{


class Loader_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Loader"); }

		virtual Void onData( ::neash::events::Event event);
		Dynamic onData_dyn();

		virtual Void unload( );
		Dynamic unload_dyn();

		virtual Void loadBytes( ::neash::utils::ByteArray bytes);
		Dynamic loadBytes_dyn();

		virtual Void load( ::neash::net::URLRequest request);
		Dynamic load_dyn();

		virtual bool doLoad( ::neash::utils::ByteArray inBytes);
		Dynamic doLoad_dyn();

		::neash::display::MovieClip nmeSWF; /* REM */ 
		::neash::display::BitmapData nmeImage; /* REM */ 
		::neash::display::LoaderInfo contentLoaderInfo; /* REM */ 
		::neash::display::DisplayObject content; /* REM */ 
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Loader */ 
