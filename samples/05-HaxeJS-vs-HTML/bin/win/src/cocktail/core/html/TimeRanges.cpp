#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_html_TimeRanges
#include <cocktail/core/html/TimeRanges.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void TimeRanges_obj::__construct(Dynamic ranges)
{
HX_STACK_PUSH("TimeRanges::new","cocktail/core/html/TimeRanges.hx",35);
{
	HX_STACK_LINE(35)
	this->_ranges = ranges;
}
;
	return null();
}

TimeRanges_obj::~TimeRanges_obj() { }

Dynamic TimeRanges_obj::__CreateEmpty() { return  new TimeRanges_obj; }
hx::ObjectPtr< TimeRanges_obj > TimeRanges_obj::__new(Dynamic ranges)
{  hx::ObjectPtr< TimeRanges_obj > result = new TimeRanges_obj();
	result->__construct(ranges);
	return result;}

Dynamic TimeRanges_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimeRanges_obj > result = new TimeRanges_obj();
	result->__construct(inArgs[0]);
	return result;}

int TimeRanges_obj::get_length( ){
	HX_STACK_PUSH("TimeRanges::get_length","cocktail/core/html/TimeRanges.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_LINE(66)
	return this->_ranges->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(TimeRanges_obj,get_length,return )

Float TimeRanges_obj::end( int index){
	HX_STACK_PUSH("TimeRanges::end","cocktail/core/html/TimeRanges.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(57)
	return this->_ranges->__GetItem(index)->__Field(HX_CSTRING("end"),true);
}


HX_DEFINE_DYNAMIC_FUNC1(TimeRanges_obj,end,return )

Float TimeRanges_obj::start( int index){
	HX_STACK_PUSH("TimeRanges::start","cocktail/core/html/TimeRanges.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(48)
	return this->_ranges->__GetItem(index)->__Field(HX_CSTRING("start"),true);
}


HX_DEFINE_DYNAMIC_FUNC1(TimeRanges_obj,start,return )


TimeRanges_obj::TimeRanges_obj()
{
}

void TimeRanges_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimeRanges);
	HX_MARK_MEMBER_NAME(_ranges,"_ranges");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void TimeRanges_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_ranges,"_ranges");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic TimeRanges_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return end_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_ranges") ) { return _ranges; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TimeRanges_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_ranges") ) { _ranges=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TimeRanges_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_ranges"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("end"),
	HX_CSTRING("start"),
	HX_CSTRING("_ranges"),
	HX_CSTRING("length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimeRanges_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TimeRanges_obj::__mClass,"__mClass");
};

Class TimeRanges_obj::__mClass;

void TimeRanges_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.TimeRanges"), hx::TCanCast< TimeRanges_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TimeRanges_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
