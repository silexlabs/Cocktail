#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void Output_obj::__construct()
{
	return null();
}

Output_obj::~Output_obj() { }

Dynamic Output_obj::__CreateEmpty() { return  new Output_obj; }
hx::ObjectPtr< Output_obj > Output_obj::__new()
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Dynamic Output_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Void Output_obj::writeString( ::String s){
{
		HX_STACK_PUSH("Output::writeString","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",348);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(352)
		::haxe::io::Bytes b = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(354)
		this->writeFullBytes(b,(int)0,b->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeString,(void))

Void Output_obj::writeInput( ::haxe::io::Input i,Dynamic bufsize){
{
		HX_STACK_PUSH("Output::writeInput","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",326);
		HX_STACK_THIS(this);
		HX_STACK_ARG(i,"i");
		HX_STACK_ARG(bufsize,"bufsize");
		HX_STACK_LINE(327)
		if (((bufsize == null()))){
			HX_STACK_LINE(328)
			bufsize = (int)4096;
		}
		HX_STACK_LINE(329)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
		HX_STACK_LINE(330)
		try{
			HX_STACK_LINE(330)
			while((true)){
				HX_STACK_LINE(332)
				int len = i->readBytes(buf,(int)0,bufsize);		HX_STACK_VAR(len,"len");
				HX_STACK_LINE(333)
				if (((len == (int)0))){
					HX_STACK_LINE(334)
					hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
				}
				HX_STACK_LINE(335)
				int p = (int)0;		HX_STACK_VAR(p,"p");
				HX_STACK_LINE(336)
				while(((len > (int)0))){
					HX_STACK_LINE(337)
					int k = this->writeBytes(buf,p,len);		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(338)
					if (((k == (int)0))){
						HX_STACK_LINE(339)
						hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
					}
					HX_STACK_LINE(340)
					hx::AddEq(p,k);
					HX_STACK_LINE(341)
					hx::SubEq(len,k);
				}
			}
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::haxe::io::Eof >() ){
				::haxe::io::Eof e = __e;{
				}
			}
			else throw(__e);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Output_obj,writeInput,(void))

Void Output_obj::prepare( int nbytes){
{
		HX_STACK_PUSH("Output::prepare","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",323);
		HX_STACK_THIS(this);
		HX_STACK_ARG(nbytes,"nbytes");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,prepare,(void))

Void Output_obj::writeInt32( ::cpp::CppInt32__ x){
{
		HX_STACK_PUSH("Output::writeInt32","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",303);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(303)
		if ((this->bigEndian)){
			HX_STACK_LINE(305)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)24)));
			HX_STACK_LINE(306)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)16))) & int((int)255)));
			HX_STACK_LINE(307)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)8))) & int((int)255)));
			HX_STACK_LINE(308)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt((int)255))));
		}
		else{
			HX_STACK_LINE(310)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt((int)255))));
			HX_STACK_LINE(311)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)8))) & int((int)255)));
			HX_STACK_LINE(312)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)16))) & int((int)255)));
			HX_STACK_LINE(313)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)24)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt32,(void))

