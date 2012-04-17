#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_hxtml_StyleProxy
#include <cocktail/core/hxtml/StyleProxy.h>
#endif
#ifndef INCLUDED_cocktail_core_style_adapter_Style
#include <cocktail/core/style/adapter/Style.h>
#endif
#ifndef INCLUDED_hxtml_IStyleProxy
#include <hxtml/IStyleProxy.h>
#endif
namespace cocktail{
namespace core{
namespace hxtml{

Void StyleProxy_obj::__construct()
{
{
}
;
	return null();
}

StyleProxy_obj::~StyleProxy_obj() { }

Dynamic StyleProxy_obj::__CreateEmpty() { return  new StyleProxy_obj; }
hx::ObjectPtr< StyleProxy_obj > StyleProxy_obj::__new()
{  hx::ObjectPtr< StyleProxy_obj > result = new StyleProxy_obj();
	result->__construct();
	return result;}

Dynamic StyleProxy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StyleProxy_obj > result = new StyleProxy_obj();
	result->__construct();
	return result;}

hx::Object *StyleProxy_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxtml::IStyleProxy_obj)) return operator ::hxtml::IStyleProxy_obj *();
	return super::__ToInterface(inType);
}

Void StyleProxy_obj::setDisplay( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setDisplay")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",62)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",62)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_display(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setDisplay,(void))

Void StyleProxy_obj::setPosition( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setPosition")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",65)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",65)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_position(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setPosition,(void))

Void StyleProxy_obj::setMarginLeftNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginLeftNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",87)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",87)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginLeft((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setMarginLeftNum,(void))

Void StyleProxy_obj::setMarginLeftKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginLeftKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",92)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",92)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginLeft(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setMarginLeftKey,(void))

Void StyleProxy_obj::setMarginTopNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginTopNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",97)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",97)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginTop((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setMarginTopNum,(void))

Void StyleProxy_obj::setMarginTopKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginTopKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",101)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",101)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginTop(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setMarginTopKey,(void))

Void StyleProxy_obj::setMarginRightNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginRightNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",105)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",105)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginRight((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setMarginRightNum,(void))

Void StyleProxy_obj::setMarginRightKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginRightKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",109)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",109)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginRight(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setMarginRightKey,(void))

Void StyleProxy_obj::setMarginBottomNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginBottomNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",114)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",114)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginBottom((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setMarginBottomNum,(void))

Void StyleProxy_obj::setMarginBottomKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setMarginBottomKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",118)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",118)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_marginBottom(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setMarginBottomKey,(void))

Void StyleProxy_obj::setPaddingLeft( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setPaddingLeft")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",123)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",123)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_paddingLeft((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setPaddingLeft,(void))

Void StyleProxy_obj::setPaddingTop( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setPaddingTop")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",127)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",127)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_paddingTop((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setPaddingTop,(void))

Void StyleProxy_obj::setPaddingRight( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setPaddingRight")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",131)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",131)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_paddingRight((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setPaddingRight,(void))

Void StyleProxy_obj::setPaddingBottom( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setPaddingBottom")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",135)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",135)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_paddingBottom((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setPaddingBottom,(void))

Void StyleProxy_obj::setWidth( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setWidth")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",169)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",169)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_width((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setWidth,(void))

Void StyleProxy_obj::setHeight( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setHeight")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",172)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",172)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_height((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setHeight,(void))

Void StyleProxy_obj::setTop( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTop")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",187)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",187)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_top((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setTop,(void))

Void StyleProxy_obj::setLeft( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLeft")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",190)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",190)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_left((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setLeft,(void))

Void StyleProxy_obj::setBottom( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBottom")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",193)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",193)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_bottom((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setBottom,(void))

Void StyleProxy_obj::setRight( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setRight")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",196)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",196)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_right((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setRight,(void))

Void StyleProxy_obj::setTopKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTopKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",199)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",199)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_top(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setTopKey,(void))

Void StyleProxy_obj::setLeftKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLeftKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",202)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",202)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_left(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setLeftKey,(void))

Void StyleProxy_obj::setBottomKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBottomKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",205)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",205)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_bottom(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBottomKey,(void))

Void StyleProxy_obj::setRightKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setRightKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",208)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",208)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_right(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setRightKey,(void))

Void StyleProxy_obj::setBgColorNum( Dynamic _tmp_element,int value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgColorNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",211)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",211)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundColor((HX_CSTRING("#") + ::Std_obj::string(value)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgColorNum,(void))

Void StyleProxy_obj::setBgColorRGBA( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgColorRGBA")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",214)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",214)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundColor(((HX_CSTRING("rgba(") + value) + HX_CSTRING(")")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgColorRGBA,(void))

Void StyleProxy_obj::setBgColorKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgColorKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",217)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",217)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundColor(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgColorKey,(void))

