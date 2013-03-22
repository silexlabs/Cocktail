#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_cocktail_core_url_URL
#include <cocktail/core/url/URL.h>
#endif
namespace cocktail{
namespace core{
namespace url{

Void URL_obj::__construct()
{
HX_STACK_PUSH("URL::new","cocktail/core/url/URL.hx",52);
{
}
;
	return null();
}

URL_obj::~URL_obj() { }

Dynamic URL_obj::__CreateEmpty() { return  new URL_obj; }
hx::ObjectPtr< URL_obj > URL_obj::__new()
{  hx::ObjectPtr< URL_obj > result = new URL_obj();
	result->__construct();
	return result;}

Dynamic URL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URL_obj > result = new URL_obj();
	result->__construct();
	return result;}

Array< ::String > URL_obj::_parts;

::cocktail::core::url::URL URL_obj::fromString( ::String url){
	HX_STACK_PUSH("URL::fromString","cocktail/core/url/URL.hx",64);
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(66)
	::EReg r = ::EReg_obj::__new(HX_CSTRING("^(?:(?![^:@]+:[^:@/]*@)([^:/?#.]+):)?(?://)?((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:/?#]*)(?::(\\d*))?)(((/(?:[^?#](?![^?#/]*\\.[^?#/.]+(?:[?#]|$)))*/?)?([^?#/]*))(?:\\?([^#]*))?(?:#(.*))?)"),HX_CSTRING(""));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(69)
	r->match(url);
	HX_STACK_LINE(71)
	::cocktail::core::url::URL url1 = ::cocktail::core::url::URL_obj::__new();		HX_STACK_VAR(url1,"url1");
	HX_STACK_LINE(74)
	{
		HX_STACK_LINE(74)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::cocktail::core::url::URL_obj::_parts->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(74)
		while(((_g1 < _g))){
			HX_STACK_LINE(74)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(76)
			if (((url1 != null()))){
				HX_STACK_LINE(76)
				url1->__SetField(::cocktail::core::url::URL_obj::_parts->__get(i),r->matched(i),false);
			}
		}
	}
	HX_STACK_LINE(79)
	return url1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(URL_obj,fromString,return )

::String URL_obj::toString( ::cocktail::core::url::URL url){
	HX_STACK_PUSH("URL::toString","cocktail/core/url/URL.hx",87);
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(88)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(90)
	if (((url->scheme != null()))){
		HX_STACK_LINE(91)
		hx::AddEq(result,(url->scheme + HX_CSTRING("://")));
	}
	HX_STACK_LINE(95)
	if (((url->user != null()))){
		HX_STACK_LINE(96)
		hx::AddEq(result,(url->user + HX_CSTRING(":")));
	}
	HX_STACK_LINE(100)
	if (((url->password != null()))){
		HX_STACK_LINE(101)
		hx::AddEq(result,(url->password + HX_CSTRING("@")));
	}
	HX_STACK_LINE(105)
	if (((url->host != null()))){
		HX_STACK_LINE(106)
		hx::AddEq(result,url->host);
	}
	HX_STACK_LINE(110)
	if (((url->port != null()))){
		HX_STACK_LINE(111)
		hx::AddEq(result,(HX_CSTRING(":") + url->port));
	}
	HX_STACK_LINE(115)
	if (((url->path != null()))){
		HX_STACK_LINE(116)
		hx::AddEq(result,url->path);
	}
	HX_STACK_LINE(120)
	if (((url->query != null()))){
		HX_STACK_LINE(121)
		hx::AddEq(result,(HX_CSTRING("?") + url->query));
	}
	HX_STACK_LINE(125)
	if (((url->fragment != null()))){
		HX_STACK_LINE(126)
		hx::AddEq(result,(HX_CSTRING("#") + url->fragment));
	}
	HX_STACK_LINE(130)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(URL_obj,toString,return )


URL_obj::URL_obj()
{
}

void URL_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URL);
	HX_MARK_MEMBER_NAME(fragment,"fragment");
	HX_MARK_MEMBER_NAME(query,"query");
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(directory,"directory");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(relative,"relative");
	HX_MARK_MEMBER_NAME(port,"port");
	HX_MARK_MEMBER_NAME(host,"host");
	HX_MARK_MEMBER_NAME(password,"password");
	HX_MARK_MEMBER_NAME(user,"user");
	HX_MARK_MEMBER_NAME(userInfo,"userInfo");
	HX_MARK_MEMBER_NAME(authority,"authority");
	HX_MARK_MEMBER_NAME(scheme,"scheme");
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_END_CLASS();
}

void URL_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fragment,"fragment");
	HX_VISIT_MEMBER_NAME(query,"query");
	HX_VISIT_MEMBER_NAME(file,"file");
	HX_VISIT_MEMBER_NAME(directory,"directory");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(relative,"relative");
	HX_VISIT_MEMBER_NAME(port,"port");
	HX_VISIT_MEMBER_NAME(host,"host");
	HX_VISIT_MEMBER_NAME(password,"password");
	HX_VISIT_MEMBER_NAME(user,"user");
	HX_VISIT_MEMBER_NAME(userInfo,"userInfo");
	HX_VISIT_MEMBER_NAME(authority,"authority");
	HX_VISIT_MEMBER_NAME(scheme,"scheme");
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(url,"url");
}

