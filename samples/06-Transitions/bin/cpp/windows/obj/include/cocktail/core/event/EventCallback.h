#ifndef INCLUDED_cocktail_core_event_EventCallback
#define INCLUDED_cocktail_core_event_EventCallback

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,FocusEvent)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,PopStateEvent)
HX_DECLARE_CLASS3(cocktail,core,event,TransitionEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,event,WheelEvent)
namespace cocktail{
namespace core{
namespace event{


class EventCallback_obj : public ::cocktail::core::event::EventTarget_obj{
	public:
		typedef ::cocktail::core::event::EventTarget_obj super;
		typedef EventCallback_obj OBJ_;
		EventCallback_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EventCallback_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventCallback_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventCallback"); }

		virtual Dynamic set_onPopState( Dynamic value);
		Dynamic set_onPopState_dyn();

		virtual Dynamic set_onTransitionEnd( Dynamic value);
		Dynamic set_onTransitionEnd_dyn();

		virtual Dynamic set_onVolumeChange( Dynamic value);
		Dynamic set_onVolumeChange_dyn();

		virtual Dynamic set_onPause( Dynamic value);
		Dynamic set_onPause_dyn();

		virtual Dynamic set_onPlay( Dynamic value);
		Dynamic set_onPlay_dyn();

		virtual Dynamic set_onTimeUpdate( Dynamic value);
		Dynamic set_onTimeUpdate_dyn();

		virtual Dynamic set_onDurationChanged( Dynamic value);
		Dynamic set_onDurationChanged_dyn();

		virtual Dynamic set_onEnded( Dynamic value);
		Dynamic set_onEnded_dyn();

		virtual Dynamic set_onSeeked( Dynamic value);
		Dynamic set_onSeeked_dyn();

		virtual Dynamic set_onSeeking( Dynamic value);
		Dynamic set_onSeeking_dyn();

		virtual Dynamic set_onWaiting( Dynamic value);
		Dynamic set_onWaiting_dyn();

		virtual Dynamic set_onPlaying( Dynamic value);
		Dynamic set_onPlaying_dyn();

		virtual Dynamic set_onCanPlayThrough( Dynamic value);
		Dynamic set_onCanPlayThrough_dyn();

		virtual Dynamic set_onCanPlay( Dynamic value);
		Dynamic set_onCanPlay_dyn();

		virtual Dynamic set_onLoadedData( Dynamic value);
		Dynamic set_onLoadedData_dyn();

		virtual Dynamic set_onLoadedMetadata( Dynamic value);
		Dynamic set_onLoadedMetadata_dyn();

		virtual Dynamic set_onStalled( Dynamic value);
		Dynamic set_onStalled_dyn();

		virtual Dynamic set_onEmptied( Dynamic value);
		Dynamic set_onEmptied_dyn();

		virtual Dynamic set_onSuspend( Dynamic value);
		Dynamic set_onSuspend_dyn();

		virtual Dynamic set_onProgress( Dynamic value);
		Dynamic set_onProgress_dyn();

		virtual Dynamic set_onLoadStart( Dynamic value);
		Dynamic set_onLoadStart_dyn();

		virtual Dynamic set_onInput( Dynamic value);
		Dynamic set_onInput_dyn();

		virtual Dynamic set_onChange( Dynamic value);
		Dynamic set_onChange_dyn();

		virtual Dynamic set_onError( Dynamic value);
		Dynamic set_onError_dyn();

		virtual Dynamic set_onLoad( Dynamic value);
		Dynamic set_onLoad_dyn();

		virtual Dynamic set_onScroll( Dynamic value);
		Dynamic set_onScroll_dyn();

		virtual Dynamic set_onFullScreenChange( Dynamic value);
		Dynamic set_onFullScreenChange_dyn();

		virtual Dynamic set_onResize( Dynamic value);
		Dynamic set_onResize_dyn();

		virtual Dynamic set_onBlur( Dynamic value);
		Dynamic set_onBlur_dyn();

		virtual Dynamic set_onFocus( Dynamic value);
		Dynamic set_onFocus_dyn();

		virtual Dynamic set_onKeyUp( Dynamic value);
		Dynamic set_onKeyUp_dyn();

		virtual Dynamic set_onKeyDown( Dynamic value);
		Dynamic set_onKeyDown_dyn();

		virtual Dynamic set_onMouseWheel( Dynamic value);
		Dynamic set_onMouseWheel_dyn();

		virtual Dynamic set_onMouseMove( Dynamic value);
		Dynamic set_onMouseMove_dyn();

		virtual Dynamic set_onMouseOut( Dynamic value);
		Dynamic set_onMouseOut_dyn();

		virtual Dynamic set_onMouseOver( Dynamic value);
		Dynamic set_onMouseOver_dyn();

		virtual Dynamic set_onMouseUp( Dynamic value);
		Dynamic set_onMouseUp_dyn();

		virtual Dynamic set_onMouseDown( Dynamic value);
		Dynamic set_onMouseDown_dyn();

