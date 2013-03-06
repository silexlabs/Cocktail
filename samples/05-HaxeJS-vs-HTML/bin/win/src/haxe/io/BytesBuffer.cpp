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
HX_STACK_PUSH("BytesBuffer::new","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesBuffer.hx",45);
{
	HX_STACK_LINE(45)
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

::haxe::io::Bytes BytesBuffer_obj::getBytes( ){
	HX_STACK_PUSH("BytesBuffer::getBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesBuffer.hx",126);
	HX_STACK_THIS(this);
	HX_STACK_LINE(142)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new(this->b->length,this->b);		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(144)
	this->b = null();
	HX_STACK_LINE(145)
	return bytes;
}


HX_DEFINE_DYNAMIC_FUNC0(BytesBuffer_obj,getBytes,return )

Void BytesBuffer_obj::addBytes( ::haxe::io::Bytes src,int pos,int len){
{
		HX_STACK_PUSH("BytesBuffer::addBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesBuffer.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_ARG(src,"src");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(102)
		if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > src->length))))){
			HX_STACK_LINE(102)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_STACK_LINE(115)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(116)
		Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(117)
		{
			HX_STACK_LINE(117)
			int _g1 = pos;		HX_STACK_VAR(_g1,"_g1");
			int _g = (pos + len);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(117)
			while(((_g1 < _g))){
				HX_STACK_LINE(117)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(118)
				this->b->push(b2->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BytesBuffer_obj,addBytes,(void))

Void BytesBuffer_obj::add( ::haxe::io::Bytes src){
{
		HX_STACK_PUSH("BytesBuffer::add","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesBuffer.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(src,"src");
		HX_STACK_LINE(93)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(94)
		Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(95)
		{
			HX_STACK_LINE(95)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = src->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(95)
			while(((_g1 < _g))){
				HX_STACK_LINE(95)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(96)
				this->b->push(b2->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesBuffer_obj,add,(void))

Void BytesBuffer_obj::addByte( int byte){
{
		HX_STACK_PUSH("BytesBuffer::addByte","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesBuffer.hx",63);
		HX_STACK_THIS(this);
		HX_STACK_ARG(byte,"byte");
		HX_STACK_LINE(63)
		this->b->push(byte);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BytesBuffer_obj,addByte,(void))


BytesBuffer_obj::BytesBuffer_obj()
{
}

void BytesBuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesBuffer);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void BytesBuffer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic BytesBuffer_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"addBytes") ) { return addBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BytesBuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BytesBuffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBytes"),
	HX_CSTRING("addBytes"),
	HX_CSTRING("add"),
	HX_CSTRING("addByte"),
	HX_CSTRING("b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytesBuffer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytesBuffer_obj::__mClass,"__mClass");
};

Class BytesBuffer_obj::__mClass;

void BytesBuffer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.BytesBuffer"), hx::TCanCast< BytesBuffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BytesBuffer_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
