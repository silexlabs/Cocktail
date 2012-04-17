#ifndef INCLUDED_nme_events_EventDispatcher
#define INCLUDED_nme_events_EventDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/IEventDispatcher.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{
namespace events{


class EventDispatcher_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventDispatcher_obj OBJ_;
		EventDispatcher_obj();
		Void __construct(::nme::events::IEventDispatcher target);

	public:
		static hx::ObjectPtr< EventDispatcher_obj > __new(::nme::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventDispatcher_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::nme::events::IEventDispatcher_obj *()
			{ return new ::nme::events::IEventDispatcher_delegate_< EventDispatcher_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("EventDispatcher"); }

		::Hash nmeEventMap; /* REM */ 
		::nme::events::IEventDispatcher nmeTarget; /* REM */ 
		virtual Void addEventListener( ::String type,Dynamic listener,Dynamic useCapture,Dynamic priority,Dynamic useWeakReference);
		Dynamic addEventListener_dyn();

		virtual Void DispatchCompleteEvent( );
		Dynamic DispatchCompleteEvent_dyn();

		virtual bool dispatchEvent( ::nme::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual Void DispatchIOErrorEvent( );
		Dynamic DispatchIOErrorEvent_dyn();

		virtual bool hasEventListener( ::String type);
		Dynamic hasEventListener_dyn();

		virtual Void removeEventListener( ::String type,Dynamic listener,Dynamic capture);
		Dynamic removeEventListener_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual bool willTrigger( ::String type);
		Dynamic willTrigger_dyn();

};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_EventDispatcher */ 
