#ifndef INCLUDED_core_style_Transform
#define INCLUDED_core_style_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Transform)
HX_DECLARE_CLASS2(core,style,TransformFunction)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Transform"); }
		::String __ToString() const { return HX_CSTRING("Transform.") + tag; }

		static ::core::style::Transform none;
		static inline ::core::style::Transform none_dyn() { return none; }
		static ::core::style::Transform transformFunctions(Array< ::core::style::TransformFunction > transformFunctions);
		static Dynamic transformFunctions_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Transform */ 
