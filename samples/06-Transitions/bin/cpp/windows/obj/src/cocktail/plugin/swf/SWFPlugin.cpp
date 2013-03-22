#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_GeomUtils
#include <cocktail/core/geom/GeomUtils.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
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
#ifndef INCLUDED_cocktail_plugin_swf_SWFPlugin
#include <cocktail/plugin/swf/SWFPlugin.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#include <cocktail/port/base/NativeHttpBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeHttp
#include <cocktail/port/platform/nme/NativeHttp.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Loader
#include <neash/display/Loader.h>
#endif
#ifndef INCLUDED_neash_display_LoaderInfo
#include <neash/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
#ifndef INCLUDED_neash_net_URLLoader
#include <neash/net/URLLoader.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace cocktail{
namespace plugin{
namespace swf{

Void SWFPlugin_obj::__construct(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError)
{
HX_STACK_PUSH("SWFPlugin::new","cocktail/plugin/swf/SWFPlugin.hx",141);
{
	HX_STACK_LINE(142)
	super::__construct(elementAttributes,params,loadComplete,loadError);
	HX_STACK_LINE(143)
	this->_swfBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(144)
	this->_swfAddedToStage = false;
	HX_STACK_LINE(145)
	this->_isAVM1swf = false;
	HX_STACK_LINE(146)
	this->init();
}
;
	return null();
}

SWFPlugin_obj::~SWFPlugin_obj() { }

Dynamic SWFPlugin_obj::__CreateEmpty() { return  new SWFPlugin_obj; }
hx::ObjectPtr< SWFPlugin_obj > SWFPlugin_obj::__new(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError)
{  hx::ObjectPtr< SWFPlugin_obj > result = new SWFPlugin_obj();
	result->__construct(elementAttributes,params,loadComplete,loadError);
	return result;}

Dynamic SWFPlugin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SWFPlugin_obj > result = new SWFPlugin_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void SWFPlugin_obj::onLoaderReady( ::neash::display::Loader loader){
{
		HX_STACK_PUSH("SWFPlugin::onLoaderReady","cocktail/plugin/swf/SWFPlugin.hx",448);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(452)
		this->_isAVM1swf = false;
		HX_STACK_LINE(457)
		this->_swfHeight = loader->contentLoaderInfo->height;
		HX_STACK_LINE(458)
		this->_swfWidth = loader->contentLoaderInfo->width;
		HX_STACK_LINE(459)
		this->_swf = loader->content;
		HX_STACK_LINE(463)
		this->_swf->nmeSetMask(this->_mask);
		HX_STACK_LINE(466)
		this->_loadComplete();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SWFPlugin_obj,onLoaderReady,(void))

Void SWFPlugin_obj::onSWFLoadComplete( ::neash::events::Event event){
{
		HX_STACK_PUSH("SWFPlugin::onSWFLoadComplete","cocktail/plugin/swf/SWFPlugin.hx",439);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(439)
		this->onLoaderReady(this->_loader);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SWFPlugin_obj,onSWFLoadComplete,(void))

Void SWFPlugin_obj::updateViewport( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("SWFPlugin::updateViewport","cocktail/plugin/swf/SWFPlugin.hx",383);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(385)
		if (((bool((bool((bool((x == this->viewport->x)) && bool((y == this->viewport->y)))) && bool((width == this->viewport->width)))) && bool((height == this->viewport->height))))){
			HX_STACK_LINE(387)
			return null();
		}
		HX_STACK_LINE(391)
		this->viewport->x = x;
		HX_STACK_LINE(392)
		this->viewport->y = y;
		HX_STACK_LINE(393)
		this->viewport->width = width;
		HX_STACK_LINE(394)
		this->viewport->height = height;
		HX_STACK_LINE(397)
		this->_swf->nmeGetTransform()->nmeGetMatrix()->identity();
		HX_STACK_LINE(400)
		::cocktail::core::geom::GeomUtils_obj::getCenteredBounds(this->viewport->width,this->viewport->height,this->_swfWidth,this->_swfHeight,this->_swfBounds);
		HX_STACK_LINE(404)
		::String _switch_1 = (this->_scaleMode);
		if (  ( _switch_1==HX_CSTRING("noscale"))){
			HX_STACK_LINE(407)
			this->_swf->nmeSetX(::Math_obj::round(this->viewport->x));
			HX_STACK_LINE(408)
			this->_swf->nmeSetY(::Math_obj::round(this->viewport->y));
		}
		else if (  ( _switch_1==HX_CSTRING("exactfit"))){
			HX_STACK_LINE(411)
			this->_swf->nmeSetX(::Math_obj::round(this->viewport->x));
			HX_STACK_LINE(412)
			this->_swf->nmeSetY(::Math_obj::round(this->viewport->y));
			HX_STACK_LINE(413)
			this->_swf->nmeSetScaleX((Float(this->viewport->width) / Float(this->_swfWidth)));
			HX_STACK_LINE(414)
			this->_swf->nmeSetScaleY((Float(this->viewport->height) / Float(this->_swfHeight)));
		}
		else  {
			HX_STACK_LINE(417)
			this->_swf->nmeSetX(::Math_obj::round((this->viewport->x + this->_swfBounds->x)));
			HX_STACK_LINE(418)
			this->_swf->nmeSetY(::Math_obj::round((this->viewport->y + this->_swfBounds->y)));
			HX_STACK_LINE(419)
			this->_swf->nmeSetScaleX((Float(this->_swfBounds->width) / Float(this->_swfWidth)));
			HX_STACK_LINE(420)
			this->_swf->nmeSetScaleY((Float(this->_swfBounds->height) / Float(this->_swfHeight)));
		}
;
;
		HX_STACK_LINE(424)
		this->_mask->nmeGetGraphics()->clear();
		HX_STACK_LINE(425)
		this->_mask->nmeGetGraphics()->beginFill((int)16711680,0.5);
		HX_STACK_LINE(426)
		this->_mask->nmeGetGraphics()->drawRect(this->viewport->x,this->viewport->y,this->viewport->width,this->viewport->height);
		HX_STACK_LINE(427)
		this->_mask->nmeGetGraphics()->endFill();
	}
return null();
}


bool SWFPlugin_obj::isCompositedPlugin( ){
	HX_STACK_PUSH("SWFPlugin::isCompositedPlugin","cocktail/plugin/swf/SWFPlugin.hx",374);
	HX_STACK_THIS(this);
	HX_STACK_LINE(374)
	return true;
}


Void SWFPlugin_obj::dispose( ){
{
		HX_STACK_PUSH("SWFPlugin::dispose","cocktail/plugin/swf/SWFPlugin.hx",351);
		HX_STACK_THIS(this);
		HX_STACK_LINE(357)
		this->_loader = null();
		HX_STACK_LINE(358)
		this->_swf = null();
		HX_STACK_LINE(363)
		::cocktail::port::platform::nme::NativeHttp loadedSWF = ::cocktail::core::resource::ResourceManager_obj::getBinaryResource(this->_elementAttributes->get(HX_CSTRING("data")));		HX_STACK_VAR(loadedSWF,"loadedSWF");
		HX_STACK_LINE(364)
		if (((::Std_obj::is(loadedSWF->response,hx::ClassOf< ::neash::display::Loader >()) == true))){
			HX_STACK_LINE(365)
			::cocktail::core::resource::ResourceManager_obj::removeBinaryResource(this->_elementAttributes->get(HX_CSTRING("data")));
		}
	}
return null();
}


Void SWFPlugin_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("SWFPlugin::detach","cocktail/plugin/swf/SWFPlugin.hx",330);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_LINE(330)
		if (((this->_swfAddedToStage == true))){
			HX_STACK_LINE(334)
			if (((this->_isAVM1swf == false))){
				HX_STACK_LINE(335)
				this->_swf->nmeGetParent()->removeChild(this->_swf);
			}
			else{
				HX_STACK_LINE(340)
				this->_loader->nmeGetParent()->removeChild(this->_loader);
			}
			HX_STACK_LINE(343)
			this->_swfAddedToStage = false;
		}
	}
return null();
}


Void SWFPlugin_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicsContext){
{
		HX_STACK_PUSH("SWFPlugin::attach","cocktail/plugin/swf/SWFPlugin.hx",282);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_LINE(282)
		if (((this->_swfAddedToStage == false))){
			HX_STACK_LINE(287)
			::neash::display::DisplayObjectContainer containerGraphicContext = graphicsContext->get_nativeLayer();		HX_STACK_VAR(containerGraphicContext,"containerGraphicContext");
			HX_STACK_LINE(293)
			if (((bool((::cocktail::core::config::Config_obj::getInstance()->enableCompositing == false)) && bool((::cocktail::core::config::Config_obj::getInstance()->objectBelowWhenNoCompositing == true))))){
				HX_STACK_LINE(294)
				if (((this->_isAVM1swf == false))){
					HX_STACK_LINE(298)
					containerGraphicContext->nmeGetParent()->addChildAt(this->_swf,(int)0);
				}
				else{
					HX_STACK_LINE(303)
					containerGraphicContext->nmeGetParent()->addChildAt(this->_loader,(int)0);
				}
			}
			else{
				HX_STACK_LINE(308)
				if (((this->_isAVM1swf == false))){
					HX_STACK_LINE(310)
					containerGraphicContext->addChild(this->_swf);
				}
				else{
					HX_STACK_LINE(316)
					containerGraphicContext->addChild(this->_loader);
				}
			}
			HX_STACK_LINE(321)
			this->_swfAddedToStage = true;
		}
	}
return null();
}


