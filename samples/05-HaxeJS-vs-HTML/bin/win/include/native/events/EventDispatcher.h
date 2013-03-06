#ifndef INCLUDED_native_events_EventDispatcher
#define INCLUDED_native_events_EventDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/IEventDispatcher.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace native{
namespace events{


class EventDispatcher_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventDispatcher_obj OBJ_;
		EventDispatcher_obj();
		Void __construct(::native::events::IEventDispatcher target);

	public:
		static hx::ObjectPtr< EventDispatcher_obj > __new(::native::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventDispatcher_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::native::events::IEventDispatcher_obj *()
			{ return new ::native::events::IEventDispatcher_delegate_< EventDispatcher_obj >(this); }
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

		virtual bool dispatchEvent( ::native::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual Void DispatchCompleteEvent( );
		Dynamic DispatchCompleteEvent_dyn();

		virtual Void addEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture,hx::Null< int >  priority,hx::Null< bool >  useWeakReference);
		Dynamic addEventListener_dyn();

		::native::events::IEventDispatcher nmeTarget; /* REM */ 
		::Hash nmeEventMap; /* REM */ 
};

} // end namespace native
} // end namespace events

#endif /* INCLUDED_native_events_EventDispatcher */ 
