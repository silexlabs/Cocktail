#ifndef INCLUDED_core_event_UIEvent
#define INCLUDED_core_event_UIEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/event/Event.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace event{


class UIEvent_obj : public ::core::event::Event_obj{
	public:
		typedef ::core::event::Event_obj super;
		typedef UIEvent_obj OBJ_;
		UIEvent_obj();
		Void __construct(::String type,::port::flash_player::HTMLElement target,double detail);

	public:
		static hx::ObjectPtr< UIEvent_obj > __new(::String type,::port::flash_player::HTMLElement target,double detail);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UIEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("UIEvent"); }

		double _detail; /* REM */ 
		double detail; /* REM */ 
		virtual double get_detail( );
		Dynamic get_detail_dyn();

		virtual double set_detail( double value);
		Dynamic set_detail_dyn();

};

} // end namespace core
} // end namespace event

#endif /* INCLUDED_core_event_UIEvent */ 
