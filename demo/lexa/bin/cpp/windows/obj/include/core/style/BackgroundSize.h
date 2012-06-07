#ifndef INCLUDED_core_style_BackgroundSize
#define INCLUDED_core_style_BackgroundSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundSize)
namespace core{
namespace style{


class BackgroundSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundSize_obj OBJ_;

	public:
		BackgroundSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundSize"); }
		::String __ToString() const { return HX_CSTRING("BackgroundSize.") + tag; }

		static ::core::style::BackgroundSize contain;
		static inline ::core::style::BackgroundSize contain_dyn() { return contain; }
		static ::core::style::BackgroundSize cover;
		static inline ::core::style::BackgroundSize cover_dyn() { return cover; }
		static ::core::style::BackgroundSize dimensions(Dynamic value);
		static Dynamic dimensions_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundSize */ 
