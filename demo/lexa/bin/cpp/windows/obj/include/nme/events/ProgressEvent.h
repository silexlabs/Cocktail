#ifndef INCLUDED_nme_events_ProgressEvent
#define INCLUDED_nme_events_ProgressEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,ProgressEvent)
namespace nme{
namespace events{


class ProgressEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef ProgressEvent_obj OBJ_;
		ProgressEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_bytesLoaded,Dynamic __o_bytesTotal);

	public:
		static hx::ObjectPtr< ProgressEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_bytesLoaded,Dynamic __o_bytesTotal);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProgressEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ProgressEvent"); }

		int bytesLoaded; /* REM */ 
		int bytesTotal; /* REM */ 
		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::String PROGRESS; /* REM */ 
		static ::String SOCKET_DATA; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_ProgressEvent */ 
