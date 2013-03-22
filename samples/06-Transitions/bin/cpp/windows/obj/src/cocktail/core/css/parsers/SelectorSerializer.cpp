#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#include <cocktail/core/css/AttributeSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#include <cocktail/core/css/CombinatorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#include <cocktail/core/css/LinkPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#include <cocktail/core/css/SelectorComponentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#include <cocktail/core/css/UIElementStatesValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_SelectorSerializer
#include <cocktail/core/css/parsers/SelectorSerializer.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

Void SelectorSerializer_obj::__construct()
{
HX_STACK_PUSH("SelectorSerializer::new","cocktail/core/css/parsers/SelectorSerializer.hx",26);
{
}
;
	return null();
}

SelectorSerializer_obj::~SelectorSerializer_obj() { }

Dynamic SelectorSerializer_obj::__CreateEmpty() { return  new SelectorSerializer_obj; }
hx::ObjectPtr< SelectorSerializer_obj > SelectorSerializer_obj::__new()
{  hx::ObjectPtr< SelectorSerializer_obj > result = new SelectorSerializer_obj();
	result->__construct();
	return result;}

Dynamic SelectorSerializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SelectorSerializer_obj > result = new SelectorSerializer_obj();
	result->__construct();
	return result;}

::String SelectorSerializer_obj::serialize( ::cocktail::core::css::SelectorVO selector){
	HX_STACK_PUSH("SelectorSerializer::serialize","cocktail/core/css/parsers/SelectorSerializer.hx",35);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_LINE(36)
	::String serializedSelector = HX_CSTRING("");		HX_STACK_VAR(serializedSelector,"serializedSelector");
	HX_STACK_LINE(38)
	{
		HX_STACK_LINE(38)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = selector->components->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(38)
		while(((_g1 < _g))){
			HX_STACK_LINE(38)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(40)
			::cocktail::core::css::SelectorComponentValue component = selector->components->__get(i);		HX_STACK_VAR(component,"component");
			HX_STACK_LINE(42)
			{
				::cocktail::core::css::SelectorComponentValue _switch_1 = (component);
				switch((_switch_1)->GetIndex()){
					case 0: {
						::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_1->__Param(0);
{
							HX_STACK_LINE(44)
							hx::AddEq(serializedSelector,::cocktail::core::css::parsers::SelectorSerializer_obj::serializeSimpleSelectorSequence(value));
						}
					}
					;break;
					case 1: {
						::cocktail::core::css::CombinatorValue value = _switch_1->__Param(0);
{
							HX_STACK_LINE(47)
							hx::AddEq(serializedSelector,::cocktail::core::css::parsers::SelectorSerializer_obj::serializeCombinator(value));
						}
					}
					;break;
				}
			}
		}
	}
	HX_STACK_LINE(52)
	hx::AddEq(serializedSelector,::cocktail::core::css::parsers::SelectorSerializer_obj::serializePseudoElement(selector->pseudoElement));
	HX_STACK_LINE(55)
	return serializedSelector;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serialize,return )

::String SelectorSerializer_obj::serializePseudoElement( ::cocktail::core::css::PseudoElementSelectorValue pseudoElement){
	HX_STACK_PUSH("SelectorSerializer::serializePseudoElement","cocktail/core/css/parsers/SelectorSerializer.hx",63);
	HX_STACK_ARG(pseudoElement,"pseudoElement");
	HX_STACK_LINE(63)
	{
		::cocktail::core::css::PseudoElementSelectorValue _switch_2 = (pseudoElement);
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_STACK_LINE(66)
				return HX_CSTRING("");
			}
			;break;
			case 2: {
				HX_STACK_LINE(69)
				return HX_CSTRING("::first-letter");
			}
			;break;
			case 1: {
				HX_STACK_LINE(72)
				return HX_CSTRING("::first-line");
			}
			;break;
			case 3: {
				HX_STACK_LINE(75)
				return HX_CSTRING("::before");
			}
			;break;
			case 4: {
				HX_STACK_LINE(78)
				return HX_CSTRING("::after");
			}
			;break;
		}
	}
	HX_STACK_LINE(63)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializePseudoElement,return )

