#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif

Void Reflect_obj::__construct()
{
	return null();
}

Reflect_obj::~Reflect_obj() { }

Dynamic Reflect_obj::__CreateEmpty() { return  new Reflect_obj; }
hx::ObjectPtr< Reflect_obj > Reflect_obj::__new()
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

Dynamic Reflect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

bool Reflect_obj::hasField( Dynamic o,::String field){
	HX_SOURCE_PUSH("Reflect_obj::hasField")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",29)
	return (bool((o != null())) && bool(o->__HasField(field)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,hasField,return )

Dynamic Reflect_obj::field( Dynamic o,::String field){
	HX_SOURCE_PUSH("Reflect_obj::field")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",33)
	return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(field)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,field,return )

Void Reflect_obj::setField( Dynamic o,::String field,Dynamic value){
{
		HX_SOURCE_PUSH("Reflect_obj::setField")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",37)
		if (((o != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",39)
			o->__SetField(field,value);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,setField,(void))

Dynamic Reflect_obj::callMethod( Dynamic o,Dynamic func,Dynamic args){
	HX_SOURCE_PUSH("Reflect_obj::callMethod")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",43)
	if (((bool((func != null())) && bool((func->__GetType() == ::vtString))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",44)
		func = o->__Field(func);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",45)
	func->__SetThis(o);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",46)
	return func->__Run(args);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,callMethod,return )

Array< ::String > Reflect_obj::fields( Dynamic o){
	HX_SOURCE_PUSH("Reflect_obj::fields")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",50)
	if (((o == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",50)
		return Array_obj< ::String >::__new();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",51)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",52)
	o->__GetFields(a);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",53)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,fields,return )

bool Reflect_obj::isFunction( Dynamic f){
	HX_SOURCE_PUSH("Reflect_obj::isFunction")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",56)
	return (bool((f != null())) && bool((f->__GetType() == ::vtFunction)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isFunction,return )

int Reflect_obj::compare( Dynamic a,Dynamic b){
	HX_SOURCE_PUSH("Reflect_obj::compare")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",60)
	return (  (((a == b))) ? int((int)0) : int((  (((a > b))) ? int((int)1) : int((int)-1) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,compare,return )

bool Reflect_obj::compareMethods( Dynamic f1,Dynamic f2){
	HX_SOURCE_PUSH("Reflect_obj::compareMethods")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",65)
	if (((f1 == f2))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",66)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",67)
	if (((bool(!(::Reflect_obj::isFunction(f1))) || bool(!(::Reflect_obj::isFunction(f2)))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",68)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",69)
	return ::__hxcpp_same_closure(f1,f2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,compareMethods,return )

bool Reflect_obj::isObject( Dynamic v){
	HX_SOURCE_PUSH("Reflect_obj::isObject")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",73)
	if (((v == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",73)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",74)
	int t = v->__GetType();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",75)
	return (bool((bool((bool((t == ::vtObject)) || bool((t == ::vtClass)))) || bool((t == ::vtString)))) || bool((t == ::vtArray)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isObject,return )

bool Reflect_obj::deleteField( Dynamic o,::String f){
	HX_SOURCE_PUSH("Reflect_obj::deleteField")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",80)
	if (((o == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",80)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",81)
	return ::__hxcpp_anon_remove(o,f);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,deleteField,return )

Dynamic Reflect_obj::copy( Dynamic o){
	HX_SOURCE_PUSH("Reflect_obj::copy")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",85)
	if (((o == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",85)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",86)
	if (((o->__GetType() == ::vtString))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",86)
		return o;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",87)
	if (((o->__GetType() == ::vtArray))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",88)
		return o->__Field(HX_CSTRING("copy"))();
	}
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",89)
	Dynamic o2 = _Function_1_1::Block();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",90)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",90)
		int _g = (int)0;
		Array< ::String > _g1 = ::Reflect_obj::fields(o);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",90)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",90)
			::String f = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",90)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",91)
			if (((o2 != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",91)
				o2->__SetField(f,::Reflect_obj::field(o,f));
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",92)
	return o2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,copy,return )

Dynamic Reflect_obj::makeVarArgs( Dynamic f){
	HX_SOURCE_PUSH("Reflect_obj::makeVarArgs")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Reflect.hx",95)
	return ::__hxcpp_create_var_args(f);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,makeVarArgs,return )


Reflect_obj::Reflect_obj()
{
}

void Reflect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Reflect);
	HX_MARK_END_CLASS();
}

Dynamic Reflect_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"field") ) { return field_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { return fields_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasField") ) { return hasField_dyn(); }
		if (HX_FIELD_EQ(inName,"setField") ) { return setField_dyn(); }
		if (HX_FIELD_EQ(inName,"isObject") ) { return isObject_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callMethod") ) { return callMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"isFunction") ) { return isFunction_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"deleteField") ) { return deleteField_dyn(); }
		if (HX_FIELD_EQ(inName,"makeVarArgs") ) { return makeVarArgs_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"compareMethods") ) { return compareMethods_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Reflect_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Reflect_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("hasField"),
	HX_CSTRING("field"),
	HX_CSTRING("setField"),
	HX_CSTRING("callMethod"),
	HX_CSTRING("fields"),
	HX_CSTRING("isFunction"),
	HX_CSTRING("compare"),
	HX_CSTRING("compareMethods"),
	HX_CSTRING("isObject"),
	HX_CSTRING("deleteField"),
	HX_CSTRING("copy"),
	HX_CSTRING("makeVarArgs"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Reflect_obj::__mClass;

void Reflect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Reflect"), hx::TCanCast< Reflect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Reflect_obj::__boot()
{
}

