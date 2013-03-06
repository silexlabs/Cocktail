#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_MediaList
#include <cocktail/core/css/MediaList.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void MediaList_obj::__construct()
{
HX_STACK_PUSH("MediaList::new","cocktail/core/css/MediaList.hx",17);
{
}
;
	return null();
}

MediaList_obj::~MediaList_obj() { }

Dynamic MediaList_obj::__CreateEmpty() { return  new MediaList_obj; }
hx::ObjectPtr< MediaList_obj > MediaList_obj::__new()
{  hx::ObjectPtr< MediaList_obj > result = new MediaList_obj();
	result->__construct();
	return result;}

Dynamic MediaList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MediaList_obj > result = new MediaList_obj();
	result->__construct();
	return result;}

Void MediaList_obj::deleteMedium( ::String medium){
{
		HX_STACK_PUSH("MediaList::deleteMedium","cocktail/core/css/MediaList.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_ARG(medium,"medium");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaList_obj,deleteMedium,(void))

Void MediaList_obj::appendMedium( ::String medium){
{
		HX_STACK_PUSH("MediaList::appendMedium","cocktail/core/css/MediaList.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(medium,"medium");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaList_obj,appendMedium,(void))

::String MediaList_obj::item( int index){
	HX_STACK_PUSH("MediaList::item","cocktail/core/css/MediaList.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(22)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaList_obj,item,return )


MediaList_obj::MediaList_obj()
{
}

void MediaList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MediaList);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(mediaText,"mediaText");
	HX_MARK_END_CLASS();
}

void MediaList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(mediaText,"mediaText");
}

Dynamic MediaList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"item") ) { return item_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mediaText") ) { return mediaText; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"deleteMedium") ) { return deleteMedium_dyn(); }
		if (HX_FIELD_EQ(inName,"appendMedium") ) { return appendMedium_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MediaList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mediaText") ) { mediaText=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MediaList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("mediaText"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("deleteMedium"),
	HX_CSTRING("appendMedium"),
	HX_CSTRING("item"),
	HX_CSTRING("length"),
	HX_CSTRING("mediaText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MediaList_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MediaList_obj::__mClass,"__mClass");
};

Class MediaList_obj::__mClass;

void MediaList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.MediaList"), hx::TCanCast< MediaList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MediaList_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
