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
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",30)
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

Void IntHash_obj::set( int key,Dynamic value){
{
		HX_SOURCE_PUSH("IntHash_obj::set")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",34)
		::__int_hash_set(this->h,key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IntHash_obj,set,(void))

Dynamic IntHash_obj::get( int key){
	HX_SOURCE_PUSH("IntHash_obj::get")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",38)
	return ::__int_hash_get(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,get,return )

bool IntHash_obj::exists( int key){
	HX_SOURCE_PUSH("IntHash_obj::exists")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",42)
	return ::__int_hash_exists(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,exists,return )

bool IntHash_obj::remove( int key){
	HX_SOURCE_PUSH("IntHash_obj::remove")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",46)
	return ::__int_hash_remove(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntHash_obj,remove,return )

Dynamic IntHash_obj::keys( ){
	HX_SOURCE_PUSH("IntHash_obj::keys")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",51)
	Array< int > a = ::__int_hash_keys(this->h);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",52)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,keys,return )

Dynamic IntHash_obj::iterator( ){
	HX_SOURCE_PUSH("IntHash_obj::iterator")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",56)
	Dynamic a = ::__int_hash_values(this->h);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",57)
	return a->__Field(HX_CSTRING("iterator"))();
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,iterator,return )

::String IntHash_obj::toString( ){
	HX_SOURCE_PUSH("IntHash_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",61)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",62)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("{");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",63)
	Dynamic it = this->keys();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",64)
	for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(it);  __it->hasNext(); ){
		int i = __it->next();
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",65)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = i;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",66)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(" => ");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",67)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::Std_obj::string(this->get(i));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",68)
			if ((it->__Field(HX_CSTRING("hasNext"))())){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",69)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(", ");
			}
		}
;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",71)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("}");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/IntHash.hx",72)
	return s->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(IntHash_obj,toString,return )


IntHash_obj::IntHash_obj()
{
}

void IntHash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IntHash);
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_END_CLASS();
}

Dynamic IntHash_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IntHash_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IntHash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("h"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("h"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("exists"),
	HX_CSTRING("remove"),
	HX_CSTRING("keys"),
	HX_CSTRING("iterator"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class IntHash_obj::__mClass;

void IntHash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("IntHash"), hx::TCanCast< IntHash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IntHash_obj::__boot()
{
}

