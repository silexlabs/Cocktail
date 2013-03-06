#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_http_HTTPConstants
#include <cocktail/core/http/HTTPConstants.h>
#endif
namespace cocktail{
namespace core{
namespace http{

Void HTTPConstants_obj::__construct()
{
HX_STACK_PUSH("HTTPConstants::new","cocktail/core/http/HTTPConstants.hx",134);
{
}
;
	return null();
}

HTTPConstants_obj::~HTTPConstants_obj() { }

Dynamic HTTPConstants_obj::__CreateEmpty() { return  new HTTPConstants_obj; }
hx::ObjectPtr< HTTPConstants_obj > HTTPConstants_obj::__new()
{  hx::ObjectPtr< HTTPConstants_obj > result = new HTTPConstants_obj();
	result->__construct();
	return result;}

Dynamic HTTPConstants_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPConstants_obj > result = new HTTPConstants_obj();
	result->__construct();
	return result;}

int HTTPConstants_obj::UNSENT;

int HTTPConstants_obj::OPENED;

int HTTPConstants_obj::HEADERS_RECEIVED;

int HTTPConstants_obj::LOADING;

int HTTPConstants_obj::DONE;

::String HTTPConstants_obj::CONNECT;

::String HTTPConstants_obj::DELETE;

::String HTTPConstants_obj::GET;

::String HTTPConstants_obj::HEAD;

::String HTTPConstants_obj::OPTIONS;

::String HTTPConstants_obj::POST;

::String HTTPConstants_obj::PUT;

::String HTTPConstants_obj::TRACE;

::String HTTPConstants_obj::TRACK;

::String HTTPConstants_obj::TYPE_TEXT;

::String HTTPConstants_obj::TYPE_ARRAY_BUFFER;

::String HTTPConstants_obj::TYPE_BLOB;

::String HTTPConstants_obj::TYPE_DOCUMENT;

::String HTTPConstants_obj::TYPE_JSON;

::String HTTPConstants_obj::ACCEPT_CHARSET;

::String HTTPConstants_obj::ACCEPT_ENCODING;

::String HTTPConstants_obj::ACCESS_CONTROL_REQUEST_HEADERS;

::String HTTPConstants_obj::ACCESS_CONTROL_REQUEST_METHOD;

::String HTTPConstants_obj::CONNECTION;

::String HTTPConstants_obj::CONTENT_LENGTH;

::String HTTPConstants_obj::COOKIE;

::String HTTPConstants_obj::COOKIE_2;

::String HTTPConstants_obj::CONTENT_TRANSFER_ENCODING;

::String HTTPConstants_obj::DATE;

::String HTTPConstants_obj::EXPECT;

::String HTTPConstants_obj::HOST;

::String HTTPConstants_obj::KEEP_ALIVE;

::String HTTPConstants_obj::ORIGIN;

::String HTTPConstants_obj::REFERER;

::String HTTPConstants_obj::TE;

::String HTTPConstants_obj::TRAILER;

::String HTTPConstants_obj::TRANSFER_ENCODING;

::String HTTPConstants_obj::UPGRADE;

::String HTTPConstants_obj::USER_AGENT;

::String HTTPConstants_obj::VIA;

::String HTTPConstants_obj::PROXY;

::String HTTPConstants_obj::SEC;


HTTPConstants_obj::HTTPConstants_obj()
{
}

void HTTPConstants_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPConstants);
	HX_MARK_END_CLASS();
}

