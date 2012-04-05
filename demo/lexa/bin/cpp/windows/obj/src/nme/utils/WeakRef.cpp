#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_utils_WeakRef
#include <nme/utils/WeakRef.h>
#endif
namespace nme{
namespace utils{

Void WeakRef_obj::__construct(Dynamic inObject,Dynamic __o_inMakeWeak)
{
bool inMakeWeak = __o_inMakeWeak.Default(true);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",17)
	if ((inMakeWeak)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",20)
		this->weakRef = ::nme::utils::WeakRef_obj::nme_weak_ref_create(hx::ObjectPtr<OBJ_>(this),inObject);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",21)
		this->hardRef = null();
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",25)
		this->weakRef = (int)-1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",26)
		this->hardRef = inObject;
	}
}
;
	return null();
}

WeakRef_obj::~WeakRef_obj() { }

Dynamic WeakRef_obj::__CreateEmpty() { return  new WeakRef_obj; }
hx::ObjectPtr< WeakRef_obj > WeakRef_obj::__new(Dynamic inObject,Dynamic __o_inMakeWeak)
{  hx::ObjectPtr< WeakRef_obj > result = new WeakRef_obj();
	result->__construct(inObject,__o_inMakeWeak);
	return result;}

Dynamic WeakRef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WeakRef_obj > result = new WeakRef_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic WeakRef_obj::get( ){
	HX_SOURCE_PUSH("WeakRef_obj::get")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",33)
	if (((this->hardRef != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",34)
		return this->hardRef;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",36)
	if (((this->weakRef < (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",37)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",39)
	Dynamic result = ::nme::utils::WeakRef_obj::nme_weak_ref_get(this->weakRef);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",40)
	if (((result == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",41)
		this->weakRef = (int)-1;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",42)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(WeakRef_obj,get,return )

::String WeakRef_obj::toString( ){
	HX_SOURCE_PUSH("WeakRef_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",48)
	if (((this->hardRef == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",49)
		return (HX_CSTRING("") + this->hardRef);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/utils/WeakRef.hx",51)
	return ((HX_CSTRING("WeakRef(") + this->weakRef) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(WeakRef_obj,toString,return )

Dynamic WeakRef_obj::nme_weak_ref_create;

Dynamic WeakRef_obj::nme_weak_ref_get;


WeakRef_obj::WeakRef_obj()
{
}

void WeakRef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WeakRef);
	HX_MARK_MEMBER_NAME(hardRef,"hardRef");
	HX_MARK_MEMBER_NAME(weakRef,"weakRef");
	HX_MARK_END_CLASS();
}

Dynamic WeakRef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hardRef") ) { return hardRef; }
		if (HX_FIELD_EQ(inName,"weakRef") ) { return weakRef; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_weak_ref_get") ) { return nme_weak_ref_get; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_weak_ref_create") ) { return nme_weak_ref_create; }
	}
	return super::__Field(inName);
}

Dynamic WeakRef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"hardRef") ) { hardRef=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weakRef") ) { weakRef=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_weak_ref_get") ) { nme_weak_ref_get=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_weak_ref_create") ) { nme_weak_ref_create=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void WeakRef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hardRef"));
	outFields->push(HX_CSTRING("weakRef"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_weak_ref_create"),
	HX_CSTRING("nme_weak_ref_get"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("hardRef"),
	HX_CSTRING("weakRef"),
	HX_CSTRING("get"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WeakRef_obj::nme_weak_ref_create,"nme_weak_ref_create");
	HX_MARK_MEMBER_NAME(WeakRef_obj::nme_weak_ref_get,"nme_weak_ref_get");
};

Class WeakRef_obj::__mClass;

void WeakRef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.utils.WeakRef"), hx::TCanCast< WeakRef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void WeakRef_obj::__boot()
{
	hx::Static(nme_weak_ref_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_weak_ref_create"),(int)2);
	hx::Static(nme_weak_ref_get) = ::nme::Loader_obj::load(HX_CSTRING("nme_weak_ref_get"),(int)1);
}

} // end namespace nme
} // end namespace utils
