#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
namespace cpp{

Void Lib_obj::__construct()
{
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::load( ::String lib,::String prim,int nargs){
	HX_SOURCE_PUSH("Lib_obj::load")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",32)
	return ::__loadprim(lib,prim,nargs);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,load,return )

Dynamic Lib_obj::loadLazy( ::String lib,::String prim,int nargs){
	HX_SOURCE_PUSH("Lib_obj::loadLazy")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",44)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",45)
		return ::__loadprim(lib,prim,nargs);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",47)
				Dynamic e1 = Dynamic( Array_obj<Dynamic>::__new().Add(e));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",47)
				switch( (int)(nargs)){
					case (int)0: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",49)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",49)
						return  Dynamic(new _Function_3_1(e1));
					}
					;break;
					case (int)2: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(Dynamic _1,Dynamic _2){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",50)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC2((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",50)
						return  Dynamic(new _Function_3_1(e1));
					}
					;break;
					case (int)3: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",51)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC3((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",51)
						return  Dynamic(new _Function_3_1(e1));
					}
					;break;
					case (int)4: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",52)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC4((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",52)
						return  Dynamic(new _Function_3_1(e1));
					}
					;break;
					case (int)5: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4,Dynamic _5){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",53)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC5((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",53)
						return  Dynamic(new _Function_3_1(e1));
					}
					;break;
					default: {

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,e1)
						Void run(Dynamic _1){
{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",54)
								hx::Throw (e1->__GetItem((int)0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC1((void))

						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",54)
						return  Dynamic(new _Function_3_1(e1));
					}
				}
			}
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,loadLazy,return )

Void Lib_obj::rethrow( Dynamic inExp){
{
		HX_SOURCE_PUSH("Lib_obj::rethrow")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",59)
		hx::Throw (inExp);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,rethrow,(void))

Void Lib_obj::stringReference( Dynamic inExp){
{
		HX_SOURCE_PUSH("Lib_obj::stringReference")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",61)
		hx::Throw (inExp);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,stringReference,(void))

Void Lib_obj::print( Dynamic v){
{
		HX_SOURCE_PUSH("Lib_obj::print")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",66)
		::__hxcpp_print(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,print,(void))

Dynamic Lib_obj::haxeToNeko( Dynamic v){
	HX_SOURCE_PUSH("Lib_obj::haxeToNeko")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",74)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,haxeToNeko,return )

Dynamic Lib_obj::nekoToHaxe( Dynamic v){
	HX_SOURCE_PUSH("Lib_obj::nekoToHaxe")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",82)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,nekoToHaxe,return )

Void Lib_obj::println( Dynamic v){
{
		HX_SOURCE_PUSH("Lib_obj::println")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Lib.hx",88)
		::__hxcpp_println(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,println,(void))


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lib);
	HX_MARK_END_CLASS();
}

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rethrow") ) { return rethrow_dyn(); }
		if (HX_FIELD_EQ(inName,"println") ) { return println_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"loadLazy") ) { return loadLazy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"haxeToNeko") ) { return haxeToNeko_dyn(); }
		if (HX_FIELD_EQ(inName,"nekoToHaxe") ) { return nekoToHaxe_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stringReference") ) { return stringReference_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("load"),
	HX_CSTRING("loadLazy"),
	HX_CSTRING("rethrow"),
	HX_CSTRING("stringReference"),
	HX_CSTRING("print"),
	HX_CSTRING("haxeToNeko"),
	HX_CSTRING("nekoToHaxe"),
	HX_CSTRING("println"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
}

} // end namespace cpp
