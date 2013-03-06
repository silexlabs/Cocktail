#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#define INCLUDED_cocktail_core_linebox_InlineBox

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/FastNode.h>
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,LineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace linebox{


class InlineBox_obj : public ::cocktail::core::utils::FastNode_obj{
	public:
		typedef ::cocktail::core::utils::FastNode_obj super;
		typedef InlineBox_obj OBJ_;
		InlineBox_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent);

	public:
		static hx::ObjectPtr< InlineBox_obj > __new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineBox_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineBox"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::cocktail::core::geom::PointVO offsetFromParentInlineBox; /* REM */ 
		::cocktail::core::linebox::LineBox lineBox; /* REM */ 
		Float borderRight; /* REM */ 
		Float borderLeft; /* REM */ 
		Float paddingRight; /* REM */ 
		Float paddingLeft; /* REM */ 
		Float marginRight; /* REM */ 
		Float marginLeft; /* REM */ 
		Float leadedDescent; /* REM */ 
		Float leadedAscent; /* REM */ 
		::cocktail::core::geom::RectangleVO bounds; /* REM */ 
		::cocktail::core::renderer::ElementRenderer elementRenderer; /* REM */ 
		bool isLineFeed; /* REM */ 
		bool isEmbedded; /* REM */ 
		bool isSpace; /* REM */ 
		bool isText; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace linebox

#endif /* INCLUDED_cocktail_core_linebox_InlineBox */ 