Void StyleProxy_obj::setBgImage( Dynamic _tmp_element,Array< ::String > value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgImage")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",220)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",220)
		if (((value->length > (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",223)
			(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundImage((HX_CSTRING("\"") + value->join(HX_CSTRING("\""))));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",225)
			(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundImage(HX_CSTRING(""));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgImage,(void))

Void StyleProxy_obj::setBgAttachment( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgAttachment")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",227)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgAttachment,(void))

Void StyleProxy_obj::setBgRepeat( Dynamic _tmp_element,Array< ::String > value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgRepeat")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",230)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",230)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_backgroundRepeat(value->join(HX_CSTRING(",")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgRepeat,(void))

Void StyleProxy_obj::setBgPosXKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgPosXKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",239)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgPosXKey,(void))

Void StyleProxy_obj::setBgPosYKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgPosYKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",241)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setBgPosYKey,(void))

Void StyleProxy_obj::setBgPosYNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgPosYNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",243)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setBgPosYNum,(void))

Void StyleProxy_obj::setBgPosXNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setBgPosXNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",245)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setBgPosXNum,(void))

Void StyleProxy_obj::setFontSizeNum( Dynamic _tmp_element,double value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontSizeNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",252)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",252)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontSize((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setFontSizeNum,(void))

Void StyleProxy_obj::setFontSizeKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontSizeKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",255)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",255)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontSize(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontSizeKey,(void))

Void StyleProxy_obj::setFontWeightNum( Dynamic _tmp_element,int value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontWeightNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",258)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",258)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontWeight(::Std_obj::string(value));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontWeightNum,(void))

Void StyleProxy_obj::setFontWeightKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontWeightKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",261)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",261)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontWeight(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontWeightKey,(void))

Void StyleProxy_obj::setFontStyle( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontStyle")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",264)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",264)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontStyle(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontStyle,(void))

Void StyleProxy_obj::setFontFamily( Dynamic _tmp_element,Array< ::String > value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontFamily")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",267)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",267)
		if (((value->length > (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",269)
			(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontFamily(value->join(HX_CSTRING(",")));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",271)
			(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontFamily(HX_CSTRING(""));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontFamily,(void))

Void StyleProxy_obj::setFontVariant( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setFontVariant")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",273)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",273)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_fontVariant(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setFontVariant,(void))

Void StyleProxy_obj::setTextColorKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTextColorKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",276)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",276)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_color(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setTextColorKey,(void))

Void StyleProxy_obj::setTextColorNum( Dynamic _tmp_element,int value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTextColorNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",279)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",279)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_color((HX_CSTRING("#") + ::Std_obj::string(value)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setTextColorNum,(void))

Void StyleProxy_obj::setTextDecoration( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTextDecoration")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",282)
		::cocktail::core::dom::Node element = _tmp_element;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setTextDecoration,(void))

Void StyleProxy_obj::setLineHeightKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLineHeightKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",285)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",285)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_lineHeight(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setLineHeightKey,(void))

Void StyleProxy_obj::setLineHeightNum( Dynamic _tmp_element,double value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLineHeightNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",288)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",288)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_lineHeight((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setLineHeightNum,(void))

Void StyleProxy_obj::setTextTransform( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setTextTransform")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",291)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",291)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_textTransform(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setTextTransform,(void))

Void StyleProxy_obj::setLetterSpacingNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLetterSpacingNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",294)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",294)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_letterSpacing((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setLetterSpacingNum,(void))

Void StyleProxy_obj::setLetterSpacingKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setLetterSpacingKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",297)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",297)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_letterSpacing(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setLetterSpacingKey,(void))

Void StyleProxy_obj::setWordSpacingNum( Dynamic _tmp_element,int value,::String unit){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setWordSpacingNum")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",300)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",300)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_wordSpacing((value + unit));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleProxy_obj,setWordSpacingNum,(void))

Void StyleProxy_obj::setWordSpacingKey( Dynamic _tmp_element,::String value){
{
		HX_SOURCE_PUSH("StyleProxy_obj::setWordSpacingKey")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",303)
		::cocktail::core::dom::Node element = _tmp_element;
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",303)
		(hx::TCast< cocktail::core::html::HTMLElement >::cast(element))->get_style()->set_wordSpacing(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StyleProxy_obj,setWordSpacingKey,(void))


StyleProxy_obj::StyleProxy_obj()
{
}

void StyleProxy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StyleProxy);
	HX_MARK_END_CLASS();
}

Dynamic StyleProxy_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"setTop") ) { return setTop_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setLeft") ) { return setLeft_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setWidth") ) { return setWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setRight") ) { return setRight_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setHeight") ) { return setHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setBottom") ) { return setBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"setTopKey") ) { return setTopKey_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setDisplay") ) { return setDisplay_dyn(); }
		if (HX_FIELD_EQ(inName,"setLeftKey") ) { return setLeftKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgImage") ) { return setBgImage_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setRightKey") ) { return setRightKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgRepeat") ) { return setBgRepeat_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setBottomKey") ) { return setBottomKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgPosXKey") ) { return setBgPosXKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgPosYKey") ) { return setBgPosYKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgPosYNum") ) { return setBgPosYNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgPosXNum") ) { return setBgPosXNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontStyle") ) { return setFontStyle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setPaddingTop") ) { return setPaddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgColorNum") ) { return setBgColorNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgColorKey") ) { return setBgColorKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontFamily") ) { return setFontFamily_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setPaddingLeft") ) { return setPaddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgColorRGBA") ) { return setBgColorRGBA_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontSizeNum") ) { return setFontSizeNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontSizeKey") ) { return setFontSizeKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontVariant") ) { return setFontVariant_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setMarginTopNum") ) { return setMarginTopNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginTopKey") ) { return setMarginTopKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingRight") ) { return setPaddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"setBgAttachment") ) { return setBgAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextColorKey") ) { return setTextColorKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextColorNum") ) { return setTextColorNum_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setMarginLeftNum") ) { return setMarginLeftNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginLeftKey") ) { return setMarginLeftKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingBottom") ) { return setPaddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontWeightNum") ) { return setFontWeightNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontWeightKey") ) { return setFontWeightKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setLineHeightKey") ) { return setLineHeightKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setLineHeightNum") ) { return setLineHeightNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextTransform") ) { return setTextTransform_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setMarginRightNum") ) { return setMarginRightNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginRightKey") ) { return setMarginRightKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextDecoration") ) { return setTextDecoration_dyn(); }
		if (HX_FIELD_EQ(inName,"setWordSpacingNum") ) { return setWordSpacingNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setWordSpacingKey") ) { return setWordSpacingKey_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setMarginBottomNum") ) { return setMarginBottomNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginBottomKey") ) { return setMarginBottomKey_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"setLetterSpacingNum") ) { return setLetterSpacingNum_dyn(); }
		if (HX_FIELD_EQ(inName,"setLetterSpacingKey") ) { return setLetterSpacingKey_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StyleProxy_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void StyleProxy_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setDisplay"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("setMarginLeftNum"),
	HX_CSTRING("setMarginLeftKey"),
	HX_CSTRING("setMarginTopNum"),
	HX_CSTRING("setMarginTopKey"),
	HX_CSTRING("setMarginRightNum"),
	HX_CSTRING("setMarginRightKey"),
	HX_CSTRING("setMarginBottomNum"),
	HX_CSTRING("setMarginBottomKey"),
	HX_CSTRING("setPaddingLeft"),
	HX_CSTRING("setPaddingTop"),
	HX_CSTRING("setPaddingRight"),
	HX_CSTRING("setPaddingBottom"),
	HX_CSTRING("setWidth"),
	HX_CSTRING("setHeight"),
	HX_CSTRING("setTop"),
	HX_CSTRING("setLeft"),
	HX_CSTRING("setBottom"),
	HX_CSTRING("setRight"),
	HX_CSTRING("setTopKey"),
	HX_CSTRING("setLeftKey"),
	HX_CSTRING("setBottomKey"),
	HX_CSTRING("setRightKey"),
	HX_CSTRING("setBgColorNum"),
	HX_CSTRING("setBgColorRGBA"),
	HX_CSTRING("setBgColorKey"),
	HX_CSTRING("setBgImage"),
	HX_CSTRING("setBgAttachment"),
	HX_CSTRING("setBgRepeat"),
	HX_CSTRING("setBgPosXKey"),
	HX_CSTRING("setBgPosYKey"),
	HX_CSTRING("setBgPosYNum"),
	HX_CSTRING("setBgPosXNum"),
	HX_CSTRING("setFontSizeNum"),
	HX_CSTRING("setFontSizeKey"),
	HX_CSTRING("setFontWeightNum"),
	HX_CSTRING("setFontWeightKey"),
	HX_CSTRING("setFontStyle"),
	HX_CSTRING("setFontFamily"),
	HX_CSTRING("setFontVariant"),
	HX_CSTRING("setTextColorKey"),
	HX_CSTRING("setTextColorNum"),
	HX_CSTRING("setTextDecoration"),
	HX_CSTRING("setLineHeightKey"),
	HX_CSTRING("setLineHeightNum"),
	HX_CSTRING("setTextTransform"),
	HX_CSTRING("setLetterSpacingNum"),
	HX_CSTRING("setLetterSpacingKey"),
	HX_CSTRING("setWordSpacingNum"),
	HX_CSTRING("setWordSpacingKey"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StyleProxy_obj::__mClass;

void StyleProxy_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.hxtml.StyleProxy"), hx::TCanCast< StyleProxy_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StyleProxy_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace hxtml
