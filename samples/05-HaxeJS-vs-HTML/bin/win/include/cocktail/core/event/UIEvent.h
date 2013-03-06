#ifndef INCLUDED_cocktail_core_event_UIEvent
#define INCLUDED_cocktail_core_event_UIEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/Event.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class UIEvent_obj : public ::cocktail::core::event::Event_obj{
	public:
		typedef ::cocktail::core::event::Event_obj super;
		typedef UIEvent_obj OBJ_;
		UIEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< UIEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UIEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UIEvent"); }

		virtual Void initUIEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg);
		Dynamic initUIEvent_dyn();

		Float detail; /* REM */ 
		Dynamic view; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_UIEvent */ 
