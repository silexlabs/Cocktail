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
HX_STACK_PUSH("BytesOutput::new","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesOutput.hx",35);
{
	HX_STACK_LINE(35)
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

::haxe::io::Bytes BytesOutput_obj::getBytes( ){
	HX_STACK_PUSH("BytesOutput::getBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesOutput.hx",126);
	HX_STACK_THIS(this);
	HX_STACK_LINE(126)
	return this->b->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC0(BytesOutput_obj,getBytes,return )

int BytesOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_PUSH("BytesOutput::writeBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesOutput.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buf,"buf");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(57)
	{
		HX_STACK_LINE(57)
		::haxe::io::BytesBuffer _this = this->b;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(57)
		if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > buf->length))))){
			HX_STACK_LINE(57)
			hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
		}
		HX_STACK_LINE(57)
		Array< unsigned char > b1 = _this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(57)
		Array< unsigned char > b2 = buf->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			int _g1 = pos;		HX_STACK_VAR(_g1,"_g1");
			int _g = (pos + len);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			while(((_g1 < _g))){
				HX_STACK_LINE(57)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(57)
				_this->b->push(b2->__get(i));
			}
		}
	}
	HX_STACK_LINE(59)
	return len;
}


Void BytesOutput_obj::writeByte( int c){
{
		HX_STACK_PUSH("BytesOutput::writeByte","C:\\Motion-Twin\\Haxe/std/haxe/io/BytesOutput.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(44)
		this->b->b->push(c);
	}
return null();
}



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

void BytesOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BytesOutput_obj::__Field(const ::String &inName,bool inCallProp)
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
	return super::__Field(inName,inCallProp);
}

Dynamic BytesOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::haxe::io::BytesBuffer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BytesOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBytes"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytesOutput_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytesOutput_obj::__mClass,"__mClass");
};

Class BytesOutput_obj::__mClass;

void BytesOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.BytesOutput"), hx::TCanCast< BytesOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BytesOutput_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
