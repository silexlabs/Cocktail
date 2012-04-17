#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
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
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
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
namespace haxe{
namespace io{

Void Input_obj::__construct()
{
	return null();
}

Input_obj::~Input_obj() { }

Dynamic Input_obj::__CreateEmpty() { return  new Input_obj; }
hx::ObjectPtr< Input_obj > Input_obj::__new()
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

Dynamic Input_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

int Input_obj::readByte( ){
	HX_SOURCE_PUSH("Input_obj::readByte")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",37)
	hx::Throw (HX_CSTRING("Not implemented"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",38)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readByte,return )

int Input_obj::readBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_SOURCE_PUSH("Input_obj::readBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",45)
	int k = len;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",46)
	Array< unsigned char > b = s->b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",47)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",48)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",49)
	while(((k > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",55)
		b[pos] = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",59)
		(pos)++;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",60)
		(k)--;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",62)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readBytes,return )

Void Input_obj::close( ){
{
		HX_SOURCE_PUSH("Input_obj::close")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,close,(void))

bool Input_obj::setEndian( bool b){
	HX_SOURCE_PUSH("Input_obj::setEndian")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",69)
	this->bigEndian = b;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",70)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,setEndian,return )

::haxe::io::Bytes Input_obj::readAll( Dynamic bufsize){
	HX_SOURCE_PUSH("Input_obj::readAll")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",76)
	if (((bufsize == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",80)
		bufsize = (int)16384;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",82)
	::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",83)
	::haxe::io::BytesBuffer total = ::haxe::io::BytesBuffer_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",84)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",84)
		while((true)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",86)
			int len = this->readBytes(buf,(int)0,bufsize);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",87)
			if (((len == (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",88)
				hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
				Array< unsigned char > b1 = total->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
				Array< unsigned char > b2 = buf->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
					int _g1 = (int)0;
					int _g = len;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",89)
						total->b->push(b2->__get(i));
					}
				}
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
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",93)
	return total->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readAll,return )

Void Input_obj::readFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_SOURCE_PUSH("Input_obj::readFullBytes")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",96)
		while(((len > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",98)
			int k = this->readBytes(s,pos,len);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",99)
			hx::AddEq(pos,k);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",100)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readFullBytes,(void))

::haxe::io::Bytes Input_obj::read( int nbytes){
	HX_SOURCE_PUSH("Input_obj::read")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",105)
	::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc(nbytes);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",106)
	int p = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",107)
	while(((nbytes > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",108)
		int k = this->readBytes(s,p,nbytes);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",109)
		if (((k == (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",109)
			hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",110)
		hx::AddEq(p,k);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",111)
		hx::SubEq(nbytes,k);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",113)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,read,return )

::String Input_obj::readUntil( int end){
	HX_SOURCE_PUSH("Input_obj::readUntil")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",117)
	::StringBuf buf = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",118)
	int last;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",119)
	while((((last = this->readByte()) != end))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",120)
		hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode(last);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",121)
	return buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readUntil,return )

::String Input_obj::readLine( ){
	HX_SOURCE_PUSH("Input_obj::readLine")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",125)
	::StringBuf buf = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",126)
	int last;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",127)
	::String s;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",128)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",129)
		while((((last = this->readByte()) != (int)10))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",130)
			hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode(last);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",131)
		s = buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",132)
		if (((s.charCodeAt((s.length - (int)1)) == (int)13))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",132)
			s = s.substr((int)0,(int)-1);
		}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::haxe::io::Eof >() ){
			::haxe::io::Eof e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",134)
				s = buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",135)
				if (((s.length == (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",136)
					hx::Throw (e);
				}
			}
		}
		else throw(__e);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",138)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readLine,return )

double Input_obj::readFloat( ){
	HX_SOURCE_PUSH("Input_obj::readFloat")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",141)
	return ::haxe::io::Input_obj::_float_of_bytes(this->read((int)4)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readFloat,return )

double Input_obj::readDouble( ){
	HX_SOURCE_PUSH("Input_obj::readDouble")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",155)
	return ::haxe::io::Input_obj::_double_of_bytes(this->read((int)8)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readDouble,return )

int Input_obj::readInt8( ){
	HX_SOURCE_PUSH("Input_obj::readInt8")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",170)
	int n = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",171)
	if (((n >= (int)128))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",172)
		return (n - (int)256);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",173)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt8,return )

int Input_obj::readInt16( ){
	HX_SOURCE_PUSH("Input_obj::readInt16")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",177)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",178)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",179)
	int n = (  ((this->bigEndian)) ? int((int(ch2) | int((int(ch1) << int((int)8))))) : int((int(ch1) | int((int(ch2) << int((int)8))))) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",180)
	if (((((int(n) & int((int)32768))) != (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",181)
		return (n - (int)65536);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",182)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt16,return )

int Input_obj::readUInt16( ){
	HX_SOURCE_PUSH("Input_obj::readUInt16")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",186)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",187)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",188)
	return (  ((this->bigEndian)) ? int((int(ch2) | int((int(ch1) << int((int)8))))) : int((int(ch1) | int((int(ch2) << int((int)8))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt16,return )

int Input_obj::readInt24( ){
	HX_SOURCE_PUSH("Input_obj::readInt24")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",192)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",193)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",194)
	int ch3 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",195)
	int n = (  ((this->bigEndian)) ? int((int((int(ch3) | int((int(ch2) << int((int)8))))) | int((int(ch1) << int((int)16))))) : int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",196)
	if (((((int(n) & int((int)8388608))) != (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",197)
		return (n - (int)16777216);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",198)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt24,return )

int Input_obj::readUInt24( ){
	HX_SOURCE_PUSH("Input_obj::readUInt24")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",202)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",203)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",204)
	int ch3 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",205)
	return (  ((this->bigEndian)) ? int((int((int(ch3) | int((int(ch2) << int((int)8))))) | int((int(ch1) << int((int)16))))) : int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt24,return )

int Input_obj::readInt31( ){
	HX_SOURCE_PUSH("Input_obj::readInt31")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",209)
	int ch1;
	int ch2;
	int ch3;
	int ch4;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",210)
	if ((this->bigEndian)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",211)
		ch4 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",212)
		ch3 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",213)
		ch2 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",214)
		ch1 = this->readByte();
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",216)
		ch1 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",217)
		ch2 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",218)
		ch3 = this->readByte();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",219)
		ch4 = this->readByte();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",221)
	if ((((((int(ch4) & int((int)128))) == (int)0) != ((((int(ch4) & int((int)64))) == (int)0))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",221)
		hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",222)
	return (int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) | int((int(ch4) << int((int)24))));
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt31,return )

int Input_obj::readUInt30( ){
	HX_SOURCE_PUSH("Input_obj::readUInt30")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",226)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",227)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",228)
	int ch3 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",229)
	int ch4 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",230)
	if (((((  ((this->bigEndian)) ? int(ch1) : int(ch4) )) >= (int)64))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",230)
		hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",231)
	return (  ((this->bigEndian)) ? int((int((int((int(ch4) | int((int(ch3) << int((int)8))))) | int((int(ch2) << int((int)16))))) | int((int(ch1) << int((int)24))))) : int((int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) | int((int(ch4) << int((int)24))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt30,return )

::cpp::CppInt32__ Input_obj::readInt32( ){
	HX_SOURCE_PUSH("Input_obj::readInt32")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",235)
	int ch1 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",236)
	int ch2 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",237)
	int ch3 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",238)
	int ch4 = this->readByte();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",245)
	return (  ((this->bigEndian)) ? ::cpp::CppInt32__(::cpp::CppInt32___obj::make((int((int(ch1) << int((int)8))) | int(ch2)),(int((int(ch3) << int((int)8))) | int(ch4)))) : ::cpp::CppInt32__(::cpp::CppInt32___obj::make((int((int(ch4) << int((int)8))) | int(ch3)),(int((int(ch2) << int((int)8))) | int(ch1)))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt32,return )

::String Input_obj::readString( int len){
	HX_SOURCE_PUSH("Input_obj::readString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",250)
	::haxe::io::Bytes b = ::haxe::io::Bytes_obj::alloc(len);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",251)
	this->readFullBytes(b,(int)0,len);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/io/Input.hx",255)
	return b->toString();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readString,return )

Dynamic Input_obj::_float_of_bytes;

Dynamic Input_obj::_double_of_bytes;


Input_obj::Input_obj()
{
}

void Input_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Input);
	HX_MARK_MEMBER_NAME(bigEndian,"bigEndian");
	HX_MARK_END_CLASS();
}

Dynamic Input_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"readAll") ) { return readAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"readLine") ) { return readLine_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt8") ) { return readInt8_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"setEndian") ) { return setEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"readUntil") ) { return readUntil_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt16") ) { return readInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt24") ) { return readInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt31") ) { return readInt31_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt32") ) { return readInt32_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt16") ) { return readUInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt24") ) { return readUInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt30") ) { return readUInt30_dyn(); }
		if (HX_FIELD_EQ(inName,"readString") ) { return readString_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readFullBytes") ) { return readFullBytes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { return _float_of_bytes; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { return _double_of_bytes; }
	}
	return super::__Field(inName);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return setEndian(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Input_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_float_of_bytes"),
	HX_CSTRING("_double_of_bytes"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bigEndian"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("close"),
	HX_CSTRING("setEndian"),
	HX_CSTRING("readAll"),
	HX_CSTRING("readFullBytes"),
	HX_CSTRING("read"),
	HX_CSTRING("readUntil"),
	HX_CSTRING("readLine"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readInt8"),
	HX_CSTRING("readInt16"),
	HX_CSTRING("readUInt16"),
	HX_CSTRING("readInt24"),
	HX_CSTRING("readUInt24"),
	HX_CSTRING("readInt31"),
	HX_CSTRING("readUInt30"),
	HX_CSTRING("readInt32"),
	HX_CSTRING("readString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Input_obj::_float_of_bytes,"_float_of_bytes");
	HX_MARK_MEMBER_NAME(Input_obj::_double_of_bytes,"_double_of_bytes");
};

Class Input_obj::__mClass;

void Input_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Input"), hx::TCanCast< Input_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Input_obj::__boot()
{
	hx::Static(_float_of_bytes) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_of_bytes"),(int)2);
	hx::Static(_double_of_bytes) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_of_bytes"),(int)2);
}

} // end namespace haxe
} // end namespace io
