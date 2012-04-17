#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Std_obj::__construct()
{
	return null();
}

Std_obj::~Std_obj() { }

Dynamic Std_obj::__CreateEmpty() { return  new Std_obj; }
hx::ObjectPtr< Std_obj > Std_obj::__new()
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

Dynamic Std_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

bool Std_obj::is( Dynamic v,Dynamic t){
	HX_SOURCE_PUSH("Std_obj::is")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",27)
	return ::__instanceof(v,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

::String Std_obj::string( Dynamic s){
	HX_SOURCE_PUSH("Std_obj::string")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",31)
	return (  (((s == null()))) ? ::String(HX_CSTRING("null")) : ::String(s->toString()) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::_int( double x){
	HX_SOURCE_PUSH("Std_obj::int")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",35)
	return ::__int__(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,_int,return )

Dynamic Std_obj::parseInt( ::String x){
	HX_SOURCE_PUSH("Std_obj::parseInt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",39)
	return ::__hxcpp_parse_int(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

double Std_obj::parseFloat( ::String x){
	HX_SOURCE_PUSH("Std_obj::parseFloat")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",43)
	return ::__hxcpp_parse_float(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	HX_SOURCE_PUSH("Std_obj::random")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Std.hx",47)
	return hx::Mod(::rand(),x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,random,return )


Std_obj::Std_obj()
{
}

void Std_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Std);
	HX_MARK_END_CLASS();
}

Dynamic Std_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"is") ) { return is_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"int") ) { return _int_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"string") ) { return string_dyn(); }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"parseInt") ) { return parseInt_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parseFloat") ) { return parseFloat_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Std_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Std_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("is"),
	HX_CSTRING("string"),
	HX_CSTRING("int"),
	HX_CSTRING("parseInt"),
	HX_CSTRING("parseFloat"),
	HX_CSTRING("random"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Std_obj::__mClass;

void Std_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Std"), hx::TCanCast< Std_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Std_obj::__boot()
{
}

