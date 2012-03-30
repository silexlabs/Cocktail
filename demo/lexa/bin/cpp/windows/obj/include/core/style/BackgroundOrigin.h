#ifndef INCLUDED_core_style_BackgroundOrigin
#define INCLUDED_core_style_BackgroundOrigin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundOrigin)
namespace core{
namespace style{


class BackgroundOrigin_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundOrigin_obj OBJ_;

	public:
		BackgroundOrigin_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundOrigin"); }
		::String __ToString() const { return HX_CSTRING("BackgroundOrigin.") + tag; }

		static ::core::style::BackgroundOrigin borderBox;
		static inline ::core::style::BackgroundOrigin borderBox_dyn() { return borderBox; }
		static ::core::style::BackgroundOrigin contentBox;
		static inline ::core::style::BackgroundOrigin contentBox_dyn() { return contentBox; }
		static ::core::style::BackgroundOrigin paddingBox;
		static inline ::core::style::BackgroundOrigin paddingBox_dyn() { return paddingBox; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundOrigin */ 
