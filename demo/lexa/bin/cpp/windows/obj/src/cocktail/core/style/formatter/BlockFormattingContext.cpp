#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
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
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_floats_FloatsManager
#include <cocktail/core/style/floats/FloatsManager.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_BlockFormattingContext
#include <cocktail/core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace formatter{

Void BlockFormattingContext_obj::__construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",34)
	super::__construct(formattingContextRoot);
}
;
	return null();
}

BlockFormattingContext_obj::~BlockFormattingContext_obj() { }

Dynamic BlockFormattingContext_obj::__CreateEmpty() { return  new BlockFormattingContext_obj; }
hx::ObjectPtr< BlockFormattingContext_obj > BlockFormattingContext_obj::__new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{  hx::ObjectPtr< BlockFormattingContext_obj > result = new BlockFormattingContext_obj();
	result->__construct(formattingContextRoot);
	return result;}

Dynamic BlockFormattingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlockFormattingContext_obj > result = new BlockFormattingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BlockFormattingContext_obj::doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext){
{
		HX_SOURCE_PUSH("BlockFormattingContext_obj::doFormat")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",40)
		this->doFormat2(this->_formattingContextRoot,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockFormattingContext_obj,doFormat,(void))

Void BlockFormattingContext_obj::doFormat2( ::cocktail::core::renderer::ElementRenderer elementRenderer,int concatenatedX){
{
		HX_SOURCE_PUSH("BlockFormattingContext_obj::doFormat2")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",47)
		int currentAddedSiblingsHeight = (int)0;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",50)
		hx::AddEq(concatenatedX,(elementRenderer->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginLeft")) + elementRenderer->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",52)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",52)
			int _g1 = (int)0;
			int _g = elementRenderer->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",52)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",52)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",55)
				::cocktail::core::renderer::ElementRenderer child = elementRenderer->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",58)
				int marginTop = child->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",60)
				if (((i == (int)0))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",61)
					if (((child->get_firstChild() != null()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",64)
						::cocktail::core::renderer::ElementRenderer firstChild = child->get_firstChild();
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",65)
						if (((bool((firstChild->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop")) > marginTop)) && bool((child->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")) == (int)0))))){
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",66)
							marginTop = firstChild->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
						}
					}
				}
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",73)
				if (((child->hasChildNodes() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",74)
					if (((child->establishesNewFormattingContext() == false))){
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",76)
						this->doFormat2(child,concatenatedX);
					}
				}
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",83)
				int marginBottom = this->getCollapsedMarginBottom(child);
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",87)
				double x = (concatenatedX + child->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginLeft")));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",88)
				double y = ((this->_formattingContextData->__Field(HX_CSTRING("y")) + marginTop) + elementRenderer->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",89)
				Dynamic computedStyle = child->getCoreStyle()->getComputedStyle();
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",90)
				double width = ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",91)
				double height = ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
				struct _Function_3_1{
					inline static Dynamic Block( double &y,double &width,double &x,double &height){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("x") , x,false);
						__result->Add(HX_CSTRING("y") , y,false);
						__result->Add(HX_CSTRING("width") , width,false);
						__result->Add(HX_CSTRING("height") , height,false);
						return __result;
					}
				};
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",93)
				child->setBounds(_Function_3_1::Block(y,width,x,height));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",100)
				hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),((::Math_obj::round(child->getBounds()->__Field(HX_CSTRING("height"))) + marginTop) + marginBottom));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",101)
				hx::AddEq(currentAddedSiblingsHeight,((::Math_obj::round(child->getBounds()->__Field(HX_CSTRING("height"))) + marginTop) + marginBottom));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",105)
		hx::SubEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),currentAddedSiblingsHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BlockFormattingContext_obj,doFormat2,(void))

int BlockFormattingContext_obj::getCollapsedMarginBottom( ::cocktail::core::renderer::ElementRenderer child){
	HX_SOURCE_PUSH("BlockFormattingContext_obj::getCollapsedMarginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",110)
	int marginBottom = child->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginBottom"));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",112)
	if (((child->get_nextSibling() != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",114)
		::cocktail::core::renderer::ElementRenderer nextSibling = child->get_nextSibling();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",116)
		if (((nextSibling->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop")) > marginBottom))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",117)
			marginBottom = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",121)
			hx::SubEq(marginBottom,nextSibling->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop")));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",126)
	return marginBottom;
}


HX_DEFINE_DYNAMIC_FUNC1(BlockFormattingContext_obj,getCollapsedMarginBottom,return )

Void BlockFormattingContext_obj::insertFloat( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("BlockFormattingContext_obj::insertFloat")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",135)
		::cocktail::core::renderer::FlowBoxRenderer parent = element->get_parentNode();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",136)
		Dynamic floatData = this->_floatsManager->computeFloatData(element,this->_formattingContextData,::Math_obj::round(parent->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",138)
		double x = (floatData->__Field(HX_CSTRING("x")) + parent->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",139)
		double y = (floatData->__Field(HX_CSTRING("y")) + parent->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",140)
		double width = floatData->__Field(HX_CSTRING("width"));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",141)
		double height = floatData->__Field(HX_CSTRING("height"));
		struct _Function_1_1{
			inline static Dynamic Block( double &y,double &width,double &x,double &height){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , x,false);
				__result->Add(HX_CSTRING("y") , y,false);
				__result->Add(HX_CSTRING("width") , width,false);
				__result->Add(HX_CSTRING("height") , height,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/BlockFormattingContext.hx",143)
		element->setBounds(_Function_1_1::Block(y,width,x,height));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockFormattingContext_obj,insertFloat,(void))


BlockFormattingContext_obj::BlockFormattingContext_obj()
{
}

void BlockFormattingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlockFormattingContext);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BlockFormattingContext_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"doFormat") ) { return doFormat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"doFormat2") ) { return doFormat2_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"insertFloat") ) { return insertFloat_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getCollapsedMarginBottom") ) { return getCollapsedMarginBottom_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BlockFormattingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BlockFormattingContext_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doFormat"),
	HX_CSTRING("doFormat2"),
	HX_CSTRING("getCollapsedMarginBottom"),
	HX_CSTRING("insertFloat"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BlockFormattingContext_obj::__mClass;

void BlockFormattingContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.formatter.BlockFormattingContext"), hx::TCanCast< BlockFormattingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BlockFormattingContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter
