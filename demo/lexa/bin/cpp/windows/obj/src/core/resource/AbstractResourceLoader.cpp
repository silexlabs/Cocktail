#include <hxcpp.h>

#ifndef INCLUDED_core_resource_AbstractResourceLoader
#include <core/resource/AbstractResourceLoader.h>
#endif
namespace core{
namespace resource{

Void AbstractResourceLoader_obj::__construct()
{
{
}
;
	return null();
}

AbstractResourceLoader_obj::~AbstractResourceLoader_obj() { }

Dynamic AbstractResourceLoader_obj::__CreateEmpty() { return  new AbstractResourceLoader_obj; }
hx::ObjectPtr< AbstractResourceLoader_obj > AbstractResourceLoader_obj::__new()
{  hx::ObjectPtr< AbstractResourceLoader_obj > result = new AbstractResourceLoader_obj();
	result->__construct();
	return result;}

Dynamic AbstractResourceLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractResourceLoader_obj > result = new AbstractResourceLoader_obj();
	result->__construct();
	return result;}

Void AbstractResourceLoader_obj::load( Array< ::String > urls,Dynamic onLoadComplete,Dynamic onLoadError){
{
		HX_SOURCE_PUSH("AbstractResourceLoader_obj::load")
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",67)
		this->_onLoadCompleteCallback = onLoadComplete;
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",68)
		this->_onLoadErrorCallback = onLoadError;
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",70)
		this->_urls = urls;
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",71)
		this->_urlToLoadIdx = (int)0;
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",73)
		this->doLoad(this->_urls->__get(this->_urlToLoadIdx));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractResourceLoader_obj,load,(void))

Void AbstractResourceLoader_obj::doLoad( ::String url){
{
		HX_SOURCE_PUSH("AbstractResourceLoader_obj::doLoad")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractResourceLoader_obj,doLoad,(void))

Void AbstractResourceLoader_obj::onLoadComplete( Dynamic data){
{
		HX_SOURCE_PUSH("AbstractResourceLoader_obj::onLoadComplete")
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",99)
		this->_onLoadCompleteCallback(data);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractResourceLoader_obj,onLoadComplete,(void))

Void AbstractResourceLoader_obj::onLoadError( ::String msg){
{
		HX_SOURCE_PUSH("AbstractResourceLoader_obj::onLoadError")
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",113)
		(this->_urlToLoadIdx)++;
		HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",114)
		if (((this->_urlToLoadIdx < (this->_urls->length - (int)1)))){
			HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",115)
			this->doLoad(this->_urls->__get(this->_urlToLoadIdx));
		}
		else{
			HX_SOURCE_POS("../../src/core/resource/AbstractResourceLoader.hx",119)
			this->_onLoadErrorCallback(msg);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractResourceLoader_obj,onLoadError,(void))


AbstractResourceLoader_obj::AbstractResourceLoader_obj()
{
}

void AbstractResourceLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractResourceLoader);
	HX_MARK_MEMBER_NAME(_onLoadCompleteCallback,"_onLoadCompleteCallback");
	HX_MARK_MEMBER_NAME(_onLoadErrorCallback,"_onLoadErrorCallback");
	HX_MARK_MEMBER_NAME(_urlToLoadIdx,"_urlToLoadIdx");
	HX_MARK_MEMBER_NAME(_urls,"_urls");
	HX_MARK_END_CLASS();
}

Dynamic AbstractResourceLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { return _urls; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doLoad") ) { return doLoad_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onLoadError") ) { return onLoadError_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_urlToLoadIdx") ) { return _urlToLoadIdx; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadComplete") ) { return onLoadComplete_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_onLoadErrorCallback") ) { return _onLoadErrorCallback; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_onLoadCompleteCallback") ) { return _onLoadCompleteCallback; }
	}
	return super::__Field(inName);
}

Dynamic AbstractResourceLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { _urls=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_urlToLoadIdx") ) { _urlToLoadIdx=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_onLoadErrorCallback") ) { _onLoadErrorCallback=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_onLoadCompleteCallback") ) { _onLoadCompleteCallback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractResourceLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_urlToLoadIdx"));
	outFields->push(HX_CSTRING("_urls"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onLoadCompleteCallback"),
	HX_CSTRING("_onLoadErrorCallback"),
	HX_CSTRING("_urlToLoadIdx"),
	HX_CSTRING("_urls"),
	HX_CSTRING("load"),
	HX_CSTRING("doLoad"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("onLoadError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractResourceLoader_obj::__mClass;

void AbstractResourceLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.resource.AbstractResourceLoader"), hx::TCanCast< AbstractResourceLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractResourceLoader_obj::__boot()
{
}

} // end namespace core
} // end namespace resource
