#ifndef INCLUDED_cocktailCore_focus_FocusManager
#define INCLUDED_cocktailCore_focus_FocusManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(cocktailCore,focus,FocusManager)
HX_DECLARE_CLASS3(cocktailCore,focus,abstract,AbstractFocusManagerImpl)
HX_DECLARE_CLASS3(cocktailCore,focus,as3,FocusManagerImpl)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,HTMLBodyElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace cocktailCore{
namespace focus{


class FocusManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FocusManager_obj OBJ_;
		FocusManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FocusManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FocusManager"); }

		::core::html::HTMLBodyElement bodyElement; /* REM */ 
		::port::flash_player::HTMLElement activeElement; /* REM */ 
		::cocktailCore::focus::as3::FocusManagerImpl _focusManagerImpl; /* REM */ 
		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual ::port::flash_player::HTMLElement setActiveElement( ::port::flash_player::HTMLElement value);
		Dynamic setActiveElement_dyn();

		virtual ::port::flash_player::HTMLElement getActiveElement( );
		Dynamic getActiveElement_dyn();

		virtual ::core::html::HTMLBodyElement setBodyElement( ::core::html::HTMLBodyElement value);
		Dynamic setBodyElement_dyn();

		virtual ::core::html::HTMLBodyElement getBodyElement( );
		Dynamic getBodyElement_dyn();

		static ::cocktailCore::focus::FocusManager _instance; /* REM */ 
		static ::cocktailCore::focus::FocusManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktailCore
} // end namespace focus

#endif /* INCLUDED_cocktailCore_focus_FocusManager */ 
