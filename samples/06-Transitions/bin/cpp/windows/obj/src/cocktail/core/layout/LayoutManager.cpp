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
#ifndef INCLUDED_cocktail_core_layout_LayoutManager
#include <cocktail/core/layout/LayoutManager.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedFloatBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_FloatBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/FloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InLineBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InlineBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_PositionedBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.h>
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
namespace cocktail{
namespace core{
namespace layout{

Void LayoutManager_obj::__construct()
{
HX_STACK_PUSH("LayoutManager::new","cocktail/core/layout/LayoutManager.hx",62);
{
	HX_STACK_LINE(65)
	::cocktail::core::layout::floats::FloatsManager floatsManager = ::cocktail::core::layout::floats::FloatsManager_obj::__new();		HX_STACK_VAR(floatsManager,"floatsManager");
	HX_STACK_LINE(67)
	this->embeddedBlockBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__new();
	HX_STACK_LINE(68)
	this->embeddedFloatBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__new();
	HX_STACK_LINE(69)
	this->embeddedInlineBlockBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__new();
	HX_STACK_LINE(70)
	this->embeddedInlineBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__new();
	HX_STACK_LINE(71)
	this->embeddedPositionedBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__new();
	HX_STACK_LINE(73)
	this->blockBoxStyleComputer = ::cocktail::core::layout::computer::boxComputers::BlockBoxStylesComputer_obj::__new();
	HX_STACK_LINE(74)
	this->floatBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::FloatBoxStylesComputer_obj::__new();
	HX_STACK_LINE(75)
	this->inlineBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::InLineBoxStylesComputer_obj::__new();
	HX_STACK_LINE(76)
	this->inlineBlockBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__new();
	HX_STACK_LINE(77)
	this->positionedBoxStylesComputer = ::cocktail::core::layout::computer::boxComputers::PositionedBoxStylesComputer_obj::__new();
}
;
	return null();
}

LayoutManager_obj::~LayoutManager_obj() { }

Dynamic LayoutManager_obj::__CreateEmpty() { return  new LayoutManager_obj; }
hx::ObjectPtr< LayoutManager_obj > LayoutManager_obj::__new()
{  hx::ObjectPtr< LayoutManager_obj > result = new LayoutManager_obj();
	result->__construct();
	return result;}

Dynamic LayoutManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LayoutManager_obj > result = new LayoutManager_obj();
	result->__construct();
	return result;}

::cocktail::core::layout::computer::boxComputers::BoxStylesComputer LayoutManager_obj::getBoxStylesComputer( ::cocktail::core::renderer::ElementRenderer elementRenderer){
	HX_STACK_PUSH("LayoutManager::getBoxStylesComputer","cocktail/core/layout/LayoutManager.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_LINE(84)
	if (((elementRenderer->isFloat() == true))){
		HX_STACK_LINE(87)
		if (((elementRenderer->isReplaced == true))){
			HX_STACK_LINE(89)
			return this->embeddedFloatBoxStylesComputer;
		}
		else{
			HX_STACK_LINE(93)
			return this->floatBoxStylesComputer;
		}
	}
	else{
		HX_STACK_LINE(98)
		if (((bool((elementRenderer->isPositioned() == true)) && bool((elementRenderer->isRelativePositioned() == false))))){
			HX_STACK_LINE(99)
			if (((elementRenderer->isReplaced == true))){
				HX_STACK_LINE(101)
				return this->embeddedPositionedBoxStylesComputer;
			}
			else{
				HX_STACK_LINE(105)
				return this->positionedBoxStylesComputer;
			}
		}
		else{
			HX_STACK_LINE(110)
			if (((elementRenderer->isAnonymousBlockBox() == true))){
				HX_STACK_LINE(111)
				return this->blockBoxStyleComputer;
			}
			else{
				HX_STACK_LINE(116)
				{
					::cocktail::core::css::CSSPropertyValue _switch_1 = (elementRenderer->coreStyle->getComputedOrInitialProperty((int)0));
					switch((_switch_1)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
								HX_STACK_LINE(119)
								{
									::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
									switch((_switch_2)->GetIndex()){
										case 28: {
											HX_STACK_LINE(122)
											if (((elementRenderer->isReplaced == true))){
												HX_STACK_LINE(124)
												return this->embeddedBlockBoxStylesComputer;
											}
											else{
												HX_STACK_LINE(128)
												return this->blockBoxStyleComputer;
											}
										}
										;break;
										case 29: {
											HX_STACK_LINE(133)
											if (((elementRenderer->isReplaced == true))){
												HX_STACK_LINE(135)
												return this->embeddedInlineBlockBoxStylesComputer;
											}
											else{
												HX_STACK_LINE(139)
												return this->inlineBlockBoxStylesComputer;
											}
										}
										;break;
										case 30: {
											HX_STACK_LINE(143)
											if (((elementRenderer->isReplaced == true))){
												HX_STACK_LINE(145)
												return this->embeddedInlineBoxStylesComputer;
											}
											else{
												HX_STACK_LINE(149)
												return this->inlineBoxStylesComputer;
											}
										}
										;break;
										default: {
											HX_STACK_LINE(154)
											return null();
										}
									}
								}
							}
						}
						;break;
						default: {
							HX_STACK_LINE(158)
							return null();
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(84)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayoutManager_obj,getBoxStylesComputer,return )


LayoutManager_obj::LayoutManager_obj()
{
}

void LayoutManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LayoutManager);
	HX_MARK_MEMBER_NAME(positionedBoxStylesComputer,"positionedBoxStylesComputer");
	HX_MARK_MEMBER_NAME(inlineBoxStylesComputer,"inlineBoxStylesComputer");
	HX_MARK_MEMBER_NAME(inlineBlockBoxStylesComputer,"inlineBlockBoxStylesComputer");
	HX_MARK_MEMBER_NAME(floatBoxStylesComputer,"floatBoxStylesComputer");
	HX_MARK_MEMBER_NAME(embeddedPositionedBoxStylesComputer,"embeddedPositionedBoxStylesComputer");
	HX_MARK_MEMBER_NAME(embeddedInlineBoxStylesComputer,"embeddedInlineBoxStylesComputer");
	HX_MARK_MEMBER_NAME(embeddedInlineBlockBoxStylesComputer,"embeddedInlineBlockBoxStylesComputer");
	HX_MARK_MEMBER_NAME(embeddedFloatBoxStylesComputer,"embeddedFloatBoxStylesComputer");
	HX_MARK_MEMBER_NAME(embeddedBlockBoxStylesComputer,"embeddedBlockBoxStylesComputer");
	HX_MARK_MEMBER_NAME(blockBoxStyleComputer,"blockBoxStyleComputer");
	HX_MARK_END_CLASS();
}

void LayoutManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(positionedBoxStylesComputer,"positionedBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(inlineBoxStylesComputer,"inlineBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(inlineBlockBoxStylesComputer,"inlineBlockBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(floatBoxStylesComputer,"floatBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(embeddedPositionedBoxStylesComputer,"embeddedPositionedBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(embeddedInlineBoxStylesComputer,"embeddedInlineBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(embeddedInlineBlockBoxStylesComputer,"embeddedInlineBlockBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(embeddedFloatBoxStylesComputer,"embeddedFloatBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(embeddedBlockBoxStylesComputer,"embeddedBlockBoxStylesComputer");
	HX_VISIT_MEMBER_NAME(blockBoxStyleComputer,"blockBoxStyleComputer");
}

Dynamic LayoutManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getBoxStylesComputer") ) { return getBoxStylesComputer_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"blockBoxStyleComputer") ) { return blockBoxStyleComputer; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"floatBoxStylesComputer") ) { return floatBoxStylesComputer; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"inlineBoxStylesComputer") ) { return inlineBoxStylesComputer; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"positionedBoxStylesComputer") ) { return positionedBoxStylesComputer; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"inlineBlockBoxStylesComputer") ) { return inlineBlockBoxStylesComputer; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"embeddedFloatBoxStylesComputer") ) { return embeddedFloatBoxStylesComputer; }
		if (HX_FIELD_EQ(inName,"embeddedBlockBoxStylesComputer") ) { return embeddedBlockBoxStylesComputer; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"embeddedInlineBoxStylesComputer") ) { return embeddedInlineBoxStylesComputer; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"embeddedPositionedBoxStylesComputer") ) { return embeddedPositionedBoxStylesComputer; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"embeddedInlineBlockBoxStylesComputer") ) { return embeddedInlineBlockBoxStylesComputer; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LayoutManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"blockBoxStyleComputer") ) { blockBoxStyleComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::BlockBoxStylesComputer >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"floatBoxStylesComputer") ) { floatBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::FloatBoxStylesComputer >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"inlineBoxStylesComputer") ) { inlineBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::InLineBoxStylesComputer >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"positionedBoxStylesComputer") ) { positionedBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::PositionedBoxStylesComputer >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"inlineBlockBoxStylesComputer") ) { inlineBlockBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::InlineBlockBoxStylesComputer >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"embeddedFloatBoxStylesComputer") ) { embeddedFloatBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::EmbeddedFloatBoxStylesComputer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"embeddedBlockBoxStylesComputer") ) { embeddedBlockBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"embeddedInlineBoxStylesComputer") ) { embeddedInlineBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBoxStylesComputer >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"embeddedPositionedBoxStylesComputer") ) { embeddedPositionedBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::EmbeddedPositionedBoxStylesComputer >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"embeddedInlineBlockBoxStylesComputer") ) { embeddedInlineBlockBoxStylesComputer=inValue.Cast< ::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LayoutManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("positionedBoxStylesComputer"));
	outFields->push(HX_CSTRING("inlineBoxStylesComputer"));
	outFields->push(HX_CSTRING("inlineBlockBoxStylesComputer"));
	outFields->push(HX_CSTRING("floatBoxStylesComputer"));
	outFields->push(HX_CSTRING("embeddedPositionedBoxStylesComputer"));
	outFields->push(HX_CSTRING("embeddedInlineBoxStylesComputer"));
	outFields->push(HX_CSTRING("embeddedInlineBlockBoxStylesComputer"));
	outFields->push(HX_CSTRING("embeddedFloatBoxStylesComputer"));
	outFields->push(HX_CSTRING("embeddedBlockBoxStylesComputer"));
	outFields->push(HX_CSTRING("blockBoxStyleComputer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBoxStylesComputer"),
	HX_CSTRING("positionedBoxStylesComputer"),
	HX_CSTRING("inlineBoxStylesComputer"),
	HX_CSTRING("inlineBlockBoxStylesComputer"),
	HX_CSTRING("floatBoxStylesComputer"),
	HX_CSTRING("embeddedPositionedBoxStylesComputer"),
	HX_CSTRING("embeddedInlineBoxStylesComputer"),
	HX_CSTRING("embeddedInlineBlockBoxStylesComputer"),
	HX_CSTRING("embeddedFloatBoxStylesComputer"),
	HX_CSTRING("embeddedBlockBoxStylesComputer"),
	HX_CSTRING("blockBoxStyleComputer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LayoutManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LayoutManager_obj::__mClass,"__mClass");
};

Class LayoutManager_obj::__mClass;

void LayoutManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.LayoutManager"), hx::TCanCast< LayoutManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LayoutManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
