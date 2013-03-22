#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_sys_io_Process
#include <sys/io/Process.h>
#endif
namespace neash{

Void Loader_obj::__construct()
{
	return null();
}

Loader_obj::~Loader_obj() { }

Dynamic Loader_obj::__CreateEmpty() { return  new Loader_obj; }
hx::ObjectPtr< Loader_obj > Loader_obj::__new()
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

Dynamic Loader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

bool Loader_obj::moduleInit;

::String Loader_obj::moduleName;

::String Loader_obj::findHaxeLib( ::String inLib){
	HX_STACK_PUSH("Loader::findHaxeLib","neash/Loader.hx",31);
	HX_STACK_ARG(inLib,"inLib");
	HX_STACK_LINE(32)
	try{
		HX_STACK_LINE(34)
		::sys::io::Process proc = ::sys::io::Process_obj::__new(HX_CSTRING("haxelib"),Array_obj< ::String >::__new().Add(HX_CSTRING("path")).Add(inLib));		HX_STACK_VAR(proc,"proc");
		HX_STACK_LINE(35)
		if (((proc != null()))){
			HX_STACK_LINE(37)
			::haxe::io::Input stream = proc->_stdout;		HX_STACK_VAR(stream,"stream");
			HX_STACK_LINE(38)
			try{
				HX_STACK_LINE(39)
				while((true)){
					HX_STACK_LINE(42)
					::String s = stream->readLine();		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(43)
					if (((s.substr((int)0,(int)1) != HX_CSTRING("-")))){
						HX_STACK_LINE(45)
						stream->close();
						HX_STACK_LINE(46)
						proc->close();
						HX_STACK_LINE(47)
						::neash::Loader_obj::loaderTrace((HX_CSTRING("Found haxelib ") + s));
						HX_STACK_LINE(48)
						return s;
					}
				}
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
					}
				}
			}
			HX_STACK_LINE(53)
			stream->close();
			HX_STACK_LINE(54)
			proc->close();
		}
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
			}
		}
	}
	HX_STACK_LINE(59)
	return HX_CSTRING("");
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,findHaxeLib,return )

Dynamic Loader_obj::load( ::String func,int args){
	HX_STACK_PUSH("Loader::load","neash/Loader.hx",64);
	HX_STACK_ARG(func,"func");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(65)
	if ((::neash::Loader_obj::moduleInit)){
		HX_STACK_LINE(66)
		return ::cpp::Lib_obj::load(::neash::Loader_obj::moduleName,func,args);
	}
	HX_STACK_LINE(74)
	::neash::Loader_obj::moduleInit = true;
	HX_STACK_LINE(75)
	::neash::Loader_obj::moduleName = HX_CSTRING("nme");
	HX_STACK_LINE(78)
	Dynamic result = ::neash::Loader_obj::tryLoad(HX_CSTRING("./nme"),func,args);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(79)
	if (((result == null()))){
		HX_STACK_LINE(80)
		result = ::neash::Loader_obj::tryLoad(HX_CSTRING(".\\nme"),func,args);
	}
	HX_STACK_LINE(83)
	if (((result == null()))){
		HX_STACK_LINE(84)
		result = ::neash::Loader_obj::tryLoad(HX_CSTRING("nme"),func,args);
	}
	HX_STACK_LINE(86)
	if (((result == null()))){
		HX_STACK_LINE(88)
		::String slash = (  (((::neash::Loader_obj::sysName()->__Field(HX_CSTRING("substr"),true)((int)7)->__Field(HX_CSTRING("toLowerCase"),true)() == HX_CSTRING("windows")))) ? ::String(HX_CSTRING("\\")) : ::String(HX_CSTRING("/")) );		HX_STACK_VAR(slash,"slash");
		HX_STACK_LINE(89)
		::String haxelib = ::neash::Loader_obj::findHaxeLib(HX_CSTRING("nme"));		HX_STACK_VAR(haxelib,"haxelib");
		HX_STACK_LINE(90)
		if (((haxelib != HX_CSTRING("")))){
			HX_STACK_LINE(92)
			result = ::neash::Loader_obj::tryLoad(((((((haxelib + slash) + HX_CSTRING("ndll")) + slash) + ::Std_obj::string(::neash::Loader_obj::sysName())) + slash) + HX_CSTRING("nme")),func,args);
			HX_STACK_LINE(95)
			if (((result == null()))){
				HX_STACK_LINE(96)
				result = ::neash::Loader_obj::tryLoad((((((((haxelib + slash) + HX_CSTRING("ndll")) + slash) + ::Std_obj::string(::neash::Loader_obj::sysName())) + HX_CSTRING("64")) + slash) + HX_CSTRING("nme")),func,args);
			}
		}
	}
	HX_STACK_LINE(100)
	::neash::Loader_obj::loaderTrace((HX_CSTRING("Result : ") + ::Std_obj::string(result)));
	HX_STACK_LINE(106)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Loader_obj,load,return )

