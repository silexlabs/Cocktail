#ifndef INCLUDED_nme_utils_ByteArray
#define INCLUDED_nme_utils_ByteArray

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Bytes.h>
#include <nme/utils/IDataInput.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(nme,Loader)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
namespace utils{


class ByteArray_obj : public ::haxe::io::Bytes_obj{
	public:
		typedef ::haxe::io::Bytes_obj super;
		typedef ByteArray_obj OBJ_;
		ByteArray_obj();
		Void __construct(Dynamic __o_inSize);

	public:
		static hx::ObjectPtr< ByteArray_obj > __new(Dynamic __o_inSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ByteArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::nme::utils::IDataInput_obj *()
			{ return new ::nme::utils::IDataInput_delegate_< ByteArray_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("ByteArray"); }

		typedef int __array_access;
		bool bigEndian; /* REM */ 
		int bytesAvailable; /* REM */ 
		::String endian; /* REM */ 
		int position; /* REM */ 
		virtual int __get( int pos);
		Dynamic __get_dyn();

		virtual Void __set( int pos,int v);
		Dynamic __set_dyn();

		virtual ::String asString( );
		Dynamic asString_dyn();

		virtual Void checkData( int inLength);
		Dynamic checkData_dyn();

		virtual Void compress( Dynamic algorithm);
		Dynamic compress_dyn();

		virtual Void ensureElem( int inSize,bool inUpdateLenght);
		Dynamic ensureElem_dyn();

		virtual Void push( int inByte);
		Dynamic push_dyn();

		virtual Void push_uncheck( int inByte);
		Dynamic push_uncheck_dyn();

		virtual bool readBoolean( );
		Dynamic readBoolean_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual Void readBytes( ::nme::utils::ByteArray outData,Dynamic inOffset,Dynamic inLen);
		Dynamic readBytes_dyn();

		virtual double readDouble( );
		Dynamic readDouble_dyn();

		virtual double readFloat( );
		Dynamic readFloat_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual int readUnsignedInt( );
		Dynamic readUnsignedInt_dyn();

		virtual int readUnsignedShort( );
		Dynamic readUnsignedShort_dyn();

		virtual ::String readUTF( );
		Dynamic readUTF_dyn();

		virtual ::String readUTFBytes( int inLen);
		Dynamic readUTFBytes_dyn();

		virtual Void setLength( int inLength);
		Dynamic setLength_dyn();

		virtual int ThrowEOFi( );
		Dynamic ThrowEOFi_dyn();

		virtual Void uncompress( Dynamic algorithm);
		Dynamic uncompress_dyn();

		virtual Void writeBoolean( bool value);
		Dynamic writeBoolean_dyn();

		virtual Void writeByte( int value);
		Dynamic writeByte_dyn();

		virtual Void writeBytes( ::haxe::io::Bytes bytes,Dynamic inOffset,Dynamic inLength);
		Dynamic writeBytes_dyn();

		virtual Void writeDouble( double x);
		Dynamic writeDouble_dyn();

		virtual Void writeFile( ::String inString);
		Dynamic writeFile_dyn();

		virtual Void writeFloat( double x);
		Dynamic writeFloat_dyn();

		virtual Void writeInt( int value);
		Dynamic writeInt_dyn();

		virtual Void writeShort( int value);
		Dynamic writeShort_dyn();

		virtual Void writeUnsignedInt( int value);
		Dynamic writeUnsignedInt_dyn();

		virtual Void writeUTF( ::String s);
		Dynamic writeUTF_dyn();

		virtual Void writeUTFBytes( ::String s);
		Dynamic writeUTFBytes_dyn();

		virtual int nmeGetBytesAvailable( );
		Dynamic nmeGetBytesAvailable_dyn();

		virtual ::String nmeGetEndian( );
		Dynamic nmeGetEndian_dyn();

		virtual ::String nmeSetEndian( ::String s);
		Dynamic nmeSetEndian_dyn();

		static Dynamic bytes; /* REM */ 
		static Dynamic factory; /* REM */ 
		static Dynamic resize; /* REM */ 
		static Dynamic slen; /* REM */ 
		static ::nme::utils::ByteArray fromBytes( ::haxe::io::Bytes inBytes);
		static Dynamic fromBytes_dyn();

		static ::nme::utils::ByteArray readFile( ::String inString);
		static Dynamic readFile_dyn();

		static Dynamic _double_bytes; /* REM */ 
	Dynamic &_double_bytes_dyn() { return _double_bytes;}
		static Dynamic _double_of_bytes; /* REM */ 
	Dynamic &_double_of_bytes_dyn() { return _double_of_bytes;}
		static Dynamic _float_bytes; /* REM */ 
	Dynamic &_float_bytes_dyn() { return _float_bytes;}
		static Dynamic _float_of_bytes; /* REM */ 
	Dynamic &_float_of_bytes_dyn() { return _float_of_bytes;}
		static Dynamic nme_byte_array_overwrite_file; /* REM */ 
	Dynamic &nme_byte_array_overwrite_file_dyn() { return nme_byte_array_overwrite_file;}
		static Dynamic nme_byte_array_read_file; /* REM */ 
	Dynamic &nme_byte_array_read_file_dyn() { return nme_byte_array_read_file;}
};

} // end namespace nme
} // end namespace utils

#endif /* INCLUDED_nme_utils_ByteArray */ 
