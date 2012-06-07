#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_renderer_BlockBoxRenderer
#include <core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_BoxRenderer
#include <core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_FlowBoxRenderer
#include <core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_InitialBlockRenderer
#include <core/renderer/InitialBlockRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_LayerRenderer
#include <core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_core_style_AbstractBodyStyle
#include <core/style/AbstractBodyStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractContainerStyle
#include <core/style/AbstractContainerStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_formatter_BlockFormattingContext
#include <core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_core_style_formatter_FormattingContext
#include <core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_port_flash_player_ContainerStyle
#include <port/flash_player/ContainerStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace style{

Void AbstractBodyStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",53)
	super::__construct(htmlElement);
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",55)
	this->_nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",60)
	this->_isDirty = false;
}
;
	return null();
}

AbstractBodyStyle_obj::~AbstractBodyStyle_obj() { }

Dynamic AbstractBodyStyle_obj::__CreateEmpty() { return  new AbstractBodyStyle_obj; }
hx::ObjectPtr< AbstractBodyStyle_obj > AbstractBodyStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractBodyStyle_obj > result = new AbstractBodyStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractBodyStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractBodyStyle_obj > result = new AbstractBodyStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractBodyStyle_obj::invalidate( ){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::invalidate")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",73)
		if (((this->_isDirty == false))){
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",76)
			this->_isDirty = true;
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",77)
			Dynamic windowData = this->getWindowData();
			struct _Function_2_1{
				inline static Dynamic Block( Dynamic &windowData){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
					__result->Add(HX_CSTRING("data") , windowData,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",80)
			Dynamic lastPositionedHTMLElementData = _Function_2_1::Block(windowData);
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",85)
			this->scheduleLayout(windowData,lastPositionedHTMLElementData,windowData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyStyle_obj,invalidate,(void))

Void AbstractBodyStyle_obj::render( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::render")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",101)
		this->_nativeElements = this->_elementRenderer->getLayerRenderer()->render();
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",102)
		this->_nativeElements->__Field(HX_CSTRING("reverse"))();
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",103)
		this->attachNativeElements(this->_nativeElements);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,render,(void))

Void AbstractBodyStyle_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::attachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,attachNativeElement,(void))

Void AbstractBodyStyle_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::detachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,detachNativeElement,(void))

Void AbstractBodyStyle_obj::attachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::attachNativeElements")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",135)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",135)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",135)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",137)
			this->attachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,attachNativeElements,(void))

Void AbstractBodyStyle_obj::detachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::detachNativeElements")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",147)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",147)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",147)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",149)
			this->detachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,detachNativeElements,(void))

::core::renderer::ElementRenderer AbstractBodyStyle_obj::createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractBodyStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",162)
	::core::renderer::ElementRenderer elementRenderer = ::core::renderer::InitialBlockRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",163)
	elementRenderer->setLayerRenderer(::core::renderer::LayerRenderer_obj::__new(elementRenderer));
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",165)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,createElementRenderer,return )

Void AbstractBodyStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::layout")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",180)
		this->detachNativeElements(this->_nativeElements);
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",182)
		this->super::layout(containingHTMLElementData,lastPositionedHTMLElementData,viewportData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",183)
		this->render(this->_htmlElement->get_nativeElement());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractBodyStyle_obj,layout,(void))

Void AbstractBodyStyle_obj::insertHTMLElement( ::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::insertHTMLElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractBodyStyle_obj,insertHTMLElement,(void))

Void AbstractBodyStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractBodyStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",205)
		this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractBodyStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Dynamic AbstractBodyStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractBodyStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",217)
	return this->getWindowData();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyStyle_obj,getPositionedHTMLElementData,return )

bool AbstractBodyStyle_obj::isInlineLevel( ){
	HX_SOURCE_PUSH("AbstractBodyStyle_obj::isInlineLevel")
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",225)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyStyle_obj,isInlineLevel,return )

::core::style::formatter::FormattingContext AbstractBodyStyle_obj::getformattingContext( ::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("AbstractBodyStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",233)
	return ::core::style::formatter::BlockFormattingContext_obj::__new(this->_elementRenderer);
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractBodyStyle_obj,getformattingContext,return )

bool AbstractBodyStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractBodyStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/core/style/AbstractBodyStyle.hx",242)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractBodyStyle_obj,establishesNewFormattingContext,return )


AbstractBodyStyle_obj::AbstractBodyStyle_obj()
{
}

void AbstractBodyStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractBodyStyle);
	HX_MARK_MEMBER_NAME(_nativeElements,"_nativeElements");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractBodyStyle_obj::__Field(const ::String &inName)
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

Dynamic AbstractBodyStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { _nativeElements=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractBodyStyle_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("getformattingContext"),
	HX_CSTRING("establishesNewFormattingContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractBodyStyle_obj::__mClass;

void AbstractBodyStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.AbstractBodyStyle"), hx::TCanCast< AbstractBodyStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractBodyStyle_obj::__boot()
{
}

} // end namespace core
} // end namespace style
