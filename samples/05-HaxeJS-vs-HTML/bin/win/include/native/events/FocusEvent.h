#ifndef INCLUDED_native_events_FocusEvent
#define INCLUDED_native_events_FocusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/Event.h>
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,FocusEvent)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace native{
namespace events{


class FocusEvent_obj : public ::native::events::Event_obj{
	public:
		typedef ::native::events::Event_obj super;
		typedef FocusEvent_obj OBJ_;
		FocusEvent_obj();
		Void __construct(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::native::display::InteractiveObject relatedObject,hx::Null< bool >  __o_shiftKey,hx::Null< int >  __o_keyCode,::String __o_direction);

	public:
		static hx::ObjectPtr< FocusEvent_obj > __new(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::native::display::InteractiveObject relatedObject,hx::Null< bool >  __o_shiftKey,hx::Null< int >  __o_keyCode,::String __o_direction);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FocusEvent"); }

		virtual ::String toString( );

		virtual ::native::events::Event clone( );

		bool shiftKey; /* REM */ 
		::native::display::InteractiveObject relatedObject; /* REM */ 
		int keyCode; /* REM */ 
		static ::String FOCUS_IN; /* REM */ 
		static ::String FOCUS_OUT; /* REM */ 
		static ::String KEY_FOCUS_CHANGE; /* REM */ 
		static ::String MOUSE_FOCUS_CHANGE; /* REM */ 
};

} // end namespace native
} // end namespace events

#endif /* INCLUDED_native_events_FocusEvent */ 
