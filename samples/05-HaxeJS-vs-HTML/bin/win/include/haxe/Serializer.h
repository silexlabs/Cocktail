#ifndef INCLUDED_haxe_Serializer
#define INCLUDED_haxe_Serializer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS1(haxe,Serializer)
namespace haxe{


class Serializer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Serializer_obj OBJ_;
		Serializer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Serializer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Serializer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Serializer"); }

		virtual Void serializeException( Dynamic e);
		Dynamic serializeException_dyn();

		virtual Void serialize( Dynamic v);
		Dynamic serialize_dyn();

		virtual Void serializeFields( Dynamic v);
		Dynamic serializeFields_dyn();

		virtual bool serializeRef( Dynamic v);
		Dynamic serializeRef_dyn();

		virtual Void serializeString( ::String s);
		Dynamic serializeString_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		bool useEnumIndex; /* REM */ 
		bool useCache; /* REM */ 
		int scount; /* REM */ 
		::Hash shash; /* REM */ 
		Dynamic cache; /* REM */ 
		::StringBuf buf; /* REM */ 
		static bool USE_CACHE; /* REM */ 
		static bool USE_ENUM_INDEX; /* REM */ 
		static ::String BASE64; /* REM */ 
		static ::String run( Dynamic v);
		static Dynamic run_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Serializer */ 
