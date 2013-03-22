#ifndef INCLUDED_cocktail_core_layout_InlineFormattingVO
#define INCLUDED_cocktail_core_layout_InlineFormattingVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,layout,InlineFormattingVO)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,LineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layout{


class InlineFormattingVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef InlineFormattingVO_obj OBJ_;
		InlineFormattingVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InlineFormattingVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineFormattingVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineFormattingVO"); }

		::cocktail::core::geom::PointVO lineBoxPosition; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > openedElementRenderers; /* REM */ 
		::cocktail::core::linebox::InlineBox inlineBox; /* REM */ 
		::cocktail::core::linebox::LineBox lineBox; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_InlineFormattingVO */ 
