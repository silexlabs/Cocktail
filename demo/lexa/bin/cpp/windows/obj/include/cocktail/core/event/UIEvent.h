#ifndef INCLUDED_cocktail_core_event_UIEvent
#define INCLUDED_cocktail_core_event_UIEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/Event.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace event{


class UIEvent_obj : public ::cocktail::core::event::Event_obj{
	public:
		typedef ::cocktail::core::event::Event_obj super;
		typedef UIEvent_obj OBJ_;
		UIEvent_obj();
		Void __construct(::String type,::cocktail::port::flash_player::HTMLElement target,double detail);

	public:
		static hx::ObjectPtr< UIEvent_obj > __new(::String type,::cocktail::port::flash_player::HTMLElement target,double detail);
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

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_UIEvent */ 
