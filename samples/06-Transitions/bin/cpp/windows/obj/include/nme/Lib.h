#ifndef INCLUDED_nme_Lib
#define INCLUDED_nme_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,ManagedStage)
HX_DECLARE_CLASS2(neash,display,MovieClip)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,net,URLRequest)
HX_DECLARE_CLASS1(nme,Lib)
namespace nme{


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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Lib"); }

		static int FULLSCREEN; /* REM */ 
		static int BORDERLESS; /* REM */ 
		static int RESIZABLE; /* REM */ 
		static int HARDWARE; /* REM */ 
		static int VSYNC; /* REM */ 
		static int HW_AA; /* REM */ 
		static int HW_AA_HIRES; /* REM */ 
		static int ALLOW_SHADERS; /* REM */ 
		static ::String company; /* REM */ 
		static ::neash::display::MovieClip current; /* REM */ 
		static ::String file; /* REM */ 
		static int initHeight; /* REM */ 
		static int initWidth; /* REM */ 
		static ::String packageName; /* REM */ 
		static ::neash::display::Stage stage; /* REM */ 
		static ::String version; /* REM */ 
		static Void close( );
		static Dynamic close_dyn();

		static Void create( Dynamic onLoaded,int width,int height,hx::Null< Float >  frameRate,hx::Null< int >  color,hx::Null< int >  flags,::String title,::neash::display::BitmapData icon);
		static Dynamic create_dyn();

		static ::neash::display::ManagedStage createManagedStage( int width,int height);
		static Dynamic createManagedStage_dyn();

		static Void exit( );
		static Dynamic exit_dyn();

		static Void forceClose( );
		static Dynamic forceClose_dyn();

		static int getTimer( );
		static Dynamic getTimer_dyn();

		static Void getURL( ::neash::net::URLRequest url,::String target);
		static Dynamic getURL_dyn();

		static Void pause( );
		static Dynamic pause_dyn();

		static Void postUICallback( Dynamic handler);
		static Dynamic postUICallback_dyn();

		static Void resume( );
		static Dynamic resume_dyn();

		static Void setPackage( ::String company,::String file,::String packageName,::String version);
		static Dynamic setPackage_dyn();

		static Void trace( Dynamic arg);
		static Dynamic trace_dyn();

		static ::String nmeGetCompany( );
		static Dynamic nmeGetCompany_dyn();

		static ::neash::display::MovieClip nmeGetCurrent( );
		static Dynamic nmeGetCurrent_dyn();

		static ::String nmeGetFile( );
		static Dynamic nmeGetFile_dyn();

		static int nmeGetInitHeight( );
		static Dynamic nmeGetInitHeight_dyn();

		static int nmeGetInitWidth( );
		static Dynamic nmeGetInitWidth_dyn();

		static ::String nmeGetPackageName( );
		static Dynamic nmeGetPackageName_dyn();

		static ::neash::display::Stage nmeGetStage( );
		static Dynamic nmeGetStage_dyn();

		static ::String nmeGetVersion( );
		static Dynamic nmeGetVersion_dyn();

};

} // end namespace nme

#endif /* INCLUDED_nme_Lib */ 
