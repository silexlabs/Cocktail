#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace display{

Void Sprite_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",18)
	super::__construct(::nme::display::DisplayObjectContainer_obj::nme_create_display_object_container(),this->nmeGetType());
}
;
	return null();
}

Sprite_obj::~Sprite_obj() { }

Dynamic Sprite_obj::__CreateEmpty() { return  new Sprite_obj; }
hx::ObjectPtr< Sprite_obj > Sprite_obj::__new()
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

Dynamic Sprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

::String Sprite_obj::nmeGetType( ){
	HX_SOURCE_PUSH("Sprite_obj::nmeGetType")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",25)
	::String type = ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",26)
	int pos = type.lastIndexOf(HX_CSTRING("."),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",27)
	return (  (((pos >= (int)0))) ? ::String(type.substr((pos + (int)1),null())) : ::String(type) );
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,nmeGetType,return )

Void Sprite_obj::startDrag( Dynamic __o_lockCenter,::nme::geom::Rectangle bounds){
bool lockCenter = __o_lockCenter.Default(false);
	HX_SOURCE_PUSH("Sprite_obj::startDrag");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",32)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",34)
			this->nmeGetStage()->nmeStartDrag(hx::ObjectPtr<OBJ_>(this),lockCenter,bounds);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Sprite_obj,startDrag,(void))

Void Sprite_obj::stopDrag( ){
{
		HX_SOURCE_PUSH("Sprite_obj::stopDrag")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",39)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Sprite.hx",41)
			this->nmeGetStage()->nmeStopDrag(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,stopDrag,(void))


Sprite_obj::Sprite_obj()
{
}

void Sprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sprite);
	HX_MARK_MEMBER_NAME(buttonMode,"buttonMode");
	HX_MARK_MEMBER_NAME(useHandCursor,"useHandCursor");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Sprite_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"stopDrag") ) { return stopDrag_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startDrag") ) { return startDrag_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"buttonMode") ) { return buttonMode; }
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"useHandCursor") ) { return useHandCursor; }
	}
	return super::__Field(inName);
}

Dynamic Sprite_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"buttonMode") ) { buttonMode=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"useHandCursor") ) { useHandCursor=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buttonMode"));
	outFields->push(HX_CSTRING("useHandCursor"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("buttonMode"),
	HX_CSTRING("useHandCursor"),
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("startDrag"),
	HX_CSTRING("stopDrag"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Sprite_obj::__mClass;

void Sprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Sprite"), hx::TCanCast< Sprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
