#ifndef INCLUDED_cocktail_core_event_EventConstants
#define INCLUDED_cocktail_core_event_EventConstants

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,EventConstants)
namespace cocktail{
namespace core{
namespace event{


class EventConstants_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventConstants_obj OBJ_;
		EventConstants_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EventConstants_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventConstants_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventConstants"); }

		static ::String PLAY; /* REM */ 
		static ::String PLAYING; /* REM */ 
		static ::String PAUSE; /* REM */ 
		static ::String ABORT; /* REM */ 
		static ::String LOAD_START; /* REM */ 
		static ::String WAITING; /* REM */ 
		static ::String TIME_UPDATE; /* REM */ 
		static ::String ENDED; /* REM */ 
		static ::String LOADED_DATA; /* REM */ 
		static ::String SEEKING; /* REM */ 
		static ::String SEEKED; /* REM */ 
		static ::String PROGRESS; /* REM */ 
		static ::String CAN_PLAY; /* REM */ 
		static ::String EMPTIED; /* REM */ 
		static ::String LOADED_METADATA; /* REM */ 
		static ::String DURATION_CHANGE; /* REM */ 
		static ::String VOLUME_CHANGE; /* REM */ 
		static ::String SUSPEND; /* REM */ 
		static ::String STALLED; /* REM */ 
		static ::String CAN_PLAY_THROUGH; /* REM */ 
		static ::String READY_STATE_CHANGE; /* REM */ 
		static ::String TIME_OUT; /* REM */ 
		static ::String LOAD_END; /* REM */ 
		static ::String FULL_SCREEN_CHANGE; /* REM */ 
		static ::String FOCUS; /* REM */ 
		static ::String BLUR; /* REM */ 
		static ::String FOCUS_IN; /* REM */ 
		static ::String FOCUS_OUT; /* REM */ 
		static ::String KEY_DOWN; /* REM */ 
		static ::String KEY_UP; /* REM */ 
		static ::String CLICK; /* REM */ 
		static ::String DOUBLE_CLICK; /* REM */ 
		static ::String MOUSE_UP; /* REM */ 
		static ::String MOUSE_DOWN; /* REM */ 
		static ::String MOUSE_OVER; /* REM */ 
		static ::String MOUSE_OUT; /* REM */ 
		static ::String MOUSE_MOVE; /* REM */ 
		static ::String MOUSE_LEAVE; /* REM */ 
		static ::String TOUCH_START; /* REM */ 
		static ::String TOUCH_END; /* REM */ 
		static ::String TOUCH_MOVE; /* REM */ 
		static ::String TOUCH_CANCEL; /* REM */ 
		static ::String TRANSITION_END; /* REM */ 
		static ::String SCROLL; /* REM */ 
		static ::String RESIZE; /* REM */ 
		static ::String LOAD; /* REM */ 
		static ::String ERROR; /* REM */ 
		static ::String MOUSE_WHEEL; /* REM */ 
		static ::String POP_STATE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_EventConstants */ 
