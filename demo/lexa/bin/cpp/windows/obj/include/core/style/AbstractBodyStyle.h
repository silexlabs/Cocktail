#ifndef INCLUDED_core_style_AbstractBodyStyle
#define INCLUDED_core_style_AbstractBodyStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/ContainerStyle.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,style,AbstractBodyStyle)
HX_DECLARE_CLASS2(core,style,AbstractContainerStyle)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS3(core,style,formatter,FormattingContext)
HX_DECLARE_CLASS2(port,flash_player,ContainerStyle)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace style{


class AbstractBodyStyle_obj : public ::port::flash_player::ContainerStyle_obj{
	public:
		typedef ::port::flash_player::ContainerStyle_obj super;
		typedef AbstractBodyStyle_obj OBJ_;
		AbstractBodyStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractBodyStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractBodyStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractBodyStyle"); }

		Dynamic _nativeElements; /* REM */ 
		virtual Void invalidate( );
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

		virtual ::core::renderer::ElementRenderer createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual Void layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData);
		Dynamic layout_dyn();

		virtual Void insertHTMLElement( ::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic insertHTMLElement_dyn();

		virtual Void positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn();

		virtual Dynamic getPositionedHTMLElementData( );
		Dynamic getPositionedHTMLElementData_dyn();

		virtual bool isInlineLevel( );
		Dynamic isInlineLevel_dyn();

		virtual ::core::style::formatter::FormattingContext getformattingContext( ::core::style::formatter::FormattingContext previousformattingContext);
		Dynamic getformattingContext_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_AbstractBodyStyle */ 
