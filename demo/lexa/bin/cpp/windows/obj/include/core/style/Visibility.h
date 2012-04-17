#ifndef INCLUDED_core_style_Visibility
#define INCLUDED_core_style_Visibility

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Visibility)
namespace core{
namespace style{


class Visibility_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Visibility_obj OBJ_;

	public:
		Visibility_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Visibility"); }
		::String __ToString() const { return HX_CSTRING("Visibility.") + tag; }

		static ::core::style::Visibility hidden;
		static inline ::core::style::Visibility hidden_dyn() { return hidden; }
		static ::core::style::Visibility visible;
		static inline ::core::style::Visibility visible_dyn() { return visible; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Visibility */ 
