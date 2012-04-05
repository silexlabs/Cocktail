#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLImageElement
#include <core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_mouse_AbstractMouseCursor
#include <core/mouse/AbstractMouseCursor.h>
#endif
#ifndef INCLUDED_core_mouse_MouseCursorValue
#include <core/mouse/MouseCursorValue.h>
#endif
#ifndef INCLUDED_core_mouse_NativeOSMouseCursorValue
#include <core/mouse/NativeOSMouseCursorValue.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace mouse{

Void AbstractMouseCursor_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",34)
	this->_nativeMouseCursor = ::core::mouse::MouseCursorValue_obj::cssAuto_dyn();
}
;
	return null();
}

AbstractMouseCursor_obj::~AbstractMouseCursor_obj() { }

Dynamic AbstractMouseCursor_obj::__CreateEmpty() { return  new AbstractMouseCursor_obj; }
hx::ObjectPtr< AbstractMouseCursor_obj > AbstractMouseCursor_obj::__new()
{  hx::ObjectPtr< AbstractMouseCursor_obj > result = new AbstractMouseCursor_obj();
	result->__construct();
	return result;}

Dynamic AbstractMouseCursor_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractMouseCursor_obj > result = new AbstractMouseCursor_obj();
	result->__construct();
	return result;}

::core::mouse::MouseCursorValue AbstractMouseCursor_obj::setNativeMouseCursor( ::core::mouse::MouseCursorValue value){
	HX_SOURCE_PUSH("AbstractMouseCursor_obj::setNativeMouseCursor")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",47)
	this->_nativeMouseCursor = value;
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",49)
	{
::core::mouse::MouseCursorValue _switch_1 = (value);
		switch((_switch_1)->GetIndex()){
			case 0: {
				Dynamic hotSpot = _switch_1->__Param(1);
				::core::html::AbstractHTMLImageElement imageHTMLElement = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",54)
					this->setBitmapCursor(imageHTMLElement,hotSpot);
				}
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",58)
				this->setDefaultCursor();
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",62)
				this->hideCursor();
			}
			;break;
			case 3: {
				::core::mouse::NativeOSMouseCursorValue nativeOSMouseCursor = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",66)
					this->setNativeOSCursor(nativeOSMouseCursor);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",70)
	return this->_nativeMouseCursor;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouseCursor_obj,setNativeMouseCursor,return )

::core::mouse::MouseCursorValue AbstractMouseCursor_obj::getNativeMouseCursor( ){
	HX_SOURCE_PUSH("AbstractMouseCursor_obj::getNativeMouseCursor")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouseCursor.hx",77)
	return this->_nativeMouseCursor;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouseCursor_obj,getNativeMouseCursor,return )

Void AbstractMouseCursor_obj::setBitmapCursor( ::core::html::AbstractHTMLImageElement imageHTMLElement,Dynamic hotSpot){
{
		HX_SOURCE_PUSH("AbstractMouseCursor_obj::setBitmapCursor")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractMouseCursor_obj,setBitmapCursor,(void))

Void AbstractMouseCursor_obj::hideCursor( ){
{
		HX_SOURCE_PUSH("AbstractMouseCursor_obj::hideCursor")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouseCursor_obj,hideCursor,(void))

Void AbstractMouseCursor_obj::setDefaultCursor( ){
{
		HX_SOURCE_PUSH("AbstractMouseCursor_obj::setDefaultCursor")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouseCursor_obj,setDefaultCursor,(void))

Void AbstractMouseCursor_obj::setNativeOSCursor( ::core::mouse::NativeOSMouseCursorValue value){
{
		HX_SOURCE_PUSH("AbstractMouseCursor_obj::setNativeOSCursor")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouseCursor_obj,setNativeOSCursor,(void))


AbstractMouseCursor_obj::AbstractMouseCursor_obj()
{
}

void AbstractMouseCursor_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractMouseCursor);
	HX_MARK_MEMBER_NAME(_nativeMouseCursor,"_nativeMouseCursor");
	HX_MARK_MEMBER_NAME(nativeMouseCursor,"nativeMouseCursor");
	HX_MARK_END_CLASS();
}

Dynamic AbstractMouseCursor_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"hideCursor") ) { return hideCursor_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setBitmapCursor") ) { return setBitmapCursor_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setDefaultCursor") ) { return setDefaultCursor_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nativeMouseCursor") ) { return getNativeMouseCursor(); }
		if (HX_FIELD_EQ(inName,"setNativeOSCursor") ) { return setNativeOSCursor_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_nativeMouseCursor") ) { return _nativeMouseCursor; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"setNativeMouseCursor") ) { return setNativeMouseCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"getNativeMouseCursor") ) { return getNativeMouseCursor_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractMouseCursor_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"nativeMouseCursor") ) { return setNativeMouseCursor(inValue); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_nativeMouseCursor") ) { _nativeMouseCursor=inValue.Cast< ::core::mouse::MouseCursorValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractMouseCursor_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeMouseCursor"));
	outFields->push(HX_CSTRING("nativeMouseCursor"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nativeMouseCursor"),
	HX_CSTRING("nativeMouseCursor"),
	HX_CSTRING("setNativeMouseCursor"),
	HX_CSTRING("getNativeMouseCursor"),
	HX_CSTRING("setBitmapCursor"),
	HX_CSTRING("hideCursor"),
	HX_CSTRING("setDefaultCursor"),
	HX_CSTRING("setNativeOSCursor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractMouseCursor_obj::__mClass;

void AbstractMouseCursor_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.mouse.AbstractMouseCursor"), hx::TCanCast< AbstractMouseCursor_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractMouseCursor_obj::__boot()
{
}

} // end namespace core
} // end namespace mouse
