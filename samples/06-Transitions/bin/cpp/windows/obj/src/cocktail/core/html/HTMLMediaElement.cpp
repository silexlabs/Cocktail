#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#include <cocktail/core/html/HTMLMediaElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLSourceElement
#include <cocktail/core/html/HTMLSourceElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_TimeRanges
#include <cocktail/core/html/TimeRanges.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLMediaElement_obj::__construct(::String tagName)
{
HX_STACK_PUSH("HTMLMediaElement::new","cocktail/core/html/HTMLMediaElement.hx",306);
{
	HX_STACK_LINE(307)
	super::__construct(tagName);
	HX_STACK_LINE(309)
	this->networkState = (int)0;
	HX_STACK_LINE(310)
	this->ended = false;
	HX_STACK_LINE(311)
	this->duration = (int)0;
	HX_STACK_LINE(312)
	this->paused = true;
	HX_STACK_LINE(313)
	this->seeking = false;
	HX_STACK_LINE(314)
	this->readyState = (int)0;
	HX_STACK_LINE(315)
	this->_autoplaying = true;
	HX_STACK_LINE(316)
	this->set_volume(1.0);
	HX_STACK_LINE(317)
	this->set_muted(false);
	HX_STACK_LINE(319)
	this->_stalledByPreload = false;
	HX_STACK_LINE(320)
	this->_loadedDataWasDispatched = false;
	HX_STACK_LINE(321)
	this->_defaultPlaybackStartPosition = (int)0;
	HX_STACK_LINE(322)
	this->_officialPlaybackPosition = (int)0;
	HX_STACK_LINE(323)
	this->_currentPlaybackPosition = (int)0;
	HX_STACK_LINE(324)
	this->_initialPlaybackPosition = (int)0;
	HX_STACK_LINE(325)
	this->_earliestPossiblePosition = (int)0;
}
;
	return null();
}

HTMLMediaElement_obj::~HTMLMediaElement_obj() { }

Dynamic HTMLMediaElement_obj::__CreateEmpty() { return  new HTMLMediaElement_obj; }
hx::ObjectPtr< HTMLMediaElement_obj > HTMLMediaElement_obj::__new(::String tagName)
{  hx::ObjectPtr< HTMLMediaElement_obj > result = new HTMLMediaElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic HTMLMediaElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLMediaElement_obj > result = new HTMLMediaElement_obj();
	result->__construct(inArgs[0]);
	return result;}

Float HTMLMediaElement_obj::set_currentTime( Float value){
	HX_STACK_PUSH("HTMLMediaElement::set_currentTime","cocktail/core/html/HTMLMediaElement.hx",1222);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1223)
	switch( (int)(this->readyState)){
		case (int)0: {
			HX_STACK_LINE(1228)
			this->_defaultPlaybackStartPosition = value;
		}
		;break;
		default: {
			HX_STACK_LINE(1232)
			this->_officialPlaybackPosition = value;
			HX_STACK_LINE(1233)
			this->seek(value);
		}
	}
	HX_STACK_LINE(1236)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_currentTime,return )

Float HTMLMediaElement_obj::get_currentTime( ){
	HX_STACK_PUSH("HTMLMediaElement::get_currentTime","cocktail/core/html/HTMLMediaElement.hx",1208);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1213)
	if (((this->_defaultPlaybackStartPosition != (int)0))){
		HX_STACK_LINE(1214)
		return this->_defaultPlaybackStartPosition;
	}
	HX_STACK_LINE(1218)
	return this->_officialPlaybackPosition;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_currentTime,return )

::cocktail::core::html::TimeRanges HTMLMediaElement_obj::get_buffered( ){
	HX_STACK_PUSH("HTMLMediaElement::get_buffered","cocktail/core/html/HTMLMediaElement.hx",1193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1194)
	Dynamic ranges = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(ranges,"ranges");
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::html::HTMLMediaElement_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/html/HTMLMediaElement.hx",1198);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("start") , 0.0,false);
				__result->Add(HX_CSTRING("end") , (__this->duration * ((Float(__this->nativeMedia->get_bytesLoaded()) / Float(__this->nativeMedia->get_bytesTotal())))),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1198)
	ranges->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block(this));
	HX_STACK_LINE(1203)
	::cocktail::core::html::TimeRanges timeRanges = ::cocktail::core::html::TimeRanges_obj::__new(ranges);		HX_STACK_VAR(timeRanges,"timeRanges");
	HX_STACK_LINE(1204)
	return timeRanges;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_buffered,return )

Float HTMLMediaElement_obj::set_volume( Float value){
	HX_STACK_PUSH("HTMLMediaElement::set_volume","cocktail/core/html/HTMLMediaElement.hx",1180);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1181)
	if (((this->muted == false))){
		HX_STACK_LINE(1182)
		this->nativeMedia->set_volume(value);
	}
	HX_STACK_LINE(1186)
	this->volume = value;
	HX_STACK_LINE(1187)
	this->fireEvent(HX_CSTRING("volumechange"),false,false);
	HX_STACK_LINE(1189)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_volume,return )

bool HTMLMediaElement_obj::set_muted( bool value){
	HX_STACK_PUSH("HTMLMediaElement::set_muted","cocktail/core/html/HTMLMediaElement.hx",1159);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1162)
	if (((value == false))){
		HX_STACK_LINE(1163)
		this->nativeMedia->set_volume(this->volume);
	}
	else{
		HX_STACK_LINE(1169)
		this->nativeMedia->set_volume((int)0);
	}
	HX_STACK_LINE(1173)
	this->muted = value;
	HX_STACK_LINE(1174)
	this->fireEvent(HX_CSTRING("volumechange"),false,false);
	HX_STACK_LINE(1176)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_muted,return )

::String HTMLMediaElement_obj::set_preload( ::String value){
	HX_STACK_PUSH("HTMLMediaElement::set_preload","cocktail/core/html/HTMLMediaElement.hx",1131);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1134)
	::String _switch_1 = (value);
	if (  ( _switch_1==HX_CSTRING(""))){
		HX_STACK_LINE(1137)
		value = HX_CSTRING("auto");
	}
	else if (  ( _switch_1==HX_CSTRING("auto")) ||  ( _switch_1==HX_CSTRING("metadata")) ||  ( _switch_1==HX_CSTRING("none"))){
	}
	else  {
		HX_STACK_LINE(1145)
		value = HX_CSTRING("metadata");
	}
;
;
	HX_STACK_LINE(1149)
	this->super::setAttribute(HX_CSTRING("preload"),value);
	HX_STACK_LINE(1150)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_preload,return )

::String HTMLMediaElement_obj::get_preload( ){
	HX_STACK_PUSH("HTMLMediaElement::get_preload","cocktail/core/html/HTMLMediaElement.hx",1118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1119)
	::String preloadValue = this->super::getAttribute(HX_CSTRING("preload"));		HX_STACK_VAR(preloadValue,"preloadValue");
	HX_STACK_LINE(1123)
	if (((preloadValue == null()))){
		HX_STACK_LINE(1124)
		return HX_CSTRING("metadata");
	}
	HX_STACK_LINE(1127)
	return preloadValue;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_preload,return )

