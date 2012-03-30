#ifndef INCLUDED_core_nativeElement_NativeElementTypeValue
#define INCLUDED_core_nativeElement_NativeElementTypeValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,nativeElement,NativeElementTypeValue)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.nativeElement.NativeElementTypeValue"); }
		::String __ToString() const { return HX_CSTRING("NativeElementTypeValue.") + tag; }

		static ::core::nativeElement::NativeElementTypeValue custom(::String name);
		static Dynamic custom_dyn();
		static ::core::nativeElement::NativeElementTypeValue graphic;
		static inline ::core::nativeElement::NativeElementTypeValue graphic_dyn() { return graphic; }
		static ::core::nativeElement::NativeElementTypeValue image;
		static inline ::core::nativeElement::NativeElementTypeValue image_dyn() { return image; }
		static ::core::nativeElement::NativeElementTypeValue library;
		static inline ::core::nativeElement::NativeElementTypeValue library_dyn() { return library; }
		static ::core::nativeElement::NativeElementTypeValue link;
		static inline ::core::nativeElement::NativeElementTypeValue link_dyn() { return link; }
		static ::core::nativeElement::NativeElementTypeValue neutral;
		static inline ::core::nativeElement::NativeElementTypeValue neutral_dyn() { return neutral; }
		static ::core::nativeElement::NativeElementTypeValue skin;
		static inline ::core::nativeElement::NativeElementTypeValue skin_dyn() { return skin; }
		static ::core::nativeElement::NativeElementTypeValue text;
		static inline ::core::nativeElement::NativeElementTypeValue text_dyn() { return text; }
		static ::core::nativeElement::NativeElementTypeValue textInput;
		static inline ::core::nativeElement::NativeElementTypeValue textInput_dyn() { return textInput; }
};

} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_core_nativeElement_NativeElementTypeValue */ 
