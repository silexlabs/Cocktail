#ifndef INCLUDED_cocktail_core_event_PopStateEvent
#define INCLUDED_cocktail_core_event_PopStateEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,PopStateEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class PopStateEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef PopStateEvent_obj OBJ_;
		PopStateEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PopStateEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PopStateEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PopStateEvent"); }

		virtual Void initPopStateEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,Dynamic state);
		Dynamic initPopStateEvent_dyn();

		Dynamic state; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_PopStateEvent */ 
