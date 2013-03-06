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
	HX_STACK_PUSH("Type::getClass","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",39);
	HX_STACK_ARG(o,"o");
	HX_STACK_LINE(40)
	if (((bool((o == null())) || bool(!(::Reflect_obj::isObject(o)))))){
		HX_STACK_LINE(40)
		return null();
	}
	HX_STACK_LINE(41)
	Dynamic c = o->__GetClass();		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(42)
	::String _switch_1 = (c->toString());
	if (  ( _switch_1==HX_CSTRING("__Anon"))){
		HX_STACK_LINE(44)
		return null();
	}
	else if (  ( _switch_1==HX_CSTRING("Class"))){
		HX_STACK_LINE(45)
		return null();
	}
	HX_STACK_LINE(47)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClass,return )

::Enum Type_obj::getEnum( Dynamic o){
	HX_STACK_PUSH("Type::getEnum","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",50);
	HX_STACK_ARG(o,"o");
	HX_STACK_LINE(51)
	if (((o == null()))){
		HX_STACK_LINE(51)
		return null();
	}
	HX_STACK_LINE(52)
	return o->__GetClass();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnum,return )

::Class Type_obj::getSuperClass( ::Class c){
	HX_STACK_PUSH("Type::getSuperClass","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",56);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(56)
	return c->GetSuper();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getSuperClass,return )

::String Type_obj::getClassName( ::Class c){
	HX_STACK_PUSH("Type::getClassName","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",60);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(61)
	if (((c == null()))){
		HX_STACK_LINE(62)
		return null();
	}
	HX_STACK_LINE(63)
	return c->mName;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassName,return )

::String Type_obj::getEnumName( ::Enum e){
	HX_STACK_PUSH("Type::getEnumName","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",66);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(66)
	return e->__ToString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumName,return )

::Class Type_obj::resolveClass( ::String name){
	HX_STACK_PUSH("Type::resolveClass","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",70);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(71)
	::Class result = ::Class_obj::Resolve(name);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(72)
	if (((bool((result != null())) && bool(result->__IsEnum())))){
		HX_STACK_LINE(73)
		return null();
	}
	HX_STACK_LINE(74)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveClass,return )

::Enum Type_obj::resolveEnum( ::String name){
	HX_STACK_PUSH("Type::resolveEnum","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",77);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(78)
	::Class result = ::Class_obj::Resolve(name);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(79)
	if (((bool((result != null())) && bool(!(result->__IsEnum()))))){
		HX_STACK_LINE(80)
		return null();
	}
	HX_STACK_LINE(81)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveEnum,return )

Dynamic Type_obj::createInstance( ::Class cl,Dynamic args){
	HX_STACK_PUSH("Type::createInstance","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",84);
	HX_STACK_ARG(cl,"cl");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(85)
	if (((cl != null()))){
		HX_STACK_LINE(86)
		return cl->mConstructArgs(args);
	}
	HX_STACK_LINE(87)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,createInstance,return )

Dynamic Type_obj::createEmptyInstance( ::Class cl){
	HX_STACK_PUSH("Type::createEmptyInstance","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",90);
	HX_STACK_ARG(cl,"cl");
	HX_STACK_LINE(90)
	return cl->mConstructEmpty();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,createEmptyInstance,return )

Dynamic Type_obj::createEnum( ::Enum e,::String constr,Dynamic params){
	HX_STACK_PUSH("Type::createEnum","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",94);
	HX_STACK_ARG(e,"e");
	HX_STACK_ARG(constr,"constr");
	HX_STACK_ARG(params,"params");
	HX_STACK_LINE(95)
	if (((e->mConstructEnum != null()))){
		HX_STACK_LINE(96)
		return e->mConstructEnum(constr,params);
	}
	HX_STACK_LINE(97)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnum,return )

Dynamic Type_obj::createEnumIndex( ::Enum e,int index,Dynamic params){
	HX_STACK_PUSH("Type::createEnumIndex","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",100);
	HX_STACK_ARG(e,"e");
	HX_STACK_ARG(index,"index");
	HX_STACK_ARG(params,"params");
	HX_STACK_LINE(101)
	::String c = ::Type_obj::getEnumConstructs(e)->__get(index);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(102)
	if (((c == null()))){
		HX_STACK_LINE(102)
		hx::Throw ((index + HX_CSTRING(" is not a valid enum constructor index")));
	}
	HX_STACK_LINE(103)
	return ::Type_obj::createEnum(e,c,params);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnumIndex,return )

