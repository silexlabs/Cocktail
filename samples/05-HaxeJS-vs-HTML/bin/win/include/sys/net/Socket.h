#ifndef INCLUDED_sys_net_Socket
#define INCLUDED_sys_net_Socket

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,net,Host)
HX_DECLARE_CLASS2(sys,net,Socket)
namespace sys{
namespace net{


class Socket_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Socket_obj OBJ_;
		Socket_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Socket_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Socket_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Socket"); }

		virtual Void setFastSend( bool b);
		Dynamic setFastSend_dyn();

		virtual Void setBlocking( bool b);
		Dynamic setBlocking_dyn();

		virtual Void waitForRead( );
		Dynamic waitForRead_dyn();

		virtual Void setTimeout( Float timeout);
		Dynamic setTimeout_dyn();

		virtual Dynamic host( );
		Dynamic host_dyn();

		virtual Dynamic peer( );
		Dynamic peer_dyn();

		virtual ::sys::net::Socket accept( );
		Dynamic accept_dyn();

		virtual Void bind( ::sys::net::Host host,int port);
		Dynamic bind_dyn();

		virtual Void shutdown( bool read,bool write);
		Dynamic shutdown_dyn();

		virtual Void listen( int connections);
		Dynamic listen_dyn();

		virtual Void connect( ::sys::net::Host host,int port);
		Dynamic connect_dyn();

		virtual Void write( ::String content);
		Dynamic write_dyn();

		virtual ::String read( );
		Dynamic read_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		Dynamic custom; /* REM */ 
		::haxe::io::Output output; /* REM */ 
		::haxe::io::Input input; /* REM */ 
		Dynamic __s; /* REM */ 
		static Dynamic select( Array< ::sys::net::Socket > read,Array< ::sys::net::Socket > write,Array< ::sys::net::Socket > others,Dynamic timeout);
		static Dynamic select_dyn();

		static Dynamic socket_new; /* REM */ 
		static Dynamic &socket_new_dyn() { return socket_new;}
		static Dynamic socket_close; /* REM */ 
		static Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_write; /* REM */ 
		static Dynamic &socket_write_dyn() { return socket_write;}
		static Dynamic socket_read; /* REM */ 
		static Dynamic &socket_read_dyn() { return socket_read;}
		static Dynamic socket_connect; /* REM */ 
		static Dynamic &socket_connect_dyn() { return socket_connect;}
		static Dynamic socket_listen; /* REM */ 
		static Dynamic &socket_listen_dyn() { return socket_listen;}
		static Dynamic socket_select; /* REM */ 
		static Dynamic &socket_select_dyn() { return socket_select;}
		static Dynamic socket_bind; /* REM */ 
		static Dynamic &socket_bind_dyn() { return socket_bind;}
		static Dynamic socket_accept; /* REM */ 
		static Dynamic &socket_accept_dyn() { return socket_accept;}
		static Dynamic socket_peer; /* REM */ 
		static Dynamic &socket_peer_dyn() { return socket_peer;}
		static Dynamic socket_host; /* REM */ 
		static Dynamic &socket_host_dyn() { return socket_host;}
		static Dynamic socket_set_timeout; /* REM */ 
		static Dynamic &socket_set_timeout_dyn() { return socket_set_timeout;}
		static Dynamic socket_shutdown; /* REM */ 
		static Dynamic &socket_shutdown_dyn() { return socket_shutdown;}
		static Dynamic socket_set_blocking; /* REM */ 
		static Dynamic &socket_set_blocking_dyn() { return socket_set_blocking;}
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Socket */ 
