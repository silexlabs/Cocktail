#ifndef INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget
#define INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,ProgressEvent)
HX_DECLARE_CLASS3(cocktail,core,event,XMLHttpRequestEventTarget)
namespace cocktail{
namespace core{
namespace event{


class XMLHttpRequestEventTarget_obj : public ::cocktail::core::event::EventTarget_obj{
	public:
		typedef ::cocktail::core::event::EventTarget_obj super;
		typedef XMLHttpRequestEventTarget_obj OBJ_;
		XMLHttpRequestEventTarget_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< XMLHttpRequestEventTarget_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~XMLHttpRequestEventTarget_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("XMLHttpRequestEventTarget"); }

		virtual Dynamic set_onLoadEnd( Dynamic value);
		Dynamic set_onLoadEnd_dyn();

		virtual Dynamic set_onTimeout( Dynamic value);
		Dynamic set_onTimeout_dyn();

		virtual Dynamic set_onLoad( Dynamic value);
		Dynamic set_onLoad_dyn();

		virtual Dynamic set_onError( Dynamic value);
		Dynamic set_onError_dyn();

		virtual Dynamic set_onAbort( Dynamic value);
		Dynamic set_onAbort_dyn();

		virtual Dynamic set_onProgress( Dynamic value);
		Dynamic set_onProgress_dyn();

		virtual Dynamic set_onLoadStart( Dynamic value);
		Dynamic set_onLoadStart_dyn();

		virtual Void updateCallbackListener( ::String eventType,Dynamic newListener,Dynamic oldListener);
		Dynamic updateCallbackListener_dyn();

		Dynamic onloadend; /* REM */ 
		Dynamic &onloadend_dyn() { return onloadend;}
		Dynamic ontimeout; /* REM */ 
		Dynamic &ontimeout_dyn() { return ontimeout;}
		Dynamic onload; /* REM */ 
		Dynamic &onload_dyn() { return onload;}
		Dynamic onerror; /* REM */ 
		Dynamic &onerror_dyn() { return onerror;}
		Dynamic onabort; /* REM */ 
		Dynamic &onabort_dyn() { return onabort;}
		Dynamic onprogress; /* REM */ 
		Dynamic &onprogress_dyn() { return onprogress;}
		Dynamic onloadStart; /* REM */ 
		Dynamic &onloadStart_dyn() { return onloadStart;}
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget */ 
