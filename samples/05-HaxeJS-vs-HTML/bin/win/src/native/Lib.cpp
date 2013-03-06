#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
#endif
#ifndef INCLUDED_native_Loader
#include <native/Loader.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_ManagedStage
#include <native/display/ManagedStage.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
#endif
namespace native{

Void Lib_obj::__construct()
{
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

int Lib_obj::FULLSCREEN;

int Lib_obj::BORDERLESS;

int Lib_obj::RESIZABLE;

int Lib_obj::HARDWARE;

int Lib_obj::VSYNC;

int Lib_obj::HW_AA;

int Lib_obj::HW_AA_HIRES;

int Lib_obj::ALLOW_SHADERS;

int Lib_obj::REQUIRE_SHADERS;

int Lib_obj::DEPTH_BUFFER;

int Lib_obj::STENCIL_BUFFER;

::native::display::MovieClip Lib_obj::current;

int Lib_obj::initHeight;

int Lib_obj::initWidth;

::native::display::Stage Lib_obj::stage;

::native::display::MovieClip Lib_obj::nmeCurrent;

Dynamic Lib_obj::nmeMainFrame;

::native::display::Stage Lib_obj::nmeStage;

bool Lib_obj::sIsInit;

::String Lib_obj::company;

::String Lib_obj::version;

::String Lib_obj::packageName;

::String Lib_obj::file;

Void Lib_obj::close( ){
{
		HX_STACK_PUSH("Lib::close","native/Lib.hx",52);
		HX_STACK_LINE(54)
		Dynamic close = ::native::Loader_obj::load(HX_CSTRING("nme_close"),(int)0);		HX_STACK_VAR(close,"close");
		HX_STACK_LINE(55)
		close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,close,(void))

Void Lib_obj::create( Dynamic inOnLoaded,int inWidth,int inHeight,hx::Null< Float >  __o_inFrameRate,hx::Null< int >  __o_inColour,hx::Null< int >  __o_inFlags,::String __o_inTitle,::native::display::BitmapData inIcon){
Float inFrameRate = __o_inFrameRate.Default(60.0);
int inColour = __o_inColour.Default(16777215);
int inFlags = __o_inFlags.Default(15);
::String inTitle = __o_inTitle.Default(HX_CSTRING("NME"));
	HX_STACK_PUSH("Lib::create","native/Lib.hx",60);
	HX_STACK_ARG(inOnLoaded,"inOnLoaded");
	HX_STACK_ARG(inWidth,"inWidth");
	HX_STACK_ARG(inHeight,"inHeight");
	HX_STACK_ARG(inFrameRate,"inFrameRate");
	HX_STACK_ARG(inColour,"inColour");
	HX_STACK_ARG(inFlags,"inFlags");
	HX_STACK_ARG(inTitle,"inTitle");
	HX_STACK_ARG(inIcon,"inIcon");
{
		HX_STACK_LINE(60)
		Array< int > inColour1 = Array_obj< int >::__new().Add(inColour);		HX_STACK_VAR(inColour1,"inColour1");
		HX_STACK_LINE(60)
		Array< Float > inFrameRate1 = Array_obj< Float >::__new().Add(inFrameRate);		HX_STACK_VAR(inFrameRate1,"inFrameRate1");
		HX_STACK_LINE(60)
		Array< int > inHeight1 = Array_obj< int >::__new().Add(inHeight);		HX_STACK_VAR(inHeight1,"inHeight1");
		HX_STACK_LINE(60)
		Array< int > inWidth1 = Array_obj< int >::__new().Add(inWidth);		HX_STACK_VAR(inWidth1,"inWidth1");
		HX_STACK_LINE(60)
		Dynamic inOnLoaded1 = Dynamic( Array_obj<Dynamic>::__new().Add(inOnLoaded));		HX_STACK_VAR(inOnLoaded1,"inOnLoaded1");
		HX_STACK_LINE(62)
		if ((::native::Lib_obj::sIsInit)){
			HX_STACK_LINE(62)
			hx::Throw (HX_CSTRING("nme.Lib.create called multiple times. This function is automatically called by the project code."));
		}
		HX_STACK_LINE(68)
		::native::Lib_obj::sIsInit = true;
		HX_STACK_LINE(69)
		::native::Lib_obj::initWidth = inWidth1->__get((int)0);
		HX_STACK_LINE(70)
		::native::Lib_obj::initHeight = inHeight1->__get((int)0);
		HX_STACK_LINE(72)
		Dynamic create_main_frame = ::native::Loader_obj::load(HX_CSTRING("nme_create_main_frame"),(int)-1);		HX_STACK_VAR(create_main_frame,"create_main_frame");

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Dynamic,inOnLoaded1,Array< int >,inHeight1,Array< int >,inColour1,Array< int >,inWidth1,Array< Float >,inFrameRate1)
		Void run(Dynamic inFrameHandle){
			HX_STACK_PUSH("*::_Function_1_1","native/Lib.hx",74);
			HX_STACK_ARG(inFrameHandle,"inFrameHandle");
			{
				HX_STACK_LINE(77)
				::native::Lib_obj::nmeMainFrame = inFrameHandle;
				HX_STACK_LINE(78)
				Dynamic stage_handle = ::native::Lib_obj::nme_get_frame_stage(::native::Lib_obj::nmeMainFrame);		HX_STACK_VAR(stage_handle,"stage_handle");
				HX_STACK_LINE(80)
				::native::Lib_obj::nmeStage = ::native::display::Stage_obj::__new(stage_handle,inWidth1->__get((int)0),inHeight1->__get((int)0));
				HX_STACK_LINE(81)
				::native::Lib_obj::nmeStage->set_frameRate(inFrameRate1->__get((int)0));
				HX_STACK_LINE(82)
				::native::Lib_obj::nmeStage->set_opaqueBackground(inColour1->__get((int)0));
				HX_STACK_LINE(83)
				::native::Lib_obj::nmeStage->onQuit = ::native::Lib_obj::close_dyn();
				HX_STACK_LINE(85)
				if (((::native::Lib_obj::nmeCurrent != null()))){
					HX_STACK_LINE(86)
					::native::Lib_obj::nmeStage->addChild(::native::Lib_obj::nmeCurrent);
				}
				HX_STACK_LINE(88)
				inOnLoaded1->__GetItem((int)0)().Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(74)
		create_main_frame( Dynamic(new _Function_1_1(inOnLoaded1,inHeight1,inColour1,inWidth1,inFrameRate1)),inWidth1->__get((int)0),inHeight1->__get((int)0),inFlags,inTitle,(  (((inIcon == null()))) ? Dynamic(null()) : Dynamic(inIcon->nmeHandle) ));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Lib_obj,create,(void))

::native::display::ManagedStage Lib_obj::createManagedStage( int inWidth,int inHeight,hx::Null< int >  __o_inFlags){
int inFlags = __o_inFlags.Default(0);
	HX_STACK_PUSH("Lib::createManagedStage","native/Lib.hx",97);
	HX_STACK_ARG(inWidth,"inWidth");
	HX_STACK_ARG(inHeight,"inHeight");
	HX_STACK_ARG(inFlags,"inFlags");
{
		HX_STACK_LINE(99)
		::native::Lib_obj::initWidth = inWidth;
		HX_STACK_LINE(100)
		::native::Lib_obj::initHeight = inHeight;
		HX_STACK_LINE(102)
		::native::display::ManagedStage result = ::native::display::ManagedStage_obj::__new(inWidth,inHeight,inFlags);		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(103)
		::native::Lib_obj::nmeStage = result;
		HX_STACK_LINE(105)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,createManagedStage,return )

Void Lib_obj::exit( ){
{
		HX_STACK_PUSH("Lib::exit","native/Lib.hx",110);
		HX_STACK_LINE(112)
		Dynamic quit = ::native::Lib_obj::get_stage()->onQuit_dyn();		HX_STACK_VAR(quit,"quit");
		HX_STACK_LINE(114)
		if (((quit != null()))){
			HX_STACK_LINE(114)
			quit().Cast< Void >();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,exit,(void))

Void Lib_obj::forceClose( ){
{
		HX_STACK_PUSH("Lib::forceClose","native/Lib.hx",131);
		HX_STACK_LINE(134)
		Dynamic terminate = ::native::Loader_obj::load(HX_CSTRING("nme_terminate"),(int)0);		HX_STACK_VAR(terminate,"terminate");
		HX_STACK_LINE(135)
		terminate();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,forceClose,(void))

int Lib_obj::getTimer( ){
	HX_STACK_PUSH("Lib::getTimer","native/Lib.hx",140);
	HX_STACK_LINE(140)
	return ::Std_obj::_int((::haxe::Timer_obj::stamp() * 1000.0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,getTimer,return )

Void Lib_obj::getURL( ::native::net::URLRequest url,::String target){
{
		HX_STACK_PUSH("Lib::getURL","native/Lib.hx",148);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(148)
		::native::Lib_obj::nme_get_url(url->url);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,getURL,(void))

Void Lib_obj::nmeSetCurrentStage( ::native::display::Stage inStage){
{
		HX_STACK_PUSH("Lib::nmeSetCurrentStage","native/Lib.hx",155);
		HX_STACK_ARG(inStage,"inStage");
		HX_STACK_LINE(155)
		::native::Lib_obj::nmeStage = inStage;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,nmeSetCurrentStage,(void))

Void Lib_obj::pause( ){
{
		HX_STACK_PUSH("Lib::pause","native/Lib.hx",162);
		HX_STACK_LINE(162)
		::native::Lib_obj::nme_pause_animation();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,pause,(void))

Void Lib_obj::postUICallback( Dynamic inCallback){
{
		HX_STACK_PUSH("Lib::postUICallback","native/Lib.hx",169);
		HX_STACK_ARG(inCallback,"inCallback");
		HX_STACK_LINE(169)
		inCallback().Cast< Void >();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,postUICallback,(void))

Void Lib_obj::resume( ){
{
		HX_STACK_PUSH("Lib::resume","native/Lib.hx",182);
		HX_STACK_LINE(182)
		::native::Lib_obj::nme_resume_animation();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,resume,(void))

Void Lib_obj::setIcon( ::String path){
{
		HX_STACK_PUSH("Lib::setIcon","native/Lib.hx",197);
		HX_STACK_ARG(path,"path");
		HX_STACK_LINE(200)
		Dynamic set_icon = ::native::Loader_obj::load(HX_CSTRING("nme_set_icon"),(int)1);		HX_STACK_VAR(set_icon,"set_icon");
		HX_STACK_LINE(201)
		set_icon(path);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,setIcon,(void))

Void Lib_obj::setPackage( ::String inCompany,::String inFile,::String inPack,::String inVersion){
{
		HX_STACK_PUSH("Lib::setPackage","native/Lib.hx",206);
		HX_STACK_ARG(inCompany,"inCompany");
		HX_STACK_ARG(inFile,"inFile");
		HX_STACK_ARG(inPack,"inPack");
		HX_STACK_ARG(inVersion,"inVersion");
		HX_STACK_LINE(208)
		::native::Lib_obj::company = inCompany;
		HX_STACK_LINE(209)
		::native::Lib_obj::file = inFile;
		HX_STACK_LINE(210)
		::native::Lib_obj::packageName = inPack;
		HX_STACK_LINE(211)
		::native::Lib_obj::version = inVersion;
		HX_STACK_LINE(213)
		::native::Lib_obj::nme_set_package(inCompany,inFile,inPack,inVersion);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Lib_obj,setPackage,(void))

::native::display::MovieClip Lib_obj::get_current( ){
	HX_STACK_PUSH("Lib::get_current","native/Lib.hx",225);
	HX_STACK_LINE(227)
	if (((::native::Lib_obj::nmeCurrent == null()))){
		HX_STACK_LINE(229)
		::native::Lib_obj::nmeCurrent = ::native::display::MovieClip_obj::__new();
		HX_STACK_LINE(231)
		if (((::native::Lib_obj::nmeStage != null()))){
			HX_STACK_LINE(232)
			::native::Lib_obj::nmeStage->addChild(::native::Lib_obj::nmeCurrent);
		}
	}
	HX_STACK_LINE(236)
	return ::native::Lib_obj::nmeCurrent;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,get_current,return )

::native::display::Stage Lib_obj::get_stage( ){
	HX_STACK_PUSH("Lib::get_stage","native/Lib.hx",241);
	HX_STACK_LINE(243)
	if (((::native::Lib_obj::nmeStage == null()))){
		HX_STACK_LINE(244)
		hx::Throw (HX_CSTRING("Error : stage can't be accessed until init is called"));
	}
	HX_STACK_LINE(246)
	return ::native::Lib_obj::nmeStage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,get_stage,return )

Dynamic Lib_obj::nme_set_package;

Dynamic Lib_obj::nme_get_frame_stage;

Dynamic Lib_obj::nme_get_url;

Dynamic Lib_obj::nme_pause_animation;

Dynamic Lib_obj::nme_resume_animation;


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lib);
	HX_MARK_END_CLASS();
}

void Lib_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Lib_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return file; }
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { return VSYNC; }
		if (HX_FIELD_EQ(inName,"HW_AA") ) { return HW_AA; }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? get_stage() : stage; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"getURL") ) { return getURL_dyn(); }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return inCallProp ? get_current() : current; }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { return sIsInit; }
		if (HX_FIELD_EQ(inName,"company") ) { return company; }
		if (HX_FIELD_EQ(inName,"version") ) { return version; }
		if (HX_FIELD_EQ(inName,"setIcon") ) { return setIcon_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { return HARDWARE; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { return nmeStage; }
		if (HX_FIELD_EQ(inName,"getTimer") ) { return getTimer_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { return RESIZABLE; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { return initWidth; }
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { return FULLSCREEN; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { return BORDERLESS; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { return initHeight; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { return nmeCurrent; }
		if (HX_FIELD_EQ(inName,"forceClose") ) { return forceClose_dyn(); }
		if (HX_FIELD_EQ(inName,"setPackage") ) { return setPackage_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HW_AA_HIRES") ) { return HW_AA_HIRES; }
		if (HX_FIELD_EQ(inName,"packageName") ) { return packageName; }
		if (HX_FIELD_EQ(inName,"get_current") ) { return get_current_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_get_url") ) { return nme_get_url; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DEPTH_BUFFER") ) { return DEPTH_BUFFER; }
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { return nmeMainFrame; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ALLOW_SHADERS") ) { return ALLOW_SHADERS; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"STENCIL_BUFFER") ) { return STENCIL_BUFFER; }
		if (HX_FIELD_EQ(inName,"postUICallback") ) { return postUICallback_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"REQUIRE_SHADERS") ) { return REQUIRE_SHADERS; }
		if (HX_FIELD_EQ(inName,"nme_set_package") ) { return nme_set_package; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createManagedStage") ) { return createManagedStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetCurrentStage") ) { return nmeSetCurrentStage_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { return nme_get_frame_stage; }
		if (HX_FIELD_EQ(inName,"nme_pause_animation") ) { return nme_pause_animation; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_resume_animation") ) { return nme_resume_animation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { VSYNC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HW_AA") ) { HW_AA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::native::display::MovieClip >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { sIsInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"company") ) { company=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"version") ) { version=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { nmeStage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { RESIZABLE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { initWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { FULLSCREEN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { BORDERLESS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { initHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { nmeCurrent=inValue.Cast< ::native::display::MovieClip >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HW_AA_HIRES") ) { HW_AA_HIRES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"packageName") ) { packageName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_get_url") ) { nme_get_url=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DEPTH_BUFFER") ) { DEPTH_BUFFER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { nmeMainFrame=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ALLOW_SHADERS") ) { ALLOW_SHADERS=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"STENCIL_BUFFER") ) { STENCIL_BUFFER=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"REQUIRE_SHADERS") ) { REQUIRE_SHADERS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_set_package") ) { nme_set_package=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { nme_get_frame_stage=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_pause_animation") ) { nme_pause_animation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_resume_animation") ) { nme_resume_animation=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FULLSCREEN"),
	HX_CSTRING("BORDERLESS"),
	HX_CSTRING("RESIZABLE"),
	HX_CSTRING("HARDWARE"),
	HX_CSTRING("VSYNC"),
	HX_CSTRING("HW_AA"),
	HX_CSTRING("HW_AA_HIRES"),
	HX_CSTRING("ALLOW_SHADERS"),
	HX_CSTRING("REQUIRE_SHADERS"),
	HX_CSTRING("DEPTH_BUFFER"),
	HX_CSTRING("STENCIL_BUFFER"),
	HX_CSTRING("current"),
	HX_CSTRING("initHeight"),
	HX_CSTRING("initWidth"),
	HX_CSTRING("stage"),
	HX_CSTRING("nmeCurrent"),
	HX_CSTRING("nmeMainFrame"),
	HX_CSTRING("nmeStage"),
	HX_CSTRING("sIsInit"),
	HX_CSTRING("company"),
	HX_CSTRING("version"),
	HX_CSTRING("packageName"),
	HX_CSTRING("file"),
	HX_CSTRING("close"),
	HX_CSTRING("create"),
	HX_CSTRING("createManagedStage"),
	HX_CSTRING("exit"),
	HX_CSTRING("forceClose"),
	HX_CSTRING("getTimer"),
	HX_CSTRING("getURL"),
	HX_CSTRING("nmeSetCurrentStage"),
	HX_CSTRING("pause"),
	HX_CSTRING("postUICallback"),
	HX_CSTRING("resume"),
	HX_CSTRING("setIcon"),
	HX_CSTRING("setPackage"),
	HX_CSTRING("get_current"),
	HX_CSTRING("get_stage"),
	HX_CSTRING("nme_set_package"),
	HX_CSTRING("nme_get_frame_stage"),
	HX_CSTRING("nme_get_url"),
	HX_CSTRING("nme_pause_animation"),
	HX_CSTRING("nme_resume_animation"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lib_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Lib_obj::FULLSCREEN,"FULLSCREEN");
	HX_MARK_MEMBER_NAME(Lib_obj::BORDERLESS,"BORDERLESS");
	HX_MARK_MEMBER_NAME(Lib_obj::RESIZABLE,"RESIZABLE");
	HX_MARK_MEMBER_NAME(Lib_obj::HARDWARE,"HARDWARE");
	HX_MARK_MEMBER_NAME(Lib_obj::VSYNC,"VSYNC");
	HX_MARK_MEMBER_NAME(Lib_obj::HW_AA,"HW_AA");
	HX_MARK_MEMBER_NAME(Lib_obj::HW_AA_HIRES,"HW_AA_HIRES");
	HX_MARK_MEMBER_NAME(Lib_obj::ALLOW_SHADERS,"ALLOW_SHADERS");
	HX_MARK_MEMBER_NAME(Lib_obj::REQUIRE_SHADERS,"REQUIRE_SHADERS");
	HX_MARK_MEMBER_NAME(Lib_obj::DEPTH_BUFFER,"DEPTH_BUFFER");
	HX_MARK_MEMBER_NAME(Lib_obj::STENCIL_BUFFER,"STENCIL_BUFFER");
	HX_MARK_MEMBER_NAME(Lib_obj::current,"current");
	HX_MARK_MEMBER_NAME(Lib_obj::initHeight,"initHeight");
	HX_MARK_MEMBER_NAME(Lib_obj::initWidth,"initWidth");
	HX_MARK_MEMBER_NAME(Lib_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeCurrent,"nmeCurrent");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeMainFrame,"nmeMainFrame");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeStage,"nmeStage");
	HX_MARK_MEMBER_NAME(Lib_obj::sIsInit,"sIsInit");
	HX_MARK_MEMBER_NAME(Lib_obj::company,"company");
	HX_MARK_MEMBER_NAME(Lib_obj::version,"version");
	HX_MARK_MEMBER_NAME(Lib_obj::packageName,"packageName");
	HX_MARK_MEMBER_NAME(Lib_obj::file,"file");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_set_package,"nme_set_package");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_get_frame_stage,"nme_get_frame_stage");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_get_url,"nme_get_url");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_pause_animation,"nme_pause_animation");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_resume_animation,"nme_resume_animation");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lib_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Lib_obj::FULLSCREEN,"FULLSCREEN");
	HX_VISIT_MEMBER_NAME(Lib_obj::BORDERLESS,"BORDERLESS");
	HX_VISIT_MEMBER_NAME(Lib_obj::RESIZABLE,"RESIZABLE");
	HX_VISIT_MEMBER_NAME(Lib_obj::HARDWARE,"HARDWARE");
	HX_VISIT_MEMBER_NAME(Lib_obj::VSYNC,"VSYNC");
	HX_VISIT_MEMBER_NAME(Lib_obj::HW_AA,"HW_AA");
	HX_VISIT_MEMBER_NAME(Lib_obj::HW_AA_HIRES,"HW_AA_HIRES");
	HX_VISIT_MEMBER_NAME(Lib_obj::ALLOW_SHADERS,"ALLOW_SHADERS");
	HX_VISIT_MEMBER_NAME(Lib_obj::REQUIRE_SHADERS,"REQUIRE_SHADERS");
	HX_VISIT_MEMBER_NAME(Lib_obj::DEPTH_BUFFER,"DEPTH_BUFFER");
	HX_VISIT_MEMBER_NAME(Lib_obj::STENCIL_BUFFER,"STENCIL_BUFFER");
	HX_VISIT_MEMBER_NAME(Lib_obj::current,"current");
	HX_VISIT_MEMBER_NAME(Lib_obj::initHeight,"initHeight");
	HX_VISIT_MEMBER_NAME(Lib_obj::initWidth,"initWidth");
	HX_VISIT_MEMBER_NAME(Lib_obj::stage,"stage");
	HX_VISIT_MEMBER_NAME(Lib_obj::nmeCurrent,"nmeCurrent");
	HX_VISIT_MEMBER_NAME(Lib_obj::nmeMainFrame,"nmeMainFrame");
	HX_VISIT_MEMBER_NAME(Lib_obj::nmeStage,"nmeStage");
	HX_VISIT_MEMBER_NAME(Lib_obj::sIsInit,"sIsInit");
	HX_VISIT_MEMBER_NAME(Lib_obj::company,"company");
	HX_VISIT_MEMBER_NAME(Lib_obj::version,"version");
	HX_VISIT_MEMBER_NAME(Lib_obj::packageName,"packageName");
	HX_VISIT_MEMBER_NAME(Lib_obj::file,"file");
	HX_VISIT_MEMBER_NAME(Lib_obj::nme_set_package,"nme_set_package");
	HX_VISIT_MEMBER_NAME(Lib_obj::nme_get_frame_stage,"nme_get_frame_stage");
	HX_VISIT_MEMBER_NAME(Lib_obj::nme_get_url,"nme_get_url");
	HX_VISIT_MEMBER_NAME(Lib_obj::nme_pause_animation,"nme_pause_animation");
	HX_VISIT_MEMBER_NAME(Lib_obj::nme_resume_animation,"nme_resume_animation");
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Lib_obj::__boot()
{
	FULLSCREEN= (int)1;
	BORDERLESS= (int)2;
	RESIZABLE= (int)4;
	HARDWARE= (int)8;
	VSYNC= (int)16;
	HW_AA= (int)32;
	HW_AA_HIRES= (int)96;
	ALLOW_SHADERS= (int)128;
	REQUIRE_SHADERS= (int)256;
	DEPTH_BUFFER= (int)512;
	STENCIL_BUFFER= (int)1024;
	nmeCurrent= null();
	nmeMainFrame= null();
	nmeStage= null();
	sIsInit= false;
	nme_set_package= ::native::Loader_obj::load(HX_CSTRING("nme_set_package"),(int)4);
	nme_get_frame_stage= ::native::Loader_obj::load(HX_CSTRING("nme_get_frame_stage"),(int)1);
	nme_get_url= ::native::Loader_obj::load(HX_CSTRING("nme_get_url"),(int)1);
	nme_pause_animation= ::native::Loader_obj::load(HX_CSTRING("nme_pause_animation"),(int)0);
	nme_resume_animation= ::native::Loader_obj::load(HX_CSTRING("nme_resume_animation"),(int)0);
}

} // end namespace native
