#ifndef INCLUDED_cocktail_core_renderer_InputRenderer
#define INCLUDED_cocktail_core_renderer_InputRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BlockBoxRenderer.h>
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
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
namespace cocktail{
namespace core{
namespace renderer{


class InputRenderer_obj : public ::cocktail::core::renderer::BlockBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BlockBoxRenderer_obj super;
		typedef InputRenderer_obj OBJ_;
		InputRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< InputRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InputRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InputRenderer"); }

		virtual int get_intrinsicHeight( );
		Dynamic get_intrinsicHeight_dyn();

		virtual int get_intrinsicWidth( );
		Dynamic get_intrinsicWidth_dyn();

		virtual bool set_checked( bool value);
		Dynamic set_checked_dyn();

		virtual bool get_checked( );
		Dynamic get_checked_dyn();

		virtual bool set_readonly( bool value);
		Dynamic set_readonly_dyn();

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual Void updateNativeInputViewport( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic updateNativeInputViewport_dyn();

		virtual Void renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void doCreateLayer( );

		virtual bool createOwnLayer( );

		virtual Void blur( );
		Dynamic blur_dyn();

		virtual Void focus( );
		Dynamic focus_dyn();

		virtual Void setNativeInputCallbacks( );
		Dynamic setNativeInputCallbacks_dyn();

		virtual Void createNativeInput( );
		Dynamic createNativeInput_dyn();

		Dynamic onInput; /* REM */ 
		Dynamic &onInput_dyn() { return onInput;}
		Dynamic onActivate; /* REM */ 
		Dynamic &onActivate_dyn() { return onActivate;}
		::cocktail::port::base::NativeInputBase nativeInput; /* REM */ 
		int intrinsicHeight; /* REM */ 
		int intrinsicWidth; /* REM */ 
		bool readonly; /* REM */ 
		bool disabled; /* REM */ 
		int maxLength; /* REM */ 
		bool checked; /* REM */ 
		::String value; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_InputRenderer */ 
