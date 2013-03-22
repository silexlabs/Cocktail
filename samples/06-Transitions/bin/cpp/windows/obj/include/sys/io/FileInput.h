#ifndef INCLUDED_sys_io_FileInput
#define INCLUDED_sys_io_FileInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(sys,io,FileInput)
HX_DECLARE_CLASS2(sys,io,FileSeek)
namespace sys{
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileInput"); }

		virtual bool eof( );
		Dynamic eof_dyn();

		virtual int tell( );
		Dynamic tell_dyn();

		virtual Void seek( int p,::sys::io::FileSeek pos);
		Dynamic seek_dyn();

		virtual Void close( );

		virtual int readBytes( ::haxe::io::Bytes s,int p,int l);

		virtual int readByte( );

		Dynamic __f; /* REM */ 
		static Dynamic file_eof; /* REM */ 
		static Dynamic &file_eof_dyn() { return file_eof;}
		static Dynamic file_read; /* REM */ 
		static Dynamic &file_read_dyn() { return file_read;}
		static Dynamic file_read_char; /* REM */ 
		static Dynamic &file_read_char_dyn() { return file_read_char;}
		static Dynamic file_close; /* REM */ 
		static Dynamic &file_close_dyn() { return file_close;}
		static Dynamic file_seek; /* REM */ 
		static Dynamic &file_seek_dyn() { return file_seek;}
		static Dynamic file_tell; /* REM */ 
		static Dynamic &file_tell_dyn() { return file_tell;}
};

} // end namespace sys
} // end namespace io

#endif /* INCLUDED_sys_io_FileInput */ 
