#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_BlendMode
#include <neash/display/BlendMode.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
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
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
namespace neash{
namespace display{

Void DisplayObject_obj::__construct(Dynamic inHandle,::String inType)
{
HX_STACK_PUSH("DisplayObject::new","neash/display/DisplayObject.hx",186);
{
	HX_STACK_LINE(187)
	super::__construct(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(189)
	this->nmeParent = null();
	HX_STACK_LINE(190)
	this->nmeHandle = inHandle;
	HX_STACK_LINE(191)
	this->nmeID = ::neash::display::DisplayObject_obj::nme_display_object_get_id(this->nmeHandle);
	HX_STACK_LINE(192)
	this->nmeSetName(((inType + HX_CSTRING(" ")) + this->nmeID));
}
;
	return null();
}

DisplayObject_obj::~DisplayObject_obj() { }

Dynamic DisplayObject_obj::__CreateEmpty() { return  new DisplayObject_obj; }
hx::ObjectPtr< DisplayObject_obj > DisplayObject_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic DisplayObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *DisplayObject_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::display::IBitmapDrawable_obj)) return operator ::neash::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

Float DisplayObject_obj::nmeSetY( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetY","neash/display/DisplayObject.hx",762);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(763)
	::neash::display::DisplayObject_obj::nme_display_object_set_y(this->nmeHandle,inVal);
	HX_STACK_LINE(764)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetY,return )

Float DisplayObject_obj::nmeGetY( ){
	HX_STACK_PUSH("DisplayObject::nmeGetY","neash/display/DisplayObject.hx",760);
	HX_STACK_THIS(this);
	HX_STACK_LINE(760)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetY,return )

Float DisplayObject_obj::nmeSetX( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetX","neash/display/DisplayObject.hx",754);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(755)
	::neash::display::DisplayObject_obj::nme_display_object_set_x(this->nmeHandle,inVal);
	HX_STACK_LINE(756)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetX,return )

Float DisplayObject_obj::nmeGetX( ){
	HX_STACK_PUSH("DisplayObject::nmeGetX","neash/display/DisplayObject.hx",752);
	HX_STACK_THIS(this);
	HX_STACK_LINE(752)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetX,return )

Float DisplayObject_obj::nmeSetWidth( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetWidth","neash/display/DisplayObject.hx",746);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(747)
	::neash::display::DisplayObject_obj::nme_display_object_set_width(this->nmeHandle,inVal);
	HX_STACK_LINE(748)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetWidth,return )

Float DisplayObject_obj::nmeGetWidth( ){
	HX_STACK_PUSH("DisplayObject::nmeGetWidth","neash/display/DisplayObject.hx",744);
	HX_STACK_THIS(this);
	HX_STACK_LINE(744)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetWidth,return )

bool DisplayObject_obj::nmeSetVisible( bool inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetVisible","neash/display/DisplayObject.hx",738);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(739)
	::neash::display::DisplayObject_obj::nme_display_object_set_visible(this->nmeHandle,inVal);
	HX_STACK_LINE(740)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetVisible,return )

bool DisplayObject_obj::nmeGetVisible( ){
	HX_STACK_PUSH("DisplayObject::nmeGetVisible","neash/display/DisplayObject.hx",736);
	HX_STACK_THIS(this);
	HX_STACK_LINE(736)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_visible(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetVisible,return )

::neash::geom::Transform DisplayObject_obj::nmeSetTransform( ::neash::geom::Transform inTransform){
	HX_STACK_PUSH("DisplayObject::nmeSetTransform","neash/display/DisplayObject.hx",729);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inTransform,"inTransform");
	HX_STACK_LINE(730)
	this->nmeSetMatrix(inTransform->nmeGetMatrix());
	HX_STACK_LINE(731)
	this->nmeSetColorTransform(inTransform->nmeGetColorTransform());
	HX_STACK_LINE(732)
	return inTransform;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetTransform,return )

::neash::geom::Transform DisplayObject_obj::nmeGetTransform( ){
	HX_STACK_PUSH("DisplayObject::nmeGetTransform","neash/display/DisplayObject.hx",727);
	HX_STACK_THIS(this);
	HX_STACK_LINE(727)
	return ::neash::geom::Transform_obj::__new(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetTransform,return )

::neash::display::Stage DisplayObject_obj::nmeGetStage( ){
	HX_STACK_PUSH("DisplayObject::nmeGetStage","neash/display/DisplayObject.hx",719);
	HX_STACK_THIS(this);
	HX_STACK_LINE(720)
	if (((this->nmeParent != null()))){
		HX_STACK_LINE(721)
		return this->nmeParent->nmeGetStage();
	}
	HX_STACK_LINE(723)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetStage,return )

::neash::geom::Rectangle DisplayObject_obj::nmeSetScrollRect( ::neash::geom::Rectangle inRect){
	HX_STACK_PUSH("DisplayObject::nmeSetScrollRect","neash/display/DisplayObject.hx",711);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inRect,"inRect");
	HX_STACK_LINE(712)
	this->nmeScrollRect = (  (((inRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(inRect->clone()) );
	HX_STACK_LINE(713)
	::neash::display::DisplayObject_obj::nme_display_object_set_scroll_rect(this->nmeHandle,this->nmeScrollRect);
	HX_STACK_LINE(714)
	return inRect;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScrollRect,return )

::neash::geom::Rectangle DisplayObject_obj::nmeGetScrollRect( ){
	HX_STACK_PUSH("DisplayObject::nmeGetScrollRect","neash/display/DisplayObject.hx",709);
	HX_STACK_THIS(this);
	HX_STACK_LINE(709)
	return (  (((this->nmeScrollRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(this->nmeScrollRect->clone()) );
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScrollRect,return )

Float DisplayObject_obj::nmeSetScaleY( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetScaleY","neash/display/DisplayObject.hx",703);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(704)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale_y(this->nmeHandle,inVal);
	HX_STACK_LINE(705)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScaleY,return )

Float DisplayObject_obj::nmeGetScaleY( ){
	HX_STACK_PUSH("DisplayObject::nmeGetScaleY","neash/display/DisplayObject.hx",701);
	HX_STACK_THIS(this);
	HX_STACK_LINE(701)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_scale_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScaleY,return )

Float DisplayObject_obj::nmeSetScaleX( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetScaleX","neash/display/DisplayObject.hx",695);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(696)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale_x(this->nmeHandle,inVal);
	HX_STACK_LINE(697)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScaleX,return )

Float DisplayObject_obj::nmeGetScaleX( ){
	HX_STACK_PUSH("DisplayObject::nmeGetScaleX","neash/display/DisplayObject.hx",693);
	HX_STACK_THIS(this);
	HX_STACK_LINE(693)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_scale_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScaleX,return )

::neash::geom::Rectangle DisplayObject_obj::nmeSetScale9Grid( ::neash::geom::Rectangle inRect){
	HX_STACK_PUSH("DisplayObject::nmeSetScale9Grid","neash/display/DisplayObject.hx",686);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inRect,"inRect");
	HX_STACK_LINE(687)
	this->nmeScale9Grid = (  (((inRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(inRect->clone()) );
	HX_STACK_LINE(688)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale9_grid(this->nmeHandle,this->nmeScale9Grid);
	HX_STACK_LINE(689)
	return inRect;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScale9Grid,return )

::neash::geom::Rectangle DisplayObject_obj::nmeGetScale9Grid( ){
	HX_STACK_PUSH("DisplayObject::nmeGetScale9Grid","neash/display/DisplayObject.hx",684);
	HX_STACK_THIS(this);
	HX_STACK_LINE(684)
	return (  (((this->nmeScale9Grid == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(this->nmeScale9Grid->clone()) );
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScale9Grid,return )

Float DisplayObject_obj::nmeSetRotation( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetRotation","neash/display/DisplayObject.hx",678);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(679)
	::neash::display::DisplayObject_obj::nme_display_object_set_rotation(this->nmeHandle,inVal);
	HX_STACK_LINE(680)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetRotation,return )

Float DisplayObject_obj::nmeGetRotation( ){
	HX_STACK_PUSH("DisplayObject::nmeGetRotation","neash/display/DisplayObject.hx",676);
	HX_STACK_THIS(this);
	HX_STACK_LINE(676)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_rotation(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetRotation,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::nmeSetParent( ::neash::display::DisplayObjectContainer inParent){
	HX_STACK_PUSH("DisplayObject::nmeSetParent","neash/display/DisplayObject.hx",649);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inParent,"inParent");
	HX_STACK_LINE(650)
	if (((inParent == this->nmeParent))){
		HX_STACK_LINE(651)
		return inParent;
	}
	HX_STACK_LINE(653)
	if (((this->nmeParent != null()))){
		HX_STACK_LINE(654)
		this->nmeParent->nmeRemoveChildFromArray(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(656)
	if (((bool((this->nmeParent == null())) && bool((inParent != null()))))){
		HX_STACK_LINE(658)
		this->nmeParent = inParent;
		HX_STACK_LINE(659)
		this->nmeOnAdded(hx::ObjectPtr<OBJ_>(this),(this->nmeGetStage() != null()));
	}
	else{
		HX_STACK_LINE(661)
		if (((bool((this->nmeParent != null())) && bool((inParent == null()))))){
			HX_STACK_LINE(663)
			bool was_on_stage = (this->nmeGetStage() != null());		HX_STACK_VAR(was_on_stage,"was_on_stage");
			HX_STACK_LINE(664)
			this->nmeParent = inParent;
			HX_STACK_LINE(665)
			this->nmeOnRemoved(hx::ObjectPtr<OBJ_>(this),was_on_stage);
		}
		else{
			HX_STACK_LINE(668)
			this->nmeParent = inParent;
		}
	}
	HX_STACK_LINE(672)
	return inParent;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetParent,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::nmeGetParent( ){
	HX_STACK_PUSH("DisplayObject::nmeGetParent","neash/display/DisplayObject.hx",645);
	HX_STACK_THIS(this);
	HX_STACK_LINE(645)
	return this->nmeParent;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetParent,return )

::String DisplayObject_obj::nmeSetName( ::String inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetName","neash/display/DisplayObject.hx",639);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(640)
	::neash::display::DisplayObject_obj::nme_display_object_set_name(this->nmeHandle,inVal);
	HX_STACK_LINE(641)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetName,return )

::String DisplayObject_obj::nmeGetName( ){
	HX_STACK_PUSH("DisplayObject::nmeGetName","neash/display/DisplayObject.hx",637);
	HX_STACK_THIS(this);
	HX_STACK_LINE(637)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_name(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetName,return )

Float DisplayObject_obj::nmeGetMouseY( ){
	HX_STACK_PUSH("DisplayObject::nmeGetMouseY","neash/display/DisplayObject.hx",634);
	HX_STACK_THIS(this);
	HX_STACK_LINE(634)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_mouse_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMouseY,return )

Float DisplayObject_obj::nmeGetMouseX( ){
	HX_STACK_PUSH("DisplayObject::nmeGetMouseX","neash/display/DisplayObject.hx",633);
	HX_STACK_THIS(this);
	HX_STACK_LINE(633)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_mouse_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMouseX,return )

::neash::display::DisplayObject DisplayObject_obj::nmeSetMask( ::neash::display::DisplayObject inObject){
	HX_STACK_PUSH("DisplayObject::nmeSetMask","neash/display/DisplayObject.hx",626);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inObject,"inObject");
	HX_STACK_LINE(627)
	this->mask = inObject;
	HX_STACK_LINE(628)
	::neash::display::DisplayObject_obj::nme_display_object_set_mask(this->nmeHandle,(  (((inObject == null()))) ? Dynamic(null()) : Dynamic(inObject->nmeHandle) ));
	HX_STACK_LINE(629)
	return inObject;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetMask,return )

Float DisplayObject_obj::nmeSetHeight( Float inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetHeight","neash/display/DisplayObject.hx",619);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(620)
	::neash::display::DisplayObject_obj::nme_display_object_set_height(this->nmeHandle,inVal);
	HX_STACK_LINE(621)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetHeight,return )

Float DisplayObject_obj::nmeGetHeight( ){
	HX_STACK_PUSH("DisplayObject::nmeGetHeight","neash/display/DisplayObject.hx",617);
	HX_STACK_THIS(this);
	HX_STACK_LINE(617)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetHeight,return )

::neash::display::Graphics DisplayObject_obj::nmeGetGraphics( ){
	HX_STACK_PUSH("DisplayObject::nmeGetGraphics","neash/display/DisplayObject.hx",610);
	HX_STACK_THIS(this);
	HX_STACK_LINE(611)
	if (((this->nmeGraphicsCache == null()))){
		HX_STACK_LINE(612)
		this->nmeGraphicsCache = ::neash::display::Graphics_obj::__new(::neash::display::DisplayObject_obj::nme_display_object_get_graphics(this->nmeHandle));
	}
	HX_STACK_LINE(613)
	return this->nmeGraphicsCache;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetGraphics,return )

Dynamic DisplayObject_obj::nmeSetFilters( Dynamic inFilters){
	HX_STACK_PUSH("DisplayObject::nmeSetFilters","neash/display/DisplayObject.hx",590);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inFilters,"inFilters");
	HX_STACK_LINE(591)
	if (((inFilters == null()))){
		HX_STACK_LINE(592)
		this->nmeFilters = null();
	}
	else{
		HX_STACK_LINE(597)
		this->nmeFilters = Dynamic( Array_obj<Dynamic>::__new() );
		HX_STACK_LINE(599)
		{
			HX_STACK_LINE(599)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(599)
			while(((_g < inFilters->__Field(HX_CSTRING("length"),true)))){
				HX_STACK_LINE(599)
				Dynamic filter = inFilters->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(599)
				++(_g);
				HX_STACK_LINE(600)
				this->nmeFilters->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
			}
		}
	}
	HX_STACK_LINE(603)
	::neash::display::DisplayObject_obj::nme_display_object_set_filters(this->nmeHandle,this->nmeFilters);
	HX_STACK_LINE(605)
	return inFilters;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetFilters,return )

Dynamic DisplayObject_obj::nmeGetFilters( ){
	HX_STACK_PUSH("DisplayObject::nmeGetFilters","neash/display/DisplayObject.hx",577);
	HX_STACK_THIS(this);
	HX_STACK_LINE(578)
	if (((this->nmeFilters == null()))){
		HX_STACK_LINE(578)
		return Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(580)
	Dynamic result = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(582)
	{
		HX_STACK_LINE(582)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Dynamic _g1 = this->nmeFilters;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(582)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(582)
			Dynamic filter = _g1->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
			HX_STACK_LINE(582)
			++(_g);
			HX_STACK_LINE(583)
			result->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
		}
	}
	HX_STACK_LINE(585)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetFilters,return )

::neash::display::PixelSnapping DisplayObject_obj::nmeSetPixelSnapping( ::neash::display::PixelSnapping inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetPixelSnapping","neash/display/DisplayObject.hx",569);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(570)
	if (((inVal == null()))){
		HX_STACK_LINE(571)
		::neash::display::DisplayObject_obj::nme_display_object_set_pixel_snapping(this->nmeHandle,(int)0);
	}
	HX_STACK_LINE(572)
	::neash::display::DisplayObject_obj::nme_display_object_set_pixel_snapping(this->nmeHandle,inVal->__Index());
	HX_STACK_LINE(573)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetPixelSnapping,return )

::neash::display::PixelSnapping DisplayObject_obj::nmeGetPixelSnapping( ){
	HX_STACK_PUSH("DisplayObject::nmeGetPixelSnapping","neash/display/DisplayObject.hx",564);
	HX_STACK_THIS(this);
	HX_STACK_LINE(565)
	int val = ::neash::display::DisplayObject_obj::nme_display_object_get_pixel_snapping(this->nmeHandle);		HX_STACK_VAR(val,"val");
	HX_STACK_LINE(566)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::PixelSnapping >(),val,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetPixelSnapping,return )

bool DisplayObject_obj::nmeSetPedanticBitmapCaching( bool inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetPedanticBitmapCaching","neash/display/DisplayObject.hx",559);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(560)
	::neash::display::DisplayObject_obj::nme_display_object_set_pedantic_bitmap_caching(this->nmeHandle,inVal);
	HX_STACK_LINE(561)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetPedanticBitmapCaching,return )

bool DisplayObject_obj::nmeGetPedanticBitmapCaching( ){
	HX_STACK_PUSH("DisplayObject::nmeGetPedanticBitmapCaching","neash/display/DisplayObject.hx",557);
	HX_STACK_THIS(this);
	HX_STACK_LINE(557)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_pedantic_bitmap_caching(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetPedanticBitmapCaching,return )

bool DisplayObject_obj::nmeSetCacheAsBitmap( bool inVal){
	HX_STACK_PUSH("DisplayObject::nmeSetCacheAsBitmap","neash/display/DisplayObject.hx",552);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(553)
	::neash::display::DisplayObject_obj::nme_display_object_set_cache_as_bitmap(this->nmeHandle,inVal);
	HX_STACK_LINE(554)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetCacheAsBitmap,return )

bool DisplayObject_obj::nmeGetCacheAsBitmap( ){
	HX_STACK_PUSH("DisplayObject::nmeGetCacheAsBitmap","neash/display/DisplayObject.hx",550);
	HX_STACK_THIS(this);
	HX_STACK_LINE(550)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_cache_as_bitmap(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetCacheAsBitmap,return )

::neash::display::BlendMode DisplayObject_obj::nmeSetBlendMode( ::neash::display::BlendMode inMode){
	HX_STACK_PUSH("DisplayObject::nmeSetBlendMode","neash/display/DisplayObject.hx",544);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(545)
	::neash::display::DisplayObject_obj::nme_display_object_set_blend_mode(this->nmeHandle,inMode->__Index());
	HX_STACK_LINE(546)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetBlendMode,return )

::neash::display::BlendMode DisplayObject_obj::nmeGetBlendMode( ){
	HX_STACK_PUSH("DisplayObject::nmeGetBlendMode","neash/display/DisplayObject.hx",537);
	HX_STACK_THIS(this);
	HX_STACK_LINE(538)
	int i = ::neash::display::DisplayObject_obj::nme_display_object_get_blend_mode(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(539)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::BlendMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetBlendMode,return )

Dynamic DisplayObject_obj::nmeSetBG( Dynamic inBG){
	HX_STACK_PUSH("DisplayObject::nmeSetBG","neash/display/DisplayObject.hx",526);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inBG,"inBG");
	HX_STACK_LINE(527)
	if (((inBG == null()))){
		HX_STACK_LINE(528)
		::neash::display::DisplayObject_obj::nme_display_object_set_bg(this->nmeHandle,(int)0);
	}
	else{
		HX_STACK_LINE(530)
		::neash::display::DisplayObject_obj::nme_display_object_set_bg(this->nmeHandle,inBG);
	}
	HX_STACK_LINE(532)
	return inBG;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetBG,return )

Dynamic DisplayObject_obj::nmeGetBG( ){
	HX_STACK_PUSH("DisplayObject::nmeGetBG","neash/display/DisplayObject.hx",516);
	HX_STACK_THIS(this);
	HX_STACK_LINE(517)
	int i = ::neash::display::DisplayObject_obj::nme_display_object_get_bg(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(518)
	if (((((int(i) & int((int)16777216))) == (int)0))){
		HX_STACK_LINE(519)
		return null();
	}
	HX_STACK_LINE(521)
	return (int(i) & int((int)16777215));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetBG,return )

Float DisplayObject_obj::nmeSetAlpha( Float inAlpha){
	HX_STACK_PUSH("DisplayObject::nmeSetAlpha","neash/display/DisplayObject.hx",509);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inAlpha,"inAlpha");
	HX_STACK_LINE(510)
	::neash::display::DisplayObject_obj::nme_display_object_set_alpha(this->nmeHandle,inAlpha);
	HX_STACK_LINE(511)
	return inAlpha;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetAlpha,return )

Float DisplayObject_obj::nmeGetAlpha( ){
	HX_STACK_PUSH("DisplayObject::nmeGetAlpha","neash/display/DisplayObject.hx",507);
	HX_STACK_THIS(this);
	HX_STACK_LINE(507)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_alpha(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetAlpha,return )

::String DisplayObject_obj::toString( ){
	HX_STACK_PUSH("DisplayObject::toString","neash/display/DisplayObject.hx",497);
	HX_STACK_THIS(this);
	HX_STACK_LINE(497)
	return this->nmeGetName();
}


Void DisplayObject_obj::nmeSetMatrix( ::neash::geom::Matrix inMatrix){
{
		HX_STACK_PUSH("DisplayObject::nmeSetMatrix","neash/display/DisplayObject.hx",488);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inMatrix,"inMatrix");
		HX_STACK_LINE(488)
		::neash::display::DisplayObject_obj::nme_display_object_set_matrix(this->nmeHandle,inMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetMatrix,(void))

Void DisplayObject_obj::nmeSetColorTransform( ::neash::geom::ColorTransform inTrans){
{
		HX_STACK_PUSH("DisplayObject::nmeSetColorTransform","neash/display/DisplayObject.hx",482);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inTrans,"inTrans");
		HX_STACK_LINE(482)
		::neash::display::DisplayObject_obj::nme_display_object_set_color_transform(this->nmeHandle,inTrans);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetColorTransform,(void))

Void DisplayObject_obj::nmeOnRemoved( ::neash::display::DisplayObject inObj,bool inWasOnStage){
{
		HX_STACK_PUSH("DisplayObject::nmeOnRemoved","neash/display/DisplayObject.hx",464);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inObj,"inObj");
		HX_STACK_ARG(inWasOnStage,"inWasOnStage");
		HX_STACK_LINE(465)
		if (((inObj == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(467)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED,true,false);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(468)
			evt->nmeSetTarget(inObj);
			HX_STACK_LINE(469)
			this->dispatchEvent(evt);
		}
		HX_STACK_LINE(472)
		if ((inWasOnStage)){
			HX_STACK_LINE(474)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED_FROM_STAGE,false,false);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(475)
			evt->nmeSetTarget(inObj);
			HX_STACK_LINE(476)
			this->dispatchEvent(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeOnRemoved,(void))

Void DisplayObject_obj::nmeOnAdded( ::neash::display::DisplayObject inObj,bool inIsOnStage){
{
		HX_STACK_PUSH("DisplayObject::nmeOnAdded","neash/display/DisplayObject.hx",446);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inObj,"inObj");
		HX_STACK_ARG(inIsOnStage,"inIsOnStage");
		HX_STACK_LINE(447)
		if (((inObj == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(449)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED,true,false);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(450)
			evt->nmeSetTarget(inObj);
			HX_STACK_LINE(451)
			this->dispatchEvent(evt);
		}
		HX_STACK_LINE(454)
		if ((inIsOnStage)){
			HX_STACK_LINE(456)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED_TO_STAGE,false,false);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(457)
			evt->nmeSetTarget(inObj);
			HX_STACK_LINE(458)
			this->dispatchEvent(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeOnAdded,(void))

::neash::geom::Rectangle DisplayObject_obj::nmeGetPixelBounds( ){
	HX_STACK_PUSH("DisplayObject::nmeGetPixelBounds","neash/display/DisplayObject.hx",438);
	HX_STACK_THIS(this);
	HX_STACK_LINE(439)
	::neash::geom::Rectangle rect = ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(440)
	::neash::display::DisplayObject_obj::nme_display_object_get_pixel_bounds(this->nmeHandle,rect);
	HX_STACK_LINE(441)
	return rect;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetPixelBounds,return )

Void DisplayObject_obj::nmeGetObjectsUnderPoint( ::neash::geom::Point point,Array< ::neash::display::DisplayObject > result){
{
		HX_STACK_PUSH("DisplayObject::nmeGetObjectsUnderPoint","neash/display/DisplayObject.hx",431);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(431)
		if ((::neash::display::DisplayObject_obj::nme_display_object_hit_test_point(this->nmeHandle,point->x,point->y,true,false))){
			HX_STACK_LINE(433)
			result->push(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeGetObjectsUnderPoint,(void))

::neash::geom::Matrix DisplayObject_obj::nmeGetMatrix( ){
	HX_STACK_PUSH("DisplayObject::nmeGetMatrix","neash/display/DisplayObject.hx",423);
	HX_STACK_THIS(this);
	HX_STACK_LINE(424)
	::neash::geom::Matrix mtx = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(mtx,"mtx");
	HX_STACK_LINE(425)
	::neash::display::DisplayObject_obj::nme_display_object_get_matrix(this->nmeHandle,mtx,false);
	HX_STACK_LINE(426)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMatrix,return )

Void DisplayObject_obj::nmeGetInteractiveObjectStack( Array< ::neash::display::InteractiveObject > outStack){
{
		HX_STACK_PUSH("DisplayObject::nmeGetInteractiveObjectStack","neash/display/DisplayObject.hx",411);
		HX_STACK_THIS(this);
		HX_STACK_ARG(outStack,"outStack");
		HX_STACK_LINE(412)
		::neash::display::InteractiveObject io = this->nmeAsInteractiveObject();		HX_STACK_VAR(io,"io");
		HX_STACK_LINE(414)
		if (((io != null()))){
			HX_STACK_LINE(415)
			outStack->push(io);
		}
		HX_STACK_LINE(417)
		if (((this->nmeParent != null()))){
			HX_STACK_LINE(418)
			this->nmeParent->nmeGetInteractiveObjectStack(outStack);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeGetInteractiveObjectStack,(void))

::neash::geom::Matrix DisplayObject_obj::nmeGetConcatenatedMatrix( ){
	HX_STACK_PUSH("DisplayObject::nmeGetConcatenatedMatrix","neash/display/DisplayObject.hx",403);
	HX_STACK_THIS(this);
	HX_STACK_LINE(404)
	::neash::geom::Matrix mtx = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(mtx,"mtx");
	HX_STACK_LINE(405)
	::neash::display::DisplayObject_obj::nme_display_object_get_matrix(this->nmeHandle,mtx,true);
	HX_STACK_LINE(406)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetConcatenatedMatrix,return )

::neash::geom::ColorTransform DisplayObject_obj::nmeGetConcatenatedColorTransform( ){
	HX_STACK_PUSH("DisplayObject::nmeGetConcatenatedColorTransform","neash/display/DisplayObject.hx",395);
	HX_STACK_THIS(this);
	HX_STACK_LINE(396)
	::neash::geom::ColorTransform trans = ::neash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(trans,"trans");
	HX_STACK_LINE(397)
	::neash::display::DisplayObject_obj::nme_display_object_get_color_transform(this->nmeHandle,trans,true);
	HX_STACK_LINE(398)
	return trans;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetConcatenatedColorTransform,return )

::neash::geom::ColorTransform DisplayObject_obj::nmeGetColorTransform( ){
	HX_STACK_PUSH("DisplayObject::nmeGetColorTransform","neash/display/DisplayObject.hx",387);
	HX_STACK_THIS(this);
	HX_STACK_LINE(388)
	::neash::geom::ColorTransform trans = ::neash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(trans,"trans");
	HX_STACK_LINE(389)
	::neash::display::DisplayObject_obj::nme_display_object_get_color_transform(this->nmeHandle,trans,false);
	HX_STACK_LINE(390)
	return trans;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetColorTransform,return )

Void DisplayObject_obj::nmeFireEvent( ::neash::events::Event inEvt){
{
		HX_STACK_PUSH("DisplayObject::nmeFireEvent","neash/display/DisplayObject.hx",335);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvt,"inEvt");
		HX_STACK_LINE(336)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(338)
		if (((this->nmeParent != null()))){
			HX_STACK_LINE(339)
			this->nmeParent->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(341)
		int l = stack->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(343)
		if (((l > (int)0))){
			HX_STACK_LINE(346)
			inEvt->nmeSetPhase(::neash::events::EventPhase_obj::CAPTURING_PHASE);
			HX_STACK_LINE(347)
			stack->reverse();
			HX_STACK_LINE(349)
			{
				HX_STACK_LINE(349)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(349)
				while(((_g < stack->length))){
					HX_STACK_LINE(349)
					::neash::display::InteractiveObject obj = stack->__get(_g);		HX_STACK_VAR(obj,"obj");
					HX_STACK_LINE(349)
					++(_g);
					HX_STACK_LINE(351)
					inEvt->nmeSetCurrentTarget(obj);
					HX_STACK_LINE(352)
					obj->nmeDispatchEvent(inEvt);
					HX_STACK_LINE(354)
					if ((inEvt->nmeGetIsCancelled())){
						HX_STACK_LINE(355)
						return null();
					}
				}
			}
		}
		HX_STACK_LINE(361)
		inEvt->nmeSetPhase(::neash::events::EventPhase_obj::AT_TARGET);
		HX_STACK_LINE(362)
		inEvt->nmeSetCurrentTarget(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(363)
		this->nmeDispatchEvent(inEvt);
		HX_STACK_LINE(365)
		if ((inEvt->nmeGetIsCancelled())){
			HX_STACK_LINE(366)
			return null();
		}
		HX_STACK_LINE(369)
		if ((inEvt->nmeGetBubbles())){
			HX_STACK_LINE(371)
			inEvt->nmeSetPhase(::neash::events::EventPhase_obj::BUBBLING_PHASE);
			HX_STACK_LINE(372)
			stack->reverse();
			HX_STACK_LINE(374)
			{
				HX_STACK_LINE(374)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(374)
				while(((_g < stack->length))){
					HX_STACK_LINE(374)
					::neash::display::InteractiveObject obj = stack->__get(_g);		HX_STACK_VAR(obj,"obj");
					HX_STACK_LINE(374)
					++(_g);
					HX_STACK_LINE(376)
					inEvt->nmeSetCurrentTarget(obj);
					HX_STACK_LINE(377)
					obj->nmeDispatchEvent(inEvt);
					HX_STACK_LINE(379)
					if ((inEvt->nmeGetIsCancelled())){
						HX_STACK_LINE(380)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeFireEvent,(void))

::neash::display::DisplayObject DisplayObject_obj::nmeFindByID( int inID){
	HX_STACK_PUSH("DisplayObject::nmeFindByID","neash/display/DisplayObject.hx",327);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inID,"inID");
	HX_STACK_LINE(328)
	if (((this->nmeID == inID))){
		HX_STACK_LINE(329)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(330)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeFindByID,return )

Void DisplayObject_obj::nmeDrawToSurface( Dynamic inSurface,::neash::geom::Matrix matrix,::neash::geom::ColorTransform colorTransform,::String blendMode,::neash::geom::Rectangle clipRect,bool smoothing){
{
		HX_STACK_PUSH("DisplayObject::nmeDrawToSurface","neash/display/DisplayObject.hx",320);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSurface,"inSurface");
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(smoothing,"smoothing");
		HX_STACK_LINE(320)
		::neash::display::DisplayObject_obj::nme_display_object_draw_to_surface(this->nmeHandle,inSurface,matrix,colorTransform,blendMode,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(DisplayObject_obj,nmeDrawToSurface,(void))

bool DisplayObject_obj::nmeDispatchEvent( ::neash::events::Event inEvt){
	HX_STACK_PUSH("DisplayObject::nmeDispatchEvent","neash/display/DisplayObject.hx",309);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvt,"inEvt");
	HX_STACK_LINE(310)
	if (((inEvt->nmeGetTarget() == null()))){
		HX_STACK_LINE(311)
		inEvt->nmeSetTarget(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(314)
	inEvt->nmeSetCurrentTarget(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(315)
	return this->super::dispatchEvent(inEvt);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeDispatchEvent,return )

Void DisplayObject_obj::nmeBroadcast( ::neash::events::Event inEvt){
{
		HX_STACK_PUSH("DisplayObject::nmeBroadcast","neash/display/DisplayObject.hx",303);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvt,"inEvt");
		HX_STACK_LINE(303)
		this->nmeDispatchEvent(inEvt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeBroadcast,(void))

::neash::display::InteractiveObject DisplayObject_obj::nmeAsInteractiveObject( ){
	HX_STACK_PUSH("DisplayObject::nmeAsInteractiveObject","neash/display/DisplayObject.hx",297);
	HX_STACK_THIS(this);
	HX_STACK_LINE(297)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeAsInteractiveObject,return )

::neash::geom::Point DisplayObject_obj::localToGlobal( ::neash::geom::Point inLocal){
	HX_STACK_PUSH("DisplayObject::localToGlobal","neash/display/DisplayObject.hx",289);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inLocal,"inLocal");
	HX_STACK_LINE(290)
	::neash::geom::Point result = inLocal->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(291)
	::neash::display::DisplayObject_obj::nme_display_object_local_to_global(this->nmeHandle,result);
	HX_STACK_LINE(292)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,localToGlobal,return )

::neash::geom::Rectangle DisplayObject_obj::getRect( ::neash::display::DisplayObject targetCoordinateSpace){
	HX_STACK_PUSH("DisplayObject::getRect","neash/display/DisplayObject.hx",274);
	HX_STACK_THIS(this);
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace");
	HX_STACK_LINE(275)
	::neash::geom::Rectangle result = ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(276)
	::neash::display::DisplayObject_obj::nme_display_object_get_bounds(this->nmeHandle,targetCoordinateSpace->nmeHandle,result,false);
	HX_STACK_LINE(277)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getRect,return )

::neash::geom::Rectangle DisplayObject_obj::getBounds( ::neash::display::DisplayObject targetCoordinateSpace){
	HX_STACK_PUSH("DisplayObject::getBounds","neash/display/DisplayObject.hx",267);
	HX_STACK_THIS(this);
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace");
	HX_STACK_LINE(268)
	::neash::geom::Rectangle result = ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(269)
	::neash::display::DisplayObject_obj::nme_display_object_get_bounds(this->nmeHandle,targetCoordinateSpace->nmeHandle,result,true);
	HX_STACK_LINE(270)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getBounds,return )

bool DisplayObject_obj::hitTestPoint( Float x,Float y,hx::Null< bool >  __o_shapeFlag){
bool shapeFlag = __o_shapeFlag.Default(false);
	HX_STACK_PUSH("DisplayObject::hitTestPoint","neash/display/DisplayObject.hx",262);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(shapeFlag,"shapeFlag");
{
		HX_STACK_LINE(262)
		return ::neash::display::DisplayObject_obj::nme_display_object_hit_test_point(this->nmeHandle,x,y,shapeFlag,true);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,hitTestPoint,return )

bool DisplayObject_obj::hitTestObject( ::neash::display::DisplayObject object){
	HX_STACK_PUSH("DisplayObject::hitTestObject","neash/display/DisplayObject.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_ARG(object,"object");
	HX_STACK_LINE(227)
	if (((bool((bool((object != null())) && bool((object->nmeGetParent() != null())))) && bool((this->nmeGetParent() != null()))))){
		HX_STACK_LINE(229)
		::neash::geom::Matrix currentMatrix = this->nmeGetTransform()->nmeGetConcatenatedMatrix();		HX_STACK_VAR(currentMatrix,"currentMatrix");
		HX_STACK_LINE(230)
		::neash::geom::Matrix targetMatrix = object->nmeGetTransform()->nmeGetConcatenatedMatrix();		HX_STACK_VAR(targetMatrix,"targetMatrix");
		HX_STACK_LINE(232)
		::neash::geom::Point xPoint = ::neash::geom::Point_obj::__new((int)1,(int)0);		HX_STACK_VAR(xPoint,"xPoint");
		HX_STACK_LINE(233)
		::neash::geom::Point yPoint = ::neash::geom::Point_obj::__new((int)0,(int)1);		HX_STACK_VAR(yPoint,"yPoint");
		HX_STACK_LINE(235)
		Float currentWidth = (this->nmeGetWidth() * currentMatrix->deltaTransformPoint(xPoint)->nmeGetLength());		HX_STACK_VAR(currentWidth,"currentWidth");
		HX_STACK_LINE(236)
		Float currentHeight = (this->nmeGetHeight() * currentMatrix->deltaTransformPoint(yPoint)->nmeGetLength());		HX_STACK_VAR(currentHeight,"currentHeight");
		HX_STACK_LINE(237)
		Float targetWidth = (object->nmeGetWidth() * targetMatrix->deltaTransformPoint(xPoint)->nmeGetLength());		HX_STACK_VAR(targetWidth,"targetWidth");
		HX_STACK_LINE(238)
		Float targetHeight = (object->nmeGetHeight() * targetMatrix->deltaTransformPoint(yPoint)->nmeGetLength());		HX_STACK_VAR(targetHeight,"targetHeight");
		HX_STACK_LINE(240)
		::neash::geom::Rectangle currentRect = ::neash::geom::Rectangle_obj::__new(currentMatrix->tx,currentMatrix->ty,currentWidth,currentHeight);		HX_STACK_VAR(currentRect,"currentRect");
		HX_STACK_LINE(241)
		::neash::geom::Rectangle targetRect = ::neash::geom::Rectangle_obj::__new(targetMatrix->tx,targetMatrix->ty,targetWidth,targetHeight);		HX_STACK_VAR(targetRect,"targetRect");
		HX_STACK_LINE(243)
		return currentRect->intersects(targetRect);
	}
	HX_STACK_LINE(246)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,hitTestObject,return )

::neash::geom::Point DisplayObject_obj::globalToLocal( ::neash::geom::Point inGlobal){
	HX_STACK_PUSH("DisplayObject::globalToLocal","neash/display/DisplayObject.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inGlobal,"inGlobal");
	HX_STACK_LINE(219)
	::neash::geom::Point result = inGlobal->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(220)
	::neash::display::DisplayObject_obj::nme_display_object_global_to_local(this->nmeHandle,result);
	HX_STACK_LINE(221)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,globalToLocal,return )

bool DisplayObject_obj::dispatchEvent( ::neash::events::Event event){
	HX_STACK_PUSH("DisplayObject::dispatchEvent","neash/display/DisplayObject.hx",196);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(198)
	bool result = this->nmeDispatchEvent(event);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(200)
	if ((event->nmeGetIsCancelled())){
		HX_STACK_LINE(201)
		return true;
	}
	HX_STACK_LINE(203)
	if (((bool(event->nmeGetBubbles()) && bool((this->nmeGetParent() != null()))))){
		HX_STACK_LINE(204)
		this->nmeGetParent()->dispatchEvent(event);
	}
	HX_STACK_LINE(208)
	return result;
}


Dynamic DisplayObject_obj::nme_create_display_object;

Dynamic DisplayObject_obj::nme_display_object_get_graphics;

Dynamic DisplayObject_obj::nme_display_object_draw_to_surface;

Dynamic DisplayObject_obj::nme_display_object_get_id;

Dynamic DisplayObject_obj::nme_display_object_get_x;

Dynamic DisplayObject_obj::nme_display_object_set_x;

Dynamic DisplayObject_obj::nme_display_object_get_y;

Dynamic DisplayObject_obj::nme_display_object_set_y;

Dynamic DisplayObject_obj::nme_display_object_get_scale_x;

Dynamic DisplayObject_obj::nme_display_object_set_scale_x;

Dynamic DisplayObject_obj::nme_display_object_get_scale_y;

Dynamic DisplayObject_obj::nme_display_object_set_scale_y;

Dynamic DisplayObject_obj::nme_display_object_get_mouse_x;

Dynamic DisplayObject_obj::nme_display_object_get_mouse_y;

Dynamic DisplayObject_obj::nme_display_object_get_rotation;

Dynamic DisplayObject_obj::nme_display_object_set_rotation;

Dynamic DisplayObject_obj::nme_display_object_get_bg;

Dynamic DisplayObject_obj::nme_display_object_set_bg;

Dynamic DisplayObject_obj::nme_display_object_get_name;

Dynamic DisplayObject_obj::nme_display_object_set_name;

Dynamic DisplayObject_obj::nme_display_object_get_width;

Dynamic DisplayObject_obj::nme_display_object_set_width;

Dynamic DisplayObject_obj::nme_display_object_get_height;

Dynamic DisplayObject_obj::nme_display_object_set_height;

Dynamic DisplayObject_obj::nme_display_object_get_alpha;

Dynamic DisplayObject_obj::nme_display_object_set_alpha;

Dynamic DisplayObject_obj::nme_display_object_get_blend_mode;

Dynamic DisplayObject_obj::nme_display_object_set_blend_mode;

Dynamic DisplayObject_obj::nme_display_object_get_cache_as_bitmap;

Dynamic DisplayObject_obj::nme_display_object_set_cache_as_bitmap;

Dynamic DisplayObject_obj::nme_display_object_get_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::nme_display_object_set_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::nme_display_object_get_pixel_snapping;

Dynamic DisplayObject_obj::nme_display_object_set_pixel_snapping;

Dynamic DisplayObject_obj::nme_display_object_get_visible;

Dynamic DisplayObject_obj::nme_display_object_set_visible;

Dynamic DisplayObject_obj::nme_display_object_set_filters;

Dynamic DisplayObject_obj::nme_display_object_global_to_local;

Dynamic DisplayObject_obj::nme_display_object_local_to_global;

Dynamic DisplayObject_obj::nme_display_object_set_scale9_grid;

Dynamic DisplayObject_obj::nme_display_object_set_scroll_rect;

Dynamic DisplayObject_obj::nme_display_object_set_mask;

Dynamic DisplayObject_obj::nme_display_object_set_matrix;

Dynamic DisplayObject_obj::nme_display_object_get_matrix;

Dynamic DisplayObject_obj::nme_display_object_get_color_transform;

Dynamic DisplayObject_obj::nme_display_object_set_color_transform;

Dynamic DisplayObject_obj::nme_display_object_get_pixel_bounds;

Dynamic DisplayObject_obj::nme_display_object_get_bounds;

Dynamic DisplayObject_obj::nme_display_object_hit_test_point;


DisplayObject_obj::DisplayObject_obj()
{
}

void DisplayObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObject);
	HX_MARK_MEMBER_NAME(nmeScrollRect,"nmeScrollRect");
	HX_MARK_MEMBER_NAME(nmeScale9Grid,"nmeScale9Grid");
	HX_MARK_MEMBER_NAME(nmeParent,"nmeParent");
	HX_MARK_MEMBER_NAME(nmeID,"nmeID");
	HX_MARK_MEMBER_NAME(nmeGraphicsCache,"nmeGraphicsCache");
	HX_MARK_MEMBER_NAME(nmeFilters,"nmeFilters");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(scrollRect,"scrollRect");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scale9Grid,"scale9Grid");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(opaqueBackground,"opaqueBackground");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(mask,"mask");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_MEMBER_NAME(filters,"filters");
	HX_MARK_MEMBER_NAME(pixelSnapping,"pixelSnapping");
	HX_MARK_MEMBER_NAME(pedanticBitmapCaching,"pedanticBitmapCaching");
	HX_MARK_MEMBER_NAME(cacheAsBitmap,"cacheAsBitmap");
	HX_MARK_MEMBER_NAME(blendMode,"blendMode");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DisplayObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeScrollRect,"nmeScrollRect");
	HX_VISIT_MEMBER_NAME(nmeScale9Grid,"nmeScale9Grid");
	HX_VISIT_MEMBER_NAME(nmeParent,"nmeParent");
	HX_VISIT_MEMBER_NAME(nmeID,"nmeID");
	HX_VISIT_MEMBER_NAME(nmeGraphicsCache,"nmeGraphicsCache");
	HX_VISIT_MEMBER_NAME(nmeFilters,"nmeFilters");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(stage,"stage");
	HX_VISIT_MEMBER_NAME(scrollRect,"scrollRect");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(scale9Grid,"scale9Grid");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(opaqueBackground,"opaqueBackground");
	HX_VISIT_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(mouseY,"mouseY");
	HX_VISIT_MEMBER_NAME(mouseX,"mouseX");
	HX_VISIT_MEMBER_NAME(mask,"mask");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
	HX_VISIT_MEMBER_NAME(filters,"filters");
	HX_VISIT_MEMBER_NAME(pixelSnapping,"pixelSnapping");
	HX_VISIT_MEMBER_NAME(pedanticBitmapCaching,"pedanticBitmapCaching");
	HX_VISIT_MEMBER_NAME(cacheAsBitmap,"cacheAsBitmap");
	HX_VISIT_MEMBER_NAME(blendMode,"blendMode");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic DisplayObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return inCallProp ? nmeGetY() : y; }
		if (HX_FIELD_EQ(inName,"x") ) { return inCallProp ? nmeGetX() : x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return inCallProp ? nmeGetName() : name; }
		if (HX_FIELD_EQ(inName,"mask") ) { return mask; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nmeID") ) { return nmeID; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? nmeGetWidth() : width; }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? nmeGetStage() : stage; }
		if (HX_FIELD_EQ(inName,"alpha") ) { return inCallProp ? nmeGetAlpha() : alpha; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleY") ) { return inCallProp ? nmeGetScaleY() : scaleY; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return inCallProp ? nmeGetScaleX() : scaleX; }
		if (HX_FIELD_EQ(inName,"parent") ) { return inCallProp ? nmeGetParent() : parent; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return inCallProp ? nmeGetMouseY() : mouseY; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return inCallProp ? nmeGetMouseX() : mouseX; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? nmeGetHeight() : height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nmeSetY") ) { return nmeSetY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetY") ) { return nmeGetY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetX") ) { return nmeSetX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetX") ) { return nmeGetX_dyn(); }
		if (HX_FIELD_EQ(inName,"getRect") ) { return getRect_dyn(); }
		if (HX_FIELD_EQ(inName,"visible") ) { return inCallProp ? nmeGetVisible() : visible; }
		if (HX_FIELD_EQ(inName,"filters") ) { return inCallProp ? nmeGetFilters() : filters; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nmeSetBG") ) { return nmeSetBG_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBG") ) { return nmeGetBG_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? nmeGetRotation() : rotation; }
		if (HX_FIELD_EQ(inName,"graphics") ) { return inCallProp ? nmeGetGraphics() : graphics; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeParent") ) { return nmeParent; }
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? nmeGetTransform() : transform; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"blendMode") ) { return inCallProp ? nmeGetBlendMode() : blendMode; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeSetName") ) { return nmeSetName_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetName") ) { return nmeGetName_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMask") ) { return nmeSetMask_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFilters") ) { return nmeFilters; }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return inCallProp ? nmeGetScrollRect() : scrollRect; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return inCallProp ? nmeGetScale9Grid() : scale9Grid; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeSetWidth") ) { return nmeSetWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetWidth") ) { return nmeGetWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAlpha") ) { return nmeSetAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetAlpha") ) { return nmeGetAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeSetScaleY") ) { return nmeSetScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleY") ) { return nmeGetScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScaleX") ) { return nmeSetScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleX") ) { return nmeGetScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetParent") ) { return nmeSetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetParent") ) { return nmeGetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseY") ) { return nmeGetMouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseX") ) { return nmeGetMouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetHeight") ) { return nmeSetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetHeight") ) { return nmeGetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMatrix") ) { return nmeSetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMatrix") ) { return nmeGetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFireEvent") ) { return nmeFireEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"hitTestPoint") ) { return hitTestPoint_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeSetVisible") ) { return nmeSetVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetVisible") ) { return nmeGetVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFilters") ) { return nmeSetFilters_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetFilters") ) { return nmeGetFilters_dyn(); }
		if (HX_FIELD_EQ(inName,"localToGlobal") ) { return localToGlobal_dyn(); }
		if (HX_FIELD_EQ(inName,"hitTestObject") ) { return hitTestObject_dyn(); }
		if (HX_FIELD_EQ(inName,"globalToLocal") ) { return globalToLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeScrollRect") ) { return nmeScrollRect; }
		if (HX_FIELD_EQ(inName,"nmeScale9Grid") ) { return nmeScale9Grid; }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return inCallProp ? nmeGetPixelSnapping() : pixelSnapping; }
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return inCallProp ? nmeGetCacheAsBitmap() : cacheAsBitmap; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeSetRotation") ) { return nmeSetRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetRotation") ) { return nmeGetRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetGraphics") ) { return nmeGetGraphics_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeSetTransform") ) { return nmeSetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTransform") ) { return nmeGetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBlendMode") ) { return nmeSetBlendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBlendMode") ) { return nmeGetBlendMode_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeSetScrollRect") ) { return nmeSetScrollRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollRect") ) { return nmeGetScrollRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScale9Grid") ) { return nmeSetScale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScale9Grid") ) { return nmeGetScale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeDrawToSurface") ) { return nmeDrawToSurface_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeDispatchEvent") ) { return nmeDispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGraphicsCache") ) { return nmeGraphicsCache; }
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return inCallProp ? nmeGetBG() : opaqueBackground; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetPixelBounds") ) { return nmeGetPixelBounds_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeSetPixelSnapping") ) { return nmeSetPixelSnapping_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetPixelSnapping") ) { return nmeGetPixelSnapping_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetCacheAsBitmap") ) { return nmeSetCacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetCacheAsBitmap") ) { return nmeGetCacheAsBitmap_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeSetColorTransform") ) { return nmeSetColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetColorTransform") ) { return nmeGetColorTransform_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { return inCallProp ? nmeGetPedanticBitmapCaching() : pedanticBitmapCaching; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeAsInteractiveObject") ) { return nmeAsInteractiveObject_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_x") ) { return nme_display_object_get_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_x") ) { return nme_display_object_set_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_y") ) { return nme_display_object_get_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_y") ) { return nme_display_object_set_y; }
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedMatrix") ) { return nmeGetConcatenatedMatrix_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_create_display_object") ) { return nme_create_display_object; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_id") ) { return nme_display_object_get_id; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bg") ) { return nme_display_object_get_bg; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_bg") ) { return nme_display_object_set_bg; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_name") ) { return nme_display_object_get_name; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_name") ) { return nme_display_object_set_name; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mask") ) { return nme_display_object_set_mask; }
		if (HX_FIELD_EQ(inName,"nmeSetPedanticBitmapCaching") ) { return nmeSetPedanticBitmapCaching_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetPedanticBitmapCaching") ) { return nmeGetPedanticBitmapCaching_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_width") ) { return nme_display_object_get_width; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_width") ) { return nme_display_object_set_width; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_alpha") ) { return nme_display_object_get_alpha; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_alpha") ) { return nme_display_object_set_alpha; }
		if (HX_FIELD_EQ(inName,"nmeGetInteractiveObjectStack") ) { return nmeGetInteractiveObjectStack_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_height") ) { return nme_display_object_get_height; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_height") ) { return nme_display_object_set_height; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_matrix") ) { return nme_display_object_set_matrix; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_matrix") ) { return nme_display_object_get_matrix; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bounds") ) { return nme_display_object_get_bounds; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_x") ) { return nme_display_object_get_scale_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_x") ) { return nme_display_object_set_scale_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_y") ) { return nme_display_object_get_scale_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_y") ) { return nme_display_object_set_scale_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_x") ) { return nme_display_object_get_mouse_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_y") ) { return nme_display_object_get_mouse_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_visible") ) { return nme_display_object_get_visible; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_visible") ) { return nme_display_object_set_visible; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_filters") ) { return nme_display_object_set_filters; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_graphics") ) { return nme_display_object_get_graphics; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_rotation") ) { return nme_display_object_get_rotation; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_rotation") ) { return nme_display_object_set_rotation; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedColorTransform") ) { return nmeGetConcatenatedColorTransform_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_blend_mode") ) { return nme_display_object_get_blend_mode; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_blend_mode") ) { return nme_display_object_set_blend_mode; }
		if (HX_FIELD_EQ(inName,"nme_display_object_hit_test_point") ) { return nme_display_object_hit_test_point; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_display_object_draw_to_surface") ) { return nme_display_object_draw_to_surface; }
		if (HX_FIELD_EQ(inName,"nme_display_object_global_to_local") ) { return nme_display_object_global_to_local; }
		if (HX_FIELD_EQ(inName,"nme_display_object_local_to_global") ) { return nme_display_object_local_to_global; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale9_grid") ) { return nme_display_object_set_scale9_grid; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scroll_rect") ) { return nme_display_object_set_scroll_rect; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_bounds") ) { return nme_display_object_get_pixel_bounds; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_snapping") ) { return nme_display_object_get_pixel_snapping; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_pixel_snapping") ) { return nme_display_object_set_pixel_snapping; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_cache_as_bitmap") ) { return nme_display_object_get_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_cache_as_bitmap") ) { return nme_display_object_set_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_color_transform") ) { return nme_display_object_get_color_transform; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_color_transform") ) { return nme_display_object_set_color_transform; }
		break;
	case 46:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pedantic_bitmap_caching") ) { return nme_display_object_get_pedantic_bitmap_caching; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_pedantic_bitmap_caching") ) { return nme_display_object_set_pedantic_bitmap_caching; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { if (inCallProp) return nmeSetY(inValue);y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { if (inCallProp) return nmeSetX(inValue);x=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp) return nmeSetName(inValue);name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mask") ) { if (inCallProp) return nmeSetMask(inValue);mask=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nmeID") ) { nmeID=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return nmeSetWidth(inValue);width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::neash::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return nmeSetAlpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleY") ) { if (inCallProp) return nmeSetScaleY(inValue);scaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { if (inCallProp) return nmeSetScaleX(inValue);scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return nmeSetHeight(inValue);height=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { if (inCallProp) return nmeSetVisible(inValue);visible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"filters") ) { if (inCallProp) return nmeSetFilters(inValue);filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { if (inCallProp) return nmeSetRotation(inValue);rotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeParent") ) { nmeParent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { if (inCallProp) return nmeSetTransform(inValue);transform=inValue.Cast< ::neash::geom::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendMode") ) { if (inCallProp) return nmeSetBlendMode(inValue);blendMode=inValue.Cast< ::neash::display::BlendMode >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeFilters") ) { nmeFilters=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { if (inCallProp) return nmeSetScrollRect(inValue);scrollRect=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { if (inCallProp) return nmeSetScale9Grid(inValue);scale9Grid=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeScrollRect") ) { nmeScrollRect=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeScale9Grid") ) { nmeScale9Grid=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { if (inCallProp) return nmeSetPixelSnapping(inValue);pixelSnapping=inValue.Cast< ::neash::display::PixelSnapping >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { if (inCallProp) return nmeSetCacheAsBitmap(inValue);cacheAsBitmap=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeGraphicsCache") ) { nmeGraphicsCache=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { if (inCallProp) return nmeSetBG(inValue);opaqueBackground=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { if (inCallProp) return nmeSetPedanticBitmapCaching(inValue);pedanticBitmapCaching=inValue.Cast< bool >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_x") ) { nme_display_object_get_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_x") ) { nme_display_object_set_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_y") ) { nme_display_object_get_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_y") ) { nme_display_object_set_y=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_create_display_object") ) { nme_create_display_object=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_id") ) { nme_display_object_get_id=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bg") ) { nme_display_object_get_bg=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_bg") ) { nme_display_object_set_bg=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_name") ) { nme_display_object_get_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_name") ) { nme_display_object_set_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mask") ) { nme_display_object_set_mask=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_width") ) { nme_display_object_get_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_width") ) { nme_display_object_set_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_alpha") ) { nme_display_object_get_alpha=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_alpha") ) { nme_display_object_set_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_height") ) { nme_display_object_get_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_height") ) { nme_display_object_set_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_matrix") ) { nme_display_object_set_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_matrix") ) { nme_display_object_get_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bounds") ) { nme_display_object_get_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_x") ) { nme_display_object_get_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_x") ) { nme_display_object_set_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_y") ) { nme_display_object_get_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_y") ) { nme_display_object_set_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_x") ) { nme_display_object_get_mouse_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_y") ) { nme_display_object_get_mouse_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_visible") ) { nme_display_object_get_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_visible") ) { nme_display_object_set_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_filters") ) { nme_display_object_set_filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_graphics") ) { nme_display_object_get_graphics=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_rotation") ) { nme_display_object_get_rotation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_rotation") ) { nme_display_object_set_rotation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_blend_mode") ) { nme_display_object_get_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_blend_mode") ) { nme_display_object_set_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_hit_test_point") ) { nme_display_object_hit_test_point=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_display_object_draw_to_surface") ) { nme_display_object_draw_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_global_to_local") ) { nme_display_object_global_to_local=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_local_to_global") ) { nme_display_object_local_to_global=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale9_grid") ) { nme_display_object_set_scale9_grid=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scroll_rect") ) { nme_display_object_set_scroll_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_bounds") ) { nme_display_object_get_pixel_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_snapping") ) { nme_display_object_get_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_pixel_snapping") ) { nme_display_object_set_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_cache_as_bitmap") ) { nme_display_object_get_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_cache_as_bitmap") ) { nme_display_object_set_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_color_transform") ) { nme_display_object_get_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_color_transform") ) { nme_display_object_set_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 46:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pedantic_bitmap_caching") ) { nme_display_object_get_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_pedantic_bitmap_caching") ) { nme_display_object_set_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeScrollRect"));
	outFields->push(HX_CSTRING("nmeScale9Grid"));
	outFields->push(HX_CSTRING("nmeParent"));
	outFields->push(HX_CSTRING("nmeID"));
	outFields->push(HX_CSTRING("nmeGraphicsCache"));
	outFields->push(HX_CSTRING("nmeFilters"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("scrollRect"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scale9Grid"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("opaqueBackground"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("graphics"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("pixelSnapping"));
	outFields->push(HX_CSTRING("pedanticBitmapCaching"));
	outFields->push(HX_CSTRING("cacheAsBitmap"));
	outFields->push(HX_CSTRING("blendMode"));
	outFields->push(HX_CSTRING("alpha"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_create_display_object"),
	HX_CSTRING("nme_display_object_get_graphics"),
	HX_CSTRING("nme_display_object_draw_to_surface"),
	HX_CSTRING("nme_display_object_get_id"),
	HX_CSTRING("nme_display_object_get_x"),
	HX_CSTRING("nme_display_object_set_x"),
	HX_CSTRING("nme_display_object_get_y"),
	HX_CSTRING("nme_display_object_set_y"),
	HX_CSTRING("nme_display_object_get_scale_x"),
	HX_CSTRING("nme_display_object_set_scale_x"),
	HX_CSTRING("nme_display_object_get_scale_y"),
	HX_CSTRING("nme_display_object_set_scale_y"),
	HX_CSTRING("nme_display_object_get_mouse_x"),
	HX_CSTRING("nme_display_object_get_mouse_y"),
	HX_CSTRING("nme_display_object_get_rotation"),
	HX_CSTRING("nme_display_object_set_rotation"),
	HX_CSTRING("nme_display_object_get_bg"),
	HX_CSTRING("nme_display_object_set_bg"),
	HX_CSTRING("nme_display_object_get_name"),
	HX_CSTRING("nme_display_object_set_name"),
	HX_CSTRING("nme_display_object_get_width"),
	HX_CSTRING("nme_display_object_set_width"),
	HX_CSTRING("nme_display_object_get_height"),
	HX_CSTRING("nme_display_object_set_height"),
	HX_CSTRING("nme_display_object_get_alpha"),
	HX_CSTRING("nme_display_object_set_alpha"),
	HX_CSTRING("nme_display_object_get_blend_mode"),
	HX_CSTRING("nme_display_object_set_blend_mode"),
	HX_CSTRING("nme_display_object_get_cache_as_bitmap"),
	HX_CSTRING("nme_display_object_set_cache_as_bitmap"),
	HX_CSTRING("nme_display_object_get_pedantic_bitmap_caching"),
	HX_CSTRING("nme_display_object_set_pedantic_bitmap_caching"),
	HX_CSTRING("nme_display_object_get_pixel_snapping"),
	HX_CSTRING("nme_display_object_set_pixel_snapping"),
	HX_CSTRING("nme_display_object_get_visible"),
	HX_CSTRING("nme_display_object_set_visible"),
	HX_CSTRING("nme_display_object_set_filters"),
	HX_CSTRING("nme_display_object_global_to_local"),
	HX_CSTRING("nme_display_object_local_to_global"),
	HX_CSTRING("nme_display_object_set_scale9_grid"),
	HX_CSTRING("nme_display_object_set_scroll_rect"),
	HX_CSTRING("nme_display_object_set_mask"),
	HX_CSTRING("nme_display_object_set_matrix"),
	HX_CSTRING("nme_display_object_get_matrix"),
	HX_CSTRING("nme_display_object_get_color_transform"),
	HX_CSTRING("nme_display_object_set_color_transform"),
	HX_CSTRING("nme_display_object_get_pixel_bounds"),
	HX_CSTRING("nme_display_object_get_bounds"),
	HX_CSTRING("nme_display_object_hit_test_point"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetY"),
	HX_CSTRING("nmeGetY"),
	HX_CSTRING("nmeSetX"),
	HX_CSTRING("nmeGetX"),
	HX_CSTRING("nmeSetWidth"),
	HX_CSTRING("nmeGetWidth"),
	HX_CSTRING("nmeSetVisible"),
	HX_CSTRING("nmeGetVisible"),
	HX_CSTRING("nmeSetTransform"),
	HX_CSTRING("nmeGetTransform"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("nmeSetScrollRect"),
	HX_CSTRING("nmeGetScrollRect"),
	HX_CSTRING("nmeSetScaleY"),
	HX_CSTRING("nmeGetScaleY"),
	HX_CSTRING("nmeSetScaleX"),
	HX_CSTRING("nmeGetScaleX"),
	HX_CSTRING("nmeSetScale9Grid"),
	HX_CSTRING("nmeGetScale9Grid"),
	HX_CSTRING("nmeSetRotation"),
	HX_CSTRING("nmeGetRotation"),
	HX_CSTRING("nmeSetParent"),
	HX_CSTRING("nmeGetParent"),
	HX_CSTRING("nmeSetName"),
	HX_CSTRING("nmeGetName"),
	HX_CSTRING("nmeGetMouseY"),
	HX_CSTRING("nmeGetMouseX"),
	HX_CSTRING("nmeSetMask"),
	HX_CSTRING("nmeSetHeight"),
	HX_CSTRING("nmeGetHeight"),
	HX_CSTRING("nmeGetGraphics"),
	HX_CSTRING("nmeSetFilters"),
	HX_CSTRING("nmeGetFilters"),
	HX_CSTRING("nmeSetPixelSnapping"),
	HX_CSTRING("nmeGetPixelSnapping"),
	HX_CSTRING("nmeSetPedanticBitmapCaching"),
	HX_CSTRING("nmeGetPedanticBitmapCaching"),
	HX_CSTRING("nmeSetCacheAsBitmap"),
	HX_CSTRING("nmeGetCacheAsBitmap"),
	HX_CSTRING("nmeSetBlendMode"),
	HX_CSTRING("nmeGetBlendMode"),
	HX_CSTRING("nmeSetBG"),
	HX_CSTRING("nmeGetBG"),
	HX_CSTRING("nmeSetAlpha"),
	HX_CSTRING("nmeGetAlpha"),
	HX_CSTRING("toString"),
	HX_CSTRING("nmeSetMatrix"),
	HX_CSTRING("nmeSetColorTransform"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeGetPixelBounds"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("nmeGetMatrix"),
	HX_CSTRING("nmeGetInteractiveObjectStack"),
	HX_CSTRING("nmeGetConcatenatedMatrix"),
	HX_CSTRING("nmeGetConcatenatedColorTransform"),
	HX_CSTRING("nmeGetColorTransform"),
	HX_CSTRING("nmeFireEvent"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeDrawToSurface"),
	HX_CSTRING("nmeDispatchEvent"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeAsInteractiveObject"),
	HX_CSTRING("localToGlobal"),
	HX_CSTRING("getRect"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("hitTestPoint"),
	HX_CSTRING("hitTestObject"),
	HX_CSTRING("globalToLocal"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("nmeScrollRect"),
	HX_CSTRING("nmeScale9Grid"),
	HX_CSTRING("nmeParent"),
	HX_CSTRING("nmeID"),
	HX_CSTRING("nmeGraphicsCache"),
	HX_CSTRING("nmeFilters"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("width"),
	HX_CSTRING("visible"),
	HX_CSTRING("transform"),
	HX_CSTRING("stage"),
	HX_CSTRING("scrollRect"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scale9Grid"),
	HX_CSTRING("rotation"),
	HX_CSTRING("parent"),
	HX_CSTRING("opaqueBackground"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("name"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("mask"),
	HX_CSTRING("height"),
	HX_CSTRING("graphics"),
	HX_CSTRING("filters"),
	HX_CSTRING("pixelSnapping"),
	HX_CSTRING("pedanticBitmapCaching"),
	HX_CSTRING("cacheAsBitmap"),
	HX_CSTRING("blendMode"),
	HX_CSTRING("alpha"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_create_display_object,"nme_create_display_object");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_graphics,"nme_display_object_get_graphics");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_draw_to_surface,"nme_display_object_draw_to_surface");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_id,"nme_display_object_get_id");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_x,"nme_display_object_get_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_x,"nme_display_object_set_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_y,"nme_display_object_get_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_y,"nme_display_object_set_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_x,"nme_display_object_get_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_x,"nme_display_object_set_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_y,"nme_display_object_get_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_y,"nme_display_object_set_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_x,"nme_display_object_get_mouse_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_y,"nme_display_object_get_mouse_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_rotation,"nme_display_object_get_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_rotation,"nme_display_object_set_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_bg,"nme_display_object_get_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_bg,"nme_display_object_set_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_name,"nme_display_object_get_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_name,"nme_display_object_set_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_width,"nme_display_object_get_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_width,"nme_display_object_set_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_height,"nme_display_object_get_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_height,"nme_display_object_set_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_alpha,"nme_display_object_get_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_alpha,"nme_display_object_set_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_blend_mode,"nme_display_object_get_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_blend_mode,"nme_display_object_set_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_cache_as_bitmap,"nme_display_object_get_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_cache_as_bitmap,"nme_display_object_set_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pedantic_bitmap_caching,"nme_display_object_get_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_pedantic_bitmap_caching,"nme_display_object_set_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pixel_snapping,"nme_display_object_get_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_pixel_snapping,"nme_display_object_set_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_visible,"nme_display_object_get_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_visible,"nme_display_object_set_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_filters,"nme_display_object_set_filters");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_global_to_local,"nme_display_object_global_to_local");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_local_to_global,"nme_display_object_local_to_global");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale9_grid,"nme_display_object_set_scale9_grid");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scroll_rect,"nme_display_object_set_scroll_rect");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_mask,"nme_display_object_set_mask");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_matrix,"nme_display_object_set_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_matrix,"nme_display_object_get_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_color_transform,"nme_display_object_get_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_color_transform,"nme_display_object_set_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pixel_bounds,"nme_display_object_get_pixel_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_bounds,"nme_display_object_get_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_hit_test_point,"nme_display_object_hit_test_point");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_create_display_object,"nme_create_display_object");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_graphics,"nme_display_object_get_graphics");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_draw_to_surface,"nme_display_object_draw_to_surface");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_id,"nme_display_object_get_id");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_x,"nme_display_object_get_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_x,"nme_display_object_set_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_y,"nme_display_object_get_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_y,"nme_display_object_set_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_x,"nme_display_object_get_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_x,"nme_display_object_set_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_y,"nme_display_object_get_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_y,"nme_display_object_set_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_x,"nme_display_object_get_mouse_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_y,"nme_display_object_get_mouse_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_rotation,"nme_display_object_get_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_rotation,"nme_display_object_set_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_bg,"nme_display_object_get_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_bg,"nme_display_object_set_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_name,"nme_display_object_get_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_name,"nme_display_object_set_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_width,"nme_display_object_get_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_width,"nme_display_object_set_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_height,"nme_display_object_get_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_height,"nme_display_object_set_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_alpha,"nme_display_object_get_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_alpha,"nme_display_object_set_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_blend_mode,"nme_display_object_get_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_blend_mode,"nme_display_object_set_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_cache_as_bitmap,"nme_display_object_get_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_cache_as_bitmap,"nme_display_object_set_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pedantic_bitmap_caching,"nme_display_object_get_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_pedantic_bitmap_caching,"nme_display_object_set_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pixel_snapping,"nme_display_object_get_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_pixel_snapping,"nme_display_object_set_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_visible,"nme_display_object_get_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_visible,"nme_display_object_set_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_filters,"nme_display_object_set_filters");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_global_to_local,"nme_display_object_global_to_local");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_local_to_global,"nme_display_object_local_to_global");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale9_grid,"nme_display_object_set_scale9_grid");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scroll_rect,"nme_display_object_set_scroll_rect");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_mask,"nme_display_object_set_mask");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_matrix,"nme_display_object_set_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_matrix,"nme_display_object_get_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_color_transform,"nme_display_object_get_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_color_transform,"nme_display_object_set_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pixel_bounds,"nme_display_object_get_pixel_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_bounds,"nme_display_object_get_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::nme_display_object_hit_test_point,"nme_display_object_hit_test_point");
};