void HTTPConstants_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic HTTPConstants_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"TE") ) { return TE; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"GET") ) { return GET; }
		if (HX_FIELD_EQ(inName,"PUT") ) { return PUT; }
		if (HX_FIELD_EQ(inName,"VIA") ) { return VIA; }
		if (HX_FIELD_EQ(inName,"SEC") ) { return SEC; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"DONE") ) { return DONE; }
		if (HX_FIELD_EQ(inName,"HEAD") ) { return HEAD; }
		if (HX_FIELD_EQ(inName,"POST") ) { return POST; }
		if (HX_FIELD_EQ(inName,"DATE") ) { return DATE; }
		if (HX_FIELD_EQ(inName,"HOST") ) { return HOST; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"TRACE") ) { return TRACE; }
		if (HX_FIELD_EQ(inName,"TRACK") ) { return TRACK; }
		if (HX_FIELD_EQ(inName,"PROXY") ) { return PROXY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"UNSENT") ) { return UNSENT; }
		if (HX_FIELD_EQ(inName,"OPENED") ) { return OPENED; }
		if (HX_FIELD_EQ(inName,"DELETE") ) { return DELETE; }
		if (HX_FIELD_EQ(inName,"COOKIE") ) { return COOKIE; }
		if (HX_FIELD_EQ(inName,"EXPECT") ) { return EXPECT; }
		if (HX_FIELD_EQ(inName,"ORIGIN") ) { return ORIGIN; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"LOADING") ) { return LOADING; }
		if (HX_FIELD_EQ(inName,"CONNECT") ) { return CONNECT; }
		if (HX_FIELD_EQ(inName,"OPTIONS") ) { return OPTIONS; }
		if (HX_FIELD_EQ(inName,"REFERER") ) { return REFERER; }
		if (HX_FIELD_EQ(inName,"TRAILER") ) { return TRAILER; }
		if (HX_FIELD_EQ(inName,"UPGRADE") ) { return UPGRADE; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"COOKIE_2") ) { return COOKIE_2; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TYPE_TEXT") ) { return TYPE_TEXT; }
		if (HX_FIELD_EQ(inName,"TYPE_BLOB") ) { return TYPE_BLOB; }
		if (HX_FIELD_EQ(inName,"TYPE_JSON") ) { return TYPE_JSON; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"CONNECTION") ) { return CONNECTION; }
		if (HX_FIELD_EQ(inName,"KEEP_ALIVE") ) { return KEEP_ALIVE; }
		if (HX_FIELD_EQ(inName,"USER_AGENT") ) { return USER_AGENT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TYPE_DOCUMENT") ) { return TYPE_DOCUMENT; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ACCEPT_CHARSET") ) { return ACCEPT_CHARSET; }
		if (HX_FIELD_EQ(inName,"CONTENT_LENGTH") ) { return CONTENT_LENGTH; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ACCEPT_ENCODING") ) { return ACCEPT_ENCODING; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"HEADERS_RECEIVED") ) { return HEADERS_RECEIVED; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TYPE_ARRAY_BUFFER") ) { return TYPE_ARRAY_BUFFER; }
		if (HX_FIELD_EQ(inName,"TRANSFER_ENCODING") ) { return TRANSFER_ENCODING; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"CONTENT_TRANSFER_ENCODING") ) { return CONTENT_TRANSFER_ENCODING; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"ACCESS_CONTROL_REQUEST_METHOD") ) { return ACCESS_CONTROL_REQUEST_METHOD; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"ACCESS_CONTROL_REQUEST_HEADERS") ) { return ACCESS_CONTROL_REQUEST_HEADERS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPConstants_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"TE") ) { TE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"GET") ) { GET=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PUT") ) { PUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"VIA") ) { VIA=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SEC") ) { SEC=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"DONE") ) { DONE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HEAD") ) { HEAD=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POST") ) { POST=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DATE") ) { DATE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HOST") ) { HOST=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"TRACE") ) { TRACE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRACK") ) { TRACK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PROXY") ) { PROXY=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"UNSENT") ) { UNSENT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OPENED") ) { OPENED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DELETE") ) { DELETE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COOKIE") ) { COOKIE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"EXPECT") ) { EXPECT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ORIGIN") ) { ORIGIN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"LOADING") ) { LOADING=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CONNECT") ) { CONNECT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OPTIONS") ) { OPTIONS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"REFERER") ) { REFERER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRAILER") ) { TRAILER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"UPGRADE") ) { UPGRADE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"COOKIE_2") ) { COOKIE_2=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TYPE_TEXT") ) { TYPE_TEXT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TYPE_BLOB") ) { TYPE_BLOB=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TYPE_JSON") ) { TYPE_JSON=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"CONNECTION") ) { CONNECTION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KEEP_ALIVE") ) { KEEP_ALIVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"USER_AGENT") ) { USER_AGENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TYPE_DOCUMENT") ) { TYPE_DOCUMENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ACCEPT_CHARSET") ) { ACCEPT_CHARSET=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CONTENT_LENGTH") ) { CONTENT_LENGTH=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ACCEPT_ENCODING") ) { ACCEPT_ENCODING=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"HEADERS_RECEIVED") ) { HEADERS_RECEIVED=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TYPE_ARRAY_BUFFER") ) { TYPE_ARRAY_BUFFER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRANSFER_ENCODING") ) { TRANSFER_ENCODING=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"CONTENT_TRANSFER_ENCODING") ) { CONTENT_TRANSFER_ENCODING=inValue.Cast< ::String >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"ACCESS_CONTROL_REQUEST_METHOD") ) { ACCESS_CONTROL_REQUEST_METHOD=inValue.Cast< ::String >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"ACCESS_CONTROL_REQUEST_HEADERS") ) { ACCESS_CONTROL_REQUEST_HEADERS=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPConstants_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UNSENT"),
	HX_CSTRING("OPENED"),
	HX_CSTRING("HEADERS_RECEIVED"),
	HX_CSTRING("LOADING"),
	HX_CSTRING("DONE"),
	HX_CSTRING("CONNECT"),
	HX_CSTRING("DELETE"),
	HX_CSTRING("GET"),
	HX_CSTRING("HEAD"),
	HX_CSTRING("OPTIONS"),
	HX_CSTRING("POST"),
	HX_CSTRING("PUT"),
	HX_CSTRING("TRACE"),
	HX_CSTRING("TRACK"),
	HX_CSTRING("TYPE_TEXT"),
	HX_CSTRING("TYPE_ARRAY_BUFFER"),
	HX_CSTRING("TYPE_BLOB"),
	HX_CSTRING("TYPE_DOCUMENT"),
	HX_CSTRING("TYPE_JSON"),
	HX_CSTRING("ACCEPT_CHARSET"),
	HX_CSTRING("ACCEPT_ENCODING"),
	HX_CSTRING("ACCESS_CONTROL_REQUEST_HEADERS"),
	HX_CSTRING("ACCESS_CONTROL_REQUEST_METHOD"),
	HX_CSTRING("CONNECTION"),
	HX_CSTRING("CONTENT_LENGTH"),
	HX_CSTRING("COOKIE"),
	HX_CSTRING("COOKIE_2"),
	HX_CSTRING("CONTENT_TRANSFER_ENCODING"),
	HX_CSTRING("DATE"),
	HX_CSTRING("EXPECT"),
	HX_CSTRING("HOST"),
	HX_CSTRING("KEEP_ALIVE"),
	HX_CSTRING("ORIGIN"),
	HX_CSTRING("REFERER"),
	HX_CSTRING("TE"),
	HX_CSTRING("TRAILER"),
	HX_CSTRING("TRANSFER_ENCODING"),
	HX_CSTRING("UPGRADE"),
	HX_CSTRING("USER_AGENT"),
	HX_CSTRING("VIA"),
	HX_CSTRING("PROXY"),
	HX_CSTRING("SEC"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::UNSENT,"UNSENT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::OPENED,"OPENED");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::HEADERS_RECEIVED,"HEADERS_RECEIVED");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::LOADING,"LOADING");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::DONE,"DONE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::CONNECT,"CONNECT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::DELETE,"DELETE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::GET,"GET");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::HEAD,"HEAD");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::OPTIONS,"OPTIONS");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::POST,"POST");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::PUT,"PUT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TRACE,"TRACE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TRACK,"TRACK");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TYPE_TEXT,"TYPE_TEXT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TYPE_ARRAY_BUFFER,"TYPE_ARRAY_BUFFER");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TYPE_BLOB,"TYPE_BLOB");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TYPE_DOCUMENT,"TYPE_DOCUMENT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TYPE_JSON,"TYPE_JSON");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::ACCEPT_CHARSET,"ACCEPT_CHARSET");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::ACCEPT_ENCODING,"ACCEPT_ENCODING");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::ACCESS_CONTROL_REQUEST_HEADERS,"ACCESS_CONTROL_REQUEST_HEADERS");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::ACCESS_CONTROL_REQUEST_METHOD,"ACCESS_CONTROL_REQUEST_METHOD");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::CONNECTION,"CONNECTION");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::CONTENT_LENGTH,"CONTENT_LENGTH");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::COOKIE,"COOKIE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::COOKIE_2,"COOKIE_2");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::CONTENT_TRANSFER_ENCODING,"CONTENT_TRANSFER_ENCODING");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::DATE,"DATE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::EXPECT,"EXPECT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::HOST,"HOST");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::KEEP_ALIVE,"KEEP_ALIVE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::ORIGIN,"ORIGIN");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::REFERER,"REFERER");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TE,"TE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TRAILER,"TRAILER");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::TRANSFER_ENCODING,"TRANSFER_ENCODING");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::UPGRADE,"UPGRADE");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::USER_AGENT,"USER_AGENT");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::VIA,"VIA");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::PROXY,"PROXY");
	HX_MARK_MEMBER_NAME(HTTPConstants_obj::SEC,"SEC");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::UNSENT,"UNSENT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::OPENED,"OPENED");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::HEADERS_RECEIVED,"HEADERS_RECEIVED");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::LOADING,"LOADING");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::DONE,"DONE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::CONNECT,"CONNECT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::DELETE,"DELETE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::GET,"GET");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::HEAD,"HEAD");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::OPTIONS,"OPTIONS");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::POST,"POST");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::PUT,"PUT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TRACE,"TRACE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TRACK,"TRACK");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TYPE_TEXT,"TYPE_TEXT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TYPE_ARRAY_BUFFER,"TYPE_ARRAY_BUFFER");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TYPE_BLOB,"TYPE_BLOB");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TYPE_DOCUMENT,"TYPE_DOCUMENT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TYPE_JSON,"TYPE_JSON");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::ACCEPT_CHARSET,"ACCEPT_CHARSET");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::ACCEPT_ENCODING,"ACCEPT_ENCODING");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::ACCESS_CONTROL_REQUEST_HEADERS,"ACCESS_CONTROL_REQUEST_HEADERS");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::ACCESS_CONTROL_REQUEST_METHOD,"ACCESS_CONTROL_REQUEST_METHOD");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::CONNECTION,"CONNECTION");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::CONTENT_LENGTH,"CONTENT_LENGTH");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::COOKIE,"COOKIE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::COOKIE_2,"COOKIE_2");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::CONTENT_TRANSFER_ENCODING,"CONTENT_TRANSFER_ENCODING");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::DATE,"DATE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::EXPECT,"EXPECT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::HOST,"HOST");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::KEEP_ALIVE,"KEEP_ALIVE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::ORIGIN,"ORIGIN");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::REFERER,"REFERER");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TE,"TE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TRAILER,"TRAILER");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::TRANSFER_ENCODING,"TRANSFER_ENCODING");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::UPGRADE,"UPGRADE");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::USER_AGENT,"USER_AGENT");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::VIA,"VIA");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::PROXY,"PROXY");
	HX_VISIT_MEMBER_NAME(HTTPConstants_obj::SEC,"SEC");
};

