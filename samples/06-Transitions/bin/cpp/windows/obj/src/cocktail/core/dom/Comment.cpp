#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Comment
#include <cocktail/core/dom/Comment.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Comment_obj::__construct()
{
HX_STACK_PUSH("Comment::new","cocktail/core/dom/Comment.hx",34);
{
	HX_STACK_LINE(34)
	super::__construct();
}
;
	return null();
}

Comment_obj::~Comment_obj() { }

Dynamic Comment_obj::__CreateEmpty() { return  new Comment_obj; }
hx::ObjectPtr< Comment_obj > Comment_obj::__new()
{  hx::ObjectPtr< Comment_obj > result = new Comment_obj();
	result->__construct();
	return result;}

Dynamic Comment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Comment_obj > result = new Comment_obj();
	result->__construct();
	return result;}

int Comment_obj::get_nodeType( ){
	HX_STACK_PUSH("Comment::get_nodeType","cocktail/core/dom/Comment.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_LINE(66)
	return (int)8;
}


Void Comment_obj::detach( bool recursive){
{
		HX_STACK_PUSH("Comment::detach","cocktail/core/dom/Comment.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
	}
return null();
}


Void Comment_obj::attach( bool recursive){
{
		HX_STACK_PUSH("Comment::attach","cocktail/core/dom/Comment.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
	}
return null();
}


Void Comment_obj::updateElementRenderer( ){
{
		HX_STACK_PUSH("Comment::updateElementRenderer","cocktail/core/dom/Comment.hx",47);
		HX_STACK_THIS(this);
	}
return null();
}



Comment_obj::Comment_obj()
{
}

void Comment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Comment);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Comment_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Comment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updateElementRenderer") ) { return updateElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Comment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Comment_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("updateElementRenderer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Comment_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Comment_obj::__mClass,"__mClass");
};

Class Comment_obj::__mClass;

void Comment_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Comment"), hx::TCanCast< Comment_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Comment_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
