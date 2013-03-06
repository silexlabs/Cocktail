#ifndef INCLUDED_cocktail_core_graphics_InitialGraphicsContext
#define INCLUDED_cocktail_core_graphics_InitialGraphicsContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/graphics/GraphicsContext.h>
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,graphics,InitialGraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace graphics{


class InitialGraphicsContext_obj : public ::cocktail::core::graphics::GraphicsContext_obj{
	public:
		typedef ::cocktail::core::graphics::GraphicsContext_obj super;
		typedef InitialGraphicsContext_obj OBJ_;
		InitialGraphicsContext_obj();
		Void __construct(::cocktail::core::layer::LayerRenderer layerRenderer);

	public:
		static hx::ObjectPtr< InitialGraphicsContext_obj > __new(::cocktail::core::layer::LayerRenderer layerRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InitialGraphicsContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InitialGraphicsContext"); }

		virtual Void doDetach( );

		virtual Void doAttach( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace graphics

#endif /* INCLUDED_cocktail_core_graphics_InitialGraphicsContext */ 
