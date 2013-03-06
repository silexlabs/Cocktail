#ifndef INCLUDED_cocktail_port_platform_nme_NativeText
#define INCLUDED_cocktail_port_platform_nme_NativeText

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/NativeTextBase.h>
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextBase)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeText)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,text,TextField)
namespace cocktail{
namespace port{
namespace platform{
namespace nme{


class NativeText_obj : public ::cocktail::port::base::NativeTextBase_obj{
	public:
		typedef ::cocktail::port::base::NativeTextBase_obj super;
		typedef NativeText_obj OBJ_;
		NativeText_obj();
		Void __construct(Dynamic nativeElement);

	public:
		static hx::ObjectPtr< NativeText_obj > __new(Dynamic nativeElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeText_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeText"); }

		virtual Float get_width( );

		virtual ::native::display::BitmapData getBitmap( ::cocktail::core::geom::RectangleVO bounds);

		::native::text::TextField _textField; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_cocktail_port_platform_nme_NativeText */ 
