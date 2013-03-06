#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#define INCLUDED_cocktail_core_geom_RectangleVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/IPoolable.h>
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,core,utils,ObjectPool)
namespace cocktail{
namespace core{
namespace geom{


class RectangleVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RectangleVO_obj OBJ_;
		RectangleVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< RectangleVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RectangleVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::cocktail::core::utils::IPoolable_obj *()
			{ return new ::cocktail::core::utils::IPoolable_delegate_< RectangleVO_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("RectangleVO"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		Float height; /* REM */ 
		Float width; /* REM */ 
		Float y; /* REM */ 
		Float x; /* REM */ 
		static ::cocktail::core::utils::ObjectPool _pool; /* REM */ 
		static ::cocktail::core::utils::ObjectPool getPool( );
		static Dynamic getPool_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_RectangleVO */ 
