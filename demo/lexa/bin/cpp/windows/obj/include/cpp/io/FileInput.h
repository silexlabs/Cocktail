#ifndef INCLUDED_cpp_io_FileInput
#define INCLUDED_cpp_io_FileInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(cpp,io,FileInput)
HX_DECLARE_CLASS2(cpp,io,FileSeek)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
namespace cpp{
namespace io{


class FileInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef FileInput_obj OBJ_;
		FileInput_obj();
		Void __construct(Dynamic f);

	public:
		static hx::ObjectPtr< FileInput_obj > __new(Dynamic f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileInput"); }

		Dynamic __f; /* REM */ 
		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual int readBytes( ::haxe::io::Bytes s,int p,int l);
		Dynamic readBytes_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void seek( int p,::cpp::io::FileSeek pos);
		Dynamic seek_dyn();

		virtual int tell( );
		Dynamic tell_dyn();

		virtual bool eof( );
		Dynamic eof_dyn();

		static Dynamic file_eof; /* REM */ 
	Dynamic &file_eof_dyn() { return file_eof;}
		static Dynamic file_read; /* REM */ 
	Dynamic &file_read_dyn() { return file_read;}
		static Dynamic file_read_char; /* REM */ 
	Dynamic &file_read_char_dyn() { return file_read_char;}
		static Dynamic file_close; /* REM */ 
	Dynamic &file_close_dyn() { return file_close;}
		static Dynamic file_seek; /* REM */ 
	Dynamic &file_seek_dyn() { return file_seek;}
		static Dynamic file_tell; /* REM */ 
	Dynamic &file_tell_dyn() { return file_tell;}
};

} // end namespace cpp
} // end namespace io

#endif /* INCLUDED_cpp_io_FileInput */ 