::String SelectorSerializer_obj::serializeSimpleSelectorSequence( ::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence){
	HX_STACK_PUSH("SelectorSerializer::serializeSimpleSelectorSequence","cocktail/core/css/parsers/SelectorSerializer.hx",84);
	HX_STACK_ARG(simpleSelectorSequence,"simpleSelectorSequence");
	HX_STACK_LINE(85)
	::String serializedSimpleSelectorSequence = HX_CSTRING("");		HX_STACK_VAR(serializedSimpleSelectorSequence,"serializedSimpleSelectorSequence");
	HX_STACK_LINE(87)
	hx::AddEq(serializedSimpleSelectorSequence,::cocktail::core::css::parsers::SelectorSerializer_obj::serializeStartValue(simpleSelectorSequence->startValue));
	HX_STACK_LINE(89)
	{
		HX_STACK_LINE(89)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = simpleSelectorSequence->simpleSelectors->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(89)
		while(((_g1 < _g))){
			HX_STACK_LINE(89)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(91)
			::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelector = simpleSelectorSequence->simpleSelectors->__get(i);		HX_STACK_VAR(simpleSelector,"simpleSelector");
			HX_STACK_LINE(92)
			hx::AddEq(serializedSimpleSelectorSequence,::cocktail::core::css::parsers::SelectorSerializer_obj::serializeSimpleSelector(simpleSelector));
		}
	}
	HX_STACK_LINE(95)
	return serializedSimpleSelectorSequence;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeSimpleSelectorSequence,return )

::String SelectorSerializer_obj::serializeCombinator( ::cocktail::core::css::CombinatorValue combinator){
	HX_STACK_PUSH("SelectorSerializer::serializeCombinator","cocktail/core/css/parsers/SelectorSerializer.hx",99);
	HX_STACK_ARG(combinator,"combinator");
	HX_STACK_LINE(99)
	{
		::cocktail::core::css::CombinatorValue _switch_3 = (combinator);
		switch((_switch_3)->GetIndex()){
			case 0: {
				HX_STACK_LINE(102)
				return HX_CSTRING(" ");
			}
			;break;
			case 1: {
				HX_STACK_LINE(105)
				return HX_CSTRING(" > ");
			}
			;break;
			case 2: {
				HX_STACK_LINE(108)
				return HX_CSTRING(" + ");
			}
			;break;
			case 3: {
				HX_STACK_LINE(111)
				return HX_CSTRING(" ~ ");
			}
			;break;
		}
	}
	HX_STACK_LINE(99)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeCombinator,return )

