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
	HX_STACK_PUSH("Std::is","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",27);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(27)
	return ::__instanceof(v,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

::String Std_obj::string( Dynamic s){
	HX_STACK_PUSH("Std::string","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",31);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(31)
	return (  (((s == null()))) ? ::String(HX_CSTRING("null")) : ::String(s->toString()) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::_int( Float x){
	HX_STACK_PUSH("Std::int","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",35);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(35)
	return ::__int__(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,_int,return )

Dynamic Std_obj::parseInt( ::String x){
	HX_STACK_PUSH("Std::parseInt","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",39);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(39)
	return ::__hxcpp_parse_int(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

Float Std_obj::parseFloat( ::String x){
	HX_STACK_PUSH("Std::parseFloat","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",43);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(43)
	return ::__hxcpp_parse_float(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	HX_STACK_PUSH("Std::random","C:\\Motion-Twin\\Haxe/std/cpp/_std/Std.hx",47);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(47)
	return ::__hxcpp_irand(x);
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

void Std_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Std_obj::__Field(const ::String &inName,bool inCallProp)
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
	return super::__Field(inName,inCallProp);
}

Dynamic Std_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_MARK_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

Class Std_obj::__mClass;

void Std_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Std"), hx::TCanCast< Std_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Std_obj::__boot()
{
}

