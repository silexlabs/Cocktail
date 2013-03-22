#ifndef INCLUDED_sys_net__Socket_SocketOutput
#define INCLUDED_sys_net__Socket_SocketOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS3(sys,net,_Socket,SocketOutput)
namespace sys{
namespace net{
namespace _Socket{


class SocketOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef SocketOutput_obj OBJ_;
		SocketOutput_obj();
		Void __construct(Dynamic s);

	public:
		static hx::ObjectPtr< SocketOutput_obj > __new(Dynamic s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SocketOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SocketOutput"); }

		virtual Void close( );

		virtual int writeBytes( ::haxe::io::Bytes buf,int pos,int len);

		virtual Void writeByte( int c);

		Dynamic __s; /* REM */ 
		static Dynamic socket_close; /* REM */ 
		static Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_send_char; /* REM */ 
		static Dynamic &socket_send_char_dyn() { return socket_send_char;}
		static Dynamic socket_send; /* REM */ 
		static Dynamic &socket_send_dyn() { return socket_send;}
};

} // end namespace sys
} // end namespace net
} // end namespace _Socket

#endif /* INCLUDED_sys_net__Socket_SocketOutput */ 
