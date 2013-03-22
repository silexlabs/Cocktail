#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_FocusEvent
#include <cocktail/core/event/FocusEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_PopStateEvent
#include <cocktail/core/event/PopStateEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TransitionEvent
#include <cocktail/core/event/TransitionEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void EventCallback_obj::__construct()
{
HX_STACK_PUSH("EventCallback::new","cocktail/core/event/EventCallback.hx",292);
{
	HX_STACK_LINE(292)
	super::__construct();
}
;
	return null();
}

EventCallback_obj::~EventCallback_obj() { }

Dynamic EventCallback_obj::__CreateEmpty() { return  new EventCallback_obj; }
hx::ObjectPtr< EventCallback_obj > EventCallback_obj::__new()
{  hx::ObjectPtr< EventCallback_obj > result = new EventCallback_obj();
	result->__construct();
	return result;}

Dynamic EventCallback_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventCallback_obj > result = new EventCallback_obj();
	result->__construct();
	return result;}

Dynamic EventCallback_obj::set_onPopState( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onPopState","cocktail/core/event/EventCallback.hx",578);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(579)
	this->updateCallbackListener(HX_CSTRING("popstate"),value,this->onpopstate_dyn());
	HX_STACK_LINE(580)
	return this->onpopstate = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onPopState,return )

Dynamic EventCallback_obj::set_onTransitionEnd( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onTransitionEnd","cocktail/core/event/EventCallback.hx",569);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(570)
	this->updateCallbackListener(HX_CSTRING("transitionend"),value,this->ontransitionend_dyn());
	HX_STACK_LINE(571)
	return this->ontransitionend = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onTransitionEnd,return )

Dynamic EventCallback_obj::set_onVolumeChange( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onVolumeChange","cocktail/core/event/EventCallback.hx",560);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(561)
	this->updateCallbackListener(HX_CSTRING("volumechange"),value,this->onvolumechange_dyn());
	HX_STACK_LINE(562)
	return this->onvolumechange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onVolumeChange,return )

Dynamic EventCallback_obj::set_onPause( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onPause","cocktail/core/event/EventCallback.hx",554);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(555)
	this->updateCallbackListener(HX_CSTRING("pause"),value,this->onpause_dyn());
	HX_STACK_LINE(556)
	return this->onpause = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onPause,return )

Dynamic EventCallback_obj::set_onPlay( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onPlay","cocktail/core/event/EventCallback.hx",548);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(549)
	this->updateCallbackListener(HX_CSTRING("play"),value,this->onplay_dyn());
	HX_STACK_LINE(550)
	return this->onplay = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onPlay,return )

Dynamic EventCallback_obj::set_onTimeUpdate( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onTimeUpdate","cocktail/core/event/EventCallback.hx",542);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(543)
	this->updateCallbackListener(HX_CSTRING("timeupdate"),value,this->ontimeupdate_dyn());
	HX_STACK_LINE(544)
	return this->ontimeupdate = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onTimeUpdate,return )

Dynamic EventCallback_obj::set_onDurationChanged( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onDurationChanged","cocktail/core/event/EventCallback.hx",536);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(537)
	this->updateCallbackListener(HX_CSTRING("durationchange"),value,this->ondurationchange_dyn());
	HX_STACK_LINE(538)
	return this->ondurationchange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onDurationChanged,return )

Dynamic EventCallback_obj::set_onEnded( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onEnded","cocktail/core/event/EventCallback.hx",530);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(531)
	this->updateCallbackListener(HX_CSTRING("ended"),value,this->onended_dyn());
	HX_STACK_LINE(532)
	return this->onended = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onEnded,return )

Dynamic EventCallback_obj::set_onSeeked( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onSeeked","cocktail/core/event/EventCallback.hx",524);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(525)
	this->updateCallbackListener(HX_CSTRING("seeked"),value,this->onseeked_dyn());
	HX_STACK_LINE(526)
	return this->onseeked = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onSeeked,return )

Dynamic EventCallback_obj::set_onSeeking( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onSeeking","cocktail/core/event/EventCallback.hx",518);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(519)
	this->updateCallbackListener(HX_CSTRING("seeking"),value,this->onseeking_dyn());
	HX_STACK_LINE(520)
	return this->set_onWaiting(value);
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onSeeking,return )

