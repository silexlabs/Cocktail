#ifndef INCLUDED_cocktail_core_layout_FloatVO
#define INCLUDED_cocktail_core_layout_FloatVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layout,FloatVO)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace layout{


class FloatVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FloatVO_obj OBJ_;
		FloatVO_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer node,::cocktail::core::geom::RectangleVO bounds);

	public:
		static hx::ObjectPtr< FloatVO_obj > __new(::cocktail::core::renderer::ElementRenderer node,::cocktail::core::geom::RectangleVO bounds);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FloatVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatVO"); }

		::cocktail::core::geom::RectangleVO bounds; /* REM */ 
		::cocktail::core::renderer::ElementRenderer node; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_FloatVO */ 
