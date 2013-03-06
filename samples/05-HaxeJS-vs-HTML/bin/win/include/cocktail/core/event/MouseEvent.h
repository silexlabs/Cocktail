#ifndef INCLUDED_cocktail_core_event_MouseEvent
#define INCLUDED_cocktail_core_event_MouseEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
namespace cocktail{
namespace core{
namespace event{


class MouseEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef MouseEvent_obj OBJ_;
		MouseEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MouseEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseEvent"); }

		virtual Void initMouseEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,int screenXArg,int screenYArg,int clientXArg,int clientYArg,bool ctrlKeyArg,bool altKeyArg,bool shiftKeyArg,bool metaKeyArg,int buttonArg,::cocktail::core::event::EventTarget relatedTargeArg);
		Dynamic initMouseEvent_dyn();

		::cocktail::core::event::EventTarget relatedTarget; /* REM */ 
		int button; /* REM */ 
		bool metaKey; /* REM */ 
		bool altKey; /* REM */ 
		bool shiftKey; /* REM */ 
		bool ctrlKey; /* REM */ 
		int clientY; /* REM */ 
		int clientX; /* REM */ 
		int screenY; /* REM */ 
		int screenX; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_MouseEvent */ 
