#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
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
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
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
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_FPS
#include <nme/display/FPS.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",21);
{
	HX_STACK_LINE(23)
	::nme::display::FPS fps = ::nme::display::FPS_obj::__new(null(),null(),null());		HX_STACK_VAR(fps,"fps");
	HX_STACK_LINE(24)
	fps->nmeSetY((int)50);
	HX_STACK_LINE(25)
	::nme::Lib_obj::nmeGetCurrent()->addChild(fps);
	HX_STACK_LINE(28)
	this->addTransitionBox();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::addTransitionBox( ){
{
		HX_STACK_PUSH("Main::addTransitionBox","Main.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(50)
		Array< ::Main > _g = Array_obj< ::Main >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(52)
		Array< ::cocktail::core::html::HTMLElement > transitionBox = Array_obj< ::cocktail::core::html::HTMLElement >::__new().Add(::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("div")));		HX_STACK_VAR(transitionBox,"transitionBox");
		HX_STACK_LINE(53)
		transitionBox->__get((int)0)->set_className(HX_CSTRING("trans"));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(){
			HX_STACK_PUSH("*::_Function_1_1","Main.hx",55);
			{
				HX_STACK_LINE(55)
				return ::Math_obj::floor((::Math_obj::random() * (int)255));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_STACK_LINE(55)
		Dynamic randColor =  Dynamic(new _Function_1_1());		HX_STACK_VAR(randColor,"randColor");
		HX_STACK_LINE(57)
		transitionBox->__get((int)0)->style->set_backgroundColor(((((((HX_CSTRING("rgb(") + randColor().Cast< int >()) + HX_CSTRING(",")) + randColor().Cast< int >()) + HX_CSTRING(",")) + randColor().Cast< int >()) + HX_CSTRING(")")));

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_2,Array< ::Main >,_g,Array< ::cocktail::core::html::HTMLElement >,transitionBox)
		Void run(::cocktail::core::event::Event e){
			HX_STACK_PUSH("*::_Function_1_2","Main.hx",60);
			HX_STACK_ARG(e,"e");
			{
				HX_STACK_LINE(60)
				_g->__get((int)0)->transition(transitionBox->__get((int)0));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(59)
		transitionBox->__get((int)0)->addEventListener(HX_CSTRING("transitionend"), Dynamic(new _Function_1_2(_g,transitionBox)),false);

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_3,Array< ::Main >,_g,Array< ::cocktail::core::html::HTMLElement >,transitionBox)
		Void run(::cocktail::core::event::Event e){
			HX_STACK_PUSH("*::_Function_1_3","Main.hx",66);
			HX_STACK_ARG(e,"e");
			{
				HX_STACK_LINE(66)
				_g->__get((int)0)->transition(transitionBox->__get((int)0));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(65)
		transitionBox->__get((int)0)->addEventListener(HX_CSTRING("webkitTransitionEnd"), Dynamic(new _Function_1_3(_g,transitionBox)),false);

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::Main >,_g)
		Void run(::cocktail::core::event::MouseEvent e){
			HX_STACK_PUSH("*::_Function_1_4","Main.hx",71);
			HX_STACK_ARG(e,"e");
			{
				HX_STACK_LINE(71)
				_g->__get((int)0)->addTransitionBox();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(71)
		transitionBox->__get((int)0)->set_onClick( Dynamic(new _Function_1_4(_g)));
		HX_STACK_LINE(75)
		::cocktail::Lib_obj::get_document()->getElementById(HX_CSTRING("container"))->appendChild(transitionBox->__get((int)0));

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_5,Array< ::Main >,_g,Array< ::cocktail::core::html::HTMLElement >,transitionBox)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_5","Main.hx",77);
			{
				HX_STACK_LINE(77)
				_g->__get((int)0)->transition(transitionBox->__get((int)0));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(77)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_5(_g,transitionBox)),(int)1000);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,addTransitionBox,(void))

Void Main_obj::transition( ::cocktail::core::html::HTMLElement transitionBox){
{
		HX_STACK_PUSH("Main::transition","Main.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transitionBox,"transitionBox");
		HX_STACK_LINE(36)
		::cocktail::core::html::HTMLElement container = ::cocktail::Lib_obj::get_document()->getElementById(HX_CSTRING("container"));		HX_STACK_VAR(container,"container");
		HX_STACK_LINE(38)
		int transWidth = transitionBox->get_clientWidth();		HX_STACK_VAR(transWidth,"transWidth");
		HX_STACK_LINE(39)
		int transHeight = transitionBox->get_clientHeight();		HX_STACK_VAR(transHeight,"transHeight");
		HX_STACK_LINE(40)
		int containerWidth = container->get_clientWidth();		HX_STACK_VAR(containerWidth,"containerWidth");
		HX_STACK_LINE(41)
		int containerHeight = container->get_clientHeight();		HX_STACK_VAR(containerHeight,"containerHeight");
		HX_STACK_LINE(43)
		transitionBox->style->set_left((::Std_obj::string(::Math_obj::round((::Math_obj::random() * ((containerWidth - transWidth))))) + HX_CSTRING("px")));
		HX_STACK_LINE(44)
		transitionBox->style->set_top((::Std_obj::string(::Math_obj::round((::Math_obj::random() * ((containerHeight - transHeight))))) + HX_CSTRING("px")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,transition,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"transition") ) { return transition_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addTransitionBox") ) { return addTransitionBox_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("addTransitionBox"),
	HX_CSTRING("transition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

