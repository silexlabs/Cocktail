#ifndef INCLUDED_cocktail_core_layout_floats_FloatsManager
#define INCLUDED_cocktail_core_layout_floats_FloatsManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layout,FloatVO)
HX_DECLARE_CLASS3(cocktail,core,layout,FloatsVO)
HX_DECLARE_CLASS4(cocktail,core,layout,floats,FloatsManager)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace layout{
namespace floats{


class FloatsManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FloatsManager_obj OBJ_;
		FloatsManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FloatsManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FloatsManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatsManager"); }

		virtual ::cocktail::core::layout::FloatsVO set_floats( ::cocktail::core::layout::FloatsVO value);
		Dynamic set_floats_dyn();

		virtual Float getRightFloatOffset( Float y,Float elementHeight,Float elementWidth,Float containingBlockXOffset,Float containingBlockWidth);
		Dynamic getRightFloatOffset_dyn();

		virtual Float getLeftFloatOffset( Float y,Float elementHeight,Float containingBlockXOffset);
		Dynamic getLeftFloatOffset_dyn();

		virtual bool canFitElementAtY( Float y,Float elementHeight,Float elementWidth,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic canFitElementAtY_dyn();

		virtual Float getFirstAvailableYPosition( Float currentYPosition,Float elementHeight,Float elementWidth,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic getFirstAvailableYPosition_dyn();

		virtual ::cocktail::core::geom::RectangleVO getFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic getFloatBounds_dyn();

		virtual ::cocktail::core::geom::RectangleVO getRightFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic getRightFloatBounds_dyn();

		virtual ::cocktail::core::geom::RectangleVO getLeftFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic getLeftFloatBounds_dyn();

		virtual ::cocktail::core::geom::RectangleVO registerFloat( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset);
		Dynamic registerFloat_dyn();

		virtual bool doGetHasClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY,Array< ::cocktail::core::layout::FloatVO > floats);
		Dynamic doGetHasClearance_dyn();

		virtual Float doGetClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY,Array< ::cocktail::core::layout::FloatVO > floats);
		Dynamic doGetClearance_dyn();

		virtual bool hasClearanceBoth( ::cocktail::core::renderer::ElementRenderer target,Float currentY);
		Dynamic hasClearanceBoth_dyn();

		virtual Float clearBoth( ::cocktail::core::renderer::ElementRenderer target,Float currentY);
		Dynamic clearBoth_dyn();

		virtual bool hasClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY);
		Dynamic hasClearance_dyn();

		virtual Float getClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY);
		Dynamic getClearance_dyn();

		virtual Void registerClear( ::cocktail::core::renderer::ElementRenderer elementRenderer);
		Dynamic registerClear_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		bool hasFloats; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > childrenWithClearance; /* REM */ 
		::cocktail::core::layout::FloatsVO floats; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace floats

#endif /* INCLUDED_cocktail_core_layout_floats_FloatsManager */ 
