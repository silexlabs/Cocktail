#ifndef INCLUDED_nme_events_Event
#define INCLUDED_nme_events_Event

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,events,Event)
namespace nme{
namespace events{


class Event_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Event_obj OBJ_;
		Event_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);

	public:
		static hx::ObjectPtr< Event_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Event_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Event"); }

		bool bubbles; /* REM */ 
		bool cancelable; /* REM */ 
		Dynamic currentTarget; /* REM */ 
		int eventPhase; /* REM */ 
		Dynamic target; /* REM */ 
		::String type; /* REM */ 
		bool _bubbles; /* REM */ 
		bool _cancelable; /* REM */ 
		Dynamic _currentTarget; /* REM */ 
		int _eventPhase; /* REM */ 
		Dynamic _target; /* REM */ 
		::String _type; /* REM */ 
		bool nmeIsCancelled; /* REM */ 
		bool nmeIsCancelledNow; /* REM */ 
		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual bool nmeGetIsCancelled( );
		Dynamic nmeGetIsCancelled_dyn();

		virtual bool nmeGetIsCancelledNow( );
		Dynamic nmeGetIsCancelledNow_dyn();

		virtual Void nmeSetPhase( int inPhase);
		Dynamic nmeSetPhase_dyn();

		virtual Void stopImmediatePropagation( );
		Dynamic stopImmediatePropagation_dyn();

		virtual Void stopPropagation( );
		Dynamic stopPropagation_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual bool nmeGetBubbles( );
		Dynamic nmeGetBubbles_dyn();

		virtual bool nmeGetCancelable( );
		Dynamic nmeGetCancelable_dyn();

		virtual Dynamic nmeGetCurrentTarget( );
		Dynamic nmeGetCurrentTarget_dyn();

		virtual Dynamic nmeSetCurrentTarget( Dynamic v);
		Dynamic nmeSetCurrentTarget_dyn();

		virtual int nmeGetEventPhase( );
		Dynamic nmeGetEventPhase_dyn();

		virtual Dynamic nmeGetTarget( );
		Dynamic nmeGetTarget_dyn();

		virtual Dynamic nmeSetTarget( Dynamic v);
		Dynamic nmeSetTarget_dyn();

		virtual ::String nmeGetType( );
		Dynamic nmeGetType_dyn();

		static ::String ACTIVATE; /* REM */ 
		static ::String ADDED; /* REM */ 
		static ::String ADDED_TO_STAGE; /* REM */ 
		static ::String CANCEL; /* REM */ 
		static ::String CHANGE; /* REM */ 
		static ::String CLOSE; /* REM */ 
		static ::String COMPLETE; /* REM */ 
		static ::String CONNECT; /* REM */ 
		static ::String DEACTIVATE; /* REM */ 
		static ::String ENTER_FRAME; /* REM */ 
		static ::String GOT_INPUT_FOCUS; /* REM */ 
		static ::String ID3; /* REM */ 
		static ::String INIT; /* REM */ 
		static ::String LOST_INPUT_FOCUS; /* REM */ 
		static ::String MOUSE_LEAVE; /* REM */ 
		static ::String OPEN; /* REM */ 
		static ::String REMOVED; /* REM */ 
		static ::String REMOVED_FROM_STAGE; /* REM */ 
		static ::String RENDER; /* REM */ 
		static ::String RESIZE; /* REM */ 
		static ::String SCROLL; /* REM */ 
		static ::String SELECT; /* REM */ 
		static ::String SOUND_COMPLETE; /* REM */ 
		static ::String TAB_CHILDREN_CHANGE; /* REM */ 
		static ::String TAB_ENABLED_CHANGE; /* REM */ 
		static ::String TAB_INDEX_CHANGE; /* REM */ 
		static ::String UNLOAD; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_Event */ 
