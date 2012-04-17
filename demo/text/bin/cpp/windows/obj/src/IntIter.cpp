#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif

Void IntIter_obj::__construct(int min,int max)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/IntIter.hx",39)
	this->min = min;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/IntIter.hx",40)
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

bool IntIter_obj::hasNext( ){
	HX_SOURCE_PUSH("IntIter_obj::hasNext")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/IntIter.hx",46)
	return (this->min < this->max);
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,hasNext,return )

int IntIter_obj::next( ){
	HX_SOURCE_PUSH("IntIter_obj::next")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/IntIter.hx",53)
	return (this->min)++;
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,next,return )


IntIter_obj::IntIter_obj()
{
}

void IntIter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IntIter);
	HX_MARK_MEMBER_NAME(min,"min");
	HX_MARK_MEMBER_NAME(max,"max");
	HX_MARK_END_CLASS();
}

Dynamic IntIter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return min; }
		if (HX_FIELD_EQ(inName,"max") ) { return max; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IntIter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { min=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"max") ) { max=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IntIter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("min"));
	outFields->push(HX_CSTRING("max"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("min"),
	HX_CSTRING("max"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class IntIter_obj::__mClass;

void IntIter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("IntIter"), hx::TCanCast< IntIter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IntIter_obj::__boot()
{
}

