#ifndef INCLUDED_cocktail_core_html_HTMLElement
#define INCLUDED_cocktail_core_html_HTMLElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Element.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,CascadeManager)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,css,InitialStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace html{


class HTMLElement_obj : public ::cocktail::core::dom::Element_obj{
	public:
		typedef ::cocktail::core::dom::Element_obj super;
		typedef HTMLElement_obj OBJ_;
		HTMLElement_obj();
		Void __construct(::String tagName);

	public:
		static hx::ObjectPtr< HTMLElement_obj > __new(::String tagName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLElement"); }

		virtual int get_clientLeft( );
		Dynamic get_clientLeft_dyn();

		virtual int get_clientTop( );
		Dynamic get_clientTop_dyn();

		virtual int get_clientHeight( );
		Dynamic get_clientHeight_dyn();

		virtual int get_clientWidth( );
		Dynamic get_clientWidth_dyn();

		virtual int get_offsetTop( );
		Dynamic get_offsetTop_dyn();

		virtual int get_offsetLeft( );
		Dynamic get_offsetLeft_dyn();

		virtual int get_offsetHeight( );
		Dynamic get_offsetHeight_dyn();

		virtual int get_offsetWidth( );
		Dynamic get_offsetWidth_dyn();

		virtual ::cocktail::core::html::HTMLElement get_offsetParent( );
		Dynamic get_offsetParent_dyn();

		virtual bool isVoidElement( );
		Dynamic isVoidElement_dyn();

		virtual ::String get_outerHTML( );
		Dynamic get_outerHTML_dyn();

		virtual ::String get_innerHTML( );
		Dynamic get_innerHTML_dyn();

		virtual ::String set_outerHTML( ::String value);
		Dynamic set_outerHTML_dyn();

		virtual ::String set_innerHTML( ::String value);
		Dynamic set_innerHTML_dyn();

		virtual int getAttributeAsPositiveSignedInteger( ::String name,Dynamic defaultValue);
		Dynamic getAttributeAsPositiveSignedInteger_dyn();

		virtual int getAttributeAsSignedInteger( ::String name,Dynamic defaultValue);
		Dynamic getAttributeAsSignedInteger_dyn();

		virtual Void setAttributeAsBool( ::String name,bool value);
		Dynamic setAttributeAsBool_dyn();

		virtual bool getAttributeAsBool( ::String name);
		Dynamic getAttributeAsBool_dyn();

		virtual ::String getEnumeratedAttributeAsDOMString( ::String name,Array< ::String > allowedValues,::String missingValueDefault,::String invalidValueDefault);
		Dynamic getEnumeratedAttributeAsDOMString_dyn();

		virtual ::String getAttributeAsDOMString( ::String name);
		Dynamic getAttributeAsDOMString_dyn();

		virtual bool set_hidden( bool value);
		Dynamic set_hidden_dyn();

		virtual bool get_hidden( );
		Dynamic get_hidden_dyn();

		virtual ::String set_className( ::String value);
		Dynamic set_className_dyn();

		virtual ::String get_className( );
		Dynamic get_className_dyn();

		virtual ::String set_id( ::String value);
		Dynamic set_id_dyn();

		virtual ::String get_id( );
		Dynamic get_id_dyn();

		virtual int get_tabIndex( );
		Dynamic get_tabIndex_dyn();

		virtual int set_tabIndex( int value);
		Dynamic set_tabIndex_dyn();

		virtual int get_scrollTop( );
		Dynamic get_scrollTop_dyn();

		virtual int set_scrollTop( int value);
		Dynamic set_scrollTop_dyn();

		virtual int get_scrollLeft( );
		Dynamic get_scrollLeft_dyn();

		virtual int set_scrollLeft( int value);
		Dynamic set_scrollLeft_dyn();

		virtual int get_scrollWidth( );
		Dynamic get_scrollWidth_dyn();

		virtual int get_scrollHeight( );
		Dynamic get_scrollHeight_dyn();

		virtual ::cocktail::core::html::HTMLElement getNearestActivatableElement( );
		Dynamic getNearestActivatableElement_dyn();

		virtual Void runPostClickActivationStep( ::cocktail::core::event::MouseEvent event);
		Dynamic runPostClickActivationStep_dyn();

		virtual Void runCanceledActivationStep( );
		Dynamic runCanceledActivationStep_dyn();

		virtual Void runPreClickActivation( );
		Dynamic runPreClickActivation_dyn();

		virtual bool hasActivationBehaviour( );
		Dynamic hasActivationBehaviour_dyn();

		virtual Void triggerActivationBehaviour( ::cocktail::core::event::MouseEvent clickEvent);
		Dynamic triggerActivationBehaviour_dyn();

		virtual Void requestFullScreen( );
		Dynamic requestFullScreen_dyn();

		virtual Void blur( );
		Dynamic blur_dyn();

		virtual Void focus( );
		Dynamic focus_dyn();

		virtual bool isDefaultFocusable( );
		Dynamic isDefaultFocusable_dyn();

		virtual bool isFocusable( );
		Dynamic isFocusable_dyn();

		virtual bool fireEvent( ::String eventType,bool bubbles,bool cancelable);
		Dynamic fireEvent_dyn();

		virtual ::cocktail::core::event::MouseEvent createMouseClickEvent( );
		Dynamic createMouseClickEvent_dyn();

		virtual Void click( );
		Dynamic click_dyn();

		virtual Void endPendingAnimation( );
		Dynamic endPendingAnimation_dyn();

		virtual bool startPendingAnimation( );
		Dynamic startPendingAnimation_dyn();

		virtual bool isParentRendered( );
		Dynamic isParentRendered_dyn();

		virtual bool isRendered( );
		Dynamic isRendered_dyn();

		virtual Void createElementRenderer( );
		Dynamic createElementRenderer_dyn();

		virtual Void detachFromParentElementRenderer( );
		Dynamic detachFromParentElementRenderer_dyn();

		virtual Void attachToParentElementRenderer( );
		Dynamic attachToParentElementRenderer_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer getNextElementRendererSibling( );
		Dynamic getNextElementRendererSibling_dyn();

		virtual Void onInlineStyleChange( int changedPropertyIndex);
		Dynamic onInlineStyleChange_dyn();

		virtual Void cascadeSelf( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange);
		Dynamic cascadeSelf_dyn();

		virtual Void getStyleDeclaration( );
		Dynamic getStyleDeclaration_dyn();

		virtual Void cascade( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange);
		Dynamic cascade_dyn();

		virtual Void detach( bool recursive);
		Dynamic detach_dyn();

		virtual Void attach( bool recursive);
		Dynamic attach_dyn();

		virtual Void updateElementRenderer( );
		Dynamic updateElementRenderer_dyn();

		virtual bool isAttachedToDOM( );
		Dynamic isAttachedToDOM_dyn();

		virtual Void removedFromDOM( );
		Dynamic removedFromDOM_dyn();

		virtual Void addedToDOM( );
		Dynamic addedToDOM_dyn();

		virtual Void removed( );
		Dynamic removed_dyn();

		virtual Void appended( );
		Dynamic appended_dyn();

		virtual Void updateDocumentImmediately( );
		Dynamic updateDocumentImmediately_dyn();

		virtual Void invalidateRendering( );
		Dynamic invalidateRendering_dyn();

		virtual Void invalidateCascade( );
		Dynamic invalidateCascade_dyn();

		virtual Void invalidateStyleDeclaration( bool recursive);
		Dynamic invalidateStyleDeclaration_dyn();

		virtual Void invalidateLayerRenderer( );
		Dynamic invalidateLayerRenderer_dyn();

		virtual Void invalidateElementRenderer( );
		Dynamic invalidateElementRenderer_dyn();

		virtual Void invalidateStyle( int styleIndex);
		Dynamic invalidateStyle_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual ::cocktail::core::dom::Document set_ownerDocument( ::cocktail::core::dom::Document value);

		virtual Void executeDefaultActionIfNeeded( bool defaultPrevented,::cocktail::core::event::Event event);

		virtual Array< ::cocktail::core::event::EventTarget > getTargetAncestors( );

		virtual ::String getAttribute( ::String name);

		virtual Void setAttribute( ::String name,::String value);

		virtual Array< ::cocktail::core::html::HTMLElement > getElementsByTagName( ::String tagName);

		virtual Dynamic insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild);

