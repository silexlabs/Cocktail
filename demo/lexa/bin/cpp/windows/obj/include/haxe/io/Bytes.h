#ifndef INCLUDED_haxe_io_Bytes
#define INCLUDED_haxe_io_Bytes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
namespace haxe{
namespace io{


class Bytes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bytes_obj OBJ_;
		Bytes_obj();
		Void __construct(int length,Array< unsigned char > b);

	public:
		static hx::ObjectPtr< Bytes_obj > __new(int length,Array< unsigned char > b);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bytes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bytes"); }

		int length; /* REM */ 
		Array< unsigned char > b; /* REM */ 
		virtual int get( int pos);
		Dynamic get_dyn();

		virtual Void set( int pos,int v);
		Dynamic set_dyn();

		virtual Void blit( int pos,::haxe::io::Bytes src,int srcpos,int len);
		Dynamic blit_dyn();

		virtual ::haxe::io::Bytes sub( int pos,int len);
		Dynamic sub_dyn();

		virtual int compare( ::haxe::io::Bytes other);
		Dynamic compare_dyn();

		virtual ::String readString( int pos,int len);
		Dynamic readString_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String toHex( );
		Dynamic toHex_dyn();

		virtual Array< unsigned char > getData( );
		Dynamic getData_dyn();

		static ::haxe::io::Bytes alloc( int length);
		static Dynamic alloc_dyn();

		static ::haxe::io::Bytes ofString( ::String s);
		static Dynamic ofString_dyn();

		static ::haxe::io::Bytes ofData( Array< unsigned char > b);
		static Dynamic ofData_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Bytes */ 
