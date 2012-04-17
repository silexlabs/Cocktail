#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_core_background_BackgroundManager
#include <core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_core_background_InitialBlockBackgroundManager
#include <core/background/InitialBlockBackgroundManager.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
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
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_window_AbstractWindow
#include <core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
#ifndef INCLUDED_port_flash_player_Window
#include <port/flash_player/Window.h>
#endif
namespace core{
namespace renderer{

Void InitialBlockRenderer_obj::__construct(::port::flash_player::Style style)
{
{
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",30)
	super::__construct(style);
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",33)
	double width = ::cocktail::Lib_obj::get_window()->get_innerWidth();
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",34)
	double height = ::cocktail::Lib_obj::get_window()->get_innerHeight();
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",36)
	this->_bounds->__FieldRef(HX_CSTRING("width")) = width;
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",37)
	this->_bounds->__FieldRef(HX_CSTRING("height")) = height;
}
;
	return null();
}

InitialBlockRenderer_obj::~InitialBlockRenderer_obj() { }

Dynamic InitialBlockRenderer_obj::__CreateEmpty() { return  new InitialBlockRenderer_obj; }
hx::ObjectPtr< InitialBlockRenderer_obj > InitialBlockRenderer_obj::__new(::port::flash_player::Style style)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic InitialBlockRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool InitialBlockRenderer_obj::isInitialContainer( ){
	HX_SOURCE_PUSH("InitialBlockRenderer_obj::isInitialContainer")
	HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",41)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(InitialBlockRenderer_obj,isInitialContainer,return )

Void InitialBlockRenderer_obj::init( ){
{
		HX_SOURCE_PUSH("InitialBlockRenderer_obj::init")
		HX_SOURCE_POS("../../src/core/renderer/InitialBlockRenderer.hx",46)
		this->_backgroundManager = ::core::background::InitialBlockBackgroundManager_obj::__new();
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.renderer.InitialBlockRenderer"), hx::TCanCast< InitialBlockRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InitialBlockRenderer_obj::__boot()
{
}

} // end namespace core
} // end namespace renderer