		virtual Dynamic removeChild( Dynamic _tmp_oldChild);

		virtual Dynamic appendChild( Dynamic _tmp_newChild);

		virtual Void initStyle( );
		Dynamic initStyle_dyn();

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		::cocktail::core::css::InitialStyleDeclaration _initialStyleDeclaration; /* REM */ 
		::cocktail::core::html::HTMLDocument _ownerHTMLDocument; /* REM */ 
		bool _shouldCascadeAllProperties; /* REM */ 
		Array< int > _pendingChangedProperties; /* REM */ 
		bool _needsElementRendererUpdate; /* REM */ 
		bool _needsStyleDeclarationUpdate; /* REM */ 
		bool _needsCascading; /* REM */ 
		bool attachedToDOM; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration styleManagerCSSDeclaration; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration style; /* REM */ 
		::cocktail::core::css::CoreStyle coreStyle; /* REM */ 
		int clientTop; /* REM */ 
		int clientLeft; /* REM */ 
		int clientHeight; /* REM */ 
		int clientWidth; /* REM */ 
		int offsetTop; /* REM */ 
		int offsetLeft; /* REM */ 
		int offsetHeight; /* REM */ 
		int offsetWidth; /* REM */ 
		::cocktail::core::html::HTMLElement offsetParent; /* REM */ 
		::cocktail::core::renderer::ElementRenderer elementRenderer; /* REM */ 
		::String outerHTML; /* REM */ 
		::String innerHTML; /* REM */ 
		int scrollWidth; /* REM */ 
		int scrollHeight; /* REM */ 
		int scrollLeft; /* REM */ 
		int scrollTop; /* REM */ 
		bool hidden; /* REM */ 
		Array< ::String > classList; /* REM */ 
		::String className; /* REM */ 
		::String id; /* REM */ 
		int tabIndex; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLElement */ 
