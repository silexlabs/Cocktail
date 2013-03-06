#ifndef INCLUDED_native_text_AntiAliasType
#define INCLUDED_native_text_AntiAliasType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,text,AntiAliasType)
namespace native{
namespace text{


class AntiAliasType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AntiAliasType_obj OBJ_;

	public:
		AntiAliasType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("native.text.AntiAliasType"); }
		::String __ToString() const { return HX_CSTRING("AntiAliasType.") + tag; }

		static ::native::text::AntiAliasType ADVANCED;
		static inline ::native::text::AntiAliasType ADVANCED_dyn() { return ADVANCED; }
		static ::native::text::AntiAliasType NORMAL;
		static inline ::native::text::AntiAliasType NORMAL_dyn() { return NORMAL; }
};

} // end namespace native
} // end namespace text

#endif /* INCLUDED_native_text_AntiAliasType */ 
