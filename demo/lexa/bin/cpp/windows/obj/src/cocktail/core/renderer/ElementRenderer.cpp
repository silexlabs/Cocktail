#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void ElementRenderer_obj::__construct(::cocktail::core::style::CoreStyle style)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",69)
	super::__construct();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",70)
	this->_coreStyle = style;
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , 0.0,false);
			__result->Add(HX_CSTRING("y") , 0.0,false);
			__result->Add(HX_CSTRING("width") , 0.0,false);
			__result->Add(HX_CSTRING("height") , 0.0,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",71)
	this->_bounds = _Function_1_1::Block();
}
;
	return null();
}

ElementRenderer_obj::~ElementRenderer_obj() { }

Dynamic ElementRenderer_obj::__CreateEmpty() { return  new ElementRenderer_obj; }
hx::ObjectPtr< ElementRenderer_obj > ElementRenderer_obj::__new(::cocktail::core::style::CoreStyle style)
{  hx::ObjectPtr< ElementRenderer_obj > result = new ElementRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic ElementRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ElementRenderer_obj > result = new ElementRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic ElementRenderer_obj::render( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",88)
	return Dynamic( Array_obj<Dynamic>::__new());
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,render,return )

Dynamic ElementRenderer_obj::renderBackground( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::renderBackground")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",97)
	return Dynamic( Array_obj<Dynamic>::__new());
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,renderBackground,return )

Void ElementRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("ElementRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",104)
		this->_bounds = null();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",105)
		this->_coreStyle = null();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",108)
		this->_layerRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,dispose,(void))

bool ElementRenderer_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",116)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,establishesNewFormattingContext,return )

bool ElementRenderer_obj::canHaveChildren( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::canHaveChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",121)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,canHaveChildren,return )

bool ElementRenderer_obj::isFloat( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isFloat")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",126)
	return this->_coreStyle->isFloat();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isFloat,return )

bool ElementRenderer_obj::isPositioned( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isPositioned")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",131)
	return this->_coreStyle->isPositioned();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isPositioned,return )

bool ElementRenderer_obj::isEmbedded( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isEmbedded")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",136)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isEmbedded,return )

bool ElementRenderer_obj::isText( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isText")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",141)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isText,return )

bool ElementRenderer_obj::isSpace( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isSpace")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",146)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isSpace,return )

bool ElementRenderer_obj::isLineFeed( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isLineFeed")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",151)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isLineFeed,return )

bool ElementRenderer_obj::isTab( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isTab")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",156)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isTab,return )

bool ElementRenderer_obj::isInitialContainer( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isInitialContainer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",161)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isInitialContainer,return )

bool ElementRenderer_obj::isDisplayed( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::isDisplayed")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",166)
	return this->_coreStyle->isDisplayed();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isDisplayed,return )

::cocktail::core::renderer::LayerRenderer ElementRenderer_obj::setLayerRenderer( ::cocktail::core::renderer::LayerRenderer value){
	HX_SOURCE_PUSH("ElementRenderer_obj::setLayerRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",175)
	return this->_layerRenderer = value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,setLayerRenderer,return )

::cocktail::core::renderer::LayerRenderer ElementRenderer_obj::getLayerRenderer( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::getLayerRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",180)
	return this->_layerRenderer;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getLayerRenderer,return )

::cocktail::core::style::CoreStyle ElementRenderer_obj::getCoreStyle( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::getCoreStyle")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",185)
	return this->_coreStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getCoreStyle,return )

Dynamic ElementRenderer_obj::getBounds( ){
	HX_SOURCE_PUSH("ElementRenderer_obj::getBounds")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",190)
	return this->_bounds;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getBounds,return )

Dynamic ElementRenderer_obj::setBounds( Dynamic value){
	HX_SOURCE_PUSH("ElementRenderer_obj::setBounds")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/ElementRenderer.hx",195)
	return this->_bounds = value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,setBounds,return )


ElementRenderer_obj::ElementRenderer_obj()
{
}

void ElementRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ElementRenderer);
	HX_MARK_MEMBER_NAME(_bounds,"_bounds");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(_coreStyle,"_coreStyle");
	HX_MARK_MEMBER_NAME(coreStyle,"coreStyle");
	HX_MARK_MEMBER_NAME(_layerRenderer,"_layerRenderer");
	HX_MARK_MEMBER_NAME(layerRenderer,"layerRenderer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ElementRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"isTab") ) { return isTab_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return getBounds(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"isText") ) { return isText_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bounds") ) { return _bounds; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"coreStyle") ) { return getCoreStyle(); }
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"setBounds") ) { return setBounds_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { return _coreStyle; }
		if (HX_FIELD_EQ(inName,"isEmbedded") ) { return isEmbedded_dyn(); }
		if (HX_FIELD_EQ(inName,"isLineFeed") ) { return isLineFeed_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isDisplayed") ) { return isDisplayed_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"getCoreStyle") ) { return getCoreStyle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { return getLayerRenderer(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_layerRenderer") ) { return _layerRenderer; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"canHaveChildren") ) { return canHaveChildren_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"renderBackground") ) { return renderBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"setLayerRenderer") ) { return setLayerRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"getLayerRenderer") ) { return getLayerRenderer_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isInitialContainer") ) { return isInitialContainer_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"establishesNewFormattingContext") ) { return establishesNewFormattingContext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ElementRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return setBounds(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bounds") ) { _bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"coreStyle") ) { coreStyle=inValue.Cast< ::cocktail::core::style::CoreStyle >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { _coreStyle=inValue.Cast< ::cocktail::core::style::CoreStyle >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { return setLayerRenderer(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_layerRenderer") ) { _layerRenderer=inValue.Cast< ::cocktail::core::renderer::LayerRenderer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ElementRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bounds"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("_coreStyle"));
	outFields->push(HX_CSTRING("coreStyle"));
	outFields->push(HX_CSTRING("_layerRenderer"));
	outFields->push(HX_CSTRING("layerRenderer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_bounds"),
	HX_CSTRING("bounds"),
	HX_CSTRING("_coreStyle"),
	HX_CSTRING("coreStyle"),
	HX_CSTRING("_layerRenderer"),
	HX_CSTRING("layerRenderer"),
	HX_CSTRING("render"),
	HX_CSTRING("renderBackground"),
	HX_CSTRING("dispose"),
	HX_CSTRING("establishesNewFormattingContext"),
	HX_CSTRING("canHaveChildren"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isEmbedded"),
	HX_CSTRING("isText"),
	HX_CSTRING("isSpace"),
	HX_CSTRING("isLineFeed"),
	HX_CSTRING("isTab"),
	HX_CSTRING("isInitialContainer"),
	HX_CSTRING("isDisplayed"),
	HX_CSTRING("setLayerRenderer"),
	HX_CSTRING("getLayerRenderer"),
	HX_CSTRING("getCoreStyle"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("setBounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ElementRenderer_obj::__mClass;

void ElementRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.ElementRenderer"), hx::TCanCast< ElementRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ElementRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
