#ifndef INCLUDED_cocktail_core_event_Event
#define INCLUDED_cocktail_core_event_Event

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
namespace cocktail{
namespace core{
namespace event{


class Event_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Event_obj OBJ_;
		Event_obj();
		Void __construct(::String type,::cocktail::core::event::IEventTarget target);

	public:
		static hx::ObjectPtr< Event_obj > __new(::String type,::cocktail::core::event::IEventTarget target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Event_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Event"); }

		::String _type; /* REM */ 
		::String type; /* REM */ 
		::cocktail::core::event::IEventTarget _target; /* REM */ 
		::cocktail::core::event::IEventTarget target; /* REM */ 
		bool _defaultPrevented; /* REM */ 
		bool defaultPrevented; /* REM */ 
		virtual Void preventDefault( );
		Dynamic preventDefault_dyn();

		virtual bool get_defaultPrevented( );
		Dynamic get_defaultPrevented_dyn();

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual ::cocktail::core::event::IEventTarget get_target( );
		Dynamic get_target_dyn();

		static ::String SCROLL; /* REM */ 
		static ::String LOAD; /* REM */ 
		static ::String FOCUS; /* REM */ 
		static ::String BLUR; /* REM */ 
		static ::String ERROR; /* REM */ 
		static ::String READY_STATE_CHANGE; /* REM */ 
		static ::String RESIZE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_Event */ 