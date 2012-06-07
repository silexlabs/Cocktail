#ifndef INCLUDED_cpp_Sys
#define INCLUDED_cpp_Sys

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS1(cpp,Sys)
namespace cpp{


class Sys_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Sys_obj OBJ_;
		Sys_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Sys_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sys_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Sys"); }

		static Array< ::String > args( );
		static Dynamic args_dyn();

		static ::String getEnv( ::String s);
		static Dynamic getEnv_dyn();

		static Void putEnv( ::String s,::String v);
		static Dynamic putEnv_dyn();

		static Void sleep( double seconds);
		static Dynamic sleep_dyn();

		static bool setTimeLocale( ::String loc);
		static Dynamic setTimeLocale_dyn();

		static ::String getCwd( );
		static Dynamic getCwd_dyn();

		static Void setCwd( ::String s);
		static Dynamic setCwd_dyn();

		static ::String systemName( );
		static Dynamic systemName_dyn();

		static ::String escapeArgument( ::String arg);
		static Dynamic escapeArgument_dyn();

		static int command( ::String cmd,Array< ::String > args);
		static Dynamic command_dyn();

		static Void exit( int code);
		static Dynamic exit_dyn();

		static double time( );
		static Dynamic time_dyn();

		static double cpuTime( );
		static Dynamic cpuTime_dyn();

		static ::String executablePath( );
		static Dynamic executablePath_dyn();

		static ::Hash environment( );
		static Dynamic environment_dyn();

		static Dynamic get_env; /* REM */ 
	Dynamic &get_env_dyn() { return get_env;}
		static Dynamic put_env; /* REM */ 
	Dynamic &put_env_dyn() { return put_env;}
		static Dynamic _sleep; /* REM */ 
	Dynamic &_sleep_dyn() { return _sleep;}
		static Dynamic set_time_locale; /* REM */ 
	Dynamic &set_time_locale_dyn() { return set_time_locale;}
		static Dynamic get_cwd; /* REM */ 
	Dynamic &get_cwd_dyn() { return get_cwd;}
		static Dynamic set_cwd; /* REM */ 
	Dynamic &set_cwd_dyn() { return set_cwd;}
		static Dynamic sys_string; /* REM */ 
	Dynamic &sys_string_dyn() { return sys_string;}
		static Dynamic sys_command; /* REM */ 
	Dynamic &sys_command_dyn() { return sys_command;}
		static Dynamic sys_exit; /* REM */ 
	Dynamic &sys_exit_dyn() { return sys_exit;}
		static Dynamic sys_time; /* REM */ 
	Dynamic &sys_time_dyn() { return sys_time;}
		static Dynamic sys_cpu_time; /* REM */ 
	Dynamic &sys_cpu_time_dyn() { return sys_cpu_time;}
		static Dynamic sys_exe_path; /* REM */ 
	Dynamic &sys_exe_path_dyn() { return sys_exe_path;}
		static Dynamic sys_env; /* REM */ 
	Dynamic &sys_env_dyn() { return sys_env;}
};

} // end namespace cpp

#endif /* INCLUDED_cpp_Sys */ 
