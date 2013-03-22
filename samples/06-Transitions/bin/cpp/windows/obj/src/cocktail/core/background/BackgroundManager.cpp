#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#include <cocktail/core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_DimensionVO
#include <cocktail/core/geom/DimensionVO.h>
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
#ifndef INCLUDED_cocktail_core_layout_computer_BackgroundStylesComputer
#include <cocktail/core/layout/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
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
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace core{
namespace background{

Void BackgroundManager_obj::__construct()
{
HX_STACK_PUSH("BackgroundManager::new","cocktail/core/background/BackgroundManager.hx",69);
{
}
;
	return null();
}

BackgroundManager_obj::~BackgroundManager_obj() { }

Dynamic BackgroundManager_obj::__CreateEmpty() { return  new BackgroundManager_obj; }
hx::ObjectPtr< BackgroundManager_obj > BackgroundManager_obj::__new()
{  hx::ObjectPtr< BackgroundManager_obj > result = new BackgroundManager_obj();
	result->__construct();
	return result;}

Dynamic BackgroundManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BackgroundManager_obj > result = new BackgroundManager_obj();
	result->__construct();
	return result;}

::cocktail::core::geom::RectangleVO BackgroundManager_obj::_box;

::cocktail::core::geom::PointVO BackgroundManager_obj::_destinationPoint;

::cocktail::core::geom::RectangleVO BackgroundManager_obj::_intersectionBounds;

Void BackgroundManager_obj::render( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::css::CoreStyle style,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BackgroundManager::render","cocktail/core/background/BackgroundManager.hx",89);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(backgroundBox,"backgroundBox");
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(91)
		if (((bool((::Math_obj::round(backgroundBox->width) <= (int)0)) || bool((::Math_obj::round(backgroundBox->height) <= (int)0))))){
			HX_STACK_LINE(92)
			return null();
		}
		HX_STACK_LINE(98)
		if (((style->usedValues->backgroundColor->alpha != 0.0))){
			HX_STACK_LINE(100)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->x = backgroundBox->x;
			HX_STACK_LINE(101)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->y = backgroundBox->y;
			HX_STACK_LINE(102)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->width = backgroundBox->width;
			HX_STACK_LINE(103)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->height = backgroundBox->height;
			HX_STACK_LINE(106)
			{
				HX_STACK_LINE(106)
				::cocktail::core::geom::RectangleVO bounds1 = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(bounds1,"bounds1");
				::cocktail::core::geom::RectangleVO resultBounds = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
				HX_STACK_LINE(106)
				if (((bool((bool((bool(((bounds1->x + bounds1->width) < clipRect->x)) || bool(((clipRect->x + clipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < clipRect->y)))) || bool(((clipRect->y + clipRect->height) < bounds1->y))))){
					HX_STACK_LINE(106)
					resultBounds->x = (int)0;
					HX_STACK_LINE(106)
					resultBounds->y = (int)0;
					HX_STACK_LINE(106)
					resultBounds->height = (int)0;
					HX_STACK_LINE(106)
					resultBounds->width = (int)0;
				}
				else{
					HX_STACK_LINE(106)
					Float left = (int)0;		HX_STACK_VAR(left,"left");
					HX_STACK_LINE(106)
					Float right = (int)0;		HX_STACK_VAR(right,"right");
					HX_STACK_LINE(106)
					Float top = (int)0;		HX_STACK_VAR(top,"top");
					HX_STACK_LINE(106)
					Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
					HX_STACK_LINE(106)
					if (((bounds1->x < clipRect->x))){
						HX_STACK_LINE(106)
						left = clipRect->x;
					}
					else{
						HX_STACK_LINE(106)
						left = bounds1->x;
					}
					HX_STACK_LINE(106)
					if ((((bounds1->x + bounds1->width) < (clipRect->x + clipRect->width)))){
						HX_STACK_LINE(106)
						right = (bounds1->x + bounds1->width);
					}
					else{
						HX_STACK_LINE(106)
						right = (clipRect->x + clipRect->width);
					}
					HX_STACK_LINE(106)
					if (((bounds1->y < clipRect->y))){
						HX_STACK_LINE(106)
						top = clipRect->y;
					}
					else{
						HX_STACK_LINE(106)
						top = bounds1->y;
					}
					HX_STACK_LINE(106)
					if ((((bounds1->y + bounds1->height) < (clipRect->y + clipRect->height)))){
						HX_STACK_LINE(106)
						bottom = (bounds1->y + bounds1->height);
					}
					else{
						HX_STACK_LINE(106)
						bottom = (clipRect->y + clipRect->height);
					}
					HX_STACK_LINE(106)
					resultBounds->x = left;
					HX_STACK_LINE(106)
					resultBounds->y = top;
					HX_STACK_LINE(106)
					resultBounds->width = (right - left);
					HX_STACK_LINE(106)
					resultBounds->height = (bottom - top);
				}
			}
			HX_STACK_LINE(107)
			if (((bool((::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->width == (int)0)) || bool((::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->height == (int)0))))){
				HX_STACK_LINE(108)
				return null();
			}
			HX_STACK_LINE(112)
			graphicContext->graphics->fillRect(backgroundBox,style->usedValues->backgroundColor,clipRect);
		}
		HX_STACK_LINE(116)
		if (((style->hasBackgroundImage == false))){
			HX_STACK_LINE(117)
			return null();
		}
		HX_STACK_LINE(121)
		::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->x = backgroundBox->x;
		HX_STACK_LINE(122)
		::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->y = backgroundBox->y;
		HX_STACK_LINE(123)
		::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->width = backgroundBox->width;
		HX_STACK_LINE(124)
		::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->height = backgroundBox->height;
		HX_STACK_LINE(127)
		{
			HX_STACK_LINE(127)
			::cocktail::core::geom::RectangleVO bounds1 = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(bounds1,"bounds1");
			::cocktail::core::geom::RectangleVO resultBounds = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
			HX_STACK_LINE(127)
			if (((bool((bool((bool(((bounds1->x + bounds1->width) < clipRect->x)) || bool(((clipRect->x + clipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < clipRect->y)))) || bool(((clipRect->y + clipRect->height) < bounds1->y))))){
				HX_STACK_LINE(127)
				resultBounds->x = (int)0;
				HX_STACK_LINE(127)
				resultBounds->y = (int)0;
				HX_STACK_LINE(127)
				resultBounds->height = (int)0;
				HX_STACK_LINE(127)
				resultBounds->width = (int)0;
			}
			else{
				HX_STACK_LINE(127)
				Float left = (int)0;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(127)
				Float right = (int)0;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(127)
				Float top = (int)0;		HX_STACK_VAR(top,"top");
				HX_STACK_LINE(127)
				Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
				HX_STACK_LINE(127)
				if (((bounds1->x < clipRect->x))){
					HX_STACK_LINE(127)
					left = clipRect->x;
				}
				else{
					HX_STACK_LINE(127)
					left = bounds1->x;
				}
				HX_STACK_LINE(127)
				if ((((bounds1->x + bounds1->width) < (clipRect->x + clipRect->width)))){
					HX_STACK_LINE(127)
					right = (bounds1->x + bounds1->width);
				}
				else{
					HX_STACK_LINE(127)
					right = (clipRect->x + clipRect->width);
				}
				HX_STACK_LINE(127)
				if (((bounds1->y < clipRect->y))){
					HX_STACK_LINE(127)
					top = clipRect->y;
				}
				else{
					HX_STACK_LINE(127)
					top = bounds1->y;
				}
				HX_STACK_LINE(127)
				if ((((bounds1->y + bounds1->height) < (clipRect->y + clipRect->height)))){
					HX_STACK_LINE(127)
					bottom = (bounds1->y + bounds1->height);
				}
				else{
					HX_STACK_LINE(127)
					bottom = (clipRect->y + clipRect->height);
				}
				HX_STACK_LINE(127)
				resultBounds->x = left;
				HX_STACK_LINE(127)
				resultBounds->y = top;
				HX_STACK_LINE(127)
				resultBounds->width = (right - left);
				HX_STACK_LINE(127)
				resultBounds->height = (bottom - top);
			}
		}
		HX_STACK_LINE(128)
		if (((bool((::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->width == (int)0)) || bool((::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->height == (int)0))))){
			HX_STACK_LINE(129)
			return null();
		}
		HX_STACK_LINE(133)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundImages = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)26));		HX_STACK_VAR(backgroundImages,"backgroundImages");
		HX_STACK_LINE(135)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundPositions = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)30));		HX_STACK_VAR(backgroundPositions,"backgroundPositions");
		HX_STACK_LINE(137)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundOrigins = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)28));		HX_STACK_VAR(backgroundOrigins,"backgroundOrigins");
		HX_STACK_LINE(138)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundClips = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)31));		HX_STACK_VAR(backgroundClips,"backgroundClips");
		HX_STACK_LINE(139)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundSizes = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)29));		HX_STACK_VAR(backgroundSizes,"backgroundSizes");
		HX_STACK_LINE(140)
		Array< ::cocktail::core::css::CSSPropertyValue > backgroundRepeats = ::cocktail::core::background::BackgroundManager_obj::getAsArray(style->getComputedOrInitialProperty((int)27));		HX_STACK_VAR(backgroundRepeats,"backgroundRepeats");
		HX_STACK_LINE(146)
		int length = backgroundImages->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(147)
		{
			HX_STACK_LINE(147)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(147)
			while(((_g < length))){
				HX_STACK_LINE(147)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(149)
				::cocktail::core::css::CSSPropertyValue backgroundImage = backgroundImages->__get(i);		HX_STACK_VAR(backgroundImage,"backgroundImage");
				HX_STACK_LINE(150)
				{
					::cocktail::core::css::CSSPropertyValue _switch_1 = (backgroundImage);
					switch((_switch_1)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
							}
						}
						;break;
						case 5: {
							::String value = _switch_1->__Param(0);
{
								HX_STACK_LINE(154)
								::cocktail::core::background::BackgroundManager_obj::drawBackgroundImage(graphicContext,value,style,backgroundBox,backgroundPositions->__get(i),backgroundSizes->__get(i),backgroundOrigins->__get(i),backgroundClips->__get(i),backgroundRepeats->__get(i),backgroundImages->__get(i),elementRenderer,clipRect);
							}
						}
						;break;
						default: {
						}
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BackgroundManager_obj,render,(void))

Array< ::cocktail::core::css::CSSPropertyValue > BackgroundManager_obj::getAsArray( ::cocktail::core::css::CSSPropertyValue cssProperty){
	HX_STACK_PUSH("BackgroundManager::getAsArray","cocktail/core/background/BackgroundManager.hx",166);
	HX_STACK_ARG(cssProperty,"cssProperty");
	HX_STACK_LINE(166)
	{
		::cocktail::core::css::CSSPropertyValue _switch_2 = (cssProperty);
		switch((_switch_2)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_2->__Param(0);
{
					HX_STACK_LINE(169)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(cssProperty);
				}
			}
			;break;
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_2->__Param(0);
{
					HX_STACK_LINE(172)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(cssProperty);
				}
			}
			;break;
			case 2: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(175)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(cssProperty);
				}
			}
			;break;
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_2->__Param(0);
{
					HX_STACK_LINE(178)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(cssProperty);
				}
			}
			;break;
			case 5: {
				::String value = _switch_2->__Param(0);
{
					HX_STACK_LINE(181)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(cssProperty);
				}
			}
			;break;
			default: {
				HX_STACK_LINE(184)
				return null();
			}
		}
	}
	HX_STACK_LINE(166)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundManager_obj,getAsArray,return )

