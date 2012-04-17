#ifndef INCLUDED_core_style_FontWeight
#define INCLUDED_core_style_FontWeight

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,FontWeight)
namespace core{
namespace style{


class FontWeight_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontWeight_obj OBJ_;

	public:
		FontWeight_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.FontWeight"); }
		::String __ToString() const { return HX_CSTRING("FontWeight.") + tag; }

		static ::core::style::FontWeight bold;
		static inline ::core::style::FontWeight bold_dyn() { return bold; }
		static ::core::style::FontWeight bolder;
		static inline ::core::style::FontWeight bolder_dyn() { return bolder; }
		static ::core::style::FontWeight css100;
		static inline ::core::style::FontWeight css100_dyn() { return css100; }
		static ::core::style::FontWeight css200;
		static inline ::core::style::FontWeight css200_dyn() { return css200; }
		static ::core::style::FontWeight css300;
		static inline ::core::style::FontWeight css300_dyn() { return css300; }
		static ::core::style::FontWeight css400;
		static inline ::core::style::FontWeight css400_dyn() { return css400; }
		static ::core::style::FontWeight css500;
		static inline ::core::style::FontWeight css500_dyn() { return css500; }
		static ::core::style::FontWeight css600;
		static inline ::core::style::FontWeight css600_dyn() { return css600; }
		static ::core::style::FontWeight css700;
		static inline ::core::style::FontWeight css700_dyn() { return css700; }
		static ::core::style::FontWeight css800;
		static inline ::core::style::FontWeight css800_dyn() { return css800; }
		static ::core::style::FontWeight css900;
		static inline ::core::style::FontWeight css900_dyn() { return css900; }
		static ::core::style::FontWeight lighter;
		static inline ::core::style::FontWeight lighter_dyn() { return lighter; }
		static ::core::style::FontWeight normal;
		static inline ::core::style::FontWeight normal_dyn() { return normal; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_FontWeight */ 