Void Loader_obj::loaderTrace( ::String inStr){
{
		HX_STACK_PUSH("Loader::loaderTrace","neash/Loader.hx",126);
		HX_STACK_ARG(inStr,"inStr");
		HX_STACK_LINE(129)
		Dynamic get_env = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_env"),(int)1);		HX_STACK_VAR(get_env,"get_env");
		HX_STACK_LINE(130)
		bool debug = (get_env(HX_CSTRING("NME_LOAD_DEBUG")) != null());		HX_STACK_VAR(debug,"debug");
		HX_STACK_LINE(135)
		if ((debug)){
			HX_STACK_LINE(136)
			::cpp::Lib_obj::println(inStr);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,loaderTrace,(void))

Dynamic Loader_obj::sysName( ){
	HX_STACK_PUSH("Loader::sysName","neash/Loader.hx",141);
	HX_STACK_LINE(144)
	Dynamic sys_string = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_string"),(int)0);		HX_STACK_VAR(sys_string,"sys_string");
	HX_STACK_LINE(145)
	return sys_string();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Loader_obj,sysName,return )

Dynamic Loader_obj::tryLoad( ::String inName,::String func,int args){
	HX_STACK_PUSH("Loader::tryLoad","neash/Loader.hx",153);
	HX_STACK_ARG(inName,"inName");
	HX_STACK_ARG(func,"func");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(154)
	try{
		HX_STACK_LINE(156)
		Dynamic result = ::cpp::Lib_obj::load(inName,func,args);		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(157)
		if (((result != null()))){
			HX_STACK_LINE(159)
			::neash::Loader_obj::loaderTrace((HX_CSTRING("Got result ") + inName));
			HX_STACK_LINE(160)
			::neash::Loader_obj::moduleName = inName;
			HX_STACK_LINE(161)
			return result;
		}
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_STACK_LINE(165)
				::neash::Loader_obj::loaderTrace((HX_CSTRING("Failed to load : ") + inName));
			}
		}
	}
	HX_STACK_LINE(168)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Loader_obj,tryLoad,return )


Loader_obj::Loader_obj()
{
}

void Loader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Loader);
	HX_MARK_END_CLASS();
}

void Loader_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Loader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"sysName") ) { return sysName_dyn(); }
		if (HX_FIELD_EQ(inName,"tryLoad") ) { return tryLoad_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { return moduleInit; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { return moduleName; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"findHaxeLib") ) { return findHaxeLib_dyn(); }
		if (HX_FIELD_EQ(inName,"loaderTrace") ) { return loaderTrace_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Loader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { moduleInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { moduleName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Loader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("moduleInit"),
	HX_CSTRING("moduleName"),
	HX_CSTRING("findHaxeLib"),
	HX_CSTRING("load"),
	HX_CSTRING("loaderTrace"),
	HX_CSTRING("sysName"),
	HX_CSTRING("tryLoad"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Loader_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Loader_obj::moduleInit,"moduleInit");
	HX_MARK_MEMBER_NAME(Loader_obj::moduleName,"moduleName");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Loader_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Loader_obj::moduleInit,"moduleInit");
	HX_VISIT_MEMBER_NAME(Loader_obj::moduleName,"moduleName");
};

Class Loader_obj::__mClass;

void Loader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.Loader"), hx::TCanCast< Loader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Loader_obj::__boot()
{
	moduleInit= false;
	moduleName= HX_CSTRING("");
}

} // end namespace neash
