#ifndef INCLUDED_cocktail_core_style_AbstractBodyCoreStyle
#define INCLUDED_cocktail_core_style_AbstractBodyCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/ContainerCoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractBodyCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
HX_DECLARE_CLASS3(cocktail,port,flash_player,ContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace style{


class AbstractBodyCoreStyle_obj : public ::cocktail::port::flash_player::ContainerCoreStyle_obj{
	public:
		typedef ::cocktail::port::flash_player::ContainerCoreStyle_obj super;
		typedef AbstractBodyCoreStyle_obj OBJ_;
		AbstractBodyCoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractBodyCoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractBodyCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractBodyCoreStyle"); }

		Dynamic _nativeElements; /* REM */ 
		virtual Void invalidate( Dynamic immediate);
		Dynamic invalidate_dyn();

		virtual Void render( Dynamic nativeElement);
		Dynamic render_dyn();

		virtual Void attachNativeElement( Dynamic nativeElement);
		Dynamic attachNativeElement_dyn();

		virtual Void detachNativeElement( Dynamic nativeElement);
		Dynamic detachNativeElement_dyn();

		virtual Void attachNativeElements( Dynamic nativeElements);
		Dynamic attachNativeElements_dyn();

		virtual Void detachNativeElements( Dynamic nativeElements);
		Dynamic detachNativeElements_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual Void layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData);
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

		virtual ::cocktail::port::flash_player::HTMLElement getFirstPositionedAncestor( );
		Dynamic getFirstPositionedAncestor_dyn();

		virtual ::cocktail::core::style::formatter::FormattingContext getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext);
		Dynamic getformattingContext_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_AbstractBodyCoreStyle */ 
