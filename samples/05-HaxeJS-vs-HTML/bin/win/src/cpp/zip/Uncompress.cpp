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
HX_STACK_PUSH("Uncompress::new","C:\\Motion-Twin\\Haxe/std/cpp/zip/Uncompress.hx",30);
{
	HX_STACK_LINE(30)
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

Void Uncompress_obj::close( ){
{
		HX_STACK_PUSH("Uncompress::close","C:\\Motion-Twin\\Haxe/std/cpp/zip/Uncompress.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		::cpp::zip::Uncompress_obj::_inflate_end(this->s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Uncompress_obj,close,(void))

Void Uncompress_obj::setFlushMode( ::cpp::zip::Flush f){
{
		HX_STACK_PUSH("Uncompress::setFlushMode","C:\\Motion-Twin\\Haxe/std/cpp/zip/Uncompress.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(38)
		::cpp::zip::Uncompress_obj::_set_flush_mode(this->s,f->__Tag());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Uncompress_obj,setFlushMode,(void))

Dynamic Uncompress_obj::this_run( ::haxe::io::Bytes src,int srcPos,::haxe::io::Bytes dst,int dstPos){
	HX_STACK_PUSH("Uncompress::this_run","C:\\Motion-Twin\\Haxe/std/cpp/zip/Uncompress.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(src,"src");
	HX_STACK_ARG(srcPos,"srcPos");
	HX_STACK_ARG(dst,"dst");
	HX_STACK_ARG(dstPos,"dstPos");
	HX_STACK_LINE(34)
	return ::cpp::zip::Uncompress_obj::_inflate_buffer(this->s,src->b,srcPos,dst->b,dstPos);
}


HX_DEFINE_DYNAMIC_FUNC4(Uncompress_obj,this_run,return )

::haxe::io::Bytes Uncompress_obj::run( ::haxe::io::Bytes src,Dynamic bufsize){
	HX_STACK_PUSH("Uncompress::run","C:\\Motion-Twin\\Haxe/std/cpp/zip/Uncompress.hx",46);
	HX_STACK_ARG(src,"src");
	HX_STACK_ARG(bufsize,"bufsize");
	HX_STACK_LINE(47)
	::cpp::zip::Uncompress u = ::cpp::zip::Uncompress_obj::__new(null());		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(48)
	if (((bufsize == null()))){
		HX_STACK_LINE(48)
		bufsize = (int)65536;
	}
	HX_STACK_LINE(49)
	::haxe::io::Bytes tmp = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(50)
	::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(51)
	int pos = (int)0;		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(52)
	u->setFlushMode(::cpp::zip::Flush_obj::SYNC_dyn());
	HX_STACK_LINE(53)
	while((true)){
		HX_STACK_LINE(54)
		Dynamic r = u->this_run(src,pos,tmp,(int)0);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(55)
		{
			HX_STACK_LINE(55)
			int len = r->__Field(HX_CSTRING("write"),true);		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(55)
			if (((bool((len < (int)0)) || bool((len > tmp->length))))){
				HX_STACK_LINE(55)
				hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
			}
			HX_STACK_LINE(55)
			Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
			HX_STACK_LINE(55)
			Array< unsigned char > b2 = tmp->b;		HX_STACK_VAR(b2,"b2");
			HX_STACK_LINE(55)
			{
				HX_STACK_LINE(55)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				int _g = len;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(55)
				while(((_g1 < _g))){
					HX_STACK_LINE(55)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					b->b->push(b2->__get(i));
				}
			}
		}
		HX_STACK_LINE(56)
		hx::AddEq(pos,r->__Field(HX_CSTRING("read"),true));
		HX_STACK_LINE(57)
		if ((r->__Field(HX_CSTRING("done"),true))){
			HX_STACK_LINE(58)
			break;
		}
	}
	HX_STACK_LINE(60)
	u->close();
	HX_STACK_LINE(61)
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

void Uncompress_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(s,"s");
}

Dynamic Uncompress_obj::__Field(const ::String &inName,bool inCallProp)
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
	return super::__Field(inName,inCallProp);
}

Dynamic Uncompress_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("close"),
	HX_CSTRING("setFlushMode"),
	HX_CSTRING("this_run"),
	HX_CSTRING("s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Uncompress_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_init,"_inflate_init");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_buffer,"_inflate_buffer");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_inflate_end,"_inflate_end");
	HX_MARK_MEMBER_NAME(Uncompress_obj::_set_flush_mode,"_set_flush_mode");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Uncompress_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Uncompress_obj::_inflate_init,"_inflate_init");
	HX_VISIT_MEMBER_NAME(Uncompress_obj::_inflate_buffer,"_inflate_buffer");
	HX_VISIT_MEMBER_NAME(Uncompress_obj::_inflate_end,"_inflate_end");
	HX_VISIT_MEMBER_NAME(Uncompress_obj::_set_flush_mode,"_set_flush_mode");
};

Class Uncompress_obj::__mClass;

void Uncompress_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.zip.Uncompress"), hx::TCanCast< Uncompress_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Uncompress_obj::__boot()
{
	_inflate_init= ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_init"),(int)1);
	_inflate_buffer= ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_buffer"),(int)5);
	_inflate_end= ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("inflate_end"),(int)1);
	_set_flush_mode= ::cpp::Lib_obj::load(HX_CSTRING("zlib"),HX_CSTRING("set_flush_mode"),(int)2);
}

} // end namespace cpp
} // end namespace zip