Dynamic EventCallback_obj::set_onWaiting( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onWaiting","cocktail/core/event/EventCallback.hx",512);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(513)
	this->updateCallbackListener(HX_CSTRING("waiting"),value,this->onwaiting_dyn());
	HX_STACK_LINE(514)
	return this->onwaiting = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onWaiting,return )

Dynamic EventCallback_obj::set_onPlaying( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onPlaying","cocktail/core/event/EventCallback.hx",506);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(507)
	this->updateCallbackListener(HX_CSTRING("playing"),value,this->onplaying_dyn());
	HX_STACK_LINE(508)
	return this->onplaying = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onPlaying,return )

Dynamic EventCallback_obj::set_onCanPlayThrough( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onCanPlayThrough","cocktail/core/event/EventCallback.hx",500);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(501)
	this->updateCallbackListener(HX_CSTRING("canplaythrough"),value,this->oncanplaythrough_dyn());
	HX_STACK_LINE(502)
	return this->oncanplaythrough = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onCanPlayThrough,return )

Dynamic EventCallback_obj::set_onCanPlay( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onCanPlay","cocktail/core/event/EventCallback.hx",494);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(495)
	this->updateCallbackListener(HX_CSTRING("canplay"),value,this->oncanplay_dyn());
	HX_STACK_LINE(496)
	return this->oncanplay = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onCanPlay,return )

Dynamic EventCallback_obj::set_onLoadedData( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onLoadedData","cocktail/core/event/EventCallback.hx",488);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(489)
	this->updateCallbackListener(HX_CSTRING("loadeddata"),value,this->onloadeddata_dyn());
	HX_STACK_LINE(490)
	return this->onloadeddata = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onLoadedData,return )

Dynamic EventCallback_obj::set_onLoadedMetadata( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onLoadedMetadata","cocktail/core/event/EventCallback.hx",482);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(483)
	this->updateCallbackListener(HX_CSTRING("loadedmetadata"),value,this->onloadedmetadata_dyn());
	HX_STACK_LINE(484)
	return this->onloadedmetadata = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onLoadedMetadata,return )

Dynamic EventCallback_obj::set_onStalled( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onStalled","cocktail/core/event/EventCallback.hx",476);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(477)
	this->updateCallbackListener(HX_CSTRING("stalled"),value,this->onstalled_dyn());
	HX_STACK_LINE(478)
	return this->onstalled = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onStalled,return )

Dynamic EventCallback_obj::set_onEmptied( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onEmptied","cocktail/core/event/EventCallback.hx",470);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(471)
	this->updateCallbackListener(HX_CSTRING("emptied"),value,this->onemptied_dyn());
	HX_STACK_LINE(472)
	return this->onemptied = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onEmptied,return )

Dynamic EventCallback_obj::set_onSuspend( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onSuspend","cocktail/core/event/EventCallback.hx",464);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(465)
	this->updateCallbackListener(HX_CSTRING("suspend"),value,this->onsuspend_dyn());
	HX_STACK_LINE(466)
	return this->onsuspend = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onSuspend,return )

Dynamic EventCallback_obj::set_onProgress( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onProgress","cocktail/core/event/EventCallback.hx",458);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(459)
	this->updateCallbackListener(HX_CSTRING("progress"),value,this->onprogress_dyn());
	HX_STACK_LINE(460)
	return this->onprogress = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onProgress,return )

Dynamic EventCallback_obj::set_onLoadStart( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onLoadStart","cocktail/core/event/EventCallback.hx",452);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(453)
	this->updateCallbackListener(HX_CSTRING("loadstart"),value,this->onloadstart_dyn());
	HX_STACK_LINE(454)
	return this->onloadstart = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onLoadStart,return )

Dynamic EventCallback_obj::set_onInput( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onInput","cocktail/core/event/EventCallback.hx",443);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(444)
	this->updateCallbackListener(HX_CSTRING("input"),value,this->oninput_dyn());
	HX_STACK_LINE(445)
	return this->oninput = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onInput,return )

Dynamic EventCallback_obj::set_onChange( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onChange","cocktail/core/event/EventCallback.hx",437);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(438)
	this->updateCallbackListener(HX_CSTRING("change"),value,this->onchange_dyn());
	HX_STACK_LINE(439)
	return this->onchange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onChange,return )

