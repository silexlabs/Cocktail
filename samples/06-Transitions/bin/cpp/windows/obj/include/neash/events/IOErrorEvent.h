#ifndef INCLUDED_neash_events_IOErrorEvent
#define INCLUDED_neash_events_IOErrorEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/ErrorEvent.h>
HX_DECLARE_CLASS2(neash,events,ErrorEvent)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,IOErrorEvent)
HX_DECLARE_CLASS2(neash,events,TextEvent)
namespace neash{
namespace events{


class IOErrorEvent_obj : public ::neash::events::ErrorEvent_obj{
	public:
		typedef ::neash::events::ErrorEvent_obj super;
		typedef IOErrorEvent_obj OBJ_;
		IOErrorEvent_obj();
		Void __construct(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);

	public:
		static hx::ObjectPtr< IOErrorEvent_obj > __new(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IOErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("IOErrorEvent"); }

		virtual ::String toString( );

		virtual ::neash::events::Event clone( );

		static ::String IO_ERROR; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_IOErrorEvent */ 