Class HTTPConstants_obj::__mClass;

void HTTPConstants_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.http.HTTPConstants"), hx::TCanCast< HTTPConstants_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTTPConstants_obj::__boot()
{
	UNSENT= (int)0;
	OPENED= (int)1;
	HEADERS_RECEIVED= (int)2;
	LOADING= (int)3;
	DONE= (int)4;
	CONNECT= HX_CSTRING("CONNECT");
	DELETE= HX_CSTRING("DELETE");
	GET= HX_CSTRING("GET");
	HEAD= HX_CSTRING("HEAD");
	OPTIONS= HX_CSTRING("OPTIONS");
	POST= HX_CSTRING("POST");
	PUT= HX_CSTRING("PUT");
	TRACE= HX_CSTRING("TRACE");
	TRACK= HX_CSTRING("TRACK");
	TYPE_TEXT= HX_CSTRING("text");
	TYPE_ARRAY_BUFFER= HX_CSTRING("arraybuffer");
	TYPE_BLOB= HX_CSTRING("blob");
	TYPE_DOCUMENT= HX_CSTRING("document");
	TYPE_JSON= HX_CSTRING("json");
	ACCEPT_CHARSET= HX_CSTRING("accept-charset");
	ACCEPT_ENCODING= HX_CSTRING("accept-encoding");
	ACCESS_CONTROL_REQUEST_HEADERS= HX_CSTRING("access-control-request-headers");
	ACCESS_CONTROL_REQUEST_METHOD= HX_CSTRING("access-control-request-method");
	CONNECTION= HX_CSTRING("connection");
	CONTENT_LENGTH= HX_CSTRING("content-length");
	COOKIE= HX_CSTRING("cookie");
	COOKIE_2= HX_CSTRING("cookie2");
	CONTENT_TRANSFER_ENCODING= HX_CSTRING("content-transfer-encoding");
	DATE= HX_CSTRING("date");
	EXPECT= HX_CSTRING("expect");
	HOST= HX_CSTRING("host");
	KEEP_ALIVE= HX_CSTRING("keep-alive");
	ORIGIN= HX_CSTRING("origin");
	REFERER= HX_CSTRING("referer");
	TE= HX_CSTRING("te");
	TRAILER= HX_CSTRING("trailer");
	TRANSFER_ENCODING= HX_CSTRING("transfer-encoding");
	UPGRADE= HX_CSTRING("upgrade");
	USER_AGENT= HX_CSTRING("user-agent");
	VIA= HX_CSTRING("via");
	PROXY= HX_CSTRING("proxy-");
	SEC= HX_CSTRING("sec-");
}

} // end namespace cocktail
} // end namespace core
} // end namespace http
