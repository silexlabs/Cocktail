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
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_LineBox
#include <cocktail/core/linebox/LineBox.h>
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
namespace linebox{

Void LineBox_obj::__construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float availableWidth,bool isFirstLine,::cocktail::core::layout::LayoutStateValue layoutState)
{
HX_STACK_PUSH("LineBox::new","cocktail/core/linebox/LineBox.hx",54);
{
	HX_STACK_LINE(55)
	this->_availableWidth = availableWidth;
	HX_STACK_LINE(56)
	this->_isFirstLine = isFirstLine;
	HX_STACK_LINE(57)
	this->_elementRenderer = elementRenderer;
	HX_STACK_LINE(58)
	this->_spacesNumber = (int)0;
	HX_STACK_LINE(59)
	this->unbreakableWidth = (int)0;
	HX_STACK_LINE(60)
	this->_addedWidth = (int)0;
	HX_STACK_LINE(61)
	this->_firstInlineBoxInserted = false;
	HX_STACK_LINE(62)
	this->_unbreakableInlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
	HX_STACK_LINE(63)
	this->_layoutState = layoutState;
	HX_STACK_LINE(64)
	this->_trailingSpaceWidth = (int)0;
	HX_STACK_LINE(66)
	this->rootInlineBox = ::cocktail::core::linebox::InlineBox_obj::__new(elementRenderer,elementRenderer->getLeadedAscent(),elementRenderer->getLeadedDescent());
	HX_STACK_LINE(67)
	this->bounds = ::cocktail::core::geom::RectangleVO_obj::__new();
}
;
	return null();
}

LineBox_obj::~LineBox_obj() { }

Dynamic LineBox_obj::__CreateEmpty() { return  new LineBox_obj; }
hx::ObjectPtr< LineBox_obj > LineBox_obj::__new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float availableWidth,bool isFirstLine,::cocktail::core::layout::LayoutStateValue layoutState)
{  hx::ObjectPtr< LineBox_obj > result = new LineBox_obj();
	result->__construct(elementRenderer,availableWidth,isFirstLine,layoutState);
	return result;}

Dynamic LineBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LineBox_obj > result = new LineBox_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Float LineBox_obj::getAlignedSubTreeHeight( ::cocktail::core::linebox::InlineBox inlineBox,Float alignedSubTreeHeight,Float addedY,bool includeChildTopAndBottomInlineBoxes){
	HX_STACK_PUSH("LineBox::getAlignedSubTreeHeight","cocktail/core/linebox/LineBox.hx",977);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_ARG(alignedSubTreeHeight,"alignedSubTreeHeight");
	HX_STACK_ARG(addedY,"addedY");
	HX_STACK_ARG(includeChildTopAndBottomInlineBoxes,"includeChildTopAndBottomInlineBoxes");
	HX_STACK_LINE(977)
	return alignedSubTreeHeight;
}


HX_DEFINE_DYNAMIC_FUNC4(LineBox_obj,getAlignedSubTreeHeight,return )

bool LineBox_obj::isBottomAligned( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::isBottomAligned","cocktail/core/linebox/LineBox.hx",952);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(952)
	return inlineBox->elementRenderer->coreStyle->isBottomAligned;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,isBottomAligned,return )

bool LineBox_obj::isTopAligned( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::isTopAligned","cocktail/core/linebox/LineBox.hx",943);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(943)
	return inlineBox->elementRenderer->coreStyle->isTopAligned;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,isTopAligned,return )

bool LineBox_obj::isTopOrBottomAligned( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::isTopOrBottomAligned","cocktail/core/linebox/LineBox.hx",934);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(934)
	return (bool((inlineBox->elementRenderer->coreStyle->isBottomAligned == true)) || bool(inlineBox->elementRenderer->coreStyle->isTopAligned));
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,isTopOrBottomAligned,return )

