#ifndef INCLUDED_nme_display_TouchInfo
#define INCLUDED_nme_display_TouchInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,TouchInfo)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{
namespace display{


class TouchInfo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TouchInfo_obj OBJ_;
		TouchInfo_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TouchInfo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchInfo"); }

		Array< ::nme::display::InteractiveObject > touchOverObjects; /* REM */ 
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_TouchInfo */ 
