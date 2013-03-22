#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void StringBuf_obj::__construct()
{
HX_STACK_PUSH("StringBuf::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/StringBuf.hx",31);
{
	HX_STACK_LINE(31)
	this->b = Dynamic( Array_obj<Dynamic>::__new() );
}
;
	return null();
}

StringBuf_obj::~StringBuf_obj() { }

Dynamic StringBuf_obj::__CreateEmpty() { return  new StringBuf_obj; }
hx::ObjectPtr< StringBuf_obj > StringBuf_obj::__new()
{  hx::ObjectPtr< StringBuf_obj > result = new StringBuf_obj();
	result->__construct();
	return result;}

Dynamic StringBuf_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringBuf_obj > result = new StringBuf_obj();
	result->__construct();
	return result;}

::String StringBuf_obj::toString( ){
	HX_STACK_PUSH("StringBuf::toString","C:\\Motion-Twin\\Haxe/std/cpp/_std/StringBuf.hx",47);
	HX_STACK_THIS(this);
	HX_STACK_LINE(47)
	return this->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(StringBuf_obj,toString,return )

Void StringBuf_obj::addChar( int c){
{
		HX_STACK_PUSH("StringBuf::addChar","C:\\Motion-Twin\\Haxe/std/cpp/_std/StringBuf.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(43)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,addChar,(void))

Void StringBuf_obj::addSub( ::String s,int pos,Dynamic len){
{
		HX_STACK_PUSH("StringBuf::addSub","C:\\Motion-Twin\\Haxe/std/cpp/_std/StringBuf.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(39)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"),true)) = s.substr(pos,len);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StringBuf_obj,addSub,(void))

Void StringBuf_obj::add( Dynamic x){
{
		HX_STACK_PUSH("StringBuf::add","C:\\Motion-Twin\\Haxe/std/cpp/_std/StringBuf.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(35)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"),true)) = x;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,add,(void))


StringBuf_obj::StringBuf_obj()
{
}

void StringBuf_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringBuf);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void StringBuf_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic StringBuf_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"addSub") ) { return addSub_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addChar") ) { return addChar_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StringBuf_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StringBuf_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("addChar"),
	HX_CSTRING("addSub"),
	HX_CSTRING("add"),
	HX_CSTRING("b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StringBuf_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringBuf_obj::__mClass,"__mClass");
};

Class StringBuf_obj::__mClass;

void StringBuf_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringBuf"), hx::TCanCast< StringBuf_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StringBuf_obj::__boot()
{
}

