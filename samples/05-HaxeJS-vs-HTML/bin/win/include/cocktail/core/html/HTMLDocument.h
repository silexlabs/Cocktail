#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#define INCLUDED_cocktail_core_html_HTMLDocument

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Document.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,CascadeManager)
HX_DECLARE_CLASS3(cocktail,core,css,MatchedPseudoClassesVO)
HX_DECLARE_CLASS3(cocktail,core,css,StyleManager)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,TouchEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,event,WheelEvent)
HX_DECLARE_CLASS3(cocktail,core,focus,FocusManager)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,hittest,HitTestManager)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBodyElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,invalidation,InvalidationManager)
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutManager)
HX_DECLARE_CLASS3(cocktail,core,multitouch,MultiTouchManager)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,timer,Timer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,window,Window)
namespace cocktail{
namespace core{
namespace html{


class HTMLDocument_obj : public ::cocktail::core::dom::Document_obj{
	public:
		typedef ::cocktail::core::dom::Document_obj super;
		typedef HTMLDocument_obj OBJ_;
		HTMLDocument_obj();
		Void __construct(::cocktail::core::window::Window window);

	public:
		static hx::ObjectPtr< HTMLDocument_obj > __new(::cocktail::core::window::Window window);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLDocument_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLDocument"); }

		virtual ::cocktail::core::html::HTMLElement get_activeElement( );
		Dynamic get_activeElement_dyn();

		virtual ::cocktail::core::html::HTMLElement set_activeElement( ::cocktail::core::html::HTMLElement newActiveElement);
		Dynamic set_activeElement_dyn();

		virtual ::cocktail::core::html::HTMLElement getFirstVerticallyScrollableHTMLElement( ::cocktail::core::html::HTMLElement htmlElement,int scrollOffset);
		Dynamic getFirstVerticallyScrollableHTMLElement_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer getFirstElementRendererWhichCanDispatchMouseEvent( int x,int y);
		Dynamic getFirstElementRendererWhichCanDispatchMouseEvent_dyn();

		virtual ::cocktail::core::html::HTMLElement set_fullscreenElement( ::cocktail::core::html::HTMLElement value);
		Dynamic set_fullscreenElement_dyn();

		virtual bool get_fullscreenEnabled( );
		Dynamic get_fullscreenEnabled_dyn();

		virtual Void exitFullscreen( );
		Dynamic exitFullscreen_dyn();

		virtual Void setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor);
		Dynamic setMouseCursor_dyn();

		virtual Void dispatchClickEvent( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic dispatchClickEvent_dyn();

		virtual Void onPlatformTouchEvent( ::cocktail::core::event::TouchEvent touchEvent);
		Dynamic onPlatformTouchEvent_dyn();

		virtual Void onPlatformKeyUpEvent( ::cocktail::core::event::KeyboardEvent keyboardEvent);
		Dynamic onPlatformKeyUpEvent_dyn();

		virtual Void onPlatformKeyDownEvent( ::cocktail::core::event::KeyboardEvent keyboardEvent);
		Dynamic onPlatformKeyDownEvent_dyn();

		virtual Void onPlatformMouseMoveEvent( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onPlatformMouseMoveEvent_dyn();

		virtual Void onPlatformMouseWheelEvent( ::cocktail::core::event::WheelEvent wheelEvent);
		Dynamic onPlatformMouseWheelEvent_dyn();

		virtual Void onPlatformMouseLeaveEvent( ::cocktail::core::event::Event event);
		Dynamic onPlatformMouseLeaveEvent_dyn();

		virtual Void onPlatformMouseEvent( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onPlatformMouseEvent_dyn();

		virtual ::String get_innerHTML( );
		Dynamic get_innerHTML_dyn();

		virtual ::String set_innerHTML( ::String value);
		Dynamic set_innerHTML_dyn();

		virtual ::cocktail::core::css::MatchedPseudoClassesVO getMatchedPseudoClassesVO( ::cocktail::core::html::HTMLElement node);
		Dynamic getMatchedPseudoClassesVO_dyn();

		virtual ::cocktail::core::css::CSSStyleDeclaration getStyleDeclaration( ::cocktail::core::html::HTMLElement node);
		Dynamic getStyleDeclaration_dyn();

		virtual Void removeStyleSheet( ::cocktail::core::css::CSSStyleSheet stylesheet);
		Dynamic removeStyleSheet_dyn();

		virtual Void addStyleSheet( ::cocktail::core::css::CSSStyleSheet stylesheet);
		Dynamic addStyleSheet_dyn();

		virtual ::cocktail::core::html::HTMLElement createElement( ::String tagName);

		virtual Void initStyleManager( );
		Dynamic initStyleManager_dyn();

		virtual Void initBody( ::cocktail::core::html::HTMLBodyElement htmlBodyElement);
		Dynamic initBody_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		::String innerHTML; /* REM */ 
		::cocktail::core::css::CascadeManager cascadeManager; /* REM */ 
		::cocktail::core::css::MatchedPseudoClassesVO _matchedPseudoClasses; /* REM */ 
		::cocktail::core::invalidation::InvalidationManager invalidationManager; /* REM */ 
		::cocktail::core::layout::LayoutManager layoutManager; /* REM */ 
		::cocktail::core::css::StyleManager _styleManager; /* REM */ 
		::cocktail::core::window::Window window; /* REM */ 
		::cocktail::core::hittest::HitTestManager _hitTestManager; /* REM */ 
		::cocktail::core::multitouch::MultiTouchManager _multiTouchManager; /* REM */ 
		::cocktail::core::timer::Timer timer; /* REM */ 
		::cocktail::core::geom::PointVO _lastTouchStartPosition; /* REM */ 
		bool _shouldDispatchClickOnNextMouseUp; /* REM */ 
		Dynamic onSetMouseCursor; /* REM */ 
		Dynamic &onSetMouseCursor_dyn() { return onSetMouseCursor;}
		Dynamic onExitFullscreen; /* REM */ 
		Dynamic &onExitFullscreen_dyn() { return onExitFullscreen;}
		Dynamic onEnterFullscreen; /* REM */ 
		Dynamic &onEnterFullscreen_dyn() { return onEnterFullscreen;}
		::cocktail::core::html::HTMLElement fullscreenElement; /* REM */ 
		bool fullscreenEnabled; /* REM */ 
		::cocktail::core::renderer::ElementRenderer _mousedDownedElementRenderer; /* REM */ 
		::cocktail::core::renderer::ElementRenderer _hoveredElementRenderer; /* REM */ 
		::cocktail::core::focus::FocusManager _focusManager; /* REM */ 
		::cocktail::core::html::HTMLElement activeElement; /* REM */ 
		::cocktail::core::html::HTMLBodyElement body; /* REM */ 
		static int TAB_KEY_CODE; /* REM */ 
		static int ENTER_KEY_CODE; /* REM */ 
		static int SPACE_KEY_CODE; /* REM */ 
		static int MOUSE_WHEEL_DELTA_MULTIPLIER; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLDocument */ 
