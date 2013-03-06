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
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace layer{

Void ScrollableView_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("ScrollableView::new","cocktail/core/layer/ScrollableView.hx",138);
{
	HX_STACK_LINE(139)
	super::__construct();
	HX_STACK_LINE(140)
	this->rootElementRenderer = rootElementRenderer;
	HX_STACK_LINE(142)
	this->set_scrollLeft((int)0);
	HX_STACK_LINE(143)
	this->set_scrollTop((int)0);
	HX_STACK_LINE(145)
	this->_previousScrollOffsetX = (int)0;
	HX_STACK_LINE(146)
	this->_previousScrollOffsetY = (int)0;
	HX_STACK_LINE(147)
	this->_ancestorsScrollOffset = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(148)
	this->scrollOffset = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(149)
	this->bounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(150)
	this->_clippedBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(151)
	this->scrollableBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(152)
	this->clipRect = ::cocktail::core::geom::RectangleVO_obj::__new();
}
;
	return null();
}

ScrollableView_obj::~ScrollableView_obj() { }

Dynamic ScrollableView_obj::__CreateEmpty() { return  new ScrollableView_obj; }
hx::ObjectPtr< ScrollableView_obj > ScrollableView_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< ScrollableView_obj > result = new ScrollableView_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic ScrollableView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScrollableView_obj > result = new ScrollableView_obj();
	result->__construct(inArgs[0]);
	return result;}

bool ScrollableView_obj::treatVisibleOverflowAsAuto( ){
	HX_STACK_PUSH("ScrollableView::treatVisibleOverflowAsAuto","cocktail/core/layer/ScrollableView.hx",930);
	HX_STACK_THIS(this);
	HX_STACK_LINE(930)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,treatVisibleOverflowAsAuto,return )

bool ScrollableView_obj::isYAxisClipped( ){
	HX_STACK_PUSH("ScrollableView::isYAxisClipped","cocktail/core/layer/ScrollableView.hx",881);
	HX_STACK_THIS(this);
	HX_STACK_LINE(883)
	if (((this->rootElementRenderer->isBlockContainer == false))){
		HX_STACK_LINE(884)
		return false;
	}
	HX_STACK_LINE(889)
	if (((this->rootElementRenderer->coreStyle->canAlwaysOverflow == true))){
		HX_STACK_LINE(890)
		return false;
	}
	HX_STACK_LINE(895)
	if (((this->rootElementRenderer->coreStyle->hasHiddenOrScrollOverflowY == true))){
		HX_STACK_LINE(896)
		return true;
	}
	HX_STACK_LINE(900)
	{
		::cocktail::core::css::CSSKeywordValue _switch_1 = (this->rootElementRenderer->coreStyle->getKeyword(this->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)52)));
		switch((_switch_1)->GetIndex()){
			case 37: case 38: {
				HX_STACK_LINE(902)
				return true;
			}
			;break;
			case 27: {
				HX_STACK_LINE(905)
				return false;
			}
			;break;
			case 36: {
				HX_STACK_LINE(909)
				if (((this->treatVisibleOverflowAsAuto() == true))){
					HX_STACK_LINE(910)
					return false;
				}
				HX_STACK_LINE(913)
				return false;
			}
			;break;
			default: {
				HX_STACK_LINE(915)
				return false;
			}
		}
	}
	HX_STACK_LINE(900)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,isYAxisClipped,return )

bool ScrollableView_obj::isXAxisClipped( ){
	HX_STACK_PUSH("ScrollableView::isXAxisClipped","cocktail/core/layer/ScrollableView.hx",833);
	HX_STACK_THIS(this);
	HX_STACK_LINE(835)
	if (((this->rootElementRenderer->isBlockContainer == false))){
		HX_STACK_LINE(836)
		return false;
	}
	HX_STACK_LINE(841)
	if (((this->rootElementRenderer->coreStyle->canAlwaysOverflow == true))){
		HX_STACK_LINE(842)
		return false;
	}
	HX_STACK_LINE(847)
	if (((this->rootElementRenderer->coreStyle->hasHiddenOrScrollOverflowX == true))){
		HX_STACK_LINE(848)
		return true;
	}
	HX_STACK_LINE(852)
	{
		::cocktail::core::css::CSSKeywordValue _switch_2 = (this->rootElementRenderer->coreStyle->getKeyword(this->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)51)));
		switch((_switch_2)->GetIndex()){
			case 37: case 38: {
				HX_STACK_LINE(854)
				return true;
			}
			;break;
			case 27: {
				HX_STACK_LINE(859)
				return false;
			}
			;break;
			case 36: {
				HX_STACK_LINE(865)
				if (((this->treatVisibleOverflowAsAuto() == true))){
					HX_STACK_LINE(866)
					return false;
				}
				HX_STACK_LINE(869)
				return false;
			}
			;break;
			default: {
				HX_STACK_LINE(871)
				return false;
			}
		}
	}
	HX_STACK_LINE(852)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,isXAxisClipped,return )

