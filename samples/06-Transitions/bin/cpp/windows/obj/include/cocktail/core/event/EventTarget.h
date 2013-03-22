#ifndef INCLUDED_cocktail_core_event_EventTarget
#define INCLUDED_cocktail_core_event_EventTarget

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventListener)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
namespace cocktail{
namespace core{
namespace event{


class EventTarget_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventTarget_obj OBJ_;
		EventTarget_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EventTarget_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventTarget_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventTarget"); }

		virtual Void executeDefaultActionIfNeeded( bool defaultPrevented,::cocktail::core::event::Event event);
		Dynamic executeDefaultActionIfNeeded_dyn();

		virtual Array< ::cocktail::core::event::EventTarget > getTargetAncestors( );
		Dynamic getTargetAncestors_dyn();

		virtual bool endEventDispatching( ::cocktail::core::event::Event evt);
		Dynamic endEventDispatching_dyn();

		virtual bool shouldStopEventPropagation( ::cocktail::core::event::Event evt);
		Dynamic shouldStopEventPropagation_dyn();

		virtual Void doDispatchEvent( Array< ::cocktail::core::event::EventListener > eventListeners,::cocktail::core::event::Event evt);
		Dynamic doDispatchEvent_dyn();

		virtual Void removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture);
		Dynamic removeEventListener_dyn();

		virtual Void addEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture);
		Dynamic addEventListener_dyn();

		virtual bool dispatchEvent( ::cocktail::core::event::Event evt);
		Dynamic dispatchEvent_dyn();

		Array< ::cocktail::core::event::EventTarget > _targetAncestors; /* REM */ 
		::Hash _registeredEventListeners; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_EventTarget */ 