Void BackgroundManager_obj::drawBackgroundImage( ::cocktail::core::graphics::GraphicsContext graphicContext,::String url,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::css::CSSPropertyValue backgroundImage,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BackgroundManager::drawBackgroundImage","cocktail/core/background/BackgroundManager.hx",212);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(backgroundBox,"backgroundBox");
		HX_STACK_ARG(backgroundPosition,"backgroundPosition");
		HX_STACK_ARG(backgroundSize,"backgroundSize");
		HX_STACK_ARG(backgroundOrigin,"backgroundOrigin");
		HX_STACK_ARG(backgroundClip,"backgroundClip");
		HX_STACK_ARG(backgroundRepeat,"backgroundRepeat");
		HX_STACK_ARG(backgroundImage,"backgroundImage");
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(212)
		Array< ::cocktail::core::renderer::ElementRenderer > elementRenderer1 = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new().Add(elementRenderer);		HX_STACK_VAR(elementRenderer1,"elementRenderer1");
		HX_STACK_LINE(216)
		bool foundResource = false;		HX_STACK_VAR(foundResource,"foundResource");
		HX_STACK_LINE(218)
		::cocktail::core::resource::AbstractResource resource = ::cocktail::core::resource::ResourceManager_obj::getImageResource(url);		HX_STACK_VAR(resource,"resource");
		HX_STACK_LINE(220)
		if (((resource->loaded == true))){
			HX_STACK_LINE(222)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->x = backgroundBox->x;
			HX_STACK_LINE(223)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->y = backgroundBox->y;
			HX_STACK_LINE(224)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->width = backgroundBox->width;
			HX_STACK_LINE(225)
			::cocktail::core::background::BackgroundManager_obj::_intersectionBounds->height = backgroundBox->height;
			HX_STACK_LINE(231)
			{
				HX_STACK_LINE(231)
				::cocktail::core::geom::RectangleVO bounds1 = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(bounds1,"bounds1");
				::cocktail::core::geom::RectangleVO resultBounds = ::cocktail::core::background::BackgroundManager_obj::_intersectionBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
				HX_STACK_LINE(231)
				if (((bool((bool((bool(((bounds1->x + bounds1->width) < clipRect->x)) || bool(((clipRect->x + clipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < clipRect->y)))) || bool(((clipRect->y + clipRect->height) < bounds1->y))))){
					HX_STACK_LINE(231)
					resultBounds->x = (int)0;
					HX_STACK_LINE(231)
					resultBounds->y = (int)0;
					HX_STACK_LINE(231)
					resultBounds->height = (int)0;
					HX_STACK_LINE(231)
					resultBounds->width = (int)0;
				}
				else{
					HX_STACK_LINE(231)
					Float left = (int)0;		HX_STACK_VAR(left,"left");
					HX_STACK_LINE(231)
					Float right = (int)0;		HX_STACK_VAR(right,"right");
					HX_STACK_LINE(231)
					Float top = (int)0;		HX_STACK_VAR(top,"top");
					HX_STACK_LINE(231)
					Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
					HX_STACK_LINE(231)
					if (((bounds1->x < clipRect->x))){
						HX_STACK_LINE(231)
						left = clipRect->x;
					}
					else{
						HX_STACK_LINE(231)
						left = bounds1->x;
					}
					HX_STACK_LINE(231)
					if ((((bounds1->x + bounds1->width) < (clipRect->x + clipRect->width)))){
						HX_STACK_LINE(231)
						right = (bounds1->x + bounds1->width);
					}
					else{
						HX_STACK_LINE(231)
						right = (clipRect->x + clipRect->width);
					}
					HX_STACK_LINE(231)
					if (((bounds1->y < clipRect->y))){
						HX_STACK_LINE(231)
						top = clipRect->y;
					}
					else{
						HX_STACK_LINE(231)
						top = bounds1->y;
					}
					HX_STACK_LINE(231)
					if ((((bounds1->y + bounds1->height) < (clipRect->y + clipRect->height)))){
						HX_STACK_LINE(231)
						bottom = (bounds1->y + bounds1->height);
					}
					else{
						HX_STACK_LINE(231)
						bottom = (clipRect->y + clipRect->height);
					}
					HX_STACK_LINE(231)
					resultBounds->x = left;
					HX_STACK_LINE(231)
					resultBounds->y = top;
					HX_STACK_LINE(231)
					resultBounds->width = (right - left);
					HX_STACK_LINE(231)
					resultBounds->height = (bottom - top);
				}
			}
			HX_STACK_LINE(233)
			Dynamic computedGradientStyles = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::computeIndividualBackground(style,backgroundBox,resource->intrinsicWidth,resource->intrinsicHeight,resource->intrinsicRatio,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);		HX_STACK_VAR(computedGradientStyles,"computedGradientStyles");
			HX_STACK_LINE(237)
			::cocktail::core::background::BackgroundManager_obj::doDrawBackgroundImage(backgroundBox,graphicContext,resource,computedGradientStyles->__Field(HX_CSTRING("backgroundOrigin"),true),computedGradientStyles->__Field(HX_CSTRING("backgroundClip"),true),resource->intrinsicWidth,resource->intrinsicHeight,resource->intrinsicRatio,computedGradientStyles->__Field(HX_CSTRING("backgroundSize"),true),computedGradientStyles->__Field(HX_CSTRING("backgroundPosition"),true),computedGradientStyles->__Field(HX_CSTRING("backgroundRepeat"),true),::cocktail::core::background::BackgroundManager_obj::_intersectionBounds);
			HX_STACK_LINE(250)
			foundResource = true;
		}
		else{
			HX_STACK_LINE(252)
			if (((resource->loadedWithError == false))){

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::cocktail::core::renderer::ElementRenderer >,elementRenderer1)
				Void run(::cocktail::core::event::Event e){
					HX_STACK_PUSH("*::_Function_3_1","cocktail/core/background/BackgroundManager.hx",254);
					HX_STACK_ARG(e,"e");
					{
						HX_STACK_LINE(254)
						elementRenderer1->__get((int)0)->invalidateRendering();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(254)
				resource->addEventListener(HX_CSTRING("load"), Dynamic(new _Function_3_1(elementRenderer1)),null());

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,Array< ::cocktail::core::renderer::ElementRenderer >,elementRenderer1)
				Void run(::cocktail::core::event::Event e){
					HX_STACK_PUSH("*::_Function_3_2","cocktail/core/background/BackgroundManager.hx",258);
					HX_STACK_ARG(e,"e");
					{
						HX_STACK_LINE(258)
						elementRenderer1->__get((int)0)->invalidateRendering();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(258)
				resource->addEventListener(HX_CSTRING("error"), Dynamic(new _Function_3_2(elementRenderer1)),null());
				HX_STACK_LINE(262)
				foundResource = true;
			}
		}
		HX_STACK_LINE(266)
		if (((foundResource == false))){
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC12(BackgroundManager_obj,drawBackgroundImage,(void))

Void BackgroundManager_obj::doDrawBackgroundImage( ::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::resource::AbstractResource resource,::cocktail::core::geom::RectangleVO backgroundPositioningBox,::cocktail::core::geom::RectangleVO backgroundPaintingBox,Float intrinsicWidth,Float intrinsicHeight,Float intrinsicRatio,::cocktail::core::geom::DimensionVO computedBackgroundSize,::cocktail::core::geom::PointVO computedBackgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("BackgroundManager::doDrawBackgroundImage","cocktail/core/background/BackgroundManager.hx",295);
		HX_STACK_ARG(backgroundBox,"backgroundBox");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(resource,"resource");
		HX_STACK_ARG(backgroundPositioningBox,"backgroundPositioningBox");
		HX_STACK_ARG(backgroundPaintingBox,"backgroundPaintingBox");
		HX_STACK_ARG(intrinsicWidth,"intrinsicWidth");
		HX_STACK_ARG(intrinsicHeight,"intrinsicHeight");
		HX_STACK_ARG(intrinsicRatio,"intrinsicRatio");
		HX_STACK_ARG(computedBackgroundSize,"computedBackgroundSize");
		HX_STACK_ARG(computedBackgroundPosition,"computedBackgroundPosition");
		HX_STACK_ARG(backgroundRepeat,"backgroundRepeat");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(297)
		::cocktail::core::css::CSSKeywordValue backgroundRepeatX = null();		HX_STACK_VAR(backgroundRepeatX,"backgroundRepeatX");
		HX_STACK_LINE(298)
		::cocktail::core::css::CSSKeywordValue backgroundRepeatY = null();		HX_STACK_VAR(backgroundRepeatY,"backgroundRepeatY");
		HX_STACK_LINE(300)
		{
			::cocktail::core::css::CSSPropertyValue _switch_3 = (backgroundRepeat);
			switch((_switch_3)->GetIndex()){
				case 13: {
					Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_3->__Param(0);
{
						HX_STACK_LINE(303)
						{
							::cocktail::core::css::CSSPropertyValue _switch_4 = (value->__get((int)0));
							switch((_switch_4)->GetIndex()){
								case 4: {
									::cocktail::core::css::CSSKeywordValue value1 = _switch_4->__Param(0);
{
										HX_STACK_LINE(305)
										backgroundRepeatX = value1;
									}
								}
								;break;
								default: {
								}
							}
						}
						HX_STACK_LINE(311)
						{
							::cocktail::core::css::CSSPropertyValue _switch_5 = (value->__get((int)1));
							switch((_switch_5)->GetIndex()){
								case 4: {
									::cocktail::core::css::CSSKeywordValue value1 = _switch_5->__Param(0);
{
										HX_STACK_LINE(313)
										backgroundRepeatY = value1;
									}
								}
								;break;
								default: {
								}
							}
						}
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(322)
		Float totalWidth = (computedBackgroundPosition->x + backgroundPositioningBox->x);		HX_STACK_VAR(totalWidth,"totalWidth");
		HX_STACK_LINE(323)
		Float maxWidth = (backgroundPaintingBox->x + backgroundPaintingBox->width);		HX_STACK_VAR(maxWidth,"maxWidth");
		HX_STACK_LINE(324)
		Float imageWidth = computedBackgroundSize->width;		HX_STACK_VAR(imageWidth,"imageWidth");
		HX_STACK_LINE(326)
		{
			::cocktail::core::css::CSSKeywordValue _switch_6 = (backgroundRepeatX);
			switch((_switch_6)->GetIndex()){
				case 72: {
					HX_STACK_LINE(328)
					maxWidth = (totalWidth + imageWidth);
				}
				;break;
				case 67: {
					HX_STACK_LINE(331)
					while(((totalWidth > backgroundPaintingBox->x))){
						HX_STACK_LINE(333)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
				case 70: {
					HX_STACK_LINE(338)
					imageWidth = ::Math_obj::round((Float(backgroundPositioningBox->width) / Float(computedBackgroundSize->width)));
					HX_STACK_LINE(339)
					while(((totalWidth > backgroundPaintingBox->x))){
						HX_STACK_LINE(340)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
				case 71: {
					HX_STACK_LINE(344)
					while(((totalWidth > backgroundPaintingBox->x))){
						HX_STACK_LINE(346)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(352)
		Float initialWidth = totalWidth;		HX_STACK_VAR(initialWidth,"initialWidth");
		HX_STACK_LINE(354)
		Float totalHeight = (computedBackgroundPosition->y + ::Math_obj::round(backgroundPositioningBox->y));		HX_STACK_VAR(totalHeight,"totalHeight");
		HX_STACK_LINE(355)
		Float maxHeight = (backgroundPaintingBox->y + backgroundPaintingBox->height);		HX_STACK_VAR(maxHeight,"maxHeight");
		HX_STACK_LINE(356)
		Float imageHeight = computedBackgroundSize->height;		HX_STACK_VAR(imageHeight,"imageHeight");
		HX_STACK_LINE(358)
		{
			::cocktail::core::css::CSSKeywordValue _switch_7 = (backgroundRepeatY);
			switch((_switch_7)->GetIndex()){
				case 72: {
					HX_STACK_LINE(360)
					maxHeight = (totalHeight + imageHeight);
				}
				;break;
				case 67: {
					HX_STACK_LINE(363)
					while(((totalHeight > backgroundPaintingBox->y))){
						HX_STACK_LINE(365)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
				case 70: {
					HX_STACK_LINE(370)
					imageHeight = (Float(backgroundPositioningBox->height) / Float(computedBackgroundSize->height));
					HX_STACK_LINE(371)
					while(((totalHeight > backgroundPaintingBox->y))){
						HX_STACK_LINE(372)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
				case 71: {
					HX_STACK_LINE(376)
					while(((totalHeight > backgroundPaintingBox->y))){
						HX_STACK_LINE(378)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(385)
		Float initialHeight = totalHeight;		HX_STACK_VAR(initialHeight,"initialHeight");
		HX_STACK_LINE(387)
		if (((bool(((Float(imageWidth) / Float(intrinsicWidth)) == (int)1)) && bool(((Float(imageHeight) / Float(intrinsicHeight)) == (int)1))))){
			HX_STACK_LINE(389)
			::cocktail::core::background::BackgroundManager_obj::_destinationPoint->x = ((totalWidth + backgroundBox->x) - computedBackgroundPosition->x);
			HX_STACK_LINE(390)
			::cocktail::core::background::BackgroundManager_obj::_destinationPoint->y = ((totalHeight + backgroundBox->y) - computedBackgroundPosition->y);
			HX_STACK_LINE(392)
			Float intWidth = intrinsicWidth;		HX_STACK_VAR(intWidth,"intWidth");
			HX_STACK_LINE(393)
			Float intHeight = intrinsicHeight;		HX_STACK_VAR(intHeight,"intHeight");
			HX_STACK_LINE(395)
			::cocktail::core::background::BackgroundManager_obj::_box->x = (backgroundPaintingBox->x - computedBackgroundPosition->x);
			HX_STACK_LINE(396)
			::cocktail::core::background::BackgroundManager_obj::_box->y = (backgroundPaintingBox->y - computedBackgroundPosition->y);
			HX_STACK_LINE(397)
			::cocktail::core::background::BackgroundManager_obj::_box->width = backgroundPaintingBox->width;
			HX_STACK_LINE(398)
			::cocktail::core::background::BackgroundManager_obj::_box->height = backgroundPaintingBox->height;
			HX_STACK_LINE(400)
			while(((totalHeight < maxHeight))){
				HX_STACK_LINE(402)
				graphicContext->graphics->copyPixels(resource->nativeResource,::cocktail::core::background::BackgroundManager_obj::_box,::cocktail::core::background::BackgroundManager_obj::_destinationPoint,clipRect);
				HX_STACK_LINE(404)
				hx::AddEq(totalWidth,imageWidth);
				HX_STACK_LINE(406)
				if (((totalWidth >= maxWidth))){
					HX_STACK_LINE(408)
					totalWidth = initialWidth;
					HX_STACK_LINE(409)
					hx::AddEq(totalHeight,imageHeight);
				}
				HX_STACK_LINE(412)
				::cocktail::core::background::BackgroundManager_obj::_destinationPoint->x = ((totalWidth + backgroundBox->x) - computedBackgroundPosition->x);
				HX_STACK_LINE(413)
				::cocktail::core::background::BackgroundManager_obj::_destinationPoint->y = ((totalHeight + backgroundBox->y) - computedBackgroundPosition->y);
			}
		}
		else{
			HX_STACK_LINE(418)
			::cocktail::core::geom::Matrix matrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
			HX_STACK_LINE(420)
			hx::AddEq(backgroundPaintingBox->x,(backgroundBox->x + computedBackgroundPosition->x));
			HX_STACK_LINE(421)
			hx::AddEq(backgroundPaintingBox->y,(backgroundBox->y + computedBackgroundPosition->y));
			HX_STACK_LINE(423)
			while(((totalHeight < maxHeight))){
				HX_STACK_LINE(426)
				matrix->identity();
				HX_STACK_LINE(428)
				matrix->translate((totalWidth + backgroundBox->x),(totalHeight + backgroundBox->y));
				HX_STACK_LINE(430)
				matrix->scale((Float(imageWidth) / Float(intrinsicWidth)),(Float(imageHeight) / Float(intrinsicHeight)));
				HX_STACK_LINE(432)
				graphicContext->graphics->drawImage(resource->nativeResource,matrix,backgroundPaintingBox,clipRect);
				HX_STACK_LINE(434)
				hx::AddEq(totalWidth,imageWidth);
				HX_STACK_LINE(436)
				if (((totalWidth >= maxWidth))){
					HX_STACK_LINE(438)
					totalWidth = initialWidth;
					HX_STACK_LINE(439)
					hx::AddEq(totalHeight,imageHeight);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC12(BackgroundManager_obj,doDrawBackgroundImage,(void))


BackgroundManager_obj::BackgroundManager_obj()
{
}

void BackgroundManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BackgroundManager);
	HX_MARK_END_CLASS();
}

void BackgroundManager_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BackgroundManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_box") ) { return _box; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAsArray") ) { return getAsArray_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_destinationPoint") ) { return _destinationPoint; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_intersectionBounds") ) { return _intersectionBounds; }
		if (HX_FIELD_EQ(inName,"drawBackgroundImage") ) { return drawBackgroundImage_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"doDrawBackgroundImage") ) { return doDrawBackgroundImage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BackgroundManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_box") ) { _box=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_destinationPoint") ) { _destinationPoint=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_intersectionBounds") ) { _intersectionBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BackgroundManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_box"),
	HX_CSTRING("_destinationPoint"),
	HX_CSTRING("_intersectionBounds"),
	HX_CSTRING("render"),
	HX_CSTRING("getAsArray"),
	HX_CSTRING("drawBackgroundImage"),
	HX_CSTRING("doDrawBackgroundImage"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BackgroundManager_obj::_box,"_box");
	HX_MARK_MEMBER_NAME(BackgroundManager_obj::_destinationPoint,"_destinationPoint");
	HX_MARK_MEMBER_NAME(BackgroundManager_obj::_intersectionBounds,"_intersectionBounds");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BackgroundManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BackgroundManager_obj::_box,"_box");
	HX_VISIT_MEMBER_NAME(BackgroundManager_obj::_destinationPoint,"_destinationPoint");
	HX_VISIT_MEMBER_NAME(BackgroundManager_obj::_intersectionBounds,"_intersectionBounds");
};

Class BackgroundManager_obj::__mClass;

void BackgroundManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.background.BackgroundManager"), hx::TCanCast< BackgroundManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BackgroundManager_obj::__boot()
{
	_box= ::cocktail::core::geom::RectangleVO_obj::__new();
	_destinationPoint= ::cocktail::core::geom::PointVO_obj::__new(0.0,0.0);
	_intersectionBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace background
