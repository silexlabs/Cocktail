#ifndef INCLUDED_cocktail_core_focus_FocusManager
#define INCLUDED_cocktail_core_focus_FocusManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,focus,AbstractFocusManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,focus,FocusManager)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBodyElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
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

		::cocktail::core::html::HTMLBodyElement bodyElement; /* REM */ 
		::cocktail::port::flash_player::HTMLElement activeElement; /* REM */ 
		::cocktail::core::focus::AbstractFocusManagerImpl _focusManagerImpl; /* REM */ 
		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual ::cocktail::port::flash_player::HTMLElement setActiveElement( ::cocktail::port::flash_player::HTMLElement value);
		Dynamic setActiveElement_dyn();

		virtual ::cocktail::port::flash_player::HTMLElement getActiveElement( );
		Dynamic getActiveElement_dyn();

		virtual ::cocktail::core::html::HTMLBodyElement setBodyElement( ::cocktail::core::html::HTMLBodyElement value);
		Dynamic setBodyElement_dyn();

		virtual ::cocktail::core::html::HTMLBodyElement getBodyElement( );
		Dynamic getBodyElement_dyn();

		static ::cocktail::core::focus::FocusManager _instance; /* REM */ 
		static ::cocktail::core::focus::FocusManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace focus

#endif /* INCLUDED_cocktail_core_focus_FocusManager */ 
