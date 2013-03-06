#ifndef INCLUDED_cocktail_core_multitouch_MultiTouchManager
#define INCLUDED_cocktail_core_multitouch_MultiTouchManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,TouchEvent)
HX_DECLARE_CLASS3(cocktail,core,event,TouchList)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,multitouch,MultiTouchManager)
namespace cocktail{
namespace core{
namespace multitouch{


class MultiTouchManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MultiTouchManager_obj OBJ_;
		MultiTouchManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MultiTouchManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MultiTouchManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MultiTouchManager"); }

		virtual Dynamic getTouchByIdentifier( int identifier);
		Dynamic getTouchByIdentifier_dyn();

		virtual ::cocktail::core::event::TouchList getTouchesByTarget( ::cocktail::core::html::HTMLElement target);
		Dynamic getTouchesByTarget_dyn();

		virtual Void initTouchEvent( ::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::event::TouchList targetTouches,::cocktail::core::event::TouchList changedTouches);
		Dynamic initTouchEvent_dyn();

		virtual Void updatePagePosition( Dynamic touch);
		Dynamic updatePagePosition_dyn();

		virtual Void updateStoredTouch( Dynamic storedTouch,Dynamic touch);
		Dynamic updateStoredTouch_dyn();

		virtual Void updateTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent);
		Dynamic updateTouch_dyn();

		virtual Void unregisterTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent);
		Dynamic unregisterTouch_dyn();

		virtual Void registerTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::html::HTMLElement target);
		Dynamic registerTouch_dyn();

		virtual Void setUpTouchEvent( ::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::html::HTMLElement target);
		Dynamic setUpTouchEvent_dyn();

		Dynamic _touches; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace multitouch

#endif /* INCLUDED_cocktail_core_multitouch_MultiTouchManager */ 
