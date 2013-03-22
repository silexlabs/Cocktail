#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void NativeMedia_obj::__construct()
{
HX_STACK_PUSH("NativeMedia::new","cocktail/port/base/NativeMedia.hx",104);
{
	HX_STACK_LINE(105)
	this->set_alpha(1.0);
	HX_STACK_LINE(106)
	this->set_matrix(::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(107)
	this->set_viewport(::cocktail::core::geom::RectangleVO_obj::__new());
}
;
	return null();
}

NativeMedia_obj::~NativeMedia_obj() { }

Dynamic NativeMedia_obj::__CreateEmpty() { return  new NativeMedia_obj; }
hx::ObjectPtr< NativeMedia_obj > NativeMedia_obj::__new()
{  hx::ObjectPtr< NativeMedia_obj > result = new NativeMedia_obj();
	result->__construct();
	return result;}

Dynamic NativeMedia_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeMedia_obj > result = new NativeMedia_obj();
	result->__construct();
	return result;}

Float NativeMedia_obj::set_alpha( Float value){
	HX_STACK_PUSH("NativeMedia::set_alpha","cocktail/port/base/NativeMedia.hx",259);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(259)
	return this->alpha = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,set_alpha,return )

Float NativeMedia_obj::get_alpha( ){
	HX_STACK_PUSH("NativeMedia::get_alpha","cocktail/port/base/NativeMedia.hx",254);
	HX_STACK_THIS(this);
	HX_STACK_LINE(254)
	return this->alpha;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_alpha,return )

::cocktail::core::geom::Matrix NativeMedia_obj::set_matrix( ::cocktail::core::geom::Matrix value){
	HX_STACK_PUSH("NativeMedia::set_matrix","cocktail/port/base/NativeMedia.hx",249);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(249)
	return this->matrix = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,set_matrix,return )

::cocktail::core::geom::Matrix NativeMedia_obj::get_matrix( ){
	HX_STACK_PUSH("NativeMedia::get_matrix","cocktail/port/base/NativeMedia.hx",244);
	HX_STACK_THIS(this);
	HX_STACK_LINE(244)
	return this->matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_matrix,return )

::cocktail::core::geom::RectangleVO NativeMedia_obj::set_viewport( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeMedia::set_viewport","cocktail/port/base/NativeMedia.hx",239);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(239)
	return this->viewport = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,set_viewport,return )

::cocktail::core::geom::RectangleVO NativeMedia_obj::get_viewport( ){
	HX_STACK_PUSH("NativeMedia::get_viewport","cocktail/port/base/NativeMedia.hx",234);
	HX_STACK_THIS(this);
	HX_STACK_LINE(234)
	return this->viewport;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_viewport,return )

