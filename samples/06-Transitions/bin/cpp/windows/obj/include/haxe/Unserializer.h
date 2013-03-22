#ifndef INCLUDED_haxe_Unserializer
#define INCLUDED_haxe_Unserializer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Unserializer)
namespace haxe{


class Unserializer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Unserializer_obj OBJ_;
		Unserializer_obj();
		Void __construct(::String buf);

	public:
		static hx::ObjectPtr< Unserializer_obj > __new(::String buf);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Unserializer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Unserializer"); }

		virtual Dynamic unserialize( );
		Dynamic unserialize_dyn();

		virtual Dynamic unserializeEnum( ::Enum edecl,::String tag);
		Dynamic unserializeEnum_dyn();

		virtual Void unserializeObject( Dynamic o);
		Dynamic unserializeObject_dyn();

		virtual int readDigits( );
		Dynamic readDigits_dyn();

		virtual int get( int p);
		Dynamic get_dyn();

		virtual Dynamic getResolver( );
		Dynamic getResolver_dyn();

		virtual Void setResolver( Dynamic r);
		Dynamic setResolver_dyn();

		Dynamic resolver; /* REM */ 
		Array< ::String > scache; /* REM */ 
		Dynamic cache; /* REM */ 
		int length; /* REM */ 
		int pos; /* REM */ 
		::String buf; /* REM */ 
		static Dynamic DEFAULT_RESOLVER; /* REM */ 
		static ::String BASE64; /* REM */ 
		static Array< int > CODES; /* REM */ 
		static Array< int > initCodes( );
		static Dynamic initCodes_dyn();

		static Dynamic run( ::String v);
		static Dynamic run_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Unserializer */ 
