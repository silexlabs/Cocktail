#ifndef INCLUDED_Hash
#define INCLUDED_Hash

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)


class Hash_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Hash_obj OBJ_;
		Hash_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Hash_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Hash_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Hash"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual Dynamic keys( );
		Dynamic keys_dyn();

		virtual bool remove( ::String key);
		Dynamic remove_dyn();

		virtual bool exists( ::String key);
		Dynamic exists_dyn();

		virtual Dynamic get( ::String key);
		Dynamic get_dyn();

		virtual Void set( ::String key,Dynamic value);
		Dynamic set_dyn();

		Dynamic __Internal; /* REM */ 
};


#endif /* INCLUDED_Hash */ 
