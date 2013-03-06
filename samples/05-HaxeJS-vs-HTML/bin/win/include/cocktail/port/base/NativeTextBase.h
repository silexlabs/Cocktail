#ifndef INCLUDED_cocktail_port_base_NativeTextBase
#define INCLUDED_cocktail_port_base_NativeTextBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextBase)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
namespace cocktail{
namespace port{
namespace base{


class NativeTextBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeTextBase_obj OBJ_;
		NativeTextBase_obj();
		Void __construct(Dynamic nativeElement);

	public:
		static hx::ObjectPtr< NativeTextBase_obj > __new(Dynamic nativeElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeTextBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeTextBase"); }

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual ::native::display::BitmapData getBitmap( ::cocktail::core::geom::RectangleVO bounds);
		Dynamic getBitmap_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Dynamic _nativeElement; /* REM */ 
		Float width; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeTextBase */ 
