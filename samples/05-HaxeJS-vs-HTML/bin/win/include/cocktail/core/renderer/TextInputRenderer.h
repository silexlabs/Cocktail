#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#define INCLUDED_cocktail_core_renderer_TextInputRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,EmbeddedBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextInputRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeTextInput)
namespace cocktail{
namespace core{
namespace renderer{


class TextInputRenderer_obj : public ::cocktail::core::renderer::EmbeddedBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::EmbeddedBoxRenderer_obj super;
		typedef TextInputRenderer_obj OBJ_;
		TextInputRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< TextInputRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextInputRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextInputRenderer"); }

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual Void updateNativeTextInput( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic updateNativeTextInput_dyn();

		virtual Void onTextInputFocus( ::cocktail::core::event::Event e);
		Dynamic onTextInputFocus_dyn();

		virtual Void renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void doCreateLayer( );

		virtual bool createOwnLayer( );

		int maxLength; /* REM */ 
		::String value; /* REM */ 
		::cocktail::port::platform::flash_player::NativeTextInput nativeTextInput; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_TextInputRenderer */ 
