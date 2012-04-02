#ifndef INCLUDED_core_renderer_BlockBoxRenderer
#define INCLUDED_core_renderer_BlockBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/FlowBoxRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class BlockBoxRenderer_obj : public ::core::renderer::FlowBoxRenderer_obj{
	public:
		typedef ::core::renderer::FlowBoxRenderer_obj super;
		typedef BlockBoxRenderer_obj OBJ_;
		BlockBoxRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< BlockBoxRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlockBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlockBoxRenderer"); }

		Array< Array< ::core::renderer::ElementRenderer > > _lineBoxes; /* REM */ 
		Array< Array< ::core::renderer::ElementRenderer > > lineBoxes; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void addLineBox( Array< ::core::renderer::ElementRenderer > lineBoxElements);
		Dynamic addLineBox_dyn();

		virtual Void removeLineBoxes( );
		Dynamic removeLineBoxes_dyn();

		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual Array< Array< ::core::renderer::ElementRenderer > > getLineBoxes( );
		Dynamic getLineBoxes_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_BlockBoxRenderer */ 
