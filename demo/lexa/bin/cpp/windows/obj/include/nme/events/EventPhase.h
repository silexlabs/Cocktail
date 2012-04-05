#ifndef INCLUDED_nme_events_EventPhase
#define INCLUDED_nme_events_EventPhase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,events,EventPhase)
namespace nme{
namespace events{


class EventPhase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventPhase_obj OBJ_;
		EventPhase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EventPhase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventPhase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventPhase"); }

		static int CAPTURING_PHASE; /* REM */ 
		static int AT_TARGET; /* REM */ 
		static int BUBBLING_PHASE; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_EventPhase */ 
