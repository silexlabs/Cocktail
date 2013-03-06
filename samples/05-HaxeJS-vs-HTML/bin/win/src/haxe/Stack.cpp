#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_Stack
#include <haxe/Stack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
namespace haxe{

Void Stack_obj::__construct()
{
	return null();
}

Stack_obj::~Stack_obj() { }

Dynamic Stack_obj::__CreateEmpty() { return  new Stack_obj; }
hx::ObjectPtr< Stack_obj > Stack_obj::__new()
{  hx::ObjectPtr< Stack_obj > result = new Stack_obj();
	result->__construct();
	return result;}

Dynamic Stack_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stack_obj > result = new Stack_obj();
	result->__construct();
	return result;}

Array< ::haxe::StackItem > Stack_obj::callStack( ){
	HX_STACK_PUSH("Stack::callStack","C:\\Motion-Twin\\Haxe/std/haxe/Stack.hx",46);
	HX_STACK_LINE(60)
	Array< ::String > s = ::__hxcpp_get_call_stack(true);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(61)
	return ::haxe::Stack_obj::makeStack(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stack_obj,callStack,return )

Array< ::haxe::StackItem > Stack_obj::exceptionStack( ){
	Array< ::String > s = ::__hxcpp_get_exception_stack();
	return ::haxe::Stack_obj::makeStack(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stack_obj,exceptionStack,return )

::String Stack_obj::toString( Array< ::haxe::StackItem > stack){
	HX_STACK_PUSH("Stack::toString","C:\\Motion-Twin\\Haxe/std/haxe/Stack.hx",131);
	HX_STACK_ARG(stack,"stack");
	HX_STACK_LINE(132)
	::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(133)
	{
		HX_STACK_LINE(133)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(133)
		while(((_g < stack->length))){
			HX_STACK_LINE(133)
			::haxe::StackItem s = stack->__get(_g);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(133)
			++(_g);
			HX_STACK_LINE(134)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\nCalled from ");
			HX_STACK_LINE(135)
			::haxe::Stack_obj::itemToString(b,s);
		}
	}
	HX_STACK_LINE(137)
	return b->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stack_obj,toString,return )

Void Stack_obj::itemToString( ::StringBuf b,::haxe::StackItem s){
{
		HX_STACK_PUSH("Stack::itemToString","C:\\Motion-Twin\\Haxe/std/haxe/Stack.hx",140);
		HX_STACK_ARG(b,"b");
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(140)
		{
			::haxe::StackItem _switch_1 = (s);
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_STACK_LINE(142)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("a C function");
				}
				;break;
				case 1: {
					::String m = _switch_1->__Param(0);
{
						HX_STACK_LINE(145)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("module ");
						HX_STACK_LINE(146)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = m;
					}
				}
				;break;
				case 2: {
					int line = _switch_1->__Param(2);
					::String file = _switch_1->__Param(1);
					::haxe::StackItem s1 = _switch_1->__Param(0);
{
						HX_STACK_LINE(148)
						if (((s1 != null()))){
							HX_STACK_LINE(149)
							::haxe::Stack_obj::itemToString(b,s1);
							HX_STACK_LINE(150)
							hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(" (");
						}
						HX_STACK_LINE(152)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = file;
						HX_STACK_LINE(153)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(" line ");
						HX_STACK_LINE(154)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = line;
						HX_STACK_LINE(155)
						if (((s1 != null()))){
							HX_STACK_LINE(155)
							hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(")");
						}
					}
				}
				;break;
				case 3: {
					::String meth = _switch_1->__Param(1);
					::String cname = _switch_1->__Param(0);
{
						HX_STACK_LINE(157)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = cname;
						HX_STACK_LINE(158)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(".");
						HX_STACK_LINE(159)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = meth;
					}
				}
				;break;
				case 4: {
					int n = _switch_1->__Param(0);
{
						HX_STACK_LINE(161)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("local function #");
						HX_STACK_LINE(162)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = n;
					}
				}
				;break;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Stack_obj,itemToString,(void))

Array< ::haxe::StackItem > Stack_obj::makeStack( Array< ::String > s){
	Array< ::String > stack = s;
	Array< ::haxe::StackItem > m = Array_obj< ::haxe::StackItem >::__new();
	{
		int _g = (int)0;
		while(((_g < stack->length))){
			::String func = stack->__get(_g);
			++(_g);
			Array< ::String > words = func.split(HX_CSTRING("::"));
			if (((words->length == (int)0))){
				m->unshift(::haxe::StackItem_obj::CFunction_dyn());
			}
			else{
				if (((words->length == (int)2))){
					m->unshift(::haxe::StackItem_obj::Method(words->__get((int)0),words->__get((int)1)));
				}
				else{
					if (((words->length == (int)4))){
						m->unshift(::haxe::StackItem_obj::FilePos(::haxe::StackItem_obj::Method(words->__get((int)0),words->__get((int)1)),words->__get((int)2),::Std_obj::parseInt(words->__get((int)3))));
					}
				}
			}
		}
	}
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stack_obj,makeStack,return )


Stack_obj::Stack_obj()
{
}

void Stack_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stack);
	HX_MARK_END_CLASS();
}

void Stack_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Stack_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"callStack") ) { return callStack_dyn(); }
		if (HX_FIELD_EQ(inName,"makeStack") ) { return makeStack_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"itemToString") ) { return itemToString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"exceptionStack") ) { return exceptionStack_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stack_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Stack_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callStack"),
	HX_CSTRING("exceptionStack"),
	HX_CSTRING("toString"),
	HX_CSTRING("itemToString"),
	HX_CSTRING("makeStack"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stack_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stack_obj::__mClass,"__mClass");
};

Class Stack_obj::__mClass;

void Stack_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Stack"), hx::TCanCast< Stack_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Stack_obj::__boot()
{
}

} // end namespace haxe
