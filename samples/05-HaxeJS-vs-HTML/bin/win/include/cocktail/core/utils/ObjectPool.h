#ifndef INCLUDED_cocktail_core_utils_ObjectPool
#define INCLUDED_cocktail_core_utils_ObjectPool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,utils,ObjectPool)
namespace cocktail{
namespace core{
namespace utils{


class ObjectPool_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectPool_obj OBJ_;
		ObjectPool_obj();
		Void __construct(::Class pooledClass);

	public:
		static hx::ObjectPtr< ObjectPool_obj > __new(::Class pooledClass);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ObjectPool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ObjectPool"); }

		virtual Void release( Dynamic object);
		Dynamic release_dyn();

		virtual Dynamic get( );
		Dynamic get_dyn();

		Dynamic _args; /* REM */ 
		::Class _pooledClass; /* REM */ 
		int _freeObjectIndex; /* REM */ 
		Dynamic _pool; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace utils

#endif /* INCLUDED_cocktail_core_utils_ObjectPool */ 
