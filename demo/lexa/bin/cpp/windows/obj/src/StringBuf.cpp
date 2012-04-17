#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void StringBuf_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringBuf.hx",35)
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

Void StringBuf_obj::add( Dynamic x){
{
		HX_SOURCE_PUSH("StringBuf_obj::add")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringBuf.hx",46)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"))) = x;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,add,(void))

Void StringBuf_obj::addSub( ::String s,int pos,Dynamic len){
{
		HX_SOURCE_PUSH("StringBuf_obj::addSub")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringBuf.hx",59)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"))) = s.substr(pos,len);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StringBuf_obj,addSub,(void))

Void StringBuf_obj::addChar( int c){
{
		HX_SOURCE_PUSH("StringBuf_obj::addChar")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringBuf.hx",75)
		hx::IndexRef((this->b).mPtr,this->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,addChar,(void))

::String StringBuf_obj::toString( ){
	HX_SOURCE_PUSH("StringBuf_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringBuf.hx",89)
	return this->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(StringBuf_obj,toString,return )


StringBuf_obj::StringBuf_obj()
{
}

void StringBuf_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringBuf);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

Dynamic StringBuf_obj::__Field(const ::String &inName)
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
	return super::__Field(inName);
}

Dynamic StringBuf_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StringBuf_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("add"),
	HX_CSTRING("addSub"),
	HX_CSTRING("addChar"),
	HX_CSTRING("toString"),
	HX_CSTRING("b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StringBuf_obj::__mClass;

void StringBuf_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringBuf"), hx::TCanCast< StringBuf_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StringBuf_obj::__boot()
{
}