Float NativeMedia_obj::set_volume( Float value){
	HX_STACK_PUSH("NativeMedia::set_volume","cocktail/port/base/NativeMedia.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(229)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,set_volume,return )

::String NativeMedia_obj::set_src( ::String value){
	HX_STACK_PUSH("NativeMedia::set_src","cocktail/port/base/NativeMedia.hx",225);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(225)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,set_src,return )

Float NativeMedia_obj::get_duration( ){
	HX_STACK_PUSH("NativeMedia::get_duration","cocktail/port/base/NativeMedia.hx",220);
	HX_STACK_THIS(this);
	HX_STACK_LINE(220)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_duration,return )

Dynamic NativeMedia_obj::get_width( ){
	HX_STACK_PUSH("NativeMedia::get_width","cocktail/port/base/NativeMedia.hx",215);
	HX_STACK_THIS(this);
	HX_STACK_LINE(215)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_width,return )

Dynamic NativeMedia_obj::get_height( ){
	HX_STACK_PUSH("NativeMedia::get_height","cocktail/port/base/NativeMedia.hx",210);
	HX_STACK_THIS(this);
	HX_STACK_LINE(210)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_height,return )

Float NativeMedia_obj::get_currentTime( ){
	HX_STACK_PUSH("NativeMedia::get_currentTime","cocktail/port/base/NativeMedia.hx",205);
	HX_STACK_THIS(this);
	HX_STACK_LINE(205)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_currentTime,return )

Float NativeMedia_obj::get_bytesLoaded( ){
	HX_STACK_PUSH("NativeMedia::get_bytesLoaded","cocktail/port/base/NativeMedia.hx",200);
	HX_STACK_THIS(this);
	HX_STACK_LINE(200)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_bytesLoaded,return )

Float NativeMedia_obj::get_bytesTotal( ){
	HX_STACK_PUSH("NativeMedia::get_bytesTotal","cocktail/port/base/NativeMedia.hx",195);
	HX_STACK_THIS(this);
	HX_STACK_LINE(195)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,get_bytesTotal,return )

Void NativeMedia_obj::onNativeLoadedMetaData( ){
{
		HX_STACK_PUSH("NativeMedia::onNativeLoadedMetaData","cocktail/port/base/NativeMedia.hx",181);
		HX_STACK_THIS(this);
		HX_STACK_LINE(181)
		if (((this->onLoadedMetaData_dyn() != null()))){
			HX_STACK_LINE(184)
			::cocktail::core::event::Event loaddedMetadataEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(loaddedMetadataEvent,"loaddedMetadataEvent");
			HX_STACK_LINE(185)
			loaddedMetadataEvent->initEvent(HX_CSTRING("loadedmetadata"),false,false);
			HX_STACK_LINE(186)
			this->onLoadedMetaData(loaddedMetadataEvent);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,onNativeLoadedMetaData,(void))

Void NativeMedia_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("NativeMedia::detach","cocktail/port/base/NativeMedia.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,detach,(void))

Void NativeMedia_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("NativeMedia::attach","cocktail/port/base/NativeMedia.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,attach,(void))

::String NativeMedia_obj::canPlayType( ::String type){
	HX_STACK_PUSH("NativeMedia::canPlayType","cocktail/port/base/NativeMedia.hx",146);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(146)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,canPlayType,return )

Void NativeMedia_obj::seek( Float time){
{
		HX_STACK_PUSH("NativeMedia::seek","cocktail/port/base/NativeMedia.hx",137);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeMedia_obj,seek,(void))

Void NativeMedia_obj::pause( ){
{
		HX_STACK_PUSH("NativeMedia::pause","cocktail/port/base/NativeMedia.hx",126);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,pause,(void))

Void NativeMedia_obj::play( ){
{
		HX_STACK_PUSH("NativeMedia::play","cocktail/port/base/NativeMedia.hx",118);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeMedia_obj,play,(void))


NativeMedia_obj::NativeMedia_obj()
{
}

void NativeMedia_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeMedia);
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(viewport,"viewport");
	HX_MARK_MEMBER_NAME(onLoadedMetaData,"onLoadedMetaData");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(currentTime,"currentTime");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(src,"src");
	HX_MARK_MEMBER_NAME(volume,"volume");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void NativeMedia_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	HX_VISIT_MEMBER_NAME(viewport,"viewport");
	HX_VISIT_MEMBER_NAME(onLoadedMetaData,"onLoadedMetaData");
	HX_VISIT_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_VISIT_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_VISIT_MEMBER_NAME(currentTime,"currentTime");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(src,"src");
	HX_VISIT_MEMBER_NAME(volume,"volume");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic NativeMedia_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return src; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"alpha") ) { return inCallProp ? get_alpha() : alpha; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return inCallProp ? get_matrix() : matrix; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"volume") ) { return volume; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"viewport") ) { return inCallProp ? get_viewport() : viewport; }
		if (HX_FIELD_EQ(inName,"duration") ) { return inCallProp ? get_duration() : duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"get_alpha") ) { return get_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_matrix") ) { return set_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"get_matrix") ) { return get_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"set_volume") ) { return set_volume_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return inCallProp ? get_bytesTotal() : bytesTotal; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"canPlayType") ) { return canPlayType_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return inCallProp ? get_bytesLoaded() : bytesLoaded; }
		if (HX_FIELD_EQ(inName,"currentTime") ) { return inCallProp ? get_currentTime() : currentTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_viewport") ) { return set_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_viewport") ) { return get_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_duration") ) { return get_duration_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_bytesTotal") ) { return get_bytesTotal_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_currentTime") ) { return get_currentTime_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bytesLoaded") ) { return get_bytesLoaded_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onLoadedMetaData") ) { return onLoadedMetaData; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"onNativeLoadedMetaData") ) { return onNativeLoadedMetaData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeMedia_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { if (inCallProp) return set_src(inValue);src=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return set_alpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { if (inCallProp) return set_matrix(inValue);matrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"volume") ) { if (inCallProp) return set_volume(inValue);volume=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"viewport") ) { if (inCallProp) return set_viewport(inValue);viewport=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentTime") ) { currentTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onLoadedMetaData") ) { onLoadedMetaData=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeMedia_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("viewport"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("currentTime"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("src"));
	outFields->push(HX_CSTRING("volume"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_alpha"),
	HX_CSTRING("get_alpha"),
	HX_CSTRING("set_matrix"),
	HX_CSTRING("get_matrix"),
	HX_CSTRING("set_viewport"),
	HX_CSTRING("get_viewport"),
	HX_CSTRING("set_volume"),
	HX_CSTRING("set_src"),
	HX_CSTRING("get_duration"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_currentTime"),
	HX_CSTRING("get_bytesLoaded"),
	HX_CSTRING("get_bytesTotal"),
	HX_CSTRING("onNativeLoadedMetaData"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("canPlayType"),
	HX_CSTRING("seek"),
	HX_CSTRING("pause"),
	HX_CSTRING("play"),
	HX_CSTRING("alpha"),
	HX_CSTRING("matrix"),
	HX_CSTRING("viewport"),
	HX_CSTRING("onLoadedMetaData"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("currentTime"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("src"),
	HX_CSTRING("volume"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeMedia_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeMedia_obj::__mClass,"__mClass");
};

Class NativeMedia_obj::__mClass;

void NativeMedia_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.NativeMedia"), hx::TCanCast< NativeMedia_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeMedia_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
