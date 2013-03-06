#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void List_obj::__construct()
{
HX_STACK_PUSH("List::new","C:\\Motion-Twin\\Haxe/std/List.hx",44);
{
	HX_STACK_LINE(44)
	this->length = (int)0;
}
;
	return null();
}

List_obj::~List_obj() { }

Dynamic List_obj::__CreateEmpty() { return  new List_obj; }
hx::ObjectPtr< List_obj > List_obj::__new()
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Dynamic List_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

::List List_obj::map( Dynamic f){
	HX_STACK_PUSH("List::map","C:\\Motion-Twin\\Haxe/std/List.hx",246);
	HX_STACK_THIS(this);
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(247)
	::List b = ::List_obj::__new();		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(248)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(249)
	while(((l != null()))){
		HX_STACK_LINE(250)
		Dynamic v = l->__GetItem((int)0);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(251)
		l = l->__GetItem((int)1);
		HX_STACK_LINE(252)
		b->add(f(v));
	}
	HX_STACK_LINE(254)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,map,return )

::List List_obj::filter( Dynamic f){
	HX_STACK_PUSH("List::filter","C:\\Motion-Twin\\Haxe/std/List.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(231)
	::List l2 = ::List_obj::__new();		HX_STACK_VAR(l2,"l2");
	HX_STACK_LINE(232)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(233)
	while(((l != null()))){
		HX_STACK_LINE(234)
		Dynamic v = l->__GetItem((int)0);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(235)
		l = l->__GetItem((int)1);
		HX_STACK_LINE(236)
		if ((f(v).Cast< bool >())){
			HX_STACK_LINE(237)
			l2->add(v);
		}
	}
	HX_STACK_LINE(239)
	return l2;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,filter,return )

::String List_obj::join( ::String sep){
	HX_STACK_PUSH("List::join","C:\\Motion-Twin\\Haxe/std/List.hx",211);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sep,"sep");
	HX_STACK_LINE(212)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(213)
	bool first = true;		HX_STACK_VAR(first,"first");
	HX_STACK_LINE(214)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(215)
	while(((l != null()))){
		HX_STACK_LINE(216)
		if ((first)){
			HX_STACK_LINE(217)
			first = false;
		}
		else{
			HX_STACK_LINE(219)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = sep;
		}
		HX_STACK_LINE(220)
		hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = l->__GetItem((int)0);
		HX_STACK_LINE(221)
		l = l->__GetItem((int)1);
	}
	HX_STACK_LINE(223)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,join,return )

