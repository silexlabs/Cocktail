#ifndef INCLUDED_cpp_io_Process
#define INCLUDED_cpp_io_Process

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(cpp,io,Process)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace io{


class Process_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Process_obj OBJ_;
		Process_obj();
		Void __construct(::String cmd,Array< ::String > args);

	public:
		static hx::ObjectPtr< Process_obj > __new(::String cmd,Array< ::String > args);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Process_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Process"); }

		Dynamic p; /* REM */ 
		::haxe::io::Input _stdout; /* REM */ 
		::haxe::io::Input _stderr; /* REM */ 
		::haxe::io::Output _stdin; /* REM */ 
		virtual int getPid( );
		Dynamic getPid_dyn();

		virtual int exitCode( );
		Dynamic exitCode_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		static Dynamic _run; /* REM */ 
	Dynamic &_run_dyn() { return _run;}
		static Dynamic _exit; /* REM */ 
	Dynamic &_exit_dyn() { return _exit;}
		static Dynamic _pid; /* REM */ 
	Dynamic &_pid_dyn() { return _pid;}
		static Dynamic _close; /* REM */ 
	Dynamic &_close_dyn() { return _close;}
};

} // end namespace cpp
} // end namespace io

#endif /* INCLUDED_cpp_io_Process */ 
