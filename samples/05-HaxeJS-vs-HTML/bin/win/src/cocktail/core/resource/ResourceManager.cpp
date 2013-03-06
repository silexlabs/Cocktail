#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#include <cocktail/core/http/DataFormatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#include <cocktail/port/base/NativeHttpBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_ImageResource
#include <cocktail/port/platform/flash_player/ImageResource.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_ImageResource
#include <cocktail/port/platform/nme/ImageResource.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeHttp
#include <cocktail/port/platform/nme/NativeHttp.h>
#endif
namespace cocktail{
namespace core{
namespace resource{

Void ResourceManager_obj::__construct()
{
HX_STACK_PUSH("ResourceManager::new","cocktail/core/resource/ResourceManager.hx",44);
{
}
;
	return null();
}

ResourceManager_obj::~ResourceManager_obj() { }

Dynamic ResourceManager_obj::__CreateEmpty() { return  new ResourceManager_obj; }
hx::ObjectPtr< ResourceManager_obj > ResourceManager_obj::__new()
{  hx::ObjectPtr< ResourceManager_obj > result = new ResourceManager_obj();
	result->__construct();
	return result;}

Dynamic ResourceManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ResourceManager_obj > result = new ResourceManager_obj();
	result->__construct();
	return result;}

::Hash ResourceManager_obj::_resources;

::Hash ResourceManager_obj::_binaryResources;

::cocktail::core::resource::AbstractResource ResourceManager_obj::getImageResource( ::String url){
	HX_STACK_PUSH("ResourceManager::getImageResource","cocktail/core/resource/ResourceManager.hx",54);
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(56)
	::cocktail::core::resource::AbstractResource resource = ::cocktail::core::resource::ResourceManager_obj::_resources->get(url);		HX_STACK_VAR(resource,"resource");
	HX_STACK_LINE(60)
	if (((resource == null()))){
		HX_STACK_LINE(62)
		resource = ::cocktail::port::platform::nme::ImageResource_obj::__new(url);
		HX_STACK_LINE(63)
		::cocktail::core::resource::ResourceManager_obj::_resources->set(url,resource);
	}
	HX_STACK_LINE(67)
	return resource;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ResourceManager_obj,getImageResource,return )

Void ResourceManager_obj::removeImageResource( ::String url){
{
		HX_STACK_PUSH("ResourceManager::removeImageResource","cocktail/core/resource/ResourceManager.hx",74);
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(74)
		::cocktail::core::resource::ResourceManager_obj::_resources->remove(url);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ResourceManager_obj,removeImageResource,(void))

::cocktail::port::platform::nme::NativeHttp ResourceManager_obj::getBinaryResource( ::String url){
	HX_STACK_PUSH("ResourceManager::getBinaryResource","cocktail/core/resource/ResourceManager.hx",83);
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(84)
	::cocktail::port::platform::nme::NativeHttp resource = ::cocktail::core::resource::ResourceManager_obj::_binaryResources->get(url);		HX_STACK_VAR(resource,"resource");
	HX_STACK_LINE(86)
	if (((resource == null()))){
		HX_STACK_LINE(88)
		resource = ::cocktail::port::platform::nme::NativeHttp_obj::__new();
		HX_STACK_LINE(89)
		resource->load(url,HX_CSTRING("GET"),null(),null(),::cocktail::core::http::DataFormatValue_obj::BINARY_dyn());
		HX_STACK_LINE(90)
		::cocktail::core::resource::ResourceManager_obj::_binaryResources->set(url,resource);
	}
	HX_STACK_LINE(93)
	return resource;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ResourceManager_obj,getBinaryResource,return )

Void ResourceManager_obj::removeBinaryResource( ::String url){
{
		HX_STACK_PUSH("ResourceManager::removeBinaryResource","cocktail/core/resource/ResourceManager.hx",100);
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(100)
		::cocktail::core::resource::ResourceManager_obj::_binaryResources->remove(url);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ResourceManager_obj,removeBinaryResource,(void))


ResourceManager_obj::ResourceManager_obj()
{
}

void ResourceManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ResourceManager);
	HX_MARK_END_CLASS();
}

void ResourceManager_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic ResourceManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_resources") ) { return _resources; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_binaryResources") ) { return _binaryResources; }
		if (HX_FIELD_EQ(inName,"getImageResource") ) { return getImageResource_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getBinaryResource") ) { return getBinaryResource_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"removeImageResource") ) { return removeImageResource_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"removeBinaryResource") ) { return removeBinaryResource_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ResourceManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_resources") ) { _resources=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_binaryResources") ) { _binaryResources=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ResourceManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_resources"),
	HX_CSTRING("_binaryResources"),
	HX_CSTRING("getImageResource"),
	HX_CSTRING("removeImageResource"),
	HX_CSTRING("getBinaryResource"),
	HX_CSTRING("removeBinaryResource"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ResourceManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ResourceManager_obj::_resources,"_resources");
	HX_MARK_MEMBER_NAME(ResourceManager_obj::_binaryResources,"_binaryResources");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ResourceManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ResourceManager_obj::_resources,"_resources");
	HX_VISIT_MEMBER_NAME(ResourceManager_obj::_binaryResources,"_binaryResources");
};

Class ResourceManager_obj::__mClass;

void ResourceManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.resource.ResourceManager"), hx::TCanCast< ResourceManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ResourceManager_obj::__boot()
{
	_resources= ::Hash_obj::__new();
	_binaryResources= ::Hash_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace resource