::String List_obj::toString( ){
	HX_STACK_PUSH("List::toString","C:\\Motion-Twin\\Haxe/std/List.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_LINE(192)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(193)
	bool first = true;		HX_STACK_VAR(first,"first");
	HX_STACK_LINE(194)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(195)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("{");
	HX_STACK_LINE(196)
	while(((l != null()))){
		HX_STACK_LINE(197)
		if ((first)){
			HX_STACK_LINE(198)
			first = false;
		}
		else{
			HX_STACK_LINE(200)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(", ");
		}
		HX_STACK_LINE(201)
		hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::Std_obj::string(l->__GetItem((int)0));
		HX_STACK_LINE(202)
		l = l->__GetItem((int)1);
	}
	HX_STACK_LINE(204)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("}");
	HX_STACK_LINE(205)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,toString,return )

Dynamic List_obj::iterator( ){
	HX_STACK_PUSH("List::iterator","C:\\Motion-Twin\\Haxe/std/List.hx",152);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static Dynamic Block( ::List_obj *__this){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/List.hx",170);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("h") , __this->h,false);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_1)
				Dynamic run(){
					HX_STACK_PUSH("*::_Function_2_1","C:\\Motion-Twin\\Haxe/std/List.hx",172);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(172)
						return (__this->__Field(HX_CSTRING("h"),true) != null());
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_2)
				Dynamic run(){
					HX_STACK_PUSH("*::_Function_2_2","C:\\Motion-Twin\\Haxe/std/List.hx",175);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(177)
						if (((__this->__Field(HX_CSTRING("h"),true) == null()))){
							HX_STACK_LINE(178)
							return null();
						}
						HX_STACK_LINE(179)
						Dynamic x = __this->__Field(HX_CSTRING("h"),true)->__GetItem((int)0);		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(180)
						__this->__FieldRef(HX_CSTRING("h")) = __this->__Field(HX_CSTRING("h"),true)->__GetItem((int)1);
						HX_STACK_LINE(181)
						return x;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2()),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(152)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,iterator,return )

bool List_obj::remove( Dynamic v){
	HX_STACK_PUSH("List::remove","C:\\Motion-Twin\\Haxe/std/List.hx",129);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(130)
	Dynamic prev = null();		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(131)
	Dynamic l = this->h;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(132)
	while(((l != null()))){
		HX_STACK_LINE(133)
		if (((l->__GetItem((int)0) == v))){
			HX_STACK_LINE(134)
			if (((prev == null()))){
				HX_STACK_LINE(135)
				this->h = l->__GetItem((int)1);
			}
			else{
				HX_STACK_LINE(137)
				hx::IndexRef((prev).mPtr,(int)1) = l->__GetItem((int)1);
			}
			HX_STACK_LINE(138)
			if (((this->q == l))){
				HX_STACK_LINE(139)
				this->q = prev;
			}
			HX_STACK_LINE(140)
			(this->length)--;
			HX_STACK_LINE(141)
			return true;
		}
		HX_STACK_LINE(143)
		prev = l;
		HX_STACK_LINE(144)
		l = l->__GetItem((int)1);
	}
	HX_STACK_LINE(146)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,remove,return )

Void List_obj::clear( ){
{
		HX_STACK_PUSH("List::clear","C:\\Motion-Twin\\Haxe/std/List.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_LINE(120)
		this->h = null();
		HX_STACK_LINE(121)
		this->q = null();
		HX_STACK_LINE(122)
		this->length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,clear,(void))

bool List_obj::isEmpty( ){
	HX_STACK_PUSH("List::isEmpty","C:\\Motion-Twin\\Haxe/std/List.hx",112);
	HX_STACK_THIS(this);
	HX_STACK_LINE(112)
	return (this->h == null());
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,isEmpty,return )

Dynamic List_obj::pop( ){
	HX_STACK_PUSH("List::pop","C:\\Motion-Twin\\Haxe/std/List.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_LINE(99)
	if (((this->h == null()))){
		HX_STACK_LINE(100)
		return null();
	}
	HX_STACK_LINE(101)
	Dynamic x = this->h->__GetItem((int)0);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(102)
	this->h = this->h->__GetItem((int)1);
	HX_STACK_LINE(103)
	if (((this->h == null()))){
		HX_STACK_LINE(104)
		this->q = null();
	}
	HX_STACK_LINE(105)
	(this->length)--;
	HX_STACK_LINE(106)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,pop,return )

Dynamic List_obj::last( ){
	HX_STACK_PUSH("List::last","C:\\Motion-Twin\\Haxe/std/List.hx",88);
	HX_STACK_THIS(this);
	HX_STACK_LINE(88)
	return (  (((this->q == null()))) ? Dynamic(null()) : Dynamic(this->q->__GetItem((int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,last,return )

Dynamic List_obj::first( ){
	HX_STACK_PUSH("List::first","C:\\Motion-Twin\\Haxe/std/List.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_LINE(80)
	return (  (((this->h == null()))) ? Dynamic(null()) : Dynamic(this->h->__GetItem((int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,first,return )

Void List_obj::push( Dynamic item){
{
		HX_STACK_PUSH("List::push","C:\\Motion-Twin\\Haxe/std/List.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_ARG(item,"item");
		HX_STACK_LINE(65)
		Dynamic x = Dynamic( Array_obj<Dynamic>::__new().Add(item).Add(this->h));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(70)
		this->h = x;
		HX_STACK_LINE(71)
		if (((this->q == null()))){
			HX_STACK_LINE(72)
			this->q = x;
		}
		HX_STACK_LINE(73)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,push,(void))

Void List_obj::add( Dynamic item){
{
		HX_STACK_PUSH("List::add","C:\\Motion-Twin\\Haxe/std/List.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(item,"item");
		HX_STACK_LINE(52)
		Dynamic x = Dynamic( Array_obj<Dynamic>::__new().Add(item));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(53)
		if (((this->h == null()))){
			HX_STACK_LINE(54)
			this->h = x;
		}
		else{
			HX_STACK_LINE(56)
			hx::IndexRef((this->q).mPtr,(int)1) = x;
		}
		HX_STACK_LINE(57)
		this->q = x;
		HX_STACK_LINE(58)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,add,(void))


List_obj::List_obj()
{
}

void List_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(List);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(q,"q");
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_END_CLASS();
}

void List_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(q,"q");
	HX_VISIT_MEMBER_NAME(h,"h");
}

Dynamic List_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"q") ) { return q; }
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { return map_dyn(); }
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"join") ) { return join_dyn(); }
		if (HX_FIELD_EQ(inName,"last") ) { return last_dyn(); }
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"first") ) { return first_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { return filter_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic List_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"q") ) { q=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void List_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("q"));
	outFields->push(HX_CSTRING("h"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("map"),
	HX_CSTRING("filter"),
	HX_CSTRING("join"),
	HX_CSTRING("toString"),
	HX_CSTRING("iterator"),
	HX_CSTRING("remove"),
	HX_CSTRING("clear"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("pop"),
	HX_CSTRING("last"),
	HX_CSTRING("first"),
	HX_CSTRING("push"),
	HX_CSTRING("add"),
	HX_CSTRING("length"),
	HX_CSTRING("q"),
	HX_CSTRING("h"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(List_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(List_obj::__mClass,"__mClass");
};

Class List_obj::__mClass;

void List_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("List"), hx::TCanCast< List_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void List_obj::__boot()
{
}

