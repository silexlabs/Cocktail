#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
namespace neash{
namespace geom{

Void Transform_obj::__construct(::neash::display::DisplayObject inParent)
{
HX_STACK_PUSH("Transform::new","neash/geom/Transform.hx",20);
{
	HX_STACK_LINE(20)
	this->nmeObj = inParent;
}
;
	return null();
}

Transform_obj::~Transform_obj() { }

Dynamic Transform_obj::__CreateEmpty() { return  new Transform_obj; }
hx::ObjectPtr< Transform_obj > Transform_obj::__new(::neash::display::DisplayObject inParent)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inParent);
	return result;}

Dynamic Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inArgs[0]);
	return result;}

::neash::geom::Rectangle Transform_obj::nmeGetPixelBounds( ){
	HX_STACK_PUSH("Transform::nmeGetPixelBounds","neash/geom/Transform.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_LINE(36)
	return this->nmeObj->nmeGetPixelBounds();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetPixelBounds,return )

::neash::geom::Matrix Transform_obj::nmeSetMatrix( ::neash::geom::Matrix inMatrix){
	HX_STACK_PUSH("Transform::nmeSetMatrix","neash/geom/Transform.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMatrix,"inMatrix");
	HX_STACK_LINE(35)
	this->nmeObj->nmeSetMatrix(inMatrix);
	HX_STACK_LINE(35)
	return inMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,nmeSetMatrix,return )

::neash::geom::Matrix Transform_obj::nmeGetMatrix( ){
	HX_STACK_PUSH("Transform::nmeGetMatrix","neash/geom/Transform.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(34)
	return this->nmeObj->nmeGetMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetMatrix,return )

::neash::geom::Matrix Transform_obj::nmeGetConcatenatedMatrix( ){
	HX_STACK_PUSH("Transform::nmeGetConcatenatedMatrix","neash/geom/Transform.hx",33);
	HX_STACK_THIS(this);
	HX_STACK_LINE(33)
	return this->nmeObj->nmeGetConcatenatedMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetConcatenatedMatrix,return )

::neash::geom::ColorTransform Transform_obj::nmeGetConcatenatedColorTransform( ){
	HX_STACK_PUSH("Transform::nmeGetConcatenatedColorTransform","neash/geom/Transform.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_LINE(32)
	return this->nmeObj->nmeGetConcatenatedColorTransform();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetConcatenatedColorTransform,return )

::neash::geom::ColorTransform Transform_obj::nmeSetColorTransform( ::neash::geom::ColorTransform inTrans){
	HX_STACK_PUSH("Transform::nmeSetColorTransform","neash/geom/Transform.hx",31);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inTrans,"inTrans");
	HX_STACK_LINE(31)
	this->nmeObj->nmeSetColorTransform(inTrans);
	HX_STACK_LINE(31)
	return inTrans;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,nmeSetColorTransform,return )

::neash::geom::ColorTransform Transform_obj::nmeGetColorTransform( ){
	HX_STACK_PUSH("Transform::nmeGetColorTransform","neash/geom/Transform.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	return this->nmeObj->nmeGetColorTransform();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetColorTransform,return )


Transform_obj::Transform_obj()
{
}

void Transform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Transform);
	HX_MARK_MEMBER_NAME(nmeObj,"nmeObj");
	HX_MARK_MEMBER_NAME(pixelBounds,"pixelBounds");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(concatenatedMatrix,"concatenatedMatrix");
	HX_MARK_MEMBER_NAME(concatenatedColorTransform,"concatenatedColorTransform");
	HX_MARK_MEMBER_NAME(colorTransform,"colorTransform");
	HX_MARK_END_CLASS();
}

void Transform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeObj,"nmeObj");
	HX_VISIT_MEMBER_NAME(pixelBounds,"pixelBounds");
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	HX_VISIT_MEMBER_NAME(concatenatedMatrix,"concatenatedMatrix");
	HX_VISIT_MEMBER_NAME(concatenatedColorTransform,"concatenatedColorTransform");
	HX_VISIT_MEMBER_NAME(colorTransform,"colorTransform");
}

Dynamic Transform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"nmeObj") ) { return nmeObj; }
		if (HX_FIELD_EQ(inName,"matrix") ) { return inCallProp ? nmeGetMatrix() : matrix; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pixelBounds") ) { return inCallProp ? nmeGetPixelBounds() : pixelBounds; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeSetMatrix") ) { return nmeSetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMatrix") ) { return nmeGetMatrix_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return inCallProp ? nmeGetColorTransform() : colorTransform; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetPixelBounds") ) { return nmeGetPixelBounds_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"concatenatedMatrix") ) { return inCallProp ? nmeGetConcatenatedMatrix() : concatenatedMatrix; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeSetColorTransform") ) { return nmeSetColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetColorTransform") ) { return nmeGetColorTransform_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedMatrix") ) { return nmeGetConcatenatedMatrix_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"concatenatedColorTransform") ) { return inCallProp ? nmeGetConcatenatedColorTransform() : concatenatedColorTransform; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedColorTransform") ) { return nmeGetConcatenatedColorTransform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"nmeObj") ) { nmeObj=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"matrix") ) { if (inCallProp) return nmeSetMatrix(inValue);matrix=inValue.Cast< ::neash::geom::Matrix >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pixelBounds") ) { pixelBounds=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { if (inCallProp) return nmeSetColorTransform(inValue);colorTransform=inValue.Cast< ::neash::geom::ColorTransform >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"concatenatedMatrix") ) { concatenatedMatrix=inValue.Cast< ::neash::geom::Matrix >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"concatenatedColorTransform") ) { concatenatedColorTransform=inValue.Cast< ::neash::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeObj"));
	outFields->push(HX_CSTRING("pixelBounds"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("concatenatedMatrix"));
	outFields->push(HX_CSTRING("concatenatedColorTransform"));
	outFields->push(HX_CSTRING("colorTransform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetPixelBounds"),
	HX_CSTRING("nmeSetMatrix"),
	HX_CSTRING("nmeGetMatrix"),
	HX_CSTRING("nmeGetConcatenatedMatrix"),
	HX_CSTRING("nmeGetConcatenatedColorTransform"),
	HX_CSTRING("nmeSetColorTransform"),
	HX_CSTRING("nmeGetColorTransform"),
	HX_CSTRING("nmeObj"),
	HX_CSTRING("pixelBounds"),
	HX_CSTRING("matrix"),
	HX_CSTRING("concatenatedMatrix"),
	HX_CSTRING("concatenatedColorTransform"),
	HX_CSTRING("colorTransform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
};

Class Transform_obj::__mClass;

void Transform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Transform"), hx::TCanCast< Transform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Transform_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
