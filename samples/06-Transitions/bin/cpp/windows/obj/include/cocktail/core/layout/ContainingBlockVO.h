#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#define INCLUDED_cocktail_core_layout_ContainingBlockVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
namespace cocktail{
namespace core{
namespace layout{


class ContainingBlockVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ContainingBlockVO_obj OBJ_;
		ContainingBlockVO_obj();
		Void __construct(Float width,bool isWidthAuto,Float height,bool isHeightAuto);

	public:
		static hx::ObjectPtr< ContainingBlockVO_obj > __new(Float width,bool isWidthAuto,Float height,bool isHeightAuto);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ContainingBlockVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ContainingBlockVO"); }

		bool isHeightAuto; /* REM */ 
		Float height; /* REM */ 
		bool isWidthAuto; /* REM */ 
		Float width; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_ContainingBlockVO */ 
