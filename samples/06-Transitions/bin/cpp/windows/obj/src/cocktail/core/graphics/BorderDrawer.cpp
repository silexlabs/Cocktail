#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl
#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_BorderDrawer
#include <cocktail/core/graphics/BorderDrawer.h>
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
#ifndef INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl
#include <cocktail/port/platform/flash_player/GraphicsContextImpl.h>
#endif
namespace cocktail{
namespace core{
namespace graphics{

Void BorderDrawer_obj::__construct()
{
HX_STACK_PUSH("BorderDrawer::new","cocktail/core/graphics/BorderDrawer.hx",36);
{
}
;
	return null();
}

BorderDrawer_obj::~BorderDrawer_obj() { }

Dynamic BorderDrawer_obj::__CreateEmpty() { return  new BorderDrawer_obj; }
hx::ObjectPtr< BorderDrawer_obj > BorderDrawer_obj::__new()
{  hx::ObjectPtr< BorderDrawer_obj > result = new BorderDrawer_obj();
	result->__construct();
	return result;}

Dynamic BorderDrawer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BorderDrawer_obj > result = new BorderDrawer_obj();
	result->__construct();
	return result;}

::cocktail::core::geom::RectangleVO BorderDrawer_obj::_currentBorderBox;

Void BorderDrawer_obj::draw( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO borderBox,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BorderDrawer::draw","cocktail/core/graphics/BorderDrawer.hx",58);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(borderBox,"borderBox");
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(59)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getTopBorderBox(borderBox,style->usedValues->borderTopWidth),style->usedValues->borderTopColor,style->getKeyword(style->getComputedOrInitialProperty((int)72)),clipRect);
		HX_STACK_LINE(60)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getLeftBorderBox(borderBox,style->usedValues->borderLeftWidth),style->usedValues->borderLeftColor,style->getKeyword(style->getComputedOrInitialProperty((int)75)),clipRect);
		HX_STACK_LINE(61)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getRightBorderBox(borderBox,style->usedValues->borderRightWidth),style->usedValues->borderRightColor,style->getKeyword(style->getComputedOrInitialProperty((int)73)),clipRect);
		HX_STACK_LINE(62)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getBottomBorderBox(borderBox,style->usedValues->borderBottomWidth),style->usedValues->borderBottomColor,style->getKeyword(style->getComputedOrInitialProperty((int)74)),clipRect);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BorderDrawer_obj,draw,(void))

Void BorderDrawer_obj::drawOutline( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO outlineBox,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BorderDrawer::drawOutline","cocktail/core/graphics/BorderDrawer.hx",79);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(outlineBox,"outlineBox");
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(80)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getTopBorderBox(outlineBox,style->usedValues->outlineWidth),style->usedValues->outlineColor,style->getKeyword(style->getComputedOrInitialProperty((int)83)),clipRect);
		HX_STACK_LINE(81)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getLeftBorderBox(outlineBox,style->usedValues->outlineWidth),style->usedValues->outlineColor,style->getKeyword(style->getComputedOrInitialProperty((int)83)),clipRect);
		HX_STACK_LINE(82)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getRightBorderBox(outlineBox,style->usedValues->outlineWidth),style->usedValues->outlineColor,style->getKeyword(style->getComputedOrInitialProperty((int)83)),clipRect);
		HX_STACK_LINE(83)
		::cocktail::core::graphics::BorderDrawer_obj::drawBorder(graphicContext,::cocktail::core::graphics::BorderDrawer_obj::getBottomBorderBox(outlineBox,style->usedValues->outlineWidth),style->usedValues->outlineColor,style->getKeyword(style->getComputedOrInitialProperty((int)83)),clipRect);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BorderDrawer_obj,drawOutline,(void))

Void BorderDrawer_obj::drawBorder( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO borderBox,::cocktail::core::css::ColorVO borderColor,::cocktail::core::css::CSSKeywordValue borderStyle,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BorderDrawer::drawBorder","cocktail/core/graphics/BorderDrawer.hx",106);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(borderBox,"borderBox");
		HX_STACK_ARG(borderColor,"borderColor");
		HX_STACK_ARG(borderStyle,"borderStyle");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(108)
		if (((bool((::Math_obj::round(borderBox->width) <= (int)0)) || bool((::Math_obj::round(borderBox->height) <= (int)0))))){
			HX_STACK_LINE(109)
			return null();
		}
		HX_STACK_LINE(113)
		graphicContext->graphics->fillRect(borderBox,borderColor,clipRect);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BorderDrawer_obj,drawBorder,(void))

