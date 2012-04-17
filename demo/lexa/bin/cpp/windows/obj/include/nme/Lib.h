#ifndef INCLUDED_nme_Lib
#define INCLUDED_nme_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nme,Lib)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,ManagedStage)
HX_DECLARE_CLASS2(nme,display,MovieClip)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,net,URLRequest)
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
		::String __ToString() const { return HX_CSTRING("Lib"); }

		static int FULLSCREEN; /* REM */ 
		static int BORDERLESS; /* REM */ 
		static int RESIZABLE; /* REM */ 
		static int HARDWARE; /* REM */ 
		static int VSYNC; /* REM */ 
		static int HW_AA; /* REM */ 
		static int HW_AA_HIRES; /* REM */ 
		static ::nme::display::MovieClip current; /* REM */ 
		static int initHeight; /* REM */ 
		static int initWidth; /* REM */ 
		static ::nme::display::Stage stage; /* REM */ 
		static ::nme::display::MovieClip nmeCurrent; /* REM */ 
		static Dynamic nmeMainFrame; /* REM */ 
		static ::nme::display::Stage nmeStage; /* REM */ 
		static bool sIsInit; /* REM */ 
		static ::String company; /* REM */ 
		static ::String version; /* REM */ 
		static ::String packageName; /* REM */ 
		static ::String file; /* REM */ 
		static Void close( );
		static Dynamic close_dyn();

		static Void create( Dynamic inOnLoaded,int inWidth,int inHeight,Dynamic inFrameRate,Dynamic inColour,Dynamic inFlags,Dynamic inTitle,::nme::display::BitmapData inIcon);
		static Dynamic create_dyn();

		static ::nme::display::ManagedStage createManagedStage( int inWidth,int inHeight);
		static Dynamic createManagedStage_dyn();

		static Void exit( );
		static Dynamic exit_dyn();

		static Void forceClose( );
		static Dynamic forceClose_dyn();

		static int getTimer( );
		static Dynamic getTimer_dyn();

		static Void getURL( ::nme::net::URLRequest url,::String target);
		static Dynamic getURL_dyn();

		static Void nmeSetCurrentStage( ::nme::display::Stage inStage);
		static Dynamic nmeSetCurrentStage_dyn();

		static Void postUICallback( Dynamic inCallback);
		static Dynamic postUICallback_dyn();

		static Void setIcon( ::String path);
		static Dynamic setIcon_dyn();

		static Void setPackage( ::String inCompany,::String inFile,::String inPack,::String inVersion);
		static Dynamic setPackage_dyn();

		static ::nme::display::MovieClip nmeGetCurrent( );
		static Dynamic nmeGetCurrent_dyn();

		static ::nme::display::Stage nmeGetStage( );
		static Dynamic nmeGetStage_dyn();

		static Dynamic nme_set_package; /* REM */ 
	Dynamic &nme_set_package_dyn() { return nme_set_package;}
		static Dynamic nme_get_frame_stage; /* REM */ 
	Dynamic &nme_get_frame_stage_dyn() { return nme_get_frame_stage;}
		static Dynamic nme_get_url; /* REM */ 
	Dynamic &nme_get_url_dyn() { return nme_get_url;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Lib */ 
