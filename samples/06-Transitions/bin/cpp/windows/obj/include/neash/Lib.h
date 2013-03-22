#ifndef INCLUDED_neash_Lib
#define INCLUDED_neash_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(neash,Lib)
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
namespace neash{


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
		static ::neash::display::MovieClip current; /* REM */ 
		static int initHeight; /* REM */ 
		static int initWidth; /* REM */ 
		static ::neash::display::Stage stage; /* REM */ 
		static ::neash::display::MovieClip nmeCurrent; /* REM */ 
		static Dynamic nmeMainFrame; /* REM */ 
		static ::neash::display::Stage nmeStage; /* REM */ 
		static bool sIsInit; /* REM */ 
		static ::String company; /* REM */ 
		static ::String version; /* REM */ 
		static ::String packageName; /* REM */ 
		static ::String file; /* REM */ 
		static Void close( );
		static Dynamic close_dyn();

		static Void create( Dynamic inOnLoaded,int inWidth,int inHeight,hx::Null< Float >  inFrameRate,hx::Null< int >  inColour,hx::Null< int >  inFlags,::String inTitle,::neash::display::BitmapData inIcon);
		static Dynamic create_dyn();

		static ::neash::display::ManagedStage createManagedStage( int inWidth,int inHeight,hx::Null< int >  inFlags);
		static Dynamic createManagedStage_dyn();

		static Void exit( );
		static Dynamic exit_dyn();

		static Void forceClose( );
		static Dynamic forceClose_dyn();

		static int getTimer( );
		static Dynamic getTimer_dyn();

		static Void getURL( ::neash::net::URLRequest url,::String target);
		static Dynamic getURL_dyn();

		static Void nmeSetCurrentStage( ::neash::display::Stage inStage);
		static Dynamic nmeSetCurrentStage_dyn();

		static Void pause( );
		static Dynamic pause_dyn();

		static Void postUICallback( Dynamic inCallback);
		static Dynamic postUICallback_dyn();

		static Void resume( );
		static Dynamic resume_dyn();

		static Void setIcon( ::String path);
		static Dynamic setIcon_dyn();

		static Void setPackage( ::String inCompany,::String inFile,::String inPack,::String inVersion);
		static Dynamic setPackage_dyn();

		static ::neash::display::MovieClip nmeGetCurrent( );
		static Dynamic nmeGetCurrent_dyn();

		static ::neash::display::Stage nmeGetStage( );
		static Dynamic nmeGetStage_dyn();

		static Dynamic nme_set_package; /* REM */ 
		static Dynamic &nme_set_package_dyn() { return nme_set_package;}
		static Dynamic nme_get_frame_stage; /* REM */ 
		static Dynamic &nme_get_frame_stage_dyn() { return nme_get_frame_stage;}
		static Dynamic nme_get_url; /* REM */ 
		static Dynamic &nme_get_url_dyn() { return nme_get_url;}
		static Dynamic nme_pause_animation; /* REM */ 
		static Dynamic &nme_pause_animation_dyn() { return nme_pause_animation;}
		static Dynamic nme_resume_animation; /* REM */ 
		static Dynamic &nme_resume_animation_dyn() { return nme_resume_animation;}
};

} // end namespace neash

#endif /* INCLUDED_neash_Lib */ 
