#ifndef INCLUDED_cocktail_core_html_HTMLElement
#define INCLUDED_cocktail_core_html_HTMLElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Element.h>
#include <cocktail/core/event/IEventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,keyboard,AbstractKeyboard)
HX_DECLARE_CLASS3(cocktail,core,mouse,AbstractMouse)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS4(cocktail,core,style,adapter,Style)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Keyboard)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Mouse)
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
		inline operator ::cocktail::core::event::IEventTarget_obj *()
			{ return new ::cocktail::core::event::IEventTarget_delegate_< HTMLElement_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("HTMLElement"); }

		::cocktail::port::flash_player::Mouse _mouse; /* REM */ 
		Dynamic _onClick; /* REM */ 
	Dynamic &_onClick_dyn() { return _onClick;}
		Dynamic onclick; /* REM */ 
	Dynamic &onclick_dyn() { return onclick;}
		Dynamic _onMouseDown; /* REM */ 
	Dynamic &_onMouseDown_dyn() { return _onMouseDown;}
		Dynamic onmousedown; /* REM */ 
	Dynamic &onmousedown_dyn() { return onmousedown;}
		Dynamic _onMouseUp; /* REM */ 
	Dynamic &_onMouseUp_dyn() { return _onMouseUp;}
		Dynamic onmouseup; /* REM */ 
	Dynamic &onmouseup_dyn() { return onmouseup;}
		Dynamic _onMouseOver; /* REM */ 
	Dynamic &_onMouseOver_dyn() { return _onMouseOver;}
		Dynamic onmouseover; /* REM */ 
	Dynamic &onmouseover_dyn() { return onmouseover;}
		Dynamic _onMouseOut; /* REM */ 
	Dynamic &_onMouseOut_dyn() { return _onMouseOut;}
		Dynamic onmouseout; /* REM */ 
	Dynamic &onmouseout_dyn() { return onmouseout;}
		Dynamic _onMouseMove; /* REM */ 
	Dynamic &_onMouseMove_dyn() { return _onMouseMove;}
		Dynamic onmousemove; /* REM */ 
	Dynamic &onmousemove_dyn() { return onmousemove;}
		::cocktail::port::flash_player::Keyboard _keyboard; /* REM */ 
		Dynamic _onKeyDown; /* REM */ 
	Dynamic &_onKeyDown_dyn() { return _onKeyDown;}
		Dynamic onkeydown; /* REM */ 
	Dynamic &onkeydown_dyn() { return onkeydown;}
		Dynamic _onKeyUp; /* REM */ 
	Dynamic &_onKeyUp_dyn() { return _onKeyUp;}
		Dynamic onkeyup; /* REM */ 
	Dynamic &onkeyup_dyn() { return onkeyup;}
		Dynamic _tabIndex; /* REM */ 
		Dynamic tabIndex; /* REM */ 
		Dynamic _onFocus; /* REM */ 
	Dynamic &_onFocus_dyn() { return _onFocus;}
		Dynamic onfocus; /* REM */ 
	Dynamic &onfocus_dyn() { return onfocus;}
		Dynamic _onBlur; /* REM */ 
	Dynamic &_onBlur_dyn() { return _onBlur;}
		Dynamic onblur; /* REM */ 
	Dynamic &onblur_dyn() { return onblur;}
		Dynamic _onScroll; /* REM */ 
	Dynamic &_onScroll_dyn() { return _onScroll;}
		Dynamic onscroll; /* REM */ 
	Dynamic &onscroll_dyn() { return onscroll;}
		int scrollTop; /* REM */ 
		int scrollLeft; /* REM */ 
		int scrollHeight; /* REM */ 
		int scrollWidth; /* REM */ 
		Dynamic _nativeElement; /* REM */ 
		Dynamic nativeElement; /* REM */ 
		::String id; /* REM */ 
		::String innerHTML; /* REM */ 
		::cocktail::core::html::HTMLElement offsetParent; /* REM */ 
		int offsetWidth; /* REM */ 
		int offsetHeight; /* REM */ 
		int offsetLeft; /* REM */ 
		int offsetTop; /* REM */ 
		int clientWidth; /* REM */ 
		int clientHeight; /* REM */ 
		int clientLeft; /* REM */ 
		int clientTop; /* REM */ 
		::cocktail::core::style::CoreStyle _coreStyle; /* REM */ 
		::cocktail::core::style::CoreStyle coreStyle; /* REM */ 
		::cocktail::core::style::adapter::Style _style; /* REM */ 
		::cocktail::core::style::adapter::Style style; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void initNativeElement( );
		Dynamic initNativeElement_dyn();

		virtual Void initMouse( );
		Dynamic initMouse_dyn();

		virtual Void initKeyboard( );
		Dynamic initKeyboard_dyn();

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		virtual Void initStyle( );
		Dynamic initStyle_dyn();

		virtual Void initId( );
		Dynamic initId_dyn();

		virtual ::cocktail::core::dom::Node appendChild( ::cocktail::core::dom::Node newChild);
		Dynamic appendChild_dyn();

		virtual ::cocktail::core::dom::Node removeChild( ::cocktail::core::dom::Node oldChild);
		Dynamic removeChild_dyn();

		virtual Array< ::cocktail::core::dom::Node > getElementsByTagName( ::String tagName);
		Dynamic getElementsByTagName_dyn();

		virtual Void click( );
		Dynamic click_dyn();

		virtual Dynamic set_onClick( Dynamic value);
		Dynamic set_onClick_dyn();

		virtual Dynamic get_onClick( );
		Dynamic get_onClick_dyn();

		virtual Dynamic set_onMouseDown( Dynamic value);
		Dynamic set_onMouseDown_dyn();

		virtual Dynamic get_onMouseDown( );
		Dynamic get_onMouseDown_dyn();

		virtual Dynamic set_onMouseUp( Dynamic value);
		Dynamic set_onMouseUp_dyn();

		virtual Dynamic get_onMouseUp( );
		Dynamic get_onMouseUp_dyn();

		virtual Dynamic set_onMouseOver( Dynamic value);
		Dynamic set_onMouseOver_dyn();

		virtual Dynamic get_onMouseOver( );
		Dynamic get_onMouseOver_dyn();

		virtual Dynamic set_onMouseOut( Dynamic value);
		Dynamic set_onMouseOut_dyn();

		virtual Dynamic get_onMouseOut( );
		Dynamic get_onMouseOut_dyn();

		virtual Dynamic set_onMouseMove( Dynamic value);
		Dynamic set_onMouseMove_dyn();

		virtual Dynamic get_onMouseMove( );
		Dynamic get_onMouseMove_dyn();

		virtual Void onClickCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onClickCallback_dyn();

		virtual Void onMouseDownCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseDownCallback_dyn();

		virtual Void onMouseUpCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseUpCallback_dyn();

		virtual Void onMouseMoveCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseMoveCallback_dyn();

		virtual Void onMouseOverCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOverCallback_dyn();

		virtual Void onMouseOutCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOutCallback_dyn();

		virtual Dynamic set_onKeyDown( Dynamic value);
		Dynamic set_onKeyDown_dyn();

		virtual Dynamic get_onKeyDown( );
		Dynamic get_onKeyDown_dyn();

		virtual Dynamic set_onKeyUp( Dynamic value);
		Dynamic set_onKeyUp_dyn();

		virtual Dynamic get_onKeyUp( );
		Dynamic get_onKeyUp_dyn();

		virtual Void onKeyDownCallback( ::cocktail::core::event::KeyboardEvent keyEventData);
		Dynamic onKeyDownCallback_dyn();

		virtual Void onKeyUpCallback( ::cocktail::core::event::KeyboardEvent keyEventData);
		Dynamic onKeyUpCallback_dyn();

		virtual bool isFocusable( );
		Dynamic isFocusable_dyn();

		virtual bool isDefaultFocusable( );
		Dynamic isDefaultFocusable_dyn();

		virtual Void focus( );
		Dynamic focus_dyn();

		virtual Void blur( );
		Dynamic blur_dyn();

		virtual Dynamic set_onFocus( Dynamic value);
		Dynamic set_onFocus_dyn();

		virtual Dynamic get_onFocus( );
		Dynamic get_onFocus_dyn();

		virtual Dynamic set_onBlur( Dynamic value);
		Dynamic set_onBlur_dyn();

		virtual Dynamic get_onBlur( );
		Dynamic get_onBlur_dyn();

		virtual Dynamic set_tabIndex( Dynamic value);
		Dynamic set_tabIndex_dyn();

		virtual Dynamic get_tabIndex( );
		Dynamic get_tabIndex_dyn();

		virtual Dynamic set_onScroll( Dynamic value);
		Dynamic set_onScroll_dyn();

		virtual Dynamic get_onScroll( );
		Dynamic get_onScroll_dyn();

		virtual Void onScrollCallback( ::cocktail::core::event::Event event);
		Dynamic onScrollCallback_dyn();

		virtual int get_scrollHeight( );
		Dynamic get_scrollHeight_dyn();

		virtual int get_scrollWidth( );
		Dynamic get_scrollWidth_dyn();

		virtual int set_scrollLeft( int value);
		Dynamic set_scrollLeft_dyn();

		virtual int get_scrollLeft( );
		Dynamic get_scrollLeft_dyn();

		virtual int set_scrollTop( int value);
		Dynamic set_scrollTop_dyn();

		virtual int get_scrollTop( );
		Dynamic get_scrollTop_dyn();

		virtual Dynamic get_nativeElement( );
		Dynamic get_nativeElement_dyn();

		virtual ::String get_id( );
		Dynamic get_id_dyn();

		virtual ::String set_id( ::String value);
		Dynamic set_id_dyn();

		virtual ::String set_innerHTML( ::String value);
		Dynamic set_innerHTML_dyn();

		virtual ::String get_innerHTML( );
		Dynamic get_innerHTML_dyn();

		virtual ::cocktail::core::html::HTMLElement get_offsetParent( );
		Dynamic get_offsetParent_dyn();

		virtual int get_offsetWidth( );
		Dynamic get_offsetWidth_dyn();

		virtual int get_offsetHeight( );
		Dynamic get_offsetHeight_dyn();

		virtual int get_offsetLeft( );
		Dynamic get_offsetLeft_dyn();

		virtual int get_offsetTop( );
		Dynamic get_offsetTop_dyn();

		virtual int get_clientWidth( );
		Dynamic get_clientWidth_dyn();

		virtual int get_clientHeight( );
		Dynamic get_clientHeight_dyn();

		virtual int get_clientTop( );
		Dynamic get_clientTop_dyn();

		virtual int get_clientLeft( );
		Dynamic get_clientLeft_dyn();

		virtual ::cocktail::core::style::CoreStyle get_coreStyle( );
		Dynamic get_coreStyle_dyn();

		virtual ::cocktail::core::style::adapter::Style get_style( );
		Dynamic get_style_dyn();

		static ::String HTML_ID_ATTRIBUTE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLElement */ 
