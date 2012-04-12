#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
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
#ifndef INCLUDED_cocktail_core_style_AbstractBodyCoreStyle
#include <cocktail/core/style/AbstractBodyCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractContainerCoreStyle
#include <cocktail/core/style/AbstractContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_BlockFormattingContext
#include <cocktail/core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_ContainerCoreStyle
#include <cocktail/port/flash_player/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void AbstractBodyCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",53)
	super::__construct(htmlElement);
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",55)
	this->_nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",60)
	this->_isDirty = false;
}
;
	return null();
}

AbstractBodyCoreStyle_obj::~AbstractBodyCoreStyle_obj() { }

Dynamic AbstractBodyCoreStyle_obj::__CreateEmpty() { return  new AbstractBodyCoreStyle_obj; }
hx::ObjectPtr< AbstractBodyCoreStyle_obj > AbstractBodyCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractBodyCoreStyle_obj > result = new AbstractBodyCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractBodyCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractBodyCoreStyle_obj > result = new AbstractBodyCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractBodyCoreStyle_obj::invalidate( Dynamic __o_immediate){
bool immediate = __o_immediate.Default(false);
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::invalidate");
{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",73)
		if (((bool((this->_isDirty == false)) || bool((immediate == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",78)
			this->_isDirty = true;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",79)
			Dynamic windowData = this->getWindowData();
			struct _Function_2_1{
				inline static Dynamic Block( Dynamic &windowData){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
					__result->Add(HX_CSTRING("data") , windowData,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",82)
			Dynamic lastPositionedHTMLElementData = _Function_2_1::Block(windowData);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",88)
			if (((immediate == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",89)
				this->scheduleLayout(windowData,lastPositionedHTMLElementData,windowData);
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",93)
				this->layout(windowData,lastPositionedHTMLElementData,windowData,null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,invalidate,(void))

Void AbstractBodyCoreStyle_obj::render( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::render")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",111)
		this->_nativeElements = this->_elementRenderer->getLayerRenderer()->render();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",112)
		this->_nativeElements->__Field(HX_CSTRING("reverse"))();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",113)
		this->attachNativeElements(this->_nativeElements);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,render,(void))

Void AbstractBodyCoreStyle_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::attachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,attachNativeElement,(void))

Void AbstractBodyCoreStyle_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::detachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,detachNativeElement,(void))

Void AbstractBodyCoreStyle_obj::attachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::attachNativeElements")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",145)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",145)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",145)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",147)
			this->attachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,attachNativeElements,(void))

Void AbstractBodyCoreStyle_obj::detachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::detachNativeElements")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",157)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",157)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",157)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",159)
			this->detachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,detachNativeElements,(void))

::cocktail::core::renderer::ElementRenderer AbstractBodyCoreStyle_obj::createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",172)
	::cocktail::core::renderer::ElementRenderer elementRenderer = ::cocktail::core::renderer::InitialBlockRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",173)
	elementRenderer->setLayerRenderer(::cocktail::core::renderer::LayerRenderer_obj::__new(elementRenderer));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",175)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,createElementRenderer,return )

Void AbstractBodyCoreStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::layout")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",190)
		this->detachNativeElements(this->_nativeElements);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",192)
		this->super::layout(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",193)
		this->render(this->_htmlElement->get_nativeElement());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractBodyCoreStyle_obj,layout,(void))

Void AbstractBodyCoreStyle_obj::insertHTMLElement( ::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::insertHTMLElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractBodyCoreStyle_obj,insertHTMLElement,(void))

Void AbstractBodyCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",215)
		this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractBodyCoreStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Dynamic AbstractBodyCoreStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",227)
	return this->getWindowData();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyCoreStyle_obj,getPositionedHTMLElementData,return )

bool AbstractBodyCoreStyle_obj::isInlineLevel( ){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::isInlineLevel")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",235)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyCoreStyle_obj,isInlineLevel,return )

bool AbstractBodyCoreStyle_obj::isOffsetParent( ){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::isOffsetParent")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",244)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyCoreStyle_obj,isOffsetParent,return )

::cocktail::port::flash_player::HTMLElement AbstractBodyCoreStyle_obj::getFirstPositionedAncestor( ){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::getFirstPositionedAncestor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",253)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyCoreStyle_obj,getFirstPositionedAncestor,return )

::cocktail::core::style::formatter::FormattingContext AbstractBodyCoreStyle_obj::getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",261)
	return ::cocktail::core::style::formatter::BlockFormattingContext_obj::__new(this->_elementRenderer);
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyCoreStyle_obj,getformattingContext,return )

bool AbstractBodyCoreStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractBodyCoreStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractBodyCoreStyle.hx",270)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyCoreStyle_obj,establishesNewFormattingContext,return )


AbstractBodyCoreStyle_obj::AbstractBodyCoreStyle_obj()
{
}

void AbstractBodyCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractBodyCoreStyle);
	HX_MARK_MEMBER_NAME(_nativeElements,"_nativeElements");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractBodyCoreStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
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
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { return _nativeElements; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"insertHTMLElement") ) { return insertHTMLElement_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"attachNativeElement") ) { return attachNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElement") ) { return detachNativeElement_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"attachNativeElements") ) { return attachNativeElements_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElements") ) { return detachNativeElements_dyn(); }
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

Dynamic AbstractBodyCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { _nativeElements=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractBodyCoreStyle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeElements"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nativeElements"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("render"),
	HX_CSTRING("attachNativeElement"),
	HX_CSTRING("detachNativeElement"),
	HX_CSTRING("attachNativeElements"),
	HX_CSTRING("detachNativeElements"),
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

Class AbstractBodyCoreStyle_obj::__mClass;

void AbstractBodyCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.AbstractBodyCoreStyle"), hx::TCanCast< AbstractBodyCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractBodyCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
