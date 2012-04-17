#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InitialBlockRenderer
#include <cocktail/core/renderer/InitialBlockRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BodyCoreStyle
#include <cocktail/core/style/BodyCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ContainerCoreStyle
#include <cocktail/core/style/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_BlockFormattingContext
#include <cocktail/core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#include <cocktail/port/flash_player/HTMLDocument.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void BodyCoreStyle_obj::__construct(::cocktail::core::html::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",41)
	super::__construct(htmlElement);
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",46)
	this->_isDirty = false;
}
;
	return null();
}

BodyCoreStyle_obj::~BodyCoreStyle_obj() { }

Dynamic BodyCoreStyle_obj::__CreateEmpty() { return  new BodyCoreStyle_obj; }
hx::ObjectPtr< BodyCoreStyle_obj > BodyCoreStyle_obj::__new(::cocktail::core::html::HTMLElement htmlElement)
{  hx::ObjectPtr< BodyCoreStyle_obj > result = new BodyCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic BodyCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BodyCoreStyle_obj > result = new BodyCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BodyCoreStyle_obj::invalidate( Dynamic __o_immediate){
bool immediate = __o_immediate.Default(false);
	HX_SOURCE_PUSH("BodyCoreStyle_obj::invalidate");
{
		HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",59)
		if (((bool((this->_isDirty == false)) || bool((immediate == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",64)
			this->_isDirty = true;
			HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",65)
			::cocktail::port::flash_player::HTMLDocument htmlDocument = this->_htmlElement->get_ownerDocument();
			HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",66)
			htmlDocument->invalidate(immediate);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BodyCoreStyle_obj,invalidate,(void))

::cocktail::core::renderer::ElementRenderer BodyCoreStyle_obj::createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",79)
	::cocktail::core::renderer::ElementRenderer elementRenderer = ::cocktail::core::renderer::InitialBlockRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",80)
	elementRenderer->setLayerRenderer(::cocktail::core::renderer::LayerRenderer_obj::__new(elementRenderer));
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",82)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(BodyCoreStyle_obj,createElementRenderer,return )

Void BodyCoreStyle_obj::layout( ){
{
		HX_SOURCE_PUSH("BodyCoreStyle_obj::layout")
		HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",106)
		Dynamic windowData = this->getWindowData();
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &windowData){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
				__result->Add(HX_CSTRING("data") , windowData,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",109)
		Dynamic lastPositionedHTMLElementData = _Function_1_1::Block(windowData);
		HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",114)
		this->flow(windowData,windowData,lastPositionedHTMLElementData,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,layout,(void))

Void BodyCoreStyle_obj::insertHTMLElement( ::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("BodyCoreStyle_obj::insertHTMLElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BodyCoreStyle_obj,insertHTMLElement,(void))

Void BodyCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("BodyCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",136)
		this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BodyCoreStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Dynamic BodyCoreStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",148)
	return this->getWindowData();
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,getPositionedHTMLElementData,return )

bool BodyCoreStyle_obj::isInlineLevel( ){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::isInlineLevel")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",156)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,isInlineLevel,return )

bool BodyCoreStyle_obj::isOffsetParent( ){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::isOffsetParent")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",165)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,isOffsetParent,return )

::cocktail::core::html::HTMLElement BodyCoreStyle_obj::getFirstPositionedAncestor( ){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::getFirstPositionedAncestor")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",174)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,getFirstPositionedAncestor,return )

::cocktail::core::style::formatter::FormattingContext BodyCoreStyle_obj::getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",182)
	return ::cocktail::core::style::formatter::BlockFormattingContext_obj::__new(this->_elementRenderer);
}


HX_DEFINE_DYNAMIC_FUNC1(BodyCoreStyle_obj,getformattingContext,return )

bool BodyCoreStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("BodyCoreStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/BodyCoreStyle.hx",191)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BodyCoreStyle_obj,establishesNewFormattingContext,return )


BodyCoreStyle_obj::BodyCoreStyle_obj()
{
}

void BodyCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BodyCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BodyCoreStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isOffsetParent") ) { return isOffsetParent_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"insertHTMLElement") ) { return insertHTMLElement_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getformattingContext") ) { return getformattingContext_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getFirstPositionedAncestor") ) { return getFirstPositionedAncestor_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getPositionedHTMLElementData") ) { return getPositionedHTMLElementData_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"establishesNewFormattingContext") ) { return establishesNewFormattingContext_dyn(); }
		break;
	case 48:
		if (HX_FIELD_EQ(inName,"positionAbsolutelyPositionedHTMLElementsIfNeeded") ) { return positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BodyCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BodyCoreStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("invalidate"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("layout"),
	HX_CSTRING("insertHTMLElement"),
	HX_CSTRING("positionAbsolutelyPositionedHTMLElementsIfNeeded"),
	HX_CSTRING("getPositionedHTMLElementData"),
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("isOffsetParent"),
	HX_CSTRING("getFirstPositionedAncestor"),
	HX_CSTRING("getformattingContext"),
	HX_CSTRING("establishesNewFormattingContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BodyCoreStyle_obj::__mClass;

void BodyCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.BodyCoreStyle"), hx::TCanCast< BodyCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BodyCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
