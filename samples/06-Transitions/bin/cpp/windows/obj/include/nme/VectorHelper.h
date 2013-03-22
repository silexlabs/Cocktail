#ifndef INCLUDED_nme_VectorHelper
#define INCLUDED_nme_VectorHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nme,VectorHelper)
namespace nme{


class VectorHelper_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VectorHelper_obj OBJ_;
		VectorHelper_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< VectorHelper_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VectorHelper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VectorHelper"); }

		static Dynamic ofArray( ::Class v,Dynamic array);
		static Dynamic ofArray_dyn();

};

} // end namespace nme

#endif /* INCLUDED_nme_VectorHelper */ 
