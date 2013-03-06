#ifndef INCLUDED_cocktail_core_event_FocusEvent
#define INCLUDED_cocktail_core_event_FocusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,FocusEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class FocusEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef FocusEvent_obj OBJ_;
		FocusEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FocusEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FocusEvent"); }

		virtual Void initFocusEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,::cocktail::core::event::EventTarget relatedTargetArg);
		Dynamic initFocusEvent_dyn();

		::cocktail::core::event::EventTarget relatedTarget; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_FocusEvent */ 