bool HTMLMediaElement_obj::set_loop( bool value){
	HX_STACK_PUSH("HTMLMediaElement::set_loop","cocktail/core/html/HTMLMediaElement.hx",1112);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1113)
	this->super::setAttribute(HX_CSTRING("loop"),::Std_obj::string(value));
	HX_STACK_LINE(1114)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_loop,return )

bool HTMLMediaElement_obj::get_loop( ){
	HX_STACK_PUSH("HTMLMediaElement::get_loop","cocktail/core/html/HTMLMediaElement.hx",1100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1100)
	if (((this->getAttribute(HX_CSTRING("loop")) != null()))){
		HX_STACK_LINE(1102)
		return true;
	}
	else{
		HX_STACK_LINE(1106)
		return false;
	}
	HX_STACK_LINE(1100)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_loop,return )

bool HTMLMediaElement_obj::set_autoplay( bool value){
	HX_STACK_PUSH("HTMLMediaElement::set_autoplay","cocktail/core/html/HTMLMediaElement.hx",1094);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1095)
	this->super::setAttribute(HX_CSTRING("autoplay"),::Std_obj::string(value));
	HX_STACK_LINE(1096)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_autoplay,return )

bool HTMLMediaElement_obj::get_autoplay( ){
	HX_STACK_PUSH("HTMLMediaElement::get_autoplay","cocktail/core/html/HTMLMediaElement.hx",1082);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1082)
	if (((this->getAttribute(HX_CSTRING("autoplay")) != null()))){
		HX_STACK_LINE(1084)
		return true;
	}
	else{
		HX_STACK_LINE(1088)
		return false;
	}
	HX_STACK_LINE(1082)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_autoplay,return )

::String HTMLMediaElement_obj::set_src( ::String value){
	HX_STACK_PUSH("HTMLMediaElement::set_src","cocktail/core/html/HTMLMediaElement.hx",1075);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1076)
	this->super::setAttribute(HX_CSTRING("src"),value);
	HX_STACK_LINE(1077)
	this->selectResource();
	HX_STACK_LINE(1078)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,set_src,return )

