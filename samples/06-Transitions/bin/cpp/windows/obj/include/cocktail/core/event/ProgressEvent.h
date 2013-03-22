#ifndef INCLUDED_cocktail_core_event_ProgressEvent
#define INCLUDED_cocktail_core_event_ProgressEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/Event.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,ProgressEvent)
namespace cocktail{
namespace core{
namespace event{


class ProgressEvent_obj : public ::cocktail::core::event::Event_obj{
	public:
		typedef ::cocktail::core::event::Event_obj super;
		typedef ProgressEvent_obj OBJ_;
		ProgressEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ProgressEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProgressEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ProgressEvent"); }

		virtual Void initProgressEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,bool lengthComputableArg,Float loadedArg,Float totalArg);
		Dynamic initProgressEvent_dyn();

		Float total; /* REM */ 
		Float loaded; /* REM */ 
		bool lengthComputable; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_ProgressEvent */ 
