#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#define INCLUDED_cocktail_core_http_DataFormatValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,http,DataFormatValue)
namespace cocktail{
namespace core{
namespace http{


class DataFormatValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef DataFormatValue_obj OBJ_;

	public:
		DataFormatValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.http.DataFormatValue"); }
		::String __ToString() const { return HX_CSTRING("DataFormatValue.") + tag; }

		static ::cocktail::core::http::DataFormatValue BINARY;
		static inline ::cocktail::core::http::DataFormatValue BINARY_dyn() { return BINARY; }
		static ::cocktail::core::http::DataFormatValue TEXT;
		static inline ::cocktail::core::http::DataFormatValue TEXT_dyn() { return TEXT; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace http

#endif /* INCLUDED_cocktail_core_http_DataFormatValue */ 