Array< ::String > Type_obj::getInstanceFields( ::Class c){
	HX_STACK_PUSH("Type::getInstanceFields","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",106);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(106)
	return c->GetInstanceFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getInstanceFields,return )

Array< ::String > Type_obj::getClassFields( ::Class c){
	HX_STACK_PUSH("Type::getClassFields","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",110);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(110)
	return c->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassFields,return )

Array< ::String > Type_obj::getEnumConstructs( ::Enum e){
	HX_STACK_PUSH("Type::getEnumConstructs","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",114);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(114)
	return e->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumConstructs,return )

::ValueType Type_obj::_typeof( Dynamic v){
	HX_STACK_PUSH("Type::typeof","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",118);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(119)
	if (((v == null()))){
		HX_STACK_LINE(119)
		return ::ValueType_obj::TNull_dyn();
	}
	HX_STACK_LINE(120)
	int t = v->__GetType();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(121)
	int _switch_2 = (t);
	if (  ( _switch_2==::vtBool)){
		HX_STACK_LINE(123)
		return ::ValueType_obj::TBool_dyn();
	}
	else if (  ( _switch_2==::vtInt)){
		HX_STACK_LINE(124)
		return ::ValueType_obj::TInt_dyn();
	}
	else if (  ( _switch_2==::vtFloat)){
		HX_STACK_LINE(125)
		return ::ValueType_obj::TFloat_dyn();
	}
	else if (  ( _switch_2==::vtFunction)){
		HX_STACK_LINE(126)
		return ::ValueType_obj::TFunction_dyn();
	}
	else if (  ( _switch_2==::vtObject)){
		HX_STACK_LINE(127)
		return ::ValueType_obj::TObject_dyn();
	}
	else if (  ( _switch_2==::vtEnum)){
		HX_STACK_LINE(128)
		return ::ValueType_obj::TEnum(v->__GetClass());
	}
	else  {
		HX_STACK_LINE(129)
		return ::ValueType_obj::TClass(v->__GetClass());
	}
;
;
	HX_STACK_LINE(121)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,_typeof,return )

bool Type_obj::enumEq( Dynamic a,Dynamic b){
	HX_STACK_PUSH("Type::enumEq","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",134);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(134)
	return (a == b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,enumEq,return )

::String Type_obj::enumConstructor( Dynamic e){
	HX_STACK_PUSH("Type::enumConstructor","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",138);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(138)
	return e->__Tag();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumConstructor,return )

Dynamic Type_obj::enumParameters( Dynamic e){
	HX_STACK_PUSH("Type::enumParameters","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",142);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(143)
	Dynamic result = e->__EnumParams();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(144)
	return (  (((result == null()))) ? Dynamic(Dynamic( Array_obj<Dynamic>::__new())) : Dynamic(result) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumParameters,return )

int Type_obj::enumIndex( Dynamic e){
	HX_STACK_PUSH("Type::enumIndex","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",147);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(147)
	return e->__Index();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumIndex,return )

Dynamic Type_obj::allEnums( ::Enum e){
	HX_STACK_PUSH("Type::allEnums","C:\\Motion-Twin\\Haxe/std/cpp/_std/Type.hx",151);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(152)
	Array< ::String > names = e->GetClassFields();		HX_STACK_VAR(names,"names");
	HX_STACK_LINE(153)
	Dynamic enums = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(enums,"enums");
	HX_STACK_LINE(154)
	{
		HX_STACK_LINE(154)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(154)
		while(((_g < names->length))){
			HX_STACK_LINE(154)
			::String name = names->__get(_g);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(154)
			++(_g);
			HX_STACK_LINE(156)
			try{
				HX_STACK_LINE(157)
				Dynamic result = e->mConstructEnum(name,null());		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(158)
				enums->__Field(HX_CSTRING("push"),true)(result);
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::String >() ){
					::String invalidArgCount = __e;{
					}
				}
				else throw(__e);
			}
		}
	}
	HX_STACK_LINE(162)
	return enums;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,allEnums,return )


Type_obj::Type_obj()
{
}

void Type_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Type);
	HX_MARK_END_CLASS();
}

void Type_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Type_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"allEnums") ) { return allEnums_dyn(); }
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
	return super::__Field(inName,inCallProp);
}

Dynamic Type_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("allEnums"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Type_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Type_obj::__mClass,"__mClass");
};

Class Type_obj::__mClass;

void Type_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Type"), hx::TCanCast< Type_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Type_obj::__boot()
{
}

