#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl
#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace cocktail{
namespace core{
namespace graphics{

Void AbstractGraphicsContextImpl_obj::__construct()
{
HX_STACK_PUSH("AbstractGraphicsContextImpl::new","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",75);
{
	HX_STACK_LINE(76)
	this->_useTransparency = false;
	HX_STACK_LINE(77)
	this->_useTransformations = false;
	HX_STACK_LINE(78)
	this->_alpha = 0.0;
}
;
	return null();
}

AbstractGraphicsContextImpl_obj::~AbstractGraphicsContextImpl_obj() { }

Dynamic AbstractGraphicsContextImpl_obj::__CreateEmpty() { return  new AbstractGraphicsContextImpl_obj; }
hx::ObjectPtr< AbstractGraphicsContextImpl_obj > AbstractGraphicsContextImpl_obj::__new()
{  hx::ObjectPtr< AbstractGraphicsContextImpl_obj > result = new AbstractGraphicsContextImpl_obj();
	result->__construct();
	return result;}

Dynamic AbstractGraphicsContextImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractGraphicsContextImpl_obj > result = new AbstractGraphicsContextImpl_obj();
	result->__construct();
	return result;}

::native::display::DisplayObjectContainer AbstractGraphicsContextImpl_obj::get_nativeLayer( ){
	HX_STACK_PUSH("AbstractGraphicsContextImpl::get_nativeLayer","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",261);
	HX_STACK_THIS(this);
	HX_STACK_LINE(261)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,get_nativeLayer,return )

::native::display::BitmapData AbstractGraphicsContextImpl_obj::get_nativeBitmapData( ){
	HX_STACK_PUSH("AbstractGraphicsContextImpl::get_nativeBitmapData","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",256);
	HX_STACK_THIS(this);
	HX_STACK_LINE(256)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,get_nativeBitmapData,return )

Void AbstractGraphicsContextImpl_obj::fillRect( ::cocktail::core::geom::RectangleVO rect,::cocktail::core::css::ColorVO color,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::fillRect","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",247);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(color,"color");
		HX_STACK_ARG(clipRect,"clipRect");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractGraphicsContextImpl_obj,fillRect,(void))

Void AbstractGraphicsContextImpl_obj::copyPixels( ::native::display::BitmapData bitmapData,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::PointVO destPoint,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::copyPixels","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",235);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bitmapData,"bitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(clipRect,"clipRect");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractGraphicsContextImpl_obj,copyPixels,(void))

Void AbstractGraphicsContextImpl_obj::drawImage( ::native::display::BitmapData bitmapData,::cocktail::core::geom::Matrix matrix,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::drawImage","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",221);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bitmapData,"bitmapData");
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(clipRect,"clipRect");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractGraphicsContextImpl_obj,drawImage,(void))

Void AbstractGraphicsContextImpl_obj::endTransformations( ){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::endTransformations","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",204);
		HX_STACK_THIS(this);
		HX_STACK_LINE(205)
		this->_matrix = null();
		HX_STACK_LINE(206)
		this->_useTransformations = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,endTransformations,(void))

Void AbstractGraphicsContextImpl_obj::beginTransformations( ::cocktail::core::geom::Matrix matrix){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::beginTransformations","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",194);
		HX_STACK_THIS(this);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_LINE(195)
		this->_useTransformations = true;
		HX_STACK_LINE(196)
		this->_matrix = matrix;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractGraphicsContextImpl_obj,beginTransformations,(void))

Void AbstractGraphicsContextImpl_obj::endTransparency( ){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::endTransparency","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",184);
		HX_STACK_THIS(this);
		HX_STACK_LINE(184)
		this->_useTransparency = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,endTransparency,(void))

Void AbstractGraphicsContextImpl_obj::copyRect( ::cocktail::core::geom::RectangleVO rect,Float x,Float y){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::copyRect","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractGraphicsContextImpl_obj,copyRect,(void))

Void AbstractGraphicsContextImpl_obj::beginTransparency( Float alpha){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::beginTransparency","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_ARG(alpha,"alpha");
		HX_STACK_LINE(166)
		this->_useTransparency = true;
		HX_STACK_LINE(167)
		this->_alpha = alpha;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractGraphicsContextImpl_obj,beginTransparency,(void))

Void AbstractGraphicsContextImpl_obj::clear( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::clear","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractGraphicsContextImpl_obj,clear,(void))

Void AbstractGraphicsContextImpl_obj::transform( ::cocktail::core::geom::Matrix matrix){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::transform","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_ARG(matrix,"matrix");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractGraphicsContextImpl_obj,transform,(void))

Void AbstractGraphicsContextImpl_obj::dispose( ){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::dispose","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",138);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,dispose,(void))

Void AbstractGraphicsContextImpl_obj::detachFromRoot( ){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::detachFromRoot","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",129);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractGraphicsContextImpl_obj,detachFromRoot,(void))

Void AbstractGraphicsContextImpl_obj::attachToRoot( ::native::display::DisplayObjectContainer rootLayer){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::attachToRoot","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayer,"rootLayer");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractGraphicsContextImpl_obj,attachToRoot,(void))

Void AbstractGraphicsContextImpl_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::detach","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractGraphicsContextImpl_obj,detach,(void))

Void AbstractGraphicsContextImpl_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicsContext,int index){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::attach","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_ARG(index,"index");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractGraphicsContextImpl_obj,attach,(void))

