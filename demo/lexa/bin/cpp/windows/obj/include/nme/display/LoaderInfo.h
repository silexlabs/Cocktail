#ifndef INCLUDED_nme_display_LoaderInfo
#define INCLUDED_nme_display_LoaderInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/net/URLLoader.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Loader)
HX_DECLARE_CLASS2(nme,display,LoaderInfo)
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


class LoaderInfo_obj : public ::nme::net::URLLoader_obj{
	public:
		typedef ::nme::net::URLLoader_obj super;
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
		::String __ToString() const { return HX_CSTRING("LoaderInfo"); }

		::nme::utils::ByteArray bytes; /* REM */ 
		bool childAllowsParent; /* REM */ 
		::nme::display::DisplayObject content; /* REM */ 
		::String contentType; /* REM */ 
		double frameRate; /* REM */ 
		int height; /* REM */ 
		::nme::display::Loader loader; /* REM */ 
		::String loaderURL; /* REM */ 
		Dynamic parameters; /* REM */ 
		bool parentAllowsChild; /* REM */ 
		bool sameDomain; /* REM */ 
		::nme::events::EventDispatcher sharedEvents; /* REM */ 
		::String url; /* REM */ 
		int width; /* REM */ 
		::String pendingURL; /* REM */ 
		virtual Void load( ::nme::net::URLRequest request);
		Dynamic load_dyn();

		virtual Void onURLLoaded( ::nme::events::Event event);
		Dynamic onURLLoaded_dyn();

		virtual ::nme::utils::ByteArray getBytes( );
		Dynamic getBytes_dyn();

		static ::nme::display::LoaderInfo create( ::nme::display::Loader ldr);
		static Dynamic create_dyn();

};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_LoaderInfo */ 
