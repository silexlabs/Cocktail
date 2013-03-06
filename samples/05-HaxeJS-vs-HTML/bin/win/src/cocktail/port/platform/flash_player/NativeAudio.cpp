#include <hxcpp.h>

#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeAudio
#include <cocktail/port/platform/flash_player/NativeAudio.h>
#endif
#ifndef INCLUDED_native_events_ErrorEvent
#include <native/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IOErrorEvent
#include <native/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_native_events_TextEvent
#include <native/events/TextEvent.h>
#endif
#ifndef INCLUDED_native_media_Sound
#include <native/media/Sound.h>
#endif
#ifndef INCLUDED_native_media_SoundChannel
#include <native/media/SoundChannel.h>
#endif
#ifndef INCLUDED_native_media_SoundLoaderContext
#include <native/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_native_media_SoundTransform
#include <native/media/SoundTransform.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void NativeAudio_obj::__construct()
{
HX_STACK_PUSH("NativeAudio::new","cocktail/port/platform/flash_player/NativeAudio.hx",63);
{
	HX_STACK_LINE(64)
	super::__construct();
	HX_STACK_LINE(65)
	this->_currentTime = 0.0;
	HX_STACK_LINE(66)
	this->_isPlaying = false;
}
;
	return null();
}

NativeAudio_obj::~NativeAudio_obj() { }

Dynamic NativeAudio_obj::__CreateEmpty() { return  new NativeAudio_obj; }
hx::ObjectPtr< NativeAudio_obj > NativeAudio_obj::__new()
{  hx::ObjectPtr< NativeAudio_obj > result = new NativeAudio_obj();
	result->__construct();
	return result;}

Dynamic NativeAudio_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeAudio_obj > result = new NativeAudio_obj();
	result->__construct();
	return result;}

::String NativeAudio_obj::set_src( ::String value){
	HX_STACK_PUSH("NativeAudio::set_src","cocktail/port/platform/flash_player/NativeAudio.hx",256);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(258)
	this->_currentTime = 0.0;
	HX_STACK_LINE(259)
	this->initSound(value);
	HX_STACK_LINE(260)
	return value;
}


Float NativeAudio_obj::get_currentTime( ){
	HX_STACK_PUSH("NativeAudio::get_currentTime","cocktail/port/platform/flash_player/NativeAudio.hx",248);
	HX_STACK_THIS(this);
	HX_STACK_LINE(248)
	return (Float(this->_soundChannel->get_position()) / Float((int)1000));
}


Float NativeAudio_obj::get_duration( ){
	HX_STACK_PUSH("NativeAudio::get_duration","cocktail/port/platform/flash_player/NativeAudio.hx",239);
	HX_STACK_THIS(this);
	HX_STACK_LINE(239)
	return (Float(this->_sound->get_length()) / Float((int)1000));
}


