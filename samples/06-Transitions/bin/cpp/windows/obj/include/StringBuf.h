#ifndef INCLUDED_StringBuf
#define INCLUDED_StringBuf

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)


class StringBuf_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StringBuf_obj OBJ_;
		StringBuf_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StringBuf_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StringBuf_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StringBuf"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void addChar( int c);
		Dynamic addChar_dyn();

		virtual Void addSub( ::String s,int pos,Dynamic len);
		Dynamic addSub_dyn();

		virtual Void add( Dynamic x);
		Dynamic add_dyn();

		Dynamic b; /* REM */ 
};


#endif /* INCLUDED_StringBuf */ 
