#include <hxcpp.h>

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

Void Output_obj::writeByte( int c){
{
		HX_SOURCE_PUSH("Output_obj::writeByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",37)
		hx::Throw (HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeByte,(void))

int Output_obj::writeBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_SOURCE_PUSH("Output_obj::writeBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",42)
	int k = len;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",43)
	Array< unsigned char > b = s->b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",45)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",46)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",48)
	while(((k > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",54)
		this->writeByte(b->__get(pos));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",58)
		(pos)++;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",59)
		(k)--;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",61)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeBytes,return )

Void Output_obj::flush( ){
{
		HX_SOURCE_PUSH("Output_obj::flush")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,flush,(void))

Void Output_obj::close( ){
{
		HX_SOURCE_PUSH("Output_obj::close")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,close,(void))

bool Output_obj::setEndian( bool b){
	HX_SOURCE_PUSH("Output_obj::setEndian")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",71)
	this->bigEndian = b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",72)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,setEndian,return )

Void Output_obj::write( ::haxe::io::Bytes s){
{
		HX_SOURCE_PUSH("Output_obj::write")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",78)
		int l = s->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",79)
		int p = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",80)
		while(((l > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",81)
			int k = this->writeBytes(s,p,l);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",82)
			if (((k == (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",82)
				hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",83)
			hx::AddEq(p,k);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",84)
			hx::SubEq(l,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,write,(void))

Void Output_obj::writeFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_SOURCE_PUSH("Output_obj::writeFullBytes")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",88)
		while(((len > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",90)
			int k = this->writeBytes(s,pos,len);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",91)
			hx::AddEq(pos,k);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",92)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeFullBytes,(void))

Void Output_obj::writeFloat( double x){
{
		HX_SOURCE_PUSH("Output_obj::writeFloat")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",96)
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_float_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeFloat,(void))

Void Output_obj::writeDouble( double x){
{
		HX_SOURCE_PUSH("Output_obj::writeDouble")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",108)
		this->write(::haxe::io::Bytes_obj::ofData(::haxe::io::Output_obj::_double_bytes(x,this->bigEndian)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeDouble,(void))

Void Output_obj::writeInt8( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeInt8")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",121)
		if (((bool((x < (int)-128)) || bool((x >= (int)128))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",122)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",123)
		this->writeByte((int(x) & int((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt8,(void))

Void Output_obj::writeInt16( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeInt16")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",127)
		if (((bool((x < (int)-32768)) || bool((x >= (int)32768))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",127)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",128)
		this->writeUInt16((int(x) & int((int)65535)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt16,(void))

Void Output_obj::writeUInt16( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeUInt16")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",132)
		if (((bool((x < (int)0)) || bool((x >= (int)65536))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",132)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",133)
		if ((this->bigEndian)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",134)
			this->writeByte((int(x) >> int((int)8)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",135)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",137)
			this->writeByte((int(x) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",138)
			this->writeByte((int(x) >> int((int)8)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt16,(void))

Void Output_obj::writeInt24( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeInt24")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",143)
		if (((bool((x < (int)-8388608)) || bool((x >= (int)8388608))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",143)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",144)
		this->writeUInt24((int(x) & int((int)16777215)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt24,(void))

Void Output_obj::writeUInt24( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeUInt24")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",148)
		if (((bool((x < (int)0)) || bool((x >= (int)16777216))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",148)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",149)
		if ((this->bigEndian)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",150)
			this->writeByte((int(x) >> int((int)16)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",151)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",152)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",154)
			this->writeByte((int(x) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",155)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",156)
			this->writeByte((int(x) >> int((int)16)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt24,(void))

Void Output_obj::writeInt31( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeInt31")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",162)
		if (((bool((x < (int)-1073741824)) || bool((x >= (int)1073741824))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",162)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",164)
		if ((this->bigEndian)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",165)
			this->writeByte(hx::UShr(x,(int)24));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",166)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",167)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",168)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",170)
			this->writeByte((int(x) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",171)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",172)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",173)
			this->writeByte(hx::UShr(x,(int)24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt31,(void))

Void Output_obj::writeUInt30( int x){
{
		HX_SOURCE_PUSH("Output_obj::writeUInt30")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",178)
		if (((bool((x < (int)0)) || bool((x >= (int)1073741824))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",178)
			hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",179)
		if ((this->bigEndian)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",180)
			this->writeByte(hx::UShr(x,(int)24));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",181)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",182)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",183)
			this->writeByte((int(x) & int((int)255)));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",185)
			this->writeByte((int(x) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",186)
			this->writeByte((int((int(x) >> int((int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",187)
			this->writeByte((int((int(x) >> int((int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",188)
			this->writeByte(hx::UShr(x,(int)24));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeUInt30,(void))

Void Output_obj::writeInt32( ::cpp::CppInt32__ x){
{
		HX_SOURCE_PUSH("Output_obj::writeInt32")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",192)
		if ((this->bigEndian)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",194)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)24)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",195)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",196)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",197)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt((int)255))));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",199)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::_and(x,::cpp::CppInt32___obj::ofInt((int)255))));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",200)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)8))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",201)
			this->writeByte((int(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)16))) & int((int)255)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",202)
			this->writeByte(::cpp::CppInt32___obj::toInt(::cpp::CppInt32___obj::ushr(x,(int)24)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeInt32,(void))

Void Output_obj::prepare( int nbytes){
{
		HX_SOURCE_PUSH("Output_obj::prepare")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,prepare,(void))

Void Output_obj::writeInput( ::haxe::io::Input i,Dynamic bufsize){
{
		HX_SOURCE_PUSH("Output_obj::writeInput")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",216)
		if (((bufsize == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",217)
			bufsize = (int)4096;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",218)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",219)
		try{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",219)
			while((true)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",221)
				int len = i->readBytes(buf,(int)0,bufsize);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",222)
				if (((len == (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",223)
					hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",224)
				int p = (int)0;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",225)
				while(((len > (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",226)
					int k = this->writeBytes(buf,p,len);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",227)
					if (((k == (int)0))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",228)
						hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",229)
					hx::AddEq(p,k);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",230)
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

Void Output_obj::writeString( ::String s){
{
		HX_SOURCE_PUSH("Output_obj::writeString")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",241)
		::haxe::io::Bytes b = ::haxe::io::Bytes_obj::ofString(s);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Output.hx",243)
		this->writeFullBytes(b,(int)0,b->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeString,(void))

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

Dynamic Output_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prepare") ) { return prepare_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		if (HX_FIELD_EQ(inName,"setEndian") ) { return setEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt8") ) { return writeInt8_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt16") ) { return writeInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt24") ) { return writeInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt31") ) { return writeInt31_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt32") ) { return writeInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInput") ) { return writeInput_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt16") ) { return writeUInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt24") ) { return writeUInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUInt30") ) { return writeUInt30_dyn(); }
		if (HX_FIELD_EQ(inName,"writeString") ) { return writeString_dyn(); }
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
	return super::__Field(inName);
}

Dynamic Output_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return setEndian(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Output_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_float_bytes"),
	HX_CSTRING("_double_bytes"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bigEndian"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("flush"),
	HX_CSTRING("close"),
	HX_CSTRING("setEndian"),
	HX_CSTRING("write"),
	HX_CSTRING("writeFullBytes"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeInt8"),
	HX_CSTRING("writeInt16"),
	HX_CSTRING("writeUInt16"),
	HX_CSTRING("writeInt24"),
	HX_CSTRING("writeUInt24"),
	HX_CSTRING("writeInt31"),
	HX_CSTRING("writeUInt30"),
	HX_CSTRING("writeInt32"),
	HX_CSTRING("prepare"),
	HX_CSTRING("writeInput"),
	HX_CSTRING("writeString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Output_obj::_float_bytes,"_float_bytes");
	HX_MARK_MEMBER_NAME(Output_obj::_double_bytes,"_double_bytes");
};

Class Output_obj::__mClass;

void Output_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Output"), hx::TCanCast< Output_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Output_obj::__boot()
{
	hx::Static(_float_bytes) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_bytes"),(int)2);
	hx::Static(_double_bytes) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_bytes"),(int)2);
}

} // end namespace haxe
} // end namespace io
