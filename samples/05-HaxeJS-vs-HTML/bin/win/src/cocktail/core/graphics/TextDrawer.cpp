#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
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
#ifndef INCLUDED_cocktail_core_graphics_TextDrawer
#include <cocktail/core/graphics/TextDrawer.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_LineBox
#include <cocktail/core/linebox/LineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_TextInlineBox
#include <cocktail/core/linebox/TextInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
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
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace core{
namespace graphics{

Void TextDrawer_obj::__construct()
{
HX_STACK_PUSH("TextDrawer::new","cocktail/core/graphics/TextDrawer.hx",49);
{
}
;
	return null();
}

TextDrawer_obj::~TextDrawer_obj() { }

Dynamic TextDrawer_obj::__CreateEmpty() { return  new TextDrawer_obj; }
hx::ObjectPtr< TextDrawer_obj > TextDrawer_obj::__new()
{  hx::ObjectPtr< TextDrawer_obj > result = new TextDrawer_obj();
	result->__construct();
	return result;}

Dynamic TextDrawer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextDrawer_obj > result = new TextDrawer_obj();
	result->__construct();
	return result;}

::cocktail::core::geom::PointVO TextDrawer_obj::_destPoint;

::cocktail::core::geom::RectangleVO TextDrawer_obj::_renderRect;

::cocktail::core::geom::RectangleVO TextDrawer_obj::_decorationRect;

Float TextDrawer_obj::TEXT_DECORATION_THICKNESS;

Void TextDrawer_obj::draw( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::renderer::ElementRenderer elementRenderer,bool hasUnderline,bool hasOverline,bool hasLineThrough,bool hasBlink,::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("TextDrawer::draw","cocktail/core/graphics/TextDrawer.hx",72);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(hasUnderline,"hasUnderline");
		HX_STACK_ARG(hasOverline,"hasOverline");
		HX_STACK_ARG(hasLineThrough,"hasLineThrough");
		HX_STACK_ARG(hasBlink,"hasBlink");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(74)
		int inlineBoxesLength = elementRenderer->inlineBoxes->length;		HX_STACK_VAR(inlineBoxesLength,"inlineBoxesLength");
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			while(((_g < inlineBoxesLength))){
				HX_STACK_LINE(75)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(77)
				::cocktail::core::linebox::InlineBox inlineBox = elementRenderer->inlineBoxes->__get(i);		HX_STACK_VAR(inlineBox,"inlineBox");
				HX_STACK_LINE(80)
				::cocktail::core::graphics::TextDrawer_obj::_renderRect->width = inlineBox->bounds->width;
				HX_STACK_LINE(81)
				::cocktail::core::graphics::TextDrawer_obj::_renderRect->height = inlineBox->bounds->height;
				HX_STACK_LINE(82)
				::cocktail::core::graphics::TextDrawer_obj::_destPoint->x = ((inlineBox->bounds->x + elementRenderer->globalBounds->x) - scrollOffset->x);
				HX_STACK_LINE(83)
				::cocktail::core::graphics::TextDrawer_obj::_destPoint->y = ((inlineBox->bounds->y + elementRenderer->globalBounds->y) - scrollOffset->y);
				HX_STACK_LINE(87)
				if (((inlineBox->lineBox != null()))){
					HX_STACK_LINE(89)
					hx::AddEq(::cocktail::core::graphics::TextDrawer_obj::_destPoint->y,inlineBox->lineBox->bounds->y);
					HX_STACK_LINE(90)
					hx::AddEq(::cocktail::core::graphics::TextDrawer_obj::_destPoint->x,inlineBox->lineBox->bounds->x);
				}
				HX_STACK_LINE(94)
				if (((hasUnderline == true))){
					HX_STACK_LINE(96)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->width = ::cocktail::core::graphics::TextDrawer_obj::_renderRect->width;
					HX_STACK_LINE(97)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->height = ::cocktail::core::graphics::TextDrawer_obj::TEXT_DECORATION_THICKNESS;
					HX_STACK_LINE(98)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->x = ::cocktail::core::graphics::TextDrawer_obj::_destPoint->x;
					HX_STACK_LINE(99)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->y = ((::cocktail::core::graphics::TextDrawer_obj::_destPoint->y + elementRenderer->getLeadedAscent()) + elementRenderer->coreStyle->fontMetrics->underlineOffset);
					HX_STACK_LINE(101)
					graphicsContext->graphics->fillRect(::cocktail::core::graphics::TextDrawer_obj::_decorationRect,elementRenderer->coreStyle->usedValues->color,clipRect);
				}
				HX_STACK_LINE(105)
				if (((hasOverline == true))){
					HX_STACK_LINE(107)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->width = ::cocktail::core::graphics::TextDrawer_obj::_renderRect->width;
					HX_STACK_LINE(108)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->height = ::cocktail::core::graphics::TextDrawer_obj::TEXT_DECORATION_THICKNESS;
					HX_STACK_LINE(109)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->x = ::cocktail::core::graphics::TextDrawer_obj::_destPoint->x;
					HX_STACK_LINE(110)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->y = ::cocktail::core::graphics::TextDrawer_obj::_destPoint->y;
					HX_STACK_LINE(112)
					graphicsContext->graphics->fillRect(::cocktail::core::graphics::TextDrawer_obj::_decorationRect,elementRenderer->coreStyle->usedValues->color,clipRect);
				}
				HX_STACK_LINE(116)
				if (((inlineBox->isSpace == false))){
					HX_STACK_LINE(119)
					::cocktail::core::linebox::TextInlineBox typedTextInlineBox = inlineBox;		HX_STACK_VAR(typedTextInlineBox,"typedTextInlineBox");
					HX_STACK_LINE(120)
					if (((typedTextInlineBox->get_nativeTextBitmap() != null()))){
						HX_STACK_LINE(121)
						graphicsContext->graphics->copyPixels(typedTextInlineBox->get_nativeTextBitmap(),::cocktail::core::graphics::TextDrawer_obj::_renderRect,::cocktail::core::graphics::TextDrawer_obj::_destPoint,clipRect);
					}
				}
				HX_STACK_LINE(127)
				if (((hasLineThrough == true))){
					HX_STACK_LINE(129)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->width = ::cocktail::core::graphics::TextDrawer_obj::_renderRect->width;
					HX_STACK_LINE(130)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->height = ::cocktail::core::graphics::TextDrawer_obj::TEXT_DECORATION_THICKNESS;
					HX_STACK_LINE(131)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->x = ::cocktail::core::graphics::TextDrawer_obj::_destPoint->x;
					HX_STACK_LINE(132)
					::cocktail::core::graphics::TextDrawer_obj::_decorationRect->y = ((::cocktail::core::graphics::TextDrawer_obj::_destPoint->y + elementRenderer->getLeadedAscent()) - elementRenderer->getLeadedDescent());
					HX_STACK_LINE(134)
					graphicsContext->graphics->fillRect(::cocktail::core::graphics::TextDrawer_obj::_decorationRect,elementRenderer->coreStyle->usedValues->color,clipRect);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(TextDrawer_obj,draw,(void))


TextDrawer_obj::TextDrawer_obj()
{
}

void TextDrawer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextDrawer);
	HX_MARK_END_CLASS();
}

void TextDrawer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic TextDrawer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_destPoint") ) { return _destPoint; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_renderRect") ) { return _renderRect; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_decorationRect") ) { return _decorationRect; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"TEXT_DECORATION_THICKNESS") ) { return TEXT_DECORATION_THICKNESS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextDrawer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_destPoint") ) { _destPoint=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_renderRect") ) { _renderRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_decorationRect") ) { _decorationRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"TEXT_DECORATION_THICKNESS") ) { TEXT_DECORATION_THICKNESS=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextDrawer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_destPoint"),
	HX_CSTRING("_renderRect"),
	HX_CSTRING("_decorationRect"),
	HX_CSTRING("TEXT_DECORATION_THICKNESS"),
	HX_CSTRING("draw"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextDrawer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextDrawer_obj::_destPoint,"_destPoint");
	HX_MARK_MEMBER_NAME(TextDrawer_obj::_renderRect,"_renderRect");
	HX_MARK_MEMBER_NAME(TextDrawer_obj::_decorationRect,"_decorationRect");
	HX_MARK_MEMBER_NAME(TextDrawer_obj::TEXT_DECORATION_THICKNESS,"TEXT_DECORATION_THICKNESS");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextDrawer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextDrawer_obj::_destPoint,"_destPoint");
	HX_VISIT_MEMBER_NAME(TextDrawer_obj::_renderRect,"_renderRect");
	HX_VISIT_MEMBER_NAME(TextDrawer_obj::_decorationRect,"_decorationRect");
	HX_VISIT_MEMBER_NAME(TextDrawer_obj::TEXT_DECORATION_THICKNESS,"TEXT_DECORATION_THICKNESS");
};

Class TextDrawer_obj::__mClass;

void TextDrawer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.graphics.TextDrawer"), hx::TCanCast< TextDrawer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextDrawer_obj::__boot()
{
	_destPoint= ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	_renderRect= ::cocktail::core::geom::RectangleVO_obj::__new();
	_decorationRect= ::cocktail::core::geom::RectangleVO_obj::__new();
	TEXT_DECORATION_THICKNESS= 1.0;
}

} // end namespace cocktail
} // end namespace core
} // end namespace graphics
