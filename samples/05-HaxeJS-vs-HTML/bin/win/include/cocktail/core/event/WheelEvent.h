#ifndef INCLUDED_cocktail_core_event_WheelEvent
#define INCLUDED_cocktail_core_event_WheelEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/MouseEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,event,WheelEvent)
namespace cocktail{
namespace core{
namespace event{


class WheelEvent_obj : public ::cocktail::core::event::MouseEvent_obj{
	public:
		typedef ::cocktail::core::event::MouseEvent_obj super;
		typedef WheelEvent_obj OBJ_;
		WheelEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< WheelEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WheelEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WheelEvent"); }

		virtual Void initWheelEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,int screenXArg,int screenYArg,int clientXArg,int clientYArg,int buttonArg,::cocktail::core::event::EventTarget relatedTargetArg,::String modifiersListArg,Float deltaXArg,Float deltaYArg,Float deltaZArg,int deltaModeArg);
		Dynamic initWheelEvent_dyn();

		int deltaMode; /* REM */ 
		Float deltaZ; /* REM */ 
		Float deltaY; /* REM */ 
		Float deltaX; /* REM */ 
		static int DOM_DELTA_PIXEL; /* REM */ 
		static int DOM_DELTA_LINE; /* REM */ 
		static int DOM_DELTA_PAGE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_WheelEvent */ 
