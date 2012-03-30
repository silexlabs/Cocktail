#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_ManagedStage
#include <nme/display/ManagedStage.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace display{

Void ManagedStage_obj::__construct(int inWidth,int inHeight)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",43)
	super::__construct(::nme::display::ManagedStage_obj::nme_managed_stage_create(inWidth,inHeight),inWidth,inHeight);
}
;
	return null();
}

ManagedStage_obj::~ManagedStage_obj() { }

Dynamic ManagedStage_obj::__CreateEmpty() { return  new ManagedStage_obj; }
hx::ObjectPtr< ManagedStage_obj > ManagedStage_obj::__new(int inWidth,int inHeight)
{  hx::ObjectPtr< ManagedStage_obj > result = new ManagedStage_obj();
	result->__construct(inWidth,inHeight);
	return result;}

Dynamic ManagedStage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ManagedStage_obj > result = new ManagedStage_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_beginRender,ManagedStage_obj)
Void run(){
{
		HX_SOURCE_PUSH("ManagedStage_obj::beginRender")
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_endRender,ManagedStage_obj)
Void run(){
{
		HX_SOURCE_PUSH("ManagedStage_obj::endRender")
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

double ManagedStage_obj::nmeDoProcessStageEvent( Dynamic inEvent){
	HX_SOURCE_PUSH("ManagedStage_obj::nmeDoProcessStageEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",62)
	this->nmePollTimers();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",64)
	double wake = this->super::nmeDoProcessStageEvent(inEvent);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",65)
	this->setNextWake(wake);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",67)
	return wake;
}


HX_DEFINE_DYNAMIC_FUNC1(ManagedStage_obj,nmeDoProcessStageEvent,return )

Void ManagedStage_obj::nmeRender( bool inSendEnterFrame){
{
		HX_SOURCE_PUSH("ManagedStage_obj::nmeRender")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",76)
		this->beginRender();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",77)
		this->super::nmeRender(inSendEnterFrame);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",78)
		this->endRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ManagedStage_obj,nmeRender,(void))

Void ManagedStage_obj::pumpEvent( Dynamic inEvent){
{
		HX_SOURCE_PUSH("ManagedStage_obj::pumpEvent")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",83)
		::nme::display::ManagedStage_obj::nme_managed_stage_pump_event(this->nmeHandle,inEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ManagedStage_obj,pumpEvent,(void))

Void ManagedStage_obj::resize( int inWidth,int inHeight){
{
		HX_SOURCE_PUSH("ManagedStage_obj::resize")
		struct _Function_1_1{
			inline static Dynamic Block( int &inWidth,int &inHeight){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("type") , (int)8,false);
				__result->Add(HX_CSTRING("x") , inWidth,false);
				__result->Add(HX_CSTRING("y") , inHeight,false);
				return __result;
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",89)
		this->pumpEvent(_Function_1_1::Block(inWidth,inHeight));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ManagedStage_obj,resize,(void))

Void ManagedStage_obj::sendQuit( ){
{
		HX_SOURCE_PUSH("ManagedStage_obj::sendQuit")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("type") , (int)10,false);
				return __result;
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/ManagedStage.hx",95)
		this->pumpEvent(_Function_1_1::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ManagedStage_obj,sendQuit,(void))

HX_BEGIN_DEFAULT_FUNC(__default_setNextWake,ManagedStage_obj)
Void run(double inDelay){
{
		HX_SOURCE_PUSH("ManagedStage_obj::setNextWake")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

int ManagedStage_obj::etUnknown;

int ManagedStage_obj::etKeyDown;

int ManagedStage_obj::etChar;

int ManagedStage_obj::etKeyUp;

int ManagedStage_obj::etMouseMove;

int ManagedStage_obj::etMouseDown;

int ManagedStage_obj::etMouseClick;

int ManagedStage_obj::etMouseUp;

int ManagedStage_obj::etResize;

int ManagedStage_obj::etPoll;

int ManagedStage_obj::etQuit;

int ManagedStage_obj::etFocus;

int ManagedStage_obj::etShouldRotate;

int ManagedStage_obj::etDestroyHandler;

int ManagedStage_obj::etRedraw;

int ManagedStage_obj::etTouchBegin;

int ManagedStage_obj::etTouchMove;

int ManagedStage_obj::etTouchEnd;

int ManagedStage_obj::etTouchTap;

int ManagedStage_obj::etChange;

int ManagedStage_obj::efLeftDown;

int ManagedStage_obj::efShiftDown;

int ManagedStage_obj::efCtrlDown;

int ManagedStage_obj::efAltDown;

int ManagedStage_obj::efCommandDown;

int ManagedStage_obj::efMiddleDown;

int ManagedStage_obj::efRightDown;

int ManagedStage_obj::efLocationRight;

int ManagedStage_obj::efPrimaryTouch;

Dynamic ManagedStage_obj::nme_managed_stage_create;

Dynamic ManagedStage_obj::nme_managed_stage_pump_event;


ManagedStage_obj::ManagedStage_obj()
{
	beginRender = new __default_beginRender(this);
	endRender = new __default_endRender(this);
	setNextWake = new __default_setNextWake(this);
}

void ManagedStage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ManagedStage);
	HX_MARK_MEMBER_NAME(beginRender,"beginRender");
	HX_MARK_MEMBER_NAME(endRender,"endRender");
	HX_MARK_MEMBER_NAME(setNextWake,"setNextWake");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ManagedStage_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"etChar") ) { return etChar; }
		if (HX_FIELD_EQ(inName,"etPoll") ) { return etPoll; }
		if (HX_FIELD_EQ(inName,"etQuit") ) { return etQuit; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"etKeyUp") ) { return etKeyUp; }
		if (HX_FIELD_EQ(inName,"etFocus") ) { return etFocus; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"etResize") ) { return etResize; }
		if (HX_FIELD_EQ(inName,"etRedraw") ) { return etRedraw; }
		if (HX_FIELD_EQ(inName,"etChange") ) { return etChange; }
		if (HX_FIELD_EQ(inName,"sendQuit") ) { return sendQuit_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"etUnknown") ) { return etUnknown; }
		if (HX_FIELD_EQ(inName,"etKeyDown") ) { return etKeyDown; }
		if (HX_FIELD_EQ(inName,"etMouseUp") ) { return etMouseUp; }
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"endRender") ) { return endRender; }
		if (HX_FIELD_EQ(inName,"nmeRender") ) { return nmeRender_dyn(); }
		if (HX_FIELD_EQ(inName,"pumpEvent") ) { return pumpEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"etTouchEnd") ) { return etTouchEnd; }
		if (HX_FIELD_EQ(inName,"etTouchTap") ) { return etTouchTap; }
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { return efLeftDown; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { return efCtrlDown; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"etMouseMove") ) { return etMouseMove; }
		if (HX_FIELD_EQ(inName,"etMouseDown") ) { return etMouseDown; }
		if (HX_FIELD_EQ(inName,"etTouchMove") ) { return etTouchMove; }
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"efRightDown") ) { return efRightDown; }
		if (HX_FIELD_EQ(inName,"beginRender") ) { return beginRender; }
		if (HX_FIELD_EQ(inName,"setNextWake") ) { return setNextWake; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"etMouseClick") ) { return etMouseClick; }
		if (HX_FIELD_EQ(inName,"etTouchBegin") ) { return etTouchBegin; }
		if (HX_FIELD_EQ(inName,"efMiddleDown") ) { return efMiddleDown; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"etShouldRotate") ) { return etShouldRotate; }
		if (HX_FIELD_EQ(inName,"efPrimaryTouch") ) { return efPrimaryTouch; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { return efLocationRight; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"etDestroyHandler") ) { return etDestroyHandler; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeDoProcessStageEvent") ) { return nmeDoProcessStageEvent_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_create") ) { return nme_managed_stage_create; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_pump_event") ) { return nme_managed_stage_pump_event; }
	}
	return super::__Field(inName);
}

