#ifndef INCLUDED_nme_events_TouchEvent
#define INCLUDED_nme_events_TouchEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/MouseEvent.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nme,events,TouchEvent)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace nme{
namespace events{


class TouchEvent_obj : public ::nme::events::MouseEvent_obj{
	public:
		typedef ::nme::events::MouseEvent_obj super;
		typedef TouchEvent_obj OBJ_;
		TouchEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount);

	public:
		static hx::ObjectPtr< TouchEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchEvent"); }

		bool isPrimaryTouchPoint; /* REM */ 
		int touchPointID; /* REM */ 
		virtual ::nme::events::MouseEvent nmeCreateSimilar( ::String inType,::nme::display::InteractiveObject related,::nme::display::InteractiveObject targ);
		Dynamic nmeCreateSimilar_dyn();

		static ::String TOUCH_BEGIN; /* REM */ 
		static ::String TOUCH_END; /* REM */ 
		static ::String TOUCH_MOVE; /* REM */ 
		static ::String TOUCH_OUT; /* REM */ 
		static ::String TOUCH_OVER; /* REM */ 
		static ::String TOUCH_ROLL_OUT; /* REM */ 
		static ::String TOUCH_ROLL_OVER; /* REM */ 
		static ::String TOUCH_TAP; /* REM */ 
		static ::nme::events::TouchEvent nmeCreate( ::String inType,Dynamic inEvent,::nme::geom::Point inLocal,::nme::display::InteractiveObject inTarget);
		static Dynamic nmeCreate_dyn();

};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_TouchEvent */ 
