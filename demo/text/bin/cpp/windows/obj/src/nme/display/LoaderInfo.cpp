#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Loader
#include <nme/display/Loader.h>
#endif
#ifndef INCLUDED_nme_display_LoaderInfo
#include <nme/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_net_URLLoader
#include <nme/net/URLLoader.h>
#endif
#ifndef INCLUDED_nme_net_URLLoaderDataFormat
#include <nme/net/URLLoaderDataFormat.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace nme{
namespace display{

Void LoaderInfo_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",43)
	super::__construct(null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",45)
	this->childAllowsParent = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",46)
	this->frameRate = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",47)
	this->dataFormat = ::nme::net::URLLoaderDataFormat_obj::BINARY_dyn();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",48)
	this->loaderURL = null();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",51)
	this->addEventListener(::nme::events::Event_obj::COMPLETE,this->onURLLoaded_dyn(),null(),null(),null());
}
;
	return null();
}

LoaderInfo_obj::~LoaderInfo_obj() { }

Dynamic LoaderInfo_obj::__CreateEmpty() { return  new LoaderInfo_obj; }
hx::ObjectPtr< LoaderInfo_obj > LoaderInfo_obj::__new()
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

Dynamic LoaderInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

Void LoaderInfo_obj::load( ::nme::net::URLRequest request){
{
		HX_SOURCE_PUSH("LoaderInfo_obj::load")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",67)
		this->pendingURL = request->url;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",68)
		int dot = this->pendingURL.lastIndexOf(HX_CSTRING("."),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",69)
		::String extension = (  (((dot > (int)0))) ? ::String(this->pendingURL.substr((dot + (int)1),null()).toLowerCase()) : ::String(HX_CSTRING("")) );
		struct _Function_1_1{
			inline static ::String Block( ::String &extension,::nme::display::LoaderInfo_obj *__this){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",71)
				::String _switch_1 = (extension);
				if (  ( _switch_1==HX_CSTRING("swf"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",73)
					return HX_CSTRING("application/x-shockwave-flash");
				}
				else if (  ( _switch_1==HX_CSTRING("jpg")) ||  ( _switch_1==HX_CSTRING("jpeg"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",74)
					return HX_CSTRING("image/jpeg");
				}
				else if (  ( _switch_1==HX_CSTRING("png"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",75)
					return HX_CSTRING("image/png");
				}
				else if (  ( _switch_1==HX_CSTRING("gif"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",76)
					return HX_CSTRING("image/gif");
				}
				else  {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",77)
					return hx::Throw ((HX_CSTRING("Unrecognized file ") + __this->pendingURL));
				}
;
;
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",71)
		this->contentType = _Function_1_1::Block(extension,this);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",81)
		this->url = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",83)
		this->super::load(request);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,load,(void))

Void LoaderInfo_obj::onURLLoaded( ::nme::events::Event event){
{
		HX_SOURCE_PUSH("LoaderInfo_obj::onURLLoaded")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",93)
		this->url = this->pendingURL;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,onURLLoaded,(void))

::nme::utils::ByteArray LoaderInfo_obj::getBytes( ){
	HX_SOURCE_PUSH("LoaderInfo_obj::getBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",104)
	return this->data;
}


HX_DEFINE_DYNAMIC_FUNC0(LoaderInfo_obj,getBytes,return )

::nme::display::LoaderInfo LoaderInfo_obj::create( ::nme::display::Loader ldr){
	HX_SOURCE_PUSH("LoaderInfo_obj::create")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",57)
	::nme::display::LoaderInfo li = ::nme::display::LoaderInfo_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",58)
	li->loader = ldr;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/LoaderInfo.hx",60)
	return li;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,create,return )


LoaderInfo_obj::LoaderInfo_obj()
{
}

void LoaderInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoaderInfo);
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(childAllowsParent,"childAllowsParent");
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(contentType,"contentType");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(loaderURL,"loaderURL");
	HX_MARK_MEMBER_NAME(parameters,"parameters");
	HX_MARK_MEMBER_NAME(parentAllowsChild,"parentAllowsChild");
	HX_MARK_MEMBER_NAME(sameDomain,"sameDomain");
	HX_MARK_MEMBER_NAME(sharedEvents,"sharedEvents");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(pendingURL,"pendingURL");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LoaderInfo_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { return getBytes(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"loader") ) { return loader; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		if (HX_FIELD_EQ(inName,"loaderURL") ) { return loaderURL; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parameters") ) { return parameters; }
		if (HX_FIELD_EQ(inName,"sameDomain") ) { return sameDomain; }
		if (HX_FIELD_EQ(inName,"pendingURL") ) { return pendingURL; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { return contentType; }
		if (HX_FIELD_EQ(inName,"onURLLoaded") ) { return onURLLoaded_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { return sharedEvents; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { return childAllowsParent; }
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { return parentAllowsChild; }
	}
	return super::__Field(inName);
}

Dynamic LoaderInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast< ::nme::utils::ByteArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast< ::nme::display::Loader >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::nme::display::DisplayObject >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { frameRate=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loaderURL") ) { loaderURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parameters") ) { parameters=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sameDomain") ) { sameDomain=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pendingURL") ) { pendingURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { contentType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { sharedEvents=inValue.Cast< ::nme::events::EventDispatcher >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { childAllowsParent=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { parentAllowsChild=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LoaderInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytes"));
	outFields->push(HX_CSTRING("childAllowsParent"));
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("contentType"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("loader"));
	outFields->push(HX_CSTRING("loaderURL"));
	outFields->push(HX_CSTRING("parameters"));
	outFields->push(HX_CSTRING("parentAllowsChild"));
	outFields->push(HX_CSTRING("sameDomain"));
	outFields->push(HX_CSTRING("sharedEvents"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("pendingURL"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bytes"),
	HX_CSTRING("childAllowsParent"),
	HX_CSTRING("content"),
	HX_CSTRING("contentType"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("height"),
	HX_CSTRING("loader"),
	HX_CSTRING("loaderURL"),
	HX_CSTRING("parameters"),
	HX_CSTRING("parentAllowsChild"),
	HX_CSTRING("sameDomain"),
	HX_CSTRING("sharedEvents"),
	HX_CSTRING("url"),
	HX_CSTRING("width"),
	HX_CSTRING("pendingURL"),
	HX_CSTRING("load"),
	HX_CSTRING("onURLLoaded"),
	HX_CSTRING("getBytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LoaderInfo_obj::__mClass;

void LoaderInfo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.LoaderInfo"), hx::TCanCast< LoaderInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LoaderInfo_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