Dynamic EventCallback_obj::set_onError( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onError","cocktail/core/event/EventCallback.hx",431);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(432)
	this->updateCallbackListener(HX_CSTRING("error"),value,this->onerror_dyn());
	HX_STACK_LINE(433)
	return this->onerror = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onError,return )

Dynamic EventCallback_obj::set_onLoad( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onLoad","cocktail/core/event/EventCallback.hx",425);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(426)
	this->updateCallbackListener(HX_CSTRING("load"),value,this->onload_dyn());
	HX_STACK_LINE(427)
	return this->onload = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onLoad,return )

Dynamic EventCallback_obj::set_onScroll( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onScroll","cocktail/core/event/EventCallback.hx",419);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(420)
	this->updateCallbackListener(HX_CSTRING("scroll"),value,this->onscroll_dyn());
	HX_STACK_LINE(421)
	return this->onscroll = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onScroll,return )

Dynamic EventCallback_obj::set_onFullScreenChange( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onFullScreenChange","cocktail/core/event/EventCallback.hx",413);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(414)
	this->updateCallbackListener(HX_CSTRING("fullscreenchange"),value,this->onfullscreenchange_dyn());
	HX_STACK_LINE(415)
	return this->onfullscreenchange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onFullScreenChange,return )

Dynamic EventCallback_obj::set_onResize( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onResize","cocktail/core/event/EventCallback.hx",407);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(408)
	this->updateCallbackListener(HX_CSTRING("resize"),value,this->onresize_dyn());
	HX_STACK_LINE(409)
	return this->onresize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onResize,return )

Dynamic EventCallback_obj::set_onBlur( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onBlur","cocktail/core/event/EventCallback.hx",398);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(399)
	this->updateCallbackListener(HX_CSTRING("blur"),value,this->onblur_dyn());
	HX_STACK_LINE(400)
	return this->onblur = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onBlur,return )

Dynamic EventCallback_obj::set_onFocus( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onFocus","cocktail/core/event/EventCallback.hx",392);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(393)
	this->updateCallbackListener(HX_CSTRING("focus"),value,this->onfocus_dyn());
	HX_STACK_LINE(394)
	return this->onfocus = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onFocus,return )

Dynamic EventCallback_obj::set_onKeyUp( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onKeyUp","cocktail/core/event/EventCallback.hx",383);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(384)
	this->updateCallbackListener(HX_CSTRING("keyup"),value,this->onkeyup_dyn());
	HX_STACK_LINE(385)
	return this->onkeyup = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onKeyUp,return )

Dynamic EventCallback_obj::set_onKeyDown( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onKeyDown","cocktail/core/event/EventCallback.hx",377);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(378)
	this->updateCallbackListener(HX_CSTRING("keydown"),value,this->onkeydown_dyn());
	HX_STACK_LINE(379)
	return this->onkeydown = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onKeyDown,return )

Dynamic EventCallback_obj::set_onMouseWheel( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseWheel","cocktail/core/event/EventCallback.hx",368);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(369)
	this->updateCallbackListener(HX_CSTRING("wheel"),value,this->onmousewheel_dyn());
	HX_STACK_LINE(370)
	return this->onmousewheel = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseWheel,return )

Dynamic EventCallback_obj::set_onMouseMove( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseMove","cocktail/core/event/EventCallback.hx",362);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(363)
	this->updateCallbackListener(HX_CSTRING("mousemove"),value,this->onmousemove_dyn());
	HX_STACK_LINE(364)
	return this->onmousemove = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseMove,return )

Dynamic EventCallback_obj::set_onMouseOut( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseOut","cocktail/core/event/EventCallback.hx",356);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(357)
	this->updateCallbackListener(HX_CSTRING("mouseout"),value,this->onmouseout_dyn());
	HX_STACK_LINE(358)
	return this->onmouseout = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseOut,return )

Dynamic EventCallback_obj::set_onMouseOver( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseOver","cocktail/core/event/EventCallback.hx",350);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(351)
	this->updateCallbackListener(HX_CSTRING("mouseover"),value,this->onmouseover_dyn());
	HX_STACK_LINE(352)
	return this->onmouseover = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseOver,return )

Dynamic EventCallback_obj::set_onMouseUp( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseUp","cocktail/core/event/EventCallback.hx",344);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(345)
	this->updateCallbackListener(HX_CSTRING("mouseup"),value,this->onmouseup_dyn());
	HX_STACK_LINE(346)
	return this->onmouseup = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseUp,return )

