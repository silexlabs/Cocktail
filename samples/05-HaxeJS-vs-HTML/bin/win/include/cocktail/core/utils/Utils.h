#ifndef INCLUDED_cocktail_core_utils_Utils
#define INCLUDED_cocktail_core_utils_Utils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,utils,Utils)
namespace cocktail{
namespace core{
namespace utils{


class Utils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Utils_obj OBJ_;
		Utils_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Utils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Utils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Utils"); }

		static Dynamic clear( Dynamic array);
		static Dynamic clear_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace utils

#endif /* INCLUDED_cocktail_core_utils_Utils */ 