		virtual Dynamic set_onDblClick( Dynamic value);
		Dynamic set_onDblClick_dyn();

		virtual Dynamic set_onClick( Dynamic value);
		Dynamic set_onClick_dyn();

		virtual Void updateCallbackListener( ::String eventType,Dynamic newListener,Dynamic oldListener);
		Dynamic updateCallbackListener_dyn();

		Dynamic onpopstate; /* REM */ 
		Dynamic &onpopstate_dyn() { return onpopstate;}
		Dynamic ontransitionend; /* REM */ 
		Dynamic &ontransitionend_dyn() { return ontransitionend;}
		Dynamic onvolumechange; /* REM */ 
		Dynamic &onvolumechange_dyn() { return onvolumechange;}
		Dynamic onpause; /* REM */ 
		Dynamic &onpause_dyn() { return onpause;}
		Dynamic onplay; /* REM */ 
		Dynamic &onplay_dyn() { return onplay;}
		Dynamic ontimeupdate; /* REM */ 
		Dynamic &ontimeupdate_dyn() { return ontimeupdate;}
		Dynamic ondurationchange; /* REM */ 
		Dynamic &ondurationchange_dyn() { return ondurationchange;}
		Dynamic onended; /* REM */ 
		Dynamic &onended_dyn() { return onended;}
		Dynamic onseeked; /* REM */ 
		Dynamic &onseeked_dyn() { return onseeked;}
		Dynamic onseeking; /* REM */ 
		Dynamic &onseeking_dyn() { return onseeking;}
		Dynamic onwaiting; /* REM */ 
		Dynamic &onwaiting_dyn() { return onwaiting;}
		Dynamic onplaying; /* REM */ 
		Dynamic &onplaying_dyn() { return onplaying;}
		Dynamic oncanplaythrough; /* REM */ 
		Dynamic &oncanplaythrough_dyn() { return oncanplaythrough;}
		Dynamic oncanplay; /* REM */ 
		Dynamic &oncanplay_dyn() { return oncanplay;}
		Dynamic onloadeddata; /* REM */ 
		Dynamic &onloadeddata_dyn() { return onloadeddata;}
		Dynamic onloadedmetadata; /* REM */ 
		Dynamic &onloadedmetadata_dyn() { return onloadedmetadata;}
		Dynamic onstalled; /* REM */ 
		Dynamic &onstalled_dyn() { return onstalled;}
		Dynamic onemptied; /* REM */ 
		Dynamic &onemptied_dyn() { return onemptied;}
		Dynamic onsuspend; /* REM */ 
		Dynamic &onsuspend_dyn() { return onsuspend;}
		Dynamic onprogress; /* REM */ 
		Dynamic &onprogress_dyn() { return onprogress;}
		Dynamic onloadstart; /* REM */ 
		Dynamic &onloadstart_dyn() { return onloadstart;}
		Dynamic oninput; /* REM */ 
		Dynamic &oninput_dyn() { return oninput;}
		Dynamic onchange; /* REM */ 
		Dynamic &onchange_dyn() { return onchange;}
		Dynamic onerror; /* REM */ 
		Dynamic &onerror_dyn() { return onerror;}
		Dynamic onload; /* REM */ 
		Dynamic &onload_dyn() { return onload;}
		Dynamic onscroll; /* REM */ 
		Dynamic &onscroll_dyn() { return onscroll;}
		Dynamic onfullscreenchange; /* REM */ 
		Dynamic &onfullscreenchange_dyn() { return onfullscreenchange;}
		Dynamic onresize; /* REM */ 
		Dynamic &onresize_dyn() { return onresize;}
		Dynamic onblur; /* REM */ 
		Dynamic &onblur_dyn() { return onblur;}
		Dynamic onfocus; /* REM */ 
		Dynamic &onfocus_dyn() { return onfocus;}
		Dynamic onkeyup; /* REM */ 
		Dynamic &onkeyup_dyn() { return onkeyup;}
		Dynamic onkeydown; /* REM */ 
		Dynamic &onkeydown_dyn() { return onkeydown;}
		Dynamic onmousewheel; /* REM */ 
		Dynamic &onmousewheel_dyn() { return onmousewheel;}
		Dynamic onmousemove; /* REM */ 
		Dynamic &onmousemove_dyn() { return onmousemove;}
		Dynamic onmouseout; /* REM */ 
		Dynamic &onmouseout_dyn() { return onmouseout;}
		Dynamic onmouseover; /* REM */ 
		Dynamic &onmouseover_dyn() { return onmouseover;}
		Dynamic onmouseup; /* REM */ 
		Dynamic &onmouseup_dyn() { return onmouseup;}
		Dynamic onmousedown; /* REM */ 
		Dynamic &onmousedown_dyn() { return onmousedown;}
		Dynamic ondblclick; /* REM */ 
		Dynamic &ondblclick_dyn() { return ondblclick;}
		Dynamic onclick; /* REM */ 
		Dynamic &onclick_dyn() { return onclick;}
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_EventCallback */ 
