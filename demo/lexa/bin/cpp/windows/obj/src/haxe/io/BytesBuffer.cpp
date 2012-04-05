#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Void BytesBuffer_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",41)
	this->b = Array_obj< unsigned char >::__new();
}
;
	return null();
}

BytesBuffer_obj::~BytesBuffer_obj() { }

Dynamic BytesBuffer_obj::__CreateEmpty() { return  new BytesBuffer_obj; }
hx::ObjectPtr< BytesBuffer_obj > BytesBuffer_obj::__new()
{  hx::ObjectPtr< BytesBuffer_obj > result = new BytesBuffer_obj();
	result->__construct();
	return result;}

Dynamic BytesBuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesBuffer_obj > result = new BytesBuffer_obj();
	result->__construct();
	return result;}

Void BytesBuffer_obj::addByte( int byte){
{
		HX_SOURCE_PUSH("BytesBuffer_obj::addByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",55)
		this->b->push(byte);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesBuffer_obj,addByte,(void))

Void BytesBuffer_obj::add( ::haxe::io::Bytes src){
{
		HX_SOURCE_PUSH("BytesBuffer_obj::add")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",77)
		Array< unsigned char > b1 = this->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",78)
		Array< unsigned char > b2 = src->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",79)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",79)
			int _g1 = (int)0;
			int _g = src->length;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",79)
			while(((_g1 < _g))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",79)
				int i = (_g1)++;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",80)
				this->b->push(b2->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesBuffer_obj,add,(void))

Void BytesBuffer_obj::addBytes( ::haxe::io::Bytes src,int pos,int len){
{
		HX_SOURCE_PUSH("BytesBuffer_obj::addBytes")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",86)
		if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > src->length))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",86)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",95)
		Array< unsigned char > b1 = this->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",96)
		Array< unsigned char > b2 = src->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",97)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",97)
			int _g1 = pos;
			int _g = (pos + len);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",97)
			while(((_g1 < _g))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",97)
				int i = (_g1)++;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",98)
				this->b->push(b2->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BytesBuffer_obj,addBytes,(void))

::haxe::io::Bytes BytesBuffer_obj::getBytes( ){
	HX_SOURCE_PUSH("BytesBuffer_obj::getBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",116)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new(this->b->length,this->b);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",118)
	this->b = null();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesBuffer.hx",119)
	return bytes;
}


HX_DEFINE_DYNAMIC_FUNC0(BytesBuffer_obj,getBytes,return )


BytesBuffer_obj::BytesBuffer_obj()
{
}

void BytesBuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesBuffer);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

Dynamic BytesBuffer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addByte") ) { return addByte_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addBytes") ) { return addBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BytesBuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BytesBuffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("b"),
	HX_CSTRING("addByte"),
	HX_CSTRING("add"),
	HX_CSTRING("addBytes"),
	HX_CSTRING("getBytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BytesBuffer_obj::__mClass;

void BytesBuffer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.BytesBuffer"), hx::TCanCast< BytesBuffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BytesBuffer_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
