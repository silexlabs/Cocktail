#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
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
#ifndef INCLUDED_cocktail_core_layout_FloatVO
#include <cocktail/core/layout/FloatVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_FloatsVO
#include <cocktail/core/layout/FloatsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_floats_FloatsManager
#include <cocktail/core/layout/floats/FloatsManager.h>
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
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace floats{

Void FloatsManager_obj::__construct()
{
HX_STACK_PUSH("FloatsManager::new","cocktail/core/layout/floats/FloatsManager.hx",63);
{
	HX_STACK_LINE(64)
	Array< ::cocktail::core::layout::FloatVO > floatsLeft = Array_obj< ::cocktail::core::layout::FloatVO >::__new();		HX_STACK_VAR(floatsLeft,"floatsLeft");
	HX_STACK_LINE(65)
	Array< ::cocktail::core::layout::FloatVO > floatsRight = Array_obj< ::cocktail::core::layout::FloatVO >::__new();		HX_STACK_VAR(floatsRight,"floatsRight");
	HX_STACK_LINE(66)
	this->childrenWithClearance = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_STACK_LINE(67)
	this->set_floats(::cocktail::core::layout::FloatsVO_obj::__new(floatsLeft,floatsRight));
	HX_STACK_LINE(68)
	this->hasFloats = false;
}
;
	return null();
}

FloatsManager_obj::~FloatsManager_obj() { }

Dynamic FloatsManager_obj::__CreateEmpty() { return  new FloatsManager_obj; }
hx::ObjectPtr< FloatsManager_obj > FloatsManager_obj::__new()
{  hx::ObjectPtr< FloatsManager_obj > result = new FloatsManager_obj();
	result->__construct();
	return result;}

Dynamic FloatsManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatsManager_obj > result = new FloatsManager_obj();
	result->__construct();
	return result;}

::cocktail::core::layout::FloatsVO FloatsManager_obj::set_floats( ::cocktail::core::layout::FloatsVO value){
	HX_STACK_PUSH("FloatsManager::set_floats","cocktail/core/layout/floats/FloatsManager.hx",482);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(483)
	this->floats = value;
	HX_STACK_LINE(485)
	if (((bool((value->left->length > (int)0)) || bool((value->right->length > (int)0))))){
		HX_STACK_LINE(486)
		this->hasFloats = true;
	}
	else{
		HX_STACK_LINE(490)
		this->hasFloats = false;
	}
	HX_STACK_LINE(494)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,set_floats,return )

