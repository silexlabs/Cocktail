#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_SampleDataEvent
#include <neash/events/SampleDataEvent.h>
#endif
#ifndef INCLUDED_neash_media_SoundChannel
#include <neash/media/SoundChannel.h>
#endif
#ifndef INCLUDED_neash_media_SoundTransform
#include <neash/media/SoundTransform.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace media{

Void SoundChannel_obj::__construct(Dynamic inSoundHandle,Float startTime,int loops,::neash::media::SoundTransform sndTransform)
{
HX_STACK_PUSH("SoundChannel::new","neash/media/SoundChannel.hx",28);
{
	HX_STACK_LINE(29)
	super::__construct(null());
	HX_STACK_LINE(31)
	if (((sndTransform != null()))){
		HX_STACK_LINE(31)
		this->nmeTransform = sndTransform->clone();
	}
	HX_STACK_LINE(35)
	if (((inSoundHandle != null()))){
		HX_STACK_LINE(36)
		this->nmeHandle = ::neash::media::SoundChannel_obj::nme_sound_channel_create(inSoundHandle,startTime,loops,this->nmeTransform);
	}
	HX_STACK_LINE(38)
	if (((this->nmeHandle != null()))){
		HX_STACK_LINE(39)
		::neash::media::SoundChannel_obj::nmeIncompleteList->push(hx::ObjectPtr<OBJ_>(this));
	}
}
;
	return null();
}

SoundChannel_obj::~SoundChannel_obj() { }

Dynamic SoundChannel_obj::__CreateEmpty() { return  new SoundChannel_obj; }
hx::ObjectPtr< SoundChannel_obj > SoundChannel_obj::__new(Dynamic inSoundHandle,Float startTime,int loops,::neash::media::SoundTransform sndTransform)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(inSoundHandle,startTime,loops,sndTransform);
	return result;}

Dynamic SoundChannel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::neash::media::SoundTransform SoundChannel_obj::nmeSetTransform( ::neash::media::SoundTransform inTransform){
	HX_STACK_PUSH("SoundChannel::nmeSetTransform","neash/media/SoundChannel.hx",136);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inTransform,"inTransform");
	HX_STACK_LINE(137)
	this->nmeTransform = inTransform->clone();
	HX_STACK_LINE(138)
	::neash::media::SoundChannel_obj::nme_sound_channel_set_transform(this->nmeHandle,this->nmeTransform);
	HX_STACK_LINE(140)
	return inTransform;
}


HX_DEFINE_DYNAMIC_FUNC1(SoundChannel_obj,nmeSetTransform,return )

::neash::media::SoundTransform SoundChannel_obj::nmeGetTransform( ){
	HX_STACK_PUSH("SoundChannel::nmeGetTransform","neash/media/SoundChannel.hx",125);
	HX_STACK_THIS(this);
	HX_STACK_LINE(126)
	if (((this->nmeTransform == null()))){
		HX_STACK_LINE(127)
		this->nmeTransform = ::neash::media::SoundTransform_obj::__new(null(),null());
	}
	HX_STACK_LINE(131)
	return this->nmeTransform->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetTransform,return )

