#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#define INCLUDED_cocktail_core_event_KeyboardEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/UIEvent.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace event{


class KeyboardEvent_obj : public ::cocktail::core::event::UIEvent_obj{
	public:
		typedef ::cocktail::core::event::UIEvent_obj super;
		typedef KeyboardEvent_obj OBJ_;
		KeyboardEvent_obj();
		Void __construct(::String type,::cocktail::core::html::HTMLElement target,double detail,int keyChar,int key,bool ctrlKey,bool shiftKey,bool altKey);

	public:
		static hx::ObjectPtr< KeyboardEvent_obj > __new(::String type,::cocktail::core::html::HTMLElement target,double detail,int keyChar,int key,bool ctrlKey,bool shiftKey,bool altKey);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("KeyboardEvent"); }

		int _keyChar; /* REM */ 
		int keyChar; /* REM */ 
		int _key; /* REM */ 
		int key; /* REM */ 
		bool _ctrlKey; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool _shiftKey; /* REM */ 
		bool shiftKey; /* REM */ 
		bool _altKey; /* REM */ 
		bool altKey; /* REM */ 
		virtual bool get_altKey( );
		Dynamic get_altKey_dyn();

		virtual bool get_shiftKey( );
		Dynamic get_shiftKey_dyn();

		virtual bool get_ctrlKey( );
		Dynamic get_ctrlKey_dyn();

		virtual int get_keyChar( );
		Dynamic get_keyChar_dyn();

		virtual int get_key( );
		Dynamic get_key_dyn();

		static ::String KEY_DOWN; /* REM */ 
		static ::String KEY_UP; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_KeyboardEvent */ 