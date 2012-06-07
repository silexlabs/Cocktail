#ifndef INCLUDED_cpp_io__Process_Stdin
#define INCLUDED_cpp_io__Process_Stdin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS3(cpp,io,_Process,Stdin)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace io{
namespace _Process{


class Stdin_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef Stdin_obj OBJ_;
		Stdin_obj();
		Void __construct(Dynamic p);

	public:
		static hx::ObjectPtr< Stdin_obj > __new(Dynamic p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Stdin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Stdin"); }

		Dynamic p; /* REM */ 
		::haxe::io::Bytes buf; /* REM */ 
		virtual Void close( );
		Dynamic close_dyn();

		virtual Void writeByte( int c);
		Dynamic writeByte_dyn();

		virtual int writeBytes( ::haxe::io::Bytes buf,int pos,int len);
		Dynamic writeBytes_dyn();

		static Dynamic _stdin_write; /* REM */ 
	Dynamic &_stdin_write_dyn() { return _stdin_write;}
		static Dynamic _stdin_close; /* REM */ 
	Dynamic &_stdin_close_dyn() { return _stdin_close;}
};

} // end namespace cpp
} // end namespace io
} // end namespace _Process

#endif /* INCLUDED_cpp_io__Process_Stdin */ 
