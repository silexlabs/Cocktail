#ifndef INCLUDED_haxe_io_Output
#define INCLUDED_haxe_io_Output

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace haxe{
namespace io{


class Output_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Output_obj OBJ_;
		Output_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Output_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Output_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Output"); }

		bool bigEndian; /* REM */ 
		virtual Void writeByte( int c);
		Dynamic writeByte_dyn();

		virtual int writeBytes( ::haxe::io::Bytes s,int pos,int len);
		Dynamic writeBytes_dyn();

		virtual Void flush( );
		Dynamic flush_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual bool setEndian( bool b);
		Dynamic setEndian_dyn();

		virtual Void write( ::haxe::io::Bytes s);
		Dynamic write_dyn();

		virtual Void writeFullBytes( ::haxe::io::Bytes s,int pos,int len);
		Dynamic writeFullBytes_dyn();

		virtual Void writeFloat( double x);
		Dynamic writeFloat_dyn();

		virtual Void writeDouble( double x);
		Dynamic writeDouble_dyn();

		virtual Void writeInt8( int x);
		Dynamic writeInt8_dyn();

		virtual Void writeInt16( int x);
		Dynamic writeInt16_dyn();

		virtual Void writeUInt16( int x);
		Dynamic writeUInt16_dyn();

		virtual Void writeInt24( int x);
		Dynamic writeInt24_dyn();

		virtual Void writeUInt24( int x);
		Dynamic writeUInt24_dyn();

		virtual Void writeInt31( int x);
		Dynamic writeInt31_dyn();

		virtual Void writeUInt30( int x);
		Dynamic writeUInt30_dyn();

		virtual Void writeInt32( ::cpp::CppInt32__ x);
		Dynamic writeInt32_dyn();

		virtual Void prepare( int nbytes);
		Dynamic prepare_dyn();

		virtual Void writeInput( ::haxe::io::Input i,Dynamic bufsize);
		Dynamic writeInput_dyn();

		virtual Void writeString( ::String s);
		Dynamic writeString_dyn();

		static Dynamic _float_bytes; /* REM */ 
	Dynamic &_float_bytes_dyn() { return _float_bytes;}
		static Dynamic _double_bytes; /* REM */ 
	Dynamic &_double_bytes_dyn() { return _double_bytes;}
};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Output */ 
