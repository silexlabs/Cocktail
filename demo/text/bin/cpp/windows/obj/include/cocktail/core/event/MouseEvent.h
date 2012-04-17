#ifndef INCLUDED_cocktail_core_event_MouseEvent
#define INCLUDED_cocktail_core_event_MouseEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace event{


class MouseEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef MouseEvent_obj OBJ_;
		MouseEvent_obj();
		Void __construct(::String type,::cocktail::core::html::HTMLElement target,double detail,double screenX,double screenY,double clientX,double clientY,bool ctrlKey,bool shiftKey,bool altKey);

	public:
		static hx::ObjectPtr< MouseEvent_obj > __new(::String type,::cocktail::core::html::HTMLElement target,double detail,double screenX,double screenY,double clientX,double clientY,bool ctrlKey,bool shiftKey,bool altKey);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseEvent"); }

		double _screenX; /* REM */ 
		double screenX; /* REM */ 
		double _screenY; /* REM */ 
		double screenY; /* REM */ 
		double _clientX; /* REM */ 
		double clientX; /* REM */ 
		double _clientY; /* REM */ 
		double clientY; /* REM */ 
		bool _ctrlKey; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool _shiftKey; /* REM */ 
		bool shiftKey; /* REM */ 
		bool _altKey; /* REM */ 
		bool altKey; /* REM */ 
		virtual bool get_altKey( );
		Dynamic get_altKey_dyn();

		virtual bool get_shiftKey( );
		Dynamic get_shiftKey_dyn();

		virtual bool get_ctrlKey( );
		Dynamic get_ctrlKey_dyn();

		virtual double get_clientY( );
		Dynamic get_clientY_dyn();

		virtual double get_clientX( );
		Dynamic get_clientX_dyn();

		virtual double get_screenX( );
		Dynamic get_screenX_dyn();

		virtual double get_screenY( );
		Dynamic get_screenY_dyn();

		static ::String CLICK; /* REM */ 
		static ::String MOUSE_UP; /* REM */ 
		static ::String MOUSE_DOWN; /* REM */ 
		static ::String MOUSE_OVER; /* REM */ 
		static ::String MOUSE_OUT; /* REM */ 
		static ::String MOUSE_MOVE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_MouseEvent */ 