Void AbstractGraphicsContextImpl_obj::initBitmapData( int width,int height){
{
		HX_STACK_PUSH("AbstractGraphicsContextImpl::initBitmapData","cocktail/core/graphics/AbstractGraphicsContextImpl.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractGraphicsContextImpl_obj,initBitmapData,(void))


AbstractGraphicsContextImpl_obj::AbstractGraphicsContextImpl_obj()
{
}

void AbstractGraphicsContextImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractGraphicsContextImpl);
	HX_MARK_MEMBER_NAME(_matrix,"_matrix");
	HX_MARK_MEMBER_NAME(_useTransformations,"_useTransformations");
	HX_MARK_MEMBER_NAME(_alpha,"_alpha");
	HX_MARK_MEMBER_NAME(_useTransparency,"_useTransparency");
	HX_MARK_MEMBER_NAME(nativeBitmapData,"nativeBitmapData");
	HX_MARK_MEMBER_NAME(nativeLayer,"nativeLayer");
	HX_MARK_END_CLASS();
}

void AbstractGraphicsContextImpl_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_matrix,"_matrix");
	HX_VISIT_MEMBER_NAME(_useTransformations,"_useTransformations");
	HX_VISIT_MEMBER_NAME(_alpha,"_alpha");
	HX_VISIT_MEMBER_NAME(_useTransparency,"_useTransparency");
	HX_VISIT_MEMBER_NAME(nativeBitmapData,"nativeBitmapData");
	HX_VISIT_MEMBER_NAME(nativeLayer,"nativeLayer");
}

Dynamic AbstractGraphicsContextImpl_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"_alpha") ) { return _alpha; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_matrix") ) { return _matrix; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fillRect") ) { return fillRect_dyn(); }
		if (HX_FIELD_EQ(inName,"copyRect") ) { return copyRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawImage") ) { return drawImage_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"copyPixels") ) { return copyPixels_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nativeLayer") ) { return inCallProp ? get_nativeLayer() : nativeLayer; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"attachToRoot") ) { return attachToRoot_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"detachFromRoot") ) { return detachFromRoot_dyn(); }
		if (HX_FIELD_EQ(inName,"initBitmapData") ) { return initBitmapData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_nativeLayer") ) { return get_nativeLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"endTransparency") ) { return endTransparency_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_useTransparency") ) { return _useTransparency; }
		if (HX_FIELD_EQ(inName,"nativeBitmapData") ) { return inCallProp ? get_nativeBitmapData() : nativeBitmapData; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"beginTransparency") ) { return beginTransparency_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"endTransformations") ) { return endTransformations_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_useTransformations") ) { return _useTransformations; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_nativeBitmapData") ) { return get_nativeBitmapData_dyn(); }
		if (HX_FIELD_EQ(inName,"beginTransformations") ) { return beginTransformations_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AbstractGraphicsContextImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_alpha") ) { _alpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_matrix") ) { _matrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nativeLayer") ) { nativeLayer=inValue.Cast< ::native::display::DisplayObjectContainer >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_useTransparency") ) { _useTransparency=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nativeBitmapData") ) { nativeBitmapData=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_useTransformations") ) { _useTransformations=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AbstractGraphicsContextImpl_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_matrix"));
	outFields->push(HX_CSTRING("_useTransformations"));
	outFields->push(HX_CSTRING("_alpha"));
	outFields->push(HX_CSTRING("_useTransparency"));
	outFields->push(HX_CSTRING("nativeBitmapData"));
	outFields->push(HX_CSTRING("nativeLayer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_nativeLayer"),
	HX_CSTRING("get_nativeBitmapData"),
	HX_CSTRING("fillRect"),
	HX_CSTRING("copyPixels"),
	HX_CSTRING("drawImage"),
	HX_CSTRING("endTransformations"),
	HX_CSTRING("beginTransformations"),
	HX_CSTRING("endTransparency"),
	HX_CSTRING("copyRect"),
	HX_CSTRING("beginTransparency"),
	HX_CSTRING("clear"),
	HX_CSTRING("transform"),
	HX_CSTRING("dispose"),
	HX_CSTRING("detachFromRoot"),
	HX_CSTRING("attachToRoot"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("initBitmapData"),
	HX_CSTRING("_matrix"),
	HX_CSTRING("_useTransformations"),
	HX_CSTRING("_alpha"),
	HX_CSTRING("_useTransparency"),
	HX_CSTRING("nativeBitmapData"),
	HX_CSTRING("nativeLayer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractGraphicsContextImpl_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AbstractGraphicsContextImpl_obj::__mClass,"__mClass");
};

Class AbstractGraphicsContextImpl_obj::__mClass;

void AbstractGraphicsContextImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.graphics.AbstractGraphicsContextImpl"), hx::TCanCast< AbstractGraphicsContextImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AbstractGraphicsContextImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace graphics
