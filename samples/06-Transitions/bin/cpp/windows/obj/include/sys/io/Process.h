#ifndef INCLUDED_sys_io_Process
#define INCLUDED_sys_io_Process

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,io,Process)
namespace sys{
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Process"); }

		virtual Void kill( );
		Dynamic kill_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual int exitCode( );
		Dynamic exitCode_dyn();

		virtual int getPid( );
		Dynamic getPid_dyn();

		::haxe::io::Output _stdin; /* REM */ 
		::haxe::io::Input _stderr; /* REM */ 
		::haxe::io::Input _stdout; /* REM */ 
		Dynamic p; /* REM */ 
		static Dynamic _run; /* REM */ 
		static Dynamic &_run_dyn() { return _run;}
		static Dynamic _exit; /* REM */ 
		static Dynamic &_exit_dyn() { return _exit;}
		static Dynamic _pid; /* REM */ 
		static Dynamic &_pid_dyn() { return _pid;}
		static Dynamic _close; /* REM */ 
		static Dynamic &_close_dyn() { return _close;}
};

} // end namespace sys
} // end namespace io

#endif /* INCLUDED_sys_io_Process */ 
