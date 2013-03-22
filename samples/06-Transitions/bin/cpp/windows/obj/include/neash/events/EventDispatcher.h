#ifndef INCLUDED_neash_events_EventDispatcher
#define INCLUDED_neash_events_EventDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/IEventDispatcher.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace neash{
namespace events{


class EventDispatcher_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventDispatcher_obj OBJ_;
		EventDispatcher_obj();
		Void __construct(::neash::events::IEventDispatcher target);

	public:
		static hx::ObjectPtr< EventDispatcher_obj > __new(::neash::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventDispatcher_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::neash::events::IEventDispatcher_obj *()
			{ return new ::neash::events::IEventDispatcher_delegate_< EventDispatcher_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("EventDispatcher"); }

		virtual bool willTrigger( ::String type);
		Dynamic willTrigger_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  capture);
		Dynamic removeEventListener_dyn();

		virtual bool hasEventListener( ::String type);
		Dynamic hasEventListener_dyn();

		virtual Void DispatchIOErrorEvent( );
		Dynamic DispatchIOErrorEvent_dyn();

		virtual bool dispatchEvent( ::neash::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual Void DispatchCompleteEvent( );
		Dynamic DispatchCompleteEvent_dyn();

		virtual Void addEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture,hx::Null< int >  priority,hx::Null< bool >  useWeakReference);
		Dynamic addEventListener_dyn();

		::neash::events::IEventDispatcher nmeTarget; /* REM */ 
		::Hash nmeEventMap; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_EventDispatcher */ 