Float SoundChannel_obj::nmeGetPosition( ){
	HX_STACK_PUSH("SoundChannel::nmeGetPosition","neash/media/SoundChannel.hx",121);
	HX_STACK_THIS(this);
	HX_STACK_LINE(121)
	return ::neash::media::SoundChannel_obj::nme_sound_channel_get_position(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetPosition,return )

Float SoundChannel_obj::nmeGetRight( ){
	HX_STACK_PUSH("SoundChannel::nmeGetRight","neash/media/SoundChannel.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(120)
	return ::neash::media::SoundChannel_obj::nme_sound_channel_get_right(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetRight,return )

Float SoundChannel_obj::nmeGetLeft( ){
	HX_STACK_PUSH("SoundChannel::nmeGetLeft","neash/media/SoundChannel.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_LINE(119)
	return ::neash::media::SoundChannel_obj::nme_sound_channel_get_left(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetLeft,return )

Void SoundChannel_obj::stop( ){
{
		HX_STACK_PUSH("SoundChannel::stop","neash/media/SoundChannel.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_LINE(109)
		::neash::media::SoundChannel_obj::nme_sound_channel_stop(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,stop,(void))

bool SoundChannel_obj::nmeCheckComplete( ){
	HX_STACK_PUSH("SoundChannel::nmeCheckComplete","neash/media/SoundChannel.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_LINE(57)
	if (((this->nmeHandle != null()))){
		HX_STACK_LINE(59)
		if (((bool((this->nmeDataProvider != null())) && bool(::neash::media::SoundChannel_obj::nme_sound_channel_needs_data(this->nmeHandle))))){
			HX_STACK_LINE(61)
			::neash::events::SampleDataEvent request = ::neash::events::SampleDataEvent_obj::__new(::neash::events::SampleDataEvent_obj::SAMPLE_DATA,null(),null());		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(62)
			request->position = ::neash::media::SoundChannel_obj::nme_sound_channel_get_data_position(this->nmeHandle);
			HX_STACK_LINE(63)
			this->nmeDataProvider->dispatchEvent(request);
			HX_STACK_LINE(64)
			if (((request->data->length > (int)0))){
				HX_STACK_LINE(65)
				::neash::media::SoundChannel_obj::nme_sound_channel_add_data(this->nmeHandle,request->data);
			}
		}
		HX_STACK_LINE(68)
		if ((::neash::media::SoundChannel_obj::nme_sound_channel_is_complete(this->nmeHandle))){
			HX_STACK_LINE(70)
			this->nmeHandle = null();
			HX_STACK_LINE(71)
			if (((this->nmeDataProvider != null()))){
				HX_STACK_LINE(72)
				(::neash::media::SoundChannel_obj::nmeDynamicSoundCount)--;
			}
			HX_STACK_LINE(73)
			::neash::events::Event complete = ::neash::events::Event_obj::__new(::neash::events::Event_obj::SOUND_COMPLETE,null(),null());		HX_STACK_VAR(complete,"complete");
			HX_STACK_LINE(74)
			this->dispatchEvent(complete);
			HX_STACK_LINE(75)
			return true;
		}
	}
	HX_STACK_LINE(79)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeCheckComplete,return )

int SoundChannel_obj::nmeDynamicSoundCount;

Array< ::neash::media::SoundChannel > SoundChannel_obj::nmeIncompleteList;

::neash::media::SoundChannel SoundChannel_obj::createDynamic( Dynamic inSoundHandle,::neash::media::SoundTransform sndTransform,::neash::events::EventDispatcher dataProvider){
	HX_STACK_PUSH("SoundChannel::createDynamic","neash/media/SoundChannel.hx",43);
	HX_STACK_ARG(inSoundHandle,"inSoundHandle");
	HX_STACK_ARG(sndTransform,"sndTransform");
	HX_STACK_ARG(dataProvider,"dataProvider");
	HX_STACK_LINE(44)
	::neash::media::SoundChannel result = ::neash::media::SoundChannel_obj::__new(null(),(int)0,(int)0,sndTransform);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(45)
	result->nmeDataProvider = dataProvider;
	HX_STACK_LINE(46)
	result->nmeHandle = inSoundHandle;
	HX_STACK_LINE(47)
	::neash::media::SoundChannel_obj::nmeIncompleteList->push(result);
	HX_STACK_LINE(48)
	(::neash::media::SoundChannel_obj::nmeDynamicSoundCount)++;
	HX_STACK_LINE(49)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(SoundChannel_obj,createDynamic,return )

bool SoundChannel_obj::nmeCompletePending( ){
	HX_STACK_PUSH("SoundChannel::nmeCompletePending","neash/media/SoundChannel.hx",84);
	HX_STACK_LINE(84)
	return (::neash::media::SoundChannel_obj::nmeIncompleteList->length > (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeCompletePending,return )

Void SoundChannel_obj::nmePollComplete( ){
{
		HX_STACK_PUSH("SoundChannel::nmePollComplete","neash/media/SoundChannel.hx",90);
		HX_STACK_LINE(90)
		if (((::neash::media::SoundChannel_obj::nmeIncompleteList->length > (int)0))){
			HX_STACK_LINE(93)
			Array< ::neash::media::SoundChannel > incomplete = Array_obj< ::neash::media::SoundChannel >::__new();		HX_STACK_VAR(incomplete,"incomplete");
			HX_STACK_LINE(95)
			{
				HX_STACK_LINE(95)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::neash::media::SoundChannel > _g1 = ::neash::media::SoundChannel_obj::nmeIncompleteList;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(95)
				while(((_g < _g1->length))){
					HX_STACK_LINE(95)
					::neash::media::SoundChannel channel = _g1->__get(_g);		HX_STACK_VAR(channel,"channel");
					HX_STACK_LINE(95)
					++(_g);
					HX_STACK_LINE(97)
					if ((!(channel->nmeCheckComplete()))){
						HX_STACK_LINE(98)
						incomplete->push(channel);
					}
				}
			}
			HX_STACK_LINE(103)
			::neash::media::SoundChannel_obj::nmeIncompleteList = incomplete;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmePollComplete,(void))

Dynamic SoundChannel_obj::nme_sound_channel_is_complete;

Dynamic SoundChannel_obj::nme_sound_channel_get_left;

Dynamic SoundChannel_obj::nme_sound_channel_get_right;

Dynamic SoundChannel_obj::nme_sound_channel_get_position;

Dynamic SoundChannel_obj::nme_sound_channel_get_data_position;

Dynamic SoundChannel_obj::nme_sound_channel_stop;

Dynamic SoundChannel_obj::nme_sound_channel_create;

Dynamic SoundChannel_obj::nme_sound_channel_set_transform;

Dynamic SoundChannel_obj::nme_sound_channel_needs_data;

Dynamic SoundChannel_obj::nme_sound_channel_add_data;


SoundChannel_obj::SoundChannel_obj()
{
}

void SoundChannel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundChannel);
	HX_MARK_MEMBER_NAME(nmeDataProvider,"nmeDataProvider");
	HX_MARK_MEMBER_NAME(nmeTransform,"nmeTransform");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(soundTransform,"soundTransform");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(rightPeak,"rightPeak");
	HX_MARK_MEMBER_NAME(leftPeak,"leftPeak");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SoundChannel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeDataProvider,"nmeDataProvider");
	HX_VISIT_MEMBER_NAME(nmeTransform,"nmeTransform");
	HX_VISIT_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_VISIT_MEMBER_NAME(soundTransform,"soundTransform");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(rightPeak,"rightPeak");
	HX_VISIT_MEMBER_NAME(leftPeak,"leftPeak");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SoundChannel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return inCallProp ? nmeGetPosition() : position; }
		if (HX_FIELD_EQ(inName,"leftPeak") ) { return inCallProp ? nmeGetLeft() : leftPeak; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"rightPeak") ) { return inCallProp ? nmeGetRight() : rightPeak; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeGetLeft") ) { return nmeGetLeft_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeGetRight") ) { return nmeGetRight_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeTransform") ) { return nmeTransform; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createDynamic") ) { return createDynamic_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeGetPosition") ) { return nmeGetPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"soundTransform") ) { return inCallProp ? nmeGetTransform() : soundTransform; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmePollComplete") ) { return nmePollComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTransform") ) { return nmeSetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTransform") ) { return nmeGetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeDataProvider") ) { return nmeDataProvider; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeCheckComplete") ) { return nmeCheckComplete_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeIncompleteList") ) { return nmeIncompleteList; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nmeCompletePending") ) { return nmeCompletePending_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeDynamicSoundCount") ) { return nmeDynamicSoundCount; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_stop") ) { return nme_sound_channel_stop; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create") ) { return nme_sound_channel_create; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_left") ) { return nme_sound_channel_get_left; }
		if (HX_FIELD_EQ(inName,"nme_sound_channel_add_data") ) { return nme_sound_channel_add_data; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_right") ) { return nme_sound_channel_get_right; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_needs_data") ) { return nme_sound_channel_needs_data; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_is_complete") ) { return nme_sound_channel_is_complete; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_position") ) { return nme_sound_channel_get_position; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_set_transform") ) { return nme_sound_channel_set_transform; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_data_position") ) { return nme_sound_channel_get_data_position; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundChannel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"leftPeak") ) { leftPeak=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightPeak") ) { rightPeak=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeTransform") ) { nmeTransform=inValue.Cast< ::neash::media::SoundTransform >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"soundTransform") ) { if (inCallProp) return nmeSetTransform(inValue);soundTransform=inValue.Cast< ::neash::media::SoundTransform >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeDataProvider") ) { nmeDataProvider=inValue.Cast< ::neash::events::EventDispatcher >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeIncompleteList") ) { nmeIncompleteList=inValue.Cast< Array< ::neash::media::SoundChannel > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeDynamicSoundCount") ) { nmeDynamicSoundCount=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_stop") ) { nme_sound_channel_stop=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create") ) { nme_sound_channel_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_left") ) { nme_sound_channel_get_left=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_sound_channel_add_data") ) { nme_sound_channel_add_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_right") ) { nme_sound_channel_get_right=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_needs_data") ) { nme_sound_channel_needs_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_is_complete") ) { nme_sound_channel_is_complete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_position") ) { nme_sound_channel_get_position=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_set_transform") ) { nme_sound_channel_set_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_data_position") ) { nme_sound_channel_get_data_position=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundChannel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeDataProvider"));
	outFields->push(HX_CSTRING("nmeTransform"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("soundTransform"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("rightPeak"));
	outFields->push(HX_CSTRING("leftPeak"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nmeDynamicSoundCount"),
	HX_CSTRING("nmeIncompleteList"),
	HX_CSTRING("createDynamic"),
	HX_CSTRING("nmeCompletePending"),
	HX_CSTRING("nmePollComplete"),
	HX_CSTRING("nme_sound_channel_is_complete"),
	HX_CSTRING("nme_sound_channel_get_left"),
	HX_CSTRING("nme_sound_channel_get_right"),
	HX_CSTRING("nme_sound_channel_get_position"),
	HX_CSTRING("nme_sound_channel_get_data_position"),
	HX_CSTRING("nme_sound_channel_stop"),
	HX_CSTRING("nme_sound_channel_create"),
	HX_CSTRING("nme_sound_channel_set_transform"),
	HX_CSTRING("nme_sound_channel_needs_data"),
	HX_CSTRING("nme_sound_channel_add_data"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetTransform"),
	HX_CSTRING("nmeGetTransform"),
	HX_CSTRING("nmeGetPosition"),
	HX_CSTRING("nmeGetRight"),
	HX_CSTRING("nmeGetLeft"),
	HX_CSTRING("stop"),
	HX_CSTRING("nmeCheckComplete"),
	HX_CSTRING("nmeDataProvider"),
	HX_CSTRING("nmeTransform"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("soundTransform"),
	HX_CSTRING("position"),
	HX_CSTRING("rightPeak"),
	HX_CSTRING("leftPeak"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundChannel_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nmeDynamicSoundCount,"nmeDynamicSoundCount");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nmeIncompleteList,"nmeIncompleteList");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_is_complete,"nme_sound_channel_is_complete");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_left,"nme_sound_channel_get_left");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_right,"nme_sound_channel_get_right");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_position,"nme_sound_channel_get_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_data_position,"nme_sound_channel_get_data_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_stop,"nme_sound_channel_stop");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_create,"nme_sound_channel_create");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_set_transform,"nme_sound_channel_set_transform");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_needs_data,"nme_sound_channel_needs_data");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_add_data,"nme_sound_channel_add_data");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nmeDynamicSoundCount,"nmeDynamicSoundCount");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nmeIncompleteList,"nmeIncompleteList");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_is_complete,"nme_sound_channel_is_complete");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_left,"nme_sound_channel_get_left");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_right,"nme_sound_channel_get_right");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_position,"nme_sound_channel_get_position");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_data_position,"nme_sound_channel_get_data_position");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_stop,"nme_sound_channel_stop");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_create,"nme_sound_channel_create");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_set_transform,"nme_sound_channel_set_transform");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_needs_data,"nme_sound_channel_needs_data");
	HX_VISIT_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_add_data,"nme_sound_channel_add_data");
};

Class SoundChannel_obj::__mClass;

void SoundChannel_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.media.SoundChannel"), hx::TCanCast< SoundChannel_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SoundChannel_obj::__boot()
{
	nmeDynamicSoundCount= (int)0;
	nmeIncompleteList= Array_obj< ::neash::media::SoundChannel >::__new();
	nme_sound_channel_is_complete= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_is_complete"),(int)1);
	nme_sound_channel_get_left= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_left"),(int)1);
	nme_sound_channel_get_right= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_right"),(int)1);
	nme_sound_channel_get_position= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_position"),(int)1);
	nme_sound_channel_get_data_position= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_data_position"),(int)1);
	nme_sound_channel_stop= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_stop"),(int)1);
	nme_sound_channel_create= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_create"),(int)4);
	nme_sound_channel_set_transform= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_set_transform"),(int)2);
	nme_sound_channel_needs_data= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_needs_data"),(int)1);
	nme_sound_channel_add_data= ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_add_data"),(int)2);
}

} // end namespace neash
} // end namespace media
