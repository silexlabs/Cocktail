#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextBase
#include <cocktail/port/base/NativeTextBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeText
#include <cocktail/port/platform/nme/NativeText.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace nme{

Void NativeText_obj::__construct(Dynamic nativeElement)
{
HX_STACK_PUSH("NativeText::new","cocktail/port/platform/nme/NativeText.hx",35);
{
	HX_STACK_LINE(36)
	super::__construct(nativeElement);
	HX_STACK_LINE(37)
	this->_textField = nativeElement;
}
;
	return null();
}

NativeText_obj::~NativeText_obj() { }

Dynamic NativeText_obj::__CreateEmpty() { return  new NativeText_obj; }
hx::ObjectPtr< NativeText_obj > NativeText_obj::__new(Dynamic nativeElement)
{  hx::ObjectPtr< NativeText_obj > result = new NativeText_obj();
	result->__construct(nativeElement);
	return result;}

Dynamic NativeText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeText_obj > result = new NativeText_obj();
	result->__construct(inArgs[0]);
	return result;}

Float NativeText_obj::get_width( ){
	HX_STACK_PUSH("NativeText::get_width","cocktail/port/platform/nme/NativeText.hx",63);
	HX_STACK_THIS(this);
	HX_STACK_LINE(63)
	return this->_textField->nmeGetWidth();
}


::neash::display::BitmapData NativeText_obj::getBitmap( ::cocktail::core::geom::RectangleVO bounds){
	HX_STACK_PUSH("NativeText::getBitmap","cocktail/port/platform/nme/NativeText.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_LINE(50)
	::neash::display::BitmapData bitmap = ::neash::display::BitmapData_obj::__new(::Math_obj::round(bounds->width),::Math_obj::round(bounds->height),true,(int)0);		HX_STACK_VAR(bitmap,"bitmap");
	HX_STACK_LINE(51)
	bitmap->draw(this->_nativeElement,null(),null(),null(),null(),null());
	HX_STACK_LINE(52)
	return bitmap;
}



NativeText_obj::NativeText_obj()
{
}

void NativeText_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeText);
	HX_MARK_MEMBER_NAME(_textField,"_textField");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeText_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_textField,"_textField");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeText_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_textField") ) { return _textField; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeText_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_textField") ) { _textField=inValue.Cast< ::neash::text::TextField >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_textField"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_width"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("_textField"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeText_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeText_obj::__mClass,"__mClass");
};

Class NativeText_obj::__mClass;

void NativeText_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.nme.NativeText"), hx::TCanCast< NativeText_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeText_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme
