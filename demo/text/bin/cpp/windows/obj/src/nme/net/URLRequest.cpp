#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_net_URLVariables
#include <nme/net/URLVariables.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace nme{
namespace net{

Void URLRequest_obj::__construct(::String inURL)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",33)
	if (((inURL != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",34)
		this->url = inURL;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",35)
	this->verbose = false;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",36)
	this->userPassword = HX_CSTRING("");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",37)
	this->cookieString = HX_CSTRING("");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",38)
	this->authType = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",39)
	this->contentType = HX_CSTRING("application/x-www-form-urlencoded");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",40)
	this->method = HX_CSTRING("GET");
}
;
	return null();
}

URLRequest_obj::~URLRequest_obj() { }

Dynamic URLRequest_obj::__CreateEmpty() { return  new URLRequest_obj; }
hx::ObjectPtr< URLRequest_obj > URLRequest_obj::__new(::String inURL)
{  hx::ObjectPtr< URLRequest_obj > result = new URLRequest_obj();
	result->__construct(inURL);
	return result;}

Dynamic URLRequest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLRequest_obj > result = new URLRequest_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLRequest_obj::basicAuth( ::String inUser,::String inPasswd){
{
		HX_SOURCE_PUSH("URLRequest_obj::basicAuth")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",46)
		this->authType = (int)1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",47)
		this->userPassword = ((inUser + HX_CSTRING(":")) + inPasswd);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(URLRequest_obj,basicAuth,(void))

Void URLRequest_obj::digestAuth( ::String inUser,::String inPasswd){
{
		HX_SOURCE_PUSH("URLRequest_obj::digestAuth")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",53)
		this->authType = (int)2;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",54)
		this->userPassword = ((inUser + HX_CSTRING(":")) + inPasswd);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(URLRequest_obj,digestAuth,(void))

Void URLRequest_obj::nmePrepare( ){
{
		HX_SOURCE_PUSH("URLRequest_obj::nmePrepare")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",62)
		if (((this->data == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",64)
			this->nmeBytes = null();
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",66)
			if ((::Std_obj::is(this->data,hx::ClassOf< ::nme::utils::ByteArray >()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",68)
				this->nmeBytes = this->data;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",69)
				if ((::Std_obj::is(this->data,hx::ClassOf< ::nme::net::URLVariables >()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",71)
					::nme::net::URLVariables vars = this->data;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",72)
					::String str = vars->toString();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",73)
					this->nmeBytes = ::nme::utils::ByteArray_obj::__new(null());
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",74)
					this->nmeBytes->writeUTFBytes(str);
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",76)
					if ((::Std_obj::is(this->data,hx::ClassOf< ::String >()))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",78)
						::String str = this->data;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",79)
						this->nmeBytes = ::nme::utils::ByteArray_obj::__new(null());
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",80)
						this->nmeBytes->writeUTFBytes(str);
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLRequest.hx",83)
						hx::Throw (HX_CSTRING("Unknown data type"));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLRequest_obj,nmePrepare,(void))

int URLRequest_obj::AUTH_BASIC;

int URLRequest_obj::AUTH_DIGEST;

int URLRequest_obj::AUTH_GSSNEGOTIATE;

int URLRequest_obj::AUTH_NTLM;

int URLRequest_obj::AUTH_DIGEST_IE;

int URLRequest_obj::AUTH_DIGEST_ANY;


URLRequest_obj::URLRequest_obj()
{
}

void URLRequest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLRequest);
	HX_MARK_MEMBER_NAME(authType,"authType");
	HX_MARK_MEMBER_NAME(cookieString,"cookieString");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(userPassword,"userPassword");
	HX_MARK_MEMBER_NAME(verbose,"verbose");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_MEMBER_NAME(contentType,"contentType");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(nmeBytes,"nmeBytes");
	HX_MARK_END_CLASS();
}

Dynamic URLRequest_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { return method; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { return verbose; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"authType") ) { return authType; }
		if (HX_FIELD_EQ(inName,"nmeBytes") ) { return nmeBytes; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AUTH_NTLM") ) { return AUTH_NTLM; }
		if (HX_FIELD_EQ(inName,"basicAuth") ) { return basicAuth_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"AUTH_BASIC") ) { return AUTH_BASIC; }
		if (HX_FIELD_EQ(inName,"digestAuth") ) { return digestAuth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmePrepare") ) { return nmePrepare_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST") ) { return AUTH_DIGEST; }
		if (HX_FIELD_EQ(inName,"contentType") ) { return contentType; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cookieString") ) { return cookieString; }
		if (HX_FIELD_EQ(inName,"userPassword") ) { return userPassword; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_IE") ) { return AUTH_DIGEST_IE; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_ANY") ) { return AUTH_DIGEST_ANY; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"AUTH_GSSNEGOTIATE") ) { return AUTH_GSSNEGOTIATE; }
	}
	return super::__Field(inName);
}

Dynamic URLRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { verbose=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"authType") ) { authType=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeBytes") ) { nmeBytes=inValue.Cast< ::nme::utils::ByteArray >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AUTH_NTLM") ) { AUTH_NTLM=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"AUTH_BASIC") ) { AUTH_BASIC=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST") ) { AUTH_DIGEST=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"contentType") ) { contentType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cookieString") ) { cookieString=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userPassword") ) { userPassword=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_IE") ) { AUTH_DIGEST_IE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_ANY") ) { AUTH_DIGEST_ANY=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"AUTH_GSSNEGOTIATE") ) { AUTH_GSSNEGOTIATE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void URLRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("authType"));
	outFields->push(HX_CSTRING("cookieString"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("userPassword"));
	outFields->push(HX_CSTRING("verbose"));
	outFields->push(HX_CSTRING("method"));
	outFields->push(HX_CSTRING("contentType"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("nmeBytes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("AUTH_BASIC"),
	HX_CSTRING("AUTH_DIGEST"),
	HX_CSTRING("AUTH_GSSNEGOTIATE"),
	HX_CSTRING("AUTH_NTLM"),
	HX_CSTRING("AUTH_DIGEST_IE"),
	HX_CSTRING("AUTH_DIGEST_ANY"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("authType"),
	HX_CSTRING("cookieString"),
	HX_CSTRING("url"),
	HX_CSTRING("userPassword"),
	HX_CSTRING("verbose"),
	HX_CSTRING("method"),
	HX_CSTRING("contentType"),
	HX_CSTRING("data"),
	HX_CSTRING("nmeBytes"),
	HX_CSTRING("basicAuth"),
	HX_CSTRING("digestAuth"),
	HX_CSTRING("nmePrepare"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_BASIC,"AUTH_BASIC");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST,"AUTH_DIGEST");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_GSSNEGOTIATE,"AUTH_GSSNEGOTIATE");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_NTLM,"AUTH_NTLM");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST_IE,"AUTH_DIGEST_IE");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST_ANY,"AUTH_DIGEST_ANY");
};

Class URLRequest_obj::__mClass;

void URLRequest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.net.URLRequest"), hx::TCanCast< URLRequest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLRequest_obj::__boot()
{
	hx::Static(AUTH_BASIC) = (int)1;
	hx::Static(AUTH_DIGEST) = (int)2;
	hx::Static(AUTH_GSSNEGOTIATE) = (int)4;
	hx::Static(AUTH_NTLM) = (int)8;
	hx::Static(AUTH_DIGEST_IE) = (int)16;
	hx::Static(AUTH_DIGEST_ANY) = (int)15;
}

} // end namespace nme
} // end namespace net
