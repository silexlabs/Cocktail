#ifndef INCLUDED_cpp_io_File
#define INCLUDED_cpp_io_File

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(cpp,io,File)
HX_DECLARE_CLASS2(cpp,io,FileInput)
HX_DECLARE_CLASS2(cpp,io,FileOutput)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace io{


class File_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef File_obj OBJ_;
		File_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< File_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~File_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("File"); }

		static ::String getContent( ::String path);
		static Dynamic getContent_dyn();

		static ::haxe::io::Bytes getBytes( ::String path);
		static Dynamic getBytes_dyn();

		static ::cpp::io::FileInput read( ::String path,bool binary);
		static Dynamic read_dyn();

		static ::cpp::io::FileOutput write( ::String path,bool binary);
		static Dynamic write_dyn();

		static ::cpp::io::FileOutput append( ::String path,bool binary);
		static Dynamic append_dyn();

		static Void copy( ::String src,::String dst);
		static Dynamic copy_dyn();

		static ::cpp::io::FileInput _stdin( );
		static Dynamic _stdin_dyn();

		static ::cpp::io::FileOutput _stdout( );
		static Dynamic _stdout_dyn();

		static ::cpp::io::FileOutput _stderr( );
		static Dynamic _stderr_dyn();

		static int getChar( bool echo);
		static Dynamic getChar_dyn();

		static Dynamic file_stdin; /* REM */ 
	Dynamic &file_stdin_dyn() { return file_stdin;}
		static Dynamic file_stdout; /* REM */ 
	Dynamic &file_stdout_dyn() { return file_stdout;}
		static Dynamic file_stderr; /* REM */ 
	Dynamic &file_stderr_dyn() { return file_stderr;}
		static Dynamic file_contents; /* REM */ 
	Dynamic &file_contents_dyn() { return file_contents;}
		static Dynamic file_open; /* REM */ 
	Dynamic &file_open_dyn() { return file_open;}
		static Dynamic getch; /* REM */ 
	Dynamic &getch_dyn() { return getch;}
};

} // end namespace cpp
} // end namespace io

#endif /* INCLUDED_cpp_io_File */ 
