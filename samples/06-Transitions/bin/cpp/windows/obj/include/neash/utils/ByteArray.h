#ifndef INCLUDED_neash_utils_ByteArray
#define INCLUDED_neash_utils_ByteArray

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Bytes.h>
#include <neash/utils/IDataInput.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(neash,Loader)
HX_DECLARE_CLASS2(neash,utils,ByteArray)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
namespace neash{
namespace utils{


class ByteArray_obj : public ::haxe::io::Bytes_obj{
	public:
		typedef ::haxe::io::Bytes_obj super;
		typedef ByteArray_obj OBJ_;
		ByteArray_obj();
		Void __construct(hx::Null< int >  __o_inSize);

	public:
		static hx::ObjectPtr< ByteArray_obj > __new(hx::Null< int >  __o_inSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ByteArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::neash::utils::IDataInput_obj *()
			{ return new ::neash::utils::IDataInput_delegate_< ByteArray_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("ByteArray"); }

		typedef int __array_access;
		virtual ::String nmeSetEndian( ::String s);
		Dynamic nmeSetEndian_dyn();

		virtual ::String nmeGetEndian( );
		Dynamic nmeGetEndian_dyn();

		virtual int nmeGetBytesAvailable( );
		Dynamic nmeGetBytesAvailable_dyn();

		virtual Void writeUTFBytes( ::String s);
		Dynamic writeUTFBytes_dyn();

		virtual Void writeUTF( ::String s);
		Dynamic writeUTF_dyn();

		virtual Void writeUnsignedInt( int value);
		Dynamic writeUnsignedInt_dyn();

		virtual Void writeShort( int value);
		Dynamic writeShort_dyn();

		virtual Void writeInt( int value);
		Dynamic writeInt_dyn();

		virtual Void writeFloat( Float x);
		Dynamic writeFloat_dyn();

		virtual Void writeFile( ::String inString);
		Dynamic writeFile_dyn();

		virtual Void writeDouble( Float x);
		Dynamic writeDouble_dyn();

		virtual Void writeBytes( ::haxe::io::Bytes bytes,hx::Null< int >  inOffset,hx::Null< int >  inLength);
		Dynamic writeBytes_dyn();

		virtual Void write_uncheck( int inByte);
		Dynamic write_uncheck_dyn();

		virtual Void writeByte( int value);
		Dynamic writeByte_dyn();

		virtual Void writeBoolean( bool value);
		Dynamic writeBoolean_dyn();

		virtual Void uncompress( ::String algorithm);
		Dynamic uncompress_dyn();

		virtual int ThrowEOFi( );
		Dynamic ThrowEOFi_dyn();

		virtual Void setLength( int inLength);
		Dynamic setLength_dyn();

		virtual ::String readUTFBytes( int inLen);
		Dynamic readUTFBytes_dyn();

		virtual ::String readUTF( );
		Dynamic readUTF_dyn();

		virtual int readUnsignedShort( );
		Dynamic readUnsignedShort_dyn();

		virtual int readUnsignedInt( );
		Dynamic readUnsignedInt_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual Float readFloat( );
		Dynamic readFloat_dyn();

		virtual Float readDouble( );
		Dynamic readDouble_dyn();

		virtual Void readBytes( ::neash::utils::ByteArray outData,hx::Null< int >  inOffset,hx::Null< int >  inLen);
		Dynamic readBytes_dyn();

		virtual ::String readMultiByte( int inLen,::String charSet);
		Dynamic readMultiByte_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual bool readBoolean( );
		Dynamic readBoolean_dyn();

		virtual Void ensureElem( int inSize,bool inUpdateLenght);
		Dynamic ensureElem_dyn();

		virtual Void compress( ::String algorithm);
		Dynamic compress_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void checkData( int inLength);
		Dynamic checkData_dyn();

		virtual ::String asString( );
		Dynamic asString_dyn();

		virtual Void __set( int pos,int v);
		Dynamic __set_dyn();

		virtual int __get( int pos);
		Dynamic __get_dyn();

		int position; /* REM */ 
		::String endian; /* REM */ 
		int bytesAvailable; /* REM */ 
		bool bigEndian; /* REM */ 
		static ::neash::utils::ByteArray fromBytes( ::haxe::io::Bytes inBytes);
		static Dynamic fromBytes_dyn();

		static ::neash::utils::ByteArray readFile( ::String inString);
		static Dynamic readFile_dyn();

		static Dynamic _double_bytes; /* REM */ 
		static Dynamic &_double_bytes_dyn() { return _double_bytes;}
		static Dynamic _double_of_bytes; /* REM */ 
		static Dynamic &_double_of_bytes_dyn() { return _double_of_bytes;}
		static Dynamic _float_bytes; /* REM */ 
		static Dynamic &_float_bytes_dyn() { return _float_bytes;}
		static Dynamic _float_of_bytes; /* REM */ 
		static Dynamic &_float_of_bytes_dyn() { return _float_of_bytes;}
		static Dynamic nme_byte_array_overwrite_file; /* REM */ 
		static Dynamic &nme_byte_array_overwrite_file_dyn() { return nme_byte_array_overwrite_file;}
		static Dynamic nme_byte_array_read_file; /* REM */ 
		static Dynamic &nme_byte_array_read_file_dyn() { return nme_byte_array_read_file;}
};

} // end namespace neash
} // end namespace utils

#endif /* INCLUDED_neash_utils_ByteArray */ 
