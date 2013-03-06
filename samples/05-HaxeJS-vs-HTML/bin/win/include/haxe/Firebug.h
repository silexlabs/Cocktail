#ifndef INCLUDED_haxe_Firebug
#define INCLUDED_haxe_Firebug

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Firebug)
namespace haxe{


class Firebug_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Firebug_obj OBJ_;
		Firebug_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Firebug_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Firebug_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Firebug"); }

		static bool detect( );
		static Dynamic detect_dyn();

		static Void redirectTraces( );
		static Dynamic redirectTraces_dyn();

		static Void onError( ::String err,Array< ::String > stack);
		static Dynamic onError_dyn();

		static Void trace( Dynamic v,Dynamic inf);
		static Dynamic trace_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Firebug */ 
