#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#define INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementTypeValue)
namespace cocktail{
namespace core{
namespace nativeElement{


class NativeElementTypeValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef NativeElementTypeValue_obj OBJ_;

	public:
		NativeElementTypeValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.nativeElement.NativeElementTypeValue"); }
		::String __ToString() const { return HX_CSTRING("NativeElementTypeValue.") + tag; }

		static ::cocktail::core::nativeElement::NativeElementTypeValue custom(::String name);
		static Dynamic custom_dyn();
		static ::cocktail::core::nativeElement::NativeElementTypeValue graphic;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue graphic_dyn() { return graphic; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue image;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue image_dyn() { return image; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue library;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue library_dyn() { return library; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue link;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue link_dyn() { return link; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue neutral;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue neutral_dyn() { return neutral; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue skin;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue skin_dyn() { return skin; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue text;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue text_dyn() { return text; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue textInput;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue textInput_dyn() { return textInput; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue */ 