::String SelectorSerializer_obj::serializeStartValue( ::cocktail::core::css::SimpleSelectorSequenceStartValue selectorStartValue){
	HX_STACK_PUSH("SelectorSerializer::serializeStartValue","cocktail/core/css/parsers/SelectorSerializer.hx",117);
	HX_STACK_ARG(selectorStartValue,"selectorStartValue");
	HX_STACK_LINE(117)
	{
		::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_4 = (selectorStartValue);
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_STACK_LINE(120)
				return HX_CSTRING("*");
			}
			;break;
			case 1: {
				::String value = _switch_4->__Param(0);
{
					HX_STACK_LINE(123)
					return value;
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(117)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeStartValue,return )

::String SelectorSerializer_obj::serializeSimpleSelector( ::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeSimpleSelector","cocktail/core/css/parsers/SelectorSerializer.hx",129);
	HX_STACK_ARG(simpleSelector,"simpleSelector");
	HX_STACK_LINE(129)
	{
		::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_5 = (simpleSelector);
		switch((_switch_5)->GetIndex()){
			case 3: {
				::String value = _switch_5->__Param(0);
{
					HX_STACK_LINE(132)
					return (HX_CSTRING("#") + value);
				}
			}
			;break;
			case 2: {
				::String value = _switch_5->__Param(0);
{
					HX_STACK_LINE(135)
					return (HX_CSTRING(".") + value);
				}
			}
			;break;
			case 0: {
				::cocktail::core::css::AttributeSelectorValue value = _switch_5->__Param(0);
{
					HX_STACK_LINE(138)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeAttributeSelector(value);
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::PseudoClassSelectorValue value = _switch_5->__Param(0);
{
					HX_STACK_LINE(141)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializePseudoClassSelector(value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(129)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeSimpleSelector,return )

::String SelectorSerializer_obj::serializeAttributeSelector( ::cocktail::core::css::AttributeSelectorValue attributeSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeAttributeSelector","cocktail/core/css/parsers/SelectorSerializer.hx",147);
	HX_STACK_ARG(attributeSelector,"attributeSelector");
	HX_STACK_LINE(147)
	{
		::cocktail::core::css::AttributeSelectorValue _switch_6 = (attributeSelector);
		switch((_switch_6)->GetIndex()){
			case 0: {
				::String value = _switch_6->__Param(0);
{
					HX_STACK_LINE(150)
					return ((HX_CSTRING("[") + value) + HX_CSTRING("]"));
				}
			}
			;break;
			case 1: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(153)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
			case 2: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(156)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("~=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
			case 3: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(159)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("^=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
			case 4: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(162)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("$=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
			case 5: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(165)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("*=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
			case 6: {
				::String value = _switch_6->__Param(1);
				::String name = _switch_6->__Param(0);
{
					HX_STACK_LINE(168)
					return ((((HX_CSTRING("[") + name) + HX_CSTRING("|=\"")) + value) + HX_CSTRING("\"]"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(147)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeAttributeSelector,return )

::String SelectorSerializer_obj::serializePseudoClassSelector( ::cocktail::core::css::PseudoClassSelectorValue pseudoClassSelector){
	HX_STACK_PUSH("SelectorSerializer::serializePseudoClassSelector","cocktail/core/css/parsers/SelectorSerializer.hx",174);
	HX_STACK_ARG(pseudoClassSelector,"pseudoClassSelector");
	HX_STACK_LINE(174)
	{
		::cocktail::core::css::PseudoClassSelectorValue _switch_7 = (pseudoClassSelector);
		switch((_switch_7)->GetIndex()){
			case 0: {
				::cocktail::core::css::StructuralPseudoClassSelectorValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(177)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeStructuralPseudoClassSelector(value);
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::LinkPseudoClassValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(180)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeLinkPseudoClassSelector(value);
				}
			}
			;break;
			case 2: {
				HX_STACK_LINE(183)
				return HX_CSTRING(":target");
			}
			;break;
			case 3: {
				Array< ::String > value = _switch_7->__Param(0);
{
					HX_STACK_LINE(186)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeLangPseudoClassSelector(value);
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::UserActionPseudoClassValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(189)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeUserActionPseudoClassSelector(value);
				}
			}
			;break;
			case 5: {
				::cocktail::core::css::UIElementStatesValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(192)
					return ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeUIElementStatePseudoClass(value);
				}
			}
			;break;
			case 6: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_7->__Param(0);
{
					HX_STACK_LINE(195)
					return ((HX_CSTRING(":not(") + ::cocktail::core::css::parsers::SelectorSerializer_obj::serializeSimpleSelectorSequence(value)) + HX_CSTRING(")"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(174)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializePseudoClassSelector,return )

::String SelectorSerializer_obj::serializeUIElementStatePseudoClass( ::cocktail::core::css::UIElementStatesValue uiElementStateSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeUIElementStatePseudoClass","cocktail/core/css/parsers/SelectorSerializer.hx",201);
	HX_STACK_ARG(uiElementStateSelector,"uiElementStateSelector");
	HX_STACK_LINE(201)
	{
		::cocktail::core::css::UIElementStatesValue _switch_8 = (uiElementStateSelector);
		switch((_switch_8)->GetIndex()){
			case 0: {
				HX_STACK_LINE(204)
				return HX_CSTRING(":enabled");
			}
			;break;
			case 1: {
				HX_STACK_LINE(207)
				return HX_CSTRING(":disabled");
			}
			;break;
			case 2: {
				HX_STACK_LINE(210)
				return HX_CSTRING(":checked");
			}
			;break;
		}
	}
	HX_STACK_LINE(201)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeUIElementStatePseudoClass,return )

::String SelectorSerializer_obj::serializeLangPseudoClassSelector( Array< ::String > langs){
	HX_STACK_PUSH("SelectorSerializer::serializeLangPseudoClassSelector","cocktail/core/css/parsers/SelectorSerializer.hx",216);
	HX_STACK_ARG(langs,"langs");
	HX_STACK_LINE(217)
	::String serializedLangSelector = HX_CSTRING(":lang(");		HX_STACK_VAR(serializedLangSelector,"serializedLangSelector");
	HX_STACK_LINE(219)
	{
		HX_STACK_LINE(219)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = langs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(219)
		while(((_g1 < _g))){
			HX_STACK_LINE(219)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(221)
			hx::AddEq(serializedLangSelector,langs->__get(i));
			HX_STACK_LINE(222)
			if (((i < langs->length))){
				HX_STACK_LINE(223)
				hx::AddEq(serializedLangSelector,HX_CSTRING("-"));
			}
		}
	}
	HX_STACK_LINE(228)
	hx::AddEq(serializedLangSelector,HX_CSTRING(")"));
	HX_STACK_LINE(229)
	return serializedLangSelector;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeLangPseudoClassSelector,return )

::String SelectorSerializer_obj::serializeLinkPseudoClassSelector( ::cocktail::core::css::LinkPseudoClassValue linkPseudoClassSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeLinkPseudoClassSelector","cocktail/core/css/parsers/SelectorSerializer.hx",233);
	HX_STACK_ARG(linkPseudoClassSelector,"linkPseudoClassSelector");
	HX_STACK_LINE(233)
	{
		::cocktail::core::css::LinkPseudoClassValue _switch_9 = (linkPseudoClassSelector);
		switch((_switch_9)->GetIndex()){
			case 1: {
				HX_STACK_LINE(236)
				return HX_CSTRING(":visited");
			}
			;break;
			case 0: {
				HX_STACK_LINE(239)
				return HX_CSTRING(":link");
			}
			;break;
		}
	}
	HX_STACK_LINE(233)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeLinkPseudoClassSelector,return )

::String SelectorSerializer_obj::serializeUserActionPseudoClassSelector( ::cocktail::core::css::UserActionPseudoClassValue userActionPseudoClassSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeUserActionPseudoClassSelector","cocktail/core/css/parsers/SelectorSerializer.hx",245);
	HX_STACK_ARG(userActionPseudoClassSelector,"userActionPseudoClassSelector");
	HX_STACK_LINE(245)
	{
		::cocktail::core::css::UserActionPseudoClassValue _switch_10 = (userActionPseudoClassSelector);
		switch((_switch_10)->GetIndex()){
			case 0: {
				HX_STACK_LINE(248)
				return HX_CSTRING(":active");
			}
			;break;
			case 1: {
				HX_STACK_LINE(251)
				return HX_CSTRING(":hover");
			}
			;break;
			case 2: {
				HX_STACK_LINE(254)
				return HX_CSTRING(":focus");
			}
			;break;
		}
	}
	HX_STACK_LINE(245)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeUserActionPseudoClassSelector,return )

::String SelectorSerializer_obj::serializeStructuralPseudoClassSelector( ::cocktail::core::css::StructuralPseudoClassSelectorValue structuralpseudoClassSelector){
	HX_STACK_PUSH("SelectorSerializer::serializeStructuralPseudoClassSelector","cocktail/core/css/parsers/SelectorSerializer.hx",260);
	HX_STACK_ARG(structuralpseudoClassSelector,"structuralpseudoClassSelector");
	HX_STACK_LINE(260)
	{
		::cocktail::core::css::StructuralPseudoClassSelectorValue _switch_11 = (structuralpseudoClassSelector);
		switch((_switch_11)->GetIndex()){
			case 0: {
				HX_STACK_LINE(263)
				return HX_CSTRING(":root");
			}
			;break;
			case 1: {
				HX_STACK_LINE(266)
				return HX_CSTRING(":first-child");
			}
			;break;
			case 2: {
				HX_STACK_LINE(269)
				return HX_CSTRING(":last-child");
			}
			;break;
			case 3: {
				HX_STACK_LINE(272)
				return HX_CSTRING(":first-of-type");
			}
			;break;
			case 4: {
				HX_STACK_LINE(275)
				return HX_CSTRING(":last-of-type");
			}
			;break;
			case 5: {
				HX_STACK_LINE(278)
				return HX_CSTRING(":only-child");
			}
			;break;
			case 6: {
				HX_STACK_LINE(281)
				return HX_CSTRING(":only-of-type");
			}
			;break;
			case 7: {
				HX_STACK_LINE(284)
				return HX_CSTRING(":empty");
			}
			;break;
			default: {
				HX_STACK_LINE(288)
				return HX_CSTRING("");
			}
		}
	}
	HX_STACK_LINE(260)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorSerializer_obj,serializeStructuralPseudoClassSelector,return )


SelectorSerializer_obj::SelectorSerializer_obj()
{
}

void SelectorSerializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SelectorSerializer);
	HX_MARK_END_CLASS();
}

void SelectorSerializer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic SelectorSerializer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"serializeCombinator") ) { return serializeCombinator_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeStartValue") ) { return serializeStartValue_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"serializePseudoElement") ) { return serializePseudoElement_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"serializeSimpleSelector") ) { return serializeSimpleSelector_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"serializeAttributeSelector") ) { return serializeAttributeSelector_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"serializePseudoClassSelector") ) { return serializePseudoClassSelector_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"serializeSimpleSelectorSequence") ) { return serializeSimpleSelectorSequence_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"serializeLangPseudoClassSelector") ) { return serializeLangPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeLinkPseudoClassSelector") ) { return serializeLinkPseudoClassSelector_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"serializeUIElementStatePseudoClass") ) { return serializeUIElementStatePseudoClass_dyn(); }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"serializeUserActionPseudoClassSelector") ) { return serializeUserActionPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeStructuralPseudoClassSelector") ) { return serializeStructuralPseudoClassSelector_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SelectorSerializer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SelectorSerializer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("serialize"),
	HX_CSTRING("serializePseudoElement"),
	HX_CSTRING("serializeSimpleSelectorSequence"),
	HX_CSTRING("serializeCombinator"),
	HX_CSTRING("serializeStartValue"),
	HX_CSTRING("serializeSimpleSelector"),
	HX_CSTRING("serializeAttributeSelector"),
	HX_CSTRING("serializePseudoClassSelector"),
	HX_CSTRING("serializeUIElementStatePseudoClass"),
	HX_CSTRING("serializeLangPseudoClassSelector"),
	HX_CSTRING("serializeLinkPseudoClassSelector"),
	HX_CSTRING("serializeUserActionPseudoClassSelector"),
	HX_CSTRING("serializeStructuralPseudoClassSelector"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SelectorSerializer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorSerializer_obj::__mClass,"__mClass");
};

Class SelectorSerializer_obj::__mClass;

void SelectorSerializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.SelectorSerializer"), hx::TCanCast< SelectorSerializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SelectorSerializer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