::String HTMLMediaElement_obj::get_src( ){
	HX_STACK_PUSH("HTMLMediaElement::get_src","cocktail/core/html/HTMLMediaElement.hx",1070);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1070)
	return this->getAttribute(HX_CSTRING("src"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,get_src,return )

Void HTMLMediaElement_obj::onProgressTick( Float timeStamp){
{
		HX_STACK_PUSH("HTMLMediaElement::onProgressTick","cocktail/core/html/HTMLMediaElement.hx",1037);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeStamp,"timeStamp");
		HX_STACK_LINE(1040)
		this->fireEvent(HX_CSTRING("progress"),false,false);
		HX_STACK_LINE(1044)
		if (((this->readyState == (int)1))){
			HX_STACK_LINE(1045)
			this->setReadyState((int)3);
		}
		HX_STACK_LINE(1050)
		if (((this->nativeMedia->get_bytesLoaded() >= this->nativeMedia->get_bytesTotal()))){
			HX_STACK_LINE(1052)
			this->setReadyState((int)4);
			HX_STACK_LINE(1054)
			this->networkState = (int)1;
			HX_STACK_LINE(1055)
			this->fireEvent(HX_CSTRING("suspend"),false,false);
			HX_STACK_LINE(1057)
			return null();
		}
		HX_STACK_LINE(1062)
		this->_ownerHTMLDocument->timer->delay(this->onProgressTick_dyn(),(int)350);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,onProgressTick,(void))

Void HTMLMediaElement_obj::onTimeUpdateTick( Float timeStamp){
{
		HX_STACK_PUSH("HTMLMediaElement::onTimeUpdateTick","cocktail/core/html/HTMLMediaElement.hx",981);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeStamp,"timeStamp");
		HX_STACK_LINE(984)
		if (((this->paused == true))){
			HX_STACK_LINE(985)
			return null();
		}
		HX_STACK_LINE(990)
		this->_currentPlaybackPosition = this->nativeMedia->get_currentTime();
		HX_STACK_LINE(991)
		this->_officialPlaybackPosition = this->_currentPlaybackPosition;
		HX_STACK_LINE(994)
		if ((((this->duration - this->_currentPlaybackPosition) < 0.2))){
			HX_STACK_LINE(998)
			if (((this->get_loop() == true))){
				HX_STACK_LINE(1000)
				this->seek((int)0);
				HX_STACK_LINE(1001)
				this->doPlay();
				HX_STACK_LINE(1002)
				return null();
			}
			HX_STACK_LINE(1004)
			this->ended = true;
			HX_STACK_LINE(1008)
			this->_currentPlaybackPosition = this->duration;
			HX_STACK_LINE(1009)
			this->_officialPlaybackPosition = this->_currentPlaybackPosition;
			HX_STACK_LINE(1012)
			this->fireEvent(HX_CSTRING("timeupdate"),false,false);
			HX_STACK_LINE(1015)
			if (((this->paused == false))){
				HX_STACK_LINE(1017)
				this->paused = true;
				HX_STACK_LINE(1018)
				this->fireEvent(HX_CSTRING("pause"),false,false);
			}
			HX_STACK_LINE(1021)
			this->fireEvent(HX_CSTRING("ended"),false,false);
			HX_STACK_LINE(1022)
			return null();
		}
		HX_STACK_LINE(1025)
		this->fireEvent(HX_CSTRING("timeupdate"),false,false);
		HX_STACK_LINE(1029)
		this->_ownerHTMLDocument->timer->delay(this->onTimeUpdateTick_dyn(),(int)250);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,onTimeUpdateTick,(void))

Void HTMLMediaElement_obj::onNativeMediaLoadedMetaData( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLMediaElement::onNativeMediaLoadedMetaData","cocktail/core/html/HTMLMediaElement.hx",949);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(950)
		this->intrinsicHeight = this->nativeMedia->get_height();
		HX_STACK_LINE(951)
		this->intrinsicWidth = this->nativeMedia->get_width();
		HX_STACK_LINE(952)
		this->intrinsicRatio = (Float(this->get_intrinsicHeight()) / Float(this->get_intrinsicWidth()));
		HX_STACK_LINE(955)
		this->establishMediaTimeline();
		HX_STACK_LINE(958)
		this->invalidate();
		HX_STACK_LINE(962)
		this->onProgressTick((int)0);
		HX_STACK_LINE(969)
		if (((this->_stalledByPreload == true))){
			HX_STACK_LINE(971)
			this->_stalledByPreload = false;
			HX_STACK_LINE(972)
			this->play();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,onNativeMediaLoadedMetaData,(void))

Void HTMLMediaElement_obj::onLoadingError( ::cocktail::core::event::Event error){
{
		HX_STACK_PUSH("HTMLMediaElement::onLoadingError","cocktail/core/html/HTMLMediaElement.hx",938);
		HX_STACK_THIS(this);
		HX_STACK_ARG(error,"error");
		HX_STACK_LINE(938)
		this->selectResource();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,onLoadingError,(void))

bool HTMLMediaElement_obj::hasChildSourceElement( ){
	HX_STACK_PUSH("HTMLMediaElement::hasChildSourceElement","cocktail/core/html/HTMLMediaElement.hx",921);
	HX_STACK_THIS(this);
	HX_STACK_LINE(922)
	{
		HX_STACK_LINE(922)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(922)
		while(((_g1 < _g))){
			HX_STACK_LINE(922)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(924)
			if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeName"),true)() == HX_CSTRING("SOURCE")))){
				HX_STACK_LINE(925)
				return true;
			}
		}
	}
	HX_STACK_LINE(930)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,hasChildSourceElement,return )

Void HTMLMediaElement_obj::establishMediaTimeline( ){
{
		HX_STACK_PUSH("HTMLMediaElement::establishMediaTimeline","cocktail/core/html/HTMLMediaElement.hx",890);
		HX_STACK_THIS(this);
		HX_STACK_LINE(891)
		this->_currentPlaybackPosition = (int)0;
		HX_STACK_LINE(892)
		this->_initialPlaybackPosition = (int)0;
		HX_STACK_LINE(893)
		this->_officialPlaybackPosition = (int)0;
		HX_STACK_LINE(895)
		this->duration = this->nativeMedia->get_duration();
		HX_STACK_LINE(896)
		this->fireEvent(HX_CSTRING("durationchange"),false,false);
		HX_STACK_LINE(898)
		this->setReadyState((int)1);
		HX_STACK_LINE(900)
		bool jumped = false;		HX_STACK_VAR(jumped,"jumped");
		HX_STACK_LINE(902)
		if (((this->_defaultPlaybackStartPosition > (int)0))){
			HX_STACK_LINE(904)
			this->seek(this->_defaultPlaybackStartPosition);
			HX_STACK_LINE(905)
			jumped = true;
		}
		HX_STACK_LINE(908)
		this->_defaultPlaybackStartPosition = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,establishMediaTimeline,(void))

bool HTMLMediaElement_obj::isPotentiallyPlaying( ){
	HX_STACK_PUSH("HTMLMediaElement::isPotentiallyPlaying","cocktail/core/html/HTMLMediaElement.hx",867);
	HX_STACK_THIS(this);
	HX_STACK_LINE(868)
	if (((this->paused == true))){
		HX_STACK_LINE(869)
		return false;
	}
	HX_STACK_LINE(873)
	if (((this->ended == true))){
		HX_STACK_LINE(874)
		return false;
	}
	HX_STACK_LINE(878)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,isPotentiallyPlaying,return )

Void HTMLMediaElement_obj::setReadyState( int newReadyState){
{
		HX_STACK_PUSH("HTMLMediaElement::setReadyState","cocktail/core/html/HTMLMediaElement.hx",781);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newReadyState,"newReadyState");
		HX_STACK_LINE(782)
		if (((bool((this->readyState == (int)0)) && bool((newReadyState == (int)1))))){
			HX_STACK_LINE(783)
			this->fireEvent(HX_CSTRING("loadedmetadata"),false,false);
		}
		HX_STACK_LINE(787)
		if (((bool((bool((this->readyState == (int)1)) && bool(((bool((bool((newReadyState == (int)2)) || bool((newReadyState == (int)4)))) || bool((newReadyState == (int)3))))))) || bool((bool((this->readyState == (int)3)) && bool((newReadyState == (int)4))))))){
			HX_STACK_LINE(790)
			if (((bool((this->_loadedDataWasDispatched == false)) && bool((this->readyState == (int)1))))){
				HX_STACK_LINE(792)
				this->fireEvent(HX_CSTRING("loadeddata"),false,false);
				HX_STACK_LINE(793)
				this->_loadedDataWasDispatched = true;
			}
			HX_STACK_LINE(796)
			if (((bool((newReadyState == (int)4)) || bool((newReadyState == (int)3))))){
				HX_STACK_LINE(798)
				if (((bool((this->readyState >= (int)3)) && bool((newReadyState <= (int)2))))){
					HX_STACK_LINE(799)
					if (((this->isPotentiallyPlaying() == true))){
						HX_STACK_LINE(802)
						this->fireEvent(HX_CSTRING("timeupdate"),false,false);
						HX_STACK_LINE(803)
						this->fireEvent(HX_CSTRING("waiting"),false,false);
					}
				}
				HX_STACK_LINE(807)
				if (((bool((this->readyState <= (int)2)) && bool((newReadyState == (int)3))))){
					HX_STACK_LINE(809)
					this->fireEvent(HX_CSTRING("canplay"),false,false);
					HX_STACK_LINE(811)
					if (((this->paused == false))){
						HX_STACK_LINE(813)
						this->doPlay();
						HX_STACK_LINE(814)
						this->fireEvent(HX_CSTRING("playing"),false,false);
					}
				}
				HX_STACK_LINE(818)
				if (((newReadyState == (int)4))){
					HX_STACK_LINE(820)
					if (((this->readyState == (int)2))){
						HX_STACK_LINE(822)
						this->fireEvent(HX_CSTRING("canplay"),false,false);
						HX_STACK_LINE(824)
						if (((this->paused == false))){
							HX_STACK_LINE(826)
							this->doPlay();
							HX_STACK_LINE(827)
							this->fireEvent(HX_CSTRING("playing"),false,false);
						}
					}
					HX_STACK_LINE(831)
					if (((this->_autoplaying == true))){
						HX_STACK_LINE(832)
						if (((this->paused == true))){
							HX_STACK_LINE(834)
							if (((this->get_autoplay() == true))){
								HX_STACK_LINE(837)
								this->paused = false;
								HX_STACK_LINE(838)
								this->fireEvent(HX_CSTRING("play"),false,false);
								HX_STACK_LINE(839)
								this->doPlay();
								HX_STACK_LINE(841)
								this->fireEvent(HX_CSTRING("playing"),false,false);
							}
						}
					}
					HX_STACK_LINE(846)
					this->fireEvent(HX_CSTRING("canplaythrough"),false,false);
				}
			}
		}
		HX_STACK_LINE(851)
		this->readyState = newReadyState;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,setReadyState,(void))

Void HTMLMediaElement_obj::seek( Float newPlaybackPosition){
{
		HX_STACK_PUSH("HTMLMediaElement::seek","cocktail/core/html/HTMLMediaElement.hx",722);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newPlaybackPosition,"newPlaybackPosition");
		HX_STACK_LINE(723)
		if (((this->readyState == (int)0))){
			HX_STACK_LINE(724)
			return null();
		}
		HX_STACK_LINE(728)
		if (((this->seeking == true))){
		}
		HX_STACK_LINE(736)
		this->seeking = true;
		HX_STACK_LINE(738)
		if (((newPlaybackPosition > this->duration))){
			HX_STACK_LINE(739)
			newPlaybackPosition = this->duration;
		}
		HX_STACK_LINE(743)
		if (((newPlaybackPosition < this->_earliestPossiblePosition))){
			HX_STACK_LINE(744)
			newPlaybackPosition = (int)0;
		}
		HX_STACK_LINE(758)
		this->fireEvent(HX_CSTRING("seeking"),false,false);
		HX_STACK_LINE(761)
		this->_currentPlaybackPosition = newPlaybackPosition;
		HX_STACK_LINE(762)
		this->nativeMedia->seek(newPlaybackPosition);
		HX_STACK_LINE(768)
		this->fireEvent(HX_CSTRING("timeupdate"),false,false);
		HX_STACK_LINE(770)
		this->fireEvent(HX_CSTRING("seeked"),false,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,seek,(void))

Void HTMLMediaElement_obj::fetchResource( ::String url){
{
		HX_STACK_PUSH("HTMLMediaElement::fetchResource","cocktail/core/html/HTMLMediaElement.hx",693);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(696)
		if (((bool((this->get_preload() == HX_CSTRING("none"))) && bool((this->_stalledByPreload == false))))){
			HX_STACK_LINE(697)
			if (((this->get_autoplay() == false))){
				HX_STACK_LINE(702)
				this->networkState = (int)1;
				HX_STACK_LINE(703)
				this->fireEvent(HX_CSTRING("suspend"),false,false);
				HX_STACK_LINE(704)
				this->_stalledByPreload = true;
				HX_STACK_LINE(705)
				return null();
			}
		}
		HX_STACK_LINE(708)
		this->nativeMedia->onLoadedMetaData = this->onNativeMediaLoadedMetaData_dyn();
		HX_STACK_LINE(709)
		this->nativeMedia->set_src(url);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,fetchResource,(void))

Void HTMLMediaElement_obj::doSelectResource( Float time){
{
		HX_STACK_PUSH("HTMLMediaElement::doSelectResource","cocktail/core/html/HTMLMediaElement.hx",601);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(602)
		int mode;		HX_STACK_VAR(mode,"mode");
		HX_STACK_LINE(603)
		::cocktail::core::html::HTMLSourceElement candidate;		HX_STACK_VAR(candidate,"candidate");
		HX_STACK_LINE(604)
		if (((this->get_src() != null()))){
			HX_STACK_LINE(605)
			mode = (int)0;
		}
		else{
			HX_STACK_LINE(608)
			if (((this->hasChildSourceElement() == true))){
				HX_STACK_LINE(610)
				mode = (int)1;
				HX_STACK_LINE(613)
				int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(614)
				{
					HX_STACK_LINE(614)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(614)
					while(((_g < length))){
						HX_STACK_LINE(614)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(616)
						if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeName"),true)() == HX_CSTRING("SOURCE")))){
							HX_STACK_LINE(618)
							candidate = this->childNodes->__GetItem(i);
							HX_STACK_LINE(619)
							break;
						}
					}
				}
			}
			else{
				HX_STACK_LINE(625)
				this->networkState = (int)0;
				HX_STACK_LINE(626)
				return null();
			}
		}
		HX_STACK_LINE(629)
		this->networkState = (int)2;
		HX_STACK_LINE(631)
		this->fireEvent(HX_CSTRING("loadstart"),false,false);
		HX_STACK_LINE(633)
		if (((mode == (int)0))){
			HX_STACK_LINE(635)
			if (((this->get_src() == HX_CSTRING("")))){
				HX_STACK_LINE(639)
				this->networkState = (int)3;
				HX_STACK_LINE(641)
				this->fireEvent(HX_CSTRING("error"),false,false);
				HX_STACK_LINE(643)
				return null();
			}
			HX_STACK_LINE(649)
			this->currentSrc = this->get_src();
			HX_STACK_LINE(650)
			this->fetchResource(this->currentSrc);
		}
		else{
			HX_STACK_LINE(652)
			if (((mode == (int)1))){
				HX_STACK_LINE(655)
				{
					HX_STACK_LINE(655)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(655)
					while(((_g1 < _g))){
						HX_STACK_LINE(655)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(657)
						if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeName"),true)() == HX_CSTRING("SOURCE")))){
							HX_STACK_LINE(659)
							::cocktail::core::html::HTMLSourceElement sourceChild = this->childNodes->__GetItem(i);		HX_STACK_VAR(sourceChild,"sourceChild");
							HX_STACK_LINE(660)
							if (((sourceChild->get_type() != null()))){
								HX_STACK_LINE(661)
								if (((this->canPlayType(sourceChild->get_type()) == HX_CSTRING("probably")))){
									HX_STACK_LINE(664)
									this->currentSrc = sourceChild->get_src();
									HX_STACK_LINE(665)
									this->fetchResource(this->currentSrc);
									HX_STACK_LINE(666)
									return null();
								}
							}
							else{
								HX_STACK_LINE(669)
								if (((sourceChild->get_src() != null()))){
									HX_STACK_LINE(670)
									if (((this->canPlayType(sourceChild->get_src()) == HX_CSTRING("probably")))){
										HX_STACK_LINE(673)
										this->currentSrc = sourceChild->get_src();
										HX_STACK_LINE(674)
										this->fetchResource(this->currentSrc);
										HX_STACK_LINE(675)
										return null();
									}
								}
							}
						}
					}
				}
				HX_STACK_LINE(681)
				this->networkState = (int)0;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,doSelectResource,(void))

Void HTMLMediaElement_obj::selectResource( ){
{
		HX_STACK_PUSH("HTMLMediaElement::selectResource","cocktail/core/html/HTMLMediaElement.hx",585);
		HX_STACK_THIS(this);
		HX_STACK_LINE(586)
		this->networkState = (int)3;
		HX_STACK_LINE(594)
		this->_ownerHTMLDocument->timer->delay(this->doSelectResource_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,selectResource,(void))

Void HTMLMediaElement_obj::loadResource( ){
{
		HX_STACK_PUSH("HTMLMediaElement::loadResource","cocktail/core/html/HTMLMediaElement.hx",531);
		HX_STACK_THIS(this);
		HX_STACK_LINE(532)
		switch( (int)(this->networkState)){
			case (int)2: case (int)1: {
				HX_STACK_LINE(534)
				this->fireEvent(HX_CSTRING("abort"),false,false);
			}
			;break;
		}
		HX_STACK_LINE(538)
		if (((this->networkState != (int)0))){
			HX_STACK_LINE(540)
			this->fireEvent(HX_CSTRING("emptied"),false,false);
			HX_STACK_LINE(542)
			this->nativeMedia->set_src(null());
			HX_STACK_LINE(544)
			this->networkState = (int)0;
			HX_STACK_LINE(547)
			this->readyState = (int)0;
			HX_STACK_LINE(549)
			this->paused = true;
			HX_STACK_LINE(551)
			this->seeking = false;
			HX_STACK_LINE(553)
			this->_currentPlaybackPosition = (int)0;
			HX_STACK_LINE(555)
			if (((this->_officialPlaybackPosition > (int)0))){
				HX_STACK_LINE(557)
				this->_officialPlaybackPosition = (int)0;
				HX_STACK_LINE(558)
				this->fireEvent(HX_CSTRING("timeupdate"),false,false);
			}
			else{
				HX_STACK_LINE(561)
				this->_officialPlaybackPosition = (int)0;
			}
			HX_STACK_LINE(565)
			this->_initialPlaybackPosition = (int)0;
			HX_STACK_LINE(567)
			this->duration = ::Math_obj::NaN;
		}
		HX_STACK_LINE(570)
		this->_loadedDataWasDispatched = false;
		HX_STACK_LINE(572)
		this->selectResource();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,loadResource,(void))

Void HTMLMediaElement_obj::doPlay( ){
{
		HX_STACK_PUSH("HTMLMediaElement::doPlay","cocktail/core/html/HTMLMediaElement.hx",518);
		HX_STACK_THIS(this);
		HX_STACK_LINE(519)
		this->nativeMedia->play();
		HX_STACK_LINE(520)
		this->onTimeUpdateTick((int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,doPlay,(void))

::String HTMLMediaElement_obj::canPlayType( ::String type){
	HX_STACK_PUSH("HTMLMediaElement::canPlayType","cocktail/core/html/HTMLMediaElement.hx",506);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(506)
	return this->nativeMedia->canPlayType(type);
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMediaElement_obj,canPlayType,return )

Void HTMLMediaElement_obj::pause( ){
{
		HX_STACK_PUSH("HTMLMediaElement::pause","cocktail/core/html/HTMLMediaElement.hx",478);
		HX_STACK_THIS(this);
		HX_STACK_LINE(479)
		if (((this->networkState == (int)0))){
			HX_STACK_LINE(480)
			this->selectResource();
		}
		HX_STACK_LINE(484)
		this->_autoplaying = false;
		HX_STACK_LINE(486)
		if (((this->paused == false))){
			HX_STACK_LINE(488)
			this->paused = true;
			HX_STACK_LINE(490)
			this->fireEvent(HX_CSTRING("timeupdate"),false,false);
			HX_STACK_LINE(492)
			this->fireEvent(HX_CSTRING("pause"),false,false);
			HX_STACK_LINE(494)
			this->_officialPlaybackPosition = this->_currentPlaybackPosition;
		}
		HX_STACK_LINE(497)
		this->nativeMedia->pause();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,pause,(void))

Void HTMLMediaElement_obj::play( ){
{
		HX_STACK_PUSH("HTMLMediaElement::play","cocktail/core/html/HTMLMediaElement.hx",428);
		HX_STACK_THIS(this);
		HX_STACK_LINE(429)
		if (((this->networkState == (int)0))){
			HX_STACK_LINE(430)
			this->selectResource();
		}
		HX_STACK_LINE(434)
		if (((this->ended == true))){
			HX_STACK_LINE(436)
			this->ended = false;
			HX_STACK_LINE(437)
			this->seek((int)0);
		}
		HX_STACK_LINE(440)
		if (((this->paused == true))){
			HX_STACK_LINE(442)
			this->paused = false;
			HX_STACK_LINE(444)
			this->fireEvent(HX_CSTRING("play"),false,false);
			HX_STACK_LINE(446)
			switch( (int)(this->readyState)){
				case (int)0: case (int)1: case (int)2: {
					HX_STACK_LINE(448)
					this->fireEvent(HX_CSTRING("waiting"),false,false);
				}
				;break;
				case (int)3: case (int)4: {
					HX_STACK_LINE(452)
					this->doPlay();
					HX_STACK_LINE(453)
					this->fireEvent(HX_CSTRING("playing"),false,false);
				}
				;break;
			}
		}
		HX_STACK_LINE(457)
		this->_autoplaying = false;
		HX_STACK_LINE(463)
		if (((this->_stalledByPreload == true))){
			HX_STACK_LINE(464)
			this->selectResource();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,play,(void))

::String HTMLMediaElement_obj::getAttribute( ::String name){
	HX_STACK_PUSH("HTMLMediaElement::getAttribute","cocktail/core/html/HTMLMediaElement.hx",402);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(402)
	if (((name == HX_CSTRING("preload")))){
		HX_STACK_LINE(404)
		return this->get_preload();
	}
	else{
		HX_STACK_LINE(408)
		return this->super::getAttribute(name);
	}
	HX_STACK_LINE(402)
	return null();
}


Void HTMLMediaElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLMediaElement::setAttribute","cocktail/core/html/HTMLMediaElement.hx",382);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(382)
		if (((name == HX_CSTRING("src")))){
			HX_STACK_LINE(384)
			this->set_src(value);
		}
		else{
			HX_STACK_LINE(387)
			if (((name == HX_CSTRING("preload")))){
				HX_STACK_LINE(388)
				this->set_preload(value);
			}
			else{
				HX_STACK_LINE(392)
				this->super::setAttribute(name,value);
			}
		}
	}
return null();
}


Dynamic HTMLMediaElement_obj::appendChild( Dynamic _tmp_newChild){
	HX_STACK_PUSH("HTMLMediaElement::appendChild","cocktail/core/html/HTMLMediaElement.hx",355);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
	HX_STACK_LINE(356)
	::cocktail::core::html::HTMLElement newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
	HX_STACK_LINE(356)
	this->super::appendChild(newChild);
	HX_STACK_LINE(360)
	if (((bool((this->get_src() == null())) && bool((this->networkState == (int)0))))){
		HX_STACK_LINE(361)
		if (((newChild->get_nodeName() == HX_CSTRING("SOURCE")))){
			HX_STACK_LINE(365)
			this->selectResource();
		}
	}
	HX_STACK_LINE(370)
	return newChild;
}


Void HTMLMediaElement_obj::initNativeMedia( ){
{
		HX_STACK_PUSH("HTMLMediaElement::initNativeMedia","cocktail/core/html/HTMLMediaElement.hx",342);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMediaElement_obj,initNativeMedia,(void))

Void HTMLMediaElement_obj::init( ){
{
		HX_STACK_PUSH("HTMLMediaElement::init","cocktail/core/html/HTMLMediaElement.hx",332);
		HX_STACK_THIS(this);
		HX_STACK_LINE(333)
		this->initNativeMedia();
		HX_STACK_LINE(334)
		this->super::init();
	}
return null();
}


int HTMLMediaElement_obj::RESOURCE_SELECTION_ATTRIBUTE_MODE;

int HTMLMediaElement_obj::RESOURCE_SELECTION_CHILDREN_MODE;

int HTMLMediaElement_obj::TIME_UPDATE_FREQUENCY;

int HTMLMediaElement_obj::PROGRESS_FREQUENCY;

Float HTMLMediaElement_obj::PLAYBACK_END_DELTA;

int HTMLMediaElement_obj::NETWORK_EMPTY;

int HTMLMediaElement_obj::NETWORK_IDLE;

int HTMLMediaElement_obj::NETWORK_LOADING;

int HTMLMediaElement_obj::NETWORK_NO_SOURCE;

::String HTMLMediaElement_obj::CAN_PLAY_TYPE_MAYBE;

::String HTMLMediaElement_obj::CAN_PLAY_TYPE_PROBABLY;

int HTMLMediaElement_obj::HAVE_NOTHING;

int HTMLMediaElement_obj::HAVE_METADATA;

int HTMLMediaElement_obj::HAVE_CURRENT_DATA;

int HTMLMediaElement_obj::HAVE_FUTURE_DATA;

int HTMLMediaElement_obj::HAVE_ENOUGH_DATA;


HTMLMediaElement_obj::HTMLMediaElement_obj()
{
}

void HTMLMediaElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLMediaElement);
	HX_MARK_MEMBER_NAME(_autoplaying,"_autoplaying");
	HX_MARK_MEMBER_NAME(_loadedDataWasDispatched,"_loadedDataWasDispatched");
	HX_MARK_MEMBER_NAME(_earliestPossiblePosition,"_earliestPossiblePosition");
	HX_MARK_MEMBER_NAME(_defaultPlaybackStartPosition,"_defaultPlaybackStartPosition");
	HX_MARK_MEMBER_NAME(_currentPlaybackPosition,"_currentPlaybackPosition");
	HX_MARK_MEMBER_NAME(_officialPlaybackPosition,"_officialPlaybackPosition");
	HX_MARK_MEMBER_NAME(_initialPlaybackPosition,"_initialPlaybackPosition");
	HX_MARK_MEMBER_NAME(_stalledByPreload,"_stalledByPreload");
	HX_MARK_MEMBER_NAME(nativeMedia,"nativeMedia");
	HX_MARK_MEMBER_NAME(volume,"volume");
	HX_MARK_MEMBER_NAME(muted,"muted");
	HX_MARK_MEMBER_NAME(ended,"ended");
	HX_MARK_MEMBER_NAME(paused,"paused");
	HX_MARK_MEMBER_NAME(buffered,"buffered");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(currentSrc,"currentSrc");
	HX_MARK_MEMBER_NAME(currentTime,"currentTime");
	HX_MARK_MEMBER_NAME(seeking,"seeking");
	HX_MARK_MEMBER_NAME(readyState,"readyState");
	HX_MARK_MEMBER_NAME(networkState,"networkState");
	HX_MARK_MEMBER_NAME(preload,"preload");
	HX_MARK_MEMBER_NAME(loop,"loop");
	HX_MARK_MEMBER_NAME(autoplay,"autoplay");
	HX_MARK_MEMBER_NAME(src,"src");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLMediaElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_autoplaying,"_autoplaying");
	HX_VISIT_MEMBER_NAME(_loadedDataWasDispatched,"_loadedDataWasDispatched");
	HX_VISIT_MEMBER_NAME(_earliestPossiblePosition,"_earliestPossiblePosition");
	HX_VISIT_MEMBER_NAME(_defaultPlaybackStartPosition,"_defaultPlaybackStartPosition");
	HX_VISIT_MEMBER_NAME(_currentPlaybackPosition,"_currentPlaybackPosition");
	HX_VISIT_MEMBER_NAME(_officialPlaybackPosition,"_officialPlaybackPosition");
	HX_VISIT_MEMBER_NAME(_initialPlaybackPosition,"_initialPlaybackPosition");
	HX_VISIT_MEMBER_NAME(_stalledByPreload,"_stalledByPreload");
	HX_VISIT_MEMBER_NAME(nativeMedia,"nativeMedia");
	HX_VISIT_MEMBER_NAME(volume,"volume");
	HX_VISIT_MEMBER_NAME(muted,"muted");
	HX_VISIT_MEMBER_NAME(ended,"ended");
	HX_VISIT_MEMBER_NAME(paused,"paused");
	HX_VISIT_MEMBER_NAME(buffered,"buffered");
	HX_VISIT_MEMBER_NAME(duration,"duration");
	HX_VISIT_MEMBER_NAME(currentSrc,"currentSrc");
	HX_VISIT_MEMBER_NAME(currentTime,"currentTime");
	HX_VISIT_MEMBER_NAME(seeking,"seeking");
	HX_VISIT_MEMBER_NAME(readyState,"readyState");
	HX_VISIT_MEMBER_NAME(networkState,"networkState");
	HX_VISIT_MEMBER_NAME(preload,"preload");
	HX_VISIT_MEMBER_NAME(loop,"loop");
	HX_VISIT_MEMBER_NAME(autoplay,"autoplay");
	HX_VISIT_MEMBER_NAME(src,"src");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLMediaElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return inCallProp ? get_src() : src; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"loop") ) { return inCallProp ? get_loop() : loop; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"muted") ) { return muted; }
		if (HX_FIELD_EQ(inName,"ended") ) { return ended; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doPlay") ) { return doPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"volume") ) { return volume; }
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		if (HX_FIELD_EQ(inName,"get_src") ) { return get_src_dyn(); }
		if (HX_FIELD_EQ(inName,"seeking") ) { return seeking; }
		if (HX_FIELD_EQ(inName,"preload") ) { return inCallProp ? get_preload() : preload; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_loop") ) { return set_loop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_loop") ) { return get_loop_dyn(); }
		if (HX_FIELD_EQ(inName,"buffered") ) { return inCallProp ? get_buffered() : buffered; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"autoplay") ) { return inCallProp ? get_autoplay() : autoplay; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_muted") ) { return set_muted_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_volume") ) { return set_volume_dyn(); }
		if (HX_FIELD_EQ(inName,"currentSrc") ) { return currentSrc; }
		if (HX_FIELD_EQ(inName,"readyState") ) { return readyState; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_preload") ) { return set_preload_dyn(); }
		if (HX_FIELD_EQ(inName,"get_preload") ) { return get_preload_dyn(); }
		if (HX_FIELD_EQ(inName,"canPlayType") ) { return canPlayType_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nativeMedia") ) { return nativeMedia; }
		if (HX_FIELD_EQ(inName,"currentTime") ) { return inCallProp ? get_currentTime() : currentTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"NETWORK_IDLE") ) { return NETWORK_IDLE; }
		if (HX_FIELD_EQ(inName,"HAVE_NOTHING") ) { return HAVE_NOTHING; }
		if (HX_FIELD_EQ(inName,"get_buffered") ) { return get_buffered_dyn(); }
		if (HX_FIELD_EQ(inName,"set_autoplay") ) { return set_autoplay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_autoplay") ) { return get_autoplay_dyn(); }
		if (HX_FIELD_EQ(inName,"loadResource") ) { return loadResource_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttribute") ) { return getAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"_autoplaying") ) { return _autoplaying; }
		if (HX_FIELD_EQ(inName,"networkState") ) { return networkState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"NETWORK_EMPTY") ) { return NETWORK_EMPTY; }
		if (HX_FIELD_EQ(inName,"HAVE_METADATA") ) { return HAVE_METADATA; }
		if (HX_FIELD_EQ(inName,"setReadyState") ) { return setReadyState_dyn(); }
		if (HX_FIELD_EQ(inName,"fetchResource") ) { return fetchResource_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onProgressTick") ) { return onProgressTick_dyn(); }
		if (HX_FIELD_EQ(inName,"onLoadingError") ) { return onLoadingError_dyn(); }
		if (HX_FIELD_EQ(inName,"selectResource") ) { return selectResource_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"NETWORK_LOADING") ) { return NETWORK_LOADING; }
		if (HX_FIELD_EQ(inName,"set_currentTime") ) { return set_currentTime_dyn(); }
		if (HX_FIELD_EQ(inName,"get_currentTime") ) { return get_currentTime_dyn(); }
		if (HX_FIELD_EQ(inName,"initNativeMedia") ) { return initNativeMedia_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"HAVE_FUTURE_DATA") ) { return HAVE_FUTURE_DATA; }
		if (HX_FIELD_EQ(inName,"HAVE_ENOUGH_DATA") ) { return HAVE_ENOUGH_DATA; }
		if (HX_FIELD_EQ(inName,"onTimeUpdateTick") ) { return onTimeUpdateTick_dyn(); }
		if (HX_FIELD_EQ(inName,"doSelectResource") ) { return doSelectResource_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"NETWORK_NO_SOURCE") ) { return NETWORK_NO_SOURCE; }
		if (HX_FIELD_EQ(inName,"HAVE_CURRENT_DATA") ) { return HAVE_CURRENT_DATA; }
		if (HX_FIELD_EQ(inName,"_stalledByPreload") ) { return _stalledByPreload; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PROGRESS_FREQUENCY") ) { return PROGRESS_FREQUENCY; }
		if (HX_FIELD_EQ(inName,"PLAYBACK_END_DELTA") ) { return PLAYBACK_END_DELTA; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_TYPE_MAYBE") ) { return CAN_PLAY_TYPE_MAYBE; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isPotentiallyPlaying") ) { return isPotentiallyPlaying_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"TIME_UPDATE_FREQUENCY") ) { return TIME_UPDATE_FREQUENCY; }
		if (HX_FIELD_EQ(inName,"hasChildSourceElement") ) { return hasChildSourceElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_TYPE_PROBABLY") ) { return CAN_PLAY_TYPE_PROBABLY; }
		if (HX_FIELD_EQ(inName,"establishMediaTimeline") ) { return establishMediaTimeline_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_loadedDataWasDispatched") ) { return _loadedDataWasDispatched; }
		if (HX_FIELD_EQ(inName,"_currentPlaybackPosition") ) { return _currentPlaybackPosition; }
		if (HX_FIELD_EQ(inName,"_initialPlaybackPosition") ) { return _initialPlaybackPosition; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_earliestPossiblePosition") ) { return _earliestPossiblePosition; }
		if (HX_FIELD_EQ(inName,"_officialPlaybackPosition") ) { return _officialPlaybackPosition; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"onNativeMediaLoadedMetaData") ) { return onNativeMediaLoadedMetaData_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_defaultPlaybackStartPosition") ) { return _defaultPlaybackStartPosition; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"RESOURCE_SELECTION_CHILDREN_MODE") ) { return RESOURCE_SELECTION_CHILDREN_MODE; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"RESOURCE_SELECTION_ATTRIBUTE_MODE") ) { return RESOURCE_SELECTION_ATTRIBUTE_MODE; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLMediaElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { if (inCallProp) return set_src(inValue);src=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { if (inCallProp) return set_loop(inValue);loop=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"muted") ) { if (inCallProp) return set_muted(inValue);muted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ended") ) { ended=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"volume") ) { if (inCallProp) return set_volume(inValue);volume=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"seeking") ) { seeking=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"preload") ) { if (inCallProp) return set_preload(inValue);preload=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"buffered") ) { buffered=inValue.Cast< ::cocktail::core::html::TimeRanges >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"autoplay") ) { if (inCallProp) return set_autoplay(inValue);autoplay=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"currentSrc") ) { currentSrc=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"readyState") ) { readyState=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nativeMedia") ) { nativeMedia=inValue.Cast< ::cocktail::port::base::NativeMedia >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentTime") ) { if (inCallProp) return set_currentTime(inValue);currentTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"NETWORK_IDLE") ) { NETWORK_IDLE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HAVE_NOTHING") ) { HAVE_NOTHING=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_autoplaying") ) { _autoplaying=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"networkState") ) { networkState=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"NETWORK_EMPTY") ) { NETWORK_EMPTY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HAVE_METADATA") ) { HAVE_METADATA=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"NETWORK_LOADING") ) { NETWORK_LOADING=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"HAVE_FUTURE_DATA") ) { HAVE_FUTURE_DATA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HAVE_ENOUGH_DATA") ) { HAVE_ENOUGH_DATA=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"NETWORK_NO_SOURCE") ) { NETWORK_NO_SOURCE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HAVE_CURRENT_DATA") ) { HAVE_CURRENT_DATA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stalledByPreload") ) { _stalledByPreload=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PROGRESS_FREQUENCY") ) { PROGRESS_FREQUENCY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PLAYBACK_END_DELTA") ) { PLAYBACK_END_DELTA=inValue.Cast< Float >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_TYPE_MAYBE") ) { CAN_PLAY_TYPE_MAYBE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"TIME_UPDATE_FREQUENCY") ) { TIME_UPDATE_FREQUENCY=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_TYPE_PROBABLY") ) { CAN_PLAY_TYPE_PROBABLY=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_loadedDataWasDispatched") ) { _loadedDataWasDispatched=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_currentPlaybackPosition") ) { _currentPlaybackPosition=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_initialPlaybackPosition") ) { _initialPlaybackPosition=inValue.Cast< Float >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_earliestPossiblePosition") ) { _earliestPossiblePosition=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_officialPlaybackPosition") ) { _officialPlaybackPosition=inValue.Cast< Float >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_defaultPlaybackStartPosition") ) { _defaultPlaybackStartPosition=inValue.Cast< Float >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"RESOURCE_SELECTION_CHILDREN_MODE") ) { RESOURCE_SELECTION_CHILDREN_MODE=inValue.Cast< int >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"RESOURCE_SELECTION_ATTRIBUTE_MODE") ) { RESOURCE_SELECTION_ATTRIBUTE_MODE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLMediaElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_autoplaying"));
	outFields->push(HX_CSTRING("_loadedDataWasDispatched"));
	outFields->push(HX_CSTRING("_earliestPossiblePosition"));
	outFields->push(HX_CSTRING("_defaultPlaybackStartPosition"));
	outFields->push(HX_CSTRING("_currentPlaybackPosition"));
	outFields->push(HX_CSTRING("_officialPlaybackPosition"));
	outFields->push(HX_CSTRING("_initialPlaybackPosition"));
	outFields->push(HX_CSTRING("_stalledByPreload"));
	outFields->push(HX_CSTRING("nativeMedia"));
	outFields->push(HX_CSTRING("volume"));
	outFields->push(HX_CSTRING("muted"));
	outFields->push(HX_CSTRING("ended"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("buffered"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("currentSrc"));
	outFields->push(HX_CSTRING("currentTime"));
	outFields->push(HX_CSTRING("seeking"));
	outFields->push(HX_CSTRING("readyState"));
	outFields->push(HX_CSTRING("networkState"));
	outFields->push(HX_CSTRING("preload"));
	outFields->push(HX_CSTRING("loop"));
	outFields->push(HX_CSTRING("autoplay"));
	outFields->push(HX_CSTRING("src"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("RESOURCE_SELECTION_ATTRIBUTE_MODE"),
	HX_CSTRING("RESOURCE_SELECTION_CHILDREN_MODE"),
	HX_CSTRING("TIME_UPDATE_FREQUENCY"),
	HX_CSTRING("PROGRESS_FREQUENCY"),
	HX_CSTRING("PLAYBACK_END_DELTA"),
	HX_CSTRING("NETWORK_EMPTY"),
	HX_CSTRING("NETWORK_IDLE"),
	HX_CSTRING("NETWORK_LOADING"),
	HX_CSTRING("NETWORK_NO_SOURCE"),
	HX_CSTRING("CAN_PLAY_TYPE_MAYBE"),
	HX_CSTRING("CAN_PLAY_TYPE_PROBABLY"),
	HX_CSTRING("HAVE_NOTHING"),
	HX_CSTRING("HAVE_METADATA"),
	HX_CSTRING("HAVE_CURRENT_DATA"),
	HX_CSTRING("HAVE_FUTURE_DATA"),
	HX_CSTRING("HAVE_ENOUGH_DATA"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_currentTime"),
	HX_CSTRING("get_currentTime"),
	HX_CSTRING("get_buffered"),
	HX_CSTRING("set_volume"),
	HX_CSTRING("set_muted"),
	HX_CSTRING("set_preload"),
	HX_CSTRING("get_preload"),
	HX_CSTRING("set_loop"),
	HX_CSTRING("get_loop"),
	HX_CSTRING("set_autoplay"),
	HX_CSTRING("get_autoplay"),
	HX_CSTRING("set_src"),
	HX_CSTRING("get_src"),
	HX_CSTRING("onProgressTick"),
	HX_CSTRING("onTimeUpdateTick"),
	HX_CSTRING("onNativeMediaLoadedMetaData"),
	HX_CSTRING("onLoadingError"),
	HX_CSTRING("hasChildSourceElement"),
	HX_CSTRING("establishMediaTimeline"),
	HX_CSTRING("isPotentiallyPlaying"),
	HX_CSTRING("setReadyState"),
	HX_CSTRING("seek"),
	HX_CSTRING("fetchResource"),
	HX_CSTRING("doSelectResource"),
	HX_CSTRING("selectResource"),
	HX_CSTRING("loadResource"),
	HX_CSTRING("doPlay"),
	HX_CSTRING("canPlayType"),
	HX_CSTRING("pause"),
	HX_CSTRING("play"),
	HX_CSTRING("getAttribute"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("initNativeMedia"),
	HX_CSTRING("init"),
	HX_CSTRING("_autoplaying"),
	HX_CSTRING("_loadedDataWasDispatched"),
	HX_CSTRING("_earliestPossiblePosition"),
	HX_CSTRING("_defaultPlaybackStartPosition"),
	HX_CSTRING("_currentPlaybackPosition"),
	HX_CSTRING("_officialPlaybackPosition"),
	HX_CSTRING("_initialPlaybackPosition"),
	HX_CSTRING("_stalledByPreload"),
	HX_CSTRING("nativeMedia"),
	HX_CSTRING("volume"),
	HX_CSTRING("muted"),
	HX_CSTRING("ended"),
	HX_CSTRING("paused"),
	HX_CSTRING("buffered"),
	HX_CSTRING("duration"),
	HX_CSTRING("currentSrc"),
	HX_CSTRING("currentTime"),
	HX_CSTRING("seeking"),
	HX_CSTRING("readyState"),
	HX_CSTRING("networkState"),
	HX_CSTRING("preload"),
	HX_CSTRING("loop"),
	HX_CSTRING("autoplay"),
	HX_CSTRING("src"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::RESOURCE_SELECTION_ATTRIBUTE_MODE,"RESOURCE_SELECTION_ATTRIBUTE_MODE");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::RESOURCE_SELECTION_CHILDREN_MODE,"RESOURCE_SELECTION_CHILDREN_MODE");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::TIME_UPDATE_FREQUENCY,"TIME_UPDATE_FREQUENCY");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::PROGRESS_FREQUENCY,"PROGRESS_FREQUENCY");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::PLAYBACK_END_DELTA,"PLAYBACK_END_DELTA");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_EMPTY,"NETWORK_EMPTY");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_IDLE,"NETWORK_IDLE");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_LOADING,"NETWORK_LOADING");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_NO_SOURCE,"NETWORK_NO_SOURCE");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::CAN_PLAY_TYPE_MAYBE,"CAN_PLAY_TYPE_MAYBE");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::CAN_PLAY_TYPE_PROBABLY,"CAN_PLAY_TYPE_PROBABLY");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::HAVE_NOTHING,"HAVE_NOTHING");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::HAVE_METADATA,"HAVE_METADATA");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::HAVE_CURRENT_DATA,"HAVE_CURRENT_DATA");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::HAVE_FUTURE_DATA,"HAVE_FUTURE_DATA");
	HX_MARK_MEMBER_NAME(HTMLMediaElement_obj::HAVE_ENOUGH_DATA,"HAVE_ENOUGH_DATA");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::RESOURCE_SELECTION_ATTRIBUTE_MODE,"RESOURCE_SELECTION_ATTRIBUTE_MODE");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::RESOURCE_SELECTION_CHILDREN_MODE,"RESOURCE_SELECTION_CHILDREN_MODE");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::TIME_UPDATE_FREQUENCY,"TIME_UPDATE_FREQUENCY");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::PROGRESS_FREQUENCY,"PROGRESS_FREQUENCY");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::PLAYBACK_END_DELTA,"PLAYBACK_END_DELTA");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_EMPTY,"NETWORK_EMPTY");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_IDLE,"NETWORK_IDLE");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_LOADING,"NETWORK_LOADING");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::NETWORK_NO_SOURCE,"NETWORK_NO_SOURCE");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::CAN_PLAY_TYPE_MAYBE,"CAN_PLAY_TYPE_MAYBE");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::CAN_PLAY_TYPE_PROBABLY,"CAN_PLAY_TYPE_PROBABLY");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::HAVE_NOTHING,"HAVE_NOTHING");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::HAVE_METADATA,"HAVE_METADATA");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::HAVE_CURRENT_DATA,"HAVE_CURRENT_DATA");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::HAVE_FUTURE_DATA,"HAVE_FUTURE_DATA");
	HX_VISIT_MEMBER_NAME(HTMLMediaElement_obj::HAVE_ENOUGH_DATA,"HAVE_ENOUGH_DATA");
};

Class HTMLMediaElement_obj::__mClass;

void HTMLMediaElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLMediaElement"), hx::TCanCast< HTMLMediaElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLMediaElement_obj::__boot()
{
	RESOURCE_SELECTION_ATTRIBUTE_MODE= (int)0;
	RESOURCE_SELECTION_CHILDREN_MODE= (int)1;
	TIME_UPDATE_FREQUENCY= (int)250;
	PROGRESS_FREQUENCY= (int)350;
	PLAYBACK_END_DELTA= 0.2;
	NETWORK_EMPTY= (int)0;
	NETWORK_IDLE= (int)1;
	NETWORK_LOADING= (int)2;
	NETWORK_NO_SOURCE= (int)3;
	CAN_PLAY_TYPE_MAYBE= HX_CSTRING("maybe");
	CAN_PLAY_TYPE_PROBABLY= HX_CSTRING("probably");
	HAVE_NOTHING= (int)0;
	HAVE_METADATA= (int)1;
	HAVE_CURRENT_DATA= (int)2;
	HAVE_FUTURE_DATA= (int)3;
	HAVE_ENOUGH_DATA= (int)4;
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
