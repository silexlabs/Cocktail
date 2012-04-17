#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
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
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace renderer{

Void FlowBoxRenderer_obj::__construct(::port::flash_player::Style style)
{
{
	HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",30)
	super::__construct(style);
}
;
	return null();
}

FlowBoxRenderer_obj::~FlowBoxRenderer_obj() { }

Dynamic FlowBoxRenderer_obj::__CreateEmpty() { return  new FlowBoxRenderer_obj; }
hx::ObjectPtr< FlowBoxRenderer_obj > FlowBoxRenderer_obj::__new(::port::flash_player::Style style)
{  hx::ObjectPtr< FlowBoxRenderer_obj > result = new FlowBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic FlowBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlowBoxRenderer_obj > result = new FlowBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FlowBoxRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("FlowBoxRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",40)
		this->super::dispose();
		HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",42)
		{
			HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",42)
			int _g1 = (int)0;
			int _g = this->_childNodes->length;
			HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",42)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",42)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",44)
				::core::renderer::ElementRenderer child = this->_childNodes->__get(i);
				HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",45)
				child->dispose();
			}
		}
		HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",47)
		this->_childNodes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlowBoxRenderer_obj,dispose,(void))

bool FlowBoxRenderer_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("FlowBoxRenderer_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",55)
	return this->_style->establishesNewFormattingContext();
}


HX_DEFINE_DYNAMIC_FUNC0(FlowBoxRenderer_obj,establishesNewFormattingContext,return )

bool FlowBoxRenderer_obj::isEmbedded( ){
	HX_SOURCE_PUSH("FlowBoxRenderer_obj::isEmbedded")
	HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",60)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlowBoxRenderer_obj,isEmbedded,return )

bool FlowBoxRenderer_obj::canHaveChildren( ){
	HX_SOURCE_PUSH("FlowBoxRenderer_obj::canHaveChildren")
	HX_SOURCE_POS("../../src/core/renderer/FlowBoxRenderer.hx",65)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(FlowBoxRenderer_obj,canHaveChildren,return )


FlowBoxRenderer_obj::FlowBoxRenderer_obj()
{
}

void FlowBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlowBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FlowBoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isEmbedded") ) { return isEmbedded_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"canHaveChildren") ) { return canHaveChildren_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"establishesNewFormattingContext") ) { return establishesNewFormattingContext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FlowBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FlowBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("establishesNewFormattingContext"),
	HX_CSTRING("isEmbedded"),
	HX_CSTRING("canHaveChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FlowBoxRenderer_obj::__mClass;

void FlowBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.renderer.FlowBoxRenderer"), hx::TCanCast< FlowBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FlowBoxRenderer_obj::__boot()
{
}

} // end namespace core
} // end namespace renderer
