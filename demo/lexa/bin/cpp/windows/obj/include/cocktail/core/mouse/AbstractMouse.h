#ifndef INCLUDED_cocktail_core_mouse_AbstractMouse
#define INCLUDED_cocktail_core_mouse_AbstractMouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,mouse,AbstractMouse)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace mouse{


class AbstractMouse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractMouse_obj OBJ_;
		AbstractMouse_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractMouse_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractMouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractMouse"); }

		Dynamic _onClick; /* REM */ 
	Dynamic &_onClick_dyn() { return _onClick;}
		Dynamic onClick; /* REM */ 
	Dynamic &onClick_dyn() { return onClick;}
		Dynamic _onMouseDown; /* REM */ 
	Dynamic &_onMouseDown_dyn() { return _onMouseDown;}
		Dynamic onMouseDown; /* REM */ 
	Dynamic &onMouseDown_dyn() { return onMouseDown;}
		Dynamic _onMouseUp; /* REM */ 
	Dynamic &_onMouseUp_dyn() { return _onMouseUp;}
		Dynamic onMouseUp; /* REM */ 
	Dynamic &onMouseUp_dyn() { return onMouseUp;}
		Dynamic _onMouseOver; /* REM */ 
	Dynamic &_onMouseOver_dyn() { return _onMouseOver;}
		Dynamic onMouseOver; /* REM */ 
	Dynamic &onMouseOver_dyn() { return onMouseOver;}
		Dynamic _onMouseOut; /* REM */ 
	Dynamic &_onMouseOut_dyn() { return _onMouseOut;}
		Dynamic onMouseOut; /* REM */ 
	Dynamic &onMouseOut_dyn() { return onMouseOut;}
		Dynamic _onMouseMove; /* REM */ 
	Dynamic &_onMouseMove_dyn() { return _onMouseMove;}
		Dynamic onMouseMove; /* REM */ 
	Dynamic &onMouseMove_dyn() { return onMouseMove;}
		::String _clickEvent; /* REM */ 
		::String _mouseDownEvent; /* REM */ 
		::String _mouseUpEvent; /* REM */ 
		::String _mouseOverEvent; /* REM */ 
		::String _mouseOutEvent; /* REM */ 
		::String _mouseMoveEvent; /* REM */ 
		::cocktail::port::flash_player::HTMLElement _htmlElement; /* REM */ 
		virtual Void onNativeClick( Dynamic event);
		Dynamic onNativeClick_dyn();

		virtual Void onNativeMouseDown( Dynamic event);
		Dynamic onNativeMouseDown_dyn();

		virtual Void onNativeMouseUp( Dynamic event);
		Dynamic onNativeMouseUp_dyn();

		virtual Void onNativeMouseOver( Dynamic event);
		Dynamic onNativeMouseOver_dyn();

		virtual Void onNativeMouseOut( Dynamic event);
		Dynamic onNativeMouseOut_dyn();

		virtual Void onNativeMouseMove( Dynamic event);
		Dynamic onNativeMouseMove_dyn();

		virtual Void updateListeners( ::String mouseEvent,Dynamic nativeCallback,Dynamic htmlElementCallback);
		Dynamic updateListeners_dyn();

		virtual ::cocktail::core::event::MouseEvent getMouseEvent( Dynamic event);
		Dynamic getMouseEvent_dyn();

		virtual Dynamic set_onClick( Dynamic value);
		Dynamic set_onClick_dyn();

		virtual Dynamic get_onClick( );
		Dynamic get_onClick_dyn();

		virtual Dynamic setOnMouseDown( Dynamic value);
		Dynamic setOnMouseDown_dyn();

		virtual Dynamic getOnMouseDown( );
		Dynamic getOnMouseDown_dyn();

		virtual Dynamic setOnMouseUp( Dynamic value);
		Dynamic setOnMouseUp_dyn();

		virtual Dynamic getOnMouseUp( );
		Dynamic getOnMouseUp_dyn();

		virtual Dynamic setOnMouseOver( Dynamic value);
		Dynamic setOnMouseOver_dyn();

		virtual Dynamic getOnMouseOver( );
		Dynamic getOnMouseOver_dyn();

		virtual Dynamic setOnMouseOut( Dynamic value);
		Dynamic setOnMouseOut_dyn();

		virtual Dynamic getOnMouseOut( );
		Dynamic getOnMouseOut_dyn();

		virtual Dynamic setOnMouseMove( Dynamic value);
		Dynamic setOnMouseMove_dyn();

		virtual Dynamic getOnMouseMove( );
		Dynamic getOnMouseMove_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_cocktail_core_mouse_AbstractMouse */ 
