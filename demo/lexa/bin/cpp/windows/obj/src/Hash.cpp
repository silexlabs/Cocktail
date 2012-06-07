#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void Hash_obj::__construct()
{
{
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",29)
	this->__Internal = _Function_1_1::Block();
}
;
	return null();
}

Hash_obj::~Hash_obj() { }

Dynamic Hash_obj::__CreateEmpty() { return  new Hash_obj; }
hx::ObjectPtr< Hash_obj > Hash_obj::__new()
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Dynamic Hash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Void Hash_obj::set( ::String key,Dynamic value){
{
		HX_SOURCE_PUSH("Hash_obj::set")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",33)
		this->__Internal->__SetField(key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Hash_obj,set,(void))

Dynamic Hash_obj::get( ::String key){
	HX_SOURCE_PUSH("Hash_obj::get")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",37)
	return this->__Internal->__Field(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,get,return )

bool Hash_obj::exists( ::String key){
	HX_SOURCE_PUSH("Hash_obj::exists")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",41)
	return this->__Internal->__HasField(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,exists,return )

bool Hash_obj::remove( ::String key){
	HX_SOURCE_PUSH("Hash_obj::remove")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",45)
	return ::__hxcpp_anon_remove(this->__Internal,key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,remove,return )

Dynamic Hash_obj::keys( ){
	HX_SOURCE_PUSH("Hash_obj::keys")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",53)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",54)
	this->__Internal->__GetFields(a);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",55)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,keys,return )

Dynamic Hash_obj::iterator( ){
	HX_SOURCE_PUSH("Hash_obj::iterator")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",62)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",63)
	this->__Internal->__GetFields(a);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",64)
	Dynamic it = Dynamic( Array_obj<Dynamic>::__new().Add(a->iterator()));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",65)
	Array< ::Hash > me = Array_obj< ::Hash >::__new().Add(hx::ObjectPtr<OBJ_>(this));
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &it,Array< ::Hash > &me){
			hx::Anon __result = hx::Anon_obj::Create();

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,it)
			bool run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",67)
					return it->__GetItem((int)0)->__Field(HX_CSTRING("hasNext"))();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(it)),true);

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Hash >,me,Dynamic,it)
			Dynamic run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",68)
					return me->__get((int)0)->__Internal->__Field(it->__GetItem((int)0)->__Field(HX_CSTRING("next"))());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(me,it)),true);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",66)
	return _Function_1_1::Block(it,me);
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,iterator,return )

::String Hash_obj::toString( ){
	HX_SOURCE_PUSH("Hash_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",77)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",78)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("{");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",79)
	Dynamic it = this->keys();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",80)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(it);  __it->hasNext(); ){
		::String i = __it->next();
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",81)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = i;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",82)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(" => ");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",83)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::Std_obj::string(this->get(i));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",84)
			if ((it->__Field(HX_CSTRING("hasNext"))())){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",85)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(", ");
			}
		}
;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",87)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("}");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Hash.hx",88)
	return s->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,toString,return )


Hash_obj::Hash_obj()
{
}

void Hash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Hash);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_END_CLASS();
}

Dynamic Hash_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName);
}

Dynamic Hash_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Hash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__Internal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__Internal"),
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

Class Hash_obj::__mClass;

void Hash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Hash"), hx::TCanCast< Hash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Hash_obj::__boot()
{
}

