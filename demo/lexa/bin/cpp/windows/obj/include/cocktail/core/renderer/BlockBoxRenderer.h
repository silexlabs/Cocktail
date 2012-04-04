#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#define INCLUDED_cocktail_core_renderer_BlockBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/FlowBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class BlockBoxRenderer_obj : public ::cocktail::core::renderer::FlowBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::FlowBoxRenderer_obj super;
		typedef BlockBoxRenderer_obj OBJ_;
		BlockBoxRenderer_obj();
		Void __construct(::cocktail::port::flash_player::CoreStyle style);

	public:
		static hx::ObjectPtr< BlockBoxRenderer_obj > __new(::cocktail::port::flash_player::CoreStyle style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlockBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlockBoxRenderer"); }

		Array< Array< ::cocktail::core::renderer::ElementRenderer > > _lineBoxes; /* REM */ 
		Array< Array< ::cocktail::core::renderer::ElementRenderer > > lineBoxes; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void addLineBox( Array< ::cocktail::core::renderer::ElementRenderer > lineBoxElements);
		Dynamic addLineBox_dyn();

		virtual Void removeLineBoxes( );
		Dynamic removeLineBoxes_dyn();

		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual Array< Array< ::cocktail::core::renderer::ElementRenderer > > getLineBoxes( );
		Dynamic getLineBoxes_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_BlockBoxRenderer */ 
