#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Loader
#include <neash/display/Loader.h>
#endif
#ifndef INCLUDED_neash_display_LoaderInfo
#include <neash/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_net_URLLoader
#include <neash/net/URLLoader.h>
#endif
#ifndef INCLUDED_neash_net_URLRequest
#include <neash/net/URLRequest.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace display{

Void Loader_obj::__construct()
{
HX_STACK_PUSH("Loader::new","neash/display/Loader.hx",36);
{
	HX_STACK_LINE(37)
	super::__construct();
	HX_STACK_LINE(38)
	this->contentLoaderInfo = ::neash::display::LoaderInfo_obj::create(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(40)
	this->contentLoaderInfo->nmeOnComplete = this->doLoad_dyn();
}
;
	return null();
}

Loader_obj::~Loader_obj() { }

Dynamic Loader_obj::__CreateEmpty() { return  new Loader_obj; }
hx::ObjectPtr< Loader_obj > Loader_obj::__new()
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

Dynamic Loader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

Void Loader_obj::onData( ::neash::events::Event event){
{
		HX_STACK_PUSH("Loader::onData","neash/display/Loader.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(120)
		event->stopImmediatePropagation();
		HX_STACK_LINE(121)
		this->doLoad(this->contentLoaderInfo->getBytes());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,onData,(void))

Void Loader_obj::unload( ){
{
		HX_STACK_PUSH("Loader::unload","neash/display/Loader.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_LINE(90)
		if (((this->nmeGetNumChildren() > (int)0))){
			HX_STACK_LINE(93)
			while(((this->nmeGetNumChildren() > (int)0))){
				HX_STACK_LINE(94)
				this->removeChildAt((int)0);
			}
			HX_STACK_LINE(99)
			{
				HX_STACK_LINE(100)
				this->contentLoaderInfo->url = null();
				HX_STACK_LINE(101)
				this->contentLoaderInfo->contentType = null();
				HX_STACK_LINE(102)
				this->contentLoaderInfo->content = null();
				HX_STACK_LINE(103)
				this->contentLoaderInfo->bytesLoaded = this->contentLoaderInfo->bytesTotal = (int)0;
				HX_STACK_LINE(104)
				this->contentLoaderInfo->width = (int)0;
				HX_STACK_LINE(105)
				this->contentLoaderInfo->height = (int)0;
			}
			HX_STACK_LINE(108)
			this->dispatchEvent(::neash::events::Event_obj::__new(::neash::events::Event_obj::UNLOAD,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Loader_obj,unload,(void))

Void Loader_obj::loadBytes( ::neash::utils::ByteArray bytes){
{
		HX_STACK_PUSH("Loader::loadBytes","neash/display/Loader.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_LINE(80)
		if ((this->doLoad(bytes))){
			HX_STACK_LINE(83)
			this->contentLoaderInfo->dispatchEvent(::neash::events::Event_obj::__new(::neash::events::Event_obj::COMPLETE,null(),null()));
		}
		else{
			HX_STACK_LINE(85)
			this->contentLoaderInfo->DispatchIOErrorEvent();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,loadBytes,(void))

Void Loader_obj::load( ::neash::net::URLRequest request){
{
		HX_STACK_PUSH("Loader::load","neash/display/Loader.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_ARG(request,"request");
		HX_STACK_LINE(73)
		this->contentLoaderInfo->load(request);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,load,(void))

bool Loader_obj::doLoad( ::neash::utils::ByteArray inBytes){
	HX_STACK_PUSH("Loader::doLoad","neash/display/Loader.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inBytes,"inBytes");
	HX_STACK_LINE(46)
	if (((inBytes == null()))){
		HX_STACK_LINE(47)
		return false;
	}
	HX_STACK_LINE(48)
	try{
		HX_STACK_LINE(50)
		this->nmeImage = ::neash::display::BitmapData_obj::loadFromBytes(inBytes,null());
		HX_STACK_LINE(52)
		::neash::display::Bitmap bmp = ::neash::display::Bitmap_obj::__new(this->nmeImage,null(),null());		HX_STACK_VAR(bmp,"bmp");
		HX_STACK_LINE(53)
		this->content = bmp;
		HX_STACK_LINE(54)
		this->contentLoaderInfo->content = bmp;
		HX_STACK_LINE(56)
		while(((this->nmeGetNumChildren() > (int)0))){
			HX_STACK_LINE(57)
			this->removeChildAt((int)0);
		}
		HX_STACK_LINE(61)
		this->addChild(bmp);
		HX_STACK_LINE(62)
		return true;
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_STACK_LINE(65)
				return false;
			}
		}
	}
	HX_STACK_LINE(48)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,doLoad,return )


Loader_obj::Loader_obj()
{
}

void Loader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Loader);
	HX_MARK_MEMBER_NAME(nmeSWF,"nmeSWF");
	HX_MARK_MEMBER_NAME(nmeImage,"nmeImage");
	HX_MARK_MEMBER_NAME(contentLoaderInfo,"contentLoaderInfo");
	HX_MARK_MEMBER_NAME(content,"content");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Loader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeSWF,"nmeSWF");
	HX_VISIT_MEMBER_NAME(nmeImage,"nmeImage");
	HX_VISIT_MEMBER_NAME(contentLoaderInfo,"contentLoaderInfo");
	HX_VISIT_MEMBER_NAME(content,"content");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Loader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onData") ) { return onData_dyn(); }
		if (HX_FIELD_EQ(inName,"unload") ) { return unload_dyn(); }
		if (HX_FIELD_EQ(inName,"doLoad") ) { return doLoad_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSWF") ) { return nmeSWF; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nmeImage") ) { return nmeImage; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return loadBytes_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"contentLoaderInfo") ) { return contentLoaderInfo; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Loader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"nmeSWF") ) { nmeSWF=inValue.Cast< ::neash::display::MovieClip >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nmeImage") ) { nmeImage=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"contentLoaderInfo") ) { contentLoaderInfo=inValue.Cast< ::neash::display::LoaderInfo >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Loader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeSWF"));
	outFields->push(HX_CSTRING("nmeImage"));
	outFields->push(HX_CSTRING("contentLoaderInfo"));
	outFields->push(HX_CSTRING("content"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onData"),
	HX_CSTRING("unload"),
	HX_CSTRING("loadBytes"),
	HX_CSTRING("load"),
	HX_CSTRING("doLoad"),
	HX_CSTRING("nmeSWF"),
	HX_CSTRING("nmeImage"),
	HX_CSTRING("contentLoaderInfo"),
	HX_CSTRING("content"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Loader_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Loader_obj::__mClass,"__mClass");
};

Class Loader_obj::__mClass;

void Loader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Loader"), hx::TCanCast< Loader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Loader_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
