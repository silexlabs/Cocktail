#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void BytesOutput_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",35)
	this->b = ::haxe::io::BytesBuffer_obj::__new();
}
;
	return null();
}

BytesOutput_obj::~BytesOutput_obj() { }

Dynamic BytesOutput_obj::__CreateEmpty() { return  new BytesOutput_obj; }
hx::ObjectPtr< BytesOutput_obj > BytesOutput_obj::__new()
{  hx::ObjectPtr< BytesOutput_obj > result = new BytesOutput_obj();
	result->__construct();
	return result;}

Dynamic BytesOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesOutput_obj > result = new BytesOutput_obj();
	result->__construct();
	return result;}

Void BytesOutput_obj::writeByte( int c){
{
		HX_SOURCE_PUSH("BytesOutput_obj::writeByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",44)
		this->b->b->push(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesOutput_obj,writeByte,(void))

int BytesOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_SOURCE_PUSH("BytesOutput_obj::writeBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
		::haxe::io::BytesBuffer _this = this->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
		if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > buf->length))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
		Array< unsigned char > b1 = _this->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
		Array< unsigned char > b2 = buf->b;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
			int _g1 = pos;
			int _g = (pos + len);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
			while(((_g1 < _g))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
				int i = (_g1)++;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",57)
				_this->b->push(b2->__get(i));
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",59)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(BytesOutput_obj,writeBytes,return )

::haxe::io::Bytes BytesOutput_obj::getBytes( ){
	HX_SOURCE_PUSH("BytesOutput_obj::getBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/BytesOutput.hx",126)
	return this->b->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC0(BytesOutput_obj,getBytes,return )


BytesOutput_obj::BytesOutput_obj()
{
}

void BytesOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesOutput);
	HX_MARK_MEMBER_NAME(b,"b");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BytesOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BytesOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::haxe::io::BytesBuffer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BytesOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("b"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("getBytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BytesOutput_obj::__mClass;

void BytesOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.BytesOutput"), hx::TCanCast< BytesOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BytesOutput_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
