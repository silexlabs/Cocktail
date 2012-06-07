#ifndef INCLUDED_Std
#define INCLUDED_Std

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Std)


class Std_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Std_obj OBJ_;
		Std_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Std_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Std_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Std"); }

		static bool is( Dynamic v,Dynamic t);
		static Dynamic is_dyn();

		static ::String string( Dynamic s);
		static Dynamic string_dyn();

		static int _int( double x);
		static Dynamic _int_dyn();

		static Dynamic parseInt( ::String x);
		static Dynamic parseInt_dyn();

		static double parseFloat( ::String x);
		static Dynamic parseFloat_dyn();

		static int random( int x);
		static Dynamic random_dyn();

};


#endif /* INCLUDED_Std */ 
