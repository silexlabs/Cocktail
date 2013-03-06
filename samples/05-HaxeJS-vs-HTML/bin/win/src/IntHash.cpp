#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void IntHash_obj::__construct()
{
HX_STACK_PUSH("IntHash::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",30);
{
	HX_STACK_LINE(30)
	this->h = ::__int_hash_create();
}
;
	return null();
}

IntHash_obj::~IntHash_obj() { }

Dynamic IntHash_obj::__CreateEmpty() { return  new IntHash_obj; }
hx::ObjectPtr< IntHash_obj > IntHash_obj::__new()
{  hx::ObjectPtr< IntHash_obj > result = new IntHash_obj();
	result->__construct();
	return result;}

Dynamic IntHash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntHash_obj > result = new IntHash_obj();
	result->__construct();
	return result;}

::String IntHash_obj::toString( ){
	HX_STACK_PUSH("IntHash::toString","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(62)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("{");
	HX_STACK_LINE(63)
	Dynamic it = this->keys();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(64)
	for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(it);  __it->hasNext(); ){
		int i = __it->next();
		{
			HX_STACK_LINE(65)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = i;
			HX_STACK_LINE(66)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(" => ");
			HX_STACK_LINE(67)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::Std_obj::string(this->get(i));
			HX_STACK_LINE(68)
			if ((it->__Field(HX_CSTRING("hasNext"),true)())){
				HX_STACK_LINE(69)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(", ");
			}
		}
;
	}
	HX_STACK_LINE(71)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("}");
	HX_STACK_LINE(72)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,toString,return )

Dynamic IntHash_obj::iterator( ){
	HX_STACK_PUSH("IntHash::iterator","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_LINE(56)
	Dynamic a = ::__int_hash_values(this->h);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(57)
	return a->__Field(HX_CSTRING("iterator"),true)();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,iterator,return )

Dynamic IntHash_obj::keys( ){
	HX_STACK_PUSH("IntHash::keys","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_LINE(51)
	Array< int > a = ::__int_hash_keys(this->h);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(52)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,keys,return )

bool IntHash_obj::remove( int key){
	HX_STACK_PUSH("IntHash::remove","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(46)
	return ::__int_hash_remove(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,remove,return )

bool IntHash_obj::exists( int key){
	HX_STACK_PUSH("IntHash::exists","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(42)
	return ::__int_hash_exists(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,exists,return )

Dynamic IntHash_obj::get( int key){
	HX_STACK_PUSH("IntHash::get","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(38)
	return ::__int_hash_get(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,get,return )

Void IntHash_obj::set( int key,Dynamic value){
{
		HX_STACK_PUSH("IntHash::set","C:\\Motion-Twin\\Haxe/std/cpp/_std/IntHash.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(34)
		::__int_hash_set(this->h,key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IntHash_obj,set,(void))


IntHash_obj::IntHash_obj()
{
}

void IntHash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IntHash);
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_END_CLASS();
}

void IntHash_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(h,"h");
}

Dynamic IntHash_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IntHash_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IntHash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("h"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("iterator"),
	HX_CSTRING("keys"),
	HX_CSTRING("remove"),
	HX_CSTRING("exists"),
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("h"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IntHash_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IntHash_obj::__mClass,"__mClass");
};

Class IntHash_obj::__mClass;

void IntHash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("IntHash"), hx::TCanCast< IntHash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IntHash_obj::__boot()
{
}

