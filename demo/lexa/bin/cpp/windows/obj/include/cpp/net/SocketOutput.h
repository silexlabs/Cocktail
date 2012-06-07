#ifndef INCLUDED_cpp_net_SocketOutput
#define INCLUDED_cpp_net_SocketOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(cpp,net,SocketOutput)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace cpp{
namespace net{


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
		::String __ToString() const { return HX_CSTRING("SocketOutput"); }

		Dynamic __s; /* REM */ 
		virtual Void writeByte( int c);
		Dynamic writeByte_dyn();

		virtual int writeBytes( ::haxe::io::Bytes buf,int pos,int len);
		Dynamic writeBytes_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		static Dynamic socket_close; /* REM */ 
	Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_send_char; /* REM */ 
	Dynamic &socket_send_char_dyn() { return socket_send_char;}
		static Dynamic socket_send; /* REM */ 
	Dynamic &socket_send_dyn() { return socket_send;}
};

} // end namespace cpp
} // end namespace net

#endif /* INCLUDED_cpp_net_SocketOutput */ 