Float FloatsManager_obj::getRightFloatOffset( Float y,Float elementHeight,Float elementWidth,Float containingBlockXOffset,Float containingBlockWidth){
	HX_STACK_PUSH("FloatsManager::getRightFloatOffset","cocktail/core/layout/floats/FloatsManager.hx",451);
	HX_STACK_THIS(this);
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(elementHeight,"elementHeight");
	HX_STACK_ARG(elementWidth,"elementWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_LINE(452)
	Float rightFloatOffset = (containingBlockXOffset + containingBlockWidth);		HX_STACK_VAR(rightFloatOffset,"rightFloatOffset");
	HX_STACK_LINE(454)
	int length = this->floats->right->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(455)
	{
		HX_STACK_LINE(455)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(455)
		while(((_g < length))){
			HX_STACK_LINE(455)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(457)
			::cocktail::core::geom::RectangleVO floatBounds = this->floats->right->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
			HX_STACK_LINE(458)
			if (((bool((bool(((floatBounds->y + floatBounds->height) > y)) && bool((floatBounds->y <= y)))) || bool((bool((floatBounds->y <= (y + elementHeight))) && bool((floatBounds->y > y))))))){
				HX_STACK_LINE(460)
				if (((floatBounds->x < rightFloatOffset))){
					HX_STACK_LINE(462)
					rightFloatOffset = floatBounds->x;
				}
			}
		}
	}
	HX_STACK_LINE(468)
	return rightFloatOffset;
}


HX_DEFINE_DYNAMIC_FUNC5(FloatsManager_obj,getRightFloatOffset,return )

Float FloatsManager_obj::getLeftFloatOffset( Float y,Float elementHeight,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::getLeftFloatOffset","cocktail/core/layout/floats/FloatsManager.hx",416);
	HX_STACK_THIS(this);
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(elementHeight,"elementHeight");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(417)
	Float leftFloatOffset = containingBlockXOffset;		HX_STACK_VAR(leftFloatOffset,"leftFloatOffset");
	HX_STACK_LINE(420)
	int length = this->floats->left->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(422)
	{
		HX_STACK_LINE(422)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(422)
		while(((_g < length))){
			HX_STACK_LINE(422)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(424)
			::cocktail::core::geom::RectangleVO floatBounds = this->floats->left->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
			HX_STACK_LINE(427)
			if (((bool((bool(((floatBounds->y + floatBounds->height) > y)) && bool((floatBounds->y <= y)))) || bool((bool((floatBounds->y <= (y + elementHeight))) && bool((floatBounds->y > y))))))){
				HX_STACK_LINE(429)
				if ((((floatBounds->x + floatBounds->width) > leftFloatOffset))){
					HX_STACK_LINE(433)
					leftFloatOffset = (floatBounds->x + floatBounds->width);
				}
			}
		}
	}
	HX_STACK_LINE(439)
	return leftFloatOffset;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,getLeftFloatOffset,return )

bool FloatsManager_obj::canFitElementAtY( Float y,Float elementHeight,Float elementWidth,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::canFitElementAtY","cocktail/core/layout/floats/FloatsManager.hx",393);
	HX_STACK_THIS(this);
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(elementHeight,"elementHeight");
	HX_STACK_ARG(elementWidth,"elementWidth");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(393)
	if ((((this->getRightFloatOffset(y,elementHeight,elementWidth,containingBlockXOffset,containingBlockWidth) - this->getLeftFloatOffset(y,elementHeight,containingBlockXOffset)) < elementWidth))){
		HX_STACK_LINE(396)
		return false;
	}
	else{
		HX_STACK_LINE(400)
		return true;
	}
	HX_STACK_LINE(393)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC5(FloatsManager_obj,canFitElementAtY,return )

Float FloatsManager_obj::getFirstAvailableYPosition( Float currentYPosition,Float elementHeight,Float elementWidth,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::getFirstAvailableYPosition","cocktail/core/layout/floats/FloatsManager.hx",309);
	HX_STACK_THIS(this);
	HX_STACK_ARG(currentYPosition,"currentYPosition");
	HX_STACK_ARG(elementHeight,"elementHeight");
	HX_STACK_ARG(elementWidth,"elementWidth");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(313)
	Float retY = currentYPosition;		HX_STACK_VAR(retY,"retY");
	HX_STACK_LINE(317)
	while(((this->canFitElementAtY(retY,elementHeight,elementWidth,containingBlockWidth,containingBlockXOffset) == false))){
		HX_STACK_LINE(322)
		Array< ::cocktail::core::geom::RectangleVO > afterFloats = Array_obj< ::cocktail::core::geom::RectangleVO >::__new();		HX_STACK_VAR(afterFloats,"afterFloats");
		HX_STACK_LINE(325)
		int leftFloatLength = this->floats->left->length;		HX_STACK_VAR(leftFloatLength,"leftFloatLength");
		HX_STACK_LINE(326)
		{
			HX_STACK_LINE(326)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(326)
			while(((_g < leftFloatLength))){
				HX_STACK_LINE(326)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(328)
				::cocktail::core::geom::RectangleVO floatBounds = this->floats->left->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
				HX_STACK_LINE(329)
				if (((bool((bool((floatBounds->y <= retY)) && bool(((floatBounds->height + floatBounds->y) > retY)))) || bool((bool((floatBounds->y <= (retY + elementHeight))) && bool((floatBounds->y > retY))))))){
					HX_STACK_LINE(331)
					afterFloats->push(floatBounds);
				}
			}
		}
		HX_STACK_LINE(337)
		int rightFloatLength = this->floats->right->length;		HX_STACK_VAR(rightFloatLength,"rightFloatLength");
		HX_STACK_LINE(338)
		{
			HX_STACK_LINE(338)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(338)
			while(((_g < rightFloatLength))){
				HX_STACK_LINE(338)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(340)
				::cocktail::core::geom::RectangleVO floatBounds = this->floats->right->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
				HX_STACK_LINE(341)
				if (((bool((bool((floatBounds->y <= retY)) && bool(((floatBounds->height + floatBounds->y) > retY)))) || bool((bool((floatBounds->y <= (retY + elementHeight))) && bool((floatBounds->y > retY))))))){
					HX_STACK_LINE(343)
					afterFloats->push(floatBounds);
				}
			}
		}
		HX_STACK_LINE(351)
		if (((afterFloats->length == (int)0))){
			HX_STACK_LINE(352)
			break;
		}
		else{
			HX_STACK_LINE(365)
			Float nextY = (int)1000000;		HX_STACK_VAR(nextY,"nextY");
			HX_STACK_LINE(368)
			{
				HX_STACK_LINE(368)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				int _g = afterFloats->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(368)
				while(((_g1 < _g))){
					HX_STACK_LINE(368)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(370)
					if (((((afterFloats->__get(i)->y + afterFloats->__get(i)->height) - retY) < nextY))){
						HX_STACK_LINE(371)
						nextY = ((afterFloats->__get(i)->y + afterFloats->__get(i)->height) - retY);
					}
				}
			}
			HX_STACK_LINE(380)
			hx::AddEq(retY,nextY);
		}
	}
	HX_STACK_LINE(385)
	return retY;
}


HX_DEFINE_DYNAMIC_FUNC5(FloatsManager_obj,getFirstAvailableYPosition,return )

::cocktail::core::geom::RectangleVO FloatsManager_obj::getFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::getFloatBounds","cocktail/core/layout/floats/FloatsManager.hx",274);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(floatY,"floatY");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(277)
	::cocktail::core::css::UsedValuesVO usedValues = elementRenderer->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(278)
	Float floatWidth = ((elementRenderer->bounds->width + usedValues->marginLeft) + usedValues->marginRight);		HX_STACK_VAR(floatWidth,"floatWidth");
	HX_STACK_LINE(279)
	Float floatHeight = ((elementRenderer->bounds->height + usedValues->marginTop) + usedValues->marginBottom);		HX_STACK_VAR(floatHeight,"floatHeight");
	HX_STACK_LINE(282)
	Float floatY1 = this->getFirstAvailableYPosition(floatY,floatHeight,floatWidth,containingBlockWidth,containingBlockXOffset);		HX_STACK_VAR(floatY1,"floatY1");
	HX_STACK_LINE(285)
	Float floatX = 0.0;		HX_STACK_VAR(floatX,"floatX");
	HX_STACK_LINE(287)
	::cocktail::core::geom::RectangleVO rect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(288)
	rect->x = floatX;
	HX_STACK_LINE(289)
	rect->y = floatY1;
	HX_STACK_LINE(290)
	rect->width = floatWidth;
	HX_STACK_LINE(291)
	rect->height = floatHeight;
	HX_STACK_LINE(292)
	return rect;
}


HX_DEFINE_DYNAMIC_FUNC4(FloatsManager_obj,getFloatBounds,return )

::cocktail::core::geom::RectangleVO FloatsManager_obj::getRightFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::getRightFloatBounds","cocktail/core/layout/floats/FloatsManager.hx",258);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(floatY,"floatY");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(260)
	::cocktail::core::geom::RectangleVO floatBounds = this->getFloatBounds(elementRenderer,floatY,containingBlockWidth,containingBlockXOffset);		HX_STACK_VAR(floatBounds,"floatBounds");
	HX_STACK_LINE(264)
	floatBounds->x = (this->getRightFloatOffset(floatBounds->y,floatBounds->height,floatBounds->width,containingBlockXOffset,containingBlockWidth) - floatBounds->width);
	HX_STACK_LINE(266)
	return floatBounds;
}


