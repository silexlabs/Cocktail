#ifndef INCLUDED_cocktail_core_style_Transform
#define INCLUDED_cocktail_core_style_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Transform)
HX_DECLARE_CLASS3(cocktail,core,style,TransformFunction)
namespace cocktail{
namespace core{
namespace style{


class Transform_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Transform_obj OBJ_;

	public:
		Transform_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Transform"); }
		::String __ToString() const { return HX_CSTRING("Transform.") + tag; }

		static ::cocktail::core::style::Transform none;
		static inline ::cocktail::core::style::Transform none_dyn() { return none; }
		static ::cocktail::core::style::Transform transformFunctions(Array< ::cocktail::core::style::TransformFunction > transformFunctions);
		static Dynamic transformFunctions_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Transform */ 
