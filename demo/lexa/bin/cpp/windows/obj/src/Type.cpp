#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif

Void Type_obj::__construct()
{
	return null();
}

Type_obj::~Type_obj() { }

Dynamic Type_obj::__CreateEmpty() { return  new Type_obj; }
hx::ObjectPtr< Type_obj > Type_obj::__new()
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

Dynamic Type_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

::Class Type_obj::getClass( Dynamic o){
	HX_SOURCE_PUSH("Type_obj::getClass")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",40)
	if (((bool((o == null())) || bool(!(::Reflect_obj::isObject(o)))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",40)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",41)
	Dynamic c = o->__GetClass();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",42)
	::String _switch_1 = (c->toString());
	if (  ( _switch_1==HX_CSTRING("__Anon"))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",44)
		return null();
	}
	else if (  ( _switch_1==HX_CSTRING("Class"))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",45)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",47)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClass,return )

::Enum Type_obj::getEnum( Dynamic o){
	HX_SOURCE_PUSH("Type_obj::getEnum")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",51)
	if (((o == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",51)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",52)
	return o->__GetClass();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnum,return )

::Class Type_obj::getSuperClass( ::Class c){
	HX_SOURCE_PUSH("Type_obj::getSuperClass")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",56)
	return c->GetSuper();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getSuperClass,return )

::String Type_obj::getClassName( ::Class c){
	HX_SOURCE_PUSH("Type_obj::getClassName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",61)
	if (((c == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",62)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",63)
	return c->mName;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassName,return )

::String Type_obj::getEnumName( ::Enum e){
	HX_SOURCE_PUSH("Type_obj::getEnumName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",66)
	return e->__ToString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumName,return )

::Class Type_obj::resolveClass( ::String name){
	HX_SOURCE_PUSH("Type_obj::resolveClass")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",71)
	::Class result = ::Class_obj::Resolve(name);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",72)
	if (((bool((result != null())) && bool(result->__IsEnum())))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",73)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",74)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveClass,return )

::Enum Type_obj::resolveEnum( ::String name){
	HX_SOURCE_PUSH("Type_obj::resolveEnum")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",78)
	::Class result = ::Class_obj::Resolve(name);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",79)
	if (((bool((result != null())) && bool(!(result->__IsEnum()))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",80)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",81)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveEnum,return )

Dynamic Type_obj::createInstance( ::Class cl,Dynamic args){
	HX_SOURCE_PUSH("Type_obj::createInstance")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",85)
	if (((cl != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",86)
		return cl->mConstructArgs(args);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",87)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,createInstance,return )

Dynamic Type_obj::createEmptyInstance( ::Class cl){
	HX_SOURCE_PUSH("Type_obj::createEmptyInstance")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",90)
	return cl->mConstructEmpty();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,createEmptyInstance,return )

Dynamic Type_obj::createEnum( ::Enum e,::String constr,Dynamic params){
	HX_SOURCE_PUSH("Type_obj::createEnum")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",95)
	if (((e->mConstructEnum != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",96)
		return e->mConstructEnum(constr,params);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",97)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnum,return )

Dynamic Type_obj::createEnumIndex( ::Enum e,int index,Dynamic params){
	HX_SOURCE_PUSH("Type_obj::createEnumIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",101)
	::String c = ::Type_obj::getEnumConstructs(e)->__get(index);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",102)
	if (((c == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",102)
		hx::Throw ((index + HX_CSTRING(" is not a valid enum constructor index")));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",103)
	return ::Type_obj::createEnum(e,c,params);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnumIndex,return )

Array< ::String > Type_obj::getInstanceFields( ::Class c){
	HX_SOURCE_PUSH("Type_obj::getInstanceFields")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",106)
	return c->GetInstanceFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getInstanceFields,return )

Array< ::String > Type_obj::getClassFields( ::Class c){
	HX_SOURCE_PUSH("Type_obj::getClassFields")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",110)
	return c->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassFields,return )

Array< ::String > Type_obj::getEnumConstructs( ::Enum e){
	HX_SOURCE_PUSH("Type_obj::getEnumConstructs")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",114)
	return e->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumConstructs,return )

::ValueType Type_obj::_typeof( Dynamic v){
	HX_SOURCE_PUSH("Type_obj::typeof")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",119)
	if (((v == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",119)
		return ::ValueType_obj::TNull_dyn();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",120)
	int t = v->__GetType();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",121)
	int _switch_2 = (t);
	if (  ( _switch_2==::vtBool)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",123)
		return ::ValueType_obj::TBool_dyn();
	}
	else if (  ( _switch_2==::vtInt)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",124)
		return ::ValueType_obj::TInt_dyn();
	}
	else if (  ( _switch_2==::vtFloat)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",125)
		return ::ValueType_obj::TFloat_dyn();
	}
	else if (  ( _switch_2==::vtFunction)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",126)
		return ::ValueType_obj::TFunction_dyn();
	}
	else if (  ( _switch_2==::vtObject)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",127)
		return ::ValueType_obj::TObject_dyn();
	}
	else if (  ( _switch_2==::vtEnum)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",128)
		return ::ValueType_obj::TEnum(v->__GetClass());
	}
	else  {
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",129)
		return ::ValueType_obj::TClass(v->__GetClass());
	}
;
;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,_typeof,return )

bool Type_obj::enumEq( Dynamic a,Dynamic b){
	HX_SOURCE_PUSH("Type_obj::enumEq")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",134)
	return (a == b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,enumEq,return )

::String Type_obj::enumConstructor( Dynamic e){
	HX_SOURCE_PUSH("Type_obj::enumConstructor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",138)
	return e->__Tag();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumConstructor,return )

Dynamic Type_obj::enumParameters( Dynamic e){
	HX_SOURCE_PUSH("Type_obj::enumParameters")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",143)
	Dynamic result = e->__EnumParams();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",144)
	return (  (((result == null()))) ? Dynamic(Dynamic( Array_obj<Dynamic>::__new())) : Dynamic(result) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumParameters,return )

int Type_obj::enumIndex( Dynamic e){
	HX_SOURCE_PUSH("Type_obj::enumIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Type.hx",147)
	return e->__Index();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumIndex,return )


Type_obj::Type_obj()
{
}

void Type_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Type);
	HX_MARK_END_CLASS();
}

Dynamic Type_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"typeof") ) { return _typeof_dyn(); }
		if (HX_FIELD_EQ(inName,"enumEq") ) { return enumEq_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getEnum") ) { return getEnum_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getClass") ) { return getClass_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"enumIndex") ) { return enumIndex_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"createEnum") ) { return createEnum_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getEnumName") ) { return getEnumName_dyn(); }
		if (HX_FIELD_EQ(inName,"resolveEnum") ) { return resolveEnum_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getClassName") ) { return getClassName_dyn(); }
		if (HX_FIELD_EQ(inName,"resolveClass") ) { return resolveClass_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getSuperClass") ) { return getSuperClass_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createInstance") ) { return createInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"getClassFields") ) { return getClassFields_dyn(); }
		if (HX_FIELD_EQ(inName,"enumParameters") ) { return enumParameters_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"createEnumIndex") ) { return createEnumIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"enumConstructor") ) { return enumConstructor_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getInstanceFields") ) { return getInstanceFields_dyn(); }
		if (HX_FIELD_EQ(inName,"getEnumConstructs") ) { return getEnumConstructs_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createEmptyInstance") ) { return createEmptyInstance_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Type_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Type_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getClass"),
	HX_CSTRING("getEnum"),
	HX_CSTRING("getSuperClass"),
	HX_CSTRING("getClassName"),
	HX_CSTRING("getEnumName"),
	HX_CSTRING("resolveClass"),
	HX_CSTRING("resolveEnum"),
	HX_CSTRING("createInstance"),
	HX_CSTRING("createEmptyInstance"),
	HX_CSTRING("createEnum"),
	HX_CSTRING("createEnumIndex"),
	HX_CSTRING("getInstanceFields"),
	HX_CSTRING("getClassFields"),
	HX_CSTRING("getEnumConstructs"),
	HX_CSTRING("typeof"),
	HX_CSTRING("enumEq"),
	HX_CSTRING("enumConstructor"),
	HX_CSTRING("enumParameters"),
	HX_CSTRING("enumIndex"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Type_obj::__mClass;

void Type_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Type"), hx::TCanCast< Type_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Type_obj::__boot()
{
}

