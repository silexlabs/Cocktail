#include <hxcpp.h>

#ifndef INCLUDED_nme_media_SoundTransform
#include <nme/media/SoundTransform.h>
#endif
namespace nme{
namespace media{

Void SoundTransform_obj::__construct(Dynamic __o_vol,Dynamic __o_panning)
{
double vol = __o_vol.Default(1.0);
double panning = __o_panning.Default(0.0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundTransform.hx",14)
	this->volume = vol;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundTransform.hx",15)
	this->pan = panning;
}
;
	return null();
}

SoundTransform_obj::~SoundTransform_obj() { }

Dynamic SoundTransform_obj::__CreateEmpty() { return  new SoundTransform_obj; }
hx::ObjectPtr< SoundTransform_obj > SoundTransform_obj::__new(Dynamic __o_vol,Dynamic __o_panning)
{  hx::ObjectPtr< SoundTransform_obj > result = new SoundTransform_obj();
	result->__construct(__o_vol,__o_panning);
	return result;}

Dynamic SoundTransform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundTransform_obj > result = new SoundTransform_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::nme::media::SoundTransform SoundTransform_obj::clone( ){
	HX_SOURCE_PUSH("SoundTransform_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/media/SoundTransform.hx",20)
	return ::nme::media::SoundTransform_obj::__new(this->volume,this->pan);
}


HX_DEFINE_DYNAMIC_FUNC0(SoundTransform_obj,clone,return )


SoundTransform_obj::SoundTransform_obj()
{
}

void SoundTransform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundTransform);
	HX_MARK_MEMBER_NAME(pan,"pan");
	HX_MARK_MEMBER_NAME(volume,"volume");
	HX_MARK_END_CLASS();
}

Dynamic SoundTransform_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pan") ) { return pan; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"volume") ) { return volume; }
	}
	return super::__Field(inName);
}

Dynamic SoundTransform_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pan") ) { pan=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"volume") ) { volume=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SoundTransform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pan"));
	outFields->push(HX_CSTRING("volume"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pan"),
	HX_CSTRING("volume"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class SoundTransform_obj::__mClass;

void SoundTransform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.media.SoundTransform"), hx::TCanCast< SoundTransform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SoundTransform_obj::__boot()
{
}

} // end namespace nme
} // end namespace media
