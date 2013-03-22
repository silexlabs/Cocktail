#ifndef INCLUDED_cocktail_core_html_ValueModeValue
#define INCLUDED_cocktail_core_html_ValueModeValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,html,ValueModeValue)
namespace cocktail{
namespace core{
namespace html{


class ValueModeValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ValueModeValue_obj OBJ_;

	public:
		ValueModeValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.html.ValueModeValue"); }
		::String __ToString() const { return HX_CSTRING("ValueModeValue.") + tag; }

		static ::cocktail::core::html::ValueModeValue DEFAULT;
		static inline ::cocktail::core::html::ValueModeValue DEFAULT_dyn() { return DEFAULT; }
		static ::cocktail::core::html::ValueModeValue DEFAULT_ON;
		static inline ::cocktail::core::html::ValueModeValue DEFAULT_ON_dyn() { return DEFAULT_ON; }
		static ::cocktail::core::html::ValueModeValue FILENAME;
		static inline ::cocktail::core::html::ValueModeValue FILENAME_dyn() { return FILENAME; }
		static ::cocktail::core::html::ValueModeValue VALUE;
		static inline ::cocktail::core::html::ValueModeValue VALUE_dyn() { return VALUE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_ValueModeValue */ 
