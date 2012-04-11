#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#include <cocktail/core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_background_InitialBlockBackgroundManager
#include <cocktail/core/background/InitialBlockBackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
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
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Window
#include <cocktail/port/flash_player/Window.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InitialBlockRenderer_obj::__construct(::cocktail::core::style::CoreStyle style)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",30)
	super::__construct(style);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",33)
	double width = ::cocktail::Lib_obj::get_window()->get_innerWidth();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",34)
	double height = ::cocktail::Lib_obj::get_window()->get_innerHeight();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",36)
	this->_bounds->__FieldRef(HX_CSTRING("width")) = width;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",37)
	this->_bounds->__FieldRef(HX_CSTRING("height")) = height;
}
;
	return null();
}

InitialBlockRenderer_obj::~InitialBlockRenderer_obj() { }

Dynamic InitialBlockRenderer_obj::__CreateEmpty() { return  new InitialBlockRenderer_obj; }
hx::ObjectPtr< InitialBlockRenderer_obj > InitialBlockRenderer_obj::__new(::cocktail::core::style::CoreStyle style)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic InitialBlockRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool InitialBlockRenderer_obj::isInitialContainer( ){
	HX_SOURCE_PUSH("InitialBlockRenderer_obj::isInitialContainer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",41)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(InitialBlockRenderer_obj,isInitialContainer,return )

Void InitialBlockRenderer_obj::init( ){
{
		HX_SOURCE_PUSH("InitialBlockRenderer_obj::init")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/InitialBlockRenderer.hx",46)
		this->_backgroundManager = ::cocktail::core::background::InitialBlockBackgroundManager_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialBlockRenderer_obj,init,(void))


InitialBlockRenderer_obj::InitialBlockRenderer_obj()
{
}

void InitialBlockRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialBlockRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InitialBlockRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isInitialContainer") ) { return isInitialContainer_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InitialBlockRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void InitialBlockRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isInitialContainer"),
	HX_CSTRING("init"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InitialBlockRenderer_obj::__mClass;

void InitialBlockRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InitialBlockRenderer"), hx::TCanCast< InitialBlockRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InitialBlockRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