Dynamic ManagedStage_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"etChar") ) { etChar=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etPoll") ) { etPoll=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etQuit") ) { etQuit=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"etKeyUp") ) { etKeyUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etFocus") ) { etFocus=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"etResize") ) { etResize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etRedraw") ) { etRedraw=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etChange") ) { etChange=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"etUnknown") ) { etUnknown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etKeyDown") ) { etKeyDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etMouseUp") ) { etMouseUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRender") ) { endRender=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"etTouchEnd") ) { etTouchEnd=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchTap") ) { etTouchTap=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { efLeftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { efCtrlDown=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"etMouseMove") ) { etMouseMove=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etMouseDown") ) { etMouseDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchMove") ) { etTouchMove=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { efShiftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efRightDown") ) { efRightDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"beginRender") ) { beginRender=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"setNextWake") ) { setNextWake=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"etMouseClick") ) { etMouseClick=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchBegin") ) { etTouchBegin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efMiddleDown") ) { efMiddleDown=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"etShouldRotate") ) { etShouldRotate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efPrimaryTouch") ) { efPrimaryTouch=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { efLocationRight=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"etDestroyHandler") ) { etDestroyHandler=inValue.Cast< int >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_create") ) { nme_managed_stage_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_pump_event") ) { nme_managed_stage_pump_event=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ManagedStage_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("etUnknown"),
	HX_CSTRING("etKeyDown"),
	HX_CSTRING("etChar"),
	HX_CSTRING("etKeyUp"),
	HX_CSTRING("etMouseMove"),
	HX_CSTRING("etMouseDown"),
	HX_CSTRING("etMouseClick"),
	HX_CSTRING("etMouseUp"),
	HX_CSTRING("etResize"),
	HX_CSTRING("etPoll"),
	HX_CSTRING("etQuit"),
	HX_CSTRING("etFocus"),
	HX_CSTRING("etShouldRotate"),
	HX_CSTRING("etDestroyHandler"),
	HX_CSTRING("etRedraw"),
	HX_CSTRING("etTouchBegin"),
	HX_CSTRING("etTouchMove"),
	HX_CSTRING("etTouchEnd"),
	HX_CSTRING("etTouchTap"),
	HX_CSTRING("etChange"),
	HX_CSTRING("efLeftDown"),
	HX_CSTRING("efShiftDown"),
	HX_CSTRING("efCtrlDown"),
	HX_CSTRING("efAltDown"),
	HX_CSTRING("efCommandDown"),
	HX_CSTRING("efMiddleDown"),
	HX_CSTRING("efRightDown"),
	HX_CSTRING("efLocationRight"),
	HX_CSTRING("efPrimaryTouch"),
	HX_CSTRING("nme_managed_stage_create"),
	HX_CSTRING("nme_managed_stage_pump_event"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("beginRender"),
	HX_CSTRING("endRender"),
	HX_CSTRING("nmeDoProcessStageEvent"),
	HX_CSTRING("nmeRender"),
	HX_CSTRING("pumpEvent"),
	HX_CSTRING("resize"),
	HX_CSTRING("sendQuit"),
	HX_CSTRING("setNextWake"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etUnknown,"etUnknown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etKeyDown,"etKeyDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etChar,"etChar");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etKeyUp,"etKeyUp");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseMove,"etMouseMove");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseDown,"etMouseDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseClick,"etMouseClick");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseUp,"etMouseUp");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etResize,"etResize");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etPoll,"etPoll");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etQuit,"etQuit");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etFocus,"etFocus");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etShouldRotate,"etShouldRotate");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etDestroyHandler,"etDestroyHandler");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etRedraw,"etRedraw");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchBegin,"etTouchBegin");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchMove,"etTouchMove");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchEnd,"etTouchEnd");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchTap,"etTouchTap");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etChange,"etChange");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efLeftDown,"efLeftDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efShiftDown,"efShiftDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efCtrlDown,"efCtrlDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efAltDown,"efAltDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efCommandDown,"efCommandDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efMiddleDown,"efMiddleDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efRightDown,"efRightDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efLocationRight,"efLocationRight");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efPrimaryTouch,"efPrimaryTouch");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_create,"nme_managed_stage_create");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_pump_event,"nme_managed_stage_pump_event");
};

