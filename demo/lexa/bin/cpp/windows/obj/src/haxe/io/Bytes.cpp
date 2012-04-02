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
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",33)
	this->length = length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",34)
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

int Bytes_obj::get( int pos){
	HX_SOURCE_PUSH("Bytes_obj::get")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",37)
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,get,return )

Void Bytes_obj::set( int pos,int v){
{
		HX_SOURCE_PUSH("Bytes_obj::set")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",51)
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,set,(void))

Void Bytes_obj::blit( int pos,::haxe::io::Bytes src,int srcpos,int len){
{
		HX_SOURCE_PUSH("Bytes_obj::blit")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",67)
		if (((bool((bool((bool((bool((pos < (int)0)) || bool((srcpos < (int)0)))) || bool((len < (int)0)))) || bool(((pos + len) > this->length)))) || bool(((srcpos + len) > src->length))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",67)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",78)
		Array< unsigned char > b1 = this->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",79)
		Array< unsigned char > b2 = src->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",80)
		if (((bool((b1 == b2)) && bool((pos > srcpos))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",81)
			int i = len;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",82)
			while(((i > (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",83)
				(i)--;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",84)
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",86)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",88)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",88)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",88)
			while(((_g < len))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",88)
				int i = (_g)++;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",89)
				b1[(i + pos)] = b2->__get((i + srcpos));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Bytes_obj,blit,(void))

::haxe::io::Bytes Bytes_obj::sub( int pos,int len){
	HX_SOURCE_PUSH("Bytes_obj::sub")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",95)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > this->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",95)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",108)
	return ::haxe::io::Bytes_obj::__new(len,this->b->slice(pos,(pos + len)));
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,sub,return )

int Bytes_obj::compare( ::haxe::io::Bytes other){
	HX_SOURCE_PUSH("Bytes_obj::compare")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",134)
	Array< unsigned char > b1 = this->b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",135)
	Array< unsigned char > b2 = other->b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",136)
	int len = (  (((this->length < other->length))) ? int(this->length) : int(other->length) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",137)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",137)
		int _g = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",137)
		while(((_g < len))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",137)
			int i = (_g)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",138)
			if (((b1->__get(i) != b2->__get(i)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",140)
				return (b1->__get(i) - b2->__get(i));
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",144)
	return (this->length - other->length);
}


HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,compare,return )

::String Bytes_obj::readString( int pos,int len){
	HX_SOURCE_PUSH("Bytes_obj::readString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",150)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > this->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",150)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",162)
	::String result = HX_CSTRING("");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",163)
	::__hxcpp_string_of_bytes(this->b,result,pos,len);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",164)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,readString,return )

::String Bytes_obj::toString( ){
	HX_SOURCE_PUSH("Bytes_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",192)
	return this->readString((int)0,this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toString,return )

::String Bytes_obj::toHex( ){
	HX_SOURCE_PUSH("Bytes_obj::toHex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",208)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",209)
	Array< Dynamic > chars = Array_obj< Dynamic >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",210)
	::String str = HX_CSTRING("0123456789abcdef");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",211)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",211)
		int _g1 = (int)0;
		int _g = str.length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",211)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",211)
			int i = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",212)
			chars->push(str.charCodeAt(i));
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",213)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",213)
		int _g1 = (int)0;
		int _g = this->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",213)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",213)
			int i = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",214)
			int c = this->b->__get(i);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",215)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",215)
				int c1 = chars->__get((int(c) >> int((int)4)));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",215)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode(c1);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",216)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",216)
				int c1 = chars->__get((int(c) & int((int)15)));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",216)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode(c1);
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",218)
	return s->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toHex,return )

Array< unsigned char > Bytes_obj::getData( ){
	HX_SOURCE_PUSH("Bytes_obj::getData")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",221)
	return this->b;
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,getData,return )

::haxe::io::Bytes Bytes_obj::alloc( int length){
	HX_SOURCE_PUSH("Bytes_obj::alloc")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",242)
	Array< unsigned char > a = Array_obj< unsigned char >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",243)
	if (((length > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",243)
		a[(length - (int)1)] = (int)0;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",244)
	return ::haxe::io::Bytes_obj::__new(length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,alloc,return )

::haxe::io::Bytes Bytes_obj::ofString( ::String s){
	HX_SOURCE_PUSH("Bytes_obj::ofString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",264)
	Array< unsigned char > a = Array_obj< unsigned char >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",265)
	::__hxcpp_bytes_of_string(a,s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",266)
	return ::haxe::io::Bytes_obj::__new(a->length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofString,return )

::haxe::io::Bytes Bytes_obj::ofData( Array< unsigned char > b){
	HX_SOURCE_PUSH("Bytes_obj::ofData")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Bytes.hx",292)
	return ::haxe::io::Bytes_obj::__new(b->length,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofData,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

Dynamic Bytes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
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
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { return ofString_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readString") ) { return readString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Bytes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("alloc"),
	HX_CSTRING("ofString"),
	HX_CSTRING("ofData"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("b"),
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("blit"),
	HX_CSTRING("sub"),
	HX_CSTRING("compare"),
	HX_CSTRING("readString"),
	HX_CSTRING("toString"),
	HX_CSTRING("toHex"),
	HX_CSTRING("getData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Bytes_obj::__mClass;

void Bytes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Bytes"), hx::TCanCast< Bytes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bytes_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
