#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_mouse_AbstractMouseCursor
#include <cocktail/core/mouse/AbstractMouseCursor.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_MouseCursorManager
#include <cocktail/core/mouse/MouseCursorManager.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_MouseCursorValue
#include <cocktail/core/mouse/MouseCursorValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_MouseCursor
#include <cocktail/port/flash_player/MouseCursor.h>
#endif
namespace cocktail{
namespace core{
namespace mouse{

Void MouseCursorManager_obj::__construct()
{
{
}
;
	return null();
}

MouseCursorManager_obj::~MouseCursorManager_obj() { }

Dynamic MouseCursorManager_obj::__CreateEmpty() { return  new MouseCursorManager_obj; }
hx::ObjectPtr< MouseCursorManager_obj > MouseCursorManager_obj::__new()
{  hx::ObjectPtr< MouseCursorManager_obj > result = new MouseCursorManager_obj();
	result->__construct();
	return result;}

Dynamic MouseCursorManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseCursorManager_obj > result = new MouseCursorManager_obj();
	result->__construct();
	return result;}

::cocktail::port::flash_player::MouseCursor MouseCursorManager_obj::_mouseCursor;

Void MouseCursorManager_obj::setMouseCursor( ::cocktail::core::mouse::MouseCursorValue mouseCursorValue){
{
		HX_SOURCE_PUSH("MouseCursorManager_obj::setMouseCursor")
		HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",61)
		if (((::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",62)
			::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor = ::cocktail::port::flash_player::MouseCursor_obj::__new();
		}
		HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",66)
		::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor->setNativeMouseCursor(mouseCursorValue);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MouseCursorManager_obj,setMouseCursor,(void))

::cocktail::core::mouse::MouseCursorValue MouseCursorManager_obj::getMousecursor( ){
	HX_SOURCE_PUSH("MouseCursorManager_obj::getMousecursor")
	HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",75)
	if (((::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",76)
		::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor = ::cocktail::port::flash_player::MouseCursor_obj::__new();
	}
	HX_SOURCE_POS("../../src/cocktail/core/mouse/MouseCursorManager.hx",80)
	return ::cocktail::core::mouse::MouseCursorManager_obj::_mouseCursor->getNativeMouseCursor();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MouseCursorManager_obj,getMousecursor,return )


MouseCursorManager_obj::MouseCursorManager_obj()
{
}

void MouseCursorManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseCursorManager);
	HX_MARK_END_CLASS();
}

Dynamic MouseCursorManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_mouseCursor") ) { return _mouseCursor; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setMouseCursor") ) { return setMouseCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"getMousecursor") ) { return getMousecursor_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MouseCursorManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_mouseCursor") ) { _mouseCursor=inValue.Cast< ::cocktail::port::flash_player::MouseCursor >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MouseCursorManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_mouseCursor"),
	HX_CSTRING("setMouseCursor"),
	HX_CSTRING("getMousecursor"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseCursorManager_obj::_mouseCursor,"_mouseCursor");
};

Class MouseCursorManager_obj::__mClass;

void MouseCursorManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.mouse.MouseCursorManager"), hx::TCanCast< MouseCursorManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MouseCursorManager_obj::__boot()
{
	hx::Static(_mouseCursor);
}

} // end namespace cocktail
} // end namespace core
} // end namespace mouse
