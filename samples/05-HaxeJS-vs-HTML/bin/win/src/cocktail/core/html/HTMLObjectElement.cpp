#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_NamedNodeMap
#include <cocktail/core/dom/NamedNodeMap.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLObjectElement
#include <cocktail/core/html/HTMLObjectElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ObjectRenderer
#include <cocktail/core/renderer/ObjectRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
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
namespace cocktail{
namespace core{
namespace html{

Void HTMLObjectElement_obj::__construct()
{
HX_STACK_PUSH("HTMLObjectElement::new","cocktail/core/html/HTMLObjectElement.hx",94);
{
	HX_STACK_LINE(95)
	super::__construct(HX_CSTRING("OBJECT"));
	HX_STACK_LINE(97)
	this->_pluginReady = false;
	HX_STACK_LINE(98)
	this->intrinsicHeight = (int)150;
	HX_STACK_LINE(99)
	this->intrinsicWidth = (int)300;
	HX_STACK_LINE(100)
	this->intrinsicRatio = (Float(this->get_intrinsicWidth()) / Float(this->get_intrinsicHeight()));
}
;
	return null();
}

HTMLObjectElement_obj::~HTMLObjectElement_obj() { }

Dynamic HTMLObjectElement_obj::__CreateEmpty() { return  new HTMLObjectElement_obj; }
hx::ObjectPtr< HTMLObjectElement_obj > HTMLObjectElement_obj::__new()
{  hx::ObjectPtr< HTMLObjectElement_obj > result = new HTMLObjectElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLObjectElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLObjectElement_obj > result = new HTMLObjectElement_obj();
	result->__construct();
	return result;}

::String HTMLObjectElement_obj::get_type( ){
	HX_STACK_PUSH("HTMLObjectElement::get_type","cocktail/core/html/HTMLObjectElement.hx",382);
	HX_STACK_THIS(this);
	HX_STACK_LINE(382)
	return this->getAttribute(HX_CSTRING("type"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,get_type,return )

::String HTMLObjectElement_obj::set_type( ::String value){
	HX_STACK_PUSH("HTMLObjectElement::set_type","cocktail/core/html/HTMLObjectElement.hx",376);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(377)
	this->super::setAttribute(HX_CSTRING("type"),value);
	HX_STACK_LINE(378)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLObjectElement_obj,set_type,return )

::String HTMLObjectElement_obj::get_data( ){
	HX_STACK_PUSH("HTMLObjectElement::get_data","cocktail/core/html/HTMLObjectElement.hx",371);
	HX_STACK_THIS(this);
	HX_STACK_LINE(371)
	return this->getAttribute(HX_CSTRING("data"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,get_data,return )

::String HTMLObjectElement_obj::set_data( ::String value){
	HX_STACK_PUSH("HTMLObjectElement::set_data","cocktail/core/html/HTMLObjectElement.hx",359);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(360)
	this->super::setAttribute(HX_CSTRING("data"),value);
	HX_STACK_LINE(364)
	this->deletePlugin();
	HX_STACK_LINE(365)
	this->createPlugin();
	HX_STACK_LINE(367)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLObjectElement_obj,set_data,return )

Void HTMLObjectElement_obj::onLoadError( ){
{
		HX_STACK_PUSH("HTMLObjectElement::onLoadError","cocktail/core/html/HTMLObjectElement.hx",346);
		HX_STACK_THIS(this);
		HX_STACK_LINE(347)
		this->_pluginReady = false;
		HX_STACK_LINE(349)
		::cocktail::core::event::UIEvent errorEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
		HX_STACK_LINE(350)
		errorEvent->initUIEvent(HX_CSTRING("error"),false,false,null(),0.0);
		HX_STACK_LINE(351)
		this->dispatchEvent(errorEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,onLoadError,(void))

Void HTMLObjectElement_obj::onLoadComplete( ){
{
		HX_STACK_PUSH("HTMLObjectElement::onLoadComplete","cocktail/core/html/HTMLObjectElement.hx",328);
		HX_STACK_THIS(this);
		HX_STACK_LINE(329)
		this->_pluginReady = true;
		HX_STACK_LINE(333)
		this->invalidateElementRenderer();
		HX_STACK_LINE(335)
		::cocktail::core::event::UIEvent loadEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(loadEvent,"loadEvent");
		HX_STACK_LINE(336)
		loadEvent->initUIEvent(HX_CSTRING("load"),false,false,null(),0.0);
		HX_STACK_LINE(337)
		this->dispatchEvent(loadEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,onLoadComplete,(void))

Void HTMLObjectElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLObjectElement::createElementRenderer","cocktail/core/html/HTMLObjectElement.hx",313);
		HX_STACK_THIS(this);
		HX_STACK_LINE(313)
		if (((this->_pluginReady == true))){
			HX_STACK_LINE(315)
			this->elementRenderer = ::cocktail::core::renderer::ObjectRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


Void HTMLObjectElement_obj::onPluginResourceLoaded( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLObjectElement::onPluginResourceLoaded","cocktail/core/html/HTMLObjectElement.hx",295);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(296)
		e->target->removeEventListener(HX_CSTRING("load"),this->onPluginResourceLoaded_dyn(),null());
		HX_STACK_LINE(298)
		this->createPlugin();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLObjectElement_obj,onPluginResourceLoaded,(void))

Void HTMLObjectElement_obj::deletePlugin( ){
{
		HX_STACK_PUSH("HTMLObjectElement::deletePlugin","cocktail/core/html/HTMLObjectElement.hx",281);
		HX_STACK_THIS(this);
		HX_STACK_LINE(281)
		if (((this->plugin != null()))){
			HX_STACK_LINE(284)
			this->_pluginReady = false;
			HX_STACK_LINE(285)
			this->plugin->dispose();
			HX_STACK_LINE(286)
			this->plugin = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,deletePlugin,(void))

Void HTMLObjectElement_obj::createPlugin( ){
{
		HX_STACK_PUSH("HTMLObjectElement::createPlugin","cocktail/core/html/HTMLObjectElement.hx",200);
		HX_STACK_THIS(this);
		HX_STACK_LINE(202)
		if (((this->plugin != null()))){
			HX_STACK_LINE(203)
			return null();
		}
		HX_STACK_LINE(210)
		if (((this->attachedToDOM == false))){
			HX_STACK_LINE(211)
			return null();
		}
		HX_STACK_LINE(216)
		if (((this->get_data() != null()))){
			HX_STACK_LINE(217)
			if (((bool((this->get_data().indexOf(HX_CSTRING(".swf"),null()) != (int)-1)) || bool((this->getAttribute(HX_CSTRING("type")) == HX_CSTRING("application/x-shockwave-flash")))))){
				HX_STACK_LINE(224)
				::cocktail::port::platform::nme::NativeHttp resource = ::cocktail::core::resource::ResourceManager_obj::getBinaryResource(this->get_data());		HX_STACK_VAR(resource,"resource");
				HX_STACK_LINE(227)
				if (((resource->error == true))){
					HX_STACK_LINE(228)
					return null();
				}
				HX_STACK_LINE(233)
				if (((resource->complete == false))){
					HX_STACK_LINE(235)
					resource->addEventListener(HX_CSTRING("load"),this->onPluginResourceLoaded_dyn(),null());
					HX_STACK_LINE(236)
					return null();
				}
				HX_STACK_LINE(239)
				::Hash params = ::Hash_obj::__new();		HX_STACK_VAR(params,"params");
				HX_STACK_LINE(242)
				int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(243)
				{
					HX_STACK_LINE(243)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(243)
					while(((_g < length))){
						HX_STACK_LINE(243)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(245)
						::cocktail::core::html::HTMLElement child = this->childNodes->__GetItem(i);		HX_STACK_VAR(child,"child");
						HX_STACK_LINE(246)
						if (((child->tagName == HX_CSTRING("PARAM")))){
							HX_STACK_LINE(248)
							::String name = child->getAttribute(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
							HX_STACK_LINE(249)
							::String value = child->getAttribute(HX_CSTRING("value"));		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(251)
							if (((bool((name != null())) && bool((value != null()))))){
								HX_STACK_LINE(252)
								params->set(name,value);
							}
						}
					}
				}
				HX_STACK_LINE(259)
				::Hash elementAttributes = ::Hash_obj::__new();		HX_STACK_VAR(elementAttributes,"elementAttributes");
				HX_STACK_LINE(260)
				{
					HX_STACK_LINE(260)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->attributes->get_length();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(260)
					while(((_g1 < _g))){
						HX_STACK_LINE(260)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(262)
						::cocktail::core::dom::Attr attr = this->attributes->item(i);		HX_STACK_VAR(attr,"attr");
						HX_STACK_LINE(263)
						elementAttributes->set(attr->name,attr->get_value());
					}
				}
				HX_STACK_LINE(267)
				this->plugin = ::cocktail::plugin::swf::SWFPlugin_obj::__new(elementAttributes,params,this->onLoadComplete_dyn(),this->onLoadError_dyn());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLObjectElement_obj,createPlugin,(void))

Void HTMLObjectElement_obj::removedFromDOM( ){
{
		HX_STACK_PUSH("HTMLObjectElement::removedFromDOM","cocktail/core/html/HTMLObjectElement.hx",186);
		HX_STACK_THIS(this);
		HX_STACK_LINE(187)
		this->super::removedFromDOM();
		HX_STACK_LINE(188)
		this->deletePlugin();
	}
return null();
}


Void HTMLObjectElement_obj::addedToDOM( ){
{
		HX_STACK_PUSH("HTMLObjectElement::addedToDOM","cocktail/core/html/HTMLObjectElement.hx",159);
		HX_STACK_THIS(this);
		HX_STACK_LINE(160)
		this->super::addedToDOM();
		HX_STACK_LINE(162)
		if (((this->get_data() != null()))){
			HX_STACK_LINE(163)
			if (((this->get_data().indexOf(HX_CSTRING(".swf"),null()) != (int)-1))){
				HX_STACK_LINE(166)
				::cocktail::core::resource::ResourceManager_obj::getBinaryResource(this->get_data());
			}
		}
	}
return null();
}


Void HTMLObjectElement_obj::attach( bool recursive){
{
		HX_STACK_PUSH("HTMLObjectElement::attach","cocktail/core/html/HTMLObjectElement.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
		HX_STACK_LINE(137)
		this->super::attach(recursive);
		HX_STACK_LINE(143)
		if (((this->isRendered() == true))){
			HX_STACK_LINE(144)
			this->createPlugin();
		}
	}
return null();
}


Void HTMLObjectElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLObjectElement::setAttribute","cocktail/core/html/HTMLObjectElement.hx",108);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(108)
		if (((name == HX_CSTRING("data")))){
			HX_STACK_LINE(110)
			this->set_data(value);
		}
		else{
			HX_STACK_LINE(113)
			if (((name == HX_CSTRING("type")))){
				HX_STACK_LINE(114)
				this->set_type(value);
			}
			else{
				HX_STACK_LINE(118)
				this->super::setAttribute(name,value);
			}
		}
	}
return null();
}


Float HTMLObjectElement_obj::HTML_OBJECT_INTRISIC_WIDTH;

Float HTMLObjectElement_obj::HTML_OBJECT_INTRINSIC_HEIGHT;

::String HTMLObjectElement_obj::SWF_FILE_EXTENSION;

::String HTMLObjectElement_obj::SWF_FILE_MIME_TYPE;


HTMLObjectElement_obj::HTMLObjectElement_obj()
{
}

void HTMLObjectElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLObjectElement);
	HX_MARK_MEMBER_NAME(_pluginReady,"_pluginReady");
	HX_MARK_MEMBER_NAME(plugin,"plugin");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLObjectElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_pluginReady,"_pluginReady");
	HX_VISIT_MEMBER_NAME(plugin,"plugin");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(data,"data");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLObjectElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		if (HX_FIELD_EQ(inName,"data") ) { return inCallProp ? get_data() : data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"plugin") ) { return plugin; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		if (HX_FIELD_EQ(inName,"get_data") ) { return get_data_dyn(); }
		if (HX_FIELD_EQ(inName,"set_data") ) { return set_data_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addedToDOM") ) { return addedToDOM_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onLoadError") ) { return onLoadError_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"deletePlugin") ) { return deletePlugin_dyn(); }
		if (HX_FIELD_EQ(inName,"createPlugin") ) { return createPlugin_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"_pluginReady") ) { return _pluginReady; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadComplete") ) { return onLoadComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"removedFromDOM") ) { return removedFromDOM_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SWF_FILE_EXTENSION") ) { return SWF_FILE_EXTENSION; }
		if (HX_FIELD_EQ(inName,"SWF_FILE_MIME_TYPE") ) { return SWF_FILE_MIME_TYPE; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"onPluginResourceLoaded") ) { return onPluginResourceLoaded_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"HTML_OBJECT_INTRISIC_WIDTH") ) { return HTML_OBJECT_INTRISIC_WIDTH; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"HTML_OBJECT_INTRINSIC_HEIGHT") ) { return HTML_OBJECT_INTRINSIC_HEIGHT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLObjectElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { if (inCallProp) return set_data(inValue);data=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"plugin") ) { plugin=inValue.Cast< ::cocktail::plugin::Plugin >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_pluginReady") ) { _pluginReady=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SWF_FILE_EXTENSION") ) { SWF_FILE_EXTENSION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SWF_FILE_MIME_TYPE") ) { SWF_FILE_MIME_TYPE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"HTML_OBJECT_INTRISIC_WIDTH") ) { HTML_OBJECT_INTRISIC_WIDTH=inValue.Cast< Float >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"HTML_OBJECT_INTRINSIC_HEIGHT") ) { HTML_OBJECT_INTRINSIC_HEIGHT=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLObjectElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_pluginReady"));
	outFields->push(HX_CSTRING("plugin"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_OBJECT_INTRISIC_WIDTH"),
	HX_CSTRING("HTML_OBJECT_INTRINSIC_HEIGHT"),
	HX_CSTRING("SWF_FILE_EXTENSION"),
	HX_CSTRING("SWF_FILE_MIME_TYPE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_type"),
	HX_CSTRING("set_type"),
	HX_CSTRING("get_data"),
	HX_CSTRING("set_data"),
	HX_CSTRING("onLoadError"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("onPluginResourceLoaded"),
	HX_CSTRING("deletePlugin"),
	HX_CSTRING("createPlugin"),
	HX_CSTRING("removedFromDOM"),
	HX_CSTRING("addedToDOM"),
	HX_CSTRING("attach"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("_pluginReady"),
	HX_CSTRING("plugin"),
	HX_CSTRING("type"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLObjectElement_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTMLObjectElement_obj::HTML_OBJECT_INTRISIC_WIDTH,"HTML_OBJECT_INTRISIC_WIDTH");
	HX_MARK_MEMBER_NAME(HTMLObjectElement_obj::HTML_OBJECT_INTRINSIC_HEIGHT,"HTML_OBJECT_INTRINSIC_HEIGHT");
	HX_MARK_MEMBER_NAME(HTMLObjectElement_obj::SWF_FILE_EXTENSION,"SWF_FILE_EXTENSION");
	HX_MARK_MEMBER_NAME(HTMLObjectElement_obj::SWF_FILE_MIME_TYPE,"SWF_FILE_MIME_TYPE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLObjectElement_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTMLObjectElement_obj::HTML_OBJECT_INTRISIC_WIDTH,"HTML_OBJECT_INTRISIC_WIDTH");
	HX_VISIT_MEMBER_NAME(HTMLObjectElement_obj::HTML_OBJECT_INTRINSIC_HEIGHT,"HTML_OBJECT_INTRINSIC_HEIGHT");
	HX_VISIT_MEMBER_NAME(HTMLObjectElement_obj::SWF_FILE_EXTENSION,"SWF_FILE_EXTENSION");
	HX_VISIT_MEMBER_NAME(HTMLObjectElement_obj::SWF_FILE_MIME_TYPE,"SWF_FILE_MIME_TYPE");
};

Class HTMLObjectElement_obj::__mClass;

void HTMLObjectElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLObjectElement"), hx::TCanCast< HTMLObjectElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLObjectElement_obj::__boot()
{
	HTML_OBJECT_INTRISIC_WIDTH= (int)300;
	HTML_OBJECT_INTRINSIC_HEIGHT= (int)150;
	SWF_FILE_EXTENSION= HX_CSTRING(".swf");
	SWF_FILE_MIME_TYPE= HX_CSTRING("application/x-shockwave-flash");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
