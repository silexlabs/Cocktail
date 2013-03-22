#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Void Bytes_obj::__construct(int length,Array< unsigned char > b)
{
HX_STACK_PUSH("Bytes::new","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",32);
{
	HX_STACK_LINE(33)
	this->length = length;
	HX_STACK_LINE(34)
	this->b = b;
}
;
	return null();
}

Bytes_obj::~Bytes_obj() { }

Dynamic Bytes_obj::__CreateEmpty() { return  new Bytes_obj; }
hx::ObjectPtr< Bytes_obj > Bytes_obj::__new(int length,Array< unsigned char > b)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(length,b);
	return result;}

Dynamic Bytes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Array< unsigned char > Bytes_obj::getData( ){
	HX_STACK_PUSH("Bytes::getData","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",255);
	HX_STACK_THIS(this);
	HX_STACK_LINE(255)
	return this->b;
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,getData,return )

::String Bytes_obj::toHex( ){
	HX_STACK_PUSH("Bytes::toHex","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",241);
	HX_STACK_THIS(this);
	HX_STACK_LINE(242)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(243)
	Array< Dynamic > chars = Array_obj< Dynamic >::__new();		HX_STACK_VAR(chars,"chars");
	HX_STACK_LINE(244)
	::String str = HX_CSTRING("0123456789abcdef");		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(245)
	{
		HX_STACK_LINE(245)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = str.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(245)
		while(((_g1 < _g))){
			HX_STACK_LINE(245)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(246)
			chars->push(str.charCodeAt(i));
		}
	}
	HX_STACK_LINE(247)
	{
		HX_STACK_LINE(247)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(247)
		while(((_g1 < _g))){
			HX_STACK_LINE(247)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(248)
			int c = this->b->__get(i);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(249)
			{
				HX_STACK_LINE(249)
				int c1 = chars->__get((int(c) >> int((int)4)));		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(249)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode(c1);
			}
			HX_STACK_LINE(250)
			{
				HX_STACK_LINE(250)
				int c1 = chars->__get((int(c) & int((int)15)));		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(250)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode(c1);
			}
		}
	}
	HX_STACK_LINE(252)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toHex,return )

::String Bytes_obj::toString( ){
	HX_STACK_PUSH("Bytes::toString","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_LINE(218)
	return this->readString((int)0,this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toString,return )

::String Bytes_obj::readString( int pos,int len){
	HX_STACK_PUSH("Bytes::readString","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(170)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > this->length))))){
		HX_STACK_LINE(170)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_STACK_LINE(182)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(183)
	::__hxcpp_string_of_bytes(this->b,result,pos,len);
	HX_STACK_LINE(184)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,readString,return )

int Bytes_obj::compare( ::haxe::io::Bytes other){
	HX_STACK_PUSH("Bytes::compare","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",130);
	HX_STACK_THIS(this);
	HX_STACK_ARG(other,"other");
	HX_STACK_LINE(154)
	Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
	HX_STACK_LINE(155)
	Array< unsigned char > b2 = other->b;		HX_STACK_VAR(b2,"b2");
	HX_STACK_LINE(156)
	int len = (  (((this->length < other->length))) ? int(this->length) : int(other->length) );		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(157)
	{
		HX_STACK_LINE(157)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		while(((_g < len))){
			HX_STACK_LINE(157)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(158)
			if (((b1->__get(i) != b2->__get(i)))){
				HX_STACK_LINE(160)
				return (b1->__get(i) - b2->__get(i));
			}
		}
	}
	HX_STACK_LINE(164)
	return (this->length - other->length);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,compare,return )

::haxe::io::Bytes Bytes_obj::sub( int pos,int len){
	HX_STACK_PUSH("Bytes::sub","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",103);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(105)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > this->length))))){
		HX_STACK_LINE(105)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_STACK_LINE(126)
	return ::haxe::io::Bytes_obj::__new(len,this->b->slice(pos,(pos + len)));
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,sub,return )

Void Bytes_obj::blit( int pos,::haxe::io::Bytes src,int srcpos,int len){
{
		HX_STACK_PUSH("Bytes::blit","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(src,"src");
		HX_STACK_ARG(srcpos,"srcpos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(73)
		if (((bool((bool((bool((bool((pos < (int)0)) || bool((srcpos < (int)0)))) || bool((len < (int)0)))) || bool(((pos + len) > this->length)))) || bool(((srcpos + len) > src->length))))){
			HX_STACK_LINE(73)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_STACK_LINE(88)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(89)
		Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(90)
		if (((bool((b1 == b2)) && bool((pos > srcpos))))){
			HX_STACK_LINE(91)
			int i = len;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(92)
			while(((i > (int)0))){
				HX_STACK_LINE(93)
				(i)--;
				HX_STACK_LINE(94)
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
			HX_STACK_LINE(96)
			return null();
		}
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			while(((_g < len))){
				HX_STACK_LINE(98)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(99)
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Bytes_obj,blit,(void))

Void Bytes_obj::set( int pos,int v){
{
		HX_STACK_PUSH("Bytes::set","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(53)
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,set,(void))

int Bytes_obj::get( int pos){
	HX_STACK_PUSH("Bytes::get","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(37)
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,get,return )

::haxe::io::Bytes Bytes_obj::alloc( int length){
	HX_STACK_PUSH("Bytes::alloc","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",259);
	HX_STACK_ARG(length,"length");
	HX_STACK_LINE(276)
	Array< unsigned char > a = Array_obj< unsigned char >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(277)
	if (((length > (int)0))){
		HX_STACK_LINE(277)
		a[(length - (int)1)] = (int)0;
	}
	HX_STACK_LINE(278)
	return ::haxe::io::Bytes_obj::__new(length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,alloc,return )

::haxe::io::Bytes Bytes_obj::ofString( ::String s){
	HX_STACK_PUSH("Bytes::ofString","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",291);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(302)
	Array< unsigned char > a = Array_obj< unsigned char >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(303)
	::__hxcpp_bytes_of_string(a,s);
	HX_STACK_LINE(304)
	return ::haxe::io::Bytes_obj::__new(a->length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofString,return )

::haxe::io::Bytes Bytes_obj::ofData( Array< unsigned char > b){
	HX_STACK_PUSH("Bytes::ofData","C:\\Motion-Twin\\Haxe/std/haxe/io/Bytes.hx",340);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(340)
	return ::haxe::io::Bytes_obj::__new(b->length,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofData,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void Bytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic Bytes_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"blit") ) { return blit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alloc") ) { return alloc_dyn(); }
		if (HX_FIELD_EQ(inName,"toHex") ) { return toHex_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ofData") ) { return ofData_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { return ofString_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readString") ) { return readString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bytes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("alloc"),
	HX_CSTRING("ofString"),
	HX_CSTRING("ofData"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getData"),
	HX_CSTRING("toHex"),
	HX_CSTRING("toString"),
	HX_CSTRING("readString"),
	HX_CSTRING("compare"),
	HX_CSTRING("sub"),
	HX_CSTRING("blit"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("b"),
	HX_CSTRING("length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

Class Bytes_obj::__mClass;

void Bytes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Bytes"), hx::TCanCast< Bytes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bytes_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
