#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_nme_net_URLVariables
#include <nme/net/URLVariables.h>
#endif
namespace nme{
namespace net{

Void URLVariables_obj::__construct(::String inEncoded)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",6)
	if (((inEncoded != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",8)
		this->decode(inEncoded);
	}
}
;
	return null();
}

URLVariables_obj::~URLVariables_obj() { }

Dynamic URLVariables_obj::__CreateEmpty() { return  new URLVariables_obj; }
hx::ObjectPtr< URLVariables_obj > URLVariables_obj::__new(::String inEncoded)
{  hx::ObjectPtr< URLVariables_obj > result = new URLVariables_obj();
	result->__construct(inEncoded);
	return result;}

Dynamic URLVariables_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLVariables_obj > result = new URLVariables_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLVariables_obj::decode( ::String inVars){
{
		HX_SOURCE_PUSH("URLVariables_obj::decode")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",13)
		Array< ::String > fields = ::Reflect_obj::fields(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",14)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",14)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",14)
			while(((_g < fields->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",14)
				::String f = fields->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",14)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",15)
				::Reflect_obj::deleteField(hx::ObjectPtr<OBJ_>(this),f);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",16)
		Array< ::String > fields1 = inVars.split(HX_CSTRING(";"))->join(HX_CSTRING("&")).split(HX_CSTRING("&"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",17)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",17)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",17)
			while(((_g < fields1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",17)
				::String f = fields1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",17)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",19)
				int eq = f.indexOf(HX_CSTRING("="),null());
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",20)
				if (((eq > (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",21)
					if (((hx::ObjectPtr<OBJ_>(this) != null()))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",21)
						this->__SetField(::StringTools_obj::urlDecode(f.substr((int)0,eq)),::StringTools_obj::urlDecode(f.substr((eq + (int)1),null())));
					}
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",23)
					if (((eq != (int)0))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",24)
						if (((hx::ObjectPtr<OBJ_>(this) != null()))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",24)
							this->__SetField(::StringTools_obj::urlDecode(f),HX_CSTRING(""));
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLVariables_obj,decode,(void))

::String URLVariables_obj::toString( ){
	HX_SOURCE_PUSH("URLVariables_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",30)
	Array< ::String > result = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",31)
	Array< ::String > fields = ::Reflect_obj::fields(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",32)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",32)
		int _g = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",32)
		while(((_g < fields->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",32)
			::String f = fields->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",32)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",33)
			result->push(((::StringTools_obj::urlEncode(f) + HX_CSTRING("=")) + ::StringTools_obj::urlEncode(::Reflect_obj::field(hx::ObjectPtr<OBJ_>(this),f))));
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLVariables.hx",35)
	return result->join(HX_CSTRING("&"));
}


HX_DEFINE_DYNAMIC_FUNC0(URLVariables_obj,toString,return )


URLVariables_obj::URLVariables_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void URLVariables_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLVariables);
	HX_MARK_DYNAMIC;
	HX_MARK_END_CLASS();
}

Dynamic URLVariables_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"decode") ) { return decode_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	HX_CHECK_DYNAMIC_GET_FIELD(inName);
	return super::__Field(inName);
}

Dynamic URLVariables_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void URLVariables_obj::__GetFields(Array< ::String> &outFields)
{
	HX_APPEND_DYNAMIC_FIELDS(outFields);
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("decode"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class URLVariables_obj::__mClass;

void URLVariables_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.net.URLVariables"), hx::TCanCast< URLVariables_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLVariables_obj::__boot()
{
}

} // end namespace nme
} // end namespace net