Class ManagedStage_obj::__mClass;

void ManagedStage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.ManagedStage"), hx::TCanCast< ManagedStage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ManagedStage_obj::__boot()
{
	hx::Static(etUnknown) = (int)0;
	hx::Static(etKeyDown) = (int)1;
	hx::Static(etChar) = (int)2;
	hx::Static(etKeyUp) = (int)3;
	hx::Static(etMouseMove) = (int)4;
	hx::Static(etMouseDown) = (int)5;
	hx::Static(etMouseClick) = (int)6;
	hx::Static(etMouseUp) = (int)7;
	hx::Static(etResize) = (int)8;
	hx::Static(etPoll) = (int)9;
	hx::Static(etQuit) = (int)10;
	hx::Static(etFocus) = (int)11;
	hx::Static(etShouldRotate) = (int)12;
	hx::Static(etDestroyHandler) = (int)13;
	hx::Static(etRedraw) = (int)14;
	hx::Static(etTouchBegin) = (int)15;
	hx::Static(etTouchMove) = (int)16;
	hx::Static(etTouchEnd) = (int)17;
	hx::Static(etTouchTap) = (int)18;
	hx::Static(etChange) = (int)19;
	hx::Static(efLeftDown) = (int)1;
	hx::Static(efShiftDown) = (int)2;
	hx::Static(efCtrlDown) = (int)4;
	hx::Static(efAltDown) = (int)8;
	hx::Static(efCommandDown) = (int)16;
	hx::Static(efMiddleDown) = (int)32;
	hx::Static(efRightDown) = (int)64;
	hx::Static(efLocationRight) = (int)16384;
	hx::Static(efPrimaryTouch) = (int)32768;
	hx::Static(nme_managed_stage_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_managed_stage_create"),(int)2);
	hx::Static(nme_managed_stage_pump_event) = ::nme::Loader_obj::load(HX_CSTRING("nme_managed_stage_pump_event"),(int)2);
}

} // end namespace nme
} // end namespace display
