#ifndef INCLUDED_cocktail_core_event_EventListener
#define INCLUDED_cocktail_core_event_EventListener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventListener)
namespace cocktail{
namespace core{
namespace event{


class EventListener_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventListener_obj OBJ_;
		EventListener_obj();
		Void __construct(::String eventType,Dynamic listener,bool useCapture);

	public:
		static hx::ObjectPtr< EventListener_obj > __new(::String eventType,Dynamic listener,bool useCapture);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventListener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventListener"); }

		virtual Void handleEvent( ::cocktail::core::event::Event evt);
		Dynamic handleEvent_dyn();

		::String eventType; /* REM */ 
		Dynamic listener; /* REM */ 
		Dynamic &listener_dyn() { return listener;}
		bool useCapture; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_EventListener */ 
