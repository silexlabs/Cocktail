#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_zip_Compress
#include <cpp/zip/Compress.h>
#endif
#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_errors_EOFError
#include <neash/errors/EOFError.h>
#endif
#ifndef INCLUDED_neash_errors_Error
#include <neash/errors/Error.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace utils{

Void ByteArray_obj::__construct(hx::Null< int >  __o_inSize)
{
HX_STACK_PUSH("ByteArray::new","neash/utils/ByteArray.hx",35);
int inSize = __o_inSize.Default(0);
{
	HX_STACK_LINE(36)
	this->bigEndian = true;
	HX_STACK_LINE(37)
	this->position = (int)0;
	HX_STACK_LINE(38)
	if (((inSize >= (int)0))){
		HX_STACK_LINE(45)
		Array< unsigned char > data = Array_obj< unsigned char >::__new();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(46)
		if (((inSize > (int)0))){
			HX_STACK_LINE(47)
			data[(inSize - (int)1)] = (int)0;
		}
		HX_STACK_LINE(48)
		super::__construct(inSize,data);
	}
}
;
	return null();
}

ByteArray_obj::~ByteArray_obj() { }

Dynamic ByteArray_obj::__CreateEmpty() { return  new ByteArray_obj; }
hx::ObjectPtr< ByteArray_obj > ByteArray_obj::__new(hx::Null< int >  __o_inSize)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(__o_inSize);
	return result;}

Dynamic ByteArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *ByteArray_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::utils::IDataInput_obj)) return operator ::neash::utils::IDataInput_obj *();
	return super::__ToInterface(inType);
}

