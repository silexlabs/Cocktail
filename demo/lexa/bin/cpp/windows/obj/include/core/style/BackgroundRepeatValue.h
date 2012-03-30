#ifndef INCLUDED_core_style_BackgroundRepeatValue
#define INCLUDED_core_style_BackgroundRepeatValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundRepeatValue)
namespace core{
namespace style{


class BackgroundRepeatValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundRepeatValue_obj OBJ_;

	public:
		BackgroundRepeatValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundRepeatValue"); }
		::String __ToString() const { return HX_CSTRING("BackgroundRepeatValue.") + tag; }

		static ::core::style::BackgroundRepeatValue noRepeat;
		static inline ::core::style::BackgroundRepeatValue noRepeat_dyn() { return noRepeat; }
		static ::core::style::BackgroundRepeatValue repeat;
		static inline ::core::style::BackgroundRepeatValue repeat_dyn() { return repeat; }
		static ::core::style::BackgroundRepeatValue round;
		static inline ::core::style::BackgroundRepeatValue round_dyn() { return round; }
		static ::core::style::BackgroundRepeatValue space;
		static inline ::core::style::BackgroundRepeatValue space_dyn() { return space; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundRepeatValue */ 
