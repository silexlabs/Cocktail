#ifndef INCLUDED_cocktail_core_layout_FloatsVO
#define INCLUDED_cocktail_core_layout_FloatsVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,layout,FloatVO)
HX_DECLARE_CLASS3(cocktail,core,layout,FloatsVO)
namespace cocktail{
namespace core{
namespace layout{


class FloatsVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FloatsVO_obj OBJ_;
		FloatsVO_obj();
		Void __construct(Array< ::cocktail::core::layout::FloatVO > left,Array< ::cocktail::core::layout::FloatVO > right);

	public:
		static hx::ObjectPtr< FloatsVO_obj > __new(Array< ::cocktail::core::layout::FloatVO > left,Array< ::cocktail::core::layout::FloatVO > right);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FloatsVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatsVO"); }

		Array< ::cocktail::core::layout::FloatVO > right; /* REM */ 
		Array< ::cocktail::core::layout::FloatVO > left; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_FloatsVO */ 