HX_DEFINE_DYNAMIC_FUNC4(FloatsManager_obj,getRightFloatBounds,return )

::cocktail::core::geom::RectangleVO FloatsManager_obj::getLeftFloatBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::getLeftFloatBounds","cocktail/core/layout/floats/FloatsManager.hx",242);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(floatY,"floatY");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(244)
	::cocktail::core::geom::RectangleVO floatBounds = this->getFloatBounds(elementRenderer,floatY,containingBlockWidth,containingBlockXOffset);		HX_STACK_VAR(floatBounds,"floatBounds");
	HX_STACK_LINE(248)
	floatBounds->x = this->getLeftFloatOffset(floatBounds->y,floatBounds->height,containingBlockXOffset);
	HX_STACK_LINE(250)
	return floatBounds;
}


HX_DEFINE_DYNAMIC_FUNC4(FloatsManager_obj,getLeftFloatBounds,return )

::cocktail::core::geom::RectangleVO FloatsManager_obj::registerFloat( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float floatY,Float containingBlockWidth,Float containingBlockXOffset){
	HX_STACK_PUSH("FloatsManager::registerFloat","cocktail/core/layout/floats/FloatsManager.hx",217);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(floatY,"floatY");
	HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
	HX_STACK_ARG(containingBlockXOffset,"containingBlockXOffset");
	HX_STACK_LINE(217)
	{
		::cocktail::core::css::CSSKeywordValue _switch_1 = (elementRenderer->coreStyle->getKeyword(elementRenderer->coreStyle->getComputedOrInitialProperty((int)2)));
		switch((_switch_1)->GetIndex()){
			case 11: {
				HX_STACK_LINE(221)
				::cocktail::core::geom::RectangleVO floatBounds = this->getLeftFloatBounds(elementRenderer,floatY,containingBlockWidth,containingBlockXOffset);		HX_STACK_VAR(floatBounds,"floatBounds");
				HX_STACK_LINE(222)
				this->floats->left->push(::cocktail::core::layout::FloatVO_obj::__new(elementRenderer,floatBounds));
				HX_STACK_LINE(223)
				this->hasFloats = true;
				HX_STACK_LINE(224)
				return floatBounds;
			}
			;break;
			case 12: {
				HX_STACK_LINE(227)
				::cocktail::core::geom::RectangleVO floatBounds = this->getRightFloatBounds(elementRenderer,floatY,containingBlockWidth,containingBlockXOffset);		HX_STACK_VAR(floatBounds,"floatBounds");
				HX_STACK_LINE(228)
				this->floats->right->push(::cocktail::core::layout::FloatVO_obj::__new(elementRenderer,floatBounds));
				HX_STACK_LINE(229)
				this->hasFloats = true;
				HX_STACK_LINE(230)
				return floatBounds;
			}
			;break;
			default: {
				HX_STACK_LINE(232)
				hx::Throw (HX_CSTRING("Illegal value for float style"));
			}
		}
	}
	HX_STACK_LINE(217)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FloatsManager_obj,registerFloat,return )

