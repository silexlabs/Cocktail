#include <hxcpp.h>

#ifndef INCLUDED_core_nativeElement_NativeElementManager
#include <core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_core_nativeElement_NativeElementTypeValue
#include <core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_core_resource_AbstractImageLoader
#include <core/resource/AbstractImageLoader.h>
#endif
#ifndef INCLUDED_core_resource_AbstractMediaLoader
#include <core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_core_resource_AbstractResourceLoader
#include <core/resource/AbstractResourceLoader.h>
#endif
#ifndef INCLUDED_port_flash_player_MediaLoader
#include <port/flash_player/MediaLoader.h>
#endif
namespace core{
namespace resource{

Void AbstractImageLoader_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/resource/AbstractImageLoader.hx",32)
	Dynamic nativeElement = ::core::nativeElement::NativeElementManager_obj::createNativeElement(::core::nativeElement::NativeElementTypeValue_obj::image_dyn());
	HX_SOURCE_POS("../../src/core/resource/AbstractImageLoader.hx",33)
	super::__construct(nativeElement);
}
;
	return null();
}

AbstractImageLoader_obj::~AbstractImageLoader_obj() { }

Dynamic AbstractImageLoader_obj::__CreateEmpty() { return  new AbstractImageLoader_obj; }
hx::ObjectPtr< AbstractImageLoader_obj > AbstractImageLoader_obj::__new()
{  hx::ObjectPtr< AbstractImageLoader_obj > result = new AbstractImageLoader_obj();
	result->__construct();
	return result;}

Dynamic AbstractImageLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractImageLoader_obj > result = new AbstractImageLoader_obj();
	result->__construct();
	return result;}


AbstractImageLoader_obj::AbstractImageLoader_obj()
{
}

void AbstractImageLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractImageLoader);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractImageLoader_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic AbstractImageLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractImageLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractImageLoader_obj::__mClass;

void AbstractImageLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.resource.AbstractImageLoader"), hx::TCanCast< AbstractImageLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractImageLoader_obj::__boot()
{
}

} // end namespace core
} // end namespace resource
