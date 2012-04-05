#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_media_SoundChannel
#include <nme/media/SoundChannel.h>
#endif
#ifndef INCLUDED_nme_media_SoundTransform
#include <nme/media/SoundTransform.h>
#endif
namespace nme{
namespace media{

Void SoundChannel_obj::__construct(Dynamic inSoundHandle,double startTime,int loops,::nme::media::SoundTransform sndTransform)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",26)
	super::__construct(null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",28)
	if (((sndTransform != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",29)
		this->nmeTransform = sndTransform->clone();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",33)
	this->nmeHandle = ::nme::media::SoundChannel_obj::nme_sound_channel_create(inSoundHandle,startTime,loops,this->nmeTransform);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",35)
	if (((this->nmeHandle != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",36)
		::nme::media::SoundChannel_obj::nmeIncompleteList->push(hx::ObjectPtr<OBJ_>(this));
	}
}
;
	return null();
}

SoundChannel_obj::~SoundChannel_obj() { }

Dynamic SoundChannel_obj::__CreateEmpty() { return  new SoundChannel_obj; }
hx::ObjectPtr< SoundChannel_obj > SoundChannel_obj::__new(Dynamic inSoundHandle,double startTime,int loops,::nme::media::SoundTransform sndTransform)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(inSoundHandle,startTime,loops,sndTransform);
	return result;}

Dynamic SoundChannel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundChannel_obj > result = new SoundChannel_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

bool SoundChannel_obj::nmeCheckComplete( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeCheckComplete")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",44)
	if (((bool((this->nmeHandle != null())) && bool(::nme::media::SoundChannel_obj::nme_sound_channel_is_complete(this->nmeHandle))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",46)
		this->nmeHandle = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",47)
		::nme::events::Event complete = ::nme::events::Event_obj::__new(::nme::events::Event_obj::SOUND_COMPLETE,null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",48)
		this->dispatchEvent(complete);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",50)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",53)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeCheckComplete,return )

Void SoundChannel_obj::stop( ){
{
		HX_SOURCE_PUSH("SoundChannel_obj::stop")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",89)
		::nme::media::SoundChannel_obj::nme_sound_channel_stop(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,stop,(void))

double SoundChannel_obj::nmeGetLeft( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeGetLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",99)
	return ::nme::media::SoundChannel_obj::nme_sound_channel_get_left(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetLeft,return )

double SoundChannel_obj::nmeGetRight( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeGetRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",100)
	return ::nme::media::SoundChannel_obj::nme_sound_channel_get_right(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetRight,return )

double SoundChannel_obj::nmeGetPosition( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeGetPosition")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",101)
	return ::nme::media::SoundChannel_obj::nme_sound_channel_get_position(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetPosition,return )

::nme::media::SoundTransform SoundChannel_obj::nmeGetTransform( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeGetTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",106)
	if (((this->nmeTransform == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",107)
		this->nmeTransform = ::nme::media::SoundTransform_obj::__new(null(),null());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",111)
	return this->nmeTransform->clone();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeGetTransform,return )

::nme::media::SoundTransform SoundChannel_obj::nmeSetTransform( ::nme::media::SoundTransform inTransform){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeSetTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",117)
	this->nmeTransform = inTransform->clone();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",118)
	::nme::media::SoundChannel_obj::nme_sound_channel_set_transform(this->nmeHandle,this->nmeTransform);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",120)
	return inTransform;
}


HX_DEFINE_DYNAMIC_FUNC1(SoundChannel_obj,nmeSetTransform,return )

Array< ::nme::media::SoundChannel > SoundChannel_obj::nmeIncompleteList;

bool SoundChannel_obj::nmeCompletePending( ){
	HX_SOURCE_PUSH("SoundChannel_obj::nmeCompletePending")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",61)
	return (::nme::media::SoundChannel_obj::nmeIncompleteList->length > (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmeCompletePending,return )

Void SoundChannel_obj::nmePollComplete( ){
{
		HX_SOURCE_PUSH("SoundChannel_obj::nmePollComplete")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",70)
		if (((::nme::media::SoundChannel_obj::nmeIncompleteList->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",73)
			Array< ::nme::media::SoundChannel > incomplete = Array_obj< ::nme::media::SoundChannel >::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",75)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",75)
				int _g = (int)0;
				Array< ::nme::media::SoundChannel > _g1 = ::nme::media::SoundChannel_obj::nmeIncompleteList;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",75)
				while(((_g < _g1->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",75)
					::nme::media::SoundChannel channel = _g1->__get(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",75)
					++(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",77)
					if ((!(channel->nmeCheckComplete()))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",78)
						incomplete->push(channel);
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundChannel.hx",83)
			::nme::media::SoundChannel_obj::nmeIncompleteList = incomplete;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundChannel_obj,nmePollComplete,(void))

Dynamic SoundChannel_obj::nme_sound_channel_is_complete;

Dynamic SoundChannel_obj::nme_sound_channel_get_left;

Dynamic SoundChannel_obj::nme_sound_channel_get_right;

Dynamic SoundChannel_obj::nme_sound_channel_get_position;

Dynamic SoundChannel_obj::nme_sound_channel_stop;

Dynamic SoundChannel_obj::nme_sound_channel_create;

Dynamic SoundChannel_obj::nme_sound_channel_set_transform;


SoundChannel_obj::SoundChannel_obj()
{
}

void SoundChannel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundChannel);
	HX_MARK_MEMBER_NAME(leftPeak,"leftPeak");
	HX_MARK_MEMBER_NAME(rightPeak,"rightPeak");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(soundTransform,"soundTransform");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(nmeTransform,"nmeTransform");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic SoundChannel_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftPeak") ) { return nmeGetLeft(); }
		if (HX_FIELD_EQ(inName,"position") ) { return nmeGetPosition(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightPeak") ) { return nmeGetRight(); }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
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
	case 14:
		if (HX_FIELD_EQ(inName,"soundTransform") ) { return nmeGetTransform(); }
		if (HX_FIELD_EQ(inName,"nmeGetPosition") ) { return nmeGetPosition_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmePollComplete") ) { return nmePollComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTransform") ) { return nmeGetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTransform") ) { return nmeSetTransform_dyn(); }
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
	case 22:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_stop") ) { return nme_sound_channel_stop; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create") ) { return nme_sound_channel_create; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_left") ) { return nme_sound_channel_get_left; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_right") ) { return nme_sound_channel_get_right; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_is_complete") ) { return nme_sound_channel_is_complete; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_position") ) { return nme_sound_channel_get_position; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_set_transform") ) { return nme_sound_channel_set_transform; }
	}
	return super::__Field(inName);
}

Dynamic SoundChannel_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"leftPeak") ) { leftPeak=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightPeak") ) { rightPeak=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeTransform") ) { nmeTransform=inValue.Cast< ::nme::media::SoundTransform >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"soundTransform") ) { return nmeSetTransform(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeIncompleteList") ) { nmeIncompleteList=inValue.Cast< Array< ::nme::media::SoundChannel > >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_stop") ) { nme_sound_channel_stop=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create") ) { nme_sound_channel_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_left") ) { nme_sound_channel_get_left=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_right") ) { nme_sound_channel_get_right=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_is_complete") ) { nme_sound_channel_is_complete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_get_position") ) { nme_sound_channel_get_position=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_set_transform") ) { nme_sound_channel_set_transform=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SoundChannel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("leftPeak"));
	outFields->push(HX_CSTRING("rightPeak"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("soundTransform"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("nmeTransform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nmeIncompleteList"),
	HX_CSTRING("nmeCompletePending"),
	HX_CSTRING("nmePollComplete"),
	HX_CSTRING("nme_sound_channel_is_complete"),
	HX_CSTRING("nme_sound_channel_get_left"),
	HX_CSTRING("nme_sound_channel_get_right"),
	HX_CSTRING("nme_sound_channel_get_position"),
	HX_CSTRING("nme_sound_channel_stop"),
	HX_CSTRING("nme_sound_channel_create"),
	HX_CSTRING("nme_sound_channel_set_transform"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("leftPeak"),
	HX_CSTRING("rightPeak"),
	HX_CSTRING("position"),
	HX_CSTRING("soundTransform"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("nmeTransform"),
	HX_CSTRING("nmeCheckComplete"),
	HX_CSTRING("stop"),
	HX_CSTRING("nmeGetLeft"),
	HX_CSTRING("nmeGetRight"),
	HX_CSTRING("nmeGetPosition"),
	HX_CSTRING("nmeGetTransform"),
	HX_CSTRING("nmeSetTransform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nmeIncompleteList,"nmeIncompleteList");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_is_complete,"nme_sound_channel_is_complete");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_left,"nme_sound_channel_get_left");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_right,"nme_sound_channel_get_right");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_get_position,"nme_sound_channel_get_position");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_stop,"nme_sound_channel_stop");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_create,"nme_sound_channel_create");
	HX_MARK_MEMBER_NAME(SoundChannel_obj::nme_sound_channel_set_transform,"nme_sound_channel_set_transform");
};

Class SoundChannel_obj::__mClass;

void SoundChannel_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.media.SoundChannel"), hx::TCanCast< SoundChannel_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SoundChannel_obj::__boot()
{
	hx::Static(nmeIncompleteList) = Array_obj< ::nme::media::SoundChannel >::__new();
	hx::Static(nme_sound_channel_is_complete) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_is_complete"),(int)1);
	hx::Static(nme_sound_channel_get_left) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_left"),(int)1);
	hx::Static(nme_sound_channel_get_right) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_right"),(int)1);
	hx::Static(nme_sound_channel_get_position) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_get_position"),(int)1);
	hx::Static(nme_sound_channel_stop) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_stop"),(int)1);
	hx::Static(nme_sound_channel_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_create"),(int)4);
	hx::Static(nme_sound_channel_set_transform) = ::nme::Loader_obj::load(HX_CSTRING("nme_sound_channel_set_transform"),(int)2);
}

} // end namespace nme
} // end namespace media
