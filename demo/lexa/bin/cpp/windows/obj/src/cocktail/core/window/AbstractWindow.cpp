#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
namespace cocktail{
namespace core{
namespace window{

Void AbstractWindow_obj::__construct(::cocktail::core::dom::Document document)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",55)
	this->_document = document;
}
;
	return null();
}

AbstractWindow_obj::~AbstractWindow_obj() { }

Dynamic AbstractWindow_obj::__CreateEmpty() { return  new AbstractWindow_obj; }
hx::ObjectPtr< AbstractWindow_obj > AbstractWindow_obj::__new(::cocktail::core::dom::Document document)
{  hx::ObjectPtr< AbstractWindow_obj > result = new AbstractWindow_obj();
	result->__construct(document);
	return result;}

Dynamic AbstractWindow_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractWindow_obj > result = new AbstractWindow_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *AbstractWindow_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::event::IEventTarget_obj)) return operator ::cocktail::core::event::IEventTarget_obj *();
	return super::__ToInterface(inType);
}

Dynamic AbstractWindow_obj::set_onResize( Dynamic value){
	HX_SOURCE_PUSH("AbstractWindow_obj::set_onResize")
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",64)
	return this->_onResize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractWindow_obj,set_onResize,return )

Dynamic AbstractWindow_obj::get_onResize( ){
	HX_SOURCE_PUSH("AbstractWindow_obj::get_onResize")
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",69)
	return this->_onResize_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractWindow_obj,get_onResize,return )

int AbstractWindow_obj::get_innerHeight( ){
	HX_SOURCE_PUSH("AbstractWindow_obj::get_innerHeight")
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",74)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractWindow_obj,get_innerHeight,return )

int AbstractWindow_obj::get_innerWidth( ){
	HX_SOURCE_PUSH("AbstractWindow_obj::get_innerWidth")
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",79)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractWindow_obj,get_innerWidth,return )

::cocktail::core::dom::Document AbstractWindow_obj::get_document( ){
	HX_SOURCE_PUSH("AbstractWindow_obj::get_document")
	HX_SOURCE_POS("../../src/cocktail/core/window/AbstractWindow.hx",84)
	return this->_document;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractWindow_obj,get_document,return )


AbstractWindow_obj::AbstractWindow_obj()
{
}

void AbstractWindow_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractWindow);
	HX_MARK_MEMBER_NAME(_onResize,"_onResize");
	HX_MARK_MEMBER_NAME(onResize,"onResize");
	HX_MARK_MEMBER_NAME(_document,"_document");
	HX_MARK_MEMBER_NAME(document,"document");
	HX_MARK_MEMBER_NAME(innerHeight,"innerHeight");
	HX_MARK_MEMBER_NAME(innerWidth,"innerWidth");
	HX_MARK_END_CLASS();
}

Dynamic AbstractWindow_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { return get_onResize(); }
		if (HX_FIELD_EQ(inName,"document") ) { return get_document(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onResize") ) { return _onResize; }
		if (HX_FIELD_EQ(inName,"_document") ) { return _document; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"innerWidth") ) { return get_innerWidth(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { return get_innerHeight(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_onResize") ) { return set_onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onResize") ) { return get_onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_document") ) { return get_document_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_innerWidth") ) { return get_innerWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractWindow_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { return set_onResize(inValue); }
		if (HX_FIELD_EQ(inName,"document") ) { document=inValue.Cast< ::cocktail::core::dom::Document >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onResize") ) { _onResize=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_document") ) { _document=inValue.Cast< ::cocktail::core::dom::Document >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"innerWidth") ) { innerWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { innerHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractWindow_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_document"));
	outFields->push(HX_CSTRING("document"));
	outFields->push(HX_CSTRING("innerHeight"));
	outFields->push(HX_CSTRING("innerWidth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onResize"),
	HX_CSTRING("onResize"),
	HX_CSTRING("_document"),
	HX_CSTRING("document"),
	HX_CSTRING("innerHeight"),
	HX_CSTRING("innerWidth"),
	HX_CSTRING("set_onResize"),
	HX_CSTRING("get_onResize"),
	HX_CSTRING("get_innerHeight"),
	HX_CSTRING("get_innerWidth"),
	HX_CSTRING("get_document"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractWindow_obj::__mClass;

void AbstractWindow_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.window.AbstractWindow"), hx::TCanCast< AbstractWindow_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractWindow_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace window
