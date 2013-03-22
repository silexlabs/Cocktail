#ifndef INCLUDED_Cocktail
#define INCLUDED_Cocktail

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Cocktail)


class Cocktail_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Cocktail_obj OBJ_;
		Cocktail_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Cocktail_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Cocktail_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Cocktail"); }

		static ::String htmlSourcePath; /* REM */ 
		static ::String htmlSource; /* REM */ 
		static ::String customClassName; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Cocktail */ 