Void SWFPlugin_obj::parseQueryString( Dynamic data,::String queryString){
{
		HX_STACK_PUSH("SWFPlugin::parseQueryString","cocktail/plugin/swf/SWFPlugin.hx",264);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(queryString,"queryString");
		HX_STACK_LINE(265)
		Array< ::String > params = queryString.split(HX_CSTRING("&"));		HX_STACK_VAR(params,"params");
		HX_STACK_LINE(267)
		{
			HX_STACK_LINE(267)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = params->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(267)
			while(((_g1 < _g))){
				HX_STACK_LINE(267)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(269)
				Array< ::String > param = params->__get(i).split(HX_CSTRING("="));		HX_STACK_VAR(param,"param");
				HX_STACK_LINE(270)
				if (((data != null()))){
					HX_STACK_LINE(270)
					data->__SetField(param->__get((int)0),param->__get((int)1),false);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SWFPlugin_obj,parseQueryString,(void))

Dynamic SWFPlugin_obj::getLoaderContextParams( ){
	HX_STACK_PUSH("SWFPlugin::getLoaderContextParams","cocktail/plugin/swf/SWFPlugin.hx",234);
	HX_STACK_THIS(this);
	HX_STACK_LINE(235)
	Dynamic data = null();		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(238)
	::String swfUrl = this->_elementAttributes->get(HX_CSTRING("data"));		HX_STACK_VAR(swfUrl,"swfUrl");
	HX_STACK_LINE(239)
	if (((swfUrl.indexOf(HX_CSTRING("?"),null()) != (int)-1))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","cocktail/plugin/swf/SWFPlugin.hx",241);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(241)
		data = _Function_2_1::Block();
		HX_STACK_LINE(242)
		this->parseQueryString(data,swfUrl.substr((swfUrl.indexOf(HX_CSTRING("?"),null()) + (int)1),null()));
	}
	HX_STACK_LINE(246)
	if ((this->_params->exists(HX_CSTRING("flashvars")))){
		HX_STACK_LINE(248)
		if (((data == null()))){
			struct _Function_3_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","cocktail/plugin/swf/SWFPlugin.hx",250);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(249)
			data = _Function_3_1::Block();
		}
		HX_STACK_LINE(253)
		this->parseQueryString(data,this->_params->get(HX_CSTRING("flashvars")));
	}
	HX_STACK_LINE(256)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(SWFPlugin_obj,getLoaderContextParams,return )

Void SWFPlugin_obj::init( ){
{
		HX_STACK_PUSH("SWFPlugin::init","cocktail/plugin/swf/SWFPlugin.hx",153);
		HX_STACK_THIS(this);
		HX_STACK_LINE(152)
		Array< ::cocktail::plugin::swf::SWFPlugin > _g = Array_obj< ::cocktail::plugin::swf::SWFPlugin >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(155)
		if ((this->_params->exists(HX_CSTRING("scale")))){
			HX_STACK_LINE(156)
			this->_scaleMode = this->_params->get(HX_CSTRING("scale"));
		}
		else{
			HX_STACK_LINE(160)
			this->_scaleMode = HX_CSTRING("showall");
		}
		HX_STACK_LINE(165)
		this->_mask = ::neash::display::Sprite_obj::__new();
		HX_STACK_LINE(169)
		::cocktail::port::platform::nme::NativeHttp loadedSWF = ::cocktail::core::resource::ResourceManager_obj::getBinaryResource(this->_elementAttributes->get(HX_CSTRING("data")));		HX_STACK_VAR(loadedSWF,"loadedSWF");
		HX_STACK_LINE(174)
		if ((::Std_obj::is(loadedSWF->response,hx::ClassOf< ::neash::display::Loader >()))){
			HX_STACK_LINE(176)
			this->_loader = loadedSWF->response;

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::cocktail::plugin::swf::SWFPlugin >,_g)
			Void run(Float e){
				HX_STACK_PUSH("*::_Function_2_1","cocktail/plugin/swf/SWFPlugin.hx",181);
				HX_STACK_ARG(e,"e");
				{
					HX_STACK_LINE(181)
					_g->__get((int)0)->onLoaderReady(_g->__get((int)0)->_loader);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(181)
			::cocktail::Lib_obj::get_document()->timer->delay( Dynamic(new _Function_2_1(_g)),null());
			HX_STACK_LINE(182)
			return null();
		}
		HX_STACK_LINE(187)
		this->_loader = ::neash::display::Loader_obj::__new();
		HX_STACK_LINE(189)
		this->_loader->contentLoaderInfo->addEventListener(::neash::events::Event_obj::INIT,this->onSWFLoadComplete_dyn(),null(),null(),null());
		HX_STACK_LINE(193)
		this->_loader->loadBytes(loadedSWF->response);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SWFPlugin_obj,init,(void))

::String SWFPlugin_obj::NO_SCALE;

::String SWFPlugin_obj::SHOW_ALL;

::String SWFPlugin_obj::EXACT_FIT;

::String SWFPlugin_obj::SCALE_MODE;

::String SWFPlugin_obj::DATA_ATTRIBUTE;

::String SWFPlugin_obj::FLASHVARS_ATTRIBUTE;

::String SWFPlugin_obj::WMODE_ATTRIBUTE;

::String SWFPlugin_obj::WMODE_TRANSPARENT;


SWFPlugin_obj::SWFPlugin_obj()
{
}

void SWFPlugin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SWFPlugin);
	HX_MARK_MEMBER_NAME(_isAVM1swf,"_isAVM1swf");
	HX_MARK_MEMBER_NAME(_swfAddedToStage,"_swfAddedToStage");
	HX_MARK_MEMBER_NAME(_mask,"_mask");
	HX_MARK_MEMBER_NAME(_loader,"_loader");
	HX_MARK_MEMBER_NAME(_swfWidth,"_swfWidth");
	HX_MARK_MEMBER_NAME(_swfHeight,"_swfHeight");
	HX_MARK_MEMBER_NAME(_swfBounds,"_swfBounds");
	HX_MARK_MEMBER_NAME(_swf,"_swf");
	HX_MARK_MEMBER_NAME(_scaleMode,"_scaleMode");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SWFPlugin_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isAVM1swf,"_isAVM1swf");
	HX_VISIT_MEMBER_NAME(_swfAddedToStage,"_swfAddedToStage");
	HX_VISIT_MEMBER_NAME(_mask,"_mask");
	HX_VISIT_MEMBER_NAME(_loader,"_loader");
	HX_VISIT_MEMBER_NAME(_swfWidth,"_swfWidth");
	HX_VISIT_MEMBER_NAME(_swfHeight,"_swfHeight");
	HX_VISIT_MEMBER_NAME(_swfBounds,"_swfBounds");
	HX_VISIT_MEMBER_NAME(_swf,"_swf");
	HX_VISIT_MEMBER_NAME(_scaleMode,"_scaleMode");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SWFPlugin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"_swf") ) { return _swf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mask") ) { return _mask; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_loader") ) { return _loader; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"NO_SCALE") ) { return NO_SCALE; }
		if (HX_FIELD_EQ(inName,"SHOW_ALL") ) { return SHOW_ALL; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"EXACT_FIT") ) { return EXACT_FIT; }
		if (HX_FIELD_EQ(inName,"_swfWidth") ) { return _swfWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"SCALE_MODE") ) { return SCALE_MODE; }
		if (HX_FIELD_EQ(inName,"_isAVM1swf") ) { return _isAVM1swf; }
		if (HX_FIELD_EQ(inName,"_swfHeight") ) { return _swfHeight; }
		if (HX_FIELD_EQ(inName,"_swfBounds") ) { return _swfBounds; }
		if (HX_FIELD_EQ(inName,"_scaleMode") ) { return _scaleMode; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onLoaderReady") ) { return onLoaderReady_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"DATA_ATTRIBUTE") ) { return DATA_ATTRIBUTE; }
		if (HX_FIELD_EQ(inName,"updateViewport") ) { return updateViewport_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"WMODE_ATTRIBUTE") ) { return WMODE_ATTRIBUTE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parseQueryString") ) { return parseQueryString_dyn(); }
		if (HX_FIELD_EQ(inName,"_swfAddedToStage") ) { return _swfAddedToStage; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"WMODE_TRANSPARENT") ) { return WMODE_TRANSPARENT; }
		if (HX_FIELD_EQ(inName,"onSWFLoadComplete") ) { return onSWFLoadComplete_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isCompositedPlugin") ) { return isCompositedPlugin_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"FLASHVARS_ATTRIBUTE") ) { return FLASHVARS_ATTRIBUTE; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getLoaderContextParams") ) { return getLoaderContextParams_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SWFPlugin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_swf") ) { _swf=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mask") ) { _mask=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_loader") ) { _loader=inValue.Cast< ::neash::display::Loader >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"NO_SCALE") ) { NO_SCALE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SHOW_ALL") ) { SHOW_ALL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"EXACT_FIT") ) { EXACT_FIT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_swfWidth") ) { _swfWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"SCALE_MODE") ) { SCALE_MODE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isAVM1swf") ) { _isAVM1swf=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_swfHeight") ) { _swfHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_swfBounds") ) { _swfBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scaleMode") ) { _scaleMode=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"DATA_ATTRIBUTE") ) { DATA_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"WMODE_ATTRIBUTE") ) { WMODE_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_swfAddedToStage") ) { _swfAddedToStage=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"WMODE_TRANSPARENT") ) { WMODE_TRANSPARENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"FLASHVARS_ATTRIBUTE") ) { FLASHVARS_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SWFPlugin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isAVM1swf"));
	outFields->push(HX_CSTRING("_swfAddedToStage"));
	outFields->push(HX_CSTRING("_mask"));
	outFields->push(HX_CSTRING("_loader"));
	outFields->push(HX_CSTRING("_swfWidth"));
	outFields->push(HX_CSTRING("_swfHeight"));
	outFields->push(HX_CSTRING("_swfBounds"));
	outFields->push(HX_CSTRING("_swf"));
	outFields->push(HX_CSTRING("_scaleMode"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NO_SCALE"),
	HX_CSTRING("SHOW_ALL"),
	HX_CSTRING("EXACT_FIT"),
	HX_CSTRING("SCALE_MODE"),
	HX_CSTRING("DATA_ATTRIBUTE"),
	HX_CSTRING("FLASHVARS_ATTRIBUTE"),
	HX_CSTRING("WMODE_ATTRIBUTE"),
	HX_CSTRING("WMODE_TRANSPARENT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onLoaderReady"),
	HX_CSTRING("onSWFLoadComplete"),
	HX_CSTRING("updateViewport"),
	HX_CSTRING("isCompositedPlugin"),
	HX_CSTRING("dispose"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("parseQueryString"),
	HX_CSTRING("getLoaderContextParams"),
	HX_CSTRING("init"),
	HX_CSTRING("_isAVM1swf"),
	HX_CSTRING("_swfAddedToStage"),
	HX_CSTRING("_mask"),
	HX_CSTRING("_loader"),
	HX_CSTRING("_swfWidth"),
	HX_CSTRING("_swfHeight"),
	HX_CSTRING("_swfBounds"),
	HX_CSTRING("_swf"),
	HX_CSTRING("_scaleMode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::NO_SCALE,"NO_SCALE");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::SHOW_ALL,"SHOW_ALL");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::EXACT_FIT,"EXACT_FIT");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::SCALE_MODE,"SCALE_MODE");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::DATA_ATTRIBUTE,"DATA_ATTRIBUTE");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::FLASHVARS_ATTRIBUTE,"FLASHVARS_ATTRIBUTE");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::WMODE_ATTRIBUTE,"WMODE_ATTRIBUTE");
	HX_MARK_MEMBER_NAME(SWFPlugin_obj::WMODE_TRANSPARENT,"WMODE_TRANSPARENT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::NO_SCALE,"NO_SCALE");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::SHOW_ALL,"SHOW_ALL");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::EXACT_FIT,"EXACT_FIT");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::SCALE_MODE,"SCALE_MODE");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::DATA_ATTRIBUTE,"DATA_ATTRIBUTE");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::FLASHVARS_ATTRIBUTE,"FLASHVARS_ATTRIBUTE");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::WMODE_ATTRIBUTE,"WMODE_ATTRIBUTE");
	HX_VISIT_MEMBER_NAME(SWFPlugin_obj::WMODE_TRANSPARENT,"WMODE_TRANSPARENT");
};

Class SWFPlugin_obj::__mClass;

void SWFPlugin_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.plugin.swf.SWFPlugin"), hx::TCanCast< SWFPlugin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SWFPlugin_obj::__boot()
{
	NO_SCALE= HX_CSTRING("noscale");
	SHOW_ALL= HX_CSTRING("showall");
	EXACT_FIT= HX_CSTRING("exactfit");
	SCALE_MODE= HX_CSTRING("scale");
	DATA_ATTRIBUTE= HX_CSTRING("data");
	FLASHVARS_ATTRIBUTE= HX_CSTRING("flashvars");
	WMODE_ATTRIBUTE= HX_CSTRING("wmode");
	WMODE_TRANSPARENT= HX_CSTRING("transparent");
}

} // end namespace cocktail
} // end namespace plugin
} // end namespace swf
