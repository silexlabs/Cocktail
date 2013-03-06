#ifndef INCLUDED_native_events_Event
#define INCLUDED_native_events_Event

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,events,Event)
namespace native{
namespace events{


class Event_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Event_obj OBJ_;
		Event_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< Event_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Event_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Event"); }

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual Dynamic set_target( Dynamic v);
		Dynamic set_target_dyn();

		virtual Dynamic get_target( );
		Dynamic get_target_dyn();

		virtual int get_eventPhase( );
		Dynamic get_eventPhase_dyn();

		virtual Dynamic set_currentTarget( Dynamic v);
		Dynamic set_currentTarget_dyn();

		virtual Dynamic get_currentTarget( );
		Dynamic get_currentTarget_dyn();

		virtual bool get_cancelable( );
		Dynamic get_cancelable_dyn();

		virtual bool get_bubbles( );
		Dynamic get_bubbles_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void stopPropagation( );
		Dynamic stopPropagation_dyn();

		virtual Void stopImmediatePropagation( );
		Dynamic stopImmediatePropagation_dyn();

		virtual Void nmeSetPhase( int inPhase);
		Dynamic nmeSetPhase_dyn();

		virtual bool nmeGetIsCancelledNow( );
		Dynamic nmeGetIsCancelledNow_dyn();

		virtual bool nmeGetIsCancelled( );
		Dynamic nmeGetIsCancelled_dyn();

		virtual ::native::events::Event clone( );
		Dynamic clone_dyn();

		bool nmeIsCancelledNow; /* REM */ 
		bool nmeIsCancelled; /* REM */ 
		::String _type; /* REM */ 
		Dynamic _target; /* REM */ 
		int _eventPhase; /* REM */ 
		Dynamic _currentTarget; /* REM */ 
		bool _cancelable; /* REM */ 
		bool _bubbles; /* REM */ 
		::String type; /* REM */ 
		Dynamic target; /* REM */ 
		int eventPhase; /* REM */ 
		Dynamic currentTarget; /* REM */ 
		bool cancelable; /* REM */ 
		bool bubbles; /* REM */ 
		static ::String ACTIVATE; /* REM */ 
		static ::String ADDED; /* REM */ 
		static ::String ADDED_TO_STAGE; /* REM */ 
		static ::String CANCEL; /* REM */ 
		static ::String CHANGE; /* REM */ 
		static ::String CLOSE; /* REM */ 
		static ::String COMPLETE; /* REM */ 
		static ::String CONNECT; /* REM */ 
		static ::String CONTEXT3D_CREATE; /* REM */ 
		static ::String DEACTIVATE; /* REM */ 
		static ::String ENTER_FRAME; /* REM */ 
		static ::String ID3; /* REM */ 
		static ::String INIT; /* REM */ 
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

} // end namespace native
} // end namespace events

#endif /* INCLUDED_native_events_Event */ 
