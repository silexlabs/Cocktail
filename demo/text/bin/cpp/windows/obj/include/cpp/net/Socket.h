#ifndef INCLUDED_cpp_net_Socket
#define INCLUDED_cpp_net_Socket

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
HX_DECLARE_CLASS2(cpp,net,Host)
HX_DECLARE_CLASS2(cpp,net,Socket)
HX_DECLARE_CLASS2(cpp,net,SocketInput)
HX_DECLARE_CLASS2(cpp,net,SocketOutput)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace net{


class Socket_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Socket_obj OBJ_;
		Socket_obj();
		Void __construct(Dynamic s);

	public:
		static hx::ObjectPtr< Socket_obj > __new(Dynamic s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Socket_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Socket"); }

		Dynamic __s; /* REM */ 
		::cpp::net::SocketInput input; /* REM */ 
		::cpp::net::SocketOutput output; /* REM */ 
		Dynamic custom; /* REM */ 
		virtual Void close( );
		Dynamic close_dyn();

		virtual ::String read( );
		Dynamic read_dyn();

		virtual Void write( ::String content);
		Dynamic write_dyn();

		virtual Void connect( ::cpp::net::Host host,int port);
		Dynamic connect_dyn();

		virtual Void listen( int connections);
		Dynamic listen_dyn();

		virtual Void shutdown( bool read,bool write);
		Dynamic shutdown_dyn();

		virtual Void bind( ::cpp::net::Host host,int port);
		Dynamic bind_dyn();

		virtual ::cpp::net::Socket accept( );
		Dynamic accept_dyn();

		virtual Dynamic peer( );
		Dynamic peer_dyn();

		virtual Dynamic host( );
		Dynamic host_dyn();

		virtual Void setTimeout( double timeout);
		Dynamic setTimeout_dyn();

		virtual Void waitForRead( );
		Dynamic waitForRead_dyn();

		virtual Void setBlocking( bool b);
		Dynamic setBlocking_dyn();

		static ::cpp::net::Socket newUdpSocket( );
		static Dynamic newUdpSocket_dyn();

		static Dynamic select( Array< ::cpp::net::Socket > read,Array< ::cpp::net::Socket > write,Array< ::cpp::net::Socket > others,Dynamic timeout);
		static Dynamic select_dyn();

		static Dynamic socket_new; /* REM */ 
	Dynamic &socket_new_dyn() { return socket_new;}
		static Dynamic socket_close; /* REM */ 
	Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_write; /* REM */ 
	Dynamic &socket_write_dyn() { return socket_write;}
		static Dynamic socket_read; /* REM */ 
	Dynamic &socket_read_dyn() { return socket_read;}
		static Dynamic socket_connect; /* REM */ 
	Dynamic &socket_connect_dyn() { return socket_connect;}
		static Dynamic socket_listen; /* REM */ 
	Dynamic &socket_listen_dyn() { return socket_listen;}
		static Dynamic socket_select; /* REM */ 
	Dynamic &socket_select_dyn() { return socket_select;}
		static Dynamic socket_bind; /* REM */ 
	Dynamic &socket_bind_dyn() { return socket_bind;}
		static Dynamic socket_accept; /* REM */ 
	Dynamic &socket_accept_dyn() { return socket_accept;}
		static Dynamic socket_peer; /* REM */ 
	Dynamic &socket_peer_dyn() { return socket_peer;}
		static Dynamic socket_host; /* REM */ 
	Dynamic &socket_host_dyn() { return socket_host;}
		static Dynamic socket_set_timeout; /* REM */ 
	Dynamic &socket_set_timeout_dyn() { return socket_set_timeout;}
		static Dynamic socket_shutdown; /* REM */ 
	Dynamic &socket_shutdown_dyn() { return socket_shutdown;}
		static Dynamic socket_set_blocking; /* REM */ 
	Dynamic &socket_set_blocking_dyn() { return socket_set_blocking;}
};

} // end namespace cpp
} // end namespace net

#endif /* INCLUDED_cpp_net_Socket */ 
