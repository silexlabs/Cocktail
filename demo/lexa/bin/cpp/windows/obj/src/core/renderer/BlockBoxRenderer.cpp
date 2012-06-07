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
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace renderer{

Void BlockBoxRenderer_obj::__construct(::port::flash_player::Style style)
{
{
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",26)
	super::__construct(style);
}
;
	return null();
}

BlockBoxRenderer_obj::~BlockBoxRenderer_obj() { }

Dynamic BlockBoxRenderer_obj::__CreateEmpty() { return  new BlockBoxRenderer_obj; }
hx::ObjectPtr< BlockBoxRenderer_obj > BlockBoxRenderer_obj::__new(::port::flash_player::Style style)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic BlockBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BlockBoxRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",36)
		this->super::dispose();
		HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",38)
		{
			HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",38)
			int _g1 = (int)0;
			int _g = this->_lineBoxes->length;
			HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",38)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",38)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",40)
				{
					HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",40)
					int _g3 = (int)0;
					int _g2 = this->_lineBoxes->__get(i)->length;
					HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",40)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",40)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",42)
						this->_lineBoxes->__get(i)->__get(j)->dispose();
					}
				}
			}
		}
		HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",45)
		this->_lineBoxes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,dispose,(void))

Void BlockBoxRenderer_obj::addLineBox( Array< ::core::renderer::ElementRenderer > lineBoxElements){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::addLineBox")
		HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",52)
		this->_lineBoxes->push(lineBoxElements);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,addLineBox,(void))

Void BlockBoxRenderer_obj::removeLineBoxes( ){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::removeLineBoxes")
		HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",60)
		this->_lineBoxes = Array_obj< Array< ::core::renderer::ElementRenderer > >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,removeLineBoxes,(void))

Dynamic BlockBoxRenderer_obj::render( ){
	HX_SOURCE_PUSH("BlockBoxRenderer_obj::render")
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",70)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",75)
	::nme::display::Sprite nativeElement = this->_style->get_htmlElement()->get_nativeElement();
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",77)
	nativeElement->nmeGetGraphics()->clear();
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",78)
	nativeElement->nmeGetGraphics()->beginFill((int)16711680,0.0);
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",79)
	nativeElement->nmeGetGraphics()->drawRect(this->_bounds->__Field(HX_CSTRING("x")),this->_bounds->__Field(HX_CSTRING("y")),this->_bounds->__Field(HX_CSTRING("width")),this->_bounds->__Field(HX_CSTRING("height")));
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",80)
	nativeElement->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",82)
	nativeElement->nmeSetX(this->_style->getComputedStyle()->__Field(HX_CSTRING("marginLeft")));
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",84)
	ret->__Field(HX_CSTRING("push"))(nativeElement);
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",86)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,render,return )

Array< Array< ::core::renderer::ElementRenderer > > BlockBoxRenderer_obj::getLineBoxes( ){
	HX_SOURCE_PUSH("BlockBoxRenderer_obj::getLineBoxes")
	HX_SOURCE_POS("../../src/core/renderer/BlockBoxRenderer.hx",95)
	return this->_lineBoxes;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,getLineBoxes,return )


BlockBoxRenderer_obj::BlockBoxRenderer_obj()
{
}

void BlockBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlockBoxRenderer);
	HX_MARK_MEMBER_NAME(_lineBoxes,"_lineBoxes");
	HX_MARK_MEMBER_NAME(lineBoxes,"lineBoxes");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BlockBoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { return getLineBoxes(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lineBoxes") ) { return _lineBoxes; }
		if (HX_FIELD_EQ(inName,"addLineBox") ) { return addLineBox_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getLineBoxes") ) { return getLineBoxes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeLineBoxes") ) { return removeLineBoxes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BlockBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { lineBoxes=inValue.Cast< Array< Array< ::core::renderer::ElementRenderer > > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lineBoxes") ) { _lineBoxes=inValue.Cast< Array< Array< ::core::renderer::ElementRenderer > > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BlockBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_lineBoxes"));
	outFields->push(HX_CSTRING("lineBoxes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_lineBoxes"),
	HX_CSTRING("lineBoxes"),
	HX_CSTRING("dispose"),
	HX_CSTRING("addLineBox"),
	HX_CSTRING("removeLineBoxes"),
	HX_CSTRING("render"),
	HX_CSTRING("getLineBoxes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BlockBoxRenderer_obj::__mClass;

void BlockBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.renderer.BlockBoxRenderer"), hx::TCanCast< BlockBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BlockBoxRenderer_obj::__boot()
{
}

} // end namespace core
} // end namespace renderer
