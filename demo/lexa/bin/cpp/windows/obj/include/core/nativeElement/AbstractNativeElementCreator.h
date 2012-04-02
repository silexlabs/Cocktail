#ifndef INCLUDED_core_nativeElement_AbstractNativeElementCreator
#define INCLUDED_core_nativeElement_AbstractNativeElementCreator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,nativeElement,AbstractNativeElementCreator)
HX_DECLARE_CLASS2(core,nativeElement,NativeElementTypeValue)
namespace core{
namespace nativeElement{


class AbstractNativeElementCreator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractNativeElementCreator_obj OBJ_;
		AbstractNativeElementCreator_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractNativeElementCreator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractNativeElementCreator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractNativeElementCreator"); }

		virtual Dynamic createNativeElement( ::core::nativeElement::NativeElementTypeValue nativeElementType);
		Dynamic createNativeElement_dyn();

};

} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_core_nativeElement_AbstractNativeElementCreator */ 
