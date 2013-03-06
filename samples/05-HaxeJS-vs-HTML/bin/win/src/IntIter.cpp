#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif

Void IntIter_obj::__construct(int min,int max)
{
HX_STACK_PUSH("IntIter::new","C:\\Motion-Twin\\Haxe/std/IntIter.hx",38);
{
	HX_STACK_LINE(39)
	this->min = min;
	HX_STACK_LINE(40)
	this->max = max;
}
;
	return null();
}

IntIter_obj::~IntIter_obj() { }

Dynamic IntIter_obj::__CreateEmpty() { return  new IntIter_obj; }
hx::ObjectPtr< IntIter_obj > IntIter_obj::__new(int min,int max)
{  hx::ObjectPtr< IntIter_obj > result = new IntIter_obj();
	result->__construct(min,max);
	return result;}

Dynamic IntIter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntIter_obj > result = new IntIter_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int IntIter_obj::next( ){
	HX_STACK_PUSH("IntIter::next","C:\\Motion-Twin\\Haxe/std/IntIter.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_LINE(53)
	return (this->min)++;
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,next,return )

bool IntIter_obj::hasNext( ){
	HX_STACK_PUSH("IntIter::hasNext","C:\\Motion-Twin\\Haxe/std/IntIter.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_LINE(46)
	return (this->min < this->max);
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,hasNext,return )


IntIter_obj::IntIter_obj()
{
}

void IntIter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IntIter);
	HX_MARK_MEMBER_NAME(max,"max");
	HX_MARK_MEMBER_NAME(min,"min");
	HX_MARK_END_CLASS();
}

void IntIter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(max,"max");
	HX_VISIT_MEMBER_NAME(min,"min");
}

Dynamic IntIter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"max") ) { return max; }
		if (HX_FIELD_EQ(inName,"min") ) { return min; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IntIter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"max") ) { max=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"min") ) { min=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IntIter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("max"));
	outFields->push(HX_CSTRING("min"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("next"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("max"),
	HX_CSTRING("min"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IntIter_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IntIter_obj::__mClass,"__mClass");
};

Class IntIter_obj::__mClass;

void IntIter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("IntIter"), hx::TCanCast< IntIter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IntIter_obj::__boot()
{
}

