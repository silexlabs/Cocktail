#ifndef INCLUDED_sys_net_Host
#define INCLUDED_sys_net_Host

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
HX_DECLARE_CLASS1(cpp,Lib)
HX_DECLARE_CLASS2(sys,net,Host)
namespace sys{
namespace net{


class Host_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Host_obj OBJ_;
		Host_obj();
		Void __construct(::String name);

	public:
		static hx::ObjectPtr< Host_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Host_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("Host"); }

		virtual ::String reverse( );
		Dynamic reverse_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		::cpp::CppInt32__ ip; /* REM */ 
		static ::String localhost( );
		static Dynamic localhost_dyn();

		static Dynamic host_resolve; /* REM */ 
		static Dynamic &host_resolve_dyn() { return host_resolve;}
		static Dynamic host_reverse; /* REM */ 
		static Dynamic &host_reverse_dyn() { return host_reverse;}
		static Dynamic host_to_string; /* REM */ 
		static Dynamic &host_to_string_dyn() { return host_to_string;}
		static Dynamic host_local; /* REM */ 
		static Dynamic &host_local_dyn() { return host_local;}
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Host */ 
