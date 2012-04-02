#ifndef INCLUDED_cpp_net_SocketInput
#define INCLUDED_cpp_net_SocketInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(cpp,net,SocketInput)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
namespace cpp{
namespace net{


class SocketInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef SocketInput_obj OBJ_;
		SocketInput_obj();
		Void __construct(Dynamic s);

	public:
		static hx::ObjectPtr< SocketInput_obj > __new(Dynamic s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SocketInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SocketInput"); }

		Dynamic __s; /* REM */ 
		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual int readBytes( ::haxe::io::Bytes buf,int pos,int len);
		Dynamic readBytes_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		static Dynamic socket_recv; /* REM */ 
	Dynamic &socket_recv_dyn() { return socket_recv;}
		static Dynamic socket_recv_char; /* REM */ 
	Dynamic &socket_recv_char_dyn() { return socket_recv_char;}
		static Dynamic socket_close; /* REM */ 
	Dynamic &socket_close_dyn() { return socket_close;}
};

} // end namespace cpp
} // end namespace net

#endif /* INCLUDED_cpp_net_SocketInput */ 
