#ifndef INCLUDED_cocktail_core_event_TouchEvent
#define INCLUDED_cocktail_core_event_TouchEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,TouchEvent)
HX_DECLARE_CLASS3(cocktail,core,event,TouchList)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class TouchEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef TouchEvent_obj OBJ_;
		TouchEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TouchEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchEvent"); }

		virtual Void initTouchEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,::cocktail::core::event::TouchList touchesArg,::cocktail::core::event::TouchList targetTouchesArg,::cocktail::core::event::TouchList changedTouchesArg,bool altKeyArg,bool metaKeyArg,bool ctrlKeyArg,bool shiftKeyArg);
		Dynamic initTouchEvent_dyn();

		bool shiftKey; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool metaKey; /* REM */ 
		bool altKey; /* REM */ 
		::cocktail::core::event::TouchList changedTouches; /* REM */ 
		::cocktail::core::event::TouchList targetTouches; /* REM */ 
		::cocktail::core::event::TouchList touches; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_TouchEvent */ 
