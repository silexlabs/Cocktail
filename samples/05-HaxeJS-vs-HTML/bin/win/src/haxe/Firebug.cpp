#include <hxcpp.h>

#ifndef INCLUDED_haxe_Firebug
#include <haxe/Firebug.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace haxe{

Void Firebug_obj::__construct()
{
	return null();
}

Firebug_obj::~Firebug_obj() { }

Dynamic Firebug_obj::__CreateEmpty() { return  new Firebug_obj; }
hx::ObjectPtr< Firebug_obj > Firebug_obj::__new()
{  hx::ObjectPtr< Firebug_obj > result = new Firebug_obj();
	result->__construct();
	return result;}

Dynamic Firebug_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Firebug_obj > result = new Firebug_obj();
	result->__construct();
	return result;}

bool Firebug_obj::detect( ){
	HX_STACK_PUSH("Firebug::detect","C:\\Motion-Twin\\Haxe/std/haxe/Firebug.hx",29);
	HX_STACK_LINE(29)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Firebug_obj,detect,return )

Void Firebug_obj::redirectTraces( ){
{
		HX_STACK_PUSH("Firebug::redirectTraces","C:\\Motion-Twin\\Haxe/std/haxe/Firebug.hx",45);
		HX_STACK_LINE(45)
		::haxe::Log_obj::trace = ::haxe::Firebug_obj::trace_dyn();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Firebug_obj,redirectTraces,(void))

Void Firebug_obj::onError( ::String err,Array< ::String > stack){
{
		HX_STACK_PUSH("Firebug::onError","C:\\Motion-Twin\\Haxe/std/haxe/Firebug.hx",55);
		HX_STACK_ARG(err,"err");
		HX_STACK_ARG(stack,"stack");
		HX_STACK_LINE(56)
		::String buf = (err + HX_CSTRING("\n"));		HX_STACK_VAR(buf,"buf");
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			while(((_g < stack->length))){
				HX_STACK_LINE(57)
				::String s = stack->__get(_g);		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(57)
				++(_g);
				HX_STACK_LINE(58)
				hx::AddEq(buf,((HX_CSTRING("Called from ") + s) + HX_CSTRING("\n")));
			}
		}
		HX_STACK_LINE(59)
		::haxe::Firebug_obj::trace(buf,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Firebug_obj,onError,(void))

Void Firebug_obj::trace( Dynamic v,Dynamic inf){
{
		HX_STACK_PUSH("Firebug::trace","C:\\Motion-Twin\\Haxe/std/haxe/Firebug.hx",65);
		HX_STACK_ARG(v,"v");
		HX_STACK_ARG(inf,"inf");
		HX_STACK_LINE(66)
		::String type = (  (((bool((inf != null())) && bool((inf->__Field(HX_CSTRING("customParams"),true) != null()))))) ? ::String(inf->__Field(HX_CSTRING("customParams"),true)->__GetItem((int)0)) : ::String(null()) );		HX_STACK_VAR(type,"type");
		HX_STACK_LINE(67)
		if (((bool((bool((bool((type != HX_CSTRING("warn"))) && bool((type != HX_CSTRING("info"))))) && bool((type != HX_CSTRING("debug"))))) && bool((type != HX_CSTRING("error")))))){
			HX_STACK_LINE(68)
			type = (  (((inf == null()))) ? ::String(HX_CSTRING("error")) : ::String(HX_CSTRING("log")) );
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Firebug_obj,trace,(void))


Firebug_obj::Firebug_obj()
{
}

void Firebug_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Firebug);
	HX_MARK_END_CLASS();
}

void Firebug_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Firebug_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { return trace_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detect") ) { return detect_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { return onError_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"redirectTraces") ) { return redirectTraces_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Firebug_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Firebug_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("detect"),
	HX_CSTRING("redirectTraces"),
	HX_CSTRING("onError"),
	HX_CSTRING("trace"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Firebug_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Firebug_obj::__mClass,"__mClass");
};

Class Firebug_obj::__mClass;

void Firebug_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Firebug"), hx::TCanCast< Firebug_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Firebug_obj::__boot()
{
}

} // end namespace haxe