Float NativeAudio_obj::get_bytesLoaded( ){
	HX_STACK_PUSH("NativeAudio::get_bytesLoaded","cocktail/port/platform/flash_player/NativeAudio.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_LINE(230)
	return this->_sound->bytesLoaded;
}


Float NativeAudio_obj::get_bytesTotal( ){
	HX_STACK_PUSH("NativeAudio::get_bytesTotal","cocktail/port/platform/flash_player/NativeAudio.hx",225);
	HX_STACK_THIS(this);
	HX_STACK_LINE(225)
	return this->_sound->bytesTotal;
}


Float NativeAudio_obj::set_volume( Float value){
	HX_STACK_PUSH("NativeAudio::set_volume","cocktail/port/platform/flash_player/NativeAudio.hx",208);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(209)
	this->volume = value;
	HX_STACK_LINE(216)
	if (((this->_soundChannel != null()))){
		HX_STACK_LINE(217)
		this->_soundChannel->set_soundTransform(::native::media::SoundTransform_obj::__new(value,(int)0));
	}
	HX_STACK_LINE(221)
	return value;
}


Void NativeAudio_obj::onIOError( ::native::events::IOErrorEvent e){
{
		HX_STACK_PUSH("NativeAudio::onIOError","cocktail/port/platform/flash_player/NativeAudio.hx",199);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeAudio_obj,onIOError,(void))

Void NativeAudio_obj::initSound( ::String src){
{
		HX_STACK_PUSH("NativeAudio::initSound","cocktail/port/platform/flash_player/NativeAudio.hx",178);
		HX_STACK_THIS(this);
		HX_STACK_ARG(src,"src");
		HX_STACK_LINE(181)
		this->_sound = ::native::media::Sound_obj::__new(null(),null(),null());
		HX_STACK_LINE(184)
		this->_sound->addEventListener(::native::events::Event_obj::ID3,this->onID3DataReceived_dyn(),null(),null(),null());
		HX_STACK_LINE(187)
		this->_sound->addEventListener(::native::events::Event_obj::COMPLETE,this->onID3DataReceived_dyn(),null(),null(),null());
		HX_STACK_LINE(189)
		this->_sound->addEventListener(::native::events::IOErrorEvent_obj::IO_ERROR,this->onIOError_dyn(),null(),null(),null());
		HX_STACK_LINE(191)
		this->_sound->load(::native::net::URLRequest_obj::__new(src),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeAudio_obj,initSound,(void))

Void NativeAudio_obj::onID3DataReceived( ::native::events::Event event){
{
		HX_STACK_PUSH("NativeAudio::onID3DataReceived","cocktail/port/platform/flash_player/NativeAudio.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(167)
		this->onNativeLoadedMetaData();
		HX_STACK_LINE(168)
		this->_sound->removeEventListener(::native::events::Event_obj::ID3,this->onID3DataReceived_dyn(),null());
		HX_STACK_LINE(169)
		this->_sound->removeEventListener(::native::events::Event_obj::COMPLETE,this->onID3DataReceived_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeAudio_obj,onID3DataReceived,(void))

::String NativeAudio_obj::canPlayType( ::String type){
	HX_STACK_PUSH("NativeAudio::canPlayType","cocktail/port/platform/flash_player/NativeAudio.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(148)
	if (((type.indexOf(HX_CSTRING("mp3"),null()) != (int)-1))){
		HX_STACK_LINE(149)
		return HX_CSTRING("probably");
	}
	HX_STACK_LINE(154)
	return HX_CSTRING("maybe");
}


Void NativeAudio_obj::seek( Float time){
{
		HX_STACK_PUSH("NativeAudio::seek","cocktail/port/platform/flash_player/NativeAudio.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(117)
		if (((this->_soundChannel != null()))){
			HX_STACK_LINE(118)
			this->_soundChannel->stop();
		}
		HX_STACK_LINE(125)
		if (((this->_isPlaying == true))){
			HX_STACK_LINE(126)
			this->_soundChannel = this->_sound->play((time * (int)1000),(int)0,::native::media::SoundTransform_obj::__new(this->volume,(int)0));
		}
		else{
			HX_STACK_LINE(137)
			this->_currentTime = time;
		}
	}
return null();
}


Void NativeAudio_obj::pause( ){
{
		HX_STACK_PUSH("NativeAudio::pause","cocktail/port/platform/flash_player/NativeAudio.hx",91);
		HX_STACK_THIS(this);
		HX_STACK_LINE(92)
		this->_isPlaying = false;
		HX_STACK_LINE(96)
		if (((this->_soundChannel != null()))){
			HX_STACK_LINE(100)
			this->_currentTime = this->_soundChannel->get_position();
			HX_STACK_LINE(101)
			this->_soundChannel->stop();
		}
	}
return null();
}


Void NativeAudio_obj::play( ){
{
		HX_STACK_PUSH("NativeAudio::play","cocktail/port/platform/flash_player/NativeAudio.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_LINE(78)
		this->_isPlaying = true;
		HX_STACK_LINE(83)
		this->seek((Float(this->_currentTime) / Float((int)1000)));
	}
return null();
}


::String NativeAudio_obj::MP3_EXTENSION;


NativeAudio_obj::NativeAudio_obj()
{
}

void NativeAudio_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeAudio);
	HX_MARK_MEMBER_NAME(_isPlaying,"_isPlaying");
	HX_MARK_MEMBER_NAME(_currentTime,"_currentTime");
	HX_MARK_MEMBER_NAME(_soundChannel,"_soundChannel");
	HX_MARK_MEMBER_NAME(_sound,"_sound");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeAudio_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isPlaying,"_isPlaying");
	HX_VISIT_MEMBER_NAME(_currentTime,"_currentTime");
	HX_VISIT_MEMBER_NAME(_soundChannel,"_soundChannel");
	HX_VISIT_MEMBER_NAME(_sound,"_sound");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeAudio_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sound") ) { return _sound; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onIOError") ) { return onIOError_dyn(); }
		if (HX_FIELD_EQ(inName,"initSound") ) { return initSound_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_volume") ) { return set_volume_dyn(); }
		if (HX_FIELD_EQ(inName,"_isPlaying") ) { return _isPlaying; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"canPlayType") ) { return canPlayType_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_duration") ) { return get_duration_dyn(); }
		if (HX_FIELD_EQ(inName,"_currentTime") ) { return _currentTime; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"MP3_EXTENSION") ) { return MP3_EXTENSION; }
		if (HX_FIELD_EQ(inName,"_soundChannel") ) { return _soundChannel; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_bytesTotal") ) { return get_bytesTotal_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_currentTime") ) { return get_currentTime_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bytesLoaded") ) { return get_bytesLoaded_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onID3DataReceived") ) { return onID3DataReceived_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeAudio_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_sound") ) { _sound=inValue.Cast< ::native::media::Sound >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_isPlaying") ) { _isPlaying=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentTime") ) { _currentTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"MP3_EXTENSION") ) { MP3_EXTENSION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_soundChannel") ) { _soundChannel=inValue.Cast< ::native::media::SoundChannel >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeAudio_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isPlaying"));
	outFields->push(HX_CSTRING("_currentTime"));
	outFields->push(HX_CSTRING("_soundChannel"));
	outFields->push(HX_CSTRING("_sound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MP3_EXTENSION"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_src"),
	HX_CSTRING("get_currentTime"),
	HX_CSTRING("get_duration"),
	HX_CSTRING("get_bytesLoaded"),
	HX_CSTRING("get_bytesTotal"),
	HX_CSTRING("set_volume"),
	HX_CSTRING("onIOError"),
	HX_CSTRING("initSound"),
	HX_CSTRING("onID3DataReceived"),
	HX_CSTRING("canPlayType"),
	HX_CSTRING("seek"),
	HX_CSTRING("pause"),
	HX_CSTRING("play"),
	HX_CSTRING("_isPlaying"),
	HX_CSTRING("_currentTime"),
	HX_CSTRING("_soundChannel"),
	HX_CSTRING("_sound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeAudio_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NativeAudio_obj::MP3_EXTENSION,"MP3_EXTENSION");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeAudio_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NativeAudio_obj::MP3_EXTENSION,"MP3_EXTENSION");
};

Class NativeAudio_obj::__mClass;

void NativeAudio_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.NativeAudio"), hx::TCanCast< NativeAudio_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeAudio_obj::__boot()
{
	MP3_EXTENSION= HX_CSTRING("mp3");
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
