#ifndef INCLUDED_neash_display_LoaderInfo
#define INCLUDED_neash_display_LoaderInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/net/URLLoader.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Loader)
HX_DECLARE_CLASS2(neash,display,LoaderInfo)
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


class LoaderInfo_obj : public ::neash::net::URLLoader_obj{
	public:
		typedef ::neash::net::URLLoader_obj super;
		typedef LoaderInfo_obj OBJ_;
		LoaderInfo_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< LoaderInfo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LoaderInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LoaderInfo"); }

		virtual ::neash::utils::ByteArray getBytes( );
		Dynamic getBytes_dyn();

		virtual Void onURLLoaded( ::neash::events::Event event);
		Dynamic onURLLoaded_dyn();

		virtual Void load( ::neash::net::URLRequest request);

		::String pendingURL; /* REM */ 
		int width; /* REM */ 
		::String url; /* REM */ 
		::neash::events::EventDispatcher sharedEvents; /* REM */ 
		bool sameDomain; /* REM */ 
		bool parentAllowsChild; /* REM */ 
		Dynamic parameters; /* REM */ 
		::String loaderURL; /* REM */ 
		::neash::display::Loader loader; /* REM */ 
		int height; /* REM */ 
		Float frameRate; /* REM */ 
		::String contentType; /* REM */ 
		::neash::display::DisplayObject content; /* REM */ 
		bool childAllowsParent; /* REM */ 
		::neash::utils::ByteArray bytes; /* REM */ 
		static ::neash::display::LoaderInfo create( ::neash::display::Loader ldr);
		static Dynamic create_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_LoaderInfo */ 