bool ScrollableView_obj::isContainingBlockChildren( Dynamic layer){
	HX_STACK_PUSH("ScrollableView::isContainingBlockChildren","cocktail/core/layer/ScrollableView.hx",803);
	HX_STACK_THIS(this);
	HX_STACK_ARG(layer,"layer");
	HX_STACK_LINE(804)
	::cocktail::core::renderer::ElementRenderer containingBlock = this->rootElementRenderer->containingBlock;		HX_STACK_VAR(containingBlock,"containingBlock");
	HX_STACK_LINE(806)
	::cocktail::core::renderer::ElementRenderer layerContainingBlock = layer->__Field(HX_CSTRING("rootElementRenderer"),true)->__Field(HX_CSTRING("containingBlock"),true);		HX_STACK_VAR(layerContainingBlock,"layerContainingBlock");
	HX_STACK_LINE(808)
	if (((containingBlock == layerContainingBlock))){
		HX_STACK_LINE(809)
		return false;
	}
	HX_STACK_LINE(813)
	::cocktail::core::renderer::ElementRenderer parent = layerContainingBlock;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(815)
	while(((parent != null()))){
		HX_STACK_LINE(817)
		if (((parent == containingBlock))){
			HX_STACK_LINE(818)
			return true;
		}
		HX_STACK_LINE(822)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(825)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(ScrollableView_obj,isContainingBlockChildren,return )

Void ScrollableView_obj::scrollChanged( ){
{
		HX_STACK_PUSH("ScrollableView::scrollChanged","cocktail/core/layer/ScrollableView.hx",794);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,scrollChanged,(void))

Float ScrollableView_obj::set_scrollTop( Float value){
	HX_STACK_PUSH("ScrollableView::set_scrollTop","cocktail/core/layer/ScrollableView.hx",732);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(733)
	if (((this->isYAxisClipped() == false))){
		HX_STACK_LINE(734)
		return this->scrollTop = (int)0;
	}
	HX_STACK_LINE(738)
	if (((value <= (int)0))){
		HX_STACK_LINE(740)
		if (((this->scrollTop > (int)0))){
			HX_STACK_LINE(741)
			this->scrollChanged();
		}
		HX_STACK_LINE(744)
		this->scrollTop = (int)0;
	}
	else{
		HX_STACK_LINE(748)
		Float maxHeightScroll = (this->scrollableBounds->height - this->_clippedBounds->height);		HX_STACK_VAR(maxHeightScroll,"maxHeightScroll");
		HX_STACK_LINE(750)
		if (((maxHeightScroll <= (int)0))){
			HX_STACK_LINE(752)
			if (((this->scrollTop != (int)0))){
				HX_STACK_LINE(753)
				this->scrollChanged();
			}
			HX_STACK_LINE(757)
			this->scrollTop = (int)0;
		}
		else{
			HX_STACK_LINE(760)
			if (((value > maxHeightScroll))){
				HX_STACK_LINE(763)
				if (((this->scrollTop != maxHeightScroll))){
					HX_STACK_LINE(764)
					this->scrollChanged();
				}
				HX_STACK_LINE(768)
				this->scrollTop = maxHeightScroll;
			}
			else{
				HX_STACK_LINE(772)
				if (((this->scrollTop != value))){
					HX_STACK_LINE(773)
					this->scrollChanged();
				}
				HX_STACK_LINE(777)
				this->scrollTop = value;
			}
		}
	}
	HX_STACK_LINE(782)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ScrollableView_obj,set_scrollTop,return )

Float ScrollableView_obj::set_scrollLeft( Float value){
	HX_STACK_PUSH("ScrollableView::set_scrollLeft","cocktail/core/layer/ScrollableView.hx",670);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(673)
	if (((this->isXAxisClipped() == false))){
		HX_STACK_LINE(674)
		return this->scrollLeft = (int)0;
	}
	HX_STACK_LINE(679)
	if (((value <= (int)0))){
		HX_STACK_LINE(681)
		if (((this->scrollLeft > (int)0))){
			HX_STACK_LINE(682)
			this->scrollChanged();
		}
		HX_STACK_LINE(685)
		this->scrollLeft = (int)0;
	}
	else{
		HX_STACK_LINE(690)
		Float maxWidthScroll = (this->scrollableBounds->width - this->_clippedBounds->width);		HX_STACK_VAR(maxWidthScroll,"maxWidthScroll");
		HX_STACK_LINE(694)
		if (((maxWidthScroll <= (int)0))){
			HX_STACK_LINE(696)
			if (((this->scrollLeft != (int)0))){
				HX_STACK_LINE(697)
				this->scrollChanged();
			}
			HX_STACK_LINE(701)
			this->scrollLeft = (int)0;
		}
		else{
			HX_STACK_LINE(706)
			if (((value > maxWidthScroll))){
				HX_STACK_LINE(709)
				if (((this->scrollLeft != maxWidthScroll))){
					HX_STACK_LINE(710)
					this->scrollChanged();
				}
				HX_STACK_LINE(714)
				this->scrollLeft = maxWidthScroll;
			}
			else{
				HX_STACK_LINE(718)
				if (((this->scrollLeft != value))){
					HX_STACK_LINE(719)
					this->scrollChanged();
				}
				HX_STACK_LINE(723)
				this->scrollLeft = value;
			}
		}
	}
	HX_STACK_LINE(728)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ScrollableView_obj,set_scrollLeft,return )

Void ScrollableView_obj::doGetScrollableBounds( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO scrollableBounds,Dynamic referenceLayer,bool getHorizontalBounds,bool getVerticalBounds){
{
		HX_STACK_PUSH("ScrollableView::doGetScrollableBounds","cocktail/core/layer/ScrollableView.hx",619);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayerRenderer,"rootLayerRenderer");
		HX_STACK_ARG(scrollableBounds,"scrollableBounds");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(getHorizontalBounds,"getHorizontalBounds");
		HX_STACK_ARG(getVerticalBounds,"getVerticalBounds");
		HX_STACK_LINE(621)
		Dynamic child = rootLayerRenderer->__Field(HX_CSTRING("firstChild"),true);		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(622)
		while(((child != null()))){
			HX_STACK_LINE(625)
			::cocktail::core::geom::RectangleVO childBounds = child->__Field(HX_CSTRING("getScrollableBoundsIfNeeded"),true)(referenceLayer);		HX_STACK_VAR(childBounds,"childBounds");
			HX_STACK_LINE(630)
			if (((childBounds != null()))){
				HX_STACK_LINE(633)
				{
					HX_STACK_LINE(633)
					if (((getHorizontalBounds == true))){
						HX_STACK_LINE(633)
						if (((childBounds->x < scrollableBounds->x))){
							HX_STACK_LINE(633)
							scrollableBounds->x = childBounds->x;
						}
						HX_STACK_LINE(633)
						if ((((childBounds->x + childBounds->width) > (scrollableBounds->x + scrollableBounds->width)))){
							HX_STACK_LINE(633)
							scrollableBounds->width = ((childBounds->x + childBounds->width) - scrollableBounds->x);
						}
					}
					HX_STACK_LINE(633)
					if (((getVerticalBounds == true))){
						HX_STACK_LINE(633)
						if (((childBounds->y < scrollableBounds->y))){
							HX_STACK_LINE(633)
							scrollableBounds->y = childBounds->y;
						}
						HX_STACK_LINE(633)
						if ((((childBounds->y + childBounds->height) > (scrollableBounds->y + scrollableBounds->height)))){
							HX_STACK_LINE(633)
							scrollableBounds->height = ((childBounds->y + childBounds->height) - scrollableBounds->y);
						}
					}
				}
				HX_STACK_LINE(635)
				if (((child->__Field(HX_CSTRING("firstChild"),true) != null()))){
					HX_STACK_LINE(641)
					if (((child->__Field(HX_CSTRING("isXAxisClipped"),true)() == true))){
						HX_STACK_LINE(642)
						getHorizontalBounds = false;
					}
					HX_STACK_LINE(647)
					if (((child->__Field(HX_CSTRING("isYAxisClipped"),true)() == true))){
						HX_STACK_LINE(648)
						getVerticalBounds = false;
					}
					HX_STACK_LINE(654)
					if (((bool((getHorizontalBounds == true)) || bool((getVerticalBounds == true))))){
						HX_STACK_LINE(655)
						this->doGetScrollableBounds(child,scrollableBounds,referenceLayer,getHorizontalBounds,getVerticalBounds);
					}
				}
			}
			HX_STACK_LINE(661)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ScrollableView_obj,doGetScrollableBounds,(void))

Void ScrollableView_obj::getScrollableBounds( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO scrollableBounds){
{
		HX_STACK_PUSH("ScrollableView::getScrollableBounds","cocktail/core/layer/ScrollableView.hx",597);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayerRenderer,"rootLayerRenderer");
		HX_STACK_ARG(scrollableBounds,"scrollableBounds");
		HX_STACK_LINE(598)
		scrollableBounds->x = (int)50000;
		HX_STACK_LINE(599)
		scrollableBounds->y = (int)50000;
		HX_STACK_LINE(600)
		scrollableBounds->width = (int)0;
		HX_STACK_LINE(601)
		scrollableBounds->height = (int)0;
		HX_STACK_LINE(604)
		{
			HX_STACK_LINE(604)
			::cocktail::core::geom::RectangleVO addedBounds = this->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
			bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
			bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
			HX_STACK_LINE(604)
			if (((getHorizontalBounds == true))){
				HX_STACK_LINE(604)
				if (((addedBounds->x < scrollableBounds->x))){
					HX_STACK_LINE(604)
					scrollableBounds->x = addedBounds->x;
				}
				HX_STACK_LINE(604)
				if ((((addedBounds->x + addedBounds->width) > (scrollableBounds->x + scrollableBounds->width)))){
					HX_STACK_LINE(604)
					scrollableBounds->width = ((addedBounds->x + addedBounds->width) - scrollableBounds->x);
				}
			}
			HX_STACK_LINE(604)
			if (((getVerticalBounds == true))){
				HX_STACK_LINE(604)
				if (((addedBounds->y < scrollableBounds->y))){
					HX_STACK_LINE(604)
					scrollableBounds->y = addedBounds->y;
				}
				HX_STACK_LINE(604)
				if ((((addedBounds->y + addedBounds->height) > (scrollableBounds->y + scrollableBounds->height)))){
					HX_STACK_LINE(604)
					scrollableBounds->height = ((addedBounds->y + addedBounds->height) - scrollableBounds->y);
				}
			}
		}
		HX_STACK_LINE(607)
		this->doGetScrollableBounds(rootLayerRenderer,scrollableBounds,hx::ObjectPtr<OBJ_>(this),true,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ScrollableView_obj,getScrollableBounds,(void))

::cocktail::core::geom::RectangleVO ScrollableView_obj::getScrollableBoundsIfNeeded( Dynamic layer){
	HX_STACK_PUSH("ScrollableView::getScrollableBoundsIfNeeded","cocktail/core/layer/ScrollableView.hx",563);
	HX_STACK_THIS(this);
	HX_STACK_ARG(layer,"layer");
	HX_STACK_LINE(566)
	if (((this->rootElementRenderer->coreStyle->isFixedPositioned == true))){
		HX_STACK_LINE(567)
		return null();
	}
	HX_STACK_LINE(574)
	if (((this->isContainingBlockChildren(layer) == true))){
		HX_STACK_LINE(575)
		return null();
	}
	HX_STACK_LINE(580)
	if (((this->isXAxisClipped() == false))){
		HX_STACK_LINE(581)
		if (((this->isYAxisClipped() == false))){
			HX_STACK_LINE(583)
			return this->bounds;
		}
	}
	HX_STACK_LINE(589)
	return this->_clippedBounds;
}


HX_DEFINE_DYNAMIC_FUNC1(ScrollableView_obj,getScrollableBoundsIfNeeded,return )

Void ScrollableView_obj::updateScrollableBounds( ){
{
		HX_STACK_PUSH("ScrollableView::updateScrollableBounds","cocktail/core/layer/ScrollableView.hx",541);
		HX_STACK_THIS(this);
		HX_STACK_LINE(542)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(545)
		this->getScrollableBounds(hx::ObjectPtr<OBJ_>(this),this->scrollableBounds);
		HX_STACK_LINE(548)
		while(((child != null()))){
			HX_STACK_LINE(550)
			child->__Field(HX_CSTRING("updateScrollableBounds"),true)();
			HX_STACK_LINE(551)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,updateScrollableBounds,(void))

Void ScrollableView_obj::doGetElementRenderersBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ScrollableView::doGetElementRenderersBounds","cocktail/core/layer/ScrollableView.hx",501);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(504)
		::cocktail::core::layer::LayerRenderer thisAsLayer = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(thisAsLayer,"thisAsLayer");
		HX_STACK_LINE(506)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(507)
		while(((child != null()))){
			HX_STACK_LINE(512)
			if (((child->isText == false))){
				HX_STACK_LINE(513)
				if (((child->layerRenderer == thisAsLayer))){
					HX_STACK_LINE(518)
					{
						HX_STACK_LINE(518)
						::cocktail::core::geom::RectangleVO addedBounds = child->globalBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
						bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
						bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
						HX_STACK_LINE(518)
						if (((getHorizontalBounds == true))){
							HX_STACK_LINE(518)
							if (((addedBounds->x < bounds->x))){
								HX_STACK_LINE(518)
								bounds->x = addedBounds->x;
							}
							HX_STACK_LINE(518)
							if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
								HX_STACK_LINE(518)
								bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
							}
						}
						HX_STACK_LINE(518)
						if (((getVerticalBounds == true))){
							HX_STACK_LINE(518)
							if (((addedBounds->y < bounds->y))){
								HX_STACK_LINE(518)
								bounds->y = addedBounds->y;
							}
							HX_STACK_LINE(518)
							if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
								HX_STACK_LINE(518)
								bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
							}
						}
					}
					HX_STACK_LINE(519)
					if (((child->firstChild != null()))){
						HX_STACK_LINE(520)
						this->doGetElementRenderersBounds(child,bounds);
					}
				}
			}
			HX_STACK_LINE(527)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ScrollableView_obj,doGetElementRenderersBounds,(void))

Void ScrollableView_obj::getElementRenderersBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ScrollableView::getElementRenderersBounds","cocktail/core/layer/ScrollableView.hx",481);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(483)
		bounds->x = (int)50000;
		HX_STACK_LINE(484)
		bounds->y = (int)50000;
		HX_STACK_LINE(485)
		bounds->width = (int)0;
		HX_STACK_LINE(486)
		bounds->height = (int)0;
		HX_STACK_LINE(489)
		{
			HX_STACK_LINE(489)
			::cocktail::core::geom::RectangleVO addedBounds = rootElementRenderer->globalBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
			bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
			bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
			HX_STACK_LINE(489)
			if (((getHorizontalBounds == true))){
				HX_STACK_LINE(489)
				if (((addedBounds->x < bounds->x))){
					HX_STACK_LINE(489)
					bounds->x = addedBounds->x;
				}
				HX_STACK_LINE(489)
				if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
					HX_STACK_LINE(489)
					bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
				}
			}
			HX_STACK_LINE(489)
			if (((getVerticalBounds == true))){
				HX_STACK_LINE(489)
				if (((addedBounds->y < bounds->y))){
					HX_STACK_LINE(489)
					bounds->y = addedBounds->y;
				}
				HX_STACK_LINE(489)
				if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
					HX_STACK_LINE(489)
					bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
				}
			}
		}
		HX_STACK_LINE(492)
		this->doGetElementRenderersBounds(rootElementRenderer,bounds);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ScrollableView_obj,getElementRenderersBounds,(void))

Void ScrollableView_obj::updateClippedBounds( ){
{
		HX_STACK_PUSH("ScrollableView::updateClippedBounds","cocktail/core/layer/ScrollableView.hx",436);
		HX_STACK_THIS(this);
		HX_STACK_LINE(437)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(442)
		Float x = this->bounds->x;		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(443)
		Float y = this->bounds->y;		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(444)
		Float width = this->bounds->width;		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(445)
		Float height = this->bounds->height;		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(449)
		if (((this->isXAxisClipped() == true))){
			HX_STACK_LINE(451)
			x = this->rootElementRenderer->globalBounds->x;
			HX_STACK_LINE(452)
			width = this->rootElementRenderer->globalBounds->width;
		}
		HX_STACK_LINE(456)
		if (((this->isYAxisClipped() == true))){
			HX_STACK_LINE(458)
			y = this->rootElementRenderer->globalBounds->y;
			HX_STACK_LINE(459)
			height = this->rootElementRenderer->globalBounds->height;
		}
		HX_STACK_LINE(462)
		this->_clippedBounds->x = x;
		HX_STACK_LINE(463)
		this->_clippedBounds->y = y;
		HX_STACK_LINE(464)
		this->_clippedBounds->width = width;
		HX_STACK_LINE(465)
		this->_clippedBounds->height = height;
		HX_STACK_LINE(468)
		while(((child != null()))){
			HX_STACK_LINE(470)
			child->__Field(HX_CSTRING("updateClippedBounds"),true)();
			HX_STACK_LINE(471)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,updateClippedBounds,(void))

Void ScrollableView_obj::updateBounds( ){
{
		HX_STACK_PUSH("ScrollableView::updateBounds","cocktail/core/layer/ScrollableView.hx",414);
		HX_STACK_THIS(this);
		HX_STACK_LINE(415)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(418)
		this->getElementRenderersBounds(this->rootElementRenderer,this->bounds);
		HX_STACK_LINE(421)
		while(((child != null()))){
			HX_STACK_LINE(423)
			child->__Field(HX_CSTRING("updateBounds"),true)();
			HX_STACK_LINE(424)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,updateBounds,(void))

Void ScrollableView_obj::addScrollOffsetToChildren( Dynamic rootLayerRenderer,Float scrollLeft,Float scrollTop,Dynamic referenceLayer){
{
		HX_STACK_PUSH("ScrollableView::addScrollOffsetToChildren","cocktail/core/layer/ScrollableView.hx",387);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayerRenderer,"rootLayerRenderer");
		HX_STACK_ARG(scrollLeft,"scrollLeft");
		HX_STACK_ARG(scrollTop,"scrollTop");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_LINE(389)
		Dynamic child = rootLayerRenderer->__Field(HX_CSTRING("firstChild"),true);		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(390)
		while(((child != null()))){
			HX_STACK_LINE(393)
			child->__Field(HX_CSTRING("addScrollOffsetIfNeeded"),true)(referenceLayer,scrollLeft,scrollTop);
			HX_STACK_LINE(395)
			if (((child->__Field(HX_CSTRING("firstChild"),true) != null()))){
				HX_STACK_LINE(396)
				this->addScrollOffsetToChildren(child,scrollLeft,scrollTop,referenceLayer);
			}
			HX_STACK_LINE(400)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ScrollableView_obj,addScrollOffsetToChildren,(void))

Void ScrollableView_obj::addScrollOffsetIfNeeded( Dynamic layer,Float scrollLeft,Float scrollTop){
{
		HX_STACK_PUSH("ScrollableView::addScrollOffsetIfNeeded","cocktail/core/layer/ScrollableView.hx",357);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layer,"layer");
		HX_STACK_ARG(scrollLeft,"scrollLeft");
		HX_STACK_ARG(scrollTop,"scrollTop");
		HX_STACK_LINE(360)
		if (((this->rootElementRenderer->coreStyle->isFixedPositioned == true))){
			HX_STACK_LINE(361)
			return null();
		}
		HX_STACK_LINE(366)
		if (((this->isContainingBlockChildren(layer) == true))){
			HX_STACK_LINE(367)
			return null();
		}
		HX_STACK_LINE(372)
		hx::AddEq(this->_ancestorsScrollOffset->x,scrollLeft);
		HX_STACK_LINE(373)
		hx::AddEq(this->_ancestorsScrollOffset->y,scrollTop);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ScrollableView_obj,addScrollOffsetIfNeeded,(void))

Void ScrollableView_obj::updateScrollOffset( ){
{
		HX_STACK_PUSH("ScrollableView::updateScrollOffset","cocktail/core/layer/ScrollableView.hx",323);
		HX_STACK_THIS(this);
		HX_STACK_LINE(327)
		if (((this->isXAxisClipped() == true))){
			HX_STACK_LINE(328)
			this->addScrollOffsetToChildren(hx::ObjectPtr<OBJ_>(this),this->scrollLeft,this->scrollTop,hx::ObjectPtr<OBJ_>(this));
		}
		else{
			HX_STACK_LINE(332)
			if (((this->isYAxisClipped() == true))){
				HX_STACK_LINE(333)
				this->addScrollOffsetToChildren(hx::ObjectPtr<OBJ_>(this),this->scrollLeft,this->scrollTop,hx::ObjectPtr<OBJ_>(this));
			}
		}
		HX_STACK_LINE(339)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(340)
		while(((child != null()))){
			HX_STACK_LINE(342)
			child->__Field(HX_CSTRING("updateScrollOffset"),true)();
			HX_STACK_LINE(343)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
		HX_STACK_LINE(347)
		this->scrollOffset->x = (this->_ancestorsScrollOffset->x + this->scrollLeft);
		HX_STACK_LINE(348)
		this->scrollOffset->y = (this->_ancestorsScrollOffset->y + this->scrollTop);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,updateScrollOffset,(void))

Void ScrollableView_obj::resetScrollOffset( ){
{
		HX_STACK_PUSH("ScrollableView::resetScrollOffset","cocktail/core/layer/ScrollableView.hx",299);
		HX_STACK_THIS(this);
		HX_STACK_LINE(300)
		this->_ancestorsScrollOffset->x = (int)0;
		HX_STACK_LINE(301)
		this->_ancestorsScrollOffset->y = (int)0;
		HX_STACK_LINE(303)
		this->_previousScrollOffsetX = this->scrollOffset->x;
		HX_STACK_LINE(304)
		this->_previousScrollOffsetY = this->scrollOffset->y;
		HX_STACK_LINE(306)
		this->scrollOffset->x = (int)0;
		HX_STACK_LINE(307)
		this->scrollOffset->y = (int)0;
		HX_STACK_LINE(309)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(310)
		while(((child != null()))){
			HX_STACK_LINE(312)
			child->__Field(HX_CSTRING("resetScrollOffset"),true)();
			HX_STACK_LINE(313)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,resetScrollOffset,(void))

bool ScrollableView_obj::clipIfNeeded( ::cocktail::core::geom::RectangleVO parentClipRect,Dynamic layer){
	HX_STACK_PUSH("ScrollableView::clipIfNeeded","cocktail/core/layer/ScrollableView.hx",270);
	HX_STACK_THIS(this);
	HX_STACK_ARG(parentClipRect,"parentClipRect");
	HX_STACK_ARG(layer,"layer");
	HX_STACK_LINE(273)
	if (((this->rootElementRenderer->coreStyle->isFixedPositioned == true))){
		HX_STACK_LINE(274)
		return false;
	}
	HX_STACK_LINE(279)
	if (((this->isContainingBlockChildren(layer) == true))){
		HX_STACK_LINE(280)
		return false;
	}
	HX_STACK_LINE(286)
	{
		HX_STACK_LINE(286)
		::cocktail::core::geom::RectangleVO bounds1 = this->clipRect;		HX_STACK_VAR(bounds1,"bounds1");
		::cocktail::core::geom::RectangleVO resultBounds = this->clipRect;		HX_STACK_VAR(resultBounds,"resultBounds");
		HX_STACK_LINE(286)
		if (((bool((bool((bool(((bounds1->x + bounds1->width) < parentClipRect->x)) || bool(((parentClipRect->x + parentClipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < parentClipRect->y)))) || bool(((parentClipRect->y + parentClipRect->height) < bounds1->y))))){
			HX_STACK_LINE(286)
			resultBounds->x = (int)0;
			HX_STACK_LINE(286)
			resultBounds->y = (int)0;
			HX_STACK_LINE(286)
			resultBounds->height = (int)0;
			HX_STACK_LINE(286)
			resultBounds->width = (int)0;
		}
		else{
			HX_STACK_LINE(286)
			Float left = (int)0;		HX_STACK_VAR(left,"left");
			HX_STACK_LINE(286)
			Float right = (int)0;		HX_STACK_VAR(right,"right");
			HX_STACK_LINE(286)
			Float top = (int)0;		HX_STACK_VAR(top,"top");
			HX_STACK_LINE(286)
			Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
			HX_STACK_LINE(286)
			if (((bounds1->x < parentClipRect->x))){
				HX_STACK_LINE(286)
				left = parentClipRect->x;
			}
			else{
				HX_STACK_LINE(286)
				left = bounds1->x;
			}
			HX_STACK_LINE(286)
			if ((((bounds1->x + bounds1->width) < (parentClipRect->x + parentClipRect->width)))){
				HX_STACK_LINE(286)
				right = (bounds1->x + bounds1->width);
			}
			else{
				HX_STACK_LINE(286)
				right = (parentClipRect->x + parentClipRect->width);
			}
			HX_STACK_LINE(286)
			if (((bounds1->y < parentClipRect->y))){
				HX_STACK_LINE(286)
				top = parentClipRect->y;
			}
			else{
				HX_STACK_LINE(286)
				top = bounds1->y;
			}
			HX_STACK_LINE(286)
			if ((((bounds1->y + bounds1->height) < (parentClipRect->y + parentClipRect->height)))){
				HX_STACK_LINE(286)
				bottom = (bounds1->y + bounds1->height);
			}
			else{
				HX_STACK_LINE(286)
				bottom = (parentClipRect->y + parentClipRect->height);
			}
			HX_STACK_LINE(286)
			resultBounds->x = left;
			HX_STACK_LINE(286)
			resultBounds->y = top;
			HX_STACK_LINE(286)
			resultBounds->width = (right - left);
			HX_STACK_LINE(286)
			resultBounds->height = (bottom - top);
		}
	}
	HX_STACK_LINE(287)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(ScrollableView_obj,clipIfNeeded,return )

Void ScrollableView_obj::clipChildren( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO clipRect,Dynamic referenceLayer){
{
		HX_STACK_PUSH("ScrollableView::clipChildren","cocktail/core/layer/ScrollableView.hx",235);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayerRenderer,"rootLayerRenderer");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_LINE(237)
		Dynamic child = rootLayerRenderer->__Field(HX_CSTRING("firstChild"),true);		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(238)
		while(((child != null()))){
			HX_STACK_LINE(242)
			bool childWasClipped = child->__Field(HX_CSTRING("clipIfNeeded"),true)(clipRect,referenceLayer);		HX_STACK_VAR(childWasClipped,"childWasClipped");
			HX_STACK_LINE(247)
			if (((childWasClipped == true))){
				HX_STACK_LINE(248)
				if (((child->__Field(HX_CSTRING("firstChild"),true) != null()))){
					HX_STACK_LINE(250)
					this->clipChildren(child,clipRect,referenceLayer);
				}
			}
			HX_STACK_LINE(255)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ScrollableView_obj,clipChildren,(void))

Void ScrollableView_obj::updateClipRect( ){
{
		HX_STACK_PUSH("ScrollableView::updateClipRect","cocktail/core/layer/ScrollableView.hx",185);
		HX_STACK_THIS(this);
		HX_STACK_LINE(187)
		bool clipped = false;		HX_STACK_VAR(clipped,"clipped");
		HX_STACK_LINE(188)
		if (((this->isXAxisClipped() == true))){
			HX_STACK_LINE(189)
			clipped = true;
		}
		else{
			HX_STACK_LINE(192)
			if (((this->isYAxisClipped() == true))){
				HX_STACK_LINE(193)
				clipped = true;
			}
		}
		HX_STACK_LINE(199)
		if (((clipped == true))){
			HX_STACK_LINE(203)
			hx::SubEq(this->_clippedBounds->x,this->_ancestorsScrollOffset->x);
			HX_STACK_LINE(204)
			hx::SubEq(this->_clippedBounds->y,this->_ancestorsScrollOffset->y);
			HX_STACK_LINE(208)
			{
				HX_STACK_LINE(208)
				::cocktail::core::geom::RectangleVO bounds1 = this->clipRect;		HX_STACK_VAR(bounds1,"bounds1");
				::cocktail::core::geom::RectangleVO bounds2 = this->_clippedBounds;		HX_STACK_VAR(bounds2,"bounds2");
				::cocktail::core::geom::RectangleVO resultBounds = this->clipRect;		HX_STACK_VAR(resultBounds,"resultBounds");
				HX_STACK_LINE(208)
				if (((bool((bool((bool(((bounds1->x + bounds1->width) < bounds2->x)) || bool(((bounds2->x + bounds2->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < bounds2->y)))) || bool(((bounds2->y + bounds2->height) < bounds1->y))))){
					HX_STACK_LINE(208)
					resultBounds->x = (int)0;
					HX_STACK_LINE(208)
					resultBounds->y = (int)0;
					HX_STACK_LINE(208)
					resultBounds->height = (int)0;
					HX_STACK_LINE(208)
					resultBounds->width = (int)0;
				}
				else{
					HX_STACK_LINE(208)
					Float left = (int)0;		HX_STACK_VAR(left,"left");
					HX_STACK_LINE(208)
					Float right = (int)0;		HX_STACK_VAR(right,"right");
					HX_STACK_LINE(208)
					Float top = (int)0;		HX_STACK_VAR(top,"top");
					HX_STACK_LINE(208)
					Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
					HX_STACK_LINE(208)
					if (((bounds1->x < bounds2->x))){
						HX_STACK_LINE(208)
						left = bounds2->x;
					}
					else{
						HX_STACK_LINE(208)
						left = bounds1->x;
					}
					HX_STACK_LINE(208)
					if ((((bounds1->x + bounds1->width) < (bounds2->x + bounds2->width)))){
						HX_STACK_LINE(208)
						right = (bounds1->x + bounds1->width);
					}
					else{
						HX_STACK_LINE(208)
						right = (bounds2->x + bounds2->width);
					}
					HX_STACK_LINE(208)
					if (((bounds1->y < bounds2->y))){
						HX_STACK_LINE(208)
						top = bounds2->y;
					}
					else{
						HX_STACK_LINE(208)
						top = bounds1->y;
					}
					HX_STACK_LINE(208)
					if ((((bounds1->y + bounds1->height) < (bounds2->y + bounds2->height)))){
						HX_STACK_LINE(208)
						bottom = (bounds1->y + bounds1->height);
					}
					else{
						HX_STACK_LINE(208)
						bottom = (bounds2->y + bounds2->height);
					}
					HX_STACK_LINE(208)
					resultBounds->x = left;
					HX_STACK_LINE(208)
					resultBounds->y = top;
					HX_STACK_LINE(208)
					resultBounds->width = (right - left);
					HX_STACK_LINE(208)
					resultBounds->height = (bottom - top);
				}
			}
			HX_STACK_LINE(211)
			hx::AddEq(this->_clippedBounds->x,this->_ancestorsScrollOffset->x);
			HX_STACK_LINE(212)
			hx::AddEq(this->_clippedBounds->y,this->_ancestorsScrollOffset->y);
			HX_STACK_LINE(214)
			this->clipChildren(hx::ObjectPtr<OBJ_>(this),this->clipRect,hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(218)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(219)
		while(((child != null()))){
			HX_STACK_LINE(221)
			child->__Field(HX_CSTRING("updateClipRect"),true)();
			HX_STACK_LINE(222)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScrollableView_obj,updateClipRect,(void))

Void ScrollableView_obj::resetClipRect( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("ScrollableView::resetClipRect","cocktail/core/layer/ScrollableView.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(166)
		this->clipRect->x = x;
		HX_STACK_LINE(167)
		this->clipRect->y = y;
		HX_STACK_LINE(168)
		this->clipRect->width = width;
		HX_STACK_LINE(169)
		this->clipRect->height = height;
		HX_STACK_LINE(172)
		Dynamic child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(173)
		while(((child != null()))){
			HX_STACK_LINE(175)
			child->__Field(HX_CSTRING("resetClipRect"),true)(x,y,width,height);
			HX_STACK_LINE(176)
			child = child->__Field(HX_CSTRING("nextSibling"),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ScrollableView_obj,resetClipRect,(void))


ScrollableView_obj::ScrollableView_obj()
{
}

void ScrollableView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScrollableView);
	HX_MARK_MEMBER_NAME(scrollTop,"scrollTop");
	HX_MARK_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_MARK_MEMBER_NAME(clipRect,"clipRect");
	HX_MARK_MEMBER_NAME(scrollableBounds,"scrollableBounds");
	HX_MARK_MEMBER_NAME(_clippedBounds,"_clippedBounds");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(_previousScrollOffsetY,"_previousScrollOffsetY");
	HX_MARK_MEMBER_NAME(_previousScrollOffsetX,"_previousScrollOffsetX");
	HX_MARK_MEMBER_NAME(scrollOffset,"scrollOffset");
	HX_MARK_MEMBER_NAME(_ancestorsScrollOffset,"_ancestorsScrollOffset");
	HX_MARK_MEMBER_NAME(rootElementRenderer,"rootElementRenderer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ScrollableView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scrollTop,"scrollTop");
	HX_VISIT_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_VISIT_MEMBER_NAME(clipRect,"clipRect");
	HX_VISIT_MEMBER_NAME(scrollableBounds,"scrollableBounds");
	HX_VISIT_MEMBER_NAME(_clippedBounds,"_clippedBounds");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(_previousScrollOffsetY,"_previousScrollOffsetY");
	HX_VISIT_MEMBER_NAME(_previousScrollOffsetX,"_previousScrollOffsetX");
	HX_VISIT_MEMBER_NAME(scrollOffset,"scrollOffset");
	HX_VISIT_MEMBER_NAME(_ancestorsScrollOffset,"_ancestorsScrollOffset");
	HX_VISIT_MEMBER_NAME(rootElementRenderer,"rootElementRenderer");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ScrollableView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipRect") ) { return clipRect; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"scrollTop") ) { return scrollTop; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { return scrollLeft; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateBounds") ) { return updateBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"clipIfNeeded") ) { return clipIfNeeded_dyn(); }
		if (HX_FIELD_EQ(inName,"clipChildren") ) { return clipChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"scrollOffset") ) { return scrollOffset; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"scrollChanged") ) { return scrollChanged_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollTop") ) { return set_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"resetClipRect") ) { return resetClipRect_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isYAxisClipped") ) { return isYAxisClipped_dyn(); }
		if (HX_FIELD_EQ(inName,"isXAxisClipped") ) { return isXAxisClipped_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollLeft") ) { return set_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"updateClipRect") ) { return updateClipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"_clippedBounds") ) { return _clippedBounds; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"scrollableBounds") ) { return scrollableBounds; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"resetScrollOffset") ) { return resetScrollOffset_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateScrollOffset") ) { return updateScrollOffset_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getScrollableBounds") ) { return getScrollableBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"updateClippedBounds") ) { return updateClippedBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"rootElementRenderer") ) { return rootElementRenderer; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"doGetScrollableBounds") ) { return doGetScrollableBounds_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateScrollableBounds") ) { return updateScrollableBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"_previousScrollOffsetY") ) { return _previousScrollOffsetY; }
		if (HX_FIELD_EQ(inName,"_previousScrollOffsetX") ) { return _previousScrollOffsetX; }
		if (HX_FIELD_EQ(inName,"_ancestorsScrollOffset") ) { return _ancestorsScrollOffset; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"addScrollOffsetIfNeeded") ) { return addScrollOffsetIfNeeded_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"isContainingBlockChildren") ) { return isContainingBlockChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"getElementRenderersBounds") ) { return getElementRenderersBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"addScrollOffsetToChildren") ) { return addScrollOffsetToChildren_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"treatVisibleOverflowAsAuto") ) { return treatVisibleOverflowAsAuto_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"getScrollableBoundsIfNeeded") ) { return getScrollableBoundsIfNeeded_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetElementRenderersBounds") ) { return doGetElementRenderersBounds_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScrollableView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipRect") ) { clipRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"scrollTop") ) { if (inCallProp) return set_scrollTop(inValue);scrollTop=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { if (inCallProp) return set_scrollLeft(inValue);scrollLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"scrollOffset") ) { scrollOffset=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_clippedBounds") ) { _clippedBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"scrollableBounds") ) { scrollableBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"rootElementRenderer") ) { rootElementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_previousScrollOffsetY") ) { _previousScrollOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_previousScrollOffsetX") ) { _previousScrollOffsetX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_ancestorsScrollOffset") ) { _ancestorsScrollOffset=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScrollableView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scrollTop"));
	outFields->push(HX_CSTRING("scrollLeft"));
	outFields->push(HX_CSTRING("clipRect"));
	outFields->push(HX_CSTRING("scrollableBounds"));
	outFields->push(HX_CSTRING("_clippedBounds"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("_previousScrollOffsetY"));
	outFields->push(HX_CSTRING("_previousScrollOffsetX"));
	outFields->push(HX_CSTRING("scrollOffset"));
	outFields->push(HX_CSTRING("_ancestorsScrollOffset"));
	outFields->push(HX_CSTRING("rootElementRenderer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("treatVisibleOverflowAsAuto"),
	HX_CSTRING("isYAxisClipped"),
	HX_CSTRING("isXAxisClipped"),
	HX_CSTRING("isContainingBlockChildren"),
	HX_CSTRING("scrollChanged"),
	HX_CSTRING("set_scrollTop"),
	HX_CSTRING("set_scrollLeft"),
	HX_CSTRING("doGetScrollableBounds"),
	HX_CSTRING("getScrollableBounds"),
	HX_CSTRING("getScrollableBoundsIfNeeded"),
	HX_CSTRING("updateScrollableBounds"),
	HX_CSTRING("doGetElementRenderersBounds"),
	HX_CSTRING("getElementRenderersBounds"),
	HX_CSTRING("updateClippedBounds"),
	HX_CSTRING("updateBounds"),
	HX_CSTRING("addScrollOffsetToChildren"),
	HX_CSTRING("addScrollOffsetIfNeeded"),
	HX_CSTRING("updateScrollOffset"),
	HX_CSTRING("resetScrollOffset"),
	HX_CSTRING("clipIfNeeded"),
	HX_CSTRING("clipChildren"),
	HX_CSTRING("updateClipRect"),
	HX_CSTRING("resetClipRect"),
	HX_CSTRING("scrollTop"),
	HX_CSTRING("scrollLeft"),
	HX_CSTRING("clipRect"),
	HX_CSTRING("scrollableBounds"),
	HX_CSTRING("_clippedBounds"),
	HX_CSTRING("bounds"),
	HX_CSTRING("_previousScrollOffsetY"),
	HX_CSTRING("_previousScrollOffsetX"),
	HX_CSTRING("scrollOffset"),
	HX_CSTRING("_ancestorsScrollOffset"),
	HX_CSTRING("rootElementRenderer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScrollableView_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScrollableView_obj::__mClass,"__mClass");
};

Class ScrollableView_obj::__mClass;

void ScrollableView_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.ScrollableView"), hx::TCanCast< ScrollableView_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ScrollableView_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
