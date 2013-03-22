#ifndef INCLUDED_cocktail_core_event_TransitionEvent
#define INCLUDED_cocktail_core_event_TransitionEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/Event.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,TransitionEvent)
namespace cocktail{
namespace core{
namespace event{


class TransitionEvent_obj : public ::cocktail::core::event::Event_obj{
	public:
		typedef ::cocktail::core::event::Event_obj super;
		typedef TransitionEvent_obj OBJ_;
		TransitionEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TransitionEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransitionEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TransitionEvent"); }

		virtual Void initTransitionEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,::String propertyNameArg,Float elapsedTimeArg,::String pseudoElementArg);
		Dynamic initTransitionEvent_dyn();

		::String pseudoElement; /* REM */ 
		Float elapsedTime; /* REM */ 
		::String propertyName; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_TransitionEvent */ 