void ByteArray_obj::__init__() {
HX_STACK_PUSH("ByteArray::__init__","neash/utils/ByteArray.hx",68);
{

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	::neash::utils::ByteArray run(int inLen){
		HX_STACK_PUSH("*::_Function_1_1","neash/utils/ByteArray.hx",69);
		HX_STACK_ARG(inLen,"inLen");
		{
			HX_STACK_LINE(69)
			return ::neash::utils::ByteArray_obj::__new(inLen);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(69)
	Dynamic factory =  Dynamic(new _Function_1_1());		HX_STACK_VAR(factory,"factory");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::neash::utils::ByteArray inArray,int inLen){
		HX_STACK_PUSH("*::_Function_1_2","neash/utils/ByteArray.hx",70);
		HX_STACK_ARG(inArray,"inArray");
		HX_STACK_ARG(inLen,"inLen");
		{
			HX_STACK_LINE(71)
			if (((inLen > (int)0))){
				HX_STACK_LINE(72)
				inArray->__Field(HX_CSTRING("ensureElem"),true)((inLen - (int)1),true);
			}
			HX_STACK_LINE(73)
			inArray->__FieldRef(HX_CSTRING("length")) = inLen;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(70)
	Dynamic resize =  Dynamic(new _Function_1_2());		HX_STACK_VAR(resize,"resize");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
	Array< unsigned char > run(::neash::utils::ByteArray inArray){
		HX_STACK_PUSH("*::_Function_1_3","neash/utils/ByteArray.hx",75);
		HX_STACK_ARG(inArray,"inArray");
		{
			HX_STACK_LINE(75)
			return (  (((inArray == null()))) ? Array< unsigned char >(null()) : Array< unsigned char >(inArray->__Field(HX_CSTRING("b"),true)) );
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(75)
	Dynamic bytes =  Dynamic(new _Function_1_3());		HX_STACK_VAR(bytes,"bytes");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_4)
	int run(::neash::utils::ByteArray inArray){
		HX_STACK_PUSH("*::_Function_1_4","neash/utils/ByteArray.hx",76);
		HX_STACK_ARG(inArray,"inArray");
		{
			HX_STACK_LINE(76)
			return (  (((inArray == null()))) ? int((int)0) : int(inArray->__Field(HX_CSTRING("length"),true)) );
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(76)
	Dynamic slen =  Dynamic(new _Function_1_4());		HX_STACK_VAR(slen,"slen");
	HX_STACK_LINE(78)
	Dynamic init = ::neash::Loader_obj::load(HX_CSTRING("nme_byte_array_init"),(int)4);		HX_STACK_VAR(init,"init");
	HX_STACK_LINE(79)
	init(factory,slen,resize,bytes);
}
}

::String ByteArray_obj::nmeSetEndian( ::String s){
	HX_STACK_PUSH("ByteArray::nmeSetEndian","neash/utils/ByteArray.hx",487);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(487)
	this->bigEndian = (s == HX_CSTRING("bigEndian"));
	HX_STACK_LINE(487)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,nmeSetEndian,return )

::String ByteArray_obj::nmeGetEndian( ){
	HX_STACK_PUSH("ByteArray::nmeGetEndian","neash/utils/ByteArray.hx",486);
	HX_STACK_THIS(this);
	HX_STACK_LINE(486)
	return (  ((this->bigEndian)) ? ::String(HX_CSTRING("bigEndian")) : ::String(HX_CSTRING("littleEndian")) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,nmeGetEndian,return )

int ByteArray_obj::nmeGetBytesAvailable( ){
	HX_STACK_PUSH("ByteArray::nmeGetBytesAvailable","neash/utils/ByteArray.hx",485);
	HX_STACK_THIS(this);
	HX_STACK_LINE(485)
	return (this->length - this->position);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,nmeGetBytesAvailable,return )

Void ByteArray_obj::writeUTFBytes( ::String s){
{
		HX_STACK_PUSH("ByteArray::writeUTFBytes","neash/utils/ByteArray.hx",470);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(474)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(476)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTFBytes,(void))

Void ByteArray_obj::writeUTF( ::String s){
{
		HX_STACK_PUSH("ByteArray::writeUTF","neash/utils/ByteArray.hx",458);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(462)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(464)
		this->writeShort(bytes->length);
		HX_STACK_LINE(465)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTF,(void))

Void ByteArray_obj::writeUnsignedInt( int value){
{
		HX_STACK_PUSH("ByteArray::writeUnsignedInt","neash/utils/ByteArray.hx",452);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(452)
		this->writeInt(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUnsignedInt,(void))

Void ByteArray_obj::writeShort( int value){
{
		HX_STACK_PUSH("ByteArray::writeShort","neash/utils/ByteArray.hx",436);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(437)
		this->ensureElem((this->position + (int)1),true);
		HX_STACK_LINE(438)
		if ((this->bigEndian)){
			HX_STACK_LINE(440)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(441)
			this->b->__unsafe_set((this->position)++,value);
		}
		else{
			HX_STACK_LINE(445)
			this->b->__unsafe_set((this->position)++,value);
			HX_STACK_LINE(446)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeShort,(void))

Void ByteArray_obj::writeInt( int value){
{
		HX_STACK_PUSH("ByteArray::writeInt","neash/utils/ByteArray.hx",412);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(413)
		this->ensureElem((this->position + (int)3),true);
		HX_STACK_LINE(414)
		if ((this->bigEndian)){
			HX_STACK_LINE(416)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)24)));
			HX_STACK_LINE(417)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)16)));
			HX_STACK_LINE(418)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(419)
			this->b->__unsafe_set((this->position)++,value);
		}
		else{
			HX_STACK_LINE(423)
			this->b->__unsafe_set((this->position)++,value);
			HX_STACK_LINE(424)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(425)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)16)));
			HX_STACK_LINE(426)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)24)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeInt,(void))

Void ByteArray_obj::writeFloat( Float x){
{
		HX_STACK_PUSH("ByteArray::writeFloat","neash/utils/ByteArray.hx",401);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(405)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(::neash::utils::ByteArray_obj::_float_bytes(x,this->bigEndian));		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(407)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFloat,(void))

Void ByteArray_obj::writeFile( ::String inString){
{
		HX_STACK_PUSH("ByteArray::writeFile","neash/utils/ByteArray.hx",394);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inString,"inString");
		HX_STACK_LINE(394)
		::neash::utils::ByteArray_obj::nme_byte_array_overwrite_file(inString,hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFile,(void))

Void ByteArray_obj::writeDouble( Float x){
{
		HX_STACK_PUSH("ByteArray::writeDouble","neash/utils/ByteArray.hx",382);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(386)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(::neash::utils::ByteArray_obj::_double_bytes(x,this->bigEndian));		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(388)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeDouble,(void))

Void ByteArray_obj::writeBytes( ::haxe::io::Bytes bytes,hx::Null< int >  __o_inOffset,hx::Null< int >  __o_inLength){
int inOffset = __o_inOffset.Default(0);
int inLength = __o_inLength.Default(0);
	HX_STACK_PUSH("ByteArray::writeBytes","neash/utils/ByteArray.hx",372);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_ARG(inOffset,"inOffset");
	HX_STACK_ARG(inLength,"inLength");
{
		HX_STACK_LINE(373)
		if (((inLength == (int)0))){
			HX_STACK_LINE(373)
			inLength = (bytes->length - inOffset);
		}
		HX_STACK_LINE(374)
		this->ensureElem(((this->position + inLength) - (int)1),true);
		HX_STACK_LINE(375)
		int opos = this->position;		HX_STACK_VAR(opos,"opos");
		HX_STACK_LINE(376)
		hx::AddEq(this->position,inLength);
		HX_STACK_LINE(377)
		this->blit(opos,bytes,inOffset,inLength);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,writeBytes,(void))

Void ByteArray_obj::write_uncheck( int inByte){
{
		HX_STACK_PUSH("ByteArray::write_uncheck","neash/utils/ByteArray.hx",362);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inByte,"inByte");
		HX_STACK_LINE(362)
		this->b->__unsafe_set((this->position)++,inByte);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,write_uncheck,(void))

Void ByteArray_obj::writeByte( int value){
{
		HX_STACK_PUSH("ByteArray::writeByte","neash/utils/ByteArray.hx",352);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(353)
		this->ensureElem(this->position,true);
		HX_STACK_LINE(355)
		this->b[(this->position)++] = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeByte,(void))

Void ByteArray_obj::writeBoolean( bool value){
{
		HX_STACK_PUSH("ByteArray::writeBoolean","neash/utils/ByteArray.hx",347);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(347)
		{
			HX_STACK_LINE(348)
			this->ensureElem(this->position,true);
			HX_STACK_LINE(348)
			this->b[(this->position)++] = (  ((value)) ? int((int)1) : int((int)0) );
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeBoolean,(void))

Void ByteArray_obj::uncompress( ::String __o_algorithm){
::String algorithm = __o_algorithm.Default(HX_CSTRING(""));
	HX_STACK_PUSH("ByteArray::uncompress","neash/utils/ByteArray.hx",329);
	HX_STACK_THIS(this);
	HX_STACK_ARG(algorithm,"algorithm");
{
		HX_STACK_LINE(333)
		::neash::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(336)
		::haxe::io::Bytes result = ::cpp::zip::Uncompress_obj::run(src,null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(337)
		this->b = result->b;
		HX_STACK_LINE(338)
		this->length = result->length;
		HX_STACK_LINE(339)
		this->position = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,uncompress,(void))

int ByteArray_obj::ThrowEOFi( ){
	HX_STACK_PUSH("ByteArray::ThrowEOFi","neash/utils/ByteArray.hx",322);
	HX_STACK_THIS(this);
	HX_STACK_LINE(323)
	hx::Throw (::neash::errors::EOFError_obj::__new());
	HX_STACK_LINE(324)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,ThrowEOFi,return )

Void ByteArray_obj::setLength( int inLength){
{
		HX_STACK_PUSH("ByteArray::setLength","neash/utils/ByteArray.hx",314);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inLength,"inLength");
		HX_STACK_LINE(315)
		if (((inLength > (int)0))){
			HX_STACK_LINE(316)
			this->ensureElem((inLength - (int)1),false);
		}
		HX_STACK_LINE(317)
		this->length = inLength;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,setLength,(void))

::String ByteArray_obj::readUTFBytes( int inLen){
	HX_STACK_PUSH("ByteArray::readUTFBytes","neash/utils/ByteArray.hx",297);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inLen,"inLen");
	HX_STACK_LINE(298)
	if ((((this->position + inLen) > this->length))){
		HX_STACK_LINE(299)
		this->ThrowEOFi();
	}
	HX_STACK_LINE(300)
	int p = this->position;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(301)
	hx::AddEq(this->position,inLen);
	HX_STACK_LINE(306)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(307)
	::__hxcpp_string_of_bytes(this->b,result,p,inLen);
	HX_STACK_LINE(308)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readUTFBytes,return )

::String ByteArray_obj::readUTF( ){
	HX_STACK_PUSH("ByteArray::readUTF","neash/utils/ByteArray.hx",290);
	HX_STACK_THIS(this);
	HX_STACK_LINE(291)
	int len = this->readUnsignedShort();		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(292)
	return this->readUTFBytes(len);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUTF,return )

int ByteArray_obj::readUnsignedShort( ){
	HX_STACK_PUSH("ByteArray::readUnsignedShort","neash/utils/ByteArray.hx",282);
	HX_STACK_THIS(this);
	HX_STACK_LINE(283)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(284)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(285)
	return (  ((this->bigEndian)) ? int((int((int(ch1) << int((int)8))) | int(ch2))) : int((((int(ch2) << int((int)8))) + ch1)) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedShort,return )

int ByteArray_obj::readUnsignedInt( ){
	HX_STACK_PUSH("ByteArray::readUnsignedInt","neash/utils/ByteArray.hx",272);
	HX_STACK_THIS(this);
	HX_STACK_LINE(273)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(274)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(275)
	int ch3 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(276)
	int ch4 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(277)
	return (  ((this->bigEndian)) ? int((int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4))) : int((int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1))) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedInt,return )

int ByteArray_obj::readUnsignedByte( ){
	HX_STACK_PUSH("ByteArray::readUnsignedByte","neash/utils/ByteArray.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_LINE(266)
	return (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedByte,return )

int ByteArray_obj::readShort( ){
	HX_STACK_PUSH("ByteArray::readShort","neash/utils/ByteArray.hx",257);
	HX_STACK_THIS(this);
	HX_STACK_LINE(258)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(259)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(260)
	int val = (  ((this->bigEndian)) ? int((int((int(ch1) << int((int)8))) | int(ch2))) : int((((int(ch2) << int((int)8))) + ch1)) );		HX_STACK_VAR(val,"val");
	HX_STACK_LINE(261)
	return (  (((val >= (int)32768))) ? int(((int)65534 - val)) : int(val) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readShort,return )

int ByteArray_obj::readInt( ){
	HX_STACK_PUSH("ByteArray::readInt","neash/utils/ByteArray.hx",247);
	HX_STACK_THIS(this);
	HX_STACK_LINE(248)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(249)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(250)
	int ch3 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(251)
	int ch4 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(252)
	return (  ((this->bigEndian)) ? int((int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4))) : int((int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1))) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readInt,return )

Float ByteArray_obj::readFloat( ){
	HX_STACK_PUSH("ByteArray::readFloat","neash/utils/ByteArray.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_LINE(232)
	if ((((this->position + (int)4) > this->length))){
		HX_STACK_LINE(233)
		this->ThrowEOFi();
	}
	HX_STACK_LINE(238)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)4,this->b->slice(this->position,(this->position + (int)4)));		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(241)
	hx::AddEq(this->position,(int)4);
	HX_STACK_LINE(242)
	return ::neash::utils::ByteArray_obj::_float_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readFloat,return )

Float ByteArray_obj::readDouble( ){
	HX_STACK_PUSH("ByteArray::readDouble","neash/utils/ByteArray.hx",207);
	HX_STACK_THIS(this);
	HX_STACK_LINE(208)
	if ((((this->position + (int)8) > this->length))){
		HX_STACK_LINE(209)
		this->ThrowEOFi();
	}
	HX_STACK_LINE(214)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)8,this->b->slice(this->position,(this->position + (int)8)));		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(217)
	hx::AddEq(this->position,(int)8);
	HX_STACK_LINE(218)
	return ::neash::utils::ByteArray_obj::_double_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readDouble,return )

Void ByteArray_obj::readBytes( ::neash::utils::ByteArray outData,hx::Null< int >  __o_inOffset,hx::Null< int >  __o_inLen){
int inOffset = __o_inOffset.Default(0);
int inLen = __o_inLen.Default(0);
	HX_STACK_PUSH("ByteArray::readBytes","neash/utils/ByteArray.hx",185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(outData,"outData");
	HX_STACK_ARG(inOffset,"inOffset");
	HX_STACK_ARG(inLen,"inLen");
{
		HX_STACK_LINE(186)
		if (((inLen == (int)0))){
			HX_STACK_LINE(187)
			inLen = (this->length - this->position);
		}
		HX_STACK_LINE(188)
		if ((((this->position + inLen) > this->length))){
			HX_STACK_LINE(189)
			this->ThrowEOFi();
		}
		HX_STACK_LINE(190)
		if (((outData->length < (inOffset + inLen)))){
			HX_STACK_LINE(191)
			outData->ensureElem(((inOffset + inLen) - (int)1),true);
		}
		HX_STACK_LINE(196)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(197)
		Array< unsigned char > b2 = outData->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(198)
		int p = this->position;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(199)
		{
			HX_STACK_LINE(199)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(199)
			while(((_g < inLen))){
				HX_STACK_LINE(199)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(200)
				b2[(inOffset + i)] = b1->__get((p + i));
			}
		}
		HX_STACK_LINE(202)
		hx::AddEq(this->position,inLen);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,readBytes,(void))

::String ByteArray_obj::readMultiByte( int inLen,::String charSet){
	HX_STACK_PUSH("ByteArray::readMultiByte","neash/utils/ByteArray.hx",177);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inLen,"inLen");
	HX_STACK_ARG(charSet,"charSet");
	HX_STACK_LINE(177)
	return this->readUTFBytes(inLen);
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,readMultiByte,return )

int ByteArray_obj::readByte( ){
	HX_STACK_PUSH("ByteArray::readByte","neash/utils/ByteArray.hx",171);
	HX_STACK_THIS(this);
	HX_STACK_LINE(171)
	return (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->ThrowEOFi()) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readByte,return )

bool ByteArray_obj::readBoolean( ){
	HX_STACK_PUSH("ByteArray::readBoolean","neash/utils/ByteArray.hx",165);
	HX_STACK_THIS(this);
	HX_STACK_LINE(165)
	return (  ((((this->position + (int)1) < this->length))) ? bool((this->b->__get((this->position)++) != (int)0)) : bool((this->ThrowEOFi() != (int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readBoolean,return )

Void ByteArray_obj::ensureElem( int inSize,bool inUpdateLenght){
{
		HX_STACK_PUSH("ByteArray::ensureElem","neash/utils/ByteArray.hx",132);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSize,"inSize");
		HX_STACK_ARG(inUpdateLenght,"inUpdateLenght");
		HX_STACK_LINE(133)
		int len = (inSize + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(143)
		if (((this->b->length < len))){
			HX_STACK_LINE(144)
			this->b->__SetSize(len);
		}
		HX_STACK_LINE(146)
		if (((bool(inUpdateLenght) && bool((this->length < len))))){
			HX_STACK_LINE(147)
			this->length = len;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,ensureElem,(void))

Void ByteArray_obj::compress( ::String __o_algorithm){
::String algorithm = __o_algorithm.Default(HX_CSTRING(""));
	HX_STACK_PUSH("ByteArray::compress","neash/utils/ByteArray.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_ARG(algorithm,"algorithm");
{
		HX_STACK_LINE(119)
		::neash::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(121)
		::haxe::io::Bytes result = ::cpp::zip::Compress_obj::run(src,(int)8);		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(122)
		this->b = result->b;
		HX_STACK_LINE(123)
		this->length = result->length;
		HX_STACK_LINE(124)
		this->position = this->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,compress,(void))

Void ByteArray_obj::clear( ){
{
		HX_STACK_PUSH("ByteArray::clear","neash/utils/ByteArray.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_LINE(110)
		this->position = (int)0;
		HX_STACK_LINE(111)
		this->length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,clear,(void))

Void ByteArray_obj::checkData( int inLength){
{
		HX_STACK_PUSH("ByteArray::checkData","neash/utils/ByteArray.hx",103);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inLength,"inLength");
		HX_STACK_LINE(103)
		if ((((inLength + this->position) > this->length))){
			HX_STACK_LINE(105)
			this->ThrowEOFi();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,checkData,(void))

::String ByteArray_obj::asString( ){
	HX_STACK_PUSH("ByteArray::asString","neash/utils/ByteArray.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_LINE(95)
	return this->readUTFBytes(this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,asString,return )

Void ByteArray_obj::__set( int pos,int v){
{
		HX_STACK_PUSH("ByteArray::__set","neash/utils/ByteArray.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(85)
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,__set,(void))

int ByteArray_obj::__get( int pos){
	HX_STACK_PUSH("ByteArray::__get","neash/utils/ByteArray.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(55)
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__get,return )

::neash::utils::ByteArray ByteArray_obj::fromBytes( ::haxe::io::Bytes inBytes){
	HX_STACK_PUSH("ByteArray::fromBytes","neash/utils/ByteArray.hx",152);
	HX_STACK_ARG(inBytes,"inBytes");
	HX_STACK_LINE(153)
	::neash::utils::ByteArray result = ::neash::utils::ByteArray_obj::__new((int)-1);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(154)
	result->b = inBytes->b;
	HX_STACK_LINE(155)
	result->length = inBytes->length;
	HX_STACK_LINE(159)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,fromBytes,return )

::neash::utils::ByteArray ByteArray_obj::readFile( ::String inString){
	HX_STACK_PUSH("ByteArray::readFile","neash/utils/ByteArray.hx",224);
	HX_STACK_ARG(inString,"inString");
	HX_STACK_LINE(224)
	return ::neash::utils::ByteArray_obj::nme_byte_array_read_file(inString);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readFile,return )

Dynamic ByteArray_obj::_double_bytes;

Dynamic ByteArray_obj::_double_of_bytes;

Dynamic ByteArray_obj::_float_bytes;

Dynamic ByteArray_obj::_float_of_bytes;

Dynamic ByteArray_obj::nme_byte_array_overwrite_file;

Dynamic ByteArray_obj::nme_byte_array_read_file;


ByteArray_obj::ByteArray_obj()
{
}

void ByteArray_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ByteArray);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(endian,"endian");
	HX_MARK_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_MARK_MEMBER_NAME(bigEndian,"bigEndian");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ByteArray_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(endian,"endian");
	HX_VISIT_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_VISIT_MEMBER_NAME(bigEndian,"bigEndian");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ByteArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"__set") ) { return __set_dyn(); }
		if (HX_FIELD_EQ(inName,"__get") ) { return __get_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return inCallProp ? nmeGetEndian() : endian; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"readUTF") ) { return readUTF_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt") ) { return readInt_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readFile") ) { return readFile_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTF") ) { return writeUTF_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt") ) { return writeInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"compress") ) { return compress_dyn(); }
		if (HX_FIELD_EQ(inName,"asString") ) { return asString_dyn(); }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromBytes") ) { return fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFile") ) { return writeFile_dyn(); }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		if (HX_FIELD_EQ(inName,"ThrowEOFi") ) { return ThrowEOFi_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength") ) { return setLength_dyn(); }
		if (HX_FIELD_EQ(inName,"readShort") ) { return readShort_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"checkData") ) { return checkData_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeShort") ) { return writeShort_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"uncompress") ) { return uncompress_dyn(); }
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"ensureElem") ) { return ensureElem_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"readBoolean") ) { return readBoolean_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { return _float_bytes; }
		if (HX_FIELD_EQ(inName,"nmeSetEndian") ) { return nmeSetEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetEndian") ) { return nmeGetEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBoolean") ) { return writeBoolean_dyn(); }
		if (HX_FIELD_EQ(inName,"readUTFBytes") ) { return readUTFBytes_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { return _double_bytes; }
		if (HX_FIELD_EQ(inName,"writeUTFBytes") ) { return writeUTFBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"write_uncheck") ) { return write_uncheck_dyn(); }
		if (HX_FIELD_EQ(inName,"readMultiByte") ) { return readMultiByte_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { return inCallProp ? nmeGetBytesAvailable() : bytesAvailable; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { return _float_of_bytes; }
		if (HX_FIELD_EQ(inName,"readUnsignedInt") ) { return readUnsignedInt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { return _double_of_bytes; }
		if (HX_FIELD_EQ(inName,"writeUnsignedInt") ) { return writeUnsignedInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readUnsignedByte") ) { return readUnsignedByte_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"readUnsignedShort") ) { return readUnsignedShort_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeGetBytesAvailable") ) { return nmeGetBytesAvailable_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { return nme_byte_array_read_file; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { return nme_byte_array_overwrite_file; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ByteArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { if (inCallProp) return nmeSetEndian(inValue);endian=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { bigEndian=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { bytesAvailable=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { nme_byte_array_read_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { nme_byte_array_overwrite_file=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ByteArray_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("endian"));
	outFields->push(HX_CSTRING("bytesAvailable"));
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromBytes"),
	HX_CSTRING("readFile"),
	HX_CSTRING("_double_bytes"),
	HX_CSTRING("_double_of_bytes"),
	HX_CSTRING("_float_bytes"),
	HX_CSTRING("_float_of_bytes"),
	HX_CSTRING("nme_byte_array_overwrite_file"),
	HX_CSTRING("nme_byte_array_read_file"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetEndian"),
	HX_CSTRING("nmeGetEndian"),
	HX_CSTRING("nmeGetBytesAvailable"),
	HX_CSTRING("writeUTFBytes"),
	HX_CSTRING("writeUTF"),
	HX_CSTRING("writeUnsignedInt"),
	HX_CSTRING("writeShort"),
	HX_CSTRING("writeInt"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeFile"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("write_uncheck"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBoolean"),
	HX_CSTRING("uncompress"),
	HX_CSTRING("ThrowEOFi"),
	HX_CSTRING("setLength"),
	HX_CSTRING("readUTFBytes"),
	HX_CSTRING("readUTF"),
	HX_CSTRING("readUnsignedShort"),
	HX_CSTRING("readUnsignedInt"),
	HX_CSTRING("readUnsignedByte"),
	HX_CSTRING("readShort"),
	HX_CSTRING("readInt"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readMultiByte"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBoolean"),
	HX_CSTRING("ensureElem"),
	HX_CSTRING("compress"),
	HX_CSTRING("clear"),
	HX_CSTRING("checkData"),
	HX_CSTRING("asString"),
	HX_CSTRING("__set"),
	HX_CSTRING("__get"),
	HX_CSTRING("position"),
	HX_CSTRING("endian"),
	HX_CSTRING("bytesAvailable"),
	HX_CSTRING("bigEndian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_overwrite_file,"nme_byte_array_overwrite_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_read_file,"nme_byte_array_read_file");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_byte_array_overwrite_file,"nme_byte_array_overwrite_file");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_byte_array_read_file,"nme_byte_array_read_file");
};

Class ByteArray_obj::__mClass;

void ByteArray_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.utils.ByteArray"), hx::TCanCast< ByteArray_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ByteArray_obj::__boot()
{
	_double_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_bytes"),(int)2);
	_double_of_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_of_bytes"),(int)2);
	_float_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_bytes"),(int)2);
	_float_of_bytes= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_of_bytes"),(int)2);
	nme_byte_array_overwrite_file= ::neash::Loader_obj::load(HX_CSTRING("nme_byte_array_overwrite_file"),(int)2);
	nme_byte_array_read_file= ::neash::Loader_obj::load(HX_CSTRING("nme_byte_array_read_file"),(int)1);
}

} // end namespace neash
} // end namespace utils
