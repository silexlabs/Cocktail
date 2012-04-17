#ifndef INCLUDED_nme_events_JoystickEvent
#define INCLUDED_nme_events_JoystickEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,JoystickEvent)
namespace nme{
namespace events{


class JoystickEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef JoystickEvent_obj OBJ_;
		JoystickEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_device,Dynamic __o_id,Dynamic __o_x,Dynamic __o_y,Dynamic __o_z);

	public:
		static hx::ObjectPtr< JoystickEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_device,Dynamic __o_id,Dynamic __o_x,Dynamic __o_y,Dynamic __o_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JoystickEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JoystickEvent"); }

		int device; /* REM */ 
		int id; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::String AXIS_MOVE; /* REM */ 
		static ::String BALL_MOVE; /* REM */ 
		static ::String BUTTON_DOWN; /* REM */ 
		static ::String BUTTON_UP; /* REM */ 
		static ::String HAT_MOVE; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_JoystickEvent */ 
