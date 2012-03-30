#include <hxcpp.h>

#ifndef INCLUDED_core_resource_AbstractMediaLoader
#include <core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_core_resource_AbstractResourceLoader
#include <core/resource/AbstractResourceLoader.h>
#endif
namespace core{
namespace resource{

Void AbstractMediaLoader_obj::__construct(Dynamic nativeElement)
{
{
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",53)
	this->_nativeElement = nativeElement;
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",54)
	super::__construct();
}
;
	return null();
}

AbstractMediaLoader_obj::~AbstractMediaLoader_obj() { }

Dynamic AbstractMediaLoader_obj::__CreateEmpty() { return  new AbstractMediaLoader_obj; }
hx::ObjectPtr< AbstractMediaLoader_obj > AbstractMediaLoader_obj::__new(Dynamic nativeElement)
{  hx::ObjectPtr< AbstractMediaLoader_obj > result = new AbstractMediaLoader_obj();
	result->__construct(nativeElement);
	return result;}

Dynamic AbstractMediaLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractMediaLoader_obj > result = new AbstractMediaLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic AbstractMediaLoader_obj::getNativeElement( ){
	HX_SOURCE_PUSH("AbstractMediaLoader_obj::getNativeElement")
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",62)
	return this->_nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMediaLoader_obj,getNativeElement,return )

int AbstractMediaLoader_obj::getIntrinsicWidth( ){
	HX_SOURCE_PUSH("AbstractMediaLoader_obj::getIntrinsicWidth")
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",67)
	return this->_intrinsicWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMediaLoader_obj,getIntrinsicWidth,return )

int AbstractMediaLoader_obj::getIntrinsicHeight( ){
	HX_SOURCE_PUSH("AbstractMediaLoader_obj::getIntrinsicHeight")
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",72)
	return this->_intrinsicHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMediaLoader_obj,getIntrinsicHeight,return )

double AbstractMediaLoader_obj::getIntrinsicRatio( ){
	HX_SOURCE_PUSH("AbstractMediaLoader_obj::getIntrinsicRatio")
	HX_SOURCE_POS("../../src/core/resource/AbstractMediaLoader.hx",77)
	return this->_intrinsicRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMediaLoader_obj,getIntrinsicRatio,return )


AbstractMediaLoader_obj::AbstractMediaLoader_obj()
{
}

void AbstractMediaLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractMediaLoader);
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_MARK_MEMBER_NAME(nativeElement,"nativeElement");
	HX_MARK_MEMBER_NAME(_intrinsicWidth,"_intrinsicWidth");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(_intrinsicHeight,"_intrinsicHeight");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(_intrinsicRatio,"_intrinsicRatio");
	HX_MARK_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractMediaLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { return getNativeElement(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return getIntrinsicWidth(); }
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { return getIntrinsicRatio(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_intrinsicWidth") ) { return _intrinsicWidth; }
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return getIntrinsicHeight(); }
		if (HX_FIELD_EQ(inName,"_intrinsicRatio") ) { return _intrinsicRatio; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intrinsicHeight") ) { return _intrinsicHeight; }
		if (HX_FIELD_EQ(inName,"getNativeElement") ) { return getNativeElement_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getIntrinsicWidth") ) { return getIntrinsicWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getIntrinsicRatio") ) { return getIntrinsicRatio_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getIntrinsicHeight") ) { return getIntrinsicHeight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractMediaLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { intrinsicRatio=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_intrinsicWidth") ) { _intrinsicWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_intrinsicRatio") ) { _intrinsicRatio=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intrinsicHeight") ) { _intrinsicHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractMediaLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeElement"));
	outFields->push(HX_CSTRING("nativeElement"));
	outFields->push(HX_CSTRING("_intrinsicWidth"));
	outFields->push(HX_CSTRING("intrinsicWidth"));
	outFields->push(HX_CSTRING("_intrinsicHeight"));
	outFields->push(HX_CSTRING("intrinsicHeight"));
	outFields->push(HX_CSTRING("_intrinsicRatio"));
	outFields->push(HX_CSTRING("intrinsicRatio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("nativeElement"),
	HX_CSTRING("_intrinsicWidth"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("_intrinsicHeight"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("_intrinsicRatio"),
	HX_CSTRING("intrinsicRatio"),
	HX_CSTRING("getNativeElement"),
	HX_CSTRING("getIntrinsicWidth"),
	HX_CSTRING("getIntrinsicHeight"),
	HX_CSTRING("getIntrinsicRatio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractMediaLoader_obj::__mClass;

void AbstractMediaLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.resource.AbstractMediaLoader"), hx::TCanCast< AbstractMediaLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractMediaLoader_obj::__boot()
{
}

} // end namespace core
} // end namespace resource
