#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#define INCLUDED_cocktail_core_event_KeyboardEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class KeyboardEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef KeyboardEvent_obj OBJ_;
		KeyboardEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< KeyboardEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("KeyboardEvent"); }

		virtual Void initKeyboardEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,::String charArg,::String keyArg,int locationArg,::String modifiersListArg,bool repeatArg,::String localeArg);
		Dynamic initKeyboardEvent_dyn();

		bool repeat; /* REM */ 
		bool metaKey; /* REM */ 
		bool altKey; /* REM */ 
		bool shiftKey; /* REM */ 
		bool ctrlKey; /* REM */ 
		::String locale; /* REM */ 
		int location; /* REM */ 
		::String key; /* REM */ 
		::String keyChar; /* REM */ 
		static int DOM_KEY_LOCATION_STANDARD; /* REM */ 
		static int DOM_KEY_LOCATION_LEFT; /* REM */ 
		static int DOM_KEY_LOCATION_RIGHT; /* REM */ 
		static int DOM_KEY_LOCATION_NUMPAD; /* REM */ 
		static int DOM_KEY_LOCATION_MOBILE; /* REM */ 
		static int DOM_KEY_LOCATION_JOYSTICK; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_KeyboardEvent */ 
