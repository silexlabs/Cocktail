#ifndef INCLUDED_neash_text_AntiAliasType
#define INCLUDED_neash_text_AntiAliasType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,AntiAliasType)
namespace neash{
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
		::String GetEnumName( ) const { return HX_CSTRING("neash.text.AntiAliasType"); }
		::String __ToString() const { return HX_CSTRING("AntiAliasType.") + tag; }

		static ::neash::text::AntiAliasType ADVANCED;
		static inline ::neash::text::AntiAliasType ADVANCED_dyn() { return ADVANCED; }
		static ::neash::text::AntiAliasType NORMAL;
		static inline ::neash::text::AntiAliasType NORMAL_dyn() { return NORMAL; }
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_AntiAliasType */ 