Class DisplayObject_obj::__mClass;

void DisplayObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.DisplayObject"), hx::TCanCast< DisplayObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DisplayObject_obj::__boot()
{
	nme_create_display_object= ::neash::Loader_obj::load(HX_CSTRING("nme_create_display_object"),(int)0);
	nme_display_object_get_graphics= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_graphics"),(int)1);
	nme_display_object_draw_to_surface= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_draw_to_surface"),(int)-1);
	nme_display_object_get_id= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_id"),(int)1);
	nme_display_object_get_x= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_x"),(int)1);
	nme_display_object_set_x= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_x"),(int)2);
	nme_display_object_get_y= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_y"),(int)1);
	nme_display_object_set_y= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_y"),(int)2);
	nme_display_object_get_scale_x= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_scale_x"),(int)1);
	nme_display_object_set_scale_x= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale_x"),(int)2);
	nme_display_object_get_scale_y= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_scale_y"),(int)1);
	nme_display_object_set_scale_y= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale_y"),(int)2);
	nme_display_object_get_mouse_x= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_mouse_x"),(int)1);
	nme_display_object_get_mouse_y= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_mouse_y"),(int)1);
	nme_display_object_get_rotation= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_rotation"),(int)1);
	nme_display_object_set_rotation= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_rotation"),(int)2);
	nme_display_object_get_bg= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_bg"),(int)1);
	nme_display_object_set_bg= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_bg"),(int)2);
	nme_display_object_get_name= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_name"),(int)1);
	nme_display_object_set_name= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_name"),(int)2);
	nme_display_object_get_width= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_width"),(int)1);
	nme_display_object_set_width= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_width"),(int)2);
	nme_display_object_get_height= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_height"),(int)1);
	nme_display_object_set_height= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_height"),(int)2);
	nme_display_object_get_alpha= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_alpha"),(int)1);
	nme_display_object_set_alpha= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_alpha"),(int)2);
	nme_display_object_get_blend_mode= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_blend_mode"),(int)1);
	nme_display_object_set_blend_mode= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_blend_mode"),(int)2);
	nme_display_object_get_cache_as_bitmap= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_cache_as_bitmap"),(int)1);
	nme_display_object_set_cache_as_bitmap= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_cache_as_bitmap"),(int)2);
	nme_display_object_get_pedantic_bitmap_caching= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_pedantic_bitmap_caching"),(int)1);
	nme_display_object_set_pedantic_bitmap_caching= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_pedantic_bitmap_caching"),(int)2);
	nme_display_object_get_pixel_snapping= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_pixel_snapping"),(int)1);
	nme_display_object_set_pixel_snapping= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_pixel_snapping"),(int)2);
	nme_display_object_get_visible= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_visible"),(int)1);
	nme_display_object_set_visible= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_visible"),(int)2);
	nme_display_object_set_filters= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_filters"),(int)2);
	nme_display_object_global_to_local= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_global_to_local"),(int)2);
	nme_display_object_local_to_global= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_local_to_global"),(int)2);
	nme_display_object_set_scale9_grid= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale9_grid"),(int)2);
	nme_display_object_set_scroll_rect= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scroll_rect"),(int)2);
	nme_display_object_set_mask= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_mask"),(int)2);
	nme_display_object_set_matrix= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_matrix"),(int)2);
	nme_display_object_get_matrix= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_matrix"),(int)3);
	nme_display_object_get_color_transform= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_color_transform"),(int)3);
	nme_display_object_set_color_transform= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_color_transform"),(int)2);
	nme_display_object_get_pixel_bounds= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_pixel_bounds"),(int)2);
	nme_display_object_get_bounds= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_bounds"),(int)4);
	nme_display_object_hit_test_point= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_hit_test_point"),(int)5);
}

} // end namespace neash
} // end namespace display
