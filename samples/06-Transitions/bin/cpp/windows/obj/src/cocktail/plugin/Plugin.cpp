#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_plugin_Plugin
#include <cocktail/plugin/Plugin.h>
#endif
namespace cocktail{
namespace plugin{

Void Plugin_obj::__construct(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError)
{
HX_STACK_PUSH("Plugin::new","cocktail/plugin/Plugin.hx",68);
{
	HX_STACK_LINE(69)
	this->viewport = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(70)
	this->_loadComplete = loadComplete;
	HX_STACK_LINE(71)
	this->_loadError = loadError;
	HX_STACK_LINE(72)
	this->_elementAttributes = elementAttributes;
	HX_STACK_LINE(73)
	this->_params = params;
}
;
	return null();
}

Plugin_obj::~Plugin_obj() { }

Dynamic Plugin_obj::__CreateEmpty() { return  new Plugin_obj; }
hx::ObjectPtr< Plugin_obj > Plugin_obj::__new(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError)
{  hx::ObjectPtr< Plugin_obj > result = new Plugin_obj();
	result->__construct(elementAttributes,params,loadComplete,loadError);
	return result;}

Dynamic Plugin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Plugin_obj > result = new Plugin_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Plugin_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("Plugin::detach","cocktail/plugin/Plugin.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Plugin_obj,detach,(void))

Void Plugin_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("Plugin::attach","cocktail/plugin/Plugin.hx",122);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Plugin_obj,attach,(void))

bool Plugin_obj::isCompositedPlugin( ){
	HX_STACK_PUSH("Plugin::isCompositedPlugin","cocktail/plugin/Plugin.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_LINE(107)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Plugin_obj,isCompositedPlugin,return )

Void Plugin_obj::dispose( ){
{
		HX_STACK_PUSH("Plugin::dispose","cocktail/plugin/Plugin.hx",94);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Plugin_obj,dispose,(void))

Void Plugin_obj::updateViewport( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("Plugin::updateViewport","cocktail/plugin/Plugin.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Plugin_obj,updateViewport,(void))


Plugin_obj::Plugin_obj()
{
}

void Plugin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Plugin);
	HX_MARK_MEMBER_NAME(_params,"_params");
	HX_MARK_MEMBER_NAME(_elementAttributes,"_elementAttributes");
	HX_MARK_MEMBER_NAME(_loadError,"_loadError");
	HX_MARK_MEMBER_NAME(_loadComplete,"_loadComplete");
	HX_MARK_MEMBER_NAME(viewport,"viewport");
	HX_MARK_END_CLASS();
}

void Plugin_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_params,"_params");
	HX_VISIT_MEMBER_NAME(_elementAttributes,"_elementAttributes");
	HX_VISIT_MEMBER_NAME(_loadError,"_loadError");
	HX_VISIT_MEMBER_NAME(_loadComplete,"_loadComplete");
	HX_VISIT_MEMBER_NAME(viewport,"viewport");
}

Dynamic Plugin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_params") ) { return _params; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"viewport") ) { return viewport; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_loadError") ) { return _loadError; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_loadComplete") ) { return _loadComplete; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateViewport") ) { return updateViewport_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isCompositedPlugin") ) { return isCompositedPlugin_dyn(); }
		if (HX_FIELD_EQ(inName,"_elementAttributes") ) { return _elementAttributes; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Plugin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_params") ) { _params=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"viewport") ) { viewport=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_loadError") ) { _loadError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_loadComplete") ) { _loadComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_elementAttributes") ) { _elementAttributes=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Plugin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_params"));
	outFields->push(HX_CSTRING("_elementAttributes"));
	outFields->push(HX_CSTRING("viewport"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("isCompositedPlugin"),
	HX_CSTRING("dispose"),
	HX_CSTRING("updateViewport"),
	HX_CSTRING("_params"),
	HX_CSTRING("_elementAttributes"),
	HX_CSTRING("_loadError"),
	HX_CSTRING("_loadComplete"),
	HX_CSTRING("viewport"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Plugin_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Plugin_obj::__mClass,"__mClass");
};

Class Plugin_obj::__mClass;

void Plugin_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.plugin.Plugin"), hx::TCanCast< Plugin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Plugin_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace plugin
