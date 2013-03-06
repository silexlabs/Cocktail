#ifndef INCLUDED_cocktail_core_event_Event
#define INCLUDED_cocktail_core_event_Event

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
namespace cocktail{
namespace core{
namespace event{


class Event_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Event_obj OBJ_;
		Event_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Event_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Event_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Event"); }

		virtual Void stopImmediatePropagation( );
		Dynamic stopImmediatePropagation_dyn();

		virtual Void stopPropagation( );
		Dynamic stopPropagation_dyn();

		virtual Void preventDefault( );
		Dynamic preventDefault_dyn();

		virtual Void initEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg);
		Dynamic initEvent_dyn();

		bool dispatched; /* REM */ 
		bool immediatePropagationStopped; /* REM */ 
		bool propagationStopped; /* REM */ 
		bool defaultPrevented; /* REM */ 
		bool cancelable; /* REM */ 
		bool bubbles; /* REM */ 
		::cocktail::core::event::EventTarget currentTarget; /* REM */ 
		::cocktail::core::event::EventTarget target; /* REM */ 
		::String type; /* REM */ 
		int eventPhase; /* REM */ 
		static int CAPTURING_PHASE; /* REM */ 
		static int AT_TARGET; /* REM */ 
		static int BUBBLING_PHASE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_Event */ 
