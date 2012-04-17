#ifndef INCLUDED_IntHash
#define INCLUDED_IntHash

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IntHash)


class IntHash_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IntHash_obj OBJ_;
		IntHash_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< IntHash_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IntHash_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("IntHash"); }

		Dynamic h; /* REM */ 
		virtual Void set( int key,Dynamic value);
		Dynamic set_dyn();

		virtual Dynamic get( int key);
		Dynamic get_dyn();

		virtual bool exists( int key);
		Dynamic exists_dyn();

		virtual bool remove( int key);
		Dynamic remove_dyn();

		virtual Dynamic keys( );
		Dynamic keys_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};


#endif /* INCLUDED_IntHash */ 
