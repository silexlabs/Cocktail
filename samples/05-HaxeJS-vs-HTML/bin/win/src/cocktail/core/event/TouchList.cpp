#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_TouchList
#include <cocktail/core/event/TouchList.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void TouchList_obj::__construct(Dynamic touches)
{
HX_STACK_PUSH("TouchList::new","cocktail/core/event/TouchList.hx",32);
{
	HX_STACK_LINE(32)
	this->_touches = touches;
}
;
	return null();
}

TouchList_obj::~TouchList_obj() { }

Dynamic TouchList_obj::__CreateEmpty() { return  new TouchList_obj; }
hx::ObjectPtr< TouchList_obj > TouchList_obj::__new(Dynamic touches)
{  hx::ObjectPtr< TouchList_obj > result = new TouchList_obj();
	result->__construct(touches);
	return result;}

Dynamic TouchList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchList_obj > result = new TouchList_obj();
	result->__construct(inArgs[0]);
	return result;}

int TouchList_obj::get_length( ){
	HX_STACK_PUSH("TouchList::get_length","cocktail/core/event/TouchList.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(73)
	return this->_touches->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(TouchList_obj,get_length,return )

Dynamic TouchList_obj::identifiedTouch( int identifier){
	HX_STACK_PUSH("TouchList::identifiedTouch","cocktail/core/event/TouchList.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(identifier,"identifier");
	HX_STACK_LINE(54)
	{
		HX_STACK_LINE(54)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->get_length();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		while(((_g1 < _g))){
			HX_STACK_LINE(54)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(56)
			if (((this->_touches->__GetItem(i)->__Field(HX_CSTRING("identifier"),true) == identifier))){
				HX_STACK_LINE(57)
				return this->_touches->__GetItem(i);
			}
		}
	}
	HX_STACK_LINE(62)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchList_obj,identifiedTouch,return )

Dynamic TouchList_obj::item( int index){
	HX_STACK_PUSH("TouchList::item","cocktail/core/event/TouchList.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(44)
	return this->_touches->__GetItem(index);
}


HX_DEFINE_DYNAMIC_FUNC1(TouchList_obj,item,return )


TouchList_obj::TouchList_obj()
{
}

void TouchList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchList);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(_touches,"_touches");
	HX_MARK_END_CLASS();
}

void TouchList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(_touches,"_touches");
}

Dynamic TouchList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"item") ) { return item_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_touches") ) { return _touches; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"identifiedTouch") ) { return identifiedTouch_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_touches") ) { _touches=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("_touches"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("identifiedTouch"),
	HX_CSTRING("item"),
	HX_CSTRING("length"),
	HX_CSTRING("_touches"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchList_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchList_obj::__mClass,"__mClass");
};

Class TouchList_obj::__mClass;

void TouchList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.TouchList"), hx::TCanCast< TouchList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchList_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