Dynamic EventCallback_obj::set_onMouseDown( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onMouseDown","cocktail/core/event/EventCallback.hx",338);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(339)
	this->updateCallbackListener(HX_CSTRING("mousedown"),value,this->onmousedown_dyn());
	HX_STACK_LINE(340)
	return this->onmousedown = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onMouseDown,return )

Dynamic EventCallback_obj::set_onDblClick( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onDblClick","cocktail/core/event/EventCallback.hx",332);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(333)
	this->updateCallbackListener(HX_CSTRING("dblclick"),value,this->ondblclick_dyn());
	HX_STACK_LINE(334)
	return this->ondblclick = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onDblClick,return )

Dynamic EventCallback_obj::set_onClick( Dynamic value){
	HX_STACK_PUSH("EventCallback::set_onClick","cocktail/core/event/EventCallback.hx",326);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(327)
	this->updateCallbackListener(HX_CSTRING("click"),value,this->onclick_dyn());
	HX_STACK_LINE(328)
	return this->onclick = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EventCallback_obj,set_onClick,return )

Void EventCallback_obj::updateCallbackListener( ::String eventType,Dynamic newListener,Dynamic oldListener){
{
		HX_STACK_PUSH("EventCallback::updateCallbackListener","cocktail/core/event/EventCallback.hx",303);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventType,"eventType");
		HX_STACK_ARG(newListener,"newListener");
		HX_STACK_ARG(oldListener,"oldListener");
		HX_STACK_LINE(306)
		if (((oldListener != null()))){
			HX_STACK_LINE(307)
			this->removeEventListener(eventType,oldListener,null());
		}
		HX_STACK_LINE(312)
		if (((newListener != null()))){
			HX_STACK_LINE(313)
			this->addEventListener(eventType,newListener,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventCallback_obj,updateCallbackListener,(void))


EventCallback_obj::EventCallback_obj()
{
}

void EventCallback_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventCallback);
	HX_MARK_MEMBER_NAME(onpopstate,"onpopstate");
	HX_MARK_MEMBER_NAME(ontransitionend,"ontransitionend");
	HX_MARK_MEMBER_NAME(onvolumechange,"onvolumechange");
	HX_MARK_MEMBER_NAME(onpause,"onpause");
	HX_MARK_MEMBER_NAME(onplay,"onplay");
	HX_MARK_MEMBER_NAME(ontimeupdate,"ontimeupdate");
	HX_MARK_MEMBER_NAME(ondurationchange,"ondurationchange");
	HX_MARK_MEMBER_NAME(onended,"onended");
	HX_MARK_MEMBER_NAME(onseeked,"onseeked");
	HX_MARK_MEMBER_NAME(onseeking,"onseeking");
	HX_MARK_MEMBER_NAME(onwaiting,"onwaiting");
	HX_MARK_MEMBER_NAME(onplaying,"onplaying");
	HX_MARK_MEMBER_NAME(oncanplaythrough,"oncanplaythrough");
	HX_MARK_MEMBER_NAME(oncanplay,"oncanplay");
	HX_MARK_MEMBER_NAME(onloadeddata,"onloadeddata");
	HX_MARK_MEMBER_NAME(onloadedmetadata,"onloadedmetadata");
	HX_MARK_MEMBER_NAME(onstalled,"onstalled");
	HX_MARK_MEMBER_NAME(onemptied,"onemptied");
	HX_MARK_MEMBER_NAME(onsuspend,"onsuspend");
	HX_MARK_MEMBER_NAME(onprogress,"onprogress");
	HX_MARK_MEMBER_NAME(onloadstart,"onloadstart");
	HX_MARK_MEMBER_NAME(oninput,"oninput");
	HX_MARK_MEMBER_NAME(onchange,"onchange");
	HX_MARK_MEMBER_NAME(onerror,"onerror");
	HX_MARK_MEMBER_NAME(onload,"onload");
	HX_MARK_MEMBER_NAME(onscroll,"onscroll");
	HX_MARK_MEMBER_NAME(onfullscreenchange,"onfullscreenchange");
	HX_MARK_MEMBER_NAME(onresize,"onresize");
	HX_MARK_MEMBER_NAME(onblur,"onblur");
	HX_MARK_MEMBER_NAME(onfocus,"onfocus");
	HX_MARK_MEMBER_NAME(onkeyup,"onkeyup");
	HX_MARK_MEMBER_NAME(onkeydown,"onkeydown");
	HX_MARK_MEMBER_NAME(onmousewheel,"onmousewheel");
	HX_MARK_MEMBER_NAME(onmousemove,"onmousemove");
	HX_MARK_MEMBER_NAME(onmouseout,"onmouseout");
	HX_MARK_MEMBER_NAME(onmouseover,"onmouseover");
	HX_MARK_MEMBER_NAME(onmouseup,"onmouseup");
	HX_MARK_MEMBER_NAME(onmousedown,"onmousedown");
	HX_MARK_MEMBER_NAME(ondblclick,"ondblclick");
	HX_MARK_MEMBER_NAME(onclick,"onclick");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EventCallback_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onpopstate,"onpopstate");
	HX_VISIT_MEMBER_NAME(ontransitionend,"ontransitionend");
	HX_VISIT_MEMBER_NAME(onvolumechange,"onvolumechange");
	HX_VISIT_MEMBER_NAME(onpause,"onpause");
	HX_VISIT_MEMBER_NAME(onplay,"onplay");
	HX_VISIT_MEMBER_NAME(ontimeupdate,"ontimeupdate");
	HX_VISIT_MEMBER_NAME(ondurationchange,"ondurationchange");
	HX_VISIT_MEMBER_NAME(onended,"onended");
	HX_VISIT_MEMBER_NAME(onseeked,"onseeked");
	HX_VISIT_MEMBER_NAME(onseeking,"onseeking");
	HX_VISIT_MEMBER_NAME(onwaiting,"onwaiting");
	HX_VISIT_MEMBER_NAME(onplaying,"onplaying");
	HX_VISIT_MEMBER_NAME(oncanplaythrough,"oncanplaythrough");
	HX_VISIT_MEMBER_NAME(oncanplay,"oncanplay");
	HX_VISIT_MEMBER_NAME(onloadeddata,"onloadeddata");
	HX_VISIT_MEMBER_NAME(onloadedmetadata,"onloadedmetadata");
	HX_VISIT_MEMBER_NAME(onstalled,"onstalled");
	HX_VISIT_MEMBER_NAME(onemptied,"onemptied");
	HX_VISIT_MEMBER_NAME(onsuspend,"onsuspend");
	HX_VISIT_MEMBER_NAME(onprogress,"onprogress");
	HX_VISIT_MEMBER_NAME(onloadstart,"onloadstart");
	HX_VISIT_MEMBER_NAME(oninput,"oninput");
	HX_VISIT_MEMBER_NAME(onchange,"onchange");
	HX_VISIT_MEMBER_NAME(onerror,"onerror");
	HX_VISIT_MEMBER_NAME(onload,"onload");
	HX_VISIT_MEMBER_NAME(onscroll,"onscroll");
	HX_VISIT_MEMBER_NAME(onfullscreenchange,"onfullscreenchange");
	HX_VISIT_MEMBER_NAME(onresize,"onresize");
	HX_VISIT_MEMBER_NAME(onblur,"onblur");
	HX_VISIT_MEMBER_NAME(onfocus,"onfocus");
	HX_VISIT_MEMBER_NAME(onkeyup,"onkeyup");
	HX_VISIT_MEMBER_NAME(onkeydown,"onkeydown");
	HX_VISIT_MEMBER_NAME(onmousewheel,"onmousewheel");
	HX_VISIT_MEMBER_NAME(onmousemove,"onmousemove");
	HX_VISIT_MEMBER_NAME(onmouseout,"onmouseout");
	HX_VISIT_MEMBER_NAME(onmouseover,"onmouseover");
	HX_VISIT_MEMBER_NAME(onmouseup,"onmouseup");
	HX_VISIT_MEMBER_NAME(onmousedown,"onmousedown");
	HX_VISIT_MEMBER_NAME(ondblclick,"ondblclick");
	HX_VISIT_MEMBER_NAME(onclick,"onclick");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EventCallback_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onplay") ) { return onplay; }
		if (HX_FIELD_EQ(inName,"onload") ) { return onload; }
		if (HX_FIELD_EQ(inName,"onblur") ) { return onblur; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onpause") ) { return onpause; }
		if (HX_FIELD_EQ(inName,"onended") ) { return onended; }
		if (HX_FIELD_EQ(inName,"oninput") ) { return oninput; }
		if (HX_FIELD_EQ(inName,"onerror") ) { return onerror; }
		if (HX_FIELD_EQ(inName,"onfocus") ) { return onfocus; }
		if (HX_FIELD_EQ(inName,"onkeyup") ) { return onkeyup; }
		if (HX_FIELD_EQ(inName,"onclick") ) { return onclick; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onseeked") ) { return onseeked; }
		if (HX_FIELD_EQ(inName,"onchange") ) { return onchange; }
		if (HX_FIELD_EQ(inName,"onscroll") ) { return onscroll; }
		if (HX_FIELD_EQ(inName,"onresize") ) { return onresize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onseeking") ) { return onseeking; }
		if (HX_FIELD_EQ(inName,"onwaiting") ) { return onwaiting; }
		if (HX_FIELD_EQ(inName,"onplaying") ) { return onplaying; }
		if (HX_FIELD_EQ(inName,"oncanplay") ) { return oncanplay; }
		if (HX_FIELD_EQ(inName,"onstalled") ) { return onstalled; }
		if (HX_FIELD_EQ(inName,"onemptied") ) { return onemptied; }
		if (HX_FIELD_EQ(inName,"onsuspend") ) { return onsuspend; }
		if (HX_FIELD_EQ(inName,"onkeydown") ) { return onkeydown; }
		if (HX_FIELD_EQ(inName,"onmouseup") ) { return onmouseup; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_onPlay") ) { return set_onPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onLoad") ) { return set_onLoad_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onBlur") ) { return set_onBlur_dyn(); }
		if (HX_FIELD_EQ(inName,"onpopstate") ) { return onpopstate; }
		if (HX_FIELD_EQ(inName,"onprogress") ) { return onprogress; }
		if (HX_FIELD_EQ(inName,"onmouseout") ) { return onmouseout; }
		if (HX_FIELD_EQ(inName,"ondblclick") ) { return ondblclick; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_onPause") ) { return set_onPause_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onEnded") ) { return set_onEnded_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onInput") ) { return set_onInput_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onError") ) { return set_onError_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onFocus") ) { return set_onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onKeyUp") ) { return set_onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onClick") ) { return set_onClick_dyn(); }
		if (HX_FIELD_EQ(inName,"onloadstart") ) { return onloadstart; }
		if (HX_FIELD_EQ(inName,"onmousemove") ) { return onmousemove; }
		if (HX_FIELD_EQ(inName,"onmouseover") ) { return onmouseover; }
		if (HX_FIELD_EQ(inName,"onmousedown") ) { return onmousedown; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_onSeeked") ) { return set_onSeeked_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onChange") ) { return set_onChange_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onScroll") ) { return set_onScroll_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onResize") ) { return set_onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"ontimeupdate") ) { return ontimeupdate; }
		if (HX_FIELD_EQ(inName,"onloadeddata") ) { return onloadeddata; }
		if (HX_FIELD_EQ(inName,"onmousewheel") ) { return onmousewheel; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_onSeeking") ) { return set_onSeeking_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onWaiting") ) { return set_onWaiting_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onPlaying") ) { return set_onPlaying_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onCanPlay") ) { return set_onCanPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onStalled") ) { return set_onStalled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onEmptied") ) { return set_onEmptied_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onSuspend") ) { return set_onSuspend_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onKeyDown") ) { return set_onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseUp") ) { return set_onMouseUp_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_onPopState") ) { return set_onPopState_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onProgress") ) { return set_onProgress_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseOut") ) { return set_onMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onDblClick") ) { return set_onDblClick_dyn(); }
		if (HX_FIELD_EQ(inName,"onvolumechange") ) { return onvolumechange; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_onLoadStart") ) { return set_onLoadStart_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseMove") ) { return set_onMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseOver") ) { return set_onMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseDown") ) { return set_onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"ontransitionend") ) { return ontransitionend; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_onTimeUpdate") ) { return set_onTimeUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onLoadedData") ) { return set_onLoadedData_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseWheel") ) { return set_onMouseWheel_dyn(); }
		if (HX_FIELD_EQ(inName,"ondurationchange") ) { return ondurationchange; }
		if (HX_FIELD_EQ(inName,"oncanplaythrough") ) { return oncanplaythrough; }
		if (HX_FIELD_EQ(inName,"onloadedmetadata") ) { return onloadedmetadata; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"set_onVolumeChange") ) { return set_onVolumeChange_dyn(); }
		if (HX_FIELD_EQ(inName,"onfullscreenchange") ) { return onfullscreenchange; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"set_onTransitionEnd") ) { return set_onTransitionEnd_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"set_onCanPlayThrough") ) { return set_onCanPlayThrough_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onLoadedMetadata") ) { return set_onLoadedMetadata_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"set_onDurationChanged") ) { return set_onDurationChanged_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"set_onFullScreenChange") ) { return set_onFullScreenChange_dyn(); }
		if (HX_FIELD_EQ(inName,"updateCallbackListener") ) { return updateCallbackListener_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventCallback_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onplay") ) { if (inCallProp) return set_onPlay(inValue);onplay=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onload") ) { if (inCallProp) return set_onLoad(inValue);onload=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onblur") ) { if (inCallProp) return set_onBlur(inValue);onblur=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onpause") ) { if (inCallProp) return set_onPause(inValue);onpause=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onended") ) { if (inCallProp) return set_onEnded(inValue);onended=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"oninput") ) { if (inCallProp) return set_onInput(inValue);oninput=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onerror") ) { if (inCallProp) return set_onError(inValue);onerror=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onfocus") ) { if (inCallProp) return set_onFocus(inValue);onfocus=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onkeyup") ) { if (inCallProp) return set_onKeyUp(inValue);onkeyup=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onclick") ) { if (inCallProp) return set_onClick(inValue);onclick=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onseeked") ) { if (inCallProp) return set_onSeeked(inValue);onseeked=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onchange") ) { if (inCallProp) return set_onChange(inValue);onchange=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onscroll") ) { if (inCallProp) return set_onScroll(inValue);onscroll=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onresize") ) { if (inCallProp) return set_onResize(inValue);onresize=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onseeking") ) { if (inCallProp) return set_onSeeking(inValue);onseeking=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onwaiting") ) { if (inCallProp) return set_onWaiting(inValue);onwaiting=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onplaying") ) { if (inCallProp) return set_onPlaying(inValue);onplaying=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"oncanplay") ) { if (inCallProp) return set_onCanPlay(inValue);oncanplay=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onstalled") ) { if (inCallProp) return set_onStalled(inValue);onstalled=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onemptied") ) { if (inCallProp) return set_onEmptied(inValue);onemptied=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onsuspend") ) { if (inCallProp) return set_onSuspend(inValue);onsuspend=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onkeydown") ) { if (inCallProp) return set_onKeyDown(inValue);onkeydown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmouseup") ) { if (inCallProp) return set_onMouseUp(inValue);onmouseup=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onpopstate") ) { if (inCallProp) return set_onPopState(inValue);onpopstate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onprogress") ) { if (inCallProp) return set_onProgress(inValue);onprogress=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmouseout") ) { if (inCallProp) return set_onMouseOut(inValue);onmouseout=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ondblclick") ) { if (inCallProp) return set_onDblClick(inValue);ondblclick=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onloadstart") ) { if (inCallProp) return set_onLoadStart(inValue);onloadstart=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmousemove") ) { if (inCallProp) return set_onMouseMove(inValue);onmousemove=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmouseover") ) { if (inCallProp) return set_onMouseOver(inValue);onmouseover=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmousedown") ) { if (inCallProp) return set_onMouseDown(inValue);onmousedown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ontimeupdate") ) { if (inCallProp) return set_onTimeUpdate(inValue);ontimeupdate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onloadeddata") ) { if (inCallProp) return set_onLoadedData(inValue);onloadeddata=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmousewheel") ) { if (inCallProp) return set_onMouseWheel(inValue);onmousewheel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onvolumechange") ) { if (inCallProp) return set_onVolumeChange(inValue);onvolumechange=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ontransitionend") ) { if (inCallProp) return set_onTransitionEnd(inValue);ontransitionend=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ondurationchange") ) { if (inCallProp) return set_onDurationChanged(inValue);ondurationchange=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"oncanplaythrough") ) { if (inCallProp) return set_onCanPlayThrough(inValue);oncanplaythrough=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onloadedmetadata") ) { if (inCallProp) return set_onLoadedMetadata(inValue);onloadedmetadata=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onfullscreenchange") ) { if (inCallProp) return set_onFullScreenChange(inValue);onfullscreenchange=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventCallback_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_onPopState"),
	HX_CSTRING("set_onTransitionEnd"),
	HX_CSTRING("set_onVolumeChange"),
	HX_CSTRING("set_onPause"),
	HX_CSTRING("set_onPlay"),
	HX_CSTRING("set_onTimeUpdate"),
	HX_CSTRING("set_onDurationChanged"),
	HX_CSTRING("set_onEnded"),
	HX_CSTRING("set_onSeeked"),
	HX_CSTRING("set_onSeeking"),
	HX_CSTRING("set_onWaiting"),
	HX_CSTRING("set_onPlaying"),
	HX_CSTRING("set_onCanPlayThrough"),
	HX_CSTRING("set_onCanPlay"),
	HX_CSTRING("set_onLoadedData"),
	HX_CSTRING("set_onLoadedMetadata"),
	HX_CSTRING("set_onStalled"),
	HX_CSTRING("set_onEmptied"),
	HX_CSTRING("set_onSuspend"),
	HX_CSTRING("set_onProgress"),
	HX_CSTRING("set_onLoadStart"),
	HX_CSTRING("set_onInput"),
	HX_CSTRING("set_onChange"),
	HX_CSTRING("set_onError"),
	HX_CSTRING("set_onLoad"),
	HX_CSTRING("set_onScroll"),
	HX_CSTRING("set_onFullScreenChange"),
	HX_CSTRING("set_onResize"),
	HX_CSTRING("set_onBlur"),
	HX_CSTRING("set_onFocus"),
	HX_CSTRING("set_onKeyUp"),
	HX_CSTRING("set_onKeyDown"),
	HX_CSTRING("set_onMouseWheel"),
	HX_CSTRING("set_onMouseMove"),
	HX_CSTRING("set_onMouseOut"),
	HX_CSTRING("set_onMouseOver"),
	HX_CSTRING("set_onMouseUp"),
	HX_CSTRING("set_onMouseDown"),
	HX_CSTRING("set_onDblClick"),
	HX_CSTRING("set_onClick"),
	HX_CSTRING("updateCallbackListener"),
	HX_CSTRING("onpopstate"),
	HX_CSTRING("ontransitionend"),
	HX_CSTRING("onvolumechange"),
	HX_CSTRING("onpause"),
	HX_CSTRING("onplay"),
	HX_CSTRING("ontimeupdate"),
	HX_CSTRING("ondurationchange"),
	HX_CSTRING("onended"),
	HX_CSTRING("onseeked"),
	HX_CSTRING("onseeking"),
	HX_CSTRING("onwaiting"),
	HX_CSTRING("onplaying"),
	HX_CSTRING("oncanplaythrough"),
	HX_CSTRING("oncanplay"),
	HX_CSTRING("onloadeddata"),
	HX_CSTRING("onloadedmetadata"),
	HX_CSTRING("onstalled"),
	HX_CSTRING("onemptied"),
	HX_CSTRING("onsuspend"),
	HX_CSTRING("onprogress"),
	HX_CSTRING("onloadstart"),
	HX_CSTRING("oninput"),
	HX_CSTRING("onchange"),
	HX_CSTRING("onerror"),
	HX_CSTRING("onload"),
	HX_CSTRING("onscroll"),
	HX_CSTRING("onfullscreenchange"),
	HX_CSTRING("onresize"),
	HX_CSTRING("onblur"),
	HX_CSTRING("onfocus"),
	HX_CSTRING("onkeyup"),
	HX_CSTRING("onkeydown"),
	HX_CSTRING("onmousewheel"),
	HX_CSTRING("onmousemove"),
	HX_CSTRING("onmouseout"),
	HX_CSTRING("onmouseover"),
	HX_CSTRING("onmouseup"),
	HX_CSTRING("onmousedown"),
	HX_CSTRING("ondblclick"),
	HX_CSTRING("onclick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventCallback_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventCallback_obj::__mClass,"__mClass");
};

Class EventCallback_obj::__mClass;

void EventCallback_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.EventCallback"), hx::TCanCast< EventCallback_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EventCallback_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
