#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_zip_Flush
#include <cpp/zip/Flush.h>
#endif
#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace cpp{
namespace zip{

Void Uncompress_obj::__construct(Dynamic windowBits)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",30)
	this->s = ::cpp::zip::Uncompress_obj::_inflate_init(windowBits);
}
;
	return null();
}

Uncompress_obj::~Uncompress_obj() { }

Dynamic Uncompress_obj::__CreateEmpty() { return  new Uncompress_obj; }
hx::ObjectPtr< Uncompress_obj > Uncompress_obj::__new(Dynamic windowBits)
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct(windowBits);
	return result;}

Dynamic Uncompress_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Uncompress_obj > result = new Uncompress_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Uncompress_obj::this_run( ::haxe::io::Bytes src,int srcPos,::haxe::io::Bytes dst,int dstPos){
	HX_SOURCE_PUSH("Uncompress_obj::this_run")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",34)
	return ::cpp::zip::Uncompress_obj::_inflate_buffer(this->s,src->b,srcPos,dst->b,dstPos);
}


HX_DEFINE_DYNAMIC_FUNC4(Uncompress_obj,this_run,return )

Void Uncompress_obj::setFlushMode( ::cpp::zip::Flush f){
{
		HX_SOURCE_PUSH("Uncompress_obj::setFlushMode")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",38)
		::cpp::zip::Uncompress_obj::_set_flush_mode(this->s,f->__Tag());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Uncompress_obj,setFlushMode,(void))

Void Uncompress_obj::close( ){
{
		HX_SOURCE_PUSH("Uncompress_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",42)
		::cpp::zip::Uncompress_obj::_inflate_end(this->s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Uncompress_obj,close,(void))

::haxe::io::Bytes Uncompress_obj::run( ::haxe::io::Bytes src,Dynamic bufsize){
	HX_SOURCE_PUSH("Uncompress_obj::run")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",47)
	::cpp::zip::Uncompress u = ::cpp::zip::Uncompress_obj::__new(null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",48)
	if (((bufsize == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",48)
		bufsize = (int)65536;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",49)
	::haxe::io::Bytes tmp = ::haxe::io::Bytes_obj::alloc(bufsize);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",50)
	::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",51)
	int pos = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",52)
	u->setFlushMode(::cpp::zip::Flush_obj::SYNC_dyn());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",53)
	while((true)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",54)
		Dynamic r = u->this_run(src,pos,tmp,(int)0);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
			int len = r->__Field(HX_CSTRING("write"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
			if (((bool((len < (int)0)) || bool((len > tmp->length))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
				hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
			Array< unsigned char > b1 = b->b;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
			Array< unsigned char > b2 = tmp->b;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
				int _g1 = (int)0;
				int _g = len;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
				while(((_g1 < _g))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
					int i = (_g1)++;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",55)
					b->b->push(b2->__get(i));
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",56)
		hx::AddEq(pos,r->__Field(HX_CSTRING("read")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",57)
		if ((r->__Field(HX_CSTRING("done")))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",58)
			break;
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",60)
	u->close();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/zip/Uncompress.hx",61)
	return b->getBytes();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Uncompress_obj,run,return )

Dynamic Uncompress_obj::_inflate_init;

Dynamic Uncompress_obj::_inflate_buffer;

Dynamic Uncompress_obj::_inflate_end;

Dynamic Uncompress_obj::_set_flush_mode;


Uncompress_obj::Uncompress_obj()
{
}

void Uncompress_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Uncompress);
	HX_MARK_MEMBER_NAME(s,"s");
	HX_MARK_END_CLASS();
}

Dynamic Uncompress_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"s") ) { return s; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"this_run") ) { return this_run_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_inflate_end") ) { return _inflate_end; }
		if (HX_FIELD_EQ(inName,"setFlushMode") ) { return setFlushMode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_inflate_init") ) { return _inflate_init; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_inflate_buffer") ) { return _inflate_buffer; }
		if (HX_FIELD_EQ(inName,"_set_flush_mode") ) { return _set_flush_mode; }
	}
	return super::__Field(inName);
}

Dynamic Uncompress_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"s") ) { s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_inflate_end") ) { _inflate_end=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_inflate_init") ) { _inflate_init=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_inflate_buffer") ) { _inflate_buffer=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_set_flush_mode") ) { _set_flush_mode=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Uncompress_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("run"),
	HX_CSTRING("_inflate_init"),
	HX_CSTRING("_inflate_buffer"),
	HX_CSTRING("_inflate_end"),
	HX_CSTRING("_set_flush_mode"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("s"),
	HX_CSTRING("this_run"),
	HX_CSTRING("setFlushMode"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_init,"_inflate_init");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_buffer,"_inflate_buffer");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_end,"_inflate_end");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_set_flush_mode,"_set_flush_mode");
};

Class Uncompress_obj::__mClass;

void Uncompress_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.zip.Uncompress"), hx::TCanCast< Uncompress_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Uncompress_obj::__boot()
{
	hx::Static(_inflate_init) = ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_init"),(int)1);
	hx::Static(_inflate_buffer) = ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_buffer"),(int)5);
	hx::Static(_inflate_end) = ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_end"),(int)1);
	hx::Static(_set_flush_mode) = ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("set_flush_mode"),(int)2);
}

} // end namespace cpp
} // end namespace zip
