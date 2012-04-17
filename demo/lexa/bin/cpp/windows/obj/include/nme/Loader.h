#ifndef INCLUDED_nme_Loader
#define INCLUDED_nme_Loader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nme,Loader)
namespace nme{


class Loader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Loader_obj OBJ_;
		Loader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Loader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Loader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Loader"); }

		static bool moduleInit; /* REM */ 
		static ::String moduleName; /* REM */ 
		static ::String findHaxeLib( ::String inLib);
		static Dynamic findHaxeLib_dyn();

		static Dynamic load( ::String func,int args);
		static Dynamic load_dyn();

		static Void loaderTrace( ::String inStr);
		static Dynamic loaderTrace_dyn();

		static Dynamic sysName( );
		static Dynamic sysName_dyn();

		static Dynamic tryLoad( ::String inName,::String func,int args);
		static Dynamic tryLoad_dyn();

};

} // end namespace nme

#endif /* INCLUDED_nme_Loader */ 
