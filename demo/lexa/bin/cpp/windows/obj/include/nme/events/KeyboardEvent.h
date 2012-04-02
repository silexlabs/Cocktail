#ifndef INCLUDED_nme_events_KeyboardEvent
#define INCLUDED_nme_events_KeyboardEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,KeyboardEvent)
namespace nme{
namespace events{


class KeyboardEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef KeyboardEvent_obj OBJ_;
		KeyboardEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_charCodeValue,Dynamic __o_keyCodeValue,Dynamic __o_keyLocationValue,Dynamic __o_ctrlKeyValue,Dynamic __o_altKeyValue,Dynamic __o_shiftKeyValue,Dynamic __o_controlKeyValue,Dynamic __o_commandKeyValue);

	public:
		static hx::ObjectPtr< KeyboardEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_charCodeValue,Dynamic __o_keyCodeValue,Dynamic __o_keyLocationValue,Dynamic __o_ctrlKeyValue,Dynamic __o_altKeyValue,Dynamic __o_shiftKeyValue,Dynamic __o_controlKeyValue,Dynamic __o_commandKeyValue);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("KeyboardEvent"); }

		bool altKey; /* REM */ 
		int charCode; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool controlKey; /* REM */ 
		bool commandKey; /* REM */ 
		int keyCode; /* REM */ 
		int keyLocation; /* REM */ 
		bool shiftKey; /* REM */ 
		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::String KEY_DOWN; /* REM */ 
		static ::String KEY_UP; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_KeyboardEvent */ 
