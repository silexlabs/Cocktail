#ifndef INCLUDED_cocktail_core_css_PropertyVO
#define INCLUDED_cocktail_core_css_PropertyVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/IPoolable.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,PropertyOriginValue)
HX_DECLARE_CLASS3(cocktail,core,css,PropertyVO)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,core,utils,ObjectPool)
namespace cocktail{
namespace core{
namespace css{


class PropertyVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PropertyVO_obj OBJ_;
		PropertyVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PropertyVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PropertyVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::cocktail::core::utils::IPoolable_obj *()
			{ return new ::cocktail::core::utils::IPoolable_delegate_< PropertyVO_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("PropertyVO"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		::cocktail::core::css::SelectorVO selector; /* REM */ 
		::cocktail::core::css::CSSPropertyValue typedValue; /* REM */ 
		::cocktail::core::css::PropertyOriginValue origin; /* REM */ 
		bool important; /* REM */ 
		static ::cocktail::core::utils::ObjectPool _pool; /* REM */ 
		static ::cocktail::core::utils::ObjectPool getPool( );
		static Dynamic getPool_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_PropertyVO */ 
