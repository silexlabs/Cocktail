#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextBase
#include <cocktail/port/base/NativeTextBase.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void NativeTextBase_obj::__construct(Dynamic nativeElement)
{
HX_STACK_PUSH("NativeTextBase::new","cocktail/port/base/NativeTextBase.hx",36);
{
	HX_STACK_LINE(36)
	this->_nativeElement = nativeElement;
}
;
	return null();
}

NativeTextBase_obj::~NativeTextBase_obj() { }

Dynamic NativeTextBase_obj::__CreateEmpty() { return  new NativeTextBase_obj; }
hx::ObjectPtr< NativeTextBase_obj > NativeTextBase_obj::__new(Dynamic nativeElement)
{  hx::ObjectPtr< NativeTextBase_obj > result = new NativeTextBase_obj();
	result->__construct(nativeElement);
	return result;}

Dynamic NativeTextBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextBase_obj > result = new NativeTextBase_obj();
	result->__construct(inArgs[0]);
	return result;}

Float NativeTextBase_obj::get_width( ){
	HX_STACK_PUSH("NativeTextBase::get_width","cocktail/port/base/NativeTextBase.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_LINE(66)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextBase_obj,get_width,return )

::native::display::BitmapData NativeTextBase_obj::getBitmap( ::cocktail::core::geom::RectangleVO bounds){
	HX_STACK_PUSH("NativeTextBase::getBitmap","cocktail/port/base/NativeTextBase.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_LINE(57)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextBase_obj,getBitmap,return )

Void NativeTextBase_obj::dispose( ){
{
		HX_STACK_PUSH("NativeTextBase::dispose","cocktail/port/base/NativeTextBase.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_LINE(44)
		this->_nativeElement = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextBase_obj,dispose,(void))


NativeTextBase_obj::NativeTextBase_obj()
{
}

void NativeTextBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeTextBase);
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void NativeTextBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic NativeTextBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeTextBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeTextBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeElement"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_width"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeTextBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeTextBase_obj::__mClass,"__mClass");
};

Class NativeTextBase_obj::__mClass;

void NativeTextBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.NativeTextBase"), hx::TCanCast< NativeTextBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeTextBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
