#ifndef INCLUDED_nme_events_IOErrorEvent
#define INCLUDED_nme_events_IOErrorEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/ErrorEvent.h>
HX_DECLARE_CLASS2(nme,events,ErrorEvent)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,IOErrorEvent)
HX_DECLARE_CLASS2(nme,events,TextEvent)
namespace nme{
namespace events{


class IOErrorEvent_obj : public ::nme::events::ErrorEvent_obj{
	public:
		typedef ::nme::events::ErrorEvent_obj super;
		typedef IOErrorEvent_obj OBJ_;
		IOErrorEvent_obj();
		Void __construct(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_text,Dynamic __o_id);

	public:
		static hx::ObjectPtr< IOErrorEvent_obj > __new(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_text,Dynamic __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IOErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("IOErrorEvent"); }

		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::String IO_ERROR; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_IOErrorEvent */ 
