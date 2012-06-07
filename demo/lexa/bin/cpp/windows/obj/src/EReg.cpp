#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void EReg_obj::__construct(::String r,::String opt)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",33)
	Array< ::String > a = opt.split(HX_CSTRING("g"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",34)
	this->global = (a->length > (int)1);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",35)
	if ((this->global)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",36)
		opt = a->join(HX_CSTRING(""));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",37)
	this->r = ::EReg_obj::regexp_new_options(r,opt);
}
;
	return null();
}

EReg_obj::~EReg_obj() { }

Dynamic EReg_obj::__CreateEmpty() { return  new EReg_obj; }
hx::ObjectPtr< EReg_obj > EReg_obj::__new(::String r,::String opt)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(r,opt);
	return result;}

Dynamic EReg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool EReg_obj::match( ::String s){
	HX_SOURCE_PUSH("EReg_obj::match")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",41)
	bool p = ::EReg_obj::regexp_match(this->r,s,(int)0,s.length);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",42)
	if ((p)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",43)
		this->last = s;
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",45)
		this->last = null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",46)
	return p;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,match,return )

::String EReg_obj::matched( int n){
	HX_SOURCE_PUSH("EReg_obj::matched")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",50)
	::String m = ::EReg_obj::regexp_matched(this->r,n);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",51)
	return m;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,matched,return )

::String EReg_obj::matchedLeft( ){
	HX_SOURCE_PUSH("EReg_obj::matchedLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",55)
	Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",56)
	return this->last.substr((int)0,p->__Field(HX_CSTRING("pos")));
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedLeft,return )

::String EReg_obj::matchedRight( ){
	HX_SOURCE_PUSH("EReg_obj::matchedRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",60)
	Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",61)
	int sz = (p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len")));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",62)
	return this->last.substr(sz,(this->last.length - sz));
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedRight,return )

Dynamic EReg_obj::matchedPos( ){
	HX_SOURCE_PUSH("EReg_obj::matchedPos")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",65)
	return ::EReg_obj::regexp_matched_pos(this->r,(int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedPos,return )

Array< ::String > EReg_obj::split( ::String s){
	HX_SOURCE_PUSH("EReg_obj::split")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",70)
	int pos = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",71)
	int len = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",72)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",73)
	bool first = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",74)
	do{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",75)
		if ((!(::EReg_obj::regexp_match(this->r,s,pos,len)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",76)
			break;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",77)
		Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,(int)0);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",78)
		if (((bool((p->__Field(HX_CSTRING("len")) == (int)0)) && bool(!(first))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",79)
			if (((p->__Field(HX_CSTRING("pos")) == s.length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",80)
				break;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",81)
			hx::AddEq(p->__FieldRef(HX_CSTRING("pos")),(int)1);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",83)
		a->push(s.substr(pos,(p->__Field(HX_CSTRING("pos")) - pos)));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",84)
		int tot = ((p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len"))) - pos);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",85)
		hx::AddEq(pos,tot);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",86)
		hx::SubEq(len,tot);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",87)
		first = false;
	}
while((this->global));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",89)
	a->push(s.substr(pos,len));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",90)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,split,return )

::String EReg_obj::replace( ::String s,::String by){
	HX_SOURCE_PUSH("EReg_obj::replace")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",94)
	::StringBuf b = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",95)
	int pos = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",96)
	int len = s.length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",97)
	Array< ::String > a = by.split(HX_CSTRING("$"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",98)
	bool first = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",99)
	do{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",100)
		if ((!(::EReg_obj::regexp_match(this->r,s,pos,len)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",101)
			break;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",102)
		Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,(int)0);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",103)
		if (((bool((p->__Field(HX_CSTRING("len")) == (int)0)) && bool(!(first))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",104)
			if (((p->__Field(HX_CSTRING("pos")) == s.length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",105)
				break;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",106)
			hx::AddEq(p->__FieldRef(HX_CSTRING("pos")),(int)1);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",108)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = s.substr(pos,(p->__Field(HX_CSTRING("pos")) - pos));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",109)
		if (((a->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",110)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = a->__get((int)0);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",111)
		int i = (int)1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",112)
		while(((i < a->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",113)
			::String k = a->__get(i);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",114)
			Dynamic c = k.charCodeAt((int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",116)
			if (((bool((c >= (int)49)) && bool((c <= (int)57))))){
				struct _Function_4_1{
					inline static Dynamic Block( ::EReg_obj *__this,Dynamic &c){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",117)
						try{
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",117)
							return ::EReg_obj::regexp_matched_pos(__this->r,(::Std_obj::_int(c) - (int)48));
						}
						catch(Dynamic __e){
							if (__e.IsClass< ::String >() ){
								::String e = __e;{
									HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",117)
									return null();
								}
							}
							else throw(__e);
						}
					}
				};
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",117)
				Dynamic p1 = _Function_4_1::Block(this,c);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",118)
				if (((p1 == null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",119)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("$");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",120)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = k;
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",122)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = s.substr(p1->__Field(HX_CSTRING("pos")),p1->__Field(HX_CSTRING("len")));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",123)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = k.substr((int)1,(k.length - (int)1));
				}
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",125)
				if (((c == null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",126)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("$");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",127)
					(i)++;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",128)
					::String k2 = a->__get(i);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",129)
					if (((bool((k2 != null())) && bool((k2.length > (int)0))))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",130)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = k2;
					}
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",132)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = (HX_CSTRING("$") + k);
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",133)
			(i)++;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",135)
		int tot = ((p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len"))) - pos);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",136)
		hx::AddEq(pos,tot);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",137)
		hx::SubEq(len,tot);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",138)
		first = false;
	}
while((this->global));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",140)
	hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = s.substr(pos,len);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",141)
	return b->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC2(EReg_obj,replace,return )

::String EReg_obj::customReplace( ::String s,Dynamic f){
	HX_SOURCE_PUSH("EReg_obj::customReplace")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",145)
	::StringBuf buf = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",146)
	while((true)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",147)
		if ((!(this->match(s)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",148)
			break;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",149)
		hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"))) = this->matchedLeft();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",150)
		hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"))) = f(hx::ObjectPtr<OBJ_>(this)).Cast< ::String >();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",151)
		s = this->matchedRight();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",153)
	hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"))) = s;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/EReg.hx",154)
	return buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC2(EReg_obj,customReplace,return )

Dynamic EReg_obj::regexp_new_options;

Dynamic EReg_obj::regexp_match;

Dynamic EReg_obj::regexp_matched;

Dynamic EReg_obj::regexp_matched_pos;


EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EReg);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_END_CLASS();
}

Dynamic EReg_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { return last; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"match") ) { return match_dyn(); }
		if (HX_FIELD_EQ(inName,"split") ) { return split_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { return global; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"matched") ) { return matched_dyn(); }
		if (HX_FIELD_EQ(inName,"replace") ) { return replace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"matchedPos") ) { return matchedPos_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"matchedLeft") ) { return matchedLeft_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regexp_match") ) { return regexp_match; }
		if (HX_FIELD_EQ(inName,"matchedRight") ) { return matchedRight_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"customReplace") ) { return customReplace_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"regexp_matched") ) { return regexp_matched; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { return regexp_new_options; }
		if (HX_FIELD_EQ(inName,"regexp_matched_pos") ) { return regexp_matched_pos; }
	}
	return super::__Field(inName);
}

Dynamic EReg_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regexp_match") ) { regexp_match=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"regexp_matched") ) { regexp_matched=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { regexp_new_options=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"regexp_matched_pos") ) { regexp_matched_pos=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("last"));
	outFields->push(HX_CSTRING("global"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("regexp_new_options"),
	HX_CSTRING("regexp_match"),
	HX_CSTRING("regexp_matched"),
	HX_CSTRING("regexp_matched_pos"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("r"),
	HX_CSTRING("last"),
	HX_CSTRING("global"),
	HX_CSTRING("match"),
	HX_CSTRING("matched"),
	HX_CSTRING("matchedLeft"),
	HX_CSTRING("matchedRight"),
	HX_CSTRING("matchedPos"),
	HX_CSTRING("split"),
	HX_CSTRING("replace"),
	HX_CSTRING("customReplace"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_new_options,"regexp_new_options");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_match,"regexp_match");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_matched,"regexp_matched");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_matched_pos,"regexp_matched_pos");
};

Class EReg_obj::__mClass;

void EReg_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("EReg"), hx::TCanCast< EReg_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EReg_obj::__boot()
{
	hx::Static(regexp_new_options) = ::cpp::Lib_obj::load(HX_CSTRING("regexp"),HX_CSTRING("regexp_new_options"),(int)2);
	hx::Static(regexp_match) = ::cpp::Lib_obj::load(HX_CSTRING("regexp"),HX_CSTRING("regexp_match"),(int)4);
	hx::Static(regexp_matched) = ::cpp::Lib_obj::load(HX_CSTRING("regexp"),HX_CSTRING("regexp_matched"),(int)2);
	hx::Static(regexp_matched_pos) = ::cpp::Lib_obj::load(HX_CSTRING("regexp"),HX_CSTRING("regexp_matched_pos"),(int)2);
}

