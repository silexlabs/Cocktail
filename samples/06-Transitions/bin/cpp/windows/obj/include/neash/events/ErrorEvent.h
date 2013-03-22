#ifndef INCLUDED_neash_events_ErrorEvent
#define INCLUDED_neash_events_ErrorEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/TextEvent.h>
HX_DECLARE_CLASS2(neash,events,ErrorEvent)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,TextEvent)
namespace neash{
namespace events{


class ErrorEvent_obj : public ::neash::events::TextEvent_obj{
	public:
		typedef ::neash::events::TextEvent_obj super;
		typedef ErrorEvent_obj OBJ_;
		ErrorEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);

	public:
		static hx::ObjectPtr< ErrorEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ErrorEvent"); }

		virtual ::String toString( );

		virtual ::neash::events::Event clone( );

		int errorID; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_ErrorEvent */ 
