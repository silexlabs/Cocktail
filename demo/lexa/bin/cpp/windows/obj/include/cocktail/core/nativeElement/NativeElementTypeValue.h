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

		static ::cocktail::core::nativeElement::NativeElementTypeValue anchor;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue anchor_dyn() { return anchor; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue canvas;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue canvas_dyn() { return canvas; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue img;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue img_dyn() { return img; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue input;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue input_dyn() { return input; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue script;
		static inline ::cocktail::core::nativeElement::NativeElementTypeValue script_dyn() { return script; }
		static ::cocktail::core::nativeElement::NativeElementTypeValue semantic(::String name);
		static Dynamic semantic_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue */ 
