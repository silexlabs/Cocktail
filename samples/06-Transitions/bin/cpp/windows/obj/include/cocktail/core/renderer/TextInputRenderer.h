#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#define INCLUDED_cocktail_core_renderer_TextInputRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/InputRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InputRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextInputRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeTextInput)
namespace cocktail{
namespace core{
namespace renderer{


class TextInputRenderer_obj : public ::cocktail::core::renderer::InputRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::InputRenderer_obj super;
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

		virtual Void updateNativeTextInput( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic updateNativeTextInput_dyn();

		virtual Void renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void createNativeInput( );

		::cocktail::port::platform::flash_player::NativeTextInput nativeTextInput; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_TextInputRenderer */ 