bool FloatsManager_obj::doGetHasClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY,Array< ::cocktail::core::layout::FloatVO > floats){
	HX_STACK_PUSH("FloatsManager::doGetHasClearance","cocktail/core/layout/floats/FloatsManager.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_ARG(floats,"floats");
	HX_STACK_LINE(194)
	int length = floats->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(195)
	{
		HX_STACK_LINE(195)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(195)
		while(((_g < length))){
			HX_STACK_LINE(195)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(197)
			::cocktail::core::geom::RectangleVO floatBounds = floats->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
			HX_STACK_LINE(198)
			if (((bool(((floatBounds->y + floatBounds->height) >= currentY)) || bool((bool((floatBounds->y <= currentY)) && bool(((floatBounds->y + floatBounds->height) > currentY))))))){
				HX_STACK_LINE(200)
				return true;
			}
		}
	}
	HX_STACK_LINE(205)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,doGetHasClearance,return )

Float FloatsManager_obj::doGetClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY,Array< ::cocktail::core::layout::FloatVO > floats){
	HX_STACK_PUSH("FloatsManager::doGetClearance","cocktail/core/layout/floats/FloatsManager.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_ARG(floats,"floats");
	HX_STACK_LINE(174)
	Float clearance = (int)0;		HX_STACK_VAR(clearance,"clearance");
	HX_STACK_LINE(176)
	Float maxY = currentY;		HX_STACK_VAR(maxY,"maxY");
	HX_STACK_LINE(178)
	int length = floats->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(179)
	{
		HX_STACK_LINE(179)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(179)
		while(((_g < length))){
			HX_STACK_LINE(179)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(181)
			::cocktail::core::geom::RectangleVO floatBounds = floats->__get(i)->bounds;		HX_STACK_VAR(floatBounds,"floatBounds");
			HX_STACK_LINE(182)
			if (((bool(((floatBounds->y + floatBounds->height) >= maxY)) || bool((bool((floatBounds->y <= maxY)) && bool(((floatBounds->y + floatBounds->height) > maxY))))))){
				HX_STACK_LINE(184)
				maxY = (floatBounds->y + floatBounds->height);
			}
		}
	}
	HX_STACK_LINE(189)
	return (maxY - currentY);
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,doGetClearance,return )

bool FloatsManager_obj::hasClearanceBoth( ::cocktail::core::renderer::ElementRenderer target,Float currentY){
	HX_STACK_PUSH("FloatsManager::hasClearanceBoth","cocktail/core/layout/floats/FloatsManager.hx",161);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_LINE(162)
	bool hasLeftClearance = this->doGetHasClearance(target,currentY,this->floats->left);		HX_STACK_VAR(hasLeftClearance,"hasLeftClearance");
	HX_STACK_LINE(164)
	if (((hasLeftClearance == true))){
		HX_STACK_LINE(165)
		return true;
	}
	HX_STACK_LINE(169)
	return this->doGetHasClearance(target,currentY,this->floats->right);
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,hasClearanceBoth,return )

Float FloatsManager_obj::clearBoth( ::cocktail::core::renderer::ElementRenderer target,Float currentY){
	HX_STACK_PUSH("FloatsManager::clearBoth","cocktail/core/layout/floats/FloatsManager.hx",144);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_LINE(145)
	Float leftClearance = this->doGetClearance(target,currentY,this->floats->left);		HX_STACK_VAR(leftClearance,"leftClearance");
	HX_STACK_LINE(146)
	Float rightClearance = this->doGetClearance(target,currentY,this->floats->right);		HX_STACK_VAR(rightClearance,"rightClearance");
	HX_STACK_LINE(150)
	if (((leftClearance > rightClearance))){
		HX_STACK_LINE(151)
		return leftClearance;
	}
	else{
		HX_STACK_LINE(155)
		return rightClearance;
	}
	HX_STACK_LINE(150)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,clearBoth,return )

bool FloatsManager_obj::hasClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY){
	HX_STACK_PUSH("FloatsManager::hasClearance","cocktail/core/layout/floats/FloatsManager.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_LINE(120)
	bool hasClearance = false;		HX_STACK_VAR(hasClearance,"hasClearance");
	HX_STACK_LINE(122)
	{
		::cocktail::core::css::CSSKeywordValue _switch_2 = (target->coreStyle->getKeyword(target->coreStyle->getComputedOrInitialProperty((int)3)));
		switch((_switch_2)->GetIndex()){
			case 11: {
				HX_STACK_LINE(125)
				hasClearance = this->doGetHasClearance(target,currentY,this->floats->left);
			}
			;break;
			case 12: {
				HX_STACK_LINE(128)
				hasClearance = this->doGetHasClearance(target,currentY,this->floats->right);
			}
			;break;
			case 31: {
				HX_STACK_LINE(131)
				hasClearance = this->hasClearanceBoth(target,currentY);
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(137)
	return hasClearance;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,hasClearance,return )

Float FloatsManager_obj::getClearance( ::cocktail::core::renderer::ElementRenderer target,Float currentY){
	HX_STACK_PUSH("FloatsManager::getClearance","cocktail/core/layout/floats/FloatsManager.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(currentY,"currentY");
	HX_STACK_LINE(98)
	Float clearance = (int)0;		HX_STACK_VAR(clearance,"clearance");
	HX_STACK_LINE(100)
	{
		::cocktail::core::css::CSSKeywordValue _switch_3 = (target->coreStyle->getKeyword(target->coreStyle->getComputedOrInitialProperty((int)3)));
		switch((_switch_3)->GetIndex()){
			case 11: {
				HX_STACK_LINE(103)
				clearance = this->doGetClearance(target,currentY,this->floats->left);
			}
			;break;
			case 12: {
				HX_STACK_LINE(106)
				clearance = this->doGetClearance(target,currentY,this->floats->right);
			}
			;break;
			case 31: {
				HX_STACK_LINE(109)
				clearance = this->clearBoth(target,currentY);
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(115)
	return clearance;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,getClearance,return )

Void FloatsManager_obj::registerClear( ::cocktail::core::renderer::ElementRenderer elementRenderer){
{
		HX_STACK_PUSH("FloatsManager::registerClear","cocktail/core/layout/floats/FloatsManager.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_LINE(86)
		this->childrenWithClearance->push(elementRenderer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,registerClear,(void))

Void FloatsManager_obj::init( ){
{
		HX_STACK_PUSH("FloatsManager::init","cocktail/core/layout/floats/FloatsManager.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_LINE(76)
		if (((bool((this->floats->left->length > (int)0)) || bool((this->floats->right->length > (int)0))))){
			HX_STACK_LINE(78)
			this->floats->left = ::cocktail::core::utils::Utils_obj::clear(this->floats->left);
			HX_STACK_LINE(79)
			this->floats->right = ::cocktail::core::utils::Utils_obj::clear(this->floats->right);
			HX_STACK_LINE(80)
			this->hasFloats = false;
		}
		HX_STACK_LINE(82)
		this->childrenWithClearance = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FloatsManager_obj,init,(void))


FloatsManager_obj::FloatsManager_obj()
{
}

void FloatsManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatsManager);
	HX_MARK_MEMBER_NAME(hasFloats,"hasFloats");
	HX_MARK_MEMBER_NAME(childrenWithClearance,"childrenWithClearance");
	HX_MARK_MEMBER_NAME(floats,"floats");
	HX_MARK_END_CLASS();
}

void FloatsManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hasFloats,"hasFloats");
	HX_VISIT_MEMBER_NAME(childrenWithClearance,"childrenWithClearance");
	HX_VISIT_MEMBER_NAME(floats,"floats");
}

Dynamic FloatsManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"floats") ) { return floats; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"clearBoth") ) { return clearBoth_dyn(); }
		if (HX_FIELD_EQ(inName,"hasFloats") ) { return hasFloats; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_floats") ) { return set_floats_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hasClearance") ) { return hasClearance_dyn(); }
		if (HX_FIELD_EQ(inName,"getClearance") ) { return getClearance_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"registerFloat") ) { return registerFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"registerClear") ) { return registerClear_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFloatBounds") ) { return getFloatBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetClearance") ) { return doGetClearance_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"canFitElementAtY") ) { return canFitElementAtY_dyn(); }
		if (HX_FIELD_EQ(inName,"hasClearanceBoth") ) { return hasClearanceBoth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"doGetHasClearance") ) { return doGetHasClearance_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getLeftFloatOffset") ) { return getLeftFloatOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeftFloatBounds") ) { return getLeftFloatBounds_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getRightFloatOffset") ) { return getRightFloatOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"getRightFloatBounds") ) { return getRightFloatBounds_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"childrenWithClearance") ) { return childrenWithClearance; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getFirstAvailableYPosition") ) { return getFirstAvailableYPosition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatsManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"floats") ) { if (inCallProp) return set_floats(inValue);floats=inValue.Cast< ::cocktail::core::layout::FloatsVO >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasFloats") ) { hasFloats=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"childrenWithClearance") ) { childrenWithClearance=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatsManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hasFloats"));
	outFields->push(HX_CSTRING("childrenWithClearance"));
	outFields->push(HX_CSTRING("floats"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_floats"),
	HX_CSTRING("getRightFloatOffset"),
	HX_CSTRING("getLeftFloatOffset"),
	HX_CSTRING("canFitElementAtY"),
	HX_CSTRING("getFirstAvailableYPosition"),
	HX_CSTRING("getFloatBounds"),
	HX_CSTRING("getRightFloatBounds"),
	HX_CSTRING("getLeftFloatBounds"),
	HX_CSTRING("registerFloat"),
	HX_CSTRING("doGetHasClearance"),
	HX_CSTRING("doGetClearance"),
	HX_CSTRING("hasClearanceBoth"),
	HX_CSTRING("clearBoth"),
	HX_CSTRING("hasClearance"),
	HX_CSTRING("getClearance"),
	HX_CSTRING("registerClear"),
	HX_CSTRING("init"),
	HX_CSTRING("hasFloats"),
	HX_CSTRING("childrenWithClearance"),
	HX_CSTRING("floats"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatsManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatsManager_obj::__mClass,"__mClass");
};

Class FloatsManager_obj::__mClass;

void FloatsManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.floats.FloatsManager"), hx::TCanCast< FloatsManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FloatsManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace floats
