#include <hxcpp.h>

#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
namespace neash{
namespace display{

Void Bitmap_obj::__construct(::neash::display::BitmapData bitmapData,::neash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{
HX_STACK_PUSH("Bitmap::new","neash/display/Bitmap.hx",28);
bool smoothing = __o_smoothing.Default(false);
{
	HX_STACK_LINE(29)
	super::__construct(::neash::display::DisplayObject_obj::nme_create_display_object(),HX_CSTRING("Bitmap"));
	HX_STACK_LINE(31)
	this->nmeSetPixelSnapping((  (((pixelSnapping == null()))) ? ::neash::display::PixelSnapping(::neash::display::PixelSnapping_obj::AUTO_dyn()) : ::neash::display::PixelSnapping(pixelSnapping) ));
	HX_STACK_LINE(32)
	this->nmeSetSmoothing(smoothing);
	HX_STACK_LINE(34)
	if (((bitmapData != null()))){
		HX_STACK_LINE(35)
		this->nmeSetBitmapData(bitmapData);
	}
	else{
		HX_STACK_LINE(38)
		if (((this->bitmapData != null()))){
			HX_STACK_LINE(39)
			this->nmeRebuild();
		}
	}
}
;
	return null();
}

Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::neash::display::BitmapData bitmapData,::neash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(bitmapData,pixelSnapping,__o_smoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool Bitmap_obj::nmeSetSmoothing( bool inSmooth){
	HX_STACK_PUSH("Bitmap::nmeSetSmoothing","neash/display/Bitmap.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inSmooth,"inSmooth");
	HX_STACK_LINE(78)
	this->smoothing = inSmooth;
	HX_STACK_LINE(79)
	this->nmeRebuild();
	HX_STACK_LINE(81)
	return inSmooth;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,nmeSetSmoothing,return )

::neash::display::BitmapData Bitmap_obj::nmeSetBitmapData( ::neash::display::BitmapData inBitmapData){
	HX_STACK_PUSH("Bitmap::nmeSetBitmapData","neash/display/Bitmap.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inBitmapData,"inBitmapData");
	HX_STACK_LINE(69)
	this->bitmapData = inBitmapData;
	HX_STACK_LINE(70)
	this->nmeRebuild();
	HX_STACK_LINE(72)
	return inBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,nmeSetBitmapData,return )

Void Bitmap_obj::nmeRebuild( ){
{
		HX_STACK_PUSH("Bitmap::nmeRebuild","neash/display/Bitmap.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(46)
		if (((bool((this->nmeHandle != null())) && bool((this->bitmapData != null()))))){
			HX_STACK_LINE(49)
			::neash::display::Graphics gfx = this->nmeGetGraphics();		HX_STACK_VAR(gfx,"gfx");
			HX_STACK_LINE(50)
			gfx->clear();
			HX_STACK_LINE(52)
			if (((this->bitmapData != null()))){
				HX_STACK_LINE(54)
				gfx->beginBitmapFill(this->bitmapData,null(),false,this->smoothing);
				HX_STACK_LINE(55)
				gfx->drawRect((int)0,(int)0,this->bitmapData->nmeGetWidth(),this->bitmapData->nmeGetHeight());
				HX_STACK_LINE(56)
				gfx->endFill();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,nmeRebuild,(void))


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(mGraphics,"mGraphics");
	HX_MARK_MEMBER_NAME(smoothing,"smoothing");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Bitmap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mGraphics,"mGraphics");
	HX_VISIT_MEMBER_NAME(smoothing,"smoothing");
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Bitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"mGraphics") ) { return mGraphics; }
		if (HX_FIELD_EQ(inName,"smoothing") ) { return smoothing; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeRebuild") ) { return nmeRebuild_dyn(); }
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeSetSmoothing") ) { return nmeSetSmoothing_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeSetBitmapData") ) { return nmeSetBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"mGraphics") ) { mGraphics=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"smoothing") ) { if (inCallProp) return nmeSetSmoothing(inValue);smoothing=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { if (inCallProp) return nmeSetBitmapData(inValue);bitmapData=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mGraphics"));
	outFields->push(HX_CSTRING("smoothing"));
	outFields->push(HX_CSTRING("bitmapData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetSmoothing"),
	HX_CSTRING("nmeSetBitmapData"),
	HX_CSTRING("nmeRebuild"),
	HX_CSTRING("mGraphics"),
	HX_CSTRING("smoothing"),
	HX_CSTRING("bitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bitmap_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
