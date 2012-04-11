#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InlineBoxRenderer
#include <cocktail/core/renderer/InlineBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InlineBoxRenderer_obj::__construct(::cocktail::core::style::CoreStyle style)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InlineBoxRenderer.hx",16)
	super::__construct(style);
}
;
	return null();
}

InlineBoxRenderer_obj::~InlineBoxRenderer_obj() { }

Dynamic InlineBoxRenderer_obj::__CreateEmpty() { return  new InlineBoxRenderer_obj; }
hx::ObjectPtr< InlineBoxRenderer_obj > InlineBoxRenderer_obj::__new(::cocktail::core::style::CoreStyle style)
{  hx::ObjectPtr< InlineBoxRenderer_obj > result = new InlineBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic InlineBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineBoxRenderer_obj > result = new InlineBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic InlineBoxRenderer_obj::render( ){
	HX_SOURCE_PUSH("InlineBoxRenderer_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InlineBoxRenderer.hx",21)
	return this->renderBackground();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineBoxRenderer_obj,render,return )


InlineBoxRenderer_obj::InlineBoxRenderer_obj()
{
}

void InlineBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InlineBoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InlineBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void InlineBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InlineBoxRenderer_obj::__mClass;

void InlineBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InlineBoxRenderer"), hx::TCanCast< InlineBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InlineBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
