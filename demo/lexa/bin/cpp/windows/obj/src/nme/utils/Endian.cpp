#include <hxcpp.h>

#ifndef INCLUDED_nme_utils_Endian
#include <nme/utils/Endian.h>
#endif
namespace nme{
namespace utils{

Void Endian_obj::__construct()
{
	return null();
}

Endian_obj::~Endian_obj() { }

Dynamic Endian_obj::__CreateEmpty() { return  new Endian_obj; }
hx::ObjectPtr< Endian_obj > Endian_obj::__new()
{  hx::ObjectPtr< Endian_obj > result = new Endian_obj();
	result->__construct();
	return result;}

Dynamic Endian_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Endian_obj > result = new Endian_obj();
	result->__construct();
	return result;}

::String Endian_obj::_BIG_ENDIAN;

::String Endian_obj::_LITTLE_ENDIAN;


Endian_obj::Endian_obj()
{
}

void Endian_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Endian);
	HX_MARK_END_CLASS();
}

Dynamic Endian_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"BIG_ENDIAN") ) { return _BIG_ENDIAN; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LITTLE_ENDIAN") ) { return _LITTLE_ENDIAN; }
	}
	return super::__Field(inName);
}

Dynamic Endian_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"BIG_ENDIAN") ) { _BIG_ENDIAN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LITTLE_ENDIAN") ) { _LITTLE_ENDIAN=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Endian_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("BIG_ENDIAN"),
	HX_CSTRING("LITTLE_ENDIAN"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Endian_obj::_BIG_ENDIAN,"BIG_ENDIAN");
	HX_MARK_MEMBER_NAME(Endian_obj::_LITTLE_ENDIAN,"LITTLE_ENDIAN");
};

Class Endian_obj::__mClass;

void Endian_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.utils.Endian"), hx::TCanCast< Endian_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Endian_obj::__boot()
{
	hx::Static(_BIG_ENDIAN) = HX_CSTRING("bigEndian");
	hx::Static(_LITTLE_ENDIAN) = HX_CSTRING("littleEndian");
}

} // end namespace nme
} // end namespace utils