Dynamic URL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return file; }
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		if (HX_FIELD_EQ(inName,"port") ) { return port; }
		if (HX_FIELD_EQ(inName,"host") ) { return host; }
		if (HX_FIELD_EQ(inName,"user") ) { return user; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"query") ) { return query; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_parts") ) { return _parts; }
		if (HX_FIELD_EQ(inName,"scheme") ) { return scheme; }
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"fragment") ) { return fragment; }
		if (HX_FIELD_EQ(inName,"relative") ) { return relative; }
		if (HX_FIELD_EQ(inName,"password") ) { return password; }
		if (HX_FIELD_EQ(inName,"userInfo") ) { return userInfo; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { return directory; }
		if (HX_FIELD_EQ(inName,"authority") ) { return authority; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic URL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"port") ) { port=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"host") ) { host=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"user") ) { user=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"query") ) { query=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_parts") ) { _parts=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scheme") ) { scheme=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fragment") ) { fragment=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"relative") ) { relative=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"password") ) { password=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userInfo") ) { userInfo=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { directory=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"authority") ) { authority=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void URL_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fragment"));
	outFields->push(HX_CSTRING("query"));
	outFields->push(HX_CSTRING("file"));
	outFields->push(HX_CSTRING("directory"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("relative"));
	outFields->push(HX_CSTRING("port"));
	outFields->push(HX_CSTRING("host"));
	outFields->push(HX_CSTRING("password"));
	outFields->push(HX_CSTRING("user"));
	outFields->push(HX_CSTRING("userInfo"));
	outFields->push(HX_CSTRING("authority"));
	outFields->push(HX_CSTRING("scheme"));
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("url"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_parts"),
	HX_CSTRING("fromString"),
	HX_CSTRING("toString"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("fragment"),
	HX_CSTRING("query"),
	HX_CSTRING("file"),
	HX_CSTRING("directory"),
	HX_CSTRING("path"),
	HX_CSTRING("relative"),
	HX_CSTRING("port"),
	HX_CSTRING("host"),
	HX_CSTRING("password"),
	HX_CSTRING("user"),
	HX_CSTRING("userInfo"),
	HX_CSTRING("authority"),
	HX_CSTRING("scheme"),
	HX_CSTRING("source"),
	HX_CSTRING("url"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URL_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(URL_obj::_parts,"_parts");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(URL_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(URL_obj::_parts,"_parts");
};

Class URL_obj::__mClass;

void URL_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.url.URL"), hx::TCanCast< URL_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void URL_obj::__boot()
{
	_parts= Array_obj< ::String >::__new().Add(HX_CSTRING("source")).Add(HX_CSTRING("scheme")).Add(HX_CSTRING("authority")).Add(HX_CSTRING("userInfo")).Add(HX_CSTRING("user")).Add(HX_CSTRING("password")).Add(HX_CSTRING("host")).Add(HX_CSTRING("port")).Add(HX_CSTRING("relative")).Add(HX_CSTRING("path")).Add(HX_CSTRING("directory")).Add(HX_CSTRING("file")).Add(HX_CSTRING("query")).Add(HX_CSTRING("fragment"));
}

} // end namespace cocktail
} // end namespace core
} // end namespace url
