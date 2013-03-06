#ifndef INCLUDED_cocktail_core_linebox_EmbeddedInlineBox
#define INCLUDED_cocktail_core_linebox_EmbeddedInlineBox

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/linebox/InlineBox.h>
HX_DECLARE_CLASS3(cocktail,core,linebox,EmbeddedInlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace linebox{


class EmbeddedInlineBox_obj : public ::cocktail::core::linebox::InlineBox_obj{
	public:
		typedef ::cocktail::core::linebox::InlineBox_obj super;
		typedef EmbeddedInlineBox_obj OBJ_;
		EmbeddedInlineBox_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent);

	public:
		static hx::ObjectPtr< EmbeddedInlineBox_obj > __new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedInlineBox_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedInlineBox"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace linebox

#endif /* INCLUDED_cocktail_core_linebox_EmbeddedInlineBox */ 
