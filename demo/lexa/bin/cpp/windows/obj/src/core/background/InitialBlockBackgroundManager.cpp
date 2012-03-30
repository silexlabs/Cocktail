#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_core_background_BackgroundManager
#include <core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_core_background_InitialBlockBackgroundManager
#include <core/background/InitialBlockBackgroundManager.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_window_AbstractWindow
#include <core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_port_flash_player_Window
#include <port/flash_player/Window.h>
#endif
namespace core{
namespace background{

Void InitialBlockBackgroundManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",37)
	super::__construct();
}
;
	return null();
}

InitialBlockBackgroundManager_obj::~InitialBlockBackgroundManager_obj() { }

Dynamic InitialBlockBackgroundManager_obj::__CreateEmpty() { return  new InitialBlockBackgroundManager_obj; }
hx::ObjectPtr< InitialBlockBackgroundManager_obj > InitialBlockBackgroundManager_obj::__new()
{  hx::ObjectPtr< InitialBlockBackgroundManager_obj > result = new InitialBlockBackgroundManager_obj();
	result->__construct();
	return result;}

Dynamic InitialBlockBackgroundManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialBlockBackgroundManager_obj > result = new InitialBlockBackgroundManager_obj();
	result->__construct();
	return result;}

Dynamic InitialBlockBackgroundManager_obj::getBackgroundPaintingBox( Dynamic computedBackgroundBox){
	HX_SOURCE_PUSH("InitialBlockBackgroundManager_obj::getBackgroundPaintingBox")
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",49)
	return this->getWindowRectangleData();
}


HX_DEFINE_DYNAMIC_FUNC1(InitialBlockBackgroundManager_obj,getBackgroundPaintingBox,return )

Dynamic InitialBlockBackgroundManager_obj::getBackgroundPositioningBox( Dynamic computedPositioningBox){
	HX_SOURCE_PUSH("InitialBlockBackgroundManager_obj::getBackgroundPositioningBox")
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",57)
	return this->getWindowRectangleData();
}


HX_DEFINE_DYNAMIC_FUNC1(InitialBlockBackgroundManager_obj,getBackgroundPositioningBox,return )

Dynamic InitialBlockBackgroundManager_obj::getWindowRectangleData( ){
	HX_SOURCE_PUSH("InitialBlockBackgroundManager_obj::getWindowRectangleData")
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",70)
	double windowWidth = ::cocktail::Lib_obj::get_window()->get_innerWidth();
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",71)
	double windowHeight = ::cocktail::Lib_obj::get_window()->get_innerHeight();
	struct _Function_1_1{
		inline static Dynamic Block( double &windowWidth,double &windowHeight){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , 0.0,false);
			__result->Add(HX_CSTRING("y") , 0.0,false);
			__result->Add(HX_CSTRING("width") , windowWidth,false);
			__result->Add(HX_CSTRING("height") , windowHeight,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",73)
	Dynamic window = _Function_1_1::Block(windowWidth,windowHeight);
	HX_SOURCE_POS("../../src/core/background/InitialBlockBackgroundManager.hx",80)
	return window;
}


HX_DEFINE_DYNAMIC_FUNC0(InitialBlockBackgroundManager_obj,getWindowRectangleData,return )


InitialBlockBackgroundManager_obj::InitialBlockBackgroundManager_obj()
{
}

void InitialBlockBackgroundManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialBlockBackgroundManager);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InitialBlockBackgroundManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 22:
		if (HX_FIELD_EQ(inName,"getWindowRectangleData") ) { return getWindowRectangleData_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getBackgroundPaintingBox") ) { return getBackgroundPaintingBox_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"getBackgroundPositioningBox") ) { return getBackgroundPositioningBox_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InitialBlockBackgroundManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void InitialBlockBackgroundManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBackgroundPaintingBox"),
	HX_CSTRING("getBackgroundPositioningBox"),
	HX_CSTRING("getWindowRectangleData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InitialBlockBackgroundManager_obj::__mClass;

void InitialBlockBackgroundManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.background.InitialBlockBackgroundManager"), hx::TCanCast< InitialBlockBackgroundManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InitialBlockBackgroundManager_obj::__boot()
{
}

} // end namespace core
} // end namespace background