Void LineBox_obj::getLineBoxHeight( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::geom::RectangleVO lineBoxBounds,Float addedY){
{
		HX_STACK_PUSH("LineBox::getLineBoxHeight","cocktail/core/linebox/LineBox.hx",881);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_ARG(lineBoxBounds,"lineBoxBounds");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_LINE(882)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(883)
		while(((child != null()))){
			HX_STACK_LINE(890)
			if (((((bool((child->elementRenderer->coreStyle->isBottomAligned == true)) || bool(child->elementRenderer->coreStyle->isTopAligned))) == true))){
				HX_STACK_LINE(891)
				Float alignedSubTreeHeight = this->getAlignedSubTreeHeight(child,child->bounds->height,(int)0,true);		HX_STACK_VAR(alignedSubTreeHeight,"alignedSubTreeHeight");
			}
			else{
				HX_STACK_LINE(904)
				::cocktail::core::linebox::LineBox_obj::_childBounds->x = (int)0;
				HX_STACK_LINE(905)
				::cocktail::core::linebox::LineBox_obj::_childBounds->y = (int)0;
				HX_STACK_LINE(906)
				::cocktail::core::linebox::LineBox_obj::_childBounds->width = (int)0;
				HX_STACK_LINE(907)
				::cocktail::core::linebox::LineBox_obj::_childBounds->height = (int)0;
				HX_STACK_LINE(909)
				::cocktail::core::linebox::LineBox_obj::_childBounds->y = (child->offsetFromParentInlineBox->y + addedY);
				HX_STACK_LINE(910)
				::cocktail::core::linebox::LineBox_obj::_childBounds->height = child->bounds->height;
				HX_STACK_LINE(912)
				{
					HX_STACK_LINE(912)
					::cocktail::core::geom::RectangleVO addedBounds = ::cocktail::core::linebox::LineBox_obj::_childBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
					bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
					bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
					HX_STACK_LINE(912)
					if (((getHorizontalBounds == true))){
						HX_STACK_LINE(912)
						if (((addedBounds->x < lineBoxBounds->x))){
							HX_STACK_LINE(912)
							lineBoxBounds->x = addedBounds->x;
						}
						HX_STACK_LINE(912)
						if ((((addedBounds->x + addedBounds->width) > (lineBoxBounds->x + lineBoxBounds->width)))){
							HX_STACK_LINE(912)
							lineBoxBounds->width = ((addedBounds->x + addedBounds->width) - lineBoxBounds->x);
						}
					}
					HX_STACK_LINE(912)
					if (((getVerticalBounds == true))){
						HX_STACK_LINE(912)
						if (((addedBounds->y < lineBoxBounds->y))){
							HX_STACK_LINE(912)
							lineBoxBounds->y = addedBounds->y;
						}
						HX_STACK_LINE(912)
						if ((((addedBounds->y + addedBounds->height) > (lineBoxBounds->y + lineBoxBounds->height)))){
							HX_STACK_LINE(912)
							lineBoxBounds->height = ((addedBounds->y + addedBounds->height) - lineBoxBounds->y);
						}
					}
				}
				HX_STACK_LINE(916)
				if (((child->isEmbedded == false))){
					HX_STACK_LINE(917)
					if (((child->firstChild != null()))){
						HX_STACK_LINE(919)
						this->getLineBoxHeight(child,lineBoxBounds,(addedY + child->offsetFromParentInlineBox->y));
					}
				}
			}
			HX_STACK_LINE(925)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,getLineBoxHeight,(void))

Void LineBox_obj::applyMinimumTop( ::cocktail::core::linebox::InlineBox inlineBox,Float minimumTop){
{
		HX_STACK_PUSH("LineBox::applyMinimumTop","cocktail/core/linebox/LineBox.hx",851);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_ARG(minimumTop,"minimumTop");
		HX_STACK_LINE(852)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(853)
		while(((child != null()))){
			HX_STACK_LINE(855)
			if (((((bool((child->elementRenderer->coreStyle->isBottomAligned == true)) || bool(child->elementRenderer->coreStyle->isTopAligned))) == false))){
				HX_STACK_LINE(857)
				hx::SubEq(child->bounds->y,minimumTop);
				HX_STACK_LINE(859)
				if (((child->isEmbedded == false))){
					HX_STACK_LINE(860)
					if (((child->firstChild != null()))){
						HX_STACK_LINE(862)
						this->applyMinimumTop(child,minimumTop);
					}
				}
			}
			HX_STACK_LINE(868)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(LineBox_obj,applyMinimumTop,(void))

Float LineBox_obj::getMinimumTop( ::cocktail::core::linebox::InlineBox inlineBox,Float minimumTop){
	HX_STACK_PUSH("LineBox::getMinimumTop","cocktail/core/linebox/LineBox.hx",824);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_ARG(minimumTop,"minimumTop");
	HX_STACK_LINE(825)
	::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(826)
	while(((child != null()))){
		HX_STACK_LINE(828)
		if (((((bool((child->elementRenderer->coreStyle->isBottomAligned == true)) || bool(child->elementRenderer->coreStyle->isTopAligned))) == false))){
			HX_STACK_LINE(830)
			if (((child->bounds->y < minimumTop))){
				HX_STACK_LINE(831)
				minimumTop = child->bounds->y;
			}
			HX_STACK_LINE(835)
			if (((child->isEmbedded == false))){
				HX_STACK_LINE(836)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(838)
					minimumTop = this->getMinimumTop(child,minimumTop);
				}
			}
		}
		HX_STACK_LINE(844)
		child = child->nextSibling;
	}
	HX_STACK_LINE(847)
	return minimumTop;
}


HX_DEFINE_DYNAMIC_FUNC2(LineBox_obj,getMinimumTop,return )

Void LineBox_obj::updateOffsetFromLineBox( ::cocktail::core::linebox::InlineBox inlineBox,Float lineBoxHeight,Float addedY){
{
		HX_STACK_PUSH("LineBox::updateOffsetFromLineBox","cocktail/core/linebox/LineBox.hx",787);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_ARG(lineBoxHeight,"lineBoxHeight");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_LINE(788)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(789)
		while(((child != null()))){
			HX_STACK_LINE(792)
			if ((child->elementRenderer->coreStyle->isTopAligned)){
				HX_STACK_LINE(793)
				child->bounds->y = (int)0;
			}
			else{
				HX_STACK_LINE(798)
				if ((child->elementRenderer->coreStyle->isBottomAligned)){
					HX_STACK_LINE(799)
					child->bounds->y = (lineBoxHeight - this->getAlignedSubTreeHeight(child,child->bounds->height,(int)0,false));
				}
				else{
					HX_STACK_LINE(803)
					child->bounds->y = (addedY + child->offsetFromParentInlineBox->y);
				}
			}
			HX_STACK_LINE(808)
			if (((bool((child->isEmbedded == false)) && bool((child->isText == false))))){
				HX_STACK_LINE(811)
				hx::AddEq(child->bounds->y,addedY);
				HX_STACK_LINE(813)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(814)
					this->updateOffsetFromLineBox(child,lineBoxHeight,child->bounds->y);
				}
			}
			HX_STACK_LINE(819)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,updateOffsetFromLineBox,(void))

Void LineBox_obj::updateOffsetFromParentInlineBox( ::cocktail::core::linebox::InlineBox inlineBox){
{
		HX_STACK_PUSH("LineBox::updateOffsetFromParentInlineBox","cocktail/core/linebox/LineBox.hx",702);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_LINE(703)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(704)
		while(((child != null()))){
			HX_STACK_LINE(706)
			::cocktail::core::css::CoreStyle childCoreStyle = child->elementRenderer->coreStyle;		HX_STACK_VAR(childCoreStyle,"childCoreStyle");
			HX_STACK_LINE(709)
			if (((childCoreStyle->isBaselineAligned == true))){
				HX_STACK_LINE(711)
				Float yOffset = (childCoreStyle->fontMetrics->ascent - inlineBox->elementRenderer->coreStyle->fontMetrics->ascent);		HX_STACK_VAR(yOffset,"yOffset");
				HX_STACK_LINE(712)
				child->offsetFromParentInlineBox->y = -(yOffset);
			}
			else{
				HX_STACK_LINE(715)
				{
					::cocktail::core::css::CSSPropertyValue _switch_1 = (childCoreStyle->getComputedOrInitialProperty((int)48));
					switch((_switch_1)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
								HX_STACK_LINE(719)
								{
									::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
									switch((_switch_2)->GetIndex()){
										case 24: {
											HX_STACK_LINE(725)
											Float yOffset = ((childCoreStyle->fontMetrics->ascent + (Float(child->bounds->height) / Float((int)2))) - ((inlineBox->leadedAscent + (Float(inlineBox->elementRenderer->coreStyle->fontMetrics->xHeight) / Float((int)2)))));		HX_STACK_VAR(yOffset,"yOffset");
											HX_STACK_LINE(726)
											child->offsetFromParentInlineBox->y = -(yOffset);
										}
										;break;
										case 26: {
										}
										;break;
										case 23: {
										}
										;break;
										case 20: {
										}
										;break;
										case 21: {
										}
										;break;
										case 22: case 25: {
											HX_STACK_LINE(739)
											child->offsetFromParentInlineBox->y = (int)0;
										}
										;break;
										default: {
										}
									}
								}
							}
						}
						;break;
						case 18: {
							Float value = _switch_1->__Param(0);
{
								HX_STACK_LINE(746)
								Float offsetFromBaseline = (childCoreStyle->fontMetrics->ascent - inlineBox->elementRenderer->coreStyle->fontMetrics->ascent);		HX_STACK_VAR(offsetFromBaseline,"offsetFromBaseline");
								HX_STACK_LINE(747)
								child->offsetFromParentInlineBox->y = -(value);
							}
						}
						;break;
						case 2: {
							Float value = _switch_1->__Param(0);
{
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			HX_STACK_LINE(759)
			if (((child->isEmbedded == false))){
				HX_STACK_LINE(760)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(762)
					this->updateOffsetFromParentInlineBox(child);
				}
			}
			HX_STACK_LINE(767)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,updateOffsetFromParentInlineBox,(void))

Void LineBox_obj::updateInlineBoxBounds( ::cocktail::core::linebox::InlineBox inlineBox){
{
		HX_STACK_PUSH("LineBox::updateInlineBoxBounds","cocktail/core/linebox/LineBox.hx",661);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_LINE(662)
		inlineBox->bounds->x = (int)50000;
		HX_STACK_LINE(663)
		inlineBox->bounds->y = (int)50000;
		HX_STACK_LINE(664)
		inlineBox->bounds->width = (int)0;
		HX_STACK_LINE(665)
		inlineBox->bounds->height = (int)0;
		HX_STACK_LINE(667)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(670)
		if (((child == null()))){
			HX_STACK_LINE(672)
			inlineBox->bounds->x = (int)0;
			HX_STACK_LINE(673)
			inlineBox->bounds->y = (int)0;
		}
		HX_STACK_LINE(676)
		while(((child != null()))){
			HX_STACK_LINE(679)
			::cocktail::core::linebox::LineBox_obj::_childBounds->x = (child->bounds->x - child->marginLeft);
			HX_STACK_LINE(680)
			::cocktail::core::linebox::LineBox_obj::_childBounds->y = child->bounds->y;
			HX_STACK_LINE(681)
			::cocktail::core::linebox::LineBox_obj::_childBounds->width = ((child->bounds->width + child->marginRight) + child->marginLeft);
			HX_STACK_LINE(682)
			::cocktail::core::linebox::LineBox_obj::_childBounds->height = child->bounds->height;
			HX_STACK_LINE(684)
			{
				HX_STACK_LINE(684)
				::cocktail::core::geom::RectangleVO addedBounds = ::cocktail::core::linebox::LineBox_obj::_childBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
				::cocktail::core::geom::RectangleVO bounds = inlineBox->bounds;		HX_STACK_VAR(bounds,"bounds");
				bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
				bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
				HX_STACK_LINE(684)
				if (((getHorizontalBounds == true))){
					HX_STACK_LINE(684)
					if (((addedBounds->x < bounds->x))){
						HX_STACK_LINE(684)
						bounds->x = addedBounds->x;
					}
					HX_STACK_LINE(684)
					if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
						HX_STACK_LINE(684)
						bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
					}
				}
				HX_STACK_LINE(684)
				if (((getVerticalBounds == true))){
					HX_STACK_LINE(684)
					if (((addedBounds->y < bounds->y))){
						HX_STACK_LINE(684)
						bounds->y = addedBounds->y;
					}
					HX_STACK_LINE(684)
					if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
						HX_STACK_LINE(684)
						bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
					}
				}
			}
			HX_STACK_LINE(685)
			child = child->nextSibling;
		}
		HX_STACK_LINE(689)
		hx::AddEq(inlineBox->bounds->width,(((inlineBox->paddingLeft + inlineBox->paddingRight) + inlineBox->borderLeft) + inlineBox->borderRight));
		HX_STACK_LINE(690)
		hx::SubEq(inlineBox->bounds->x,(inlineBox->paddingLeft + inlineBox->borderLeft));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,updateInlineBoxBounds,(void))

Void LineBox_obj::updateInlineBoxesBounds( ::cocktail::core::linebox::InlineBox inlineBox){
{
		HX_STACK_PUSH("LineBox::updateInlineBoxesBounds","cocktail/core/linebox/LineBox.hx",642);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_LINE(643)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(644)
		while(((child != null()))){
			HX_STACK_LINE(646)
			if (((bool((child->isText == false)) && bool((child->isEmbedded == false))))){
				HX_STACK_LINE(648)
				this->updateInlineBoxesBounds(child);
				HX_STACK_LINE(649)
				this->updateInlineBoxBounds(child);
			}
			HX_STACK_LINE(652)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,updateInlineBoxesBounds,(void))

Float LineBox_obj::alignInlineBoxesVertically( ){
	HX_STACK_PUSH("LineBox::alignInlineBoxesVertically","cocktail/core/linebox/LineBox.hx",615);
	HX_STACK_THIS(this);
	HX_STACK_LINE(616)
	this->updateOffsetFromParentInlineBox(this->rootInlineBox);
	HX_STACK_LINE(618)
	::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->x = (int)0;
	HX_STACK_LINE(619)
	::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->y = (int)0;
	HX_STACK_LINE(620)
	::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->width = (int)0;
	HX_STACK_LINE(621)
	::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->height = (int)0;
	HX_STACK_LINE(623)
	::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->height = this->_elementRenderer->coreStyle->usedValues->lineHeight;
	HX_STACK_LINE(625)
	this->getLineBoxHeight(this->rootInlineBox,::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds,(int)0);
	HX_STACK_LINE(626)
	Float lineBoxHeight = ::cocktail::core::linebox::LineBox_obj::_lineBoxesBounds->height;		HX_STACK_VAR(lineBoxHeight,"lineBoxHeight");
	HX_STACK_LINE(628)
	this->updateOffsetFromLineBox(this->rootInlineBox,lineBoxHeight,(int)0);
	HX_STACK_LINE(630)
	Float minimumTop = this->getMinimumTop(this->rootInlineBox,(int)0);		HX_STACK_VAR(minimumTop,"minimumTop");
	HX_STACK_LINE(632)
	this->applyMinimumTop(this->rootInlineBox,minimumTop);
	HX_STACK_LINE(634)
	return lineBoxHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(LineBox_obj,alignInlineBoxesVertically,return )

Void LineBox_obj::alignJustify( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox,int spacesInLine){
{
		HX_STACK_PUSH("LineBox::alignJustify","cocktail/core/linebox/LineBox.hx",579);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(remainingSpace,"remainingSpace");
		HX_STACK_ARG(inlineBox,"inlineBox");
		HX_STACK_ARG(spacesInLine,"spacesInLine");
		HX_STACK_LINE(580)
		::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(581)
		while(((child != null()))){
			HX_STACK_LINE(583)
			if (((child->isSpace == true))){
				HX_STACK_LINE(585)
				Float spaceWidth = (Float(remainingSpace) / Float(spacesInLine));		HX_STACK_VAR(spaceWidth,"spaceWidth");
				HX_STACK_LINE(587)
				(spacesInLine)--;
				HX_STACK_LINE(588)
				hx::SubEq(remainingSpace,spaceWidth);
				HX_STACK_LINE(589)
				hx::AddEq(x,spaceWidth);
			}
			HX_STACK_LINE(592)
			child->bounds->x = x;
			HX_STACK_LINE(593)
			hx::AddEq(x,child->bounds->width);
			HX_STACK_LINE(595)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(596)
				this->alignJustify(x,remainingSpace,child,spacesInLine);
			}
			HX_STACK_LINE(600)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(LineBox_obj,alignJustify,(void))

Float LineBox_obj::alignRight( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::alignRight","cocktail/core/linebox/LineBox.hx",551);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(remainingSpace,"remainingSpace");
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(552)
	hx::AddEq(x,((inlineBox->marginLeft + inlineBox->borderLeft) + inlineBox->paddingLeft));
	HX_STACK_LINE(554)
	::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(555)
	while(((child != null()))){
		HX_STACK_LINE(557)
		if (((child->firstChild != null()))){
			HX_STACK_LINE(558)
			x = this->alignRight(x,remainingSpace,child);
		}
		HX_STACK_LINE(562)
		child->bounds->x = (x + remainingSpace);
		HX_STACK_LINE(563)
		hx::AddEq(x,child->bounds->width);
		HX_STACK_LINE(565)
		child = child->nextSibling;
	}
	HX_STACK_LINE(568)
	hx::AddEq(x,((inlineBox->marginRight + inlineBox->borderRight) + inlineBox->paddingRight));
	HX_STACK_LINE(570)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,alignRight,return )

Float LineBox_obj::alignCenter( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::alignCenter","cocktail/core/linebox/LineBox.hx",524);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(remainingSpace,"remainingSpace");
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(525)
	hx::AddEq(x,((inlineBox->marginLeft + inlineBox->borderLeft) + inlineBox->paddingLeft));
	HX_STACK_LINE(527)
	::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(528)
	while(((child != null()))){
		HX_STACK_LINE(530)
		if (((child->firstChild != null()))){
			HX_STACK_LINE(531)
			x = this->alignCenter(x,remainingSpace,child);
		}
		HX_STACK_LINE(535)
		child->bounds->x = ((Float(remainingSpace) / Float((int)2)) + x);
		HX_STACK_LINE(536)
		hx::AddEq(x,child->bounds->width);
		HX_STACK_LINE(538)
		child = child->nextSibling;
	}
	HX_STACK_LINE(541)
	hx::AddEq(x,((inlineBox->marginRight + inlineBox->borderRight) + inlineBox->paddingRight));
	HX_STACK_LINE(543)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,alignCenter,return )

Float LineBox_obj::alignLeft( Float x,::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::alignLeft","cocktail/core/linebox/LineBox.hx",495);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(496)
	hx::AddEq(x,((inlineBox->paddingLeft + inlineBox->borderLeft) + inlineBox->marginLeft));
	HX_STACK_LINE(498)
	::cocktail::core::linebox::InlineBox child = inlineBox->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(499)
	while(((child != null()))){
		HX_STACK_LINE(501)
		if (((child->firstChild != null()))){
			HX_STACK_LINE(502)
			x = this->alignLeft(x,child);
		}
		else{
			HX_STACK_LINE(507)
			child->bounds->x = (x + child->marginLeft);
			HX_STACK_LINE(508)
			hx::AddEq(x,((child->bounds->width + child->marginLeft) + child->marginRight));
		}
		HX_STACK_LINE(511)
		child = child->nextSibling;
	}
	HX_STACK_LINE(514)
	hx::AddEq(x,((inlineBox->paddingRight + inlineBox->borderRight) + inlineBox->marginRight));
	HX_STACK_LINE(516)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC2(LineBox_obj,alignLeft,return )

Float LineBox_obj::alignInlineBoxesHorizontally( ::cocktail::core::linebox::InlineBox rootInlineBox,bool isLastLine,Float concatenatedLength){
	HX_STACK_PUSH("LineBox::alignInlineBoxesHorizontally","cocktail/core/linebox/LineBox.hx",424);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootInlineBox,"rootInlineBox");
	HX_STACK_ARG(isLastLine,"isLastLine");
	HX_STACK_ARG(concatenatedLength,"concatenatedLength");
	HX_STACK_LINE(428)
	Float remainingSpace = (this->_availableWidth - concatenatedLength);		HX_STACK_VAR(remainingSpace,"remainingSpace");
	HX_STACK_LINE(429)
	Float x = (int)0;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(433)
	if (((this->_isFirstLine == true))){
		HX_STACK_LINE(435)
		hx::AddEq(x,this->_elementRenderer->coreStyle->usedValues->textIndent);
		HX_STACK_LINE(436)
		hx::SubEq(remainingSpace,this->_elementRenderer->coreStyle->usedValues->textIndent);
	}
	HX_STACK_LINE(441)
	if (((this->_elementRenderer->coreStyle->isLeftAligned == true))){
		HX_STACK_LINE(442)
		this->alignLeft(x,rootInlineBox);
	}
	else{
		HX_STACK_LINE(446)
		{
			::cocktail::core::css::CSSKeywordValue _switch_3 = (this->_elementRenderer->coreStyle->getKeyword(this->_elementRenderer->coreStyle->getComputedOrInitialProperty((int)46)));
			switch((_switch_3)->GetIndex()){
				case 12: {
					HX_STACK_LINE(449)
					this->alignRight(x,remainingSpace,rootInlineBox);
				}
				;break;
				case 13: {
					HX_STACK_LINE(452)
					this->alignCenter(x,remainingSpace,rootInlineBox);
				}
				;break;
				case 14: {
					HX_STACK_LINE(455)
					if (((isLastLine == true))){
						HX_STACK_LINE(459)
						this->alignLeft(x,rootInlineBox);
					}
					else{
						HX_STACK_LINE(463)
						{
							::cocktail::core::css::CSSKeywordValue _switch_4 = (this->_elementRenderer->coreStyle->getKeyword(this->_elementRenderer->coreStyle->getComputedOrInitialProperty((int)45)));
							switch((_switch_4)->GetIndex()){
								case 7: case 9: {
									HX_STACK_LINE(468)
									this->alignLeft(x,rootInlineBox);
								}
								;break;
								default: {
									HX_STACK_LINE(474)
									concatenatedLength = this->_availableWidth;
									HX_STACK_LINE(475)
									this->alignJustify(x,remainingSpace,rootInlineBox,this->_spacesNumber);
								}
							}
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(481)
					hx::Throw (HX_CSTRING("Illegal value for text-align style"));
				}
			}
		}
	}
	HX_STACK_LINE(487)
	return concatenatedLength;
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,alignInlineBoxesHorizontally,return )

bool LineBox_obj::isEmptyLineBox( ){
	HX_STACK_PUSH("LineBox::isEmptyLineBox","cocktail/core/linebox/LineBox.hx",402);
	HX_STACK_THIS(this);
	HX_STACK_LINE(404)
	if (((this->rootInlineBox->firstChild == null()))){
		HX_STACK_LINE(405)
		return true;
	}
	HX_STACK_LINE(409)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LineBox_obj,isEmptyLineBox,return )

bool LineBox_obj::getTrailingSpacesWidth( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::getTrailingSpacesWidth","cocktail/core/linebox/LineBox.hx",340);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(342)
	::cocktail::core::linebox::InlineBox child = inlineBox->lastChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(343)
	while(((child != null()))){
		HX_STACK_LINE(347)
		if (((child->isEmbedded == false))){
			HX_STACK_LINE(348)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(351)
				bool canAddSpacesWidthFurther = this->getTrailingSpacesWidth(child);		HX_STACK_VAR(canAddSpacesWidthFurther,"canAddSpacesWidthFurther");
				HX_STACK_LINE(354)
				if (((canAddSpacesWidthFurther == false))){
					HX_STACK_LINE(355)
					return false;
				}
			}
		}
		HX_STACK_LINE(362)
		if (((child->isSpace == true))){
			HX_STACK_LINE(364)
			::cocktail::core::css::CoreStyle inlineBoxCoreStyle = child->elementRenderer->coreStyle;		HX_STACK_VAR(inlineBoxCoreStyle,"inlineBoxCoreStyle");
			HX_STACK_LINE(365)
			if (((bool((bool((inlineBoxCoreStyle->hasNormalWhiteSpace == true)) || bool((inlineBoxCoreStyle->hasNoWrapWhiteSpace == true)))) || bool((inlineBoxCoreStyle->hasPreLineWhiteSpace == true))))){
				HX_STACK_LINE(368)
				hx::AddEq(this->_trailingSpaceWidth,child->bounds->width);
			}
			else{
				HX_STACK_LINE(372)
				return false;
			}
		}
		else{
			HX_STACK_LINE(378)
			return false;
		}
		HX_STACK_LINE(382)
		child = child->previousSibling;
	}
	HX_STACK_LINE(385)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,getTrailingSpacesWidth,return )

bool LineBox_obj::removeTrailingSpaces( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::removeTrailingSpaces","cocktail/core/linebox/LineBox.hx",279);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(281)
	::cocktail::core::linebox::InlineBox child = inlineBox->lastChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(282)
	while(((child != null()))){
		HX_STACK_LINE(286)
		if (((child->isEmbedded == false))){
			HX_STACK_LINE(287)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(290)
				bool canRemoveSpacesFurther = this->removeTrailingSpaces(child);		HX_STACK_VAR(canRemoveSpacesFurther,"canRemoveSpacesFurther");
				HX_STACK_LINE(293)
				if (((canRemoveSpacesFurther == false))){
					HX_STACK_LINE(294)
					return false;
				}
			}
		}
		HX_STACK_LINE(302)
		::cocktail::core::linebox::InlineBox previousSibling = child->previousSibling;		HX_STACK_VAR(previousSibling,"previousSibling");
		HX_STACK_LINE(305)
		if (((child->isSpace == true))){
			HX_STACK_LINE(307)
			::cocktail::core::css::CoreStyle inlineBoxCoreStyle = child->elementRenderer->coreStyle;		HX_STACK_VAR(inlineBoxCoreStyle,"inlineBoxCoreStyle");
			HX_STACK_LINE(308)
			if (((bool((bool((inlineBoxCoreStyle->hasNormalWhiteSpace == true)) || bool((inlineBoxCoreStyle->hasNoWrapWhiteSpace == true)))) || bool((inlineBoxCoreStyle->hasPreLineWhiteSpace == true))))){
				HX_STACK_LINE(311)
				child->parentNode->__Field(HX_CSTRING("removeChild"),true)(child);
			}
			else{
				HX_STACK_LINE(315)
				return false;
			}
		}
		else{
			HX_STACK_LINE(321)
			return false;
		}
		HX_STACK_LINE(325)
		child = previousSibling;
	}
	HX_STACK_LINE(328)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,removeTrailingSpaces,return )

Void LineBox_obj::layout( bool isLastLine,::cocktail::core::linebox::InlineBox parentInlineBox){
{
		HX_STACK_PUSH("LineBox::layout","cocktail/core/linebox/LineBox.hx",231);
		HX_STACK_THIS(this);
		HX_STACK_ARG(isLastLine,"isLastLine");
		HX_STACK_ARG(parentInlineBox,"parentInlineBox");
		HX_STACK_LINE(234)
		if (((isLastLine == true))){
			HX_STACK_LINE(236)
			hx::AddEq(this->_addedWidth,this->unbreakableWidth);
			HX_STACK_LINE(241)
			int unbreakableLength = this->_unbreakableInlineBoxes->length;		HX_STACK_VAR(unbreakableLength,"unbreakableLength");
			HX_STACK_LINE(242)
			{
				HX_STACK_LINE(242)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(242)
				while(((_g < unbreakableLength))){
					HX_STACK_LINE(242)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(244)
					this->_unbreakableInlineBoxes->__get(i)->lineBox = hx::ObjectPtr<OBJ_>(this);
					HX_STACK_LINE(245)
					parentInlineBox->appendChild(this->_unbreakableInlineBoxes->__get(i));
				}
			}
		}
		HX_STACK_LINE(250)
		this->removeTrailingSpaces(this->rootInlineBox);
		HX_STACK_LINE(254)
		this->bounds->width = this->alignInlineBoxesHorizontally(this->rootInlineBox,isLastLine,this->_addedWidth);
		HX_STACK_LINE(258)
		this->updateInlineBoxesBounds(this->rootInlineBox);
		HX_STACK_LINE(262)
		this->bounds->height = this->alignInlineBoxesVertically();
		HX_STACK_LINE(265)
		if (((this->isEmptyLineBox() == true))){
			HX_STACK_LINE(266)
			this->bounds->height = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(LineBox_obj,layout,(void))

bool LineBox_obj::introduceBreakOpportunity( ::cocktail::core::linebox::InlineBox inlineBox){
	HX_STACK_PUSH("LineBox::introduceBreakOpportunity","cocktail/core/linebox/LineBox.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_LINE(207)
	if (((this->_layoutState == ::cocktail::core::layout::LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_WIDTH_dyn()))){
		HX_STACK_LINE(208)
		return false;
	}
	HX_STACK_LINE(214)
	::cocktail::core::css::CoreStyle inlineBoxCoreStyle = inlineBox->elementRenderer->coreStyle;		HX_STACK_VAR(inlineBoxCoreStyle,"inlineBoxCoreStyle");
	HX_STACK_LINE(215)
	if (((bool((inlineBoxCoreStyle->hasPreWhiteSpace == true)) || bool((inlineBoxCoreStyle->hasNoWrapWhiteSpace == true))))){
		HX_STACK_LINE(216)
		return false;
	}
	HX_STACK_LINE(220)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,introduceBreakOpportunity,return )

Void LineBox_obj::addUnbreakableInlineBoxesToLineBox( ::cocktail::core::linebox::InlineBox parentInlineBox){
{
		HX_STACK_PUSH("LineBox::addUnbreakableInlineBoxesToLineBox","cocktail/core/linebox/LineBox.hx",185);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentInlineBox,"parentInlineBox");
		HX_STACK_LINE(186)
		int unbreakableLength = this->_unbreakableInlineBoxes->length;		HX_STACK_VAR(unbreakableLength,"unbreakableLength");
		HX_STACK_LINE(187)
		{
			HX_STACK_LINE(187)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(187)
			while(((_g < unbreakableLength))){
				HX_STACK_LINE(187)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(189)
				this->_unbreakableInlineBoxes->__get(i)->lineBox = hx::ObjectPtr<OBJ_>(this);
				HX_STACK_LINE(190)
				parentInlineBox->appendChild(this->_unbreakableInlineBoxes->__get(i));
			}
		}
		HX_STACK_LINE(194)
		this->_unbreakableInlineBoxes = ::cocktail::core::utils::Utils_obj::clear(this->_unbreakableInlineBoxes);
		HX_STACK_LINE(195)
		this->unbreakableWidth = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,addUnbreakableInlineBoxesToLineBox,(void))

bool LineBox_obj::insert( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::linebox::InlineBox parentInlineBox,bool force){
	HX_STACK_PUSH("LineBox::insert","cocktail/core/linebox/LineBox.hx",101);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_ARG(parentInlineBox,"parentInlineBox");
	HX_STACK_ARG(force,"force");
	HX_STACK_LINE(104)
	if (((this->_firstInlineBoxInserted == false))){
		HX_STACK_LINE(106)
		if (((inlineBox->isSpace == true))){
			HX_STACK_LINE(108)
			::cocktail::core::css::CoreStyle inlineBoxCoreStyle = inlineBox->elementRenderer->coreStyle;		HX_STACK_VAR(inlineBoxCoreStyle,"inlineBoxCoreStyle");
			HX_STACK_LINE(109)
			if (((bool((bool((inlineBoxCoreStyle->hasNormalWhiteSpace == true)) || bool((inlineBoxCoreStyle->hasPreWrapWhiteSpace == true)))) || bool(inlineBoxCoreStyle->hasNoWrapWhiteSpace)))){
				HX_STACK_LINE(111)
				return false;
			}
		}
		HX_STACK_LINE(116)
		this->_firstInlineBoxInserted = true;
	}
	HX_STACK_LINE(121)
	if (((inlineBox->isSpace == true))){
		HX_STACK_LINE(122)
		(this->_spacesNumber)++;
	}
	HX_STACK_LINE(129)
	this->_unbreakableInlineBoxes->push(inlineBox);
	HX_STACK_LINE(131)
	Float inlineBoxWidth = ((inlineBox->bounds->width + inlineBox->marginLeft) + inlineBox->marginRight);		HX_STACK_VAR(inlineBoxWidth,"inlineBoxWidth");
	HX_STACK_LINE(132)
	hx::AddEq(this->unbreakableWidth,::Math_obj::floor(inlineBoxWidth));
	HX_STACK_LINE(135)
	int remainingLineWidth = ::Math_obj::floor((this->_availableWidth - this->_addedWidth));		HX_STACK_VAR(remainingLineWidth,"remainingLineWidth");
	HX_STACK_LINE(138)
	if (((inlineBox->isLineFeed == true))){
		HX_STACK_LINE(139)
		return true;
	}
	else{
		HX_STACK_LINE(143)
		if ((((remainingLineWidth - this->unbreakableWidth) < (int)0))){
			HX_STACK_LINE(144)
			if (((bool((this->introduceBreakOpportunity(inlineBox) == true)) && bool((force == false))))){
				HX_STACK_LINE(149)
				return true;
			}
			else{
				HX_STACK_LINE(155)
				hx::AddEq(this->_addedWidth,this->unbreakableWidth);
				HX_STACK_LINE(156)
				this->addUnbreakableInlineBoxesToLineBox(parentInlineBox);
			}
		}
		else{
			HX_STACK_LINE(163)
			if (((bool((this->introduceBreakOpportunity(inlineBox) == true)) || bool((force == true))))){
				HX_STACK_LINE(165)
				hx::AddEq(this->_addedWidth,this->unbreakableWidth);
				HX_STACK_LINE(166)
				this->addUnbreakableInlineBoxesToLineBox(parentInlineBox);
			}
		}
	}
	HX_STACK_LINE(171)
	if (((this->_layoutState == ::cocktail::core::layout::LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH_dyn()))){
		HX_STACK_LINE(172)
		return true;
	}
	HX_STACK_LINE(176)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(LineBox_obj,insert,return )

bool LineBox_obj::widthCanFit( Float width){
	HX_STACK_PUSH("LineBox::widthCanFit","cocktail/core/linebox/LineBox.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(width,"width");
	HX_STACK_LINE(87)
	this->_trailingSpaceWidth = (int)0;
	HX_STACK_LINE(88)
	this->getTrailingSpacesWidth(this->rootInlineBox);
	HX_STACK_LINE(90)
	if (((((this->_addedWidth + width) - this->_trailingSpaceWidth) <= this->_availableWidth))){
		HX_STACK_LINE(91)
		return true;
	}
	else{
		HX_STACK_LINE(95)
		return false;
	}
	HX_STACK_LINE(90)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,widthCanFit,return )

Void LineBox_obj::addUnbreakableWidth( Float width){
{
		HX_STACK_PUSH("LineBox::addUnbreakableWidth","cocktail/core/linebox/LineBox.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_LINE(71)
		hx::AddEq(this->unbreakableWidth,::Math_obj::floor(width));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LineBox_obj,addUnbreakableWidth,(void))

::cocktail::core::geom::RectangleVO LineBox_obj::_childBounds;

::cocktail::core::geom::RectangleVO LineBox_obj::_lineBoxesBounds;


LineBox_obj::LineBox_obj()
{
}

void LineBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LineBox);
	HX_MARK_MEMBER_NAME(_trailingSpaceWidth,"_trailingSpaceWidth");
	HX_MARK_MEMBER_NAME(_layoutState,"_layoutState");
	HX_MARK_MEMBER_NAME(_firstInlineBoxInserted,"_firstInlineBoxInserted");
	HX_MARK_MEMBER_NAME(_spacesNumber,"_spacesNumber");
	HX_MARK_MEMBER_NAME(_elementRenderer,"_elementRenderer");
	HX_MARK_MEMBER_NAME(_isFirstLine,"_isFirstLine");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(_availableWidth,"_availableWidth");
	HX_MARK_MEMBER_NAME(_addedWidth,"_addedWidth");
	HX_MARK_MEMBER_NAME(rootInlineBox,"rootInlineBox");
	HX_MARK_MEMBER_NAME(unbreakableWidth,"unbreakableWidth");
	HX_MARK_MEMBER_NAME(_unbreakableInlineBoxes,"_unbreakableInlineBoxes");
	HX_MARK_END_CLASS();
}

void LineBox_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_trailingSpaceWidth,"_trailingSpaceWidth");
	HX_VISIT_MEMBER_NAME(_layoutState,"_layoutState");
	HX_VISIT_MEMBER_NAME(_firstInlineBoxInserted,"_firstInlineBoxInserted");
	HX_VISIT_MEMBER_NAME(_spacesNumber,"_spacesNumber");
	HX_VISIT_MEMBER_NAME(_elementRenderer,"_elementRenderer");
	HX_VISIT_MEMBER_NAME(_isFirstLine,"_isFirstLine");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(_availableWidth,"_availableWidth");
	HX_VISIT_MEMBER_NAME(_addedWidth,"_addedWidth");
	HX_VISIT_MEMBER_NAME(rootInlineBox,"rootInlineBox");
	HX_VISIT_MEMBER_NAME(unbreakableWidth,"unbreakableWidth");
	HX_VISIT_MEMBER_NAME(_unbreakableInlineBoxes,"_unbreakableInlineBoxes");
}

Dynamic LineBox_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		if (HX_FIELD_EQ(inName,"insert") ) { return insert_dyn(); }
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alignLeft") ) { return alignLeft_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"alignRight") ) { return alignRight_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"alignCenter") ) { return alignCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"widthCanFit") ) { return widthCanFit_dyn(); }
		if (HX_FIELD_EQ(inName,"_addedWidth") ) { return _addedWidth; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_childBounds") ) { return _childBounds; }
		if (HX_FIELD_EQ(inName,"isTopAligned") ) { return isTopAligned_dyn(); }
		if (HX_FIELD_EQ(inName,"alignJustify") ) { return alignJustify_dyn(); }
		if (HX_FIELD_EQ(inName,"_layoutState") ) { return _layoutState; }
		if (HX_FIELD_EQ(inName,"_isFirstLine") ) { return _isFirstLine; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getMinimumTop") ) { return getMinimumTop_dyn(); }
		if (HX_FIELD_EQ(inName,"_spacesNumber") ) { return _spacesNumber; }
		if (HX_FIELD_EQ(inName,"rootInlineBox") ) { return rootInlineBox; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isEmptyLineBox") ) { return isEmptyLineBox_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isBottomAligned") ) { return isBottomAligned_dyn(); }
		if (HX_FIELD_EQ(inName,"applyMinimumTop") ) { return applyMinimumTop_dyn(); }
		if (HX_FIELD_EQ(inName,"_availableWidth") ) { return _availableWidth; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_lineBoxesBounds") ) { return _lineBoxesBounds; }
		if (HX_FIELD_EQ(inName,"getLineBoxHeight") ) { return getLineBoxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"_elementRenderer") ) { return _elementRenderer; }
		if (HX_FIELD_EQ(inName,"unbreakableWidth") ) { return unbreakableWidth; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"addUnbreakableWidth") ) { return addUnbreakableWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"_trailingSpaceWidth") ) { return _trailingSpaceWidth; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isTopOrBottomAligned") ) { return isTopOrBottomAligned_dyn(); }
		if (HX_FIELD_EQ(inName,"removeTrailingSpaces") ) { return removeTrailingSpaces_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updateInlineBoxBounds") ) { return updateInlineBoxBounds_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getTrailingSpacesWidth") ) { return getTrailingSpacesWidth_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getAlignedSubTreeHeight") ) { return getAlignedSubTreeHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"updateOffsetFromLineBox") ) { return updateOffsetFromLineBox_dyn(); }
		if (HX_FIELD_EQ(inName,"updateInlineBoxesBounds") ) { return updateInlineBoxesBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"_firstInlineBoxInserted") ) { return _firstInlineBoxInserted; }
		if (HX_FIELD_EQ(inName,"_unbreakableInlineBoxes") ) { return _unbreakableInlineBoxes; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"introduceBreakOpportunity") ) { return introduceBreakOpportunity_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"alignInlineBoxesVertically") ) { return alignInlineBoxesVertically_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"alignInlineBoxesHorizontally") ) { return alignInlineBoxesHorizontally_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"updateOffsetFromParentInlineBox") ) { return updateOffsetFromParentInlineBox_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"addUnbreakableInlineBoxesToLineBox") ) { return addUnbreakableInlineBoxesToLineBox_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LineBox_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_addedWidth") ) { _addedWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_childBounds") ) { _childBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_layoutState") ) { _layoutState=inValue.Cast< ::cocktail::core::layout::LayoutStateValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isFirstLine") ) { _isFirstLine=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_spacesNumber") ) { _spacesNumber=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rootInlineBox") ) { rootInlineBox=inValue.Cast< ::cocktail::core::linebox::InlineBox >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_availableWidth") ) { _availableWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_lineBoxesBounds") ) { _lineBoxesBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_elementRenderer") ) { _elementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"unbreakableWidth") ) { unbreakableWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_trailingSpaceWidth") ) { _trailingSpaceWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_firstInlineBoxInserted") ) { _firstInlineBoxInserted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_unbreakableInlineBoxes") ) { _unbreakableInlineBoxes=inValue.Cast< Array< ::cocktail::core::linebox::InlineBox > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LineBox_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_trailingSpaceWidth"));
	outFields->push(HX_CSTRING("_layoutState"));
	outFields->push(HX_CSTRING("_firstInlineBoxInserted"));
	outFields->push(HX_CSTRING("_spacesNumber"));
	outFields->push(HX_CSTRING("_elementRenderer"));
	outFields->push(HX_CSTRING("_isFirstLine"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("_availableWidth"));
	outFields->push(HX_CSTRING("_addedWidth"));
	outFields->push(HX_CSTRING("rootInlineBox"));
	outFields->push(HX_CSTRING("unbreakableWidth"));
	outFields->push(HX_CSTRING("_unbreakableInlineBoxes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_childBounds"),
	HX_CSTRING("_lineBoxesBounds"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAlignedSubTreeHeight"),
	HX_CSTRING("isBottomAligned"),
	HX_CSTRING("isTopAligned"),
	HX_CSTRING("isTopOrBottomAligned"),
	HX_CSTRING("getLineBoxHeight"),
	HX_CSTRING("applyMinimumTop"),
	HX_CSTRING("getMinimumTop"),
	HX_CSTRING("updateOffsetFromLineBox"),
	HX_CSTRING("updateOffsetFromParentInlineBox"),
	HX_CSTRING("updateInlineBoxBounds"),
	HX_CSTRING("updateInlineBoxesBounds"),
	HX_CSTRING("alignInlineBoxesVertically"),
	HX_CSTRING("alignJustify"),
	HX_CSTRING("alignRight"),
	HX_CSTRING("alignCenter"),
	HX_CSTRING("alignLeft"),
	HX_CSTRING("alignInlineBoxesHorizontally"),
	HX_CSTRING("isEmptyLineBox"),
	HX_CSTRING("getTrailingSpacesWidth"),
	HX_CSTRING("removeTrailingSpaces"),
	HX_CSTRING("layout"),
	HX_CSTRING("introduceBreakOpportunity"),
	HX_CSTRING("addUnbreakableInlineBoxesToLineBox"),
	HX_CSTRING("insert"),
	HX_CSTRING("widthCanFit"),
	HX_CSTRING("addUnbreakableWidth"),
	HX_CSTRING("_trailingSpaceWidth"),
	HX_CSTRING("_layoutState"),
	HX_CSTRING("_firstInlineBoxInserted"),
	HX_CSTRING("_spacesNumber"),
	HX_CSTRING("_elementRenderer"),
	HX_CSTRING("_isFirstLine"),
	HX_CSTRING("bounds"),
	HX_CSTRING("_availableWidth"),
	HX_CSTRING("_addedWidth"),
	HX_CSTRING("rootInlineBox"),
	HX_CSTRING("unbreakableWidth"),
	HX_CSTRING("_unbreakableInlineBoxes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LineBox_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(LineBox_obj::_childBounds,"_childBounds");
	HX_MARK_MEMBER_NAME(LineBox_obj::_lineBoxesBounds,"_lineBoxesBounds");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LineBox_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LineBox_obj::_childBounds,"_childBounds");
	HX_VISIT_MEMBER_NAME(LineBox_obj::_lineBoxesBounds,"_lineBoxesBounds");
};

Class LineBox_obj::__mClass;

void LineBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.linebox.LineBox"), hx::TCanCast< LineBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LineBox_obj::__boot()
{
	_childBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
	_lineBoxesBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace linebox
