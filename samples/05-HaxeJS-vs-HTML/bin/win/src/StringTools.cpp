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
	HX_STACK_PUSH("StringTools::urlEncode","C:\\Motion-Twin\\Haxe/std/StringTools.hx",41);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(41)
	return s.__URLEncode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlEncode,return )

::String StringTools_obj::urlDecode( ::String s){
	HX_STACK_PUSH("StringTools::urlDecode","C:\\Motion-Twin\\Haxe/std/StringTools.hx",68);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(68)
	return s.__URLDecode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlDecode,return )

::String StringTools_obj::htmlEscape( ::String s){
	HX_STACK_PUSH("StringTools::htmlEscape","C:\\Motion-Twin\\Haxe/std/StringTools.hx",95);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(95)
	return s.split(HX_CSTRING("&"))->join(HX_CSTRING("&amp;")).split(HX_CSTRING("<"))->join(HX_CSTRING("&lt;")).split(HX_CSTRING(">"))->join(HX_CSTRING("&gt;"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlEscape,return )

::String StringTools_obj::htmlUnescape( ::String s){
	HX_STACK_PUSH("StringTools::htmlUnescape","C:\\Motion-Twin\\Haxe/std/StringTools.hx",102);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(102)
	return s.split(HX_CSTRING("&gt;"))->join(HX_CSTRING(">")).split(HX_CSTRING("&lt;"))->join(HX_CSTRING("<")).split(HX_CSTRING("&amp;"))->join(HX_CSTRING("&"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlUnescape,return )

bool StringTools_obj::startsWith( ::String s,::String start){
	HX_STACK_PUSH("StringTools::startsWith","C:\\Motion-Twin\\Haxe/std/StringTools.hx",113);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(start,"start");
	HX_STACK_LINE(113)
	return (bool((s.length >= start.length)) && bool((s.substr((int)0,start.length) == start)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,startsWith,return )

bool StringTools_obj::endsWith( ::String s,::String end){
	HX_STACK_PUSH("StringTools::endsWith","C:\\Motion-Twin\\Haxe/std/StringTools.hx",126);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(end,"end");
	HX_STACK_LINE(132)
	int elen = end.length;		HX_STACK_VAR(elen,"elen");
	HX_STACK_LINE(133)
	int slen = s.length;		HX_STACK_VAR(slen,"slen");
	HX_STACK_LINE(134)
	return (bool((slen >= elen)) && bool((s.substr((slen - elen),elen) == end)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,endsWith,return )

bool StringTools_obj::isSpace( ::String s,int pos){
	HX_STACK_PUSH("StringTools::isSpace","C:\\Motion-Twin\\Haxe/std/StringTools.hx",141);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(142)
	Dynamic c = s.charCodeAt(pos);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(143)
	return (bool((bool((c >= (int)9)) && bool((c <= (int)13)))) || bool((c == (int)32)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,isSpace,return )

::String StringTools_obj::ltrim( ::String s){
	HX_STACK_PUSH("StringTools::ltrim","C:\\Motion-Twin\\Haxe/std/StringTools.hx",149);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(155)
	int l = s.length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(156)
	int r = (int)0;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(157)
	while(((bool((r < l)) && bool(::StringTools_obj::isSpace(s,r))))){
		HX_STACK_LINE(157)
		(r)++;
	}
	HX_STACK_LINE(160)
	if (((r > (int)0))){
		HX_STACK_LINE(161)
		return s.substr(r,(l - r));
	}
	else{
		HX_STACK_LINE(163)
		return s;
	}
	HX_STACK_LINE(160)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,ltrim,return )

::String StringTools_obj::rtrim( ::String s){
	HX_STACK_PUSH("StringTools::rtrim","C:\\Motion-Twin\\Haxe/std/StringTools.hx",170);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(176)
	int l = s.length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(177)
	int r = (int)0;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(178)
	while(((bool((r < l)) && bool(::StringTools_obj::isSpace(s,((l - r) - (int)1)))))){
		HX_STACK_LINE(178)
		(r)++;
	}
	HX_STACK_LINE(181)
	if (((r > (int)0))){
		HX_STACK_LINE(181)
		return s.substr((int)0,(l - r));
	}
	else{
		HX_STACK_LINE(183)
		return s;
	}
	HX_STACK_LINE(181)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,rtrim,return )

::String StringTools_obj::trim( ::String s){
	HX_STACK_PUSH("StringTools::trim","C:\\Motion-Twin\\Haxe/std/StringTools.hx",192);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(192)
	return ::StringTools_obj::ltrim(::StringTools_obj::rtrim(s));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,trim,return )

::String StringTools_obj::rpad( ::String s,::String c,int l){
	HX_STACK_PUSH("StringTools::rpad","C:\\Motion-Twin\\Haxe/std/StringTools.hx",207);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(l,"l");
	HX_STACK_LINE(211)
	int sl = s.length;		HX_STACK_VAR(sl,"sl");
	HX_STACK_LINE(212)
	int cl = c.length;		HX_STACK_VAR(cl,"cl");
	HX_STACK_LINE(213)
	while(((sl < l))){
		HX_STACK_LINE(213)
		if ((((l - sl) < cl))){
			HX_STACK_LINE(215)
			hx::AddEq(s,c.substr((int)0,(l - sl)));
			HX_STACK_LINE(216)
			sl = l;
		}
		else{
			HX_STACK_LINE(218)
			hx::AddEq(s,c);
			HX_STACK_LINE(219)
			hx::AddEq(sl,cl);
		}
	}
	HX_STACK_LINE(222)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,rpad,return )

::String StringTools_obj::lpad( ::String s,::String c,int l){
	HX_STACK_PUSH("StringTools::lpad","C:\\Motion-Twin\\Haxe/std/StringTools.hx",229);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(l,"l");
	HX_STACK_LINE(233)
	::String ns = HX_CSTRING("");		HX_STACK_VAR(ns,"ns");
	HX_STACK_LINE(234)
	int sl = s.length;		HX_STACK_VAR(sl,"sl");
	HX_STACK_LINE(235)
	if (((sl >= l))){
		HX_STACK_LINE(235)
		return s;
	}
	HX_STACK_LINE(237)
	int cl = c.length;		HX_STACK_VAR(cl,"cl");
	HX_STACK_LINE(238)
	while(((sl < l))){
		HX_STACK_LINE(238)
		if ((((l - sl) < cl))){
			HX_STACK_LINE(240)
			hx::AddEq(ns,c.substr((int)0,(l - sl)));
			HX_STACK_LINE(241)
			sl = l;
		}
		else{
			HX_STACK_LINE(243)
			hx::AddEq(ns,c);
			HX_STACK_LINE(244)
			hx::AddEq(sl,cl);
		}
	}
	HX_STACK_LINE(247)
	return (ns + s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,lpad,return )

::String StringTools_obj::replace( ::String s,::String sub,::String by){
	HX_STACK_PUSH("StringTools::replace","C:\\Motion-Twin\\Haxe/std/StringTools.hx",254);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(sub,"sub");
	HX_STACK_ARG(by,"by");
	HX_STACK_LINE(254)
	return s.split(sub)->join(by);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,replace,return )

::String StringTools_obj::hex( int n,Dynamic digits){
	HX_STACK_PUSH("StringTools::hex","C:\\Motion-Twin\\Haxe/std/StringTools.hx",269);
	HX_STACK_ARG(n,"n");
	HX_STACK_ARG(digits,"digits");
	HX_STACK_LINE(275)
	::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(276)
	::String hexChars = HX_CSTRING("0123456789ABCDEF");		HX_STACK_VAR(hexChars,"hexChars");
	HX_STACK_LINE(277)
	do{
		HX_STACK_LINE(278)
		s = (hexChars.charAt((int(n) & int((int)15))) + s);
		HX_STACK_LINE(279)
		hx::UShrEq(n,(int)4);
	}
while(((n > (int)0)));
	HX_STACK_LINE(282)
	if (((digits != null()))){
		HX_STACK_LINE(283)
		while(((s.length < digits))){
			HX_STACK_LINE(284)
			s = (HX_CSTRING("0") + s);
		}
	}
	HX_STACK_LINE(285)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,hex,return )

int StringTools_obj::fastCodeAt( ::String s,int index){
	HX_STACK_PUSH("StringTools::fastCodeAt","C:\\Motion-Twin\\Haxe/std/StringTools.hx",292);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(292)
	return s.cca(index);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,fastCodeAt,return )

bool StringTools_obj::isEOF( int c){
	HX_STACK_PUSH("StringTools::isEOF","C:\\Motion-Twin\\Haxe/std/StringTools.hx",322);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(322)
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

void StringTools_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic StringTools_obj::__Field(const ::String &inName,bool inCallProp)
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
	return super::__Field(inName,inCallProp);
}

Dynamic StringTools_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_MARK_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

Class StringTools_obj::__mClass;

void StringTools_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringTools"), hx::TCanCast< StringTools_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StringTools_obj::__boot()
{
}

