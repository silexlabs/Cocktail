#ifndef INCLUDED_nme_utils_WeakRef
#define INCLUDED_nme_utils_WeakRef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,utils,WeakRef)
namespace nme{
namespace utils{


class WeakRef_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WeakRef_obj OBJ_;
		WeakRef_obj();
		Void __construct(Dynamic inObject,Dynamic __o_inMakeWeak);

	public:
		static hx::ObjectPtr< WeakRef_obj > __new(Dynamic inObject,Dynamic __o_inMakeWeak);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WeakRef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("WeakRef"); }

		Dynamic hardRef; /* REM */ 
		int weakRef; /* REM */ 
		virtual Dynamic get( );
		Dynamic get_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static Dynamic nme_weak_ref_create; /* REM */ 
	Dynamic &nme_weak_ref_create_dyn() { return nme_weak_ref_create;}
		static Dynamic nme_weak_ref_get; /* REM */ 
	Dynamic &nme_weak_ref_get_dyn() { return nme_weak_ref_get;}
};

} // end namespace nme
} // end namespace utils

#endif /* INCLUDED_nme_utils_WeakRef */ 
