#ifndef INCLUDED_cocktail_core_style_BodyCoreStyle
#define INCLUDED_cocktail_core_style_BodyCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/ContainerCoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,BodyCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,ContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
namespace cocktail{
namespace core{
namespace style{


class BodyCoreStyle_obj : public ::cocktail::core::style::ContainerCoreStyle_obj{
	public:
		typedef ::cocktail::core::style::ContainerCoreStyle_obj super;
		typedef BodyCoreStyle_obj OBJ_;
		BodyCoreStyle_obj();
		Void __construct(::cocktail::core::html::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< BodyCoreStyle_obj > __new(::cocktail::core::html::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BodyCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BodyCoreStyle"); }

		virtual Void invalidate( Dynamic immediate);
		Dynamic invalidate_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual Void layout( );
		Dynamic layout_dyn();

		virtual Void insertHTMLElement( ::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic insertHTMLElement_dyn();

		virtual Void positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn();

		virtual Dynamic getPositionedHTMLElementData( );
		Dynamic getPositionedHTMLElementData_dyn();

		virtual bool isInlineLevel( );
		Dynamic isInlineLevel_dyn();

		virtual bool isOffsetParent( );
		Dynamic isOffsetParent_dyn();

		virtual ::cocktail::core::html::HTMLElement getFirstPositionedAncestor( );
		Dynamic getFirstPositionedAncestor_dyn();

		virtual ::cocktail::core::style::formatter::FormattingContext getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext);
		Dynamic getformattingContext_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BodyCoreStyle */ 