::cocktail::core::geom::RectangleVO BorderDrawer_obj::getTopBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth){
	HX_STACK_PUSH("BorderDrawer::getTopBorderBox","cocktail/core/graphics/BorderDrawer.hx",126);
	HX_STACK_ARG(borderBox,"borderBox");
	HX_STACK_ARG(borderWidth,"borderWidth");
	HX_STACK_LINE(127)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->x = borderBox->x;
	HX_STACK_LINE(128)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->y = borderBox->y;
	HX_STACK_LINE(129)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->width = borderBox->width;
	HX_STACK_LINE(130)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->height = borderWidth;
	HX_STACK_LINE(132)
	return ::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BorderDrawer_obj,getTopBorderBox,return )

::cocktail::core::geom::RectangleVO BorderDrawer_obj::getBottomBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth){
	HX_STACK_PUSH("BorderDrawer::getBottomBorderBox","cocktail/core/graphics/BorderDrawer.hx",139);
	HX_STACK_ARG(borderBox,"borderBox");
	HX_STACK_ARG(borderWidth,"borderWidth");
	HX_STACK_LINE(140)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->x = borderBox->x;
	HX_STACK_LINE(141)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->y = ((borderBox->y + borderBox->height) - borderWidth);
	HX_STACK_LINE(142)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->width = borderBox->width;
	HX_STACK_LINE(143)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->height = borderWidth;
	HX_STACK_LINE(145)
	return ::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BorderDrawer_obj,getBottomBorderBox,return )

::cocktail::core::geom::RectangleVO BorderDrawer_obj::getLeftBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth){
	HX_STACK_PUSH("BorderDrawer::getLeftBorderBox","cocktail/core/graphics/BorderDrawer.hx",152);
	HX_STACK_ARG(borderBox,"borderBox");
	HX_STACK_ARG(borderWidth,"borderWidth");
	HX_STACK_LINE(153)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->x = borderBox->x;
	HX_STACK_LINE(154)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->y = borderBox->y;
	HX_STACK_LINE(155)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->width = borderWidth;
	HX_STACK_LINE(156)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->height = borderBox->height;
	HX_STACK_LINE(158)
	return ::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BorderDrawer_obj,getLeftBorderBox,return )

::cocktail::core::geom::RectangleVO BorderDrawer_obj::getRightBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth){
	HX_STACK_PUSH("BorderDrawer::getRightBorderBox","cocktail/core/graphics/BorderDrawer.hx",165);
	HX_STACK_ARG(borderBox,"borderBox");
	HX_STACK_ARG(borderWidth,"borderWidth");
	HX_STACK_LINE(166)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->x = ((borderBox->x + borderBox->width) - borderWidth);
	HX_STACK_LINE(167)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->y = borderBox->y;
	HX_STACK_LINE(168)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->width = borderWidth;
	HX_STACK_LINE(169)
	::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox->height = borderBox->height;
	HX_STACK_LINE(171)
	return ::cocktail::core::graphics::BorderDrawer_obj::_currentBorderBox;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BorderDrawer_obj,getRightBorderBox,return )


BorderDrawer_obj::BorderDrawer_obj()
{
}

void BorderDrawer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BorderDrawer);
	HX_MARK_END_CLASS();
}

void BorderDrawer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BorderDrawer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawBorder") ) { return drawBorder_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"drawOutline") ) { return drawOutline_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getTopBorderBox") ) { return getTopBorderBox_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getLeftBorderBox") ) { return getLeftBorderBox_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_currentBorderBox") ) { return _currentBorderBox; }
		if (HX_FIELD_EQ(inName,"getRightBorderBox") ) { return getRightBorderBox_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getBottomBorderBox") ) { return getBottomBorderBox_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BorderDrawer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"_currentBorderBox") ) { _currentBorderBox=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BorderDrawer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_currentBorderBox"),
	HX_CSTRING("draw"),
	HX_CSTRING("drawOutline"),
	HX_CSTRING("drawBorder"),
	HX_CSTRING("getTopBorderBox"),
	HX_CSTRING("getBottomBorderBox"),
	HX_CSTRING("getLeftBorderBox"),
	HX_CSTRING("getRightBorderBox"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BorderDrawer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BorderDrawer_obj::_currentBorderBox,"_currentBorderBox");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BorderDrawer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BorderDrawer_obj::_currentBorderBox,"_currentBorderBox");
};

Class BorderDrawer_obj::__mClass;

void BorderDrawer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.graphics.BorderDrawer"), hx::TCanCast< BorderDrawer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BorderDrawer_obj::__boot()
{
	_currentBorderBox= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace graphics
