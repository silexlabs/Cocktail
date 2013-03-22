#ifndef INCLUDED_neash_filters_BitmapFilter
#define INCLUDED_neash_filters_BitmapFilter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,filters,BitmapFilter)
namespace neash{
namespace filters{


class BitmapFilter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapFilter_obj OBJ_;
		BitmapFilter_obj();
		Void __construct(::String inType);

	public:
		static hx::ObjectPtr< BitmapFilter_obj > __new(::String inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapFilter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapFilter"); }

		virtual ::neash::filters::BitmapFilter clone( );
		Dynamic clone_dyn();

		::String type; /* REM */ 
};

} // end namespace neash
} // end namespace filters

#endif /* INCLUDED_neash_filters_BitmapFilter */ 
