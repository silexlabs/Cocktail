#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#define INCLUDED_cocktail_core_renderer_TextRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/ElementRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,TextTokenValue)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class TextRenderer_obj : public ::cocktail::core::renderer::ElementRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::ElementRenderer_obj super;
		typedef TextRenderer_obj OBJ_;
		TextRenderer_obj();
		Void __construct(::cocktail::core::style::CoreStyle style,Dynamic nativeElement,::cocktail::core::dom::TextTokenValue textToken);

	public:
		static hx::ObjectPtr< TextRenderer_obj > __new(::cocktail::core::style::CoreStyle style,Dynamic nativeElement,::cocktail::core::dom::TextTokenValue textToken);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextRenderer"); }

		::cocktail::core::dom::TextTokenValue _textToken; /* REM */ 
		Dynamic _nativeElement; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual int getOffsetWidth( );
		Dynamic getOffsetWidth_dyn();

		virtual int getOffsetHeight( );
		Dynamic getOffsetHeight_dyn();

		virtual bool isFloat( );
		Dynamic isFloat_dyn();

		virtual bool isPositioned( );
		Dynamic isPositioned_dyn();

		virtual bool isText( );
		Dynamic isText_dyn();

		virtual bool isSpace( );
		Dynamic isSpace_dyn();

		virtual bool isLineFeed( );
		Dynamic isLineFeed_dyn();

		virtual bool isTab( );
		Dynamic isTab_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_TextRenderer */ 
