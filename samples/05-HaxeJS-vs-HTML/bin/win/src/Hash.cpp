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
HX_STACK_PUSH("Hash::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",29);
{
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",30);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(29)
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

::String Hash_obj::toString( ){
	HX_STACK_PUSH("Hash::toString","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_LINE(77)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(78)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("{");
	HX_STACK_LINE(79)
	Dynamic it = this->keys();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(80)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(it);  __it->hasNext(); ){
		::String i = __it->next();
		{
			HX_STACK_LINE(81)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = i;
			HX_STACK_LINE(82)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(" => ");
			HX_STACK_LINE(83)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::Std_obj::string(this->get(i));
			HX_STACK_LINE(84)
			if ((it->__Field(HX_CSTRING("hasNext"),true)())){
				HX_STACK_LINE(85)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(", ");
			}
		}
;
	}
	HX_STACK_LINE(87)
	hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("}");
	HX_STACK_LINE(88)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,toString,return )

Dynamic Hash_obj::iterator( ){
	HX_STACK_PUSH("Hash::iterator","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(62)
	Array< ::String > a = Array_obj< ::String >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(63)
	this->__Internal->__GetFields(a);
	HX_STACK_LINE(64)
	Dynamic it = Dynamic( Array_obj<Dynamic>::__new().Add(a->iterator()));		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(65)
	Array< ::Hash > me = Array_obj< ::Hash >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(me,"me");
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &it,Array< ::Hash > &me){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",66);
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,it)
				bool run(){
					HX_STACK_PUSH("*::_Function_2_1","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",67);
					{
						HX_STACK_LINE(67)
						return it->__GetItem((int)0)->__Field(HX_CSTRING("hasNext"),true)();
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(it)),true);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< ::Hash >,me,Dynamic,it)
				Dynamic run(){
					HX_STACK_PUSH("*::_Function_2_2","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",68);
					{
						HX_STACK_LINE(68)
						return me->__get((int)0)->__Internal->__Field(it->__GetItem((int)0)->__Field(HX_CSTRING("next"),true)(),true);
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(me,it)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(66)
	return _Function_1_1::Block(it,me);
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,iterator,return )

Dynamic Hash_obj::keys( ){
	HX_STACK_PUSH("Hash::keys","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(53)
	Array< ::String > a = Array_obj< ::String >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(54)
	this->__Internal->__GetFields(a);
	HX_STACK_LINE(55)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,keys,return )

bool Hash_obj::remove( ::String key){
	HX_STACK_PUSH("Hash::remove","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(45)
	return ::__hxcpp_anon_remove(this->__Internal,key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,remove,return )

bool Hash_obj::exists( ::String key){
	HX_STACK_PUSH("Hash::exists","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(41)
	return this->__Internal->__HasField(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,exists,return )

Dynamic Hash_obj::get( ::String key){
	HX_STACK_PUSH("Hash::get","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(37)
	return this->__Internal->__Field(key,true);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,get,return )

Void Hash_obj::set( ::String key,Dynamic value){
{
		HX_STACK_PUSH("Hash::set","C:\\Motion-Twin\\Haxe/std/cpp/_std/Hash.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(33)
		this->__Internal->__SetField(key,value,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Hash_obj,set,(void))


Hash_obj::Hash_obj()
{
}

void Hash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Hash);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_END_CLASS();
}

void Hash_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__Internal,"__Internal");
}

Dynamic Hash_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Hash_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Hash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__Internal"));
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
	HX_CSTRING("__Internal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Hash_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Hash_obj::__mClass,"__mClass");
};

Class Hash_obj::__mClass;

void Hash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Hash"), hx::TCanCast< Hash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Hash_obj::__boot()
{
}

