#ifndef INCLUDED_core_renderer_TextRenderer
#define INCLUDED_core_renderer_TextRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/ElementRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,TextTokenValue)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,TextRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class TextRenderer_obj : public ::core::renderer::ElementRenderer_obj{
	public:
		typedef ::core::renderer::ElementRenderer_obj super;
		typedef TextRenderer_obj OBJ_;
		TextRenderer_obj();
		Void __construct(::port::flash_player::Style style,Dynamic nativeElement,::core::dom::TextTokenValue textToken);

	public:
		static hx::ObjectPtr< TextRenderer_obj > __new(::port::flash_player::Style style,Dynamic nativeElement,::core::dom::TextTokenValue textToken);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextRenderer"); }

		::core::dom::TextTokenValue _textToken; /* REM */ 
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

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_TextRenderer */ 
