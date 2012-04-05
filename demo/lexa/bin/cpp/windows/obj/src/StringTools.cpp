#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void StringTools_obj::__construct()
{
	return null();
}

StringTools_obj::~StringTools_obj() { }

Dynamic StringTools_obj::__CreateEmpty() { return  new StringTools_obj; }
hx::ObjectPtr< StringTools_obj > StringTools_obj::__new()
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

Dynamic StringTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

::String StringTools_obj::urlEncode( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::urlEncode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",38)
	return s.__URLEncode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlEncode,return )

::String StringTools_obj::urlDecode( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::urlDecode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",59)
	return s.__URLDecode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlDecode,return )

::String StringTools_obj::htmlEscape( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::htmlEscape")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",80)
	return s.split(HX_CSTRING("&"))->join(HX_CSTRING("&amp;")).split(HX_CSTRING("<"))->join(HX_CSTRING("&lt;")).split(HX_CSTRING(">"))->join(HX_CSTRING("&gt;"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlEscape,return )

::String StringTools_obj::htmlUnescape( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::htmlUnescape")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",87)
	return s.split(HX_CSTRING("&gt;"))->join(HX_CSTRING(">")).split(HX_CSTRING("&lt;"))->join(HX_CSTRING("<")).split(HX_CSTRING("&amp;"))->join(HX_CSTRING("&"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlUnescape,return )

bool StringTools_obj::startsWith( ::String s,::String start){
	HX_SOURCE_PUSH("StringTools_obj::startsWith")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",98)
	return (bool((s.length >= start.length)) && bool((s.substr((int)0,start.length) == start)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,startsWith,return )

bool StringTools_obj::endsWith( ::String s,::String end){
	HX_SOURCE_PUSH("StringTools_obj::endsWith")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",106)
	int elen = end.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",107)
	int slen = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",108)
	return (bool((slen >= elen)) && bool((s.substr((slen - elen),elen) == end)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,endsWith,return )

bool StringTools_obj::isSpace( ::String s,int pos){
	HX_SOURCE_PUSH("StringTools_obj::isSpace")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",115)
	Dynamic c = s.charCodeAt(pos);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",116)
	return (bool((bool((c >= (int)9)) && bool((c <= (int)13)))) || bool((c == (int)32)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,isSpace,return )

::String StringTools_obj::ltrim( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::ltrim")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",126)
	int l = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",127)
	int r = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",128)
	while(((bool((r < l)) && bool(::StringTools_obj::isSpace(s,r))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",128)
		(r)++;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",131)
	if (((r > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",132)
		return s.substr(r,(l - r));
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",134)
		return s;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,ltrim,return )

::String StringTools_obj::rtrim( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::rtrim")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",145)
	int l = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",146)
	int r = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",147)
	while(((bool((r < l)) && bool(::StringTools_obj::isSpace(s,((l - r) - (int)1)))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",147)
		(r)++;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",150)
	if (((r > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",150)
		return s.substr((int)0,(l - r));
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",152)
		return s;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,rtrim,return )

::String StringTools_obj::trim( ::String s){
	HX_SOURCE_PUSH("StringTools_obj::trim")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",161)
	return ::StringTools_obj::ltrim(::StringTools_obj::rtrim(s));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,trim,return )

::String StringTools_obj::rpad( ::String s,::String c,int l){
	HX_SOURCE_PUSH("StringTools_obj::rpad")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",176)
	int sl = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",177)
	int cl = c.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",178)
	while(((sl < l))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",178)
		if ((((l - sl) < cl))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",180)
			hx::AddEq(s,c.substr((int)0,(l - sl)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",181)
			sl = l;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",183)
			hx::AddEq(s,c);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",184)
			hx::AddEq(sl,cl);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",187)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,rpad,return )

::String StringTools_obj::lpad( ::String s,::String c,int l){
	HX_SOURCE_PUSH("StringTools_obj::lpad")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",198)
	::String ns = HX_CSTRING("");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",199)
	int sl = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",200)
	if (((sl >= l))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",200)
		return s;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",202)
	int cl = c.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",203)
	while(((sl < l))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",203)
		if ((((l - sl) < cl))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",205)
			hx::AddEq(ns,c.substr((int)0,(l - sl)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",206)
			sl = l;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",208)
			hx::AddEq(ns,c);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",209)
			hx::AddEq(sl,cl);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",212)
	return (ns + s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,lpad,return )

::String StringTools_obj::replace( ::String s,::String sub,::String by){
	HX_SOURCE_PUSH("StringTools_obj::replace")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",219)
	return s.split(sub)->join(by);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,replace,return )

::String StringTools_obj::hex( int n,Dynamic digits){
	HX_SOURCE_PUSH("StringTools_obj::hex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",236)
	::String s = HX_CSTRING("");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",237)
	::String hexChars = HX_CSTRING("0123456789ABCDEF");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",238)
	do{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",239)
		s = (hexChars.charAt((int(n) & int((int)15))) + s);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",240)
		hx::UShrEq(n,(int)4);
	}
while(((n > (int)0)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",243)
	if (((digits != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",244)
		while(((s.length < digits))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",245)
			s = (HX_CSTRING("0") + s);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",246)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,hex,return )

int StringTools_obj::fastCodeAt( ::String s,int index){
	HX_SOURCE_PUSH("StringTools_obj::fastCodeAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",253)
	return s.cca(index);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,fastCodeAt,return )

bool StringTools_obj::isEOF( int c){
	HX_SOURCE_PUSH("StringTools_obj::isEOF")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/StringTools.hx",270)
	return (c == (int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,isEOF,return )


StringTools_obj::StringTools_obj()
{
}

void StringTools_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringTools);
	HX_MARK_END_CLASS();
}

Dynamic StringTools_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hex") ) { return hex_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"trim") ) { return trim_dyn(); }
		if (HX_FIELD_EQ(inName,"rpad") ) { return rpad_dyn(); }
		if (HX_FIELD_EQ(inName,"lpad") ) { return lpad_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ltrim") ) { return ltrim_dyn(); }
		if (HX_FIELD_EQ(inName,"rtrim") ) { return rtrim_dyn(); }
		if (HX_FIELD_EQ(inName,"isEOF") ) { return isEOF_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"replace") ) { return replace_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"endsWith") ) { return endsWith_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"urlEncode") ) { return urlEncode_dyn(); }
		if (HX_FIELD_EQ(inName,"urlDecode") ) { return urlDecode_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"htmlEscape") ) { return htmlEscape_dyn(); }
		if (HX_FIELD_EQ(inName,"startsWith") ) { return startsWith_dyn(); }
		if (HX_FIELD_EQ(inName,"fastCodeAt") ) { return fastCodeAt_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"htmlUnescape") ) { return htmlUnescape_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StringTools_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void StringTools_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("urlEncode"),
	HX_CSTRING("urlDecode"),
	HX_CSTRING("htmlEscape"),
	HX_CSTRING("htmlUnescape"),
	HX_CSTRING("startsWith"),
	HX_CSTRING("endsWith"),
	HX_CSTRING("isSpace"),
	HX_CSTRING("ltrim"),
	HX_CSTRING("rtrim"),
	HX_CSTRING("trim"),
	HX_CSTRING("rpad"),
	HX_CSTRING("lpad"),
	HX_CSTRING("replace"),
	HX_CSTRING("hex"),
	HX_CSTRING("fastCodeAt"),
	HX_CSTRING("isEOF"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StringTools_obj::__mClass;

void StringTools_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringTools"), hx::TCanCast< StringTools_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StringTools_obj::__boot()
{
}

