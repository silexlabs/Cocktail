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

::String Input_obj::readString( int len){
	HX_STACK_PUSH("Input::readString","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",408);
	HX_STACK_THIS(this);
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(409)
	::haxe::io::Bytes b = ::haxe::io::Bytes_obj::alloc(len);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(410)
	this->readFullBytes(b,(int)0,len);
	HX_STACK_LINE(414)
	return b->toString();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readString,return )

::cpp::CppInt32__ Input_obj::readInt32( ){
	HX_STACK_PUSH("Input::readInt32","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",393);
	HX_STACK_THIS(this);
	HX_STACK_LINE(394)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(395)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(396)
	int ch3 = this->readByte();		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(397)
	int ch4 = this->readByte();		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(404)
	return (  ((this->bigEndian)) ? ::cpp::CppInt32__(::cpp::CppInt32___obj::make((int((int(ch1) << int((int)8))) | int(ch2)),(int((int(ch3) << int((int)8))) | int(ch4)))) : ::cpp::CppInt32__(::cpp::CppInt32___obj::make((int((int(ch4) << int((int)8))) | int(ch3)),(int((int(ch2) << int((int)8))) | int(ch1)))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt32,return )

int Input_obj::readUInt30( ){
	HX_STACK_PUSH("Input::readUInt30","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",384);
	HX_STACK_THIS(this);
	HX_STACK_LINE(385)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(386)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(387)
	int ch3 = this->readByte();		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(388)
	int ch4 = this->readByte();		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(389)
	if (((((  ((this->bigEndian)) ? int(ch1) : int(ch4) )) >= (int)64))){
		HX_STACK_LINE(389)
		hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
	}
	HX_STACK_LINE(390)
	return (  ((this->bigEndian)) ? int((int((int((int(ch4) | int((int(ch3) << int((int)8))))) | int((int(ch2) << int((int)16))))) | int((int(ch1) << int((int)24))))) : int((int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) | int((int(ch4) << int((int)24))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt30,return )

int Input_obj::readInt31( ){
	HX_STACK_PUSH("Input::readInt31","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",367);
	HX_STACK_THIS(this);
	HX_STACK_LINE(368)
	int ch1;		HX_STACK_VAR(ch1,"ch1");
	int ch2;		HX_STACK_VAR(ch2,"ch2");
	int ch3;		HX_STACK_VAR(ch3,"ch3");
	int ch4;		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(369)
	if ((this->bigEndian)){
		HX_STACK_LINE(370)
		ch4 = this->readByte();
		HX_STACK_LINE(371)
		ch3 = this->readByte();
		HX_STACK_LINE(372)
		ch2 = this->readByte();
		HX_STACK_LINE(373)
		ch1 = this->readByte();
	}
	else{
		HX_STACK_LINE(375)
		ch1 = this->readByte();
		HX_STACK_LINE(376)
		ch2 = this->readByte();
		HX_STACK_LINE(377)
		ch3 = this->readByte();
		HX_STACK_LINE(378)
		ch4 = this->readByte();
	}
	HX_STACK_LINE(380)
	if ((((((int(ch4) & int((int)128))) == (int)0) != ((((int(ch4) & int((int)64))) == (int)0))))){
		HX_STACK_LINE(380)
		hx::Throw (::haxe::io::Error_obj::Overflow_dyn());
	}
	HX_STACK_LINE(381)
	return (int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) | int((int(ch4) << int((int)24))));
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt31,return )

int Input_obj::readUInt24( ){
	HX_STACK_PUSH("Input::readUInt24","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",360);
	HX_STACK_THIS(this);
	HX_STACK_LINE(361)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(362)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(363)
	int ch3 = this->readByte();		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(364)
	return (  ((this->bigEndian)) ? int((int((int(ch3) | int((int(ch2) << int((int)8))))) | int((int(ch1) << int((int)16))))) : int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt24,return )

int Input_obj::readInt24( ){
	HX_STACK_PUSH("Input::readInt24","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",350);
	HX_STACK_THIS(this);
	HX_STACK_LINE(351)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(352)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(353)
	int ch3 = this->readByte();		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(354)
	int n = (  ((this->bigEndian)) ? int((int((int(ch3) | int((int(ch2) << int((int)8))))) | int((int(ch1) << int((int)16))))) : int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) );		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(355)
	if (((((int(n) & int((int)8388608))) != (int)0))){
		HX_STACK_LINE(356)
		return (n - (int)16777216);
	}
	HX_STACK_LINE(357)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt24,return )

int Input_obj::readUInt16( ){
	HX_STACK_PUSH("Input::readUInt16","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",344);
	HX_STACK_THIS(this);
	HX_STACK_LINE(345)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(346)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(347)
	return (  ((this->bigEndian)) ? int((int(ch2) | int((int(ch1) << int((int)8))))) : int((int(ch1) | int((int(ch2) << int((int)8))))) );
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readUInt16,return )

int Input_obj::readInt16( ){
	HX_STACK_PUSH("Input::readInt16","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",335);
	HX_STACK_THIS(this);
	HX_STACK_LINE(336)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(337)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(338)
	int n = (  ((this->bigEndian)) ? int((int(ch2) | int((int(ch1) << int((int)8))))) : int((int(ch1) | int((int(ch2) << int((int)8))))) );		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(339)
	if (((((int(n) & int((int)32768))) != (int)0))){
		HX_STACK_LINE(340)
		return (n - (int)65536);
	}
	HX_STACK_LINE(341)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt16,return )

int Input_obj::readInt8( ){
	HX_STACK_PUSH("Input::readInt8","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",328);
	HX_STACK_THIS(this);
	HX_STACK_LINE(329)
	int n = this->readByte();		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(330)
	if (((n >= (int)128))){
		HX_STACK_LINE(331)
		return (n - (int)256);
	}
	HX_STACK_LINE(332)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt8,return )

Float Input_obj::readDouble( ){
	HX_STACK_PUSH("Input::readDouble","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",255);
	HX_STACK_THIS(this);
	HX_STACK_LINE(255)
	return ::haxe::io::Input_obj::_double_of_bytes(this->read((int)8)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readDouble,return )

Float Input_obj::readFloat( ){
	HX_STACK_PUSH("Input::readFloat","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_LINE(201)
	return ::haxe::io::Input_obj::_float_of_bytes(this->read((int)4)->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readFloat,return )

::String Input_obj::readLine( ){
	HX_STACK_PUSH("Input::readLine","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",184);
	HX_STACK_THIS(this);
	HX_STACK_LINE(185)
	::StringBuf buf = ::StringBuf_obj::__new();		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(186)
	int last;		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(187)
	::String s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(188)
	try{
		HX_STACK_LINE(189)
		while((((last = this->readByte()) != (int)10))){
			HX_STACK_LINE(190)
			hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode(last);
		}
		HX_STACK_LINE(191)
		s = buf->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
		HX_STACK_LINE(192)
		if (((s.charCodeAt((s.length - (int)1)) == (int)13))){
			HX_STACK_LINE(192)
			s = s.substr((int)0,(int)-1);
		}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::haxe::io::Eof >() ){
			::haxe::io::Eof e = __e;{
				HX_STACK_LINE(194)
				s = buf->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
				HX_STACK_LINE(195)
				if (((s.length == (int)0))){
					HX_STACK_LINE(196)
					hx::Throw (e);
				}
			}
		}
		else throw(__e);
	}
	HX_STACK_LINE(198)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readLine,return )

::String Input_obj::readUntil( int end){
	HX_STACK_PUSH("Input::readUntil","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",176);
	HX_STACK_THIS(this);
	HX_STACK_ARG(end,"end");
	HX_STACK_LINE(177)
	::StringBuf buf = ::StringBuf_obj::__new();		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(178)
	int last;		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(179)
	while((((last = this->readByte()) != end))){
		HX_STACK_LINE(180)
		hx::IndexRef((buf->b).mPtr,buf->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode(last);
	}
	HX_STACK_LINE(181)
	return buf->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readUntil,return )

::haxe::io::Bytes Input_obj::read( int nbytes){
	HX_STACK_PUSH("Input::read","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",164);
	HX_STACK_THIS(this);
	HX_STACK_ARG(nbytes,"nbytes");
	HX_STACK_LINE(165)
	::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc(nbytes);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(166)
	int p = (int)0;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(167)
	while(((nbytes > (int)0))){
		HX_STACK_LINE(168)
		int k = this->readBytes(s,p,nbytes);		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(169)
		if (((k == (int)0))){
			HX_STACK_LINE(169)
			hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
		}
		HX_STACK_LINE(170)
		hx::AddEq(p,k);
		HX_STACK_LINE(171)
		hx::SubEq(nbytes,k);
	}
	HX_STACK_LINE(173)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,read,return )

Void Input_obj::readFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_STACK_PUSH("Input::readFullBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(156)
		while(((len > (int)0))){
			HX_STACK_LINE(158)
			int k = this->readBytes(s,pos,len);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(159)
			hx::AddEq(pos,k);
			HX_STACK_LINE(160)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readFullBytes,(void))

::haxe::io::Bytes Input_obj::readAll( Dynamic bufsize){
	HX_STACK_PUSH("Input::readAll","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bufsize,"bufsize");
	HX_STACK_LINE(81)
	if (((bufsize == null()))){
		HX_STACK_LINE(85)
		bufsize = (int)16384;
	}
	HX_STACK_LINE(141)
	::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(142)
	::haxe::io::BytesBuffer total = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(total,"total");
	HX_STACK_LINE(143)
	try{
		HX_STACK_LINE(143)
		while((true)){
			HX_STACK_LINE(145)
			int len = this->readBytes(buf,(int)0,bufsize);		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(146)
			if (((len == (int)0))){
				HX_STACK_LINE(147)
				hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
			}
			HX_STACK_LINE(148)
			{
				HX_STACK_LINE(148)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_STACK_LINE(148)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_STACK_LINE(148)
				Array< unsigned char > b1 = total->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(148)
				Array< unsigned char > b2 = buf->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(148)
				{
					HX_STACK_LINE(148)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = len;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(148)
					while(((_g1 < _g))){
						HX_STACK_LINE(148)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(148)
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
	HX_STACK_LINE(152)
	return total->getBytes();
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,readAll,return )

bool Input_obj::setEndian( bool b){
	HX_STACK_PUSH("Input::setEndian","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(74)
	this->bigEndian = b;
	HX_STACK_LINE(75)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,setEndian,return )

Void Input_obj::close( ){
{
		HX_STACK_PUSH("Input::close","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",70);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,close,(void))

int Input_obj::readBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_STACK_PUSH("Input::readBytes","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(50)
	int k = len;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(51)
	Array< unsigned char > b = s->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(52)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_STACK_LINE(53)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
	}
	HX_STACK_LINE(54)
	while(((k > (int)0))){
		HX_STACK_LINE(60)
		b[pos] = this->readByte();
		HX_STACK_LINE(64)
		(pos)++;
		HX_STACK_LINE(65)
		(k)--;
	}
	HX_STACK_LINE(67)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Input_obj,readBytes,return )

int Input_obj::readByte( ){
	HX_STACK_PUSH("Input::readByte","C:\\Motion-Twin\\Haxe/std/haxe/io/Input.hx",40);
	HX_STACK_THIS(this);
	HX_STACK_LINE(42)
	hx::Throw (HX_CSTRING("Not implemented"));
	HX_STACK_LINE(43)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readByte,return )

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

void Input_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bigEndian,"bigEndian");
}

Dynamic Input_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"readInt8") ) { return readInt8_dyn(); }
		if (HX_FIELD_EQ(inName,"readLine") ) { return readLine_dyn(); }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readInt32") ) { return readInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt31") ) { return readInt31_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt24") ) { return readInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt16") ) { return readInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readUntil") ) { return readUntil_dyn(); }
		if (HX_FIELD_EQ(inName,"setEndian") ) { return setEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readString") ) { return readString_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt30") ) { return readUInt30_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt24") ) { return readUInt24_dyn(); }
		if (HX_FIELD_EQ(inName,"readUInt16") ) { return readUInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
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
	return super::__Field(inName,inCallProp);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { if (inCallProp) return setEndian(inValue);bigEndian=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("readString"),
	HX_CSTRING("readInt32"),
	HX_CSTRING("readUInt30"),
	HX_CSTRING("readInt31"),
	HX_CSTRING("readUInt24"),
	HX_CSTRING("readInt24"),
	HX_CSTRING("readUInt16"),
	HX_CSTRING("readInt16"),
	HX_CSTRING("readInt8"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readLine"),
	HX_CSTRING("readUntil"),
	HX_CSTRING("read"),
	HX_CSTRING("readFullBytes"),
	HX_CSTRING("readAll"),
	HX_CSTRING("setEndian"),
	HX_CSTRING("close"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readByte"),
	HX_CSTRING("bigEndian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Input_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Input_obj::_float_of_bytes,"_float_of_bytes");
	HX_MARK_MEMBER_NAME(Input_obj::_double_of_bytes,"_double_of_bytes");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Input_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Input_obj::_float_of_bytes,"_float_of_bytes");
	HX_VISIT_MEMBER_NAME(Input_obj::_double_of_bytes,"_double_of_bytes");
};

Class Input_obj::__mClass;

void Input_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Input"), hx::TCanCast< Input_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Input_obj::__boot()
{
	_float_of_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_of_bytes"),(int)2);
	_double_of_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_of_bytes"),(int)2);
}

} // end namespace haxe
} // end namespace io
