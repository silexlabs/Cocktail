#ifndef INCLUDED_nme_text_AntiAliasType
#define INCLUDED_nme_text_AntiAliasType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,text,AntiAliasType)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.text.AntiAliasType"); }
		::String __ToString() const { return HX_CSTRING("AntiAliasType.") + tag; }

		static ::nme::text::AntiAliasType ADVANCED;
		static inline ::nme::text::AntiAliasType ADVANCED_dyn() { return ADVANCED; }
		static ::nme::text::AntiAliasType NORMAL;
		static inline ::nme::text::AntiAliasType NORMAL_dyn() { return NORMAL; }
};

} // end namespace nme
} // end namespace text

#endif /* INCLUDED_nme_text_AntiAliasType */ 