Void Output_obj::writeUInt30( int x){
{
		HX_STACK_PUSH("Output::writeUInt30","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",288);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(289)
		if (((bool((x < (int)0)) || bool((x >= (int)1073741824))))){
			HX_STACK_LINE(289)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(290)
		if ((this->bigEndian)){
			HX_STACK_LINE(291)
			this->writeByte(hx::UShr(x,(int)24));
			HX_STACK_LINE(292)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_STACK_LINE(293)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(294)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_STACK_LINE(296)
			this->writeByte((int(x) & int((int)255)));
			HX_STACK_LINE(297)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(298)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_STACK_LINE(299)
			this->writeByte(hx::UShr(x,(int)24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt30,(void))

Void Output_obj::writeInt31( int x){
{
		HX_STACK_PUSH("Output::writeInt31","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",271);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(273)
		if (((bool((x < (int)-1073741824)) || bool((x >= (int)1073741824))))){
			HX_STACK_LINE(273)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(275)
		if ((this->bigEndian)){
			HX_STACK_LINE(276)
			this->writeByte(hx::UShr(x,(int)24));
			HX_STACK_LINE(277)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_STACK_LINE(278)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(279)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_STACK_LINE(281)
			this->writeByte((int(x) & int((int)255)));
			HX_STACK_LINE(282)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(283)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_STACK_LINE(284)
			this->writeByte(hx::UShr(x,(int)24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt31,(void))

Void Output_obj::writeUInt24( int x){
{
		HX_STACK_PUSH("Output::writeUInt24","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",258);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(259)
		if (((bool((x < (int)0)) || bool((x >= (int)16777216))))){
			HX_STACK_LINE(259)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(260)
		if ((this->bigEndian)){
			HX_STACK_LINE(261)
			this->writeByte((int(x) >> int((int)16)));
			HX_STACK_LINE(262)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(263)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_STACK_LINE(265)
			this->writeByte((int(x) & int((int)255)));
			HX_STACK_LINE(266)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_STACK_LINE(267)
			this->writeByte((int(x) >> int((int)16)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt24,(void))

Void Output_obj::writeInt24( int x){
{
		HX_STACK_PUSH("Output::writeInt24","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(254)
		if (((bool((x < (int)-8388608)) || bool((x >= (int)8388608))))){
			HX_STACK_LINE(254)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(255)
		this->writeUInt24((int(x) & int((int)16777215)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt24,(void))

Void Output_obj::writeUInt16( int x){
{
		HX_STACK_PUSH("Output::writeUInt16","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",242);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(243)
		if (((bool((x < (int)0)) || bool((x >= (int)65536))))){
			HX_STACK_LINE(243)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(244)
		if ((this->bigEndian)){
			HX_STACK_LINE(245)
			this->writeByte((int(x) >> int((int)8)));
			HX_STACK_LINE(246)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_STACK_LINE(248)
			this->writeByte((int(x) & int((int)255)));
			HX_STACK_LINE(249)
			this->writeByte((int(x) >> int((int)8)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt16,(void))

Void Output_obj::writeInt16( int x){
{
		HX_STACK_PUSH("Output::writeInt16","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",237);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(238)
		if (((bool((x < (int)-32768)) || bool((x >= (int)32768))))){
			HX_STACK_LINE(238)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(239)
		this->writeUInt16((int(x) & int((int)65535)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt16,(void))

Void Output_obj::writeInt8( int x){
{
		HX_STACK_PUSH("Output::writeInt8","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",231);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(232)
		if (((bool((x < (int)-128)) || bool((x >= (int)128))))){
			HX_STACK_LINE(233)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_STACK_LINE(234)
		this->writeByte((int(x) & int((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt8,(void))

Void Output_obj::writeDouble( Float x){
{
		HX_STACK_PUSH("Output::writeDouble","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",154);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(154)
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_double_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeDouble,(void))

Void Output_obj::writeFloat( Float x){
{
		HX_STACK_PUSH("Output::writeFloat","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(100)
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_float_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeFloat,(void))

Void Output_obj::writeFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_STACK_PUSH("Output::writeFullBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(92)
		while(((len > (int)0))){
			HX_STACK_LINE(94)
			int k = this->writeBytes(s,pos,len);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(95)
			hx::AddEq(pos,k);
			HX_STACK_LINE(96)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeFullBytes,(void))

Void Output_obj::write( ::haxe::io::Bytes s){
{
		HX_STACK_PUSH("Output::write","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(82)
		int l = s->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(83)
		int p = (int)0;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(84)
		while(((l > (int)0))){
			HX_STACK_LINE(85)
			int k = this->writeBytes(s,p,l);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(86)
			if (((k == (int)0))){
				HX_STACK_LINE(86)
				hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
			}
			HX_STACK_LINE(87)
			hx::AddEq(p,k);
			HX_STACK_LINE(88)
			hx::SubEq(l,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,write,(void))

bool Output_obj::setEndian( bool b){
	HX_STACK_PUSH("Output::setEndian","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",74);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(75)
	this->bigEndian = b;
	HX_STACK_LINE(76)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,setEndian,return )

Void Output_obj::close( ){
{
		HX_STACK_PUSH("Output::close","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",71);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,close,(void))

Void Output_obj::flush( ){
{
		HX_STACK_PUSH("Output::flush","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",68);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,flush,(void))

int Output_obj::writeBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_STACK_PUSH("Output::writeBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(46)
	int k = len;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(47)
	Array< unsigned char > b = s->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(49)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_STACK_LINE(50)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_STACK_LINE(52)
	while(((k > (int)0))){
		HX_STACK_LINE(58)
		this->writeByte(b->__get(pos));
		HX_STACK_LINE(62)
		(pos)++;
		HX_STACK_LINE(63)
		(k)--;
	}
	HX_STACK_LINE(65)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeBytes,return )

Void Output_obj::writeByte( int c){
{
		HX_STACK_PUSH("Output::writeByte","C:\\Motion-Twin\\Haxe/std/haxe/io/Output.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(41)
		hx::Throw (HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeByte,(void))

Float Output_obj::LN2;

Dynamic Output_obj::_float_bytes;

Dynamic Output_obj::_double_bytes;


Output_obj::Output_obj()
{
}

void Output_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Output);
	HX_MARK_MEMBER_NAME(bigEndian,"bigEndian");
	HX_MARK_END_CLASS();
}

void Output_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bigEndian,"bigEndian");
}

Dynamic Output_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"LN2") ) { return LN2; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prepare") ) { return prepare_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeInt8") ) { return writeInt8_dyn(); }
		if (HX_FIELD_EQ(inName,"setEndian") ) { return setEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeInput") ) { return writeInput_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt32") ) { return writeInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt31") ) { return writeInt31_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt24") ) { return writeInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt16") ) { return writeInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"writeString") ) { return writeString_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt30") ) { return writeUInt30_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt24") ) { return writeUInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt16") ) { return writeUInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { return _float_bytes; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { return _double_bytes; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"writeFullBytes") ) { return writeFullBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Output_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"LN2") ) { LN2=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { if (inCallProp) return setEndian(inValue);bigEndian=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Output_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("LN2"),
	HX_CSTRING("_float_bytes"),
	HX_CSTRING("_double_bytes"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("writeString"),
	HX_CSTRING("writeInput"),
	HX_CSTRING("prepare"),
	HX_CSTRING("writeInt32"),
	HX_CSTRING("writeUInt30"),
	HX_CSTRING("writeInt31"),
	HX_CSTRING("writeUInt24"),
	HX_CSTRING("writeInt24"),
	HX_CSTRING("writeUInt16"),
	HX_CSTRING("writeInt16"),
	HX_CSTRING("writeInt8"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeFullBytes"),
	HX_CSTRING("write"),
	HX_CSTRING("setEndian"),
	HX_CSTRING("close"),
	HX_CSTRING("flush"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("bigEndian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Output_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Output_obj::LN2,"LN2");
	HX_MARK_MEMBER_NAME(Output_obj::_float_bytes,"_float_bytes");
	HX_MARK_MEMBER_NAME(Output_obj::_double_bytes,"_double_bytes");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Output_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Output_obj::LN2,"LN2");
	HX_VISIT_MEMBER_NAME(Output_obj::_float_bytes,"_float_bytes");
	HX_VISIT_MEMBER_NAME(Output_obj::_double_bytes,"_double_bytes");
};

Class Output_obj::__mClass;

void Output_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Output"), hx::TCanCast< Output_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Output_obj::__boot()
{
	LN2= ::Math_obj::log((int)2);
	_float_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_bytes"),(int)2);
	_double_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_bytes"),(int)2);
}

} // end namespace haxe
} // end namespace io
