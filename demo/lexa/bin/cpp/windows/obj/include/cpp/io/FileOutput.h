#ifndef INCLUDED_cpp_io_FileOutput
#define INCLUDED_cpp_io_FileOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(cpp,io,FileOutput)
HX_DECLARE_CLASS2(cpp,io,FileSeek)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace io{


class FileOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef FileOutput_obj OBJ_;
		FileOutput_obj();
		Void __construct(Dynamic f);

	public:
		static hx::ObjectPtr< FileOutput_obj > __new(Dynamic f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileOutput"); }

		Dynamic __f; /* REM */ 
		virtual Void writeByte( int c);
		Dynamic writeByte_dyn();

		virtual int writeBytes( ::haxe::io::Bytes s,int p,int l);
		Dynamic writeBytes_dyn();

		virtual Void flush( );
		Dynamic flush_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void seek( int p,::cpp::io::FileSeek pos);
		Dynamic seek_dyn();

		virtual int tell( );
		Dynamic tell_dyn();

		static Dynamic file_close; /* REM */ 
	Dynamic &file_close_dyn() { return file_close;}
		static Dynamic file_seek; /* REM */ 
	Dynamic &file_seek_dyn() { return file_seek;}
		static Dynamic file_tell; /* REM */ 
	Dynamic &file_tell_dyn() { return file_tell;}
		static Dynamic file_flush; /* REM */ 
	Dynamic &file_flush_dyn() { return file_flush;}
		static Dynamic file_write; /* REM */ 
	Dynamic &file_write_dyn() { return file_write;}
		static Dynamic file_write_char; /* REM */ 
	Dynamic &file_write_char_dyn() { return file_write_char;}
};

} // end namespace cpp
} // end namespace io

#endif /* INCLUDED_cpp_io_FileOutput */ 
